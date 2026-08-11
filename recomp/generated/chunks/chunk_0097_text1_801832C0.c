// DolRecomp output
#include "../generated.h"

static void loop_801856AC(CPUState* ctx) {
label_801856AC:
    ctx->downcount -= 3;
    ctx->pc = 0x801856ACu;
    // 801856AC: lwz     r4, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

    // 801856B0: addi    r0, r4, 8
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(8);

    ctx->pc = 0x801856B4u;
    // 801856B4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801856B8u;
    // 801856B8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 801856BC: cmplwi  r0, 0x03E8
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x03E8u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 801856C0: bc    12, 0, 0x801856AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801856ACu;
                return;
            }
            goto label_801856AC;
        }
    }

    ctx->pc = 0x801856C4u;
}

void func_801832C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x801832C0u: goto label_801832C0;
    case 0x801832C4u: goto label_801832C4;
    case 0x801832C8u: goto label_801832C8;
    case 0x801832CCu: goto label_801832CC;
    case 0x801832D0u: goto label_801832D0;
    case 0x801832D4u: goto label_801832D4;
    case 0x801832D8u: goto label_801832D8;
    case 0x801832DCu: goto label_801832DC;
    case 0x801832E0u: goto label_801832E0;
    case 0x801832E4u: goto label_801832E4;
    case 0x801832E8u: goto label_801832E8;
    case 0x801832ECu: goto label_801832EC;
    case 0x801832F0u: goto label_801832F0;
    case 0x801832F4u: goto label_801832F4;
    case 0x801832F8u: goto label_801832F8;
    case 0x801832FCu: goto label_801832FC;
    case 0x80183300u: goto label_80183300;
    case 0x80183304u: goto label_80183304;
    case 0x80183308u: goto label_80183308;
    case 0x8018330Cu: goto label_8018330C;
    case 0x80183310u: goto label_80183310;
    case 0x80183314u: goto label_80183314;
    case 0x80183318u: goto label_80183318;
    case 0x8018331Cu: goto label_8018331C;
    case 0x80183320u: goto label_80183320;
    case 0x80183324u: goto label_80183324;
    case 0x80183328u: goto label_80183328;
    case 0x8018332Cu: goto label_8018332C;
    case 0x80183330u: goto label_80183330;
    case 0x80183334u: goto label_80183334;
    case 0x80183338u: goto label_80183338;
    case 0x8018333Cu: goto label_8018333C;
    case 0x80183340u: goto label_80183340;
    case 0x80183344u: goto label_80183344;
    case 0x80183348u: goto label_80183348;
    case 0x8018334Cu: goto label_8018334C;
    case 0x80183350u: goto label_80183350;
    case 0x80183354u: goto label_80183354;
    case 0x80183358u: goto label_80183358;
    case 0x8018335Cu: goto label_8018335C;
    case 0x80183360u: goto label_80183360;
    case 0x80183364u: goto label_80183364;
    case 0x80183368u: goto label_80183368;
    case 0x8018336Cu: goto label_8018336C;
    case 0x80183370u: goto label_80183370;
    case 0x80183374u: goto label_80183374;
    case 0x80183378u: goto label_80183378;
    case 0x8018337Cu: goto label_8018337C;
    case 0x80183380u: goto label_80183380;
    case 0x80183384u: goto label_80183384;
    case 0x80183388u: goto label_80183388;
    case 0x8018338Cu: goto label_8018338C;
    case 0x80183390u: goto label_80183390;
    case 0x80183394u: goto label_80183394;
    case 0x80183398u: goto label_80183398;
    case 0x8018339Cu: goto label_8018339C;
    case 0x801833A0u: goto label_801833A0;
    case 0x801833A4u: goto label_801833A4;
    case 0x801833A8u: goto label_801833A8;
    case 0x801833ACu: goto label_801833AC;
    case 0x801833B0u: goto label_801833B0;
    case 0x801833B4u: goto label_801833B4;
    case 0x801833B8u: goto label_801833B8;
    case 0x801833BCu: goto label_801833BC;
    case 0x801833C0u: goto label_801833C0;
    case 0x801833C4u: goto label_801833C4;
    case 0x801833C8u: goto label_801833C8;
    case 0x801833CCu: goto label_801833CC;
    case 0x801833D0u: goto label_801833D0;
    case 0x801833D4u: goto label_801833D4;
    case 0x801833D8u: goto label_801833D8;
    case 0x801833DCu: goto label_801833DC;
    case 0x801833E0u: goto label_801833E0;
    case 0x801833E4u: goto label_801833E4;
    case 0x801833E8u: goto label_801833E8;
    case 0x801833ECu: goto label_801833EC;
    case 0x801833F0u: goto label_801833F0;
    case 0x801833F4u: goto label_801833F4;
    case 0x801833F8u: goto label_801833F8;
    case 0x801833FCu: goto label_801833FC;
    case 0x80183400u: goto label_80183400;
    case 0x80183404u: goto label_80183404;
    case 0x80183408u: goto label_80183408;
    case 0x8018340Cu: goto label_8018340C;
    case 0x80183410u: goto label_80183410;
    case 0x80183414u: goto label_80183414;
    case 0x80183418u: goto label_80183418;
    case 0x8018341Cu: goto label_8018341C;
    case 0x80183420u: goto label_80183420;
    case 0x80183424u: goto label_80183424;
    case 0x80183428u: goto label_80183428;
    case 0x8018342Cu: goto label_8018342C;
    case 0x80183430u: goto label_80183430;
    case 0x80183434u: goto label_80183434;
    case 0x80183438u: goto label_80183438;
    case 0x8018343Cu: goto label_8018343C;
    case 0x80183440u: goto label_80183440;
    case 0x80183444u: goto label_80183444;
    case 0x80183448u: goto label_80183448;
    case 0x8018344Cu: goto label_8018344C;
    case 0x80183450u: goto label_80183450;
    case 0x80183454u: goto label_80183454;
    case 0x80183458u: goto label_80183458;
    case 0x8018345Cu: goto label_8018345C;
    case 0x80183460u: goto label_80183460;
    case 0x80183464u: goto label_80183464;
    case 0x80183468u: goto label_80183468;
    case 0x8018346Cu: goto label_8018346C;
    case 0x80183470u: goto label_80183470;
    case 0x80183474u: goto label_80183474;
    case 0x80183478u: goto label_80183478;
    case 0x8018347Cu: goto label_8018347C;
    case 0x80183480u: goto label_80183480;
    case 0x80183484u: goto label_80183484;
    case 0x80183488u: goto label_80183488;
    case 0x8018348Cu: goto label_8018348C;
    case 0x80183490u: goto label_80183490;
    case 0x80183494u: goto label_80183494;
    case 0x80183498u: goto label_80183498;
    case 0x8018349Cu: goto label_8018349C;
    case 0x801834A0u: goto label_801834A0;
    case 0x801834A4u: goto label_801834A4;
    case 0x801834A8u: goto label_801834A8;
    case 0x801834ACu: goto label_801834AC;
    case 0x801834B0u: goto label_801834B0;
    case 0x801834B4u: goto label_801834B4;
    case 0x801834B8u: goto label_801834B8;
    case 0x801834BCu: goto label_801834BC;
    case 0x801834C0u: goto label_801834C0;
    case 0x801834C4u: goto label_801834C4;
    case 0x801834C8u: goto label_801834C8;
    case 0x801834CCu: goto label_801834CC;
    case 0x801834D0u: goto label_801834D0;
    case 0x801834D4u: goto label_801834D4;
    case 0x801834D8u: goto label_801834D8;
    case 0x801834DCu: goto label_801834DC;
    case 0x801834E0u: goto label_801834E0;
    case 0x801834E4u: goto label_801834E4;
    case 0x801834E8u: goto label_801834E8;
    case 0x801834ECu: goto label_801834EC;
    case 0x801834F0u: goto label_801834F0;
    case 0x801834F4u: goto label_801834F4;
    case 0x801834F8u: goto label_801834F8;
    case 0x801834FCu: goto label_801834FC;
    case 0x80183500u: goto label_80183500;
    case 0x80183504u: goto label_80183504;
    case 0x80183508u: goto label_80183508;
    case 0x8018350Cu: goto label_8018350C;
    case 0x80183510u: goto label_80183510;
    case 0x80183514u: goto label_80183514;
    case 0x80183518u: goto label_80183518;
    case 0x8018351Cu: goto label_8018351C;
    case 0x80183520u: goto label_80183520;
    case 0x80183524u: goto label_80183524;
    case 0x80183528u: goto label_80183528;
    case 0x8018352Cu: goto label_8018352C;
    case 0x80183530u: goto label_80183530;
    case 0x80183534u: goto label_80183534;
    case 0x80183538u: goto label_80183538;
    case 0x8018353Cu: goto label_8018353C;
    case 0x80183540u: goto label_80183540;
    case 0x80183544u: goto label_80183544;
    case 0x80183548u: goto label_80183548;
    case 0x8018354Cu: goto label_8018354C;
    case 0x80183550u: goto label_80183550;
    case 0x80183554u: goto label_80183554;
    case 0x80183558u: goto label_80183558;
    case 0x8018355Cu: goto label_8018355C;
    case 0x80183560u: goto label_80183560;
    case 0x80183564u: goto label_80183564;
    case 0x80183568u: goto label_80183568;
    case 0x8018356Cu: goto label_8018356C;
    case 0x80183570u: goto label_80183570;
    case 0x80183574u: goto label_80183574;
    case 0x80183578u: goto label_80183578;
    case 0x8018357Cu: goto label_8018357C;
    case 0x80183580u: goto label_80183580;
    case 0x80183584u: goto label_80183584;
    case 0x80183588u: goto label_80183588;
    case 0x8018358Cu: goto label_8018358C;
    case 0x80183590u: goto label_80183590;
    case 0x80183594u: goto label_80183594;
    case 0x80183598u: goto label_80183598;
    case 0x8018359Cu: goto label_8018359C;
    case 0x801835A0u: goto label_801835A0;
    case 0x801835A4u: goto label_801835A4;
    case 0x801835A8u: goto label_801835A8;
    case 0x801835ACu: goto label_801835AC;
    case 0x801835B0u: goto label_801835B0;
    case 0x801835B4u: goto label_801835B4;
    case 0x801835B8u: goto label_801835B8;
    case 0x801835BCu: goto label_801835BC;
    case 0x801835C0u: goto label_801835C0;
    case 0x801835C4u: goto label_801835C4;
    case 0x801835C8u: goto label_801835C8;
    case 0x801835CCu: goto label_801835CC;
    case 0x801835D0u: goto label_801835D0;
    case 0x801835D4u: goto label_801835D4;
    case 0x801835D8u: goto label_801835D8;
    case 0x801835DCu: goto label_801835DC;
    case 0x801835E0u: goto label_801835E0;
    case 0x801835E4u: goto label_801835E4;
    case 0x801835E8u: goto label_801835E8;
    case 0x801835ECu: goto label_801835EC;
    case 0x801835F0u: goto label_801835F0;
    case 0x801835F4u: goto label_801835F4;
    case 0x801835F8u: goto label_801835F8;
    case 0x801835FCu: goto label_801835FC;
    case 0x80183600u: goto label_80183600;
    case 0x80183604u: goto label_80183604;
    case 0x80183608u: goto label_80183608;
    case 0x8018360Cu: goto label_8018360C;
    case 0x80183610u: goto label_80183610;
    case 0x80183614u: goto label_80183614;
    case 0x80183618u: goto label_80183618;
    case 0x8018361Cu: goto label_8018361C;
    case 0x80183620u: goto label_80183620;
    case 0x80183624u: goto label_80183624;
    case 0x80183628u: goto label_80183628;
    case 0x8018362Cu: goto label_8018362C;
    case 0x80183630u: goto label_80183630;
    case 0x80183634u: goto label_80183634;
    case 0x80183638u: goto label_80183638;
    case 0x8018363Cu: goto label_8018363C;
    case 0x80183640u: goto label_80183640;
    case 0x80183644u: goto label_80183644;
    case 0x80183648u: goto label_80183648;
    case 0x8018364Cu: goto label_8018364C;
    case 0x80183650u: goto label_80183650;
    case 0x80183654u: goto label_80183654;
    case 0x80183658u: goto label_80183658;
    case 0x8018365Cu: goto label_8018365C;
    case 0x80183660u: goto label_80183660;
    case 0x80183664u: goto label_80183664;
    case 0x80183668u: goto label_80183668;
    case 0x8018366Cu: goto label_8018366C;
    case 0x80183670u: goto label_80183670;
    case 0x80183674u: goto label_80183674;
    case 0x80183678u: goto label_80183678;
    case 0x8018367Cu: goto label_8018367C;
    case 0x80183680u: goto label_80183680;
    case 0x80183684u: goto label_80183684;
    case 0x80183688u: goto label_80183688;
    case 0x8018368Cu: goto label_8018368C;
    case 0x80183690u: goto label_80183690;
    case 0x80183694u: goto label_80183694;
    case 0x80183698u: goto label_80183698;
    case 0x8018369Cu: goto label_8018369C;
    case 0x801836A0u: goto label_801836A0;
    case 0x801836A4u: goto label_801836A4;
    case 0x801836A8u: goto label_801836A8;
    case 0x801836ACu: goto label_801836AC;
    case 0x801836B0u: goto label_801836B0;
    case 0x801836B4u: goto label_801836B4;
    case 0x801836B8u: goto label_801836B8;
    case 0x801836BCu: goto label_801836BC;
    case 0x801836C0u: goto label_801836C0;
    case 0x801836C4u: goto label_801836C4;
    case 0x801836C8u: goto label_801836C8;
    case 0x801836CCu: goto label_801836CC;
    case 0x801836D0u: goto label_801836D0;
    case 0x801836D4u: goto label_801836D4;
    case 0x801836D8u: goto label_801836D8;
    case 0x801836DCu: goto label_801836DC;
    case 0x801836E0u: goto label_801836E0;
    case 0x801836E4u: goto label_801836E4;
    case 0x801836E8u: goto label_801836E8;
    case 0x801836ECu: goto label_801836EC;
    case 0x801836F0u: goto label_801836F0;
    case 0x801836F4u: goto label_801836F4;
    case 0x801836F8u: goto label_801836F8;
    case 0x801836FCu: goto label_801836FC;
    case 0x80183700u: goto label_80183700;
    case 0x80183704u: goto label_80183704;
    case 0x80183708u: goto label_80183708;
    case 0x8018370Cu: goto label_8018370C;
    case 0x80183710u: goto label_80183710;
    case 0x80183714u: goto label_80183714;
    case 0x80183718u: goto label_80183718;
    case 0x8018371Cu: goto label_8018371C;
    case 0x80183720u: goto label_80183720;
    case 0x80183724u: goto label_80183724;
    case 0x80183728u: goto label_80183728;
    case 0x8018372Cu: goto label_8018372C;
    case 0x80183730u: goto label_80183730;
    case 0x80183734u: goto label_80183734;
    case 0x80183738u: goto label_80183738;
    case 0x8018373Cu: goto label_8018373C;
    case 0x80183740u: goto label_80183740;
    case 0x80183744u: goto label_80183744;
    case 0x80183748u: goto label_80183748;
    case 0x8018374Cu: goto label_8018374C;
    case 0x80183750u: goto label_80183750;
    case 0x80183754u: goto label_80183754;
    case 0x80183758u: goto label_80183758;
    case 0x8018375Cu: goto label_8018375C;
    case 0x80183760u: goto label_80183760;
    case 0x80183764u: goto label_80183764;
    case 0x80183768u: goto label_80183768;
    case 0x8018376Cu: goto label_8018376C;
    case 0x80183770u: goto label_80183770;
    case 0x80183774u: goto label_80183774;
    case 0x80183778u: goto label_80183778;
    case 0x8018377Cu: goto label_8018377C;
    case 0x80183780u: goto label_80183780;
    case 0x80183784u: goto label_80183784;
    case 0x80183788u: goto label_80183788;
    case 0x8018378Cu: goto label_8018378C;
    case 0x80183790u: goto label_80183790;
    case 0x80183794u: goto label_80183794;
    case 0x80183798u: goto label_80183798;
    case 0x8018379Cu: goto label_8018379C;
    case 0x801837A0u: goto label_801837A0;
    case 0x801837A4u: goto label_801837A4;
    case 0x801837A8u: goto label_801837A8;
    case 0x801837ACu: goto label_801837AC;
    case 0x801837B0u: goto label_801837B0;
    case 0x801837B4u: goto label_801837B4;
    case 0x801837B8u: goto label_801837B8;
    case 0x801837BCu: goto label_801837BC;
    case 0x801837C0u: goto label_801837C0;
    case 0x801837C4u: goto label_801837C4;
    case 0x801837C8u: goto label_801837C8;
    case 0x801837CCu: goto label_801837CC;
    case 0x801837D0u: goto label_801837D0;
    case 0x801837D4u: goto label_801837D4;
    case 0x801837D8u: goto label_801837D8;
    case 0x801837DCu: goto label_801837DC;
    case 0x801837E0u: goto label_801837E0;
    case 0x801837E4u: goto label_801837E4;
    case 0x801837E8u: goto label_801837E8;
    case 0x801837ECu: goto label_801837EC;
    case 0x801837F0u: goto label_801837F0;
    case 0x801837F4u: goto label_801837F4;
    case 0x801837F8u: goto label_801837F8;
    case 0x801837FCu: goto label_801837FC;
    case 0x80183800u: goto label_80183800;
    case 0x80183804u: goto label_80183804;
    case 0x80183808u: goto label_80183808;
    case 0x8018380Cu: goto label_8018380C;
    case 0x80183810u: goto label_80183810;
    case 0x80183814u: goto label_80183814;
    case 0x80183818u: goto label_80183818;
    case 0x8018381Cu: goto label_8018381C;
    case 0x80183820u: goto label_80183820;
    case 0x80183824u: goto label_80183824;
    case 0x80183828u: goto label_80183828;
    case 0x8018382Cu: goto label_8018382C;
    case 0x80183830u: goto label_80183830;
    case 0x80183834u: goto label_80183834;
    case 0x80183838u: goto label_80183838;
    case 0x8018383Cu: goto label_8018383C;
    case 0x80183840u: goto label_80183840;
    case 0x80183844u: goto label_80183844;
    case 0x80183848u: goto label_80183848;
    case 0x8018384Cu: goto label_8018384C;
    case 0x80183850u: goto label_80183850;
    case 0x80183854u: goto label_80183854;
    case 0x80183858u: goto label_80183858;
    case 0x8018385Cu: goto label_8018385C;
    case 0x80183860u: goto label_80183860;
    case 0x80183864u: goto label_80183864;
    case 0x80183868u: goto label_80183868;
    case 0x8018386Cu: goto label_8018386C;
    case 0x80183870u: goto label_80183870;
    case 0x80183874u: goto label_80183874;
    case 0x80183878u: goto label_80183878;
    case 0x8018387Cu: goto label_8018387C;
    case 0x80183880u: goto label_80183880;
    case 0x80183884u: goto label_80183884;
    case 0x80183888u: goto label_80183888;
    case 0x8018388Cu: goto label_8018388C;
    case 0x80183890u: goto label_80183890;
    case 0x80183894u: goto label_80183894;
    case 0x80183898u: goto label_80183898;
    case 0x8018389Cu: goto label_8018389C;
    case 0x801838A0u: goto label_801838A0;
    case 0x801838A4u: goto label_801838A4;
    case 0x801838A8u: goto label_801838A8;
    case 0x801838ACu: goto label_801838AC;
    case 0x801838B0u: goto label_801838B0;
    case 0x801838B4u: goto label_801838B4;
    case 0x801838B8u: goto label_801838B8;
    case 0x801838BCu: goto label_801838BC;
    case 0x801838C0u: goto label_801838C0;
    case 0x801838C4u: goto label_801838C4;
    case 0x801838C8u: goto label_801838C8;
    case 0x801838CCu: goto label_801838CC;
    case 0x801838D0u: goto label_801838D0;
    case 0x801838D4u: goto label_801838D4;
    case 0x801838D8u: goto label_801838D8;
    case 0x801838DCu: goto label_801838DC;
    case 0x801838E0u: goto label_801838E0;
    case 0x801838E4u: goto label_801838E4;
    case 0x801838E8u: goto label_801838E8;
    case 0x801838ECu: goto label_801838EC;
    case 0x801838F0u: goto label_801838F0;
    case 0x801838F4u: goto label_801838F4;
    case 0x801838F8u: goto label_801838F8;
    case 0x801838FCu: goto label_801838FC;
    case 0x80183900u: goto label_80183900;
    case 0x80183904u: goto label_80183904;
    case 0x80183908u: goto label_80183908;
    case 0x8018390Cu: goto label_8018390C;
    case 0x80183910u: goto label_80183910;
    case 0x80183914u: goto label_80183914;
    case 0x80183918u: goto label_80183918;
    case 0x8018391Cu: goto label_8018391C;
    case 0x80183920u: goto label_80183920;
    case 0x80183924u: goto label_80183924;
    case 0x80183928u: goto label_80183928;
    case 0x8018392Cu: goto label_8018392C;
    case 0x80183930u: goto label_80183930;
    case 0x80183934u: goto label_80183934;
    case 0x80183938u: goto label_80183938;
    case 0x8018393Cu: goto label_8018393C;
    case 0x80183940u: goto label_80183940;
    case 0x80183944u: goto label_80183944;
    case 0x80183948u: goto label_80183948;
    case 0x8018394Cu: goto label_8018394C;
    case 0x80183950u: goto label_80183950;
    case 0x80183954u: goto label_80183954;
    case 0x80183958u: goto label_80183958;
    case 0x8018395Cu: goto label_8018395C;
    case 0x80183960u: goto label_80183960;
    case 0x80183964u: goto label_80183964;
    case 0x80183968u: goto label_80183968;
    case 0x8018396Cu: goto label_8018396C;
    case 0x80183970u: goto label_80183970;
    case 0x80183974u: goto label_80183974;
    case 0x80183978u: goto label_80183978;
    case 0x8018397Cu: goto label_8018397C;
    case 0x80183980u: goto label_80183980;
    case 0x80183984u: goto label_80183984;
    case 0x80183988u: goto label_80183988;
    case 0x8018398Cu: goto label_8018398C;
    case 0x80183990u: goto label_80183990;
    case 0x80183994u: goto label_80183994;
    case 0x80183998u: goto label_80183998;
    case 0x8018399Cu: goto label_8018399C;
    case 0x801839A0u: goto label_801839A0;
    case 0x801839A4u: goto label_801839A4;
    case 0x801839A8u: goto label_801839A8;
    case 0x801839ACu: goto label_801839AC;
    case 0x801839B0u: goto label_801839B0;
    case 0x801839B4u: goto label_801839B4;
    case 0x801839B8u: goto label_801839B8;
    case 0x801839BCu: goto label_801839BC;
    case 0x801839C0u: goto label_801839C0;
    case 0x801839C4u: goto label_801839C4;
    case 0x801839C8u: goto label_801839C8;
    case 0x801839CCu: goto label_801839CC;
    case 0x801839D0u: goto label_801839D0;
    case 0x801839D4u: goto label_801839D4;
    case 0x801839D8u: goto label_801839D8;
    case 0x801839DCu: goto label_801839DC;
    case 0x801839E0u: goto label_801839E0;
    case 0x801839E4u: goto label_801839E4;
    case 0x801839E8u: goto label_801839E8;
    case 0x801839ECu: goto label_801839EC;
    case 0x801839F0u: goto label_801839F0;
    case 0x801839F4u: goto label_801839F4;
    case 0x801839F8u: goto label_801839F8;
    case 0x801839FCu: goto label_801839FC;
    case 0x80183A00u: goto label_80183A00;
    case 0x80183A04u: goto label_80183A04;
    case 0x80183A08u: goto label_80183A08;
    case 0x80183A0Cu: goto label_80183A0C;
    case 0x80183A10u: goto label_80183A10;
    case 0x80183A14u: goto label_80183A14;
    case 0x80183A18u: goto label_80183A18;
    case 0x80183A1Cu: goto label_80183A1C;
    case 0x80183A20u: goto label_80183A20;
    case 0x80183A24u: goto label_80183A24;
    case 0x80183A28u: goto label_80183A28;
    case 0x80183A2Cu: goto label_80183A2C;
    case 0x80183A30u: goto label_80183A30;
    case 0x80183A34u: goto label_80183A34;
    case 0x80183A38u: goto label_80183A38;
    case 0x80183A3Cu: goto label_80183A3C;
    case 0x80183A40u: goto label_80183A40;
    case 0x80183A44u: goto label_80183A44;
    case 0x80183A48u: goto label_80183A48;
    case 0x80183A4Cu: goto label_80183A4C;
    case 0x80183A50u: goto label_80183A50;
    case 0x80183A54u: goto label_80183A54;
    case 0x80183A58u: goto label_80183A58;
    case 0x80183A5Cu: goto label_80183A5C;
    case 0x80183A60u: goto label_80183A60;
    case 0x80183A64u: goto label_80183A64;
    case 0x80183A68u: goto label_80183A68;
    case 0x80183A6Cu: goto label_80183A6C;
    case 0x80183A70u: goto label_80183A70;
    case 0x80183A74u: goto label_80183A74;
    case 0x80183A78u: goto label_80183A78;
    case 0x80183A7Cu: goto label_80183A7C;
    case 0x80183A80u: goto label_80183A80;
    case 0x80183A84u: goto label_80183A84;
    case 0x80183A88u: goto label_80183A88;
    case 0x80183A8Cu: goto label_80183A8C;
    case 0x80183A90u: goto label_80183A90;
    case 0x80183A94u: goto label_80183A94;
    case 0x80183A98u: goto label_80183A98;
    case 0x80183A9Cu: goto label_80183A9C;
    case 0x80183AA0u: goto label_80183AA0;
    case 0x80183AA4u: goto label_80183AA4;
    case 0x80183AA8u: goto label_80183AA8;
    case 0x80183AACu: goto label_80183AAC;
    case 0x80183AB0u: goto label_80183AB0;
    case 0x80183AB4u: goto label_80183AB4;
    case 0x80183AB8u: goto label_80183AB8;
    case 0x80183ABCu: goto label_80183ABC;
    case 0x80183AC0u: goto label_80183AC0;
    case 0x80183AC4u: goto label_80183AC4;
    case 0x80183AC8u: goto label_80183AC8;
    case 0x80183ACCu: goto label_80183ACC;
    case 0x80183AD0u: goto label_80183AD0;
    case 0x80183AD4u: goto label_80183AD4;
    case 0x80183AD8u: goto label_80183AD8;
    case 0x80183ADCu: goto label_80183ADC;
    case 0x80183AE0u: goto label_80183AE0;
    case 0x80183AE4u: goto label_80183AE4;
    case 0x80183AE8u: goto label_80183AE8;
    case 0x80183AECu: goto label_80183AEC;
    case 0x80183AF0u: goto label_80183AF0;
    case 0x80183AF4u: goto label_80183AF4;
    case 0x80183AF8u: goto label_80183AF8;
    case 0x80183AFCu: goto label_80183AFC;
    case 0x80183B00u: goto label_80183B00;
    case 0x80183B04u: goto label_80183B04;
    case 0x80183B08u: goto label_80183B08;
    case 0x80183B0Cu: goto label_80183B0C;
    case 0x80183B10u: goto label_80183B10;
    case 0x80183B14u: goto label_80183B14;
    case 0x80183B18u: goto label_80183B18;
    case 0x80183B1Cu: goto label_80183B1C;
    case 0x80183B20u: goto label_80183B20;
    case 0x80183B24u: goto label_80183B24;
    case 0x80183B28u: goto label_80183B28;
    case 0x80183B2Cu: goto label_80183B2C;
    case 0x80183B30u: goto label_80183B30;
    case 0x80183B34u: goto label_80183B34;
    case 0x80183B38u: goto label_80183B38;
    case 0x80183B3Cu: goto label_80183B3C;
    case 0x80183B40u: goto label_80183B40;
    case 0x80183B44u: goto label_80183B44;
    case 0x80183B48u: goto label_80183B48;
    case 0x80183B4Cu: goto label_80183B4C;
    case 0x80183B50u: goto label_80183B50;
    case 0x80183B54u: goto label_80183B54;
    case 0x80183B58u: goto label_80183B58;
    case 0x80183B5Cu: goto label_80183B5C;
    case 0x80183B60u: goto label_80183B60;
    case 0x80183B64u: goto label_80183B64;
    case 0x80183B68u: goto label_80183B68;
    case 0x80183B6Cu: goto label_80183B6C;
    case 0x80183B70u: goto label_80183B70;
    case 0x80183B74u: goto label_80183B74;
    case 0x80183B78u: goto label_80183B78;
    case 0x80183B7Cu: goto label_80183B7C;
    case 0x80183B80u: goto label_80183B80;
    case 0x80183B84u: goto label_80183B84;
    case 0x80183B88u: goto label_80183B88;
    case 0x80183B8Cu: goto label_80183B8C;
    case 0x80183B90u: goto label_80183B90;
    case 0x80183B94u: goto label_80183B94;
    case 0x80183B98u: goto label_80183B98;
    case 0x80183B9Cu: goto label_80183B9C;
    case 0x80183BA0u: goto label_80183BA0;
    case 0x80183BA4u: goto label_80183BA4;
    case 0x80183BA8u: goto label_80183BA8;
    case 0x80183BACu: goto label_80183BAC;
    case 0x80183BB0u: goto label_80183BB0;
    case 0x80183BB4u: goto label_80183BB4;
    case 0x80183BB8u: goto label_80183BB8;
    case 0x80183BBCu: goto label_80183BBC;
    case 0x80183BC0u: goto label_80183BC0;
    case 0x80183BC4u: goto label_80183BC4;
    case 0x80183BC8u: goto label_80183BC8;
    case 0x80183BCCu: goto label_80183BCC;
    case 0x80183BD0u: goto label_80183BD0;
    case 0x80183BD4u: goto label_80183BD4;
    case 0x80183BD8u: goto label_80183BD8;
    case 0x80183BDCu: goto label_80183BDC;
    case 0x80183BE0u: goto label_80183BE0;
    case 0x80183BE4u: goto label_80183BE4;
    case 0x80183BE8u: goto label_80183BE8;
    case 0x80183BECu: goto label_80183BEC;
    case 0x80183BF0u: goto label_80183BF0;
    case 0x80183BF4u: goto label_80183BF4;
    case 0x80183BF8u: goto label_80183BF8;
    case 0x80183BFCu: goto label_80183BFC;
    case 0x80183C00u: goto label_80183C00;
    case 0x80183C04u: goto label_80183C04;
    case 0x80183C08u: goto label_80183C08;
    case 0x80183C0Cu: goto label_80183C0C;
    case 0x80183C10u: goto label_80183C10;
    case 0x80183C14u: goto label_80183C14;
    case 0x80183C18u: goto label_80183C18;
    case 0x80183C1Cu: goto label_80183C1C;
    case 0x80183C20u: goto label_80183C20;
    case 0x80183C24u: goto label_80183C24;
    case 0x80183C28u: goto label_80183C28;
    case 0x80183C2Cu: goto label_80183C2C;
    case 0x80183C30u: goto label_80183C30;
    case 0x80183C34u: goto label_80183C34;
    case 0x80183C38u: goto label_80183C38;
    case 0x80183C3Cu: goto label_80183C3C;
    case 0x80183C40u: goto label_80183C40;
    case 0x80183C44u: goto label_80183C44;
    case 0x80183C48u: goto label_80183C48;
    case 0x80183C4Cu: goto label_80183C4C;
    case 0x80183C50u: goto label_80183C50;
    case 0x80183C54u: goto label_80183C54;
    case 0x80183C58u: goto label_80183C58;
    case 0x80183C5Cu: goto label_80183C5C;
    case 0x80183C60u: goto label_80183C60;
    case 0x80183C64u: goto label_80183C64;
    case 0x80183C68u: goto label_80183C68;
    case 0x80183C6Cu: goto label_80183C6C;
    case 0x80183C70u: goto label_80183C70;
    case 0x80183C74u: goto label_80183C74;
    case 0x80183C78u: goto label_80183C78;
    case 0x80183C7Cu: goto label_80183C7C;
    case 0x80183C80u: goto label_80183C80;
    case 0x80183C84u: goto label_80183C84;
    case 0x80183C88u: goto label_80183C88;
    case 0x80183C8Cu: goto label_80183C8C;
    case 0x80183C90u: goto label_80183C90;
    case 0x80183C94u: goto label_80183C94;
    case 0x80183C98u: goto label_80183C98;
    case 0x80183C9Cu: goto label_80183C9C;
    case 0x80183CA0u: goto label_80183CA0;
    case 0x80183CA4u: goto label_80183CA4;
    case 0x80183CA8u: goto label_80183CA8;
    case 0x80183CACu: goto label_80183CAC;
    case 0x80183CB0u: goto label_80183CB0;
    case 0x80183CB4u: goto label_80183CB4;
    case 0x80183CB8u: goto label_80183CB8;
    case 0x80183CBCu: goto label_80183CBC;
    case 0x80183CC0u: goto label_80183CC0;
    case 0x80183CC4u: goto label_80183CC4;
    case 0x80183CC8u: goto label_80183CC8;
    case 0x80183CCCu: goto label_80183CCC;
    case 0x80183CD0u: goto label_80183CD0;
    case 0x80183CD4u: goto label_80183CD4;
    case 0x80183CD8u: goto label_80183CD8;
    case 0x80183CDCu: goto label_80183CDC;
    case 0x80183CE0u: goto label_80183CE0;
    case 0x80183CE4u: goto label_80183CE4;
    case 0x80183CE8u: goto label_80183CE8;
    case 0x80183CECu: goto label_80183CEC;
    case 0x80183CF0u: goto label_80183CF0;
    case 0x80183CF4u: goto label_80183CF4;
    case 0x80183CF8u: goto label_80183CF8;
    case 0x80183CFCu: goto label_80183CFC;
    case 0x80183D00u: goto label_80183D00;
    case 0x80183D04u: goto label_80183D04;
    case 0x80183D08u: goto label_80183D08;
    case 0x80183D0Cu: goto label_80183D0C;
    case 0x80183D10u: goto label_80183D10;
    case 0x80183D14u: goto label_80183D14;
    case 0x80183D18u: goto label_80183D18;
    case 0x80183D1Cu: goto label_80183D1C;
    case 0x80183D20u: goto label_80183D20;
    case 0x80183D24u: goto label_80183D24;
    case 0x80183D28u: goto label_80183D28;
    case 0x80183D2Cu: goto label_80183D2C;
    case 0x80183D30u: goto label_80183D30;
    case 0x80183D34u: goto label_80183D34;
    case 0x80183D38u: goto label_80183D38;
    case 0x80183D3Cu: goto label_80183D3C;
    case 0x80183D40u: goto label_80183D40;
    case 0x80183D44u: goto label_80183D44;
    case 0x80183D48u: goto label_80183D48;
    case 0x80183D4Cu: goto label_80183D4C;
    case 0x80183D50u: goto label_80183D50;
    case 0x80183D54u: goto label_80183D54;
    case 0x80183D58u: goto label_80183D58;
    case 0x80183D5Cu: goto label_80183D5C;
    case 0x80183D60u: goto label_80183D60;
    case 0x80183D64u: goto label_80183D64;
    case 0x80183D68u: goto label_80183D68;
    case 0x80183D6Cu: goto label_80183D6C;
    case 0x80183D70u: goto label_80183D70;
    case 0x80183D74u: goto label_80183D74;
    case 0x80183D78u: goto label_80183D78;
    case 0x80183D7Cu: goto label_80183D7C;
    case 0x80183D80u: goto label_80183D80;
    case 0x80183D84u: goto label_80183D84;
    case 0x80183D88u: goto label_80183D88;
    case 0x80183D8Cu: goto label_80183D8C;
    case 0x80183D90u: goto label_80183D90;
    case 0x80183D94u: goto label_80183D94;
    case 0x80183D98u: goto label_80183D98;
    case 0x80183D9Cu: goto label_80183D9C;
    case 0x80183DA0u: goto label_80183DA0;
    case 0x80183DA4u: goto label_80183DA4;
    case 0x80183DA8u: goto label_80183DA8;
    case 0x80183DACu: goto label_80183DAC;
    case 0x80183DB0u: goto label_80183DB0;
    case 0x80183DB4u: goto label_80183DB4;
    case 0x80183DB8u: goto label_80183DB8;
    case 0x80183DBCu: goto label_80183DBC;
    case 0x80183DC0u: goto label_80183DC0;
    case 0x80183DC4u: goto label_80183DC4;
    case 0x80183DC8u: goto label_80183DC8;
    case 0x80183DCCu: goto label_80183DCC;
    case 0x80183DD0u: goto label_80183DD0;
    case 0x80183DD4u: goto label_80183DD4;
    case 0x80183DD8u: goto label_80183DD8;
    case 0x80183DDCu: goto label_80183DDC;
    case 0x80183DE0u: goto label_80183DE0;
    case 0x80183DE4u: goto label_80183DE4;
    case 0x80183DE8u: goto label_80183DE8;
    case 0x80183DECu: goto label_80183DEC;
    case 0x80183DF0u: goto label_80183DF0;
    case 0x80183DF4u: goto label_80183DF4;
    case 0x80183DF8u: goto label_80183DF8;
    case 0x80183DFCu: goto label_80183DFC;
    case 0x80183E00u: goto label_80183E00;
    case 0x80183E04u: goto label_80183E04;
    case 0x80183E08u: goto label_80183E08;
    case 0x80183E0Cu: goto label_80183E0C;
    case 0x80183E10u: goto label_80183E10;
    case 0x80183E14u: goto label_80183E14;
    case 0x80183E18u: goto label_80183E18;
    case 0x80183E1Cu: goto label_80183E1C;
    case 0x80183E20u: goto label_80183E20;
    case 0x80183E24u: goto label_80183E24;
    case 0x80183E28u: goto label_80183E28;
    case 0x80183E2Cu: goto label_80183E2C;
    case 0x80183E30u: goto label_80183E30;
    case 0x80183E34u: goto label_80183E34;
    case 0x80183E38u: goto label_80183E38;
    case 0x80183E3Cu: goto label_80183E3C;
    case 0x80183E40u: goto label_80183E40;
    case 0x80183E44u: goto label_80183E44;
    case 0x80183E48u: goto label_80183E48;
    case 0x80183E4Cu: goto label_80183E4C;
    case 0x80183E50u: goto label_80183E50;
    case 0x80183E54u: goto label_80183E54;
    case 0x80183E58u: goto label_80183E58;
    case 0x80183E5Cu: goto label_80183E5C;
    case 0x80183E60u: goto label_80183E60;
    case 0x80183E64u: goto label_80183E64;
    case 0x80183E68u: goto label_80183E68;
    case 0x80183E6Cu: goto label_80183E6C;
    case 0x80183E70u: goto label_80183E70;
    case 0x80183E74u: goto label_80183E74;
    case 0x80183E78u: goto label_80183E78;
    case 0x80183E7Cu: goto label_80183E7C;
    case 0x80183E80u: goto label_80183E80;
    case 0x80183E84u: goto label_80183E84;
    case 0x80183E88u: goto label_80183E88;
    case 0x80183E8Cu: goto label_80183E8C;
    case 0x80183E90u: goto label_80183E90;
    case 0x80183E94u: goto label_80183E94;
    case 0x80183E98u: goto label_80183E98;
    case 0x80183E9Cu: goto label_80183E9C;
    case 0x80183EA0u: goto label_80183EA0;
    case 0x80183EA4u: goto label_80183EA4;
    case 0x80183EA8u: goto label_80183EA8;
    case 0x80183EACu: goto label_80183EAC;
    case 0x80183EB0u: goto label_80183EB0;
    case 0x80183EB4u: goto label_80183EB4;
    case 0x80183EB8u: goto label_80183EB8;
    case 0x80183EBCu: goto label_80183EBC;
    case 0x80183EC0u: goto label_80183EC0;
    case 0x80183EC4u: goto label_80183EC4;
    case 0x80183EC8u: goto label_80183EC8;
    case 0x80183ECCu: goto label_80183ECC;
    case 0x80183ED0u: goto label_80183ED0;
    case 0x80183ED4u: goto label_80183ED4;
    case 0x80183ED8u: goto label_80183ED8;
    case 0x80183EDCu: goto label_80183EDC;
    case 0x80183EE0u: goto label_80183EE0;
    case 0x80183EE4u: goto label_80183EE4;
    case 0x80183EE8u: goto label_80183EE8;
    case 0x80183EECu: goto label_80183EEC;
    case 0x80183EF0u: goto label_80183EF0;
    case 0x80183EF4u: goto label_80183EF4;
    case 0x80183EF8u: goto label_80183EF8;
    case 0x80183EFCu: goto label_80183EFC;
    case 0x80183F00u: goto label_80183F00;
    case 0x80183F04u: goto label_80183F04;
    case 0x80183F08u: goto label_80183F08;
    case 0x80183F0Cu: goto label_80183F0C;
    case 0x80183F10u: goto label_80183F10;
    case 0x80183F14u: goto label_80183F14;
    case 0x80183F18u: goto label_80183F18;
    case 0x80183F1Cu: goto label_80183F1C;
    case 0x80183F20u: goto label_80183F20;
    case 0x80183F24u: goto label_80183F24;
    case 0x80183F28u: goto label_80183F28;
    case 0x80183F2Cu: goto label_80183F2C;
    case 0x80183F30u: goto label_80183F30;
    case 0x80183F34u: goto label_80183F34;
    case 0x80183F38u: goto label_80183F38;
    case 0x80183F3Cu: goto label_80183F3C;
    case 0x80183F40u: goto label_80183F40;
    case 0x80183F44u: goto label_80183F44;
    case 0x80183F48u: goto label_80183F48;
    case 0x80183F4Cu: goto label_80183F4C;
    case 0x80183F50u: goto label_80183F50;
    case 0x80183F54u: goto label_80183F54;
    case 0x80183F58u: goto label_80183F58;
    case 0x80183F5Cu: goto label_80183F5C;
    case 0x80183F60u: goto label_80183F60;
    case 0x80183F64u: goto label_80183F64;
    case 0x80183F68u: goto label_80183F68;
    case 0x80183F6Cu: goto label_80183F6C;
    case 0x80183F70u: goto label_80183F70;
    case 0x80183F74u: goto label_80183F74;
    case 0x80183F78u: goto label_80183F78;
    case 0x80183F7Cu: goto label_80183F7C;
    case 0x80183F80u: goto label_80183F80;
    case 0x80183F84u: goto label_80183F84;
    case 0x80183F88u: goto label_80183F88;
    case 0x80183F8Cu: goto label_80183F8C;
    case 0x80183F90u: goto label_80183F90;
    case 0x80183F94u: goto label_80183F94;
    case 0x80183F98u: goto label_80183F98;
    case 0x80183F9Cu: goto label_80183F9C;
    case 0x80183FA0u: goto label_80183FA0;
    case 0x80183FA4u: goto label_80183FA4;
    case 0x80183FA8u: goto label_80183FA8;
    case 0x80183FACu: goto label_80183FAC;
    case 0x80183FB0u: goto label_80183FB0;
    case 0x80183FB4u: goto label_80183FB4;
    case 0x80183FB8u: goto label_80183FB8;
    case 0x80183FBCu: goto label_80183FBC;
    case 0x80183FC0u: goto label_80183FC0;
    case 0x80183FC4u: goto label_80183FC4;
    case 0x80183FC8u: goto label_80183FC8;
    case 0x80183FCCu: goto label_80183FCC;
    case 0x80183FD0u: goto label_80183FD0;
    case 0x80183FD4u: goto label_80183FD4;
    case 0x80183FD8u: goto label_80183FD8;
    case 0x80183FDCu: goto label_80183FDC;
    case 0x80183FE0u: goto label_80183FE0;
    case 0x80183FE4u: goto label_80183FE4;
    case 0x80183FE8u: goto label_80183FE8;
    case 0x80183FECu: goto label_80183FEC;
    case 0x80183FF0u: goto label_80183FF0;
    case 0x80183FF4u: goto label_80183FF4;
    case 0x80183FF8u: goto label_80183FF8;
    case 0x80183FFCu: goto label_80183FFC;
    case 0x80184000u: goto label_80184000;
    case 0x80184004u: goto label_80184004;
    case 0x80184008u: goto label_80184008;
    case 0x8018400Cu: goto label_8018400C;
    case 0x80184010u: goto label_80184010;
    case 0x80184014u: goto label_80184014;
    case 0x80184018u: goto label_80184018;
    case 0x8018401Cu: goto label_8018401C;
    case 0x80184020u: goto label_80184020;
    case 0x80184024u: goto label_80184024;
    case 0x80184028u: goto label_80184028;
    case 0x8018402Cu: goto label_8018402C;
    case 0x80184030u: goto label_80184030;
    case 0x80184034u: goto label_80184034;
    case 0x80184038u: goto label_80184038;
    case 0x8018403Cu: goto label_8018403C;
    case 0x80184040u: goto label_80184040;
    case 0x80184044u: goto label_80184044;
    case 0x80184048u: goto label_80184048;
    case 0x8018404Cu: goto label_8018404C;
    case 0x80184050u: goto label_80184050;
    case 0x80184054u: goto label_80184054;
    case 0x80184058u: goto label_80184058;
    case 0x8018405Cu: goto label_8018405C;
    case 0x80184060u: goto label_80184060;
    case 0x80184064u: goto label_80184064;
    case 0x80184068u: goto label_80184068;
    case 0x8018406Cu: goto label_8018406C;
    case 0x80184070u: goto label_80184070;
    case 0x80184074u: goto label_80184074;
    case 0x80184078u: goto label_80184078;
    case 0x8018407Cu: goto label_8018407C;
    case 0x80184080u: goto label_80184080;
    case 0x80184084u: goto label_80184084;
    case 0x80184088u: goto label_80184088;
    case 0x8018408Cu: goto label_8018408C;
    case 0x80184090u: goto label_80184090;
    case 0x80184094u: goto label_80184094;
    case 0x80184098u: goto label_80184098;
    case 0x8018409Cu: goto label_8018409C;
    case 0x801840A0u: goto label_801840A0;
    case 0x801840A4u: goto label_801840A4;
    case 0x801840A8u: goto label_801840A8;
    case 0x801840ACu: goto label_801840AC;
    case 0x801840B0u: goto label_801840B0;
    case 0x801840B4u: goto label_801840B4;
    case 0x801840B8u: goto label_801840B8;
    case 0x801840BCu: goto label_801840BC;
    case 0x801840C0u: goto label_801840C0;
    case 0x801840C4u: goto label_801840C4;
    case 0x801840C8u: goto label_801840C8;
    case 0x801840CCu: goto label_801840CC;
    case 0x801840D0u: goto label_801840D0;
    case 0x801840D4u: goto label_801840D4;
    case 0x801840D8u: goto label_801840D8;
    case 0x801840DCu: goto label_801840DC;
    case 0x801840E0u: goto label_801840E0;
    case 0x801840E4u: goto label_801840E4;
    case 0x801840E8u: goto label_801840E8;
    case 0x801840ECu: goto label_801840EC;
    case 0x801840F0u: goto label_801840F0;
    case 0x801840F4u: goto label_801840F4;
    case 0x801840F8u: goto label_801840F8;
    case 0x801840FCu: goto label_801840FC;
    case 0x80184100u: goto label_80184100;
    case 0x80184104u: goto label_80184104;
    case 0x80184108u: goto label_80184108;
    case 0x8018410Cu: goto label_8018410C;
    case 0x80184110u: goto label_80184110;
    case 0x80184114u: goto label_80184114;
    case 0x80184118u: goto label_80184118;
    case 0x8018411Cu: goto label_8018411C;
    case 0x80184120u: goto label_80184120;
    case 0x80184124u: goto label_80184124;
    case 0x80184128u: goto label_80184128;
    case 0x8018412Cu: goto label_8018412C;
    case 0x80184130u: goto label_80184130;
    case 0x80184134u: goto label_80184134;
    case 0x80184138u: goto label_80184138;
    case 0x8018413Cu: goto label_8018413C;
    case 0x80184140u: goto label_80184140;
    case 0x80184144u: goto label_80184144;
    case 0x80184148u: goto label_80184148;
    case 0x8018414Cu: goto label_8018414C;
    case 0x80184150u: goto label_80184150;
    case 0x80184154u: goto label_80184154;
    case 0x80184158u: goto label_80184158;
    case 0x8018415Cu: goto label_8018415C;
    case 0x80184160u: goto label_80184160;
    case 0x80184164u: goto label_80184164;
    case 0x80184168u: goto label_80184168;
    case 0x8018416Cu: goto label_8018416C;
    case 0x80184170u: goto label_80184170;
    case 0x80184174u: goto label_80184174;
    case 0x80184178u: goto label_80184178;
    case 0x8018417Cu: goto label_8018417C;
    case 0x80184180u: goto label_80184180;
    case 0x80184184u: goto label_80184184;
    case 0x80184188u: goto label_80184188;
    case 0x8018418Cu: goto label_8018418C;
    case 0x80184190u: goto label_80184190;
    case 0x80184194u: goto label_80184194;
    case 0x80184198u: goto label_80184198;
    case 0x8018419Cu: goto label_8018419C;
    case 0x801841A0u: goto label_801841A0;
    case 0x801841A4u: goto label_801841A4;
    case 0x801841A8u: goto label_801841A8;
    case 0x801841ACu: goto label_801841AC;
    case 0x801841B0u: goto label_801841B0;
    case 0x801841B4u: goto label_801841B4;
    case 0x801841B8u: goto label_801841B8;
    case 0x801841BCu: goto label_801841BC;
    case 0x801841C0u: goto label_801841C0;
    case 0x801841C4u: goto label_801841C4;
    case 0x801841C8u: goto label_801841C8;
    case 0x801841CCu: goto label_801841CC;
    case 0x801841D0u: goto label_801841D0;
    case 0x801841D4u: goto label_801841D4;
    case 0x801841D8u: goto label_801841D8;
    case 0x801841DCu: goto label_801841DC;
    case 0x801841E0u: goto label_801841E0;
    case 0x801841E4u: goto label_801841E4;
    case 0x801841E8u: goto label_801841E8;
    case 0x801841ECu: goto label_801841EC;
    case 0x801841F0u: goto label_801841F0;
    case 0x801841F4u: goto label_801841F4;
    case 0x801841F8u: goto label_801841F8;
    case 0x801841FCu: goto label_801841FC;
    case 0x80184200u: goto label_80184200;
    case 0x80184204u: goto label_80184204;
    case 0x80184208u: goto label_80184208;
    case 0x8018420Cu: goto label_8018420C;
    case 0x80184210u: goto label_80184210;
    case 0x80184214u: goto label_80184214;
    case 0x80184218u: goto label_80184218;
    case 0x8018421Cu: goto label_8018421C;
    case 0x80184220u: goto label_80184220;
    case 0x80184224u: goto label_80184224;
    case 0x80184228u: goto label_80184228;
    case 0x8018422Cu: goto label_8018422C;
    case 0x80184230u: goto label_80184230;
    case 0x80184234u: goto label_80184234;
    case 0x80184238u: goto label_80184238;
    case 0x8018423Cu: goto label_8018423C;
    case 0x80184240u: goto label_80184240;
    case 0x80184244u: goto label_80184244;
    case 0x80184248u: goto label_80184248;
    case 0x8018424Cu: goto label_8018424C;
    case 0x80184250u: goto label_80184250;
    case 0x80184254u: goto label_80184254;
    case 0x80184258u: goto label_80184258;
    case 0x8018425Cu: goto label_8018425C;
    case 0x80184260u: goto label_80184260;
    case 0x80184264u: goto label_80184264;
    case 0x80184268u: goto label_80184268;
    case 0x8018426Cu: goto label_8018426C;
    case 0x80184270u: goto label_80184270;
    case 0x80184274u: goto label_80184274;
    case 0x80184278u: goto label_80184278;
    case 0x8018427Cu: goto label_8018427C;
    case 0x80184280u: goto label_80184280;
    case 0x80184284u: goto label_80184284;
    case 0x80184288u: goto label_80184288;
    case 0x8018428Cu: goto label_8018428C;
    case 0x80184290u: goto label_80184290;
    case 0x80184294u: goto label_80184294;
    case 0x80184298u: goto label_80184298;
    case 0x8018429Cu: goto label_8018429C;
    case 0x801842A0u: goto label_801842A0;
    case 0x801842A4u: goto label_801842A4;
    case 0x801842A8u: goto label_801842A8;
    case 0x801842ACu: goto label_801842AC;
    case 0x801842B0u: goto label_801842B0;
    case 0x801842B4u: goto label_801842B4;
    case 0x801842B8u: goto label_801842B8;
    case 0x801842BCu: goto label_801842BC;
    case 0x801842C0u: goto label_801842C0;
    case 0x801842C4u: goto label_801842C4;
    case 0x801842C8u: goto label_801842C8;
    case 0x801842CCu: goto label_801842CC;
    case 0x801842D0u: goto label_801842D0;
    case 0x801842D4u: goto label_801842D4;
    case 0x801842D8u: goto label_801842D8;
    case 0x801842DCu: goto label_801842DC;
    case 0x801842E0u: goto label_801842E0;
    case 0x801842E4u: goto label_801842E4;
    case 0x801842E8u: goto label_801842E8;
    case 0x801842ECu: goto label_801842EC;
    case 0x801842F0u: goto label_801842F0;
    case 0x801842F4u: goto label_801842F4;
    case 0x801842F8u: goto label_801842F8;
    case 0x801842FCu: goto label_801842FC;
    case 0x80184300u: goto label_80184300;
    case 0x80184304u: goto label_80184304;
    case 0x80184308u: goto label_80184308;
    case 0x8018430Cu: goto label_8018430C;
    case 0x80184310u: goto label_80184310;
    case 0x80184314u: goto label_80184314;
    case 0x80184318u: goto label_80184318;
    case 0x8018431Cu: goto label_8018431C;
    case 0x80184320u: goto label_80184320;
    case 0x80184324u: goto label_80184324;
    case 0x80184328u: goto label_80184328;
    case 0x8018432Cu: goto label_8018432C;
    case 0x80184330u: goto label_80184330;
    case 0x80184334u: goto label_80184334;
    case 0x80184338u: goto label_80184338;
    case 0x8018433Cu: goto label_8018433C;
    case 0x80184340u: goto label_80184340;
    case 0x80184344u: goto label_80184344;
    case 0x80184348u: goto label_80184348;
    case 0x8018434Cu: goto label_8018434C;
    case 0x80184350u: goto label_80184350;
    case 0x80184354u: goto label_80184354;
    case 0x80184358u: goto label_80184358;
    case 0x8018435Cu: goto label_8018435C;
    case 0x80184360u: goto label_80184360;
    case 0x80184364u: goto label_80184364;
    case 0x80184368u: goto label_80184368;
    case 0x8018436Cu: goto label_8018436C;
    case 0x80184370u: goto label_80184370;
    case 0x80184374u: goto label_80184374;
    case 0x80184378u: goto label_80184378;
    case 0x8018437Cu: goto label_8018437C;
    case 0x80184380u: goto label_80184380;
    case 0x80184384u: goto label_80184384;
    case 0x80184388u: goto label_80184388;
    case 0x8018438Cu: goto label_8018438C;
    case 0x80184390u: goto label_80184390;
    case 0x80184394u: goto label_80184394;
    case 0x80184398u: goto label_80184398;
    case 0x8018439Cu: goto label_8018439C;
    case 0x801843A0u: goto label_801843A0;
    case 0x801843A4u: goto label_801843A4;
    case 0x801843A8u: goto label_801843A8;
    case 0x801843ACu: goto label_801843AC;
    case 0x801843B0u: goto label_801843B0;
    case 0x801843B4u: goto label_801843B4;
    case 0x801843B8u: goto label_801843B8;
    case 0x801843BCu: goto label_801843BC;
    case 0x801843C0u: goto label_801843C0;
    case 0x801843C4u: goto label_801843C4;
    case 0x801843C8u: goto label_801843C8;
    case 0x801843CCu: goto label_801843CC;
    case 0x801843D0u: goto label_801843D0;
    case 0x801843D4u: goto label_801843D4;
    case 0x801843D8u: goto label_801843D8;
    case 0x801843DCu: goto label_801843DC;
    case 0x801843E0u: goto label_801843E0;
    case 0x801843E4u: goto label_801843E4;
    case 0x801843E8u: goto label_801843E8;
    case 0x801843ECu: goto label_801843EC;
    case 0x801843F0u: goto label_801843F0;
    case 0x801843F4u: goto label_801843F4;
    case 0x801843F8u: goto label_801843F8;
    case 0x801843FCu: goto label_801843FC;
    case 0x80184400u: goto label_80184400;
    case 0x80184404u: goto label_80184404;
    case 0x80184408u: goto label_80184408;
    case 0x8018440Cu: goto label_8018440C;
    case 0x80184410u: goto label_80184410;
    case 0x80184414u: goto label_80184414;
    case 0x80184418u: goto label_80184418;
    case 0x8018441Cu: goto label_8018441C;
    case 0x80184420u: goto label_80184420;
    case 0x80184424u: goto label_80184424;
    case 0x80184428u: goto label_80184428;
    case 0x8018442Cu: goto label_8018442C;
    case 0x80184430u: goto label_80184430;
    case 0x80184434u: goto label_80184434;
    case 0x80184438u: goto label_80184438;
    case 0x8018443Cu: goto label_8018443C;
    case 0x80184440u: goto label_80184440;
    case 0x80184444u: goto label_80184444;
    case 0x80184448u: goto label_80184448;
    case 0x8018444Cu: goto label_8018444C;
    case 0x80184450u: goto label_80184450;
    case 0x80184454u: goto label_80184454;
    case 0x80184458u: goto label_80184458;
    case 0x8018445Cu: goto label_8018445C;
    case 0x80184460u: goto label_80184460;
    case 0x80184464u: goto label_80184464;
    case 0x80184468u: goto label_80184468;
    case 0x8018446Cu: goto label_8018446C;
    case 0x80184470u: goto label_80184470;
    case 0x80184474u: goto label_80184474;
    case 0x80184478u: goto label_80184478;
    case 0x8018447Cu: goto label_8018447C;
    case 0x80184480u: goto label_80184480;
    case 0x80184484u: goto label_80184484;
    case 0x80184488u: goto label_80184488;
    case 0x8018448Cu: goto label_8018448C;
    case 0x80184490u: goto label_80184490;
    case 0x80184494u: goto label_80184494;
    case 0x80184498u: goto label_80184498;
    case 0x8018449Cu: goto label_8018449C;
    case 0x801844A0u: goto label_801844A0;
    case 0x801844A4u: goto label_801844A4;
    case 0x801844A8u: goto label_801844A8;
    case 0x801844ACu: goto label_801844AC;
    case 0x801844B0u: goto label_801844B0;
    case 0x801844B4u: goto label_801844B4;
    case 0x801844B8u: goto label_801844B8;
    case 0x801844BCu: goto label_801844BC;
    case 0x801844C0u: goto label_801844C0;
    case 0x801844C4u: goto label_801844C4;
    case 0x801844C8u: goto label_801844C8;
    case 0x801844CCu: goto label_801844CC;
    case 0x801844D0u: goto label_801844D0;
    case 0x801844D4u: goto label_801844D4;
    case 0x801844D8u: goto label_801844D8;
    case 0x801844DCu: goto label_801844DC;
    case 0x801844E0u: goto label_801844E0;
    case 0x801844E4u: goto label_801844E4;
    case 0x801844E8u: goto label_801844E8;
    case 0x801844ECu: goto label_801844EC;
    case 0x801844F0u: goto label_801844F0;
    case 0x801844F4u: goto label_801844F4;
    case 0x801844F8u: goto label_801844F8;
    case 0x801844FCu: goto label_801844FC;
    case 0x80184500u: goto label_80184500;
    case 0x80184504u: goto label_80184504;
    case 0x80184508u: goto label_80184508;
    case 0x8018450Cu: goto label_8018450C;
    case 0x80184510u: goto label_80184510;
    case 0x80184514u: goto label_80184514;
    case 0x80184518u: goto label_80184518;
    case 0x8018451Cu: goto label_8018451C;
    case 0x80184520u: goto label_80184520;
    case 0x80184524u: goto label_80184524;
    case 0x80184528u: goto label_80184528;
    case 0x8018452Cu: goto label_8018452C;
    case 0x80184530u: goto label_80184530;
    case 0x80184534u: goto label_80184534;
    case 0x80184538u: goto label_80184538;
    case 0x8018453Cu: goto label_8018453C;
    case 0x80184540u: goto label_80184540;
    case 0x80184544u: goto label_80184544;
    case 0x80184548u: goto label_80184548;
    case 0x8018454Cu: goto label_8018454C;
    case 0x80184550u: goto label_80184550;
    case 0x80184554u: goto label_80184554;
    case 0x80184558u: goto label_80184558;
    case 0x8018455Cu: goto label_8018455C;
    case 0x80184560u: goto label_80184560;
    case 0x80184564u: goto label_80184564;
    case 0x80184568u: goto label_80184568;
    case 0x8018456Cu: goto label_8018456C;
    case 0x80184570u: goto label_80184570;
    case 0x80184574u: goto label_80184574;
    case 0x80184578u: goto label_80184578;
    case 0x8018457Cu: goto label_8018457C;
    case 0x80184580u: goto label_80184580;
    case 0x80184584u: goto label_80184584;
    case 0x80184588u: goto label_80184588;
    case 0x8018458Cu: goto label_8018458C;
    case 0x80184590u: goto label_80184590;
    case 0x80184594u: goto label_80184594;
    case 0x80184598u: goto label_80184598;
    case 0x8018459Cu: goto label_8018459C;
    case 0x801845A0u: goto label_801845A0;
    case 0x801845A4u: goto label_801845A4;
    case 0x801845A8u: goto label_801845A8;
    case 0x801845ACu: goto label_801845AC;
    case 0x801845B0u: goto label_801845B0;
    case 0x801845B4u: goto label_801845B4;
    case 0x801845B8u: goto label_801845B8;
    case 0x801845BCu: goto label_801845BC;
    case 0x801845C0u: goto label_801845C0;
    case 0x801845C4u: goto label_801845C4;
    case 0x801845C8u: goto label_801845C8;
    case 0x801845CCu: goto label_801845CC;
    case 0x801845D0u: goto label_801845D0;
    case 0x801845D4u: goto label_801845D4;
    case 0x801845D8u: goto label_801845D8;
    case 0x801845DCu: goto label_801845DC;
    case 0x801845E0u: goto label_801845E0;
    case 0x801845E4u: goto label_801845E4;
    case 0x801845E8u: goto label_801845E8;
    case 0x801845ECu: goto label_801845EC;
    case 0x801845F0u: goto label_801845F0;
    case 0x801845F4u: goto label_801845F4;
    case 0x801845F8u: goto label_801845F8;
    case 0x801845FCu: goto label_801845FC;
    case 0x80184600u: goto label_80184600;
    case 0x80184604u: goto label_80184604;
    case 0x80184608u: goto label_80184608;
    case 0x8018460Cu: goto label_8018460C;
    case 0x80184610u: goto label_80184610;
    case 0x80184614u: goto label_80184614;
    case 0x80184618u: goto label_80184618;
    case 0x8018461Cu: goto label_8018461C;
    case 0x80184620u: goto label_80184620;
    case 0x80184624u: goto label_80184624;
    case 0x80184628u: goto label_80184628;
    case 0x8018462Cu: goto label_8018462C;
    case 0x80184630u: goto label_80184630;
    case 0x80184634u: goto label_80184634;
    case 0x80184638u: goto label_80184638;
    case 0x8018463Cu: goto label_8018463C;
    case 0x80184640u: goto label_80184640;
    case 0x80184644u: goto label_80184644;
    case 0x80184648u: goto label_80184648;
    case 0x8018464Cu: goto label_8018464C;
    case 0x80184650u: goto label_80184650;
    case 0x80184654u: goto label_80184654;
    case 0x80184658u: goto label_80184658;
    case 0x8018465Cu: goto label_8018465C;
    case 0x80184660u: goto label_80184660;
    case 0x80184664u: goto label_80184664;
    case 0x80184668u: goto label_80184668;
    case 0x8018466Cu: goto label_8018466C;
    case 0x80184670u: goto label_80184670;
    case 0x80184674u: goto label_80184674;
    case 0x80184678u: goto label_80184678;
    case 0x8018467Cu: goto label_8018467C;
    case 0x80184680u: goto label_80184680;
    case 0x80184684u: goto label_80184684;
    case 0x80184688u: goto label_80184688;
    case 0x8018468Cu: goto label_8018468C;
    case 0x80184690u: goto label_80184690;
    case 0x80184694u: goto label_80184694;
    case 0x80184698u: goto label_80184698;
    case 0x8018469Cu: goto label_8018469C;
    case 0x801846A0u: goto label_801846A0;
    case 0x801846A4u: goto label_801846A4;
    case 0x801846A8u: goto label_801846A8;
    case 0x801846ACu: goto label_801846AC;
    case 0x801846B0u: goto label_801846B0;
    case 0x801846B4u: goto label_801846B4;
    case 0x801846B8u: goto label_801846B8;
    case 0x801846BCu: goto label_801846BC;
    case 0x801846C0u: goto label_801846C0;
    case 0x801846C4u: goto label_801846C4;
    case 0x801846C8u: goto label_801846C8;
    case 0x801846CCu: goto label_801846CC;
    case 0x801846D0u: goto label_801846D0;
    case 0x801846D4u: goto label_801846D4;
    case 0x801846D8u: goto label_801846D8;
    case 0x801846DCu: goto label_801846DC;
    case 0x801846E0u: goto label_801846E0;
    case 0x801846E4u: goto label_801846E4;
    case 0x801846E8u: goto label_801846E8;
    case 0x801846ECu: goto label_801846EC;
    case 0x801846F0u: goto label_801846F0;
    case 0x801846F4u: goto label_801846F4;
    case 0x801846F8u: goto label_801846F8;
    case 0x801846FCu: goto label_801846FC;
    case 0x80184700u: goto label_80184700;
    case 0x80184704u: goto label_80184704;
    case 0x80184708u: goto label_80184708;
    case 0x8018470Cu: goto label_8018470C;
    case 0x80184710u: goto label_80184710;
    case 0x80184714u: goto label_80184714;
    case 0x80184718u: goto label_80184718;
    case 0x8018471Cu: goto label_8018471C;
    case 0x80184720u: goto label_80184720;
    case 0x80184724u: goto label_80184724;
    case 0x80184728u: goto label_80184728;
    case 0x8018472Cu: goto label_8018472C;
    case 0x80184730u: goto label_80184730;
    case 0x80184734u: goto label_80184734;
    case 0x80184738u: goto label_80184738;
    case 0x8018473Cu: goto label_8018473C;
    case 0x80184740u: goto label_80184740;
    case 0x80184744u: goto label_80184744;
    case 0x80184748u: goto label_80184748;
    case 0x8018474Cu: goto label_8018474C;
    case 0x80184750u: goto label_80184750;
    case 0x80184754u: goto label_80184754;
    case 0x80184758u: goto label_80184758;
    case 0x8018475Cu: goto label_8018475C;
    case 0x80184760u: goto label_80184760;
    case 0x80184764u: goto label_80184764;
    case 0x80184768u: goto label_80184768;
    case 0x8018476Cu: goto label_8018476C;
    case 0x80184770u: goto label_80184770;
    case 0x80184774u: goto label_80184774;
    case 0x80184778u: goto label_80184778;
    case 0x8018477Cu: goto label_8018477C;
    case 0x80184780u: goto label_80184780;
    case 0x80184784u: goto label_80184784;
    case 0x80184788u: goto label_80184788;
    case 0x8018478Cu: goto label_8018478C;
    case 0x80184790u: goto label_80184790;
    case 0x80184794u: goto label_80184794;
    case 0x80184798u: goto label_80184798;
    case 0x8018479Cu: goto label_8018479C;
    case 0x801847A0u: goto label_801847A0;
    case 0x801847A4u: goto label_801847A4;
    case 0x801847A8u: goto label_801847A8;
    case 0x801847ACu: goto label_801847AC;
    case 0x801847B0u: goto label_801847B0;
    case 0x801847B4u: goto label_801847B4;
    case 0x801847B8u: goto label_801847B8;
    case 0x801847BCu: goto label_801847BC;
    case 0x801847C0u: goto label_801847C0;
    case 0x801847C4u: goto label_801847C4;
    case 0x801847C8u: goto label_801847C8;
    case 0x801847CCu: goto label_801847CC;
    case 0x801847D0u: goto label_801847D0;
    case 0x801847D4u: goto label_801847D4;
    case 0x801847D8u: goto label_801847D8;
    case 0x801847DCu: goto label_801847DC;
    case 0x801847E0u: goto label_801847E0;
    case 0x801847E4u: goto label_801847E4;
    case 0x801847E8u: goto label_801847E8;
    case 0x801847ECu: goto label_801847EC;
    case 0x801847F0u: goto label_801847F0;
    case 0x801847F4u: goto label_801847F4;
    case 0x801847F8u: goto label_801847F8;
    case 0x801847FCu: goto label_801847FC;
    case 0x80184800u: goto label_80184800;
    case 0x80184804u: goto label_80184804;
    case 0x80184808u: goto label_80184808;
    case 0x8018480Cu: goto label_8018480C;
    case 0x80184810u: goto label_80184810;
    case 0x80184814u: goto label_80184814;
    case 0x80184818u: goto label_80184818;
    case 0x8018481Cu: goto label_8018481C;
    case 0x80184820u: goto label_80184820;
    case 0x80184824u: goto label_80184824;
    case 0x80184828u: goto label_80184828;
    case 0x8018482Cu: goto label_8018482C;
    case 0x80184830u: goto label_80184830;
    case 0x80184834u: goto label_80184834;
    case 0x80184838u: goto label_80184838;
    case 0x8018483Cu: goto label_8018483C;
    case 0x80184840u: goto label_80184840;
    case 0x80184844u: goto label_80184844;
    case 0x80184848u: goto label_80184848;
    case 0x8018484Cu: goto label_8018484C;
    case 0x80184850u: goto label_80184850;
    case 0x80184854u: goto label_80184854;
    case 0x80184858u: goto label_80184858;
    case 0x8018485Cu: goto label_8018485C;
    case 0x80184860u: goto label_80184860;
    case 0x80184864u: goto label_80184864;
    case 0x80184868u: goto label_80184868;
    case 0x8018486Cu: goto label_8018486C;
    case 0x80184870u: goto label_80184870;
    case 0x80184874u: goto label_80184874;
    case 0x80184878u: goto label_80184878;
    case 0x8018487Cu: goto label_8018487C;
    case 0x80184880u: goto label_80184880;
    case 0x80184884u: goto label_80184884;
    case 0x80184888u: goto label_80184888;
    case 0x8018488Cu: goto label_8018488C;
    case 0x80184890u: goto label_80184890;
    case 0x80184894u: goto label_80184894;
    case 0x80184898u: goto label_80184898;
    case 0x8018489Cu: goto label_8018489C;
    case 0x801848A0u: goto label_801848A0;
    case 0x801848A4u: goto label_801848A4;
    case 0x801848A8u: goto label_801848A8;
    case 0x801848ACu: goto label_801848AC;
    case 0x801848B0u: goto label_801848B0;
    case 0x801848B4u: goto label_801848B4;
    case 0x801848B8u: goto label_801848B8;
    case 0x801848BCu: goto label_801848BC;
    case 0x801848C0u: goto label_801848C0;
    case 0x801848C4u: goto label_801848C4;
    case 0x801848C8u: goto label_801848C8;
    case 0x801848CCu: goto label_801848CC;
    case 0x801848D0u: goto label_801848D0;
    case 0x801848D4u: goto label_801848D4;
    case 0x801848D8u: goto label_801848D8;
    case 0x801848DCu: goto label_801848DC;
    case 0x801848E0u: goto label_801848E0;
    case 0x801848E4u: goto label_801848E4;
    case 0x801848E8u: goto label_801848E8;
    case 0x801848ECu: goto label_801848EC;
    case 0x801848F0u: goto label_801848F0;
    case 0x801848F4u: goto label_801848F4;
    case 0x801848F8u: goto label_801848F8;
    case 0x801848FCu: goto label_801848FC;
    case 0x80184900u: goto label_80184900;
    case 0x80184904u: goto label_80184904;
    case 0x80184908u: goto label_80184908;
    case 0x8018490Cu: goto label_8018490C;
    case 0x80184910u: goto label_80184910;
    case 0x80184914u: goto label_80184914;
    case 0x80184918u: goto label_80184918;
    case 0x8018491Cu: goto label_8018491C;
    case 0x80184920u: goto label_80184920;
    case 0x80184924u: goto label_80184924;
    case 0x80184928u: goto label_80184928;
    case 0x8018492Cu: goto label_8018492C;
    case 0x80184930u: goto label_80184930;
    case 0x80184934u: goto label_80184934;
    case 0x80184938u: goto label_80184938;
    case 0x8018493Cu: goto label_8018493C;
    case 0x80184940u: goto label_80184940;
    case 0x80184944u: goto label_80184944;
    case 0x80184948u: goto label_80184948;
    case 0x8018494Cu: goto label_8018494C;
    case 0x80184950u: goto label_80184950;
    case 0x80184954u: goto label_80184954;
    case 0x80184958u: goto label_80184958;
    case 0x8018495Cu: goto label_8018495C;
    case 0x80184960u: goto label_80184960;
    case 0x80184964u: goto label_80184964;
    case 0x80184968u: goto label_80184968;
    case 0x8018496Cu: goto label_8018496C;
    case 0x80184970u: goto label_80184970;
    case 0x80184974u: goto label_80184974;
    case 0x80184978u: goto label_80184978;
    case 0x8018497Cu: goto label_8018497C;
    case 0x80184980u: goto label_80184980;
    case 0x80184984u: goto label_80184984;
    case 0x80184988u: goto label_80184988;
    case 0x8018498Cu: goto label_8018498C;
    case 0x80184990u: goto label_80184990;
    case 0x80184994u: goto label_80184994;
    case 0x80184998u: goto label_80184998;
    case 0x8018499Cu: goto label_8018499C;
    case 0x801849A0u: goto label_801849A0;
    case 0x801849A4u: goto label_801849A4;
    case 0x801849A8u: goto label_801849A8;
    case 0x801849ACu: goto label_801849AC;
    case 0x801849B0u: goto label_801849B0;
    case 0x801849B4u: goto label_801849B4;
    case 0x801849B8u: goto label_801849B8;
    case 0x801849BCu: goto label_801849BC;
    case 0x801849C0u: goto label_801849C0;
    case 0x801849C4u: goto label_801849C4;
    case 0x801849C8u: goto label_801849C8;
    case 0x801849CCu: goto label_801849CC;
    case 0x801849D0u: goto label_801849D0;
    case 0x801849D4u: goto label_801849D4;
    case 0x801849D8u: goto label_801849D8;
    case 0x801849DCu: goto label_801849DC;
    case 0x801849E0u: goto label_801849E0;
    case 0x801849E4u: goto label_801849E4;
    case 0x801849E8u: goto label_801849E8;
    case 0x801849ECu: goto label_801849EC;
    case 0x801849F0u: goto label_801849F0;
    case 0x801849F4u: goto label_801849F4;
    case 0x801849F8u: goto label_801849F8;
    case 0x801849FCu: goto label_801849FC;
    case 0x80184A00u: goto label_80184A00;
    case 0x80184A04u: goto label_80184A04;
    case 0x80184A08u: goto label_80184A08;
    case 0x80184A0Cu: goto label_80184A0C;
    case 0x80184A10u: goto label_80184A10;
    case 0x80184A14u: goto label_80184A14;
    case 0x80184A18u: goto label_80184A18;
    case 0x80184A1Cu: goto label_80184A1C;
    case 0x80184A20u: goto label_80184A20;
    case 0x80184A24u: goto label_80184A24;
    case 0x80184A28u: goto label_80184A28;
    case 0x80184A2Cu: goto label_80184A2C;
    case 0x80184A30u: goto label_80184A30;
    case 0x80184A34u: goto label_80184A34;
    case 0x80184A38u: goto label_80184A38;
    case 0x80184A3Cu: goto label_80184A3C;
    case 0x80184A40u: goto label_80184A40;
    case 0x80184A44u: goto label_80184A44;
    case 0x80184A48u: goto label_80184A48;
    case 0x80184A4Cu: goto label_80184A4C;
    case 0x80184A50u: goto label_80184A50;
    case 0x80184A54u: goto label_80184A54;
    case 0x80184A58u: goto label_80184A58;
    case 0x80184A5Cu: goto label_80184A5C;
    case 0x80184A60u: goto label_80184A60;
    case 0x80184A64u: goto label_80184A64;
    case 0x80184A68u: goto label_80184A68;
    case 0x80184A6Cu: goto label_80184A6C;
    case 0x80184A70u: goto label_80184A70;
    case 0x80184A74u: goto label_80184A74;
    case 0x80184A78u: goto label_80184A78;
    case 0x80184A7Cu: goto label_80184A7C;
    case 0x80184A80u: goto label_80184A80;
    case 0x80184A84u: goto label_80184A84;
    case 0x80184A88u: goto label_80184A88;
    case 0x80184A8Cu: goto label_80184A8C;
    case 0x80184A90u: goto label_80184A90;
    case 0x80184A94u: goto label_80184A94;
    case 0x80184A98u: goto label_80184A98;
    case 0x80184A9Cu: goto label_80184A9C;
    case 0x80184AA0u: goto label_80184AA0;
    case 0x80184AA4u: goto label_80184AA4;
    case 0x80184AA8u: goto label_80184AA8;
    case 0x80184AACu: goto label_80184AAC;
    case 0x80184AB0u: goto label_80184AB0;
    case 0x80184AB4u: goto label_80184AB4;
    case 0x80184AB8u: goto label_80184AB8;
    case 0x80184ABCu: goto label_80184ABC;
    case 0x80184AC0u: goto label_80184AC0;
    case 0x80184AC4u: goto label_80184AC4;
    case 0x80184AC8u: goto label_80184AC8;
    case 0x80184ACCu: goto label_80184ACC;
    case 0x80184AD0u: goto label_80184AD0;
    case 0x80184AD4u: goto label_80184AD4;
    case 0x80184AD8u: goto label_80184AD8;
    case 0x80184ADCu: goto label_80184ADC;
    case 0x80184AE0u: goto label_80184AE0;
    case 0x80184AE4u: goto label_80184AE4;
    case 0x80184AE8u: goto label_80184AE8;
    case 0x80184AECu: goto label_80184AEC;
    case 0x80184AF0u: goto label_80184AF0;
    case 0x80184AF4u: goto label_80184AF4;
    case 0x80184AF8u: goto label_80184AF8;
    case 0x80184AFCu: goto label_80184AFC;
    case 0x80184B00u: goto label_80184B00;
    case 0x80184B04u: goto label_80184B04;
    case 0x80184B08u: goto label_80184B08;
    case 0x80184B0Cu: goto label_80184B0C;
    case 0x80184B10u: goto label_80184B10;
    case 0x80184B14u: goto label_80184B14;
    case 0x80184B18u: goto label_80184B18;
    case 0x80184B1Cu: goto label_80184B1C;
    case 0x80184B20u: goto label_80184B20;
    case 0x80184B24u: goto label_80184B24;
    case 0x80184B28u: goto label_80184B28;
    case 0x80184B2Cu: goto label_80184B2C;
    case 0x80184B30u: goto label_80184B30;
    case 0x80184B34u: goto label_80184B34;
    case 0x80184B38u: goto label_80184B38;
    case 0x80184B3Cu: goto label_80184B3C;
    case 0x80184B40u: goto label_80184B40;
    case 0x80184B44u: goto label_80184B44;
    case 0x80184B48u: goto label_80184B48;
    case 0x80184B4Cu: goto label_80184B4C;
    case 0x80184B50u: goto label_80184B50;
    case 0x80184B54u: goto label_80184B54;
    case 0x80184B58u: goto label_80184B58;
    case 0x80184B5Cu: goto label_80184B5C;
    case 0x80184B60u: goto label_80184B60;
    case 0x80184B64u: goto label_80184B64;
    case 0x80184B68u: goto label_80184B68;
    case 0x80184B6Cu: goto label_80184B6C;
    case 0x80184B70u: goto label_80184B70;
    case 0x80184B74u: goto label_80184B74;
    case 0x80184B78u: goto label_80184B78;
    case 0x80184B7Cu: goto label_80184B7C;
    case 0x80184B80u: goto label_80184B80;
    case 0x80184B84u: goto label_80184B84;
    case 0x80184B88u: goto label_80184B88;
    case 0x80184B8Cu: goto label_80184B8C;
    case 0x80184B90u: goto label_80184B90;
    case 0x80184B94u: goto label_80184B94;
    case 0x80184B98u: goto label_80184B98;
    case 0x80184B9Cu: goto label_80184B9C;
    case 0x80184BA0u: goto label_80184BA0;
    case 0x80184BA4u: goto label_80184BA4;
    case 0x80184BA8u: goto label_80184BA8;
    case 0x80184BACu: goto label_80184BAC;
    case 0x80184BB0u: goto label_80184BB0;
    case 0x80184BB4u: goto label_80184BB4;
    case 0x80184BB8u: goto label_80184BB8;
    case 0x80184BBCu: goto label_80184BBC;
    case 0x80184BC0u: goto label_80184BC0;
    case 0x80184BC4u: goto label_80184BC4;
    case 0x80184BC8u: goto label_80184BC8;
    case 0x80184BCCu: goto label_80184BCC;
    case 0x80184BD0u: goto label_80184BD0;
    case 0x80184BD4u: goto label_80184BD4;
    case 0x80184BD8u: goto label_80184BD8;
    case 0x80184BDCu: goto label_80184BDC;
    case 0x80184BE0u: goto label_80184BE0;
    case 0x80184BE4u: goto label_80184BE4;
    case 0x80184BE8u: goto label_80184BE8;
    case 0x80184BECu: goto label_80184BEC;
    case 0x80184BF0u: goto label_80184BF0;
    case 0x80184BF4u: goto label_80184BF4;
    case 0x80184BF8u: goto label_80184BF8;
    case 0x80184BFCu: goto label_80184BFC;
    case 0x80184C00u: goto label_80184C00;
    case 0x80184C04u: goto label_80184C04;
    case 0x80184C08u: goto label_80184C08;
    case 0x80184C0Cu: goto label_80184C0C;
    case 0x80184C10u: goto label_80184C10;
    case 0x80184C14u: goto label_80184C14;
    case 0x80184C18u: goto label_80184C18;
    case 0x80184C1Cu: goto label_80184C1C;
    case 0x80184C20u: goto label_80184C20;
    case 0x80184C24u: goto label_80184C24;
    case 0x80184C28u: goto label_80184C28;
    case 0x80184C2Cu: goto label_80184C2C;
    case 0x80184C30u: goto label_80184C30;
    case 0x80184C34u: goto label_80184C34;
    case 0x80184C38u: goto label_80184C38;
    case 0x80184C3Cu: goto label_80184C3C;
    case 0x80184C40u: goto label_80184C40;
    case 0x80184C44u: goto label_80184C44;
    case 0x80184C48u: goto label_80184C48;
    case 0x80184C4Cu: goto label_80184C4C;
    case 0x80184C50u: goto label_80184C50;
    case 0x80184C54u: goto label_80184C54;
    case 0x80184C58u: goto label_80184C58;
    case 0x80184C5Cu: goto label_80184C5C;
    case 0x80184C60u: goto label_80184C60;
    case 0x80184C64u: goto label_80184C64;
    case 0x80184C68u: goto label_80184C68;
    case 0x80184C6Cu: goto label_80184C6C;
    case 0x80184C70u: goto label_80184C70;
    case 0x80184C74u: goto label_80184C74;
    case 0x80184C78u: goto label_80184C78;
    case 0x80184C7Cu: goto label_80184C7C;
    case 0x80184C80u: goto label_80184C80;
    case 0x80184C84u: goto label_80184C84;
    case 0x80184C88u: goto label_80184C88;
    case 0x80184C8Cu: goto label_80184C8C;
    case 0x80184C90u: goto label_80184C90;
    case 0x80184C94u: goto label_80184C94;
    case 0x80184C98u: goto label_80184C98;
    case 0x80184C9Cu: goto label_80184C9C;
    case 0x80184CA0u: goto label_80184CA0;
    case 0x80184CA4u: goto label_80184CA4;
    case 0x80184CA8u: goto label_80184CA8;
    case 0x80184CACu: goto label_80184CAC;
    case 0x80184CB0u: goto label_80184CB0;
    case 0x80184CB4u: goto label_80184CB4;
    case 0x80184CB8u: goto label_80184CB8;
    case 0x80184CBCu: goto label_80184CBC;
    case 0x80184CC0u: goto label_80184CC0;
    case 0x80184CC4u: goto label_80184CC4;
    case 0x80184CC8u: goto label_80184CC8;
    case 0x80184CCCu: goto label_80184CCC;
    case 0x80184CD0u: goto label_80184CD0;
    case 0x80184CD4u: goto label_80184CD4;
    case 0x80184CD8u: goto label_80184CD8;
    case 0x80184CDCu: goto label_80184CDC;
    case 0x80184CE0u: goto label_80184CE0;
    case 0x80184CE4u: goto label_80184CE4;
    case 0x80184CE8u: goto label_80184CE8;
    case 0x80184CECu: goto label_80184CEC;
    case 0x80184CF0u: goto label_80184CF0;
    case 0x80184CF4u: goto label_80184CF4;
    case 0x80184CF8u: goto label_80184CF8;
    case 0x80184CFCu: goto label_80184CFC;
    case 0x80184D00u: goto label_80184D00;
    case 0x80184D04u: goto label_80184D04;
    case 0x80184D08u: goto label_80184D08;
    case 0x80184D0Cu: goto label_80184D0C;
    case 0x80184D10u: goto label_80184D10;
    case 0x80184D14u: goto label_80184D14;
    case 0x80184D18u: goto label_80184D18;
    case 0x80184D1Cu: goto label_80184D1C;
    case 0x80184D20u: goto label_80184D20;
    case 0x80184D24u: goto label_80184D24;
    case 0x80184D28u: goto label_80184D28;
    case 0x80184D2Cu: goto label_80184D2C;
    case 0x80184D30u: goto label_80184D30;
    case 0x80184D34u: goto label_80184D34;
    case 0x80184D38u: goto label_80184D38;
    case 0x80184D3Cu: goto label_80184D3C;
    case 0x80184D40u: goto label_80184D40;
    case 0x80184D44u: goto label_80184D44;
    case 0x80184D48u: goto label_80184D48;
    case 0x80184D4Cu: goto label_80184D4C;
    case 0x80184D50u: goto label_80184D50;
    case 0x80184D54u: goto label_80184D54;
    case 0x80184D58u: goto label_80184D58;
    case 0x80184D5Cu: goto label_80184D5C;
    case 0x80184D60u: goto label_80184D60;
    case 0x80184D64u: goto label_80184D64;
    case 0x80184D68u: goto label_80184D68;
    case 0x80184D6Cu: goto label_80184D6C;
    case 0x80184D70u: goto label_80184D70;
    case 0x80184D74u: goto label_80184D74;
    case 0x80184D78u: goto label_80184D78;
    case 0x80184D7Cu: goto label_80184D7C;
    case 0x80184D80u: goto label_80184D80;
    case 0x80184D84u: goto label_80184D84;
    case 0x80184D88u: goto label_80184D88;
    case 0x80184D8Cu: goto label_80184D8C;
    case 0x80184D90u: goto label_80184D90;
    case 0x80184D94u: goto label_80184D94;
    case 0x80184D98u: goto label_80184D98;
    case 0x80184D9Cu: goto label_80184D9C;
    case 0x80184DA0u: goto label_80184DA0;
    case 0x80184DA4u: goto label_80184DA4;
    case 0x80184DA8u: goto label_80184DA8;
    case 0x80184DACu: goto label_80184DAC;
    case 0x80184DB0u: goto label_80184DB0;
    case 0x80184DB4u: goto label_80184DB4;
    case 0x80184DB8u: goto label_80184DB8;
    case 0x80184DBCu: goto label_80184DBC;
    case 0x80184DC0u: goto label_80184DC0;
    case 0x80184DC4u: goto label_80184DC4;
    case 0x80184DC8u: goto label_80184DC8;
    case 0x80184DCCu: goto label_80184DCC;
    case 0x80184DD0u: goto label_80184DD0;
    case 0x80184DD4u: goto label_80184DD4;
    case 0x80184DD8u: goto label_80184DD8;
    case 0x80184DDCu: goto label_80184DDC;
    case 0x80184DE0u: goto label_80184DE0;
    case 0x80184DE4u: goto label_80184DE4;
    case 0x80184DE8u: goto label_80184DE8;
    case 0x80184DECu: goto label_80184DEC;
    case 0x80184DF0u: goto label_80184DF0;
    case 0x80184DF4u: goto label_80184DF4;
    case 0x80184DF8u: goto label_80184DF8;
    case 0x80184DFCu: goto label_80184DFC;
    case 0x80184E00u: goto label_80184E00;
    case 0x80184E04u: goto label_80184E04;
    case 0x80184E08u: goto label_80184E08;
    case 0x80184E0Cu: goto label_80184E0C;
    case 0x80184E10u: goto label_80184E10;
    case 0x80184E14u: goto label_80184E14;
    case 0x80184E18u: goto label_80184E18;
    case 0x80184E1Cu: goto label_80184E1C;
    case 0x80184E20u: goto label_80184E20;
    case 0x80184E24u: goto label_80184E24;
    case 0x80184E28u: goto label_80184E28;
    case 0x80184E2Cu: goto label_80184E2C;
    case 0x80184E30u: goto label_80184E30;
    case 0x80184E34u: goto label_80184E34;
    case 0x80184E38u: goto label_80184E38;
    case 0x80184E3Cu: goto label_80184E3C;
    case 0x80184E40u: goto label_80184E40;
    case 0x80184E44u: goto label_80184E44;
    case 0x80184E48u: goto label_80184E48;
    case 0x80184E4Cu: goto label_80184E4C;
    case 0x80184E50u: goto label_80184E50;
    case 0x80184E54u: goto label_80184E54;
    case 0x80184E58u: goto label_80184E58;
    case 0x80184E5Cu: goto label_80184E5C;
    case 0x80184E60u: goto label_80184E60;
    case 0x80184E64u: goto label_80184E64;
    case 0x80184E68u: goto label_80184E68;
    case 0x80184E6Cu: goto label_80184E6C;
    case 0x80184E70u: goto label_80184E70;
    case 0x80184E74u: goto label_80184E74;
    case 0x80184E78u: goto label_80184E78;
    case 0x80184E7Cu: goto label_80184E7C;
    case 0x80184E80u: goto label_80184E80;
    case 0x80184E84u: goto label_80184E84;
    case 0x80184E88u: goto label_80184E88;
    case 0x80184E8Cu: goto label_80184E8C;
    case 0x80184E90u: goto label_80184E90;
    case 0x80184E94u: goto label_80184E94;
    case 0x80184E98u: goto label_80184E98;
    case 0x80184E9Cu: goto label_80184E9C;
    case 0x80184EA0u: goto label_80184EA0;
    case 0x80184EA4u: goto label_80184EA4;
    case 0x80184EA8u: goto label_80184EA8;
    case 0x80184EACu: goto label_80184EAC;
    case 0x80184EB0u: goto label_80184EB0;
    case 0x80184EB4u: goto label_80184EB4;
    case 0x80184EB8u: goto label_80184EB8;
    case 0x80184EBCu: goto label_80184EBC;
    case 0x80184EC0u: goto label_80184EC0;
    case 0x80184EC4u: goto label_80184EC4;
    case 0x80184EC8u: goto label_80184EC8;
    case 0x80184ECCu: goto label_80184ECC;
    case 0x80184ED0u: goto label_80184ED0;
    case 0x80184ED4u: goto label_80184ED4;
    case 0x80184ED8u: goto label_80184ED8;
    case 0x80184EDCu: goto label_80184EDC;
    case 0x80184EE0u: goto label_80184EE0;
    case 0x80184EE4u: goto label_80184EE4;
    case 0x80184EE8u: goto label_80184EE8;
    case 0x80184EECu: goto label_80184EEC;
    case 0x80184EF0u: goto label_80184EF0;
    case 0x80184EF4u: goto label_80184EF4;
    case 0x80184EF8u: goto label_80184EF8;
    case 0x80184EFCu: goto label_80184EFC;
    case 0x80184F00u: goto label_80184F00;
    case 0x80184F04u: goto label_80184F04;
    case 0x80184F08u: goto label_80184F08;
    case 0x80184F0Cu: goto label_80184F0C;
    case 0x80184F10u: goto label_80184F10;
    case 0x80184F14u: goto label_80184F14;
    case 0x80184F18u: goto label_80184F18;
    case 0x80184F1Cu: goto label_80184F1C;
    case 0x80184F20u: goto label_80184F20;
    case 0x80184F24u: goto label_80184F24;
    case 0x80184F28u: goto label_80184F28;
    case 0x80184F2Cu: goto label_80184F2C;
    case 0x80184F30u: goto label_80184F30;
    case 0x80184F34u: goto label_80184F34;
    case 0x80184F38u: goto label_80184F38;
    case 0x80184F3Cu: goto label_80184F3C;
    case 0x80184F40u: goto label_80184F40;
    case 0x80184F44u: goto label_80184F44;
    case 0x80184F48u: goto label_80184F48;
    case 0x80184F4Cu: goto label_80184F4C;
    case 0x80184F50u: goto label_80184F50;
    case 0x80184F54u: goto label_80184F54;
    case 0x80184F58u: goto label_80184F58;
    case 0x80184F5Cu: goto label_80184F5C;
    case 0x80184F60u: goto label_80184F60;
    case 0x80184F64u: goto label_80184F64;
    case 0x80184F68u: goto label_80184F68;
    case 0x80184F6Cu: goto label_80184F6C;
    case 0x80184F70u: goto label_80184F70;
    case 0x80184F74u: goto label_80184F74;
    case 0x80184F78u: goto label_80184F78;
    case 0x80184F7Cu: goto label_80184F7C;
    case 0x80184F80u: goto label_80184F80;
    case 0x80184F84u: goto label_80184F84;
    case 0x80184F88u: goto label_80184F88;
    case 0x80184F8Cu: goto label_80184F8C;
    case 0x80184F90u: goto label_80184F90;
    case 0x80184F94u: goto label_80184F94;
    case 0x80184F98u: goto label_80184F98;
    case 0x80184F9Cu: goto label_80184F9C;
    case 0x80184FA0u: goto label_80184FA0;
    case 0x80184FA4u: goto label_80184FA4;
    case 0x80184FA8u: goto label_80184FA8;
    case 0x80184FACu: goto label_80184FAC;
    case 0x80184FB0u: goto label_80184FB0;
    case 0x80184FB4u: goto label_80184FB4;
    case 0x80184FB8u: goto label_80184FB8;
    case 0x80184FBCu: goto label_80184FBC;
    case 0x80184FC0u: goto label_80184FC0;
    case 0x80184FC4u: goto label_80184FC4;
    case 0x80184FC8u: goto label_80184FC8;
    case 0x80184FCCu: goto label_80184FCC;
    case 0x80184FD0u: goto label_80184FD0;
    case 0x80184FD4u: goto label_80184FD4;
    case 0x80184FD8u: goto label_80184FD8;
    case 0x80184FDCu: goto label_80184FDC;
    case 0x80184FE0u: goto label_80184FE0;
    case 0x80184FE4u: goto label_80184FE4;
    case 0x80184FE8u: goto label_80184FE8;
    case 0x80184FECu: goto label_80184FEC;
    case 0x80184FF0u: goto label_80184FF0;
    case 0x80184FF4u: goto label_80184FF4;
    case 0x80184FF8u: goto label_80184FF8;
    case 0x80184FFCu: goto label_80184FFC;
    case 0x80185000u: goto label_80185000;
    case 0x80185004u: goto label_80185004;
    case 0x80185008u: goto label_80185008;
    case 0x8018500Cu: goto label_8018500C;
    case 0x80185010u: goto label_80185010;
    case 0x80185014u: goto label_80185014;
    case 0x80185018u: goto label_80185018;
    case 0x8018501Cu: goto label_8018501C;
    case 0x80185020u: goto label_80185020;
    case 0x80185024u: goto label_80185024;
    case 0x80185028u: goto label_80185028;
    case 0x8018502Cu: goto label_8018502C;
    case 0x80185030u: goto label_80185030;
    case 0x80185034u: goto label_80185034;
    case 0x80185038u: goto label_80185038;
    case 0x8018503Cu: goto label_8018503C;
    case 0x80185040u: goto label_80185040;
    case 0x80185044u: goto label_80185044;
    case 0x80185048u: goto label_80185048;
    case 0x8018504Cu: goto label_8018504C;
    case 0x80185050u: goto label_80185050;
    case 0x80185054u: goto label_80185054;
    case 0x80185058u: goto label_80185058;
    case 0x8018505Cu: goto label_8018505C;
    case 0x80185060u: goto label_80185060;
    case 0x80185064u: goto label_80185064;
    case 0x80185068u: goto label_80185068;
    case 0x8018506Cu: goto label_8018506C;
    case 0x80185070u: goto label_80185070;
    case 0x80185074u: goto label_80185074;
    case 0x80185078u: goto label_80185078;
    case 0x8018507Cu: goto label_8018507C;
    case 0x80185080u: goto label_80185080;
    case 0x80185084u: goto label_80185084;
    case 0x80185088u: goto label_80185088;
    case 0x8018508Cu: goto label_8018508C;
    case 0x80185090u: goto label_80185090;
    case 0x80185094u: goto label_80185094;
    case 0x80185098u: goto label_80185098;
    case 0x8018509Cu: goto label_8018509C;
    case 0x801850A0u: goto label_801850A0;
    case 0x801850A4u: goto label_801850A4;
    case 0x801850A8u: goto label_801850A8;
    case 0x801850ACu: goto label_801850AC;
    case 0x801850B0u: goto label_801850B0;
    case 0x801850B4u: goto label_801850B4;
    case 0x801850B8u: goto label_801850B8;
    case 0x801850BCu: goto label_801850BC;
    case 0x801850C0u: goto label_801850C0;
    case 0x801850C4u: goto label_801850C4;
    case 0x801850C8u: goto label_801850C8;
    case 0x801850CCu: goto label_801850CC;
    case 0x801850D0u: goto label_801850D0;
    case 0x801850D4u: goto label_801850D4;
    case 0x801850D8u: goto label_801850D8;
    case 0x801850DCu: goto label_801850DC;
    case 0x801850E0u: goto label_801850E0;
    case 0x801850E4u: goto label_801850E4;
    case 0x801850E8u: goto label_801850E8;
    case 0x801850ECu: goto label_801850EC;
    case 0x801850F0u: goto label_801850F0;
    case 0x801850F4u: goto label_801850F4;
    case 0x801850F8u: goto label_801850F8;
    case 0x801850FCu: goto label_801850FC;
    case 0x80185100u: goto label_80185100;
    case 0x80185104u: goto label_80185104;
    case 0x80185108u: goto label_80185108;
    case 0x8018510Cu: goto label_8018510C;
    case 0x80185110u: goto label_80185110;
    case 0x80185114u: goto label_80185114;
    case 0x80185118u: goto label_80185118;
    case 0x8018511Cu: goto label_8018511C;
    case 0x80185120u: goto label_80185120;
    case 0x80185124u: goto label_80185124;
    case 0x80185128u: goto label_80185128;
    case 0x8018512Cu: goto label_8018512C;
    case 0x80185130u: goto label_80185130;
    case 0x80185134u: goto label_80185134;
    case 0x80185138u: goto label_80185138;
    case 0x8018513Cu: goto label_8018513C;
    case 0x80185140u: goto label_80185140;
    case 0x80185144u: goto label_80185144;
    case 0x80185148u: goto label_80185148;
    case 0x8018514Cu: goto label_8018514C;
    case 0x80185150u: goto label_80185150;
    case 0x80185154u: goto label_80185154;
    case 0x80185158u: goto label_80185158;
    case 0x8018515Cu: goto label_8018515C;
    case 0x80185160u: goto label_80185160;
    case 0x80185164u: goto label_80185164;
    case 0x80185168u: goto label_80185168;
    case 0x8018516Cu: goto label_8018516C;
    case 0x80185170u: goto label_80185170;
    case 0x80185174u: goto label_80185174;
    case 0x80185178u: goto label_80185178;
    case 0x8018517Cu: goto label_8018517C;
    case 0x80185180u: goto label_80185180;
    case 0x80185184u: goto label_80185184;
    case 0x80185188u: goto label_80185188;
    case 0x8018518Cu: goto label_8018518C;
    case 0x80185190u: goto label_80185190;
    case 0x80185194u: goto label_80185194;
    case 0x80185198u: goto label_80185198;
    case 0x8018519Cu: goto label_8018519C;
    case 0x801851A0u: goto label_801851A0;
    case 0x801851A4u: goto label_801851A4;
    case 0x801851A8u: goto label_801851A8;
    case 0x801851ACu: goto label_801851AC;
    case 0x801851B0u: goto label_801851B0;
    case 0x801851B4u: goto label_801851B4;
    case 0x801851B8u: goto label_801851B8;
    case 0x801851BCu: goto label_801851BC;
    case 0x801851C0u: goto label_801851C0;
    case 0x801851C4u: goto label_801851C4;
    case 0x801851C8u: goto label_801851C8;
    case 0x801851CCu: goto label_801851CC;
    case 0x801851D0u: goto label_801851D0;
    case 0x801851D4u: goto label_801851D4;
    case 0x801851D8u: goto label_801851D8;
    case 0x801851DCu: goto label_801851DC;
    case 0x801851E0u: goto label_801851E0;
    case 0x801851E4u: goto label_801851E4;
    case 0x801851E8u: goto label_801851E8;
    case 0x801851ECu: goto label_801851EC;
    case 0x801851F0u: goto label_801851F0;
    case 0x801851F4u: goto label_801851F4;
    case 0x801851F8u: goto label_801851F8;
    case 0x801851FCu: goto label_801851FC;
    case 0x80185200u: goto label_80185200;
    case 0x80185204u: goto label_80185204;
    case 0x80185208u: goto label_80185208;
    case 0x8018520Cu: goto label_8018520C;
    case 0x80185210u: goto label_80185210;
    case 0x80185214u: goto label_80185214;
    case 0x80185218u: goto label_80185218;
    case 0x8018521Cu: goto label_8018521C;
    case 0x80185220u: goto label_80185220;
    case 0x80185224u: goto label_80185224;
    case 0x80185228u: goto label_80185228;
    case 0x8018522Cu: goto label_8018522C;
    case 0x80185230u: goto label_80185230;
    case 0x80185234u: goto label_80185234;
    case 0x80185238u: goto label_80185238;
    case 0x8018523Cu: goto label_8018523C;
    case 0x80185240u: goto label_80185240;
    case 0x80185244u: goto label_80185244;
    case 0x80185248u: goto label_80185248;
    case 0x8018524Cu: goto label_8018524C;
    case 0x80185250u: goto label_80185250;
    case 0x80185254u: goto label_80185254;
    case 0x80185258u: goto label_80185258;
    case 0x8018525Cu: goto label_8018525C;
    case 0x80185260u: goto label_80185260;
    case 0x80185264u: goto label_80185264;
    case 0x80185268u: goto label_80185268;
    case 0x8018526Cu: goto label_8018526C;
    case 0x80185270u: goto label_80185270;
    case 0x80185274u: goto label_80185274;
    case 0x80185278u: goto label_80185278;
    case 0x8018527Cu: goto label_8018527C;
    case 0x80185280u: goto label_80185280;
    case 0x80185284u: goto label_80185284;
    case 0x80185288u: goto label_80185288;
    case 0x8018528Cu: goto label_8018528C;
    case 0x80185290u: goto label_80185290;
    case 0x80185294u: goto label_80185294;
    case 0x80185298u: goto label_80185298;
    case 0x8018529Cu: goto label_8018529C;
    case 0x801852A0u: goto label_801852A0;
    case 0x801852A4u: goto label_801852A4;
    case 0x801852A8u: goto label_801852A8;
    case 0x801852ACu: goto label_801852AC;
    case 0x801852B0u: goto label_801852B0;
    case 0x801852B4u: goto label_801852B4;
    case 0x801852B8u: goto label_801852B8;
    case 0x801852BCu: goto label_801852BC;
    case 0x801852C0u: goto label_801852C0;
    case 0x801852C4u: goto label_801852C4;
    case 0x801852C8u: goto label_801852C8;
    case 0x801852CCu: goto label_801852CC;
    case 0x801852D0u: goto label_801852D0;
    case 0x801852D4u: goto label_801852D4;
    case 0x801852D8u: goto label_801852D8;
    case 0x801852DCu: goto label_801852DC;
    case 0x801852E0u: goto label_801852E0;
    case 0x801852E4u: goto label_801852E4;
    case 0x801852E8u: goto label_801852E8;
    case 0x801852ECu: goto label_801852EC;
    case 0x801852F0u: goto label_801852F0;
    case 0x801852F4u: goto label_801852F4;
    case 0x801852F8u: goto label_801852F8;
    case 0x801852FCu: goto label_801852FC;
    case 0x80185300u: goto label_80185300;
    case 0x80185304u: goto label_80185304;
    case 0x80185308u: goto label_80185308;
    case 0x8018530Cu: goto label_8018530C;
    case 0x80185310u: goto label_80185310;
    case 0x80185314u: goto label_80185314;
    case 0x80185318u: goto label_80185318;
    case 0x8018531Cu: goto label_8018531C;
    case 0x80185320u: goto label_80185320;
    case 0x80185324u: goto label_80185324;
    case 0x80185328u: goto label_80185328;
    case 0x8018532Cu: goto label_8018532C;
    case 0x80185330u: goto label_80185330;
    case 0x80185334u: goto label_80185334;
    case 0x80185338u: goto label_80185338;
    case 0x8018533Cu: goto label_8018533C;
    case 0x80185340u: goto label_80185340;
    case 0x80185344u: goto label_80185344;
    case 0x80185348u: goto label_80185348;
    case 0x8018534Cu: goto label_8018534C;
    case 0x80185350u: goto label_80185350;
    case 0x80185354u: goto label_80185354;
    case 0x80185358u: goto label_80185358;
    case 0x8018535Cu: goto label_8018535C;
    case 0x80185360u: goto label_80185360;
    case 0x80185364u: goto label_80185364;
    case 0x80185368u: goto label_80185368;
    case 0x8018536Cu: goto label_8018536C;
    case 0x80185370u: goto label_80185370;
    case 0x80185374u: goto label_80185374;
    case 0x80185378u: goto label_80185378;
    case 0x8018537Cu: goto label_8018537C;
    case 0x80185380u: goto label_80185380;
    case 0x80185384u: goto label_80185384;
    case 0x80185388u: goto label_80185388;
    case 0x8018538Cu: goto label_8018538C;
    case 0x80185390u: goto label_80185390;
    case 0x80185394u: goto label_80185394;
    case 0x80185398u: goto label_80185398;
    case 0x8018539Cu: goto label_8018539C;
    case 0x801853A0u: goto label_801853A0;
    case 0x801853A4u: goto label_801853A4;
    case 0x801853A8u: goto label_801853A8;
    case 0x801853ACu: goto label_801853AC;
    case 0x801853B0u: goto label_801853B0;
    case 0x801853B4u: goto label_801853B4;
    case 0x801853B8u: goto label_801853B8;
    case 0x801853BCu: goto label_801853BC;
    case 0x801853C0u: goto label_801853C0;
    case 0x801853C4u: goto label_801853C4;
    case 0x801853C8u: goto label_801853C8;
    case 0x801853CCu: goto label_801853CC;
    case 0x801853D0u: goto label_801853D0;
    case 0x801853D4u: goto label_801853D4;
    case 0x801853D8u: goto label_801853D8;
    case 0x801853DCu: goto label_801853DC;
    case 0x801853E0u: goto label_801853E0;
    case 0x801853E4u: goto label_801853E4;
    case 0x801853E8u: goto label_801853E8;
    case 0x801853ECu: goto label_801853EC;
    case 0x801853F0u: goto label_801853F0;
    case 0x801853F4u: goto label_801853F4;
    case 0x801853F8u: goto label_801853F8;
    case 0x801853FCu: goto label_801853FC;
    case 0x80185400u: goto label_80185400;
    case 0x80185404u: goto label_80185404;
    case 0x80185408u: goto label_80185408;
    case 0x8018540Cu: goto label_8018540C;
    case 0x80185410u: goto label_80185410;
    case 0x80185414u: goto label_80185414;
    case 0x80185418u: goto label_80185418;
    case 0x8018541Cu: goto label_8018541C;
    case 0x80185420u: goto label_80185420;
    case 0x80185424u: goto label_80185424;
    case 0x80185428u: goto label_80185428;
    case 0x8018542Cu: goto label_8018542C;
    case 0x80185430u: goto label_80185430;
    case 0x80185434u: goto label_80185434;
    case 0x80185438u: goto label_80185438;
    case 0x8018543Cu: goto label_8018543C;
    case 0x80185440u: goto label_80185440;
    case 0x80185444u: goto label_80185444;
    case 0x80185448u: goto label_80185448;
    case 0x8018544Cu: goto label_8018544C;
    case 0x80185450u: goto label_80185450;
    case 0x80185454u: goto label_80185454;
    case 0x80185458u: goto label_80185458;
    case 0x8018545Cu: goto label_8018545C;
    case 0x80185460u: goto label_80185460;
    case 0x80185464u: goto label_80185464;
    case 0x80185468u: goto label_80185468;
    case 0x8018546Cu: goto label_8018546C;
    case 0x80185470u: goto label_80185470;
    case 0x80185474u: goto label_80185474;
    case 0x80185478u: goto label_80185478;
    case 0x8018547Cu: goto label_8018547C;
    case 0x80185480u: goto label_80185480;
    case 0x80185484u: goto label_80185484;
    case 0x80185488u: goto label_80185488;
    case 0x8018548Cu: goto label_8018548C;
    case 0x80185490u: goto label_80185490;
    case 0x80185494u: goto label_80185494;
    case 0x80185498u: goto label_80185498;
    case 0x8018549Cu: goto label_8018549C;
    case 0x801854A0u: goto label_801854A0;
    case 0x801854A4u: goto label_801854A4;
    case 0x801854A8u: goto label_801854A8;
    case 0x801854ACu: goto label_801854AC;
    case 0x801854B0u: goto label_801854B0;
    case 0x801854B4u: goto label_801854B4;
    case 0x801854B8u: goto label_801854B8;
    case 0x801854BCu: goto label_801854BC;
    case 0x801854C0u: goto label_801854C0;
    case 0x801854C4u: goto label_801854C4;
    case 0x801854C8u: goto label_801854C8;
    case 0x801854CCu: goto label_801854CC;
    case 0x801854D0u: goto label_801854D0;
    case 0x801854D4u: goto label_801854D4;
    case 0x801854D8u: goto label_801854D8;
    case 0x801854DCu: goto label_801854DC;
    case 0x801854E0u: goto label_801854E0;
    case 0x801854E4u: goto label_801854E4;
    case 0x801854E8u: goto label_801854E8;
    case 0x801854ECu: goto label_801854EC;
    case 0x801854F0u: goto label_801854F0;
    case 0x801854F4u: goto label_801854F4;
    case 0x801854F8u: goto label_801854F8;
    case 0x801854FCu: goto label_801854FC;
    case 0x80185500u: goto label_80185500;
    case 0x80185504u: goto label_80185504;
    case 0x80185508u: goto label_80185508;
    case 0x8018550Cu: goto label_8018550C;
    case 0x80185510u: goto label_80185510;
    case 0x80185514u: goto label_80185514;
    case 0x80185518u: goto label_80185518;
    case 0x8018551Cu: goto label_8018551C;
    case 0x80185520u: goto label_80185520;
    case 0x80185524u: goto label_80185524;
    case 0x80185528u: goto label_80185528;
    case 0x8018552Cu: goto label_8018552C;
    case 0x80185530u: goto label_80185530;
    case 0x80185534u: goto label_80185534;
    case 0x80185538u: goto label_80185538;
    case 0x8018553Cu: goto label_8018553C;
    case 0x80185540u: goto label_80185540;
    case 0x80185544u: goto label_80185544;
    case 0x80185548u: goto label_80185548;
    case 0x8018554Cu: goto label_8018554C;
    case 0x80185550u: goto label_80185550;
    case 0x80185554u: goto label_80185554;
    case 0x80185558u: goto label_80185558;
    case 0x8018555Cu: goto label_8018555C;
    case 0x80185560u: goto label_80185560;
    case 0x80185564u: goto label_80185564;
    case 0x80185568u: goto label_80185568;
    case 0x8018556Cu: goto label_8018556C;
    case 0x80185570u: goto label_80185570;
    case 0x80185574u: goto label_80185574;
    case 0x80185578u: goto label_80185578;
    case 0x8018557Cu: goto label_8018557C;
    case 0x80185580u: goto label_80185580;
    case 0x80185584u: goto label_80185584;
    case 0x80185588u: goto label_80185588;
    case 0x8018558Cu: goto label_8018558C;
    case 0x80185590u: goto label_80185590;
    case 0x80185594u: goto label_80185594;
    case 0x80185598u: goto label_80185598;
    case 0x8018559Cu: goto label_8018559C;
    case 0x801855A0u: goto label_801855A0;
    case 0x801855A4u: goto label_801855A4;
    case 0x801855A8u: goto label_801855A8;
    case 0x801855ACu: goto label_801855AC;
    case 0x801855B0u: goto label_801855B0;
    case 0x801855B4u: goto label_801855B4;
    case 0x801855B8u: goto label_801855B8;
    case 0x801855BCu: goto label_801855BC;
    case 0x801855C0u: goto label_801855C0;
    case 0x801855C4u: goto label_801855C4;
    case 0x801855C8u: goto label_801855C8;
    case 0x801855CCu: goto label_801855CC;
    case 0x801855D0u: goto label_801855D0;
    case 0x801855D4u: goto label_801855D4;
    case 0x801855D8u: goto label_801855D8;
    case 0x801855DCu: goto label_801855DC;
    case 0x801855E0u: goto label_801855E0;
    case 0x801855E4u: goto label_801855E4;
    case 0x801855E8u: goto label_801855E8;
    case 0x801855ECu: goto label_801855EC;
    case 0x801855F0u: goto label_801855F0;
    case 0x801855F4u: goto label_801855F4;
    case 0x801855F8u: goto label_801855F8;
    case 0x801855FCu: goto label_801855FC;
    case 0x80185600u: goto label_80185600;
    case 0x80185604u: goto label_80185604;
    case 0x80185608u: goto label_80185608;
    case 0x8018560Cu: goto label_8018560C;
    case 0x80185610u: goto label_80185610;
    case 0x80185614u: goto label_80185614;
    case 0x80185618u: goto label_80185618;
    case 0x8018561Cu: goto label_8018561C;
    case 0x80185620u: goto label_80185620;
    case 0x80185624u: goto label_80185624;
    case 0x80185628u: goto label_80185628;
    case 0x8018562Cu: goto label_8018562C;
    case 0x80185630u: goto label_80185630;
    case 0x80185634u: goto label_80185634;
    case 0x80185638u: goto label_80185638;
    case 0x8018563Cu: goto label_8018563C;
    case 0x80185640u: goto label_80185640;
    case 0x80185644u: goto label_80185644;
    case 0x80185648u: goto label_80185648;
    case 0x8018564Cu: goto label_8018564C;
    case 0x80185650u: goto label_80185650;
    case 0x80185654u: goto label_80185654;
    case 0x80185658u: goto label_80185658;
    case 0x8018565Cu: goto label_8018565C;
    case 0x80185660u: goto label_80185660;
    case 0x80185664u: goto label_80185664;
    case 0x80185668u: goto label_80185668;
    case 0x8018566Cu: goto label_8018566C;
    case 0x80185670u: goto label_80185670;
    case 0x80185674u: goto label_80185674;
    case 0x80185678u: goto label_80185678;
    case 0x8018567Cu: goto label_8018567C;
    case 0x80185680u: goto label_80185680;
    case 0x80185684u: goto label_80185684;
    case 0x80185688u: goto label_80185688;
    case 0x8018568Cu: goto label_8018568C;
    case 0x80185690u: goto label_80185690;
    case 0x80185694u: goto label_80185694;
    case 0x80185698u: goto label_80185698;
    case 0x8018569Cu: goto label_8018569C;
    case 0x801856A0u: goto label_801856A0;
    case 0x801856A4u: goto label_801856A4;
    case 0x801856A8u: goto label_801856A8;
    case 0x801856ACu: goto label_801856AC;
    case 0x801856B0u: goto label_801856B0;
    case 0x801856B4u: goto label_801856B4;
    case 0x801856B8u: goto label_801856B8;
    case 0x801856BCu: goto label_801856BC;
    case 0x801856C0u: goto label_801856C0;
    case 0x801856C4u: goto label_801856C4;
    case 0x801856C8u: goto label_801856C8;
    case 0x801856CCu: goto label_801856CC;
    case 0x801856D0u: goto label_801856D0;
    case 0x801856D4u: goto label_801856D4;
    case 0x801856D8u: goto label_801856D8;
    case 0x801856DCu: goto label_801856DC;
    case 0x801856E0u: goto label_801856E0;
    case 0x801856E4u: goto label_801856E4;
    case 0x801856E8u: goto label_801856E8;
    case 0x801856ECu: goto label_801856EC;
    case 0x801856F0u: goto label_801856F0;
    case 0x801856F4u: goto label_801856F4;
    case 0x801856F8u: goto label_801856F8;
    case 0x801856FCu: goto label_801856FC;
    case 0x80185700u: goto label_80185700;
    case 0x80185704u: goto label_80185704;
    case 0x80185708u: goto label_80185708;
    case 0x8018570Cu: goto label_8018570C;
    case 0x80185710u: goto label_80185710;
    case 0x80185714u: goto label_80185714;
    case 0x80185718u: goto label_80185718;
    case 0x8018571Cu: goto label_8018571C;
    case 0x80185720u: goto label_80185720;
    case 0x80185724u: goto label_80185724;
    case 0x80185728u: goto label_80185728;
    case 0x8018572Cu: goto label_8018572C;
    case 0x80185730u: goto label_80185730;
    case 0x80185734u: goto label_80185734;
    case 0x80185738u: goto label_80185738;
    case 0x8018573Cu: goto label_8018573C;
    case 0x80185740u: goto label_80185740;
    case 0x80185744u: goto label_80185744;
    case 0x80185748u: goto label_80185748;
    case 0x8018574Cu: goto label_8018574C;
    case 0x80185750u: goto label_80185750;
    case 0x80185754u: goto label_80185754;
    case 0x80185758u: goto label_80185758;
    case 0x8018575Cu: goto label_8018575C;
    case 0x80185760u: goto label_80185760;
    case 0x80185764u: goto label_80185764;
    case 0x80185768u: goto label_80185768;
    case 0x8018576Cu: goto label_8018576C;
    case 0x80185770u: goto label_80185770;
    case 0x80185774u: goto label_80185774;
    case 0x80185778u: goto label_80185778;
    case 0x8018577Cu: goto label_8018577C;
    case 0x80185780u: goto label_80185780;
    case 0x80185784u: goto label_80185784;
    case 0x80185788u: goto label_80185788;
    case 0x8018578Cu: goto label_8018578C;
    case 0x80185790u: goto label_80185790;
    case 0x80185794u: goto label_80185794;
    case 0x80185798u: goto label_80185798;
    case 0x8018579Cu: goto label_8018579C;
    case 0x801857A0u: goto label_801857A0;
    case 0x801857A4u: goto label_801857A4;
    case 0x801857A8u: goto label_801857A8;
    case 0x801857ACu: goto label_801857AC;
    case 0x801857B0u: goto label_801857B0;
    case 0x801857B4u: goto label_801857B4;
    case 0x801857B8u: goto label_801857B8;
    case 0x801857BCu: goto label_801857BC;
    case 0x801857C0u: goto label_801857C0;
    case 0x801857C4u: goto label_801857C4;
    case 0x801857C8u: goto label_801857C8;
    case 0x801857CCu: goto label_801857CC;
    case 0x801857D0u: goto label_801857D0;
    case 0x801857D4u: goto label_801857D4;
    case 0x801857D8u: goto label_801857D8;
    case 0x801857DCu: goto label_801857DC;
    case 0x801857E0u: goto label_801857E0;
    case 0x801857E4u: goto label_801857E4;
    case 0x801857E8u: goto label_801857E8;
    case 0x801857ECu: goto label_801857EC;
    case 0x801857F0u: goto label_801857F0;
    case 0x801857F4u: goto label_801857F4;
    case 0x801857F8u: goto label_801857F8;
    case 0x801857FCu: goto label_801857FC;
    case 0x80185800u: goto label_80185800;
    case 0x80185804u: goto label_80185804;
    case 0x80185808u: goto label_80185808;
    case 0x8018580Cu: goto label_8018580C;
    case 0x80185810u: goto label_80185810;
    case 0x80185814u: goto label_80185814;
    case 0x80185818u: goto label_80185818;
    case 0x8018581Cu: goto label_8018581C;
    case 0x80185820u: goto label_80185820;
    case 0x80185824u: goto label_80185824;
    case 0x80185828u: goto label_80185828;
    case 0x8018582Cu: goto label_8018582C;
    case 0x80185830u: goto label_80185830;
    case 0x80185834u: goto label_80185834;
    case 0x80185838u: goto label_80185838;
    case 0x8018583Cu: goto label_8018583C;
    case 0x80185840u: goto label_80185840;
    case 0x80185844u: goto label_80185844;
    case 0x80185848u: goto label_80185848;
    case 0x8018584Cu: goto label_8018584C;
    case 0x80185850u: goto label_80185850;
    case 0x80185854u: goto label_80185854;
    case 0x80185858u: goto label_80185858;
    case 0x8018585Cu: goto label_8018585C;
    case 0x80185860u: goto label_80185860;
    case 0x80185864u: goto label_80185864;
    case 0x80185868u: goto label_80185868;
    case 0x8018586Cu: goto label_8018586C;
    case 0x80185870u: goto label_80185870;
    case 0x80185874u: goto label_80185874;
    case 0x80185878u: goto label_80185878;
    case 0x8018587Cu: goto label_8018587C;
    case 0x80185880u: goto label_80185880;
    case 0x80185884u: goto label_80185884;
    case 0x80185888u: goto label_80185888;
    case 0x8018588Cu: goto label_8018588C;
    case 0x80185890u: goto label_80185890;
    case 0x80185894u: goto label_80185894;
    case 0x80185898u: goto label_80185898;
    case 0x8018589Cu: goto label_8018589C;
    case 0x801858A0u: goto label_801858A0;
    case 0x801858A4u: goto label_801858A4;
    case 0x801858A8u: goto label_801858A8;
    case 0x801858ACu: goto label_801858AC;
    case 0x801858B0u: goto label_801858B0;
    case 0x801858B4u: goto label_801858B4;
    case 0x801858B8u: goto label_801858B8;
    case 0x801858BCu: goto label_801858BC;
    case 0x801858C0u: goto label_801858C0;
    case 0x801858C4u: goto label_801858C4;
    case 0x801858C8u: goto label_801858C8;
    case 0x801858CCu: goto label_801858CC;
    case 0x801858D0u: goto label_801858D0;
    case 0x801858D4u: goto label_801858D4;
    case 0x801858D8u: goto label_801858D8;
    case 0x801858DCu: goto label_801858DC;
    case 0x801858E0u: goto label_801858E0;
    case 0x801858E4u: goto label_801858E4;
    case 0x801858E8u: goto label_801858E8;
    case 0x801858ECu: goto label_801858EC;
    case 0x801858F0u: goto label_801858F0;
    case 0x801858F4u: goto label_801858F4;
    case 0x801858F8u: goto label_801858F8;
    case 0x801858FCu: goto label_801858FC;
    case 0x80185900u: goto label_80185900;
    case 0x80185904u: goto label_80185904;
    case 0x80185908u: goto label_80185908;
    case 0x8018590Cu: goto label_8018590C;
    case 0x80185910u: goto label_80185910;
    case 0x80185914u: goto label_80185914;
    case 0x80185918u: goto label_80185918;
    case 0x8018591Cu: goto label_8018591C;
    case 0x80185920u: goto label_80185920;
    case 0x80185924u: goto label_80185924;
    case 0x80185928u: goto label_80185928;
    case 0x8018592Cu: goto label_8018592C;
    case 0x80185930u: goto label_80185930;
    case 0x80185934u: goto label_80185934;
    case 0x80185938u: goto label_80185938;
    case 0x8018593Cu: goto label_8018593C;
    case 0x80185940u: goto label_80185940;
    case 0x80185944u: goto label_80185944;
    case 0x80185948u: goto label_80185948;
    case 0x8018594Cu: goto label_8018594C;
    case 0x80185950u: goto label_80185950;
    case 0x80185954u: goto label_80185954;
    case 0x80185958u: goto label_80185958;
    case 0x8018595Cu: goto label_8018595C;
    case 0x80185960u: goto label_80185960;
    case 0x80185964u: goto label_80185964;
    case 0x80185968u: goto label_80185968;
    case 0x8018596Cu: goto label_8018596C;
    case 0x80185970u: goto label_80185970;
    case 0x80185974u: goto label_80185974;
    case 0x80185978u: goto label_80185978;
    case 0x8018597Cu: goto label_8018597C;
    case 0x80185980u: goto label_80185980;
    case 0x80185984u: goto label_80185984;
    case 0x80185988u: goto label_80185988;
    case 0x8018598Cu: goto label_8018598C;
    case 0x80185990u: goto label_80185990;
    case 0x80185994u: goto label_80185994;
    case 0x80185998u: goto label_80185998;
    case 0x8018599Cu: goto label_8018599C;
    case 0x801859A0u: goto label_801859A0;
    case 0x801859A4u: goto label_801859A4;
    case 0x801859A8u: goto label_801859A8;
    case 0x801859ACu: goto label_801859AC;
    case 0x801859B0u: goto label_801859B0;
    case 0x801859B4u: goto label_801859B4;
    case 0x801859B8u: goto label_801859B8;
    case 0x801859BCu: goto label_801859BC;
    case 0x801859C0u: goto label_801859C0;
    case 0x801859C4u: goto label_801859C4;
    case 0x801859C8u: goto label_801859C8;
    case 0x801859CCu: goto label_801859CC;
    case 0x801859D0u: goto label_801859D0;
    case 0x801859D4u: goto label_801859D4;
    case 0x801859D8u: goto label_801859D8;
    case 0x801859DCu: goto label_801859DC;
    case 0x801859E0u: goto label_801859E0;
    case 0x801859E4u: goto label_801859E4;
    case 0x801859E8u: goto label_801859E8;
    case 0x801859ECu: goto label_801859EC;
    case 0x801859F0u: goto label_801859F0;
    case 0x801859F4u: goto label_801859F4;
    case 0x801859F8u: goto label_801859F8;
    case 0x801859FCu: goto label_801859FC;
    case 0x80185A00u: goto label_80185A00;
    case 0x80185A04u: goto label_80185A04;
    case 0x80185A08u: goto label_80185A08;
    case 0x80185A0Cu: goto label_80185A0C;
    case 0x80185A10u: goto label_80185A10;
    case 0x80185A14u: goto label_80185A14;
    case 0x80185A18u: goto label_80185A18;
    case 0x80185A1Cu: goto label_80185A1C;
    case 0x80185A20u: goto label_80185A20;
    case 0x80185A24u: goto label_80185A24;
    case 0x80185A28u: goto label_80185A28;
    case 0x80185A2Cu: goto label_80185A2C;
    case 0x80185A30u: goto label_80185A30;
    case 0x80185A34u: goto label_80185A34;
    case 0x80185A38u: goto label_80185A38;
    case 0x80185A3Cu: goto label_80185A3C;
    case 0x80185A40u: goto label_80185A40;
    case 0x80185A44u: goto label_80185A44;
    case 0x80185A48u: goto label_80185A48;
    case 0x80185A4Cu: goto label_80185A4C;
    case 0x80185A50u: goto label_80185A50;
    case 0x80185A54u: goto label_80185A54;
    case 0x80185A58u: goto label_80185A58;
    case 0x80185A5Cu: goto label_80185A5C;
    case 0x80185A60u: goto label_80185A60;
    case 0x80185A64u: goto label_80185A64;
    case 0x80185A68u: goto label_80185A68;
    case 0x80185A6Cu: goto label_80185A6C;
    case 0x80185A70u: goto label_80185A70;
    case 0x80185A74u: goto label_80185A74;
    case 0x80185A78u: goto label_80185A78;
    case 0x80185A7Cu: goto label_80185A7C;
    case 0x80185A80u: goto label_80185A80;
    case 0x80185A84u: goto label_80185A84;
    case 0x80185A88u: goto label_80185A88;
    case 0x80185A8Cu: goto label_80185A8C;
    case 0x80185A90u: goto label_80185A90;
    case 0x80185A94u: goto label_80185A94;
    case 0x80185A98u: goto label_80185A98;
    case 0x80185A9Cu: goto label_80185A9C;
    case 0x80185AA0u: goto label_80185AA0;
    case 0x80185AA4u: goto label_80185AA4;
    case 0x80185AA8u: goto label_80185AA8;
    case 0x80185AACu: goto label_80185AAC;
    case 0x80185AB0u: goto label_80185AB0;
    case 0x80185AB4u: goto label_80185AB4;
    case 0x80185AB8u: goto label_80185AB8;
    case 0x80185ABCu: goto label_80185ABC;
    case 0x80185AC0u: goto label_80185AC0;
    case 0x80185AC4u: goto label_80185AC4;
    case 0x80185AC8u: goto label_80185AC8;
    case 0x80185ACCu: goto label_80185ACC;
    case 0x80185AD0u: goto label_80185AD0;
    case 0x80185AD4u: goto label_80185AD4;
    case 0x80185AD8u: goto label_80185AD8;
    case 0x80185ADCu: goto label_80185ADC;
    case 0x80185AE0u: goto label_80185AE0;
    case 0x80185AE4u: goto label_80185AE4;
    case 0x80185AE8u: goto label_80185AE8;
    case 0x80185AECu: goto label_80185AEC;
    case 0x80185AF0u: goto label_80185AF0;
    case 0x80185AF4u: goto label_80185AF4;
    case 0x80185AF8u: goto label_80185AF8;
    case 0x80185AFCu: goto label_80185AFC;
    case 0x80185B00u: goto label_80185B00;
    case 0x80185B04u: goto label_80185B04;
    case 0x80185B08u: goto label_80185B08;
    case 0x80185B0Cu: goto label_80185B0C;
    case 0x80185B10u: goto label_80185B10;
    case 0x80185B14u: goto label_80185B14;
    case 0x80185B18u: goto label_80185B18;
    case 0x80185B1Cu: goto label_80185B1C;
    case 0x80185B20u: goto label_80185B20;
    case 0x80185B24u: goto label_80185B24;
    case 0x80185B28u: goto label_80185B28;
    case 0x80185B2Cu: goto label_80185B2C;
    case 0x80185B30u: goto label_80185B30;
    case 0x80185B34u: goto label_80185B34;
    case 0x80185B38u: goto label_80185B38;
    case 0x80185B3Cu: goto label_80185B3C;
    case 0x80185B40u: goto label_80185B40;
    case 0x80185B44u: goto label_80185B44;
    case 0x80185B48u: goto label_80185B48;
    case 0x80185B4Cu: goto label_80185B4C;
    case 0x80185B50u: goto label_80185B50;
    case 0x80185B54u: goto label_80185B54;
    case 0x80185B58u: goto label_80185B58;
    case 0x80185B5Cu: goto label_80185B5C;
    case 0x80185B60u: goto label_80185B60;
    case 0x80185B64u: goto label_80185B64;
    case 0x80185B68u: goto label_80185B68;
    case 0x80185B6Cu: goto label_80185B6C;
    case 0x80185B70u: goto label_80185B70;
    case 0x80185B74u: goto label_80185B74;
    case 0x80185B78u: goto label_80185B78;
    case 0x80185B7Cu: goto label_80185B7C;
    case 0x80185B80u: goto label_80185B80;
    case 0x80185B84u: goto label_80185B84;
    case 0x80185B88u: goto label_80185B88;
    case 0x80185B8Cu: goto label_80185B8C;
    case 0x80185B90u: goto label_80185B90;
    case 0x80185B94u: goto label_80185B94;
    case 0x80185B98u: goto label_80185B98;
    case 0x80185B9Cu: goto label_80185B9C;
    case 0x80185BA0u: goto label_80185BA0;
    case 0x80185BA4u: goto label_80185BA4;
    case 0x80185BA8u: goto label_80185BA8;
    case 0x80185BACu: goto label_80185BAC;
    case 0x80185BB0u: goto label_80185BB0;
    case 0x80185BB4u: goto label_80185BB4;
    case 0x80185BB8u: goto label_80185BB8;
    case 0x80185BBCu: goto label_80185BBC;
    case 0x80185BC0u: goto label_80185BC0;
    case 0x80185BC4u: goto label_80185BC4;
    case 0x80185BC8u: goto label_80185BC8;
    case 0x80185BCCu: goto label_80185BCC;
    case 0x80185BD0u: goto label_80185BD0;
    case 0x80185BD4u: goto label_80185BD4;
    case 0x80185BD8u: goto label_80185BD8;
    case 0x80185BDCu: goto label_80185BDC;
    case 0x80185BE0u: goto label_80185BE0;
    case 0x80185BE4u: goto label_80185BE4;
    case 0x80185BE8u: goto label_80185BE8;
    case 0x80185BECu: goto label_80185BEC;
    case 0x80185BF0u: goto label_80185BF0;
    case 0x80185BF4u: goto label_80185BF4;
    case 0x80185BF8u: goto label_80185BF8;
    case 0x80185BFCu: goto label_80185BFC;
    case 0x80185C00u: goto label_80185C00;
    case 0x80185C04u: goto label_80185C04;
    case 0x80185C08u: goto label_80185C08;
    case 0x80185C0Cu: goto label_80185C0C;
    case 0x80185C10u: goto label_80185C10;
    case 0x80185C14u: goto label_80185C14;
    case 0x80185C18u: goto label_80185C18;
    case 0x80185C1Cu: goto label_80185C1C;
    case 0x80185C20u: goto label_80185C20;
    case 0x80185C24u: goto label_80185C24;
    case 0x80185C28u: goto label_80185C28;
    case 0x80185C2Cu: goto label_80185C2C;
    case 0x80185C30u: goto label_80185C30;
    case 0x80185C34u: goto label_80185C34;
    case 0x80185C38u: goto label_80185C38;
    case 0x80185C3Cu: goto label_80185C3C;
    case 0x80185C40u: goto label_80185C40;
    case 0x80185C44u: goto label_80185C44;
    case 0x80185C48u: goto label_80185C48;
    case 0x80185C4Cu: goto label_80185C4C;
    case 0x80185C50u: goto label_80185C50;
    case 0x80185C54u: goto label_80185C54;
    case 0x80185C58u: goto label_80185C58;
    case 0x80185C5Cu: goto label_80185C5C;
    case 0x80185C60u: goto label_80185C60;
    case 0x80185C64u: goto label_80185C64;
    case 0x80185C68u: goto label_80185C68;
    case 0x80185C6Cu: goto label_80185C6C;
    case 0x80185C70u: goto label_80185C70;
    case 0x80185C74u: goto label_80185C74;
    case 0x80185C78u: goto label_80185C78;
    case 0x80185C7Cu: goto label_80185C7C;
    case 0x80185C80u: goto label_80185C80;
    case 0x80185C84u: goto label_80185C84;
    case 0x80185C88u: goto label_80185C88;
    case 0x80185C8Cu: goto label_80185C8C;
    case 0x80185C90u: goto label_80185C90;
    case 0x80185C94u: goto label_80185C94;
    case 0x80185C98u: goto label_80185C98;
    case 0x80185C9Cu: goto label_80185C9C;
    case 0x80185CA0u: goto label_80185CA0;
    case 0x80185CA4u: goto label_80185CA4;
    case 0x80185CA8u: goto label_80185CA8;
    case 0x80185CACu: goto label_80185CAC;
    case 0x80185CB0u: goto label_80185CB0;
    case 0x80185CB4u: goto label_80185CB4;
    case 0x80185CB8u: goto label_80185CB8;
    case 0x80185CBCu: goto label_80185CBC;
    case 0x80185CC0u: goto label_80185CC0;
    case 0x80185CC4u: goto label_80185CC4;
    case 0x80185CC8u: goto label_80185CC8;
    case 0x80185CCCu: goto label_80185CCC;
    case 0x80185CD0u: goto label_80185CD0;
    case 0x80185CD4u: goto label_80185CD4;
    case 0x80185CD8u: goto label_80185CD8;
    case 0x80185CDCu: goto label_80185CDC;
    case 0x80185CE0u: goto label_80185CE0;
    case 0x80185CE4u: goto label_80185CE4;
    case 0x80185CE8u: goto label_80185CE8;
    case 0x80185CECu: goto label_80185CEC;
    case 0x80185CF0u: goto label_80185CF0;
    case 0x80185CF4u: goto label_80185CF4;
    case 0x80185CF8u: goto label_80185CF8;
    case 0x80185CFCu: goto label_80185CFC;
    case 0x80185D00u: goto label_80185D00;
    case 0x80185D04u: goto label_80185D04;
    case 0x80185D08u: goto label_80185D08;
    case 0x80185D0Cu: goto label_80185D0C;
    case 0x80185D10u: goto label_80185D10;
    case 0x80185D14u: goto label_80185D14;
    case 0x80185D18u: goto label_80185D18;
    case 0x80185D1Cu: goto label_80185D1C;
    case 0x80185D20u: goto label_80185D20;
    case 0x80185D24u: goto label_80185D24;
    case 0x80185D28u: goto label_80185D28;
    case 0x80185D2Cu: goto label_80185D2C;
    case 0x80185D30u: goto label_80185D30;
    case 0x80185D34u: goto label_80185D34;
    case 0x80185D38u: goto label_80185D38;
    case 0x80185D3Cu: goto label_80185D3C;
    case 0x80185D40u: goto label_80185D40;
    case 0x80185D44u: goto label_80185D44;
    case 0x80185D48u: goto label_80185D48;
    case 0x80185D4Cu: goto label_80185D4C;
    case 0x80185D50u: goto label_80185D50;
    case 0x80185D54u: goto label_80185D54;
    case 0x80185D58u: goto label_80185D58;
    case 0x80185D5Cu: goto label_80185D5C;
    case 0x80185D60u: goto label_80185D60;
    case 0x80185D64u: goto label_80185D64;
    case 0x80185D68u: goto label_80185D68;
    case 0x80185D6Cu: goto label_80185D6C;
    case 0x80185D70u: goto label_80185D70;
    case 0x80185D74u: goto label_80185D74;
    case 0x80185D78u: goto label_80185D78;
    case 0x80185D7Cu: goto label_80185D7C;
    case 0x80185D80u: goto label_80185D80;
    case 0x80185D84u: goto label_80185D84;
    case 0x80185D88u: goto label_80185D88;
    case 0x80185D8Cu: goto label_80185D8C;
    case 0x80185D90u: goto label_80185D90;
    case 0x80185D94u: goto label_80185D94;
    case 0x80185D98u: goto label_80185D98;
    case 0x80185D9Cu: goto label_80185D9C;
    case 0x80185DA0u: goto label_80185DA0;
    case 0x80185DA4u: goto label_80185DA4;
    case 0x80185DA8u: goto label_80185DA8;
    case 0x80185DACu: goto label_80185DAC;
    case 0x80185DB0u: goto label_80185DB0;
    case 0x80185DB4u: goto label_80185DB4;
    case 0x80185DB8u: goto label_80185DB8;
    case 0x80185DBCu: goto label_80185DBC;
    case 0x80185DC0u: goto label_80185DC0;
    case 0x80185DC4u: goto label_80185DC4;
    case 0x80185DC8u: goto label_80185DC8;
    case 0x80185DCCu: goto label_80185DCC;
    case 0x80185DD0u: goto label_80185DD0;
    case 0x80185DD4u: goto label_80185DD4;
    case 0x80185DD8u: goto label_80185DD8;
    case 0x80185DDCu: goto label_80185DDC;
    case 0x80185DE0u: goto label_80185DE0;
    case 0x80185DE4u: goto label_80185DE4;
    case 0x80185DE8u: goto label_80185DE8;
    case 0x80185DECu: goto label_80185DEC;
    case 0x80185DF0u: goto label_80185DF0;
    case 0x80185DF4u: goto label_80185DF4;
    case 0x80185DF8u: goto label_80185DF8;
    case 0x80185DFCu: goto label_80185DFC;
    case 0x80185E00u: goto label_80185E00;
    case 0x80185E04u: goto label_80185E04;
    case 0x80185E08u: goto label_80185E08;
    case 0x80185E0Cu: goto label_80185E0C;
    case 0x80185E10u: goto label_80185E10;
    case 0x80185E14u: goto label_80185E14;
    case 0x80185E18u: goto label_80185E18;
    case 0x80185E1Cu: goto label_80185E1C;
    case 0x80185E20u: goto label_80185E20;
    case 0x80185E24u: goto label_80185E24;
    case 0x80185E28u: goto label_80185E28;
    case 0x80185E2Cu: goto label_80185E2C;
    case 0x80185E30u: goto label_80185E30;
    case 0x80185E34u: goto label_80185E34;
    case 0x80185E38u: goto label_80185E38;
    case 0x80185E3Cu: goto label_80185E3C;
    case 0x80185E40u: goto label_80185E40;
    case 0x80185E44u: goto label_80185E44;
    case 0x80185E48u: goto label_80185E48;
    case 0x80185E4Cu: goto label_80185E4C;
    case 0x80185E50u: goto label_80185E50;
    case 0x80185E54u: goto label_80185E54;
    case 0x80185E58u: goto label_80185E58;
    case 0x80185E5Cu: goto label_80185E5C;
    case 0x80185E60u: goto label_80185E60;
    case 0x80185E64u: goto label_80185E64;
    case 0x80185E68u: goto label_80185E68;
    case 0x80185E6Cu: goto label_80185E6C;
    case 0x80185E70u: goto label_80185E70;
    case 0x80185E74u: goto label_80185E74;
    case 0x80185E78u: goto label_80185E78;
    case 0x80185E7Cu: goto label_80185E7C;
    case 0x80185E80u: goto label_80185E80;
    case 0x80185E84u: goto label_80185E84;
    case 0x80185E88u: goto label_80185E88;
    case 0x80185E8Cu: goto label_80185E8C;
    case 0x80185E90u: goto label_80185E90;
    case 0x80185E94u: goto label_80185E94;
    case 0x80185E98u: goto label_80185E98;
    case 0x80185E9Cu: goto label_80185E9C;
    case 0x80185EA0u: goto label_80185EA0;
    case 0x80185EA4u: goto label_80185EA4;
    case 0x80185EA8u: goto label_80185EA8;
    case 0x80185EACu: goto label_80185EAC;
    case 0x80185EB0u: goto label_80185EB0;
    case 0x80185EB4u: goto label_80185EB4;
    case 0x80185EB8u: goto label_80185EB8;
    case 0x80185EBCu: goto label_80185EBC;
    case 0x80185EC0u: goto label_80185EC0;
    case 0x80185EC4u: goto label_80185EC4;
    case 0x80185EC8u: goto label_80185EC8;
    case 0x80185ECCu: goto label_80185ECC;
    case 0x80185ED0u: goto label_80185ED0;
    case 0x80185ED4u: goto label_80185ED4;
    case 0x80185ED8u: goto label_80185ED8;
    case 0x80185EDCu: goto label_80185EDC;
    case 0x80185EE0u: goto label_80185EE0;
    case 0x80185EE4u: goto label_80185EE4;
    case 0x80185EE8u: goto label_80185EE8;
    case 0x80185EECu: goto label_80185EEC;
    case 0x80185EF0u: goto label_80185EF0;
    case 0x80185EF4u: goto label_80185EF4;
    case 0x80185EF8u: goto label_80185EF8;
    case 0x80185EFCu: goto label_80185EFC;
    case 0x80185F00u: goto label_80185F00;
    case 0x80185F04u: goto label_80185F04;
    case 0x80185F08u: goto label_80185F08;
    case 0x80185F0Cu: goto label_80185F0C;
    case 0x80185F10u: goto label_80185F10;
    case 0x80185F14u: goto label_80185F14;
    case 0x80185F18u: goto label_80185F18;
    case 0x80185F1Cu: goto label_80185F1C;
    case 0x80185F20u: goto label_80185F20;
    case 0x80185F24u: goto label_80185F24;
    case 0x80185F28u: goto label_80185F28;
    case 0x80185F2Cu: goto label_80185F2C;
    case 0x80185F30u: goto label_80185F30;
    case 0x80185F34u: goto label_80185F34;
    case 0x80185F38u: goto label_80185F38;
    case 0x80185F3Cu: goto label_80185F3C;
    case 0x80185F40u: goto label_80185F40;
    case 0x80185F44u: goto label_80185F44;
    case 0x80185F48u: goto label_80185F48;
    case 0x80185F4Cu: goto label_80185F4C;
    case 0x80185F50u: goto label_80185F50;
    case 0x80185F54u: goto label_80185F54;
    case 0x80185F58u: goto label_80185F58;
    case 0x80185F5Cu: goto label_80185F5C;
    case 0x80185F60u: goto label_80185F60;
    case 0x80185F64u: goto label_80185F64;
    case 0x80185F68u: goto label_80185F68;
    case 0x80185F6Cu: goto label_80185F6C;
    case 0x80185F70u: goto label_80185F70;
    case 0x80185F74u: goto label_80185F74;
    case 0x80185F78u: goto label_80185F78;
    case 0x80185F7Cu: goto label_80185F7C;
    case 0x80185F80u: goto label_80185F80;
    case 0x80185F84u: goto label_80185F84;
    case 0x80185F88u: goto label_80185F88;
    case 0x80185F8Cu: goto label_80185F8C;
    case 0x80185F90u: goto label_80185F90;
    case 0x80185F94u: goto label_80185F94;
    case 0x80185F98u: goto label_80185F98;
    case 0x80185F9Cu: goto label_80185F9C;
    case 0x80185FA0u: goto label_80185FA0;
    case 0x80185FA4u: goto label_80185FA4;
    case 0x80185FA8u: goto label_80185FA8;
    case 0x80185FACu: goto label_80185FAC;
    case 0x80185FB0u: goto label_80185FB0;
    case 0x80185FB4u: goto label_80185FB4;
    case 0x80185FB8u: goto label_80185FB8;
    case 0x80185FBCu: goto label_80185FBC;
    case 0x80185FC0u: goto label_80185FC0;
    case 0x80185FC4u: goto label_80185FC4;
    case 0x80185FC8u: goto label_80185FC8;
    case 0x80185FCCu: goto label_80185FCC;
    case 0x80185FD0u: goto label_80185FD0;
    case 0x80185FD4u: goto label_80185FD4;
    case 0x80185FD8u: goto label_80185FD8;
    case 0x80185FDCu: goto label_80185FDC;
    case 0x80185FE0u: goto label_80185FE0;
    case 0x80185FE4u: goto label_80185FE4;
    case 0x80185FE8u: goto label_80185FE8;
    case 0x80185FECu: goto label_80185FEC;
    case 0x80185FF0u: goto label_80185FF0;
    case 0x80185FF4u: goto label_80185FF4;
    case 0x80185FF8u: goto label_80185FF8;
    case 0x80185FFCu: goto label_80185FFC;
    case 0x80186000u: goto label_80186000;
    case 0x80186004u: goto label_80186004;
    case 0x80186008u: goto label_80186008;
    case 0x8018600Cu: goto label_8018600C;
    case 0x80186010u: goto label_80186010;
    case 0x80186014u: goto label_80186014;
    case 0x80186018u: goto label_80186018;
    case 0x8018601Cu: goto label_8018601C;
    case 0x80186020u: goto label_80186020;
    case 0x80186024u: goto label_80186024;
    case 0x80186028u: goto label_80186028;
    case 0x8018602Cu: goto label_8018602C;
    case 0x80186030u: goto label_80186030;
    case 0x80186034u: goto label_80186034;
    case 0x80186038u: goto label_80186038;
    case 0x8018603Cu: goto label_8018603C;
    case 0x80186040u: goto label_80186040;
    case 0x80186044u: goto label_80186044;
    case 0x80186048u: goto label_80186048;
    case 0x8018604Cu: goto label_8018604C;
    case 0x80186050u: goto label_80186050;
    case 0x80186054u: goto label_80186054;
    case 0x80186058u: goto label_80186058;
    case 0x8018605Cu: goto label_8018605C;
    case 0x80186060u: goto label_80186060;
    case 0x80186064u: goto label_80186064;
    case 0x80186068u: goto label_80186068;
    case 0x8018606Cu: goto label_8018606C;
    case 0x80186070u: goto label_80186070;
    case 0x80186074u: goto label_80186074;
    case 0x80186078u: goto label_80186078;
    case 0x8018607Cu: goto label_8018607C;
    case 0x80186080u: goto label_80186080;
    case 0x80186084u: goto label_80186084;
    case 0x80186088u: goto label_80186088;
    case 0x8018608Cu: goto label_8018608C;
    case 0x80186090u: goto label_80186090;
    case 0x80186094u: goto label_80186094;
    case 0x80186098u: goto label_80186098;
    case 0x8018609Cu: goto label_8018609C;
    case 0x801860A0u: goto label_801860A0;
    case 0x801860A4u: goto label_801860A4;
    case 0x801860A8u: goto label_801860A8;
    case 0x801860ACu: goto label_801860AC;
    case 0x801860B0u: goto label_801860B0;
    case 0x801860B4u: goto label_801860B4;
    case 0x801860B8u: goto label_801860B8;
    case 0x801860BCu: goto label_801860BC;
    case 0x801860C0u: goto label_801860C0;
    case 0x801860C4u: goto label_801860C4;
    case 0x801860C8u: goto label_801860C8;
    case 0x801860CCu: goto label_801860CC;
    case 0x801860D0u: goto label_801860D0;
    case 0x801860D4u: goto label_801860D4;
    case 0x801860D8u: goto label_801860D8;
    case 0x801860DCu: goto label_801860DC;
    case 0x801860E0u: goto label_801860E0;
    case 0x801860E4u: goto label_801860E4;
    case 0x801860E8u: goto label_801860E8;
    case 0x801860ECu: goto label_801860EC;
    case 0x801860F0u: goto label_801860F0;
    case 0x801860F4u: goto label_801860F4;
    case 0x801860F8u: goto label_801860F8;
    case 0x801860FCu: goto label_801860FC;
    case 0x80186100u: goto label_80186100;
    case 0x80186104u: goto label_80186104;
    case 0x80186108u: goto label_80186108;
    case 0x8018610Cu: goto label_8018610C;
    case 0x80186110u: goto label_80186110;
    case 0x80186114u: goto label_80186114;
    case 0x80186118u: goto label_80186118;
    case 0x8018611Cu: goto label_8018611C;
    case 0x80186120u: goto label_80186120;
    case 0x80186124u: goto label_80186124;
    case 0x80186128u: goto label_80186128;
    case 0x8018612Cu: goto label_8018612C;
    case 0x80186130u: goto label_80186130;
    case 0x80186134u: goto label_80186134;
    case 0x80186138u: goto label_80186138;
    case 0x8018613Cu: goto label_8018613C;
    case 0x80186140u: goto label_80186140;
    case 0x80186144u: goto label_80186144;
    case 0x80186148u: goto label_80186148;
    case 0x8018614Cu: goto label_8018614C;
    case 0x80186150u: goto label_80186150;
    case 0x80186154u: goto label_80186154;
    case 0x80186158u: goto label_80186158;
    case 0x8018615Cu: goto label_8018615C;
    case 0x80186160u: goto label_80186160;
    case 0x80186164u: goto label_80186164;
    case 0x80186168u: goto label_80186168;
    case 0x8018616Cu: goto label_8018616C;
    case 0x80186170u: goto label_80186170;
    case 0x80186174u: goto label_80186174;
    case 0x80186178u: goto label_80186178;
    case 0x8018617Cu: goto label_8018617C;
    case 0x80186180u: goto label_80186180;
    case 0x80186184u: goto label_80186184;
    case 0x80186188u: goto label_80186188;
    case 0x8018618Cu: goto label_8018618C;
    case 0x80186190u: goto label_80186190;
    case 0x80186194u: goto label_80186194;
    case 0x80186198u: goto label_80186198;
    case 0x8018619Cu: goto label_8018619C;
    case 0x801861A0u: goto label_801861A0;
    case 0x801861A4u: goto label_801861A4;
    case 0x801861A8u: goto label_801861A8;
    case 0x801861ACu: goto label_801861AC;
    case 0x801861B0u: goto label_801861B0;
    case 0x801861B4u: goto label_801861B4;
    case 0x801861B8u: goto label_801861B8;
    case 0x801861BCu: goto label_801861BC;
    case 0x801861C0u: goto label_801861C0;
    case 0x801861C4u: goto label_801861C4;
    case 0x801861C8u: goto label_801861C8;
    case 0x801861CCu: goto label_801861CC;
    case 0x801861D0u: goto label_801861D0;
    case 0x801861D4u: goto label_801861D4;
    case 0x801861D8u: goto label_801861D8;
    case 0x801861DCu: goto label_801861DC;
    case 0x801861E0u: goto label_801861E0;
    case 0x801861E4u: goto label_801861E4;
    case 0x801861E8u: goto label_801861E8;
    case 0x801861ECu: goto label_801861EC;
    case 0x801861F0u: goto label_801861F0;
    case 0x801861F4u: goto label_801861F4;
    case 0x801861F8u: goto label_801861F8;
    case 0x801861FCu: goto label_801861FC;
    case 0x80186200u: goto label_80186200;
    case 0x80186204u: goto label_80186204;
    case 0x80186208u: goto label_80186208;
    case 0x8018620Cu: goto label_8018620C;
    case 0x80186210u: goto label_80186210;
    case 0x80186214u: goto label_80186214;
    case 0x80186218u: goto label_80186218;
    case 0x8018621Cu: goto label_8018621C;
    case 0x80186220u: goto label_80186220;
    case 0x80186224u: goto label_80186224;
    case 0x80186228u: goto label_80186228;
    case 0x8018622Cu: goto label_8018622C;
    case 0x80186230u: goto label_80186230;
    case 0x80186234u: goto label_80186234;
    case 0x80186238u: goto label_80186238;
    case 0x8018623Cu: goto label_8018623C;
    case 0x80186240u: goto label_80186240;
    case 0x80186244u: goto label_80186244;
    case 0x80186248u: goto label_80186248;
    case 0x8018624Cu: goto label_8018624C;
    case 0x80186250u: goto label_80186250;
    case 0x80186254u: goto label_80186254;
    case 0x80186258u: goto label_80186258;
    case 0x8018625Cu: goto label_8018625C;
    case 0x80186260u: goto label_80186260;
    case 0x80186264u: goto label_80186264;
    case 0x80186268u: goto label_80186268;
    case 0x8018626Cu: goto label_8018626C;
    case 0x80186270u: goto label_80186270;
    case 0x80186274u: goto label_80186274;
    case 0x80186278u: goto label_80186278;
    case 0x8018627Cu: goto label_8018627C;
    case 0x80186280u: goto label_80186280;
    case 0x80186284u: goto label_80186284;
    case 0x80186288u: goto label_80186288;
    case 0x8018628Cu: goto label_8018628C;
    case 0x80186290u: goto label_80186290;
    case 0x80186294u: goto label_80186294;
    case 0x80186298u: goto label_80186298;
    case 0x8018629Cu: goto label_8018629C;
    case 0x801862A0u: goto label_801862A0;
    case 0x801862A4u: goto label_801862A4;
    case 0x801862A8u: goto label_801862A8;
    case 0x801862ACu: goto label_801862AC;
    case 0x801862B0u: goto label_801862B0;
    case 0x801862B4u: goto label_801862B4;
    case 0x801862B8u: goto label_801862B8;
    case 0x801862BCu: goto label_801862BC;
    case 0x801862C0u: goto label_801862C0;
    case 0x801862C4u: goto label_801862C4;
    case 0x801862C8u: goto label_801862C8;
    case 0x801862CCu: goto label_801862CC;
    case 0x801862D0u: goto label_801862D0;
    case 0x801862D4u: goto label_801862D4;
    case 0x801862D8u: goto label_801862D8;
    case 0x801862DCu: goto label_801862DC;
    case 0x801862E0u: goto label_801862E0;
    case 0x801862E4u: goto label_801862E4;
    case 0x801862E8u: goto label_801862E8;
    case 0x801862ECu: goto label_801862EC;
    case 0x801862F0u: goto label_801862F0;
    case 0x801862F4u: goto label_801862F4;
    case 0x801862F8u: goto label_801862F8;
    case 0x801862FCu: goto label_801862FC;
    case 0x80186300u: goto label_80186300;
    case 0x80186304u: goto label_80186304;
    case 0x80186308u: goto label_80186308;
    case 0x8018630Cu: goto label_8018630C;
    case 0x80186310u: goto label_80186310;
    case 0x80186314u: goto label_80186314;
    case 0x80186318u: goto label_80186318;
    case 0x8018631Cu: goto label_8018631C;
    case 0x80186320u: goto label_80186320;
    case 0x80186324u: goto label_80186324;
    case 0x80186328u: goto label_80186328;
    case 0x8018632Cu: goto label_8018632C;
    case 0x80186330u: goto label_80186330;
    case 0x80186334u: goto label_80186334;
    case 0x80186338u: goto label_80186338;
    case 0x8018633Cu: goto label_8018633C;
    case 0x80186340u: goto label_80186340;
    case 0x80186344u: goto label_80186344;
    case 0x80186348u: goto label_80186348;
    case 0x8018634Cu: goto label_8018634C;
    case 0x80186350u: goto label_80186350;
    case 0x80186354u: goto label_80186354;
    case 0x80186358u: goto label_80186358;
    case 0x8018635Cu: goto label_8018635C;
    case 0x80186360u: goto label_80186360;
    case 0x80186364u: goto label_80186364;
    case 0x80186368u: goto label_80186368;
    case 0x8018636Cu: goto label_8018636C;
    case 0x80186370u: goto label_80186370;
    case 0x80186374u: goto label_80186374;
    case 0x80186378u: goto label_80186378;
    case 0x8018637Cu: goto label_8018637C;
    case 0x80186380u: goto label_80186380;
    case 0x80186384u: goto label_80186384;
    case 0x80186388u: goto label_80186388;
    case 0x8018638Cu: goto label_8018638C;
    case 0x80186390u: goto label_80186390;
    case 0x80186394u: goto label_80186394;
    case 0x80186398u: goto label_80186398;
    case 0x8018639Cu: goto label_8018639C;
    case 0x801863A0u: goto label_801863A0;
    case 0x801863A4u: goto label_801863A4;
    case 0x801863A8u: goto label_801863A8;
    case 0x801863ACu: goto label_801863AC;
    case 0x801863B0u: goto label_801863B0;
    case 0x801863B4u: goto label_801863B4;
    case 0x801863B8u: goto label_801863B8;
    case 0x801863BCu: goto label_801863BC;
    case 0x801863C0u: goto label_801863C0;
    case 0x801863C4u: goto label_801863C4;
    case 0x801863C8u: goto label_801863C8;
    case 0x801863CCu: goto label_801863CC;
    case 0x801863D0u: goto label_801863D0;
    case 0x801863D4u: goto label_801863D4;
    case 0x801863D8u: goto label_801863D8;
    case 0x801863DCu: goto label_801863DC;
    case 0x801863E0u: goto label_801863E0;
    case 0x801863E4u: goto label_801863E4;
    case 0x801863E8u: goto label_801863E8;
    case 0x801863ECu: goto label_801863EC;
    case 0x801863F0u: goto label_801863F0;
    case 0x801863F4u: goto label_801863F4;
    case 0x801863F8u: goto label_801863F8;
    case 0x801863FCu: goto label_801863FC;
    case 0x80186400u: goto label_80186400;
    case 0x80186404u: goto label_80186404;
    case 0x80186408u: goto label_80186408;
    case 0x8018640Cu: goto label_8018640C;
    case 0x80186410u: goto label_80186410;
    case 0x80186414u: goto label_80186414;
    case 0x80186418u: goto label_80186418;
    case 0x8018641Cu: goto label_8018641C;
    case 0x80186420u: goto label_80186420;
    case 0x80186424u: goto label_80186424;
    case 0x80186428u: goto label_80186428;
    case 0x8018642Cu: goto label_8018642C;
    case 0x80186430u: goto label_80186430;
    case 0x80186434u: goto label_80186434;
    case 0x80186438u: goto label_80186438;
    case 0x8018643Cu: goto label_8018643C;
    case 0x80186440u: goto label_80186440;
    case 0x80186444u: goto label_80186444;
    case 0x80186448u: goto label_80186448;
    case 0x8018644Cu: goto label_8018644C;
    case 0x80186450u: goto label_80186450;
    case 0x80186454u: goto label_80186454;
    case 0x80186458u: goto label_80186458;
    case 0x8018645Cu: goto label_8018645C;
    case 0x80186460u: goto label_80186460;
    case 0x80186464u: goto label_80186464;
    case 0x80186468u: goto label_80186468;
    case 0x8018646Cu: goto label_8018646C;
    case 0x80186470u: goto label_80186470;
    case 0x80186474u: goto label_80186474;
    case 0x80186478u: goto label_80186478;
    case 0x8018647Cu: goto label_8018647C;
    case 0x80186480u: goto label_80186480;
    case 0x80186484u: goto label_80186484;
    case 0x80186488u: goto label_80186488;
    case 0x8018648Cu: goto label_8018648C;
    case 0x80186490u: goto label_80186490;
    case 0x80186494u: goto label_80186494;
    case 0x80186498u: goto label_80186498;
    case 0x8018649Cu: goto label_8018649C;
    case 0x801864A0u: goto label_801864A0;
    case 0x801864A4u: goto label_801864A4;
    case 0x801864A8u: goto label_801864A8;
    case 0x801864ACu: goto label_801864AC;
    case 0x801864B0u: goto label_801864B0;
    case 0x801864B4u: goto label_801864B4;
    case 0x801864B8u: goto label_801864B8;
    case 0x801864BCu: goto label_801864BC;
    case 0x801864C0u: goto label_801864C0;
    case 0x801864C4u: goto label_801864C4;
    case 0x801864C8u: goto label_801864C8;
    case 0x801864CCu: goto label_801864CC;
    case 0x801864D0u: goto label_801864D0;
    case 0x801864D4u: goto label_801864D4;
    case 0x801864D8u: goto label_801864D8;
    case 0x801864DCu: goto label_801864DC;
    case 0x801864E0u: goto label_801864E0;
    case 0x801864E4u: goto label_801864E4;
    case 0x801864E8u: goto label_801864E8;
    case 0x801864ECu: goto label_801864EC;
    case 0x801864F0u: goto label_801864F0;
    case 0x801864F4u: goto label_801864F4;
    case 0x801864F8u: goto label_801864F8;
    case 0x801864FCu: goto label_801864FC;
    case 0x80186500u: goto label_80186500;
    case 0x80186504u: goto label_80186504;
    case 0x80186508u: goto label_80186508;
    case 0x8018650Cu: goto label_8018650C;
    case 0x80186510u: goto label_80186510;
    case 0x80186514u: goto label_80186514;
    case 0x80186518u: goto label_80186518;
    case 0x8018651Cu: goto label_8018651C;
    case 0x80186520u: goto label_80186520;
    case 0x80186524u: goto label_80186524;
    case 0x80186528u: goto label_80186528;
    case 0x8018652Cu: goto label_8018652C;
    case 0x80186530u: goto label_80186530;
    case 0x80186534u: goto label_80186534;
    case 0x80186538u: goto label_80186538;
    case 0x8018653Cu: goto label_8018653C;
    case 0x80186540u: goto label_80186540;
    case 0x80186544u: goto label_80186544;
    case 0x80186548u: goto label_80186548;
    case 0x8018654Cu: goto label_8018654C;
    case 0x80186550u: goto label_80186550;
    case 0x80186554u: goto label_80186554;
    case 0x80186558u: goto label_80186558;
    case 0x8018655Cu: goto label_8018655C;
    case 0x80186560u: goto label_80186560;
    case 0x80186564u: goto label_80186564;
    case 0x80186568u: goto label_80186568;
    case 0x8018656Cu: goto label_8018656C;
    case 0x80186570u: goto label_80186570;
    case 0x80186574u: goto label_80186574;
    case 0x80186578u: goto label_80186578;
    case 0x8018657Cu: goto label_8018657C;
    case 0x80186580u: goto label_80186580;
    case 0x80186584u: goto label_80186584;
    case 0x80186588u: goto label_80186588;
    case 0x8018658Cu: goto label_8018658C;
    case 0x80186590u: goto label_80186590;
    case 0x80186594u: goto label_80186594;
    case 0x80186598u: goto label_80186598;
    case 0x8018659Cu: goto label_8018659C;
    case 0x801865A0u: goto label_801865A0;
    case 0x801865A4u: goto label_801865A4;
    case 0x801865A8u: goto label_801865A8;
    case 0x801865ACu: goto label_801865AC;
    case 0x801865B0u: goto label_801865B0;
    case 0x801865B4u: goto label_801865B4;
    case 0x801865B8u: goto label_801865B8;
    case 0x801865BCu: goto label_801865BC;
    case 0x801865C0u: goto label_801865C0;
    case 0x801865C4u: goto label_801865C4;
    case 0x801865C8u: goto label_801865C8;
    case 0x801865CCu: goto label_801865CC;
    case 0x801865D0u: goto label_801865D0;
    case 0x801865D4u: goto label_801865D4;
    case 0x801865D8u: goto label_801865D8;
    case 0x801865DCu: goto label_801865DC;
    case 0x801865E0u: goto label_801865E0;
    case 0x801865E4u: goto label_801865E4;
    case 0x801865E8u: goto label_801865E8;
    case 0x801865ECu: goto label_801865EC;
    case 0x801865F0u: goto label_801865F0;
    case 0x801865F4u: goto label_801865F4;
    case 0x801865F8u: goto label_801865F8;
    case 0x801865FCu: goto label_801865FC;
    case 0x80186600u: goto label_80186600;
    case 0x80186604u: goto label_80186604;
    case 0x80186608u: goto label_80186608;
    case 0x8018660Cu: goto label_8018660C;
    case 0x80186610u: goto label_80186610;
    case 0x80186614u: goto label_80186614;
    case 0x80186618u: goto label_80186618;
    case 0x8018661Cu: goto label_8018661C;
    case 0x80186620u: goto label_80186620;
    case 0x80186624u: goto label_80186624;
    case 0x80186628u: goto label_80186628;
    case 0x8018662Cu: goto label_8018662C;
    case 0x80186630u: goto label_80186630;
    case 0x80186634u: goto label_80186634;
    case 0x80186638u: goto label_80186638;
    case 0x8018663Cu: goto label_8018663C;
    case 0x80186640u: goto label_80186640;
    case 0x80186644u: goto label_80186644;
    case 0x80186648u: goto label_80186648;
    case 0x8018664Cu: goto label_8018664C;
    case 0x80186650u: goto label_80186650;
    case 0x80186654u: goto label_80186654;
    case 0x80186658u: goto label_80186658;
    case 0x8018665Cu: goto label_8018665C;
    case 0x80186660u: goto label_80186660;
    case 0x80186664u: goto label_80186664;
    case 0x80186668u: goto label_80186668;
    case 0x8018666Cu: goto label_8018666C;
    case 0x80186670u: goto label_80186670;
    case 0x80186674u: goto label_80186674;
    case 0x80186678u: goto label_80186678;
    case 0x8018667Cu: goto label_8018667C;
    case 0x80186680u: goto label_80186680;
    case 0x80186684u: goto label_80186684;
    case 0x80186688u: goto label_80186688;
    case 0x8018668Cu: goto label_8018668C;
    case 0x80186690u: goto label_80186690;
    case 0x80186694u: goto label_80186694;
    case 0x80186698u: goto label_80186698;
    case 0x8018669Cu: goto label_8018669C;
    case 0x801866A0u: goto label_801866A0;
    case 0x801866A4u: goto label_801866A4;
    case 0x801866A8u: goto label_801866A8;
    case 0x801866ACu: goto label_801866AC;
    case 0x801866B0u: goto label_801866B0;
    case 0x801866B4u: goto label_801866B4;
    case 0x801866B8u: goto label_801866B8;
    case 0x801866BCu: goto label_801866BC;
    case 0x801866C0u: goto label_801866C0;
    case 0x801866C4u: goto label_801866C4;
    case 0x801866C8u: goto label_801866C8;
    case 0x801866CCu: goto label_801866CC;
    case 0x801866D0u: goto label_801866D0;
    case 0x801866D4u: goto label_801866D4;
    case 0x801866D8u: goto label_801866D8;
    case 0x801866DCu: goto label_801866DC;
    case 0x801866E0u: goto label_801866E0;
    case 0x801866E4u: goto label_801866E4;
    case 0x801866E8u: goto label_801866E8;
    case 0x801866ECu: goto label_801866EC;
    case 0x801866F0u: goto label_801866F0;
    case 0x801866F4u: goto label_801866F4;
    case 0x801866F8u: goto label_801866F8;
    case 0x801866FCu: goto label_801866FC;
    case 0x80186700u: goto label_80186700;
    case 0x80186704u: goto label_80186704;
    case 0x80186708u: goto label_80186708;
    case 0x8018670Cu: goto label_8018670C;
    case 0x80186710u: goto label_80186710;
    case 0x80186714u: goto label_80186714;
    case 0x80186718u: goto label_80186718;
    case 0x8018671Cu: goto label_8018671C;
    case 0x80186720u: goto label_80186720;
    case 0x80186724u: goto label_80186724;
    case 0x80186728u: goto label_80186728;
    case 0x8018672Cu: goto label_8018672C;
    case 0x80186730u: goto label_80186730;
    case 0x80186734u: goto label_80186734;
    case 0x80186738u: goto label_80186738;
    case 0x8018673Cu: goto label_8018673C;
    case 0x80186740u: goto label_80186740;
    case 0x80186744u: goto label_80186744;
    case 0x80186748u: goto label_80186748;
    case 0x8018674Cu: goto label_8018674C;
    case 0x80186750u: goto label_80186750;
    case 0x80186754u: goto label_80186754;
    case 0x80186758u: goto label_80186758;
    case 0x8018675Cu: goto label_8018675C;
    case 0x80186760u: goto label_80186760;
    case 0x80186764u: goto label_80186764;
    case 0x80186768u: goto label_80186768;
    case 0x8018676Cu: goto label_8018676C;
    case 0x80186770u: goto label_80186770;
    case 0x80186774u: goto label_80186774;
    case 0x80186778u: goto label_80186778;
    case 0x8018677Cu: goto label_8018677C;
    case 0x80186780u: goto label_80186780;
    case 0x80186784u: goto label_80186784;
    case 0x80186788u: goto label_80186788;
    case 0x8018678Cu: goto label_8018678C;
    case 0x80186790u: goto label_80186790;
    case 0x80186794u: goto label_80186794;
    case 0x80186798u: goto label_80186798;
    case 0x8018679Cu: goto label_8018679C;
    case 0x801867A0u: goto label_801867A0;
    case 0x801867A4u: goto label_801867A4;
    case 0x801867A8u: goto label_801867A8;
    case 0x801867ACu: goto label_801867AC;
    case 0x801867B0u: goto label_801867B0;
    case 0x801867B4u: goto label_801867B4;
    case 0x801867B8u: goto label_801867B8;
    case 0x801867BCu: goto label_801867BC;
    case 0x801867C0u: goto label_801867C0;
    case 0x801867C4u: goto label_801867C4;
    case 0x801867C8u: goto label_801867C8;
    case 0x801867CCu: goto label_801867CC;
    case 0x801867D0u: goto label_801867D0;
    case 0x801867D4u: goto label_801867D4;
    case 0x801867D8u: goto label_801867D8;
    case 0x801867DCu: goto label_801867DC;
    case 0x801867E0u: goto label_801867E0;
    case 0x801867E4u: goto label_801867E4;
    case 0x801867E8u: goto label_801867E8;
    case 0x801867ECu: goto label_801867EC;
    case 0x801867F0u: goto label_801867F0;
    case 0x801867F4u: goto label_801867F4;
    case 0x801867F8u: goto label_801867F8;
    case 0x801867FCu: goto label_801867FC;
    case 0x80186800u: goto label_80186800;
    case 0x80186804u: goto label_80186804;
    case 0x80186808u: goto label_80186808;
    case 0x8018680Cu: goto label_8018680C;
    case 0x80186810u: goto label_80186810;
    case 0x80186814u: goto label_80186814;
    case 0x80186818u: goto label_80186818;
    case 0x8018681Cu: goto label_8018681C;
    case 0x80186820u: goto label_80186820;
    case 0x80186824u: goto label_80186824;
    case 0x80186828u: goto label_80186828;
    case 0x8018682Cu: goto label_8018682C;
    case 0x80186830u: goto label_80186830;
    case 0x80186834u: goto label_80186834;
    case 0x80186838u: goto label_80186838;
    case 0x8018683Cu: goto label_8018683C;
    case 0x80186840u: goto label_80186840;
    case 0x80186844u: goto label_80186844;
    case 0x80186848u: goto label_80186848;
    case 0x8018684Cu: goto label_8018684C;
    case 0x80186850u: goto label_80186850;
    case 0x80186854u: goto label_80186854;
    case 0x80186858u: goto label_80186858;
    case 0x8018685Cu: goto label_8018685C;
    case 0x80186860u: goto label_80186860;
    case 0x80186864u: goto label_80186864;
    case 0x80186868u: goto label_80186868;
    case 0x8018686Cu: goto label_8018686C;
    case 0x80186870u: goto label_80186870;
    case 0x80186874u: goto label_80186874;
    case 0x80186878u: goto label_80186878;
    case 0x8018687Cu: goto label_8018687C;
    case 0x80186880u: goto label_80186880;
    case 0x80186884u: goto label_80186884;
    case 0x80186888u: goto label_80186888;
    case 0x8018688Cu: goto label_8018688C;
    case 0x80186890u: goto label_80186890;
    case 0x80186894u: goto label_80186894;
    case 0x80186898u: goto label_80186898;
    case 0x8018689Cu: goto label_8018689C;
    case 0x801868A0u: goto label_801868A0;
    case 0x801868A4u: goto label_801868A4;
    case 0x801868A8u: goto label_801868A8;
    case 0x801868ACu: goto label_801868AC;
    case 0x801868B0u: goto label_801868B0;
    case 0x801868B4u: goto label_801868B4;
    case 0x801868B8u: goto label_801868B8;
    case 0x801868BCu: goto label_801868BC;
    case 0x801868C0u: goto label_801868C0;
    case 0x801868C4u: goto label_801868C4;
    case 0x801868C8u: goto label_801868C8;
    case 0x801868CCu: goto label_801868CC;
    case 0x801868D0u: goto label_801868D0;
    case 0x801868D4u: goto label_801868D4;
    case 0x801868D8u: goto label_801868D8;
    case 0x801868DCu: goto label_801868DC;
    case 0x801868E0u: goto label_801868E0;
    case 0x801868E4u: goto label_801868E4;
    case 0x801868E8u: goto label_801868E8;
    case 0x801868ECu: goto label_801868EC;
    case 0x801868F0u: goto label_801868F0;
    case 0x801868F4u: goto label_801868F4;
    case 0x801868F8u: goto label_801868F8;
    case 0x801868FCu: goto label_801868FC;
    case 0x80186900u: goto label_80186900;
    case 0x80186904u: goto label_80186904;
    case 0x80186908u: goto label_80186908;
    case 0x8018690Cu: goto label_8018690C;
    case 0x80186910u: goto label_80186910;
    case 0x80186914u: goto label_80186914;
    case 0x80186918u: goto label_80186918;
    case 0x8018691Cu: goto label_8018691C;
    case 0x80186920u: goto label_80186920;
    case 0x80186924u: goto label_80186924;
    case 0x80186928u: goto label_80186928;
    case 0x8018692Cu: goto label_8018692C;
    case 0x80186930u: goto label_80186930;
    case 0x80186934u: goto label_80186934;
    case 0x80186938u: goto label_80186938;
    case 0x8018693Cu: goto label_8018693C;
    case 0x80186940u: goto label_80186940;
    case 0x80186944u: goto label_80186944;
    case 0x80186948u: goto label_80186948;
    case 0x8018694Cu: goto label_8018694C;
    case 0x80186950u: goto label_80186950;
    case 0x80186954u: goto label_80186954;
    case 0x80186958u: goto label_80186958;
    case 0x8018695Cu: goto label_8018695C;
    case 0x80186960u: goto label_80186960;
    case 0x80186964u: goto label_80186964;
    case 0x80186968u: goto label_80186968;
    case 0x8018696Cu: goto label_8018696C;
    case 0x80186970u: goto label_80186970;
    case 0x80186974u: goto label_80186974;
    case 0x80186978u: goto label_80186978;
    case 0x8018697Cu: goto label_8018697C;
    case 0x80186980u: goto label_80186980;
    case 0x80186984u: goto label_80186984;
    case 0x80186988u: goto label_80186988;
    case 0x8018698Cu: goto label_8018698C;
    case 0x80186990u: goto label_80186990;
    case 0x80186994u: goto label_80186994;
    case 0x80186998u: goto label_80186998;
    case 0x8018699Cu: goto label_8018699C;
    case 0x801869A0u: goto label_801869A0;
    case 0x801869A4u: goto label_801869A4;
    case 0x801869A8u: goto label_801869A8;
    case 0x801869ACu: goto label_801869AC;
    case 0x801869B0u: goto label_801869B0;
    case 0x801869B4u: goto label_801869B4;
    case 0x801869B8u: goto label_801869B8;
    case 0x801869BCu: goto label_801869BC;
    case 0x801869C0u: goto label_801869C0;
    case 0x801869C4u: goto label_801869C4;
    case 0x801869C8u: goto label_801869C8;
    case 0x801869CCu: goto label_801869CC;
    case 0x801869D0u: goto label_801869D0;
    case 0x801869D4u: goto label_801869D4;
    case 0x801869D8u: goto label_801869D8;
    case 0x801869DCu: goto label_801869DC;
    case 0x801869E0u: goto label_801869E0;
    case 0x801869E4u: goto label_801869E4;
    case 0x801869E8u: goto label_801869E8;
    case 0x801869ECu: goto label_801869EC;
    case 0x801869F0u: goto label_801869F0;
    case 0x801869F4u: goto label_801869F4;
    case 0x801869F8u: goto label_801869F8;
    case 0x801869FCu: goto label_801869FC;
    case 0x80186A00u: goto label_80186A00;
    case 0x80186A04u: goto label_80186A04;
    case 0x80186A08u: goto label_80186A08;
    case 0x80186A0Cu: goto label_80186A0C;
    case 0x80186A10u: goto label_80186A10;
    case 0x80186A14u: goto label_80186A14;
    case 0x80186A18u: goto label_80186A18;
    case 0x80186A1Cu: goto label_80186A1C;
    case 0x80186A20u: goto label_80186A20;
    case 0x80186A24u: goto label_80186A24;
    case 0x80186A28u: goto label_80186A28;
    case 0x80186A2Cu: goto label_80186A2C;
    case 0x80186A30u: goto label_80186A30;
    case 0x80186A34u: goto label_80186A34;
    case 0x80186A38u: goto label_80186A38;
    case 0x80186A3Cu: goto label_80186A3C;
    case 0x80186A40u: goto label_80186A40;
    case 0x80186A44u: goto label_80186A44;
    case 0x80186A48u: goto label_80186A48;
    case 0x80186A4Cu: goto label_80186A4C;
    case 0x80186A50u: goto label_80186A50;
    case 0x80186A54u: goto label_80186A54;
    case 0x80186A58u: goto label_80186A58;
    case 0x80186A5Cu: goto label_80186A5C;
    case 0x80186A60u: goto label_80186A60;
    case 0x80186A64u: goto label_80186A64;
    case 0x80186A68u: goto label_80186A68;
    case 0x80186A6Cu: goto label_80186A6C;
    case 0x80186A70u: goto label_80186A70;
    case 0x80186A74u: goto label_80186A74;
    case 0x80186A78u: goto label_80186A78;
    case 0x80186A7Cu: goto label_80186A7C;
    case 0x80186A80u: goto label_80186A80;
    case 0x80186A84u: goto label_80186A84;
    case 0x80186A88u: goto label_80186A88;
    case 0x80186A8Cu: goto label_80186A8C;
    case 0x80186A90u: goto label_80186A90;
    case 0x80186A94u: goto label_80186A94;
    case 0x80186A98u: goto label_80186A98;
    case 0x80186A9Cu: goto label_80186A9C;
    case 0x80186AA0u: goto label_80186AA0;
    case 0x80186AA4u: goto label_80186AA4;
    case 0x80186AA8u: goto label_80186AA8;
    case 0x80186AACu: goto label_80186AAC;
    case 0x80186AB0u: goto label_80186AB0;
    case 0x80186AB4u: goto label_80186AB4;
    case 0x80186AB8u: goto label_80186AB8;
    case 0x80186ABCu: goto label_80186ABC;
    case 0x80186AC0u: goto label_80186AC0;
    case 0x80186AC4u: goto label_80186AC4;
    case 0x80186AC8u: goto label_80186AC8;
    case 0x80186ACCu: goto label_80186ACC;
    case 0x80186AD0u: goto label_80186AD0;
    case 0x80186AD4u: goto label_80186AD4;
    case 0x80186AD8u: goto label_80186AD8;
    case 0x80186ADCu: goto label_80186ADC;
    case 0x80186AE0u: goto label_80186AE0;
    case 0x80186AE4u: goto label_80186AE4;
    case 0x80186AE8u: goto label_80186AE8;
    case 0x80186AECu: goto label_80186AEC;
    case 0x80186AF0u: goto label_80186AF0;
    case 0x80186AF4u: goto label_80186AF4;
    case 0x80186AF8u: goto label_80186AF8;
    case 0x80186AFCu: goto label_80186AFC;
    case 0x80186B00u: goto label_80186B00;
    case 0x80186B04u: goto label_80186B04;
    case 0x80186B08u: goto label_80186B08;
    case 0x80186B0Cu: goto label_80186B0C;
    case 0x80186B10u: goto label_80186B10;
    case 0x80186B14u: goto label_80186B14;
    case 0x80186B18u: goto label_80186B18;
    case 0x80186B1Cu: goto label_80186B1C;
    case 0x80186B20u: goto label_80186B20;
    case 0x80186B24u: goto label_80186B24;
    case 0x80186B28u: goto label_80186B28;
    case 0x80186B2Cu: goto label_80186B2C;
    case 0x80186B30u: goto label_80186B30;
    case 0x80186B34u: goto label_80186B34;
    case 0x80186B38u: goto label_80186B38;
    case 0x80186B3Cu: goto label_80186B3C;
    case 0x80186B40u: goto label_80186B40;
    case 0x80186B44u: goto label_80186B44;
    case 0x80186B48u: goto label_80186B48;
    case 0x80186B4Cu: goto label_80186B4C;
    case 0x80186B50u: goto label_80186B50;
    case 0x80186B54u: goto label_80186B54;
    case 0x80186B58u: goto label_80186B58;
    case 0x80186B5Cu: goto label_80186B5C;
    case 0x80186B60u: goto label_80186B60;
    case 0x80186B64u: goto label_80186B64;
    case 0x80186B68u: goto label_80186B68;
    case 0x80186B6Cu: goto label_80186B6C;
    case 0x80186B70u: goto label_80186B70;
    case 0x80186B74u: goto label_80186B74;
    case 0x80186B78u: goto label_80186B78;
    case 0x80186B7Cu: goto label_80186B7C;
    case 0x80186B80u: goto label_80186B80;
    case 0x80186B84u: goto label_80186B84;
    case 0x80186B88u: goto label_80186B88;
    case 0x80186B8Cu: goto label_80186B8C;
    case 0x80186B90u: goto label_80186B90;
    case 0x80186B94u: goto label_80186B94;
    case 0x80186B98u: goto label_80186B98;
    case 0x80186B9Cu: goto label_80186B9C;
    case 0x80186BA0u: goto label_80186BA0;
    case 0x80186BA4u: goto label_80186BA4;
    case 0x80186BA8u: goto label_80186BA8;
    case 0x80186BACu: goto label_80186BAC;
    case 0x80186BB0u: goto label_80186BB0;
    case 0x80186BB4u: goto label_80186BB4;
    case 0x80186BB8u: goto label_80186BB8;
    case 0x80186BBCu: goto label_80186BBC;
    case 0x80186BC0u: goto label_80186BC0;
    case 0x80186BC4u: goto label_80186BC4;
    case 0x80186BC8u: goto label_80186BC8;
    case 0x80186BCCu: goto label_80186BCC;
    case 0x80186BD0u: goto label_80186BD0;
    case 0x80186BD4u: goto label_80186BD4;
    case 0x80186BD8u: goto label_80186BD8;
    case 0x80186BDCu: goto label_80186BDC;
    case 0x80186BE0u: goto label_80186BE0;
    case 0x80186BE4u: goto label_80186BE4;
    case 0x80186BE8u: goto label_80186BE8;
    case 0x80186BECu: goto label_80186BEC;
    case 0x80186BF0u: goto label_80186BF0;
    case 0x80186BF4u: goto label_80186BF4;
    case 0x80186BF8u: goto label_80186BF8;
    case 0x80186BFCu: goto label_80186BFC;
    case 0x80186C00u: goto label_80186C00;
    case 0x80186C04u: goto label_80186C04;
    case 0x80186C08u: goto label_80186C08;
    case 0x80186C0Cu: goto label_80186C0C;
    case 0x80186C10u: goto label_80186C10;
    case 0x80186C14u: goto label_80186C14;
    case 0x80186C18u: goto label_80186C18;
    case 0x80186C1Cu: goto label_80186C1C;
    case 0x80186C20u: goto label_80186C20;
    case 0x80186C24u: goto label_80186C24;
    case 0x80186C28u: goto label_80186C28;
    case 0x80186C2Cu: goto label_80186C2C;
    case 0x80186C30u: goto label_80186C30;
    case 0x80186C34u: goto label_80186C34;
    case 0x80186C38u: goto label_80186C38;
    case 0x80186C3Cu: goto label_80186C3C;
    case 0x80186C40u: goto label_80186C40;
    case 0x80186C44u: goto label_80186C44;
    case 0x80186C48u: goto label_80186C48;
    case 0x80186C4Cu: goto label_80186C4C;
    case 0x80186C50u: goto label_80186C50;
    case 0x80186C54u: goto label_80186C54;
    case 0x80186C58u: goto label_80186C58;
    case 0x80186C5Cu: goto label_80186C5C;
    case 0x80186C60u: goto label_80186C60;
    case 0x80186C64u: goto label_80186C64;
    case 0x80186C68u: goto label_80186C68;
    case 0x80186C6Cu: goto label_80186C6C;
    case 0x80186C70u: goto label_80186C70;
    case 0x80186C74u: goto label_80186C74;
    case 0x80186C78u: goto label_80186C78;
    case 0x80186C7Cu: goto label_80186C7C;
    case 0x80186C80u: goto label_80186C80;
    case 0x80186C84u: goto label_80186C84;
    case 0x80186C88u: goto label_80186C88;
    case 0x80186C8Cu: goto label_80186C8C;
    case 0x80186C90u: goto label_80186C90;
    case 0x80186C94u: goto label_80186C94;
    case 0x80186C98u: goto label_80186C98;
    case 0x80186C9Cu: goto label_80186C9C;
    case 0x80186CA0u: goto label_80186CA0;
    case 0x80186CA4u: goto label_80186CA4;
    case 0x80186CA8u: goto label_80186CA8;
    case 0x80186CACu: goto label_80186CAC;
    case 0x80186CB0u: goto label_80186CB0;
    case 0x80186CB4u: goto label_80186CB4;
    case 0x80186CB8u: goto label_80186CB8;
    case 0x80186CBCu: goto label_80186CBC;
    case 0x80186CC0u: goto label_80186CC0;
    case 0x80186CC4u: goto label_80186CC4;
    case 0x80186CC8u: goto label_80186CC8;
    case 0x80186CCCu: goto label_80186CCC;
    case 0x80186CD0u: goto label_80186CD0;
    case 0x80186CD4u: goto label_80186CD4;
    case 0x80186CD8u: goto label_80186CD8;
    case 0x80186CDCu: goto label_80186CDC;
    case 0x80186CE0u: goto label_80186CE0;
    case 0x80186CE4u: goto label_80186CE4;
    case 0x80186CE8u: goto label_80186CE8;
    case 0x80186CECu: goto label_80186CEC;
    case 0x80186CF0u: goto label_80186CF0;
    case 0x80186CF4u: goto label_80186CF4;
    case 0x80186CF8u: goto label_80186CF8;
    case 0x80186CFCu: goto label_80186CFC;
    case 0x80186D00u: goto label_80186D00;
    case 0x80186D04u: goto label_80186D04;
    case 0x80186D08u: goto label_80186D08;
    case 0x80186D0Cu: goto label_80186D0C;
    case 0x80186D10u: goto label_80186D10;
    case 0x80186D14u: goto label_80186D14;
    case 0x80186D18u: goto label_80186D18;
    case 0x80186D1Cu: goto label_80186D1C;
    case 0x80186D20u: goto label_80186D20;
    case 0x80186D24u: goto label_80186D24;
    case 0x80186D28u: goto label_80186D28;
    case 0x80186D2Cu: goto label_80186D2C;
    case 0x80186D30u: goto label_80186D30;
    case 0x80186D34u: goto label_80186D34;
    case 0x80186D38u: goto label_80186D38;
    case 0x80186D3Cu: goto label_80186D3C;
    case 0x80186D40u: goto label_80186D40;
    case 0x80186D44u: goto label_80186D44;
    case 0x80186D48u: goto label_80186D48;
    case 0x80186D4Cu: goto label_80186D4C;
    case 0x80186D50u: goto label_80186D50;
    case 0x80186D54u: goto label_80186D54;
    case 0x80186D58u: goto label_80186D58;
    case 0x80186D5Cu: goto label_80186D5C;
    case 0x80186D60u: goto label_80186D60;
    case 0x80186D64u: goto label_80186D64;
    case 0x80186D68u: goto label_80186D68;
    case 0x80186D6Cu: goto label_80186D6C;
    case 0x80186D70u: goto label_80186D70;
    case 0x80186D74u: goto label_80186D74;
    case 0x80186D78u: goto label_80186D78;
    case 0x80186D7Cu: goto label_80186D7C;
    case 0x80186D80u: goto label_80186D80;
    case 0x80186D84u: goto label_80186D84;
    case 0x80186D88u: goto label_80186D88;
    case 0x80186D8Cu: goto label_80186D8C;
    case 0x80186D90u: goto label_80186D90;
    case 0x80186D94u: goto label_80186D94;
    case 0x80186D98u: goto label_80186D98;
    case 0x80186D9Cu: goto label_80186D9C;
    case 0x80186DA0u: goto label_80186DA0;
    case 0x80186DA4u: goto label_80186DA4;
    case 0x80186DA8u: goto label_80186DA8;
    case 0x80186DACu: goto label_80186DAC;
    case 0x80186DB0u: goto label_80186DB0;
    case 0x80186DB4u: goto label_80186DB4;
    case 0x80186DB8u: goto label_80186DB8;
    case 0x80186DBCu: goto label_80186DBC;
    case 0x80186DC0u: goto label_80186DC0;
    case 0x80186DC4u: goto label_80186DC4;
    case 0x80186DC8u: goto label_80186DC8;
    case 0x80186DCCu: goto label_80186DCC;
    case 0x80186DD0u: goto label_80186DD0;
    case 0x80186DD4u: goto label_80186DD4;
    case 0x80186DD8u: goto label_80186DD8;
    case 0x80186DDCu: goto label_80186DDC;
    case 0x80186DE0u: goto label_80186DE0;
    case 0x80186DE4u: goto label_80186DE4;
    case 0x80186DE8u: goto label_80186DE8;
    case 0x80186DECu: goto label_80186DEC;
    case 0x80186DF0u: goto label_80186DF0;
    case 0x80186DF4u: goto label_80186DF4;
    case 0x80186DF8u: goto label_80186DF8;
    case 0x80186DFCu: goto label_80186DFC;
    case 0x80186E00u: goto label_80186E00;
    case 0x80186E04u: goto label_80186E04;
    case 0x80186E08u: goto label_80186E08;
    case 0x80186E0Cu: goto label_80186E0C;
    case 0x80186E10u: goto label_80186E10;
    case 0x80186E14u: goto label_80186E14;
    case 0x80186E18u: goto label_80186E18;
    case 0x80186E1Cu: goto label_80186E1C;
    case 0x80186E20u: goto label_80186E20;
    case 0x80186E24u: goto label_80186E24;
    case 0x80186E28u: goto label_80186E28;
    case 0x80186E2Cu: goto label_80186E2C;
    case 0x80186E30u: goto label_80186E30;
    case 0x80186E34u: goto label_80186E34;
    case 0x80186E38u: goto label_80186E38;
    case 0x80186E3Cu: goto label_80186E3C;
    case 0x80186E40u: goto label_80186E40;
    case 0x80186E44u: goto label_80186E44;
    case 0x80186E48u: goto label_80186E48;
    case 0x80186E4Cu: goto label_80186E4C;
    case 0x80186E50u: goto label_80186E50;
    case 0x80186E54u: goto label_80186E54;
    case 0x80186E58u: goto label_80186E58;
    case 0x80186E5Cu: goto label_80186E5C;
    case 0x80186E60u: goto label_80186E60;
    case 0x80186E64u: goto label_80186E64;
    case 0x80186E68u: goto label_80186E68;
    case 0x80186E6Cu: goto label_80186E6C;
    case 0x80186E70u: goto label_80186E70;
    case 0x80186E74u: goto label_80186E74;
    case 0x80186E78u: goto label_80186E78;
    case 0x80186E7Cu: goto label_80186E7C;
    case 0x80186E80u: goto label_80186E80;
    case 0x80186E84u: goto label_80186E84;
    case 0x80186E88u: goto label_80186E88;
    case 0x80186E8Cu: goto label_80186E8C;
    case 0x80186E90u: goto label_80186E90;
    case 0x80186E94u: goto label_80186E94;
    case 0x80186E98u: goto label_80186E98;
    case 0x80186E9Cu: goto label_80186E9C;
    case 0x80186EA0u: goto label_80186EA0;
    case 0x80186EA4u: goto label_80186EA4;
    case 0x80186EA8u: goto label_80186EA8;
    case 0x80186EACu: goto label_80186EAC;
    case 0x80186EB0u: goto label_80186EB0;
    case 0x80186EB4u: goto label_80186EB4;
    case 0x80186EB8u: goto label_80186EB8;
    case 0x80186EBCu: goto label_80186EBC;
    case 0x80186EC0u: goto label_80186EC0;
    case 0x80186EC4u: goto label_80186EC4;
    case 0x80186EC8u: goto label_80186EC8;
    case 0x80186ECCu: goto label_80186ECC;
    case 0x80186ED0u: goto label_80186ED0;
    case 0x80186ED4u: goto label_80186ED4;
    case 0x80186ED8u: goto label_80186ED8;
    case 0x80186EDCu: goto label_80186EDC;
    case 0x80186EE0u: goto label_80186EE0;
    case 0x80186EE4u: goto label_80186EE4;
    case 0x80186EE8u: goto label_80186EE8;
    case 0x80186EECu: goto label_80186EEC;
    case 0x80186EF0u: goto label_80186EF0;
    case 0x80186EF4u: goto label_80186EF4;
    case 0x80186EF8u: goto label_80186EF8;
    case 0x80186EFCu: goto label_80186EFC;
    case 0x80186F00u: goto label_80186F00;
    case 0x80186F04u: goto label_80186F04;
    case 0x80186F08u: goto label_80186F08;
    case 0x80186F0Cu: goto label_80186F0C;
    case 0x80186F10u: goto label_80186F10;
    case 0x80186F14u: goto label_80186F14;
    case 0x80186F18u: goto label_80186F18;
    case 0x80186F1Cu: goto label_80186F1C;
    case 0x80186F20u: goto label_80186F20;
    case 0x80186F24u: goto label_80186F24;
    case 0x80186F28u: goto label_80186F28;
    case 0x80186F2Cu: goto label_80186F2C;
    case 0x80186F30u: goto label_80186F30;
    case 0x80186F34u: goto label_80186F34;
    case 0x80186F38u: goto label_80186F38;
    case 0x80186F3Cu: goto label_80186F3C;
    case 0x80186F40u: goto label_80186F40;
    case 0x80186F44u: goto label_80186F44;
    case 0x80186F48u: goto label_80186F48;
    case 0x80186F4Cu: goto label_80186F4C;
    case 0x80186F50u: goto label_80186F50;
    case 0x80186F54u: goto label_80186F54;
    case 0x80186F58u: goto label_80186F58;
    case 0x80186F5Cu: goto label_80186F5C;
    case 0x80186F60u: goto label_80186F60;
    case 0x80186F64u: goto label_80186F64;
    case 0x80186F68u: goto label_80186F68;
    case 0x80186F6Cu: goto label_80186F6C;
    case 0x80186F70u: goto label_80186F70;
    case 0x80186F74u: goto label_80186F74;
    case 0x80186F78u: goto label_80186F78;
    case 0x80186F7Cu: goto label_80186F7C;
    case 0x80186F80u: goto label_80186F80;
    case 0x80186F84u: goto label_80186F84;
    case 0x80186F88u: goto label_80186F88;
    case 0x80186F8Cu: goto label_80186F8C;
    case 0x80186F90u: goto label_80186F90;
    case 0x80186F94u: goto label_80186F94;
    case 0x80186F98u: goto label_80186F98;
    case 0x80186F9Cu: goto label_80186F9C;
    case 0x80186FA0u: goto label_80186FA0;
    case 0x80186FA4u: goto label_80186FA4;
    case 0x80186FA8u: goto label_80186FA8;
    case 0x80186FACu: goto label_80186FAC;
    case 0x80186FB0u: goto label_80186FB0;
    case 0x80186FB4u: goto label_80186FB4;
    case 0x80186FB8u: goto label_80186FB8;
    case 0x80186FBCu: goto label_80186FBC;
    case 0x80186FC0u: goto label_80186FC0;
    case 0x80186FC4u: goto label_80186FC4;
    case 0x80186FC8u: goto label_80186FC8;
    case 0x80186FCCu: goto label_80186FCC;
    case 0x80186FD0u: goto label_80186FD0;
    case 0x80186FD4u: goto label_80186FD4;
    case 0x80186FD8u: goto label_80186FD8;
    case 0x80186FDCu: goto label_80186FDC;
    case 0x80186FE0u: goto label_80186FE0;
    case 0x80186FE4u: goto label_80186FE4;
    case 0x80186FE8u: goto label_80186FE8;
    case 0x80186FECu: goto label_80186FEC;
    case 0x80186FF0u: goto label_80186FF0;
    case 0x80186FF4u: goto label_80186FF4;
    case 0x80186FF8u: goto label_80186FF8;
    case 0x80186FFCu: goto label_80186FFC;
    case 0x80187000u: goto label_80187000;
    case 0x80187004u: goto label_80187004;
    case 0x80187008u: goto label_80187008;
    case 0x8018700Cu: goto label_8018700C;
    case 0x80187010u: goto label_80187010;
    case 0x80187014u: goto label_80187014;
    case 0x80187018u: goto label_80187018;
    case 0x8018701Cu: goto label_8018701C;
    case 0x80187020u: goto label_80187020;
    case 0x80187024u: goto label_80187024;
    case 0x80187028u: goto label_80187028;
    case 0x8018702Cu: goto label_8018702C;
    case 0x80187030u: goto label_80187030;
    case 0x80187034u: goto label_80187034;
    case 0x80187038u: goto label_80187038;
    case 0x8018703Cu: goto label_8018703C;
    case 0x80187040u: goto label_80187040;
    case 0x80187044u: goto label_80187044;
    case 0x80187048u: goto label_80187048;
    case 0x8018704Cu: goto label_8018704C;
    case 0x80187050u: goto label_80187050;
    case 0x80187054u: goto label_80187054;
    case 0x80187058u: goto label_80187058;
    case 0x8018705Cu: goto label_8018705C;
    case 0x80187060u: goto label_80187060;
    case 0x80187064u: goto label_80187064;
    case 0x80187068u: goto label_80187068;
    case 0x8018706Cu: goto label_8018706C;
    case 0x80187070u: goto label_80187070;
    case 0x80187074u: goto label_80187074;
    case 0x80187078u: goto label_80187078;
    case 0x8018707Cu: goto label_8018707C;
    case 0x80187080u: goto label_80187080;
    case 0x80187084u: goto label_80187084;
    case 0x80187088u: goto label_80187088;
    case 0x8018708Cu: goto label_8018708C;
    case 0x80187090u: goto label_80187090;
    case 0x80187094u: goto label_80187094;
    case 0x80187098u: goto label_80187098;
    case 0x8018709Cu: goto label_8018709C;
    case 0x801870A0u: goto label_801870A0;
    case 0x801870A4u: goto label_801870A4;
    case 0x801870A8u: goto label_801870A8;
    case 0x801870ACu: goto label_801870AC;
    case 0x801870B0u: goto label_801870B0;
    case 0x801870B4u: goto label_801870B4;
    case 0x801870B8u: goto label_801870B8;
    case 0x801870BCu: goto label_801870BC;
    case 0x801870C0u: goto label_801870C0;
    case 0x801870C4u: goto label_801870C4;
    case 0x801870C8u: goto label_801870C8;
    case 0x801870CCu: goto label_801870CC;
    case 0x801870D0u: goto label_801870D0;
    case 0x801870D4u: goto label_801870D4;
    case 0x801870D8u: goto label_801870D8;
    case 0x801870DCu: goto label_801870DC;
    case 0x801870E0u: goto label_801870E0;
    case 0x801870E4u: goto label_801870E4;
    case 0x801870E8u: goto label_801870E8;
    case 0x801870ECu: goto label_801870EC;
    case 0x801870F0u: goto label_801870F0;
    case 0x801870F4u: goto label_801870F4;
    case 0x801870F8u: goto label_801870F8;
    case 0x801870FCu: goto label_801870FC;
    case 0x80187100u: goto label_80187100;
    case 0x80187104u: goto label_80187104;
    case 0x80187108u: goto label_80187108;
    case 0x8018710Cu: goto label_8018710C;
    case 0x80187110u: goto label_80187110;
    case 0x80187114u: goto label_80187114;
    case 0x80187118u: goto label_80187118;
    case 0x8018711Cu: goto label_8018711C;
    case 0x80187120u: goto label_80187120;
    case 0x80187124u: goto label_80187124;
    case 0x80187128u: goto label_80187128;
    case 0x8018712Cu: goto label_8018712C;
    case 0x80187130u: goto label_80187130;
    case 0x80187134u: goto label_80187134;
    case 0x80187138u: goto label_80187138;
    case 0x8018713Cu: goto label_8018713C;
    case 0x80187140u: goto label_80187140;
    case 0x80187144u: goto label_80187144;
    case 0x80187148u: goto label_80187148;
    case 0x8018714Cu: goto label_8018714C;
    case 0x80187150u: goto label_80187150;
    case 0x80187154u: goto label_80187154;
    case 0x80187158u: goto label_80187158;
    case 0x8018715Cu: goto label_8018715C;
    case 0x80187160u: goto label_80187160;
    case 0x80187164u: goto label_80187164;
    case 0x80187168u: goto label_80187168;
    case 0x8018716Cu: goto label_8018716C;
    case 0x80187170u: goto label_80187170;
    case 0x80187174u: goto label_80187174;
    case 0x80187178u: goto label_80187178;
    case 0x8018717Cu: goto label_8018717C;
    case 0x80187180u: goto label_80187180;
    case 0x80187184u: goto label_80187184;
    case 0x80187188u: goto label_80187188;
    case 0x8018718Cu: goto label_8018718C;
    case 0x80187190u: goto label_80187190;
    case 0x80187194u: goto label_80187194;
    case 0x80187198u: goto label_80187198;
    case 0x8018719Cu: goto label_8018719C;
    case 0x801871A0u: goto label_801871A0;
    case 0x801871A4u: goto label_801871A4;
    case 0x801871A8u: goto label_801871A8;
    case 0x801871ACu: goto label_801871AC;
    case 0x801871B0u: goto label_801871B0;
    case 0x801871B4u: goto label_801871B4;
    case 0x801871B8u: goto label_801871B8;
    case 0x801871BCu: goto label_801871BC;
    case 0x801871C0u: goto label_801871C0;
    case 0x801871C4u: goto label_801871C4;
    case 0x801871C8u: goto label_801871C8;
    case 0x801871CCu: goto label_801871CC;
    case 0x801871D0u: goto label_801871D0;
    case 0x801871D4u: goto label_801871D4;
    case 0x801871D8u: goto label_801871D8;
    case 0x801871DCu: goto label_801871DC;
    case 0x801871E0u: goto label_801871E0;
    case 0x801871E4u: goto label_801871E4;
    case 0x801871E8u: goto label_801871E8;
    case 0x801871ECu: goto label_801871EC;
    case 0x801871F0u: goto label_801871F0;
    case 0x801871F4u: goto label_801871F4;
    case 0x801871F8u: goto label_801871F8;
    case 0x801871FCu: goto label_801871FC;
    case 0x80187200u: goto label_80187200;
    case 0x80187204u: goto label_80187204;
    case 0x80187208u: goto label_80187208;
    case 0x8018720Cu: goto label_8018720C;
    case 0x80187210u: goto label_80187210;
    case 0x80187214u: goto label_80187214;
    case 0x80187218u: goto label_80187218;
    case 0x8018721Cu: goto label_8018721C;
    case 0x80187220u: goto label_80187220;
    case 0x80187224u: goto label_80187224;
    case 0x80187228u: goto label_80187228;
    case 0x8018722Cu: goto label_8018722C;
    case 0x80187230u: goto label_80187230;
    case 0x80187234u: goto label_80187234;
    case 0x80187238u: goto label_80187238;
    case 0x8018723Cu: goto label_8018723C;
    case 0x80187240u: goto label_80187240;
    case 0x80187244u: goto label_80187244;
    case 0x80187248u: goto label_80187248;
    case 0x8018724Cu: goto label_8018724C;
    case 0x80187250u: goto label_80187250;
    case 0x80187254u: goto label_80187254;
    case 0x80187258u: goto label_80187258;
    case 0x8018725Cu: goto label_8018725C;
    case 0x80187260u: goto label_80187260;
    case 0x80187264u: goto label_80187264;
    case 0x80187268u: goto label_80187268;
    case 0x8018726Cu: goto label_8018726C;
    case 0x80187270u: goto label_80187270;
    case 0x80187274u: goto label_80187274;
    case 0x80187278u: goto label_80187278;
    case 0x8018727Cu: goto label_8018727C;
    case 0x80187280u: goto label_80187280;
    case 0x80187284u: goto label_80187284;
    case 0x80187288u: goto label_80187288;
    case 0x8018728Cu: goto label_8018728C;
    case 0x80187290u: goto label_80187290;
    case 0x80187294u: goto label_80187294;
    case 0x80187298u: goto label_80187298;
    case 0x8018729Cu: goto label_8018729C;
    case 0x801872A0u: goto label_801872A0;
    case 0x801872A4u: goto label_801872A4;
    case 0x801872A8u: goto label_801872A8;
    case 0x801872ACu: goto label_801872AC;
    case 0x801872B0u: goto label_801872B0;
    case 0x801872B4u: goto label_801872B4;
    case 0x801872B8u: goto label_801872B8;
    case 0x801872BCu: goto label_801872BC;
    default: return;
    }
label_801832C0:
    ctx->pc = 0x801832C0u;
    ctx->downcount -= 4;
    // 801832C0: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801832C4:
    ctx->pc = 0x801832C4u;
    // 801832C4: lwz     r0, -26660(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26660);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801832C8:
    ctx->pc = 0x801832C8u;
    // 801832C8: cmpwi   r0, 0
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

label_801832CC:
    ctx->pc = 0x801832CCu;
    // 801832CC: bc    12, 2, 0x801832D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801832D8;
        }
    }

label_801832D0:
    ctx->pc = 0x801832D0u;
    ctx->downcount -= 2;
    // 801832D0: stw     r4, -26660(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26660);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801832D4:
    ctx->pc = 0x801832D4u;
    // 801832D4: bl      0x80180E50
    {
            ctx->lr = 0x801832D8u;
            ctx->pc = 0x80180E50u;
            return;
    }

label_801832D8:
    ctx->pc = 0x801832D8u;
    ctx->downcount -= 2;
    // 801832D8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801832DC:
    ctx->pc = 0x801832DCu;
    // 801832DC: bl      0x80173F54
    {
            ctx->lr = 0x801832E0u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801832E0:
    ctx->pc = 0x801832E0u;
    ctx->downcount -= 2;
    // 801832E0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801832E4:
    ctx->pc = 0x801832E4u;
    // 801832E4: bl      0x80173F54
    {
            ctx->lr = 0x801832E8u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801832E8:
    ctx->pc = 0x801832E8u;
    ctx->downcount -= 2;
    // 801832E8: cmpwi   r30, 0
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

label_801832EC:
    ctx->pc = 0x801832ECu;
    // 801832EC: bc    4, 2, 0x80183300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183300;
        }
    }

label_801832F0:
    ctx->pc = 0x801832F0u;
    ctx->downcount -= 2;
    // 801832F0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801832F4:
    ctx->pc = 0x801832F4u;
    // 801832F4: bl      0x80173F54
    {
            ctx->lr = 0x801832F8u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801832F8:
    ctx->pc = 0x801832F8u;
    ctx->downcount -= 2;
    // 801832F8: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801832FC:
    ctx->pc = 0x801832FCu;
    // 801832FC: b       0x80183324
    {
            goto label_80183324;
    }

label_80183300:
    ctx->pc = 0x80183300u;
    ctx->downcount -= 3;
    // 80183300: lwz     r0, -26616(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26616);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183304:
    // 80183304: cmpwi   r0, 0
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

label_80183308:
    // 80183308: bc    4, 2, 0x80183318
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183318;
        }
    }

label_8018330C:
    ctx->downcount -= 2;
    // 8018330C: addi    r3, r13, -26688
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26688);

label_80183310:
    // 80183310: bl      0x80179478
    {
            ctx->lr = 0x80183314u;
            ctx->pc = 0x80179478u;
            return;
    }

label_80183314:
    ctx->downcount -= 1;
    // 80183314: b       0x80183300
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80183300u;
                return;
            }
            goto label_80183300;
    }

label_80183318:
    ctx->pc = 0x80183318u;
    ctx->downcount -= 2;
    // 80183318: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8018331C:
    ctx->pc = 0x8018331Cu;
    // 8018331C: bl      0x80173F54
    {
            ctx->lr = 0x80183320u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80183320:
    ctx->pc = 0x80183320u;
    ctx->downcount -= 1;
    // 80183320: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80183324:
    ctx->pc = 0x80183324u;
    ctx->downcount -= 9;
    // 80183324: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183328:
    ctx->pc = 0x80183328u;
    // 80183328: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018332C:
    ctx->pc = 0x8018332Cu;
    // 8018332C: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80183330:
    ctx->pc = 0x80183330u;
    // 80183330: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80183334:
    ctx->pc = 0x80183334u;
    // 80183334: lwz     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80183338:
    ctx->pc = 0x80183338u;
    // 80183338: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8018333C:
    ctx->pc = 0x8018333Cu;
    // 8018333C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183340:
    ctx->pc = 0x80183340u;
    // 80183340: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183344:
    ctx->pc = 0x80183344u;
    ctx->downcount -= 7;
    // 80183344: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183348:
    ctx->pc = 0x80183348u;
    // 80183348: addi    r3, r13, -26688
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26688);

label_8018334C:
    ctx->pc = 0x8018334Cu;
    // 8018334C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183350:
    ctx->pc = 0x80183350u;
    // 80183350: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80183354:
    ctx->pc = 0x80183354u;
    // 80183354: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183358:
    ctx->pc = 0x80183358u;
    // 80183358: stw     r0, -26616(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26616);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018335C:
    ctx->pc = 0x8018335Cu;
    // 8018335C: bl      0x80179564
    {
            ctx->lr = 0x80183360u;
            ctx->pc = 0x80179564u;
            return;
    }

label_80183360:
    ctx->pc = 0x80183360u;
    ctx->downcount -= 5;
    // 80183360: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183364:
    ctx->pc = 0x80183364u;
    // 80183364: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80183368:
    ctx->pc = 0x80183368u;
    // 80183368: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018336C:
    ctx->pc = 0x8018336Cu;
    // 8018336C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183370:
    ctx->pc = 0x80183370u;
    ctx->downcount -= 2;
    // 80183370: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80183374:
    ctx->pc = 0x80183374u;
    // 80183374: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183378:
    ctx->pc = 0x80183378u;
    ctx->downcount -= 5;
    // 80183378: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018337C:
    ctx->pc = 0x8018337Cu;
    // 8018337C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183380:
    ctx->pc = 0x80183380u;
    // 80183380: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183384:
    ctx->pc = 0x80183384u;
    // 80183384: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80183388:
    ctx->pc = 0x80183388u;
    // 80183388: bl      0x80173F2C
    {
            ctx->lr = 0x8018338Cu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018338C:
    ctx->pc = 0x8018338Cu;
    ctx->downcount -= 3;
    // 8018338C: lwz     r0, -26652(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26652);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183390:
    ctx->pc = 0x80183390u;
    // 80183390: cmpwi   r0, 0
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

label_80183394:
    ctx->pc = 0x80183394u;
    // 80183394: bc    12, 2, 0x801833A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801833A0;
        }
    }

label_80183398:
    ctx->pc = 0x80183398u;
    ctx->downcount -= 2;
    // 80183398: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8018339C:
    ctx->pc = 0x8018339Cu;
    // 8018339C: b       0x801833E4
    {
            goto label_801833E4;
    }

label_801833A0:
    ctx->pc = 0x801833A0u;
    ctx->downcount -= 3;
    // 801833A0: lwz     r0, -26660(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26660);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801833A4:
    ctx->pc = 0x801833A4u;
    // 801833A4: cmpwi   r0, 0
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

label_801833A8:
    ctx->pc = 0x801833A8u;
    // 801833A8: bc    12, 2, 0x801833B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801833B4;
        }
    }

label_801833AC:
    ctx->pc = 0x801833ACu;
    ctx->downcount -= 2;
    // 801833AC: li      r4, 8
    ctx->gpr[4] = (u32)(s32)(8);

label_801833B0:
    ctx->pc = 0x801833B0u;
    // 801833B0: b       0x801833E4
    {
            goto label_801833E4;
    }

label_801833B4:
    ctx->pc = 0x801833B4u;
    ctx->downcount -= 3;
    // 801833B4: lwz     r5, -26680(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26680);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801833B8:
    ctx->pc = 0x801833B8u;
    // 801833B8: cmplwi  r5, 0x0000
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

label_801833BC:
    ctx->pc = 0x801833BCu;
    // 801833BC: bc    4, 2, 0x801833C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801833C8;
        }
    }

label_801833C0:
    ctx->pc = 0x801833C0u;
    ctx->downcount -= 2;
    // 801833C0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801833C4:
    ctx->pc = 0x801833C4u;
    // 801833C4: b       0x801833E4
    {
            goto label_801833E4;
    }

label_801833C8:
    ctx->pc = 0x801833C8u;
    ctx->downcount -= 4;
    // 801833C8: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_801833CC:
    ctx->pc = 0x801833CCu;
    // 801833CC: addi    r0, r4, 1920
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1920);

label_801833D0:
    ctx->pc = 0x801833D0u;
    // 801833D0: cmplw   r5, r0
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801833D4:
    ctx->pc = 0x801833D4u;
    // 801833D4: bc    4, 2, 0x801833E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801833E0;
        }
    }

label_801833D8:
    ctx->pc = 0x801833D8u;
    ctx->downcount -= 2;
    // 801833D8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801833DC:
    ctx->pc = 0x801833DCu;
    // 801833DC: b       0x801833E4
    {
            goto label_801833E4;
    }

label_801833E0:
    ctx->pc = 0x801833E0u;
    ctx->downcount -= 1;
    // 801833E0: lwz     r4, 12(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(12);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801833E4:
    ctx->pc = 0x801833E4u;
    ctx->downcount -= 3;
    // 801833E4: addi    r0, r4, 1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1);

label_801833E8:
    ctx->pc = 0x801833E8u;
    // 801833E8: cmplwi  r0, 0x000C
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x000Cu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801833EC:
    ctx->pc = 0x801833ECu;
    // 801833EC: bc    12, 1, 0x80183440
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183440;
        }
    }

label_801833F0:
    ctx->pc = 0x801833F0u;
    ctx->downcount -= 7;
    // 801833F0: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_801833F4:
    ctx->pc = 0x801833F4u;
    // 801833F4: addi    r4, r4, -9496
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-9496);

label_801833F8:
    ctx->pc = 0x801833F8u;
    // 801833F8: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_801833FC:
    ctx->pc = 0x801833FCu;
    // 801833FC: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183400:
    ctx->pc = 0x80183400u;
    // 80183400: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80183404:
    ctx->pc = 0x80183404u;
    // 80183404: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80183408:
    ctx->pc = 0x80183408u;
    ctx->downcount -= 2;
    // 80183408: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_8018340C:
    ctx->pc = 0x8018340Cu;
    // 8018340C: b       0x80183440
    {
            goto label_80183440;
    }

label_80183410:
    ctx->pc = 0x80183410u;
    ctx->downcount -= 2;
    // 80183410: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80183414:
    ctx->pc = 0x80183414u;
    // 80183414: b       0x80183440
    {
            goto label_80183440;
    }

label_80183418:
    ctx->pc = 0x80183418u;
    ctx->downcount -= 5;
    // 80183418: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_8018341C:
    ctx->pc = 0x8018341Cu;
    // 8018341C: addi    r4, r4, 24576
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(24576);

label_80183420:
    ctx->pc = 0x80183420u;
    // 80183420: lwz     r4, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183424:
    ctx->pc = 0x80183424u;
    // 80183424: rlwinm. r0, r4, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 30u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80183428:
    ctx->pc = 0x80183428u;
    // 80183428: bc    4, 2, 0x80183434
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183434;
        }
    }

label_8018342C:
    ctx->pc = 0x8018342Cu;
    ctx->downcount -= 2;
    // 8018342C: rlwinm. r0, r4, 0, 31, 31
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

label_80183430:
    ctx->pc = 0x80183430u;
    // 80183430: bc    12, 2, 0x8018343C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018343C;
        }
    }

label_80183434:
    ctx->pc = 0x80183434u;
    ctx->downcount -= 2;
    // 80183434: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80183438:
    ctx->pc = 0x80183438u;
    // 80183438: b       0x80183440
    {
            goto label_80183440;
    }

label_8018343C:
    ctx->pc = 0x8018343Cu;
    ctx->downcount -= 1;
    // 8018343C: li      r31, 1
    ctx->gpr[31] = (u32)(s32)(1);

label_80183440:
    ctx->pc = 0x80183440u;
    ctx->downcount -= 1;
    // 80183440: bl      0x80173F54
    {
            ctx->lr = 0x80183444u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80183444:
    ctx->pc = 0x80183444u;
    ctx->downcount -= 7;
    // 80183444: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80183448:
    ctx->pc = 0x80183448u;
    // 80183448: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018344C:
    ctx->pc = 0x8018344Cu;
    // 8018344C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183450:
    ctx->pc = 0x80183450u;
    // 80183450: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80183454:
    ctx->pc = 0x80183454u;
    // 80183454: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183458:
    ctx->pc = 0x80183458u;
    // 80183458: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018345C:
    ctx->pc = 0x8018345Cu;
    ctx->downcount -= 8;
    // 8018345C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183460:
    ctx->pc = 0x80183460u;
    // 80183460: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183464:
    ctx->pc = 0x80183464u;
    // 80183464: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183468:
    ctx->pc = 0x80183468u;
    // 80183468: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018346C:
    ctx->pc = 0x8018346Cu;
    // 8018346C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80183470:
    ctx->pc = 0x80183470u;
    // 80183470: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80183474:
    ctx->pc = 0x80183474u;
    // 80183474: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80183478:
    ctx->pc = 0x80183478u;
    // 80183478: bl      0x80173F2C
    {
            ctx->lr = 0x8018347Cu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018347C:
    ctx->pc = 0x8018347Cu;
    ctx->downcount -= 2;
    // 8018347C: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80183480:
    ctx->pc = 0x80183480u;
    // 80183480: bl      0x80183578
    {
            ctx->lr = 0x80183484u;
            goto label_80183578;
    }

label_80183484:
    ctx->pc = 0x80183484u;
    ctx->downcount -= 3;
    // 80183484: lwz     r0, -26644(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26644);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183488:
    ctx->pc = 0x80183488u;
    // 80183488: cmplwi  r0, 0x0000
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

label_8018348C:
    ctx->pc = 0x8018348Cu;
    // 8018348C: bc    12, 2, 0x80183498
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183498;
        }
    }

label_80183490:
    ctx->pc = 0x80183490u;
    ctx->downcount -= 2;
    // 80183490: stw     r30, -26640(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26640);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80183494:
    ctx->pc = 0x80183494u;
    // 80183494: b       0x80183554
    {
            goto label_80183554;
    }

label_80183498:
    ctx->pc = 0x80183498u;
    ctx->downcount -= 3;
    // 80183498: lwz     r3, -26680(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26680);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018349C:
    ctx->pc = 0x8018349Cu;
    // 8018349C: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801834A0:
    ctx->pc = 0x801834A0u;
    // 801834A0: bc    12, 2, 0x801834AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801834AC;
        }
    }

label_801834A4:
    ctx->pc = 0x801834A4u;
    ctx->downcount -= 2;
    // 801834A4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801834A8:
    ctx->pc = 0x801834A8u;
    // 801834A8: stw     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801834AC:
    ctx->pc = 0x801834ACu;
    ctx->downcount -= 1;
    // 801834AC: bl      0x80173F2C
    {
            ctx->lr = 0x801834B0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801834B0:
    ctx->pc = 0x801834B0u;
    ctx->downcount -= 2;
    // 801834B0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801834B4:
    ctx->pc = 0x801834B4u;
    // 801834B4: bl      0x80173F2C
    {
            ctx->lr = 0x801834B8u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801834B8:
    ctx->pc = 0x801834B8u;
    ctx->downcount -= 5;
    // 801834B8: lwz     r0, -26680(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26680);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801834BC:
    ctx->pc = 0x801834BCu;
    // 801834BC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801834C0:
    ctx->pc = 0x801834C0u;
    // 801834C0: stw     r4, -26664(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26664);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801834C4:
    ctx->pc = 0x801834C4u;
    // 801834C4: cmplwi  r0, 0x0000
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

label_801834C8:
    ctx->pc = 0x801834C8u;
    // 801834C8: bc    4, 2, 0x801834D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801834D0;
        }
    }

label_801834CC:
    ctx->pc = 0x801834CCu;
    ctx->downcount -= 1;
    // 801834CC: stw     r4, -26660(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26660);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801834D0:
    ctx->pc = 0x801834D0u;
    ctx->downcount -= 1;
    // 801834D0: bl      0x80173F54
    {
            ctx->lr = 0x801834D4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801834D4:
    ctx->pc = 0x801834D4u;
    ctx->downcount -= 1;
    // 801834D4: b       0x801834E0
    {
            goto label_801834E0;
    }

label_801834D8:
    ctx->downcount -= 2;
    // 801834D8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801834DC:
    // 801834DC: bl      0x80182DE0
    {
            ctx->lr = 0x801834E0u;
            ctx->pc = 0x80182DE0u;
            return;
    }

label_801834E0:
    ctx->downcount -= 1;
    // 801834E0: bl      0x8018367C
    {
            ctx->lr = 0x801834E4u;
            goto label_8018367C;
    }

label_801834E4:
    ctx->downcount -= 2;
    // 801834E4: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801834E8:
    // 801834E8: bc    4, 2, 0x801834D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801834D8u;
                return;
            }
            goto label_801834D8;
        }
    }

label_801834EC:
    ctx->pc = 0x801834ECu;
    ctx->downcount -= 3;
    // 801834EC: lwz     r3, -26680(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26680);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801834F0:
    ctx->pc = 0x801834F0u;
    // 801834F0: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801834F4:
    ctx->pc = 0x801834F4u;
    // 801834F4: bc    12, 2, 0x80183504
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183504;
        }
    }

label_801834F8:
    ctx->pc = 0x801834F8u;
    ctx->downcount -= 2;
    // 801834F8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801834FC:
    ctx->pc = 0x801834FCu;
    // 801834FC: bl      0x80182DE0
    {
            ctx->lr = 0x80183500u;
            ctx->pc = 0x80182DE0u;
            return;
    }

label_80183500:
    ctx->pc = 0x80183500u;
    ctx->downcount -= 1;
    // 80183500: b       0x80183520
    {
            goto label_80183520;
    }

label_80183504:
    ctx->pc = 0x80183504u;
    ctx->downcount -= 2;
    // 80183504: cmplwi  r30, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183508:
    ctx->pc = 0x80183508u;
    // 80183508: bc    12, 2, 0x80183520
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183520;
        }
    }

label_8018350C:
    ctx->pc = 0x8018350Cu;
    ctx->downcount -= 6;
    // 8018350C: addi    r12, r30, 0
    ctx->gpr[12] = ctx->gpr[30] + (u32)(s32)(0);

label_80183510:
    ctx->pc = 0x80183510u;
    // 80183510: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_80183514:
    ctx->pc = 0x80183514u;
    // 80183514: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80183518:
    ctx->pc = 0x80183518u;
    // 80183518: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8018351C:
    ctx->pc = 0x8018351Cu;
    // 8018351C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80183520u;
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183520:
    ctx->pc = 0x80183520u;
    ctx->downcount -= 1;
    // 80183520: bl      0x80173F2C
    {
            ctx->lr = 0x80183524u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80183524:
    ctx->pc = 0x80183524u;
    ctx->downcount -= 6;
    // 80183524: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80183528:
    ctx->pc = 0x80183528u;
    // 80183528: stw     r4, -26664(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26664);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8018352C:
    ctx->pc = 0x8018352Cu;
    // 8018352C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80183530:
    ctx->pc = 0x80183530u;
    // 80183530: lwz     r0, -26660(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26660);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183534:
    ctx->pc = 0x80183534u;
    // 80183534: cmpwi   r0, 0
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

label_80183538:
    ctx->pc = 0x80183538u;
    // 80183538: bc    12, 2, 0x80183544
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183544;
        }
    }

label_8018353C:
    ctx->pc = 0x8018353Cu;
    ctx->downcount -= 2;
    // 8018353C: stw     r4, -26660(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26660);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80183540:
    ctx->pc = 0x80183540u;
    // 80183540: bl      0x80180E50
    {
            ctx->lr = 0x80183544u;
            ctx->pc = 0x80180E50u;
            return;
    }

label_80183544:
    ctx->pc = 0x80183544u;
    ctx->downcount -= 2;
    // 80183544: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80183548:
    ctx->pc = 0x80183548u;
    // 80183548: bl      0x80173F54
    {
            ctx->lr = 0x8018354Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018354C:
    ctx->pc = 0x8018354Cu;
    ctx->downcount -= 2;
    // 8018354C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80183550:
    ctx->pc = 0x80183550u;
    // 80183550: bl      0x80173F54
    {
            ctx->lr = 0x80183554u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80183554:
    ctx->pc = 0x80183554u;
    ctx->downcount -= 2;
    // 80183554: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80183558:
    ctx->pc = 0x80183558u;
    // 80183558: bl      0x80173F54
    {
            ctx->lr = 0x8018355Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018355C:
    ctx->pc = 0x8018355Cu;
    ctx->downcount -= 8;
    // 8018355C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183560:
    ctx->pc = 0x80183560u;
    // 80183560: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183564:
    ctx->pc = 0x80183564u;
    // 80183564: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80183568:
    ctx->pc = 0x80183568u;
    // 80183568: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018356C:
    ctx->pc = 0x8018356Cu;
    // 8018356C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80183570:
    ctx->pc = 0x80183570u;
    // 80183570: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183574:
    ctx->pc = 0x80183574u;
    // 80183574: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183578:
    ctx->pc = 0x80183578u;
    ctx->downcount -= 14;
    // 80183578: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_8018357C:
    ctx->pc = 0x8018357Cu;
    // 8018357C: addi    r3, r3, 2008
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2008);

label_80183580:
    ctx->pc = 0x80183580u;
    // 80183580: stw     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80183584:
    ctx->pc = 0x80183584u;
    // 80183584: addi    r5, r3, 8
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(8);

label_80183588:
    ctx->pc = 0x80183588u;
    // 80183588: addi    r4, r3, 16
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(16);

label_8018358C:
    ctx->pc = 0x8018358Cu;
    // 8018358C: stw     r3, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80183590:
    ctx->pc = 0x80183590u;
    // 80183590: addi    r3, r3, 24
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(24);

label_80183594:
    ctx->pc = 0x80183594u;
    // 80183594: stw     r5, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80183598:
    ctx->pc = 0x80183598u;
    // 80183598: stw     r5, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8018359C:
    ctx->pc = 0x8018359Cu;
    // 8018359C: stw     r4, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801835A0:
    ctx->pc = 0x801835A0u;
    // 801835A0: stw     r4, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801835A4:
    ctx->pc = 0x801835A4u;
    // 801835A4: stw     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801835A8:
    ctx->pc = 0x801835A8u;
    // 801835A8: stw     r3, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801835AC:
    ctx->pc = 0x801835ACu;
    // 801835AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801835B0:
    ctx->pc = 0x801835B0u;
    ctx->downcount -= 8;
    // 801835B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801835B4:
    ctx->pc = 0x801835B4u;
    // 801835B4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801835B8:
    ctx->pc = 0x801835B8u;
    // 801835B8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801835BC:
    ctx->pc = 0x801835BCu;
    // 801835BC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801835C0:
    ctx->pc = 0x801835C0u;
    // 801835C0: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_801835C4:
    ctx->pc = 0x801835C4u;
    // 801835C4: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801835C8:
    ctx->pc = 0x801835C8u;
    // 801835C8: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_801835CC:
    ctx->pc = 0x801835CCu;
    // 801835CC: bl      0x80173F2C
    {
            ctx->lr = 0x801835D0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801835D0:
    ctx->pc = 0x801835D0u;
    ctx->downcount -= 11;
    // 801835D0: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_801835D4:
    ctx->pc = 0x801835D4u;
    // 801835D4: rlwinm r5, r30, 3, 0, 28
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[30], 3u) & 0xFFFFFFF8u;
    }

label_801835D8:
    ctx->pc = 0x801835D8u;
    // 801835D8: addi    r0, r4, 2008
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(2008);

label_801835DC:
    ctx->pc = 0x801835DCu;
    // 801835DC: add   r5, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_801835E0:
    ctx->pc = 0x801835E0u;
    // 801835E0: lwz     r4, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801835E4:
    ctx->pc = 0x801835E4u;
    // 801835E4: stw     r31, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801835E8:
    ctx->pc = 0x801835E8u;
    // 801835E8: lwz     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801835EC:
    ctx->pc = 0x801835ECu;
    // 801835EC: stw     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801835F0:
    ctx->pc = 0x801835F0u;
    // 801835F0: stw     r5, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801835F4:
    ctx->pc = 0x801835F4u;
    // 801835F4: stw     r31, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801835F8:
    ctx->pc = 0x801835F8u;
    // 801835F8: bl      0x80173F54
    {
            ctx->lr = 0x801835FCu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801835FC:
    ctx->pc = 0x801835FCu;
    ctx->downcount -= 8;
    // 801835FC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183600:
    ctx->pc = 0x80183600u;
    // 80183600: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80183604:
    ctx->pc = 0x80183604u;
    // 80183604: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183608:
    ctx->pc = 0x80183608u;
    // 80183608: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018360C:
    ctx->pc = 0x8018360Cu;
    // 8018360C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80183610:
    ctx->pc = 0x80183610u;
    // 80183610: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183614:
    ctx->pc = 0x80183614u;
    // 80183614: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183618:
    ctx->pc = 0x80183618u;
    ctx->downcount -= 6;
    // 80183618: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018361C:
    ctx->pc = 0x8018361Cu;
    // 8018361C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183620:
    ctx->pc = 0x80183620u;
    // 80183620: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183624:
    ctx->pc = 0x80183624u;
    // 80183624: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80183628:
    ctx->pc = 0x80183628u;
    // 80183628: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018362C:
    ctx->pc = 0x8018362Cu;
    // 8018362C: bl      0x80173F2C
    {
            ctx->lr = 0x80183630u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80183630:
    ctx->pc = 0x80183630u;
    ctx->downcount -= 10;
    // 80183630: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80183634:
    ctx->pc = 0x80183634u;
    // 80183634: rlwinm r5, r31, 3, 0, 28
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 3u) & 0xFFFFFFF8u;
    }

label_80183638:
    ctx->pc = 0x80183638u;
    // 80183638: addi    r0, r4, 2008
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(2008);

label_8018363C:
    ctx->pc = 0x8018363Cu;
    // 8018363C: add   r5, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_80183640:
    ctx->pc = 0x80183640u;
    // 80183640: lwz     r31, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183644:
    ctx->pc = 0x80183644u;
    // 80183644: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183648:
    ctx->pc = 0x80183648u;
    // 80183648: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018364C:
    ctx->pc = 0x8018364Cu;
    // 8018364C: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183650:
    ctx->pc = 0x80183650u;
    // 80183650: stw     r5, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80183654:
    ctx->pc = 0x80183654u;
    // 80183654: bl      0x80173F54
    {
            ctx->lr = 0x80183658u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80183658:
    ctx->pc = 0x80183658u;
    ctx->downcount -= 10;
    // 80183658: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018365C:
    ctx->pc = 0x8018365Cu;
    // 8018365C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183660:
    ctx->pc = 0x80183660u;
    // 80183660: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80183664:
    ctx->pc = 0x80183664u;
    // 80183664: stw     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183668:
    ctx->pc = 0x80183668u;
    // 80183668: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018366C:
    ctx->pc = 0x8018366Cu;
    // 8018366C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183670:
    ctx->pc = 0x80183670u;
    // 80183670: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80183674:
    ctx->pc = 0x80183674u;
    // 80183674: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183678:
    ctx->pc = 0x80183678u;
    // 80183678: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018367C:
    ctx->pc = 0x8018367Cu;
    ctx->downcount -= 5;
    // 8018367C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183680:
    ctx->pc = 0x80183680u;
    // 80183680: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183684:
    ctx->pc = 0x80183684u;
    // 80183684: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183688:
    ctx->pc = 0x80183688u;
    // 80183688: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018368C:
    ctx->pc = 0x8018368Cu;
    // 8018368C: bl      0x80173F2C
    {
            ctx->lr = 0x80183690u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80183690:
    ctx->pc = 0x80183690u;
    ctx->downcount -= 6;
    // 80183690: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_80183694:
    ctx->pc = 0x80183694u;
    // 80183694: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80183698:
    ctx->pc = 0x80183698u;
    // 80183698: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8018369C:
    ctx->pc = 0x8018369Cu;
    // 8018369C: addi    r4, r4, 2008
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2008);

label_801836A0:
    ctx->pc = 0x801836A0u;
    // 801836A0: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_801836A4:
    ctx->pc = 0x801836A4u;
    ctx->downcount -= 3;
    // 801836A4: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801836A8:
    // 801836A8: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801836AC:
    // 801836AC: bc    12, 2, 0x801836F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801836F4;
        }
    }

label_801836B0:
    ctx->downcount -= 1;
    // 801836B0: bl      0x80173F54
    {
            ctx->lr = 0x801836B4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801836B4:
    ctx->downcount -= 1;
    // 801836B4: bl      0x80173F2C
    {
            ctx->lr = 0x801836B8u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801836B8:
    ctx->downcount -= 10;
    // 801836B8: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_801836BC:
    // 801836BC: rlwinm r5, r31, 3, 0, 28
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 3u) & 0xFFFFFFF8u;
    }

label_801836C0:
    // 801836C0: addi    r0, r4, 2008
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(2008);

label_801836C4:
    // 801836C4: add   r5, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_801836C8:
    ctx->pc = 0x801836C8u;
    // 801836C8: lwz     r31, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801836CC:
    ctx->pc = 0x801836CCu;
    // 801836CC: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801836D0:
    ctx->pc = 0x801836D0u;
    // 801836D0: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801836D4:
    ctx->pc = 0x801836D4u;
    // 801836D4: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801836D8:
    ctx->pc = 0x801836D8u;
    // 801836D8: stw     r5, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801836DC:
    // 801836DC: bl      0x80173F54
    {
            ctx->lr = 0x801836E0u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801836E0:
    ctx->downcount -= 5;
    // 801836E0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801836E4:
    ctx->pc = 0x801836E4u;
    // 801836E4: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801836E8:
    // 801836E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801836EC:
    ctx->pc = 0x801836ECu;
    // 801836EC: stw     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801836F0:
    // 801836F0: b       0x80183708
    {
            goto label_80183708;
    }

label_801836F4:
    ctx->downcount -= 3;
    // 801836F4: addi    r4, r4, 8
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(8);

label_801836F8:
    // 801836F8: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_801836FC:
    // 801836FC: bc    16, 0, 0x801836A4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801836A4u;
                return;
            }
            goto label_801836A4;
        }
    }

label_80183700:
    ctx->pc = 0x80183700u;
    ctx->downcount -= 1;
    // 80183700: bl      0x80173F54
    {
            ctx->lr = 0x80183704u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80183704:
    ctx->pc = 0x80183704u;
    ctx->downcount -= 1;
    // 80183704: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80183708:
    ctx->pc = 0x80183708u;
    ctx->downcount -= 6;
    // 80183708: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018370C:
    ctx->pc = 0x8018370Cu;
    // 8018370C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183710:
    ctx->pc = 0x80183710u;
    // 80183710: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80183714:
    ctx->pc = 0x80183714u;
    // 80183714: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183718:
    ctx->pc = 0x80183718u;
    // 80183718: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018371C:
    ctx->pc = 0x8018371Cu;
    ctx->downcount -= 4;
    // 8018371C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183720:
    ctx->pc = 0x80183720u;
    // 80183720: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183724:
    ctx->pc = 0x80183724u;
    // 80183724: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183728:
    ctx->pc = 0x80183728u;
    // 80183728: bl      0x80173F2C
    {
            ctx->lr = 0x8018372Cu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018372C:
    ctx->pc = 0x8018372Cu;
    ctx->downcount -= 5;
    // 8018372C: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_80183730:
    ctx->pc = 0x80183730u;
    // 80183730: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80183734:
    ctx->pc = 0x80183734u;
    // 80183734: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80183738:
    ctx->pc = 0x80183738u;
    // 80183738: addi    r4, r4, 2008
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2008);

label_8018373C:
    ctx->pc = 0x8018373Cu;
    ctx->downcount -= 3;
    // 8018373C: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183740:
    // 80183740: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183744:
    // 80183744: bc    12, 2, 0x80183754
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183754;
        }
    }

label_80183748:
    ctx->downcount -= 1;
    // 80183748: bl      0x80173F54
    {
            ctx->lr = 0x8018374Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018374C:
    ctx->downcount -= 2;
    // 8018374C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80183750:
    // 80183750: b       0x80183764
    {
            goto label_80183764;
    }

label_80183754:
    ctx->downcount -= 2;
    // 80183754: addi    r4, r4, 8
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(8);

label_80183758:
    // 80183758: bc    16, 0, 0x8018373C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018373Cu;
                return;
            }
            goto label_8018373C;
        }
    }

label_8018375C:
    ctx->pc = 0x8018375Cu;
    ctx->downcount -= 1;
    // 8018375C: bl      0x80173F54
    {
            ctx->lr = 0x80183760u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80183760:
    ctx->pc = 0x80183760u;
    ctx->downcount -= 1;
    // 80183760: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80183764:
    ctx->pc = 0x80183764u;
    ctx->downcount -= 5;
    // 80183764: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183768:
    ctx->pc = 0x80183768u;
    // 80183768: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8018376C:
    ctx->pc = 0x8018376Cu;
    // 8018376C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183770:
    ctx->pc = 0x80183770u;
    // 80183770: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183774:
    ctx->pc = 0x80183774u;
    ctx->downcount -= 6;
    // 80183774: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183778:
    ctx->pc = 0x80183778u;
    // 80183778: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018377C:
    ctx->pc = 0x8018377Cu;
    // 8018377C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183780:
    ctx->pc = 0x80183780u;
    // 80183780: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80183784:
    ctx->pc = 0x80183784u;
    // 80183784: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80183788:
    ctx->pc = 0x80183788u;
    // 80183788: bl      0x80173F2C
    {
            ctx->lr = 0x8018378Cu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018378C:
    ctx->pc = 0x8018378Cu;
    ctx->downcount -= 4;
    // 8018378C: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183790:
    ctx->pc = 0x80183790u;
    // 80183790: lwz     r5, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183794:
    ctx->pc = 0x80183794u;
    // 80183794: cmplwi  r4, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183798:
    ctx->pc = 0x80183798u;
    // 80183798: bc    12, 2, 0x801837A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801837A4;
        }
    }

label_8018379C:
    ctx->pc = 0x8018379Cu;
    ctx->downcount -= 2;
    // 8018379C: cmplwi  r5, 0x0000
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

label_801837A0:
    ctx->pc = 0x801837A0u;
    // 801837A0: bc    4, 2, 0x801837B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801837B0;
        }
    }

label_801837A4:
    ctx->pc = 0x801837A4u;
    ctx->downcount -= 1;
    // 801837A4: bl      0x80173F54
    {
            ctx->lr = 0x801837A8u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801837A8:
    ctx->pc = 0x801837A8u;
    ctx->downcount -= 2;
    // 801837A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801837AC:
    ctx->pc = 0x801837ACu;
    // 801837AC: b       0x801837C0
    {
            goto label_801837C0;
    }

label_801837B0:
    ctx->pc = 0x801837B0u;
    ctx->downcount -= 3;
    // 801837B0: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801837B4:
    ctx->pc = 0x801837B4u;
    // 801837B4: stw     r4, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801837B8:
    ctx->pc = 0x801837B8u;
    // 801837B8: bl      0x80173F54
    {
            ctx->lr = 0x801837BCu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801837BC:
    ctx->pc = 0x801837BCu;
    ctx->downcount -= 1;
    // 801837BC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801837C0:
    ctx->pc = 0x801837C0u;
    ctx->downcount -= 6;
    // 801837C0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801837C4:
    ctx->pc = 0x801837C4u;
    // 801837C4: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801837C8:
    ctx->pc = 0x801837C8u;
    // 801837C8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801837CC:
    ctx->pc = 0x801837CCu;
    // 801837CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801837D0:
    ctx->pc = 0x801837D0u;
    // 801837D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801837D4:
    ctx->pc = 0x801837D4u;
    ctx->downcount -= 4;
    // 801837D4: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_801837D8:
    ctx->pc = 0x801837D8u;
    // 801837D8: lwzu     r0, 2008(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2008);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_801837DC:
    ctx->pc = 0x801837DCu;
    // 801837DC: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801837E0:
    ctx->pc = 0x801837E0u;
    // 801837E0: bc    12, 2, 0x80183808
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183808;
        }
    }

label_801837E4:
    ctx->pc = 0x801837E4u;
    ctx->downcount -= 2;
    // 801837E4: or   r5, r0, r0
    {
        ctx->gpr[5] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801837E8:
    ctx->pc = 0x801837E8u;
    // 801837E8: b       0x80183800
    {
            goto label_80183800;
    }

label_801837EC:
    ctx->downcount -= 2;
    // 801837EC: cmplw   r5, r3
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801837F0:
    // 801837F0: bc    4, 2, 0x801837FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801837FC;
        }
    }

label_801837F4:
    ctx->downcount -= 2;
    // 801837F4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801837F8:
    ctx->pc = 0x801837F8u;
    // 801837F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801837FC:
    ctx->pc = 0x801837FCu;
    ctx->downcount -= 1;
    // 801837FC: lwz     r5, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183800:
    ctx->downcount -= 2;
    // 80183800: cmplw   r5, r4
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183804:
    // 80183804: bc    4, 2, 0x801837EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801837ECu;
                return;
            }
            goto label_801837EC;
        }
    }

label_80183808:
    ctx->pc = 0x80183808u;
    ctx->downcount -= 3;
    // 80183808: lwzu     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8018380C:
    ctx->pc = 0x8018380Cu;
    // 8018380C: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183810:
    ctx->pc = 0x80183810u;
    // 80183810: bc    12, 2, 0x80183838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183838;
        }
    }

label_80183814:
    ctx->pc = 0x80183814u;
    ctx->downcount -= 2;
    // 80183814: or   r5, r0, r0
    {
        ctx->gpr[5] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80183818:
    ctx->pc = 0x80183818u;
    // 80183818: b       0x80183830
    {
            goto label_80183830;
    }

label_8018381C:
    ctx->downcount -= 2;
    // 8018381C: cmplw   r5, r3
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183820:
    // 80183820: bc    4, 2, 0x8018382C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018382C;
        }
    }

label_80183824:
    ctx->downcount -= 2;
    // 80183824: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80183828:
    ctx->pc = 0x80183828u;
    // 80183828: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018382C:
    ctx->pc = 0x8018382Cu;
    ctx->downcount -= 1;
    // 8018382C: lwz     r5, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183830:
    ctx->downcount -= 2;
    // 80183830: cmplw   r5, r4
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183834:
    // 80183834: bc    4, 2, 0x8018381C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018381Cu;
                return;
            }
            goto label_8018381C;
        }
    }

label_80183838:
    ctx->pc = 0x80183838u;
    ctx->downcount -= 3;
    // 80183838: lwzu     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8018383C:
    ctx->pc = 0x8018383Cu;
    // 8018383C: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183840:
    ctx->pc = 0x80183840u;
    // 80183840: bc    12, 2, 0x80183868
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183868;
        }
    }

label_80183844:
    ctx->pc = 0x80183844u;
    ctx->downcount -= 2;
    // 80183844: or   r5, r0, r0
    {
        ctx->gpr[5] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80183848:
    ctx->pc = 0x80183848u;
    // 80183848: b       0x80183860
    {
            goto label_80183860;
    }

label_8018384C:
    ctx->downcount -= 2;
    // 8018384C: cmplw   r5, r3
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183850:
    // 80183850: bc    4, 2, 0x8018385C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018385C;
        }
    }

label_80183854:
    ctx->downcount -= 2;
    // 80183854: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80183858:
    ctx->pc = 0x80183858u;
    // 80183858: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018385C:
    ctx->pc = 0x8018385Cu;
    ctx->downcount -= 1;
    // 8018385C: lwz     r5, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183860:
    ctx->downcount -= 2;
    // 80183860: cmplw   r5, r4
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183864:
    // 80183864: bc    4, 2, 0x8018384C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018384Cu;
                return;
            }
            goto label_8018384C;
        }
    }

label_80183868:
    ctx->pc = 0x80183868u;
    ctx->downcount -= 3;
    // 80183868: lwzu     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8018386C:
    ctx->pc = 0x8018386Cu;
    // 8018386C: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183870:
    ctx->pc = 0x80183870u;
    // 80183870: bc    12, 2, 0x80183898
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183898;
        }
    }

label_80183874:
    ctx->pc = 0x80183874u;
    ctx->downcount -= 2;
    // 80183874: or   r5, r0, r0
    {
        ctx->gpr[5] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80183878:
    ctx->pc = 0x80183878u;
    // 80183878: b       0x80183890
    {
            goto label_80183890;
    }

label_8018387C:
    ctx->downcount -= 2;
    // 8018387C: cmplw   r5, r3
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183880:
    // 80183880: bc    4, 2, 0x8018388C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018388C;
        }
    }

label_80183884:
    ctx->downcount -= 2;
    // 80183884: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80183888:
    ctx->pc = 0x80183888u;
    // 80183888: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018388C:
    ctx->pc = 0x8018388Cu;
    ctx->downcount -= 1;
    // 8018388C: lwz     r5, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183890:
    ctx->downcount -= 2;
    // 80183890: cmplw   r5, r4
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183894:
    // 80183894: bc    4, 2, 0x8018387C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018387Cu;
                return;
            }
            goto label_8018387C;
        }
    }

label_80183898:
    ctx->pc = 0x80183898u;
    ctx->downcount -= 2;
    // 80183898: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018389C:
    ctx->pc = 0x8018389Cu;
    // 8018389C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801838A0:
    ctx->pc = 0x801838A0u;
    ctx->downcount -= 12;
    // 801838A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801838A4:
    ctx->pc = 0x801838A4u;
    // 801838A4: lis     r3, -32732
    ctx->gpr[3] = ((u32)(s32)(-32732) << 16);

label_801838A8:
    ctx->pc = 0x801838A8u;
    // 801838A8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801838AC:
    ctx->pc = 0x801838ACu;
    // 801838AC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801838B0:
    ctx->pc = 0x801838B0u;
    // 801838B0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801838B4:
    ctx->pc = 0x801838B4u;
    // 801838B4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801838B8:
    ctx->pc = 0x801838B8u;
    // 801838B8: addi    r31, r3, -9440
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(-9440);

label_801838BC:
    ctx->pc = 0x801838BCu;
    // 801838BC: addi    r3, r31, 236
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(236);

label_801838C0:
    ctx->pc = 0x801838C0u;
    // 801838C0: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801838C4:
    ctx->pc = 0x801838C4u;
    // 801838C4: stw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801838C8:
    ctx->pc = 0x801838C8u;
    // 801838C8: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_801838CC:
    ctx->pc = 0x801838CCu;
    // 801838CC: bl      0x80172A0C
    {
            ctx->lr = 0x801838D0u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_801838D0:
    ctx->pc = 0x801838D0u;
    ctx->downcount -= 3;
    // 801838D0: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_801838D4:
    ctx->pc = 0x801838D4u;
    // 801838D4: addi    r30, r3, 2008
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(2008);

label_801838D8:
    ctx->pc = 0x801838D8u;
    // 801838D8: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801838DC:
    ctx->downcount -= 4;
    // 801838DC: addi    r4, r29, 0
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(0);

label_801838E0:
    // 801838E0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801838E4:
    // 801838E4: addi    r3, r31, 272
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(272);

label_801838E8:
    // 801838E8: bl      0x80172A0C
    {
            ctx->lr = 0x801838ECu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_801838EC:
    ctx->pc = 0x801838ECu;
    ctx->downcount -= 3;
    // 801838EC: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801838F0:
    // 801838F0: cmplw   r0, r30
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801838F4:
    // 801838F4: bc    4, 2, 0x80183908
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183908;
        }
    }

label_801838F8:
    ctx->downcount -= 3;
    // 801838F8: addi    r3, r13, -28788
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-28788);

label_801838FC:
    // 801838FC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183900:
    // 80183900: bl      0x80172A0C
    {
            ctx->lr = 0x80183904u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183904:
    ctx->downcount -= 1;
    // 80183904: b       0x8018397C
    {
            goto label_8018397C;
    }

label_80183908:
    ctx->downcount -= 3;
    // 80183908: addi    r3, r13, -28780
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-28780);

label_8018390C:
    // 8018390C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183910:
    // 80183910: bl      0x80172A0C
    {
            ctx->lr = 0x80183914u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183914:
    ctx->pc = 0x80183914u;
    ctx->downcount -= 2;
    // 80183914: lwz     r28, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80183918:
    // 80183918: b       0x80183974
    {
            goto label_80183974;
    }

label_8018391C:
    ctx->pc = 0x8018391Cu;
    ctx->downcount -= 8;
    // 8018391C: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183920:
    // 80183920: addi    r4, r28, 0
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(0);

label_80183924:
    // 80183924: addi    r3, r31, 288
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(288);

label_80183928:
    // 80183928: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8018392C:
    // 8018392C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80183930:
    // 80183930: add   r5, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_80183934:
    ctx->pc = 0x80183934u;
    // 80183934: lwz     r5, 172(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(172);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183938:
    // 80183938: bl      0x80172A0C
    {
            ctx->lr = 0x8018393Cu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_8018393C:
    ctx->pc = 0x8018393Cu;
    ctx->downcount -= 3;
    // 8018393C: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183940:
    // 80183940: cmplwi  r0, 0x0001
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

label_80183944:
    // 80183944: bc    4, 2, 0x80183964
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183964;
        }
    }

label_80183948:
    ctx->pc = 0x80183948u;
    ctx->downcount -= 6;
    // 80183948: lwz     r4, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018394C:
    // 8018394C: addi    r3, r31, 312
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(312);

label_80183950:
    ctx->pc = 0x80183950u;
    // 80183950: lwz     r5, 20(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183954:
    // 80183954: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183958:
    ctx->pc = 0x80183958u;
    // 80183958: lwz     r6, 24(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(24);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8018395C:
    // 8018395C: bl      0x80172A0C
    {
            ctx->lr = 0x80183960u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183960:
    ctx->downcount -= 1;
    // 80183960: b       0x80183970
    {
            goto label_80183970;
    }

label_80183964:
    ctx->downcount -= 3;
    // 80183964: addi    r3, r13, -28780
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-28780);

label_80183968:
    // 80183968: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8018396C:
    // 8018396C: bl      0x80172A0C
    {
            ctx->lr = 0x80183970u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183970:
    ctx->pc = 0x80183970u;
    ctx->downcount -= 1;
    // 80183970: lwz     r28, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80183974:
    ctx->downcount -= 2;
    // 80183974: cmplw   r28, r30
    {
        u32 val_a = (u32)(ctx->gpr[28]);
        u32 val_b = (u32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183978:
    // 80183978: bc    4, 2, 0x8018391C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018391Cu;
                return;
            }
            goto label_8018391C;
        }
    }

label_8018397C:
    ctx->downcount -= 4;
    // 8018397C: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_80183980:
    // 80183980: cmplwi  r29, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183984:
    // 80183984: addi    r30, r30, 8
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(8);

label_80183988:
    // 80183988: bc    12, 0, 0x801838DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801838DCu;
                return;
            }
            goto label_801838DC;
        }
    }

label_8018398C:
    ctx->pc = 0x8018398Cu;
    ctx->downcount -= 9;
    // 8018398C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183990:
    ctx->pc = 0x80183990u;
    // 80183990: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183994:
    ctx->pc = 0x80183994u;
    // 80183994: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80183998:
    ctx->pc = 0x80183998u;
    // 80183998: lwz     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018399C:
    ctx->pc = 0x8018399Cu;
    // 8018399C: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_801839A0:
    ctx->pc = 0x801839A0u;
    // 801839A0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801839A4:
    ctx->pc = 0x801839A4u;
    // 801839A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801839A8:
    ctx->pc = 0x801839A8u;
    // 801839A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801839AC:
    ctx->pc = 0x801839ACu;
    ctx->downcount -= 6;
    // 801839AC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_801839B0:
    ctx->pc = 0x801839B0u;
    // 801839B0: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_801839B4:
    ctx->pc = 0x801839B4u;
    // 801839B4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_801839B8:
    ctx->pc = 0x801839B8u;
    // 801839B8: addi    r4, r4, -9080
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-9080);

label_801839BC:
    ctx->pc = 0x801839BCu;
    // 801839BC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801839C0:
    ctx->pc = 0x801839C0u;
    ctx->downcount -= 3;
    // 801839C0: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801839C4:
    // 801839C4: cmplw   r3, r0
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

label_801839C8:
    // 801839C8: bc    4, 2, 0x801839D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801839D4;
        }
    }

label_801839CC:
    ctx->downcount -= 2;
    // 801839CC: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_801839D0:
    ctx->pc = 0x801839D0u;
    // 801839D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801839D4:
    ctx->pc = 0x801839D4u;
    ctx->downcount -= 4;
    // 801839D4: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_801839D8:
    // 801839D8: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_801839DC:
    // 801839DC: cmplw   r3, r0
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

label_801839E0:
    // 801839E0: bc    4, 2, 0x801839EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801839EC;
        }
    }

label_801839E4:
    ctx->downcount -= 2;
    // 801839E4: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_801839E8:
    ctx->pc = 0x801839E8u;
    // 801839E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801839EC:
    ctx->pc = 0x801839ECu;
    ctx->downcount -= 4;
    // 801839EC: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_801839F0:
    // 801839F0: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_801839F4:
    // 801839F4: cmplw   r3, r0
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

label_801839F8:
    // 801839F8: bc    4, 2, 0x80183A04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183A04;
        }
    }

label_801839FC:
    ctx->downcount -= 2;
    // 801839FC: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80183A00:
    ctx->pc = 0x80183A00u;
    // 80183A00: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183A04:
    ctx->pc = 0x80183A04u;
    ctx->downcount -= 4;
    // 80183A04: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183A08:
    // 80183A08: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_80183A0C:
    // 80183A0C: cmplw   r3, r0
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

label_80183A10:
    // 80183A10: bc    4, 2, 0x80183A1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183A1C;
        }
    }

label_80183A14:
    ctx->downcount -= 2;
    // 80183A14: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80183A18:
    ctx->pc = 0x80183A18u;
    // 80183A18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183A1C:
    ctx->pc = 0x80183A1Cu;
    ctx->downcount -= 4;
    // 80183A1C: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183A20:
    // 80183A20: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_80183A24:
    // 80183A24: cmplw   r3, r0
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

label_80183A28:
    // 80183A28: bc    4, 2, 0x80183A34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183A34;
        }
    }

label_80183A2C:
    ctx->downcount -= 2;
    // 80183A2C: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80183A30:
    ctx->pc = 0x80183A30u;
    // 80183A30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183A34:
    ctx->pc = 0x80183A34u;
    ctx->downcount -= 4;
    // 80183A34: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183A38:
    // 80183A38: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_80183A3C:
    // 80183A3C: cmplw   r3, r0
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

label_80183A40:
    // 80183A40: bc    4, 2, 0x80183A4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183A4C;
        }
    }

label_80183A44:
    ctx->downcount -= 2;
    // 80183A44: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80183A48:
    ctx->pc = 0x80183A48u;
    // 80183A48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183A4C:
    ctx->pc = 0x80183A4Cu;
    ctx->downcount -= 4;
    // 80183A4C: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183A50:
    // 80183A50: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_80183A54:
    // 80183A54: cmplw   r3, r0
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

label_80183A58:
    // 80183A58: bc    4, 2, 0x80183A64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183A64;
        }
    }

label_80183A5C:
    ctx->downcount -= 2;
    // 80183A5C: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80183A60:
    ctx->pc = 0x80183A60u;
    // 80183A60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183A64:
    ctx->pc = 0x80183A64u;
    ctx->downcount -= 4;
    // 80183A64: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183A68:
    // 80183A68: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_80183A6C:
    // 80183A6C: cmplw   r3, r0
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

label_80183A70:
    // 80183A70: bc    4, 2, 0x80183A7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183A7C;
        }
    }

label_80183A74:
    ctx->downcount -= 2;
    // 80183A74: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80183A78:
    ctx->pc = 0x80183A78u;
    // 80183A78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183A7C:
    ctx->pc = 0x80183A7Cu;
    ctx->downcount -= 4;
    // 80183A7C: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183A80:
    // 80183A80: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_80183A84:
    // 80183A84: cmplw   r3, r0
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

label_80183A88:
    // 80183A88: bc    4, 2, 0x80183A94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183A94;
        }
    }

label_80183A8C:
    ctx->downcount -= 2;
    // 80183A8C: rlwinm r3, r5, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80183A90:
    ctx->pc = 0x80183A90u;
    // 80183A90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183A94:
    ctx->downcount -= 3;
    // 80183A94: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_80183A98:
    // 80183A98: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_80183A9C:
    // 80183A9C: bc    16, 0, 0x801839C0
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801839C0u;
                return;
            }
            goto label_801839C0;
        }
    }

label_80183AA0:
    ctx->pc = 0x80183AA0u;
    ctx->downcount -= 3;
    // 80183AA0: lis     r4, 16
    ctx->gpr[4] = ((u32)(s32)(16) << 16);

label_80183AA4:
    ctx->pc = 0x80183AA4u;
    // 80183AA4: cmplw   r3, r4
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

label_80183AA8:
    ctx->pc = 0x80183AA8u;
    // 80183AA8: bc    12, 0, 0x80183AC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183AC0;
        }
    }

label_80183AAC:
    ctx->pc = 0x80183AACu;
    ctx->downcount -= 3;
    // 80183AAC: addi    r0, r4, 8
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(8);

label_80183AB0:
    ctx->pc = 0x80183AB0u;
    // 80183AB0: cmplw   r3, r0
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

label_80183AB4:
    ctx->pc = 0x80183AB4u;
    // 80183AB4: bc    12, 1, 0x80183AC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183AC0;
        }
    }

label_80183AB8:
    ctx->pc = 0x80183AB8u;
    ctx->downcount -= 2;
    // 80183AB8: li      r3, 17
    ctx->gpr[3] = (u32)(s32)(17);

label_80183ABC:
    ctx->pc = 0x80183ABCu;
    // 80183ABC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183AC0:
    ctx->pc = 0x80183AC0u;
    ctx->downcount -= 2;
    // 80183AC0: li      r3, 29
    ctx->gpr[3] = (u32)(s32)(29);

label_80183AC4:
    ctx->pc = 0x80183AC4u;
    // 80183AC4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183AC8:
    ctx->pc = 0x80183AC8u;
    ctx->downcount -= 3;
    // 80183AC8: addis   r0, r3, -291
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-291) << 16);

label_80183ACC:
    ctx->pc = 0x80183ACCu;
    // 80183ACC: cmplwi  r0, 0x4567
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x4567u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183AD0:
    ctx->pc = 0x80183AD0u;
    // 80183AD0: bc    4, 2, 0x80183ADC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183ADC;
        }
    }

label_80183AD4:
    ctx->pc = 0x80183AD4u;
    ctx->downcount -= 2;
    // 80183AD4: li      r3, 255
    ctx->gpr[3] = (u32)(s32)(255);

label_80183AD8:
    ctx->pc = 0x80183AD8u;
    // 80183AD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183ADC:
    ctx->pc = 0x80183ADCu;
    ctx->downcount -= 2;
    // 80183ADC: cmplwi  r0, 0x4568
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x4568u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183AE0:
    ctx->pc = 0x80183AE0u;
    // 80183AE0: bc    4, 2, 0x80183AEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183AEC;
        }
    }

label_80183AE4:
    ctx->pc = 0x80183AE4u;
    ctx->downcount -= 2;
    // 80183AE4: li      r3, 254
    ctx->gpr[3] = (u32)(s32)(254);

label_80183AE8:
    ctx->pc = 0x80183AE8u;
    // 80183AE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183AEC:
    ctx->pc = 0x80183AECu;
    ctx->downcount -= 8;
    // 80183AEC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80183AF0:
    ctx->pc = 0x80183AF0u;
    // 80183AF0: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_80183AF4:
    ctx->pc = 0x80183AF4u;
    // 80183AF4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80183AF8:
    ctx->pc = 0x80183AF8u;
    // 80183AF8: addi    r4, r4, -9080
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-9080);

label_80183AFC:
    ctx->pc = 0x80183AFCu;
    // 80183AFC: rlwinm r5, r3, 8, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x000000FFu;
    }

label_80183B00:
    ctx->pc = 0x80183B00u;
    // 80183B00: rlwinm r6, r3, 0, 8, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_80183B04:
    ctx->pc = 0x80183B04u;
    // 80183B04: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80183B08:
    ctx->pc = 0x80183B08u;
    ctx->downcount -= 3;
    // 80183B08: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183B0C:
    // 80183B0C: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183B10:
    // 80183B10: bc    4, 2, 0x80183B1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183B1C;
        }
    }

label_80183B14:
    ctx->downcount -= 2;
    // 80183B14: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183B18:
    // 80183B18: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183B1C:
    ctx->pc = 0x80183B1Cu;
    ctx->downcount -= 4;
    // 80183B1C: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183B20:
    // 80183B20: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183B24:
    // 80183B24: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183B28:
    // 80183B28: bc    4, 2, 0x80183B34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183B34;
        }
    }

label_80183B2C:
    ctx->downcount -= 2;
    // 80183B2C: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183B30:
    // 80183B30: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183B34:
    ctx->pc = 0x80183B34u;
    ctx->downcount -= 4;
    // 80183B34: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183B38:
    // 80183B38: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183B3C:
    // 80183B3C: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183B40:
    // 80183B40: bc    4, 2, 0x80183B4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183B4C;
        }
    }

label_80183B44:
    ctx->downcount -= 2;
    // 80183B44: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183B48:
    // 80183B48: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183B4C:
    ctx->pc = 0x80183B4Cu;
    ctx->downcount -= 4;
    // 80183B4C: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183B50:
    // 80183B50: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183B54:
    // 80183B54: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183B58:
    // 80183B58: bc    4, 2, 0x80183B64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183B64;
        }
    }

label_80183B5C:
    ctx->downcount -= 2;
    // 80183B5C: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183B60:
    // 80183B60: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183B64:
    ctx->pc = 0x80183B64u;
    ctx->downcount -= 4;
    // 80183B64: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183B68:
    // 80183B68: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183B6C:
    // 80183B6C: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183B70:
    // 80183B70: bc    4, 2, 0x80183B7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183B7C;
        }
    }

label_80183B74:
    ctx->downcount -= 2;
    // 80183B74: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183B78:
    // 80183B78: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183B7C:
    ctx->pc = 0x80183B7Cu;
    ctx->downcount -= 4;
    // 80183B7C: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183B80:
    // 80183B80: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183B84:
    // 80183B84: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183B88:
    // 80183B88: bc    4, 2, 0x80183B94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183B94;
        }
    }

label_80183B8C:
    ctx->downcount -= 2;
    // 80183B8C: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183B90:
    // 80183B90: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183B94:
    ctx->pc = 0x80183B94u;
    ctx->downcount -= 4;
    // 80183B94: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183B98:
    // 80183B98: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183B9C:
    // 80183B9C: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183BA0:
    // 80183BA0: bc    4, 2, 0x80183BAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183BAC;
        }
    }

label_80183BA4:
    ctx->downcount -= 2;
    // 80183BA4: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183BA8:
    // 80183BA8: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183BAC:
    ctx->pc = 0x80183BACu;
    ctx->downcount -= 4;
    // 80183BAC: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183BB0:
    // 80183BB0: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183BB4:
    // 80183BB4: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183BB8:
    // 80183BB8: bc    4, 2, 0x80183BC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183BC4;
        }
    }

label_80183BBC:
    ctx->downcount -= 2;
    // 80183BBC: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183BC0:
    // 80183BC0: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183BC4:
    ctx->pc = 0x80183BC4u;
    ctx->downcount -= 4;
    // 80183BC4: lwzu     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80183BC8:
    // 80183BC8: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183BCC:
    // 80183BCC: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183BD0:
    // 80183BD0: bc    4, 2, 0x80183BDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183BDC;
        }
    }

label_80183BD4:
    ctx->downcount -= 2;
    // 80183BD4: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183BD8:
    // 80183BD8: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183BDC:
    ctx->downcount -= 3;
    // 80183BDC: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_80183BE0:
    // 80183BE0: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80183BE4:
    // 80183BE4: bc    16, 0, 0x80183B08
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80183B08u;
                return;
            }
            goto label_80183B08;
        }
    }

label_80183BE8:
    ctx->pc = 0x80183BE8u;
    ctx->downcount -= 3;
    // 80183BE8: lis     r3, 16
    ctx->gpr[3] = ((u32)(s32)(16) << 16);

label_80183BEC:
    ctx->pc = 0x80183BECu;
    // 80183BEC: cmplw   r6, r3
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183BF0:
    ctx->pc = 0x80183BF0u;
    // 80183BF0: bc    12, 0, 0x80183C08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183C08;
        }
    }

label_80183BF4:
    ctx->pc = 0x80183BF4u;
    ctx->downcount -= 3;
    // 80183BF4: addi    r0, r3, 8
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(8);

label_80183BF8:
    ctx->pc = 0x80183BF8u;
    // 80183BF8: cmplw   r6, r0
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183BFC:
    ctx->pc = 0x80183BFCu;
    // 80183BFC: bc    12, 1, 0x80183C08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183C08;
        }
    }

label_80183C00:
    ctx->pc = 0x80183C00u;
    ctx->downcount -= 2;
    // 80183C00: li      r3, 17
    ctx->gpr[3] = (u32)(s32)(17);

label_80183C04:
    ctx->pc = 0x80183C04u;
    // 80183C04: b       0x80183C0C
    {
            goto label_80183C0C;
    }

label_80183C08:
    ctx->pc = 0x80183C08u;
    ctx->downcount -= 1;
    // 80183C08: li      r3, 29
    ctx->gpr[3] = (u32)(s32)(29);

label_80183C0C:
    ctx->pc = 0x80183C0Cu;
    ctx->downcount -= 2;
    // 80183C0C: cmplwi  r5, 0x0006
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0006u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183C10:
    ctx->pc = 0x80183C10u;
    // 80183C10: bc    12, 0, 0x80183C18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183C18;
        }
    }

label_80183C14:
    ctx->pc = 0x80183C14u;
    ctx->downcount -= 1;
    // 80183C14: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_80183C18:
    ctx->pc = 0x80183C18u;
    ctx->downcount -= 6;
    // 80183C18: mulli   r0, r5, 30
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[5] * (s64)(s32)30);

label_80183C1C:
    ctx->pc = 0x80183C1Cu;
    // 80183C1C: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183C20:
    ctx->pc = 0x80183C20u;
    // 80183C20: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80183C24:
    ctx->pc = 0x80183C24u;
    // 80183C24: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183C28:
    ctx->pc = 0x80183C28u;
    ctx->downcount -= 7;
    // 80183C28: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183C2C:
    ctx->pc = 0x80183C2Cu;
    // 80183C2C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183C30:
    ctx->pc = 0x80183C30u;
    // 80183C30: addis   r0, r3, -291
    ctx->gpr[0] = ctx->gpr[3] + ((u32)(s32)(-291) << 16);

label_80183C34:
    ctx->pc = 0x80183C34u;
    // 80183C34: cmplwi  r0, 0x4567
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x4567u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183C38:
    ctx->pc = 0x80183C38u;
    // 80183C38: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183C3C:
    ctx->pc = 0x80183C3Cu;
    // 80183C3C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80183C40:
    ctx->pc = 0x80183C40u;
    // 80183C40: bc    4, 2, 0x80183C4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183C4C;
        }
    }

label_80183C44:
    ctx->pc = 0x80183C44u;
    ctx->downcount -= 2;
    // 80183C44: li      r31, 255
    ctx->gpr[31] = (u32)(s32)(255);

label_80183C48:
    ctx->pc = 0x80183C48u;
    // 80183C48: b       0x80183C80
    {
            goto label_80183C80;
    }

label_80183C4C:
    ctx->pc = 0x80183C4Cu;
    ctx->downcount -= 2;
    // 80183C4C: cmplwi  r0, 0x4568
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x4568u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183C50:
    ctx->pc = 0x80183C50u;
    // 80183C50: bc    4, 2, 0x80183C5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183C5C;
        }
    }

label_80183C54:
    ctx->pc = 0x80183C54u;
    ctx->downcount -= 2;
    // 80183C54: li      r31, 254
    ctx->gpr[31] = (u32)(s32)(254);

label_80183C58:
    ctx->pc = 0x80183C58u;
    // 80183C58: b       0x80183C80
    {
            goto label_80183C80;
    }

label_80183C5C:
    ctx->pc = 0x80183C5Cu;
    ctx->downcount -= 3;
    // 80183C5C: rlwinm r31, r3, 8, 24, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x000000FFu;
    }

label_80183C60:
    ctx->pc = 0x80183C60u;
    // 80183C60: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_80183C64:
    ctx->pc = 0x80183C64u;
    // 80183C64: bl      0x801839AC
    {
            ctx->lr = 0x80183C68u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801839ACu;
                return;
            }
            goto label_801839AC;
    }

label_80183C68:
    ctx->pc = 0x80183C68u;
    ctx->downcount -= 2;
    // 80183C68: cmplwi  r31, 0x0006
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

label_80183C6C:
    ctx->pc = 0x80183C6Cu;
    // 80183C6C: bc    12, 0, 0x80183C74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183C74;
        }
    }

label_80183C70:
    ctx->pc = 0x80183C70u;
    ctx->downcount -= 1;
    // 80183C70: li      r31, 6
    ctx->gpr[31] = (u32)(s32)(6);

label_80183C74:
    ctx->pc = 0x80183C74u;
    ctx->downcount -= 5;
    // 80183C74: mulli   r0, r31, 30
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[31] * (s64)(s32)30);

label_80183C78:
    ctx->pc = 0x80183C78u;
    // 80183C78: rlwinm r3, r3, 0, 24, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80183C7C:
    ctx->pc = 0x80183C7Cu;
    // 80183C7C: add   r31, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_80183C80:
    ctx->pc = 0x80183C80u;
    ctx->downcount -= 1;
    // 80183C80: bl      0x80176F3C
    {
            ctx->lr = 0x80183C84u;
            ctx->pc = 0x80176F3Cu;
            return;
    }

label_80183C84:
    ctx->pc = 0x80183C84u;
    ctx->downcount -= 3;
    // 80183C84: stb     r31, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write8(ctx, ea, (u8)ctx->gpr[31]);
    }

label_80183C88:
    ctx->pc = 0x80183C88u;
    // 80183C88: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80183C8C:
    ctx->pc = 0x80183C8Cu;
    // 80183C8C: bl      0x801772C4
    {
            ctx->lr = 0x80183C90u;
            ctx->pc = 0x801772C4u;
            return;
    }

label_80183C90:
    ctx->pc = 0x80183C90u;
    ctx->downcount -= 6;
    // 80183C90: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183C94:
    ctx->pc = 0x80183C94u;
    // 80183C94: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183C98:
    ctx->pc = 0x80183C98u;
    // 80183C98: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80183C9C:
    ctx->pc = 0x80183C9Cu;
    // 80183C9C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183CA0:
    ctx->pc = 0x80183CA0u;
    // 80183CA0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183CA4:
    ctx->pc = 0x80183CA4u;
    ctx->downcount -= 7;
    // 80183CA4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183CA8:
    ctx->pc = 0x80183CA8u;
    // 80183CA8: cmpwi   r3, 0
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

label_80183CAC:
    ctx->pc = 0x80183CACu;
    // 80183CAC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183CB0:
    ctx->pc = 0x80183CB0u;
    // 80183CB0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183CB4:
    ctx->pc = 0x80183CB4u;
    // 80183CB4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80183CB8:
    ctx->pc = 0x80183CB8u;
    // 80183CB8: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80183CBC:
    ctx->pc = 0x80183CBCu;
    // 80183CBC: bc    4, 1, 0x80183D38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183D38;
        }
    }

label_80183CC0:
    ctx->pc = 0x80183CC0u;
    ctx->downcount -= 3;
    // 80183CC0: lwz     r0, -26592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183CC4:
    ctx->pc = 0x80183CC4u;
    // 80183CC4: cmpwi   r0, 1
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

label_80183CC8:
    ctx->pc = 0x80183CC8u;
    // 80183CC8: bc    12, 2, 0x80183D04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183D04;
        }
    }

label_80183CCC:
    ctx->pc = 0x80183CCCu;
    ctx->downcount -= 1;
    // 80183CCC: bc    4, 0, 0x80183D68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183D68;
        }
    }

label_80183CD0:
    ctx->pc = 0x80183CD0u;
    ctx->downcount -= 2;
    // 80183CD0: cmpwi   r0, 0
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

label_80183CD4:
    ctx->pc = 0x80183CD4u;
    // 80183CD4: bc    4, 0, 0x80183CDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183CDC;
        }
    }

label_80183CD8:
    ctx->pc = 0x80183CD8u;
    ctx->downcount -= 1;
    // 80183CD8: b       0x80183D68
    {
            goto label_80183D68;
    }

label_80183CDC:
    ctx->pc = 0x80183CDCu;
    ctx->downcount -= 9;
    // 80183CDC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80183CE0:
    ctx->pc = 0x80183CE0u;
    // 80183CE0: lwz     r4, -26588(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26588);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183CE4:
    ctx->pc = 0x80183CE4u;
    // 80183CE4: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80183CE8:
    ctx->pc = 0x80183CE8u;
    // 80183CE8: stw     r0, -26592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183CEC:
    ctx->pc = 0x80183CECu;
    // 80183CEC: addi    r7, r3, 15524
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(15524);

label_80183CF0:
    ctx->pc = 0x80183CF0u;
    // 80183CF0: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80183CF4:
    ctx->pc = 0x80183CF4u;
    // 80183CF4: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80183CF8:
    ctx->pc = 0x80183CF8u;
    // 80183CF8: li      r6, 1056
    ctx->gpr[6] = (u32)(s32)(1056);

label_80183CFC:
    ctx->pc = 0x80183CFCu;
    // 80183CFC: bl      0x80181B90
    {
            ctx->lr = 0x80183D00u;
            ctx->pc = 0x80181B90u;
            return;
    }

label_80183D00:
    ctx->pc = 0x80183D00u;
    ctx->downcount -= 1;
    // 80183D00: b       0x80183D68
    {
            goto label_80183D68;
    }

label_80183D04:
    ctx->pc = 0x80183D04u;
    ctx->downcount -= 12;
    // 80183D04: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80183D08:
    ctx->pc = 0x80183D08u;
    // 80183D08: lwz     r6, -26588(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26588);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80183D0C:
    ctx->pc = 0x80183D0Cu;
    // 80183D0C: stw     r0, -26592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183D10:
    ctx->pc = 0x80183D10u;
    // 80183D10: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80183D14:
    ctx->pc = 0x80183D14u;
    // 80183D14: addi    r7, r3, 15524
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(15524);

label_80183D18:
    ctx->pc = 0x80183D18u;
    // 80183D18: lwz     r5, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183D1C:
    ctx->pc = 0x80183D1Cu;
    // 80183D1C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80183D20:
    ctx->pc = 0x80183D20u;
    // 80183D20: lwz     r4, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183D24:
    ctx->pc = 0x80183D24u;
    // 80183D24: addi    r0, r5, 31
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(31);

label_80183D28:
    ctx->pc = 0x80183D28u;
    // 80183D28: lwz     r6, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80183D2C:
    ctx->pc = 0x80183D2Cu;
    // 80183D2C: rlwinm r5, r0, 0, 0, 26
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFE0u;
    }

label_80183D30:
    ctx->pc = 0x80183D30u;
    // 80183D30: bl      0x80181B90
    {
            ctx->lr = 0x80183D34u;
            ctx->pc = 0x80181B90u;
            return;
    }

label_80183D34:
    ctx->pc = 0x80183D34u;
    ctx->downcount -= 1;
    // 80183D34: b       0x80183D68
    {
            goto label_80183D68;
    }

label_80183D38:
    ctx->pc = 0x80183D38u;
    ctx->downcount -= 2;
    // 80183D38: cmpwi   r3, -1
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

label_80183D3C:
    ctx->pc = 0x80183D3Cu;
    // 80183D3C: bc    12, 2, 0x80183D68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80183D68;
        }
    }

label_80183D40:
    ctx->pc = 0x80183D40u;
    ctx->downcount -= 2;
    // 80183D40: cmpwi   r3, -4
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80183D44:
    ctx->pc = 0x80183D44u;
    // 80183D44: bc    4, 2, 0x80183D68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183D68;
        }
    }

label_80183D48:
    ctx->pc = 0x80183D48u;
    ctx->downcount -= 3;
    // 80183D48: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80183D4C:
    ctx->pc = 0x80183D4Cu;
    // 80183D4C: stw     r0, -26592(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183D50:
    ctx->pc = 0x80183D50u;
    // 80183D50: bl      0x80182C00
    {
            ctx->lr = 0x80183D54u;
            ctx->pc = 0x80182C00u;
            return;
    }

label_80183D54:
    ctx->pc = 0x80183D54u;
    ctx->downcount -= 5;
    // 80183D54: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80183D58:
    ctx->pc = 0x80183D58u;
    // 80183D58: lwz     r4, -26584(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26584);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183D5C:
    ctx->pc = 0x80183D5Cu;
    // 80183D5C: addi    r5, r3, 15524
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(15524);

label_80183D60:
    ctx->pc = 0x80183D60u;
    // 80183D60: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80183D64:
    ctx->pc = 0x80183D64u;
    // 80183D64: bl      0x80181C60
    {
            ctx->lr = 0x80183D68u;
            ctx->pc = 0x80181C60u;
            return;
    }

label_80183D68:
    ctx->pc = 0x80183D68u;
    ctx->downcount -= 6;
    // 80183D68: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183D6C:
    ctx->pc = 0x80183D6Cu;
    // 80183D6C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183D70:
    ctx->pc = 0x80183D70u;
    // 80183D70: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80183D74:
    ctx->pc = 0x80183D74u;
    // 80183D74: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183D78:
    ctx->pc = 0x80183D78u;
    // 80183D78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183D7C:
    ctx->pc = 0x80183D7Cu;
    ctx->downcount -= 9;
    // 80183D7C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183D80:
    ctx->pc = 0x80183D80u;
    // 80183D80: lis     r3, -32732
    ctx->gpr[3] = ((u32)(s32)(-32732) << 16);

label_80183D84:
    ctx->pc = 0x80183D84u;
    // 80183D84: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183D88:
    ctx->pc = 0x80183D88u;
    // 80183D88: stwu     r1, -96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-96);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183D8C:
    ctx->pc = 0x80183D8Cu;
    // 80183D8C: stw     r31, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80183D90:
    ctx->pc = 0x80183D90u;
    // 80183D90: addi    r31, r3, -9008
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(-9008);

label_80183D94:
    ctx->pc = 0x80183D94u;
    // 80183D94: stw     r30, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80183D98:
    ctx->pc = 0x80183D98u;
    // 80183D98: stw     r29, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80183D9C:
    ctx->pc = 0x80183D9Cu;
    // 80183D9C: bl      0x80171228
    {
            ctx->lr = 0x80183DA0u;
            ctx->pc = 0x80171228u;
            return;
    }

label_80183DA0:
    ctx->pc = 0x80183DA0u;
    ctx->downcount -= 9;
    // 80183DA0: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80183DA4:
    ctx->pc = 0x80183DA4u;
    // 80183DA4: addi    r3, r3, 2040
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2040);

label_80183DA8:
    ctx->pc = 0x80183DA8u;
    // 80183DA8: addi    r4, r1, 43
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(43);

label_80183DAC:
    ctx->pc = 0x80183DACu;
    // 80183DAC: addi    r0, r3, 31
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(31);

label_80183DB0:
    ctx->pc = 0x80183DB0u;
    // 80183DB0: rlwinm r3, r4, 0, 0, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFE0u;
    }

label_80183DB4:
    ctx->pc = 0x80183DB4u;
    // 80183DB4: rlwinm r0, r0, 0, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFE0u;
    }

label_80183DB8:
    ctx->pc = 0x80183DB8u;
    // 80183DB8: stw     r3, -26584(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26584);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80183DBC:
    ctx->pc = 0x80183DBCu;
    // 80183DBC: stw     r0, -26588(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26588);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183DC0:
    ctx->pc = 0x80183DC0u;
    // 80183DC0: bl      0x80182C00
    {
            ctx->lr = 0x80183DC4u;
            ctx->pc = 0x80182C00u;
            return;
    }

label_80183DC4:
    ctx->pc = 0x80183DC4u;
    ctx->downcount -= 6;
    // 80183DC4: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80183DC8:
    ctx->pc = 0x80183DC8u;
    // 80183DC8: lwz     r4, -26584(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26584);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183DCC:
    ctx->pc = 0x80183DCCu;
    // 80183DCC: lis     r5, -32744
    ctx->gpr[5] = ((u32)(s32)(-32744) << 16);

label_80183DD0:
    ctx->pc = 0x80183DD0u;
    // 80183DD0: addi    r3, r3, 2104
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2104);

label_80183DD4:
    ctx->pc = 0x80183DD4u;
    // 80183DD4: addi    r5, r5, 15524
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(15524);

label_80183DD8:
    ctx->pc = 0x80183DD8u;
    // 80183DD8: bl      0x80181C60
    {
            ctx->lr = 0x80183DDCu;
            ctx->pc = 0x80181C60u;
            return;
    }

label_80183DDC:
    ctx->downcount -= 1;
    // 80183DDC: bl      0x80182C98
    {
            ctx->lr = 0x80183DE0u;
            ctx->pc = 0x80182C98u;
            return;
    }

label_80183DE0:
    ctx->downcount -= 2;
    // 80183DE0: cmpwi   r3, 0
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

label_80183DE4:
    // 80183DE4: bc    4, 2, 0x80183DDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80183DDCu;
                return;
            }
            goto label_80183DDC;
        }
    }

label_80183DE8:
    ctx->pc = 0x80183DE8u;
    ctx->downcount -= 12;
    // 80183DE8: lwz     r3, -26588(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26588);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80183DEC:
    ctx->pc = 0x80183DECu;
    // 80183DEC: lis     r29, -32768
    ctx->gpr[29] = ((u32)(s32)(-32768) << 16);

label_80183DF0:
    ctx->pc = 0x80183DF0u;
    // 80183DF0: lis     r30, -32768
    ctx->gpr[30] = ((u32)(s32)(-32768) << 16);

label_80183DF4:
    ctx->pc = 0x80183DF4u;
    // 80183DF4: lwz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183DF8:
    ctx->pc = 0x80183DF8u;
    // 80183DF8: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_80183DFC:
    ctx->pc = 0x80183DFCu;
    // 80183DFC: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80183E00:
    ctx->pc = 0x80183E00u;
    // 80183E00: stw     r0, 56(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183E04:
    ctx->pc = 0x80183E04u;
    // 80183E04: lwz     r4, -26588(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26588);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183E08:
    ctx->pc = 0x80183E08u;
    // 80183E08: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183E0C:
    ctx->pc = 0x80183E0Cu;
    // 80183E0C: stw     r0, 60(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183E10:
    ctx->pc = 0x80183E10u;
    // 80183E10: lwz     r4, -26584(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26584);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183E14:
    ctx->pc = 0x80183E14u;
    // 80183E14: bl      0x8016984C
    {
            ctx->lr = 0x80183E18u;
            ctx->pc = 0x8016984Cu;
            return;
    }

label_80183E18:
    ctx->pc = 0x80183E18u;
    ctx->downcount -= 3;
    // 80183E18: addi    r3, r13, -28776
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-28776);

label_80183E1C:
    ctx->pc = 0x80183E1Cu;
    // 80183E1C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183E20:
    ctx->pc = 0x80183E20u;
    // 80183E20: bl      0x80172A0C
    {
            ctx->lr = 0x80183E24u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183E24:
    ctx->pc = 0x80183E24u;
    ctx->downcount -= 11;
    // 80183E24: lbz     r4, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80183E28:
    ctx->pc = 0x80183E28u;
    // 80183E28: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80183E2C:
    ctx->pc = 0x80183E2Cu;
    // 80183E2C: lbz     r5, 1(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80183E30:
    ctx->pc = 0x80183E30u;
    // 80183E30: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183E34:
    ctx->pc = 0x80183E34u;
    // 80183E34: lbz     r6, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80183E38:
    ctx->pc = 0x80183E38u;
    // 80183E38: lbz     r7, 3(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(3);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80183E3C:
    ctx->pc = 0x80183E3Cu;
    // 80183E3C: extsb r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_80183E40:
    ctx->pc = 0x80183E40u;
    // 80183E40: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80183E44:
    ctx->pc = 0x80183E44u;
    // 80183E44: extsb r6, r6
    {
        ctx->gpr[6] = (u32)(s32)(s8)ctx->gpr[6];
    }

label_80183E48:
    ctx->pc = 0x80183E48u;
    // 80183E48: extsb r7, r7
    {
        ctx->gpr[7] = (u32)(s32)(s8)ctx->gpr[7];
    }

label_80183E4C:
    ctx->pc = 0x80183E4Cu;
    // 80183E4C: bl      0x80172A0C
    {
            ctx->lr = 0x80183E50u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183E50:
    ctx->pc = 0x80183E50u;
    ctx->downcount -= 7;
    // 80183E50: lbz     r4, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80183E54:
    ctx->pc = 0x80183E54u;
    // 80183E54: addi    r3, r31, 28
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(28);

label_80183E58:
    ctx->pc = 0x80183E58u;
    // 80183E58: lbz     r5, 5(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80183E5C:
    ctx->pc = 0x80183E5Cu;
    // 80183E5C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183E60:
    ctx->pc = 0x80183E60u;
    // 80183E60: extsb r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_80183E64:
    ctx->pc = 0x80183E64u;
    // 80183E64: extsb r5, r5
    {
        ctx->gpr[5] = (u32)(s32)(s8)ctx->gpr[5];
    }

label_80183E68:
    ctx->pc = 0x80183E68u;
    // 80183E68: bl      0x80172A0C
    {
            ctx->lr = 0x80183E6Cu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183E6C:
    ctx->pc = 0x80183E6Cu;
    ctx->downcount -= 4;
    // 80183E6C: lbz     r4, 6(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80183E70:
    ctx->pc = 0x80183E70u;
    // 80183E70: addi    r3, r31, 52
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(52);

label_80183E74:
    ctx->pc = 0x80183E74u;
    // 80183E74: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183E78:
    ctx->pc = 0x80183E78u;
    // 80183E78: bl      0x80172A0C
    {
            ctx->lr = 0x80183E7Cu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183E7C:
    ctx->pc = 0x80183E7Cu;
    ctx->downcount -= 4;
    // 80183E7C: lbz     r4, 7(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(7);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80183E80:
    ctx->pc = 0x80183E80u;
    // 80183E80: addi    r3, r31, 72
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(72);

label_80183E84:
    ctx->pc = 0x80183E84u;
    // 80183E84: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183E88:
    ctx->pc = 0x80183E88u;
    // 80183E88: bl      0x80172A0C
    {
            ctx->lr = 0x80183E8Cu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183E8C:
    ctx->pc = 0x80183E8Cu;
    ctx->downcount -= 3;
    // 80183E8C: lbz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80183E90:
    ctx->pc = 0x80183E90u;
    // 80183E90: cmplwi  r0, 0x0000
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

label_80183E94:
    ctx->pc = 0x80183E94u;
    // 80183E94: bc    4, 2, 0x80183EA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183EA0;
        }
    }

label_80183E98:
    ctx->pc = 0x80183E98u;
    ctx->downcount -= 2;
    // 80183E98: addi    r4, r13, -28772
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-28772);

label_80183E9C:
    ctx->pc = 0x80183E9Cu;
    // 80183E9C: b       0x80183EA4
    {
            goto label_80183EA4;
    }

label_80183EA0:
    ctx->pc = 0x80183EA0u;
    ctx->downcount -= 1;
    // 80183EA0: addi    r4, r13, -28768
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-28768);

label_80183EA4:
    ctx->pc = 0x80183EA4u;
    ctx->downcount -= 3;
    // 80183EA4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183EA8:
    ctx->pc = 0x80183EA8u;
    // 80183EA8: addi    r3, r31, 92
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(92);

label_80183EAC:
    ctx->pc = 0x80183EACu;
    // 80183EAC: bl      0x80172A0C
    {
            ctx->lr = 0x80183EB0u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183EB0:
    ctx->pc = 0x80183EB0u;
    ctx->downcount -= 3;
    // 80183EB0: addi    r3, r13, -28776
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-28776);

label_80183EB4:
    ctx->pc = 0x80183EB4u;
    // 80183EB4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80183EB8:
    ctx->pc = 0x80183EB8u;
    // 80183EB8: bl      0x80172A0C
    {
            ctx->lr = 0x80183EBCu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80183EBC:
    ctx->pc = 0x80183EBCu;
    ctx->downcount -= 3;
    // 80183EBC: lwz     r3, -26588(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26588);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80183EC0:
    ctx->pc = 0x80183EC0u;
    // 80183EC0: lwz     r3, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80183EC4:
    ctx->pc = 0x80183EC4u;
    // 80183EC4: bl      0x80171238
    {
            ctx->lr = 0x80183EC8u;
            ctx->pc = 0x80171238u;
            return;
    }

label_80183EC8:
    ctx->pc = 0x80183EC8u;
    ctx->downcount -= 8;
    // 80183EC8: lwz     r0, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183ECC:
    ctx->pc = 0x80183ECCu;
    // 80183ECC: lwz     r31, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80183ED0:
    ctx->pc = 0x80183ED0u;
    // 80183ED0: lwz     r30, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80183ED4:
    ctx->pc = 0x80183ED4u;
    // 80183ED4: lwz     r29, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80183ED8:
    ctx->pc = 0x80183ED8u;
    // 80183ED8: addi    r1, r1, 96
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(96);

label_80183EDC:
    ctx->pc = 0x80183EDCu;
    // 80183EDC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183EE0:
    ctx->pc = 0x80183EE0u;
    // 80183EE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183EE4:
    ctx->pc = 0x80183EE4u;
    ctx->downcount -= 11;
    // 80183EE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183EE8:
    ctx->pc = 0x80183EE8u;
    // 80183EE8: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80183EEC:
    ctx->pc = 0x80183EECu;
    // 80183EEC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183EF0:
    ctx->pc = 0x80183EF0u;
    // 80183EF0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80183EF4:
    ctx->pc = 0x80183EF4u;
    // 80183EF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80183EF8:
    ctx->pc = 0x80183EF8u;
    // 80183EF8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183EFC:
    ctx->pc = 0x80183EFCu;
    // 80183EFC: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183F00:
    ctx->pc = 0x80183F00u;
    // 80183F00: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80183F04:
    ctx->pc = 0x80183F04u;
    // 80183F04: stw     r0, 2152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2152);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183F08:
    ctx->pc = 0x80183F08u;
    // 80183F08: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80183F0C:
    ctx->pc = 0x80183F0Cu;
    // 80183F0C: bl      0x80185150
    {
            ctx->lr = 0x80183F10u;
            goto label_80185150;
    }

label_80183F10:
    ctx->pc = 0x80183F10u;
    ctx->downcount -= 1;
    // 80183F10: bl      0x8016FEA0
    {
            ctx->lr = 0x80183F14u;
            ctx->pc = 0x8016FEA0u;
            return;
    }

label_80183F14:
    ctx->pc = 0x80183F14u;
    ctx->downcount -= 5;
    // 80183F14: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183F18:
    ctx->pc = 0x80183F18u;
    // 80183F18: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80183F1C:
    ctx->pc = 0x80183F1Cu;
    // 80183F1C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183F20:
    ctx->pc = 0x80183F20u;
    // 80183F20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183F24:
    ctx->pc = 0x80183F24u;
    ctx->downcount -= 12;
    // 80183F24: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183F28:
    ctx->pc = 0x80183F28u;
    // 80183F28: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80183F2C:
    ctx->pc = 0x80183F2Cu;
    // 80183F2C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183F30:
    ctx->pc = 0x80183F30u;
    // 80183F30: addi    r4, r3, 2152
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(2152);

label_80183F34:
    ctx->pc = 0x80183F34u;
    // 80183F34: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183F38:
    ctx->pc = 0x80183F38u;
    // 80183F38: lwz     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183F3C:
    ctx->pc = 0x80183F3Cu;
    // 80183F3C: mulli   r0, r0, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_80183F40:
    ctx->pc = 0x80183F40u;
    // 80183F40: lwzx    r3, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80183F44:
    ctx->pc = 0x80183F44u;
    // 80183F44: cmpwi   r3, 1
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

label_80183F48:
    ctx->pc = 0x80183F48u;
    // 80183F48: bc    4, 2, 0x80183F78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183F78;
        }
    }

label_80183F4C:
    ctx->pc = 0x80183F4Cu;
    ctx->downcount -= 9;
    // 80183F4C: lwz     r3, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80183F50:
    ctx->pc = 0x80183F50u;
    // 80183F50: add   r6, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80183F54:
    ctx->pc = 0x80183F54u;
    // 80183F54: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_80183F58:
    ctx->pc = 0x80183F58u;
    // 80183F58: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183F5C:
    ctx->pc = 0x80183F5Cu;
    // 80183F5C: lwz     r3, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80183F60:
    ctx->pc = 0x80183F60u;
    // 80183F60: lwz     r4, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183F64:
    ctx->pc = 0x80183F64u;
    // 80183F64: lwz     r5, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80183F68:
    ctx->pc = 0x80183F68u;
    // 80183F68: lwz     r6, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80183F6C:
    ctx->pc = 0x80183F6Cu;
    // 80183F6C: bl      0x80184404
    {
            ctx->lr = 0x80183F70u;
            goto label_80184404;
    }

label_80183F70:
    ctx->pc = 0x80183F70u;
    ctx->downcount -= 2;
    // 80183F70: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80183F74:
    ctx->pc = 0x80183F74u;
    // 80183F74: b       0x80183FA8
    {
            goto label_80183FA8;
    }

label_80183F78:
    ctx->pc = 0x80183F78u;
    ctx->downcount -= 2;
    // 80183F78: cmpwi   r3, 2
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

label_80183F7C:
    ctx->pc = 0x80183F7Cu;
    // 80183F7C: bc    4, 2, 0x80183FA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80183FA4;
        }
    }

label_80183F80:
    ctx->pc = 0x80183F80u;
    ctx->downcount -= 7;
    // 80183F80: lwz     r3, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80183F84:
    ctx->pc = 0x80183F84u;
    // 80183F84: add   r4, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80183F88:
    ctx->pc = 0x80183F88u;
    // 80183F88: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_80183F8C:
    ctx->pc = 0x80183F8Cu;
    // 80183F8C: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183F90:
    ctx->pc = 0x80183F90u;
    // 80183F90: lwz     r3, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80183F94:
    ctx->pc = 0x80183F94u;
    // 80183F94: lwz     r4, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80183F98:
    ctx->pc = 0x80183F98u;
    // 80183F98: bl      0x801849C4
    {
            ctx->lr = 0x80183F9Cu;
            goto label_801849C4;
    }

label_80183F9C:
    ctx->pc = 0x80183F9Cu;
    ctx->downcount -= 2;
    // 80183F9C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80183FA0:
    ctx->pc = 0x80183FA0u;
    // 80183FA0: b       0x80183FA8
    {
            goto label_80183FA8;
    }

label_80183FA4:
    ctx->pc = 0x80183FA4u;
    ctx->downcount -= 1;
    // 80183FA4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80183FA8:
    ctx->pc = 0x80183FA8u;
    ctx->downcount -= 5;
    // 80183FA8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183FAC:
    ctx->pc = 0x80183FACu;
    // 80183FAC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80183FB0:
    ctx->pc = 0x80183FB0u;
    // 80183FB0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80183FB4:
    ctx->pc = 0x80183FB4u;
    // 80183FB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80183FB8:
    ctx->pc = 0x80183FB8u;
    ctx->downcount -= 13;
    // 80183FB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80183FBC:
    ctx->pc = 0x80183FBCu;
    // 80183FBC: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80183FC0:
    ctx->pc = 0x80183FC0u;
    // 80183FC0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80183FC4:
    ctx->pc = 0x80183FC4u;
    // 80183FC4: stwu     r1, -744(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-744);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80183FC8:
    ctx->pc = 0x80183FC8u;
    // 80183FC8: stw     r31, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80183FCC:
    ctx->pc = 0x80183FCCu;
    // 80183FCC: stw     r30, 736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(736);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80183FD0:
    ctx->pc = 0x80183FD0u;
    // 80183FD0: addi    r30, r3, 2152
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(2152);

label_80183FD4:
    ctx->pc = 0x80183FD4u;
    // 80183FD4: addi    r3, r30, 104
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(104);

label_80183FD8:
    ctx->pc = 0x80183FD8u;
    // 80183FD8: stw     r29, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80183FDC:
    ctx->pc = 0x80183FDCu;
    // 80183FDC: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80183FE0:
    ctx->pc = 0x80183FE0u;
    // 80183FE0: stw     r28, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80183FE4:
    ctx->pc = 0x80183FE4u;
    // 80183FE4: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_80183FE8:
    ctx->pc = 0x80183FE8u;
    // 80183FE8: bl      0x8017029C
    {
            ctx->lr = 0x80183FECu;
            ctx->pc = 0x8017029Cu;
            return;
    }

label_80183FEC:
    ctx->pc = 0x80183FECu;
    ctx->downcount -= 3;
    // 80183FEC: lwz     r0, -26512(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26512);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80183FF0:
    ctx->pc = 0x80183FF0u;
    // 80183FF0: cmpwi   r0, 0
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

label_80183FF4:
    ctx->pc = 0x80183FF4u;
    // 80183FF4: bc    12, 2, 0x80184034
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184034;
        }
    }

label_80183FF8:
    ctx->pc = 0x80183FF8u;
    ctx->downcount -= 1;
    // 80183FF8: bl      0x8017A0AC
    {
            ctx->lr = 0x80183FFCu;
            ctx->pc = 0x8017A0ACu;
            return;
    }

label_80183FFC:
    ctx->pc = 0x80183FFCu;
    ctx->downcount -= 13;
    // 80183FFC: stw     r4, -26524(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26524);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184000:
    ctx->pc = 0x80184000u;
    // 80184000: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184004:
    ctx->pc = 0x80184004u;
    // 80184004: stw     r3, -26528(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26528);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184008:
    ctx->pc = 0x80184008u;
    // 80184008: stw     r0, -28760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018400C:
    ctx->pc = 0x8018400Cu;
    // 8018400C: lwz     r0, 196(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184010:
    ctx->pc = 0x80184010u;
    // 80184010: stw     r0, 184(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184014:
    ctx->pc = 0x80184014u;
    // 80184014: lwz     r0, 200(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184018:
    ctx->pc = 0x80184018u;
    // 80184018: stw     r0, 188(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(188);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018401C:
    ctx->pc = 0x8018401Cu;
    // 8018401C: lwz     r0, 204(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(204);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184020:
    ctx->pc = 0x80184020u;
    // 80184020: stw     r0, 192(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(192);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184024:
    ctx->pc = 0x80184024u;
    // 80184024: lwz     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184028:
    ctx->pc = 0x80184028u;
    // 80184028: cmpwi   r0, 1
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

label_8018402C:
    ctx->pc = 0x8018402Cu;
    // 8018402C: bc    4, 2, 0x80184034
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80184034;
        }
    }

label_80184030:
    ctx->pc = 0x80184030u;
    ctx->downcount -= 1;
    // 80184030: ori     r29, r29, 0x0008
    ctx->gpr[29] = ctx->gpr[29] | 0x0008u;

label_80184034:
    ctx->pc = 0x80184034u;
    ctx->downcount -= 11;
    // 80184034: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184038:
    ctx->pc = 0x80184038u;
    // 80184038: stw     r0, -26512(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26512);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018403C:
    ctx->pc = 0x8018403Cu;
    // 8018403C: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80184040:
    ctx->pc = 0x80184040u;
    // 80184040: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184044:
    ctx->pc = 0x80184044u;
    // 80184044: lwz     r0, 24576(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24576);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184048:
    ctx->pc = 0x80184048u;
    // 80184048: andi.   r4, r0, 0x002A
    {
        ctx->gpr[4] = ctx->gpr[0] & 0x002Au;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018404C:
    ctx->pc = 0x8018404Cu;
    // 8018404C: andi.   r3, r0, 0x0054
    {
        ctx->gpr[3] = ctx->gpr[0] & 0x0054u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80184050:
    ctx->pc = 0x80184050u;
    // 80184050: rlwinm r0, r4, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_80184054:
    ctx->pc = 0x80184054u;
    // 80184054: and   r3, r3, r0
    {
        ctx->gpr[3] = ctx->gpr[3] & ctx->gpr[0];
    }

label_80184058:
    ctx->pc = 0x80184058u;
    // 80184058: rlwinm. r0, r3, 0, 25, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000040u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018405C:
    ctx->pc = 0x8018405Cu;
    // 8018405C: bc    12, 2, 0x80184064
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184064;
        }
    }

label_80184060:
    ctx->pc = 0x80184060u;
    ctx->downcount -= 1;
    // 80184060: ori     r29, r29, 0x0008
    ctx->gpr[29] = ctx->gpr[29] | 0x0008u;

label_80184064:
    ctx->pc = 0x80184064u;
    ctx->downcount -= 2;
    // 80184064: rlwinm. r0, r3, 0, 27, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80184068:
    ctx->pc = 0x80184068u;
    // 80184068: bc    12, 2, 0x80184070
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184070;
        }
    }

label_8018406C:
    ctx->pc = 0x8018406Cu;
    ctx->downcount -= 1;
    // 8018406C: ori     r29, r29, 0x0001
    ctx->gpr[29] = ctx->gpr[29] | 0x0001u;

label_80184070:
    ctx->pc = 0x80184070u;
    ctx->downcount -= 2;
    // 80184070: rlwinm. r0, r3, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80184074:
    ctx->pc = 0x80184074u;
    // 80184074: bc    12, 2, 0x8018407C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018407C;
        }
    }

label_80184078:
    ctx->pc = 0x80184078u;
    ctx->downcount -= 1;
    // 80184078: ori     r29, r29, 0x0002
    ctx->gpr[29] = ctx->gpr[29] | 0x0002u;

label_8018407C:
    ctx->pc = 0x8018407Cu;
    ctx->downcount -= 2;
    // 8018407C: cmplwi  r29, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80184080:
    ctx->pc = 0x80184080u;
    // 80184080: bc    12, 2, 0x8018408C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018408C;
        }
    }

label_80184084:
    ctx->pc = 0x80184084u;
    ctx->downcount -= 2;
    // 80184084: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184088:
    ctx->pc = 0x80184088u;
    // 80184088: stw     r0, -26552(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26552);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018408C:
    ctx->pc = 0x8018408Cu;
    ctx->downcount -= 6;
    // 8018408C: or   r0, r3, r4
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[4];
    }

label_80184090:
    ctx->pc = 0x80184090u;
    // 80184090: lis     r31, -13312
    ctx->gpr[31] = ((u32)(s32)(-13312) << 16);

label_80184094:
    ctx->pc = 0x80184094u;
    // 80184094: stw     r0, 24576(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184098:
    ctx->pc = 0x80184098u;
    // 80184098: lwz     r0, -26552(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26552);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018409C:
    ctx->pc = 0x8018409Cu;
    // 8018409C: cmplwi  r0, 0x0000
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

label_801840A0:
    ctx->pc = 0x801840A0u;
    // 801840A0: bc    12, 2, 0x8018413C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018413C;
        }
    }

label_801840A4:
    ctx->pc = 0x801840A4u;
    ctx->downcount -= 1;
    // 801840A4: bl      0x8017A0AC
    {
            ctx->lr = 0x801840A8u;
            ctx->pc = 0x8017A0ACu;
            return;
    }

label_801840A8:
    ctx->pc = 0x801840A8u;
    ctx->downcount -= 26;
    // 801840A8: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_801840AC:
    ctx->pc = 0x801840ACu;
    // 801840AC: lwz     r7, -26560(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26560);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801840B0:
    ctx->pc = 0x801840B0u;
    // 801840B0: lwz     r6, 248(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(248);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801840B4:
    ctx->pc = 0x801840B4u;
    // 801840B4: lis     r5, 4194
    ctx->gpr[5] = ((u32)(s32)(4194) << 16);

label_801840B8:
    ctx->pc = 0x801840B8u;
    // 801840B8: addi    r5, r5, 19923
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(19923);

label_801840BC:
    ctx->pc = 0x801840BCu;
    // 801840BC: lwz     r8, -26556(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26556);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801840C0:
    ctx->pc = 0x801840C0u;
    // 801840C0: rlwinm r6, r6, 30, 2, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 30u) & 0x3FFFFFFFu;
    }

label_801840C4:
    ctx->pc = 0x801840C4u;
    // 801840C4: mulhwu   r5, r5, r6
    {
        u64 product = (u64)ctx->gpr[5] * (u64)ctx->gpr[6];
        ctx->gpr[5] = (u32)(product >> 32);
    }

label_801840C8:
    ctx->pc = 0x801840C8u;
    // 801840C8: rlwinm r5, r5, 26, 6, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 26u) & 0x03FFFFFFu;
    }

label_801840CC:
    ctx->pc = 0x801840CCu;
    // 801840CC: mulli   r5, r5, 200
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[5] * (s64)(s32)200);

label_801840D0:
    ctx->pc = 0x801840D0u;
    // 801840D0: subfc   r6, r8, r4
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[6] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801840D4:
    ctx->pc = 0x801840D4u;
    // 801840D4: subfe   r3, r7, r3
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801840D8:
    ctx->pc = 0x801840D8u;
    // 801840D8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801840DC:
    ctx->pc = 0x801840DCu;
    // 801840DC: xoris   r4, r3, 0x8000
    ctx->gpr[4] = ctx->gpr[3] ^ (0x8000u << 16);

label_801840E0:
    ctx->pc = 0x801840E0u;
    // 801840E0: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_801840E4:
    ctx->pc = 0x801840E4u;
    // 801840E4: subfc   r0, r5, r6
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[6];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801840E8:
    ctx->pc = 0x801840E8u;
    // 801840E8: subfe   r3, r3, r4
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801840EC:
    ctx->pc = 0x801840ECu;
    // 801840EC: subfe   r3, r4, r4
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801840F0:
    ctx->pc = 0x801840F0u;
    // 801840F0: neg.  r3, r3
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

label_801840F4:
    ctx->pc = 0x801840F4u;
    // 801840F4: bc    12, 2, 0x8018413C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018413C;
        }
    }

label_801840F8:
    ctx->pc = 0x801840F8u;
    ctx->downcount -= 6;
    // 801840F8: lwzu     r0, 24580(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24580);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[31] = ea;
    }

label_801840FC:
    ctx->pc = 0x801840FCu;
    // 801840FC: rlwinm r3, r0, 0, 29, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000004u;
    }

label_80184100:
    ctx->pc = 0x80184100u;
    // 80184100: rlwinm r0, r0, 1, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000004u;
    }

label_80184104:
    ctx->pc = 0x80184104u;
    // 80184104: and   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[0];
    }

label_80184108:
    ctx->pc = 0x80184108u;
    // 80184108: rlwinm. r0, r0, 0, 29, 29
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

label_8018410C:
    ctx->pc = 0x8018410Cu;
    // 8018410C: bc    12, 2, 0x80184130
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184130;
        }
    }

label_80184110:
    ctx->pc = 0x80184110u;
    ctx->downcount -= 3;
    // 80184110: lwz     r12, -26564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26564);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80184114:
    ctx->pc = 0x80184114u;
    // 80184114: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80184118:
    ctx->pc = 0x80184118u;
    // 80184118: bc    12, 2, 0x80184128
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184128;
        }
    }

label_8018411C:
    ctx->pc = 0x8018411Cu;
    ctx->downcount -= 4;
    // 8018411C: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_80184120:
    ctx->pc = 0x80184120u;
    // 80184120: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80184124:
    ctx->pc = 0x80184124u;
    // 80184124: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80184128u;
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184128:
    ctx->pc = 0x80184128u;
    ctx->downcount -= 2;
    // 80184128: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018412C:
    ctx->pc = 0x8018412Cu;
    // 8018412C: stw     r0, -26564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26564);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184130:
    ctx->pc = 0x80184130u;
    ctx->downcount -= 3;
    // 80184130: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184134:
    ctx->pc = 0x80184134u;
    // 80184134: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184138:
    ctx->pc = 0x80184138u;
    // 80184138: b       0x80184190
    {
            goto label_80184190;
    }

label_8018413C:
    ctx->pc = 0x8018413Cu;
    ctx->downcount -= 3;
    // 8018413C: lwz     r0, -26548(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26548);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184140:
    ctx->pc = 0x80184140u;
    // 80184140: cmpwi   r0, 0
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

label_80184144:
    ctx->pc = 0x80184144u;
    // 80184144: bc    12, 2, 0x80184184
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184184;
        }
    }

label_80184148:
    ctx->pc = 0x80184148u;
    ctx->downcount -= 9;
    // 80184148: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018414C:
    ctx->pc = 0x8018414Cu;
    // 8018414C: addi    r5, r3, 24576
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(24576);

label_80184150:
    ctx->pc = 0x80184150u;
    // 80184150: lwzu     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[5] = ea;
    }

label_80184154:
    ctx->pc = 0x80184154u;
    // 80184154: rlwinm r4, r0, 0, 30, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
    }

label_80184158:
    ctx->pc = 0x80184158u;
    // 80184158: rlwinm r3, r0, 0, 29, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000004u;
    }

label_8018415C:
    ctx->pc = 0x8018415Cu;
    // 8018415C: rlwinm r0, r0, 1, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000004u;
    }

label_80184160:
    ctx->pc = 0x80184160u;
    // 80184160: and   r3, r3, r0
    {
        ctx->gpr[3] = ctx->gpr[3] & ctx->gpr[0];
    }

label_80184164:
    ctx->pc = 0x80184164u;
    // 80184164: rlwinm. r0, r3, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80184168:
    ctx->pc = 0x80184168u;
    // 80184168: bc    12, 2, 0x80184170
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184170;
        }
    }

label_8018416C:
    ctx->pc = 0x8018416Cu;
    ctx->downcount -= 1;
    // 8018416C: ori     r29, r29, 0x0004
    ctx->gpr[29] = ctx->gpr[29] | 0x0004u;

label_80184170:
    ctx->pc = 0x80184170u;
    ctx->downcount -= 5;
    // 80184170: or   r0, r3, r4
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[4];
    }

label_80184174:
    ctx->pc = 0x80184174u;
    // 80184174: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184178:
    ctx->pc = 0x80184178u;
    // 80184178: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018417C:
    ctx->pc = 0x8018417Cu;
    // 8018417C: stw     r0, -26548(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26548);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184180:
    ctx->pc = 0x80184180u;
    // 80184180: b       0x80184190
    {
            goto label_80184190;
    }

label_80184184:
    ctx->pc = 0x80184184u;
    ctx->downcount -= 3;
    // 80184184: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80184188:
    ctx->pc = 0x80184188u;
    // 80184188: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018418C:
    ctx->pc = 0x8018418Cu;
    // 8018418C: stw     r0, 24580(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24580);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184190:
    ctx->pc = 0x80184190u;
    ctx->downcount -= 2;
    // 80184190: rlwinm. r0, r29, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80184194:
    ctx->pc = 0x80184194u;
    // 80184194: bc    12, 2, 0x801841A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801841A8;
        }
    }

label_80184198:
    ctx->pc = 0x80184198u;
    ctx->downcount -= 3;
    // 80184198: lwz     r0, -26544(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26544);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018419C:
    ctx->pc = 0x8018419Cu;
    // 8018419C: cmpwi   r0, 0
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

label_801841A0:
    ctx->pc = 0x801841A0u;
    // 801841A0: bc    4, 2, 0x801841A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801841A8;
        }
    }

label_801841A4:
    ctx->pc = 0x801841A4u;
    ctx->downcount -= 1;
    // 801841A4: rlwinm r29, r29, 0, 29, 27
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0xFFFFFFF7u;
    }

label_801841A8:
    ctx->pc = 0x801841A8u;
    ctx->downcount -= 2;
    // 801841A8: rlwinm. r0, r29, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801841AC:
    ctx->pc = 0x801841ACu;
    // 801841AC: bc    12, 2, 0x8018422C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018422C;
        }
    }

label_801841B0:
    ctx->pc = 0x801841B0u;
    ctx->downcount -= 7;
    // 801841B0: lwz     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801841B4:
    ctx->pc = 0x801841B4u;
    // 801841B4: mulli   r0, r0, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_801841B8:
    ctx->pc = 0x801841B8u;
    // 801841B8: lwzx    r3, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801841BC:
    ctx->pc = 0x801841BCu;
    // 801841BC: cmpwi   r3, 1
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

label_801841C0:
    ctx->pc = 0x801841C0u;
    // 801841C0: bc    4, 2, 0x801841F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801841F0;
        }
    }

label_801841C4:
    ctx->pc = 0x801841C4u;
    ctx->downcount -= 9;
    // 801841C4: lwz     r3, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801841C8:
    ctx->pc = 0x801841C8u;
    // 801841C8: add   r6, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_801841CC:
    ctx->pc = 0x801841CCu;
    // 801841CC: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_801841D0:
    ctx->pc = 0x801841D0u;
    // 801841D0: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801841D4:
    ctx->pc = 0x801841D4u;
    // 801841D4: lwz     r3, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801841D8:
    ctx->pc = 0x801841D8u;
    // 801841D8: lwz     r4, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801841DC:
    ctx->pc = 0x801841DCu;
    // 801841DC: lwz     r5, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801841E0:
    ctx->pc = 0x801841E0u;
    // 801841E0: lwz     r6, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801841E4:
    ctx->pc = 0x801841E4u;
    // 801841E4: bl      0x80184404
    {
            ctx->lr = 0x801841E8u;
            goto label_80184404;
    }

label_801841E8:
    ctx->pc = 0x801841E8u;
    ctx->downcount -= 2;
    // 801841E8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801841EC:
    ctx->pc = 0x801841ECu;
    // 801841EC: b       0x80184220
    {
            goto label_80184220;
    }

label_801841F0:
    ctx->pc = 0x801841F0u;
    ctx->downcount -= 2;
    // 801841F0: cmpwi   r3, 2
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

label_801841F4:
    ctx->pc = 0x801841F4u;
    // 801841F4: bc    4, 2, 0x8018421C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018421C;
        }
    }

label_801841F8:
    ctx->pc = 0x801841F8u;
    ctx->downcount -= 7;
    // 801841F8: lwz     r3, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801841FC:
    ctx->pc = 0x801841FCu;
    // 801841FC: add   r4, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80184200:
    ctx->pc = 0x80184200u;
    // 80184200: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_80184204:
    ctx->pc = 0x80184204u;
    // 80184204: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184208:
    ctx->pc = 0x80184208u;
    // 80184208: lwz     r3, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018420C:
    ctx->pc = 0x8018420Cu;
    // 8018420C: lwz     r4, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80184210:
    ctx->pc = 0x80184210u;
    // 80184210: bl      0x801849C4
    {
            ctx->lr = 0x80184214u;
            goto label_801849C4;
    }

label_80184214:
    ctx->pc = 0x80184214u;
    ctx->downcount -= 2;
    // 80184214: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184218:
    ctx->pc = 0x80184218u;
    // 80184218: b       0x80184220
    {
            goto label_80184220;
    }

label_8018421C:
    ctx->pc = 0x8018421Cu;
    ctx->downcount -= 1;
    // 8018421C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184220:
    ctx->pc = 0x80184220u;
    ctx->downcount -= 2;
    // 80184220: cmpwi   r0, 0
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

label_80184224:
    ctx->pc = 0x80184224u;
    // 80184224: bc    12, 2, 0x8018423C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018423C;
        }
    }

label_80184228:
    ctx->pc = 0x80184228u;
    ctx->downcount -= 1;
    // 80184228: b       0x8018428C
    {
            goto label_8018428C;
    }

label_8018422C:
    ctx->pc = 0x8018422Cu;
    ctx->downcount -= 4;
    // 8018422C: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80184230:
    ctx->pc = 0x80184230u;
    // 80184230: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184234:
    ctx->pc = 0x80184234u;
    // 80184234: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184238:
    ctx->pc = 0x80184238u;
    // 80184238: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018423C:
    ctx->pc = 0x8018423Cu;
    ctx->downcount -= 2;
    // 8018423C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80184240:
    ctx->pc = 0x80184240u;
    // 80184240: bl      0x8017248C
    {
            ctx->lr = 0x80184244u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_80184244:
    ctx->pc = 0x80184244u;
    ctx->downcount -= 2;
    // 80184244: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80184248:
    ctx->pc = 0x80184248u;
    // 80184248: bl      0x80172284
    {
            ctx->lr = 0x8018424Cu;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018424C:
    ctx->pc = 0x8018424Cu;
    ctx->downcount -= 2;
    // 8018424C: cmplwi  r29, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80184250:
    ctx->pc = 0x80184250u;
    // 80184250: bc    12, 2, 0x8018427C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018427C;
        }
    }

label_80184254:
    ctx->pc = 0x80184254u;
    ctx->downcount -= 5;
    // 80184254: lwz     r12, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80184258:
    ctx->pc = 0x80184258u;
    // 80184258: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018425C:
    ctx->pc = 0x8018425Cu;
    // 8018425C: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80184260:
    ctx->pc = 0x80184260u;
    // 80184260: stw     r0, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184264:
    ctx->pc = 0x80184264u;
    // 80184264: bc    12, 2, 0x80184274
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184274;
        }
    }

label_80184268:
    ctx->pc = 0x80184268u;
    ctx->downcount -= 4;
    // 80184268: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_8018426C:
    ctx->pc = 0x8018426Cu;
    // 8018426C: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_80184270:
    ctx->pc = 0x80184270u;
    // 80184270: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80184274u;
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184274:
    ctx->pc = 0x80184274u;
    ctx->downcount -= 2;
    // 80184274: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184278:
    ctx->pc = 0x80184278u;
    // 80184278: stw     r0, -26544(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26544);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018427C:
    ctx->pc = 0x8018427Cu;
    ctx->downcount -= 2;
    // 8018427C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80184280:
    ctx->pc = 0x80184280u;
    // 80184280: bl      0x8017248C
    {
            ctx->lr = 0x80184284u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_80184284:
    ctx->pc = 0x80184284u;
    ctx->downcount -= 2;
    // 80184284: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80184288:
    ctx->pc = 0x80184288u;
    // 80184288: bl      0x80172284
    {
            ctx->lr = 0x8018428Cu;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018428C:
    ctx->pc = 0x8018428Cu;
    ctx->downcount -= 9;
    // 8018428C: lwz     r0, 748(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(748);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184290:
    ctx->pc = 0x80184290u;
    // 80184290: lwz     r31, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184294:
    ctx->pc = 0x80184294u;
    // 80184294: lwz     r30, 736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(736);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184298:
    ctx->pc = 0x80184298u;
    // 80184298: lwz     r29, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018429C:
    ctx->pc = 0x8018429Cu;
    // 8018429C: lwz     r28, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_801842A0:
    ctx->pc = 0x801842A0u;
    // 801842A0: addi    r1, r1, 744
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(744);

label_801842A4:
    ctx->pc = 0x801842A4u;
    // 801842A4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801842A8:
    ctx->pc = 0x801842A8u;
    // 801842A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801842AC:
    ctx->pc = 0x801842ACu;
    ctx->downcount -= 12;
    // 801842AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801842B0:
    ctx->pc = 0x801842B0u;
    // 801842B0: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_801842B4:
    ctx->pc = 0x801842B4u;
    // 801842B4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801842B8:
    ctx->pc = 0x801842B8u;
    // 801842B8: addi    r4, r3, 2152
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(2152);

label_801842BC:
    ctx->pc = 0x801842BCu;
    // 801842BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801842C0:
    ctx->pc = 0x801842C0u;
    // 801842C0: lwz     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801842C4:
    ctx->pc = 0x801842C4u;
    // 801842C4: mulli   r0, r0, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_801842C8:
    ctx->pc = 0x801842C8u;
    // 801842C8: lwzx    r3, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801842CC:
    ctx->pc = 0x801842CCu;
    // 801842CC: cmpwi   r3, 1
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

label_801842D0:
    ctx->pc = 0x801842D0u;
    // 801842D0: bc    4, 2, 0x801842FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801842FC;
        }
    }

label_801842D4:
    ctx->pc = 0x801842D4u;
    ctx->downcount -= 9;
    // 801842D4: lwz     r3, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801842D8:
    ctx->pc = 0x801842D8u;
    // 801842D8: add   r6, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_801842DC:
    ctx->pc = 0x801842DCu;
    // 801842DC: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_801842E0:
    ctx->pc = 0x801842E0u;
    // 801842E0: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801842E4:
    ctx->pc = 0x801842E4u;
    // 801842E4: lwz     r3, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801842E8:
    ctx->pc = 0x801842E8u;
    // 801842E8: lwz     r4, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801842EC:
    ctx->pc = 0x801842ECu;
    // 801842EC: lwz     r5, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801842F0:
    ctx->pc = 0x801842F0u;
    // 801842F0: lwz     r6, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801842F4:
    ctx->pc = 0x801842F4u;
    // 801842F4: bl      0x80184404
    {
            ctx->lr = 0x801842F8u;
            goto label_80184404;
    }

label_801842F8:
    ctx->pc = 0x801842F8u;
    ctx->downcount -= 1;
    // 801842F8: b       0x80184320
    {
            goto label_80184320;
    }

label_801842FC:
    ctx->pc = 0x801842FCu;
    ctx->downcount -= 2;
    // 801842FC: cmpwi   r3, 2
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

label_80184300:
    ctx->pc = 0x80184300u;
    // 80184300: bc    4, 2, 0x80184320
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80184320;
        }
    }

label_80184304:
    ctx->pc = 0x80184304u;
    ctx->downcount -= 7;
    // 80184304: lwz     r3, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80184308:
    ctx->pc = 0x80184308u;
    // 80184308: add   r4, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8018430C:
    ctx->pc = 0x8018430Cu;
    // 8018430C: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_80184310:
    ctx->pc = 0x80184310u;
    // 80184310: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184314:
    ctx->pc = 0x80184314u;
    // 80184314: lwz     r3, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80184318:
    ctx->pc = 0x80184318u;
    // 80184318: lwz     r4, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018431C:
    ctx->pc = 0x8018431Cu;
    // 8018431C: bl      0x801849C4
    {
            ctx->lr = 0x80184320u;
            goto label_801849C4;
    }

label_80184320:
    ctx->pc = 0x80184320u;
    ctx->downcount -= 5;
    // 80184320: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184324:
    ctx->pc = 0x80184324u;
    // 80184324: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80184328:
    ctx->pc = 0x80184328u;
    // 80184328: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018432C:
    ctx->pc = 0x8018432Cu;
    // 8018432C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184330:
    ctx->pc = 0x80184330u;
    ctx->downcount -= 7;
    // 80184330: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184334:
    ctx->pc = 0x80184334u;
    // 80184334: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_80184338:
    ctx->pc = 0x80184338u;
    // 80184338: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018433C:
    ctx->pc = 0x8018433Cu;
    // 8018433C: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184340:
    ctx->pc = 0x80184340u;
    // 80184340: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184344:
    ctx->pc = 0x80184344u;
    // 80184344: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80184348:
    ctx->pc = 0x80184348u;
    // 80184348: bl      0x80174390
    {
            ctx->lr = 0x8018434Cu;
            ctx->pc = 0x80174390u;
            return;
    }

label_8018434C:
    ctx->pc = 0x8018434Cu;
    ctx->downcount -= 2;
    // 8018434C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80184350:
    ctx->pc = 0x80184350u;
    // 80184350: bl      0x8017248C
    {
            ctx->lr = 0x80184354u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_80184354:
    ctx->pc = 0x80184354u;
    ctx->downcount -= 2;
    // 80184354: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80184358:
    ctx->pc = 0x80184358u;
    // 80184358: bl      0x80172284
    {
            ctx->lr = 0x8018435Cu;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018435C:
    ctx->pc = 0x8018435Cu;
    ctx->downcount -= 5;
    // 8018435C: lwz     r12, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80184360:
    ctx->pc = 0x80184360u;
    // 80184360: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184364:
    ctx->pc = 0x80184364u;
    // 80184364: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80184368:
    ctx->pc = 0x80184368u;
    // 80184368: stw     r0, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018436C:
    ctx->pc = 0x8018436Cu;
    // 8018436C: bc    12, 2, 0x8018437C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018437C;
        }
    }

label_80184370:
    ctx->pc = 0x80184370u;
    ctx->downcount -= 4;
    // 80184370: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_80184374:
    ctx->pc = 0x80184374u;
    // 80184374: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80184378:
    ctx->pc = 0x80184378u;
    // 80184378: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8018437Cu;
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018437C:
    ctx->pc = 0x8018437Cu;
    ctx->downcount -= 2;
    // 8018437C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80184380:
    ctx->pc = 0x80184380u;
    // 80184380: bl      0x8017248C
    {
            ctx->lr = 0x80184384u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_80184384:
    ctx->pc = 0x80184384u;
    ctx->downcount -= 2;
    // 80184384: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80184388:
    ctx->pc = 0x80184388u;
    // 80184388: bl      0x80172284
    {
            ctx->lr = 0x8018438Cu;
            ctx->pc = 0x80172284u;
            return;
    }

label_8018438C:
    ctx->pc = 0x8018438Cu;
    ctx->downcount -= 6;
    // 8018438C: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184390:
    ctx->pc = 0x80184390u;
    // 80184390: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184394:
    ctx->pc = 0x80184394u;
    // 80184394: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_80184398:
    ctx->pc = 0x80184398u;
    // 80184398: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018439C:
    ctx->pc = 0x8018439Cu;
    // 8018439C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801843A0:
    ctx->pc = 0x801843A0u;
    ctx->downcount -= 12;
    // 801843A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801843A4:
    ctx->pc = 0x801843A4u;
    // 801843A4: lis     r5, -32697
    ctx->gpr[5] = ((u32)(s32)(-32697) << 16);

label_801843A8:
    ctx->pc = 0x801843A8u;
    // 801843A8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801843AC:
    ctx->pc = 0x801843ACu;
    // 801843AC: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801843B0:
    ctx->pc = 0x801843B0u;
    // 801843B0: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801843B4:
    ctx->pc = 0x801843B4u;
    // 801843B4: addi    r31, r5, 2256
    ctx->gpr[31] = ctx->gpr[5] + (u32)(s32)(2256);

label_801843B8:
    ctx->pc = 0x801843B8u;
    // 801843B8: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801843BC:
    ctx->pc = 0x801843BCu;
    // 801843BC: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_801843C0:
    ctx->pc = 0x801843C0u;
    // 801843C0: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801843C4:
    ctx->pc = 0x801843C4u;
    // 801843C4: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801843C8:
    ctx->pc = 0x801843C8u;
    // 801843C8: addi    r29, r4, 0
    ctx->gpr[29] = ctx->gpr[4] + (u32)(s32)(0);

label_801843CC:
    ctx->pc = 0x801843CCu;
    // 801843CC: bl      0x8016FEEC
    {
            ctx->lr = 0x801843D0u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_801843D0:
    ctx->pc = 0x801843D0u;
    ctx->downcount -= 6;
    // 801843D0: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_801843D4:
    ctx->pc = 0x801843D4u;
    // 801843D4: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_801843D8:
    ctx->pc = 0x801843D8u;
    // 801843D8: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801843DC:
    ctx->pc = 0x801843DCu;
    // 801843DC: addi    r6, r29, 0
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(0);

label_801843E0:
    ctx->pc = 0x801843E0u;
    // 801843E0: addi    r5, r30, 0
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(0);

label_801843E4:
    ctx->pc = 0x801843E4u;
    // 801843E4: bl      0x80170148
    {
            ctx->lr = 0x801843E8u;
            ctx->pc = 0x80170148u;
            return;
    }

label_801843E8:
    ctx->pc = 0x801843E8u;
    ctx->downcount -= 8;
    // 801843E8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801843EC:
    ctx->pc = 0x801843ECu;
    // 801843EC: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801843F0:
    ctx->pc = 0x801843F0u;
    // 801843F0: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801843F4:
    ctx->pc = 0x801843F4u;
    // 801843F4: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801843F8:
    ctx->pc = 0x801843F8u;
    // 801843F8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801843FC:
    ctx->pc = 0x801843FCu;
    // 801843FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184400:
    ctx->pc = 0x80184400u;
    // 80184400: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184404:
    ctx->pc = 0x80184404u;
    ctx->downcount -= 18;
    // 80184404: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184408:
    ctx->pc = 0x80184408u;
    // 80184408: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018440C:
    ctx->pc = 0x8018440Cu;
    // 8018440C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184410:
    ctx->pc = 0x80184410u;
    // 80184410: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184414:
    ctx->pc = 0x80184414u;
    // 80184414: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184418:
    ctx->pc = 0x80184418u;
    // 80184418: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018441C:
    ctx->pc = 0x8018441Cu;
    // 8018441C: addi    r30, r5, 0
    ctx->gpr[30] = ctx->gpr[5] + (u32)(s32)(0);

label_80184420:
    ctx->pc = 0x80184420u;
    // 80184420: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80184424:
    ctx->pc = 0x80184424u;
    // 80184424: addi    r29, r4, 0
    ctx->gpr[29] = ctx->gpr[4] + (u32)(s32)(0);

label_80184428:
    ctx->pc = 0x80184428u;
    // 80184428: stw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8018442C:
    ctx->pc = 0x8018442Cu;
    // 8018442C: addi    r28, r3, 0
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(0);

label_80184430:
    ctx->pc = 0x80184430u;
    // 80184430: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184434:
    ctx->pc = 0x80184434u;
    // 80184434: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184438:
    ctx->pc = 0x80184438u;
    // 80184438: stw     r6, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8018443C:
    ctx->pc = 0x8018443Cu;
    // 8018443C: lis     r6, -32697
    ctx->gpr[6] = ((u32)(s32)(-32697) << 16);

label_80184440:
    ctx->pc = 0x80184440u;
    // 80184440: addi    r31, r6, 2152
    ctx->gpr[31] = ctx->gpr[6] + (u32)(s32)(2152);

label_80184444:
    ctx->pc = 0x80184444u;
    // 80184444: stw     r0, -26512(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26512);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184448:
    ctx->pc = 0x80184448u;
    // 80184448: bl      0x8017A0AC
    {
            ctx->lr = 0x8018444Cu;
            ctx->pc = 0x8017A0ACu;
            return;
    }

label_8018444C:
    ctx->pc = 0x8018444Cu;
    ctx->downcount -= 17;
    // 8018444C: stw     r4, -26516(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26516);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184450:
    ctx->pc = 0x80184450u;
    // 80184450: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_80184454:
    ctx->pc = 0x80184454u;
    // 80184454: lis     r0, 160
    ctx->gpr[0] = ((u32)(s32)(160) << 16);

label_80184458:
    ctx->pc = 0x80184458u;
    // 80184458: stw     r3, -26520(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26520);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8018445C:
    ctx->pc = 0x8018445Cu;
    // 8018445C: addi    r4, r4, 24576
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(24576);

label_80184460:
    ctx->pc = 0x80184460u;
    // 80184460: lis     r3, -22528
    ctx->gpr[3] = ((u32)(s32)(-22528) << 16);

label_80184464:
    ctx->pc = 0x80184464u;
    // 80184464: stw     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184468:
    ctx->pc = 0x80184468u;
    // 80184468: rlwinm r3, r30, 30, 2, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[30], 30u) & 0x3FFFFFFFu;
    }

label_8018446C:
    ctx->pc = 0x8018446Cu;
    // 8018446C: cmplw   r29, r0
    {
        u32 val_a = (u32)(ctx->gpr[29]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80184470:
    ctx->pc = 0x80184470u;
    // 80184470: stw     r3, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184474:
    ctx->pc = 0x80184474u;
    // 80184474: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80184478:
    ctx->pc = 0x80184478u;
    // 80184478: stw     r29, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8018447C:
    ctx->pc = 0x8018447Cu;
    // 8018447C: stw     r28, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80184480:
    ctx->pc = 0x80184480u;
    // 80184480: stw     r29, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80184484:
    ctx->pc = 0x80184484u;
    // 80184484: stw     r29, -26572(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26572);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80184488:
    ctx->pc = 0x80184488u;
    // 80184488: stw     r0, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018448C:
    ctx->pc = 0x8018448Cu;
    // 8018448C: bc    4, 1, 0x801844C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801844C4;
        }
    }

label_80184490:
    ctx->pc = 0x80184490u;
    ctx->downcount -= 8;
    // 80184490: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80184494:
    ctx->pc = 0x80184494u;
    // 80184494: lwz     r0, 248(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184498:
    ctx->pc = 0x80184498u;
    // 80184498: addi    r3, r31, 104
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(104);

label_8018449C:
    ctx->pc = 0x8018449Cu;
    // 8018449C: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_801844A0:
    ctx->pc = 0x801844A0u;
    // 801844A0: mulli   r30, r0, 20
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_801844A4:
    ctx->pc = 0x801844A4u;
    // 801844A4: bl      0x8016FEEC
    {
            ctx->lr = 0x801844A8u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_801844A8:
    ctx->pc = 0x801844A8u;
    ctx->downcount -= 6;
    // 801844A8: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_801844AC:
    ctx->pc = 0x801844ACu;
    // 801844AC: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_801844B0:
    ctx->pc = 0x801844B0u;
    // 801844B0: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_801844B4:
    ctx->pc = 0x801844B4u;
    // 801844B4: addi    r3, r31, 104
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(104);

label_801844B8:
    ctx->pc = 0x801844B8u;
    // 801844B8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801844BC:
    ctx->pc = 0x801844BCu;
    // 801844BC: bl      0x80170148
    {
            ctx->lr = 0x801844C0u;
            ctx->pc = 0x80170148u;
            return;
    }

label_801844C0:
    ctx->pc = 0x801844C0u;
    ctx->downcount -= 1;
    // 801844C0: b       0x801844F4
    {
            goto label_801844F4;
    }

label_801844C4:
    ctx->pc = 0x801844C4u;
    ctx->downcount -= 8;
    // 801844C4: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_801844C8:
    ctx->pc = 0x801844C8u;
    // 801844C8: lwz     r0, 248(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801844CC:
    ctx->pc = 0x801844CCu;
    // 801844CC: addi    r3, r31, 104
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(104);

label_801844D0:
    ctx->pc = 0x801844D0u;
    // 801844D0: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_801844D4:
    ctx->pc = 0x801844D4u;
    // 801844D4: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_801844D8:
    ctx->pc = 0x801844D8u;
    // 801844D8: bl      0x8016FEEC
    {
            ctx->lr = 0x801844DCu;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_801844DC:
    ctx->pc = 0x801844DCu;
    ctx->downcount -= 6;
    // 801844DC: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_801844E0:
    ctx->pc = 0x801844E0u;
    // 801844E0: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_801844E4:
    ctx->pc = 0x801844E4u;
    // 801844E4: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_801844E8:
    ctx->pc = 0x801844E8u;
    // 801844E8: addi    r3, r31, 104
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(104);

label_801844EC:
    ctx->pc = 0x801844ECu;
    // 801844EC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801844F0:
    ctx->pc = 0x801844F0u;
    // 801844F0: bl      0x80170148
    {
            ctx->lr = 0x801844F4u;
            ctx->pc = 0x80170148u;
            return;
    }

label_801844F4:
    ctx->pc = 0x801844F4u;
    ctx->downcount -= 9;
    // 801844F4: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801844F8:
    ctx->pc = 0x801844F8u;
    // 801844F8: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801844FC:
    ctx->pc = 0x801844FCu;
    // 801844FC: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184500:
    ctx->pc = 0x80184500u;
    // 80184500: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80184504:
    ctx->pc = 0x80184504u;
    // 80184504: lwz     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80184508:
    ctx->pc = 0x80184508u;
    // 80184508: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8018450C:
    ctx->pc = 0x8018450Cu;
    // 8018450C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184510:
    ctx->pc = 0x80184510u;
    // 80184510: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184514:
    ctx->pc = 0x80184514u;
    ctx->downcount -= 4;
    // 80184514: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184518:
    ctx->pc = 0x80184518u;
    // 80184518: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018451C:
    ctx->pc = 0x8018451Cu;
    // 8018451C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184520:
    ctx->pc = 0x80184520u;
    // 80184520: bl      0x80183370
    {
            ctx->lr = 0x80184524u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80183370u;
                return;
            }
            goto label_80183370;
    }

label_80184524:
    ctx->pc = 0x80184524u;
    ctx->downcount -= 3;
    // 80184524: lbz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80184528:
    ctx->pc = 0x80184528u;
    // 80184528: cmplwi  r0, 0x0000
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

label_8018452C:
    ctx->pc = 0x8018452Cu;
    // 8018452C: bc    12, 2, 0x80184538
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184538;
        }
    }

label_80184530:
    ctx->pc = 0x80184530u;
    ctx->downcount -= 2;
    // 80184530: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184534:
    ctx->pc = 0x80184534u;
    // 80184534: b       0x8018453C
    {
            goto label_8018453C;
    }

label_80184538:
    ctx->pc = 0x80184538u;
    ctx->downcount -= 1;
    // 80184538: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018453C:
    ctx->pc = 0x8018453Cu;
    ctx->downcount -= 5;
    // 8018453C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184540:
    ctx->pc = 0x80184540u;
    // 80184540: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80184544:
    ctx->pc = 0x80184544u;
    // 80184544: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184548:
    ctx->pc = 0x80184548u;
    // 80184548: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018454C:
    ctx->pc = 0x8018454Cu;
    ctx->downcount -= 13;
    // 8018454C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184550:
    ctx->pc = 0x80184550u;
    // 80184550: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184554:
    ctx->pc = 0x80184554u;
    // 80184554: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184558:
    ctx->pc = 0x80184558u;
    // 80184558: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018455C:
    ctx->pc = 0x8018455Cu;
    // 8018455C: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184560:
    ctx->pc = 0x80184560u;
    // 80184560: lwz     r5, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80184564:
    ctx->pc = 0x80184564u;
    // 80184564: lwz     r6, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80184568:
    ctx->pc = 0x80184568u;
    // 80184568: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018456C:
    ctx->pc = 0x8018456Cu;
    // 8018456C: addi    r4, r5, -1
    ctx->gpr[4] = ctx->gpr[5] + (u32)(s32)(-1);

label_80184570:
    ctx->pc = 0x80184570u;
    // 80184570: add   r3, r6, r4
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80184574:
    ctx->pc = 0x80184574u;
    // 80184574: rlwinm r31, r3, 17, 15, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[3], 17u) & 0x0001FFFFu;
    }

label_80184578:
    ctx->pc = 0x80184578u;
    // 80184578: rlwinm r30, r0, 17, 15, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x0001FFFFu;
    }

label_8018457C:
    ctx->pc = 0x8018457Cu;
    // 8018457C: bl      0x80183370
    {
            ctx->lr = 0x80184580u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80183370u;
                return;
            }
            goto label_80183370;
    }

label_80184580:
    ctx->pc = 0x80184580u;
    ctx->downcount -= 3;
    // 80184580: lbz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80184584:
    ctx->pc = 0x80184584u;
    // 80184584: cmplwi  r0, 0x0000
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

label_80184588:
    ctx->pc = 0x80184588u;
    // 80184588: bc    12, 2, 0x80184594
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184594;
        }
    }

label_8018458C:
    ctx->pc = 0x8018458Cu;
    ctx->downcount -= 2;
    // 8018458C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184590:
    ctx->pc = 0x80184590u;
    // 80184590: b       0x80184598
    {
            goto label_80184598;
    }

label_80184594:
    ctx->pc = 0x80184594u;
    ctx->downcount -= 1;
    // 80184594: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184598:
    ctx->pc = 0x80184598u;
    ctx->downcount -= 2;
    // 80184598: cmpwi   r0, 0
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

label_8018459C:
    ctx->pc = 0x8018459Cu;
    // 8018459C: bc    12, 2, 0x801845A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801845A8;
        }
    }

label_801845A0:
    ctx->pc = 0x801845A0u;
    ctx->downcount -= 2;
    // 801845A0: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_801845A4:
    ctx->pc = 0x801845A4u;
    // 801845A4: b       0x801845AC
    {
            goto label_801845AC;
    }

label_801845A8:
    ctx->pc = 0x801845A8u;
    ctx->downcount -= 1;
    // 801845A8: li      r3, 15
    ctx->gpr[3] = (u32)(s32)(15);

label_801845AC:
    ctx->pc = 0x801845ACu;
    ctx->downcount -= 3;
    // 801845AC: addi    r0, r31, -2
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-2);

label_801845B0:
    ctx->pc = 0x801845B0u;
    // 801845B0: cmplw   r30, r0
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801845B4:
    ctx->pc = 0x801845B4u;
    // 801845B4: bc    12, 1, 0x801845C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801845C8;
        }
    }

label_801845B8:
    ctx->pc = 0x801845B8u;
    ctx->downcount -= 4;
    // 801845B8: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_801845BC:
    ctx->pc = 0x801845BCu;
    // 801845BC: add   r0, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801845C0:
    ctx->pc = 0x801845C0u;
    // 801845C0: cmplw   r30, r0
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801845C4:
    ctx->pc = 0x801845C4u;
    // 801845C4: bc    4, 0, 0x801845D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801845D0;
        }
    }

label_801845C8:
    ctx->pc = 0x801845C8u;
    ctx->downcount -= 2;
    // 801845C8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801845CC:
    ctx->pc = 0x801845CCu;
    // 801845CC: b       0x801845D4
    {
            goto label_801845D4;
    }

label_801845D0:
    ctx->pc = 0x801845D0u;
    ctx->downcount -= 1;
    // 801845D0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801845D4:
    ctx->pc = 0x801845D4u;
    ctx->downcount -= 7;
    // 801845D4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801845D8:
    ctx->pc = 0x801845D8u;
    // 801845D8: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801845DC:
    ctx->pc = 0x801845DCu;
    // 801845DC: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801845E0:
    ctx->pc = 0x801845E0u;
    // 801845E0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801845E4:
    ctx->pc = 0x801845E4u;
    // 801845E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801845E8:
    ctx->pc = 0x801845E8u;
    // 801845E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801845EC:
    ctx->pc = 0x801845ECu;
    ctx->downcount -= 9;
    // 801845EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801845F0:
    ctx->pc = 0x801845F0u;
    // 801845F0: lis     r7, -32697
    ctx->gpr[7] = ((u32)(s32)(-32697) << 16);

label_801845F4:
    ctx->pc = 0x801845F4u;
    // 801845F4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801845F8:
    ctx->pc = 0x801845F8u;
    // 801845F8: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_801845FC:
    ctx->pc = 0x801845FCu;
    // 801845FC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184600:
    ctx->pc = 0x80184600u;
    // 80184600: stw     r0, 2152(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(2152);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184604:
    ctx->pc = 0x80184604u;
    // 80184604: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184608:
    ctx->pc = 0x80184608u;
    // 80184608: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018460C:
    ctx->pc = 0x8018460Cu;
    // 8018460C: bl      0x80184404
    {
            ctx->lr = 0x80184610u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80184404u;
                return;
            }
            goto label_80184404;
    }

label_80184610:
    ctx->pc = 0x80184610u;
    ctx->downcount -= 5;
    // 80184610: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184614:
    ctx->pc = 0x80184614u;
    // 80184614: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80184618:
    ctx->pc = 0x80184618u;
    // 80184618: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018461C:
    ctx->pc = 0x8018461Cu;
    // 8018461C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184620:
    ctx->pc = 0x80184620u;
    ctx->downcount -= 7;
    // 80184620: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184624:
    ctx->pc = 0x80184624u;
    // 80184624: lis     r7, -32697
    ctx->gpr[7] = ((u32)(s32)(-32697) << 16);

label_80184628:
    ctx->pc = 0x80184628u;
    // 80184628: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018462C:
    ctx->pc = 0x8018462Cu;
    // 8018462C: rlwinm. r8, r5, 0, 0, 16
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF8000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80184630:
    ctx->pc = 0x80184630u;
    // 80184630: addi    r9, r7, 2152
    ctx->gpr[9] = ctx->gpr[7] + (u32)(s32)(2152);

label_80184634:
    ctx->pc = 0x80184634u;
    // 80184634: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184638:
    ctx->pc = 0x80184638u;
    // 80184638: bc    4, 2, 0x80184644
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80184644;
        }
    }

label_8018463C:
    ctx->pc = 0x8018463Cu;
    ctx->downcount -= 2;
    // 8018463C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80184640:
    ctx->pc = 0x80184640u;
    // 80184640: b       0x8018464C
    {
            goto label_8018464C;
    }

label_80184644:
    ctx->pc = 0x80184644u;
    ctx->downcount -= 2;
    // 80184644: lwz     r0, -26536(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26536);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184648:
    ctx->pc = 0x80184648u;
    // 80184648: add   r10, r8, r0
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_8018464C:
    ctx->pc = 0x8018464Cu;
    ctx->downcount -= 17;
    // 8018464C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80184650:
    ctx->pc = 0x80184650u;
    // 80184650: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184654:
    ctx->pc = 0x80184654u;
    // 80184654: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_80184658:
    ctx->pc = 0x80184658u;
    // 80184658: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_8018465C:
    ctx->pc = 0x8018465Cu;
    // 8018465C: stw     r10, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80184660:
    ctx->pc = 0x80184660u;
    // 80184660: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184664:
    ctx->pc = 0x80184664u;
    // 80184664: stw     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80184668:
    ctx->pc = 0x80184668u;
    // 80184668: stw     r8, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8018466C:
    ctx->pc = 0x8018466Cu;
    // 8018466C: stw     r3, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184670:
    ctx->pc = 0x80184670u;
    // 80184670: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_80184674:
    ctx->pc = 0x80184674u;
    // 80184674: stw     r4, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184678:
    ctx->pc = 0x80184678u;
    // 80184678: or   r4, r6, r6
    {
        ctx->gpr[4] = ctx->gpr[6] | ctx->gpr[6];
    }

label_8018467C:
    ctx->pc = 0x8018467Cu;
    // 8018467C: stw     r5, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80184680:
    ctx->pc = 0x80184680u;
    // 80184680: stw     r6, 36(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80184684:
    ctx->pc = 0x80184684u;
    // 80184684: stw     r7, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80184688:
    ctx->pc = 0x80184688u;
    // 80184688: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018468C:
    ctx->pc = 0x8018468Cu;
    // 8018468C: bl      0x801849C4
    {
            ctx->lr = 0x80184690u;
            goto label_801849C4;
    }

label_80184690:
    ctx->pc = 0x80184690u;
    ctx->downcount -= 5;
    // 80184690: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184694:
    ctx->pc = 0x80184694u;
    // 80184694: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80184698:
    ctx->pc = 0x80184698u;
    // 80184698: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018469C:
    ctx->pc = 0x8018469Cu;
    // 8018469C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801846A0:
    ctx->pc = 0x801846A0u;
    ctx->downcount -= 22;
    // 801846A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801846A4:
    ctx->pc = 0x801846A4u;
    // 801846A4: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_801846A8:
    ctx->pc = 0x801846A8u;
    // 801846A8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801846AC:
    ctx->pc = 0x801846ACu;
    // 801846AC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801846B0:
    ctx->pc = 0x801846B0u;
    // 801846B0: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801846B4:
    ctx->pc = 0x801846B4u;
    // 801846B4: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801846B8:
    ctx->pc = 0x801846B8u;
    // 801846B8: addi    r31, r9, 2152
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(2152);

label_801846BC:
    ctx->pc = 0x801846BCu;
    // 801846BC: li      r9, -1
    ctx->gpr[9] = (u32)(s32)(-1);

label_801846C0:
    ctx->pc = 0x801846C0u;
    // 801846C0: stw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801846C4:
    ctx->pc = 0x801846C4u;
    // 801846C4: addi    r30, r7, 0
    ctx->gpr[30] = ctx->gpr[7] + (u32)(s32)(0);

label_801846C8:
    ctx->pc = 0x801846C8u;
    // 801846C8: stw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801846CC:
    ctx->pc = 0x801846CCu;
    // 801846CC: addi    r29, r8, 0
    ctx->gpr[29] = ctx->gpr[8] + (u32)(s32)(0);

label_801846D0:
    ctx->pc = 0x801846D0u;
    // 801846D0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801846D4:
    ctx->pc = 0x801846D4u;
    // 801846D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801846D8:
    ctx->pc = 0x801846D8u;
    // 801846D8: stw     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801846DC:
    ctx->pc = 0x801846DCu;
    // 801846DC: addi    r3, r31, 64
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(64);

label_801846E0:
    ctx->pc = 0x801846E0u;
    // 801846E0: stw     r4, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801846E4:
    ctx->pc = 0x801846E4u;
    // 801846E4: stw     r5, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801846E8:
    ctx->pc = 0x801846E8u;
    // 801846E8: stw     r6, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801846EC:
    ctx->pc = 0x801846ECu;
    // 801846EC: stw     r9, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801846F0:
    ctx->pc = 0x801846F0u;
    // 801846F0: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801846F4:
    ctx->pc = 0x801846F4u;
    // 801846F4: bl      0x8016FEEC
    {
            ctx->lr = 0x801846F8u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_801846F8:
    ctx->pc = 0x801846F8u;
    ctx->downcount -= 6;
    // 801846F8: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_801846FC:
    ctx->pc = 0x801846FCu;
    // 801846FC: addi    r7, r3, 17068
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17068);

label_80184700:
    ctx->pc = 0x80184700u;
    // 80184700: addi    r6, r29, 0
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(0);

label_80184704:
    ctx->pc = 0x80184704u;
    // 80184704: addi    r5, r30, 0
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(0);

label_80184708:
    ctx->pc = 0x80184708u;
    // 80184708: addi    r3, r31, 64
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(64);

label_8018470C:
    ctx->pc = 0x8018470Cu;
    // 8018470C: bl      0x80170148
    {
            ctx->lr = 0x80184710u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184710:
    ctx->pc = 0x80184710u;
    ctx->downcount -= 8;
    // 80184710: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184714:
    ctx->pc = 0x80184714u;
    // 80184714: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184718:
    ctx->pc = 0x80184718u;
    // 80184718: lwz     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8018471C:
    ctx->pc = 0x8018471Cu;
    // 8018471C: lwz     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80184720:
    ctx->pc = 0x80184720u;
    // 80184720: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80184724:
    ctx->pc = 0x80184724u;
    // 80184724: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184728:
    ctx->pc = 0x80184728u;
    // 80184728: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018472C:
    ctx->pc = 0x8018472Cu;
    ctx->downcount -= 30;
    // 8018472C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184730:
    ctx->pc = 0x80184730u;
    // 80184730: lis     r7, -13312
    ctx->gpr[7] = ((u32)(s32)(-13312) << 16);

label_80184734:
    ctx->pc = 0x80184734u;
    // 80184734: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184738:
    ctx->pc = 0x80184738u;
    // 80184738: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018473C:
    ctx->pc = 0x8018473Cu;
    // 8018473C: stmw     r22, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 22; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80184740:
    ctx->pc = 0x80184740u;
    // 80184740: addi    r25, r4, 0
    ctx->gpr[25] = ctx->gpr[4] + (u32)(s32)(0);

label_80184744:
    ctx->pc = 0x80184744u;
    // 80184744: addi    r4, r7, 24576
    ctx->gpr[4] = ctx->gpr[7] + (u32)(s32)(24576);

label_80184748:
    ctx->pc = 0x80184748u;
    // 80184748: lis     r7, -32697
    ctx->gpr[7] = ((u32)(s32)(-32697) << 16);

label_8018474C:
    ctx->pc = 0x8018474Cu;
    // 8018474C: addi    r31, r7, 2152
    ctx->gpr[31] = ctx->gpr[7] + (u32)(s32)(2152);

label_80184750:
    ctx->pc = 0x80184750u;
    // 80184750: addi    r24, r3, 0
    ctx->gpr[24] = ctx->gpr[3] + (u32)(s32)(0);

label_80184754:
    ctx->pc = 0x80184754u;
    // 80184754: addi    r26, r5, 0
    ctx->gpr[26] = ctx->gpr[5] + (u32)(s32)(0);

label_80184758:
    ctx->pc = 0x80184758u;
    // 80184758: addi    r30, r31, 204
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(204);

label_8018475C:
    ctx->pc = 0x8018475Cu;
    // 8018475C: or   r27, r6, r6
    {
        ctx->gpr[27] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80184760:
    ctx->pc = 0x80184760u;
    // 80184760: stw     r25, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80184764:
    ctx->pc = 0x80184764u;
    // 80184764: stw     r24, 196(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(196);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_80184768:
    ctx->pc = 0x80184768u;
    // 80184768: stw     r25, 200(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(200);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_8018476C:
    ctx->pc = 0x8018476Cu;
    // 8018476C: stw     r26, 204(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(204);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80184770:
    ctx->pc = 0x80184770u;
    // 80184770: lwz     r0, -26540(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26540);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184774:
    ctx->pc = 0x80184774u;
    // 80184774: cmplwi  r0, 0x0000
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

label_80184778:
    ctx->pc = 0x80184778u;
    // 80184778: bc    4, 2, 0x801847A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801847A4;
        }
    }

label_8018477C:
    ctx->pc = 0x8018477Cu;
    ctx->downcount -= 9;
    // 8018477C: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80184780:
    ctx->pc = 0x80184780u;
    // 80184780: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184784:
    ctx->pc = 0x80184784u;
    // 80184784: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184788:
    ctx->pc = 0x80184788u;
    // 80184788: addi    r3, r24, 0
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(0);

label_8018478C:
    ctx->pc = 0x8018478Cu;
    // 8018478C: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184790:
    ctx->pc = 0x80184790u;
    // 80184790: addi    r4, r25, 0
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(0);

label_80184794:
    ctx->pc = 0x80184794u;
    // 80184794: addi    r5, r26, 0
    ctx->gpr[5] = ctx->gpr[26] + (u32)(s32)(0);

label_80184798:
    ctx->pc = 0x80184798u;
    // 80184798: addi    r6, r27, 0
    ctx->gpr[6] = ctx->gpr[27] + (u32)(s32)(0);

label_8018479C:
    ctx->pc = 0x8018479Cu;
    // 8018479C: bl      0x80184404
    {
            ctx->lr = 0x801847A0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80184404u;
                return;
            }
            goto label_80184404;
    }

label_801847A0:
    ctx->pc = 0x801847A0u;
    ctx->downcount -= 1;
    // 801847A0: b       0x801849AC
    {
            goto label_801849AC;
    }

label_801847A4:
    ctx->pc = 0x801847A4u;
    ctx->downcount -= 3;
    // 801847A4: lwz     r0, -26540(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26540);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801847A8:
    ctx->pc = 0x801847A8u;
    // 801847A8: cmplwi  r0, 0x0001
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

label_801847AC:
    ctx->pc = 0x801847ACu;
    // 801847AC: bc    4, 2, 0x801849AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801849AC;
        }
    }

label_801847B0:
    ctx->pc = 0x801847B0u;
    ctx->downcount -= 3;
    // 801847B0: lwz     r0, -28760(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28760);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801847B4:
    ctx->pc = 0x801847B4u;
    // 801847B4: cmpwi   r0, 0
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

label_801847B8:
    ctx->pc = 0x801847B8u;
    // 801847B8: bc    12, 2, 0x801847D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801847D4;
        }
    }

label_801847BC:
    ctx->pc = 0x801847BCu;
    ctx->downcount -= 5;
    // 801847BC: addi    r3, r24, 0
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(0);

label_801847C0:
    ctx->pc = 0x801847C0u;
    // 801847C0: addi    r4, r25, 0
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(0);

label_801847C4:
    ctx->pc = 0x801847C4u;
    // 801847C4: addi    r5, r26, 0
    ctx->gpr[5] = ctx->gpr[26] + (u32)(s32)(0);

label_801847C8:
    ctx->pc = 0x801847C8u;
    // 801847C8: addi    r6, r27, 0
    ctx->gpr[6] = ctx->gpr[27] + (u32)(s32)(0);

label_801847CC:
    ctx->pc = 0x801847CCu;
    // 801847CC: bl      0x80184620
    {
            ctx->lr = 0x801847D0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80184620u;
                return;
            }
            goto label_80184620;
    }

label_801847D0:
    ctx->pc = 0x801847D0u;
    ctx->downcount -= 1;
    // 801847D0: b       0x801849AC
    {
            goto label_801849AC;
    }

label_801847D4:
    ctx->pc = 0x801847D4u;
    ctx->downcount -= 10;
    // 801847D4: addi    r29, r31, 188
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(188);

label_801847D8:
    ctx->pc = 0x801847D8u;
    // 801847D8: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801847DC:
    ctx->pc = 0x801847DCu;
    // 801847DC: addi    r28, r31, 192
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(192);

label_801847E0:
    ctx->pc = 0x801847E0u;
    // 801847E0: lwz     r3, 188(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(188);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801847E4:
    ctx->pc = 0x801847E4u;
    // 801847E4: lwz     r4, 192(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(192);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801847E8:
    ctx->pc = 0x801847E8u;
    // 801847E8: rlwinm r23, r0, 17, 15, 31
    {
        ctx->gpr[23] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x0001FFFFu;
    }

label_801847EC:
    ctx->pc = 0x801847ECu;
    // 801847EC: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_801847F0:
    ctx->pc = 0x801847F0u;
    // 801847F0: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801847F4:
    ctx->pc = 0x801847F4u;
    // 801847F4: rlwinm r22, r0, 17, 15, 31
    {
        ctx->gpr[22] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x0001FFFFu;
    }

label_801847F8:
    ctx->pc = 0x801847F8u;
    // 801847F8: bl      0x80183370
    {
            ctx->lr = 0x801847FCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80183370u;
                return;
            }
            goto label_80183370;
    }

label_801847FC:
    ctx->pc = 0x801847FCu;
    ctx->downcount -= 3;
    // 801847FC: lbz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80184800:
    ctx->pc = 0x80184800u;
    // 80184800: cmplwi  r0, 0x0000
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

label_80184804:
    ctx->pc = 0x80184804u;
    // 80184804: bc    12, 2, 0x80184810
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184810;
        }
    }

label_80184808:
    ctx->pc = 0x80184808u;
    ctx->downcount -= 2;
    // 80184808: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8018480C:
    ctx->pc = 0x8018480Cu;
    // 8018480C: b       0x80184814
    {
            goto label_80184814;
    }

label_80184810:
    ctx->pc = 0x80184810u;
    ctx->downcount -= 1;
    // 80184810: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184814:
    ctx->pc = 0x80184814u;
    ctx->downcount -= 2;
    // 80184814: cmpwi   r0, 0
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

label_80184818:
    ctx->pc = 0x80184818u;
    // 80184818: bc    12, 2, 0x80184824
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184824;
        }
    }

label_8018481C:
    ctx->pc = 0x8018481Cu;
    ctx->downcount -= 2;
    // 8018481C: li      r3, 5
    ctx->gpr[3] = (u32)(s32)(5);

label_80184820:
    ctx->pc = 0x80184820u;
    // 80184820: b       0x80184828
    {
            goto label_80184828;
    }

label_80184824:
    ctx->pc = 0x80184824u;
    ctx->downcount -= 1;
    // 80184824: li      r3, 15
    ctx->gpr[3] = (u32)(s32)(15);

label_80184828:
    ctx->pc = 0x80184828u;
    ctx->downcount -= 3;
    // 80184828: addi    r0, r22, -2
    ctx->gpr[0] = ctx->gpr[22] + (u32)(s32)(-2);

label_8018482C:
    ctx->pc = 0x8018482Cu;
    // 8018482C: cmplw   r23, r0
    {
        u32 val_a = (u32)(ctx->gpr[23]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80184830:
    ctx->pc = 0x80184830u;
    // 80184830: bc    12, 1, 0x80184844
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184844;
        }
    }

label_80184834:
    ctx->pc = 0x80184834u;
    ctx->downcount -= 4;
    // 80184834: addi    r0, r3, 3
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(3);

label_80184838:
    ctx->pc = 0x80184838u;
    // 80184838: add   r0, r22, r0
    {
        u32 a = ctx->gpr[22];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8018483C:
    ctx->pc = 0x8018483Cu;
    // 8018483C: cmplw   r23, r0
    {
        u32 val_a = (u32)(ctx->gpr[23]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80184840:
    ctx->pc = 0x80184840u;
    // 80184840: bc    4, 0, 0x8018484C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018484C;
        }
    }

label_80184844:
    ctx->pc = 0x80184844u;
    ctx->downcount -= 2;
    // 80184844: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184848:
    ctx->pc = 0x80184848u;
    // 80184848: b       0x80184850
    {
            goto label_80184850;
    }

label_8018484C:
    ctx->pc = 0x8018484Cu;
    ctx->downcount -= 1;
    // 8018484C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184850:
    ctx->pc = 0x80184850u;
    ctx->downcount -= 2;
    // 80184850: cmpwi   r0, 0
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

label_80184854:
    ctx->pc = 0x80184854u;
    // 80184854: bc    4, 2, 0x80184880
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80184880;
        }
    }

label_80184858:
    ctx->pc = 0x80184858u;
    ctx->downcount -= 9;
    // 80184858: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8018485C:
    ctx->pc = 0x8018485Cu;
    // 8018485C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184860:
    ctx->pc = 0x80184860u;
    // 80184860: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184864:
    ctx->pc = 0x80184864u;
    // 80184864: addi    r3, r24, 0
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(0);

label_80184868:
    ctx->pc = 0x80184868u;
    // 80184868: stw     r0, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018486C:
    ctx->pc = 0x8018486Cu;
    // 8018486C: addi    r4, r25, 0
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(0);

label_80184870:
    ctx->pc = 0x80184870u;
    // 80184870: addi    r5, r26, 0
    ctx->gpr[5] = ctx->gpr[26] + (u32)(s32)(0);

label_80184874:
    ctx->pc = 0x80184874u;
    // 80184874: addi    r6, r27, 0
    ctx->gpr[6] = ctx->gpr[27] + (u32)(s32)(0);

label_80184878:
    ctx->pc = 0x80184878u;
    // 80184878: bl      0x80184404
    {
            ctx->lr = 0x8018487Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80184404u;
                return;
            }
            goto label_80184404;
    }

label_8018487C:
    ctx->pc = 0x8018487Cu;
    ctx->downcount -= 1;
    // 8018487C: b       0x801849AC
    {
            goto label_801849AC;
    }

label_80184880:
    ctx->pc = 0x80184880u;
    ctx->downcount -= 9;
    // 80184880: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80184884:
    ctx->pc = 0x80184884u;
    // 80184884: lwz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80184888:
    ctx->pc = 0x80184888u;
    // 80184888: addi    r3, r3, -1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-1);

label_8018488C:
    ctx->pc = 0x8018488Cu;
    // 8018488C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184890:
    ctx->pc = 0x80184890u;
    // 80184890: add   r3, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80184894:
    ctx->pc = 0x80184894u;
    // 80184894: rlwinm r3, r3, 17, 15, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 17u) & 0x0001FFFFu;
    }

label_80184898:
    ctx->pc = 0x80184898u;
    // 80184898: rlwinm r4, r0, 17, 15, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x0001FFFFu;
    }

label_8018489C:
    ctx->pc = 0x8018489Cu;
    // 8018489C: cmplw   r3, r4
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

label_801848A0:
    ctx->pc = 0x801848A0u;
    // 801848A0: bc    12, 2, 0x801848B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801848B0;
        }
    }

label_801848A4:
    ctx->pc = 0x801848A4u;
    ctx->downcount -= 3;
    // 801848A4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_801848A8:
    ctx->pc = 0x801848A8u;
    // 801848A8: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801848AC:
    ctx->pc = 0x801848ACu;
    // 801848AC: bc    4, 2, 0x80184998
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80184998;
        }
    }

label_801848B0:
    ctx->pc = 0x801848B0u;
    ctx->downcount -= 1;
    // 801848B0: bl      0x8017A0AC
    {
            ctx->lr = 0x801848B4u;
            ctx->pc = 0x8017A0ACu;
            return;
    }

label_801848B4:
    ctx->pc = 0x801848B4u;
    ctx->downcount -= 26;
    // 801848B4: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_801848B8:
    ctx->pc = 0x801848B8u;
    // 801848B8: lwz     r8, -26528(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26528);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801848BC:
    ctx->pc = 0x801848BCu;
    // 801848BC: lwz     r0, 248(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801848C0:
    ctx->pc = 0x801848C0u;
    // 801848C0: lis     r5, 4194
    ctx->gpr[5] = ((u32)(s32)(4194) << 16);

label_801848C4:
    ctx->pc = 0x801848C4u;
    // 801848C4: lwz     r9, -26524(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26524);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801848C8:
    ctx->pc = 0x801848C8u;
    // 801848C8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801848CC:
    ctx->pc = 0x801848CCu;
    // 801848CC: rlwinm r7, r0, 30, 2, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_801848D0:
    ctx->pc = 0x801848D0u;
    // 801848D0: addi    r0, r5, 19923
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(19923);

label_801848D4:
    ctx->pc = 0x801848D4u;
    // 801848D4: mulhwu   r0, r0, r7
    {
        u64 product = (u64)ctx->gpr[0] * (u64)ctx->gpr[7];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_801848D8:
    ctx->pc = 0x801848D8u;
    // 801848D8: rlwinm r0, r0, 26, 6, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x03FFFFFFu;
    }

label_801848DC:
    ctx->pc = 0x801848DCu;
    // 801848DC: subfc   r9, r9, r4
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[9] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801848E0:
    ctx->pc = 0x801848E0u;
    // 801848E0: subfe   r8, r8, r3
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[8] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801848E4:
    ctx->pc = 0x801848E4u;
    // 801848E4: mulli   r5, r0, 5
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)5);

label_801848E8:
    ctx->pc = 0x801848E8u;
    // 801848E8: xoris   r4, r6, 0x8000
    ctx->gpr[4] = ctx->gpr[6] ^ (0x8000u << 16);

label_801848EC:
    ctx->pc = 0x801848ECu;
    // 801848EC: xoris   r3, r8, 0x8000
    ctx->gpr[3] = ctx->gpr[8] ^ (0x8000u << 16);

label_801848F0:
    ctx->pc = 0x801848F0u;
    // 801848F0: subfc   r0, r9, r5
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[5];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801848F4:
    ctx->pc = 0x801848F4u;
    // 801848F4: subfe   r3, r3, r4
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801848F8:
    ctx->pc = 0x801848F8u;
    // 801848F8: subfe   r3, r4, r4
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801848FC:
    ctx->pc = 0x801848FCu;
    // 801848FC: neg.  r3, r3
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

label_80184900:
    ctx->pc = 0x80184900u;
    // 80184900: bc    12, 2, 0x80184928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184928;
        }
    }

label_80184904:
    ctx->pc = 0x80184904u;
    ctx->downcount -= 8;
    // 80184904: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80184908:
    ctx->pc = 0x80184908u;
    // 80184908: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018490C:
    ctx->pc = 0x8018490Cu;
    // 8018490C: addi    r3, r24, 0
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(0);

label_80184910:
    ctx->pc = 0x80184910u;
    // 80184910: addi    r4, r25, 0
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(0);

label_80184914:
    ctx->pc = 0x80184914u;
    // 80184914: stw     r6, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80184918:
    ctx->pc = 0x80184918u;
    // 80184918: addi    r5, r26, 0
    ctx->gpr[5] = ctx->gpr[26] + (u32)(s32)(0);

label_8018491C:
    ctx->pc = 0x8018491Cu;
    // 8018491C: addi    r6, r27, 0
    ctx->gpr[6] = ctx->gpr[27] + (u32)(s32)(0);

label_80184920:
    ctx->pc = 0x80184920u;
    // 80184920: bl      0x80184404
    {
            ctx->lr = 0x80184924u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80184404u;
                return;
            }
            goto label_80184404;
    }

label_80184924:
    ctx->pc = 0x80184924u;
    ctx->downcount -= 1;
    // 80184924: b       0x801849AC
    {
            goto label_801849AC;
    }

label_80184928:
    ctx->pc = 0x80184928u;
    ctx->downcount -= 27;
    // 80184928: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8018492C:
    ctx->pc = 0x8018492Cu;
    // 8018492C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184930:
    ctx->pc = 0x80184930u;
    // 80184930: lis     r3, 17180
    ctx->gpr[3] = ((u32)(s32)(17180) << 16);

label_80184934:
    ctx->pc = 0x80184934u;
    // 80184934: addi    r0, r3, -8573
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-8573);

label_80184938:
    ctx->pc = 0x80184938u;
    // 80184938: stw     r24, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_8018493C:
    ctx->pc = 0x8018493Cu;
    // 8018493C: mulhwu   r0, r0, r7
    {
        u64 product = (u64)ctx->gpr[0] * (u64)ctx->gpr[7];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_80184940:
    ctx->pc = 0x80184940u;
    // 80184940: stw     r25, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80184944:
    ctx->pc = 0x80184944u;
    // 80184944: stw     r26, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80184948:
    ctx->pc = 0x80184948u;
    // 80184948: rlwinm r0, r0, 17, 15, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x0001FFFFu;
    }

label_8018494C:
    ctx->pc = 0x8018494Cu;
    // 8018494C: mulli   r3, r0, 500
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)500);

label_80184950:
    ctx->pc = 0x80184950u;
    // 80184950: stw     r27, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80184954:
    ctx->pc = 0x80184954u;
    // 80184954: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80184958:
    ctx->pc = 0x80184958u;
    // 80184958: stw     r0, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018495C:
    ctx->pc = 0x8018495Cu;
    // 8018495C: subfc   r5, r9, r5
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[5];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184960:
    ctx->pc = 0x80184960u;
    // 80184960: subfe   r4, r8, r6
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[6];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184964:
    ctx->pc = 0x80184964u;
    // 80184964: rlwinm r0, r3, 29, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 29u) & 0x1FFFFFFFu;
    }

label_80184968:
    ctx->pc = 0x80184968u;
    // 80184968: stw     r6, -26508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26508);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8018496C:
    ctx->pc = 0x8018496Cu;
    // 8018496C: addc   r23, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u64 wide = (u64)a + (u64)b;
        u32 res = (u32)wide;
        ctx->gpr[23] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184970:
    ctx->pc = 0x80184970u;
    // 80184970: adde   r22, r4, r6
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[6];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[22] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184974:
    ctx->pc = 0x80184974u;
    // 80184974: addi    r3, r31, 64
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(64);

label_80184978:
    ctx->pc = 0x80184978u;
    // 80184978: bl      0x8016FEEC
    {
            ctx->lr = 0x8018497Cu;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_8018497C:
    ctx->pc = 0x8018497Cu;
    ctx->downcount -= 6;
    // 8018497C: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184980:
    ctx->pc = 0x80184980u;
    // 80184980: addi    r7, r3, 17068
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17068);

label_80184984:
    ctx->pc = 0x80184984u;
    // 80184984: addi    r6, r23, 0
    ctx->gpr[6] = ctx->gpr[23] + (u32)(s32)(0);

label_80184988:
    ctx->pc = 0x80184988u;
    // 80184988: addi    r5, r22, 0
    ctx->gpr[5] = ctx->gpr[22] + (u32)(s32)(0);

label_8018498C:
    ctx->pc = 0x8018498Cu;
    // 8018498C: addi    r3, r31, 64
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(64);

label_80184990:
    ctx->pc = 0x80184990u;
    // 80184990: bl      0x80170148
    {
            ctx->lr = 0x80184994u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184994:
    ctx->pc = 0x80184994u;
    ctx->downcount -= 1;
    // 80184994: b       0x801849AC
    {
            goto label_801849AC;
    }

label_80184998:
    ctx->pc = 0x80184998u;
    ctx->downcount -= 5;
    // 80184998: addi    r3, r24, 0
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(0);

label_8018499C:
    ctx->pc = 0x8018499Cu;
    // 8018499C: addi    r4, r25, 0
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(0);

label_801849A0:
    ctx->pc = 0x801849A0u;
    // 801849A0: addi    r5, r26, 0
    ctx->gpr[5] = ctx->gpr[26] + (u32)(s32)(0);

label_801849A4:
    ctx->pc = 0x801849A4u;
    // 801849A4: addi    r6, r27, 0
    ctx->gpr[6] = ctx->gpr[27] + (u32)(s32)(0);

label_801849A8:
    ctx->pc = 0x801849A8u;
    // 801849A8: bl      0x80184620
    {
            ctx->lr = 0x801849ACu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80184620u;
                return;
            }
            goto label_80184620;
    }

label_801849AC:
    ctx->pc = 0x801849ACu;
    ctx->downcount -= 17;
    // 801849AC: lmw     r22, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 22; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801849B0:
    ctx->pc = 0x801849B0u;
    // 801849B0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801849B4:
    ctx->pc = 0x801849B4u;
    // 801849B4: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801849B8:
    ctx->pc = 0x801849B8u;
    // 801849B8: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_801849BC:
    ctx->pc = 0x801849BCu;
    // 801849BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801849C0:
    ctx->pc = 0x801849C0u;
    // 801849C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801849C4:
    ctx->pc = 0x801849C4u;
    ctx->downcount -= 26;
    // 801849C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801849C8:
    ctx->pc = 0x801849C8u;
    // 801849C8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801849CC:
    ctx->pc = 0x801849CCu;
    // 801849CC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801849D0:
    ctx->pc = 0x801849D0u;
    // 801849D0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801849D4:
    ctx->pc = 0x801849D4u;
    // 801849D4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801849D8:
    ctx->pc = 0x801849D8u;
    // 801849D8: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801849DC:
    ctx->pc = 0x801849DCu;
    // 801849DC: stw     r4, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801849E0:
    ctx->pc = 0x801849E0u;
    // 801849E0: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_801849E4:
    ctx->pc = 0x801849E4u;
    // 801849E4: addi    r4, r4, 24576
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(24576);

label_801849E8:
    ctx->pc = 0x801849E8u;
    // 801849E8: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801849EC:
    ctx->pc = 0x801849ECu;
    // 801849EC: lis     r0, -21760
    ctx->gpr[0] = ((u32)(s32)(-21760) << 16);

label_801849F0:
    ctx->pc = 0x801849F0u;
    // 801849F0: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801849F4:
    ctx->pc = 0x801849F4u;
    // 801849F4: rlwinm r0, r3, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 30u) & 0x3FFFFFFFu;
    }

label_801849F8:
    ctx->pc = 0x801849F8u;
    // 801849F8: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_801849FC:
    ctx->pc = 0x801849FCu;
    // 801849FC: stw     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184A00:
    ctx->pc = 0x80184A00u;
    // 80184A00: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184A04:
    ctx->pc = 0x80184A04u;
    // 80184A04: addi    r31, r3, 2256
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2256);

label_80184A08:
    ctx->pc = 0x80184A08u;
    // 80184A08: stw     r0, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184A0C:
    ctx->pc = 0x80184A0Cu;
    // 80184A0C: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80184A10:
    ctx->pc = 0x80184A10u;
    // 80184A10: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184A14:
    ctx->pc = 0x80184A14u;
    // 80184A14: lwz     r0, 248(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184A18:
    ctx->pc = 0x80184A18u;
    // 80184A18: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184A1C:
    ctx->pc = 0x80184A1Cu;
    // 80184A1C: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_80184A20:
    ctx->pc = 0x80184A20u;
    // 80184A20: bl      0x8016FEEC
    {
            ctx->lr = 0x80184A24u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_80184A24:
    ctx->pc = 0x80184A24u;
    ctx->downcount -= 6;
    // 80184A24: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184A28:
    ctx->pc = 0x80184A28u;
    // 80184A28: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_80184A2C:
    ctx->pc = 0x80184A2Cu;
    // 80184A2C: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184A30:
    ctx->pc = 0x80184A30u;
    // 80184A30: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_80184A34:
    ctx->pc = 0x80184A34u;
    // 80184A34: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80184A38:
    ctx->pc = 0x80184A38u;
    // 80184A38: bl      0x80170148
    {
            ctx->lr = 0x80184A3Cu;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184A3C:
    ctx->pc = 0x80184A3Cu;
    ctx->downcount -= 8;
    // 80184A3C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184A40:
    ctx->pc = 0x80184A40u;
    // 80184A40: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184A44:
    ctx->pc = 0x80184A44u;
    // 80184A44: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184A48:
    ctx->pc = 0x80184A48u;
    // 80184A48: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184A4C:
    ctx->pc = 0x80184A4Cu;
    // 80184A4C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80184A50:
    ctx->pc = 0x80184A50u;
    // 80184A50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184A54:
    ctx->pc = 0x80184A54u;
    // 80184A54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184A58:
    ctx->pc = 0x80184A58u;
    ctx->downcount -= 11;
    // 80184A58: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184A5C:
    ctx->pc = 0x80184A5Cu;
    // 80184A5C: stw     r3, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184A60:
    ctx->pc = 0x80184A60u;
    // 80184A60: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80184A64:
    ctx->pc = 0x80184A64u;
    // 80184A64: stw     r0, -26548(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26548);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184A68:
    ctx->pc = 0x80184A68u;
    // 80184A68: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184A6C:
    ctx->pc = 0x80184A6Cu;
    // 80184A6C: addi    r4, r3, 24576
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24576);

label_80184A70:
    ctx->pc = 0x80184A70u;
    // 80184A70: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184A74:
    ctx->pc = 0x80184A74u;
    // 80184A74: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80184A78:
    ctx->pc = 0x80184A78u;
    // 80184A78: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184A7C:
    ctx->pc = 0x80184A7Cu;
    // 80184A7C: stw     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184A80:
    ctx->pc = 0x80184A80u;
    // 80184A80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184A84:
    ctx->pc = 0x80184A84u;
    ctx->downcount -= 30;
    // 80184A84: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184A88:
    ctx->pc = 0x80184A88u;
    // 80184A88: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80184A8C:
    ctx->pc = 0x80184A8Cu;
    // 80184A8C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184A90:
    ctx->pc = 0x80184A90u;
    // 80184A90: lis     r5, -22528
    ctx->gpr[5] = ((u32)(s32)(-22528) << 16);

label_80184A94:
    ctx->pc = 0x80184A94u;
    // 80184A94: addi    r0, r5, 64
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(64);

label_80184A98:
    ctx->pc = 0x80184A98u;
    // 80184A98: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184A9C:
    ctx->pc = 0x80184A9Cu;
    // 80184A9C: li      r6, 32
    ctx->gpr[6] = (u32)(s32)(32);

label_80184AA0:
    ctx->pc = 0x80184AA0u;
    // 80184AA0: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_80184AA4:
    ctx->pc = 0x80184AA4u;
    // 80184AA4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184AA8:
    ctx->pc = 0x80184AA8u;
    // 80184AA8: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184AAC:
    ctx->pc = 0x80184AACu;
    // 80184AAC: stw     r4, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184AB0:
    ctx->pc = 0x80184AB0u;
    // 80184AB0: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_80184AB4:
    ctx->pc = 0x80184AB4u;
    // 80184AB4: addi    r7, r4, 24576
    ctx->gpr[7] = ctx->gpr[4] + (u32)(s32)(24576);

label_80184AB8:
    ctx->pc = 0x80184AB8u;
    // 80184AB8: stw     r8, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80184ABC:
    ctx->pc = 0x80184ABCu;
    // 80184ABC: stw     r0, 24584(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24584);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184AC0:
    ctx->pc = 0x80184AC0u;
    // 80184AC0: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80184AC4:
    ctx->pc = 0x80184AC4u;
    // 80184AC4: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80184AC8:
    ctx->pc = 0x80184AC8u;
    // 80184AC8: stw     r8, 12(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80184ACC:
    ctx->pc = 0x80184ACCu;
    // 80184ACC: addi    r31, r4, 2256
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(2256);

label_80184AD0:
    ctx->pc = 0x80184AD0u;
    // 80184AD0: stw     r6, 16(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80184AD4:
    ctx->pc = 0x80184AD4u;
    // 80184AD4: stw     r3, 20(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184AD8:
    ctx->pc = 0x80184AD8u;
    // 80184AD8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80184ADC:
    ctx->pc = 0x80184ADCu;
    // 80184ADC: stw     r6, 24(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80184AE0:
    ctx->pc = 0x80184AE0u;
    // 80184AE0: stw     r0, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184AE4:
    ctx->pc = 0x80184AE4u;
    // 80184AE4: lwz     r0, 248(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184AE8:
    ctx->pc = 0x80184AE8u;
    // 80184AE8: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184AEC:
    ctx->pc = 0x80184AECu;
    // 80184AEC: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_80184AF0:
    ctx->pc = 0x80184AF0u;
    // 80184AF0: bl      0x8016FEEC
    {
            ctx->lr = 0x80184AF4u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_80184AF4:
    ctx->pc = 0x80184AF4u;
    ctx->downcount -= 6;
    // 80184AF4: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184AF8:
    ctx->pc = 0x80184AF8u;
    // 80184AF8: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_80184AFC:
    ctx->pc = 0x80184AFCu;
    // 80184AFC: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184B00:
    ctx->pc = 0x80184B00u;
    // 80184B00: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_80184B04:
    ctx->pc = 0x80184B04u;
    // 80184B04: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80184B08:
    ctx->pc = 0x80184B08u;
    // 80184B08: bl      0x80170148
    {
            ctx->lr = 0x80184B0Cu;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184B0C:
    ctx->pc = 0x80184B0Cu;
    ctx->downcount -= 8;
    // 80184B0C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184B10:
    ctx->pc = 0x80184B10u;
    // 80184B10: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184B14:
    ctx->pc = 0x80184B14u;
    // 80184B14: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184B18:
    ctx->pc = 0x80184B18u;
    // 80184B18: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184B1C:
    ctx->pc = 0x80184B1Cu;
    // 80184B1C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80184B20:
    ctx->pc = 0x80184B20u;
    // 80184B20: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184B24:
    ctx->pc = 0x80184B24u;
    // 80184B24: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184B28:
    ctx->pc = 0x80184B28u;
    ctx->downcount -= 24;
    // 80184B28: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184B2C:
    ctx->pc = 0x80184B2Cu;
    // 80184B2C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184B30:
    ctx->pc = 0x80184B30u;
    // 80184B30: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184B34:
    ctx->pc = 0x80184B34u;
    // 80184B34: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184B38:
    ctx->pc = 0x80184B38u;
    // 80184B38: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184B3C:
    ctx->pc = 0x80184B3Cu;
    // 80184B3C: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184B40:
    ctx->pc = 0x80184B40u;
    // 80184B40: stw     r3, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184B44:
    ctx->pc = 0x80184B44u;
    // 80184B44: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80184B48:
    ctx->pc = 0x80184B48u;
    // 80184B48: addi    r4, r3, 24576
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24576);

label_80184B4C:
    ctx->pc = 0x80184B4Cu;
    // 80184B4C: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184B50:
    ctx->pc = 0x80184B50u;
    // 80184B50: lis     r0, -7424
    ctx->gpr[0] = ((u32)(s32)(-7424) << 16);

label_80184B54:
    ctx->pc = 0x80184B54u;
    // 80184B54: stw     r0, 24584(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24584);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184B58:
    ctx->pc = 0x80184B58u;
    // 80184B58: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184B5C:
    ctx->pc = 0x80184B5Cu;
    // 80184B5C: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80184B60:
    ctx->pc = 0x80184B60u;
    // 80184B60: stw     r0, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184B64:
    ctx->pc = 0x80184B64u;
    // 80184B64: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80184B68:
    ctx->pc = 0x80184B68u;
    // 80184B68: addi    r31, r3, 2256
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2256);

label_80184B6C:
    ctx->pc = 0x80184B6Cu;
    // 80184B6C: lwz     r0, 248(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184B70:
    ctx->pc = 0x80184B70u;
    // 80184B70: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184B74:
    ctx->pc = 0x80184B74u;
    // 80184B74: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184B78:
    ctx->pc = 0x80184B78u;
    // 80184B78: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_80184B7C:
    ctx->pc = 0x80184B7Cu;
    // 80184B7C: bl      0x8016FEEC
    {
            ctx->lr = 0x80184B80u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_80184B80:
    ctx->pc = 0x80184B80u;
    ctx->downcount -= 6;
    // 80184B80: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184B84:
    ctx->pc = 0x80184B84u;
    // 80184B84: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_80184B88:
    ctx->pc = 0x80184B88u;
    // 80184B88: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184B8C:
    ctx->pc = 0x80184B8Cu;
    // 80184B8C: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_80184B90:
    ctx->pc = 0x80184B90u;
    // 80184B90: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80184B94:
    ctx->pc = 0x80184B94u;
    // 80184B94: bl      0x80170148
    {
            ctx->lr = 0x80184B98u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184B98:
    ctx->pc = 0x80184B98u;
    ctx->downcount -= 8;
    // 80184B98: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184B9C:
    ctx->pc = 0x80184B9Cu;
    // 80184B9C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184BA0:
    ctx->pc = 0x80184BA0u;
    // 80184BA0: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184BA4:
    ctx->pc = 0x80184BA4u;
    // 80184BA4: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184BA8:
    ctx->pc = 0x80184BA8u;
    // 80184BA8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80184BAC:
    ctx->pc = 0x80184BACu;
    // 80184BAC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184BB0:
    ctx->pc = 0x80184BB0u;
    // 80184BB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184BB4:
    ctx->pc = 0x80184BB4u;
    ctx->downcount -= 24;
    // 80184BB4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184BB8:
    ctx->pc = 0x80184BB8u;
    // 80184BB8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184BBC:
    ctx->pc = 0x80184BBCu;
    // 80184BBC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184BC0:
    ctx->pc = 0x80184BC0u;
    // 80184BC0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184BC4:
    ctx->pc = 0x80184BC4u;
    // 80184BC4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184BC8:
    ctx->pc = 0x80184BC8u;
    // 80184BC8: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184BCC:
    ctx->pc = 0x80184BCCu;
    // 80184BCC: stw     r3, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184BD0:
    ctx->pc = 0x80184BD0u;
    // 80184BD0: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80184BD4:
    ctx->pc = 0x80184BD4u;
    // 80184BD4: addi    r4, r3, 24576
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24576);

label_80184BD8:
    ctx->pc = 0x80184BD8u;
    // 80184BD8: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184BDC:
    ctx->pc = 0x80184BDCu;
    // 80184BDC: lis     r0, -8192
    ctx->gpr[0] = ((u32)(s32)(-8192) << 16);

label_80184BE0:
    ctx->pc = 0x80184BE0u;
    // 80184BE0: stw     r0, 24584(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24584);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184BE4:
    ctx->pc = 0x80184BE4u;
    // 80184BE4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184BE8:
    ctx->pc = 0x80184BE8u;
    // 80184BE8: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80184BEC:
    ctx->pc = 0x80184BECu;
    // 80184BEC: stw     r0, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184BF0:
    ctx->pc = 0x80184BF0u;
    // 80184BF0: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80184BF4:
    ctx->pc = 0x80184BF4u;
    // 80184BF4: addi    r31, r3, 2256
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2256);

label_80184BF8:
    ctx->pc = 0x80184BF8u;
    // 80184BF8: lwz     r0, 248(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184BFC:
    ctx->pc = 0x80184BFCu;
    // 80184BFC: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184C00:
    ctx->pc = 0x80184C00u;
    // 80184C00: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184C04:
    ctx->pc = 0x80184C04u;
    // 80184C04: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_80184C08:
    ctx->pc = 0x80184C08u;
    // 80184C08: bl      0x8016FEEC
    {
            ctx->lr = 0x80184C0Cu;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_80184C0C:
    ctx->pc = 0x80184C0Cu;
    ctx->downcount -= 6;
    // 80184C0C: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184C10:
    ctx->pc = 0x80184C10u;
    // 80184C10: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_80184C14:
    ctx->pc = 0x80184C14u;
    // 80184C14: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184C18:
    ctx->pc = 0x80184C18u;
    // 80184C18: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_80184C1C:
    ctx->pc = 0x80184C1Cu;
    // 80184C1C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80184C20:
    ctx->pc = 0x80184C20u;
    // 80184C20: bl      0x80170148
    {
            ctx->lr = 0x80184C24u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184C24:
    ctx->pc = 0x80184C24u;
    ctx->downcount -= 8;
    // 80184C24: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184C28:
    ctx->pc = 0x80184C28u;
    // 80184C28: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184C2C:
    ctx->pc = 0x80184C2Cu;
    // 80184C2C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184C30:
    ctx->pc = 0x80184C30u;
    // 80184C30: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184C34:
    ctx->pc = 0x80184C34u;
    // 80184C34: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80184C38:
    ctx->pc = 0x80184C38u;
    // 80184C38: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184C3C:
    ctx->pc = 0x80184C3Cu;
    // 80184C3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184C40:
    ctx->pc = 0x80184C40u;
    ctx->downcount -= 28;
    // 80184C40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184C44:
    ctx->pc = 0x80184C44u;
    // 80184C44: li      r6, 32
    ctx->gpr[6] = (u32)(s32)(32);

label_80184C48:
    ctx->pc = 0x80184C48u;
    // 80184C48: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184C4C:
    ctx->pc = 0x80184C4Cu;
    // 80184C4C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184C50:
    ctx->pc = 0x80184C50u;
    // 80184C50: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_80184C54:
    ctx->pc = 0x80184C54u;
    // 80184C54: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184C58:
    ctx->pc = 0x80184C58u;
    // 80184C58: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184C5C:
    ctx->pc = 0x80184C5Cu;
    // 80184C5C: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184C60:
    ctx->pc = 0x80184C60u;
    // 80184C60: stw     r4, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184C64:
    ctx->pc = 0x80184C64u;
    // 80184C64: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_80184C68:
    ctx->pc = 0x80184C68u;
    // 80184C68: addi    r7, r4, 24576
    ctx->gpr[7] = ctx->gpr[4] + (u32)(s32)(24576);

label_80184C6C:
    ctx->pc = 0x80184C6Cu;
    // 80184C6C: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184C70:
    ctx->pc = 0x80184C70u;
    // 80184C70: lis     r0, 4608
    ctx->gpr[0] = ((u32)(s32)(4608) << 16);

label_80184C74:
    ctx->pc = 0x80184C74u;
    // 80184C74: stw     r0, 24584(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24584);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184C78:
    ctx->pc = 0x80184C78u;
    // 80184C78: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80184C7C:
    ctx->pc = 0x80184C7Cu;
    // 80184C7C: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80184C80:
    ctx->pc = 0x80184C80u;
    // 80184C80: stw     r6, 16(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80184C84:
    ctx->pc = 0x80184C84u;
    // 80184C84: addi    r31, r4, 2256
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(2256);

label_80184C88:
    ctx->pc = 0x80184C88u;
    // 80184C88: stw     r3, 20(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184C8C:
    ctx->pc = 0x80184C8Cu;
    // 80184C8C: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184C90:
    ctx->pc = 0x80184C90u;
    // 80184C90: stw     r6, 24(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80184C94:
    ctx->pc = 0x80184C94u;
    // 80184C94: stw     r0, 28(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184C98:
    ctx->pc = 0x80184C98u;
    // 80184C98: lwz     r0, 248(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184C9C:
    ctx->pc = 0x80184C9Cu;
    // 80184C9C: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184CA0:
    ctx->pc = 0x80184CA0u;
    // 80184CA0: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_80184CA4:
    ctx->pc = 0x80184CA4u;
    // 80184CA4: bl      0x8016FEEC
    {
            ctx->lr = 0x80184CA8u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_80184CA8:
    ctx->pc = 0x80184CA8u;
    ctx->downcount -= 6;
    // 80184CA8: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184CAC:
    ctx->pc = 0x80184CACu;
    // 80184CAC: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_80184CB0:
    ctx->pc = 0x80184CB0u;
    // 80184CB0: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184CB4:
    ctx->pc = 0x80184CB4u;
    // 80184CB4: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_80184CB8:
    ctx->pc = 0x80184CB8u;
    // 80184CB8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80184CBC:
    ctx->pc = 0x80184CBCu;
    // 80184CBC: bl      0x80170148
    {
            ctx->lr = 0x80184CC0u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184CC0:
    ctx->pc = 0x80184CC0u;
    ctx->downcount -= 8;
    // 80184CC0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184CC4:
    ctx->pc = 0x80184CC4u;
    // 80184CC4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184CC8:
    ctx->pc = 0x80184CC8u;
    // 80184CC8: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184CCC:
    ctx->pc = 0x80184CCCu;
    // 80184CCC: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184CD0:
    ctx->pc = 0x80184CD0u;
    // 80184CD0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80184CD4:
    ctx->pc = 0x80184CD4u;
    // 80184CD4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184CD8:
    ctx->pc = 0x80184CD8u;
    // 80184CD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184CDC:
    ctx->pc = 0x80184CDCu;
    ctx->downcount -= 27;
    // 80184CDC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184CE0:
    ctx->pc = 0x80184CE0u;
    // 80184CE0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184CE4:
    ctx->pc = 0x80184CE4u;
    // 80184CE4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184CE8:
    ctx->pc = 0x80184CE8u;
    // 80184CE8: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184CEC:
    ctx->pc = 0x80184CECu;
    // 80184CEC: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184CF0:
    ctx->pc = 0x80184CF0u;
    // 80184CF0: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184CF4:
    ctx->pc = 0x80184CF4u;
    // 80184CF4: stw     r6, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80184CF8:
    ctx->pc = 0x80184CF8u;
    // 80184CF8: lis     r6, -13312
    ctx->gpr[6] = ((u32)(s32)(-13312) << 16);

label_80184CFC:
    ctx->pc = 0x80184CFCu;
    // 80184CFC: addi    r6, r6, 24576
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(24576);

label_80184D00:
    ctx->pc = 0x80184D00u;
    // 80184D00: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184D04:
    ctx->pc = 0x80184D04u;
    // 80184D04: oris    r0, r3, 0xE100
    ctx->gpr[0] = ctx->gpr[3] | (0xE100u << 16);

label_80184D08:
    ctx->pc = 0x80184D08u;
    // 80184D08: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80184D0C:
    ctx->pc = 0x80184D0Cu;
    // 80184D0C: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184D10:
    ctx->pc = 0x80184D10u;
    // 80184D10: rlwinm r0, r5, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 30u) & 0x3FFFFFFFu;
    }

label_80184D14:
    ctx->pc = 0x80184D14u;
    // 80184D14: addi    r31, r3, 2256
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2256);

label_80184D18:
    ctx->pc = 0x80184D18u;
    // 80184D18: stw     r0, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184D1C:
    ctx->pc = 0x80184D1Cu;
    // 80184D1C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184D20:
    ctx->pc = 0x80184D20u;
    // 80184D20: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184D24:
    ctx->pc = 0x80184D24u;
    // 80184D24: stw     r4, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184D28:
    ctx->pc = 0x80184D28u;
    // 80184D28: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80184D2C:
    ctx->pc = 0x80184D2Cu;
    // 80184D2C: stw     r0, 28(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184D30:
    ctx->pc = 0x80184D30u;
    // 80184D30: lwz     r0, 248(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184D34:
    ctx->pc = 0x80184D34u;
    // 80184D34: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184D38:
    ctx->pc = 0x80184D38u;
    // 80184D38: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_80184D3C:
    ctx->pc = 0x80184D3Cu;
    // 80184D3C: bl      0x8016FEEC
    {
            ctx->lr = 0x80184D40u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_80184D40:
    ctx->pc = 0x80184D40u;
    ctx->downcount -= 6;
    // 80184D40: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184D44:
    ctx->pc = 0x80184D44u;
    // 80184D44: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_80184D48:
    ctx->pc = 0x80184D48u;
    // 80184D48: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184D4C:
    ctx->pc = 0x80184D4Cu;
    // 80184D4C: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_80184D50:
    ctx->pc = 0x80184D50u;
    // 80184D50: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80184D54:
    ctx->pc = 0x80184D54u;
    // 80184D54: bl      0x80170148
    {
            ctx->lr = 0x80184D58u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184D58:
    ctx->pc = 0x80184D58u;
    ctx->downcount -= 8;
    // 80184D58: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184D5C:
    ctx->pc = 0x80184D5Cu;
    // 80184D5C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184D60:
    ctx->pc = 0x80184D60u;
    // 80184D60: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184D64:
    ctx->pc = 0x80184D64u;
    // 80184D64: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184D68:
    ctx->pc = 0x80184D68u;
    // 80184D68: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80184D6C:
    ctx->pc = 0x80184D6Cu;
    // 80184D6C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184D70:
    ctx->pc = 0x80184D70u;
    // 80184D70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184D74:
    ctx->pc = 0x80184D74u;
    ctx->downcount -= 24;
    // 80184D74: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184D78:
    ctx->pc = 0x80184D78u;
    // 80184D78: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184D7C:
    ctx->pc = 0x80184D7Cu;
    // 80184D7C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184D80:
    ctx->pc = 0x80184D80u;
    // 80184D80: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184D84:
    ctx->pc = 0x80184D84u;
    // 80184D84: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184D88:
    ctx->pc = 0x80184D88u;
    // 80184D88: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184D8C:
    ctx->pc = 0x80184D8Cu;
    // 80184D8C: stw     r4, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184D90:
    ctx->pc = 0x80184D90u;
    // 80184D90: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_80184D94:
    ctx->pc = 0x80184D94u;
    // 80184D94: addi    r4, r4, 24576
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(24576);

label_80184D98:
    ctx->pc = 0x80184D98u;
    // 80184D98: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184D9C:
    ctx->pc = 0x80184D9Cu;
    // 80184D9C: oris    r0, r3, 0xE200
    ctx->gpr[0] = ctx->gpr[3] | (0xE200u << 16);

label_80184DA0:
    ctx->pc = 0x80184DA0u;
    // 80184DA0: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80184DA4:
    ctx->pc = 0x80184DA4u;
    // 80184DA4: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184DA8:
    ctx->pc = 0x80184DA8u;
    // 80184DA8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184DAC:
    ctx->pc = 0x80184DACu;
    // 80184DAC: addi    r31, r3, 2256
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2256);

label_80184DB0:
    ctx->pc = 0x80184DB0u;
    // 80184DB0: stw     r0, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184DB4:
    ctx->pc = 0x80184DB4u;
    // 80184DB4: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80184DB8:
    ctx->pc = 0x80184DB8u;
    // 80184DB8: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184DBC:
    ctx->pc = 0x80184DBCu;
    // 80184DBC: lwz     r0, 248(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184DC0:
    ctx->pc = 0x80184DC0u;
    // 80184DC0: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184DC4:
    ctx->pc = 0x80184DC4u;
    // 80184DC4: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_80184DC8:
    ctx->pc = 0x80184DC8u;
    // 80184DC8: bl      0x8016FEEC
    {
            ctx->lr = 0x80184DCCu;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_80184DCC:
    ctx->pc = 0x80184DCCu;
    ctx->downcount -= 6;
    // 80184DCC: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184DD0:
    ctx->pc = 0x80184DD0u;
    // 80184DD0: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_80184DD4:
    ctx->pc = 0x80184DD4u;
    // 80184DD4: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184DD8:
    ctx->pc = 0x80184DD8u;
    // 80184DD8: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_80184DDC:
    ctx->pc = 0x80184DDCu;
    // 80184DDC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80184DE0:
    ctx->pc = 0x80184DE0u;
    // 80184DE0: bl      0x80170148
    {
            ctx->lr = 0x80184DE4u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184DE4:
    ctx->pc = 0x80184DE4u;
    ctx->downcount -= 8;
    // 80184DE4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184DE8:
    ctx->pc = 0x80184DE8u;
    // 80184DE8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184DEC:
    ctx->pc = 0x80184DECu;
    // 80184DEC: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184DF0:
    ctx->pc = 0x80184DF0u;
    // 80184DF0: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184DF4:
    ctx->pc = 0x80184DF4u;
    // 80184DF4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80184DF8:
    ctx->pc = 0x80184DF8u;
    // 80184DF8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184DFC:
    ctx->pc = 0x80184DFCu;
    // 80184DFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184E00:
    ctx->pc = 0x80184E00u;
    ctx->downcount -= 10;
    // 80184E00: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184E04:
    ctx->pc = 0x80184E04u;
    // 80184E04: cmpwi   r3, 0
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

label_80184E08:
    ctx->pc = 0x80184E08u;
    // 80184E08: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184E0C:
    ctx->pc = 0x80184E0Cu;
    // 80184E0C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80184E10:
    ctx->pc = 0x80184E10u;
    // 80184E10: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184E14:
    ctx->pc = 0x80184E14u;
    // 80184E14: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184E18:
    ctx->pc = 0x80184E18u;
    // 80184E18: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184E1C:
    ctx->pc = 0x80184E1Cu;
    // 80184E1C: stw     r5, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80184E20:
    ctx->pc = 0x80184E20u;
    // 80184E20: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184E24:
    ctx->pc = 0x80184E24u;
    // 80184E24: bc    12, 2, 0x80184E2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80184E2C;
        }
    }

label_80184E28:
    ctx->pc = 0x80184E28u;
    ctx->downcount -= 1;
    // 80184E28: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_80184E2C:
    ctx->pc = 0x80184E2Cu;
    ctx->downcount -= 17;
    // 80184E2C: oris    r0, r0, 0xE400
    ctx->gpr[0] = ctx->gpr[0] | (0xE400u << 16);

label_80184E30:
    ctx->pc = 0x80184E30u;
    // 80184E30: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80184E34:
    ctx->pc = 0x80184E34u;
    // 80184E34: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80184E38:
    ctx->pc = 0x80184E38u;
    // 80184E38: addi    r3, r3, 24576
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(24576);

label_80184E3C:
    ctx->pc = 0x80184E3Cu;
    // 80184E3C: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184E40:
    ctx->pc = 0x80184E40u;
    // 80184E40: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184E44:
    ctx->pc = 0x80184E44u;
    // 80184E44: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80184E48:
    ctx->pc = 0x80184E48u;
    // 80184E48: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184E4C:
    ctx->pc = 0x80184E4Cu;
    // 80184E4C: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80184E50:
    ctx->pc = 0x80184E50u;
    // 80184E50: addi    r31, r3, 2256
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2256);

label_80184E54:
    ctx->pc = 0x80184E54u;
    // 80184E54: lwz     r0, 248(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184E58:
    ctx->pc = 0x80184E58u;
    // 80184E58: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184E5C:
    ctx->pc = 0x80184E5Cu;
    // 80184E5C: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184E60:
    ctx->pc = 0x80184E60u;
    // 80184E60: mulli   r30, r0, 10
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)10);

label_80184E64:
    ctx->pc = 0x80184E64u;
    // 80184E64: bl      0x8016FEEC
    {
            ctx->lr = 0x80184E68u;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_80184E68:
    ctx->pc = 0x80184E68u;
    ctx->downcount -= 6;
    // 80184E68: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80184E6C:
    ctx->pc = 0x80184E6Cu;
    // 80184E6C: addi    r7, r3, 17200
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(17200);

label_80184E70:
    ctx->pc = 0x80184E70u;
    // 80184E70: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80184E74:
    ctx->pc = 0x80184E74u;
    // 80184E74: addi    r6, r30, 0
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(0);

label_80184E78:
    ctx->pc = 0x80184E78u;
    // 80184E78: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80184E7C:
    ctx->pc = 0x80184E7Cu;
    // 80184E7C: bl      0x80170148
    {
            ctx->lr = 0x80184E80u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80184E80:
    ctx->pc = 0x80184E80u;
    ctx->downcount -= 8;
    // 80184E80: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184E84:
    ctx->pc = 0x80184E84u;
    // 80184E84: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80184E88:
    ctx->pc = 0x80184E88u;
    // 80184E88: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184E8C:
    ctx->pc = 0x80184E8Cu;
    // 80184E8C: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184E90:
    ctx->pc = 0x80184E90u;
    // 80184E90: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80184E94:
    ctx->pc = 0x80184E94u;
    // 80184E94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184E98:
    ctx->pc = 0x80184E98u;
    // 80184E98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184E9C:
    ctx->pc = 0x80184E9Cu;
    ctx->downcount -= 23;
    // 80184E9C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184EA0:
    ctx->pc = 0x80184EA0u;
    // 80184EA0: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_80184EA4:
    ctx->pc = 0x80184EA4u;
    // 80184EA4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184EA8:
    ctx->pc = 0x80184EA8u;
    // 80184EA8: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80184EAC:
    ctx->pc = 0x80184EACu;
    // 80184EAC: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184EB0:
    ctx->pc = 0x80184EB0u;
    // 80184EB0: stmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80184EB4:
    ctx->pc = 0x80184EB4u;
    // 80184EB4: addi    r31, r4, 12288
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(12288);

label_80184EB8:
    ctx->pc = 0x80184EB8u;
    // 80184EB8: stw     r0, 24580(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24580);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184EBC:
    ctx->pc = 0x80184EBCu;
    // 80184EBC: lwz     r30, 12324(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12324);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184EC0:
    ctx->pc = 0x80184EC0u;
    // 80184EC0: rlwinm r0, r30, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0xFFFFFFFBu;
    }

label_80184EC4:
    ctx->pc = 0x80184EC4u;
    // 80184EC4: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_80184EC8:
    ctx->pc = 0x80184EC8u;
    // 80184EC8: stwu     r0, 36(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
        ctx->gpr[31] = ea;
    }

label_80184ECC:
    ctx->pc = 0x80184ECCu;
    // 80184ECC: bl      0x8017A0AC
    {
            ctx->lr = 0x80184ED0u;
            ctx->pc = 0x8017A0ACu;
            return;
    }

label_80184ED0:
    ctx->pc = 0x80184ED0u;
    ctx->downcount -= 18;
    // 80184ED0: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_80184ED4:
    ctx->pc = 0x80184ED4u;
    // 80184ED4: lwz     r0, 248(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184ED8:
    ctx->pc = 0x80184ED8u;
    // 80184ED8: lis     r5, 17180
    ctx->gpr[5] = ((u32)(s32)(17180) << 16);

label_80184EDC:
    ctx->pc = 0x80184EDCu;
    // 80184EDC: addi    r5, r5, -8573
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-8573);

label_80184EE0:
    ctx->pc = 0x80184EE0u;
    // 80184EE0: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80184EE4:
    ctx->pc = 0x80184EE4u;
    // 80184EE4: mulhwu   r0, r5, r0
    {
        u64 product = (u64)ctx->gpr[5] * (u64)ctx->gpr[0];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_80184EE8:
    ctx->pc = 0x80184EE8u;
    // 80184EE8: rlwinm r0, r0, 17, 15, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x0001FFFFu;
    }

label_80184EEC:
    ctx->pc = 0x80184EECu;
    // 80184EEC: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_80184EF0:
    ctx->pc = 0x80184EF0u;
    // 80184EF0: addi    r26, r4, 0
    ctx->gpr[26] = ctx->gpr[4] + (u32)(s32)(0);

label_80184EF4:
    ctx->pc = 0x80184EF4u;
    // 80184EF4: addi    r27, r3, 0
    ctx->gpr[27] = ctx->gpr[3] + (u32)(s32)(0);

label_80184EF8:
    ctx->pc = 0x80184EF8u;
    // 80184EF8: rlwinm r28, r0, 29, 3, 31
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x1FFFFFFFu;
    }

label_80184EFC:
    ctx->pc = 0x80184EFCu;
    // 80184EFC: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80184F00:
    ctx->downcount -= 1;
    // 80184F00: bl      0x8017A0AC
    {
            ctx->lr = 0x80184F04u;
            ctx->pc = 0x8017A0ACu;
            return;
    }

label_80184F04:
    ctx->downcount -= 9;
    // 80184F04: subfc   r5, r26, r4
    {
        u32 a = ~ctx->gpr[26];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[5] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184F08:
    // 80184F08: subfe   r0, r27, r3
    {
        u32 a = ~ctx->gpr[27];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184F0C:
    // 80184F0C: xoris   r4, r0, 0x8000
    ctx->gpr[4] = ctx->gpr[0] ^ (0x8000u << 16);

label_80184F10:
    // 80184F10: xoris   r3, r29, 0x8000
    ctx->gpr[3] = ctx->gpr[29] ^ (0x8000u << 16);

label_80184F14:
    // 80184F14: subfc   r0, r28, r5
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[5];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184F18:
    // 80184F18: subfe   r3, r3, r4
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184F1C:
    // 80184F1C: subfe   r3, r4, r4
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80184F20:
    // 80184F20: neg.  r3, r3
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

label_80184F24:
    // 80184F24: bc    4, 2, 0x80184F00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80184F00u;
                return;
            }
            goto label_80184F00;
        }
    }

label_80184F28:
    ctx->pc = 0x80184F28u;
    ctx->downcount -= 5;
    // 80184F28: ori     r0, r30, 0x0005
    ctx->gpr[0] = ctx->gpr[30] | 0x0005u;

label_80184F2C:
    ctx->pc = 0x80184F2Cu;
    // 80184F2C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184F30:
    ctx->pc = 0x80184F30u;
    // 80184F30: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184F34:
    ctx->pc = 0x80184F34u;
    // 80184F34: stw     r0, -26552(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26552);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184F38:
    ctx->pc = 0x80184F38u;
    // 80184F38: bl      0x8017A0AC
    {
            ctx->lr = 0x80184F3Cu;
            ctx->pc = 0x8017A0ACu;
            return;
    }

label_80184F3C:
    ctx->pc = 0x80184F3Cu;
    ctx->downcount -= 18;
    // 80184F3C: stw     r4, -26556(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26556);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184F40:
    ctx->pc = 0x80184F40u;
    // 80184F40: stw     r3, -26560(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26560);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184F44:
    ctx->pc = 0x80184F44u;
    // 80184F44: lmw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80184F48:
    ctx->pc = 0x80184F48u;
    // 80184F48: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184F4C:
    ctx->pc = 0x80184F4Cu;
    // 80184F4C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80184F50:
    ctx->pc = 0x80184F50u;
    // 80184F50: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184F54:
    ctx->pc = 0x80184F54u;
    // 80184F54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184F58:
    ctx->pc = 0x80184F58u;
    ctx->downcount -= 7;
    // 80184F58: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184F5C:
    ctx->pc = 0x80184F5Cu;
    // 80184F5C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184F60:
    ctx->pc = 0x80184F60u;
    // 80184F60: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184F64:
    ctx->pc = 0x80184F64u;
    // 80184F64: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80184F68:
    ctx->pc = 0x80184F68u;
    // 80184F68: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184F6C:
    ctx->pc = 0x80184F6Cu;
    // 80184F6C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80184F70:
    ctx->pc = 0x80184F70u;
    // 80184F70: bl      0x80173F2C
    {
            ctx->lr = 0x80184F74u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80184F74:
    ctx->pc = 0x80184F74u;
    ctx->downcount -= 3;
    // 80184F74: lwz     r31, -26564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26564);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184F78:
    ctx->pc = 0x80184F78u;
    // 80184F78: stw     r30, -26564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26564);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80184F7C:
    ctx->pc = 0x80184F7Cu;
    // 80184F7C: bl      0x80173F54
    {
            ctx->lr = 0x80184F80u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80184F80:
    ctx->pc = 0x80184F80u;
    ctx->downcount -= 8;
    // 80184F80: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80184F84:
    ctx->pc = 0x80184F84u;
    // 80184F84: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184F88:
    ctx->pc = 0x80184F88u;
    // 80184F88: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80184F8C:
    ctx->pc = 0x80184F8Cu;
    // 80184F8C: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80184F90:
    ctx->pc = 0x80184F90u;
    // 80184F90: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80184F94:
    ctx->pc = 0x80184F94u;
    // 80184F94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80184F98:
    ctx->pc = 0x80184F98u;
    // 80184F98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184F9C:
    ctx->pc = 0x80184F9Cu;
    ctx->downcount -= 7;
    // 80184F9C: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80184FA0:
    ctx->pc = 0x80184FA0u;
    // 80184FA0: lwz     r4, 24576(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24576);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80184FA4:
    ctx->pc = 0x80184FA4u;
    // 80184FA4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184FA8:
    ctx->pc = 0x80184FA8u;
    // 80184FA8: ori     r4, r4, 0x0041
    ctx->gpr[4] = ctx->gpr[4] | 0x0041u;

label_80184FAC:
    ctx->pc = 0x80184FACu;
    // 80184FAC: stw     r4, 24576(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24576);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80184FB0:
    ctx->pc = 0x80184FB0u;
    // 80184FB0: stw     r0, -26544(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26544);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184FB4:
    ctx->pc = 0x80184FB4u;
    // 80184FB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80184FB8:
    ctx->pc = 0x80184FB8u;
    ctx->downcount -= 9;
    // 80184FB8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80184FBC:
    ctx->pc = 0x80184FBCu;
    // 80184FBC: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_80184FC0:
    ctx->pc = 0x80184FC0u;
    // 80184FC0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184FC4:
    ctx->pc = 0x80184FC4u;
    // 80184FC4: addi    r3, r4, 24576
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(24576);

label_80184FC8:
    ctx->pc = 0x80184FC8u;
    // 80184FC8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80184FCC:
    ctx->pc = 0x80184FCCu;
    // 80184FCC: lwz     r0, -26572(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26572);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184FD0:
    ctx->pc = 0x80184FD0u;
    // 80184FD0: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80184FD4:
    ctx->pc = 0x80184FD4u;
    // 80184FD4: cmplw   r3, r0
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

label_80184FD8:
    ctx->pc = 0x80184FD8u;
    // 80184FD8: bc    4, 0, 0x80184FF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80184FF4;
        }
    }

label_80184FDC:
    ctx->pc = 0x80184FDCu;
    ctx->downcount -= 6;
    // 80184FDC: lwz     r3, 24576(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24576);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80184FE0:
    ctx->pc = 0x80184FE0u;
    // 80184FE0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80184FE4:
    ctx->pc = 0x80184FE4u;
    // 80184FE4: ori     r3, r3, 0x0041
    ctx->gpr[3] = ctx->gpr[3] | 0x0041u;

label_80184FE8:
    ctx->pc = 0x80184FE8u;
    // 80184FE8: stw     r3, 24576(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24576);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80184FEC:
    ctx->pc = 0x80184FECu;
    // 80184FEC: stw     r0, -26544(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26544);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80184FF0:
    ctx->pc = 0x80184FF0u;
    // 80184FF0: b       0x8018501C
    {
            goto label_8018501C;
    }

label_80184FF4:
    ctx->pc = 0x80184FF4u;
    ctx->downcount -= 16;
    // 80184FF4: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80184FF8:
    ctx->pc = 0x80184FF8u;
    // 80184FF8: lwz     r0, 248(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(248);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80184FFC:
    ctx->pc = 0x80184FFCu;
    // 80184FFC: lis     r3, 4194
    ctx->gpr[3] = ((u32)(s32)(4194) << 16);

label_80185000:
    ctx->pc = 0x80185000u;
    // 80185000: addi    r3, r3, 19923
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(19923);

label_80185004:
    ctx->pc = 0x80185004u;
    // 80185004: rlwinm r0, r0, 30, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_80185008:
    ctx->pc = 0x80185008u;
    // 80185008: mulhwu   r0, r3, r0
    {
        u64 product = (u64)ctx->gpr[3] * (u64)ctx->gpr[0];
        ctx->gpr[0] = (u32)(product >> 32);
    }

label_8018500C:
    ctx->pc = 0x8018500Cu;
    // 8018500C: rlwinm r0, r0, 26, 6, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x03FFFFFFu;
    }

label_80185010:
    ctx->pc = 0x80185010u;
    // 80185010: mulli   r4, r0, 20
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_80185014:
    ctx->pc = 0x80185014u;
    // 80185014: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80185018:
    ctx->pc = 0x80185018u;
    // 80185018: bl      0x8018502C
    {
            ctx->lr = 0x8018501Cu;
            goto label_8018502C;
    }

label_8018501C:
    ctx->pc = 0x8018501Cu;
    ctx->downcount -= 5;
    // 8018501C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185020:
    ctx->pc = 0x80185020u;
    // 80185020: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80185024:
    ctx->pc = 0x80185024u;
    // 80185024: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80185028:
    ctx->pc = 0x80185028u;
    // 80185028: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018502C:
    ctx->pc = 0x8018502Cu;
    ctx->downcount -= 12;
    // 8018502C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80185030:
    ctx->pc = 0x80185030u;
    // 80185030: lis     r5, -32697
    ctx->gpr[5] = ((u32)(s32)(-32697) << 16);

label_80185034:
    ctx->pc = 0x80185034u;
    // 80185034: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185038:
    ctx->pc = 0x80185038u;
    // 80185038: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018503C:
    ctx->pc = 0x8018503Cu;
    // 8018503C: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80185040:
    ctx->pc = 0x80185040u;
    // 80185040: addi    r31, r5, 2296
    ctx->gpr[31] = ctx->gpr[5] + (u32)(s32)(2296);

label_80185044:
    ctx->pc = 0x80185044u;
    // 80185044: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80185048:
    ctx->pc = 0x80185048u;
    // 80185048: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_8018504C:
    ctx->pc = 0x8018504Cu;
    // 8018504C: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80185050:
    ctx->pc = 0x80185050u;
    // 80185050: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185054:
    ctx->pc = 0x80185054u;
    // 80185054: addi    r29, r4, 0
    ctx->gpr[29] = ctx->gpr[4] + (u32)(s32)(0);

label_80185058:
    ctx->pc = 0x80185058u;
    // 80185058: bl      0x8016FEEC
    {
            ctx->lr = 0x8018505Cu;
            ctx->pc = 0x8016FEECu;
            return;
    }

label_8018505C:
    ctx->pc = 0x8018505Cu;
    ctx->downcount -= 6;
    // 8018505C: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80185060:
    ctx->pc = 0x80185060u;
    // 80185060: addi    r7, r3, 20408
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(20408);

label_80185064:
    ctx->pc = 0x80185064u;
    // 80185064: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_80185068:
    ctx->pc = 0x80185068u;
    // 80185068: addi    r6, r29, 0
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(0);

label_8018506C:
    ctx->pc = 0x8018506Cu;
    // 8018506C: addi    r5, r30, 0
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(0);

label_80185070:
    ctx->pc = 0x80185070u;
    // 80185070: bl      0x80170148
    {
            ctx->lr = 0x80185074u;
            ctx->pc = 0x80170148u;
            return;
    }

label_80185074:
    ctx->pc = 0x80185074u;
    ctx->downcount -= 8;
    // 80185074: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185078:
    ctx->pc = 0x80185078u;
    // 80185078: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018507C:
    ctx->pc = 0x8018507Cu;
    // 8018507C: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80185080:
    ctx->pc = 0x80185080u;
    // 80185080: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80185084:
    ctx->pc = 0x80185084u;
    // 80185084: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80185088:
    ctx->pc = 0x80185088u;
    // 80185088: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018508C:
    ctx->pc = 0x8018508Cu;
    // 8018508C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185090:
    ctx->pc = 0x80185090u;
    ctx->downcount -= 5;
    // 80185090: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80185094:
    ctx->pc = 0x80185094u;
    // 80185094: stw     r0, -26576(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26576);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185098:
    ctx->pc = 0x80185098u;
    // 80185098: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8018509C:
    ctx->pc = 0x8018509Cu;
    // 8018509C: stw     r0, -26544(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26544);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801850A0:
    ctx->pc = 0x801850A0u;
    // 801850A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801850A4:
    ctx->pc = 0x801850A4u;
    ctx->downcount -= 6;
    // 801850A4: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_801850A8:
    ctx->pc = 0x801850A8u;
    // 801850A8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801850AC:
    ctx->pc = 0x801850ACu;
    // 801850AC: stw     r0, 24580(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24580);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801850B0:
    ctx->pc = 0x801850B0u;
    // 801850B0: lwz     r3, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801850B4:
    ctx->pc = 0x801850B4u;
    // 801850B4: stw     r0, -26568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26568);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801850B8:
    ctx->pc = 0x801850B8u;
    // 801850B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801850BC:
    ctx->pc = 0x801850BCu;
    ctx->downcount -= 4;
    // 801850BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801850C0:
    ctx->pc = 0x801850C0u;
    // 801850C0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801850C4:
    ctx->pc = 0x801850C4u;
    // 801850C4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801850C8:
    ctx->pc = 0x801850C8u;
    // 801850C8: bl      0x8017A0AC
    {
            ctx->lr = 0x801850CCu;
            ctx->pc = 0x8017A0ACu;
            return;
    }

label_801850CC:
    ctx->pc = 0x801850CCu;
    ctx->downcount -= 26;
    // 801850CC: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_801850D0:
    ctx->pc = 0x801850D0u;
    // 801850D0: lwz     r7, -26560(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26560);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801850D4:
    ctx->pc = 0x801850D4u;
    // 801850D4: lwz     r6, 248(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(248);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801850D8:
    ctx->pc = 0x801850D8u;
    // 801850D8: lis     r5, 4194
    ctx->gpr[5] = ((u32)(s32)(4194) << 16);

label_801850DC:
    ctx->pc = 0x801850DCu;
    // 801850DC: addi    r5, r5, 19923
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(19923);

label_801850E0:
    ctx->pc = 0x801850E0u;
    // 801850E0: lwz     r8, -26556(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26556);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801850E4:
    ctx->pc = 0x801850E4u;
    // 801850E4: rlwinm r6, r6, 30, 2, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 30u) & 0x3FFFFFFFu;
    }

label_801850E8:
    ctx->pc = 0x801850E8u;
    // 801850E8: mulhwu   r5, r5, r6
    {
        u64 product = (u64)ctx->gpr[5] * (u64)ctx->gpr[6];
        ctx->gpr[5] = (u32)(product >> 32);
    }

label_801850EC:
    ctx->pc = 0x801850ECu;
    // 801850EC: rlwinm r5, r5, 26, 6, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 26u) & 0x03FFFFFFu;
    }

label_801850F0:
    ctx->pc = 0x801850F0u;
    // 801850F0: mulli   r5, r5, 100
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[5] * (s64)(s32)100);

label_801850F4:
    ctx->pc = 0x801850F4u;
    // 801850F4: subfc   r6, r8, r4
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[6] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801850F8:
    ctx->pc = 0x801850F8u;
    // 801850F8: subfe   r3, r7, r3
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801850FC:
    ctx->pc = 0x801850FCu;
    // 801850FC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80185100:
    ctx->pc = 0x80185100u;
    // 80185100: xoris   r4, r3, 0x8000
    ctx->gpr[4] = ctx->gpr[3] ^ (0x8000u << 16);

label_80185104:
    ctx->pc = 0x80185104u;
    // 80185104: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_80185108:
    ctx->pc = 0x80185108u;
    // 80185108: subfc   r0, r5, r6
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[6];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018510C:
    ctx->pc = 0x8018510Cu;
    // 8018510C: subfe   r3, r3, r4
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185110:
    ctx->pc = 0x80185110u;
    // 80185110: subfe   r3, r4, r4
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185114:
    ctx->pc = 0x80185114u;
    // 80185114: neg.  r3, r3
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

label_80185118:
    ctx->pc = 0x80185118u;
    // 80185118: bc    12, 2, 0x80185124
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80185124;
        }
    }

label_8018511C:
    ctx->pc = 0x8018511Cu;
    ctx->downcount -= 2;
    // 8018511C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80185120:
    ctx->pc = 0x80185120u;
    // 80185120: b       0x80185140
    {
            goto label_80185140;
    }

label_80185124:
    ctx->pc = 0x80185124u;
    ctx->downcount -= 4;
    // 80185124: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80185128:
    ctx->pc = 0x80185128u;
    // 80185128: lwz     r0, 24580(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24580);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018512C:
    ctx->pc = 0x8018512Cu;
    // 8018512C: rlwinm. r0, r0, 0, 31, 31
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

label_80185130:
    ctx->pc = 0x80185130u;
    // 80185130: bc    12, 2, 0x8018513C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018513C;
        }
    }

label_80185134:
    ctx->pc = 0x80185134u;
    ctx->downcount -= 2;
    // 80185134: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80185138:
    ctx->pc = 0x80185138u;
    // 80185138: b       0x80185140
    {
            goto label_80185140;
    }

label_8018513C:
    ctx->pc = 0x8018513Cu;
    ctx->downcount -= 1;
    // 8018513C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80185140:
    ctx->pc = 0x80185140u;
    ctx->downcount -= 5;
    // 80185140: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185144:
    ctx->pc = 0x80185144u;
    // 80185144: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80185148:
    ctx->pc = 0x80185148u;
    // 80185148: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018514C:
    ctx->pc = 0x8018514Cu;
    // 8018514C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185150:
    ctx->pc = 0x80185150u;
    ctx->downcount -= 8;
    // 80185150: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80185154:
    ctx->pc = 0x80185154u;
    // 80185154: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185158:
    ctx->pc = 0x80185158u;
    // 80185158: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018515C:
    ctx->pc = 0x8018515Cu;
    // 8018515C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80185160:
    ctx->pc = 0x80185160u;
    // 80185160: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80185164:
    ctx->pc = 0x80185164u;
    // 80185164: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80185168:
    ctx->pc = 0x80185168u;
    // 80185168: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_8018516C:
    ctx->pc = 0x8018516Cu;
    // 8018516C: bl      0x80173F2C
    {
            ctx->lr = 0x80185170u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80185170:
    ctx->pc = 0x80185170u;
    ctx->downcount -= 3;
    // 80185170: stw     r30, -26540(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26540);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80185174:
    ctx->pc = 0x80185174u;
    // 80185174: stw     r31, -26536(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26536);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80185178:
    ctx->pc = 0x80185178u;
    // 80185178: bl      0x80173F54
    {
            ctx->lr = 0x8018517Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018517C:
    ctx->pc = 0x8018517Cu;
    ctx->downcount -= 7;
    // 8018517C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185180:
    ctx->pc = 0x80185180u;
    // 80185180: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80185184:
    ctx->pc = 0x80185184u;
    // 80185184: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80185188:
    ctx->pc = 0x80185188u;
    // 80185188: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8018518C:
    ctx->pc = 0x8018518Cu;
    // 8018518C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80185190:
    ctx->pc = 0x80185190u;
    // 80185190: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185194:
    ctx->pc = 0x80185194u;
    ctx->downcount -= 2;
    // 80185194: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80185198:
    ctx->pc = 0x80185198u;
    // 80185198: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018519C:
    ctx->pc = 0x8018519Cu;
    ctx->downcount -= 9;
    // 8018519C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801851A0:
    ctx->pc = 0x801851A0u;
    // 801851A0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_801851A4:
    ctx->pc = 0x801851A4u;
    // 801851A4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801851A8:
    ctx->pc = 0x801851A8u;
    // 801851A8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801851AC:
    ctx->pc = 0x801851ACu;
    // 801851AC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801851B0:
    ctx->pc = 0x801851B0u;
    // 801851B0: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_801851B4:
    ctx->pc = 0x801851B4u;
    // 801851B4: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801851B8:
    ctx->pc = 0x801851B8u;
    // 801851B8: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_801851BC:
    ctx->pc = 0x801851BCu;
    // 801851BC: bl      0x801632BC
    {
            ctx->lr = 0x801851C0u;
            ctx->pc = 0x801632BCu;
            return;
    }

label_801851C0:
    ctx->pc = 0x801851C0u;
    ctx->downcount -= 5;
    // 801851C0: cntlzw r3, r4
    {
        u32 v = ctx->gpr[4];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_801851C4:
    ctx->pc = 0x801851C4u;
    // 801851C4: cmpwi   r3, 32
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801851C8:
    ctx->pc = 0x801851C8u;
    // 801851C8: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_801851CC:
    ctx->pc = 0x801851CCu;
    // 801851CC: and   r0, r30, r0
    {
        ctx->gpr[0] = ctx->gpr[30] & ctx->gpr[0];
    }

label_801851D0:
    ctx->pc = 0x801851D0u;
    // 801851D0: bc    4, 0, 0x801851D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801851D8;
        }
    }

label_801851D4:
    ctx->pc = 0x801851D4u;
    ctx->downcount -= 1;
    // 801851D4: b       0x801851E0
    {
            goto label_801851E0;
    }

label_801851D8:
    ctx->pc = 0x801851D8u;
    ctx->downcount -= 2;
    // 801851D8: cntlzw r3, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_801851DC:
    ctx->pc = 0x801851DCu;
    // 801851DC: addi    r3, r3, 32
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(32);

label_801851E0:
    ctx->pc = 0x801851E0u;
    ctx->downcount -= 7;
    // 801851E0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801851E4:
    ctx->pc = 0x801851E4u;
    // 801851E4: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801851E8:
    ctx->pc = 0x801851E8u;
    // 801851E8: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801851EC:
    ctx->pc = 0x801851ECu;
    // 801851EC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801851F0:
    ctx->pc = 0x801851F0u;
    // 801851F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801851F4:
    ctx->pc = 0x801851F4u;
    // 801851F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801851F8:
    ctx->pc = 0x801851F8u;
    ctx->downcount -= 12;
    // 801851F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801851FC:
    ctx->pc = 0x801851FCu;
    // 801851FC: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80185200:
    ctx->pc = 0x80185200u;
    // 80185200: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185204:
    ctx->pc = 0x80185204u;
    // 80185204: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80185208:
    ctx->pc = 0x80185208u;
    // 80185208: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018520C:
    ctx->pc = 0x8018520Cu;
    // 8018520C: addi    r31, r3, 2360
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2360);

label_80185210:
    ctx->pc = 0x80185210u;
    // 80185210: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80185214:
    ctx->pc = 0x80185214u;
    // 80185214: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185218:
    ctx->pc = 0x80185218u;
    // 80185218: stw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8018521C:
    ctx->pc = 0x8018521Cu;
    // 8018521C: lwz     r0, -26456(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26456);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185220:
    ctx->pc = 0x80185220u;
    // 80185220: cmplwi  r0, 0x0001
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

label_80185224:
    ctx->pc = 0x80185224u;
    // 80185224: bc    4, 2, 0x80185234
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185234;
        }
    }

label_80185228:
    ctx->pc = 0x80185228u;
    ctx->downcount -= 1;
    // 80185228: bl      0x80187668
    {
            ctx->lr = 0x8018522Cu;
            ctx->pc = 0x80187668u;
            return;
    }

label_8018522C:
    ctx->pc = 0x8018522Cu;
    ctx->downcount -= 2;
    // 8018522C: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80185230:
    ctx->pc = 0x80185230u;
    // 80185230: bc    12, 2, 0x801852EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801852EC;
        }
    }

label_80185234:
    ctx->pc = 0x80185234u;
    ctx->downcount -= 3;
    // 80185234: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80185238:
    ctx->pc = 0x80185238u;
    // 80185238: addi    r30, r3, 8192
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(8192);

label_8018523C:
    ctx->pc = 0x8018523Cu;
    // 8018523C: b       0x801852B4
    {
            goto label_801852B4;
    }

label_80185240:
    ctx->pc = 0x80185240u;
    ctx->downcount -= 5;
    // 80185240: lwz     r3, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80185244:
    // 80185244: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80185248:
    ctx->pc = 0x80185248u;
    // 80185248: lwz     r28, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8018524C:
    // 8018524C: addi    r4, r28, 0
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(0);

label_80185250:
    // 80185250: bl      0x801632BC
    {
            ctx->lr = 0x80185254u;
            ctx->pc = 0x801632BCu;
            return;
    }

label_80185254:
    ctx->downcount -= 5;
    // 80185254: cntlzw r4, r4
    {
        u32 v = ctx->gpr[4];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[4] = n;
    }

label_80185258:
    // 80185258: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018525C:
    // 8018525C: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80185260:
    // 80185260: and   r0, r28, r0
    {
        ctx->gpr[0] = ctx->gpr[28] & ctx->gpr[0];
    }

label_80185264:
    // 80185264: bc    4, 0, 0x8018526C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018526C;
        }
    }

label_80185268:
    ctx->downcount -= 1;
    // 80185268: b       0x80185274
    {
            goto label_80185274;
    }

label_8018526C:
    ctx->downcount -= 2;
    // 8018526C: cntlzw r3, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_80185270:
    // 80185270: addi    r4, r3, 32
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(32);

label_80185274:
    ctx->downcount -= 8;
    // 80185274: rlwinm r6, r4, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_80185278:
    // 80185278: add   r3, r31, r6
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8018527C:
    ctx->pc = 0x8018527Cu;
    // 8018527C: lhz     r0, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80185280:
    // 80185280: subfic  r5, r4, 63
    {
        u64 res = (u64)(u32)(s32)(63) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80185284:
    // 80185284: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80185288:
    ctx->pc = 0x80185288u;
    // 80185288: sthx    r0, r30, r6
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[6];
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018528C:
    // 8018528C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80185290:
    // 80185290: bl      0x801632C4
    {
            ctx->lr = 0x80185294u;
            ctx->pc = 0x801632C4u;
            return;
    }

label_80185294:
    ctx->pc = 0x80185294u;
    ctx->downcount -= 8;
    // 80185294: lwz     r0, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185298:
    // 80185298: nor   r5, r3, r3
    {
        ctx->gpr[5] = ~(ctx->gpr[3] | ctx->gpr[3]);
    }

label_8018529C:
    // 8018529C: nor   r4, r4, r4
    {
        ctx->gpr[4] = ~(ctx->gpr[4] | ctx->gpr[4]);
    }

label_801852A0:
    ctx->pc = 0x801852A0u;
    // 801852A0: lwz     r3, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801852A4:
    // 801852A4: and   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[5];
    }

label_801852A8:
    // 801852A8: and   r3, r3, r4
    {
        ctx->gpr[3] = ctx->gpr[3] & ctx->gpr[4];
    }

label_801852AC:
    ctx->pc = 0x801852ACu;
    // 801852AC: stw     r3, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801852B0:
    ctx->pc = 0x801852B0u;
    // 801852B0: stw     r0, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801852B4:
    ctx->pc = 0x801852B4u;
    ctx->downcount -= 7;
    // 801852B4: lwz     r0, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801852B8:
    // 801852B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801852BC:
    ctx->pc = 0x801852BCu;
    // 801852BC: lwz     r3, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801852C0:
    // 801852C0: xor   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[4];
    }

label_801852C4:
    // 801852C4: xor   r3, r3, r4
    {
        ctx->gpr[3] = ctx->gpr[3] ^ ctx->gpr[4];
    }

label_801852C8:
    // 801852C8: or.   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801852CC:
    // 801852CC: bc    4, 2, 0x80185240
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80185240u;
                return;
            }
            goto label_80185240;
        }
    }

label_801852D0:
    ctx->pc = 0x801852D0u;
    ctx->downcount -= 7;
    // 801852D0: stw     r4, -26456(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26456);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801852D4:
    ctx->pc = 0x801852D4u;
    // 801852D4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801852D8:
    ctx->pc = 0x801852D8u;
    // 801852D8: lwz     r0, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801852DC:
    ctx->pc = 0x801852DCu;
    // 801852DC: stw     r0, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801852E0:
    ctx->pc = 0x801852E0u;
    // 801852E0: lwz     r0, 280(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(280);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801852E4:
    ctx->pc = 0x801852E4u;
    // 801852E4: stw     r0, -26436(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26436);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801852E8:
    ctx->pc = 0x801852E8u;
    // 801852E8: b       0x801852F0
    {
            goto label_801852F0;
    }

label_801852EC:
    ctx->pc = 0x801852ECu;
    ctx->downcount -= 1;
    // 801852EC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801852F0:
    ctx->pc = 0x801852F0u;
    ctx->downcount -= 9;
    // 801852F0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801852F4:
    ctx->pc = 0x801852F4u;
    // 801852F4: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801852F8:
    ctx->pc = 0x801852F8u;
    // 801852F8: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801852FC:
    ctx->pc = 0x801852FCu;
    // 801852FC: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80185300:
    ctx->pc = 0x80185300u;
    // 80185300: lwz     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80185304:
    ctx->pc = 0x80185304u;
    // 80185304: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80185308:
    ctx->pc = 0x80185308u;
    // 80185308: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018530C:
    ctx->pc = 0x8018530Cu;
    // 8018530C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185310:
    ctx->pc = 0x80185310u;
    ctx->downcount -= 23;
    // 80185310: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80185314:
    ctx->pc = 0x80185314u;
    // 80185314: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80185318:
    ctx->pc = 0x80185318u;
    // 80185318: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018531C:
    ctx->pc = 0x8018531Cu;
    // 8018531C: addi    r5, r3, 8192
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(8192);

label_80185320:
    ctx->pc = 0x80185320u;
    // 80185320: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80185324:
    ctx->pc = 0x80185324u;
    // 80185324: stwu     r1, -760(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-760);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80185328:
    ctx->pc = 0x80185328u;
    // 80185328: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8018532C:
    ctx->pc = 0x8018532Cu;
    // 8018532C: stmw     r27, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80185330:
    ctx->pc = 0x80185330u;
    // 80185330: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_80185334:
    ctx->pc = 0x80185334u;
    // 80185334: addi    r31, r3, 2360
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2360);

label_80185338:
    ctx->pc = 0x80185338u;
    // 80185338: lhzu     r6, 48(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read16(ctx, ea);
        ctx->gpr[5] = ea;
    }

label_8018533C:
    ctx->pc = 0x8018533Cu;
    // 8018533C: rlwinm. r0, r6, 0, 16, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00008000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185340:
    ctx->pc = 0x80185340u;
    // 80185340: bc    12, 2, 0x80185350
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80185350;
        }
    }

label_80185344:
    ctx->pc = 0x80185344u;
    ctx->downcount -= 3;
    // 80185344: rlwinm r0, r6, 0, 17, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFF7FFFu;
    }

label_80185348:
    ctx->pc = 0x80185348u;
    // 80185348: sth     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018534C:
    ctx->pc = 0x8018534Cu;
    // 8018534C: ori     r7, r7, 0x0001
    ctx->gpr[7] = ctx->gpr[7] | 0x0001u;

label_80185350:
    ctx->pc = 0x80185350u;
    ctx->downcount -= 4;
    // 80185350: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80185354:
    ctx->pc = 0x80185354u;
    // 80185354: lhzu     r4, 8244(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8244);
        ctx->gpr[4] = mem_read16(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80185358:
    ctx->pc = 0x80185358u;
    // 80185358: rlwinm. r0, r4, 0, 16, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00008000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018535C:
    ctx->pc = 0x8018535Cu;
    // 8018535C: bc    12, 2, 0x8018536C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018536C;
        }
    }

label_80185360:
    ctx->pc = 0x80185360u;
    ctx->downcount -= 3;
    // 80185360: rlwinm r0, r4, 0, 17, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF7FFFu;
    }

label_80185364:
    ctx->pc = 0x80185364u;
    // 80185364: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185368:
    ctx->pc = 0x80185368u;
    // 80185368: ori     r7, r7, 0x0002
    ctx->gpr[7] = ctx->gpr[7] | 0x0002u;

label_8018536C:
    ctx->pc = 0x8018536Cu;
    ctx->downcount -= 4;
    // 8018536C: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80185370:
    ctx->pc = 0x80185370u;
    // 80185370: lhzu     r4, 8248(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8248);
        ctx->gpr[4] = mem_read16(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80185374:
    ctx->pc = 0x80185374u;
    // 80185374: rlwinm. r0, r4, 0, 16, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00008000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185378:
    ctx->pc = 0x80185378u;
    // 80185378: bc    12, 2, 0x80185388
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80185388;
        }
    }

label_8018537C:
    ctx->pc = 0x8018537Cu;
    ctx->downcount -= 3;
    // 8018537C: rlwinm r0, r4, 0, 17, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF7FFFu;
    }

label_80185380:
    ctx->pc = 0x80185380u;
    // 80185380: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185384:
    ctx->pc = 0x80185384u;
    // 80185384: ori     r7, r7, 0x0004
    ctx->gpr[7] = ctx->gpr[7] | 0x0004u;

label_80185388:
    ctx->pc = 0x80185388u;
    ctx->downcount -= 4;
    // 80185388: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018538C:
    ctx->pc = 0x8018538Cu;
    // 8018538C: lhzu     r4, 8252(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8252);
        ctx->gpr[4] = mem_read16(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80185390:
    ctx->pc = 0x80185390u;
    // 80185390: rlwinm. r0, r4, 0, 16, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00008000u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185394:
    ctx->pc = 0x80185394u;
    // 80185394: bc    12, 2, 0x801853A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801853A4;
        }
    }

label_80185398:
    ctx->pc = 0x80185398u;
    ctx->downcount -= 3;
    // 80185398: rlwinm r0, r4, 0, 17, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFF7FFFu;
    }

label_8018539C:
    ctx->pc = 0x8018539Cu;
    // 8018539C: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801853A0:
    ctx->pc = 0x801853A0u;
    // 801853A0: ori     r7, r7, 0x0008
    ctx->gpr[7] = ctx->gpr[7] | 0x0008u;

label_801853A4:
    ctx->pc = 0x801853A4u;
    ctx->downcount -= 2;
    // 801853A4: rlwinm. r0, r7, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801853A8:
    ctx->pc = 0x801853A8u;
    // 801853A8: bc    4, 2, 0x801853B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801853B4;
        }
    }

label_801853AC:
    ctx->pc = 0x801853ACu;
    ctx->downcount -= 2;
    // 801853AC: rlwinm. r0, r7, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801853B0:
    ctx->pc = 0x801853B0u;
    // 801853B0: bc    12, 2, 0x801853C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801853C0;
        }
    }

label_801853B4:
    ctx->pc = 0x801853B4u;
    ctx->downcount -= 2;
    // 801853B4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801853B8:
    ctx->pc = 0x801853B8u;
    // 801853B8: bl      0x80172284
    {
            ctx->lr = 0x801853BCu;
            ctx->pc = 0x80172284u;
            return;
    }

label_801853BC:
    ctx->pc = 0x801853BCu;
    ctx->downcount -= 1;
    // 801853BC: b       0x80185524
    {
            goto label_80185524;
    }

label_801853C0:
    ctx->pc = 0x801853C0u;
    ctx->downcount -= 5;
    // 801853C0: lwz     r4, -26504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26504);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801853C4:
    ctx->pc = 0x801853C4u;
    // 801853C4: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_801853C8:
    ctx->pc = 0x801853C8u;
    // 801853C8: addi    r0, r4, 1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1);

label_801853CC:
    ctx->pc = 0x801853CCu;
    // 801853CC: stw     r0, -26504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26504);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801853D0:
    ctx->pc = 0x801853D0u;
    // 801853D0: bl      0x8017248C
    {
            ctx->lr = 0x801853D4u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_801853D4:
    ctx->pc = 0x801853D4u;
    ctx->downcount -= 2;
    // 801853D4: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_801853D8:
    ctx->pc = 0x801853D8u;
    // 801853D8: bl      0x80172284
    {
            ctx->lr = 0x801853DCu;
            ctx->pc = 0x80172284u;
            return;
    }

label_801853DC:
    ctx->pc = 0x801853DCu;
    ctx->downcount -= 3;
    // 801853DC: lwz     r12, -26488(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26488);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801853E0:
    ctx->pc = 0x801853E0u;
    // 801853E0: cmplwi  r12, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[12]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801853E4:
    ctx->pc = 0x801853E4u;
    // 801853E4: bc    12, 2, 0x801853F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801853F4;
        }
    }

label_801853E8:
    ctx->pc = 0x801853E8u;
    ctx->downcount -= 4;
    // 801853E8: lwz     r3, -26504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26504);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801853EC:
    ctx->pc = 0x801853ECu;
    // 801853EC: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_801853F0:
    ctx->pc = 0x801853F0u;
    // 801853F0: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801853F4u;
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801853F4:
    ctx->pc = 0x801853F4u;
    ctx->downcount -= 3;
    // 801853F4: lwz     r0, -26500(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26500);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801853F8:
    ctx->pc = 0x801853F8u;
    // 801853F8: cmplwi  r0, 0x0000
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

label_801853FC:
    ctx->pc = 0x801853FCu;
    // 801853FC: bc    12, 2, 0x801854E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801854E8;
        }
    }

label_80185400:
    ctx->pc = 0x80185400u;
    ctx->downcount -= 3;
    // 80185400: lwz     r0, -26456(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26456);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185404:
    ctx->pc = 0x80185404u;
    // 80185404: cmplwi  r0, 0x0001
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

label_80185408:
    ctx->pc = 0x80185408u;
    // 80185408: bc    4, 2, 0x80185418
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185418;
        }
    }

label_8018540C:
    ctx->pc = 0x8018540Cu;
    ctx->downcount -= 1;
    // 8018540C: bl      0x80187668
    {
            ctx->lr = 0x80185410u;
            ctx->pc = 0x80187668u;
            return;
    }

label_80185410:
    ctx->pc = 0x80185410u;
    ctx->downcount -= 2;
    // 80185410: cmplwi  r3, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80185414:
    ctx->pc = 0x80185414u;
    // 80185414: bc    12, 2, 0x801854D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801854D0;
        }
    }

label_80185418:
    ctx->pc = 0x80185418u;
    ctx->downcount -= 3;
    // 80185418: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_8018541C:
    ctx->pc = 0x8018541Cu;
    // 8018541C: addi    r29, r3, 8192
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(8192);

label_80185420:
    ctx->pc = 0x80185420u;
    // 80185420: b       0x80185498
    {
            goto label_80185498;
    }

label_80185424:
    ctx->pc = 0x80185424u;
    ctx->downcount -= 5;
    // 80185424: lwz     r3, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80185428:
    // 80185428: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8018542C:
    ctx->pc = 0x8018542Cu;
    // 8018542C: lwz     r27, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_80185430:
    // 80185430: addi    r4, r27, 0
    ctx->gpr[4] = ctx->gpr[27] + (u32)(s32)(0);

label_80185434:
    // 80185434: bl      0x801632BC
    {
            ctx->lr = 0x80185438u;
            ctx->pc = 0x801632BCu;
            return;
    }

label_80185438:
    ctx->downcount -= 5;
    // 80185438: cntlzw r4, r4
    {
        u32 v = ctx->gpr[4];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[4] = n;
    }

label_8018543C:
    // 8018543C: cmpwi   r4, 32
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(32);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80185440:
    // 80185440: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80185444:
    // 80185444: and   r0, r27, r0
    {
        ctx->gpr[0] = ctx->gpr[27] & ctx->gpr[0];
    }

label_80185448:
    // 80185448: bc    4, 0, 0x80185450
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185450;
        }
    }

label_8018544C:
    ctx->downcount -= 1;
    // 8018544C: b       0x80185458
    {
            goto label_80185458;
    }

label_80185450:
    ctx->downcount -= 2;
    // 80185450: cntlzw r3, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_80185454:
    // 80185454: addi    r4, r3, 32
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(32);

label_80185458:
    ctx->downcount -= 8;
    // 80185458: rlwinm r6, r4, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_8018545C:
    // 8018545C: add   r3, r31, r6
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80185460:
    ctx->pc = 0x80185460u;
    // 80185460: lhz     r0, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80185464:
    // 80185464: subfic  r5, r4, 63
    {
        u64 res = (u64)(u32)(s32)(63) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80185468:
    // 80185468: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018546C:
    ctx->pc = 0x8018546Cu;
    // 8018546C: sthx    r0, r29, r6
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[6];
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185470:
    // 80185470: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80185474:
    // 80185474: bl      0x801632C4
    {
            ctx->lr = 0x80185478u;
            ctx->pc = 0x801632C4u;
            return;
    }

label_80185478:
    ctx->pc = 0x80185478u;
    ctx->downcount -= 8;
    // 80185478: lwz     r0, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018547C:
    // 8018547C: nor   r5, r3, r3
    {
        ctx->gpr[5] = ~(ctx->gpr[3] | ctx->gpr[3]);
    }

label_80185480:
    // 80185480: nor   r4, r4, r4
    {
        ctx->gpr[4] = ~(ctx->gpr[4] | ctx->gpr[4]);
    }

label_80185484:
    ctx->pc = 0x80185484u;
    // 80185484: lwz     r3, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80185488:
    // 80185488: and   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[5];
    }

label_8018548C:
    // 8018548C: and   r3, r3, r4
    {
        ctx->gpr[3] = ctx->gpr[3] & ctx->gpr[4];
    }

label_80185490:
    ctx->pc = 0x80185490u;
    // 80185490: stw     r3, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80185494:
    ctx->pc = 0x80185494u;
    // 80185494: stw     r0, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185498:
    ctx->pc = 0x80185498u;
    ctx->downcount -= 7;
    // 80185498: lwz     r0, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018549C:
    // 8018549C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801854A0:
    ctx->pc = 0x801854A0u;
    // 801854A0: lwz     r3, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801854A4:
    // 801854A4: xor   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[4];
    }

label_801854A8:
    // 801854A8: xor   r3, r3, r4
    {
        ctx->gpr[3] = ctx->gpr[3] ^ ctx->gpr[4];
    }

label_801854AC:
    // 801854AC: or.   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801854B0:
    // 801854B0: bc    4, 2, 0x80185424
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80185424u;
                return;
            }
            goto label_80185424;
        }
    }

label_801854B4:
    ctx->pc = 0x801854B4u;
    ctx->downcount -= 7;
    // 801854B4: stw     r4, -26456(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26456);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801854B8:
    ctx->pc = 0x801854B8u;
    // 801854B8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801854BC:
    ctx->pc = 0x801854BCu;
    // 801854BC: lwz     r0, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801854C0:
    ctx->pc = 0x801854C0u;
    // 801854C0: stw     r0, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801854C4:
    ctx->pc = 0x801854C4u;
    // 801854C4: lwz     r0, 280(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(280);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801854C8:
    ctx->pc = 0x801854C8u;
    // 801854C8: stw     r0, -26436(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26436);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801854CC:
    ctx->pc = 0x801854CCu;
    // 801854CC: b       0x801854D4
    {
            goto label_801854D4;
    }

label_801854D0:
    ctx->pc = 0x801854D0u;
    ctx->downcount -= 1;
    // 801854D0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801854D4:
    ctx->pc = 0x801854D4u;
    ctx->downcount -= 2;
    // 801854D4: cmpwi   r3, 0
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

label_801854D8:
    ctx->pc = 0x801854D8u;
    // 801854D8: bc    12, 2, 0x801854E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801854E8;
        }
    }

label_801854DC:
    ctx->pc = 0x801854DCu;
    ctx->downcount -= 3;
    // 801854DC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801854E0:
    ctx->pc = 0x801854E0u;
    // 801854E0: stw     r0, -26500(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26500);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801854E4:
    ctx->pc = 0x801854E4u;
    // 801854E4: bl      0x801A4EB4
    {
            ctx->lr = 0x801854E8u;
            ctx->pc = 0x801A4EB4u;
            return;
    }

label_801854E8:
    ctx->pc = 0x801854E8u;
    ctx->downcount -= 3;
    // 801854E8: lwz     r0, -26484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26484);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801854EC:
    ctx->pc = 0x801854ECu;
    // 801854EC: cmplwi  r0, 0x0000
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

label_801854F0:
    ctx->pc = 0x801854F0u;
    // 801854F0: bc    12, 2, 0x8018550C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8018550C;
        }
    }

label_801854F4:
    ctx->pc = 0x801854F4u;
    ctx->downcount -= 2;
    // 801854F4: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_801854F8:
    ctx->pc = 0x801854F8u;
    // 801854F8: bl      0x8017248C
    {
            ctx->lr = 0x801854FCu;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_801854FC:
    ctx->pc = 0x801854FCu;
    ctx->downcount -= 5;
    // 801854FC: lwz     r12, -26484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26484);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80185500:
    ctx->pc = 0x80185500u;
    // 80185500: lwz     r3, -26504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26504);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80185504:
    ctx->pc = 0x80185504u;
    // 80185504: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_80185508:
    ctx->pc = 0x80185508u;
    // 80185508: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8018550Cu;
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018550C:
    ctx->pc = 0x8018550Cu;
    ctx->downcount -= 2;
    // 8018550C: addi    r3, r13, -26496
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26496);

label_80185510:
    ctx->pc = 0x80185510u;
    // 80185510: bl      0x80179564
    {
            ctx->lr = 0x80185514u;
            ctx->pc = 0x80179564u;
            return;
    }

label_80185514:
    ctx->pc = 0x80185514u;
    ctx->downcount -= 2;
    // 80185514: addi    r3, r1, 24
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(24);

label_80185518:
    ctx->pc = 0x80185518u;
    // 80185518: bl      0x8017248C
    {
            ctx->lr = 0x8018551Cu;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_8018551C:
    ctx->pc = 0x8018551Cu;
    ctx->downcount -= 2;
    // 8018551C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80185520:
    ctx->pc = 0x80185520u;
    // 80185520: bl      0x80172284
    {
            ctx->lr = 0x80185524u;
            ctx->pc = 0x80172284u;
            return;
    }

label_80185524:
    ctx->pc = 0x80185524u;
    ctx->downcount -= 16;
    // 80185524: lmw     r27, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80185528:
    ctx->pc = 0x80185528u;
    // 80185528: lwz     r0, 764(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(764);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018552C:
    ctx->pc = 0x8018552Cu;
    // 8018552C: addi    r1, r1, 760
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(760);

label_80185530:
    ctx->pc = 0x80185530u;
    // 80185530: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80185534:
    ctx->pc = 0x80185534u;
    // 80185534: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185538:
    ctx->pc = 0x80185538u;
    ctx->downcount -= 8;
    // 80185538: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8018553C:
    ctx->pc = 0x8018553Cu;
    // 8018553C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185540:
    ctx->pc = 0x80185540u;
    // 80185540: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80185544:
    ctx->pc = 0x80185544u;
    // 80185544: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80185548:
    ctx->pc = 0x80185548u;
    // 80185548: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018554C:
    ctx->pc = 0x8018554Cu;
    // 8018554C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80185550:
    ctx->pc = 0x80185550u;
    // 80185550: lwz     r31, -26488(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26488);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80185554:
    ctx->pc = 0x80185554u;
    // 80185554: bl      0x80173F2C
    {
            ctx->lr = 0x80185558u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80185558:
    ctx->pc = 0x80185558u;
    ctx->downcount -= 2;
    // 80185558: stw     r30, -26488(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26488);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018555C:
    ctx->pc = 0x8018555Cu;
    // 8018555C: bl      0x80173F54
    {
            ctx->lr = 0x80185560u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80185560:
    ctx->pc = 0x80185560u;
    ctx->downcount -= 8;
    // 80185560: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80185564:
    ctx->pc = 0x80185564u;
    // 80185564: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185568:
    ctx->pc = 0x80185568u;
    // 80185568: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8018556C:
    ctx->pc = 0x8018556Cu;
    // 8018556C: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80185570:
    ctx->pc = 0x80185570u;
    // 80185570: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80185574:
    ctx->pc = 0x80185574u;
    // 80185574: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80185578:
    ctx->pc = 0x80185578u;
    // 80185578: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018557C:
    ctx->pc = 0x8018557Cu;
    ctx->downcount -= 8;
    // 8018557C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80185580:
    ctx->pc = 0x80185580u;
    // 80185580: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185584:
    ctx->pc = 0x80185584u;
    // 80185584: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80185588:
    ctx->pc = 0x80185588u;
    // 80185588: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018558C:
    ctx->pc = 0x8018558Cu;
    // 8018558C: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80185590:
    ctx->pc = 0x80185590u;
    // 80185590: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80185594:
    ctx->pc = 0x80185594u;
    // 80185594: lwz     r31, -26484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26484);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80185598:
    ctx->pc = 0x80185598u;
    // 80185598: bl      0x80173F2C
    {
            ctx->lr = 0x8018559Cu;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_8018559C:
    ctx->pc = 0x8018559Cu;
    ctx->downcount -= 2;
    // 8018559C: stw     r30, -26484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26484);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801855A0:
    ctx->pc = 0x801855A0u;
    // 801855A0: bl      0x80173F54
    {
            ctx->lr = 0x801855A4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801855A4:
    ctx->pc = 0x801855A4u;
    ctx->downcount -= 8;
    // 801855A4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801855A8:
    ctx->pc = 0x801855A8u;
    // 801855A8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801855AC:
    ctx->pc = 0x801855ACu;
    // 801855AC: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801855B0:
    ctx->pc = 0x801855B0u;
    // 801855B0: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801855B4:
    ctx->pc = 0x801855B4u;
    // 801855B4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801855B8:
    ctx->pc = 0x801855B8u;
    // 801855B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801855BC:
    ctx->pc = 0x801855BCu;
    // 801855BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801855C0:
    ctx->pc = 0x801855C0u;
    ctx->downcount -= 4;
    // 801855C0: cmplwi  r3, 0x0015
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0015u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801855C4:
    ctx->pc = 0x801855C4u;
    // 801855C4: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_801855C8:
    ctx->pc = 0x801855C8u;
    // 801855C8: addi    r5, r4, -8896
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(-8896);

label_801855CC:
    ctx->pc = 0x801855CCu;
    // 801855CC: bc    12, 1, 0x80185648
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80185648;
        }
    }

label_801855D0:
    ctx->pc = 0x801855D0u;
    ctx->downcount -= 7;
    // 801855D0: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_801855D4:
    ctx->pc = 0x801855D4u;
    // 801855D4: addi    r4, r4, -8540
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-8540);

label_801855D8:
    ctx->pc = 0x801855D8u;
    // 801855D8: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_801855DC:
    ctx->pc = 0x801855DCu;
    // 801855DC: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801855E0:
    ctx->pc = 0x801855E0u;
    // 801855E0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_801855E4:
    ctx->pc = 0x801855E4u;
    // 801855E4: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_801855E8:
    ctx->pc = 0x801855E8u;
    ctx->downcount -= 2;
    // 801855E8: or   r3, r5, r5
    {
        ctx->gpr[3] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801855EC:
    ctx->pc = 0x801855ECu;
    // 801855EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801855F0:
    ctx->pc = 0x801855F0u;
    ctx->downcount -= 2;
    // 801855F0: addi    r3, r5, 38
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(38);

label_801855F4:
    ctx->pc = 0x801855F4u;
    // 801855F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801855F8:
    ctx->pc = 0x801855F8u;
    ctx->downcount -= 2;
    // 801855F8: addi    r3, r5, 76
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(76);

label_801855FC:
    ctx->pc = 0x801855FCu;
    // 801855FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185600:
    ctx->pc = 0x80185600u;
    ctx->downcount -= 2;
    // 80185600: addi    r3, r5, 114
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(114);

label_80185604:
    ctx->pc = 0x80185604u;
    // 80185604: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185608:
    ctx->pc = 0x80185608u;
    ctx->downcount -= 2;
    // 80185608: or   r3, r5, r5
    {
        ctx->gpr[3] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8018560C:
    ctx->pc = 0x8018560Cu;
    // 8018560C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185610:
    ctx->pc = 0x80185610u;
    ctx->downcount -= 2;
    // 80185610: addi    r3, r5, 38
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(38);

label_80185614:
    ctx->pc = 0x80185614u;
    // 80185614: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185618:
    ctx->pc = 0x80185618u;
    ctx->downcount -= 2;
    // 80185618: addi    r3, r5, 152
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(152);

label_8018561C:
    ctx->pc = 0x8018561Cu;
    // 8018561C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185620:
    ctx->pc = 0x80185620u;
    ctx->downcount -= 2;
    // 80185620: addi    r3, r5, 190
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(190);

label_80185624:
    ctx->pc = 0x80185624u;
    // 80185624: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185628:
    ctx->pc = 0x80185628u;
    ctx->downcount -= 2;
    // 80185628: addi    r3, r5, 228
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(228);

label_8018562C:
    ctx->pc = 0x8018562Cu;
    // 8018562C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185630:
    ctx->pc = 0x80185630u;
    ctx->downcount -= 2;
    // 80185630: addi    r3, r5, 266
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(266);

label_80185634:
    ctx->pc = 0x80185634u;
    // 80185634: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185638:
    ctx->pc = 0x80185638u;
    ctx->downcount -= 2;
    // 80185638: addi    r3, r5, 76
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(76);

label_8018563C:
    ctx->pc = 0x8018563Cu;
    // 8018563C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185640:
    ctx->pc = 0x80185640u;
    ctx->downcount -= 2;
    // 80185640: addi    r3, r5, 114
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(114);

label_80185644:
    ctx->pc = 0x80185644u;
    // 80185644: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185648:
    ctx->pc = 0x80185648u;
    ctx->downcount -= 2;
    // 80185648: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8018564C:
    ctx->pc = 0x8018564Cu;
    // 8018564C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185650:
    ctx->pc = 0x80185650u;
    ctx->downcount -= 13;
    // 80185650: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80185654:
    ctx->pc = 0x80185654u;
    // 80185654: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185658:
    ctx->pc = 0x80185658u;
    // 80185658: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8018565C:
    ctx->pc = 0x8018565Cu;
    // 8018565C: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80185660:
    ctx->pc = 0x80185660u;
    // 80185660: rlwinm r31, r3, 30, 2, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[3], 30u) & 0x3FFFFFFFu;
    }

label_80185664:
    ctx->pc = 0x80185664u;
    // 80185664: stw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80185668:
    ctx->pc = 0x80185668u;
    // 80185668: stw     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8018566C:
    ctx->pc = 0x8018566Cu;
    // 8018566C: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80185670:
    ctx->pc = 0x80185670u;
    // 80185670: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_80185674:
    ctx->pc = 0x80185674u;
    // 80185674: stw     r31, 204(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(204);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80185678:
    ctx->pc = 0x80185678u;
    // 80185678: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_8018567C:
    ctx->pc = 0x8018567Cu;
    // 8018567C: rlwinm r30, r29, 0, 30, 30
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x00000002u;
    }

label_80185680:
    ctx->pc = 0x80185680u;
    // 80185680: bl      0x801855C0
    {
            ctx->lr = 0x80185684u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801855C0u;
                return;
            }
            goto label_801855C0;
    }

label_80185684:
    ctx->pc = 0x80185684u;
    ctx->downcount -= 9;
    // 80185684: lis     r4, -13312
    ctx->gpr[4] = ((u32)(s32)(-13312) << 16);

label_80185688:
    ctx->pc = 0x80185688u;
    // 80185688: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8018568C:
    ctx->pc = 0x8018568Cu;
    // 8018568C: addi    r5, r4, 8192
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(8192);

label_80185690:
    ctx->pc = 0x80185690u;
    // 80185690: sthu     r0, 2(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
        ctx->gpr[5] = ea;
    }

label_80185694:
    ctx->pc = 0x80185694u;
    // 80185694: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80185698:
    ctx->pc = 0x80185698u;
    // 80185698: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018569C:
    ctx->pc = 0x8018569Cu;
    // 8018569C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801856A0:
    ctx->pc = 0x801856A0u;
    // 801856A0: cmplwi  r0, 0x03E8
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x03E8u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801856A4:
    ctx->pc = 0x801856A4u;
    // 801856A4: bc    4, 0, 0x801856C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801856C4;
        }
    }

label_801856A8:
    ctx->pc = 0x801856A8u;
    ctx->downcount -= 1;
    // 801856A8: b       0x801856B8
    {
            goto label_801856B8;
    }

label_801856AC:
    loop_801856AC(ctx);
    if (ctx->pc == 0x801856C4u) goto label_801856C4;
    return;
label_801856B0:
    // 801856B0: addi    r0, r4, 8
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(8);

label_801856B4:
    ctx->pc = 0x801856B4u;
    // 801856B4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801856B8:
    ctx->pc = 0x801856B8u;
    ctx->downcount -= 3;
    // 801856B8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801856BC:
    // 801856BC: cmplwi  r0, 0x03E8
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x03E8u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801856C0:
    // 801856C0: bc    12, 0, 0x801856AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801856ACu;
                return;
            }
            goto label_801856AC;
        }
    }

label_801856C4:
    ctx->pc = 0x801856C4u;
    ctx->downcount -= 75;
    // 801856C4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801856C8:
    ctx->pc = 0x801856C8u;
    // 801856C8: sth     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801856CC:
    ctx->pc = 0x801856CCu;
    // 801856CC: lis     r12, -13312
    ctx->gpr[12] = ((u32)(s32)(-13312) << 16);

label_801856D0:
    ctx->pc = 0x801856D0u;
    // 801856D0: li      r8, 10280
    ctx->gpr[8] = (u32)(s32)(10280);

label_801856D4:
    ctx->pc = 0x801856D4u;
    // 801856D4: lhz     r6, 26(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_801856D8:
    ctx->pc = 0x801856D8u;
    // 801856D8: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_801856DC:
    ctx->pc = 0x801856DCu;
    // 801856DC: cmpwi   r29, 2
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801856E0:
    ctx->pc = 0x801856E0u;
    // 801856E0: sth     r6, 8198(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8198);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_801856E4:
    ctx->pc = 0x801856E4u;
    // 801856E4: li      r6, 4097
    ctx->gpr[6] = (u32)(s32)(4097);

label_801856E8:
    ctx->pc = 0x801856E8u;
    // 801856E8: addi    r4, r12, 8192
    ctx->gpr[4] = ctx->gpr[12] + (u32)(s32)(8192);

label_801856EC:
    ctx->pc = 0x801856ECu;
    // 801856EC: lbz     r9, 29(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(29);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_801856F0:
    ctx->pc = 0x801856F0u;
    // 801856F0: lbz     r10, 30(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_801856F4:
    ctx->pc = 0x801856F4u;
    // 801856F4: rlwimi r10, r9, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[9], 8u);
        ctx->gpr[10] = (ctx->gpr[10] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_801856F8:
    ctx->pc = 0x801856F8u;
    // 801856F8: sth     r10, 8196(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8196);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_801856FC:
    ctx->pc = 0x801856FCu;
    // 801856FC: lbz     r9, 31(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(31);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_80185700:
    ctx->pc = 0x80185700u;
    // 80185700: lbz     r10, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80185704:
    ctx->pc = 0x80185704u;
    // 80185704: rlwinm r9, r9, 7, 0, 24
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 7u) & 0xFFFFFF80u;
    }

label_80185708:
    ctx->pc = 0x80185708u;
    // 80185708: or   r9, r10, r9
    {
        ctx->gpr[9] = ctx->gpr[10] | ctx->gpr[9];
    }

label_8018570C:
    ctx->pc = 0x8018570Cu;
    // 8018570C: sth     r9, 8202(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8202);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80185710:
    ctx->pc = 0x80185710u;
    // 80185710: lhz     r9, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185714:
    ctx->pc = 0x80185714u;
    // 80185714: rlwinm r9, r9, 1, 16, 30
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 1u) & 0x0000FFFEu;
    }

label_80185718:
    ctx->pc = 0x80185718u;
    // 80185718: sth     r9, 8200(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8200);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_8018571C:
    ctx->pc = 0x8018571Cu;
    // 8018571C: lhz     r9, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185720:
    ctx->pc = 0x80185720u;
    // 80185720: lbz     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_80185724:
    ctx->pc = 0x80185724u;
    // 80185724: rlwinm r9, r9, 1, 0, 30
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 1u) & 0xFFFFFFFEu;
    }

label_80185728:
    ctx->pc = 0x80185728u;
    // 80185728: lhz     r10, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_8018572C:
    ctx->pc = 0x8018572Cu;
    // 8018572C: addi    r9, r9, -2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2);

label_80185730:
    ctx->pc = 0x80185730u;
    // 80185730: sth     r11, 8192(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8192);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_80185734:
    ctx->pc = 0x80185734u;
    // 80185734: add   r9, r10, r9
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80185738:
    ctx->pc = 0x80185738u;
    // 80185738: sth     r9, 8206(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8206);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_8018573C:
    ctx->pc = 0x8018573Cu;
    // 8018573C: lhz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185740:
    ctx->pc = 0x80185740u;
    // 80185740: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_80185744:
    ctx->pc = 0x80185744u;
    // 80185744: sth     r9, 8204(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8204);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80185748:
    ctx->pc = 0x80185748u;
    // 80185748: lhz     r9, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_8018574C:
    ctx->pc = 0x8018574Cu;
    // 8018574C: lhz     r10, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_80185750:
    ctx->pc = 0x80185750u;
    // 80185750: rlwinm r9, r9, 1, 0, 30
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 1u) & 0xFFFFFFFEu;
    }

label_80185754:
    ctx->pc = 0x80185754u;
    // 80185754: addi    r9, r9, -2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2);

label_80185758:
    ctx->pc = 0x80185758u;
    // 80185758: add   r9, r10, r9
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8018575C:
    ctx->pc = 0x8018575Cu;
    // 8018575C: sth     r9, 8210(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8210);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80185760:
    ctx->pc = 0x80185760u;
    // 80185760: lhz     r9, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185764:
    ctx->pc = 0x80185764u;
    // 80185764: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_80185768:
    ctx->pc = 0x80185768u;
    // 80185768: sth     r9, 8208(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8208);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_8018576C:
    ctx->pc = 0x8018576Cu;
    // 8018576C: lhz     r9, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185770:
    ctx->pc = 0x80185770u;
    // 80185770: lbz     r10, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80185774:
    ctx->pc = 0x80185774u;
    // 80185774: rlwinm r9, r9, 5, 0, 26
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 5u) & 0xFFFFFFE0u;
    }

label_80185778:
    ctx->pc = 0x80185778u;
    // 80185778: or   r9, r10, r9
    {
        ctx->gpr[9] = ctx->gpr[10] | ctx->gpr[9];
    }

label_8018577C:
    ctx->pc = 0x8018577Cu;
    // 8018577C: sth     r9, 8214(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8214);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80185780:
    ctx->pc = 0x80185780u;
    // 80185780: lhz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185784:
    ctx->pc = 0x80185784u;
    // 80185784: lbz     r10, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80185788:
    ctx->pc = 0x80185788u;
    // 80185788: rlwinm r9, r9, 5, 0, 26
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 5u) & 0xFFFFFFE0u;
    }

label_8018578C:
    ctx->pc = 0x8018578Cu;
    // 8018578C: or   r9, r10, r9
    {
        ctx->gpr[9] = ctx->gpr[10] | ctx->gpr[9];
    }

label_80185790:
    ctx->pc = 0x80185790u;
    // 80185790: sth     r9, 8212(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8212);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80185794:
    ctx->pc = 0x80185794u;
    // 80185794: lhz     r9, 18(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(18);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185798:
    ctx->pc = 0x80185798u;
    // 80185798: lbz     r10, 13(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(13);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_8018579C:
    ctx->pc = 0x8018579Cu;
    // 8018579C: rlwinm r9, r9, 5, 0, 26
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 5u) & 0xFFFFFFE0u;
    }

label_801857A0:
    ctx->pc = 0x801857A0u;
    // 801857A0: or   r9, r10, r9
    {
        ctx->gpr[9] = ctx->gpr[10] | ctx->gpr[9];
    }

label_801857A4:
    ctx->pc = 0x801857A4u;
    // 801857A4: sth     r9, 8218(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8218);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_801857A8:
    ctx->pc = 0x801857A8u;
    // 801857A8: lhz     r9, 22(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(22);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_801857AC:
    ctx->pc = 0x801857ACu;
    // 801857AC: lbz     r10, 15(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(15);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_801857B0:
    ctx->pc = 0x801857B0u;
    // 801857B0: rlwinm r9, r9, 5, 0, 26
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 5u) & 0xFFFFFFE0u;
    }

label_801857B4:
    ctx->pc = 0x801857B4u;
    // 801857B4: or   r9, r10, r9
    {
        ctx->gpr[9] = ctx->gpr[10] | ctx->gpr[9];
    }

label_801857B8:
    ctx->pc = 0x801857B8u;
    // 801857B8: sth     r9, 8216(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8216);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_801857BC:
    ctx->pc = 0x801857BCu;
    // 801857BC: sth     r8, 8264(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8264);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_801857C0:
    ctx->pc = 0x801857C0u;
    // 801857C0: sth     r7, 8246(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8246);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_801857C4:
    ctx->pc = 0x801857C4u;
    // 801857C4: sth     r6, 8244(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8244);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_801857C8:
    ctx->pc = 0x801857C8u;
    // 801857C8: lhz     r6, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_801857CC:
    ctx->pc = 0x801857CCu;
    // 801857CC: lhz     r3, 26(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801857D0:
    ctx->pc = 0x801857D0u;
    // 801857D0: srawi r6, r6, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[6];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[6] = value;
        } else if (sh > 31) {
            ctx->gpr[6] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[6] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_801857D4:
    ctx->pc = 0x801857D4u;
    // 801857D4: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_801857D8:
    ctx->pc = 0x801857D8u;
    // 801857D8: addze  r6, r6
    {
        u32 a = ctx->gpr[6];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[6] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801857DC:
    ctx->pc = 0x801857DCu;
    // 801857DC: sth     r3, 8242(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8242);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801857E0:
    ctx->pc = 0x801857E0u;
    // 801857E0: addi    r6, r6, 1
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1);

label_801857E4:
    ctx->pc = 0x801857E4u;
    // 801857E4: ori     r3, r6, 0x1000
    ctx->gpr[3] = ctx->gpr[6] | 0x1000u;

label_801857E8:
    ctx->pc = 0x801857E8u;
    // 801857E8: sth     r3, 8240(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(8240);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801857EC:
    ctx->pc = 0x801857ECu;
    // 801857EC: bc    12, 2, 0x80185814
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80185814;
        }
    }

label_801857F0:
    ctx->pc = 0x801857F0u;
    ctx->downcount -= 2;
    // 801857F0: cmpwi   r29, 3
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801857F4:
    ctx->pc = 0x801857F4u;
    // 801857F4: bc    12, 2, 0x80185814
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80185814;
        }
    }

label_801857F8:
    ctx->pc = 0x801857F8u;
    ctx->downcount -= 7;
    // 801857F8: rlwinm r3, r30, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_801857FC:
    ctx->pc = 0x801857FCu;
    // 801857FC: ori     r6, r3, 0x0001
    ctx->gpr[6] = ctx->gpr[3] | 0x0001u;

label_80185800:
    ctx->pc = 0x80185800u;
    // 80185800: rlwinm r3, r31, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[31], 8u) & 0xFFFFFF00u;
    }

label_80185804:
    ctx->pc = 0x80185804u;
    // 80185804: or   r3, r6, r3
    {
        ctx->gpr[3] = ctx->gpr[6] | ctx->gpr[3];
    }

label_80185808:
    ctx->pc = 0x80185808u;
    // 80185808: sth     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8018580C:
    ctx->pc = 0x8018580Cu;
    // 8018580C: sth     r0, 108(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(108);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185810:
    ctx->pc = 0x80185810u;
    // 80185810: b       0x8018582C
    {
            goto label_8018582C;
    }

label_80185814:
    ctx->pc = 0x80185814u;
    ctx->downcount -= 6;
    // 80185814: rlwinm r0, r31, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 8u) & 0xFFFFFF00u;
    }

label_80185818:
    ctx->pc = 0x80185818u;
    // 80185818: ori     r0, r0, 0x0005
    ctx->gpr[0] = ctx->gpr[0] | 0x0005u;

label_8018581C:
    ctx->pc = 0x8018581Cu;
    // 8018581C: sth     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185820:
    ctx->pc = 0x80185820u;
    // 80185820: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80185824:
    ctx->pc = 0x80185824u;
    // 80185824: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80185828:
    ctx->pc = 0x80185828u;
    // 80185828: sth     r0, 8300(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8300);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018582C:
    ctx->pc = 0x8018582Cu;
    ctx->downcount -= 8;
    // 8018582C: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185830:
    ctx->pc = 0x80185830u;
    // 80185830: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80185834:
    ctx->pc = 0x80185834u;
    // 80185834: lwz     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80185838:
    ctx->pc = 0x80185838u;
    // 80185838: lwz     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8018583C:
    ctx->pc = 0x8018583Cu;
    // 8018583C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80185840:
    ctx->pc = 0x80185840u;
    // 80185840: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80185844:
    ctx->pc = 0x80185844u;
    // 80185844: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185848:
    ctx->pc = 0x80185848u;
    ctx->downcount -= 9;
    // 80185848: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_8018584C:
    ctx->pc = 0x8018584Cu;
    // 8018584C: lha     r5, -26476(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26476);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185850:
    ctx->pc = 0x80185850u;
    // 80185850: addi    r4, r4, 2360
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2360);

label_80185854:
    ctx->pc = 0x80185854u;
    // 80185854: lha     r6, 240(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(240);
        ctx->gpr[6] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185858:
    ctx->pc = 0x80185858u;
    // 80185858: lhz     r0, 244(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018585C:
    ctx->pc = 0x8018585Cu;
    // 8018585C: add   r5, r6, r5
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_80185860:
    ctx->pc = 0x80185860u;
    // 80185860: subfic  r0, r0, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80185864:
    ctx->pc = 0x80185864u;
    // 80185864: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80185868:
    ctx->pc = 0x80185868u;
    // 80185868: bc    4, 1, 0x80185870
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185870;
        }
    }

label_8018586C:
    ctx->pc = 0x8018586Cu;
    ctx->downcount -= 1;
    // 8018586C: b       0x80185880
    {
            goto label_80185880;
    }

label_80185870:
    ctx->pc = 0x80185870u;
    ctx->downcount -= 2;
    // 80185870: cmpwi   r5, 0
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

label_80185874:
    ctx->pc = 0x80185874u;
    // 80185874: bc    4, 0, 0x8018587C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018587C;
        }
    }

label_80185878:
    ctx->pc = 0x80185878u;
    ctx->downcount -= 1;
    // 80185878: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8018587C:
    ctx->pc = 0x8018587Cu;
    ctx->downcount -= 1;
    // 8018587C: or   r0, r5, r5
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80185880:
    ctx->pc = 0x80185880u;
    ctx->downcount -= 4;
    // 80185880: sth     r0, 248(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(248);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185884:
    ctx->pc = 0x80185884u;
    // 80185884: lwz     r0, 272(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185888:
    ctx->pc = 0x80185888u;
    // 80185888: cmpwi   r0, 0
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

label_8018588C:
    ctx->pc = 0x8018588Cu;
    // 8018588C: bc    4, 2, 0x80185898
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185898;
        }
    }

label_80185890:
    ctx->pc = 0x80185890u;
    ctx->downcount -= 2;
    // 80185890: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80185894:
    ctx->pc = 0x80185894u;
    // 80185894: b       0x8018589C
    {
            goto label_8018589C;
    }

label_80185898:
    ctx->pc = 0x80185898u;
    ctx->downcount -= 1;
    // 80185898: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8018589C:
    ctx->pc = 0x8018589Cu;
    ctx->downcount -= 8;
    // 8018589C: lhz     r0, 242(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(242);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801858A0:
    ctx->pc = 0x801858A0u;
    // 801858A0: addi    r8, r4, 242
    ctx->gpr[8] = ctx->gpr[4] + (u32)(s32)(242);

label_801858A4:
    ctx->pc = 0x801858A4u;
    // 801858A4: lha     r7, -26474(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26474);
        ctx->gpr[7] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801858A8:
    ctx->pc = 0x801858A8u;
    // 801858A8: extsh r5, r0
    {
        ctx->gpr[5] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_801858AC:
    ctx->pc = 0x801858ACu;
    // 801858AC: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_801858B0:
    ctx->pc = 0x801858B0u;
    // 801858B0: add   r5, r5, r7
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_801858B4:
    ctx->pc = 0x801858B4u;
    // 801858B4: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801858B8:
    ctx->pc = 0x801858B8u;
    // 801858B8: bc    4, 1, 0x801858C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801858C0;
        }
    }

label_801858BC:
    ctx->pc = 0x801858BCu;
    ctx->downcount -= 1;
    // 801858BC: b       0x801858C4
    {
            goto label_801858C4;
    }

label_801858C0:
    ctx->pc = 0x801858C0u;
    ctx->downcount -= 1;
    // 801858C0: or   r5, r0, r0
    {
        ctx->gpr[5] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801858C4:
    ctx->pc = 0x801858C4u;
    ctx->downcount -= 12;
    // 801858C4: sth     r5, 250(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(250);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_801858C8:
    ctx->pc = 0x801858C8u;
    // 801858C8: extsh r3, r3
    {
        ctx->gpr[3] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_801858CC:
    ctx->pc = 0x801858CCu;
    // 801858CC: rlwinm r3, r3, 1, 0, 30
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0xFFFFFFFEu;
    }

label_801858D0:
    ctx->pc = 0x801858D0u;
    // 801858D0: lhz     r11, 246(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(246);
        ctx->gpr[11] = mem_read16(ctx, ea);
    }

label_801858D4:
    ctx->pc = 0x801858D4u;
    // 801858D4: subf   r9, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_801858D8:
    ctx->pc = 0x801858D8u;
    // 801858D8: lha     r10, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801858DC:
    ctx->pc = 0x801858DCu;
    // 801858DC: addi    r12, r4, 246
    ctx->gpr[12] = ctx->gpr[4] + (u32)(s32)(246);

label_801858E0:
    ctx->pc = 0x801858E0u;
    // 801858E0: extsh r3, r11
    {
        ctx->gpr[3] = (u32)(s32)(s16)ctx->gpr[11];
    }

label_801858E4:
    ctx->pc = 0x801858E4u;
    // 801858E4: add   r5, r3, r7
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_801858E8:
    ctx->pc = 0x801858E8u;
    // 801858E8: add   r5, r10, r5
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_801858EC:
    ctx->pc = 0x801858ECu;
    // 801858EC: subf.   r3, r9, r5
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801858F0:
    ctx->pc = 0x801858F0u;
    // 801858F0: bc    4, 1, 0x801858FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801858FC;
        }
    }

label_801858F4:
    ctx->pc = 0x801858F4u;
    ctx->downcount -= 2;
    // 801858F4: subf   r5, r9, r5
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_801858F8:
    ctx->pc = 0x801858F8u;
    // 801858F8: b       0x80185900
    {
            goto label_80185900;
    }

label_801858FC:
    ctx->pc = 0x801858FCu;
    ctx->downcount -= 1;
    // 801858FC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80185900:
    ctx->pc = 0x80185900u;
    ctx->downcount -= 3;
    // 80185900: add   r10, r10, r7
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_80185904:
    ctx->pc = 0x80185904u;
    // 80185904: subf.   r3, r0, r10
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185908:
    ctx->pc = 0x80185908u;
    // 80185908: bc    4, 0, 0x80185914
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185914;
        }
    }

label_8018590C:
    ctx->pc = 0x8018590Cu;
    ctx->downcount -= 2;
    // 8018590C: subf   r3, r0, r10
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80185910:
    ctx->pc = 0x80185910u;
    // 80185910: b       0x80185918
    {
            goto label_80185918;
    }

label_80185914:
    ctx->pc = 0x80185914u;
    ctx->downcount -= 1;
    // 80185914: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80185918:
    ctx->pc = 0x80185918u;
    ctx->downcount -= 7;
    // 80185918: add   r3, r11, r3
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8018591C:
    ctx->pc = 0x8018591Cu;
    // 8018591C: subf   r3, r5, r3
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80185920:
    ctx->pc = 0x80185920u;
    // 80185920: sth     r3, 252(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(252);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80185924:
    ctx->pc = 0x80185924u;
    // 80185924: lha     r3, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185928:
    ctx->pc = 0x80185928u;
    // 80185928: add   r5, r3, r7
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8018592C:
    ctx->pc = 0x8018592Cu;
    // 8018592C: subf.   r3, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185930:
    ctx->pc = 0x80185930u;
    // 80185930: bc    4, 0, 0x8018593C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018593C;
        }
    }

label_80185934:
    ctx->pc = 0x80185934u;
    ctx->downcount -= 2;
    // 80185934: subf   r3, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80185938:
    ctx->pc = 0x80185938u;
    // 80185938: b       0x80185940
    {
            goto label_80185940;
    }

label_8018593C:
    ctx->pc = 0x8018593Cu;
    ctx->downcount -= 1;
    // 8018593C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80185940:
    ctx->pc = 0x80185940u;
    ctx->downcount -= 49;
    // 80185940: divw   r5, r3, r6
    {
        s32 dividend = (s32)ctx->gpr[3];
        s32 divisor = (s32)ctx->gpr[6];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[5] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80185944:
    ctx->pc = 0x80185944u;
    // 80185944: lhz     r3, 264(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(264);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80185948:
    ctx->pc = 0x80185948u;
    // 80185948: subf   r3, r5, r3
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_8018594C:
    ctx->pc = 0x8018594Cu;
    // 8018594C: sth     r3, 254(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(254);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80185950:
    ctx->pc = 0x80185950u;
    // 80185950: lha     r3, 0(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(0);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185954:
    ctx->pc = 0x80185954u;
    // 80185954: lha     r8, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[8] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185958:
    ctx->pc = 0x80185958u;
    // 80185958: add   r5, r3, r7
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8018595C:
    ctx->pc = 0x8018595Cu;
    // 8018595C: add   r5, r8, r5
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_80185960:
    ctx->pc = 0x80185960u;
    // 80185960: subf.   r3, r9, r5
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185964:
    ctx->pc = 0x80185964u;
    // 80185964: bc    4, 1, 0x80185970
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185970;
        }
    }

label_80185968:
    ctx->pc = 0x80185968u;
    ctx->downcount -= 2;
    // 80185968: subf   r5, r9, r5
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8018596C:
    ctx->pc = 0x8018596Cu;
    // 8018596C: b       0x80185974
    {
            goto label_80185974;
    }

label_80185970:
    ctx->pc = 0x80185970u;
    ctx->downcount -= 1;
    // 80185970: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80185974:
    ctx->pc = 0x80185974u;
    ctx->downcount -= 3;
    // 80185974: add   r7, r8, r7
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80185978:
    ctx->pc = 0x80185978u;
    // 80185978: subf.   r3, r0, r7
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018597C:
    ctx->pc = 0x8018597Cu;
    // 8018597C: bc    4, 0, 0x80185988
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185988;
        }
    }

label_80185980:
    ctx->pc = 0x80185980u;
    ctx->downcount -= 2;
    // 80185980: subf   r0, r0, r7
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80185984:
    ctx->pc = 0x80185984u;
    // 80185984: b       0x8018598C
    {
            goto label_8018598C;
    }

label_80185988:
    ctx->pc = 0x80185988u;
    ctx->downcount -= 1;
    // 80185988: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8018598C:
    ctx->pc = 0x8018598Cu;
    ctx->downcount -= 85;
    // 8018598C: divw   r0, r0, r6
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[6];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80185990:
    ctx->pc = 0x80185990u;
    // 80185990: lhz     r3, 268(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(268);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80185994:
    ctx->pc = 0x80185994u;
    // 80185994: divw   r5, r5, r6
    {
        s32 dividend = (s32)ctx->gpr[5];
        s32 divisor = (s32)ctx->gpr[6];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[5] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80185998:
    ctx->pc = 0x80185998u;
    // 80185998: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8018599C:
    ctx->pc = 0x8018599Cu;
    // 8018599C: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801859A0:
    ctx->pc = 0x801859A0u;
    // 801859A0: sth     r0, 256(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(256);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801859A4:
    ctx->pc = 0x801859A4u;
    // 801859A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801859A8:
    ctx->pc = 0x801859A8u;
    ctx->downcount -= 4;
    // 801859A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801859AC:
    ctx->pc = 0x801859ACu;
    // 801859AC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801859B0:
    ctx->pc = 0x801859B0u;
    // 801859B0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801859B4:
    ctx->pc = 0x801859B4u;
    // 801859B4: bl      0x80176EE0
    {
            ctx->lr = 0x801859B8u;
            ctx->pc = 0x80176EE0u;
            return;
    }

label_801859B8:
    ctx->pc = 0x801859B8u;
    ctx->downcount -= 7;
    // 801859B8: lbz     r4, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801859BC:
    ctx->pc = 0x801859BCu;
    // 801859BC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801859C0:
    ctx->pc = 0x801859C0u;
    // 801859C0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801859C4:
    ctx->pc = 0x801859C4u;
    // 801859C4: extsb r4, r4
    {
        ctx->gpr[4] = (u32)(s32)(s8)ctx->gpr[4];
    }

label_801859C8:
    ctx->pc = 0x801859C8u;
    // 801859C8: sth     r0, -26474(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26474);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801859CC:
    ctx->pc = 0x801859CCu;
    // 801859CC: sth     r4, -26476(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26476);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_801859D0:
    ctx->pc = 0x801859D0u;
    // 801859D0: bl      0x801772A0
    {
            ctx->lr = 0x801859D4u;
            ctx->pc = 0x801772A0u;
            return;
    }

label_801859D4:
    ctx->pc = 0x801859D4u;
    ctx->downcount -= 5;
    // 801859D4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801859D8:
    ctx->pc = 0x801859D8u;
    // 801859D8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801859DC:
    ctx->pc = 0x801859DCu;
    // 801859DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801859E0:
    ctx->pc = 0x801859E0u;
    // 801859E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801859E4:
    ctx->pc = 0x801859E4u;
    ctx->downcount -= 18;
    // 801859E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801859E8:
    ctx->pc = 0x801859E8u;
    // 801859E8: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_801859EC:
    ctx->pc = 0x801859ECu;
    // 801859EC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801859F0:
    ctx->pc = 0x801859F0u;
    // 801859F0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801859F4:
    ctx->pc = 0x801859F4u;
    // 801859F4: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_801859F8:
    ctx->pc = 0x801859F8u;
    // 801859F8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801859FC:
    ctx->pc = 0x801859FCu;
    // 801859FC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80185A00:
    ctx->pc = 0x80185A00u;
    // 80185A00: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80185A04:
    ctx->pc = 0x80185A04u;
    // 80185A04: addi    r30, r4, -8896
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(-8896);

label_80185A08:
    ctx->pc = 0x80185A08u;
    // 80185A08: stw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A0C:
    ctx->pc = 0x80185A0Cu;
    // 80185A0C: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80185A10:
    ctx->pc = 0x80185A10u;
    // 80185A10: addi    r28, r3, 8192
    ctx->gpr[28] = ctx->gpr[3] + (u32)(s32)(8192);

label_80185A14:
    ctx->pc = 0x80185A14u;
    // 80185A14: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80185A18:
    ctx->pc = 0x80185A18u;
    // 80185A18: stw     r0, -26480(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26480);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185A1C:
    ctx->pc = 0x80185A1Cu;
    // 80185A1C: addi    r31, r3, 2360
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(2360);

label_80185A20:
    ctx->pc = 0x80185A20u;
    // 80185A20: lhzu     r0, 2(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[28] = ea;
    }

label_80185A24:
    ctx->pc = 0x80185A24u;
    // 80185A24: rlwinm. r0, r0, 0, 31, 31
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

label_80185A28:
    ctx->pc = 0x80185A28u;
    // 80185A28: bc    4, 2, 0x80185A34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185A34;
        }
    }

label_80185A2C:
    ctx->pc = 0x80185A2Cu;
    ctx->downcount -= 2;
    // 80185A2C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80185A30:
    ctx->pc = 0x80185A30u;
    // 80185A30: bl      0x80185650
    {
            ctx->lr = 0x80185A34u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80185650u;
                return;
            }
            goto label_80185650;
    }

label_80185A34:
    ctx->pc = 0x80185A34u;
    ctx->downcount -= 87;
    // 80185A34: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80185A38:
    ctx->pc = 0x80185A38u;
    // 80185A38: stw     r29, -26504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26504);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A3C:
    ctx->pc = 0x80185A3Cu;
    // 80185A3C: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80185A40:
    ctx->pc = 0x80185A40u;
    // 80185A40: addi    r3, r3, 8192
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8192);

label_80185A44:
    ctx->pc = 0x80185A44u;
    // 80185A44: stw     r29, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A48:
    ctx->pc = 0x80185A48u;
    // 80185A48: li      r0, 640
    ctx->gpr[0] = (u32)(s32)(640);

label_80185A4C:
    ctx->pc = 0x80185A4Cu;
    // 80185A4C: stw     r29, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A50:
    ctx->pc = 0x80185A50u;
    // 80185A50: stw     r29, -26444(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26444);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A54:
    ctx->pc = 0x80185A54u;
    // 80185A54: stw     r29, -26448(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26448);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A58:
    ctx->pc = 0x80185A58u;
    // 80185A58: stw     r29, -26472(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26472);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A5C:
    ctx->pc = 0x80185A5Cu;
    // 80185A5C: stw     r29, -26456(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26456);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A60:
    ctx->pc = 0x80185A60u;
    // 80185A60: stw     r29, -26500(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26500);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80185A64:
    ctx->pc = 0x80185A64u;
    // 80185A64: lhz     r5, 306(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(306);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185A68:
    ctx->pc = 0x80185A68u;
    // 80185A68: lhz     r6, 304(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(304);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80185A6C:
    ctx->pc = 0x80185A6Cu;
    // 80185A6C: rlwinm r5, r5, 10, 16, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 10u) & 0x0000FC00u;
    }

label_80185A70:
    ctx->pc = 0x80185A70u;
    // 80185A70: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80185A74:
    ctx->pc = 0x80185A74u;
    // 80185A74: sth     r5, 78(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(78);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_80185A78:
    ctx->pc = 0x80185A78u;
    // 80185A78: lhz     r6, 306(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(306);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80185A7C:
    ctx->pc = 0x80185A7Cu;
    // 80185A7C: lhz     r5, 308(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(308);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185A80:
    ctx->pc = 0x80185A80u;
    // 80185A80: srawi r6, r6, 6
    {
        u32 sh = 6u;
        u32 value = ctx->gpr[6];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[6] = value;
        } else if (sh > 31) {
            ctx->gpr[6] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[6] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80185A84:
    ctx->pc = 0x80185A84u;
    // 80185A84: rlwinm r5, r5, 4, 0, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0xFFFFFFF0u;
    }

label_80185A88:
    ctx->pc = 0x80185A88u;
    // 80185A88: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80185A8C:
    ctx->pc = 0x80185A8Cu;
    // 80185A8C: sth     r5, 76(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(76);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_80185A90:
    ctx->pc = 0x80185A90u;
    // 80185A90: lhz     r5, 312(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(312);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185A94:
    ctx->pc = 0x80185A94u;
    // 80185A94: lhz     r6, 310(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(310);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80185A98:
    ctx->pc = 0x80185A98u;
    // 80185A98: rlwinm r5, r5, 10, 16, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 10u) & 0x0000FC00u;
    }

label_80185A9C:
    ctx->pc = 0x80185A9Cu;
    // 80185A9C: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80185AA0:
    ctx->pc = 0x80185AA0u;
    // 80185AA0: sth     r5, 82(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(82);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_80185AA4:
    ctx->pc = 0x80185AA4u;
    // 80185AA4: lhz     r6, 312(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(312);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80185AA8:
    ctx->pc = 0x80185AA8u;
    // 80185AA8: lhz     r5, 314(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(314);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185AAC:
    ctx->pc = 0x80185AACu;
    // 80185AAC: srawi r6, r6, 6
    {
        u32 sh = 6u;
        u32 value = ctx->gpr[6];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[6] = value;
        } else if (sh > 31) {
            ctx->gpr[6] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[6] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80185AB0:
    ctx->pc = 0x80185AB0u;
    // 80185AB0: rlwinm r5, r5, 4, 0, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0xFFFFFFF0u;
    }

label_80185AB4:
    ctx->pc = 0x80185AB4u;
    // 80185AB4: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80185AB8:
    ctx->pc = 0x80185AB8u;
    // 80185AB8: sth     r5, 80(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(80);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_80185ABC:
    ctx->pc = 0x80185ABCu;
    // 80185ABC: lhz     r5, 318(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(318);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185AC0:
    ctx->pc = 0x80185AC0u;
    // 80185AC0: lhz     r6, 316(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(316);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80185AC4:
    ctx->pc = 0x80185AC4u;
    // 80185AC4: rlwinm r5, r5, 10, 16, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 10u) & 0x0000FC00u;
    }

label_80185AC8:
    ctx->pc = 0x80185AC8u;
    // 80185AC8: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80185ACC:
    ctx->pc = 0x80185ACCu;
    // 80185ACC: sth     r5, 86(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(86);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_80185AD0:
    ctx->pc = 0x80185AD0u;
    // 80185AD0: lhz     r5, 318(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(318);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185AD4:
    ctx->pc = 0x80185AD4u;
    // 80185AD4: lhz     r4, 320(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(320);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185AD8:
    ctx->pc = 0x80185AD8u;
    // 80185AD8: srawi r5, r5, 6
    {
        u32 sh = 6u;
        u32 value = ctx->gpr[5];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[5] = value;
        } else if (sh > 31) {
            ctx->gpr[5] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[5] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80185ADC:
    ctx->pc = 0x80185ADCu;
    // 80185ADC: rlwinm r4, r4, 4, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_80185AE0:
    ctx->pc = 0x80185AE0u;
    // 80185AE0: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185AE4:
    ctx->pc = 0x80185AE4u;
    // 80185AE4: sth     r4, 84(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(84);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185AE8:
    ctx->pc = 0x80185AE8u;
    // 80185AE8: lhz     r4, 324(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(324);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185AEC:
    ctx->pc = 0x80185AECu;
    // 80185AEC: lhz     r5, 322(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(322);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185AF0:
    ctx->pc = 0x80185AF0u;
    // 80185AF0: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80185AF4:
    ctx->pc = 0x80185AF4u;
    // 80185AF4: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185AF8:
    ctx->pc = 0x80185AF8u;
    // 80185AF8: sth     r4, 90(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(90);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185AFC:
    ctx->pc = 0x80185AFCu;
    // 80185AFC: lhz     r4, 328(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(328);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185B00:
    ctx->pc = 0x80185B00u;
    // 80185B00: lhz     r5, 326(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(326);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185B04:
    ctx->pc = 0x80185B04u;
    // 80185B04: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80185B08:
    ctx->pc = 0x80185B08u;
    // 80185B08: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185B0C:
    ctx->pc = 0x80185B0Cu;
    // 80185B0C: sth     r4, 88(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(88);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185B10:
    ctx->pc = 0x80185B10u;
    // 80185B10: lhz     r4, 332(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(332);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185B14:
    ctx->pc = 0x80185B14u;
    // 80185B14: lhz     r5, 330(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(330);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185B18:
    ctx->pc = 0x80185B18u;
    // 80185B18: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80185B1C:
    ctx->pc = 0x80185B1Cu;
    // 80185B1C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185B20:
    ctx->pc = 0x80185B20u;
    // 80185B20: sth     r4, 94(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(94);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185B24:
    ctx->pc = 0x80185B24u;
    // 80185B24: lhz     r4, 336(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(336);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185B28:
    ctx->pc = 0x80185B28u;
    // 80185B28: lhz     r5, 334(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(334);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185B2C:
    ctx->pc = 0x80185B2Cu;
    // 80185B2C: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80185B30:
    ctx->pc = 0x80185B30u;
    // 80185B30: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185B34:
    ctx->pc = 0x80185B34u;
    // 80185B34: sth     r4, 92(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(92);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185B38:
    ctx->pc = 0x80185B38u;
    // 80185B38: lhz     r4, 340(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(340);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185B3C:
    ctx->pc = 0x80185B3Cu;
    // 80185B3C: lhz     r5, 338(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(338);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185B40:
    ctx->pc = 0x80185B40u;
    // 80185B40: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80185B44:
    ctx->pc = 0x80185B44u;
    // 80185B44: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185B48:
    ctx->pc = 0x80185B48u;
    // 80185B48: sth     r4, 98(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(98);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185B4C:
    ctx->pc = 0x80185B4Cu;
    // 80185B4C: lhz     r4, 344(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(344);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185B50:
    ctx->pc = 0x80185B50u;
    // 80185B50: lhz     r5, 342(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(342);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185B54:
    ctx->pc = 0x80185B54u;
    // 80185B54: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80185B58:
    ctx->pc = 0x80185B58u;
    // 80185B58: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185B5C:
    ctx->pc = 0x80185B5Cu;
    // 80185B5C: sth     r4, 96(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(96);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185B60:
    ctx->pc = 0x80185B60u;
    // 80185B60: lhz     r4, 348(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(348);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185B64:
    ctx->pc = 0x80185B64u;
    // 80185B64: lhz     r5, 346(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(346);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185B68:
    ctx->pc = 0x80185B68u;
    // 80185B68: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80185B6C:
    ctx->pc = 0x80185B6Cu;
    // 80185B6C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185B70:
    ctx->pc = 0x80185B70u;
    // 80185B70: sth     r4, 102(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(102);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185B74:
    ctx->pc = 0x80185B74u;
    // 80185B74: lhz     r4, 352(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(352);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185B78:
    ctx->pc = 0x80185B78u;
    // 80185B78: lhz     r5, 350(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(350);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185B7C:
    ctx->pc = 0x80185B7Cu;
    // 80185B7C: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80185B80:
    ctx->pc = 0x80185B80u;
    // 80185B80: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80185B84:
    ctx->pc = 0x80185B84u;
    // 80185B84: sth     r4, 100(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(100);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185B88:
    ctx->pc = 0x80185B88u;
    // 80185B88: sth     r0, 112(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(112);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185B8C:
    ctx->pc = 0x80185B8Cu;
    // 80185B8C: bl      0x80176EE0
    {
            ctx->lr = 0x80185B90u;
            ctx->pc = 0x80176EE0u;
            return;
    }

label_80185B90:
    ctx->pc = 0x80185B90u;
    ctx->downcount -= 6;
    // 80185B90: lbz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80185B94:
    ctx->pc = 0x80185B94u;
    // 80185B94: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80185B98:
    ctx->pc = 0x80185B98u;
    // 80185B98: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80185B9C:
    ctx->pc = 0x80185B9Cu;
    // 80185B9C: sth     r29, -26474(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26474);
        mem_write16(ctx, ea, (u16)ctx->gpr[29]);
    }

label_80185BA0:
    ctx->pc = 0x80185BA0u;
    // 80185BA0: sth     r0, -26476(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26476);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185BA4:
    ctx->pc = 0x80185BA4u;
    // 80185BA4: bl      0x801772A0
    {
            ctx->lr = 0x80185BA8u;
            ctx->pc = 0x801772A0u;
            return;
    }

label_80185BA8:
    ctx->pc = 0x80185BA8u;
    ctx->downcount -= 10;
    // 80185BA8: lhz     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read16(ctx, ea);
    }

label_80185BAC:
    ctx->pc = 0x80185BACu;
    // 80185BAC: addi    r3, r31, 276
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(276);

label_80185BB0:
    ctx->pc = 0x80185BB0u;
    // 80185BB0: addi    r28, r31, 280
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(280);

label_80185BB4:
    ctx->pc = 0x80185BB4u;
    // 80185BB4: rlwinm r0, r30, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 30u) & 0x00000001u;
    }

label_80185BB8:
    ctx->pc = 0x80185BB8u;
    // 80185BB8: stw     r0, 276(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(276);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185BBC:
    ctx->pc = 0x80185BBCu;
    // 80185BBC: rlwinm r0, r30, 24, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 24u) & 0x00000003u;
    }

label_80185BC0:
    ctx->pc = 0x80185BC0u;
    // 80185BC0: stw     r0, 280(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(280);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185BC4:
    ctx->pc = 0x80185BC4u;
    // 80185BC4: lwz     r0, 280(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(280);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185BC8:
    ctx->pc = 0x80185BC8u;
    // 80185BC8: cmplwi  r0, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80185BCC:
    ctx->pc = 0x80185BCCu;
    // 80185BCC: bc    4, 2, 0x80185BD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185BD4;
        }
    }

label_80185BD0:
    ctx->pc = 0x80185BD0u;
    ctx->downcount -= 1;
    // 80185BD0: b       0x80185BD8
    {
            goto label_80185BD8;
    }

label_80185BD4:
    ctx->pc = 0x80185BD4u;
    ctx->downcount -= 1;
    // 80185BD4: or   r29, r0, r0
    {
        ctx->gpr[29] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80185BD8:
    ctx->pc = 0x80185BD8u;
    ctx->downcount -= 4;
    // 80185BD8: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185BDC:
    ctx->pc = 0x80185BDCu;
    // 80185BDC: rlwinm r3, r29, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[29], 2u) & 0xFFFFFFFCu;
    }

label_80185BE0:
    ctx->pc = 0x80185BE0u;
    // 80185BE0: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80185BE4:
    ctx->pc = 0x80185BE4u;
    // 80185BE4: bl      0x801855C0
    {
            ctx->lr = 0x80185BE8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801855C0u;
                return;
            }
            goto label_801855C0;
    }

label_80185BE8:
    ctx->pc = 0x80185BE8u;
    ctx->downcount -= 30;
    // 80185BE8: stw     r3, 324(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(324);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80185BEC:
    ctx->pc = 0x80185BECu;
    // 80185BEC: addi    r4, r31, 324
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(324);

label_80185BF0:
    ctx->pc = 0x80185BF0u;
    // 80185BF0: li      r0, 640
    ctx->gpr[0] = (u32)(s32)(640);

label_80185BF4:
    ctx->pc = 0x80185BF4u;
    // 80185BF4: sth     r30, 2(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_80185BF8:
    ctx->pc = 0x80185BF8u;
    // 80185BF8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80185BFC:
    ctx->pc = 0x80185BFCu;
    // 80185BFC: addi    r6, r31, 246
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(246);

label_80185C00:
    ctx->pc = 0x80185C00u;
    // 80185C00: lwz     r4, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80185C04:
    ctx->pc = 0x80185C04u;
    // 80185C04: addi    r3, r31, 242
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(242);

label_80185C08:
    ctx->pc = 0x80185C08u;
    // 80185C08: stw     r4, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80185C0C:
    ctx->pc = 0x80185C0Cu;
    // 80185C0C: lwz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80185C10:
    ctx->pc = 0x80185C10u;
    // 80185C10: stw     r4, -26436(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26436);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80185C14:
    ctx->pc = 0x80185C14u;
    // 80185C14: sth     r0, 244(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(244);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185C18:
    ctx->pc = 0x80185C18u;
    // 80185C18: lwz     r4, -26440(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26440);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80185C1C:
    ctx->pc = 0x80185C1Cu;
    // 80185C1C: lhzu     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80185C20:
    ctx->pc = 0x80185C20u;
    // 80185C20: rlwinm r0, r0, 1, 16, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x0000FFFEu;
    }

label_80185C24:
    ctx->pc = 0x80185C24u;
    // 80185C24: sth     r0, 246(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(246);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185C28:
    ctx->pc = 0x80185C28u;
    // 80185C28: lhz     r0, 244(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80185C2C:
    ctx->pc = 0x80185C2Cu;
    // 80185C2C: subfic  r0, r0, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80185C30:
    ctx->pc = 0x80185C30u;
    // 80185C30: srawi r0, r0, 1
    {
        u32 sh = 1u;
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

label_80185C34:
    ctx->pc = 0x80185C34u;
    // 80185C34: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185C38:
    ctx->pc = 0x80185C38u;
    // 80185C38: sth     r0, 240(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(240);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185C3C:
    ctx->pc = 0x80185C3Cu;
    // 80185C3C: sth     r8, 242(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(242);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_80185C40:
    ctx->pc = 0x80185C40u;
    // 80185C40: lhz     r0, 244(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80185C44:
    ctx->pc = 0x80185C44u;
    // 80185C44: lha     r7, 240(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(240);
        ctx->gpr[7] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185C48:
    ctx->pc = 0x80185C48u;
    // 80185C48: lha     r5, -26476(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26476);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185C4C:
    ctx->pc = 0x80185C4Cu;
    // 80185C4C: subfic  r0, r0, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80185C50:
    ctx->pc = 0x80185C50u;
    // 80185C50: lhz     r9, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185C54:
    ctx->pc = 0x80185C54u;
    // 80185C54: add   r5, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_80185C58:
    ctx->pc = 0x80185C58u;
    // 80185C58: cmpw    r5, r0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80185C5C:
    ctx->pc = 0x80185C5Cu;
    // 80185C5C: bc    4, 1, 0x80185C64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185C64;
        }
    }

label_80185C60:
    ctx->pc = 0x80185C60u;
    ctx->downcount -= 1;
    // 80185C60: b       0x80185C78
    {
            goto label_80185C78;
    }

label_80185C64:
    ctx->pc = 0x80185C64u;
    ctx->downcount -= 2;
    // 80185C64: cmpwi   r5, 0
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

label_80185C68:
    ctx->pc = 0x80185C68u;
    // 80185C68: bc    4, 0, 0x80185C70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185C70;
        }
    }

label_80185C6C:
    ctx->pc = 0x80185C6Cu;
    ctx->downcount -= 1;
    // 80185C6C: b       0x80185C74
    {
            goto label_80185C74;
    }

label_80185C70:
    ctx->pc = 0x80185C70u;
    ctx->downcount -= 1;
    // 80185C70: or   r8, r5, r5
    {
        ctx->gpr[8] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80185C74:
    ctx->pc = 0x80185C74u;
    ctx->downcount -= 1;
    // 80185C74: or   r0, r8, r8
    {
        ctx->gpr[0] = ctx->gpr[8] | ctx->gpr[8];
    }

label_80185C78:
    ctx->pc = 0x80185C78u;
    ctx->downcount -= 5;
    // 80185C78: sth     r0, 248(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(248);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185C7C:
    ctx->pc = 0x80185C7Cu;
    // 80185C7C: addi    r8, r31, 272
    ctx->gpr[8] = ctx->gpr[31] + (u32)(s32)(272);

label_80185C80:
    ctx->pc = 0x80185C80u;
    // 80185C80: lwz     r0, 272(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185C84:
    ctx->pc = 0x80185C84u;
    // 80185C84: cmpwi   r0, 0
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

label_80185C88:
    ctx->pc = 0x80185C88u;
    // 80185C88: bc    4, 2, 0x80185C94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185C94;
        }
    }

label_80185C8C:
    ctx->pc = 0x80185C8Cu;
    ctx->downcount -= 2;
    // 80185C8C: li      r11, 2
    ctx->gpr[11] = (u32)(s32)(2);

label_80185C90:
    ctx->pc = 0x80185C90u;
    // 80185C90: b       0x80185C98
    {
            goto label_80185C98;
    }

label_80185C94:
    ctx->pc = 0x80185C94u;
    ctx->downcount -= 1;
    // 80185C94: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_80185C98:
    ctx->pc = 0x80185C98u;
    ctx->downcount -= 7;
    // 80185C98: lhz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80185C9C:
    ctx->pc = 0x80185C9Cu;
    // 80185C9C: lha     r5, -26474(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26474);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185CA0:
    ctx->pc = 0x80185CA0u;
    // 80185CA0: extsh r7, r0
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_80185CA4:
    ctx->pc = 0x80185CA4u;
    // 80185CA4: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_80185CA8:
    ctx->pc = 0x80185CA8u;
    // 80185CA8: add   r7, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80185CAC:
    ctx->pc = 0x80185CACu;
    // 80185CAC: cmpw    r7, r0
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80185CB0:
    ctx->pc = 0x80185CB0u;
    // 80185CB0: bc    4, 1, 0x80185CB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185CB8;
        }
    }

label_80185CB4:
    ctx->pc = 0x80185CB4u;
    ctx->downcount -= 1;
    // 80185CB4: b       0x80185CBC
    {
            goto label_80185CBC;
    }

label_80185CB8:
    ctx->pc = 0x80185CB8u;
    ctx->downcount -= 1;
    // 80185CB8: or   r7, r0, r0
    {
        ctx->gpr[7] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80185CBC:
    ctx->pc = 0x80185CBCu;
    ctx->downcount -= 11;
    // 80185CBC: sth     r7, 250(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(250);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80185CC0:
    ctx->pc = 0x80185CC0u;
    // 80185CC0: extsh r7, r9
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_80185CC4:
    ctx->pc = 0x80185CC4u;
    // 80185CC4: rlwinm r7, r7, 1, 0, 30
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 1u) & 0xFFFFFFFEu;
    }

label_80185CC8:
    ctx->pc = 0x80185CC8u;
    // 80185CC8: lhz     r28, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[28] = mem_read16(ctx, ea);
    }

label_80185CCC:
    ctx->pc = 0x80185CCCu;
    // 80185CCC: subf   r12, r0, r7
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[12] = res;
    }

label_80185CD0:
    ctx->pc = 0x80185CD0u;
    // 80185CD0: lha     r10, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185CD4:
    ctx->pc = 0x80185CD4u;
    // 80185CD4: extsh r7, r28
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[28];
    }

label_80185CD8:
    ctx->pc = 0x80185CD8u;
    // 80185CD8: add   r9, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80185CDC:
    ctx->pc = 0x80185CDCu;
    // 80185CDC: add   r9, r10, r9
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80185CE0:
    ctx->pc = 0x80185CE0u;
    // 80185CE0: subf.   r7, r12, r9
    {
        u32 a = ~ctx->gpr[12];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185CE4:
    ctx->pc = 0x80185CE4u;
    // 80185CE4: bc    4, 1, 0x80185CF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185CF0;
        }
    }

label_80185CE8:
    ctx->pc = 0x80185CE8u;
    ctx->downcount -= 2;
    // 80185CE8: subf   r9, r12, r9
    {
        u32 a = ~ctx->gpr[12];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80185CEC:
    ctx->pc = 0x80185CECu;
    // 80185CEC: b       0x80185CF4
    {
            goto label_80185CF4;
    }

label_80185CF0:
    ctx->pc = 0x80185CF0u;
    ctx->downcount -= 1;
    // 80185CF0: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80185CF4:
    ctx->pc = 0x80185CF4u;
    ctx->downcount -= 3;
    // 80185CF4: add   r10, r10, r5
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_80185CF8:
    ctx->pc = 0x80185CF8u;
    // 80185CF8: subf.   r7, r0, r10
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185CFC:
    ctx->pc = 0x80185CFCu;
    // 80185CFC: bc    4, 0, 0x80185D08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185D08;
        }
    }

label_80185D00:
    ctx->pc = 0x80185D00u;
    ctx->downcount -= 2;
    // 80185D00: subf   r7, r0, r10
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80185D04:
    ctx->pc = 0x80185D04u;
    // 80185D04: b       0x80185D0C
    {
            goto label_80185D0C;
    }

label_80185D08:
    ctx->pc = 0x80185D08u;
    ctx->downcount -= 1;
    // 80185D08: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80185D0C:
    ctx->pc = 0x80185D0Cu;
    ctx->downcount -= 7;
    // 80185D0C: add   r7, r28, r7
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80185D10:
    ctx->pc = 0x80185D10u;
    // 80185D10: subf   r7, r9, r7
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80185D14:
    ctx->pc = 0x80185D14u;
    // 80185D14: sth     r7, 252(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(252);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80185D18:
    ctx->pc = 0x80185D18u;
    // 80185D18: lha     r7, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[7] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185D1C:
    ctx->pc = 0x80185D1Cu;
    // 80185D1C: add   r9, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80185D20:
    ctx->pc = 0x80185D20u;
    // 80185D20: subf.   r7, r0, r9
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185D24:
    ctx->pc = 0x80185D24u;
    // 80185D24: bc    4, 0, 0x80185D30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185D30;
        }
    }

label_80185D28:
    ctx->pc = 0x80185D28u;
    ctx->downcount -= 2;
    // 80185D28: subf   r7, r0, r9
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80185D2C:
    ctx->pc = 0x80185D2Cu;
    // 80185D2C: b       0x80185D34
    {
            goto label_80185D34;
    }

label_80185D30:
    ctx->pc = 0x80185D30u;
    ctx->downcount -= 1;
    // 80185D30: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80185D34:
    ctx->pc = 0x80185D34u;
    ctx->downcount -= 50;
    // 80185D34: divw   r10, r7, r11
    {
        s32 dividend = (s32)ctx->gpr[7];
        s32 divisor = (s32)ctx->gpr[11];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[10] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80185D38:
    ctx->pc = 0x80185D38u;
    // 80185D38: addi    r7, r31, 264
    ctx->gpr[7] = ctx->gpr[31] + (u32)(s32)(264);

label_80185D3C:
    ctx->pc = 0x80185D3Cu;
    // 80185D3C: lhz     r9, 264(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(264);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80185D40:
    ctx->pc = 0x80185D40u;
    // 80185D40: subf   r9, r10, r9
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80185D44:
    ctx->pc = 0x80185D44u;
    // 80185D44: sth     r9, 254(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(254);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80185D48:
    ctx->pc = 0x80185D48u;
    // 80185D48: lha     r6, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[6] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185D4C:
    ctx->pc = 0x80185D4Cu;
    // 80185D4C: lha     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80185D50:
    ctx->pc = 0x80185D50u;
    // 80185D50: add   r6, r6, r5
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80185D54:
    ctx->pc = 0x80185D54u;
    // 80185D54: add   r6, r9, r6
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80185D58:
    ctx->pc = 0x80185D58u;
    // 80185D58: subf.   r3, r12, r6
    {
        u32 a = ~ctx->gpr[12];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185D5C:
    ctx->pc = 0x80185D5Cu;
    // 80185D5C: bc    4, 1, 0x80185D68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185D68;
        }
    }

label_80185D60:
    ctx->pc = 0x80185D60u;
    ctx->downcount -= 2;
    // 80185D60: subf   r6, r12, r6
    {
        u32 a = ~ctx->gpr[12];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_80185D64:
    ctx->pc = 0x80185D64u;
    // 80185D64: b       0x80185D6C
    {
            goto label_80185D6C;
    }

label_80185D68:
    ctx->pc = 0x80185D68u;
    ctx->downcount -= 1;
    // 80185D68: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80185D6C:
    ctx->pc = 0x80185D6Cu;
    ctx->downcount -= 3;
    // 80185D6C: add   r5, r9, r5
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_80185D70:
    ctx->pc = 0x80185D70u;
    // 80185D70: subf.   r3, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185D74:
    ctx->pc = 0x80185D74u;
    // 80185D74: bc    4, 0, 0x80185D80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185D80;
        }
    }

label_80185D78:
    ctx->pc = 0x80185D78u;
    ctx->downcount -= 2;
    // 80185D78: subf   r0, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80185D7C:
    ctx->pc = 0x80185D7Cu;
    // 80185D7C: b       0x80185D84
    {
            goto label_80185D84;
    }

label_80185D80:
    ctx->pc = 0x80185D80u;
    ctx->downcount -= 1;
    // 80185D80: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80185D84:
    ctx->pc = 0x80185D84u;
    ctx->downcount -= 107;
    // 80185D84: divw   r0, r0, r11
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[11];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80185D88:
    ctx->pc = 0x80185D88u;
    // 80185D88: lhz     r3, 268(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(268);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80185D8C:
    ctx->pc = 0x80185D8Cu;
    // 80185D8C: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80185D90:
    ctx->pc = 0x80185D90u;
    // 80185D90: divw   r5, r6, r11
    {
        s32 dividend = (s32)ctx->gpr[6];
        s32 divisor = (s32)ctx->gpr[11];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[5] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80185D94:
    ctx->pc = 0x80185D94u;
    // 80185D94: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80185D98:
    ctx->pc = 0x80185D98u;
    // 80185D98: sth     r0, 256(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(256);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185D9C:
    ctx->pc = 0x80185D9Cu;
    // 80185D9C: li      r9, 640
    ctx->gpr[9] = (u32)(s32)(640);

label_80185DA0:
    ctx->pc = 0x80185DA0u;
    // 80185DA0: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80185DA4:
    ctx->pc = 0x80185DA4u;
    // 80185DA4: sth     r9, 258(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(258);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80185DA8:
    ctx->pc = 0x80185DA8u;
    // 80185DA8: li      r5, 40
    ctx->gpr[5] = (u32)(s32)(40);

label_80185DAC:
    ctx->pc = 0x80185DACu;
    // 80185DAC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80185DB0:
    ctx->pc = 0x80185DB0u;
    // 80185DB0: lhz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80185DB4:
    ctx->pc = 0x80185DB4u;
    // 80185DB4: addi    r3, r13, -26496
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26496);

label_80185DB8:
    ctx->pc = 0x80185DB8u;
    // 80185DB8: rlwinm r6, r6, 1, 16, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0x0000FFFEu;
    }

label_80185DBC:
    ctx->pc = 0x80185DBCu;
    // 80185DBC: sth     r6, 260(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(260);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80185DC0:
    ctx->pc = 0x80185DC0u;
    // 80185DC0: sth     r28, 262(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(262);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_80185DC4:
    ctx->pc = 0x80185DC4u;
    // 80185DC4: sth     r28, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_80185DC8:
    ctx->pc = 0x80185DC8u;
    // 80185DC8: sth     r9, 266(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(266);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80185DCC:
    ctx->pc = 0x80185DCCu;
    // 80185DCC: lhz     r4, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80185DD0:
    ctx->pc = 0x80185DD0u;
    // 80185DD0: rlwinm r4, r4, 1, 16, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0x0000FFFEu;
    }

label_80185DD4:
    ctx->pc = 0x80185DD4u;
    // 80185DD4: sth     r4, 268(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(268);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80185DD8:
    ctx->pc = 0x80185DD8u;
    // 80185DD8: stw     r28, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80185DDC:
    ctx->pc = 0x80185DDCu;
    // 80185DDC: stb     r5, 284(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(284);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80185DE0:
    ctx->pc = 0x80185DE0u;
    // 80185DE0: stb     r5, 285(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(285);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80185DE4:
    ctx->pc = 0x80185DE4u;
    // 80185DE4: stb     r5, 286(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(286);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80185DE8:
    ctx->pc = 0x80185DE8u;
    // 80185DE8: stb     r28, 300(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(300);
        mem_write8(ctx, ea, (u8)ctx->gpr[28]);
    }

label_80185DEC:
    ctx->pc = 0x80185DECu;
    // 80185DEC: stw     r0, 304(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(304);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185DF0:
    ctx->pc = 0x80185DF0u;
    // 80185DF0: stw     r28, 308(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(308);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80185DF4:
    ctx->pc = 0x80185DF4u;
    // 80185DF4: bl      0x8017836C
    {
            ctx->lr = 0x80185DF8u;
            ctx->pc = 0x8017836Cu;
            return;
    }

label_80185DF8:
    ctx->pc = 0x80185DF8u;
    ctx->downcount -= 15;
    // 80185DF8: lis     r3, -13312
    ctx->gpr[3] = ((u32)(s32)(-13312) << 16);

label_80185DFC:
    ctx->pc = 0x80185DFCu;
    // 80185DFC: lhz     r0, 8240(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8240);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80185E00:
    ctx->pc = 0x80185E00u;
    // 80185E00: addi    r4, r3, 8192
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(8192);

label_80185E04:
    ctx->pc = 0x80185E04u;
    // 80185E04: addi    r5, r3, 8192
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(8192);

label_80185E08:
    ctx->pc = 0x80185E08u;
    // 80185E08: rlwinm r0, r0, 0, 17, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00007FFFu;
    }

label_80185E0C:
    ctx->pc = 0x80185E0Cu;
    // 80185E0C: sth     r0, 48(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185E10:
    ctx->pc = 0x80185E10u;
    // 80185E10: lis     r3, -32744
    ctx->gpr[3] = ((u32)(s32)(-32744) << 16);

label_80185E14:
    ctx->pc = 0x80185E14u;
    // 80185E14: addi    r4, r3, 21264
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(21264);

label_80185E18:
    ctx->pc = 0x80185E18u;
    // 80185E18: lhz     r0, 52(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80185E1C:
    ctx->pc = 0x80185E1Cu;
    // 80185E1C: li      r3, 24
    ctx->gpr[3] = (u32)(s32)(24);

label_80185E20:
    ctx->pc = 0x80185E20u;
    // 80185E20: rlwinm r0, r0, 0, 17, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00007FFFu;
    }

label_80185E24:
    ctx->pc = 0x80185E24u;
    // 80185E24: sth     r0, 52(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185E28:
    ctx->pc = 0x80185E28u;
    // 80185E28: stw     r28, -26488(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26488);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80185E2C:
    ctx->pc = 0x80185E2Cu;
    // 80185E2C: stw     r28, -26484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26484);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80185E30:
    ctx->pc = 0x80185E30u;
    // 80185E30: bl      0x80173F78
    {
            ctx->lr = 0x80185E34u;
            ctx->pc = 0x80173F78u;
            return;
    }

label_80185E34:
    ctx->pc = 0x80185E34u;
    ctx->downcount -= 2;
    // 80185E34: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_80185E38:
    ctx->pc = 0x80185E38u;
    // 80185E38: bl      0x80174418
    {
            ctx->lr = 0x80185E3Cu;
            ctx->pc = 0x80174418u;
            return;
    }

label_80185E3C:
    ctx->pc = 0x80185E3Cu;
    ctx->downcount -= 9;
    // 80185E3C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185E40:
    ctx->pc = 0x80185E40u;
    // 80185E40: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80185E44:
    ctx->pc = 0x80185E44u;
    // 80185E44: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80185E48:
    ctx->pc = 0x80185E48u;
    // 80185E48: lwz     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80185E4C:
    ctx->pc = 0x80185E4Cu;
    // 80185E4C: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80185E50:
    ctx->pc = 0x80185E50u;
    // 80185E50: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80185E54:
    ctx->pc = 0x80185E54u;
    // 80185E54: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80185E58:
    ctx->pc = 0x80185E58u;
    // 80185E58: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185E5C:
    ctx->pc = 0x80185E5Cu;
    ctx->downcount -= 6;
    // 80185E5C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80185E60:
    ctx->pc = 0x80185E60u;
    // 80185E60: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185E64:
    ctx->pc = 0x80185E64u;
    // 80185E64: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80185E68:
    ctx->pc = 0x80185E68u;
    // 80185E68: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80185E6C:
    ctx->pc = 0x80185E6Cu;
    // 80185E6C: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80185E70:
    ctx->pc = 0x80185E70u;
    // 80185E70: bl      0x80173F2C
    {
            ctx->lr = 0x80185E74u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80185E74:
    ctx->pc = 0x80185E74u;
    ctx->downcount -= 2;
    // 80185E74: lwz     r30, -26504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26504);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80185E78:
    ctx->pc = 0x80185E78u;
    // 80185E78: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80185E7C:
    ctx->downcount -= 2;
    // 80185E7C: addi    r3, r13, -26496
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26496);

label_80185E80:
    // 80185E80: bl      0x80179478
    {
            ctx->lr = 0x80185E84u;
            ctx->pc = 0x80179478u;
            return;
    }

label_80185E84:
    ctx->pc = 0x80185E84u;
    ctx->downcount -= 3;
    // 80185E84: lwz     r0, -26504(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26504);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185E88:
    // 80185E88: cmplw   r30, r0
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80185E8C:
    // 80185E8C: bc    12, 2, 0x80185E7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80185E7Cu;
                return;
            }
            goto label_80185E7C;
        }
    }

label_80185E90:
    ctx->pc = 0x80185E90u;
    ctx->downcount -= 2;
    // 80185E90: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80185E94:
    ctx->pc = 0x80185E94u;
    // 80185E94: bl      0x80173F54
    {
            ctx->lr = 0x80185E98u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80185E98:
    ctx->pc = 0x80185E98u;
    ctx->downcount -= 7;
    // 80185E98: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185E9C:
    ctx->pc = 0x80185E9Cu;
    // 80185E9C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80185EA0:
    ctx->pc = 0x80185EA0u;
    // 80185EA0: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80185EA4:
    ctx->pc = 0x80185EA4u;
    // 80185EA4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80185EA8:
    ctx->pc = 0x80185EA8u;
    // 80185EA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80185EAC:
    ctx->pc = 0x80185EACu;
    // 80185EAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185EB0:
    ctx->pc = 0x80185EB0u;
    ctx->downcount -= 10;
    // 80185EB0: lhz     r5, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80185EB4:
    ctx->pc = 0x80185EB4u;
    // 80185EB4: srawi r4, r5, 1
    {
        u32 sh = 1u;
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

label_80185EB8:
    ctx->pc = 0x80185EB8u;
    // 80185EB8: addze  r4, r4
    {
        u32 a = ctx->gpr[4];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185EBC:
    ctx->pc = 0x80185EBCu;
    // 80185EBC: srawi r0, r5, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[5];
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

label_80185EC0:
    ctx->pc = 0x80185EC0u;
    // 80185EC0: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185EC4:
    ctx->pc = 0x80185EC4u;
    // 80185EC4: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80185EC8:
    ctx->pc = 0x80185EC8u;
    // 80185EC8: subfc   r0, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185ECC:
    ctx->pc = 0x80185ECCu;
    // 80185ECC: rlwinm. r0, r0, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80185ED0:
    ctx->pc = 0x80185ED0u;
    // 80185ED0: rlwinm r4, r4, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_80185ED4:
    ctx->pc = 0x80185ED4u;
    // 80185ED4: bc    12, 2, 0x80185EE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80185EE0;
        }
    }

label_80185ED8:
    ctx->pc = 0x80185ED8u;
    ctx->downcount -= 2;
    // 80185ED8: lhz     r3, 26(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80185EDC:
    ctx->pc = 0x80185EDCu;
    // 80185EDC: b       0x80185EE4
    {
            goto label_80185EE4;
    }

label_80185EE0:
    ctx->pc = 0x80185EE0u;
    ctx->downcount -= 1;
    // 80185EE0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80185EE4:
    ctx->pc = 0x80185EE4u;
    ctx->downcount -= 18;
    // 80185EE4: addi    r0, r3, 1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(1);

label_80185EE8:
    ctx->pc = 0x80185EE8u;
    // 80185EE8: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80185EEC:
    ctx->pc = 0x80185EECu;
    // 80185EEC: addi    r5, r3, 2360
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(2360);

label_80185EF0:
    ctx->pc = 0x80185EF0u;
    // 80185EF0: sth     r0, 50(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(50);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185EF4:
    ctx->pc = 0x80185EF4u;
    // 80185EF4: addi    r0, r4, 1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1);

label_80185EF8:
    ctx->pc = 0x80185EF8u;
    // 80185EF8: ori     r0, r0, 0x1000
    ctx->gpr[0] = ctx->gpr[0] | 0x1000u;

label_80185EFC:
    ctx->pc = 0x80185EFCu;
    // 80185EFC: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80185F00:
    ctx->pc = 0x80185F00u;
    // 80185F00: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80185F04:
    ctx->pc = 0x80185F04u;
    // 80185F04: ori     r3, r3, 0x0040
    ctx->gpr[3] = ctx->gpr[3] | 0x0040u;

label_80185F08:
    ctx->pc = 0x80185F08u;
    // 80185F08: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80185F0C:
    ctx->pc = 0x80185F0Cu;
    // 80185F0C: stw     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80185F10:
    ctx->pc = 0x80185F10u;
    // 80185F10: sth     r0, 48(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185F14:
    ctx->pc = 0x80185F14u;
    // 80185F14: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80185F18:
    ctx->pc = 0x80185F18u;
    // 80185F18: lwz     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80185F1C:
    ctx->pc = 0x80185F1Cu;
    // 80185F1C: ori     r0, r0, 0x0080
    ctx->gpr[0] = ctx->gpr[0] | 0x0080u;

label_80185F20:
    ctx->pc = 0x80185F20u;
    // 80185F20: stw     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80185F24:
    ctx->pc = 0x80185F24u;
    // 80185F24: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185F28:
    ctx->pc = 0x80185F28u;
    // 80185F28: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185F2C:
    ctx->pc = 0x80185F2Cu;
    ctx->downcount -= 7;
    // 80185F2C: rlwinm r3, r3, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_80185F30:
    ctx->pc = 0x80185F30u;
    // 80185F30: addi    r0, r3, 15
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(15);

label_80185F34:
    ctx->pc = 0x80185F34u;
    // 80185F34: srawi r0, r0, 4
    {
        u32 sh = 4u;
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

label_80185F38:
    ctx->pc = 0x80185F38u;
    // 80185F38: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185F3C:
    ctx->pc = 0x80185F3Cu;
    // 80185F3C: cmpwi   r4, 0
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

label_80185F40:
    ctx->pc = 0x80185F40u;
    // 80185F40: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80185F44:
    ctx->pc = 0x80185F44u;
    // 80185F44: bc    4, 2, 0x80185F50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80185F50;
        }
    }

label_80185F48:
    ctx->pc = 0x80185F48u;
    ctx->downcount -= 2;
    // 80185F48: lbz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80185F4C:
    ctx->pc = 0x80185F4Cu;
    // 80185F4C: b       0x80185F58
    {
            goto label_80185F58;
    }

label_80185F50:
    ctx->pc = 0x80185F50u;
    ctx->downcount -= 2;
    // 80185F50: lbz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80185F54:
    ctx->pc = 0x80185F54u;
    // 80185F54: rlwinm r0, r0, 1, 24, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x000000FEu;
    }

label_80185F58:
    ctx->pc = 0x80185F58u;
    ctx->downcount -= 27;
    // 80185F58: rlwinm r3, r5, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_80185F5C:
    ctx->pc = 0x80185F5Cu;
    // 80185F5C: stb     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80185F60:
    ctx->pc = 0x80185F60u;
    // 80185F60: srawi r0, r3, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[3];
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

label_80185F64:
    ctx->pc = 0x80185F64u;
    // 80185F64: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185F68:
    ctx->pc = 0x80185F68u;
    // 80185F68: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_80185F6C:
    ctx->pc = 0x80185F6Cu;
    // 80185F6C: subfc   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185F70:
    ctx->pc = 0x80185F70u;
    // 80185F70: stb     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80185F74:
    ctx->pc = 0x80185F74u;
    // 80185F74: rlwinm r4, r6, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_80185F78:
    ctx->pc = 0x80185F78u;
    // 80185F78: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80185F7C:
    ctx->pc = 0x80185F7Cu;
    // 80185F7C: lbz     r5, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80185F80:
    ctx->pc = 0x80185F80u;
    // 80185F80: addi    r0, r4, 15
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(15);

label_80185F84:
    ctx->pc = 0x80185F84u;
    // 80185F84: addi    r3, r3, 2360
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(2360);

label_80185F88:
    ctx->pc = 0x80185F88u;
    // 80185F88: add   r0, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80185F8C:
    ctx->pc = 0x80185F8Cu;
    // 80185F8C: srawi r0, r0, 4
    {
        u32 sh = 4u;
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

label_80185F90:
    ctx->pc = 0x80185F90u;
    // 80185F90: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80185F94:
    ctx->pc = 0x80185F94u;
    // 80185F94: stb     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80185F98:
    ctx->pc = 0x80185F98u;
    // 80185F98: lis     r0, 2048
    ctx->gpr[0] = ((u32)(s32)(2048) << 16);

label_80185F9C:
    ctx->pc = 0x80185F9Cu;
    // 80185F9C: lbz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80185FA0:
    ctx->pc = 0x80185FA0u;
    // 80185FA0: lbz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80185FA4:
    ctx->pc = 0x80185FA4u;
    // 80185FA4: rlwimi r5, r4, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 8u);
        ctx->gpr[5] = (ctx->gpr[5] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_80185FA8:
    ctx->pc = 0x80185FA8u;
    // 80185FA8: sth     r5, 72(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(72);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_80185FAC:
    ctx->pc = 0x80185FACu;
    // 80185FAC: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80185FB0:
    ctx->pc = 0x80185FB0u;
    // 80185FB0: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80185FB4:
    ctx->pc = 0x80185FB4u;
    // 80185FB4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80185FB8:
    ctx->pc = 0x80185FB8u;
    // 80185FB8: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80185FBC:
    ctx->pc = 0x80185FBCu;
    // 80185FBC: stw     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80185FC0:
    ctx->pc = 0x80185FC0u;
    // 80185FC0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80185FC4:
    ctx->pc = 0x80185FC4u;
    ctx->downcount -= 47;
    // 80185FC4: lhz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80185FC8:
    ctx->pc = 0x80185FC8u;
    // 80185FC8: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80185FCC:
    ctx->pc = 0x80185FCCu;
    // 80185FCC: lbz     r5, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80185FD0:
    ctx->pc = 0x80185FD0u;
    // 80185FD0: addi    r4, r4, 2360
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(2360);

label_80185FD4:
    ctx->pc = 0x80185FD4u;
    // 80185FD4: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80185FD8:
    ctx->pc = 0x80185FD8u;
    // 80185FD8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80185FDC:
    ctx->pc = 0x80185FDCu;
    // 80185FDC: sth     r0, 22(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80185FE0:
    ctx->pc = 0x80185FE0u;
    // 80185FE0: lis     r7, 16
    ctx->gpr[7] = ((u32)(s32)(16) << 16);

label_80185FE4:
    ctx->pc = 0x80185FE4u;
    // 80185FE4: lis     r6, 32
    ctx->gpr[6] = ((u32)(s32)(32) << 16);

label_80185FE8:
    ctx->pc = 0x80185FE8u;
    // 80185FE8: lwz     r8, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80185FEC:
    ctx->pc = 0x80185FECu;
    // 80185FEC: lis     r5, 4
    ctx->gpr[5] = ((u32)(s32)(4) << 16);

label_80185FF0:
    ctx->pc = 0x80185FF0u;
    // 80185FF0: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_80185FF4:
    ctx->pc = 0x80185FF4u;
    // 80185FF4: lwz     r9, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80185FF8:
    ctx->pc = 0x80185FF8u;
    // 80185FF8: or   r7, r8, r7
    {
        ctx->gpr[7] = ctx->gpr[8] | ctx->gpr[7];
    }

label_80185FFC:
    ctx->pc = 0x80185FFCu;
    // 80185FFC: stw     r9, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80186000:
    ctx->pc = 0x80186000u;
    // 80186000: stw     r7, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80186004:
    ctx->pc = 0x80186004u;
    // 80186004: lhz     r7, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80186008:
    ctx->pc = 0x80186008u;
    // 80186008: lbz     r8, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_8018600C:
    ctx->pc = 0x8018600Cu;
    // 8018600C: rlwinm r7, r7, 5, 0, 26
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 5u) & 0xFFFFFFE0u;
    }

label_80186010:
    ctx->pc = 0x80186010u;
    // 80186010: or   r7, r8, r7
    {
        ctx->gpr[7] = ctx->gpr[8] | ctx->gpr[7];
    }

label_80186014:
    ctx->pc = 0x80186014u;
    // 80186014: sth     r7, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80186018:
    ctx->pc = 0x80186018u;
    // 80186018: lwz     r7, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8018601C:
    ctx->pc = 0x8018601Cu;
    // 8018601C: lwz     r8, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80186020:
    ctx->pc = 0x80186020u;
    // 80186020: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_80186024:
    ctx->pc = 0x80186024u;
    // 80186024: stw     r8, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80186028:
    ctx->pc = 0x80186028u;
    // 80186028: stw     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8018602C:
    ctx->pc = 0x8018602Cu;
    // 8018602C: lhz     r6, 18(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(18);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80186030:
    ctx->pc = 0x80186030u;
    // 80186030: lbz     r7, 13(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(13);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80186034:
    ctx->pc = 0x80186034u;
    // 80186034: rlwinm r6, r6, 5, 0, 26
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 5u) & 0xFFFFFFE0u;
    }

label_80186038:
    ctx->pc = 0x80186038u;
    // 80186038: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_8018603C:
    ctx->pc = 0x8018603Cu;
    // 8018603C: sth     r6, 26(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(26);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80186040:
    ctx->pc = 0x80186040u;
    // 80186040: lwz     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80186044:
    ctx->pc = 0x80186044u;
    // 80186044: lwz     r7, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80186048:
    ctx->pc = 0x80186048u;
    // 80186048: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_8018604C:
    ctx->pc = 0x8018604Cu;
    // 8018604C: stw     r7, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80186050:
    ctx->pc = 0x80186050u;
    // 80186050: stw     r5, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80186054:
    ctx->pc = 0x80186054u;
    // 80186054: lhz     r5, 22(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(22);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80186058:
    ctx->pc = 0x80186058u;
    // 80186058: lbz     r6, 15(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(15);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_8018605C:
    ctx->pc = 0x8018605Cu;
    // 8018605C: rlwinm r3, r5, 5, 0, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[5], 5u) & 0xFFFFFFE0u;
    }

label_80186060:
    ctx->pc = 0x80186060u;
    // 80186060: or   r3, r6, r3
    {
        ctx->gpr[3] = ctx->gpr[6] | ctx->gpr[3];
    }

label_80186064:
    ctx->pc = 0x80186064u;
    // 80186064: sth     r3, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80186068:
    ctx->pc = 0x80186068u;
    // 80186068: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018606C:
    ctx->pc = 0x8018606Cu;
    // 8018606C: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80186070:
    ctx->pc = 0x80186070u;
    // 80186070: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80186074:
    ctx->pc = 0x80186074u;
    // 80186074: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186078:
    ctx->pc = 0x80186078u;
    // 80186078: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018607C:
    ctx->pc = 0x8018607Cu;
    // 8018607C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80186080:
    ctx->pc = 0x80186080u;
    ctx->downcount -= 4;
    // 80186080: cmpwi   r5, 0
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

label_80186084:
    ctx->pc = 0x80186084u;
    // 80186084: lis     r5, -32697
    ctx->gpr[5] = ((u32)(s32)(-32697) << 16);

label_80186088:
    ctx->pc = 0x80186088u;
    // 80186088: addi    r5, r5, 2360
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(2360);

label_8018608C:
    ctx->pc = 0x8018608Cu;
    // 8018608C: bc    12, 2, 0x80186098
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186098;
        }
    }

label_80186090:
    ctx->pc = 0x80186090u;
    ctx->downcount -= 2;
    // 80186090: rlwinm r0, r3, 1, 15, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0x0001FFFEu;
    }

label_80186094:
    ctx->pc = 0x80186094u;
    // 80186094: b       0x8018609C
    {
            goto label_8018609C;
    }

label_80186098:
    ctx->pc = 0x80186098u;
    ctx->downcount -= 1;
    // 80186098: rlwinm r0, r3, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8018609C:
    ctx->pc = 0x8018609Cu;
    ctx->downcount -= 4;
    // 8018609C: rlwinm r6, r0, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_801860A0:
    ctx->pc = 0x801860A0u;
    // 801860A0: rlwinm r4, r4, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_801860A4:
    ctx->pc = 0x801860A4u;
    // 801860A4: cmplw   r6, r4
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801860A8:
    ctx->pc = 0x801860A8u;
    // 801860A8: bc    4, 0, 0x801860F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801860F8;
        }
    }

label_801860AC:
    ctx->pc = 0x801860ACu;
    ctx->downcount -= 58;
    // 801860AC: rlwinm r3, r6, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[6], 8u) & 0xFFFFFF00u;
    }

label_801860B0:
    ctx->pc = 0x801860B0u;
    // 801860B0: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_801860B4:
    ctx->pc = 0x801860B4u;
    // 801860B4: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801860B8:
    ctx->pc = 0x801860B8u;
    // 801860B8: divwu   r0, r0, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[0] / divisor;
    }

label_801860BC:
    ctx->pc = 0x801860BCu;
    // 801860BC: ori     r0, r0, 0x1000
    ctx->gpr[0] = ctx->gpr[0] | 0x1000u;

label_801860C0:
    ctx->pc = 0x801860C0u;
    // 801860C0: sth     r0, 74(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801860C4:
    ctx->pc = 0x801860C4u;
    // 801860C4: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_801860C8:
    ctx->pc = 0x801860C8u;
    // 801860C8: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801860CC:
    ctx->pc = 0x801860CCu;
    // 801860CC: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801860D0:
    ctx->pc = 0x801860D0u;
    // 801860D0: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_801860D4:
    ctx->pc = 0x801860D4u;
    // 801860D4: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801860D8:
    ctx->pc = 0x801860D8u;
    // 801860D8: stw     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801860DC:
    ctx->pc = 0x801860DCu;
    // 801860DC: sth     r6, 112(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(112);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_801860E0:
    ctx->pc = 0x801860E0u;
    // 801860E0: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801860E4:
    ctx->pc = 0x801860E4u;
    // 801860E4: lwz     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801860E8:
    ctx->pc = 0x801860E8u;
    // 801860E8: ori     r0, r0, 0x0080
    ctx->gpr[0] = ctx->gpr[0] | 0x0080u;

label_801860EC:
    ctx->pc = 0x801860ECu;
    // 801860EC: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801860F0:
    ctx->pc = 0x801860F0u;
    // 801860F0: stw     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801860F4:
    ctx->pc = 0x801860F4u;
    // 801860F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801860F8:
    ctx->pc = 0x801860F8u;
    ctx->downcount -= 9;
    // 801860F8: li      r0, 256
    ctx->gpr[0] = (u32)(s32)(256);

label_801860FC:
    ctx->pc = 0x801860FCu;
    // 801860FC: sth     r0, 74(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186100:
    ctx->pc = 0x80186100u;
    // 80186100: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_80186104:
    ctx->pc = 0x80186104u;
    // 80186104: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80186108:
    ctx->pc = 0x80186108u;
    // 80186108: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018610C:
    ctx->pc = 0x8018610Cu;
    // 8018610C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80186110:
    ctx->pc = 0x80186110u;
    // 80186110: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186114:
    ctx->pc = 0x80186114u;
    // 80186114: stw     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80186118:
    ctx->pc = 0x80186118u;
    // 80186118: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018611C:
    ctx->pc = 0x8018611Cu;
    ctx->downcount -= 13;
    // 8018611C: rlwinm r6, r6, 5, 19, 26
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 5u) & 0x00001FE0u;
    }

label_80186120:
    ctx->pc = 0x80186120u;
    // 80186120: rlwinm r0, r5, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_80186124:
    ctx->pc = 0x80186124u;
    // 80186124: mullw   r0, r6, r0
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_80186128:
    ctx->pc = 0x80186128u;
    // 80186128: rlwinm r4, r4, 1, 15, 26
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0x0001FFE0u;
    }

label_8018612C:
    ctx->pc = 0x8018612Cu;
    // 8018612C: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80186130:
    ctx->pc = 0x80186130u;
    // 80186130: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80186134:
    ctx->pc = 0x80186134u;
    // 80186134: cmpwi   r7, 0
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186138:
    ctx->pc = 0x80186138u;
    // 80186138: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018613C:
    ctx->pc = 0x8018613Cu;
    // 8018613C: bc    4, 2, 0x80186148
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186148;
        }
    }

label_80186140:
    ctx->pc = 0x80186140u;
    ctx->downcount -= 2;
    // 80186140: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186144:
    ctx->pc = 0x80186144u;
    // 80186144: b       0x80186150
    {
            goto label_80186150;
    }

label_80186148:
    ctx->pc = 0x80186148u;
    ctx->downcount -= 2;
    // 80186148: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018614C:
    ctx->pc = 0x8018614Cu;
    // 8018614C: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80186150:
    ctx->pc = 0x80186150u;
    ctx->downcount -= 8;
    // 80186150: rlwinm r3, r8, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x0000FFFFu;
    }

label_80186154:
    ctx->pc = 0x80186154u;
    // 80186154: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186158:
    ctx->pc = 0x80186158u;
    // 80186158: srawi r0, r3, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[3];
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

label_8018615C:
    ctx->pc = 0x8018615Cu;
    // 8018615C: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186160:
    ctx->pc = 0x80186160u;
    // 80186160: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80186164:
    ctx->pc = 0x80186164u;
    // 80186164: subfc   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186168:
    ctx->pc = 0x80186168u;
    // 80186168: cmpwi   r0, 1
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

label_8018616C:
    ctx->pc = 0x8018616Cu;
    // 8018616C: bc    4, 2, 0x80186180
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186180;
        }
    }

label_80186170:
    ctx->pc = 0x80186170u;
    ctx->downcount -= 4;
    // 80186170: lwz     r3, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80186174:
    ctx->pc = 0x80186174u;
    // 80186174: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186178:
    ctx->pc = 0x80186178u;
    // 80186178: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018617C:
    ctx->pc = 0x8018617Cu;
    // 8018617C: stw     r3, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80186180:
    ctx->pc = 0x80186180u;
    ctx->downcount -= 7;
    // 80186180: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186184:
    ctx->pc = 0x80186184u;
    // 80186184: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_80186188:
    ctx->pc = 0x80186188u;
    // 80186188: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018618C:
    ctx->pc = 0x8018618Cu;
    // 8018618C: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186190:
    ctx->pc = 0x80186190u;
    // 80186190: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_80186194:
    ctx->pc = 0x80186194u;
    // 80186194: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186198:
    ctx->pc = 0x80186198u;
    // 80186198: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018619C:
    ctx->pc = 0x8018619Cu;
    ctx->downcount -= 22;
    // 8018619C: stwu     r1, -72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-72);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801861A0:
    ctx->pc = 0x801861A0u;
    // 801861A0: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_801861A4:
    ctx->pc = 0x801861A4u;
    // 801861A4: addi    r9, r9, 2360
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2360);

label_801861A8:
    ctx->pc = 0x801861A8u;
    // 801861A8: stw     r31, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801861AC:
    ctx->pc = 0x801861ACu;
    // 801861AC: lbz     r8, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_801861B0:
    ctx->pc = 0x801861B0u;
    // 801861B0: lhz     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801861B4:
    ctx->pc = 0x801861B4u;
    // 801861B4: rlwinm r31, r8, 5, 0, 26
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[8], 5u) & 0xFFFFFFE0u;
    }

label_801861B8:
    ctx->pc = 0x801861B8u;
    // 801861B8: lhz     r8, 22(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(22);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_801861BC:
    ctx->pc = 0x801861BCu;
    // 801861BC: mullw   r0, r31, r0
    {
        s64 product = (s64)(s32)ctx->gpr[31] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_801861C0:
    ctx->pc = 0x801861C0u;
    // 801861C0: lwz     r11, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801861C4:
    ctx->pc = 0x801861C4u;
    // 801861C4: lwz     r10, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801861C8:
    ctx->pc = 0x801861C8u;
    // 801861C8: lhz     r12, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[12] = mem_read16(ctx, ea);
    }

label_801861CC:
    ctx->pc = 0x801861CCu;
    // 801861CC: rlwinm r8, r8, 1, 0, 26
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 1u) & 0xFFFFFFE0u;
    }

label_801861D0:
    ctx->pc = 0x801861D0u;
    // 801861D0: add   r0, r8, r0
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801861D4:
    ctx->pc = 0x801861D4u;
    // 801861D4: add   r0, r10, r0
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801861D8:
    ctx->pc = 0x801861D8u;
    // 801861D8: cmpwi   r11, 0
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

label_801861DC:
    ctx->pc = 0x801861DCu;
    // 801861DC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801861E0:
    ctx->pc = 0x801861E0u;
    // 801861E0: bc    4, 2, 0x801861EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801861EC;
        }
    }

label_801861E4:
    ctx->pc = 0x801861E4u;
    ctx->downcount -= 2;
    // 801861E4: lwz     r8, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801861E8:
    ctx->pc = 0x801861E8u;
    // 801861E8: b       0x801861F4
    {
            goto label_801861F4;
    }

label_801861EC:
    ctx->pc = 0x801861ECu;
    ctx->downcount -= 2;
    // 801861EC: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801861F0:
    ctx->pc = 0x801861F0u;
    // 801861F0: add   r8, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_801861F4:
    ctx->pc = 0x801861F4u;
    ctx->downcount -= 7;
    // 801861F4: srawi r0, r12, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[12];
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

label_801861F8:
    ctx->pc = 0x801861F8u;
    // 801861F8: stw     r8, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801861FC:
    ctx->pc = 0x801861FCu;
    // 801861FC: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186200:
    ctx->pc = 0x80186200u;
    // 80186200: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80186204:
    ctx->pc = 0x80186204u;
    // 80186204: subfc   r0, r0, r12
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[12];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186208:
    ctx->pc = 0x80186208u;
    // 80186208: cmpwi   r0, 1
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

label_8018620C:
    ctx->pc = 0x8018620Cu;
    // 8018620C: bc    4, 2, 0x80186220
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186220;
        }
    }

label_80186210:
    ctx->pc = 0x80186210u;
    ctx->downcount -= 4;
    // 80186210: lwz     r8, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80186214:
    ctx->pc = 0x80186214u;
    // 80186214: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186218:
    ctx->pc = 0x80186218u;
    // 80186218: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018621C:
    ctx->pc = 0x8018621Cu;
    // 8018621C: stw     r8, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80186220:
    ctx->pc = 0x80186220u;
    ctx->downcount -= 9;
    // 80186220: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186224:
    ctx->pc = 0x80186224u;
    // 80186224: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_80186228:
    ctx->pc = 0x80186228u;
    // 80186228: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018622C:
    ctx->pc = 0x8018622Cu;
    // 8018622C: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186230:
    ctx->pc = 0x80186230u;
    // 80186230: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_80186234:
    ctx->pc = 0x80186234u;
    // 80186234: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186238:
    ctx->pc = 0x80186238u;
    // 80186238: lwz     r0, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018623C:
    ctx->pc = 0x8018623Cu;
    // 8018623C: cmpwi   r0, 0
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

label_80186240:
    ctx->pc = 0x80186240u;
    // 80186240: bc    12, 2, 0x801862D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801862D0;
        }
    }

label_80186244:
    ctx->pc = 0x80186244u;
    ctx->downcount -= 18;
    // 80186244: lbz     r8, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_80186248:
    ctx->pc = 0x80186248u;
    // 80186248: lhz     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018624C:
    ctx->pc = 0x8018624Cu;
    // 8018624C: rlwinm r31, r8, 5, 0, 26
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[8], 5u) & 0xFFFFFFE0u;
    }

label_80186250:
    ctx->pc = 0x80186250u;
    // 80186250: lhz     r8, 22(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(22);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_80186254:
    ctx->pc = 0x80186254u;
    // 80186254: mullw   r0, r31, r0
    {
        s64 product = (s64)(s32)ctx->gpr[31] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_80186258:
    ctx->pc = 0x80186258u;
    // 80186258: lwz     r11, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8018625C:
    ctx->pc = 0x8018625Cu;
    // 8018625C: lwz     r10, 72(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(72);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186260:
    ctx->pc = 0x80186260u;
    // 80186260: lhz     r12, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[12] = mem_read16(ctx, ea);
    }

label_80186264:
    ctx->pc = 0x80186264u;
    // 80186264: rlwinm r8, r8, 1, 0, 26
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 1u) & 0xFFFFFFE0u;
    }

label_80186268:
    ctx->pc = 0x80186268u;
    // 80186268: add   r0, r8, r0
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8018626C:
    ctx->pc = 0x8018626Cu;
    // 8018626C: add   r0, r10, r0
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80186270:
    ctx->pc = 0x80186270u;
    // 80186270: cmpwi   r11, 0
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

label_80186274:
    ctx->pc = 0x80186274u;
    // 80186274: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186278:
    ctx->pc = 0x80186278u;
    // 80186278: bc    4, 2, 0x80186284
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186284;
        }
    }

label_8018627C:
    ctx->pc = 0x8018627Cu;
    ctx->downcount -= 2;
    // 8018627C: lwz     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80186280:
    ctx->pc = 0x80186280u;
    // 80186280: b       0x8018628C
    {
            goto label_8018628C;
    }

label_80186284:
    ctx->pc = 0x80186284u;
    ctx->downcount -= 2;
    // 80186284: lwz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186288:
    ctx->pc = 0x80186288u;
    // 80186288: add   r8, r0, r31
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8018628C:
    ctx->pc = 0x8018628Cu;
    ctx->downcount -= 7;
    // 8018628C: srawi r0, r12, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[12];
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

label_80186290:
    ctx->pc = 0x80186290u;
    // 80186290: stw     r8, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80186294:
    ctx->pc = 0x80186294u;
    // 80186294: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186298:
    ctx->pc = 0x80186298u;
    // 80186298: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_8018629C:
    ctx->pc = 0x8018629Cu;
    // 8018629C: subfc   r0, r0, r12
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[12];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801862A0:
    ctx->pc = 0x801862A0u;
    // 801862A0: cmpwi   r0, 1
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

label_801862A4:
    ctx->pc = 0x801862A4u;
    // 801862A4: bc    4, 2, 0x801862B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801862B8;
        }
    }

label_801862A8:
    ctx->pc = 0x801862A8u;
    ctx->downcount -= 4;
    // 801862A8: lwz     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801862AC:
    ctx->pc = 0x801862ACu;
    // 801862AC: lwz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801862B0:
    ctx->pc = 0x801862B0u;
    // 801862B0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801862B4:
    ctx->pc = 0x801862B4u;
    // 801862B4: stw     r8, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801862B8:
    ctx->pc = 0x801862B8u;
    ctx->downcount -= 6;
    // 801862B8: lwz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801862BC:
    ctx->pc = 0x801862BCu;
    // 801862BC: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_801862C0:
    ctx->pc = 0x801862C0u;
    // 801862C0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801862C4:
    ctx->pc = 0x801862C4u;
    // 801862C4: lwz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801862C8:
    ctx->pc = 0x801862C8u;
    // 801862C8: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_801862CC:
    ctx->pc = 0x801862CCu;
    // 801862CC: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801862D0:
    ctx->pc = 0x801862D0u;
    ctx->downcount -= 4;
    // 801862D0: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801862D4:
    ctx->pc = 0x801862D4u;
    // 801862D4: lis     r8, 256
    ctx->gpr[8] = ((u32)(s32)(256) << 16);

label_801862D8:
    ctx->pc = 0x801862D8u;
    // 801862D8: cmplw   r0, r8
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801862DC:
    ctx->pc = 0x801862DCu;
    // 801862DC: bc    4, 0, 0x8018630C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018630C;
        }
    }

label_801862E0:
    ctx->pc = 0x801862E0u;
    ctx->downcount -= 3;
    // 801862E0: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801862E4:
    ctx->pc = 0x801862E4u;
    // 801862E4: cmplw   r0, r8
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801862E8:
    ctx->pc = 0x801862E8u;
    // 801862E8: bc    4, 0, 0x8018630C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018630C;
        }
    }

label_801862EC:
    ctx->pc = 0x801862ECu;
    ctx->downcount -= 3;
    // 801862EC: lwz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801862F0:
    ctx->pc = 0x801862F0u;
    // 801862F0: cmplw   r0, r8
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801862F4:
    ctx->pc = 0x801862F4u;
    // 801862F4: bc    4, 0, 0x8018630C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018630C;
        }
    }

label_801862F8:
    ctx->pc = 0x801862F8u;
    ctx->downcount -= 3;
    // 801862F8: lwz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801862FC:
    ctx->pc = 0x801862FCu;
    // 801862FC: cmplw   r0, r8
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186300:
    ctx->pc = 0x80186300u;
    // 80186300: bc    4, 0, 0x8018630C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018630C;
        }
    }

label_80186304:
    ctx->pc = 0x80186304u;
    ctx->downcount -= 2;
    // 80186304: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80186308:
    ctx->pc = 0x80186308u;
    // 80186308: b       0x80186310
    {
            goto label_80186310;
    }

label_8018630C:
    ctx->pc = 0x8018630Cu;
    ctx->downcount -= 1;
    // 8018630C: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_80186310:
    ctx->pc = 0x80186310u;
    ctx->downcount -= 2;
    // 80186310: cmplwi  r10, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[10]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186314:
    ctx->pc = 0x80186314u;
    // 80186314: bc    12, 2, 0x80186348
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186348;
        }
    }

label_80186318:
    ctx->pc = 0x80186318u;
    ctx->downcount -= 12;
    // 80186318: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018631C:
    ctx->pc = 0x8018631Cu;
    // 8018631C: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_80186320:
    ctx->pc = 0x80186320u;
    // 80186320: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186324:
    ctx->pc = 0x80186324u;
    // 80186324: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186328:
    ctx->pc = 0x80186328u;
    // 80186328: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_8018632C:
    ctx->pc = 0x8018632Cu;
    // 8018632C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186330:
    ctx->pc = 0x80186330u;
    // 80186330: lwz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186334:
    ctx->pc = 0x80186334u;
    // 80186334: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_80186338:
    ctx->pc = 0x80186338u;
    // 80186338: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018633C:
    ctx->pc = 0x8018633Cu;
    // 8018633C: lwz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186340:
    ctx->pc = 0x80186340u;
    // 80186340: rlwinm r0, r0, 27, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x07FFFFFFu;
    }

label_80186344:
    ctx->pc = 0x80186344u;
    // 80186344: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186348:
    ctx->pc = 0x80186348u;
    ctx->downcount -= 40;
    // 80186348: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018634C:
    ctx->pc = 0x8018634Cu;
    // 8018634C: rlwinm r11, r10, 12, 0, 19
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 12u) & 0xFFFFF000u;
    }

label_80186350:
    ctx->pc = 0x80186350u;
    // 80186350: lis     r8, 1
    ctx->gpr[8] = ((u32)(s32)(1) << 16);

label_80186354:
    ctx->pc = 0x80186354u;
    // 80186354: sth     r0, 30(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186358:
    ctx->pc = 0x80186358u;
    // 80186358: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_8018635C:
    ctx->pc = 0x8018635Cu;
    // 8018635C: lwz     r10, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186360:
    ctx->pc = 0x80186360u;
    // 80186360: lwz     r12, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80186364:
    ctx->pc = 0x80186364u;
    // 80186364: or   r10, r10, r8
    {
        ctx->gpr[10] = ctx->gpr[10] | ctx->gpr[8];
    }

label_80186368:
    ctx->pc = 0x80186368u;
    // 80186368: stw     r12, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8018636C:
    ctx->pc = 0x8018636Cu;
    // 8018636C: stw     r10, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80186370:
    ctx->pc = 0x80186370u;
    // 80186370: lwz     r10, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186374:
    ctx->pc = 0x80186374u;
    // 80186374: lbz     r4, 60(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(60);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80186378:
    ctx->pc = 0x80186378u;
    // 80186378: rlwinm r10, r10, 16, 16, 31
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 16u) & 0x0000FFFFu;
    }

label_8018637C:
    ctx->pc = 0x8018637Cu;
    // 8018637C: rlwinm r4, r4, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80186380:
    ctx->pc = 0x80186380u;
    // 80186380: or   r4, r10, r4
    {
        ctx->gpr[4] = ctx->gpr[10] | ctx->gpr[4];
    }

label_80186384:
    ctx->pc = 0x80186384u;
    // 80186384: or   r4, r11, r4
    {
        ctx->gpr[4] = ctx->gpr[11] | ctx->gpr[4];
    }

label_80186388:
    ctx->pc = 0x80186388u;
    // 80186388: sth     r4, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_8018638C:
    ctx->pc = 0x8018638Cu;
    // 8018638C: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80186390:
    ctx->pc = 0x80186390u;
    // 80186390: lwz     r10, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186394:
    ctx->pc = 0x80186394u;
    // 80186394: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80186398:
    ctx->pc = 0x80186398u;
    // 80186398: stw     r10, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8018639C:
    ctx->pc = 0x8018639Cu;
    // 8018639C: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801863A0:
    ctx->pc = 0x801863A0u;
    // 801863A0: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801863A4:
    ctx->pc = 0x801863A4u;
    // 801863A4: sth     r0, 38(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(38);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801863A8:
    ctx->pc = 0x801863A8u;
    // 801863A8: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801863AC:
    ctx->pc = 0x801863ACu;
    // 801863AC: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801863B0:
    ctx->pc = 0x801863B0u;
    // 801863B0: ori     r0, r0, 0x1000
    ctx->gpr[0] = ctx->gpr[0] | 0x1000u;

label_801863B4:
    ctx->pc = 0x801863B4u;
    // 801863B4: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801863B8:
    ctx->pc = 0x801863B8u;
    // 801863B8: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801863BC:
    ctx->pc = 0x801863BCu;
    // 801863BC: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801863C0:
    ctx->pc = 0x801863C0u;
    // 801863C0: rlwinm r0, r0, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_801863C4:
    ctx->pc = 0x801863C4u;
    // 801863C4: sth     r0, 36(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(36);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801863C8:
    ctx->pc = 0x801863C8u;
    // 801863C8: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801863CC:
    ctx->pc = 0x801863CCu;
    // 801863CC: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801863D0:
    ctx->pc = 0x801863D0u;
    // 801863D0: ori     r0, r0, 0x2000
    ctx->gpr[0] = ctx->gpr[0] | 0x2000u;

label_801863D4:
    ctx->pc = 0x801863D4u;
    // 801863D4: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801863D8:
    ctx->pc = 0x801863D8u;
    // 801863D8: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801863DC:
    ctx->pc = 0x801863DCu;
    // 801863DC: lwz     r0, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801863E0:
    ctx->pc = 0x801863E0u;
    // 801863E0: cmpwi   r0, 0
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

label_801863E4:
    ctx->pc = 0x801863E4u;
    // 801863E4: bc    12, 2, 0x80186464
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186464;
        }
    }

label_801863E8:
    ctx->pc = 0x801863E8u;
    ctx->downcount -= 31;
    // 801863E8: lwz     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801863EC:
    ctx->pc = 0x801863ECu;
    // 801863EC: addi    r0, r8, -32768
    ctx->gpr[0] = ctx->gpr[8] + (u32)(s32)(-32768);

label_801863F0:
    ctx->pc = 0x801863F0u;
    // 801863F0: sth     r3, 34(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(34);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801863F4:
    ctx->pc = 0x801863F4u;
    // 801863F4: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801863F8:
    ctx->pc = 0x801863F8u;
    // 801863F8: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801863FC:
    ctx->pc = 0x801863FCu;
    // 801863FC: ori     r3, r3, 0x4000
    ctx->gpr[3] = ctx->gpr[3] | 0x4000u;

label_80186400:
    ctx->pc = 0x80186400u;
    // 80186400: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186404:
    ctx->pc = 0x80186404u;
    // 80186404: stw     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80186408:
    ctx->pc = 0x80186408u;
    // 80186408: lwz     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8018640C:
    ctx->pc = 0x8018640Cu;
    // 8018640C: rlwinm r3, r3, 16, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0x0000FFFFu;
    }

label_80186410:
    ctx->pc = 0x80186410u;
    // 80186410: sth     r3, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80186414:
    ctx->pc = 0x80186414u;
    // 80186414: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80186418:
    ctx->pc = 0x80186418u;
    // 80186418: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018641C:
    ctx->pc = 0x8018641Cu;
    // 8018641C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80186420:
    ctx->pc = 0x80186420u;
    // 80186420: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186424:
    ctx->pc = 0x80186424u;
    // 80186424: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186428:
    ctx->pc = 0x80186428u;
    // 80186428: lwz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018642C:
    ctx->pc = 0x8018642Cu;
    // 8018642C: sth     r0, 42(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186430:
    ctx->pc = 0x80186430u;
    // 80186430: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186434:
    ctx->pc = 0x80186434u;
    // 80186434: lwz     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80186438:
    ctx->pc = 0x80186438u;
    // 80186438: ori     r0, r0, 0x0400
    ctx->gpr[0] = ctx->gpr[0] | 0x0400u;

label_8018643C:
    ctx->pc = 0x8018643Cu;
    // 8018643C: stw     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80186440:
    ctx->pc = 0x80186440u;
    // 80186440: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186444:
    ctx->pc = 0x80186444u;
    // 80186444: lwz     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186448:
    ctx->pc = 0x80186448u;
    // 80186448: rlwinm r0, r0, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_8018644C:
    ctx->pc = 0x8018644Cu;
    // 8018644C: sth     r0, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186450:
    ctx->pc = 0x80186450u;
    // 80186450: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186454:
    ctx->pc = 0x80186454u;
    // 80186454: lwz     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80186458:
    ctx->pc = 0x80186458u;
    // 80186458: ori     r0, r0, 0x0800
    ctx->gpr[0] = ctx->gpr[0] | 0x0800u;

label_8018645C:
    ctx->pc = 0x8018645Cu;
    // 8018645C: stw     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80186460:
    ctx->pc = 0x80186460u;
    // 80186460: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186464:
    ctx->pc = 0x80186464u;
    ctx->downcount -= 3;
    // 80186464: lwz     r31, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80186468:
    ctx->pc = 0x80186468u;
    // 80186468: addi    r1, r1, 72
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(72);

label_8018646C:
    ctx->pc = 0x8018646Cu;
    // 8018646C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80186470:
    ctx->pc = 0x80186470u;
    ctx->downcount -= 51;
    // 80186470: lis     r6, -32697
    ctx->gpr[6] = ((u32)(s32)(-32697) << 16);

label_80186474:
    ctx->pc = 0x80186474u;
    // 80186474: lhz     r0, 26(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(26);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186478:
    ctx->pc = 0x80186478u;
    // 80186478: addi    r6, r6, 2360
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2360);

label_8018647C:
    ctx->pc = 0x8018647Cu;
    // 8018647C: sth     r0, 6(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186480:
    ctx->pc = 0x80186480u;
    // 80186480: rlwinm r0, r5, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_80186484:
    ctx->pc = 0x80186484u;
    // 80186484: lis     r5, 4096
    ctx->gpr[5] = ((u32)(s32)(4096) << 16);

label_80186488:
    ctx->pc = 0x80186488u;
    // 80186488: lwz     r8, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8018648C:
    ctx->pc = 0x8018648Cu;
    // 8018648C: rlwinm r10, r4, 0, 16, 31
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_80186490:
    ctx->pc = 0x80186490u;
    // 80186490: lis     r7, 8192
    ctx->gpr[7] = ((u32)(s32)(8192) << 16);

label_80186494:
    ctx->pc = 0x80186494u;
    // 80186494: lwz     r9, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80186498:
    ctx->pc = 0x80186498u;
    // 80186498: or   r4, r8, r5
    {
        ctx->gpr[4] = ctx->gpr[8] | ctx->gpr[5];
    }

label_8018649C:
    ctx->pc = 0x8018649Cu;
    // 8018649C: subfic  r8, r0, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[8] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801864A0:
    ctx->pc = 0x801864A0u;
    // 801864A0: stw     r9, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801864A4:
    ctx->pc = 0x801864A4u;
    // 801864A4: lis     r5, 1024
    ctx->gpr[5] = ((u32)(s32)(1024) << 16);

label_801864A8:
    ctx->pc = 0x801864A8u;
    // 801864A8: lis     r0, 2048
    ctx->gpr[0] = ((u32)(s32)(2048) << 16);

label_801864AC:
    ctx->pc = 0x801864ACu;
    // 801864AC: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801864B0:
    ctx->pc = 0x801864B0u;
    // 801864B0: lbz     r4, 29(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(29);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801864B4:
    ctx->pc = 0x801864B4u;
    // 801864B4: lbz     r9, 30(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_801864B8:
    ctx->pc = 0x801864B8u;
    // 801864B8: rlwimi r9, r4, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 8u);
        ctx->gpr[9] = (ctx->gpr[9] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_801864BC:
    ctx->pc = 0x801864BCu;
    // 801864BC: sth     r9, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_801864C0:
    ctx->pc = 0x801864C0u;
    // 801864C0: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801864C4:
    ctx->pc = 0x801864C4u;
    // 801864C4: lwz     r9, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801864C8:
    ctx->pc = 0x801864C8u;
    // 801864C8: or   r4, r4, r7
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[7];
    }

label_801864CC:
    ctx->pc = 0x801864CCu;
    // 801864CC: stw     r9, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801864D0:
    ctx->pc = 0x801864D0u;
    // 801864D0: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801864D4:
    ctx->pc = 0x801864D4u;
    // 801864D4: lbz     r4, 31(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(31);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801864D8:
    ctx->pc = 0x801864D8u;
    // 801864D8: lhz     r7, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_801864DC:
    ctx->pc = 0x801864DCu;
    // 801864DC: add   r9, r4, r10
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_801864E0:
    ctx->pc = 0x801864E0u;
    // 801864E0: lbz     r4, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801864E4:
    ctx->pc = 0x801864E4u;
    // 801864E4: addi    r9, r9, -40
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-40);

label_801864E8:
    ctx->pc = 0x801864E8u;
    // 801864E8: rlwinm r3, r9, 7, 16, 24
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[9], 7u) & 0x0000FF80u;
    }

label_801864EC:
    ctx->pc = 0x801864ECu;
    // 801864EC: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_801864F0:
    ctx->pc = 0x801864F0u;
    // 801864F0: sth     r3, 10(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801864F4:
    ctx->pc = 0x801864F4u;
    // 801864F4: add   r3, r7, r10
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801864F8:
    ctx->pc = 0x801864F8u;
    // 801864F8: addi    r3, r3, 40
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(40);

label_801864FC:
    ctx->pc = 0x801864FCu;
    // 801864FC: lwz     r7, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80186500:
    ctx->pc = 0x80186500u;
    // 80186500: subf   r3, r8, r3
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80186504:
    ctx->pc = 0x80186504u;
    // 80186504: rlwinm r4, r9, 23, 9, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[9], 23u) & 0x007FFFFFu;
    }

label_80186508:
    ctx->pc = 0x80186508u;
    // 80186508: lwz     r8, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8018650C:
    ctx->pc = 0x8018650Cu;
    // 8018650C: rlwinm r3, r3, 1, 0, 30
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0xFFFFFFFEu;
    }

label_80186510:
    ctx->pc = 0x80186510u;
    // 80186510: or   r5, r7, r5
    {
        ctx->gpr[5] = ctx->gpr[7] | ctx->gpr[5];
    }

label_80186514:
    ctx->pc = 0x80186514u;
    // 80186514: stw     r8, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80186518:
    ctx->pc = 0x80186518u;
    // 80186518: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8018651C:
    ctx->pc = 0x8018651Cu;
    // 8018651C: stw     r5, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80186520:
    ctx->pc = 0x80186520u;
    // 80186520: sth     r3, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80186524:
    ctx->pc = 0x80186524u;
    // 80186524: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80186528:
    ctx->pc = 0x80186528u;
    // 80186528: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018652C:
    ctx->pc = 0x8018652Cu;
    // 8018652C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80186530:
    ctx->pc = 0x80186530u;
    // 80186530: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186534:
    ctx->pc = 0x80186534u;
    // 80186534: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186538:
    ctx->pc = 0x80186538u;
    // 80186538: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_8018653C:
    ctx->pc = 0x8018653Cu;
    ctx->downcount -= 10;
    // 8018653C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80186540:
    ctx->pc = 0x80186540u;
    // 80186540: rlwinm r0, r5, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80186544:
    ctx->pc = 0x80186544u;
    // 80186544: lis     r11, -32697
    ctx->gpr[11] = ((u32)(s32)(-32697) << 16);

label_80186548:
    ctx->pc = 0x80186548u;
    // 80186548: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8018654C:
    ctx->pc = 0x8018654Cu;
    // 8018654C: cmplwi  r0, 0x000A
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x000Au);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186550:
    ctx->pc = 0x80186550u;
    // 80186550: lwz     r31, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80186554:
    ctx->pc = 0x80186554u;
    // 80186554: addi    r11, r11, 2360
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2360);

label_80186558:
    ctx->pc = 0x80186558u;
    // 80186558: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8018655C:
    ctx->pc = 0x8018655Cu;
    // 8018655C: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80186560:
    ctx->pc = 0x80186560u;
    // 80186560: bc    12, 0, 0x80186570
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186570;
        }
    }

label_80186564:
    ctx->pc = 0x80186564u;
    ctx->downcount -= 3;
    // 80186564: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_80186568:
    ctx->pc = 0x80186568u;
    // 80186568: li      r29, 2
    ctx->gpr[29] = (u32)(s32)(2);

label_8018656C:
    ctx->pc = 0x8018656Cu;
    // 8018656C: b       0x80186578
    {
            goto label_80186578;
    }

label_80186570:
    ctx->pc = 0x80186570u;
    ctx->downcount -= 2;
    // 80186570: li      r12, 2
    ctx->gpr[12] = (u32)(s32)(2);

label_80186574:
    ctx->pc = 0x80186574u;
    // 80186574: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_80186578:
    ctx->pc = 0x80186578u;
    ctx->downcount -= 6;
    // 80186578: rlwinm r30, r3, 0, 16, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8018657C:
    ctx->pc = 0x8018657Cu;
    // 8018657C: srawi r0, r30, 1
    {
        u32 sh = 1u;
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

label_80186580:
    ctx->pc = 0x80186580u;
    // 80186580: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186584:
    ctx->pc = 0x80186584u;
    // 80186584: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80186588:
    ctx->pc = 0x80186588u;
    // 80186588: subfc.   r0, r0, r30
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018658C:
    ctx->pc = 0x8018658Cu;
    // 8018658C: bc    4, 2, 0x801865C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801865C8;
        }
    }

label_80186590:
    ctx->pc = 0x80186590u;
    ctx->downcount -= 26;
    // 80186590: rlwinm r3, r12, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x0000FFFFu;
    }

label_80186594:
    ctx->pc = 0x80186594u;
    // 80186594: rlwinm r0, r6, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_80186598:
    ctx->pc = 0x80186598u;
    // 80186598: mullw   r0, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_8018659C:
    ctx->pc = 0x8018659Cu;
    // 8018659C: rlwinm r3, r4, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_801865A0:
    ctx->pc = 0x801865A0u;
    // 801865A0: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801865A4:
    ctx->pc = 0x801865A4u;
    // 801865A4: rlwinm r3, r29, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x0000FFFFu;
    }

label_801865A8:
    ctx->pc = 0x801865A8u;
    // 801865A8: mullw   r29, r3, r30
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[30];
        ctx->gpr[29] = (u32)product;
    }

label_801865AC:
    ctx->pc = 0x801865ACu;
    // 801865AC: subf   r0, r30, r0
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801865B0:
    ctx->pc = 0x801865B0u;
    // 801865B0: mullw   r30, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[30] = (u32)product;
    }

label_801865B4:
    ctx->pc = 0x801865B4u;
    // 801865B4: add   r0, r7, r29
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801865B8:
    ctx->pc = 0x801865B8u;
    // 801865B8: add   r6, r9, r30
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_801865BC:
    ctx->pc = 0x801865BCu;
    // 801865BC: add   r3, r8, r29
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801865C0:
    ctx->pc = 0x801865C0u;
    // 801865C0: add   r7, r10, r30
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_801865C4:
    ctx->pc = 0x801865C4u;
    // 801865C4: b       0x801865FC
    {
            goto label_801865FC;
    }

label_801865C8:
    ctx->pc = 0x801865C8u;
    ctx->downcount -= 25;
    // 801865C8: rlwinm r3, r12, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x0000FFFFu;
    }

label_801865CC:
    ctx->pc = 0x801865CCu;
    // 801865CC: rlwinm r0, r6, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_801865D0:
    ctx->pc = 0x801865D0u;
    // 801865D0: mullw   r0, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_801865D4:
    ctx->pc = 0x801865D4u;
    // 801865D4: rlwinm r3, r4, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_801865D8:
    ctx->pc = 0x801865D8u;
    // 801865D8: subf   r0, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801865DC:
    ctx->pc = 0x801865DCu;
    // 801865DC: rlwinm r3, r29, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x0000FFFFu;
    }

label_801865E0:
    ctx->pc = 0x801865E0u;
    // 801865E0: mullw   r29, r3, r30
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[30];
        ctx->gpr[29] = (u32)product;
    }

label_801865E4:
    ctx->pc = 0x801865E4u;
    // 801865E4: subf   r0, r30, r0
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801865E8:
    ctx->pc = 0x801865E8u;
    // 801865E8: mullw   r30, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[30] = (u32)product;
    }

label_801865EC:
    ctx->pc = 0x801865ECu;
    // 801865EC: add   r0, r8, r29
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801865F0:
    ctx->pc = 0x801865F0u;
    // 801865F0: add   r6, r10, r30
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_801865F4:
    ctx->pc = 0x801865F4u;
    // 801865F4: add   r3, r7, r29
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801865F8:
    ctx->pc = 0x801865F8u;
    // 801865F8: add   r7, r9, r30
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_801865FC:
    ctx->pc = 0x801865FCu;
    ctx->downcount -= 45;
    // 801865FC: rlwinm r8, r4, 0, 16, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_80186600:
    ctx->pc = 0x80186600u;
    // 80186600: rlwinm r4, r12, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x0000FFFFu;
    }

label_80186604:
    ctx->pc = 0x80186604u;
    // 80186604: divw   r4, r8, r4
    {
        s32 dividend = (s32)ctx->gpr[8];
        s32 divisor = (s32)ctx->gpr[4];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[4] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80186608:
    ctx->pc = 0x80186608u;
    // 80186608: cmpwi   r31, 0
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

label_8018660C:
    ctx->pc = 0x8018660Cu;
    // 8018660C: rlwinm r4, r4, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_80186610:
    ctx->pc = 0x80186610u;
    // 80186610: bc    12, 2, 0x80186630
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186630;
        }
    }

label_80186614:
    ctx->pc = 0x80186614u;
    ctx->downcount -= 7;
    // 80186614: rlwinm r4, r4, 1, 0, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_80186618:
    ctx->pc = 0x80186618u;
    // 80186618: addi    r4, r4, -2
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-2);

label_8018661C:
    ctx->pc = 0x8018661Cu;
    // 8018661C: add   r0, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80186620:
    ctx->pc = 0x80186620u;
    // 80186620: add   r3, r3, r4
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80186624:
    ctx->pc = 0x80186624u;
    // 80186624: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80186628:
    ctx->pc = 0x80186628u;
    // 80186628: addi    r6, r6, 2
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(2);

label_8018662C:
    ctx->pc = 0x8018662Cu;
    // 8018662C: addi    r7, r7, 2
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(2);

label_80186630:
    ctx->pc = 0x80186630u;
    ctx->downcount -= 43;
    // 80186630: rlwinm r5, r5, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80186634:
    ctx->pc = 0x80186634u;
    // 80186634: rlwinm r4, r4, 4, 12, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0x000FFFF0u;
    }

label_80186638:
    ctx->pc = 0x80186638u;
    // 80186638: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8018663C:
    ctx->pc = 0x8018663Cu;
    // 8018663C: sth     r4, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80186640:
    ctx->pc = 0x80186640u;
    // 80186640: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_80186644:
    ctx->pc = 0x80186644u;
    // 80186644: lis     r9, 256
    ctx->gpr[9] = ((u32)(s32)(256) << 16);

label_80186648:
    ctx->pc = 0x80186648u;
    // 80186648: lwz     r5, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018664C:
    ctx->pc = 0x8018664Cu;
    // 8018664C: lis     r8, 512
    ctx->gpr[8] = ((u32)(s32)(512) << 16);

label_80186650:
    ctx->pc = 0x80186650u;
    // 80186650: lwz     r10, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186654:
    ctx->pc = 0x80186654u;
    // 80186654: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80186658:
    ctx->pc = 0x80186658u;
    // 80186658: lis     r5, 64
    ctx->gpr[5] = ((u32)(s32)(64) << 16);

label_8018665C:
    ctx->pc = 0x8018665Cu;
    // 8018665C: stw     r10, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80186660:
    ctx->pc = 0x80186660u;
    // 80186660: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186664:
    ctx->pc = 0x80186664u;
    // 80186664: lis     r4, 128
    ctx->gpr[4] = ((u32)(s32)(128) << 16);

label_80186668:
    ctx->pc = 0x80186668u;
    // 80186668: sth     r0, 14(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018666C:
    ctx->pc = 0x8018666Cu;
    // 8018666C: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186670:
    ctx->pc = 0x80186670u;
    // 80186670: lwz     r10, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186674:
    ctx->pc = 0x80186674u;
    // 80186674: or   r0, r0, r9
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[9];
    }

label_80186678:
    ctx->pc = 0x80186678u;
    // 80186678: stw     r10, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8018667C:
    ctx->pc = 0x8018667Cu;
    // 8018667C: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186680:
    ctx->pc = 0x80186680u;
    // 80186680: sth     r6, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80186684:
    ctx->pc = 0x80186684u;
    // 80186684: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186688:
    ctx->pc = 0x80186688u;
    // 80186688: lwz     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8018668C:
    ctx->pc = 0x8018668Cu;
    // 8018668C: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_80186690:
    ctx->pc = 0x80186690u;
    // 80186690: stw     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80186694:
    ctx->pc = 0x80186694u;
    // 80186694: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186698:
    ctx->pc = 0x80186698u;
    // 80186698: sth     r3, 18(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(18);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8018669C:
    ctx->pc = 0x8018669Cu;
    // 8018669C: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801866A0:
    ctx->pc = 0x801866A0u;
    // 801866A0: lwz     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801866A4:
    ctx->pc = 0x801866A4u;
    // 801866A4: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_801866A8:
    ctx->pc = 0x801866A8u;
    // 801866A8: stw     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801866AC:
    ctx->pc = 0x801866ACu;
    // 801866AC: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801866B0:
    ctx->pc = 0x801866B0u;
    // 801866B0: sth     r7, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_801866B4:
    ctx->pc = 0x801866B4u;
    // 801866B4: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801866B8:
    ctx->pc = 0x801866B8u;
    // 801866B8: lwz     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801866BC:
    ctx->pc = 0x801866BCu;
    // 801866BC: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_801866C0:
    ctx->pc = 0x801866C0u;
    // 801866C0: stw     r3, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801866C4:
    ctx->pc = 0x801866C4u;
    // 801866C4: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801866C8:
    ctx->pc = 0x801866C8u;
    // 801866C8: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801866CC:
    ctx->pc = 0x801866CCu;
    // 801866CC: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801866D0:
    ctx->pc = 0x801866D0u;
    // 801866D0: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801866D4:
    ctx->pc = 0x801866D4u;
    // 801866D4: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_801866D8:
    ctx->pc = 0x801866D8u;
    // 801866D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801866DC:
    ctx->pc = 0x801866DCu;
    ctx->downcount -= 9;
    // 801866DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801866E0:
    ctx->pc = 0x801866E0u;
    // 801866E0: lis     r3, -32732
    ctx->gpr[3] = ((u32)(s32)(-32732) << 16);

label_801866E4:
    ctx->pc = 0x801866E4u;
    // 801866E4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801866E8:
    ctx->pc = 0x801866E8u;
    // 801866E8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801866EC:
    ctx->pc = 0x801866ECu;
    // 801866EC: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801866F0:
    ctx->pc = 0x801866F0u;
    // 801866F0: addi    r31, r3, -8896
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(-8896);

label_801866F4:
    ctx->pc = 0x801866F4u;
    // 801866F4: lwz     r0, -26428(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26428);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801866F8:
    ctx->pc = 0x801866F8u;
    // 801866F8: cmplwi  r0, 0x0000
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

label_801866FC:
    ctx->pc = 0x801866FCu;
    // 801866FC: bc    4, 2, 0x8018675C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018675C;
        }
    }

label_80186700:
    ctx->pc = 0x80186700u;
    ctx->downcount -= 5;
    // 80186700: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80186704:
    ctx->pc = 0x80186704u;
    // 80186704: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186708:
    ctx->pc = 0x80186708u;
    // 80186708: stw     r0, -26428(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26428);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018670C:
    ctx->pc = 0x8018670Cu;
    // 8018670C: addi    r3, r31, 444
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(444);

label_80186710:
    ctx->pc = 0x80186710u;
    // 80186710: bl      0x80172A0C
    {
            ctx->lr = 0x80186714u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186714:
    ctx->pc = 0x80186714u;
    ctx->downcount -= 3;
    // 80186714: addi    r3, r31, 488
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(488);

label_80186718:
    ctx->pc = 0x80186718u;
    // 80186718: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8018671C:
    ctx->pc = 0x8018671Cu;
    // 8018671C: bl      0x80172A0C
    {
            ctx->lr = 0x80186720u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186720:
    ctx->pc = 0x80186720u;
    ctx->downcount -= 3;
    // 80186720: addi    r3, r31, 532
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(532);

label_80186724:
    ctx->pc = 0x80186724u;
    // 80186724: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186728:
    ctx->pc = 0x80186728u;
    // 80186728: bl      0x80172A0C
    {
            ctx->lr = 0x8018672Cu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_8018672C:
    ctx->pc = 0x8018672Cu;
    ctx->downcount -= 3;
    // 8018672C: addi    r3, r31, 576
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(576);

label_80186730:
    ctx->pc = 0x80186730u;
    // 80186730: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186734:
    ctx->pc = 0x80186734u;
    // 80186734: bl      0x80172A0C
    {
            ctx->lr = 0x80186738u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186738:
    ctx->pc = 0x80186738u;
    ctx->downcount -= 3;
    // 80186738: addi    r3, r31, 620
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(620);

label_8018673C:
    ctx->pc = 0x8018673Cu;
    // 8018673C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186740:
    ctx->pc = 0x80186740u;
    // 80186740: bl      0x80172A0C
    {
            ctx->lr = 0x80186744u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186744:
    ctx->pc = 0x80186744u;
    ctx->downcount -= 3;
    // 80186744: addi    r3, r31, 664
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(664);

label_80186748:
    ctx->pc = 0x80186748u;
    // 80186748: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8018674C:
    ctx->pc = 0x8018674Cu;
    // 8018674C: bl      0x80172A0C
    {
            ctx->lr = 0x80186750u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186750:
    ctx->pc = 0x80186750u;
    ctx->downcount -= 3;
    // 80186750: addi    r3, r31, 444
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(444);

label_80186754:
    ctx->pc = 0x80186754u;
    // 80186754: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186758:
    ctx->pc = 0x80186758u;
    // 80186758: bl      0x80172A0C
    {
            ctx->lr = 0x8018675Cu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_8018675C:
    ctx->pc = 0x8018675Cu;
    ctx->downcount -= 6;
    // 8018675C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186760:
    ctx->pc = 0x80186760u;
    // 80186760: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80186764:
    ctx->pc = 0x80186764u;
    // 80186764: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80186768:
    ctx->pc = 0x80186768u;
    // 80186768: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018676C:
    ctx->pc = 0x8018676Cu;
    // 8018676C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80186770:
    ctx->pc = 0x80186770u;
    ctx->downcount -= 20;
    // 80186770: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80186774:
    ctx->pc = 0x80186774u;
    // 80186774: lis     r5, -32732
    ctx->gpr[5] = ((u32)(s32)(-32732) << 16);

label_80186778:
    ctx->pc = 0x80186778u;
    // 80186778: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018677C:
    ctx->pc = 0x8018677Cu;
    // 8018677C: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80186780:
    ctx->pc = 0x80186780u;
    // 80186780: stwu     r1, -120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-120);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80186784:
    ctx->pc = 0x80186784u;
    // 80186784: stmw     r14, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80186788:
    ctx->pc = 0x80186788u;
    // 80186788: addi    r31, r3, 0
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(0);

label_8018678C:
    ctx->pc = 0x8018678Cu;
    // 8018678C: addi    r15, r5, -8896
    ctx->gpr[15] = ctx->gpr[5] + (u32)(s32)(-8896);

label_80186790:
    ctx->pc = 0x80186790u;
    // 80186790: addi    r29, r4, 2360
    ctx->gpr[29] = ctx->gpr[4] + (u32)(s32)(2360);

label_80186794:
    ctx->pc = 0x80186794u;
    // 80186794: bl      0x80173F2C
    {
            ctx->lr = 0x80186798u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80186798:
    ctx->pc = 0x80186798u;
    ctx->downcount -= 7;
    // 80186798: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018679C:
    ctx->pc = 0x8018679Cu;
    // 8018679C: addi    r28, r29, 276
    ctx->gpr[28] = ctx->gpr[29] + (u32)(s32)(276);

label_801867A0:
    ctx->pc = 0x801867A0u;
    // 801867A0: lwz     r0, 276(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(276);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801867A4:
    ctx->pc = 0x801867A4u;
    // 801867A4: addi    r14, r3, 0
    ctx->gpr[14] = ctx->gpr[3] + (u32)(s32)(0);

label_801867A8:
    ctx->pc = 0x801867A8u;
    // 801867A8: rlwinm r4, r4, 0, 30, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000003u;
    }

label_801867AC:
    ctx->pc = 0x801867ACu;
    // 801867AC: cmplw   r0, r4
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801867B0:
    ctx->pc = 0x801867B0u;
    // 801867B0: bc    12, 2, 0x801867C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801867C0;
        }
    }

label_801867B4:
    ctx->pc = 0x801867B4u;
    ctx->downcount -= 3;
    // 801867B4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801867B8:
    ctx->pc = 0x801867B8u;
    // 801867B8: stw     r0, -26472(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26472);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801867BC:
    ctx->pc = 0x801867BCu;
    // 801867BC: stw     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801867C0:
    ctx->pc = 0x801867C0u;
    ctx->downcount -= 6;
    // 801867C0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801867C4:
    ctx->pc = 0x801867C4u;
    // 801867C4: lis     r3, -32768
    ctx->gpr[3] = ((u32)(s32)(-32768) << 16);

label_801867C8:
    ctx->pc = 0x801867C8u;
    // 801867C8: lwz     r17, 204(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(204);
        ctx->gpr[17] = mem_read32(ctx, ea);
    }

label_801867CC:
    ctx->pc = 0x801867CCu;
    // 801867CC: rlwinm r16, r0, 30, 2, 31
    {
        ctx->gpr[16] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x3FFFFFFFu;
    }

label_801867D0:
    ctx->pc = 0x801867D0u;
    // 801867D0: cmplwi  r16, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[16]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801867D4:
    ctx->pc = 0x801867D4u;
    // 801867D4: bc    4, 2, 0x80186840
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186840;
        }
    }

label_801867D8:
    ctx->pc = 0x801867D8u;
    ctx->downcount -= 3;
    // 801867D8: lwz     r0, -26428(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26428);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801867DC:
    ctx->pc = 0x801867DCu;
    // 801867DC: cmplwi  r0, 0x0000
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

label_801867E0:
    ctx->pc = 0x801867E0u;
    // 801867E0: bc    4, 2, 0x80186840
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186840;
        }
    }

label_801867E4:
    ctx->pc = 0x801867E4u;
    ctx->downcount -= 5;
    // 801867E4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801867E8:
    ctx->pc = 0x801867E8u;
    // 801867E8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801867EC:
    ctx->pc = 0x801867ECu;
    // 801867EC: stw     r0, -26428(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26428);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801867F0:
    ctx->pc = 0x801867F0u;
    // 801867F0: addi    r3, r15, 444
    ctx->gpr[3] = ctx->gpr[15] + (u32)(s32)(444);

label_801867F4:
    ctx->pc = 0x801867F4u;
    // 801867F4: bl      0x80172A0C
    {
            ctx->lr = 0x801867F8u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_801867F8:
    ctx->pc = 0x801867F8u;
    ctx->downcount -= 3;
    // 801867F8: addi    r3, r15, 488
    ctx->gpr[3] = ctx->gpr[15] + (u32)(s32)(488);

label_801867FC:
    ctx->pc = 0x801867FCu;
    // 801867FC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186800:
    ctx->pc = 0x80186800u;
    // 80186800: bl      0x80172A0C
    {
            ctx->lr = 0x80186804u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186804:
    ctx->pc = 0x80186804u;
    ctx->downcount -= 3;
    // 80186804: addi    r3, r15, 532
    ctx->gpr[3] = ctx->gpr[15] + (u32)(s32)(532);

label_80186808:
    ctx->pc = 0x80186808u;
    // 80186808: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8018680C:
    ctx->pc = 0x8018680Cu;
    // 8018680C: bl      0x80172A0C
    {
            ctx->lr = 0x80186810u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186810:
    ctx->pc = 0x80186810u;
    ctx->downcount -= 3;
    // 80186810: addi    r3, r15, 576
    ctx->gpr[3] = ctx->gpr[15] + (u32)(s32)(576);

label_80186814:
    ctx->pc = 0x80186814u;
    // 80186814: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186818:
    ctx->pc = 0x80186818u;
    // 80186818: bl      0x80172A0C
    {
            ctx->lr = 0x8018681Cu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_8018681C:
    ctx->pc = 0x8018681Cu;
    ctx->downcount -= 3;
    // 8018681C: addi    r3, r15, 620
    ctx->gpr[3] = ctx->gpr[15] + (u32)(s32)(620);

label_80186820:
    ctx->pc = 0x80186820u;
    // 80186820: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186824:
    ctx->pc = 0x80186824u;
    // 80186824: bl      0x80172A0C
    {
            ctx->lr = 0x80186828u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186828:
    ctx->pc = 0x80186828u;
    ctx->downcount -= 3;
    // 80186828: addi    r3, r15, 664
    ctx->gpr[3] = ctx->gpr[15] + (u32)(s32)(664);

label_8018682C:
    ctx->pc = 0x8018682Cu;
    // 8018682C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80186830:
    ctx->pc = 0x80186830u;
    // 80186830: bl      0x80172A0C
    {
            ctx->lr = 0x80186834u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186834:
    ctx->pc = 0x80186834u;
    ctx->downcount -= 3;
    // 80186834: addi    r3, r15, 444
    ctx->gpr[3] = ctx->gpr[15] + (u32)(s32)(444);

label_80186838:
    ctx->pc = 0x80186838u;
    // 80186838: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8018683C:
    ctx->pc = 0x8018683Cu;
    // 8018683C: bl      0x80172A0C
    {
            ctx->lr = 0x80186840u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80186840:
    ctx->pc = 0x80186840u;
    ctx->downcount -= 2;
    // 80186840: cmplwi  r16, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[16]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186844:
    ctx->pc = 0x80186844u;
    // 80186844: bc    12, 2, 0x80186850
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186850;
        }
    }

label_80186848:
    ctx->pc = 0x80186848u;
    ctx->downcount -= 2;
    // 80186848: cmplwi  r16, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[16]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018684C:
    ctx->pc = 0x8018684Cu;
    // 8018684C: bc    4, 2, 0x80186858
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186858;
        }
    }

label_80186850:
    ctx->pc = 0x80186850u;
    ctx->downcount -= 2;
    // 80186850: stw     r17, 280(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(280);
        mem_write32(ctx, ea, (u32)ctx->gpr[17]);
    }

label_80186854:
    ctx->pc = 0x80186854u;
    // 80186854: b       0x8018685C
    {
            goto label_8018685C;
    }

label_80186858:
    ctx->pc = 0x80186858u;
    ctx->downcount -= 1;
    // 80186858: stw     r16, 280(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(280);
        mem_write32(ctx, ea, (u32)ctx->gpr[16]);
    }

label_8018685C:
    ctx->pc = 0x8018685Cu;
    ctx->downcount -= 5;
    // 8018685C: lhz     r0, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186860:
    ctx->pc = 0x80186860u;
    // 80186860: sth     r0, 240(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(240);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186864:
    ctx->pc = 0x80186864u;
    // 80186864: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186868:
    ctx->pc = 0x80186868u;
    // 80186868: cmplwi  r0, 0x0001
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

label_8018686C:
    ctx->pc = 0x8018686Cu;
    // 8018686C: bc    4, 2, 0x8018687C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018687C;
        }
    }

label_80186870:
    ctx->pc = 0x80186870u;
    ctx->downcount -= 3;
    // 80186870: lhz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186874:
    ctx->pc = 0x80186874u;
    // 80186874: rlwinm r0, r0, 1, 16, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x0000FFFEu;
    }

label_80186878:
    ctx->pc = 0x80186878u;
    // 80186878: b       0x80186880
    {
            goto label_80186880;
    }

label_8018687C:
    ctx->pc = 0x8018687Cu;
    ctx->downcount -= 1;
    // 8018687C: lhz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186880:
    ctx->pc = 0x80186880u;
    ctx->downcount -= 27;
    // 80186880: sth     r0, 242(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(242);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186884:
    ctx->pc = 0x80186884u;
    // 80186884: addi    r23, r29, 242
    ctx->gpr[23] = ctx->gpr[29] + (u32)(s32)(242);

label_80186888:
    ctx->pc = 0x80186888u;
    // 80186888: addi    r24, r29, 244
    ctx->gpr[24] = ctx->gpr[29] + (u32)(s32)(244);

label_8018688C:
    ctx->pc = 0x8018688Cu;
    // 8018688C: lhz     r0, 14(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186890:
    ctx->pc = 0x80186890u;
    // 80186890: addi    r27, r29, 258
    ctx->gpr[27] = ctx->gpr[29] + (u32)(s32)(258);

label_80186894:
    ctx->pc = 0x80186894u;
    // 80186894: addi    r25, r29, 272
    ctx->gpr[25] = ctx->gpr[29] + (u32)(s32)(272);

label_80186898:
    ctx->pc = 0x80186898u;
    // 80186898: sth     r0, 244(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(244);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018689C:
    ctx->pc = 0x8018689Cu;
    // 8018689C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801868A0:
    ctx->pc = 0x801868A0u;
    // 801868A0: addi    r16, r29, 266
    ctx->gpr[16] = ctx->gpr[29] + (u32)(s32)(266);

label_801868A4:
    ctx->pc = 0x801868A4u;
    // 801868A4: lhz     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801868A8:
    ctx->pc = 0x801868A8u;
    // 801868A8: addi    r26, r29, 268
    ctx->gpr[26] = ctx->gpr[29] + (u32)(s32)(268);

label_801868AC:
    ctx->pc = 0x801868ACu;
    // 801868AC: addi    r15, r29, 262
    ctx->gpr[15] = ctx->gpr[29] + (u32)(s32)(262);

label_801868B0:
    ctx->pc = 0x801868B0u;
    // 801868B0: sth     r3, 258(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(258);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801868B4:
    ctx->pc = 0x801868B4u;
    // 801868B4: addi    r17, r29, 264
    ctx->gpr[17] = ctx->gpr[29] + (u32)(s32)(264);

label_801868B8:
    ctx->pc = 0x801868B8u;
    // 801868B8: lhz     r3, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801868BC:
    ctx->pc = 0x801868BCu;
    // 801868BC: sth     r3, 260(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(260);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801868C0:
    ctx->pc = 0x801868C0u;
    // 801868C0: lwz     r3, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801868C4:
    ctx->pc = 0x801868C4u;
    // 801868C4: stw     r3, 272(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(272);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801868C8:
    ctx->pc = 0x801868C8u;
    // 801868C8: lhz     r3, 258(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(258);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801868CC:
    ctx->pc = 0x801868CCu;
    // 801868CC: sth     r3, 266(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(266);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801868D0:
    ctx->pc = 0x801868D0u;
    // 801868D0: lhz     r3, 260(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(260);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801868D4:
    ctx->pc = 0x801868D4u;
    // 801868D4: sth     r3, 268(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(268);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_801868D8:
    ctx->pc = 0x801868D8u;
    // 801868D8: sth     r0, 262(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(262);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801868DC:
    ctx->pc = 0x801868DCu;
    // 801868DC: sth     r0, 264(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(264);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801868E0:
    ctx->pc = 0x801868E0u;
    // 801868E0: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801868E4:
    ctx->pc = 0x801868E4u;
    // 801868E4: cmplwi  r0, 0x0002
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

label_801868E8:
    ctx->pc = 0x801868E8u;
    // 801868E8: bc    4, 2, 0x801868F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801868F4;
        }
    }

label_801868EC:
    ctx->pc = 0x801868ECu;
    ctx->downcount -= 2;
    // 801868EC: lhz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_801868F0:
    ctx->pc = 0x801868F0u;
    // 801868F0: b       0x80186920
    {
            goto label_80186920;
    }

label_801868F4:
    ctx->pc = 0x801868F4u;
    ctx->downcount -= 2;
    // 801868F4: cmplwi  r0, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801868F8:
    ctx->pc = 0x801868F8u;
    // 801868F8: bc    4, 2, 0x80186904
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186904;
        }
    }

label_801868FC:
    ctx->pc = 0x801868FCu;
    ctx->downcount -= 2;
    // 801868FC: lhz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186900:
    ctx->pc = 0x80186900u;
    // 80186900: b       0x80186920
    {
            goto label_80186920;
    }

label_80186904:
    ctx->pc = 0x80186904u;
    ctx->downcount -= 3;
    // 80186904: lwz     r0, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186908:
    ctx->pc = 0x80186908u;
    // 80186908: cmpwi   r0, 0
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

label_8018690C:
    ctx->pc = 0x8018690Cu;
    // 8018690C: bc    4, 2, 0x8018691C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018691C;
        }
    }

label_80186910:
    ctx->pc = 0x80186910u;
    ctx->downcount -= 3;
    // 80186910: lhz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186914:
    ctx->pc = 0x80186914u;
    // 80186914: rlwinm r0, r0, 1, 16, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x0000FFFEu;
    }

label_80186918:
    ctx->pc = 0x80186918u;
    // 80186918: b       0x80186920
    {
            goto label_80186920;
    }

label_8018691C:
    ctx->pc = 0x8018691Cu;
    ctx->downcount -= 1;
    // 8018691C: lhz     r0, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186920:
    ctx->pc = 0x80186920u;
    ctx->downcount -= 5;
    // 80186920: addi    r22, r29, 246
    ctx->gpr[22] = ctx->gpr[29] + (u32)(s32)(246);

label_80186924:
    ctx->pc = 0x80186924u;
    // 80186924: sth     r0, 246(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(246);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186928:
    ctx->pc = 0x80186928u;
    // 80186928: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018692C:
    ctx->pc = 0x8018692Cu;
    // 8018692C: cmplwi  r0, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186930:
    ctx->pc = 0x80186930u;
    // 80186930: bc    4, 2, 0x8018693C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018693C;
        }
    }

label_80186934:
    ctx->pc = 0x80186934u;
    ctx->downcount -= 2;
    // 80186934: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80186938:
    ctx->pc = 0x80186938u;
    // 80186938: b       0x80186940
    {
            goto label_80186940;
    }

label_8018693C:
    ctx->pc = 0x8018693Cu;
    ctx->downcount -= 1;
    // 8018693C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80186940:
    ctx->pc = 0x80186940u;
    ctx->downcount -= 8;
    // 80186940: addi    r18, r29, 308
    ctx->gpr[18] = ctx->gpr[29] + (u32)(s32)(308);

label_80186944:
    ctx->pc = 0x80186944u;
    // 80186944: stw     r0, 308(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(308);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186948:
    ctx->pc = 0x80186948u;
    // 80186948: addi    r21, r29, 280
    ctx->gpr[21] = ctx->gpr[29] + (u32)(s32)(280);

label_8018694C:
    ctx->pc = 0x8018694Cu;
    // 8018694C: lwz     r3, 280(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(280);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80186950:
    ctx->pc = 0x80186950u;
    // 80186950: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186954:
    ctx->pc = 0x80186954u;
    // 80186954: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80186958:
    ctx->pc = 0x80186958u;
    // 80186958: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8018695C:
    ctx->pc = 0x8018695Cu;
    // 8018695C: bl      0x801855C0
    {
            ctx->lr = 0x80186960u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801855C0u;
                return;
            }
            goto label_801855C0;
    }

label_80186960:
    ctx->pc = 0x80186960u;
    ctx->downcount -= 10;
    // 80186960: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80186964:
    ctx->pc = 0x80186964u;
    // 80186964: stw     r30, 324(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(324);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80186968:
    ctx->pc = 0x80186968u;
    // 80186968: lhz     r0, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018696C:
    ctx->pc = 0x8018696Cu;
    // 8018696C: lha     r4, 240(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(240);
        ctx->gpr[4] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80186970:
    ctx->pc = 0x80186970u;
    // 80186970: lha     r3, -26476(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26476);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80186974:
    ctx->pc = 0x80186974u;
    // 80186974: subfic  r5, r0, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80186978:
    ctx->pc = 0x80186978u;
    // 80186978: lhz     r0, 2(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8018697C:
    ctx->pc = 0x8018697Cu;
    // 8018697C: add   r3, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80186980:
    ctx->pc = 0x80186980u;
    // 80186980: cmpw    r3, r5
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186984:
    ctx->pc = 0x80186984u;
    // 80186984: bc    4, 1, 0x8018698C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8018698C;
        }
    }

label_80186988:
    ctx->pc = 0x80186988u;
    ctx->downcount -= 1;
    // 80186988: b       0x8018699C
    {
            goto label_8018699C;
    }

label_8018698C:
    ctx->pc = 0x8018698Cu;
    ctx->downcount -= 2;
    // 8018698C: cmpwi   r3, 0
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

label_80186990:
    ctx->pc = 0x80186990u;
    // 80186990: bc    4, 0, 0x80186998
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186998;
        }
    }

label_80186994:
    ctx->pc = 0x80186994u;
    ctx->downcount -= 1;
    // 80186994: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80186998:
    ctx->pc = 0x80186998u;
    ctx->downcount -= 1;
    // 80186998: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8018699C:
    ctx->pc = 0x8018699Cu;
    ctx->downcount -= 5;
    // 8018699C: sth     r5, 248(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(248);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_801869A0:
    ctx->pc = 0x801869A0u;
    // 801869A0: addi    r3, r29, 248
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(248);

label_801869A4:
    ctx->pc = 0x801869A4u;
    // 801869A4: lwz     r4, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801869A8:
    ctx->pc = 0x801869A8u;
    // 801869A8: cmpwi   r4, 0
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

label_801869AC:
    ctx->pc = 0x801869ACu;
    // 801869AC: bc    4, 2, 0x801869B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801869B8;
        }
    }

label_801869B0:
    ctx->pc = 0x801869B0u;
    ctx->downcount -= 2;
    // 801869B0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801869B4:
    ctx->pc = 0x801869B4u;
    // 801869B4: b       0x801869BC
    {
            goto label_801869BC;
    }

label_801869B8:
    ctx->pc = 0x801869B8u;
    ctx->downcount -= 1;
    // 801869B8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801869BC:
    ctx->pc = 0x801869BCu;
    ctx->downcount -= 7;
    // 801869BC: lhz     r5, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_801869C0:
    ctx->pc = 0x801869C0u;
    // 801869C0: lha     r6, -26474(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26474);
        ctx->gpr[6] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801869C4:
    ctx->pc = 0x801869C4u;
    // 801869C4: extsh r7, r5
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[5];
    }

label_801869C8:
    ctx->pc = 0x801869C8u;
    // 801869C8: rlwinm r5, r5, 0, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000001u;
    }

label_801869CC:
    ctx->pc = 0x801869CCu;
    // 801869CC: add   r7, r7, r6
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_801869D0:
    ctx->pc = 0x801869D0u;
    // 801869D0: cmpw    r7, r5
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801869D4:
    ctx->pc = 0x801869D4u;
    // 801869D4: bc    4, 1, 0x801869DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801869DC;
        }
    }

label_801869D8:
    ctx->pc = 0x801869D8u;
    ctx->downcount -= 1;
    // 801869D8: b       0x801869E0
    {
            goto label_801869E0;
    }

label_801869DC:
    ctx->pc = 0x801869DCu;
    ctx->downcount -= 1;
    // 801869DC: or   r7, r5, r5
    {
        ctx->gpr[7] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801869E0:
    ctx->pc = 0x801869E0u;
    ctx->downcount -= 12;
    // 801869E0: sth     r7, 250(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(250);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_801869E4:
    ctx->pc = 0x801869E4u;
    // 801869E4: extsh r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_801869E8:
    ctx->pc = 0x801869E8u;
    // 801869E8: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_801869EC:
    ctx->pc = 0x801869ECu;
    // 801869EC: lhz     r8, 0(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_801869F0:
    ctx->pc = 0x801869F0u;
    // 801869F0: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_801869F4:
    ctx->pc = 0x801869F4u;
    // 801869F4: lha     r7, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[7] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801869F8:
    ctx->pc = 0x801869F8u;
    // 801869F8: addi    r19, r29, 250
    ctx->gpr[19] = ctx->gpr[29] + (u32)(s32)(250);

label_801869FC:
    ctx->pc = 0x801869FCu;
    // 801869FC: extsh r9, r8
    {
        ctx->gpr[9] = (u32)(s32)(s16)ctx->gpr[8];
    }

label_80186A00:
    ctx->pc = 0x80186A00u;
    // 80186A00: add   r10, r9, r6
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_80186A04:
    ctx->pc = 0x80186A04u;
    // 80186A04: add   r10, r7, r10
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_80186A08:
    ctx->pc = 0x80186A08u;
    // 80186A08: subf.   r9, r0, r10
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80186A0C:
    ctx->pc = 0x80186A0Cu;
    // 80186A0C: bc    4, 1, 0x80186A18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186A18;
        }
    }

label_80186A10:
    ctx->pc = 0x80186A10u;
    ctx->downcount -= 2;
    // 80186A10: subf   r9, r0, r10
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80186A14:
    ctx->pc = 0x80186A14u;
    // 80186A14: b       0x80186A1C
    {
            goto label_80186A1C;
    }

label_80186A18:
    ctx->pc = 0x80186A18u;
    ctx->downcount -= 1;
    // 80186A18: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80186A1C:
    ctx->pc = 0x80186A1Cu;
    ctx->downcount -= 3;
    // 80186A1C: add   r10, r7, r6
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_80186A20:
    ctx->pc = 0x80186A20u;
    // 80186A20: subf.   r7, r5, r10
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80186A24:
    ctx->pc = 0x80186A24u;
    // 80186A24: bc    4, 0, 0x80186A30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186A30;
        }
    }

label_80186A28:
    ctx->pc = 0x80186A28u;
    ctx->downcount -= 2;
    // 80186A28: subf   r7, r5, r10
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80186A2C:
    ctx->pc = 0x80186A2Cu;
    // 80186A2C: b       0x80186A34
    {
            goto label_80186A34;
    }

label_80186A30:
    ctx->pc = 0x80186A30u;
    ctx->downcount -= 1;
    // 80186A30: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80186A34:
    ctx->pc = 0x80186A34u;
    ctx->downcount -= 8;
    // 80186A34: add   r7, r8, r7
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80186A38:
    ctx->pc = 0x80186A38u;
    // 80186A38: subf   r7, r9, r7
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80186A3C:
    ctx->pc = 0x80186A3Cu;
    // 80186A3C: addi    r20, r29, 252
    ctx->gpr[20] = ctx->gpr[29] + (u32)(s32)(252);

label_80186A40:
    ctx->pc = 0x80186A40u;
    // 80186A40: sth     r7, 252(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(252);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80186A44:
    ctx->pc = 0x80186A44u;
    // 80186A44: lha     r7, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[7] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80186A48:
    ctx->pc = 0x80186A48u;
    // 80186A48: add   r8, r7, r6
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80186A4C:
    ctx->pc = 0x80186A4Cu;
    // 80186A4C: subf.   r7, r5, r8
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80186A50:
    ctx->pc = 0x80186A50u;
    // 80186A50: bc    4, 0, 0x80186A5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186A5C;
        }
    }

label_80186A54:
    ctx->pc = 0x80186A54u;
    ctx->downcount -= 2;
    // 80186A54: subf   r7, r5, r8
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80186A58:
    ctx->pc = 0x80186A58u;
    // 80186A58: b       0x80186A60
    {
            goto label_80186A60;
    }

label_80186A5C:
    ctx->pc = 0x80186A5Cu;
    ctx->downcount -= 1;
    // 80186A5C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80186A60:
    ctx->pc = 0x80186A60u;
    ctx->downcount -= 49;
    // 80186A60: divw   r8, r7, r4
    {
        s32 dividend = (s32)ctx->gpr[7];
        s32 divisor = (s32)ctx->gpr[4];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[8] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80186A64:
    ctx->pc = 0x80186A64u;
    // 80186A64: lhz     r7, 0(r17)
    {
        u32 ea = ctx->gpr[17] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80186A68:
    ctx->pc = 0x80186A68u;
    // 80186A68: subf   r7, r8, r7
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80186A6C:
    ctx->pc = 0x80186A6Cu;
    // 80186A6C: sth     r7, 254(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(254);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80186A70:
    ctx->pc = 0x80186A70u;
    // 80186A70: lha     r7, 0(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(0);
        ctx->gpr[7] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80186A74:
    ctx->pc = 0x80186A74u;
    // 80186A74: lha     r9, 0(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(0);
        ctx->gpr[9] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80186A78:
    ctx->pc = 0x80186A78u;
    // 80186A78: add   r8, r7, r6
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80186A7C:
    ctx->pc = 0x80186A7Cu;
    // 80186A7C: add   r8, r9, r8
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80186A80:
    ctx->pc = 0x80186A80u;
    // 80186A80: subf.   r7, r0, r8
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80186A84:
    ctx->pc = 0x80186A84u;
    // 80186A84: bc    4, 1, 0x80186A90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186A90;
        }
    }

label_80186A88:
    ctx->pc = 0x80186A88u;
    ctx->downcount -= 2;
    // 80186A88: subf   r7, r0, r8
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_80186A8C:
    ctx->pc = 0x80186A8Cu;
    // 80186A8C: b       0x80186A94
    {
            goto label_80186A94;
    }

label_80186A90:
    ctx->pc = 0x80186A90u;
    ctx->downcount -= 1;
    // 80186A90: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80186A94:
    ctx->pc = 0x80186A94u;
    ctx->downcount -= 3;
    // 80186A94: add   r6, r9, r6
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80186A98:
    ctx->pc = 0x80186A98u;
    // 80186A98: subf.   r0, r5, r6
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[6];
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

label_80186A9C:
    ctx->pc = 0x80186A9Cu;
    // 80186A9C: bc    4, 0, 0x80186AA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186AA8;
        }
    }

label_80186AA0:
    ctx->pc = 0x80186AA0u;
    ctx->downcount -= 2;
    // 80186AA0: subf   r0, r5, r6
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80186AA4:
    ctx->pc = 0x80186AA4u;
    // 80186AA4: b       0x80186AAC
    {
            goto label_80186AAC;
    }

label_80186AA8:
    ctx->pc = 0x80186AA8u;
    ctx->downcount -= 1;
    // 80186AA8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80186AAC:
    ctx->pc = 0x80186AACu;
    ctx->downcount -= 87;
    // 80186AAC: divw   r0, r0, r4
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[4];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80186AB0:
    ctx->pc = 0x80186AB0u;
    // 80186AB0: lhz     r5, 0(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80186AB4:
    ctx->pc = 0x80186AB4u;
    // 80186AB4: divw   r4, r7, r4
    {
        s32 dividend = (s32)ctx->gpr[7];
        s32 divisor = (s32)ctx->gpr[4];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[4] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80186AB8:
    ctx->pc = 0x80186AB8u;
    // 80186AB8: add   r0, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80186ABC:
    ctx->pc = 0x80186ABCu;
    // 80186ABC: subf   r0, r4, r0
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80186AC0:
    ctx->pc = 0x80186AC0u;
    // 80186AC0: sth     r0, 256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(256);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186AC4:
    ctx->pc = 0x80186AC4u;
    // 80186AC4: lwz     r0, -26480(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26480);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186AC8:
    ctx->pc = 0x80186AC8u;
    // 80186AC8: cmplwi  r0, 0x0000
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

label_80186ACC:
    ctx->pc = 0x80186ACCu;
    // 80186ACC: bc    4, 2, 0x80186AD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186AD8;
        }
    }

label_80186AD0:
    ctx->pc = 0x80186AD0u;
    ctx->downcount -= 2;
    // 80186AD0: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80186AD4:
    ctx->pc = 0x80186AD4u;
    // 80186AD4: stw     r0, 0(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186AD8:
    ctx->pc = 0x80186AD8u;
    ctx->downcount -= 10;
    // 80186AD8: lhz     r5, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80186ADC:
    ctx->pc = 0x80186ADCu;
    // 80186ADC: srawi r4, r5, 1
    {
        u32 sh = 1u;
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

label_80186AE0:
    ctx->pc = 0x80186AE0u;
    // 80186AE0: addze  r4, r4
    {
        u32 a = ctx->gpr[4];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186AE4:
    ctx->pc = 0x80186AE4u;
    // 80186AE4: srawi r0, r5, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[5];
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

label_80186AE8:
    ctx->pc = 0x80186AE8u;
    // 80186AE8: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186AEC:
    ctx->pc = 0x80186AECu;
    // 80186AEC: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80186AF0:
    ctx->pc = 0x80186AF0u;
    // 80186AF0: subfc   r0, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186AF4:
    ctx->pc = 0x80186AF4u;
    // 80186AF4: rlwinm. r0, r0, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80186AF8:
    ctx->pc = 0x80186AF8u;
    // 80186AF8: rlwinm r4, r4, 0, 16, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_80186AFC:
    ctx->pc = 0x80186AFCu;
    // 80186AFC: bc    12, 2, 0x80186B08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186B08;
        }
    }

label_80186B00:
    ctx->pc = 0x80186B00u;
    ctx->downcount -= 2;
    // 80186B00: lhz     r5, 26(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(26);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80186B04:
    ctx->pc = 0x80186B04u;
    // 80186B04: b       0x80186B0C
    {
            goto label_80186B0C;
    }

label_80186B08:
    ctx->pc = 0x80186B08u;
    ctx->downcount -= 1;
    // 80186B08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80186B0C:
    ctx->pc = 0x80186B0Cu;
    ctx->downcount -= 20;
    // 80186B0C: addi    r0, r5, 1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(1);

label_80186B10:
    ctx->pc = 0x80186B10u;
    // 80186B10: sth     r0, 50(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(50);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186B14:
    ctx->pc = 0x80186B14u;
    // 80186B14: addi    r0, r4, 1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1);

label_80186B18:
    ctx->pc = 0x80186B18u;
    // 80186B18: ori     r0, r0, 0x1000
    ctx->gpr[0] = ctx->gpr[0] | 0x1000u;

label_80186B1C:
    ctx->pc = 0x80186B1Cu;
    // 80186B1C: lwz     r5, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80186B20:
    ctx->pc = 0x80186B20u;
    // 80186B20: addi    r4, r29, 2
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(2);

label_80186B24:
    ctx->pc = 0x80186B24u;
    // 80186B24: lwz     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80186B28:
    ctx->pc = 0x80186B28u;
    // 80186B28: ori     r5, r5, 0x0040
    ctx->gpr[5] = ctx->gpr[5] | 0x0040u;

label_80186B2C:
    ctx->pc = 0x80186B2Cu;
    // 80186B2C: stw     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80186B30:
    ctx->pc = 0x80186B30u;
    // 80186B30: stw     r5, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80186B34:
    ctx->pc = 0x80186B34u;
    // 80186B34: sth     r0, 48(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186B38:
    ctx->pc = 0x80186B38u;
    // 80186B38: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186B3C:
    ctx->pc = 0x80186B3Cu;
    // 80186B3C: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80186B40:
    ctx->pc = 0x80186B40u;
    // 80186B40: ori     r0, r0, 0x0080
    ctx->gpr[0] = ctx->gpr[0] | 0x0080u;

label_80186B44:
    ctx->pc = 0x80186B44u;
    // 80186B44: stw     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80186B48:
    ctx->pc = 0x80186B48u;
    // 80186B48: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186B4C:
    ctx->pc = 0x80186B4Cu;
    // 80186B4C: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186B50:
    ctx->pc = 0x80186B50u;
    // 80186B50: lhz     r5, 2(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80186B54:
    ctx->pc = 0x80186B54u;
    // 80186B54: cmplwi  r0, 0x0002
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

label_80186B58:
    ctx->pc = 0x80186B58u;
    // 80186B58: bc    12, 2, 0x80186B64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186B64;
        }
    }

label_80186B5C:
    ctx->pc = 0x80186B5Cu;
    ctx->downcount -= 2;
    // 80186B5C: cmplwi  r0, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186B60:
    ctx->pc = 0x80186B60u;
    // 80186B60: bc    4, 2, 0x80186B70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186B70;
        }
    }

label_80186B64:
    ctx->pc = 0x80186B64u;
    ctx->downcount -= 3;
    // 80186B64: rlwinm r0, r5, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFBu;
    }

label_80186B68:
    ctx->pc = 0x80186B68u;
    // 80186B68: ori     r5, r0, 0x0004
    ctx->gpr[5] = ctx->gpr[0] | 0x0004u;

label_80186B6C:
    ctx->pc = 0x80186B6Cu;
    // 80186B6C: b       0x80186B78
    {
            goto label_80186B78;
    }

label_80186B70:
    ctx->pc = 0x80186B70u;
    ctx->downcount -= 2;
    // 80186B70: rlwinm r5, r5, 0, 30, 28
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFBu;
    }

label_80186B74:
    ctx->pc = 0x80186B74u;
    // 80186B74: rlwimi r5, r0, 2, 29, 29
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[0], 2u);
        ctx->gpr[5] = (ctx->gpr[5] & ~0x00000004u) | (rot & 0x00000004u);
    }

label_80186B78:
    ctx->pc = 0x80186B78u;
    ctx->downcount -= 7;
    // 80186B78: lwz     r6, 0(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80186B7C:
    ctx->pc = 0x80186B7Cu;
    // 80186B7C: rlwinm r5, r5, 0, 29, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF7u;
    }

label_80186B80:
    ctx->pc = 0x80186B80u;
    // 80186B80: lwz     r7, 0(r18)
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80186B84:
    ctx->pc = 0x80186B84u;
    // 80186B84: cmplwi  r6, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186B88:
    ctx->pc = 0x80186B88u;
    // 80186B88: rlwinm r0, r7, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 3u) & 0xFFFFFFF8u;
    }

label_80186B8C:
    ctx->pc = 0x80186B8Cu;
    // 80186B8C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80186B90:
    ctx->pc = 0x80186B90u;
    // 80186B90: bc    12, 2, 0x80186B9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186B9C;
        }
    }

label_80186B94:
    ctx->pc = 0x80186B94u;
    ctx->downcount -= 2;
    // 80186B94: cmplwi  r6, 0x0005
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x0005u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186B98:
    ctx->pc = 0x80186B98u;
    // 80186B98: bc    4, 2, 0x80186BA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186BA4;
        }
    }

label_80186B9C:
    ctx->pc = 0x80186B9Cu;
    ctx->downcount -= 2;
    // 80186B9C: rlwinm r0, r0, 0, 24, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFCFFu;
    }

label_80186BA0:
    ctx->pc = 0x80186BA0u;
    // 80186BA0: b       0x80186BB0
    {
            goto label_80186BB0;
    }

label_80186BA4:
    ctx->pc = 0x80186BA4u;
    ctx->downcount -= 3;
    // 80186BA4: rlwinm r5, r0, 0, 24, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFCFFu;
    }

label_80186BA8:
    ctx->pc = 0x80186BA8u;
    // 80186BA8: rlwinm r0, r6, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 8u) & 0xFFFFFF00u;
    }

label_80186BAC:
    ctx->pc = 0x80186BACu;
    // 80186BAC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80186BB0:
    ctx->pc = 0x80186BB0u;
    ctx->downcount -= 12;
    // 80186BB0: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186BB4:
    ctx->pc = 0x80186BB4u;
    // 80186BB4: lis     r0, 16384
    ctx->gpr[0] = ((u32)(s32)(16384) << 16);

label_80186BB8:
    ctx->pc = 0x80186BB8u;
    // 80186BB8: addi    r6, r29, 108
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(108);

label_80186BBC:
    ctx->pc = 0x80186BBCu;
    // 80186BBC: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80186BC0:
    ctx->pc = 0x80186BC0u;
    // 80186BC0: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80186BC4:
    ctx->pc = 0x80186BC4u;
    // 80186BC4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80186BC8:
    ctx->pc = 0x80186BC8u;
    // 80186BC8: stw     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80186BCC:
    ctx->pc = 0x80186BCCu;
    // 80186BCC: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186BD0:
    ctx->pc = 0x80186BD0u;
    // 80186BD0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186BD4:
    ctx->pc = 0x80186BD4u;
    // 80186BD4: lhz     r4, 108(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(108);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80186BD8:
    ctx->pc = 0x80186BD8u;
    // 80186BD8: cmpwi   r0, 2
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

label_80186BDC:
    ctx->pc = 0x80186BDCu;
    // 80186BDC: bc    12, 2, 0x80186BE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186BE8;
        }
    }

label_80186BE0:
    ctx->pc = 0x80186BE0u;
    ctx->downcount -= 2;
    // 80186BE0: cmpwi   r0, 3
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

label_80186BE4:
    ctx->pc = 0x80186BE4u;
    // 80186BE4: bc    4, 2, 0x80186BF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186BF4;
        }
    }

label_80186BE8:
    ctx->pc = 0x80186BE8u;
    ctx->downcount -= 3;
    // 80186BE8: rlwinm r0, r4, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFFEu;
    }

label_80186BEC:
    ctx->pc = 0x80186BECu;
    // 80186BEC: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_80186BF0:
    ctx->pc = 0x80186BF0u;
    // 80186BF0: b       0x80186BF8
    {
            goto label_80186BF8;
    }

label_80186BF4:
    ctx->pc = 0x80186BF4u;
    ctx->downcount -= 1;
    // 80186BF4: rlwinm r0, r4, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFFEu;
    }

label_80186BF8:
    ctx->pc = 0x80186BF8u;
    ctx->downcount -= 10;
    // 80186BF8: sth     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186BFC:
    ctx->pc = 0x80186BFCu;
    // 80186BFC: cmpwi   r7, 0
    {
        s32 val_a = (s32)(ctx->gpr[7]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186C00:
    ctx->pc = 0x80186C00u;
    // 80186C00: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80186C04:
    ctx->pc = 0x80186C04u;
    // 80186C04: lwz     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186C08:
    ctx->pc = 0x80186C08u;
    // 80186C08: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_80186C0C:
    ctx->pc = 0x80186C0Cu;
    // 80186C0C: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186C10:
    ctx->pc = 0x80186C10u;
    // 80186C10: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186C14:
    ctx->pc = 0x80186C14u;
    // 80186C14: lhz     r4, 0(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80186C18:
    ctx->pc = 0x80186C18u;
    // 80186C18: lhz     r5, 0(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80186C1C:
    ctx->pc = 0x80186C1Cu;
    // 80186C1C: bc    12, 2, 0x80186C28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186C28;
        }
    }

label_80186C20:
    ctx->pc = 0x80186C20u;
    ctx->downcount -= 2;
    // 80186C20: rlwinm r0, r5, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 1u) & 0xFFFFFFFEu;
    }

label_80186C24:
    ctx->pc = 0x80186C24u;
    // 80186C24: b       0x80186C2C
    {
            goto label_80186C2C;
    }

label_80186C28:
    ctx->pc = 0x80186C28u;
    ctx->downcount -= 1;
    // 80186C28: or   r0, r5, r5
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80186C2C:
    ctx->pc = 0x80186C2Cu;
    ctx->downcount -= 3;
    // 80186C2C: rlwinm r8, r0, 0, 16, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_80186C30:
    ctx->pc = 0x80186C30u;
    // 80186C30: cmplw   r8, r4
    {
        u32 val_a = (u32)(ctx->gpr[8]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186C34:
    ctx->pc = 0x80186C34u;
    // 80186C34: bc    4, 0, 0x80186C84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186C84;
        }
    }

label_80186C38:
    ctx->pc = 0x80186C38u;
    ctx->downcount -= 58;
    // 80186C38: rlwinm r6, r8, 8, 0, 23
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[8], 8u) & 0xFFFFFF00u;
    }

label_80186C3C:
    ctx->pc = 0x80186C3Cu;
    // 80186C3C: addi    r0, r6, -1
    ctx->gpr[0] = ctx->gpr[6] + (u32)(s32)(-1);

label_80186C40:
    ctx->pc = 0x80186C40u;
    // 80186C40: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80186C44:
    ctx->pc = 0x80186C44u;
    // 80186C44: divwu   r0, r0, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[0] / divisor;
    }

label_80186C48:
    ctx->pc = 0x80186C48u;
    // 80186C48: ori     r0, r0, 0x1000
    ctx->gpr[0] = ctx->gpr[0] | 0x1000u;

label_80186C4C:
    ctx->pc = 0x80186C4Cu;
    // 80186C4C: sth     r0, 74(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186C50:
    ctx->pc = 0x80186C50u;
    // 80186C50: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_80186C54:
    ctx->pc = 0x80186C54u;
    // 80186C54: lwz     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80186C58:
    ctx->pc = 0x80186C58u;
    // 80186C58: lwz     r7, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80186C5C:
    ctx->pc = 0x80186C5Cu;
    // 80186C5C: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_80186C60:
    ctx->pc = 0x80186C60u;
    // 80186C60: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186C64:
    ctx->pc = 0x80186C64u;
    // 80186C64: stw     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80186C68:
    ctx->pc = 0x80186C68u;
    // 80186C68: sth     r8, 112(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(112);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_80186C6C:
    ctx->pc = 0x80186C6Cu;
    // 80186C6C: lwz     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80186C70:
    ctx->pc = 0x80186C70u;
    // 80186C70: lwz     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186C74:
    ctx->pc = 0x80186C74u;
    // 80186C74: ori     r0, r0, 0x0080
    ctx->gpr[0] = ctx->gpr[0] | 0x0080u;

label_80186C78:
    ctx->pc = 0x80186C78u;
    // 80186C78: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186C7C:
    ctx->pc = 0x80186C7Cu;
    // 80186C7C: stw     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80186C80:
    ctx->pc = 0x80186C80u;
    // 80186C80: b       0x80186CA4
    {
            goto label_80186CA4;
    }

label_80186C84:
    ctx->pc = 0x80186C84u;
    ctx->downcount -= 8;
    // 80186C84: li      r0, 256
    ctx->gpr[0] = (u32)(s32)(256);

label_80186C88:
    ctx->pc = 0x80186C88u;
    // 80186C88: sth     r0, 74(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186C8C:
    ctx->pc = 0x80186C8Cu;
    // 80186C8C: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_80186C90:
    ctx->pc = 0x80186C90u;
    // 80186C90: lwz     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80186C94:
    ctx->pc = 0x80186C94u;
    // 80186C94: lwz     r7, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80186C98:
    ctx->pc = 0x80186C98u;
    // 80186C98: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_80186C9C:
    ctx->pc = 0x80186C9Cu;
    // 80186C9C: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186CA0:
    ctx->pc = 0x80186CA0u;
    // 80186CA0: stw     r6, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80186CA4:
    ctx->pc = 0x80186CA4u;
    ctx->downcount -= 101;
    // 80186CA4: lhz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186CA8:
    ctx->pc = 0x80186CA8u;
    // 80186CA8: subfic  r12, r4, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[12] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80186CAC:
    ctx->pc = 0x80186CACu;
    // 80186CAC: lhz     r6, 26(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(26);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80186CB0:
    ctx->pc = 0x80186CB0u;
    // 80186CB0: lis     r3, 4096
    ctx->gpr[3] = ((u32)(s32)(4096) << 16);

label_80186CB4:
    ctx->pc = 0x80186CB4u;
    // 80186CB4: lis     r8, 8192
    ctx->gpr[8] = ((u32)(s32)(8192) << 16);

label_80186CB8:
    ctx->pc = 0x80186CB8u;
    // 80186CB8: sth     r6, 6(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80186CBC:
    ctx->pc = 0x80186CBCu;
    // 80186CBC: lis     r9, 1024
    ctx->gpr[9] = ((u32)(s32)(1024) << 16);

label_80186CC0:
    ctx->pc = 0x80186CC0u;
    // 80186CC0: lis     r7, 2048
    ctx->gpr[7] = ((u32)(s32)(2048) << 16);

label_80186CC4:
    ctx->pc = 0x80186CC4u;
    // 80186CC4: lwz     r10, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186CC8:
    ctx->pc = 0x80186CC8u;
    // 80186CC8: lis     r6, 16
    ctx->gpr[6] = ((u32)(s32)(16) << 16);

label_80186CCC:
    ctx->pc = 0x80186CCCu;
    // 80186CCC: lis     r4, 32
    ctx->gpr[4] = ((u32)(s32)(32) << 16);

label_80186CD0:
    ctx->pc = 0x80186CD0u;
    // 80186CD0: lwz     r11, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80186CD4:
    ctx->pc = 0x80186CD4u;
    // 80186CD4: or   r10, r10, r3
    {
        ctx->gpr[10] = ctx->gpr[10] | ctx->gpr[3];
    }

label_80186CD8:
    ctx->pc = 0x80186CD8u;
    // 80186CD8: lis     r3, 4
    ctx->gpr[3] = ((u32)(s32)(4) << 16);

label_80186CDC:
    ctx->pc = 0x80186CDCu;
    // 80186CDC: stw     r11, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80186CE0:
    ctx->pc = 0x80186CE0u;
    // 80186CE0: stw     r10, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80186CE4:
    ctx->pc = 0x80186CE4u;
    // 80186CE4: lbz     r10, 29(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(29);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80186CE8:
    ctx->pc = 0x80186CE8u;
    // 80186CE8: lbz     r11, 30(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(30);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_80186CEC:
    ctx->pc = 0x80186CECu;
    // 80186CEC: rlwimi r11, r10, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[10], 8u);
        ctx->gpr[11] = (ctx->gpr[11] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_80186CF0:
    ctx->pc = 0x80186CF0u;
    // 80186CF0: sth     r11, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_80186CF4:
    ctx->pc = 0x80186CF4u;
    // 80186CF4: lwz     r10, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186CF8:
    ctx->pc = 0x80186CF8u;
    // 80186CF8: lwz     r11, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80186CFC:
    ctx->pc = 0x80186CFCu;
    // 80186CFC: or   r8, r10, r8
    {
        ctx->gpr[8] = ctx->gpr[10] | ctx->gpr[8];
    }

label_80186D00:
    ctx->pc = 0x80186D00u;
    // 80186D00: stw     r11, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80186D04:
    ctx->pc = 0x80186D04u;
    // 80186D04: stw     r8, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80186D08:
    ctx->pc = 0x80186D08u;
    // 80186D08: lbz     r8, 31(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(31);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_80186D0C:
    ctx->pc = 0x80186D0Cu;
    // 80186D0C: lbz     r10, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80186D10:
    ctx->pc = 0x80186D10u;
    // 80186D10: add   r16, r8, r0
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[16] = res;
    }

label_80186D14:
    ctx->pc = 0x80186D14u;
    // 80186D14: lhz     r11, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read16(ctx, ea);
    }

label_80186D18:
    ctx->pc = 0x80186D18u;
    // 80186D18: addi    r16, r16, -40
    ctx->gpr[16] = ctx->gpr[16] + (u32)(s32)(-40);

label_80186D1C:
    ctx->pc = 0x80186D1Cu;
    // 80186D1C: rlwinm r8, r16, 7, 16, 24
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[16], 7u) & 0x0000FF80u;
    }

label_80186D20:
    ctx->pc = 0x80186D20u;
    // 80186D20: or   r8, r10, r8
    {
        ctx->gpr[8] = ctx->gpr[10] | ctx->gpr[8];
    }

label_80186D24:
    ctx->pc = 0x80186D24u;
    // 80186D24: sth     r8, 10(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_80186D28:
    ctx->pc = 0x80186D28u;
    // 80186D28: add   r8, r11, r0
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80186D2C:
    ctx->pc = 0x80186D2Cu;
    // 80186D2C: addi    r0, r8, 40
    ctx->gpr[0] = ctx->gpr[8] + (u32)(s32)(40);

label_80186D30:
    ctx->pc = 0x80186D30u;
    // 80186D30: lwz     r10, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80186D34:
    ctx->pc = 0x80186D34u;
    // 80186D34: subf   r0, r12, r0
    {
        u32 a = ~ctx->gpr[12];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80186D38:
    ctx->pc = 0x80186D38u;
    // 80186D38: rlwinm r8, r16, 23, 9, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[16], 23u) & 0x007FFFFFu;
    }

label_80186D3C:
    ctx->pc = 0x80186D3Cu;
    // 80186D3C: lwz     r11, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80186D40:
    ctx->pc = 0x80186D40u;
    // 80186D40: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80186D44:
    ctx->pc = 0x80186D44u;
    // 80186D44: or   r9, r10, r9
    {
        ctx->gpr[9] = ctx->gpr[10] | ctx->gpr[9];
    }

label_80186D48:
    ctx->pc = 0x80186D48u;
    // 80186D48: stw     r11, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80186D4C:
    ctx->pc = 0x80186D4Cu;
    // 80186D4C: or   r0, r8, r0
    {
        ctx->gpr[0] = ctx->gpr[8] | ctx->gpr[0];
    }

label_80186D50:
    ctx->pc = 0x80186D50u;
    // 80186D50: stw     r9, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80186D54:
    ctx->pc = 0x80186D54u;
    // 80186D54: sth     r0, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186D58:
    ctx->pc = 0x80186D58u;
    // 80186D58: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186D5C:
    ctx->pc = 0x80186D5Cu;
    // 80186D5C: lwz     r8, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80186D60:
    ctx->pc = 0x80186D60u;
    // 80186D60: or   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[7];
    }

label_80186D64:
    ctx->pc = 0x80186D64u;
    // 80186D64: stw     r8, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80186D68:
    ctx->pc = 0x80186D68u;
    // 80186D68: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186D6C:
    ctx->pc = 0x80186D6Cu;
    // 80186D6C: lhz     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186D70:
    ctx->pc = 0x80186D70u;
    // 80186D70: lbz     r7, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80186D74:
    ctx->pc = 0x80186D74u;
    // 80186D74: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80186D78:
    ctx->pc = 0x80186D78u;
    // 80186D78: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_80186D7C:
    ctx->pc = 0x80186D7Cu;
    // 80186D7C: sth     r0, 22(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186D80:
    ctx->pc = 0x80186D80u;
    // 80186D80: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186D84:
    ctx->pc = 0x80186D84u;
    // 80186D84: lwz     r7, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80186D88:
    ctx->pc = 0x80186D88u;
    // 80186D88: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_80186D8C:
    ctx->pc = 0x80186D8Cu;
    // 80186D8C: stw     r7, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80186D90:
    ctx->pc = 0x80186D90u;
    // 80186D90: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186D94:
    ctx->pc = 0x80186D94u;
    // 80186D94: lhz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186D98:
    ctx->pc = 0x80186D98u;
    // 80186D98: lbz     r6, 14(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(14);
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80186D9C:
    ctx->pc = 0x80186D9Cu;
    // 80186D9C: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80186DA0:
    ctx->pc = 0x80186DA0u;
    // 80186DA0: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80186DA4:
    ctx->pc = 0x80186DA4u;
    // 80186DA4: sth     r0, 20(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186DA8:
    ctx->pc = 0x80186DA8u;
    // 80186DA8: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186DAC:
    ctx->pc = 0x80186DACu;
    // 80186DAC: lwz     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80186DB0:
    ctx->pc = 0x80186DB0u;
    // 80186DB0: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_80186DB4:
    ctx->pc = 0x80186DB4u;
    // 80186DB4: stw     r6, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80186DB8:
    ctx->pc = 0x80186DB8u;
    // 80186DB8: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186DBC:
    ctx->pc = 0x80186DBCu;
    // 80186DBC: lhz     r0, 18(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(18);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186DC0:
    ctx->pc = 0x80186DC0u;
    // 80186DC0: lbz     r4, 13(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(13);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80186DC4:
    ctx->pc = 0x80186DC4u;
    // 80186DC4: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80186DC8:
    ctx->pc = 0x80186DC8u;
    // 80186DC8: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80186DCC:
    ctx->pc = 0x80186DCCu;
    // 80186DCC: sth     r0, 26(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(26);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186DD0:
    ctx->pc = 0x80186DD0u;
    // 80186DD0: lwz     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186DD4:
    ctx->pc = 0x80186DD4u;
    // 80186DD4: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80186DD8:
    ctx->pc = 0x80186DD8u;
    // 80186DD8: or   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[3];
    }

label_80186DDC:
    ctx->pc = 0x80186DDCu;
    // 80186DDC: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186DE0:
    ctx->pc = 0x80186DE0u;
    // 80186DE0: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186DE4:
    ctx->pc = 0x80186DE4u;
    // 80186DE4: lhz     r0, 22(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(22);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186DE8:
    ctx->pc = 0x80186DE8u;
    // 80186DE8: lbz     r3, 15(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(15);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80186DEC:
    ctx->pc = 0x80186DECu;
    // 80186DEC: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80186DF0:
    ctx->pc = 0x80186DF0u;
    // 80186DF0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80186DF4:
    ctx->pc = 0x80186DF4u;
    // 80186DF4: sth     r0, 24(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(24);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186DF8:
    ctx->pc = 0x80186DF8u;
    // 80186DF8: lwz     r3, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80186DFC:
    ctx->pc = 0x80186DFCu;
    // 80186DFC: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_80186E00:
    ctx->pc = 0x80186E00u;
    // 80186E00: addi    r6, r29, 284
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(284);

label_80186E04:
    ctx->pc = 0x80186E04u;
    // 80186E04: lwz     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80186E08:
    ctx->pc = 0x80186E08u;
    // 80186E08: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80186E0C:
    ctx->pc = 0x80186E0Cu;
    // 80186E0C: stw     r4, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186E10:
    ctx->pc = 0x80186E10u;
    // 80186E10: stw     r0, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186E14:
    ctx->pc = 0x80186E14u;
    // 80186E14: lhz     r3, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80186E18:
    ctx->pc = 0x80186E18u;
    // 80186E18: lwz     r4, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80186E1C:
    ctx->pc = 0x80186E1Cu;
    // 80186E1C: addi    r0, r3, 15
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(15);

label_80186E20:
    ctx->pc = 0x80186E20u;
    // 80186E20: lhz     r3, 0(r15)
    {
        u32 ea = ctx->gpr[15] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80186E24:
    ctx->pc = 0x80186E24u;
    // 80186E24: srawi r0, r0, 4
    {
        u32 sh = 4u;
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

label_80186E28:
    ctx->pc = 0x80186E28u;
    // 80186E28: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186E2C:
    ctx->pc = 0x80186E2Cu;
    // 80186E2C: cmpwi   r4, 0
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

label_80186E30:
    ctx->pc = 0x80186E30u;
    // 80186E30: stb     r0, 284(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(284);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80186E34:
    ctx->pc = 0x80186E34u;
    // 80186E34: bc    4, 2, 0x80186E40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186E40;
        }
    }

label_80186E38:
    ctx->pc = 0x80186E38u;
    ctx->downcount -= 2;
    // 80186E38: lbz     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80186E3C:
    ctx->pc = 0x80186E3Cu;
    // 80186E3C: b       0x80186E48
    {
            goto label_80186E48;
    }

label_80186E40:
    ctx->pc = 0x80186E40u;
    ctx->downcount -= 2;
    // 80186E40: lbz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80186E44:
    ctx->pc = 0x80186E44u;
    // 80186E44: rlwinm r4, r0, 1, 24, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x000000FEu;
    }

label_80186E48:
    ctx->pc = 0x80186E48u;
    ctx->downcount -= 25;
    // 80186E48: srawi r0, r3, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[3];
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

label_80186E4C:
    ctx->pc = 0x80186E4Cu;
    // 80186E4C: stb     r4, 285(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(285);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80186E50:
    ctx->pc = 0x80186E50u;
    // 80186E50: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186E54:
    ctx->pc = 0x80186E54u;
    // 80186E54: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_80186E58:
    ctx->pc = 0x80186E58u;
    // 80186E58: subfc   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186E5C:
    ctx->pc = 0x80186E5Cu;
    // 80186E5C: stb     r0, 300(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(300);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80186E60:
    ctx->pc = 0x80186E60u;
    // 80186E60: addi    r0, r5, 15
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(15);

label_80186E64:
    ctx->pc = 0x80186E64u;
    // 80186E64: lis     r3, 2048
    ctx->gpr[3] = ((u32)(s32)(2048) << 16);

label_80186E68:
    ctx->pc = 0x80186E68u;
    // 80186E68: lbz     r4, 300(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(300);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80186E6C:
    ctx->pc = 0x80186E6Cu;
    // 80186E6C: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80186E70:
    ctx->pc = 0x80186E70u;
    // 80186E70: srawi r0, r0, 4
    {
        u32 sh = 4u;
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

label_80186E74:
    ctx->pc = 0x80186E74u;
    // 80186E74: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80186E78:
    ctx->pc = 0x80186E78u;
    // 80186E78: stb     r0, 286(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(286);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80186E7C:
    ctx->pc = 0x80186E7Cu;
    // 80186E7C: lbz     r0, 286(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(286);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80186E80:
    ctx->pc = 0x80186E80u;
    // 80186E80: lbz     r4, 285(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(285);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80186E84:
    ctx->pc = 0x80186E84u;
    // 80186E84: rlwimi r4, r0, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[0], 8u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_80186E88:
    ctx->pc = 0x80186E88u;
    // 80186E88: sth     r4, 72(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(72);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80186E8C:
    ctx->pc = 0x80186E8Cu;
    // 80186E8C: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80186E90:
    ctx->pc = 0x80186E90u;
    // 80186E90: lwz     r0, -26432(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26432);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186E94:
    ctx->pc = 0x80186E94u;
    // 80186E94: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80186E98:
    ctx->pc = 0x80186E98u;
    // 80186E98: cmplwi  r0, 0x0000
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

label_80186E9C:
    ctx->pc = 0x80186E9Cu;
    // 80186E9C: or   r0, r5, r3
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[3];
    }

label_80186EA0:
    ctx->pc = 0x80186EA0u;
    // 80186EA0: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186EA4:
    ctx->pc = 0x80186EA4u;
    // 80186EA4: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80186EA8:
    ctx->pc = 0x80186EA8u;
    // 80186EA8: bc    12, 2, 0x80186EC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80186EC4;
        }
    }

label_80186EAC:
    ctx->pc = 0x80186EACu;
    ctx->downcount -= 6;
    // 80186EAC: addi    r3, r29, 240
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(240);

label_80186EB0:
    ctx->pc = 0x80186EB0u;
    // 80186EB0: addi    r4, r29, 292
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(292);

label_80186EB4:
    ctx->pc = 0x80186EB4u;
    // 80186EB4: addi    r5, r29, 296
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(296);

label_80186EB8:
    ctx->pc = 0x80186EB8u;
    // 80186EB8: addi    r6, r29, 316
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(316);

label_80186EBC:
    ctx->pc = 0x80186EBCu;
    // 80186EBC: addi    r7, r29, 320
    ctx->gpr[7] = ctx->gpr[29] + (u32)(s32)(320);

label_80186EC0:
    ctx->pc = 0x80186EC0u;
    // 80186EC0: bl      0x8018619C
    {
            ctx->lr = 0x80186EC4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018619Cu;
                return;
            }
            goto label_8018619C;
    }

label_80186EC4:
    ctx->pc = 0x80186EC4u;
    ctx->downcount -= 11;
    // 80186EC4: lwz     r0, 304(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(304);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186EC8:
    ctx->pc = 0x80186EC8u;
    // 80186EC8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186ECC:
    ctx->pc = 0x80186ECCu;
    // 80186ECC: lhz     r3, 0(r19)
    {
        u32 ea = ctx->gpr[19] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80186ED0:
    ctx->pc = 0x80186ED0u;
    // 80186ED0: lhz     r4, 0(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80186ED4:
    ctx->pc = 0x80186ED4u;
    // 80186ED4: lbz     r5, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80186ED8:
    ctx->pc = 0x80186ED8u;
    // 80186ED8: lhz     r6, 2(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80186EDC:
    ctx->pc = 0x80186EDCu;
    // 80186EDC: lhz     r7, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80186EE0:
    ctx->pc = 0x80186EE0u;
    // 80186EE0: lhz     r8, 6(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(6);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_80186EE4:
    ctx->pc = 0x80186EE4u;
    // 80186EE4: lhz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80186EE8:
    ctx->pc = 0x80186EE8u;
    // 80186EE8: lhz     r10, 10(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(10);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_80186EEC:
    ctx->pc = 0x80186EECu;
    // 80186EEC: bl      0x8018653C
    {
            ctx->lr = 0x80186EF0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018653Cu;
                return;
            }
            goto label_8018653C;
    }

label_80186EF0:
    ctx->pc = 0x80186EF0u;
    ctx->downcount -= 2;
    // 80186EF0: or   r3, r14, r14
    {
        ctx->gpr[3] = ctx->gpr[14] | ctx->gpr[14];
    }

label_80186EF4:
    ctx->pc = 0x80186EF4u;
    // 80186EF4: bl      0x80173F54
    {
            ctx->lr = 0x80186EF8u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80186EF8:
    ctx->pc = 0x80186EF8u;
    ctx->downcount -= 16;
    // 80186EF8: lmw     r14, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80186EFC:
    ctx->pc = 0x80186EFCu;
    // 80186EFC: lwz     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186F00:
    ctx->pc = 0x80186F00u;
    // 80186F00: addi    r1, r1, 120
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(120);

label_80186F04:
    ctx->pc = 0x80186F04u;
    // 80186F04: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80186F08:
    ctx->pc = 0x80186F08u;
    // 80186F08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_80186F0C:
    ctx->pc = 0x80186F0Cu;
    ctx->downcount -= 21;
    // 80186F0C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80186F10:
    ctx->pc = 0x80186F10u;
    // 80186F10: lis     r7, -32697
    ctx->gpr[7] = ((u32)(s32)(-32697) << 16);

label_80186F14:
    ctx->pc = 0x80186F14u;
    // 80186F14: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80186F18:
    ctx->pc = 0x80186F18u;
    // 80186F18: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80186F1C:
    ctx->pc = 0x80186F1Cu;
    // 80186F1C: stmw     r23, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 23; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80186F20:
    ctx->pc = 0x80186F20u;
    // 80186F20: addi    r26, r3, 0
    ctx->gpr[26] = ctx->gpr[3] + (u32)(s32)(0);

label_80186F24:
    ctx->pc = 0x80186F24u;
    // 80186F24: addi    r25, r4, 0
    ctx->gpr[25] = ctx->gpr[4] + (u32)(s32)(0);

label_80186F28:
    ctx->pc = 0x80186F28u;
    // 80186F28: addi    r24, r5, 0
    ctx->gpr[24] = ctx->gpr[5] + (u32)(s32)(0);

label_80186F2C:
    ctx->pc = 0x80186F2Cu;
    // 80186F2C: addi    r23, r6, 0
    ctx->gpr[23] = ctx->gpr[6] + (u32)(s32)(0);

label_80186F30:
    ctx->pc = 0x80186F30u;
    // 80186F30: addi    r29, r7, 2360
    ctx->gpr[29] = ctx->gpr[7] + (u32)(s32)(2360);

label_80186F34:
    ctx->pc = 0x80186F34u;
    // 80186F34: bl      0x80173F2C
    {
            ctx->lr = 0x80186F38u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80186F38:
    ctx->pc = 0x80186F38u;
    ctx->downcount -= 12;
    // 80186F38: sth     r26, 262(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(262);
        mem_write16(ctx, ea, (u16)ctx->gpr[26]);
    }

label_80186F3C:
    ctx->pc = 0x80186F3Cu;
    // 80186F3C: addi    r11, r29, 262
    ctx->gpr[11] = ctx->gpr[29] + (u32)(s32)(262);

label_80186F40:
    ctx->pc = 0x80186F40u;
    // 80186F40: addi    r8, r29, 264
    ctx->gpr[8] = ctx->gpr[29] + (u32)(s32)(264);

label_80186F44:
    ctx->pc = 0x80186F44u;
    // 80186F44: sth     r25, 264(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(264);
        mem_write16(ctx, ea, (u16)ctx->gpr[25]);
    }

label_80186F48:
    ctx->pc = 0x80186F48u;
    // 80186F48: addi    r10, r29, 266
    ctx->gpr[10] = ctx->gpr[29] + (u32)(s32)(266);

label_80186F4C:
    ctx->pc = 0x80186F4Cu;
    // 80186F4C: addi    r4, r29, 268
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(268);

label_80186F50:
    ctx->pc = 0x80186F50u;
    // 80186F50: sth     r24, 266(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(266);
        mem_write16(ctx, ea, (u16)ctx->gpr[24]);
    }

label_80186F54:
    ctx->pc = 0x80186F54u;
    // 80186F54: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80186F58:
    ctx->pc = 0x80186F58u;
    // 80186F58: sth     r23, 268(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(268);
        mem_write16(ctx, ea, (u16)ctx->gpr[23]);
    }

label_80186F5C:
    ctx->pc = 0x80186F5Cu;
    // 80186F5C: lwz     r0, 276(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(276);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186F60:
    ctx->pc = 0x80186F60u;
    // 80186F60: cmplwi  r0, 0x0002
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

label_80186F64:
    ctx->pc = 0x80186F64u;
    // 80186F64: bc    4, 2, 0x80186F70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186F70;
        }
    }

label_80186F68:
    ctx->pc = 0x80186F68u;
    ctx->downcount -= 2;
    // 80186F68: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186F6C:
    ctx->pc = 0x80186F6Cu;
    // 80186F6C: b       0x80186F9C
    {
            goto label_80186F9C;
    }

label_80186F70:
    ctx->pc = 0x80186F70u;
    ctx->downcount -= 2;
    // 80186F70: cmplwi  r0, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80186F74:
    ctx->pc = 0x80186F74u;
    // 80186F74: bc    4, 2, 0x80186F80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186F80;
        }
    }

label_80186F78:
    ctx->pc = 0x80186F78u;
    ctx->downcount -= 2;
    // 80186F78: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186F7C:
    ctx->pc = 0x80186F7Cu;
    // 80186F7C: b       0x80186F9C
    {
            goto label_80186F9C;
    }

label_80186F80:
    ctx->pc = 0x80186F80u;
    ctx->downcount -= 3;
    // 80186F80: lwz     r0, 272(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186F84:
    ctx->pc = 0x80186F84u;
    // 80186F84: cmpwi   r0, 0
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

label_80186F88:
    ctx->pc = 0x80186F88u;
    // 80186F88: bc    4, 2, 0x80186F98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186F98;
        }
    }

label_80186F8C:
    ctx->pc = 0x80186F8Cu;
    ctx->downcount -= 3;
    // 80186F8C: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186F90:
    ctx->pc = 0x80186F90u;
    // 80186F90: rlwinm r0, r0, 1, 16, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x0000FFFEu;
    }

label_80186F94:
    ctx->pc = 0x80186F94u;
    // 80186F94: b       0x80186F9C
    {
            goto label_80186F9C;
    }

label_80186F98:
    ctx->pc = 0x80186F98u;
    ctx->downcount -= 1;
    // 80186F98: lhz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186F9C:
    ctx->pc = 0x80186F9Cu;
    ctx->downcount -= 12;
    // 80186F9C: addi    r27, r29, 246
    ctx->gpr[27] = ctx->gpr[29] + (u32)(s32)(246);

label_80186FA0:
    ctx->pc = 0x80186FA0u;
    // 80186FA0: sth     r0, 246(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(246);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186FA4:
    ctx->pc = 0x80186FA4u;
    // 80186FA4: addi    r9, r29, 244
    ctx->gpr[9] = ctx->gpr[29] + (u32)(s32)(244);

label_80186FA8:
    ctx->pc = 0x80186FA8u;
    // 80186FA8: lhz     r0, 244(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(244);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80186FAC:
    ctx->pc = 0x80186FACu;
    // 80186FAC: lha     r5, 240(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(240);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80186FB0:
    ctx->pc = 0x80186FB0u;
    // 80186FB0: lha     r3, -26476(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26476);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80186FB4:
    ctx->pc = 0x80186FB4u;
    // 80186FB4: subfic  r0, r0, 720
    {
        u64 res = (u64)(u32)(s32)(720) + (u64)(~ctx->gpr[0]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80186FB8:
    ctx->pc = 0x80186FB8u;
    // 80186FB8: lwz     r28, 324(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(324);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80186FBC:
    ctx->pc = 0x80186FBCu;
    // 80186FBC: add   r3, r5, r3
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80186FC0:
    ctx->pc = 0x80186FC0u;
    // 80186FC0: cmpw    r3, r0
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

label_80186FC4:
    ctx->pc = 0x80186FC4u;
    // 80186FC4: lhz     r7, 2(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(2);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80186FC8:
    ctx->pc = 0x80186FC8u;
    // 80186FC8: bc    4, 1, 0x80186FD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186FD0;
        }
    }

label_80186FCC:
    ctx->pc = 0x80186FCCu;
    ctx->downcount -= 1;
    // 80186FCC: b       0x80186FE0
    {
            goto label_80186FE0;
    }

label_80186FD0:
    ctx->pc = 0x80186FD0u;
    ctx->downcount -= 2;
    // 80186FD0: cmpwi   r3, 0
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

label_80186FD4:
    ctx->pc = 0x80186FD4u;
    // 80186FD4: bc    4, 0, 0x80186FDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186FDC;
        }
    }

label_80186FD8:
    ctx->pc = 0x80186FD8u;
    ctx->downcount -= 1;
    // 80186FD8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80186FDC:
    ctx->pc = 0x80186FDCu;
    ctx->downcount -= 1;
    // 80186FDC: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80186FE0:
    ctx->pc = 0x80186FE0u;
    ctx->downcount -= 5;
    // 80186FE0: sth     r0, 248(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(248);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80186FE4:
    ctx->pc = 0x80186FE4u;
    // 80186FE4: addi    r12, r29, 272
    ctx->gpr[12] = ctx->gpr[29] + (u32)(s32)(272);

label_80186FE8:
    ctx->pc = 0x80186FE8u;
    // 80186FE8: lwz     r0, 272(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(272);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80186FEC:
    ctx->pc = 0x80186FECu;
    // 80186FEC: cmpwi   r0, 0
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

label_80186FF0:
    ctx->pc = 0x80186FF0u;
    // 80186FF0: bc    4, 2, 0x80186FFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80186FFC;
        }
    }

label_80186FF4:
    ctx->pc = 0x80186FF4u;
    ctx->downcount -= 2;
    // 80186FF4: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80186FF8:
    ctx->pc = 0x80186FF8u;
    // 80186FF8: b       0x80187000
    {
            goto label_80187000;
    }

label_80186FFC:
    ctx->pc = 0x80186FFCu;
    ctx->downcount -= 1;
    // 80186FFC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80187000:
    ctx->pc = 0x80187000u;
    ctx->downcount -= 8;
    // 80187000: lhz     r3, 242(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(242);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80187004:
    ctx->pc = 0x80187004u;
    // 80187004: addi    r6, r29, 242
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(242);

label_80187008:
    ctx->pc = 0x80187008u;
    // 80187008: lha     r5, -26474(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26474);
        ctx->gpr[5] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8018700C:
    ctx->pc = 0x8018700Cu;
    // 8018700C: extsh r25, r3
    {
        ctx->gpr[25] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_80187010:
    ctx->pc = 0x80187010u;
    // 80187010: rlwinm r3, r3, 0, 31, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
    }

label_80187014:
    ctx->pc = 0x80187014u;
    // 80187014: add   r26, r25, r5
    {
        u32 a = ctx->gpr[25];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[26] = res;
    }

label_80187018:
    ctx->pc = 0x80187018u;
    // 80187018: cmpw    r26, r3
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8018701C:
    ctx->pc = 0x8018701Cu;
    // 8018701C: bc    4, 1, 0x80187024
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187024;
        }
    }

label_80187020:
    ctx->pc = 0x80187020u;
    ctx->downcount -= 1;
    // 80187020: b       0x80187028
    {
            goto label_80187028;
    }

label_80187024:
    ctx->pc = 0x80187024u;
    ctx->downcount -= 1;
    // 80187024: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80187028:
    ctx->pc = 0x80187028u;
    ctx->downcount -= 12;
    // 80187028: sth     r26, 250(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(250);
        mem_write16(ctx, ea, (u16)ctx->gpr[26]);
    }

label_8018702C:
    ctx->pc = 0x8018702Cu;
    // 8018702C: extsh r7, r7
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[7];
    }

label_80187030:
    ctx->pc = 0x80187030u;
    // 80187030: rlwinm r7, r7, 1, 0, 30
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 1u) & 0xFFFFFFFEu;
    }

label_80187034:
    ctx->pc = 0x80187034u;
    // 80187034: lhz     r23, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[23] = mem_read16(ctx, ea);
    }

label_80187038:
    ctx->pc = 0x80187038u;
    // 80187038: subf   r7, r3, r7
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_8018703C:
    ctx->pc = 0x8018703Cu;
    // 8018703C: lha     r24, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[24] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80187040:
    ctx->pc = 0x80187040u;
    // 80187040: addi    r31, r29, 250
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(250);

label_80187044:
    ctx->pc = 0x80187044u;
    // 80187044: extsh r26, r23
    {
        ctx->gpr[26] = (u32)(s32)(s16)ctx->gpr[23];
    }

label_80187048:
    ctx->pc = 0x80187048u;
    // 80187048: add   r25, r26, r5
    {
        u32 a = ctx->gpr[26];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[25] = res;
    }

label_8018704C:
    ctx->pc = 0x8018704Cu;
    // 8018704C: add   r25, r24, r25
    {
        u32 a = ctx->gpr[24];
        u32 b = ctx->gpr[25];
        u32 res = a + b;
        ctx->gpr[25] = res;
    }

label_80187050:
    ctx->pc = 0x80187050u;
    // 80187050: subf.   r26, r7, r25
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[25];
        u32 res = a + b + 1u;
        ctx->gpr[26] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[26];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80187054:
    ctx->pc = 0x80187054u;
    // 80187054: bc    4, 1, 0x80187060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187060;
        }
    }

label_80187058:
    ctx->pc = 0x80187058u;
    ctx->downcount -= 2;
    // 80187058: subf   r25, r7, r25
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[25];
        u32 res = a + b + 1u;
        ctx->gpr[25] = res;
    }

label_8018705C:
    ctx->pc = 0x8018705Cu;
    // 8018705C: b       0x80187064
    {
            goto label_80187064;
    }

label_80187060:
    ctx->pc = 0x80187060u;
    ctx->downcount -= 1;
    // 80187060: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_80187064:
    ctx->pc = 0x80187064u;
    ctx->downcount -= 3;
    // 80187064: add   r24, r24, r5
    {
        u32 a = ctx->gpr[24];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[24] = res;
    }

label_80187068:
    ctx->pc = 0x80187068u;
    // 80187068: subf.   r26, r3, r24
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[24];
        u32 res = a + b + 1u;
        ctx->gpr[26] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[26];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8018706C:
    ctx->pc = 0x8018706Cu;
    // 8018706C: bc    4, 0, 0x80187078
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187078;
        }
    }

label_80187070:
    ctx->pc = 0x80187070u;
    ctx->downcount -= 2;
    // 80187070: subf   r26, r3, r24
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[24];
        u32 res = a + b + 1u;
        ctx->gpr[26] = res;
    }

label_80187074:
    ctx->pc = 0x80187074u;
    // 80187074: b       0x8018707C
    {
            goto label_8018707C;
    }

label_80187078:
    ctx->pc = 0x80187078u;
    ctx->downcount -= 1;
    // 80187078: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_8018707C:
    ctx->pc = 0x8018707Cu;
    ctx->downcount -= 7;
    // 8018707C: add   r26, r23, r26
    {
        u32 a = ctx->gpr[23];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[26] = res;
    }

label_80187080:
    ctx->pc = 0x80187080u;
    // 80187080: subf   r26, r25, r26
    {
        u32 a = ~ctx->gpr[25];
        u32 b = ctx->gpr[26];
        u32 res = a + b + 1u;
        ctx->gpr[26] = res;
    }

label_80187084:
    ctx->pc = 0x80187084u;
    // 80187084: sth     r26, 252(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(252);
        mem_write16(ctx, ea, (u16)ctx->gpr[26]);
    }

label_80187088:
    ctx->pc = 0x80187088u;
    // 80187088: lha     r26, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[26] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8018708C:
    ctx->pc = 0x8018708Cu;
    // 8018708C: add   r23, r26, r5
    {
        u32 a = ctx->gpr[26];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[23] = res;
    }

label_80187090:
    ctx->pc = 0x80187090u;
    // 80187090: subf.   r26, r3, r23
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[23];
        u32 res = a + b + 1u;
        ctx->gpr[26] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[26];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80187094:
    ctx->pc = 0x80187094u;
    // 80187094: bc    4, 0, 0x801870A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801870A0;
        }
    }

label_80187098:
    ctx->pc = 0x80187098u;
    ctx->downcount -= 2;
    // 80187098: subf   r25, r3, r23
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[23];
        u32 res = a + b + 1u;
        ctx->gpr[25] = res;
    }

label_8018709C:
    ctx->pc = 0x8018709Cu;
    // 8018709C: b       0x801870A4
    {
            goto label_801870A4;
    }

label_801870A0:
    ctx->pc = 0x801870A0u;
    ctx->downcount -= 1;
    // 801870A0: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_801870A4:
    ctx->pc = 0x801870A4u;
    ctx->downcount -= 49;
    // 801870A4: divw   r26, r25, r0
    {
        s32 dividend = (s32)ctx->gpr[25];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[26] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_801870A8:
    ctx->pc = 0x801870A8u;
    // 801870A8: lhz     r8, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_801870AC:
    ctx->pc = 0x801870ACu;
    // 801870AC: subf   r8, r26, r8
    {
        u32 a = ~ctx->gpr[26];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[8] = res;
    }

label_801870B0:
    ctx->pc = 0x801870B0u;
    // 801870B0: sth     r8, 254(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(254);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_801870B4:
    ctx->pc = 0x801870B4u;
    // 801870B4: lha     r8, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[8] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801870B8:
    ctx->pc = 0x801870B8u;
    // 801870B8: lha     r23, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[23] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801870BC:
    ctx->pc = 0x801870BCu;
    // 801870BC: add   r8, r8, r5
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_801870C0:
    ctx->pc = 0x801870C0u;
    // 801870C0: add   r8, r23, r8
    {
        u32 a = ctx->gpr[23];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_801870C4:
    ctx->pc = 0x801870C4u;
    // 801870C4: subf.   r6, r7, r8
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801870C8:
    ctx->pc = 0x801870C8u;
    // 801870C8: bc    4, 1, 0x801870D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801870D4;
        }
    }

label_801870CC:
    ctx->pc = 0x801870CCu;
    ctx->downcount -= 2;
    // 801870CC: subf   r6, r7, r8
    {
        u32 a = ~ctx->gpr[7];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_801870D0:
    ctx->pc = 0x801870D0u;
    // 801870D0: b       0x801870D8
    {
            goto label_801870D8;
    }

label_801870D4:
    ctx->pc = 0x801870D4u;
    ctx->downcount -= 1;
    // 801870D4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801870D8:
    ctx->pc = 0x801870D8u;
    ctx->downcount -= 3;
    // 801870D8: add   r7, r23, r5
    {
        u32 a = ctx->gpr[23];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_801870DC:
    ctx->pc = 0x801870DCu;
    // 801870DC: subf.   r5, r3, r7
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801870E0:
    ctx->pc = 0x801870E0u;
    // 801870E0: bc    4, 0, 0x801870EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801870EC;
        }
    }

label_801870E4:
    ctx->pc = 0x801870E4u;
    ctx->downcount -= 2;
    // 801870E4: subf   r3, r3, r7
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_801870E8:
    ctx->pc = 0x801870E8u;
    // 801870E8: b       0x801870F0
    {
            goto label_801870F0;
    }

label_801870EC:
    ctx->pc = 0x801870ECu;
    ctx->downcount -= 1;
    // 801870EC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801870F0:
    ctx->pc = 0x801870F0u;
    ctx->downcount -= 89;
    // 801870F0: divw   r3, r3, r0
    {
        s32 dividend = (s32)ctx->gpr[3];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[3] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_801870F4:
    ctx->pc = 0x801870F4u;
    // 801870F4: lhz     r4, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_801870F8:
    ctx->pc = 0x801870F8u;
    // 801870F8: divw   r5, r6, r0
    {
        s32 dividend = (s32)ctx->gpr[6];
        s32 divisor = (s32)ctx->gpr[0];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[5] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_801870FC:
    ctx->pc = 0x801870FCu;
    // 801870FC: add   r0, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80187100:
    ctx->pc = 0x80187100u;
    // 80187100: subf   r0, r5, r0
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80187104:
    ctx->pc = 0x80187104u;
    // 80187104: sth     r0, 256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(256);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187108:
    ctx->pc = 0x80187108u;
    // 80187108: lwz     r0, 308(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(308);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018710C:
    ctx->pc = 0x8018710Cu;
    // 8018710C: lhz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80187110:
    ctx->pc = 0x80187110u;
    // 80187110: cmpwi   r0, 0
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

label_80187114:
    ctx->pc = 0x80187114u;
    // 80187114: lhz     r3, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80187118:
    ctx->pc = 0x80187118u;
    // 80187118: bc    12, 2, 0x80187124
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187124;
        }
    }

label_8018711C:
    ctx->pc = 0x8018711Cu;
    ctx->downcount -= 2;
    // 8018711C: rlwinm r0, r3, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0xFFFFFFFEu;
    }

label_80187120:
    ctx->pc = 0x80187120u;
    // 80187120: b       0x80187128
    {
            goto label_80187128;
    }

label_80187124:
    ctx->pc = 0x80187124u;
    ctx->downcount -= 1;
    // 80187124: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80187128:
    ctx->pc = 0x80187128u;
    ctx->downcount -= 3;
    // 80187128: rlwinm r6, r0, 0, 16, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000FFFFu;
    }

label_8018712C:
    ctx->pc = 0x8018712Cu;
    // 8018712C: cmplw   r6, r5
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80187130:
    ctx->pc = 0x80187130u;
    // 80187130: bc    4, 0, 0x80187180
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80187180;
        }
    }

label_80187134:
    ctx->pc = 0x80187134u;
    ctx->downcount -= 58;
    // 80187134: rlwinm r4, r6, 8, 0, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 8u) & 0xFFFFFF00u;
    }

label_80187138:
    ctx->pc = 0x80187138u;
    // 80187138: addi    r0, r4, -1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-1);

label_8018713C:
    ctx->pc = 0x8018713Cu;
    // 8018713C: add   r0, r5, r0
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80187140:
    ctx->pc = 0x80187140u;
    // 80187140: divwu   r0, r0, r5
    {
        u32 divisor = ctx->gpr[5];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[0] / divisor;
    }

label_80187144:
    ctx->pc = 0x80187144u;
    // 80187144: ori     r0, r0, 0x1000
    ctx->gpr[0] = ctx->gpr[0] | 0x1000u;

label_80187148:
    ctx->pc = 0x80187148u;
    // 80187148: sth     r0, 74(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8018714C:
    ctx->pc = 0x8018714Cu;
    // 8018714C: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_80187150:
    ctx->pc = 0x80187150u;
    // 80187150: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80187154:
    ctx->pc = 0x80187154u;
    // 80187154: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80187158:
    ctx->pc = 0x80187158u;
    // 80187158: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_8018715C:
    ctx->pc = 0x8018715Cu;
    // 8018715C: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187160:
    ctx->pc = 0x80187160u;
    // 80187160: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80187164:
    ctx->pc = 0x80187164u;
    // 80187164: sth     r6, 112(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(112);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80187168:
    ctx->pc = 0x80187168u;
    // 80187168: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8018716C:
    ctx->pc = 0x8018716Cu;
    // 8018716C: lwz     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187170:
    ctx->pc = 0x80187170u;
    // 80187170: ori     r0, r0, 0x0080
    ctx->gpr[0] = ctx->gpr[0] | 0x0080u;

label_80187174:
    ctx->pc = 0x80187174u;
    // 80187174: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187178:
    ctx->pc = 0x80187178u;
    // 80187178: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8018717C:
    ctx->pc = 0x8018717Cu;
    // 8018717C: b       0x801871A0
    {
            goto label_801871A0;
    }

label_80187180:
    ctx->pc = 0x80187180u;
    ctx->downcount -= 8;
    // 80187180: li      r0, 256
    ctx->gpr[0] = (u32)(s32)(256);

label_80187184:
    ctx->pc = 0x80187184u;
    // 80187184: sth     r0, 74(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(74);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80187188:
    ctx->pc = 0x80187188u;
    // 80187188: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_8018718C:
    ctx->pc = 0x8018718Cu;
    // 8018718C: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80187190:
    ctx->pc = 0x80187190u;
    // 80187190: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80187194:
    ctx->pc = 0x80187194u;
    // 80187194: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80187198:
    ctx->pc = 0x80187198u;
    // 80187198: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8018719C:
    ctx->pc = 0x8018719Cu;
    // 8018719C: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801871A0:
    ctx->pc = 0x801871A0u;
    ctx->downcount -= 10;
    // 801871A0: lhz     r4, 258(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(258);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_801871A4:
    ctx->pc = 0x801871A4u;
    // 801871A4: addi    r6, r29, 284
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(284);

label_801871A8:
    ctx->pc = 0x801871A8u;
    // 801871A8: lwz     r5, 0(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801871AC:
    ctx->pc = 0x801871ACu;
    // 801871AC: addi    r0, r4, 15
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(15);

label_801871B0:
    ctx->pc = 0x801871B0u;
    // 801871B0: lhz     r4, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_801871B4:
    ctx->pc = 0x801871B4u;
    // 801871B4: srawi r0, r0, 4
    {
        u32 sh = 4u;
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

label_801871B8:
    ctx->pc = 0x801871B8u;
    // 801871B8: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801871BC:
    ctx->pc = 0x801871BCu;
    // 801871BC: cmpwi   r5, 0
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

label_801871C0:
    ctx->pc = 0x801871C0u;
    // 801871C0: stb     r0, 284(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(284);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801871C4:
    ctx->pc = 0x801871C4u;
    // 801871C4: bc    4, 2, 0x801871D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801871D0;
        }
    }

label_801871C8:
    ctx->pc = 0x801871C8u;
    ctx->downcount -= 2;
    // 801871C8: lbz     r5, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_801871CC:
    ctx->pc = 0x801871CCu;
    // 801871CC: b       0x801871D8
    {
            goto label_801871D8;
    }

label_801871D0:
    ctx->pc = 0x801871D0u;
    ctx->downcount -= 2;
    // 801871D0: lbz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_801871D4:
    ctx->pc = 0x801871D4u;
    // 801871D4: rlwinm r5, r0, 1, 24, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x000000FEu;
    }

label_801871D8:
    ctx->pc = 0x801871D8u;
    ctx->downcount -= 26;
    // 801871D8: srawi r0, r4, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[4];
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

label_801871DC:
    ctx->pc = 0x801871DCu;
    // 801871DC: stb     r5, 285(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(285);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_801871E0:
    ctx->pc = 0x801871E0u;
    // 801871E0: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801871E4:
    ctx->pc = 0x801871E4u;
    // 801871E4: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_801871E8:
    ctx->pc = 0x801871E8u;
    // 801871E8: subfc   r0, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801871EC:
    ctx->pc = 0x801871ECu;
    // 801871EC: stb     r0, 300(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(300);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801871F0:
    ctx->pc = 0x801871F0u;
    // 801871F0: addi    r4, r29, 300
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(300);

label_801871F4:
    ctx->pc = 0x801871F4u;
    // 801871F4: addi    r0, r3, 15
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(15);

label_801871F8:
    ctx->pc = 0x801871F8u;
    // 801871F8: lbz     r4, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801871FC:
    ctx->pc = 0x801871FCu;
    // 801871FC: lis     r3, 2048
    ctx->gpr[3] = ((u32)(s32)(2048) << 16);

label_80187200:
    ctx->pc = 0x80187200u;
    // 80187200: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80187204:
    ctx->pc = 0x80187204u;
    // 80187204: srawi r0, r0, 4
    {
        u32 sh = 4u;
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

label_80187208:
    ctx->pc = 0x80187208u;
    // 80187208: addze  r0, r0
    {
        u32 a = ctx->gpr[0];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8018720C:
    ctx->pc = 0x8018720Cu;
    // 8018720C: stb     r0, 286(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(286);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80187210:
    ctx->pc = 0x80187210u;
    // 80187210: lbz     r0, 286(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(286);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80187214:
    ctx->pc = 0x80187214u;
    // 80187214: lbz     r4, 285(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(285);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_80187218:
    ctx->pc = 0x80187218u;
    // 80187218: rlwimi r4, r0, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[0], 8u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_8018721C:
    ctx->pc = 0x8018721Cu;
    // 8018721C: sth     r4, 72(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(72);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80187220:
    ctx->pc = 0x80187220u;
    // 80187220: lwz     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80187224:
    ctx->pc = 0x80187224u;
    // 80187224: lwz     r0, -26432(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26432);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187228:
    ctx->pc = 0x80187228u;
    // 80187228: lwz     r5, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8018722C:
    ctx->pc = 0x8018722Cu;
    // 8018722C: cmplwi  r0, 0x0000
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

label_80187230:
    ctx->pc = 0x80187230u;
    // 80187230: or   r0, r5, r3
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[3];
    }

label_80187234:
    ctx->pc = 0x80187234u;
    // 80187234: stw     r0, -26460(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187238:
    ctx->pc = 0x80187238u;
    // 80187238: stw     r4, -26464(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26464);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8018723C:
    ctx->pc = 0x8018723Cu;
    // 8018723C: bc    12, 2, 0x80187258
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80187258;
        }
    }

label_80187240:
    ctx->pc = 0x80187240u;
    ctx->downcount -= 6;
    // 80187240: addi    r3, r29, 240
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(240);

label_80187244:
    ctx->pc = 0x80187244u;
    // 80187244: addi    r4, r29, 292
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(292);

label_80187248:
    ctx->pc = 0x80187248u;
    // 80187248: addi    r5, r29, 296
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(296);

label_8018724C:
    ctx->pc = 0x8018724Cu;
    // 8018724C: addi    r6, r29, 316
    ctx->gpr[6] = ctx->gpr[29] + (u32)(s32)(316);

label_80187250:
    ctx->pc = 0x80187250u;
    // 80187250: addi    r7, r29, 320
    ctx->gpr[7] = ctx->gpr[29] + (u32)(s32)(320);

label_80187254:
    ctx->pc = 0x80187254u;
    // 80187254: bl      0x8018619C
    {
            ctx->lr = 0x80187258u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018619Cu;
                return;
            }
            goto label_8018619C;
    }

label_80187258:
    ctx->pc = 0x80187258u;
    ctx->downcount -= 11;
    // 80187258: lwz     r0, 304(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(304);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8018725C:
    ctx->pc = 0x8018725Cu;
    // 8018725C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80187260:
    ctx->pc = 0x80187260u;
    // 80187260: lhz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80187264:
    ctx->pc = 0x80187264u;
    // 80187264: lhz     r4, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80187268:
    ctx->pc = 0x80187268u;
    // 80187268: lbz     r5, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8018726C:
    ctx->pc = 0x8018726Cu;
    // 8018726C: lhz     r6, 2(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(2);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80187270:
    ctx->pc = 0x80187270u;
    // 80187270: lhz     r7, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_80187274:
    ctx->pc = 0x80187274u;
    // 80187274: lhz     r8, 6(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(6);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_80187278:
    ctx->pc = 0x80187278u;
    // 80187278: lhz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_8018727C:
    ctx->pc = 0x8018727Cu;
    // 8018727C: lhz     r10, 10(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(10);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_80187280:
    ctx->pc = 0x80187280u;
    // 80187280: bl      0x8018653C
    {
            ctx->lr = 0x80187284u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8018653Cu;
                return;
            }
            goto label_8018653C;
    }

label_80187284:
    ctx->pc = 0x80187284u;
    ctx->downcount -= 2;
    // 80187284: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80187288:
    ctx->pc = 0x80187288u;
    // 80187288: bl      0x80173F54
    {
            ctx->lr = 0x8018728Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8018728C:
    ctx->pc = 0x8018728Cu;
    ctx->downcount -= 16;
    // 8018728C: lmw     r23, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 23; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80187290:
    ctx->pc = 0x80187290u;
    // 80187290: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80187294:
    ctx->pc = 0x80187294u;
    // 80187294: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_80187298:
    ctx->pc = 0x80187298u;
    // 80187298: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8018729C:
    ctx->pc = 0x8018729Cu;
    // 8018729C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801832C0;
        }
    }

label_801872A0:
    ctx->pc = 0x801872A0u;
    ctx->downcount -= 15;
    // 801872A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801872A4:
    ctx->pc = 0x801872A4u;
    // 801872A4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801872A8:
    ctx->pc = 0x801872A8u;
    // 801872A8: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801872AC:
    ctx->pc = 0x801872ACu;
    // 801872AC: stmw     r27, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801872B0:
    ctx->pc = 0x801872B0u;
    // 801872B0: bl      0x80173F2C
    {
            ctx->lr = 0x801872B4u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801872B4:
    ctx->pc = 0x801872B4u;
    ctx->downcount -= 3;
    // 801872B4: lwz     r7, -26456(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26456);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801872B8:
    ctx->pc = 0x801872B8u;
    // 801872B8: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_801872BC:
    ctx->pc = 0x801872BCu;
    // 801872BC: lis     r5, -32697
    ctx->gpr[5] = ((u32)(s32)(-32697) << 16);

    ctx->pc = 0x801872C0u;
    return;
return_dispatch_801832C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x801832D8u: goto label_801832D8;
    case 0x801832E0u: goto label_801832E0;
    case 0x801832E8u: goto label_801832E8;
    case 0x801832F8u: goto label_801832F8;
    case 0x80183314u: goto label_80183314;
    case 0x80183320u: goto label_80183320;
    case 0x80183360u: goto label_80183360;
    case 0x8018338Cu: goto label_8018338C;
    case 0x80183444u: goto label_80183444;
    case 0x8018347Cu: goto label_8018347C;
    case 0x80183484u: goto label_80183484;
    case 0x801834B0u: goto label_801834B0;
    case 0x801834B8u: goto label_801834B8;
    case 0x801834D4u: goto label_801834D4;
    case 0x801834E0u: goto label_801834E0;
    case 0x801834E4u: goto label_801834E4;
    case 0x80183500u: goto label_80183500;
    case 0x80183520u: goto label_80183520;
    case 0x80183524u: goto label_80183524;
    case 0x80183544u: goto label_80183544;
    case 0x8018354Cu: goto label_8018354C;
    case 0x80183554u: goto label_80183554;
    case 0x8018355Cu: goto label_8018355C;
    case 0x801835D0u: goto label_801835D0;
    case 0x801835FCu: goto label_801835FC;
    case 0x80183630u: goto label_80183630;
    case 0x80183658u: goto label_80183658;
    case 0x80183690u: goto label_80183690;
    case 0x801836B4u: goto label_801836B4;
    case 0x801836B8u: goto label_801836B8;
    case 0x801836E0u: goto label_801836E0;
    case 0x80183704u: goto label_80183704;
    case 0x8018372Cu: goto label_8018372C;
    case 0x8018374Cu: goto label_8018374C;
    case 0x80183760u: goto label_80183760;
    case 0x8018378Cu: goto label_8018378C;
    case 0x801837A8u: goto label_801837A8;
    case 0x801837BCu: goto label_801837BC;
    case 0x801838D0u: goto label_801838D0;
    case 0x801838ECu: goto label_801838EC;
    case 0x80183904u: goto label_80183904;
    case 0x80183914u: goto label_80183914;
    case 0x8018393Cu: goto label_8018393C;
    case 0x80183960u: goto label_80183960;
    case 0x80183970u: goto label_80183970;
    case 0x80183C68u: goto label_80183C68;
    case 0x80183C84u: goto label_80183C84;
    case 0x80183C90u: goto label_80183C90;
    case 0x80183D00u: goto label_80183D00;
    case 0x80183D34u: goto label_80183D34;
    case 0x80183D54u: goto label_80183D54;
    case 0x80183D68u: goto label_80183D68;
    case 0x80183DA0u: goto label_80183DA0;
    case 0x80183DC4u: goto label_80183DC4;
    case 0x80183DDCu: goto label_80183DDC;
    case 0x80183DE0u: goto label_80183DE0;
    case 0x80183E18u: goto label_80183E18;
    case 0x80183E24u: goto label_80183E24;
    case 0x80183E50u: goto label_80183E50;
    case 0x80183E6Cu: goto label_80183E6C;
    case 0x80183E7Cu: goto label_80183E7C;
    case 0x80183E8Cu: goto label_80183E8C;
    case 0x80183EB0u: goto label_80183EB0;
    case 0x80183EBCu: goto label_80183EBC;
    case 0x80183EC8u: goto label_80183EC8;
    case 0x80183F10u: goto label_80183F10;
    case 0x80183F14u: goto label_80183F14;
    case 0x80183F70u: goto label_80183F70;
    case 0x80183F9Cu: goto label_80183F9C;
    case 0x80183FECu: goto label_80183FEC;
    case 0x80183FFCu: goto label_80183FFC;
    case 0x801840A8u: goto label_801840A8;
    case 0x80184128u: goto label_80184128;
    case 0x801841E8u: goto label_801841E8;
    case 0x80184214u: goto label_80184214;
    case 0x80184244u: goto label_80184244;
    case 0x8018424Cu: goto label_8018424C;
    case 0x80184274u: goto label_80184274;
    case 0x80184284u: goto label_80184284;
    case 0x8018428Cu: goto label_8018428C;
    case 0x801842F8u: goto label_801842F8;
    case 0x80184320u: goto label_80184320;
    case 0x8018434Cu: goto label_8018434C;
    case 0x80184354u: goto label_80184354;
    case 0x8018435Cu: goto label_8018435C;
    case 0x8018437Cu: goto label_8018437C;
    case 0x80184384u: goto label_80184384;
    case 0x8018438Cu: goto label_8018438C;
    case 0x801843D0u: goto label_801843D0;
    case 0x801843E8u: goto label_801843E8;
    case 0x8018444Cu: goto label_8018444C;
    case 0x801844A8u: goto label_801844A8;
    case 0x801844C0u: goto label_801844C0;
    case 0x801844DCu: goto label_801844DC;
    case 0x801844F4u: goto label_801844F4;
    case 0x80184524u: goto label_80184524;
    case 0x80184580u: goto label_80184580;
    case 0x80184610u: goto label_80184610;
    case 0x80184690u: goto label_80184690;
    case 0x801846F8u: goto label_801846F8;
    case 0x80184710u: goto label_80184710;
    case 0x801847A0u: goto label_801847A0;
    case 0x801847D0u: goto label_801847D0;
    case 0x801847FCu: goto label_801847FC;
    case 0x8018487Cu: goto label_8018487C;
    case 0x801848B4u: goto label_801848B4;
    case 0x80184924u: goto label_80184924;
    case 0x8018497Cu: goto label_8018497C;
    case 0x80184994u: goto label_80184994;
    case 0x801849ACu: goto label_801849AC;
    case 0x80184A24u: goto label_80184A24;
    case 0x80184A3Cu: goto label_80184A3C;
    case 0x80184AF4u: goto label_80184AF4;
    case 0x80184B0Cu: goto label_80184B0C;
    case 0x80184B80u: goto label_80184B80;
    case 0x80184B98u: goto label_80184B98;
    case 0x80184C0Cu: goto label_80184C0C;
    case 0x80184C24u: goto label_80184C24;
    case 0x80184CA8u: goto label_80184CA8;
    case 0x80184CC0u: goto label_80184CC0;
    case 0x80184D40u: goto label_80184D40;
    case 0x80184D58u: goto label_80184D58;
    case 0x80184DCCu: goto label_80184DCC;
    case 0x80184DE4u: goto label_80184DE4;
    case 0x80184E68u: goto label_80184E68;
    case 0x80184E80u: goto label_80184E80;
    case 0x80184ED0u: goto label_80184ED0;
    case 0x80184F04u: goto label_80184F04;
    case 0x80184F3Cu: goto label_80184F3C;
    case 0x80184F74u: goto label_80184F74;
    case 0x80184F80u: goto label_80184F80;
    case 0x8018501Cu: goto label_8018501C;
    case 0x8018505Cu: goto label_8018505C;
    case 0x80185074u: goto label_80185074;
    case 0x801850CCu: goto label_801850CC;
    case 0x80185170u: goto label_80185170;
    case 0x8018517Cu: goto label_8018517C;
    case 0x801851C0u: goto label_801851C0;
    case 0x8018522Cu: goto label_8018522C;
    case 0x80185254u: goto label_80185254;
    case 0x80185294u: goto label_80185294;
    case 0x801853BCu: goto label_801853BC;
    case 0x801853D4u: goto label_801853D4;
    case 0x801853DCu: goto label_801853DC;
    case 0x801853F4u: goto label_801853F4;
    case 0x80185410u: goto label_80185410;
    case 0x80185438u: goto label_80185438;
    case 0x80185478u: goto label_80185478;
    case 0x801854E8u: goto label_801854E8;
    case 0x801854FCu: goto label_801854FC;
    case 0x8018550Cu: goto label_8018550C;
    case 0x80185514u: goto label_80185514;
    case 0x8018551Cu: goto label_8018551C;
    case 0x80185524u: goto label_80185524;
    case 0x80185558u: goto label_80185558;
    case 0x80185560u: goto label_80185560;
    case 0x8018559Cu: goto label_8018559C;
    case 0x801855A4u: goto label_801855A4;
    case 0x80185684u: goto label_80185684;
    case 0x801859B8u: goto label_801859B8;
    case 0x801859D4u: goto label_801859D4;
    case 0x80185A34u: goto label_80185A34;
    case 0x80185B90u: goto label_80185B90;
    case 0x80185BA8u: goto label_80185BA8;
    case 0x80185BE8u: goto label_80185BE8;
    case 0x80185DF8u: goto label_80185DF8;
    case 0x80185E34u: goto label_80185E34;
    case 0x80185E3Cu: goto label_80185E3C;
    case 0x80185E74u: goto label_80185E74;
    case 0x80185E84u: goto label_80185E84;
    case 0x80185E98u: goto label_80185E98;
    case 0x80186714u: goto label_80186714;
    case 0x80186720u: goto label_80186720;
    case 0x8018672Cu: goto label_8018672C;
    case 0x80186738u: goto label_80186738;
    case 0x80186744u: goto label_80186744;
    case 0x80186750u: goto label_80186750;
    case 0x8018675Cu: goto label_8018675C;
    case 0x80186798u: goto label_80186798;
    case 0x801867F8u: goto label_801867F8;
    case 0x80186804u: goto label_80186804;
    case 0x80186810u: goto label_80186810;
    case 0x8018681Cu: goto label_8018681C;
    case 0x80186828u: goto label_80186828;
    case 0x80186834u: goto label_80186834;
    case 0x80186840u: goto label_80186840;
    case 0x80186960u: goto label_80186960;
    case 0x80186EC4u: goto label_80186EC4;
    case 0x80186EF0u: goto label_80186EF0;
    case 0x80186EF8u: goto label_80186EF8;
    case 0x80186F38u: goto label_80186F38;
    case 0x80187258u: goto label_80187258;
    case 0x80187284u: goto label_80187284;
    case 0x8018728Cu: goto label_8018728C;
    case 0x801872B4u: goto label_801872B4;
    default: return;
    }
}

