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

void Interpreter::fmulx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product = NI_mul(ppc_state, a.PS0AsDouble(), c.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const double result = ForceDouble(ppc_state.fpscr, product.value);

    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.fpscr.FI = 0;  // are these flags important?
    ppc_state.fpscr.FR = 0;
    ppc_state.UpdateFPRFDouble(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}
void Interpreter::fmulsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& c = ppc_state.ps[inst.FC];

  const double c_value = Force25Bit(c.PS0AsDouble());
  const FPResult product = NI_mul(ppc_state, a.PS0AsDouble(), c_value);

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const float result = ForceSingle(ppc_state.fpscr, product.value);

    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.fpscr.FI = 0;
    ppc_state.fpscr.FR = 0;
    ppc_state.UpdateFPRFSingle(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fmaddx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product =
      NI_madd<false>(ppc_state, a.PS0AsDouble(), c.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const double result = ForceDouble(ppc_state.fpscr, product.value);
    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.UpdateFPRFDouble(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fmaddsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product =
      NI_madd<true>(ppc_state, a.PS0AsDouble(), c.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const float result = ForceSingle(ppc_state.fpscr, product.value);

    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.fpscr.FI = product.value != result;
    ppc_state.fpscr.FR = 0;
    ppc_state.UpdateFPRFSingle(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::faddx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];

  const FPResult sum = NI_add(ppc_state, a.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || sum.HasNoInvalidExceptions())
  {
    const double result = ForceDouble(ppc_state.fpscr, sum.value);
    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.UpdateFPRFDouble(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}
void Interpreter::faddsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];

  const FPResult sum = NI_add(ppc_state, a.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || sum.HasNoInvalidExceptions())
  {
    const float result = ForceSingle(ppc_state.fpscr, sum.value);
    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.UpdateFPRFSingle(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fdivx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];

  const FPResult quotient = NI_div(ppc_state, a.PS0AsDouble(), b.PS0AsDouble());
  const bool not_divide_by_zero = ppc_state.fpscr.ZE == 0 || quotient.exception != FPSCR_ZX;
  const bool not_invalid = ppc_state.fpscr.VE == 0 || quotient.HasNoInvalidExceptions();

  if (not_divide_by_zero && not_invalid)
  {
    const double result = ForceDouble(ppc_state.fpscr, quotient.value);
    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.UpdateFPRFDouble(result);
  }

  // FR,FI,OX,UX???
  if (inst.Rc)
    ppc_state.UpdateCR1();
}
void Interpreter::fdivsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];

  const FPResult quotient = NI_div(ppc_state, a.PS0AsDouble(), b.PS0AsDouble());
  const bool not_divide_by_zero = ppc_state.fpscr.ZE == 0 || quotient.exception != FPSCR_ZX;
  const bool not_invalid = ppc_state.fpscr.VE == 0 || quotient.HasNoInvalidExceptions();

  if (not_divide_by_zero && not_invalid)
  {
    const float result = ForceSingle(ppc_state.fpscr, quotient.value);
    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.UpdateFPRFSingle(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

// Single precision only.
void Interpreter::fresx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const double b = ppc_state.ps[inst.FB].PS0AsDouble();

  const auto compute_result = [&ppc_state, inst](double value) {
    const double result = Common::ApproximateReciprocal(value);
    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.UpdateFPRFSingle(float(result));
  };

  if (b == 0.0)
  {
    SetFPException(ppc_state, FPSCR_ZX);
    ppc_state.fpscr.ClearFIFR();

    if (ppc_state.fpscr.ZE == 0)
      compute_result(b);
  }
  else if (Common::IsSNAN(b))
  {
    SetFPException(ppc_state, FPSCR_VXSNAN);
    ppc_state.fpscr.ClearFIFR();

    if (ppc_state.fpscr.VE == 0)
      compute_result(b);
  }
  else
  {
    if (std::isnan(b) || std::isinf(b))
      ppc_state.fpscr.ClearFIFR();

    compute_result(b);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::frsqrtex(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const double b = ppc_state.ps[inst.FB].PS0AsDouble();

  const auto compute_result = [&ppc_state, inst](double value) {
    const double result = Common::ApproximateReciprocalSquareRoot(value);
    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.UpdateFPRFDouble(result);
  };

  if (b < 0.0)
  {
    SetFPException(ppc_state, FPSCR_VXSQRT);
    ppc_state.fpscr.ClearFIFR();

    if (ppc_state.fpscr.VE == 0)
      compute_result(b);
  }
  else if (b == 0.0)
  {
    SetFPException(ppc_state, FPSCR_ZX);
    ppc_state.fpscr.ClearFIFR();

    if (ppc_state.fpscr.ZE == 0)
      compute_result(b);
  }
  else if (Common::IsSNAN(b))
  {
    SetFPException(ppc_state, FPSCR_VXSNAN);
    ppc_state.fpscr.ClearFIFR();

    if (ppc_state.fpscr.VE == 0)
      compute_result(b);
  }
  else
  {
    if (std::isnan(b) || std::isinf(b))
      ppc_state.fpscr.ClearFIFR();

    compute_result(b);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fmsubx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product =
      NI_msub<false>(ppc_state, a.PS0AsDouble(), c.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const double result = ForceDouble(ppc_state.fpscr, product.value);
    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.UpdateFPRFDouble(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fmsubsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product =
      NI_msub<true>(ppc_state, a.PS0AsDouble(), c.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const float result = ForceSingle(ppc_state.fpscr, product.value);
    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.UpdateFPRFSingle(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fnmaddx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product =
      NI_madd<false>(ppc_state, a.PS0AsDouble(), c.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const double tmp = ForceDouble(ppc_state.fpscr, product.value);
    const double result = std::isnan(tmp) ? tmp : -tmp;

    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.UpdateFPRFDouble(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fnmaddsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product =
      NI_madd<true>(ppc_state, a.PS0AsDouble(), c.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const float tmp = ForceSingle(ppc_state.fpscr, product.value);
    const float result = std::isnan(tmp) ? tmp : -tmp;

    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.UpdateFPRFSingle(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fnmsubx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product =
      NI_msub<false>(ppc_state, a.PS0AsDouble(), c.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const double tmp = ForceDouble(ppc_state.fpscr, product.value);
    const double result = std::isnan(tmp) ? tmp : -tmp;

    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.UpdateFPRFDouble(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fnmsubsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];
  const auto& c = ppc_state.ps[inst.FC];

  const FPResult product =
      NI_msub<true>(ppc_state, a.PS0AsDouble(), c.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || product.HasNoInvalidExceptions())
  {
    const float tmp = ForceSingle(ppc_state.fpscr, product.value);
    const float result = std::isnan(tmp) ? tmp : -tmp;

    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.UpdateFPRFSingle(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fsubx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];

  const FPResult difference = NI_sub(ppc_state, a.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || difference.HasNoInvalidExceptions())
  {
    const double result = ForceDouble(ppc_state.fpscr, difference.value);
    ppc_state.ps[inst.FD].SetPS0(result);
    ppc_state.UpdateFPRFDouble(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}

void Interpreter::fsubsx(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];

  const FPResult difference = NI_sub(ppc_state, a.PS0AsDouble(), b.PS0AsDouble());

  if (ppc_state.fpscr.VE == 0 || difference.HasNoInvalidExceptions())
  {
    const float result = ForceSingle(ppc_state.fpscr, difference.value);
    ppc_state.ps[inst.FD].Fill(result);
    ppc_state.UpdateFPRFSingle(result);
  }

  if (inst.Rc)
    ppc_state.UpdateCR1();
}
