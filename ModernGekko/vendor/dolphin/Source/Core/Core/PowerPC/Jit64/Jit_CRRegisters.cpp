// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/Jit64/Jit.h"

#include "Common/BitSet.h"
#include "Common/CPUDetect.h"
#include "Common/CommonTypes.h"
#include "Common/MathUtil.h"
#include "Common/x64Emitter.h"

#include "Core/CoreTiming.h"
#include "Core/HW/ProcessorInterface.h"
#include "Core/PowerPC/Jit64/RegCache/JitRegCache.h"
#include "Core/PowerPC/Jit64Common/Jit64PowerPCState.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/System.h"

using namespace Gen;

static OpArg CROffset(int field)
{
  return PPCSTATE_CR(field);
}

void Jit64::GetCRFieldBit(int field, int bit, X64Reg out, bool negate)
{
  switch (bit)
  {
  case PowerPC::CR_SO_BIT:  // check bit 59 set
    BT(64, CROffset(field), Imm8(PowerPC::CR_EMU_SO_BIT));
    SETcc(negate ? CC_NC : CC_C, R(out));
    break;

  case PowerPC::CR_EQ_BIT:  // check bits 31-0 == 0
    CMP(32, CROffset(field), Imm8(0));
    SETcc(negate ? CC_NZ : CC_Z, R(out));
    break;

  case PowerPC::CR_GT_BIT:  // check val > 0
    CMP(64, CROffset(field), Imm8(0));
    SETcc(negate ? CC_NG : CC_G, R(out));
    break;

  case PowerPC::CR_LT_BIT:  // check bit 62 set
    BT(64, CROffset(field), Imm8(PowerPC::CR_EMU_LT_BIT));
    SETcc(negate ? CC_NC : CC_C, R(out));
    break;

  default:
    ASSERT_MSG(DYNA_REC, false, "Invalid CR bit");
  }
}

void Jit64::SetCRFieldBit(int field, int bit, X64Reg in)
{
  MOV(64, R(RSCRATCH2), CROffset(field));
  MOVZX(32, 8, in, R(in));

  if (bit != PowerPC::CR_GT_BIT)
    FixGTBeforeSettingCRFieldBit(RSCRATCH2);

  switch (bit)
  {
  case PowerPC::CR_SO_BIT:  // set bit 59 to input
    BTR(64, R(RSCRATCH2), Imm8(PowerPC::CR_EMU_SO_BIT));
    SHL(64, R(in), Imm8(PowerPC::CR_EMU_SO_BIT));
    OR(64, R(RSCRATCH2), R(in));
    break;

  case PowerPC::CR_EQ_BIT:  // clear low 32 bits, set bit 0 to !input
    SHR(64, R(RSCRATCH2), Imm8(32));
    SHL(64, R(RSCRATCH2), Imm8(32));
    XOR(32, R(in), Imm8(1));
    OR(64, R(RSCRATCH2), R(in));
    break;

  case PowerPC::CR_GT_BIT:  // set bit 63 to !input
    BTR(64, R(RSCRATCH2), Imm8(63));
    NOT(32, R(in));
    SHL(64, R(in), Imm8(63));
    OR(64, R(RSCRATCH2), R(in));
    break;

  case PowerPC::CR_LT_BIT:  // set bit 62 to input
    BTR(64, R(RSCRATCH2), Imm8(PowerPC::CR_EMU_LT_BIT));
    SHL(64, R(in), Imm8(PowerPC::CR_EMU_LT_BIT));
    OR(64, R(RSCRATCH2), R(in));
    break;
  }

  BTS(64, R(RSCRATCH2), Imm8(32));
  MOV(64, CROffset(field), R(RSCRATCH2));
}

void Jit64::ClearCRFieldBit(int field, int bit)
{
  switch (bit)
  {
  case PowerPC::CR_SO_BIT:
    BTR(64, CROffset(field), Imm8(PowerPC::CR_EMU_SO_BIT));
    break;

  case PowerPC::CR_EQ_BIT:
    MOV(64, R(RSCRATCH), CROffset(field));
    FixGTBeforeSettingCRFieldBit(RSCRATCH);
    OR(64, R(RSCRATCH), Imm8(1));
    MOV(64, CROffset(field), R(RSCRATCH));
    break;

  case PowerPC::CR_GT_BIT:
    BTS(64, CROffset(field), Imm8(63));
    break;

  case PowerPC::CR_LT_BIT:
    BTR(64, CROffset(field), Imm8(PowerPC::CR_EMU_LT_BIT));
    break;
  }
  // We don't need to set bit 32; the cases where that's needed only come up when setting bits, not
  // clearing.
}

void Jit64::SetCRFieldBit(int field, int bit)
{
  MOV(64, R(RSCRATCH), CROffset(field));
  if (bit != PowerPC::CR_GT_BIT)
    FixGTBeforeSettingCRFieldBit(RSCRATCH);

  switch (bit)
  {
  case PowerPC::CR_SO_BIT:
    BTS(64, R(RSCRATCH), Imm8(PowerPC::CR_EMU_SO_BIT));
    break;

  case PowerPC::CR_EQ_BIT:
    SHR(64, R(RSCRATCH), Imm8(32));
    SHL(64, R(RSCRATCH), Imm8(32));
    break;

  case PowerPC::CR_GT_BIT:
    BTR(64, R(RSCRATCH), Imm8(63));
    break;

  case PowerPC::CR_LT_BIT:
    BTS(64, R(RSCRATCH), Imm8(PowerPC::CR_EMU_LT_BIT));
    break;
  }

  BTS(64, R(RSCRATCH), Imm8(32));
  MOV(64, CROffset(field), R(RSCRATCH));
}

void Jit64::FixGTBeforeSettingCRFieldBit(Gen::X64Reg reg)
{
  // GT is considered unset if the internal representation is <= 0, or in other words,
  // if the internal representation either has bit 63 set or has all bits set to zero.
  // If all bits are zero and we set some bit that's unrelated to GT, we need to set bit 63 so GT
  // doesn't accidentally become considered set. Gross but necessary; this can break actual games.
  TEST(64, R(reg), R(reg));
  FixupBranch dont_clear_gt = J_CC(CC_NZ);
  BTS(64, R(reg), Imm8(63));
  SetJumpTarget(dont_clear_gt);
}

FixupBranch Jit64::JumpIfCRFieldBit(int field, int bit, bool jump_if_set)
{
  switch (bit)
  {
  case PowerPC::CR_SO_BIT:  // check bit 59 set
    BT(64, CROffset(field), Imm8(PowerPC::CR_EMU_SO_BIT));
    return J_CC(jump_if_set ? CC_C : CC_NC, Jump::Near);

  case PowerPC::CR_EQ_BIT:  // check bits 31-0 == 0
    CMP(32, CROffset(field), Imm8(0));
    return J_CC(jump_if_set ? CC_Z : CC_NZ, Jump::Near);

  case PowerPC::CR_GT_BIT:  // check val > 0
    CMP(64, CROffset(field), Imm8(0));
    return J_CC(jump_if_set ? CC_G : CC_LE, Jump::Near);

  case PowerPC::CR_LT_BIT:  // check bit 62 set
    BT(64, CROffset(field), Imm8(PowerPC::CR_EMU_LT_BIT));
    return J_CC(jump_if_set ? CC_C : CC_NC, Jump::Near);

  default:
    ASSERT_MSG(DYNA_REC, false, "Invalid CR bit");
  }

  // Should never happen.
  return FixupBranch();
}

// Could be done with one temp register, but with two temp registers it's faster
void Jit64::mfcr(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  int d = inst.RD;

  RCX64Reg scratch_guard = gpr.Scratch(RSCRATCH_EXTRA);
  CALL(asm_routines.mfcr);

  RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
  RegCache::Realize(Rd);
  MOV(32, Rd, R(RSCRATCH));
}

void Jit64::mtcrf(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);

  // USES_CR
  u32 crm = inst.CRM;
  if (crm != 0)
  {
    if (gpr.IsImm(inst.RS))
    {
      for (int i = 0; i < 8; i++)
      {
        if ((crm & (0x80 >> i)) != 0)
        {
          u8 newcr = (gpr.Imm32(inst.RS) >> (28 - (i * 4))) & 0xF;
          u64 newcrval = PowerPC::ConditionRegister::PPCToInternal(newcr);
          if ((s64)newcrval == (s32)newcrval)
          {
            MOV(64, CROffset(i), Imm32((s32)newcrval));
          }
          else
          {
            MOV(64, R(RSCRATCH), Imm64(newcrval));
            MOV(64, CROffset(i), R(RSCRATCH));
          }
        }
      }
    }
    else
    {
      MOV(64, R(RSCRATCH2), ImmPtr(PowerPC::ConditionRegister::s_crTable.data()));
      RCX64Reg Rs = gpr.Bind(inst.RS, RCMode::Read);
      RegCache::Realize(Rs);
      for (int i = 0; i < 8; i++)
      {
        if ((crm & (0x80 >> i)) != 0)
        {
          MOV(32, R(RSCRATCH), Rs);
          if (i != 7)
            SHR(32, R(RSCRATCH), Imm8(28 - (i * 4)));
          if (i != 0)
            AND(32, R(RSCRATCH), Imm8(0xF));
          MOV(64, R(RSCRATCH), MComplex(RSCRATCH2, RSCRATCH, SCALE_8, 0));
          MOV(64, CROffset(i), R(RSCRATCH));
        }
      }
    }
  }
}

void Jit64::mcrf(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);

  // USES_CR
  if (inst.CRFS != inst.CRFD)
  {
    MOV(64, R(RSCRATCH), CROffset(inst.CRFS));
    MOV(64, CROffset(inst.CRFD), R(RSCRATCH));
  }
}

void Jit64::mcrxr(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);

  // Copy XER[0-3] into CR[inst.CRFD]
  MOVZX(32, 8, RSCRATCH, PPCSTATE(xer_ca));
  MOVZX(32, 8, RSCRATCH2, PPCSTATE(xer_so_ov));
  // [0 SO OV CA]
  LEA(32, RSCRATCH, MComplex(RSCRATCH, RSCRATCH2, SCALE_2, 0));
  // [SO OV CA 0] << 3
  SHL(32, R(RSCRATCH), Imm8(4));

  MOV(64, R(RSCRATCH2), ImmPtr(PowerPC::ConditionRegister::s_crTable.data()));
  MOV(64, R(RSCRATCH), MRegSum(RSCRATCH, RSCRATCH2));
  MOV(64, CROffset(inst.CRFD), R(RSCRATCH));

  // Clear XER[0-3]
  static_assert(PPCSTATE_OFF(xer_ca) + 1 == PPCSTATE_OFF(xer_so_ov));
  MOV(16, PPCSTATE(xer_ca), Imm16(0));
}

void Jit64::crXXX(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  DEBUG_ASSERT_MSG(DYNA_REC, inst.OPCD == 19, "Invalid crXXX");

  // TODO(merry): Further optimizations can be performed here. For example,
  // instead of extracting each CR field bit then setting it, the operation
  // could be performed on the internal format directly instead and the
  // relevant bit result can be masked out.

  if (inst.CRBA == inst.CRBB)
  {
    switch (inst.SUBOP10)
    {
    // crclr
    case 129:  // crandc: A && ~B => 0
    case 193:  // crxor:  A ^ B   => 0
      ClearCRFieldBit(inst.CRBD >> 2, 3 - (inst.CRBD & 3));
      return;

    // crset
    case 289:  // creqv: ~(A ^ B) => 1
    case 417:  // crorc: A || ~B  => 1
      SetCRFieldBit(inst.CRBD >> 2, 3 - (inst.CRBD & 3));
      return;

    case 257:  // crand: A && B => A
    case 449:  // cror:  A || B => A
      GetCRFieldBit(inst.CRBA >> 2, 3 - (inst.CRBA & 3), RSCRATCH, false);
      SetCRFieldBit(inst.CRBD >> 2, 3 - (inst.CRBD & 3), RSCRATCH);
      return;

    case 33:   // crnor:  ~(A || B) => ~A
    case 225:  // crnand: ~(A && B) => ~A
      GetCRFieldBit(inst.CRBA >> 2, 3 - (inst.CRBA & 3), RSCRATCH, true);
      SetCRFieldBit(inst.CRBD >> 2, 3 - (inst.CRBD & 3), RSCRATCH);
      return;
    }
  }

  // creqv or crnand or crnor
  bool negateA = inst.SUBOP10 == 289 || inst.SUBOP10 == 225 || inst.SUBOP10 == 33;
  // crandc or crorc or crnand or crnor
  bool negateB =
      inst.SUBOP10 == 129 || inst.SUBOP10 == 417 || inst.SUBOP10 == 225 || inst.SUBOP10 == 33;

  GetCRFieldBit(inst.CRBA >> 2, 3 - (inst.CRBA & 3), RSCRATCH, negateA);
  GetCRFieldBit(inst.CRBB >> 2, 3 - (inst.CRBB & 3), RSCRATCH2, negateB);

  // Compute combined bit
  switch (inst.SUBOP10)
  {
  case 33:   // crnor: ~(A || B) == (~A && ~B)
  case 129:  // crandc: A && ~B
  case 257:  // crand:  A && B
    AND(8, R(RSCRATCH), R(RSCRATCH2));
    break;

  case 193:  // crxor: A ^ B
  case 289:  // creqv: ~(A ^ B) = ~A ^ B
    XOR(8, R(RSCRATCH), R(RSCRATCH2));
    break;

  case 225:  // crnand: ~(A && B) == (~A || ~B)
  case 417:  // crorc: A || ~B
  case 449:  // cror:  A || B
    OR(8, R(RSCRATCH), R(RSCRATCH2));
    break;
  }

  // Store result bit in CRBD
  SetCRFieldBit(inst.CRBD >> 2, 3 - (inst.CRBD & 3), RSCRATCH);
}
