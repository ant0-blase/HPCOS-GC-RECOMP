// Copyright 2014 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/JitArm64/Jit.h"

#include <bit>

#include "Common/Arm64Emitter.h"
#include "Common/BitSet.h"
#include "Common/CommonTypes.h"
#include "Common/ScopeGuard.h"

#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/Debugger/BranchWatch.h"
#include "Core/HW/DSP.h"
#include "Core/HW/MMIO.h"
#include "Core/HW/Memmap.h"
#include "Core/PowerPC/JitArm64/JitArm64_RegCache.h"
#include "Core/PowerPC/JitArm64/Jit_Util.h"
#include "Core/PowerPC/JitInterface.h"
#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/PPCTables.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/System.h"

using namespace Arm64Gen;

void JitArm64::SafeLoadToReg(u32 dest, s32 addr, s32 offsetReg, u32 flags, s32 offset, bool update)
{
  // We want to make sure to not get LR as a temp register
  gpr.Lock(ARM64Reg::W1, ARM64Reg::W30);
  if (jo.memcheck || !jo.fastmem)
    gpr.Lock(ARM64Reg::W0);

  gpr.BindToRegister(dest, dest == (u32)addr || dest == (u32)offsetReg, false);
  ARM64Reg dest_reg = gpr.R(dest);
  ARM64Reg up_reg = ARM64Reg::INVALID_REG;
  ARM64Reg off_reg = ARM64Reg::INVALID_REG;

  if (addr != -1 && !gpr.IsImm(addr))
    up_reg = gpr.R(addr);

  if (offsetReg != -1 && !gpr.IsImm(offsetReg))
    off_reg = gpr.R(offsetReg);

  ARM64Reg addr_reg = ARM64Reg::W1;
  u32 imm_addr = 0;
  bool is_immediate = false;

  if (offsetReg == -1)
  {
    if (addr != -1)
    {
      if (gpr.IsImm(addr))
      {
        is_immediate = true;
        imm_addr = gpr.GetImm(addr) + offset;
      }
      else
      {
        ADDI2R(addr_reg, up_reg, offset, addr_reg);
      }
    }
    else
    {
      is_immediate = true;
      imm_addr = offset;
    }
  }
  else
  {
    if (addr != -1)
    {
      if (gpr.IsImm(addr) && gpr.IsImm(offsetReg))
      {
        is_immediate = true;
        imm_addr = gpr.GetImm(addr) + gpr.GetImm(offsetReg);
      }
      else if (gpr.IsImm(addr) && !gpr.IsImm(offsetReg))
      {
        u32 reg_offset = gpr.GetImm(addr);
        ADDI2R(addr_reg, off_reg, reg_offset, addr_reg);
      }
      else if (!gpr.IsImm(addr) && gpr.IsImm(offsetReg))
      {
        u32 reg_offset = gpr.GetImm(offsetReg);
        ADDI2R(addr_reg, up_reg, reg_offset, addr_reg);
      }
      else
      {
        ADD(addr_reg, up_reg, off_reg);
      }
    }
    else
    {
      if (gpr.IsImm(offsetReg))
      {
        is_immediate = true;
        imm_addr = gpr.GetImm(offsetReg);
      }
      else
      {
        MOV(addr_reg, off_reg);
      }
    }
  }

  ARM64Reg XA = EncodeRegTo64(addr_reg);

  bool addr_reg_set = !is_immediate;
  const auto set_addr_reg_if_needed = [&] {
    if (!addr_reg_set)
      MOVI2R(XA, imm_addr);
  };

  const bool early_update = !jo.memcheck && dest != static_cast<u32>(addr);
  if (update && early_update)
  {
    gpr.BindToRegister(addr, false);
    set_addr_reg_if_needed();
    MOV(gpr.R(addr), addr_reg);
  }

  BitSet32 regs_in_use = gpr.GetCallerSavedUsed();
  BitSet32 fprs_in_use = fpr.GetCallerSavedUsed();
  if (!update || early_update)
    regs_in_use[DecodeReg(ARM64Reg::W1)] = false;
  if (jo.memcheck || !jo.fastmem)
    regs_in_use[DecodeReg(ARM64Reg::W0)] = false;
  if (!jo.memcheck)
    regs_in_use[DecodeReg(dest_reg)] = false;

  u32 access_size = BackPatchInfo::GetFlagSize(flags);
  u32 mmio_address = 0;
  if (is_immediate)
    mmio_address = m_mmu.IsOptimizableMMIOAccess(imm_addr, access_size);

  if (is_immediate && m_mmu.IsOptimizableRAMAddress(imm_addr, access_size))
  {
    set_addr_reg_if_needed();
    EmitBackpatchRoutine(flags, MemAccessMode::AlwaysFastAccess, dest_reg, XA, regs_in_use,
                         fprs_in_use);
  }
  else if (mmio_address)
  {
    regs_in_use[DecodeReg(ARM64Reg::W1)] = false;
    regs_in_use[DecodeReg(ARM64Reg::W30)] = false;
    regs_in_use[DecodeReg(dest_reg)] = false;
    MMIOLoadToReg(m_system, m_system.GetMemory().GetMMIOMapping(), this, &m_float_emit, regs_in_use,
                  fprs_in_use, dest_reg, mmio_address, flags);
    addr_reg_set = false;
  }
  else
  {
    set_addr_reg_if_needed();
    EmitBackpatchRoutine(flags, MemAccessMode::Auto, dest_reg, XA, regs_in_use, fprs_in_use);
  }

  gpr.BindToRegister(dest, false, true);
  ASSERT(dest_reg == gpr.R(dest));

  if (update && !early_update)
  {
    gpr.BindToRegister(addr, false);
    set_addr_reg_if_needed();
    MOV(gpr.R(addr), addr_reg);
  }

  gpr.Unlock(ARM64Reg::W1, ARM64Reg::W30);
  if (jo.memcheck || !jo.fastmem)
    gpr.Unlock(ARM64Reg::W0);
}

void JitArm64::SafeStoreFromReg(s32 dest, u32 value, s32 regOffset, u32 flags, s32 offset,
                                bool update)
{
  // We want to make sure to not get LR as a temp register
  gpr.Lock(ARM64Reg::W1, ARM64Reg::W2, ARM64Reg::W30);
  if (!jo.fastmem)
    gpr.Lock(ARM64Reg::W0);

  // Don't materialize zero.
  ARM64Reg RS = gpr.IsImm(value, 0) ? ARM64Reg::WZR : gpr.R(value);

  ARM64Reg reg_dest = ARM64Reg::INVALID_REG;
  ARM64Reg reg_off = ARM64Reg::INVALID_REG;

  if (regOffset != -1 && !gpr.IsImm(regOffset))
    reg_off = gpr.R(regOffset);
  if (dest != -1 && !gpr.IsImm(dest))
    reg_dest = gpr.R(dest);

  ARM64Reg addr_reg = ARM64Reg::W2;

  u32 imm_addr = 0;
  bool is_immediate = false;

  if (regOffset == -1)
  {
    if (dest != -1)
    {
      if (gpr.IsImm(dest))
      {
        is_immediate = true;
        imm_addr = gpr.GetImm(dest) + offset;
      }
      else
      {
        ADDI2R(addr_reg, reg_dest, offset, addr_reg);
      }
    }
    else
    {
      is_immediate = true;
      imm_addr = offset;
    }
  }
  else
  {
    if (dest != -1)
    {
      if (gpr.IsImm(dest) && gpr.IsImm(regOffset))
      {
        is_immediate = true;
        imm_addr = gpr.GetImm(dest) + gpr.GetImm(regOffset);
      }
      else if (gpr.IsImm(dest) && !gpr.IsImm(regOffset))
      {
        u32 reg_offset = gpr.GetImm(dest);
        ADDI2R(addr_reg, reg_off, reg_offset, addr_reg);
      }
      else if (!gpr.IsImm(dest) && gpr.IsImm(regOffset))
      {
        u32 reg_offset = gpr.GetImm(regOffset);
        ADDI2R(addr_reg, reg_dest, reg_offset, addr_reg);
      }
      else
      {
        ADD(addr_reg, reg_dest, reg_off);
      }
    }
    else
    {
      if (gpr.IsImm(regOffset))
      {
        is_immediate = true;
        imm_addr = gpr.GetImm(regOffset);
      }
      else
      {
        MOV(addr_reg, reg_off);
      }
    }
  }

  ARM64Reg XA = EncodeRegTo64(addr_reg);

  bool addr_reg_set = !is_immediate;
  const auto set_addr_reg_if_needed = [&] {
    if (!addr_reg_set)
      MOVI2R(XA, imm_addr);
  };

  const bool early_update = !jo.memcheck && value != static_cast<u32>(dest);
  if (update && early_update)
  {
    gpr.BindToRegister(dest, false);
    set_addr_reg_if_needed();
    MOV(gpr.R(dest), addr_reg);
  }

  BitSet32 regs_in_use = gpr.GetCallerSavedUsed();
  BitSet32 fprs_in_use = fpr.GetCallerSavedUsed();
  regs_in_use[DecodeReg(ARM64Reg::W1)] = false;
  if (!update || early_update)
    regs_in_use[DecodeReg(ARM64Reg::W2)] = false;
  if (!jo.fastmem)
    regs_in_use[DecodeReg(ARM64Reg::W0)] = false;

  u32 access_size = BackPatchInfo::GetFlagSize(flags);
  u32 mmio_address = 0;
  if (is_immediate)
    mmio_address = m_mmu.IsOptimizableMMIOAccess(imm_addr, access_size);

  if (is_immediate && jo.optimizeGatherPipe && m_mmu.IsOptimizableGatherPipeWrite(imm_addr))
  {
    int accessSize;
    if (flags & BackPatchInfo::FLAG_SIZE_32)
      accessSize = 32;
    else if (flags & BackPatchInfo::FLAG_SIZE_16)
      accessSize = 16;
    else
      accessSize = 8;

    LDR(IndexType::Unsigned, ARM64Reg::X2, PPC_REG, PPCSTATE_OFF(gather_pipe_ptr));

    ARM64Reg temp = ARM64Reg::W1;
    temp = ByteswapBeforeStore(this, &m_float_emit, temp, RS, flags, true);

    if (accessSize == 32)
      STR(IndexType::Post, temp, ARM64Reg::X2, 4);
    else if (accessSize == 16)
      STRH(IndexType::Post, temp, ARM64Reg::X2, 2);
    else
      STRB(IndexType::Post, temp, ARM64Reg::X2, 1);

    STR(IndexType::Unsigned, ARM64Reg::X2, PPC_REG, PPCSTATE_OFF(gather_pipe_ptr));

    js.fifoBytesSinceCheck += accessSize >> 3;
  }
  else if (is_immediate && m_mmu.IsOptimizableRAMAddress(imm_addr, access_size))
  {
    set_addr_reg_if_needed();
    EmitBackpatchRoutine(flags, MemAccessMode::AlwaysFastAccess, RS, XA, regs_in_use, fprs_in_use);
  }
  else if (mmio_address)
  {
    regs_in_use[DecodeReg(ARM64Reg::W1)] = false;
    regs_in_use[DecodeReg(ARM64Reg::W2)] = false;
    regs_in_use[DecodeReg(ARM64Reg::W30)] = false;
    regs_in_use[DecodeReg(RS)] = false;
    MMIOWriteRegToAddr(m_system, m_system.GetMemory().GetMMIOMapping(), this, &m_float_emit,
                       regs_in_use, fprs_in_use, RS, mmio_address, flags);
    addr_reg_set = false;
  }
  else
  {
    set_addr_reg_if_needed();
    EmitBackpatchRoutine(flags, MemAccessMode::Auto, RS, XA, regs_in_use, fprs_in_use);
  }

  if (update && !early_update)
  {
    gpr.BindToRegister(dest, false);
    set_addr_reg_if_needed();
    MOV(gpr.R(dest), addr_reg);
  }

  gpr.Unlock(ARM64Reg::W1, ARM64Reg::W2, ARM64Reg::W30);
  if (!jo.fastmem)
    gpr.Unlock(ARM64Reg::W0);
}

FixupBranch JitArm64::BATAddressLookup(ARM64Reg addr_out, ARM64Reg addr_in, ARM64Reg tmp,
                                       const void* bat_table)
{
  tmp = EncodeRegTo64(tmp);

  MOVP2R(tmp, bat_table);
  LSR(addr_out, addr_in, PowerPC::BAT_INDEX_SHIFT);
  LDR(addr_out, tmp, ArithOption(addr_out, true));
  FixupBranch pass = TBNZ(addr_out, MathUtil::IntLog2(PowerPC::BAT_MAPPED_BIT));
  FixupBranch fail = B();
  SetJumpTarget(pass);
  return fail;
}

FixupBranch JitArm64::CheckIfSafeAddress(Arm64Gen::ARM64Reg addr, Arm64Gen::ARM64Reg tmp1,
                                         Arm64Gen::ARM64Reg tmp2)
{
  tmp2 = EncodeRegTo64(tmp2);

  MOVP2R(tmp2, m_mmu.GetDBATTable().data());
  LSR(tmp1, addr, PowerPC::BAT_INDEX_SHIFT);
  LDR(tmp1, tmp2, ArithOption(tmp1, true));
  FixupBranch pass = TBNZ(tmp1, MathUtil::IntLog2(PowerPC::BAT_PHYSICAL_BIT));
  FixupBranch fail = B();
  SetJumpTarget(pass);
  return fail;
}

void JitArm64::lXX(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITLoadStoreOff);

  u32 a = inst.RA, b = inst.RB, d = inst.RD;
  s32 offset = inst.SIMM_16;
  s32 offsetReg = -1;
  u32 flags = BackPatchInfo::FLAG_LOAD;
  bool update = false;

  switch (inst.OPCD)
  {
  case 31:
    offsetReg = b;
    switch (inst.SUBOP10)
    {
    case 55:  // lwzux
      update = true;
      [[fallthrough]];
    case 23:  // lwzx
      flags |= BackPatchInfo::FLAG_SIZE_32;
      break;
    case 119:  // lbzux
      update = true;
      [[fallthrough]];
    case 87:  // lbzx
      flags |= BackPatchInfo::FLAG_SIZE_8;
      break;
    case 311:  // lhzux
      update = true;
      [[fallthrough]];
    case 279:  // lhzx
      flags |= BackPatchInfo::FLAG_SIZE_16;
      break;
    case 375:  // lhaux
      update = true;
      [[fallthrough]];
    case 343:  // lhax
      flags |= BackPatchInfo::FLAG_EXTEND | BackPatchInfo::FLAG_SIZE_16;
      break;
    case 534:  // lwbrx
      flags |= BackPatchInfo::FLAG_REVERSE | BackPatchInfo::FLAG_SIZE_32;
      break;
    case 790:  // lhbrx
      flags |= BackPatchInfo::FLAG_REVERSE | BackPatchInfo::FLAG_SIZE_16;
      break;
    }
    break;
  case 33:  // lwzu
    update = true;
    [[fallthrough]];
  case 32:  // lwz
    flags |= BackPatchInfo::FLAG_SIZE_32;
    break;
  case 35:  // lbzu
    update = true;
    [[fallthrough]];
  case 34:  // lbz
    flags |= BackPatchInfo::FLAG_SIZE_8;
    break;
  case 41:  // lhzu
    update = true;
    [[fallthrough]];
  case 40:  // lhz
    flags |= BackPatchInfo::FLAG_SIZE_16;
    break;
  case 43:  // lhau
    update = true;
    [[fallthrough]];
  case 42:  // lha
    flags |= BackPatchInfo::FLAG_EXTEND | BackPatchInfo::FLAG_SIZE_16;
    break;
  }

  SafeLoadToReg(d, update ? a : (a ? a : -1), offsetReg, flags, offset, update);
}

void JitArm64::stX(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITLoadStoreOff);

  u32 a = inst.RA, b = inst.RB, s = inst.RS;
  s32 offset = inst.SIMM_16;
  s32 regOffset = -1;
  u32 flags = BackPatchInfo::FLAG_STORE;
  bool update = false;
  switch (inst.OPCD)
  {
  case 31:
    regOffset = b;
    switch (inst.SUBOP10)
    {
    case 183:  // stwux
      update = true;
      [[fallthrough]];
    case 151:  // stwx
      flags |= BackPatchInfo::FLAG_SIZE_32;
      break;
    case 247:  // stbux
      update = true;
      [[fallthrough]];
    case 215:  // stbx
      flags |= BackPatchInfo::FLAG_SIZE_8;
      break;
    case 439:  // sthux
      update = true;
      [[fallthrough]];
    case 407:  // sthx
      flags |= BackPatchInfo::FLAG_SIZE_16;
      break;
    case 662:  // stwbrx
      flags |= BackPatchInfo::FLAG_REVERSE | BackPatchInfo::FLAG_SIZE_32;
      break;
    case 918:  // sthbrx
      flags |= BackPatchInfo::FLAG_REVERSE | BackPatchInfo::FLAG_SIZE_16;
      break;
    }
    break;
  case 37:  // stwu
    update = true;
    [[fallthrough]];
  case 36:  // stw
    flags |= BackPatchInfo::FLAG_SIZE_32;
    break;
  case 39:  // stbu
    update = true;
    [[fallthrough]];
  case 38:  // stb
    flags |= BackPatchInfo::FLAG_SIZE_8;
    break;
  case 45:  // sthu
    update = true;
    [[fallthrough]];
  case 44:  // sth
    flags |= BackPatchInfo::FLAG_SIZE_16;
    break;
  }

  SafeStoreFromReg(update ? a : (a ? a : -1), s, regOffset, flags, offset, update);
}

