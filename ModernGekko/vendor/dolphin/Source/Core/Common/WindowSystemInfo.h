// Copyright 2018 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <atomic>
#include <cstdint>
#include <memory>
#include <utility>

enum class WindowSystemType
{
  Headless,
  Windows,
  MacOS,
  Android,
  X11,
  Wayland,
  FBDev,
  Haiku,
};

// Thread-safe dimensions supplied by window systems where the application
// chooses the render-surface extent (most notably Wayland Vulkan). The state
// is shared because WindowSystemInfo is copied into the video backend while
// the platform continues receiving resize events on another thread.
class RenderSurfaceSize final
{
public:
  RenderSurfaceSize() = default;
  RenderSurfaceSize(std::uint32_t width, std::uint32_t height) { Set(width, height); }

  void Set(std::uint32_t width, std::uint32_t height)
  {
    const std::uint64_t packed = (static_cast<std::uint64_t>(width) << 32) | height;
    m_packed.store(packed, std::memory_order_release);
  }

  std::pair<std::uint32_t, std::uint32_t> Get() const
  {
    const std::uint64_t packed = m_packed.load(std::memory_order_acquire);
    return {static_cast<std::uint32_t>(packed >> 32), static_cast<std::uint32_t>(packed)};
  }

private:
  std::atomic<std::uint64_t> m_packed{0};
};

struct WindowSystemInfo
{
  WindowSystemInfo() = default;
  WindowSystemInfo(WindowSystemType type_, void* display_connection_, void* render_window_,
                   void* render_surface_)
      : type(type_), display_connection(display_connection_), render_window(render_window_),
        render_surface(render_surface_)
  {
  }

  // Window system type. Determines which GL context or Vulkan WSI is used.
  WindowSystemType type = WindowSystemType::Headless;

  // Connection to a display server. This is used on X11 and Wayland platforms.
  void* display_connection = nullptr;

  // Render window. This is a pointer to the native window handle, which depends
  // on the platform. e.g. HWND for Windows, Window for X11. If the surface is
  // set to nullptr, the video backend will run in headless mode.
  void* render_window = nullptr;

  // Render surface. Depending on the host platform, this may differ from the window.
  // This is kept separate as input may require a different handle to rendering, and
  // during video backend startup the surface pointer may change (MoltenVK).
  void* render_surface = nullptr;

  // Scale of the render surface. For hidpi systems, this will be >1.
  float render_surface_scale = 1.0f;

  // Live client-selected surface dimensions. Fixed-extent window systems can
  // leave this empty and let their graphics API report the current extent.
  std::shared_ptr<RenderSurfaceSize> render_surface_size;
};
