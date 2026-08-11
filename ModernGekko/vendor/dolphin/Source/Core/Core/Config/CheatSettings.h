// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "Common/Config/Config.h"

namespace Config
{
extern const Info<bool> MAIN_ENABLE_CHEATS;

bool AreCheatsEnabled();
}  // namespace Config
