// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/NetPlay/NetPlayServer.h"
#include <fmt/ranges.h>
#include "Common/Config/Config.h"
#include "Common/Logging/Log.h"
#include "Common/SFMLHelper.h"
#include "Core/Config/NetplaySettings.h"
#include "Core/NetPlay/NetPlayClient.h"
#include <algorithm>
#include <ranges>

namespace NetPlay
{

void NetPlayServer::SendChunked(sf::Packet&& packet, const PlayerId pid, const std::string& title)
{
  {
    std::lock_guard lkq(m_crit.chunked_data_queue_write);
    m_chunked_data_queue.Push(
        ChunkedDataQueueEntry{std::move(packet), pid, TargetMode::Only, title});
  }
  m_chunked_data_event.Set();
}

void NetPlayServer::SendChunkedToClients(sf::Packet&& packet, const PlayerId skip_pid,
                                         const std::string& title)
{
  {
    std::lock_guard lkq(m_crit.chunked_data_queue_write);
    m_chunked_data_queue.Push(
        ChunkedDataQueueEntry{std::move(packet), skip_pid, TargetMode::AllExcept, title});
  }
  m_chunked_data_event.Set();
}

void NetPlayServer::ChunkedDataThreadFunc()
{
  INFO_LOG_FMT(NETPLAY, "Starting Chunked Data Thread.");

  while (m_do_loop)
  {
    m_chunked_data_event.Wait();

    if (m_abort_chunked_data)
    {
      while (!m_chunked_data_queue.Empty())
        m_chunked_data_queue.Pop();

      m_abort_chunked_data = false;
    }

    while (!m_chunked_data_queue.Empty())
    {
      if (!m_do_loop)
        return;
      if (m_abort_chunked_data)
        break;
      auto& e = m_chunked_data_queue.Front();
      const u32 id = m_next_chunked_data_id++;

      m_chunked_data_complete_count[id] = 0;
      size_t player_count;
      {
        std::vector<int> players;
        if (e.target_mode == TargetMode::Only)
        {
          players.push_back(e.target_pid);
        }
        else
        {
          for (auto& pl : std::views::values(m_players))
          {
            if (pl.pid != e.target_pid)
              players.push_back(pl.pid);
          }
        }
        player_count = players.size();

        INFO_LOG_FMT(NETPLAY, "Informing players {} of data chunk {} start.",
                     fmt::join(players, ", "), id);

        sf::Packet pac;
        pac << MessageID::ChunkedDataStart;
        pac << id << e.title << u64{e.packet.getDataSize()};

        ChunkedDataSend(std::move(pac), e.target_pid, e.target_mode);

        if (e.target_mode == TargetMode::AllExcept && e.target_pid == 1)
          m_dialog->ShowChunkedProgressDialog(e.title, e.packet.getDataSize(), players);
      }

      const bool enable_limit = Config::Get(Config::NETPLAY_ENABLE_CHUNKED_UPLOAD_LIMIT);
      const float bytes_per_second =
          (std::max(Config::Get(Config::NETPLAY_CHUNKED_UPLOAD_LIMIT), 1u) / 8.0f) * 1024.0f;
      const std::chrono::duration<double> send_interval(CHUNKED_DATA_UNIT_SIZE / bytes_per_second);
      bool skip_wait = false;
      size_t index = 0;
      do
      {
        if (!m_do_loop)
          return;
        if (m_abort_chunked_data)
        {
          INFO_LOG_FMT(NETPLAY, "Informing players of data chunk {} abort.", id);

          sf::Packet pac;
          pac << MessageID::ChunkedDataAbort;
          pac << id;
          ChunkedDataSend(std::move(pac), e.target_pid, e.target_mode);
          break;
        }
        if (e.target_mode == TargetMode::Only)
        {
          if (!m_players.contains(e.target_pid))
          {
            skip_wait = true;
            break;
          }
        }

        auto start = std::chrono::steady_clock::now();

        sf::Packet pac;
        pac << MessageID::ChunkedDataPayload;
        pac << id;
        size_t len = std::min(CHUNKED_DATA_UNIT_SIZE, e.packet.getDataSize() - index);
        pac.append(static_cast<const u8*>(e.packet.getData()) + index, len);

        INFO_LOG_FMT(NETPLAY, "Sending data chunk of {} ({} bytes at {}/{}).", id, len, index,
                     e.packet.getDataSize());

        ChunkedDataSend(std::move(pac), e.target_pid, e.target_mode);
        index += CHUNKED_DATA_UNIT_SIZE;

        if (enable_limit)
        {
          std::chrono::duration<double> delta = std::chrono::steady_clock::now() - start;
          std::this_thread::sleep_for(send_interval - delta);
        }
      } while (index < e.packet.getDataSize());

      if (!m_abort_chunked_data)
      {
        INFO_LOG_FMT(NETPLAY, "Informing players of data chunk {} end.", id);

        sf::Packet pac;
        pac << MessageID::ChunkedDataEnd;
        pac << id;
        ChunkedDataSend(std::move(pac), e.target_pid, e.target_mode);
      }

      while (m_chunked_data_complete_count[id] < player_count && m_do_loop &&
             !m_abort_chunked_data && !skip_wait)
        m_chunked_data_complete_event.Wait();
      m_chunked_data_complete_count.erase(id);
      m_dialog->HideChunkedProgressDialog();

      m_chunked_data_queue.Pop();
    }
  }

  INFO_LOG_FMT(NETPLAY, "Stopping Chunked Data Thread.");
}

void NetPlayServer::ChunkedDataSend(sf::Packet&& packet, const PlayerId pid,
                                    const TargetMode target_mode)
{
  if (target_mode == TargetMode::Only)
  {
    SendAsync(std::move(packet), pid, CHUNKED_DATA_CHANNEL);
  }
  else
  {
    SendAsyncToClients(std::move(packet), pid, CHUNKED_DATA_CHANNEL);
  }
}

void NetPlayServer::ChunkedDataAbort()
{
  m_abort_chunked_data = true;
  m_chunked_data_event.Set();
  m_chunked_data_complete_event.Set();
}

}  // namespace NetPlay
