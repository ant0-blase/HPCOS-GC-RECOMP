// SPDX-License-Identifier: GPL-3.0-or-later
// gxcore texture-decode conformance. Synthetic guest bytes ->
// exact RGBA8 hand-computed from Dolphin TextureDecoder_Generic semantics
// (the designated oracle; the fork substrate codec matches it bit-for-bit).
// THE synthetic-fixture pattern: build known guest bytes, assert decoded RGBA.

#include "gxruntime/gxcore/texture_decode.hpp"

#include <cstdint>
#include <cstdio>
#include <vector>

namespace gxc = gxruntime::gxcore;

static int g_failures = 0;

#define CHECK(cond)                                                           \
  do {                                                                        \
    if (!(cond)) {                                                            \
      std::fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond);    \
      ++g_failures;                                                           \
    }                                                                         \
  } while (0)

namespace {

// Assert RGBA of texel `i` in a tightly-packed RGBA8 buffer.
void check_texel(const std::vector<std::uint8_t>& rgba, std::size_t i,
                 std::uint8_t r, std::uint8_t g, std::uint8_t b,
                 std::uint8_t a, const char* label) {
  const std::size_t o = i * 4u;
  if (o + 3u >= rgba.size()) {
    std::fprintf(stderr, "FAIL %s: texel %zu out of range (size %zu)\n", label,
                 i, rgba.size());
    ++g_failures;
    return;
  }
  if (rgba[o] != r || rgba[o + 1] != g || rgba[o + 2] != b ||
      rgba[o + 3] != a) {
    std::fprintf(stderr,
                 "FAIL %s texel %zu: got (%u,%u,%u,%u) want (%u,%u,%u,%u)\n",
                 label, i, rgba[o], rgba[o + 1], rgba[o + 2], rgba[o + 3], r, g,
                 b, a);
    ++g_failures;
  }
}

// I8, 8x4 = one tile block, row-major: texel i = byte i, splatted to RGBA.
void test_i8() {
  std::vector<std::uint8_t> data(32);
  for (std::uint32_t i = 0; i < 32; ++i)
    data[i] = static_cast<std::uint8_t>(i);
  const auto rgba = gxc::decode_texture(
      static_cast<std::uint32_t>(gxc::TexFormat::I8), 8, 4, data.data(),
      data.size());
  CHECK(rgba.size() == 8u * 4u * 4u);
  for (std::uint32_t i = 0; i < 32; ++i)
    check_texel(rgba, i, static_cast<std::uint8_t>(i),
                static_cast<std::uint8_t>(i), static_cast<std::uint8_t>(i),
                static_cast<std::uint8_t>(i), "I8");
}

// IA8, 4x4 = one block, 2 bytes/texel. Native (LE) read: intensity = high byte
// (byte 2i+1), alpha = low byte (byte 2i).
void test_ia8() {
  std::vector<std::uint8_t> data(32);
  for (std::uint32_t i = 0; i < 16; ++i) {
    data[2 * i] = static_cast<std::uint8_t>(0x10 + i);     // alpha
    data[2 * i + 1] = static_cast<std::uint8_t>(0x80 + i); // intensity
  }
  const auto rgba = gxc::decode_texture(
      static_cast<std::uint32_t>(gxc::TexFormat::IA8), 4, 4, data.data(),
      data.size());
  CHECK(rgba.size() == 4u * 4u * 4u);
  for (std::uint32_t i = 0; i < 16; ++i) {
    const std::uint8_t inten = static_cast<std::uint8_t>(0x80 + i);
    const std::uint8_t alpha = static_cast<std::uint8_t>(0x10 + i);
    check_texel(rgba, i, inten, inten, inten, alpha, "IA8");
  }
}

// RGB5A3, 4x4. Big-endian read. Exercise both branches:
//   texel 0 = 0xFC00 (bit15 set): r5=0x1f -> 255, g=b=0, a=255.
//   texel 5 = 0x30F0 (bit15 clear): a3=3 -> 109, r4=0, g4=0xf -> 255, b4=0.
void test_rgb5a3() {
  std::vector<std::uint8_t> data(32, 0);
  auto put = [&](std::uint32_t i, std::uint16_t v) {
    data[2 * i] = static_cast<std::uint8_t>(v >> 8);   // big-endian high
    data[2 * i + 1] = static_cast<std::uint8_t>(v);    // low
  };
  put(0, 0xFC00);
  put(5, 0x30F0);
  const auto rgba = gxc::decode_texture(
      static_cast<std::uint32_t>(gxc::TexFormat::RGB5A3), 4, 4, data.data(),
      data.size());
  CHECK(rgba.size() == 4u * 4u * 4u);
  check_texel(rgba, 0, 255, 0, 0, 255, "RGB5A3.opaque");
  check_texel(rgba, 5, 0, 255, 0, 109, "RGB5A3.transparent");
}

// CMPR, 8x8 (one 4-subblock super-block). Top-left 4x4 sub-block only:
//   color1=0xF800 (red), color2=0x001F (blue), c1>c2 -> 4-color gradient.
//   color[0]=(255,0,0,255) color[1]=(0,0,255,255)
//   color[2]=(159,0,95,255) [ (3*c2+5*c1)>>3 ] color[3]=(95,0,159,255)
//   index rows: 0x00->all c0, 0x55->all c1, 0xAA->all c2, 0xFF->all c3.
void test_cmpr() {
  std::vector<std::uint8_t> data(32, 0);
  // Sub-block (0,0): 2B color1 (BE) + 2B color2 (BE) + 4B index rows.
  data[0] = 0xF8; data[1] = 0x00; // color1 = 0xF800
  data[2] = 0x00; data[3] = 0x1F; // color2 = 0x001F
  data[4] = 0x00; data[5] = 0x55; data[6] = 0xAA; data[7] = 0xFF; // index rows
  const auto rgba = gxc::decode_texture(
      static_cast<std::uint32_t>(gxc::TexFormat::CMPR), 8, 8, data.data(),
      data.size());
  CHECK(rgba.size() == 8u * 8u * 4u);
  // Row-major over the 8-wide image: texel(x,y) = index y*8 + x.
  check_texel(rgba, 0 * 8 + 0, 255, 0, 0, 255, "CMPR.row0");
  check_texel(rgba, 1 * 8 + 0, 0, 0, 255, 255, "CMPR.row1");
  check_texel(rgba, 2 * 8 + 0, 159, 0, 95, 255, "CMPR.row2");
  check_texel(rgba, 3 * 8 + 0, 95, 0, 159, 255, "CMPR.row3");
}

// C8 + IA8 TLUT, 8x4. Index = byte. Palette (IA8 native read): entry e ->
// (I,I,I,A) with I=byte[2e+1], A=byte[2e]. Out-of-range index -> transparent.
void test_c8_tlut() {
  std::vector<std::uint8_t> tex(32, 0);
  tex[0] = 0; tex[1] = 1; tex[2] = 2; tex[3] = 3;
  tex[4] = 5; // out of range (only 4 entries)
  std::vector<std::uint8_t> tlut(8);
  const std::uint8_t alpha[4] = {0xAA, 0xBB, 0xCC, 0xDD};
  const std::uint8_t inten[4] = {0x11, 0x22, 0x33, 0x44};
  for (std::uint32_t e = 0; e < 4; ++e) {
    tlut[2 * e] = alpha[e];
    tlut[2 * e + 1] = inten[e];
  }
  const auto rgba = gxc::decode_ci(
      static_cast<std::uint32_t>(gxc::TexFormat::C8), 8, 4, tex.data(),
      tex.size(), static_cast<std::uint32_t>(gxc::TlutFormat::IA8), 4,
      tlut.data(), tlut.size());
  CHECK(rgba.size() == 8u * 4u * 4u);
  check_texel(rgba, 0, 0x11, 0x11, 0x11, 0xAA, "C8.idx0");
  check_texel(rgba, 1, 0x22, 0x22, 0x22, 0xBB, "C8.idx1");
  check_texel(rgba, 2, 0x33, 0x33, 0x33, 0xCC, "C8.idx2");
  check_texel(rgba, 3, 0x44, 0x44, 0x44, 0xDD, "C8.idx3");
  check_texel(rgba, 4, 0, 0, 0, 0, "C8.oob");
}

} // namespace

int main() {
  test_i8();
  test_ia8();
  test_rgb5a3();
  test_cmpr();
  test_c8_tlut();
  if (g_failures != 0) {
    std::fprintf(stderr, "gxcore_texture_decode_tests: %d failure(s)\n",
                 g_failures);
    return 1;
  }
  std::printf("gxcore_texture_decode_tests: OK\n");
  return 0;
}
