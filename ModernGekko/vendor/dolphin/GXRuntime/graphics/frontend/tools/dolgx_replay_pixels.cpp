// SPDX-License-Identifier: GPL-3.0-or-later
// dolgx_replay --pixels — Mode B1 pixel replay.
//
// Feeds the recorded stream through the SAME live entry points the backend
// uses in a real run — aurora_backend_gx_write (which applies the cull-all
// state interceptions), aurora_backend_call_display_list, and
// aurora_backend_set_array — over a MEM1 image reconstructed from MEM_UPDATE
// records, presents at each PRESENT_STATS, and reads the EFB back through
// the aurora 0006 patch. AURORA_SYNC_PIPELINES=1 is forced so draws are
// never skipped while a pipeline compiles (cold and warm runs must render
// identical frames; the double-replay hash compare is the M3 gate).
//
// Escape-fed state (GX_AURORA_* texture/TLUT metadata bridges) is not in the
// trace by design — pixel replay exercises the raw-register path that the
// eventual core cutover will use, so a visual gap against a live hybrid run
// is signal, not a defect of the harness.

#include "dolgx_replay_pixels.hpp"

#include "gxruntime/aurora_backend.h"
#include "gxruntime/aurora_recomp/trace.hpp"
#include "gxruntime/gx_recomp.h"

#include <aurora/gfx.h>
#include <dolphin/gx.h>

#include <algorithm>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <span>
#include <string>
#include <thread>
#include <vector>

extern "C" {
void aurora_backend_present(void);
bool aurora_backend_should_quit(void);
void aurora_backend_gx_write(u64 value, u8 size);
void aurora_backend_call_display_list(const void* data, u32 size);
void aurora_backend_set_array(u32 attr, const void* data, u32 size, u8 stride);
void aurora_backend_set_guest_address_resolver(
    DolPlatformGuestAddressResolverFn resolve, void* user);
}

namespace {

namespace trace = gxruntime::aurora_recomp::trace;

// GXAttr GX_VA_POS (dolphin/gx/GXEnum.h); the trace stores CP array indices
// relative to it (the backend's gx_attr_to_cp_array mapping).
constexpr u32 kGxVaPos = 9u;

constexpr std::uint64_t kFnvBasis = 1469598103934665603ull;
constexpr std::uint64_t kFnvPrime = 1099511628211ull;

struct PixelContext {
  std::vector<std::uint8_t> mem1;
};

bool mem1_resolver(void* user, u32 address, u32 size, DolGuestAddressSpace,
                   DolGuestResourceKind, const void** data, u32* available) {
  auto* ctx = static_cast<PixelContext*>(user);
  const u32 physical = dol_gx_recomp_guest_to_physical(address);
  if (physical >= ctx->mem1.size())
    return false;
  (void)size;
  *data = ctx->mem1.data() + physical;
  *available = static_cast<u32>(ctx->mem1.size() - physical);
  return true;
}

std::uint64_t fnv1a(const std::uint8_t* data, std::size_t size) {
  std::uint64_t hash = kFnvBasis;
  for (std::size_t i = 0; i < size; ++i) {
    hash ^= data[i];
    hash *= kFnvPrime;
  }
  return hash;
}

// --- Minimal deterministic PNG writer (RGBA8, stored-deflate zlib) -------

std::uint32_t crc32_update(std::uint32_t crc, const std::uint8_t* data,
                           std::size_t size) {
  static std::uint32_t table[256];
  static bool table_ready = false;
  if (!table_ready) {
    for (std::uint32_t n = 0; n < 256u; ++n) {
      std::uint32_t c = n;
      for (int k = 0; k < 8; ++k)
        c = (c & 1u) ? 0xEDB88320u ^ (c >> 1) : c >> 1;
      table[n] = c;
    }
    table_ready = true;
  }
  crc ^= 0xFFFFFFFFu;
  for (std::size_t i = 0; i < size; ++i)
    crc = table[(crc ^ data[i]) & 0xFFu] ^ (crc >> 8);
  return crc ^ 0xFFFFFFFFu;
}

void put_be32(std::vector<std::uint8_t>& out, std::uint32_t value) {
  out.push_back(static_cast<std::uint8_t>(value >> 24));
  out.push_back(static_cast<std::uint8_t>(value >> 16));
  out.push_back(static_cast<std::uint8_t>(value >> 8));
  out.push_back(static_cast<std::uint8_t>(value));
}

void put_chunk(std::vector<std::uint8_t>& out, const char type[4],
               const std::vector<std::uint8_t>& payload) {
  put_be32(out, static_cast<std::uint32_t>(payload.size()));
  const std::size_t crc_begin = out.size();
  out.insert(out.end(), type, type + 4);
  out.insert(out.end(), payload.begin(), payload.end());
  const std::uint32_t crc =
      crc32_update(0u, out.data() + crc_begin, out.size() - crc_begin);
  put_be32(out, crc);
}

} // namespace

bool dolgx_replay_write_png(const std::string& path, const std::uint8_t* rgba,
                            std::uint32_t width, std::uint32_t height) {
  // Raw image stream: one filter byte (0 = None) per row.
  std::vector<std::uint8_t> raw;
  raw.reserve((static_cast<std::size_t>(width) * 4u + 1u) * height);
  for (u32 y = 0; y < height; ++y) {
    raw.push_back(0u);
    const std::uint8_t* row = rgba + static_cast<std::size_t>(y) * width * 4u;
    raw.insert(raw.end(), row, row + static_cast<std::size_t>(width) * 4u);
  }
  // zlib stream with stored (uncompressed) deflate blocks.
  std::vector<std::uint8_t> zlib;
  zlib.push_back(0x78u);
  zlib.push_back(0x01u);
  std::size_t offset = 0;
  while (offset < raw.size()) {
    const std::size_t block = std::min<std::size_t>(65535u, raw.size() - offset);
    const bool final_block = offset + block == raw.size();
    zlib.push_back(final_block ? 1u : 0u);
    zlib.push_back(static_cast<std::uint8_t>(block & 0xFFu));
    zlib.push_back(static_cast<std::uint8_t>(block >> 8));
    zlib.push_back(static_cast<std::uint8_t>(~block & 0xFFu));
    zlib.push_back(static_cast<std::uint8_t>(~(block >> 8) & 0xFFu));
    zlib.insert(zlib.end(), raw.begin() + offset, raw.begin() + offset + block);
    offset += block;
  }
  std::uint32_t adler_a = 1u, adler_b = 0u;
  for (const std::uint8_t byte : raw) {
    adler_a = (adler_a + byte) % 65521u;
    adler_b = (adler_b + adler_a) % 65521u;
  }
  put_be32(zlib, (adler_b << 16) | adler_a);

  std::vector<std::uint8_t> png = {0x89u, 'P', 'N', 'G', 0x0Du, 0x0Au, 0x1Au,
                                   0x0Au};
  std::vector<std::uint8_t> ihdr;
  put_be32(ihdr, width);
  put_be32(ihdr, height);
  ihdr.push_back(8u);  // bit depth
  ihdr.push_back(6u);  // color type RGBA
  ihdr.push_back(0u);  // compression
  ihdr.push_back(0u);  // filter
  ihdr.push_back(0u);  // interlace
  put_chunk(png, "IHDR", ihdr);
  put_chunk(png, "IDAT", zlib);
  put_chunk(png, "IEND", {});

  std::ofstream out(path, std::ios::binary | std::ios::trunc);
  if (!out)
    return false;
  out.write(reinterpret_cast<const char*>(png.data()),
            static_cast<std::streamsize>(png.size()));
  return static_cast<bool>(out);
}

int dolgx_replay_pixels_main(const char* trace_path,
                             const PixelReplayOptions& options) {
  // Deterministic pixels need every draw's pipeline ready at encode time
  // (an explicit AURORA_SYNC_PIPELINES=0 wins, for experiments).
  setenv("AURORA_SYNC_PIPELINES", "1", 0);
  // The backend arms its recorder/shadow from these; a replay must never
  // re-record or shadow-decode.
  unsetenv("DOL_AURORA_RECOMP_TRACE_OUT");
  unsetenv("DOL_AURORA_RECOMP_TRACE_FRAMES");
  unsetenv("DOL_AURORA_RECOMP_FRONTEND_SHADOW");
  // This tool drives the live Aurora backend directly (EFB readback via the
  // Aurora substrate). Since the 63/Mfin default flip made gxcore the
  // backend's default renderer, pin it off here so this Aurora-path pixel
  // golden stays stable; the gxcore pixel path is gated by --core double-replay.
  setenv("DOL_GX_CORE", "0", 1);

  trace::TraceReader reader;
  if (!reader.open(trace_path)) {
    std::fprintf(stderr, "dolgx_replay: cannot open trace %s\n", trace_path);
    return 2;
  }
  const trace::TraceHeader& header = reader.header();

  PixelContext ctx;
  const std::uint32_t mem1_size =
      header.mem1_size != 0u ? header.mem1_size : 0x01800000u;
  ctx.mem1.assign(mem1_size, 0u);
  aurora_backend_set_guest_address_resolver(mem1_resolver, &ctx);

  // Fixed window geometry: the framebuffer size feeds the pixel hashes, so
  // goldens are only comparable at one size. Small enough that no display
  // clamps it (a clamped window resizes the framebuffer and every hash);
  // the actual size still scales with the host's backing factor and is part
  // of each digest line.
  const AuroraBackendConfig config = {
      .app_name = "dolgx_replay",
      .window_width = 1024,
      .window_height = 768,
      .vsync = false,
      .allow_texture_dumps = false,
      .info_logging = false,
      .graphics_logging = false,
      .force_untextured = false,
  };
  char arg0[] = "dolgx_replay";
  char* fake_argv[] = {arg0, nullptr};
  if (!dol_aurora_initialize(1, fake_argv, &config)) {
    std::fprintf(stderr, "dolgx_replay: aurora initialization failed\n");
    return 2;
  }

  // Canonical SDK baseline, exactly as a booting game establishes it before
  // any recording window opens. A windowed trace only carries the state its
  // frames rewrite; anything untouched since boot (e.g. genMode's TEV stage
  // count) must come from GXInit or shader generation reads garbage
  // (tevStages[tevStageCount - 1] with count 0 was a live crash). GXInit
  // leaves genMode/VCD/VAT behind the SDK dirty flags that only flush on an
  // SDK draw, so flush explicitly.
  static std::vector<std::uint8_t> gx_fifo(64u * 1024u);
  GXInit(gx_fifo.data(), static_cast<u32>(gx_fifo.size()));
  GXFlush();

  std::vector<std::string> lines;
  std::uint32_t current_frame = 0;
  bool frame_open = false;
  unsigned long long record_index = 0;
  bool ok = true;
  std::string error;

  auto fail = [&](const std::string& message) {
    ok = false;
    char prefix[64];
    std::snprintf(prefix, sizeof prefix, "record %llu frame %u: ",
                  record_index, current_frame);
    error = prefix + message;
  };

  // Frame boundary: present exactly where the backend presented, with a
  // readback armed for the submitted frame. Wait by pumping GPU events
  // only — presenting filler frames here would clear the framebuffer,
  // flicker the window, and race the capture (blank frames were captured
  // when the map from frame N was still in flight at frame N+1).
  // Backend-recorded traces close every frame at PRESENT_STATS; converted
  // Dolphin traces (dff2dolt) have no stats records and close at the next
  // FRAME_BEGIN / end-of-trace instead.
  auto present_and_capture = [&]() {
    frame_open = false;
    aurora_request_framebuffer_readback();
    aurora_backend_present();
    const std::uint8_t* rgba = nullptr;
    u32 width = 0;
    u32 height = 0;
    bool got_pixels = false;
    for (int attempt = 0; attempt < 20000; ++attempt) {
      if (aurora_take_framebuffer_readback(&rgba, &width, &height)) {
        got_pixels = true;
        break;
      }
      aurora_pump_framebuffer_readback();
      std::this_thread::sleep_for(std::chrono::microseconds(250));
    }
    if (!got_pixels) {
      fail("EFB readback never completed");
      return;
    }
    const std::uint64_t hash =
        fnv1a(rgba, static_cast<std::size_t>(width) * height * 4u);
    char line[96];
    std::snprintf(line, sizeof line, "frame %u pixels %ux%u fnv %016llx",
                  current_frame, width, height,
                  static_cast<unsigned long long>(hash));
    lines.push_back(line);
    if (!options.quiet)
      std::printf("%s\n", line);
    if (options.png_dir != nullptr &&
        (options.png_every <= 1u || current_frame % options.png_every == 0u)) {
      char path[1024];
      std::snprintf(path, sizeof path, "%s/frame_%05u.png", options.png_dir,
                    current_frame);
      if (!dolgx_replay_write_png(path, rgba, width, height))
        std::fprintf(stderr, "dolgx_replay: cannot write %s\n", path);
    }
  };

  trace::RecordView record;
  while (ok && reader.next(record)) {
    ++record_index;
    switch (record.kind) {
    case trace::RecordKind::FrameBegin: {
      std::uint32_t frame_index = 0;
      if (!trace::decode_frame_begin(record, frame_index)) {
        fail("malformed FRAME_BEGIN");
        break;
      }
      if (frame_open)
        present_and_capture();
      current_frame = frame_index;
      frame_open = true;
      break;
    }
    case trace::RecordKind::GxWrite: {
      std::uint8_t size = 0;
      std::uint64_t value = 0;
      if (!trace::decode_gx_write(record, size, value)) {
        fail("malformed GX_WRITE");
        break;
      }
      aurora_backend_gx_write(value, size);
      break;
    }
    case trace::RecordKind::CallDisplayList: {
      std::uint32_t guest_addr = 0;
      std::span<const std::uint8_t> bytes;
      if (!trace::decode_call_display_list(record, guest_addr, bytes)) {
        fail("malformed CALL_DL");
        break;
      }
      aurora_backend_call_display_list(bytes.data(),
                                       static_cast<u32>(bytes.size()));
      break;
    }
    case trace::RecordKind::SetArray: {
      std::uint8_t attr = 0;
      std::uint32_t guest_addr = 0;
      std::uint16_t stride = 0;
      if (!trace::decode_set_array(record, attr, guest_addr, stride) ||
          stride > 0xFFu) {
        fail("malformed SET_ARRAY");
        break;
      }
      const u32 physical = dol_gx_recomp_guest_to_physical(guest_addr);
      if (physical >= ctx.mem1.size()) {
        fail("SET_ARRAY outside MEM1");
        break;
      }
      aurora_backend_set_array(kGxVaPos + attr, ctx.mem1.data() + physical,
                               static_cast<u32>(ctx.mem1.size() - physical),
                               static_cast<u8>(stride));
      break;
    }
    case trace::RecordKind::MemUpdate: {
      std::uint32_t guest_addr = 0;
      std::span<const std::uint8_t> bytes;
      if (!trace::decode_mem_update(record, guest_addr, bytes)) {
        fail("malformed MEM_UPDATE");
        break;
      }
      const u32 physical = dol_gx_recomp_guest_to_physical(guest_addr);
      if (physical >= ctx.mem1.size() ||
          bytes.size() > ctx.mem1.size() - physical) {
        fail("MEM_UPDATE outside MEM1");
        break;
      }
      std::memcpy(ctx.mem1.data() + physical, bytes.data(), bytes.size());
      break;
    }
    case trace::RecordKind::PresentStats: {
      present_and_capture();
      break;
    }
    default:
      // Unknown kinds are forward-compatible: skip.
      break;
    }
    if (aurora_backend_should_quit()) {
      fail("window closed during replay");
      break;
    }
  }
  if (ok && frame_open)
    present_and_capture();
  if (reader.truncated())
    std::fprintf(stderr,
                 "dolgx_replay: trace ends mid-record (interrupted "
                 "recording); replayed the complete prefix\n");

  dol_aurora_shutdown();

  if (!ok) {
    std::fprintf(stderr, "dolgx_replay: pixels FAIL %s\n", error.c_str());
    return 1;
  }

  if (options.write_path != nullptr) {
    std::ofstream out(options.write_path, std::ios::trunc);
    if (!out) {
      std::fprintf(stderr, "dolgx_replay: cannot write %s\n",
                   options.write_path);
      return 2;
    }
    for (const std::string& line : lines)
      out << line << '\n';
  }

  int exit_code = 0;
  if (options.golden_path != nullptr) {
    std::ifstream golden(options.golden_path);
    if (!golden) {
      std::fprintf(stderr, "dolgx_replay: cannot open golden %s\n",
                   options.golden_path);
      return 2;
    }
    std::size_t line_index = 0;
    bool digest_ok = true;
    std::string golden_line;
    while (std::getline(golden, golden_line)) {
      if (line_index >= lines.size() || golden_line != lines[line_index]) {
        std::fprintf(stderr,
                     "dolgx_replay: pixel digest FAIL line %zu\n  golden: %s\n"
                     "  replay: %s\n",
                     line_index + 1u, golden_line.c_str(),
                     line_index < lines.size() ? lines[line_index].c_str()
                                               : "(missing)");
        digest_ok = false;
        break;
      }
      ++line_index;
    }
    if (digest_ok && line_index != lines.size()) {
      std::fprintf(stderr,
                   "dolgx_replay: pixel digest FAIL golden has %zu lines, "
                   "replay produced %zu\n",
                   line_index, lines.size());
      digest_ok = false;
    }
    if (digest_ok)
      std::fprintf(stderr, "dolgx_replay: pixel digest OK (%zu lines)\n",
                   line_index);
    else
      exit_code = 1;
  }
  return exit_code;
}
