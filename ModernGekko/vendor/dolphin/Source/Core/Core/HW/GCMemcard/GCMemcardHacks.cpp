// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/GCMemcard/GCMemcard.h"
#include "Common/Swap.h"
#include <cstring>

namespace Memcard
{

s32 GCMemcard::FZEROGX_MakeSaveGameValid(const Header& cardheader, const DEntry& direntry,
                                         std::vector<GCMBlock>& FileBuffer)
{
  u32 i, j;
  u16 chksum = 0xFFFF;

  // check for F-Zero GX system file
  if (strcmp(reinterpret_cast<const char*>(direntry.m_filename.data()), "f_zero.dat") != 0)
    return 0;

  // also make sure that the filesize is correct
  if (FileBuffer.size() != 4)
    return 0;

  // get encrypted destination memory card serial numbers
  const auto [serial1, serial2] = cardheader.CalculateSerial();

  // set new serial numbers
  *(u16*)&FileBuffer[1].m_block[0x0066] = Common::swap16(u16(Common::swap32(serial1) >> 16));
  *(u16*)&FileBuffer[3].m_block[0x1580] = Common::swap16(u16(Common::swap32(serial2) >> 16));
  *(u16*)&FileBuffer[1].m_block[0x0060] = Common::swap16(u16(Common::swap32(serial1) & 0xFFFF));
  *(u16*)&FileBuffer[1].m_block[0x0200] = Common::swap16(u16(Common::swap32(serial2) & 0xFFFF));

  // calc 16-bit checksum
  for (i = 0x02; i < 0x8000; i++)
  {
    const int block = i / 0x2000;
    const int offset = i % 0x2000;
    chksum ^= (FileBuffer[block].m_block[offset] & 0xFF);
    for (j = 8; j > 0; j--)
    {
      if (chksum & 1)
        chksum = (chksum >> 1) ^ 0x8408;
      else
        chksum >>= 1;
    }
  }

  // set new checksum
  *(u16*)&FileBuffer[0].m_block[0x00] = Common::swap16(u16(~chksum));

  return 1;
}

s32 GCMemcard::PSO_MakeSaveGameValid(const Header& cardheader, const DEntry& direntry,
                                     std::vector<GCMBlock>& FileBuffer)
{
  u32 i, j;
  u32 chksum;
  u32 crc32LUT[256];
  u32 pso3offset = 0x00;

  // check for PSO1&2 system file
  if (strcmp(reinterpret_cast<const char*>(direntry.m_filename.data()), "PSO_SYSTEM") != 0)
  {
    // check for PSO3 system file
    if (strcmp(reinterpret_cast<const char*>(direntry.m_filename.data()), "PSO3_SYSTEM") == 0)
    {
      // PSO3 data block size adjustment
      pso3offset = 0x10;
    }
    else
    {
      // nothing to do
      return 0;
    }
  }

  // get encrypted destination memory card serial numbers
  const auto [serial1, serial2] = cardheader.CalculateSerial();

  // set new serial numbers
  *(u32*)&FileBuffer[1].m_block[0x0158] = serial1;
  *(u32*)&FileBuffer[1].m_block[0x015C] = serial2;

  // generate crc32 LUT
  for (i = 0; i < 256; i++)
  {
    chksum = i;
    for (j = 8; j > 0; j--)
    {
      if (chksum & 1)
        chksum = (chksum >> 1) ^ 0xEDB88320;
      else
        chksum >>= 1;
    }

    crc32LUT[i] = chksum;
  }

  // PSO initial crc32 value
  chksum = 0xDEBB20E3;

  // calc 32-bit checksum
  for (i = 0x004C; i < 0x0164 + pso3offset; i++)
  {
    chksum = ((chksum >> 8) & 0xFFFFFF) ^ crc32LUT[(chksum ^ FileBuffer[1].m_block[i]) & 0xFF];
  }

  // set new checksum
  *(u32*)&FileBuffer[1].m_block[0x0048] = Common::swap32(chksum ^ 0xFFFFFFFF);

  return 1;
}

}  // namespace Memcard
