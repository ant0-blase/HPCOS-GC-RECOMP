// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "Core/PowerPC/MMU.h"

namespace PowerPC
{
inline bool TranslateBatAddress(const BatTable& bat_table, u32* address, bool* wi)
{
  u32 bat_result = bat_table[*address >> BAT_INDEX_SHIFT];
  if ((bat_result & BAT_MAPPED_BIT) == 0)
    return false;
  *address = (bat_result & BAT_RESULT_MASK) | (*address & (BAT_PAGE_SIZE - 1));
  *wi = (bat_result & BAT_WI_BIT) != 0;
  return true;
}
}  // namespace PowerPC
