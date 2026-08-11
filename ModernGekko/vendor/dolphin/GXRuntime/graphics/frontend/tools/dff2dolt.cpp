// SPDX-License-Identifier: GPL-3.0-or-later
// dff2dolt — Dolphin FIFO log (.dff) to .dolt trace converter.
// See include/gxruntime/aurora_recomp/dff2dolt.hpp for the mapping.

#include "gxruntime/aurora_recomp/dff2dolt.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

namespace {

int usage(std::FILE* out) {
  std::fprintf(out,
               "usage: dff2dolt <in.dff> <out.dolt> [options]\n"
               "  --frame-base <n>  first FRAME_BEGIN index (default 1)\n"
               "  --help            this text\n"
               "exit: 0 ok, 1 conversion failure, 2 usage error\n");
  return out == stdout ? 0 : 2;
}

} // namespace

int main(int argc, char** argv) {
  namespace dff = gxruntime::aurora_recomp::dff;

  const char* in_path = nullptr;
  const char* out_path = nullptr;
  dff::ConvertOptions options;

  for (int i = 1; i < argc; ++i) {
    const char* arg = argv[i];
    if (std::strcmp(arg, "--help") == 0)
      return usage(stdout);
    if (std::strcmp(arg, "--frame-base") == 0 && i + 1 < argc) {
      options.frame_base =
          static_cast<std::uint32_t>(std::strtoul(argv[++i], nullptr, 10));
    } else if (arg[0] != '-' && in_path == nullptr) {
      in_path = arg;
    } else if (arg[0] != '-' && out_path == nullptr) {
      out_path = arg;
    } else {
      std::fprintf(stderr, "dff2dolt: unknown argument '%s'\n", arg);
      return usage(stderr);
    }
  }
  if (in_path == nullptr || out_path == nullptr)
    return usage(stderr);

  dff::ConvertStats stats;
  std::string error;
  if (!dff::convert_file(in_path, out_path, options, &stats, &error)) {
    std::fprintf(stderr, "dff2dolt: FAIL %s\n", error.c_str());
    return 1;
  }
  std::fprintf(stderr,
               "dff2dolt: %s -> %s game_id=%s dff_v%u frames=%u "
               "fifo_bytes=%llu gx_records=%llu mem_updates=%u "
               "(%llu bytes) preamble bp=%u cp=%u xf_words=%u xf_regs=%u\n",
               in_path, out_path,
               stats.game_id[0] != '\0' ? stats.game_id : "(unset)",
               stats.dff_version, stats.frames,
               static_cast<unsigned long long>(stats.fifo_bytes),
               static_cast<unsigned long long>(stats.gx_records),
               stats.mem_updates,
               static_cast<unsigned long long>(stats.mem_update_bytes),
               stats.preamble_bp_regs, stats.preamble_cp_regs,
               stats.preamble_xf_words, stats.preamble_xf_regs);
  if (stats.skipped_exram_updates != 0u)
    std::fprintf(stderr, "dff2dolt: WARNING skipped %u EXRAM memory updates\n",
                 stats.skipped_exram_updates);
  if (stats.tmem_nonzero_bytes != 0u)
    std::fprintf(stderr,
                 "dff2dolt: note: TMEM snapshot has %u nonzero bytes that are "
                 "NOT restored (v1 gap; see dff2dolt.hpp)\n",
                 stats.tmem_nonzero_bytes);
  return 0;
}
