// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/State.h"
#include "Core/StateFile.h"

#include <algorithm>
#include <filesystem>
#include <locale>
#include <map>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <utility>
#include <vector>

#include <fmt/chrono.h>
#include <fmt/format.h>
#include <fmt/std.h>

#include "Common/Buffer.h"
#include "Common/ChunkFile.h"
#include "Common/CommonTypes.h"
#include "Common/Contains.h"
#include "Common/FileUtil.h"
#include "Common/IOFile.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Common/Thread.h"
#include "Common/TimeUtil.h"
#include "Common/TransferableSharedMutex.h"
#include "Common/Version.h"
#include "Common/WorkQueueThread.h"

#include "Core/Achievements/AchievementManager.h"
#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/Cheats/GeckoCode.h"
#include "Core/HW/HW.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/Wiimote.h"
#include "Core/Movie.h"
#include "Core/NetPlay/NetPlayProto.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/System.h"

#include "UICommon/UICommon.h"

#include "VideoCommon/FrameDumpFFMpeg.h"
#include "VideoCommon/OnScreenDisplay.h"
#include "VideoCommon/VideoBackendBase.h"

namespace State
{

static AfterLoadCallbackFunc s_on_after_load_callback;
static Common::EventHook s_flush_unsaved_data_hook;

// Temporary undo state buffer
static Common::UniqueBuffer<u8> s_undo_load_buffer;

// Used to estimate buffer size for the next save.
static u32 s_last_state_size = 0;

// Shared locks are acquired for each state save task.
// Tasks generally transition from: Calling thread -> CPU thread -> Compress/Write thread.
// Holding an "exclusive" lock will:
// 1. Ensure all previous save tasks have been completely written to the file system.
// 2. Prevent new tasks from starting.
Common::TransferableSharedMutex s_state_saves_in_progress;

struct CompressAndDumpStateArgs
{
  Common::UniqueBuffer<u8> buffer;
  std::string filename;
  std::shared_lock<decltype(s_state_saves_in_progress)> task_lock;
};

// Queue for compressing and writing savestates to disk.
// Only the CPU thread manipulates this worker.
static Common::WorkQueueThreadSP<CompressAndDumpStateArgs> s_compress_and_dump_thread;

// Acquired for tasks that will write state save data to the filesystem.
// This allows for later waiting on completion of said tasks when necessary.
// We want to maintain a proper order of async operations, e.g. Save, Save, GetInfoString.
[[nodiscard]] static auto GetStateSaveTaskLock()
{
  return std::shared_lock{s_state_saves_in_progress};
}

static void DoState(Core::System& system, PointerWrap& p)
{
  bool is_wii = system.IsWii() || system.IsMIOS();
  const bool is_wii_currently = is_wii;
  p.Do(is_wii);
  if (is_wii != is_wii_currently)
  {
    OSD::AddMessage(fmt::format("Cannot load a savestate created under {} mode in {} mode",
                                is_wii ? "Wii" : "GC", is_wii_currently ? "Wii" : "GC"),
                    OSD::Duration::NORMAL, OSD::Color::RED);
    p.SetMeasureMode();
    return;
  }

  // Check to make sure the emulated memory sizes are the same as the savestate
  auto& memory = system.GetMemory();
  u32 state_mem1_size = memory.GetRamSizeReal();
  u32 state_mem2_size = memory.GetExRamSizeReal();
  p.Do(state_mem1_size);
  p.Do(state_mem2_size);
  if (state_mem1_size != memory.GetRamSizeReal() || state_mem2_size != memory.GetExRamSizeReal())
  {
    OSD::AddMessage(fmt::format("Memory size mismatch!\n"
                                "Current | MEM1 {:08X} ({:3}MB)    MEM2 {:08X} ({:3}MB)\n"
                                "State   | MEM1 {:08X} ({:3}MB)    MEM2 {:08X} ({:3}MB)",
                                memory.GetRamSizeReal(), memory.GetRamSizeReal() / 0x100000U,
                                memory.GetExRamSizeReal(), memory.GetExRamSizeReal() / 0x100000U,
                                state_mem1_size, state_mem1_size / 0x100000U, state_mem2_size,
                                state_mem2_size / 0x100000U));
    p.SetMeasureMode();
    return;
  }

  // Movie must be done before the video backend, because the window is redrawn in the video backend
  // state load, and the frame number must be up-to-date.
  system.GetMovie().DoState(p);
  p.DoMarker("Movie");

  // Begin with video backend, so that it gets a chance to clear its caches and writeback modified
  // things to RAM
  g_video_backend->DoState(p);
  p.DoMarker("video_backend");

  // CoreTiming needs to be restored before restoring Hardware because
  // the controller code might need to schedule an event if the controller has changed.
  system.GetCoreTiming().DoState(p);
  p.DoMarker("CoreTiming");

  // HW needs to be restored before PowerPC because the data cache might need to be flushed.
  HW::DoState(system, p);
  p.DoMarker("HW");

  system.GetPowerPC().DoState(p);
  p.DoMarker("PowerPC");

  if (system.IsWii())
    Wiimote::DoState(p);
  p.DoMarker("Wiimote");
  Gecko::DoState(p);
  p.DoMarker("Gecko");

#ifdef USE_RETRO_ACHIEVEMENTS
  AchievementManager::GetInstance().DoState(p);
#endif  // USE_RETRO_ACHIEVEMENTS
}

static bool CheckIfStateLoadIsAllowed(Core::System& system)
{
  if (!Core::IsRunningOrStarting(system))
    return false;

  if (NetPlay::IsNetPlayRunning())
  {
    OSD::AddMessage("Loading savestates is disabled in Netplay to prevent desyncs");
    return false;
  }

  if (AchievementManager::GetInstance().IsHardcoreModeActive())
  {
    OSD::AddMessage("Loading savestates is disabled in RetroAchievements hardcore mode");
    return false;
  }

  return true;
}

static bool LoadFromBuffer(Core::System& system, std::span<u8> buffer)
{
  u8* ptr = buffer.data();
  PointerWrap p(&ptr, buffer.size(), PointerWrap::Mode::Read);
  DoState(system, p);
  return p.IsReadMode();
}

// Returns the required size, or 0 on failure.
static std::size_t SaveToBuffer(Core::System& system, Common::UniqueBuffer<u8>& buffer)
{
  // Attempt to save to our provided buffer as-is.
  // If buffer isn't large enough, PointerWrap transitions to MeasureMode,
  //  and then we have our measurement for a second attempt.
  u8* ptr = buffer.data();
  PointerWrap pointer_wrap(&ptr, buffer.size(), PointerWrap::Mode::Write);
  DoState(system, pointer_wrap);
  const auto measured_size = pointer_wrap.GetOffsetFromPreviousPosition(buffer.data());

  if (pointer_wrap.IsWriteMode())
  {
    s_last_state_size = measured_size;
    return measured_size;
  }

  if (measured_size > buffer.size())
  {
    DEBUG_LOG_FMT(CORE, "SaveToBuffer: Growing buffer from size {} to measured size {}",
                  buffer.size(), measured_size);
    buffer.reset(measured_size);
    return SaveToBuffer(system, buffer);
  }

  // Buffer was large enough but we still failed for some other reason.
  return 0;
}

static void CompressAndDumpState(Core::System& system, const CompressAndDumpStateArgs& save_args)
{
  const auto& buffer = save_args.buffer;
  const std::string& filename = save_args.filename;

  // Find free temporary filename.
  std::string temp_filename;
  auto temp_counter = static_cast<size_t>(Common::CurrentThreadId());
  do
  {
    temp_filename = fmt::format("{}{}.tmp", filename, temp_counter);
    ++temp_counter;
  } while (File::Exists(temp_filename));

  File::IOFile f(temp_filename, "wb");
  if (!f)
  {
    Core::DisplayMessage("Failed to create state file", 2000);
    return;
  }

  WriteHeadersToFile(buffer.size(), f);

  if (s_use_compression)
    CompressBufferToFile(buffer, f);
  else
    f.WriteBytes(buffer.data(), buffer.size());

  if (!f.IsGood())
    Core::DisplayMessage("Failed to write state file", 2000);

  const std::string last_state_filename = File::GetUserPath(D_STATESAVES_IDX) + "lastState.sav";
  const std::string last_state_dtmname = last_state_filename + ".dtm";
  const std::string dtmname = filename + ".dtm";

  // Backup existing state (overwriting an existing backup, if any).
  if (File::Exists(filename))
  {
    if (File::Exists(last_state_filename))
      File::Delete((last_state_filename));
    if (File::Exists(last_state_dtmname))
      File::Delete((last_state_dtmname));

    if (!File::Rename(filename, last_state_filename))
    {
      Core::DisplayMessage("Failed to move previous state to state undo backup", 1000);
    }
    else if (File::Exists(dtmname))
    {
      if (!File::Rename(dtmname, last_state_dtmname))
        Core::DisplayMessage("Failed to move previous state's dtm to state undo backup", 1000);
    }
  }

  auto& movie = system.GetMovie();
  if ((movie.IsMovieActive()) && !movie.IsJustStartingRecordingInputFromSaveState())
    movie.SaveRecording(dtmname);
  else if (!movie.IsMovieActive())
    File::Delete(dtmname);

  // Move written state to final location.
  if (!f.Close())
    Core::DisplayMessage("Failed to close state file", 2000);

  if (!File::Rename(temp_filename, filename))
  {
    Core::DisplayMessage("Failed to rename state file", 2000);
  }
  else
  {
    const std::filesystem::path temp_path(filename);
    Core::DisplayMessage(fmt::format("Saved State to {}", temp_path.filename()), 2000);
  }
}

static void SaveAsFromCore(Core::System& system, std::string filename)
{
  const auto buffer_size_estimate = std::size_t(s_last_state_size) * 110 / 100;
  Common::UniqueBuffer<u8> buffer{buffer_size_estimate};

  if (const auto actual_size = SaveToBuffer(system, buffer))
  {
    buffer.assign(buffer.extract().first, actual_size);

    CompressAndDumpStateArgs dump_args{
        .buffer = std::move(buffer),
        .filename = std::move(filename),
        .task_lock = GetStateSaveTaskLock(),
    };
    Core::DisplayMessage("Saving State...", 1000);
    s_compress_and_dump_thread.EmplaceItem(std::move(dump_args));
  }
  else
  {
    Core::DisplayMessage("Unable to save: Internal DoState Error", 4000);
  }
}

void SaveAs(Core::System& system, std::string filename)
{
  Core::RunOnCPUThread(
      system, [&system, filename = std::move(filename), lock = GetStateSaveTaskLock()]() mutable {
        SaveAsFromCore(system, std::move(filename));
      });
}

static void LoadAsFromCore(Core::System& system, std::string filename)
{
  s_compress_and_dump_thread.WaitForCompletion();

  auto& movie = system.GetMovie();
  if (!movie.IsJustStartingRecordingInputFromSaveState())
  {
    SaveToBuffer(system, s_undo_load_buffer);
    const std::string dtmpath = File::GetUserPath(D_STATESAVES_IDX) + "undo.dtm";
    if (movie.IsMovieActive())
      movie.SaveRecording(dtmpath);
    else if (File::Exists(dtmpath))
      File::Delete(dtmpath);
  }

  bool was_file_read = false;
  bool loaded_successfully = false;

  {
    Common::UniqueBuffer<u8> buffer;
    LoadFileStateData(filename, buffer);

    if (!buffer.empty())
    {
      was_file_read = true;
      loaded_successfully = LoadFromBuffer(system, buffer);
    }
  }

  if (was_file_read)
  {
    if (loaded_successfully)
    {
      const std::filesystem::path temp_filename(filename);
      Core::DisplayMessage(fmt::format("Loaded State from {}", temp_filename.filename()), 2000);
      if (File::Exists(filename + ".dtm"))
      {
        movie.LoadInput(filename + ".dtm");
      }
      else if (!movie.IsJustStartingRecordingInputFromSaveState() &&
               !movie.IsJustStartingPlayingInputFromSaveState())
      {
        movie.EndPlayInput(false);
      }
    }
    else
    {
      Core::DisplayMessage("The savestate could not be loaded", OSD::Duration::NORMAL);
      UndoLoadState(system);
    }
  }

  if (s_on_after_load_callback)
    s_on_after_load_callback();
}

void LoadAs(Core::System& system, std::string filename)
{
  if (!CheckIfStateLoadIsAllowed(system))
    return;

  Core::RunOnCPUThread(system, [&system, filename = std::move(filename)]() mutable {
    LoadAsFromCore(system, std::move(filename));
  });
}

void SetOnAfterLoadCallback(AfterLoadCallbackFunc callback)
{
  s_on_after_load_callback = std::move(callback);
}

void Init(Core::System& system)
{
  s_compress_and_dump_thread.Reset("Savestate Worker",
                                   std::bind_front(&CompressAndDumpState, std::ref(system)));

  s_flush_unsaved_data_hook = UICommon::AddFlushUnsavedDataCallback([] {
    std::lock_guard lk{s_state_saves_in_progress};
  });
}

void Shutdown()
{
  s_compress_and_dump_thread.Shutdown();
  s_undo_load_buffer.reset();
  s_flush_unsaved_data_hook.reset();
}

void Save(Core::System& system, int slot)
{
  SaveAs(system, MakeStateFilename(slot));
}

void Load(Core::System& system, int slot)
{
  LoadAs(system, MakeStateFilename(slot));
}

void LoadLastSaved(Core::System& system, int i)
{
  if (!CheckIfStateLoadIsAllowed(system))
    return;

  Core::RunOnCPUThread(system, [&system, i] {
    s_compress_and_dump_thread.WaitForCompletion();

    std::vector<SlotWithTimestamp> used_slots = GetUsedSlotsWithTimestamp();
    if (std::size_t(i) > used_slots.size())
    {
      Core::DisplayMessage("State doesn't exist", 2000);
      return;
    }

    std::ranges::stable_sort(used_slots, std::ranges::greater{}, &SlotWithTimestamp::timestamp);
    LoadAsFromCore(system, MakeStateFilename(used_slots[i].slot));
  });
}

void SaveFirstSaved(Core::System& system)
{
  Core::RunOnCPUThread(system, [&system, lock = GetStateSaveTaskLock()] {
    s_compress_and_dump_thread.WaitForCompletion();

    std::vector<SlotWithTimestamp> used_slots = GetUsedSlotsWithTimestamp();
    auto slot = GetEmptySlot(used_slots);
    if (!slot.has_value())
    {
      std::ranges::stable_sort(used_slots, {}, &SlotWithTimestamp::timestamp);
      slot = used_slots.front().slot;
    }

    SaveAsFromCore(system, MakeStateFilename(*slot));
  });
}

void UndoLoadState(Core::System& system)
{
  if (!CheckIfStateLoadIsAllowed(system))
    return;

  Core::RunOnCPUThread(system, [&system] {
    if (s_undo_load_buffer.empty())
    {
      PanicAlertFmtT("There is nothing to undo!");
      return;
    }

    auto& movie = system.GetMovie();
    if (movie.IsMovieActive())
    {
      const std::string dtmpath = File::GetUserPath(D_STATESAVES_IDX) + "undo.dtm";
      if (File::Exists(dtmpath))
      {
        LoadFromBuffer(system, s_undo_load_buffer);
        movie.LoadInput(dtmpath);
      }
      else
      {
        PanicAlertFmtT("No undo.dtm found, aborting undo load state to prevent movie desyncs");
      }
    }
    else
    {
      LoadFromBuffer(system, s_undo_load_buffer);
    }
  });
}

void UndoSaveState(Core::System& system)
{
  LoadAs(system, File::GetUserPath(D_STATESAVES_IDX) + "lastState.sav");
}

}  // namespace State
