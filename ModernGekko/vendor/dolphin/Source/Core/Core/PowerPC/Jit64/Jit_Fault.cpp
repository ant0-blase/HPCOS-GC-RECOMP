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

bool Jit64::HandleFault(uintptr_t access_address, SContext* ctx)
{
  const uintptr_t stack_guard = reinterpret_cast<uintptr_t>(m_stack_guard);
  // In the trap region?
  if (m_enable_blr_optimization && access_address >= stack_guard &&
      access_address < stack_guard + GUARD_SIZE)
  {
    return HandleStackFault();
  }

  // This generates some fairly heavy trampolines, but it doesn't really hurt.
  // Only instructions that access I/O will get these, and there won't be that
  // many of them in a typical program/game.

  auto& memory = m_system.GetMemory();

  if (memory.IsAddressInFastmemArea(reinterpret_cast<u8*>(access_address)))
  {
    auto& ppc_state = m_system.GetPPCState();
    const uintptr_t memory_base = reinterpret_cast<uintptr_t>(
        ppc_state.msr.DR ? memory.GetLogicalBase() : memory.GetPhysicalBase());

    if (access_address < memory_base || access_address >= memory_base + 0x1'0000'0000)
    {
      WARN_LOG_FMT(DYNA_REC,
                   "Jit64 address calculation overflowed! Please report if this happens a lot. "
                   "PC {:#018x}, access address {:#018x}, memory base {:#018x}, MSR.DR {}",
                   ctx->CTX_PC, access_address, memory_base, ppc_state.msr.DR);
    }

    return BackPatch(ctx);
  }

  return false;
}

bool Jit64::BackPatch(SContext* ctx)
{
  u8* codePtr = reinterpret_cast<u8*>(ctx->CTX_PC);

  if (!IsInSpace(codePtr))
    return false;  // this will become a regular crash real soon after this

  auto it = m_back_patch_info.find(codePtr);
  if (it == m_back_patch_info.end())
  {
    PanicAlertFmt("BackPatch: no register use entry for address {}", fmt::ptr(codePtr));
    return false;
  }

  TrampolineInfo& info = it->second;

  u8* exceptionHandler = nullptr;
  if (jo.memcheck)
  {
    auto it2 = m_exception_handler_at_loc.find(codePtr);
    if (it2 != m_exception_handler_at_loc.end())
      exceptionHandler = it2->second;
  }

  // In the trampoline code, we jump back into the block at the beginning
  // of the next instruction. The next instruction comes immediately
  // after the backpatched operation, or BACKPATCH_SIZE bytes after the start
  // of the backpatched operation, whichever comes last. (The JIT inserts NOPs
  // into the original code if necessary to ensure there is enough space
  // to insert the backpatch jump.)

  js.generatingTrampoline = true;
  js.trampolineExceptionHandler = exceptionHandler;
  js.compilerPC = info.pc;

  // Generate the trampoline.
  const u8* trampoline = trampolines.GenerateTrampoline(info);
  js.generatingTrampoline = false;
  js.trampolineExceptionHandler = nullptr;

  u8* start = info.start;

  // Patch the original memory operation.
  XEmitter emitter(start, start + info.len);
  emitter.JMP(trampoline);
  // NOPs become dead code
  const u8* end = info.start + info.len;
  for (const u8* i = emitter.GetCodePtr(); i < end; ++i)
    emitter.INT3();

  // Rewind time to just before the start of the write block. If we swapped memory
  // before faulting (eg: the store+swap was not an atomic op like MOVBE), let's
  // swap it back so that the swap can happen again (this double swap isn't ideal but
  // only happens the first time we fault).
  if (info.nonAtomicSwapStoreSrc != Gen::INVALID_REG)
  {
    u64* ptr = ContextRN(ctx, info.nonAtomicSwapStoreSrc);
    switch (info.accessSize << 3)
    {
    case 8:
      // No need to swap a byte
      break;
    case 16:
      *ptr = Common::swap16(static_cast<u16>(*ptr));
      break;
    case 32:
      *ptr = Common::swap32(static_cast<u32>(*ptr));
      break;
    case 64:
      *ptr = Common::swap64(static_cast<u64>(*ptr));
      break;
    default:
      DEBUG_ASSERT(false);
      break;
    }
  }

  // This is special code to undo the LEA in SafeLoadToReg if it clobbered the address
  // register in the case where reg_value shared the same location as opAddress.
  if (info.offsetAddedToAddress)
  {
    u64* ptr = ContextRN(ctx, info.op_arg.GetSimpleReg());
    *ptr = static_cast<u32>(*ptr - info.offset);
  }

  ctx->CTX_PC = reinterpret_cast<u64>(trampoline);

  return true;
}
