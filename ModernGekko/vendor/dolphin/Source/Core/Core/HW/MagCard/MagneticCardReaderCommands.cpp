// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/MagCard/MagneticCardReader.h"

#include <algorithm>
#include <numeric>

#include "Common/DirectIOFile.h"
#include "Common/FileUtil.h"
#include "Common/Lazy.h"
#include "Common/Logging/Log.h"
#include "Common/SmallVector.h"
#include "Common/StringUtil.h"
#include "Core/Core.h"

namespace MagCard
{
void MagneticCardReader::Command_10_Initialize()
{
  EjectCard();
  m_status.SoftReset();
  FinishCommand();
}

void MagneticCardReader::Command_20_ReadStatus()
{
  m_status.SoftReset();
  FinishCommand();
}

void MagneticCardReader::Command_33_ReadData()
{
  enum class Mode : u8
  {
    Standard = 0x30,      // read 69-bytes
    ReadVariable = 0x31,  // variable length read
    CardCapture = 0x32,   // pull in card
  };

  if (m_current_packet.size() < 3)
  {
    SetPError(P::SYSTEM_ERR);
    return;
  }

  const auto mode = Mode(m_current_packet[0]);
  // const auto bit_mode = BitMode(m_current_packet[1]);
  const auto track = Track(m_current_packet[2]);

  switch (m_current_step)
  {
  case 1:
    if (mode == Mode::CardCapture)
      INFO_LOG_FMT(SERIALINTERFACE_CARD, "Command_33_ReadData: CardCapture");
    break;
  case 2:
  {
    // Doesn't return card data.
    if (mode == Mode::CardCapture)
    {
      if (!IsCardPresent())
      {
        m_status.s = S::WAITING_FOR_CARD;
        --m_current_step;
        break;
      }

      // How does hardware behave when the card is already elsewhere in the machine ?
      if (m_status.r != R::READ_WRITE_HEAD)
      {
        NOTICE_LOG_FMT(SERIALINTERFACE_CARD, "Capturing Card.");

        MoveCard(R::READ_WRITE_HEAD);
        ReadCardFile();

        Core::DisplayMessage("Inserted Magnetic Card", 4000);
      }
      break;
    }

    DEBUG_LOG_FMT(SERIALINTERFACE_CARD, "Command_33_ReadData: mode {:02x} track {:02x}", u8(mode),
                  u8(track));

    const auto track_indices = GetTrackIndicesForTrackType(track);

    if (!IsCardLoaded() || track_indices.size() == 0)
    {
      SetPError(P::ILLEGAL_ERR);
      return;
    }

    for (auto track_index : track_indices)
    {
      auto& track_data = m_card_data[track_index];
      if (!track_data.has_value())
      {
        SetPError(P::READ_ERR);
        WARN_LOG_FMT(SERIALINTERFACE_CARD, "Command_33_ReadData: Empty track {:02x}", track_index);
        // TODO: Are we supposed to return partial data ?
        return;
      }

      AppendRange(&m_command_payload, *track_data);
    }
  }
  default:
    break;
  }

  if (m_current_step >= 2)
    FinishCommand();
}

void MagneticCardReader::Command_35_GetData()
{
  switch (m_current_step)
  {
  case 2:
    if (!IsCardLoaded())
    {
      // TODO: Is this correct ?
      SetPError(P::ILLEGAL_ERR);
      return;
    }

    for (auto& track_data : m_card_data)
    {
      if (!track_data.has_value())
      {
        SetPError(P::READ_ERR);
        // TODO: Are we supposed to return partial data ?
        return;
      }

      AppendRange(&m_command_payload, *track_data);
    }
    break;
  default:
    break;
  }

  if (m_current_step >= 2)
    FinishCommand();
}

void MagneticCardReader::Command_40_Cancel()
{
  m_status.SoftReset();
  FinishCommand();
}

void MagneticCardReader::Command_53_WriteData()
{
  enum class Mode : u8
  {
    Standard = 0x30,  // 69-bytes
  };

  if (m_current_packet.size() < 3)
  {
    SetPError(P::SYSTEM_ERR);
    return;
  }

  if (m_current_step < 2)
    return;

  const auto mode = Mode(m_current_packet[0]);
  // const auto bit_mode = BitMode(m_current_packet[1]);
  auto track = Track(m_current_packet[2]);

  const auto track_indices = GetTrackIndicesForTrackType(track);
  const auto proper_payload_size = track_indices.size() * TRACK_SIZE;
  const auto payload = std::span{m_current_packet}.subspan(3);

  if (mode != Mode::Standard || !IsCardLoaded() || track_indices.size() == 0 ||
      payload.size() != proper_payload_size)
  {
    WARN_LOG_FMT(SERIALINTERFACE_CARD, "Command_53_WriteData: Failed.");
    SetPError(P::ILLEGAL_ERR);
    return;
  }

  INFO_LOG_FMT(SERIALINTERFACE_CARD, "Command_53_WriteData: Writing {} track(s) to memory.",
               track_indices.size());

  for (auto track_index : track_indices)
  {
    auto& track_data = m_card_data[track_index];
    track_data.emplace();
    std::ranges::copy(payload.subspan(track_index * TRACK_SIZE, TRACK_SIZE), track_data->data());
  }

  Core::DisplayMessage("Writing Magnetic Card", 4000);

  WriteCardFile();

  FinishCommand();
}

void MagneticCardReader::Command_78_PrintSettings()
{
  m_status.SoftReset();
  FinishCommand();
}

void MagneticCardReader::Command_7A_RegisterFont()
{
  m_status.SoftReset();
  FinishCommand();
}

void MagneticCardReader::Command_7B_PrintImage()
{
  // TODO: Are these print functions supposed to succeed before the card is actually grabbed ?
  if (!IsCardPresent())
  {
    SetPError(P::PRINT_ERR);
    return;
  }
  m_status.SoftReset();
  FinishCommand();
}

void MagneticCardReader::Command_7C_PrintLine()
{
  if (m_current_packet.size() < 3)
  {
    SetPError(P::SYSTEM_ERR);
    return;
  }

  switch (m_current_step)
  {
  case 1:
  {
    if (!IsCardPresent())
    {
      SetPError(P::PRINT_ERR);
      return;
    }

    // FIXME: Should we only move the head when we're actually about to print?
    MoveCard(R::THERMAL_HEAD);
    break;
  }
  case 2:
    MoveCard(R::READ_WRITE_HEAD);
    break;
  default:
    break;
  }

  if (m_current_step >= 2)
    FinishCommand();
}

void MagneticCardReader::Command_7D_Erase()
{
  switch (m_current_step)
  {
  case 1:
    if (!IsCardPresent())
    {
      SetPError(P::PRINT_ERR);
      return;
    }
    MoveCard(R::THERMAL_HEAD);
    break;
  case 2:
    MoveCard(R::READ_WRITE_HEAD);
    break;
  default:
    break;
  }

  if (m_current_step >= 2)
    FinishCommand();
}

void MagneticCardReader::Command_7E_PrintBarcode()
{
  switch (m_current_step)
  {
  case 2:
    if (!IsCardPresent())
    {
      SetPError(P::ILLEGAL_ERR);
      return;
    }
    break;
  default:
    break;
  }

  if (m_current_step >= 2)
    FinishCommand();
}

void MagneticCardReader::Command_80_EjectCard()
{
  if (m_current_step >= 3)
  {
    EjectCard();
    FinishCommand();
  }
}

void MagneticCardReader::Command_A0_Clean()
{
  switch (m_current_step)
  {
  case 2:
    // TODO: How is this command supposed to behave if a card is already in the machine ?
    if (!IsCardLoaded())
    {
      NOTICE_LOG_FMT(SERIALINTERFACE_CARD, "Inserting cleaning card.");
      Core::DisplayMessage("Inserting cleaning card", 4000);
      MoveCard(R::THERMAL_HEAD);
    }
    break;
  case 3:
    EjectCard();
    break;
  default:
    break;
  }

  if (m_current_step >= 3)
    FinishCommand();
}

void MagneticCardReader::Command_B0_DispenseCard()
{
  enum class Mode : u8
  {
    Dispense = 0x31,
    CheckOnly = 0x32,
  };

  // MarioKart GP1 issues this command without options.
  auto mode = Mode::Dispense;
  if (!m_current_packet.empty())
  {
    mode = Mode(m_current_packet[0]);
  }

  switch (m_current_step)
  {
  case 2:
    if (mode == Mode::CheckOnly)
    {
      if (m_card_settings->report_dispenser_empty)
      {
        m_status.s = S::DISPENSER_EMPTY;
      }
      else
      {
        m_status.s = S::CARD_FULL;
      }
    }
    else
    {
      DispenseCard();
    }
    break;
  case 3:
    if (m_status.r == R::DISPENSER_THERMAL)
    {
      MoveCard(R::READ_WRITE_HEAD);
    }
    break;
  default:
    break;
  }

  if (m_current_step >= 3)
    FinishCommand();
}

void MagneticCardReader::Command_C0_ControlLED()
{
  // We don't need to handle this properly but let's leave some notes.
  enum class Mode : u8
  {
    Off = 0x30,
    On = 0x31,
    SlowBlink = 0x32,
    FastBlink = 0x33,
  };

  m_status.SoftReset();
  FinishCommand();
}

void MagneticCardReader::Command_C1_SetPrintRetry()
{
  // We don't need to handle this properly but let's leave some notes
  // m_current_packet[0] == 0x31 NONE ~ 0x39 MAX8
  m_status.SoftReset();
  FinishCommand();
}

void MagneticCardReader::Command_D0_ControlShutter()
{
  // Only BR model supports this command.
  SetSError(S::ILLEGAL_COMMAND);
}

void MagneticCardReader::Command_F0_GetVersion()
{
  AppendRange(&m_command_payload, VERSION_STRING);

  m_status.SoftReset();
  FinishCommand();
}

}
