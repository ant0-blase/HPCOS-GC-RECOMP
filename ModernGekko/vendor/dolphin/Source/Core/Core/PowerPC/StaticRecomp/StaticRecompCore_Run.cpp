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

static bool HpcosWriteGuestFovFloatBE(u8* ram, std::size_t ram_size,
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

  // HPCOS_FOV is process configuration too, so parse it once instead of
  // revisiting the static-local guard in the hot outer loop.
  static const float hpcos_requested_hfov = [] {
    const char* env = std::getenv("HPCOS_FOV");

    if (!env || !*env)
      return 0.0f;

    char* end = nullptr;
    const float value = std::strtof(env, &end);

    if (end == env || *end != '\0' || value < 30.0f || value > 150.0f)
      return 0.0f;

    return value;
  }();

  while (*state_ptr == CPU::State::Running)
  {
    core_timing.Advance();

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

    if (hpcos_requested_hfov > 0.0f && guest_fov_supported)
    {
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
      static float hpcos_guest_vfov = 0.0f;

      if (std::fabs(guest_aspect - hpcos_cached_aspect) > 0.00001f)
      {
        const float half_h =
            hpcos_requested_hfov * pi / 360.0f;

        hpcos_guest_vfov =
            2.0f *
            std::atan(std::tan(half_h) / guest_aspect) *
            180.0f / pi;

        hpcos_cached_aspect = guest_aspect;

        // Diagnostic ONCE per aspect change, not every CPU quantum.
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
        HpcosWriteGuestFovFloatBE(
            m_guest.ram,
            m_guest.ram_size,
            FOV_ADDRESS,
            hpcos_guest_vfov);
      }
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

          /*
           * ABI v4 native burst:
           *
           * Keep lockstep and REL execution on the old one-segment path.
           * For the normal DOL gameplay path, execute multiple verified chunks
           * inside the native module before returning to the C++ chassis.
           */
          if (!do_ls &&
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
