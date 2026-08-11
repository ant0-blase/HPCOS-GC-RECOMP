// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/PowerPC.h"

#include <algorithm>
#include <array>
#include <bit>
#include <cstring>

#include "Common/Assert.h"
#include "Common/ChunkFile.h"
#include "Common/CommonTypes.h"
#include "Common/FPURoundMode.h"
#include "Common/FloatUtils.h"
#include "Common/Logging/Log.h"

#include "Core/CPUThreadConfigCallback.h"
#include "Core/Config/MainSettings.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/HW/CPU.h"
#include "Core/HW/SystemTimers.h"
#include "Core/Host.h"
#include "Core/PowerPC/CPUCoreBase.h"
#include "Core/PowerPC/GDBStub.h"
#include "Core/PowerPC/Interpreter/Interpreter.h"
#include "Core/PowerPC/JitInterface.h"
#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/PPCSymbolDB.h"
#include "Core/System.h"

namespace PowerPC
{
double PairedSingle::PS0AsDouble() const
{
  return std::bit_cast<double>(ps0);
}

double PairedSingle::PS1AsDouble() const
{
  return std::bit_cast<double>(ps1);
}

void PairedSingle::SetPS0(double value)
{
  ps0 = std::bit_cast<u64>(value);
}

void PairedSingle::SetPS1(double value)
{
  ps1 = std::bit_cast<u64>(value);
}

static void InvalidateCacheThreadSafe(Core::System& system, u64 userdata, s64 cyclesLate)
{
  system.GetPPCState().iCache.Invalidate(system.GetMemory(), system.GetJitInterface(),
                                         static_cast<u32>(userdata));
  Host_JitCacheInvalidation();
}

PowerPCManager::PowerPCManager(Core::System& system)
    : m_breakpoints(system), m_memchecks(system), m_debug_interface(system, m_symbol_db),
      m_system(system)
{
}

PowerPCManager::~PowerPCManager() = default;

void PowerPCManager::DoState(PointerWrap& p)
{
  // some of this code has been disabled, because
  // it changes registers even in Mode::Measure (which is suspicious and seems like it could cause
  // desyncs)
  // and because the values it's changing have been added to CoreTiming::DoState, so it might
  // conflict to mess with them here.

  // m_ppc_state.spr[SPR_DEC] = SystemTimers::GetFakeDecrementer();
  // *((u64 *)&TL(m_ppc_state)) = SystemTimers::GetFakeTimeBase(); //works since we are little
  // endian and TL comes first :)

  const std::array<u32, 16> old_sr = m_ppc_state.sr;

  p.DoArray(m_ppc_state.gpr);
  p.Do(m_ppc_state.pc);
  p.Do(m_ppc_state.npc);
  p.DoArray(m_ppc_state.cr.fields);
  p.Do(m_ppc_state.msr);
  p.Do(m_ppc_state.fpscr);
  p.Do(m_ppc_state.Exceptions);
  p.Do(m_ppc_state.downcount);
  p.Do(m_ppc_state.xer_ca);
  p.Do(m_ppc_state.xer_so_ov);
  p.Do(m_ppc_state.xer_stringctrl);
  p.DoArray(m_ppc_state.ps);
  p.DoArray(m_ppc_state.sr);
  p.DoArray(m_ppc_state.spr);
  p.DoArray(m_ppc_state.tlb);
  p.Do(m_ppc_state.pagetable_base);
  p.Do(m_ppc_state.pagetable_mask);
  p.Do(m_ppc_state.pagetable_update_pending);

  p.Do(m_ppc_state.reserve);
  p.Do(m_ppc_state.reserve_address);

  auto& memory = m_system.GetMemory();
  m_ppc_state.iCache.DoState(memory, p);
  m_ppc_state.dCache.DoState(memory, p);

  auto& mmu = m_system.GetMMU();
  if (p.IsReadMode())
  {
    mmu.DoState(p, old_sr != m_ppc_state.sr);

    if (!m_ppc_state.m_enable_dcache)
    {
      INFO_LOG_FMT(POWERPC, "Flushing data cache");
      m_ppc_state.dCache.FlushAll(memory);
    }

    RoundingModeUpdated(m_ppc_state);
    RecalculateAllFeatureFlags(m_ppc_state);

    mmu.IBATUpdated();
    mmu.DBATUpdated();
  }
  else
  {
    mmu.DoState(p, false);
  }

  // SystemTimers::DecrementerSet();
  // SystemTimers::TimeBaseSet();

  m_system.GetJitInterface().DoState(p);
}

void PowerPCManager::ResetRegisters()
{
  std::ranges::fill(m_ppc_state.ps, PairedSingle{});
  std::ranges::fill(m_ppc_state.sr, 0U);
  std::ranges::fill(m_ppc_state.gpr, 0U);
  std::ranges::fill(m_ppc_state.spr, 0U);

  // Gamecube:
  // 0x00080200 = lonestar 2.0
  // 0x00088202 = lonestar 2.2
  // 0x70000100 = gekko 1.0
  // 0x00080100 = gekko 2.0
  // 0x00083203 = gekko 2.3a
  // 0x00083213 = gekko 2.3b
  // 0x00083204 = gekko 2.4
  // 0x00083214 = gekko 2.4e (8SE) - retail HW2
  // Wii:
  // 0x00087102 = broadway retail hw
  if (m_system.IsWii())
  {
    m_ppc_state.spr[SPR_PVR] = 0x00087102;
  }
  else
  {
    m_ppc_state.spr[SPR_PVR] = 0x00083214;
  }
  m_ppc_state.spr[SPR_HID1] = 0x80000000;  // We're running at 3x the bus clock
  m_ppc_state.spr[SPR_ECID_U] = 0x0d96e200;
  m_ppc_state.spr[SPR_ECID_M] = 0x1840c00d;
  m_ppc_state.spr[SPR_ECID_L] = 0x82bb08e8;

  m_ppc_state.fpscr.Hex = 0;
  m_ppc_state.pc = 0;
  m_ppc_state.npc = 0;
  m_ppc_state.Exceptions = 0;

  m_ppc_state.reserve = false;
  m_ppc_state.reserve_address = 0;

  for (auto& v : m_ppc_state.cr.fields)
  {
    v = 0x8000000000000001;
  }
  m_ppc_state.SetXER({});

  auto& mmu = m_system.GetMMU();
  mmu.DBATUpdated();
  mmu.IBATUpdated();

  auto& system_timers = m_system.GetSystemTimers();
  TL(m_ppc_state) = 0;
  TU(m_ppc_state) = 0;
  system_timers.TimeBaseSet();

  // MSR should be 0x40, but we don't emulate BS1, so it would never be turned off :}
  m_ppc_state.msr.Hex = 0;
  m_ppc_state.spr[SPR_DEC] = 0xFFFFFFFF;
  system_timers.DecrementerSet();

  RoundingModeUpdated(m_ppc_state);
  RecalculateAllFeatureFlags(m_ppc_state);
}

void PowerPCManager::InitializeCPUCore(CPUCore cpu_core)
{
  // We initialize the interpreter because
  // it is used on boot and code window independently.
  auto& interpreter = m_system.GetInterpreter();
  interpreter.Init();

  switch (cpu_core)
  {
  case CPUCore::Interpreter:
    m_cpu_core_base = &interpreter;
    break;

  default:
    m_cpu_core_base = m_system.GetJitInterface().InitJitCore(cpu_core);
    if (!m_cpu_core_base)  // Handle Situations where JIT core isn't available
    {
      WARN_LOG_FMT(POWERPC, "CPU core {} not available. Falling back to default.",
                   static_cast<int>(cpu_core));
      m_cpu_core_base = m_system.GetJitInterface().InitJitCore(DefaultCPUCore());
    }
    break;
  }

  m_mode = m_cpu_core_base == &interpreter ? CoreMode::Interpreter : CoreMode::JIT;
}

std::span<const CPUCore> AvailableCPUCores()
{
  static constexpr auto cpu_cores = {
#ifdef _M_X86_64
      CPUCore::JIT64,
#elif defined(_M_ARM_64)
      CPUCore::JITARM64,
#endif
      CPUCore::CachedInterpreter,
      CPUCore::Interpreter,
      CPUCore::StaticRecomp,
  };

  return cpu_cores;
}

CPUCore DefaultCPUCore()
{
#ifdef _M_X86_64
  return CPUCore::JIT64;
#elif defined(_M_ARM_64)
  return CPUCore::JITARM64;
#else
  return CPUCore::CachedInterpreter;
#endif
}

void PowerPCManager::RefreshConfig()
{
  const bool old_enable_dcache = m_ppc_state.m_enable_dcache;

  m_ppc_state.m_enable_dcache = Config::Get(Config::MAIN_ACCURATE_CPU_CACHE);

  if (old_enable_dcache && !m_ppc_state.m_enable_dcache)
  {
    INFO_LOG_FMT(POWERPC, "Flushing data cache");
    m_ppc_state.dCache.FlushAll(m_system.GetMemory());
  }
}

void PowerPCManager::Init(CPUCore cpu_core)
{
  m_registered_config_callback_id =
      CPUThreadConfigCallback::AddConfigChangedCallback([this] { RefreshConfig(); });
  RefreshConfig();

  m_invalidate_cache_thread_safe =
      m_system.GetCoreTiming().RegisterEvent("invalidateEmulatedCache", InvalidateCacheThreadSafe);

  Reset();

  InitializeCPUCore(cpu_core);
  auto& memory = m_system.GetMemory();
  m_ppc_state.iCache.Init(memory);
  m_ppc_state.dCache.Init(memory);
}

void PowerPCManager::Reset()
{
  m_ppc_state.pagetable_base = 0;
  m_ppc_state.pagetable_mask = 0;
  m_ppc_state.pagetable_update_pending = false;
  m_ppc_state.tlb = {};

  ResetRegisters();
  m_ppc_state.iCache.Reset(m_system.GetJitInterface());
  m_ppc_state.dCache.Reset();
  m_system.GetMMU().Reset();
}

void PowerPCManager::ScheduleInvalidateCacheThreadSafe(u32 address)
{
  auto& cpu = m_system.GetCPU();

  if (cpu.GetState() == CPU::State::Running && !Core::IsCPUThread())
  {
    m_system.GetCoreTiming().ScheduleEvent(0, m_invalidate_cache_thread_safe, address,
                                           CoreTiming::FromThread::NON_CPU);
  }
  else
  {
    m_ppc_state.iCache.Invalidate(m_system.GetMemory(), m_system.GetJitInterface(),
                                  static_cast<u32>(address));
    Host_JitCacheInvalidation();
  }
}

void PowerPCManager::Shutdown()
{
  CPUThreadConfigCallback::RemoveConfigChangedCallback(m_registered_config_callback_id);
  InjectExternalCPUCore(nullptr);
  m_system.GetJitInterface().Shutdown();
  m_system.GetInterpreter().Shutdown();
  m_cpu_core_base = nullptr;
}

CoreMode PowerPCManager::GetMode() const
{
  return !m_cpu_core_base_is_injected ? m_mode : CoreMode::Interpreter;
}

void PowerPCManager::ApplyMode()
{
  auto& interpreter = m_system.GetInterpreter();

  switch (m_mode)
  {
  case CoreMode::Interpreter:  // Switching from JIT to interpreter
    m_cpu_core_base = &interpreter;
    break;

  case CoreMode::JIT:  // Switching from interpreter to JIT.
    // Don't really need to do much. It'll work, the cache will refill itself.
    m_cpu_core_base = m_system.GetJitInterface().GetCore();
    if (!m_cpu_core_base)  // Has a chance to not get a working JIT core if one isn't active on host
      m_cpu_core_base = &interpreter;
    break;
  }
}

void PowerPCManager::SetMode(CoreMode new_mode)
{
  if (new_mode == m_mode)
    return;  // We don't need to do anything.

  m_mode = new_mode;

  // If we're using an external CPU core implementation then don't do anything.
  if (m_cpu_core_base_is_injected)
    return;

  ApplyMode();
}

const char* PowerPCManager::GetCPUName() const
{
  return m_cpu_core_base->GetName();
}

void PowerPCManager::InjectExternalCPUCore(CPUCoreBase* new_cpu)
{
  // Previously injected.
  if (m_cpu_core_base_is_injected)
    m_cpu_core_base->Shutdown();

  // nullptr means just remove
  if (!new_cpu)
  {
    if (m_cpu_core_base_is_injected)
    {
      m_cpu_core_base_is_injected = false;
      ApplyMode();
    }
    return;
  }

  new_cpu->Init();
  m_cpu_core_base = new_cpu;
  m_cpu_core_base_is_injected = true;
}

void PowerPCManager::SingleStep()
{
  m_cpu_core_base->SingleStep();
}

void PowerPCManager::RunLoop()
{
  m_cpu_core_base->Run();
  Host_UpdateDisasmDialog();
}

u64 PowerPCManager::ReadFullTimeBaseValue() const
{
  u64 value;
  std::memcpy(&value, &TL(m_ppc_state), sizeof(value));
  return value;
}

void PowerPCManager::WriteFullTimeBaseValue(u64 value)
{
  std::memcpy(&TL(m_ppc_state), &value, sizeof(value));
}

void UpdatePerformanceMonitor(u32 cycles, u32 num_load_stores, u32 num_fp_inst,
                              PowerPCState& ppc_state)
{
  switch (MMCR0(ppc_state).PMC1SELECT)
  {
  case 0:  // No change
    break;
  case 1:  // Processor cycles
    ppc_state.spr[SPR_PMC1] += cycles;
    break;
  default:
    break;
  }

  switch (MMCR0(ppc_state).PMC2SELECT)
  {
  case 0:  // No change
    break;
  case 1:  // Processor cycles
    ppc_state.spr[SPR_PMC2] += cycles;
    break;
  case 11:  // Number of loads and stores completed
    ppc_state.spr[SPR_PMC2] += num_load_stores;
    break;
  default:
    break;
  }

  switch (MMCR1(ppc_state).PMC3SELECT)
  {
  case 0:  // No change
    break;
  case 1:  // Processor cycles
    ppc_state.spr[SPR_PMC3] += cycles;
    break;
  case 11:  // Number of FPU instructions completed
    ppc_state.spr[SPR_PMC3] += num_fp_inst;
    break;
  default:
    break;
  }

  switch (MMCR1(ppc_state).PMC4SELECT)
  {
  case 0:  // No change
    break;
  case 1:  // Processor cycles
    ppc_state.spr[SPR_PMC4] += cycles;
    break;
  default:
    break;
  }

  if ((MMCR0(ppc_state).PMC1INTCONTROL && (ppc_state.spr[SPR_PMC1] & 0x80000000) != 0) ||
      (MMCR0(ppc_state).PMCINTCONTROL && (ppc_state.spr[SPR_PMC2] & 0x80000000) != 0) ||
      (MMCR0(ppc_state).PMCINTCONTROL && (ppc_state.spr[SPR_PMC3] & 0x80000000) != 0) ||
      (MMCR0(ppc_state).PMCINTCONTROL && (ppc_state.spr[SPR_PMC4] & 0x80000000) != 0))
  {
    ppc_state.Exceptions |= EXCEPTION_PERFORMANCE_MONITOR;
  }
}

}  // namespace PowerPC
