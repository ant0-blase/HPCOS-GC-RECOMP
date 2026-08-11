// Copyright 2026 ModernGekko Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "DolphinNoGUI/Platform.h"

#include <algorithm>
#include <cerrno>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <optional>
#include <poll.h>
#include <string>
#include <sys/mman.h>
#include <thread>
#include <unistd.h>

#include <wayland-client.h>
#include <wayland-cursor.h>
#include <xkbcommon/xkbcommon-keysyms.h>
#include <xkbcommon/xkbcommon-names.h>
#include <xkbcommon/xkbcommon.h>

#include "idle-inhibit-unstable-v1-client-protocol.h"
#include "xdg-decoration-client-protocol.h"
#include "xdg-shell-client-protocol.h"

#include "Core/Config/MainSettings.h"
#include "Core/Core.h"
#include "Core/State.h"
#include "Core/System.h"
#include "UICommon/UICommon.h"
#include "VideoCommon/Present.h"

namespace
{
class PlatformWayland final : public Platform
{
public:
  ~PlatformWayland() override;

  bool Init() override;
  void SetTitle(const std::string& title) override;
  void MainLoop() override;
  void SaveWindowGeometry() override;
  WindowSystemInfo GetWindowSystemInfo() const override;

  static void RegistryGlobal(void* data, wl_registry* registry, uint32_t name,
                             const char* interface, uint32_t version);
  static void RegistryGlobalRemove(void*, wl_registry*, uint32_t) {}
  static void WmBasePing(void*, xdg_wm_base* wm_base, uint32_t serial);
  static void SurfaceConfigure(void* data, xdg_surface* surface, uint32_t serial);
  static void ToplevelConfigure(void* data, xdg_toplevel*, int32_t width, int32_t height,
                                wl_array* states);
  static void ToplevelClose(void* data, xdg_toplevel*);
  static void ToplevelConfigureBounds(void*, xdg_toplevel*, int32_t, int32_t) {}
  static void ToplevelWmCapabilities(void*, xdg_toplevel*, wl_array*) {}

  static void SeatCapabilities(void* data, wl_seat* seat, uint32_t capabilities);
  static void SeatName(void*, wl_seat*, const char*) {}
  static void KeyboardKeymap(void* data, wl_keyboard*, uint32_t format, int32_t fd,
                             uint32_t size);
  static void KeyboardEnter(void* data, wl_keyboard*, uint32_t, wl_surface* surface, wl_array*);
  static void KeyboardLeave(void* data, wl_keyboard*, uint32_t, wl_surface* surface);
  static void KeyboardKey(void* data, wl_keyboard*, uint32_t, uint32_t, uint32_t key,
                          uint32_t state);
  static void KeyboardModifiers(void* data, wl_keyboard*, uint32_t, uint32_t depressed,
                                uint32_t latched, uint32_t locked, uint32_t group);
  static void KeyboardRepeatInfo(void*, wl_keyboard*, int32_t, int32_t) {}

  static void PointerEnter(void* data, wl_pointer*, uint32_t serial, wl_surface* surface,
                           wl_fixed_t, wl_fixed_t);
  static void PointerLeave(void* data, wl_pointer*, uint32_t, wl_surface* surface);
  static void PointerMotion(void*, wl_pointer*, uint32_t, wl_fixed_t, wl_fixed_t) {}
  static void PointerButton(void*, wl_pointer*, uint32_t, uint32_t, uint32_t, uint32_t) {}
  static void PointerAxis(void*, wl_pointer*, uint32_t, uint32_t, wl_fixed_t) {}
  static void PointerFrame(void*, wl_pointer*) {}
  static void PointerAxisSource(void*, wl_pointer*, uint32_t) {}
  static void PointerAxisStop(void*, wl_pointer*, uint32_t, uint32_t) {}
  static void PointerAxisDiscrete(void*, wl_pointer*, uint32_t, int32_t) {}
  static void PointerAxisValue120(void*, wl_pointer*, uint32_t, int32_t) {}
  static void PointerAxisRelativeDirection(void*, wl_pointer*, uint32_t, uint32_t) {}

private:
  void ApplyPendingTitle();
  bool DispatchEvents();
  void HandleHotkey(xkb_keysym_t symbol);
  bool ModifierActive(const char* name) const;
  void UpdateCursor();
  void DestroyKeyboard();
  void DestroyPointer();

  wl_display* m_display = nullptr;
  wl_registry* m_registry = nullptr;
  wl_compositor* m_compositor = nullptr;
  wl_shm* m_shm = nullptr;
  wl_seat* m_seat = nullptr;
  wl_keyboard* m_keyboard = nullptr;
  wl_pointer* m_pointer = nullptr;
  xdg_wm_base* m_wm_base = nullptr;
  zxdg_decoration_manager_v1* m_decoration_manager = nullptr;
  zwp_idle_inhibit_manager_v1* m_idle_inhibit_manager = nullptr;
  zwp_idle_inhibitor_v1* m_idle_inhibitor = nullptr;
  wl_surface* m_surface = nullptr;
  xdg_surface* m_xdg_surface = nullptr;
  xdg_toplevel* m_toplevel = nullptr;
  zxdg_toplevel_decoration_v1* m_toplevel_decoration = nullptr;

  xkb_context* m_xkb_context = nullptr;
  xkb_keymap* m_xkb_keymap = nullptr;
  xkb_state* m_xkb_state = nullptr;
  wl_cursor_theme* m_cursor_theme = nullptr;
  wl_cursor* m_default_cursor = nullptr;
  wl_surface* m_cursor_surface = nullptr;
  uint32_t m_pointer_serial = 0;
  bool m_pointer_inside = false;

  std::thread::id m_owner_thread;
  std::mutex m_title_mutex;
  std::optional<std::string> m_pending_title;
  bool m_configured = false;
  bool m_resize_pending = false;
  bool m_screensaver_inhibited = false;
  int32_t m_width = std::max(Config::Get(Config::MAIN_RENDER_WINDOW_WIDTH), 1);
  int32_t m_height = std::max(Config::Get(Config::MAIN_RENDER_WINDOW_HEIGHT), 1);
  int32_t m_pending_width = m_width;
  int32_t m_pending_height = m_height;
};

constexpr wl_registry_listener s_registry_listener = {PlatformWayland::RegistryGlobal,
                                                       PlatformWayland::RegistryGlobalRemove};
constexpr xdg_wm_base_listener s_wm_base_listener = {PlatformWayland::WmBasePing};
constexpr xdg_surface_listener s_surface_listener = {PlatformWayland::SurfaceConfigure};
constexpr xdg_toplevel_listener s_toplevel_listener = {
    PlatformWayland::ToplevelConfigure, PlatformWayland::ToplevelClose,
    PlatformWayland::ToplevelConfigureBounds, PlatformWayland::ToplevelWmCapabilities};
constexpr wl_seat_listener s_seat_listener = {PlatformWayland::SeatCapabilities,
                                              PlatformWayland::SeatName};
constexpr wl_keyboard_listener s_keyboard_listener = {
    PlatformWayland::KeyboardKeymap, PlatformWayland::KeyboardEnter,
    PlatformWayland::KeyboardLeave, PlatformWayland::KeyboardKey,
    PlatformWayland::KeyboardModifiers, PlatformWayland::KeyboardRepeatInfo};
constexpr wl_pointer_listener s_pointer_listener = {
    PlatformWayland::PointerEnter,
    PlatformWayland::PointerLeave,
    PlatformWayland::PointerMotion,
    PlatformWayland::PointerButton,
    PlatformWayland::PointerAxis,
    PlatformWayland::PointerFrame,
    PlatformWayland::PointerAxisSource,
    PlatformWayland::PointerAxisStop,
    PlatformWayland::PointerAxisDiscrete,
    PlatformWayland::PointerAxisValue120,
    PlatformWayland::PointerAxisRelativeDirection,
};

PlatformWayland::~PlatformWayland()
{
  if (m_screensaver_inhibited)
    UICommon::InhibitScreenSaver(false);
  if (m_idle_inhibitor)
    zwp_idle_inhibitor_v1_destroy(m_idle_inhibitor);
  if (m_toplevel_decoration)
    zxdg_toplevel_decoration_v1_destroy(m_toplevel_decoration);
  if (m_toplevel)
    xdg_toplevel_destroy(m_toplevel);
  if (m_xdg_surface)
    xdg_surface_destroy(m_xdg_surface);
  DestroyPointer();
  DestroyKeyboard();
  if (m_cursor_surface)
    wl_surface_destroy(m_cursor_surface);
  if (m_cursor_theme)
    wl_cursor_theme_destroy(m_cursor_theme);
  if (m_xkb_context)
    xkb_context_unref(m_xkb_context);
  if (m_surface)
    wl_surface_destroy(m_surface);
  if (m_seat)
  {
    if (wl_seat_get_version(m_seat) >= WL_SEAT_RELEASE_SINCE_VERSION)
      wl_seat_release(m_seat);
    else
      wl_seat_destroy(m_seat);
  }
  if (m_wm_base)
    xdg_wm_base_destroy(m_wm_base);
  if (m_idle_inhibit_manager)
    zwp_idle_inhibit_manager_v1_destroy(m_idle_inhibit_manager);
  if (m_decoration_manager)
    zxdg_decoration_manager_v1_destroy(m_decoration_manager);
  if (m_shm)
    wl_shm_destroy(m_shm);
  if (m_compositor)
    wl_compositor_destroy(m_compositor);
  if (m_registry)
    wl_registry_destroy(m_registry);
  if (m_display)
  {
    wl_display_flush(m_display);
    wl_display_disconnect(m_display);
  }
}

bool PlatformWayland::Init()
{
  m_owner_thread = std::this_thread::get_id();
  m_xkb_context = xkb_context_new(XKB_CONTEXT_NO_FLAGS);
  m_display = wl_display_connect(nullptr);
  if (!m_display)
    return false;

  m_registry = wl_display_get_registry(m_display);
  wl_registry_add_listener(m_registry, &s_registry_listener, this);
  if (wl_display_roundtrip(m_display) < 0 || !m_compositor || !m_wm_base)
    return false;

  xdg_wm_base_add_listener(m_wm_base, &s_wm_base_listener, this);
  m_surface = wl_compositor_create_surface(m_compositor);
  if (!m_surface)
    return false;

  m_xdg_surface = xdg_wm_base_get_xdg_surface(m_wm_base, m_surface);
  if (!m_xdg_surface)
    return false;

  m_toplevel = xdg_surface_get_toplevel(m_xdg_surface);
  if (!m_toplevel)
    return false;

  if (m_decoration_manager)
  {
    m_toplevel_decoration =
        zxdg_decoration_manager_v1_get_toplevel_decoration(m_decoration_manager, m_toplevel);
    if (m_toplevel_decoration)
    {
      zxdg_toplevel_decoration_v1_set_mode(
          m_toplevel_decoration, ZXDG_TOPLEVEL_DECORATION_V1_MODE_SERVER_SIDE);
    }
  }

  if (m_shm)
  {
    int cursor_size = 24;
    if (const char* size = std::getenv("XCURSOR_SIZE"))
      cursor_size = std::clamp(std::atoi(size), 1, 256);
    m_cursor_theme = wl_cursor_theme_load(std::getenv("XCURSOR_THEME"), cursor_size, m_shm);
    if (m_cursor_theme)
    {
      m_default_cursor = wl_cursor_theme_get_cursor(m_cursor_theme, "default");
      if (!m_default_cursor)
        m_default_cursor = wl_cursor_theme_get_cursor(m_cursor_theme, "left_ptr");
      m_cursor_surface = wl_compositor_create_surface(m_compositor);
    }
  }

  if (Config::Get(Config::MAIN_DISABLE_SCREENSAVER))
  {
    if (m_idle_inhibit_manager)
      m_idle_inhibitor =
          zwp_idle_inhibit_manager_v1_create_inhibitor(m_idle_inhibit_manager, m_surface);
    UICommon::InhibitScreenSaver(true);
    m_screensaver_inhibited = true;
  }

  xdg_surface_add_listener(m_xdg_surface, &s_surface_listener, this);
  xdg_toplevel_add_listener(m_toplevel, &s_toplevel_listener, this);
  xdg_toplevel_set_app_id(m_toplevel, "org.moderngekko.Runner");
  xdg_toplevel_set_title(m_toplevel, "ModernGekko");
  xdg_surface_set_window_geometry(m_xdg_surface, 0, 0, m_width, m_height);
  if (Config::Get(Config::MAIN_FULLSCREEN))
  {
    xdg_toplevel_set_fullscreen(m_toplevel, nullptr);
    m_window_fullscreen = true;
  }
  wl_surface_commit(m_surface);

  while (!m_configured)
  {
    if (wl_display_dispatch(m_display) < 0)
      return false;
  }
  return wl_display_flush(m_display) >= 0 || errno == EAGAIN;
}

void PlatformWayland::SetTitle(const std::string& title)
{
  if (std::this_thread::get_id() == m_owner_thread && m_toplevel)
  {
    xdg_toplevel_set_title(m_toplevel, title.c_str());
    wl_surface_commit(m_surface);
    wl_display_flush(m_display);
    return;
  }

  std::lock_guard lock(m_title_mutex);
  m_pending_title = title;
}

void PlatformWayland::ApplyPendingTitle()
{
  std::optional<std::string> title;
  {
    std::lock_guard lock(m_title_mutex);
    title.swap(m_pending_title);
  }
  if (title && m_toplevel)
  {
    xdg_toplevel_set_title(m_toplevel, title->c_str());
    wl_surface_commit(m_surface);
  }
}

void PlatformWayland::MainLoop()
{
  while (IsRunning())
  {
    UpdateRunningFlag();
    Core::HostDispatchJobs(Core::System::GetInstance());
    ApplyPendingTitle();
    if (!DispatchEvents())
      break;
  }
}

bool PlatformWayland::DispatchEvents()
{
  while (wl_display_prepare_read(m_display) != 0)
  {
    if (wl_display_dispatch_pending(m_display) < 0)
      return false;
  }

  short events = POLLIN;
  if (wl_display_flush(m_display) < 0)
  {
    if (errno != EAGAIN)
    {
      wl_display_cancel_read(m_display);
      return false;
    }
    events |= POLLOUT;
  }

  pollfd display_fd{wl_display_get_fd(m_display), events, 0};
  const int result = poll(&display_fd, 1, 2);
  if (result < 0)
  {
    wl_display_cancel_read(m_display);
    return errno == EINTR;
  }
  if (result == 0)
  {
    wl_display_cancel_read(m_display);
    return true;
  }
  if (display_fd.revents & (POLLERR | POLLHUP | POLLNVAL))
  {
    wl_display_cancel_read(m_display);
    return false;
  }

  if (display_fd.revents & POLLIN)
  {
    if (wl_display_read_events(m_display) < 0)
      return false;
  }
  else
  {
    wl_display_cancel_read(m_display);
  }

  if ((display_fd.revents & POLLOUT) && wl_display_flush(m_display) < 0 && errno != EAGAIN)
    return false;
  return wl_display_dispatch_pending(m_display) >= 0;
}

void PlatformWayland::SaveWindowGeometry()
{
  if (m_window_fullscreen)
    return;
  Config::SetBase(Config::MAIN_RENDER_WINDOW_WIDTH, m_width);
  Config::SetBase(Config::MAIN_RENDER_WINDOW_HEIGHT, m_height);
}

WindowSystemInfo PlatformWayland::GetWindowSystemInfo() const
{
  return {WindowSystemType::Wayland, m_display, m_surface, m_surface};
}

void PlatformWayland::RegistryGlobal(void* data, wl_registry* registry, uint32_t name,
                                     const char* interface, uint32_t version)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if (std::strcmp(interface, wl_compositor_interface.name) == 0)
  {
    platform->m_compositor = static_cast<wl_compositor*>(
        wl_registry_bind(registry, name, &wl_compositor_interface, std::min(version, 6u)));
  }
  else if (std::strcmp(interface, wl_shm_interface.name) == 0)
  {
    platform->m_shm =
        static_cast<wl_shm*>(wl_registry_bind(registry, name, &wl_shm_interface, 1));
  }
  else if (std::strcmp(interface, wl_seat_interface.name) == 0 && !platform->m_seat)
  {
    platform->m_seat = static_cast<wl_seat*>(
        wl_registry_bind(registry, name, &wl_seat_interface, std::min(version, 9u)));
    wl_seat_add_listener(platform->m_seat, &s_seat_listener, platform);
  }
  else if (std::strcmp(interface, xdg_wm_base_interface.name) == 0)
  {
    platform->m_wm_base = static_cast<xdg_wm_base*>(
        wl_registry_bind(registry, name, &xdg_wm_base_interface, std::min(version, 6u)));
  }
  else if (std::strcmp(interface, zxdg_decoration_manager_v1_interface.name) == 0)
  {
    platform->m_decoration_manager = static_cast<zxdg_decoration_manager_v1*>(wl_registry_bind(
        registry, name, &zxdg_decoration_manager_v1_interface, std::min(version, 1u)));
  }
  else if (std::strcmp(interface, zwp_idle_inhibit_manager_v1_interface.name) == 0)
  {
    platform->m_idle_inhibit_manager = static_cast<zwp_idle_inhibit_manager_v1*>(wl_registry_bind(
        registry, name, &zwp_idle_inhibit_manager_v1_interface, std::min(version, 1u)));
  }
}

void PlatformWayland::WmBasePing(void*, xdg_wm_base* wm_base, uint32_t serial)
{
  xdg_wm_base_pong(wm_base, serial);
}

void PlatformWayland::SurfaceConfigure(void* data, xdg_surface* surface, uint32_t serial)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  xdg_surface_ack_configure(surface, serial);
  if (platform->m_resize_pending)
  {
    platform->m_width = platform->m_pending_width;
    platform->m_height = platform->m_pending_height;
    xdg_surface_set_window_geometry(platform->m_xdg_surface, 0, 0, platform->m_width,
                                    platform->m_height);
    platform->m_resize_pending = false;
    if (g_presenter)
      g_presenter->ResizeSurface();
  }
  platform->m_configured = true;
}

void PlatformWayland::ToplevelConfigure(void* data, xdg_toplevel*, int32_t width, int32_t height,
                                        wl_array* states)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  bool fullscreen = false;
  const auto* state = static_cast<const uint32_t*>(states->data);
  const size_t state_count = states->size / sizeof(*state);
  for (size_t i = 0; i < state_count; ++i)
  {
    if (state[i] == XDG_TOPLEVEL_STATE_FULLSCREEN)
      fullscreen = true;
  }
  platform->m_window_fullscreen = fullscreen;

  if (width > 0 && height > 0 &&
      (width != platform->m_width || height != platform->m_height))
  {
    platform->m_pending_width = width;
    platform->m_pending_height = height;
    platform->m_resize_pending = true;
  }
}

void PlatformWayland::ToplevelClose(void* data, xdg_toplevel*)
{
  static_cast<PlatformWayland*>(data)->Stop();
}

void PlatformWayland::SeatCapabilities(void* data, wl_seat* seat, uint32_t capabilities)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if ((capabilities & WL_SEAT_CAPABILITY_KEYBOARD) && !platform->m_keyboard)
  {
    platform->m_keyboard = wl_seat_get_keyboard(seat);
    wl_keyboard_add_listener(platform->m_keyboard, &s_keyboard_listener, platform);
  }
  else if (!(capabilities & WL_SEAT_CAPABILITY_KEYBOARD) && platform->m_keyboard)
  {
    platform->DestroyKeyboard();
  }

  if ((capabilities & WL_SEAT_CAPABILITY_POINTER) && !platform->m_pointer)
  {
    platform->m_pointer = wl_seat_get_pointer(seat);
    wl_pointer_add_listener(platform->m_pointer, &s_pointer_listener, platform);
  }
  else if (!(capabilities & WL_SEAT_CAPABILITY_POINTER) && platform->m_pointer)
  {
    platform->DestroyPointer();
  }
}

void PlatformWayland::DestroyKeyboard()
{
  if (m_xkb_state)
    xkb_state_unref(m_xkb_state);
  if (m_xkb_keymap)
    xkb_keymap_unref(m_xkb_keymap);
  m_xkb_state = nullptr;
  m_xkb_keymap = nullptr;
  if (m_keyboard)
  {
    if (wl_keyboard_get_version(m_keyboard) >= WL_KEYBOARD_RELEASE_SINCE_VERSION)
      wl_keyboard_release(m_keyboard);
    else
      wl_keyboard_destroy(m_keyboard);
    m_keyboard = nullptr;
  }
}

void PlatformWayland::DestroyPointer()
{
  if (m_pointer)
  {
    if (wl_pointer_get_version(m_pointer) >= WL_POINTER_RELEASE_SINCE_VERSION)
      wl_pointer_release(m_pointer);
    else
      wl_pointer_destroy(m_pointer);
    m_pointer = nullptr;
  }
  m_pointer_inside = false;
}

void PlatformWayland::KeyboardKeymap(void* data, wl_keyboard*, uint32_t format, int32_t fd,
                                     uint32_t size)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if (format != WL_KEYBOARD_KEYMAP_FORMAT_XKB_V1 || !platform->m_xkb_context)
  {
    close(fd);
    return;
  }

  void* mapping = mmap(nullptr, size, PROT_READ, MAP_PRIVATE, fd, 0);
  close(fd);
  if (mapping == MAP_FAILED)
    return;

  xkb_keymap* keymap = xkb_keymap_new_from_string(
      platform->m_xkb_context, static_cast<const char*>(mapping), XKB_KEYMAP_FORMAT_TEXT_V1,
      XKB_KEYMAP_COMPILE_NO_FLAGS);
  munmap(mapping, size);
  if (!keymap)
    return;

  xkb_state* state = xkb_state_new(keymap);
  if (!state)
  {
    xkb_keymap_unref(keymap);
    return;
  }

  if (platform->m_xkb_state)
    xkb_state_unref(platform->m_xkb_state);
  if (platform->m_xkb_keymap)
    xkb_keymap_unref(platform->m_xkb_keymap);
  platform->m_xkb_keymap = keymap;
  platform->m_xkb_state = state;
}

void PlatformWayland::KeyboardEnter(void* data, wl_keyboard*, uint32_t, wl_surface* surface,
                                    wl_array*)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if (surface == platform->m_surface)
  {
    platform->m_window_focus = true;
    platform->UpdateCursor();
  }
}

void PlatformWayland::KeyboardLeave(void* data, wl_keyboard*, uint32_t, wl_surface* surface)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if (surface == platform->m_surface)
  {
    platform->m_window_focus = false;
    platform->UpdateCursor();
  }
}

void PlatformWayland::KeyboardKey(void* data, wl_keyboard*, uint32_t, uint32_t, uint32_t key,
                                  uint32_t state)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if (state != WL_KEYBOARD_KEY_STATE_PRESSED || !platform->m_xkb_state)
    return;
  platform->HandleHotkey(xkb_state_key_get_one_sym(platform->m_xkb_state, key + 8));
}

void PlatformWayland::KeyboardModifiers(void* data, wl_keyboard*, uint32_t, uint32_t depressed,
                                        uint32_t latched, uint32_t locked, uint32_t group)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if (platform->m_xkb_state)
  {
    xkb_state_update_mask(platform->m_xkb_state, depressed, latched, locked, 0, 0, group);
  }
}

bool PlatformWayland::ModifierActive(const char* name) const
{
  return m_xkb_state &&
         xkb_state_mod_name_is_active(m_xkb_state, name, XKB_STATE_MODS_EFFECTIVE) > 0;
}

void PlatformWayland::HandleHotkey(xkb_keysym_t symbol)
{
  auto& system = Core::System::GetInstance();
  if (symbol == XKB_KEY_Escape && ModifierActive(XKB_MOD_NAME_CTRL))
  {
    RequestShutdown();
  }
  else if (symbol == XKB_KEY_F10)
  {
    const bool running = Core::GetState(system) == Core::State::Running;
    Core::SetState(system, running ? Core::State::Paused : Core::State::Running);
    UpdateCursor();
  }
  else if (symbol == XKB_KEY_Return && ModifierActive(XKB_MOD_NAME_ALT))
  {
    if (m_window_fullscreen)
      xdg_toplevel_unset_fullscreen(m_toplevel);
    else
      xdg_toplevel_set_fullscreen(m_toplevel, nullptr);
    m_window_fullscreen = !m_window_fullscreen;
    wl_surface_commit(m_surface);
  }
  else if (symbol >= XKB_KEY_F1 && symbol <= XKB_KEY_F8)
  {
    const int slot = static_cast<int>(symbol - XKB_KEY_F1) + 1;
    if (ModifierActive(XKB_MOD_NAME_SHIFT))
      State::Save(system, slot);
    else
      State::Load(system, slot);
  }
  else if (symbol == XKB_KEY_F9)
  {
    Core::SaveScreenShot();
  }
  else if (symbol == XKB_KEY_F11)
  {
    State::LoadLastSaved(system);
  }
  else if (symbol == XKB_KEY_F12)
  {
    if (ModifierActive(XKB_MOD_NAME_SHIFT))
      State::UndoLoadState(system);
    else
      State::UndoSaveState(system);
  }
}

void PlatformWayland::PointerEnter(void* data, wl_pointer*, uint32_t serial, wl_surface* surface,
                                   wl_fixed_t, wl_fixed_t)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if (surface == platform->m_surface)
  {
    platform->m_pointer_inside = true;
    platform->m_pointer_serial = serial;
    platform->UpdateCursor();
  }
}

void PlatformWayland::PointerLeave(void* data, wl_pointer*, uint32_t, wl_surface* surface)
{
  auto* platform = static_cast<PlatformWayland*>(data);
  if (surface == platform->m_surface)
    platform->m_pointer_inside = false;
}

void PlatformWayland::UpdateCursor()
{
  if (!m_pointer || !m_pointer_inside)
    return;

  const bool hide = m_window_focus &&
                    Config::Get(Config::MAIN_SHOW_CURSOR) == Config::ShowCursor::Never &&
                    Core::GetState(Core::System::GetInstance()) != Core::State::Paused;
  if (hide || !m_cursor_surface || !m_default_cursor || m_default_cursor->image_count == 0)
  {
    wl_pointer_set_cursor(m_pointer, m_pointer_serial, nullptr, 0, 0);
    return;
  }

  wl_cursor_image* image = m_default_cursor->images[0];
  wl_buffer* buffer = wl_cursor_image_get_buffer(image);
  if (!buffer)
    return;
  wl_pointer_set_cursor(m_pointer, m_pointer_serial, m_cursor_surface, image->hotspot_x,
                        image->hotspot_y);
  wl_surface_attach(m_cursor_surface, buffer, 0, 0);
  wl_surface_damage(m_cursor_surface, 0, 0, image->width, image->height);
  wl_surface_commit(m_cursor_surface);
}
}  // namespace

std::unique_ptr<Platform> Platform::CreateWaylandPlatform()
{
  return std::make_unique<PlatformWayland>();
}
