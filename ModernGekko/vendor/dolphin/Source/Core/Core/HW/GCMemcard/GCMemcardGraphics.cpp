// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/GCMemcard/GCMemcard.h"
#include "Common/ColorUtil.h"
#include <cstring>

namespace Memcard
{

std::optional<std::vector<u32>> GCMemcard::ReadBannerRGBA8(u8 index) const
{
  if (!m_valid || index >= DIRLEN)
    return std::nullopt;

  const u32 offset = GetActiveDirectory().m_dir_entries[index].m_image_offset;
  if (offset == 0xFFFFFFFF)
    return std::nullopt;

  // See comment on m_banner_and_icon_flags for an explanation of these.
  const u8 flags = GetActiveDirectory().m_dir_entries[index].m_banner_and_icon_flags;
  const u8 format = (flags & 0b0000'0011);
  if (format != MEMORY_CARD_BANNER_FORMAT_CI8 && format != MEMORY_CARD_BANNER_FORMAT_RGB5A3)
    return std::nullopt;

  constexpr u32 pixel_count = MEMORY_CARD_BANNER_WIDTH * MEMORY_CARD_BANNER_HEIGHT;
  const size_t total_bytes = format == MEMORY_CARD_BANNER_FORMAT_CI8 ?
                                 (pixel_count + MEMORY_CARD_CI8_PALETTE_ENTRIES * 2) :
                                 (pixel_count * 2);
  const auto data = GetSaveDataBytes(index, offset, total_bytes);
  if (!data || data->size() != total_bytes)
    return std::nullopt;

  std::vector<u32> rgba(pixel_count);
  if (format == MEMORY_CARD_BANNER_FORMAT_CI8)
  {
    const u8* pxdata = data->data();
    std::array<u16, MEMORY_CARD_CI8_PALETTE_ENTRIES> paldata;
    std::memcpy(paldata.data(), data->data() + pixel_count, MEMORY_CARD_CI8_PALETTE_ENTRIES * 2);
    Common::DecodeCI8Image(rgba.data(), pxdata, paldata.data(), MEMORY_CARD_BANNER_WIDTH,
                           MEMORY_CARD_BANNER_HEIGHT);
  }
  else
  {
    std::array<u16, pixel_count> pxdata;
    std::memcpy(pxdata.data(), data->data(), pixel_count * 2);
    Common::Decode5A3Image(rgba.data(), pxdata.data(), MEMORY_CARD_BANNER_WIDTH,
                           MEMORY_CARD_BANNER_HEIGHT);
  }

  return rgba;
}

std::optional<std::vector<GCMemcardAnimationFrameRGBA8>> GCMemcard::ReadAnimRGBA8(u8 index) const
{
  if (!m_valid || index >= DIRLEN)
    return std::nullopt;

  u32 image_offset = GetActiveDirectory().m_dir_entries[index].m_image_offset;
  if (image_offset == 0xFFFFFFFF)
    return std::nullopt;

  // Data at m_image_offset stores first the banner, if any, and then the icon data.
  // Skip over the banner if there is one.
  // See ReadBannerRGBA8() for details on how the banner is stored.
  const u8 flags = GetActiveDirectory().m_dir_entries[index].m_banner_and_icon_flags;
  const u8 banner_format = (flags & 0b0000'0011);
  const u32 banner_pixels = MEMORY_CARD_BANNER_WIDTH * MEMORY_CARD_BANNER_HEIGHT;
  if (banner_format == MEMORY_CARD_BANNER_FORMAT_CI8)
    image_offset += banner_pixels + MEMORY_CARD_CI8_PALETTE_ENTRIES * 2;
  else if (banner_format == MEMORY_CARD_BANNER_FORMAT_RGB5A3)
    image_offset += banner_pixels * 2;

  // decode icon formats and frame delays
  const u16 icon_format = GetActiveDirectory().m_dir_entries[index].m_icon_format;
  const u16 animation_speed = GetActiveDirectory().m_dir_entries[index].m_animation_speed;
  std::array<u8, MEMORY_CARD_ICON_ANIMATION_MAX_FRAMES> frame_formats;
  std::array<u8, MEMORY_CARD_ICON_ANIMATION_MAX_FRAMES> frame_delays;
  for (u32 i = 0; i < MEMORY_CARD_ICON_ANIMATION_MAX_FRAMES; ++i)
  {
    frame_formats[i] = (icon_format >> (2 * i)) & 0b11;
    frame_delays[i] = (animation_speed >> (2 * i)) & 0b11;
  }

  // if first frame format is 0, the entire icon is skipped
  if (frame_formats[0] == 0)
    return std::nullopt;

  // calculate byte length of each individual icon frame and full icon data
  constexpr u32 pixels_per_frame = MEMORY_CARD_ICON_WIDTH * MEMORY_CARD_ICON_HEIGHT;
  u32 data_length = 0;
  u32 frame_count = 0;
  std::array<u32, MEMORY_CARD_ICON_ANIMATION_MAX_FRAMES> frame_offsets;
  bool has_shared_palette = false;
  for (u32 i = 0; i < MEMORY_CARD_ICON_ANIMATION_MAX_FRAMES; ++i)
  {
    if (frame_delays[i] == 0)
    {
      // frame delay of 0 means we're out of frames
      break;
    }

    // otherwise this counts as a frame, even if the format is none of the three valid ones
    // (see the actual icon decoding below for how that is handled)
    ++frame_count;
    frame_offsets[i] = data_length;

    if (frame_formats[i] == MEMORY_CARD_ICON_FORMAT_CI8_SHARED_PALETTE)
    {
      data_length += pixels_per_frame;
      has_shared_palette = true;
    }
    else if (frame_formats[i] == MEMORY_CARD_ICON_FORMAT_RGB5A3)
    {
      data_length += pixels_per_frame * 2;
    }
    else if (frame_formats[i] == MEMORY_CARD_ICON_FORMAT_CI8_UNIQUE_PALETTE)
    {
      data_length += pixels_per_frame + 2 * MEMORY_CARD_CI8_PALETTE_ENTRIES;
    }
  }

  if (frame_count == 0)
    return std::nullopt;

  const u32 shared_palette_offset = data_length;
  if (has_shared_palette)
    data_length += 2 * MEMORY_CARD_CI8_PALETTE_ENTRIES;

  // now that we have determined the data length, fetch the actual data from the save file
  // if anything is sketchy, bail so we don't access out of bounds
  const auto save_data_bytes = GetSaveDataBytes(index, image_offset, data_length);
  if (!save_data_bytes || save_data_bytes->size() != data_length)
    return std::nullopt;

  // and finally, decode icons into RGBA8
  std::array<u16, MEMORY_CARD_CI8_PALETTE_ENTRIES> shared_palette;
  if (has_shared_palette)
  {
    std::memcpy(shared_palette.data(), save_data_bytes->data() + shared_palette_offset,
                2 * MEMORY_CARD_CI8_PALETTE_ENTRIES);
  }

  std::vector<GCMemcardAnimationFrameRGBA8> output;
  for (u32 i = 0; i < frame_count; ++i)
  {
    GCMemcardAnimationFrameRGBA8& output_frame = output.emplace_back();
    output_frame.image_data.resize(pixels_per_frame);
    output_frame.delay = frame_delays[i];

    for (u32 j = i; j < frame_count; ++j)
    {
      if (frame_formats[j] == MEMORY_CARD_ICON_FORMAT_CI8_SHARED_PALETTE)
      {
        Common::DecodeCI8Image(output_frame.image_data.data(),
                               save_data_bytes->data() + frame_offsets[j], shared_palette.data(),
                               MEMORY_CARD_ICON_WIDTH, MEMORY_CARD_ICON_HEIGHT);
        break;
      }

      if (frame_formats[j] == MEMORY_CARD_ICON_FORMAT_RGB5A3)
      {
        std::array<u16, pixels_per_frame> pxdata;
        std::memcpy(pxdata.data(), save_data_bytes->data() + frame_offsets[j],
                    pixels_per_frame * 2);
        Common::Decode5A3Image(output_frame.image_data.data(), pxdata.data(),
                               MEMORY_CARD_ICON_WIDTH, MEMORY_CARD_ICON_HEIGHT);
        break;
      }

      if (frame_formats[j] == MEMORY_CARD_ICON_FORMAT_CI8_UNIQUE_PALETTE)
      {
        std::array<u16, MEMORY_CARD_CI8_PALETTE_ENTRIES> paldata;
        std::memcpy(paldata.data(), save_data_bytes->data() + frame_offsets[j] + pixels_per_frame,
                    MEMORY_CARD_CI8_PALETTE_ENTRIES * 2);
        Common::DecodeCI8Image(output_frame.image_data.data(),
                               save_data_bytes->data() + frame_offsets[j], paldata.data(),
                               MEMORY_CARD_ICON_WIDTH, MEMORY_CARD_ICON_HEIGHT);
        break;
      }
    }
  }

  return output;
}

}  // namespace Memcard
