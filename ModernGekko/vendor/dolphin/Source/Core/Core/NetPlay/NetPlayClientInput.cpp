// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Common/Config/Config.h"
#include "Common/SFMLHelper.h"
#include "Core/Config/MainSettings.h"
#include "Core/Core.h"
#include "Core/HW/GBAPad.h"
#include "Core/HW/GCPad.h"
#include "Core/HW/SI/SI_Device.h"
#include "Core/Movie.h"
#include "Core/NetPlay/NetPlayClient.h"
#include "Core/System.h"
#include "InputCommon/GCAdapter.h"

#include <algorithm>
#include <atomic>
#include <chrono>

namespace NetPlay
{

bool NetPlayClient::GetNetPads(const int pad_nb, const bool batching, GCPadStatus* pad_status)
{
  while (m_wait_on_input)
  {
    if (!m_is_running.IsSet())
    {
      return false;
    }

    if (m_wait_on_input_received)
    {
      sf::Packet spac;
      spac << MessageID::GolfPrepare;
      Send(spac);

      m_wait_on_input_received = false;
    }

    m_wait_on_input_event.Wait();
  }

  if (IsFirstInGamePad(pad_nb) && batching)
  {
    sf::Packet packet;
    packet << MessageID::PadData;

    bool send_packet = false;
    const int num_local_pads = NumLocalPads();
    for (int local_pad = 0; local_pad < num_local_pads; local_pad++)
    {
      send_packet = PollLocalPad(local_pad, packet) || send_packet;
    }

    if (send_packet)
      SendAsync(std::move(packet), INPUT_CHANNEL);

    if (m_host_input_authority)
      SendPadHostPoll(-1);
  }

  if (!batching)
  {
    const int local_pad = InGamePadToLocalPad(pad_nb);
    if (local_pad < 4)
    {
      sf::Packet packet;
      packet << MessageID::PadData;
      if (PollLocalPad(local_pad, packet))
        SendAsync(std::move(packet), INPUT_CHANNEL);
    }

    if (m_host_input_authority)
      SendPadHostPoll(pad_nb);
  }

  if (m_host_input_authority)
  {
    if (m_local_player->pid != m_current_golfer)
    {
      const bool buffer_over_target =
          m_pad_buffer[pad_nb].Size() > m_target_buffer_size.load(std::memory_order_relaxed) + 1;
      if (!buffer_over_target)
        m_buffer_under_target_last = std::chrono::steady_clock::now();

      std::chrono::duration<double> time_diff =
          std::chrono::steady_clock::now() - m_buffer_under_target_last;
      if (time_diff.count() >= 1.0 || !buffer_over_target)
      {
        Config::SetCurrent(Config::MAIN_EMULATION_SPEED, buffer_over_target ? 0.0f : 1.0f);
      }
    }
    else
    {
      Config::SetCurrent(Config::MAIN_EMULATION_SPEED, 1.0f);
    }
  }

  while (m_pad_buffer[pad_nb].Size() == 0)
  {
    if (!m_is_running.IsSet())
    {
      return false;
    }

    m_gc_pad_event.Wait();
  }

  m_pad_buffer[pad_nb].Pop(*pad_status);

  auto& movie = Core::System::GetInstance().GetMovie();
  if (movie.IsRecordingInput())
  {
    movie.RecordInput(pad_status, pad_nb);
    movie.InputUpdate();
  }
  else
  {
    movie.CheckPadStatus(pad_status, pad_nb);
  }

  return true;
}

bool NetPlayClient::WiimoteUpdate(const std::span<WiimoteDataBatchEntry>& entries)
{
  sf::Packet packet;
  packet << MessageID::WiimoteData;
  bool send_packet = false;
  bool waited = false;
  std::chrono::steady_clock::time_point wait_start;
  for (const WiimoteDataBatchEntry& entry : entries)
  {
    const int local_wiimote = InGameWiimoteToLocalWiimote(entry.wiimote);
    if (local_wiimote < 4)
      send_packet = AddLocalWiimoteToBuffer(local_wiimote, *entry.state, packet) || send_packet;
  }

  if (send_packet)
    SendAsync(std::move(packet), INPUT_CHANNEL);

  for (const WiimoteDataBatchEntry& entry : entries)
  {
    while (m_wiimote_buffer[entry.wiimote].Size() == 0)
    {
      if (!m_is_running.IsSet())
      {
        return false;
      }

      if (!waited)
      {
        waited = true;
        wait_start = std::chrono::steady_clock::now();
      }
      m_wii_pad_event.Wait();
    }

    m_wiimote_buffer[entry.wiimote].Pop(*entry.state);
  }

  if (waited)
  {
    const auto now = std::chrono::steady_clock::now();
    const u64 wait_ns = static_cast<u64>(
        std::chrono::duration_cast<std::chrono::nanoseconds>(now - wait_start).count());
    RecordInputWait(wait_ns);
    const unsigned int current = m_target_buffer_size.load(std::memory_order_relaxed);
    if (wait_ns >= 4000000 && current < 20 &&
        now - m_last_buffer_request >= std::chrono::seconds(2))
    {
      sf::Packet request;
      request << MessageID::PadBufferRequest << current + 1;
      SendAsync(std::move(request));
      m_last_buffer_request = now;
    }
  }

  return true;
}

InputWaitTelemetry NetPlayClient::GetInputWaitTelemetry()
{
  return {
      s_total_input_wait_ns.load(std::memory_order_relaxed),
      s_maximum_input_wait_ns.load(std::memory_order_relaxed),
      s_input_wait_count.load(std::memory_order_relaxed),
      s_input_buffer_size.load(std::memory_order_relaxed),
      s_input_wait_active.load(std::memory_order_acquire),
  };
}

void NetPlayClient::RecordInputWait(const u64 wait_ns)
{
  s_total_input_wait_ns.fetch_add(wait_ns, std::memory_order_relaxed);
  s_input_wait_count.fetch_add(1, std::memory_order_relaxed);
  u64 previous = s_maximum_input_wait_ns.load(std::memory_order_relaxed);
  while (previous < wait_ns && !s_maximum_input_wait_ns.compare_exchange_weak(
                                   previous, wait_ns, std::memory_order_relaxed))
  {
  }
}

void NetPlayClient::ResetInputWaitTelemetry(const bool active)
{
  s_total_input_wait_ns.store(0, std::memory_order_relaxed);
  s_maximum_input_wait_ns.store(0, std::memory_order_relaxed);
  s_input_wait_count.store(0, std::memory_order_relaxed);
  s_input_buffer_size.store(m_target_buffer_size.load(std::memory_order_relaxed),
                            std::memory_order_relaxed);
  s_input_wait_active.store(active, std::memory_order_release);
  if (active)
    m_last_buffer_request = {};
}

void NetPlayClient::SetInputBufferTelemetry(const u32 size)
{
  s_input_buffer_size.store(size, std::memory_order_relaxed);
}

bool NetPlayClient::PollLocalPad(const int local_pad, sf::Packet& packet)
{
  const int ingame_pad = LocalPadToInGamePad(local_pad);
  bool data_added = false;
  GCPadStatus pad_status;

  if (m_gba_config[ingame_pad].enabled)
  {
    pad_status = Pad::GetGBAStatus(local_pad);
  }
  else if (Config::Get(Config::GetInfoForSIDevice(local_pad)) ==
           SerialInterface::SIDEVICE_WIIU_ADAPTER)
  {
    pad_status = GCAdapter::Input(local_pad);
  }
  else
  {
    pad_status = Pad::GetStatus(local_pad);
  }

  if (m_host_input_authority)
  {
    if (m_local_player->pid != m_current_golfer)
    {
      AddPadStateToPacket(ingame_pad, pad_status, packet);
      data_added = true;
    }
    else
    {
      m_last_pad_status[ingame_pad] = pad_status;
      m_first_pad_status_received[ingame_pad] = true;
    }
  }
  else
  {
    const unsigned int target = m_target_buffer_size.load(std::memory_order_relaxed);
    while (m_pad_buffer[ingame_pad].Size() <= target)
    {
      m_pad_buffer[ingame_pad].Push(pad_status);
      AddPadStateToPacket(ingame_pad, pad_status, packet);
      data_added = true;
    }
  }

  return data_added;
}

bool NetPlayClient::AddLocalWiimoteToBuffer(const int local_wiimote,
                                            const WiimoteEmu::SerializedWiimoteState& state,
                                            sf::Packet& packet)
{
  const int ingame_pad = LocalWiimoteToInGameWiimote(local_wiimote);
  bool data_added = false;

  const unsigned int target = m_target_buffer_size.load(std::memory_order_relaxed);
  while (m_wiimote_buffer[ingame_pad].Size() <= target)
  {
    m_wiimote_buffer[ingame_pad].Push(state);
    AddWiimoteStateToPacket(ingame_pad, state, packet);
    data_added = true;
  }

  return data_added;
}

void NetPlayClient::SendPadHostPoll(const PadIndex pad_num)
{
  if (m_local_player->pid != m_current_golfer)
    return;

  sf::Packet packet;
  packet << MessageID::PadHostData;

  if (pad_num < 0)
  {
    for (size_t i = 0; i < m_pad_map.size(); i++)
    {
      if (m_pad_map[i] <= 0)
        continue;

      while (!m_first_pad_status_received[i])
      {
        if (!m_is_running.IsSet())
          return;

        m_first_pad_status_received_event.Wait();
      }
    }

    for (size_t i = 0; i < m_pad_map.size(); i++)
    {
      if (m_pad_map[i] == 0 || m_pad_buffer[i].Size() > 0)
        continue;

      const GCPadStatus& pad_status = m_last_pad_status[i];
      m_pad_buffer[i].Push(pad_status);
      AddPadStateToPacket(static_cast<int>(i), pad_status, packet);
    }
  }
  else if (m_pad_map[pad_num] != 0)
  {
    while (!m_first_pad_status_received[pad_num])
    {
      if (!m_is_running.IsSet())
        return;

      m_first_pad_status_received_event.Wait();
    }

    if (m_pad_buffer[pad_num].Size() == 0)
    {
      const GCPadStatus& pad_status = m_last_pad_status[pad_num];
      m_pad_buffer[pad_num].Push(pad_status);
      AddPadStateToPacket(pad_num, pad_status, packet);
    }
  }

  SendAsync(std::move(packet), INPUT_CHANNEL);
}

}  // namespace NetPlay
