// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include <algorithm>
#include <array>
#include <chrono>
#include <ranges>
#include "Common/Config/Config.h"
#include "Common/Logging/Log.h"
#include "Common/SFMLHelper.h"
#include "Core/Config/MainSettings.h"
#include "Core/NetPlay/NetPlayServer.h"
#ifdef HAS_LIBMGBA
#include "Core/HW/GBACore.h"
#endif

namespace NetPlay
{

PadMappingArray NetPlayServer::GetPadMapping() const
{
  return m_pad_map;
}

GBAConfigArray NetPlayServer::GetGBAConfig() const
{
  return m_gba_config;
}

PadMappingArray NetPlayServer::GetWiimoteMapping() const
{
  return m_wiimote_map;
}

void NetPlayServer::SetPadMapping(const PadMappingArray& mappings)
{
  m_pad_map = mappings;
  UpdatePadMapping();
}

void NetPlayServer::SetGBAConfig(const GBAConfigArray& configs, bool update_rom)
{
#ifdef HAS_LIBMGBA
  m_gba_config = configs;
  if (update_rom)
  {
    for (size_t i = 0; i < m_gba_config.size(); ++i)
    {
      auto& config = m_gba_config[i];
      if (!config.enabled)
        continue;
      std::string rom_path = Config::Get(Config::MAIN_GBA_ROM_PATHS[i]);
      config.has_rom = HW::GBA::Core::GetRomInfo(rom_path.c_str(), config.hash, config.title);
    }
  }
#endif
  UpdateGBAConfig();
}

void NetPlayServer::SetWiimoteMapping(const PadMappingArray& mappings)
{
  m_wiimote_map = mappings;
  UpdateWiimoteMapping();
}

void NetPlayServer::UpdatePadMapping()
{
  sf::Packet spac;
  spac << MessageID::PadMapping;
  for (PlayerId mapping : m_pad_map)
  {
    spac << mapping;
  }
  SendToClients(spac);
}

void NetPlayServer::UpdateGBAConfig()
{
  sf::Packet spac;
  spac << MessageID::GBAConfig;
  for (const auto& config : m_gba_config)
  {
    spac << config.enabled << config.has_rom << config.title;
    for (auto& data : config.hash)
      spac << data;
  }
  SendToClients(spac);
}

void NetPlayServer::UpdateWiimoteMapping()
{
  sf::Packet spac;
  spac << MessageID::WiimoteMapping;
  for (PlayerId mapping : m_wiimote_map)
  {
    spac << mapping;
  }
  SendToClients(spac);
}

void NetPlayServer::AdjustPadBufferSize(unsigned int size)
{
  std::lock_guard lkg(m_crit.game);

  m_target_buffer_size = size;

  if (!m_host_input_authority)
  {
    sf::Packet spac;
    spac << MessageID::PadBuffer;
    spac << m_target_buffer_size;

    SendAsyncToClients(std::move(spac));
  }
}

void NetPlayServer::SetAdaptiveBuffer(const bool enable)
{
  m_adaptive_buffer = enable;
  m_adaptive_recommended_buffer_size = std::clamp(m_target_buffer_size, 2u, 20u);
  m_adaptive_boost_buffer_size = 0;
  m_last_adaptive_buffer_update = {};
  m_last_adaptive_buffer_decrease = std::chrono::steady_clock::now();
  m_adaptive_buffer_boost_until = {};
}

void NetPlayServer::UpdateAdaptiveBuffer()
{
  if (!m_adaptive_buffer)
    return;

  const auto now = std::chrono::steady_clock::now();
  if (m_last_adaptive_buffer_update.time_since_epoch().count() != 0 &&
      now - m_last_adaptive_buffer_update < std::chrono::milliseconds(500))
  {
    return;
  }
  m_last_adaptive_buffer_update = now;

  std::array<u32, 2> links{};
  for (const auto& player : std::views::values(m_players))
  {
    const u32 ping = std::min(player.ping, 1000u);
    const u32 variance =
        player.socket ? std::min(player.socket->roundTripTimeVariance, ping / 2) : 0;
    const u32 link = ping + variance;
    if (link >= links[0])
    {
      links[1] = links[0];
      links[0] = link;
    }
    else if (link > links[1])
    {
      links[1] = link;
    }
  }

  const u32 relay_ms = (links[0] + links[1] + 1) / 2;
  m_adaptive_recommended_buffer_size =
      std::clamp(static_cast<unsigned int>((relay_ms * 60 + 999) / 1000 + 1), 2u, 20u);

  unsigned int desired = m_adaptive_recommended_buffer_size;
  if (now < m_adaptive_buffer_boost_until)
    desired = std::max(desired, m_adaptive_boost_buffer_size);
  else
    m_adaptive_boost_buffer_size = 0;

  if (m_target_buffer_size < desired)
  {
    AdjustPadBufferSize(desired);
    m_last_adaptive_buffer_decrease = now;
  }
  else if (m_target_buffer_size > desired &&
           now - m_last_adaptive_buffer_decrease >= std::chrono::seconds(2))
  {
    AdjustPadBufferSize(m_target_buffer_size - 1);
    m_last_adaptive_buffer_decrease = now;
  }
}

void NetPlayServer::SetHostInputAuthority(const bool enable)
{
  std::lock_guard lkg(m_crit.game);

  m_host_input_authority = enable;

  sf::Packet spac;
  spac << MessageID::HostInputAuthority;
  spac << m_host_input_authority;

  SendAsyncToClients(std::move(spac));

  if (!m_host_input_authority)
    AdjustPadBufferSize(m_target_buffer_size);
}

}  // namespace NetPlay
