// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Core.h"
#include "Core/Host.h"
#include "Core/System.h"

#include <atomic>
#include <functional>
#include <mutex>
#include <queue>

namespace Core
{
extern std::atomic<State> s_state;

struct HostJob
{
  std::function<void(Core::System&)> job;
  bool run_after_stop;
};

static std::mutex s_host_jobs_lock;
static std::queue<HostJob> s_host_jobs_queue;

void QueueHostJob(std::function<void(Core::System&)> job, bool run_during_stop)
{
  if (!job)
    return;

  bool send_message = false;
  {
    std::lock_guard guard(s_host_jobs_lock);
    send_message = s_host_jobs_queue.empty();
    s_host_jobs_queue.emplace(HostJob{std::move(job), run_during_stop});
  }
  // If the queue was empty then kick the Host to come and get this job.
  if (send_message)
    Host_Message(HostMessageID::WMUserJobDispatch);
}

void HostDispatchJobs(Core::System& system)
{
  // WARNING: This should only run on the Host Thread.
  // NOTE: This function is potentially re-entrant. If a job calls
  //   Core::Stop for instance then we'll enter this a second time.
  std::unique_lock guard(s_host_jobs_lock);
  while (!s_host_jobs_queue.empty())
  {
    HostJob job = std::move(s_host_jobs_queue.front());
    s_host_jobs_queue.pop();

    if (!job.run_after_stop)
    {
      const State state = s_state.load();
      if (state == State::Stopping || state == State::Uninitialized)
        continue;
    }

    guard.unlock();
    job.job(system);
    guard.lock();
  }
}

}  // namespace Core
