// Copyright 2003 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

// Some of the code in this file was originally based on PearPC, though it has been modified since.
// We have been given permission by the author to re-license the code under GPLv2+.
/*
 * PearPC
 * ppc_mmu.cc
 *
 * Copyright (C) 2003, 2004 Sebastian Biallas (sb@biallas.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

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
MMU::MMU(Core::System& system, Memory::MemoryManager& memory, PowerPC::PowerPCManager& power_pc)
    : m_system(system), m_memory(memory), m_power_pc(power_pc), m_ppc_state(power_pc.GetPPCState())
{
}

MMU::~MMU() = default;

void MMU::Reset()
{
  ClearPageTable();
}

void MMU::DoState(PointerWrap& p, bool sr_changed)
{
  // Instead of storing m_page_table in savestates, we *could* refetch it from memory
  // here in DoState, but this could lead to us getting a more up-to-date set of page mappings
  // than we had when the savestate was created, which could be a problem for TAS determinism.
  if (p.IsReadMode())
  {
    if (!m_system.GetJitInterface().WantsPageTableMappings())
    {
      // Clear page table mappings if we have any.
      p.Do(m_page_table);
      ClearPageTable();
    }
    else if (sr_changed)
    {
      // Non-incremental update of page table mappings.
      p.Do(m_page_table);
      SRUpdated();
    }
    else
    {
      // Incremental update of page table mappings.
      p.Do(m_temp_page_table);
      PageTableUpdated(m_temp_page_table);
    }
  }
  else
  {
    p.Do(m_page_table);
  }
}

// Nasty but necessary. Super Mario Galaxy pointer relies on this stuff.
u32 EFB_Read(const u32 addr)
{
  u32 var = 0;
  // Convert address to coordinates. It's possible that this should be done
  // differently depending on color depth, especially regarding PeekColor.
  const u32 x = (addr & 0xfff) >> 2;
  const u32 y = (addr >> 12) & 0x3ff;

  if (addr & 0x00800000)
  {
    ERROR_LOG_FMT(MEMMAP, "Unimplemented Z+Color EFB read @ {:#010x}", addr);
  }
  else if (addr & 0x00400000)
  {
    var = g_efb_interface->PeekDepth(x, y);
    DEBUG_LOG_FMT(MEMMAP, "EFB Z Read @ {}, {}\t= {:#010x}", x, y, var);
  }
  else
  {
    var = g_efb_interface->PeekColor(x, y);
    DEBUG_LOG_FMT(MEMMAP, "EFB Color Read @ {}, {}\t= {:#010x}", x, y, var);
  }

  return var;
}

void EFB_Write(u32 data, u32 addr)
{
  const u32 x = (addr & 0xfff) >> 2;
  const u32 y = (addr >> 12) & 0x3ff;

  if (addr & 0x00800000)
  {
    // It's possible to do a z-tested write to EFB by writing a 64bit value to this address range.
    // Not much is known, but let's at least get some logging.
    ERROR_LOG_FMT(MEMMAP, "Unimplemented Z+Color EFB write. {:08x} @ {:#010x}", data, addr);
  }
  else if (addr & 0x00400000)
  {
    g_efb_interface->PokeDepth(x, y, data);
    DEBUG_LOG_FMT(MEMMAP, "EFB Z Write {:08x} @ {}, {}", data, x, y);
  }
  else
  {
    g_efb_interface->PokeColor(x, y, data);
    DEBUG_LOG_FMT(MEMMAP, "EFB Color Write {:08x} @ {}, {}", data, x, y);
  }
}

// =====================

// =================================
/* These functions are primarily called by the Interpreter functions and are routed to the correct
   location through ReadFromHardware and WriteToHardware */
// ----------------

u32 MMU::Read_Opcode(u32 address)
{
  TryReadInstResult result = TryReadInstruction(address);
  if (!result.valid)
  {
    GenerateISIException(address);
    return 0;
  }
  return result.hex;
}

TryReadInstResult MMU::TryReadInstruction(u32 address)
{
  bool from_bat = true;
  if (m_ppc_state.msr.IR)
  {
    auto tlb_addr = TranslateAddress<XCheckTLBFlag::Opcode>(address);
    if (!tlb_addr.Success())
    {
      return TryReadInstResult{false, false, 0, 0};
    }
    else
    {
      address = tlb_addr.address;
      from_bat = tlb_addr.result == TranslateAddressResultEnum::BAT_TRANSLATED;
    }
  }

  u32 hex;
  // TODO: Refactor this. This icache implementation is totally wrong if used with the fake vmem.
  if (m_memory.GetFakeVMEM() && ((address & 0xFE000000) == 0x7E000000))
  {
    hex = Common::swap32(&m_memory.GetFakeVMEM()[address & m_memory.GetFakeVMemMask()]);
  }
  else
  {
    hex = m_ppc_state.iCache.ReadInstruction(m_memory, m_ppc_state, address);
  }
  return TryReadInstResult{true, from_bat, hex, address};
}



template <std::unsigned_integral T>
T MMU::Read(const u32 address)
{
  T var = ReadFromHardware<XCheckTLBFlag::Read, T>(address);
  Memcheck(address, var, false, sizeof(T));
  return var;
}
template u8 MMU::Read<u8>(const u32 address);
template u16 MMU::Read<u16>(const u32 address);
template u32 MMU::Read<u32>(const u32 address);
template u64 MMU::Read<u64>(const u32 address);



template <std::unsigned_integral T>
void MMU::Write(const Common::MakeAtLeastU32<T> var, const u32 address)
{
  Memcheck(address, var, true, sizeof(T));
  WriteToHardware<XCheckTLBFlag::Write>(address, var, sizeof(T));
}
template void MMU::Write<u8>(const u32 var, const u32 address);
template void MMU::Write<u16>(const u32 var, const u32 address);
template void MMU::Write<u32>(const u32 var, const u32 address);
template <>
void MMU::Write<u64>(const u64 var, const u32 address)
{
  Memcheck(address, var, true, 8);
  WriteToHardware<XCheckTLBFlag::Write>(address, static_cast<u32>(var >> 32), 4);
  WriteToHardware<XCheckTLBFlag::Write>(address + sizeof(u32), static_cast<u32>(var), 4);
}

void MMU::Write_U16_Swap(const u32 var, const u32 address)
{
  Write<u16>((var & 0xFFFF0000) | Common::swap16(static_cast<u16>(var)), address);
}
void MMU::Write_U32_Swap(const u32 var, const u32 address)
{
  Write<u32>(Common::swap32(var), address);
}
void MMU::Write_U64_Swap(const u64 var, const u32 address)
{
  Write<u64>(Common::swap64(var), address);
}



bool MMU::IsOptimizableRAMAddress(const u32 address, const u32 access_size) const
{
  if (m_power_pc.GetMemChecks().HasAny())
    return false;

  if (!m_ppc_state.msr.DR)
    return false;

  if (m_ppc_state.m_enable_dcache)
    return false;

  // We store whether an access can be optimized to an unchecked access
  // in dbat_table.
  const u32 last_byte_address = address + (access_size >> 3) - 1;
  const u32 bat_result_1 = m_dbat_table[address >> BAT_INDEX_SHIFT];
  const u32 bat_result_2 = m_dbat_table[last_byte_address >> BAT_INDEX_SHIFT];
  return (bat_result_1 & bat_result_2 & BAT_PHYSICAL_BIT) != 0;
}

bool MMU::IsPhysicalRAMAddress(const u32 address) const
{
  const u32 segment = address >> 28;
  if (m_memory.GetRAM() && segment == 0x0 && (address & 0x0FFFFFFF) < m_memory.GetRamSizeReal())
  {
    return true;
  }
  if (m_memory.GetEXRAM() && segment == 0x1 && (address & 0x0FFFFFFF) < m_memory.GetExRamSizeReal())
  {
    return true;
  }
  if (m_memory.GetFakeVMEM() && (address & 0xFE000000) == 0x7E000000)
  {
    return true;
  }
  if (m_memory.GetL1Cache() && segment == 0xE && address < 0xE0000000 + m_memory.GetL1CacheSize())
  {
    return true;
  }
  return false;
}






void MMU::ClearDCacheLine(u32 address)
{
  DEBUG_ASSERT((address & 0x1F) == 0);
  if (m_ppc_state.msr.DR)
  {
    auto translated_address = TranslateAddress<XCheckTLBFlag::Write>(address);
    if (translated_address.result == TranslateAddressResultEnum::DIRECT_STORE_SEGMENT)
    {
      // dcbz to direct store segments is ignored. This is a little
      // unintuitive, but this is consistent with both console and the PEM.
      // Advance Game Port crashes if we don't emulate this correctly.
      return;
    }
    if (translated_address.result == TranslateAddressResultEnum::PAGE_FAULT)
    {
      // If translation fails, generate a DSI.
      GenerateDSIException(address, true);
      return;
    }
    address = translated_address.address;
  }

  // TODO: This isn't precisely correct for non-RAM regions, but the difference
  // is unlikely to matter.
  for (u32 i = 0; i < 32; i += 4)
    WriteToHardware<XCheckTLBFlag::Write, true>(address + i, 0, 4);
}

void MMU::StoreDCacheLine(u32 address)
{
  address &= ~0x1F;

  if (m_ppc_state.msr.DR)
  {
    auto translated_address = TranslateAddress<XCheckTLBFlag::Write>(address);
    if (translated_address.result == TranslateAddressResultEnum::DIRECT_STORE_SEGMENT)
    {
      return;
    }
    if (translated_address.result == TranslateAddressResultEnum::PAGE_FAULT)
    {
      // If translation fails, generate a DSI.
      GenerateDSIException(address, true);
      return;
    }
    address = translated_address.address;
  }

  if (m_ppc_state.m_enable_dcache)
    m_ppc_state.dCache.Store(m_memory, address);
}

void MMU::InvalidateDCacheLine(u32 address)
{
  address &= ~0x1F;

  if (m_ppc_state.msr.DR)
  {
    auto translated_address = TranslateAddress<XCheckTLBFlag::Write>(address);
    if (translated_address.result == TranslateAddressResultEnum::DIRECT_STORE_SEGMENT)
    {
      return;
    }
    if (translated_address.result == TranslateAddressResultEnum::PAGE_FAULT)
    {
      return;
    }
    address = translated_address.address;
  }

  if (m_ppc_state.m_enable_dcache)
    m_ppc_state.dCache.Invalidate(m_memory, address);
}

void MMU::FlushDCacheLine(u32 address)
{
  address &= ~0x1F;

  if (m_ppc_state.msr.DR)
  {
    auto translated_address = TranslateAddress<XCheckTLBFlag::Write>(address);
    if (translated_address.result == TranslateAddressResultEnum::DIRECT_STORE_SEGMENT)
    {
      return;
    }
    if (translated_address.result == TranslateAddressResultEnum::PAGE_FAULT)
    {
      // If translation fails, generate a DSI.
      GenerateDSIException(address, true);
      return;
    }
    address = translated_address.address;
  }

  if (m_ppc_state.m_enable_dcache)
    m_ppc_state.dCache.Flush(m_memory, address);
}

void MMU::TouchDCacheLine(u32 address, bool store)
{
  address &= ~0x1F;

  if (m_ppc_state.msr.DR)
  {
    auto translated_address = TranslateAddress<XCheckTLBFlag::Write>(address);
    if (translated_address.result == TranslateAddressResultEnum::DIRECT_STORE_SEGMENT)
    {
      return;
    }
    if (translated_address.result == TranslateAddressResultEnum::PAGE_FAULT)
    {
      // If translation fails, generate a DSI.
      GenerateDSIException(address, true);
      return;
    }
    address = translated_address.address;
  }

  if (m_ppc_state.m_enable_dcache)
    m_ppc_state.dCache.Touch(m_memory, address, store);
}

u32 MMU::IsOptimizableMMIOAccess(u32 address, u32 access_size) const
{
  if (m_power_pc.GetMemChecks().HasAny())
    return 0;

  if (!m_ppc_state.msr.DR)
    return 0;

  if (m_ppc_state.m_enable_dcache)
    return 0;

  // Translate address
  // If we also optimize for TLB mappings, we'd have to clear the
  // JitCache on each TLB invalidation.
  bool wi = false;
  if (!TranslateBatAddress(m_dbat_table, &address, &wi))
    return 0;

  // Check whether the address is an aligned address of an MMIO register.
  const bool aligned = (address & ((access_size >> 3) - 1)) == 0;
  if (!aligned || !MMIO::IsMMIOAddress(address, m_system.IsWii()))
    return 0;

  return address;
}

bool MMU::IsOptimizableGatherPipeWrite(u32 address) const
{
  if (m_power_pc.GetMemChecks().HasAny())
    return false;

  if (!m_ppc_state.msr.DR)
    return false;

  // Translate address, only check BAT mapping.
  // If we also optimize for TLB mappings, we'd have to clear the
  // JitCache on each TLB invalidation.
  bool wi = false;
  if (!TranslateBatAddress(m_dbat_table, &address, &wi))
    return false;

  // Check whether the translated address equals the address in WPAR.
  return address == GPFifo::GATHER_PIPE_PHYSICAL_ADDRESS;
}

TranslateResult MMU::JitCache_TranslateAddress(u32 address)
{
  if (!m_ppc_state.msr.IR)
    return TranslateResult{address};

  // TODO: We shouldn't use FLAG_OPCODE if the caller is the debugger.
  const auto tlb_addr = TranslateAddress<XCheckTLBFlag::Opcode>(address);
  if (!tlb_addr.Success())
    return TranslateResult{};

  const bool from_bat = tlb_addr.result == TranslateAddressResultEnum::BAT_TRANSLATED;
  return TranslateResult{from_bat, tlb_addr.address};
}

void MMU::GenerateDSIException(u32 effective_address, bool write)
{
  // DSI exceptions are only supported in MMU mode.
  if (!m_system.IsMMUMode())
  {
    if (write)
    {
      PanicAlertFmtT(
          "Invalid write to {0:#010x}, PC = {1:#010x}.\n\nThe game probably would have crashed on "
          "real hardware. Enable MMU in advanced settings to accurately emulate game crashes.",
          effective_address, m_ppc_state.pc);
    }
    else
    {
      PanicAlertFmtT(
          "Invalid read from {0:#010x}, PC = {1:#010x}.\n\nThe game probably would have crashed on "
          "real hardware. Enable MMU in advanced settings to accurately emulate game crashes.",
          effective_address, m_ppc_state.pc);
    }
    if (m_system.IsPauseOnPanicMode())
    {
      m_system.GetCPU().Break();
      m_ppc_state.Exceptions |= EXCEPTION_DSI | EXCEPTION_FAKE_MEMCHECK_HIT;
    }
    return;
  }

  constexpr u32 dsisr_page = 1U << 30;
  constexpr u32 dsisr_store = 1U << 25;

  if (write)
    m_ppc_state.spr[SPR_DSISR] = dsisr_page | dsisr_store;
  else
    m_ppc_state.spr[SPR_DSISR] = dsisr_page;

  m_ppc_state.spr[SPR_DAR] = effective_address;

  m_ppc_state.Exceptions |= EXCEPTION_DSI;
}

void MMU::GenerateISIException(u32 effective_address)
{
  // Address of instruction could not be translated
  m_ppc_state.npc = effective_address;

  m_ppc_state.Exceptions |= EXCEPTION_ISI;
  WARN_LOG_FMT(POWERPC, "ISI exception at {:#010x}", m_ppc_state.pc);
}

void MMU::SDRUpdated()
{
  const auto sdr = UReg_SDR1{m_ppc_state.spr[SPR_SDR]};
  const u32 htabmask = sdr.htabmask;

  if (!Common::IsValidLowMask(htabmask))
    WARN_LOG_FMT(POWERPC, "Invalid HTABMASK: 0b{:032b}", htabmask);

  // While 6xx_pem.pdf §7.6.1.1 mentions that the number of trailing zeros in HTABORG
  // must be equal to the number of trailing ones in the mask (i.e. HTABORG must be
  // properly aligned), this is actually not a hard requirement. Real hardware will just OR
  // the base address anyway. Ignoring SDR changes would lead to incorrect emulation.
  const u32 htaborg = sdr.htaborg;
  if ((htaborg & htabmask) != 0)
    WARN_LOG_FMT(POWERPC, "Invalid HTABORG: htaborg=0x{:08x} htabmask=0x{:08x}", htaborg, htabmask);

  m_ppc_state.pagetable_base = htaborg << 16;
  m_ppc_state.pagetable_mask = (htabmask << 16) | 0xffc0;

  PageTableUpdated();
}

void MMU::SRUpdated()
{
  // Our incremental handling of page table updates can't handle SR changing, so throw away all
  // existing mappings and then reparse the whole page table.
  m_memory.RemoveAllPageTableMappings();
  ReloadPageTable();
}

TLBLookupResult LookupTLBPageAddress(PowerPC::PowerPCState& ppc_state,
                                           const XCheckTLBFlag flag, const u32 vpa, const u32 vsid,
                                           u32* paddr, bool* wi)
{
  const u32 tag = vpa >> HW_PAGE_INDEX_SHIFT;
  const size_t tlb_index = IsOpcodeFlag(flag) ? PowerPC::INST_TLB_INDEX : PowerPC::DATA_TLB_INDEX;
  TLBEntry& tlbe = ppc_state.tlb[tlb_index][tag & HW_PAGE_INDEX_MASK];

  if (tlbe.tag[0] == tag && tlbe.vsid[0] == vsid)
  {
    UPTE_Hi pte2(tlbe.pte[0]);

    // Check if C bit requires updating
    if (flag == XCheckTLBFlag::Write)
    {
      if (pte2.C == 0)
      {
        pte2.C = 1;
        tlbe.pte[0] = pte2.Hex;
        return TLBLookupResult::UpdateC;
      }
    }

    if (!IsNoExceptionFlag(flag))
      tlbe.recent = 0;

    *paddr = tlbe.paddr[0] | (vpa & 0xfff);
    *wi = (pte2.WIMG & 0b1100) != 0;

    return TLBLookupResult::Found;
  }
  if (tlbe.tag[1] == tag && tlbe.vsid[1] == vsid)
  {
    UPTE_Hi pte2(tlbe.pte[1]);

    // Check if C bit requires updating
    if (flag == XCheckTLBFlag::Write)
    {
      if (pte2.C == 0)
      {
        pte2.C = 1;
        tlbe.pte[1] = pte2.Hex;
        return TLBLookupResult::UpdateC;
      }
    }

    if (!IsNoExceptionFlag(flag))
      tlbe.recent = 1;

    *paddr = tlbe.paddr[1] | (vpa & 0xfff);
    *wi = (pte2.WIMG & 0b1100) != 0;

    return TLBLookupResult::Found;
  }
  return TLBLookupResult::NotFound;
}

void UpdateTLBEntry(PowerPC::PowerPCState& ppc_state, const XCheckTLBFlag flag, UPTE_Hi pte2,
                    const u32 address, const u32 vsid)
{
  if (IsNoExceptionFlag(flag))
    return;

  const u32 tag = address >> HW_PAGE_INDEX_SHIFT;
  const size_t tlb_index = IsOpcodeFlag(flag) ? PowerPC::INST_TLB_INDEX : PowerPC::DATA_TLB_INDEX;
  TLBEntry& tlbe = ppc_state.tlb[tlb_index][tag & HW_PAGE_INDEX_MASK];
  const u32 index = tlbe.recent == 0 && tlbe.tag[0] != TLBEntry::INVALID_TAG;
  tlbe.recent = index;
  tlbe.paddr[index] = pte2.RPN << HW_PAGE_INDEX_SHIFT;
  tlbe.pte[index] = pte2.Hex;
  tlbe.tag[index] = tag;
  tlbe.vsid[index] = vsid;
}

void MMU::InvalidateTLBEntry(u32 address)
{
  const u32 entry_index = (address >> HW_PAGE_INDEX_SHIFT) & HW_PAGE_INDEX_MASK;

  m_ppc_state.tlb[PowerPC::DATA_TLB_INDEX][entry_index].Invalidate();
  m_ppc_state.tlb[PowerPC::INST_TLB_INDEX][entry_index].Invalidate();

  if (m_ppc_state.msr.DR)
    PageTableUpdated();
  else
    m_ppc_state.pagetable_update_pending = true;
}



// Page Address Translation



void MMU::DBATUpdated()
{
  m_dbat_table = {};
  UpdateBATs(m_dbat_table, SPR_DBAT0U);
  bool extended_bats = m_system.IsWii() && HID4(m_ppc_state).SBE;
  if (extended_bats)
    UpdateBATs(m_dbat_table, SPR_DBAT4U);
  if (m_memory.GetFakeVMEM())
  {
    // In Fake-MMU mode, insert some extra entries into the BAT tables.
    UpdateFakeMMUBat(m_dbat_table, 0x40000000);
    UpdateFakeMMUBat(m_dbat_table, 0x70000000);
  }

#ifndef _ARCH_32
  m_memory.UpdateDBATMappings(m_dbat_table);

  // Calling UpdateDBATMappings removes all fastmem page table mappings, so we have to recreate
  // them. We need to go through them anyway because there may have been a change in which DBATs
  // or memchecks are shadowing which page table mappings.
  if (!m_page_table.empty())
    ReloadPageTable();
#endif

  // IsOptimizable*Address and dcbz depends on the BAT mapping, so we need a flush here.
  m_system.GetJitInterface().ClearSafe();
}

void MMU::IBATUpdated()
{
  m_ibat_table = {};
  UpdateBATs(m_ibat_table, SPR_IBAT0U);
  bool extended_bats = m_system.IsWii() && HID4(m_ppc_state).SBE;
  if (extended_bats)
    UpdateBATs(m_ibat_table, SPR_IBAT4U);
  if (m_memory.GetFakeVMEM())
  {
    // In Fake-MMU mode, insert some extra entries into the BAT tables.
    UpdateFakeMMUBat(m_ibat_table, 0x40000000);
    UpdateFakeMMUBat(m_ibat_table, 0x70000000);
  }
  m_system.GetJitInterface().ClearSafe();
}


std::optional<u32> MMU::GetTranslatedAddress(u32 address)
{
  auto result = TranslateAddress<XCheckTLBFlag::NoException>(address);
  if (!result.Success())
  {
    return std::nullopt;
  }
  return std::optional<u32>(result.address);
}

void ClearDCacheLineFromJit(MMU& mmu, u32 address)
{
  mmu.ClearDCacheLine(address);
}
template <std::unsigned_integral T>
Common::MakeAtLeastU32<T> ReadFromJit(MMU& mmu, u32 address)
{
  return mmu.Read<T>(address);
}
template u32 ReadFromJit<u8>(MMU& mmu, u32 address);
template u32 ReadFromJit<u16>(MMU& mmu, u32 address);
template u32 ReadFromJit<u32>(MMU& mmu, u32 address);
template u64 ReadFromJit<u64>(MMU& mmu, u32 address);

template <std::unsigned_integral T>
void WriteFromJit(MMU& mmu, Common::MakeAtLeastU32<T> var, u32 address)
{
  mmu.Write<T>(var, address);
}
template void WriteFromJit<u8>(MMU& mmu, u32 var, u32 address);
template void WriteFromJit<u16>(MMU& mmu, u32 var, u32 address);
template void WriteFromJit<u32>(MMU& mmu, u32 var, u32 address);
template void WriteFromJit<u64>(MMU& mmu, u64 var, u32 address);
void WriteU16SwapFromJit(MMU& mmu, u32 var, u32 address)
{
  mmu.Write_U16_Swap(var, address);
}
void WriteU32SwapFromJit(MMU& mmu, u32 var, u32 address)
{
  mmu.Write_U32_Swap(var, address);
}
void WriteU64SwapFromJit(MMU& mmu, u64 var, u32 address)
{
  mmu.Write_U64_Swap(var, address);
}

}  // namespace PowerPC
