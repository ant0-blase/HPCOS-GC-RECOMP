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


void JitArm64::reg_imm(u32 d, u32 a, u32 value,
                       void (ARM64XEmitter::*op)(ARM64Reg, ARM64Reg, u64, ARM64Reg), bool Rc)
{
  gpr.BindToRegister(d, d == a);
  {
    auto WA = gpr.GetScopedReg();
    (this->*op)(gpr.R(d), gpr.R(a), value, WA);
  }

  if (Rc)
    ComputeRC0(gpr.R(d));
}

void JitArm64::arith_imm(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  u32 a = inst.RA, s = inst.RS;

  switch (inst.OPCD)
  {
  case 24:  // ori
  case 25:  // oris
  {
    const u32 immediate = inst.OPCD == 24 ? inst.UIMM : inst.UIMM << 16;
    reg_imm(a, s, immediate, &ARM64XEmitter::ORRI2R);
    break;
  }
  case 28:  // andi
    reg_imm(a, s, inst.UIMM, &ARM64XEmitter::ANDI2R, true);
    break;
  case 29:  // andis
    reg_imm(a, s, inst.UIMM << 16, &ARM64XEmitter::ANDI2R, true);
    break;
  case 26:  // xori
  case 27:  // xoris
  {
    const u32 immediate = inst.OPCD == 26 ? inst.UIMM : inst.UIMM << 16;
    reg_imm(a, s, immediate, &ARM64XEmitter::EORI2R);
    break;
  }
  }
}

void JitArm64::boolX(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, s = inst.RS, b = inst.RB;

  if (s == b)
  {
    if ((inst.SUBOP10 == 28 /* andx */) || (inst.SUBOP10 == 444 /* orx */))
    {
      if (a != s)
      {
        gpr.BindToRegister(a, false);
        MOV(gpr.R(a), gpr.R(s));
      }
      if (inst.Rc)
        ComputeRC0(gpr.R(a));
    }
    else if ((inst.SUBOP10 == 476 /* nandx */) || (inst.SUBOP10 == 124 /* norx */))
    {
      gpr.BindToRegister(a, a == s);
      MVN(gpr.R(a), gpr.R(s));
      if (inst.Rc)
        ComputeRC0(gpr.R(a));
    }
    else if ((inst.SUBOP10 == 412 /* orcx */) || (inst.SUBOP10 == 284 /* eqvx */))
    {
      gpr.SetImmediate(a, 0xFFFFFFFF);
      if (inst.Rc)
        ComputeRC0(gpr.GetImm(a));
    }
    else if ((inst.SUBOP10 == 60 /* andcx */) || (inst.SUBOP10 == 316 /* xorx */))
    {
      gpr.SetImmediate(a, 0);
      if (inst.Rc)
        ComputeRC0(gpr.GetImm(a));
    }
    else
    {
      PanicAlertFmt("WTF!");
    }
  }
  else if ((gpr.IsImm(s) && (gpr.GetImm(s) == 0 || gpr.GetImm(s) == 0xFFFFFFFF ||
                             LogicalImm(gpr.GetImm(s), GPRSize::B32))) ||
           (gpr.IsImm(b) && (gpr.GetImm(b) == 0 || gpr.GetImm(b) == 0xFFFFFFFF ||
                             LogicalImm(gpr.GetImm(b), GPRSize::B32))))
  {
    int i, j;
    if (gpr.IsImm(s))
    {
      i = s;
      j = b;
    }
    else
    {
      i = b;
      j = s;
    }

    bool complement_b = (inst.SUBOP10 == 60 /* andcx */) || (inst.SUBOP10 == 412 /* orcx */);
    const bool final_not = (inst.SUBOP10 == 476 /* nandx */) || (inst.SUBOP10 == 124 /* norx */);
    const bool is_and = (inst.SUBOP10 == 28 /* andx */) || (inst.SUBOP10 == 60 /* andcx */) ||
                        (inst.SUBOP10 == 476 /* nandx */);
    const bool is_or = (inst.SUBOP10 == 444 /* orx */) || (inst.SUBOP10 == 412 /* orcx */) ||
                       (inst.SUBOP10 == 124 /* norx */);
    const bool is_xor = (inst.SUBOP10 == 316 /* xorx */) || (inst.SUBOP10 == 284 /* eqvx */);

    u32 imm = gpr.GetImm(i);
    if ((complement_b && i == b) || (inst.SUBOP10 == 284 /* eqvx */))
    {
      imm = ~imm;
      complement_b = false;
    }

    const bool is_zero = imm == 0;
    const bool is_ones = imm == 0xFFFFFFFF;
    const auto log_imm = LogicalImm(imm, GPRSize::B32);

    if (is_xor)
    {
      if (is_zero)
      {
        if (a != j)
        {
          gpr.BindToRegister(a, false);
          MOV(gpr.R(a), gpr.R(j));
        }
      }
      else
      {
        gpr.BindToRegister(a, a == j);
        if (is_ones)
        {
          MVN(gpr.R(a), gpr.R(j));
        }
        else
        {
          EOR(gpr.R(a), gpr.R(j), log_imm);
        }
      }
      if (inst.Rc)
        ComputeRC0(gpr.R(a));
    }
    else if (is_and)
    {
      if (is_zero)
      {
        gpr.SetImmediate(a, final_not ? 0xFFFFFFFF : 0);
        if (inst.Rc)
          ComputeRC0(gpr.GetImm(a));
      }
      else if (is_ones)
      {
        if (final_not || complement_b)
        {
          gpr.BindToRegister(a, a == j);
          MVN(gpr.R(a), gpr.R(j));
        }
        else if (a != j)
        {
          gpr.BindToRegister(a, false);
          MOV(gpr.R(a), gpr.R(j));
        }
        if (inst.Rc)
          ComputeRC0(gpr.R(a));
      }
      else
      {
        if (!complement_b)
        {
          gpr.BindToRegister(a, a == j);
          AND(gpr.R(a), gpr.R(j), log_imm);
          if (final_not)
            MVN(gpr.R(a), gpr.R(a));
        }
        else
        {
          gpr.BindToRegister(a, (a == i) || (a == j));
          BIC(gpr.R(a), gpr.R(i), gpr.R(j));
        }
        if (inst.Rc)
          ComputeRC0(gpr.R(a));
      }
    }
    else if (is_or)
    {
      if (is_ones)
      {
        gpr.SetImmediate(a, final_not ? 0 : 0xFFFFFFFF);
        if (inst.Rc)
          ComputeRC0(gpr.GetImm(a));
      }
      else if (is_zero)
      {
        if (final_not || complement_b)
        {
          gpr.BindToRegister(a, a == j);
          MVN(gpr.R(a), gpr.R(j));
        }
        else if (a != j)
        {
          gpr.BindToRegister(a, false);
          MOV(gpr.R(a), gpr.R(j));
        }
        if (inst.Rc)
          ComputeRC0(gpr.R(a));
      }
      else
      {
        if (!complement_b)
        {
          gpr.BindToRegister(a, a == j);
          ORR(gpr.R(a), gpr.R(j), log_imm);
          if (final_not)
            MVN(gpr.R(a), gpr.R(a));
        }
        else
        {
          gpr.BindToRegister(a, (a == i) || (a == j));
          ORN(gpr.R(a), gpr.R(i), gpr.R(j));
        }
        if (inst.Rc)
          ComputeRC0(gpr.R(a));
      }
    }
    else
    {
      PanicAlertFmt("WTF!");
    }
  }
  else
  {
    gpr.BindToRegister(a, (a == s) || (a == b));
    if (inst.SUBOP10 == 28)  // andx
    {
      AND(gpr.R(a), gpr.R(s), gpr.R(b));
    }
    else if (inst.SUBOP10 == 476)  // nandx
    {
      AND(gpr.R(a), gpr.R(s), gpr.R(b));
      MVN(gpr.R(a), gpr.R(a));
    }
    else if (inst.SUBOP10 == 60)  // andcx
    {
      BIC(gpr.R(a), gpr.R(s), gpr.R(b));
    }
    else if (inst.SUBOP10 == 444)  // orx
    {
      ORR(gpr.R(a), gpr.R(s), gpr.R(b));
    }
    else if (inst.SUBOP10 == 124)  // norx
    {
      ORR(gpr.R(a), gpr.R(s), gpr.R(b));
      MVN(gpr.R(a), gpr.R(a));
    }
    else if (inst.SUBOP10 == 412)  // orcx
    {
      ORN(gpr.R(a), gpr.R(s), gpr.R(b));
    }
    else if (inst.SUBOP10 == 316)  // xorx
    {
      EOR(gpr.R(a), gpr.R(s), gpr.R(b));
    }
    else if (inst.SUBOP10 == 284)  // eqvx
    {
      EON(gpr.R(a), gpr.R(b), gpr.R(s));
    }
    else
    {
      PanicAlertFmt("WTF!");
    }
    if (inst.Rc)
      ComputeRC0(gpr.R(a));
  }
}

void JitArm64::extsXx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, s = inst.RS;
  int size = inst.SUBOP10 == 922 ? 16 : 8;

  gpr.BindToRegister(a, a == s);
  SBFM(gpr.R(a), gpr.R(s), 0, size - 1);
  if (inst.Rc)
    ComputeRC0(gpr.R(a));
}

void JitArm64::cntlzwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA;
  int s = inst.RS;

  gpr.BindToRegister(a, a == s);
  CLZ(gpr.R(a), gpr.R(s));
  if (inst.Rc)
    ComputeRC0(gpr.R(a));
}

void JitArm64::rlwinmx_internal(UGeckoInstruction inst, u32 sh)
{
  u32 a = inst.RA, s = inst.RS;
  const u32 mask = MakeRotationMask(inst.MB, inst.ME);

  if (mask == 0)
  {
    gpr.SetImmediate(a, 0);
    if (inst.Rc)
      ComputeRC0(0);
    return;
  }

  gpr.BindToRegister(a, a == s);

  if (sh == 0 && mask == 0xFFFFFFFF)
  {
    if (a != s)
      MOV(gpr.R(a), gpr.R(s));
  }
  else if (sh == 0)
  {
    AND(gpr.R(a), gpr.R(s), LogicalImm(mask, GPRSize::B32));
  }
  else if (mask == 0xFFFFFFFF)
  {
    ROR(gpr.R(a), gpr.R(s), 32 - sh);
  }
  else if (inst.ME == 31 && 31 < sh + inst.MB)
  {
    UBFX(gpr.R(a), gpr.R(s), 32 - sh, 32 - inst.MB);
  }
  else if (inst.ME == 31 - sh && 32 > sh + inst.MB)
  {
    UBFIZ(gpr.R(a), gpr.R(s), sh, 32 - sh - inst.MB);
  }
  else
  {
    auto WA = gpr.GetScopedReg();
    MOVI2R(WA, mask);
    AND(gpr.R(a), WA, gpr.R(s), ArithOption(gpr.R(s), ShiftType::ROR, 32 - sh));
  }

  if (inst.Rc)
    ComputeRC0(gpr.R(a));
}

void JitArm64::rlwinmx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  rlwinmx_internal(inst, inst.SH);
}

void JitArm64::rlwnmx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  const u32 a = inst.RA, b = inst.RB, s = inst.RS;

  if (gpr.IsImm(b))
  {
    rlwinmx_internal(inst, gpr.GetImm(b) & 0x1F);
    return;
  }

  const u32 mask = MakeRotationMask(inst.MB, inst.ME);

  gpr.BindToRegister(a, a == s || a == b);
  {
    auto WA = gpr.GetScopedReg();
    NEG(WA, gpr.R(b));
    RORV(gpr.R(a), gpr.R(s), WA);
    ANDI2R(gpr.R(a), gpr.R(a), mask, WA);
  }

  if (inst.Rc)
    ComputeRC0(gpr.R(a));
}

void JitArm64::srawix(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA;
  int s = inst.RS;
  int amount = inst.SH;
  bool inplace_carry = CanMergeNextInstructions(1) && js.op[1].wantsCAInFlags;

  if (amount == 0)
  {
    gpr.BindToRegister(a, a == s);
    ARM64Reg RA = gpr.R(a);
    ARM64Reg RS = gpr.R(s);
    MOV(RA, RS);
    ComputeCarry(false);

    if (inst.Rc)
      ComputeRC0(RA);
  }
  else
  {
    gpr.BindToRegister(a, a == s);
    ARM64Reg RA = gpr.R(a);
    ARM64Reg RS = gpr.R(s);

    if (js.op->wantsCA)
    {
      auto WA = gpr.GetScopedReg();
      ARM64Reg dest = inplace_carry ? ARM64Reg(WA) : ARM64Reg::WSP;
      if (a != s)
      {
        ASR(RA, RS, amount);
        ANDS(dest, RA, RS, ArithOption(RS, ShiftType::LSL, 32 - amount));
      }
      else
      {
        LSL(WA, RS, 32 - amount);
        ASR(RA, RS, amount);
        ANDS(dest, WA, RA);
      }
      if (inplace_carry)
      {
        CMP(dest, 1);
        ComputeCarry();
      }
      else
      {
        CSINC(WA, ARM64Reg::WSP, ARM64Reg::WSP, CC_EQ);
        ComputeCarry(WA);
      }
    }
    else
    {
      ASR(RA, RS, amount);
    }

    if (inst.Rc)
      ComputeRC0(RA);
  }
}

void JitArm64::slwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA, b = inst.RB, s = inst.RS;

  if (gpr.IsImm(b))
  {
    u32 i = gpr.GetImm(b);
    if (i & 0x20)
    {
      gpr.SetImmediate(a, 0);
      if (inst.Rc)
        ComputeRC0(0);
    }
    else
    {
      gpr.BindToRegister(a, a == s);
      LSL(gpr.R(a), gpr.R(s), i & 0x1F);
      if (inst.Rc)
        ComputeRC0(gpr.R(a));
    }
  }
  else
  {
    gpr.BindToRegister(a, a == b || a == s);

    LSLV(EncodeRegTo64(gpr.R(a)), EncodeRegTo64(gpr.R(s)), EncodeRegTo64(gpr.R(b)));
    if (inst.Rc)
      ComputeRC0(gpr.R(a));
    MOV(gpr.R(a), gpr.R(a));
  }
}

void JitArm64::srwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA, b = inst.RB, s = inst.RS;

  if (gpr.IsImm(b))
  {
    u32 amount = gpr.GetImm(b);
    if (amount & 0x20)
    {
      gpr.SetImmediate(a, 0);
      if (inst.Rc)
        ComputeRC0(0);
    }
    else
    {
      gpr.BindToRegister(a, a == s);
      LSR(gpr.R(a), gpr.R(s), amount & 0x1F);
      if (inst.Rc)
        ComputeRC0(gpr.R(a));
    }
  }
  else
  {
    gpr.BindToRegister(a, a == b || a == s);

    LSRV(EncodeRegTo64(gpr.R(a)), EncodeRegTo64(gpr.R(s)), EncodeRegTo64(gpr.R(b)));

    if (inst.Rc)
      ComputeRC0(gpr.R(a));
  }
}

void JitArm64::srawx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  int a = inst.RA, b = inst.RB, s = inst.RS;

  if (gpr.IsImm(b))
  {
    int amount = gpr.GetImm(b);

    bool special = amount & 0x20;
    amount &= 0x1f;

    if (special)
    {
      gpr.BindToRegister(a, a == s);

      if (js.op->wantsCA)
      {
        CMN(gpr.R(s), gpr.R(s));
        ComputeCarry();
      }

      ASR(gpr.R(a), gpr.R(s), 31);
    }
    else if (amount == 0)
    {
      if (a != s)
      {
        gpr.BindToRegister(a, false);

        MOV(gpr.R(a), gpr.R(s));
      }

      ComputeCarry(false);
    }
    else if (!js.op->wantsCA)
    {
      gpr.BindToRegister(a, a == s);

      ASR(gpr.R(a), gpr.R(s), amount);
    }
    else
    {
      gpr.BindToRegister(a, a == s);
      auto WA = gpr.GetScopedReg();

      if (a != s)
      {
        ASR(gpr.R(a), gpr.R(s), amount);
        TST(gpr.R(a), gpr.R(s), ArithOption(gpr.R(s), ShiftType::LSL, 32 - amount));
      }
      else
      {
        LSL(WA, gpr.R(s), 32 - amount);
        ASR(gpr.R(a), gpr.R(s), amount);
        TST(WA, gpr.R(a));
      }

      CSET(WA, CC_NEQ);
      ComputeCarry(WA);
    }
  }
  else
  {
    const bool will_read = a == b || a == s;
    gpr.BindToRegister(a, will_read);

    auto WA =
        will_read || js.op->wantsCA ? gpr.GetScopedReg() : Arm64GPRCache::ScopedARM64Reg(gpr.R(a));

    LSL(EncodeRegTo64(WA), EncodeRegTo64(gpr.R(s)), 32);
    ASRV(EncodeRegTo64(WA), EncodeRegTo64(WA), EncodeRegTo64(gpr.R(b)));
    LSR(EncodeRegTo64(gpr.R(a)), EncodeRegTo64(WA), 32);

    if (js.op->wantsCA)
    {
      TST(gpr.R(a), WA);
      CSET(WA, CC_NEQ);
      ComputeCarry(WA);
    }
  }

  if (inst.Rc)
    ComputeRC0(gpr.R(a));
}

void JitArm64::rlwimix(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);

  const int a = inst.RA, s = inst.RS;
  const u32 mask = MakeRotationMask(inst.MB, inst.ME);

  const u32 lsb = 31 - inst.ME;
  const u32 width = inst.ME - inst.MB + 1;
  const u32 rot_dist = inst.SH ? 32 - inst.SH : 0;

  if (mask == 0 || (a == s && inst.SH == 0))
  {
    // Do Nothing
  }
  else if (mask == 0xFFFFFFFF)
  {
    if (inst.SH || a != s)
      gpr.BindToRegister(a, a == s);

    if (inst.SH)
      ROR(gpr.R(a), gpr.R(s), rot_dist);
    else if (a != s)
      MOV(gpr.R(a), gpr.R(s));
  }
  else if (lsb == 0 && inst.MB <= inst.ME && rot_dist + width <= 32)
  {
    gpr.BindToRegister(a, true);
    BFXIL(gpr.R(a), gpr.R(s), rot_dist, width);
  }
  else if (inst.SH == 0 && inst.MB <= inst.ME)
  {
    gpr.BindToRegister(a, true);
    auto WA = gpr.GetScopedReg();
    UBFX(WA, gpr.R(s), lsb, width);
    BFI(gpr.R(a), WA, lsb, width);
  }
  else if (inst.SH && inst.MB <= inst.ME)
  {
    gpr.BindToRegister(a, true);
    if ((rot_dist + lsb) % 32 == 0)
    {
      BFI(gpr.R(a), gpr.R(s), lsb, width);
    }
    else
    {
      auto WA = gpr.GetScopedReg();
      ROR(WA, gpr.R(s), (rot_dist + lsb) % 32);
      BFI(gpr.R(a), WA, lsb, width);
    }
  }
  else
  {
    gpr.BindToRegister(a, true);
    ARM64Reg RA = gpr.R(a);
    auto WA = gpr.GetScopedReg();
    const u32 inverted_mask = ~mask;

    AND(WA, gpr.R(s), LogicalImm(std::rotl(mask, rot_dist), GPRSize::B32));
    AND(RA, RA, LogicalImm(inverted_mask, GPRSize::B32));
    ORR(RA, RA, WA, ArithOption(WA, ShiftType::ROR, rot_dist));
  }

  if (inst.Rc)
    ComputeRC0(gpr.R(a));
}
