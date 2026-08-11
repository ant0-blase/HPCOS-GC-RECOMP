// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/DVD/AMMediaboard.h"
#include "Core/HLE/HLE.h"
#include "Core/HW/Memmap.h"
#include "Core/System.h"

namespace AMMediaboard
{

void ApplyBootHacks(Core::System& system, Memory::MemoryManager& memory)
{
  HLE::Patch(system, 0x813048B8, "OSReport");
  HLE::Patch(system, 0x8130095C, "OSReport");  // Apploader
}

void CheckTestModeBootHack(u32 offset, Memory::MemoryManager& memory)
{
  if (offset == 0x0002440)
  {
    // Set by OSResetSystem
    if (memory.Read_U32(0x811FFF00) == 1)
    {
      // Don't map firmware while in SegaBoot
      if (memory.Read_U32(0x8006BF70) != 0x0A536567)
      {
        FirmwareMap(true);
      }
    }
  }
}

}  // namespace AMMediaboard
