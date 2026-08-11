#pragma once

#include <cstdint>

// GXRuntime recomp patch (0006): one-shot CPU readback of the frame's
// present source, for deterministic pixel replay (dolgx_replay --pixels).
// Upstream remedy: a public aurora framebuffer readback API.
namespace aurora::gfx::efb_readback {

// Arm a readback of the next submitted frame. Any thread.
void request() noexcept;

// Copy the frame's present source into a readback buffer and start the map.
// Render worker only, after the frame's queue submit.
void after_submit() noexcept;

// True once a readback completed; returns tightly packed RGBA8 rows
// (top-left origin). Consumes the result; the pointer stays valid until the
// next readback completes. Any thread.
bool take(const std::uint8_t** rgba, std::uint32_t* width,
          std::uint32_t* height) noexcept;

} // namespace aurora::gfx::efb_readback
