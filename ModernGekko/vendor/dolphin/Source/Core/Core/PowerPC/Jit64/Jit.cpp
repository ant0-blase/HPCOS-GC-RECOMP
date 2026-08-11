// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/Jit64/Jit.h"

#include <map>
#include <span>
#include <sstream>
#include <string>
#include <utility>

#include <fmt/format.h>
#include <fmt/ostream.h>

// for the PROFILER stuff
#ifdef _WIN32
#include <windows.h>
#endif

#include "Common/CommonTypes.h"
#include "Common/GekkoDisassembler.h"
#include "Common/HostDisassembler.h"
#include "Common/IOFile.h"
#include "Common/Logging/Log.h"
#include "Common/Swap.h"
#include "Common/x64ABI.h"
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

// Dolphin's PowerPC->x86_64 JIT dynamic recompiler
// Written mostly by ector (hrydgard)
// Features:
// * Basic block linking
// * Fast dispatcher

// Unfeatures:
// * Does not recompile all instructions - sometimes falls back to inserting a CALL to the
// corresponding Interpreter function.

// Open questions
// * Should there be any statically allocated registers? r3, r4, r5, r8, r0 come to mind.. maybe sp
// * Does it make sense to finish off the remaining non-jitted instructions? Seems we are hitting
// diminishing returns.

// Other considerations
//
// We support block linking. Reserve space at the exits of every block for a full 5-byte jmp. Save
// 16-bit offsets
// from the starts of each block, marking the exits so that they can be nicely patched at any time.
//
// Blocks do NOT use call/ret, they only jmp to each other and to the dispatcher when necessary.
//
// All blocks that can be precompiled will be precompiled. Code will be memory protected - any write
// will mark
// the region as non-compilable, and all links to the page will be torn out and replaced with
// dispatcher jmps.
//
// Alternatively, icbi instruction SHOULD mark where we can't compile
//
// Seldom-happening events is handled by adding a decrement of a counter to all blr instructions
// (which are
// expensive anyway since we need to return to dispatcher, except when they can be predicted).

// TODO: SERIOUS synchronization problem with the video backend setting tokens and breakpoints in
// dual core mode!!!
//       Somewhat fixed by disabling idle skipping when certain interrupts are enabled
//       This is no permanent reliable fix
// TODO: Zeldas go whacko when you hang the gfx thread

// Idea - Accurate exception handling
// Compute register state at a certain instruction by running the JIT in "dry mode", and stopping at
// the right place.
// Not likely to be done :P

// Optimization Ideas -
/*
  * Assume SP is in main RAM (in Wii mode too?) - partly done
  * Assume all floating point loads and double precision loads+stores are to/from main ram
    (single precision stores can be used in write gather pipe, specialized fast check added)
  * AMD only - use movaps instead of movapd when loading ps from memory?
  * HLE functions like floorf, sin, memcpy, etc - they can be much faster
  * ABI optimizations - drop F0-F13 on blr, for example. Watch out for context switching.
    CR2-CR4 are non-volatile, rest of CR is volatile -> dropped on blr.
  R5-R12 are volatile -> dropped on blr.
  * classic inlining across calls.
  * Track which registers a block clobbers without using, then take advantage of this knowledge
    when compiling a block that links to that block.
  * Track more dependencies between instructions, e.g. avoiding PPC_FP code, single/double
    conversion, movddup on non-paired singles, etc where possible.
  * Support loads/stores directly from xmm registers in jit_util and the backpatcher; this might
    help AMD a lot since gpr/xmm transfers are slower there.
  * Smarter register allocation in general; maybe learn to drop values once we know they won't be
    used again before being overwritten?
  * More flexible reordering; there's limits to how far we can go because of exception handling
    and such, but it's currently limited to integer ops only. This can definitely be made better.
*/

Jit64::Jit64(Core::System& system)
    : JitBase(system), QuantizedMemoryRoutines(*this),
      m_disassembler(HostDisassembler::Factory(HostDisassembler::Platform::x86_64))
{
}

Jit64::~Jit64() = default;




void Jit64::FallBackToInterpreter(UGeckoInstruction inst)
{
  FlushCarry();
  gpr.Flush(BitSet32(0xFFFFFFFF), RegCache::IgnoreDiscardedRegisters::Yes);
  fpr.Flush(BitSet32(0xFFFFFFFF), RegCache::IgnoreDiscardedRegisters::Yes);

  if (js.op->canEndBlock)
  {
    MOV(32, PPCSTATE(pc), Imm32(js.compilerPC));
    MOV(32, PPCSTATE(npc), Imm32(js.compilerPC + 4));
  }

  Interpreter::Instruction instr = Interpreter::GetInterpreterOp(inst);
  ABI_PushRegistersAndAdjustStack({}, 0);
  ABI_CallFunctionPC(instr, &m_system.GetInterpreter(), inst.hex);
  ABI_PopRegistersAndAdjustStack({}, 0);

  // If the instruction wrote to any registers which were marked as discarded,
  // we must mark them as no longer discarded
  gpr.Reset(js.op->regsOut);
  fpr.Reset(js.op->GetFregsOut());

  // We must also update constant propagation
  m_constant_propagation.ClearGPRs(js.op->regsOut);

  if (js.op->opinfo->flags & FL_SET_MSR)
    EmitUpdateMembase();

  if (js.op->canEndBlock)
  {
    if (js.isLastInstruction)
    {
      MOV(32, R(RSCRATCH), PPCSTATE(npc));
      MOV(32, PPCSTATE(pc), R(RSCRATCH));
      WriteExceptionExit();
    }
    else
    {
      MOV(32, R(RSCRATCH), PPCSTATE(npc));
      CMP(32, R(RSCRATCH), Imm32(js.compilerPC + 4));
      FixupBranch c = J_CC(CC_Z);
      MOV(32, PPCSTATE(pc), R(RSCRATCH));
      WriteExceptionExit();
      SetJumpTarget(c);
    }
  }
  else if (ShouldHandleFPExceptionForInstruction(js.op))
  {
    TEST(32, PPCSTATE(Exceptions), Imm32(EXCEPTION_PROGRAM));
    FixupBranch exception = J_CC(CC_NZ, Jump::Near);

    SwitchToFarCode();
    SetJumpTarget(exception);

    RCForkGuard gpr_guard = gpr.Fork();
    RCForkGuard fpr_guard = fpr.Fork();

    gpr.Flush();
    fpr.Flush();

    MOV(32, PPCSTATE(pc), Imm32(js.op->address));
    WriteExceptionExit();
    SwitchToNearCode();
  }
}

void Jit64::HLEFunction(u32 hook_index)
{
  gpr.Flush();
  fpr.Flush();
  ABI_PushRegistersAndAdjustStack({}, 0);
  ABI_CallFunctionCCP(HLE::ExecuteFromJIT, js.compilerPC, hook_index, &m_system);
  ABI_PopRegistersAndAdjustStack({}, 0);
}

void Jit64::DoNothing(UGeckoInstruction _inst)
{
  // Yup, just don't do anything.
}

void Jit64::ImHere(Jit64& jit)
{
  auto& ppc_state = jit.m_ppc_state;
  static File::IOFile f;
  if (jit.m_im_here_log)
  {
    if (!f)
      f.Open("log64.txt", "w");

    f.WriteString(fmt::format("{0:08x}\n", ppc_state.pc));
  }
  auto& been_here = jit.m_been_here;
  auto it = been_here.find(ppc_state.pc);
  if (it != been_here.end())
  {
    it->second++;
    if (it->second & 1023)
      return;
  }
  INFO_LOG_FMT(DYNA_REC, "I'm here - PC = {:08x} , LR = {:08x}", ppc_state.pc, LR(ppc_state));
  been_here[ppc_state.pc] = 1;
}

bool Jit64::Cleanup()
{
  bool did_something = false;

  if (jo.optimizeGatherPipe && js.fifoBytesSinceCheck > 0)
  {
    MOV(64, R(RSCRATCH), PPCSTATE(gather_pipe_ptr));
    SUB(64, R(RSCRATCH), PPCSTATE(gather_pipe_base_ptr));
    CMP(64, R(RSCRATCH), Imm32(GPFifo::GATHER_PIPE_SIZE));
    FixupBranch exit = J_CC(CC_L);
    ABI_PushRegistersAndAdjustStack({}, 0);
    ABI_CallFunctionP(GPFifo::UpdateGatherPipe, &m_system.GetGPFifo());
    ABI_PopRegistersAndAdjustStack({}, 0);
    SetJumpTarget(exit);
    did_something = true;
  }

  if (m_ppc_state.feature_flags & FEATURE_FLAG_PERFMON)
  {
    ABI_PushRegistersAndAdjustStack({}, 0);
    ABI_CallFunctionCCCP(PowerPC::UpdatePerformanceMonitor, js.downcountAmount, js.numLoadStoreInst,
                         js.numFloatingPointInst, &m_ppc_state);
    ABI_PopRegistersAndAdjustStack({}, 0);
    did_something = true;
  }

  if (IsProfilingEnabled())
  {
    ABI_PushRegistersAndAdjustStack({}, 0);
    ABI_CallFunctionPC(&JitBlock::ProfileData::EndProfiling, js.curBlock->profile_data.get(),
                       js.downcountAmount);
    ABI_PopRegistersAndAdjustStack({}, 0);
    did_something = true;
  }

  return did_something;
}

void Jit64::FakeBLCall(u32 after)
{
  if (!m_enable_blr_optimization)
    return;

  // We may need to fake the BLR stack on inlined CALL instructions.
  // Else we can't return to this location any more.
  MOV(64, R(RSCRATCH2), Imm64(u64(m_ppc_state.feature_flags) << 32 | after));
  PUSH(RSCRATCH2);
  FixupBranch skip_exit = CALL();
  POP(RSCRATCH2);
  JustWriteExit(after, false, 0);
  SetJumpTarget(skip_exit);
}

void Jit64::EmitUpdateMembase()
{
  MOV(64, R(RMEM), PPCSTATE(mem_ptr));
}

void Jit64::MSRUpdated(const OpArg& msr, X64Reg scratch_reg)
{
  ASSERT(!msr.IsSimpleReg(scratch_reg));

  constexpr u32 dr_bit = 1 << UReg_MSR{}.DR.StartBit();

  // Update mem_ptr
  auto& memory = m_system.GetMemory();
  if (msr.IsImm())
  {
    MOV(64, R(RMEM),
        ImmPtr(UReg_MSR(msr.Imm32()).DR ? memory.GetLogicalBase() : memory.GetPhysicalBase()));
  }
  else
  {
    MOV(64, R(RMEM), ImmPtr(memory.GetLogicalBase()));
    MOV(64, R(scratch_reg), ImmPtr(memory.GetPhysicalBase()));
    TEST(32, msr, Imm32(dr_bit));
    CMOVcc(64, RMEM, R(scratch_reg), CC_Z);
  }
  MOV(64, PPCSTATE(mem_ptr), R(RMEM));

  // Update feature_flags
  static_assert(UReg_MSR{}.DR.StartBit() == 4);
  static_assert(UReg_MSR{}.IR.StartBit() == 5);
  static_assert(FEATURE_FLAG_MSR_DR == 1 << 0);
  static_assert(FEATURE_FLAG_MSR_IR == 1 << 1);
  const u32 other_feature_flags = m_ppc_state.feature_flags & ~0x3;
  if (msr.IsImm())
  {
    MOV(32, PPCSTATE(feature_flags), Imm32(other_feature_flags | ((msr.Imm32() >> 4) & 0x3)));
  }
  else
  {
    MOV(32, R(scratch_reg), msr);
    SHR(32, R(scratch_reg), Imm8(4));
    AND(32, R(scratch_reg), Imm32(0x3));
    if (other_feature_flags != 0)
      OR(32, R(scratch_reg), Imm32(other_feature_flags));
    MOV(32, PPCSTATE(feature_flags), R(scratch_reg));
  }

  // Call PageTableUpdatedFromJit if needed
  if (!msr.IsImm() || UReg_MSR(msr.Imm32()).DR)
  {
    gpr.Flush();
    fpr.Flush();
    FixupBranch dr_unset;
    if (!msr.IsImm())
    {
      TEST(32, msr, Imm32(dr_bit));
      dr_unset = J_CC(CC_Z);
    }
    CMP(8, PPCSTATE(pagetable_update_pending), Imm8(0));
    FixupBranch update_not_pending = J_CC(CC_E);
    ABI_CallFunctionP(&PowerPC::MMU::PageTableUpdatedFromJit, &m_system.GetMMU());
    SetJumpTarget(update_not_pending);
    if (!msr.IsImm())
      SetJumpTarget(dr_unset);
  }
}

void Jit64::WriteExit(u32 destination, bool bl, u32 after)
{
  if (!m_enable_blr_optimization)
    bl = false;

  Cleanup();

  if (bl)
  {
    MOV(64, R(RSCRATCH2), Imm64(u64(m_ppc_state.feature_flags) << 32 | after));
    PUSH(RSCRATCH2);
  }

  SUB(32, PPCSTATE(downcount), Imm32(js.downcountAmount));

  JustWriteExit(destination, bl, after);
}

void Jit64::JustWriteExit(u32 destination, bool bl, u32 after)
{
  // If nobody has taken care of this yet (this can be removed when all branches are done)
  JitBlock* b = js.curBlock;
  JitBlock::LinkData linkData;
  linkData.exitAddress = destination;
  linkData.linkStatus = false;
  linkData.call = bl;

  MOV(32, PPCSTATE(pc), Imm32(destination));

  // Perform downcount flag check, followed by the requested exit
  if (bl)
  {
    FixupBranch do_timing = J_CC(CC_LE, Jump::Near);
    SwitchToFarCode();
    SetJumpTarget(do_timing);
    CALL(asm_routines.do_timing);
    FixupBranch after_fixup = J(Jump::Near);
    SwitchToNearCode();

    linkData.exitPtrs = GetWritableCodePtr();
    CALL(asm_routines.dispatcher_no_timing_check);

    SetJumpTarget(after_fixup);
    POP(RSCRATCH);
    JustWriteExit(after, false, 0);
  }
  else
  {
    J_CC(CC_LE, asm_routines.do_timing);

    linkData.exitPtrs = GetWritableCodePtr();
    // Padding required for correctness, as the JMP length might differ between dispatcher and
    // linked block: if this wrote a Short JMP but then JitBlockCache::WriteLinkBlock wrote a Near
    // JMP, the latter would overwrite other instructions.
    JMP(asm_routines.dispatcher_no_timing_check, true);
  }

  b->linkData.push_back(linkData);
}

void Jit64::WriteExitDestInRSCRATCH(bool bl, u32 after)
{
  if (!m_enable_blr_optimization)
    bl = false;
  MOV(32, PPCSTATE(pc), R(RSCRATCH));
  Cleanup();

  if (bl)
  {
    MOV(64, R(RSCRATCH2), Imm64(u64(m_ppc_state.feature_flags) << 32 | after));
    PUSH(RSCRATCH2);
  }

  SUB(32, PPCSTATE(downcount), Imm32(js.downcountAmount));
  if (bl)
  {
    CALL(asm_routines.dispatcher);
    POP(RSCRATCH);
    JustWriteExit(after, false, 0);
  }
  else
  {
    JMP(asm_routines.dispatcher);
  }
}

void Jit64::WriteBLRExit()
{
  if (!m_enable_blr_optimization)
  {
    WriteExitDestInRSCRATCH();
    return;
  }
  MOV(32, PPCSTATE(pc), R(RSCRATCH));
  bool disturbed = Cleanup();
  if (disturbed)
    MOV(32, R(RSCRATCH), PPCSTATE(pc));
  if (m_ppc_state.feature_flags != 0)
  {
    MOV(32, R(RSCRATCH2), Imm32(m_ppc_state.feature_flags));
    SHL(64, R(RSCRATCH2), Imm8(32));
    OR(64, R(RSCRATCH), R(RSCRATCH2));
  }
  MOV(32, R(RSCRATCH2), Imm32(js.downcountAmount));
  CMP(64, R(RSCRATCH), MDisp(RSP, 8));
  J_CC(CC_NE, asm_routines.dispatcher_mispredicted_blr);
  SUB(32, PPCSTATE(downcount), R(RSCRATCH2));
  RET();
}

void Jit64::WriteRfiExitDestInRSCRATCH()
{
  MOV(32, PPCSTATE(pc), R(RSCRATCH));
  MOV(32, PPCSTATE(npc), R(RSCRATCH));
  Cleanup();
  ABI_PushRegistersAndAdjustStack({}, 0);
  ABI_CallFunctionP(PowerPC::CheckExceptionsFromJIT, &m_system.GetPowerPC());
  ABI_PopRegistersAndAdjustStack({}, 0);
  EmitUpdateMembase();
  SUB(32, PPCSTATE(downcount), Imm32(js.downcountAmount));
  JMP(asm_routines.dispatcher);
}

void Jit64::WriteIdleExit(u32 destination)
{
  ABI_PushRegistersAndAdjustStack({}, 0);
  ABI_CallFunction(CoreTiming::GlobalIdle);
  ABI_PopRegistersAndAdjustStack({}, 0);
  MOV(32, PPCSTATE(pc), Imm32(destination));
  WriteExceptionExit();
}

void Jit64::WriteExceptionExit()
{
  Cleanup();
  MOV(32, R(RSCRATCH), PPCSTATE(pc));
  MOV(32, PPCSTATE(npc), R(RSCRATCH));
  ABI_PushRegistersAndAdjustStack({}, 0);
  ABI_CallFunctionP(PowerPC::CheckExceptionsFromJIT, &m_system.GetPowerPC());
  ABI_PopRegistersAndAdjustStack({}, 0);
  EmitUpdateMembase();
  SUB(32, PPCSTATE(downcount), Imm32(js.downcountAmount));
  JMP(asm_routines.dispatcher);
}

void Jit64::WriteExternalExceptionExit()
{
  Cleanup();
  MOV(32, R(RSCRATCH), PPCSTATE(pc));
  MOV(32, PPCSTATE(npc), R(RSCRATCH));
  ABI_PushRegistersAndAdjustStack({}, 0);
  ABI_CallFunctionP(PowerPC::CheckExternalExceptionsFromJIT, &m_system.GetPowerPC());
  ABI_PopRegistersAndAdjustStack({}, 0);
  EmitUpdateMembase();
  SUB(32, PPCSTATE(downcount), Imm32(js.downcountAmount));
  JMP(asm_routines.dispatcher);
}

void Jit64::Run()
{
  ProtectStack();
  m_system.GetJitInterface().UpdateMembase();

  CompiledCode pExecAddr = (CompiledCode)asm_routines.enter_code;
  pExecAddr();

  UnprotectStack();
}

void Jit64::SingleStep()
{
  ProtectStack();
  m_system.GetJitInterface().UpdateMembase();

  CompiledCode pExecAddr = (CompiledCode)asm_routines.enter_code;
  pExecAddr();

  UnprotectStack();
}

void Jit64::Trace()
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
                "JIT64 PC: {:08x} SRR0: {:08x} SRR1: {:08x} FPSCR: {:08x} "
                "MSR: {:08x} LR: {:08x} {} {}",
                m_ppc_state.pc, SRR0(m_ppc_state), SRR1(m_ppc_state), m_ppc_state.fpscr.Hex,
                m_ppc_state.msr.Hex, m_ppc_state.spr[8], regs, fregs);
}

