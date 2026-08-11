// Copyright 2014 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/JitArm64/Jit.h"

#include <cstdio>
#include <optional>
#include <span>
#include <sstream>
#include <utility>

#include <fmt/format.h>
#include <fmt/ostream.h>

#include "Common/Arm64Emitter.h"
#include "Common/CommonTypes.h"
#include "Common/GekkoDisassembler.h"
#include "Common/HostDisassembler.h"
#include "Common/Logging/Log.h"
#include "Common/MathUtil.h"
#include "Common/MsgHandler.h"
#include "Common/StringUtil.h"

#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/HLE/HLE.h"
#include "Core/HW/CPU.h"
#include "Core/HW/GPFifo.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/ProcessorInterface.h"
#include "Core/Host.h"
#include "Core/Cheats/PatchEngine.h"
#include "Core/PowerPC/Interpreter/Interpreter.h"
#include "Core/PowerPC/JitArm64/JitArm64_RegCache.h"
#include "Core/PowerPC/JitCommon/ConstantPropagation.h"
#include "Core/PowerPC/JitInterface.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/System.h"

using namespace Arm64Gen;



JitArm64::JitArm64(Core::System& system)
    : JitBase(system), m_float_emit(this),
      m_disassembler(HostDisassembler::Factory(HostDisassembler::Platform::aarch64))
{
}

JitArm64::~JitArm64() = default;



void JitArm64::FallBackToInterpreter(UGeckoInstruction inst)
{
  FlushCarry();
  gpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG, IgnoreDiscardedRegisters::Yes);
  fpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG, IgnoreDiscardedRegisters::Yes);

  if (js.op->canEndBlock)
  {
    // also flush the program counter
    auto WA = gpr.GetScopedReg();
    MOVI2R(WA, js.compilerPC);
    STR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(pc));
    ADD(WA, WA, 4);
    STR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(npc));
  }

  Interpreter::Instruction instr = Interpreter::GetInterpreterOp(inst);
  ABI_CallFunction(instr, &m_system.GetInterpreter(), inst.hex);

  // If the instruction wrote to any registers which were marked as discarded,
  // we must mark them as no longer discarded
  gpr.ResetRegisters(js.op->regsOut);
  fpr.ResetRegisters(js.op->GetFregsOut());
  gpr.ResetCRRegisters(js.op->crOut);

  // We must also update constant propagation
  m_constant_propagation.ClearGPRs(js.op->regsOut);

  if (js.op->opinfo->flags & FL_SET_MSR)
    EmitUpdateMembase();

  if (js.op->canEndBlock)
  {
    if (js.isLastInstruction)
    {
      auto WA = gpr.GetScopedReg();
      LDR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(npc));
      WriteExceptionExit(WA);
    }
    else
    {
      // only exit if ppcstate.npc was changed
      auto WA = gpr.GetScopedReg();
      LDR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(npc));
      {
        auto WB = gpr.GetScopedReg();
        MOVI2R(WB, js.compilerPC + 4);
        CMP(WB, WA);
      }
      FixupBranch c = B(CC_EQ);
      WriteExceptionExit(WA);
      SetJumpTarget(c);
    }
  }
  else if (ShouldHandleFPExceptionForInstruction(js.op))
  {
    WriteConditionalExceptionExit(EXCEPTION_PROGRAM);
  }

  if (jo.memcheck && (js.op->opinfo->flags & FL_LOADSTORE))
  {
    WriteConditionalExceptionExit(EXCEPTION_DSI);
  }
}

void JitArm64::HLEFunction(u32 hook_index)
{
  FlushCarry();
  gpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
  fpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);

  ABI_CallFunction(&HLE::ExecuteFromJIT, js.compilerPC, hook_index, &m_system);
}

void JitArm64::DoNothing(UGeckoInstruction inst)
{
  // Yup, just don't do anything.
}

void JitArm64::Break(UGeckoInstruction inst)
{
  WARN_LOG_FMT(DYNA_REC, "Breaking! {:08x} - Fix me ;)", inst.hex);
  std::exit(0);
}

void JitArm64::Cleanup()
{
  if (jo.optimizeGatherPipe && js.fifoBytesSinceCheck > 0)
  {
    static_assert(PPCSTATE_OFF(gather_pipe_ptr) <= 504);
    static_assert(PPCSTATE_OFF(gather_pipe_ptr) + 8 == PPCSTATE_OFF(gather_pipe_base_ptr));
    LDP(IndexType::Signed, ARM64Reg::X0, ARM64Reg::X1, PPC_REG, PPCSTATE_OFF(gather_pipe_ptr));
    SUB(ARM64Reg::X0, ARM64Reg::X0, ARM64Reg::X1);
    CMP(ARM64Reg::X0, GPFifo::GATHER_PIPE_SIZE);
    FixupBranch exit = B(CC_LT);
    ABI_CallFunction(&GPFifo::UpdateGatherPipe, &m_system.GetGPFifo());
    SetJumpTarget(exit);
  }

  if (m_ppc_state.feature_flags & FEATURE_FLAG_PERFMON)
  {
    ABI_CallFunction(&PowerPC::UpdatePerformanceMonitor, js.downcountAmount, js.numLoadStoreInst,
                     js.numFloatingPointInst, &m_ppc_state);
  }
}

void JitArm64::DoDownCount()
{
  LDR(IndexType::Unsigned, ARM64Reg::W0, PPC_REG, PPCSTATE_OFF(downcount));
  SUBSI2R(ARM64Reg::W0, ARM64Reg::W0, js.downcountAmount, ARM64Reg::W1);
  STR(IndexType::Unsigned, ARM64Reg::W0, PPC_REG, PPCSTATE_OFF(downcount));
}

void JitArm64::ResetStack()
{
  if (!m_enable_blr_optimization)
    return;

  LDR(IndexType::Unsigned, ARM64Reg::X0, PPC_REG, PPCSTATE_OFF(stored_stack_pointer));
  ADD(ARM64Reg::SP, ARM64Reg::X0, 0);
}

void JitArm64::IntializeSpeculativeConstants()
{
  // If the block depends on an input register which looks like a gather pipe or MMIO related
  // constant, guess that it is actually a constant input, and specialize the block based on this
  // assumption. This happens when there are branches in code writing to the gather pipe, but only
  // the first block loads the constant.
  // Insert a check at the start of the block to verify that the value is actually constant.
  // This can save a lot of backpatching and optimize gather pipe writes in more places.
  const u8* fail = nullptr;
  for (auto i : code_block.m_gpr_inputs)
  {
    u32 compile_time_value = m_ppc_state.gpr[i];
    if (m_mmu.IsOptimizableGatherPipeWrite(compile_time_value) ||
        m_mmu.IsOptimizableGatherPipeWrite(compile_time_value - 0x8000) ||
        compile_time_value == 0xCC000000)
    {
      if (!fail)
      {
        SwitchToFarCode();
        fail = GetCodePtr();
        MOVI2R(DISPATCHER_PC, js.blockStart);
        STR(IndexType::Unsigned, DISPATCHER_PC, PPC_REG, PPCSTATE_OFF(pc));
        ABI_CallFunction(&JitInterface::CompileExceptionCheckFromJIT, &m_system.GetJitInterface(),
                         static_cast<u32>(JitInterface::ExceptionType::SpeculativeConstants));
        B(dispatcher_no_check);
        SwitchToNearCode();
      }

      {
        auto tmp = gpr.GetScopedReg();
        ARM64Reg value = gpr.R(i);
        MOVI2R(tmp, compile_time_value);
        CMP(value, tmp);
      }

      FixupBranch no_fail = B(CCFlags::CC_EQ);
      B(fail);
      SetJumpTarget(no_fail);

      gpr.SetImmediate(i, compile_time_value, true);
    }
  }
}

void JitArm64::EmitUpdateMembase()
{
  LDR(IndexType::Unsigned, MEM_REG, PPC_REG, PPCSTATE_OFF(mem_ptr));
}

void JitArm64::MSRUpdated(u32 msr)
{
  // Update mem_ptr
  auto& memory = m_system.GetMemory();
  MOVP2R(MEM_REG,
         UReg_MSR(msr).DR ?
             (jo.fastmem ? memory.GetLogicalBase() : memory.GetLogicalPageMappingsBase()) :
             (jo.fastmem ? memory.GetPhysicalBase() : memory.GetPhysicalPageMappingsBase()));
  STR(IndexType::Unsigned, MEM_REG, PPC_REG, PPCSTATE_OFF(mem_ptr));

  // Update feature_flags
  static_assert(UReg_MSR{}.DR.StartBit() == 4);
  static_assert(UReg_MSR{}.IR.StartBit() == 5);
  static_assert(FEATURE_FLAG_MSR_DR == 1 << 0);
  static_assert(FEATURE_FLAG_MSR_IR == 1 << 1);
  const u32 other_feature_flags = m_ppc_state.feature_flags & ~0x3;
  const u32 feature_flags = other_feature_flags | ((msr >> 4) & 0x3);
  if (feature_flags == 0)
  {
    STR(IndexType::Unsigned, ARM64Reg::WZR, PPC_REG, PPCSTATE_OFF(feature_flags));
  }
  else
  {
    auto WA = gpr.GetScopedReg();
    MOVI2R(WA, feature_flags);
    STR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(feature_flags));
  }

  // Call PageTableUpdatedFromJit if needed
  if (UReg_MSR(msr).DR)
  {
    gpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
    fpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);

    auto WA = gpr.GetScopedReg();

    static_assert(PPCSTATE_OFF(pagetable_update_pending) < 0x1000);
    LDRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(pagetable_update_pending));
    FixupBranch update_not_pending = CBZ(WA);
    ABI_CallFunction(&PowerPC::MMU::PageTableUpdatedFromJit, &m_system.GetMMU());
    SetJumpTarget(update_not_pending);
  }
}

void JitArm64::MSRUpdated(ARM64Reg msr)
{
  auto WA = gpr.GetScopedReg();
  ARM64Reg XA = EncodeRegTo64(WA);

  // Update mem_ptr
  auto& memory = m_system.GetMemory();
  MOVP2R(MEM_REG, jo.fastmem ? memory.GetLogicalBase() : memory.GetLogicalPageMappingsBase());
  MOVP2R(XA, jo.fastmem ? memory.GetPhysicalBase() : memory.GetPhysicalPageMappingsBase());
  TST(msr, LogicalImm(1ULL << UReg_MSR{}.DR.StartBit(), GPRSize::B32));
  CSEL(MEM_REG, MEM_REG, XA, CCFlags::CC_NEQ);
  STR(IndexType::Unsigned, MEM_REG, PPC_REG, PPCSTATE_OFF(mem_ptr));

  // Update feature_flags
  static_assert(UReg_MSR{}.DR.StartBit() == 4);
  static_assert(UReg_MSR{}.IR.StartBit() == 5);
  static_assert(FEATURE_FLAG_MSR_DR == 1 << 0);
  static_assert(FEATURE_FLAG_MSR_IR == 1 << 1);
  const u32 other_feature_flags = m_ppc_state.feature_flags & ~0x3;
  UBFX(WA, msr, 4, 2);
  if (other_feature_flags != 0)
    ORR(WA, WA, LogicalImm(other_feature_flags, GPRSize::B32));
  STR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(feature_flags));

  // Call PageTableUpdatedFromJit if needed
  MOV(WA, msr);
  gpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
  fpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
  FixupBranch dr_unset = TBZ(WA, u8(UReg_MSR{}.DR.StartBit()));
  static_assert(PPCSTATE_OFF(pagetable_update_pending) < 0x1000);
  LDRB(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(pagetable_update_pending));
  FixupBranch update_not_pending = CBZ(WA);
  ABI_CallFunction(&PowerPC::MMU::PageTableUpdatedFromJit, &m_system.GetMMU());
  SetJumpTarget(update_not_pending);
  SetJumpTarget(dr_unset);
}

void JitArm64::WriteExit(u32 destination, bool LK, u32 exit_address_after_return,
                         ARM64Reg exit_address_after_return_reg)
{
  Cleanup();
  if (IsProfilingEnabled())
  {
    ABI_CallFunction(&JitBlock::ProfileData::EndProfiling, js.curBlock->profile_data.get(),
                     js.downcountAmount);
  }
  DoDownCount();

  LK &= m_enable_blr_optimization;

  const u8* host_address_after_return = nullptr;
  if (LK)
  {
    // Push {ARM_PC (64-bit); PPC_PC (32-bit); feature_flags (32-bit)} on the stack
    ARM64Reg reg_to_push = ARM64Reg::X1;
    const u64 feature_flags = m_ppc_state.feature_flags;
    if (exit_address_after_return_reg == ARM64Reg::INVALID_REG)
    {
      MOVI2R(ARM64Reg::X1, feature_flags << 32 | exit_address_after_return);
    }
    else if (feature_flags == 0)
    {
      reg_to_push = EncodeRegTo64(exit_address_after_return_reg);
    }
    else
    {
      ORRI2R(ARM64Reg::X1, EncodeRegTo64(exit_address_after_return_reg), feature_flags << 32,
             ARM64Reg::X1);
    }
    constexpr s32 adr_offset = JitArm64BlockCache::BLOCK_LINK_SIZE + sizeof(u32) * 2;
    host_address_after_return = GetCodePtr() + adr_offset;
    ADR(ARM64Reg::X0, adr_offset);
    STP(IndexType::Pre, ARM64Reg::X0, reg_to_push, ARM64Reg::SP, -16);
  }

  constexpr size_t primary_farcode_size = 3 * sizeof(u32);
  const bool switch_to_far_code = !IsInFarCode();
  const u8* primary_farcode_addr;
  if (switch_to_far_code)
  {
    SwitchToFarCode();
    primary_farcode_addr = GetCodePtr();
    SwitchToNearCode();
  }
  else
  {
    primary_farcode_addr = GetCodePtr() + JitArm64BlockCache::BLOCK_LINK_SIZE +
                           (LK ? JitArm64BlockCache::BLOCK_LINK_SIZE : 0);
  }
  const u8* return_farcode_addr = primary_farcode_addr + primary_farcode_size;

  JitBlock* b = js.curBlock;
  JitBlock::LinkData linkData;
  linkData.exitAddress = destination;
  linkData.exitPtrs = GetWritableCodePtr();
  linkData.linkStatus = false;
  linkData.call = LK;
  linkData.exitFarcode = primary_farcode_addr;
  b->linkData.push_back(linkData);

  blocks.WriteLinkBlock(*this, linkData);

  if (LK)
  {
    DEBUG_ASSERT(GetCodePtr() == host_address_after_return || HasWriteFailed());

    // Write the regular exit node after the return.
    linkData.exitAddress = exit_address_after_return;
    linkData.exitPtrs = GetWritableCodePtr();
    linkData.linkStatus = false;
    linkData.call = false;
    linkData.exitFarcode = return_farcode_addr;
    b->linkData.push_back(linkData);

    blocks.WriteLinkBlock(*this, linkData);
  }

  if (switch_to_far_code)
    SwitchToFarCode();
  DEBUG_ASSERT(GetCodePtr() == primary_farcode_addr || HasWriteFailed());
  MOVI2R(DISPATCHER_PC, destination);
  if (LK)
    BL(GetAsmRoutines()->do_timing);
  else
    B(GetAsmRoutines()->do_timing);

  if (LK)
  {
    if (GetCodePtr() == return_farcode_addr - sizeof(u32))
      BRK(101);
    DEBUG_ASSERT(GetCodePtr() == return_farcode_addr || HasWriteFailed());
    MOVI2R(DISPATCHER_PC, exit_address_after_return);
    B(GetAsmRoutines()->do_timing);
  }

  if (switch_to_far_code)
    SwitchToNearCode();
}

void JitArm64::WriteExit(Arm64Gen::ARM64Reg dest, bool LK, u32 exit_address_after_return,
                         ARM64Reg exit_address_after_return_reg)
{
  if (dest != DISPATCHER_PC)
    MOV(DISPATCHER_PC, dest);

  Cleanup();
  if (IsProfilingEnabled())
  {
    ABI_CallFunction(&JitBlock::ProfileData::EndProfiling, js.curBlock->profile_data.get(),
                     js.downcountAmount);
  }
  DoDownCount();

  LK &= m_enable_blr_optimization;

  if (!LK)
  {
    B(dispatcher);
  }
  else
  {
    // Push {ARM_PC (64-bit); PPC_PC (32-bit); feature_flags (32-bit)} on the stack
    ARM64Reg reg_to_push = ARM64Reg::X1;
    const u64 feature_flags = m_ppc_state.feature_flags;
    if (exit_address_after_return_reg == ARM64Reg::INVALID_REG)
    {
      MOVI2R(ARM64Reg::X1, feature_flags << 32 | exit_address_after_return);
    }
    else if (feature_flags == 0)
    {
      reg_to_push = EncodeRegTo64(exit_address_after_return_reg);
    }
    else
    {
      ORRI2R(ARM64Reg::X1, EncodeRegTo64(exit_address_after_return_reg), feature_flags << 32,
             ARM64Reg::X1);
    }
    constexpr s32 adr_offset = sizeof(u32) * 3;
    const u8* host_address_after_return = GetCodePtr() + adr_offset;
    ADR(ARM64Reg::X0, adr_offset);
    STP(IndexType::Pre, ARM64Reg::X0, reg_to_push, ARM64Reg::SP, -16);

    BL(dispatcher);
    DEBUG_ASSERT(GetCodePtr() == host_address_after_return || HasWriteFailed());

    // Write the regular exit node after the return.
    JitBlock* b = js.curBlock;
    JitBlock::LinkData linkData;
    linkData.exitAddress = exit_address_after_return;
    linkData.exitPtrs = GetWritableCodePtr();
    linkData.linkStatus = false;
    linkData.call = false;
    const bool switch_to_far_code = !IsInFarCode();
    if (switch_to_far_code)
    {
      SwitchToFarCode();
      linkData.exitFarcode = GetCodePtr();
      SwitchToNearCode();
    }
    else
    {
      linkData.exitFarcode = GetCodePtr() + JitArm64BlockCache::BLOCK_LINK_SIZE;
    }
    b->linkData.push_back(linkData);

    blocks.WriteLinkBlock(*this, linkData);

    if (switch_to_far_code)
      SwitchToFarCode();
    MOVI2R(DISPATCHER_PC, exit_address_after_return);
    B(GetAsmRoutines()->do_timing);
    if (switch_to_far_code)
      SwitchToNearCode();
  }
}

void JitArm64::FakeLKExit(u32 exit_address_after_return, ARM64Reg exit_address_after_return_reg)
{
  if (!m_enable_blr_optimization)
    return;

  // We may need to fake the BLR stack on inlined CALL instructions.
  // Else we can't return to this location any more.
  if (exit_address_after_return_reg != ARM64Reg::W30)
  {
    // Do not lock W30 if it is the same as the exit address register, since
    // it's already locked. It'll only get clobbered at the BL (below) where
    // we do not need its value anymore.
    // NOTE: This means W30 won't contain the return address anymore after this
    // function has been called!
    gpr.Lock(ARM64Reg::W30);
  }

  const u8* host_address_after_return;
  {
    // Push {ARM_PC (64-bit); PPC_PC (32-bit); feature_flags (32-bit)} on the stack
    Arm64RegCache::ScopedARM64Reg after_reg;
    ARM64Reg reg_to_push;
    const u64 feature_flags = m_ppc_state.feature_flags;
    if (exit_address_after_return_reg == ARM64Reg::INVALID_REG)
    {
      after_reg = gpr.GetScopedReg();
      reg_to_push = EncodeRegTo64(after_reg);
      MOVI2R(reg_to_push, feature_flags << 32 | exit_address_after_return);
    }
    else if (feature_flags == 0)
    {
      reg_to_push = EncodeRegTo64(exit_address_after_return_reg);
    }
    else
    {
      after_reg = gpr.GetScopedReg();
      reg_to_push = EncodeRegTo64(after_reg);
      ORRI2R(reg_to_push, EncodeRegTo64(exit_address_after_return_reg), feature_flags << 32,
             reg_to_push);
    }

    auto code_reg = gpr.GetScopedReg();
    constexpr s32 adr_offset = sizeof(u32) * 3;
    host_address_after_return = GetCodePtr() + adr_offset;
    ADR(EncodeRegTo64(code_reg), adr_offset);
    STP(IndexType::Pre, EncodeRegTo64(code_reg), reg_to_push, ARM64Reg::SP, -16);
  }

  FixupBranch skip_exit = BL();
  DEBUG_ASSERT(GetCodePtr() == host_address_after_return || HasWriteFailed());
  if (exit_address_after_return_reg != ARM64Reg::W30)
  {
    gpr.Unlock(ARM64Reg::W30);
  }

  // Write the regular exit node after the return.
  JitBlock* b = js.curBlock;
  JitBlock::LinkData linkData;
  linkData.exitAddress = exit_address_after_return;
  linkData.exitPtrs = GetWritableCodePtr();
  linkData.linkStatus = false;
  linkData.call = false;
  const bool switch_to_far_code = !IsInFarCode();
  if (switch_to_far_code)
  {
    SwitchToFarCode();
    linkData.exitFarcode = GetCodePtr();
    SwitchToNearCode();
  }
  else
  {
    linkData.exitFarcode = GetCodePtr() + JitArm64BlockCache::BLOCK_LINK_SIZE;
  }
  b->linkData.push_back(linkData);

  blocks.WriteLinkBlock(*this, linkData);

  if (switch_to_far_code)
    SwitchToFarCode();
  MOVI2R(DISPATCHER_PC, exit_address_after_return);
  B(GetAsmRoutines()->do_timing);
  if (switch_to_far_code)
    SwitchToNearCode();

  SetJumpTarget(skip_exit);
}

void JitArm64::WriteBLRExit(Arm64Gen::ARM64Reg dest)
{
  if (!m_enable_blr_optimization)
  {
    WriteExit(dest);
    return;
  }

  if (dest != DISPATCHER_PC)
    MOV(DISPATCHER_PC, dest);

  Cleanup();
  if (IsProfilingEnabled())
  {
    ABI_CallFunction(&JitBlock::ProfileData::EndProfiling, js.curBlock->profile_data.get(),
                     js.downcountAmount);
  }

  // Check if {PPC_PC, feature_flags} matches the current state, then RET to ARM_PC.
  LDP(IndexType::Post, ARM64Reg::X2, ARM64Reg::X1, ARM64Reg::SP, 16);
  const u64 feature_flags = m_ppc_state.feature_flags;
  if (feature_flags == 0)
  {
    CMP(ARM64Reg::X1, EncodeRegTo64(DISPATCHER_PC));
  }
  else
  {
    ORRI2R(ARM64Reg::X0, EncodeRegTo64(DISPATCHER_PC), feature_flags << 32, ARM64Reg::X0);
    CMP(ARM64Reg::X1, ARM64Reg::X0);
  }
  FixupBranch no_match = B(CC_NEQ);

  DoDownCount();  // overwrites X0 + X1

  RET(ARM64Reg::X2);

  SetJumpTarget(no_match);

  ResetStack();

  DoDownCount();

  B(dispatcher);
}

void JitArm64::WriteExceptionExit(u32 destination, bool only_external, bool always_exception)
{
  MOVI2R(DISPATCHER_PC, destination);
  WriteExceptionExit(DISPATCHER_PC, only_external, always_exception);
}

void JitArm64::WriteExceptionExit(ARM64Reg dest, bool only_external, bool always_exception)
{
  if (dest != DISPATCHER_PC)
    MOV(DISPATCHER_PC, dest);

  Cleanup();

  FixupBranch no_exceptions;
  if (!always_exception)
  {
    LDR(IndexType::Unsigned, ARM64Reg::W30, PPC_REG, PPCSTATE_OFF(Exceptions));
    no_exceptions = CBZ(ARM64Reg::W30);
  }

  static_assert(PPCSTATE_OFF(pc) <= 252);
  static_assert(PPCSTATE_OFF(pc) + 4 == PPCSTATE_OFF(npc));
  STP(IndexType::Signed, DISPATCHER_PC, DISPATCHER_PC, PPC_REG, PPCSTATE_OFF(pc));

  const auto f =
      only_external ? &PowerPC::CheckExternalExceptionsFromJIT : &PowerPC::CheckExceptionsFromJIT;
  ABI_CallFunction(f, &m_system.GetPowerPC());

  EmitUpdateMembase();

  LDR(IndexType::Unsigned, DISPATCHER_PC, PPC_REG, PPCSTATE_OFF(npc));

  if (!always_exception)
    SetJumpTarget(no_exceptions);

  if (IsProfilingEnabled())
  {
    ABI_CallFunction(&JitBlock::ProfileData::EndProfiling, js.curBlock->profile_data.get(),
                     js.downcountAmount);
  }
  DoDownCount();

  B(dispatcher);
}

void JitArm64::WriteConditionalExceptionExit(int exception, u64 increment_sp_on_exit)
{
  auto WA = gpr.GetScopedReg();
  WriteConditionalExceptionExit(exception, WA, Arm64Gen::ARM64Reg::INVALID_REG,
                                increment_sp_on_exit);
}

void JitArm64::WriteConditionalExceptionExit(int exception, ARM64Reg temp_gpr, ARM64Reg temp_fpr,
                                             u64 increment_sp_on_exit)
{
  LDR(IndexType::Unsigned, temp_gpr, PPC_REG, PPCSTATE_OFF(Exceptions));
  FixupBranch no_exception = TBZ(temp_gpr, MathUtil::IntLog2(exception));

  const bool switch_to_far_code = !IsInFarCode();

  if (switch_to_far_code)
  {
    FixupBranch handle_exception = B();
    SwitchToFarCode();
    SetJumpTarget(handle_exception);
  }

  if (increment_sp_on_exit != 0)
    ADDI2R(ARM64Reg::SP, ARM64Reg::SP, increment_sp_on_exit, temp_gpr);

  gpr.Flush(FlushMode::MaintainState, temp_gpr);
  fpr.Flush(FlushMode::MaintainState, temp_fpr);

  WriteExceptionExit(js.compilerPC, false, true);

  if (switch_to_far_code)
    SwitchToNearCode();

  SetJumpTarget(no_exception);
}

bool JitArm64::HandleFunctionHooking(u32 address)
{
  const auto result = HLE::TryReplaceFunction(m_ppc_symbol_db, address, PowerPC::CoreMode::JIT);
  if (!result)
    return false;

  HLEFunction(result.hook_index);

  if (result.type != HLE::HookType::Replace)
    return false;

  LDR(IndexType::Unsigned, DISPATCHER_PC, PPC_REG, PPCSTATE_OFF(npc));
  js.downcountAmount += js.st.numCycles;
  WriteExit(DISPATCHER_PC);
  return true;
}

void JitArm64::DumpCode(const u8* start, const u8* end)
{
  std::string output;
  for (const u8* code = start; code < end; code += sizeof(u32))
    output += fmt::format("{:08x}", Common::swap32(code));
  WARN_LOG_FMT(DYNA_REC, "Code dump from {} to {}:\n{}", fmt::ptr(start), fmt::ptr(end), output);
}

void JitArm64::Run()
{
  ProtectStack();
  m_system.GetJitInterface().UpdateMembase();

  CompiledCode pExecAddr = (CompiledCode)enter_code;
  pExecAddr();

  UnprotectStack();
}

void JitArm64::SingleStep()
{
  ProtectStack();
  m_system.GetJitInterface().UpdateMembase();

  CompiledCode pExecAddr = (CompiledCode)enter_code;
  pExecAddr();

  UnprotectStack();
}

void JitArm64::Trace()
{
  std::string regs;
  std::string fregs;

#ifdef JIT_LOG_GPR
  for (size_t i = 0; i < std::size(m_ppc_state.gpr); i++)
  {
    regs += fmt::format("r{:02d}: {:08x} ", i, m_ppc_state.gpr[i]);
  }
#endif

#ifdef JIT_LOG_FPR
  for (size_t i = 0; i < std::size(m_ppc_state.ps); i++)
  {
    fregs += fmt::format("f{:02d}: {:016x} ", i, m_ppc_state.ps[i].PS0AsU64());
  }
#endif

  DEBUG_LOG_FMT(DYNA_REC,
                "JitArm64 PC: {:08x} SRR0: {:08x} SRR1: {:08x} FPSCR: {:08x} "
                "MSR: {:08x} LR: {:08x} {} {}",
                m_ppc_state.pc, SRR0(m_ppc_state), SRR1(m_ppc_state), m_ppc_state.fpscr.Hex,
                m_ppc_state.msr.Hex, m_ppc_state.spr[8], regs, fregs);
}

