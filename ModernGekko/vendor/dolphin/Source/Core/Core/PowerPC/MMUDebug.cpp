// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/MMUBAT.h"

#include <algorithm>
#include <concepts>
#include <optional>
#include <string>

#include "Common/Assert.h"
#include "Common/Logging/Log.h"
#include "Common/StringUtil.h"
#include "Core/Core.h"
#include "Core/HW/CPU.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/MMIO.h"
#include "Core/HW/ProcessorInterface.h"
#include "Core/PowerPC/GDBStub.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/PowerPC/StaticRecomp/StaticRecompLockstep.h"
#include "Core/System.h"
#include "VideoCommon/EFBInterface.h"

namespace PowerPC
{

// Declared extern or defined in MMU.cpp
u32 EFB_Read(const u32 addr);
void EFB_Write(u32 data, u32 addr);

void MMU::Memcheck(u32 address, u64 var, bool write, size_t size)
{
  if (!m_power_pc.GetMemChecks().HasAny())
    return;

  TMemCheck* mc = m_power_pc.GetMemChecks().GetMemCheck(address, size);
  if (mc == nullptr)
    return;

  if (m_system.GetCPU().IsStepping())
  {
    // Disable when stepping so that resume works.
    return;
  }

  mc->num_hits++;

  const bool pause = mc->Action(m_system, var, address, write, size, m_ppc_state.pc);
  if (!pause)
    return;

  m_system.GetCPU().Break();

  if (GDBStub::IsActive())
    GDBStub::TakeControl();

  // Fake a DSI so that all the code that tests for it in order to skip
  // the rest of the instruction will apply.  (This means that
  // watchpoints will stop the emulator before the offending load/store,
  // not after like GDB does, but that's better anyway.  Just need to
  // make sure resuming after that works.)
  // It doesn't matter if ReadFromHardware triggers its own DSI because
  // we'll take it after resuming.
  m_ppc_state.Exceptions |= EXCEPTION_DSI | EXCEPTION_FAKE_MEMCHECK_HIT;
}

template <std::unsigned_integral T>
std::optional<ReadResult<T>> MMU::HostTryRead(const Core::CPUThreadGuard& guard, const u32 address,
                                              RequestedAddressSpace space)
{
  if (!HostIsRAMAddress(guard, address, space))
    return std::nullopt;

  auto& mmu = guard.GetSystem().GetMMU();
  switch (space)
  {
  case RequestedAddressSpace::Effective:
  {
    T value = mmu.ReadFromHardware<XCheckTLBFlag::NoException, T>(address);
    return ReadResult<T>(!!mmu.m_ppc_state.msr.DR, std::move(value));
  }
  case RequestedAddressSpace::Physical:
  {
    T value = mmu.ReadFromHardware<XCheckTLBFlag::NoException, T, true>(address);
    return ReadResult<T>(false, std::move(value));
  }
  case RequestedAddressSpace::Virtual:
  {
    if (!mmu.m_ppc_state.msr.DR)
      return std::nullopt;
    T value = mmu.ReadFromHardware<XCheckTLBFlag::NoException, T>(address);
    return ReadResult<T>(true, std::move(value));
  }
  }

  ASSERT(false);
  return std::nullopt;
}
template std::optional<ReadResult<u8>> MMU::HostTryRead<u8>(const Core::CPUThreadGuard& guard,
                                                            const u32 address,
                                                            RequestedAddressSpace space);
template std::optional<ReadResult<u16>> MMU::HostTryRead<u16>(const Core::CPUThreadGuard& guard,
                                                              const u32 address,
                                                              RequestedAddressSpace space);
template std::optional<ReadResult<u32>> MMU::HostTryRead<u32>(const Core::CPUThreadGuard& guard,
                                                              const u32 address,
                                                              RequestedAddressSpace space);
template std::optional<ReadResult<u64>> MMU::HostTryRead<u64>(const Core::CPUThreadGuard& guard,
                                                              const u32 address,
                                                              RequestedAddressSpace space);

template <std::unsigned_integral T>
T MMU::HostRead(const Core::CPUThreadGuard& guard, const u32 address)
{
  auto& mmu = guard.GetSystem().GetMMU();
  return mmu.ReadFromHardware<XCheckTLBFlag::NoException, T>(address);
}
template u8 MMU::HostRead<u8>(const Core::CPUThreadGuard& guard, const u32 address);
template u16 MMU::HostRead<u16>(const Core::CPUThreadGuard& guard, const u32 address);
template u32 MMU::HostRead<u32>(const Core::CPUThreadGuard& guard, const u32 address);
template u64 MMU::HostRead<u64>(const Core::CPUThreadGuard& guard, const u32 address);

u32 MMU::HostRead_Instruction(const Core::CPUThreadGuard& guard, const u32 address)
{
  return guard.GetSystem().GetMMU().ReadFromHardware<XCheckTLBFlag::OpcodeNoException, u32>(
      address);
}

std::optional<ReadResult<u32>> MMU::HostTryReadInstruction(const Core::CPUThreadGuard& guard,
                                                           const u32 address,
                                                           RequestedAddressSpace space)
{
  if (!HostIsInstructionRAMAddress(guard, address, space))
    return std::nullopt;

  auto& mmu = guard.GetSystem().GetMMU();
  switch (space)
  {
  case RequestedAddressSpace::Effective:
  {
    const u32 value = mmu.ReadFromHardware<XCheckTLBFlag::OpcodeNoException, u32>(address);
    return ReadResult<u32>(!!mmu.m_ppc_state.msr.IR, value);
  }
  case RequestedAddressSpace::Physical:
  {
    const u32 value = mmu.ReadFromHardware<XCheckTLBFlag::OpcodeNoException, u32, true>(address);
    return ReadResult<u32>(false, value);
  }
  case RequestedAddressSpace::Virtual:
  {
    if (!mmu.m_ppc_state.msr.IR)
      return std::nullopt;
    const u32 value = mmu.ReadFromHardware<XCheckTLBFlag::OpcodeNoException, u32>(address);
    return ReadResult<u32>(true, value);
  }
  }

  ASSERT(false);
  return std::nullopt;
}

template <std::unsigned_integral T>
void MMU::HostWrite(const Core::CPUThreadGuard& guard, const Common::MakeAtLeastU32<T> var,
                    const u32 address)
{
  auto& mmu = guard.GetSystem().GetMMU();
  mmu.WriteToHardware<XCheckTLBFlag::NoException>(address, var, sizeof(T));
}
template void MMU::HostWrite<u8>(const Core::CPUThreadGuard& guard, const u32 var,
                                 const u32 address);
template void MMU::HostWrite<u16>(const Core::CPUThreadGuard& guard, const u32 var,
                                  const u32 address);
template void MMU::HostWrite<u32>(const Core::CPUThreadGuard& guard, const u32 var,
                                  const u32 address);
template <>
void MMU::HostWrite<u64>(const Core::CPUThreadGuard& guard, const u64 var, const u32 address)
{
  auto& mmu = guard.GetSystem().GetMMU();
  mmu.WriteToHardware<XCheckTLBFlag::NoException>(address, static_cast<u32>(var >> 32), 4);
  mmu.WriteToHardware<XCheckTLBFlag::NoException>(address + sizeof(u32), static_cast<u32>(var), 4);
}

template <std::unsigned_integral T>
std::optional<WriteResult> MMU::HostTryWrite(const Core::CPUThreadGuard& guard,
                                             const Common::MakeAtLeastU32<T> var, const u32 address,
                                             RequestedAddressSpace space)
{
  constexpr auto size = sizeof(T);

  if (!HostIsRAMAddress(guard, address, space))
    return std::nullopt;

  auto& mmu = guard.GetSystem().GetMMU();
  switch (space)
  {
  case RequestedAddressSpace::Effective:
    mmu.WriteToHardware<XCheckTLBFlag::NoException>(address, var, size);
    return WriteResult(!!mmu.m_ppc_state.msr.DR);
  case RequestedAddressSpace::Physical:
    mmu.WriteToHardware<XCheckTLBFlag::NoException, true>(address, var, size);
    return WriteResult(false);
  case RequestedAddressSpace::Virtual:
    if (!mmu.m_ppc_state.msr.DR)
      return std::nullopt;
    mmu.WriteToHardware<XCheckTLBFlag::NoException>(address, var, size);
    return WriteResult(true);
  }

  ASSERT(false);
  return std::nullopt;
}
template std::optional<WriteResult> MMU::HostTryWrite<u8>(const Core::CPUThreadGuard& guard,
                                                          const u32 var, const u32 address,
                                                          RequestedAddressSpace space);
template std::optional<WriteResult> MMU::HostTryWrite<u16>(const Core::CPUThreadGuard& guard,
                                                           const u32 var, const u32 address,
                                                           RequestedAddressSpace space);
template std::optional<WriteResult> MMU::HostTryWrite<u32>(const Core::CPUThreadGuard& guard,
                                                           const u32 var, const u32 address,
                                                           RequestedAddressSpace space);
template <>
std::optional<WriteResult> MMU::HostTryWrite<u64>(const Core::CPUThreadGuard& guard, const u64 var,
                                                  const u32 address, RequestedAddressSpace space)
{
  const auto result = HostTryWrite<u32>(guard, static_cast<u32>(var >> 32), address, space);
  if (!result)
    return result;

  return HostTryWrite<u32>(guard, static_cast<u32>(var), address + 4, space);
}

std::string MMU::HostGetString(const Core::CPUThreadGuard& guard, u32 address, size_t size)
{
  std::string s;
  do
  {
    if (!HostIsRAMAddress(guard, address))
      break;
    u8 res = HostRead<u8>(guard, address);
    if (!res)
      break;
    s += static_cast<char>(res);
    ++address;
  } while (size == 0 || s.length() < size);
  return s;
}

std::u16string MMU::HostGetU16String(const Core::CPUThreadGuard& guard, u32 address, size_t size)
{
  std::u16string s;
  do
  {
    if (!HostIsRAMAddress(guard, address) || !HostIsRAMAddress(guard, address + 1))
      break;
    const u16 res = HostRead<u16>(guard, address);
    if (!res)
      break;
    s += static_cast<char16_t>(res);
    address += 2;
  } while (size == 0 || s.length() < size);
  return s;
}

std::optional<ReadResult<std::string>> MMU::HostTryReadString(const Core::CPUThreadGuard& guard,
                                                              u32 address, size_t size,
                                                              RequestedAddressSpace space)
{
  auto c = HostTryRead<u8>(guard, address, space);
  if (!c)
    return std::nullopt;
  if (c->value == 0)
    return ReadResult<std::string>(c->translated, "");

  std::string s;
  s += static_cast<char>(c->value);
  while (size == 0 || s.length() < size)
  {
    ++address;
    const auto res = HostTryRead<u8>(guard, address, space);
    if (!res || res->value == 0)
      break;
    s += static_cast<char>(res->value);
  }
  return ReadResult<std::string>(c->translated, std::move(s));
}

bool MMU::HostIsRAMAddress(const Core::CPUThreadGuard& guard, u32 address,
                           RequestedAddressSpace space)
{
  auto& mmu = guard.GetSystem().GetMMU();
  switch (space)
  {
  case RequestedAddressSpace::Effective:
    return mmu.m_ppc_state.msr.DR ? mmu.IsEffectiveRAMAddress<XCheckTLBFlag::NoException>(address) :
                                    mmu.IsPhysicalRAMAddress(address);
  case RequestedAddressSpace::Physical:
    return mmu.IsPhysicalRAMAddress(address);
  case RequestedAddressSpace::Virtual:
    if (!mmu.m_ppc_state.msr.DR)
      return false;
    return mmu.IsEffectiveRAMAddress<XCheckTLBFlag::NoException>(address);
  }

  ASSERT(false);
  return false;
}

bool MMU::HostIsInstructionRAMAddress(const Core::CPUThreadGuard& guard, u32 address,
                                      RequestedAddressSpace space)
{
  // Instructions are always 32bit aligned.
  if (address & 3)
    return false;

  auto& mmu = guard.GetSystem().GetMMU();
  switch (space)
  {
  case RequestedAddressSpace::Effective:
    return mmu.m_ppc_state.msr.IR ?
               mmu.IsEffectiveRAMAddress<XCheckTLBFlag::OpcodeNoException>(address) :
               mmu.IsPhysicalRAMAddress(address);
  case RequestedAddressSpace::Physical:
    return mmu.IsPhysicalRAMAddress(address);
  case RequestedAddressSpace::Virtual:
    if (!mmu.m_ppc_state.msr.IR)
      return false;
    return mmu.IsEffectiveRAMAddress<XCheckTLBFlag::OpcodeNoException>(address);
  }

  ASSERT(false);
  return false;
}

void MMU::DMA_LCToMemory(const u32 mem_address, const u32 cache_address, const u32 num_blocks)
{
  if ((mem_address & 0x0F000000) == 0x08000000)
  {
    for (u32 i = 0; i < 32 * num_blocks; i += 4)
    {
      const u32 data = Common::swap32(m_memory.GetL1Cache() + ((cache_address + i) & 0x3FFFF));
      EFB_Write(data, mem_address + i);
    }
    return;
  }

  if ((mem_address & 0x0F000000) == 0x0C000000)
  {
    for (u32 i = 0; i < 32 * num_blocks; i += 4)
    {
      const u32 data = Common::swap32(m_memory.GetL1Cache() + ((cache_address + i) & 0x3FFFF));
      m_memory.GetMMIOMapping()->Write(m_system, mem_address + i, data);
    }
    return;
  }

  const u8* src = m_memory.GetL1Cache() + (cache_address & 0x3FFFF);
  m_memory.CopyToEmu(mem_address, src, 32 * num_blocks);
}

void MMU::DMA_MemoryToLC(const u32 cache_address, const u32 mem_address, const u32 num_blocks)
{
  if ((mem_address & 0x0F000000) == 0x08000000)
  {
    for (u32 i = 0; i < 32 * num_blocks; i += 4)
    {
      const u32 data = Common::swap32(EFB_Read(mem_address + i));
      std::memcpy(m_memory.GetL1Cache() + ((cache_address + i) & 0x3FFFF), &data, sizeof(u32));
    }
    return;
  }

  if ((mem_address & 0x0F000000) == 0x0C000000)
  {
    for (u32 i = 0; i < 32 * num_blocks; i += 4)
    {
      const u32 data =
          Common::swap32(m_memory.GetMMIOMapping()->Read<u32>(m_system, mem_address + i));
      std::memcpy(m_memory.GetL1Cache() + ((cache_address + i) & 0x3FFFF), &data, sizeof(u32));
    }
    return;
  }

  u8* dst = m_memory.GetL1Cache() + (cache_address & 0x3FFFF);
  m_memory.CopyFromEmu(dst, mem_address, 32 * num_blocks);
}

}  // namespace PowerPC
