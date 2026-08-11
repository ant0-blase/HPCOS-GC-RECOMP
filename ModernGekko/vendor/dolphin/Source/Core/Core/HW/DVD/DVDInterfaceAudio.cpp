// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/DVD/DVDInterface.h"
#include "AudioCommon/AudioCommon.h"
#include "Common/Logging/Log.h"
#include "Common/Swap.h"
#include "Core/CoreTiming.h"
#include "Core/HW/AudioInterface.h"
#include "Core/HW/DVD/DVDThread.h"
#include "Core/HW/SystemTimers.h"
#include "Core/System.h"

namespace DVD
{

static u64 PackFinishExecutingCommandUserdata(ReplyType reply_type, DIInterruptType interrupt_type)
{
  return (static_cast<u64>(reply_type) << 32) + static_cast<u32>(interrupt_type);
}

size_t DVDInterface::ProcessDTKSamples(s16* target_samples, size_t target_block_count,
                                       std::span<const u8> audio_data)
{
  const size_t block_count_to_process =
      std::min(target_block_count, audio_data.size() / StreamADPCM::ONE_BLOCK_SIZE);
  size_t samples_processed = 0;
  size_t bytes_processed = 0;
  for (size_t i = 0; i < block_count_to_process; ++i)
  {
    m_adpcm_decoder.DecodeBlock(&target_samples[samples_processed * 2],
                                &audio_data[bytes_processed]);
    for (size_t j = 0; j < StreamADPCM::SAMPLES_PER_BLOCK * 2; ++j)
    {
      // TODO: Fix the mixer so it can accept non-byte-swapped samples.
      s16* sample = &target_samples[samples_processed * 2 + j];
      *sample = Common::swap16(*sample);
    }
    samples_processed += StreamADPCM::SAMPLES_PER_BLOCK;
    bytes_processed += StreamADPCM::ONE_BLOCK_SIZE;
  }
  return block_count_to_process;
}

u32 DVDInterface::AdvanceDTK(u32 maximum_blocks, u32* blocks_to_process)
{
  u32 bytes_to_process = 0;
  *blocks_to_process = 0;
  while (*blocks_to_process < maximum_blocks)
  {
    if (m_audio_position >= m_current_start + m_current_length)
    {
      DEBUG_LOG_FMT(DVDINTERFACE,
                    "AdvanceDTK: NextStart={:08x}, NextLength={:08x}, "
                    "CurrentStart={:08x}, CurrentLength={:08x}, AudioPos={:08x}",
                    m_next_start, m_next_length, m_current_start, m_current_length,
                    m_audio_position);

      m_audio_position = m_next_start;
      m_current_start = m_next_start;
      m_current_length = m_next_length;

      if (m_stop_at_track_end)
      {
        m_stop_at_track_end = false;
        m_stream = false;
        break;
      }

      m_adpcm_decoder.ResetFilter();
    }

    m_audio_position += StreamADPCM::ONE_BLOCK_SIZE;
    bytes_to_process += StreamADPCM::ONE_BLOCK_SIZE;
    *blocks_to_process += 1;
  }

  return bytes_to_process;
}

void DVDInterface::DTKStreamingCallback(DIInterruptType interrupt_type,
                                        std::span<const u8> audio_data, s64 cycles_late)
{
  auto& ai = m_system.GetAudioInterface();

  // Actual games always set this to 48 KHz
  // but let's make sure to use GetAISSampleRateDivisor()
  // just in case it changes to 32 KHz
  const auto sample_rate = ai.GetAISSampleRate();
  const u32 sample_rate_divisor = ai.GetAISSampleRateDivisor();

  // Determine which audio data to read next.

  // 3.5 ms of samples
  constexpr u32 MAX_POSSIBLE_BLOCKS = 6;
  constexpr u32 MAX_POSSIBLE_SAMPLES = MAX_POSSIBLE_BLOCKS * StreamADPCM::SAMPLES_PER_BLOCK;
  const u32 maximum_blocks = sample_rate == AudioInterface::SampleRate::AI32KHz ? 4 : 6;
  u64 read_offset = 0;
  u32 read_length = 0;

  if (interrupt_type == DIInterruptType::TCINT)
  {
    // Send audio to the mixer.
    std::array<s16, MAX_POSSIBLE_SAMPLES * 2> temp_pcm{};
    ASSERT(m_pending_blocks <= MAX_POSSIBLE_BLOCKS);
    const u32 pending_blocks = std::min(m_pending_blocks, MAX_POSSIBLE_BLOCKS);
    ProcessDTKSamples(temp_pcm.data(), pending_blocks, audio_data);

    SoundStream* sound_stream = m_system.GetSoundStream();
    sound_stream->GetMixer()->PushStreamingSamples(temp_pcm.data(),
                                                   pending_blocks * StreamADPCM::SAMPLES_PER_BLOCK);

    if (m_stream && ai.IsPlaying())
    {
      read_offset = m_audio_position;
      read_length = AdvanceDTK(maximum_blocks, &m_pending_blocks);
    }
    else
    {
      read_length = 0;
      m_pending_blocks = maximum_blocks;
    }
  }
  else
  {
    read_length = 0;
    m_pending_blocks = maximum_blocks;
  }

  // Read the next chunk of audio data asynchronously.
  s64 ticks_to_dtk = m_system.GetSystemTimers().GetTicksPerSecond() * s64(m_pending_blocks) *
                     StreamADPCM::SAMPLES_PER_BLOCK * sample_rate_divisor /
                     Mixer::FIXED_SAMPLE_RATE_DIVIDEND;
  ticks_to_dtk -= cycles_late;
  if (read_length > 0)
  {
    m_system.GetDVDThread().StartRead(read_offset, read_length, DiscIO::PARTITION_NONE,
                                      ReplyType::DTK, ticks_to_dtk);
  }
  else
  {
    // There's nothing to read, so using DVDThread is unnecessary.
    u64 userdata = PackFinishExecutingCommandUserdata(ReplyType::DTK, DIInterruptType::TCINT);
    m_system.GetCoreTiming().ScheduleEvent(ticks_to_dtk, m_finish_executing_command, userdata);
  }
}

void DVDInterface::AudioBufferConfig(bool enable_dtk, u8 dtk_buffer_length)
{
  m_enable_dtk = enable_dtk;
  m_dtk_buffer_length = dtk_buffer_length;
  if (m_enable_dtk)
    INFO_LOG_FMT(DVDINTERFACE, "DTK enabled: buffer size {}", m_dtk_buffer_length);
  else
    INFO_LOG_FMT(DVDINTERFACE, "DTK disabled");
}

}  // namespace DVD
