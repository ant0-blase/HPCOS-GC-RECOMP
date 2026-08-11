// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/Core.h"
#include "Core/System.h"

namespace Core
{
static thread_local bool tls_is_cpu_thread = false;
static thread_local bool tls_is_gpu_thread = false;

bool PauseAndLock(Core::System& system);
void RestoreStateAndUnlock(Core::System& system, const bool unpause_on_unlock);

void DeclareAsCPUThread()
{
  tls_is_cpu_thread = true;
}

void UndeclareAsCPUThread()
{
  tls_is_cpu_thread = false;
}

void DeclareAsGPUThread()
{
  tls_is_gpu_thread = true;
}

void UndeclareAsGPUThread()
{
  tls_is_gpu_thread = false;
}

bool IsCPUThread()
{
  return tls_is_cpu_thread;
}

bool IsGPUThread()
{
  return tls_is_gpu_thread;
}

CPUThreadGuard::CPUThreadGuard(Core::System& system)
    : m_system(system), m_was_cpu_thread(IsCPUThread())
{
  if (!m_was_cpu_thread)
    m_was_unpaused = PauseAndLock(system);
}

CPUThreadGuard::~CPUThreadGuard()
{
  if (!m_was_cpu_thread)
    RestoreStateAndUnlock(m_system, m_was_unpaused);
}

}  // namespace Core
