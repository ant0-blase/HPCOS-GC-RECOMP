// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Config/CheatSettings.h"

namespace Config
{
const Info<bool> MAIN_ENABLE_CHEATS{{System::Main, "Core", "EnableCheats"}, false};

bool AreCheatsEnabled()
{
  return Config::Get(::Config::MAIN_ENABLE_CHEATS);
}
}  // namespace Config
