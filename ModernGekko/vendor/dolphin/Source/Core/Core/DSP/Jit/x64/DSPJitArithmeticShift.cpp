// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

// Additional copyrights go to Duddie and Tratax (c) 2004

#include "Core/DSP/Jit/x64/DSPEmitter.h"

#include "Common/CommonTypes.h"
#include "Core/DSP/DSPCore.h"

using namespace Gen;

namespace DSP::JIT::x64
{
// LSL16 $acR
// 1111 000r xxxx xxxx
// Logically shifts left accumulator $acR by 16.
//
// flags out: --xx xx00
void DSPEmitter::lsl16(const UDSPInstruction opc)
{
  u8 areg = (opc >> 8) & 0x1;
  //	s64 acc = dsp_get_long_acc(areg);
  get_long_acc(areg);
  //	acc <<= 16;
  SHL(64, R(RAX), Imm8(16));
  //	dsp_set_long_acc(areg, acc);
  set_long_acc(areg);
  //	Update_SR_Register64(dsp_get_long_acc(areg));
  if (FlagsNeeded())
  {
    Update_SR_Register64();
  }
}

// LSR16 $acR
// 1111 010r xxxx xxxx
// Logically shifts right accumulator $acR by 16.
//
// flags out: --xx xx00
void DSPEmitter::lsr16(const UDSPInstruction opc)
{
  u8 areg = (opc >> 8) & 0x1;

  //	u64 acc = dsp_get_long_acc(areg);
  get_long_acc(areg);
  //	acc &= 0x000000FFFFFFFFFFULL; 	// Lop off the extraneous sign extension our 64-bit fake accum
  // causes
  //	acc >>= 16;
  SHR(64, R(RAX), Imm8(16));
  AND(32, R(EAX), Imm32(0xffffff));
  //	dsp_set_long_acc(areg, (s64)acc);
  set_long_acc(areg);
  //	Update_SR_Register64(dsp_get_long_acc(areg));
  if (FlagsNeeded())
  {
    Update_SR_Register64();
  }
}

// ASR16 $acR
// 1001 r001 xxxx xxxx
// Arithmetically shifts right accumulator $acR by 16.
//
// flags out: --xx xx00
void DSPEmitter::asr16(const UDSPInstruction opc)
{
  u8 areg = (opc >> 11) & 0x1;

  //	s64 acc = dsp_get_long_acc(areg);
  get_long_acc(areg);
  //	acc >>= 16;
  SAR(64, R(RAX), Imm8(16));
  //	dsp_set_long_acc(areg, acc);
  set_long_acc(areg);
  //	Update_SR_Register64(dsp_get_long_acc(areg));
  if (FlagsNeeded())
  {
    Update_SR_Register64();
  }
}

// LSL $acR, #I
// 0001 010r 00ii iiii
// Logically shifts left accumulator $acR by number specified by value I.
//
// flags out: --xx xx00
void DSPEmitter::lsl(const UDSPInstruction opc)
{
  u8 rreg = (opc >> 8) & 0x01;
  u16 shift = opc & 0x3f;
  //	u64 acc = dsp_get_long_acc(rreg);
  get_long_acc(rreg);

  //	acc <<= shift;
  SHL(64, R(RAX), Imm8((u8)shift));

  //	dsp_set_long_acc(rreg, acc);
  set_long_acc(rreg);
  //	Update_SR_Register64(dsp_get_long_acc(rreg));
  if (FlagsNeeded())
  {
    Update_SR_Register64();
  }
}

// LSR $acR, #I
// 0001 010r 01ii iiii
// Logically shifts right accumulator $acR by number specified by value
// calculated by negating sign extended bits 0-6.
//
// flags out: --xx xx00
void DSPEmitter::lsr(const UDSPInstruction opc)
{
  u8 rreg = (opc >> 8) & 0x01;
  u16 shift;
  //	u64 acc = dsp_get_long_acc(rreg);
  get_long_acc(rreg);

  if ((opc & 0x3f) == 0)
    shift = 0;
  else
    shift = 0x40 - (opc & 0x3f);

  if (shift)
  {
    //	acc &= 0x000000FFFFFFFFFFULL; 	// Lop off the extraneous sign extension our 64-bit fake
    // accum causes
    SHL(64, R(RAX), Imm8(24));
    //	acc >>= shift;
    SHR(64, R(RAX), Imm8(shift + 24));
  }

  //	dsp_set_long_acc(rreg, (s64)acc);
  set_long_acc(rreg);
  //	Update_SR_Register64(dsp_get_long_acc(rreg));
  if (FlagsNeeded())
  {
    Update_SR_Register64();
  }
}

// ASL $acR, #I
// 0001 010r 10ii iiii
// Logically shifts left accumulator $acR by number specified by value I.
//
// flags out: --xx xx00
void DSPEmitter::asl(const UDSPInstruction opc)
{
  u8 rreg = (opc >> 8) & 0x01;
  u16 shift = opc & 0x3f;
  //	u64 acc = dsp_get_long_acc(rreg);
  get_long_acc(rreg);
  //	acc <<= shift;
  SHL(64, R(RAX), Imm8((u8)shift));
  //	dsp_set_long_acc(rreg, acc);
  set_long_acc(rreg);
  //	Update_SR_Register64(dsp_get_long_acc(rreg));
  if (FlagsNeeded())
  {
    Update_SR_Register64();
  }
}

// ASR $acR, #I
// 0001 010r 11ii iiii
// Arithmetically shifts right accumulator $acR by number specified by
// value calculated by negating sign extended bits 0-6.
//
// flags out: --xx xx00
void DSPEmitter::asr(const UDSPInstruction opc)
{
  u8 dreg = (opc >> 8) & 0x01;
  u16 shift;

  if ((opc & 0x3f) == 0)
    shift = 0;
  else
    shift = 0x40 - (opc & 0x3f);

  // arithmetic shift
  //	s64 acc = dsp_get_long_acc(dreg);
  get_long_acc(dreg);
  //	acc >>= shift;
  SAR(64, R(RAX), Imm8((u8)shift));

  //	dsp_set_long_acc(dreg, acc);
  set_long_acc(dreg);
  //	Update_SR_Register64(dsp_get_long_acc(dreg));
  if (FlagsNeeded())
  {
    Update_SR_Register64();
  }
}

// LSRN  (fixed parameters)
// 0000 0010 1100 1010
// Logically shifts right accumulator $ACC0 by lower 7-bit (signed) value in $AC1.M
// (if value negative, becomes left shift).
//
// flags out: --xx xx00
void DSPEmitter::lsrn(const UDSPInstruction opc)
{
  //	s16 shift;
  //	u16 accm = (u16)dsp_get_acc_m(1);
  get_acc_m(1);
  //	u64 acc = dsp_get_long_acc(0);
  get_long_acc(0, RDX);
  //	acc &= 0x000000FFFFFFFFFFULL;
  SHL(64, R(RDX), Imm8(24));
  SHR(64, R(RDX), Imm8(24));

  //	if ((accm & 0x3f) == 0)
  //		shift = 0;
  //	else if (accm & 0x40)
  //		shift = -0x40 + (accm & 0x3f);
  //	else
  //		shift = accm & 0x3f;

  //	if (shift > 0)
  //	{
  //		acc >>= shift;
  //	}
  //	else if (shift < 0)
  //	{
  //		acc <<= -shift;
  //	}

  TEST(64, R(RDX), R(RDX));  // is this actually worth the branch cost?
  FixupBranch zero = J_CC(CC_E);
  TEST(16, R(RAX), Imm16(0x3f));  // is this actually worth the branch cost?
  FixupBranch noShift = J_CC(CC_Z);
  // CL gets automatically masked with 0x3f on IA32/AMD64
  // MOVZX(64, 16, RCX, R(RAX));
  MOV(64, R(RCX), R(RAX));
  // AND(16, R(RCX), Imm16(0x3f));
  TEST(16, R(RAX), Imm16(0x40));
  FixupBranch shiftLeft = J_CC(CC_Z);
  NEG(16, R(RCX));
  // ADD(16, R(RCX), Imm16(0x40));
  SHL(64, R(RDX), R(RCX));
  FixupBranch exit = J();
  SetJumpTarget(shiftLeft);
  SHR(64, R(RDX), R(RCX));
  SetJumpTarget(noShift);
  SetJumpTarget(exit);

  //	dsp_set_long_acc(0, (s64)acc);
  set_long_acc(0, RDX);
  SetJumpTarget(zero);
  //	Update_SR_Register64(dsp_get_long_acc(0));
  if (FlagsNeeded())
  {
    Update_SR_Register64(RDX, RCX);
  }
}

// ASRN  (fixed parameters)
// 0000 0010 1100 1011
// Arithmetically shifts right accumulator $ACC0 by lower 7-bit (signed) value in $AC1.M
// (if value negative, becomes left shift).
//
// flags out: --xx xx00
void DSPEmitter::asrn(const UDSPInstruction opc)
{
  //	s16 shift;
  //	u16 accm = (u16)dsp_get_acc_m(1);
  get_acc_m(1);
  //	s64 acc = dsp_get_long_acc(0);
  get_long_acc(0, RDX);

  //	if ((accm & 0x3f) == 0)
  //		shift = 0;
  //	else if (accm & 0x40)
  //		shift = -0x40 + (accm & 0x3f);
  //	else
  //		shift = accm & 0x3f;

  //	if (shift > 0)
  //	{
  //		acc >>= shift;
  //	}
  //	else if (shift < 0)
  //	{
  //		acc <<= -shift;
  //	}

  TEST(64, R(RDX), R(RDX));
  FixupBranch zero = J_CC(CC_E);
  TEST(16, R(RAX), Imm16(0x3f));
  FixupBranch noShift = J_CC(CC_Z);
  MOVZX(64, 16, RCX, R(RAX));
  AND(16, R(RCX), Imm16(0x3f));
  TEST(16, R(RAX), Imm16(0x40));
  FixupBranch shiftLeft = J_CC(CC_Z);
  NEG(16, R(RCX));
  ADD(16, R(RCX), Imm16(0x40));
  SHL(64, R(RDX), R(RCX));
  FixupBranch exit = J();
  SetJumpTarget(shiftLeft);
  SAR(64, R(RDX), R(RCX));
  SetJumpTarget(noShift);
  SetJumpTarget(exit);

  //	dsp_set_long_acc(0, acc);
  //	Update_SR_Register64(dsp_get_long_acc(0));
  set_long_acc(0, RDX);
  SetJumpTarget(zero);
  if (FlagsNeeded())
  {
    Update_SR_Register64(RDX, RCX);
  }
}

// LSRNRX $acD, $axS.h
// 0011 01sd 1xxx xxxx
// Logically shifts left/right accumulator $ACC[D] by lower 7-bit (signed) value in $AX[S].H
// x = extension (7 bits!!)
//
// flags out: --xx xx00
void DSPEmitter::lsrnrx(const UDSPInstruction opc)
{
  u8 dreg = (opc >> 8) & 0x1;
  u8 sreg = (opc >> 9) & 0x1;

  //	s16 shift;
  //	u16 axh = g_dsp.r.axh[sreg];
  get_ax_h(sreg);
  //	u64 acc = dsp_get_long_acc(dreg);
  get_long_acc(dreg, RDX);
  //	acc &= 0x000000FFFFFFFFFFULL;
  SHL(64, R(RDX), Imm8(24));
  SHR(64, R(RDX), Imm8(24));

  //	if ((axh & 0x3f) == 0)
  //		shift = 0;
  //	else if (axh & 0x40)
  //		shift = -0x40 + (axh & 0x3f);
  //	else
  //		shift = axh & 0x3f;

  //	if (shift > 0)
  //	{
  //		acc <<= shift;
  //	}
  //	else if (shift < 0)
  //	{
  //		acc >>= -shift;
  //	}

  TEST(64, R(RDX), R(RDX));
  FixupBranch zero = J_CC(CC_E);
  TEST(16, R(RAX), Imm16(0x3f));
  FixupBranch noShift = J_CC(CC_Z);
  MOVZX(64, 16, RCX, R(RAX));
  AND(16, R(RCX), Imm16(0x3f));
  TEST(16, R(RAX), Imm16(0x40));
  FixupBranch shiftLeft = J_CC(CC_Z);
  NEG(16, R(RCX));
  ADD(16, R(RCX), Imm16(0x40));
  SHR(64, R(RDX), R(RCX));
  FixupBranch exit = J();
  SetJumpTarget(shiftLeft);
  SHL(64, R(RDX), R(RCX));
  SetJumpTarget(noShift);
  SetJumpTarget(exit);

  //	dsp_set_long_acc(dreg, (s64)acc);
  //	Update_SR_Register64(dsp_get_long_acc(dreg));
  set_long_acc(dreg, RDX);
  SetJumpTarget(zero);
  if (FlagsNeeded())
  {
    Update_SR_Register64(RDX, RCX);
  }
}

// ASRNRX $acD, $axS.h
// 0011 10sd 1xxx xxxx
// Arithmetically shifts left/right accumulator $ACC[D] by lower 7-bit (signed) value in $AX[S].H
// x = extension (7 bits!!)
//
// flags out: --xx xx00
void DSPEmitter::asrnrx(const UDSPInstruction opc)
{
  u8 dreg = (opc >> 8) & 0x1;
  u8 sreg = (opc >> 9) & 0x1;

  //	s16 shift;
  //	u16 axh = g_dsp.r.axh[sreg];
  get_ax_h(sreg);
  //	s64 acc = dsp_get_long_acc(dreg);
  get_long_acc(dreg, RDX);

  //	if ((axh & 0x3f) == 0)
  //		shift = 0;
  //	else if (axh & 0x40)
  //		shift = -0x40 + (axh & 0x3f);
  //	else
  //		shift = axh & 0x3f;

  //	if (shift > 0) {
  //		acc <<= shift;
  //	} else if (shift < 0) {
  //		acc >>= -shift;
  //	}

  TEST(64, R(RDX), R(RDX));
  FixupBranch zero = J_CC(CC_E);
  TEST(16, R(RAX), Imm16(0x3f));
  FixupBranch noShift = J_CC(CC_Z);
  MOVZX(64, 16, RCX, R(RAX));
  AND(16, R(RCX), Imm16(0x3f));
  TEST(16, R(RAX), Imm16(0x40));
  FixupBranch shiftLeft = J_CC(CC_Z);
  NEG(16, R(RCX));
  ADD(16, R(RCX), Imm16(0x40));
  SAR(64, R(RDX), R(RCX));
  FixupBranch exit = J();
  SetJumpTarget(shiftLeft);
  SHL(64, R(RDX), R(RCX));
  SetJumpTarget(noShift);
  SetJumpTarget(exit);

  //	dsp_set_long_acc(dreg, acc);
  set_long_acc(dreg, RDX);
  SetJumpTarget(zero);
  //	Update_SR_Register64(dsp_get_long_acc(dreg));
  if (FlagsNeeded())
  {
    Update_SR_Register64(RDX, RCX);
  }
}

// LSRNR  $acD
// 0011 110d 1xxx xxxx
// Logically shifts left/right accumulator $ACC[D] by lower 7-bit (signed) value in $AC[1-D].M
// x = extension (7 bits!!)
//
// flags out: --xx xx00
void DSPEmitter::lsrnr(const UDSPInstruction opc)
{
  u8 dreg = (opc >> 8) & 0x1;

  //	s16 shift;
  //	u16 accm = (u16)dsp_get_acc_m(1 - dreg);
  get_acc_m(1 - dreg);
  //	u64 acc = dsp_get_long_acc(dreg);
  get_long_acc(dreg, RDX);
  //	acc &= 0x000000FFFFFFFFFFULL;
  SHL(64, R(RDX), Imm8(24));
  SHR(64, R(RDX), Imm8(24));

  //	if ((accm & 0x3f) == 0)
  //		shift = 0;
  //	else if (accm & 0x40)
  //		shift = -0x40 + (accm & 0x3f);
  //	else
  //		shift = accm & 0x3f;

  //	if (shift > 0)
  //		acc <<= shift;
  //	else if (shift < 0)
  //		acc >>= -shift;

  TEST(64, R(RDX), R(RDX));
  FixupBranch zero = J_CC(CC_E);
  TEST(16, R(RAX), Imm16(0x3f));
  FixupBranch noShift = J_CC(CC_Z);
  MOVZX(64, 16, RCX, R(RAX));
  AND(16, R(RCX), Imm16(0x3f));
  TEST(16, R(RAX), Imm16(0x40));
  FixupBranch shiftLeft = J_CC(CC_Z);
  NEG(16, R(RCX));
  ADD(16, R(RCX), Imm16(0x40));
  SHR(64, R(RDX), R(RCX));
  FixupBranch exit = J();
  SetJumpTarget(shiftLeft);
  SHL(64, R(RDX), R(RCX));
  SetJumpTarget(noShift);
  SetJumpTarget(exit);

  //	dsp_set_long_acc(dreg, (s64)acc);
  set_long_acc(dreg, RDX);
  SetJumpTarget(zero);
  //	Update_SR_Register64(dsp_get_long_acc(dreg));
  if (FlagsNeeded())
  {
    Update_SR_Register64(RDX, RCX);
  }
}

// ASRNR  $acD
// 0011 111d 1xxx xxxx
// Arithmetically shift left/right accumulator $ACC[D] by lower 7-bit (signed) value in $AC[1-D].M
// x = extension (7 bits!!)
//
// flags out: --xx xx00
void DSPEmitter::asrnr(const UDSPInstruction opc)
{
  u8 dreg = (opc >> 8) & 0x1;

  //	s16 shift;
  //	u16 accm = (u16)dsp_get_acc_m(1 - dreg);
  get_acc_m(1 - dreg);
  //	s64 acc = dsp_get_long_acc(dreg);
  get_long_acc(dreg, RDX);

  //	if ((accm & 0x3f) == 0)
  //		shift = 0;
  //	else if (accm & 0x40)
  //		shift = -0x40 + (accm & 0x3f);
  //	else
  //		shift = accm & 0x3f;

  //	if (shift > 0)
  //		acc <<= shift;
  //	else if (shift < 0)
  //		acc >>= -shift;

  TEST(64, R(RDX), R(RDX));
  FixupBranch zero = J_CC(CC_E);
  TEST(16, R(RAX), Imm16(0x3f));
  FixupBranch noShift = J_CC(CC_Z);
  MOVZX(64, 16, RCX, R(RAX));
  AND(16, R(RCX), Imm16(0x3f));
  TEST(16, R(RAX), Imm16(0x40));
  FixupBranch shiftLeft = J_CC(CC_Z);
  NEG(16, R(RCX));
  ADD(16, R(RCX), Imm16(0x40));
  SAR(64, R(RDX), R(RCX));
  FixupBranch exit = J();
  SetJumpTarget(shiftLeft);
  SHL(64, R(RDX), R(RCX));
  SetJumpTarget(noShift);
  SetJumpTarget(exit);

  //	dsp_set_long_acc(dreg, acc);
  set_long_acc(dreg, RDX);
  SetJumpTarget(zero);
  //	Update_SR_Register64(dsp_get_long_acc(dreg));
  if (FlagsNeeded())
  {
    Update_SR_Register64(RDX, RCX);
  }
}

}
