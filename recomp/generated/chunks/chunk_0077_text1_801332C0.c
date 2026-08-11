// DolRecomp output
#include "../generated.h"

static void loop_80133870(CPUState* ctx) {
label_80133870:
    ctx->downcount -= 3;
    ctx->pc = 0x80133870u;
    // 80133870: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80133874: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

    // 80133878: bc    16, 0, 0x80133870
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133870u;
                return;
            }
            goto label_80133870;
        }
    }

    ctx->pc = 0x8013387Cu;
}

void func_801332C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x801332C0u: goto label_801332C0;
    case 0x801332C4u: goto label_801332C4;
    case 0x801332C8u: goto label_801332C8;
    case 0x801332CCu: goto label_801332CC;
    case 0x801332D0u: goto label_801332D0;
    case 0x801332D4u: goto label_801332D4;
    case 0x801332D8u: goto label_801332D8;
    case 0x801332DCu: goto label_801332DC;
    case 0x801332E0u: goto label_801332E0;
    case 0x801332E4u: goto label_801332E4;
    case 0x801332E8u: goto label_801332E8;
    case 0x801332ECu: goto label_801332EC;
    case 0x801332F0u: goto label_801332F0;
    case 0x801332F4u: goto label_801332F4;
    case 0x801332F8u: goto label_801332F8;
    case 0x801332FCu: goto label_801332FC;
    case 0x80133300u: goto label_80133300;
    case 0x80133304u: goto label_80133304;
    case 0x80133308u: goto label_80133308;
    case 0x8013330Cu: goto label_8013330C;
    case 0x80133310u: goto label_80133310;
    case 0x80133314u: goto label_80133314;
    case 0x80133318u: goto label_80133318;
    case 0x8013331Cu: goto label_8013331C;
    case 0x80133320u: goto label_80133320;
    case 0x80133324u: goto label_80133324;
    case 0x80133328u: goto label_80133328;
    case 0x8013332Cu: goto label_8013332C;
    case 0x80133330u: goto label_80133330;
    case 0x80133334u: goto label_80133334;
    case 0x80133338u: goto label_80133338;
    case 0x8013333Cu: goto label_8013333C;
    case 0x80133340u: goto label_80133340;
    case 0x80133344u: goto label_80133344;
    case 0x80133348u: goto label_80133348;
    case 0x8013334Cu: goto label_8013334C;
    case 0x80133350u: goto label_80133350;
    case 0x80133354u: goto label_80133354;
    case 0x80133358u: goto label_80133358;
    case 0x8013335Cu: goto label_8013335C;
    case 0x80133360u: goto label_80133360;
    case 0x80133364u: goto label_80133364;
    case 0x80133368u: goto label_80133368;
    case 0x8013336Cu: goto label_8013336C;
    case 0x80133370u: goto label_80133370;
    case 0x80133374u: goto label_80133374;
    case 0x80133378u: goto label_80133378;
    case 0x8013337Cu: goto label_8013337C;
    case 0x80133380u: goto label_80133380;
    case 0x80133384u: goto label_80133384;
    case 0x80133388u: goto label_80133388;
    case 0x8013338Cu: goto label_8013338C;
    case 0x80133390u: goto label_80133390;
    case 0x80133394u: goto label_80133394;
    case 0x80133398u: goto label_80133398;
    case 0x8013339Cu: goto label_8013339C;
    case 0x801333A0u: goto label_801333A0;
    case 0x801333A4u: goto label_801333A4;
    case 0x801333A8u: goto label_801333A8;
    case 0x801333ACu: goto label_801333AC;
    case 0x801333B0u: goto label_801333B0;
    case 0x801333B4u: goto label_801333B4;
    case 0x801333B8u: goto label_801333B8;
    case 0x801333BCu: goto label_801333BC;
    case 0x801333C0u: goto label_801333C0;
    case 0x801333C4u: goto label_801333C4;
    case 0x801333C8u: goto label_801333C8;
    case 0x801333CCu: goto label_801333CC;
    case 0x801333D0u: goto label_801333D0;
    case 0x801333D4u: goto label_801333D4;
    case 0x801333D8u: goto label_801333D8;
    case 0x801333DCu: goto label_801333DC;
    case 0x801333E0u: goto label_801333E0;
    case 0x801333E4u: goto label_801333E4;
    case 0x801333E8u: goto label_801333E8;
    case 0x801333ECu: goto label_801333EC;
    case 0x801333F0u: goto label_801333F0;
    case 0x801333F4u: goto label_801333F4;
    case 0x801333F8u: goto label_801333F8;
    case 0x801333FCu: goto label_801333FC;
    case 0x80133400u: goto label_80133400;
    case 0x80133404u: goto label_80133404;
    case 0x80133408u: goto label_80133408;
    case 0x8013340Cu: goto label_8013340C;
    case 0x80133410u: goto label_80133410;
    case 0x80133414u: goto label_80133414;
    case 0x80133418u: goto label_80133418;
    case 0x8013341Cu: goto label_8013341C;
    case 0x80133420u: goto label_80133420;
    case 0x80133424u: goto label_80133424;
    case 0x80133428u: goto label_80133428;
    case 0x8013342Cu: goto label_8013342C;
    case 0x80133430u: goto label_80133430;
    case 0x80133434u: goto label_80133434;
    case 0x80133438u: goto label_80133438;
    case 0x8013343Cu: goto label_8013343C;
    case 0x80133440u: goto label_80133440;
    case 0x80133444u: goto label_80133444;
    case 0x80133448u: goto label_80133448;
    case 0x8013344Cu: goto label_8013344C;
    case 0x80133450u: goto label_80133450;
    case 0x80133454u: goto label_80133454;
    case 0x80133458u: goto label_80133458;
    case 0x8013345Cu: goto label_8013345C;
    case 0x80133460u: goto label_80133460;
    case 0x80133464u: goto label_80133464;
    case 0x80133468u: goto label_80133468;
    case 0x8013346Cu: goto label_8013346C;
    case 0x80133470u: goto label_80133470;
    case 0x80133474u: goto label_80133474;
    case 0x80133478u: goto label_80133478;
    case 0x8013347Cu: goto label_8013347C;
    case 0x80133480u: goto label_80133480;
    case 0x80133484u: goto label_80133484;
    case 0x80133488u: goto label_80133488;
    case 0x8013348Cu: goto label_8013348C;
    case 0x80133490u: goto label_80133490;
    case 0x80133494u: goto label_80133494;
    case 0x80133498u: goto label_80133498;
    case 0x8013349Cu: goto label_8013349C;
    case 0x801334A0u: goto label_801334A0;
    case 0x801334A4u: goto label_801334A4;
    case 0x801334A8u: goto label_801334A8;
    case 0x801334ACu: goto label_801334AC;
    case 0x801334B0u: goto label_801334B0;
    case 0x801334B4u: goto label_801334B4;
    case 0x801334B8u: goto label_801334B8;
    case 0x801334BCu: goto label_801334BC;
    case 0x801334C0u: goto label_801334C0;
    case 0x801334C4u: goto label_801334C4;
    case 0x801334C8u: goto label_801334C8;
    case 0x801334CCu: goto label_801334CC;
    case 0x801334D0u: goto label_801334D0;
    case 0x801334D4u: goto label_801334D4;
    case 0x801334D8u: goto label_801334D8;
    case 0x801334DCu: goto label_801334DC;
    case 0x801334E0u: goto label_801334E0;
    case 0x801334E4u: goto label_801334E4;
    case 0x801334E8u: goto label_801334E8;
    case 0x801334ECu: goto label_801334EC;
    case 0x801334F0u: goto label_801334F0;
    case 0x801334F4u: goto label_801334F4;
    case 0x801334F8u: goto label_801334F8;
    case 0x801334FCu: goto label_801334FC;
    case 0x80133500u: goto label_80133500;
    case 0x80133504u: goto label_80133504;
    case 0x80133508u: goto label_80133508;
    case 0x8013350Cu: goto label_8013350C;
    case 0x80133510u: goto label_80133510;
    case 0x80133514u: goto label_80133514;
    case 0x80133518u: goto label_80133518;
    case 0x8013351Cu: goto label_8013351C;
    case 0x80133520u: goto label_80133520;
    case 0x80133524u: goto label_80133524;
    case 0x80133528u: goto label_80133528;
    case 0x8013352Cu: goto label_8013352C;
    case 0x80133530u: goto label_80133530;
    case 0x80133534u: goto label_80133534;
    case 0x80133538u: goto label_80133538;
    case 0x8013353Cu: goto label_8013353C;
    case 0x80133540u: goto label_80133540;
    case 0x80133544u: goto label_80133544;
    case 0x80133548u: goto label_80133548;
    case 0x8013354Cu: goto label_8013354C;
    case 0x80133550u: goto label_80133550;
    case 0x80133554u: goto label_80133554;
    case 0x80133558u: goto label_80133558;
    case 0x8013355Cu: goto label_8013355C;
    case 0x80133560u: goto label_80133560;
    case 0x80133564u: goto label_80133564;
    case 0x80133568u: goto label_80133568;
    case 0x8013356Cu: goto label_8013356C;
    case 0x80133570u: goto label_80133570;
    case 0x80133574u: goto label_80133574;
    case 0x80133578u: goto label_80133578;
    case 0x8013357Cu: goto label_8013357C;
    case 0x80133580u: goto label_80133580;
    case 0x80133584u: goto label_80133584;
    case 0x80133588u: goto label_80133588;
    case 0x8013358Cu: goto label_8013358C;
    case 0x80133590u: goto label_80133590;
    case 0x80133594u: goto label_80133594;
    case 0x80133598u: goto label_80133598;
    case 0x8013359Cu: goto label_8013359C;
    case 0x801335A0u: goto label_801335A0;
    case 0x801335A4u: goto label_801335A4;
    case 0x801335A8u: goto label_801335A8;
    case 0x801335ACu: goto label_801335AC;
    case 0x801335B0u: goto label_801335B0;
    case 0x801335B4u: goto label_801335B4;
    case 0x801335B8u: goto label_801335B8;
    case 0x801335BCu: goto label_801335BC;
    case 0x801335C0u: goto label_801335C0;
    case 0x801335C4u: goto label_801335C4;
    case 0x801335C8u: goto label_801335C8;
    case 0x801335CCu: goto label_801335CC;
    case 0x801335D0u: goto label_801335D0;
    case 0x801335D4u: goto label_801335D4;
    case 0x801335D8u: goto label_801335D8;
    case 0x801335DCu: goto label_801335DC;
    case 0x801335E0u: goto label_801335E0;
    case 0x801335E4u: goto label_801335E4;
    case 0x801335E8u: goto label_801335E8;
    case 0x801335ECu: goto label_801335EC;
    case 0x801335F0u: goto label_801335F0;
    case 0x801335F4u: goto label_801335F4;
    case 0x801335F8u: goto label_801335F8;
    case 0x801335FCu: goto label_801335FC;
    case 0x80133600u: goto label_80133600;
    case 0x80133604u: goto label_80133604;
    case 0x80133608u: goto label_80133608;
    case 0x8013360Cu: goto label_8013360C;
    case 0x80133610u: goto label_80133610;
    case 0x80133614u: goto label_80133614;
    case 0x80133618u: goto label_80133618;
    case 0x8013361Cu: goto label_8013361C;
    case 0x80133620u: goto label_80133620;
    case 0x80133624u: goto label_80133624;
    case 0x80133628u: goto label_80133628;
    case 0x8013362Cu: goto label_8013362C;
    case 0x80133630u: goto label_80133630;
    case 0x80133634u: goto label_80133634;
    case 0x80133638u: goto label_80133638;
    case 0x8013363Cu: goto label_8013363C;
    case 0x80133640u: goto label_80133640;
    case 0x80133644u: goto label_80133644;
    case 0x80133648u: goto label_80133648;
    case 0x8013364Cu: goto label_8013364C;
    case 0x80133650u: goto label_80133650;
    case 0x80133654u: goto label_80133654;
    case 0x80133658u: goto label_80133658;
    case 0x8013365Cu: goto label_8013365C;
    case 0x80133660u: goto label_80133660;
    case 0x80133664u: goto label_80133664;
    case 0x80133668u: goto label_80133668;
    case 0x8013366Cu: goto label_8013366C;
    case 0x80133670u: goto label_80133670;
    case 0x80133674u: goto label_80133674;
    case 0x80133678u: goto label_80133678;
    case 0x8013367Cu: goto label_8013367C;
    case 0x80133680u: goto label_80133680;
    case 0x80133684u: goto label_80133684;
    case 0x80133688u: goto label_80133688;
    case 0x8013368Cu: goto label_8013368C;
    case 0x80133690u: goto label_80133690;
    case 0x80133694u: goto label_80133694;
    case 0x80133698u: goto label_80133698;
    case 0x8013369Cu: goto label_8013369C;
    case 0x801336A0u: goto label_801336A0;
    case 0x801336A4u: goto label_801336A4;
    case 0x801336A8u: goto label_801336A8;
    case 0x801336ACu: goto label_801336AC;
    case 0x801336B0u: goto label_801336B0;
    case 0x801336B4u: goto label_801336B4;
    case 0x801336B8u: goto label_801336B8;
    case 0x801336BCu: goto label_801336BC;
    case 0x801336C0u: goto label_801336C0;
    case 0x801336C4u: goto label_801336C4;
    case 0x801336C8u: goto label_801336C8;
    case 0x801336CCu: goto label_801336CC;
    case 0x801336D0u: goto label_801336D0;
    case 0x801336D4u: goto label_801336D4;
    case 0x801336D8u: goto label_801336D8;
    case 0x801336DCu: goto label_801336DC;
    case 0x801336E0u: goto label_801336E0;
    case 0x801336E4u: goto label_801336E4;
    case 0x801336E8u: goto label_801336E8;
    case 0x801336ECu: goto label_801336EC;
    case 0x801336F0u: goto label_801336F0;
    case 0x801336F4u: goto label_801336F4;
    case 0x801336F8u: goto label_801336F8;
    case 0x801336FCu: goto label_801336FC;
    case 0x80133700u: goto label_80133700;
    case 0x80133704u: goto label_80133704;
    case 0x80133708u: goto label_80133708;
    case 0x8013370Cu: goto label_8013370C;
    case 0x80133710u: goto label_80133710;
    case 0x80133714u: goto label_80133714;
    case 0x80133718u: goto label_80133718;
    case 0x8013371Cu: goto label_8013371C;
    case 0x80133720u: goto label_80133720;
    case 0x80133724u: goto label_80133724;
    case 0x80133728u: goto label_80133728;
    case 0x8013372Cu: goto label_8013372C;
    case 0x80133730u: goto label_80133730;
    case 0x80133734u: goto label_80133734;
    case 0x80133738u: goto label_80133738;
    case 0x8013373Cu: goto label_8013373C;
    case 0x80133740u: goto label_80133740;
    case 0x80133744u: goto label_80133744;
    case 0x80133748u: goto label_80133748;
    case 0x8013374Cu: goto label_8013374C;
    case 0x80133750u: goto label_80133750;
    case 0x80133754u: goto label_80133754;
    case 0x80133758u: goto label_80133758;
    case 0x8013375Cu: goto label_8013375C;
    case 0x80133760u: goto label_80133760;
    case 0x80133764u: goto label_80133764;
    case 0x80133768u: goto label_80133768;
    case 0x8013376Cu: goto label_8013376C;
    case 0x80133770u: goto label_80133770;
    case 0x80133774u: goto label_80133774;
    case 0x80133778u: goto label_80133778;
    case 0x8013377Cu: goto label_8013377C;
    case 0x80133780u: goto label_80133780;
    case 0x80133784u: goto label_80133784;
    case 0x80133788u: goto label_80133788;
    case 0x8013378Cu: goto label_8013378C;
    case 0x80133790u: goto label_80133790;
    case 0x80133794u: goto label_80133794;
    case 0x80133798u: goto label_80133798;
    case 0x8013379Cu: goto label_8013379C;
    case 0x801337A0u: goto label_801337A0;
    case 0x801337A4u: goto label_801337A4;
    case 0x801337A8u: goto label_801337A8;
    case 0x801337ACu: goto label_801337AC;
    case 0x801337B0u: goto label_801337B0;
    case 0x801337B4u: goto label_801337B4;
    case 0x801337B8u: goto label_801337B8;
    case 0x801337BCu: goto label_801337BC;
    case 0x801337C0u: goto label_801337C0;
    case 0x801337C4u: goto label_801337C4;
    case 0x801337C8u: goto label_801337C8;
    case 0x801337CCu: goto label_801337CC;
    case 0x801337D0u: goto label_801337D0;
    case 0x801337D4u: goto label_801337D4;
    case 0x801337D8u: goto label_801337D8;
    case 0x801337DCu: goto label_801337DC;
    case 0x801337E0u: goto label_801337E0;
    case 0x801337E4u: goto label_801337E4;
    case 0x801337E8u: goto label_801337E8;
    case 0x801337ECu: goto label_801337EC;
    case 0x801337F0u: goto label_801337F0;
    case 0x801337F4u: goto label_801337F4;
    case 0x801337F8u: goto label_801337F8;
    case 0x801337FCu: goto label_801337FC;
    case 0x80133800u: goto label_80133800;
    case 0x80133804u: goto label_80133804;
    case 0x80133808u: goto label_80133808;
    case 0x8013380Cu: goto label_8013380C;
    case 0x80133810u: goto label_80133810;
    case 0x80133814u: goto label_80133814;
    case 0x80133818u: goto label_80133818;
    case 0x8013381Cu: goto label_8013381C;
    case 0x80133820u: goto label_80133820;
    case 0x80133824u: goto label_80133824;
    case 0x80133828u: goto label_80133828;
    case 0x8013382Cu: goto label_8013382C;
    case 0x80133830u: goto label_80133830;
    case 0x80133834u: goto label_80133834;
    case 0x80133838u: goto label_80133838;
    case 0x8013383Cu: goto label_8013383C;
    case 0x80133840u: goto label_80133840;
    case 0x80133844u: goto label_80133844;
    case 0x80133848u: goto label_80133848;
    case 0x8013384Cu: goto label_8013384C;
    case 0x80133850u: goto label_80133850;
    case 0x80133854u: goto label_80133854;
    case 0x80133858u: goto label_80133858;
    case 0x8013385Cu: goto label_8013385C;
    case 0x80133860u: goto label_80133860;
    case 0x80133864u: goto label_80133864;
    case 0x80133868u: goto label_80133868;
    case 0x8013386Cu: goto label_8013386C;
    case 0x80133870u: goto label_80133870;
    case 0x80133874u: goto label_80133874;
    case 0x80133878u: goto label_80133878;
    case 0x8013387Cu: goto label_8013387C;
    case 0x80133880u: goto label_80133880;
    case 0x80133884u: goto label_80133884;
    case 0x80133888u: goto label_80133888;
    case 0x8013388Cu: goto label_8013388C;
    case 0x80133890u: goto label_80133890;
    case 0x80133894u: goto label_80133894;
    case 0x80133898u: goto label_80133898;
    case 0x8013389Cu: goto label_8013389C;
    case 0x801338A0u: goto label_801338A0;
    case 0x801338A4u: goto label_801338A4;
    case 0x801338A8u: goto label_801338A8;
    case 0x801338ACu: goto label_801338AC;
    case 0x801338B0u: goto label_801338B0;
    case 0x801338B4u: goto label_801338B4;
    case 0x801338B8u: goto label_801338B8;
    case 0x801338BCu: goto label_801338BC;
    case 0x801338C0u: goto label_801338C0;
    case 0x801338C4u: goto label_801338C4;
    case 0x801338C8u: goto label_801338C8;
    case 0x801338CCu: goto label_801338CC;
    case 0x801338D0u: goto label_801338D0;
    case 0x801338D4u: goto label_801338D4;
    case 0x801338D8u: goto label_801338D8;
    case 0x801338DCu: goto label_801338DC;
    case 0x801338E0u: goto label_801338E0;
    case 0x801338E4u: goto label_801338E4;
    case 0x801338E8u: goto label_801338E8;
    case 0x801338ECu: goto label_801338EC;
    case 0x801338F0u: goto label_801338F0;
    case 0x801338F4u: goto label_801338F4;
    case 0x801338F8u: goto label_801338F8;
    case 0x801338FCu: goto label_801338FC;
    case 0x80133900u: goto label_80133900;
    case 0x80133904u: goto label_80133904;
    case 0x80133908u: goto label_80133908;
    case 0x8013390Cu: goto label_8013390C;
    case 0x80133910u: goto label_80133910;
    case 0x80133914u: goto label_80133914;
    case 0x80133918u: goto label_80133918;
    case 0x8013391Cu: goto label_8013391C;
    case 0x80133920u: goto label_80133920;
    case 0x80133924u: goto label_80133924;
    case 0x80133928u: goto label_80133928;
    case 0x8013392Cu: goto label_8013392C;
    case 0x80133930u: goto label_80133930;
    case 0x80133934u: goto label_80133934;
    case 0x80133938u: goto label_80133938;
    case 0x8013393Cu: goto label_8013393C;
    case 0x80133940u: goto label_80133940;
    case 0x80133944u: goto label_80133944;
    case 0x80133948u: goto label_80133948;
    case 0x8013394Cu: goto label_8013394C;
    case 0x80133950u: goto label_80133950;
    case 0x80133954u: goto label_80133954;
    case 0x80133958u: goto label_80133958;
    case 0x8013395Cu: goto label_8013395C;
    case 0x80133960u: goto label_80133960;
    case 0x80133964u: goto label_80133964;
    case 0x80133968u: goto label_80133968;
    case 0x8013396Cu: goto label_8013396C;
    case 0x80133970u: goto label_80133970;
    case 0x80133974u: goto label_80133974;
    case 0x80133978u: goto label_80133978;
    case 0x8013397Cu: goto label_8013397C;
    case 0x80133980u: goto label_80133980;
    case 0x80133984u: goto label_80133984;
    case 0x80133988u: goto label_80133988;
    case 0x8013398Cu: goto label_8013398C;
    case 0x80133990u: goto label_80133990;
    case 0x80133994u: goto label_80133994;
    case 0x80133998u: goto label_80133998;
    case 0x8013399Cu: goto label_8013399C;
    case 0x801339A0u: goto label_801339A0;
    case 0x801339A4u: goto label_801339A4;
    case 0x801339A8u: goto label_801339A8;
    case 0x801339ACu: goto label_801339AC;
    case 0x801339B0u: goto label_801339B0;
    case 0x801339B4u: goto label_801339B4;
    case 0x801339B8u: goto label_801339B8;
    case 0x801339BCu: goto label_801339BC;
    case 0x801339C0u: goto label_801339C0;
    case 0x801339C4u: goto label_801339C4;
    case 0x801339C8u: goto label_801339C8;
    case 0x801339CCu: goto label_801339CC;
    case 0x801339D0u: goto label_801339D0;
    case 0x801339D4u: goto label_801339D4;
    case 0x801339D8u: goto label_801339D8;
    case 0x801339DCu: goto label_801339DC;
    case 0x801339E0u: goto label_801339E0;
    case 0x801339E4u: goto label_801339E4;
    case 0x801339E8u: goto label_801339E8;
    case 0x801339ECu: goto label_801339EC;
    case 0x801339F0u: goto label_801339F0;
    case 0x801339F4u: goto label_801339F4;
    case 0x801339F8u: goto label_801339F8;
    case 0x801339FCu: goto label_801339FC;
    case 0x80133A00u: goto label_80133A00;
    case 0x80133A04u: goto label_80133A04;
    case 0x80133A08u: goto label_80133A08;
    case 0x80133A0Cu: goto label_80133A0C;
    case 0x80133A10u: goto label_80133A10;
    case 0x80133A14u: goto label_80133A14;
    case 0x80133A18u: goto label_80133A18;
    case 0x80133A1Cu: goto label_80133A1C;
    case 0x80133A20u: goto label_80133A20;
    case 0x80133A24u: goto label_80133A24;
    case 0x80133A28u: goto label_80133A28;
    case 0x80133A2Cu: goto label_80133A2C;
    case 0x80133A30u: goto label_80133A30;
    case 0x80133A34u: goto label_80133A34;
    case 0x80133A38u: goto label_80133A38;
    case 0x80133A3Cu: goto label_80133A3C;
    case 0x80133A40u: goto label_80133A40;
    case 0x80133A44u: goto label_80133A44;
    case 0x80133A48u: goto label_80133A48;
    case 0x80133A4Cu: goto label_80133A4C;
    case 0x80133A50u: goto label_80133A50;
    case 0x80133A54u: goto label_80133A54;
    case 0x80133A58u: goto label_80133A58;
    case 0x80133A5Cu: goto label_80133A5C;
    case 0x80133A60u: goto label_80133A60;
    case 0x80133A64u: goto label_80133A64;
    case 0x80133A68u: goto label_80133A68;
    case 0x80133A6Cu: goto label_80133A6C;
    case 0x80133A70u: goto label_80133A70;
    case 0x80133A74u: goto label_80133A74;
    case 0x80133A78u: goto label_80133A78;
    case 0x80133A7Cu: goto label_80133A7C;
    case 0x80133A80u: goto label_80133A80;
    case 0x80133A84u: goto label_80133A84;
    case 0x80133A88u: goto label_80133A88;
    case 0x80133A8Cu: goto label_80133A8C;
    case 0x80133A90u: goto label_80133A90;
    case 0x80133A94u: goto label_80133A94;
    case 0x80133A98u: goto label_80133A98;
    case 0x80133A9Cu: goto label_80133A9C;
    case 0x80133AA0u: goto label_80133AA0;
    case 0x80133AA4u: goto label_80133AA4;
    case 0x80133AA8u: goto label_80133AA8;
    case 0x80133AACu: goto label_80133AAC;
    case 0x80133AB0u: goto label_80133AB0;
    case 0x80133AB4u: goto label_80133AB4;
    case 0x80133AB8u: goto label_80133AB8;
    case 0x80133ABCu: goto label_80133ABC;
    case 0x80133AC0u: goto label_80133AC0;
    case 0x80133AC4u: goto label_80133AC4;
    case 0x80133AC8u: goto label_80133AC8;
    case 0x80133ACCu: goto label_80133ACC;
    case 0x80133AD0u: goto label_80133AD0;
    case 0x80133AD4u: goto label_80133AD4;
    case 0x80133AD8u: goto label_80133AD8;
    case 0x80133ADCu: goto label_80133ADC;
    case 0x80133AE0u: goto label_80133AE0;
    case 0x80133AE4u: goto label_80133AE4;
    case 0x80133AE8u: goto label_80133AE8;
    case 0x80133AECu: goto label_80133AEC;
    case 0x80133AF0u: goto label_80133AF0;
    case 0x80133AF4u: goto label_80133AF4;
    case 0x80133AF8u: goto label_80133AF8;
    case 0x80133AFCu: goto label_80133AFC;
    case 0x80133B00u: goto label_80133B00;
    case 0x80133B04u: goto label_80133B04;
    case 0x80133B08u: goto label_80133B08;
    case 0x80133B0Cu: goto label_80133B0C;
    case 0x80133B10u: goto label_80133B10;
    case 0x80133B14u: goto label_80133B14;
    case 0x80133B18u: goto label_80133B18;
    case 0x80133B1Cu: goto label_80133B1C;
    case 0x80133B20u: goto label_80133B20;
    case 0x80133B24u: goto label_80133B24;
    case 0x80133B28u: goto label_80133B28;
    case 0x80133B2Cu: goto label_80133B2C;
    case 0x80133B30u: goto label_80133B30;
    case 0x80133B34u: goto label_80133B34;
    case 0x80133B38u: goto label_80133B38;
    case 0x80133B3Cu: goto label_80133B3C;
    case 0x80133B40u: goto label_80133B40;
    case 0x80133B44u: goto label_80133B44;
    case 0x80133B48u: goto label_80133B48;
    case 0x80133B4Cu: goto label_80133B4C;
    case 0x80133B50u: goto label_80133B50;
    case 0x80133B54u: goto label_80133B54;
    case 0x80133B58u: goto label_80133B58;
    case 0x80133B5Cu: goto label_80133B5C;
    case 0x80133B60u: goto label_80133B60;
    case 0x80133B64u: goto label_80133B64;
    case 0x80133B68u: goto label_80133B68;
    case 0x80133B6Cu: goto label_80133B6C;
    case 0x80133B70u: goto label_80133B70;
    case 0x80133B74u: goto label_80133B74;
    case 0x80133B78u: goto label_80133B78;
    case 0x80133B7Cu: goto label_80133B7C;
    case 0x80133B80u: goto label_80133B80;
    case 0x80133B84u: goto label_80133B84;
    case 0x80133B88u: goto label_80133B88;
    case 0x80133B8Cu: goto label_80133B8C;
    case 0x80133B90u: goto label_80133B90;
    case 0x80133B94u: goto label_80133B94;
    case 0x80133B98u: goto label_80133B98;
    case 0x80133B9Cu: goto label_80133B9C;
    case 0x80133BA0u: goto label_80133BA0;
    case 0x80133BA4u: goto label_80133BA4;
    case 0x80133BA8u: goto label_80133BA8;
    case 0x80133BACu: goto label_80133BAC;
    case 0x80133BB0u: goto label_80133BB0;
    case 0x80133BB4u: goto label_80133BB4;
    case 0x80133BB8u: goto label_80133BB8;
    case 0x80133BBCu: goto label_80133BBC;
    case 0x80133BC0u: goto label_80133BC0;
    case 0x80133BC4u: goto label_80133BC4;
    case 0x80133BC8u: goto label_80133BC8;
    case 0x80133BCCu: goto label_80133BCC;
    case 0x80133BD0u: goto label_80133BD0;
    case 0x80133BD4u: goto label_80133BD4;
    case 0x80133BD8u: goto label_80133BD8;
    case 0x80133BDCu: goto label_80133BDC;
    case 0x80133BE0u: goto label_80133BE0;
    case 0x80133BE4u: goto label_80133BE4;
    case 0x80133BE8u: goto label_80133BE8;
    case 0x80133BECu: goto label_80133BEC;
    case 0x80133BF0u: goto label_80133BF0;
    case 0x80133BF4u: goto label_80133BF4;
    case 0x80133BF8u: goto label_80133BF8;
    case 0x80133BFCu: goto label_80133BFC;
    case 0x80133C00u: goto label_80133C00;
    case 0x80133C04u: goto label_80133C04;
    case 0x80133C08u: goto label_80133C08;
    case 0x80133C0Cu: goto label_80133C0C;
    case 0x80133C10u: goto label_80133C10;
    case 0x80133C14u: goto label_80133C14;
    case 0x80133C18u: goto label_80133C18;
    case 0x80133C1Cu: goto label_80133C1C;
    case 0x80133C20u: goto label_80133C20;
    case 0x80133C24u: goto label_80133C24;
    case 0x80133C28u: goto label_80133C28;
    case 0x80133C2Cu: goto label_80133C2C;
    case 0x80133C30u: goto label_80133C30;
    case 0x80133C34u: goto label_80133C34;
    case 0x80133C38u: goto label_80133C38;
    case 0x80133C3Cu: goto label_80133C3C;
    case 0x80133C40u: goto label_80133C40;
    case 0x80133C44u: goto label_80133C44;
    case 0x80133C48u: goto label_80133C48;
    case 0x80133C4Cu: goto label_80133C4C;
    case 0x80133C50u: goto label_80133C50;
    case 0x80133C54u: goto label_80133C54;
    case 0x80133C58u: goto label_80133C58;
    case 0x80133C5Cu: goto label_80133C5C;
    case 0x80133C60u: goto label_80133C60;
    case 0x80133C64u: goto label_80133C64;
    case 0x80133C68u: goto label_80133C68;
    case 0x80133C6Cu: goto label_80133C6C;
    case 0x80133C70u: goto label_80133C70;
    case 0x80133C74u: goto label_80133C74;
    case 0x80133C78u: goto label_80133C78;
    case 0x80133C7Cu: goto label_80133C7C;
    case 0x80133C80u: goto label_80133C80;
    case 0x80133C84u: goto label_80133C84;
    case 0x80133C88u: goto label_80133C88;
    case 0x80133C8Cu: goto label_80133C8C;
    case 0x80133C90u: goto label_80133C90;
    case 0x80133C94u: goto label_80133C94;
    case 0x80133C98u: goto label_80133C98;
    case 0x80133C9Cu: goto label_80133C9C;
    case 0x80133CA0u: goto label_80133CA0;
    case 0x80133CA4u: goto label_80133CA4;
    case 0x80133CA8u: goto label_80133CA8;
    case 0x80133CACu: goto label_80133CAC;
    case 0x80133CB0u: goto label_80133CB0;
    case 0x80133CB4u: goto label_80133CB4;
    case 0x80133CB8u: goto label_80133CB8;
    case 0x80133CBCu: goto label_80133CBC;
    case 0x80133CC0u: goto label_80133CC0;
    case 0x80133CC4u: goto label_80133CC4;
    case 0x80133CC8u: goto label_80133CC8;
    case 0x80133CCCu: goto label_80133CCC;
    case 0x80133CD0u: goto label_80133CD0;
    case 0x80133CD4u: goto label_80133CD4;
    case 0x80133CD8u: goto label_80133CD8;
    case 0x80133CDCu: goto label_80133CDC;
    case 0x80133CE0u: goto label_80133CE0;
    case 0x80133CE4u: goto label_80133CE4;
    case 0x80133CE8u: goto label_80133CE8;
    case 0x80133CECu: goto label_80133CEC;
    case 0x80133CF0u: goto label_80133CF0;
    case 0x80133CF4u: goto label_80133CF4;
    case 0x80133CF8u: goto label_80133CF8;
    case 0x80133CFCu: goto label_80133CFC;
    case 0x80133D00u: goto label_80133D00;
    case 0x80133D04u: goto label_80133D04;
    case 0x80133D08u: goto label_80133D08;
    case 0x80133D0Cu: goto label_80133D0C;
    case 0x80133D10u: goto label_80133D10;
    case 0x80133D14u: goto label_80133D14;
    case 0x80133D18u: goto label_80133D18;
    case 0x80133D1Cu: goto label_80133D1C;
    case 0x80133D20u: goto label_80133D20;
    case 0x80133D24u: goto label_80133D24;
    case 0x80133D28u: goto label_80133D28;
    case 0x80133D2Cu: goto label_80133D2C;
    case 0x80133D30u: goto label_80133D30;
    case 0x80133D34u: goto label_80133D34;
    case 0x80133D38u: goto label_80133D38;
    case 0x80133D3Cu: goto label_80133D3C;
    case 0x80133D40u: goto label_80133D40;
    case 0x80133D44u: goto label_80133D44;
    case 0x80133D48u: goto label_80133D48;
    case 0x80133D4Cu: goto label_80133D4C;
    case 0x80133D50u: goto label_80133D50;
    case 0x80133D54u: goto label_80133D54;
    case 0x80133D58u: goto label_80133D58;
    case 0x80133D5Cu: goto label_80133D5C;
    case 0x80133D60u: goto label_80133D60;
    case 0x80133D64u: goto label_80133D64;
    case 0x80133D68u: goto label_80133D68;
    case 0x80133D6Cu: goto label_80133D6C;
    case 0x80133D70u: goto label_80133D70;
    case 0x80133D74u: goto label_80133D74;
    case 0x80133D78u: goto label_80133D78;
    case 0x80133D7Cu: goto label_80133D7C;
    case 0x80133D80u: goto label_80133D80;
    case 0x80133D84u: goto label_80133D84;
    case 0x80133D88u: goto label_80133D88;
    case 0x80133D8Cu: goto label_80133D8C;
    case 0x80133D90u: goto label_80133D90;
    case 0x80133D94u: goto label_80133D94;
    case 0x80133D98u: goto label_80133D98;
    case 0x80133D9Cu: goto label_80133D9C;
    case 0x80133DA0u: goto label_80133DA0;
    case 0x80133DA4u: goto label_80133DA4;
    case 0x80133DA8u: goto label_80133DA8;
    case 0x80133DACu: goto label_80133DAC;
    case 0x80133DB0u: goto label_80133DB0;
    case 0x80133DB4u: goto label_80133DB4;
    case 0x80133DB8u: goto label_80133DB8;
    case 0x80133DBCu: goto label_80133DBC;
    case 0x80133DC0u: goto label_80133DC0;
    case 0x80133DC4u: goto label_80133DC4;
    case 0x80133DC8u: goto label_80133DC8;
    case 0x80133DCCu: goto label_80133DCC;
    case 0x80133DD0u: goto label_80133DD0;
    case 0x80133DD4u: goto label_80133DD4;
    case 0x80133DD8u: goto label_80133DD8;
    case 0x80133DDCu: goto label_80133DDC;
    case 0x80133DE0u: goto label_80133DE0;
    case 0x80133DE4u: goto label_80133DE4;
    case 0x80133DE8u: goto label_80133DE8;
    case 0x80133DECu: goto label_80133DEC;
    case 0x80133DF0u: goto label_80133DF0;
    case 0x80133DF4u: goto label_80133DF4;
    case 0x80133DF8u: goto label_80133DF8;
    case 0x80133DFCu: goto label_80133DFC;
    case 0x80133E00u: goto label_80133E00;
    case 0x80133E04u: goto label_80133E04;
    case 0x80133E08u: goto label_80133E08;
    case 0x80133E0Cu: goto label_80133E0C;
    case 0x80133E10u: goto label_80133E10;
    case 0x80133E14u: goto label_80133E14;
    case 0x80133E18u: goto label_80133E18;
    case 0x80133E1Cu: goto label_80133E1C;
    case 0x80133E20u: goto label_80133E20;
    case 0x80133E24u: goto label_80133E24;
    case 0x80133E28u: goto label_80133E28;
    case 0x80133E2Cu: goto label_80133E2C;
    case 0x80133E30u: goto label_80133E30;
    case 0x80133E34u: goto label_80133E34;
    case 0x80133E38u: goto label_80133E38;
    case 0x80133E3Cu: goto label_80133E3C;
    case 0x80133E40u: goto label_80133E40;
    case 0x80133E44u: goto label_80133E44;
    case 0x80133E48u: goto label_80133E48;
    case 0x80133E4Cu: goto label_80133E4C;
    case 0x80133E50u: goto label_80133E50;
    case 0x80133E54u: goto label_80133E54;
    case 0x80133E58u: goto label_80133E58;
    case 0x80133E5Cu: goto label_80133E5C;
    case 0x80133E60u: goto label_80133E60;
    case 0x80133E64u: goto label_80133E64;
    case 0x80133E68u: goto label_80133E68;
    case 0x80133E6Cu: goto label_80133E6C;
    case 0x80133E70u: goto label_80133E70;
    case 0x80133E74u: goto label_80133E74;
    case 0x80133E78u: goto label_80133E78;
    case 0x80133E7Cu: goto label_80133E7C;
    case 0x80133E80u: goto label_80133E80;
    case 0x80133E84u: goto label_80133E84;
    case 0x80133E88u: goto label_80133E88;
    case 0x80133E8Cu: goto label_80133E8C;
    case 0x80133E90u: goto label_80133E90;
    case 0x80133E94u: goto label_80133E94;
    case 0x80133E98u: goto label_80133E98;
    case 0x80133E9Cu: goto label_80133E9C;
    case 0x80133EA0u: goto label_80133EA0;
    case 0x80133EA4u: goto label_80133EA4;
    case 0x80133EA8u: goto label_80133EA8;
    case 0x80133EACu: goto label_80133EAC;
    case 0x80133EB0u: goto label_80133EB0;
    case 0x80133EB4u: goto label_80133EB4;
    case 0x80133EB8u: goto label_80133EB8;
    case 0x80133EBCu: goto label_80133EBC;
    case 0x80133EC0u: goto label_80133EC0;
    case 0x80133EC4u: goto label_80133EC4;
    case 0x80133EC8u: goto label_80133EC8;
    case 0x80133ECCu: goto label_80133ECC;
    case 0x80133ED0u: goto label_80133ED0;
    case 0x80133ED4u: goto label_80133ED4;
    case 0x80133ED8u: goto label_80133ED8;
    case 0x80133EDCu: goto label_80133EDC;
    case 0x80133EE0u: goto label_80133EE0;
    case 0x80133EE4u: goto label_80133EE4;
    case 0x80133EE8u: goto label_80133EE8;
    case 0x80133EECu: goto label_80133EEC;
    case 0x80133EF0u: goto label_80133EF0;
    case 0x80133EF4u: goto label_80133EF4;
    case 0x80133EF8u: goto label_80133EF8;
    case 0x80133EFCu: goto label_80133EFC;
    case 0x80133F00u: goto label_80133F00;
    case 0x80133F04u: goto label_80133F04;
    case 0x80133F08u: goto label_80133F08;
    case 0x80133F0Cu: goto label_80133F0C;
    case 0x80133F10u: goto label_80133F10;
    case 0x80133F14u: goto label_80133F14;
    case 0x80133F18u: goto label_80133F18;
    case 0x80133F1Cu: goto label_80133F1C;
    case 0x80133F20u: goto label_80133F20;
    case 0x80133F24u: goto label_80133F24;
    case 0x80133F28u: goto label_80133F28;
    case 0x80133F2Cu: goto label_80133F2C;
    case 0x80133F30u: goto label_80133F30;
    case 0x80133F34u: goto label_80133F34;
    case 0x80133F38u: goto label_80133F38;
    case 0x80133F3Cu: goto label_80133F3C;
    case 0x80133F40u: goto label_80133F40;
    case 0x80133F44u: goto label_80133F44;
    case 0x80133F48u: goto label_80133F48;
    case 0x80133F4Cu: goto label_80133F4C;
    case 0x80133F50u: goto label_80133F50;
    case 0x80133F54u: goto label_80133F54;
    case 0x80133F58u: goto label_80133F58;
    case 0x80133F5Cu: goto label_80133F5C;
    case 0x80133F60u: goto label_80133F60;
    case 0x80133F64u: goto label_80133F64;
    case 0x80133F68u: goto label_80133F68;
    case 0x80133F6Cu: goto label_80133F6C;
    case 0x80133F70u: goto label_80133F70;
    case 0x80133F74u: goto label_80133F74;
    case 0x80133F78u: goto label_80133F78;
    case 0x80133F7Cu: goto label_80133F7C;
    case 0x80133F80u: goto label_80133F80;
    case 0x80133F84u: goto label_80133F84;
    case 0x80133F88u: goto label_80133F88;
    case 0x80133F8Cu: goto label_80133F8C;
    case 0x80133F90u: goto label_80133F90;
    case 0x80133F94u: goto label_80133F94;
    case 0x80133F98u: goto label_80133F98;
    case 0x80133F9Cu: goto label_80133F9C;
    case 0x80133FA0u: goto label_80133FA0;
    case 0x80133FA4u: goto label_80133FA4;
    case 0x80133FA8u: goto label_80133FA8;
    case 0x80133FACu: goto label_80133FAC;
    case 0x80133FB0u: goto label_80133FB0;
    case 0x80133FB4u: goto label_80133FB4;
    case 0x80133FB8u: goto label_80133FB8;
    case 0x80133FBCu: goto label_80133FBC;
    case 0x80133FC0u: goto label_80133FC0;
    case 0x80133FC4u: goto label_80133FC4;
    case 0x80133FC8u: goto label_80133FC8;
    case 0x80133FCCu: goto label_80133FCC;
    case 0x80133FD0u: goto label_80133FD0;
    case 0x80133FD4u: goto label_80133FD4;
    case 0x80133FD8u: goto label_80133FD8;
    case 0x80133FDCu: goto label_80133FDC;
    case 0x80133FE0u: goto label_80133FE0;
    case 0x80133FE4u: goto label_80133FE4;
    case 0x80133FE8u: goto label_80133FE8;
    case 0x80133FECu: goto label_80133FEC;
    case 0x80133FF0u: goto label_80133FF0;
    case 0x80133FF4u: goto label_80133FF4;
    case 0x80133FF8u: goto label_80133FF8;
    case 0x80133FFCu: goto label_80133FFC;
    case 0x80134000u: goto label_80134000;
    case 0x80134004u: goto label_80134004;
    case 0x80134008u: goto label_80134008;
    case 0x8013400Cu: goto label_8013400C;
    case 0x80134010u: goto label_80134010;
    case 0x80134014u: goto label_80134014;
    case 0x80134018u: goto label_80134018;
    case 0x8013401Cu: goto label_8013401C;
    case 0x80134020u: goto label_80134020;
    case 0x80134024u: goto label_80134024;
    case 0x80134028u: goto label_80134028;
    case 0x8013402Cu: goto label_8013402C;
    case 0x80134030u: goto label_80134030;
    case 0x80134034u: goto label_80134034;
    case 0x80134038u: goto label_80134038;
    case 0x8013403Cu: goto label_8013403C;
    case 0x80134040u: goto label_80134040;
    case 0x80134044u: goto label_80134044;
    case 0x80134048u: goto label_80134048;
    case 0x8013404Cu: goto label_8013404C;
    case 0x80134050u: goto label_80134050;
    case 0x80134054u: goto label_80134054;
    case 0x80134058u: goto label_80134058;
    case 0x8013405Cu: goto label_8013405C;
    case 0x80134060u: goto label_80134060;
    case 0x80134064u: goto label_80134064;
    case 0x80134068u: goto label_80134068;
    case 0x8013406Cu: goto label_8013406C;
    case 0x80134070u: goto label_80134070;
    case 0x80134074u: goto label_80134074;
    case 0x80134078u: goto label_80134078;
    case 0x8013407Cu: goto label_8013407C;
    case 0x80134080u: goto label_80134080;
    case 0x80134084u: goto label_80134084;
    case 0x80134088u: goto label_80134088;
    case 0x8013408Cu: goto label_8013408C;
    case 0x80134090u: goto label_80134090;
    case 0x80134094u: goto label_80134094;
    case 0x80134098u: goto label_80134098;
    case 0x8013409Cu: goto label_8013409C;
    case 0x801340A0u: goto label_801340A0;
    case 0x801340A4u: goto label_801340A4;
    case 0x801340A8u: goto label_801340A8;
    case 0x801340ACu: goto label_801340AC;
    case 0x801340B0u: goto label_801340B0;
    case 0x801340B4u: goto label_801340B4;
    case 0x801340B8u: goto label_801340B8;
    case 0x801340BCu: goto label_801340BC;
    case 0x801340C0u: goto label_801340C0;
    case 0x801340C4u: goto label_801340C4;
    case 0x801340C8u: goto label_801340C8;
    case 0x801340CCu: goto label_801340CC;
    case 0x801340D0u: goto label_801340D0;
    case 0x801340D4u: goto label_801340D4;
    case 0x801340D8u: goto label_801340D8;
    case 0x801340DCu: goto label_801340DC;
    case 0x801340E0u: goto label_801340E0;
    case 0x801340E4u: goto label_801340E4;
    case 0x801340E8u: goto label_801340E8;
    case 0x801340ECu: goto label_801340EC;
    case 0x801340F0u: goto label_801340F0;
    case 0x801340F4u: goto label_801340F4;
    case 0x801340F8u: goto label_801340F8;
    case 0x801340FCu: goto label_801340FC;
    case 0x80134100u: goto label_80134100;
    case 0x80134104u: goto label_80134104;
    case 0x80134108u: goto label_80134108;
    case 0x8013410Cu: goto label_8013410C;
    case 0x80134110u: goto label_80134110;
    case 0x80134114u: goto label_80134114;
    case 0x80134118u: goto label_80134118;
    case 0x8013411Cu: goto label_8013411C;
    case 0x80134120u: goto label_80134120;
    case 0x80134124u: goto label_80134124;
    case 0x80134128u: goto label_80134128;
    case 0x8013412Cu: goto label_8013412C;
    case 0x80134130u: goto label_80134130;
    case 0x80134134u: goto label_80134134;
    case 0x80134138u: goto label_80134138;
    case 0x8013413Cu: goto label_8013413C;
    case 0x80134140u: goto label_80134140;
    case 0x80134144u: goto label_80134144;
    case 0x80134148u: goto label_80134148;
    case 0x8013414Cu: goto label_8013414C;
    case 0x80134150u: goto label_80134150;
    case 0x80134154u: goto label_80134154;
    case 0x80134158u: goto label_80134158;
    case 0x8013415Cu: goto label_8013415C;
    case 0x80134160u: goto label_80134160;
    case 0x80134164u: goto label_80134164;
    case 0x80134168u: goto label_80134168;
    case 0x8013416Cu: goto label_8013416C;
    case 0x80134170u: goto label_80134170;
    case 0x80134174u: goto label_80134174;
    case 0x80134178u: goto label_80134178;
    case 0x8013417Cu: goto label_8013417C;
    case 0x80134180u: goto label_80134180;
    case 0x80134184u: goto label_80134184;
    case 0x80134188u: goto label_80134188;
    case 0x8013418Cu: goto label_8013418C;
    case 0x80134190u: goto label_80134190;
    case 0x80134194u: goto label_80134194;
    case 0x80134198u: goto label_80134198;
    case 0x8013419Cu: goto label_8013419C;
    case 0x801341A0u: goto label_801341A0;
    case 0x801341A4u: goto label_801341A4;
    case 0x801341A8u: goto label_801341A8;
    case 0x801341ACu: goto label_801341AC;
    case 0x801341B0u: goto label_801341B0;
    case 0x801341B4u: goto label_801341B4;
    case 0x801341B8u: goto label_801341B8;
    case 0x801341BCu: goto label_801341BC;
    case 0x801341C0u: goto label_801341C0;
    case 0x801341C4u: goto label_801341C4;
    case 0x801341C8u: goto label_801341C8;
    case 0x801341CCu: goto label_801341CC;
    case 0x801341D0u: goto label_801341D0;
    case 0x801341D4u: goto label_801341D4;
    case 0x801341D8u: goto label_801341D8;
    case 0x801341DCu: goto label_801341DC;
    case 0x801341E0u: goto label_801341E0;
    case 0x801341E4u: goto label_801341E4;
    case 0x801341E8u: goto label_801341E8;
    case 0x801341ECu: goto label_801341EC;
    case 0x801341F0u: goto label_801341F0;
    case 0x801341F4u: goto label_801341F4;
    case 0x801341F8u: goto label_801341F8;
    case 0x801341FCu: goto label_801341FC;
    case 0x80134200u: goto label_80134200;
    case 0x80134204u: goto label_80134204;
    case 0x80134208u: goto label_80134208;
    case 0x8013420Cu: goto label_8013420C;
    case 0x80134210u: goto label_80134210;
    case 0x80134214u: goto label_80134214;
    case 0x80134218u: goto label_80134218;
    case 0x8013421Cu: goto label_8013421C;
    case 0x80134220u: goto label_80134220;
    case 0x80134224u: goto label_80134224;
    case 0x80134228u: goto label_80134228;
    case 0x8013422Cu: goto label_8013422C;
    case 0x80134230u: goto label_80134230;
    case 0x80134234u: goto label_80134234;
    case 0x80134238u: goto label_80134238;
    case 0x8013423Cu: goto label_8013423C;
    case 0x80134240u: goto label_80134240;
    case 0x80134244u: goto label_80134244;
    case 0x80134248u: goto label_80134248;
    case 0x8013424Cu: goto label_8013424C;
    case 0x80134250u: goto label_80134250;
    case 0x80134254u: goto label_80134254;
    case 0x80134258u: goto label_80134258;
    case 0x8013425Cu: goto label_8013425C;
    case 0x80134260u: goto label_80134260;
    case 0x80134264u: goto label_80134264;
    case 0x80134268u: goto label_80134268;
    case 0x8013426Cu: goto label_8013426C;
    case 0x80134270u: goto label_80134270;
    case 0x80134274u: goto label_80134274;
    case 0x80134278u: goto label_80134278;
    case 0x8013427Cu: goto label_8013427C;
    case 0x80134280u: goto label_80134280;
    case 0x80134284u: goto label_80134284;
    case 0x80134288u: goto label_80134288;
    case 0x8013428Cu: goto label_8013428C;
    case 0x80134290u: goto label_80134290;
    case 0x80134294u: goto label_80134294;
    case 0x80134298u: goto label_80134298;
    case 0x8013429Cu: goto label_8013429C;
    case 0x801342A0u: goto label_801342A0;
    case 0x801342A4u: goto label_801342A4;
    case 0x801342A8u: goto label_801342A8;
    case 0x801342ACu: goto label_801342AC;
    case 0x801342B0u: goto label_801342B0;
    case 0x801342B4u: goto label_801342B4;
    case 0x801342B8u: goto label_801342B8;
    case 0x801342BCu: goto label_801342BC;
    case 0x801342C0u: goto label_801342C0;
    case 0x801342C4u: goto label_801342C4;
    case 0x801342C8u: goto label_801342C8;
    case 0x801342CCu: goto label_801342CC;
    case 0x801342D0u: goto label_801342D0;
    case 0x801342D4u: goto label_801342D4;
    case 0x801342D8u: goto label_801342D8;
    case 0x801342DCu: goto label_801342DC;
    case 0x801342E0u: goto label_801342E0;
    case 0x801342E4u: goto label_801342E4;
    case 0x801342E8u: goto label_801342E8;
    case 0x801342ECu: goto label_801342EC;
    case 0x801342F0u: goto label_801342F0;
    case 0x801342F4u: goto label_801342F4;
    case 0x801342F8u: goto label_801342F8;
    case 0x801342FCu: goto label_801342FC;
    case 0x80134300u: goto label_80134300;
    case 0x80134304u: goto label_80134304;
    case 0x80134308u: goto label_80134308;
    case 0x8013430Cu: goto label_8013430C;
    case 0x80134310u: goto label_80134310;
    case 0x80134314u: goto label_80134314;
    case 0x80134318u: goto label_80134318;
    case 0x8013431Cu: goto label_8013431C;
    case 0x80134320u: goto label_80134320;
    case 0x80134324u: goto label_80134324;
    case 0x80134328u: goto label_80134328;
    case 0x8013432Cu: goto label_8013432C;
    case 0x80134330u: goto label_80134330;
    case 0x80134334u: goto label_80134334;
    case 0x80134338u: goto label_80134338;
    case 0x8013433Cu: goto label_8013433C;
    case 0x80134340u: goto label_80134340;
    case 0x80134344u: goto label_80134344;
    case 0x80134348u: goto label_80134348;
    case 0x8013434Cu: goto label_8013434C;
    case 0x80134350u: goto label_80134350;
    case 0x80134354u: goto label_80134354;
    case 0x80134358u: goto label_80134358;
    case 0x8013435Cu: goto label_8013435C;
    case 0x80134360u: goto label_80134360;
    case 0x80134364u: goto label_80134364;
    case 0x80134368u: goto label_80134368;
    case 0x8013436Cu: goto label_8013436C;
    case 0x80134370u: goto label_80134370;
    case 0x80134374u: goto label_80134374;
    case 0x80134378u: goto label_80134378;
    case 0x8013437Cu: goto label_8013437C;
    case 0x80134380u: goto label_80134380;
    case 0x80134384u: goto label_80134384;
    case 0x80134388u: goto label_80134388;
    case 0x8013438Cu: goto label_8013438C;
    case 0x80134390u: goto label_80134390;
    case 0x80134394u: goto label_80134394;
    case 0x80134398u: goto label_80134398;
    case 0x8013439Cu: goto label_8013439C;
    case 0x801343A0u: goto label_801343A0;
    case 0x801343A4u: goto label_801343A4;
    case 0x801343A8u: goto label_801343A8;
    case 0x801343ACu: goto label_801343AC;
    case 0x801343B0u: goto label_801343B0;
    case 0x801343B4u: goto label_801343B4;
    case 0x801343B8u: goto label_801343B8;
    case 0x801343BCu: goto label_801343BC;
    case 0x801343C0u: goto label_801343C0;
    case 0x801343C4u: goto label_801343C4;
    case 0x801343C8u: goto label_801343C8;
    case 0x801343CCu: goto label_801343CC;
    case 0x801343D0u: goto label_801343D0;
    case 0x801343D4u: goto label_801343D4;
    case 0x801343D8u: goto label_801343D8;
    case 0x801343DCu: goto label_801343DC;
    case 0x801343E0u: goto label_801343E0;
    case 0x801343E4u: goto label_801343E4;
    case 0x801343E8u: goto label_801343E8;
    case 0x801343ECu: goto label_801343EC;
    case 0x801343F0u: goto label_801343F0;
    case 0x801343F4u: goto label_801343F4;
    case 0x801343F8u: goto label_801343F8;
    case 0x801343FCu: goto label_801343FC;
    case 0x80134400u: goto label_80134400;
    case 0x80134404u: goto label_80134404;
    case 0x80134408u: goto label_80134408;
    case 0x8013440Cu: goto label_8013440C;
    case 0x80134410u: goto label_80134410;
    case 0x80134414u: goto label_80134414;
    case 0x80134418u: goto label_80134418;
    case 0x8013441Cu: goto label_8013441C;
    case 0x80134420u: goto label_80134420;
    case 0x80134424u: goto label_80134424;
    case 0x80134428u: goto label_80134428;
    case 0x8013442Cu: goto label_8013442C;
    case 0x80134430u: goto label_80134430;
    case 0x80134434u: goto label_80134434;
    case 0x80134438u: goto label_80134438;
    case 0x8013443Cu: goto label_8013443C;
    case 0x80134440u: goto label_80134440;
    case 0x80134444u: goto label_80134444;
    case 0x80134448u: goto label_80134448;
    case 0x8013444Cu: goto label_8013444C;
    case 0x80134450u: goto label_80134450;
    case 0x80134454u: goto label_80134454;
    case 0x80134458u: goto label_80134458;
    case 0x8013445Cu: goto label_8013445C;
    case 0x80134460u: goto label_80134460;
    case 0x80134464u: goto label_80134464;
    case 0x80134468u: goto label_80134468;
    case 0x8013446Cu: goto label_8013446C;
    case 0x80134470u: goto label_80134470;
    case 0x80134474u: goto label_80134474;
    case 0x80134478u: goto label_80134478;
    case 0x8013447Cu: goto label_8013447C;
    case 0x80134480u: goto label_80134480;
    case 0x80134484u: goto label_80134484;
    case 0x80134488u: goto label_80134488;
    case 0x8013448Cu: goto label_8013448C;
    case 0x80134490u: goto label_80134490;
    case 0x80134494u: goto label_80134494;
    case 0x80134498u: goto label_80134498;
    case 0x8013449Cu: goto label_8013449C;
    case 0x801344A0u: goto label_801344A0;
    case 0x801344A4u: goto label_801344A4;
    case 0x801344A8u: goto label_801344A8;
    case 0x801344ACu: goto label_801344AC;
    case 0x801344B0u: goto label_801344B0;
    case 0x801344B4u: goto label_801344B4;
    case 0x801344B8u: goto label_801344B8;
    case 0x801344BCu: goto label_801344BC;
    case 0x801344C0u: goto label_801344C0;
    case 0x801344C4u: goto label_801344C4;
    case 0x801344C8u: goto label_801344C8;
    case 0x801344CCu: goto label_801344CC;
    case 0x801344D0u: goto label_801344D0;
    case 0x801344D4u: goto label_801344D4;
    case 0x801344D8u: goto label_801344D8;
    case 0x801344DCu: goto label_801344DC;
    case 0x801344E0u: goto label_801344E0;
    case 0x801344E4u: goto label_801344E4;
    case 0x801344E8u: goto label_801344E8;
    case 0x801344ECu: goto label_801344EC;
    case 0x801344F0u: goto label_801344F0;
    case 0x801344F4u: goto label_801344F4;
    case 0x801344F8u: goto label_801344F8;
    case 0x801344FCu: goto label_801344FC;
    case 0x80134500u: goto label_80134500;
    case 0x80134504u: goto label_80134504;
    case 0x80134508u: goto label_80134508;
    case 0x8013450Cu: goto label_8013450C;
    case 0x80134510u: goto label_80134510;
    case 0x80134514u: goto label_80134514;
    case 0x80134518u: goto label_80134518;
    case 0x8013451Cu: goto label_8013451C;
    case 0x80134520u: goto label_80134520;
    case 0x80134524u: goto label_80134524;
    case 0x80134528u: goto label_80134528;
    case 0x8013452Cu: goto label_8013452C;
    case 0x80134530u: goto label_80134530;
    case 0x80134534u: goto label_80134534;
    case 0x80134538u: goto label_80134538;
    case 0x8013453Cu: goto label_8013453C;
    case 0x80134540u: goto label_80134540;
    case 0x80134544u: goto label_80134544;
    case 0x80134548u: goto label_80134548;
    case 0x8013454Cu: goto label_8013454C;
    case 0x80134550u: goto label_80134550;
    case 0x80134554u: goto label_80134554;
    case 0x80134558u: goto label_80134558;
    case 0x8013455Cu: goto label_8013455C;
    case 0x80134560u: goto label_80134560;
    case 0x80134564u: goto label_80134564;
    case 0x80134568u: goto label_80134568;
    case 0x8013456Cu: goto label_8013456C;
    case 0x80134570u: goto label_80134570;
    case 0x80134574u: goto label_80134574;
    case 0x80134578u: goto label_80134578;
    case 0x8013457Cu: goto label_8013457C;
    case 0x80134580u: goto label_80134580;
    case 0x80134584u: goto label_80134584;
    case 0x80134588u: goto label_80134588;
    case 0x8013458Cu: goto label_8013458C;
    case 0x80134590u: goto label_80134590;
    case 0x80134594u: goto label_80134594;
    case 0x80134598u: goto label_80134598;
    case 0x8013459Cu: goto label_8013459C;
    case 0x801345A0u: goto label_801345A0;
    case 0x801345A4u: goto label_801345A4;
    case 0x801345A8u: goto label_801345A8;
    case 0x801345ACu: goto label_801345AC;
    case 0x801345B0u: goto label_801345B0;
    case 0x801345B4u: goto label_801345B4;
    case 0x801345B8u: goto label_801345B8;
    case 0x801345BCu: goto label_801345BC;
    case 0x801345C0u: goto label_801345C0;
    case 0x801345C4u: goto label_801345C4;
    case 0x801345C8u: goto label_801345C8;
    case 0x801345CCu: goto label_801345CC;
    case 0x801345D0u: goto label_801345D0;
    case 0x801345D4u: goto label_801345D4;
    case 0x801345D8u: goto label_801345D8;
    case 0x801345DCu: goto label_801345DC;
    case 0x801345E0u: goto label_801345E0;
    case 0x801345E4u: goto label_801345E4;
    case 0x801345E8u: goto label_801345E8;
    case 0x801345ECu: goto label_801345EC;
    case 0x801345F0u: goto label_801345F0;
    case 0x801345F4u: goto label_801345F4;
    case 0x801345F8u: goto label_801345F8;
    case 0x801345FCu: goto label_801345FC;
    case 0x80134600u: goto label_80134600;
    case 0x80134604u: goto label_80134604;
    case 0x80134608u: goto label_80134608;
    case 0x8013460Cu: goto label_8013460C;
    case 0x80134610u: goto label_80134610;
    case 0x80134614u: goto label_80134614;
    case 0x80134618u: goto label_80134618;
    case 0x8013461Cu: goto label_8013461C;
    case 0x80134620u: goto label_80134620;
    case 0x80134624u: goto label_80134624;
    case 0x80134628u: goto label_80134628;
    case 0x8013462Cu: goto label_8013462C;
    case 0x80134630u: goto label_80134630;
    case 0x80134634u: goto label_80134634;
    case 0x80134638u: goto label_80134638;
    case 0x8013463Cu: goto label_8013463C;
    case 0x80134640u: goto label_80134640;
    case 0x80134644u: goto label_80134644;
    case 0x80134648u: goto label_80134648;
    case 0x8013464Cu: goto label_8013464C;
    case 0x80134650u: goto label_80134650;
    case 0x80134654u: goto label_80134654;
    case 0x80134658u: goto label_80134658;
    case 0x8013465Cu: goto label_8013465C;
    case 0x80134660u: goto label_80134660;
    case 0x80134664u: goto label_80134664;
    case 0x80134668u: goto label_80134668;
    case 0x8013466Cu: goto label_8013466C;
    case 0x80134670u: goto label_80134670;
    case 0x80134674u: goto label_80134674;
    case 0x80134678u: goto label_80134678;
    case 0x8013467Cu: goto label_8013467C;
    case 0x80134680u: goto label_80134680;
    case 0x80134684u: goto label_80134684;
    case 0x80134688u: goto label_80134688;
    case 0x8013468Cu: goto label_8013468C;
    case 0x80134690u: goto label_80134690;
    case 0x80134694u: goto label_80134694;
    case 0x80134698u: goto label_80134698;
    case 0x8013469Cu: goto label_8013469C;
    case 0x801346A0u: goto label_801346A0;
    case 0x801346A4u: goto label_801346A4;
    case 0x801346A8u: goto label_801346A8;
    case 0x801346ACu: goto label_801346AC;
    case 0x801346B0u: goto label_801346B0;
    case 0x801346B4u: goto label_801346B4;
    case 0x801346B8u: goto label_801346B8;
    case 0x801346BCu: goto label_801346BC;
    case 0x801346C0u: goto label_801346C0;
    case 0x801346C4u: goto label_801346C4;
    case 0x801346C8u: goto label_801346C8;
    case 0x801346CCu: goto label_801346CC;
    case 0x801346D0u: goto label_801346D0;
    case 0x801346D4u: goto label_801346D4;
    case 0x801346D8u: goto label_801346D8;
    case 0x801346DCu: goto label_801346DC;
    case 0x801346E0u: goto label_801346E0;
    case 0x801346E4u: goto label_801346E4;
    case 0x801346E8u: goto label_801346E8;
    case 0x801346ECu: goto label_801346EC;
    case 0x801346F0u: goto label_801346F0;
    case 0x801346F4u: goto label_801346F4;
    case 0x801346F8u: goto label_801346F8;
    case 0x801346FCu: goto label_801346FC;
    case 0x80134700u: goto label_80134700;
    case 0x80134704u: goto label_80134704;
    case 0x80134708u: goto label_80134708;
    case 0x8013470Cu: goto label_8013470C;
    case 0x80134710u: goto label_80134710;
    case 0x80134714u: goto label_80134714;
    case 0x80134718u: goto label_80134718;
    case 0x8013471Cu: goto label_8013471C;
    case 0x80134720u: goto label_80134720;
    case 0x80134724u: goto label_80134724;
    case 0x80134728u: goto label_80134728;
    case 0x8013472Cu: goto label_8013472C;
    case 0x80134730u: goto label_80134730;
    case 0x80134734u: goto label_80134734;
    case 0x80134738u: goto label_80134738;
    case 0x8013473Cu: goto label_8013473C;
    case 0x80134740u: goto label_80134740;
    case 0x80134744u: goto label_80134744;
    case 0x80134748u: goto label_80134748;
    case 0x8013474Cu: goto label_8013474C;
    case 0x80134750u: goto label_80134750;
    case 0x80134754u: goto label_80134754;
    case 0x80134758u: goto label_80134758;
    case 0x8013475Cu: goto label_8013475C;
    case 0x80134760u: goto label_80134760;
    case 0x80134764u: goto label_80134764;
    case 0x80134768u: goto label_80134768;
    case 0x8013476Cu: goto label_8013476C;
    case 0x80134770u: goto label_80134770;
    case 0x80134774u: goto label_80134774;
    case 0x80134778u: goto label_80134778;
    case 0x8013477Cu: goto label_8013477C;
    case 0x80134780u: goto label_80134780;
    case 0x80134784u: goto label_80134784;
    case 0x80134788u: goto label_80134788;
    case 0x8013478Cu: goto label_8013478C;
    case 0x80134790u: goto label_80134790;
    case 0x80134794u: goto label_80134794;
    case 0x80134798u: goto label_80134798;
    case 0x8013479Cu: goto label_8013479C;
    case 0x801347A0u: goto label_801347A0;
    case 0x801347A4u: goto label_801347A4;
    case 0x801347A8u: goto label_801347A8;
    case 0x801347ACu: goto label_801347AC;
    case 0x801347B0u: goto label_801347B0;
    case 0x801347B4u: goto label_801347B4;
    case 0x801347B8u: goto label_801347B8;
    case 0x801347BCu: goto label_801347BC;
    case 0x801347C0u: goto label_801347C0;
    case 0x801347C4u: goto label_801347C4;
    case 0x801347C8u: goto label_801347C8;
    case 0x801347CCu: goto label_801347CC;
    case 0x801347D0u: goto label_801347D0;
    case 0x801347D4u: goto label_801347D4;
    case 0x801347D8u: goto label_801347D8;
    case 0x801347DCu: goto label_801347DC;
    case 0x801347E0u: goto label_801347E0;
    case 0x801347E4u: goto label_801347E4;
    case 0x801347E8u: goto label_801347E8;
    case 0x801347ECu: goto label_801347EC;
    case 0x801347F0u: goto label_801347F0;
    case 0x801347F4u: goto label_801347F4;
    case 0x801347F8u: goto label_801347F8;
    case 0x801347FCu: goto label_801347FC;
    case 0x80134800u: goto label_80134800;
    case 0x80134804u: goto label_80134804;
    case 0x80134808u: goto label_80134808;
    case 0x8013480Cu: goto label_8013480C;
    case 0x80134810u: goto label_80134810;
    case 0x80134814u: goto label_80134814;
    case 0x80134818u: goto label_80134818;
    case 0x8013481Cu: goto label_8013481C;
    case 0x80134820u: goto label_80134820;
    case 0x80134824u: goto label_80134824;
    case 0x80134828u: goto label_80134828;
    case 0x8013482Cu: goto label_8013482C;
    case 0x80134830u: goto label_80134830;
    case 0x80134834u: goto label_80134834;
    case 0x80134838u: goto label_80134838;
    case 0x8013483Cu: goto label_8013483C;
    case 0x80134840u: goto label_80134840;
    case 0x80134844u: goto label_80134844;
    case 0x80134848u: goto label_80134848;
    case 0x8013484Cu: goto label_8013484C;
    case 0x80134850u: goto label_80134850;
    case 0x80134854u: goto label_80134854;
    case 0x80134858u: goto label_80134858;
    case 0x8013485Cu: goto label_8013485C;
    case 0x80134860u: goto label_80134860;
    case 0x80134864u: goto label_80134864;
    case 0x80134868u: goto label_80134868;
    case 0x8013486Cu: goto label_8013486C;
    case 0x80134870u: goto label_80134870;
    case 0x80134874u: goto label_80134874;
    case 0x80134878u: goto label_80134878;
    case 0x8013487Cu: goto label_8013487C;
    case 0x80134880u: goto label_80134880;
    case 0x80134884u: goto label_80134884;
    case 0x80134888u: goto label_80134888;
    case 0x8013488Cu: goto label_8013488C;
    case 0x80134890u: goto label_80134890;
    case 0x80134894u: goto label_80134894;
    case 0x80134898u: goto label_80134898;
    case 0x8013489Cu: goto label_8013489C;
    case 0x801348A0u: goto label_801348A0;
    case 0x801348A4u: goto label_801348A4;
    case 0x801348A8u: goto label_801348A8;
    case 0x801348ACu: goto label_801348AC;
    case 0x801348B0u: goto label_801348B0;
    case 0x801348B4u: goto label_801348B4;
    case 0x801348B8u: goto label_801348B8;
    case 0x801348BCu: goto label_801348BC;
    case 0x801348C0u: goto label_801348C0;
    case 0x801348C4u: goto label_801348C4;
    case 0x801348C8u: goto label_801348C8;
    case 0x801348CCu: goto label_801348CC;
    case 0x801348D0u: goto label_801348D0;
    case 0x801348D4u: goto label_801348D4;
    case 0x801348D8u: goto label_801348D8;
    case 0x801348DCu: goto label_801348DC;
    case 0x801348E0u: goto label_801348E0;
    case 0x801348E4u: goto label_801348E4;
    case 0x801348E8u: goto label_801348E8;
    case 0x801348ECu: goto label_801348EC;
    case 0x801348F0u: goto label_801348F0;
    case 0x801348F4u: goto label_801348F4;
    case 0x801348F8u: goto label_801348F8;
    case 0x801348FCu: goto label_801348FC;
    case 0x80134900u: goto label_80134900;
    case 0x80134904u: goto label_80134904;
    case 0x80134908u: goto label_80134908;
    case 0x8013490Cu: goto label_8013490C;
    case 0x80134910u: goto label_80134910;
    case 0x80134914u: goto label_80134914;
    case 0x80134918u: goto label_80134918;
    case 0x8013491Cu: goto label_8013491C;
    case 0x80134920u: goto label_80134920;
    case 0x80134924u: goto label_80134924;
    case 0x80134928u: goto label_80134928;
    case 0x8013492Cu: goto label_8013492C;
    case 0x80134930u: goto label_80134930;
    case 0x80134934u: goto label_80134934;
    case 0x80134938u: goto label_80134938;
    case 0x8013493Cu: goto label_8013493C;
    case 0x80134940u: goto label_80134940;
    case 0x80134944u: goto label_80134944;
    case 0x80134948u: goto label_80134948;
    case 0x8013494Cu: goto label_8013494C;
    case 0x80134950u: goto label_80134950;
    case 0x80134954u: goto label_80134954;
    case 0x80134958u: goto label_80134958;
    case 0x8013495Cu: goto label_8013495C;
    case 0x80134960u: goto label_80134960;
    case 0x80134964u: goto label_80134964;
    case 0x80134968u: goto label_80134968;
    case 0x8013496Cu: goto label_8013496C;
    case 0x80134970u: goto label_80134970;
    case 0x80134974u: goto label_80134974;
    case 0x80134978u: goto label_80134978;
    case 0x8013497Cu: goto label_8013497C;
    case 0x80134980u: goto label_80134980;
    case 0x80134984u: goto label_80134984;
    case 0x80134988u: goto label_80134988;
    case 0x8013498Cu: goto label_8013498C;
    case 0x80134990u: goto label_80134990;
    case 0x80134994u: goto label_80134994;
    case 0x80134998u: goto label_80134998;
    case 0x8013499Cu: goto label_8013499C;
    case 0x801349A0u: goto label_801349A0;
    case 0x801349A4u: goto label_801349A4;
    case 0x801349A8u: goto label_801349A8;
    case 0x801349ACu: goto label_801349AC;
    case 0x801349B0u: goto label_801349B0;
    case 0x801349B4u: goto label_801349B4;
    case 0x801349B8u: goto label_801349B8;
    case 0x801349BCu: goto label_801349BC;
    case 0x801349C0u: goto label_801349C0;
    case 0x801349C4u: goto label_801349C4;
    case 0x801349C8u: goto label_801349C8;
    case 0x801349CCu: goto label_801349CC;
    case 0x801349D0u: goto label_801349D0;
    case 0x801349D4u: goto label_801349D4;
    case 0x801349D8u: goto label_801349D8;
    case 0x801349DCu: goto label_801349DC;
    case 0x801349E0u: goto label_801349E0;
    case 0x801349E4u: goto label_801349E4;
    case 0x801349E8u: goto label_801349E8;
    case 0x801349ECu: goto label_801349EC;
    case 0x801349F0u: goto label_801349F0;
    case 0x801349F4u: goto label_801349F4;
    case 0x801349F8u: goto label_801349F8;
    case 0x801349FCu: goto label_801349FC;
    case 0x80134A00u: goto label_80134A00;
    case 0x80134A04u: goto label_80134A04;
    case 0x80134A08u: goto label_80134A08;
    case 0x80134A0Cu: goto label_80134A0C;
    case 0x80134A10u: goto label_80134A10;
    case 0x80134A14u: goto label_80134A14;
    case 0x80134A18u: goto label_80134A18;
    case 0x80134A1Cu: goto label_80134A1C;
    case 0x80134A20u: goto label_80134A20;
    case 0x80134A24u: goto label_80134A24;
    case 0x80134A28u: goto label_80134A28;
    case 0x80134A2Cu: goto label_80134A2C;
    case 0x80134A30u: goto label_80134A30;
    case 0x80134A34u: goto label_80134A34;
    case 0x80134A38u: goto label_80134A38;
    case 0x80134A3Cu: goto label_80134A3C;
    case 0x80134A40u: goto label_80134A40;
    case 0x80134A44u: goto label_80134A44;
    case 0x80134A48u: goto label_80134A48;
    case 0x80134A4Cu: goto label_80134A4C;
    case 0x80134A50u: goto label_80134A50;
    case 0x80134A54u: goto label_80134A54;
    case 0x80134A58u: goto label_80134A58;
    case 0x80134A5Cu: goto label_80134A5C;
    case 0x80134A60u: goto label_80134A60;
    case 0x80134A64u: goto label_80134A64;
    case 0x80134A68u: goto label_80134A68;
    case 0x80134A6Cu: goto label_80134A6C;
    case 0x80134A70u: goto label_80134A70;
    case 0x80134A74u: goto label_80134A74;
    case 0x80134A78u: goto label_80134A78;
    case 0x80134A7Cu: goto label_80134A7C;
    case 0x80134A80u: goto label_80134A80;
    case 0x80134A84u: goto label_80134A84;
    case 0x80134A88u: goto label_80134A88;
    case 0x80134A8Cu: goto label_80134A8C;
    case 0x80134A90u: goto label_80134A90;
    case 0x80134A94u: goto label_80134A94;
    case 0x80134A98u: goto label_80134A98;
    case 0x80134A9Cu: goto label_80134A9C;
    case 0x80134AA0u: goto label_80134AA0;
    case 0x80134AA4u: goto label_80134AA4;
    case 0x80134AA8u: goto label_80134AA8;
    case 0x80134AACu: goto label_80134AAC;
    case 0x80134AB0u: goto label_80134AB0;
    case 0x80134AB4u: goto label_80134AB4;
    case 0x80134AB8u: goto label_80134AB8;
    case 0x80134ABCu: goto label_80134ABC;
    case 0x80134AC0u: goto label_80134AC0;
    case 0x80134AC4u: goto label_80134AC4;
    case 0x80134AC8u: goto label_80134AC8;
    case 0x80134ACCu: goto label_80134ACC;
    case 0x80134AD0u: goto label_80134AD0;
    case 0x80134AD4u: goto label_80134AD4;
    case 0x80134AD8u: goto label_80134AD8;
    case 0x80134ADCu: goto label_80134ADC;
    case 0x80134AE0u: goto label_80134AE0;
    case 0x80134AE4u: goto label_80134AE4;
    case 0x80134AE8u: goto label_80134AE8;
    case 0x80134AECu: goto label_80134AEC;
    case 0x80134AF0u: goto label_80134AF0;
    case 0x80134AF4u: goto label_80134AF4;
    case 0x80134AF8u: goto label_80134AF8;
    case 0x80134AFCu: goto label_80134AFC;
    case 0x80134B00u: goto label_80134B00;
    case 0x80134B04u: goto label_80134B04;
    case 0x80134B08u: goto label_80134B08;
    case 0x80134B0Cu: goto label_80134B0C;
    case 0x80134B10u: goto label_80134B10;
    case 0x80134B14u: goto label_80134B14;
    case 0x80134B18u: goto label_80134B18;
    case 0x80134B1Cu: goto label_80134B1C;
    case 0x80134B20u: goto label_80134B20;
    case 0x80134B24u: goto label_80134B24;
    case 0x80134B28u: goto label_80134B28;
    case 0x80134B2Cu: goto label_80134B2C;
    case 0x80134B30u: goto label_80134B30;
    case 0x80134B34u: goto label_80134B34;
    case 0x80134B38u: goto label_80134B38;
    case 0x80134B3Cu: goto label_80134B3C;
    case 0x80134B40u: goto label_80134B40;
    case 0x80134B44u: goto label_80134B44;
    case 0x80134B48u: goto label_80134B48;
    case 0x80134B4Cu: goto label_80134B4C;
    case 0x80134B50u: goto label_80134B50;
    case 0x80134B54u: goto label_80134B54;
    case 0x80134B58u: goto label_80134B58;
    case 0x80134B5Cu: goto label_80134B5C;
    case 0x80134B60u: goto label_80134B60;
    case 0x80134B64u: goto label_80134B64;
    case 0x80134B68u: goto label_80134B68;
    case 0x80134B6Cu: goto label_80134B6C;
    case 0x80134B70u: goto label_80134B70;
    case 0x80134B74u: goto label_80134B74;
    case 0x80134B78u: goto label_80134B78;
    case 0x80134B7Cu: goto label_80134B7C;
    case 0x80134B80u: goto label_80134B80;
    case 0x80134B84u: goto label_80134B84;
    case 0x80134B88u: goto label_80134B88;
    case 0x80134B8Cu: goto label_80134B8C;
    case 0x80134B90u: goto label_80134B90;
    case 0x80134B94u: goto label_80134B94;
    case 0x80134B98u: goto label_80134B98;
    case 0x80134B9Cu: goto label_80134B9C;
    case 0x80134BA0u: goto label_80134BA0;
    case 0x80134BA4u: goto label_80134BA4;
    case 0x80134BA8u: goto label_80134BA8;
    case 0x80134BACu: goto label_80134BAC;
    case 0x80134BB0u: goto label_80134BB0;
    case 0x80134BB4u: goto label_80134BB4;
    case 0x80134BB8u: goto label_80134BB8;
    case 0x80134BBCu: goto label_80134BBC;
    case 0x80134BC0u: goto label_80134BC0;
    case 0x80134BC4u: goto label_80134BC4;
    case 0x80134BC8u: goto label_80134BC8;
    case 0x80134BCCu: goto label_80134BCC;
    case 0x80134BD0u: goto label_80134BD0;
    case 0x80134BD4u: goto label_80134BD4;
    case 0x80134BD8u: goto label_80134BD8;
    case 0x80134BDCu: goto label_80134BDC;
    case 0x80134BE0u: goto label_80134BE0;
    case 0x80134BE4u: goto label_80134BE4;
    case 0x80134BE8u: goto label_80134BE8;
    case 0x80134BECu: goto label_80134BEC;
    case 0x80134BF0u: goto label_80134BF0;
    case 0x80134BF4u: goto label_80134BF4;
    case 0x80134BF8u: goto label_80134BF8;
    case 0x80134BFCu: goto label_80134BFC;
    case 0x80134C00u: goto label_80134C00;
    case 0x80134C04u: goto label_80134C04;
    case 0x80134C08u: goto label_80134C08;
    case 0x80134C0Cu: goto label_80134C0C;
    case 0x80134C10u: goto label_80134C10;
    case 0x80134C14u: goto label_80134C14;
    case 0x80134C18u: goto label_80134C18;
    case 0x80134C1Cu: goto label_80134C1C;
    case 0x80134C20u: goto label_80134C20;
    case 0x80134C24u: goto label_80134C24;
    case 0x80134C28u: goto label_80134C28;
    case 0x80134C2Cu: goto label_80134C2C;
    case 0x80134C30u: goto label_80134C30;
    case 0x80134C34u: goto label_80134C34;
    case 0x80134C38u: goto label_80134C38;
    case 0x80134C3Cu: goto label_80134C3C;
    case 0x80134C40u: goto label_80134C40;
    case 0x80134C44u: goto label_80134C44;
    case 0x80134C48u: goto label_80134C48;
    case 0x80134C4Cu: goto label_80134C4C;
    case 0x80134C50u: goto label_80134C50;
    case 0x80134C54u: goto label_80134C54;
    case 0x80134C58u: goto label_80134C58;
    case 0x80134C5Cu: goto label_80134C5C;
    case 0x80134C60u: goto label_80134C60;
    case 0x80134C64u: goto label_80134C64;
    case 0x80134C68u: goto label_80134C68;
    case 0x80134C6Cu: goto label_80134C6C;
    case 0x80134C70u: goto label_80134C70;
    case 0x80134C74u: goto label_80134C74;
    case 0x80134C78u: goto label_80134C78;
    case 0x80134C7Cu: goto label_80134C7C;
    case 0x80134C80u: goto label_80134C80;
    case 0x80134C84u: goto label_80134C84;
    case 0x80134C88u: goto label_80134C88;
    case 0x80134C8Cu: goto label_80134C8C;
    case 0x80134C90u: goto label_80134C90;
    case 0x80134C94u: goto label_80134C94;
    case 0x80134C98u: goto label_80134C98;
    case 0x80134C9Cu: goto label_80134C9C;
    case 0x80134CA0u: goto label_80134CA0;
    case 0x80134CA4u: goto label_80134CA4;
    case 0x80134CA8u: goto label_80134CA8;
    case 0x80134CACu: goto label_80134CAC;
    case 0x80134CB0u: goto label_80134CB0;
    case 0x80134CB4u: goto label_80134CB4;
    case 0x80134CB8u: goto label_80134CB8;
    case 0x80134CBCu: goto label_80134CBC;
    case 0x80134CC0u: goto label_80134CC0;
    case 0x80134CC4u: goto label_80134CC4;
    case 0x80134CC8u: goto label_80134CC8;
    case 0x80134CCCu: goto label_80134CCC;
    case 0x80134CD0u: goto label_80134CD0;
    case 0x80134CD4u: goto label_80134CD4;
    case 0x80134CD8u: goto label_80134CD8;
    case 0x80134CDCu: goto label_80134CDC;
    case 0x80134CE0u: goto label_80134CE0;
    case 0x80134CE4u: goto label_80134CE4;
    case 0x80134CE8u: goto label_80134CE8;
    case 0x80134CECu: goto label_80134CEC;
    case 0x80134CF0u: goto label_80134CF0;
    case 0x80134CF4u: goto label_80134CF4;
    case 0x80134CF8u: goto label_80134CF8;
    case 0x80134CFCu: goto label_80134CFC;
    case 0x80134D00u: goto label_80134D00;
    case 0x80134D04u: goto label_80134D04;
    case 0x80134D08u: goto label_80134D08;
    case 0x80134D0Cu: goto label_80134D0C;
    case 0x80134D10u: goto label_80134D10;
    case 0x80134D14u: goto label_80134D14;
    case 0x80134D18u: goto label_80134D18;
    case 0x80134D1Cu: goto label_80134D1C;
    case 0x80134D20u: goto label_80134D20;
    case 0x80134D24u: goto label_80134D24;
    case 0x80134D28u: goto label_80134D28;
    case 0x80134D2Cu: goto label_80134D2C;
    case 0x80134D30u: goto label_80134D30;
    case 0x80134D34u: goto label_80134D34;
    case 0x80134D38u: goto label_80134D38;
    case 0x80134D3Cu: goto label_80134D3C;
    case 0x80134D40u: goto label_80134D40;
    case 0x80134D44u: goto label_80134D44;
    case 0x80134D48u: goto label_80134D48;
    case 0x80134D4Cu: goto label_80134D4C;
    case 0x80134D50u: goto label_80134D50;
    case 0x80134D54u: goto label_80134D54;
    case 0x80134D58u: goto label_80134D58;
    case 0x80134D5Cu: goto label_80134D5C;
    case 0x80134D60u: goto label_80134D60;
    case 0x80134D64u: goto label_80134D64;
    case 0x80134D68u: goto label_80134D68;
    case 0x80134D6Cu: goto label_80134D6C;
    case 0x80134D70u: goto label_80134D70;
    case 0x80134D74u: goto label_80134D74;
    case 0x80134D78u: goto label_80134D78;
    case 0x80134D7Cu: goto label_80134D7C;
    case 0x80134D80u: goto label_80134D80;
    case 0x80134D84u: goto label_80134D84;
    case 0x80134D88u: goto label_80134D88;
    case 0x80134D8Cu: goto label_80134D8C;
    case 0x80134D90u: goto label_80134D90;
    case 0x80134D94u: goto label_80134D94;
    case 0x80134D98u: goto label_80134D98;
    case 0x80134D9Cu: goto label_80134D9C;
    case 0x80134DA0u: goto label_80134DA0;
    case 0x80134DA4u: goto label_80134DA4;
    case 0x80134DA8u: goto label_80134DA8;
    case 0x80134DACu: goto label_80134DAC;
    case 0x80134DB0u: goto label_80134DB0;
    case 0x80134DB4u: goto label_80134DB4;
    case 0x80134DB8u: goto label_80134DB8;
    case 0x80134DBCu: goto label_80134DBC;
    case 0x80134DC0u: goto label_80134DC0;
    case 0x80134DC4u: goto label_80134DC4;
    case 0x80134DC8u: goto label_80134DC8;
    case 0x80134DCCu: goto label_80134DCC;
    case 0x80134DD0u: goto label_80134DD0;
    case 0x80134DD4u: goto label_80134DD4;
    case 0x80134DD8u: goto label_80134DD8;
    case 0x80134DDCu: goto label_80134DDC;
    case 0x80134DE0u: goto label_80134DE0;
    case 0x80134DE4u: goto label_80134DE4;
    case 0x80134DE8u: goto label_80134DE8;
    case 0x80134DECu: goto label_80134DEC;
    case 0x80134DF0u: goto label_80134DF0;
    case 0x80134DF4u: goto label_80134DF4;
    case 0x80134DF8u: goto label_80134DF8;
    case 0x80134DFCu: goto label_80134DFC;
    case 0x80134E00u: goto label_80134E00;
    case 0x80134E04u: goto label_80134E04;
    case 0x80134E08u: goto label_80134E08;
    case 0x80134E0Cu: goto label_80134E0C;
    case 0x80134E10u: goto label_80134E10;
    case 0x80134E14u: goto label_80134E14;
    case 0x80134E18u: goto label_80134E18;
    case 0x80134E1Cu: goto label_80134E1C;
    case 0x80134E20u: goto label_80134E20;
    case 0x80134E24u: goto label_80134E24;
    case 0x80134E28u: goto label_80134E28;
    case 0x80134E2Cu: goto label_80134E2C;
    case 0x80134E30u: goto label_80134E30;
    case 0x80134E34u: goto label_80134E34;
    case 0x80134E38u: goto label_80134E38;
    case 0x80134E3Cu: goto label_80134E3C;
    case 0x80134E40u: goto label_80134E40;
    case 0x80134E44u: goto label_80134E44;
    case 0x80134E48u: goto label_80134E48;
    case 0x80134E4Cu: goto label_80134E4C;
    case 0x80134E50u: goto label_80134E50;
    case 0x80134E54u: goto label_80134E54;
    case 0x80134E58u: goto label_80134E58;
    case 0x80134E5Cu: goto label_80134E5C;
    case 0x80134E60u: goto label_80134E60;
    case 0x80134E64u: goto label_80134E64;
    case 0x80134E68u: goto label_80134E68;
    case 0x80134E6Cu: goto label_80134E6C;
    case 0x80134E70u: goto label_80134E70;
    case 0x80134E74u: goto label_80134E74;
    case 0x80134E78u: goto label_80134E78;
    case 0x80134E7Cu: goto label_80134E7C;
    case 0x80134E80u: goto label_80134E80;
    case 0x80134E84u: goto label_80134E84;
    case 0x80134E88u: goto label_80134E88;
    case 0x80134E8Cu: goto label_80134E8C;
    case 0x80134E90u: goto label_80134E90;
    case 0x80134E94u: goto label_80134E94;
    case 0x80134E98u: goto label_80134E98;
    case 0x80134E9Cu: goto label_80134E9C;
    case 0x80134EA0u: goto label_80134EA0;
    case 0x80134EA4u: goto label_80134EA4;
    case 0x80134EA8u: goto label_80134EA8;
    case 0x80134EACu: goto label_80134EAC;
    case 0x80134EB0u: goto label_80134EB0;
    case 0x80134EB4u: goto label_80134EB4;
    case 0x80134EB8u: goto label_80134EB8;
    case 0x80134EBCu: goto label_80134EBC;
    case 0x80134EC0u: goto label_80134EC0;
    case 0x80134EC4u: goto label_80134EC4;
    case 0x80134EC8u: goto label_80134EC8;
    case 0x80134ECCu: goto label_80134ECC;
    case 0x80134ED0u: goto label_80134ED0;
    case 0x80134ED4u: goto label_80134ED4;
    case 0x80134ED8u: goto label_80134ED8;
    case 0x80134EDCu: goto label_80134EDC;
    case 0x80134EE0u: goto label_80134EE0;
    case 0x80134EE4u: goto label_80134EE4;
    case 0x80134EE8u: goto label_80134EE8;
    case 0x80134EECu: goto label_80134EEC;
    case 0x80134EF0u: goto label_80134EF0;
    case 0x80134EF4u: goto label_80134EF4;
    case 0x80134EF8u: goto label_80134EF8;
    case 0x80134EFCu: goto label_80134EFC;
    case 0x80134F00u: goto label_80134F00;
    case 0x80134F04u: goto label_80134F04;
    case 0x80134F08u: goto label_80134F08;
    case 0x80134F0Cu: goto label_80134F0C;
    case 0x80134F10u: goto label_80134F10;
    case 0x80134F14u: goto label_80134F14;
    case 0x80134F18u: goto label_80134F18;
    case 0x80134F1Cu: goto label_80134F1C;
    case 0x80134F20u: goto label_80134F20;
    case 0x80134F24u: goto label_80134F24;
    case 0x80134F28u: goto label_80134F28;
    case 0x80134F2Cu: goto label_80134F2C;
    case 0x80134F30u: goto label_80134F30;
    case 0x80134F34u: goto label_80134F34;
    case 0x80134F38u: goto label_80134F38;
    case 0x80134F3Cu: goto label_80134F3C;
    case 0x80134F40u: goto label_80134F40;
    case 0x80134F44u: goto label_80134F44;
    case 0x80134F48u: goto label_80134F48;
    case 0x80134F4Cu: goto label_80134F4C;
    case 0x80134F50u: goto label_80134F50;
    case 0x80134F54u: goto label_80134F54;
    case 0x80134F58u: goto label_80134F58;
    case 0x80134F5Cu: goto label_80134F5C;
    case 0x80134F60u: goto label_80134F60;
    case 0x80134F64u: goto label_80134F64;
    case 0x80134F68u: goto label_80134F68;
    case 0x80134F6Cu: goto label_80134F6C;
    case 0x80134F70u: goto label_80134F70;
    case 0x80134F74u: goto label_80134F74;
    case 0x80134F78u: goto label_80134F78;
    case 0x80134F7Cu: goto label_80134F7C;
    case 0x80134F80u: goto label_80134F80;
    case 0x80134F84u: goto label_80134F84;
    case 0x80134F88u: goto label_80134F88;
    case 0x80134F8Cu: goto label_80134F8C;
    case 0x80134F90u: goto label_80134F90;
    case 0x80134F94u: goto label_80134F94;
    case 0x80134F98u: goto label_80134F98;
    case 0x80134F9Cu: goto label_80134F9C;
    case 0x80134FA0u: goto label_80134FA0;
    case 0x80134FA4u: goto label_80134FA4;
    case 0x80134FA8u: goto label_80134FA8;
    case 0x80134FACu: goto label_80134FAC;
    case 0x80134FB0u: goto label_80134FB0;
    case 0x80134FB4u: goto label_80134FB4;
    case 0x80134FB8u: goto label_80134FB8;
    case 0x80134FBCu: goto label_80134FBC;
    case 0x80134FC0u: goto label_80134FC0;
    case 0x80134FC4u: goto label_80134FC4;
    case 0x80134FC8u: goto label_80134FC8;
    case 0x80134FCCu: goto label_80134FCC;
    case 0x80134FD0u: goto label_80134FD0;
    case 0x80134FD4u: goto label_80134FD4;
    case 0x80134FD8u: goto label_80134FD8;
    case 0x80134FDCu: goto label_80134FDC;
    case 0x80134FE0u: goto label_80134FE0;
    case 0x80134FE4u: goto label_80134FE4;
    case 0x80134FE8u: goto label_80134FE8;
    case 0x80134FECu: goto label_80134FEC;
    case 0x80134FF0u: goto label_80134FF0;
    case 0x80134FF4u: goto label_80134FF4;
    case 0x80134FF8u: goto label_80134FF8;
    case 0x80134FFCu: goto label_80134FFC;
    case 0x80135000u: goto label_80135000;
    case 0x80135004u: goto label_80135004;
    case 0x80135008u: goto label_80135008;
    case 0x8013500Cu: goto label_8013500C;
    case 0x80135010u: goto label_80135010;
    case 0x80135014u: goto label_80135014;
    case 0x80135018u: goto label_80135018;
    case 0x8013501Cu: goto label_8013501C;
    case 0x80135020u: goto label_80135020;
    case 0x80135024u: goto label_80135024;
    case 0x80135028u: goto label_80135028;
    case 0x8013502Cu: goto label_8013502C;
    case 0x80135030u: goto label_80135030;
    case 0x80135034u: goto label_80135034;
    case 0x80135038u: goto label_80135038;
    case 0x8013503Cu: goto label_8013503C;
    case 0x80135040u: goto label_80135040;
    case 0x80135044u: goto label_80135044;
    case 0x80135048u: goto label_80135048;
    case 0x8013504Cu: goto label_8013504C;
    case 0x80135050u: goto label_80135050;
    case 0x80135054u: goto label_80135054;
    case 0x80135058u: goto label_80135058;
    case 0x8013505Cu: goto label_8013505C;
    case 0x80135060u: goto label_80135060;
    case 0x80135064u: goto label_80135064;
    case 0x80135068u: goto label_80135068;
    case 0x8013506Cu: goto label_8013506C;
    case 0x80135070u: goto label_80135070;
    case 0x80135074u: goto label_80135074;
    case 0x80135078u: goto label_80135078;
    case 0x8013507Cu: goto label_8013507C;
    case 0x80135080u: goto label_80135080;
    case 0x80135084u: goto label_80135084;
    case 0x80135088u: goto label_80135088;
    case 0x8013508Cu: goto label_8013508C;
    case 0x80135090u: goto label_80135090;
    case 0x80135094u: goto label_80135094;
    case 0x80135098u: goto label_80135098;
    case 0x8013509Cu: goto label_8013509C;
    case 0x801350A0u: goto label_801350A0;
    case 0x801350A4u: goto label_801350A4;
    case 0x801350A8u: goto label_801350A8;
    case 0x801350ACu: goto label_801350AC;
    case 0x801350B0u: goto label_801350B0;
    case 0x801350B4u: goto label_801350B4;
    case 0x801350B8u: goto label_801350B8;
    case 0x801350BCu: goto label_801350BC;
    case 0x801350C0u: goto label_801350C0;
    case 0x801350C4u: goto label_801350C4;
    case 0x801350C8u: goto label_801350C8;
    case 0x801350CCu: goto label_801350CC;
    case 0x801350D0u: goto label_801350D0;
    case 0x801350D4u: goto label_801350D4;
    case 0x801350D8u: goto label_801350D8;
    case 0x801350DCu: goto label_801350DC;
    case 0x801350E0u: goto label_801350E0;
    case 0x801350E4u: goto label_801350E4;
    case 0x801350E8u: goto label_801350E8;
    case 0x801350ECu: goto label_801350EC;
    case 0x801350F0u: goto label_801350F0;
    case 0x801350F4u: goto label_801350F4;
    case 0x801350F8u: goto label_801350F8;
    case 0x801350FCu: goto label_801350FC;
    case 0x80135100u: goto label_80135100;
    case 0x80135104u: goto label_80135104;
    case 0x80135108u: goto label_80135108;
    case 0x8013510Cu: goto label_8013510C;
    case 0x80135110u: goto label_80135110;
    case 0x80135114u: goto label_80135114;
    case 0x80135118u: goto label_80135118;
    case 0x8013511Cu: goto label_8013511C;
    case 0x80135120u: goto label_80135120;
    case 0x80135124u: goto label_80135124;
    case 0x80135128u: goto label_80135128;
    case 0x8013512Cu: goto label_8013512C;
    case 0x80135130u: goto label_80135130;
    case 0x80135134u: goto label_80135134;
    case 0x80135138u: goto label_80135138;
    case 0x8013513Cu: goto label_8013513C;
    case 0x80135140u: goto label_80135140;
    case 0x80135144u: goto label_80135144;
    case 0x80135148u: goto label_80135148;
    case 0x8013514Cu: goto label_8013514C;
    case 0x80135150u: goto label_80135150;
    case 0x80135154u: goto label_80135154;
    case 0x80135158u: goto label_80135158;
    case 0x8013515Cu: goto label_8013515C;
    case 0x80135160u: goto label_80135160;
    case 0x80135164u: goto label_80135164;
    case 0x80135168u: goto label_80135168;
    case 0x8013516Cu: goto label_8013516C;
    case 0x80135170u: goto label_80135170;
    case 0x80135174u: goto label_80135174;
    case 0x80135178u: goto label_80135178;
    case 0x8013517Cu: goto label_8013517C;
    case 0x80135180u: goto label_80135180;
    case 0x80135184u: goto label_80135184;
    case 0x80135188u: goto label_80135188;
    case 0x8013518Cu: goto label_8013518C;
    case 0x80135190u: goto label_80135190;
    case 0x80135194u: goto label_80135194;
    case 0x80135198u: goto label_80135198;
    case 0x8013519Cu: goto label_8013519C;
    case 0x801351A0u: goto label_801351A0;
    case 0x801351A4u: goto label_801351A4;
    case 0x801351A8u: goto label_801351A8;
    case 0x801351ACu: goto label_801351AC;
    case 0x801351B0u: goto label_801351B0;
    case 0x801351B4u: goto label_801351B4;
    case 0x801351B8u: goto label_801351B8;
    case 0x801351BCu: goto label_801351BC;
    case 0x801351C0u: goto label_801351C0;
    case 0x801351C4u: goto label_801351C4;
    case 0x801351C8u: goto label_801351C8;
    case 0x801351CCu: goto label_801351CC;
    case 0x801351D0u: goto label_801351D0;
    case 0x801351D4u: goto label_801351D4;
    case 0x801351D8u: goto label_801351D8;
    case 0x801351DCu: goto label_801351DC;
    case 0x801351E0u: goto label_801351E0;
    case 0x801351E4u: goto label_801351E4;
    case 0x801351E8u: goto label_801351E8;
    case 0x801351ECu: goto label_801351EC;
    case 0x801351F0u: goto label_801351F0;
    case 0x801351F4u: goto label_801351F4;
    case 0x801351F8u: goto label_801351F8;
    case 0x801351FCu: goto label_801351FC;
    case 0x80135200u: goto label_80135200;
    case 0x80135204u: goto label_80135204;
    case 0x80135208u: goto label_80135208;
    case 0x8013520Cu: goto label_8013520C;
    case 0x80135210u: goto label_80135210;
    case 0x80135214u: goto label_80135214;
    case 0x80135218u: goto label_80135218;
    case 0x8013521Cu: goto label_8013521C;
    case 0x80135220u: goto label_80135220;
    case 0x80135224u: goto label_80135224;
    case 0x80135228u: goto label_80135228;
    case 0x8013522Cu: goto label_8013522C;
    case 0x80135230u: goto label_80135230;
    case 0x80135234u: goto label_80135234;
    case 0x80135238u: goto label_80135238;
    case 0x8013523Cu: goto label_8013523C;
    case 0x80135240u: goto label_80135240;
    case 0x80135244u: goto label_80135244;
    case 0x80135248u: goto label_80135248;
    case 0x8013524Cu: goto label_8013524C;
    case 0x80135250u: goto label_80135250;
    case 0x80135254u: goto label_80135254;
    case 0x80135258u: goto label_80135258;
    case 0x8013525Cu: goto label_8013525C;
    case 0x80135260u: goto label_80135260;
    case 0x80135264u: goto label_80135264;
    case 0x80135268u: goto label_80135268;
    case 0x8013526Cu: goto label_8013526C;
    case 0x80135270u: goto label_80135270;
    case 0x80135274u: goto label_80135274;
    case 0x80135278u: goto label_80135278;
    case 0x8013527Cu: goto label_8013527C;
    case 0x80135280u: goto label_80135280;
    case 0x80135284u: goto label_80135284;
    case 0x80135288u: goto label_80135288;
    case 0x8013528Cu: goto label_8013528C;
    case 0x80135290u: goto label_80135290;
    case 0x80135294u: goto label_80135294;
    case 0x80135298u: goto label_80135298;
    case 0x8013529Cu: goto label_8013529C;
    case 0x801352A0u: goto label_801352A0;
    case 0x801352A4u: goto label_801352A4;
    case 0x801352A8u: goto label_801352A8;
    case 0x801352ACu: goto label_801352AC;
    case 0x801352B0u: goto label_801352B0;
    case 0x801352B4u: goto label_801352B4;
    case 0x801352B8u: goto label_801352B8;
    case 0x801352BCu: goto label_801352BC;
    case 0x801352C0u: goto label_801352C0;
    case 0x801352C4u: goto label_801352C4;
    case 0x801352C8u: goto label_801352C8;
    case 0x801352CCu: goto label_801352CC;
    case 0x801352D0u: goto label_801352D0;
    case 0x801352D4u: goto label_801352D4;
    case 0x801352D8u: goto label_801352D8;
    case 0x801352DCu: goto label_801352DC;
    case 0x801352E0u: goto label_801352E0;
    case 0x801352E4u: goto label_801352E4;
    case 0x801352E8u: goto label_801352E8;
    case 0x801352ECu: goto label_801352EC;
    case 0x801352F0u: goto label_801352F0;
    case 0x801352F4u: goto label_801352F4;
    case 0x801352F8u: goto label_801352F8;
    case 0x801352FCu: goto label_801352FC;
    case 0x80135300u: goto label_80135300;
    case 0x80135304u: goto label_80135304;
    case 0x80135308u: goto label_80135308;
    case 0x8013530Cu: goto label_8013530C;
    case 0x80135310u: goto label_80135310;
    case 0x80135314u: goto label_80135314;
    case 0x80135318u: goto label_80135318;
    case 0x8013531Cu: goto label_8013531C;
    case 0x80135320u: goto label_80135320;
    case 0x80135324u: goto label_80135324;
    case 0x80135328u: goto label_80135328;
    case 0x8013532Cu: goto label_8013532C;
    case 0x80135330u: goto label_80135330;
    case 0x80135334u: goto label_80135334;
    case 0x80135338u: goto label_80135338;
    case 0x8013533Cu: goto label_8013533C;
    case 0x80135340u: goto label_80135340;
    case 0x80135344u: goto label_80135344;
    case 0x80135348u: goto label_80135348;
    case 0x8013534Cu: goto label_8013534C;
    case 0x80135350u: goto label_80135350;
    case 0x80135354u: goto label_80135354;
    case 0x80135358u: goto label_80135358;
    case 0x8013535Cu: goto label_8013535C;
    case 0x80135360u: goto label_80135360;
    case 0x80135364u: goto label_80135364;
    case 0x80135368u: goto label_80135368;
    case 0x8013536Cu: goto label_8013536C;
    case 0x80135370u: goto label_80135370;
    case 0x80135374u: goto label_80135374;
    case 0x80135378u: goto label_80135378;
    case 0x8013537Cu: goto label_8013537C;
    case 0x80135380u: goto label_80135380;
    case 0x80135384u: goto label_80135384;
    case 0x80135388u: goto label_80135388;
    case 0x8013538Cu: goto label_8013538C;
    case 0x80135390u: goto label_80135390;
    case 0x80135394u: goto label_80135394;
    case 0x80135398u: goto label_80135398;
    case 0x8013539Cu: goto label_8013539C;
    case 0x801353A0u: goto label_801353A0;
    case 0x801353A4u: goto label_801353A4;
    case 0x801353A8u: goto label_801353A8;
    case 0x801353ACu: goto label_801353AC;
    case 0x801353B0u: goto label_801353B0;
    case 0x801353B4u: goto label_801353B4;
    case 0x801353B8u: goto label_801353B8;
    case 0x801353BCu: goto label_801353BC;
    case 0x801353C0u: goto label_801353C0;
    case 0x801353C4u: goto label_801353C4;
    case 0x801353C8u: goto label_801353C8;
    case 0x801353CCu: goto label_801353CC;
    case 0x801353D0u: goto label_801353D0;
    case 0x801353D4u: goto label_801353D4;
    case 0x801353D8u: goto label_801353D8;
    case 0x801353DCu: goto label_801353DC;
    case 0x801353E0u: goto label_801353E0;
    case 0x801353E4u: goto label_801353E4;
    case 0x801353E8u: goto label_801353E8;
    case 0x801353ECu: goto label_801353EC;
    case 0x801353F0u: goto label_801353F0;
    case 0x801353F4u: goto label_801353F4;
    case 0x801353F8u: goto label_801353F8;
    case 0x801353FCu: goto label_801353FC;
    case 0x80135400u: goto label_80135400;
    case 0x80135404u: goto label_80135404;
    case 0x80135408u: goto label_80135408;
    case 0x8013540Cu: goto label_8013540C;
    case 0x80135410u: goto label_80135410;
    case 0x80135414u: goto label_80135414;
    case 0x80135418u: goto label_80135418;
    case 0x8013541Cu: goto label_8013541C;
    case 0x80135420u: goto label_80135420;
    case 0x80135424u: goto label_80135424;
    case 0x80135428u: goto label_80135428;
    case 0x8013542Cu: goto label_8013542C;
    case 0x80135430u: goto label_80135430;
    case 0x80135434u: goto label_80135434;
    case 0x80135438u: goto label_80135438;
    case 0x8013543Cu: goto label_8013543C;
    case 0x80135440u: goto label_80135440;
    case 0x80135444u: goto label_80135444;
    case 0x80135448u: goto label_80135448;
    case 0x8013544Cu: goto label_8013544C;
    case 0x80135450u: goto label_80135450;
    case 0x80135454u: goto label_80135454;
    case 0x80135458u: goto label_80135458;
    case 0x8013545Cu: goto label_8013545C;
    case 0x80135460u: goto label_80135460;
    case 0x80135464u: goto label_80135464;
    case 0x80135468u: goto label_80135468;
    case 0x8013546Cu: goto label_8013546C;
    case 0x80135470u: goto label_80135470;
    case 0x80135474u: goto label_80135474;
    case 0x80135478u: goto label_80135478;
    case 0x8013547Cu: goto label_8013547C;
    case 0x80135480u: goto label_80135480;
    case 0x80135484u: goto label_80135484;
    case 0x80135488u: goto label_80135488;
    case 0x8013548Cu: goto label_8013548C;
    case 0x80135490u: goto label_80135490;
    case 0x80135494u: goto label_80135494;
    case 0x80135498u: goto label_80135498;
    case 0x8013549Cu: goto label_8013549C;
    case 0x801354A0u: goto label_801354A0;
    case 0x801354A4u: goto label_801354A4;
    case 0x801354A8u: goto label_801354A8;
    case 0x801354ACu: goto label_801354AC;
    case 0x801354B0u: goto label_801354B0;
    case 0x801354B4u: goto label_801354B4;
    case 0x801354B8u: goto label_801354B8;
    case 0x801354BCu: goto label_801354BC;
    case 0x801354C0u: goto label_801354C0;
    case 0x801354C4u: goto label_801354C4;
    case 0x801354C8u: goto label_801354C8;
    case 0x801354CCu: goto label_801354CC;
    case 0x801354D0u: goto label_801354D0;
    case 0x801354D4u: goto label_801354D4;
    case 0x801354D8u: goto label_801354D8;
    case 0x801354DCu: goto label_801354DC;
    case 0x801354E0u: goto label_801354E0;
    case 0x801354E4u: goto label_801354E4;
    case 0x801354E8u: goto label_801354E8;
    case 0x801354ECu: goto label_801354EC;
    case 0x801354F0u: goto label_801354F0;
    case 0x801354F4u: goto label_801354F4;
    case 0x801354F8u: goto label_801354F8;
    case 0x801354FCu: goto label_801354FC;
    case 0x80135500u: goto label_80135500;
    case 0x80135504u: goto label_80135504;
    case 0x80135508u: goto label_80135508;
    case 0x8013550Cu: goto label_8013550C;
    case 0x80135510u: goto label_80135510;
    case 0x80135514u: goto label_80135514;
    case 0x80135518u: goto label_80135518;
    case 0x8013551Cu: goto label_8013551C;
    case 0x80135520u: goto label_80135520;
    case 0x80135524u: goto label_80135524;
    case 0x80135528u: goto label_80135528;
    case 0x8013552Cu: goto label_8013552C;
    case 0x80135530u: goto label_80135530;
    case 0x80135534u: goto label_80135534;
    case 0x80135538u: goto label_80135538;
    case 0x8013553Cu: goto label_8013553C;
    case 0x80135540u: goto label_80135540;
    case 0x80135544u: goto label_80135544;
    case 0x80135548u: goto label_80135548;
    case 0x8013554Cu: goto label_8013554C;
    case 0x80135550u: goto label_80135550;
    case 0x80135554u: goto label_80135554;
    case 0x80135558u: goto label_80135558;
    case 0x8013555Cu: goto label_8013555C;
    case 0x80135560u: goto label_80135560;
    case 0x80135564u: goto label_80135564;
    case 0x80135568u: goto label_80135568;
    case 0x8013556Cu: goto label_8013556C;
    case 0x80135570u: goto label_80135570;
    case 0x80135574u: goto label_80135574;
    case 0x80135578u: goto label_80135578;
    case 0x8013557Cu: goto label_8013557C;
    case 0x80135580u: goto label_80135580;
    case 0x80135584u: goto label_80135584;
    case 0x80135588u: goto label_80135588;
    case 0x8013558Cu: goto label_8013558C;
    case 0x80135590u: goto label_80135590;
    case 0x80135594u: goto label_80135594;
    case 0x80135598u: goto label_80135598;
    case 0x8013559Cu: goto label_8013559C;
    case 0x801355A0u: goto label_801355A0;
    case 0x801355A4u: goto label_801355A4;
    case 0x801355A8u: goto label_801355A8;
    case 0x801355ACu: goto label_801355AC;
    case 0x801355B0u: goto label_801355B0;
    case 0x801355B4u: goto label_801355B4;
    case 0x801355B8u: goto label_801355B8;
    case 0x801355BCu: goto label_801355BC;
    case 0x801355C0u: goto label_801355C0;
    case 0x801355C4u: goto label_801355C4;
    case 0x801355C8u: goto label_801355C8;
    case 0x801355CCu: goto label_801355CC;
    case 0x801355D0u: goto label_801355D0;
    case 0x801355D4u: goto label_801355D4;
    case 0x801355D8u: goto label_801355D8;
    case 0x801355DCu: goto label_801355DC;
    case 0x801355E0u: goto label_801355E0;
    case 0x801355E4u: goto label_801355E4;
    case 0x801355E8u: goto label_801355E8;
    case 0x801355ECu: goto label_801355EC;
    case 0x801355F0u: goto label_801355F0;
    case 0x801355F4u: goto label_801355F4;
    case 0x801355F8u: goto label_801355F8;
    case 0x801355FCu: goto label_801355FC;
    case 0x80135600u: goto label_80135600;
    case 0x80135604u: goto label_80135604;
    case 0x80135608u: goto label_80135608;
    case 0x8013560Cu: goto label_8013560C;
    case 0x80135610u: goto label_80135610;
    case 0x80135614u: goto label_80135614;
    case 0x80135618u: goto label_80135618;
    case 0x8013561Cu: goto label_8013561C;
    case 0x80135620u: goto label_80135620;
    case 0x80135624u: goto label_80135624;
    case 0x80135628u: goto label_80135628;
    case 0x8013562Cu: goto label_8013562C;
    case 0x80135630u: goto label_80135630;
    case 0x80135634u: goto label_80135634;
    case 0x80135638u: goto label_80135638;
    case 0x8013563Cu: goto label_8013563C;
    case 0x80135640u: goto label_80135640;
    case 0x80135644u: goto label_80135644;
    case 0x80135648u: goto label_80135648;
    case 0x8013564Cu: goto label_8013564C;
    case 0x80135650u: goto label_80135650;
    case 0x80135654u: goto label_80135654;
    case 0x80135658u: goto label_80135658;
    case 0x8013565Cu: goto label_8013565C;
    case 0x80135660u: goto label_80135660;
    case 0x80135664u: goto label_80135664;
    case 0x80135668u: goto label_80135668;
    case 0x8013566Cu: goto label_8013566C;
    case 0x80135670u: goto label_80135670;
    case 0x80135674u: goto label_80135674;
    case 0x80135678u: goto label_80135678;
    case 0x8013567Cu: goto label_8013567C;
    case 0x80135680u: goto label_80135680;
    case 0x80135684u: goto label_80135684;
    case 0x80135688u: goto label_80135688;
    case 0x8013568Cu: goto label_8013568C;
    case 0x80135690u: goto label_80135690;
    case 0x80135694u: goto label_80135694;
    case 0x80135698u: goto label_80135698;
    case 0x8013569Cu: goto label_8013569C;
    case 0x801356A0u: goto label_801356A0;
    case 0x801356A4u: goto label_801356A4;
    case 0x801356A8u: goto label_801356A8;
    case 0x801356ACu: goto label_801356AC;
    case 0x801356B0u: goto label_801356B0;
    case 0x801356B4u: goto label_801356B4;
    case 0x801356B8u: goto label_801356B8;
    case 0x801356BCu: goto label_801356BC;
    case 0x801356C0u: goto label_801356C0;
    case 0x801356C4u: goto label_801356C4;
    case 0x801356C8u: goto label_801356C8;
    case 0x801356CCu: goto label_801356CC;
    case 0x801356D0u: goto label_801356D0;
    case 0x801356D4u: goto label_801356D4;
    case 0x801356D8u: goto label_801356D8;
    case 0x801356DCu: goto label_801356DC;
    case 0x801356E0u: goto label_801356E0;
    case 0x801356E4u: goto label_801356E4;
    case 0x801356E8u: goto label_801356E8;
    case 0x801356ECu: goto label_801356EC;
    case 0x801356F0u: goto label_801356F0;
    case 0x801356F4u: goto label_801356F4;
    case 0x801356F8u: goto label_801356F8;
    case 0x801356FCu: goto label_801356FC;
    case 0x80135700u: goto label_80135700;
    case 0x80135704u: goto label_80135704;
    case 0x80135708u: goto label_80135708;
    case 0x8013570Cu: goto label_8013570C;
    case 0x80135710u: goto label_80135710;
    case 0x80135714u: goto label_80135714;
    case 0x80135718u: goto label_80135718;
    case 0x8013571Cu: goto label_8013571C;
    case 0x80135720u: goto label_80135720;
    case 0x80135724u: goto label_80135724;
    case 0x80135728u: goto label_80135728;
    case 0x8013572Cu: goto label_8013572C;
    case 0x80135730u: goto label_80135730;
    case 0x80135734u: goto label_80135734;
    case 0x80135738u: goto label_80135738;
    case 0x8013573Cu: goto label_8013573C;
    case 0x80135740u: goto label_80135740;
    case 0x80135744u: goto label_80135744;
    case 0x80135748u: goto label_80135748;
    case 0x8013574Cu: goto label_8013574C;
    case 0x80135750u: goto label_80135750;
    case 0x80135754u: goto label_80135754;
    case 0x80135758u: goto label_80135758;
    case 0x8013575Cu: goto label_8013575C;
    case 0x80135760u: goto label_80135760;
    case 0x80135764u: goto label_80135764;
    case 0x80135768u: goto label_80135768;
    case 0x8013576Cu: goto label_8013576C;
    case 0x80135770u: goto label_80135770;
    case 0x80135774u: goto label_80135774;
    case 0x80135778u: goto label_80135778;
    case 0x8013577Cu: goto label_8013577C;
    case 0x80135780u: goto label_80135780;
    case 0x80135784u: goto label_80135784;
    case 0x80135788u: goto label_80135788;
    case 0x8013578Cu: goto label_8013578C;
    case 0x80135790u: goto label_80135790;
    case 0x80135794u: goto label_80135794;
    case 0x80135798u: goto label_80135798;
    case 0x8013579Cu: goto label_8013579C;
    case 0x801357A0u: goto label_801357A0;
    case 0x801357A4u: goto label_801357A4;
    case 0x801357A8u: goto label_801357A8;
    case 0x801357ACu: goto label_801357AC;
    case 0x801357B0u: goto label_801357B0;
    case 0x801357B4u: goto label_801357B4;
    case 0x801357B8u: goto label_801357B8;
    case 0x801357BCu: goto label_801357BC;
    case 0x801357C0u: goto label_801357C0;
    case 0x801357C4u: goto label_801357C4;
    case 0x801357C8u: goto label_801357C8;
    case 0x801357CCu: goto label_801357CC;
    case 0x801357D0u: goto label_801357D0;
    case 0x801357D4u: goto label_801357D4;
    case 0x801357D8u: goto label_801357D8;
    case 0x801357DCu: goto label_801357DC;
    case 0x801357E0u: goto label_801357E0;
    case 0x801357E4u: goto label_801357E4;
    case 0x801357E8u: goto label_801357E8;
    case 0x801357ECu: goto label_801357EC;
    case 0x801357F0u: goto label_801357F0;
    case 0x801357F4u: goto label_801357F4;
    case 0x801357F8u: goto label_801357F8;
    case 0x801357FCu: goto label_801357FC;
    case 0x80135800u: goto label_80135800;
    case 0x80135804u: goto label_80135804;
    case 0x80135808u: goto label_80135808;
    case 0x8013580Cu: goto label_8013580C;
    case 0x80135810u: goto label_80135810;
    case 0x80135814u: goto label_80135814;
    case 0x80135818u: goto label_80135818;
    case 0x8013581Cu: goto label_8013581C;
    case 0x80135820u: goto label_80135820;
    case 0x80135824u: goto label_80135824;
    case 0x80135828u: goto label_80135828;
    case 0x8013582Cu: goto label_8013582C;
    case 0x80135830u: goto label_80135830;
    case 0x80135834u: goto label_80135834;
    case 0x80135838u: goto label_80135838;
    case 0x8013583Cu: goto label_8013583C;
    case 0x80135840u: goto label_80135840;
    case 0x80135844u: goto label_80135844;
    case 0x80135848u: goto label_80135848;
    case 0x8013584Cu: goto label_8013584C;
    case 0x80135850u: goto label_80135850;
    case 0x80135854u: goto label_80135854;
    case 0x80135858u: goto label_80135858;
    case 0x8013585Cu: goto label_8013585C;
    case 0x80135860u: goto label_80135860;
    case 0x80135864u: goto label_80135864;
    case 0x80135868u: goto label_80135868;
    case 0x8013586Cu: goto label_8013586C;
    case 0x80135870u: goto label_80135870;
    case 0x80135874u: goto label_80135874;
    case 0x80135878u: goto label_80135878;
    case 0x8013587Cu: goto label_8013587C;
    case 0x80135880u: goto label_80135880;
    case 0x80135884u: goto label_80135884;
    case 0x80135888u: goto label_80135888;
    case 0x8013588Cu: goto label_8013588C;
    case 0x80135890u: goto label_80135890;
    case 0x80135894u: goto label_80135894;
    case 0x80135898u: goto label_80135898;
    case 0x8013589Cu: goto label_8013589C;
    case 0x801358A0u: goto label_801358A0;
    case 0x801358A4u: goto label_801358A4;
    case 0x801358A8u: goto label_801358A8;
    case 0x801358ACu: goto label_801358AC;
    case 0x801358B0u: goto label_801358B0;
    case 0x801358B4u: goto label_801358B4;
    case 0x801358B8u: goto label_801358B8;
    case 0x801358BCu: goto label_801358BC;
    case 0x801358C0u: goto label_801358C0;
    case 0x801358C4u: goto label_801358C4;
    case 0x801358C8u: goto label_801358C8;
    case 0x801358CCu: goto label_801358CC;
    case 0x801358D0u: goto label_801358D0;
    case 0x801358D4u: goto label_801358D4;
    case 0x801358D8u: goto label_801358D8;
    case 0x801358DCu: goto label_801358DC;
    case 0x801358E0u: goto label_801358E0;
    case 0x801358E4u: goto label_801358E4;
    case 0x801358E8u: goto label_801358E8;
    case 0x801358ECu: goto label_801358EC;
    case 0x801358F0u: goto label_801358F0;
    case 0x801358F4u: goto label_801358F4;
    case 0x801358F8u: goto label_801358F8;
    case 0x801358FCu: goto label_801358FC;
    case 0x80135900u: goto label_80135900;
    case 0x80135904u: goto label_80135904;
    case 0x80135908u: goto label_80135908;
    case 0x8013590Cu: goto label_8013590C;
    case 0x80135910u: goto label_80135910;
    case 0x80135914u: goto label_80135914;
    case 0x80135918u: goto label_80135918;
    case 0x8013591Cu: goto label_8013591C;
    case 0x80135920u: goto label_80135920;
    case 0x80135924u: goto label_80135924;
    case 0x80135928u: goto label_80135928;
    case 0x8013592Cu: goto label_8013592C;
    case 0x80135930u: goto label_80135930;
    case 0x80135934u: goto label_80135934;
    case 0x80135938u: goto label_80135938;
    case 0x8013593Cu: goto label_8013593C;
    case 0x80135940u: goto label_80135940;
    case 0x80135944u: goto label_80135944;
    case 0x80135948u: goto label_80135948;
    case 0x8013594Cu: goto label_8013594C;
    case 0x80135950u: goto label_80135950;
    case 0x80135954u: goto label_80135954;
    case 0x80135958u: goto label_80135958;
    case 0x8013595Cu: goto label_8013595C;
    case 0x80135960u: goto label_80135960;
    case 0x80135964u: goto label_80135964;
    case 0x80135968u: goto label_80135968;
    case 0x8013596Cu: goto label_8013596C;
    case 0x80135970u: goto label_80135970;
    case 0x80135974u: goto label_80135974;
    case 0x80135978u: goto label_80135978;
    case 0x8013597Cu: goto label_8013597C;
    case 0x80135980u: goto label_80135980;
    case 0x80135984u: goto label_80135984;
    case 0x80135988u: goto label_80135988;
    case 0x8013598Cu: goto label_8013598C;
    case 0x80135990u: goto label_80135990;
    case 0x80135994u: goto label_80135994;
    case 0x80135998u: goto label_80135998;
    case 0x8013599Cu: goto label_8013599C;
    case 0x801359A0u: goto label_801359A0;
    case 0x801359A4u: goto label_801359A4;
    case 0x801359A8u: goto label_801359A8;
    case 0x801359ACu: goto label_801359AC;
    case 0x801359B0u: goto label_801359B0;
    case 0x801359B4u: goto label_801359B4;
    case 0x801359B8u: goto label_801359B8;
    case 0x801359BCu: goto label_801359BC;
    case 0x801359C0u: goto label_801359C0;
    case 0x801359C4u: goto label_801359C4;
    case 0x801359C8u: goto label_801359C8;
    case 0x801359CCu: goto label_801359CC;
    case 0x801359D0u: goto label_801359D0;
    case 0x801359D4u: goto label_801359D4;
    case 0x801359D8u: goto label_801359D8;
    case 0x801359DCu: goto label_801359DC;
    case 0x801359E0u: goto label_801359E0;
    case 0x801359E4u: goto label_801359E4;
    case 0x801359E8u: goto label_801359E8;
    case 0x801359ECu: goto label_801359EC;
    case 0x801359F0u: goto label_801359F0;
    case 0x801359F4u: goto label_801359F4;
    case 0x801359F8u: goto label_801359F8;
    case 0x801359FCu: goto label_801359FC;
    case 0x80135A00u: goto label_80135A00;
    case 0x80135A04u: goto label_80135A04;
    case 0x80135A08u: goto label_80135A08;
    case 0x80135A0Cu: goto label_80135A0C;
    case 0x80135A10u: goto label_80135A10;
    case 0x80135A14u: goto label_80135A14;
    case 0x80135A18u: goto label_80135A18;
    case 0x80135A1Cu: goto label_80135A1C;
    case 0x80135A20u: goto label_80135A20;
    case 0x80135A24u: goto label_80135A24;
    case 0x80135A28u: goto label_80135A28;
    case 0x80135A2Cu: goto label_80135A2C;
    case 0x80135A30u: goto label_80135A30;
    case 0x80135A34u: goto label_80135A34;
    case 0x80135A38u: goto label_80135A38;
    case 0x80135A3Cu: goto label_80135A3C;
    case 0x80135A40u: goto label_80135A40;
    case 0x80135A44u: goto label_80135A44;
    case 0x80135A48u: goto label_80135A48;
    case 0x80135A4Cu: goto label_80135A4C;
    case 0x80135A50u: goto label_80135A50;
    case 0x80135A54u: goto label_80135A54;
    case 0x80135A58u: goto label_80135A58;
    case 0x80135A5Cu: goto label_80135A5C;
    case 0x80135A60u: goto label_80135A60;
    case 0x80135A64u: goto label_80135A64;
    case 0x80135A68u: goto label_80135A68;
    case 0x80135A6Cu: goto label_80135A6C;
    case 0x80135A70u: goto label_80135A70;
    case 0x80135A74u: goto label_80135A74;
    case 0x80135A78u: goto label_80135A78;
    case 0x80135A7Cu: goto label_80135A7C;
    case 0x80135A80u: goto label_80135A80;
    case 0x80135A84u: goto label_80135A84;
    case 0x80135A88u: goto label_80135A88;
    case 0x80135A8Cu: goto label_80135A8C;
    case 0x80135A90u: goto label_80135A90;
    case 0x80135A94u: goto label_80135A94;
    case 0x80135A98u: goto label_80135A98;
    case 0x80135A9Cu: goto label_80135A9C;
    case 0x80135AA0u: goto label_80135AA0;
    case 0x80135AA4u: goto label_80135AA4;
    case 0x80135AA8u: goto label_80135AA8;
    case 0x80135AACu: goto label_80135AAC;
    case 0x80135AB0u: goto label_80135AB0;
    case 0x80135AB4u: goto label_80135AB4;
    case 0x80135AB8u: goto label_80135AB8;
    case 0x80135ABCu: goto label_80135ABC;
    case 0x80135AC0u: goto label_80135AC0;
    case 0x80135AC4u: goto label_80135AC4;
    case 0x80135AC8u: goto label_80135AC8;
    case 0x80135ACCu: goto label_80135ACC;
    case 0x80135AD0u: goto label_80135AD0;
    case 0x80135AD4u: goto label_80135AD4;
    case 0x80135AD8u: goto label_80135AD8;
    case 0x80135ADCu: goto label_80135ADC;
    case 0x80135AE0u: goto label_80135AE0;
    case 0x80135AE4u: goto label_80135AE4;
    case 0x80135AE8u: goto label_80135AE8;
    case 0x80135AECu: goto label_80135AEC;
    case 0x80135AF0u: goto label_80135AF0;
    case 0x80135AF4u: goto label_80135AF4;
    case 0x80135AF8u: goto label_80135AF8;
    case 0x80135AFCu: goto label_80135AFC;
    case 0x80135B00u: goto label_80135B00;
    case 0x80135B04u: goto label_80135B04;
    case 0x80135B08u: goto label_80135B08;
    case 0x80135B0Cu: goto label_80135B0C;
    case 0x80135B10u: goto label_80135B10;
    case 0x80135B14u: goto label_80135B14;
    case 0x80135B18u: goto label_80135B18;
    case 0x80135B1Cu: goto label_80135B1C;
    case 0x80135B20u: goto label_80135B20;
    case 0x80135B24u: goto label_80135B24;
    case 0x80135B28u: goto label_80135B28;
    case 0x80135B2Cu: goto label_80135B2C;
    case 0x80135B30u: goto label_80135B30;
    case 0x80135B34u: goto label_80135B34;
    case 0x80135B38u: goto label_80135B38;
    case 0x80135B3Cu: goto label_80135B3C;
    case 0x80135B40u: goto label_80135B40;
    case 0x80135B44u: goto label_80135B44;
    case 0x80135B48u: goto label_80135B48;
    case 0x80135B4Cu: goto label_80135B4C;
    case 0x80135B50u: goto label_80135B50;
    case 0x80135B54u: goto label_80135B54;
    case 0x80135B58u: goto label_80135B58;
    case 0x80135B5Cu: goto label_80135B5C;
    case 0x80135B60u: goto label_80135B60;
    case 0x80135B64u: goto label_80135B64;
    case 0x80135B68u: goto label_80135B68;
    case 0x80135B6Cu: goto label_80135B6C;
    case 0x80135B70u: goto label_80135B70;
    case 0x80135B74u: goto label_80135B74;
    case 0x80135B78u: goto label_80135B78;
    case 0x80135B7Cu: goto label_80135B7C;
    case 0x80135B80u: goto label_80135B80;
    case 0x80135B84u: goto label_80135B84;
    case 0x80135B88u: goto label_80135B88;
    case 0x80135B8Cu: goto label_80135B8C;
    case 0x80135B90u: goto label_80135B90;
    case 0x80135B94u: goto label_80135B94;
    case 0x80135B98u: goto label_80135B98;
    case 0x80135B9Cu: goto label_80135B9C;
    case 0x80135BA0u: goto label_80135BA0;
    case 0x80135BA4u: goto label_80135BA4;
    case 0x80135BA8u: goto label_80135BA8;
    case 0x80135BACu: goto label_80135BAC;
    case 0x80135BB0u: goto label_80135BB0;
    case 0x80135BB4u: goto label_80135BB4;
    case 0x80135BB8u: goto label_80135BB8;
    case 0x80135BBCu: goto label_80135BBC;
    case 0x80135BC0u: goto label_80135BC0;
    case 0x80135BC4u: goto label_80135BC4;
    case 0x80135BC8u: goto label_80135BC8;
    case 0x80135BCCu: goto label_80135BCC;
    case 0x80135BD0u: goto label_80135BD0;
    case 0x80135BD4u: goto label_80135BD4;
    case 0x80135BD8u: goto label_80135BD8;
    case 0x80135BDCu: goto label_80135BDC;
    case 0x80135BE0u: goto label_80135BE0;
    case 0x80135BE4u: goto label_80135BE4;
    case 0x80135BE8u: goto label_80135BE8;
    case 0x80135BECu: goto label_80135BEC;
    case 0x80135BF0u: goto label_80135BF0;
    case 0x80135BF4u: goto label_80135BF4;
    case 0x80135BF8u: goto label_80135BF8;
    case 0x80135BFCu: goto label_80135BFC;
    case 0x80135C00u: goto label_80135C00;
    case 0x80135C04u: goto label_80135C04;
    case 0x80135C08u: goto label_80135C08;
    case 0x80135C0Cu: goto label_80135C0C;
    case 0x80135C10u: goto label_80135C10;
    case 0x80135C14u: goto label_80135C14;
    case 0x80135C18u: goto label_80135C18;
    case 0x80135C1Cu: goto label_80135C1C;
    case 0x80135C20u: goto label_80135C20;
    case 0x80135C24u: goto label_80135C24;
    case 0x80135C28u: goto label_80135C28;
    case 0x80135C2Cu: goto label_80135C2C;
    case 0x80135C30u: goto label_80135C30;
    case 0x80135C34u: goto label_80135C34;
    case 0x80135C38u: goto label_80135C38;
    case 0x80135C3Cu: goto label_80135C3C;
    case 0x80135C40u: goto label_80135C40;
    case 0x80135C44u: goto label_80135C44;
    case 0x80135C48u: goto label_80135C48;
    case 0x80135C4Cu: goto label_80135C4C;
    case 0x80135C50u: goto label_80135C50;
    case 0x80135C54u: goto label_80135C54;
    case 0x80135C58u: goto label_80135C58;
    case 0x80135C5Cu: goto label_80135C5C;
    case 0x80135C60u: goto label_80135C60;
    case 0x80135C64u: goto label_80135C64;
    case 0x80135C68u: goto label_80135C68;
    case 0x80135C6Cu: goto label_80135C6C;
    case 0x80135C70u: goto label_80135C70;
    case 0x80135C74u: goto label_80135C74;
    case 0x80135C78u: goto label_80135C78;
    case 0x80135C7Cu: goto label_80135C7C;
    case 0x80135C80u: goto label_80135C80;
    case 0x80135C84u: goto label_80135C84;
    case 0x80135C88u: goto label_80135C88;
    case 0x80135C8Cu: goto label_80135C8C;
    case 0x80135C90u: goto label_80135C90;
    case 0x80135C94u: goto label_80135C94;
    case 0x80135C98u: goto label_80135C98;
    case 0x80135C9Cu: goto label_80135C9C;
    case 0x80135CA0u: goto label_80135CA0;
    case 0x80135CA4u: goto label_80135CA4;
    case 0x80135CA8u: goto label_80135CA8;
    case 0x80135CACu: goto label_80135CAC;
    case 0x80135CB0u: goto label_80135CB0;
    case 0x80135CB4u: goto label_80135CB4;
    case 0x80135CB8u: goto label_80135CB8;
    case 0x80135CBCu: goto label_80135CBC;
    case 0x80135CC0u: goto label_80135CC0;
    case 0x80135CC4u: goto label_80135CC4;
    case 0x80135CC8u: goto label_80135CC8;
    case 0x80135CCCu: goto label_80135CCC;
    case 0x80135CD0u: goto label_80135CD0;
    case 0x80135CD4u: goto label_80135CD4;
    case 0x80135CD8u: goto label_80135CD8;
    case 0x80135CDCu: goto label_80135CDC;
    case 0x80135CE0u: goto label_80135CE0;
    case 0x80135CE4u: goto label_80135CE4;
    case 0x80135CE8u: goto label_80135CE8;
    case 0x80135CECu: goto label_80135CEC;
    case 0x80135CF0u: goto label_80135CF0;
    case 0x80135CF4u: goto label_80135CF4;
    case 0x80135CF8u: goto label_80135CF8;
    case 0x80135CFCu: goto label_80135CFC;
    case 0x80135D00u: goto label_80135D00;
    case 0x80135D04u: goto label_80135D04;
    case 0x80135D08u: goto label_80135D08;
    case 0x80135D0Cu: goto label_80135D0C;
    case 0x80135D10u: goto label_80135D10;
    case 0x80135D14u: goto label_80135D14;
    case 0x80135D18u: goto label_80135D18;
    case 0x80135D1Cu: goto label_80135D1C;
    case 0x80135D20u: goto label_80135D20;
    case 0x80135D24u: goto label_80135D24;
    case 0x80135D28u: goto label_80135D28;
    case 0x80135D2Cu: goto label_80135D2C;
    case 0x80135D30u: goto label_80135D30;
    case 0x80135D34u: goto label_80135D34;
    case 0x80135D38u: goto label_80135D38;
    case 0x80135D3Cu: goto label_80135D3C;
    case 0x80135D40u: goto label_80135D40;
    case 0x80135D44u: goto label_80135D44;
    case 0x80135D48u: goto label_80135D48;
    case 0x80135D4Cu: goto label_80135D4C;
    case 0x80135D50u: goto label_80135D50;
    case 0x80135D54u: goto label_80135D54;
    case 0x80135D58u: goto label_80135D58;
    case 0x80135D5Cu: goto label_80135D5C;
    case 0x80135D60u: goto label_80135D60;
    case 0x80135D64u: goto label_80135D64;
    case 0x80135D68u: goto label_80135D68;
    case 0x80135D6Cu: goto label_80135D6C;
    case 0x80135D70u: goto label_80135D70;
    case 0x80135D74u: goto label_80135D74;
    case 0x80135D78u: goto label_80135D78;
    case 0x80135D7Cu: goto label_80135D7C;
    case 0x80135D80u: goto label_80135D80;
    case 0x80135D84u: goto label_80135D84;
    case 0x80135D88u: goto label_80135D88;
    case 0x80135D8Cu: goto label_80135D8C;
    case 0x80135D90u: goto label_80135D90;
    case 0x80135D94u: goto label_80135D94;
    case 0x80135D98u: goto label_80135D98;
    case 0x80135D9Cu: goto label_80135D9C;
    case 0x80135DA0u: goto label_80135DA0;
    case 0x80135DA4u: goto label_80135DA4;
    case 0x80135DA8u: goto label_80135DA8;
    case 0x80135DACu: goto label_80135DAC;
    case 0x80135DB0u: goto label_80135DB0;
    case 0x80135DB4u: goto label_80135DB4;
    case 0x80135DB8u: goto label_80135DB8;
    case 0x80135DBCu: goto label_80135DBC;
    case 0x80135DC0u: goto label_80135DC0;
    case 0x80135DC4u: goto label_80135DC4;
    case 0x80135DC8u: goto label_80135DC8;
    case 0x80135DCCu: goto label_80135DCC;
    case 0x80135DD0u: goto label_80135DD0;
    case 0x80135DD4u: goto label_80135DD4;
    case 0x80135DD8u: goto label_80135DD8;
    case 0x80135DDCu: goto label_80135DDC;
    case 0x80135DE0u: goto label_80135DE0;
    case 0x80135DE4u: goto label_80135DE4;
    case 0x80135DE8u: goto label_80135DE8;
    case 0x80135DECu: goto label_80135DEC;
    case 0x80135DF0u: goto label_80135DF0;
    case 0x80135DF4u: goto label_80135DF4;
    case 0x80135DF8u: goto label_80135DF8;
    case 0x80135DFCu: goto label_80135DFC;
    case 0x80135E00u: goto label_80135E00;
    case 0x80135E04u: goto label_80135E04;
    case 0x80135E08u: goto label_80135E08;
    case 0x80135E0Cu: goto label_80135E0C;
    case 0x80135E10u: goto label_80135E10;
    case 0x80135E14u: goto label_80135E14;
    case 0x80135E18u: goto label_80135E18;
    case 0x80135E1Cu: goto label_80135E1C;
    case 0x80135E20u: goto label_80135E20;
    case 0x80135E24u: goto label_80135E24;
    case 0x80135E28u: goto label_80135E28;
    case 0x80135E2Cu: goto label_80135E2C;
    case 0x80135E30u: goto label_80135E30;
    case 0x80135E34u: goto label_80135E34;
    case 0x80135E38u: goto label_80135E38;
    case 0x80135E3Cu: goto label_80135E3C;
    case 0x80135E40u: goto label_80135E40;
    case 0x80135E44u: goto label_80135E44;
    case 0x80135E48u: goto label_80135E48;
    case 0x80135E4Cu: goto label_80135E4C;
    case 0x80135E50u: goto label_80135E50;
    case 0x80135E54u: goto label_80135E54;
    case 0x80135E58u: goto label_80135E58;
    case 0x80135E5Cu: goto label_80135E5C;
    case 0x80135E60u: goto label_80135E60;
    case 0x80135E64u: goto label_80135E64;
    case 0x80135E68u: goto label_80135E68;
    case 0x80135E6Cu: goto label_80135E6C;
    case 0x80135E70u: goto label_80135E70;
    case 0x80135E74u: goto label_80135E74;
    case 0x80135E78u: goto label_80135E78;
    case 0x80135E7Cu: goto label_80135E7C;
    case 0x80135E80u: goto label_80135E80;
    case 0x80135E84u: goto label_80135E84;
    case 0x80135E88u: goto label_80135E88;
    case 0x80135E8Cu: goto label_80135E8C;
    case 0x80135E90u: goto label_80135E90;
    case 0x80135E94u: goto label_80135E94;
    case 0x80135E98u: goto label_80135E98;
    case 0x80135E9Cu: goto label_80135E9C;
    case 0x80135EA0u: goto label_80135EA0;
    case 0x80135EA4u: goto label_80135EA4;
    case 0x80135EA8u: goto label_80135EA8;
    case 0x80135EACu: goto label_80135EAC;
    case 0x80135EB0u: goto label_80135EB0;
    case 0x80135EB4u: goto label_80135EB4;
    case 0x80135EB8u: goto label_80135EB8;
    case 0x80135EBCu: goto label_80135EBC;
    case 0x80135EC0u: goto label_80135EC0;
    case 0x80135EC4u: goto label_80135EC4;
    case 0x80135EC8u: goto label_80135EC8;
    case 0x80135ECCu: goto label_80135ECC;
    case 0x80135ED0u: goto label_80135ED0;
    case 0x80135ED4u: goto label_80135ED4;
    case 0x80135ED8u: goto label_80135ED8;
    case 0x80135EDCu: goto label_80135EDC;
    case 0x80135EE0u: goto label_80135EE0;
    case 0x80135EE4u: goto label_80135EE4;
    case 0x80135EE8u: goto label_80135EE8;
    case 0x80135EECu: goto label_80135EEC;
    case 0x80135EF0u: goto label_80135EF0;
    case 0x80135EF4u: goto label_80135EF4;
    case 0x80135EF8u: goto label_80135EF8;
    case 0x80135EFCu: goto label_80135EFC;
    case 0x80135F00u: goto label_80135F00;
    case 0x80135F04u: goto label_80135F04;
    case 0x80135F08u: goto label_80135F08;
    case 0x80135F0Cu: goto label_80135F0C;
    case 0x80135F10u: goto label_80135F10;
    case 0x80135F14u: goto label_80135F14;
    case 0x80135F18u: goto label_80135F18;
    case 0x80135F1Cu: goto label_80135F1C;
    case 0x80135F20u: goto label_80135F20;
    case 0x80135F24u: goto label_80135F24;
    case 0x80135F28u: goto label_80135F28;
    case 0x80135F2Cu: goto label_80135F2C;
    case 0x80135F30u: goto label_80135F30;
    case 0x80135F34u: goto label_80135F34;
    case 0x80135F38u: goto label_80135F38;
    case 0x80135F3Cu: goto label_80135F3C;
    case 0x80135F40u: goto label_80135F40;
    case 0x80135F44u: goto label_80135F44;
    case 0x80135F48u: goto label_80135F48;
    case 0x80135F4Cu: goto label_80135F4C;
    case 0x80135F50u: goto label_80135F50;
    case 0x80135F54u: goto label_80135F54;
    case 0x80135F58u: goto label_80135F58;
    case 0x80135F5Cu: goto label_80135F5C;
    case 0x80135F60u: goto label_80135F60;
    case 0x80135F64u: goto label_80135F64;
    case 0x80135F68u: goto label_80135F68;
    case 0x80135F6Cu: goto label_80135F6C;
    case 0x80135F70u: goto label_80135F70;
    case 0x80135F74u: goto label_80135F74;
    case 0x80135F78u: goto label_80135F78;
    case 0x80135F7Cu: goto label_80135F7C;
    case 0x80135F80u: goto label_80135F80;
    case 0x80135F84u: goto label_80135F84;
    case 0x80135F88u: goto label_80135F88;
    case 0x80135F8Cu: goto label_80135F8C;
    case 0x80135F90u: goto label_80135F90;
    case 0x80135F94u: goto label_80135F94;
    case 0x80135F98u: goto label_80135F98;
    case 0x80135F9Cu: goto label_80135F9C;
    case 0x80135FA0u: goto label_80135FA0;
    case 0x80135FA4u: goto label_80135FA4;
    case 0x80135FA8u: goto label_80135FA8;
    case 0x80135FACu: goto label_80135FAC;
    case 0x80135FB0u: goto label_80135FB0;
    case 0x80135FB4u: goto label_80135FB4;
    case 0x80135FB8u: goto label_80135FB8;
    case 0x80135FBCu: goto label_80135FBC;
    case 0x80135FC0u: goto label_80135FC0;
    case 0x80135FC4u: goto label_80135FC4;
    case 0x80135FC8u: goto label_80135FC8;
    case 0x80135FCCu: goto label_80135FCC;
    case 0x80135FD0u: goto label_80135FD0;
    case 0x80135FD4u: goto label_80135FD4;
    case 0x80135FD8u: goto label_80135FD8;
    case 0x80135FDCu: goto label_80135FDC;
    case 0x80135FE0u: goto label_80135FE0;
    case 0x80135FE4u: goto label_80135FE4;
    case 0x80135FE8u: goto label_80135FE8;
    case 0x80135FECu: goto label_80135FEC;
    case 0x80135FF0u: goto label_80135FF0;
    case 0x80135FF4u: goto label_80135FF4;
    case 0x80135FF8u: goto label_80135FF8;
    case 0x80135FFCu: goto label_80135FFC;
    case 0x80136000u: goto label_80136000;
    case 0x80136004u: goto label_80136004;
    case 0x80136008u: goto label_80136008;
    case 0x8013600Cu: goto label_8013600C;
    case 0x80136010u: goto label_80136010;
    case 0x80136014u: goto label_80136014;
    case 0x80136018u: goto label_80136018;
    case 0x8013601Cu: goto label_8013601C;
    case 0x80136020u: goto label_80136020;
    case 0x80136024u: goto label_80136024;
    case 0x80136028u: goto label_80136028;
    case 0x8013602Cu: goto label_8013602C;
    case 0x80136030u: goto label_80136030;
    case 0x80136034u: goto label_80136034;
    case 0x80136038u: goto label_80136038;
    case 0x8013603Cu: goto label_8013603C;
    case 0x80136040u: goto label_80136040;
    case 0x80136044u: goto label_80136044;
    case 0x80136048u: goto label_80136048;
    case 0x8013604Cu: goto label_8013604C;
    case 0x80136050u: goto label_80136050;
    case 0x80136054u: goto label_80136054;
    case 0x80136058u: goto label_80136058;
    case 0x8013605Cu: goto label_8013605C;
    case 0x80136060u: goto label_80136060;
    case 0x80136064u: goto label_80136064;
    case 0x80136068u: goto label_80136068;
    case 0x8013606Cu: goto label_8013606C;
    case 0x80136070u: goto label_80136070;
    case 0x80136074u: goto label_80136074;
    case 0x80136078u: goto label_80136078;
    case 0x8013607Cu: goto label_8013607C;
    case 0x80136080u: goto label_80136080;
    case 0x80136084u: goto label_80136084;
    case 0x80136088u: goto label_80136088;
    case 0x8013608Cu: goto label_8013608C;
    case 0x80136090u: goto label_80136090;
    case 0x80136094u: goto label_80136094;
    case 0x80136098u: goto label_80136098;
    case 0x8013609Cu: goto label_8013609C;
    case 0x801360A0u: goto label_801360A0;
    case 0x801360A4u: goto label_801360A4;
    case 0x801360A8u: goto label_801360A8;
    case 0x801360ACu: goto label_801360AC;
    case 0x801360B0u: goto label_801360B0;
    case 0x801360B4u: goto label_801360B4;
    case 0x801360B8u: goto label_801360B8;
    case 0x801360BCu: goto label_801360BC;
    case 0x801360C0u: goto label_801360C0;
    case 0x801360C4u: goto label_801360C4;
    case 0x801360C8u: goto label_801360C8;
    case 0x801360CCu: goto label_801360CC;
    case 0x801360D0u: goto label_801360D0;
    case 0x801360D4u: goto label_801360D4;
    case 0x801360D8u: goto label_801360D8;
    case 0x801360DCu: goto label_801360DC;
    case 0x801360E0u: goto label_801360E0;
    case 0x801360E4u: goto label_801360E4;
    case 0x801360E8u: goto label_801360E8;
    case 0x801360ECu: goto label_801360EC;
    case 0x801360F0u: goto label_801360F0;
    case 0x801360F4u: goto label_801360F4;
    case 0x801360F8u: goto label_801360F8;
    case 0x801360FCu: goto label_801360FC;
    case 0x80136100u: goto label_80136100;
    case 0x80136104u: goto label_80136104;
    case 0x80136108u: goto label_80136108;
    case 0x8013610Cu: goto label_8013610C;
    case 0x80136110u: goto label_80136110;
    case 0x80136114u: goto label_80136114;
    case 0x80136118u: goto label_80136118;
    case 0x8013611Cu: goto label_8013611C;
    case 0x80136120u: goto label_80136120;
    case 0x80136124u: goto label_80136124;
    case 0x80136128u: goto label_80136128;
    case 0x8013612Cu: goto label_8013612C;
    case 0x80136130u: goto label_80136130;
    case 0x80136134u: goto label_80136134;
    case 0x80136138u: goto label_80136138;
    case 0x8013613Cu: goto label_8013613C;
    case 0x80136140u: goto label_80136140;
    case 0x80136144u: goto label_80136144;
    case 0x80136148u: goto label_80136148;
    case 0x8013614Cu: goto label_8013614C;
    case 0x80136150u: goto label_80136150;
    case 0x80136154u: goto label_80136154;
    case 0x80136158u: goto label_80136158;
    case 0x8013615Cu: goto label_8013615C;
    case 0x80136160u: goto label_80136160;
    case 0x80136164u: goto label_80136164;
    case 0x80136168u: goto label_80136168;
    case 0x8013616Cu: goto label_8013616C;
    case 0x80136170u: goto label_80136170;
    case 0x80136174u: goto label_80136174;
    case 0x80136178u: goto label_80136178;
    case 0x8013617Cu: goto label_8013617C;
    case 0x80136180u: goto label_80136180;
    case 0x80136184u: goto label_80136184;
    case 0x80136188u: goto label_80136188;
    case 0x8013618Cu: goto label_8013618C;
    case 0x80136190u: goto label_80136190;
    case 0x80136194u: goto label_80136194;
    case 0x80136198u: goto label_80136198;
    case 0x8013619Cu: goto label_8013619C;
    case 0x801361A0u: goto label_801361A0;
    case 0x801361A4u: goto label_801361A4;
    case 0x801361A8u: goto label_801361A8;
    case 0x801361ACu: goto label_801361AC;
    case 0x801361B0u: goto label_801361B0;
    case 0x801361B4u: goto label_801361B4;
    case 0x801361B8u: goto label_801361B8;
    case 0x801361BCu: goto label_801361BC;
    case 0x801361C0u: goto label_801361C0;
    case 0x801361C4u: goto label_801361C4;
    case 0x801361C8u: goto label_801361C8;
    case 0x801361CCu: goto label_801361CC;
    case 0x801361D0u: goto label_801361D0;
    case 0x801361D4u: goto label_801361D4;
    case 0x801361D8u: goto label_801361D8;
    case 0x801361DCu: goto label_801361DC;
    case 0x801361E0u: goto label_801361E0;
    case 0x801361E4u: goto label_801361E4;
    case 0x801361E8u: goto label_801361E8;
    case 0x801361ECu: goto label_801361EC;
    case 0x801361F0u: goto label_801361F0;
    case 0x801361F4u: goto label_801361F4;
    case 0x801361F8u: goto label_801361F8;
    case 0x801361FCu: goto label_801361FC;
    case 0x80136200u: goto label_80136200;
    case 0x80136204u: goto label_80136204;
    case 0x80136208u: goto label_80136208;
    case 0x8013620Cu: goto label_8013620C;
    case 0x80136210u: goto label_80136210;
    case 0x80136214u: goto label_80136214;
    case 0x80136218u: goto label_80136218;
    case 0x8013621Cu: goto label_8013621C;
    case 0x80136220u: goto label_80136220;
    case 0x80136224u: goto label_80136224;
    case 0x80136228u: goto label_80136228;
    case 0x8013622Cu: goto label_8013622C;
    case 0x80136230u: goto label_80136230;
    case 0x80136234u: goto label_80136234;
    case 0x80136238u: goto label_80136238;
    case 0x8013623Cu: goto label_8013623C;
    case 0x80136240u: goto label_80136240;
    case 0x80136244u: goto label_80136244;
    case 0x80136248u: goto label_80136248;
    case 0x8013624Cu: goto label_8013624C;
    case 0x80136250u: goto label_80136250;
    case 0x80136254u: goto label_80136254;
    case 0x80136258u: goto label_80136258;
    case 0x8013625Cu: goto label_8013625C;
    case 0x80136260u: goto label_80136260;
    case 0x80136264u: goto label_80136264;
    case 0x80136268u: goto label_80136268;
    case 0x8013626Cu: goto label_8013626C;
    case 0x80136270u: goto label_80136270;
    case 0x80136274u: goto label_80136274;
    case 0x80136278u: goto label_80136278;
    case 0x8013627Cu: goto label_8013627C;
    case 0x80136280u: goto label_80136280;
    case 0x80136284u: goto label_80136284;
    case 0x80136288u: goto label_80136288;
    case 0x8013628Cu: goto label_8013628C;
    case 0x80136290u: goto label_80136290;
    case 0x80136294u: goto label_80136294;
    case 0x80136298u: goto label_80136298;
    case 0x8013629Cu: goto label_8013629C;
    case 0x801362A0u: goto label_801362A0;
    case 0x801362A4u: goto label_801362A4;
    case 0x801362A8u: goto label_801362A8;
    case 0x801362ACu: goto label_801362AC;
    case 0x801362B0u: goto label_801362B0;
    case 0x801362B4u: goto label_801362B4;
    case 0x801362B8u: goto label_801362B8;
    case 0x801362BCu: goto label_801362BC;
    case 0x801362C0u: goto label_801362C0;
    case 0x801362C4u: goto label_801362C4;
    case 0x801362C8u: goto label_801362C8;
    case 0x801362CCu: goto label_801362CC;
    case 0x801362D0u: goto label_801362D0;
    case 0x801362D4u: goto label_801362D4;
    case 0x801362D8u: goto label_801362D8;
    case 0x801362DCu: goto label_801362DC;
    case 0x801362E0u: goto label_801362E0;
    case 0x801362E4u: goto label_801362E4;
    case 0x801362E8u: goto label_801362E8;
    case 0x801362ECu: goto label_801362EC;
    case 0x801362F0u: goto label_801362F0;
    case 0x801362F4u: goto label_801362F4;
    case 0x801362F8u: goto label_801362F8;
    case 0x801362FCu: goto label_801362FC;
    case 0x80136300u: goto label_80136300;
    case 0x80136304u: goto label_80136304;
    case 0x80136308u: goto label_80136308;
    case 0x8013630Cu: goto label_8013630C;
    case 0x80136310u: goto label_80136310;
    case 0x80136314u: goto label_80136314;
    case 0x80136318u: goto label_80136318;
    case 0x8013631Cu: goto label_8013631C;
    case 0x80136320u: goto label_80136320;
    case 0x80136324u: goto label_80136324;
    case 0x80136328u: goto label_80136328;
    case 0x8013632Cu: goto label_8013632C;
    case 0x80136330u: goto label_80136330;
    case 0x80136334u: goto label_80136334;
    case 0x80136338u: goto label_80136338;
    case 0x8013633Cu: goto label_8013633C;
    case 0x80136340u: goto label_80136340;
    case 0x80136344u: goto label_80136344;
    case 0x80136348u: goto label_80136348;
    case 0x8013634Cu: goto label_8013634C;
    case 0x80136350u: goto label_80136350;
    case 0x80136354u: goto label_80136354;
    case 0x80136358u: goto label_80136358;
    case 0x8013635Cu: goto label_8013635C;
    case 0x80136360u: goto label_80136360;
    case 0x80136364u: goto label_80136364;
    case 0x80136368u: goto label_80136368;
    case 0x8013636Cu: goto label_8013636C;
    case 0x80136370u: goto label_80136370;
    case 0x80136374u: goto label_80136374;
    case 0x80136378u: goto label_80136378;
    case 0x8013637Cu: goto label_8013637C;
    case 0x80136380u: goto label_80136380;
    case 0x80136384u: goto label_80136384;
    case 0x80136388u: goto label_80136388;
    case 0x8013638Cu: goto label_8013638C;
    case 0x80136390u: goto label_80136390;
    case 0x80136394u: goto label_80136394;
    case 0x80136398u: goto label_80136398;
    case 0x8013639Cu: goto label_8013639C;
    case 0x801363A0u: goto label_801363A0;
    case 0x801363A4u: goto label_801363A4;
    case 0x801363A8u: goto label_801363A8;
    case 0x801363ACu: goto label_801363AC;
    case 0x801363B0u: goto label_801363B0;
    case 0x801363B4u: goto label_801363B4;
    case 0x801363B8u: goto label_801363B8;
    case 0x801363BCu: goto label_801363BC;
    case 0x801363C0u: goto label_801363C0;
    case 0x801363C4u: goto label_801363C4;
    case 0x801363C8u: goto label_801363C8;
    case 0x801363CCu: goto label_801363CC;
    case 0x801363D0u: goto label_801363D0;
    case 0x801363D4u: goto label_801363D4;
    case 0x801363D8u: goto label_801363D8;
    case 0x801363DCu: goto label_801363DC;
    case 0x801363E0u: goto label_801363E0;
    case 0x801363E4u: goto label_801363E4;
    case 0x801363E8u: goto label_801363E8;
    case 0x801363ECu: goto label_801363EC;
    case 0x801363F0u: goto label_801363F0;
    case 0x801363F4u: goto label_801363F4;
    case 0x801363F8u: goto label_801363F8;
    case 0x801363FCu: goto label_801363FC;
    case 0x80136400u: goto label_80136400;
    case 0x80136404u: goto label_80136404;
    case 0x80136408u: goto label_80136408;
    case 0x8013640Cu: goto label_8013640C;
    case 0x80136410u: goto label_80136410;
    case 0x80136414u: goto label_80136414;
    case 0x80136418u: goto label_80136418;
    case 0x8013641Cu: goto label_8013641C;
    case 0x80136420u: goto label_80136420;
    case 0x80136424u: goto label_80136424;
    case 0x80136428u: goto label_80136428;
    case 0x8013642Cu: goto label_8013642C;
    case 0x80136430u: goto label_80136430;
    case 0x80136434u: goto label_80136434;
    case 0x80136438u: goto label_80136438;
    case 0x8013643Cu: goto label_8013643C;
    case 0x80136440u: goto label_80136440;
    case 0x80136444u: goto label_80136444;
    case 0x80136448u: goto label_80136448;
    case 0x8013644Cu: goto label_8013644C;
    case 0x80136450u: goto label_80136450;
    case 0x80136454u: goto label_80136454;
    case 0x80136458u: goto label_80136458;
    case 0x8013645Cu: goto label_8013645C;
    case 0x80136460u: goto label_80136460;
    case 0x80136464u: goto label_80136464;
    case 0x80136468u: goto label_80136468;
    case 0x8013646Cu: goto label_8013646C;
    case 0x80136470u: goto label_80136470;
    case 0x80136474u: goto label_80136474;
    case 0x80136478u: goto label_80136478;
    case 0x8013647Cu: goto label_8013647C;
    case 0x80136480u: goto label_80136480;
    case 0x80136484u: goto label_80136484;
    case 0x80136488u: goto label_80136488;
    case 0x8013648Cu: goto label_8013648C;
    case 0x80136490u: goto label_80136490;
    case 0x80136494u: goto label_80136494;
    case 0x80136498u: goto label_80136498;
    case 0x8013649Cu: goto label_8013649C;
    case 0x801364A0u: goto label_801364A0;
    case 0x801364A4u: goto label_801364A4;
    case 0x801364A8u: goto label_801364A8;
    case 0x801364ACu: goto label_801364AC;
    case 0x801364B0u: goto label_801364B0;
    case 0x801364B4u: goto label_801364B4;
    case 0x801364B8u: goto label_801364B8;
    case 0x801364BCu: goto label_801364BC;
    case 0x801364C0u: goto label_801364C0;
    case 0x801364C4u: goto label_801364C4;
    case 0x801364C8u: goto label_801364C8;
    case 0x801364CCu: goto label_801364CC;
    case 0x801364D0u: goto label_801364D0;
    case 0x801364D4u: goto label_801364D4;
    case 0x801364D8u: goto label_801364D8;
    case 0x801364DCu: goto label_801364DC;
    case 0x801364E0u: goto label_801364E0;
    case 0x801364E4u: goto label_801364E4;
    case 0x801364E8u: goto label_801364E8;
    case 0x801364ECu: goto label_801364EC;
    case 0x801364F0u: goto label_801364F0;
    case 0x801364F4u: goto label_801364F4;
    case 0x801364F8u: goto label_801364F8;
    case 0x801364FCu: goto label_801364FC;
    case 0x80136500u: goto label_80136500;
    case 0x80136504u: goto label_80136504;
    case 0x80136508u: goto label_80136508;
    case 0x8013650Cu: goto label_8013650C;
    case 0x80136510u: goto label_80136510;
    case 0x80136514u: goto label_80136514;
    case 0x80136518u: goto label_80136518;
    case 0x8013651Cu: goto label_8013651C;
    case 0x80136520u: goto label_80136520;
    case 0x80136524u: goto label_80136524;
    case 0x80136528u: goto label_80136528;
    case 0x8013652Cu: goto label_8013652C;
    case 0x80136530u: goto label_80136530;
    case 0x80136534u: goto label_80136534;
    case 0x80136538u: goto label_80136538;
    case 0x8013653Cu: goto label_8013653C;
    case 0x80136540u: goto label_80136540;
    case 0x80136544u: goto label_80136544;
    case 0x80136548u: goto label_80136548;
    case 0x8013654Cu: goto label_8013654C;
    case 0x80136550u: goto label_80136550;
    case 0x80136554u: goto label_80136554;
    case 0x80136558u: goto label_80136558;
    case 0x8013655Cu: goto label_8013655C;
    case 0x80136560u: goto label_80136560;
    case 0x80136564u: goto label_80136564;
    case 0x80136568u: goto label_80136568;
    case 0x8013656Cu: goto label_8013656C;
    case 0x80136570u: goto label_80136570;
    case 0x80136574u: goto label_80136574;
    case 0x80136578u: goto label_80136578;
    case 0x8013657Cu: goto label_8013657C;
    case 0x80136580u: goto label_80136580;
    case 0x80136584u: goto label_80136584;
    case 0x80136588u: goto label_80136588;
    case 0x8013658Cu: goto label_8013658C;
    case 0x80136590u: goto label_80136590;
    case 0x80136594u: goto label_80136594;
    case 0x80136598u: goto label_80136598;
    case 0x8013659Cu: goto label_8013659C;
    case 0x801365A0u: goto label_801365A0;
    case 0x801365A4u: goto label_801365A4;
    case 0x801365A8u: goto label_801365A8;
    case 0x801365ACu: goto label_801365AC;
    case 0x801365B0u: goto label_801365B0;
    case 0x801365B4u: goto label_801365B4;
    case 0x801365B8u: goto label_801365B8;
    case 0x801365BCu: goto label_801365BC;
    case 0x801365C0u: goto label_801365C0;
    case 0x801365C4u: goto label_801365C4;
    case 0x801365C8u: goto label_801365C8;
    case 0x801365CCu: goto label_801365CC;
    case 0x801365D0u: goto label_801365D0;
    case 0x801365D4u: goto label_801365D4;
    case 0x801365D8u: goto label_801365D8;
    case 0x801365DCu: goto label_801365DC;
    case 0x801365E0u: goto label_801365E0;
    case 0x801365E4u: goto label_801365E4;
    case 0x801365E8u: goto label_801365E8;
    case 0x801365ECu: goto label_801365EC;
    case 0x801365F0u: goto label_801365F0;
    case 0x801365F4u: goto label_801365F4;
    case 0x801365F8u: goto label_801365F8;
    case 0x801365FCu: goto label_801365FC;
    case 0x80136600u: goto label_80136600;
    case 0x80136604u: goto label_80136604;
    case 0x80136608u: goto label_80136608;
    case 0x8013660Cu: goto label_8013660C;
    case 0x80136610u: goto label_80136610;
    case 0x80136614u: goto label_80136614;
    case 0x80136618u: goto label_80136618;
    case 0x8013661Cu: goto label_8013661C;
    case 0x80136620u: goto label_80136620;
    case 0x80136624u: goto label_80136624;
    case 0x80136628u: goto label_80136628;
    case 0x8013662Cu: goto label_8013662C;
    case 0x80136630u: goto label_80136630;
    case 0x80136634u: goto label_80136634;
    case 0x80136638u: goto label_80136638;
    case 0x8013663Cu: goto label_8013663C;
    case 0x80136640u: goto label_80136640;
    case 0x80136644u: goto label_80136644;
    case 0x80136648u: goto label_80136648;
    case 0x8013664Cu: goto label_8013664C;
    case 0x80136650u: goto label_80136650;
    case 0x80136654u: goto label_80136654;
    case 0x80136658u: goto label_80136658;
    case 0x8013665Cu: goto label_8013665C;
    case 0x80136660u: goto label_80136660;
    case 0x80136664u: goto label_80136664;
    case 0x80136668u: goto label_80136668;
    case 0x8013666Cu: goto label_8013666C;
    case 0x80136670u: goto label_80136670;
    case 0x80136674u: goto label_80136674;
    case 0x80136678u: goto label_80136678;
    case 0x8013667Cu: goto label_8013667C;
    case 0x80136680u: goto label_80136680;
    case 0x80136684u: goto label_80136684;
    case 0x80136688u: goto label_80136688;
    case 0x8013668Cu: goto label_8013668C;
    case 0x80136690u: goto label_80136690;
    case 0x80136694u: goto label_80136694;
    case 0x80136698u: goto label_80136698;
    case 0x8013669Cu: goto label_8013669C;
    case 0x801366A0u: goto label_801366A0;
    case 0x801366A4u: goto label_801366A4;
    case 0x801366A8u: goto label_801366A8;
    case 0x801366ACu: goto label_801366AC;
    case 0x801366B0u: goto label_801366B0;
    case 0x801366B4u: goto label_801366B4;
    case 0x801366B8u: goto label_801366B8;
    case 0x801366BCu: goto label_801366BC;
    case 0x801366C0u: goto label_801366C0;
    case 0x801366C4u: goto label_801366C4;
    case 0x801366C8u: goto label_801366C8;
    case 0x801366CCu: goto label_801366CC;
    case 0x801366D0u: goto label_801366D0;
    case 0x801366D4u: goto label_801366D4;
    case 0x801366D8u: goto label_801366D8;
    case 0x801366DCu: goto label_801366DC;
    case 0x801366E0u: goto label_801366E0;
    case 0x801366E4u: goto label_801366E4;
    case 0x801366E8u: goto label_801366E8;
    case 0x801366ECu: goto label_801366EC;
    case 0x801366F0u: goto label_801366F0;
    case 0x801366F4u: goto label_801366F4;
    case 0x801366F8u: goto label_801366F8;
    case 0x801366FCu: goto label_801366FC;
    case 0x80136700u: goto label_80136700;
    case 0x80136704u: goto label_80136704;
    case 0x80136708u: goto label_80136708;
    case 0x8013670Cu: goto label_8013670C;
    case 0x80136710u: goto label_80136710;
    case 0x80136714u: goto label_80136714;
    case 0x80136718u: goto label_80136718;
    case 0x8013671Cu: goto label_8013671C;
    case 0x80136720u: goto label_80136720;
    case 0x80136724u: goto label_80136724;
    case 0x80136728u: goto label_80136728;
    case 0x8013672Cu: goto label_8013672C;
    case 0x80136730u: goto label_80136730;
    case 0x80136734u: goto label_80136734;
    case 0x80136738u: goto label_80136738;
    case 0x8013673Cu: goto label_8013673C;
    case 0x80136740u: goto label_80136740;
    case 0x80136744u: goto label_80136744;
    case 0x80136748u: goto label_80136748;
    case 0x8013674Cu: goto label_8013674C;
    case 0x80136750u: goto label_80136750;
    case 0x80136754u: goto label_80136754;
    case 0x80136758u: goto label_80136758;
    case 0x8013675Cu: goto label_8013675C;
    case 0x80136760u: goto label_80136760;
    case 0x80136764u: goto label_80136764;
    case 0x80136768u: goto label_80136768;
    case 0x8013676Cu: goto label_8013676C;
    case 0x80136770u: goto label_80136770;
    case 0x80136774u: goto label_80136774;
    case 0x80136778u: goto label_80136778;
    case 0x8013677Cu: goto label_8013677C;
    case 0x80136780u: goto label_80136780;
    case 0x80136784u: goto label_80136784;
    case 0x80136788u: goto label_80136788;
    case 0x8013678Cu: goto label_8013678C;
    case 0x80136790u: goto label_80136790;
    case 0x80136794u: goto label_80136794;
    case 0x80136798u: goto label_80136798;
    case 0x8013679Cu: goto label_8013679C;
    case 0x801367A0u: goto label_801367A0;
    case 0x801367A4u: goto label_801367A4;
    case 0x801367A8u: goto label_801367A8;
    case 0x801367ACu: goto label_801367AC;
    case 0x801367B0u: goto label_801367B0;
    case 0x801367B4u: goto label_801367B4;
    case 0x801367B8u: goto label_801367B8;
    case 0x801367BCu: goto label_801367BC;
    case 0x801367C0u: goto label_801367C0;
    case 0x801367C4u: goto label_801367C4;
    case 0x801367C8u: goto label_801367C8;
    case 0x801367CCu: goto label_801367CC;
    case 0x801367D0u: goto label_801367D0;
    case 0x801367D4u: goto label_801367D4;
    case 0x801367D8u: goto label_801367D8;
    case 0x801367DCu: goto label_801367DC;
    case 0x801367E0u: goto label_801367E0;
    case 0x801367E4u: goto label_801367E4;
    case 0x801367E8u: goto label_801367E8;
    case 0x801367ECu: goto label_801367EC;
    case 0x801367F0u: goto label_801367F0;
    case 0x801367F4u: goto label_801367F4;
    case 0x801367F8u: goto label_801367F8;
    case 0x801367FCu: goto label_801367FC;
    case 0x80136800u: goto label_80136800;
    case 0x80136804u: goto label_80136804;
    case 0x80136808u: goto label_80136808;
    case 0x8013680Cu: goto label_8013680C;
    case 0x80136810u: goto label_80136810;
    case 0x80136814u: goto label_80136814;
    case 0x80136818u: goto label_80136818;
    case 0x8013681Cu: goto label_8013681C;
    case 0x80136820u: goto label_80136820;
    case 0x80136824u: goto label_80136824;
    case 0x80136828u: goto label_80136828;
    case 0x8013682Cu: goto label_8013682C;
    case 0x80136830u: goto label_80136830;
    case 0x80136834u: goto label_80136834;
    case 0x80136838u: goto label_80136838;
    case 0x8013683Cu: goto label_8013683C;
    case 0x80136840u: goto label_80136840;
    case 0x80136844u: goto label_80136844;
    case 0x80136848u: goto label_80136848;
    case 0x8013684Cu: goto label_8013684C;
    case 0x80136850u: goto label_80136850;
    case 0x80136854u: goto label_80136854;
    case 0x80136858u: goto label_80136858;
    case 0x8013685Cu: goto label_8013685C;
    case 0x80136860u: goto label_80136860;
    case 0x80136864u: goto label_80136864;
    case 0x80136868u: goto label_80136868;
    case 0x8013686Cu: goto label_8013686C;
    case 0x80136870u: goto label_80136870;
    case 0x80136874u: goto label_80136874;
    case 0x80136878u: goto label_80136878;
    case 0x8013687Cu: goto label_8013687C;
    case 0x80136880u: goto label_80136880;
    case 0x80136884u: goto label_80136884;
    case 0x80136888u: goto label_80136888;
    case 0x8013688Cu: goto label_8013688C;
    case 0x80136890u: goto label_80136890;
    case 0x80136894u: goto label_80136894;
    case 0x80136898u: goto label_80136898;
    case 0x8013689Cu: goto label_8013689C;
    case 0x801368A0u: goto label_801368A0;
    case 0x801368A4u: goto label_801368A4;
    case 0x801368A8u: goto label_801368A8;
    case 0x801368ACu: goto label_801368AC;
    case 0x801368B0u: goto label_801368B0;
    case 0x801368B4u: goto label_801368B4;
    case 0x801368B8u: goto label_801368B8;
    case 0x801368BCu: goto label_801368BC;
    case 0x801368C0u: goto label_801368C0;
    case 0x801368C4u: goto label_801368C4;
    case 0x801368C8u: goto label_801368C8;
    case 0x801368CCu: goto label_801368CC;
    case 0x801368D0u: goto label_801368D0;
    case 0x801368D4u: goto label_801368D4;
    case 0x801368D8u: goto label_801368D8;
    case 0x801368DCu: goto label_801368DC;
    case 0x801368E0u: goto label_801368E0;
    case 0x801368E4u: goto label_801368E4;
    case 0x801368E8u: goto label_801368E8;
    case 0x801368ECu: goto label_801368EC;
    case 0x801368F0u: goto label_801368F0;
    case 0x801368F4u: goto label_801368F4;
    case 0x801368F8u: goto label_801368F8;
    case 0x801368FCu: goto label_801368FC;
    case 0x80136900u: goto label_80136900;
    case 0x80136904u: goto label_80136904;
    case 0x80136908u: goto label_80136908;
    case 0x8013690Cu: goto label_8013690C;
    case 0x80136910u: goto label_80136910;
    case 0x80136914u: goto label_80136914;
    case 0x80136918u: goto label_80136918;
    case 0x8013691Cu: goto label_8013691C;
    case 0x80136920u: goto label_80136920;
    case 0x80136924u: goto label_80136924;
    case 0x80136928u: goto label_80136928;
    case 0x8013692Cu: goto label_8013692C;
    case 0x80136930u: goto label_80136930;
    case 0x80136934u: goto label_80136934;
    case 0x80136938u: goto label_80136938;
    case 0x8013693Cu: goto label_8013693C;
    case 0x80136940u: goto label_80136940;
    case 0x80136944u: goto label_80136944;
    case 0x80136948u: goto label_80136948;
    case 0x8013694Cu: goto label_8013694C;
    case 0x80136950u: goto label_80136950;
    case 0x80136954u: goto label_80136954;
    case 0x80136958u: goto label_80136958;
    case 0x8013695Cu: goto label_8013695C;
    case 0x80136960u: goto label_80136960;
    case 0x80136964u: goto label_80136964;
    case 0x80136968u: goto label_80136968;
    case 0x8013696Cu: goto label_8013696C;
    case 0x80136970u: goto label_80136970;
    case 0x80136974u: goto label_80136974;
    case 0x80136978u: goto label_80136978;
    case 0x8013697Cu: goto label_8013697C;
    case 0x80136980u: goto label_80136980;
    case 0x80136984u: goto label_80136984;
    case 0x80136988u: goto label_80136988;
    case 0x8013698Cu: goto label_8013698C;
    case 0x80136990u: goto label_80136990;
    case 0x80136994u: goto label_80136994;
    case 0x80136998u: goto label_80136998;
    case 0x8013699Cu: goto label_8013699C;
    case 0x801369A0u: goto label_801369A0;
    case 0x801369A4u: goto label_801369A4;
    case 0x801369A8u: goto label_801369A8;
    case 0x801369ACu: goto label_801369AC;
    case 0x801369B0u: goto label_801369B0;
    case 0x801369B4u: goto label_801369B4;
    case 0x801369B8u: goto label_801369B8;
    case 0x801369BCu: goto label_801369BC;
    case 0x801369C0u: goto label_801369C0;
    case 0x801369C4u: goto label_801369C4;
    case 0x801369C8u: goto label_801369C8;
    case 0x801369CCu: goto label_801369CC;
    case 0x801369D0u: goto label_801369D0;
    case 0x801369D4u: goto label_801369D4;
    case 0x801369D8u: goto label_801369D8;
    case 0x801369DCu: goto label_801369DC;
    case 0x801369E0u: goto label_801369E0;
    case 0x801369E4u: goto label_801369E4;
    case 0x801369E8u: goto label_801369E8;
    case 0x801369ECu: goto label_801369EC;
    case 0x801369F0u: goto label_801369F0;
    case 0x801369F4u: goto label_801369F4;
    case 0x801369F8u: goto label_801369F8;
    case 0x801369FCu: goto label_801369FC;
    case 0x80136A00u: goto label_80136A00;
    case 0x80136A04u: goto label_80136A04;
    case 0x80136A08u: goto label_80136A08;
    case 0x80136A0Cu: goto label_80136A0C;
    case 0x80136A10u: goto label_80136A10;
    case 0x80136A14u: goto label_80136A14;
    case 0x80136A18u: goto label_80136A18;
    case 0x80136A1Cu: goto label_80136A1C;
    case 0x80136A20u: goto label_80136A20;
    case 0x80136A24u: goto label_80136A24;
    case 0x80136A28u: goto label_80136A28;
    case 0x80136A2Cu: goto label_80136A2C;
    case 0x80136A30u: goto label_80136A30;
    case 0x80136A34u: goto label_80136A34;
    case 0x80136A38u: goto label_80136A38;
    case 0x80136A3Cu: goto label_80136A3C;
    case 0x80136A40u: goto label_80136A40;
    case 0x80136A44u: goto label_80136A44;
    case 0x80136A48u: goto label_80136A48;
    case 0x80136A4Cu: goto label_80136A4C;
    case 0x80136A50u: goto label_80136A50;
    case 0x80136A54u: goto label_80136A54;
    case 0x80136A58u: goto label_80136A58;
    case 0x80136A5Cu: goto label_80136A5C;
    case 0x80136A60u: goto label_80136A60;
    case 0x80136A64u: goto label_80136A64;
    case 0x80136A68u: goto label_80136A68;
    case 0x80136A6Cu: goto label_80136A6C;
    case 0x80136A70u: goto label_80136A70;
    case 0x80136A74u: goto label_80136A74;
    case 0x80136A78u: goto label_80136A78;
    case 0x80136A7Cu: goto label_80136A7C;
    case 0x80136A80u: goto label_80136A80;
    case 0x80136A84u: goto label_80136A84;
    case 0x80136A88u: goto label_80136A88;
    case 0x80136A8Cu: goto label_80136A8C;
    case 0x80136A90u: goto label_80136A90;
    case 0x80136A94u: goto label_80136A94;
    case 0x80136A98u: goto label_80136A98;
    case 0x80136A9Cu: goto label_80136A9C;
    case 0x80136AA0u: goto label_80136AA0;
    case 0x80136AA4u: goto label_80136AA4;
    case 0x80136AA8u: goto label_80136AA8;
    case 0x80136AACu: goto label_80136AAC;
    case 0x80136AB0u: goto label_80136AB0;
    case 0x80136AB4u: goto label_80136AB4;
    case 0x80136AB8u: goto label_80136AB8;
    case 0x80136ABCu: goto label_80136ABC;
    case 0x80136AC0u: goto label_80136AC0;
    case 0x80136AC4u: goto label_80136AC4;
    case 0x80136AC8u: goto label_80136AC8;
    case 0x80136ACCu: goto label_80136ACC;
    case 0x80136AD0u: goto label_80136AD0;
    case 0x80136AD4u: goto label_80136AD4;
    case 0x80136AD8u: goto label_80136AD8;
    case 0x80136ADCu: goto label_80136ADC;
    case 0x80136AE0u: goto label_80136AE0;
    case 0x80136AE4u: goto label_80136AE4;
    case 0x80136AE8u: goto label_80136AE8;
    case 0x80136AECu: goto label_80136AEC;
    case 0x80136AF0u: goto label_80136AF0;
    case 0x80136AF4u: goto label_80136AF4;
    case 0x80136AF8u: goto label_80136AF8;
    case 0x80136AFCu: goto label_80136AFC;
    case 0x80136B00u: goto label_80136B00;
    case 0x80136B04u: goto label_80136B04;
    case 0x80136B08u: goto label_80136B08;
    case 0x80136B0Cu: goto label_80136B0C;
    case 0x80136B10u: goto label_80136B10;
    case 0x80136B14u: goto label_80136B14;
    case 0x80136B18u: goto label_80136B18;
    case 0x80136B1Cu: goto label_80136B1C;
    case 0x80136B20u: goto label_80136B20;
    case 0x80136B24u: goto label_80136B24;
    case 0x80136B28u: goto label_80136B28;
    case 0x80136B2Cu: goto label_80136B2C;
    case 0x80136B30u: goto label_80136B30;
    case 0x80136B34u: goto label_80136B34;
    case 0x80136B38u: goto label_80136B38;
    case 0x80136B3Cu: goto label_80136B3C;
    case 0x80136B40u: goto label_80136B40;
    case 0x80136B44u: goto label_80136B44;
    case 0x80136B48u: goto label_80136B48;
    case 0x80136B4Cu: goto label_80136B4C;
    case 0x80136B50u: goto label_80136B50;
    case 0x80136B54u: goto label_80136B54;
    case 0x80136B58u: goto label_80136B58;
    case 0x80136B5Cu: goto label_80136B5C;
    case 0x80136B60u: goto label_80136B60;
    case 0x80136B64u: goto label_80136B64;
    case 0x80136B68u: goto label_80136B68;
    case 0x80136B6Cu: goto label_80136B6C;
    case 0x80136B70u: goto label_80136B70;
    case 0x80136B74u: goto label_80136B74;
    case 0x80136B78u: goto label_80136B78;
    case 0x80136B7Cu: goto label_80136B7C;
    case 0x80136B80u: goto label_80136B80;
    case 0x80136B84u: goto label_80136B84;
    case 0x80136B88u: goto label_80136B88;
    case 0x80136B8Cu: goto label_80136B8C;
    case 0x80136B90u: goto label_80136B90;
    case 0x80136B94u: goto label_80136B94;
    case 0x80136B98u: goto label_80136B98;
    case 0x80136B9Cu: goto label_80136B9C;
    case 0x80136BA0u: goto label_80136BA0;
    case 0x80136BA4u: goto label_80136BA4;
    case 0x80136BA8u: goto label_80136BA8;
    case 0x80136BACu: goto label_80136BAC;
    case 0x80136BB0u: goto label_80136BB0;
    case 0x80136BB4u: goto label_80136BB4;
    case 0x80136BB8u: goto label_80136BB8;
    case 0x80136BBCu: goto label_80136BBC;
    case 0x80136BC0u: goto label_80136BC0;
    case 0x80136BC4u: goto label_80136BC4;
    case 0x80136BC8u: goto label_80136BC8;
    case 0x80136BCCu: goto label_80136BCC;
    case 0x80136BD0u: goto label_80136BD0;
    case 0x80136BD4u: goto label_80136BD4;
    case 0x80136BD8u: goto label_80136BD8;
    case 0x80136BDCu: goto label_80136BDC;
    case 0x80136BE0u: goto label_80136BE0;
    case 0x80136BE4u: goto label_80136BE4;
    case 0x80136BE8u: goto label_80136BE8;
    case 0x80136BECu: goto label_80136BEC;
    case 0x80136BF0u: goto label_80136BF0;
    case 0x80136BF4u: goto label_80136BF4;
    case 0x80136BF8u: goto label_80136BF8;
    case 0x80136BFCu: goto label_80136BFC;
    case 0x80136C00u: goto label_80136C00;
    case 0x80136C04u: goto label_80136C04;
    case 0x80136C08u: goto label_80136C08;
    case 0x80136C0Cu: goto label_80136C0C;
    case 0x80136C10u: goto label_80136C10;
    case 0x80136C14u: goto label_80136C14;
    case 0x80136C18u: goto label_80136C18;
    case 0x80136C1Cu: goto label_80136C1C;
    case 0x80136C20u: goto label_80136C20;
    case 0x80136C24u: goto label_80136C24;
    case 0x80136C28u: goto label_80136C28;
    case 0x80136C2Cu: goto label_80136C2C;
    case 0x80136C30u: goto label_80136C30;
    case 0x80136C34u: goto label_80136C34;
    case 0x80136C38u: goto label_80136C38;
    case 0x80136C3Cu: goto label_80136C3C;
    case 0x80136C40u: goto label_80136C40;
    case 0x80136C44u: goto label_80136C44;
    case 0x80136C48u: goto label_80136C48;
    case 0x80136C4Cu: goto label_80136C4C;
    case 0x80136C50u: goto label_80136C50;
    case 0x80136C54u: goto label_80136C54;
    case 0x80136C58u: goto label_80136C58;
    case 0x80136C5Cu: goto label_80136C5C;
    case 0x80136C60u: goto label_80136C60;
    case 0x80136C64u: goto label_80136C64;
    case 0x80136C68u: goto label_80136C68;
    case 0x80136C6Cu: goto label_80136C6C;
    case 0x80136C70u: goto label_80136C70;
    case 0x80136C74u: goto label_80136C74;
    case 0x80136C78u: goto label_80136C78;
    case 0x80136C7Cu: goto label_80136C7C;
    case 0x80136C80u: goto label_80136C80;
    case 0x80136C84u: goto label_80136C84;
    case 0x80136C88u: goto label_80136C88;
    case 0x80136C8Cu: goto label_80136C8C;
    case 0x80136C90u: goto label_80136C90;
    case 0x80136C94u: goto label_80136C94;
    case 0x80136C98u: goto label_80136C98;
    case 0x80136C9Cu: goto label_80136C9C;
    case 0x80136CA0u: goto label_80136CA0;
    case 0x80136CA4u: goto label_80136CA4;
    case 0x80136CA8u: goto label_80136CA8;
    case 0x80136CACu: goto label_80136CAC;
    case 0x80136CB0u: goto label_80136CB0;
    case 0x80136CB4u: goto label_80136CB4;
    case 0x80136CB8u: goto label_80136CB8;
    case 0x80136CBCu: goto label_80136CBC;
    case 0x80136CC0u: goto label_80136CC0;
    case 0x80136CC4u: goto label_80136CC4;
    case 0x80136CC8u: goto label_80136CC8;
    case 0x80136CCCu: goto label_80136CCC;
    case 0x80136CD0u: goto label_80136CD0;
    case 0x80136CD4u: goto label_80136CD4;
    case 0x80136CD8u: goto label_80136CD8;
    case 0x80136CDCu: goto label_80136CDC;
    case 0x80136CE0u: goto label_80136CE0;
    case 0x80136CE4u: goto label_80136CE4;
    case 0x80136CE8u: goto label_80136CE8;
    case 0x80136CECu: goto label_80136CEC;
    case 0x80136CF0u: goto label_80136CF0;
    case 0x80136CF4u: goto label_80136CF4;
    case 0x80136CF8u: goto label_80136CF8;
    case 0x80136CFCu: goto label_80136CFC;
    case 0x80136D00u: goto label_80136D00;
    case 0x80136D04u: goto label_80136D04;
    case 0x80136D08u: goto label_80136D08;
    case 0x80136D0Cu: goto label_80136D0C;
    case 0x80136D10u: goto label_80136D10;
    case 0x80136D14u: goto label_80136D14;
    case 0x80136D18u: goto label_80136D18;
    case 0x80136D1Cu: goto label_80136D1C;
    case 0x80136D20u: goto label_80136D20;
    case 0x80136D24u: goto label_80136D24;
    case 0x80136D28u: goto label_80136D28;
    case 0x80136D2Cu: goto label_80136D2C;
    case 0x80136D30u: goto label_80136D30;
    case 0x80136D34u: goto label_80136D34;
    case 0x80136D38u: goto label_80136D38;
    case 0x80136D3Cu: goto label_80136D3C;
    case 0x80136D40u: goto label_80136D40;
    case 0x80136D44u: goto label_80136D44;
    case 0x80136D48u: goto label_80136D48;
    case 0x80136D4Cu: goto label_80136D4C;
    case 0x80136D50u: goto label_80136D50;
    case 0x80136D54u: goto label_80136D54;
    case 0x80136D58u: goto label_80136D58;
    case 0x80136D5Cu: goto label_80136D5C;
    case 0x80136D60u: goto label_80136D60;
    case 0x80136D64u: goto label_80136D64;
    case 0x80136D68u: goto label_80136D68;
    case 0x80136D6Cu: goto label_80136D6C;
    case 0x80136D70u: goto label_80136D70;
    case 0x80136D74u: goto label_80136D74;
    case 0x80136D78u: goto label_80136D78;
    case 0x80136D7Cu: goto label_80136D7C;
    case 0x80136D80u: goto label_80136D80;
    case 0x80136D84u: goto label_80136D84;
    case 0x80136D88u: goto label_80136D88;
    case 0x80136D8Cu: goto label_80136D8C;
    case 0x80136D90u: goto label_80136D90;
    case 0x80136D94u: goto label_80136D94;
    case 0x80136D98u: goto label_80136D98;
    case 0x80136D9Cu: goto label_80136D9C;
    case 0x80136DA0u: goto label_80136DA0;
    case 0x80136DA4u: goto label_80136DA4;
    case 0x80136DA8u: goto label_80136DA8;
    case 0x80136DACu: goto label_80136DAC;
    case 0x80136DB0u: goto label_80136DB0;
    case 0x80136DB4u: goto label_80136DB4;
    case 0x80136DB8u: goto label_80136DB8;
    case 0x80136DBCu: goto label_80136DBC;
    case 0x80136DC0u: goto label_80136DC0;
    case 0x80136DC4u: goto label_80136DC4;
    case 0x80136DC8u: goto label_80136DC8;
    case 0x80136DCCu: goto label_80136DCC;
    case 0x80136DD0u: goto label_80136DD0;
    case 0x80136DD4u: goto label_80136DD4;
    case 0x80136DD8u: goto label_80136DD8;
    case 0x80136DDCu: goto label_80136DDC;
    case 0x80136DE0u: goto label_80136DE0;
    case 0x80136DE4u: goto label_80136DE4;
    case 0x80136DE8u: goto label_80136DE8;
    case 0x80136DECu: goto label_80136DEC;
    case 0x80136DF0u: goto label_80136DF0;
    case 0x80136DF4u: goto label_80136DF4;
    case 0x80136DF8u: goto label_80136DF8;
    case 0x80136DFCu: goto label_80136DFC;
    case 0x80136E00u: goto label_80136E00;
    case 0x80136E04u: goto label_80136E04;
    case 0x80136E08u: goto label_80136E08;
    case 0x80136E0Cu: goto label_80136E0C;
    case 0x80136E10u: goto label_80136E10;
    case 0x80136E14u: goto label_80136E14;
    case 0x80136E18u: goto label_80136E18;
    case 0x80136E1Cu: goto label_80136E1C;
    case 0x80136E20u: goto label_80136E20;
    case 0x80136E24u: goto label_80136E24;
    case 0x80136E28u: goto label_80136E28;
    case 0x80136E2Cu: goto label_80136E2C;
    case 0x80136E30u: goto label_80136E30;
    case 0x80136E34u: goto label_80136E34;
    case 0x80136E38u: goto label_80136E38;
    case 0x80136E3Cu: goto label_80136E3C;
    case 0x80136E40u: goto label_80136E40;
    case 0x80136E44u: goto label_80136E44;
    case 0x80136E48u: goto label_80136E48;
    case 0x80136E4Cu: goto label_80136E4C;
    case 0x80136E50u: goto label_80136E50;
    case 0x80136E54u: goto label_80136E54;
    case 0x80136E58u: goto label_80136E58;
    case 0x80136E5Cu: goto label_80136E5C;
    case 0x80136E60u: goto label_80136E60;
    case 0x80136E64u: goto label_80136E64;
    case 0x80136E68u: goto label_80136E68;
    case 0x80136E6Cu: goto label_80136E6C;
    case 0x80136E70u: goto label_80136E70;
    case 0x80136E74u: goto label_80136E74;
    case 0x80136E78u: goto label_80136E78;
    case 0x80136E7Cu: goto label_80136E7C;
    case 0x80136E80u: goto label_80136E80;
    case 0x80136E84u: goto label_80136E84;
    case 0x80136E88u: goto label_80136E88;
    case 0x80136E8Cu: goto label_80136E8C;
    case 0x80136E90u: goto label_80136E90;
    case 0x80136E94u: goto label_80136E94;
    case 0x80136E98u: goto label_80136E98;
    case 0x80136E9Cu: goto label_80136E9C;
    case 0x80136EA0u: goto label_80136EA0;
    case 0x80136EA4u: goto label_80136EA4;
    case 0x80136EA8u: goto label_80136EA8;
    case 0x80136EACu: goto label_80136EAC;
    case 0x80136EB0u: goto label_80136EB0;
    case 0x80136EB4u: goto label_80136EB4;
    case 0x80136EB8u: goto label_80136EB8;
    case 0x80136EBCu: goto label_80136EBC;
    case 0x80136EC0u: goto label_80136EC0;
    case 0x80136EC4u: goto label_80136EC4;
    case 0x80136EC8u: goto label_80136EC8;
    case 0x80136ECCu: goto label_80136ECC;
    case 0x80136ED0u: goto label_80136ED0;
    case 0x80136ED4u: goto label_80136ED4;
    case 0x80136ED8u: goto label_80136ED8;
    case 0x80136EDCu: goto label_80136EDC;
    case 0x80136EE0u: goto label_80136EE0;
    case 0x80136EE4u: goto label_80136EE4;
    case 0x80136EE8u: goto label_80136EE8;
    case 0x80136EECu: goto label_80136EEC;
    case 0x80136EF0u: goto label_80136EF0;
    case 0x80136EF4u: goto label_80136EF4;
    case 0x80136EF8u: goto label_80136EF8;
    case 0x80136EFCu: goto label_80136EFC;
    case 0x80136F00u: goto label_80136F00;
    case 0x80136F04u: goto label_80136F04;
    case 0x80136F08u: goto label_80136F08;
    case 0x80136F0Cu: goto label_80136F0C;
    case 0x80136F10u: goto label_80136F10;
    case 0x80136F14u: goto label_80136F14;
    case 0x80136F18u: goto label_80136F18;
    case 0x80136F1Cu: goto label_80136F1C;
    case 0x80136F20u: goto label_80136F20;
    case 0x80136F24u: goto label_80136F24;
    case 0x80136F28u: goto label_80136F28;
    case 0x80136F2Cu: goto label_80136F2C;
    case 0x80136F30u: goto label_80136F30;
    case 0x80136F34u: goto label_80136F34;
    case 0x80136F38u: goto label_80136F38;
    case 0x80136F3Cu: goto label_80136F3C;
    case 0x80136F40u: goto label_80136F40;
    case 0x80136F44u: goto label_80136F44;
    case 0x80136F48u: goto label_80136F48;
    case 0x80136F4Cu: goto label_80136F4C;
    case 0x80136F50u: goto label_80136F50;
    case 0x80136F54u: goto label_80136F54;
    case 0x80136F58u: goto label_80136F58;
    case 0x80136F5Cu: goto label_80136F5C;
    case 0x80136F60u: goto label_80136F60;
    case 0x80136F64u: goto label_80136F64;
    case 0x80136F68u: goto label_80136F68;
    case 0x80136F6Cu: goto label_80136F6C;
    case 0x80136F70u: goto label_80136F70;
    case 0x80136F74u: goto label_80136F74;
    case 0x80136F78u: goto label_80136F78;
    case 0x80136F7Cu: goto label_80136F7C;
    case 0x80136F80u: goto label_80136F80;
    case 0x80136F84u: goto label_80136F84;
    case 0x80136F88u: goto label_80136F88;
    case 0x80136F8Cu: goto label_80136F8C;
    case 0x80136F90u: goto label_80136F90;
    case 0x80136F94u: goto label_80136F94;
    case 0x80136F98u: goto label_80136F98;
    case 0x80136F9Cu: goto label_80136F9C;
    case 0x80136FA0u: goto label_80136FA0;
    case 0x80136FA4u: goto label_80136FA4;
    case 0x80136FA8u: goto label_80136FA8;
    case 0x80136FACu: goto label_80136FAC;
    case 0x80136FB0u: goto label_80136FB0;
    case 0x80136FB4u: goto label_80136FB4;
    case 0x80136FB8u: goto label_80136FB8;
    case 0x80136FBCu: goto label_80136FBC;
    case 0x80136FC0u: goto label_80136FC0;
    case 0x80136FC4u: goto label_80136FC4;
    case 0x80136FC8u: goto label_80136FC8;
    case 0x80136FCCu: goto label_80136FCC;
    case 0x80136FD0u: goto label_80136FD0;
    case 0x80136FD4u: goto label_80136FD4;
    case 0x80136FD8u: goto label_80136FD8;
    case 0x80136FDCu: goto label_80136FDC;
    case 0x80136FE0u: goto label_80136FE0;
    case 0x80136FE4u: goto label_80136FE4;
    case 0x80136FE8u: goto label_80136FE8;
    case 0x80136FECu: goto label_80136FEC;
    case 0x80136FF0u: goto label_80136FF0;
    case 0x80136FF4u: goto label_80136FF4;
    case 0x80136FF8u: goto label_80136FF8;
    case 0x80136FFCu: goto label_80136FFC;
    case 0x80137000u: goto label_80137000;
    case 0x80137004u: goto label_80137004;
    case 0x80137008u: goto label_80137008;
    case 0x8013700Cu: goto label_8013700C;
    case 0x80137010u: goto label_80137010;
    case 0x80137014u: goto label_80137014;
    case 0x80137018u: goto label_80137018;
    case 0x8013701Cu: goto label_8013701C;
    case 0x80137020u: goto label_80137020;
    case 0x80137024u: goto label_80137024;
    case 0x80137028u: goto label_80137028;
    case 0x8013702Cu: goto label_8013702C;
    case 0x80137030u: goto label_80137030;
    case 0x80137034u: goto label_80137034;
    case 0x80137038u: goto label_80137038;
    case 0x8013703Cu: goto label_8013703C;
    case 0x80137040u: goto label_80137040;
    case 0x80137044u: goto label_80137044;
    case 0x80137048u: goto label_80137048;
    case 0x8013704Cu: goto label_8013704C;
    case 0x80137050u: goto label_80137050;
    case 0x80137054u: goto label_80137054;
    case 0x80137058u: goto label_80137058;
    case 0x8013705Cu: goto label_8013705C;
    case 0x80137060u: goto label_80137060;
    case 0x80137064u: goto label_80137064;
    case 0x80137068u: goto label_80137068;
    case 0x8013706Cu: goto label_8013706C;
    case 0x80137070u: goto label_80137070;
    case 0x80137074u: goto label_80137074;
    case 0x80137078u: goto label_80137078;
    case 0x8013707Cu: goto label_8013707C;
    case 0x80137080u: goto label_80137080;
    case 0x80137084u: goto label_80137084;
    case 0x80137088u: goto label_80137088;
    case 0x8013708Cu: goto label_8013708C;
    case 0x80137090u: goto label_80137090;
    case 0x80137094u: goto label_80137094;
    case 0x80137098u: goto label_80137098;
    case 0x8013709Cu: goto label_8013709C;
    case 0x801370A0u: goto label_801370A0;
    case 0x801370A4u: goto label_801370A4;
    case 0x801370A8u: goto label_801370A8;
    case 0x801370ACu: goto label_801370AC;
    case 0x801370B0u: goto label_801370B0;
    case 0x801370B4u: goto label_801370B4;
    case 0x801370B8u: goto label_801370B8;
    case 0x801370BCu: goto label_801370BC;
    case 0x801370C0u: goto label_801370C0;
    case 0x801370C4u: goto label_801370C4;
    case 0x801370C8u: goto label_801370C8;
    case 0x801370CCu: goto label_801370CC;
    case 0x801370D0u: goto label_801370D0;
    case 0x801370D4u: goto label_801370D4;
    case 0x801370D8u: goto label_801370D8;
    case 0x801370DCu: goto label_801370DC;
    case 0x801370E0u: goto label_801370E0;
    case 0x801370E4u: goto label_801370E4;
    case 0x801370E8u: goto label_801370E8;
    case 0x801370ECu: goto label_801370EC;
    case 0x801370F0u: goto label_801370F0;
    case 0x801370F4u: goto label_801370F4;
    case 0x801370F8u: goto label_801370F8;
    case 0x801370FCu: goto label_801370FC;
    case 0x80137100u: goto label_80137100;
    case 0x80137104u: goto label_80137104;
    case 0x80137108u: goto label_80137108;
    case 0x8013710Cu: goto label_8013710C;
    case 0x80137110u: goto label_80137110;
    case 0x80137114u: goto label_80137114;
    case 0x80137118u: goto label_80137118;
    case 0x8013711Cu: goto label_8013711C;
    case 0x80137120u: goto label_80137120;
    case 0x80137124u: goto label_80137124;
    case 0x80137128u: goto label_80137128;
    case 0x8013712Cu: goto label_8013712C;
    case 0x80137130u: goto label_80137130;
    case 0x80137134u: goto label_80137134;
    case 0x80137138u: goto label_80137138;
    case 0x8013713Cu: goto label_8013713C;
    case 0x80137140u: goto label_80137140;
    case 0x80137144u: goto label_80137144;
    case 0x80137148u: goto label_80137148;
    case 0x8013714Cu: goto label_8013714C;
    case 0x80137150u: goto label_80137150;
    case 0x80137154u: goto label_80137154;
    case 0x80137158u: goto label_80137158;
    case 0x8013715Cu: goto label_8013715C;
    case 0x80137160u: goto label_80137160;
    case 0x80137164u: goto label_80137164;
    case 0x80137168u: goto label_80137168;
    case 0x8013716Cu: goto label_8013716C;
    case 0x80137170u: goto label_80137170;
    case 0x80137174u: goto label_80137174;
    case 0x80137178u: goto label_80137178;
    case 0x8013717Cu: goto label_8013717C;
    case 0x80137180u: goto label_80137180;
    case 0x80137184u: goto label_80137184;
    case 0x80137188u: goto label_80137188;
    case 0x8013718Cu: goto label_8013718C;
    case 0x80137190u: goto label_80137190;
    case 0x80137194u: goto label_80137194;
    case 0x80137198u: goto label_80137198;
    case 0x8013719Cu: goto label_8013719C;
    case 0x801371A0u: goto label_801371A0;
    case 0x801371A4u: goto label_801371A4;
    case 0x801371A8u: goto label_801371A8;
    case 0x801371ACu: goto label_801371AC;
    case 0x801371B0u: goto label_801371B0;
    case 0x801371B4u: goto label_801371B4;
    case 0x801371B8u: goto label_801371B8;
    case 0x801371BCu: goto label_801371BC;
    case 0x801371C0u: goto label_801371C0;
    case 0x801371C4u: goto label_801371C4;
    case 0x801371C8u: goto label_801371C8;
    case 0x801371CCu: goto label_801371CC;
    case 0x801371D0u: goto label_801371D0;
    case 0x801371D4u: goto label_801371D4;
    case 0x801371D8u: goto label_801371D8;
    case 0x801371DCu: goto label_801371DC;
    case 0x801371E0u: goto label_801371E0;
    case 0x801371E4u: goto label_801371E4;
    case 0x801371E8u: goto label_801371E8;
    case 0x801371ECu: goto label_801371EC;
    case 0x801371F0u: goto label_801371F0;
    case 0x801371F4u: goto label_801371F4;
    case 0x801371F8u: goto label_801371F8;
    case 0x801371FCu: goto label_801371FC;
    case 0x80137200u: goto label_80137200;
    case 0x80137204u: goto label_80137204;
    case 0x80137208u: goto label_80137208;
    case 0x8013720Cu: goto label_8013720C;
    case 0x80137210u: goto label_80137210;
    case 0x80137214u: goto label_80137214;
    case 0x80137218u: goto label_80137218;
    case 0x8013721Cu: goto label_8013721C;
    case 0x80137220u: goto label_80137220;
    case 0x80137224u: goto label_80137224;
    case 0x80137228u: goto label_80137228;
    case 0x8013722Cu: goto label_8013722C;
    case 0x80137230u: goto label_80137230;
    case 0x80137234u: goto label_80137234;
    case 0x80137238u: goto label_80137238;
    case 0x8013723Cu: goto label_8013723C;
    case 0x80137240u: goto label_80137240;
    case 0x80137244u: goto label_80137244;
    case 0x80137248u: goto label_80137248;
    case 0x8013724Cu: goto label_8013724C;
    case 0x80137250u: goto label_80137250;
    case 0x80137254u: goto label_80137254;
    case 0x80137258u: goto label_80137258;
    case 0x8013725Cu: goto label_8013725C;
    case 0x80137260u: goto label_80137260;
    case 0x80137264u: goto label_80137264;
    case 0x80137268u: goto label_80137268;
    case 0x8013726Cu: goto label_8013726C;
    case 0x80137270u: goto label_80137270;
    case 0x80137274u: goto label_80137274;
    case 0x80137278u: goto label_80137278;
    case 0x8013727Cu: goto label_8013727C;
    case 0x80137280u: goto label_80137280;
    case 0x80137284u: goto label_80137284;
    case 0x80137288u: goto label_80137288;
    case 0x8013728Cu: goto label_8013728C;
    case 0x80137290u: goto label_80137290;
    case 0x80137294u: goto label_80137294;
    case 0x80137298u: goto label_80137298;
    case 0x8013729Cu: goto label_8013729C;
    case 0x801372A0u: goto label_801372A0;
    case 0x801372A4u: goto label_801372A4;
    case 0x801372A8u: goto label_801372A8;
    case 0x801372ACu: goto label_801372AC;
    case 0x801372B0u: goto label_801372B0;
    case 0x801372B4u: goto label_801372B4;
    case 0x801372B8u: goto label_801372B8;
    case 0x801372BCu: goto label_801372BC;
    default: return;
    }
label_801332C0:
    ctx->pc = 0x801332C0u;
    ctx->downcount -= 5;
    // 801332C0: fadds   f31, f31, f13
    if (!ppc_fp_available(ctx, 0x801332C0u)) return;
    ppc_fadds(ctx, 31, 31, 13);

label_801332C4:
    ctx->pc = 0x801332C4u;
    // 801332C4: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x801332C4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801332C8:
    ctx->pc = 0x801332C8u;
    // 801332C8: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x801332C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801332CC:
    ctx->pc = 0x801332CCu;
    // 801332CC: lwz     r28, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_801332D0:
    ctx->pc = 0x801332D0u;
    // 801332D0: bl      0x80046B00
    {
            ctx->lr = 0x801332D4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801332D4:
    ctx->pc = 0x801332D4u;
    ctx->downcount -= 5;
    // 801332D4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801332D8:
    ctx->pc = 0x801332D8u;
    // 801332D8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801332DC:
    ctx->pc = 0x801332DCu;
    // 801332DC: addi    r3, r26, -19280
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(-19280);

label_801332E0:
    ctx->pc = 0x801332E0u;
    // 801332E0: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801332E4:
    ctx->pc = 0x801332E4u;
    // 801332E4: bl      0x80034E9C
    {
            ctx->lr = 0x801332E8u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801332E8:
    ctx->pc = 0x801332E8u;
    ctx->downcount -= 11;
    // 801332E8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801332EC:
    ctx->pc = 0x801332ECu;
    // 801332EC: lfs     f13, 5684(r9)
    if (!ppc_fp_available(ctx, 0x801332ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5684);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801332F0:
    ctx->pc = 0x801332F0u;
    // 801332F0: addi    r6, r13, -30068
    ctx->gpr[6] = ctx->gpr[13] + (u32)(s32)(-30068);

label_801332F4:
    ctx->pc = 0x801332F4u;
    // 801332F4: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801332F8:
    ctx->pc = 0x801332F8u;
    // 801332F8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801332FC:
    ctx->pc = 0x801332FCu;
    // 801332FC: fadds   f30, f30, f13
    if (!ppc_fp_available(ctx, 0x801332FCu)) return;
    ppc_fadds(ctx, 30, 30, 13);

label_80133300:
    ctx->pc = 0x80133300u;
    // 80133300: fctiwz    f0, f30
    if (!ppc_fp_available(ctx, 0x80133300u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[30], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80133304:
    ctx->pc = 0x80133304u;
    // 80133304: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x80133304u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80133308:
    ctx->pc = 0x80133308u;
    // 80133308: lwz     r30, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8013330C:
    ctx->pc = 0x8013330Cu;
    // 8013330C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80133310:
    ctx->pc = 0x80133310u;
    // 80133310: bl      0x80034E9C
    {
            ctx->lr = 0x80133314u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80133314:
    ctx->pc = 0x80133314u;
    ctx->downcount -= 3;
    // 80133314: li      r4, 4191
    ctx->gpr[4] = (u32)(s32)(4191);

label_80133318:
    ctx->pc = 0x80133318u;
    // 80133318: addi    r3, r25, 9872
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(9872);

label_8013331C:
    ctx->pc = 0x8013331Cu;
    // 8013331C: bl      0x80046B00
    {
            ctx->lr = 0x80133320u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80133320:
    ctx->pc = 0x80133320u;
    ctx->downcount -= 5;
    // 80133320: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80133324:
    ctx->pc = 0x80133324u;
    // 80133324: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80133328:
    ctx->pc = 0x80133328u;
    // 80133328: addi    r3, r26, -19280
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(-19280);

label_8013332C:
    ctx->pc = 0x8013332Cu;
    // 8013332C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80133330:
    ctx->pc = 0x80133330u;
    // 80133330: bl      0x80034E9C
    {
            ctx->lr = 0x80133334u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80133334:
    ctx->pc = 0x80133334u;
    ctx->downcount -= 4;
    // 80133334: lfs     f2, 4(r24)
    if (!ppc_fp_available(ctx, 0x80133334u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80133338:
    ctx->pc = 0x80133338u;
    // 80133338: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013333C:
    ctx->pc = 0x8013333Cu;
    // 8013333C: lfs     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x8013333Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133340:
    ctx->pc = 0x80133340u;
    // 80133340: bl      0x80034E6C
    {
            ctx->lr = 0x80133344u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80133344:
    ctx->pc = 0x80133344u;
    ctx->downcount -= 18;
    // 80133344: lwz     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133348:
    ctx->pc = 0x80133348u;
    // 80133348: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013334C:
    ctx->pc = 0x8013334Cu;
    // 8013334C: lmw     r24, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 24; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80133350:
    ctx->pc = 0x80133350u;
    // 80133350: lfd     f30, 56(r1)
    if (!ppc_fp_available(ctx, 0x80133350u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80133354:
    ctx->pc = 0x80133354u;
    // 80133354: lfd     f31, 64(r1)
    if (!ppc_fp_available(ctx, 0x80133354u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80133358:
    ctx->pc = 0x80133358u;
    // 80133358: addi    r1, r1, 72
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(72);

label_8013335C:
    ctx->pc = 0x8013335Cu;
    // 8013335C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133360:
    ctx->pc = 0x80133360u;
    ctx->downcount -= 25;
    // 80133360: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133364:
    ctx->pc = 0x80133364u;
    // 80133364: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133368:
    ctx->pc = 0x80133368u;
    // 80133368: stfd     f30, 48(r1)
    if (!ppc_fp_available(ctx, 0x80133368u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8013336C:
    ctx->pc = 0x8013336Cu;
    // 8013336C: stfd     f31, 56(r1)
    if (!ppc_fp_available(ctx, 0x8013336Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80133370:
    ctx->pc = 0x80133370u;
    // 80133370: stmw     r24, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 24; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80133374:
    ctx->pc = 0x80133374u;
    // 80133374: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133378:
    ctx->pc = 0x80133378u;
    // 80133378: fmr    f30, f1
    if (!ppc_fp_available(ctx, 0x80133378u)) return;
    ctx->fpr[30] = ctx->fpr[1];

label_8013337C:
    ctx->pc = 0x8013337Cu;
    // 8013337C: lis     r24, -32737
    ctx->gpr[24] = ((u32)(s32)(-32737) << 16);

label_80133380:
    ctx->pc = 0x80133380u;
    // 80133380: lfs     f1, 5688(r24)
    if (!ppc_fp_available(ctx, 0x80133380u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(5688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133384:
    ctx->pc = 0x80133384u;
    // 80133384: lis     r28, -32697
    ctx->gpr[28] = ((u32)(s32)(-32697) << 16);

label_80133388:
    ctx->pc = 0x80133388u;
    // 80133388: fmr    f31, f2
    if (!ppc_fp_available(ctx, 0x80133388u)) return;
    ctx->fpr[31] = ctx->fpr[2];

label_8013338C:
    ctx->pc = 0x8013338Cu;
    // 8013338C: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133390:
    ctx->pc = 0x80133390u;
    // 80133390: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80133390u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80133394:
    ctx->pc = 0x80133394u;
    // 80133394: lis     r27, -32737
    ctx->gpr[27] = ((u32)(s32)(-32737) << 16);

label_80133398:
    ctx->pc = 0x80133398u;
    // 80133398: bl      0x80034E6C
    {
            ctx->lr = 0x8013339Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013339C:
    ctx->pc = 0x8013339Cu;
    ctx->downcount -= 6;
    // 8013339C: lis     r26, -32735
    ctx->gpr[26] = ((u32)(s32)(-32735) << 16);

label_801333A0:
    ctx->pc = 0x801333A0u;
    // 801333A0: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_801333A4:
    ctx->pc = 0x801333A4u;
    // 801333A4: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_801333A8:
    ctx->pc = 0x801333A8u;
    // 801333A8: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_801333AC:
    ctx->pc = 0x801333ACu;
    // 801333AC: lis     r25, -32698
    ctx->gpr[25] = ((u32)(s32)(-32698) << 16);

label_801333B0:
    ctx->pc = 0x801333B0u;
    // 801333B0: bl      0x80034BA8
    {
            ctx->lr = 0x801333B4u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801333B4:
    ctx->pc = 0x801333B4u;
    ctx->downcount -= 7;
    // 801333B4: lfs     f3, 5692(r27)
    if (!ppc_fp_available(ctx, 0x801333B4u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(5692);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_801333B8:
    ctx->pc = 0x801333B8u;
    // 801333B8: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_801333BC:
    ctx->pc = 0x801333BCu;
    // 801333BC: fmr    f2, f31
    if (!ppc_fp_available(ctx, 0x801333BCu)) return;
    ctx->fpr[2] = ctx->fpr[31];

label_801333C0:
    ctx->pc = 0x801333C0u;
    // 801333C0: addi    r4, r26, -26200
    ctx->gpr[4] = ctx->gpr[26] + (u32)(s32)(-26200);

label_801333C4:
    ctx->pc = 0x801333C4u;
    // 801333C4: fmr    f1, f30
    if (!ppc_fp_available(ctx, 0x801333C4u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_801333C8:
    ctx->pc = 0x801333C8u;
    // 801333C8: ori     r3, r3, 0x010F
    ctx->gpr[3] = ctx->gpr[3] | 0x010Fu;

label_801333CC:
    ctx->pc = 0x801333CCu;
    // 801333CC: bl      0x800B7AD8
    {
            ctx->lr = 0x801333D0u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_801333D0:
    ctx->pc = 0x801333D0u;
    ctx->downcount -= 15;
    // 801333D0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801333D4:
    ctx->pc = 0x801333D4u;
    // 801333D4: lfs     f0, 5696(r9)
    if (!ppc_fp_available(ctx, 0x801333D4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5696);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801333D8:
    ctx->pc = 0x801333D8u;
    // 801333D8: fmr    f11, f31
    if (!ppc_fp_available(ctx, 0x801333D8u)) return;
    ctx->fpr[11] = ctx->fpr[31];

label_801333DC:
    ctx->pc = 0x801333DCu;
    // 801333DC: or   r30, r29, r29
    {
        ctx->gpr[30] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801333E0:
    ctx->pc = 0x801333E0u;
    // 801333E0: fctiwz    f12, f11
    if (!ppc_fp_available(ctx, 0x801333E0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[11], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_801333E4:
    ctx->pc = 0x801333E4u;
    // 801333E4: fadds   f0, f30, f0
    if (!ppc_fp_available(ctx, 0x801333E4u)) return;
    ppc_fadds(ctx, 0, 30, 0);

label_801333E8:
    ctx->pc = 0x801333E8u;
    // 801333E8: stw     r3, -30080(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30080);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801333EC:
    ctx->pc = 0x801333ECu;
    // 801333EC: li      r4, 4238
    ctx->gpr[4] = (u32)(s32)(4238);

label_801333F0:
    ctx->pc = 0x801333F0u;
    // 801333F0: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x801333F0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_801333F4:
    ctx->pc = 0x801333F4u;
    // 801333F4: addi    r3, r25, 9872
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(9872);

label_801333F8:
    ctx->pc = 0x801333F8u;
    // 801333F8: stfd     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x801333F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_801333FC:
    ctx->pc = 0x801333FCu;
    // 801333FC: lwz     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80133400:
    ctx->pc = 0x80133400u;
    // 80133400: stfd     f12, 8(r1)
    if (!ppc_fp_available(ctx, 0x80133400u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_80133404:
    ctx->pc = 0x80133404u;
    // 80133404: lwz     r30, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80133408:
    ctx->pc = 0x80133408u;
    // 80133408: bl      0x80046B00
    {
            ctx->lr = 0x8013340Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8013340C:
    ctx->pc = 0x8013340Cu;
    ctx->downcount -= 5;
    // 8013340C: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80133410:
    ctx->pc = 0x80133410u;
    // 80133410: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80133414:
    ctx->pc = 0x80133414u;
    // 80133414: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133418:
    ctx->pc = 0x80133418u;
    // 80133418: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013341C:
    ctx->pc = 0x8013341Cu;
    // 8013341C: bl      0x80034E9C
    {
            ctx->lr = 0x80133420u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80133420:
    ctx->pc = 0x80133420u;
    ctx->downcount -= 10;
    // 80133420: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133424:
    ctx->pc = 0x80133424u;
    // 80133424: lfs     f3, 5692(r27)
    if (!ppc_fp_available(ctx, 0x80133424u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(5692);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_80133428:
    ctx->pc = 0x80133428u;
    // 80133428: lfs     f0, 5700(r9)
    if (!ppc_fp_available(ctx, 0x80133428u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5700);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8013342C:
    ctx->pc = 0x8013342Cu;
    // 8013342C: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_80133430:
    ctx->pc = 0x80133430u;
    // 80133430: fmr    f1, f30
    if (!ppc_fp_available(ctx, 0x80133430u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_80133434:
    ctx->pc = 0x80133434u;
    // 80133434: addi    r4, r26, -26200
    ctx->gpr[4] = ctx->gpr[26] + (u32)(s32)(-26200);

label_80133438:
    ctx->pc = 0x80133438u;
    // 80133438: fadds   f31, f31, f0
    if (!ppc_fp_available(ctx, 0x80133438u)) return;
    ppc_fadds(ctx, 31, 31, 0);

label_8013343C:
    ctx->pc = 0x8013343Cu;
    // 8013343C: ori     r3, r3, 0x0110
    ctx->gpr[3] = ctx->gpr[3] | 0x0110u;

label_80133440:
    ctx->pc = 0x80133440u;
    // 80133440: fmr    f2, f31
    if (!ppc_fp_available(ctx, 0x80133440u)) return;
    ctx->fpr[2] = ctx->fpr[31];

label_80133444:
    ctx->pc = 0x80133444u;
    // 80133444: bl      0x800B7AD8
    {
            ctx->lr = 0x80133448u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_80133448:
    ctx->pc = 0x80133448u;
    ctx->downcount -= 7;
    // 80133448: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80133448u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8013344C:
    ctx->pc = 0x8013344Cu;
    // 8013344C: stw     r3, -30076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30076);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80133450:
    ctx->pc = 0x80133450u;
    // 80133450: stfd     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x80133450u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80133454:
    ctx->pc = 0x80133454u;
    // 80133454: li      r4, 4239
    ctx->gpr[4] = (u32)(s32)(4239);

label_80133458:
    ctx->pc = 0x80133458u;
    // 80133458: addi    r3, r25, 9872
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(9872);

label_8013345C:
    ctx->pc = 0x8013345Cu;
    // 8013345C: lwz     r30, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80133460:
    ctx->pc = 0x80133460u;
    // 80133460: bl      0x80046B00
    {
            ctx->lr = 0x80133464u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80133464:
    ctx->pc = 0x80133464u;
    ctx->downcount -= 5;
    // 80133464: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80133468:
    ctx->pc = 0x80133468u;
    // 80133468: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8013346C:
    ctx->pc = 0x8013346Cu;
    // 8013346C: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133470:
    ctx->pc = 0x80133470u;
    // 80133470: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80133474:
    ctx->pc = 0x80133474u;
    // 80133474: bl      0x80034E9C
    {
            ctx->lr = 0x80133478u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80133478:
    ctx->pc = 0x80133478u;
    ctx->downcount -= 4;
    // 80133478: lfs     f1, 5688(r24)
    if (!ppc_fp_available(ctx, 0x80133478u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(5688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013347C:
    ctx->pc = 0x8013347Cu;
    // 8013347C: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133480:
    ctx->pc = 0x80133480u;
    // 80133480: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80133480u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80133484:
    ctx->pc = 0x80133484u;
    // 80133484: bl      0x80034E6C
    {
            ctx->lr = 0x80133488u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80133488:
    ctx->pc = 0x80133488u;
    ctx->downcount -= 18;
    // 80133488: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013348C:
    ctx->pc = 0x8013348Cu;
    // 8013348C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133490:
    ctx->pc = 0x80133490u;
    // 80133490: lmw     r24, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 24; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80133494:
    ctx->pc = 0x80133494u;
    // 80133494: lfd     f30, 48(r1)
    if (!ppc_fp_available(ctx, 0x80133494u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80133498:
    ctx->pc = 0x80133498u;
    // 80133498: lfd     f31, 56(r1)
    if (!ppc_fp_available(ctx, 0x80133498u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8013349C:
    ctx->pc = 0x8013349Cu;
    // 8013349C: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_801334A0:
    ctx->pc = 0x801334A0u;
    // 801334A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_801334A4:
    ctx->pc = 0x801334A4u;
    ctx->downcount -= 20;
    // 801334A4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801334A8:
    ctx->pc = 0x801334A8u;
    // 801334A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801334AC:
    ctx->pc = 0x801334ACu;
    // 801334AC: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801334B0:
    ctx->pc = 0x801334B0u;
    // 801334B0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801334B4:
    ctx->pc = 0x801334B4u;
    // 801334B4: lis     r29, -32737
    ctx->gpr[29] = ((u32)(s32)(-32737) << 16);

label_801334B8:
    ctx->pc = 0x801334B8u;
    // 801334B8: lis     r30, -32697
    ctx->gpr[30] = ((u32)(s32)(-32697) << 16);

label_801334BC:
    ctx->pc = 0x801334BCu;
    // 801334BC: lfs     f1, 5704(r29)
    if (!ppc_fp_available(ctx, 0x801334BCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5704);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801334C0:
    ctx->pc = 0x801334C0u;
    // 801334C0: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801334C4:
    ctx->pc = 0x801334C4u;
    // 801334C4: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801334C4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801334C8:
    ctx->pc = 0x801334C8u;
    // 801334C8: bl      0x80034E6C
    {
            ctx->lr = 0x801334CCu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_801334CC:
    ctx->pc = 0x801334CCu;
    ctx->downcount -= 4;
    // 801334CC: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_801334D0:
    ctx->pc = 0x801334D0u;
    // 801334D0: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801334D4:
    ctx->pc = 0x801334D4u;
    // 801334D4: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_801334D8:
    ctx->pc = 0x801334D8u;
    // 801334D8: bl      0x80034BA8
    {
            ctx->lr = 0x801334DCu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801334DC:
    ctx->pc = 0x801334DCu;
    ctx->downcount -= 4;
    // 801334DC: lwz     r3, -30080(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30080);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801334E0:
    ctx->pc = 0x801334E0u;
    // 801334E0: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_801334E4:
    ctx->pc = 0x801334E4u;
    // 801334E4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801334E8:
    ctx->pc = 0x801334E8u;
    // 801334E8: bl      0x800B7D44
    {
            ctx->lr = 0x801334ECu;
            ctx->pc = 0x800B7D44u;
            return;
    }

label_801334EC:
    ctx->pc = 0x801334ECu;
    ctx->downcount -= 4;
    // 801334EC: lwz     r3, -30076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30076);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801334F0:
    ctx->pc = 0x801334F0u;
    // 801334F0: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_801334F4:
    ctx->pc = 0x801334F4u;
    // 801334F4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801334F8:
    ctx->pc = 0x801334F8u;
    // 801334F8: bl      0x800B7D44
    {
            ctx->lr = 0x801334FCu;
            ctx->pc = 0x800B7D44u;
            return;
    }

label_801334FC:
    ctx->pc = 0x801334FCu;
    ctx->downcount -= 4;
    // 801334FC: lfs     f1, 5704(r29)
    if (!ppc_fp_available(ctx, 0x801334FCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5704);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133500:
    ctx->pc = 0x80133500u;
    // 80133500: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80133504:
    ctx->pc = 0x80133504u;
    // 80133504: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80133504u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80133508:
    ctx->pc = 0x80133508u;
    // 80133508: bl      0x80034E6C
    {
            ctx->lr = 0x8013350Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013350C:
    ctx->pc = 0x8013350Cu;
    ctx->downcount -= 16;
    // 8013350C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133510:
    ctx->pc = 0x80133510u;
    // 80133510: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133514:
    ctx->pc = 0x80133514u;
    // 80133514: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80133518:
    ctx->pc = 0x80133518u;
    // 80133518: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8013351C:
    ctx->pc = 0x8013351Cu;
    // 8013351C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133520:
    ctx->pc = 0x80133520u;
    ctx->downcount -= 25;
    // 80133520: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133524:
    ctx->pc = 0x80133524u;
    // 80133524: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133528:
    ctx->pc = 0x80133528u;
    // 80133528: stfd     f30, 48(r1)
    if (!ppc_fp_available(ctx, 0x80133528u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8013352C:
    ctx->pc = 0x8013352Cu;
    // 8013352C: stfd     f31, 56(r1)
    if (!ppc_fp_available(ctx, 0x8013352Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80133530:
    ctx->pc = 0x80133530u;
    // 80133530: stmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80133534:
    ctx->pc = 0x80133534u;
    // 80133534: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133538:
    ctx->pc = 0x80133538u;
    // 80133538: fmr    f30, f1
    if (!ppc_fp_available(ctx, 0x80133538u)) return;
    ctx->fpr[30] = ctx->fpr[1];

label_8013353C:
    ctx->pc = 0x8013353Cu;
    // 8013353C: lis     r30, -32737
    ctx->gpr[30] = ((u32)(s32)(-32737) << 16);

label_80133540:
    ctx->pc = 0x80133540u;
    // 80133540: lfs     f1, 5708(r30)
    if (!ppc_fp_available(ctx, 0x80133540u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(5708);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133544:
    ctx->pc = 0x80133544u;
    // 80133544: lis     r27, -32697
    ctx->gpr[27] = ((u32)(s32)(-32697) << 16);

label_80133548:
    ctx->pc = 0x80133548u;
    // 80133548: fmr    f31, f2
    if (!ppc_fp_available(ctx, 0x80133548u)) return;
    ctx->fpr[31] = ctx->fpr[2];

label_8013354C:
    ctx->pc = 0x8013354Cu;
    // 8013354C: addi    r26, r1, 8
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(8);

label_80133550:
    ctx->pc = 0x80133550u;
    // 80133550: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80133550u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80133554:
    ctx->pc = 0x80133554u;
    // 80133554: addi    r3, r27, -19280
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(-19280);

label_80133558:
    ctx->pc = 0x80133558u;
    // 80133558: bl      0x80034E6C
    {
            ctx->lr = 0x8013355Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013355C:
    ctx->pc = 0x8013355Cu;
    ctx->downcount -= 4;
    // 8013355C: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_80133560:
    ctx->pc = 0x80133560u;
    // 80133560: addi    r3, r27, -19280
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(-19280);

label_80133564:
    ctx->pc = 0x80133564u;
    // 80133564: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_80133568:
    ctx->pc = 0x80133568u;
    // 80133568: bl      0x80034BA8
    {
            ctx->lr = 0x8013356Cu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8013356C:
    ctx->pc = 0x8013356Cu;
    ctx->downcount -= 7;
    // 8013356C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133570:
    ctx->pc = 0x80133570u;
    // 80133570: lfs     f1, 5708(r30)
    if (!ppc_fp_available(ctx, 0x80133570u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(5708);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133574:
    ctx->pc = 0x80133574u;
    // 80133574: lfs     f0, 5712(r9)
    if (!ppc_fp_available(ctx, 0x80133574u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5712);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80133578:
    ctx->pc = 0x80133578u;
    // 80133578: addi    r3, r27, -19280
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(-19280);

label_8013357C:
    ctx->pc = 0x8013357Cu;
    // 8013357C: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x8013357Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80133580:
    ctx->pc = 0x80133580u;
    // 80133580: fadds   f31, f31, f0
    if (!ppc_fp_available(ctx, 0x80133580u)) return;
    ppc_fadds(ctx, 31, 31, 0);

label_80133584:
    ctx->pc = 0x80133584u;
    // 80133584: bl      0x80034E6C
    {
            ctx->lr = 0x80133588u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80133588:
    ctx->pc = 0x80133588u;
    ctx->downcount -= 4;
    // 80133588: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_8013358C:
    ctx->pc = 0x8013358Cu;
    // 8013358C: addi    r3, r27, -19280
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(-19280);

label_80133590:
    ctx->pc = 0x80133590u;
    // 80133590: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_80133594:
    ctx->pc = 0x80133594u;
    // 80133594: bl      0x80034BA8
    {
            ctx->lr = 0x80133598u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80133598:
    ctx->pc = 0x80133598u;
    ctx->downcount -= 10;
    // 80133598: lis     r29, -32698
    ctx->gpr[29] = ((u32)(s32)(-32698) << 16);

label_8013359C:
    ctx->pc = 0x8013359Cu;
    // 8013359C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801335A0:
    ctx->pc = 0x801335A0u;
    // 801335A0: addi    r29, r29, 11668
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(11668);

label_801335A4:
    ctx->pc = 0x801335A4u;
    // 801335A4: lfs     f1, 5716(r9)
    if (!ppc_fp_available(ctx, 0x801335A4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5716);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801335A8:
    ctx->pc = 0x801335A8u;
    // 801335A8: lfs     f13, 148(r29)
    if (!ppc_fp_available(ctx, 0x801335A8u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(148);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801335AC:
    ctx->pc = 0x801335ACu;
    // 801335AC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801335B0:
    ctx->pc = 0x801335B0u;
    // 801335B0: lfs     f0, 152(r29)
    if (!ppc_fp_available(ctx, 0x801335B0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(152);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801335B4:
    ctx->pc = 0x801335B4u;
    // 801335B4: stfs     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x801335B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801335B8:
    ctx->pc = 0x801335B8u;
    // 801335B8: stfs     f0, 4(r26)
    if (!ppc_fp_available(ctx, 0x801335B8u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801335BC:
    ctx->pc = 0x801335BCu;
    // 801335BC: bl      0x80034E48
    {
            ctx->lr = 0x801335C0u;
            ctx->pc = 0x80034E48u;
            return;
    }

label_801335C0:
    ctx->pc = 0x801335C0u;
    ctx->downcount -= 12;
    // 801335C0: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x801335C0u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_801335C4:
    ctx->pc = 0x801335C4u;
    // 801335C4: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x801335C4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_801335C8:
    ctx->pc = 0x801335C8u;
    // 801335C8: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801335CC:
    ctx->pc = 0x801335CCu;
    // 801335CC: stfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x801335CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_801335D0:
    ctx->pc = 0x801335D0u;
    // 801335D0: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x801335D0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801335D4:
    ctx->pc = 0x801335D4u;
    // 801335D4: addi    r6, r13, -30064
    ctx->gpr[6] = ctx->gpr[13] + (u32)(s32)(-30064);

label_801335D8:
    ctx->pc = 0x801335D8u;
    // 801335D8: lwz     r4, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801335DC:
    ctx->pc = 0x801335DCu;
    // 801335DC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801335E0:
    ctx->pc = 0x801335E0u;
    // 801335E0: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x801335E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801335E4:
    ctx->pc = 0x801335E4u;
    // 801335E4: lwz     r28, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_801335E8:
    ctx->pc = 0x801335E8u;
    // 801335E8: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801335EC:
    ctx->pc = 0x801335ECu;
    // 801335EC: bl      0x80034E9C
    {
            ctx->lr = 0x801335F0u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801335F0:
    ctx->pc = 0x801335F0u;
    ctx->downcount -= 10;
    // 801335F0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801335F4:
    ctx->pc = 0x801335F4u;
    // 801335F4: lfs     f13, 5720(r9)
    if (!ppc_fp_available(ctx, 0x801335F4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5720);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801335F8:
    ctx->pc = 0x801335F8u;
    // 801335F8: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801335FC:
    ctx->pc = 0x801335FCu;
    // 801335FC: li      r4, 4191
    ctx->gpr[4] = (u32)(s32)(4191);

label_80133600:
    ctx->pc = 0x80133600u;
    // 80133600: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_80133604:
    ctx->pc = 0x80133604u;
    // 80133604: fadds   f30, f30, f13
    if (!ppc_fp_available(ctx, 0x80133604u)) return;
    ppc_fadds(ctx, 30, 30, 13);

label_80133608:
    ctx->pc = 0x80133608u;
    // 80133608: fctiwz    f0, f30
    if (!ppc_fp_available(ctx, 0x80133608u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[30], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8013360C:
    ctx->pc = 0x8013360Cu;
    // 8013360C: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8013360Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80133610:
    ctx->pc = 0x80133610u;
    // 80133610: lwz     r30, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80133614:
    ctx->pc = 0x80133614u;
    // 80133614: bl      0x80046B00
    {
            ctx->lr = 0x80133618u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80133618:
    ctx->pc = 0x80133618u;
    ctx->downcount -= 5;
    // 80133618: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013361C:
    ctx->pc = 0x8013361Cu;
    // 8013361C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80133620:
    ctx->pc = 0x80133620u;
    // 80133620: addi    r3, r27, -19280
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(-19280);

label_80133624:
    ctx->pc = 0x80133624u;
    // 80133624: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80133628:
    ctx->pc = 0x80133628u;
    // 80133628: bl      0x80034E9C
    {
            ctx->lr = 0x8013362Cu;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8013362C:
    ctx->pc = 0x8013362Cu;
    ctx->downcount -= 4;
    // 8013362C: lfs     f2, 4(r26)
    if (!ppc_fp_available(ctx, 0x8013362Cu)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80133630:
    ctx->pc = 0x80133630u;
    // 80133630: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80133634:
    ctx->pc = 0x80133634u;
    // 80133634: lfs     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x80133634u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133638:
    ctx->pc = 0x80133638u;
    // 80133638: bl      0x80034E6C
    {
            ctx->lr = 0x8013363Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013363C:
    ctx->pc = 0x8013363Cu;
    ctx->downcount -= 18;
    // 8013363C: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133640:
    ctx->pc = 0x80133640u;
    // 80133640: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133644:
    ctx->pc = 0x80133644u;
    // 80133644: lmw     r26, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80133648:
    ctx->pc = 0x80133648u;
    // 80133648: lfd     f30, 48(r1)
    if (!ppc_fp_available(ctx, 0x80133648u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8013364C:
    ctx->pc = 0x8013364Cu;
    // 8013364C: lfd     f31, 56(r1)
    if (!ppc_fp_available(ctx, 0x8013364Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80133650:
    ctx->pc = 0x80133650u;
    // 80133650: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_80133654:
    ctx->pc = 0x80133654u;
    // 80133654: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133658:
    ctx->pc = 0x80133658u;
    ctx->downcount -= 24;
    // 80133658: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013365C:
    ctx->pc = 0x8013365Cu;
    // 8013365C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133660:
    ctx->pc = 0x80133660u;
    // 80133660: stfd     f30, 32(r1)
    if (!ppc_fp_available(ctx, 0x80133660u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80133664:
    ctx->pc = 0x80133664u;
    // 80133664: stfd     f31, 40(r1)
    if (!ppc_fp_available(ctx, 0x80133664u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80133668:
    ctx->pc = 0x80133668u;
    // 80133668: stmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8013366C:
    ctx->pc = 0x8013366Cu;
    // 8013366C: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133670:
    ctx->pc = 0x80133670u;
    // 80133670: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133674:
    ctx->pc = 0x80133674u;
    // 80133674: fmr    f31, f1
    if (!ppc_fp_available(ctx, 0x80133674u)) return;
    ctx->fpr[31] = ctx->fpr[1];

label_80133678:
    ctx->pc = 0x80133678u;
    // 80133678: lfs     f1, 5724(r9)
    if (!ppc_fp_available(ctx, 0x80133678u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5724);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013367C:
    ctx->pc = 0x8013367Cu;
    // 8013367C: fmr    f30, f2
    if (!ppc_fp_available(ctx, 0x8013367Cu)) return;
    ctx->fpr[30] = ctx->fpr[2];

label_80133680:
    ctx->pc = 0x80133680u;
    // 80133680: lis     r28, -32697
    ctx->gpr[28] = ((u32)(s32)(-32697) << 16);

label_80133684:
    ctx->pc = 0x80133684u;
    // 80133684: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80133684u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80133688:
    ctx->pc = 0x80133688u;
    // 80133688: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_8013368C:
    ctx->pc = 0x8013368Cu;
    // 8013368C: bl      0x80034E6C
    {
            ctx->lr = 0x80133690u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80133690:
    ctx->pc = 0x80133690u;
    ctx->downcount -= 4;
    // 80133690: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_80133694:
    ctx->pc = 0x80133694u;
    // 80133694: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133698:
    ctx->pc = 0x80133698u;
    // 80133698: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_8013369C:
    ctx->pc = 0x8013369Cu;
    // 8013369C: bl      0x80034BA8
    {
            ctx->lr = 0x801336A0u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801336A0:
    ctx->pc = 0x801336A0u;
    ctx->downcount -= 9;
    // 801336A0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801336A4:
    ctx->pc = 0x801336A4u;
    // 801336A4: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_801336A8:
    ctx->pc = 0x801336A8u;
    // 801336A8: lfs     f3, 5728(r9)
    if (!ppc_fp_available(ctx, 0x801336A8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5728);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_801336AC:
    ctx->pc = 0x801336ACu;
    // 801336AC: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_801336B0:
    ctx->pc = 0x801336B0u;
    // 801336B0: fmr    f1, f31
    if (!ppc_fp_available(ctx, 0x801336B0u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801336B4:
    ctx->pc = 0x801336B4u;
    // 801336B4: addi    r4, r4, -26200
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-26200);

label_801336B8:
    ctx->pc = 0x801336B8u;
    // 801336B8: fmr    f2, f30
    if (!ppc_fp_available(ctx, 0x801336B8u)) return;
    ctx->fpr[2] = ctx->fpr[30];

label_801336BC:
    ctx->pc = 0x801336BCu;
    // 801336BC: ori     r3, r3, 0x010D
    ctx->gpr[3] = ctx->gpr[3] | 0x010Du;

label_801336C0:
    ctx->pc = 0x801336C0u;
    // 801336C0: bl      0x800B7AD8
    {
            ctx->lr = 0x801336C4u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_801336C4:
    ctx->pc = 0x801336C4u;
    ctx->downcount -= 14;
    // 801336C4: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801336C8:
    ctx->pc = 0x801336C8u;
    // 801336C8: lfs     f12, 5732(r9)
    if (!ppc_fp_available(ctx, 0x801336C8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5732);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_801336CC:
    ctx->pc = 0x801336CCu;
    // 801336CC: or   r30, r29, r29
    {
        ctx->gpr[30] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801336D0:
    ctx->pc = 0x801336D0u;
    // 801336D0: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801336D4:
    ctx->pc = 0x801336D4u;
    // 801336D4: fadds   f31, f31, f12
    if (!ppc_fp_available(ctx, 0x801336D4u)) return;
    ppc_fadds(ctx, 31, 31, 12);

label_801336D8:
    ctx->pc = 0x801336D8u;
    // 801336D8: li      r4, 3592
    ctx->gpr[4] = (u32)(s32)(3592);

label_801336DC:
    ctx->pc = 0x801336DCu;
    // 801336DC: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_801336E0:
    ctx->pc = 0x801336E0u;
    // 801336E0: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x801336E0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801336E4:
    ctx->pc = 0x801336E4u;
    // 801336E4: stfd     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x801336E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801336E8:
    ctx->pc = 0x801336E8u;
    // 801336E8: fctiwz    f13, f30
    if (!ppc_fp_available(ctx, 0x801336E8u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[30], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_801336EC:
    ctx->pc = 0x801336ECu;
    // 801336EC: lwz     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801336F0:
    ctx->pc = 0x801336F0u;
    // 801336F0: stfd     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x801336F0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_801336F4:
    ctx->pc = 0x801336F4u;
    // 801336F4: lwz     r30, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801336F8:
    ctx->pc = 0x801336F8u;
    // 801336F8: bl      0x80046B00
    {
            ctx->lr = 0x801336FCu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801336FC:
    ctx->pc = 0x801336FCu;
    ctx->downcount -= 5;
    // 801336FC: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80133700:
    ctx->pc = 0x80133700u;
    // 80133700: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80133704:
    ctx->pc = 0x80133704u;
    // 80133704: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133708:
    ctx->pc = 0x80133708u;
    // 80133708: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013370C:
    ctx->pc = 0x8013370Cu;
    // 8013370C: bl      0x80034E9C
    {
            ctx->lr = 0x80133710u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80133710:
    ctx->pc = 0x80133710u;
    ctx->downcount -= 18;
    // 80133710: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133714:
    ctx->pc = 0x80133714u;
    // 80133714: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133718:
    ctx->pc = 0x80133718u;
    // 80133718: lmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8013371C:
    ctx->pc = 0x8013371Cu;
    // 8013371C: lfd     f30, 32(r1)
    if (!ppc_fp_available(ctx, 0x8013371Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80133720:
    ctx->pc = 0x80133720u;
    // 80133720: lfd     f31, 40(r1)
    if (!ppc_fp_available(ctx, 0x80133720u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80133724:
    ctx->pc = 0x80133724u;
    // 80133724: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80133728:
    ctx->pc = 0x80133728u;
    // 80133728: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_8013372C:
    ctx->pc = 0x8013372Cu;
    ctx->downcount -= 25;
    // 8013372C: stwu     r1, -72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-72);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133730:
    ctx->pc = 0x80133730u;
    // 80133730: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133734:
    ctx->pc = 0x80133734u;
    // 80133734: stfd     f30, 56(r1)
    if (!ppc_fp_available(ctx, 0x80133734u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80133738:
    ctx->pc = 0x80133738u;
    // 80133738: stfd     f31, 64(r1)
    if (!ppc_fp_available(ctx, 0x80133738u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8013373C:
    ctx->pc = 0x8013373Cu;
    // 8013373C: stmw     r25, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80133740:
    ctx->pc = 0x80133740u;
    // 80133740: stw     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133744:
    ctx->pc = 0x80133744u;
    // 80133744: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133748:
    ctx->pc = 0x80133748u;
    // 80133748: fmr    f30, f1
    if (!ppc_fp_available(ctx, 0x80133748u)) return;
    ctx->fpr[30] = ctx->fpr[1];

label_8013374C:
    ctx->pc = 0x8013374Cu;
    // 8013374C: lfs     f1, 5736(r9)
    if (!ppc_fp_available(ctx, 0x8013374Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5736);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133750:
    ctx->pc = 0x80133750u;
    // 80133750: fmr    f31, f2
    if (!ppc_fp_available(ctx, 0x80133750u)) return;
    ctx->fpr[31] = ctx->fpr[2];

label_80133754:
    ctx->pc = 0x80133754u;
    // 80133754: lis     r28, -32697
    ctx->gpr[28] = ((u32)(s32)(-32697) << 16);

label_80133758:
    ctx->pc = 0x80133758u;
    // 80133758: lis     r26, -32737
    ctx->gpr[26] = ((u32)(s32)(-32737) << 16);

label_8013375C:
    ctx->pc = 0x8013375Cu;
    // 8013375C: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x8013375Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80133760:
    ctx->pc = 0x80133760u;
    // 80133760: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133764:
    ctx->pc = 0x80133764u;
    // 80133764: bl      0x80034E6C
    {
            ctx->lr = 0x80133768u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80133768:
    ctx->pc = 0x80133768u;
    ctx->downcount -= 6;
    // 80133768: lis     r27, -32735
    ctx->gpr[27] = ((u32)(s32)(-32735) << 16);

label_8013376C:
    ctx->pc = 0x8013376Cu;
    // 8013376C: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_80133770:
    ctx->pc = 0x80133770u;
    // 80133770: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133774:
    ctx->pc = 0x80133774u;
    // 80133774: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_80133778:
    ctx->pc = 0x80133778u;
    // 80133778: lis     r25, -32698
    ctx->gpr[25] = ((u32)(s32)(-32698) << 16);

label_8013377C:
    ctx->pc = 0x8013377Cu;
    // 8013377C: bl      0x80034BA8
    {
            ctx->lr = 0x80133780u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80133780:
    ctx->pc = 0x80133780u;
    ctx->downcount -= 7;
    // 80133780: lfs     f3, 5740(r26)
    if (!ppc_fp_available(ctx, 0x80133780u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(5740);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_80133784:
    ctx->pc = 0x80133784u;
    // 80133784: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_80133788:
    ctx->pc = 0x80133788u;
    // 80133788: fmr    f2, f31
    if (!ppc_fp_available(ctx, 0x80133788u)) return;
    ctx->fpr[2] = ctx->fpr[31];

label_8013378C:
    ctx->pc = 0x8013378Cu;
    // 8013378C: addi    r4, r27, -26200
    ctx->gpr[4] = ctx->gpr[27] + (u32)(s32)(-26200);

label_80133790:
    ctx->pc = 0x80133790u;
    // 80133790: fmr    f1, f30
    if (!ppc_fp_available(ctx, 0x80133790u)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_80133794:
    ctx->pc = 0x80133794u;
    // 80133794: ori     r3, r3, 0x010D
    ctx->gpr[3] = ctx->gpr[3] | 0x010Du;

label_80133798:
    ctx->pc = 0x80133798u;
    // 80133798: bl      0x800B7AD8
    {
            ctx->lr = 0x8013379Cu;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_8013379C:
    ctx->pc = 0x8013379Cu;
    ctx->downcount -= 14;
    // 8013379C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801337A0:
    ctx->pc = 0x801337A0u;
    // 801337A0: lfs     f0, 5744(r9)
    if (!ppc_fp_available(ctx, 0x801337A0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5744);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801337A4:
    ctx->pc = 0x801337A4u;
    // 801337A4: fmr    f11, f31
    if (!ppc_fp_available(ctx, 0x801337A4u)) return;
    ctx->fpr[11] = ctx->fpr[31];

label_801337A8:
    ctx->pc = 0x801337A8u;
    // 801337A8: or   r30, r29, r29
    {
        ctx->gpr[30] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801337AC:
    ctx->pc = 0x801337ACu;
    // 801337AC: fctiwz    f13, f11
    if (!ppc_fp_available(ctx, 0x801337ACu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[11], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_801337B0:
    ctx->pc = 0x801337B0u;
    // 801337B0: fadds   f0, f30, f0
    if (!ppc_fp_available(ctx, 0x801337B0u)) return;
    ppc_fadds(ctx, 0, 30, 0);

label_801337B4:
    ctx->pc = 0x801337B4u;
    // 801337B4: li      r4, 3590
    ctx->gpr[4] = (u32)(s32)(3590);

label_801337B8:
    ctx->pc = 0x801337B8u;
    // 801337B8: addi    r3, r25, 9872
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(9872);

label_801337BC:
    ctx->pc = 0x801337BCu;
    // 801337BC: fctiwz    f12, f0
    if (!ppc_fp_available(ctx, 0x801337BCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_801337C0:
    ctx->pc = 0x801337C0u;
    // 801337C0: stfd     f12, 16(r1)
    if (!ppc_fp_available(ctx, 0x801337C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_801337C4:
    ctx->pc = 0x801337C4u;
    // 801337C4: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801337C8:
    ctx->pc = 0x801337C8u;
    // 801337C8: stfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x801337C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_801337CC:
    ctx->pc = 0x801337CCu;
    // 801337CC: lwz     r30, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801337D0:
    ctx->pc = 0x801337D0u;
    // 801337D0: bl      0x80046B00
    {
            ctx->lr = 0x801337D4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801337D4:
    ctx->pc = 0x801337D4u;
    ctx->downcount -= 5;
    // 801337D4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801337D8:
    ctx->pc = 0x801337D8u;
    // 801337D8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801337DC:
    ctx->pc = 0x801337DCu;
    // 801337DC: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_801337E0:
    ctx->pc = 0x801337E0u;
    // 801337E0: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801337E4:
    ctx->pc = 0x801337E4u;
    // 801337E4: bl      0x80034E9C
    {
            ctx->lr = 0x801337E8u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801337E8:
    ctx->pc = 0x801337E8u;
    ctx->downcount -= 10;
    // 801337E8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801337EC:
    ctx->pc = 0x801337ECu;
    // 801337EC: lfs     f3, 5740(r26)
    if (!ppc_fp_available(ctx, 0x801337ECu)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(5740);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_801337F0:
    ctx->pc = 0x801337F0u;
    // 801337F0: lfs     f0, 5748(r9)
    if (!ppc_fp_available(ctx, 0x801337F0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5748);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801337F4:
    ctx->pc = 0x801337F4u;
    // 801337F4: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_801337F8:
    ctx->pc = 0x801337F8u;
    // 801337F8: addi    r4, r27, -26200
    ctx->gpr[4] = ctx->gpr[27] + (u32)(s32)(-26200);

label_801337FC:
    ctx->pc = 0x801337FCu;
    // 801337FC: fmr    f1, f30
    if (!ppc_fp_available(ctx, 0x801337FCu)) return;
    ctx->fpr[1] = ctx->fpr[30];

label_80133800:
    ctx->pc = 0x80133800u;
    // 80133800: fadds   f31, f31, f0
    if (!ppc_fp_available(ctx, 0x80133800u)) return;
    ppc_fadds(ctx, 31, 31, 0);

label_80133804:
    ctx->pc = 0x80133804u;
    // 80133804: ori     r3, r3, 0x010E
    ctx->gpr[3] = ctx->gpr[3] | 0x010Eu;

label_80133808:
    ctx->pc = 0x80133808u;
    // 80133808: fmr    f2, f31
    if (!ppc_fp_available(ctx, 0x80133808u)) return;
    ctx->fpr[2] = ctx->fpr[31];

label_8013380C:
    ctx->pc = 0x8013380Cu;
    // 8013380C: bl      0x800B7AD8
    {
            ctx->lr = 0x80133810u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_80133810:
    ctx->pc = 0x80133810u;
    ctx->downcount -= 6;
    // 80133810: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80133810u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80133814:
    ctx->pc = 0x80133814u;
    // 80133814: li      r4, 3591
    ctx->gpr[4] = (u32)(s32)(3591);

label_80133818:
    ctx->pc = 0x80133818u;
    // 80133818: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x80133818u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8013381C:
    ctx->pc = 0x8013381Cu;
    // 8013381C: addi    r3, r25, 9872
    ctx->gpr[3] = ctx->gpr[25] + (u32)(s32)(9872);

label_80133820:
    ctx->pc = 0x80133820u;
    // 80133820: lwz     r30, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80133824:
    ctx->pc = 0x80133824u;
    // 80133824: bl      0x80046B00
    {
            ctx->lr = 0x80133828u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80133828:
    ctx->pc = 0x80133828u;
    ctx->downcount -= 5;
    // 80133828: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013382C:
    ctx->pc = 0x8013382Cu;
    // 8013382C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80133830:
    ctx->pc = 0x80133830u;
    // 80133830: addi    r3, r28, -19280
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-19280);

label_80133834:
    ctx->pc = 0x80133834u;
    // 80133834: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80133838:
    ctx->pc = 0x80133838u;
    // 80133838: bl      0x80034E9C
    {
            ctx->lr = 0x8013383Cu;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8013383C:
    ctx->pc = 0x8013383Cu;
    ctx->downcount -= 18;
    // 8013383C: lwz     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133840:
    ctx->pc = 0x80133840u;
    // 80133840: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133844:
    ctx->pc = 0x80133844u;
    // 80133844: lmw     r25, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80133848:
    ctx->pc = 0x80133848u;
    // 80133848: lfd     f30, 56(r1)
    if (!ppc_fp_available(ctx, 0x80133848u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8013384C:
    ctx->pc = 0x8013384Cu;
    // 8013384C: lfd     f31, 64(r1)
    if (!ppc_fp_available(ctx, 0x8013384Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80133850:
    ctx->pc = 0x80133850u;
    // 80133850: addi    r1, r1, 72
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(72);

label_80133854:
    ctx->pc = 0x80133854u;
    // 80133854: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133858:
    ctx->pc = 0x80133858u;
    ctx->downcount -= 7;
    // 80133858: li      r11, 10
    ctx->gpr[11] = (u32)(s32)(10);

label_8013385C:
    ctx->pc = 0x8013385Cu;
    // 8013385C: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_80133860:
    ctx->pc = 0x80133860u;
    // 80133860: mtctr    r11
    ctx->ctr = ctx->gpr[11];

label_80133864:
    ctx->pc = 0x80133864u;
    // 80133864: addi    r9, r9, -18172
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-18172);

label_80133868:
    ctx->pc = 0x80133868u;
    // 80133868: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8013386C:
    ctx->pc = 0x8013386Cu;
    // 8013386C: addi    r9, r9, 36
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(36);

label_80133870:
    loop_80133870(ctx);
    if (ctx->pc == 0x8013387Cu) goto label_8013387C;
    return;
label_80133874:
    // 80133874: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_80133878:
    // 80133878: bc    16, 0, 0x80133870
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133870u;
                return;
            }
            goto label_80133870;
        }
    }

label_8013387C:
    ctx->pc = 0x8013387Cu;
    ctx->downcount -= 1;
    // 8013387C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133880:
    ctx->pc = 0x80133880u;
    ctx->downcount -= 19;
    // 80133880: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133884:
    ctx->pc = 0x80133884u;
    // 80133884: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133888:
    ctx->pc = 0x80133888u;
    // 80133888: stfd     f31, 56(r1)
    if (!ppc_fp_available(ctx, 0x80133888u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8013388C:
    ctx->pc = 0x8013388Cu;
    // 8013388C: stmw     r21, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 21; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80133890:
    ctx->pc = 0x80133890u;
    // 80133890: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133894:
    ctx->pc = 0x80133894u;
    // 80133894: lwz     r0, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133898:
    ctx->pc = 0x80133898u;
    // 80133898: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8013389C:
    ctx->pc = 0x8013389Cu;
    // 8013389C: cmpw    r29, r0
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

label_801338A0:
    ctx->pc = 0x801338A0u;
    // 801338A0: bc    4, 0, 0x8013394C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013394C;
        }
    }

label_801338A4:
    ctx->pc = 0x801338A4u;
    ctx->downcount -= 14;
    // 801338A4: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801338A8:
    ctx->pc = 0x801338A8u;
    // 801338A8: lis     r11, -32697
    ctx->gpr[11] = ((u32)(s32)(-32697) << 16);

label_801338AC:
    ctx->pc = 0x801338ACu;
    // 801338AC: lfs     f31, 5756(r9)
    if (!ppc_fp_available(ctx, 0x801338ACu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5756);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_801338B0:
    ctx->pc = 0x801338B0u;
    // 801338B0: addi    r21, r11, -18004
    ctx->gpr[21] = ctx->gpr[11] + (u32)(s32)(-18004);

label_801338B4:
    ctx->pc = 0x801338B4u;
    // 801338B4: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_801338B8:
    ctx->pc = 0x801338B8u;
    // 801338B8: lis     r11, -32697
    ctx->gpr[11] = ((u32)(s32)(-32697) << 16);

label_801338BC:
    ctx->pc = 0x801338BCu;
    // 801338BC: addi    r22, r9, 28584
    ctx->gpr[22] = ctx->gpr[9] + (u32)(s32)(28584);

label_801338C0:
    ctx->pc = 0x801338C0u;
    // 801338C0: addi    r23, r11, -18172
    ctx->gpr[23] = ctx->gpr[11] + (u32)(s32)(-18172);

label_801338C4:
    ctx->pc = 0x801338C4u;
    // 801338C4: lis     r28, -32735
    ctx->gpr[28] = ((u32)(s32)(-32735) << 16);

label_801338C8:
    ctx->pc = 0x801338C8u;
    // 801338C8: lis     r24, -32737
    ctx->gpr[24] = ((u32)(s32)(-32737) << 16);

label_801338CC:
    ctx->pc = 0x801338CCu;
    // 801338CC: li      r25, 999
    ctx->gpr[25] = (u32)(s32)(999);

label_801338D0:
    ctx->pc = 0x801338D0u;
    // 801338D0: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_801338D4:
    ctx->pc = 0x801338D4u;
    // 801338D4: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_801338D8:
    ctx->pc = 0x801338D8u;
    // 801338D8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801338DC:
    ctx->pc = 0x801338DCu;
    ctx->downcount -= 8;
    // 801338DC: lfs     f1, 5752(r24)
    if (!ppc_fp_available(ctx, 0x801338DCu)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(5752);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801338E0:
    // 801338E0: lis     r4, 16384
    ctx->gpr[4] = ((u32)(s32)(16384) << 16);

label_801338E4:
    // 801338E4: addi    r3, r28, -26200
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(-26200);

label_801338E8:
    // 801338E8: ori     r4, r4, 0x043A
    ctx->gpr[4] = ctx->gpr[4] | 0x043Au;

label_801338EC:
    ctx->pc = 0x801338ECu;
    // 801338EC: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801338ECu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801338F0:
    // 801338F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801338F4:
    ctx->pc = 0x801338F4u;
    // 801338F4: fmr    f3, f2
    if (!ppc_fp_available(ctx, 0x801338F4u)) return;
    ctx->fpr[3] = ctx->fpr[2];

label_801338F8:
    // 801338F8: bl      0x80041F40
    {
            ctx->lr = 0x801338FCu;
            ctx->pc = 0x80041F40u;
            return;
    }

label_801338FC:
    ctx->downcount -= 2;
    // 801338FC: or.   r31, r3, r3
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

label_80133900:
    // 80133900: bc    12, 2, 0x80133938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133938;
        }
    }

label_80133904:
    ctx->pc = 0x80133904u;
    ctx->downcount -= 14;
    // 80133904: stw     r25, 228(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(228);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80133908:
    // 80133908: addi    r5, r31, 208
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(208);

label_8013390C:
    ctx->pc = 0x8013390Cu;
    // 8013390C: stfs     f31, 20(r31)
    if (!ppc_fp_available(ctx, 0x8013390Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_80133910:
    // 80133910: addi    r6, r28, -26200
    ctx->gpr[6] = ctx->gpr[28] + (u32)(s32)(-26200);

label_80133914:
    ctx->pc = 0x80133914u;
    // 80133914: sth     r26, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[26]);
    }

label_80133918:
    // 80133918: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8013391C:
    ctx->pc = 0x8013391Cu;
    // 8013391C: stw     r27, 236(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(236);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80133920:
    ctx->pc = 0x80133920u;
    // 80133920: lwz     r3, 308(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(308);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80133924:
    ctx->pc = 0x80133924u;
    // 80133924: lwzx    r0, r30, r21
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[21];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133928:
    // 80133928: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_8013392C:
    ctx->pc = 0x8013392Cu;
    // 8013392C: lwzx    r4, r22, r0
    {
        u32 ea = ctx->gpr[22] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80133930:
    // 80133930: bl      0x8001A804
    {
            ctx->lr = 0x80133934u;
            ctx->pc = 0x8001A804u;
            return;
    }

label_80133934:
    ctx->pc = 0x80133934u;
    ctx->downcount -= 1;
    // 80133934: stwx    r31, r30, r23
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[23];
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80133938:
    ctx->pc = 0x80133938u;
    ctx->downcount -= 5;
    // 80133938: lwz     r0, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013393C:
    // 8013393C: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_80133940:
    // 80133940: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80133944:
    // 80133944: cmpw    r29, r0
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

label_80133948:
    // 80133948: bc    12, 0, 0x801338DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801338DCu;
                return;
            }
            goto label_801338DC;
        }
    }

label_8013394C:
    ctx->pc = 0x8013394Cu;
    ctx->downcount -= 18;
    // 8013394C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80133950:
    ctx->pc = 0x80133950u;
    // 80133950: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133954:
    ctx->pc = 0x80133954u;
    // 80133954: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133958:
    ctx->pc = 0x80133958u;
    // 80133958: lmw     r21, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 21; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8013395C:
    ctx->pc = 0x8013395Cu;
    // 8013395C: lfd     f31, 56(r1)
    if (!ppc_fp_available(ctx, 0x8013395Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80133960:
    ctx->pc = 0x80133960u;
    // 80133960: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_80133964:
    ctx->pc = 0x80133964u;
    // 80133964: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133968:
    ctx->pc = 0x80133968u;
    ctx->downcount -= 17;
    // 80133968: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013396C:
    ctx->pc = 0x8013396Cu;
    // 8013396C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133970:
    ctx->pc = 0x80133970u;
    // 80133970: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80133974:
    ctx->pc = 0x80133974u;
    // 80133974: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133978:
    ctx->pc = 0x80133978u;
    // 80133978: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_8013397C:
    ctx->pc = 0x8013397Cu;
    // 8013397C: addi    r31, r9, -18172
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-18172);

label_80133980:
    ctx->pc = 0x80133980u;
    // 80133980: addi    r30, r31, 36
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(36);

label_80133984:
    ctx->pc = 0x80133984u;
    ctx->downcount -= 4;
    // 80133984: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80133988:
    // 80133988: addi    r31, r31, 4
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(4);

label_8013398C:
    // 8013398C: cmpwi   r3, 0
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

label_80133990:
    // 80133990: bc    12, 2, 0x801339A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801339A4;
        }
    }

label_80133994:
    ctx->pc = 0x80133994u;
    ctx->downcount -= 3;
    // 80133994: lwz     r0, 232(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(232);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133998:
    // 80133998: cmpwi   r0, 0
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

label_8013399C:
    // 8013399C: bc    12, 0, 0x801339A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801339A4;
        }
    }

label_801339A0:
    ctx->downcount -= 1;
    // 801339A0: bl      0x800432AC
    {
            ctx->lr = 0x801339A4u;
            ctx->pc = 0x800432ACu;
            return;
    }

label_801339A4:
    ctx->downcount -= 2;
    // 801339A4: cmpw    r31, r30
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

label_801339A8:
    // 801339A8: bc    4, 1, 0x80133984
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133984u;
                return;
            }
            goto label_80133984;
        }
    }

label_801339AC:
    ctx->pc = 0x801339ACu;
    ctx->downcount -= 16;
    // 801339AC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801339B0:
    ctx->pc = 0x801339B0u;
    // 801339B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801339B4:
    ctx->pc = 0x801339B4u;
    // 801339B4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801339B8:
    ctx->pc = 0x801339B8u;
    // 801339B8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801339BC:
    ctx->pc = 0x801339BCu;
    // 801339BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_801339C0:
    ctx->pc = 0x801339C0u;
    ctx->downcount -= 19;
    // 801339C0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801339C4:
    ctx->pc = 0x801339C4u;
    // 801339C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801339C8:
    ctx->pc = 0x801339C8u;
    // 801339C8: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801339CC:
    ctx->pc = 0x801339CCu;
    // 801339CC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801339D0:
    ctx->pc = 0x801339D0u;
    // 801339D0: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_801339D4:
    ctx->pc = 0x801339D4u;
    // 801339D4: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_801339D8:
    ctx->pc = 0x801339D8u;
    // 801339D8: addi    r29, r9, -18172
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-18172);

label_801339DC:
    ctx->pc = 0x801339DCu;
    // 801339DC: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_801339E0:
    ctx->pc = 0x801339E0u;
    // 801339E0: li      r30, 10
    ctx->gpr[30] = (u32)(s32)(10);

label_801339E4:
    ctx->pc = 0x801339E4u;
    ctx->downcount -= 4;
    // 801339E4: lwzx    r0, r31, r29
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[29];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801339E8:
    // 801339E8: or   r3, r0, r0
    {
        ctx->gpr[3] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801339EC:
    // 801339EC: cmpwi   r0, 0
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

label_801339F0:
    // 801339F0: bc    12, 2, 0x801339FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801339FC;
        }
    }

label_801339F4:
    ctx->downcount -= 1;
    // 801339F4: bl      0x80042014
    {
            ctx->lr = 0x801339F8u;
            ctx->pc = 0x80042014u;
            return;
    }

label_801339F8:
    ctx->pc = 0x801339F8u;
    ctx->downcount -= 1;
    // 801339F8: stwx    r28, r31, r29
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_801339FC:
    ctx->downcount -= 3;
    // 801339FC: addi    r31, r31, 4
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(4);

label_80133A00:
    // 80133A00: addic.  r30, r30, -1
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

label_80133A04:
    // 80133A04: bc    4, 2, 0x801339E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801339E4u;
                return;
            }
            goto label_801339E4;
        }
    }

label_80133A08:
    ctx->pc = 0x80133A08u;
    ctx->downcount -= 16;
    // 80133A08: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133A0C:
    ctx->pc = 0x80133A0Cu;
    // 80133A0C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133A10:
    ctx->pc = 0x80133A10u;
    // 80133A10: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80133A14:
    ctx->pc = 0x80133A14u;
    // 80133A14: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80133A18:
    ctx->pc = 0x80133A18u;
    // 80133A18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133A1C:
    ctx->pc = 0x80133A1Cu;
    ctx->downcount -= 1;
    // 80133A1C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133A20:
    ctx->pc = 0x80133A20u;
    ctx->downcount -= 1;
    // 80133A20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133A24:
    ctx->pc = 0x80133A24u;
    ctx->downcount -= 4;
    // 80133A24: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133A28:
    ctx->pc = 0x80133A28u;
    // 80133A28: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133A2C:
    ctx->pc = 0x80133A2Cu;
    // 80133A2C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133A30:
    ctx->pc = 0x80133A30u;
    // 80133A30: bl      0x8000771C
    {
            ctx->lr = 0x80133A34u;
            ctx->pc = 0x8000771Cu;
            return;
    }

label_80133A34:
    ctx->pc = 0x80133A34u;
    ctx->downcount -= 3;
    // 80133A34: lwz     r4, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80133A38:
    ctx->pc = 0x80133A38u;
    // 80133A38: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133A3C:
    ctx->pc = 0x80133A3Cu;
    // 80133A3C: bl      0x80009F20
    {
            ctx->lr = 0x80133A40u;
            ctx->pc = 0x80009F20u;
            return;
    }

label_80133A40:
    ctx->pc = 0x80133A40u;
    ctx->downcount -= 5;
    // 80133A40: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133A44:
    ctx->pc = 0x80133A44u;
    // 80133A44: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133A48:
    ctx->pc = 0x80133A48u;
    // 80133A48: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80133A4C:
    ctx->pc = 0x80133A4Cu;
    // 80133A4C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133A50:
    ctx->pc = 0x80133A50u;
    ctx->downcount -= 4;
    // 80133A50: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133A54:
    ctx->pc = 0x80133A54u;
    // 80133A54: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133A58:
    ctx->pc = 0x80133A58u;
    // 80133A58: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133A5C:
    ctx->pc = 0x80133A5Cu;
    // 80133A5C: bl      0x8000776C
    {
            ctx->lr = 0x80133A60u;
            ctx->pc = 0x8000776Cu;
            return;
    }

label_80133A60:
    ctx->pc = 0x80133A60u;
    ctx->downcount -= 3;
    // 80133A60: lwz     r4, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80133A64:
    ctx->pc = 0x80133A64u;
    // 80133A64: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133A68:
    ctx->pc = 0x80133A68u;
    // 80133A68: bl      0x80009F20
    {
            ctx->lr = 0x80133A6Cu;
            ctx->pc = 0x80009F20u;
            return;
    }

label_80133A6C:
    ctx->pc = 0x80133A6Cu;
    ctx->downcount -= 5;
    // 80133A6C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133A70:
    ctx->pc = 0x80133A70u;
    // 80133A70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80133A74:
    ctx->pc = 0x80133A74u;
    // 80133A74: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80133A78:
    ctx->pc = 0x80133A78u;
    // 80133A78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80133A7C:
    ctx->pc = 0x80133A7Cu;
    ctx->downcount -= 30;
    // 80133A7C: stwu     r1, -18720(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-18720);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80133A80:
    ctx->pc = 0x80133A80u;
    // 80133A80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80133A84:
    ctx->pc = 0x80133A84u;
    // 80133A84: stfd     f20, 18624(r1)
    if (!ppc_fp_available(ctx, 0x80133A84u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18624);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[20]));
    }

label_80133A88:
    ctx->pc = 0x80133A88u;
    // 80133A88: stfd     f21, 18632(r1)
    if (!ppc_fp_available(ctx, 0x80133A88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18632);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[21]));
    }

label_80133A8C:
    ctx->pc = 0x80133A8Cu;
    // 80133A8C: stfd     f22, 18640(r1)
    if (!ppc_fp_available(ctx, 0x80133A8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18640);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[22]));
    }

label_80133A90:
    ctx->pc = 0x80133A90u;
    // 80133A90: stfd     f23, 18648(r1)
    if (!ppc_fp_available(ctx, 0x80133A90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18648);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[23]));
    }

label_80133A94:
    ctx->pc = 0x80133A94u;
    // 80133A94: stfd     f24, 18656(r1)
    if (!ppc_fp_available(ctx, 0x80133A94u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18656);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[24]));
    }

label_80133A98:
    ctx->pc = 0x80133A98u;
    // 80133A98: stfd     f25, 18664(r1)
    if (!ppc_fp_available(ctx, 0x80133A98u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18664);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[25]));
    }

label_80133A9C:
    ctx->pc = 0x80133A9Cu;
    // 80133A9C: stfd     f26, 18672(r1)
    if (!ppc_fp_available(ctx, 0x80133A9Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18672);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[26]));
    }

label_80133AA0:
    ctx->pc = 0x80133AA0u;
    // 80133AA0: stfd     f27, 18680(r1)
    if (!ppc_fp_available(ctx, 0x80133AA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18680);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[27]));
    }

label_80133AA4:
    ctx->pc = 0x80133AA4u;
    // 80133AA4: stfd     f28, 18688(r1)
    if (!ppc_fp_available(ctx, 0x80133AA4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18688);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[28]));
    }

label_80133AA8:
    ctx->pc = 0x80133AA8u;
    // 80133AA8: stfd     f29, 18696(r1)
    if (!ppc_fp_available(ctx, 0x80133AA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18696);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_80133AAC:
    ctx->pc = 0x80133AACu;
    // 80133AAC: stfd     f30, 18704(r1)
    if (!ppc_fp_available(ctx, 0x80133AACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18704);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80133AB0:
    ctx->pc = 0x80133AB0u;
    // 80133AB0: stfd     f31, 18712(r1)
    if (!ppc_fp_available(ctx, 0x80133AB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18712);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80133AB4:
    ctx->pc = 0x80133AB4u;
    // 80133AB4: stmw     r20, 18576(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18576);
        for (u32 r = 20; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80133AB8:
    ctx->pc = 0x80133AB8u;
    // 80133AB8: stw     r0, 18724(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18724);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133ABC:
    ctx->pc = 0x80133ABCu;
    // 80133ABC: lis     r0, 8192
    ctx->gpr[0] = ((u32)(s32)(8192) << 16);

label_80133AC0:
    ctx->pc = 0x80133AC0u;
    // 80133AC0: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_80133AC4:
    ctx->pc = 0x80133AC4u;
    // 80133AC4: cmpw    r3, r0
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

label_80133AC8:
    ctx->pc = 0x80133AC8u;
    // 80133AC8: bc    12, 2, 0x80136EA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EA4;
        }
    }

label_80133ACC:
    ctx->pc = 0x80133ACCu;
    ctx->downcount -= 1;
    // 80133ACC: bc    12, 1, 0x80133AF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133AF4;
        }
    }

label_80133AD0:
    ctx->pc = 0x80133AD0u;
    ctx->downcount -= 4;
    // 80133AD0: lis     r0, 4096
    ctx->gpr[0] = ((u32)(s32)(4096) << 16);

label_80133AD4:
    ctx->pc = 0x80133AD4u;
    // 80133AD4: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80133AD8:
    ctx->pc = 0x80133AD8u;
    // 80133AD8: cmpw    r3, r0
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

label_80133ADC:
    ctx->pc = 0x80133ADCu;
    // 80133ADC: bc    12, 2, 0x80136DEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136DEC;
        }
    }

label_80133AE0:
    ctx->pc = 0x80133AE0u;
    ctx->downcount -= 4;
    // 80133AE0: lis     r0, 8192
    ctx->gpr[0] = ((u32)(s32)(8192) << 16);

label_80133AE4:
    ctx->pc = 0x80133AE4u;
    // 80133AE4: ori     r0, r0, 0x0003
    ctx->gpr[0] = ctx->gpr[0] | 0x0003u;

label_80133AE8:
    ctx->pc = 0x80133AE8u;
    // 80133AE8: cmpw    r3, r0
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

label_80133AEC:
    ctx->pc = 0x80133AECu;
    // 80133AEC: bc    12, 2, 0x80133B18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133B18;
        }
    }

label_80133AF0:
    ctx->pc = 0x80133AF0u;
    ctx->downcount -= 1;
    // 80133AF0: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80133AF4:
    ctx->pc = 0x80133AF4u;
    ctx->downcount -= 4;
    // 80133AF4: lis     r0, 8448
    ctx->gpr[0] = ((u32)(s32)(8448) << 16);

label_80133AF8:
    ctx->pc = 0x80133AF8u;
    // 80133AF8: ori     r0, r0, 0x0003
    ctx->gpr[0] = ctx->gpr[0] | 0x0003u;

label_80133AFC:
    ctx->pc = 0x80133AFCu;
    // 80133AFC: cmpw    r3, r0
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

label_80133B00:
    ctx->pc = 0x80133B00u;
    // 80133B00: bc    12, 2, 0x80133B64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133B64;
        }
    }

label_80133B04:
    ctx->pc = 0x80133B04u;
    ctx->downcount -= 4;
    // 80133B04: lis     r0, 8448
    ctx->gpr[0] = ((u32)(s32)(8448) << 16);

label_80133B08:
    ctx->pc = 0x80133B08u;
    // 80133B08: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80133B0C:
    ctx->pc = 0x80133B0Cu;
    // 80133B0C: cmpw    r3, r0
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

label_80133B10:
    ctx->pc = 0x80133B10u;
    // 80133B10: bc    12, 2, 0x80133D34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133D34;
        }
    }

label_80133B14:
    ctx->pc = 0x80133B14u;
    ctx->downcount -= 1;
    // 80133B14: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80133B18:
    ctx->pc = 0x80133B18u;
    ctx->downcount -= 11;
    // 80133B18: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133B1C:
    ctx->pc = 0x80133B1Cu;
    // 80133B1C: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80133B20:
    ctx->pc = 0x80133B20u;
    // 80133B20: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80133B20u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133B24:
    ctx->pc = 0x80133B24u;
    // 80133B24: lis     r4, -32737
    ctx->gpr[4] = ((u32)(s32)(-32737) << 16);

label_80133B28:
    ctx->pc = 0x80133B28u;
    // 80133B28: lis     r5, -32737
    ctx->gpr[5] = ((u32)(s32)(-32737) << 16);

label_80133B2C:
    ctx->pc = 0x80133B2Cu;
    // 80133B2C: addi    r3, r3, -27148
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27148);

label_80133B30:
    ctx->pc = 0x80133B30u;
    // 80133B30: addi    r4, r4, 5760
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5760);

label_80133B34:
    ctx->pc = 0x80133B34u;
    // 80133B34: addi    r5, r5, 5784
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(5784);

label_80133B38:
    ctx->pc = 0x80133B38u;
    // 80133B38: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80133B3C:
    ctx->pc = 0x80133B3Cu;
    // 80133B3C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80133B40:
    ctx->pc = 0x80133B40u;
    // 80133B40: bl      0x80017588
    {
            ctx->lr = 0x80133B44u;
            ctx->pc = 0x80017588u;
            return;
    }

label_80133B44:
    ctx->pc = 0x80133B44u;
    ctx->downcount -= 8;
    // 80133B44: lis     r9, -32702
    ctx->gpr[9] = ((u32)(s32)(-32702) << 16);

label_80133B48:
    ctx->pc = 0x80133B48u;
    // 80133B48: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80133B4C:
    ctx->pc = 0x80133B4Cu;
    // 80133B4C: addi    r9, r9, 30884
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(30884);

label_80133B50:
    ctx->pc = 0x80133B50u;
    // 80133B50: stw     r0, 496(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(496);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133B54:
    ctx->pc = 0x80133B54u;
    // 80133B54: stw     r0, 508(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133B58:
    ctx->pc = 0x80133B58u;
    // 80133B58: stw     r0, 504(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133B5C:
    ctx->pc = 0x80133B5Cu;
    // 80133B5C: stw     r0, 500(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(500);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133B60:
    ctx->pc = 0x80133B60u;
    // 80133B60: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80133B64:
    ctx->pc = 0x80133B64u;
    ctx->downcount -= 16;
    // 80133B64: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80133B68:
    ctx->pc = 0x80133B68u;
    // 80133B68: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80133B6C:
    ctx->pc = 0x80133B6Cu;
    // 80133B6C: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80133B70:
    ctx->pc = 0x80133B70u;
    // 80133B70: li      r29, -1
    ctx->gpr[29] = (u32)(s32)(-1);

label_80133B74:
    ctx->pc = 0x80133B74u;
    // 80133B74: stw     r30, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B78:
    ctx->pc = 0x80133B78u;
    // 80133B78: stw     r30, -27044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27044);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B7C:
    ctx->pc = 0x80133B7Cu;
    // 80133B7C: stw     r30, -30104(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30104);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B80:
    ctx->pc = 0x80133B80u;
    // 80133B80: stw     r30, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B84:
    ctx->pc = 0x80133B84u;
    // 80133B84: stw     r30, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B88:
    ctx->pc = 0x80133B88u;
    // 80133B88: stw     r30, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B8C:
    ctx->pc = 0x80133B8Cu;
    // 80133B8C: stw     r30, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B90:
    ctx->pc = 0x80133B90u;
    // 80133B90: stw     r30, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B94:
    ctx->pc = 0x80133B94u;
    // 80133B94: stw     r30, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B98:
    ctx->pc = 0x80133B98u;
    // 80133B98: stw     r30, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133B9C:
    ctx->pc = 0x80133B9Cu;
    // 80133B9C: stw     r29, -32304(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32304);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80133BA0:
    ctx->pc = 0x80133BA0u;
    // 80133BA0: bl      0x80133858
    {
            ctx->lr = 0x80133BA4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133858u;
                return;
            }
            goto label_80133858;
    }

label_80133BA4:
    ctx->pc = 0x80133BA4u;
    ctx->downcount -= 9;
    // 80133BA4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80133BA8:
    ctx->pc = 0x80133BA8u;
    // 80133BA8: lwz     r0, -27484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27484);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133BAC:
    ctx->pc = 0x80133BACu;
    // 80133BAC: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_80133BB0:
    ctx->pc = 0x80133BB0u;
    // 80133BB0: stw     r29, -30100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30100);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80133BB4:
    ctx->pc = 0x80133BB4u;
    // 80133BB4: sth     r30, 662(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(662);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_80133BB8:
    ctx->pc = 0x80133BB8u;
    // 80133BB8: stw     r0, -27072(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27072);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133BBC:
    ctx->pc = 0x80133BBCu;
    // 80133BBC: sth     r30, 54(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_80133BC0:
    ctx->pc = 0x80133BC0u;
    // 80133BC0: stw     r30, -27484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27484);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133BC4:
    ctx->pc = 0x80133BC4u;
    // 80133BC4: bl      0x80056738
    {
            ctx->lr = 0x80133BC8u;
            ctx->pc = 0x80056738u;
            return;
    }

label_80133BC8:
    ctx->pc = 0x80133BC8u;
    ctx->downcount -= 1;
    // 80133BC8: bl      0x80055A2C
    {
            ctx->lr = 0x80133BCCu;
            ctx->pc = 0x80055A2Cu;
            return;
    }

label_80133BCC:
    ctx->pc = 0x80133BCCu;
    ctx->downcount -= 1;
    // 80133BCC: bl      0x8005AC08
    {
            ctx->lr = 0x80133BD0u;
            ctx->pc = 0x8005AC08u;
            return;
    }

label_80133BD0:
    ctx->pc = 0x80133BD0u;
    ctx->downcount -= 2;
    // 80133BD0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80133BD4:
    ctx->pc = 0x80133BD4u;
    // 80133BD4: bl      0x800689B8
    {
            ctx->lr = 0x80133BD8u;
            ctx->pc = 0x800689B8u;
            return;
    }

label_80133BD8:
    ctx->pc = 0x80133BD8u;
    ctx->downcount -= 1;
    // 80133BD8: bl      0x8001DA5C
    {
            ctx->lr = 0x80133BDCu;
            ctx->pc = 0x8001DA5Cu;
            return;
    }

label_80133BDC:
    ctx->pc = 0x80133BDCu;
    ctx->downcount -= 23;
    // 80133BDC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133BE0:
    ctx->pc = 0x80133BE0u;
    // 80133BE0: lis     r8, -32737
    ctx->gpr[8] = ((u32)(s32)(-32737) << 16);

label_80133BE4:
    ctx->pc = 0x80133BE4u;
    // 80133BE4: lfs     f0, 5900(r9)
    if (!ppc_fp_available(ctx, 0x80133BE4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5900);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80133BE8:
    ctx->pc = 0x80133BE8u;
    // 80133BE8: lis     r10, -32702
    ctx->gpr[10] = ((u32)(s32)(-32702) << 16);

label_80133BEC:
    ctx->pc = 0x80133BECu;
    // 80133BEC: lfs     f13, 5904(r8)
    if (!ppc_fp_available(ctx, 0x80133BECu)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(5904);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80133BF0:
    ctx->pc = 0x80133BF0u;
    // 80133BF0: addi    r11, r10, 30884
    ctx->gpr[11] = ctx->gpr[10] + (u32)(s32)(30884);

label_80133BF4:
    ctx->pc = 0x80133BF4u;
    // 80133BF4: stfs     f0, 30884(r10)
    if (!ppc_fp_available(ctx, 0x80133BF4u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(30884);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80133BF8:
    ctx->pc = 0x80133BF8u;
    // 80133BF8: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_80133BFC:
    ctx->pc = 0x80133BFCu;
    // 80133BFC: stw     r0, 496(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(496);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133C00:
    ctx->pc = 0x80133C00u;
    // 80133C00: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80133C04:
    ctx->pc = 0x80133C04u;
    // 80133C04: stfs     f13, 8(r11)
    if (!ppc_fp_available(ctx, 0x80133C04u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_80133C08:
    ctx->pc = 0x80133C08u;
    // 80133C08: addi    r7, r9, 28576
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(28576);

label_80133C0C:
    ctx->pc = 0x80133C0Cu;
    // 80133C0C: stfs     f0, 20(r11)
    if (!ppc_fp_available(ctx, 0x80133C0Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80133C10:
    ctx->pc = 0x80133C10u;
    // 80133C10: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_80133C14:
    ctx->pc = 0x80133C14u;
    // 80133C14: stw     r30, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133C18:
    ctx->pc = 0x80133C18u;
    // 80133C18: addi    r9, r9, -18004
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-18004);

label_80133C1C:
    ctx->pc = 0x80133C1Cu;
    // 80133C1C: stfs     f0, -27048(r13)
    if (!ppc_fp_available(ctx, 0x80133C1Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27048);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80133C20:
    ctx->pc = 0x80133C20u;
    // 80133C20: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80133C24:
    ctx->pc = 0x80133C24u;
    // 80133C24: stfs     f0, 4(r11)
    if (!ppc_fp_available(ctx, 0x80133C24u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80133C28:
    ctx->pc = 0x80133C28u;
    // 80133C28: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80133C2C:
    ctx->pc = 0x80133C2Cu;
    // 80133C2C: stfs     f0, 12(r11)
    if (!ppc_fp_available(ctx, 0x80133C2Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80133C30:
    ctx->pc = 0x80133C30u;
    // 80133C30: stfs     f0, 16(r11)
    if (!ppc_fp_available(ctx, 0x80133C30u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80133C34:
    ctx->pc = 0x80133C34u;
    // 80133C34: stw     r30, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80133C38:
    ctx->downcount -= 3;
    // 80133C38: addi    r8, r8, 1
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(1);

label_80133C3C:
    // 80133C3C: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80133C40:
    // 80133C40: addi    r11, r7, 4
    ctx->gpr[11] = ctx->gpr[7] + (u32)(s32)(4);

label_80133C44:
    ctx->pc = 0x80133C44u;
    ctx->downcount -= 4;
    // 80133C44: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133C48:
    // 80133C48: addi    r11, r11, 12
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(12);

label_80133C4C:
    // 80133C4C: andi.   r6, r0, 0x0016
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0016u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80133C50:
    // 80133C50: bc    12, 2, 0x80133C60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133C60;
        }
    }

label_80133C54:
    ctx->downcount -= 3;
    // 80133C54: rlwinm r0, r10, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 2u) & 0xFFFFFFFCu;
    }

label_80133C58:
    ctx->pc = 0x80133C58u;
    // 80133C58: stwx    r26, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80133C5C:
    // 80133C5C: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_80133C60:
    ctx->downcount -= 2;
    // 80133C60: addic.  r26, r26, 1
    {
        u64 a = ctx->gpr[26];
        u64 b = (u32)(s32)(1);
        u64 res = a + b;
        ctx->gpr[26] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[26];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80133C64:
    // 80133C64: bc    12, 2, 0x80133C44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133C44u;
                return;
            }
            goto label_80133C44;
        }
    }

label_80133C68:
    ctx->downcount -= 2;
    // 80133C68: cmpwi   r8, 6
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80133C6C:
    // 80133C6C: bc    12, 0, 0x80133C38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133C38u;
                return;
            }
            goto label_80133C38;
        }
    }

label_80133C70:
    ctx->pc = 0x80133C70u;
    ctx->downcount -= 2;
    // 80133C70: stw     r10, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80133C74:
    ctx->pc = 0x80133C74u;
    // 80133C74: bl      0x80133880
    {
            ctx->lr = 0x80133C78u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133880u;
                return;
            }
            goto label_80133880;
    }

label_80133C78:
    ctx->pc = 0x80133C78u;
    ctx->downcount -= 5;
    // 80133C78: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80133C7C:
    ctx->pc = 0x80133C7Cu;
    // 80133C7C: addi    r31, r9, -21636
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-21636);

label_80133C80:
    ctx->pc = 0x80133C80u;
    // 80133C80: lhz     r9, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80133C84:
    ctx->pc = 0x80133C84u;
    // 80133C84: cmpwi   r9, 0
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

label_80133C88:
    ctx->pc = 0x80133C88u;
    // 80133C88: bc    4, 2, 0x80133C94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80133C94;
        }
    }

label_80133C8C:
    ctx->pc = 0x80133C8Cu;
    ctx->downcount -= 2;
    // 80133C8C: addi    r0, r9, 1
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(1);

label_80133C90:
    ctx->pc = 0x80133C90u;
    // 80133C90: sth     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80133C94:
    ctx->pc = 0x80133C94u;
    ctx->downcount -= 3;
    // 80133C94: lha     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133C98:
    ctx->pc = 0x80133C98u;
    // 80133C98: cmpwi   r0, 7
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

label_80133C9C:
    ctx->pc = 0x80133C9Cu;
    // 80133C9C: bc    4, 2, 0x80133CB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80133CB4;
        }
    }

label_80133CA0:
    ctx->pc = 0x80133CA0u;
    ctx->downcount -= 5;
    // 80133CA0: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80133CA4:
    ctx->pc = 0x80133CA4u;
    // 80133CA4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133CA8:
    ctx->pc = 0x80133CA8u;
    // 80133CA8: addi    r3, r3, -27148
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27148);

label_80133CAC:
    ctx->pc = 0x80133CACu;
    // 80133CAC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133CB0:
    ctx->pc = 0x80133CB0u;
    // 80133CB0: bl      0x80017800
    {
            ctx->lr = 0x80133CB4u;
            ctx->pc = 0x80017800u;
            return;
    }

label_80133CB4:
    ctx->pc = 0x80133CB4u;
    ctx->downcount -= 10;
    // 80133CB4: lha     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133CB8:
    ctx->pc = 0x80133CB8u;
    // 80133CB8: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80133CBC:
    ctx->pc = 0x80133CBCu;
    // 80133CBC: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80133CC0:
    ctx->pc = 0x80133CC0u;
    // 80133CC0: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80133CC4:
    ctx->pc = 0x80133CC4u;
    // 80133CC4: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_80133CC8:
    ctx->pc = 0x80133CC8u;
    // 80133CC8: lwzx    r10, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80133CCC:
    ctx->pc = 0x80133CCCu;
    // 80133CCC: lwzx    r8, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80133CD0:
    ctx->pc = 0x80133CD0u;
    // 80133CD0: stw     r10, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80133CD4:
    ctx->pc = 0x80133CD4u;
    // 80133CD4: stw     r8, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80133CD8:
    ctx->pc = 0x80133CD8u;
    // 80133CD8: bl      0x800B7A5C
    {
            ctx->lr = 0x80133CDCu;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80133CDC:
    ctx->pc = 0x80133CDCu;
    ctx->downcount -= 6;
    // 80133CDC: lis     r9, -32736
    ctx->gpr[9] = ((u32)(s32)(-32736) << 16);

label_80133CE0:
    ctx->pc = 0x80133CE0u;
    // 80133CE0: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_80133CE4:
    ctx->pc = 0x80133CE4u;
    // 80133CE4: addi    r31, r9, 11968
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(11968);

label_80133CE8:
    ctx->pc = 0x80133CE8u;
    // 80133CE8: lwz     r0, 27404(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(27404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133CEC:
    ctx->pc = 0x80133CECu;
    // 80133CEC: cmpwi   r0, 0
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

label_80133CF0:
    ctx->pc = 0x80133CF0u;
    // 80133CF0: bc    4, 2, 0x80133CF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80133CF8;
        }
    }

label_80133CF4:
    ctx->pc = 0x80133CF4u;
    ctx->downcount -= 1;
    // 80133CF4: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80133CF8:
    ctx->pc = 0x80133CF8u;
    ctx->downcount -= 2;
    // 80133CF8: cmpwi   r11, 0
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

label_80133CFC:
    ctx->pc = 0x80133CFCu;
    // 80133CFC: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80133D00:
    ctx->pc = 0x80133D00u;
    ctx->downcount -= 6;
    // 80133D00: lwz     r4, -27488(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27488);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80133D04:
    ctx->pc = 0x80133D04u;
    // 80133D04: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80133D08:
    ctx->pc = 0x80133D08u;
    // 80133D08: lis     r5, -16384
    ctx->gpr[5] = ((u32)(s32)(-16384) << 16);

label_80133D0C:
    ctx->pc = 0x80133D0Cu;
    // 80133D0C: addi    r3, r3, 11668
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(11668);

label_80133D10:
    ctx->pc = 0x80133D10u;
    // 80133D10: ori     r5, r5, 0x0005
    ctx->gpr[5] = ctx->gpr[5] | 0x0005u;

label_80133D14:
    ctx->pc = 0x80133D14u;
    // 80133D14: bl      0x80034BB0
    {
            ctx->lr = 0x80133D18u;
            ctx->pc = 0x80034BB0u;
            return;
    }

label_80133D18:
    ctx->pc = 0x80133D18u;
    ctx->downcount -= 6;
    // 80133D18: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80133D1C:
    ctx->pc = 0x80133D1Cu;
    // 80133D1C: lis     r5, -16384
    ctx->gpr[5] = ((u32)(s32)(-16384) << 16);

label_80133D20:
    ctx->pc = 0x80133D20u;
    // 80133D20: addi    r3, r3, -19280
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19280);

label_80133D24:
    ctx->pc = 0x80133D24u;
    // 80133D24: addi    r4, r31, 27368
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(27368);

label_80133D28:
    ctx->pc = 0x80133D28u;
    // 80133D28: ori     r5, r5, 0x0006
    ctx->gpr[5] = ctx->gpr[5] | 0x0006u;

label_80133D2C:
    ctx->pc = 0x80133D2Cu;
    // 80133D2C: bl      0x80034BB0
    {
            ctx->lr = 0x80133D30u;
            ctx->pc = 0x80034BB0u;
            return;
    }

label_80133D30:
    ctx->pc = 0x80133D30u;
    ctx->downcount -= 1;
    // 80133D30: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80133D34:
    ctx->pc = 0x80133D34u;
    ctx->downcount -= 5;
    // 80133D34: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80133D38:
    ctx->pc = 0x80133D38u;
    // 80133D38: addi    r31, r9, -21636
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-21636);

label_80133D3C:
    ctx->pc = 0x80133D3Cu;
    // 80133D3C: lha     r0, 54(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(54);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133D40:
    ctx->pc = 0x80133D40u;
    // 80133D40: cmpwi   r0, 0
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

label_80133D44:
    ctx->pc = 0x80133D44u;
    // 80133D44: bc    12, 2, 0x80133D54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133D54;
        }
    }

label_80133D48:
    ctx->pc = 0x80133D48u;
    ctx->downcount -= 2;
    // 80133D48: cmpwi   r0, 4
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

label_80133D4C:
    ctx->pc = 0x80133D4Cu;
    // 80133D4C: bc    12, 2, 0x80133D88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133D88;
        }
    }

label_80133D50:
    ctx->pc = 0x80133D50u;
    ctx->downcount -= 1;
    // 80133D50: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80133D54:
    ctx->pc = 0x80133D54u;
    ctx->downcount -= 10;
    // 80133D54: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133D58:
    ctx->pc = 0x80133D58u;
    // 80133D58: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_80133D5C:
    ctx->pc = 0x80133D5Cu;
    // 80133D5C: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_80133D60:
    ctx->pc = 0x80133D60u;
    // 80133D60: lfs     f1, 5908(r9)
    if (!ppc_fp_available(ctx, 0x80133D60u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5908);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133D64:
    ctx->pc = 0x80133D64u;
    // 80133D64: lfs     f2, 5912(r11)
    if (!ppc_fp_available(ctx, 0x80133D64u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5912);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80133D68:
    ctx->pc = 0x80133D68u;
    // 80133D68: lis     r4, -32697
    ctx->gpr[4] = ((u32)(s32)(-32697) << 16);

label_80133D6C:
    ctx->pc = 0x80133D6Cu;
    // 80133D6C: lfs     f3, 5916(r10)
    if (!ppc_fp_available(ctx, 0x80133D6Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(5916);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_80133D70:
    ctx->pc = 0x80133D70u;
    // 80133D70: addi    r4, r4, -18768
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-18768);

label_80133D74:
    ctx->pc = 0x80133D74u;
    // 80133D74: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80133D78:
    ctx->pc = 0x80133D78u;
    // 80133D78: bl      0x800B7BF8
    {
            ctx->lr = 0x80133D7Cu;
            ctx->pc = 0x800B7BF8u;
            return;
    }

label_80133D7C:
    ctx->pc = 0x80133D7Cu;
    ctx->downcount -= 3;
    // 80133D7C: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_80133D80:
    ctx->pc = 0x80133D80u;
    // 80133D80: sth     r0, 54(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80133D84:
    ctx->pc = 0x80133D84u;
    // 80133D84: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80133D88:
    ctx->pc = 0x80133D88u;
    ctx->downcount -= 4;
    // 80133D88: lha     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133D8C:
    ctx->pc = 0x80133D8Cu;
    // 80133D8C: li      r20, 0
    ctx->gpr[20] = (u32)(s32)(0);

label_80133D90:
    ctx->pc = 0x80133D90u;
    // 80133D90: cmpwi   r0, 8
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

label_80133D94:
    ctx->pc = 0x80133D94u;
    // 80133D94: bc    12, 2, 0x80134824
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134824;
        }
    }

label_80133D98:
    ctx->pc = 0x80133D98u;
    ctx->downcount -= 1;
    // 80133D98: bc    12, 1, 0x80133DE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133DE0;
        }
    }

label_80133D9C:
    ctx->pc = 0x80133D9Cu;
    ctx->downcount -= 2;
    // 80133D9C: cmpwi   r0, 3
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

label_80133DA0:
    ctx->pc = 0x80133DA0u;
    // 80133DA0: bc    12, 2, 0x80134278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134278;
        }
    }

label_80133DA4:
    ctx->pc = 0x80133DA4u;
    ctx->downcount -= 1;
    // 80133DA4: bc    12, 1, 0x80133DC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133DC0;
        }
    }

label_80133DA8:
    ctx->pc = 0x80133DA8u;
    ctx->downcount -= 2;
    // 80133DA8: cmpwi   r0, 1
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

label_80133DAC:
    ctx->pc = 0x80133DACu;
    // 80133DAC: bc    12, 2, 0x801342F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801342F8;
        }
    }

label_80133DB0:
    ctx->pc = 0x80133DB0u;
    ctx->downcount -= 1;
    // 80133DB0: bc    12, 1, 0x80133E5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133E5C;
        }
    }

label_80133DB4:
    ctx->pc = 0x80133DB4u;
    ctx->downcount -= 2;
    // 80133DB4: cmpwi   r0, 0
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

label_80133DB8:
    ctx->pc = 0x80133DB8u;
    // 80133DB8: bc    12, 2, 0x80133EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133EBC;
        }
    }

label_80133DBC:
    ctx->pc = 0x80133DBCu;
    ctx->downcount -= 1;
    // 80133DBC: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80133DC0:
    ctx->pc = 0x80133DC0u;
    ctx->downcount -= 2;
    // 80133DC0: cmpwi   r0, 5
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

label_80133DC4:
    ctx->pc = 0x80133DC4u;
    // 80133DC4: bc    12, 2, 0x80134378
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134378;
        }
    }

label_80133DC8:
    ctx->pc = 0x80133DC8u;
    ctx->downcount -= 1;
    // 80133DC8: bc    12, 0, 0x80133E28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133E28;
        }
    }

label_80133DCC:
    ctx->pc = 0x80133DCCu;
    ctx->downcount -= 2;
    // 80133DCC: cmpwi   r0, 6
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

label_80133DD0:
    ctx->pc = 0x80133DD0u;
    // 80133DD0: bc    12, 2, 0x80133E64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133E64;
        }
    }

label_80133DD4:
    ctx->pc = 0x80133DD4u;
    ctx->downcount -= 2;
    // 80133DD4: cmpwi   r0, 7
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

label_80133DD8:
    ctx->pc = 0x80133DD8u;
    // 80133DD8: bc    12, 2, 0x801344A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801344A8;
        }
    }

label_80133DDC:
    ctx->pc = 0x80133DDCu;
    ctx->downcount -= 1;
    // 80133DDC: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80133DE0:
    ctx->pc = 0x80133DE0u;
    ctx->downcount -= 2;
    // 80133DE0: cmpwi   r0, 12
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

label_80133DE4:
    ctx->pc = 0x80133DE4u;
    // 80133DE4: bc    12, 2, 0x80135A10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135A10;
        }
    }

label_80133DE8:
    ctx->pc = 0x80133DE8u;
    ctx->downcount -= 1;
    // 80133DE8: bc    12, 1, 0x80133DFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133DFC;
        }
    }

label_80133DEC:
    ctx->pc = 0x80133DECu;
    ctx->downcount -= 2;
    // 80133DEC: cmpwi   r0, 10
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

label_80133DF0:
    ctx->pc = 0x80133DF0u;
    // 80133DF0: bc    12, 2, 0x80135364
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135364;
        }
    }

label_80133DF4:
    ctx->pc = 0x80133DF4u;
    ctx->downcount -= 1;
    // 80133DF4: bc    12, 1, 0x80135758
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135758;
        }
    }

label_80133DF8:
    ctx->pc = 0x80133DF8u;
    ctx->downcount -= 1;
    // 80133DF8: b       0x80134FF4
    {
            goto label_80134FF4;
    }

label_80133DFC:
    ctx->pc = 0x80133DFCu;
    ctx->downcount -= 2;
    // 80133DFC: cmpwi   r0, 14
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

label_80133E00:
    ctx->pc = 0x80133E00u;
    // 80133E00: bc    12, 2, 0x80135B20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135B20;
        }
    }

label_80133E04:
    ctx->pc = 0x80133E04u;
    ctx->downcount -= 1;
    // 80133E04: bc    12, 0, 0x80133EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133EBC;
        }
    }

label_80133E08:
    ctx->pc = 0x80133E08u;
    ctx->downcount -= 2;
    // 80133E08: cmpwi   r0, 15
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

label_80133E0C:
    ctx->pc = 0x80133E0Cu;
    // 80133E0C: bc    12, 2, 0x80135BF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135BF0;
        }
    }

label_80133E10:
    ctx->pc = 0x80133E10u;
    ctx->downcount -= 2;
    // 80133E10: cmpwi   r0, 16
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

label_80133E14:
    ctx->pc = 0x80133E14u;
    // 80133E14: bc    4, 2, 0x80135BF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135BF0;
        }
    }

label_80133E18:
    ctx->pc = 0x80133E18u;
    ctx->downcount -= 3;
    // 80133E18: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80133E1C:
    ctx->pc = 0x80133E1Cu;
    // 80133E1C: addi    r3, r3, -18336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-18336);

label_80133E20:
    ctx->pc = 0x80133E20u;
    // 80133E20: bl      0x8005C984
    {
            ctx->lr = 0x80133E24u;
            ctx->pc = 0x8005C984u;
            return;
    }

label_80133E24:
    ctx->pc = 0x80133E24u;
    ctx->downcount -= 1;
    // 80133E24: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80133E28:
    ctx->pc = 0x80133E28u;
    ctx->downcount -= 5;
    // 80133E28: lwz     r4, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80133E2C:
    ctx->pc = 0x80133E2Cu;
    // 80133E2C: lis     r3, -32737
    ctx->gpr[3] = ((u32)(s32)(-32737) << 16);

label_80133E30:
    ctx->pc = 0x80133E30u;
    // 80133E30: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133E34:
    ctx->pc = 0x80133E34u;
    // 80133E34: addi    r3, r3, 5808
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(5808);

label_80133E38:
    ctx->pc = 0x80133E38u;
    // 80133E38: bl      0x80009F20
    {
            ctx->lr = 0x80133E3Cu;
            ctx->pc = 0x80009F20u;
            return;
    }

label_80133E3C:
    ctx->pc = 0x80133E3Cu;
    ctx->downcount -= 5;
    // 80133E3C: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80133E40:
    ctx->pc = 0x80133E40u;
    // 80133E40: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80133E44:
    ctx->pc = 0x80133E44u;
    // 80133E44: addi    r3, r3, -27148
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27148);

label_80133E48:
    ctx->pc = 0x80133E48u;
    // 80133E48: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133E4C:
    ctx->pc = 0x80133E4Cu;
    // 80133E4C: bl      0x80017800
    {
            ctx->lr = 0x80133E50u;
            ctx->pc = 0x80017800u;
            return;
    }

label_80133E50:
    ctx->pc = 0x80133E50u;
    ctx->downcount -= 1;
    // 80133E50: stw     r20, -27044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27044);
        mem_write32(ctx, ea, (u32)ctx->gpr[20]);
    }

label_80133E54:
    ctx->downcount -= 2;
    // 80133E54: li      r20, 1
    ctx->gpr[20] = (u32)(s32)(1);

label_80133E58:
    // 80133E58: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80133E5C:
    ctx->downcount -= 1;
    // 80133E5C: bl      0x80133A24
    {
            ctx->lr = 0x80133E60u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133A24u;
                return;
            }
            goto label_80133A24;
    }

label_80133E60:
    ctx->downcount -= 1;
    // 80133E60: b       0x80133E54
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133E54u;
                return;
            }
            goto label_80133E54;
    }

label_80133E64:
    ctx->downcount -= 5;
    // 80133E64: lis     r30, -32703
    ctx->gpr[30] = ((u32)(s32)(-32703) << 16);

label_80133E68:
    // 80133E68: li      r4, 15
    ctx->gpr[4] = (u32)(s32)(15);

label_80133E6C:
    // 80133E6C: addi    r3, r30, -27148
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-27148);

label_80133E70:
    // 80133E70: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133E74:
    // 80133E74: bl      0x80017800
    {
            ctx->lr = 0x80133E78u;
            ctx->pc = 0x80017800u;
            return;
    }

label_80133E78:
    ctx->downcount -= 1;
    // 80133E78: bl      0x80133A50
    {
            ctx->lr = 0x80133E7Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133A50u;
                return;
            }
            goto label_80133A50;
    }

label_80133E7C:
    ctx->pc = 0x80133E7Cu;
    ctx->downcount -= 8;
    // 80133E7C: lwz     r0, -27044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27044);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80133E80:
    // 80133E80: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80133E84:
    // 80133E84: addi    r9, r9, 28808
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28808);

label_80133E88:
    // 80133E88: addi    r3, r30, -27148
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-27148);

label_80133E8C:
    // 80133E8C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80133E90:
    // 80133E90: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80133E94:
    ctx->pc = 0x80133E94u;
    // 80133E94: lwzx    r4, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80133E98:
    // 80133E98: bl      0x80017800
    {
            ctx->lr = 0x80133E9Cu;
            ctx->pc = 0x80017800u;
            return;
    }

label_80133E9C:
    ctx->pc = 0x80133E9Cu;
    ctx->downcount -= 5;
    // 80133E9C: lwz     r9, -27044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27044);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133EA0:
    // 80133EA0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80133EA4:
    // 80133EA4: cmpwi   r9, 6
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80133EA8:
    ctx->pc = 0x80133EA8u;
    // 80133EA8: stw     r9, -27044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27044);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80133EAC:
    // 80133EAC: bc    4, 1, 0x80133E54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133E54u;
                return;
            }
            goto label_80133E54;
        }
    }

label_80133EB0:
    ctx->downcount -= 3;
    // 80133EB0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80133EB4:
    ctx->pc = 0x80133EB4u;
    // 80133EB4: stw     r0, -27044(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27044);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80133EB8:
    // 80133EB8: b       0x80133E54
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133E54u;
                return;
            }
            goto label_80133E54;
    }

label_80133EBC:
    ctx->pc = 0x80133EBCu;
    ctx->downcount -= 2;
    // 80133EBC: lis     r3, 64
    ctx->gpr[3] = ((u32)(s32)(64) << 16);

label_80133EC0:
    ctx->pc = 0x80133EC0u;
    // 80133EC0: bl      0x80132FD8
    {
            ctx->lr = 0x80133EC4u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80133EC4:
    ctx->pc = 0x80133EC4u;
    ctx->downcount -= 2;
    // 80133EC4: cmpwi   r3, 0
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

label_80133EC8:
    ctx->pc = 0x80133EC8u;
    // 80133EC8: bc    12, 2, 0x80133F14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133F14;
        }
    }

label_80133ECC:
    ctx->pc = 0x80133ECCu;
    ctx->downcount -= 5;
    // 80133ECC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133ED0:
    ctx->pc = 0x80133ED0u;
    // 80133ED0: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80133ED4:
    ctx->pc = 0x80133ED4u;
    // 80133ED4: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80133ED4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133ED8:
    ctx->pc = 0x80133ED8u;
    // 80133ED8: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80133EDC:
    ctx->pc = 0x80133EDCu;
    // 80133EDC: bl      0x8004DC00
    {
            ctx->lr = 0x80133EE0u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80133EE0:
    ctx->pc = 0x80133EE0u;
    ctx->downcount -= 13;
    // 80133EE0: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80133EE4:
    ctx->pc = 0x80133EE4u;
    // 80133EE4: lis     r11, -32733
    ctx->gpr[11] = ((u32)(s32)(-32733) << 16);

label_80133EE8:
    ctx->pc = 0x80133EE8u;
    // 80133EE8: lha     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133EEC:
    ctx->pc = 0x80133EECu;
    // 80133EEC: addi    r11, r11, 28640
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(28640);

label_80133EF0:
    ctx->pc = 0x80133EF0u;
    // 80133EF0: addi    r10, r11, 4
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(4);

label_80133EF4:
    ctx->pc = 0x80133EF4u;
    // 80133EF4: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133EF8:
    ctx->pc = 0x80133EF8u;
    // 80133EF8: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80133EFC:
    ctx->pc = 0x80133EFCu;
    // 80133EFC: lwzx    r8, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80133F00:
    ctx->pc = 0x80133F00u;
    // 80133F00: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80133F04:
    ctx->pc = 0x80133F04u;
    // 80133F04: lwzx    r10, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80133F08:
    ctx->pc = 0x80133F08u;
    // 80133F08: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80133F0C:
    ctx->pc = 0x80133F0Cu;
    // 80133F0C: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80133F10:
    ctx->pc = 0x80133F10u;
    // 80133F10: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80133F14:
    ctx->pc = 0x80133F14u;
    ctx->downcount -= 2;
    // 80133F14: lis     r3, 128
    ctx->gpr[3] = ((u32)(s32)(128) << 16);

label_80133F18:
    ctx->pc = 0x80133F18u;
    // 80133F18: bl      0x80132FD8
    {
            ctx->lr = 0x80133F1Cu;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80133F1C:
    ctx->pc = 0x80133F1Cu;
    ctx->downcount -= 2;
    // 80133F1C: cmpwi   r3, 0
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

label_80133F20:
    ctx->pc = 0x80133F20u;
    // 80133F20: bc    12, 2, 0x80133F6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133F6C;
        }
    }

label_80133F24:
    ctx->pc = 0x80133F24u;
    ctx->downcount -= 5;
    // 80133F24: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133F28:
    ctx->pc = 0x80133F28u;
    // 80133F28: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80133F2C:
    ctx->pc = 0x80133F2Cu;
    // 80133F2C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80133F2Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133F30:
    ctx->pc = 0x80133F30u;
    // 80133F30: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80133F34:
    ctx->pc = 0x80133F34u;
    // 80133F34: bl      0x8004DC00
    {
            ctx->lr = 0x80133F38u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80133F38:
    ctx->pc = 0x80133F38u;
    ctx->downcount -= 13;
    // 80133F38: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80133F3C:
    ctx->pc = 0x80133F3Cu;
    // 80133F3C: lis     r11, -32733
    ctx->gpr[11] = ((u32)(s32)(-32733) << 16);

label_80133F40:
    ctx->pc = 0x80133F40u;
    // 80133F40: lha     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133F44:
    ctx->pc = 0x80133F44u;
    // 80133F44: addi    r11, r11, 28640
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(28640);

label_80133F48:
    ctx->pc = 0x80133F48u;
    // 80133F48: addi    r10, r11, 4
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(4);

label_80133F4C:
    ctx->pc = 0x80133F4Cu;
    // 80133F4C: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133F50:
    ctx->pc = 0x80133F50u;
    // 80133F50: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80133F54:
    ctx->pc = 0x80133F54u;
    // 80133F54: lwzx    r8, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80133F58:
    ctx->pc = 0x80133F58u;
    // 80133F58: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80133F5C:
    ctx->pc = 0x80133F5Cu;
    // 80133F5C: lwzx    r10, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80133F60:
    ctx->pc = 0x80133F60u;
    // 80133F60: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80133F64:
    ctx->pc = 0x80133F64u;
    // 80133F64: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80133F68:
    ctx->pc = 0x80133F68u;
    // 80133F68: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80133F6C:
    ctx->pc = 0x80133F6Cu;
    ctx->downcount -= 2;
    // 80133F6C: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80133F70:
    ctx->pc = 0x80133F70u;
    // 80133F70: bl      0x80132FD8
    {
            ctx->lr = 0x80133F74u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80133F74:
    ctx->pc = 0x80133F74u;
    ctx->downcount -= 2;
    // 80133F74: cmpwi   r3, 0
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

label_80133F78:
    ctx->pc = 0x80133F78u;
    // 80133F78: bc    12, 2, 0x80133FC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80133FC4;
        }
    }

label_80133F7C:
    ctx->pc = 0x80133F7Cu;
    ctx->downcount -= 5;
    // 80133F7C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133F80:
    ctx->pc = 0x80133F80u;
    // 80133F80: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80133F84:
    ctx->pc = 0x80133F84u;
    // 80133F84: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80133F84u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133F88:
    ctx->pc = 0x80133F88u;
    // 80133F88: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80133F8C:
    ctx->pc = 0x80133F8Cu;
    // 80133F8C: bl      0x8004DC00
    {
            ctx->lr = 0x80133F90u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80133F90:
    ctx->pc = 0x80133F90u;
    ctx->downcount -= 13;
    // 80133F90: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80133F94:
    ctx->pc = 0x80133F94u;
    // 80133F94: lis     r11, -32733
    ctx->gpr[11] = ((u32)(s32)(-32733) << 16);

label_80133F98:
    ctx->pc = 0x80133F98u;
    // 80133F98: lha     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133F9C:
    ctx->pc = 0x80133F9Cu;
    // 80133F9C: addi    r11, r11, 28640
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(28640);

label_80133FA0:
    ctx->pc = 0x80133FA0u;
    // 80133FA0: addi    r10, r11, 4
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(4);

label_80133FA4:
    ctx->pc = 0x80133FA4u;
    // 80133FA4: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80133FA8:
    ctx->pc = 0x80133FA8u;
    // 80133FA8: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80133FAC:
    ctx->pc = 0x80133FACu;
    // 80133FAC: lwzx    r8, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80133FB0:
    ctx->pc = 0x80133FB0u;
    // 80133FB0: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80133FB4:
    ctx->pc = 0x80133FB4u;
    // 80133FB4: lwzx    r10, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80133FB8:
    ctx->pc = 0x80133FB8u;
    // 80133FB8: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80133FBC:
    ctx->pc = 0x80133FBCu;
    // 80133FBC: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80133FC0:
    ctx->pc = 0x80133FC0u;
    // 80133FC0: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80133FC4:
    ctx->pc = 0x80133FC4u;
    ctx->downcount -= 2;
    // 80133FC4: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_80133FC8:
    ctx->pc = 0x80133FC8u;
    // 80133FC8: bl      0x80132FD8
    {
            ctx->lr = 0x80133FCCu;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80133FCC:
    ctx->pc = 0x80133FCCu;
    ctx->downcount -= 2;
    // 80133FCC: cmpwi   r3, 0
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

label_80133FD0:
    ctx->pc = 0x80133FD0u;
    // 80133FD0: bc    12, 2, 0x8013401C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013401C;
        }
    }

label_80133FD4:
    ctx->pc = 0x80133FD4u;
    ctx->downcount -= 5;
    // 80133FD4: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80133FD8:
    ctx->pc = 0x80133FD8u;
    // 80133FD8: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80133FDC:
    ctx->pc = 0x80133FDCu;
    // 80133FDC: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80133FDCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80133FE0:
    ctx->pc = 0x80133FE0u;
    // 80133FE0: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80133FE4:
    ctx->pc = 0x80133FE4u;
    // 80133FE4: bl      0x8004DC00
    {
            ctx->lr = 0x80133FE8u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80133FE8:
    ctx->pc = 0x80133FE8u;
    ctx->downcount -= 13;
    // 80133FE8: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80133FEC:
    ctx->pc = 0x80133FECu;
    // 80133FEC: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80133FF0:
    ctx->pc = 0x80133FF0u;
    // 80133FF0: lha     r0, -21584(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80133FF4:
    ctx->pc = 0x80133FF4u;
    // 80133FF4: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80133FF8:
    ctx->pc = 0x80133FF8u;
    // 80133FF8: addi    r10, r9, 4
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(4);

label_80133FFC:
    ctx->pc = 0x80133FFCu;
    // 80133FFC: lwz     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80134000:
    ctx->pc = 0x80134000u;
    // 80134000: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80134004:
    ctx->pc = 0x80134004u;
    // 80134004: lwzx    r8, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80134008:
    ctx->pc = 0x80134008u;
    // 80134008: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_8013400C:
    ctx->pc = 0x8013400Cu;
    // 8013400C: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80134010:
    ctx->pc = 0x80134010u;
    // 80134010: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80134014:
    ctx->pc = 0x80134014u;
    // 80134014: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80134018:
    ctx->pc = 0x80134018u;
    // 80134018: stw     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8013401C:
    ctx->pc = 0x8013401Cu;
    ctx->downcount -= 3;
    // 8013401C: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80134020:
    ctx->pc = 0x80134020u;
    // 80134020: cmpwi   r0, 0
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

label_80134024:
    ctx->pc = 0x80134024u;
    // 80134024: bc    4, 0, 0x80134034
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134034;
        }
    }

label_80134028:
    ctx->pc = 0x80134028u;
    ctx->downcount -= 3;
    // 80134028: lwz     r9, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013402C:
    ctx->pc = 0x8013402Cu;
    // 8013402C: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80134030:
    ctx->pc = 0x80134030u;
    // 80134030: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80134034:
    ctx->pc = 0x80134034u;
    ctx->downcount -= 4;
    // 80134034: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80134038:
    ctx->pc = 0x80134038u;
    // 80134038: lwz     r0, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013403C:
    ctx->pc = 0x8013403Cu;
    // 8013403C: cmpw    r9, r0
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

label_80134040:
    ctx->pc = 0x80134040u;
    // 80134040: bc    12, 0, 0x8013404C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013404C;
        }
    }

label_80134044:
    ctx->pc = 0x80134044u;
    ctx->downcount -= 2;
    // 80134044: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80134048:
    ctx->pc = 0x80134048u;
    // 80134048: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013404C:
    ctx->pc = 0x8013404Cu;
    ctx->downcount -= 1;
    // 8013404C: bl      0x800B7A5C
    {
            ctx->lr = 0x80134050u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80134050:
    ctx->pc = 0x80134050u;
    ctx->downcount -= 5;
    // 80134050: lis     r25, -32737
    ctx->gpr[25] = ((u32)(s32)(-32737) << 16);

label_80134054:
    ctx->pc = 0x80134054u;
    // 80134054: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80134058:
    ctx->pc = 0x80134058u;
    // 80134058: lis     r27, -32737
    ctx->gpr[27] = ((u32)(s32)(-32737) << 16);

label_8013405C:
    ctx->pc = 0x8013405Cu;
    // 8013405C: lha     r3, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80134060:
    ctx->pc = 0x80134060u;
    // 80134060: bl      0x80132E34
    {
            ctx->lr = 0x80134064u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80134064:
    ctx->pc = 0x80134064u;
    ctx->downcount -= 5;
    // 80134064: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134068:
    ctx->pc = 0x80134068u;
    // 80134068: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_8013406C:
    ctx->pc = 0x8013406Cu;
    // 8013406C: lfs     f1, 5920(r9)
    if (!ppc_fp_available(ctx, 0x8013406Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5920);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134070:
    ctx->pc = 0x80134070u;
    // 80134070: lfs     f2, 5924(r11)
    if (!ppc_fp_available(ctx, 0x80134070u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5924);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80134074:
    ctx->pc = 0x80134074u;
    // 80134074: bl      0x80133200
    {
            ctx->lr = 0x80134078u;
            ctx->pc = 0x80133200u;
            return;
    }

label_80134078:
    ctx->pc = 0x80134078u;
    ctx->downcount -= 41;
    // 80134078: lwz     r0, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013407C:
    ctx->pc = 0x8013407Cu;
    // 8013407C: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_80134080:
    ctx->pc = 0x80134080u;
    // 80134080: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134084:
    ctx->pc = 0x80134084u;
    // 80134084: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_80134088:
    ctx->pc = 0x80134088u;
    // 80134088: lfd     f13, 5928(r9)
    if (!ppc_fp_available(ctx, 0x80134088u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5928);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8013408C:
    ctx->pc = 0x8013408Cu;
    // 8013408C: stw     r0, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80134090:
    ctx->pc = 0x80134090u;
    // 80134090: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134094:
    ctx->pc = 0x80134094u;
    // 80134094: lfs     f31, 5936(r9)
    if (!ppc_fp_available(ctx, 0x80134094u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5936);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80134098:
    ctx->pc = 0x80134098u;
    // 80134098: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8013409C:
    ctx->pc = 0x8013409Cu;
    // 8013409C: stw     r8, 18568(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801340A0:
    ctx->pc = 0x801340A0u;
    // 801340A0: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801340A4:
    ctx->pc = 0x801340A4u;
    // 801340A4: lfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x801340A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801340A8:
    ctx->pc = 0x801340A8u;
    // 801340A8: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_801340AC:
    ctx->pc = 0x801340ACu;
    // 801340AC: lfs     f2, -27048(r13)
    if (!ppc_fp_available(ctx, 0x801340ACu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27048);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_801340B0:
    ctx->pc = 0x801340B0u;
    // 801340B0: fsub   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x801340B0u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_801340B4:
    ctx->pc = 0x801340B4u;
    // 801340B4: stw     r0, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801340B8:
    ctx->pc = 0x801340B8u;
    // 801340B8: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x801340B8u)) return;
    ppc_frsp(ctx, 0, 0);

label_801340BC:
    ctx->pc = 0x801340BCu;
    // 801340BC: fdivs   f26, f31, f0
    if (!ppc_fp_available(ctx, 0x801340BCu)) return;
    ppc_fdivs(ctx, 26, 31, 0);

label_801340C0:
    ctx->pc = 0x801340C0u;
    // 801340C0: stw     r8, 18568(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801340C4:
    ctx->pc = 0x801340C4u;
    // 801340C4: lfd     f1, 18568(r1)
    if (!ppc_fp_available(ctx, 0x801340C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801340C8:
    ctx->pc = 0x801340C8u;
    // 801340C8: fsub   f1, f1, f13
    if (!ppc_fp_available(ctx, 0x801340C8u)) return;
    ppc_fsub(ctx, 1, 1, 13);

label_801340CC:
    ctx->pc = 0x801340CCu;
    // 801340CC: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x801340CCu)) return;
    ppc_frsp(ctx, 1, 1);

label_801340D0:
    ctx->pc = 0x801340D0u;
    // 801340D0: fmuls   f1, f26, f1
    if (!ppc_fp_available(ctx, 0x801340D0u)) return;
    ppc_fmuls(ctx, 1, 26, 1);

label_801340D4:
    ctx->pc = 0x801340D4u;
    // 801340D4: fneg    f1, f1
    if (!ppc_fp_available(ctx, 0x801340D4u)) return;
    ctx->fpr[1] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_801340D8:
    ctx->pc = 0x801340D8u;
    // 801340D8: bl      0x80040A40
    {
            ctx->lr = 0x801340DCu;
            ctx->pc = 0x80040A40u;
            return;
    }

label_801340DC:
    ctx->pc = 0x801340DCu;
    ctx->downcount -= 26;
    // 801340DC: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_801340E0:
    ctx->pc = 0x801340E0u;
    // 801340E0: lfs     f13, -27048(r13)
    if (!ppc_fp_available(ctx, 0x801340E0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27048);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801340E4:
    ctx->pc = 0x801340E4u;
    // 801340E4: lfs     f0, 5940(r11)
    if (!ppc_fp_available(ctx, 0x801340E4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5940);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801340E8:
    ctx->pc = 0x801340E8u;
    // 801340E8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801340EC:
    ctx->pc = 0x801340ECu;
    // 801340EC: lfs     f11, 5900(r9)
    if (!ppc_fp_available(ctx, 0x801340ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5900);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_801340F0:
    ctx->pc = 0x801340F0u;
    // 801340F0: fdivs   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x801340F0u)) return;
    ppc_fdivs(ctx, 1, 1, 0);

label_801340F4:
    ctx->pc = 0x801340F4u;
    // 801340F4: fsubs   f13, f13, f1
    if (!ppc_fp_available(ctx, 0x801340F4u)) return;
    ppc_fsubs(ctx, 13, 13, 1);

label_801340F8:
    ctx->pc = 0x801340F8u;
    // 801340F8: stfs     f13, -27048(r13)
    if (!ppc_fp_available(ctx, 0x801340F8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27048);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_801340FC:
    ctx->pc = 0x801340FCu;
    // 801340FC: fcmpu   cr0, f13, f11
    if (!ppc_fp_available(ctx, 0x801340FCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[13], ctx->fpr[11], false);

label_80134100:
    ctx->pc = 0x80134100u;
    // 80134100: bc    4, 0, 0x8013411C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013411C;
        }
    }

label_80134104:
    ctx->pc = 0x80134104u;
    ctx->downcount -= 2;
    // 80134104: fmr    f12, f31
    if (!ppc_fp_available(ctx, 0x80134104u)) return;
    ctx->fpr[12] = ctx->fpr[31];

label_80134108:
    ctx->pc = 0x80134108u;
    // 80134108: fmr    f0, f11
    if (!ppc_fp_available(ctx, 0x80134108u)) return;
    ctx->fpr[0] = ctx->fpr[11];

label_8013410C:
    ctx->pc = 0x8013410Cu;
    ctx->downcount -= 3;
    // 8013410C: fadds   f13, f13, f12
    if (!ppc_fp_available(ctx, 0x8013410Cu)) return;
    ppc_fadds(ctx, 13, 13, 12);

label_80134110:
    ctx->pc = 0x80134110u;
    // 80134110: fcmpu   cr0, f13, f0
    if (!ppc_fp_available(ctx, 0x80134110u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[13], ctx->fpr[0], false);

label_80134114:
    // 80134114: bc    12, 0, 0x8013410C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013410Cu;
                return;
            }
            goto label_8013410C;
        }
    }

label_80134118:
    ctx->pc = 0x80134118u;
    ctx->downcount -= 1;
    // 80134118: stfs     f13, -27048(r13)
    if (!ppc_fp_available(ctx, 0x80134118u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27048);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8013411C:
    ctx->pc = 0x8013411Cu;
    ctx->downcount -= 5;
    // 8013411C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134120:
    ctx->pc = 0x80134120u;
    // 80134120: lfs     f13, -27048(r13)
    if (!ppc_fp_available(ctx, 0x80134120u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27048);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80134124:
    ctx->pc = 0x80134124u;
    // 80134124: lfs     f0, 5936(r9)
    if (!ppc_fp_available(ctx, 0x80134124u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5936);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80134128:
    ctx->pc = 0x80134128u;
    // 80134128: fcmpu   cr0, f13, f0
    if (!ppc_fp_available(ctx, 0x80134128u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[13], ctx->fpr[0], false);

label_8013412C:
    ctx->pc = 0x8013412Cu;
    // 8013412C: bc    4, 1, 0x80134148
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134148;
        }
    }

label_80134130:
    ctx->pc = 0x80134130u;
    ctx->downcount -= 1;
    // 80134130: fmr    f12, f0
    if (!ppc_fp_available(ctx, 0x80134130u)) return;
    ctx->fpr[12] = ctx->fpr[0];

label_80134134:
    ctx->pc = 0x80134134u;
    ctx->downcount -= 4;
    // 80134134: fsubs   f0, f13, f12
    if (!ppc_fp_available(ctx, 0x80134134u)) return;
    ppc_fsubs(ctx, 0, 13, 12);

label_80134138:
    ctx->pc = 0x80134138u;
    // 80134138: fmr    f13, f0
    if (!ppc_fp_available(ctx, 0x80134138u)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_8013413C:
    ctx->pc = 0x8013413Cu;
    // 8013413C: fcmpu   cr0, f0, f12
    if (!ppc_fp_available(ctx, 0x8013413Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[12], false);

label_80134140:
    // 80134140: bc    12, 1, 0x80134134
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80134134u;
                return;
            }
            goto label_80134134;
        }
    }

label_80134144:
    ctx->pc = 0x80134144u;
    ctx->downcount -= 1;
    // 80134144: stfs     f0, -27048(r13)
    if (!ppc_fp_available(ctx, 0x80134144u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27048);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_80134148:
    ctx->pc = 0x80134148u;
    ctx->downcount -= 7;
    // 80134148: lwz     r0, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013414C:
    ctx->pc = 0x8013414Cu;
    // 8013414C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134150:
    ctx->pc = 0x80134150u;
    // 80134150: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80134154:
    ctx->pc = 0x80134154u;
    // 80134154: lfs     f28, 5944(r9)
    if (!ppc_fp_available(ctx, 0x80134154u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5944);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[28] = value;
        ctx->ps1[28] = value;
    }

label_80134158:
    ctx->pc = 0x80134158u;
    // 80134158: cmpw    r26, r0
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

label_8013415C:
    ctx->pc = 0x8013415Cu;
    // 8013415C: lfs     f31, -27048(r13)
    if (!ppc_fp_available(ctx, 0x8013415Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27048);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_80134160:
    ctx->pc = 0x80134160u;
    // 80134160: bc    4, 0, 0x80135BF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135BF0;
        }
    }

label_80134164:
    ctx->pc = 0x80134164u;
    ctx->downcount -= 18;
    // 80134164: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134168:
    ctx->pc = 0x80134168u;
    // 80134168: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_8013416C:
    ctx->pc = 0x8013416Cu;
    // 8013416C: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_80134170:
    ctx->pc = 0x80134170u;
    // 80134170: lfs     f20, 5948(r9)
    if (!ppc_fp_available(ctx, 0x80134170u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5948);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[20] = value;
        ctx->ps1[20] = value;
    }

label_80134174:
    ctx->pc = 0x80134174u;
    // 80134174: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134178:
    ctx->pc = 0x80134178u;
    // 80134178: lfs     f27, 5952(r11)
    if (!ppc_fp_available(ctx, 0x80134178u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5952);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[27] = value;
        ctx->ps1[27] = value;
    }

label_8013417C:
    ctx->pc = 0x8013417Cu;
    // 8013417C: lfs     f21, 5956(r10)
    if (!ppc_fp_available(ctx, 0x8013417Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(5956);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[21] = value;
        ctx->ps1[21] = value;
    }

label_80134180:
    ctx->pc = 0x80134180u;
    // 80134180: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_80134184:
    ctx->pc = 0x80134184u;
    // 80134184: lfs     f22, 5960(r9)
    if (!ppc_fp_available(ctx, 0x80134184u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5960);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[22] = value;
        ctx->ps1[22] = value;
    }

label_80134188:
    ctx->pc = 0x80134188u;
    // 80134188: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_8013418C:
    ctx->pc = 0x8013418Cu;
    // 8013418C: lis     r8, -32737
    ctx->gpr[8] = ((u32)(s32)(-32737) << 16);

label_80134190:
    ctx->pc = 0x80134190u;
    // 80134190: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_80134194:
    ctx->pc = 0x80134194u;
    // 80134194: lfs     f23, 5916(r11)
    if (!ppc_fp_available(ctx, 0x80134194u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5916);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[23] = value;
        ctx->ps1[23] = value;
    }

label_80134198:
    ctx->pc = 0x80134198u;
    // 80134198: addi    r30, r9, -18172
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-18172);

label_8013419C:
    ctx->pc = 0x8013419Cu;
    // 8013419C: lfs     f24, 5964(r10)
    if (!ppc_fp_available(ctx, 0x8013419Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(5964);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[24] = value;
        ctx->ps1[24] = value;
    }

label_801341A0:
    ctx->pc = 0x801341A0u;
    // 801341A0: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_801341A4:
    ctx->pc = 0x801341A4u;
    // 801341A4: lfs     f25, 5968(r8)
    if (!ppc_fp_available(ctx, 0x801341A4u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(5968);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[25] = value;
        ctx->ps1[25] = value;
    }

label_801341A8:
    ctx->pc = 0x801341A8u;
    // 801341A8: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801341AC:
    ctx->pc = 0x801341ACu;
    ctx->downcount -= 2;
    // 801341AC: fmr    f1, f31
    if (!ppc_fp_available(ctx, 0x801341ACu)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801341B0:
    // 801341B0: bl      0x801659BC
    {
            ctx->lr = 0x801341B4u;
            ctx->pc = 0x801659BCu;
            return;
    }

label_801341B4:
    ctx->pc = 0x801341B4u;
    ctx->downcount -= 3;
    // 801341B4: fadds   f30, f1, f1
    if (!ppc_fp_available(ctx, 0x801341B4u)) return;
    ppc_fadds(ctx, 30, 1, 1);

label_801341B8:
    ctx->pc = 0x801341B8u;
    // 801341B8: fmr    f1, f31
    if (!ppc_fp_available(ctx, 0x801341B8u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801341BC:
    // 801341BC: bl      0x801657E4
    {
            ctx->lr = 0x801341C0u;
            ctx->pc = 0x801657E4u;
            return;
    }

label_801341C0:
    ctx->pc = 0x801341C0u;
    ctx->downcount -= 3;
    // 801341C0: fmsubs f29, f1, f20, f27
    if (!ppc_fp_available(ctx, 0x801341C0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[20], ctx->fpr[27], true, true, false, &result))
            ctx->fpr[29] = ctx->ps1[29] = result;
    }

label_801341C4:
    ctx->pc = 0x801341C4u;
    // 801341C4: fmr    f1, f31
    if (!ppc_fp_available(ctx, 0x801341C4u)) return;
    ctx->fpr[1] = ctx->fpr[31];

label_801341C8:
    // 801341C8: bl      0x801657E4
    {
            ctx->lr = 0x801341CCu;
            ctx->pc = 0x801657E4u;
            return;
    }

label_801341CC:
    ctx->downcount -= 6;
    // 801341CC: rlwinm r0, r26, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[26], 2u) & 0xFFFFFFFCu;
    }

label_801341D0:
    ctx->pc = 0x801341D0u;
    // 801341D0: fmadds f0, f1, f21, f22
    if (!ppc_fp_available(ctx, 0x801341D0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[1], ctx->fpr[21], ctx->fpr[22], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_801341D4:
    ctx->pc = 0x801341D4u;
    // 801341D4: lwzx    r11, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801341D8:
    // 801341D8: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801341DC:
    // 801341DC: cmpwi   r11, 0
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

label_801341E0:
    // 801341E0: bc    12, 2, 0x80134244
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134244;
        }
    }

label_801341E4:
    ctx->downcount -= 9;
    // 801341E4: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_801341E8:
    ctx->pc = 0x801341E8u;
    // 801341E8: stfsu     f30, 4(r9)
    if (!ppc_fp_available(ctx, 0x801341E8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[30]));
        ctx->gpr[9] = ea;
    }

label_801341EC:
    ctx->pc = 0x801341ECu;
    // 801341EC: stfs     f0, 8(r9)
    if (!ppc_fp_available(ctx, 0x801341ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_801341F0:
    ctx->pc = 0x801341F0u;
    // 801341F0: stfs     f29, 4(r9)
    if (!ppc_fp_available(ctx, 0x801341F0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[29]));
    }

label_801341F4:
    ctx->pc = 0x801341F4u;
    // 801341F4: stw     r29, 236(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(236);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801341F8:
    ctx->pc = 0x801341F8u;
    // 801341F8: sth     r28, 48(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_801341FC:
    ctx->pc = 0x801341FCu;
    // 801341FC: lwzx    r3, r30, r31
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[31];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80134200:
    // 80134200: cmpwi   r3, 0
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

label_80134204:
    // 80134204: bc    12, 2, 0x80134244
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134244;
        }
    }

label_80134208:
    ctx->pc = 0x80134208u;
    ctx->downcount -= 3;
    // 80134208: lfs     f0, 5900(r25)
    if (!ppc_fp_available(ctx, 0x80134208u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(5900);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8013420C:
    ctx->pc = 0x8013420Cu;
    // 8013420C: fcmpu   cr0, f28, f0
    if (!ppc_fp_available(ctx, 0x8013420Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[28], ctx->fpr[0], false);

label_80134210:
    // 80134210: bc    4, 0, 0x80134224
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134224;
        }
    }

label_80134214:
    ctx->downcount -= 2;
    // 80134214: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80134218:
    // 80134218: bl      0x800424CC
    {
            ctx->lr = 0x8013421Cu;
            ctx->pc = 0x800424CCu;
            return;
    }

label_8013421C:
    ctx->pc = 0x8013421Cu;
    ctx->downcount -= 2;
    // 8013421C: fadds   f28, f1, f27
    if (!ppc_fp_available(ctx, 0x8013421Cu)) return;
    ppc_fadds(ctx, 28, 1, 27);

label_80134220:
    // 80134220: b       0x80134228
    {
            goto label_80134228;
    }

label_80134224:
    ctx->pc = 0x80134224u;
    ctx->downcount -= 1;
    // 80134224: fadds   f28, f28, f23
    if (!ppc_fp_available(ctx, 0x80134224u)) return;
    ppc_fadds(ctx, 28, 28, 23);

label_80134228:
    ctx->pc = 0x80134228u;
    ctx->downcount -= 2;
    // 80134228: fcmpu   cr0, f28, f24
    if (!ppc_fp_available(ctx, 0x80134228u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[28], ctx->fpr[24], false);

label_8013422C:
    // 8013422C: bc    4, 1, 0x80134234
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134234;
        }
    }

label_80134230:
    ctx->pc = 0x80134230u;
    ctx->downcount -= 1;
    // 80134230: fsubs   f28, f28, f25
    if (!ppc_fp_available(ctx, 0x80134230u)) return;
    ppc_fsubs(ctx, 28, 28, 25);

label_80134234:
    ctx->pc = 0x80134234u;
    ctx->downcount -= 4;
    // 80134234: lwzx    r3, r30, r31
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[31];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80134238:
    ctx->pc = 0x80134238u;
    // 80134238: fmr    f1, f28
    if (!ppc_fp_available(ctx, 0x80134238u)) return;
    ctx->fpr[1] = ctx->fpr[28];

label_8013423C:
    // 8013423C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80134240:
    // 80134240: bl      0x800424F8
    {
            ctx->lr = 0x80134244u;
            ctx->pc = 0x800424F8u;
            return;
    }

label_80134244:
    ctx->pc = 0x80134244u;
    ctx->downcount -= 6;
    // 80134244: lfs     f0, 5936(r27)
    if (!ppc_fp_available(ctx, 0x80134244u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(5936);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80134248:
    ctx->pc = 0x80134248u;
    // 80134248: fadds   f31, f31, f26
    if (!ppc_fp_available(ctx, 0x80134248u)) return;
    ppc_fadds(ctx, 31, 31, 26);

label_8013424C:
    // 8013424C: addi    r0, r26, 1
    ctx->gpr[0] = ctx->gpr[26] + (u32)(s32)(1);

label_80134250:
    ctx->pc = 0x80134250u;
    // 80134250: lwz     r9, -27068(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27068);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80134254:
    ctx->pc = 0x80134254u;
    // 80134254: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134254u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134258:
    // 80134258: bc    4, 1, 0x80134268
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134268;
        }
    }

label_8013425C:
    ctx->pc = 0x8013425Cu;
    ctx->downcount -= 3;
    // 8013425C: fsubs   f31, f31, f0
    if (!ppc_fp_available(ctx, 0x8013425Cu)) return;
    ppc_fsubs(ctx, 31, 31, 0);

label_80134260:
    ctx->pc = 0x80134260u;
    // 80134260: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134260u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134264:
    // 80134264: bc    12, 1, 0x8013425C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013425Cu;
                return;
            }
            goto label_8013425C;
        }
    }

label_80134268:
    ctx->downcount -= 3;
    // 80134268: or   r26, r0, r0
    {
        ctx->gpr[26] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8013426C:
    // 8013426C: cmpw    r26, r9
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80134270:
    // 80134270: bc    12, 0, 0x801341AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801341ACu;
                return;
            }
            goto label_801341AC;
        }
    }

label_80134274:
    ctx->pc = 0x80134274u;
    ctx->downcount -= 1;
    // 80134274: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80134278:
    ctx->pc = 0x80134278u;
    ctx->downcount -= 4;
    // 80134278: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_8013427C:
    ctx->pc = 0x8013427Cu;
    // 8013427C: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80134280:
    ctx->pc = 0x80134280u;
    // 80134280: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134284:
    ctx->pc = 0x80134284u;
    // 80134284: bl      0x80034BA8
    {
            ctx->lr = 0x80134288u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80134288:
    ctx->pc = 0x80134288u;
    ctx->downcount -= 3;
    // 80134288: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_8013428C:
    ctx->pc = 0x8013428Cu;
    // 8013428C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134290:
    ctx->pc = 0x80134290u;
    // 80134290: bl      0x80035C48
    {
            ctx->lr = 0x80134294u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80134294:
    ctx->pc = 0x80134294u;
    ctx->downcount -= 5;
    // 80134294: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134298:
    ctx->pc = 0x80134298u;
    // 80134298: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013429C:
    ctx->pc = 0x8013429Cu;
    // 8013429C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x8013429Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801342A0:
    ctx->pc = 0x801342A0u;
    // 801342A0: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801342A0u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801342A4:
    ctx->pc = 0x801342A4u;
    // 801342A4: bl      0x80034E6C
    {
            ctx->lr = 0x801342A8u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_801342A8:
    ctx->pc = 0x801342A8u;
    ctx->downcount -= 3;
    // 801342A8: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801342AC:
    ctx->pc = 0x801342ACu;
    // 801342AC: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801342B0:
    ctx->pc = 0x801342B0u;
    // 801342B0: bl      0x800353D4
    {
            ctx->lr = 0x801342B4u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_801342B4:
    ctx->pc = 0x801342B4u;
    ctx->downcount -= 4;
    // 801342B4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801342B8:
    ctx->pc = 0x801342B8u;
    // 801342B8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801342BC:
    ctx->pc = 0x801342BCu;
    // 801342BC: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801342C0:
    ctx->pc = 0x801342C0u;
    // 801342C0: bl      0x80035C50
    {
            ctx->lr = 0x801342C4u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_801342C4:
    ctx->pc = 0x801342C4u;
    ctx->downcount -= 1;
    // 801342C4: bl      0x800B7A5C
    {
            ctx->lr = 0x801342C8u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_801342C8:
    ctx->pc = 0x801342C8u;
    ctx->downcount -= 2;
    // 801342C8: lha     r3, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801342CC:
    ctx->pc = 0x801342CCu;
    // 801342CC: bl      0x80132E34
    {
            ctx->lr = 0x801342D0u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_801342D0:
    ctx->pc = 0x801342D0u;
    ctx->downcount -= 4;
    // 801342D0: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801342D4:
    ctx->pc = 0x801342D4u;
    // 801342D4: li      r4, 4629
    ctx->gpr[4] = (u32)(s32)(4629);

label_801342D8:
    ctx->pc = 0x801342D8u;
    // 801342D8: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_801342DC:
    ctx->pc = 0x801342DCu;
    // 801342DC: bl      0x80046B00
    {
            ctx->lr = 0x801342E0u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801342E0:
    ctx->pc = 0x801342E0u;
    ctx->downcount -= 5;
    // 801342E0: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801342E4:
    ctx->pc = 0x801342E4u;
    // 801342E4: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_801342E8:
    ctx->pc = 0x801342E8u;
    // 801342E8: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801342EC:
    ctx->pc = 0x801342ECu;
    // 801342EC: li      r5, 150
    ctx->gpr[5] = (u32)(s32)(150);

label_801342F0:
    ctx->pc = 0x801342F0u;
    // 801342F0: bl      0x80034F4C
    {
            ctx->lr = 0x801342F4u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_801342F4:
    ctx->pc = 0x801342F4u;
    ctx->downcount -= 1;
    // 801342F4: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_801342F8:
    ctx->pc = 0x801342F8u;
    ctx->downcount -= 4;
    // 801342F8: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_801342FC:
    ctx->pc = 0x801342FCu;
    // 801342FC: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80134300:
    ctx->pc = 0x80134300u;
    // 80134300: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134304:
    ctx->pc = 0x80134304u;
    // 80134304: bl      0x80034BA8
    {
            ctx->lr = 0x80134308u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80134308:
    ctx->pc = 0x80134308u;
    ctx->downcount -= 3;
    // 80134308: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_8013430C:
    ctx->pc = 0x8013430Cu;
    // 8013430C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134310:
    ctx->pc = 0x80134310u;
    // 80134310: bl      0x80035C48
    {
            ctx->lr = 0x80134314u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80134314:
    ctx->pc = 0x80134314u;
    ctx->downcount -= 5;
    // 80134314: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134318:
    ctx->pc = 0x80134318u;
    // 80134318: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013431C:
    ctx->pc = 0x8013431Cu;
    // 8013431C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x8013431Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134320:
    ctx->pc = 0x80134320u;
    // 80134320: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80134320u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80134324:
    ctx->pc = 0x80134324u;
    // 80134324: bl      0x80034E6C
    {
            ctx->lr = 0x80134328u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80134328:
    ctx->pc = 0x80134328u;
    ctx->downcount -= 3;
    // 80134328: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013432C:
    ctx->pc = 0x8013432Cu;
    // 8013432C: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80134330:
    ctx->pc = 0x80134330u;
    // 80134330: bl      0x800353D4
    {
            ctx->lr = 0x80134334u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_80134334:
    ctx->pc = 0x80134334u;
    ctx->downcount -= 4;
    // 80134334: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80134338:
    ctx->pc = 0x80134338u;
    // 80134338: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8013433C:
    ctx->pc = 0x8013433Cu;
    // 8013433C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134340:
    ctx->pc = 0x80134340u;
    // 80134340: bl      0x80035C50
    {
            ctx->lr = 0x80134344u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_80134344:
    ctx->pc = 0x80134344u;
    ctx->downcount -= 1;
    // 80134344: bl      0x800B7A5C
    {
            ctx->lr = 0x80134348u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80134348:
    ctx->pc = 0x80134348u;
    ctx->downcount -= 2;
    // 80134348: lha     r3, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8013434C:
    ctx->pc = 0x8013434Cu;
    // 8013434C: bl      0x80132E34
    {
            ctx->lr = 0x80134350u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80134350:
    ctx->pc = 0x80134350u;
    ctx->downcount -= 4;
    // 80134350: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80134354:
    ctx->pc = 0x80134354u;
    // 80134354: li      r4, 3587
    ctx->gpr[4] = (u32)(s32)(3587);

label_80134358:
    ctx->pc = 0x80134358u;
    // 80134358: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_8013435C:
    ctx->pc = 0x8013435Cu;
    // 8013435C: bl      0x80046B00
    {
            ctx->lr = 0x80134360u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134360:
    ctx->pc = 0x80134360u;
    ctx->downcount -= 5;
    // 80134360: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134364:
    ctx->pc = 0x80134364u;
    // 80134364: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_80134368:
    ctx->pc = 0x80134368u;
    // 80134368: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013436C:
    ctx->pc = 0x8013436Cu;
    // 8013436C: li      r5, 250
    ctx->gpr[5] = (u32)(s32)(250);

label_80134370:
    ctx->pc = 0x80134370u;
    // 80134370: bl      0x80034F4C
    {
            ctx->lr = 0x80134374u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_80134374:
    ctx->pc = 0x80134374u;
    ctx->downcount -= 1;
    // 80134374: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80134378:
    ctx->pc = 0x80134378u;
    ctx->downcount -= 5;
    // 80134378: lis     r30, -32697
    ctx->gpr[30] = ((u32)(s32)(-32697) << 16);

label_8013437C:
    ctx->pc = 0x8013437Cu;
    // 8013437C: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80134380:
    ctx->pc = 0x80134380u;
    // 80134380: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80134384:
    ctx->pc = 0x80134384u;
    // 80134384: lis     r29, -32697
    ctx->gpr[29] = ((u32)(s32)(-32697) << 16);

label_80134388:
    ctx->pc = 0x80134388u;
    // 80134388: bl      0x80034BA8
    {
            ctx->lr = 0x8013438Cu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8013438C:
    ctx->pc = 0x8013438Cu;
    ctx->downcount -= 3;
    // 8013438C: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80134390:
    ctx->pc = 0x80134390u;
    // 80134390: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80134394:
    ctx->pc = 0x80134394u;
    // 80134394: bl      0x80035C48
    {
            ctx->lr = 0x80134398u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80134398:
    ctx->pc = 0x80134398u;
    ctx->downcount -= 5;
    // 80134398: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013439C:
    ctx->pc = 0x8013439Cu;
    // 8013439C: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801343A0:
    ctx->pc = 0x801343A0u;
    // 801343A0: lfs     f1, 5948(r9)
    if (!ppc_fp_available(ctx, 0x801343A0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5948);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801343A4:
    ctx->pc = 0x801343A4u;
    // 801343A4: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801343A4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801343A8:
    ctx->pc = 0x801343A8u;
    // 801343A8: bl      0x80034E6C
    {
            ctx->lr = 0x801343ACu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_801343AC:
    ctx->pc = 0x801343ACu;
    ctx->downcount -= 3;
    // 801343AC: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801343B0:
    ctx->pc = 0x801343B0u;
    // 801343B0: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801343B4:
    ctx->pc = 0x801343B4u;
    // 801343B4: bl      0x800353D4
    {
            ctx->lr = 0x801343B8u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_801343B8:
    ctx->pc = 0x801343B8u;
    ctx->downcount -= 4;
    // 801343B8: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801343BC:
    ctx->pc = 0x801343BCu;
    // 801343BC: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801343C0:
    ctx->pc = 0x801343C0u;
    // 801343C0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801343C4:
    ctx->pc = 0x801343C4u;
    // 801343C4: bl      0x80035C50
    {
            ctx->lr = 0x801343C8u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_801343C8:
    ctx->pc = 0x801343C8u;
    ctx->downcount -= 1;
    // 801343C8: bl      0x800B7A5C
    {
            ctx->lr = 0x801343CCu;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_801343CC:
    ctx->pc = 0x801343CCu;
    ctx->downcount -= 2;
    // 801343CC: lha     r3, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801343D0:
    ctx->pc = 0x801343D0u;
    // 801343D0: bl      0x80132E34
    {
            ctx->lr = 0x801343D4u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_801343D4:
    ctx->pc = 0x801343D4u;
    ctx->downcount -= 3;
    // 801343D4: lwz     r0, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801343D8:
    ctx->pc = 0x801343D8u;
    // 801343D8: cmpwi   r0, 1679
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1679);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801343DC:
    ctx->pc = 0x801343DCu;
    // 801343DC: bc    12, 1, 0x80134434
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134434;
        }
    }

label_801343E0:
    ctx->pc = 0x801343E0u;
    ctx->downcount -= 3;
    // 801343E0: lwz     r0, -32364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32364);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801343E4:
    ctx->pc = 0x801343E4u;
    // 801343E4: andi.   r6, r0, 0x0010
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801343E8:
    ctx->pc = 0x801343E8u;
    // 801343E8: bc    12, 2, 0x801343FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801343FC;
        }
    }

label_801343EC:
    ctx->pc = 0x801343ECu;
    ctx->downcount -= 3;
    // 801343EC: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_801343F0:
    ctx->pc = 0x801343F0u;
    // 801343F0: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801343F4:
    ctx->pc = 0x801343F4u;
    // 801343F4: bl      0x80034BA8
    {
            ctx->lr = 0x801343F8u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801343F8:
    ctx->pc = 0x801343F8u;
    ctx->downcount -= 1;
    // 801343F8: b       0x8013440C
    {
            goto label_8013440C;
    }

label_801343FC:
    ctx->pc = 0x801343FCu;
    ctx->downcount -= 4;
    // 801343FC: lis     r4, -17536
    ctx->gpr[4] = ((u32)(s32)(-17536) << 16);

label_80134400:
    ctx->pc = 0x80134400u;
    // 80134400: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80134404:
    ctx->pc = 0x80134404u;
    // 80134404: ori     r4, r4, 0x8080
    ctx->gpr[4] = ctx->gpr[4] | 0x8080u;

label_80134408:
    ctx->pc = 0x80134408u;
    // 80134408: bl      0x80034BA8
    {
            ctx->lr = 0x8013440Cu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8013440C:
    ctx->pc = 0x8013440Cu;
    ctx->downcount -= 4;
    // 8013440C: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80134410:
    ctx->pc = 0x80134410u;
    // 80134410: li      r4, 3586
    ctx->gpr[4] = (u32)(s32)(3586);

label_80134414:
    ctx->pc = 0x80134414u;
    // 80134414: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_80134418:
    ctx->pc = 0x80134418u;
    // 80134418: bl      0x80046B00
    {
            ctx->lr = 0x8013441Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8013441C:
    ctx->pc = 0x8013441Cu;
    ctx->downcount -= 6;
    // 8013441C: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134420:
    ctx->pc = 0x80134420u;
    // 80134420: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_80134424:
    ctx->pc = 0x80134424u;
    // 80134424: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80134428:
    ctx->pc = 0x80134428u;
    // 80134428: li      r5, 300
    ctx->gpr[5] = (u32)(s32)(300);

label_8013442C:
    ctx->pc = 0x8013442Cu;
    // 8013442C: addi    r3, r3, -19280
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19280);

label_80134430:
    ctx->pc = 0x80134430u;
    // 80134430: bl      0x80034F4C
    {
            ctx->lr = 0x80134434u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_80134434:
    ctx->pc = 0x80134434u;
    ctx->downcount -= 4;
    // 80134434: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_80134438:
    ctx->pc = 0x80134438u;
    // 80134438: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8013443C:
    ctx->pc = 0x8013443Cu;
    // 8013443C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134440:
    ctx->pc = 0x80134440u;
    // 80134440: bl      0x80034BA8
    {
            ctx->lr = 0x80134444u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80134444:
    ctx->pc = 0x80134444u;
    ctx->downcount -= 3;
    // 80134444: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80134448:
    ctx->pc = 0x80134448u;
    // 80134448: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013444C:
    ctx->pc = 0x8013444Cu;
    // 8013444C: bl      0x80035C48
    {
            ctx->lr = 0x80134450u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80134450:
    ctx->pc = 0x80134450u;
    ctx->downcount -= 5;
    // 80134450: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134454:
    ctx->pc = 0x80134454u;
    // 80134454: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134458:
    ctx->pc = 0x80134458u;
    // 80134458: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80134458u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013445C:
    ctx->pc = 0x8013445Cu;
    // 8013445C: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x8013445Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80134460:
    ctx->pc = 0x80134460u;
    // 80134460: bl      0x80034E6C
    {
            ctx->lr = 0x80134464u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80134464:
    ctx->pc = 0x80134464u;
    ctx->downcount -= 3;
    // 80134464: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134468:
    ctx->pc = 0x80134468u;
    // 80134468: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8013446C:
    ctx->pc = 0x8013446Cu;
    // 8013446C: bl      0x800353D4
    {
            ctx->lr = 0x80134470u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_80134470:
    ctx->pc = 0x80134470u;
    ctx->downcount -= 4;
    // 80134470: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80134474:
    ctx->pc = 0x80134474u;
    // 80134474: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134478:
    ctx->pc = 0x80134478u;
    // 80134478: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8013447C:
    ctx->pc = 0x8013447Cu;
    // 8013447C: bl      0x80035C50
    {
            ctx->lr = 0x80134480u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_80134480:
    ctx->pc = 0x80134480u;
    ctx->downcount -= 4;
    // 80134480: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80134484:
    ctx->pc = 0x80134484u;
    // 80134484: li      r4, 4628
    ctx->gpr[4] = (u32)(s32)(4628);

label_80134488:
    ctx->pc = 0x80134488u;
    // 80134488: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_8013448C:
    ctx->pc = 0x8013448Cu;
    // 8013448C: bl      0x80046B00
    {
            ctx->lr = 0x80134490u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134490:
    ctx->pc = 0x80134490u;
    ctx->downcount -= 5;
    // 80134490: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134494:
    ctx->pc = 0x80134494u;
    // 80134494: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_80134498:
    ctx->pc = 0x80134498u;
    // 80134498: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013449C:
    ctx->pc = 0x8013449Cu;
    // 8013449C: li      r5, 380
    ctx->gpr[5] = (u32)(s32)(380);

label_801344A0:
    ctx->pc = 0x801344A0u;
    // 801344A0: bl      0x80034F4C
    {
            ctx->lr = 0x801344A4u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_801344A4:
    ctx->pc = 0x801344A4u;
    ctx->downcount -= 1;
    // 801344A4: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_801344A8:
    ctx->pc = 0x801344A8u;
    ctx->downcount -= 5;
    // 801344A8: lis     r30, -32697
    ctx->gpr[30] = ((u32)(s32)(-32697) << 16);

label_801344AC:
    ctx->pc = 0x801344ACu;
    // 801344AC: li      r4, -171
    ctx->gpr[4] = (u32)(s32)(-171);

label_801344B0:
    ctx->pc = 0x801344B0u;
    // 801344B0: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801344B4:
    ctx->pc = 0x801344B4u;
    // 801344B4: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_801344B8:
    ctx->pc = 0x801344B8u;
    // 801344B8: bl      0x80034BA8
    {
            ctx->lr = 0x801344BCu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801344BC:
    ctx->pc = 0x801344BCu;
    ctx->downcount -= 4;
    // 801344BC: lis     r29, -32697
    ctx->gpr[29] = ((u32)(s32)(-32697) << 16);

label_801344C0:
    ctx->pc = 0x801344C0u;
    // 801344C0: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_801344C4:
    ctx->pc = 0x801344C4u;
    // 801344C4: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801344C8:
    ctx->pc = 0x801344C8u;
    // 801344C8: bl      0x80035C48
    {
            ctx->lr = 0x801344CCu;
            ctx->pc = 0x80035C48u;
            return;
    }

label_801344CC:
    ctx->pc = 0x801344CCu;
    ctx->downcount -= 5;
    // 801344CC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801344D0:
    ctx->pc = 0x801344D0u;
    // 801344D0: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801344D4:
    ctx->pc = 0x801344D4u;
    // 801344D4: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x801344D4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801344D8:
    ctx->pc = 0x801344D8u;
    // 801344D8: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801344D8u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801344DC:
    ctx->pc = 0x801344DCu;
    // 801344DC: bl      0x80034E6C
    {
            ctx->lr = 0x801344E0u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_801344E0:
    ctx->pc = 0x801344E0u;
    ctx->downcount -= 3;
    // 801344E0: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801344E4:
    ctx->pc = 0x801344E4u;
    // 801344E4: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801344E8:
    ctx->pc = 0x801344E8u;
    // 801344E8: bl      0x800353D4
    {
            ctx->lr = 0x801344ECu;
            ctx->pc = 0x800353D4u;
            return;
    }

label_801344EC:
    ctx->pc = 0x801344ECu;
    ctx->downcount -= 4;
    // 801344EC: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801344F0:
    ctx->pc = 0x801344F0u;
    // 801344F0: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801344F4:
    ctx->pc = 0x801344F4u;
    // 801344F4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801344F8:
    ctx->pc = 0x801344F8u;
    // 801344F8: bl      0x80035C50
    {
            ctx->lr = 0x801344FCu;
            ctx->pc = 0x80035C50u;
            return;
    }

label_801344FC:
    ctx->pc = 0x801344FCu;
    ctx->downcount -= 4;
    // 801344FC: lis     r9, -32719
    ctx->gpr[9] = ((u32)(s32)(-32719) << 16);

label_80134500:
    ctx->pc = 0x80134500u;
    // 80134500: lwz     r0, 27848(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(27848);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80134504:
    ctx->pc = 0x80134504u;
    // 80134504: cmpwi   r0, 0
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

label_80134508:
    ctx->pc = 0x80134508u;
    // 80134508: bc    12, 2, 0x80134514
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134514;
        }
    }

label_8013450C:
    ctx->pc = 0x8013450Cu;
    ctx->downcount -= 2;
    // 8013450C: li      r0, 60
    ctx->gpr[0] = (u32)(s32)(60);

label_80134510:
    ctx->pc = 0x80134510u;
    // 80134510: stw     r0, -30092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30092);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80134514:
    ctx->pc = 0x80134514u;
    ctx->downcount -= 3;
    // 80134514: lwz     r9, -30092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30092);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80134518:
    ctx->pc = 0x80134518u;
    // 80134518: cmpwi   r9, 0
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

label_8013451C:
    ctx->pc = 0x8013451Cu;
    // 8013451C: bc    12, 2, 0x80134528
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134528;
        }
    }

label_80134520:
    ctx->pc = 0x80134520u;
    ctx->downcount -= 2;
    // 80134520: addi    r0, r9, -1
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-1);

label_80134524:
    ctx->pc = 0x80134524u;
    // 80134524: stw     r0, -30092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30092);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80134528:
    ctx->pc = 0x80134528u;
    ctx->downcount -= 1;
    // 80134528: bl      0x800B7A5C
    {
            ctx->lr = 0x8013452Cu;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_8013452C:
    ctx->pc = 0x8013452Cu;
    ctx->downcount -= 4;
    // 8013452C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80134530:
    ctx->pc = 0x80134530u;
    // 80134530: addi    r31, r9, -21636
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-21636);

label_80134534:
    ctx->pc = 0x80134534u;
    // 80134534: lha     r3, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80134538:
    ctx->pc = 0x80134538u;
    // 80134538: bl      0x80132E34
    {
            ctx->lr = 0x8013453Cu;
            ctx->pc = 0x80132E34u;
            return;
    }

label_8013453C:
    ctx->pc = 0x8013453Cu;
    ctx->downcount -= 2;
    // 8013453C: lis     r3, 16
    ctx->gpr[3] = ((u32)(s32)(16) << 16);

label_80134540:
    ctx->pc = 0x80134540u;
    // 80134540: bl      0x80132FD8
    {
            ctx->lr = 0x80134544u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80134544:
    ctx->pc = 0x80134544u;
    ctx->downcount -= 2;
    // 80134544: cmpwi   r3, 0
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

label_80134548:
    ctx->pc = 0x80134548u;
    // 80134548: bc    12, 2, 0x801345A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801345A0;
        }
    }

label_8013454C:
    ctx->pc = 0x8013454Cu;
    ctx->downcount -= 14;
    // 8013454C: lha     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80134550:
    ctx->pc = 0x80134550u;
    // 80134550: lis     r11, -32733
    ctx->gpr[11] = ((u32)(s32)(-32733) << 16);

label_80134554:
    ctx->pc = 0x80134554u;
    // 80134554: addi    r11, r11, 28640
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(28640);

label_80134558:
    ctx->pc = 0x80134558u;
    // 80134558: lwz     r10, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8013455C:
    ctx->pc = 0x8013455Cu;
    // 8013455C: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80134560:
    ctx->pc = 0x80134560u;
    // 80134560: addi    r9, r11, 4
    ctx->gpr[9] = ctx->gpr[11] + (u32)(s32)(4);

label_80134564:
    ctx->pc = 0x80134564u;
    // 80134564: lwzx    r8, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80134568:
    ctx->pc = 0x80134568u;
    // 80134568: addi    r10, r10, -1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(-1);

label_8013456C:
    ctx->pc = 0x8013456Cu;
    // 8013456C: lwzx    r9, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80134570:
    ctx->pc = 0x80134570u;
    // 80134570: cmpwi   r10, 0
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

label_80134574:
    ctx->pc = 0x80134574u;
    // 80134574: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80134578:
    ctx->pc = 0x80134578u;
    // 80134578: stw     r9, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8013457C:
    ctx->pc = 0x8013457Cu;
    // 8013457C: stw     r10, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80134580:
    ctx->pc = 0x80134580u;
    // 80134580: bc    4, 0, 0x80134590
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134590;
        }
    }

label_80134584:
    ctx->pc = 0x80134584u;
    ctx->downcount -= 3;
    // 80134584: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80134588:
    ctx->pc = 0x80134588u;
    // 80134588: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013458C:
    ctx->pc = 0x8013458Cu;
    // 8013458C: b       0x801345A0
    {
            goto label_801345A0;
    }

label_80134590:
    ctx->pc = 0x80134590u;
    ctx->downcount -= 4;
    // 80134590: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80134594:
    ctx->pc = 0x80134594u;
    // 80134594: lfs     f1, 5896(r28)
    if (!ppc_fp_available(ctx, 0x80134594u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134598:
    ctx->pc = 0x80134598u;
    // 80134598: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8013459C:
    ctx->pc = 0x8013459Cu;
    // 8013459C: bl      0x8004DC00
    {
            ctx->lr = 0x801345A0u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801345A0:
    ctx->pc = 0x801345A0u;
    ctx->downcount -= 2;
    // 801345A0: lis     r3, 32
    ctx->gpr[3] = ((u32)(s32)(32) << 16);

label_801345A4:
    ctx->pc = 0x801345A4u;
    // 801345A4: bl      0x80132FD8
    {
            ctx->lr = 0x801345A8u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_801345A8:
    ctx->pc = 0x801345A8u;
    ctx->downcount -= 2;
    // 801345A8: cmpwi   r3, 0
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

label_801345AC:
    ctx->pc = 0x801345ACu;
    // 801345AC: bc    12, 2, 0x8013460C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013460C;
        }
    }

label_801345B0:
    ctx->pc = 0x801345B0u;
    ctx->downcount -= 15;
    // 801345B0: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_801345B4:
    ctx->pc = 0x801345B4u;
    // 801345B4: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_801345B8:
    ctx->pc = 0x801345B8u;
    // 801345B8: lha     r0, -21584(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_801345BC:
    ctx->pc = 0x801345BCu;
    // 801345BC: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_801345C0:
    ctx->pc = 0x801345C0u;
    // 801345C0: addi    r10, r9, 4
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(4);

label_801345C4:
    ctx->pc = 0x801345C4u;
    // 801345C4: lwz     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801345C8:
    ctx->pc = 0x801345C8u;
    // 801345C8: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_801345CC:
    ctx->pc = 0x801345CCu;
    // 801345CC: lwzx    r8, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801345D0:
    ctx->pc = 0x801345D0u;
    // 801345D0: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_801345D4:
    ctx->pc = 0x801345D4u;
    // 801345D4: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801345D8:
    ctx->pc = 0x801345D8u;
    // 801345D8: cmpwi   r11, 3
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801345DC:
    ctx->pc = 0x801345DCu;
    // 801345DC: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801345E0:
    ctx->pc = 0x801345E0u;
    // 801345E0: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801345E4:
    ctx->pc = 0x801345E4u;
    // 801345E4: stw     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801345E8:
    ctx->pc = 0x801345E8u;
    // 801345E8: bc    4, 1, 0x801345F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801345F8;
        }
    }

label_801345EC:
    ctx->pc = 0x801345ECu;
    ctx->downcount -= 3;
    // 801345EC: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_801345F0:
    ctx->pc = 0x801345F0u;
    // 801345F0: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801345F4:
    ctx->pc = 0x801345F4u;
    // 801345F4: b       0x8013460C
    {
            goto label_8013460C;
    }

label_801345F8:
    ctx->pc = 0x801345F8u;
    ctx->downcount -= 5;
    // 801345F8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801345FC:
    ctx->pc = 0x801345FCu;
    // 801345FC: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80134600:
    ctx->pc = 0x80134600u;
    // 80134600: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80134600u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134604:
    ctx->pc = 0x80134604u;
    // 80134604: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80134608:
    ctx->pc = 0x80134608u;
    // 80134608: bl      0x8004DC00
    {
            ctx->lr = 0x8013460Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8013460C:
    ctx->pc = 0x8013460Cu;
    ctx->downcount -= 2;
    // 8013460C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80134610:
    ctx->pc = 0x80134610u;
    // 80134610: bl      0x80132FD8
    {
            ctx->lr = 0x80134614u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80134614:
    ctx->pc = 0x80134614u;
    ctx->downcount -= 2;
    // 80134614: cmpwi   r3, 0
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

label_80134618:
    ctx->pc = 0x80134618u;
    // 80134618: bc    12, 2, 0x80134678
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134678;
        }
    }

label_8013461C:
    ctx->pc = 0x8013461Cu;
    ctx->downcount -= 15;
    // 8013461C: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80134620:
    ctx->pc = 0x80134620u;
    // 80134620: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80134624:
    ctx->pc = 0x80134624u;
    // 80134624: lha     r0, -21584(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80134628:
    ctx->pc = 0x80134628u;
    // 80134628: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_8013462C:
    ctx->pc = 0x8013462Cu;
    // 8013462C: addi    r10, r9, 4
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(4);

label_80134630:
    ctx->pc = 0x80134630u;
    // 80134630: lwz     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80134634:
    ctx->pc = 0x80134634u;
    // 80134634: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80134638:
    ctx->pc = 0x80134638u;
    // 80134638: lwzx    r8, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8013463C:
    ctx->pc = 0x8013463Cu;
    // 8013463C: addi    r11, r11, -1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-1);

label_80134640:
    ctx->pc = 0x80134640u;
    // 80134640: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80134644:
    ctx->pc = 0x80134644u;
    // 80134644: cmpwi   r11, 0
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

label_80134648:
    ctx->pc = 0x80134648u;
    // 80134648: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8013464C:
    ctx->pc = 0x8013464Cu;
    // 8013464C: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80134650:
    ctx->pc = 0x80134650u;
    // 80134650: stw     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80134654:
    ctx->pc = 0x80134654u;
    // 80134654: bc    4, 0, 0x80134664
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134664;
        }
    }

label_80134658:
    ctx->pc = 0x80134658u;
    ctx->downcount -= 3;
    // 80134658: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8013465C:
    ctx->pc = 0x8013465Cu;
    // 8013465C: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80134660:
    ctx->pc = 0x80134660u;
    // 80134660: b       0x80134678
    {
            goto label_80134678;
    }

label_80134664:
    ctx->pc = 0x80134664u;
    ctx->downcount -= 5;
    // 80134664: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134668:
    ctx->pc = 0x80134668u;
    // 80134668: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8013466C:
    ctx->pc = 0x8013466Cu;
    // 8013466C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x8013466Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134670:
    ctx->pc = 0x80134670u;
    // 80134670: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80134674:
    ctx->pc = 0x80134674u;
    // 80134674: bl      0x8004DC00
    {
            ctx->lr = 0x80134678u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80134678:
    ctx->pc = 0x80134678u;
    ctx->downcount -= 2;
    // 80134678: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8013467C:
    ctx->pc = 0x8013467Cu;
    // 8013467C: bl      0x80132FD8
    {
            ctx->lr = 0x80134680u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80134680:
    ctx->pc = 0x80134680u;
    ctx->downcount -= 2;
    // 80134680: cmpwi   r3, 0
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

label_80134684:
    ctx->pc = 0x80134684u;
    // 80134684: bc    12, 2, 0x801346E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801346E4;
        }
    }

label_80134688:
    ctx->pc = 0x80134688u;
    ctx->downcount -= 15;
    // 80134688: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_8013468C:
    ctx->pc = 0x8013468Cu;
    // 8013468C: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80134690:
    ctx->pc = 0x80134690u;
    // 80134690: lha     r0, -21584(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80134694:
    ctx->pc = 0x80134694u;
    // 80134694: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80134698:
    ctx->pc = 0x80134698u;
    // 80134698: addi    r10, r9, 4
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(4);

label_8013469C:
    ctx->pc = 0x8013469Cu;
    // 8013469C: lwz     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801346A0:
    ctx->pc = 0x801346A0u;
    // 801346A0: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_801346A4:
    ctx->pc = 0x801346A4u;
    // 801346A4: lwzx    r8, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801346A8:
    ctx->pc = 0x801346A8u;
    // 801346A8: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_801346AC:
    ctx->pc = 0x801346ACu;
    // 801346AC: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801346B0:
    ctx->pc = 0x801346B0u;
    // 801346B0: cmpwi   r11, 3
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801346B4:
    ctx->pc = 0x801346B4u;
    // 801346B4: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_801346B8:
    ctx->pc = 0x801346B8u;
    // 801346B8: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801346BC:
    ctx->pc = 0x801346BCu;
    // 801346BC: stw     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801346C0:
    ctx->pc = 0x801346C0u;
    // 801346C0: bc    4, 1, 0x801346D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801346D0;
        }
    }

label_801346C4:
    ctx->pc = 0x801346C4u;
    ctx->downcount -= 3;
    // 801346C4: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_801346C8:
    ctx->pc = 0x801346C8u;
    // 801346C8: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801346CC:
    ctx->pc = 0x801346CCu;
    // 801346CC: b       0x801346E4
    {
            goto label_801346E4;
    }

label_801346D0:
    ctx->pc = 0x801346D0u;
    ctx->downcount -= 5;
    // 801346D0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801346D4:
    ctx->pc = 0x801346D4u;
    // 801346D4: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_801346D8:
    ctx->pc = 0x801346D8u;
    // 801346D8: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x801346D8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801346DC:
    ctx->pc = 0x801346DCu;
    // 801346DC: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_801346E0:
    ctx->pc = 0x801346E0u;
    // 801346E0: bl      0x8004DC00
    {
            ctx->lr = 0x801346E4u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801346E4:
    ctx->pc = 0x801346E4u;
    ctx->downcount -= 5;
    // 801346E4: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801346E8:
    ctx->pc = 0x801346E8u;
    // 801346E8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801346EC:
    ctx->pc = 0x801346ECu;
    // 801346EC: addi    r3, r3, 11668
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(11668);

label_801346F0:
    ctx->pc = 0x801346F0u;
    // 801346F0: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_801346F4:
    ctx->pc = 0x801346F4u;
    // 801346F4: bl      0x80035C40
    {
            ctx->lr = 0x801346F8u;
            ctx->pc = 0x80035C40u;
            return;
    }

label_801346F8:
    ctx->pc = 0x801346F8u;
    ctx->downcount -= 1;
    // 801346F8: lis     r31, -32698
    ctx->gpr[31] = ((u32)(s32)(-32698) << 16);

label_801346FC:
    ctx->pc = 0x801346FCu;
    ctx->downcount -= 3;
    // 801346FC: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80134700:
    // 80134700: cmpw    r0, r26
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

label_80134704:
    // 80134704: bc    4, 2, 0x80134718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134718;
        }
    }

label_80134708:
    ctx->downcount -= 3;
    // 80134708: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_8013470C:
    // 8013470C: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80134710:
    // 80134710: bl      0x80034BA8
    {
            ctx->lr = 0x80134714u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80134714:
    ctx->downcount -= 1;
    // 80134714: b       0x80134728
    {
            goto label_80134728;
    }

label_80134718:
    ctx->downcount -= 4;
    // 80134718: lis     r4, -17536
    ctx->gpr[4] = ((u32)(s32)(-17536) << 16);

label_8013471C:
    // 8013471C: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80134720:
    // 80134720: ori     r4, r4, 0x8080
    ctx->gpr[4] = ctx->gpr[4] | 0x8080u;

label_80134724:
    // 80134724: bl      0x80034BA8
    {
            ctx->lr = 0x80134728u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80134728:
    ctx->downcount -= 3;
    // 80134728: cmpwi   r26, 3
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8013472C:
    // 8013472C: mfcr    r30
    ctx->gpr[30] = ctx->cr;

label_80134730:
    // 80134730: bc    4, 2, 0x8013474C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013474C;
        }
    }

label_80134734:
    ctx->downcount -= 5;
    // 80134734: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134738:
    // 80134738: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_8013473C:
    ctx->pc = 0x8013473Cu;
    // 8013473C: lfs     f1, 5948(r9)
    if (!ppc_fp_available(ctx, 0x8013473Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5948);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134740:
    ctx->pc = 0x80134740u;
    // 80134740: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80134740u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80134744:
    // 80134744: bl      0x80034E6C
    {
            ctx->lr = 0x80134748u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80134748:
    ctx->downcount -= 1;
    // 80134748: b       0x8013475C
    {
            goto label_8013475C;
    }

label_8013474C:
    ctx->pc = 0x8013474Cu;
    ctx->downcount -= 4;
    // 8013474C: lfs     f1, 5896(r28)
    if (!ppc_fp_available(ctx, 0x8013474Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134750:
    // 80134750: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80134754:
    ctx->pc = 0x80134754u;
    // 80134754: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80134754u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80134758:
    // 80134758: bl      0x80034E6C
    {
            ctx->lr = 0x8013475Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013475C:
    ctx->downcount -= 2;
    // 8013475C: cmpwi   r26, 1
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80134760:
    // 80134760: bc    12, 2, 0x801347AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801347AC;
        }
    }

label_80134764:
    ctx->downcount -= 1;
    // 80134764: bc    12, 1, 0x80134774
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134774;
        }
    }

label_80134768:
    ctx->downcount -= 2;
    // 80134768: cmpwi   r26, 0
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

label_8013476C:
    // 8013476C: bc    12, 2, 0x80134788
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134788;
        }
    }

label_80134770:
    ctx->downcount -= 1;
    // 80134770: b       0x80134814
    {
            goto label_80134814;
    }

label_80134774:
    ctx->downcount -= 2;
    // 80134774: cmpwi   r26, 2
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80134778:
    // 80134778: bc    12, 2, 0x801347D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801347D0;
        }
    }

label_8013477C:
    ctx->downcount -= 2;
    // 8013477C: mtcrf   0x80, r30
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[30] & 0xF0000000u);

label_80134780:
    // 80134780: bc    12, 2, 0x801347F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801347F4;
        }
    }

label_80134784:
    ctx->downcount -= 1;
    // 80134784: b       0x80134814
    {
            goto label_80134814;
    }

label_80134788:
    ctx->downcount -= 3;
    // 80134788: li      r4, 3569
    ctx->gpr[4] = (u32)(s32)(3569);

label_8013478C:
    // 8013478C: addi    r3, r31, 9872
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(9872);

label_80134790:
    // 80134790: bl      0x80046B00
    {
            ctx->lr = 0x80134794u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134794:
    ctx->downcount -= 5;
    // 80134794: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134798:
    // 80134798: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_8013479C:
    // 8013479C: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_801347A0:
    // 801347A0: li      r5, 280
    ctx->gpr[5] = (u32)(s32)(280);

label_801347A4:
    // 801347A4: bl      0x80034F4C
    {
            ctx->lr = 0x801347A8u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_801347A8:
    ctx->downcount -= 1;
    // 801347A8: b       0x80134814
    {
            goto label_80134814;
    }

label_801347AC:
    ctx->downcount -= 3;
    // 801347AC: li      r4, 3570
    ctx->gpr[4] = (u32)(s32)(3570);

label_801347B0:
    // 801347B0: addi    r3, r31, 9872
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(9872);

label_801347B4:
    // 801347B4: bl      0x80046B00
    {
            ctx->lr = 0x801347B8u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801347B8:
    ctx->downcount -= 5;
    // 801347B8: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801347BC:
    // 801347BC: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_801347C0:
    // 801347C0: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_801347C4:
    // 801347C4: li      r5, 318
    ctx->gpr[5] = (u32)(s32)(318);

label_801347C8:
    // 801347C8: bl      0x80034F4C
    {
            ctx->lr = 0x801347CCu;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_801347CC:
    ctx->downcount -= 1;
    // 801347CC: b       0x80134814
    {
            goto label_80134814;
    }

label_801347D0:
    ctx->downcount -= 3;
    // 801347D0: li      r4, 3571
    ctx->gpr[4] = (u32)(s32)(3571);

label_801347D4:
    // 801347D4: addi    r3, r31, 9872
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(9872);

label_801347D8:
    // 801347D8: bl      0x80046B00
    {
            ctx->lr = 0x801347DCu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801347DC:
    ctx->downcount -= 5;
    // 801347DC: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801347E0:
    // 801347E0: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_801347E4:
    // 801347E4: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_801347E8:
    // 801347E8: li      r5, 356
    ctx->gpr[5] = (u32)(s32)(356);

label_801347EC:
    // 801347EC: bl      0x80034F4C
    {
            ctx->lr = 0x801347F0u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_801347F0:
    ctx->downcount -= 1;
    // 801347F0: b       0x80134814
    {
            goto label_80134814;
    }

label_801347F4:
    ctx->downcount -= 3;
    // 801347F4: li      r4, 3580
    ctx->gpr[4] = (u32)(s32)(3580);

label_801347F8:
    // 801347F8: addi    r3, r31, 9872
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(9872);

label_801347FC:
    // 801347FC: bl      0x80046B00
    {
            ctx->lr = 0x80134800u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134800:
    ctx->downcount -= 5;
    // 80134800: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134804:
    // 80134804: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_80134808:
    // 80134808: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_8013480C:
    // 8013480C: li      r5, 394
    ctx->gpr[5] = (u32)(s32)(394);

label_80134810:
    // 80134810: bl      0x80034F4C
    {
            ctx->lr = 0x80134814u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_80134814:
    ctx->downcount -= 3;
    // 80134814: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_80134818:
    // 80134818: cmpwi   r26, 3
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8013481C:
    // 8013481C: bc    4, 1, 0x801346FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801346FCu;
                return;
            }
            goto label_801346FC;
        }
    }

label_80134820:
    ctx->pc = 0x80134820u;
    ctx->downcount -= 1;
    // 80134820: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80134824:
    ctx->pc = 0x80134824u;
    ctx->downcount -= 5;
    // 80134824: lis     r30, -32697
    ctx->gpr[30] = ((u32)(s32)(-32697) << 16);

label_80134828:
    ctx->pc = 0x80134828u;
    // 80134828: li      r4, -171
    ctx->gpr[4] = (u32)(s32)(-171);

label_8013482C:
    ctx->pc = 0x8013482Cu;
    // 8013482C: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80134830:
    ctx->pc = 0x80134830u;
    // 80134830: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80134834:
    ctx->pc = 0x80134834u;
    // 80134834: bl      0x80034BA8
    {
            ctx->lr = 0x80134838u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80134838:
    ctx->pc = 0x80134838u;
    ctx->downcount -= 4;
    // 80134838: lis     r23, -32698
    ctx->gpr[23] = ((u32)(s32)(-32698) << 16);

label_8013483C:
    ctx->pc = 0x8013483Cu;
    // 8013483C: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80134840:
    ctx->pc = 0x80134840u;
    // 80134840: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80134844:
    ctx->pc = 0x80134844u;
    // 80134844: bl      0x80035C48
    {
            ctx->lr = 0x80134848u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80134848:
    ctx->pc = 0x80134848u;
    ctx->downcount -= 5;
    // 80134848: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013484C:
    ctx->pc = 0x8013484Cu;
    // 8013484C: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80134850:
    ctx->pc = 0x80134850u;
    // 80134850: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80134850u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134854:
    ctx->pc = 0x80134854u;
    // 80134854: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80134854u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80134858:
    ctx->pc = 0x80134858u;
    // 80134858: bl      0x80034E6C
    {
            ctx->lr = 0x8013485Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013485C:
    ctx->pc = 0x8013485Cu;
    ctx->downcount -= 4;
    // 8013485C: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80134860:
    ctx->pc = 0x80134860u;
    // 80134860: li      r4, 3571
    ctx->gpr[4] = (u32)(s32)(3571);

label_80134864:
    ctx->pc = 0x80134864u;
    // 80134864: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_80134868:
    ctx->pc = 0x80134868u;
    // 80134868: bl      0x80046B00
    {
            ctx->lr = 0x8013486Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8013486C:
    ctx->pc = 0x8013486Cu;
    ctx->downcount -= 5;
    // 8013486C: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134870:
    ctx->pc = 0x80134870u;
    // 80134870: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80134874:
    ctx->pc = 0x80134874u;
    // 80134874: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80134878:
    ctx->pc = 0x80134878u;
    // 80134878: li      r5, 70
    ctx->gpr[5] = (u32)(s32)(70);

label_8013487C:
    ctx->pc = 0x8013487Cu;
    // 8013487C: bl      0x80034E9C
    {
            ctx->lr = 0x80134880u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80134880:
    ctx->pc = 0x80134880u;
    ctx->downcount -= 2;
    // 80134880: lis     r3, 16
    ctx->gpr[3] = ((u32)(s32)(16) << 16);

label_80134884:
    ctx->pc = 0x80134884u;
    // 80134884: bl      0x80132FD8
    {
            ctx->lr = 0x80134888u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80134888:
    ctx->pc = 0x80134888u;
    ctx->downcount -= 2;
    // 80134888: cmpwi   r3, 0
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

label_8013488C:
    ctx->pc = 0x8013488Cu;
    // 8013488C: bc    4, 2, 0x801348A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801348A0;
        }
    }

label_80134890:
    ctx->pc = 0x80134890u;
    ctx->downcount -= 2;
    // 80134890: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80134894:
    ctx->pc = 0x80134894u;
    // 80134894: bl      0x80132FD8
    {
            ctx->lr = 0x80134898u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80134898:
    ctx->pc = 0x80134898u;
    ctx->downcount -= 2;
    // 80134898: cmpwi   r3, 0
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

label_8013489C:
    ctx->pc = 0x8013489Cu;
    // 8013489C: bc    12, 2, 0x801348CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801348CC;
        }
    }

label_801348A0:
    ctx->pc = 0x801348A0u;
    ctx->downcount -= 5;
    // 801348A0: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801348A4:
    ctx->pc = 0x801348A4u;
    // 801348A4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801348A8:
    ctx->pc = 0x801348A8u;
    // 801348A8: cmpwi   r9, 0
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

label_801348AC:
    ctx->pc = 0x801348ACu;
    // 801348AC: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801348B0:
    ctx->pc = 0x801348B0u;
    // 801348B0: bc    4, 0, 0x801348BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801348BC;
        }
    }

label_801348B4:
    ctx->pc = 0x801348B4u;
    ctx->downcount -= 2;
    // 801348B4: stw     r20, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[20]);
    }

label_801348B8:
    ctx->pc = 0x801348B8u;
    // 801348B8: b       0x801348CC
    {
            goto label_801348CC;
    }

label_801348BC:
    ctx->pc = 0x801348BCu;
    ctx->downcount -= 4;
    // 801348BC: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_801348C0:
    ctx->pc = 0x801348C0u;
    // 801348C0: lfs     f1, 5896(r28)
    if (!ppc_fp_available(ctx, 0x801348C0u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801348C4:
    ctx->pc = 0x801348C4u;
    // 801348C4: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_801348C8:
    ctx->pc = 0x801348C8u;
    // 801348C8: bl      0x8004DC00
    {
            ctx->lr = 0x801348CCu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801348CC:
    ctx->pc = 0x801348CCu;
    ctx->downcount -= 2;
    // 801348CC: lis     r3, 32
    ctx->gpr[3] = ((u32)(s32)(32) << 16);

label_801348D0:
    ctx->pc = 0x801348D0u;
    // 801348D0: bl      0x80132FD8
    {
            ctx->lr = 0x801348D4u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_801348D4:
    ctx->pc = 0x801348D4u;
    ctx->downcount -= 2;
    // 801348D4: cmpwi   r3, 0
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

label_801348D8:
    ctx->pc = 0x801348D8u;
    // 801348D8: bc    4, 2, 0x801348EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801348EC;
        }
    }

label_801348DC:
    ctx->pc = 0x801348DCu;
    ctx->downcount -= 2;
    // 801348DC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_801348E0:
    ctx->pc = 0x801348E0u;
    // 801348E0: bl      0x80132FD8
    {
            ctx->lr = 0x801348E4u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_801348E4:
    ctx->pc = 0x801348E4u;
    ctx->downcount -= 2;
    // 801348E4: cmpwi   r3, 0
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

label_801348E8:
    ctx->pc = 0x801348E8u;
    // 801348E8: bc    12, 2, 0x80134920
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134920;
        }
    }

label_801348EC:
    ctx->pc = 0x801348ECu;
    ctx->downcount -= 5;
    // 801348EC: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801348F0:
    ctx->pc = 0x801348F0u;
    // 801348F0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801348F4:
    ctx->pc = 0x801348F4u;
    // 801348F4: cmpwi   r9, 5
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801348F8:
    ctx->pc = 0x801348F8u;
    // 801348F8: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801348FC:
    ctx->pc = 0x801348FCu;
    // 801348FC: bc    4, 1, 0x8013490C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013490C;
        }
    }

label_80134900:
    ctx->pc = 0x80134900u;
    ctx->downcount -= 3;
    // 80134900: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_80134904:
    ctx->pc = 0x80134904u;
    // 80134904: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80134908:
    ctx->pc = 0x80134908u;
    // 80134908: b       0x80134920
    {
            goto label_80134920;
    }

label_8013490C:
    ctx->pc = 0x8013490Cu;
    ctx->downcount -= 5;
    // 8013490C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134910:
    ctx->pc = 0x80134910u;
    // 80134910: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80134914:
    ctx->pc = 0x80134914u;
    // 80134914: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80134914u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134918:
    ctx->pc = 0x80134918u;
    // 80134918: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8013491C:
    ctx->pc = 0x8013491Cu;
    // 8013491C: bl      0x8004DC00
    {
            ctx->lr = 0x80134920u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80134920:
    ctx->pc = 0x80134920u;
    ctx->downcount -= 5;
    // 80134920: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_80134924:
    ctx->pc = 0x80134924u;
    // 80134924: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_80134928:
    ctx->pc = 0x80134928u;
    // 80134928: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013492C:
    ctx->pc = 0x8013492Cu;
    // 8013492C: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_80134930:
    ctx->pc = 0x80134930u;
    // 80134930: bl      0x80034BA8
    {
            ctx->lr = 0x80134934u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80134934:
    ctx->pc = 0x80134934u;
    ctx->downcount -= 4;
    // 80134934: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80134938:
    ctx->pc = 0x80134938u;
    // 80134938: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013493C:
    ctx->pc = 0x8013493Cu;
    // 8013493C: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80134940:
    ctx->pc = 0x80134940u;
    // 80134940: bl      0x800353D4
    {
            ctx->lr = 0x80134944u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_80134944:
    ctx->pc = 0x80134944u;
    ctx->downcount -= 4;
    // 80134944: lis     r24, -32698
    ctx->gpr[24] = ((u32)(s32)(-32698) << 16);

label_80134948:
    ctx->pc = 0x80134948u;
    // 80134948: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013494C:
    ctx->pc = 0x8013494Cu;
    // 8013494C: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80134950:
    ctx->pc = 0x80134950u;
    // 80134950: bl      0x80035C48
    {
            ctx->lr = 0x80134954u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80134954:
    ctx->pc = 0x80134954u;
    ctx->downcount -= 6;
    // 80134954: lis     r22, -32737
    ctx->gpr[22] = ((u32)(s32)(-32737) << 16);

label_80134958:
    ctx->pc = 0x80134958u;
    // 80134958: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8013495C:
    ctx->pc = 0x8013495Cu;
    // 8013495C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134960:
    ctx->pc = 0x80134960u;
    // 80134960: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80134964:
    ctx->pc = 0x80134964u;
    // 80134964: lis     r29, -32737
    ctx->gpr[29] = ((u32)(s32)(-32737) << 16);

label_80134968:
    ctx->pc = 0x80134968u;
    // 80134968: bl      0x80035C50
    {
            ctx->lr = 0x8013496Cu;
            ctx->pc = 0x80035C50u;
            return;
    }

label_8013496C:
    ctx->pc = 0x8013496Cu;
    ctx->downcount -= 3;
    // 8013496C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134970:
    ctx->pc = 0x80134970u;
    // 80134970: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80134974:
    ctx->pc = 0x80134974u;
    // 80134974: bl      0x80035C40
    {
            ctx->lr = 0x80134978u;
            ctx->pc = 0x80035C40u;
            return;
    }

label_80134978:
    ctx->pc = 0x80134978u;
    ctx->downcount -= 5;
    // 80134978: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013497C:
    ctx->pc = 0x8013497Cu;
    // 8013497C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80134980:
    ctx->pc = 0x80134980u;
    // 80134980: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80134980u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80134984:
    ctx->pc = 0x80134984u;
    // 80134984: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80134984u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80134988:
    ctx->pc = 0x80134988u;
    // 80134988: bl      0x80034E6C
    {
            ctx->lr = 0x8013498Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013498C:
    ctx->pc = 0x8013498Cu;
    ctx->downcount -= 4;
    // 8013498C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80134990:
    ctx->pc = 0x80134990u;
    // 80134990: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80134994:
    ctx->pc = 0x80134994u;
    // 80134994: lfs     f30, 5972(r9)
    if (!ppc_fp_available(ctx, 0x80134994u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5972);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_80134998:
    ctx->pc = 0x80134998u;
    // 80134998: addi    r31, r11, -21636
    ctx->gpr[31] = ctx->gpr[11] + (u32)(s32)(-21636);

label_8013499C:
    ctx->pc = 0x8013499Cu;
    ctx->downcount -= 3;
    // 8013499C: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801349A0:
    // 801349A0: cmpw    r0, r26
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

label_801349A4:
    // 801349A4: bc    4, 2, 0x801349D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801349D4;
        }
    }

label_801349A8:
    ctx->pc = 0x801349A8u;
    ctx->downcount -= 3;
    // 801349A8: lwz     r0, -32364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32364);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801349AC:
    // 801349AC: andi.   r6, r0, 0x0010
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801349B0:
    // 801349B0: bc    12, 2, 0x801349C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801349C4;
        }
    }

label_801349B4:
    ctx->downcount -= 3;
    // 801349B4: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801349B8:
    // 801349B8: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801349BC:
    // 801349BC: bl      0x80034BA8
    {
            ctx->lr = 0x801349C0u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801349C0:
    ctx->downcount -= 1;
    // 801349C0: b       0x801349E4
    {
            goto label_801349E4;
    }

label_801349C4:
    ctx->downcount -= 3;
    // 801349C4: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801349C8:
    // 801349C8: lis     r4, -256
    ctx->gpr[4] = ((u32)(s32)(-256) << 16);

label_801349CC:
    // 801349CC: bl      0x80034BA8
    {
            ctx->lr = 0x801349D0u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801349D0:
    ctx->downcount -= 1;
    // 801349D0: b       0x801349E4
    {
            goto label_801349E4;
    }

label_801349D4:
    ctx->downcount -= 4;
    // 801349D4: lis     r4, -36
    ctx->gpr[4] = ((u32)(s32)(-36) << 16);

label_801349D8:
    // 801349D8: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801349DC:
    // 801349DC: ori     r4, r4, 0xC828
    ctx->gpr[4] = ctx->gpr[4] | 0xC828u;

label_801349E0:
    // 801349E0: bl      0x80034BA8
    {
            ctx->lr = 0x801349E4u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801349E4:
    ctx->downcount -= 2;
    // 801349E4: cmpwi   r26, 2
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801349E8:
    // 801349E8: bc    12, 2, 0x80134BE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134BE4;
        }
    }

label_801349EC:
    ctx->downcount -= 1;
    // 801349EC: bc    12, 1, 0x80134A04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134A04;
        }
    }

label_801349F0:
    ctx->downcount -= 2;
    // 801349F0: cmpwi   r26, 0
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

label_801349F4:
    // 801349F4: bc    12, 2, 0x80134A1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134A1C;
        }
    }

label_801349F8:
    ctx->downcount -= 2;
    // 801349F8: cmpwi   r26, 1
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801349FC:
    // 801349FC: bc    12, 2, 0x80134B00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134B00;
        }
    }

label_80134A00:
    ctx->downcount -= 1;
    // 80134A00: b       0x80134FDC
    {
            goto label_80134FDC;
    }

label_80134A04:
    ctx->downcount -= 2;
    // 80134A04: cmpwi   r26, 4
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80134A08:
    // 80134A08: bc    12, 2, 0x80134DA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134DA0;
        }
    }

label_80134A0C:
    ctx->downcount -= 1;
    // 80134A0C: bc    12, 0, 0x80134CA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134CA0;
        }
    }

label_80134A10:
    ctx->downcount -= 2;
    // 80134A10: cmpwi   r26, 5
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80134A14:
    // 80134A14: bc    12, 2, 0x80134EC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134EC0;
        }
    }

label_80134A18:
    ctx->downcount -= 1;
    // 80134A18: b       0x80134FDC
    {
            goto label_80134FDC;
    }

label_80134A1C:
    ctx->pc = 0x80134A1Cu;
    ctx->downcount -= 7;
    // 80134A1C: lfd     f13, 5976(r29)
    if (!ppc_fp_available(ctx, 0x80134A1Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5976);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134A20:
    ctx->pc = 0x80134A20u;
    // 80134A20: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80134A20u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_80134A24:
    ctx->pc = 0x80134A24u;
    // 80134A24: fmr    f31, f0
    if (!ppc_fp_available(ctx, 0x80134A24u)) return;
    ctx->fpr[31] = ctx->fpr[0];

label_80134A28:
    // 80134A28: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80134A2C:
    ctx->pc = 0x80134A2Cu;
    // 80134A2C: fcmpu   cr0, f0, f13
    if (!ppc_fp_available(ctx, 0x80134A2Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_80134A30:
    // 80134A30: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134A34:
    // 80134A34: bc    12, 3, 0x80134A48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134A48;
        }
    }

label_80134A38:
    ctx->pc = 0x80134A38u;
    ctx->downcount -= 4;
    // 80134A38: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134A38u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134A3C:
    ctx->pc = 0x80134A3Cu;
    // 80134A3C: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134A3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134A40:
    ctx->pc = 0x80134A40u;
    // 80134A40: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134A44:
    // 80134A44: b       0x80134A5C
    {
            goto label_80134A5C;
    }

label_80134A48:
    ctx->pc = 0x80134A48u;
    ctx->downcount -= 5;
    // 80134A48: fsub   f0, f31, f13
    if (!ppc_fp_available(ctx, 0x80134A48u)) return;
    ppc_fsub(ctx, 0, 31, 13);

label_80134A4C:
    ctx->pc = 0x80134A4Cu;
    // 80134A4C: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134A4Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134A50:
    ctx->pc = 0x80134A50u;
    // 80134A50: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134A50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134A54:
    ctx->pc = 0x80134A54u;
    // 80134A54: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134A58:
    // 80134A58: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134A5C:
    ctx->downcount -= 3;
    // 80134A5C: li      r4, 3574
    ctx->gpr[4] = (u32)(s32)(3574);

label_80134A60:
    // 80134A60: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80134A64:
    // 80134A64: bl      0x80046B00
    {
            ctx->lr = 0x80134A68u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134A68:
    ctx->downcount -= 5;
    // 80134A68: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134A6C:
    // 80134A6C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80134A70:
    // 80134A70: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134A74:
    // 80134A74: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80134A78:
    // 80134A78: bl      0x80034E9C
    {
            ctx->lr = 0x80134A7Cu;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80134A7C:
    ctx->pc = 0x80134A7Cu;
    ctx->downcount -= 3;
    // 80134A7C: lhz     r0, 22(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(22);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80134A80:
    // 80134A80: cmpwi   r0, 0
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

label_80134A84:
    // 80134A84: bc    12, 2, 0x80134AC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134AC4;
        }
    }

label_80134A88:
    ctx->pc = 0x80134A88u;
    ctx->downcount -= 4;
    // 80134A88: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134A88u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134A8C:
    ctx->pc = 0x80134A8Cu;
    // 80134A8C: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134A8Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134A90:
    // 80134A90: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134A94:
    // 80134A94: bc    12, 3, 0x80134AA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134AA8;
        }
    }

label_80134A98:
    ctx->pc = 0x80134A98u;
    ctx->downcount -= 4;
    // 80134A98: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134A98u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134A9C:
    ctx->pc = 0x80134A9Cu;
    // 80134A9C: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134A9Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134AA0:
    ctx->pc = 0x80134AA0u;
    // 80134AA0: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134AA4:
    // 80134AA4: b       0x80134ABC
    {
            goto label_80134ABC;
    }

label_80134AA8:
    ctx->pc = 0x80134AA8u;
    ctx->downcount -= 5;
    // 80134AA8: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134AA8u)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134AAC:
    ctx->pc = 0x80134AACu;
    // 80134AAC: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134AACu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134AB0:
    ctx->pc = 0x80134AB0u;
    // 80134AB0: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134AB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134AB4:
    ctx->pc = 0x80134AB4u;
    // 80134AB4: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134AB8:
    // 80134AB8: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134ABC:
    ctx->downcount -= 2;
    // 80134ABC: li      r4, 3576
    ctx->gpr[4] = (u32)(s32)(3576);

label_80134AC0:
    // 80134AC0: b       0x80134D80
    {
            goto label_80134D80;
    }

label_80134AC4:
    ctx->pc = 0x80134AC4u;
    ctx->downcount -= 4;
    // 80134AC4: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134AC4u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134AC8:
    ctx->pc = 0x80134AC8u;
    // 80134AC8: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134AC8u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134ACC:
    // 80134ACC: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134AD0:
    // 80134AD0: bc    12, 3, 0x80134AE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134AE4;
        }
    }

label_80134AD4:
    ctx->pc = 0x80134AD4u;
    ctx->downcount -= 4;
    // 80134AD4: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134AD4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134AD8:
    ctx->pc = 0x80134AD8u;
    // 80134AD8: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134AD8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134ADC:
    ctx->pc = 0x80134ADCu;
    // 80134ADC: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134AE0:
    // 80134AE0: b       0x80134AF8
    {
            goto label_80134AF8;
    }

label_80134AE4:
    ctx->pc = 0x80134AE4u;
    ctx->downcount -= 5;
    // 80134AE4: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134AE4u)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134AE8:
    ctx->pc = 0x80134AE8u;
    // 80134AE8: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134AE8u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134AEC:
    ctx->pc = 0x80134AECu;
    // 80134AEC: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134AECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134AF0:
    ctx->pc = 0x80134AF0u;
    // 80134AF0: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134AF4:
    // 80134AF4: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134AF8:
    ctx->downcount -= 2;
    // 80134AF8: li      r4, 3577
    ctx->gpr[4] = (u32)(s32)(3577);

label_80134AFC:
    // 80134AFC: b       0x80134D80
    {
            goto label_80134D80;
    }

label_80134B00:
    ctx->pc = 0x80134B00u;
    ctx->downcount -= 7;
    // 80134B00: lfd     f13, 5976(r29)
    if (!ppc_fp_available(ctx, 0x80134B00u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5976);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134B04:
    ctx->pc = 0x80134B04u;
    // 80134B04: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80134B04u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_80134B08:
    ctx->pc = 0x80134B08u;
    // 80134B08: fmr    f31, f0
    if (!ppc_fp_available(ctx, 0x80134B08u)) return;
    ctx->fpr[31] = ctx->fpr[0];

label_80134B0C:
    // 80134B0C: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80134B10:
    ctx->pc = 0x80134B10u;
    // 80134B10: fcmpu   cr0, f0, f13
    if (!ppc_fp_available(ctx, 0x80134B10u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_80134B14:
    // 80134B14: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134B18:
    // 80134B18: bc    12, 3, 0x80134B2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134B2C;
        }
    }

label_80134B1C:
    ctx->pc = 0x80134B1Cu;
    ctx->downcount -= 4;
    // 80134B1C: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134B1Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134B20:
    ctx->pc = 0x80134B20u;
    // 80134B20: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134B20u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134B24:
    ctx->pc = 0x80134B24u;
    // 80134B24: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134B28:
    // 80134B28: b       0x80134B40
    {
            goto label_80134B40;
    }

label_80134B2C:
    ctx->pc = 0x80134B2Cu;
    ctx->downcount -= 5;
    // 80134B2C: fsub   f0, f31, f13
    if (!ppc_fp_available(ctx, 0x80134B2Cu)) return;
    ppc_fsub(ctx, 0, 31, 13);

label_80134B30:
    ctx->pc = 0x80134B30u;
    // 80134B30: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134B30u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134B34:
    ctx->pc = 0x80134B34u;
    // 80134B34: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134B34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134B38:
    ctx->pc = 0x80134B38u;
    // 80134B38: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134B3C:
    // 80134B3C: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134B40:
    ctx->downcount -= 3;
    // 80134B40: li      r4, 3581
    ctx->gpr[4] = (u32)(s32)(3581);

label_80134B44:
    // 80134B44: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80134B48:
    // 80134B48: bl      0x80046B00
    {
            ctx->lr = 0x80134B4Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134B4C:
    ctx->downcount -= 5;
    // 80134B4C: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134B50:
    // 80134B50: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80134B54:
    // 80134B54: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134B58:
    // 80134B58: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80134B5C:
    // 80134B5C: bl      0x80034E9C
    {
            ctx->lr = 0x80134B60u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80134B60:
    ctx->pc = 0x80134B60u;
    ctx->downcount -= 3;
    // 80134B60: lhz     r0, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80134B64:
    // 80134B64: cmpwi   r0, 0
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

label_80134B68:
    // 80134B68: bc    12, 2, 0x80134BA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134BA8;
        }
    }

label_80134B6C:
    ctx->pc = 0x80134B6Cu;
    ctx->downcount -= 4;
    // 80134B6C: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134B6Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134B70:
    ctx->pc = 0x80134B70u;
    // 80134B70: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134B70u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134B74:
    // 80134B74: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134B78:
    // 80134B78: bc    12, 3, 0x80134B8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134B8C;
        }
    }

label_80134B7C:
    ctx->pc = 0x80134B7Cu;
    ctx->downcount -= 4;
    // 80134B7C: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134B7Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134B80:
    ctx->pc = 0x80134B80u;
    // 80134B80: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134B80u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134B84:
    ctx->pc = 0x80134B84u;
    // 80134B84: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134B88:
    // 80134B88: b       0x80134BA0
    {
            goto label_80134BA0;
    }

label_80134B8C:
    ctx->pc = 0x80134B8Cu;
    ctx->downcount -= 5;
    // 80134B8C: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134B8Cu)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134B90:
    ctx->pc = 0x80134B90u;
    // 80134B90: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134B90u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134B94:
    ctx->pc = 0x80134B94u;
    // 80134B94: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134B94u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134B98:
    ctx->pc = 0x80134B98u;
    // 80134B98: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134B9C:
    // 80134B9C: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134BA0:
    ctx->downcount -= 2;
    // 80134BA0: li      r4, 3577
    ctx->gpr[4] = (u32)(s32)(3577);

label_80134BA4:
    // 80134BA4: b       0x80134D80
    {
            goto label_80134D80;
    }

label_80134BA8:
    ctx->pc = 0x80134BA8u;
    ctx->downcount -= 4;
    // 80134BA8: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134BA8u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134BAC:
    ctx->pc = 0x80134BACu;
    // 80134BAC: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134BACu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134BB0:
    // 80134BB0: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134BB4:
    // 80134BB4: bc    12, 3, 0x80134BC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134BC8;
        }
    }

label_80134BB8:
    ctx->pc = 0x80134BB8u;
    ctx->downcount -= 4;
    // 80134BB8: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134BB8u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134BBC:
    ctx->pc = 0x80134BBCu;
    // 80134BBC: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134BBCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134BC0:
    ctx->pc = 0x80134BC0u;
    // 80134BC0: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134BC4:
    // 80134BC4: b       0x80134BDC
    {
            goto label_80134BDC;
    }

label_80134BC8:
    ctx->pc = 0x80134BC8u;
    ctx->downcount -= 5;
    // 80134BC8: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134BC8u)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134BCC:
    ctx->pc = 0x80134BCCu;
    // 80134BCC: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134BCCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134BD0:
    ctx->pc = 0x80134BD0u;
    // 80134BD0: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134BD0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134BD4:
    ctx->pc = 0x80134BD4u;
    // 80134BD4: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134BD8:
    // 80134BD8: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134BDC:
    ctx->downcount -= 2;
    // 80134BDC: li      r4, 3576
    ctx->gpr[4] = (u32)(s32)(3576);

label_80134BE0:
    // 80134BE0: b       0x80134D80
    {
            goto label_80134D80;
    }

label_80134BE4:
    ctx->pc = 0x80134BE4u;
    ctx->downcount -= 7;
    // 80134BE4: lfd     f13, 5976(r29)
    if (!ppc_fp_available(ctx, 0x80134BE4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5976);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134BE8:
    ctx->pc = 0x80134BE8u;
    // 80134BE8: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80134BE8u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_80134BEC:
    ctx->pc = 0x80134BECu;
    // 80134BEC: fmr    f31, f0
    if (!ppc_fp_available(ctx, 0x80134BECu)) return;
    ctx->fpr[31] = ctx->fpr[0];

label_80134BF0:
    // 80134BF0: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80134BF4:
    ctx->pc = 0x80134BF4u;
    // 80134BF4: fcmpu   cr0, f0, f13
    if (!ppc_fp_available(ctx, 0x80134BF4u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_80134BF8:
    // 80134BF8: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134BFC:
    // 80134BFC: bc    12, 3, 0x80134C10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134C10;
        }
    }

label_80134C00:
    ctx->pc = 0x80134C00u;
    ctx->downcount -= 4;
    // 80134C00: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134C00u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134C04:
    ctx->pc = 0x80134C04u;
    // 80134C04: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134C04u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134C08:
    ctx->pc = 0x80134C08u;
    // 80134C08: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134C0C:
    // 80134C0C: b       0x80134C24
    {
            goto label_80134C24;
    }

label_80134C10:
    ctx->pc = 0x80134C10u;
    ctx->downcount -= 5;
    // 80134C10: fsub   f0, f31, f13
    if (!ppc_fp_available(ctx, 0x80134C10u)) return;
    ppc_fsub(ctx, 0, 31, 13);

label_80134C14:
    ctx->pc = 0x80134C14u;
    // 80134C14: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134C14u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134C18:
    ctx->pc = 0x80134C18u;
    // 80134C18: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134C18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134C1C:
    ctx->pc = 0x80134C1Cu;
    // 80134C1C: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134C20:
    // 80134C20: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134C24:
    ctx->downcount -= 3;
    // 80134C24: li      r4, 3575
    ctx->gpr[4] = (u32)(s32)(3575);

label_80134C28:
    // 80134C28: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80134C2C:
    // 80134C2C: bl      0x80046B00
    {
            ctx->lr = 0x80134C30u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134C30:
    ctx->downcount -= 5;
    // 80134C30: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134C34:
    // 80134C34: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80134C38:
    // 80134C38: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134C3C:
    // 80134C3C: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80134C40:
    // 80134C40: bl      0x80034E9C
    {
            ctx->lr = 0x80134C44u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80134C44:
    ctx->pc = 0x80134C44u;
    ctx->downcount -= 3;
    // 80134C44: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80134C48:
    // 80134C48: cmpwi   r0, 0
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

label_80134C4C:
    // 80134C4C: bc    12, 2, 0x80134C8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134C8C;
        }
    }

label_80134C50:
    ctx->pc = 0x80134C50u;
    ctx->downcount -= 4;
    // 80134C50: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134C50u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134C54:
    ctx->pc = 0x80134C54u;
    // 80134C54: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134C54u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134C58:
    // 80134C58: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134C5C:
    // 80134C5C: bc    12, 3, 0x80134C70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134C70;
        }
    }

label_80134C60:
    ctx->pc = 0x80134C60u;
    ctx->downcount -= 4;
    // 80134C60: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134C60u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134C64:
    ctx->pc = 0x80134C64u;
    // 80134C64: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134C64u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134C68:
    ctx->pc = 0x80134C68u;
    // 80134C68: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134C6C:
    // 80134C6C: b       0x80134C84
    {
            goto label_80134C84;
    }

label_80134C70:
    ctx->pc = 0x80134C70u;
    ctx->downcount -= 5;
    // 80134C70: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134C70u)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134C74:
    ctx->pc = 0x80134C74u;
    // 80134C74: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134C74u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134C78:
    ctx->pc = 0x80134C78u;
    // 80134C78: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134C78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134C7C:
    ctx->pc = 0x80134C7Cu;
    // 80134C7C: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134C80:
    // 80134C80: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134C84:
    ctx->downcount -= 2;
    // 80134C84: li      r4, 3588
    ctx->gpr[4] = (u32)(s32)(3588);

label_80134C88:
    // 80134C88: b       0x80134D80
    {
            goto label_80134D80;
    }

label_80134C8C:
    ctx->pc = 0x80134C8Cu;
    ctx->downcount -= 4;
    // 80134C8C: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134C8Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134C90:
    ctx->pc = 0x80134C90u;
    // 80134C90: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134C90u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134C94:
    // 80134C94: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134C98:
    // 80134C98: bc    4, 3, 0x80134D58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134D58;
        }
    }

label_80134C9C:
    ctx->downcount -= 1;
    // 80134C9C: b       0x80134D68
    {
            goto label_80134D68;
    }

label_80134CA0:
    ctx->pc = 0x80134CA0u;
    ctx->downcount -= 7;
    // 80134CA0: lfd     f13, 5976(r29)
    if (!ppc_fp_available(ctx, 0x80134CA0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5976);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134CA4:
    ctx->pc = 0x80134CA4u;
    // 80134CA4: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80134CA4u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_80134CA8:
    ctx->pc = 0x80134CA8u;
    // 80134CA8: fmr    f31, f0
    if (!ppc_fp_available(ctx, 0x80134CA8u)) return;
    ctx->fpr[31] = ctx->fpr[0];

label_80134CAC:
    // 80134CAC: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80134CB0:
    ctx->pc = 0x80134CB0u;
    // 80134CB0: fcmpu   cr0, f0, f13
    if (!ppc_fp_available(ctx, 0x80134CB0u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_80134CB4:
    // 80134CB4: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134CB8:
    // 80134CB8: bc    12, 3, 0x80134CCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134CCC;
        }
    }

label_80134CBC:
    ctx->pc = 0x80134CBCu;
    ctx->downcount -= 4;
    // 80134CBC: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134CBCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134CC0:
    ctx->pc = 0x80134CC0u;
    // 80134CC0: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134CC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134CC4:
    ctx->pc = 0x80134CC4u;
    // 80134CC4: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134CC8:
    // 80134CC8: b       0x80134CE0
    {
            goto label_80134CE0;
    }

label_80134CCC:
    ctx->pc = 0x80134CCCu;
    ctx->downcount -= 5;
    // 80134CCC: fsub   f0, f31, f13
    if (!ppc_fp_available(ctx, 0x80134CCCu)) return;
    ppc_fsub(ctx, 0, 31, 13);

label_80134CD0:
    ctx->pc = 0x80134CD0u;
    // 80134CD0: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134CD0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134CD4:
    ctx->pc = 0x80134CD4u;
    // 80134CD4: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134CD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134CD8:
    ctx->pc = 0x80134CD8u;
    // 80134CD8: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134CDC:
    // 80134CDC: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134CE0:
    ctx->downcount -= 3;
    // 80134CE0: li      r4, 3572
    ctx->gpr[4] = (u32)(s32)(3572);

label_80134CE4:
    // 80134CE4: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80134CE8:
    // 80134CE8: bl      0x80046B00
    {
            ctx->lr = 0x80134CECu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134CEC:
    ctx->downcount -= 5;
    // 80134CEC: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134CF0:
    // 80134CF0: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80134CF4:
    // 80134CF4: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134CF8:
    // 80134CF8: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80134CFC:
    // 80134CFC: bl      0x80034E9C
    {
            ctx->lr = 0x80134D00u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80134D00:
    ctx->pc = 0x80134D00u;
    ctx->downcount -= 3;
    // 80134D00: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80134D04:
    // 80134D04: cmpwi   r0, 0
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

label_80134D08:
    // 80134D08: bc    12, 2, 0x80134D48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134D48;
        }
    }

label_80134D0C:
    ctx->pc = 0x80134D0Cu;
    ctx->downcount -= 4;
    // 80134D0C: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134D0Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134D10:
    ctx->pc = 0x80134D10u;
    // 80134D10: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134D10u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134D14:
    // 80134D14: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134D18:
    // 80134D18: bc    12, 3, 0x80134D2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134D2C;
        }
    }

label_80134D1C:
    ctx->pc = 0x80134D1Cu;
    ctx->downcount -= 4;
    // 80134D1C: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134D1Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134D20:
    ctx->pc = 0x80134D20u;
    // 80134D20: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134D20u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134D24:
    ctx->pc = 0x80134D24u;
    // 80134D24: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134D28:
    // 80134D28: b       0x80134D40
    {
            goto label_80134D40;
    }

label_80134D2C:
    ctx->pc = 0x80134D2Cu;
    ctx->downcount -= 5;
    // 80134D2C: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134D2Cu)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134D30:
    ctx->pc = 0x80134D30u;
    // 80134D30: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134D30u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134D34:
    ctx->pc = 0x80134D34u;
    // 80134D34: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134D34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134D38:
    ctx->pc = 0x80134D38u;
    // 80134D38: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134D3C:
    // 80134D3C: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134D40:
    ctx->downcount -= 2;
    // 80134D40: li      r4, 3588
    ctx->gpr[4] = (u32)(s32)(3588);

label_80134D44:
    // 80134D44: b       0x80134D80
    {
            goto label_80134D80;
    }

label_80134D48:
    ctx->pc = 0x80134D48u;
    ctx->downcount -= 4;
    // 80134D48: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134D48u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134D4C:
    ctx->pc = 0x80134D4Cu;
    // 80134D4C: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134D4Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134D50:
    // 80134D50: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134D54:
    // 80134D54: bc    12, 3, 0x80134D68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134D68;
        }
    }

label_80134D58:
    ctx->pc = 0x80134D58u;
    ctx->downcount -= 4;
    // 80134D58: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134D58u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134D5C:
    ctx->pc = 0x80134D5Cu;
    // 80134D5C: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134D5Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134D60:
    ctx->pc = 0x80134D60u;
    // 80134D60: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134D64:
    // 80134D64: b       0x80134D7C
    {
            goto label_80134D7C;
    }

label_80134D68:
    ctx->pc = 0x80134D68u;
    ctx->downcount -= 5;
    // 80134D68: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134D68u)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134D6C:
    ctx->pc = 0x80134D6Cu;
    // 80134D6C: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134D6Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134D70:
    ctx->pc = 0x80134D70u;
    // 80134D70: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134D70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134D74:
    ctx->pc = 0x80134D74u;
    // 80134D74: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134D78:
    // 80134D78: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134D7C:
    ctx->downcount -= 1;
    // 80134D7C: li      r4, 3589
    ctx->gpr[4] = (u32)(s32)(3589);

label_80134D80:
    ctx->downcount -= 2;
    // 80134D80: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80134D84:
    // 80134D84: bl      0x80046B00
    {
            ctx->lr = 0x80134D88u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134D88:
    ctx->downcount -= 5;
    // 80134D88: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134D8C:
    // 80134D8C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80134D90:
    // 80134D90: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134D94:
    // 80134D94: li      r4, 350
    ctx->gpr[4] = (u32)(s32)(350);

label_80134D98:
    // 80134D98: bl      0x80034E9C
    {
            ctx->lr = 0x80134D9Cu;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80134D9C:
    ctx->downcount -= 1;
    // 80134D9C: b       0x80134FDC
    {
            goto label_80134FDC;
    }

label_80134DA0:
    ctx->pc = 0x80134DA0u;
    ctx->downcount -= 7;
    // 80134DA0: lfd     f13, 5976(r29)
    if (!ppc_fp_available(ctx, 0x80134DA0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5976);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134DA4:
    ctx->pc = 0x80134DA4u;
    // 80134DA4: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80134DA4u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_80134DA8:
    ctx->pc = 0x80134DA8u;
    // 80134DA8: fmr    f31, f0
    if (!ppc_fp_available(ctx, 0x80134DA8u)) return;
    ctx->fpr[31] = ctx->fpr[0];

label_80134DAC:
    // 80134DAC: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80134DB0:
    ctx->pc = 0x80134DB0u;
    // 80134DB0: fcmpu   cr0, f0, f13
    if (!ppc_fp_available(ctx, 0x80134DB0u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_80134DB4:
    // 80134DB4: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134DB8:
    // 80134DB8: bc    12, 3, 0x80134DCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134DCC;
        }
    }

label_80134DBC:
    ctx->pc = 0x80134DBCu;
    ctx->downcount -= 4;
    // 80134DBC: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134DBCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134DC0:
    ctx->pc = 0x80134DC0u;
    // 80134DC0: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134DC0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134DC4:
    ctx->pc = 0x80134DC4u;
    // 80134DC4: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134DC8:
    // 80134DC8: b       0x80134DE0
    {
            goto label_80134DE0;
    }

label_80134DCC:
    ctx->pc = 0x80134DCCu;
    ctx->downcount -= 5;
    // 80134DCC: fsub   f0, f31, f13
    if (!ppc_fp_available(ctx, 0x80134DCCu)) return;
    ppc_fsub(ctx, 0, 31, 13);

label_80134DD0:
    ctx->pc = 0x80134DD0u;
    // 80134DD0: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134DD0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134DD4:
    ctx->pc = 0x80134DD4u;
    // 80134DD4: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134DD4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134DD8:
    ctx->pc = 0x80134DD8u;
    // 80134DD8: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134DDC:
    // 80134DDC: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134DE0:
    ctx->downcount -= 3;
    // 80134DE0: li      r4, 4186
    ctx->gpr[4] = (u32)(s32)(4186);

label_80134DE4:
    // 80134DE4: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80134DE8:
    // 80134DE8: bl      0x80046B00
    {
            ctx->lr = 0x80134DECu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134DEC:
    ctx->downcount -= 5;
    // 80134DEC: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134DF0:
    // 80134DF0: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80134DF4:
    // 80134DF4: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80134DF8:
    // 80134DF8: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134DFC:
    // 80134DFC: bl      0x80034E9C
    {
            ctx->lr = 0x80134E00u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80134E00:
    ctx->pc = 0x80134E00u;
    ctx->downcount -= 7;
    // 80134E00: lwz     r5, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134E04:
    // 80134E04: lis     r4, -32737
    ctx->gpr[4] = ((u32)(s32)(-32737) << 16);

label_80134E08:
    // 80134E08: addi    r4, r4, 5832
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5832);

label_80134E0C:
    // 80134E0C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80134E10:
    // 80134E10: srawi r5, r5, 8
    {
        u32 sh = 8u;
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

label_80134E14:
    // 80134E14: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134E18:
    // 80134E18: bl      0x80167074
    {
            ctx->lr = 0x80134E1Cu;
            ctx->pc = 0x80167074u;
            return;
    }

label_80134E1C:
    ctx->pc = 0x80134E1Cu;
    ctx->downcount -= 4;
    // 80134E1C: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134E1Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134E20:
    ctx->pc = 0x80134E20u;
    // 80134E20: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134E20u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134E24:
    // 80134E24: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134E28:
    // 80134E28: bc    12, 3, 0x80134E3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134E3C;
        }
    }

label_80134E2C:
    ctx->pc = 0x80134E2Cu;
    ctx->downcount -= 4;
    // 80134E2C: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134E2Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134E30:
    ctx->pc = 0x80134E30u;
    // 80134E30: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134E30u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134E34:
    ctx->pc = 0x80134E34u;
    // 80134E34: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134E38:
    // 80134E38: b       0x80134E50
    {
            goto label_80134E50;
    }

label_80134E3C:
    ctx->pc = 0x80134E3Cu;
    ctx->downcount -= 5;
    // 80134E3C: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134E3Cu)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134E40:
    ctx->pc = 0x80134E40u;
    // 80134E40: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134E40u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134E44:
    ctx->pc = 0x80134E44u;
    // 80134E44: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134E44u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134E48:
    ctx->pc = 0x80134E48u;
    // 80134E48: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134E4C:
    // 80134E4C: xoris   r5, r5, 0x8000
    ctx->gpr[5] = ctx->gpr[5] ^ (0x8000u << 16);

label_80134E50:
    ctx->downcount -= 5;
    // 80134E50: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134E54:
    // 80134E54: li      r4, 350
    ctx->gpr[4] = (u32)(s32)(350);

label_80134E58:
    // 80134E58: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_80134E5C:
    // 80134E5C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134E60:
    // 80134E60: bl      0x800350B4
    {
            ctx->lr = 0x80134E64u;
            ctx->pc = 0x800350B4u;
            return;
    }

label_80134E64:
    ctx->pc = 0x80134E64u;
    ctx->downcount -= 3;
    // 80134E64: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80134E68:
    // 80134E68: cmpw    r0, r26
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

label_80134E6C:
    // 80134E6C: bc    4, 2, 0x80134FDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134FDC;
        }
    }

label_80134E70:
    ctx->pc = 0x80134E70u;
    ctx->downcount -= 4;
    // 80134E70: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134E70u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134E74:
    ctx->pc = 0x80134E74u;
    // 80134E74: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134E74u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134E78:
    // 80134E78: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134E7C:
    // 80134E7C: bc    12, 3, 0x80134E90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134E90;
        }
    }

label_80134E80:
    ctx->pc = 0x80134E80u;
    ctx->downcount -= 4;
    // 80134E80: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134E80u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134E84:
    ctx->pc = 0x80134E84u;
    // 80134E84: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134E84u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134E88:
    ctx->pc = 0x80134E88u;
    // 80134E88: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134E8C:
    // 80134E8C: b       0x80134EA4
    {
            goto label_80134EA4;
    }

label_80134E90:
    ctx->pc = 0x80134E90u;
    ctx->downcount -= 5;
    // 80134E90: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134E90u)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134E94:
    ctx->pc = 0x80134E94u;
    // 80134E94: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134E94u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134E98:
    ctx->pc = 0x80134E98u;
    // 80134E98: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134E98u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134E9C:
    ctx->pc = 0x80134E9Cu;
    // 80134E9C: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134EA0:
    // 80134EA0: xoris   r5, r5, 0x8000
    ctx->gpr[5] = ctx->gpr[5] ^ (0x8000u << 16);

label_80134EA4:
    ctx->downcount -= 6;
    // 80134EA4: lis     r6, -32737
    ctx->gpr[6] = ((u32)(s32)(-32737) << 16);

label_80134EA8:
    // 80134EA8: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134EAC:
    // 80134EAC: addi    r6, r6, 5836
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(5836);

label_80134EB0:
    // 80134EB0: li      r4, 325
    ctx->gpr[4] = (u32)(s32)(325);

label_80134EB4:
    // 80134EB4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134EB8:
    // 80134EB8: bl      0x800350B4
    {
            ctx->lr = 0x80134EBCu;
            ctx->pc = 0x800350B4u;
            return;
    }

label_80134EBC:
    ctx->downcount -= 1;
    // 80134EBC: b       0x80134FDC
    {
            goto label_80134FDC;
    }

label_80134EC0:
    ctx->pc = 0x80134EC0u;
    ctx->downcount -= 7;
    // 80134EC0: lfd     f13, 5976(r29)
    if (!ppc_fp_available(ctx, 0x80134EC0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5976);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134EC4:
    ctx->pc = 0x80134EC4u;
    // 80134EC4: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80134EC4u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_80134EC8:
    ctx->pc = 0x80134EC8u;
    // 80134EC8: fmr    f31, f0
    if (!ppc_fp_available(ctx, 0x80134EC8u)) return;
    ctx->fpr[31] = ctx->fpr[0];

label_80134ECC:
    // 80134ECC: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80134ED0:
    ctx->pc = 0x80134ED0u;
    // 80134ED0: fcmpu   cr0, f0, f13
    if (!ppc_fp_available(ctx, 0x80134ED0u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[0], ctx->fpr[13], false);

label_80134ED4:
    // 80134ED4: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134ED8:
    // 80134ED8: bc    12, 3, 0x80134EEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134EEC;
        }
    }

label_80134EDC:
    ctx->pc = 0x80134EDCu;
    ctx->downcount -= 4;
    // 80134EDC: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134EDCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134EE0:
    ctx->pc = 0x80134EE0u;
    // 80134EE0: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134EE0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134EE4:
    ctx->pc = 0x80134EE4u;
    // 80134EE4: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134EE8:
    // 80134EE8: b       0x80134F00
    {
            goto label_80134F00;
    }

label_80134EEC:
    ctx->pc = 0x80134EECu;
    ctx->downcount -= 5;
    // 80134EEC: fsub   f0, f31, f13
    if (!ppc_fp_available(ctx, 0x80134EECu)) return;
    ppc_fsub(ctx, 0, 31, 13);

label_80134EF0:
    ctx->pc = 0x80134EF0u;
    // 80134EF0: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134EF0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134EF4:
    ctx->pc = 0x80134EF4u;
    // 80134EF4: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134EF4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134EF8:
    ctx->pc = 0x80134EF8u;
    // 80134EF8: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80134EFC:
    // 80134EFC: xoris   r30, r30, 0x8000
    ctx->gpr[30] = ctx->gpr[30] ^ (0x8000u << 16);

label_80134F00:
    ctx->downcount -= 3;
    // 80134F00: li      r4, 4187
    ctx->gpr[4] = (u32)(s32)(4187);

label_80134F04:
    // 80134F04: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80134F08:
    // 80134F08: bl      0x80046B00
    {
            ctx->lr = 0x80134F0Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80134F0C:
    ctx->downcount -= 5;
    // 80134F0C: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80134F10:
    // 80134F10: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80134F14:
    // 80134F14: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80134F18:
    // 80134F18: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134F1C:
    // 80134F1C: bl      0x80034E9C
    {
            ctx->lr = 0x80134F20u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80134F20:
    ctx->pc = 0x80134F20u;
    ctx->downcount -= 7;
    // 80134F20: lwz     r5, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134F24:
    // 80134F24: lis     r4, -32737
    ctx->gpr[4] = ((u32)(s32)(-32737) << 16);

label_80134F28:
    // 80134F28: addi    r4, r4, 5832
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5832);

label_80134F2C:
    // 80134F2C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80134F30:
    // 80134F30: srawi r5, r5, 8
    {
        u32 sh = 8u;
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

label_80134F34:
    // 80134F34: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134F38:
    // 80134F38: bl      0x80167074
    {
            ctx->lr = 0x80134F3Cu;
            ctx->pc = 0x80167074u;
            return;
    }

label_80134F3C:
    ctx->pc = 0x80134F3Cu;
    ctx->downcount -= 4;
    // 80134F3C: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134F3Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134F40:
    ctx->pc = 0x80134F40u;
    // 80134F40: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134F40u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134F44:
    // 80134F44: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134F48:
    // 80134F48: bc    12, 3, 0x80134F5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134F5C;
        }
    }

label_80134F4C:
    ctx->pc = 0x80134F4Cu;
    ctx->downcount -= 4;
    // 80134F4C: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134F4Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134F50:
    ctx->pc = 0x80134F50u;
    // 80134F50: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134F50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134F54:
    ctx->pc = 0x80134F54u;
    // 80134F54: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134F58:
    // 80134F58: b       0x80134F70
    {
            goto label_80134F70;
    }

label_80134F5C:
    ctx->pc = 0x80134F5Cu;
    ctx->downcount -= 5;
    // 80134F5C: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134F5Cu)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134F60:
    ctx->pc = 0x80134F60u;
    // 80134F60: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134F60u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134F64:
    ctx->pc = 0x80134F64u;
    // 80134F64: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134F64u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134F68:
    ctx->pc = 0x80134F68u;
    // 80134F68: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134F6C:
    // 80134F6C: xoris   r5, r5, 0x8000
    ctx->gpr[5] = ctx->gpr[5] ^ (0x8000u << 16);

label_80134F70:
    ctx->downcount -= 5;
    // 80134F70: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134F74:
    // 80134F74: li      r4, 350
    ctx->gpr[4] = (u32)(s32)(350);

label_80134F78:
    // 80134F78: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_80134F7C:
    // 80134F7C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134F80:
    // 80134F80: bl      0x800350B4
    {
            ctx->lr = 0x80134F84u;
            ctx->pc = 0x800350B4u;
            return;
    }

label_80134F84:
    ctx->pc = 0x80134F84u;
    ctx->downcount -= 3;
    // 80134F84: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80134F88:
    // 80134F88: cmpw    r0, r26
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

label_80134F8C:
    // 80134F8C: bc    4, 2, 0x80134FDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80134FDC;
        }
    }

label_80134F90:
    ctx->pc = 0x80134F90u;
    ctx->downcount -= 4;
    // 80134F90: lfd     f0, 5976(r28)
    if (!ppc_fp_available(ctx, 0x80134F90u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5976);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80134F94:
    ctx->pc = 0x80134F94u;
    // 80134F94: fcmpu   cr0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134F94u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[31], ctx->fpr[0], false);

label_80134F98:
    // 80134F98: cror    3, 2, 1
    {
        u32 a = (ctx->cr >> (31u - 2u)) & 1u;
        u32 b = (ctx->cr >> (31u - 1u)) & 1u;
        u32 mask = 0x80000000u >> 3;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134F9C:
    // 80134F9C: bc    12, 3, 0x80134FB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x10000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80134FB0;
        }
    }

label_80134FA0:
    ctx->pc = 0x80134FA0u;
    ctx->downcount -= 4;
    // 80134FA0: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x80134FA0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_80134FA4:
    ctx->pc = 0x80134FA4u;
    // 80134FA4: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134FA4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_80134FA8:
    ctx->pc = 0x80134FA8u;
    // 80134FA8: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134FAC:
    // 80134FAC: b       0x80134FC4
    {
            goto label_80134FC4;
    }

label_80134FB0:
    ctx->pc = 0x80134FB0u;
    ctx->downcount -= 5;
    // 80134FB0: fsub   f0, f31, f0
    if (!ppc_fp_available(ctx, 0x80134FB0u)) return;
    ppc_fsub(ctx, 0, 31, 0);

label_80134FB4:
    ctx->pc = 0x80134FB4u;
    // 80134FB4: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80134FB4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80134FB8:
    ctx->pc = 0x80134FB8u;
    // 80134FB8: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80134FB8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80134FBC:
    ctx->pc = 0x80134FBCu;
    // 80134FBC: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80134FC0:
    // 80134FC0: xoris   r5, r5, 0x8000
    ctx->gpr[5] = ctx->gpr[5] ^ (0x8000u << 16);

label_80134FC4:
    ctx->downcount -= 6;
    // 80134FC4: lis     r6, -32737
    ctx->gpr[6] = ((u32)(s32)(-32737) << 16);

label_80134FC8:
    // 80134FC8: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80134FCC:
    // 80134FCC: addi    r6, r6, 5836
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(5836);

label_80134FD0:
    // 80134FD0: li      r4, 325
    ctx->gpr[4] = (u32)(s32)(325);

label_80134FD4:
    // 80134FD4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80134FD8:
    // 80134FD8: bl      0x800350B4
    {
            ctx->lr = 0x80134FDCu;
            ctx->pc = 0x800350B4u;
            return;
    }

label_80134FDC:
    ctx->pc = 0x80134FDCu;
    ctx->downcount -= 5;
    // 80134FDC: lfs     f0, 5984(r22)
    if (!ppc_fp_available(ctx, 0x80134FDCu)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(5984);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_80134FE0:
    // 80134FE0: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_80134FE4:
    // 80134FE4: cmpwi   r26, 5
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80134FE8:
    ctx->pc = 0x80134FE8u;
    // 80134FE8: fadds   f30, f30, f0
    if (!ppc_fp_available(ctx, 0x80134FE8u)) return;
    ppc_fadds(ctx, 30, 30, 0);

label_80134FEC:
    // 80134FEC: bc    4, 1, 0x8013499C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013499Cu;
                return;
            }
            goto label_8013499C;
        }
    }

label_80134FF0:
    ctx->pc = 0x80134FF0u;
    ctx->downcount -= 1;
    // 80134FF0: b       0x80135740
    {
            goto label_80135740;
    }

label_80134FF4:
    ctx->pc = 0x80134FF4u;
    ctx->downcount -= 5;
    // 80134FF4: lis     r30, -32697
    ctx->gpr[30] = ((u32)(s32)(-32697) << 16);

label_80134FF8:
    ctx->pc = 0x80134FF8u;
    // 80134FF8: li      r4, -171
    ctx->gpr[4] = (u32)(s32)(-171);

label_80134FFC:
    ctx->pc = 0x80134FFCu;
    // 80134FFC: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80135000:
    ctx->pc = 0x80135000u;
    // 80135000: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80135004:
    ctx->pc = 0x80135004u;
    // 80135004: bl      0x80034BA8
    {
            ctx->lr = 0x80135008u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135008:
    ctx->pc = 0x80135008u;
    ctx->downcount -= 4;
    // 80135008: lis     r23, -32698
    ctx->gpr[23] = ((u32)(s32)(-32698) << 16);

label_8013500C:
    ctx->pc = 0x8013500Cu;
    // 8013500C: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80135010:
    ctx->pc = 0x80135010u;
    // 80135010: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80135014:
    ctx->pc = 0x80135014u;
    // 80135014: bl      0x80035C48
    {
            ctx->lr = 0x80135018u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80135018:
    ctx->pc = 0x80135018u;
    ctx->downcount -= 5;
    // 80135018: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013501C:
    ctx->pc = 0x8013501Cu;
    // 8013501C: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80135020:
    ctx->pc = 0x80135020u;
    // 80135020: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80135020u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135024:
    ctx->pc = 0x80135024u;
    // 80135024: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80135024u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135028:
    ctx->pc = 0x80135028u;
    // 80135028: bl      0x80034E6C
    {
            ctx->lr = 0x8013502Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013502C:
    ctx->pc = 0x8013502Cu;
    ctx->downcount -= 4;
    // 8013502C: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80135030:
    ctx->pc = 0x80135030u;
    // 80135030: li      r4, 3570
    ctx->gpr[4] = (u32)(s32)(3570);

label_80135034:
    ctx->pc = 0x80135034u;
    // 80135034: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_80135038:
    ctx->pc = 0x80135038u;
    // 80135038: bl      0x80046B00
    {
            ctx->lr = 0x8013503Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8013503C:
    ctx->pc = 0x8013503Cu;
    ctx->downcount -= 5;
    // 8013503C: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135040:
    ctx->pc = 0x80135040u;
    // 80135040: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80135044:
    ctx->pc = 0x80135044u;
    // 80135044: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80135048:
    ctx->pc = 0x80135048u;
    // 80135048: li      r5, 70
    ctx->gpr[5] = (u32)(s32)(70);

label_8013504C:
    ctx->pc = 0x8013504Cu;
    // 8013504C: bl      0x80034E9C
    {
            ctx->lr = 0x80135050u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135050:
    ctx->pc = 0x80135050u;
    ctx->downcount -= 2;
    // 80135050: lis     r3, 16
    ctx->gpr[3] = ((u32)(s32)(16) << 16);

label_80135054:
    ctx->pc = 0x80135054u;
    // 80135054: bl      0x80132FD8
    {
            ctx->lr = 0x80135058u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80135058:
    ctx->pc = 0x80135058u;
    ctx->downcount -= 2;
    // 80135058: cmpwi   r3, 0
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

label_8013505C:
    ctx->pc = 0x8013505Cu;
    // 8013505C: bc    4, 2, 0x80135070
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135070;
        }
    }

label_80135060:
    ctx->pc = 0x80135060u;
    ctx->downcount -= 2;
    // 80135060: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80135064:
    ctx->pc = 0x80135064u;
    // 80135064: bl      0x80132FD8
    {
            ctx->lr = 0x80135068u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80135068:
    ctx->pc = 0x80135068u;
    ctx->downcount -= 2;
    // 80135068: cmpwi   r3, 0
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

label_8013506C:
    ctx->pc = 0x8013506Cu;
    // 8013506C: bc    12, 2, 0x801350A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801350A0;
        }
    }

label_80135070:
    ctx->pc = 0x80135070u;
    ctx->downcount -= 5;
    // 80135070: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80135074:
    ctx->pc = 0x80135074u;
    // 80135074: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80135078:
    ctx->pc = 0x80135078u;
    // 80135078: cmpwi   r9, 0
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

label_8013507C:
    ctx->pc = 0x8013507Cu;
    // 8013507C: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80135080:
    ctx->pc = 0x80135080u;
    // 80135080: bc    4, 0, 0x80135090
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135090;
        }
    }

label_80135084:
    ctx->pc = 0x80135084u;
    ctx->downcount -= 3;
    // 80135084: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80135088:
    ctx->pc = 0x80135088u;
    // 80135088: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013508C:
    ctx->pc = 0x8013508Cu;
    // 8013508C: b       0x801350A0
    {
            goto label_801350A0;
    }

label_80135090:
    ctx->pc = 0x80135090u;
    ctx->downcount -= 4;
    // 80135090: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80135094:
    ctx->pc = 0x80135094u;
    // 80135094: lfs     f1, 5896(r28)
    if (!ppc_fp_available(ctx, 0x80135094u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135098:
    ctx->pc = 0x80135098u;
    // 80135098: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8013509C:
    ctx->pc = 0x8013509Cu;
    // 8013509C: bl      0x8004DC00
    {
            ctx->lr = 0x801350A0u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801350A0:
    ctx->pc = 0x801350A0u;
    ctx->downcount -= 2;
    // 801350A0: lis     r3, 32
    ctx->gpr[3] = ((u32)(s32)(32) << 16);

label_801350A4:
    ctx->pc = 0x801350A4u;
    // 801350A4: bl      0x80132FD8
    {
            ctx->lr = 0x801350A8u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_801350A8:
    ctx->pc = 0x801350A8u;
    ctx->downcount -= 2;
    // 801350A8: cmpwi   r3, 0
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

label_801350AC:
    ctx->pc = 0x801350ACu;
    // 801350AC: bc    4, 2, 0x801350C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801350C0;
        }
    }

label_801350B0:
    ctx->pc = 0x801350B0u;
    ctx->downcount -= 2;
    // 801350B0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_801350B4:
    ctx->pc = 0x801350B4u;
    // 801350B4: bl      0x80132FD8
    {
            ctx->lr = 0x801350B8u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_801350B8:
    ctx->pc = 0x801350B8u;
    ctx->downcount -= 2;
    // 801350B8: cmpwi   r3, 0
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

label_801350BC:
    ctx->pc = 0x801350BCu;
    // 801350BC: bc    12, 2, 0x801350F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801350F4;
        }
    }

label_801350C0:
    ctx->pc = 0x801350C0u;
    ctx->downcount -= 5;
    // 801350C0: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801350C4:
    ctx->pc = 0x801350C4u;
    // 801350C4: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801350C8:
    ctx->pc = 0x801350C8u;
    // 801350C8: cmpwi   r9, 2
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801350CC:
    ctx->pc = 0x801350CCu;
    // 801350CC: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801350D0:
    ctx->pc = 0x801350D0u;
    // 801350D0: bc    4, 1, 0x801350E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801350E0;
        }
    }

label_801350D4:
    ctx->pc = 0x801350D4u;
    ctx->downcount -= 3;
    // 801350D4: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_801350D8:
    ctx->pc = 0x801350D8u;
    // 801350D8: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801350DC:
    ctx->pc = 0x801350DCu;
    // 801350DC: b       0x801350F4
    {
            goto label_801350F4;
    }

label_801350E0:
    ctx->pc = 0x801350E0u;
    ctx->downcount -= 5;
    // 801350E0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801350E4:
    ctx->pc = 0x801350E4u;
    // 801350E4: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_801350E8:
    ctx->pc = 0x801350E8u;
    // 801350E8: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x801350E8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801350EC:
    ctx->pc = 0x801350ECu;
    // 801350EC: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_801350F0:
    ctx->pc = 0x801350F0u;
    // 801350F0: bl      0x8004DC00
    {
            ctx->lr = 0x801350F4u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801350F4:
    ctx->pc = 0x801350F4u;
    ctx->downcount -= 5;
    // 801350F4: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_801350F8:
    ctx->pc = 0x801350F8u;
    // 801350F8: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_801350FC:
    ctx->pc = 0x801350FCu;
    // 801350FC: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135100:
    ctx->pc = 0x80135100u;
    // 80135100: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_80135104:
    ctx->pc = 0x80135104u;
    // 80135104: bl      0x80034BA8
    {
            ctx->lr = 0x80135108u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135108:
    ctx->pc = 0x80135108u;
    ctx->downcount -= 4;
    // 80135108: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_8013510C:
    ctx->pc = 0x8013510Cu;
    // 8013510C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135110:
    ctx->pc = 0x80135110u;
    // 80135110: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80135114:
    ctx->pc = 0x80135114u;
    // 80135114: bl      0x800353D4
    {
            ctx->lr = 0x80135118u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_80135118:
    ctx->pc = 0x80135118u;
    ctx->downcount -= 4;
    // 80135118: lis     r24, -32698
    ctx->gpr[24] = ((u32)(s32)(-32698) << 16);

label_8013511C:
    ctx->pc = 0x8013511Cu;
    // 8013511C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135120:
    ctx->pc = 0x80135120u;
    // 80135120: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80135124:
    ctx->pc = 0x80135124u;
    // 80135124: bl      0x80035C48
    {
            ctx->lr = 0x80135128u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80135128:
    ctx->pc = 0x80135128u;
    ctx->downcount -= 6;
    // 80135128: lis     r21, -32699
    ctx->gpr[21] = ((u32)(s32)(-32699) << 16);

label_8013512C:
    ctx->pc = 0x8013512Cu;
    // 8013512C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80135130:
    ctx->pc = 0x80135130u;
    // 80135130: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135134:
    ctx->pc = 0x80135134u;
    // 80135134: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80135138:
    ctx->pc = 0x80135138u;
    // 80135138: lis     r22, -32737
    ctx->gpr[22] = ((u32)(s32)(-32737) << 16);

label_8013513C:
    ctx->pc = 0x8013513Cu;
    // 8013513C: bl      0x80035C50
    {
            ctx->lr = 0x80135140u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_80135140:
    ctx->pc = 0x80135140u;
    ctx->downcount -= 4;
    // 80135140: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80135144:
    ctx->pc = 0x80135144u;
    // 80135144: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135148:
    ctx->pc = 0x80135148u;
    // 80135148: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8013514C:
    ctx->pc = 0x8013514Cu;
    // 8013514C: bl      0x80035C40
    {
            ctx->lr = 0x80135150u;
            ctx->pc = 0x80035C40u;
            return;
    }

label_80135150:
    ctx->pc = 0x80135150u;
    ctx->downcount -= 5;
    // 80135150: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135154:
    ctx->pc = 0x80135154u;
    // 80135154: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135158:
    ctx->pc = 0x80135158u;
    // 80135158: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80135158u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013515C:
    ctx->pc = 0x8013515Cu;
    // 8013515C: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x8013515Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135160:
    ctx->pc = 0x80135160u;
    // 80135160: bl      0x80034E6C
    {
            ctx->lr = 0x80135164u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80135164:
    ctx->pc = 0x80135164u;
    ctx->downcount -= 2;
    // 80135164: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135168:
    ctx->pc = 0x80135168u;
    // 80135168: lfs     f30, 5988(r9)
    if (!ppc_fp_available(ctx, 0x80135168u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5988);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_8013516C:
    ctx->pc = 0x8013516Cu;
    ctx->downcount -= 3;
    // 8013516C: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135170:
    // 80135170: cmpw    r0, r26
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

label_80135174:
    // 80135174: bc    4, 2, 0x801351A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801351A4;
        }
    }

label_80135178:
    ctx->pc = 0x80135178u;
    ctx->downcount -= 3;
    // 80135178: lwz     r0, -32364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32364);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013517C:
    // 8013517C: andi.   r6, r0, 0x0010
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80135180:
    // 80135180: bc    12, 2, 0x80135194
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135194;
        }
    }

label_80135184:
    ctx->downcount -= 3;
    // 80135184: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80135188:
    // 80135188: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8013518C:
    // 8013518C: bl      0x80034BA8
    {
            ctx->lr = 0x80135190u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135190:
    ctx->downcount -= 1;
    // 80135190: b       0x801351B4
    {
            goto label_801351B4;
    }

label_80135194:
    ctx->downcount -= 3;
    // 80135194: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80135198:
    // 80135198: lis     r4, -256
    ctx->gpr[4] = ((u32)(s32)(-256) << 16);

label_8013519C:
    // 8013519C: bl      0x80034BA8
    {
            ctx->lr = 0x801351A0u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801351A0:
    ctx->downcount -= 1;
    // 801351A0: b       0x801351B4
    {
            goto label_801351B4;
    }

label_801351A4:
    ctx->downcount -= 4;
    // 801351A4: lis     r4, -36
    ctx->gpr[4] = ((u32)(s32)(-36) << 16);

label_801351A8:
    // 801351A8: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801351AC:
    // 801351AC: ori     r4, r4, 0xC828
    ctx->gpr[4] = ctx->gpr[4] | 0xC828u;

label_801351B0:
    // 801351B0: bl      0x80034BA8
    {
            ctx->lr = 0x801351B4u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801351B4:
    ctx->pc = 0x801351B4u;
    ctx->downcount -= 9;
    // 801351B4: fmr    f13, f30
    if (!ppc_fp_available(ctx, 0x801351B4u)) return;
    ctx->fpr[13] = ctx->fpr[30];

label_801351B8:
    ctx->pc = 0x801351B8u;
    // 801351B8: fctiwz    f0, f13
    if (!ppc_fp_available(ctx, 0x801351B8u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801351BC:
    // 801351BC: addi    r4, r26, 4183
    ctx->gpr[4] = ctx->gpr[26] + (u32)(s32)(4183);

label_801351C0:
    ctx->pc = 0x801351C0u;
    // 801351C0: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x801351C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801351C4:
    ctx->pc = 0x801351C4u;
    // 801351C4: fmr    f31, f13
    if (!ppc_fp_available(ctx, 0x801351C4u)) return;
    ctx->fpr[31] = ctx->fpr[13];

label_801351C8:
    // 801351C8: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_801351CC:
    // 801351CC: addi    r30, r21, -13308
    ctx->gpr[30] = ctx->gpr[21] + (u32)(s32)(-13308);

label_801351D0:
    ctx->pc = 0x801351D0u;
    // 801351D0: lwz     r31, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801351D4:
    // 801351D4: bl      0x80046B00
    {
            ctx->lr = 0x801351D8u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801351D8:
    ctx->downcount -= 5;
    // 801351D8: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801351DC:
    // 801351DC: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_801351E0:
    // 801351E0: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801351E4:
    // 801351E4: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801351E8:
    // 801351E8: bl      0x80034E9C
    {
            ctx->lr = 0x801351ECu;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801351EC:
    ctx->pc = 0x801351ECu;
    ctx->downcount -= 3;
    // 801351EC: lwzx    r0, r30, r29
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[29];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801351F0:
    // 801351F0: cmpwi   r0, 0
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

label_801351F4:
    // 801351F4: bc    12, 2, 0x80135328
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135328;
        }
    }

label_801351F8:
    ctx->downcount -= 4;
    // 801351F8: addi    r9, r30, 4
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(4);

label_801351FC:
    ctx->pc = 0x801351FCu;
    // 801351FC: lwzx    r0, r9, r29
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[29];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135200:
    // 80135200: cmpwi   r0, 0
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

label_80135204:
    // 80135204: bc    4, 2, 0x80135304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135304;
        }
    }

label_80135208:
    ctx->downcount -= 5;
    // 80135208: addi    r0, r1, 24
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(24);

label_8013520C:
    // 8013520C: addi    r28, r30, 48
    ctx->gpr[28] = ctx->gpr[30] + (u32)(s32)(48);

label_80135210:
    // 80135210: or   r3, r0, r0
    {
        ctx->gpr[3] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80135214:
    // 80135214: or   r25, r0, r0
    {
        ctx->gpr[25] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80135218:
    // 80135218: bl      0x80036150
    {
            ctx->lr = 0x8013521Cu;
            ctx->pc = 0x80036150u;
            return;
    }

label_8013521C:
    ctx->downcount -= 7;
    // 8013521C: addi    r30, r1, 2184
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(2184);

label_80135220:
    // 80135220: add   r9, r29, r28
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80135224:
    ctx->pc = 0x80135224u;
    // 80135224: lwz     r27, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_80135228:
    // 80135228: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013522C:
    // 8013522C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80135230:
    // 80135230: li      r5, 8192
    ctx->gpr[5] = (u32)(s32)(8192);

label_80135234:
    // 80135234: bl      0x801698F0
    {
            ctx->lr = 0x80135238u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80135238:
    ctx->downcount -= 2;
    // 80135238: cmpwi   r27, 1
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8013523C:
    // 8013523C: bc    12, 1, 0x80135250
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135250;
        }
    }

label_80135240:
    ctx->pc = 0x80135240u;
    ctx->downcount -= 2;
    // 80135240: lwzx    r3, r29, r28
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[28];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80135244:
    // 80135244: bl      0x80132D84
    {
            ctx->lr = 0x80135248u;
            ctx->pc = 0x80132D84u;
            return;
    }

label_80135248:
    ctx->downcount -= 2;
    // 80135248: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013524C:
    // 8013524C: b       0x80135308
    {
            goto label_80135308;
    }

label_80135250:
    ctx->pc = 0x80135250u;
    ctx->downcount -= 2;
    // 80135250: lwzx    r3, r29, r28
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[28];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80135254:
    // 80135254: bl      0x80132D84
    {
            ctx->lr = 0x80135258u;
            ctx->pc = 0x80132D84u;
            return;
    }

label_80135258:
    ctx->downcount -= 3;
    // 80135258: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013525C:
    // 8013525C: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80135260:
    // 80135260: bl      0x80046B00
    {
            ctx->lr = 0x80135264u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135264:
    ctx->downcount -= 4;
    // 80135264: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135268:
    // 80135268: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8013526C:
    // 8013526C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80135270:
    // 80135270: bl      0x800362AC
    {
            ctx->lr = 0x80135274u;
            ctx->pc = 0x800362ACu;
            return;
    }

label_80135274:
    ctx->downcount -= 2;
    // 80135274: andi.   r0, r27, 0x0001
    {
        ctx->gpr[0] = ctx->gpr[27] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80135278:
    // 80135278: bc    4, 2, 0x8013529C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013529C;
        }
    }

label_8013527C:
    ctx->downcount -= 3;
    // 8013527C: li      r4, 4648
    ctx->gpr[4] = (u32)(s32)(4648);

label_80135280:
    // 80135280: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80135284:
    // 80135284: bl      0x80046B00
    {
            ctx->lr = 0x80135288u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135288:
    ctx->downcount -= 4;
    // 80135288: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013528C:
    // 8013528C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80135290:
    // 80135290: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80135294:
    // 80135294: bl      0x800362AC
    {
            ctx->lr = 0x80135298u;
            ctx->pc = 0x800362ACu;
            return;
    }

label_80135298:
    ctx->downcount -= 1;
    // 80135298: b       0x801352B8
    {
            goto label_801352B8;
    }

label_8013529C:
    ctx->downcount -= 3;
    // 8013529C: li      r4, 4649
    ctx->gpr[4] = (u32)(s32)(4649);

label_801352A0:
    // 801352A0: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_801352A4:
    // 801352A4: bl      0x80046B00
    {
            ctx->lr = 0x801352A8u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801352A8:
    ctx->downcount -= 4;
    // 801352A8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801352AC:
    // 801352AC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801352B0:
    // 801352B0: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801352B4:
    // 801352B4: bl      0x800362AC
    {
            ctx->lr = 0x801352B8u;
            ctx->pc = 0x800362ACu;
            return;
    }

label_801352B8:
    ctx->downcount -= 5;
    // 801352B8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801352BC:
    // 801352BC: srawi r5, r27, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[27];
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

label_801352C0:
    // 801352C0: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801352C4:
    // 801352C4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_801352C8:
    // 801352C8: bl      0x800361A8
    {
            ctx->lr = 0x801352CCu;
            ctx->pc = 0x800361A8u;
            return;
    }

label_801352CC:
    ctx->downcount -= 6;
    // 801352CC: lis     r4, -32737
    ctx->gpr[4] = ((u32)(s32)(-32737) << 16);

label_801352D0:
    // 801352D0: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801352D4:
    // 801352D4: addi    r4, r4, 5844
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5844);

label_801352D8:
    // 801352D8: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801352DC:
    // 801352DC: li      r6, 4096
    ctx->gpr[6] = (u32)(s32)(4096);

label_801352E0:
    // 801352E0: bl      0x80036410
    {
            ctx->lr = 0x801352E4u;
            ctx->pc = 0x80036410u;
            return;
    }

label_801352E4:
    ctx->pc = 0x801352E4u;
    ctx->downcount -= 7;
    // 801352E4: fctiwz    f0, f31
    if (!ppc_fp_available(ctx, 0x801352E4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[31], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_801352E8:
    ctx->pc = 0x801352E8u;
    // 801352E8: stfd     f0, 18568(r1)
    if (!ppc_fp_available(ctx, 0x801352E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_801352EC:
    // 801352EC: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801352F0:
    // 801352F0: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801352F4:
    // 801352F4: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_801352F8:
    ctx->pc = 0x801352F8u;
    // 801352F8: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801352FC:
    // 801352FC: bl      0x80034E9C
    {
            ctx->lr = 0x80135300u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135300:
    ctx->downcount -= 1;
    // 80135300: b       0x80135348
    {
            goto label_80135348;
    }

label_80135304:
    ctx->downcount -= 1;
    // 80135304: li      r4, 4148
    ctx->gpr[4] = (u32)(s32)(4148);

label_80135308:
    ctx->downcount -= 2;
    // 80135308: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_8013530C:
    // 8013530C: bl      0x80046B00
    {
            ctx->lr = 0x80135310u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135310:
    ctx->downcount -= 5;
    // 80135310: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135314:
    // 80135314: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80135318:
    // 80135318: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_8013531C:
    // 8013531C: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_80135320:
    // 80135320: bl      0x80034E9C
    {
            ctx->lr = 0x80135324u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135324:
    ctx->downcount -= 1;
    // 80135324: b       0x80135348
    {
            goto label_80135348;
    }

label_80135328:
    ctx->downcount -= 3;
    // 80135328: li      r4, 3579
    ctx->gpr[4] = (u32)(s32)(3579);

label_8013532C:
    // 8013532C: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80135330:
    // 80135330: bl      0x80046B00
    {
            ctx->lr = 0x80135334u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135334:
    ctx->downcount -= 5;
    // 80135334: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135338:
    // 80135338: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8013533C:
    // 8013533C: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80135340:
    // 80135340: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_80135344:
    // 80135344: bl      0x80034E9C
    {
            ctx->lr = 0x80135348u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135348:
    ctx->pc = 0x80135348u;
    ctx->downcount -= 6;
    // 80135348: lfs     f0, 5992(r22)
    if (!ppc_fp_available(ctx, 0x80135348u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(5992);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8013534C:
    // 8013534C: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_80135350:
    // 80135350: addi    r29, r29, 8376
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(8376);

label_80135354:
    // 80135354: cmpwi   r26, 2
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135358:
    ctx->pc = 0x80135358u;
    // 80135358: fadds   f30, f30, f0
    if (!ppc_fp_available(ctx, 0x80135358u)) return;
    ppc_fadds(ctx, 30, 30, 0);

label_8013535C:
    // 8013535C: bc    4, 1, 0x8013516C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013516Cu;
                return;
            }
            goto label_8013516C;
        }
    }

label_80135360:
    ctx->pc = 0x80135360u;
    ctx->downcount -= 1;
    // 80135360: b       0x80135740
    {
            goto label_80135740;
    }

label_80135364:
    ctx->pc = 0x80135364u;
    ctx->downcount -= 5;
    // 80135364: lis     r30, -32697
    ctx->gpr[30] = ((u32)(s32)(-32697) << 16);

label_80135368:
    ctx->pc = 0x80135368u;
    // 80135368: li      r4, -171
    ctx->gpr[4] = (u32)(s32)(-171);

label_8013536C:
    ctx->pc = 0x8013536Cu;
    // 8013536C: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80135370:
    ctx->pc = 0x80135370u;
    // 80135370: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80135374:
    ctx->pc = 0x80135374u;
    // 80135374: bl      0x80034BA8
    {
            ctx->lr = 0x80135378u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135378:
    ctx->pc = 0x80135378u;
    ctx->downcount -= 4;
    // 80135378: lis     r23, -32698
    ctx->gpr[23] = ((u32)(s32)(-32698) << 16);

label_8013537C:
    ctx->pc = 0x8013537Cu;
    // 8013537C: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80135380:
    ctx->pc = 0x80135380u;
    // 80135380: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80135384:
    ctx->pc = 0x80135384u;
    // 80135384: bl      0x80035C48
    {
            ctx->lr = 0x80135388u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80135388:
    ctx->pc = 0x80135388u;
    ctx->downcount -= 5;
    // 80135388: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013538C:
    ctx->pc = 0x8013538Cu;
    // 8013538C: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_80135390:
    ctx->pc = 0x80135390u;
    // 80135390: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80135390u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135394:
    ctx->pc = 0x80135394u;
    // 80135394: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80135394u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135398:
    ctx->pc = 0x80135398u;
    // 80135398: bl      0x80034E6C
    {
            ctx->lr = 0x8013539Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013539C:
    ctx->pc = 0x8013539Cu;
    ctx->downcount -= 4;
    // 8013539C: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801353A0:
    ctx->pc = 0x801353A0u;
    // 801353A0: li      r4, 3569
    ctx->gpr[4] = (u32)(s32)(3569);

label_801353A4:
    ctx->pc = 0x801353A4u;
    // 801353A4: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_801353A8:
    ctx->pc = 0x801353A8u;
    // 801353A8: bl      0x80046B00
    {
            ctx->lr = 0x801353ACu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801353AC:
    ctx->pc = 0x801353ACu;
    ctx->downcount -= 5;
    // 801353AC: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801353B0:
    ctx->pc = 0x801353B0u;
    // 801353B0: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_801353B4:
    ctx->pc = 0x801353B4u;
    // 801353B4: addi    r3, r30, -19280
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-19280);

label_801353B8:
    ctx->pc = 0x801353B8u;
    // 801353B8: li      r5, 70
    ctx->gpr[5] = (u32)(s32)(70);

label_801353BC:
    ctx->pc = 0x801353BCu;
    // 801353BC: bl      0x80034E9C
    {
            ctx->lr = 0x801353C0u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801353C0:
    ctx->pc = 0x801353C0u;
    ctx->downcount -= 2;
    // 801353C0: lis     r3, 16
    ctx->gpr[3] = ((u32)(s32)(16) << 16);

label_801353C4:
    ctx->pc = 0x801353C4u;
    // 801353C4: bl      0x80132FD8
    {
            ctx->lr = 0x801353C8u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_801353C8:
    ctx->pc = 0x801353C8u;
    ctx->downcount -= 2;
    // 801353C8: cmpwi   r3, 0
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

label_801353CC:
    ctx->pc = 0x801353CCu;
    // 801353CC: bc    4, 2, 0x801353E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801353E0;
        }
    }

label_801353D0:
    ctx->pc = 0x801353D0u;
    ctx->downcount -= 2;
    // 801353D0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801353D4:
    ctx->pc = 0x801353D4u;
    // 801353D4: bl      0x80132FD8
    {
            ctx->lr = 0x801353D8u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_801353D8:
    ctx->pc = 0x801353D8u;
    ctx->downcount -= 2;
    // 801353D8: cmpwi   r3, 0
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

label_801353DC:
    ctx->pc = 0x801353DCu;
    // 801353DC: bc    12, 2, 0x8013540C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013540C;
        }
    }

label_801353E0:
    ctx->pc = 0x801353E0u;
    ctx->downcount -= 5;
    // 801353E0: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801353E4:
    ctx->pc = 0x801353E4u;
    // 801353E4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801353E8:
    ctx->pc = 0x801353E8u;
    // 801353E8: cmpwi   r9, 0
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

label_801353EC:
    ctx->pc = 0x801353ECu;
    // 801353EC: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801353F0:
    ctx->pc = 0x801353F0u;
    // 801353F0: bc    4, 0, 0x801353FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801353FC;
        }
    }

label_801353F4:
    ctx->pc = 0x801353F4u;
    ctx->downcount -= 2;
    // 801353F4: stw     r20, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[20]);
    }

label_801353F8:
    ctx->pc = 0x801353F8u;
    // 801353F8: b       0x8013540C
    {
            goto label_8013540C;
    }

label_801353FC:
    ctx->pc = 0x801353FCu;
    ctx->downcount -= 4;
    // 801353FC: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80135400:
    ctx->pc = 0x80135400u;
    // 80135400: lfs     f1, 5896(r28)
    if (!ppc_fp_available(ctx, 0x80135400u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135404:
    ctx->pc = 0x80135404u;
    // 80135404: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80135408:
    ctx->pc = 0x80135408u;
    // 80135408: bl      0x8004DC00
    {
            ctx->lr = 0x8013540Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8013540C:
    ctx->pc = 0x8013540Cu;
    ctx->downcount -= 2;
    // 8013540C: lis     r3, 32
    ctx->gpr[3] = ((u32)(s32)(32) << 16);

label_80135410:
    ctx->pc = 0x80135410u;
    // 80135410: bl      0x80132FD8
    {
            ctx->lr = 0x80135414u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80135414:
    ctx->pc = 0x80135414u;
    ctx->downcount -= 2;
    // 80135414: cmpwi   r3, 0
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

label_80135418:
    ctx->pc = 0x80135418u;
    // 80135418: bc    4, 2, 0x8013542C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013542C;
        }
    }

label_8013541C:
    ctx->pc = 0x8013541Cu;
    ctx->downcount -= 2;
    // 8013541C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80135420:
    ctx->pc = 0x80135420u;
    // 80135420: bl      0x80132FD8
    {
            ctx->lr = 0x80135424u;
            ctx->pc = 0x80132FD8u;
            return;
    }

label_80135424:
    ctx->pc = 0x80135424u;
    ctx->downcount -= 2;
    // 80135424: cmpwi   r3, 0
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

label_80135428:
    ctx->pc = 0x80135428u;
    // 80135428: bc    12, 2, 0x80135460
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135460;
        }
    }

label_8013542C:
    ctx->pc = 0x8013542Cu;
    ctx->downcount -= 5;
    // 8013542C: lwz     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80135430:
    ctx->pc = 0x80135430u;
    // 80135430: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80135434:
    ctx->pc = 0x80135434u;
    // 80135434: cmpwi   r9, 3
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135438:
    ctx->pc = 0x80135438u;
    // 80135438: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8013543C:
    ctx->pc = 0x8013543Cu;
    // 8013543C: bc    4, 1, 0x8013544C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013544C;
        }
    }

label_80135440:
    ctx->pc = 0x80135440u;
    ctx->downcount -= 3;
    // 80135440: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_80135444:
    ctx->pc = 0x80135444u;
    // 80135444: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135448:
    ctx->pc = 0x80135448u;
    // 80135448: b       0x80135460
    {
            goto label_80135460;
    }

label_8013544C:
    ctx->pc = 0x8013544Cu;
    ctx->downcount -= 5;
    // 8013544C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135450:
    ctx->pc = 0x80135450u;
    // 80135450: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80135454:
    ctx->pc = 0x80135454u;
    // 80135454: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80135454u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135458:
    ctx->pc = 0x80135458u;
    // 80135458: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8013545C:
    ctx->pc = 0x8013545Cu;
    // 8013545C: bl      0x8004DC00
    {
            ctx->lr = 0x80135460u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80135460:
    ctx->pc = 0x80135460u;
    ctx->downcount -= 5;
    // 80135460: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_80135464:
    ctx->pc = 0x80135464u;
    // 80135464: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80135468:
    ctx->pc = 0x80135468u;
    // 80135468: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013546C:
    ctx->pc = 0x8013546Cu;
    // 8013546C: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80135470:
    ctx->pc = 0x80135470u;
    // 80135470: bl      0x800353D4
    {
            ctx->lr = 0x80135474u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_80135474:
    ctx->pc = 0x80135474u;
    ctx->downcount -= 4;
    // 80135474: lis     r24, -32698
    ctx->gpr[24] = ((u32)(s32)(-32698) << 16);

label_80135478:
    ctx->pc = 0x80135478u;
    // 80135478: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8013547C:
    ctx->pc = 0x8013547Cu;
    // 8013547C: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80135480:
    ctx->pc = 0x80135480u;
    // 80135480: bl      0x80035C48
    {
            ctx->lr = 0x80135484u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80135484:
    ctx->pc = 0x80135484u;
    ctx->downcount -= 6;
    // 80135484: lis     r22, -32737
    ctx->gpr[22] = ((u32)(s32)(-32737) << 16);

label_80135488:
    ctx->pc = 0x80135488u;
    // 80135488: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8013548C:
    ctx->pc = 0x8013548Cu;
    // 8013548C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135490:
    ctx->pc = 0x80135490u;
    // 80135490: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80135494:
    ctx->pc = 0x80135494u;
    // 80135494: lis     r21, -32699
    ctx->gpr[21] = ((u32)(s32)(-32699) << 16);

label_80135498:
    ctx->pc = 0x80135498u;
    // 80135498: bl      0x80035C50
    {
            ctx->lr = 0x8013549Cu;
            ctx->pc = 0x80035C50u;
            return;
    }

label_8013549C:
    ctx->pc = 0x8013549Cu;
    ctx->downcount -= 4;
    // 8013549C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_801354A0:
    ctx->pc = 0x801354A0u;
    // 801354A0: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801354A4:
    ctx->pc = 0x801354A4u;
    // 801354A4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801354A8:
    ctx->pc = 0x801354A8u;
    // 801354A8: bl      0x80035C40
    {
            ctx->lr = 0x801354ACu;
            ctx->pc = 0x80035C40u;
            return;
    }

label_801354AC:
    ctx->pc = 0x801354ACu;
    ctx->downcount -= 5;
    // 801354AC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801354B0:
    ctx->pc = 0x801354B0u;
    // 801354B0: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801354B4:
    ctx->pc = 0x801354B4u;
    // 801354B4: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x801354B4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801354B8:
    ctx->pc = 0x801354B8u;
    // 801354B8: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801354B8u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801354BC:
    ctx->pc = 0x801354BCu;
    // 801354BC: bl      0x80034E6C
    {
            ctx->lr = 0x801354C0u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_801354C0:
    ctx->pc = 0x801354C0u;
    ctx->downcount -= 2;
    // 801354C0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801354C4:
    ctx->pc = 0x801354C4u;
    // 801354C4: lfs     f30, 5996(r9)
    if (!ppc_fp_available(ctx, 0x801354C4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5996);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_801354C8:
    ctx->pc = 0x801354C8u;
    ctx->downcount -= 3;
    // 801354C8: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801354CC:
    // 801354CC: cmpw    r0, r26
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

label_801354D0:
    // 801354D0: bc    4, 2, 0x80135500
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135500;
        }
    }

label_801354D4:
    ctx->pc = 0x801354D4u;
    ctx->downcount -= 3;
    // 801354D4: lwz     r0, -32364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32364);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801354D8:
    // 801354D8: andi.   r6, r0, 0x0010
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801354DC:
    // 801354DC: bc    12, 2, 0x801354F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801354F0;
        }
    }

label_801354E0:
    ctx->downcount -= 3;
    // 801354E0: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801354E4:
    // 801354E4: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801354E8:
    // 801354E8: bl      0x80034BA8
    {
            ctx->lr = 0x801354ECu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801354EC:
    ctx->downcount -= 1;
    // 801354EC: b       0x80135510
    {
            goto label_80135510;
    }

label_801354F0:
    ctx->downcount -= 3;
    // 801354F0: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801354F4:
    // 801354F4: lis     r4, -256
    ctx->gpr[4] = ((u32)(s32)(-256) << 16);

label_801354F8:
    // 801354F8: bl      0x80034BA8
    {
            ctx->lr = 0x801354FCu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801354FC:
    ctx->downcount -= 1;
    // 801354FC: b       0x80135510
    {
            goto label_80135510;
    }

label_80135500:
    ctx->downcount -= 4;
    // 80135500: lis     r4, -36
    ctx->gpr[4] = ((u32)(s32)(-36) << 16);

label_80135504:
    // 80135504: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80135508:
    // 80135508: ori     r4, r4, 0xC828
    ctx->gpr[4] = ctx->gpr[4] | 0xC828u;

label_8013550C:
    // 8013550C: bl      0x80034BA8
    {
            ctx->lr = 0x80135510u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135510:
    ctx->pc = 0x80135510u;
    ctx->downcount -= 8;
    // 80135510: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80135510u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_80135514:
    ctx->pc = 0x80135514u;
    // 80135514: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80135514u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80135518:
    // 80135518: addi    r4, r26, 4183
    ctx->gpr[4] = ctx->gpr[26] + (u32)(s32)(4183);

label_8013551C:
    ctx->pc = 0x8013551Cu;
    // 8013551C: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x8013551Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80135520:
    // 80135520: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80135524:
    // 80135524: addi    r30, r21, -13308
    ctx->gpr[30] = ctx->gpr[21] + (u32)(s32)(-13308);

label_80135528:
    ctx->pc = 0x80135528u;
    // 80135528: lwz     r28, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8013552C:
    // 8013552C: bl      0x80046B00
    {
            ctx->lr = 0x80135530u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135530:
    ctx->downcount -= 5;
    // 80135530: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135534:
    // 80135534: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80135538:
    // 80135538: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_8013553C:
    // 8013553C: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80135540:
    // 80135540: bl      0x80034E9C
    {
            ctx->lr = 0x80135544u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135544:
    ctx->pc = 0x80135544u;
    ctx->downcount -= 3;
    // 80135544: lwzx    r0, r30, r31
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[31];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135548:
    // 80135548: cmpwi   r0, 0
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

label_8013554C:
    // 8013554C: bc    12, 2, 0x80135684
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135684;
        }
    }

label_80135550:
    ctx->downcount -= 4;
    // 80135550: addi    r9, r30, 4
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(4);

label_80135554:
    ctx->pc = 0x80135554u;
    // 80135554: lwzx    r0, r9, r31
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[31];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135558:
    // 80135558: cmpwi   r0, 0
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

label_8013555C:
    // 8013555C: bc    4, 2, 0x80135660
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135660;
        }
    }

label_80135560:
    ctx->downcount -= 5;
    // 80135560: addi    r0, r1, 24
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(24);

label_80135564:
    // 80135564: addi    r29, r30, 48
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(48);

label_80135568:
    // 80135568: or   r3, r0, r0
    {
        ctx->gpr[3] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8013556C:
    // 8013556C: or   r25, r0, r0
    {
        ctx->gpr[25] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80135570:
    // 80135570: bl      0x80036150
    {
            ctx->lr = 0x80135574u;
            ctx->pc = 0x80036150u;
            return;
    }

label_80135574:
    ctx->downcount -= 7;
    // 80135574: addi    r30, r1, 10376
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(10376);

label_80135578:
    // 80135578: add   r9, r31, r29
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8013557C:
    ctx->pc = 0x8013557Cu;
    // 8013557C: lwz     r27, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_80135580:
    // 80135580: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80135584:
    // 80135584: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80135588:
    // 80135588: li      r5, 8192
    ctx->gpr[5] = (u32)(s32)(8192);

label_8013558C:
    // 8013558C: bl      0x801698F0
    {
            ctx->lr = 0x80135590u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80135590:
    ctx->downcount -= 2;
    // 80135590: cmpwi   r27, 1
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135594:
    // 80135594: bc    12, 1, 0x801355A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801355A8;
        }
    }

label_80135598:
    ctx->pc = 0x80135598u;
    ctx->downcount -= 2;
    // 80135598: lwzx    r3, r31, r29
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[29];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8013559C:
    // 8013559C: bl      0x80132D84
    {
            ctx->lr = 0x801355A0u;
            ctx->pc = 0x80132D84u;
            return;
    }

label_801355A0:
    ctx->downcount -= 2;
    // 801355A0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801355A4:
    // 801355A4: b       0x80135664
    {
            goto label_80135664;
    }

label_801355A8:
    ctx->pc = 0x801355A8u;
    ctx->downcount -= 2;
    // 801355A8: lwzx    r3, r31, r29
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[29];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801355AC:
    // 801355AC: bl      0x80132D84
    {
            ctx->lr = 0x801355B0u;
            ctx->pc = 0x80132D84u;
            return;
    }

label_801355B0:
    ctx->downcount -= 3;
    // 801355B0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801355B4:
    // 801355B4: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_801355B8:
    // 801355B8: bl      0x80046B00
    {
            ctx->lr = 0x801355BCu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801355BC:
    ctx->downcount -= 4;
    // 801355BC: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801355C0:
    // 801355C0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801355C4:
    // 801355C4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801355C8:
    // 801355C8: bl      0x800362AC
    {
            ctx->lr = 0x801355CCu;
            ctx->pc = 0x800362ACu;
            return;
    }

label_801355CC:
    ctx->downcount -= 2;
    // 801355CC: andi.   r0, r27, 0x0001
    {
        ctx->gpr[0] = ctx->gpr[27] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801355D0:
    // 801355D0: bc    4, 2, 0x801355F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801355F4;
        }
    }

label_801355D4:
    ctx->downcount -= 3;
    // 801355D4: li      r4, 4648
    ctx->gpr[4] = (u32)(s32)(4648);

label_801355D8:
    // 801355D8: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_801355DC:
    // 801355DC: bl      0x80046B00
    {
            ctx->lr = 0x801355E0u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801355E0:
    ctx->downcount -= 4;
    // 801355E0: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801355E4:
    // 801355E4: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801355E8:
    // 801355E8: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_801355EC:
    // 801355EC: bl      0x800362AC
    {
            ctx->lr = 0x801355F0u;
            ctx->pc = 0x800362ACu;
            return;
    }

label_801355F0:
    ctx->downcount -= 1;
    // 801355F0: b       0x80135610
    {
            goto label_80135610;
    }

label_801355F4:
    ctx->downcount -= 3;
    // 801355F4: li      r4, 4649
    ctx->gpr[4] = (u32)(s32)(4649);

label_801355F8:
    // 801355F8: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_801355FC:
    // 801355FC: bl      0x80046B00
    {
            ctx->lr = 0x80135600u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135600:
    ctx->downcount -= 4;
    // 80135600: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135604:
    // 80135604: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80135608:
    // 80135608: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8013560C:
    // 8013560C: bl      0x800362AC
    {
            ctx->lr = 0x80135610u;
            ctx->pc = 0x800362ACu;
            return;
    }

label_80135610:
    ctx->downcount -= 5;
    // 80135610: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80135614:
    // 80135614: srawi r5, r27, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[27];
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

label_80135618:
    // 80135618: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8013561C:
    // 8013561C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80135620:
    // 80135620: bl      0x800361A8
    {
            ctx->lr = 0x80135624u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_80135624:
    ctx->downcount -= 6;
    // 80135624: lis     r4, -32737
    ctx->gpr[4] = ((u32)(s32)(-32737) << 16);

label_80135628:
    // 80135628: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8013562C:
    // 8013562C: addi    r4, r4, 5844
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5844);

label_80135630:
    // 80135630: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80135634:
    // 80135634: li      r6, 4096
    ctx->gpr[6] = (u32)(s32)(4096);

label_80135638:
    // 80135638: bl      0x80036410
    {
            ctx->lr = 0x8013563Cu;
            ctx->pc = 0x80036410u;
            return;
    }

label_8013563C:
    ctx->pc = 0x8013563Cu;
    ctx->downcount -= 8;
    // 8013563C: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x8013563Cu)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_80135640:
    ctx->pc = 0x80135640u;
    // 80135640: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x80135640u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80135644:
    // 80135644: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80135648:
    ctx->pc = 0x80135648u;
    // 80135648: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80135648u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_8013564C:
    // 8013564C: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80135650:
    // 80135650: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_80135654:
    ctx->pc = 0x80135654u;
    // 80135654: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80135658:
    // 80135658: bl      0x80034E9C
    {
            ctx->lr = 0x8013565Cu;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8013565C:
    ctx->downcount -= 1;
    // 8013565C: b       0x801356A4
    {
            goto label_801356A4;
    }

label_80135660:
    ctx->downcount -= 1;
    // 80135660: li      r4, 4148
    ctx->gpr[4] = (u32)(s32)(4148);

label_80135664:
    ctx->downcount -= 2;
    // 80135664: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80135668:
    // 80135668: bl      0x80046B00
    {
            ctx->lr = 0x8013566Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8013566C:
    ctx->downcount -= 5;
    // 8013566C: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135670:
    // 80135670: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80135674:
    // 80135674: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_80135678:
    // 80135678: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_8013567C:
    // 8013567C: bl      0x80034E9C
    {
            ctx->lr = 0x80135680u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135680:
    ctx->downcount -= 1;
    // 80135680: b       0x801356A4
    {
            goto label_801356A4;
    }

label_80135684:
    ctx->downcount -= 3;
    // 80135684: li      r4, 3579
    ctx->gpr[4] = (u32)(s32)(3579);

label_80135688:
    // 80135688: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_8013568C:
    // 8013568C: bl      0x80046B00
    {
            ctx->lr = 0x80135690u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135690:
    ctx->downcount -= 5;
    // 80135690: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135694:
    // 80135694: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80135698:
    // 80135698: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_8013569C:
    // 8013569C: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_801356A0:
    // 801356A0: bl      0x80034E9C
    {
            ctx->lr = 0x801356A4u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801356A4:
    ctx->pc = 0x801356A4u;
    ctx->downcount -= 6;
    // 801356A4: lfs     f0, 5984(r22)
    if (!ppc_fp_available(ctx, 0x801356A4u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(5984);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801356A8:
    // 801356A8: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_801356AC:
    // 801356AC: addi    r31, r31, 8376
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(8376);

label_801356B0:
    // 801356B0: cmpwi   r26, 2
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801356B4:
    ctx->pc = 0x801356B4u;
    // 801356B4: fadds   f30, f30, f0
    if (!ppc_fp_available(ctx, 0x801356B4u)) return;
    ppc_fadds(ctx, 30, 30, 0);

label_801356B8:
    // 801356B8: bc    4, 1, 0x801354C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801354C8u;
                return;
            }
            goto label_801354C8;
        }
    }

label_801356BC:
    ctx->pc = 0x801356BCu;
    ctx->downcount -= 3;
    // 801356BC: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801356C0:
    ctx->pc = 0x801356C0u;
    // 801356C0: cmpw    r0, r26
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

label_801356C4:
    ctx->pc = 0x801356C4u;
    // 801356C4: bc    4, 2, 0x801356F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801356F4;
        }
    }

label_801356C8:
    ctx->pc = 0x801356C8u;
    ctx->downcount -= 3;
    // 801356C8: lwz     r0, -32364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32364);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801356CC:
    ctx->pc = 0x801356CCu;
    // 801356CC: andi.   r6, r0, 0x0010
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801356D0:
    ctx->pc = 0x801356D0u;
    // 801356D0: bc    12, 2, 0x801356E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801356E0;
        }
    }

label_801356D4:
    ctx->pc = 0x801356D4u;
    ctx->downcount -= 3;
    // 801356D4: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801356D8:
    ctx->pc = 0x801356D8u;
    // 801356D8: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801356DC:
    ctx->pc = 0x801356DCu;
    // 801356DC: b       0x801356E8
    {
            goto label_801356E8;
    }

label_801356E0:
    ctx->pc = 0x801356E0u;
    ctx->downcount -= 2;
    // 801356E0: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801356E4:
    ctx->pc = 0x801356E4u;
    // 801356E4: lis     r4, -256
    ctx->gpr[4] = ((u32)(s32)(-256) << 16);

label_801356E8:
    ctx->pc = 0x801356E8u;
    ctx->downcount -= 2;
    // 801356E8: addi    r3, r3, 11668
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(11668);

label_801356EC:
    ctx->pc = 0x801356ECu;
    // 801356EC: bl      0x80034BA8
    {
            ctx->lr = 0x801356F0u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801356F0:
    ctx->pc = 0x801356F0u;
    ctx->downcount -= 1;
    // 801356F0: b       0x80135708
    {
            goto label_80135708;
    }

label_801356F4:
    ctx->pc = 0x801356F4u;
    ctx->downcount -= 5;
    // 801356F4: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801356F8:
    ctx->pc = 0x801356F8u;
    // 801356F8: lis     r4, -36
    ctx->gpr[4] = ((u32)(s32)(-36) << 16);

label_801356FC:
    ctx->pc = 0x801356FCu;
    // 801356FC: addi    r3, r3, 11668
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(11668);

label_80135700:
    ctx->pc = 0x80135700u;
    // 80135700: ori     r4, r4, 0xC828
    ctx->gpr[4] = ctx->gpr[4] | 0xC828u;

label_80135704:
    ctx->pc = 0x80135704u;
    // 80135704: bl      0x80034BA8
    {
            ctx->lr = 0x80135708u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135708:
    ctx->pc = 0x80135708u;
    ctx->downcount -= 8;
    // 80135708: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80135708u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_8013570C:
    ctx->pc = 0x8013570Cu;
    // 8013570C: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8013570Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80135710:
    ctx->pc = 0x80135710u;
    // 80135710: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80135714:
    ctx->pc = 0x80135714u;
    // 80135714: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80135714u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80135718:
    ctx->pc = 0x80135718u;
    // 80135718: li      r4, 4157
    ctx->gpr[4] = (u32)(s32)(4157);

label_8013571C:
    ctx->pc = 0x8013571Cu;
    // 8013571C: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_80135720:
    ctx->pc = 0x80135720u;
    // 80135720: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80135724:
    ctx->pc = 0x80135724u;
    // 80135724: bl      0x80046B00
    {
            ctx->lr = 0x80135728u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135728:
    ctx->pc = 0x80135728u;
    ctx->downcount -= 6;
    // 80135728: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8013572C:
    ctx->pc = 0x8013572Cu;
    // 8013572C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80135730:
    ctx->pc = 0x80135730u;
    // 80135730: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80135734:
    ctx->pc = 0x80135734u;
    // 80135734: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80135738:
    ctx->pc = 0x80135738u;
    // 80135738: addi    r3, r3, 11668
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(11668);

label_8013573C:
    ctx->pc = 0x8013573Cu;
    // 8013573C: bl      0x80034E9C
    {
            ctx->lr = 0x80135740u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135740:
    ctx->pc = 0x80135740u;
    ctx->downcount -= 5;
    // 80135740: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135744:
    ctx->pc = 0x80135744u;
    // 80135744: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_80135748:
    ctx->pc = 0x80135748u;
    // 80135748: lfs     f1, 5920(r9)
    if (!ppc_fp_available(ctx, 0x80135748u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5920);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013574C:
    ctx->pc = 0x8013574Cu;
    // 8013574C: lfs     f2, 5924(r11)
    if (!ppc_fp_available(ctx, 0x8013574Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5924);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80135750:
    ctx->pc = 0x80135750u;
    // 80135750: bl      0x80133200
    {
            ctx->lr = 0x80135754u;
            ctx->pc = 0x80133200u;
            return;
    }

label_80135754:
    ctx->pc = 0x80135754u;
    ctx->downcount -= 1;
    // 80135754: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80135758:
    ctx->pc = 0x80135758u;
    ctx->downcount -= 5;
    // 80135758: lis     r29, -32697
    ctx->gpr[29] = ((u32)(s32)(-32697) << 16);

label_8013575C:
    ctx->pc = 0x8013575Cu;
    // 8013575C: li      r4, -171
    ctx->gpr[4] = (u32)(s32)(-171);

label_80135760:
    ctx->pc = 0x80135760u;
    // 80135760: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80135764:
    ctx->pc = 0x80135764u;
    // 80135764: lis     r28, -32737
    ctx->gpr[28] = ((u32)(s32)(-32737) << 16);

label_80135768:
    ctx->pc = 0x80135768u;
    // 80135768: bl      0x80034BA8
    {
            ctx->lr = 0x8013576Cu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8013576C:
    ctx->pc = 0x8013576Cu;
    ctx->downcount -= 4;
    // 8013576C: lis     r27, -32698
    ctx->gpr[27] = ((u32)(s32)(-32698) << 16);

label_80135770:
    ctx->pc = 0x80135770u;
    // 80135770: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80135774:
    ctx->pc = 0x80135774u;
    // 80135774: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80135778:
    ctx->pc = 0x80135778u;
    // 80135778: bl      0x80035C48
    {
            ctx->lr = 0x8013577Cu;
            ctx->pc = 0x80035C48u;
            return;
    }

label_8013577C:
    ctx->pc = 0x8013577Cu;
    ctx->downcount -= 7;
    // 8013577C: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_80135780:
    ctx->pc = 0x80135780u;
    // 80135780: lfs     f1, 5896(r28)
    if (!ppc_fp_available(ctx, 0x80135780u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135784:
    ctx->pc = 0x80135784u;
    // 80135784: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80135788:
    ctx->pc = 0x80135788u;
    // 80135788: lis     r24, -32698
    ctx->gpr[24] = ((u32)(s32)(-32698) << 16);

label_8013578C:
    ctx->pc = 0x8013578Cu;
    // 8013578C: lis     r23, -32698
    ctx->gpr[23] = ((u32)(s32)(-32698) << 16);

label_80135790:
    ctx->pc = 0x80135790u;
    // 80135790: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80135790u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135794:
    ctx->pc = 0x80135794u;
    // 80135794: bl      0x80034E6C
    {
            ctx->lr = 0x80135798u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80135798:
    ctx->pc = 0x80135798u;
    ctx->downcount -= 3;
    // 80135798: li      r4, 3569
    ctx->gpr[4] = (u32)(s32)(3569);

label_8013579C:
    ctx->pc = 0x8013579Cu;
    // 8013579C: addi    r3, r27, 9872
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(9872);

label_801357A0:
    ctx->pc = 0x801357A0u;
    // 801357A0: bl      0x80046B00
    {
            ctx->lr = 0x801357A4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801357A4:
    ctx->pc = 0x801357A4u;
    ctx->downcount -= 5;
    // 801357A4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801357A8:
    ctx->pc = 0x801357A8u;
    // 801357A8: li      r5, 70
    ctx->gpr[5] = (u32)(s32)(70);

label_801357AC:
    ctx->pc = 0x801357ACu;
    // 801357AC: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_801357B0:
    ctx->pc = 0x801357B0u;
    // 801357B0: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_801357B4:
    ctx->pc = 0x801357B4u;
    // 801357B4: bl      0x80034E9C
    {
            ctx->lr = 0x801357B8u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801357B8:
    ctx->pc = 0x801357B8u;
    ctx->downcount -= 4;
    // 801357B8: lis     r4, -49
    ctx->gpr[4] = ((u32)(s32)(-49) << 16);

label_801357BC:
    ctx->pc = 0x801357BCu;
    // 801357BC: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801357C0:
    ctx->pc = 0x801357C0u;
    // 801357C0: ori     r4, r4, 0xBF20
    ctx->gpr[4] = ctx->gpr[4] | 0xBF20u;

label_801357C4:
    ctx->pc = 0x801357C4u;
    // 801357C4: bl      0x80034BA8
    {
            ctx->lr = 0x801357C8u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801357C8:
    ctx->pc = 0x801357C8u;
    ctx->downcount -= 3;
    // 801357C8: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801357CC:
    ctx->pc = 0x801357CCu;
    // 801357CC: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801357D0:
    ctx->pc = 0x801357D0u;
    // 801357D0: bl      0x800353D4
    {
            ctx->lr = 0x801357D4u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_801357D4:
    ctx->pc = 0x801357D4u;
    ctx->downcount -= 3;
    // 801357D4: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801357D8:
    ctx->pc = 0x801357D8u;
    // 801357D8: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_801357DC:
    ctx->pc = 0x801357DCu;
    // 801357DC: bl      0x80035C48
    {
            ctx->lr = 0x801357E0u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_801357E0:
    ctx->pc = 0x801357E0u;
    ctx->downcount -= 4;
    // 801357E0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801357E4:
    ctx->pc = 0x801357E4u;
    // 801357E4: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801357E8:
    ctx->pc = 0x801357E8u;
    // 801357E8: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_801357EC:
    ctx->pc = 0x801357ECu;
    // 801357EC: bl      0x80035C50
    {
            ctx->lr = 0x801357F0u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_801357F0:
    ctx->pc = 0x801357F0u;
    ctx->downcount -= 3;
    // 801357F0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801357F4:
    ctx->pc = 0x801357F4u;
    // 801357F4: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_801357F8:
    ctx->pc = 0x801357F8u;
    // 801357F8: bl      0x80035C40
    {
            ctx->lr = 0x801357FCu;
            ctx->pc = 0x80035C40u;
            return;
    }

label_801357FC:
    ctx->pc = 0x801357FCu;
    ctx->downcount -= 4;
    // 801357FC: lfs     f1, 5896(r28)
    if (!ppc_fp_available(ctx, 0x801357FCu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135800:
    ctx->pc = 0x80135800u;
    // 80135800: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135804:
    ctx->pc = 0x80135804u;
    // 80135804: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80135804u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135808:
    ctx->pc = 0x80135808u;
    // 80135808: bl      0x80034E6C
    {
            ctx->lr = 0x8013580Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_8013580C:
    ctx->pc = 0x8013580Cu;
    ctx->downcount -= 6;
    // 8013580C: lwz     r4, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80135810:
    ctx->pc = 0x80135810u;
    // 80135810: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135814:
    ctx->pc = 0x80135814u;
    // 80135814: lfs     f30, 5988(r9)
    if (!ppc_fp_available(ctx, 0x80135814u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5988);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_80135818:
    ctx->pc = 0x80135818u;
    // 80135818: addi    r3, r27, 9872
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(9872);

label_8013581C:
    ctx->pc = 0x8013581Cu;
    // 8013581C: addi    r4, r4, 4183
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4183);

label_80135820:
    ctx->pc = 0x80135820u;
    // 80135820: bl      0x80046B00
    {
            ctx->lr = 0x80135824u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135824:
    ctx->pc = 0x80135824u;
    ctx->downcount -= 5;
    // 80135824: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135828:
    ctx->pc = 0x80135828u;
    // 80135828: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_8013582C:
    ctx->pc = 0x8013582Cu;
    // 8013582C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135830:
    ctx->pc = 0x80135830u;
    // 80135830: li      r5, 176
    ctx->gpr[5] = (u32)(s32)(176);

label_80135834:
    ctx->pc = 0x80135834u;
    // 80135834: bl      0x80034E9C
    {
            ctx->lr = 0x80135838u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135838:
    ctx->pc = 0x80135838u;
    ctx->downcount -= 9;
    // 80135838: lwz     r11, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8013583C:
    ctx->pc = 0x8013583Cu;
    // 8013583C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80135840:
    ctx->pc = 0x80135840u;
    // 80135840: addi    r31, r9, -13308
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-13308);

label_80135844:
    ctx->pc = 0x80135844u;
    // 80135844: mulli   r11, r11, 8376
    ctx->gpr[11] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)8376);

label_80135848:
    ctx->pc = 0x80135848u;
    // 80135848: lwzx    r0, r31, r11
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[11];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013584C:
    ctx->pc = 0x8013584Cu;
    // 8013584C: cmpwi   r0, 0
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

label_80135850:
    ctx->pc = 0x80135850u;
    // 80135850: bc    12, 2, 0x801359C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801359C0;
        }
    }

label_80135854:
    ctx->pc = 0x80135854u;
    ctx->downcount -= 4;
    // 80135854: addi    r9, r31, 4
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(4);

label_80135858:
    ctx->pc = 0x80135858u;
    // 80135858: lwzx    r0, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013585C:
    ctx->pc = 0x8013585Cu;
    // 8013585C: cmpwi   r0, 0
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

label_80135860:
    ctx->pc = 0x80135860u;
    // 80135860: bc    4, 2, 0x801359A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801359A0;
        }
    }

label_80135864:
    ctx->pc = 0x80135864u;
    ctx->downcount -= 5;
    // 80135864: addi    r30, r1, 24
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(24);

label_80135868:
    ctx->pc = 0x80135868u;
    // 80135868: addi    r29, r1, 2184
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(2184);

label_8013586C:
    ctx->pc = 0x8013586Cu;
    // 8013586C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80135870:
    ctx->pc = 0x80135870u;
    // 80135870: addi    r28, r31, 48
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(48);

label_80135874:
    ctx->pc = 0x80135874u;
    // 80135874: bl      0x80036150
    {
            ctx->lr = 0x80135878u;
            ctx->pc = 0x80036150u;
            return;
    }

label_80135878:
    ctx->pc = 0x80135878u;
    ctx->downcount -= 12;
    // 80135878: or   r25, r30, r30
    {
        ctx->gpr[25] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8013587C:
    ctx->pc = 0x8013587Cu;
    // 8013587C: lwz     r9, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80135880:
    ctx->pc = 0x80135880u;
    // 80135880: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80135884:
    ctx->pc = 0x80135884u;
    // 80135884: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80135888:
    ctx->pc = 0x80135888u;
    // 80135888: li      r5, 8192
    ctx->gpr[5] = (u32)(s32)(8192);

label_8013588C:
    ctx->pc = 0x8013588Cu;
    // 8013588C: mulli   r9, r9, 8376
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)8376);

label_80135890:
    ctx->pc = 0x80135890u;
    // 80135890: or   r30, r29, r29
    {
        ctx->gpr[30] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80135894:
    ctx->pc = 0x80135894u;
    // 80135894: add   r9, r9, r28
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80135898:
    ctx->pc = 0x80135898u;
    // 80135898: lwz     r27, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_8013589C:
    ctx->pc = 0x8013589Cu;
    // 8013589C: bl      0x801698F0
    {
            ctx->lr = 0x801358A0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801358A0:
    ctx->pc = 0x801358A0u;
    ctx->downcount -= 2;
    // 801358A0: cmpwi   r27, 1
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801358A4:
    ctx->pc = 0x801358A4u;
    // 801358A4: bc    12, 1, 0x801358DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801358DC;
        }
    }

label_801358A8:
    ctx->pc = 0x801358A8u;
    ctx->downcount -= 6;
    // 801358A8: lwz     r0, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801358AC:
    ctx->pc = 0x801358ACu;
    // 801358AC: mulli   r0, r0, 8376
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)8376);

label_801358B0:
    ctx->pc = 0x801358B0u;
    // 801358B0: lwzx    r3, r28, r0
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801358B4:
    ctx->pc = 0x801358B4u;
    // 801358B4: bl      0x80132D84
    {
            ctx->lr = 0x801358B8u;
            ctx->pc = 0x80132D84u;
            return;
    }

label_801358B8:
    ctx->pc = 0x801358B8u;
    ctx->downcount -= 3;
    // 801358B8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801358BC:
    ctx->pc = 0x801358BCu;
    // 801358BC: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_801358C0:
    ctx->pc = 0x801358C0u;
    // 801358C0: bl      0x80046B00
    {
            ctx->lr = 0x801358C4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801358C4:
    ctx->pc = 0x801358C4u;
    ctx->downcount -= 5;
    // 801358C4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801358C8:
    ctx->pc = 0x801358C8u;
    // 801358C8: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_801358CC:
    ctx->pc = 0x801358CCu;
    // 801358CC: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801358D0:
    ctx->pc = 0x801358D0u;
    // 801358D0: li      r5, 176
    ctx->gpr[5] = (u32)(s32)(176);

label_801358D4:
    ctx->pc = 0x801358D4u;
    // 801358D4: bl      0x80034E9C
    {
            ctx->lr = 0x801358D8u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801358D8:
    ctx->pc = 0x801358D8u;
    ctx->downcount -= 1;
    // 801358D8: b       0x801359C0
    {
            goto label_801359C0;
    }

label_801358DC:
    ctx->pc = 0x801358DCu;
    ctx->downcount -= 6;
    // 801358DC: lwz     r0, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801358E0:
    ctx->pc = 0x801358E0u;
    // 801358E0: mulli   r0, r0, 8376
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)8376);

label_801358E4:
    ctx->pc = 0x801358E4u;
    // 801358E4: lwzx    r3, r28, r0
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801358E8:
    ctx->pc = 0x801358E8u;
    // 801358E8: bl      0x80132D84
    {
            ctx->lr = 0x801358ECu;
            ctx->pc = 0x80132D84u;
            return;
    }

label_801358EC:
    ctx->pc = 0x801358ECu;
    ctx->downcount -= 3;
    // 801358EC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801358F0:
    ctx->pc = 0x801358F0u;
    // 801358F0: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_801358F4:
    ctx->pc = 0x801358F4u;
    // 801358F4: bl      0x80046B00
    {
            ctx->lr = 0x801358F8u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801358F8:
    ctx->pc = 0x801358F8u;
    ctx->downcount -= 4;
    // 801358F8: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801358FC:
    ctx->pc = 0x801358FCu;
    // 801358FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80135900:
    ctx->pc = 0x80135900u;
    // 80135900: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80135904:
    ctx->pc = 0x80135904u;
    // 80135904: bl      0x800362AC
    {
            ctx->lr = 0x80135908u;
            ctx->pc = 0x800362ACu;
            return;
    }

label_80135908:
    ctx->pc = 0x80135908u;
    ctx->downcount -= 2;
    // 80135908: andi.   r0, r27, 0x0001
    {
        ctx->gpr[0] = ctx->gpr[27] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8013590C:
    ctx->pc = 0x8013590Cu;
    // 8013590C: bc    4, 2, 0x80135930
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135930;
        }
    }

label_80135910:
    ctx->pc = 0x80135910u;
    ctx->downcount -= 3;
    // 80135910: li      r4, 4648
    ctx->gpr[4] = (u32)(s32)(4648);

label_80135914:
    ctx->pc = 0x80135914u;
    // 80135914: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80135918:
    ctx->pc = 0x80135918u;
    // 80135918: bl      0x80046B00
    {
            ctx->lr = 0x8013591Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8013591C:
    ctx->pc = 0x8013591Cu;
    ctx->downcount -= 4;
    // 8013591C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135920:
    ctx->pc = 0x80135920u;
    // 80135920: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80135924:
    ctx->pc = 0x80135924u;
    // 80135924: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80135928:
    ctx->pc = 0x80135928u;
    // 80135928: bl      0x800362AC
    {
            ctx->lr = 0x8013592Cu;
            ctx->pc = 0x800362ACu;
            return;
    }

label_8013592C:
    ctx->pc = 0x8013592Cu;
    ctx->downcount -= 1;
    // 8013592C: b       0x8013594C
    {
            goto label_8013594C;
    }

label_80135930:
    ctx->pc = 0x80135930u;
    ctx->downcount -= 3;
    // 80135930: li      r4, 4649
    ctx->gpr[4] = (u32)(s32)(4649);

label_80135934:
    ctx->pc = 0x80135934u;
    // 80135934: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_80135938:
    ctx->pc = 0x80135938u;
    // 80135938: bl      0x80046B00
    {
            ctx->lr = 0x8013593Cu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8013593C:
    ctx->pc = 0x8013593Cu;
    ctx->downcount -= 4;
    // 8013593C: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135940:
    ctx->pc = 0x80135940u;
    // 80135940: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80135944:
    ctx->pc = 0x80135944u;
    // 80135944: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80135948:
    ctx->pc = 0x80135948u;
    // 80135948: bl      0x800362AC
    {
            ctx->lr = 0x8013594Cu;
            ctx->pc = 0x800362ACu;
            return;
    }

label_8013594C:
    ctx->pc = 0x8013594Cu;
    ctx->downcount -= 5;
    // 8013594C: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80135950:
    ctx->pc = 0x80135950u;
    // 80135950: srawi r5, r27, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[27];
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

label_80135954:
    ctx->pc = 0x80135954u;
    // 80135954: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80135958:
    ctx->pc = 0x80135958u;
    // 80135958: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8013595C:
    ctx->pc = 0x8013595Cu;
    // 8013595C: bl      0x800361A8
    {
            ctx->lr = 0x80135960u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_80135960:
    ctx->pc = 0x80135960u;
    ctx->downcount -= 6;
    // 80135960: lis     r4, -32737
    ctx->gpr[4] = ((u32)(s32)(-32737) << 16);

label_80135964:
    ctx->pc = 0x80135964u;
    // 80135964: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80135968:
    ctx->pc = 0x80135968u;
    // 80135968: addi    r4, r4, 5844
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5844);

label_8013596C:
    ctx->pc = 0x8013596Cu;
    // 8013596C: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80135970:
    ctx->pc = 0x80135970u;
    // 80135970: li      r6, 4096
    ctx->gpr[6] = (u32)(s32)(4096);

label_80135974:
    ctx->pc = 0x80135974u;
    // 80135974: bl      0x80036410
    {
            ctx->lr = 0x80135978u;
            ctx->pc = 0x80036410u;
            return;
    }

label_80135978:
    ctx->pc = 0x80135978u;
    ctx->downcount -= 9;
    // 80135978: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x80135978u)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_8013597C:
    ctx->pc = 0x8013597Cu;
    // 8013597C: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8013597Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80135980:
    ctx->pc = 0x80135980u;
    // 80135980: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_80135984:
    ctx->pc = 0x80135984u;
    // 80135984: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80135984u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80135988:
    ctx->pc = 0x80135988u;
    // 80135988: addi    r3, r3, 11668
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(11668);

label_8013598C:
    ctx->pc = 0x8013598Cu;
    // 8013598C: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80135990:
    ctx->pc = 0x80135990u;
    // 80135990: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_80135994:
    ctx->pc = 0x80135994u;
    // 80135994: lwz     r5, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80135998:
    ctx->pc = 0x80135998u;
    // 80135998: bl      0x80034E9C
    {
            ctx->lr = 0x8013599Cu;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8013599C:
    ctx->pc = 0x8013599Cu;
    ctx->downcount -= 1;
    // 8013599C: b       0x801359C0
    {
            goto label_801359C0;
    }

label_801359A0:
    ctx->pc = 0x801359A0u;
    ctx->downcount -= 3;
    // 801359A0: li      r4, 4148
    ctx->gpr[4] = (u32)(s32)(4148);

label_801359A4:
    ctx->pc = 0x801359A4u;
    // 801359A4: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_801359A8:
    ctx->pc = 0x801359A8u;
    // 801359A8: bl      0x80046B00
    {
            ctx->lr = 0x801359ACu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801359AC:
    ctx->pc = 0x801359ACu;
    ctx->downcount -= 5;
    // 801359AC: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801359B0:
    ctx->pc = 0x801359B0u;
    // 801359B0: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_801359B4:
    ctx->pc = 0x801359B4u;
    // 801359B4: addi    r3, r24, 11668
    ctx->gpr[3] = ctx->gpr[24] + (u32)(s32)(11668);

label_801359B8:
    ctx->pc = 0x801359B8u;
    // 801359B8: li      r5, 176
    ctx->gpr[5] = (u32)(s32)(176);

label_801359BC:
    ctx->pc = 0x801359BCu;
    // 801359BC: bl      0x80034E9C
    {
            ctx->lr = 0x801359C0u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_801359C0:
    ctx->pc = 0x801359C0u;
    ctx->downcount -= 7;
    // 801359C0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801359C4:
    ctx->pc = 0x801359C4u;
    // 801359C4: lis     r29, -32698
    ctx->gpr[29] = ((u32)(s32)(-32698) << 16);

label_801359C8:
    ctx->pc = 0x801359C8u;
    // 801359C8: lfs     f0, 5992(r9)
    if (!ppc_fp_available(ctx, 0x801359C8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5992);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_801359CC:
    ctx->pc = 0x801359CCu;
    // 801359CC: addi    r3, r29, 11668
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(11668);

label_801359D0:
    ctx->pc = 0x801359D0u;
    // 801359D0: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_801359D4:
    ctx->pc = 0x801359D4u;
    // 801359D4: fadds   f30, f30, f0
    if (!ppc_fp_available(ctx, 0x801359D4u)) return;
    ppc_fadds(ctx, 30, 30, 0);

label_801359D8:
    ctx->pc = 0x801359D8u;
    // 801359D8: bl      0x80034BA8
    {
            ctx->lr = 0x801359DCu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_801359DC:
    ctx->pc = 0x801359DCu;
    ctx->downcount -= 8;
    // 801359DC: fmr    f0, f30
    if (!ppc_fp_available(ctx, 0x801359DCu)) return;
    ctx->fpr[0] = ctx->fpr[30];

label_801359E0:
    ctx->pc = 0x801359E0u;
    // 801359E0: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x801359E0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_801359E4:
    ctx->pc = 0x801359E4u;
    // 801359E4: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_801359E8:
    ctx->pc = 0x801359E8u;
    // 801359E8: stfd     f13, 18568(r1)
    if (!ppc_fp_available(ctx, 0x801359E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_801359EC:
    ctx->pc = 0x801359ECu;
    // 801359EC: li      r4, 4155
    ctx->gpr[4] = (u32)(s32)(4155);

label_801359F0:
    ctx->pc = 0x801359F0u;
    // 801359F0: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_801359F4:
    ctx->pc = 0x801359F4u;
    // 801359F4: lwz     r30, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801359F8:
    ctx->pc = 0x801359F8u;
    // 801359F8: bl      0x80046B00
    {
            ctx->lr = 0x801359FCu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_801359FC:
    ctx->pc = 0x801359FCu;
    ctx->downcount -= 5;
    // 801359FC: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135A00:
    ctx->pc = 0x80135A00u;
    // 80135A00: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80135A04:
    ctx->pc = 0x80135A04u;
    // 80135A04: addi    r3, r29, 11668
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(11668);

label_80135A08:
    ctx->pc = 0x80135A08u;
    // 80135A08: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_80135A0C:
    ctx->pc = 0x80135A0Cu;
    // 80135A0C: b       0x80135B04
    {
            goto label_80135B04;
    }

label_80135A10:
    ctx->pc = 0x80135A10u;
    ctx->downcount -= 5;
    // 80135A10: lis     r29, -32697
    ctx->gpr[29] = ((u32)(s32)(-32697) << 16);

label_80135A14:
    ctx->pc = 0x80135A14u;
    // 80135A14: li      r4, -171
    ctx->gpr[4] = (u32)(s32)(-171);

label_80135A18:
    ctx->pc = 0x80135A18u;
    // 80135A18: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80135A1C:
    ctx->pc = 0x80135A1Cu;
    // 80135A1C: lis     r28, -32698
    ctx->gpr[28] = ((u32)(s32)(-32698) << 16);

label_80135A20:
    ctx->pc = 0x80135A20u;
    // 80135A20: bl      0x80034BA8
    {
            ctx->lr = 0x80135A24u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135A24:
    ctx->pc = 0x80135A24u;
    ctx->downcount -= 4;
    // 80135A24: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_80135A28:
    ctx->pc = 0x80135A28u;
    // 80135A28: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80135A2C:
    ctx->pc = 0x80135A2Cu;
    // 80135A2C: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80135A30:
    ctx->pc = 0x80135A30u;
    // 80135A30: bl      0x80035C48
    {
            ctx->lr = 0x80135A34u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80135A34:
    ctx->pc = 0x80135A34u;
    ctx->downcount -= 5;
    // 80135A34: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135A38:
    ctx->pc = 0x80135A38u;
    // 80135A38: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80135A3C:
    ctx->pc = 0x80135A3Cu;
    // 80135A3C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80135A3Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135A40:
    ctx->pc = 0x80135A40u;
    // 80135A40: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80135A40u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135A44:
    ctx->pc = 0x80135A44u;
    // 80135A44: bl      0x80034E6C
    {
            ctx->lr = 0x80135A48u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80135A48:
    ctx->pc = 0x80135A48u;
    ctx->downcount -= 3;
    // 80135A48: li      r4, 3569
    ctx->gpr[4] = (u32)(s32)(3569);

label_80135A4C:
    ctx->pc = 0x80135A4Cu;
    // 80135A4C: addi    r3, r28, 9872
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(9872);

label_80135A50:
    ctx->pc = 0x80135A50u;
    // 80135A50: bl      0x80046B00
    {
            ctx->lr = 0x80135A54u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135A54:
    ctx->pc = 0x80135A54u;
    ctx->downcount -= 5;
    // 80135A54: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135A58:
    ctx->pc = 0x80135A58u;
    // 80135A58: li      r5, 70
    ctx->gpr[5] = (u32)(s32)(70);

label_80135A5C:
    ctx->pc = 0x80135A5Cu;
    // 80135A5C: addi    r3, r29, -19280
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-19280);

label_80135A60:
    ctx->pc = 0x80135A60u;
    // 80135A60: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_80135A64:
    ctx->pc = 0x80135A64u;
    // 80135A64: bl      0x80034E9C
    {
            ctx->lr = 0x80135A68u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_80135A68:
    ctx->pc = 0x80135A68u;
    ctx->downcount -= 3;
    // 80135A68: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135A6C:
    ctx->pc = 0x80135A6Cu;
    // 80135A6C: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80135A70:
    ctx->pc = 0x80135A70u;
    // 80135A70: bl      0x80034BA8
    {
            ctx->lr = 0x80135A74u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135A74:
    ctx->pc = 0x80135A74u;
    ctx->downcount -= 3;
    // 80135A74: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135A78:
    ctx->pc = 0x80135A78u;
    // 80135A78: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80135A7C:
    ctx->pc = 0x80135A7Cu;
    // 80135A7C: bl      0x800353D4
    {
            ctx->lr = 0x80135A80u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_80135A80:
    ctx->pc = 0x80135A80u;
    ctx->downcount -= 3;
    // 80135A80: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135A84:
    ctx->pc = 0x80135A84u;
    // 80135A84: lis     r4, -17664
    ctx->gpr[4] = ((u32)(s32)(-17664) << 16);

label_80135A88:
    ctx->pc = 0x80135A88u;
    // 80135A88: bl      0x80035C48
    {
            ctx->lr = 0x80135A8Cu;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80135A8C:
    ctx->pc = 0x80135A8Cu;
    ctx->downcount -= 4;
    // 80135A8C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80135A90:
    ctx->pc = 0x80135A90u;
    // 80135A90: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135A94:
    ctx->pc = 0x80135A94u;
    // 80135A94: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80135A98:
    ctx->pc = 0x80135A98u;
    // 80135A98: bl      0x80035C50
    {
            ctx->lr = 0x80135A9Cu;
            ctx->pc = 0x80035C50u;
            return;
    }

label_80135A9C:
    ctx->pc = 0x80135A9Cu;
    ctx->downcount -= 3;
    // 80135A9C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80135AA0:
    ctx->pc = 0x80135AA0u;
    // 80135AA0: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135AA4:
    ctx->pc = 0x80135AA4u;
    // 80135AA4: bl      0x80035C40
    {
            ctx->lr = 0x80135AA8u;
            ctx->pc = 0x80035C40u;
            return;
    }

label_80135AA8:
    ctx->pc = 0x80135AA8u;
    ctx->downcount -= 5;
    // 80135AA8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135AAC:
    ctx->pc = 0x80135AACu;
    // 80135AAC: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135AB0:
    ctx->pc = 0x80135AB0u;
    // 80135AB0: lfs     f1, 6000(r9)
    if (!ppc_fp_available(ctx, 0x80135AB0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6000);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135AB4:
    ctx->pc = 0x80135AB4u;
    // 80135AB4: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80135AB4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135AB8:
    ctx->pc = 0x80135AB8u;
    // 80135AB8: bl      0x80034E6C
    {
            ctx->lr = 0x80135ABCu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80135ABC:
    ctx->pc = 0x80135ABCu;
    ctx->downcount -= 3;
    // 80135ABC: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135AC0:
    ctx->pc = 0x80135AC0u;
    // 80135AC0: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80135AC4:
    ctx->pc = 0x80135AC4u;
    // 80135AC4: bl      0x80034BA8
    {
            ctx->lr = 0x80135AC8u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135AC8:
    ctx->pc = 0x80135AC8u;
    ctx->downcount -= 3;
    // 80135AC8: li      r4, 4201
    ctx->gpr[4] = (u32)(s32)(4201);

label_80135ACC:
    ctx->pc = 0x80135ACCu;
    // 80135ACC: addi    r3, r28, 9872
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(9872);

label_80135AD0:
    ctx->pc = 0x80135AD0u;
    // 80135AD0: bl      0x80046B00
    {
            ctx->lr = 0x80135AD4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135AD4:
    ctx->pc = 0x80135AD4u;
    ctx->downcount -= 5;
    // 80135AD4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135AD8:
    ctx->pc = 0x80135AD8u;
    // 80135AD8: li      r5, 176
    ctx->gpr[5] = (u32)(s32)(176);

label_80135ADC:
    ctx->pc = 0x80135ADCu;
    // 80135ADC: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135AE0:
    ctx->pc = 0x80135AE0u;
    // 80135AE0: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_80135AE4:
    ctx->pc = 0x80135AE4u;
    // 80135AE4: bl      0x80034F4C
    {
            ctx->lr = 0x80135AE8u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_80135AE8:
    ctx->pc = 0x80135AE8u;
    ctx->downcount -= 3;
    // 80135AE8: li      r4, 4659
    ctx->gpr[4] = (u32)(s32)(4659);

label_80135AEC:
    ctx->pc = 0x80135AECu;
    // 80135AEC: addi    r3, r28, 9872
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(9872);

label_80135AF0:
    ctx->pc = 0x80135AF0u;
    // 80135AF0: bl      0x80046B00
    {
            ctx->lr = 0x80135AF4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_80135AF4:
    ctx->pc = 0x80135AF4u;
    ctx->downcount -= 4;
    // 80135AF4: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80135AF8:
    ctx->pc = 0x80135AF8u;
    // 80135AF8: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_80135AFC:
    ctx->pc = 0x80135AFCu;
    // 80135AFC: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135B00:
    ctx->pc = 0x80135B00u;
    // 80135B00: li      r5, 261
    ctx->gpr[5] = (u32)(s32)(261);

label_80135B04:
    ctx->pc = 0x80135B04u;
    ctx->downcount -= 1;
    // 80135B04: bl      0x80034F4C
    {
            ctx->lr = 0x80135B08u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_80135B08:
    ctx->pc = 0x80135B08u;
    ctx->downcount -= 5;
    // 80135B08: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135B0C:
    ctx->pc = 0x80135B0Cu;
    // 80135B0C: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_80135B10:
    ctx->pc = 0x80135B10u;
    // 80135B10: lfs     f1, 5920(r9)
    if (!ppc_fp_available(ctx, 0x80135B10u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5920);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135B14:
    ctx->pc = 0x80135B14u;
    // 80135B14: lfs     f2, 5924(r11)
    if (!ppc_fp_available(ctx, 0x80135B14u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(5924);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80135B18:
    ctx->pc = 0x80135B18u;
    // 80135B18: bl      0x8013372C
    {
            ctx->lr = 0x80135B1Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013372Cu;
                return;
            }
            goto label_8013372C;
    }

label_80135B1C:
    ctx->pc = 0x80135B1Cu;
    ctx->downcount -= 1;
    // 80135B1C: b       0x80135BF0
    {
            goto label_80135BF0;
    }

label_80135B20:
    ctx->pc = 0x80135B20u;
    ctx->downcount -= 5;
    // 80135B20: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_80135B24:
    ctx->pc = 0x80135B24u;
    // 80135B24: li      r4, -171
    ctx->gpr[4] = (u32)(s32)(-171);

label_80135B28:
    ctx->pc = 0x80135B28u;
    // 80135B28: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135B2C:
    ctx->pc = 0x80135B2Cu;
    // 80135B2C: lis     r29, -32737
    ctx->gpr[29] = ((u32)(s32)(-32737) << 16);

label_80135B30:
    ctx->pc = 0x80135B30u;
    // 80135B30: bl      0x80034BA8
    {
            ctx->lr = 0x80135B34u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_80135B34:
    ctx->pc = 0x80135B34u;
    ctx->downcount -= 3;
    // 80135B34: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135B38:
    ctx->pc = 0x80135B38u;
    // 80135B38: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80135B3C:
    ctx->pc = 0x80135B3Cu;
    // 80135B3C: bl      0x800353D4
    {
            ctx->lr = 0x80135B40u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_80135B40:
    ctx->pc = 0x80135B40u;
    ctx->downcount -= 4;
    // 80135B40: lis     r4, -30688
    ctx->gpr[4] = ((u32)(s32)(-30688) << 16);

label_80135B44:
    ctx->pc = 0x80135B44u;
    // 80135B44: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135B48:
    ctx->pc = 0x80135B48u;
    // 80135B48: ori     r4, r4, 0x2000
    ctx->gpr[4] = ctx->gpr[4] | 0x2000u;

label_80135B4C:
    ctx->pc = 0x80135B4Cu;
    // 80135B4C: bl      0x80035C48
    {
            ctx->lr = 0x80135B50u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_80135B50:
    ctx->pc = 0x80135B50u;
    ctx->downcount -= 4;
    // 80135B50: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80135B54:
    ctx->pc = 0x80135B54u;
    // 80135B54: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135B58:
    ctx->pc = 0x80135B58u;
    // 80135B58: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80135B5C:
    ctx->pc = 0x80135B5Cu;
    // 80135B5C: bl      0x80035C50
    {
            ctx->lr = 0x80135B60u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_80135B60:
    ctx->pc = 0x80135B60u;
    ctx->downcount -= 3;
    // 80135B60: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80135B64:
    ctx->pc = 0x80135B64u;
    // 80135B64: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135B68:
    ctx->pc = 0x80135B68u;
    // 80135B68: bl      0x80035C40
    {
            ctx->lr = 0x80135B6Cu;
            ctx->pc = 0x80035C40u;
            return;
    }

label_80135B6C:
    ctx->pc = 0x80135B6Cu;
    ctx->downcount -= 4;
    // 80135B6C: lfs     f1, 5896(r29)
    if (!ppc_fp_available(ctx, 0x80135B6Cu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135B70:
    ctx->pc = 0x80135B70u;
    // 80135B70: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135B74:
    ctx->pc = 0x80135B74u;
    // 80135B74: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80135B74u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135B78:
    ctx->pc = 0x80135B78u;
    // 80135B78: bl      0x80034E6C
    {
            ctx->lr = 0x80135B7Cu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80135B7C:
    ctx->pc = 0x80135B7Cu;
    ctx->downcount -= 7;
    // 80135B7C: lis     r6, -32737
    ctx->gpr[6] = ((u32)(s32)(-32737) << 16);

label_80135B80:
    ctx->pc = 0x80135B80u;
    // 80135B80: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135B84:
    ctx->pc = 0x80135B84u;
    // 80135B84: addi    r6, r6, 5856
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(5856);

label_80135B88:
    ctx->pc = 0x80135B88u;
    // 80135B88: li      r4, 100
    ctx->gpr[4] = (u32)(s32)(100);

label_80135B8C:
    ctx->pc = 0x80135B8Cu;
    // 80135B8C: li      r5, 30
    ctx->gpr[5] = (u32)(s32)(30);

label_80135B90:
    ctx->pc = 0x80135B90u;
    // 80135B90: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80135B94:
    ctx->pc = 0x80135B94u;
    // 80135B94: bl      0x800350B4
    {
            ctx->lr = 0x80135B98u;
            ctx->pc = 0x800350B4u;
            return;
    }

label_80135B98:
    ctx->pc = 0x80135B98u;
    ctx->downcount -= 7;
    // 80135B98: lis     r6, -32737
    ctx->gpr[6] = ((u32)(s32)(-32737) << 16);

label_80135B9C:
    ctx->pc = 0x80135B9Cu;
    // 80135B9C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135BA0:
    ctx->pc = 0x80135BA0u;
    // 80135BA0: addi    r6, r6, 5872
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(5872);

label_80135BA4:
    ctx->pc = 0x80135BA4u;
    // 80135BA4: li      r4, 100
    ctx->gpr[4] = (u32)(s32)(100);

label_80135BA8:
    ctx->pc = 0x80135BA8u;
    // 80135BA8: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_80135BAC:
    ctx->pc = 0x80135BACu;
    // 80135BAC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80135BB0:
    ctx->pc = 0x80135BB0u;
    // 80135BB0: bl      0x800350B4
    {
            ctx->lr = 0x80135BB4u;
            ctx->pc = 0x800350B4u;
            return;
    }

label_80135BB4:
    ctx->pc = 0x80135BB4u;
    ctx->downcount -= 7;
    // 80135BB4: lis     r6, -32737
    ctx->gpr[6] = ((u32)(s32)(-32737) << 16);

label_80135BB8:
    ctx->pc = 0x80135BB8u;
    // 80135BB8: li      r4, 250
    ctx->gpr[4] = (u32)(s32)(250);

label_80135BBC:
    ctx->pc = 0x80135BBCu;
    // 80135BBC: addi    r6, r6, 5884
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(5884);

label_80135BC0:
    ctx->pc = 0x80135BC0u;
    // 80135BC0: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_80135BC4:
    ctx->pc = 0x80135BC4u;
    // 80135BC4: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135BC8:
    ctx->pc = 0x80135BC8u;
    // 80135BC8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80135BCC:
    ctx->pc = 0x80135BCCu;
    // 80135BCC: bl      0x800350B4
    {
            ctx->lr = 0x80135BD0u;
            ctx->pc = 0x800350B4u;
            return;
    }

label_80135BD0:
    ctx->pc = 0x80135BD0u;
    ctx->downcount -= 4;
    // 80135BD0: lfs     f1, 5896(r29)
    if (!ppc_fp_available(ctx, 0x80135BD0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135BD4:
    ctx->pc = 0x80135BD4u;
    // 80135BD4: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_80135BD8:
    ctx->pc = 0x80135BD8u;
    // 80135BD8: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80135BD8u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80135BDC:
    ctx->pc = 0x80135BDCu;
    // 80135BDC: bl      0x80034E6C
    {
            ctx->lr = 0x80135BE0u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_80135BE0:
    ctx->pc = 0x80135BE0u;
    ctx->downcount -= 1;
    // 80135BE0: bl      0x8005EC74
    {
            ctx->lr = 0x80135BE4u;
            ctx->pc = 0x8005EC74u;
            return;
    }

label_80135BE4:
    ctx->pc = 0x80135BE4u;
    ctx->downcount -= 2;
    // 80135BE4: cmpwi   r3, 0
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

label_80135BE8:
    ctx->pc = 0x80135BE8u;
    // 80135BE8: bc    12, 2, 0x80135BF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135BF0;
        }
    }

label_80135BEC:
    ctx->pc = 0x80135BECu;
    ctx->downcount -= 1;
    // 80135BEC: bl      0x8005F3C0
    {
            ctx->lr = 0x80135BF0u;
            ctx->pc = 0x8005F3C0u;
            return;
    }

label_80135BF0:
    ctx->pc = 0x80135BF0u;
    ctx->downcount -= 4;
    // 80135BF0: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80135BF4:
    ctx->pc = 0x80135BF4u;
    // 80135BF4: lha     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80135BF8:
    ctx->pc = 0x80135BF8u;
    // 80135BF8: cmpwi   r0, 14
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

label_80135BFC:
    ctx->pc = 0x80135BFCu;
    // 80135BFC: bc    12, 2, 0x80135C90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135C90;
        }
    }

label_80135C00:
    ctx->pc = 0x80135C00u;
    ctx->downcount -= 3;
    // 80135C00: lwz     r9, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80135C04:
    ctx->pc = 0x80135C04u;
    // 80135C04: cmpwi   r9, 0
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

label_80135C08:
    ctx->pc = 0x80135C08u;
    // 80135C08: bc    4, 1, 0x80135C20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135C20;
        }
    }

label_80135C0C:
    ctx->pc = 0x80135C0Cu;
    ctx->downcount -= 4;
    // 80135C0C: addi    r0, r9, -1
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-1);

label_80135C10:
    ctx->pc = 0x80135C10u;
    // 80135C10: cmpwi   r0, 0
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

label_80135C14:
    ctx->pc = 0x80135C14u;
    // 80135C14: stw     r0, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135C18:
    ctx->pc = 0x80135C18u;
    // 80135C18: bc    4, 2, 0x80135C20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135C20;
        }
    }

label_80135C1C:
    ctx->pc = 0x80135C1Cu;
    ctx->downcount -= 1;
    // 80135C1C: li      r20, 1
    ctx->gpr[20] = (u32)(s32)(1);

label_80135C20:
    ctx->pc = 0x80135C20u;
    ctx->downcount -= 27;
    // 80135C20: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80135C24:
    ctx->pc = 0x80135C24u;
    // 80135C24: lwz     r5, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80135C28:
    ctx->pc = 0x80135C28u;
    // 80135C28: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80135C2C:
    ctx->pc = 0x80135C2Cu;
    // 80135C2C: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80135C30:
    ctx->pc = 0x80135C30u;
    // 80135C30: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135C34:
    ctx->pc = 0x80135C34u;
    // 80135C34: lwz     r4, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80135C38:
    ctx->pc = 0x80135C38u;
    // 80135C38: and   r3, r11, r5
    {
        ctx->gpr[3] = ctx->gpr[11] & ctx->gpr[5];
    }

label_80135C3C:
    ctx->pc = 0x80135C3Cu;
    // 80135C3C: lwz     r7, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80135C40:
    ctx->pc = 0x80135C40u;
    // 80135C40: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_80135C44:
    ctx->pc = 0x80135C44u;
    // 80135C44: lwz     r10, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80135C48:
    ctx->pc = 0x80135C48u;
    // 80135C48: and   r30, r4, r5
    {
        ctx->gpr[30] = ctx->gpr[4] & ctx->gpr[5];
    }

label_80135C4C:
    ctx->pc = 0x80135C4Cu;
    // 80135C4C: lwz     r8, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80135C50:
    ctx->pc = 0x80135C50u;
    // 80135C50: and   r0, r0, r3
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[3];
    }

label_80135C54:
    ctx->pc = 0x80135C54u;
    // 80135C54: lwz     r6, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80135C58:
    ctx->pc = 0x80135C58u;
    // 80135C58: xor   r10, r10, r4
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[4];
    }

label_80135C5C:
    ctx->pc = 0x80135C5Cu;
    // 80135C5C: lwz     r11, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80135C60:
    ctx->pc = 0x80135C60u;
    // 80135C60: xor   r8, r8, r7
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[7];
    }

label_80135C64:
    ctx->pc = 0x80135C64u;
    // 80135C64: and   r10, r10, r30
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[30];
    }

label_80135C68:
    ctx->pc = 0x80135C68u;
    // 80135C68: and   r7, r7, r5
    {
        ctx->gpr[7] = ctx->gpr[7] & ctx->gpr[5];
    }

label_80135C6C:
    ctx->pc = 0x80135C6Cu;
    // 80135C6C: xor   r11, r11, r6
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[6];
    }

label_80135C70:
    ctx->pc = 0x80135C70u;
    // 80135C70: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_80135C74:
    ctx->pc = 0x80135C74u;
    // 80135C74: and   r6, r6, r5
    {
        ctx->gpr[6] = ctx->gpr[6] & ctx->gpr[5];
    }

label_80135C78:
    ctx->pc = 0x80135C78u;
    // 80135C78: and   r8, r8, r7
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[7];
    }

label_80135C7C:
    ctx->pc = 0x80135C7Cu;
    // 80135C7C: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_80135C80:
    ctx->pc = 0x80135C80u;
    // 80135C80: and   r11, r11, r6
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[6];
    }

label_80135C84:
    ctx->pc = 0x80135C84u;
    // 80135C84: or.   r6, r0, r11
    {
        ctx->gpr[6] = ctx->gpr[0] | ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80135C88:
    ctx->pc = 0x80135C88u;
    // 80135C88: bc    12, 2, 0x80135C90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135C90;
        }
    }

label_80135C8C:
    ctx->pc = 0x80135C8Cu;
    ctx->downcount -= 1;
    // 80135C8C: li      r20, 1
    ctx->gpr[20] = (u32)(s32)(1);

label_80135C90:
    ctx->pc = 0x80135C90u;
    ctx->downcount -= 5;
    // 80135C90: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80135C94:
    ctx->pc = 0x80135C94u;
    // 80135C94: addi    r29, r9, -21636
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-21636);

label_80135C98:
    ctx->pc = 0x80135C98u;
    // 80135C98: lha     r31, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        ctx->gpr[31] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80135C9C:
    ctx->pc = 0x80135C9Cu;
    // 80135C9C: cmpwi   r31, 10
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135CA0:
    ctx->pc = 0x80135CA0u;
    // 80135CA0: bc    12, 2, 0x801360D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801360D0;
        }
    }

label_80135CA4:
    ctx->pc = 0x80135CA4u;
    ctx->downcount -= 1;
    // 80135CA4: bc    12, 1, 0x80135CDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135CDC;
        }
    }

label_80135CA8:
    ctx->pc = 0x80135CA8u;
    ctx->downcount -= 2;
    // 80135CA8: cmpwi   r31, 7
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135CAC:
    ctx->pc = 0x80135CACu;
    // 80135CAC: bc    12, 2, 0x80135DE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135DE8;
        }
    }

label_80135CB0:
    ctx->pc = 0x80135CB0u;
    ctx->downcount -= 1;
    // 80135CB0: bc    12, 1, 0x80135CC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135CC8;
        }
    }

label_80135CB4:
    ctx->pc = 0x80135CB4u;
    ctx->downcount -= 2;
    // 80135CB4: cmpwi   r31, 0
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

label_80135CB8:
    ctx->pc = 0x80135CB8u;
    // 80135CB8: bc    12, 2, 0x80136ADC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136ADC;
        }
    }

label_80135CBC:
    ctx->pc = 0x80135CBCu;
    ctx->downcount -= 2;
    // 80135CBC: cmpwi   r31, 5
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135CC0:
    ctx->pc = 0x80135CC0u;
    // 80135CC0: bc    12, 2, 0x80135D20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135D20;
        }
    }

label_80135CC4:
    ctx->pc = 0x80135CC4u;
    ctx->downcount -= 1;
    // 80135CC4: b       0x80136D78
    {
            goto label_80136D78;
    }

label_80135CC8:
    ctx->pc = 0x80135CC8u;
    ctx->downcount -= 2;
    // 80135CC8: cmpwi   r31, 8
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(8);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135CCC:
    ctx->pc = 0x80135CCCu;
    // 80135CCC: bc    12, 2, 0x801364D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801364D0;
        }
    }

label_80135CD0:
    ctx->pc = 0x80135CD0u;
    ctx->downcount -= 2;
    // 80135CD0: cmpwi   r31, 9
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(9);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135CD4:
    ctx->pc = 0x80135CD4u;
    // 80135CD4: bc    12, 2, 0x80135FA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135FA0;
        }
    }

label_80135CD8:
    ctx->pc = 0x80135CD8u;
    ctx->downcount -= 1;
    // 80135CD8: b       0x80136D78
    {
            goto label_80136D78;
    }

label_80135CDC:
    ctx->pc = 0x80135CDCu;
    ctx->downcount -= 2;
    // 80135CDC: cmpwi   r31, 13
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(13);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135CE0:
    ctx->pc = 0x80135CE0u;
    // 80135CE0: bc    12, 2, 0x80136BD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136BD8;
        }
    }

label_80135CE4:
    ctx->pc = 0x80135CE4u;
    ctx->downcount -= 1;
    // 80135CE4: bc    12, 1, 0x80135CFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135CFC;
        }
    }

label_80135CE8:
    ctx->pc = 0x80135CE8u;
    ctx->downcount -= 2;
    // 80135CE8: cmpwi   r31, 11
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(11);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135CEC:
    ctx->pc = 0x80135CECu;
    // 80135CEC: bc    12, 2, 0x8013629C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013629C;
        }
    }

label_80135CF0:
    ctx->pc = 0x80135CF0u;
    ctx->downcount -= 2;
    // 80135CF0: cmpwi   r31, 12
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(12);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135CF4:
    ctx->pc = 0x80135CF4u;
    // 80135CF4: bc    12, 2, 0x80136398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136398;
        }
    }

label_80135CF8:
    ctx->pc = 0x80135CF8u;
    ctx->downcount -= 1;
    // 80135CF8: b       0x80136D78
    {
            goto label_80136D78;
    }

label_80135CFC:
    ctx->pc = 0x80135CFCu;
    ctx->downcount -= 2;
    // 80135CFC: cmpwi   r31, 15
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(15);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135D00:
    ctx->pc = 0x80135D00u;
    // 80135D00: bc    12, 2, 0x80135D10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135D10;
        }
    }

label_80135D04:
    ctx->pc = 0x80135D04u;
    ctx->downcount -= 2;
    // 80135D04: cmpwi   r31, 16
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(16);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135D08:
    ctx->pc = 0x80135D08u;
    // 80135D08: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80135D0C:
    ctx->pc = 0x80135D0Cu;
    ctx->downcount -= 1;
    // 80135D0C: b       0x80136D78
    {
            goto label_80136D78;
    }

label_80135D10:
    ctx->pc = 0x80135D10u;
    ctx->downcount -= 3;
    // 80135D10: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80135D14:
    ctx->pc = 0x80135D14u;
    // 80135D14: addi    r3, r3, -18336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-18336);

label_80135D18:
    ctx->pc = 0x80135D18u;
    // 80135D18: bl      0x8005C984
    {
            ctx->lr = 0x80135D1Cu;
            ctx->pc = 0x8005C984u;
            return;
    }

label_80135D1C:
    ctx->pc = 0x80135D1Cu;
    ctx->downcount -= 1;
    // 80135D1C: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80135D20:
    ctx->pc = 0x80135D20u;
    ctx->downcount -= 3;
    // 80135D20: lwz     r0, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135D24:
    ctx->pc = 0x80135D24u;
    // 80135D24: cmpwi   r0, 0
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

label_80135D28:
    ctx->pc = 0x80135D28u;
    // 80135D28: bc    4, 0, 0x80135D38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135D38;
        }
    }

label_80135D2C:
    ctx->pc = 0x80135D2Cu;
    ctx->downcount -= 3;
    // 80135D2C: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80135D30:
    ctx->pc = 0x80135D30u;
    // 80135D30: lwz     r0, 28680(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28680);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135D34:
    ctx->pc = 0x80135D34u;
    // 80135D34: stw     r0, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135D38:
    ctx->pc = 0x80135D38u;
    ctx->downcount -= 3;
    // 80135D38: lwz     r0, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135D3C:
    ctx->pc = 0x80135D3Cu;
    // 80135D3C: cmpwi   r0, 1679
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1679);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135D40:
    ctx->pc = 0x80135D40u;
    // 80135D40: bc    12, 1, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80135D44:
    ctx->pc = 0x80135D44u;
    ctx->downcount -= 26;
    // 80135D44: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80135D48:
    ctx->pc = 0x80135D48u;
    // 80135D48: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80135D4C:
    ctx->pc = 0x80135D4Cu;
    // 80135D4C: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80135D50:
    ctx->pc = 0x80135D50u;
    // 80135D50: lwz     r6, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80135D54:
    ctx->pc = 0x80135D54u;
    // 80135D54: lwz     r11, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80135D58:
    ctx->pc = 0x80135D58u;
    // 80135D58: lwz     r10, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80135D5C:
    ctx->pc = 0x80135D5Cu;
    // 80135D5C: lwz     r4, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80135D60:
    ctx->pc = 0x80135D60u;
    // 80135D60: xor   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[7];
    }

label_80135D64:
    ctx->pc = 0x80135D64u;
    // 80135D64: lwz     r8, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80135D68:
    ctx->pc = 0x80135D68u;
    // 80135D68: xor   r10, r10, r6
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[6];
    }

label_80135D6C:
    ctx->pc = 0x80135D6Cu;
    // 80135D6C: lwz     r5, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80135D70:
    ctx->pc = 0x80135D70u;
    // 80135D70: rlwinm r11, r11, 0, 21, 21
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00000400u;
    }

label_80135D74:
    ctx->pc = 0x80135D74u;
    // 80135D74: lwz     r0, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135D78:
    ctx->pc = 0x80135D78u;
    // 80135D78: xor   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[4];
    }

label_80135D7C:
    ctx->pc = 0x80135D7Cu;
    // 80135D7C: rlwinm r10, r10, 0, 21, 21
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00000400u;
    }

label_80135D80:
    ctx->pc = 0x80135D80u;
    // 80135D80: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_80135D84:
    ctx->pc = 0x80135D84u;
    // 80135D84: and   r10, r10, r6
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[6];
    }

label_80135D88:
    ctx->pc = 0x80135D88u;
    // 80135D88: xor   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[5];
    }

label_80135D8C:
    ctx->pc = 0x80135D8Cu;
    // 80135D8C: rlwinm r8, r8, 0, 21, 21
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00000400u;
    }

label_80135D90:
    ctx->pc = 0x80135D90u;
    // 80135D90: or   r11, r11, r10
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[10];
    }

label_80135D94:
    ctx->pc = 0x80135D94u;
    // 80135D94: and   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[4];
    }

label_80135D98:
    ctx->pc = 0x80135D98u;
    // 80135D98: rlwinm r0, r0, 0, 21, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000400u;
    }

label_80135D9C:
    ctx->pc = 0x80135D9Cu;
    // 80135D9C: or   r11, r11, r8
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[8];
    }

label_80135DA0:
    ctx->pc = 0x80135DA0u;
    // 80135DA0: and   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[5];
    }

label_80135DA4:
    ctx->pc = 0x80135DA4u;
    // 80135DA4: or.   r11, r11, r0
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80135DA8:
    ctx->pc = 0x80135DA8u;
    // 80135DA8: bc    12, 2, 0x80135F54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135F54;
        }
    }

label_80135DAC:
    ctx->pc = 0x80135DACu;
    ctx->downcount -= 3;
    // 80135DAC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80135DB0:
    ctx->pc = 0x80135DB0u;
    // 80135DB0: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135DB4:
    ctx->pc = 0x80135DB4u;
    // 80135DB4: bl      0x800B7A5C
    {
            ctx->lr = 0x80135DB8u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80135DB8:
    ctx->pc = 0x80135DB8u;
    ctx->downcount -= 12;
    // 80135DB8: lhz     r9, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80135DBC:
    ctx->pc = 0x80135DBCu;
    // 80135DBC: lis     r11, -32733
    ctx->gpr[11] = ((u32)(s32)(-32733) << 16);

label_80135DC0:
    ctx->pc = 0x80135DC0u;
    // 80135DC0: addi    r11, r11, 28640
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(28640);

label_80135DC4:
    ctx->pc = 0x80135DC4u;
    // 80135DC4: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80135DC8:
    ctx->pc = 0x80135DC8u;
    // 80135DC8: addi    r8, r11, 4
    ctx->gpr[8] = ctx->gpr[11] + (u32)(s32)(4);

label_80135DCC:
    ctx->pc = 0x80135DCCu;
    // 80135DCC: sth     r9, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80135DD0:
    ctx->pc = 0x80135DD0u;
    // 80135DD0: extsh r3, r9
    {
        ctx->gpr[3] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_80135DD4:
    ctx->pc = 0x80135DD4u;
    // 80135DD4: rlwinm r0, r3, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0xFFFFFFF8u;
    }

label_80135DD8:
    ctx->pc = 0x80135DD8u;
    // 80135DD8: lwzx    r9, r8, r0
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80135DDC:
    ctx->pc = 0x80135DDCu;
    // 80135DDC: lwzx    r10, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80135DE0:
    ctx->pc = 0x80135DE0u;
    // 80135DE0: stw     r9, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80135DE4:
    ctx->pc = 0x80135DE4u;
    // 80135DE4: b       0x80135F48
    {
            goto label_80135F48;
    }

label_80135DE8:
    ctx->pc = 0x80135DE8u;
    ctx->downcount -= 3;
    // 80135DE8: lwz     r0, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135DEC:
    ctx->pc = 0x80135DECu;
    // 80135DEC: cmpwi   r0, 0
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

label_80135DF0:
    ctx->pc = 0x80135DF0u;
    // 80135DF0: bc    4, 0, 0x80135E00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135E00;
        }
    }

label_80135DF4:
    ctx->pc = 0x80135DF4u;
    ctx->downcount -= 3;
    // 80135DF4: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80135DF8:
    ctx->pc = 0x80135DF8u;
    // 80135DF8: lwz     r0, 28696(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28696);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135DFC:
    ctx->pc = 0x80135DFCu;
    // 80135DFC: stw     r0, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135E00:
    ctx->pc = 0x80135E00u;
    ctx->downcount -= 26;
    // 80135E00: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80135E04:
    ctx->pc = 0x80135E04u;
    // 80135E04: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80135E08:
    ctx->pc = 0x80135E08u;
    // 80135E08: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80135E0C:
    ctx->pc = 0x80135E0Cu;
    // 80135E0C: lwz     r6, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80135E10:
    ctx->pc = 0x80135E10u;
    // 80135E10: lwz     r11, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80135E14:
    ctx->pc = 0x80135E14u;
    // 80135E14: lwz     r10, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80135E18:
    ctx->pc = 0x80135E18u;
    // 80135E18: lwz     r4, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80135E1C:
    ctx->pc = 0x80135E1Cu;
    // 80135E1C: xor   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[7];
    }

label_80135E20:
    ctx->pc = 0x80135E20u;
    // 80135E20: lwz     r8, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80135E24:
    ctx->pc = 0x80135E24u;
    // 80135E24: xor   r10, r10, r6
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[6];
    }

label_80135E28:
    ctx->pc = 0x80135E28u;
    // 80135E28: lwz     r5, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80135E2C:
    ctx->pc = 0x80135E2Cu;
    // 80135E2C: rlwinm r11, r11, 0, 15, 15
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00010000u;
    }

label_80135E30:
    ctx->pc = 0x80135E30u;
    // 80135E30: lwz     r0, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135E34:
    ctx->pc = 0x80135E34u;
    // 80135E34: xor   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[4];
    }

label_80135E38:
    ctx->pc = 0x80135E38u;
    // 80135E38: rlwinm r10, r10, 0, 15, 15
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00010000u;
    }

label_80135E3C:
    ctx->pc = 0x80135E3Cu;
    // 80135E3C: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_80135E40:
    ctx->pc = 0x80135E40u;
    // 80135E40: and   r10, r10, r6
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[6];
    }

label_80135E44:
    ctx->pc = 0x80135E44u;
    // 80135E44: xor   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[5];
    }

label_80135E48:
    ctx->pc = 0x80135E48u;
    // 80135E48: rlwinm r8, r8, 0, 15, 15
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00010000u;
    }

label_80135E4C:
    ctx->pc = 0x80135E4Cu;
    // 80135E4C: or   r11, r11, r10
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[10];
    }

label_80135E50:
    ctx->pc = 0x80135E50u;
    // 80135E50: and   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[4];
    }

label_80135E54:
    ctx->pc = 0x80135E54u;
    // 80135E54: rlwinm r0, r0, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00010000u;
    }

label_80135E58:
    ctx->pc = 0x80135E58u;
    // 80135E58: or   r11, r11, r8
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[8];
    }

label_80135E5C:
    ctx->pc = 0x80135E5Cu;
    // 80135E5C: and   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[5];
    }

label_80135E60:
    ctx->pc = 0x80135E60u;
    // 80135E60: or.   r11, r11, r0
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80135E64:
    ctx->pc = 0x80135E64u;
    // 80135E64: bc    12, 2, 0x80135F54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135F54;
        }
    }

label_80135E68:
    ctx->pc = 0x80135E68u;
    ctx->downcount -= 5;
    // 80135E68: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80135E6C:
    ctx->pc = 0x80135E6Cu;
    // 80135E6C: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80135E70:
    ctx->pc = 0x80135E70u;
    // 80135E70: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80135E70u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80135E74:
    ctx->pc = 0x80135E74u;
    // 80135E74: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_80135E78:
    ctx->pc = 0x80135E78u;
    // 80135E78: bl      0x8004DC00
    {
            ctx->lr = 0x80135E7Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80135E7C:
    ctx->pc = 0x80135E7Cu;
    ctx->downcount -= 3;
    // 80135E7C: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135E80:
    ctx->pc = 0x80135E80u;
    // 80135E80: cmpwi   r0, 1
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

label_80135E84:
    ctx->pc = 0x80135E84u;
    // 80135E84: bc    12, 2, 0x80135EA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135EA0;
        }
    }

label_80135E88:
    ctx->pc = 0x80135E88u;
    ctx->downcount -= 1;
    // 80135E88: bc    4, 1, 0x80135F0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80135F0C;
        }
    }

label_80135E8C:
    ctx->pc = 0x80135E8Cu;
    ctx->downcount -= 2;
    // 80135E8C: cmpwi   r0, 2
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

label_80135E90:
    ctx->pc = 0x80135E90u;
    // 80135E90: bc    12, 2, 0x80136D38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136D38;
        }
    }

label_80135E94:
    ctx->pc = 0x80135E94u;
    ctx->downcount -= 2;
    // 80135E94: cmpwi   r0, 3
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

label_80135E98:
    ctx->pc = 0x80135E98u;
    // 80135E98: bc    12, 2, 0x80135EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80135EBC;
        }
    }

label_80135E9C:
    ctx->pc = 0x80135E9Cu;
    ctx->downcount -= 1;
    // 80135E9C: b       0x80135F0C
    {
            goto label_80135F0C;
    }

label_80135EA0:
    ctx->pc = 0x80135EA0u;
    ctx->downcount -= 3;
    // 80135EA0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80135EA4:
    ctx->pc = 0x80135EA4u;
    // 80135EA4: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135EA8:
    ctx->pc = 0x80135EA8u;
    // 80135EA8: bl      0x800B7A5C
    {
            ctx->lr = 0x80135EACu;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80135EAC:
    ctx->pc = 0x80135EACu;
    ctx->downcount -= 3;
    // 80135EAC: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80135EB0:
    ctx->pc = 0x80135EB0u;
    // 80135EB0: addi    r3, r3, -18336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-18336);

label_80135EB4:
    ctx->pc = 0x80135EB4u;
    // 80135EB4: bl      0x8005C750
    {
            ctx->lr = 0x80135EB8u;
            ctx->pc = 0x8005C750u;
            return;
    }

label_80135EB8:
    ctx->pc = 0x80135EB8u;
    ctx->downcount -= 1;
    // 80135EB8: b       0x80136BAC
    {
            goto label_80136BAC;
    }

label_80135EBC:
    ctx->pc = 0x80135EBCu;
    ctx->downcount -= 4;
    // 80135EBC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80135EC0:
    ctx->pc = 0x80135EC0u;
    // 80135EC0: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135EC4:
    ctx->pc = 0x80135EC4u;
    // 80135EC4: stw     r0, -30088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30088);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135EC8:
    ctx->pc = 0x80135EC8u;
    // 80135EC8: bl      0x800B7A5C
    {
            ctx->lr = 0x80135ECCu;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80135ECC:
    ctx->pc = 0x80135ECCu;
    ctx->downcount -= 12;
    // 80135ECC: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80135ED0:
    ctx->pc = 0x80135ED0u;
    // 80135ED0: li      r0, 120
    ctx->gpr[0] = (u32)(s32)(120);

label_80135ED4:
    ctx->pc = 0x80135ED4u;
    // 80135ED4: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80135ED8:
    ctx->pc = 0x80135ED8u;
    // 80135ED8: li      r7, 15
    ctx->gpr[7] = (u32)(s32)(15);

label_80135EDC:
    ctx->pc = 0x80135EDCu;
    // 80135EDC: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_80135EE0:
    ctx->pc = 0x80135EE0u;
    // 80135EE0: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80135EE4:
    ctx->pc = 0x80135EE4u;
    // 80135EE4: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80135EE8:
    ctx->pc = 0x80135EE8u;
    // 80135EE8: li      r3, 15
    ctx->gpr[3] = (u32)(s32)(15);

label_80135EEC:
    ctx->pc = 0x80135EECu;
    // 80135EEC: sth     r7, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80135EF0:
    ctx->pc = 0x80135EF0u;
    // 80135EF0: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80135EF4:
    ctx->pc = 0x80135EF4u;
    // 80135EF4: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80135EF8:
    ctx->pc = 0x80135EF8u;
    // 80135EF8: bl      0x80132E34
    {
            ctx->lr = 0x80135EFCu;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80135EFC:
    ctx->pc = 0x80135EFCu;
    ctx->downcount -= 3;
    // 80135EFC: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80135F00:
    ctx->pc = 0x80135F00u;
    // 80135F00: addi    r3, r3, -18336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-18336);

label_80135F04:
    ctx->pc = 0x80135F04u;
    // 80135F04: bl      0x8005E9C8
    {
            ctx->lr = 0x80135F08u;
            ctx->pc = 0x8005E9C8u;
            return;
    }

label_80135F08:
    ctx->pc = 0x80135F08u;
    ctx->downcount -= 1;
    // 80135F08: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80135F0C:
    ctx->pc = 0x80135F0Cu;
    ctx->downcount -= 3;
    // 80135F0C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80135F10:
    ctx->pc = 0x80135F10u;
    // 80135F10: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80135F14:
    ctx->pc = 0x80135F14u;
    // 80135F14: bl      0x800B7A5C
    {
            ctx->lr = 0x80135F18u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80135F18:
    ctx->pc = 0x80135F18u;
    ctx->downcount -= 3;
    // 80135F18: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80135F1C:
    ctx->pc = 0x80135F1Cu;
    // 80135F1C: addi    r3, r3, -18336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-18336);

label_80135F20:
    ctx->pc = 0x80135F20u;
    // 80135F20: bl      0x8005C63C
    {
            ctx->lr = 0x80135F24u;
            ctx->pc = 0x8005C63Cu;
            return;
    }

label_80135F24:
    ctx->pc = 0x80135F24u;
    ctx->downcount -= 9;
    // 80135F24: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80135F28:
    ctx->pc = 0x80135F28u;
    // 80135F28: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80135F2C:
    ctx->pc = 0x80135F2Cu;
    // 80135F2C: lha     r3, -21584(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-21584);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80135F30:
    ctx->pc = 0x80135F30u;
    // 80135F30: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80135F34:
    ctx->pc = 0x80135F34u;
    // 80135F34: addi    r8, r9, 4
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(4);

label_80135F38:
    ctx->pc = 0x80135F38u;
    // 80135F38: rlwinm r0, r3, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0xFFFFFFF8u;
    }

label_80135F3C:
    ctx->pc = 0x80135F3Cu;
    // 80135F3C: lwzx    r11, r8, r0
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80135F40:
    ctx->pc = 0x80135F40u;
    // 80135F40: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80135F44:
    ctx->pc = 0x80135F44u;
    // 80135F44: stw     r11, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80135F48:
    ctx->pc = 0x80135F48u;
    ctx->downcount -= 2;
    // 80135F48: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80135F4C:
    ctx->pc = 0x80135F4Cu;
    // 80135F4C: bl      0x80132E34
    {
            ctx->lr = 0x80135F50u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80135F50:
    ctx->pc = 0x80135F50u;
    ctx->downcount -= 1;
    // 80135F50: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80135F54:
    ctx->pc = 0x80135F54u;
    ctx->downcount -= 2;
    // 80135F54: cmpwi   r20, 0
    {
        s32 val_a = (s32)(ctx->gpr[20]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80135F58:
    ctx->pc = 0x80135F58u;
    // 80135F58: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80135F5C:
    ctx->pc = 0x80135F5Cu;
    ctx->downcount -= 2;
    // 80135F5C: stw     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80135F60:
    ctx->pc = 0x80135F60u;
    // 80135F60: bl      0x800B7A5C
    {
            ctx->lr = 0x80135F64u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80135F64:
    ctx->pc = 0x80135F64u;
    ctx->downcount -= 14;
    // 80135F64: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80135F68:
    ctx->pc = 0x80135F68u;
    // 80135F68: li      r10, 48
    ctx->gpr[10] = (u32)(s32)(48);

label_80135F6C:
    ctx->pc = 0x80135F6Cu;
    // 80135F6C: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80135F70:
    ctx->pc = 0x80135F70u;
    // 80135F70: lha     r6, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        ctx->gpr[6] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80135F74:
    ctx->pc = 0x80135F74u;
    // 80135F74: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_80135F78:
    ctx->pc = 0x80135F78u;
    // 80135F78: lwzx    r8, r9, r10
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[10];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80135F7C:
    ctx->pc = 0x80135F7Cu;
    // 80135F7C: lwzx    r7, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80135F80:
    ctx->pc = 0x80135F80u;
    // 80135F80: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_80135F84:
    ctx->pc = 0x80135F84u;
    // 80135F84: sth     r0, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80135F88:
    ctx->pc = 0x80135F88u;
    // 80135F88: li      r3, 6
    ctx->gpr[3] = (u32)(s32)(6);

label_80135F8C:
    ctx->pc = 0x80135F8Cu;
    // 80135F8C: stw     r6, -30100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30100);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80135F90:
    ctx->pc = 0x80135F90u;
    // 80135F90: stw     r8, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80135F94:
    ctx->pc = 0x80135F94u;
    // 80135F94: stw     r7, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80135F98:
    ctx->pc = 0x80135F98u;
    // 80135F98: bl      0x80132E34
    {
            ctx->lr = 0x80135F9Cu;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80135F9C:
    ctx->pc = 0x80135F9Cu;
    ctx->downcount -= 1;
    // 80135F9C: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80135FA0:
    ctx->pc = 0x80135FA0u;
    ctx->downcount -= 26;
    // 80135FA0: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80135FA4:
    ctx->pc = 0x80135FA4u;
    // 80135FA4: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80135FA8:
    ctx->pc = 0x80135FA8u;
    // 80135FA8: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80135FAC:
    ctx->pc = 0x80135FACu;
    // 80135FAC: lwz     r6, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80135FB0:
    ctx->pc = 0x80135FB0u;
    // 80135FB0: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80135FB4:
    ctx->pc = 0x80135FB4u;
    // 80135FB4: lwz     r11, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80135FB8:
    ctx->pc = 0x80135FB8u;
    // 80135FB8: lwz     r4, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80135FBC:
    ctx->pc = 0x80135FBCu;
    // 80135FBC: xor   r31, r0, r7
    {
        ctx->gpr[31] = ctx->gpr[0] ^ ctx->gpr[7];
    }

label_80135FC0:
    ctx->pc = 0x80135FC0u;
    // 80135FC0: lwz     r5, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80135FC4:
    ctx->pc = 0x80135FC4u;
    // 80135FC4: xor   r3, r11, r6
    {
        ctx->gpr[3] = ctx->gpr[11] ^ ctx->gpr[6];
    }

label_80135FC8:
    ctx->pc = 0x80135FC8u;
    // 80135FC8: lwz     r10, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80135FCC:
    ctx->pc = 0x80135FCCu;
    // 80135FCC: rlwinm r0, r3, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00010000u;
    }

label_80135FD0:
    ctx->pc = 0x80135FD0u;
    // 80135FD0: lwz     r8, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80135FD4:
    ctx->pc = 0x80135FD4u;
    // 80135FD4: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_80135FD8:
    ctx->pc = 0x80135FD8u;
    // 80135FD8: rlwinm r9, r31, 0, 15, 15
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00010000u;
    }

label_80135FDC:
    ctx->pc = 0x80135FDCu;
    // 80135FDC: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_80135FE0:
    ctx->pc = 0x80135FE0u;
    // 80135FE0: and   r9, r9, r7
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[7];
    }

label_80135FE4:
    ctx->pc = 0x80135FE4u;
    // 80135FE4: xor   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[4];
    }

label_80135FE8:
    ctx->pc = 0x80135FE8u;
    // 80135FE8: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_80135FEC:
    ctx->pc = 0x80135FECu;
    // 80135FEC: rlwinm r11, r10, 0, 15, 15
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00010000u;
    }

label_80135FF0:
    ctx->pc = 0x80135FF0u;
    // 80135FF0: and   r11, r11, r5
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[5];
    }

label_80135FF4:
    ctx->pc = 0x80135FF4u;
    // 80135FF4: rlwinm r0, r8, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00010000u;
    }

label_80135FF8:
    ctx->pc = 0x80135FF8u;
    // 80135FF8: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_80135FFC:
    ctx->pc = 0x80135FFCu;
    // 80135FFC: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_80136000:
    ctx->pc = 0x80136000u;
    // 80136000: or.   r30, r9, r0
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136004:
    ctx->pc = 0x80136004u;
    // 80136004: bc    12, 2, 0x80136060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136060;
        }
    }

label_80136008:
    ctx->pc = 0x80136008u;
    ctx->downcount -= 5;
    // 80136008: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013600C:
    ctx->pc = 0x8013600Cu;
    // 8013600C: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136010:
    ctx->pc = 0x80136010u;
    // 80136010: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136010u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136014:
    ctx->pc = 0x80136014u;
    // 80136014: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_80136018:
    ctx->pc = 0x80136018u;
    // 80136018: bl      0x8004DC00
    {
            ctx->lr = 0x8013601Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8013601C:
    ctx->pc = 0x8013601Cu;
    ctx->downcount -= 2;
    // 8013601C: lis     r3, 1
    ctx->gpr[3] = ((u32)(s32)(1) << 16);

label_80136020:
    ctx->pc = 0x80136020u;
    // 80136020: bl      0x8004427C
    {
            ctx->lr = 0x80136024u;
            ctx->pc = 0x8004427Cu;
            return;
    }

label_80136024:
    ctx->pc = 0x80136024u;
    ctx->downcount -= 10;
    // 80136024: lwz     r10, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136028:
    ctx->pc = 0x80136028u;
    // 80136028: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8013602C:
    ctx->pc = 0x8013602Cu;
    // 8013602C: addi    r9, r9, -13308
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-13308);

label_80136030:
    ctx->pc = 0x80136030u;
    // 80136030: stw     r3, -32304(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32304);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80136034:
    ctx->pc = 0x80136034u;
    // 80136034: mulli   r11, r10, 8376
    ctx->gpr[11] = (u32)((s64)(s32)ctx->gpr[10] * (s64)(s32)8376);

label_80136038:
    ctx->pc = 0x80136038u;
    // 80136038: lwzx    r0, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013603C:
    ctx->pc = 0x8013603Cu;
    // 8013603C: cmpwi   r0, 0
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

label_80136040:
    ctx->pc = 0x80136040u;
    // 80136040: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136044:
    ctx->pc = 0x80136044u;
    ctx->downcount -= 4;
    // 80136044: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80136048:
    ctx->pc = 0x80136048u;
    // 80136048: lwzx    r0, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013604C:
    ctx->pc = 0x8013604Cu;
    // 8013604C: cmpwi   r0, 0
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

label_80136050:
    ctx->pc = 0x80136050u;
    // 80136050: bc    4, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136054:
    ctx->pc = 0x80136054u;
    ctx->downcount -= 2;
    // 80136054: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_80136058:
    ctx->pc = 0x80136058u;
    // 80136058: bl      0x8005E2E8
    {
            ctx->lr = 0x8013605Cu;
            ctx->pc = 0x8005E2E8u;
            return;
    }

label_8013605C:
    ctx->pc = 0x8013605Cu;
    ctx->downcount -= 1;
    // 8013605C: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136060:
    ctx->pc = 0x80136060u;
    ctx->downcount -= 12;
    // 80136060: rlwinm r9, r31, 0, 14, 14
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00020000u;
    }

label_80136064:
    ctx->pc = 0x80136064u;
    // 80136064: rlwinm r0, r3, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00020000u;
    }

label_80136068:
    ctx->pc = 0x80136068u;
    // 80136068: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_8013606C:
    ctx->pc = 0x8013606Cu;
    // 8013606C: and   r9, r9, r7
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[7];
    }

label_80136070:
    ctx->pc = 0x80136070u;
    // 80136070: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_80136074:
    ctx->pc = 0x80136074u;
    // 80136074: rlwinm r11, r10, 0, 14, 14
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00020000u;
    }

label_80136078:
    ctx->pc = 0x80136078u;
    // 80136078: and   r11, r11, r5
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[5];
    }

label_8013607C:
    ctx->pc = 0x8013607Cu;
    // 8013607C: rlwinm r0, r8, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00020000u;
    }

label_80136080:
    ctx->pc = 0x80136080u;
    // 80136080: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_80136084:
    ctx->pc = 0x80136084u;
    // 80136084: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_80136088:
    ctx->pc = 0x80136088u;
    // 80136088: or.   r6, r9, r0
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8013608C:
    ctx->pc = 0x8013608Cu;
    // 8013608C: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136090:
    ctx->pc = 0x80136090u;
    ctx->downcount -= 5;
    // 80136090: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136094:
    ctx->pc = 0x80136094u;
    // 80136094: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136098:
    ctx->pc = 0x80136098u;
    // 80136098: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136098u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013609C:
    ctx->pc = 0x8013609Cu;
    // 8013609C: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_801360A0:
    ctx->pc = 0x801360A0u;
    // 801360A0: bl      0x8004DC00
    {
            ctx->lr = 0x801360A4u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801360A4:
    ctx->pc = 0x801360A4u;
    ctx->downcount -= 2;
    // 801360A4: stw     r30, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801360A8:
    ctx->pc = 0x801360A8u;
    // 801360A8: bl      0x800B7A5C
    {
            ctx->lr = 0x801360ACu;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_801360AC:
    ctx->pc = 0x801360ACu;
    ctx->downcount -= 9;
    // 801360AC: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_801360B0:
    ctx->pc = 0x801360B0u;
    // 801360B0: li      r0, 56
    ctx->gpr[0] = (u32)(s32)(56);

label_801360B4:
    ctx->pc = 0x801360B4u;
    // 801360B4: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_801360B8:
    ctx->pc = 0x801360B8u;
    // 801360B8: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_801360BC:
    ctx->pc = 0x801360BCu;
    // 801360BC: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_801360C0:
    ctx->pc = 0x801360C0u;
    // 801360C0: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801360C4:
    ctx->pc = 0x801360C4u;
    // 801360C4: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801360C8:
    ctx->pc = 0x801360C8u;
    // 801360C8: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_801360CC:
    ctx->pc = 0x801360CCu;
    // 801360CC: b       0x80136D64
    {
            goto label_80136D64;
    }

label_801360D0:
    ctx->pc = 0x801360D0u;
    ctx->downcount -= 26;
    // 801360D0: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_801360D4:
    ctx->pc = 0x801360D4u;
    // 801360D4: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_801360D8:
    ctx->pc = 0x801360D8u;
    // 801360D8: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801360DC:
    ctx->pc = 0x801360DCu;
    // 801360DC: lwz     r6, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801360E0:
    ctx->pc = 0x801360E0u;
    // 801360E0: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801360E4:
    ctx->pc = 0x801360E4u;
    // 801360E4: lwz     r11, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801360E8:
    ctx->pc = 0x801360E8u;
    // 801360E8: lwz     r4, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801360EC:
    ctx->pc = 0x801360ECu;
    // 801360EC: xor   r31, r0, r7
    {
        ctx->gpr[31] = ctx->gpr[0] ^ ctx->gpr[7];
    }

label_801360F0:
    ctx->pc = 0x801360F0u;
    // 801360F0: lwz     r5, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801360F4:
    ctx->pc = 0x801360F4u;
    // 801360F4: xor   r3, r11, r6
    {
        ctx->gpr[3] = ctx->gpr[11] ^ ctx->gpr[6];
    }

label_801360F8:
    ctx->pc = 0x801360F8u;
    // 801360F8: lwz     r10, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801360FC:
    ctx->pc = 0x801360FCu;
    // 801360FC: rlwinm r0, r3, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00010000u;
    }

label_80136100:
    ctx->pc = 0x80136100u;
    // 80136100: lwz     r8, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136104:
    ctx->pc = 0x80136104u;
    // 80136104: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_80136108:
    ctx->pc = 0x80136108u;
    // 80136108: rlwinm r9, r31, 0, 15, 15
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00010000u;
    }

label_8013610C:
    ctx->pc = 0x8013610Cu;
    // 8013610C: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_80136110:
    ctx->pc = 0x80136110u;
    // 80136110: and   r9, r9, r7
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[7];
    }

label_80136114:
    ctx->pc = 0x80136114u;
    // 80136114: xor   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[4];
    }

label_80136118:
    ctx->pc = 0x80136118u;
    // 80136118: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_8013611C:
    ctx->pc = 0x8013611Cu;
    // 8013611C: rlwinm r11, r10, 0, 15, 15
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00010000u;
    }

label_80136120:
    ctx->pc = 0x80136120u;
    // 80136120: and   r11, r11, r5
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[5];
    }

label_80136124:
    ctx->pc = 0x80136124u;
    // 80136124: rlwinm r0, r8, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00010000u;
    }

label_80136128:
    ctx->pc = 0x80136128u;
    // 80136128: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_8013612C:
    ctx->pc = 0x8013612Cu;
    // 8013612C: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_80136130:
    ctx->pc = 0x80136130u;
    // 80136130: or.   r30, r9, r0
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136134:
    ctx->pc = 0x80136134u;
    // 80136134: bc    12, 2, 0x8013622C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013622C;
        }
    }

label_80136138:
    ctx->pc = 0x80136138u;
    ctx->downcount -= 5;
    // 80136138: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013613C:
    ctx->pc = 0x8013613Cu;
    // 8013613C: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136140:
    ctx->pc = 0x80136140u;
    // 80136140: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136140u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136144:
    ctx->pc = 0x80136144u;
    // 80136144: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_80136148:
    ctx->pc = 0x80136148u;
    // 80136148: bl      0x8004DC00
    {
            ctx->lr = 0x8013614Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8013614C:
    ctx->pc = 0x8013614Cu;
    ctx->downcount -= 2;
    // 8013614C: lis     r3, 1
    ctx->gpr[3] = ((u32)(s32)(1) << 16);

label_80136150:
    ctx->pc = 0x80136150u;
    // 80136150: bl      0x8004427C
    {
            ctx->lr = 0x80136154u;
            ctx->pc = 0x8004427Cu;
            return;
    }

label_80136154:
    ctx->pc = 0x80136154u;
    ctx->downcount -= 4;
    // 80136154: lwz     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136158:
    ctx->pc = 0x80136158u;
    // 80136158: stw     r3, -32304(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32304);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8013615C:
    ctx->pc = 0x8013615Cu;
    // 8013615C: cmpwi   r11, 2
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80136160:
    ctx->pc = 0x80136160u;
    // 80136160: bc    4, 1, 0x8013619C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013619C;
        }
    }

label_80136164:
    ctx->pc = 0x80136164u;
    ctx->downcount -= 5;
    // 80136164: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80136168:
    ctx->pc = 0x80136168u;
    // 80136168: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8013616C:
    ctx->pc = 0x8013616Cu;
    // 8013616C: stw     r0, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136170:
    ctx->pc = 0x80136170u;
    // 80136170: stw     r9, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80136174:
    ctx->pc = 0x80136174u;
    // 80136174: bl      0x800B7A5C
    {
            ctx->lr = 0x80136178u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80136178:
    ctx->pc = 0x80136178u;
    ctx->downcount -= 9;
    // 80136178: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_8013617C:
    ctx->pc = 0x8013617Cu;
    // 8013617C: li      r0, 96
    ctx->gpr[0] = (u32)(s32)(96);

label_80136180:
    ctx->pc = 0x80136180u;
    // 80136180: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80136184:
    ctx->pc = 0x80136184u;
    // 80136184: li      r7, 12
    ctx->gpr[7] = (u32)(s32)(12);

label_80136188:
    ctx->pc = 0x80136188u;
    // 80136188: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_8013618C:
    ctx->pc = 0x8013618Cu;
    // 8013618C: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136190:
    ctx->pc = 0x80136190u;
    // 80136190: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136194:
    ctx->pc = 0x80136194u;
    // 80136194: li      r3, 12
    ctx->gpr[3] = (u32)(s32)(12);

label_80136198:
    ctx->pc = 0x80136198u;
    // 80136198: b       0x80136D64
    {
            goto label_80136D64;
    }

label_8013619C:
    ctx->pc = 0x8013619Cu;
    ctx->downcount -= 8;
    // 8013619C: mulli   r0, r11, 8376
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)8376);

label_801361A0:
    ctx->pc = 0x801361A0u;
    // 801361A0: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_801361A4:
    ctx->pc = 0x801361A4u;
    // 801361A4: addi    r9, r9, -13308
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-13308);

label_801361A8:
    ctx->pc = 0x801361A8u;
    // 801361A8: lwzx    r31, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801361AC:
    ctx->pc = 0x801361ACu;
    // 801361AC: cmpwi   r31, 0
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

label_801361B0:
    ctx->pc = 0x801361B0u;
    // 801361B0: bc    12, 2, 0x801361E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801361E8;
        }
    }

label_801361B4:
    ctx->pc = 0x801361B4u;
    ctx->downcount -= 4;
    // 801361B4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801361B8:
    ctx->pc = 0x801361B8u;
    // 801361B8: stw     r11, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801361BC:
    ctx->pc = 0x801361BCu;
    // 801361BC: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801361C0:
    ctx->pc = 0x801361C0u;
    // 801361C0: bl      0x800B7A5C
    {
            ctx->lr = 0x801361C4u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_801361C4:
    ctx->pc = 0x801361C4u;
    ctx->downcount -= 9;
    // 801361C4: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_801361C8:
    ctx->pc = 0x801361C8u;
    // 801361C8: li      r0, 88
    ctx->gpr[0] = (u32)(s32)(88);

label_801361CC:
    ctx->pc = 0x801361CCu;
    // 801361CC: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_801361D0:
    ctx->pc = 0x801361D0u;
    // 801361D0: li      r7, 11
    ctx->gpr[7] = (u32)(s32)(11);

label_801361D4:
    ctx->pc = 0x801361D4u;
    // 801361D4: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_801361D8:
    ctx->pc = 0x801361D8u;
    // 801361D8: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801361DC:
    ctx->pc = 0x801361DCu;
    // 801361DC: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801361E0:
    ctx->pc = 0x801361E0u;
    // 801361E0: li      r3, 11
    ctx->gpr[3] = (u32)(s32)(11);

label_801361E4:
    ctx->pc = 0x801361E4u;
    // 801361E4: b       0x80136D64
    {
            goto label_80136D64;
    }

label_801361E8:
    ctx->pc = 0x801361E8u;
    ctx->downcount -= 9;
    // 801361E8: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_801361EC:
    ctx->pc = 0x801361ECu;
    // 801361EC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801361F0:
    ctx->pc = 0x801361F0u;
    // 801361F0: lwz     r3, -27076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27076);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801361F4:
    ctx->pc = 0x801361F4u;
    // 801361F4: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_801361F8:
    ctx->pc = 0x801361F8u;
    // 801361F8: stw     r11, -27920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27920);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_801361FC:
    ctx->pc = 0x801361FCu;
    // 801361FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80136200:
    ctx->pc = 0x80136200u;
    // 80136200: stw     r0, 11832(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(11832);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136204:
    ctx->pc = 0x80136204u;
    // 80136204: stw     r31, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80136208:
    ctx->pc = 0x80136208u;
    // 80136208: bl      0x800B7D14
    {
            ctx->lr = 0x8013620Cu;
            ctx->pc = 0x800B7D14u;
            return;
    }

label_8013620C:
    ctx->pc = 0x8013620Cu;
    ctx->downcount -= 4;
    // 8013620C: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80136210:
    ctx->pc = 0x80136210u;
    // 80136210: li      r4, 250
    ctx->gpr[4] = (u32)(s32)(250);

label_80136214:
    ctx->pc = 0x80136214u;
    // 80136214: addi    r3, r3, -27148
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27148);

label_80136218:
    ctx->pc = 0x80136218u;
    // 80136218: bl      0x8001776C
    {
            ctx->lr = 0x8013621Cu;
            ctx->pc = 0x8001776Cu;
            return;
    }

label_8013621C:
    ctx->pc = 0x8013621Cu;
    ctx->downcount -= 2;
    // 8013621C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80136220:
    ctx->pc = 0x80136220u;
    // 80136220: bl      0x8005B7BC
    {
            ctx->lr = 0x80136224u;
            ctx->pc = 0x8005B7BCu;
            return;
    }

label_80136224:
    ctx->pc = 0x80136224u;
    ctx->downcount -= 2;
    // 80136224: stw     r31, -32360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32360);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80136228:
    ctx->pc = 0x80136228u;
    // 80136228: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_8013622C:
    ctx->pc = 0x8013622Cu;
    ctx->downcount -= 12;
    // 8013622C: rlwinm r9, r31, 0, 14, 14
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00020000u;
    }

label_80136230:
    ctx->pc = 0x80136230u;
    // 80136230: rlwinm r0, r3, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00020000u;
    }

label_80136234:
    ctx->pc = 0x80136234u;
    // 80136234: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_80136238:
    ctx->pc = 0x80136238u;
    // 80136238: and   r9, r9, r7
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[7];
    }

label_8013623C:
    ctx->pc = 0x8013623Cu;
    // 8013623C: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_80136240:
    ctx->pc = 0x80136240u;
    // 80136240: rlwinm r11, r10, 0, 14, 14
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00020000u;
    }

label_80136244:
    ctx->pc = 0x80136244u;
    // 80136244: and   r11, r11, r5
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[5];
    }

label_80136248:
    ctx->pc = 0x80136248u;
    // 80136248: rlwinm r0, r8, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00020000u;
    }

label_8013624C:
    ctx->pc = 0x8013624Cu;
    // 8013624C: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_80136250:
    ctx->pc = 0x80136250u;
    // 80136250: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_80136254:
    ctx->pc = 0x80136254u;
    // 80136254: or.   r6, r9, r0
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136258:
    ctx->pc = 0x80136258u;
    // 80136258: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_8013625C:
    ctx->pc = 0x8013625Cu;
    ctx->downcount -= 5;
    // 8013625C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136260:
    ctx->pc = 0x80136260u;
    // 80136260: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136264:
    ctx->pc = 0x80136264u;
    // 80136264: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136264u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136268:
    ctx->pc = 0x80136268u;
    // 80136268: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_8013626C:
    ctx->pc = 0x8013626Cu;
    // 8013626C: bl      0x8004DC00
    {
            ctx->lr = 0x80136270u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136270:
    ctx->pc = 0x80136270u;
    ctx->downcount -= 2;
    // 80136270: stw     r30, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80136274:
    ctx->pc = 0x80136274u;
    // 80136274: bl      0x800B7A5C
    {
            ctx->lr = 0x80136278u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80136278:
    ctx->pc = 0x80136278u;
    ctx->downcount -= 9;
    // 80136278: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_8013627C:
    ctx->pc = 0x8013627Cu;
    // 8013627C: li      r0, 56
    ctx->gpr[0] = (u32)(s32)(56);

label_80136280:
    ctx->pc = 0x80136280u;
    // 80136280: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80136284:
    ctx->pc = 0x80136284u;
    // 80136284: li      r7, 7
    ctx->gpr[7] = (u32)(s32)(7);

label_80136288:
    ctx->pc = 0x80136288u;
    // 80136288: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_8013628C:
    ctx->pc = 0x8013628Cu;
    // 8013628C: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136290:
    ctx->pc = 0x80136290u;
    // 80136290: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136294:
    ctx->pc = 0x80136294u;
    // 80136294: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80136298:
    ctx->pc = 0x80136298u;
    // 80136298: b       0x80136D64
    {
            goto label_80136D64;
    }

label_8013629C:
    ctx->pc = 0x8013629Cu;
    ctx->downcount -= 26;
    // 8013629C: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_801362A0:
    ctx->pc = 0x801362A0u;
    // 801362A0: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_801362A4:
    ctx->pc = 0x801362A4u;
    // 801362A4: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801362A8:
    ctx->pc = 0x801362A8u;
    // 801362A8: lwz     r6, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801362AC:
    ctx->pc = 0x801362ACu;
    // 801362AC: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801362B0:
    ctx->pc = 0x801362B0u;
    // 801362B0: lwz     r11, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801362B4:
    ctx->pc = 0x801362B4u;
    // 801362B4: lwz     r4, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801362B8:
    ctx->pc = 0x801362B8u;
    // 801362B8: xor   r31, r0, r7
    {
        ctx->gpr[31] = ctx->gpr[0] ^ ctx->gpr[7];
    }

label_801362BC:
    ctx->pc = 0x801362BCu;
    // 801362BC: lwz     r5, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801362C0:
    ctx->pc = 0x801362C0u;
    // 801362C0: xor   r3, r11, r6
    {
        ctx->gpr[3] = ctx->gpr[11] ^ ctx->gpr[6];
    }

label_801362C4:
    ctx->pc = 0x801362C4u;
    // 801362C4: lwz     r10, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801362C8:
    ctx->pc = 0x801362C8u;
    // 801362C8: rlwinm r0, r3, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00010000u;
    }

label_801362CC:
    ctx->pc = 0x801362CCu;
    // 801362CC: lwz     r8, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801362D0:
    ctx->pc = 0x801362D0u;
    // 801362D0: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_801362D4:
    ctx->pc = 0x801362D4u;
    // 801362D4: rlwinm r9, r31, 0, 15, 15
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00010000u;
    }

label_801362D8:
    ctx->pc = 0x801362D8u;
    // 801362D8: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_801362DC:
    ctx->pc = 0x801362DCu;
    // 801362DC: and   r9, r9, r7
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[7];
    }

label_801362E0:
    ctx->pc = 0x801362E0u;
    // 801362E0: xor   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[4];
    }

label_801362E4:
    ctx->pc = 0x801362E4u;
    // 801362E4: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_801362E8:
    ctx->pc = 0x801362E8u;
    // 801362E8: rlwinm r11, r10, 0, 15, 15
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00010000u;
    }

label_801362EC:
    ctx->pc = 0x801362ECu;
    // 801362EC: and   r11, r11, r5
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[5];
    }

label_801362F0:
    ctx->pc = 0x801362F0u;
    // 801362F0: rlwinm r0, r8, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00010000u;
    }

label_801362F4:
    ctx->pc = 0x801362F4u;
    // 801362F4: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_801362F8:
    ctx->pc = 0x801362F8u;
    // 801362F8: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_801362FC:
    ctx->pc = 0x801362FCu;
    // 801362FC: or.   r11, r9, r0
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

label_80136300:
    ctx->pc = 0x80136300u;
    // 80136300: bc    12, 2, 0x80136324
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136324;
        }
    }

label_80136304:
    ctx->pc = 0x80136304u;
    ctx->downcount -= 5;
    // 80136304: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136308:
    ctx->pc = 0x80136308u;
    // 80136308: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8013630C:
    ctx->pc = 0x8013630Cu;
    // 8013630C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x8013630Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136310:
    ctx->pc = 0x80136310u;
    // 80136310: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_80136314:
    ctx->pc = 0x80136314u;
    // 80136314: bl      0x8004DC00
    {
            ctx->lr = 0x80136318u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136318:
    ctx->pc = 0x80136318u;
    ctx->downcount -= 3;
    // 80136318: lwz     r11, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8013631C:
    ctx->pc = 0x8013631Cu;
    // 8013631C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80136320:
    ctx->pc = 0x80136320u;
    // 80136320: b       0x8013641C
    {
            goto label_8013641C;
    }

label_80136324:
    ctx->pc = 0x80136324u;
    ctx->downcount -= 12;
    // 80136324: rlwinm r9, r31, 0, 14, 14
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00020000u;
    }

label_80136328:
    ctx->pc = 0x80136328u;
    // 80136328: rlwinm r0, r3, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00020000u;
    }

label_8013632C:
    ctx->pc = 0x8013632Cu;
    // 8013632C: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_80136330:
    ctx->pc = 0x80136330u;
    // 80136330: and   r9, r9, r7
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[7];
    }

label_80136334:
    ctx->pc = 0x80136334u;
    // 80136334: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_80136338:
    ctx->pc = 0x80136338u;
    // 80136338: rlwinm r11, r10, 0, 14, 14
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00020000u;
    }

label_8013633C:
    ctx->pc = 0x8013633Cu;
    // 8013633C: and   r11, r11, r5
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[5];
    }

label_80136340:
    ctx->pc = 0x80136340u;
    // 80136340: rlwinm r0, r8, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00020000u;
    }

label_80136344:
    ctx->pc = 0x80136344u;
    // 80136344: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_80136348:
    ctx->pc = 0x80136348u;
    // 80136348: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_8013634C:
    ctx->pc = 0x8013634Cu;
    // 8013634C: or.   r6, r9, r0
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136350:
    ctx->pc = 0x80136350u;
    // 80136350: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136354:
    ctx->pc = 0x80136354u;
    ctx->downcount -= 5;
    // 80136354: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136358:
    ctx->pc = 0x80136358u;
    // 80136358: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8013635C:
    ctx->pc = 0x8013635Cu;
    // 8013635C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x8013635Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136360:
    ctx->pc = 0x80136360u;
    // 80136360: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_80136364:
    ctx->pc = 0x80136364u;
    // 80136364: bl      0x8004DC00
    {
            ctx->lr = 0x80136368u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136368:
    ctx->pc = 0x80136368u;
    ctx->downcount -= 3;
    // 80136368: lwz     r0, -27052(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27052);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013636C:
    ctx->pc = 0x8013636Cu;
    // 8013636C: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136370:
    ctx->pc = 0x80136370u;
    // 80136370: bl      0x800B7A5C
    {
            ctx->lr = 0x80136374u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80136374:
    ctx->pc = 0x80136374u;
    ctx->downcount -= 9;
    // 80136374: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80136378:
    ctx->pc = 0x80136378u;
    // 80136378: li      r0, 80
    ctx->gpr[0] = (u32)(s32)(80);

label_8013637C:
    ctx->pc = 0x8013637Cu;
    // 8013637C: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80136380:
    ctx->pc = 0x80136380u;
    // 80136380: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_80136384:
    ctx->pc = 0x80136384u;
    // 80136384: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_80136388:
    ctx->pc = 0x80136388u;
    // 80136388: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8013638C:
    ctx->pc = 0x8013638Cu;
    // 8013638C: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136390:
    ctx->pc = 0x80136390u;
    // 80136390: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_80136394:
    ctx->pc = 0x80136394u;
    // 80136394: b       0x80136D64
    {
            goto label_80136D64;
    }

label_80136398:
    ctx->pc = 0x80136398u;
    ctx->downcount -= 26;
    // 80136398: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8013639C:
    ctx->pc = 0x8013639Cu;
    // 8013639C: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_801363A0:
    ctx->pc = 0x801363A0u;
    // 801363A0: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801363A4:
    ctx->pc = 0x801363A4u;
    // 801363A4: lwz     r6, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801363A8:
    ctx->pc = 0x801363A8u;
    // 801363A8: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801363AC:
    ctx->pc = 0x801363ACu;
    // 801363AC: lwz     r11, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801363B0:
    ctx->pc = 0x801363B0u;
    // 801363B0: lwz     r4, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801363B4:
    ctx->pc = 0x801363B4u;
    // 801363B4: xor   r31, r0, r7
    {
        ctx->gpr[31] = ctx->gpr[0] ^ ctx->gpr[7];
    }

label_801363B8:
    ctx->pc = 0x801363B8u;
    // 801363B8: lwz     r5, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801363BC:
    ctx->pc = 0x801363BCu;
    // 801363BC: xor   r3, r11, r6
    {
        ctx->gpr[3] = ctx->gpr[11] ^ ctx->gpr[6];
    }

label_801363C0:
    ctx->pc = 0x801363C0u;
    // 801363C0: lwz     r10, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801363C4:
    ctx->pc = 0x801363C4u;
    // 801363C4: rlwinm r0, r3, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00010000u;
    }

label_801363C8:
    ctx->pc = 0x801363C8u;
    // 801363C8: lwz     r8, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801363CC:
    ctx->pc = 0x801363CCu;
    // 801363CC: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_801363D0:
    ctx->pc = 0x801363D0u;
    // 801363D0: rlwinm r9, r31, 0, 15, 15
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00010000u;
    }

label_801363D4:
    ctx->pc = 0x801363D4u;
    // 801363D4: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_801363D8:
    ctx->pc = 0x801363D8u;
    // 801363D8: and   r9, r9, r7
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[7];
    }

label_801363DC:
    ctx->pc = 0x801363DCu;
    // 801363DC: xor   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[4];
    }

label_801363E0:
    ctx->pc = 0x801363E0u;
    // 801363E0: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_801363E4:
    ctx->pc = 0x801363E4u;
    // 801363E4: rlwinm r11, r10, 0, 15, 15
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00010000u;
    }

label_801363E8:
    ctx->pc = 0x801363E8u;
    // 801363E8: and   r11, r11, r5
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[5];
    }

label_801363EC:
    ctx->pc = 0x801363ECu;
    // 801363EC: rlwinm r0, r8, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00010000u;
    }

label_801363F0:
    ctx->pc = 0x801363F0u;
    // 801363F0: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_801363F4:
    ctx->pc = 0x801363F4u;
    // 801363F4: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_801363F8:
    ctx->pc = 0x801363F8u;
    // 801363F8: or.   r11, r9, r0
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

label_801363FC:
    ctx->pc = 0x801363FCu;
    // 801363FC: bc    12, 2, 0x8013645C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013645C;
        }
    }

label_80136400:
    ctx->pc = 0x80136400u;
    ctx->downcount -= 5;
    // 80136400: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136404:
    ctx->pc = 0x80136404u;
    // 80136404: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136408:
    ctx->pc = 0x80136408u;
    // 80136408: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136408u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013640C:
    ctx->pc = 0x8013640Cu;
    // 8013640C: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_80136410:
    ctx->pc = 0x80136410u;
    // 80136410: bl      0x8004DC00
    {
            ctx->lr = 0x80136414u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136414:
    ctx->pc = 0x80136414u;
    ctx->downcount -= 2;
    // 80136414: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80136418:
    ctx->pc = 0x80136418u;
    // 80136418: li      r11, -1
    ctx->gpr[11] = (u32)(s32)(-1);

label_8013641C:
    ctx->pc = 0x8013641Cu;
    ctx->downcount -= 7;
    // 8013641C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80136420:
    ctx->pc = 0x80136420u;
    // 80136420: lwz     r3, -27076(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27076);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80136424:
    ctx->pc = 0x80136424u;
    // 80136424: stw     r0, 11832(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(11832);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136428:
    ctx->pc = 0x80136428u;
    // 80136428: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_8013642C:
    ctx->pc = 0x8013642Cu;
    // 8013642C: stw     r11, -27920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27920);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80136430:
    ctx->pc = 0x80136430u;
    // 80136430: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80136434:
    ctx->pc = 0x80136434u;
    // 80136434: bl      0x800B7D14
    {
            ctx->lr = 0x80136438u;
            ctx->pc = 0x800B7D14u;
            return;
    }

label_80136438:
    ctx->pc = 0x80136438u;
    ctx->downcount -= 4;
    // 80136438: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_8013643C:
    ctx->pc = 0x8013643Cu;
    // 8013643C: li      r4, 250
    ctx->gpr[4] = (u32)(s32)(250);

label_80136440:
    ctx->pc = 0x80136440u;
    // 80136440: addi    r3, r3, -27148
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27148);

label_80136444:
    ctx->pc = 0x80136444u;
    // 80136444: bl      0x8001776C
    {
            ctx->lr = 0x80136448u;
            ctx->pc = 0x8001776Cu;
            return;
    }

label_80136448:
    ctx->pc = 0x80136448u;
    ctx->downcount -= 2;
    // 80136448: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8013644C:
    ctx->pc = 0x8013644Cu;
    // 8013644C: bl      0x8005B7BC
    {
            ctx->lr = 0x80136450u;
            ctx->pc = 0x8005B7BCu;
            return;
    }

label_80136450:
    ctx->pc = 0x80136450u;
    ctx->downcount -= 3;
    // 80136450: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80136454:
    ctx->pc = 0x80136454u;
    // 80136454: stw     r0, -32360(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32360);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136458:
    ctx->pc = 0x80136458u;
    // 80136458: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_8013645C:
    ctx->pc = 0x8013645Cu;
    ctx->downcount -= 12;
    // 8013645C: rlwinm r9, r31, 0, 14, 14
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00020000u;
    }

label_80136460:
    ctx->pc = 0x80136460u;
    // 80136460: rlwinm r0, r3, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00020000u;
    }

label_80136464:
    ctx->pc = 0x80136464u;
    // 80136464: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_80136468:
    ctx->pc = 0x80136468u;
    // 80136468: and   r9, r9, r7
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[7];
    }

label_8013646C:
    ctx->pc = 0x8013646Cu;
    // 8013646C: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_80136470:
    ctx->pc = 0x80136470u;
    // 80136470: rlwinm r11, r10, 0, 14, 14
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00020000u;
    }

label_80136474:
    ctx->pc = 0x80136474u;
    // 80136474: and   r11, r11, r5
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[5];
    }

label_80136478:
    ctx->pc = 0x80136478u;
    // 80136478: rlwinm r0, r8, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00020000u;
    }

label_8013647C:
    ctx->pc = 0x8013647Cu;
    // 8013647C: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_80136480:
    ctx->pc = 0x80136480u;
    // 80136480: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_80136484:
    ctx->pc = 0x80136484u;
    // 80136484: or.   r6, r9, r0
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136488:
    ctx->pc = 0x80136488u;
    // 80136488: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_8013648C:
    ctx->pc = 0x8013648Cu;
    ctx->downcount -= 5;
    // 8013648C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136490:
    ctx->pc = 0x80136490u;
    // 80136490: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136494:
    ctx->pc = 0x80136494u;
    // 80136494: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136494u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136498:
    ctx->pc = 0x80136498u;
    // 80136498: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_8013649C:
    ctx->pc = 0x8013649Cu;
    // 8013649C: bl      0x8004DC00
    {
            ctx->lr = 0x801364A0u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801364A0:
    ctx->pc = 0x801364A0u;
    ctx->downcount -= 3;
    // 801364A0: li      r0, 3
    ctx->gpr[0] = (u32)(s32)(3);

label_801364A4:
    ctx->pc = 0x801364A4u;
    // 801364A4: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801364A8:
    ctx->pc = 0x801364A8u;
    // 801364A8: bl      0x800B7A5C
    {
            ctx->lr = 0x801364ACu;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_801364AC:
    ctx->pc = 0x801364ACu;
    ctx->downcount -= 9;
    // 801364AC: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_801364B0:
    ctx->pc = 0x801364B0u;
    // 801364B0: li      r0, 80
    ctx->gpr[0] = (u32)(s32)(80);

label_801364B4:
    ctx->pc = 0x801364B4u;
    // 801364B4: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_801364B8:
    ctx->pc = 0x801364B8u;
    // 801364B8: li      r7, 10
    ctx->gpr[7] = (u32)(s32)(10);

label_801364BC:
    ctx->pc = 0x801364BCu;
    // 801364BC: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_801364C0:
    ctx->pc = 0x801364C0u;
    // 801364C0: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801364C4:
    ctx->pc = 0x801364C4u;
    // 801364C4: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801364C8:
    ctx->pc = 0x801364C8u;
    // 801364C8: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_801364CC:
    ctx->pc = 0x801364CCu;
    // 801364CC: b       0x80136D64
    {
            goto label_80136D64;
    }

label_801364D0:
    ctx->pc = 0x801364D0u;
    ctx->downcount -= 3;
    // 801364D0: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801364D4:
    ctx->pc = 0x801364D4u;
    // 801364D4: cmpwi   r0, 4
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

label_801364D8:
    ctx->pc = 0x801364D8u;
    // 801364D8: bc    12, 2, 0x801364E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801364E8;
        }
    }

label_801364DC:
    ctx->pc = 0x801364DCu;
    ctx->downcount -= 2;
    // 801364DC: cmpwi   r0, 5
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

label_801364E0:
    ctx->pc = 0x801364E0u;
    // 801364E0: bc    12, 2, 0x80136714
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136714;
        }
    }

label_801364E4:
    ctx->pc = 0x801364E4u;
    ctx->downcount -= 1;
    // 801364E4: b       0x8013693C
    {
            goto label_8013693C;
    }

label_801364E8:
    ctx->pc = 0x801364E8u;
    ctx->downcount -= 11;
    // 801364E8: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_801364EC:
    ctx->pc = 0x801364ECu;
    // 801364EC: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_801364F0:
    ctx->pc = 0x801364F0u;
    // 801364F0: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801364F4:
    ctx->pc = 0x801364F4u;
    // 801364F4: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801364F8:
    ctx->pc = 0x801364F8u;
    // 801364F8: lwz     r8, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801364FC:
    ctx->pc = 0x801364FCu;
    // 801364FC: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_80136500:
    ctx->pc = 0x80136500u;
    // 80136500: lwz     r10, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136504:
    ctx->pc = 0x80136504u;
    // 80136504: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_80136508:
    ctx->pc = 0x80136508u;
    // 80136508: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_8013650C:
    ctx->pc = 0x8013650Cu;
    // 8013650C: andis.  r6, r0, 0x0040
    {
        ctx->gpr[6] = ctx->gpr[0] & (0x0040u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136510:
    ctx->pc = 0x80136510u;
    // 80136510: bc    12, 2, 0x80136554
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136554;
        }
    }

label_80136514:
    ctx->pc = 0x80136514u;
    ctx->downcount -= 3;
    // 80136514: lwz     r0, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136518:
    ctx->pc = 0x80136518u;
    // 80136518: cmpwi   r0, 0
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

label_8013651C:
    ctx->pc = 0x8013651Cu;
    // 8013651C: bc    12, 2, 0x80136540
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136540;
        }
    }

label_80136520:
    ctx->pc = 0x80136520u;
    ctx->downcount -= 3;
    // 80136520: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80136524:
    ctx->pc = 0x80136524u;
    // 80136524: cmpwi   r0, 0
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

label_80136528:
    ctx->pc = 0x80136528u;
    // 80136528: bc    4, 2, 0x80136540
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136540;
        }
    }

label_8013652C:
    ctx->pc = 0x8013652Cu;
    ctx->downcount -= 5;
    // 8013652C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136530:
    ctx->pc = 0x80136530u;
    // 80136530: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136534:
    ctx->pc = 0x80136534u;
    // 80136534: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136534u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136538:
    ctx->pc = 0x80136538u;
    // 80136538: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8013653C:
    ctx->pc = 0x8013653Cu;
    // 8013653C: bl      0x8004DC00
    {
            ctx->lr = 0x80136540u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136540:
    ctx->pc = 0x80136540u;
    ctx->downcount -= 5;
    // 80136540: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80136544:
    ctx->pc = 0x80136544u;
    // 80136544: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_80136548:
    ctx->pc = 0x80136548u;
    // 80136548: lwz     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013654C:
    ctx->pc = 0x8013654Cu;
    // 8013654C: addi    r9, r9, -64
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-64);

label_80136550:
    ctx->pc = 0x80136550u;
    // 80136550: stw     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80136554:
    ctx->pc = 0x80136554u;
    ctx->downcount -= 11;
    // 80136554: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136558:
    ctx->pc = 0x80136558u;
    // 80136558: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8013655C:
    ctx->pc = 0x8013655Cu;
    // 8013655C: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136560:
    ctx->pc = 0x80136560u;
    // 80136560: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136564:
    ctx->pc = 0x80136564u;
    // 80136564: lwz     r8, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136568:
    ctx->pc = 0x80136568u;
    // 80136568: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_8013656C:
    ctx->pc = 0x8013656Cu;
    // 8013656C: lwz     r10, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136570:
    ctx->pc = 0x80136570u;
    // 80136570: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_80136574:
    ctx->pc = 0x80136574u;
    // 80136574: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_80136578:
    ctx->pc = 0x80136578u;
    // 80136578: andis.  r6, r0, 0x0080
    {
        ctx->gpr[6] = ctx->gpr[0] & (0x0080u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8013657C:
    ctx->pc = 0x8013657Cu;
    // 8013657C: bc    12, 2, 0x801365C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801365C4;
        }
    }

label_80136580:
    ctx->pc = 0x80136580u;
    ctx->downcount -= 4;
    // 80136580: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80136584:
    ctx->pc = 0x80136584u;
    // 80136584: lwz     r0, -21608(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21608);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136588:
    ctx->pc = 0x80136588u;
    // 80136588: cmpwi   r0, 25600
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(25600);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8013658C:
    ctx->pc = 0x8013658Cu;
    // 8013658C: bc    12, 2, 0x801365B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801365B0;
        }
    }

label_80136590:
    ctx->pc = 0x80136590u;
    ctx->downcount -= 3;
    // 80136590: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80136594:
    ctx->pc = 0x80136594u;
    // 80136594: cmpwi   r0, 0
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

label_80136598:
    ctx->pc = 0x80136598u;
    // 80136598: bc    4, 2, 0x801365B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801365B0;
        }
    }

label_8013659C:
    ctx->pc = 0x8013659Cu;
    ctx->downcount -= 5;
    // 8013659C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801365A0:
    ctx->pc = 0x801365A0u;
    // 801365A0: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_801365A4:
    ctx->pc = 0x801365A4u;
    // 801365A4: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x801365A4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801365A8:
    ctx->pc = 0x801365A8u;
    // 801365A8: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_801365AC:
    ctx->pc = 0x801365ACu;
    // 801365AC: bl      0x8004DC00
    {
            ctx->lr = 0x801365B0u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801365B0:
    ctx->pc = 0x801365B0u;
    ctx->downcount -= 5;
    // 801365B0: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_801365B4:
    ctx->pc = 0x801365B4u;
    // 801365B4: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_801365B8:
    ctx->pc = 0x801365B8u;
    // 801365B8: lwz     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801365BC:
    ctx->pc = 0x801365BCu;
    // 801365BC: addi    r9, r9, 64
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(64);

label_801365C0:
    ctx->pc = 0x801365C0u;
    // 801365C0: stw     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801365C4:
    ctx->pc = 0x801365C4u;
    ctx->downcount -= 11;
    // 801365C4: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_801365C8:
    ctx->pc = 0x801365C8u;
    // 801365C8: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_801365CC:
    ctx->pc = 0x801365CCu;
    // 801365CC: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801365D0:
    ctx->pc = 0x801365D0u;
    // 801365D0: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801365D4:
    ctx->pc = 0x801365D4u;
    // 801365D4: lwz     r8, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801365D8:
    ctx->pc = 0x801365D8u;
    // 801365D8: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_801365DC:
    ctx->pc = 0x801365DCu;
    // 801365DC: lwz     r10, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801365E0:
    ctx->pc = 0x801365E0u;
    // 801365E0: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_801365E4:
    ctx->pc = 0x801365E4u;
    // 801365E4: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_801365E8:
    ctx->pc = 0x801365E8u;
    // 801365E8: andi.   r6, r0, 0x0004
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801365EC:
    ctx->pc = 0x801365ECu;
    // 801365EC: bc    12, 2, 0x80136634
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136634;
        }
    }

label_801365F0:
    ctx->pc = 0x801365F0u;
    ctx->downcount -= 4;
    // 801365F0: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_801365F4:
    ctx->pc = 0x801365F4u;
    // 801365F4: lwz     r0, -21608(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21608);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801365F8:
    ctx->pc = 0x801365F8u;
    // 801365F8: cmpwi   r0, 0
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

label_801365FC:
    ctx->pc = 0x801365FCu;
    // 801365FC: bc    12, 2, 0x80136620
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136620;
        }
    }

label_80136600:
    ctx->pc = 0x80136600u;
    ctx->downcount -= 3;
    // 80136600: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80136604:
    ctx->pc = 0x80136604u;
    // 80136604: cmpwi   r0, 0
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

label_80136608:
    ctx->pc = 0x80136608u;
    // 80136608: bc    4, 2, 0x80136620
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136620;
        }
    }

label_8013660C:
    ctx->pc = 0x8013660Cu;
    ctx->downcount -= 5;
    // 8013660C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136610:
    ctx->pc = 0x80136610u;
    // 80136610: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136614:
    ctx->pc = 0x80136614u;
    // 80136614: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136614u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136618:
    ctx->pc = 0x80136618u;
    // 80136618: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8013661C:
    ctx->pc = 0x8013661Cu;
    // 8013661C: bl      0x8004DC00
    {
            ctx->lr = 0x80136620u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136620:
    ctx->pc = 0x80136620u;
    ctx->downcount -= 5;
    // 80136620: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80136624:
    ctx->pc = 0x80136624u;
    // 80136624: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_80136628:
    ctx->pc = 0x80136628u;
    // 80136628: lwz     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013662C:
    ctx->pc = 0x8013662Cu;
    // 8013662C: addi    r9, r9, -64
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-64);

label_80136630:
    ctx->pc = 0x80136630u;
    // 80136630: stw     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80136634:
    ctx->pc = 0x80136634u;
    ctx->downcount -= 11;
    // 80136634: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136638:
    ctx->pc = 0x80136638u;
    // 80136638: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8013663C:
    ctx->pc = 0x8013663Cu;
    // 8013663C: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136640:
    ctx->pc = 0x80136640u;
    // 80136640: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136644:
    ctx->pc = 0x80136644u;
    // 80136644: lwz     r8, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136648:
    ctx->pc = 0x80136648u;
    // 80136648: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_8013664C:
    ctx->pc = 0x8013664Cu;
    // 8013664C: lwz     r10, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136650:
    ctx->pc = 0x80136650u;
    // 80136650: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_80136654:
    ctx->pc = 0x80136654u;
    // 80136654: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_80136658:
    ctx->pc = 0x80136658u;
    // 80136658: andi.   r6, r0, 0x0008
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8013665C:
    ctx->pc = 0x8013665Cu;
    // 8013665C: bc    12, 2, 0x801366A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801366A4;
        }
    }

label_80136660:
    ctx->pc = 0x80136660u;
    ctx->downcount -= 4;
    // 80136660: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80136664:
    ctx->pc = 0x80136664u;
    // 80136664: lwz     r0, -21608(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21608);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136668:
    ctx->pc = 0x80136668u;
    // 80136668: cmpwi   r0, 25600
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(25600);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8013666C:
    ctx->pc = 0x8013666Cu;
    // 8013666C: bc    12, 2, 0x80136690
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136690;
        }
    }

label_80136670:
    ctx->pc = 0x80136670u;
    ctx->downcount -= 3;
    // 80136670: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80136674:
    ctx->pc = 0x80136674u;
    // 80136674: cmpwi   r0, 0
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

label_80136678:
    ctx->pc = 0x80136678u;
    // 80136678: bc    4, 2, 0x80136690
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136690;
        }
    }

label_8013667C:
    ctx->pc = 0x8013667Cu;
    ctx->downcount -= 5;
    // 8013667C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136680:
    ctx->pc = 0x80136680u;
    // 80136680: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136684:
    ctx->pc = 0x80136684u;
    // 80136684: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136684u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136688:
    ctx->pc = 0x80136688u;
    // 80136688: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8013668C:
    ctx->pc = 0x8013668Cu;
    // 8013668C: bl      0x8004DC00
    {
            ctx->lr = 0x80136690u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136690:
    ctx->pc = 0x80136690u;
    ctx->downcount -= 5;
    // 80136690: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80136694:
    ctx->pc = 0x80136694u;
    // 80136694: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_80136698:
    ctx->pc = 0x80136698u;
    // 80136698: lwz     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8013669C:
    ctx->pc = 0x8013669Cu;
    // 8013669C: addi    r9, r9, 64
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(64);

label_801366A0:
    ctx->pc = 0x801366A0u;
    // 801366A0: stw     r9, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801366A4:
    ctx->pc = 0x801366A4u;
    ctx->downcount -= 5;
    // 801366A4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_801366A8:
    ctx->pc = 0x801366A8u;
    // 801366A8: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_801366AC:
    ctx->pc = 0x801366ACu;
    // 801366AC: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801366B0:
    ctx->pc = 0x801366B0u;
    // 801366B0: cmpwi   r0, 0
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

label_801366B4:
    ctx->pc = 0x801366B4u;
    // 801366B4: bc    4, 0, 0x801366C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801366C0;
        }
    }

label_801366B8:
    ctx->pc = 0x801366B8u;
    ctx->downcount -= 2;
    // 801366B8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801366BC:
    ctx->pc = 0x801366BCu;
    // 801366BC: stw     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801366C0:
    ctx->pc = 0x801366C0u;
    ctx->downcount -= 3;
    // 801366C0: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801366C4:
    ctx->pc = 0x801366C4u;
    // 801366C4: cmpwi   r0, 25600
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(25600);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801366C8:
    ctx->pc = 0x801366C8u;
    // 801366C8: bc    4, 1, 0x801366D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801366D4;
        }
    }

label_801366CC:
    ctx->pc = 0x801366CCu;
    ctx->downcount -= 2;
    // 801366CC: li      r0, 25600
    ctx->gpr[0] = (u32)(s32)(25600);

label_801366D0:
    ctx->pc = 0x801366D0u;
    // 801366D0: stw     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801366D4:
    ctx->pc = 0x801366D4u;
    ctx->downcount -= 31;
    // 801366D4: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801366D8:
    ctx->pc = 0x801366D8u;
    // 801366D8: lis     r10, 17200
    ctx->gpr[10] = ((u32)(s32)(17200) << 16);

label_801366DC:
    ctx->pc = 0x801366DCu;
    // 801366DC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801366E0:
    ctx->pc = 0x801366E0u;
    // 801366E0: srawi r0, r0, 8
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

label_801366E4:
    ctx->pc = 0x801366E4u;
    // 801366E4: lfd     f0, 5928(r9)
    if (!ppc_fp_available(ctx, 0x801366E4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5928);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_801366E8:
    ctx->pc = 0x801366E8u;
    // 801366E8: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_801366EC:
    ctx->pc = 0x801366ECu;
    // 801366EC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801366F0:
    ctx->pc = 0x801366F0u;
    // 801366F0: stw     r0, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801366F4:
    ctx->pc = 0x801366F4u;
    // 801366F4: lfs     f13, 6004(r9)
    if (!ppc_fp_available(ctx, 0x801366F4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6004);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_801366F8:
    ctx->pc = 0x801366F8u;
    // 801366F8: stw     r10, 18568(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801366FC:
    ctx->pc = 0x801366FCu;
    // 801366FC: lfd     f1, 18568(r1)
    if (!ppc_fp_available(ctx, 0x801366FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136700:
    ctx->pc = 0x80136700u;
    // 80136700: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x80136700u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_80136704:
    ctx->pc = 0x80136704u;
    // 80136704: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x80136704u)) return;
    ppc_frsp(ctx, 1, 1);

label_80136708:
    ctx->pc = 0x80136708u;
    // 80136708: fdivs   f1, f1, f13
    if (!ppc_fp_available(ctx, 0x80136708u)) return;
    ppc_fdivs(ctx, 1, 1, 13);

label_8013670C:
    ctx->pc = 0x8013670Cu;
    // 8013670C: bl      0x8004EDD0
    {
            ctx->lr = 0x80136710u;
            ctx->pc = 0x8004EDD0u;
            return;
    }

label_80136710:
    ctx->pc = 0x80136710u;
    ctx->downcount -= 1;
    // 80136710: b       0x8013693C
    {
            goto label_8013693C;
    }

label_80136714:
    ctx->pc = 0x80136714u;
    ctx->downcount -= 11;
    // 80136714: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136718:
    ctx->pc = 0x80136718u;
    // 80136718: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8013671C:
    ctx->pc = 0x8013671Cu;
    // 8013671C: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136720:
    ctx->pc = 0x80136720u;
    // 80136720: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136724:
    ctx->pc = 0x80136724u;
    // 80136724: lwz     r8, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136728:
    ctx->pc = 0x80136728u;
    // 80136728: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_8013672C:
    ctx->pc = 0x8013672Cu;
    // 8013672C: lwz     r10, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136730:
    ctx->pc = 0x80136730u;
    // 80136730: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_80136734:
    ctx->pc = 0x80136734u;
    // 80136734: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_80136738:
    ctx->pc = 0x80136738u;
    // 80136738: andis.  r6, r0, 0x0040
    {
        ctx->gpr[6] = ctx->gpr[0] & (0x0040u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8013673C:
    ctx->pc = 0x8013673Cu;
    // 8013673C: bc    12, 2, 0x80136780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136780;
        }
    }

label_80136740:
    ctx->pc = 0x80136740u;
    ctx->downcount -= 3;
    // 80136740: lwz     r0, 32(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136744:
    ctx->pc = 0x80136744u;
    // 80136744: cmpwi   r0, 0
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

label_80136748:
    ctx->pc = 0x80136748u;
    // 80136748: bc    12, 2, 0x8013676C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013676C;
        }
    }

label_8013674C:
    ctx->pc = 0x8013674Cu;
    ctx->downcount -= 3;
    // 8013674C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80136750:
    ctx->pc = 0x80136750u;
    // 80136750: cmpwi   r0, 0
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

label_80136754:
    ctx->pc = 0x80136754u;
    // 80136754: bc    4, 2, 0x8013676C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013676C;
        }
    }

label_80136758:
    ctx->pc = 0x80136758u;
    ctx->downcount -= 5;
    // 80136758: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013675C:
    ctx->pc = 0x8013675Cu;
    // 8013675C: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136760:
    ctx->pc = 0x80136760u;
    // 80136760: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136760u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136764:
    ctx->pc = 0x80136764u;
    // 80136764: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80136768:
    ctx->pc = 0x80136768u;
    // 80136768: bl      0x8004DC00
    {
            ctx->lr = 0x8013676Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8013676C:
    ctx->pc = 0x8013676Cu;
    ctx->downcount -= 5;
    // 8013676C: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80136770:
    ctx->pc = 0x80136770u;
    // 80136770: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_80136774:
    ctx->pc = 0x80136774u;
    // 80136774: lwz     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80136778:
    ctx->pc = 0x80136778u;
    // 80136778: addi    r9, r9, -64
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-64);

label_8013677C:
    ctx->pc = 0x8013677Cu;
    // 8013677C: stw     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80136780:
    ctx->pc = 0x80136780u;
    ctx->downcount -= 11;
    // 80136780: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136784:
    ctx->pc = 0x80136784u;
    // 80136784: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80136788:
    ctx->pc = 0x80136788u;
    // 80136788: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013678C:
    ctx->pc = 0x8013678Cu;
    // 8013678C: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136790:
    ctx->pc = 0x80136790u;
    // 80136790: lwz     r8, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136794:
    ctx->pc = 0x80136794u;
    // 80136794: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_80136798:
    ctx->pc = 0x80136798u;
    // 80136798: lwz     r10, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8013679C:
    ctx->pc = 0x8013679Cu;
    // 8013679C: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_801367A0:
    ctx->pc = 0x801367A0u;
    // 801367A0: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_801367A4:
    ctx->pc = 0x801367A4u;
    // 801367A4: andis.  r6, r0, 0x0080
    {
        ctx->gpr[6] = ctx->gpr[0] & (0x0080u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801367A8:
    ctx->pc = 0x801367A8u;
    // 801367A8: bc    12, 2, 0x801367F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801367F0;
        }
    }

label_801367AC:
    ctx->pc = 0x801367ACu;
    ctx->downcount -= 4;
    // 801367AC: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_801367B0:
    ctx->pc = 0x801367B0u;
    // 801367B0: lwz     r0, -21604(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21604);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801367B4:
    ctx->pc = 0x801367B4u;
    // 801367B4: cmpwi   r0, 25600
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(25600);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801367B8:
    ctx->pc = 0x801367B8u;
    // 801367B8: bc    12, 2, 0x801367DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801367DC;
        }
    }

label_801367BC:
    ctx->pc = 0x801367BCu;
    ctx->downcount -= 3;
    // 801367BC: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_801367C0:
    ctx->pc = 0x801367C0u;
    // 801367C0: cmpwi   r0, 0
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

label_801367C4:
    ctx->pc = 0x801367C4u;
    // 801367C4: bc    4, 2, 0x801367DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801367DC;
        }
    }

label_801367C8:
    ctx->pc = 0x801367C8u;
    ctx->downcount -= 5;
    // 801367C8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801367CC:
    ctx->pc = 0x801367CCu;
    // 801367CC: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_801367D0:
    ctx->pc = 0x801367D0u;
    // 801367D0: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x801367D0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801367D4:
    ctx->pc = 0x801367D4u;
    // 801367D4: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_801367D8:
    ctx->pc = 0x801367D8u;
    // 801367D8: bl      0x8004DC00
    {
            ctx->lr = 0x801367DCu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801367DC:
    ctx->pc = 0x801367DCu;
    ctx->downcount -= 5;
    // 801367DC: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_801367E0:
    ctx->pc = 0x801367E0u;
    // 801367E0: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_801367E4:
    ctx->pc = 0x801367E4u;
    // 801367E4: lwz     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801367E8:
    ctx->pc = 0x801367E8u;
    // 801367E8: addi    r9, r9, 64
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(64);

label_801367EC:
    ctx->pc = 0x801367ECu;
    // 801367EC: stw     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801367F0:
    ctx->pc = 0x801367F0u;
    ctx->downcount -= 11;
    // 801367F0: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_801367F4:
    ctx->pc = 0x801367F4u;
    // 801367F4: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_801367F8:
    ctx->pc = 0x801367F8u;
    // 801367F8: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801367FC:
    ctx->pc = 0x801367FCu;
    // 801367FC: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136800:
    ctx->pc = 0x80136800u;
    // 80136800: lwz     r8, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136804:
    ctx->pc = 0x80136804u;
    // 80136804: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_80136808:
    ctx->pc = 0x80136808u;
    // 80136808: lwz     r10, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8013680C:
    ctx->pc = 0x8013680Cu;
    // 8013680C: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_80136810:
    ctx->pc = 0x80136810u;
    // 80136810: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_80136814:
    ctx->pc = 0x80136814u;
    // 80136814: andi.   r6, r0, 0x0004
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136818:
    ctx->pc = 0x80136818u;
    // 80136818: bc    12, 2, 0x80136860
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136860;
        }
    }

label_8013681C:
    ctx->pc = 0x8013681Cu;
    ctx->downcount -= 4;
    // 8013681C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80136820:
    ctx->pc = 0x80136820u;
    // 80136820: lwz     r0, -21604(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21604);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136824:
    ctx->pc = 0x80136824u;
    // 80136824: cmpwi   r0, 0
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

label_80136828:
    ctx->pc = 0x80136828u;
    // 80136828: bc    12, 2, 0x8013684C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013684C;
        }
    }

label_8013682C:
    ctx->pc = 0x8013682Cu;
    ctx->downcount -= 3;
    // 8013682C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80136830:
    ctx->pc = 0x80136830u;
    // 80136830: cmpwi   r0, 0
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

label_80136834:
    ctx->pc = 0x80136834u;
    // 80136834: bc    4, 2, 0x8013684C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013684C;
        }
    }

label_80136838:
    ctx->pc = 0x80136838u;
    ctx->downcount -= 5;
    // 80136838: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013683C:
    ctx->pc = 0x8013683Cu;
    // 8013683C: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136840:
    ctx->pc = 0x80136840u;
    // 80136840: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136840u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136844:
    ctx->pc = 0x80136844u;
    // 80136844: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_80136848:
    ctx->pc = 0x80136848u;
    // 80136848: bl      0x8004DC00
    {
            ctx->lr = 0x8013684Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8013684C:
    ctx->pc = 0x8013684Cu;
    ctx->downcount -= 5;
    // 8013684C: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80136850:
    ctx->pc = 0x80136850u;
    // 80136850: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_80136854:
    ctx->pc = 0x80136854u;
    // 80136854: lwz     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80136858:
    ctx->pc = 0x80136858u;
    // 80136858: addi    r9, r9, -64
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-64);

label_8013685C:
    ctx->pc = 0x8013685Cu;
    // 8013685C: stw     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80136860:
    ctx->pc = 0x80136860u;
    ctx->downcount -= 11;
    // 80136860: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136864:
    ctx->pc = 0x80136864u;
    // 80136864: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80136868:
    ctx->pc = 0x80136868u;
    // 80136868: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013686C:
    ctx->pc = 0x8013686Cu;
    // 8013686C: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136870:
    ctx->pc = 0x80136870u;
    // 80136870: lwz     r8, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136874:
    ctx->pc = 0x80136874u;
    // 80136874: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_80136878:
    ctx->pc = 0x80136878u;
    // 80136878: lwz     r10, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8013687C:
    ctx->pc = 0x8013687Cu;
    // 8013687C: or   r0, r0, r8
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[8];
    }

label_80136880:
    ctx->pc = 0x80136880u;
    // 80136880: or   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[10];
    }

label_80136884:
    ctx->pc = 0x80136884u;
    // 80136884: andi.   r6, r0, 0x0008
    {
        ctx->gpr[6] = ctx->gpr[0] & 0x0008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136888:
    ctx->pc = 0x80136888u;
    // 80136888: bc    12, 2, 0x801368D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801368D0;
        }
    }

label_8013688C:
    ctx->pc = 0x8013688Cu;
    ctx->downcount -= 4;
    // 8013688C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80136890:
    ctx->pc = 0x80136890u;
    // 80136890: lwz     r0, -21604(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21604);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136894:
    ctx->pc = 0x80136894u;
    // 80136894: cmpwi   r0, 25600
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(25600);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80136898:
    ctx->pc = 0x80136898u;
    // 80136898: bc    12, 2, 0x801368BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801368BC;
        }
    }

label_8013689C:
    ctx->pc = 0x8013689Cu;
    ctx->downcount -= 3;
    // 8013689C: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_801368A0:
    ctx->pc = 0x801368A0u;
    // 801368A0: cmpwi   r0, 0
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

label_801368A4:
    ctx->pc = 0x801368A4u;
    // 801368A4: bc    4, 2, 0x801368BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801368BC;
        }
    }

label_801368A8:
    ctx->pc = 0x801368A8u;
    ctx->downcount -= 5;
    // 801368A8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_801368AC:
    ctx->pc = 0x801368ACu;
    // 801368AC: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_801368B0:
    ctx->pc = 0x801368B0u;
    // 801368B0: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x801368B0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801368B4:
    ctx->pc = 0x801368B4u;
    // 801368B4: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_801368B8:
    ctx->pc = 0x801368B8u;
    // 801368B8: bl      0x8004DC00
    {
            ctx->lr = 0x801368BCu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_801368BC:
    ctx->pc = 0x801368BCu;
    ctx->downcount -= 5;
    // 801368BC: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_801368C0:
    ctx->pc = 0x801368C0u;
    // 801368C0: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_801368C4:
    ctx->pc = 0x801368C4u;
    // 801368C4: lwz     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801368C8:
    ctx->pc = 0x801368C8u;
    // 801368C8: addi    r9, r9, 64
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(64);

label_801368CC:
    ctx->pc = 0x801368CCu;
    // 801368CC: stw     r9, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801368D0:
    ctx->pc = 0x801368D0u;
    ctx->downcount -= 5;
    // 801368D0: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_801368D4:
    ctx->pc = 0x801368D4u;
    // 801368D4: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_801368D8:
    ctx->pc = 0x801368D8u;
    // 801368D8: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801368DC:
    ctx->pc = 0x801368DCu;
    // 801368DC: cmpwi   r0, 0
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

label_801368E0:
    ctx->pc = 0x801368E0u;
    // 801368E0: bc    4, 0, 0x801368EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801368EC;
        }
    }

label_801368E4:
    ctx->pc = 0x801368E4u;
    ctx->downcount -= 2;
    // 801368E4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801368E8:
    ctx->pc = 0x801368E8u;
    // 801368E8: stw     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801368EC:
    ctx->pc = 0x801368ECu;
    ctx->downcount -= 3;
    // 801368EC: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801368F0:
    ctx->pc = 0x801368F0u;
    // 801368F0: cmpwi   r0, 25600
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(25600);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801368F4:
    ctx->pc = 0x801368F4u;
    // 801368F4: bc    4, 1, 0x80136900
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136900;
        }
    }

label_801368F8:
    ctx->pc = 0x801368F8u;
    ctx->downcount -= 2;
    // 801368F8: li      r0, 25600
    ctx->gpr[0] = (u32)(s32)(25600);

label_801368FC:
    ctx->pc = 0x801368FCu;
    // 801368FC: stw     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136900:
    ctx->pc = 0x80136900u;
    ctx->downcount -= 31;
    // 80136900: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136904:
    ctx->pc = 0x80136904u;
    // 80136904: lis     r10, 17200
    ctx->gpr[10] = ((u32)(s32)(17200) << 16);

label_80136908:
    ctx->pc = 0x80136908u;
    // 80136908: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013690C:
    ctx->pc = 0x8013690Cu;
    // 8013690C: srawi r0, r0, 8
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

label_80136910:
    ctx->pc = 0x80136910u;
    // 80136910: lfd     f0, 5928(r9)
    if (!ppc_fp_available(ctx, 0x80136910u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5928);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136914:
    ctx->pc = 0x80136914u;
    // 80136914: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_80136918:
    ctx->pc = 0x80136918u;
    // 80136918: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_8013691C:
    ctx->pc = 0x8013691Cu;
    // 8013691C: stw     r0, 18572(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18572);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136920:
    ctx->pc = 0x80136920u;
    // 80136920: lfs     f13, 6004(r9)
    if (!ppc_fp_available(ctx, 0x80136920u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6004);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_80136924:
    ctx->pc = 0x80136924u;
    // 80136924: stw     r10, 18568(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80136928:
    ctx->pc = 0x80136928u;
    // 80136928: lfd     f1, 18568(r1)
    if (!ppc_fp_available(ctx, 0x80136928u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18568);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8013692C:
    ctx->pc = 0x8013692Cu;
    // 8013692C: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x8013692Cu)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_80136930:
    ctx->pc = 0x80136930u;
    // 80136930: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x80136930u)) return;
    ppc_frsp(ctx, 1, 1);

label_80136934:
    ctx->pc = 0x80136934u;
    // 80136934: fdivs   f1, f1, f13
    if (!ppc_fp_available(ctx, 0x80136934u)) return;
    ppc_fdivs(ctx, 1, 1, 13);

label_80136938:
    ctx->pc = 0x80136938u;
    // 80136938: bl      0x8004EDB8
    {
            ctx->lr = 0x8013693Cu;
            ctx->pc = 0x8004EDB8u;
            return;
    }

label_8013693C:
    ctx->pc = 0x8013693Cu;
    ctx->downcount -= 8;
    // 8013693C: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136940:
    ctx->pc = 0x80136940u;
    // 80136940: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80136944:
    ctx->pc = 0x80136944u;
    // 80136944: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136948:
    ctx->pc = 0x80136948u;
    // 80136948: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013694C:
    ctx->pc = 0x8013694Cu;
    // 8013694C: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_80136950:
    ctx->pc = 0x80136950u;
    // 80136950: rlwinm r0, r0, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00010000u;
    }

label_80136954:
    ctx->pc = 0x80136954u;
    // 80136954: and.   r6, r0, r11
    {
        ctx->gpr[6] = ctx->gpr[0] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136958:
    ctx->pc = 0x80136958u;
    // 80136958: bc    12, 2, 0x80136A1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136A1C;
        }
    }

label_8013695C:
    ctx->pc = 0x8013695Cu;
    ctx->downcount -= 5;
    // 8013695C: lis     r31, -32737
    ctx->gpr[31] = ((u32)(s32)(-32737) << 16);

label_80136960:
    ctx->pc = 0x80136960u;
    // 80136960: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136964:
    ctx->pc = 0x80136964u;
    // 80136964: lfs     f1, 5896(r31)
    if (!ppc_fp_available(ctx, 0x80136964u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136968:
    ctx->pc = 0x80136968u;
    // 80136968: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_8013696C:
    ctx->pc = 0x8013696Cu;
    // 8013696C: bl      0x8004DC00
    {
            ctx->lr = 0x80136970u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136970:
    ctx->pc = 0x80136970u;
    ctx->downcount -= 3;
    // 80136970: lwz     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136974:
    ctx->pc = 0x80136974u;
    // 80136974: cmpwi   r0, 1
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

label_80136978:
    ctx->pc = 0x80136978u;
    // 80136978: bc    12, 2, 0x801369BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801369BC;
        }
    }

label_8013697C:
    ctx->pc = 0x8013697Cu;
    ctx->downcount -= 1;
    // 8013697C: bc    12, 1, 0x8013698C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013698C;
        }
    }

label_80136980:
    ctx->pc = 0x80136980u;
    ctx->downcount -= 2;
    // 80136980: cmpwi   r0, 0
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

label_80136984:
    ctx->pc = 0x80136984u;
    // 80136984: bc    12, 2, 0x801369A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801369A0;
        }
    }

label_80136988:
    ctx->pc = 0x80136988u;
    ctx->downcount -= 1;
    // 80136988: b       0x80136A1C
    {
            goto label_80136A1C;
    }

label_8013698C:
    ctx->pc = 0x8013698Cu;
    ctx->downcount -= 2;
    // 8013698C: cmpwi   r0, 2
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

label_80136990:
    ctx->pc = 0x80136990u;
    // 80136990: bc    12, 2, 0x801369D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801369D8;
        }
    }

label_80136994:
    ctx->pc = 0x80136994u;
    ctx->downcount -= 2;
    // 80136994: cmpwi   r0, 3
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

label_80136998:
    ctx->pc = 0x80136998u;
    // 80136998: bc    12, 2, 0x80136A08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136A08;
        }
    }

label_8013699C:
    ctx->pc = 0x8013699Cu;
    ctx->downcount -= 1;
    // 8013699C: b       0x80136A1C
    {
            goto label_80136A1C;
    }

label_801369A0:
    ctx->pc = 0x801369A0u;
    ctx->downcount -= 7;
    // 801369A0: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_801369A4:
    ctx->pc = 0x801369A4u;
    // 801369A4: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_801369A8:
    ctx->pc = 0x801369A8u;
    // 801369A8: lhz     r9, 22(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(22);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_801369AC:
    ctx->pc = 0x801369ACu;
    // 801369AC: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801369B0:
    ctx->pc = 0x801369B0u;
    // 801369B0: rlwinm r9, r9, 0, 31, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x00000001u;
    }

label_801369B4:
    ctx->pc = 0x801369B4u;
    // 801369B4: sth     r9, 22(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(22);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_801369B8:
    ctx->pc = 0x801369B8u;
    // 801369B8: b       0x80136A1C
    {
            goto label_80136A1C;
    }

label_801369BC:
    ctx->pc = 0x801369BCu;
    ctx->downcount -= 7;
    // 801369BC: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_801369C0:
    ctx->pc = 0x801369C0u;
    // 801369C0: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_801369C4:
    ctx->pc = 0x801369C4u;
    // 801369C4: lhz     r9, 24(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_801369C8:
    ctx->pc = 0x801369C8u;
    // 801369C8: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801369CC:
    ctx->pc = 0x801369CCu;
    // 801369CC: rlwinm r9, r9, 0, 31, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x00000001u;
    }

label_801369D0:
    ctx->pc = 0x801369D0u;
    // 801369D0: sth     r9, 24(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(24);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_801369D4:
    ctx->pc = 0x801369D4u;
    // 801369D4: b       0x80136A1C
    {
            goto label_80136A1C;
    }

label_801369D8:
    ctx->pc = 0x801369D8u;
    ctx->downcount -= 7;
    // 801369D8: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_801369DC:
    ctx->pc = 0x801369DCu;
    // 801369DC: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_801369E0:
    ctx->pc = 0x801369E0u;
    // 801369E0: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801369E4:
    ctx->pc = 0x801369E4u;
    // 801369E4: xori    r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] ^ 0x0001u;

label_801369E8:
    ctx->pc = 0x801369E8u;
    // 801369E8: or   r3, r0, r0
    {
        ctx->gpr[3] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801369EC:
    ctx->pc = 0x801369ECu;
    // 801369EC: stw     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801369F0:
    ctx->pc = 0x801369F0u;
    // 801369F0: bl      0x80044020
    {
            ctx->lr = 0x801369F4u;
            ctx->pc = 0x80044020u;
            return;
    }

label_801369F4:
    ctx->pc = 0x801369F4u;
    ctx->downcount -= 4;
    // 801369F4: lfs     f1, 5896(r31)
    if (!ppc_fp_available(ctx, 0x801369F4u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801369F8:
    ctx->pc = 0x801369F8u;
    // 801369F8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801369FC:
    ctx->pc = 0x801369FCu;
    // 801369FC: li      r4, 20
    ctx->gpr[4] = (u32)(s32)(20);

label_80136A00:
    ctx->pc = 0x80136A00u;
    // 80136A00: bl      0x8004435C
    {
            ctx->lr = 0x80136A04u;
            ctx->pc = 0x8004435Cu;
            return;
    }

label_80136A04:
    ctx->pc = 0x80136A04u;
    ctx->downcount -= 1;
    // 80136A04: b       0x80136A1C
    {
            goto label_80136A1C;
    }

label_80136A08:
    ctx->pc = 0x80136A08u;
    ctx->downcount -= 5;
    // 80136A08: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80136A0C:
    ctx->pc = 0x80136A0Cu;
    // 80136A0C: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_80136A10:
    ctx->pc = 0x80136A10u;
    // 80136A10: lwz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136A14:
    ctx->pc = 0x80136A14u;
    // 80136A14: xori    r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] ^ 0x0001u;

label_80136A18:
    ctx->pc = 0x80136A18u;
    // 80136A18: stw     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136A1C:
    ctx->pc = 0x80136A1Cu;
    ctx->downcount -= 26;
    // 80136A1C: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136A20:
    ctx->pc = 0x80136A20u;
    // 80136A20: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80136A24:
    ctx->pc = 0x80136A24u;
    // 80136A24: lwz     r6, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80136A28:
    ctx->pc = 0x80136A28u;
    // 80136A28: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80136A2C:
    ctx->pc = 0x80136A2Cu;
    // 80136A2C: lwz     r11, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136A30:
    ctx->pc = 0x80136A30u;
    // 80136A30: lwz     r10, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136A34:
    ctx->pc = 0x80136A34u;
    // 80136A34: lwz     r4, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80136A38:
    ctx->pc = 0x80136A38u;
    // 80136A38: xor   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[7];
    }

label_80136A3C:
    ctx->pc = 0x80136A3Cu;
    // 80136A3C: lwz     r8, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136A40:
    ctx->pc = 0x80136A40u;
    // 80136A40: xor   r10, r10, r6
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[6];
    }

label_80136A44:
    ctx->pc = 0x80136A44u;
    // 80136A44: lwz     r5, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80136A48:
    ctx->pc = 0x80136A48u;
    // 80136A48: rlwinm r11, r11, 0, 14, 14
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00020000u;
    }

label_80136A4C:
    ctx->pc = 0x80136A4Cu;
    // 80136A4C: lwz     r0, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136A50:
    ctx->pc = 0x80136A50u;
    // 80136A50: xor   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[4];
    }

label_80136A54:
    ctx->pc = 0x80136A54u;
    // 80136A54: rlwinm r10, r10, 0, 14, 14
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00020000u;
    }

label_80136A58:
    ctx->pc = 0x80136A58u;
    // 80136A58: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_80136A5C:
    ctx->pc = 0x80136A5Cu;
    // 80136A5C: and   r10, r10, r6
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[6];
    }

label_80136A60:
    ctx->pc = 0x80136A60u;
    // 80136A60: xor   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[5];
    }

label_80136A64:
    ctx->pc = 0x80136A64u;
    // 80136A64: rlwinm r8, r8, 0, 14, 14
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00020000u;
    }

label_80136A68:
    ctx->pc = 0x80136A68u;
    // 80136A68: or   r11, r11, r10
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[10];
    }

label_80136A6C:
    ctx->pc = 0x80136A6Cu;
    // 80136A6C: and   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[4];
    }

label_80136A70:
    ctx->pc = 0x80136A70u;
    // 80136A70: rlwinm r0, r0, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00020000u;
    }

label_80136A74:
    ctx->pc = 0x80136A74u;
    // 80136A74: or   r11, r11, r8
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[8];
    }

label_80136A78:
    ctx->pc = 0x80136A78u;
    // 80136A78: and   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[5];
    }

label_80136A7C:
    ctx->pc = 0x80136A7Cu;
    // 80136A7C: or.   r6, r11, r0
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136A80:
    ctx->pc = 0x80136A80u;
    // 80136A80: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136A84:
    ctx->pc = 0x80136A84u;
    ctx->downcount -= 5;
    // 80136A84: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136A88:
    ctx->pc = 0x80136A88u;
    // 80136A88: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136A8C:
    ctx->pc = 0x80136A8Cu;
    // 80136A8C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136A8Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136A90:
    ctx->pc = 0x80136A90u;
    // 80136A90: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_80136A94:
    ctx->pc = 0x80136A94u;
    // 80136A94: bl      0x8004DC00
    {
            ctx->lr = 0x80136A98u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136A98:
    ctx->pc = 0x80136A98u;
    ctx->downcount -= 3;
    // 80136A98: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80136A9C:
    ctx->pc = 0x80136A9Cu;
    // 80136A9C: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136AA0:
    ctx->pc = 0x80136AA0u;
    // 80136AA0: bl      0x800B7A5C
    {
            ctx->lr = 0x80136AA4u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80136AA4:
    ctx->pc = 0x80136AA4u;
    ctx->downcount -= 13;
    // 80136AA4: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80136AA8:
    ctx->pc = 0x80136AA8u;
    // 80136AA8: li      r10, 56
    ctx->gpr[10] = (u32)(s32)(56);

label_80136AAC:
    ctx->pc = 0x80136AACu;
    // 80136AAC: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80136AB0:
    ctx->pc = 0x80136AB0u;
    // 80136AB0: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80136AB4:
    ctx->pc = 0x80136AB4u;
    // 80136AB4: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_80136AB8:
    ctx->pc = 0x80136AB8u;
    // 80136AB8: lwzx    r7, r9, r10
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[10];
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80136ABC:
    ctx->pc = 0x80136ABCu;
    // 80136ABC: lwzx    r6, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80136AC0:
    ctx->pc = 0x80136AC0u;
    // 80136AC0: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_80136AC4:
    ctx->pc = 0x80136AC4u;
    // 80136AC4: sth     r0, -21584(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80136AC8:
    ctx->pc = 0x80136AC8u;
    // 80136AC8: li      r3, 7
    ctx->gpr[3] = (u32)(s32)(7);

label_80136ACC:
    ctx->pc = 0x80136ACCu;
    // 80136ACC: stw     r7, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80136AD0:
    ctx->pc = 0x80136AD0u;
    // 80136AD0: stw     r6, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80136AD4:
    ctx->pc = 0x80136AD4u;
    // 80136AD4: bl      0x80132E34
    {
            ctx->lr = 0x80136AD8u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80136AD8:
    ctx->pc = 0x80136AD8u;
    ctx->downcount -= 1;
    // 80136AD8: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136ADC:
    ctx->pc = 0x80136ADCu;
    ctx->downcount -= 27;
    // 80136ADC: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136AE0:
    ctx->pc = 0x80136AE0u;
    // 80136AE0: cmpwi   cr7, r20, 0
    {
        s32 val_a = (s32)(ctx->gpr[20]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_80136AE4:
    ctx->pc = 0x80136AE4u;
    // 80136AE4: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80136AE8:
    ctx->pc = 0x80136AE8u;
    // 80136AE8: lwz     r6, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80136AEC:
    ctx->pc = 0x80136AECu;
    // 80136AEC: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80136AF0:
    ctx->pc = 0x80136AF0u;
    // 80136AF0: lwz     r11, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136AF4:
    ctx->pc = 0x80136AF4u;
    // 80136AF4: lwz     r10, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136AF8:
    ctx->pc = 0x80136AF8u;
    // 80136AF8: lwz     r4, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80136AFC:
    ctx->pc = 0x80136AFCu;
    // 80136AFC: xor   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[7];
    }

label_80136B00:
    ctx->pc = 0x80136B00u;
    // 80136B00: lwz     r8, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136B04:
    ctx->pc = 0x80136B04u;
    // 80136B04: xor   r10, r10, r6
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[6];
    }

label_80136B08:
    ctx->pc = 0x80136B08u;
    // 80136B08: lwz     r5, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80136B0C:
    ctx->pc = 0x80136B0Cu;
    // 80136B0C: rlwinm r11, r11, 0, 15, 15
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00010000u;
    }

label_80136B10:
    ctx->pc = 0x80136B10u;
    // 80136B10: lwz     r0, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136B14:
    ctx->pc = 0x80136B14u;
    // 80136B14: xor   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[4];
    }

label_80136B18:
    ctx->pc = 0x80136B18u;
    // 80136B18: rlwinm r10, r10, 0, 15, 15
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00010000u;
    }

label_80136B1C:
    ctx->pc = 0x80136B1Cu;
    // 80136B1C: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_80136B20:
    ctx->pc = 0x80136B20u;
    // 80136B20: and   r10, r10, r6
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[6];
    }

label_80136B24:
    ctx->pc = 0x80136B24u;
    // 80136B24: xor   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[5];
    }

label_80136B28:
    ctx->pc = 0x80136B28u;
    // 80136B28: rlwinm r8, r8, 0, 15, 15
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00010000u;
    }

label_80136B2C:
    ctx->pc = 0x80136B2Cu;
    // 80136B2C: or   r11, r11, r10
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[10];
    }

label_80136B30:
    ctx->pc = 0x80136B30u;
    // 80136B30: and   r8, r8, r4
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[4];
    }

label_80136B34:
    ctx->pc = 0x80136B34u;
    // 80136B34: rlwinm r0, r0, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00010000u;
    }

label_80136B38:
    ctx->pc = 0x80136B38u;
    // 80136B38: or   r11, r11, r8
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[8];
    }

label_80136B3C:
    ctx->pc = 0x80136B3Cu;
    // 80136B3C: and   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[5];
    }

label_80136B40:
    ctx->pc = 0x80136B40u;
    // 80136B40: or.   r6, r11, r0
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136B44:
    ctx->pc = 0x80136B44u;
    // 80136B44: bc    4, 2, 0x80136B4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136B4C;
        }
    }

label_80136B48:
    ctx->pc = 0x80136B48u;
    ctx->downcount -= 1;
    // 80136B48: bc    12, 30, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136B4C:
    ctx->pc = 0x80136B4Cu;
    ctx->downcount -= 1;
    // 80136B4C: bc    4, 30, 0x80136B64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136B64;
        }
    }

label_80136B50:
    ctx->pc = 0x80136B50u;
    ctx->downcount -= 5;
    // 80136B50: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136B54:
    ctx->pc = 0x80136B54u;
    // 80136B54: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136B58:
    ctx->pc = 0x80136B58u;
    // 80136B58: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136B58u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136B5C:
    ctx->pc = 0x80136B5Cu;
    // 80136B5C: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_80136B60:
    ctx->pc = 0x80136B60u;
    // 80136B60: bl      0x8004DC00
    {
            ctx->lr = 0x80136B64u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136B64:
    ctx->pc = 0x80136B64u;
    ctx->downcount -= 14;
    // 80136B64: lwz     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136B68:
    ctx->pc = 0x80136B68u;
    // 80136B68: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_80136B6C:
    ctx->pc = 0x80136B6Cu;
    // 80136B6C: addi    r9, r9, -18004
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-18004);

label_80136B70:
    ctx->pc = 0x80136B70u;
    // 80136B70: lis     r10, -32733
    ctx->gpr[10] = ((u32)(s32)(-32733) << 16);

label_80136B74:
    ctx->pc = 0x80136B74u;
    // 80136B74: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_80136B78:
    ctx->pc = 0x80136B78u;
    // 80136B78: addi    r10, r10, 28576
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(28576);

label_80136B7C:
    ctx->pc = 0x80136B7Cu;
    // 80136B7C: lwzx    r0, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136B80:
    ctx->pc = 0x80136B80u;
    // 80136B80: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80136B84:
    ctx->pc = 0x80136B84u;
    // 80136B84: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_80136B88:
    ctx->pc = 0x80136B88u;
    // 80136B88: lwzx    r9, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80136B8C:
    ctx->pc = 0x80136B8Cu;
    // 80136B8C: stw     r9, 11828(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(11828);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80136B90:
    ctx->pc = 0x80136B90u;
    // 80136B90: bl      0x800C7278
    {
            ctx->lr = 0x80136B94u;
            ctx->pc = 0x800C7278u;
            return;
    }

label_80136B94:
    ctx->pc = 0x80136B94u;
    ctx->downcount -= 1;
    // 80136B94: bl      0x800B7344
    {
            ctx->lr = 0x80136B98u;
            ctx->pc = 0x800B7344u;
            return;
    }

label_80136B98:
    ctx->pc = 0x80136B98u;
    ctx->downcount -= 5;
    // 80136B98: lhz     r9, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80136B9C:
    ctx->pc = 0x80136B9Cu;
    // 80136B9C: stw     r31, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80136BA0:
    ctx->pc = 0x80136BA0u;
    // 80136BA0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80136BA4:
    ctx->pc = 0x80136BA4u;
    // 80136BA4: sth     r9, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80136BA8:
    ctx->pc = 0x80136BA8u;
    // 80136BA8: bl      0x800B7A5C
    {
            ctx->lr = 0x80136BACu;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80136BAC:
    ctx->pc = 0x80136BACu;
    ctx->downcount -= 10;
    // 80136BAC: lha     r3, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80136BB0:
    ctx->pc = 0x80136BB0u;
    // 80136BB0: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80136BB4:
    ctx->pc = 0x80136BB4u;
    // 80136BB4: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80136BB8:
    ctx->pc = 0x80136BB8u;
    // 80136BB8: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_80136BBC:
    ctx->pc = 0x80136BBCu;
    // 80136BBC: rlwinm r0, r3, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0xFFFFFFF8u;
    }

label_80136BC0:
    ctx->pc = 0x80136BC0u;
    // 80136BC0: lwzx    r10, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136BC4:
    ctx->pc = 0x80136BC4u;
    // 80136BC4: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136BC8:
    ctx->pc = 0x80136BC8u;
    // 80136BC8: stw     r10, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80136BCC:
    ctx->pc = 0x80136BCCu;
    // 80136BCC: stw     r11, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80136BD0:
    ctx->pc = 0x80136BD0u;
    // 80136BD0: bl      0x80132E34
    {
            ctx->lr = 0x80136BD4u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80136BD4:
    ctx->pc = 0x80136BD4u;
    ctx->downcount -= 1;
    // 80136BD4: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136BD8:
    ctx->pc = 0x80136BD8u;
    ctx->downcount -= 26;
    // 80136BD8: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80136BDC:
    ctx->pc = 0x80136BDCu;
    // 80136BDC: addi    r31, r9, -21024
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80136BE0:
    ctx->pc = 0x80136BE0u;
    // 80136BE0: lwz     r8, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136BE4:
    ctx->pc = 0x80136BE4u;
    // 80136BE4: lwz     r7, 84(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(84);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80136BE8:
    ctx->pc = 0x80136BE8u;
    // 80136BE8: lwz     r9, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80136BEC:
    ctx->pc = 0x80136BECu;
    // 80136BEC: lwz     r11, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136BF0:
    ctx->pc = 0x80136BF0u;
    // 80136BF0: lwz     r5, 140(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80136BF4:
    ctx->pc = 0x80136BF4u;
    // 80136BF4: xor   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] ^ ctx->gpr[8];
    }

label_80136BF8:
    ctx->pc = 0x80136BF8u;
    // 80136BF8: lwz     r10, 144(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136BFC:
    ctx->pc = 0x80136BFCu;
    // 80136BFC: xor   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[7];
    }

label_80136C00:
    ctx->pc = 0x80136C00u;
    // 80136C00: lwz     r6, 196(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(196);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80136C04:
    ctx->pc = 0x80136C04u;
    // 80136C04: rlwinm r9, r9, 0, 15, 15
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x00010000u;
    }

label_80136C08:
    ctx->pc = 0x80136C08u;
    // 80136C08: lwz     r0, 200(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136C0C:
    ctx->pc = 0x80136C0Cu;
    // 80136C0C: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_80136C10:
    ctx->pc = 0x80136C10u;
    // 80136C10: rlwinm r11, r11, 0, 15, 15
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00010000u;
    }

label_80136C14:
    ctx->pc = 0x80136C14u;
    // 80136C14: and   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[8];
    }

label_80136C18:
    ctx->pc = 0x80136C18u;
    // 80136C18: xor   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[6];
    }

label_80136C1C:
    ctx->pc = 0x80136C1Cu;
    // 80136C1C: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_80136C20:
    ctx->pc = 0x80136C20u;
    // 80136C20: rlwinm r10, r10, 0, 15, 15
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00010000u;
    }

label_80136C24:
    ctx->pc = 0x80136C24u;
    // 80136C24: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_80136C28:
    ctx->pc = 0x80136C28u;
    // 80136C28: and   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[5];
    }

label_80136C2C:
    ctx->pc = 0x80136C2Cu;
    // 80136C2C: rlwinm r0, r0, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00010000u;
    }

label_80136C30:
    ctx->pc = 0x80136C30u;
    // 80136C30: or   r9, r9, r10
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[10];
    }

label_80136C34:
    ctx->pc = 0x80136C34u;
    // 80136C34: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_80136C38:
    ctx->pc = 0x80136C38u;
    // 80136C38: or.   r6, r9, r0
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136C3C:
    ctx->pc = 0x80136C3Cu;
    // 80136C3C: bc    12, 2, 0x80136CC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136CC4;
        }
    }

label_80136C40:
    ctx->pc = 0x80136C40u;
    ctx->downcount -= 5;
    // 80136C40: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136C44:
    ctx->pc = 0x80136C44u;
    // 80136C44: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136C48:
    ctx->pc = 0x80136C48u;
    // 80136C48: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136C48u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136C4C:
    ctx->pc = 0x80136C4Cu;
    // 80136C4C: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_80136C50:
    ctx->pc = 0x80136C50u;
    // 80136C50: bl      0x8004DC00
    {
            ctx->lr = 0x80136C54u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136C54:
    ctx->pc = 0x80136C54u;
    ctx->downcount -= 14;
    // 80136C54: lwz     r11, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136C58:
    ctx->pc = 0x80136C58u;
    // 80136C58: lis     r9, -32697
    ctx->gpr[9] = ((u32)(s32)(-32697) << 16);

label_80136C5C:
    ctx->pc = 0x80136C5Cu;
    // 80136C5C: addi    r9, r9, -18004
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-18004);

label_80136C60:
    ctx->pc = 0x80136C60u;
    // 80136C60: lis     r10, -32733
    ctx->gpr[10] = ((u32)(s32)(-32733) << 16);

label_80136C64:
    ctx->pc = 0x80136C64u;
    // 80136C64: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_80136C68:
    ctx->pc = 0x80136C68u;
    // 80136C68: addi    r10, r10, 28576
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(28576);

label_80136C6C:
    ctx->pc = 0x80136C6Cu;
    // 80136C6C: lwzx    r0, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136C70:
    ctx->pc = 0x80136C70u;
    // 80136C70: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80136C74:
    ctx->pc = 0x80136C74u;
    // 80136C74: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_80136C78:
    ctx->pc = 0x80136C78u;
    // 80136C78: lwzx    r9, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80136C7C:
    ctx->pc = 0x80136C7Cu;
    // 80136C7C: stw     r9, 11828(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(11828);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80136C80:
    ctx->pc = 0x80136C80u;
    // 80136C80: bl      0x800C7278
    {
            ctx->lr = 0x80136C84u;
            ctx->pc = 0x800C7278u;
            return;
    }

label_80136C84:
    ctx->pc = 0x80136C84u;
    ctx->downcount -= 1;
    // 80136C84: bl      0x800B7344
    {
            ctx->lr = 0x80136C88u;
            ctx->pc = 0x800B7344u;
            return;
    }

label_80136C88:
    ctx->pc = 0x80136C88u;
    ctx->downcount -= 3;
    // 80136C88: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80136C8C:
    ctx->pc = 0x80136C8Cu;
    // 80136C8C: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136C90:
    ctx->pc = 0x80136C90u;
    // 80136C90: bl      0x800B7A5C
    {
            ctx->lr = 0x80136C94u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80136C94:
    ctx->pc = 0x80136C94u;
    ctx->downcount -= 12;
    // 80136C94: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80136C98:
    ctx->pc = 0x80136C98u;
    // 80136C98: li      r0, 64
    ctx->gpr[0] = (u32)(s32)(64);

label_80136C9C:
    ctx->pc = 0x80136C9Cu;
    // 80136C9C: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80136CA0:
    ctx->pc = 0x80136CA0u;
    // 80136CA0: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_80136CA4:
    ctx->pc = 0x80136CA4u;
    // 80136CA4: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_80136CA8:
    ctx->pc = 0x80136CA8u;
    // 80136CA8: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136CAC:
    ctx->pc = 0x80136CACu;
    // 80136CAC: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136CB0:
    ctx->pc = 0x80136CB0u;
    // 80136CB0: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_80136CB4:
    ctx->pc = 0x80136CB4u;
    // 80136CB4: sth     r7, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80136CB8:
    ctx->pc = 0x80136CB8u;
    // 80136CB8: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80136CBC:
    ctx->pc = 0x80136CBCu;
    // 80136CBC: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80136CC0:
    ctx->pc = 0x80136CC0u;
    // 80136CC0: bl      0x80132E34
    {
            ctx->lr = 0x80136CC4u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80136CC4:
    ctx->pc = 0x80136CC4u;
    ctx->downcount -= 24;
    // 80136CC4: lwz     r8, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136CC8:
    ctx->pc = 0x80136CC8u;
    // 80136CC8: lwz     r7, 84(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(84);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80136CCC:
    ctx->pc = 0x80136CCCu;
    // 80136CCC: lwz     r9, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80136CD0:
    ctx->pc = 0x80136CD0u;
    // 80136CD0: lwz     r11, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80136CD4:
    ctx->pc = 0x80136CD4u;
    // 80136CD4: lwz     r5, 140(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80136CD8:
    ctx->pc = 0x80136CD8u;
    // 80136CD8: xor   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] ^ ctx->gpr[8];
    }

label_80136CDC:
    ctx->pc = 0x80136CDCu;
    // 80136CDC: lwz     r10, 144(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136CE0:
    ctx->pc = 0x80136CE0u;
    // 80136CE0: xor   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[7];
    }

label_80136CE4:
    ctx->pc = 0x80136CE4u;
    // 80136CE4: lwz     r6, 196(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(196);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80136CE8:
    ctx->pc = 0x80136CE8u;
    // 80136CE8: rlwinm r9, r9, 0, 14, 14
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x00020000u;
    }

label_80136CEC:
    ctx->pc = 0x80136CECu;
    // 80136CEC: lwz     r0, 200(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136CF0:
    ctx->pc = 0x80136CF0u;
    // 80136CF0: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_80136CF4:
    ctx->pc = 0x80136CF4u;
    // 80136CF4: rlwinm r11, r11, 0, 14, 14
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00020000u;
    }

label_80136CF8:
    ctx->pc = 0x80136CF8u;
    // 80136CF8: and   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[8];
    }

label_80136CFC:
    ctx->pc = 0x80136CFCu;
    // 80136CFC: xor   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[6];
    }

label_80136D00:
    ctx->pc = 0x80136D00u;
    // 80136D00: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_80136D04:
    ctx->pc = 0x80136D04u;
    // 80136D04: rlwinm r10, r10, 0, 14, 14
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00020000u;
    }

label_80136D08:
    ctx->pc = 0x80136D08u;
    // 80136D08: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_80136D0C:
    ctx->pc = 0x80136D0Cu;
    // 80136D0C: and   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[5];
    }

label_80136D10:
    ctx->pc = 0x80136D10u;
    // 80136D10: rlwinm r0, r0, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00020000u;
    }

label_80136D14:
    ctx->pc = 0x80136D14u;
    // 80136D14: or   r9, r9, r10
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[10];
    }

label_80136D18:
    ctx->pc = 0x80136D18u;
    // 80136D18: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_80136D1C:
    ctx->pc = 0x80136D1Cu;
    // 80136D1C: or.   r6, r9, r0
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80136D20:
    ctx->pc = 0x80136D20u;
    // 80136D20: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136D24:
    ctx->pc = 0x80136D24u;
    ctx->downcount -= 5;
    // 80136D24: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80136D28:
    ctx->pc = 0x80136D28u;
    // 80136D28: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_80136D2C:
    ctx->pc = 0x80136D2Cu;
    // 80136D2C: lfs     f1, 5896(r9)
    if (!ppc_fp_available(ctx, 0x80136D2Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(5896);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80136D30:
    ctx->pc = 0x80136D30u;
    // 80136D30: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_80136D34:
    ctx->pc = 0x80136D34u;
    // 80136D34: bl      0x8004DC00
    {
            ctx->lr = 0x80136D38u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_80136D38:
    ctx->pc = 0x80136D38u;
    ctx->downcount -= 3;
    // 80136D38: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80136D3C:
    ctx->pc = 0x80136D3Cu;
    // 80136D3C: stw     r0, -27056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136D40:
    ctx->pc = 0x80136D40u;
    // 80136D40: bl      0x800B7A5C
    {
            ctx->lr = 0x80136D44u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80136D44:
    ctx->pc = 0x80136D44u;
    ctx->downcount -= 8;
    // 80136D44: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80136D48:
    ctx->pc = 0x80136D48u;
    // 80136D48: li      r0, 64
    ctx->gpr[0] = (u32)(s32)(64);

label_80136D4C:
    ctx->pc = 0x80136D4Cu;
    // 80136D4C: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80136D50:
    ctx->pc = 0x80136D50u;
    // 80136D50: li      r7, 8
    ctx->gpr[7] = (u32)(s32)(8);

label_80136D54:
    ctx->pc = 0x80136D54u;
    // 80136D54: addi    r11, r9, 4
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(4);

label_80136D58:
    ctx->pc = 0x80136D58u;
    // 80136D58: lwzx    r10, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136D5C:
    ctx->pc = 0x80136D5Cu;
    // 80136D5C: lwzx    r8, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80136D60:
    ctx->pc = 0x80136D60u;
    // 80136D60: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_80136D64:
    ctx->pc = 0x80136D64u;
    ctx->downcount -= 4;
    // 80136D64: sth     r7, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80136D68:
    ctx->pc = 0x80136D68u;
    // 80136D68: stw     r10, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80136D6C:
    ctx->pc = 0x80136D6Cu;
    // 80136D6C: stw     r8, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80136D70:
    ctx->pc = 0x80136D70u;
    // 80136D70: bl      0x80132E34
    {
            ctx->lr = 0x80136D74u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80136D74:
    ctx->pc = 0x80136D74u;
    ctx->downcount -= 1;
    // 80136D74: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136D78:
    ctx->pc = 0x80136D78u;
    ctx->downcount -= 2;
    // 80136D78: cmpwi   r20, 0
    {
        s32 val_a = (s32)(ctx->gpr[20]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80136D7C:
    ctx->pc = 0x80136D7Cu;
    // 80136D7C: bc    12, 2, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136D80:
    ctx->pc = 0x80136D80u;
    ctx->downcount -= 1;
    // 80136D80: bl      0x800B7A5C
    {
            ctx->lr = 0x80136D84u;
            ctx->pc = 0x800B7A5Cu;
            return;
    }

label_80136D84:
    ctx->pc = 0x80136D84u;
    ctx->downcount -= 3;
    // 80136D84: lwz     r0, -30100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136D88:
    ctx->pc = 0x80136D88u;
    // 80136D88: cmpwi   r0, -1
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

label_80136D8C:
    ctx->pc = 0x80136D8Cu;
    // 80136D8C: bc    12, 2, 0x80136DA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136DA0;
        }
    }

label_80136D90:
    ctx->pc = 0x80136D90u;
    ctx->downcount -= 4;
    // 80136D90: lhz     r0, -30098(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30098);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80136D94:
    ctx->pc = 0x80136D94u;
    // 80136D94: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80136D98:
    ctx->pc = 0x80136D98u;
    // 80136D98: sth     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80136D9C:
    ctx->pc = 0x80136D9Cu;
    // 80136D9C: b       0x80136DB4
    {
            goto label_80136DB4;
    }

label_80136DA0:
    ctx->pc = 0x80136DA0u;
    ctx->downcount -= 5;
    // 80136DA0: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80136DA4:
    ctx->pc = 0x80136DA4u;
    // 80136DA4: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_80136DA8:
    ctx->pc = 0x80136DA8u;
    // 80136DA8: lhz     r9, 52(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(52);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80136DAC:
    ctx->pc = 0x80136DACu;
    // 80136DAC: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_80136DB0:
    ctx->pc = 0x80136DB0u;
    // 80136DB0: sth     r9, 52(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80136DB4:
    ctx->pc = 0x80136DB4u;
    ctx->downcount -= 13;
    // 80136DB4: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_80136DB8:
    ctx->pc = 0x80136DB8u;
    // 80136DB8: lis     r9, -32733
    ctx->gpr[9] = ((u32)(s32)(-32733) << 16);

label_80136DBC:
    ctx->pc = 0x80136DBCu;
    // 80136DBC: lha     r3, -21584(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-21584);
        ctx->gpr[3] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80136DC0:
    ctx->pc = 0x80136DC0u;
    // 80136DC0: addi    r9, r9, 28640
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(28640);

label_80136DC4:
    ctx->pc = 0x80136DC4u;
    // 80136DC4: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80136DC8:
    ctx->pc = 0x80136DC8u;
    // 80136DC8: addi    r8, r9, 4
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(4);

label_80136DCC:
    ctx->pc = 0x80136DCCu;
    // 80136DCC: rlwinm r11, r3, 3, 0, 28
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0xFFFFFFF8u;
    }

label_80136DD0:
    ctx->pc = 0x80136DD0u;
    // 80136DD0: stw     r0, -30100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30100);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136DD4:
    ctx->pc = 0x80136DD4u;
    // 80136DD4: lwzx    r10, r8, r11
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[11];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80136DD8:
    ctx->pc = 0x80136DD8u;
    // 80136DD8: lwzx    r0, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136DDC:
    ctx->pc = 0x80136DDCu;
    // 80136DDC: stw     r10, -27060(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27060);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80136DE0:
    ctx->pc = 0x80136DE0u;
    // 80136DE0: stw     r0, -27064(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27064);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136DE4:
    ctx->pc = 0x80136DE4u;
    // 80136DE4: bl      0x80132E34
    {
            ctx->lr = 0x80136DE8u;
            ctx->pc = 0x80132E34u;
            return;
    }

label_80136DE8:
    ctx->pc = 0x80136DE8u;
    ctx->downcount -= 1;
    // 80136DE8: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136DEC:
    ctx->pc = 0x80136DECu;
    ctx->downcount -= 4;
    // 80136DEC: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80136DF0:
    ctx->pc = 0x80136DF0u;
    // 80136DF0: lha     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80136DF4:
    ctx->pc = 0x80136DF4u;
    // 80136DF4: cmpwi   r0, 10
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

label_80136DF8:
    ctx->pc = 0x80136DF8u;
    // 80136DF8: bc    12, 1, 0x80136E28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E28;
        }
    }

label_80136DFC:
    ctx->pc = 0x80136DFCu;
    ctx->downcount -= 2;
    // 80136DFC: cmpwi   r0, 9
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

label_80136E00:
    ctx->pc = 0x80136E00u;
    // 80136E00: bc    4, 0, 0x80136E8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136E8C;
        }
    }

label_80136E04:
    ctx->pc = 0x80136E04u;
    ctx->downcount -= 2;
    // 80136E04: cmpwi   r0, 5
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

label_80136E08:
    ctx->pc = 0x80136E08u;
    // 80136E08: bc    12, 2, 0x80136E9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E9C;
        }
    }

label_80136E0C:
    ctx->pc = 0x80136E0Cu;
    ctx->downcount -= 1;
    // 80136E0C: bc    12, 1, 0x80136E1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E1C;
        }
    }

label_80136E10:
    ctx->pc = 0x80136E10u;
    ctx->downcount -= 2;
    // 80136E10: cmpwi   r0, 0
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

label_80136E14:
    ctx->pc = 0x80136E14u;
    // 80136E14: bc    12, 2, 0x80136E68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E68;
        }
    }

label_80136E18:
    ctx->pc = 0x80136E18u;
    ctx->downcount -= 1;
    // 80136E18: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136E1C:
    ctx->pc = 0x80136E1Cu;
    ctx->downcount -= 2;
    // 80136E1C: cmpwi   r0, 7
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

label_80136E20:
    ctx->pc = 0x80136E20u;
    // 80136E20: bc    12, 0, 0x80136EBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136EBC;
        }
    }

label_80136E24:
    ctx->pc = 0x80136E24u;
    ctx->downcount -= 1;
    // 80136E24: b       0x80136E9C
    {
            goto label_80136E9C;
    }

label_80136E28:
    ctx->pc = 0x80136E28u;
    ctx->downcount -= 2;
    // 80136E28: cmpwi   r0, 14
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

label_80136E2C:
    ctx->pc = 0x80136E2Cu;
    // 80136E2C: bc    12, 2, 0x80136E54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E54;
        }
    }

label_80136E30:
    ctx->pc = 0x80136E30u;
    ctx->downcount -= 1;
    // 80136E30: bc    12, 1, 0x80136E40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E40;
        }
    }

label_80136E34:
    ctx->pc = 0x80136E34u;
    ctx->downcount -= 2;
    // 80136E34: cmpwi   r0, 13
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

label_80136E38:
    ctx->pc = 0x80136E38u;
    // 80136E38: bc    12, 2, 0x80136E68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E68;
        }
    }

label_80136E3C:
    ctx->pc = 0x80136E3Cu;
    ctx->downcount -= 1;
    // 80136E3C: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136E40:
    ctx->pc = 0x80136E40u;
    ctx->downcount -= 2;
    // 80136E40: cmpwi   r0, 15
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

label_80136E44:
    ctx->pc = 0x80136E44u;
    // 80136E44: bc    12, 2, 0x80136E70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E70;
        }
    }

label_80136E48:
    ctx->pc = 0x80136E48u;
    ctx->downcount -= 2;
    // 80136E48: cmpwi   r0, 16
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

label_80136E4C:
    ctx->pc = 0x80136E4Cu;
    // 80136E4C: bc    12, 2, 0x80136E60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136E60;
        }
    }

label_80136E50:
    ctx->pc = 0x80136E50u;
    ctx->downcount -= 1;
    // 80136E50: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136E54:
    ctx->pc = 0x80136E54u;
    ctx->downcount -= 2;
    // 80136E54: li      r3, 140
    ctx->gpr[3] = (u32)(s32)(140);

label_80136E58:
    ctx->pc = 0x80136E58u;
    // 80136E58: bl      0x8005EFCC
    {
            ctx->lr = 0x80136E5Cu;
            ctx->pc = 0x8005EFCCu;
            return;
    }

label_80136E5C:
    ctx->pc = 0x80136E5Cu;
    ctx->downcount -= 1;
    // 80136E5C: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136E60:
    ctx->pc = 0x80136E60u;
    ctx->downcount -= 2;
    // 80136E60: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80136E64:
    ctx->pc = 0x80136E64u;
    // 80136E64: b       0x80136E80
    {
            goto label_80136E80;
    }

label_80136E68:
    ctx->pc = 0x80136E68u;
    ctx->downcount -= 1;
    // 80136E68: bl      0x80133968
    {
            ctx->lr = 0x80136E6Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80133968u;
                return;
            }
            goto label_80133968;
    }

label_80136E6C:
    ctx->pc = 0x80136E6Cu;
    ctx->downcount -= 1;
    // 80136E6C: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136E70:
    ctx->pc = 0x80136E70u;
    ctx->downcount -= 4;
    // 80136E70: lis     r9, -32702
    ctx->gpr[9] = ((u32)(s32)(-32702) << 16);

label_80136E74:
    ctx->pc = 0x80136E74u;
    // 80136E74: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80136E78:
    ctx->pc = 0x80136E78u;
    // 80136E78: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80136E7C:
    ctx->pc = 0x80136E7Cu;
    // 80136E7C: stw     r0, 30628(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30628);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136E80:
    ctx->pc = 0x80136E80u;
    ctx->downcount -= 2;
    // 80136E80: addi    r3, r3, -18336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-18336);

label_80136E84:
    ctx->pc = 0x80136E84u;
    // 80136E84: bl      0x8005D53C
    {
            ctx->lr = 0x80136E88u;
            ctx->pc = 0x8005D53Cu;
            return;
    }

label_80136E88:
    ctx->pc = 0x80136E88u;
    ctx->downcount -= 1;
    // 80136E88: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136E8C:
    ctx->pc = 0x80136E8Cu;
    ctx->downcount -= 4;
    // 80136E8C: lis     r9, -32702
    ctx->gpr[9] = ((u32)(s32)(-32702) << 16);

label_80136E90:
    ctx->pc = 0x80136E90u;
    // 80136E90: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80136E94:
    ctx->pc = 0x80136E94u;
    // 80136E94: stw     r0, 30628(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30628);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136E98:
    ctx->pc = 0x80136E98u;
    // 80136E98: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136E9C:
    ctx->pc = 0x80136E9Cu;
    ctx->downcount -= 1;
    // 80136E9C: bl      0x80032C88
    {
            ctx->lr = 0x80136EA0u;
            ctx->pc = 0x80032C88u;
            return;
    }

label_80136EA0:
    ctx->pc = 0x80136EA0u;
    ctx->downcount -= 1;
    // 80136EA0: b       0x80136EBC
    {
            goto label_80136EBC;
    }

label_80136EA4:
    ctx->pc = 0x80136EA4u;
    ctx->downcount -= 1;
    // 80136EA4: bl      0x8001DB30
    {
            ctx->lr = 0x80136EA8u;
            ctx->pc = 0x8001DB30u;
            return;
    }

label_80136EA8:
    ctx->pc = 0x80136EA8u;
    ctx->downcount -= 5;
    // 80136EA8: lwz     r0, -27072(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27072);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136EAC:
    ctx->pc = 0x80136EACu;
    // 80136EAC: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80136EB0:
    ctx->pc = 0x80136EB0u;
    // 80136EB0: addi    r3, r3, -19280
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19280);

label_80136EB4:
    ctx->pc = 0x80136EB4u;
    // 80136EB4: stw     r0, -27484(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27484);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136EB8:
    ctx->pc = 0x80136EB8u;
    // 80136EB8: bl      0x80034A2C
    {
            ctx->lr = 0x80136EBCu;
            ctx->pc = 0x80034A2Cu;
            return;
    }

label_80136EBC:
    ctx->pc = 0x80136EBCu;
    ctx->downcount -= 28;
    // 80136EBC: lwz     r0, 18724(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18724);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136EC0:
    ctx->pc = 0x80136EC0u;
    // 80136EC0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80136EC4:
    ctx->pc = 0x80136EC4u;
    // 80136EC4: lmw     r20, 18576(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18576);
        for (u32 r = 20; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80136EC8:
    ctx->pc = 0x80136EC8u;
    // 80136EC8: lfd     f20, 18624(r1)
    if (!ppc_fp_available(ctx, 0x80136EC8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18624);
        ctx->fpr[20] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136ECC:
    ctx->pc = 0x80136ECCu;
    // 80136ECC: lfd     f21, 18632(r1)
    if (!ppc_fp_available(ctx, 0x80136ECCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18632);
        ctx->fpr[21] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136ED0:
    ctx->pc = 0x80136ED0u;
    // 80136ED0: lfd     f22, 18640(r1)
    if (!ppc_fp_available(ctx, 0x80136ED0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18640);
        ctx->fpr[22] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136ED4:
    ctx->pc = 0x80136ED4u;
    // 80136ED4: lfd     f23, 18648(r1)
    if (!ppc_fp_available(ctx, 0x80136ED4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18648);
        ctx->fpr[23] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136ED8:
    ctx->pc = 0x80136ED8u;
    // 80136ED8: lfd     f24, 18656(r1)
    if (!ppc_fp_available(ctx, 0x80136ED8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18656);
        ctx->fpr[24] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136EDC:
    ctx->pc = 0x80136EDCu;
    // 80136EDC: lfd     f25, 18664(r1)
    if (!ppc_fp_available(ctx, 0x80136EDCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18664);
        ctx->fpr[25] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136EE0:
    ctx->pc = 0x80136EE0u;
    // 80136EE0: lfd     f26, 18672(r1)
    if (!ppc_fp_available(ctx, 0x80136EE0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18672);
        ctx->fpr[26] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136EE4:
    ctx->pc = 0x80136EE4u;
    // 80136EE4: lfd     f27, 18680(r1)
    if (!ppc_fp_available(ctx, 0x80136EE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18680);
        ctx->fpr[27] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136EE8:
    ctx->pc = 0x80136EE8u;
    // 80136EE8: lfd     f28, 18688(r1)
    if (!ppc_fp_available(ctx, 0x80136EE8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18688);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136EEC:
    ctx->pc = 0x80136EECu;
    // 80136EEC: lfd     f29, 18696(r1)
    if (!ppc_fp_available(ctx, 0x80136EECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18696);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136EF0:
    ctx->pc = 0x80136EF0u;
    // 80136EF0: lfd     f30, 18704(r1)
    if (!ppc_fp_available(ctx, 0x80136EF0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18704);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136EF4:
    ctx->pc = 0x80136EF4u;
    // 80136EF4: lfd     f31, 18712(r1)
    if (!ppc_fp_available(ctx, 0x80136EF4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(18712);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80136EF8:
    ctx->pc = 0x80136EF8u;
    // 80136EF8: addi    r1, r1, 18720
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(18720);

label_80136EFC:
    ctx->pc = 0x80136EFCu;
    // 80136EFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80136F00:
    ctx->pc = 0x80136F00u;
    ctx->downcount -= 7;
    // 80136F00: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80136F04:
    ctx->pc = 0x80136F04u;
    // 80136F04: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80136F08:
    ctx->pc = 0x80136F08u;
    // 80136F08: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136F0C:
    ctx->pc = 0x80136F0Cu;
    // 80136F0C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80136F10:
    ctx->pc = 0x80136F10u;
    // 80136F10: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_80136F14:
    ctx->pc = 0x80136F14u;
    // 80136F14: cmpw    r4, r0
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

label_80136F18:
    ctx->pc = 0x80136F18u;
    // 80136F18: bc    4, 2, 0x80136F3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80136F3C;
        }
    }

label_80136F1C:
    ctx->pc = 0x80136F1Cu;
    ctx->downcount -= 2;
    // 80136F1C: cmpwi   r3, 0
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

label_80136F20:
    ctx->pc = 0x80136F20u;
    // 80136F20: bc    12, 2, 0x80136F3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136F3C;
        }
    }

label_80136F24:
    ctx->pc = 0x80136F24u;
    ctx->downcount -= 3;
    // 80136F24: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80136F28:
    ctx->pc = 0x80136F28u;
    // 80136F28: addi    r3, r3, -19280
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19280);

label_80136F2C:
    ctx->pc = 0x80136F2Cu;
    // 80136F2C: bl      0x800349FC
    {
            ctx->lr = 0x80136F30u;
            ctx->pc = 0x800349FCu;
            return;
    }

label_80136F30:
    ctx->pc = 0x80136F30u;
    ctx->downcount -= 3;
    // 80136F30: lis     r3, -32697
    ctx->gpr[3] = ((u32)(s32)(-32697) << 16);

label_80136F34:
    ctx->pc = 0x80136F34u;
    // 80136F34: addi    r3, r3, -18768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-18768);

label_80136F38:
    ctx->pc = 0x80136F38u;
    // 80136F38: bl      0x80041574
    {
            ctx->lr = 0x80136F3Cu;
            ctx->pc = 0x80041574u;
            return;
    }

label_80136F3C:
    ctx->pc = 0x80136F3Cu;
    ctx->downcount -= 5;
    // 80136F3C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136F40:
    ctx->pc = 0x80136F40u;
    // 80136F40: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80136F44:
    ctx->pc = 0x80136F44u;
    // 80136F44: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80136F48:
    ctx->pc = 0x80136F48u;
    // 80136F48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80136F4C:
    ctx->pc = 0x80136F4Cu;
    ctx->downcount -= 7;
    // 80136F4C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80136F50:
    ctx->pc = 0x80136F50u;
    // 80136F50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80136F54:
    ctx->pc = 0x80136F54u;
    // 80136F54: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136F58:
    ctx->pc = 0x80136F58u;
    // 80136F58: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80136F5C:
    ctx->pc = 0x80136F5Cu;
    // 80136F5C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80136F60:
    ctx->pc = 0x80136F60u;
    // 80136F60: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_80136F64:
    ctx->pc = 0x80136F64u;
    // 80136F64: bl      0x80136F00
    {
            ctx->lr = 0x80136F68u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80136F00u;
                return;
            }
            goto label_80136F00;
    }

label_80136F68:
    ctx->pc = 0x80136F68u;
    ctx->downcount -= 5;
    // 80136F68: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80136F6C:
    ctx->pc = 0x80136F6Cu;
    // 80136F6C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80136F70:
    ctx->pc = 0x80136F70u;
    // 80136F70: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80136F74:
    ctx->pc = 0x80136F74u;
    // 80136F74: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80136F78:
    ctx->pc = 0x80136F78u;
    ctx->downcount -= 8;
    // 80136F78: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80136F7C:
    ctx->pc = 0x80136F7Cu;
    // 80136F7C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80136F80:
    ctx->pc = 0x80136F80u;
    // 80136F80: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80136F84:
    ctx->pc = 0x80136F84u;
    // 80136F84: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136F88:
    ctx->pc = 0x80136F88u;
    // 80136F88: lis     r0, 8192
    ctx->gpr[0] = ((u32)(s32)(8192) << 16);

label_80136F8C:
    ctx->pc = 0x80136F8Cu;
    // 80136F8C: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_80136F90:
    ctx->pc = 0x80136F90u;
    // 80136F90: cmpw    r3, r0
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

label_80136F94:
    ctx->pc = 0x80136F94u;
    // 80136F94: bc    12, 2, 0x80137140
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137140;
        }
    }

label_80136F98:
    ctx->pc = 0x80136F98u;
    ctx->downcount -= 1;
    // 80136F98: bc    12, 1, 0x80136FC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136FC0;
        }
    }

label_80136F9C:
    ctx->pc = 0x80136F9Cu;
    ctx->downcount -= 4;
    // 80136F9C: lis     r0, 4096
    ctx->gpr[0] = ((u32)(s32)(4096) << 16);

label_80136FA0:
    ctx->pc = 0x80136FA0u;
    // 80136FA0: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80136FA4:
    ctx->pc = 0x80136FA4u;
    // 80136FA4: cmpw    r3, r0
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

label_80136FA8:
    ctx->pc = 0x80136FA8u;
    // 80136FA8: bc    12, 2, 0x80137118
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137118;
        }
    }

label_80136FAC:
    ctx->pc = 0x80136FACu;
    ctx->downcount -= 4;
    // 80136FAC: lis     r0, 8192
    ctx->gpr[0] = ((u32)(s32)(8192) << 16);

label_80136FB0:
    ctx->pc = 0x80136FB0u;
    // 80136FB0: ori     r0, r0, 0x0003
    ctx->gpr[0] = ctx->gpr[0] | 0x0003u;

label_80136FB4:
    ctx->pc = 0x80136FB4u;
    // 80136FB4: cmpw    r3, r0
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

label_80136FB8:
    ctx->pc = 0x80136FB8u;
    // 80136FB8: bc    12, 2, 0x80136FE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80136FE4;
        }
    }

label_80136FBC:
    ctx->pc = 0x80136FBCu;
    ctx->downcount -= 1;
    // 80136FBC: b       0x80137164
    {
            goto label_80137164;
    }

label_80136FC0:
    ctx->pc = 0x80136FC0u;
    ctx->downcount -= 4;
    // 80136FC0: lis     r0, 8448
    ctx->gpr[0] = ((u32)(s32)(8448) << 16);

label_80136FC4:
    ctx->pc = 0x80136FC4u;
    // 80136FC4: ori     r0, r0, 0x0003
    ctx->gpr[0] = ctx->gpr[0] | 0x0003u;

label_80136FC8:
    ctx->pc = 0x80136FC8u;
    // 80136FC8: cmpw    r3, r0
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

label_80136FCC:
    ctx->pc = 0x80136FCCu;
    // 80136FCC: bc    12, 2, 0x80137000
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137000;
        }
    }

label_80136FD0:
    ctx->pc = 0x80136FD0u;
    ctx->downcount -= 4;
    // 80136FD0: lis     r0, 8448
    ctx->gpr[0] = ((u32)(s32)(8448) << 16);

label_80136FD4:
    ctx->pc = 0x80136FD4u;
    // 80136FD4: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80136FD8:
    ctx->pc = 0x80136FD8u;
    // 80136FD8: cmpw    r3, r0
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

label_80136FDC:
    ctx->pc = 0x80136FDCu;
    // 80136FDC: bc    12, 2, 0x80137008
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137008;
        }
    }

label_80136FE0:
    ctx->pc = 0x80136FE0u;
    ctx->downcount -= 1;
    // 80136FE0: b       0x80137164
    {
            goto label_80137164;
    }

label_80136FE4:
    ctx->pc = 0x80136FE4u;
    ctx->downcount -= 4;
    // 80136FE4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80136FE8:
    ctx->pc = 0x80136FE8u;
    // 80136FE8: stw     r0, -27036(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27036);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136FEC:
    ctx->pc = 0x80136FECu;
    // 80136FEC: stw     r0, -27040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27040);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80136FF0:
    ctx->pc = 0x80136FF0u;
    // 80136FF0: bl      0x80137270
    {
            ctx->lr = 0x80136FF4u;
            goto label_80137270;
    }

label_80136FF4:
    ctx->pc = 0x80136FF4u;
    ctx->downcount -= 1;
    // 80136FF4: bl      0x8013765C
    {
            ctx->lr = 0x80136FF8u;
            ctx->pc = 0x8013765Cu;
            return;
    }

label_80136FF8:
    ctx->pc = 0x80136FF8u;
    ctx->downcount -= 1;
    // 80136FF8: bl      0x80137284
    {
            ctx->lr = 0x80136FFCu;
            goto label_80137284;
    }

label_80136FFC:
    ctx->pc = 0x80136FFCu;
    ctx->downcount -= 1;
    // 80136FFC: b       0x80137164
    {
            goto label_80137164;
    }

label_80137000:
    ctx->pc = 0x80137000u;
    ctx->downcount -= 1;
    // 80137000: bl      0x80137178
    {
            ctx->lr = 0x80137004u;
            goto label_80137178;
    }

label_80137004:
    ctx->pc = 0x80137004u;
    ctx->downcount -= 1;
    // 80137004: b       0x80137164
    {
            goto label_80137164;
    }

label_80137008:
    ctx->pc = 0x80137008u;
    ctx->downcount -= 1;
    // 80137008: bl      0x80059E90
    {
            ctx->lr = 0x8013700Cu;
            ctx->pc = 0x80059E90u;
            return;
    }

label_8013700C:
    ctx->pc = 0x8013700Cu;
    ctx->downcount -= 2;
    // 8013700C: cmpwi   r3, 0
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

label_80137010:
    ctx->pc = 0x80137010u;
    // 80137010: bc    4, 2, 0x80137164
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80137164;
        }
    }

label_80137014:
    ctx->pc = 0x80137014u;
    ctx->downcount -= 4;
    // 80137014: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80137018:
    ctx->pc = 0x80137018u;
    // 80137018: lfs     f1, 7984(r9)
    if (!ppc_fp_available(ctx, 0x80137018u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(7984);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013701C:
    ctx->pc = 0x8013701Cu;
    // 8013701C: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x8013701Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80137020:
    ctx->pc = 0x80137020u;
    // 80137020: bl      0x80036128
    {
            ctx->lr = 0x80137024u;
            ctx->pc = 0x80036128u;
            return;
    }

label_80137024:
    ctx->pc = 0x80137024u;
    ctx->downcount -= 3;
    // 80137024: lwz     r0, -30056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80137028:
    ctx->pc = 0x80137028u;
    // 80137028: cmpwi   r0, 0
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

label_8013702C:
    ctx->pc = 0x8013702Cu;
    // 8013702C: bc    12, 2, 0x80137040
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137040;
        }
    }

label_80137030:
    ctx->pc = 0x80137030u;
    ctx->downcount -= 4;
    // 80137030: lis     r3, -32737
    ctx->gpr[3] = ((u32)(s32)(-32737) << 16);

label_80137034:
    ctx->pc = 0x80137034u;
    // 80137034: addi    r3, r3, 7892
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(7892);

label_80137038:
    ctx->pc = 0x80137038u;
    // 80137038: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8013703C:
    ctx->pc = 0x8013703Cu;
    // 8013703C: bl      0x80035F84
    {
            ctx->lr = 0x80137040u;
            ctx->pc = 0x80035F84u;
            return;
    }

label_80137040:
    ctx->pc = 0x80137040u;
    ctx->downcount -= 8;
    // 80137040: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_80137044:
    ctx->pc = 0x80137044u;
    // 80137044: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_80137048:
    ctx->pc = 0x80137048u;
    // 80137048: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8013704C:
    ctx->pc = 0x8013704Cu;
    // 8013704C: lwz     r0, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80137050:
    ctx->pc = 0x80137050u;
    // 80137050: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_80137054:
    ctx->pc = 0x80137054u;
    // 80137054: rlwinm r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
    }

label_80137058:
    ctx->pc = 0x80137058u;
    // 80137058: and.   r9, r0, r11
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

label_8013705C:
    ctx->pc = 0x8013705Cu;
    // 8013705C: bc    12, 2, 0x801370B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801370B4;
        }
    }

label_80137060:
    ctx->pc = 0x80137060u;
    ctx->downcount -= 4;
    // 80137060: lwz     r9, -27040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27040);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80137064:
    ctx->pc = 0x80137064u;
    // 80137064: addi    r31, r9, 1
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(1);

label_80137068:
    ctx->pc = 0x80137068u;
    // 80137068: cmpwi   r31, 1
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

label_8013706C:
    ctx->pc = 0x8013706Cu;
    // 8013706C: bc    4, 1, 0x80137074
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80137074;
        }
    }

label_80137070:
    ctx->pc = 0x80137070u;
    ctx->downcount -= 1;
    // 80137070: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80137074:
    ctx->pc = 0x80137074u;
    ctx->downcount -= 2;
    // 80137074: cmpwi   r9, 0
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

label_80137078:
    ctx->pc = 0x80137078u;
    // 80137078: bc    12, 2, 0x80137088
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137088;
        }
    }

label_8013707C:
    ctx->pc = 0x8013707Cu;
    ctx->downcount -= 2;
    // 8013707C: cmpwi   r9, 1
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

label_80137080:
    ctx->pc = 0x80137080u;
    // 80137080: bc    12, 2, 0x80137090
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137090;
        }
    }

label_80137084:
    ctx->pc = 0x80137084u;
    ctx->downcount -= 1;
    // 80137084: b       0x80137094
    {
            goto label_80137094;
    }

label_80137088:
    ctx->pc = 0x80137088u;
    ctx->downcount -= 1;
    // 80137088: bl      0x801375B8
    {
            ctx->lr = 0x8013708Cu;
            ctx->pc = 0x801375B8u;
            return;
    }

label_8013708C:
    ctx->pc = 0x8013708Cu;
    ctx->downcount -= 1;
    // 8013708C: b       0x80137094
    {
            goto label_80137094;
    }

label_80137090:
    ctx->pc = 0x80137090u;
    ctx->downcount -= 1;
    // 80137090: bl      0x80137C28
    {
            ctx->lr = 0x80137094u;
            ctx->pc = 0x80137C28u;
            return;
    }

label_80137094:
    ctx->pc = 0x80137094u;
    ctx->downcount -= 2;
    // 80137094: cmpwi   r31, 0
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

label_80137098:
    ctx->pc = 0x80137098u;
    // 80137098: bc    12, 2, 0x801370A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801370A8;
        }
    }

label_8013709C:
    ctx->pc = 0x8013709Cu;
    ctx->downcount -= 2;
    // 8013709C: cmpwi   r31, 1
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

label_801370A0:
    ctx->pc = 0x801370A0u;
    // 801370A0: bc    12, 2, 0x801370B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801370B0;
        }
    }

label_801370A4:
    ctx->pc = 0x801370A4u;
    ctx->downcount -= 1;
    // 801370A4: b       0x801370B4
    {
            goto label_801370B4;
    }

label_801370A8:
    ctx->pc = 0x801370A8u;
    ctx->downcount -= 1;
    // 801370A8: bl      0x80137284
    {
            ctx->lr = 0x801370ACu;
            goto label_80137284;
    }

label_801370AC:
    ctx->pc = 0x801370ACu;
    ctx->downcount -= 1;
    // 801370AC: b       0x801370B4
    {
            goto label_801370B4;
    }

label_801370B0:
    ctx->pc = 0x801370B0u;
    ctx->downcount -= 1;
    // 801370B0: bl      0x801376E4
    {
            ctx->lr = 0x801370B4u;
            ctx->pc = 0x801376E4u;
            return;
    }

label_801370B4:
    ctx->pc = 0x801370B4u;
    ctx->downcount -= 8;
    // 801370B4: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_801370B8:
    ctx->pc = 0x801370B8u;
    // 801370B8: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_801370BC:
    ctx->pc = 0x801370BCu;
    // 801370BC: lwz     r11, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801370C0:
    ctx->pc = 0x801370C0u;
    // 801370C0: lwz     r0, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801370C4:
    ctx->pc = 0x801370C4u;
    // 801370C4: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_801370C8:
    ctx->pc = 0x801370C8u;
    // 801370C8: rlwinm r0, r0, 0, 23, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000100u;
    }

label_801370CC:
    ctx->pc = 0x801370CCu;
    // 801370CC: and.   r9, r0, r11
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

label_801370D0:
    ctx->pc = 0x801370D0u;
    // 801370D0: bc    12, 2, 0x801370E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801370E0;
        }
    }

label_801370D4:
    ctx->pc = 0x801370D4u;
    ctx->downcount -= 3;
    // 801370D4: lwz     r0, -30056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30056);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801370D8:
    ctx->pc = 0x801370D8u;
    // 801370D8: xori    r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] ^ 0x0001u;

label_801370DC:
    ctx->pc = 0x801370DCu;
    // 801370DC: stw     r0, -30056(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-30056);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801370E0:
    ctx->pc = 0x801370E0u;
    ctx->downcount -= 3;
    // 801370E0: lwz     r0, -27040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801370E4:
    ctx->pc = 0x801370E4u;
    // 801370E4: cmpwi   r0, 0
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

label_801370E8:
    ctx->pc = 0x801370E8u;
    // 801370E8: bc    12, 2, 0x801370F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801370F8;
        }
    }

label_801370EC:
    ctx->pc = 0x801370ECu;
    ctx->downcount -= 2;
    // 801370EC: cmpwi   r0, 1
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

label_801370F0:
    ctx->pc = 0x801370F0u;
    // 801370F0: bc    12, 2, 0x80137100
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137100;
        }
    }

label_801370F4:
    ctx->pc = 0x801370F4u;
    ctx->downcount -= 1;
    // 801370F4: b       0x80137104
    {
            goto label_80137104;
    }

label_801370F8:
    ctx->pc = 0x801370F8u;
    ctx->downcount -= 1;
    // 801370F8: bl      0x8013729C
    {
            ctx->lr = 0x801370FCu;
            goto label_8013729C;
    }

label_801370FC:
    ctx->pc = 0x801370FCu;
    ctx->downcount -= 1;
    // 801370FC: b       0x80137104
    {
            goto label_80137104;
    }

label_80137100:
    ctx->pc = 0x80137100u;
    ctx->downcount -= 1;
    // 80137100: bl      0x8013771C
    {
            ctx->lr = 0x80137104u;
            ctx->pc = 0x8013771Cu;
            return;
    }

label_80137104:
    ctx->pc = 0x80137104u;
    ctx->downcount -= 4;
    // 80137104: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_80137108:
    ctx->pc = 0x80137108u;
    // 80137108: lfs     f1, 7988(r9)
    if (!ppc_fp_available(ctx, 0x80137108u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(7988);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8013710C:
    ctx->pc = 0x8013710Cu;
    // 8013710C: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x8013710Cu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80137110:
    ctx->pc = 0x80137110u;
    // 80137110: bl      0x80036128
    {
            ctx->lr = 0x80137114u;
            ctx->pc = 0x80036128u;
            return;
    }

label_80137114:
    ctx->pc = 0x80137114u;
    ctx->downcount -= 1;
    // 80137114: b       0x80137164
    {
            goto label_80137164;
    }

label_80137118:
    ctx->pc = 0x80137118u;
    ctx->downcount -= 3;
    // 80137118: lwz     r0, -27040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8013711C:
    ctx->pc = 0x8013711Cu;
    // 8013711C: cmpwi   r0, 0
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

label_80137120:
    ctx->pc = 0x80137120u;
    // 80137120: bc    12, 2, 0x80137130
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137130;
        }
    }

label_80137124:
    ctx->pc = 0x80137124u;
    ctx->downcount -= 2;
    // 80137124: cmpwi   r0, 1
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

label_80137128:
    ctx->pc = 0x80137128u;
    // 80137128: bc    12, 2, 0x80137138
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137138;
        }
    }

label_8013712C:
    ctx->pc = 0x8013712Cu;
    ctx->downcount -= 1;
    // 8013712C: b       0x80137164
    {
            goto label_80137164;
    }

label_80137130:
    ctx->pc = 0x80137130u;
    ctx->downcount -= 1;
    // 80137130: bl      0x801375B4
    {
            ctx->lr = 0x80137134u;
            ctx->pc = 0x801375B4u;
            return;
    }

label_80137134:
    ctx->pc = 0x80137134u;
    ctx->downcount -= 1;
    // 80137134: b       0x80137164
    {
            goto label_80137164;
    }

label_80137138:
    ctx->pc = 0x80137138u;
    ctx->downcount -= 1;
    // 80137138: bl      0x80137BE0
    {
            ctx->lr = 0x8013713Cu;
            ctx->pc = 0x80137BE0u;
            return;
    }

label_8013713C:
    ctx->pc = 0x8013713Cu;
    ctx->downcount -= 1;
    // 8013713C: b       0x80137164
    {
            goto label_80137164;
    }

label_80137140:
    ctx->pc = 0x80137140u;
    ctx->downcount -= 3;
    // 80137140: lwz     r0, -27040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27040);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80137144:
    ctx->pc = 0x80137144u;
    // 80137144: cmpwi   r0, 0
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

label_80137148:
    ctx->pc = 0x80137148u;
    // 80137148: bc    12, 2, 0x80137158
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137158;
        }
    }

label_8013714C:
    ctx->pc = 0x8013714Cu;
    ctx->downcount -= 2;
    // 8013714C: cmpwi   r0, 1
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

label_80137150:
    ctx->pc = 0x80137150u;
    // 80137150: bc    12, 2, 0x80137160
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80137160;
        }
    }

label_80137154:
    ctx->pc = 0x80137154u;
    ctx->downcount -= 1;
    // 80137154: b       0x80137164
    {
            goto label_80137164;
    }

label_80137158:
    ctx->pc = 0x80137158u;
    ctx->downcount -= 1;
    // 80137158: bl      0x801375B8
    {
            ctx->lr = 0x8013715Cu;
            ctx->pc = 0x801375B8u;
            return;
    }

label_8013715C:
    ctx->pc = 0x8013715Cu;
    ctx->downcount -= 1;
    // 8013715C: b       0x80137164
    {
            goto label_80137164;
    }

label_80137160:
    ctx->pc = 0x80137160u;
    ctx->downcount -= 1;
    // 80137160: bl      0x80137C28
    {
            ctx->lr = 0x80137164u;
            ctx->pc = 0x80137C28u;
            return;
    }

label_80137164:
    ctx->pc = 0x80137164u;
    ctx->downcount -= 6;
    // 80137164: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80137168:
    ctx->pc = 0x80137168u;
    // 80137168: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8013716C:
    ctx->pc = 0x8013716Cu;
    // 8013716C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80137170:
    ctx->pc = 0x80137170u;
    // 80137170: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80137174:
    ctx->pc = 0x80137174u;
    // 80137174: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80137178:
    ctx->pc = 0x80137178u;
    ctx->downcount -= 20;
    // 80137178: stwu     r1, -160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-160);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8013717C:
    ctx->pc = 0x8013717Cu;
    // 8013717C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80137180:
    ctx->pc = 0x80137180u;
    // 80137180: stmw     r25, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80137184:
    ctx->pc = 0x80137184u;
    // 80137184: stw     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80137188:
    ctx->pc = 0x80137188u;
    // 80137188: lis     r9, -32736
    ctx->gpr[9] = ((u32)(s32)(-32736) << 16);

label_8013718C:
    ctx->pc = 0x8013718Cu;
    // 8013718C: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_80137190:
    ctx->pc = 0x80137190u;
    // 80137190: addi    r27, r9, 15368
    ctx->gpr[27] = ctx->gpr[9] + (u32)(s32)(15368);

label_80137194:
    ctx->pc = 0x80137194u;
    // 80137194: lwz     r0, 36(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80137198:
    ctx->pc = 0x80137198u;
    // 80137198: cmpwi   r0, 0
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

label_8013719C:
    ctx->pc = 0x8013719Cu;
    // 8013719C: bc    4, 2, 0x801371A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801371A4;
        }
    }

label_801371A0:
    ctx->pc = 0x801371A0u;
    ctx->downcount -= 1;
    // 801371A0: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_801371A4:
    ctx->pc = 0x801371A4u;
    ctx->downcount -= 2;
    // 801371A4: cmpwi   r11, 0
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

label_801371A8:
    ctx->pc = 0x801371A8u;
    // 801371A8: bc    12, 2, 0x8013725C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013725C;
        }
    }

label_801371AC:
    ctx->pc = 0x801371ACu;
    ctx->downcount -= 3;
    // 801371AC: lwz     r26, 36(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(36);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_801371B0:
    ctx->pc = 0x801371B0u;
    // 801371B0: cmpwi   r26, 0
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

label_801371B4:
    ctx->pc = 0x801371B4u;
    // 801371B4: bc    12, 2, 0x8013725C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013725C;
        }
    }

label_801371B8:
    ctx->pc = 0x801371B8u;
    ctx->downcount -= 3;
    // 801371B8: lwz     r0, 52(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801371BC:
    ctx->pc = 0x801371BCu;
    // 801371BC: cmpwi   r0, 0
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

label_801371C0:
    ctx->pc = 0x801371C0u;
    // 801371C0: bc    4, 1, 0x8013725C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013725C;
        }
    }

label_801371C4:
    ctx->pc = 0x801371C4u;
    ctx->downcount -= 3;
    // 801371C4: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_801371C8:
    ctx->pc = 0x801371C8u;
    // 801371C8: cmpw    r31, r0
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

label_801371CC:
    ctx->pc = 0x801371CCu;
    // 801371CC: bc    4, 0, 0x8013725C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013725C;
        }
    }

label_801371D0:
    ctx->pc = 0x801371D0u;
    ctx->downcount -= 1;
    // 801371D0: lis     r25, -32736
    ctx->gpr[25] = ((u32)(s32)(-32736) << 16);

label_801371D4:
    ctx->downcount -= 3;
    // 801371D4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801371D8:
    // 801371D8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801371DC:
    // 801371DC: bl      0x800470D8
    {
            ctx->lr = 0x801371E0u;
            ctx->pc = 0x800470D8u;
            return;
    }

label_801371E0:
    ctx->downcount -= 3;
    // 801371E0: addi    r28, r31, 1
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(1);

label_801371E4:
    // 801371E4: or.   r31, r3, r3
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

label_801371E8:
    // 801371E8: bc    12, 2, 0x8013724C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013724C;
        }
    }

label_801371EC:
    ctx->pc = 0x801371ECu;
    ctx->downcount -= 3;
    // 801371EC: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801371F0:
    // 801371F0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_801371F4:
    // 801371F4: bl      0x80048188
    {
            ctx->lr = 0x801371F8u;
            ctx->pc = 0x80048188u;
            return;
    }

label_801371F8:
    ctx->downcount -= 3;
    // 801371F8: addi    r3, r3, -1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-1);

label_801371FC:
    // 801371FC: cmplwi  r3, 0x001C
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x001Cu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80137200:
    // 80137200: bc    12, 1, 0x8013724C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8013724C;
        }
    }

label_80137204:
    ctx->pc = 0x80137204u;
    ctx->downcount -= 4;
    // 80137204: lwz     r4, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80137208:
    // 80137208: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8013720C:
    // 8013720C: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_80137210:
    // 80137210: bl      0x80048280
    {
            ctx->lr = 0x80137214u;
            ctx->pc = 0x80048280u;
            return;
    }

label_80137214:
    ctx->downcount -= 4;
    // 80137214: or.   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80137218:
    ctx->pc = 0x80137218u;
    // 80137218: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8013721C:
    // 8013721C: bc    4, 1, 0x8013724C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8013724C;
        }
    }

label_80137220:
    ctx->pc = 0x80137220u;
    ctx->downcount -= 3;
    // 80137220: mfctr    r31
    ctx->gpr[31] = ctx->ctr;

label_80137224:
    // 80137224: addi    r29, r25, 11952
    ctx->gpr[29] = ctx->gpr[25] + (u32)(s32)(11952);

label_80137228:
    // 80137228: addi    r30, r1, 8
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(8);

label_8013722C:
    ctx->pc = 0x8013722Cu;
    ctx->downcount -= 3;
    // 8013722C: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80137230:
    // 80137230: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_80137234:
    // 80137234: bl      0x800307D8
    {
            ctx->lr = 0x80137238u;
            ctx->pc = 0x800307D8u;
            return;
    }

label_80137238:
    ctx->downcount -= 5;
    // 80137238: mulli   r3, r3, 56
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)56);

label_8013723C:
    // 8013723C: add   r3, r3, r29
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80137240:
    // 80137240: bl      0x8003E7DC
    {
            ctx->lr = 0x80137244u;
            ctx->pc = 0x8003E7DCu;
            return;
    }

label_80137244:
    ctx->downcount -= 2;
    // 80137244: addic.  r31, r31, -1
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

label_80137248:
    // 80137248: bc    4, 2, 0x8013722C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8013722Cu;
                return;
            }
            goto label_8013722C;
        }
    }

label_8013724C:
    ctx->pc = 0x8013724Cu;
    ctx->downcount -= 4;
    // 8013724C: lwz     r0, 52(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80137250:
    // 80137250: or   r31, r28, r28
    {
        ctx->gpr[31] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80137254:
    // 80137254: cmpw    r31, r0
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

label_80137258:
    // 80137258: bc    12, 0, 0x801371D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801371D4u;
                return;
            }
            goto label_801371D4;
        }
    }

label_8013725C:
    ctx->pc = 0x8013725Cu;
    ctx->downcount -= 16;
    // 8013725C: lwz     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80137260:
    ctx->pc = 0x80137260u;
    // 80137260: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80137264:
    ctx->pc = 0x80137264u;
    // 80137264: lmw     r25, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80137268:
    ctx->pc = 0x80137268u;
    // 80137268: addi    r1, r1, 160
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(160);

label_8013726C:
    ctx->pc = 0x8013726Cu;
    // 8013726C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80137270:
    ctx->pc = 0x80137270u;
    ctx->downcount -= 5;
    // 80137270: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80137274:
    ctx->pc = 0x80137274u;
    // 80137274: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80137278:
    ctx->pc = 0x80137278u;
    // 80137278: stw     r0, -27020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27020);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8013727C:
    ctx->pc = 0x8013727Cu;
    // 8013727C: stw     r9, -27016(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27016);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80137280:
    ctx->pc = 0x80137280u;
    // 80137280: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_80137284:
    ctx->pc = 0x80137284u;
    ctx->downcount -= 6;
    // 80137284: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80137288:
    ctx->pc = 0x80137288u;
    // 80137288: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8013728C:
    ctx->pc = 0x8013728Cu;
    // 8013728C: stw     r9, -27036(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27036);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80137290:
    ctx->pc = 0x80137290u;
    // 80137290: stw     r0, -32272(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32272);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80137294:
    ctx->pc = 0x80137294u;
    // 80137294: stw     r9, -27040(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27040);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80137298:
    ctx->pc = 0x80137298u;
    // 80137298: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801332C0;
        }
    }

label_8013729C:
    ctx->pc = 0x8013729Cu;
    ctx->downcount -= 19;
    // 8013729C: stwu     r1, -336(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-336);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801372A0:
    ctx->pc = 0x801372A0u;
    // 801372A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801372A4:
    ctx->pc = 0x801372A4u;
    // 801372A4: stmw     r25, 308(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(308);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801372A8:
    ctx->pc = 0x801372A8u;
    // 801372A8: stw     r0, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801372AC:
    ctx->pc = 0x801372ACu;
    // 801372AC: lis     r9, -32736
    ctx->gpr[9] = ((u32)(s32)(-32736) << 16);

label_801372B0:
    ctx->pc = 0x801372B0u;
    // 801372B0: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_801372B4:
    ctx->pc = 0x801372B4u;
    // 801372B4: addi    r29, r9, 15368
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(15368);

label_801372B8:
    ctx->pc = 0x801372B8u;
    // 801372B8: lwz     r28, 36(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(36);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_801372BC:
    ctx->pc = 0x801372BCu;
    // 801372BC: cmpwi   r28, 0
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

    ctx->pc = 0x801372C0u;
    return;
return_dispatch_801332C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x801332D4u: goto label_801332D4;
    case 0x801332E8u: goto label_801332E8;
    case 0x80133314u: goto label_80133314;
    case 0x80133320u: goto label_80133320;
    case 0x80133334u: goto label_80133334;
    case 0x80133344u: goto label_80133344;
    case 0x8013339Cu: goto label_8013339C;
    case 0x801333B4u: goto label_801333B4;
    case 0x801333D0u: goto label_801333D0;
    case 0x8013340Cu: goto label_8013340C;
    case 0x80133420u: goto label_80133420;
    case 0x80133448u: goto label_80133448;
    case 0x80133464u: goto label_80133464;
    case 0x80133478u: goto label_80133478;
    case 0x80133488u: goto label_80133488;
    case 0x801334CCu: goto label_801334CC;
    case 0x801334DCu: goto label_801334DC;
    case 0x801334ECu: goto label_801334EC;
    case 0x801334FCu: goto label_801334FC;
    case 0x8013350Cu: goto label_8013350C;
    case 0x8013355Cu: goto label_8013355C;
    case 0x8013356Cu: goto label_8013356C;
    case 0x80133588u: goto label_80133588;
    case 0x80133598u: goto label_80133598;
    case 0x801335C0u: goto label_801335C0;
    case 0x801335F0u: goto label_801335F0;
    case 0x80133618u: goto label_80133618;
    case 0x8013362Cu: goto label_8013362C;
    case 0x8013363Cu: goto label_8013363C;
    case 0x80133690u: goto label_80133690;
    case 0x801336A0u: goto label_801336A0;
    case 0x801336C4u: goto label_801336C4;
    case 0x801336FCu: goto label_801336FC;
    case 0x80133710u: goto label_80133710;
    case 0x80133768u: goto label_80133768;
    case 0x80133780u: goto label_80133780;
    case 0x8013379Cu: goto label_8013379C;
    case 0x801337D4u: goto label_801337D4;
    case 0x801337E8u: goto label_801337E8;
    case 0x80133810u: goto label_80133810;
    case 0x80133828u: goto label_80133828;
    case 0x8013383Cu: goto label_8013383C;
    case 0x801338FCu: goto label_801338FC;
    case 0x80133934u: goto label_80133934;
    case 0x801339A4u: goto label_801339A4;
    case 0x801339F8u: goto label_801339F8;
    case 0x80133A34u: goto label_80133A34;
    case 0x80133A40u: goto label_80133A40;
    case 0x80133A60u: goto label_80133A60;
    case 0x80133A6Cu: goto label_80133A6C;
    case 0x80133B44u: goto label_80133B44;
    case 0x80133BA4u: goto label_80133BA4;
    case 0x80133BC8u: goto label_80133BC8;
    case 0x80133BCCu: goto label_80133BCC;
    case 0x80133BD0u: goto label_80133BD0;
    case 0x80133BD8u: goto label_80133BD8;
    case 0x80133BDCu: goto label_80133BDC;
    case 0x80133C78u: goto label_80133C78;
    case 0x80133CB4u: goto label_80133CB4;
    case 0x80133CDCu: goto label_80133CDC;
    case 0x80133D18u: goto label_80133D18;
    case 0x80133D30u: goto label_80133D30;
    case 0x80133D7Cu: goto label_80133D7C;
    case 0x80133E24u: goto label_80133E24;
    case 0x80133E3Cu: goto label_80133E3C;
    case 0x80133E50u: goto label_80133E50;
    case 0x80133E60u: goto label_80133E60;
    case 0x80133E78u: goto label_80133E78;
    case 0x80133E7Cu: goto label_80133E7C;
    case 0x80133E9Cu: goto label_80133E9C;
    case 0x80133EC4u: goto label_80133EC4;
    case 0x80133EE0u: goto label_80133EE0;
    case 0x80133F1Cu: goto label_80133F1C;
    case 0x80133F38u: goto label_80133F38;
    case 0x80133F74u: goto label_80133F74;
    case 0x80133F90u: goto label_80133F90;
    case 0x80133FCCu: goto label_80133FCC;
    case 0x80133FE8u: goto label_80133FE8;
    case 0x80134050u: goto label_80134050;
    case 0x80134064u: goto label_80134064;
    case 0x80134078u: goto label_80134078;
    case 0x801340DCu: goto label_801340DC;
    case 0x801341B4u: goto label_801341B4;
    case 0x801341C0u: goto label_801341C0;
    case 0x801341CCu: goto label_801341CC;
    case 0x8013421Cu: goto label_8013421C;
    case 0x80134244u: goto label_80134244;
    case 0x80134288u: goto label_80134288;
    case 0x80134294u: goto label_80134294;
    case 0x801342A8u: goto label_801342A8;
    case 0x801342B4u: goto label_801342B4;
    case 0x801342C4u: goto label_801342C4;
    case 0x801342C8u: goto label_801342C8;
    case 0x801342D0u: goto label_801342D0;
    case 0x801342E0u: goto label_801342E0;
    case 0x801342F4u: goto label_801342F4;
    case 0x80134308u: goto label_80134308;
    case 0x80134314u: goto label_80134314;
    case 0x80134328u: goto label_80134328;
    case 0x80134334u: goto label_80134334;
    case 0x80134344u: goto label_80134344;
    case 0x80134348u: goto label_80134348;
    case 0x80134350u: goto label_80134350;
    case 0x80134360u: goto label_80134360;
    case 0x80134374u: goto label_80134374;
    case 0x8013438Cu: goto label_8013438C;
    case 0x80134398u: goto label_80134398;
    case 0x801343ACu: goto label_801343AC;
    case 0x801343B8u: goto label_801343B8;
    case 0x801343C8u: goto label_801343C8;
    case 0x801343CCu: goto label_801343CC;
    case 0x801343D4u: goto label_801343D4;
    case 0x801343F8u: goto label_801343F8;
    case 0x8013440Cu: goto label_8013440C;
    case 0x8013441Cu: goto label_8013441C;
    case 0x80134434u: goto label_80134434;
    case 0x80134444u: goto label_80134444;
    case 0x80134450u: goto label_80134450;
    case 0x80134464u: goto label_80134464;
    case 0x80134470u: goto label_80134470;
    case 0x80134480u: goto label_80134480;
    case 0x80134490u: goto label_80134490;
    case 0x801344A4u: goto label_801344A4;
    case 0x801344BCu: goto label_801344BC;
    case 0x801344CCu: goto label_801344CC;
    case 0x801344E0u: goto label_801344E0;
    case 0x801344ECu: goto label_801344EC;
    case 0x801344FCu: goto label_801344FC;
    case 0x8013452Cu: goto label_8013452C;
    case 0x8013453Cu: goto label_8013453C;
    case 0x80134544u: goto label_80134544;
    case 0x801345A0u: goto label_801345A0;
    case 0x801345A8u: goto label_801345A8;
    case 0x8013460Cu: goto label_8013460C;
    case 0x80134614u: goto label_80134614;
    case 0x80134678u: goto label_80134678;
    case 0x80134680u: goto label_80134680;
    case 0x801346E4u: goto label_801346E4;
    case 0x801346F8u: goto label_801346F8;
    case 0x80134714u: goto label_80134714;
    case 0x80134728u: goto label_80134728;
    case 0x80134748u: goto label_80134748;
    case 0x8013475Cu: goto label_8013475C;
    case 0x80134794u: goto label_80134794;
    case 0x801347A8u: goto label_801347A8;
    case 0x801347B8u: goto label_801347B8;
    case 0x801347CCu: goto label_801347CC;
    case 0x801347DCu: goto label_801347DC;
    case 0x801347F0u: goto label_801347F0;
    case 0x80134800u: goto label_80134800;
    case 0x80134814u: goto label_80134814;
    case 0x80134838u: goto label_80134838;
    case 0x80134848u: goto label_80134848;
    case 0x8013485Cu: goto label_8013485C;
    case 0x8013486Cu: goto label_8013486C;
    case 0x80134880u: goto label_80134880;
    case 0x80134888u: goto label_80134888;
    case 0x80134898u: goto label_80134898;
    case 0x801348CCu: goto label_801348CC;
    case 0x801348D4u: goto label_801348D4;
    case 0x801348E4u: goto label_801348E4;
    case 0x80134920u: goto label_80134920;
    case 0x80134934u: goto label_80134934;
    case 0x80134944u: goto label_80134944;
    case 0x80134954u: goto label_80134954;
    case 0x8013496Cu: goto label_8013496C;
    case 0x80134978u: goto label_80134978;
    case 0x8013498Cu: goto label_8013498C;
    case 0x801349C0u: goto label_801349C0;
    case 0x801349D0u: goto label_801349D0;
    case 0x801349E4u: goto label_801349E4;
    case 0x80134A68u: goto label_80134A68;
    case 0x80134A7Cu: goto label_80134A7C;
    case 0x80134B4Cu: goto label_80134B4C;
    case 0x80134B60u: goto label_80134B60;
    case 0x80134C30u: goto label_80134C30;
    case 0x80134C44u: goto label_80134C44;
    case 0x80134CECu: goto label_80134CEC;
    case 0x80134D00u: goto label_80134D00;
    case 0x80134D88u: goto label_80134D88;
    case 0x80134D9Cu: goto label_80134D9C;
    case 0x80134DECu: goto label_80134DEC;
    case 0x80134E00u: goto label_80134E00;
    case 0x80134E1Cu: goto label_80134E1C;
    case 0x80134E64u: goto label_80134E64;
    case 0x80134EBCu: goto label_80134EBC;
    case 0x80134F0Cu: goto label_80134F0C;
    case 0x80134F20u: goto label_80134F20;
    case 0x80134F3Cu: goto label_80134F3C;
    case 0x80134F84u: goto label_80134F84;
    case 0x80134FDCu: goto label_80134FDC;
    case 0x80135008u: goto label_80135008;
    case 0x80135018u: goto label_80135018;
    case 0x8013502Cu: goto label_8013502C;
    case 0x8013503Cu: goto label_8013503C;
    case 0x80135050u: goto label_80135050;
    case 0x80135058u: goto label_80135058;
    case 0x80135068u: goto label_80135068;
    case 0x801350A0u: goto label_801350A0;
    case 0x801350A8u: goto label_801350A8;
    case 0x801350B8u: goto label_801350B8;
    case 0x801350F4u: goto label_801350F4;
    case 0x80135108u: goto label_80135108;
    case 0x80135118u: goto label_80135118;
    case 0x80135128u: goto label_80135128;
    case 0x80135140u: goto label_80135140;
    case 0x80135150u: goto label_80135150;
    case 0x80135164u: goto label_80135164;
    case 0x80135190u: goto label_80135190;
    case 0x801351A0u: goto label_801351A0;
    case 0x801351B4u: goto label_801351B4;
    case 0x801351D8u: goto label_801351D8;
    case 0x801351ECu: goto label_801351EC;
    case 0x8013521Cu: goto label_8013521C;
    case 0x80135238u: goto label_80135238;
    case 0x80135248u: goto label_80135248;
    case 0x80135258u: goto label_80135258;
    case 0x80135264u: goto label_80135264;
    case 0x80135274u: goto label_80135274;
    case 0x80135288u: goto label_80135288;
    case 0x80135298u: goto label_80135298;
    case 0x801352A8u: goto label_801352A8;
    case 0x801352B8u: goto label_801352B8;
    case 0x801352CCu: goto label_801352CC;
    case 0x801352E4u: goto label_801352E4;
    case 0x80135300u: goto label_80135300;
    case 0x80135310u: goto label_80135310;
    case 0x80135324u: goto label_80135324;
    case 0x80135334u: goto label_80135334;
    case 0x80135348u: goto label_80135348;
    case 0x80135378u: goto label_80135378;
    case 0x80135388u: goto label_80135388;
    case 0x8013539Cu: goto label_8013539C;
    case 0x801353ACu: goto label_801353AC;
    case 0x801353C0u: goto label_801353C0;
    case 0x801353C8u: goto label_801353C8;
    case 0x801353D8u: goto label_801353D8;
    case 0x8013540Cu: goto label_8013540C;
    case 0x80135414u: goto label_80135414;
    case 0x80135424u: goto label_80135424;
    case 0x80135460u: goto label_80135460;
    case 0x80135474u: goto label_80135474;
    case 0x80135484u: goto label_80135484;
    case 0x8013549Cu: goto label_8013549C;
    case 0x801354ACu: goto label_801354AC;
    case 0x801354C0u: goto label_801354C0;
    case 0x801354ECu: goto label_801354EC;
    case 0x801354FCu: goto label_801354FC;
    case 0x80135510u: goto label_80135510;
    case 0x80135530u: goto label_80135530;
    case 0x80135544u: goto label_80135544;
    case 0x80135574u: goto label_80135574;
    case 0x80135590u: goto label_80135590;
    case 0x801355A0u: goto label_801355A0;
    case 0x801355B0u: goto label_801355B0;
    case 0x801355BCu: goto label_801355BC;
    case 0x801355CCu: goto label_801355CC;
    case 0x801355E0u: goto label_801355E0;
    case 0x801355F0u: goto label_801355F0;
    case 0x80135600u: goto label_80135600;
    case 0x80135610u: goto label_80135610;
    case 0x80135624u: goto label_80135624;
    case 0x8013563Cu: goto label_8013563C;
    case 0x8013565Cu: goto label_8013565C;
    case 0x8013566Cu: goto label_8013566C;
    case 0x80135680u: goto label_80135680;
    case 0x80135690u: goto label_80135690;
    case 0x801356A4u: goto label_801356A4;
    case 0x801356F0u: goto label_801356F0;
    case 0x80135708u: goto label_80135708;
    case 0x80135728u: goto label_80135728;
    case 0x80135740u: goto label_80135740;
    case 0x80135754u: goto label_80135754;
    case 0x8013576Cu: goto label_8013576C;
    case 0x8013577Cu: goto label_8013577C;
    case 0x80135798u: goto label_80135798;
    case 0x801357A4u: goto label_801357A4;
    case 0x801357B8u: goto label_801357B8;
    case 0x801357C8u: goto label_801357C8;
    case 0x801357D4u: goto label_801357D4;
    case 0x801357E0u: goto label_801357E0;
    case 0x801357F0u: goto label_801357F0;
    case 0x801357FCu: goto label_801357FC;
    case 0x8013580Cu: goto label_8013580C;
    case 0x80135824u: goto label_80135824;
    case 0x80135838u: goto label_80135838;
    case 0x80135878u: goto label_80135878;
    case 0x801358A0u: goto label_801358A0;
    case 0x801358B8u: goto label_801358B8;
    case 0x801358C4u: goto label_801358C4;
    case 0x801358D8u: goto label_801358D8;
    case 0x801358ECu: goto label_801358EC;
    case 0x801358F8u: goto label_801358F8;
    case 0x80135908u: goto label_80135908;
    case 0x8013591Cu: goto label_8013591C;
    case 0x8013592Cu: goto label_8013592C;
    case 0x8013593Cu: goto label_8013593C;
    case 0x8013594Cu: goto label_8013594C;
    case 0x80135960u: goto label_80135960;
    case 0x80135978u: goto label_80135978;
    case 0x8013599Cu: goto label_8013599C;
    case 0x801359ACu: goto label_801359AC;
    case 0x801359C0u: goto label_801359C0;
    case 0x801359DCu: goto label_801359DC;
    case 0x801359FCu: goto label_801359FC;
    case 0x80135A24u: goto label_80135A24;
    case 0x80135A34u: goto label_80135A34;
    case 0x80135A48u: goto label_80135A48;
    case 0x80135A54u: goto label_80135A54;
    case 0x80135A68u: goto label_80135A68;
    case 0x80135A74u: goto label_80135A74;
    case 0x80135A80u: goto label_80135A80;
    case 0x80135A8Cu: goto label_80135A8C;
    case 0x80135A9Cu: goto label_80135A9C;
    case 0x80135AA8u: goto label_80135AA8;
    case 0x80135ABCu: goto label_80135ABC;
    case 0x80135AC8u: goto label_80135AC8;
    case 0x80135AD4u: goto label_80135AD4;
    case 0x80135AE8u: goto label_80135AE8;
    case 0x80135AF4u: goto label_80135AF4;
    case 0x80135B08u: goto label_80135B08;
    case 0x80135B1Cu: goto label_80135B1C;
    case 0x80135B34u: goto label_80135B34;
    case 0x80135B40u: goto label_80135B40;
    case 0x80135B50u: goto label_80135B50;
    case 0x80135B60u: goto label_80135B60;
    case 0x80135B6Cu: goto label_80135B6C;
    case 0x80135B7Cu: goto label_80135B7C;
    case 0x80135B98u: goto label_80135B98;
    case 0x80135BB4u: goto label_80135BB4;
    case 0x80135BD0u: goto label_80135BD0;
    case 0x80135BE0u: goto label_80135BE0;
    case 0x80135BE4u: goto label_80135BE4;
    case 0x80135BF0u: goto label_80135BF0;
    case 0x80135D1Cu: goto label_80135D1C;
    case 0x80135DB8u: goto label_80135DB8;
    case 0x80135E7Cu: goto label_80135E7C;
    case 0x80135EACu: goto label_80135EAC;
    case 0x80135EB8u: goto label_80135EB8;
    case 0x80135ECCu: goto label_80135ECC;
    case 0x80135EFCu: goto label_80135EFC;
    case 0x80135F08u: goto label_80135F08;
    case 0x80135F18u: goto label_80135F18;
    case 0x80135F24u: goto label_80135F24;
    case 0x80135F50u: goto label_80135F50;
    case 0x80135F64u: goto label_80135F64;
    case 0x80135F9Cu: goto label_80135F9C;
    case 0x8013601Cu: goto label_8013601C;
    case 0x80136024u: goto label_80136024;
    case 0x8013605Cu: goto label_8013605C;
    case 0x801360A4u: goto label_801360A4;
    case 0x801360ACu: goto label_801360AC;
    case 0x8013614Cu: goto label_8013614C;
    case 0x80136154u: goto label_80136154;
    case 0x80136178u: goto label_80136178;
    case 0x801361C4u: goto label_801361C4;
    case 0x8013620Cu: goto label_8013620C;
    case 0x8013621Cu: goto label_8013621C;
    case 0x80136224u: goto label_80136224;
    case 0x80136270u: goto label_80136270;
    case 0x80136278u: goto label_80136278;
    case 0x80136318u: goto label_80136318;
    case 0x80136368u: goto label_80136368;
    case 0x80136374u: goto label_80136374;
    case 0x80136414u: goto label_80136414;
    case 0x80136438u: goto label_80136438;
    case 0x80136448u: goto label_80136448;
    case 0x80136450u: goto label_80136450;
    case 0x801364A0u: goto label_801364A0;
    case 0x801364ACu: goto label_801364AC;
    case 0x80136540u: goto label_80136540;
    case 0x801365B0u: goto label_801365B0;
    case 0x80136620u: goto label_80136620;
    case 0x80136690u: goto label_80136690;
    case 0x80136710u: goto label_80136710;
    case 0x8013676Cu: goto label_8013676C;
    case 0x801367DCu: goto label_801367DC;
    case 0x8013684Cu: goto label_8013684C;
    case 0x801368BCu: goto label_801368BC;
    case 0x8013693Cu: goto label_8013693C;
    case 0x80136970u: goto label_80136970;
    case 0x801369F4u: goto label_801369F4;
    case 0x80136A04u: goto label_80136A04;
    case 0x80136A98u: goto label_80136A98;
    case 0x80136AA4u: goto label_80136AA4;
    case 0x80136AD8u: goto label_80136AD8;
    case 0x80136B64u: goto label_80136B64;
    case 0x80136B94u: goto label_80136B94;
    case 0x80136B98u: goto label_80136B98;
    case 0x80136BACu: goto label_80136BAC;
    case 0x80136BD4u: goto label_80136BD4;
    case 0x80136C54u: goto label_80136C54;
    case 0x80136C84u: goto label_80136C84;
    case 0x80136C88u: goto label_80136C88;
    case 0x80136C94u: goto label_80136C94;
    case 0x80136CC4u: goto label_80136CC4;
    case 0x80136D38u: goto label_80136D38;
    case 0x80136D44u: goto label_80136D44;
    case 0x80136D74u: goto label_80136D74;
    case 0x80136D84u: goto label_80136D84;
    case 0x80136DE8u: goto label_80136DE8;
    case 0x80136E5Cu: goto label_80136E5C;
    case 0x80136E6Cu: goto label_80136E6C;
    case 0x80136E88u: goto label_80136E88;
    case 0x80136EA0u: goto label_80136EA0;
    case 0x80136EA8u: goto label_80136EA8;
    case 0x80136EBCu: goto label_80136EBC;
    case 0x80136F30u: goto label_80136F30;
    case 0x80136F3Cu: goto label_80136F3C;
    case 0x80136F68u: goto label_80136F68;
    case 0x80136FF4u: goto label_80136FF4;
    case 0x80136FF8u: goto label_80136FF8;
    case 0x80136FFCu: goto label_80136FFC;
    case 0x80137004u: goto label_80137004;
    case 0x8013700Cu: goto label_8013700C;
    case 0x80137024u: goto label_80137024;
    case 0x80137040u: goto label_80137040;
    case 0x8013708Cu: goto label_8013708C;
    case 0x80137094u: goto label_80137094;
    case 0x801370ACu: goto label_801370AC;
    case 0x801370B4u: goto label_801370B4;
    case 0x801370FCu: goto label_801370FC;
    case 0x80137104u: goto label_80137104;
    case 0x80137114u: goto label_80137114;
    case 0x80137134u: goto label_80137134;
    case 0x8013713Cu: goto label_8013713C;
    case 0x8013715Cu: goto label_8013715C;
    case 0x80137164u: goto label_80137164;
    case 0x801371E0u: goto label_801371E0;
    case 0x801371F8u: goto label_801371F8;
    case 0x80137214u: goto label_80137214;
    case 0x80137238u: goto label_80137238;
    case 0x80137244u: goto label_80137244;
    default: return;
    }
}

