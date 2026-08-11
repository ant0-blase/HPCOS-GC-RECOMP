// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/MMUBAT.h"

#include <algorithm>
#include <bit>
#include <cstddef>
#include <cstring>
#include <memory>
#include <string>
#include <utility>

#ifdef _M_X86_64
#include <emmintrin.h>
#endif

#include "Common/Align.h"
#include "Common/Assert.h"
#include "Common/BitUtils.h"
#include "Common/ChunkFile.h"
#include "Common/CommonTypes.h"
#include "Common/Logging/Log.h"

#include "Core/Core.h"
#include "Core/HW/CPU.h"
#include "Core/HW/GPFifo.h"
#include "Core/HW/MMIO.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/ProcessorInterface.h"
#include "Core/PowerPC/GDBStub.h"
#include "Core/PowerPC/JitInterface.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/PowerPC/StaticRecomp/StaticRecompLockstep.h"
#include "Core/System.h"

#include "VideoCommon/EFBInterface.h"

namespace PowerPC
{
template <XCheckTLBFlag flag, std::unsigned_integral T, bool never_translate>
T MMU::ReadFromHardware(u32 em_address)
{
  // ReadFromHardware is currently used with XCheckTLBFlag::OpcodeNoException by host instruction
  // functions. Actual instruction decoding (which can raise exceptions and uses icache) is handled
  // by TryReadInstruction.
  static_assert(flag == XCheckTLBFlag::NoException || flag == XCheckTLBFlag::Read ||
                flag == XCheckTLBFlag::OpcodeNoException);

  const u32 em_address_start_page = em_address & ~HW_PAGE_MASK;
  const u32 em_address_end_page = (em_address + sizeof(T) - 1) & ~HW_PAGE_MASK;
  if (em_address_start_page != em_address_end_page)
  {
    // This could be unaligned down to the byte level... hopefully this is rare, so doing it this
    // way isn't too terrible.
    // TODO: floats on non-word-aligned boundaries should technically cause alignment exceptions.
    // Note that "word" means 32-bit, so paired singles or doubles might still be 32-bit aligned!
    T var = 0;
    for (u32 i = 0; i < sizeof(T); ++i)
    {
      var = (var << 8) | ReadFromHardware<flag, u8, never_translate>(em_address + i);
    }
    return var;
  }

  bool wi = false;

  if (!never_translate &&
      (IsOpcodeFlag(flag) ? m_ppc_state.msr.IR.Value() : m_ppc_state.msr.DR.Value()))
  {
    auto translated_addr = TranslateAddress<flag>(em_address);
    if (!translated_addr.Success())
    {
      if (flag == XCheckTLBFlag::Read)
        GenerateDSIException(em_address, false);
      return 0;
    }
    em_address = translated_addr.address;
    wi = translated_addr.wi;
  }

  if (flag == XCheckTLBFlag::Read && (em_address & 0xF8000000) == 0x08000000)
  {
    // StaticRecomp lockstep: replay native's recorded read instead of touching
    // hardware, so the shadow sees identical MMIO inputs (no drift/side effect).
    if (StaticRecompLockstep::g_hw_read_sink)
    {
      return static_cast<T>(StaticRecompLockstep::g_hw_read_sink(
          em_address, sizeof(T), StaticRecompLockstep::g_hw_read_sink_user));
    }
    if (em_address < 0x0c000000)
    {
      return EFB_Read(em_address);
    }
    else
    {
      return static_cast<T>(
          m_memory.GetMMIOMapping()->Read<std::make_unsigned_t<T>>(m_system, em_address));
    }
  }

  // Locked L1 technically doesn't have a fixed address, but games all use 0xE0000000.
  if (m_memory.GetL1Cache() && (em_address >> 28) == 0xE &&
      (em_address < (0xE0000000 + m_memory.GetL1CacheSize())))
  {
    T value;
    std::memcpy(&value, &m_memory.GetL1Cache()[em_address & 0x0FFFFFFF], sizeof(T));
    return bswap(value);
  }

  if (m_memory.GetRAM() && (em_address & 0xF8000000) == 0x00000000)
  {
    // Handle RAM; the masking intentionally discards bits (essentially creating
    // mirrors of memory).
    T value;
    em_address &= m_memory.GetRamMask();

    if (!m_ppc_state.m_enable_dcache || wi)
    {
      std::memcpy(&value, &m_memory.GetRAM()[em_address], sizeof(T));
    }
    else
    {
      m_ppc_state.dCache.Read(m_memory, em_address, &value, sizeof(T),
                              HID0(m_ppc_state).DLOCK || flag != XCheckTLBFlag::Read);
    }

    return bswap(value);
  }

  if (m_memory.GetEXRAM() && (em_address >> 28) == 0x1 &&
      (em_address & 0x0FFFFFFF) < m_memory.GetExRamSizeReal())
  {
    T value;
    em_address &= 0x0FFFFFFF;

    if (!m_ppc_state.m_enable_dcache || wi)
    {
      std::memcpy(&value, &m_memory.GetEXRAM()[em_address], sizeof(T));
    }
    else
    {
      m_ppc_state.dCache.Read(m_memory, em_address + 0x10000000, &value, sizeof(T),
                              HID0(m_ppc_state).DLOCK || flag != XCheckTLBFlag::Read);
    }

    return bswap(value);
  }

  // In Fake-VMEM mode, we need to map the memory somewhere into
  // physical memory for BAT translation to work; we currently use
  // [0x7E000000, 0x80000000).
  if (m_memory.GetFakeVMEM() && ((em_address & 0xFE000000) == 0x7E000000))
  {
    T value;
    std::memcpy(&value, &m_memory.GetFakeVMEM()[em_address & m_memory.GetFakeVMemMask()],
                sizeof(T));
    return bswap(value);
  }

  // Memory access error. Game Boy Interface relies on this to confirm that MEM2 isn't present.
  // TODO: This interrupt is supposed to have associated cause and address registers.
  m_system.GetProcessorInterface().SetInterrupt(ProcessorInterface::INT_CAUSE_PI);

  // Don't show a panic alert for the specific access Game Boy Interface does.
  if (em_address != 0x10000000 || (m_ppc_state.pc >> 28) != 0)
  {
    PanicAlertFmt("Unable to resolve read address {:x} PC {:x}", em_address, m_ppc_state.pc);
    if (m_system.IsPauseOnPanicMode())
    {
      m_system.GetCPU().Break();
      m_ppc_state.Exceptions |= EXCEPTION_DSI | EXCEPTION_FAKE_MEMCHECK_HIT;
    }
  }

  return 0;
}

template <XCheckTLBFlag flag, bool never_translate>
void MMU::WriteToHardware(u32 em_address, const u32 data, const u32 size)
{
  static_assert(flag == XCheckTLBFlag::NoException || flag == XCheckTLBFlag::Write);

  DEBUG_ASSERT(size <= 4);

  const u32 em_address_start_page = em_address & ~HW_PAGE_MASK;
  const u32 em_address_end_page = (em_address + size - 1) & ~HW_PAGE_MASK;
  if (em_address_start_page != em_address_end_page)
  {
    // The write crosses a page boundary. Break it up into two writes.
    // TODO: floats on non-word-aligned boundaries should technically cause alignment exceptions.
    // Note that "word" means 32-bit, so paired singles or doubles might still be 32-bit aligned!
    const u32 first_half_size = em_address_end_page - em_address;
    const u32 second_half_size = size - first_half_size;
    WriteToHardware<flag, never_translate>(em_address, std::rotr(data, second_half_size * 8),
                                           first_half_size);
    WriteToHardware<flag, never_translate>(em_address_end_page, data, second_half_size);
    return;
  }

  bool wi = false;

  if (!never_translate && m_ppc_state.msr.DR)
  {
    auto translated_addr = TranslateAddress<flag>(em_address);
    if (!translated_addr.Success())
    {
      if (flag == XCheckTLBFlag::Write)
        GenerateDSIException(em_address, true);
      return;
    }
    em_address = translated_addr.address;
    wi = translated_addr.wi;
  }

  // StaticRecomp lockstep: while an interpreter shadow re-run is in progress,
  // capture and SUPPRESS hardware (MMIO / gather-pipe) writes so we do not
  // re-issue side effects Dolphin already performed for the native run (a
  // second GX FIFO burst, a duplicate PI/VI register write). RAM/L1 writes fall
  // through and commit normally; the harness restores RAM around the shadow.
  // The sink is null outside a shadow (single predictable branch) and is never
  // installed on module-less runs, so the game-agnostic invariant is untouched.
  if constexpr (flag == XCheckTLBFlag::Write)
  {
    if (StaticRecompLockstep::g_hw_write_sink)
    {
      const bool is_gather =
          (em_address & 0xFFFFF000) == GPFifo::GATHER_PIPE_PHYSICAL_ADDRESS;
      const bool is_mmio = (em_address & 0xF8000000) == 0x08000000;
      if (is_gather || is_mmio)
      {
        StaticRecompLockstep::g_hw_write_sink(em_address, data, size,
                                              StaticRecompLockstep::g_hw_write_sink_user);
        return;
      }
    }
  }

  // Check for a gather pipe write (which are not implemented through the MMIO system).
  //
  // Note that we must mask the address to correctly emulate certain games; Pac-Man World 3
  // in particular is affected by this. (See https://bugs.dolphin-emu.org/issues/8386)
  //
  // The PowerPC 750CL manual says (in section 9.4.2 Write Gather Pipe Operation on page 327):
  // "A noncacheable store to an address with bits 0-26 matching WPAR[GB_ADDR] but with bits 27-31
  // not all zero will result in incorrect data in the buffer." So, it's possible that in some cases
  // writes which do not exactly match the masking behave differently, but Pac-Man World 3's writes
  // happen to behave correctly.
  if (flag == XCheckTLBFlag::Write &&
      (em_address & 0xFFFFF000) == GPFifo::GATHER_PIPE_PHYSICAL_ADDRESS)
  {
    switch (size)
    {
    case 1:
      m_system.GetGPFifo().Write8(static_cast<u8>(data));
      return;
    case 2:
      m_system.GetGPFifo().Write16(static_cast<u16>(data));
      return;
    case 4:
      m_system.GetGPFifo().Write32(data);
      return;
    default:
      // Some kind of misaligned write. TODO: Does this match how the actual hardware handles it?
      auto& gpfifo = m_system.GetGPFifo();
      for (size_t i = size * 8; i > 0;)
      {
        i -= 8;
        gpfifo.Write8(static_cast<u8>(data >> i));
      }
      return;
    }
  }

  if (flag == XCheckTLBFlag::Write && (em_address & 0xF8000000) == 0x08000000)
  {
    if (em_address < 0x0c000000)
    {
      EFB_Write(data, em_address);
      return;
    }

    switch (size)
    {
    case 1:
      m_memory.GetMMIOMapping()->Write<u8>(m_system, em_address, static_cast<u8>(data));
      return;
    case 2:
      m_memory.GetMMIOMapping()->Write<u16>(m_system, em_address, static_cast<u16>(data));
      return;
    case 4:
      m_memory.GetMMIOMapping()->Write<u32>(m_system, em_address, data);
      return;
    default:
      // Some kind of misaligned write. TODO: Does this match how the actual hardware handles it?
      for (size_t i = size * 8; i > 0; em_address++)
      {
        i -= 8;
        m_memory.GetMMIOMapping()->Write<u8>(m_system, em_address, static_cast<u8>(data >> i));
      }
      return;
    }
  }

  const u32 swapped_data = Common::swap32(std::rotr(data, size * 8));

  // Locked L1 technically doesn't have a fixed address, but games all use 0xE0000000.
  if (m_memory.GetL1Cache() && (em_address >> 28 == 0xE) &&
      (em_address < (0xE0000000 + m_memory.GetL1CacheSize())))
  {
    // StaticRecomp lockstep: record this L1Cache offset's pre-image so the shadow
    // re-run's LC stores can be undone afterward (locked cache is memory, so the
    // shadow commits normally but must not leak into the canonical native run).
    // Null/no-op outside a shadow (module-less runs never set it).
    if constexpr (flag == XCheckTLBFlag::Write)
    {
      if (StaticRecompLockstep::g_lc_write_journal)
        StaticRecompLockstep::g_lc_write_journal(em_address & 0x0FFFFFFF, size,
                                                 StaticRecompLockstep::g_lc_write_journal_user);
    }
    std::memcpy(&m_memory.GetL1Cache()[em_address & 0x0FFFFFFF], &swapped_data, size);
    return;
  }

  if (wi && (size < 4 || (em_address & 0x3)))
  {
    // When a write to memory is performed in hardware, 64 bits of data are sent to the memory
    // controller along with a mask. This mask is encoded using just two bits of data - one for
    // the upper 32 bits and one for the lower 32 bits - which leads to some odd data duplication
    // behavior for write-through/cache-inhibited writes with a start address or end address that
    // isn't 32-bit aligned. See https://bugs.dolphin-emu.org/issues/12565 for details.

    // TODO: This interrupt is supposed to have associated cause and address registers
    // TODO: This should trigger the hwtest's interrupt handling, but it does not seem to
    //       (https://github.com/dolphin-emu/hwtests/pull/42)
    m_system.GetProcessorInterface().SetInterrupt(ProcessorInterface::INT_CAUSE_PI);

    const u32 rotated_data = std::rotr(data, ((em_address & 0x3) + size) * 8);

    const u32 start_addr = Common::AlignDown(em_address, 8);
    const u32 end_addr = Common::AlignUp(em_address + size, 8);
    for (u32 addr = start_addr; addr != end_addr; addr += 8)
    {
      WriteToHardware<flag, true>(addr, rotated_data, 4);
      WriteToHardware<flag, true>(addr + 4, rotated_data, 4);
    }

    return;
  }

  if (m_memory.GetRAM() && (em_address & 0xF8000000) == 0x00000000)
  {
    // Handle RAM; the masking intentionally discards bits (essentially creating
    // mirrors of memory).
    em_address &= m_memory.GetRamMask();

    // Lockstep: record this MEM1 offset's pre-image so the shadow re-run's RAM
    // stores can be undone afterward (they must not leak into the canonical
    // native run). Null/no-op outside a shadow.
    if constexpr (flag == XCheckTLBFlag::Write)
    {
      if (StaticRecompLockstep::g_ram_write_journal)
        StaticRecompLockstep::g_ram_write_journal(em_address, size,
                                                  StaticRecompLockstep::g_ram_write_journal_user);
    }

    if (m_ppc_state.m_enable_dcache && !wi)
      m_ppc_state.dCache.Write(m_memory, em_address, &swapped_data, size, HID0(m_ppc_state).DLOCK);

    if (!m_ppc_state.m_enable_dcache || wi || flag != XCheckTLBFlag::Write)
      std::memcpy(&m_memory.GetRAM()[em_address], &swapped_data, size);

    return;
  }

  if (m_memory.GetEXRAM() && (em_address >> 28) == 0x1 &&
      (em_address & 0x0FFFFFFF) < m_memory.GetExRamSizeReal())
  {
    em_address &= 0x0FFFFFFF;

    if (m_ppc_state.m_enable_dcache && !wi)
    {
      m_ppc_state.dCache.Write(m_memory, em_address + 0x10000000, &swapped_data, size,
                               HID0(m_ppc_state).DLOCK);
    }

    if (!m_ppc_state.m_enable_dcache || wi || flag != XCheckTLBFlag::Write)
      std::memcpy(&m_memory.GetEXRAM()[em_address], &swapped_data, size);

    return;
  }

  // In Fake-VMEM mode, we need to map the memory somewhere into
  // physical memory for BAT translation to work; we currently use
  // [0x7E000000, 0x80000000).
  if (m_memory.GetFakeVMEM() && ((em_address & 0xFE000000) == 0x7E000000))
  {
    // StaticRecomp lockstep: record this Fake-VMEM offset's pre-image so the
    // shadow re-run reads the block pre-image (correct RMW), not native's
    // committed value, and so the shadow's own stores can be undone afterward.
    // The guest VM window lives here, not MEM1, so it needs its own journal.
    // Null/no-op outside a shadow (module-less runs never set it).
    if constexpr (flag == XCheckTLBFlag::Write)
    {
      if (StaticRecompLockstep::g_vmem_write_journal)
        StaticRecompLockstep::g_vmem_write_journal(em_address & m_memory.GetFakeVMemMask(), size,
                                                   StaticRecompLockstep::g_vmem_write_journal_user);
    }
    std::memcpy(&m_memory.GetFakeVMEM()[em_address & m_memory.GetFakeVMemMask()], &swapped_data,
                size);
    return;
  }

  // Memory access error.
  // TODO: This interrupt is supposed to have associated cause and address registers.
  m_system.GetProcessorInterface().SetInterrupt(ProcessorInterface::INT_CAUSE_PI);

  PanicAlertFmt("Unable to resolve write address {:x} PC {:x}", em_address, m_ppc_state.pc);
  if (m_system.IsPauseOnPanicMode())
  {
    m_system.GetCPU().Break();
    m_ppc_state.Exceptions |= EXCEPTION_DSI | EXCEPTION_FAKE_MEMCHECK_HIT;
  }
}
// Explicit template instantiations for MMUDebug.cpp
template u8 MMU::ReadFromHardware<XCheckTLBFlag::NoException, u8, false>(u32);
template u16 MMU::ReadFromHardware<XCheckTLBFlag::NoException, u16, false>(u32);
template u32 MMU::ReadFromHardware<XCheckTLBFlag::NoException, u32, false>(u32);
template u64 MMU::ReadFromHardware<XCheckTLBFlag::NoException, u64, false>(u32);
template u8 MMU::ReadFromHardware<XCheckTLBFlag::NoException, u8, true>(u32);
template u16 MMU::ReadFromHardware<XCheckTLBFlag::NoException, u16, true>(u32);
template u32 MMU::ReadFromHardware<XCheckTLBFlag::NoException, u32, true>(u32);
template u64 MMU::ReadFromHardware<XCheckTLBFlag::NoException, u64, true>(u32);
template u32 MMU::ReadFromHardware<XCheckTLBFlag::OpcodeNoException, u32, false>(u32);
template u32 MMU::ReadFromHardware<XCheckTLBFlag::OpcodeNoException, u32, true>(u32);

template void MMU::WriteToHardware<XCheckTLBFlag::NoException, false>(u32, u32, u32);
template void MMU::WriteToHardware<XCheckTLBFlag::NoException, true>(u32, u32, u32);

template u8 MMU::ReadFromHardware<XCheckTLBFlag::Read, u8, false>(u32);
template u16 MMU::ReadFromHardware<XCheckTLBFlag::Read, u16, false>(u32);
template u32 MMU::ReadFromHardware<XCheckTLBFlag::Read, u32, false>(u32);
template u64 MMU::ReadFromHardware<XCheckTLBFlag::Read, u64, false>(u32);

template void MMU::WriteToHardware<XCheckTLBFlag::Write, false>(u32, u32, u32);
template void MMU::WriteToHardware<XCheckTLBFlag::Write, true>(u32, u32, u32);

template MMU::TranslateAddressResult MMU::TranslateAddress<XCheckTLBFlag::NoException>(u32 address);
template MMU::TranslateAddressResult MMU::TranslateAddress<XCheckTLBFlag::OpcodeNoException>(u32 address);
template MMU::TranslateAddressResult MMU::TranslateAddress<XCheckTLBFlag::Read>(u32 address);
template MMU::TranslateAddressResult MMU::TranslateAddress<XCheckTLBFlag::Write>(u32 address);
template MMU::TranslateAddressResult MMU::TranslateAddress<XCheckTLBFlag::Opcode>(u32 address);

template bool MMU::IsEffectiveRAMAddress<XCheckTLBFlag::NoException>(const u32 address);
template bool MMU::IsEffectiveRAMAddress<XCheckTLBFlag::OpcodeNoException>(const u32 address);



template <XCheckTLBFlag flag>
bool MMU::IsEffectiveRAMAddress(const u32 address)
{
  const auto translate_address = TranslateAddress<flag>(address);
  return translate_address.Success() && IsPhysicalRAMAddress(translate_address.address);
}
template <const XCheckTLBFlag flag>
MMU::TranslateAddressResult MMU::TranslatePageAddress(const EffectiveAddress address, bool* wi)
{
  const auto sr = UReg_SR{m_ppc_state.sr[address.SR]};
  const u32 VSID = sr.VSID;  // 24 bit

  // TLB cache
  // This catches 99%+ of lookups in practice, so the actual page table entry code below doesn't
  // benefit much from optimization.
  u32 translated_address = 0;
  const TLBLookupResult res =
      LookupTLBPageAddress(m_ppc_state, flag, address.Hex, VSID, &translated_address, wi);
  if (res == TLBLookupResult::Found)
  {
    return TranslateAddressResult{TranslateAddressResultEnum::PAGE_TABLE_TRANSLATED,
                                  translated_address};
  }

  if (sr.T != 0)
    return TranslateAddressResult{TranslateAddressResultEnum::DIRECT_STORE_SEGMENT, 0};

  // TODO: Handle KS/KP segment register flags.

  // No-execute segment register flag.
  if ((flag == XCheckTLBFlag::Opcode || flag == XCheckTLBFlag::OpcodeNoException) && sr.N != 0)
  {
    return TranslateAddressResult{TranslateAddressResultEnum::PAGE_FAULT, 0};
  }

  const u32 offset = address.offset;          // 12 bit
  const u32 page_index = address.page_index;  // 16 bit
  const u32 api = address.API;                //  6 bit (part of page_index)

  // hash function no 1 "xor" .360
  u32 hash = (VSID ^ page_index);

  UPTE_Lo pte1;
  pte1.VSID = VSID;
  pte1.API = api;
  pte1.V = 1;

  for (int hash_func = 0; hash_func < 2; hash_func++)
  {
    // hash function no 2 "not" .360
    if (hash_func == 1)
    {
      hash = ~hash;
      pte1.H = 1;
    }

    u32 pteg_addr = ((hash << 6) & m_ppc_state.pagetable_mask) | m_ppc_state.pagetable_base;

    for (int i = 0; i < 8; i++, pteg_addr += 8)
    {
      constexpr XCheckTLBFlag pte_read_flag =
          IsNoExceptionFlag(flag) ? XCheckTLBFlag::NoException : XCheckTLBFlag::Read;
      const u32 pteg = ReadFromHardware<pte_read_flag, u32, true>(pteg_addr);

      if (pte1.Hex == pteg)
      {
        UPTE_Hi pte2(ReadFromHardware<pte_read_flag, u32, true>(pteg_addr + 4));
        const UPTE_Hi old_pte2 = pte2;

        // set the access bits
        switch (flag)
        {
        case XCheckTLBFlag::NoException:
        case XCheckTLBFlag::OpcodeNoException:
          break;
        case XCheckTLBFlag::Read:
          pte2.R = 1;
          break;
        case XCheckTLBFlag::Write:
          pte2.R = 1;
          pte2.C = 1;
          break;
        case XCheckTLBFlag::Opcode:
          pte2.R = 1;
          break;
        }

        if (!IsNoExceptionFlag(flag) && pte2.Hex != old_pte2.Hex)
        {
          m_memory.Write_U32(pte2.Hex, pteg_addr + 4);

          const u32 page_logical_address = address.Hex & ~HW_PAGE_MASK;
          const auto it = m_page_mappings.find(page_logical_address);
          if (it != m_page_mappings.end())
          {
            const u32 priority = (pteg_addr % 64 / 8) | (pte1.H << 3);
            if (it->second.Hex == PageMapping(pte2.RPN, true, priority).Hex)
            {
              const u32 swapped_pte1 = Common::swap32(reinterpret_cast<u8*>(&pte1));
              std::memcpy(m_page_table.data() + pteg_addr - m_ppc_state.pagetable_base,
                          &swapped_pte1, sizeof(swapped_pte1));

              const u32 swapped_pte2 = Common::swap32(reinterpret_cast<u8*>(&pte2));
              std::memcpy(m_page_table.data() + pteg_addr + 4 - m_ppc_state.pagetable_base,
                          &swapped_pte2, sizeof(swapped_pte2));

              const u32 page_translated_address = pte2.RPN << 12;
              m_memory.AddPageTableMapping(page_logical_address, page_translated_address, pte2.C);
            }
          }
        }

        // We already updated the TLB entry if this was caused by a C bit.
        if (res != TLBLookupResult::UpdateC)
          UpdateTLBEntry(m_ppc_state, flag, pte2, address.Hex, VSID);

        *wi = (pte2.WIMG & 0b1100) != 0;

        return TranslateAddressResult{TranslateAddressResultEnum::PAGE_TABLE_TRANSLATED,
                                      (pte2.RPN << 12) | offset};
      }
    }
  }
  return TranslateAddressResult{TranslateAddressResultEnum::PAGE_FAULT, 0};
}
// Translate effective address using BAT or PAT.  Returns 0 if the address cannot be translated.
// Through the hardware looks up BAT and TLB in parallel, BAT is used first if available.
// So we first check if there is a matching BAT entry, else we look for the TLB in
// TranslatePageAddress().
template <const XCheckTLBFlag flag>
MMU::TranslateAddressResult MMU::TranslateAddress(u32 address)
{
  bool wi = false;

  if (TranslateBatAddress(IsOpcodeFlag(flag) ? m_ibat_table : m_dbat_table, &address, &wi))
    return TranslateAddressResult{TranslateAddressResultEnum::BAT_TRANSLATED, address, wi};

  return TranslatePageAddress<flag>(EffectiveAddress{address}, &wi);
}

}  // namespace PowerPC
