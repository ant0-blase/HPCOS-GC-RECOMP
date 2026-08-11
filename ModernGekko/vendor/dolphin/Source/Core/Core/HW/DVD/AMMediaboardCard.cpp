// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/DVD/AMMediaboard.h"
#include "Core/HW/Memmap.h"
#include "Core/System.h"

namespace AMMediaboard
{

extern u32 s_gcam_key_a;
extern u32 s_gcam_key_b;
extern u32 s_gcam_key_c;

void InitKeys(u32 key_a, u32 key_b, u32 key_c)
{
  s_gcam_key_a = key_a;
  s_gcam_key_b = key_b;
  s_gcam_key_c = key_c;
}

void DecryptCommand(std::array<u32, 3>& dicmd_buf, Memory::MemoryManager& memory, Core::System& system)
{
  dicmd_buf[0] ^= s_gcam_key_a;
  dicmd_buf[1] ^= s_gcam_key_b;
  dicmd_buf[2] ^= s_gcam_key_c;

  const u32 seed = dicmd_buf[0] >> 16;

  s_gcam_key_a *= seed;
  s_gcam_key_b *= seed;
  s_gcam_key_c *= seed;

  if (s_gcam_key_a == 0)
  {
    if (memory.Read_U32(0))
    {
      ApplyBootHacks(system, memory);
      InitKeys(memory.Read_U32(0), memory.Read_U32(4), memory.Read_U32(8));
    }
  }
}

}  // namespace AMMediaboard
