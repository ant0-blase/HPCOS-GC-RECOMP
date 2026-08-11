// SPDX-License-Identifier: GPL-3.0-or-later
#include "hle.h"
#include "gxruntime/hle.h"
#include "gxruntime/hle_abi.h"
#include "host/audio.h"
#include "host/interrupt.h"
#include "host/sdk_map.h"
#include "host/hle_physics.h"
#include "host/hle_input.h"
#include "host/hle_offsets.h"

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef void (*HleHandler)(CPUState* cpu);

typedef struct {
    const char* name;
    HleHandler  fn;
} HleEntry;

typedef struct {
    u32         address;
    HleHandler  fn;
    const char* name;
} HleAddrEntry;

typedef struct {
    HleHandler intercept;
    HleHandler notify;
} HleDispatchEntry;

// Globals for Strikers HLE layer
static bool g_movie_log = false;
static bool g_movie_cadence_log = false;
static bool g_auto_skip_card_prompt = false;
static bool g_state_log = false;
static u64 g_auto_input_last_pulse = ~(u64)0;
static u64 g_auto_input_once_frame = 0;
static u64 g_auto_input_once_sent = ~(u64)0;
static u64 g_auto_skip_card_last_pulse = ~(u64)0;
static u64 g_movie_cadence_present_count;
static u64 g_movie_cadence_texframe_changes;
static double g_movie_cadence_start_time;
static s32 g_movie_cadence_last_texframe;
static bool g_movie_cadence_started;

#ifdef STRIKERSRECOMP_AURORA
static u32 g_gx_begin_count;
#endif

// ---------------------------------------------------------------------------
// Strikers specific notify wrappers and logging helpers
// ---------------------------------------------------------------------------

static double host_time_seconds(void) {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1000000000.0;
}

static u32 thp_audio_valid_samples(CPUState* cpu, u32* output_valid) {
    const u32 base = STRIKERS_THP_SIMPLE_CONTROL; // THP_SIMPLE_CONTROL
    u32 total = 0;
    for (u32 i = 0; i < 6u; i++)
        total += mem_read32(cpu, base + 0x16Cu + i * 12u + 8u);

    if (output_valid != NULL) {
        const u32 output_index = mem_read32(cpu, base + 0x1B8u);
        *output_valid = output_index < 6u
            ? mem_read32(cpu, base + 0x16Cu + output_index * 12u + 8u)
            : 0u;
    }
    return total;
}

static void movie_cadence_present(CPUState* cpu) {
    if (!g_movie_cadence_log)
        return;

    const u32 base = STRIKERS_THP_SIMPLE_CONTROL; // THP_SIMPLE_CONTROL
    if (mem_read8(cpu, base + 0x6Cu) == 0u) {
        g_movie_cadence_started = false;
        return;
    }

    const s32 tex_frame = (s32)mem_read32(cpu, base + 0x168u);
    const double now = host_time_seconds();
    if (!g_movie_cadence_started) {
        g_movie_cadence_started = true;
        g_movie_cadence_start_time = now;
        g_movie_cadence_present_count = 0;
        g_movie_cadence_texframe_changes = 0;
        g_movie_cadence_last_texframe = tex_frame;
    }

    g_movie_cadence_present_count++;
    if (tex_frame != g_movie_cadence_last_texframe) {
        g_movie_cadence_texframe_changes++;
        g_movie_cadence_last_texframe = tex_frame;
    }

    const double elapsed = now - g_movie_cadence_start_time;
    if (elapsed >= 1.0) {
        u32 audio_output_valid = 0;
        const u32 audio_valid = thp_audio_valid_samples(cpu, &audio_output_valid);
        fprintf(stderr,
                "[movie-cadence] seconds=%.3f presents=%llu "
                "texframe_changes=%llu last_texframe=%d audio_dec=%u "
                "audio_out=%u audio_valid=%u audio_out_valid=%u\n",
                elapsed,
                (unsigned long long)g_movie_cadence_present_count,
                (unsigned long long)g_movie_cadence_texframe_changes,
                g_movie_cadence_last_texframe,
                mem_read32(cpu, base + 0x1B4u),
                mem_read32(cpu, base + 0x1B8u),
                audio_valid,
                audio_output_valid);
        g_movie_cadence_start_time = now;
        g_movie_cadence_present_count = 0;
        g_movie_cadence_texframe_changes = 0;
    }
}

static bool guest_backchain_contains(CPUState* cpu, u32 start, u32 end) {
    if (cpu->lr >= start && cpu->lr < end)
        return true;
    u32 sp = cpu->gpr[1];
    const u32 ram_end = GC_RAM_BASE + cpu->ram_size;
    for (unsigned frame = 0; frame < 24u; ++frame) {
        if (sp < GC_RAM_BASE || sp + 8u > ram_end)
            break;
        const u32 caller = mem_read32(cpu, sp);
        if (caller <= sp || caller < GC_RAM_BASE || caller + 8u > ram_end)
            break;
        const u32 ret = mem_read32(cpu, caller + 4u);
        if (ret >= start && ret < end)
            return true;
        sp = caller;
    }
    return false;
}

static void matrix_log_floats(CPUState* cpu, const char* name, u32 addr, u32 count) {
    fprintf(stderr, "[matrix] %s addr=0x%08X:\n", name, addr);
    for (u32 row = 0; row < count / 4u; row++) {
        fprintf(stderr, "  % .7g % .7g % .7g % .7g\n",
                (double)guest_read_f32(cpu, addr + row * 16u),
                (double)guest_read_f32(cpu, addr + row * 16u + 4u),
                (double)guest_read_f32(cpu, addr + row * 16u + 8u),
                (double)guest_read_f32(cpu, addr + row * 16u + 12u));
    }
}

static void matrix_log_frame(CPUState* cpu) {
    static int matrix_log_enabled = -1;
    if (matrix_log_enabled < 0)
        matrix_log_enabled = getenv("STRIKERS_MATRIX_LOG") != NULL ? 1 : 0;
    if (!matrix_log_enabled)
        return;

    static unsigned frame_matrix_count = 0;
    if (frame_matrix_count >= 120u)
        return;
    ++frame_matrix_count;
    matrix_log_floats(cpu, "gx_proj     ", STRIKERS_GX_PROJ_MATRIX, 16u);
    matrix_log_floats(cpu, "gx_modelview", STRIKERS_GX_MODELVIEW_MATRIX, 12u);
    matrix_log_floats(cpu, "gx_mview    ", STRIKERS_GX_MVIEW_MATRIX, 12u);
}

// ---------------------------------------------------------------------------
// Custom Notify Hooks
// ---------------------------------------------------------------------------

static void notify_OSSleepThread(CPUState* cpu) {
    if (g_hle_log) {
        fprintf(stderr, "[trace] OSSleepThread queue=0x%08X context=0x%08X\n",
                hle_arg_u32(cpu, 0), mem_read32(cpu, STRIKERS_OS_CONTEXT_POINTER));
    }
}

static void notify_DSPSendMailToDSP(CPUState* cpu) {
    audio_dsp_mail(cpu, hle_arg_u32(cpu, 0));
}

static void notify_audio_api(CPUState* cpu) {
    (void)cpu;
}

static void notify_OSResetSystem(CPUState* cpu) {
    if (g_hle_log) {
        fprintf(stderr, "[hle] OSResetSystem reset=%u forceMenu=%u\n",
                hle_arg_u32(cpu, 0), hle_arg_u32(cpu, 1));
    }
}

static void notify_OSLoadContext(CPUState* cpu) {
    interrupt_restore_fpu_context(cpu, hle_arg_u32(cpu, 0));
}

static void notify_SetNextState(CPUState* cpu) {
    u32 manager = hle_arg_u32(cpu, 0);
    s32 state = (s32)hle_arg_u32(cpu, 1);
    if (g_hle_log)
        fprintf(stderr, "[state] nlTaskManager::SetNextState manager=0x%08X state=%d\n",
                manager, state);
}

static void notify_TaskManagerStartup(CPUState* cpu) {
    u32 manager = hle_arg_u32(cpu, 0);
    if (g_hle_log)
        fprintf(stderr, "[state] nlTaskManager::Startup manager=0x%08X\n", manager);
}

static void notify_SHMainMenuUpdate(CPUState* cpu) {
    u32 menu = hle_arg_u32(cpu, 0);
    if (g_hle_log) {
        static s32 last_state = -1;
        s32 state = (s32)mem_read32(cpu, menu + 0x10u);
        if (state != last_state) {
            fprintf(stderr, "[state] SHMainMenu::Update menu=0x%08X state %d -> %d\n",
                    menu, last_state, state);
            last_state = state;
        }
    }
}

static void notify_IChooseSideCheckControllers(CPUState* cpu) {
    u32 choose_side = hle_arg_u32(cpu, 0);
    if (g_hle_log) {
        static s32 last_state = -1;
        s32 state = (s32)mem_read32(cpu, choose_side + 0x10u);
        if (state != last_state) {
            fprintf(stderr, "[state] IChooseSide::CheckControllers menu=0x%08X state %d -> %d\n",
                    choose_side, last_state, state);
            last_state = state;
        }
    }
}

static void notify_IChooseSidePositionController(CPUState* cpu) {
    u32 choose_side = hle_arg_u32(cpu, 0);
    if (g_hle_log) {
        static s32 last_state = -1;
        s32 state = (s32)mem_read32(cpu, choose_side + 0x10u);
        if (state != last_state) {
            fprintf(stderr, "[state] IChooseSide::PositionController menu=0x%08X state %d -> %d\n",
                    choose_side, last_state, state);
            last_state = state;
        }
    }
}

static void notify_MovieStart(CPUState* cpu) {
    (void)cpu;
    if (g_movie_log)
        fprintf(stderr, "[movie] MovieStart\n");
}

static void notify_MovieStop(CPUState* cpu) {
    (void)cpu;
    if (g_movie_log)
        fprintf(stderr, "[movie] MovieStop\n");
}

static void notify_MoviePlay(CPUState* cpu) {
    (void)cpu;
}

static void notify_THPSimpleOpen(CPUState* cpu) {
    char filename[256];
    hle_read_cstr(cpu, hle_arg_u32(cpu, 0), filename, sizeof filename);
    if (g_movie_log)
        fprintf(stderr, "[movie] THPSimpleOpen filename='%s'\n", filename);
}

static void notify_THPSimpleSetBuffer(CPUState* cpu) {
    if (g_movie_log)
        fprintf(stderr, "[movie] THPSimpleSetBuffer buffer=0x%08X\n", hle_arg_u32(cpu, 0));
}

static void notify_THPSimplePreLoad(CPUState* cpu) {
    if (g_movie_log)
        fprintf(stderr, "[movie] THPSimplePreLoad\n");
}

static void notify_THPSimpleDecode(CPUState* cpu) {
    (void)cpu;
}

static void notify_THPVideoDecode(CPUState* cpu) {
    (void)cpu;
}

static void notify_THPVideoDecodeReturn(CPUState* cpu) {
    (void)cpu;
}

static void notify_THPSimpleDecodeReturn(CPUState* cpu) {
    (void)cpu;
}

static void notify_LCEnable(CPUState* cpu) {
    (void)cpu;
}

static void notify_LCDisable(CPUState* cpu) {
    (void)cpu;
}

static void notify_GXBegin(CPUState* cpu) {
#ifdef STRIKERSRECOMP_AURORA
    ++g_gx_begin_count;
    if (ball_state_log_enabled() && guest_backchain_contains(cpu, STRIKERS_BALL_DRAW_FUN_START, STRIKERS_BALL_DRAW_FUN_END)) {
        fprintf(stderr, "[ball-draw] guest-frame=%llu begin=%u prim=%u fmt=%u count=%u lr=0x%08X\n",
                (unsigned long long)(cpu->timebase / 675000ull),
                g_gx_begin_count, hle_arg_u32(cpu, 0), hle_arg_u32(cpu, 1),
                hle_arg_u32(cpu, 2), cpu->lr);
    }
#endif
}

static void notify_GXLoadPosMtxImm(CPUState* cpu) {
    static int matrix_log_enabled = -1;
    if (matrix_log_enabled < 0)
        matrix_log_enabled = getenv("STRIKERS_MATRIX_LOG") != NULL ? 1 : 0;
    const bool ball_load = ball_state_log_enabled() && guest_backchain_contains(cpu, STRIKERS_BALL_DRAW_FUN_START, STRIKERS_BALL_DRAW_FUN_END);
    if (!matrix_log_enabled && !ball_load)
        return;

    const u32 mtx_addr = hle_arg_u32(cpu, 0);
    const u32 pn_idx = hle_arg_u32(cpu, 1);
    u8 raw[48];
    copy_guest_to_host(cpu, mtx_addr, raw, sizeof raw);
    float m[12];
    for (int i = 0; i < 12; i++) {
        u32 b = ((u32)raw[i * 4] << 24) | ((u32)raw[i * 4 + 1] << 16) |
                ((u32)raw[i * 4 + 2] << 8) | (u32)raw[i * 4 + 3];
        memcpy(&m[i], &b, sizeof(float));
    }
    if (ball_load) {
        static unsigned ball_matrix_count = 0;
        ++ball_matrix_count;
        if (ball_matrix_count <= 40u || (ball_matrix_count % 60u) == 0u) {
            fprintf(stderr,
                    "[ball-posmtx] load=%u guest-frame=%llu begin=%u "
                    "addr=0x%08X pn=%u lr=0x%08X\n"
                    "  % .7g % .7g % .7g % .7g\n"
                    "  % .7g % .7g % .7g % .7g\n"
                    "  % .7g % .7g % .7g % .7g\n",
                    ball_matrix_count,
                    (unsigned long long)(cpu->timebase / 675000ull),
#ifdef STRIKERSRECOMP_AURORA
                    g_gx_begin_count,
#else
                    0u,
#endif
                    mtx_addr, pn_idx, cpu->lr,
                    (double)m[0], (double)m[1], (double)m[2], (double)m[3],
                    (double)m[4], (double)m[5], (double)m[6], (double)m[7],
                    (double)m[8], (double)m[9], (double)m[10], (double)m[11]);
        }
    }
}

static void notify_GXCopyTex(CPUState* cpu) {
    (void)cpu;
}

static void notify_GXCopyDisp(CPUState* cpu) {
    // DIAG logic
    {
        static int s_cutscene_diag = -1;
        if (s_cutscene_diag < 0)
            s_cutscene_diag = getenv("STRIKERS_CUTSCENE_DIAG") != NULL ? 1 : 0;
        if (s_cutscene_diag) {
            static u64 s_diag_frame = 0;
            u8 render_world = mem_read8(cpu, STRIKERS_RENDER_WORLD_GLOBAL); // g_bRenderWorld
            fprintf(stderr, "[cutscene] frame=%llu g_bRenderWorld=%u\n",
                    (unsigned long long)++s_diag_frame, render_world);
        }
    }
    matrix_log_frame(cpu);
    movie_cadence_present(cpu);
    dol_hle_GXCopyDisp(cpu);
}

static void notify_VIConfigure(CPUState* cpu) {
    (void)cpu;
}

static void notify_VIWaitForRetrace(CPUState* cpu) {
    (void)cpu;
}

static void notify_GXLoadTexObj(CPUState* cpu) {
    (void)cpu;
}

static void notify_GXLoadTlut(CPUState* cpu) {
    (void)cpu;
}

static void strikers_hle_GXBegin(CPUState* cpu) {
    notify_GXBegin(cpu);
    dol_hle_GXBegin(cpu);
}

// ---------------------------------------------------------------------------
// Input Script & Custom PAD Handlers
// ---------------------------------------------------------------------------

static void hle_PADRead(CPUState* cpu) {
    // 1. Call clean standard pad read
    dol_hle_PADRead(cpu);

    // 2. Read what standard pad read wrote to memory
    u32 out = hle_arg_u32(cpu, 0);
    u16 buttons = mem_read16(cpu, out);
    s8 stick_x = (s8)mem_read8(cpu, out + 2u);
    s8 stick_y = (s8)mem_read8(cpu, out + 3u);
    u8 analog_a = mem_read8(cpu, out + 8u);
    bool connected = mem_read8(cpu, out + 10u) == 0;

    // 3. Apply custom test scripts
    if (g_auto_input) {
        const u64 frame = cpu->timebase / 675000ull;
        if (frame >= 135u && ((frame - 135u) % 90u) < 12u) {
            buttons |= 0x0100u; // A
            analog_a = 0xFFu;
            connected = true;
        }
    }
    if (input_script_apply(cpu, &buttons, &stick_x, &stick_y, &analog_a))
        connected = true;

    // Mash to gameplay screens
    mash_to_gameplay_apply(cpu, &buttons, &stick_x, &analog_a);
    if (g_mash_to_gameplay)
        connected = true;

    // 4. Write back to guest memory
    mem_write16(cpu, out, buttons);
    mem_write8(cpu, out + 2u, (u8)stick_x);
    mem_write8(cpu, out + 3u, (u8)stick_y);
    mem_write8(cpu, out + 8u, analog_a);
    mem_write8(cpu, out + 10u, (u8)(connected ? 0 : -1));
}


// ---------------------------------------------------------------------------
// Handler registry
// ---------------------------------------------------------------------------

static const HleEntry kHandlers[] = {
    { "OSReport",          dol_hle_OSReport },
    { "ARInit",            dol_hle_ARInit },
    { "ARGetBaseAddress",  dol_hle_ARGetBaseAddress },
    { "ARGetSize",         dol_hle_ARGetSize },
    { "ARGetDMAStatus",    dol_hle_ARGetDMAStatus },
    { "ARStartDMA",        dol_hle_ARStartDMA },
    { "CARDInit",          dol_hle_CARDInit },
    { "CARDProbe",         dol_hle_CARDProbe },
    { "CARDProbeEx",       dol_hle_CARDProbeEx },
    { "CARDGetResultCode", dol_hle_CARDGetResultCode },
    { "CARDGetFastMode",   dol_hle_CARDGetFastMode },
    { "CARDGetXferredBytes", dol_hle_CARDGetXferredBytes },
    { "CARDMountAsync",    dol_hle_CARDMountAsync },
    { "CARDCheckExAsync",  dol_hle_CARDCheckExAsync },
    { "CARDCheckAsync",    dol_hle_CARDCheckAsync },
    { "CARDFreeBlocks",    dol_hle_CARDFreeBlocks },
    { "CARDOpen",          dol_hle_CARDOpen },
    { "CARDCreateAsync",   dol_hle_CARDCreateAsync },
    { "CARDDeleteAsync",   dol_hle_CARDDeleteAsync },
    { "CARDGetStatus",     dol_hle_CARDGetStatus },
    { "CARDSetStatusAsync", dol_hle_CARDSetStatusAsync },
    { "CARDGetSerialNo",   dol_hle_CARDGetSerialNo },
    { "CARDUnmount",       dol_hle_CARDUnmount },
    { "CARDClose",         dol_hle_CARDClose },
    { "CARDReadAsync",     dol_hle_CARDReadAsync },
    { "CARDWriteAsync",    dol_hle_CARDWriteAsync },
};

static const HleAddrEntry kAddrHandlers[] = {
    { 0x80254718u, dol_hle_noop,                     "__OSInitAudioSystem" },
    { 0x8023B610u, dol_hle_noop,                     "__AI_SRC_INIT" },
    { 0x80282B98u, dol_hle_salInitDsp,                "salInitDsp" },
    { 0x80281BCCu, dol_hle_aramUploadData,            "aramUploadData" },
    { 0x8023D638u, dol_hle_ARQPostRequest,            "ARQPostRequest" },
    { 0x802442C4u, dol_hle_return_zero,                "DSPCheckMailToDSP" },
    { 0x8024608Cu, dol_hle_DVDInit,                  "DVDInit" },
    { 0x80245C0Cu, dol_hle_DVDConvertPathToEntrynum, "DVDConvertPathToEntrynum" },
    { 0x80245F00u, dol_hle_DVDFastOpen,              "DVDFastOpen" },
    { 0x80245F74u, dol_hle_DVDClose,                 "DVDClose" },
    { 0x80245F98u, dol_hle_DVDReadAsyncPrio,         "DVDReadAsyncPrio" },
    { 0x80248118u, dol_hle_DVDGetCommandBlockStatus, "DVDGetCommandBlockStatus" },
    { 0x80248164u, dol_hle_DVDGetDriveStatus,        "DVDGetDriveStatus" },
    { 0x802429FCu, dol_hle_CARDFormatAsync,           "CARDFormatAsync" },
    { 0x80257CC0u, dol_hle_OSGetResetButtonState,    "OSGetResetButtonState" },
    { 0x80254C54u, dol_hle_LCStoreBlocks,             "LCStoreBlocks" },
    { 0x80254C78u, dol_hle_LCStoreData,               "LCStoreData" },
    { 0x80254D24u, dol_hle_noop,                      "LCQueueWait" },
#ifdef STRIKERSRECOMP_AURORA
    { 0x80252680u, dol_hle_PSMTXConcat,                "PSMTXConcat" },
    { 0x8024D240u, dol_hle_GXSetArray,                "GXSetArray" },
    { 0x8024DD20u, strikers_hle_GXBegin,               "GXBegin" },
    { 0x80251510u, dol_hle_GXCallDisplayList,          "GXCallDisplayList" },
#endif
    { 0x8025AC10u, dol_hle_PADReset,                  "PADReset" },
    { 0x8025AD20u, dol_hle_PADRecalibrate,            "PADRecalibrate" },
    { 0x8025AE34u, dol_hle_PADInit,                   "PADInit" },
    { 0x8025AF84u, hle_PADRead,                       "PADRead" },
    { 0x8025B284u, dol_hle_PADControlMotor,           "PADControlMotor" },
    { 0x8025B33Cu, dol_hle_PADSetSpec,                "PADSetSpec" },

};

static const HleAddrEntry kNotify[] = {
    { 0x80259990u, notify_OSSleepThread,  "OSSleepThread" },
    { 0x802442FCu, notify_DSPSendMailToDSP, "DSPSendMailToDSP" },
    { 0x80268A08u, notify_audio_api,       "sndFXStartParaInfo" },
    { 0x8026C518u, notify_audio_api,       "sndStreamActivate" },
    { 0x80277274u, notify_audio_api,       "sndPushGroup" },
    { 0x80277BA4u, notify_audio_api,       "sndSeqPlayEx" },
    { 0x80257994u, notify_OSResetSystem,    "OSResetSystem" },
    { 0x801D2908u, notify_SetNextState,     "nlTaskManager::SetNextState" },
    { 0x801D2B28u, notify_TaskManagerStartup, "nlTaskManager::Startup" },
    { 0x800A9A5Cu, notify_SHMainMenuUpdate, "SHMainMenu::Update" },
    { 0x800C3C64u, notify_IChooseSideCheckControllers, "IChooseSide::CheckControllers" },
    { 0x800C36E8u, notify_IChooseSidePositionController, "IChooseSide::PositionController" },
    { 0x801CB7F8u, notify_MoviePlay,        "MoviePlay" },
    { 0x801CB8E0u, notify_MovieStop,        "MovieStop" },
    { 0x801CBA48u, notify_MovieStart,       "MovieStart" },
    { 0x801CC5E8u, notify_THPSimpleDecode,  "THPSimpleDecode" },
    { 0x801CB868u, notify_THPSimpleDecodeReturn, "THPSimpleDecode return" },
    { 0x801CC6C4u, notify_THPVideoDecodeReturn, "THPVideoDecode return" },
    { 0x801CC7F0u, notify_THPVideoDecodeReturn, "THPVideoDecode return" },
    { 0x801CCB00u, notify_THPSimplePreLoad, "THPSimplePreLoad" },
    { 0x801CCDD0u, notify_THPSimpleSetBuffer, "THPSimpleSetBuffer" },
    { 0x801CD2C8u, notify_THPSimpleOpen,    "THPSimpleOpen" },
    { 0x802857ACu, notify_THPVideoDecode,   "THPVideoDecode" },
    { 0x80254BF4u, notify_LCEnable,          "LCEnable" },
    { 0x80254C2Cu, notify_LCDisable,         "LCDisable" },
    { 0x80255360u, notify_OSLoadContext,     "OSLoadContext" },
#ifdef STRIKERSRECOMP_AURORA
    { 0x8024E974u, notify_GXCopyDisp,      "GXCopyDisp" },
    { 0x8024EADCu, notify_GXCopyTex,       "GXCopyTex" },
    { 0x8024F89Cu, notify_GXLoadTexObj,    "GXLoadTexObj" },
    { 0x8024F928u, notify_GXLoadTlut,      "GXLoadTlut" },
    { 0x8025186Cu, notify_GXLoadPosMtxImm, "GXLoadPosMtxImm" },
    { 0x8025DF30u, notify_VIWaitForRetrace,"VIWaitForRetrace" },
    { 0x8025E3F8u, notify_VIConfigure,     "VIConfigure" },
#endif
};

// ---------------------------------------------------------------------------
// Trace and Dispatch tables
// ---------------------------------------------------------------------------

typedef struct {
    u32         address;
    const char* name;
} HleTraceEntry;

static const HleTraceEntry kTrace[] = {
    { 0x8023BA70u, "ARInit" },
    { 0x8023BB40u, "ARGetBaseAddress" },
    { 0x8023BB48u, "ARGetSize" },
    { 0x8025DA80u, "VIInit" },
    { 0x8025DF30u, "VIWaitForRetrace" },
    { 0x8025E3F8u, "VIConfigure" },
    { 0x8025ED30u, "VISetNextFrameBuffer" },
    { 0x80255360u, "OSLoadContext" },
    { 0x80259370u, "__OSReschedule" },
    { 0x80259598u, "OSResumeThread" },
};

#define HLE_CODE_BASE 0x80003000u
#define HLE_CODE_LIMIT 0x8028D260u
#define HLE_DISPATCH_COUNT ((HLE_CODE_LIMIT - HLE_CODE_BASE) / 4u)

static HleDispatchEntry g_hle_dispatch[HLE_DISPATCH_COUNT];

static HleDispatchEntry* hle_dispatch_entry(u32 address) {
    if (address < HLE_CODE_BASE || address >= HLE_CODE_LIMIT || (address & 3u) != 0u)
        return NULL;
    return &g_hle_dispatch[(address - HLE_CODE_BASE) / 4u];
}

static const char* trace_name(u32 address) {
    for (size_t i = 0; i < sizeof kTrace / sizeof kTrace[0]; i++)
        if (kTrace[i].address == address)
            return kTrace[i].name;
    return NULL;
}

static bool hle_dispatch(CPUState* cpu, u32 address) {
    if (dol_hle_handle_callback_return(cpu, address))
        return true;

    if (dol_hle_handle_gx_return(cpu, address))
        return true;

    // NULL pointer calls check
    if (address < HLE_CODE_BASE) {
        static unsigned long null_calls = 0;
        if (cpu->lr >= HLE_CODE_BASE) {
            if (g_hle_log || null_calls < 8)
                fprintf(stderr,
                        "[hle] null-pointer call to 0x%08X from lr=0x%08X "
                        "(treating as no-op callback, #%lu)\n",
                        address, cpu->lr, ++null_calls);
            else
                ++null_calls;
            hle_return(cpu);
            return true;
        }
        return false;
    }

    HleDispatchEntry* entry = hle_dispatch_entry(address);
    if (entry == NULL)
        return false;

    if (entry->intercept != NULL) {
        if (g_hle_log) {
            const char* name = sdk_symbol_name(address);
            if (name == NULL) {
                for (size_t i = 0; i < sizeof kAddrHandlers / sizeof kAddrHandlers[0]; i++)
                    if (kAddrHandlers[i].address == address) {
                        name = kAddrHandlers[i].name;
                        break;
                    }
            }
            fprintf(stderr, "[hle] %-28s 0x%08X -> host\n",
                    name != NULL ? name : "(unnamed)", address);
        }
        entry->intercept(cpu);
        hle_return(cpu);
        return true;
    }

    if (entry->notify != NULL)
        entry->notify(cpu);

    if (g_hle_log) {
        const char* tn = trace_name(address);
        if (tn != NULL)
            fprintf(stderr, "[trace] %-22s lr=0x%08X r3=0x%08X r4=0x%08X r5=0x%08X\n",
                    tn, cpu->lr, cpu->gpr[3], cpu->gpr[4], cpu->gpr[5]);
        const char* name = sdk_symbol_name(address);
        if (name != NULL)
            fprintf(stderr, "[hle] %-28s 0x%08X (recompiled)\n", name, address);
    }

    return false;
}

static const HleAddrEntry kPhysicsNotify[] = {
    { STRIKERS_CBALL_UPDATE_ORIENTATION, notify_cBallUpdateOrientation, "cBall::UpdateOrientation" },
    { STRIKERS_CBALL_POST_PHYSICS_UPDATE, notify_cBallPostPhysicsUpdate, "cBall::PostPhysicsUpdate" },
    { STRIKERS_PHYSICS_UPDATE,             notify_PhysicsUpdate,       "PhysicsUpdate" },
    { STRIKERS_PHYSICS_AI_BALL_POST_UPDATE, notify_PhysicsAIBallPostUpdate, "PhysicsAIBall::PostUpdate" },
    { STRIKERS_PHYSICS_WORLD_UPDATE,       notify_PhysicsWorldUpdate,  "PhysicsWorld::Update" },
    { STRIKERS_PHYSICS_WORLD_PRE_UPDATE,   notify_PhysicsWorldPreUpdate, "PhysicsWorld::PreUpdate" },
    { STRIKERS_DWORLD_QUICK_STEP,          notify_dWorldQuickStep,   "dWorldQuickStep" },
    { STRIKERS_DBODY_SET_FORCE,            notify_dBodySetForce,     "dBodySetForce" },
    { STRIKERS_DBODY_ADD_FORCE,            notify_dBodyAddForce,     "dBodyAddForce" },
    { STRIKERS_DBODY_SET_ANGULAR_VEL,      notify_dBodySetAngularVel, "dBodySetAngularVel" },
    { STRIKERS_DBODY_SET_LINEAR_VEL,       notify_dBodySetLinearVel, "dBodySetLinearVel" },
    { STRIKERS_DBODY_SET_ROTATION,          notify_dBodySetRotation,  "dBodySetRotation" },
    { STRIKERS_DBODY_SET_POSITION,          notify_dBodySetPosition,  "dBodySetPosition" },
    { STRIKERS_SOR_LCP,                    notify_SorLcp,             "SOR_LCP" },
    { STRIKERS_SOR_LCP_RETURN,             notify_SorLcpReturn,       "SOR_LCP return" },
    { STRIKERS_DX_STEP_BODY,               notify_dxStepBody,        "dxStepBody" },
};

static void initialize_hle_dispatch(void) {
    memset(g_hle_dispatch, 0, sizeof g_hle_dispatch);

    for (size_t i = 0; i < sizeof kHandlers / sizeof kHandlers[0]; i++) {
        HleDispatchEntry* entry = hle_dispatch_entry(sdk_symbol_address(kHandlers[i].name));
        if (entry != NULL)
            entry->intercept = kHandlers[i].fn;
    }
    for (size_t i = 0; i < sizeof kAddrHandlers / sizeof kAddrHandlers[0]; i++) {
        HleDispatchEntry* entry = hle_dispatch_entry(kAddrHandlers[i].address);
        if (entry != NULL)
            entry->intercept = kAddrHandlers[i].fn;
    }
    for (size_t i = 0; i < sizeof kNotify / sizeof kNotify[0]; i++) {
        HleDispatchEntry* entry = hle_dispatch_entry(kNotify[i].address);
        if (entry != NULL)
            entry->notify = kNotify[i].fn;
    }
    if (ball_state_log_enabled()) {
        for (size_t i = 0; i < sizeof kPhysicsNotify / sizeof kPhysicsNotify[0]; ++i) {
            HleDispatchEntry* entry = hle_dispatch_entry(kPhysicsNotify[i].address);
            if (entry != NULL)
                entry->notify = kPhysicsNotify[i].fn;
        }
    }
}

// ---------------------------------------------------------------------------
// Standard API forwarders
// ---------------------------------------------------------------------------

bool hle_card_open(const char* path) {
    return dol_hle_card_open(path);
}

void hle_card_close(void) {
    dol_hle_card_close();
}

bool hle_poll_callback(CPUState* cpu) {
    return dol_hle_poll_callback(cpu);
}

void hle_install(CPUState* cpu) {
    // 1. Configure the generic HLE config
    DolHleConfig config;
    memset(&config, 0, sizeof config);
    config.code_base = HLE_CODE_BASE;
    config.code_limit = HLE_CODE_LIMIT;
    config.dispatch_interrupt_addr = STRIKERS_DISPATCH_INTERRUPT_ADDR;
    config.musyx_dsp_done_addr = STRIKERS_MUSYX_DSP_DONE_ADDR;
    config.thp_simple_control_addr = STRIKERS_THP_SIMPLE_CONTROL;
    config.gx_dirty_state_helper_addr = STRIKERS_GX_DIRTY_STATE_HELPER_ADDR;
    config.gx_flush_prim_helper_addr = STRIKERS_GX_FLUSH_PRIM_HELPER_ADDR;
    memcpy(config.game_code, "G4QE", 4);
    memcpy(config.company, "01", 2);
    dol_hle_init(&config);

    // 2. Local logs and scripting settings
    g_movie_log = getenv("STRIKERS_MOVIE_LOG") != NULL;
    g_movie_cadence_log = getenv("STRIKERS_MOVIE_CADENCE_LOG") != NULL;
    g_auto_skip_card_prompt = getenv("STRIKERS_AUTO_SKIP_CARD_PROMPT") != NULL;
    g_state_log = getenv("STRIKERS_STATE_LOG") != NULL;
    g_auto_input = getenv("STRIKERS_AUTO_INPUT") != NULL;
    g_mash_to_gameplay = getenv("STRIKERS_MASH_TO_GAMEPLAY") != NULL;
    g_mash_side_assigned = false;
    g_mash_prematch = false;
    g_mash_route_complete = false;
    hle_physics_init();

    if (g_mash_to_gameplay) {
        fprintf(stderr, "[input] mashing A + Left + Start (8 frames held, 8 released)\n");
    }

    g_auto_input_last_pulse = ~(u64)0;
    g_auto_skip_card_last_pulse = ~(u64)0;
    g_auto_input_once_sent = ~(u64)0;
    g_auto_input_once_frame = 0;

    g_movie_cadence_present_count = 0;
    g_movie_cadence_texframe_changes = 0;
    g_movie_cadence_start_time = 0.0;
    g_movie_cadence_last_texframe = -1;
    g_movie_cadence_started = false;

    initialize_hle_dispatch();

    const char* once_frame = getenv("STRIKERS_AUTO_INPUT_ONCE");
    if (once_frame != NULL && once_frame[0] != '\0')
        g_auto_input_once_frame = strtoull(once_frame, NULL, 0);

    parse_input_script(getenv("STRIKERS_INPUT_SCRIPT"));

#ifdef STRIKERSRECOMP_AURORA
    g_gx_begin_count = 0;
#endif

    cpu->host_call = hle_dispatch;
}
