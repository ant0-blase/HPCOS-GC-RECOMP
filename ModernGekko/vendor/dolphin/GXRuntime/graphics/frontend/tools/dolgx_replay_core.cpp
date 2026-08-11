// SPDX-License-Identifier: GPL-3.0-or-later
// dolgx_replay --core — Mode B2 gxcore pixel replay.
//
// Same replay shape as --pixels, but the live Aurora gx layer never sees the
// stream: records feed a local RetailGxFrontend whose normalized packets a
// GxCoreSink turns into DrawPlans, submitted through the fork's gxcore_draw
// module onto the Aurora substrate (device/passes/present/EFB readback).
// This is the S12 vertical slice; visual gaps against --pixels or Dolphin
// are the S13-S16 flip inventory, and every stubbed feature reports through
// the gap counters printed at exit.

#include "dolgx_replay_pixels.hpp"

#include "gxruntime/aurora_backend.h"
#include "gxruntime/aurora_recomp/retail_gx_frontend.hpp"
#include "gxruntime/aurora_recomp/trace.hpp"
#include "gxruntime/gxcore/gxcore.hpp"

#include "gfx/gxcore_draw.hpp" // fork-internal (aurora lib dir on this target)

#include <aurora/gfx.h>

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
}

namespace {

namespace trace = gxruntime::aurora_recomp::trace;
namespace ar = gxruntime::aurora_recomp;
namespace gxc = gxruntime::gxcore;

constexpr std::uint64_t kFnvBasis = 1469598103934665603ull;
constexpr std::uint64_t kFnvPrime = 1099511628211ull;

std::uint64_t fnv1a(const std::uint8_t* data, std::size_t size) {
  std::uint64_t hash = kFnvBasis;
  for (std::size_t i = 0; i < size; ++i) {
    hash ^= data[i];
    hash *= kFnvPrime;
  }
  return hash;
}

struct CoreContext {
  std::vector<std::uint8_t> mem1;
  unsigned long long submitted = 0;
  unsigned long long submit_rejected = 0;
};

bool mem1_resolver(void* user, u32 address, u32 size,
                   DolGuestAddressSpace space, DolGuestResourceKind resource,
                   DolGuestResolvedRange* out) {
  auto* ctx = static_cast<CoreContext*>(user);
  if (out == nullptr || size == 0u)
    return false;
  const u32 physical = dol_gx_recomp_guest_to_physical(address);
  if (physical >= ctx->mem1.size() || size > ctx->mem1.size() - physical)
    return false;
  *out = {
      .data = ctx->mem1.data() + physical,
      .address = address,
      .size = size,
      .available = static_cast<u32>(ctx->mem1.size() - physical),
      .space = space,
      .resource = resource,
  };
  return true;
}

void plan_observer(const gxc::DrawPlan& plan, void* user) {
  auto* ctx = static_cast<CoreContext*>(user);
  if (!plan.ok)
    return; // skip reasons are tallied in the sink's gap counters
  if (aurora::gfx::gxcore::submit_draw_plan(plan))
    ++ctx->submitted;
  else
    ++ctx->submit_rejected;
}

// EFB copy-to-texture: resolve the current EFB into a texture at the
// copy destination so later binds sample it (the sink flushed the pending draw
// first, so the pass holds the copied geometry).
void copy_observer(const gxc::EfbCopyCommand& cmd, void* /*user*/) {
  aurora::gfx::gxcore::copy_efb_to_texture(cmd);
}

void print_gap_counters(const gxc::GapCounters& c) {
  std::fprintf(stderr,
               "dolgx_replay: gxcore plans=%llu skipped=%llu cull_all=%llu "
               "efb_copies=%llu (depth %llu, display %llu)\n",
               c.draws_planned, c.draws_skipped, c.cull_all_draws,
               c.efb_copies, c.efb_copy_depth, c.efb_display_copies);
  struct {
    const char* name;
    unsigned long long value;
  } gaps[] = {
      {"missing_vcd", c.missing_vcd},
      {"vertex_decode_failures", c.vertex_decode_failures},
      {"unsupported_texgen", c.unsupported_texgen},
      {"per_vertex_tex_mtx", c.per_vertex_tex_mtx},
      {"unresolved_tex_matrix", c.unresolved_tex_matrix},
      {"normals_ignored", c.normals_ignored},
      {"lighting_ignored", c.lighting_ignored},
      {"tlut_texture", c.tlut_texture},
      {"alpha_compare_ignored", c.alpha_compare_ignored},
      {"efb_copy_ignored", c.efb_copy_ignored},
      {"fog_ignored", c.fog_ignored},
      {"indirect_ignored", c.indirect_ignored},
      {"logic_op_ignored", c.logic_op_ignored},
  };
  for (const auto& gap : gaps) {
    if (gap.value != 0)
      std::fprintf(stderr, "dolgx_replay: gxcore GAP %s=%llu\n", gap.name,
                   gap.value);
  }
}

std::string frontend_error_detail(const ar::RetailGxFrontend& frontend) {
  char buf[160];
  std::snprintf(buf, sizeof buf,
                "%s (opcode=0x%02X offset=%zu detail=%u,%u,%u,%u)",
                frontend.last_error() != nullptr ? frontend.last_error()
                                                 : "unknown",
                static_cast<unsigned>(frontend.last_error_opcode()),
                frontend.last_error_offset(), frontend.last_error_a(),
                frontend.last_error_b(), frontend.last_error_c(),
                frontend.last_error_d());
  return buf;
}

} // namespace

int dolgx_replay_core_main(const char* trace_path,
                           const PixelReplayOptions& options) {
  // Same determinism requirements as --pixels: pipelines ready at encode
  // time, and never re-record or shadow-decode inside a replay.
  setenv("AURORA_SYNC_PIPELINES", "1", 0);
  unsetenv("DOL_AURORA_RECOMP_TRACE_OUT");
  unsetenv("DOL_AURORA_RECOMP_TRACE_FRAMES");
  unsetenv("DOL_AURORA_RECOMP_FRONTEND_SHADOW");

  trace::TraceReader reader;
  if (!reader.open(trace_path)) {
    std::fprintf(stderr, "dolgx_replay: cannot open trace %s\n", trace_path);
    return 2;
  }
  const trace::TraceHeader& header = reader.header();

  CoreContext ctx;
  const std::uint32_t mem1_size =
      header.mem1_size != 0u ? header.mem1_size : 0x01800000u;
  ctx.mem1.assign(mem1_size, 0u);

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
  aurora::gfx::gxcore::reset_texture_cache();

  // The gxcore path re-decodes everything from the trace stream itself; no
  // GXInit/SDK baseline is fed (that would drive the live gx layer). From-boot
  // and dff-converted traces carry their own initial state by construction.
  ar::RetailGxFrontend frontend;
  DolGuestAddressResolver resolver;
  dol_guest_address_resolver_init_callback(&resolver, mem1_resolver, &ctx);
  frontend.reset(&resolver);
  frontend.set_packet_drain_enabled(true);

  gxc::GxCoreSink sink;
  sink.set_guest_resolver(&frontend.state().resolver);
  sink.set_plan_observer(plan_observer, &ctx);
  sink.set_copy_observer(copy_observer, &ctx);

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

  // Frame boundary: plan the frame's final draw, then present with a
  // readback armed, waiting by pumping GPU events only (see --pixels notes).
  auto present_and_capture = [&]() {
    frame_open = false;
    sink.flush_frame();
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
      std::uint8_t bytes[8] = {};
      if (size != 1u && size != 2u && size != 4u && size != 8u) {
        fail("GX_WRITE with unsupported size");
        break;
      }
      for (unsigned i = 0; i < size; ++i)
        bytes[i] =
            static_cast<std::uint8_t>(value >> ((size - 1u - i) * 8u));
      if (!frontend.write_fifo({bytes, size}) || !frontend.flush(&sink)) {
        fail("frontend rejected FIFO: " + frontend_error_detail(frontend));
        break;
      }
      break;
    }
    case trace::RecordKind::CallDisplayList: {
      std::uint32_t guest_addr = 0;
      std::span<const std::uint8_t> bytes;
      if (!trace::decode_call_display_list(record, guest_addr, bytes)) {
        fail("malformed CALL_DL");
        break;
      }
      if (!frontend.write_display_list(bytes, &sink)) {
        fail("frontend rejected display list: " +
             frontend_error_detail(frontend));
        break;
      }
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
      if (!frontend.set_cp_array(attr, guest_addr,
                                 static_cast<std::uint8_t>(stride))) {
        fail("set_cp_array rejected");
        break;
      }
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
      break; // unknown kinds are forward-compatible
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

  print_gap_counters(sink.counters());
  std::fprintf(stderr, "dolgx_replay: gxcore submitted=%llu rejected=%llu\n",
               ctx.submitted, ctx.submit_rejected);
  const auto& tex = aurora::gfx::gxcore::texture_cache_stats();
  std::fprintf(stderr,
               "dolgx_replay: gxcore texture uploads=%llu hits=%llu "
               "ci_uploads=%llu raw_fallback=%llu\n",
               tex.uploads, tex.hits, tex.ci_uploads, tex.raw_fallback);
  if (sink.failure_reason() != nullptr) {
    std::fprintf(stderr, "dolgx_replay: consumer failure: %s\n",
                 sink.failure_reason());
    ok = false;
    if (error.empty())
      error = sink.failure_reason();
  }

  dol_aurora_shutdown();

  if (!ok) {
    std::fprintf(stderr, "dolgx_replay: core FAIL %s\n", error.c_str());
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
