// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/WiimoteEmu/WiimoteEmu.h"

#include <memory>

#include "Core/HW/WiimoteEmu/Extension/Classic.h"
#include "Core/HW/WiimoteEmu/Extension/DrawsomeTablet.h"
#include "Core/HW/WiimoteEmu/Extension/Drums.h"
#include "Core/HW/WiimoteEmu/Extension/Guitar.h"
#include "Core/HW/WiimoteEmu/Extension/Nunchuk.h"
#include "Core/HW/WiimoteEmu/Extension/Shinkansen.h"
#include "Core/HW/WiimoteEmu/Extension/TaTaCon.h"
#include "Core/HW/WiimoteEmu/Extension/Turntable.h"
#include "Core/HW/WiimoteEmu/Extension/UDrawTablet.h"

#include "InputCommon/ControllerEmu/ControlGroup/Attachments.h"
#include "InputCommon/ControllerEmu/ControlGroup/Buttons.h"
#include "InputCommon/ControllerEmu/ControlGroup/ControlGroup.h"
#include "InputCommon/ControllerEmu/ControlGroup/Cursor.h"
#include "InputCommon/ControllerEmu/ControlGroup/Force.h"
#include "InputCommon/ControllerEmu/ControlGroup/IMUAccelerometer.h"
#include "InputCommon/ControllerEmu/ControlGroup/IMUCursor.h"
#include "InputCommon/ControllerEmu/ControlGroup/IMUGyroscope.h"
#include "InputCommon/ControllerEmu/ControlGroup/IRPassthrough.h"
#include "InputCommon/ControllerEmu/ControlGroup/ModifySettingsButton.h"
#include "InputCommon/ControllerEmu/ControlGroup/Tilt.h"

namespace WiimoteEmu
{

ControllerEmu::ControlGroup* Wiimote::GetWiimoteGroup(WiimoteGroup group) const
{
  switch (group)
  {
  case WiimoteGroup::Buttons:
    return m_buttons;
  case WiimoteGroup::DPad:
    return m_dpad;
  case WiimoteGroup::Shake:
    return m_shake;
  case WiimoteGroup::Point:
    return m_ir;
  case WiimoteGroup::Tilt:
    return m_tilt;
  case WiimoteGroup::Swing:
    return m_swing;
  case WiimoteGroup::Rumble:
    return m_rumble;
  case WiimoteGroup::Attachments:
    return m_attachments;
  case WiimoteGroup::Options:
    return m_options;
  case WiimoteGroup::Hotkeys:
    return m_hotkeys;
  case WiimoteGroup::IMUAccelerometer:
    return m_imu_accelerometer;
  case WiimoteGroup::IMUGyroscope:
    return m_imu_gyroscope;
  case WiimoteGroup::IMUPoint:
    return m_imu_ir;
  case WiimoteGroup::IRPassthrough:
    return m_ir_passthrough;
  default:
    ASSERT(false);
    return nullptr;
  }
}

ControllerEmu::ControlGroup* Wiimote::GetNunchukGroup(NunchukGroup group) const
{
  return static_cast<Nunchuk*>(m_attachments->GetAttachmentList()[ExtensionNumber::NUNCHUK].get())
      ->GetGroup(group);
}

ControllerEmu::ControlGroup* Wiimote::GetClassicGroup(ClassicGroup group) const
{
  return static_cast<Classic*>(m_attachments->GetAttachmentList()[ExtensionNumber::CLASSIC].get())
      ->GetGroup(group);
}

ControllerEmu::ControlGroup* Wiimote::GetGuitarGroup(GuitarGroup group) const
{
  return static_cast<Guitar*>(m_attachments->GetAttachmentList()[ExtensionNumber::GUITAR].get())
      ->GetGroup(group);
}

ControllerEmu::ControlGroup* Wiimote::GetDrumsGroup(DrumsGroup group) const
{
  return static_cast<Drums*>(m_attachments->GetAttachmentList()[ExtensionNumber::DRUMS].get())
      ->GetGroup(group);
}

ControllerEmu::ControlGroup* Wiimote::GetTurntableGroup(TurntableGroup group) const
{
  return static_cast<Turntable*>(
             m_attachments->GetAttachmentList()[ExtensionNumber::TURNTABLE].get())
      ->GetGroup(group);
}

ControllerEmu::ControlGroup* Wiimote::GetUDrawTabletGroup(UDrawTabletGroup group) const
{
  return static_cast<UDrawTablet*>(
             m_attachments->GetAttachmentList()[ExtensionNumber::UDRAW_TABLET].get())
      ->GetGroup(group);
}

ControllerEmu::ControlGroup* Wiimote::GetDrawsomeTabletGroup(DrawsomeTabletGroup group) const
{
  return static_cast<DrawsomeTablet*>(
             m_attachments->GetAttachmentList()[ExtensionNumber::DRAWSOME_TABLET].get())
      ->GetGroup(group);
}

ControllerEmu::ControlGroup* Wiimote::GetTaTaConGroup(TaTaConGroup group) const
{
  return static_cast<TaTaCon*>(m_attachments->GetAttachmentList()[ExtensionNumber::TATACON].get())
      ->GetGroup(group);
}

ControllerEmu::ControlGroup* Wiimote::GetShinkansenGroup(ShinkansenGroup group) const
{
  return static_cast<Shinkansen*>(
             m_attachments->GetAttachmentList()[ExtensionNumber::SHINKANSEN].get())
      ->GetGroup(group);
}

} // namespace WiimoteEmu
