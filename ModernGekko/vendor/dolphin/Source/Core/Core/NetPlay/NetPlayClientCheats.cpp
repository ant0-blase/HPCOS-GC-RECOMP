// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/NetPlay/NetPlayClient.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Common/SFMLHelper.h"
#include "Common/StringUtil.h"
#include "Core/Cheats/ActionReplay.h"
#include "Core/Cheats/GeckoCode.h"

namespace NetPlay
{

void NetPlayClient::OnSyncCodes(sf::Packet& packet)
{
  SyncCodeID sub_id;
  packet >> sub_id;

  INFO_LOG_FMT(NETPLAY, "Processing OnSyncCodes sub id: {}", static_cast<u8>(sub_id));

  switch (sub_id)
  {
  case SyncCodeID::Notify:
    OnSyncCodesNotify();
    break;

  case SyncCodeID::NotifyGecko:
    OnSyncCodesNotifyGecko(packet);
    break;

  case SyncCodeID::GeckoData:
    OnSyncCodesDataGecko(packet);
    break;

  case SyncCodeID::NotifyAR:
    OnSyncCodesNotifyAR(packet);
    break;

  case SyncCodeID::ARData:
    OnSyncCodesDataAR(packet);
    break;

  default:
    PanicAlertFmtT("Unknown SYNC_CODES message received with id: {0}", static_cast<u8>(sub_id));
    break;
  }
}

void NetPlayClient::OnSyncCodesNotify()
{
  m_sync_gecko_codes_complete = false;
  m_sync_ar_codes_complete = false;
}

void NetPlayClient::OnSyncCodesNotifyGecko(sf::Packet& packet)
{
  if (m_local_player->IsHost())
    return;

  packet >> m_sync_gecko_codes_count;
  m_sync_gecko_codes_success_count = 0;

  INFO_LOG_FMT(NETPLAY, "Receiving {} Gecko codelines", m_sync_gecko_codes_count);

  if (m_sync_gecko_codes_count == 0)
  {
    m_sync_gecko_codes_complete = true;
    SyncCodeResponse(true);
  }
  else
  {
    m_dialog->AppendChat(Common::GetStringT("Synchronizing Gecko codes..."));
  }
}

void NetPlayClient::OnSyncCodesDataGecko(sf::Packet& packet)
{
  if (m_local_player->IsHost())
    return;

  std::vector<Gecko::GeckoCode> synced_codes;
  synced_codes.reserve(m_sync_gecko_codes_count);

  Gecko::GeckoCode gcode{};
  gcode.name = "Synced Codes";
  gcode.enabled = true;

  for (u32 i = 0; i < m_sync_gecko_codes_count; i++)
  {
    Gecko::GeckoCode::Code new_code;
    packet >> new_code.address;
    packet >> new_code.data;

    INFO_LOG_FMT(NETPLAY, "Received {:08x} {:08x}", new_code.address, new_code.data);

    gcode.codes.push_back(std::move(new_code));

    if (++m_sync_gecko_codes_success_count >= m_sync_gecko_codes_count)
    {
      m_sync_gecko_codes_complete = true;
      SyncCodeResponse(true);
    }
  }

  synced_codes.push_back(std::move(gcode));

  if (m_sync_gecko_codes_count == 0)
    synced_codes.clear();

  Gecko::UpdateSyncedCodes(synced_codes);
}

void NetPlayClient::OnSyncCodesNotifyAR(sf::Packet& packet)
{
  if (m_local_player->IsHost())
    return;

  packet >> m_sync_ar_codes_count;
  m_sync_ar_codes_success_count = 0;

  INFO_LOG_FMT(NETPLAY, "Receiving {} AR codelines", m_sync_ar_codes_count);

  if (m_sync_ar_codes_count == 0)
  {
    m_sync_ar_codes_complete = true;
    SyncCodeResponse(true);
  }
  else
  {
    m_dialog->AppendChat(Common::GetStringT("Synchronizing AR codes..."));
  }
}

void NetPlayClient::OnSyncCodesDataAR(sf::Packet& packet)
{
  if (m_local_player->IsHost())
    return;

  std::vector<ActionReplay::ARCode> synced_codes;
  synced_codes.reserve(m_sync_ar_codes_count);

  ActionReplay::ARCode arcode{};
  arcode.name = "Synced Codes";
  arcode.enabled = true;

  for (u32 i = 0; i < m_sync_ar_codes_count; i++)
  {
    ActionReplay::AREntry new_code;
    packet >> new_code.cmd_addr;
    packet >> new_code.value;

    INFO_LOG_FMT(NETPLAY, "Received {:08x} {:08x}", new_code.cmd_addr, new_code.value);
    arcode.ops.push_back(new_code);

    if (++m_sync_ar_codes_success_count >= m_sync_ar_codes_count)
    {
      m_sync_ar_codes_complete = true;
      SyncCodeResponse(true);
    }
  }

  synced_codes.push_back(std::move(arcode));

  if (m_sync_ar_codes_count == 0)
    synced_codes.clear();

  ActionReplay::UpdateSyncedCodes(synced_codes);
}

void NetPlayClient::SyncCodeResponse(const bool success)
{
  if (!success)
  {
    m_dialog->AppendChat(Common::GetStringT("Error processing codes."));

    sf::Packet response_packet;
    response_packet << MessageID::SyncCodes;
    response_packet << SyncCodeID::Failure;

    Send(response_packet);
    return;
  }

  if (m_sync_gecko_codes_complete && m_sync_ar_codes_complete)
  {
    m_dialog->AppendChat(Common::GetStringT("Codes received!"));

    sf::Packet response_packet;
    response_packet << MessageID::SyncCodes;
    response_packet << SyncCodeID::Success;

    Send(response_packet);
  }
}

}  // namespace NetPlay
