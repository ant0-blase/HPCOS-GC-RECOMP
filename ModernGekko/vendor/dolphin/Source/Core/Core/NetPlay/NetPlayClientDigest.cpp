// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/NetPlay/NetPlayClient.h"
#include "Common/Crypto/SHA1.h"
#include "Common/FileUtil.h"
#include "Common/Logging/Log.h"
#include "Common/SFMLHelper.h"
#include "Core/NetPlay/NetPlayCommon.h"
#include "DiscIO/Blob.h"
#include "UICommon/GameFile.h"
#include <fmt/ranges.h>

namespace NetPlay
{

static void ReceiveSyncIdentifier(sf::Packet& spac, SyncIdentifier& sync_identifier)
{
  // We use a temporary variable here due to a potential long vs long long mismatch
  u64 dol_elf_size;
  spac >> dol_elf_size;
  sync_identifier.dol_elf_size = dol_elf_size;

  spac >> sync_identifier.game_id;
  spac >> sync_identifier.revision;
  spac >> sync_identifier.disc_number;
  spac >> sync_identifier.is_datel;

  for (u8& x : sync_identifier.sync_hash)
    spac >> x;
}

static std::string SHA1Sum(const std::string& file_path,
                           const std::function<bool(int)>& report_progress)
{
  std::vector<u8> data(8 * 1024 * 1024);
  u64 read_offset = 0;

  std::unique_ptr<DiscIO::BlobReader> file(DiscIO::CreateBlobReader(file_path));
  u64 game_size = file->GetDataSize();

  auto ctx = Common::SHA1::CreateContext();

  while (read_offset < game_size)
  {
    size_t read_size = std::min(static_cast<u64>(data.size()), game_size - read_offset);
    if (!file->Read(read_offset, read_size, data.data()))
      return "";

    ctx->Update(data.data(), read_size);
    read_offset += read_size;

    int progress =
        static_cast<int>(static_cast<float>(read_offset) / static_cast<float>(game_size) * 100);
    if (!report_progress(progress))
      return "";
  }

  return fmt::format("{:02x}", fmt::join(ctx->Finish(), ""));
}

void NetPlayClient::OnComputeGameDigest(sf::Packet& packet)
{
  SyncIdentifier sync_identifier;
  ReceiveSyncIdentifier(packet, sync_identifier);

  ComputeGameDigest(sync_identifier);
}

void NetPlayClient::OnGameDigestProgress(sf::Packet& packet)
{
  PlayerId pid;
  int progress;
  packet >> pid;
  packet >> progress;

  m_dialog->SetGameDigestProgress(pid, progress);
}

void NetPlayClient::OnGameDigestResult(sf::Packet& packet)
{
  PlayerId pid;
  std::string result;
  packet >> pid;
  packet >> result;

  m_dialog->SetGameDigestResult(pid, result);
}

void NetPlayClient::OnGameDigestError(sf::Packet& packet)
{
  PlayerId pid;
  std::string error;
  packet >> pid;
  packet >> error;

  m_dialog->SetGameDigestResult(pid, error);
}

void NetPlayClient::OnGameDigestAbort()
{
  m_should_compute_game_digest = false;
  m_dialog->AbortGameDigest();
}

void NetPlayClient::ComputeGameDigest(const SyncIdentifier& sync_identifier)
{
  if (m_should_compute_game_digest)
    return;

  m_dialog->ShowGameDigestDialog(sync_identifier.game_id);
  m_should_compute_game_digest = true;

  std::string file;
  if (sync_identifier == GetSDCardIdentifier())
    file = File::GetUserPath(F_WIISDCARDIMAGE_IDX);
  else if (auto game = m_dialog->FindGameFile(sync_identifier))
    file = game->GetFilePath();

  if (file.empty() || !File::Exists(file))
  {
    sf::Packet packet;
    packet << MessageID::GameDigestError;
    packet << "file not found";
    Send(packet);
    return;
  }

  if (m_game_digest_thread.joinable())
    m_game_digest_thread.join();
  m_game_digest_thread = std::thread([this, file] {
    std::string sum = SHA1Sum(file, [&](int progress) {
      sf::Packet packet;
      packet << MessageID::GameDigestProgress;
      packet << progress;
      SendAsync(std::move(packet));

      return m_should_compute_game_digest;
    });

    sf::Packet packet;
    packet << MessageID::GameDigestResult;
    packet << sum;
    SendAsync(std::move(packet));
  });
}

}  // namespace NetPlay
