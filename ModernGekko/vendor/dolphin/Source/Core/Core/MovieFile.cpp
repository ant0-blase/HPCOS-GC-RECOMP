// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/MovieFile.h"
#include <mbedtls/md.h>
#include "Core/Core.h"

namespace Movie
{

bool IsMovieHeader(const std::array<u8, 4>& magic)
{
  return magic == std::array<u8, 4>{{'D', 'T', 'M', 0x1A}};
}

bool ReadDTMHeader(File::IOFile& file, DTMHeader* header)
{
  return file.ReadArray(header, 1);
}

bool WriteDTMHeader(File::IOFile& file, const DTMHeader& header)
{
  return file.WriteArray(&header, 1);
}

void MovieManager::CheckMD5()
{
  if (m_current_file_name.empty())
    return;

  // The MD5 hash was introduced in 3.0-846-gca650d4435.
  // Before that, these header bytes were set to zero.
  if (m_temp_header.md5 == std::array<u8, 16>{})
    return;

  Core::DisplayMessage("Verifying checksum...", 2000);

  std::array<u8, 16> game_md5;
  mbedtls_md_file(mbedtls_md_info_from_type(MBEDTLS_MD_MD5), m_current_file_name.c_str(),
                  game_md5.data());

  if (game_md5 == m_md5)
    Core::DisplayMessage("Checksum of current game matches the recorded game.", 2000);
  else
    Core::DisplayMessage("Checksum of current game does not match the recorded game!", 3000);
}

void MovieManager::GetMD5()
{
  if (m_current_file_name.empty())
    return;

  Core::DisplayMessage("Calculating checksum of game file...", 2000);
  mbedtls_md_file(mbedtls_md_info_from_type(MBEDTLS_MD_MD5), m_current_file_name.c_str(),
                  m_md5.data());
  Core::DisplayMessage("Finished calculating checksum.", 2000);
}

}  // namespace Movie
