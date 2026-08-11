// SPDX-License-Identifier: GPL-3.0-or-later
#include "gxruntime/gxcore/texture_decode.hpp"

#include <algorithm>
#include <array>
#include <cstring>

// Ported from graphics/aurora/lib/gfx/texture_convert.cpp (== Dolphin
// TextureDecoder_Generic, verified). Guest source is big-endian; reads
// are made explicit here so the result does not depend on host endianness:
//   rd_le16 == a native u16 read on a little-endian host (IA8 + IA8 TLUT),
//   rd_be16 == bswap(native u16) (RGB565/RGB5A3/C14X2/CMPR colors).

namespace gxruntime::gxcore {

namespace {

std::uint16_t rd_le16(const std::uint8_t* p) {
  return static_cast<std::uint16_t>(p[0] | (p[1] << 8));
}
std::uint16_t rd_be16(const std::uint8_t* p) {
  return static_cast<std::uint16_t>((p[0] << 8) | p[1]);
}

// Dolphin Convert{5,6,4,3}To8 == fork ExpandTo8<v>.
std::uint8_t expand5(std::uint32_t n) {
  return static_cast<std::uint8_t>((n << 3) | (n >> 2));
}
std::uint8_t expand6(std::uint32_t n) {
  return static_cast<std::uint8_t>((n << 2) | (n >> 4));
}
std::uint8_t expand4(std::uint32_t n) {
  return static_cast<std::uint8_t>((n << 4) | n);
}
std::uint8_t expand3(std::uint32_t n) {
  return static_cast<std::uint8_t>((n << 5) | (n << 2) | (n >> 1));
}
std::uint8_t dxt_blend(std::uint32_t a, std::uint32_t b) { // (3a + 5b) >> 3
  return static_cast<std::uint8_t>(((a * 3) + (b * 5)) >> 3);
}
std::uint8_t half_blend(std::uint32_t a, std::uint32_t b) {
  return static_cast<std::uint8_t>((a + b) >> 1);
}

struct Rgba {
  std::uint8_t r, g, b, a;
};

void put(std::vector<std::uint8_t>& out, std::size_t texel, Rgba c) {
  const std::size_t o = texel * 4u;
  out[o] = c.r;
  out[o + 1] = c.g;
  out[o + 2] = c.b;
  out[o + 3] = c.a;
}

Rgba decode_rgb565(std::uint16_t v) {
  return {expand5((v >> 11) & 0x1f), expand6((v >> 5) & 0x3f), expand5(v & 0x1f),
          0xff};
}
Rgba decode_rgb5a3(std::uint16_t v) {
  if ((v & 0x8000) != 0)
    return {expand5((v >> 10) & 0x1f), expand5((v >> 5) & 0x1f),
            expand5(v & 0x1f), 0xff};
  return {expand4((v >> 8) & 0xf), expand4((v >> 4) & 0xf), expand4(v & 0xf),
          expand3((v >> 12) & 0x7)};
}
Rgba decode_ia8(std::uint16_t v) { // native (LE) read: I=high, A=low
  const std::uint8_t i = static_cast<std::uint8_t>(v >> 8);
  return {i, i, i, static_cast<std::uint8_t>(v & 0xff)};
}

// Tile-block iterator: calls emit(dstTexelIndex, srcBytePtr) for each texel,
// where srcBytePtr points at that texel's slot in a row of `bytesPerTexel`
// (fractional bpp handled by the caller via `frac`). Mirrors the fork's
// DecodeTiled walk (in += BlockWidth/Frac per row, extraY partial-block skip).
template <typename Emit>
bool walk_tiles(std::uint32_t width, std::uint32_t height,
                std::uint32_t block_w, std::uint32_t block_h,
                std::uint32_t frac, std::uint32_t source_bytes,
                const std::uint8_t* data, std::size_t size, Emit emit) {
  // Fork DecodeTiled advances `in` by BlockWidth/Frac elements of sizeof(Source)
  // per source row (frac<1-byte texels pack multiple per byte).
  const std::uint32_t row_bytes = (block_w / frac) * source_bytes;
  std::size_t offset = 0;
  const std::uint32_t bwidth = (width + block_w - 1) / block_w;
  const std::uint32_t bheight = (height + block_h - 1) / block_h;
  for (std::uint32_t by = 0; by < bheight; ++by) {
    const std::uint32_t base_y = by * block_h;
    const std::uint32_t num_rows = std::min(height - base_y, block_h);
    for (std::uint32_t bx = 0; bx < bwidth; ++bx) {
      const std::uint32_t base_x = bx * block_w;
      for (std::uint32_t y = 0; y < num_rows; ++y) {
        if (offset + row_bytes > size)
          return false;
        const std::uint8_t* row = data + offset;
        const std::uint32_t n = std::min(width - base_x, block_w);
        for (std::uint32_t x = 0; x < n; ++x) {
          const std::size_t texel =
              static_cast<std::size_t>(base_y + y) * width + base_x + x;
          emit(texel, row, x);
        }
        offset += row_bytes;
      }
      offset += static_cast<std::size_t>(row_bytes) * (block_h - num_rows);
    }
  }
  return true;
}

// RGBA8: 4x4 blocks, two planes (AR then GB), 64 source bytes/block; `in`
// advances 8 bytes per row regardless of partial coverage (fork BuildRGBA8FromGCN).
bool decode_rgba8(std::uint32_t width, std::uint32_t height,
                  const std::uint8_t* data, std::size_t size,
                  std::vector<std::uint8_t>& out) {
  std::size_t offset = 0;
  const std::uint32_t bwidth = (width + 3) / 4;
  const std::uint32_t bheight = (height + 3) / 4;
  for (std::uint32_t by = 0; by < bheight; ++by) {
    const std::uint32_t base_y = by * 4;
    const std::uint32_t num_rows = std::min(height - base_y, 4u);
    for (std::uint32_t bx = 0; bx < bwidth; ++bx) {
      const std::uint32_t base_x = bx * 4;
      const std::uint32_t num_cols = std::min(width - base_x, 4u);
      for (std::uint32_t c = 0; c < 2; ++c) {
        for (std::uint32_t y = 0; y < 4; ++y) {
          if (offset + 8u > size)
            return false;
          const std::uint8_t* in = data + offset;
          if (y < num_rows) {
            for (std::uint32_t x = 0; x < num_cols; ++x) {
              const std::size_t o =
                  (static_cast<std::size_t>(base_y + y) * width + base_x + x) *
                  4u;
              if (c != 0) {
                out[o + 1] = in[x * 2];     // g
                out[o + 2] = in[x * 2 + 1]; // b
              } else {
                out[o + 3] = in[x * 2];     // a
                out[o + 0] = in[x * 2 + 1]; // r
              }
            }
          }
          offset += 8;
        }
      }
    }
  }
  return true;
}

// CMPR: 8x8 super-blocks of four 4x4 DXT1-like sub-blocks (8 bytes each);
// big-endian colors; GX c1<=c2 midpoint gets alpha 0 (differs from BC1).
bool decode_cmpr(std::uint32_t width, std::uint32_t height,
                 const std::uint8_t* data, std::size_t size,
                 std::vector<std::uint8_t>& out) {
  std::size_t offset = 0;
  for (std::uint32_t yy = 0; yy < height; yy += 8) {
    for (std::uint32_t xx = 0; xx < width; xx += 8) {
      for (std::uint32_t yb = 0; yb < 8; yb += 4) {
        for (std::uint32_t xb = 0; xb < 8; xb += 4) {
          if (offset + 8u > size)
            return false;
          const std::uint8_t* src = data + offset;
          const std::uint16_t c1 = rd_be16(src);
          const std::uint16_t c2 = rd_be16(src + 2);
          std::array<Rgba, 4> ct{};
          ct[0] = {expand5((c1 >> 11) & 0x1f), expand6((c1 >> 5) & 0x3f),
                   expand5(c1 & 0x1f), 0xff};
          ct[1] = {expand5((c2 >> 11) & 0x1f), expand6((c2 >> 5) & 0x3f),
                   expand5(c2 & 0x1f), 0xff};
          if (c1 > c2) {
            ct[2] = {dxt_blend(ct[1].r, ct[0].r), dxt_blend(ct[1].g, ct[0].g),
                     dxt_blend(ct[1].b, ct[0].b), 0xff};
            ct[3] = {dxt_blend(ct[0].r, ct[1].r), dxt_blend(ct[0].g, ct[1].g),
                     dxt_blend(ct[0].b, ct[1].b), 0xff};
          } else {
            ct[2] = {half_blend(ct[0].r, ct[1].r), half_blend(ct[0].g, ct[1].g),
                     half_blend(ct[0].b, ct[1].b), 0xff};
            ct[3] = {ct[2].r, ct[2].g, ct[2].b, 0x00};
          }
          for (std::uint32_t y = 0; y < 4; ++y) {
            std::uint32_t bits = src[4 + y];
            for (std::uint32_t x = 0; x < 4; ++x) {
              const std::uint32_t px = xx + xb + x;
              const std::uint32_t py = yy + yb + y;
              if (px < width && py < height)
                put(out, static_cast<std::size_t>(py) * width + px,
                    ct[(bits >> 6) & 3]);
              bits <<= 2;
            }
          }
          offset += 8;
        }
      }
    }
  }
  return true;
}

} // namespace

bool is_ci_format(std::uint32_t format) {
  return format == static_cast<std::uint32_t>(TexFormat::C4) ||
         format == static_cast<std::uint32_t>(TexFormat::C8) ||
         format == static_cast<std::uint32_t>(TexFormat::C14X2);
}

// Decode the raw palette-index buffer for a CI texture (indices, not RGBA).
static bool decode_ci_indices(std::uint32_t format, std::uint32_t width,
                              std::uint32_t height, const std::uint8_t* data,
                              std::size_t size,
                              std::vector<std::uint16_t>& out) {
  out.assign(static_cast<std::size_t>(width) * height, 0);
  switch (static_cast<TexFormat>(format)) {
  case TexFormat::C4:
    return walk_tiles(width, height, 8, 8, 2, 1, data, size,
                      [&](std::size_t t, const std::uint8_t* row,
                          std::uint32_t x) {
                        const std::uint8_t byte = row[x / 2];
                        out[t] = (x & 1) ? (byte & 0xf) : (byte >> 4);
                      });
  case TexFormat::C8:
    return walk_tiles(
        width, height, 8, 4, 1, 1, data, size,
        [&](std::size_t t, const std::uint8_t* row, std::uint32_t x) {
          out[t] = row[x];
        });
  case TexFormat::C14X2:
    return walk_tiles(
        width, height, 4, 4, 1, 2, data, size,
        [&](std::size_t t, const std::uint8_t* row, std::uint32_t x) {
          out[t] = rd_be16(row + x * 2) & 0x3fff;
        });
  default:
    return false;
  }
}

std::vector<std::uint8_t> decode_texture(std::uint32_t format,
                                         std::uint32_t width,
                                         std::uint32_t height,
                                         const std::uint8_t* data,
                                         std::size_t size) {
  if (width == 0 || height == 0 || data == nullptr)
    return {};
  std::vector<std::uint8_t> out(static_cast<std::size_t>(width) * height * 4u,
                                0);
  bool ok = false;
  switch (static_cast<TexFormat>(format)) {
  case TexFormat::I4:
    ok = walk_tiles(width, height, 8, 8, 2, 1, data, size,
                    [&](std::size_t t, const std::uint8_t* row,
                        std::uint32_t x) {
                      const std::uint8_t i = expand4(
                          (row[x / 2] >> ((x & 1) ? 0 : 4)) & 0xf);
                      put(out, t, {i, i, i, i});
                    });
    break;
  case TexFormat::I8:
    ok = walk_tiles(width, height, 8, 4, 1, 1, data, size,
                    [&](std::size_t t, const std::uint8_t* row,
                        std::uint32_t x) {
                      const std::uint8_t i = row[x];
                      put(out, t, {i, i, i, i});
                    });
    break;
  case TexFormat::IA4:
    ok = walk_tiles(width, height, 8, 4, 1, 1, data, size,
                    [&](std::size_t t, const std::uint8_t* row,
                        std::uint32_t x) {
                      const std::uint8_t i = expand4(row[x] & 0xf);
                      put(out, t, {i, i, i, expand4(row[x] >> 4)});
                    });
    break;
  case TexFormat::IA8:
    ok = walk_tiles(width, height, 4, 4, 1, 2, data, size,
                    [&](std::size_t t, const std::uint8_t* row,
                        std::uint32_t x) {
                      put(out, t, decode_ia8(rd_le16(row + x * 2)));
                    });
    break;
  case TexFormat::RGB565:
    ok = walk_tiles(width, height, 4, 4, 1, 2, data, size,
                    [&](std::size_t t, const std::uint8_t* row,
                        std::uint32_t x) {
                      put(out, t, decode_rgb565(rd_be16(row + x * 2)));
                    });
    break;
  case TexFormat::RGB5A3:
    ok = walk_tiles(width, height, 4, 4, 1, 2, data, size,
                    [&](std::size_t t, const std::uint8_t* row,
                        std::uint32_t x) {
                      put(out, t, decode_rgb5a3(rd_be16(row + x * 2)));
                    });
    break;
  case TexFormat::RGBA8:
    ok = decode_rgba8(width, height, data, size, out);
    break;
  case TexFormat::CMPR:
    ok = decode_cmpr(width, height, data, size, out);
    break;
  default:
    return {};
  }
  if (!ok)
    return {};
  return out;
}

std::vector<std::uint8_t> decode_tlut(std::uint32_t tlut_format,
                                      std::uint32_t entries,
                                      const std::uint8_t* data,
                                      std::size_t size) {
  if (entries == 0 || data == nullptr)
    return {};
  if (static_cast<std::size_t>(entries) * 2u > size)
    return {};
  std::vector<std::uint8_t> out(static_cast<std::size_t>(entries) * 4u, 0);
  for (std::uint32_t e = 0; e < entries; ++e) {
    const std::uint8_t* p = data + e * 2u;
    Rgba c;
    switch (static_cast<TlutFormat>(tlut_format)) {
    case TlutFormat::IA8:
      c = decode_ia8(rd_le16(p));
      break;
    case TlutFormat::RGB565:
      c = decode_rgb565(rd_be16(p));
      break;
    case TlutFormat::RGB5A3:
      c = decode_rgb5a3(rd_be16(p));
      break;
    default:
      return {};
    }
    put(out, e, c);
  }
  return out;
}

std::vector<std::uint8_t> decode_ci(std::uint32_t format, std::uint32_t width,
                                    std::uint32_t height,
                                    const std::uint8_t* data, std::size_t size,
                                    std::uint32_t tlut_format,
                                    std::uint32_t tlut_entries,
                                    const std::uint8_t* tlut_data,
                                    std::size_t tlut_size) {
  if (width == 0 || height == 0 || data == nullptr)
    return {};
  std::vector<std::uint16_t> indices;
  if (!decode_ci_indices(format, width, height, data, size, indices))
    return {};
  const std::vector<std::uint8_t> palette =
      decode_tlut(tlut_format, tlut_entries, tlut_data, tlut_size);
  if (palette.empty())
    return {};
  std::vector<std::uint8_t> out(static_cast<std::size_t>(width) * height * 4u,
                                0);
  for (std::size_t i = 0; i < indices.size(); ++i) {
    const std::uint16_t idx = indices[i];
    if (idx >= tlut_entries) {
      put(out, i, {0, 0, 0, 0}); // out-of-range -> transparent black
      continue;
    }
    std::memcpy(out.data() + i * 4u, palette.data() + idx * 4u, 4u);
  }
  return out;
}

} // namespace gxruntime::gxcore
