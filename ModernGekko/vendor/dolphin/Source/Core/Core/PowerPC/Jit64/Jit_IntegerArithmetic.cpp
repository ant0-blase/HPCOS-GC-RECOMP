// Copyright 2008 Dolphin Emulator Project
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

void Jit64::GenerateConstantOverflow(s64 val)
{
  GenerateConstantOverflow(val > std::numeric_limits<s32>::max() ||
                           val < std::numeric_limits<s32>::min());
}

void Jit64::GenerateConstantOverflow(bool overflow)
{
  if (overflow)
  {
    // XER[OV/SO] = 1
    MOV(8, PPCSTATE(xer_so_ov), Imm8(XER_OV_MASK | XER_SO_MASK));
  }
  else
  {
    // XER[OV] = 0
    AND(8, PPCSTATE(xer_so_ov), Imm8(~XER_OV_MASK));
  }
}

// We could do overflow branchlessly, but unlike carry it seems to be quite a bit rarer.
void Jit64::GenerateOverflow(Gen::CCFlags cond)
{
  FixupBranch jno = J_CC(cond);
  // XER[OV/SO] = 1
  MOV(8, PPCSTATE(xer_so_ov), Imm8(XER_OV_MASK | XER_SO_MASK));
  FixupBranch exit = J();
  SetJumpTarget(jno);
  // XER[OV] = 0
  // We need to do this without modifying flags so as not to break stuff that assumes flags
  // aren't clobbered (carry, branch merging): speed doesn't really matter here (this is really
  // rare).
  static const std::array<u8, 4> ovtable = {{0, 0, XER_SO_MASK, XER_SO_MASK}};
  MOVZX(32, 8, RSCRATCH, PPCSTATE(xer_so_ov));
  LEA(64, RSCRATCH2, MConst(ovtable));
  MOV(8, R(RSCRATCH), MRegSum(RSCRATCH, RSCRATCH2));
  MOV(8, PPCSTATE(xer_so_ov), R(RSCRATCH));
  SetJumpTarget(exit);
}

void Jit64::FinalizeCarry(CCFlags cond)
{
  js.carryFlag = CarryFlag::InPPCState;
  if (js.op->wantsCA)
  {
    // Not actually merging instructions, but the effect is equivalent (we can't have
    // breakpoints/etc in between).
    if (CanMergeNextInstructions(1) && js.op[1].wantsCAInFlags)
    {
      if (cond == CC_C)
      {
        js.carryFlag = CarryFlag::InHostCarry;
      }
      else if (cond == CC_NC)
      {
        js.carryFlag = CarryFlag::InHostCarryInverted;
      }
      else
      {
        // convert the condition to a carry flag (is there a better way?)
        SETcc(cond, R(RSCRATCH));
        SHR(8, R(RSCRATCH), Imm8(1));
        js.carryFlag = CarryFlag::InHostCarry;
      }
      LockFlags();
    }
    else
    {
      JitSetCAIf(cond);
    }
  }
}

// Unconditional version
void Jit64::FinalizeCarry(bool ca)
{
  js.carryFlag = CarryFlag::InPPCState;
  if (js.op->wantsCA)
  {
    if (CanMergeNextInstructions(1) && js.op[1].wantsCAInFlags)
    {
      if (ca)
        STC();
      else
        CLC();
      LockFlags();
      js.carryFlag = CarryFlag::InHostCarry;
    }
    else if (ca)
    {
      JitSetCA();
    }
    else
    {
      JitClearCA();
    }
  }
}

void Jit64::FinalizeCarryOverflow(bool oe, bool inv)
{
  if (oe)
  {
    GenerateOverflow();
  }
  // Do carry
  FinalizeCarry(inv ? CC_NC : CC_C);
}

void Jit64::FlushCarry()
{
  switch (js.carryFlag)
  {
  case CarryFlag::InPPCState:
    break;
  case CarryFlag::InHostCarry:
    JitSetCAIf(CC_C);
    UnlockFlags();
    break;
  case CarryFlag::InHostCarryInverted:
    JitSetCAIf(CC_NC);
    UnlockFlags();
    break;
  }

  js.carryFlag = CarryFlag::InPPCState;
}

// Be careful; only set needs_test to false if we can be absolutely sure flags don't need
// to be recalculated and haven't been clobbered. Keep in mind not all instructions set
// sufficient flags -- for example, the flags from SHL/SHR are *not* sufficient for LT/GT
// branches, only EQ.
// The flags from any instruction that may set OF (such as ADD/SUB) can not be used for
// LT/GT either.
void Jit64::ComputeRC(preg_t preg, bool needs_test, bool needs_sext)
{
  RCOpArg arg = gpr.Use(preg, RCMode::Read);
  RegCache::Realize(arg);

  if (arg.IsImm())
  {
    const s32 value = arg.SImm32();
    arg.Unlock();
    FinalizeImmediateRC(value);
    return;
  }
  else if (needs_sext)
  {
    MOVSX(64, 32, RSCRATCH, arg);
    MOV(64, PPCSTATE_CR(0), R(RSCRATCH));
  }
  else
  {
    MOV(64, PPCSTATE_CR(0), arg);
  }

  if (CheckMergedBranch(0))
  {
    if (needs_test)
    {
      TEST(32, arg, arg);
      arg.Unlock();
    }
    else
    {
      // If an operand to the cmp/rc op we're merging with the branch isn't used anymore, it'd be
      // better to flush it here so that we don't have to flush it on both sides of the branch.
      // We don't want to do this if a test is needed though, because it would interrupt macro-op
      // fusion.
      arg.Unlock();
      gpr.Flush(~js.op->gprInUse);
    }
    DoMergedBranchCondition();
  }
}

void Jit64::FinalizeImmediateRC(s32 value)
{
  MOV(64, PPCSTATE_CR(0), Imm32(value));

  if (CheckMergedBranch(0))
    DoMergedBranchImmediate(value);
}

// we can't do this optimization in the emitter because MOVZX and AND have different effects on
// flags.
void Jit64::AndWithMask(X64Reg reg, u32 mask)
{
  if (mask == 0xffffffff)
    return;

  if (mask == 0)
    XOR(32, R(reg), R(reg));
  else if (mask == 0xff)
    MOVZX(32, 8, reg, R(reg));
  else if (mask == 0xffff)
    MOVZX(32, 16, reg, R(reg));
  else
    AND(32, R(reg), Imm32(mask));
}

void Jit64::RotateLeft(int bits, X64Reg regOp, const OpArg& arg, u8 rotate)
{
  const bool is_same_reg = arg.IsSimpleReg(regOp);

  if (cpu_info.bBMI2 && !is_same_reg && rotate != 0)
  {
    RORX(bits, regOp, arg, bits - rotate);
    return;
  }

  if (!is_same_reg)
  {
    MOV(bits, R(regOp), arg);
  }

  if (rotate != 0)
  {
    ROL(bits, R(regOp), Imm8(rotate));
  }
}

// Following static functions are used in conjunction with regimmop
static u32 Add(u32 a, u32 b)
{
  return a + b;
}

static u32 Or(u32 a, u32 b)
{
  return a | b;
}

static u32 And(u32 a, u32 b)
{
  return a & b;
}

static u32 Xor(u32 a, u32 b)
{
  return a ^ b;
}

void Jit64::regimmop(int d, int a, bool binary, u32 value, Operation doop,
                     void (XEmitter::*op)(int, const OpArg&, const OpArg&), bool Rc, bool carry)
{
  bool needs_test = doop == Add;
  // Be careful; addic treats r0 as r0, but addi treats r0 as zero.
  if (a || binary || carry)
  {
    carry &= js.op->wantsCA;
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Ra, Rd);
    if (doop == Add && Ra.IsSimpleReg() && !carry && d != a)
    {
      LEA(32, Rd, MDisp(Ra.GetSimpleReg(), value));
    }
    else
    {
      if (d != a)
        MOV(32, Rd, Ra);
      (this->*op)(32, Rd, Imm32(value));  // m_GPR[d] = m_GPR[_inst.RA] + _inst.SIMM_16;
    }
    if (carry)
      FinalizeCarry(CC_C);
  }
  else if (doop == Add)
  {
    // a == 0, which for these instructions imply value = 0
    gpr.SetImmediate32(d, value);
  }
  else
  {
    ASSERT_MSG(DYNA_REC, 0, "WTF regimmop");
  }
  if (Rc)
    ComputeRC(d, needs_test, doop != And || (value & 0x80000000));
}

void Jit64::reg_imm(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  u32 d = inst.RD, a = inst.RA, s = inst.RS;
  switch (inst.OPCD)
  {
  case 14:  // addi
    // occasionally used as MOV
    if (a != 0 && d != a && inst.SIMM_16 == 0)
    {
      RCOpArg Ra = gpr.Use(a, RCMode::Read);
      RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
      RegCache::Realize(Ra, Rd);
      MOV(32, Rd, Ra);
    }
    else
    {
      regimmop(d, a, false, (u32)(s32)inst.SIMM_16, Add, &XEmitter::ADD);  // addi
    }
    break;
  case 15:  // addis
    regimmop(d, a, false, (u32)inst.SIMM_16 << 16, Add, &XEmitter::ADD);
    break;
  case 24:  // ori
  case 25:  // oris
  {
    const u32 immediate = inst.OPCD == 24 ? inst.UIMM : inst.UIMM << 16;
    regimmop(a, s, true, immediate, Or, &XEmitter::OR);
    break;
  }
  case 28:  // andi
    regimmop(a, s, true, inst.UIMM, And, &XEmitter::AND, true);
    break;
  case 29:  // andis
    regimmop(a, s, true, inst.UIMM << 16, And, &XEmitter::AND, true);
    break;
  case 26:  // xori
  case 27:  // xoris
  {
    const u32 immediate = inst.OPCD == 26 ? inst.UIMM : inst.UIMM << 16;
    regimmop(a, s, true, immediate, Xor, &XEmitter::XOR, false);
    break;
  }
  case 12:  // addic
    regimmop(d, a, false, (u32)(s32)inst.SIMM_16, Add, &XEmitter::ADD, false, true);
    break;
  case 13:  // addic_rc
    regimmop(d, a, true, (u32)(s32)inst.SIMM_16, Add, &XEmitter::ADD, true, true);
    break;
  default:
    FALLBACK_IF(true);
  }
}

bool Jit64::CheckMergedBranch(u32 crf) const
{
  if (!analyzer.HasOption(PPCAnalyst::PPCAnalyzer::OPTION_BRANCH_MERGE))
    return false;

  if (!CanMergeNextInstructions(1))
    return false;

  const UGeckoInstruction& next = js.op[1].inst;
  return (((next.OPCD == 16 /* bcx */) ||
           ((next.OPCD == 19) && (next.SUBOP10 == 528) /* bcctrx */) ||
           ((next.OPCD == 19) && (next.SUBOP10 == 16) /* bclrx */)) &&
          (next.BO & BO_DONT_DECREMENT_FLAG) && !(next.BO & BO_DONT_CHECK_CONDITION) &&
          static_cast<u32>(next.BI >> 2) == crf);
}

void Jit64::DoMergedBranch()
{
  // Code that handles successful PPC branching.
  const UGeckoInstruction& next = js.op[1].inst;
  const u32 nextPC = js.op[1].address;

  if (js.op[1].branchIsIdleLoop)
  {
    if (next.LK)
      MOV(32, PPCSTATE_SPR(SPR_LR), Imm32(nextPC + 4));

    const u32 destination = js.op[1].branchTo;
    WriteBranchWatch<true>(nextPC, destination, next, {});
    WriteIdleExit(destination);
  }
  else if (next.OPCD == 16)  // bcx
  {
    if (next.LK)
      MOV(32, PPCSTATE_SPR(SPR_LR), Imm32(nextPC + 4));

    const u32 destination = js.op[1].branchTo;
    WriteBranchWatch<true>(nextPC, destination, next, {});
    WriteExit(destination, next.LK, nextPC + 4);
  }
  else if ((next.OPCD == 19) && (next.SUBOP10 == 528))  // bcctrx
  {
    if (next.LK)
      MOV(32, PPCSTATE_SPR(SPR_LR), Imm32(nextPC + 4));
    MOV(32, R(RSCRATCH), PPCSTATE_SPR(SPR_CTR));
    AND(32, R(RSCRATCH), Imm32(0xFFFFFFFC));
    WriteBranchWatchDestInRSCRATCH(nextPC, next, BitSet32{RSCRATCH});
    WriteExitDestInRSCRATCH(next.LK, nextPC + 4);
  }
  else if ((next.OPCD == 19) && (next.SUBOP10 == 16))  // bclrx
  {
    MOV(32, R(RSCRATCH), PPCSTATE_SPR(SPR_LR));
    if (!m_enable_blr_optimization)
      AND(32, R(RSCRATCH), Imm32(0xFFFFFFFC));
    if (next.LK)
      MOV(32, PPCSTATE_SPR(SPR_LR), Imm32(nextPC + 4));
    WriteBranchWatchDestInRSCRATCH(nextPC, next, BitSet32{RSCRATCH});
    WriteBLRExit();
  }
  else
  {
    PanicAlertFmt("WTF invalid branch");
  }
}

void Jit64::DoMergedBranchCondition()
{
  js.downcountAmount++;
  js.skipInstructions = 1;
  const UGeckoInstruction& next = js.op[1].inst;
  int test_bit = 3 - (next.BI & 3);
  bool condition = !!(next.BO & BO_BRANCH_IF_TRUE);
  const u32 nextPC = js.op[1].address;

  ASSERT(gpr.IsAllUnlocked());

  FixupBranch pDontBranch;
  switch (test_bit)
  {
  case PowerPC::CR_LT_BIT:
    // Test < 0, so jump over if >= 0.
    pDontBranch = J_CC(condition ? CC_GE : CC_L, Jump::Near);
    break;
  case PowerPC::CR_GT_BIT:
    // Test > 0, so jump over if <= 0.
    pDontBranch = J_CC(condition ? CC_LE : CC_G, Jump::Near);
    break;
  case PowerPC::CR_EQ_BIT:
    // Test = 0, so jump over if != 0.
    pDontBranch = J_CC(condition ? CC_NE : CC_E, Jump::Near);
    break;
  case PowerPC::CR_SO_BIT:
    // SO bit, do not branch (we don't emulate SO for cmp).
    pDontBranch = J(Jump::Near);
    break;
  }

  {
    RCForkGuard gpr_guard = gpr.Fork();
    RCForkGuard fpr_guard = fpr.Fork();

    gpr.Flush();
    fpr.Flush();

    DoMergedBranch();
  }

  SetJumpTarget(pDontBranch);

  if (!analyzer.HasOption(PPCAnalyst::PPCAnalyzer::OPTION_CONDITIONAL_CONTINUE))
  {
    gpr.Flush();
    fpr.Flush();
    WriteBranchWatch<false>(nextPC, nextPC + 4, next, {});
    WriteExit(nextPC + 4);
  }
  else
  {
    WriteBranchWatch<false>(nextPC, nextPC + 4, next, CallerSavedRegistersInUse());
  }
}

void Jit64::DoMergedBranchImmediate(s64 val)
{
  js.downcountAmount++;
  js.skipInstructions = 1;
  const UGeckoInstruction& next = js.op[1].inst;
  int test_bit = 3 - (next.BI & 3);
  bool condition = !!(next.BO & BO_BRANCH_IF_TRUE);
  const u32 nextPC = js.op[1].address;

  ASSERT(gpr.IsAllUnlocked());

  bool branch = false;
  switch (test_bit)
  {
  case PowerPC::CR_LT_BIT:
    branch = condition ? val < 0 : val >= 0;
    break;
  case PowerPC::CR_GT_BIT:
    branch = condition ? val > 0 : val <= 0;
    break;
  case PowerPC::CR_EQ_BIT:
    branch = condition ? val == 0 : val != 0;
    break;
  case PowerPC::CR_SO_BIT:
    // SO bit, do not branch (we don't emulate SO for cmp).
    break;
  }

  if (branch)
  {
    gpr.Flush();
    fpr.Flush();
    DoMergedBranch();
  }
  else if (!analyzer.HasOption(PPCAnalyst::PPCAnalyzer::OPTION_CONDITIONAL_CONTINUE))
  {
    gpr.Flush();
    fpr.Flush();
    WriteBranchWatch<false>(nextPC, nextPC + 4, next, {});
    WriteExit(nextPC + 4);
  }
  else
  {
    WriteBranchWatch<false>(nextPC, nextPC + 4, next, CallerSavedRegistersInUse());
  }
}

void Jit64::cmpXX(UGeckoInstruction inst)
{
  // USES_CR
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int b = inst.RB;
  u32 crf = inst.CRFD;
  bool merge_branch = CheckMergedBranch(crf);

  bool signedCompare;
  RCOpArg comparand;
  switch (inst.OPCD)
  {
  // cmp / cmpl
  case 31:
    signedCompare = (inst.SUBOP10 == 0);
    comparand = signedCompare ? gpr.Use(b, RCMode::Read) : gpr.Bind(b, RCMode::Read);
    RegCache::Realize(comparand);
    break;

  // cmpli
  case 10:
    signedCompare = false;
    comparand = RCOpArg::Imm32((u32)inst.UIMM);
    break;

  // cmpi
  case 11:
    signedCompare = true;
    comparand = RCOpArg::Imm32((u32)(s32)(s16)inst.UIMM);
    break;

  default:
    signedCompare = false;  // silence compiler warning
    PanicAlertFmt("cmpXX");
  }

  if (gpr.IsImm(a) && comparand.IsImm())
  {
    // Both registers contain immediate values, so we can pre-compile the compare result
    s64 compareResult = signedCompare ? (s64)gpr.SImm32(a) - (s64)comparand.SImm32() :
                                        (u64)gpr.Imm32(a) - (u64)comparand.Imm32();
    if (compareResult == (s32)compareResult)
    {
      MOV(64, PPCSTATE_CR(crf), Imm32((u32)compareResult));
    }
    else
    {
      MOV(64, R(RSCRATCH), Imm64(compareResult));
      MOV(64, PPCSTATE_CR(crf), R(RSCRATCH));
    }

    if (merge_branch)
    {
      RegCache::Unlock(comparand);
      DoMergedBranchImmediate(compareResult);
    }

    return;
  }

  if (!gpr.IsImm(a) && !signedCompare && comparand.IsImm() && comparand.Imm32() == 0)
  {
    RCX64Reg Ra = gpr.Bind(a, RCMode::Read);
    RegCache::Realize(Ra);

    MOV(64, PPCSTATE_CR(crf), Ra);
    if (merge_branch)
    {
      TEST(64, Ra, Ra);
      RegCache::Unlock(comparand, Ra);
      DoMergedBranchCondition();
    }
    return;
  }

  const X64Reg input = RSCRATCH;
  if (gpr.IsImm(a))
  {
    if (signedCompare)
      MOV(64, R(input), Imm32(gpr.SImm32(a)));
    else
      MOV(32, R(input), Imm32(gpr.Imm32(a)));
  }
  else
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RegCache::Realize(Ra);
    if (signedCompare)
      MOVSX(64, 32, input, Ra);
    else
      MOVZX(64, 32, input, Ra);
  }

  if (comparand.IsImm())
  {
    // sign extension will ruin this, so store it in a register
    if (!signedCompare && (comparand.Imm32() & 0x80000000U) != 0)
    {
      MOV(32, R(RSCRATCH2), comparand);
      comparand = RCOpArg::R(RSCRATCH2);
    }
  }
  else
  {
    if (signedCompare)
    {
      MOVSX(64, 32, RSCRATCH2, comparand);
      comparand = RCOpArg::R(RSCRATCH2);
    }
  }

  if (comparand.IsImm() && comparand.Imm32() == 0)
  {
    MOV(64, PPCSTATE_CR(crf), R(input));
    // Place the comparison next to the branch for macro-op fusion
    if (merge_branch)
      TEST(64, R(input), R(input));
  }
  else
  {
    SUB(64, R(input), comparand);
    MOV(64, PPCSTATE_CR(crf), R(input));
  }

  if (merge_branch)
  {
    RegCache::Unlock(comparand);
    DoMergedBranchCondition();
  }
}



void Jit64::subfic(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, d = inst.RD, imm = inst.SIMM_16;

  RCOpArg Ra = gpr.Use(a, RCMode::Read);
  RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
  RegCache::Realize(Ra, Rd);

  if (imm == 0)
  {
    if (d != a)
      MOV(32, Rd, Ra);

    // Flags act exactly like subtracting from 0
    NEG(32, Rd);
    // Output carry is inverted
    FinalizeCarry(CC_NC);
  }
  else if (imm == -1)
  {
    if (d != a)
      MOV(32, Rd, Ra);

    NOT(32, Rd);
    // CA is always set in this case
    FinalizeCarry(true);
  }
  else if (d == a)
  {
    NOT(32, Rd);
    ADD(32, Rd, Imm32(imm + 1));
    // Output carry is normal
    FinalizeCarry(CC_C);
  }
  else
  {
    MOV(32, Rd, Imm32(imm));
    SUB(32, Rd, Ra);
    // Output carry is inverted
    FinalizeCarry(CC_NC);
  }
  // This instruction has no RC flag
}

void Jit64::subfx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, d = inst.RD;
  const bool carry = !(inst.SUBOP10 & (1 << 5));

  if (gpr.IsImm(a))
  {
    s32 j = gpr.SImm32(a);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Rb, Rd);

    if (j == 0)
    {
      if (d != b)
        MOV(32, Rd, Rb);
      if (carry)
        FinalizeCarry(true);
      if (inst.OE)
        GenerateConstantOverflow(false);
    }
    else if (d == b)
    {
      SUB(32, Rd, Imm32(j));
      if (carry)
        FinalizeCarry(CC_NC);
      if (inst.OE)
        GenerateOverflow();
    }
    else if (Rb.IsSimpleReg() && !carry && !inst.OE)
    {
      LEA(32, Rd, MDisp(Rb.GetSimpleReg(), -j));
    }
    else
    {
      MOV(32, Rd, Rb);
      SUB(32, Rd, Imm32(j));
      if (carry)
        FinalizeCarry(CC_NC);
      if (inst.OE)
        GenerateOverflow();
    }
  }
  else if (gpr.IsImm(b) && gpr.Imm32(b) == 0)
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Ra, Rd);

    if (d != a)
      MOV(32, Rd, Ra);
    NEG(32, Rd);
    if (carry)
      FinalizeCarry(CC_NC);
    if (inst.OE)
      GenerateOverflow();
  }
  else
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Ra, Rb, Rd);

    if (d == a && d != b)
    {
      // special case, because sub isn't reversible
      MOV(32, R(RSCRATCH), Ra);
      MOV(32, Rd, Rb);
      SUB(32, Rd, R(RSCRATCH));
    }
    else
    {
      if (d != b)
        MOV(32, Rd, Rb);
      SUB(32, Rd, Ra);
    }
    if (carry)
      FinalizeCarry(CC_NC);
    if (inst.OE)
      GenerateOverflow();
  }
  if (inst.Rc)
    ComputeRC(d);
}

void Jit64::addx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, b = inst.RB, d = inst.RD;
  bool carry = !(inst.SUBOP10 & (1 << 8));

  if (gpr.IsImm(a) || gpr.IsImm(b))
  {
    const auto [i, j] = gpr.IsImm(a) ? std::pair(a, b) : std::pair(b, a);
    const s32 imm = gpr.SImm32(i);
    RCOpArg Rj = gpr.Use(j, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Rj, Rd);

    if (imm == 0)
    {
      if (d != j)
        MOV(32, Rd, Rj);
      if (carry)
        FinalizeCarry(false);
      if (inst.OE)
        GenerateConstantOverflow(false);
    }
    else if (d == j)
    {
      ADD(32, Rd, Imm32(imm));
      if (carry)
        FinalizeCarry(CC_C);
      if (inst.OE)
        GenerateOverflow();
    }
    else if (Rj.IsSimpleReg() && !carry && !inst.OE)
    {
      LEA(32, Rd, MDisp(Rj.GetSimpleReg(), imm));
    }
    else if (imm >= -128 && imm <= 127)
    {
      MOV(32, Rd, Rj);
      ADD(32, Rd, Imm32(imm));
      if (carry)
        FinalizeCarry(CC_C);
      if (inst.OE)
        GenerateOverflow();
    }
    else
    {
      MOV(32, Rd, Imm32(imm));
      ADD(32, Rd, Rj);
      if (carry)
        FinalizeCarry(CC_C);
      if (inst.OE)
        GenerateOverflow();
    }
  }
  else
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Ra, Rb, Rd);

    if (d == a || d == b)
    {
      RCOpArg& Rnotd = (d == a) ? Rb : Ra;
      ADD(32, Rd, Rnotd);
    }
    else if (Ra.IsSimpleReg() && Rb.IsSimpleReg() && !carry && !inst.OE)
    {
      LEA(32, Rd, MRegSum(Ra.GetSimpleReg(), Rb.GetSimpleReg()));
    }
    else
    {
      MOV(32, Rd, Ra);
      ADD(32, Rd, Rb);
    }
    if (carry)
      FinalizeCarry(CC_C);
    if (inst.OE)
      GenerateOverflow();
  }
  if (inst.Rc)
    ComputeRC(d);
}

void Jit64::arithXex(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  bool regsource = !(inst.SUBOP10 & 64);  // addex or subfex
  bool mex = !!(inst.SUBOP10 & 32);       // addmex/subfmex or addzex/subfzex
  bool add = !!(inst.SUBOP10 & 2);        // add or sub
  int a = inst.RA;
  int b = regsource ? inst.RB : a;
  int d = inst.RD;
  bool same_input_sub = !add && regsource && a == b;

  if (js.carryFlag == CarryFlag::InPPCState)
    JitGetAndClearCAOV(inst.OE);
  else
    UnlockFlags();

  bool invertedCarry = false;
  // Special case: subfe A, B, B is a common compiler idiom
  if (same_input_sub)
  {
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Rd);

    // Convert carry to borrow
    if (js.carryFlag != CarryFlag::InHostCarryInverted)
      CMC();
    SBB(32, Rd, Rd);
    invertedCarry = true;
  }
  else if (!add && regsource && d == b)
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::ReadWrite);
    RegCache::Realize(Ra, Rd);

    if (js.carryFlag != CarryFlag::InHostCarryInverted)
      CMC();
    SBB(32, Rd, Ra);
    invertedCarry = true;
  }
  else
  {
    RCOpArg Ra = gpr.Use(a, RCMode::Read);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RCOpArg source =
        regsource ? gpr.Use(d == b ? a : b, RCMode::Read) : RCOpArg::Imm32(mex ? 0xFFFFFFFF : 0);
    RegCache::Realize(Ra, Rb, Rd, source);

    if (d != a && d != b)
      MOV(32, Rd, Ra);
    if (!add)
      NOT(32, Rd);
    // if the source is an immediate, we can invert carry by going from add -> sub and doing src =
    // -1 - src
    if (js.carryFlag == CarryFlag::InHostCarryInverted && source.IsImm())
    {
      SBB(32, Rd, Imm32(-1 - source.SImm32()));
      invertedCarry = true;
    }
    else
    {
      if (js.carryFlag == CarryFlag::InHostCarryInverted)
        CMC();
      ADC(32, Rd, source);
    }
  }
  FinalizeCarryOverflow(inst.OE, invertedCarry);
  if (inst.Rc)
    ComputeRC(d);
}



void Jit64::negx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int d = inst.RD;

  {
    RCOpArg Ra = gpr.UseNoImm(a, RCMode::Read);
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Ra, Rd);

    if (a != d)
      MOV(32, Rd, Ra);
    NEG(32, Rd);
    if (inst.OE)
      GenerateOverflow();
  }
  if (inst.Rc)
    ComputeRC(d, false);
}

void Jit64::srwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int b = inst.RB;
  int s = inst.RS;

  if (gpr.IsImm(b))
  {
    u32 amount = gpr.Imm32(b);
    if (amount & 0x20)
    {
      gpr.SetImmediate32(a, 0);
    }
    else
    {
      RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
      RCOpArg Rs = gpr.Use(s, RCMode::Read);
      RegCache::Realize(Ra, Rs);

      if (a != s)
        MOV(32, Ra, Rs);

      amount &= 0x1f;
      if (amount != 0)
        SHR(32, Ra, Imm8(amount));
    }
  }
  else if (cpu_info.bBMI2)
  {
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCX64Reg Rb = gpr.Bind(b, RCMode::Read);
    RCX64Reg Rs = gpr.Bind(s, RCMode::Read);
    RegCache::Realize(Ra, Rb, Rs);

    // Rs must be in register: This is a 64-bit operation, using an OpArg will have invalid results
    SHRX(64, Ra, Rs, Rb);
  }
  else
  {
    RCX64Reg ecx = gpr.Scratch(ECX);  // no register choice
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(ecx, Ra, Rb, Rs);

    MOV(32, ecx, Rb);
    if (a != s)
      MOV(32, Ra, Rs);
    SHR(64, Ra, ecx);
  }
  // Shift of 0 doesn't update flags, so we need to test just in case
  if (inst.Rc)
    ComputeRC(a);
}

void Jit64::slwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int b = inst.RB;
  int s = inst.RS;

  if (gpr.IsImm(b))
  {
    u32 amount = gpr.Imm32(b);
    if (amount & 0x20)
    {
      gpr.SetImmediate32(a, 0);
    }
    else
    {
      RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
      RCOpArg Rs = gpr.Use(s, RCMode::Read);
      RegCache::Realize(Ra, Rs);

      if (a != s)
        MOV(32, Ra, Rs);

      amount &= 0x1f;
      if (amount != 0)
        SHL(32, Ra, Imm8(amount));
    }

    if (inst.Rc)
      ComputeRC(a);
  }
  else if (cpu_info.bBMI2)
  {
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCX64Reg Rb = gpr.Bind(b, RCMode::Read);
    RCOpArg Rs = gpr.UseNoImm(s, RCMode::Read);
    RegCache::Realize(Ra, Rb, Rs);

    SHLX(64, Ra, Rs, Rb);
    if (inst.Rc)
    {
      AND(32, Ra, Ra);
      RegCache::Unlock(Ra, Rb, Rs);
      ComputeRC(a, false);
    }
    else
    {
      MOVZX(64, 32, Ra, Ra);
    }
  }
  else
  {
    RCX64Reg ecx = gpr.Scratch(ECX);  // no register choice
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(ecx, Ra, Rb, Rs);

    MOV(32, ecx, Rb);
    if (a != s)
      MOV(32, Ra, Rs);
    SHL(64, Ra, ecx);
    if (inst.Rc)
    {
      AND(32, Ra, Ra);
      RegCache::Unlock(ecx, Ra, Rb, Rs);
      ComputeRC(a, false);
    }
    else
    {
      MOVZX(64, 32, Ra, Ra);
    }
  }
}

void Jit64::srawx(UGeckoInstruction inst)
{
  // USES_XER
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int b = inst.RB;
  int s = inst.RS;

  if (gpr.IsImm(b))
  {
    u32 amount = gpr.Imm32(b);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Ra, Rs);

    if (a != s)
      MOV(32, Ra, Rs);

    bool special = amount & 0x20;
    amount &= 0x1f;

    if (special)
    {
      SAR(32, Ra, Imm8(31));
      FinalizeCarry(CC_NZ);
    }
    else if (amount == 0)
    {
      FinalizeCarry(false);
    }
    else if (!js.op->wantsCA)
    {
      SAR(32, Ra, Imm8(amount));
      FinalizeCarry(CC_NZ);
    }
    else
    {
      MOV(32, R(RSCRATCH), Ra);
      SAR(32, Ra, Imm8(amount));
      SHL(32, R(RSCRATCH), Imm8(32 - amount));
      TEST(32, Ra, R(RSCRATCH));
      FinalizeCarry(CC_NZ);
    }
  }
  else if (cpu_info.bBMI2)
  {
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCX64Reg Rb = gpr.Bind(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Ra, Rb, Rs);

    X64Reg tmp = RSCRATCH;
    if (a == s && a != b)
      tmp = Ra;
    else
      MOV(32, R(tmp), Rs);

    SHL(64, R(tmp), Imm8(32));
    SARX(64, Ra, R(tmp), Rb);
    if (js.op->wantsCA)
    {
      MOV(32, R(RSCRATCH), Ra);
      SHR(64, Ra, Imm8(32));
      TEST(32, Ra, R(RSCRATCH));
    }
    else
    {
      SHR(64, Ra, Imm8(32));
    }
    FinalizeCarry(CC_NZ);
  }
  else
  {
    RCX64Reg ecx = gpr.Scratch(ECX);  // no register choice
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(ecx, Ra, Rb, Rs);

    MOV(32, ecx, Rb);
    if (a != s)
      MOV(32, Ra, Rs);
    SHL(64, Ra, Imm8(32));
    SAR(64, Ra, ecx);
    if (js.op->wantsCA)
    {
      MOV(32, R(RSCRATCH), Ra);
      SHR(64, Ra, Imm8(32));
      TEST(32, Ra, R(RSCRATCH));
    }
    else
    {
      SHR(64, Ra, Imm8(32));
    }
    FinalizeCarry(CC_NZ);
  }
  if (inst.Rc)
    ComputeRC(a);
}

void Jit64::srawix(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int s = inst.RS;
  int amount = inst.SH;

  if (amount != 0)
  {
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Ra, Rs);

    if (!js.op->wantsCA)
    {
      if (a != s)
        MOV(32, Ra, Rs);
      SAR(32, Ra, Imm8(amount));
    }
    else
    {
      MOV(32, R(RSCRATCH), Rs);
      if (a != s)
        MOV(32, Ra, R(RSCRATCH));
      // some optimized common cases that can be done in slightly fewer ops
      if (amount == 1)
      {
        SHR(32, R(RSCRATCH), Imm8(31));  // sign
        AND(32, R(RSCRATCH), Ra);        // (sign && carry)
        SAR(32, Ra, Imm8(1));
        MOV(8, PPCSTATE(xer_ca),
            R(RSCRATCH));  // XER.CA = sign && carry, aka (input&0x80000001) == 0x80000001
      }
      else
      {
        SAR(32, Ra, Imm8(amount));
        SHL(32, R(RSCRATCH), Imm8(32 - amount));
        TEST(32, R(RSCRATCH), Ra);
        FinalizeCarry(CC_NZ);
      }
    }
  }
  else
  {
    FinalizeCarry(false);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RegCache::Realize(Ra, Rs);

    if (a != s)
      MOV(32, Ra, Rs);
  }
  if (inst.Rc)
    ComputeRC(a);
}

