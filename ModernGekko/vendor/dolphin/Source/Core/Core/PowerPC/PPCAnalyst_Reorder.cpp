// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/PPCAnalyst.h"

#include <algorithm>
#include <map>
#include <string>
#include <vector>

#include <fmt/format.h>

#include "Common/Assert.h"
#include "Common/CommonTypes.h"
#include "Common/Logging/Log.h"
#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "Core/HLE/HLE.h"
#include "Core/PowerPC/JitCommon/JitBase.h"
#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/PPCSymbolDB.h"
#include "Core/PowerPC/PPCTables.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/PowerPC/SignatureDB/SignatureDB.h"
#include "Core/System.h"

// Analyzes PowerPC code in memory to find functions
// After running, for each function we will know what functions it calls
// and what functions calls it. That is, we will have an incomplete call graph,
// but only missing indirect branches.

// The results of this analysis is displayed in the code browsing sections at the bottom left
// of the disassembly window (debugger).

// It is also useful for finding function boundaries so that we can find, fingerprint and detect
// library functions.
// We don't do this much currently. Only for the special case Super Monkey Ball.

namespace PPCAnalyst
{
bool PPCAnalyzer::CanSwapAdjacentOps(const CodeOp& a, const CodeOp& b) const
{
  const GekkoOPInfo* a_info = a.opinfo;
  const GekkoOPInfo* b_info = b.opinfo;
  u64 a_flags = a_info->flags;
  u64 b_flags = b_info->flags;

  // can't reorder around breakpoints
  if (m_is_debugging_enabled)
  {
    auto& breakpoints = Core::System::GetInstance().GetPowerPC().GetBreakPoints();
    if (breakpoints.IsAddressBreakPoint(a.address) || breakpoints.IsAddressBreakPoint(b.address))
      return false;
  }
  // Any instruction which can raise an interrupt is *not* a possible swap candidate:
  // see [1] for an example of a crash caused by this error.
  //
  // [1] https://bugs.dolphin-emu.org/issues/5864#note-7
  if (a.canCauseException || b.canCauseException)
    return false;
  if (a.canEndBlock || b.canEndBlock)
    return false;
  if (a_flags & (FL_TIMER | FL_NO_REORDER | FL_SET_OE))
    return false;
  if (b_flags & (FL_TIMER | FL_NO_REORDER | FL_SET_OE))
    return false;
  if ((a_flags & (FL_SET_CA | FL_READ_CA)) && (b_flags & (FL_SET_CA | FL_READ_CA)))
    return false;

  // For now, only integer ops are acceptable.
  if (b_info->type != OpType::Integer)
    return false;

  // Check that we have no register collisions.
  // That is, check that none of b's outputs matches any of a's inputs,
  // and that none of a's outputs matches any of b's inputs.

  // register collision: b outputs to one of a's inputs
  if (b.regsOut & a.regsIn)
    return false;
  if (b.crOut & a.crIn)
    return false;
  // register collision: a outputs to one of b's inputs
  if (a.regsOut & b.regsIn)
    return false;
  if (a.crOut & b.crIn)
    return false;
  // register collision: b outputs to one of a's outputs (overwriting it)
  if (b.regsOut & a.regsOut)
    return false;
  if (b.crOut & a.crOut)
    return false;

  return true;
}

// Most functions that are relevant to analyze should be
// called by another function. Therefore, let's scan the
// entire space for bl operations and find what functions
// get called.
static bool isCarryOp(const CodeOp& a)
{
  return (a.opinfo->flags & FL_SET_CA) && !(a.opinfo->flags & FL_SET_OE) &&
         a.opinfo->type == OpType::Integer;
}

static bool isCror(const CodeOp& a)
{
  return a.inst.OPCD == 19 && a.inst.SUBOP10 == 449;
}

void PPCAnalyzer::ReorderInstructionsCore(u32 instructions, CodeOp* code, bool reverse,
                                          ReorderType type) const
{
  // Instruction Reordering Pass
  // Carry pass: bubble carry-using instructions as close to each other as possible, so we can avoid
  // storing the carry flag.
  // Compare pass: bubble compare instructions next to branches, so they can be merged.

  const int start = reverse ? instructions - 1 : 0;
  const int end = reverse ? 0 : instructions - 1;
  const int increment = reverse ? -1 : 1;

  int i = start;
  int next = start;
  bool go_backwards = false;

  while (true)
  {
    if (go_backwards)
    {
      i -= increment;
      go_backwards = false;
    }
    else
    {
      i = next;
      next += increment;
    }

    if (i == end)
      break;

    CodeOp& a = code[i];
    CodeOp& b = code[i + increment];

    // Reorder integer compares, rlwinm., and carry-affecting ops
    // (if we add more merged branch instructions, add them here!)
    if ((type == ReorderType::CROR && isCror(a)) || (type == ReorderType::Carry && isCarryOp(a)) ||
        (type == ReorderType::CMP && a.crOut))
    {
      // once we're next to a carry instruction, don't move away!
      if (type == ReorderType::Carry && i != start)
      {
        // if we read the CA flag, and the previous instruction sets it, don't move away.
        if (!reverse && (a.opinfo->flags & FL_READ_CA) &&
            (code[i - increment].opinfo->flags & FL_SET_CA))
        {
          continue;
        }

        // if we set the CA flag, and the next instruction reads it, don't move away.
        if (reverse && (a.opinfo->flags & FL_SET_CA) &&
            (code[i - increment].opinfo->flags & FL_READ_CA))
        {
          continue;
        }
      }

      if (CanSwapAdjacentOps(a, b))
      {
        // Alright, let's bubble it!
        std::swap(a, b);

        if (i != start)
        {
          // Bubbling an instruction sometimes reveals another opportunity to bubble an instruction,
          // so go one step backwards and check if we have such an opportunity.
          go_backwards = true;
        }
      }
    }
  }
}

void PPCAnalyzer::ReorderInstructions(u32 instructions, CodeOp* code) const
{
  // For carry, bubble instructions *towards* each other; one direction often isn't enough
  // to get pairs like addc/adde next to each other.
  if (HasOption(OPTION_CARRY_MERGE))
  {
    ReorderInstructionsCore(instructions, code, false, ReorderType::Carry);
    ReorderInstructionsCore(instructions, code, true, ReorderType::Carry);
  }

  // Reorder instructions which write to CR (typically compare instructions) towards branches.
  if (HasOption(OPTION_BRANCH_MERGE))
    ReorderInstructionsCore(instructions, code, false, ReorderType::CMP);

  // Reorder cror instructions upwards (e.g. towards an fcmp). Technically we should be more
  // picky about this, but cror seems to almost solely be used for this purpose in real code.
  // Additionally, the other boolean ops seem to almost never be used.
  if (HasOption(OPTION_CROR_MERGE))
    ReorderInstructionsCore(instructions, code, true, ReorderType::CROR);
}
} // namespace PPCAnalyst
