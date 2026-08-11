// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/MMUBAT.h"

#include "Common/BitUtils.h"
#include "Common/Logging/Log.h"
#include "Core/HW/Memmap.h"
#include "Core/PowerPC/Gekko.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/System.h"

namespace PowerPC
{

void MMU::UpdateBATs(BatTable& bat_table, u32 base_spr)
{
  for (int i = 0; i < 4; ++i)
  {
    const u32 spr = base_spr + i * 2;
    const UReg_BAT_Up batu{m_ppc_state.spr[spr]};
    const UReg_BAT_Lo batl{m_ppc_state.spr[spr + 1]};
    if (batu.VS == 0 && batu.VP == 0)
      continue;

    if ((batu.BEPI & batu.BL) != 0)
    {
      WARN_LOG_FMT(POWERPC, "Bad BAT setup: BEPI overlaps BL");
    }
    if ((batl.BRPN & batu.BL) != 0)
    {
      WARN_LOG_FMT(POWERPC, "Bad BAT setup: BPRN overlaps BL");
    }
    if (!Common::IsValidLowMask((u32)batu.BL))
    {
      WARN_LOG_FMT(POWERPC, "Bad BAT setup: invalid mask in BL");
    }
    for (u32 j = 0; j <= batu.BL; ++j)
    {
      if ((j & batu.BL) == j)
      {
        u32 physical_address = (batl.BRPN | j) << BAT_INDEX_SHIFT;
        u32 virtual_address = (batu.BEPI | j) << BAT_INDEX_SHIFT;

        u32 valid_bit = BAT_MAPPED_BIT;

        const bool wi = (batl.WIMG & 0b1100) != 0;
        if (wi)
          valid_bit |= BAT_WI_BIT;

        if (!wi)
        {
          if (m_memory.GetFakeVMEM() && (physical_address & 0xFE000000) == 0x7E000000)
          {
            valid_bit |= BAT_PHYSICAL_BIT;
          }
          else if (physical_address < m_memory.GetRamSizeReal())
          {
            valid_bit |= BAT_PHYSICAL_BIT;
          }
          else if (m_memory.GetEXRAM() && physical_address >> 28 == 0x1 &&
                   (physical_address & 0x0FFFFFFF) < m_memory.GetExRamSizeReal())
          {
            valid_bit |= BAT_PHYSICAL_BIT;
          }
          else if (physical_address >> 28 == 0xE &&
                   physical_address < 0xE0000000 + m_memory.GetL1CacheSize())
          {
            valid_bit |= BAT_PHYSICAL_BIT;
          }
        }

        if (m_power_pc.GetMemChecks().OverlapsMemcheck(virtual_address, BAT_PAGE_SIZE))
          valid_bit &= ~BAT_PHYSICAL_BIT;

        bat_table[virtual_address >> BAT_INDEX_SHIFT] = physical_address | valid_bit;
      }
    }
  }
}

void MMU::UpdateFakeMMUBat(BatTable& bat_table, u32 start_addr)
{
  for (u32 i = 0; i < (0x10000000 >> BAT_INDEX_SHIFT); ++i)
  {
    u32 e_address = i + (start_addr >> BAT_INDEX_SHIFT);
    u32 p_address = 0x7E000000 | (i << BAT_INDEX_SHIFT & m_memory.GetFakeVMemMask());
    u32 flags = BAT_MAPPED_BIT | BAT_PHYSICAL_BIT;

    if (m_power_pc.GetMemChecks().OverlapsMemcheck(e_address << BAT_INDEX_SHIFT, BAT_PAGE_SIZE))
      flags &= ~BAT_PHYSICAL_BIT;

    bat_table[e_address] = p_address | flags;
  }
}

}  // namespace PowerPC
