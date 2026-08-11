// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <array>
#include "Common/CommonTypes.h"
#include "Common/IOFile.h"
#include "Core/Movie.h"

namespace Movie
{
bool IsMovieHeader(const std::array<u8, 4>& magic);
bool ReadDTMHeader(File::IOFile& file, DTMHeader* header);
bool WriteDTMHeader(File::IOFile& file, const DTMHeader& header);
}  // namespace Movie
