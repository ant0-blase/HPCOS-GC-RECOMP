// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/FifoPlayer/FifoPlayer.h"

#include <cstring>
#include <type_traits>

#include "Common/Assert.h"
#include "Common/CommonTypes.h"
#include "Core/FifoPlayer/FifoDataFile.h"
#include "VideoCommon/BPMemory.h"
#include "VideoCommon/CommandProcessor.h"
#include "VideoCommon/VideoCommon.h"

namespace
{
class FifoPlaybackAnalyzer : public OpcodeDecoder::Callback
{
public:
  static void AnalyzeFrames(FifoDataFile* file, std::vector<AnalyzedFrameInfo>& frame_info);

  explicit FifoPlaybackAnalyzer(const u32* cpmem) : m_cpmem(cpmem) {}

  OPCODE_CALLBACK(void OnXF(u16 address, u8 count, const u8* data)) {}
  OPCODE_CALLBACK(void OnCP(u8 command, u32 value)) { GetCPState().LoadCPReg(command, value); }
  OPCODE_CALLBACK(void OnBP(u8 command, u32 value));
  OPCODE_CALLBACK(void OnIndexedLoad(CPArray array, u32 index, u16 address, u8 size)) {}
  OPCODE_CALLBACK(void OnPrimitiveCommand(OpcodeDecoder::Primitive primitive, u8 vat,
                                          u32 vertex_size, u16 num_vertices,
                                          const u8* vertex_data));
  OPCODE_CALLBACK(void OnDisplayList(u32 address, u32 size)) {}
  OPCODE_CALLBACK(void OnNop(u32 count));
  OPCODE_CALLBACK(void OnUnknown(u8 opcode, const u8* data)) {}

  OPCODE_CALLBACK(void OnCommand(const u8* data, u32 size));

  OPCODE_CALLBACK(CPState& GetCPState()) { return m_cpmem; }

  bool m_start_of_primitives = false;
  bool m_end_of_primitives = false;
  bool m_efb_copy = false;
  // Internal state, copied to above in OnCommand
  bool m_was_primitive = false;
  bool m_is_primitive = false;
  bool m_is_copy = false;
  bool m_is_nop = false;
  CPState m_cpmem;
};

void FifoPlaybackAnalyzer::AnalyzeFrames(FifoDataFile* file,
                                         std::vector<AnalyzedFrameInfo>& frame_info)
{
  FifoPlaybackAnalyzer analyzer(file->GetCPMem());
  frame_info.clear();
  frame_info.resize(file->GetFrameCount());

  for (u32 frame_no = 0; frame_no < file->GetFrameCount(); frame_no++)
  {
    const FifoFrameInfo& frame = file->GetFrame(frame_no);
    AnalyzedFrameInfo& analyzed = frame_info[frame_no];

    u32 offset = 0;

    u32 part_start = 0;
    CPState cpmem;

    while (offset < frame.fifoData.size())
    {
      const u32 cmd_size = OpcodeDecoder::RunCommand(&frame.fifoData[offset],
                                                     u32(frame.fifoData.size()) - offset, analyzer);

      if (analyzer.m_start_of_primitives)
      {
        // Start of primitive data for an object
        analyzed.AddPart(FramePartType::Commands, part_start, offset, analyzer.m_cpmem);
        part_start = offset;
        // Copy cpmem now, because end_of_primitives isn't triggered until the first opcode after
        // primitive data, and the first opcode might update cpmem
        static_assert(std::is_trivially_copyable_v<CPState>);
        std::memcpy(static_cast<void*>(&cpmem), static_cast<const void*>(&analyzer.m_cpmem),
                    sizeof(CPState));
      }
      if (analyzer.m_end_of_primitives)
      {
        // End of primitive data for an object, and thus end of the object
        analyzed.AddPart(FramePartType::PrimitiveData, part_start, offset, cpmem);
        part_start = offset;
      }

      offset += cmd_size;

      if (analyzer.m_efb_copy)
      {
        // We increase the offset beforehand, so that the trigger EFB copy command is included.
        analyzed.AddPart(FramePartType::EFBCopy, part_start, offset, analyzer.m_cpmem);
        part_start = offset;
      }
    }

    // The frame should end with an EFB copy, so part_start should have been updated to the end.
    ASSERT(part_start == frame.fifoData.size());
    ASSERT(offset == frame.fifoData.size());
  }
}

void FifoPlaybackAnalyzer::OnBP(u8 command, u32 value)
{
  if (command == BPMEM_TRIGGER_EFB_COPY)
    m_is_copy = true;
}

void FifoPlaybackAnalyzer::OnPrimitiveCommand(OpcodeDecoder::Primitive primitive, u8 vat,
                                              u32 vertex_size, u16 num_vertices,
                                              const u8* vertex_data)
{
  m_is_primitive = true;
}

void FifoPlaybackAnalyzer::OnNop(u32 count)
{
  m_is_nop = true;
}

void FifoPlaybackAnalyzer::OnCommand(const u8* data, u32 size)
{
  m_start_of_primitives = false;
  m_end_of_primitives = false;
  m_efb_copy = false;

  if (!m_is_nop)
  {
    if (m_is_primitive && !m_was_primitive)
      m_start_of_primitives = true;
    else if (m_was_primitive && !m_is_primitive)
      m_end_of_primitives = true;
    else if (m_is_copy)
      m_efb_copy = true;

    m_was_primitive = m_is_primitive;
  }
  m_is_primitive = false;
  m_is_copy = false;
  m_is_nop = false;
}
}  // namespace

void AnalyzeFifoFrames(FifoDataFile* file, std::vector<AnalyzedFrameInfo>& frame_info)
{
  FifoPlaybackAnalyzer::AnalyzeFrames(file, frame_info);
}
