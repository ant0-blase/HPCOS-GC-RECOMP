// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/FifoPlayer/FifoPlayer.h"

#include "Common/MsgHandler.h"
#include "Core/Core.h"
#include "Core/HW/CPU.h"
#include "Core/System.h"
#include "Core/Host.h"

FifoPlayer::CPUCore::CPUCore(FifoPlayer* parent) : m_parent(parent)
{
}

FifoPlayer::CPUCore::~CPUCore()
{
}

void FifoPlayer::CPUCore::Init()
{
  IsPlayingBackFifologWithBrokenEFBCopies = m_parent->m_File->HasBrokenEFBCopies();
  // Without this call, we deadlock in initialization in dual core, as the FIFO is disabled and
  // thus ClearEfb()'s call to WaitForGPUInactive() never returns
  m_parent->m_system.GetCPU().SetStepping(false);

  m_parent->m_CurrentFrame = m_parent->m_FrameRangeStart;
  m_parent->LoadMemory();
}

void FifoPlayer::CPUCore::Shutdown()
{
  IsPlayingBackFifologWithBrokenEFBCopies = false;
}

void FifoPlayer::CPUCore::ClearCache()
{
  // Nothing to clear.
}

void FifoPlayer::CPUCore::SingleStep()
{
  // NOTE: AdvanceFrame() will get stuck forever in Dual Core because the FIFO
  //   is disabled by CPU::SetStepping(true) so the frame never gets displayed.
  PanicAlertFmtT("Cannot SingleStep the FIFO. Use Frame Advance instead.");
}

const char* FifoPlayer::CPUCore::GetName() const
{
  return "FifoPlayer";
}

void FifoPlayer::CPUCore::Run()
{
  auto& cpu = m_parent->m_system.GetCPU();
  while (cpu.GetState() == CPU::State::Running)
  {
    switch (m_parent->AdvanceFrame())
    {
    case CPU::State::PowerDown:
      cpu.Break();
      Host_Message(HostMessageID::WMUserStop);
      break;

    case CPU::State::Stepping:
      cpu.Break();
      break;

    case CPU::State::Running:
      break;
    }
  }
}
