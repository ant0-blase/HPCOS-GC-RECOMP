// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

// gxcore texture decode — std-only, headless, Dolphin-conformant.
//
// Ports the pure decode math from the fork substrate codec
// (graphics/aurora/lib/gfx/texture_convert.cpp), which is bit-identical to
// Dolphin's TextureDecoder_Generic (verified DXTBlend==S3TCBlend,
// Convert*To8==ExpandTo8, IA8 native-read, RGB565/RGB5A3/C14X2/CMPR bswap).
// Reproduced here so the --core texture path is headless-testable and does not
// couple gxcore to wgpu types. Multi-byte guest source reads are made explicit
// (little/big-endian) so the result is host-endianness independent.
//
// Single mip only (the --core path uploads mip 0). CI formats (C4/C8/C14X2)
// need a TLUT and go through decode_ci; every other format goes through
// decode_texture. Both return tightly-packed RGBA8 (width*height*4 bytes).

#include <cstddef>
#include <cstdint>
#include <vector>

namespace gxruntime::gxcore {

// GX texture format (GXTexFmt): the raw BP image format nibble.
enum class TexFormat : std::uint32_t {
  I4 = 0x0,
  I8 = 0x1,
  IA4 = 0x2,
  IA8 = 0x3,
  RGB565 = 0x4,
  RGB5A3 = 0x5,
  RGBA8 = 0x6,
  C4 = 0x8,
  C8 = 0x9,
  C14X2 = 0xA,
  CMPR = 0xE,
};

// TLUT palette format (GXTlutFmt): IA8=0, RGB565=1, RGB5A3=2.
enum class TlutFormat : std::uint32_t {
  IA8 = 0,
  RGB565 = 1,
  RGB5A3 = 2,
};

bool is_ci_format(std::uint32_t format);

// Decode a direct (non-CI) GX texture to RGBA8. Returns empty on unsupported
// format or short input. `size` bounds the readable source bytes.
std::vector<std::uint8_t> decode_texture(std::uint32_t format,
                                         std::uint32_t width,
                                         std::uint32_t height,
                                         const std::uint8_t* data,
                                         std::size_t size);

// Decode a TLUT palette (`entries` palette entries) to RGBA8 (entries*4 bytes).
std::vector<std::uint8_t> decode_tlut(std::uint32_t tlut_format,
                                      std::uint32_t entries,
                                      const std::uint8_t* data,
                                      std::size_t size);

// Decode a CI texture (C4/C8/C14X2) through its TLUT to RGBA8. Palette indices
// >= `tlut_entries` decode to transparent black (Dolphin/fork semantics).
std::vector<std::uint8_t> decode_ci(std::uint32_t format, std::uint32_t width,
                                    std::uint32_t height,
                                    const std::uint8_t* data, std::size_t size,
                                    std::uint32_t tlut_format,
                                    std::uint32_t tlut_entries,
                                    const std::uint8_t* tlut_data,
                                    std::size_t tlut_size);

} // namespace gxruntime::gxcore
