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

namespace
{
constexpr u32 MakeRotationMask(u32 mb, u32 me)
{
  u32 mask = 0xFFFFFFFF;
  if (mb <= me)
  {
    mask = (mask >> mb) & (mask << (31 - me));
  }
  else
  {
    mask = (mask >> mb) | (mask << (31 - me));
  }
  return mask;
}
}  // namespace

void Jit64::boolX(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, s = inst.RS, b = inst.RB;
  bool needs_test = false;
  DEBUG_ASSERT_MSG(DYNA_REC, inst.OPCD == 31, "Invalid boolX");

  if (gpr.IsImm(s) || gpr.IsImm(b))
  {
    const auto [i, j] = gpr.IsImm(s) ? std::pair(s, b) : std::pair(b, s);
    u32 imm = gpr.Imm32(i);

    bool complement_b = (inst.SUBOP10 == 60 /* andcx */) || (inst.SUBOP10 == 412 /* orcx */);
    const bool final_not = (inst.SUBOP10 == 476 /* nandx */) || (inst.SUBOP10 == 124 /* norx */);
    const bool is_and = (inst.SUBOP10 == 28 /* andx */) || (inst.SUBOP10 == 60 /* andcx */) ||
                        (inst.SUBOP10 == 476 /* nandx */);
    const bool is_or = (inst.SUBOP10 == 444 /* orx */) || (inst.SUBOP10 == 412 /* orcx */) ||
                       (inst.SUBOP10 == 124 /* norx */);
    const bool is_xor = (inst.SUBOP10 == 316 /* xorx */) || (inst.SUBOP10 == 284 /* eqvx */);

    if ((complement_b && gpr.IsImm(b)) || (inst.SUBOP10 == 284 /* eqvx */))
    {
      imm = ~imm;
      complement_b = false;
    }

    if (is_xor)
    {
      RCOpArg Rj = gpr.Use(j, RCMode::Read);
      RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
      RegCache::Realize(Rj, Ra);
      if (imm == 0)
      {
        if (a != j)
          MOV(32, Ra, Rj);
        needs_test = true;
      }
      else if (imm == 0xFFFFFFFF && !inst.Rc)
      {
        if (a != j)
          MOV(32, Ra, Rj);
        NOT(32, Ra);
      }
      else if (a == j)
      {
        XOR(32, Ra, Imm32(imm));
      }
      else if (s32(imm) >= -128 && s32(imm) <= 127)
      {
        MOV(32, Ra, Rj);
        XOR(32, Ra, Imm32(imm));
      }
      else
      {
        MOV(32, Ra, Imm32(imm));
        XOR(32, Ra, Rj);
      }
    }
    else if (is_and)
    {
      RCOpArg Rj = gpr.Use(j, RCMode::Read);
      RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
      RegCache::Realize(Rj, Ra);

      if (imm == 0xFFFFFFFF)
      {
        if (a != j)
          MOV(32, Ra, Rj);
        if (final_not || complement_b)
          NOT(32, Ra);
        needs_test = true;
      }
      else if (complement_b)
      {
        if (a != j)
          MOV(32, Ra, Rj);
        NOT(32, Ra);
        AND(32, Ra, Imm32(imm));
      }
      else
      {
        if (a == j)
        {
          AND(32, Ra, Imm32(imm));
        }
        else if (s32(imm) >= -128 && s32(imm) <= 127)
        {
          MOV(32, Ra, Rj);
          AND(32, Ra, Imm32(imm));
        }
        else
        {
          MOV(32, Ra, Imm32(imm));
          AND(32, Ra, Rj);
        }

        if (final_not)
        {
          NOT(32, Ra);
          needs_test = true;
        }
      }
    }
    else if (is_or)
    {
      RCOpArg Rj = gpr.Use(j, RCMode::Read);
      RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
      RegCache::Realize(Rj, Ra);

      if (imm == 0)
      {
        if (a != j)
          MOV(32, Ra, Rj);
        if (final_not || complement_b)
          NOT(32, Ra);
        needs_test = true;
      }
      else if (complement_b)
      {
        if (a != j)
          MOV(32, Ra, Rj);
        NOT(32, Ra);
        OR(32, Ra, Imm32(imm));
      }
      else
      {
        if (a == j)
        {
          OR(32, Ra, Imm32(imm));
        }
        else if (s32(imm) >= -128 && s32(imm) <= 127)
        {
          MOV(32, Ra, Rj);
          OR(32, Ra, Imm32(imm));
        }
        else
        {
          MOV(32, Ra, Imm32(imm));
          OR(32, Ra, Rj);
        }

        if (final_not)
        {
          NOT(32, Ra);
          needs_test = true;
        }
      }
    }
    else
    {
      PanicAlertFmt("WTF!");
    }
  }
  else if (s == b)
  {
    if ((inst.SUBOP10 == 28 /* andx */) || (inst.SUBOP10 == 444 /* orx */))
    {
      if (a != s)
      {
        RCOpArg Rs = gpr.Use(s, RCMode::Read);
        RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
        RegCache::Realize(Rs, Ra);
        MOV(32, Ra, Rs);
      }
      else if (inst.Rc)
      {
        gpr.Bind(a, RCMode::Read).Realize();
      }
      needs_test = true;
    }
    else if ((inst.SUBOP10 == 476 /* nandx */) || (inst.SUBOP10 == 124 /* norx */))
    {
      if (a == s && !inst.Rc)
      {
        RCOpArg Ra = gpr.UseNoImm(a, RCMode::ReadWrite);
        RegCache::Realize(Ra);
        NOT(32, Ra);
      }
      else
      {
        RCOpArg Rs = gpr.Use(s, RCMode::Read);
        RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
        RegCache::Realize(Rs, Ra);
        MOV(32, Ra, Rs);
        NOT(32, Ra);
      }
      needs_test = true;
    }
    else if ((inst.SUBOP10 == 412 /* orcx */) || (inst.SUBOP10 == 284 /* eqvx */))
    {
      gpr.SetImmediate32(a, 0xFFFFFFFF);
    }
    else if ((inst.SUBOP10 == 60 /* andcx */) || (inst.SUBOP10 == 316 /* xorx */))
    {
      gpr.SetImmediate32(a, 0);
    }
    else
    {
      PanicAlertFmt("WTF!");
    }
  }
  else if ((a == s) || (a == b))
  {
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RCOpArg operand = gpr.Use(a == s ? b : s, RCMode::Read);
    RCX64Reg Ra = gpr.Bind(a, RCMode::ReadWrite);
    RegCache::Realize(Rb, Rs, operand, Ra);

    if (inst.SUBOP10 == 28)  // andx
    {
      AND(32, Ra, operand);
    }
    else if (inst.SUBOP10 == 476)  // nandx
    {
      AND(32, Ra, operand);
      NOT(32, Ra);
      needs_test = true;
    }
    else if (inst.SUBOP10 == 60)  // andcx
    {
      if (cpu_info.bBMI1 && Rb.IsSimpleReg())
      {
        ANDN(32, Ra, Rb.GetSimpleReg(), Rs);
      }
      else if (a == b)
      {
        NOT(32, Ra);
        AND(32, Ra, operand);
      }
      else
      {
        MOV(32, R(RSCRATCH), operand);
        NOT(32, R(RSCRATCH));
        AND(32, Ra, R(RSCRATCH));
      }
    }
    else if (inst.SUBOP10 == 444)  // orx
    {
      OR(32, Ra, operand);
    }
    else if (inst.SUBOP10 == 124)  // norx
    {
      OR(32, Ra, operand);
      NOT(32, Ra);
      needs_test = true;
    }
    else if (inst.SUBOP10 == 412)  // orcx
    {
      if (a == b)
      {
        NOT(32, Ra);
        OR(32, Ra, operand);
      }
      else
      {
        MOV(32, R(RSCRATCH), operand);
        NOT(32, R(RSCRATCH));
        OR(32, Ra, R(RSCRATCH));
      }
    }
    else if (inst.SUBOP10 == 316)  // xorx
    {
      XOR(32, Ra, operand);
    }
    else if (inst.SUBOP10 == 284)  // eqvx
    {
      NOT(32, Ra);
      XOR(32, Ra, operand);
    }
    else
    {
      PanicAlertFmt("WTF");
    }
  }
  else
  {
    RCOpArg Rb = gpr.Use(b, RCMode::Read);
    RCOpArg Rs = gpr.Use(s, RCMode::Read);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RegCache::Realize(Rb, Rs, Ra);

    if (inst.SUBOP10 == 28)  // andx
    {
      MOV(32, Ra, Rs);
      AND(32, Ra, Rb);
    }
    else if (inst.SUBOP10 == 476)  // nandx
    {
      MOV(32, Ra, Rs);
      AND(32, Ra, Rb);
      NOT(32, Ra);
      needs_test = true;
    }
    else if (inst.SUBOP10 == 60)  // andcx
    {
      if (cpu_info.bBMI1 && Rb.IsSimpleReg())
      {
        ANDN(32, Ra, Rb.GetSimpleReg(), Rs);
      }
      else
      {
        MOV(32, Ra, Rb);
        NOT(32, Ra);
        AND(32, Ra, Rs);
      }
    }
    else if (inst.SUBOP10 == 444)  // orx
    {
      MOV(32, Ra, Rs);
      OR(32, Ra, Rb);
    }
    else if (inst.SUBOP10 == 124)  // norx
    {
      MOV(32, Ra, Rs);
      OR(32, Ra, Rb);
      NOT(32, Ra);
      needs_test = true;
    }
    else if (inst.SUBOP10 == 412)  // orcx
    {
      MOV(32, Ra, Rb);
      NOT(32, Ra);
      OR(32, Ra, Rs);
    }
    else if (inst.SUBOP10 == 316)  // xorx
    {
      MOV(32, Ra, Rs);
      XOR(32, Ra, Rb);
    }
    else if (inst.SUBOP10 == 284)  // eqvx
    {
      MOV(32, Ra, Rs);
      NOT(32, Ra);
      XOR(32, Ra, Rb);
    }
    else
    {
      PanicAlertFmt("WTF!");
    }
  }
  if (inst.Rc)
    ComputeRC(a, needs_test);
}

void Jit64::extsXx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, s = inst.RS;
  int size = inst.SUBOP10 == 922 ? 16 : 8;

  {
    RCOpArg Rs = gpr.UseNoImm(s, RCMode::Read);
    RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
    RegCache::Realize(Rs, Ra);
    MOVSX(32, size, Ra, Rs);
  }
  if (inst.Rc)
    ComputeRC(a);
}

void Jit64::cntlzwx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITIntegerOff);
  int a = inst.RA, s = inst.RS;

  RCOpArg Rs = gpr.Use(s, RCMode::Read);
  RCX64Reg Ra = gpr.Bind(a, RCMode::Write);
  RegCache::Realize(Rs, Ra);

  if (cpu_info.bLZCNT)
  {
    LZCNT(32, Ra, Rs);
  }
  else
  {
    BSR(32, Ra, Rs);
    FixupBranch j_not_zero = J_CC(CC_NZ);
    MOV(32, Ra, Imm32(63));
    SetJumpTarget(j_not_zero);
    XOR(32, Ra, Imm32(31));
  }
  if (inst.Rc)
    ComputeRC(a, false);
}
