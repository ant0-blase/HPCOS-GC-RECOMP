// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/Interpreter/Interpreter.h"

#include <cmath>
#include <utility>

#include "Common/CommonTypes.h"
#include "Common/FloatUtils.h"
#include "Core/PowerPC/Gekko.h"
#include "Core/PowerPC/Interpreter/Interpreter_FPUtils.h"
#include "Core/PowerPC/PowerPC.h"

namespace
{
// Apply current rounding mode
enum class RoundingMode
{
  Nearest = 0b00,
  TowardsZero = 0b01,
  TowardsPositiveInfinity = 0b10,
  TowardsNegativeInfinity = 0b11
};

void SetFI(PowerPC::PowerPCState& ppc_state, u32 FI)
{
  if (FI != 0)
  {
    SetFPException(ppc_state, FPSCR_XX);
  }
  ppc_state.fpscr.FI = FI;
}

// Round a number to an integer in the same direction as the CPU rounding mode,
// without setting any CPU flags or being careful about NaNs
double RoundToIntegerMode(double number)
{
  // This value is 2^52 -- The first number in which double precision floating point
  // numbers can only store subsequent integers, and no longer any decimals
  // This keeps the sign of the unrounded value because it needs to scale it
  // upwards when added
  const double int_precision = std::copysign(4503599627370496.0, number);

  // By adding this value to the original number,
  // it will be forced to decide a integer to round to
  // This rounding will be the same as the CPU rounding mode
  return (number + int_precision) - int_precision;
}

// Note that the convert to integer operation is defined
// in Appendix C.4.2 in PowerPC Microprocessor Family:
// The Programming Environments Manual for 32 and 64-bit Microprocessors
void ConvertToInteger(PowerPC::PowerPCState& ppc_state, UGeckoInstruction inst,
                      RoundingMode rounding_mode)
{
  const double b = ppc_state.ps[inst.FB].PS0AsDouble();
  double rounded;
  u32 value;
  bool exception_occurred = false;

  // To reduce complexity, this takes in a rounding mode in a switch case,
  // rather than always judging based on the emulated CPU rounding mode
  switch (rounding_mode)
  {
  case RoundingMode::Nearest:
    // On generic platforms, the rounding should be assumed to be ties to even
    // For targeted platforms this would work for any rounding mode,
    // but it's mainly just kept in to replace roundeven,
    // due to its lack in the C++17 (and possible lack for future versions)
    rounded = RoundToIntegerMode(b);
    break;
  case RoundingMode::TowardsZero:
    rounded = std::trunc(b);
    break;
  case RoundingMode::TowardsPositiveInfinity:
    rounded = std::ceil(b);
    break;
  case RoundingMode::TowardsNegativeInfinity:
    rounded = std::floor(b);
    break;
  default:
    std::unreachable();
  }

  if (std::isnan(b))
  {
    if (Common::IsSNAN(b))
      SetFPException(ppc_state, FPSCR_VXSNAN);

    value = 0x80000000;
    SetFPException(ppc_state, FPSCR_VXCVI);
    exception_occurred = true;
  }
  else if (rounded >= static_cast<double>(0x80000000))
  {
    // Positive large operand or +inf
    value = 0x7fffffff;
    SetFPException(ppc_state, FPSCR_VXCVI);
    exception_occurred = true;
  }
  else if (rounded < -static_cast<double>(0x80000000))
  {
    // Negative large operand or -inf
    value = 0x80000000;
    SetFPException(ppc_state, FPSCR_VXCVI);
    exception_occurred = true;
  }
  else
  {
    s32 signed_value = static_cast<s32>(rounded);
    value = static_cast<u32>(signed_value);
    const double di = static_cast<double>(signed_value);
    if (di == b)
    {
      ppc_state.fpscr.ClearFIFR();
    }
    else
    {
      // Also sets FPSCR[XX]
      SetFI(ppc_state, 1);
      ppc_state.fpscr.FR = fabs(di) > fabs(b);
    }
  }

  if (exception_occurred)
  {
    ppc_state.fpscr.ClearFIFR();
  }

  if (!exception_occurred || ppc_state.fpscr.VE == 0)
  {
    // Based on HW tests
    // FPRF is not affected
    u64 result = 0xfff8000000000000ull | value;
    if (value == 0 && std::signbit(b))
      result |= 0x100000000ull;

    ppc_state.ps[inst.FD].SetPS0(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}
}  // Anonymous namespace

void Interpreter::fctiwx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  ConvertToInteger(ppc_state, inst, static_cast<RoundingMode>(ppc_state.fpscr.RN.Value()));
}

void Interpreter::fctiwzx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  ConvertToInteger(ppc_state, inst, RoundingMode::TowardsZero);
}

void Interpreter::fmrx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  ppc_state.ps[inst.FD].SetPS0(ppc_state.ps[inst.FB].PS0AsU64());

  // This is a binary instruction. Does not alter FPSCR
  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fabsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  ppc_state.ps[inst.FD].SetPS0(fabs(ppc_state.ps[inst.FB].PS0AsDouble()));

  // This is a binary instruction. Does not alter FPSCR
  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fnabsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  ppc_state.ps[inst.FD].SetPS0(ppc_state.ps[inst.FB].PS0AsU64() | (UINT64_C(1) << 63));

  // This is a binary instruction. Does not alter FPSCR
  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fnegx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  ppc_state.ps[inst.FD].SetPS0(ppc_state.ps[inst.FB].PS0AsU64() ^ (UINT64_C(1) << 63));

  // This is a binary instruction. Does not alter FPSCR
  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fselx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  ppc_state.ps[inst.FD].SetPS0((a.PS0AsDouble() >= -0.0) ? c.PS0AsDouble() : b.PS0AsDouble());

  // This is a binary instruction. Does not alter FPSCR
  if (inst.Rc)
    ppc_state.UpdateCR1();
}

// !!! warning !!!
// PS1 must be set to the value of PS0 or DragonballZ will be f**ked up
// PS1 is said to be undefined
void Interpreter::frspx(Interpreter& interpreter, UGeckoInstruction inst)  // round to single
{
  auto& ppc_state = interpreter.m_ppc_state;
  const double b = ppc_state.ps[inst.FB].PS0AsDouble();
  const float rounded = ForceSingle(ppc_state.fpscr, b);

  if (std::isnan(b))
  {
    const bool is_snan = Common::IsSNAN(b);

    if (is_snan)
      SetFPException(ppc_state, FPSCR_VXSNAN);

    if (!is_snan || ppc_state.fpscr.VE == 0)
    {
      ppc_state.ps[inst.FD].Fill(rounded);
      ppc_state.UpdateFPRFSingle(rounded);
    }

    ppc_state.fpscr.ClearFIFR();
  }
  else
  {
    SetFI(ppc_state, b != rounded);
    ppc_state.fpscr.FR = fabs(rounded) > fabs(b);
    ppc_state.UpdateFPRFSingle(rounded);
    ppc_state.ps[inst.FD].Fill(rounded);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

