// RecompCore: StaticRecomp CPU core - Main execution loop.
// SPDX-License-Identifier: GPL-2.0-or-later

#include <cmath>
#include "VideoCommon/Present.h"
#include "Core/PowerPC/StaticRecomp/StaticRecompCore.h"
#include "Core/PowerPC/StaticRecomp/StaticRecompFastmem.h"
#include "Core/System.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/PowerPC/Interpreter/Interpreter.h"
#include "Core/PowerPC/StaticRecomp/StaticRecompLockstep.h"
#include "Core/CoreTiming.h"
#include "Core/HW/CPU.h"
#include "Core/Config/MainSettings.h"
#include "Core/Config/ConfigManager.h"
#include "Core/HPCOSSettings.h"
#include "Core/HW/SystemTimers.h"

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string_view>

namespace
{
constexpr u32 SYNC_EXCEPTION_MASK = ~static_cast<u32>(
    EXCEPTION_EXTERNAL_INT | EXCEPTION_DECREMENTER | EXCEPTION_PERFORMANCE_MONITOR);






}


// HPCOS guest FOV helpers.
//
// GHSE69 MEM1 is big-endian. These helpers access a float directly by
// its original GameCube virtual address.
static bool HpcosReadGuestFloatBE(const u8* ram, std::size_t ram_size,
                                  u32 address, float* out)
{
  constexpr u32 MEM1_BASE = 0x80000000u;

  if (!ram || !out || address < MEM1_BASE)
    return false;

  const std::size_t off =
      static_cast<std::size_t>(address - MEM1_BASE);

  if (off + 4 > ram_size)
    return false;

  const u32 bits =
      (static_cast<u32>(ram[off + 0]) << 24) |
      (static_cast<u32>(ram[off + 1]) << 16) |
      (static_cast<u32>(ram[off + 2]) << 8) |
      (static_cast<u32>(ram[off + 3]));

  std::memcpy(out, &bits, sizeof(bits));
  return true;
}

static bool HpcosReadGuestU32BE(const u8* ram, std::size_t ram_size,
                                u32 address, u32* out)
{
  constexpr u32 MEM1_BASE = 0x80000000u;

  if (!ram || !out || address < MEM1_BASE)
    return false;

  const std::size_t off = static_cast<std::size_t>(address - MEM1_BASE);
  if (off + sizeof(u32) > ram_size)
    return false;

  *out = (static_cast<u32>(ram[off + 0]) << 24) |
         (static_cast<u32>(ram[off + 1]) << 16) |
         (static_cast<u32>(ram[off + 2]) << 8) |
         static_cast<u32>(ram[off + 3]);
  return true;
}

static bool HpcosWriteGuestFloatBE(u8* ram, std::size_t ram_size,
                                      u32 address, float value)
{
  constexpr u32 MEM1_BASE = 0x80000000u;

  if (!ram || address < MEM1_BASE)
    return false;

  const std::size_t off =
      static_cast<std::size_t>(address - MEM1_BASE);

  if (off + 4 > ram_size)
    return false;

  u32 bits;
  std::memcpy(&bits, &value, sizeof(bits));

  ram[off + 0] = static_cast<u8>(bits >> 24);
  ram[off + 1] = static_cast<u8>(bits >> 16);
  ram[off + 2] = static_cast<u8>(bits >> 8);
  ram[off + 3] = static_cast<u8>(bits);

  return true;
}

void StaticRecompCore::Run()
{
  auto& core_timing = m_system.GetCoreTiming();
  auto& power_pc = m_system.GetPowerPC();
  auto& ppc = power_pc.GetPPCState();
  auto& interpreter = m_system.GetInterpreter();
  auto& memory = m_system.GetMemory();
  const CPU::State* state_ptr = m_system.GetCPU().GetStatePtr();
  const bool hpcos_idle_trace = [] {
    const char* value = std::getenv("HPCOS_IDLE_TRACE");
    return value != nullptr && value[0] == '1' && value[1] == '\0';
  }();
  struct
  {
    u64 candidates = 0;
    u64 frontend_game = 0;
    u64 module_game = 0;
    u64 interrupts_enabled = 0;
    u64 no_exceptions = 0;
    u64 readable_poll = 0;
    u64 zero_poll = 0;
    u64 skipped = 0;
    u64 post_candidates = 0;
    u64 post_zero = 0;
    u64 post_nonzero = 0;
  } idle_trace;

  m_guest.ram = memory.GetRAM();
  m_guest.ram_size = memory.GetRamSizeReal();
  m_guest.exram = memory.GetEXRAM();
  m_guest.exram_size = memory.GetExRamSizeReal();
  m_l1_cache = memory.GetL1Cache();
  m_l1_cache_size = memory.GetL1CacheSize();
  InitLookupTable(m_guest.ram_size, m_guest.exram_size);

  // Fastmem views. Both stay NULL when the arena failed to reserve, which a
  // module built with GXRUNTIME_FASTMEM must treat as "unavailable" -- these
  // are the same 4 GiB windows Dolphin's own JIT indexes, so a module and the
  // JIT can share them. Only the bases are cached: BAT updates remap pages
  // inside the logical window without moving it.
  // The fallback Jit64 built in the constructor calls InitFastmemArena during
  // its own Init, so the arena normally exists by the time we attach. It can
  // still be absent (MAIN_FASTMEM_ARENA off, or the 16 GiB reservation failed),
  // and a module built with GXRUNTIME_FASTMEM would then dereference NULL on
  // its first guest access, so say so rather than fault.
  m_guest.fastmem_physical = memory.GetPhysicalBase();
  m_guest.fastmem_logical = memory.GetLogicalBase();
  StaticRecompFastmem::SetArenaBases(m_guest.fastmem_physical, m_guest.fastmem_logical);
  m_fastmem_available = m_guest.fastmem_physical != nullptr &&
                        m_guest.fastmem_logical != nullptr;
  if (!m_fastmem_available)
  {
    WARN_LOG_FMT(POWERPC, "StaticRecomp: no fastmem arena (physical {}, logical {}); "
                          "a module built with GXRUNTIME_FASTMEM cannot run.",
                 fmt::ptr(m_guest.fastmem_physical), fmt::ptr(m_guest.fastmem_logical));
  }

  const std::string initial_game_id = SConfig::GetInstance().GetGameID();
  m_module_active = m_module && (initial_game_id.empty() || initial_game_id == m_module->game_id);
  m_hpcos_pi_poll_fastpath = initial_game_id == "GHSE69";

  // Modules built with GXRUNTIME_GAMECUBE_MEM1_ONLY decode guest addresses
  // against a hard-coded 24 MiB MEM1 and ignore EXRAM entirely. That is the
  // GameCube retail layout, but MAIN_RAM_OVERRIDE_ENABLE or a Wii title would
  // break it into out-of-bounds host accesses, so say so loudly rather than
  // corrupt memory quietly. The module cannot be interrogated for its build
  // flags, so this reports the layout and leaves the decision visible.
  if (m_module_active &&
      (m_guest.ram == nullptr || m_guest.exram != nullptr || m_guest.ram_size != 0x01800000u))
  {
    ERROR_LOG_FMT(POWERPC,
                  "StaticRecomp: guest memory is not the GameCube retail layout "
                  "(RAM {}, MEM1 {} bytes, EXRAM {}). A module built with "
                  "GXRUNTIME_GAMECUBE_MEM1_ONLY will mis-decode addresses; "
                  "rebuild it with -DRECOMPCORE_MODULE_GAMECUBE_MEM1_ONLY=OFF.",
                  m_guest.ram ? "mapped" : "NULL", m_guest.ram_size,
                  m_guest.exram ? "present" : "absent");
    // The module's address decoder asserts a non-null RAM base, so running on
    // this layout would fault on the first guest access instead of taking the
    // external path. Refuse the module rather than hand it a broken mapping.
    if (m_guest.ram == nullptr)
      m_module_active = false;
  }


  if (!m_module_active && m_fallback_jit && !m_guest.host_call)
  {
    m_fallback_jit->Run();
    return;
  }

  // Run() owns one emulation session. SConfig::GetGameID() takes the config
  // mutex and used to be called once (and, for HPCOS FOV, twice) per outer
  // StaticRecomp loop iteration. The active title cannot change underneath
  // this Run(), so cache all game-id decisions once here.
  const bool guest_fov_supported = initial_game_id == "GHSE69";

  // HPCOS FOV is live-editable from the Ctrl+F10 PC settings overlay.

  // GHSE69 derives its main-loop time directly from the VI post-retrace
  // callback at 0x8000BF30.  Dolphin VI overclock intentionally raises the
  // *real* callback/retrace rate for extra rendered frames, but passing that
  // raw high-rate retrace number into the game also makes its fixed-step
  // simulation, animation and physics run too fast.  Maintain a second,
  // virtual ~59.94 Hz retrace clock for the game while leaving the SDK/VI
  // clock itself untouched for presentation and audio.
  constexpr double HPCOS_NATIVE_SIM_HZ = 59.94005994005994;
  constexpr u32 HPCOS_VI_CALLBACK_PC = 0x8000BF30u;
  constexpr u32 HPCOS_SIM_UPDATE_PC = 0x80038DACu;
  constexpr u32 HPCOS_GAME_RETRACE_ADDRESS = 0x8041EA60u;

  int hpcos_clock_target = -1;
  bool hpcos_virtual_retrace_ready = false;
  u32 hpcos_last_real_retrace = 0;
  u32 hpcos_virtual_retrace = 0;
  double hpcos_virtual_retrace_fraction = 0.0;
  bool hpcos_update_retrace_ready = false;
  u32 hpcos_last_update_retrace = 0;
  u64 hpcos_real_retrace_callbacks = 0;
  u64 hpcos_virtual_retrace_advances = 0;
  u64 hpcos_update_runs = 0;
  u64 hpcos_update_skips = 0;
  const bool hpcos_fps_trace = [] {
    const char* value = std::getenv("HPCOS_FPS_TRACE");
    return value != nullptr && value[0] == '1' && value[1] == '\0';
  }();

  while (*state_ptr == CPU::State::Running)
  {
    core_timing.Advance();

    // HPCOS experimental high-FPS path (phase 1).
    //
    // Never change global emulation speed for an FPS patch: doing that also
    // scales DSP/audio and every guest timer.  Dolphin's VI overclock changes
    // the VBlank/render cadence while CoreTiming, CPU clock and DSP/audio keep
    // their normal real-time clocks.  This is the same host-side mechanism
    // used by the MOH Frontline timing patch; GHSE69 simulation-specific delta
    // compensation can be layered on top without touching audio.
    {
      constexpr double NTSC_VPS = 59.94005994005994;
      const int game_fps_target = HPCOS::GameFpsTarget();
      static int last_game_fps_target = -1;

      if (game_fps_target != last_game_fps_target)
      {
        if (game_fps_target > 60)
        {
          const float vi_factor =
              static_cast<float>(static_cast<double>(game_fps_target) / NTSC_VPS);
          Config::SetCurrent(Config::MAIN_VI_OVERCLOCK, vi_factor);
          Config::SetCurrent(Config::MAIN_VI_OVERCLOCK_ENABLE, true);
          Config::SetCurrent(Config::MAIN_PRECISION_FRAME_TIMING, true);
          std::fprintf(stderr,
                       "[HPCOS-FPS] VI target=%d Hz factor=%.6f; CPU/DSP/audio clock unchanged\n",
                       game_fps_target, vi_factor);
        }
        else
        {
          Config::SetCurrent(Config::MAIN_VI_OVERCLOCK_ENABLE, false);
          Config::SetCurrent(Config::MAIN_VI_OVERCLOCK, 1.0f);
          std::fprintf(stderr, "[HPCOS-FPS] native 59.94 Hz VI/game timing restored\n");
        }

        // Any live target change starts a fresh virtual-clock epoch.  The
        // first callback seeds from the game's current real retrace number so
        // menus/gameplay never observe a backwards jump.
        hpcos_clock_target = game_fps_target;
        hpcos_virtual_retrace_ready = false;
        hpcos_update_retrace_ready = false;
        hpcos_virtual_retrace_fraction = 0.0;
        hpcos_real_retrace_callbacks = 0;
        hpcos_virtual_retrace_advances = 0;
        hpcos_update_runs = 0;
        hpcos_update_skips = 0;
        last_game_fps_target = game_fps_target;
      }
    }

    // HPCOS guest-side widescreen synchronization.
    //
    // The official GHSE69 widescreen patch changes three separate aspect
    // constants.  Only stretching the host XFB leaves the guest at 4:3, so
    // its visibility/culling code still removes objects near the new screen
    // edges.  Keep all three game-side values synchronized with the selected
    // PC aspect instead.
    //
    // These are GHSE69-only addresses and are deliberately gated by game id.
    if (guest_fov_supported)
    {
      constexpr float native_aspect = 4.0f / 3.0f;
      constexpr u32 ASPECT_GLOBALS[] = {0x8042788Cu, 0x80427A74u, 0x8049EC8Cu};

      static bool hpcos_aspect_was_active = false;
      const bool aspect_active = HPCOS::DynamicAspectEnabled();
      float target_aspect = native_aspect;

      if (aspect_active && g_presenter)
      {
        const float host_aspect = g_presenter->GetHpcosHostAspect();
        if (std::isfinite(host_aspect) && host_aspect >= 1.0f && host_aspect <= 5.0f)
          target_aspect = host_aspect;
      }

      if (aspect_active || hpcos_aspect_was_active)
      {
        for (const u32 address : ASPECT_GLOBALS)
        {
          float current = 0.0f;
          const bool have_current =
              HpcosReadGuestFloatBE(m_guest.ram, m_guest.ram_size, address, &current);
          if (!have_current || !std::isfinite(current) ||
              std::fabs(current - target_aspect) > 0.0001f)
          {
            HpcosWriteGuestFloatBE(m_guest.ram, m_guest.ram_size, address, target_aspect);
          }
        }

        static float hpcos_last_logged_aspect = -1.0f;
        if (std::fabs(target_aspect - hpcos_last_logged_aspect) > 0.0001f)
        {
          std::fprintf(stderr,
                       "[HPCOS-GUEST-ASPECT] aspect=%.6f globals=8042788C/80427A74/8049EC8C\n",
                       target_aspect);
          hpcos_last_logged_aspect = target_aspect;
        }
      }

      hpcos_aspect_was_active = aspect_active;
    }

    // HPCOS guest-side FOV/frustum synchronization.
    //
    // HPCOS_FOV is a requested HORIZONTAL FOV.
    // GHSE69's global at 0x8049EC88 is its game-side FOV used by
    // camera/frustum construction, while 0x8049EC8C is its aspect.
    //
    // Convert requested hFOV -> the vertical FOV appropriate for
    // whatever aspect the guest is currently using. This widens the
    // actual game visibility frustum without changing the public
    // meaning of --fov. These two addresses are GHSE69's own camera
    // globals, so guest_fov_supported gates the patch using the cached
    // title id above.

    const float hpcos_requested_hfov = HPCOS::Fov();
    static bool hpcos_fov_was_active = false;
    if (hpcos_requested_hfov > 0.0f && guest_fov_supported)
    {
      hpcos_fov_was_active = true;
      constexpr u32 FOV_ADDRESS = 0x8049EC88u;
      constexpr u32 ASPECT_ADDRESS = 0x8049EC8Cu;
      constexpr float pi = 3.14159265358979323846f;

      float guest_aspect = 4.0f / 3.0f;
      float memory_aspect = 0.0f;

      if (HpcosReadGuestFloatBE(
              m_guest.ram,
              m_guest.ram_size,
              ASPECT_ADDRESS,
              &memory_aspect) &&
          std::isfinite(memory_aspect) &&
          memory_aspect >= 1.0f &&
          memory_aspect <= 5.0f)
      {
        guest_aspect = memory_aspect;
      }

      // Recalculate trig only if the guest aspect actually changes.
      static float hpcos_cached_aspect = -1.0f;
      static float hpcos_cached_requested_hfov = -1.0f;
      static float hpcos_guest_vfov = 0.0f;

      if (std::fabs(guest_aspect - hpcos_cached_aspect) > 0.00001f ||
          std::fabs(hpcos_requested_hfov - hpcos_cached_requested_hfov) > 0.001f)
      {
        const float half_h =
            hpcos_requested_hfov * pi / 360.0f;

        hpcos_guest_vfov =
            2.0f *
            std::atan(std::tan(half_h) / guest_aspect) *
            180.0f / pi;

        hpcos_cached_aspect = guest_aspect;
        hpcos_cached_requested_hfov = hpcos_requested_hfov;

        // Diagnostic once per FOV/aspect change, not every CPU quantum.
        std::fprintf(
            stderr,
            "[HPCOS-GUEST-FOV] "
            "requested-h=%.3f guest-aspect=%.6f guest-v=%.3f\n",
            hpcos_requested_hfov,
            guest_aspect,
            hpcos_guest_vfov);
      }

      // The game can restore its own 55° value.
      // Only touch RAM when it actually differs from our target.
      float current_guest_fov = 0.0f;

      const bool have_current =
          HpcosReadGuestFloatBE(
              m_guest.ram,
              m_guest.ram_size,
              FOV_ADDRESS,
              &current_guest_fov);

      if (std::isfinite(hpcos_guest_vfov) &&
          hpcos_guest_vfov > 1.0f &&
          hpcos_guest_vfov < 179.0f &&
          (!have_current ||
           std::fabs(current_guest_fov - hpcos_guest_vfov) > 0.001f))
      {
        HpcosWriteGuestFloatBE(
            m_guest.ram,
            m_guest.ram_size,
            FOV_ADDRESS,
            hpcos_guest_vfov);
      }
    }
    else if (guest_fov_supported && hpcos_fov_was_active)
    {
      // If the live override was disabled, restore GHSE69's native camera
      // value immediately instead of waiting for a scene reload.
      constexpr u32 FOV_ADDRESS = 0x8049EC88u;
      constexpr float NATIVE_FOV = 55.0f;
      float current_guest_fov = 0.0f;
      if (HpcosReadGuestFloatBE(m_guest.ram, m_guest.ram_size, FOV_ADDRESS, &current_guest_fov) &&
          std::isfinite(current_guest_fov) &&
          std::fabs(current_guest_fov - NATIVE_FOV) > 0.001f)
      {
        HpcosWriteGuestFloatBE(m_guest.ram, m_guest.ram_size, FOV_ADDRESS, NATIVE_FOV);
      }
      hpcos_fov_was_active = false;
    }

    do
    {
      // MSR.FP needs no gate here: generated FPU instructions raise the
      // FP-unavailable exception themselves (ppc_fp_available).
      if (m_module_active && DispatchableAt(ppc.pc) &&
          !(m_guest.host_call && IsHostCallAddress(ppc.pc)))
      {
        SyncIn();

        // GHSE69's configured idle PC polls OS scheduler RunQueueBits until an
        // interrupt makes work runnable. CoreTiming::Advance has already run
        // due events and delivered any enabled external exception before this
        // point. When the poll is still zero, charge the remainder of the
        // slice as idle instead of spending host cycles executing the same
        // lwz/cmplwi/bc loop. A non-zero or unreadable poll always executes the
        // guest chunk so the scheduler's exit path remains observable.
        constexpr u32 HPCOS_IDLE_PC = 0x801789ACu;
        constexpr s32 HPCOS_RUN_QUEUE_BITS_R13_OFFSET = -26752;
        constexpr u32 MSR_EE = 0x00008000u;
        u32 run_queue_bits = 0;
        const u32 run_queue_address =
            m_guest.gpr[13] + static_cast<u32>(HPCOS_RUN_QUEUE_BITS_R13_OFFSET);
        const bool idle_candidate =
            m_idle_pc == HPCOS_IDLE_PC && m_guest.pc == HPCOS_IDLE_PC;
        const bool hpcos_module =
            m_module_active && m_module != nullptr &&
            std::string_view(m_module->game_id) == "GHSE69";
        const bool interrupts_enabled = (m_guest.msr & MSR_EE) != 0;
        const bool no_exceptions = ppc.Exceptions == 0;
        const bool readable_poll =
            idle_candidate &&
            HpcosReadGuestU32BE(m_guest.ram, m_guest.ram_size,
                                run_queue_address, &run_queue_bits);
        const bool zero_poll = readable_poll && run_queue_bits == 0;

        if (hpcos_idle_trace && idle_candidate)
        {
          ++idle_trace.candidates;
          idle_trace.frontend_game += initial_game_id == "GHSE69";
          idle_trace.module_game += hpcos_module;
          idle_trace.interrupts_enabled += interrupts_enabled;
          idle_trace.no_exceptions += no_exceptions;
          idle_trace.readable_poll += readable_poll;
          idle_trace.zero_poll += zero_poll;
        }

        if (hpcos_module && idle_candidate && interrupts_enabled &&
            no_exceptions && zero_poll)
        {
          if (hpcos_idle_trace)
            ++idle_trace.skipped;
          core_timing.Idle();
          SyncOut();
          continue;
        }

        ++m_bursts;
        do
        {
          const bool do_ls = m_lockstep_verifier->ShouldCheck(m_guest.pc);
          if (do_ls)
          {
            m_lockstep_verifier->Prepare(m_guest);
          }

          const u32 runtime_dispatch_address = m_guest.pc;
          u32 linked_dispatch_address = runtime_dispatch_address;

          // HPCOS DOL fast path: DOL runtime and linked addresses are identical.
          if (!m_active_rel_sections.empty())
            ResolveNativeAddress(runtime_dispatch_address, &linked_dispatch_address, nullptr);

          // GHSE69 high-FPS clock virtualization.
          //
          // 0x8000BF30 is the game's VI post-retrace callback. Its r3 argument
          // is the SDK's real retrace count. Keep the real SDK counter running
          // at the requested render rate, but replace only the argument visible
          // to the game with a monotonically increasing native-rate clock.
          // This fixes every GHSE69 subsystem that consumes the main-loop
          // retrace delta, rather than trying to scale individual forces.
          if (hpcos_module && linked_dispatch_address == HPCOS_VI_CALLBACK_PC &&
              hpcos_clock_target > 60)
          {
            const u32 real_retrace = m_guest.gpr[3];
            ++hpcos_real_retrace_callbacks;

            if (!hpcos_virtual_retrace_ready)
            {
              hpcos_virtual_retrace_ready = true;
              hpcos_last_real_retrace = real_retrace;
              hpcos_virtual_retrace = real_retrace;
              hpcos_virtual_retrace_fraction = 0.0;
              hpcos_update_retrace_ready = false;
            }
            else
            {
              // Unsigned subtraction deliberately handles the normal u32 wrap.
              const u32 real_delta = real_retrace - hpcos_last_real_retrace;
              hpcos_last_real_retrace = real_retrace;

              // A callback can occasionally be delayed by the guest and arrive
              // with delta > 1. Preserve elapsed real presentation time instead
              // of assuming exactly one callback. Clamp pathological jumps so
              // reset/state transitions cannot fast-forward gameplay.
              const u32 clamped_delta = std::min<u32>(real_delta, 16u);
              hpcos_virtual_retrace_fraction +=
                  static_cast<double>(clamped_delta) * HPCOS_NATIVE_SIM_HZ /
                  static_cast<double>(hpcos_clock_target);

              const u32 virtual_steps = static_cast<u32>(hpcos_virtual_retrace_fraction);
              if (virtual_steps != 0)
              {
                hpcos_virtual_retrace += virtual_steps;
                hpcos_virtual_retrace_fraction -= static_cast<double>(virtual_steps);
                hpcos_virtual_retrace_advances += virtual_steps;
              }
            }

            m_guest.gpr[3] = hpcos_virtual_retrace;

            if (hpcos_fps_trace && (hpcos_real_retrace_callbacks % 600u) == 0)
            {
              std::fprintf(stderr,
                           "[HPCOS-FPS-TRACE] realVI=%llu virtualTicks=%llu "
                           "updates=%llu skips=%llu target=%d\n",
                           static_cast<unsigned long long>(hpcos_real_retrace_callbacks),
                           static_cast<unsigned long long>(hpcos_virtual_retrace_advances),
                           static_cast<unsigned long long>(hpcos_update_runs),
                           static_cast<unsigned long long>(hpcos_update_skips),
                           hpcos_clock_target);
            }
          }
          else if (hpcos_module && linked_dispatch_address == HPCOS_VI_CALLBACK_PC)
          {
            // Native/original timing: expose the SDK count unchanged and make
            // the next high-FPS activation reseed cleanly.
            hpcos_virtual_retrace_ready = false;
            hpcos_update_retrace_ready = false;
          }

          // The retail loop may attempt phase-1 more than once while catching
          // up. At high render rates it may also enter the phase on an extra
          // presentation frame whose virtual retrace has not advanced. Run the
          // fixed-step phase exactly once per virtual retrace tick.
          bool hpcos_skip_sim_update = false;
          if (hpcos_module && linked_dispatch_address == HPCOS_SIM_UPDATE_PC &&
              hpcos_clock_target > 60)
          {
            u32 game_retrace = hpcos_virtual_retrace;
            (void)HpcosReadGuestU32BE(m_guest.ram, m_guest.ram_size,
                                      HPCOS_GAME_RETRACE_ADDRESS, &game_retrace);

            if (!hpcos_update_retrace_ready || game_retrace != hpcos_last_update_retrace)
            {
              hpcos_update_retrace_ready = true;
              hpcos_last_update_retrace = game_retrace;
              ++hpcos_update_runs;
            }
            else
            {
              hpcos_skip_sim_update = true;
              ++hpcos_update_skips;
            }
          }

          m_guest.pc = linked_dispatch_address;

          /*
           * One public native dispatch may execute an in-chunk cycle, but it
           * must not run past either the configured quantum or Dolphin's
           * current CoreTiming deadline. The second counter is a termination
           * backstop for cycles made entirely from zero-cycle helper/data
           * blocks. Both fields live in CPUState so helper/MMIO callbacks
           * cannot accidentally reset the budget.
           */
          const u64 remaining_slice =
              ppc.downcount > 0 ? static_cast<u64>(ppc.downcount) : 1u;
          m_guest.native_cycle_budget = static_cast<s64>(
              std::min<u64>(m_native_cycle_quantum, remaining_slice));
          m_guest.native_guard_budget = 4096;

          u32 dispatched_blocks = 0;

          if (hpcos_skip_sim_update)
          {
            // Behave like an immediate leaf return from 0x80038DAC. The caller
            // does not consume a return value; it only needs control back at LR.
            m_guest.pc = m_guest.lr & ~3u;
            m_guest.downcount = -1;
            dispatched_blocks = 1;
          }

          /*
           * ABI v4 native burst:
           *
           * Keep lockstep and REL execution on the old one-segment path.
           * For the normal DOL gameplay path, execute multiple verified chunks
           * inside the native module before returning to the C++ chassis.
           */
          if (dispatched_blocks == 0 && !do_ls &&
              m_module->dispatch_burst &&
              m_active_rel_sections.empty() &&
              !m_native_chain_state.empty())
          {
            /*
             * Never execute past Dolphin's current CoreTiming slice.
             *
             * The old dispatcher returned to this loop after every native
             * segment and stopped chaining as soon as ppc.downcount <= 0.
             * Give the module exactly that remaining budget so native chaining
             * cannot run through a pending CoreTiming event.
             */
            const u64 burst_cycle_budget =
                ppc.downcount > 0 ? static_cast<u64>(ppc.downcount) : 1u;

            dispatched_blocks = m_module->dispatch_burst(
                &m_guest,
                linked_dispatch_address,
                m_native_chain_state.data(),
                static_cast<u32>(m_native_chain_state.size()),
                burst_cycle_budget,
                m_burst_tb_base,
                m_burst_tb_cycles,
                static_cast<u32>(SystemTimers::TIMER_RATIO));
          }

          // Safety fallback for non-chainable/legacy paths.
          if (dispatched_blocks == 0)
          {
            m_module->dispatch(&m_guest, linked_dispatch_address);
            dispatched_blocks = 1;
          }

          if (!m_active_rel_sections.empty())
            m_guest.pc = TranslateRelAddress(m_guest.pc);

          m_native_dispatches += dispatched_blocks;

          if (do_ls)
          {
            m_lockstep_verifier->Verify(m_guest);
          }

          // Flush the module's per-block cycle charges into Dolphin's
          // downcount. A dispatch that charged nothing (PC-switch default,
          // pure embedded data) still costs 1 so the burst always makes
          // downcount progress; this per-dispatch flush is also the
          // dispatcher back-edge timing check — CoreTiming regains control
          // with at least CachedInterpreter's per-block frequency, so
          // external-interrupt latency matches stock.
          const s64 charge = -m_guest.downcount;
          m_guest.downcount = 0;
          ppc.downcount -= static_cast<int>(charge > 0 ? charge : 1);
          m_charged_cycles += static_cast<u64>(charge > 0 ? charge : 1);
          m_burst_tb_cycles += static_cast<u64>(charge > 0 ? charge : 1);
          m_guest.timebase = m_burst_tb_base + m_burst_tb_cycles / SystemTimers::TIMER_RATIO;

          // Idle loop skipping for configured target loops (e.g. Wii Menu OSIdleThread)
          if (m_guest.pc == m_idle_pc && m_idle_pc != 0)
          {
            bool should_idle = true;
            if (hpcos_module && m_guest.pc == HPCOS_IDLE_PC)
            {
              u32 post_run_queue_bits = 0;
              const u32 post_run_queue_address =
                  m_guest.gpr[13] + static_cast<u32>(HPCOS_RUN_QUEUE_BITS_R13_OFFSET);
              should_idle =
                  HpcosReadGuestU32BE(m_guest.ram, m_guest.ram_size,
                                      post_run_queue_address, &post_run_queue_bits) &&
                  post_run_queue_bits == 0;
              if (hpcos_idle_trace)
              {
                ++idle_trace.post_candidates;
                if (should_idle)
                  ++idle_trace.post_zero;
                else
                  ++idle_trace.post_nonzero;
              }
            }
            if (should_idle)
              m_system.GetCoreTiming().Idle();
          }

          // ctx->timebase is refreshed at burst start (SyncIn), and here we
          // incrementally advance it by the exact block cycle charges to
          // prevent guest busy-wait loops from spinning on a stale timebase.
          if (m_guest.exception)
          {
            // DolRecomp's runtime already redirected pc/msr/srr to the guest
            // exception vector; the flag only signals that it happened.
            m_guest.exception = 0;
            m_guest.program_exception = 0;
            ++m_native_exceptions;
          }
          if ((ppc.Exceptions & SYNC_EXCEPTION_MASK) != 0)
            break;  // Hook-raised synchronous exception: deliver via Dolphin below.
        } while (m_module_active && FastDispatchableAt(m_guest.pc) &&
                 !(m_guest.host_call && IsHostCallAddress(m_guest.pc)) && ppc.downcount > 0 &&
                 *state_ptr == CPU::State::Running);
        SyncOut();
        if ((ppc.Exceptions & SYNC_EXCEPTION_MASK) != 0)
          power_pc.CheckExceptions();
      }
      else
      {
        if (m_guest.host_call && IsHostCallAddress(ppc.pc))
        {
          SyncIn();
          bool handled = m_guest.host_call(&m_guest, m_guest.pc);
          if (!handled && m_guest.pc < m_guest.ram_size)
            handled = m_guest.host_call(&m_guest, m_guest.pc | 0x80000000u);
          if (m_fallback_jit && IsHostCallAddress(m_guest.lr))
            m_fallback_jit->GetBlockCache()->InvalidateICache(m_guest.lr, 4, true);
          if (handled)
          {
            const s64 charge = -m_guest.downcount;
            m_guest.downcount = 0;
            ppc.downcount -= static_cast<int>(charge > 0 ? charge : 1);
            m_burst_tb_cycles += static_cast<u64>(charge > 0 ? charge : 1);
            m_guest.timebase = m_burst_tb_base + m_burst_tb_cycles / SystemTimers::TIMER_RATIO;
            SyncOut();
            continue;
          }
          SyncOut();
          if (m_fallback_jit)
          {
            m_host_call_passthrough_pc = ppc.pc;
            m_host_call_passthrough = true;
          }
        }
        // SingleStepInner delivers synchronous exceptions itself; external
        // interrupts are delivered at slice start, as in Interpreter::Run.
        // A failed verification retires module code specifically to Dolphin's
        // interpreter. Do not let the ordinary fallback JIT hide SMC execution
        // from fallback telemetry. Non-module code retains the configured JIT
        // fallback policy.
        const bool smc_failed_module_pc = m_module_active && IsFailedModuleAddress(ppc.pc);
        if (m_module_active &&
            (smc_failed_module_pc || IsForcedFallbackAddress(ppc.pc)))
        {
          ppc.downcount -= interpreter.SingleStepInner();
          ++m_fallback_steps;
          if (smc_failed_module_pc)
            ++m_smc_interpreter_steps;
        }
        else if (m_fallback_jit)
        {
          m_fallback_jit->Run();
        }
        else
        {
          do
          {
            ppc.downcount -= interpreter.SingleStepInner();
            ++m_fallback_steps;
          } while (!(m_module_active && DispatchableAt(ppc.pc)) &&
                   !IsHostCallAddress(ppc.pc) && ppc.downcount > 0 &&
                   *state_ptr == CPU::State::Running);
        }
      }
    } while (ppc.downcount > 0 && *state_ptr == CPU::State::Running);
  }

  if (hpcos_idle_trace)
  {
    std::fprintf(stderr,
                 "[HPCOS-IDLE] candidates=%llu frontend_game=%llu "
                 "module_game=%llu ee=%llu no_exceptions=%llu readable=%llu "
                 "zero=%llu skipped=%llu post_candidates=%llu post_zero=%llu "
                 "post_nonzero=%llu\n",
                 static_cast<unsigned long long>(idle_trace.candidates),
                 static_cast<unsigned long long>(idle_trace.frontend_game),
                 static_cast<unsigned long long>(idle_trace.module_game),
                 static_cast<unsigned long long>(idle_trace.interrupts_enabled),
                 static_cast<unsigned long long>(idle_trace.no_exceptions),
                 static_cast<unsigned long long>(idle_trace.readable_poll),
                 static_cast<unsigned long long>(idle_trace.zero_poll),
                 static_cast<unsigned long long>(idle_trace.skipped),
                 static_cast<unsigned long long>(idle_trace.post_candidates),
                 static_cast<unsigned long long>(idle_trace.post_zero),
                 static_cast<unsigned long long>(idle_trace.post_nonzero));
  }
}

void StaticRecompCore::SingleStep()
{
  // Debugger stepping runs through the interpreter; state outside Run() lives
  // in PowerPCState, so no sync is needed.
  auto& system = m_system;
  system.GetCoreTiming().Advance();
  system.GetPPCState().downcount -= system.GetInterpreter().SingleStepInner();
}
