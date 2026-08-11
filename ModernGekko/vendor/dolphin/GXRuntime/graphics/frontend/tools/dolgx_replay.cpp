// SPDX-License-Identifier: GPL-3.0-or-later
// dolgx_replay — Mode A headless digest replay of a .dolt trace.
// Re-decodes the recorded GX stream through RetailGxFrontend +
// ConsumingAuroraRenderSink (no Aurora, no GPU, no game boot) and emits one
// digest line per frame. Gates: --against-stats (the trace's own
// PRESENT_STATS, steady-state rules) or --digest <golden> (exact lines).

#include "gxruntime/aurora_recomp/replay.hpp"

#include "dolgx_replay_pixels.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace {

int usage(std::FILE* out) {
  std::fprintf(
      out,
      "usage: dolgx_replay <trace.dolt> [options]\n"
      "  --against-stats        gate replay digests against the trace's own\n"
      "                         PRESENT_STATS (draws exact + vert-extent band;\n"
      "                         fails on >2 consecutive mismatch frames)\n"
      "  --digest <golden>      exact line-compare against a golden digest file\n"
      "  --write-digest <path>  write the digest lines to <path>\n"
      "  --quiet                suppress per-frame digest lines on stdout\n"
      "  --histogram            print decode-event histograms (BP/CP/XF regs,\n"
      "                         TEV/genMode configs, tex/tlut/copy formats,\n"
      "                         draws) for M6 module ranking\n"
      "  --pixels               Mode B: replay through live Aurora (window +\n"
      "                         GPU) and emit per-frame pixel digests\n"
      "                         (Aurora-enabled builds only)\n"
      "  --core                 Mode B2: like --pixels but draws route\n"
      "                         through the gxcore Dolphin-ported core\n"
      "                         instead of the live Aurora gx layer\n"
      "  --pixel-digest <golden>       exact line-compare of pixel digests\n"
      "  --write-pixel-digest <path>   write pixel digest lines to <path>\n"
      "  --png-dir <dir>        with --pixels, dump one PNG per frame\n"
      "  --help                 this text\n"
      "exit: 0 ok, 1 replay/comparison failure, 2 usage or I/O error\n");
  return out == stdout ? 0 : 2;
}

// --histogram: module-demand tallies over the frontend's decode events
//. Ranks the M6 port queue; formats are named so the table maps
// straight onto Dolphin's TextureDecoder/TEV/copy modules.
struct Histogram {
  std::map<std::uint32_t, std::uint64_t> bp_regs;
  std::map<std::uint32_t, std::uint64_t> xf_regs;      // 0x1000-relative
  std::map<std::uint32_t, std::uint64_t> xf_mem_bases; // matrix/light memory
  std::map<std::uint32_t, std::uint64_t> cp_vcd_lo;    // distinct values
  std::map<std::uint32_t, std::uint64_t> tev_stage_counts;
  std::map<std::uint32_t, std::uint64_t> texgen_counts;
  std::map<std::uint32_t, std::uint64_t> ind_stage_counts;
  std::map<std::uint32_t, std::uint64_t> tex_formats;
  std::map<std::uint32_t, std::uint64_t> tlut_formats;
  std::map<std::uint32_t, std::uint64_t> copy_targets; // raw trigger bits3-6
  std::map<std::uint32_t, std::uint64_t> draw_prims;   // cmd&0xF8 per vtxfmt<<8
  std::uint64_t draw_verts = 0;
  std::uint64_t draws = 0;
  std::uint64_t display_lists = 0;
  std::uint64_t dl_bytes = 0;
  std::uint64_t indexed_xf_loads = 0;
  std::uint64_t indexed_spans = 0;
  std::uint64_t cull_all_writes = 0;
  std::uint64_t copies = 0;
  std::uint64_t copy_clears = 0;
  std::uint64_t copy_to_xfb = 0;
};

void histogram_observe(const DolGxRecompTraceEvent& event, void* user) {
  auto* h = static_cast<Histogram*>(user);
  switch (event.kind) {
  case DOL_GX_RECOMP_EVENT_BP_REG: {
    const std::uint32_t reg = event.a;
    const std::uint32_t value = event.b;
    ++h->bp_regs[reg];
    if (reg == 0x00u) { // genMode
      ++h->texgen_counts[value & 0xFu];
      ++h->tev_stage_counts[((value >> 10u) & 0xFu) + 1u];
      ++h->ind_stage_counts[(value >> 16u) & 0x7u];
    } else if (reg == 0x52u) { // copy trigger
      ++h->copies;
      ++h->copy_targets[(value >> 3u) & 0xFu];
      if ((value >> 11u) & 1u)
        ++h->copy_clears;
      if ((value >> 14u) & 1u)
        ++h->copy_to_xfb;
    }
    break;
  }
  case DOL_GX_RECOMP_EVENT_XF_LOAD:
    if (event.a >= 0x1000u) {
      for (std::uint32_t i = 0; i < event.b; ++i)
        ++h->xf_regs[event.a - 0x1000u + i];
    } else {
      ++h->xf_mem_bases[event.a & 0xFF00u]; // bucket by 256-word region
    }
    break;
  case DOL_GX_RECOMP_EVENT_CP_VCD:
    if (event.a == 0u)
      ++h->cp_vcd_lo[event.b];
    break;
  case DOL_GX_RECOMP_EVENT_TEXTURE:
    ++h->tex_formats[event.d];
    break;
  case DOL_GX_RECOMP_EVENT_TLUT:
    ++h->tlut_formats[event.d];
    break;
  case DOL_GX_RECOMP_EVENT_DRAW:
    ++h->draws;
    ++h->draw_prims[(event.b << 8u) | event.a];
    h->draw_verts += event.c;
    break;
  case DOL_GX_RECOMP_EVENT_DISPLAY_LIST:
    ++h->display_lists;
    h->dl_bytes += event.b;
    break;
  case DOL_GX_RECOMP_EVENT_INDEXED_XF_LOAD:
    ++h->indexed_xf_loads;
    break;
  case DOL_GX_RECOMP_EVENT_INDEXED_SPAN:
    ++h->indexed_spans;
    break;
  case DOL_GX_RECOMP_EVENT_CULL_ALL:
    ++h->cull_all_writes;
    break;
  default:
    break;
  }
}

const char* tex_format_name(std::uint32_t format) {
  switch (format) {
  case 0x0: return "I4";
  case 0x1: return "I8";
  case 0x2: return "IA4";
  case 0x3: return "IA8";
  case 0x4: return "RGB565";
  case 0x5: return "RGB5A3";
  case 0x6: return "RGBA8";
  case 0x8: return "C4";
  case 0x9: return "C8";
  case 0xA: return "C14X2";
  case 0xE: return "CMPR";
  default: return "?";
  }
}

const char* tlut_format_name(std::uint32_t format) {
  switch (format) {
  case 0x0: return "IA8";
  case 0x1: return "RGB565";
  case 0x2: return "RGB5A3";
  default: return "?";
  }
}

void print_histogram(const Histogram& h) {
  std::printf("== histogram: draws %llu (verts %llu) display_lists %llu "
              "(%llu bytes) indexed_xf %llu indexed_spans %llu cull_all %llu\n",
              (unsigned long long)h.draws, (unsigned long long)h.draw_verts,
              (unsigned long long)h.display_lists,
              (unsigned long long)h.dl_bytes,
              (unsigned long long)h.indexed_xf_loads,
              (unsigned long long)h.indexed_spans,
              (unsigned long long)h.cull_all_writes);
  std::printf("== copies %llu (clear %llu, to_xfb %llu) targets:",
              (unsigned long long)h.copies, (unsigned long long)h.copy_clears,
              (unsigned long long)h.copy_to_xfb);
  for (const auto& [target, count] : h.copy_targets)
    std::printf(" %u:%llu", target, (unsigned long long)count);
  std::printf("\n== tex formats:");
  for (const auto& [format, count] : h.tex_formats)
    std::printf(" %s:%llu", tex_format_name(format),
                (unsigned long long)count);
  std::printf("\n== tlut formats:");
  for (const auto& [format, count] : h.tlut_formats)
    std::printf(" %s:%llu", tlut_format_name(format),
                (unsigned long long)count);
  std::printf("\n== genMode: tev_stages");
  for (const auto& [stages, count] : h.tev_stage_counts)
    std::printf(" %u:%llu", stages, (unsigned long long)count);
  std::printf(" | texgens");
  for (const auto& [texgens, count] : h.texgen_counts)
    std::printf(" %u:%llu", texgens, (unsigned long long)count);
  std::printf(" | ind_stages");
  for (const auto& [stages, count] : h.ind_stage_counts)
    std::printf(" %u:%llu", stages, (unsigned long long)count);
  std::printf("\n== draw prims (prim/vtxfmt:count):");
  for (const auto& [key, count] : h.draw_prims)
    std::printf(" %02X/%u:%llu", key & 0xFFu, key >> 8u,
                (unsigned long long)count);
  std::printf("\n== vcd_lo values:");
  for (const auto& [value, count] : h.cp_vcd_lo)
    std::printf(" 0x%X:%llu", value, (unsigned long long)count);
  std::printf("\n== bp regs:");
  for (const auto& [reg, count] : h.bp_regs)
    std::printf(" %02X:%llu", reg, (unsigned long long)count);
  std::printf("\n== xf regs (0x1000+):");
  for (const auto& [reg, count] : h.xf_regs)
    std::printf(" %02X:%llu", reg, (unsigned long long)count);
  std::printf("\n== xf mem regions (base&0xFF00):");
  for (const auto& [base, count] : h.xf_mem_bases)
    std::printf(" %04X:%llu", base, (unsigned long long)count);
  std::printf("\n");
}

} // namespace

int main(int argc, char** argv) {
  const char* trace_path = nullptr;
  const char* golden_path = nullptr;
  const char* write_path = nullptr;
  bool against_stats = false;
  bool quiet = false;
  bool histogram = false;
  bool pixels = false;
  bool core = false;
  PixelReplayOptions pixel_options;

  for (int i = 1; i < argc; ++i) {
    const char* arg = argv[i];
    if (std::strcmp(arg, "--help") == 0)
      return usage(stdout);
    if (std::strcmp(arg, "--against-stats") == 0) {
      against_stats = true;
    } else if (std::strcmp(arg, "--quiet") == 0) {
      quiet = true;
    } else if (std::strcmp(arg, "--histogram") == 0) {
      histogram = true;
    } else if (std::strcmp(arg, "--digest") == 0 && i + 1 < argc) {
      golden_path = argv[++i];
    } else if (std::strcmp(arg, "--write-digest") == 0 && i + 1 < argc) {
      write_path = argv[++i];
    } else if (std::strcmp(arg, "--pixels") == 0) {
      pixels = true;
    } else if (std::strcmp(arg, "--core") == 0) {
      core = true;
    } else if (std::strcmp(arg, "--pixel-digest") == 0 && i + 1 < argc) {
      pixel_options.golden_path = argv[++i];
    } else if (std::strcmp(arg, "--write-pixel-digest") == 0 && i + 1 < argc) {
      pixel_options.write_path = argv[++i];
    } else if (std::strcmp(arg, "--png-dir") == 0 && i + 1 < argc) {
      pixel_options.png_dir = argv[++i];
    } else if (std::strcmp(arg, "--png-every") == 0 && i + 1 < argc) {
      pixel_options.png_every =
          static_cast<unsigned>(std::strtoul(argv[++i], nullptr, 10));
    } else if (arg[0] != '-' && trace_path == nullptr) {
      trace_path = arg;
    } else {
      std::fprintf(stderr, "dolgx_replay: unknown argument '%s'\n", arg);
      return usage(stderr);
    }
  }
  if (trace_path == nullptr)
    return usage(stderr);

  if (pixels || core) {
    if (against_stats || golden_path != nullptr || write_path != nullptr) {
      std::fprintf(stderr,
                   "dolgx_replay: --pixels/--core do not combine with Mode A "
                   "gates\n");
      return usage(stderr);
    }
    if (pixels && core) {
      std::fprintf(stderr,
                   "dolgx_replay: --pixels and --core are exclusive\n");
      return usage(stderr);
    }
    pixel_options.quiet = quiet;
    if (core) {
#if DOLGX_REPLAY_HAS_CORE
      return dolgx_replay_core_main(trace_path, pixel_options);
#else
      std::fprintf(stderr,
                   "dolgx_replay: this build has no --core support (built "
                   "without Aurora; use the StrikersRecomp GUI tree's "
                   "dolgx_replay)\n");
      return 2;
#endif
    }
#if DOLGX_REPLAY_HAS_PIXELS
    return dolgx_replay_pixels_main(trace_path, pixel_options);
#else
    std::fprintf(stderr,
                 "dolgx_replay: this build has no --pixels support (built "
                 "without Aurora; use the StrikersRecomp GUI tree's "
                 "dolgx_replay)\n");
    return 2;
#endif
  }

  namespace replay = gxruntime::aurora_recomp::replay;
  namespace trace = gxruntime::aurora_recomp::trace;

  trace::TraceReader reader;
  if (!reader.open(trace_path)) {
    std::fprintf(stderr, "dolgx_replay: cannot open trace %s\n", trace_path);
    return 2;
  }
  const trace::TraceHeader& header = reader.header();
  char game_id[9] = {};
  std::memcpy(game_id, header.game_id, sizeof header.game_id);
  std::fprintf(stderr, "dolgx_replay: %s game_id=%s mem1=0x%08X version=%u\n",
               trace_path, game_id[0] != '\0' ? game_id : "(unset)",
               header.mem1_size, reader.version());

  Histogram hist;
  const replay::ReplayResult result = replay::replay_trace(
      reader, histogram ? histogram_observe : nullptr, &hist);
  if (result.truncated)
    std::fprintf(stderr,
                 "dolgx_replay: trace ends mid-record (interrupted "
                 "recording); replayed the complete prefix\n");

  std::vector<std::string> lines;
  lines.reserve(result.frames.size());
  for (const replay::FrameDigest& frame : result.frames)
    lines.push_back(replay::format_digest_line(frame));

  if (!quiet)
    for (const std::string& line : lines)
      std::printf("%s\n", line.c_str());

  if (write_path != nullptr) {
    std::ofstream out(write_path, std::ios::trunc);
    if (!out) {
      std::fprintf(stderr, "dolgx_replay: cannot write %s\n", write_path);
      return 2;
    }
    for (const std::string& line : lines)
      out << line << '\n';
  }

  if (histogram)
    print_histogram(hist);

  if (!result.parse_ok) {
    std::fprintf(stderr, "dolgx_replay: FAIL %s\n", result.error.c_str());
    return 1;
  }

  int exit_code = 0;
  if (against_stats) {
    const replay::StatsCompareResult cmp =
        replay::compare_against_stats(result);
    std::fprintf(stderr,
                 "dolgx_replay: against-stats %s frames=%llu mismatches=%llu "
                 "worst_consecutive=%llu%s%s\n",
                 cmp.ok ? "OK" : "FAIL", cmp.frames_compared,
                 cmp.mismatch_frames, cmp.worst_consecutive,
                 cmp.detail.empty() ? "" : " first=",
                 cmp.detail.c_str());
    if (!cmp.ok)
      exit_code = 1;
  }

  if (golden_path != nullptr) {
    std::ifstream golden(golden_path);
    if (!golden) {
      std::fprintf(stderr, "dolgx_replay: cannot open golden %s\n",
                   golden_path);
      return 2;
    }
    std::size_t line_index = 0;
    bool digest_ok = true;
    std::string golden_line;
    while (std::getline(golden, golden_line)) {
      if (line_index >= lines.size()) {
        std::fprintf(stderr,
                     "dolgx_replay: digest FAIL golden has %zu+ lines, "
                     "replay produced %zu\n",
                     line_index + 1u, lines.size());
        digest_ok = false;
        break;
      }
      if (golden_line != lines[line_index]) {
        std::fprintf(stderr,
                     "dolgx_replay: digest FAIL line %zu\n  golden: %s\n"
                     "  replay: %s\n",
                     line_index + 1u, golden_line.c_str(),
                     lines[line_index].c_str());
        digest_ok = false;
        break;
      }
      ++line_index;
    }
    if (digest_ok && line_index != lines.size()) {
      std::fprintf(stderr,
                   "dolgx_replay: digest FAIL golden has %zu lines, replay "
                   "produced %zu\n",
                   line_index, lines.size());
      digest_ok = false;
    }
    if (digest_ok)
      std::fprintf(stderr, "dolgx_replay: digest OK (%zu lines)\n",
                   line_index);
    else
      exit_code = 1;
  }

  return exit_code;
}
