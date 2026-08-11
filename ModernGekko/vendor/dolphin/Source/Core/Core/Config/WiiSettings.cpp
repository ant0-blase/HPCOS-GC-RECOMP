// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Config/WiiSettings.h"

namespace Config
{
const Info<bool> MAIN_WII_SD_CARD{{System::Main, "Core", "WiiSDCard"}, true};
const Info<bool> MAIN_WII_SD_CARD_ENABLE_FOLDER_SYNC{
    {System::Main, "Core", "WiiSDCardEnableFolderSync"}, false};
const Info<u64> MAIN_WII_SD_CARD_FILESIZE{{System::Main, "Core", "WiiSDCardFilesize"}, 0};
const Info<bool> MAIN_WII_KEYBOARD{{System::Main, "Core", "WiiKeyboard"}, false};
const Info<bool> MAIN_WIIMOTE_CONTINUOUS_SCANNING{
    {System::Main, "Core", "WiimoteContinuousScanning"}, false};
const Info<std::string> MAIN_WIIMOTE_AUTO_CONNECT_ADDRESSES{
    {System::Main, "Core", "WiimoteAutoConnectAddresses"}, ""};
const Info<bool> MAIN_WIIMOTE_ENABLE_SPEAKER{{System::Main, "Core", "WiimoteEnableSpeaker"}, false};
const Info<bool> MAIN_CONNECT_WIIMOTES_FOR_CONTROLLER_INTERFACE{
    {System::Main, "Core", "ConnectWiimotesForControllerInterface"}, false};
const Info<std::string> MAIN_WII_SD_CARD_IMAGE_PATH{{System::Main, "General", "WiiSDCardImagePath"},
                                                    ""};
const Info<std::string> MAIN_WII_SD_CARD_SYNC_FOLDER_PATH{
    {System::Main, "General", "WiiSDCardSyncFolderPath"}, ""};
}  // namespace Config
