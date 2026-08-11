// Copyright 2014 Dolphin Emulator Project
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

#define CARRY_IF_NEEDED_COND(carry, inst_without_carry, inst_with_carry, ...)                      \
  do                                                                                               \
  {                                                                                                \
    if ((carry) && js.op->wantsCA)                                                                 \
      inst_with_carry(__VA_ARGS__);                                                                \
    else                                                                                           \
      inst_without_carry(__VA_ARGS__);                                                             \
  } while (0)

#define CARRY_IF_NEEDED(inst_without_carry, inst_with_carry, ...)                                  \
  CARRY_IF_NEEDED_COND(true, inst_without_carry, inst_with_carry, __VA_ARGS__)

void JitArm64::ComputeRC0(ARM64Reg reg)
{
  gpr.BindCRToRegister(0, false);
  SXTW(gpr.CR(0), reg);
}

void JitArm64::ComputeRC0(u32 imm)
{
  gpr.BindCRToRegister(0, false);
  MOVI2R(gpr.CR(0), s64(s32(imm)));
}

void JitArm64::GenerateConstantOverflow(bool overflow)
{
  ARM64Reg WA = gpr.GetReg();

  if (overflow)
  {
    MOVI2R(WA, XER_OV_MASK | XER_SO_MASK);
    STRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_so_ov));
  }
  else
  {
    LDRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_so_ov));
    AND(WA, WA, LogicalImm(~XER_OV_MASK, GPRSize::B32));
    STRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_so_ov));
  }

  gpr.Unlock(WA);
}

void JitArm64::ComputeCarry(ARM64Reg reg)
{
  js.carryFlag = CarryFlag::InPPCState;

  if (!js.op->wantsCA)
    return;

  if (CanMergeNextInstructions(1) && js.op[1].wantsCAInFlags)
  {
    CMP(reg, 1);
    js.carryFlag = CarryFlag::InHostCarry;
  }
  else
  {
    STRB(IndexType::Unsigned, reg, PPC_REG, PPCSTATE_OFF(xer_ca));
  }
}

void JitArm64::ComputeCarry(bool carry)
{
  js.carryFlag = carry ? CarryFlag::ConstantTrue : CarryFlag::ConstantFalse;
}

void JitArm64::ComputeCarry()
{
  js.carryFlag = CarryFlag::InPPCState;

  if (!js.op->wantsCA)
    return;

  js.carryFlag = CarryFlag::InHostCarry;
  if (CanMergeNextInstructions(1) && js.op[1].opinfo->type == ::OpType::Integer)
    return;

  FlushCarry();
}

void JitArm64::LoadCarry()
{
  switch (js.carryFlag)
  {
  case CarryFlag::InPPCState:
  {
    auto WA = gpr.GetScopedReg();
    LDRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_ca));
    CMP(WA, 1);
    break;
  }
  case CarryFlag::InHostCarry:
  {
    break;
  }
  case CarryFlag::ConstantTrue:
  {
    CMP(ARM64Reg::WZR, ARM64Reg::WZR);
    break;
  }
  case CarryFlag::ConstantFalse:
  {
    CMN(ARM64Reg::WZR, ARM64Reg::WZR);
    break;
  }
  }
}

void JitArm64::FlushCarry()
{
  switch (js.carryFlag)
  {
  case CarryFlag::InPPCState:
  {
    break;
  }
  case CarryFlag::InHostCarry:
  {
    auto WA = gpr.GetScopedReg();
    CSET(WA, CC_CS);
    STRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_ca));
    break;
  }
  case CarryFlag::ConstantTrue:
  {
    auto WA = gpr.GetScopedReg();
    MOVI2R(WA, 1);
    STRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_ca));
    break;
  }
  case CarryFlag::ConstantFalse:
  {
    STRB(IndexType::Unsigned, ARM64Reg::WZR, PPC_REG, PPCSTATE_OFF(xer_ca));
    break;
  }
  }

  js.carryFlag = CarryFlag::InPPCState;
}



void JitArm64::addix(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  u32 d = inst.RD, a = inst.RA;

  u32 imm = (u32)(s32)inst.SIMM_16;
  if (inst.OPCD == 15)
  {
    imm <<= 16;
  }

  if (a)
  {
    gpr.BindToRegister(d, d == a);

    auto WA = gpr.GetScopedReg();
    ADDI2R(gpr.R(d), gpr.R(a), imm, WA);
  }
  else
  {
    // a == 0, implies zero register
    gpr.SetImmediate(d, imm);
  }
}



void JitArm64::addx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  int a = inst.RA, b = inst.RB, d = inst.RD;

  if (gpr.IsImm(a) || gpr.IsImm(b))
  {
    int imm_reg = gpr.IsImm(a) ? a : b;
    int in_reg = gpr.IsImm(a) ? b : a;
    int imm_value = gpr.GetImm(imm_reg);

    gpr.BindToRegister(d, d == in_reg);
    {
      auto WA = gpr.GetScopedReg();
      ADDI2R(gpr.R(d), gpr.R(in_reg), imm_value, WA);
    }
    if (inst.Rc)
      ComputeRC0(gpr.R(d));
  }
  else
  {
    gpr.BindToRegister(d, d == a || d == b);
    ADD(gpr.R(d), gpr.R(a), gpr.R(b));
    if (inst.Rc)
      ComputeRC0(gpr.R(d));
  }
}



void JitArm64::negx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int d = inst.RD;

  FALLBACK_IF(inst.OE);

  gpr.BindToRegister(d, d == a);
  SUB(gpr.R(d), ARM64Reg::WSP, gpr.R(a));
  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}

void JitArm64::cmp(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int crf = inst.CRFD;
  u32 a = inst.RA, b = inst.RB;

  gpr.BindCRToRegister(crf, false);
  ARM64Reg CR = gpr.CR(crf);

  if (gpr.IsImm(a) && gpr.IsImm(b))
  {
    s64 A = static_cast<s32>(gpr.GetImm(a));
    s64 B = static_cast<s32>(gpr.GetImm(b));
    MOVI2R(CR, A - B);
  }
  else if (gpr.IsImm(a) && !gpr.GetImm(a))
  {
    SXTW(CR, gpr.R(b));
    NEG(CR, CR);
  }
  else if (gpr.IsImm(a, 0xFFFFFFFF))
  {
    SXTW(CR, gpr.R(b));
    MVN(CR, CR);
  }
  else if (gpr.IsImm(b) && (gpr.GetImm(b) & 0xFFF) == gpr.GetImm(b))
  {
    SXTW(CR, gpr.R(a));
    if (const u32 imm = gpr.GetImm(b); imm != 0)
      SUB(CR, CR, imm);
  }
  else if (gpr.IsImm(b) && (gpr.GetImm(b) & 0xFFF000) == gpr.GetImm(b))
  {
    SXTW(CR, gpr.R(a));
    SUB(CR, CR, gpr.GetImm(b) >> 12, true);
  }
  else if (gpr.IsImm(b) && (((~gpr.GetImm(b) + 1) & 0xFFF) == (~gpr.GetImm(b) + 1)))
  {
    SXTW(CR, gpr.R(a));
    ADD(CR, CR, ~gpr.GetImm(b) + 1);
  }
  else if (gpr.IsImm(b) && (((~gpr.GetImm(b) + 1) & 0xFFF000) == (~gpr.GetImm(b) + 1)))
  {
    SXTW(CR, gpr.R(a));
    ADD(CR, CR, (~gpr.GetImm(b) + 1) >> 12, true);
  }
  else
  {
    // If we're dealing with immediates, check their most significant bit to
    // see if we can skip sign extension.
    const auto should_sign_extend = [&](u32 reg) -> bool {
      return !gpr.IsImm(reg) || (gpr.GetImm(reg) & (1U << 31));
    };
    bool sign_extend_a = should_sign_extend(a);
    bool sign_extend_b = should_sign_extend(b);

    ARM64Reg RA = gpr.R(a);
    ARM64Reg RB = gpr.R(b);

    if (sign_extend_a)
    {
      SXTW(CR, RA);
      RA = CR;
    }
    else
    {
      RA = EncodeRegTo64(RA);
    }

    auto opt = ArithOption(RB, ExtendSpecifier::SXTW);
    if (!sign_extend_b)
    {
      opt = ArithOption(CR, ShiftType::LSL, 0);
      RB = EncodeRegTo64(RB);
    }

    SUB(CR, RA, RB, opt);
  }
}

void JitArm64::cmpl(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int crf = inst.CRFD;
  u32 a = inst.RA, b = inst.RB;

  gpr.BindCRToRegister(crf, false);
  ARM64Reg CR = gpr.CR(crf);

  if (gpr.IsImm(a) && gpr.IsImm(b))
  {
    u64 A = gpr.GetImm(a);
    u64 B = gpr.GetImm(b);
    MOVI2R(CR, A - B);
  }
  else if (gpr.IsImm(a) && !gpr.GetImm(a))
  {
    NEG(CR, EncodeRegTo64(gpr.R(b)));
  }
  else if (gpr.IsImm(b) && (gpr.GetImm(b) & 0xFFF) == gpr.GetImm(b))
  {
    const u32 imm = gpr.GetImm(b);
    if (imm == 0)
      MOV(EncodeRegTo32(CR), gpr.R(a));
    else
      SUB(CR, EncodeRegTo64(gpr.R(a)), imm);
  }
  else if (gpr.IsImm(b) && (gpr.GetImm(b) & 0xFFF000) == gpr.GetImm(b))
  {
    SUB(CR, EncodeRegTo64(gpr.R(a)), gpr.GetImm(b) >> 12, true);
  }
  else
  {
    SUB(CR, EncodeRegTo64(gpr.R(a)), EncodeRegTo64(gpr.R(b)));
  }
}

void JitArm64::cmpi(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  u32 a = inst.RA;
  s64 B = inst.SIMM_16;
  int crf = inst.CRFD;

  gpr.BindCRToRegister(crf, false);
  ARM64Reg CR = gpr.CR(crf);

  if (gpr.IsImm(a))
  {
    s64 A = static_cast<s32>(gpr.GetImm(a));
    MOVI2R(CR, A - B);
    return;
  }

  SXTW(CR, gpr.R(a));

  if (B != 0)
  {
    auto WA = gpr.GetScopedReg();
    SUBI2R(CR, CR, B, EncodeRegTo64(WA));
  }
}

void JitArm64::cmpli(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  u32 a = inst.RA;
  u64 B = inst.UIMM;
  int crf = inst.CRFD;

  gpr.BindCRToRegister(crf, false);
  ARM64Reg CR = gpr.CR(crf);

  if (gpr.IsImm(a))
  {
    u64 A = gpr.GetImm(a);
    MOVI2R(CR, A - B);
    return;
  }

  if (!B)
  {
    MOV(EncodeRegTo32(CR), gpr.R(a));
    return;
  }

  SUBI2R(CR, EncodeRegTo64(gpr.R(a)), B, CR);
}



void JitArm64::addic(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA, d = inst.RD;
  bool rc = inst.OPCD == 13;
  s32 simm = inst.SIMM_16;

  gpr.BindToRegister(d, d == a);
  {
    auto WA = gpr.GetScopedReg();
    CARRY_IF_NEEDED(ADDI2R, ADDSI2R, gpr.R(d), gpr.R(a), simm, WA);
  }

  ComputeCarry();
  if (rc)
    ComputeRC0(gpr.R(d));
}

bool JitArm64::MultiplyImmediate(u32 imm, int a, int d, bool rc)
{
  if (imm == 1)
  {
    // Multiplication by one (1).
    if (d != a)
    {
      gpr.BindToRegister(d, false);
      MOV(gpr.R(d), gpr.R(a));
    }
    if (rc)
      ComputeRC0(gpr.R(d));
  }
  else if (MathUtil::IsPow2(imm))
  {
    // Multiplication by a power of two (2^n).
    const int shift = MathUtil::IntLog2(imm);

    gpr.BindToRegister(d, d == a);
    LSL(gpr.R(d), gpr.R(a), shift);
    if (rc)
      ComputeRC0(gpr.R(d));
  }
  else if (MathUtil::IsPow2(imm - 1))
  {
    // Multiplication by a power of two plus one (2^n + 1).
    const int shift = MathUtil::IntLog2(imm - 1);

    gpr.BindToRegister(d, d == a);
    ADD(gpr.R(d), gpr.R(a), gpr.R(a), ArithOption(gpr.R(a), ShiftType::LSL, shift));
    if (rc)
      ComputeRC0(gpr.R(d));
  }
  else if (MathUtil::IsPow2(~imm + 1))
  {
    // Multiplication by a negative power of two (-(2^n)).
    const int shift = MathUtil::IntLog2(~imm + 1);

    gpr.BindToRegister(d, d == a);
    NEG(gpr.R(d), gpr.R(a), ArithOption(gpr.R(a), ShiftType::LSL, shift));
    if (rc)
      ComputeRC0(gpr.R(d));
  }
  else if (MathUtil::IsPow2(~imm + 2))
  {
    // Multiplication by a negative power of two plus one (-(2^n) + 1).
    const int shift = MathUtil::IntLog2(~imm + 2);

    gpr.BindToRegister(d, d == a);
    SUB(gpr.R(d), gpr.R(a), gpr.R(a), ArithOption(gpr.R(a), ShiftType::LSL, shift));
    if (rc)
      ComputeRC0(gpr.R(d));
  }
  else
  {
    // Immediate did not match any known special cases.
    return false;
  }

  return true;
}


void JitArm64::addzex(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  int a = inst.RA, d = inst.RD;

  if (gpr.IsImm(a) && (gpr.GetImm(a) == 0 || HasConstantCarry()))
  {
    const u32 imm = gpr.GetImm(a);
    const bool is_all_ones = imm == 0xFFFFFFFF;

    switch (js.carryFlag)
    {
    case CarryFlag::InPPCState:
    {
      gpr.BindToRegister(d, false);
      LDRB(IndexType::Unsigned, gpr.R(d), PPC_REG, PPCSTATE_OFF(xer_ca));
      ComputeCarry(false);
      break;
    }
    case CarryFlag::InHostCarry:
    {
      gpr.BindToRegister(d, false);
      CSET(gpr.R(d), CCFlags::CC_CS);
      ComputeCarry(false);
      break;
    }
    case CarryFlag::ConstantTrue:
    {
      gpr.SetImmediate(d, imm + 1);
      ComputeCarry(is_all_ones);
      break;
    }
    case CarryFlag::ConstantFalse:
    {
      gpr.SetImmediate(d, imm);
      ComputeCarry(false);
      break;
    }
    }
  }
  else
  {
    switch (js.carryFlag)
    {
    case CarryFlag::InPPCState:
    {
      const bool allocate_reg = d == a;
      gpr.BindToRegister(d, allocate_reg);

      {
        auto WA = allocate_reg ? gpr.GetScopedReg() : Arm64GPRCache::ScopedARM64Reg(gpr.R(d));
        LDRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_ca));
        CARRY_IF_NEEDED(ADD, ADDS, gpr.R(d), gpr.R(a), WA);
      }

      ComputeCarry();
      break;
    }
    case CarryFlag::InHostCarry:
    {
      gpr.BindToRegister(d, d == a);
      CARRY_IF_NEEDED(ADC, ADCS, gpr.R(d), gpr.R(a), ARM64Reg::WZR);
      ComputeCarry();
      break;
    }
    case CarryFlag::ConstantTrue:
    {
      gpr.BindToRegister(d, d == a);
      CARRY_IF_NEEDED(ADD, ADDS, gpr.R(d), gpr.R(a), 1);
      ComputeCarry();
      break;
    }
    case CarryFlag::ConstantFalse:
    {
      if (d != a)
      {
        gpr.BindToRegister(d, false);
        MOV(gpr.R(d), gpr.R(a));
      }

      ComputeCarry(false);
      break;
    }
    }
  }

  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}

void JitArm64::subfex(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  const bool mex = inst.SUBOP10 & 32;
  const int a = inst.RA, b = inst.RB, d = inst.RD;

  const auto handle_imm = [&](const u32 i, const u32 j) {
    const u32 imm = ~i + j;
    const bool is_zero = imm == 0;
    const bool is_all_ones = imm == 0xFFFFFFFF;

    switch (js.carryFlag)
    {
    case CarryFlag::InPPCState:
    {
      gpr.BindToRegister(d, false);
      ARM64Reg RD = gpr.R(d);
      if (is_zero)
      {
        LDRB(IndexType::Unsigned, RD, PPC_REG, PPCSTATE_OFF(xer_ca));
      }
      else
      {
        auto WA = gpr.GetScopedReg();
        LDRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_ca));
        ADDI2R(RD, WA, imm, RD);
      }
      break;
    }
    case CarryFlag::InHostCarry:
    {
      gpr.BindToRegister(d, false);
      ARM64Reg RD = gpr.R(d);
      if (is_zero)
      {
        // RD = 0 + carry
        CSET(RD, CC_CS);
      }
      else if (is_all_ones)
      {
        // RD = -1 + carry = carry ? 0 : -1
        // CSETM sets the destination to -1 if the condition is true, 0
        // otherwise. Hence, the condition must be carry clear.
        CSETM(RD, CC_CC);
      }
      else
      {
        MOVI2R(RD, imm);
        ADC(RD, RD, ARM64Reg::WZR);
      }
      break;
    }
    case CarryFlag::ConstantTrue:
    {
      gpr.SetImmediate(d, imm + 1);
      break;
    }
    case CarryFlag::ConstantFalse:
    {
      gpr.SetImmediate(d, imm);
      break;
    }
    }

    const bool must_have_carry = Interpreter::Helper_Carry(~i, j);
    const bool might_have_carry = is_all_ones;

    if (must_have_carry)
    {
      ComputeCarry(true);
    }
    else if (might_have_carry)
    {
      // carry stays as it is
    }
    else
    {
      ComputeCarry(false);
    }
  };

  if (!mex && a == b)
  {
    // Special case: subfe A, B, B is a common compiler idiom to copy the carry
    // flag to a register.
    // We handle this as-if we're dealing with two identical immediate values.
    // The exact values used here don't matter. We use zeroes.
    handle_imm(0, 0);
  }
  else if (gpr.IsImm(a) && (mex || gpr.IsImm(b)))
  {
    const u32 i = gpr.GetImm(a);
    const u32 j = mex ? -1 : gpr.GetImm(b);
    handle_imm(i, j);
  }
  else
  {
    gpr.BindToRegister(d, d == a || d == b);
    {
      Arm64GPRCache::ScopedARM64Reg RB;
      if (mex)
      {
        RB = gpr.GetScopedReg();
        MOVI2R(RB, -1);
      }
      else
      {
        RB = gpr.R(b);
      }

      if (js.carryFlag == CarryFlag::ConstantTrue)
      {
        CARRY_IF_NEEDED(SUB, SUBS, gpr.R(d), RB, gpr.R(a));
      }
      else
      {
        LoadCarry();
        CARRY_IF_NEEDED(SBC, SBCS, gpr.R(d), RB, gpr.R(a));
      }
    }

    ComputeCarry();
  }

  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}

void JitArm64::subfx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  const int a = inst.RA, b = inst.RB, d = inst.RD;
  const bool carry = !(inst.SUBOP10 & (1 << 5));

  if (gpr.IsImm(a))
  {
    const u32 imm = gpr.GetImm(a);

    if (imm == 0)
    {
      if (d != b)
      {
        gpr.BindToRegister(d, false);
        MOV(gpr.R(d), gpr.R(b));
      }
      if (carry)
        ComputeCarry(true);
      if (inst.Rc)
        ComputeRC0(gpr.R(d));
      return;
    }

    const bool low_12 = (imm & 0xFFF) == imm;
    const bool high_12 = (imm & 0xFFF000) == imm;
    if (low_12 || high_12)
    {
      gpr.BindToRegister(d, d == b);
      CARRY_IF_NEEDED_COND(carry, SUB, SUBS, gpr.R(d), gpr.R(b), high_12 ? imm >> 12 : imm,
                           high_12);
      if (carry)
        ComputeCarry();
      if (inst.Rc)
        ComputeRC0(gpr.R(d));
      return;
    }
  }

  if (gpr.IsImm(b, 0))
  {
    gpr.BindToRegister(d, d == a);
    CARRY_IF_NEEDED_COND(carry, NEG, NEGS, gpr.R(d), gpr.R(a));
    if (carry)
      ComputeCarry();
    if (inst.Rc)
      ComputeRC0(gpr.R(d));
    return;
  }

  gpr.BindToRegister(d, d == a || d == b);

  // d = b - a
  CARRY_IF_NEEDED_COND(carry, SUB, SUBS, gpr.R(d), gpr.R(b), gpr.R(a));
  if (carry)
    ComputeCarry();
  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}

void JitArm64::subfzex(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  int a = inst.RA, d = inst.RD;

  if (gpr.IsImm(a) && HasConstantCarry())
  {
    const u32 imm = ~gpr.GetImm(a);
    const u32 carry = js.carryFlag == CarryFlag::ConstantTrue;
    gpr.SetImmediate(d, imm + carry);
    ComputeCarry(Interpreter::Helper_Carry(imm, carry));
  }
  else
  {
    gpr.BindToRegister(d, d == a);

    switch (js.carryFlag)
    {
    case CarryFlag::InPPCState:
    {
      {
        auto WA = gpr.GetScopedReg();
        LDRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_ca));
        MVN(gpr.R(d), gpr.R(a));
        CARRY_IF_NEEDED(ADD, ADDS, gpr.R(d), gpr.R(d), WA);
      }
      ComputeCarry();
      break;
    }
    case CarryFlag::InHostCarry:
    {
      CARRY_IF_NEEDED(SBC, SBCS, gpr.R(d), ARM64Reg::WZR, gpr.R(a));
      ComputeCarry();
      break;
    }
    case CarryFlag::ConstantTrue:
    {
      CARRY_IF_NEEDED(NEG, NEGS, gpr.R(d), gpr.R(a));
      ComputeCarry();
      break;
    }
    case CarryFlag::ConstantFalse:
    {
      MVN(gpr.R(d), gpr.R(a));
      ComputeCarry(false);
      break;
    }
    }
  }

  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}

void JitArm64::subfic(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA, d = inst.RD;
  s32 imm = inst.SIMM_16;

  const bool will_read = d == a;
  gpr.BindToRegister(d, will_read);
  ARM64Reg RD = gpr.R(d);

  if (imm == -1)
  {
    // d = -1 - a = ~a
    MVN(RD, gpr.R(a));
    // CA is always set in this case
    ComputeCarry(true);
  }
  else
  {
    const bool is_zero = imm == 0;

    // d = imm - a
    {
      Arm64GPRCache::ScopedARM64Reg WA(ARM64Reg::WZR);
      if (!is_zero)
      {
        WA = will_read ? gpr.GetScopedReg() : Arm64GPRCache::ScopedARM64Reg(RD);
        MOVI2R(WA, imm);
      }

      CARRY_IF_NEEDED(SUB, SUBS, RD, WA, gpr.R(a));
    }

    ComputeCarry();
  }
}

void JitArm64::addex(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  bool mex = inst.SUBOP10 & 32;
  int a = inst.RA, b = inst.RB, d = inst.RD;

  if (gpr.IsImm(a) && (mex || gpr.IsImm(b)))
  {
    const u32 i = gpr.GetImm(a), j = mex ? -1 : gpr.GetImm(b);
    const u32 imm = i + j;
    const bool is_zero = imm == 0;
    const bool is_all_ones = imm == 0xFFFFFFFF;

    switch (js.carryFlag)
    {
    case CarryFlag::InPPCState:
    {
      gpr.BindToRegister(d, false);
      ARM64Reg RD = gpr.R(d);
      if (is_zero)
      {
        LDRB(IndexType::Unsigned, RD, PPC_REG, PPCSTATE_OFF(xer_ca));
      }
      else
      {
        auto WA = gpr.GetScopedReg();
        LDRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(xer_ca));
        ADDI2R(RD, WA, imm, RD);
      }
      break;
    }
    case CarryFlag::InHostCarry:
    {
      gpr.BindToRegister(d, false);
      ARM64Reg RD = gpr.R(d);
      if (is_zero)
      {
        // RD = 0 + carry = carry ? 1 : 0
        CSET(RD, CC_CS);
      }
      else if (is_all_ones)
      {
        // RD = -1 + carry = carry ? 0 : -1
        // Note that CSETM sets the destination to -1 if the condition is true,
        // and 0 otherwise. Hence, the condition must be carry clear.
        CSETM(RD, CC_CC);
      }
      else
      {
        MOVI2R(RD, imm);
        ADC(RD, RD, ARM64Reg::WZR);
      }
      break;
    }
    case CarryFlag::ConstantTrue:
    {
      gpr.SetImmediate(d, imm + 1);
      break;
    }
    case CarryFlag::ConstantFalse:
    {
      gpr.SetImmediate(d, imm);
      break;
    }
    }

    const bool must_have_carry = Interpreter::Helper_Carry(i, j);
    const bool might_have_carry = is_all_ones;

    if (must_have_carry)
    {
      ComputeCarry(true);
    }
    else if (might_have_carry)
    {
      // carry stays as it is
    }
    else
    {
      ComputeCarry(false);
    }
  }
  else
  {
    gpr.BindToRegister(d, d == a || d == b);
    {
      Arm64GPRCache::ScopedARM64Reg RB;
      if (mex)
      {
        RB = gpr.GetScopedReg();
        MOVI2R(RB, -1);
      }
      else
      {
        RB = gpr.R(b);
      }

      if (js.carryFlag == CarryFlag::ConstantFalse)
      {
        CARRY_IF_NEEDED(ADD, ADDS, gpr.R(d), gpr.R(a), RB);
      }
      else
      {
        LoadCarry();
        CARRY_IF_NEEDED(ADC, ADCS, gpr.R(d), gpr.R(a), RB);
      }
    }

    ComputeCarry();
  }

  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}

void JitArm64::addcx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  FALLBACK_IF(inst.OE);

  int a = inst.RA, b = inst.RB, d = inst.RD;

  gpr.BindToRegister(d, d == a || d == b);
  CARRY_IF_NEEDED(ADD, ADDS, gpr.R(d), gpr.R(a), gpr.R(b));

  ComputeCarry();
  if (inst.Rc)
    ComputeRC0(gpr.R(d));
}

