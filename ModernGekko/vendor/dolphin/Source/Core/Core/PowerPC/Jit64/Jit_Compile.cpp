// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/Jit64/Jit.h"

#include <map>
#include <span>
#include <sstream>
#include <string>
#include <utility>

#include <fmt/format.h>
#include <fmt/ostream.h>

#include "Common/CommonTypes.h"
#include "Common/GekkoDisassembler.h"
#include "Common/HostDisassembler.h"
#include "Common/IOFile.h"
#include "Common/Logging/Log.h"
#include "Common/Swap.h"
#include "Common/x64ABI.h"
#include "Core/Config/MainSettings.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/HLE/HLE.h"
#include "Core/HW/CPU.h"
#include "Core/HW/GPFifo.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/ProcessorInterface.h"
#include "Core/Host.h"
#include "Core/MachineContext.h"
#include "Core/Cheats/PatchEngine.h"
#include "Core/PowerPC/Interpreter/Interpreter.h"
#include "Core/PowerPC/Jit64/JitAsm.h"
#include "Core/PowerPC/Jit64/RegCache/JitRegCache.h"
#include "Core/PowerPC/Jit64Common/FarCodeCache.h"
#include "Core/PowerPC/Jit64Common/Jit64Constants.h"
#include "Core/PowerPC/Jit64Common/Jit64PowerPCState.h"
#include "Core/PowerPC/Jit64Common/TrampolineCache.h"
#include "Core/PowerPC/JitCommon/ConstantPropagation.h"
#include "Core/PowerPC/JitInterface.h"
#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/PPCAnalyst.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/System.h"

using namespace Gen;
using namespace PowerPC;

void Jit64::Jit(u32 em_address)
{
  Jit(em_address, true);
}

void Jit64::Jit(u32 em_address, bool clear_cache_and_retry_on_failure)
{
  CleanUpAfterStackFault();

  if (trampolines.IsAlmostFull() || SConfig::GetInstance().bJITNoBlockCache)
  {
    if (!SConfig::GetInstance().bJITNoBlockCache)
    {
      WARN_LOG_FMT(DYNA_REC, "flushing trampoline code cache, please report if this happens a lot");
    }
    ClearCache();
  }
  FreeRanges();

  std::size_t block_size = m_code_buffer.size();

  if (IsDebuggingEnabled())
  {
    // We can link blocks as long as we are not single stepping
    EnableBlockLink();
    EnableOptimization();

    if (!IsProfilingEnabled())
    {
      if (m_system.GetCPU().IsStepping())
      {
        block_size = 1;

        // Do not link this block to other blocks While single stepping
        jo.enableBlocklink = false;
        analyzer.ClearOption(PPCAnalyst::PPCAnalyzer::OPTION_CONDITIONAL_CONTINUE);
        analyzer.ClearOption(PPCAnalyst::PPCAnalyzer::OPTION_BRANCH_MERGE);
        analyzer.ClearOption(PPCAnalyst::PPCAnalyzer::OPTION_CROR_MERGE);
        analyzer.ClearOption(PPCAnalyst::PPCAnalyzer::OPTION_CARRY_MERGE);
        analyzer.ClearOption(PPCAnalyst::PPCAnalyzer::OPTION_BRANCH_FOLLOW);
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

  if (SetEmitterStateToFreeCodeRegion())
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
        m_free_ranges_near.erase(near_start, near_end);
      u8* far_end = m_far_code.GetWritableCodePtr();
      if (far_start != far_end)
        m_free_ranges_far.erase(far_start, far_end);

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
  std::exit(-1);
}

bool Jit64::SetEmitterStateToFreeCodeRegion()
{
  // Find the largest free memory blocks and set code emitters to point at them.
  // If we can't find a free block return false instead, which will trigger a JIT cache clear.
  const auto free_near = m_free_ranges_near.by_size_begin();
  if (free_near == m_free_ranges_near.by_size_end())
  {
    WARN_LOG_FMT(DYNA_REC, "Failed to find free memory region in near code region.");
    return false;
  }
  SetCodePtr(free_near.from(), free_near.to());

  const auto free_far = m_free_ranges_far.by_size_begin();
  if (free_far == m_free_ranges_far.by_size_end())
  {
    WARN_LOG_FMT(DYNA_REC, "Failed to find free memory region in far code region.");
    return false;
  }
  m_far_code.SetCodePtr(free_far.from(), free_far.to());

  return true;
}

bool Jit64::DoJit(u32 em_address, JitBlock* b, u32 nextPC)
{
  js.firstFPInstructionFound = false;
  js.isLastInstruction = false;
  js.blockStart = em_address;
  js.fifoBytesSinceCheck = 0;
  js.mustCheckFifo = false;
  js.curBlock = b;
  js.numLoadStoreInst = 0;
  js.numFloatingPointInst = 0;

  // TODO: Test if this or AlignCode16 make a difference from GetCodePtr
  b->normalEntry = AlignCode4();

  // Used to get a trace of the last few blocks before a crash, sometimes VERY useful
  if (m_im_here_debug)
  {
    ABI_PushRegistersAndAdjustStack({}, 0);
    ABI_CallFunctionP(ImHere, this);
    ABI_PopRegistersAndAdjustStack({}, 0);
  }

  // Conditionally add profiling code.
  if (IsProfilingEnabled())
    ABI_CallFunctionP(&JitBlock::ProfileData::BeginProfiling, b->profile_data.get());

#if defined(_DEBUG) || defined(DEBUGFAST) || defined(NAN_CHECK)
  // should help logged stack-traces become more accurate
  MOV(32, PPCSTATE(pc), Imm32(js.blockStart));
#endif

  // Start up the register allocators
  // They use the information in gpa/fpa to preload commonly used registers.
  gpr.Start();
  fpr.Start();

  m_constant_propagation.Clear();

  js.downcountAmount = 0;
  js.skipInstructions = 0;
  js.carryFlag = CarryFlag::InPPCState;
  js.constantGqrValid = BitSet8();

  // Assume that GQR values don't change often at runtime. Many paired-heavy games use largely float
  // loads and stores, which are significantly faster when inlined (especially in MMU mode, where
  // this lets them use fastmem).
  if (!js.pairedQuantizeAddresses.contains(js.blockStart))
  {
    // If there are GQRs used but not set, we'll treat those as constant and optimize them
    BitSet8 gqr_static = ComputeStaticGQRs(code_block);
    if (gqr_static)
    {
      SwitchToFarCode();
      const u8* target = GetCodePtr();
      MOV(32, PPCSTATE(pc), Imm32(js.blockStart));
      ABI_PushRegistersAndAdjustStack({}, 0);
      ABI_CallFunctionPC(JitInterface::CompileExceptionCheckFromJIT, &m_system.GetJitInterface(),
                         static_cast<u32>(JitInterface::ExceptionType::PairedQuantize));
      ABI_PopRegistersAndAdjustStack({}, 0);
      JMP(asm_routines.dispatcher_no_check);
      SwitchToNearCode();

      // Insert a check that the GQRs are still the value we expect at
      // the start of the block in case our guess turns out wrong.
      for (int gqr : gqr_static)
      {
        u32 value = GQR(m_ppc_state, gqr);
        js.constantGqr[gqr] = value;
        CMP_or_TEST(32, PPCSTATE_SPR(SPR_GQR0 + gqr), Imm32(value));
        J_CC(CC_NZ, target);
      }
      js.constantGqrValid = gqr_static;
    }
  }

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
    js.fastmemLoadStore = nullptr;
    js.fixupExceptionHandler = false;

    if (i == (code_block.m_num_instructions - 1))
    {
      js.isLastInstruction = true;
    }

    if (i != 0)
    {
      // Gather pipe writes using a non-immediate address are discovered by profiling.
      const u32 prev_address = m_code_buffer[i - 1].address;
      bool gatherPipeIntCheck = js.fifoWriteAddresses.contains(prev_address);

      // Gather pipe writes using an immediate address are explicitly tracked.
      if (jo.optimizeGatherPipe &&
          (js.fifoBytesSinceCheck >= GPFifo::GATHER_PIPE_SIZE || js.mustCheckFifo))
      {
        js.fifoBytesSinceCheck = 0;
        js.mustCheckFifo = false;
        BitSet32 registersInUse = CallerSavedRegistersInUse();
        ABI_PushRegistersAndAdjustStack(registersInUse, 0);
        ABI_CallFunctionP(GPFifo::FastCheckGatherPipe, &m_system.GetGPFifo());
        ABI_PopRegistersAndAdjustStack(registersInUse, 0);
        gatherPipeIntCheck = true;
      }

      // Gather pipe writes can generate an exception; add an exception check.
      // TODO: This doesn't really match hardware; the CP interrupt is
      // asynchronous.
      if (gatherPipeIntCheck)
      {
        TEST(32, PPCSTATE(Exceptions), Imm32(EXCEPTION_EXTERNAL_INT));
        FixupBranch extException = J_CC(CC_NZ, Jump::Near);

        SwitchToFarCode();
        SetJumpTarget(extException);
        TEST(32, PPCSTATE(msr), Imm32(0x0008000));
        FixupBranch noExtIntEnable = J_CC(CC_Z, Jump::Near);
        MOV(64, R(RSCRATCH), ImmPtr(&m_system.GetProcessorInterface().m_interrupt_cause));
        TEST(32, MatR(RSCRATCH),
             Imm32(ProcessorInterface::INT_CAUSE_CP | ProcessorInterface::INT_CAUSE_PE_TOKEN |
                   ProcessorInterface::INT_CAUSE_PE_FINISH));
        FixupBranch noCPInt = J_CC(CC_Z, Jump::Near);

        {
          RCForkGuard gpr_guard = gpr.Fork();
          RCForkGuard fpr_guard = fpr.Fork();

          gpr.Flush();
          fpr.Flush();

          MOV(32, PPCSTATE(pc), Imm32(op.address));
          WriteExternalExceptionExit();
        }
        SwitchToNearCode();
        SetJumpTarget(noCPInt);
        SetJumpTarget(noExtIntEnable);
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
        WriteBranchWatch<true>(op.address, op.branchTo, op.inst, CallerSavedRegistersInUse());
      }
    }
    else
    {
      auto& cpu = m_system.GetCPU();
      auto& power_pc = m_system.GetPowerPC();
      if (IsDebuggingEnabled() && power_pc.GetBreakPoints().IsAddressBreakPoint(op.address) &&
          !cpu.IsStepping())
      {
        gpr.Flush();
        fpr.Flush();

        MOV(32, PPCSTATE(pc), Imm32(op.address));
        ABI_PushRegistersAndAdjustStack({}, 0);
        ABI_CallFunctionP(PowerPC::CheckAndHandleBreakPointsFromJIT, &power_pc);
        ABI_PopRegistersAndAdjustStack({}, 0);
        MOV(64, R(RSCRATCH), ImmPtr(cpu.GetStatePtr()));
        CMP(32, MatR(RSCRATCH), Imm32(std::to_underlying(CPU::State::Running)));
        FixupBranch noBreakpoint = J_CC(CC_E);

        Cleanup();
        MOV(32, PPCSTATE(npc), Imm32(op.address));
        SUB(32, PPCSTATE(downcount), Imm32(js.downcountAmount));
        JMP(asm_routines.dispatcher_exit);

        SetJumpTarget(noBreakpoint);
      }

      if ((opinfo->flags & FL_USE_FPU) && !js.firstFPInstructionFound)
      {
        // This instruction uses FPU - needs to add FP exception bailout
        TEST(32, PPCSTATE(msr), Imm32(1 << 13));  // Test FP enabled bit
        FixupBranch b1 = J_CC(CC_Z, Jump::Near);

        SwitchToFarCode();
        SetJumpTarget(b1);
        {
          RCForkGuard gpr_guard = gpr.Fork();
          RCForkGuard fpr_guard = fpr.Fork();

          gpr.Flush();
          fpr.Flush();

          // If a FPU exception occurs, the exception handler will read
          // from PC.  Update PC with the latest value in case that happens.
          MOV(32, PPCSTATE(pc), Imm32(op.address));
          OR(32, PPCSTATE(Exceptions), Imm32(EXCEPTION_FPU_UNAVAILABLE));
          WriteExceptionExit();
        }
        SwitchToNearCode();

        js.firstFPInstructionFound = true;
      }

      if (bJITRegisterCacheOff)
      {
        gpr.Flush();
        fpr.Flush();
        m_constant_propagation.Clear();

        CompileInstruction(op);
      }
      else
      {
        const JitCommon::ConstantPropagationResult constant_propagation_result =
            m_constant_propagation.EvaluateInstruction(op.inst, opinfo->flags);

        if (!constant_propagation_result.instruction_fully_executed)
        {
          if (!bJITRegisterCacheOff)
          {
            // If we have an input register that is going to be used again, load it pre-emptively,
            // even if the instruction doesn't strictly need it in a register, to avoid redundant
            // loads later. Of course, don't do this if we're already out of registers.
            // As a bit of a heuristic, make sure we have at least one register left over for the
            // output, which needs to be bound in the actual instruction compilation.
            // TODO: make this smarter in the case that we're actually register-starved, i.e.
            // prioritize the more important registers.
            gpr.PreloadRegisters(op.regsIn & op.gprInUse & ~op.gprDiscardable);
            fpr.PreloadRegisters(op.fregsIn & op.fprInXmm & ~op.fprDiscardable);
          }

          CompileInstruction(op);
        }

        m_constant_propagation.Apply(constant_propagation_result);

        if (constant_propagation_result.gpr >= 0)
        {
          // Mark the GPR as dirty in the register cache
          gpr.SetImmediate32(constant_propagation_result.gpr,
                             constant_propagation_result.gpr_value);
        }

        if (constant_propagation_result.instruction_fully_executed)
        {
          if (constant_propagation_result.carry)
            FinalizeCarry(*constant_propagation_result.carry);

          if (constant_propagation_result.overflow)
            GenerateConstantOverflow(*constant_propagation_result.overflow);

          // FinalizeImmediateRC is called last, because it may trigger branch merging
          if (constant_propagation_result.compute_rc)
            FinalizeImmediateRC(constant_propagation_result.gpr_value);
        }
      }

      js.fpr_is_store_safe = op.fprIsStoreSafeAfterInst;

      if (jo.memcheck && (opinfo->flags & FL_LOADSTORE))
      {
        // If we have a fastmem loadstore, we can omit the exception check and let fastmem handle
        // it.
        FixupBranch memException;
        ASSERT_MSG(DYNA_REC, !(js.fastmemLoadStore && js.fixupExceptionHandler),
                   "Fastmem loadstores shouldn't have exception handler fixups (PC={:x})!",
                   op.address);
        if (!js.fastmemLoadStore && !js.fixupExceptionHandler)
        {
          TEST(32, PPCSTATE(Exceptions), Imm32(EXCEPTION_DSI));
          memException = J_CC(CC_NZ, Jump::Near);
        }

        SwitchToFarCode();
        if (!js.fastmemLoadStore)
        {
          m_exception_handler_at_loc[js.fastmemLoadStore] = nullptr;
          SetJumpTarget(js.fixupExceptionHandler ? js.exceptionHandler : memException);
        }
        else
        {
          m_exception_handler_at_loc[js.fastmemLoadStore] = GetWritableCodePtr();
        }

        RCForkGuard gpr_guard = gpr.Fork();
        RCForkGuard fpr_guard = fpr.Fork();

        gpr.Revert();
        fpr.Revert();
        gpr.Flush();
        fpr.Flush();

        MOV(32, PPCSTATE(pc), Imm32(op.address));
        WriteExceptionExit();
        SwitchToNearCode();
      }

      gpr.Commit();
      fpr.Commit();

      // If we have a register that will never be used again, discard or flush it.
      if (!bJITRegisterCacheOff)
      {
        gpr.Discard(op.gprDiscardable);
        fpr.Discard(op.fprDiscardable);
      }
      gpr.Flush(~op.gprInUse & (op.regsIn | op.regsOut));
      fpr.Flush(~op.fprInUse & (op.fregsIn | op.GetFregsOut()));

      if (opinfo->flags & FL_LOADSTORE)
        ++js.numLoadStoreInst;

      if (opinfo->flags & FL_USE_FPU)
        ++js.numFloatingPointInst;
    }

#if defined(_DEBUG) || defined(DEBUGFAST)
    if (!gpr.SanityCheck() || !fpr.SanityCheck())
    {
      const std::string ppc_inst = Common::GekkoDisassembler::Disassemble(op.inst.hex, em_address);
      NOTICE_LOG_FMT(DYNA_REC, "Unflushed register: {}", ppc_inst);
    }
#endif
    i += js.skipInstructions;
    js.skipInstructions = 0;
  }

  if (code_block.m_broken)
  {
    gpr.Flush();
    fpr.Flush();
    WriteExit(nextPC);
  }

  // When linking to an entry point immediately following it in memory, a JIT block's furthest
  // exit can, as a micro-optimization, overwrite the JMP instruction with a multibyte NOP.
  // See: 'JitBlockCache::WriteLinkBlock'
  // In order to do this in a non-sketchy way, a JIT block must own the alignment padding bytes.
  AlignCode4();  // TODO: Test if this or AlignCode16 make a difference from GetCodePtr

  if (HasWriteFailed() || m_far_code.HasWriteFailed())
  {
    if (HasWriteFailed())
      WARN_LOG_FMT(DYNA_REC, "JIT ran out of space in near code region during code generation.");
    if (m_far_code.HasWriteFailed())
      WARN_LOG_FMT(DYNA_REC, "JIT ran out of space in far code region during code generation.");

    return false;
  }

  return true;
}

void Jit64::EraseSingleBlock(const JitBlock& block)
{
  blocks.EraseSingleBlock(block);
  FreeRanges();
}

std::vector<JitBase::MemoryStats> Jit64::GetMemoryStats() const
{
  return {{"near", m_free_ranges_near.get_stats()}, {"far", m_free_ranges_far.get_stats()}};
}

std::size_t Jit64::DisassembleNearCode(const JitBlock& block, std::ostream& stream) const
{
  return m_disassembler->Disassemble(block.normalEntry, block.near_end, stream);
}

std::size_t Jit64::DisassembleFarCode(const JitBlock& block, std::ostream& stream) const
{
  return m_disassembler->Disassemble(block.far_begin, block.far_end, stream);
}

BitSet8 Jit64::ComputeStaticGQRs(const PPCAnalyst::CodeBlock& cb) const
{
  return cb.m_gqr_used & ~cb.m_gqr_modified;
}

BitSet32 Jit64::CallerSavedRegistersInUse(BitSet32 additional_registers) const
{
  BitSet32 in_use = gpr.RegistersInUse() | (fpr.RegistersInUse() << 16) | additional_registers;
  return in_use & ABI_ALL_CALLER_SAVED;
}

void Jit64::EnableBlockLink()
{
  jo.enableBlocklink = true;
  if (SConfig::GetInstance().bJITNoBlockLinking || IsStaticRecompFallback())
    jo.enableBlocklink = false;
}

void Jit64::EnableOptimization()
{
  analyzer.SetOption(PPCAnalyst::PPCAnalyzer::OPTION_CONDITIONAL_CONTINUE);
  analyzer.SetOption(PPCAnalyst::PPCAnalyzer::OPTION_BRANCH_MERGE);
  analyzer.SetOption(PPCAnalyst::PPCAnalyzer::OPTION_CROR_MERGE);
  analyzer.SetOption(PPCAnalyst::PPCAnalyzer::OPTION_CARRY_MERGE);
  analyzer.SetOption(PPCAnalyst::PPCAnalyzer::OPTION_BRANCH_FOLLOW);
}

void Jit64::IntializeSpeculativeConstants()
{
  // If the block depends on an input register which looks like a gather pipe or MMIO related
  // constant, guess that it is actually a constant input, and specialize the block based on this
  // assumption. This happens when there are branches in code writing to the gather pipe, but only
  // the first block loads the constant.
  // Insert a check at the start of the block to verify that the value is actually constant.
  // This can save a lot of backpatching and optimize gather pipe writes in more places.
  const u8* target = nullptr;
  for (auto i : code_block.m_gpr_inputs)
  {
    u32 compileTimeValue = m_ppc_state.gpr[i];
    if (m_mmu.IsOptimizableGatherPipeWrite(compileTimeValue) ||
        m_mmu.IsOptimizableGatherPipeWrite(compileTimeValue - 0x8000) ||
        compileTimeValue == 0xCC000000)
    {
      if (!target)
      {
        SwitchToFarCode();
        target = GetCodePtr();
        MOV(32, PPCSTATE(pc), Imm32(js.blockStart));
        ABI_PushRegistersAndAdjustStack({}, 0);
        ABI_CallFunctionPC(JitInterface::CompileExceptionCheckFromJIT, &m_system.GetJitInterface(),
                           static_cast<u32>(JitInterface::ExceptionType::SpeculativeConstants));
        ABI_PopRegistersAndAdjustStack({}, 0);
        JMP(asm_routines.dispatcher_no_check);
        SwitchToNearCode();
      }
      CMP(32, PPCSTATE_GPR(i), Imm32(compileTimeValue));
      J_CC(CC_NZ, target);
      gpr.SetImmediate32(i, compileTimeValue, false);
    }
  }
}

void Jit64::FlushRegistersBeforeSlowAccess()
{
  // Register values can be used by memory watchpoint conditions.
  MemChecks& mem_checks = m_system.GetPowerPC().GetMemChecks();
  if (mem_checks.HasAny())
  {
    BitSet32 gprs = mem_checks.GetGPRsUsedInConditions();
    BitSet32 fprs = mem_checks.GetFPRsUsedInConditions();
    if (gprs || fprs)
    {
      RCForkGuard gpr_guard = gpr.Fork();
      RCForkGuard fpr_guard = fpr.Fork();

      gpr.Flush(gprs);
      fpr.Flush(fprs);
    }
  }
}

bool Jit64::HandleFunctionHooking(u32 address)
{
  const auto result = HLE::TryReplaceFunction(m_ppc_symbol_db, address, PowerPC::CoreMode::JIT);
  if (!result)
    return false;

  HLEFunction(result.hook_index);

  if (result.type != HLE::HookType::Replace)
    return false;

  MOV(32, R(RSCRATCH), PPCSTATE(npc));
  js.downcountAmount += js.st.numCycles;
  WriteExitDestInRSCRATCH();
  return true;
}

void Jit64::LogGeneratedCode() const
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
