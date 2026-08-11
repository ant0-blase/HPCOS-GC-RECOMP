// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// dff2dolt — converts a Dolphin FIFO log (.dff, FifoDataFile v1-v6) into a
// .dolt trace. The SAME raw GX bytes Dolphin replays then flow
// through RetailGxFrontend / live Aurora, isolating the renderer-layer diff
// from CPU/recomp differences.
//
// Mapping (dolphin/Source/Core/Core/FifoPlayer/FifoDataFile.{h,cpp}):
//   frames[i].fifoData      -> GX_WRITE runs (8/4/2/1-byte records)
//   frames[i].memoryUpdates -> MEM_UPDATE at their fifoPosition interleave
//                              points (addresses are guest-physical; the
//                              replay resolver masks identically)
//   header BP/CP/XF/XFRegs  -> a synthesized state-restore FIFO preamble
//                              emitted before the first FRAME_BEGIN, using
//                              the exact command sequence + register
//                              exclusion lists of FifoPlayer::LoadRegisters
// No PRESENT_STATS records are written (Aurora ground truth does not exist
// for a Dolphin recording); replay closes frames at FRAME_BEGIN/EOF instead.
//
// Not restored (v1 gaps, both logged in stats): TMEM snapshot (Dolphin
// memcpys it outside the FIFO; not expressible as raw commands — S9 scenes
// carry a near-empty snapshot) and FifoPlayer::ClearEfb's synthetic clear.

#include <cstddef>
#include <cstdint>
#include <string>

namespace gxruntime::aurora_recomp::dff {

struct ConvertOptions {
  std::uint32_t frame_base = 1u; // first FRAME_BEGIN index (digests are 1-based)
};

struct ConvertStats {
  std::uint32_t dff_version = 0;
  std::uint32_t frames = 0;
  std::uint64_t fifo_bytes = 0;
  std::uint64_t gx_records = 0;
  std::uint32_t mem_updates = 0;
  std::uint64_t mem_update_bytes = 0;
  std::uint32_t skipped_exram_updates = 0; // GC titles should have none
  std::uint32_t preamble_bp_regs = 0;
  std::uint32_t preamble_cp_regs = 0;
  std::uint32_t preamble_xf_words = 0; // XF memory words written (4096)
  std::uint32_t preamble_xf_regs = 0;
  std::uint32_t tmem_nonzero_bytes = 0; // snapshot content we did NOT restore
  char game_id[9] = {};
};

// Converts an in-memory .dff image to a .dolt file at out_path. Returns false
// with *error set on malformed input or write failure.
bool convert(const std::uint8_t* dff_bytes, std::size_t dff_size,
             const char* out_path, const ConvertOptions& options,
             ConvertStats* stats, std::string* error);

// File-to-file convenience wrapper (reads the whole .dff into memory).
bool convert_file(const char* dff_path, const char* out_path,
                  const ConvertOptions& options, ConvertStats* stats,
                  std::string* error);

} // namespace gxruntime::aurora_recomp::dff
