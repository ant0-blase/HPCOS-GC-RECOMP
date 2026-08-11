// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// Mode B1 pixel replay: replays a .dolt trace through the LIVE
// Aurora path (window + GPU) and emits one pixel-digest line per frame from
// EFB readbacks. Compiled into dolgx_replay only when the tool is built in
// an Aurora-enabled tree (DOLGX_REPLAY_HAS_PIXELS); the headless build keeps
// Mode A only.

#include <cstdint>
#include <string>

struct PixelReplayOptions {
  const char* golden_path = nullptr;  // exact line-compare against a golden
  const char* write_path = nullptr;   // write digest lines here
  const char* png_dir = nullptr;      // dump PNGs here
  unsigned png_every = 1;             // dump every Nth frame (and the last)
  bool quiet = false;
};

int dolgx_replay_pixels_main(const char* trace_path,
                             const PixelReplayOptions& options);

// Mode B2: same replay shape, but draws route through the gxcore
// plan pipeline (frontend -> GxCoreSink -> gxcore_draw) instead of the live
// Aurora gx layer. Compiled beside pixels mode (DOLGX_REPLAY_HAS_CORE).
int dolgx_replay_core_main(const char* trace_path,
                           const PixelReplayOptions& options);

// Shared by the pixel/core replay mains (defined in dolgx_replay_pixels.cpp):
// deterministic stored-deflate PNG writer.
bool dolgx_replay_write_png(const std::string& path, const std::uint8_t* rgba,
                            std::uint32_t width, std::uint32_t height);
