// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/IOS/USB/Bluetooth/BTEmu.h"

#include <algorithm>
#include <cstring>
#include <memory>
#include <string>

#include "Common/Assert.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/Debugger/Debugger_SymbolMap.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/SystemTimers.h"
#include "Core/HW/Wiimote.h"
#include "Core/HW/WiimoteEmu/DesiredWiimoteState.h"
#include "Core/IOS/Device.h"
#include "Core/IOS/IOS.h"
#include "Core/Movie.h"
#include "Core/NetPlay/NetPlayClient.h"
#include "Core/NetPlay/NetPlayProto.h"
#include "Core/Wii/SysConf.h"
#include "Core/System.h"
#include "InputCommon/ControllerInterface/ControllerInterface.h"

namespace IOS::HLE
{

BluetoothEmuDevice::BluetoothEmuDevice(EmulationKernel& ios, const std::string& device_name)
    : BluetoothBaseDevice(ios, device_name)
{
  SysConf sysconf{ios.GetFS()};
  if (!Core::WantsDeterminism())
    BackUpBTInfoSection(&sysconf);

  ConfPads bt_dinf{};

  for (u8 i = 0; i != MAX_BBMOTES; ++i)
  {
    // Note: BluetoothEmu::GetConnectionHandle and WiimoteDevice::GetNumber rely on final byte.
    const bdaddr_t tmp_bd = {0x11, 0x02, 0x19, 0x79, 0, i};

    // Previous records can be safely overwritten, since they are backed up
    std::ranges::copy(tmp_bd, std::rbegin(bt_dinf.active[i].bdaddr));
    std::ranges::copy(tmp_bd, std::rbegin(bt_dinf.registered[i].bdaddr));

    const auto& wm_name =
        (i == WIIMOTE_BALANCE_BOARD) ? "Nintendo RVL-WBC-01" : "Nintendo RVL-CNT-01";
    memcpy(bt_dinf.registered[i].name, wm_name, 20);
    memcpy(bt_dinf.active[i].name, wm_name, 20);

    DEBUG_LOG_FMT(IOS_WIIMOTE, "Wii Remote {} BT ID {:x},{:x},{:x},{:x},{:x},{:x}", i, tmp_bd[0],
                  tmp_bd[1], tmp_bd[2], tmp_bd[3], tmp_bd[4], tmp_bd[5]);

    const unsigned int hid_source_number =
        NetPlay::IsNetPlayRunning() ? NetPlay::NetPlay_GetLocalWiimoteForSlot(i) : i;
    m_wiimotes[i] = std::make_unique<WiimoteDevice>(this, tmp_bd, hid_source_number);
  }

  bt_dinf.num_registered = MAX_BBMOTES;

  // save now so that when games load sysconf file it includes the new Wii Remotes
  // and the correct order for connected Wii Remotes
  auto& section = sysconf.GetOrAddEntry("BT.DINF", SysConf::Entry::Type::BigArray)->bytes;
  section.resize(sizeof(ConfPads));
  std::memcpy(section.data(), &bt_dinf, sizeof(ConfPads));
  if (!sysconf.Save())
    PanicAlertFmtT("Failed to write BT.DINF to SYSCONF");
}

BluetoothEmuDevice::~BluetoothEmuDevice() = default;

bool BluetoothEmuDevice::RemoteConnect(WiimoteDevice& wiimote)
{
  // If page scan is disabled the controller will not see this connection request.
  if (!(m_scan_enable & HCI_PAGE_SCAN_ENABLE))
    return false;

  SendEventRequestConnection(wiimote);
  return true;
}

bool BluetoothEmuDevice::RemoteDisconnect(const bdaddr_t& address)
{
  return SendEventDisconnect(GetConnectionHandle(address), 0x13);
}

WiimoteDevice* BluetoothEmuDevice::AccessWiimoteByIndex(std::size_t index)
{
  if (index < MAX_BBMOTES)
    return m_wiimotes[index].get();

  return nullptr;
}

u16 BluetoothEmuDevice::GetConnectionHandle(const bdaddr_t& address)
{
  // Handles are normally generated per connection but HLE allows fixed values for each remote.
  return 0x100 + address.back();
}

u32 BluetoothEmuDevice::GetWiimoteNumberFromConnectionHandle(u16 connection_handle)
{
  // Fixed handle values are generated in GetConnectionHandle.
  return connection_handle & 0xff;
}

WiimoteDevice* BluetoothEmuDevice::AccessWiimote(const bdaddr_t& address)
{
  // Fixed bluetooth addresses are generated in WiimoteDevice::WiimoteDevice.
  const auto wiimote = AccessWiimoteByIndex(address.back());

  if (wiimote && wiimote->GetBD() == address)
    return wiimote;

  return nullptr;
}

WiimoteDevice* BluetoothEmuDevice::AccessWiimote(u16 connection_handle)
{
  const auto wiimote =
      AccessWiimoteByIndex(GetWiimoteNumberFromConnectionHandle(connection_handle));

  if (wiimote)
    return wiimote;

  ERROR_LOG_FMT(IOS_WIIMOTE, "Can't find Wiimote by connection handle {:02x}", connection_handle);
  PanicAlertFmtT("Can't find Wii Remote by connection handle {0:02x}", connection_handle);

  return nullptr;
}

}  // namespace IOS::HLE
