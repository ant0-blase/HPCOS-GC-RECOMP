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

void Jit64::UpdateFPExceptionSummary(X64Reg fpscr, X64Reg tmp1, X64Reg tmp2)
{
  // Kill dependency on tmp1 (not required for correctness, since SHL will shift out upper bytes)
  XOR(32, R(tmp1), R(tmp1));

  // fpscr.VX = (fpscr & FPSCR_VX_ANY) != 0
  TEST(32, R(fpscr), Imm32(FPSCR_VX_ANY));
  SETcc(CC_NZ, R(tmp1));
  SHL(32, R(tmp1), Imm8(MathUtil::IntLog2(FPSCR_VX)));
  AND(32, R(fpscr), Imm32(~(FPSCR_VX | FPSCR_FEX)));
  OR(32, R(fpscr), R(tmp1));

  // fpscr.FEX = ((fpscr >> 22) & (fpscr & FPSCR_ANY_E)) != 0
  MOV(32, R(tmp1), R(fpscr));
  MOV(32, R(tmp2), R(fpscr));
  SHR(32, R(tmp1), Imm8(22));
  AND(32, R(tmp2), Imm32(FPSCR_ANY_E));
  TEST(32, R(tmp1), R(tmp2));
  // Unfortunately we eat a partial register stall below - we can't zero any of the registers before
  // the TEST, and we can't use XOR right after the TEST since that would overwrite flags. However,
  // there is no false dependency, since SETcc depends on TEST's flags and TEST depends on tmp1.
  SETcc(CC_NZ, R(tmp1));
  SHL(32, R(tmp1), Imm8(MathUtil::IntLog2(FPSCR_FEX)));
  OR(32, R(fpscr), R(tmp1));
}

void Jit64::mcrfs(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);

  u8 shift = 4 * (7 - inst.CRFS);
  u32 mask = 0xF << shift;

  // Only clear exception bits (but not FEX/VX).
  mask &= FPSCR_FX | FPSCR_ANY_X;

  RCX64Reg scratch_guard;
  X64Reg scratch;
  if (mask != 0)
  {
    scratch_guard = gpr.Scratch();
    RegCache::Realize(scratch_guard);
    scratch = scratch_guard;
  }
  else
  {
    scratch = RSCRATCH;
  }

  if (cpu_info.bBMI1)
  {
    MOV(32, R(RSCRATCH), PPCSTATE(fpscr));
    MOV(32, R(RSCRATCH2), Imm32((4 << 8) | shift));
    BEXTR(32, RSCRATCH2, R(RSCRATCH), RSCRATCH2);
  }
  else
  {
    MOV(32, R(RSCRATCH2), PPCSTATE(fpscr));
    if (mask != 0)
      MOV(32, R(RSCRATCH), R(RSCRATCH2));

    SHR(32, R(RSCRATCH2), Imm8(shift));
    AND(32, R(RSCRATCH2), Imm32(0xF));
  }

  LEA(64, scratch, MConst(PowerPC::ConditionRegister::s_crTable));
  MOV(64, R(scratch), MComplex(scratch, RSCRATCH2, SCALE_8, 0));
  MOV(64, CROffset(inst.CRFD), R(scratch));

  if (mask != 0)
  {
    AND(32, R(RSCRATCH), Imm32(~mask));
    UpdateFPExceptionSummary(RSCRATCH, RSCRATCH2, scratch);
    MOV(32, PPCSTATE(fpscr), R(RSCRATCH));
  }
}

void Jit64::mffsx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  FALLBACK_IF(inst.Rc);

  MOV(32, R(RSCRATCH), PPCSTATE(fpscr));

  int d = inst.FD;
  RCX64Reg Rd = fpr.Bind(d, RCMode::Write);
  RegCache::Realize(Rd);
  MOV(64, R(RSCRATCH2), Imm64(0xFFF8000000000000));
  OR(64, R(RSCRATCH), R(RSCRATCH2));
  MOVQ_xmm(XMM0, R(RSCRATCH));
  MOVSD(Rd, R(XMM0));
}

// MXCSR = s_fpscr_to_mxcsr[FPSCR & 7]
static const u32 s_fpscr_to_mxcsr[8] = {
    0x1F80, 0x7F80, 0x5F80, 0x3F80, 0x9F80, 0xFF80, 0xDF80, 0xBF80,
};

// Needs value of FPSCR in RSCRATCH.
void Jit64::UpdateMXCSR()
{
  LEA(64, RSCRATCH2, MConst(s_fpscr_to_mxcsr));
  AND(32, R(RSCRATCH), Imm32(7));
  LDMXCSR(MComplex(RSCRATCH2, RSCRATCH, SCALE_4, 0));
}

void Jit64::mtfsb0x(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  FALLBACK_IF(inst.Rc);

  const u32 mask = 0x80000000 >> inst.CRBD;
  const u32 inverted_mask = ~mask;

  if (mask == FPSCR_FEX || mask == FPSCR_VX)
    return;

  if (inst.CRBD < 29 && (mask & (FPSCR_ANY_X | FPSCR_ANY_E)) == 0)
  {
    AND(32, PPCSTATE(fpscr), Imm32(inverted_mask));
  }
  else
  {
    MOV(32, R(RSCRATCH), PPCSTATE(fpscr));
    AND(32, R(RSCRATCH), Imm32(inverted_mask));

    if ((mask & (FPSCR_ANY_X | FPSCR_ANY_E)) != 0)
    {
      RCX64Reg scratch = gpr.Scratch();
      RegCache::Realize(scratch);

      UpdateFPExceptionSummary(RSCRATCH, RSCRATCH2, scratch);
    }

    MOV(32, PPCSTATE(fpscr), R(RSCRATCH));
    if (inst.CRBD >= 29)
      UpdateMXCSR();
  }
}

void Jit64::mtfsb1x(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  FALLBACK_IF(inst.Rc);
  FALLBACK_IF(jo.fp_exceptions);

  const u32 mask = 0x80000000 >> inst.CRBD;

  if (mask == FPSCR_FEX || mask == FPSCR_VX)
    return;

  MOV(32, R(RSCRATCH), PPCSTATE(fpscr));
  if ((mask & FPSCR_ANY_X) != 0)
  {
    BTS(32, R(RSCRATCH), Imm32(31 - inst.CRBD));
    FixupBranch dont_set_fx = J_CC(CC_C);
    OR(32, R(RSCRATCH), Imm32(1u << 31));
    SetJumpTarget(dont_set_fx);
  }
  else
  {
    OR(32, R(RSCRATCH), Imm32(mask));
  }

  if ((mask & (FPSCR_ANY_X | FPSCR_ANY_E)) != 0)
  {
    RCX64Reg scratch = gpr.Scratch();
    RegCache::Realize(scratch);

    UpdateFPExceptionSummary(RSCRATCH, RSCRATCH2, scratch);
  }

  MOV(32, PPCSTATE(fpscr), R(RSCRATCH));
  if (inst.CRBD >= 29)
    UpdateMXCSR();
}

void Jit64::mtfsfix(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  FALLBACK_IF(inst.Rc);
  FALLBACK_IF(jo.fp_exceptions);

  u8 imm = (inst.hex >> (31 - 19)) & 0xF;
  u32 mask = 0xF0000000 >> (4 * inst.CRFD);
  u32 or_mask = imm << (28 - 4 * inst.CRFD);
  u32 and_mask = ~mask;

  MOV(32, R(RSCRATCH), PPCSTATE(fpscr));
  AND(32, R(RSCRATCH), Imm32(and_mask));
  OR(32, R(RSCRATCH), Imm32(or_mask));

  if ((mask & (FPSCR_FEX | FPSCR_VX | FPSCR_ANY_X | FPSCR_ANY_E)) != 0)
  {
    RCX64Reg scratch = gpr.Scratch();
    RegCache::Realize(scratch);

    UpdateFPExceptionSummary(RSCRATCH, RSCRATCH2, scratch);
  }

  MOV(32, PPCSTATE(fpscr), R(RSCRATCH));

  // Field 7 contains NI and RN.
  if (inst.CRFD == 7)
    LDMXCSR(MConst(s_fpscr_to_mxcsr, imm & 7));
}

void Jit64::mtfsfx(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  FALLBACK_IF(inst.Rc);
  FALLBACK_IF(jo.fp_exceptions);

  u32 mask = 0;
  for (int i = 0; i < 8; i++)
  {
    if (inst.FM & (1 << i))
      mask |= 0xF << (4 * i);
  }

  int b = inst.FB;

  RCOpArg Rb = fpr.Use(b, RCMode::Read);
  RegCache::Realize(Rb);

  if (Rb.IsSimpleReg())
    MOVQ_xmm(R(RSCRATCH), Rb.GetSimpleReg());
  else
    MOV(32, R(RSCRATCH), Rb);

  if (mask != 0xFFFFFFFF)
  {
    MOV(32, R(RSCRATCH2), PPCSTATE(fpscr));
    AND(32, R(RSCRATCH), Imm32(mask));
    AND(32, R(RSCRATCH2), Imm32(~mask));
    OR(32, R(RSCRATCH), R(RSCRATCH2));
  }

  if ((mask & (FPSCR_FEX | FPSCR_VX | FPSCR_ANY_X | FPSCR_ANY_E)) != 0)
  {
    RCX64Reg scratch = gpr.Scratch();
    RegCache::Realize(scratch);

    UpdateFPExceptionSummary(RSCRATCH, RSCRATCH2, scratch);
  }

  MOV(32, PPCSTATE(fpscr), R(RSCRATCH));

  if (inst.FM & 1)
    UpdateMXCSR();
}
