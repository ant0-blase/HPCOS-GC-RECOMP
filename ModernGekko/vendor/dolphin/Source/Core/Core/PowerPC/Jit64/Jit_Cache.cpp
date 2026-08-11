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

void Jit64::Init()
{
  InitFastmemArena();

  RefreshConfig();

  EnableBlockLink();

  jo.optimizeGatherPipe = true;
  jo.accurateSinglePrecision = true;
  js.fastmemLoadStore = nullptr;
  js.compilerPC = 0;

  gpr.SetEmitter(this);
  fpr.SetEmitter(this);

  const size_t routines_size = asm_routines.CODE_SIZE;
  const size_t trampolines_size = jo.memcheck ? TRAMPOLINE_CODE_SIZE_MMU : TRAMPOLINE_CODE_SIZE;
  const size_t farcode_size = jo.memcheck ? FARCODE_SIZE_MMU : FARCODE_SIZE;
  const size_t constpool_size = m_const_pool.CONST_POOL_SIZE;
  AllocCodeSpace(CODE_SIZE + routines_size + trampolines_size + farcode_size + constpool_size);
  AddChildCodeSpace(&asm_routines, routines_size);
  AddChildCodeSpace(&trampolines, trampolines_size);
  AddChildCodeSpace(&m_far_code, farcode_size);
  m_const_pool.Init(AllocChildCodeSpace(constpool_size), constpool_size);
  ResetCodePtr();

  InitBLROptimization();

  m_stack_guard = nullptr;

  blocks.Init();
  asm_routines.Init();

  // important: do this *after* generating the global asm routines, because we can't use farcode in
  // them.
  // it'll crash because the farcode functions get cleared on JIT clears.
  m_far_code.Init();
  Clear();

  code_block.m_stats = &js.st;
  code_block.m_gpa = &js.gpa;
  code_block.m_fpa = &js.fpa;
  EnableOptimization();

  ResetFreeMemoryRanges();
}

void Jit64::ClearCache()
{
  blocks.Clear();
  blocks.ClearRangesToFree();
  trampolines.ClearCodeSpace();
  m_far_code.ClearCodeSpace();
  m_const_pool.Clear();
  ClearCodeSpace();
  Clear();
  RefreshConfig();
  asm_routines.Regenerate();
  ResetFreeMemoryRanges();
  Host_JitCacheInvalidation();
}

void Jit64::FreeRanges()
{
  // Check if any code blocks have been freed in the block cache and transfer this information to
  // the local rangesets to allow overwriting them with new code.
  for (const auto& [from, to] : blocks.GetRangesToFreeNear())
    m_free_ranges_near.insert(from, to);
  for (const auto& [from, to] : blocks.GetRangesToFreeFar())
    m_free_ranges_far.insert(from, to);
  blocks.ClearRangesToFree();
}

void Jit64::ResetFreeMemoryRanges()
{
  // Set the entire near and far code regions as unused.
  m_free_ranges_near.clear();
  m_free_ranges_near.insert(region, region + region_size);
  m_free_ranges_far.clear();
  m_free_ranges_far.insert(m_far_code.GetWritableCodePtr(), m_far_code.GetWritableCodeEnd());
}

void Jit64::Shutdown()
{
  FreeCodeSpace();

  auto& memory = m_system.GetMemory();
  memory.ShutdownFastmemArena();

  blocks.Shutdown();
  m_far_code.Shutdown();
  m_const_pool.Shutdown();
}
