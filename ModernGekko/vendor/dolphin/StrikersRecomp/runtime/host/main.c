// Recomp host entry point.
//
// Loads the recompiled GameCube DOL into guest RAM, sets up the GameCube boot
// environment, and drives the generated block dispatcher from the entry point.
//
// The generated header provides the CPU ABI (via core/cpu.h), every
// func_XXXXXXXX prototype, and the static-inline dispatcher helpers
// dolrecomp_call() / DOLRECOMP_ENTRY_POINT.
#include "generated.h"

#include "gxruntime/aurora_backend.h"
#include "gxruntime/boot.h"
#include "gxruntime/dvd.h"
#include "gxruntime/loader.h"
#include "gxruntime/platform.h"
#include "gxruntime/savestate.h"
#include "host/audio.h"
#include "host/mmio.h"
#include "host/hle.h"
#include "host/interrupt.h"
#include "host/hle_offsets.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_DOL_PATH   "generated/main.dol"
#define DEFAULT_CARD_PATH  "strikers-g4qe01-slot-a.dolcard"
#define DEFAULT_MAX_BLOCKS 50000000ull  // watchdog: HW-wait spins would loop forever
// --call mode: lr points here so the run loop detects the function's return
// (blr -> pc == sentinel). Aligned, well outside any real code range.
#define CALL_RETURN_SENTINEL 0x0BADF00Cu

// Deterministic save-state harness (see GXRuntime savestate.h). SIGUSR1 requests
// a snapshot at the next safe dispatch boundary, so an agent can `kill -USR1` the
// process at any interactive gameplay moment without a controller hotkey.
#include <signal.h>
static volatile sig_atomic_t g_snapshot_request = 0;
static void request_snapshot(int sig) {
    (void)sig;
    g_snapshot_request = 1;
}
// SIGUSR2 dumps the current guest pc + recent pc history -- used to pinpoint
// what a restored/hung run is spin-waiting on (map the pcs to symbols.txt).
static volatile sig_atomic_t g_pcdump_request = 0;
static void request_pcdump(int sig) {
    (void)sig;
    g_pcdump_request = 1;
}
// Capture MEM1 + registers. (ARAM/locked-cache can be added; MEM1 holds the
// gameplay simulation state this harness compares.)
static bool write_state_snapshot(const char* path, const CPUState* cpu) {
    DolSaveRegion regions[1] = {{"MEM1", cpu->ram, cpu->ram_size}};
    bool ok = dol_savestate_write(path, cpu, regions, 1u);
    fprintf(stderr, "[state] snapshot %s -> %s (pc=0x%08X)\n",
            ok ? "written" : "FAILED", path, cpu->pc);
    return ok;
}
static bool dump_mem1(const char* path, const CPUState* cpu) {
    FILE* f = fopen(path, "wb");
    if (f == NULL) {
        fprintf(stderr, "[state] dump-mem FAILED to open %s\n", path);
        return false;
    }
    bool ok = fwrite(cpu->ram, 1u, cpu->ram_size, f) == cpu->ram_size;
    if (fclose(f) != 0)
        ok = false;
    fprintf(stderr, "[state] MEM1 dump %s -> %s (%u bytes)\n",
            ok ? "written" : "FAILED", path, cpu->ram_size);
    return ok;
}

static void instruction_fallback(CPUState* ctx, u32 raw, u32 cia) {
    // DolRecomp defers environment instructions (cache maintenance,
    // unmodeled SPRs) to this hook. This host has no dcache/icache or DMA
    // model, so keep the pre-deferral semantics: cache ops and unmodeled
    // mtspr are no-ops, unmodeled mfspr reads zero. The hook owns pc.
    if ((raw >> 26) == 31u) {
        const u32 xo = (raw >> 1) & 0x3FFu;
        if (xo == 982u || xo == 86u || xo == 54u || xo == 470u ||  // icbi/dcbf/dcbst/dcbi
            xo == 467u) {                                          // mtspr (unmodeled)
            ctx->pc = cia + 4u;
            return;
        }
        if (xo == 339u) {  // mfspr (unmodeled): read zero
            ctx->gpr[(raw >> 21) & 31u] = 0;
            ctx->pc = cia + 4u;
            return;
        }
    }
    fprintf(stderr, "[fallback] unhandled instruction 0x%08X at 0x%08X\n", raw, cia);
    ctx->exception |= PPC_EXC_PROGRAM;
}

// Walk the PPC EABI backchain to reconstruct the guest call stack:
// [sp] -> caller frame, [caller+4] -> caller's saved return address.
static void dump_backchain(CPUState* cpu) {
    u32 sp = cpu->gpr[1];
    fprintf(stderr, "[run] guest backchain:\n");
    for (int f = 0; f < 16 && sp >= GC_RAM_BASE && sp < GC_RAM_BASE + cpu->ram_size; f++) {
        u32 caller = mem_read32(cpu, sp);
        if (caller <= sp || caller < GC_RAM_BASE) break;
        u32 ret = mem_read32(cpu, caller + 4u);
        fprintf(stderr, "    #%-2d sp=0x%08X ret=0x%08X\n", f, sp, ret);
        sp = caller;
    }
}

static const char* exception_name(u32 exc) {
    if (exc & PPC_EXC_PROGRAM)       return "PROGRAM";
    if (exc & PPC_EXC_DSI)           return "DSI";
    if (exc & PPC_EXC_ALIGNMENT)     return "ALIGNMENT";
    if (exc & PPC_EXC_SYSTEM_CALL)   return "SYSTEM_CALL";
    if (exc & PPC_EXC_MACHINE_CHECK) return "MACHINE_CHECK";
    return "none";
}

static float guest_float(CPUState* cpu, u32 address) {
    union {
        u32 bits;
        float value;
    } converted;
    converted.bits = mem_read32(cpu, address);
    return converted.value;
}

static void dump_game_state(CPUState* cpu) {
    const u32 task_manager = mem_read32(cpu, STRIKERS_TASK_MANAGER);
    const u32 transition = mem_read32(cpu, STRIKERS_TRANSITION);
    const u32 loading_global = mem_read32(cpu, STRIKERS_LOADING_GLOBAL);
    const u32 loading = transition ? mem_read32(cpu, transition + 0x28u)
                                   : loading_global;
    const u32 game_scene_manager = mem_read32(cpu, STRIKERS_GAME_SCENE_MANAGER);
    const u32 fe_resource_manager = mem_read32(cpu, STRIKERS_FE_RESOURCE_MANAGER);
    const u32 fe_scene_manager = mem_read32(cpu, STRIKERS_FE_SCENE_MANAGER);
    const u32 fe_input = mem_read32(cpu, STRIKERS_FE_INPUT);
    const u32 view = mem_read32(cpu, STRIKERS_VIEW_BASE + 31u * 4u);
    const u32 pending_resource = mem_read32(cpu, STRIKERS_PENDING_RESOURCE);
    const u32 current_resource = mem_read32(cpu, STRIKERS_CURRENT_RESOURCE);
    const u32 resource_context = mem_read32(cpu, STRIKERS_RESOURCE_CONTEXT);
    const u32 pad_current = mem_read32(cpu, STRIKERS_PAD_CURRENT);
    const u32 pad_next = mem_read32(cpu, STRIKERS_PAD_NEXT);
    const u32 pad_internal = mem_read32(cpu, STRIKERS_PAD_INTERNAL);

    fprintf(stderr,
            "[game] task-manager=0x%08X transition=0x%08X loading=0x%08X "
            "(global=0x%08X)\n",
            task_manager, transition, loading, loading_global);
    if (task_manager) {
        fprintf(stderr,
                "[game] state current=0x%08X pending=0x%08X previous=0x%08X "
                "locked=%u dt=%g dilation=%g task-head=0x%08X\n",
                mem_read32(cpu, task_manager + 8u),
                mem_read32(cpu, task_manager + 0x0Cu),
                mem_read32(cpu, task_manager + 0x10u),
                mem_read8(cpu, task_manager + 0x18u),
                guest_float(cpu, task_manager + 0x14u),
                guest_float(cpu, task_manager),
                mem_read32(cpu, task_manager + 4u));
    }
    if (transition) {
        fprintf(stderr,
                "[game] transition phase=%u ai-handler=0x%08X "
                "goalie-handler=0x%08X\n",
                mem_read32(cpu, transition + 0x2Cu),
                mem_read32(cpu, transition + 0x20u),
                mem_read32(cpu, transition + 0x24u));
    }
    if (loading) {
        const u32 max_entries = mem_read32(cpu, loading + 0x18u);
        const u32 current = mem_read32(cpu, loading + 0x1Cu);
        const u32 count = mem_read32(cpu, loading + 0x20u);
        const u32 queue = mem_read32(cpu, loading + 0x24u);
        fprintf(stderr,
                "[game] loader max=%u current=%u queued=%u queue=0x%08X "
                "finished=%u",
                max_entries, current, count, queue,
                mem_read8(cpu, loading + 0x28u));
        if (queue && max_entries && current < max_entries)
            fprintf(stderr, " active=0x%08X",
                    mem_read32(cpu, queue + current * 4u));
        fputc('\n', stderr);
    }

    fprintf(stderr,
            "[game] FE resource=0x%08X scenes=0x%08X input=0x%08X "
            "game-scenes=0x%08X\n",
            fe_resource_manager, fe_scene_manager, fe_input, game_scene_manager);
    if (game_scene_manager) {
        u32 depth = mem_read32(cpu, game_scene_manager + 4u);
        fprintf(stderr, "[game] scene-stack depth=%u", depth);
        if (depth > 32u)
            depth = 32u;
        for (u32 i = 0; i < depth; i++)
            fprintf(stderr, " %u", mem_read32(cpu, game_scene_manager + 8u + i * 4u));
        fputc('\n', stderr);
        if (depth) {
            const u32 handler =
                mem_read32(cpu, game_scene_manager + 0x88u + (depth - 1u) * 4u);
            const u32 scene = handler ? mem_read32(cpu, handler + 0x18u) : 0u;
            fprintf(stderr,
                    "[game] scene-handler=0x%08X visible=%u scene=0x%08X",
                    handler, handler ? mem_read8(cpu, handler + 8u) : 0u, scene);
            if (scene) {
                fprintf(stderr,
                        " valid=%u package=0x%08X hash=0x%08X render-view=%u "
                        "resource-valid=%u elapsed=%g prompt=%u",
                        mem_read8(cpu, scene + 8u), mem_read32(cpu, scene),
                        mem_read32(cpu, scene + 4u),
                        mem_read32(cpu, scene + 0x4Cu),
                        mem_read8(cpu, scene + 0x60u),
                        guest_float(cpu, handler + 0x24u),
                        mem_read8(cpu, handler + 0x28u));
            }
            fputc('\n', stderr);
        }
    }
    if (fe_scene_manager) {
        const u32 fe_head = mem_read32(cpu, fe_scene_manager + 0x18u);
        // m_pushPopMessageQueue is a file-static nlDLListSlotPool @0x80343648;
        // its m_Head is at +0x18. AreAllScenesValid() returns false while this
        // is non-null (pending scene push/pop), or if any handler's scene is
        // not yet m_bValid.
        const u32 pushpop_head = mem_read32(cpu, STRIKERS_PUSHPOP_HEAD);
        fprintf(stderr,
                "[game] FE top=0x%08X default-view=%u handler-ring=0x%08X "
                "pushpop-queue=0x%08X\n",
                mem_read32(cpu, fe_scene_manager + 0x1Cu),
                mem_read32(cpu, fe_scene_manager + 0x20u),
                fe_head, pushpop_head);
        // Walk the circular scene-handler ring (m_data@+8, m_next@+0): for each
        // handler, m_pFEScene@+0x18, FEScene.m_bValid@+8. This is what wedges
        // the `while(!AreAllScenesValid())` loop in TransitionTask.
        if (fe_head) {
            u32 entry = mem_read32(cpu, fe_head);  // GetStart = head->m_next
            for (int i = 0; i < 16 && entry; i++) {
                const u32 handler = mem_read32(cpu, entry + 8u);
                const u32 scene = handler ? mem_read32(cpu, handler + 0x18u) : 0u;
                fprintf(stderr,
                        "[game]   fe-scene[%d] entry=0x%08X handler=0x%08X "
                        "hash=0x%08X scene=0x%08X valid=%d\n",
                        i, entry, handler,
                        handler ? mem_read32(cpu, handler + 4u) : 0u, scene,
                        scene ? (int)mem_read8(cpu, scene + 8u) : -1);
                if (entry == fe_head)
                    break;
                entry = mem_read32(cpu, entry);  // m_next
            }
        }
    }
    fprintf(stderr,
            "[game] resources pending=0x%08X current=0x%08X context=0x%08X "
            "timebase=%llu bus-clock=%u uptime=%g\n",
            pending_resource, current_resource, resource_context,
            (unsigned long long)cpu->timebase,
            mem_read32(cpu, STRIKERS_BUS_CLOCK),
            guest_float(cpu, STRIKERS_UPTIME));
    fprintf(stderr,
            "[game] reset mode=%u state=%u audio-init=%u pressed=%u paused=%u "
            "check-card=%u hold=%u,%u,%u,%u\n",
            mem_read32(cpu, STRIKERS_RESET_MODE), mem_read32(cpu, STRIKERS_RESET_STATE),
            mem_read8(cpu, STRIKERS_AUDIO_INIT), mem_read8(cpu, STRIKERS_RESET_PRESSED),
            mem_read8(cpu, STRIKERS_GAME_PAUSED), mem_read8(cpu, STRIKERS_CHECK_CARD),
            mem_read32(cpu, STRIKERS_RESET_HOLD_BASE), mem_read32(cpu, STRIKERS_RESET_HOLD_BASE + 4u),
            mem_read32(cpu, STRIKERS_RESET_HOLD_BASE + 8u), mem_read32(cpu, STRIKERS_RESET_HOLD_BASE + 12u));
    fprintf(stderr,
            "[game] pads current=0x%08X next=0x%08X internal=0x%08X",
            pad_current, pad_next, pad_internal);
    for (u32 i = 0; i < 4u; i++) {
        const u32 pad = pad_current + i * 12u;
        fprintf(stderr, " p%u=%04X/err%d", i,
                pad_current ? mem_read16(cpu, pad) : 0u,
                pad_current ? (s8)mem_read8(cpu, pad + 10u) : 0);
    }
    fputc('\n', stderr);
    if (current_resource) {
        fprintf(stderr,
                "[game] current-resource type=%u hash=0x%08X valid=%u\n",
                mem_read32(cpu, current_resource + 8u),
                mem_read32(cpu, current_resource + 0x0Cu),
                mem_read8(cpu, current_resource + 0x10u));
    }
    fprintf(stderr, "[game] view31 enabled=%u object=0x%08X\n",
            mem_read8(cpu, STRIKERS_VIEW_ENABLED_BASE + 31u), view);
    if (view) {
        fprintf(stderr,
                "[game] view31 sort=%u size=%ux%u target=%u "
                "view-matrix=0x%08X projection=0x%08X render-list=0x%08X "
                "depth-clear=%u\n",
                mem_read32(cpu, view), mem_read32(cpu, view + 0x0Cu),
                mem_read32(cpu, view + 0x10u), mem_read32(cpu, view + 0x1Cu),
                mem_read32(cpu, view + 0x14u), mem_read32(cpu, view + 0x18u),
                mem_read32(cpu, view + 0xF0u), mem_read8(cpu, view + 0xEDu));
    }
}


int main(int argc, char** argv) {
    // Keep stdout/stderr unbuffered so diagnostics are not lost when a worker
    // thread calls abort() (e.g. an Aurora FATAL) before buffered output is
    // flushed.
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    const char* dol_path = DEFAULT_DOL_PATH;
    const char* iso_path = NULL;
    const char* card_path = NULL;
    bool card_enabled = true;
    unsigned long long max_blocks = DEFAULT_MAX_BLOCKS;
    unsigned long long trace_every = 0;
    const char* snapshot_out = NULL;   // SIGUSR1 / --snapshot-at-block target
    const char* restore_path = NULL;   // load a snapshot at boot and resume
    const char* dump_mem_path = NULL;  // raw MEM1 at exit (Dolphin differential)
    unsigned long long snapshot_at_block = 0;  // 0 = signal-only (interactive)
    // Single-function differential: load a raw MEM1 (Dolphin MRAM), set arg
    // registers, call one guest function, run to return, dump MEM1. Rigorous and
    // resume-free -- compares one function's output against Dolphin's.
    const char* restore_mem_path = NULL;  // raw 24 MB MEM1 to load
    unsigned long long call_addr = 0;     // function entry to call (0 = normal)
    u32 set_reg_idx[32];
    u32 set_reg_val[32];
    unsigned set_reg_count = 0;
    u32 set_fpr_idx[32];
    u64 set_fpr_bits[32];
    unsigned set_fpr_count = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--max-blocks") == 0 && i + 1 < argc) {
            max_blocks = strtoull(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--trace-every") == 0 && i + 1 < argc) {
            trace_every = strtoull(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--iso") == 0 && i + 1 < argc) {
            iso_path = argv[++i];
        } else if (strcmp(argv[i], "--card") == 0 && i + 1 < argc) {
            card_path = argv[++i];
        } else if (strcmp(argv[i], "--no-card") == 0) {
            card_enabled = false;
        } else if (strcmp(argv[i], "--mmio-log") == 0) {
            mmio_set_logging(true);
        } else if (strcmp(argv[i], "--snapshot-out") == 0 && i + 1 < argc) {
            snapshot_out = argv[++i];
        } else if (strcmp(argv[i], "--snapshot-at-block") == 0 && i + 1 < argc) {
            snapshot_at_block = strtoull(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--restore") == 0 && i + 1 < argc) {
            restore_path = argv[++i];
        } else if (strcmp(argv[i], "--dump-mem") == 0 && i + 1 < argc) {
            dump_mem_path = argv[++i];
        } else if (strcmp(argv[i], "--restore-mem") == 0 && i + 1 < argc) {
            restore_mem_path = argv[++i];
        } else if (strcmp(argv[i], "--call") == 0 && i + 1 < argc) {
            call_addr = strtoull(argv[++i], NULL, 0);
        } else if (strcmp(argv[i], "--set-reg") == 0 && i + 1 < argc &&
                   set_reg_count < 32u) {
            // --set-reg N=0xVAL
            char* eq = strchr(argv[++i], '=');
            if (eq != NULL) {
                set_reg_idx[set_reg_count] = (u32)strtoul(argv[i], NULL, 0);
                set_reg_val[set_reg_count] = (u32)strtoul(eq + 1, NULL, 0);
                set_reg_count++;
            }
        } else if (strcmp(argv[i], "--set-fpr") == 0 && i + 1 < argc &&
                   set_fpr_count < 32u) {
            // --set-fpr N=0xRAWBITS (full f64 bits) or N=<float literal>
            char* eq = strchr(argv[++i], '=');
            if (eq != NULL) {
                set_fpr_idx[set_fpr_count] = (u32)strtoul(argv[i], NULL, 0);
                if (eq[1] == '0' && (eq[2] == 'x' || eq[2] == 'X')) {
                    set_fpr_bits[set_fpr_count] = strtoull(eq + 1, NULL, 16);
                } else {
                    double d = strtod(eq + 1, NULL);
                    memcpy(&set_fpr_bits[set_fpr_count], &d, sizeof(double));
                }
                set_fpr_count++;
            }
        } else if (argv[i][0] != '-') {
            dol_path = argv[i];
        } else {
            fprintf(stderr,
                    "usage: %s [dol-path] [--iso path] [--max-blocks N] "
                    "[--card path | --no-card] [--trace-every N] [--mmio-log]\n"
                    "  deterministic save-state harness:\n"
                    "    --snapshot-out PATH   write a snapshot on SIGUSR1\n"
                    "    --restore PATH        load a snapshot at boot and resume\n"
                    "    --dump-mem PATH       write raw MEM1 at exit (for diff)\n",
                    argv[0]);
            return 2;
        }
    }
    if (snapshot_out != NULL)
        signal(SIGUSR1, request_snapshot);
    signal(SIGUSR2, request_pcdump);  // always available for hang diagnosis

#ifdef STRIKERSRECOMP_AURORA
    const AuroraBackendConfig backend_config = {
        .app_name = "StrikersRecomp",
        .window_width = 1280,
        .window_height = 960,
        .vsync = true,
        .allow_texture_dumps = getenv("STRIKERS_TEXTURE_DUMP") != NULL,
        .info_logging = getenv("STRIKERS_AURORA_LOG") != NULL,
        .graphics_logging = getenv("STRIKERS_GFX_LOG") != NULL,
        .force_untextured =
            getenv("STRIKERS_GFX_FORCE_UNTEXTURED") != NULL,
    };
    // --call mode runs one pure-compute function with no rendering: skip Aurora
    // init so it runs headless (no window), agent-drivable and side-effect-free.
    const bool aurora_enabled = (call_addr == 0);
    if (aurora_enabled && !dol_aurora_initialize(argc, argv, &backend_config))
        return 1;
#endif

    CPUState cpu;
    if (!cpu_init(&cpu)) {
#ifdef STRIKERSRECOMP_AURORA
        dol_aurora_shutdown();
#endif
        return 1;
    }

    DolLayout layout;
    if (!dol_load_into_ram(&cpu, dol_path, &layout)) {
        cpu_free(&cpu);
#ifdef STRIKERSRECOMP_AURORA
        dol_aurora_shutdown();
#endif
        return 1;
    }

    if (layout.entry_point != DOLRECOMP_ENTRY_POINT) {
        fprintf(stderr,
                "warning: DOL entry 0x%08X != recompiled entry 0x%08X "
                "(DOL does not match the recompiled build)\n",
                layout.entry_point, (u32)DOLRECOMP_ENTRY_POINT);
    }

    boot_setup_os_globals(&cpu, &layout);
    if (!mmio_install(&cpu)) {
        cpu_free(&cpu);
#ifdef STRIKERSRECOMP_AURORA
        dol_aurora_shutdown();
#endif
        return 1;
    }
    if (card_enabled) {
        if (card_path == NULL)
            card_path = getenv("STRIKERS_CARD");
        if (card_path == NULL || card_path[0] == '\0')
            card_path = DEFAULT_CARD_PATH;
        if (!hle_card_open(card_path))
            fprintf(stderr,
                    "[card] slot A unavailable; continuing with no card\n");
    }
    hle_install(&cpu);
    if (iso_path == NULL)
        iso_path = getenv("STRIKERS_ISO");
    if (iso_path == NULL || iso_path[0] == '\0')
        iso_path = "../strikers.iso";
    dvd_open_image(iso_path);  // disc image backing the file system
    mmio_set_disc_present(dvd_image_ready());
    cpu.instruction_fallback = instruction_fallback;
    // This host restores FP context eagerly (host FPU cache + OSLoadContext
    // bridge in runtime/host/{interrupt,hle}.c), so keep the historical
    // execute-regardless FP semantics instead of lazy FP-unavailable traps.
    // Migrating to the generated lazy-FP path retires that bridge; see
    // KNOWLEDGE/recomp-codegen.md §Lazy FPU.
    ppc_lazy_fp_set_enabled(false);

    cpu.pc = layout.entry_point;

    // --call ambient SPR state. A bare single-function call skips the boot/OSInit
    // path that sets HID2, so HID2[PSE|LSQE] is clear and the FIRST paired-single
    // load/store (psq_l/psq_st -- pervasive in SDK vector/matrix/physics code)
    // raises a spurious PROGRAM(ILLEGAL) before block 0 (psq_check_enabled,
    // GXRuntime/src/core/cpu.c). These enables are architectural: any booted
    // Gekko running PS code has them set, so default them here. The GQR *contents*
    // (SDK fastcast quantization, e.g. gqr[5]/gqr[6]) are game policy, not
    // architectural -- pass --restore <gameplay savestate> below to recover the
    // real GQR/MSR context for a fully faithful differential. A --restore loads
    // its captured HID2 over this default (later, so it wins), which is correct.
    if (call_addr != 0) {
        cpu.hid2 |= PPC_HID2_PSE | PPC_HID2_LSQE | PPC_HID2_LCE;
        fprintf(stderr,
                "[call] ambient SPR default: hid2=0x%08X (PSE|LSQE|LCE); "
                "pass --restore <savestate> for real GQR/MSR fidelity\n",
                cpu.hid2);
    }

    // Deterministic restore: load a previously captured gameplay snapshot over
    // the freshly-booted state. The snapshot's registers (including pc) win, so
    // execution resumes exactly where it was captured -- no menu navigation, no
    // controller, identical state every run. Host function pointers (rebound by
    // cpu_init/hle_install above) are preserved by dol_savestate_read.
    if (restore_path != NULL) {
        DolSaveRegion regions[1] = {{"MEM1", cpu.ram, cpu.ram_size}};
        bool mismatch = false;
        if (!dol_savestate_read(restore_path, &cpu, regions, 1u, &mismatch)) {
            fprintf(stderr, "[state] restore FAILED from %s\n", restore_path);
            cpu_free(&cpu);
#ifdef STRIKERSRECOMP_AURORA
            dol_aurora_shutdown();
#endif
            return 1;
        }
        fprintf(stderr,
                "[state] restored from %s (pc=0x%08X)%s; resuming\n",
                restore_path, cpu.pc, mismatch ? " [size mismatch]" : "");
    }

    // Single-function differential setup. Load a raw MEM1 (Dolphin MRAM), apply
    // arg registers, and aim pc at the function with lr = a sentinel so the run
    // loop stops cleanly when the function returns (blr -> pc == sentinel).
    if (restore_mem_path != NULL) {
        FILE* mf = fopen(restore_mem_path, "rb");
        if (mf == NULL) {
            fprintf(stderr, "[call] FAILED to open MEM1 %s\n", restore_mem_path);
            cpu_free(&cpu);
#ifdef STRIKERSRECOMP_AURORA
            dol_aurora_shutdown();
#endif
            return 1;
        }
        size_t got = fread(cpu.ram, 1u, cpu.ram_size, mf);
        fclose(mf);
        fprintf(stderr, "[call] loaded MEM1 %s (%zu bytes)\n", restore_mem_path,
                got);
    }
    for (unsigned r = 0; r < set_reg_count; ++r) {
        if (set_reg_idx[r] < 32u) {
            cpu.gpr[set_reg_idx[r]] = set_reg_val[r];
            fprintf(stderr, "[call] r%u = 0x%08X\n", set_reg_idx[r],
                    set_reg_val[r]);
        }
    }
    for (unsigned r = 0; r < set_fpr_count; ++r) {
        if (set_fpr_idx[r] < 32u) {
            double d;
            memcpy(&d, &set_fpr_bits[r], sizeof(double));
            cpu.fpr[set_fpr_idx[r]] = d;
            cpu.ps1[set_fpr_idx[r]] = d;
            fprintf(stderr, "[call] f%u = %g (bits 0x%016llX)\n", set_fpr_idx[r],
                    d, (unsigned long long)set_fpr_bits[r]);
        }
    }
    if (call_addr != 0) {
        cpu.pc = (u32)call_addr;
        cpu.lr = CALL_RETURN_SENTINEL;
        fprintf(stderr, "[call] calling 0x%08X (lr sentinel 0x%08X)\n", cpu.pc,
                CALL_RETURN_SENTINEL);
    }

    printf("[run] starting execution at 0x%08X (max %llu blocks)\n",
           cpu.pc, max_blocks);

    unsigned long long blocks = 0;
    const char* stop_reason = "max-blocks watchdog";
    u32 last_pc = cpu.pc;
    enum { PC_HIST = 24 };
    u32 pc_hist[PC_HIST] = {0};
    unsigned pc_hist_i = 0;
    while (blocks < max_blocks) {
        // --call mode: the function returned (blr jumped to the lr sentinel).
        if (call_addr != 0 && cpu.pc == CALL_RETURN_SENTINEL) {
            stop_reason = "called function returned";
            break;
        }
#ifdef STRIKERSRECOMP_AURORA
        if (call_addr == 0 && dol_platform_should_quit()) {
            stop_reason = "window closed";
            break;
        }
#endif
        // In --call mode run the function in isolation: no interrupts/device
        // polling, so its output depends only on the loaded MEM1 + arg registers.
        if (call_addr != 0) {
            u32 cpc = cpu.pc;
            if (!dolrecomp_call(&cpu, cpc)) {
                stop_reason = "called function left recompiled code";
                fprintf(stderr, "[call] pc=0x%08X has no handler (lr=0x%08X)\n",
                        cpu.pc, cpu.lr);
                break;
            }
            if (cpu.exception != 0) {
                stop_reason = "cpu exception in called function";
                break;
            }
            blocks++;
            continue;
        }
        // Snapshot on request (SIGUSR1, interactive) or at a deterministic block
        // count (--snapshot-at-block, automated/agent). Taken at the top of a
        // dispatch iteration -- a block boundary -- where cpu.pc is a valid
        // resume point.
        if (snapshot_out != NULL &&
            (g_snapshot_request ||
             (snapshot_at_block != 0 && blocks == snapshot_at_block))) {
            g_snapshot_request = 0;
            write_state_snapshot(snapshot_out, &cpu);
        }
        if (g_pcdump_request) {
            g_pcdump_request = 0;
            fprintf(stderr, "[pcdump] pc=0x%08X lr=0x%08X r1=0x%08X msr=0x%08X "
                            "blocks=%llu\n  recent:",
                    cpu.pc, cpu.lr, cpu.gpr[1], cpu.msr, blocks);
            for (unsigned k = 0; k < PC_HIST; ++k)
                fprintf(stderr, " 0x%08X",
                        pc_hist[(pc_hist_i + k) % PC_HIST]);
            fprintf(stderr, "\n");
        }

        // Deliver a due VI-retrace interrupt before dispatching the next block,
        // so the redirected pc (the OS interrupt dispatcher) runs here.
        interrupt_poll(&cpu);
        hle_poll_callback(&cpu);

        u32 pc = cpu.pc;
        pc_hist[pc_hist_i++ % PC_HIST] = pc;
        if (!dolrecomp_call(&cpu, pc)) {
            stop_reason = "pc left recompiled code (no host handler)";
            fprintf(stderr, "[run] left recompiled code: pc=0x%08X reached from "
                            "block 0x%08X (lr=0x%08X)\n",
                    cpu.pc, last_pc, cpu.lr);
            fprintf(stderr, "[run] recent block entry PCs (oldest first):\n   ");
            for (unsigned k = 0; k < PC_HIST; k++)
                fprintf(stderr, " 0x%08X", pc_hist[(pc_hist_i + k) % PC_HIST]);
            fprintf(stderr, "\n");
            dump_backchain(&cpu);
            break;
        }
        last_pc = pc;
        if (cpu.exception) {
            // GameCube uses the `sc` instruction purely as a post-cache-op sync
            // barrier: DCFlushRange/DCStoreRange/etc. end with `dcbf...; sc; blr`,
            // and the SDK's default system-call vector simply syncs and returns.
            // There is no real cache to wait on here, so emulate that vector by
            // returning (rfi) to the instruction after `sc`.
            if (cpu.exception == PPC_EXC_SYSTEM_CALL) {
                cpu.exception = 0;
                ppc_rfi(&cpu, cpu.pc);
                continue;
            }
            stop_reason = "cpu exception";
            break;
        }
        blocks++;
        if (trace_every && (blocks % trace_every) == 0)
            fprintf(stderr, "[trace] block %llu pc=0x%08X lr=0x%08X r1=0x%08X\n",
                    blocks, cpu.pc, cpu.lr, cpu.gpr[1]);
    }

    if (getenv("STRIKERS_PC_HIST")) {
        fprintf(stderr, "[run] recent block entry PCs (oldest first):\n   ");
        for (unsigned k = 0; k < PC_HIST; k++)
            fprintf(stderr, " 0x%08X", pc_hist[(pc_hist_i + k) % PC_HIST]);
        fprintf(stderr, "\n");
    }
    if (getenv("STRIKERS_BACKCHAIN"))
        dump_backchain(&cpu);
    if (getenv("STRIKERS_DUMP_CTX")) {
        u32 a = (u32)strtoul(getenv("STRIKERS_DUMP_CTX"), NULL, 0);
        // OSContext: gpr1 @ +0x04, lr @ +0x84, srr0 @ +0x198 (where it resumes).
        fprintf(stderr, "[ctx] 0x%08X srr0=0x%08X lr=0x%08X r1=0x%08X r3=0x%08X\n",
                a, mem_read32(&cpu, a + 0x198u), mem_read32(&cpu, a + 0x84u),
                mem_read32(&cpu, a + 0x04u), mem_read32(&cpu, a + 0x0Cu));
        // Treat the address as an OSThread: state @+0x2C8, suspend @+0x2CC,
        // priority @+0x2D0, queue (the OSThreadQueue* it waits on) @+0x2DC.
        // state: 1=READY 2=RUNNING 4=WAITING 8=MORIBUND.
        fprintf(stderr,
                "[thread] 0x%08X state=%u suspend=%d priority=%u waiting-on-queue="
                "0x%08X (retraceQueue=0x80374814 FinishQueue=0x803746DC)\n",
                a, mem_read16(&cpu, a + 0x2C8u), (s32)mem_read32(&cpu, a + 0x2CCu),
                mem_read16(&cpu, a + 0x2D0u), mem_read32(&cpu, a + 0x2DCu));
    }
    if (getenv("STRIKERS_DUMP_ASYNC")) {
        u32 manager = mem_read32(&cpu, 0x803742A4u);
        u32 active = manager ? mem_read32(&cpu, manager + 0xA04u) : 0u;
        fprintf(stderr, "[async] manager=0x%08X active=0x%08X\n", manager, active);
        if (active) {
            u32 entry = mem_read32(&cpu, active);
            fprintf(stderr,
                    "[async] entry=0x%08X file=0x%08X callback=0x%08X "
                    "buffer=0x%08X size=%u position=%u phase=%u remaining=%u\n",
                    entry, mem_read32(&cpu, entry + 8u),
                    mem_read32(&cpu, entry + 0x0Cu),
                    mem_read32(&cpu, entry + 0x10u),
                    mem_read32(&cpu, entry + 0x14u),
                    mem_read32(&cpu, entry + 0x18u),
                    mem_read32(&cpu, entry + 0x20u),
                    mem_read32(&cpu, entry + 0x24u));
        }
    }
    if (getenv("STRIKERS_DUMP_GAME_STATE"))
        dump_game_state(&cpu);

    printf("[run] stopped: %s\n", stop_reason);
    printf("[run] blocks executed : %llu\n", blocks);
    printf("[run] final pc         : 0x%08X\n", cpu.pc);
    printf("[run] link register    : 0x%08X\n", cpu.lr);
    printf("[run] stack (r1)       : 0x%08X\n", cpu.gpr[1]);
    printf("[run] exception        : %s (0x%08X)\n",
           exception_name(cpu.exception), cpu.exception);

    // Raw MEM1 at exit for the recomp-vs-Dolphin differential. Guest big-endian
    // bytes, directly diffable against a Dolphin RAM dump.
    if (dump_mem_path != NULL)
        dump_mem1(dump_mem_path, &cpu);

    dvd_close_image();
    hle_card_close();
    audio_shutdown();
    mmio_shutdown();
#ifdef STRIKERSRECOMP_AURORA
    dol_aurora_shutdown();
#endif
    cpu_free(&cpu);
    return 0;
}
