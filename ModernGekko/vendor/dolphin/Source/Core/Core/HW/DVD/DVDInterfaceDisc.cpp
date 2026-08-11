// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/DVD/DVDInterface.h"
#include "Common/Logging/Log.h"
#include "Common/Config/Config.h"
#include "Core/Achievements/AchievementManager.h"
#include "Core/Config/SessionSettings.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/HW/SystemTimers.h"
#include "Core/HW/DVD/DVDThread.h"
#include "Core/HW/EXI/EXI_DeviceIPL.h"
#include "Core/IOS/DI/DI.h"
#include "Core/Movie.h"
#include "Core/System.h"
#include "DiscIO/VolumeDisc.h"
#include "DiscIO/Enums.h"
#include "DiscIO/DiscUtils.h"
#include "VideoCommon/OnScreenDisplay.h"

namespace DVD
{

static u64 GetDiscEndOffset(const DiscIO::VolumeDisc& disc)
{
  u64 size = disc.GetDataSize();

  if (disc.GetDataSizeType() == DiscIO::DataSizeType::Accurate)
  {
    if (size == DiscIO::MINI_DVD_SIZE)
      return DiscIO::MINI_DVD_SIZE;
  }
  else
  {
    size = DiscIO::GetBiggestReferencedOffset(disc);
  }

  const bool should_be_mini_dvd =
      disc.GetVolumeType() == DiscIO::Platform::GameCubeDisc || disc.IsDatelDisc();

  // We always return standard DVD sizes here, not DVD-R sizes.
  // RVT-R (devkit) consoles can't read the extra megabytes there are on RVT-R (DVD-R) discs.
  if (should_be_mini_dvd && size <= DiscIO::MINI_DVD_SIZE)
    return DiscIO::MINI_DVD_SIZE;
  else if (size <= DiscIO::SL_DVD_R_SIZE)
    return DiscIO::SL_DVD_SIZE;
  else
    return DiscIO::DL_DVD_SIZE;
}

void DVDInterface::SetDisc(std::unique_ptr<DiscIO::VolumeDisc> disc,
                           std::optional<std::vector<std::string>> auto_disc_change_paths)
{
  bool had_disc = IsDiscInside();
  bool has_disc = static_cast<bool>(disc);

  if (has_disc)
  {
    m_disc_end_offset = GetDiscEndOffset(*disc);
    if (disc->GetDataSizeType() != DiscIO::DataSizeType::Accurate)
      WARN_LOG_FMT(DVDINTERFACE, "Unknown disc size, guessing {0} bytes", m_disc_end_offset);

    const DiscIO::BlobReader& blob = disc->GetBlobReader();

    // DirectoryBlobs (including Riivolution-patched discs) may end up larger than a real physical
    // Wii disc, which triggers Error #001. In those cases we manually make the check succeed to
    // avoid problems.
    const bool should_fake_error_001 =
        m_system.IsWii() && blob.GetBlobType() == DiscIO::BlobType::DIRECTORY;
    Config::SetCurrent(Config::SESSION_SHOULD_FAKE_ERROR_001, should_fake_error_001);

    if (!blob.HasFastRandomAccessInBlock() && blob.GetBlockSize() > 0x200000)
    {
      OSD::AddMessage("You are running a disc image with a very large block size.", 60000);
      OSD::AddMessage("This will likely lead to performance problems.", 60000);
      OSD::AddMessage("You can use Dolphin's convert feature to reduce the block size.", 60000);
    }
  }

  if (auto_disc_change_paths)
  {
    ASSERT_MSG(DISCIO, auto_disc_change_paths->size() != 1,
               "Cannot automatically change between one disc");

    m_auto_disc_change_paths = *auto_disc_change_paths;
    m_auto_disc_change_index = 0;
  }

  // Assume that inserting a disc requires having an empty disc before
  if (had_disc != has_disc)
    ExpansionInterface::g_rtc_flags[ExpansionInterface::RTCFlag::DiscChanged] = true;

  m_system.GetDVDThread().SetDisc(std::move(disc));
  SetLidOpen();

  ResetDrive(false);
}

bool DVDInterface::IsDiscInside() const
{
  return m_system.GetDVDThread().HasDisc();
}

void DVDInterface::AutoChangeDiscCallback(Core::System& system, u64 userdata, s64 cyclesLate)
{
  system.GetDVDInterface().AutoChangeDisc(Core::CPUThreadGuard{system});
}

void DVDInterface::EjectDiscCallback(Core::System& system, u64 userdata, s64 cyclesLate)
{
  system.GetDVDInterface().SetDisc(nullptr, {});
}

void DVDInterface::InsertDiscCallback(Core::System& system, u64 userdata, s64 cyclesLate)
{
  auto& di = system.GetDVDInterface();
  std::unique_ptr<DiscIO::VolumeDisc> new_disc =
      DiscIO::CreateDiscForCore(di.m_disc_path_to_insert);

  if (new_disc)
  {
    AchievementManager::GetInstance().ChangeDisc(new_disc.get());
    di.SetDisc(std::move(new_disc), {});
  }
  else
  {
    PanicAlertFmtT("The disc that was about to be inserted couldn't be found.");
  }

  di.m_disc_path_to_insert.clear();
}

// Must only be called on the CPU thread
void DVDInterface::EjectDisc(const Core::CPUThreadGuard& guard, EjectCause cause)
{
  m_system.GetCoreTiming().ScheduleEvent(0, m_eject_disc);
  if (cause == EjectCause::User)
    ExpansionInterface::g_rtc_flags[ExpansionInterface::RTCFlag::EjectButton] = true;
}

// Must only be called on the CPU thread
void DVDInterface::ChangeDisc(const Core::CPUThreadGuard& guard,
                              const std::vector<std::string>& paths)
{
  ASSERT_MSG(DISCIO, !paths.empty(), "Trying to insert an empty list of discs");

  if (paths.size() > 1)
  {
    m_auto_disc_change_paths = paths;
    m_auto_disc_change_index = 0;
  }

  ChangeDisc(guard, paths[0]);
}

// Must only be called on the CPU thread
void DVDInterface::ChangeDisc(const Core::CPUThreadGuard& guard, const std::string& new_path)
{
  if (!m_disc_path_to_insert.empty())
  {
    PanicAlertFmtT("A disc is already about to be inserted.");
    return;
  }

  EjectDisc(guard, EjectCause::User);

  m_disc_path_to_insert = new_path;
  m_system.GetCoreTiming().ScheduleEvent(m_system.GetSystemTimers().GetTicksPerSecond(),
                                         m_insert_disc);
  m_system.GetMovie().SignalDiscChange(new_path);

  for (size_t i = 0; i < m_auto_disc_change_paths.size(); ++i)
  {
    if (m_auto_disc_change_paths[i] == new_path)
    {
      m_auto_disc_change_index = i;
      return;
    }
  }

  m_auto_disc_change_paths.clear();
}

// Must only be called on the CPU thread
bool DVDInterface::AutoChangeDisc(const Core::CPUThreadGuard& guard)
{
  if (m_auto_disc_change_paths.empty())
    return false;

  m_auto_disc_change_index = (m_auto_disc_change_index + 1) % m_auto_disc_change_paths.size();
  ChangeDisc(guard, m_auto_disc_change_paths[m_auto_disc_change_index]);
  return true;
}

void DVDInterface::SetLidOpen()
{
  const u32 old_value = m_DICVR.CVR;
  m_DICVR.CVR = IsDiscInside() ? 0 : 1;
  if (m_DICVR.CVR != old_value)
    GenerateDIInterrupt(DIInterruptType::CVRINT);
}

bool DVDInterface::UpdateRunningGameMetadata(std::optional<u64> title_id)
{
  auto& dvd_thread = m_system.GetDVDThread();

  if (!dvd_thread.HasDisc())
    return false;

  return dvd_thread.UpdateRunningGameMetadata(IOS::HLE::DIDevice::GetCurrentPartition(), title_id);
}

}  // namespace DVD
