// Copyright 2026 Dolphin Emulator Project
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

void JitArm64::Jit(u32 em_address)
{
  Jit(em_address, true);
}

void JitArm64::Jit(u32 em_address, bool clear_cache_and_retry_on_failure)
{
  CleanUpAfterStackFault();

  if (SConfig::GetInstance().bJITNoBlockCache)
    ClearCache();
  FreeRanges();

  const Common::ScopedJITPageWriteAndNoExecute enable_jit_page_writes;

  std::size_t block_size = m_code_buffer.size();

  auto& cpu = m_system.GetCPU();

  if (IsDebuggingEnabled())
  {
    // We can link blocks as long as we are not single stepping
    SetBlockLinkingEnabled(true);
    SetOptimizationEnabled(true);

    if (!IsProfilingEnabled())
    {
      if (cpu.IsStepping())
      {
        block_size = 1;

        // Do not link this block to other blocks while single stepping
        SetBlockLinkingEnabled(false);
        SetOptimizationEnabled(false);
      }
      Trace();
    }
  }

  // Analyze the block, collect all instructions it is made of (including inlining,
  // if that is enabled), reorder instructions for optimal performance, and join joinable
  // instructions.
  const u32 nextPC = analyzer.Analyze(em_address, &code_block, &m_code_buffer, block_size);

  if (code_block.m_memory_exception)
  {
    // Address of instruction could not be translated
    m_ppc_state.npc = nextPC;
    m_ppc_state.Exceptions |= EXCEPTION_ISI;
    m_system.GetPowerPC().CheckExceptions();
    m_system.GetJitInterface().UpdateMembase();
    WARN_LOG_FMT(POWERPC, "ISI exception at {:#010x}", nextPC);
    return;
  }

  if (std::optional<size_t> code_region_index = SetEmitterStateToFreeCodeRegion())
  {
    u8* near_start = GetWritableCodePtr();
    u8* far_start = m_far_code.GetWritableCodePtr();

    JitBlock* b = blocks.AllocateBlock(em_address);
    if (DoJit(em_address, b, nextPC))
    {
      // Code generation succeeded.

      // Mark the memory regions that this code block uses as used in the local rangesets.
      u8* near_end = GetWritableCodePtr();
      if (near_start != near_end)
      {
        (code_region_index == 0 ? m_free_ranges_near_0 : m_free_ranges_near_1)
            .erase(near_start, near_end);
      }
      u8* far_end = m_far_code.GetWritableCodePtr();
      if (far_start != far_end)
      {
        (code_region_index == 0 ? m_free_ranges_far_0 : m_free_ranges_far_1)
            .erase(far_start, far_end);
      }

      // Store the used memory regions in the block so we know what to mark as unused when the
      // block gets invalidated.
      b->near_begin = near_start;
      b->near_end = near_end;
      b->far_begin = far_start;
      b->far_end = far_end;

      blocks.FinalizeBlock(*b, jo.enableBlocklink, code_block, m_code_buffer);

#ifdef JIT_LOG_GENERATED_CODE
      LogGeneratedCode();
#endif
      return;
    }
  }

  if (clear_cache_and_retry_on_failure)
  {
    // Code generation failed due to not enough free space in either the near or far code regions.
    // Clear the entire JIT cache and retry.
    WARN_LOG_FMT(DYNA_REC, "flushing code caches, please report if this happens a lot");
    ClearCache();
    Jit(em_address, false);
    return;
  }

  PanicAlertFmtT("JIT failed to find code space after a cache clear. This should never happen. "
                 "Please report this incident on the bug tracker. Dolphin will now exit.");
  exit(-1);
}

void JitArm64::EraseSingleBlock(const JitBlock& block)
{
  blocks.EraseSingleBlock(block);
  FreeRanges();
}

std::vector<JitBase::MemoryStats> JitArm64::GetMemoryStats() const
{
  return {{"near_0", m_free_ranges_near_0.get_stats()},
          {"near_1", m_free_ranges_near_1.get_stats()},
          {"far_0", m_free_ranges_far_0.get_stats()},
          {"far_1", m_free_ranges_far_1.get_stats()}};
}

std::size_t JitArm64::DisassembleNearCode(const JitBlock& block, std::ostream& stream) const
{
  return m_disassembler->Disassemble(block.normalEntry, block.near_end, stream);
}

std::size_t JitArm64::DisassembleFarCode(const JitBlock& block, std::ostream& stream) const
{
  return m_disassembler->Disassemble(block.far_begin, block.far_end, stream);
}

std::optional<size_t> JitArm64::SetEmitterStateToFreeCodeRegion()
{
  // Find some large free memory blocks and set code emitters to point at them. If we can't find
  // free blocks, return std::nullopt instead, which will trigger a JIT cache clear.
  const auto free_near_0 = m_free_ranges_near_0.by_size_begin();
  const auto free_near_1 = m_free_ranges_near_1.by_size_begin();
  const auto free_far_0 = m_free_ranges_far_0.by_size_begin();
  const auto free_far_1 = m_free_ranges_far_1.by_size_begin();

  const size_t free_near_1_size = free_near_1.to() - free_near_1.from();
  const size_t free_far_1_size = free_far_1.to() - free_far_1.from();
  const size_t free_1_smallest_size = std::min(free_near_1_size, free_far_1_size);

  if (free_1_smallest_size >= 1024 * 1024)
  {
    // Don't use region 0 unless region 1 is getting full. This improves cache friendliness.
    SetCodePtr(free_near_1.from(), free_near_1.to());
    m_far_code.SetCodePtr(free_far_1.from(), free_far_1.to());
    return std::make_optional(1);
  }

  const size_t free_near_0_size = free_near_0.to() - free_near_0.from();
  const size_t free_far_0_size = free_far_0.to() - free_far_0.from();
  const size_t free_0_smallest_size = std::min(free_near_0_size, free_far_0_size);

  if (free_0_smallest_size == 0 && free_1_smallest_size == 0)
  {
    if (free_near_0_size == 0 && free_near_1_size == 0)
      WARN_LOG_FMT(DYNA_REC, "Failed to find free memory region in near code regions.");
    else if (free_far_0_size == 0 && free_far_1_size == 0)
      WARN_LOG_FMT(DYNA_REC, "Failed to find free memory region in far code regions.");
    return std::nullopt;
  }

  if (free_0_smallest_size > free_1_smallest_size)
  {
    SetCodePtr(free_near_0.from(), free_near_0.to());
    m_far_code.SetCodePtr(free_far_0.from(), free_far_0.to());
    return std::make_optional(0);
  }
  else
  {
    SetCodePtr(free_near_1.from(), free_near_1.to());
    m_far_code.SetCodePtr(free_far_1.from(), free_far_1.to());
    return std::make_optional(1);
  }
}

bool JitArm64::DoJit(u32 em_address, JitBlock* b, u32 nextPC)
{
  auto& cpu = m_system.GetCPU();

  js.isLastInstruction = false;
  js.firstFPInstructionFound = false;
  js.assumeNoPairedQuantize = false;
  js.blockStart = em_address;
  js.fifoBytesSinceCheck = 0;
  js.mustCheckFifo = false;
  js.downcountAmount = 0;
  js.skipInstructions = 0;
  js.curBlock = b;
  js.carryFlag = CarryFlag::InPPCState;
  js.numLoadStoreInst = 0;
  js.numFloatingPointInst = 0;

  b->normalEntry = GetWritableCodePtr();

  // Conditionally add profiling code.
  if (IsProfilingEnabled())
    ABI_CallFunction(&JitBlock::ProfileData::BeginProfiling, b->profile_data.get());

  if (code_block.m_gqr_used.Count() == 1 && !js.pairedQuantizeAddresses.contains(js.blockStart))
  {
    int gqr = *code_block.m_gqr_used.begin();
    if (!code_block.m_gqr_modified[gqr] && !GQR(m_ppc_state, gqr))
    {
      LDR(IndexType::Unsigned, ARM64Reg::W0, PPC_REG, PPCSTATE_OFF_SPR(SPR_GQR0 + gqr));
      FixupBranch no_fail = CBZ(ARM64Reg::W0);
      FixupBranch fail = B();
      SwitchToFarCode();
      SetJumpTarget(fail);
      MOVI2R(DISPATCHER_PC, js.blockStart);
      STR(IndexType::Unsigned, DISPATCHER_PC, PPC_REG, PPCSTATE_OFF(pc));
      ABI_CallFunction(&JitInterface::CompileExceptionCheckFromJIT, &m_system.GetJitInterface(),
                       static_cast<u32>(JitInterface::ExceptionType::PairedQuantize));
      B(dispatcher_no_check);
      SwitchToNearCode();
      SetJumpTarget(no_fail);
      js.assumeNoPairedQuantize = true;
    }
  }

  gpr.Start(js.gpa);
  fpr.Start(js.fpa);

  m_constant_propagation.Clear();

  if (!js.noSpeculativeConstantsAddresses.contains(js.blockStart))
  {
    IntializeSpeculativeConstants();
  }

  // Translate instructions
  for (u32 i = 0; i < code_block.m_num_instructions; i++)
  {
    PPCAnalyst::CodeOp& op = m_code_buffer[i];

    js.compilerPC = op.address;
    js.op = &op;
    js.fpr_is_store_safe = op.fprIsStoreSafeBeforeInst;
    js.instructionsLeft = (code_block.m_num_instructions - 1) - i;
    const GekkoOPInfo* opinfo = op.opinfo;
    js.downcountAmount += opinfo->num_cycles;
    js.isLastInstruction = i == (code_block.m_num_instructions - 1);

    // Skip calling UpdateLastUsed for lmw/stmw - it usually hurts more than it helps
    if (op.inst.OPCD != 46 && op.inst.OPCD != 47)
      gpr.UpdateLastUsed(op.regsIn | op.regsOut);

    BitSet32 fpr_used = op.fregsIn;
    if (op.fregOut >= 0)
      fpr_used[op.fregOut] = true;
    fpr.UpdateLastUsed(fpr_used);

    if (i != 0)
    {
      // Gather pipe writes using a non-immediate address are discovered by profiling.
      const u32 prev_address = m_code_buffer[i - 1].address;
      bool gatherPipeIntCheck = js.fifoWriteAddresses.contains(prev_address);

      if (jo.optimizeGatherPipe &&
          (js.fifoBytesSinceCheck >= GPFifo::GATHER_PIPE_SIZE || js.mustCheckFifo))
      {
        js.fifoBytesSinceCheck = 0;
        js.mustCheckFifo = false;

        gpr.Lock(ARM64Reg::W30);
        BitSet32 regs_in_use = gpr.GetCallerSavedUsed();
        BitSet32 fprs_in_use = fpr.GetCallerSavedUsed();
        regs_in_use[DecodeReg(ARM64Reg::W30)] = false;

        ABI_PushRegisters(regs_in_use);
        m_float_emit.ABI_PushRegisters(fprs_in_use, ARM64Reg::X30);
        ABI_CallFunction(&GPFifo::FastCheckGatherPipe, &m_system.GetGPFifo());
        m_float_emit.ABI_PopRegisters(fprs_in_use, ARM64Reg::X30);
        ABI_PopRegisters(regs_in_use);

        gpr.Unlock(ARM64Reg::W30);
        gatherPipeIntCheck = true;
      }
      // Gather pipe writes can generate an exception; add an exception check.
      // TODO: This doesn't really match hardware; the CP interrupt is
      // asynchronous.
      if (jo.optimizeGatherPipe && gatherPipeIntCheck)
      {
        auto WA = gpr.GetScopedReg();
        ARM64Reg XA = EncodeRegTo64(WA);

        LDR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(Exceptions));
        FixupBranch no_ext_exception = TBZ(WA, MathUtil::IntLog2(EXCEPTION_EXTERNAL_INT));
        FixupBranch exception = B();
        SwitchToFarCode();
        const u8* done_here = GetCodePtr();
        FixupBranch exit = B();
        SetJumpTarget(exception);
        LDR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(msr));
        TBZ(WA, 15, done_here);  // MSR.EE
        LDR(IndexType::Unsigned, WA, XA,
            MOVPage2R(XA, &m_system.GetProcessorInterface().m_interrupt_cause));
        constexpr u32 cause_mask = ProcessorInterface::INT_CAUSE_CP |
                                   ProcessorInterface::INT_CAUSE_PE_TOKEN |
                                   ProcessorInterface::INT_CAUSE_PE_FINISH;
        TST(WA, LogicalImm(cause_mask, GPRSize::B32));
        B(CC_EQ, done_here);

        gpr.Flush(FlushMode::MaintainState, WA);
        fpr.Flush(FlushMode::MaintainState, ARM64Reg::INVALID_REG);
        WriteExceptionExit(js.compilerPC, true, true);
        SwitchToNearCode();
        SetJumpTarget(no_ext_exception);
        SetJumpTarget(exit);
      }
    }

    if (HandleFunctionHooking(op.address))
      break;

    if (op.skip)
    {
      if (IsBranchWatchEnabled())
      {
        // The only thing that currently sets op.skip is the BLR following optimization.
        // If any non-branch instruction starts setting that too, this will need to be changed.
        ASSERT(op.inst.hex == 0x4e800020);
        WriteBranchWatch<true>(op.address, op.branchTo, op.inst, gpr.GetCallerSavedUsed(),
                               fpr.GetCallerSavedUsed());
      }
    }
    else
    {
      if (IsDebuggingEnabled() && !cpu.IsStepping() &&
          m_system.GetPowerPC().GetBreakPoints().IsAddressBreakPoint(op.address))
      {
        FlushCarry();
        gpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
        fpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);

        static_assert(PPCSTATE_OFF(pc) <= 252);
        static_assert(PPCSTATE_OFF(pc) + 4 == PPCSTATE_OFF(npc));

        MOVI2R(DISPATCHER_PC, op.address);
        STP(IndexType::Signed, DISPATCHER_PC, DISPATCHER_PC, PPC_REG, PPCSTATE_OFF(pc));
        ABI_CallFunction(&PowerPC::CheckAndHandleBreakPointsFromJIT, &m_system.GetPowerPC());

        LDR(IndexType::Unsigned, ARM64Reg::W0, ARM64Reg::X0,
            MOVPage2R(ARM64Reg::X0, cpu.GetStatePtr()));
        static_assert(std::to_underlying(CPU::State::Running) == 0);
        FixupBranch no_breakpoint = CBZ(ARM64Reg::W0);

        Cleanup();
        if (IsProfilingEnabled())
        {
          ABI_CallFunction(&JitBlock::ProfileData::EndProfiling, b->profile_data.get(),
                           js.downcountAmount);
        }
        DoDownCount();
        B(dispatcher_exit);

        SetJumpTarget(no_breakpoint);
      }

      if ((opinfo->flags & FL_USE_FPU) && !js.firstFPInstructionFound)
      {
        FixupBranch b1;
        // This instruction uses FPU - needs to add FP exception bailout
        {
          auto WA = gpr.GetScopedReg();
          LDR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(msr));
          b1 = TBNZ(WA, 13);  // Test FP enabled bit

          FixupBranch far_addr = B();
          SwitchToFarCode();
          SetJumpTarget(far_addr);

          gpr.Flush(FlushMode::MaintainState, WA);
          fpr.Flush(FlushMode::MaintainState, ARM64Reg::INVALID_REG);

          LDR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(Exceptions));
          ORR(WA, WA, LogicalImm(EXCEPTION_FPU_UNAVAILABLE, GPRSize::B32));
          STR(IndexType::Unsigned, WA, PPC_REG, PPCSTATE_OFF(Exceptions));
        }

        WriteExceptionExit(js.compilerPC, false, true);

        SwitchToNearCode();

        SetJumpTarget(b1);

        js.firstFPInstructionFound = true;
      }

      if (bJITRegisterCacheOff)
      {
        FlushCarry();
        gpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
        fpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
        m_constant_propagation.Clear();

        CompileInstruction(op);
      }
      else
      {
        const JitCommon::ConstantPropagationResult constant_propagation_result =
            m_constant_propagation.EvaluateInstruction(op.inst, opinfo->flags);

        if (!constant_propagation_result.instruction_fully_executed)
          CompileInstruction(op);

        m_constant_propagation.Apply(constant_propagation_result);

        if (constant_propagation_result.gpr >= 0)
        {
          // Mark the GPR as dirty in the register cache
          gpr.SetImmediate(constant_propagation_result.gpr, constant_propagation_result.gpr_value);
        }

        if (constant_propagation_result.instruction_fully_executed)
        {
          if (constant_propagation_result.carry)
            ComputeCarry(*constant_propagation_result.carry);

          if (constant_propagation_result.overflow)
            GenerateConstantOverflow(*constant_propagation_result.overflow);

          if (constant_propagation_result.compute_rc)
            ComputeRC0(constant_propagation_result.gpr_value);
        }
      }

      js.fpr_is_store_safe = op.fprIsStoreSafeAfterInst;

      if (!CanMergeNextInstructions(1) || js.op[1].opinfo->type != ::OpType::Integer)
        FlushCarry();

      // If we have a register that will never be used again, discard or flush it.
      if (!bJITRegisterCacheOff)
      {
        gpr.DiscardRegisters(op.gprDiscardable);
        fpr.DiscardRegisters(op.fprDiscardable);
        gpr.DiscardCRRegisters(op.crDiscardable);
      }
      gpr.StoreRegisters(~op.gprInUse & (op.regsIn | op.regsOut));
      fpr.StoreRegisters(~op.fprInUse & (op.fregsIn | op.GetFregsOut()));
      gpr.StoreCRRegisters(~op.crInUse & (op.crIn | op.crOut));

      if (opinfo->flags & FL_LOADSTORE)
        ++js.numLoadStoreInst;

      if (opinfo->flags & FL_USE_FPU)
        ++js.numFloatingPointInst;
    }

    i += js.skipInstructions;
    js.skipInstructions = 0;
  }

  if (code_block.m_broken)
  {
    gpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
    fpr.Flush(FlushMode::All, ARM64Reg::INVALID_REG);
    WriteExit(nextPC);
  }

  if (HasWriteFailed() || m_far_code.HasWriteFailed())
  {
    if (HasWriteFailed())
      WARN_LOG_FMT(DYNA_REC, "JIT ran out of space in near code region during code generation.");
    if (m_far_code.HasWriteFailed())
      WARN_LOG_FMT(DYNA_REC, "JIT ran out of space in far code region during code generation.");

    return false;
  }

  FlushIcache();
  m_far_code.FlushIcache();

  return true;
}

void JitArm64::LogGeneratedCode() const
{
  std::ostringstream stream;

  stream << "\nPPC Code Buffer:\n";
  for (const PPCAnalyst::CodeOp& op :
       std::span{m_code_buffer.data(), code_block.m_num_instructions})
  {
    fmt::print(stream, "0x{:08x}\t\t{}\n", op.address,
               Common::GekkoDisassembler::Disassemble(op.inst.hex, op.address));
  }

  const JitBlock* const block = js.curBlock;
  stream << "\nHost Near Code:\n";
  m_disassembler->Disassemble(block->normalEntry, block->near_end, stream);
  stream << "\nHost Far Code:\n";
  m_disassembler->Disassemble(block->far_begin, block->far_end, stream);

  // TODO C++20: std::ostringstream::view()
  DEBUG_LOG_FMT(DYNA_REC, "{}", std::move(stream).str());
}
