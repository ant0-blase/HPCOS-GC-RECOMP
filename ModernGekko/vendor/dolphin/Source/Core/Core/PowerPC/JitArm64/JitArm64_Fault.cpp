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

bool JitArm64::HandleFault(uintptr_t access_address, SContext* ctx)
{
  // Ifdef this since the exception handler runs on a separate thread on macOS (ARM)
#if !(defined(__APPLE__) && defined(_M_ARM_64))
  // We can't handle any fault from other threads.
  if (!Core::IsCPUThread())
  {
    ERROR_LOG_FMT(DYNA_REC, "Exception handler - Not on CPU thread");
    DoBacktrace(access_address, ctx);
    return false;
  }
#endif

  bool success = false;

  // Handle BLR stack faults, may happen in C++ code.
  const uintptr_t stack_guard = reinterpret_cast<uintptr_t>(m_stack_guard);
  if (access_address >= stack_guard && access_address < stack_guard + GUARD_SIZE)
    success = HandleStackFault();

  // If the fault is in JIT code space, look for fastmem areas.
  if (!success && IsInSpaceOrChildSpace(reinterpret_cast<u8*>(ctx->CTX_PC)))
  {
    auto& memory = m_system.GetMemory();
    if (memory.IsAddressInFastmemArea(reinterpret_cast<u8*>(access_address)))
    {
      const uintptr_t memory_base = reinterpret_cast<uintptr_t>(
          m_ppc_state.msr.DR ? memory.GetLogicalBase() : memory.GetPhysicalBase());

      if (access_address < memory_base || access_address >= memory_base + 0x1'0000'0000)
      {
        ERROR_LOG_FMT(DYNA_REC,
                      "JitArm64 address calculation overflowed. This should never happen! "
                      "PC {:#018x}, access address {:#018x}, memory base {:#018x}, MSR.DR {}, "
                      "mem_ptr {}, pbase {}, lbase {}",
                      ctx->CTX_PC, access_address, memory_base, m_ppc_state.msr.DR,
                      fmt::ptr(m_ppc_state.mem_ptr), fmt::ptr(memory.GetPhysicalBase()),
                      fmt::ptr(memory.GetLogicalBase()));
      }
      else
      {
        success = HandleFastmemFault(ctx);
      }
    }
  }

  if (!success)
  {
    ERROR_LOG_FMT(DYNA_REC, "Exception handler - Unhandled fault");
    DoBacktrace(access_address, ctx);
  }
  return success;
}
