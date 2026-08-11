// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/Jit64/Jit.h"

#include <array>
#include <bit>
#include <limits>

#include "Common/Assert.h"
#include "Common/CPUDetect.h"
#include "Common/CommonTypes.h"
#include "Common/MathUtil.h"
#include "Common/SmallVector.h"
#include "Common/x64Emitter.h"

#include "Core/PowerPC/ConditionRegister.h"
#include "Core/PowerPC/Interpreter/ExceptionUtils.h"
#include "Core/PowerPC/Jit64/RegCache/JitRegCache.h"
#include "Core/PowerPC/Jit64Common/Jit64PowerPCState.h"
#include "Core/PowerPC/JitCommon/DivUtils.h"
#include "Core/PowerPC/PPCAnalyst.h"

using namespace Gen;
using namespace JitCommon;
void Jit64::MultiplyImmediate(u32 imm, int a, int d, bool overflow)
{
  RCOpArg Ra = gpr.UseNoImm(a, RCMode::Read);
  RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
  RegCache::Realize(Ra, Rd);

  if (imm == (u32)-1)
  {
    if (d != a)
      MOV(32, Rd, Ra);
    NEG(32, Rd);
    return;
  }

  // skip these if we need to check overflow flag
  if (!overflow)
  {
    // power of 2; just a shift
    if (MathUtil::IsPow2(imm))
    {
      u32 shift = MathUtil::IntLog2(imm);
      // use LEA if it saves an op
      if (d != a && shift <= 3 && shift >= 1 && Ra.IsSimpleReg())
      {
        LEA(32, Rd, MScaled(Ra.GetSimpleReg(), SCALE_1 << shift, 0));
      }
      else
      {
        if (d != a)
          MOV(32, Rd, Ra);
        if (shift)
          SHL(32, Rd, Imm8(shift));
      }
      return;
    }

    // We could handle factors of 2^N*3, 2^N*5, and 2^N*9 using lea+shl, but testing shows
    // it seems to be slower overall.
    static constexpr std::array<u8, 3> lea_scales{{3, 5, 9}};
    for (size_t i = 0; i < lea_scales.size(); i++)
    {
      if (imm == lea_scales[i] && Ra.IsSimpleReg())
      {
        LEA(32, Rd, MComplex(Ra.GetSimpleReg(), Ra.GetSimpleReg(), SCALE_2 << i, 0));
        return;
      }
    }
  }

  // if we didn't find any better options
  IMUL(32, Rd, Ra, Imm32(imm));
}

void Jit64::mulli(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, d = inst.RD;
  u32 imm = inst.SIMM_16;

  MultiplyImmediate(imm, a, d, false);
}

void Jit64::mullwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, d = inst.RD;

  if (gpr.IsImm(a) || gpr.IsImm(b))
  {
    u32 imm = gpr.IsImm(a) ? gpr.Imm32(a) : gpr.Imm32(b);
    int src = gpr.IsImm(a) ? b : a;
    MultiplyImmediate(imm, src, d, inst.OE);
    if (inst.OE)
      GenerateOverflow();
  }
  else
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Ra, Rb, Rd);

    if (d == a)
    {
      IMUL(32, Rd, Rb);
    }
    else if (d == b)
    {
      IMUL(32, Rd, Ra);
    }
    else
    {
      MOV(32, Rd, Rb);
      IMUL(32, Rd, Ra);
    }
    if (inst.OE)
      GenerateOverflow();
  }
  if (inst.Rc)
    ComputeRC(d);
}

void Jit64::mulhwXx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, d = inst.RD;
  bool sign = inst.SUBOP10 == 75;

  if (sign)
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCOpArg Rb = gpr.UseNoImm(b, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RCX64Reg eax = gpr.Scratch(EAX);
    RCX64Reg edx = gpr.Scratch(EDX);
    RegCache::Realize(Ra, Rb, Rd, eax, edx);

    MOV(32, eax, Ra);
    IMUL(32, Rb);
    MOV(32, Rd, edx);
  }
  else
  {
    // Not faster for signed because we'd need two movsx.
    // We need to bind everything to registers since the top 32 bits need to be zero.
    int src = d == b ? a : b;
    int other = src == b ? a : b;

    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RCX64Reg Rsrc = gpr.Bind(src, RCMode::Read);
    RCOpArg Rother = gpr.Use(other, RCMode::Read);
    RegCache::Realize(Rd, Rsrc, Rother);

    if (other != d)
      MOV(32, Rd, Rother);
    IMUL(64, Rd, Rsrc);
    SHR(64, Rd, Imm8(32));
  }
  if (inst.Rc)
    ComputeRC(d);
}

void Jit64::divwux(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, d = inst.RD;

  if (gpr.IsImm(b))
  {
    u32 divisor = gpr.Imm32(b);
    if (divisor == 0)
    {
      gpr.SetImmediate32(d, 0);
      if (inst.OE)
        GenerateConstantOverflow(true);
    }
    else
    {
      if (MathUtil::IsPow2(divisor))
      {
        u32 shift = MathUtil::IntLog2(divisor);

        RCOpArg Ra = gpr.Use(a, RCMode::Read);
        RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
        RegCache::Realize(Ra, Rd);

        if (d != a)
          MOV(32, Rd, Ra);
        if (shift)
          SHR(32, Rd, Imm8(shift));
      }
      else
      {
        UnsignedMagic m = UnsignedDivisionConstants(divisor);

        // Test for failure in round-up method
        if (!m.fast)
        {
          // If failed, use slower round-down method
          RCOpArg Ra = gpr.Use(a, RCMode::Read);
          RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
          RegCache::Realize(Ra, Rd);

          MOV(32, R(RSCRATCH), Imm32(m.multiplier));
          if (d != a)
            MOV(32, Rd, Ra);
          IMUL(64, Rd, R(RSCRATCH));
          ADD(64, Rd, R(RSCRATCH));
          SHR(64, Rd, Imm8(m.shift + 32));
        }
        else
        {
          // If success, use faster round-up method
          RCX64Reg Ra = gpr.Bind(a, RCMode::Read);
          RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
          RegCache::Realize(Ra, Rd);

          // Three-operand IMUL sign extends the immediate to 64 bits, so we may only
          // use it when the magic number has its most significant bit set to 0
          if ((m.multiplier & 0x80000000) == 0)
          {
            IMUL(64, Rd, Ra, Imm32(m.multiplier));
          }
          else if (d == a)
          {
            MOV(32, R(RSCRATCH), Imm32(m.multiplier));
            IMUL(64, Rd, R(RSCRATCH));
          }
          else
          {
            MOV(32, Rd, Imm32(m.multiplier));
            IMUL(64, Rd, Ra);
          }
          SHR(64, Rd, Imm8(m.shift + 32));
        }
      }
      if (inst.OE)
        GenerateConstantOverflow(false);
    }
  }
  else
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCX64Reg Rb = gpr.Bind(b, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    // no register choice (do we need to do this?)
    RCX64Reg eax = gpr.Scratch(EAX);
    RCX64Reg edx = gpr.Scratch(EDX);
    RegCache::Realize(Ra, Rb, Rd, eax, edx);

    MOV(32, eax, Ra);
    XOR(32, edx, edx);
    TEST(32, Rb, Rb);
    FixupBranch not_div_by_zero = J_CC(CC_NZ);
    MOV(32, Rd, edx);
    if (inst.OE)
    {
      GenerateConstantOverflow(true);
    }
    FixupBranch end = J();
    SetJumpTarget(not_div_by_zero);
    DIV(32, Rb);
    MOV(32, Rd, eax);
    if (inst.OE)
    {
      GenerateConstantOverflow(false);
    }
    SetJumpTarget(end);
  }
  if (inst.Rc)
    ComputeRC(d);
}

void Jit64::divwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, d = inst.RD;

  if (gpr.IsImm(a))
  {
    // Constant dividend
    const u32 dividend = gpr.Imm32(a);

    if (dividend == 0)
    {
      if (inst.OE)
      {
        RCOpArg Rb = gpr.Use(b, RCMode::Read);
        RegCache::Realize(Rb);

        CMP_or_TEST(32, Rb, Imm32(0));
        GenerateOverflow(CC_NZ);
      }

      // Zero divided by anything is always zero
      gpr.SetImmediate32(d, 0);
    }
    else
    {
      RCX64Reg Rb = gpr.Bind(b, RCMode::Read);
      RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
      // no register choice
      RCX64Reg eax = gpr.Scratch(EAX);
      RCX64Reg edx = gpr.Scratch(EDX);
      RegCache::Realize(Rb, Rd, eax, edx);

      // Check for divisor == 0
      TEST(32, Rb, Rb);

      FixupBranch done;

      if (d == b && (dividend & 0x80000000) == 0 && !inst.OE)
      {
        // Divisor is 0, skip to the end
        // No need to explicitly set destination to 0 due to overlapping registers
        done = J_CC(CC_Z);
        // Otherwise, proceed to normal path
      }
      else
      {
        FixupBranch normal_path;
        if (dividend == 0x80000000)
        {
          // Divisor is 0, proceed to overflow case
          const FixupBranch overflow = J_CC(CC_Z);
          // Otherwise, check for divisor == -1
          CMP(32, Rb, Imm32(0xFFFFFFFF));
          normal_path = J_CC(CC_NE);

          SetJumpTarget(overflow);
        }
        else
        {
          // Divisor is not 0, take normal path
          normal_path = J_CC(CC_NZ);
          // Otherwise, proceed to overflow case
        }

        // Set Rd to all ones or all zeroes
        if (dividend & 0x80000000)
          MOV(32, Rd, Imm32(0xFFFFFFFF));
        else if (d != b)
          XOR(32, Rd, Rd);

        if (inst.OE)
          GenerateConstantOverflow(true);

        done = J();

        SetJumpTarget(normal_path);
      }

      MOV(32, eax, Imm32(dividend));
      CDQ();
      IDIV(32, Rb);
      MOV(32, Rd, eax);

      if (inst.OE)
        GenerateConstantOverflow(false);

      SetJumpTarget(done);
    }
  }
  else if (gpr.IsImm(b))
  {
    // Constant divisor
    const s32 divisor = gpr.SImm32(b);
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Ra, Rd);

    // Handle 0, 1, and -1 explicitly
    if (divisor == 0)
    {
      if (d != a)
        MOV(32, Rd, Ra);
      SAR(32, Rd, Imm8(31));
      if (inst.OE)
        GenerateConstantOverflow(true);
    }
    else if (divisor == 1)
    {
      if (d != a)
        MOV(32, Rd, Ra);
      if (inst.OE)
        GenerateConstantOverflow(false);
    }
    else if (divisor == -1)
    {
      if (d != a)
        MOV(32, Rd, Ra);

      NEG(32, Rd);
      const FixupBranch normal = J_CC(CC_NO);

      MOV(32, Rd, Imm32(0xFFFFFFFF));
      if (inst.OE)
        GenerateConstantOverflow(true);
      const FixupBranch done = J();

      SetJumpTarget(normal);
      if (inst.OE)
        GenerateConstantOverflow(false);

      SetJumpTarget(done);
    }
    else if (divisor == 2 || divisor == -2)
    {
      X64Reg tmp = RSCRATCH;
      X64Reg sign = tmp;

      if (!Ra.IsSimpleReg())
      {
        // Load dividend from memory
        MOV(32, R(tmp), Ra);
        MOV(32, Rd, R(tmp));
      }
      else if (d == a)
      {
        // Make a copy of the dividend
        MOV(32, R(tmp), Ra);
      }
      else
      {
        // Copy dividend directly into destination
        MOV(32, Rd, Ra);
        tmp = Ra.GetSimpleReg();
        sign = Rd;
      }

      SHR(32, R(sign), Imm8(31));
      ADD(32, Rd, R(tmp));
      SAR(32, Rd, Imm8(1));

      if (divisor < 0)
        NEG(32, Rd);

      if (inst.OE)
        GenerateConstantOverflow(false);
    }
    else if (MathUtil::IsPow2(divisor) || MathUtil::IsPow2(-static_cast<s64>(divisor)))
    {
      const u32 abs_val = static_cast<u32>(std::abs(static_cast<s64>(divisor)));

      X64Reg dividend, sum, src;
      CCFlags cond = CC_NS;

      if (!Ra.IsSimpleReg())
      {
        dividend = RSCRATCH;
        sum = Rd;
        src = RSCRATCH;

        // Load dividend from memory
        MOV(32, R(dividend), Ra);
      }
      else if (d == a)
      {
        // Rd holds the dividend, while RSCRATCH holds the sum
        // This is the reverse of the other cases
        dividend = Rd;
        sum = RSCRATCH;
        src = RSCRATCH;
        // Negate condition to compensate for the swapped values
        cond = CC_S;
      }
      else
      {
        // Use dividend from register directly
        dividend = Ra.GetSimpleReg();
        sum = Rd;
        src = dividend;
      }

      TEST(32, R(dividend), R(dividend));
      LEA(32, sum, MDisp(dividend, abs_val - 1));
      CMOVcc(32, Rd, R(src), cond);
      SAR(32, Rd, Imm8(MathUtil::IntLog2(abs_val)));

      if (divisor < 0)
        NEG(32, Rd);

      if (inst.OE)
        GenerateConstantOverflow(false);
    }
    else
    {
      // Optimize signed 32-bit integer division by a constant
      SignedMagic m = SignedDivisionConstants(divisor);

      MOVSX(64, 32, RSCRATCH, Ra);

      if (divisor > 0 && m.multiplier < 0)
      {
        IMUL(64, Rd, R(RSCRATCH), Imm32(m.multiplier));
        SHR(64, Rd, Imm8(32));
        ADD(32, Rd, R(RSCRATCH));
        SHR(32, R(RSCRATCH), Imm8(31));
        SAR(32, Rd, Imm8(m.shift));
      }
      else if (divisor < 0 && m.multiplier > 0)
      {
        IMUL(64, Rd, R(RSCRATCH), Imm32(m.multiplier));
        SHR(64, R(RSCRATCH), Imm8(32));
        SUB(32, R(RSCRATCH), Rd);
        MOV(32, Rd, R(RSCRATCH));
        SHR(32, Rd, Imm8(31));
        SAR(32, R(RSCRATCH), Imm8(m.shift));
      }
      else if (m.multiplier > 0)
      {
        IMUL(64, Rd, R(RSCRATCH), Imm32(m.multiplier));
        SHR(32, R(RSCRATCH), Imm8(31));
        SAR(64, R(Rd), Imm8(32 + m.shift));
      }
      else
      {
        IMUL(64, RSCRATCH, R(RSCRATCH), Imm32(m.multiplier));
        MOV(64, Rd, R(RSCRATCH));
        SHR(64, R(RSCRATCH), Imm8(63));
        SAR(64, R(Rd), Imm8(32 + m.shift));
      }

      ADD(32, Rd, R(RSCRATCH));

      if (inst.OE)
        GenerateConstantOverflow(false);
    }
  }
  else
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCX64Reg Rb = gpr.Bind(b, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    // no register choice
    RCX64Reg eax = gpr.Scratch(EAX);
    RCX64Reg edx = gpr.Scratch(EDX);
    RegCache::Realize(Ra, Rb, Rd, eax, edx);

    MOV(32, eax, Ra);
    TEST(32, Rb, Rb);
    const FixupBranch overflow = J_CC(CC_E);

    CMP(32, eax, Imm32(0x80000000));
    const FixupBranch normal_path1 = J_CC(CC_NE);

    CMP(32, Rb, Imm32(0xFFFFFFFF));
    const FixupBranch normal_path2 = J_CC(CC_NE);

    SetJumpTarget(overflow);
    SAR(32, eax, Imm8(31));
    if (inst.OE)
    {
      GenerateConstantOverflow(true);
    }
    const FixupBranch done = J();

    SetJumpTarget(normal_path1);
    SetJumpTarget(normal_path2);

    CDQ();
    IDIV(32, Rb);
    if (inst.OE)
    {
      GenerateConstantOverflow(false);
    }

    SetJumpTarget(done);
    MOV(32, Rd, eax);
  }
  if (inst.Rc)
    ComputeRC(d);
}

void Jit64::twX(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  s32 a = inst.RA;

  if (inst.OPCD == 3)  // twi
  {
    RCOpArg Ra = gpr.UseNoImm(a, RCMode::Read);
    RegCache::Realize(Ra);
    CMP(32, Ra, Imm32((s32)(s16)inst.SIMM_16));
  }
  else  // tw
  {
    s32 b = inst.RB;
    RCX64Reg Ra = gpr.Bind(a, RCMode::Read);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RegCache::Realize(Ra, Rb);
    CMP(32, Ra, Rb);
  }

  constexpr std::array<CCFlags, 5> conditions{{CC_A, CC_B, CC_E, CC_G, CC_L}};
  Common::SmallVector<FixupBranch, conditions.size()> fixups;

  for (size_t i = 0; i < conditions.size(); i++)
  {
    if (inst.TO & (1 << i))
    {
      FixupBranch f = J_CC(conditions[i], Jump::Near);
      fixups.push_back(f);
    }
  }

  if (!fixups.empty())
  {
    SwitchToFarCode();

    RCForkGuard gpr_guard = gpr.Fork();
    RCForkGuard fpr_guard = fpr.Fork();

    for (const FixupBranch& fixup : fixups)
    {
      SetJumpTarget(fixup);
    }
    LOCK();
    OR(32, PPCSTATE(Exceptions), Imm32(EXCEPTION_PROGRAM));
    MOV(32, PPCSTATE_SRR1, Imm32(static_cast<u32>(ProgramExceptionCause::Trap)));

    gpr.Flush();
    fpr.Flush();

    MOV(32, PPCSTATE(pc), Imm32(js.compilerPC));
    WriteExceptionExit();

    SwitchToNearCode();
  }

  if (!analyzer.HasOption(PPCAnalyst::PPCAnalyzer::OPTION_CONDITIONAL_CONTINUE))
  {
    gpr.Flush();
    fpr.Flush();
    WriteExit(js.compilerPC + 4);
  }
}
