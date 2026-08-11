// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/Jit64/Jit.h"

#include <bit>

#include "Common/CPUDetect.h"
#include "Common/CommonTypes.h"
#include "Core/Config/MainSettings.h"
#include "Core/PowerPC/Jit64/RegCache/JitRegCache.h"
#include "Core/PowerPC/Jit64Common/Jit64PowerPCState.h"
#include "Core/PowerPC/PowerPC.h"

using namespace Gen;

void Jit64::rlwinmx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int s = inst.RS;

  const bool left_shift = inst.SH && inst.MB == 0 && inst.ME == 31 - inst.SH;
  const bool right_shift = inst.SH && inst.ME == 31 && inst.MB == 32 - inst.SH;
  const bool field_extract = inst.SH && inst.ME == 31 && inst.MB > 32 - inst.SH;
  const u32 mask = MakeRotationMask(inst.MB, inst.ME);
  const u32 prerotate_mask = std::rotr(mask, inst.SH);
  const bool simple_mask = mask == 0xff || mask == 0xffff;
  const bool simple_prerotate_mask = prerotate_mask == 0xff || prerotate_mask == 0xffff;
  bool needs_test = true;
  bool needs_sext = true;
  int mask_size = inst.ME - inst.MB + 1;

  if (simple_mask && !(inst.SH & (mask_size - 1)) && !gpr.IsBound(s) && !gpr.IsImm(s))
  {
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Rs);
    OpArg mem_source = Rs.Location();
    if (inst.SH)
      mem_source.AddMemOffset((32 - inst.SH) >> 3);
    Rs.Unlock();

    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RegCache::Realize(Ra);
    MOVZX(32, mask_size, Ra, mem_source);

    needs_sext = false;
  }
  else
  {
    RCOpArg Rs = gpr.UseNoImm(s, RCMode::Read);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RegCache::Realize(Rs, Ra);

    if (a != s && left_shift && Rs.IsSimpleReg() && inst.SH <= 3)
    {
      LEA(32, Ra, MScaled(Rs.GetSimpleReg(), SCALE_1 << inst.SH, 0));
    }
    else if (simple_prerotate_mask && !left_shift)
    {
      MOVZX(32, prerotate_mask == 0xff ? 8 : 16, Ra, Rs);
      if (inst.SH)
        ROL(32, Ra, Imm8(inst.SH));
      needs_sext = (mask & 0x80000000) != 0;
    }
    else if (field_extract && cpu_info.bBMI1 && cpu_info.vendor == CPUVendor::AMD)
    {
      MOV(32, R(RSCRATCH), Imm32((mask_size << 8) | (32 - inst.SH)));
      BEXTR(32, Ra, Rs, RSCRATCH);
      needs_sext = false;
    }
    else if (left_shift)
    {
      if (a != s)
        MOV(32, Ra, Rs);

      SHL(32, Ra, Imm8(inst.SH));
    }
    else if (right_shift)
    {
      if (a != s)
        MOV(32, Ra, Rs);

      SHR(32, Ra, Imm8(inst.MB));
      needs_sext = false;
    }
    else
    {
      RotateLeft(32, Ra, Rs, inst.SH);

      if (!(inst.MB == 0 && inst.ME == 31))
      {
        if (inst.Rc && CheckMergedBranch(0))
          AND(32, Ra, Imm32(mask));
        else
          AndWithMask(Ra, mask);
        needs_sext = inst.MB == 0;
        needs_test = false;
      }
    }
  }

  if (inst.Rc)
    ComputeRC(a, needs_test, needs_sext);
}

void Jit64::rlwimix(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int s = inst.RS;

  const u32 mask = MakeRotationMask(inst.MB, inst.ME);
  const bool left_shift = mask == 0U - (1U << inst.SH);
  const bool right_shift = mask == (1U << inst.SH) - 1;
  bool needs_test = false;

  if (mask == 0 || (a == s && inst.SH == 0))
  {
    needs_test = true;
  }
  else if (mask == 0xFFFFFFFF)
  {
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RegCache::Realize(Rs, Ra);
    RotateLeft(32, Ra, Rs, inst.SH);
    needs_test = true;
  }
  else if (gpr.IsImm(s))
  {
    RCX64Reg Ra = gpr.Bind(a, RCMode::ReadWrite);
    RegCache::Realize(Ra);
    AndWithMask(Ra, ~mask);
    OR(32, Ra, Imm32(std::rotl(gpr.Imm32(s), inst.SH) & mask));
  }
  else if (gpr.IsImm(a))
  {
    const u32 maskA = gpr.Imm32(a) & ~mask;

    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RegCache::Realize(Rs, Ra);

    if (inst.SH == 0)
    {
      MOV(32, Ra, Rs);
      AndWithMask(Ra, mask);
    }
    else if (left_shift)
    {
      MOV(32, Ra, Rs);
      SHL(32, Ra, Imm8(inst.SH));
    }
    else if (right_shift)
    {
      MOV(32, Ra, Rs);
      SHR(32, Ra, Imm8(32 - inst.SH));
    }
    else
    {
      RotateLeft(32, Ra, Rs, inst.SH);
      AndWithMask(Ra, mask);
    }

    if (maskA)
      OR(32, Ra, Imm32(maskA));
    else
      needs_test = true;
  }
  else if (inst.SH)
  {
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RCX64Reg Ra = gpr.Bind(a, RCMode::ReadWrite);
    RegCache::Realize(Rs, Ra);

    if (left_shift)
    {
      MOV(32, R(RSCRATCH), Rs);
      SHL(32, R(RSCRATCH), Imm8(inst.SH));
    }
    else if (right_shift)
    {
      MOV(32, R(RSCRATCH), Rs);
      SHR(32, R(RSCRATCH), Imm8(32 - inst.SH));
    }
    else
    {
      RotateLeft(32, RSCRATCH, Rs, inst.SH);
    }

    if (mask == 0xFF || mask == 0xFFFF)
    {
      MOV(mask == 0xFF ? 8 : 16, Ra, R(RSCRATCH));
      needs_test = true;
    }
    else
    {
      if (!left_shift && !right_shift)
        AndWithMask(RSCRATCH, mask);
      AndWithMask(Ra, ~mask);
      OR(32, Ra, R(RSCRATCH));
    }
  }
  else
  {
    RCX64Reg Rs = gpr.Bind(s, RCMode::Read);
    RCX64Reg Ra = gpr.Bind(a, RCMode::ReadWrite);
    RegCache::Realize(Rs, Ra);

    if (mask == 0xFF || mask == 0xFFFF)
    {
      MOV(mask == 0xFF ? 8 : 16, Ra, Rs);
      needs_test = true;
    }
    else
    {
      XOR(32, Ra, Rs);
      AndWithMask(Ra, ~mask);
      XOR(32, Ra, Rs);
    }
  }
  if (inst.Rc)
    ComputeRC(a, needs_test);
}

void Jit64::rlwnmx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, s = inst.RS;

  const u32 mask = MakeRotationMask(inst.MB, inst.ME);
  if (gpr.IsImm(b))
  {
    u32 amount = gpr.Imm32(b) & 0x1f;
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Ra, Rs);

    RotateLeft(32, Ra, Rs, amount);

    if (inst.Rc && CheckMergedBranch(0))
      AND(32, Ra, Imm32(mask));
    else
      AndWithMask(Ra, mask);
  }
  else
  {
    RCX64Reg ecx = gpr.Scratch(ECX);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(ecx, Ra, Rb, Rs);

    MOV(32, ecx, Rb);
    if (a != s)
    {
      MOV(32, Ra, Rs);
    }
    ROL(32, Ra, ecx);
    if (inst.Rc && CheckMergedBranch(0))
      AND(32, Ra, Imm32(mask));
    else
      AndWithMask(Ra, mask);
  }
  if (inst.Rc)
    ComputeRC(a, false);
}

#if 0
void Jit64::srwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, s = inst.RS;

  if (gpr.IsImm(b))
  {
    u32 amount = gpr.Imm32(b) & 0x3f;
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Ra, Rs);

    if (amount >= 32)
    {
      gpr.SetImmediate32(a, 0);
    }
    else
    {
      if (a != s)
        MOV(32, Ra, Rs);
      if (amount)
        SHR(32, Ra, Imm8(amount));
    }
  }
  else
  {
    RCX64Reg ecx = gpr.Scratch(ECX);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(ecx, Ra, Rb, Rs);

    MOV(32, ecx, Rb);
    if (a != s)
      MOV(32, Ra, Rs);

    TEST(32, ecx, Imm8(0x20));
    FixupBranch j_zero = J_CC(CC_Z, Jump::Near);
    XOR(32, Ra, Ra);
    FixupBranch j_exit = J(Jump::Near);
    SetJumpTarget(j_zero);
    SHR(32, Ra, ecx);
    SetJumpTarget(j_exit);
  }
  if (inst.Rc)
    ComputeRC(a, false, false);
}

void Jit64::slwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, s = inst.RS;

  if (gpr.IsImm(b))
  {
    u32 amount = gpr.Imm32(b) & 0x3f;
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Ra, Rs);

    if (amount >= 32)
    {
      gpr.SetImmediate32(a, 0);
    }
    else
    {
      if (a != s)
        MOV(32, Ra, Rs);
      if (amount)
        SHL(32, Ra, Imm8(amount));
    }
  }
  else
  {
    RCX64Reg ecx = gpr.Scratch(ECX);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(ecx, Ra, Rb, Rs);

    MOV(32, ecx, Rb);
    if (a != s)
      MOV(32, Ra, Rs);

    TEST(32, ecx, Imm8(0x20));
    FixupBranch j_zero = J_CC(CC_Z, Jump::Near);
    XOR(32, Ra, Ra);
    FixupBranch j_exit = J(Jump::Near);
    SetJumpTarget(j_zero);
    SHL(32, Ra, ecx);
    SetJumpTarget(j_exit);
  }
  if (inst.Rc)
    ComputeRC(a, false, true);
}

void Jit64::srawx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, s = inst.RS;

  if (gpr.IsImm(b))
  {
    u32 amount = gpr.Imm32(b) & 0x3f;
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Ra, Rs);

    if (amount >= 32)
      amount = 31;

    if (a != s)
      MOV(32, Ra, Rs);

    if (amount == 0)
    {
      AND(32, PPCSTATE(xer_so_ov), Imm8(~XER_CA_MASK));
    }
    else
    {
      XOR(32, R(RSCRATCH), R(RSCRATCH));
      BT(32, Ra, Imm8(amount - 1));
      SETcc(CC_C, R(RSCRATCH));
      TEST(32, Ra, Ra);
      FixupBranch checkSO = J_CC(CC_NS);
      SHL(32, R(RSCRATCH), Imm8(XER_CA_SHIFT));
      OR(32, PPCSTATE(xer_so_ov), R(RSCRATCH));
      FixupBranch exit = J();
      SetJumpTarget(checkSO);
      SHL(32, R(RSCRATCH), Imm8(XER_CA_SHIFT));
      NOT(32, R(RSCRATCH));
      AND(32, PPCSTATE(xer_so_ov), R(RSCRATCH));
      SetJumpTarget(exit);

      SAR(32, Ra, Imm8(amount));
    }
  }
  else
  {
    RCX64Reg ecx = gpr.Scratch(ECX);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(ecx, Ra, Rb, Rs);

    MOV(32, ecx, Rb);
    if (a != s)
      MOV(32, Ra, Rs);

    TEST(32, ecx, Imm8(0x20));
    FixupBranch j_not_big = J_CC(CC_Z);
    MOV(32, ecx, Imm32(31));
    SetJumpTarget(j_not_big);

    XOR(32, R(RSCRATCH), R(RSCRATCH));
    MOV(32, R(RSCRATCH2), R(ecx));
    DEC(32, R(RSCRATCH2));
    BT(32, Ra, R(RSCRATCH2));
    SETcc(CC_C, R(RSCRATCH));
    TEST(32, Ra, Ra);
    FixupBranch checkSO = J_CC(CC_NS);
    SHL(32, R(RSCRATCH), Imm8(XER_CA_SHIFT));
    OR(32, PPCSTATE(xer_so_ov), R(RSCRATCH));
    FixupBranch exit = J();
    SetJumpTarget(checkSO);
    SHL(32, R(RSCRATCH), Imm8(XER_CA_SHIFT));
    NOT(32, R(RSCRATCH));
    AND(32, PPCSTATE(xer_so_ov), R(RSCRATCH));
    SetJumpTarget(exit);

    SAR(32, Ra, ecx);
  }
  if (inst.Rc)
    ComputeRC(a);
}

void Jit64::srawix(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, s = inst.RS;
  u32 amount = inst.SH;

  RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
  RCOpArg Rs = gpr.Use(s, RCMode::Read);
  RegCache::Realize(Ra, Rs);

  if (a != s)
    MOV(32, Ra, Rs);

  if (amount == 0)
  {
    AND(32, PPCSTATE(xer_so_ov), Imm8(~XER_CA_MASK));
  }
  else
  {
    XOR(32, R(RSCRATCH), R(RSCRATCH));
    BT(32, Ra, Imm8(amount - 1));
    SETcc(CC_C, R(RSCRATCH));
    TEST(32, Ra, Ra);
    FixupBranch checkSO = J_CC(CC_NS);
    SHL(32, R(RSCRATCH), Imm8(XER_CA_SHIFT));
    OR(32, PPCSTATE(xer_so_ov), R(RSCRATCH));
    FixupBranch exit = J();
    SetJumpTarget(checkSO);
    SHL(32, R(RSCRATCH), Imm8(XER_CA_SHIFT));
    NOT(32, R(RSCRATCH));
    AND(32, PPCSTATE(xer_so_ov), R(RSCRATCH));
    SetJumpTarget(exit);

    SAR(32, Ra, Imm8(amount));
  }
  if (inst.Rc)
    ComputeRC(a);
}
#endif
