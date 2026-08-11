// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/WiimoteReal/WiimoteReal.h"

#include <chrono>
#include <mutex>
#include <thread>
#include <vector>

#include "Common/CommonTypes.h"
#include "Common/Config/Config.h"
#include "Common/Logging/Log.h"
#include "Common/Thread.h"
#include "Core/Config/MainSettings.h"
#include "Core/Config/WiiSettings.h"
#include "Core/Config/WiimoteSettings.h"
#include "Core/Core.h"
#include "Core/System.h"
#include "Core/HW/WiimoteCommon/DataReport.h"
#include "Core/HW/WiimoteReal/IOAndroid.h"
#include "Core/HW/WiimoteReal/IOLinux.h"
#include "Core/HW/WiimoteReal/IOWin.h"
#include "Core/HW/WiimoteReal/IOhidapi.h"
#include "InputCommon/ControllerInterface/ControllerInterface.h"
#include "InputCommon/ControllerInterface/Wiimote/WiimoteController.h"

namespace WiimoteReal
{
using namespace WiimoteCommon;

void WiimoteScanner::StartThread()
{
  if (m_scan_thread_running.IsSet())
    return;
  m_scan_thread_running.Set();
  m_scan_thread = std::thread(&WiimoteScanner::ThreadFunc, this);
}

void WiimoteScanner::StopThread()
{
  if (m_scan_thread_running.IsSet())
  {
    SetScanMode(WiimoteScanMode::DO_NOT_SCAN);

    for (const auto& backend : m_backends)
    {
      backend->RequestStopSearching();
    }

    m_scan_thread_running.Clear();
    m_scan_thread.join();
  }
}

void WiimoteScanner::SetScanMode(WiimoteScanMode scan_mode)
{
  m_scan_mode.store(scan_mode);
  m_scan_mode_changed_or_population_event.Set();
}

static void CheckForDisconnectedWiimotes()
{
  std::lock_guard lk(g_wiimotes_mutex);
  for (unsigned int i = 0; i < MAX_BBMOTES; ++i)
    if (g_wiimotes[i] && !g_wiimotes[i]->IsConnected())
      HandleWiimoteDisconnect(i);
}

void WiimoteScanner::PoolThreadFunc()
{
  Common::SetCurrentThreadName("Wiimote Pool Thread");

  // Toggle between 1010 and 0101.
  u8 led_value = 0b1010;

  auto next_time = std::chrono::steady_clock::now();

  while (m_scan_thread_running.IsSet())
  {
    std::this_thread::sleep_until(next_time);
    next_time += std::chrono::milliseconds(250);

    std::lock_guard lk(g_wiimotes_mutex);

    // Remove stale pool entries.
    for (auto it = s_wiimote_pool.begin(); it != s_wiimote_pool.end();)
    {
      if (!it->wiimote->IsConnected())
      {
        INFO_LOG_FMT(WIIMOTE, "Removing disconnected wiimote pool entry.");
        it = s_wiimote_pool.erase(it);
      }
      else if (it->IsExpired())
      {
        INFO_LOG_FMT(WIIMOTE, "Removing expired wiimote pool entry.");
        it = s_wiimote_pool.erase(it);
      }
      else
      {
        ++it;
      }
    }

    // Make wiimote pool LEDs dance.
    for (auto& wiimote : s_wiimote_pool)
    {
      OutputReportLeds leds = {};
      leds.leds = led_value;
      wiimote.wiimote->QueueReport(leds);
    }

    led_value ^= 0b1111;
  }
}

void WiimoteScanner::PopulateDevices()
{
  m_populate_devices.Set();
  m_scan_mode_changed_or_population_event.Set();
}

void WiimoteScanner::ThreadFunc()
{
  std::thread pool_thread(&WiimoteScanner::PoolThreadFunc, this);

  Common::SetCurrentThreadName("Wiimote Scanning Thread");

  NOTICE_LOG_FMT(WIIMOTE, "Wiimote scanning thread has started.");

  // Create and destroy scanner backends here to ensure all operations stay on the same thread. The
  // HIDAPI backend on macOS has an error condition when IOHIDManagerCreate and IOHIDManagerClose
  // are called on different threads (and so reference different CFRunLoops) which can cause an
  // EXC_BAD_ACCES crash.
  {
    std::lock_guard lg(m_backends_mutex);

    m_backends.emplace_back(std::make_unique<WiimoteScannerLinux>());
    m_backends.emplace_back(std::make_unique<WiimoteScannerAndroid>());
    m_backends.emplace_back(std::make_unique<WiimoteScannerWindows>());
    m_backends.emplace_back(std::make_unique<WiimoteScannerHidapi>());
  }

  while (m_scan_thread_running.IsSet())
  {
    m_scan_mode_changed_or_population_event.WaitFor(std::chrono::milliseconds(500));

    if (m_populate_devices.TestAndClear())
    {
      g_controller_interface.PlatformPopulateDevices([] { ProcessWiimotePool(); });
    }

    // Currently does nothing. To be removed.
    for (const auto& backend : m_backends)
      backend->Update();

    CheckForDisconnectedWiimotes();

    // If we don't want Wiimotes in ControllerInterface, we may not need them at all.
    if (!Config::Get(Config::MAIN_CONNECT_WIIMOTES_FOR_CONTROLLER_INTERFACE))
    {
      auto& system = Core::System::GetInstance();
      // We don't want any remotes in passthrough mode or running in GC mode.
      const bool core_running = Core::GetState(system) != Core::State::Uninitialized;
      if (Config::Get(Config::MAIN_BLUETOOTH_PASSTHROUGH_ENABLED) ||
          (core_running && !system.IsWii()))
      {
        continue;
      }

      // We don't want any remotes if we already connected everything we need.
      if (0 == CalculateWantedWiimotes() && 0 == CalculateWantedBB())
        continue;
    }

    // Stop scanning if not in continuous mode.
    auto scan_mode = WiimoteScanMode::SCAN_ONCE;
    m_scan_mode.compare_exchange_strong(scan_mode, WiimoteScanMode::DO_NOT_SCAN);

    // When not scanning we still look for already attached devices.
    // This allows Windows, hidapi, and DolphinBar remotes to be quickly discovered.
    const bool should_perform_inquiry = scan_mode != WiimoteScanMode::DO_NOT_SCAN;

    for (const auto& backend : m_backends)
    {
      auto results =
          should_perform_inquiry ? backend->FindNewWiimotes() : backend->FindAttachedWiimotes();
      {
        std::unique_lock wm_lk(g_wiimotes_mutex);

        for (auto& wiimote : results.wii_remotes)
        {
          {
            std::lock_guard lk(s_known_ids_mutex);
            s_known_ids.insert(wiimote->GetId());
          }

          AddWiimoteToPool(std::move(wiimote));
          g_controller_interface.PlatformPopulateDevices([] { ProcessWiimotePool(); });
        }

        for (auto& bboard : results.balance_boards)
        {
          {
            std::lock_guard lk(s_known_ids_mutex);
            s_known_ids.insert(bboard->GetId());
          }

          TryToConnectBalanceBoard(std::move(bboard));
        }
      }
    }
  }

  {
    std::lock_guard lg(m_backends_mutex);
    m_backends.clear();
  }

  pool_thread.join();

  NOTICE_LOG_FMT(WIIMOTE, "Wiimote scanning thread has stopped.");
}

} // namespace WiimoteReal
