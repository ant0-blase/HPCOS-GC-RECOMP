// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// .dolt Mode A replay core: boot-free, GPU-free re-decode
// of a recorded GX stream through RetailGxFrontend + ConsumingAuroraRenderSink
// over a shadow MEM1 image, producing one digest line per frame. Digests are
// gated against the trace's own PRESENT_STATS (steady-state rules) or an
// exact golden digest file.

#include "gxruntime/aurora_recomp/retail_gx_frontend.hpp"
#include "gxruntime/aurora_recomp/trace.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace gxruntime::aurora_recomp::replay {

struct FrameDigest {
  std::uint32_t frame_index = 0;
  // Per-frame deltas of the sink's cumulative counters. verts/topo/store are
  // the DRAW-INPUT byte extents an issued draw would submit to Aurora
  // (push_verts / push_indices / push_storage), i.e. the same triple the
  // backend's shadow-extent gate diffs against AuroraStats.
  unsigned long long draws = 0;
  // Zero-vertex draw headers the frontend no-ops (s56). Live Aurora counts
  // each unmerged one in drawCallCount, so the stats gate compares
  // draws + zero_draws against the recorded draw_call_count.
  unsigned long long zero_draws = 0;
  unsigned long long vert_bytes = 0;
  unsigned long long topo_bytes = 0;
  unsigned long long store_bytes = 0;
  unsigned long long elements = 0; // assembled indexed elements
  std::uint64_t content_fnv = 0;   // vertex payloads + assembled element bytes
  std::uint64_t state_fnv = 0;     // draw-time transform snapshots
  bool has_stats = false;
  trace::PresentStats stats{};
};

struct ReplayResult {
  bool parse_ok = true;
  std::string error; // set when parse_ok is false
  bool truncated = false;
  std::vector<FrameDigest> frames;
};

// Replays every record of a freshly opened (or rewound) reader. The optional
// observer taps every frontend decode event (histograms).
ReplayResult replay_trace(
    trace::TraceReader& reader,
    RetailGxFrontend::TraceEventObserver event_observer = nullptr,
    void* event_observer_user = nullptr);

// "frame N draws D zdraws Z verts V topo T store S elems E fnv X state H"
std::string format_digest_line(const FrameDigest& f);

struct StatsCompareResult {
  bool ok = false;
  unsigned long long frames_compared = 0;
  unsigned long long mismatch_frames = 0;
  unsigned long long worst_consecutive = 0;
  std::string detail; // first mismatching frame, or why nothing compared
};

// Gate rules (backend shadow-diff parity, sessions 46/51/63-S4):
// draws + zero_draws must equal stats.draw_call_count exactly (live Aurora
// counts zero-vertex retail draws; the frontend no-ops them); raw vertex
// bytes must satisfy stats.last_vert_size >= vert_bytes with excess <=
// 4*draws+4 (Aurora pads each unmerged draw to 4 bytes). Transient rule: the
// run fails only when more than 2 consecutive frames mismatch. Topology/
// storage extents carry Aurora merge/cache caveats and are never gated.
StatsCompareResult compare_against_stats(const ReplayResult& result);

} // namespace gxruntime::aurora_recomp::replay
