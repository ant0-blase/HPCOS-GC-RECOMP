// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <string>
#include "Common/CommonTypes.h"
#include "Common/Config/Config.h"

namespace Config
{
extern const Info<bool> MAIN_WII_SD_CARD;
extern const Info<bool> MAIN_WII_SD_CARD_ENABLE_FOLDER_SYNC;
extern const Info<u64> MAIN_WII_SD_CARD_FILESIZE;
extern const Info<bool> MAIN_WII_KEYBOARD;
extern const Info<bool> MAIN_WIIMOTE_CONTINUOUS_SCANNING;
extern const Info<std::string> MAIN_WIIMOTE_AUTO_CONNECT_ADDRESSES;
extern const Info<bool> MAIN_WIIMOTE_ENABLE_SPEAKER;
extern const Info<bool> MAIN_CONNECT_WIIMOTES_FOR_CONTROLLER_INTERFACE;
extern const Info<std::string> MAIN_WII_SD_CARD_IMAGE_PATH;
extern const Info<std::string> MAIN_WII_SD_CARD_SYNC_FOLDER_PATH;
}  // namespace Config
