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

constexpr size_t NEAR_CODE_SIZE = 1024 * 1024 * 64;
constexpr size_t FAR_CODE_SIZE = 1024 * 1024 * 64;
constexpr size_t TOTAL_CODE_SIZE = NEAR_CODE_SIZE * 2 + FAR_CODE_SIZE * 2;

void JitArm64::Init()
{
  InitFastmemArena();

  RefreshConfig();

  // We want the regions to be laid out in this order in memory:
  // m_far_code_0, m_near_code_0, m_near_code_1, m_far_code_1.
  // AddChildCodeSpace grabs space from the end of the parent region,
  // so we have to call AddChildCodeSpace in reverse order.
  AllocCodeSpace(TOTAL_CODE_SIZE);
  AddChildCodeSpace(&m_far_code_1, FAR_CODE_SIZE);
  AddChildCodeSpace(&m_near_code_1, NEAR_CODE_SIZE);
  AddChildCodeSpace(&m_near_code_0, NEAR_CODE_SIZE);
  AddChildCodeSpace(&m_far_code_0, FAR_CODE_SIZE);
  ASSERT(m_far_code_0.GetCodeEnd() == m_near_code_0.GetCodePtr());
  ASSERT(m_near_code_0.GetCodeEnd() == m_near_code_1.GetCodePtr());
  ASSERT(m_near_code_1.GetCodeEnd() == m_far_code_1.GetCodePtr());

  jo.optimizeGatherPipe = true;
  SetBlockLinkingEnabled(true);
  SetOptimizationEnabled(true);
  gpr.Init(this);
  fpr.Init(this);
  blocks.Init();

  code_block.m_stats = &js.st;
  code_block.m_gpa = &js.gpa;
  code_block.m_fpa = &js.fpa;

  InitBLROptimization();

  GenerateAsmAndResetFreeMemoryRanges();
}

void JitArm64::SetBlockLinkingEnabled(bool enabled)
{
  jo.enableBlocklink = enabled && !SConfig::GetInstance().bJITNoBlockLinking;
}

void JitArm64::SetOptimizationEnabled(bool enabled)
{
  if (enabled)
  {
    analyzer.SetOption(PPCAnalyst::PPCAnalyzer::OPTION_CONDITIONAL_CONTINUE);
    analyzer.SetOption(PPCAnalyst::PPCAnalyzer::OPTION_CARRY_MERGE);
    analyzer.SetOption(PPCAnalyst::PPCAnalyzer::OPTION_BRANCH_FOLLOW);
  }
  else
  {
    analyzer.ClearOption(PPCAnalyst::PPCAnalyzer::OPTION_CONDITIONAL_CONTINUE);
    analyzer.ClearOption(PPCAnalyst::PPCAnalyzer::OPTION_CARRY_MERGE);
    analyzer.ClearOption(PPCAnalyst::PPCAnalyzer::OPTION_BRANCH_FOLLOW);
  }
}

void JitArm64::ClearCache()
{
  m_fault_to_handler.clear();

  blocks.Clear();
  blocks.ClearRangesToFree();
  const Common::ScopedJITPageWriteAndNoExecute enable_jit_page_writes;
  m_far_code_0.ClearCodeSpace();
  m_near_code_0.ClearCodeSpace();
  m_near_code_1.ClearCodeSpace();
  m_far_code_1.ClearCodeSpace();
  RefreshConfig();

  GenerateAsmAndResetFreeMemoryRanges();
}

void JitArm64::GenerateAsmAndResetFreeMemoryRanges()
{
  SetCodePtr(m_near_code_1.GetWritableCodePtr(), m_near_code_1.GetWritableCodeEnd());
  m_far_code.SetCodePtr(m_far_code_1.GetWritableCodePtr(), m_far_code_1.GetWritableCodeEnd());

  const u8* routines_near_start = GetCodePtr();
  const u8* routines_far_start = m_far_code.GetCodePtr();

  GenerateAsm();

  const u8* routines_near_end = GetCodePtr();
  const u8* routines_far_end = m_far_code.GetCodePtr();

  ResetFreeMemoryRanges(routines_near_end - routines_near_start,
                        routines_far_end - routines_far_start);

  Host_JitCacheInvalidation();
}

void JitArm64::FreeRanges()
{
  // Check if any code blocks have been freed in the block cache and transfer this information to
  // the local rangesets to allow overwriting them with new code.
  for (const auto& [from, to] : blocks.GetRangesToFreeNear())
  {
    const auto first_fastmem_area = m_fault_to_handler.upper_bound(from);
    auto last_fastmem_area = first_fastmem_area;
    const auto end = m_fault_to_handler.end();
    while (last_fastmem_area != end && last_fastmem_area->first <= to)
      ++last_fastmem_area;
    m_fault_to_handler.erase(first_fastmem_area, last_fastmem_area);

    if (from < m_near_code_0.GetCodeEnd())
      m_free_ranges_near_0.insert(from, to);
    else
      m_free_ranges_near_1.insert(from, to);
  }
  for (const auto& [from, to] : blocks.GetRangesToFreeFar())
  {
    if (from < m_far_code_0.GetCodeEnd())
      m_free_ranges_far_0.insert(from, to);
    else
      m_free_ranges_far_1.insert(from, to);
  }
  blocks.ClearRangesToFree();
}

void JitArm64::ResetFreeMemoryRanges(size_t routines_near_size, size_t routines_far_size)
{
  // Set the near and far code regions as unused.
  m_free_ranges_far_0.clear();
  m_free_ranges_far_0.insert(m_far_code_0.GetWritableCodePtr() + routines_near_size,
                             m_far_code_0.GetWritableCodeEnd());
  m_free_ranges_near_0.clear();
  m_free_ranges_near_0.insert(m_near_code_0.GetWritableCodePtr(),
                              m_near_code_0.GetWritableCodeEnd());
  m_free_ranges_near_1.clear();
  m_free_ranges_near_1.insert(m_near_code_1.GetWritableCodePtr() + routines_near_size,
                              m_near_code_1.GetWritableCodeEnd());
  m_free_ranges_far_1.clear();
  m_free_ranges_far_1.insert(m_far_code_1.GetWritableCodePtr() + routines_far_size,
                             m_far_code_1.GetWritableCodeEnd());
}

void JitArm64::Shutdown()
{
  auto& memory = m_system.GetMemory();
  memory.ShutdownFastmemArena();
  FreeCodeSpace();
  blocks.Shutdown();
}
