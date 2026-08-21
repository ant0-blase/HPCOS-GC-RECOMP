// RecompCore: StaticRecomp CPU core - Memory and instruction fallback HLE hooks.
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/StaticRecomp/StaticRecompCore.h"
#include "Core/System.h"
#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/PowerPC/JitInterface.h"
#include "Core/PowerPC/Interpreter/Interpreter.h"
#include "Core/PowerPC/StaticRecomp/StaticRecompLockstep.h"
#include "Core/HW/GPFifo.h"
#include "Core/HW/ProcessorInterface.h"
#include "Core/HW/SystemTimers.h"
#include "Common/Logging/Log.h"

#include <algorithm>
#include <cstdio>

namespace
{
constexpr u32 LOCKED_CACHE_BASE = 0xE0000000u;


// Host-side copy of GXRuntime's program-exception transition.
//
// StaticRecompCore_Hooks.cpp is linked into Dolphin's libcore/libmain, while
// ppc_program_exception() itself lives inside the per-game recomp module.
// Android links libmain.so with --no-undefined, so keep this transition local
// to the chassis instead of depending on a symbol from a module dlopen()'d
// later.
static inline void StaticRecompProgramException(CPUState* cpu, u32 cause, u32 cia)
{
  const u32 old_msr = cpu->msr;
  constexpr u32 clear =
      PPC_MSR_POW | PPC_MSR_EE | PPC_MSR_PR | PPC_MSR_FP |
      PPC_MSR_FE0 | PPC_MSR_SE | PPC_MSR_BE | PPC_MSR_FE1 |
      PPC_MSR_IR | PPC_MSR_DR | PPC_MSR_PM | PPC_MSR_RI | PPC_MSR_LE;

  u32 next_msr = old_msr & ~clear;
  if (old_msr & PPC_MSR_ILE)
    next_msr |= PPC_MSR_LE;

  cpu->program_exception |= cause;
  cpu->srr0 = cia;
  cpu->srr1 = (old_msr & PPC_MSR_RFI_MASK) | cause;
  cpu->exception |= PPC_EXC_PROGRAM;
  cpu->msr = next_msr;
  cpu->pc = ((next_msr & PPC_MSR_IP) ? 0xFFF00000u : 0u) + PPC_VECTOR_PROGRAM;
}
}

bool StaticRecompCore::HookHostCall(CPUState* cpu, u32 address)
{
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  return core->m_module_source.host_call &&
         core->m_module_source.host_call(cpu, address, core->m_module_source.host_call_user);
}

u64 StaticRecompCore::HookExternalRead(CPUState* cpu, u32 ea, u8 size)
{
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  // TranslateRelAddress is identity when no REL is active. HPCOS is DOL-only,
  // so avoid an out-of-line call on every external PSQ access.
  if (!core->m_active_rel_sections.empty())
    ea = core->TranslateRelAddress(ea);
  if (ea == 0)
    std::fprintf(stderr, "[zero-access] read size=%u guest_pc=%08x ppc_pc=%08x lr=%08x\n", size,
                 cpu->pc, core->m_system.GetPPCState().pc, cpu->lr);

  // Locked-L1 fast path. Dolphin's MMU maps the conventional 0xE0000000
  // locked-cache window directly to Memory::GetL1Cache(), with big-endian
  // byte order. PSQ-heavy GameCube code commonly keeps vertex scratch data
  // here, so routing every access through PropagateGuestMSR()+MMU is pure
  // overhead. Keep lockstep on the canonical MMU path so its journals remain
  // unchanged.
  if (!core->m_lockstep_verifier->m_ls_journaling && (ea >> 28) == 0xEu)
  {
    const u32 offset = ea - LOCKED_CACHE_BASE;
    if (core->m_l1_cache && size != 0 && size <= core->m_l1_cache_size &&
        offset <= core->m_l1_cache_size - size)
    {
      const u8* const p = core->m_l1_cache + offset;
      switch (size)
      {
      case 1:
        return p[0];
      case 2:
        return (static_cast<u64>(p[0]) << 8) | p[1];
      case 4:
        return (static_cast<u64>(p[0]) << 24) | (static_cast<u64>(p[1]) << 16) |
               (static_cast<u64>(p[2]) << 8) | p[3];
      case 8:
        return (static_cast<u64>(p[0]) << 56) | (static_cast<u64>(p[1]) << 48) |
               (static_cast<u64>(p[2]) << 40) | (static_cast<u64>(p[3]) << 32) |
               (static_cast<u64>(p[4]) << 24) | (static_cast<u64>(p[5]) << 16) |
               (static_cast<u64>(p[6]) << 8) | p[7];
      default:
        break;
      }
    }
  }
  if (core->m_external_trace) [[unlikely]]
    core->RecordExternalAccess(ea, cpu->pc, size, false);

  // GHSE69 polls PI_INTERRUPT_CAUSE and PI_INTERRUPT_MASK in its scheduler /
  // interrupt path tens of thousands of times during loading. Dolphin registers
  // both as DirectRead<u32>, so for the exact observed guest instructions the
  // MMU/MMIO dispatcher adds no semantics. Keep lockstep on the canonical path.
  if (core->m_hpcos_pi_poll_fastpath && !core->m_lockstep_verifier->m_ls_journaling && size == 4)
  {
    auto& pi = core->m_system.GetProcessorInterface();
    if (cpu->pc == 0x801744C0u && ea == 0xCC003000u)
      return pi.GetCause();
    if (cpu->pc == 0x801744D4u && ea == 0xCC003004u)
      return pi.GetMask();
  }

  core->PropagateGuestMSR();
  auto& mmu = core->m_system.GetMMU();
  u64 value;
  switch (size)
  {
  case 1:
    value = mmu.Read<u8>(ea);
    break;
  case 2:
    value = mmu.Read<u16>(ea);
    break;
  case 4:
    value = mmu.Read<u32>(ea);
    break;
  case 8:
    value = mmu.Read<u64>(ea);
    break;
  default:
    ERROR_LOG_FMT(POWERPC, "StaticRecomp: external read of bad size {} at 0x{:08X}", size, ea);
    return 0;
  }
  if (core->m_lockstep_verifier->m_ls_journaling &&
      StaticRecompLockstep::LsHwAccessInScope(mmu, ea))
  {
    core->m_lockstep_verifier->m_journal.native_reads.push_back({ea, static_cast<u32>(value), size});
  }
  /*
   * Diagnostic sampler for pathological MMIO polling loops.
   *
   * A game that never leaves a loading screen is usually spinning on one
   * hardware register that never reaches the value it wants. Set
   * STATICRECOMP_MMIO_TRACE=1 to have the hottest read addresses, with the
   * guest PC doing the reading, reported at shutdown -- that names the
   * register and the code waiting on it instead of leaving it to guesswork.
   *
   * Use a prime interval so a loop containing several external accesses
   * doesn't keep aliasing onto the exact same phase.
   */
  if (core->m_mmio_trace) [[unlikely]]
    core->RecordMmioRead(ea, cpu->pc, static_cast<u32>(value));
  return value;
}

void StaticRecompCore::RecordMmioWrite(u32 ea, u32 guest_pc)
{
  // The locked cache at 0xE0000000 is memory, not a hardware register, and it
  // is touched at hundreds of distinct addresses -- left in, it fills the table
  // and hides the register writes this sampler exists to show.
  if (ea >= 0xE0000000u)
    return;
  for (auto& slot : m_mmio_writes)
  {
    if (slot.count != 0 && slot.address == ea && slot.guest_pc == guest_pc)
    {
      ++slot.count;
      return;
    }
    if (slot.count == 0)
    {
      slot.address = ea;
      slot.guest_pc = guest_pc;
      slot.count = 1;
      return;
    }
  }
}

void StaticRecompCore::RecordMmioRead(u32 ea, u32 guest_pc, u32 value)
{
  if (ea >= 0xE0000000u)
    return;
  // Small fixed table: a stuck game polls a handful of addresses, so this only
  // has to hold the hot ones. Full table simply stops recording.
  for (auto& slot : m_mmio_reads)
  {
    if (slot.count != 0 && slot.address == ea && slot.guest_pc == guest_pc)
    {
      ++slot.count;
      if (value != slot.last_value)
      {
        slot.last_value = value;
        ++slot.distinct;
      }
      return;
    }
    if (slot.count == 0)
    {
      slot.address = ea;
      slot.guest_pc = guest_pc;
      slot.count = 1;
      slot.last_value = value;
      slot.distinct = 1;
      return;
    }
  }
}

void StaticRecompCore::RecordExternalAccess(u32 ea, u32 guest_pc, u8 size, bool write)
{
  const u32 page = ea & 0xFFFFF000u;
  // Small open-addressed table. Trace mode is diagnostic-only, but keep the
  // hot hook lightweight enough that loading behaviour remains representative.
  u32 index = ((page >> 12) * 0x9E3779B1u ^ guest_pc * 0x85EBCA6Bu) & 255u;
  for (u32 probe = 0; probe < 16; ++probe, index = (index + 1) & 255u)
  {
    auto& slot = m_external_accesses[index];
    if ((slot.reads == 0 && slot.writes == 0) ||
        (slot.page == page && slot.guest_pc == guest_pc))
    {
      if (slot.reads == 0 && slot.writes == 0)
      {
        slot.page = page;
        slot.guest_pc = guest_pc;
        slot.min_ea = ea;
        slot.max_ea = ea;
      }
      else
      {
        slot.min_ea = std::min(slot.min_ea, ea);
        slot.max_ea = std::max(slot.max_ea, ea);
      }
      const u32 size_bit = size <= 8 ? size : 0u;
      if (write)
      {
        ++slot.writes;
        slot.write_sizes |= size_bit;
      }
      else
      {
        ++slot.reads;
        slot.read_sizes |= size_bit;
      }
      return;
    }
  }
}

void StaticRecompCore::HookExternalWrite(CPUState* cpu, u32 ea, u64 value, u8 size)
{
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);

  // Gather-pipe fast path: stores to the write-gather pipe page at effective
  // 0xCC008000 go straight to GPFifo, mirroring the MMU's masked-write
  // special case without an MMU round trip. Keying on the effective page is
  // the same shortcut Dolphin's JITs take (optimizeGatherPipe). GPFifo
  // maintains ppc_state.gather_pipe_ptr internally.
  //
  // Tested before TranslateRelAddress: RefreshRelSections discovers REL
  // ranges from section tables living in guest RAM, so a relocated range
  // never covers the 0xCC008000 hardware page and translation is the
  // identity here. Every GX command word the game emits reaches this hook,
  // making it the hottest MMIO path in the runtime; the runtime is built
  // without LTO, so TranslateRelAddress is an out-of-line call into
  // StaticRecompCore_SMC.cpp that this ordering skips entirely.
  if ((ea & 0xFFFFF000) == 0xCC008000u)
  {
    if (core->m_lockstep_verifier->m_ls_journaling)
      core->m_lockstep_verifier->m_journal.native_mmio.push_back({ea, static_cast<u32>(value), size});
    auto& gpfifo = core->m_system.GetGPFifo();
    switch (size)
    {
    case 1:
      gpfifo.StaticRecompWrite8(static_cast<u8>(value));
      return;
    case 2:
      gpfifo.StaticRecompWrite16(static_cast<u16>(value));
      return;
    case 4:
      gpfifo.StaticRecompWrite32(static_cast<u32>(value));
      return;
    case 8:
      gpfifo.StaticRecompWrite64(value);
      return;
    default:
      for (u32 i = size * 8u; i > 0;)
      {
        i -= 8;
        gpfifo.StaticRecompWrite8(static_cast<u8>(value >> i));
      }
      return;
    }
  }

  if (!core->m_active_rel_sections.empty())
    ea = core->TranslateRelAddress(ea);
  if (ea == 0)
    std::fprintf(stderr, "[zero-access] write size=%u guest_pc=%08x ppc_pc=%08x lr=%08x\n", size,
                 cpu->pc, core->m_system.GetPPCState().pc, cpu->lr);

  // Same locked-L1 shortcut as the read side. Preserve the MMU path while
  // lockstep journals are active.
  if (!core->m_lockstep_verifier->m_ls_journaling && (ea >> 28) == 0xEu)
  {
    const u32 offset = ea - LOCKED_CACHE_BASE;
    if (core->m_l1_cache && size != 0 && size <= core->m_l1_cache_size &&
        offset <= core->m_l1_cache_size - size)
    {
      u8* const p = core->m_l1_cache + offset;
      switch (size)
      {
      case 1:
        p[0] = static_cast<u8>(value);
        return;
      case 2:
        p[0] = static_cast<u8>(value >> 8);
        p[1] = static_cast<u8>(value);
        return;
      case 4:
        p[0] = static_cast<u8>(value >> 24);
        p[1] = static_cast<u8>(value >> 16);
        p[2] = static_cast<u8>(value >> 8);
        p[3] = static_cast<u8>(value);
        return;
      case 8:
        p[0] = static_cast<u8>(value >> 56);
        p[1] = static_cast<u8>(value >> 48);
        p[2] = static_cast<u8>(value >> 40);
        p[3] = static_cast<u8>(value >> 32);
        p[4] = static_cast<u8>(value >> 24);
        p[5] = static_cast<u8>(value >> 16);
        p[6] = static_cast<u8>(value >> 8);
        p[7] = static_cast<u8>(value);
        return;
      default:
        break;
      }
    }
  }

  if (core->m_external_trace) [[unlikely]]
    core->RecordExternalAccess(ea, cpu->pc, size, true);

  if (core->m_mmio_trace) [[unlikely]]
    core->RecordMmioWrite(ea, cpu->pc);

  core->PropagateGuestMSR();
  auto& mmu = core->m_system.GetMMU();
  if (core->m_lockstep_verifier->m_ls_journaling &&
      StaticRecompLockstep::LsHwAccessInScope(mmu, ea))
  {
    core->m_lockstep_verifier->m_journal.native_mmio.push_back({ea, static_cast<u32>(value), size});
  }
  switch (size)
  {
  case 1:
    mmu.Write<u8>(static_cast<u8>(value), ea);
    break;
  case 2:
    mmu.Write<u16>(static_cast<u16>(value), ea);
    break;
  case 4:
    mmu.Write<u32>(static_cast<u32>(value), ea);
    break;
  case 8:
    mmu.Write<u64>(value, ea);
    break;
  default:
    ERROR_LOG_FMT(POWERPC, "StaticRecomp: external write of bad size {} at 0x{:08X}", size, ea);
    break;
  }
}

u32 StaticRecompCore::HookExternalRead32(CPUState* cpu, u32 ea, u8 rid)
{
  // eciwx external-control read. EAR-enable and alignment were checked by the
  // generated helper; Dolphin's interpreter services the access as a plain
  // MMU read (the rid is carried in EAR only).
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  ea = core->TranslateRelAddress(ea);
  core->PropagateGuestMSR();
  auto& mmu = core->m_system.GetMMU();
  const u32 value = mmu.Read<u32>(ea);
  if (core->m_lockstep_verifier->m_ls_journaling &&
      StaticRecompLockstep::LsHwAccessInScope(mmu, ea))
  {
    core->m_lockstep_verifier->m_journal.native_reads.push_back({ea, value, 4});
  }
  return value;
}

void StaticRecompCore::HookExternalWrite32(CPUState* cpu, u32 ea, u32 value, u8 rid)
{
  // ecowx external-control write; see HookExternalRead32.
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  ea = core->TranslateRelAddress(ea);
  core->PropagateGuestMSR();
  auto& mmu = core->m_system.GetMMU();
  if (core->m_lockstep_verifier->m_ls_journaling &&
      StaticRecompLockstep::LsHwAccessInScope(mmu, ea))
  {
    core->m_lockstep_verifier->m_journal.native_mmio.push_back({ea, value, 4});
  }
  mmu.Write<u32>(value, ea);
}

void* StaticRecompCore::HookExternalPointer(CPUState* cpu, u32 ea, u32 size)
{
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  if (ea >= LOCKED_CACHE_BASE && size != 0 && core->m_l1_cache &&
      size <= core->m_l1_cache_size &&
      (ea - LOCKED_CACHE_BASE) <= core->m_l1_cache_size - size)
  {
    return core->m_l1_cache + (ea - LOCKED_CACHE_BASE);
  }
  // Everything else stays on the per-access MMU hooks: this hook receives
  // *effective* addresses, and whether one maps to RAM depends on live
  // MSR/BAT state that only the MMU can answer. Handing out a raw pointer
  // here would bypass MMIO and translation. (Memory::GetPointerForRange was
  // considered and rejected for exactly that reason.)
  return nullptr;
}

u32 StaticRecompCore::HookSPRRead(CPUState* cpu, u16 spr, u32 cia)
{
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  auto& ppc = core->m_system.GetPPCState();
  if (spr >= 1024)
  {
    StaticRecompProgramException(cpu, PPC_PROGRAM_ILLEGAL, cia);
    return 0;
  }

  switch (spr)
  {
  case SPR_DEC:
    if ((ppc.spr[SPR_DEC] & 0x80000000u) == 0)
      ppc.spr[SPR_DEC] = core->m_system.GetSystemTimers().GetFakeDecrementer();
    break;
  case SPR_WPAR:
    if (core->m_system.GetGPFifo().IsBNE())
      ppc.spr[SPR_WPAR] |= 1;
    else
      ppc.spr[SPR_WPAR] &= ~1u;
    break;
  case SPR_UPMC1:
    return ppc.spr[SPR_PMC1];
  case SPR_UPMC2:
    return ppc.spr[SPR_PMC2];
  case SPR_UPMC3:
    return ppc.spr[SPR_PMC3];
  case SPR_UPMC4:
    return ppc.spr[SPR_PMC4];
  case SPR_IABR:
    return ppc.spr[SPR_IABR] & ~1u;
  case SPR_TL:
  case SPR_TU:
  {
    // TL/TU in ppc.spr are cached. Materialize the live
    // Dolphin timebase before returning them.
    const u64 time_base = StaticRecompLockstep::g_tb_override_active ?
                              StaticRecompLockstep::g_tb_override_value :
                              core->m_system.GetSystemTimers().GetFakeTimeBase();
    core->m_system.GetPowerPC().WriteFullTimeBaseValue(time_base);
    break;
  }
  default:
    break;
  }
  return ppc.spr[spr];
}

void StaticRecompCore::HookSPRWrite(CPUState* cpu, u16 spr, u32 value, u32 cia)
{
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  auto& system = core->m_system;
  auto& ppc = system.GetPPCState();
  if (spr >= 1024)
  {
    StaticRecompProgramException(cpu, PPC_PROGRAM_ILLEGAL, cia);
    return;
  }

  const u32 old_value = ppc.spr[spr];
  ppc.spr[spr] = value;

  switch (spr)
  {
  case SPR_TL_W:
    TL(ppc) = value;
    system.GetSystemTimers().TimeBaseSet();
    return;
  case SPR_TU_W:
    TU(ppc) = value;
    system.GetSystemTimers().TimeBaseSet();
    return;
  case SPR_PVR:
    ppc.spr[SPR_PVR] = old_value;
    return;
  case SPR_HID0:
  {
    if (HID0(ppc).ICFI)
    {
      HID0(ppc).ICFI = 0;
      ppc.iCache.Reset(system.GetJitInterface());
    }
    return;
  }
  case SPR_HID1:
    ppc.spr[SPR_HID1] &= 0xF8000000u;
    return;
  case SPR_HID4:
    if (old_value != value)
    {
      system.GetMMU().IBATUpdated();
      system.GetMMU().DBATUpdated();
    }
    return;
  case SPR_WPAR:
    system.GetGPFifo().ResetGatherPipe();
    return;
  case SPR_DMAL:
    if (DMAL(ppc).DMA_T)
    {
      const u32 mem_address = DMAU(ppc).MEM_ADDR << 5;
      const u32 cache_address = DMAL(ppc).LC_ADDR << 5;
      u32 length = (DMAU(ppc).DMA_LEN_U << 2) | DMAL(ppc).DMA_LEN_L;
      if (length == 0)
        length = 128;
      if (DMAL(ppc).DMA_LD)
        system.GetMMU().DMA_MemoryToLC(cache_address, mem_address, length);
      else
        system.GetMMU().DMA_LCToMemory(mem_address, cache_address, length);
    }
    DMAL(ppc).DMA_T = 0;
    return;
  case SPR_DEC:
    if ((old_value >> 31) == 0 && (value >> 31) != 0)
      ppc.Exceptions |= EXCEPTION_DECREMENTER;
    system.GetSystemTimers().DecrementerSet();
    return;
  case SPR_SDR:
    system.GetMMU().SDRUpdated();
    return;
  case SPR_MMCR0:
  case SPR_MMCR1:
    PowerPC::MMCRUpdated(ppc);
    return;
  case SPR_THRM1:
  case SPR_THRM2:
  case SPR_THRM3:
  {
    const auto update = [&ppc](UReg_THRM12* reg) {
      if (!THRM3(ppc).E || !reg->V)
      {
        reg->TIV = 0;
      }
      else
      {
        reg->TIV = 1;
        reg->TIN = reg->TID ? 42 < reg->THRESHOLD : 42 > reg->THRESHOLD;
      }
    };
    update(&THRM1(ppc));
    update(&THRM2(ppc));
    return;
  }
  default:
    break;
  }

  const bool ibat = (spr >= SPR_IBAT0U && spr <= SPR_IBAT3L) ||
                    (spr >= SPR_IBAT4U && spr <= SPR_IBAT7L);
  const bool dbat = (spr >= SPR_DBAT0U && spr <= SPR_DBAT3L) ||
                    (spr >= SPR_DBAT4U && spr <= SPR_DBAT7L);
  if (old_value != value && ibat)
    system.GetMMU().IBATUpdated();
  else if (old_value != value && dbat)
    system.GetMMU().DBATUpdated();
}

void StaticRecompCore::HookCacheControl(CPUState* cpu, u8 operation, u32 ea, u32 cia)
{
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  auto& ppc = core->m_system.GetPPCState();

  // dcbf/dcbst/dcbi with dcache emulation off, taken before any translation or
  // MSR propagation because it is by far the hottest cache op: ~15M per session
  // against 85 icbi.
  //
  // Dolphin's interpreter calls InvalidateICacheLine here, but its own comment
  // says why: a heuristic compensating for the JIT's lack of precise L1 icache
  // emulation, since games use dcbf where they should use icbi. HPCOS does not
  // need the heuristic -- it verifies chunk hashes against guest RAM and retires
  // mismatching chunks, an exact guard that icbi still drives below. Paying it
  // anyway cost InvalidateICacheLine + OnICacheInvalidate on every one of those
  // 15M calls.
  //
  // Set STATICRECOMP_DCBF_INVALIDATES=1 to restore Dolphin's heuristic.
  if (operation != PPC_CACHE_ICBI && !ppc.m_enable_dcache)
  {
    static const bool dcbf_invalidates = [] {
      const char* value = std::getenv("STATICRECOMP_DCBF_INVALIDATES");
      return value && value[0] == '1';
    }();
    if (!dcbf_invalidates)
      return;
    core->m_system.GetJitInterface().InvalidateICacheLine(core->TranslateRelAddress(ea));
    return;
  }

  ea = core->TranslateRelAddress(ea);
  core->PropagateGuestMSR();
  auto& mmu = core->m_system.GetMMU();

  if (operation == PPC_CACHE_ICBI)
  {
    ppc.iCache.Invalidate(core->m_system.GetMemory(), core->m_system.GetJitInterface(), ea);
    return;
  }

  switch (operation)
  {
  case PPC_CACHE_DCBST:
    mmu.StoreDCacheLine(ea);
    break;
  case PPC_CACHE_DCBF:
    mmu.FlushDCacheLine(ea);
    break;
  case PPC_CACHE_DCBI:
    mmu.InvalidateDCacheLine(ea);
    break;
  default:
    StaticRecompProgramException(cpu, PPC_PROGRAM_ILLEGAL, cia);
    break;
  }
}

void StaticRecompCore::HookInstructionFallback(CPUState* cpu, u32 raw, u32 cia)
{
  auto* core = static_cast<StaticRecompCore*>(cpu->external_user_data);
  cia = core->TranslateRelAddress(cia);
  ++core->m_hook_fallback_instructions;

  // Histogram of what still escapes to the interpreter, keyed the way the
  // PowerPC encoding is: a primary opcode, plus the extended field for the
  // forms that carry one. Reported at shutdown.
  {
    const u32 primary = raw >> 26;
    ++core->m_fb_primary[primary];
    switch (primary)
    {
    case 31:
      ++core->m_fb_ext31[(raw >> 1) & 0x3FFu];
      break;
    case 63:
      ++core->m_fb_ext63[(raw >> 1) & 0x3FFu];
      break;
    case 19:
      ++core->m_fb_ext19[(raw >> 1) & 0x3FFu];
      break;
    case 4:
      ++core->m_fb_ext4[(raw >> 1) & 0x7FFu];
      break;
    default:
      break;
    }
  }

  // Lockstep: a block that fell back to the interpreter for an unmodeled
  // instruction (DMA mtspr, cache op, ...) performed side effects not captured
  // by the RAM journal / MMIO hooks, so re-running it on the shadow would
  // double-issue them. Mark it unsafe to differentially check.
  if (core->m_lockstep_verifier->m_ls_journaling)
    core->m_lockstep_verifier->m_ls_fallback_seen = true;

  auto& system = core->m_system;
  auto& ppc = system.GetPPCState();

  // Fast path for dcbf/dcbst/dcbi/icbi: streaming code flushes caches in
  // 32-byte loops (thousands per frame), and these ops read two GPRs and
  // change no CPU state, so they run straight off ctx without the full
  // SyncOut/interpreter/SyncIn round trip. This mirrors Dolphin's
  // interpreter with dcache emulation off: every one funnels into
  // InvalidateICacheLine (keeping the SMC guard exact). dcbi's PR!=0
  // privilege trap and dcache-on configs take the slow path.
  if ((raw >> 26) == 31u && !ppc.m_enable_dcache)
  {
    const u32 xo = (raw >> 1) & 0x3FFu;
    if (xo == 86u || xo == 54u || xo == 982u || (xo == 470u && (cpu->msr & 0x4000u) == 0))
    {
      const u32 ra = (raw >> 16) & 31u;
      const u32 rb = (raw >> 11) & 31u;
      const u32 ea = (ra ? cpu->gpr[ra] : 0u) + cpu->gpr[rb];
      if (xo == 982u)
      {
        system.GetJitInterface().InvalidateICacheLine(ea);
      }
      // These bypass SingleStepInner, so charge Dolphin's PPCTables cost
      // here (icbi 4, dcbf/dcbst/dcbi 5); their emitted block cost is zero.
      ppc.downcount -= (xo == 982u) ? 4 : 5;
      cpu->pc = cia + 4u;
      return;
    }
  }

  // The recompiled segment resumes via the dispatcher at the PC this leaves
  // behind, so this must execute exactly the instruction at cia via
  // Dolphin's interpreter and hand the register state back.
  core->SyncOut();
  ppc.pc = cia;
  ppc.npc = cia + 4;
  ppc.downcount -= system.GetInterpreter().SingleStepInner();
  core->SyncIn();
}
