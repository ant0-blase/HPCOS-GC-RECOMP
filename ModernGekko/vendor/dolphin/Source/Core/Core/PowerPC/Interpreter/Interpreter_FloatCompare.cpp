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

void Interpreter::Helper_FloatCompareOrdered(PowerPC::PowerPCState& ppc_state,
                                             UGeckoInstruction inst, double fa, double fb)
{
  FPCC compare_result;

  if (std::isnan(fa) || std::isnan(fb))
  {
    compare_result = FPCC::FU;
    if (Common::IsSNAN(fa) || Common::IsSNAN(fb))
    {
      SetFPException(ppc_state, FPSCR_VXSNAN);
      if (ppc_state.fpscr.VE == 0)
      {
        SetFPException(ppc_state, FPSCR_VXVC);
      }
    }
    else  // QNaN
    {
      SetFPException(ppc_state, FPSCR_VXVC);
    }
  }
  else if (fa < fb)
  {
    compare_result = FPCC::FL;
  }
  else if (fa > fb)
  {
    compare_result = FPCC::FG;
  }
  else  // Equals
  {
    compare_result = FPCC::FE;
  }

  const u32 compare_value = static_cast<u32>(compare_result);

  // Clear and set the FPCC bits accordingly.
  ppc_state.fpscr.FPRF = (ppc_state.fpscr.FPRF & ~FPCC_MASK) | compare_value;

  ppc_state.cr.SetField(inst.CRFD, compare_value);
}

void Interpreter::Helper_FloatCompareUnordered(PowerPC::PowerPCState& ppc_state,
                                               UGeckoInstruction inst, double fa, double fb)
{
  FPCC compare_result;

  if (std::isnan(fa) || std::isnan(fb))
  {
    compare_result = FPCC::FU;

    if (Common::IsSNAN(fa) || Common::IsSNAN(fb))
    {
      SetFPException(ppc_state, FPSCR_VXSNAN);
    }
  }
  else if (fa < fb)
  {
    compare_result = FPCC::FL;
  }
  else if (fa > fb)
  {
    compare_result = FPCC::FG;
  }
  else  // Equals
  {
    compare_result = FPCC::FE;
  }

  const u32 compare_value = static_cast<u32>(compare_result);

  // Clear and set the FPCC bits accordingly.
  ppc_state.fpscr.FPRF = (ppc_state.fpscr.FPRF & ~FPCC_MASK) | compare_value;

  ppc_state.cr.SetField(inst.CRFD, compare_value);
}

void Interpreter::fcmpo(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];

  Helper_FloatCompareOrdered(ppc_state, inst, a.PS0AsDouble(), b.PS0AsDouble());
}

void Interpreter::fcmpu(Interpreter& interpreter, UGeckoInstruction inst)
{
  auto& ppc_state = interpreter.m_ppc_state;
  const auto& a = ppc_state.ps[inst.FA];
  const auto& b = ppc_state.ps[inst.FB];

  Helper_FloatCompareUnordered(ppc_state, inst, a.PS0AsDouble(), b.PS0AsDouble());
}

