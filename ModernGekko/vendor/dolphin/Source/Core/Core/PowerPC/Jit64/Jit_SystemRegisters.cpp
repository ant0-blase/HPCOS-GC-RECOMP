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

static void DoICacheReset(PowerPC::PowerPCState& ppc_state, JitInterface& jit_interface)
{
  ppc_state.iCache.Reset(jit_interface);
}

void Jit64::mtspr(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  u32 iIndex = (inst.SPRU << 5) | (inst.SPRL & 0x1F);
  int d = inst.RD;

  switch (iIndex)
  {
  case SPR_DMAU:

  case SPR_SPRG0:
  case SPR_SPRG1:
  case SPR_SPRG2:
  case SPR_SPRG3:

  case SPR_SRR0:
  case SPR_SRR1:

  case SPR_LR:
  case SPR_CTR:

  case SPR_GQR0:
  case SPR_GQR0 + 1:
  case SPR_GQR0 + 2:
  case SPR_GQR0 + 3:
  case SPR_GQR0 + 4:
  case SPR_GQR0 + 5:
  case SPR_GQR0 + 6:
  case SPR_GQR0 + 7:
    // These are safe to do the easy way, see the bottom of this function.
    break;

  case SPR_XER:
  {
    RCX64Reg Rd = gpr.Bind(d, RCMode::Read);
    RegCache::Realize(Rd);

    MOV(32, R(RSCRATCH), Rd);
    AND(32, R(RSCRATCH), Imm32(0xff7f));
    MOV(16, PPCSTATE(xer_stringctrl), R(RSCRATCH));

    MOV(32, R(RSCRATCH), Rd);
    SHR(32, R(RSCRATCH), Imm8(XER_CA_SHIFT));
    AND(8, R(RSCRATCH), Imm8(1));
    MOV(8, PPCSTATE(xer_ca), R(RSCRATCH));

    MOV(32, R(RSCRATCH), Rd);
    SHR(32, R(RSCRATCH), Imm8(XER_OV_SHIFT));
    MOV(8, PPCSTATE(xer_so_ov), R(RSCRATCH));

    return;
  }

  case SPR_HID0:
  {
    RCOpArg Rd = gpr.Use(d, RCMode::Read);
    RegCache::Realize(Rd);

    MOV(32, R(RSCRATCH), Rd);
    BTR(32, R(RSCRATCH), Imm8(31 - 20));  // ICFI
    MOV(32, PPCSTATE_SPR(iIndex), R(RSCRATCH));
    FixupBranch dont_reset_icache = J_CC(CC_NC);
    BitSet32 regs = CallerSavedRegistersInUse();
    ABI_PushRegistersAndAdjustStack(regs, 0);
    ABI_CallFunctionPP(DoICacheReset, &m_ppc_state, &m_system.GetJitInterface());
    ABI_PopRegistersAndAdjustStack(regs, 0);
    SetJumpTarget(dont_reset_icache);
    return;
  }

  default:
    FALLBACK_IF(true);
  }

  // OK, this is easy.
  RCOpArg Rd = gpr.BindOrImm(d, RCMode::Read);
  RegCache::Realize(Rd);
  MOV(32, PPCSTATE_SPR(iIndex), Rd);
}

void Jit64::mfspr(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  u32 iIndex = (inst.SPRU << 5) | (inst.SPRL & 0x1F);
  int d = inst.RD;
  switch (iIndex)
  {
  case SPR_TL:
  case SPR_TU:
  {
    // TODO: we really only need to call GetFakeTimeBase once per JIT block; this matters because
    // typical use of this instruction is to call it three times, e.g. mftbu/mftbl/mftbu/cmpw/bne
    // to deal with possible timer wraparound. This makes the second two (out of three) completely
    // redundant for the JIT.
    // no register choice

    RCX64Reg rdx = gpr.Scratch(RDX);
    RCX64Reg rax = gpr.Scratch(RAX);
    RCX64Reg rcx = gpr.Scratch(RCX);

    auto& core_timing_globals = m_system.GetCoreTiming().GetGlobals();
    MOV(64, rcx, ImmPtr(&core_timing_globals));

    // An inline implementation of CoreTiming::GetFakeTimeBase, since in timer-heavy games the
    // cost of calling out to C for this is actually significant.
    // Scale downcount by the CPU overclocking factor.
    CVTSI2SS(XMM0, PPCSTATE(downcount));
    MULSS(XMM0, MDisp(rcx, offsetof(CoreTiming::Globals, last_OC_factor_inverted)));
    CVTSS2SI(rdx, R(XMM0));  // RDX is downcount scaled by the overclocking factor
    MOV(32, rax, MDisp(rcx, offsetof(CoreTiming::Globals, slice_length)));
    SUB(64, rax, rdx);  // cycles since the last CoreTiming::Advance() event is (slicelength -
                        // Scaled_downcount)
    ADD(64, rax, MDisp(rcx, offsetof(CoreTiming::Globals, global_timer)));
    SUB(64, rax, MDisp(rcx, offsetof(CoreTiming::Globals, fake_TB_start_ticks)));
    // It might seem convenient to correct the timer for the block position here for even more
    // accurate
    // timing, but as of currently, this can break games. If we end up reading a time *after* the
    // time
    // at which an interrupt was supposed to occur, e.g. because we're 100 cycles into a block with
    // only
    // 50 downcount remaining, some games don't function correctly, such as Karaoke Party
    // Revolution,
    // which won't get past the loading screen.
    // if (js.downcountAmount)
    //	ADD(64, rax, Imm32(js.downcountAmount));

    // a / 12 = (a * 0xAAAAAAAAAAAAAAAB) >> 67
    MOV(64, rdx, Imm64(0xAAAAAAAAAAAAAAABULL));
    MUL(64, rdx);
    MOV(64, rax, MDisp(rcx, offsetof(CoreTiming::Globals, fake_TB_start_value)));
    SHR(64, rdx, Imm8(3));
    ADD(64, rax, rdx);
    MOV(64, PPCSTATE_SPR(SPR_TL), rax);

    if (CanMergeNextInstructions(1))
    {
      const UGeckoInstruction& next = js.op[1].inst;
      // Two calls of TU/TL next to each other are extremely common in typical usage, so merge them
      // if we can.
      u32 nextIndex = (next.SPRU << 5) | (next.SPRL & 0x1F);
      // Be careful; the actual opcode is for mftb (371), not mfspr (339)
      int n = next.RD;
      if (next.OPCD == 31 && next.SUBOP10 == 371 && (nextIndex == SPR_TU || nextIndex == SPR_TL) &&
          n != d)
      {
        js.downcountAmount++;
        js.skipInstructions = 1;
        RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
        RCX64Reg Rn = gpr.Bind(n, RCMode::Write);
        RegCache::Realize(Rd, Rn);
        if (iIndex == SPR_TL)
          MOV(32, Rd, rax);
        if (nextIndex == SPR_TL)
          MOV(32, Rn, rax);
        SHR(64, rax, Imm8(32));
        if (iIndex == SPR_TU)
          MOV(32, Rd, rax);
        if (nextIndex == SPR_TU)
          MOV(32, Rn, rax);
        break;
      }
    }
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Rd);
    if (iIndex == SPR_TU)
      SHR(64, rax, Imm8(32));
    MOV(32, Rd, rax);
    break;
  }
  case SPR_XER:
  {
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Rd);
    MOVZX(32, 16, Rd, PPCSTATE(xer_stringctrl));
    MOVZX(32, 8, RSCRATCH, PPCSTATE(xer_ca));
    SHL(32, R(RSCRATCH), Imm8(XER_CA_SHIFT));
    OR(32, Rd, R(RSCRATCH));

    MOVZX(32, 8, RSCRATCH, PPCSTATE(xer_so_ov));
    SHL(32, R(RSCRATCH), Imm8(XER_OV_SHIFT));
    OR(32, Rd, R(RSCRATCH));
    break;
  }
  case SPR_WPAR:
  case SPR_DEC:
  case SPR_PMC1:
  case SPR_PMC2:
  case SPR_PMC3:
  case SPR_PMC4:
  case SPR_UPMC1:
  case SPR_UPMC2:
  case SPR_UPMC3:
  case SPR_UPMC4:
  case SPR_IABR:
    FALLBACK_IF(true);
  default:
  {
    RCX64Reg Rd = gpr.Bind(d, RCMode::Write);
    RegCache::Realize(Rd);
    MOV(32, Rd, PPCSTATE_SPR(iIndex));
    break;
  }
  }
}

void Jit64::mtmsr(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  FALLBACK_IF(jo.fp_exceptions);

  {
    OpArg Rs_op_arg;
    {
      RCOpArg Rs = gpr.BindOrImm(inst.RS, RCMode::Read);
      RegCache::Realize(Rs);
      MOV(32, PPCSTATE(msr), Rs);
      Rs_op_arg = Rs;
    }
    MSRUpdated(Rs_op_arg, RSCRATCH2);
  }

  gpr.Flush();
  fpr.Flush();

  // If some exceptions are pending and EE are now enabled, force checking
  // external exceptions when going out of mtmsr in order to execute delayed
  // interrupts as soon as possible.
  TEST(32, PPCSTATE(msr), Imm32(0x8000));
  FixupBranch eeDisabled = J_CC(CC_Z, Jump::Near);

  TEST(32, PPCSTATE(Exceptions),
       Imm32(EXCEPTION_EXTERNAL_INT | EXCEPTION_PERFORMANCE_MONITOR | EXCEPTION_DECREMENTER));
  FixupBranch noExceptionsPending = J_CC(CC_Z, Jump::Near);

  // Check if a CP interrupt is waiting and keep the GPU emulation in sync (issue 4336)
  MOV(64, R(RSCRATCH), ImmPtr(&m_system.GetProcessorInterface().m_interrupt_cause));
  TEST(32, MatR(RSCRATCH), Imm32(ProcessorInterface::INT_CAUSE_CP));
  FixupBranch cpInt = J_CC(CC_NZ, Jump::Near);

  MOV(32, PPCSTATE(pc), Imm32(js.compilerPC + 4));
  WriteExternalExceptionExit();

  SetJumpTarget(cpInt);
  SetJumpTarget(noExceptionsPending);
  SetJumpTarget(eeDisabled);

  MOV(32, R(RSCRATCH), Imm32(js.compilerPC + 4));
  WriteExitDestInRSCRATCH();
}

void Jit64::mfmsr(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  // Privileged?
  RCX64Reg Rd = gpr.Bind(inst.RD, RCMode::Write);
  RegCache::Realize(Rd);
  MOV(32, Rd, PPCSTATE(msr));
}

void Jit64::mftb(UGeckoInstruction inst)
{
  INSTRUCTION_START
  JITDISABLE(bJITSystemRegistersOff);
  mfspr(inst);
}
