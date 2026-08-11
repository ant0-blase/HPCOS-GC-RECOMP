// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/JitArm64/Jit.h"

#include <bit>

#include "Common/Arm64Emitter.h"
#include "Common/ArmCommon.h"
#include "Common/CommonTypes.h"
#include "Common/MathUtil.h"

#include "Core/PowerPC/Interpreter/Interpreter.h"
#include "Core/PowerPC/JitArm64/JitArm64_RegCache.h"
#include "Core/PowerPC/JitCommon/DivUtils.h"
#include "Core/PowerPC/PPCTables.h"

using namespace Arm64Gen;
using namespace JitCommon;
void JitArm64::mulli(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA, d = inst.RD;

  if (MultiplyImmediate((u32)(s32)inst.SIMM_16, a, d, false))
  {
    // Code is generated inside MultiplyImmediate, nothing to be done here.
  }
  else
  {
    const bool allocate_reg = d == a;
    gpr.BindToRegister(d, allocate_reg);

    // Reuse d to hold the immediate if possible, allocate a register otherwise.
    auto WA = allocate_reg ? gpr.GetScopedReg() : Arm64GPRCache::ScopedARM64Reg(gpr.R(d));

    MOVI2R(WA, (u32)(s32)inst.SIMM_16);
    MUL(gpr.R(d), gpr.R(a), WA);
  }
}

void JitArm64::mullwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  int a = inst.RA, b = inst.RB, d = inst.RD;

  if ((gpr.IsImm(a) && MultiplyImmediate(gpr.GetImm(a), b, d, inst.Rc)) ||
      (gpr.IsImm(b) && MultiplyImmediate(gpr.GetImm(b), a, d, inst.Rc)))
  {
    // Code is generated inside MultiplyImmediate, nothing to be done here.
  }
  else
  {
    gpr.BindToRegister(d, d == a || d == b);
    MUL(gpr.R(d), gpr.R(a), gpr.R(b));
    if (inst.Rc)
      ComputeRC0(gpr.R(d));
  }
}

void JitArm64::mulhwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA, b = inst.RB, d = inst.RD;

  gpr.BindToRegister(d, d == a || d == b);
  SMULL(EncodeRegTo64(gpr.R(d)), gpr.R(a), gpr.R(b));
  LSR(EncodeRegTo64(gpr.R(d)), EncodeRegTo64(gpr.R(d)), 32);

  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}

void JitArm64::mulhwux(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA, b = inst.RB, d = inst.RD;

  gpr.BindToRegister(d, d == a || d == b);
  UMULL(EncodeRegTo64(gpr.R(d)), gpr.R(a), gpr.R(b));
  LSR(EncodeRegTo64(gpr.R(d)), EncodeRegTo64(gpr.R(d)), 32);

  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}
void JitArm64::divwux(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  int a = inst.RA, b = inst.RB, d = inst.RD;

  if (gpr.IsImm(b))
  {
    const u32 divisor = gpr.GetImm(b);

    if (divisor == 0)
    {
      gpr.SetImmediate(d, 0);
      if (inst.Rc)
        ComputeRC0(0);
    }
    else
    {
      const bool allocate_reg = d == a;
      gpr.BindToRegister(d, allocate_reg);

      ARM64Reg RD = gpr.R(d);
      ARM64Reg RA = gpr.R(a);

      if (MathUtil::IsPow2(divisor))
      {
        int shift = MathUtil::IntLog2(divisor);
        if (shift)
          LSR(RD, RA, shift);
        else if (d != a)
          MOV(RD, RA);
      }
      else
      {
        UnsignedMagic m = UnsignedDivisionConstants(divisor);

        auto WI = allocate_reg ? gpr.GetScopedReg() : Arm64GPRCache::ScopedARM64Reg(RD);
        ARM64Reg XD = EncodeRegTo64(RD);

        MOVI2R(WI, m.multiplier);

        if (m.fast)
        {
          UMULL(XD, RA, WI);
        }
        else
        {
          UMADDL(XD, RA, WI, EncodeRegTo64(WI));
        }

        LSR(XD, XD, 32 + m.shift);
      }

      if (inst.Rc)
        ComputeRC0(gpr.R(d));
    }
  }
  else
  {
    gpr.BindToRegister(d, d == a || d == b);

    // d = a / b
    UDIV(gpr.R(d), gpr.R(a), gpr.R(b));

    if (inst.Rc)
      ComputeRC0(gpr.R(d));
  }
}

void JitArm64::divwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  int a = inst.RA, b = inst.RB, d = inst.RD;

  if (gpr.IsImm(a, 0))
  {
    // Zero divided by anything is always zero
    gpr.SetImmediate(d, 0);
    if (inst.Rc)
      ComputeRC0(0);
  }
  else if (gpr.IsImm(a))
  {
    const u32 dividend = gpr.GetImm(a);

    gpr.BindToRegister(d, d == a || d == b);

    ARM64Reg RB = gpr.R(b);
    ARM64Reg RD = gpr.R(d);

    FixupBranch overflow1 = CBZ(RB);
    FixupBranch overflow2;
    if (dividend == 0x80000000)
    {
      CMN(RB, 1);
      overflow2 = B(CC_EQ);
    }
    SDIV(RD, gpr.R(a), RB);
    FixupBranch done = B();

    SetJumpTarget(overflow1);
    if (dividend == 0x80000000)
      SetJumpTarget(overflow2);

    MOVI2R(RD, dividend & 0x80000000 ? 0xFFFFFFFF : 0);

    SetJumpTarget(done);

    if (inst.Rc)
      ComputeRC0(RD);
  }
  else if (gpr.IsImm(b))
  {
    const s32 divisor = s32(gpr.GetImm(b));

    const bool allocate_reg = a == d;
    gpr.BindToRegister(d, allocate_reg);

    // Handle 0, 1, and -1 explicitly
    if (divisor == 0)
    {
      ASR(gpr.R(d), gpr.R(a), 31);
    }
    else if (divisor == 1)
    {
      if (d != a)
        MOV(gpr.R(d), gpr.R(a));
    }
    else if (divisor == -1)
    {
      // Rd = (Ra == 0x80000000) ? 0xFFFFFFFF : -Ra
      NEGS(gpr.R(d), gpr.R(a));
      CSINV(gpr.R(d), gpr.R(d), ARM64Reg::WZR, CCFlags::CC_VC);
    }
    else if (divisor == 2 || divisor == -2)
    {
      ARM64Reg RA = gpr.R(a);
      ARM64Reg RD = gpr.R(d);

      ADD(RD, RA, RA, ArithOption(RA, ShiftType::LSR, 31));

      if (divisor < 0)
        NEG(RD, RD, ArithOption(RD, ShiftType::ASR, 1));
      else
        ASR(RD, RD, 1);
    }
    else if (MathUtil::IsPow2(divisor) || MathUtil::IsPow2(-static_cast<s64>(divisor)))
    {
      const u32 abs_val = static_cast<u32>(std::abs(static_cast<s64>(divisor)));

      ARM64Reg RA = gpr.R(a);
      ARM64Reg RD = gpr.R(d);

      auto WA = allocate_reg ? gpr.GetScopedReg() : Arm64GPRCache::ScopedARM64Reg(RD);

      TST(RA, RA);
      ADDI2R(WA, RA, abs_val - 1, WA);
      CSEL(WA, RA, WA, CCFlags::CC_PL);

      if (divisor < 0)
        NEG(RD, WA, ArithOption(WA, ShiftType::ASR, MathUtil::IntLog2(abs_val)));
      else
        ASR(RD, WA, MathUtil::IntLog2(abs_val));
    }
    else
    {
      // Optimize signed 32-bit integer division by a constant
      SignedMagic m = SignedDivisionConstants(divisor);

      ARM64Reg RD = gpr.R(d);
      auto WA = gpr.GetScopedReg();
      auto WB = allocate_reg ? gpr.GetScopedReg() : Arm64GPRCache::ScopedARM64Reg(RD);

      ARM64Reg XD = EncodeRegTo64(RD);
      ARM64Reg XA = EncodeRegTo64(WA);
      ARM64Reg XB = EncodeRegTo64(WB);

      SXTW(XA, gpr.R(a));
      MOVI2R(XB, s64(m.multiplier));

      if (divisor > 0 && m.multiplier < 0)
      {
        MUL(XD, XA, XB);
        ADD(XD, XA, XD, ArithOption(XD, ShiftType::LSR, 32));
        LSR(WA, WA, 31);
        ADD(RD, WA, RD, ArithOption(RD, ShiftType::ASR, m.shift));
      }
      else if (divisor < 0 && m.multiplier > 0)
      {
        MNEG(XD, XA, XB);
        ADD(XA, XD, XA, ArithOption(XA, ShiftType::LSR, 32));
        LSR(RD, WA, 31);
        ADD(RD, RD, WA, ArithOption(WA, ShiftType::ASR, m.shift));
      }
      else if (m.multiplier > 0)
      {
        MUL(XD, XA, XB);
        ASR(XD, XD, 32 + m.shift);
        ADD(RD, RD, WA, ArithOption(WA, ShiftType::LSR, 31));
      }
      else
      {
        MUL(XD, XA, XB);
        LSR(XA, XD, 63);
        ASR(XD, XD, 32 + m.shift);
        ADD(RD, WA, RD);
      }
    }

    if (inst.Rc)
      ComputeRC0(gpr.R(d));
  }
  else
  {
    FlushCarry();

    gpr.BindToRegister(d, d == a || d == b);

    ARM64Reg RA = gpr.R(a);
    ARM64Reg RB = gpr.R(b);
    ARM64Reg RD = gpr.R(d);

    FixupBranch overflow1 = CBZ(RB);
    NEGS(ARM64Reg::WZR, RA);  // Is RA 0x80000000?
    CCMN(RB, 1, 0, CC_VS);    // Is RB -1?
    FixupBranch overflow2 = B(CC_EQ);
    SDIV(RD, RA, RB);
    FixupBranch done = B();

    SetJumpTarget(overflow1);
    SetJumpTarget(overflow2);

    ASR(RD, RA, 31);

    SetJumpTarget(done);

    if (inst.Rc)
      ComputeRC0(RD);
  }
}


