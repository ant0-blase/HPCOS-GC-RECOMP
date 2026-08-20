// Copyright 2018 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include <unistd.h>

// X.h defines None to be 0L, but other parts of Dolphin undef that so that
// None can be used in enums.  Work around that here by copying the definition
// before it is undefined.
#include <X11/X.h>
static constexpr auto X_None = None;

#include "DolphinNoGUI/Platform.h"

#include "Common/MsgHandler.h"
#include "Core/Config/MainSettings.h"
#include "Core/Core.h"
#include "Core/HPCOSSettings.h"
#include "Core/State.h"
#include "Core/System.h"

#include <algorithm>
#include <cctype>
#include <cstring>
#include <memory>
#include <string>
#include <thread>

#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include "UICommon/UICommon.h"
#include "UICommon/X11Utils.h"
#include "VideoCommon/Present.h"

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
#endif

namespace
{
std::string HpcosX11KeyToken(KeySym key)
{
  const char* raw = XKeysymToString(key);
  if (!raw)
    return {};
  std::string token(raw);
  if (token.size() == 1 && token[0] >= 'a' && token[0] <= 'z')
    token[0] = static_cast<char>(token[0] - 'a' + 'A');
  return token;
}

class PlatformX11 : public Platform
{
public:
  ~PlatformX11() override;

  bool Init() override;
  void SetTitle(const std::string& string) override;
  void MainLoop() override;

  WindowSystemInfo GetWindowSystemInfo() const override;

private:
  void CloseDisplay();
  void UpdateWindowPosition();
  void ProcessEvents();

  Display* m_display = nullptr;
  Window m_window = {};
  Cursor m_blank_cursor = X_None;
#ifdef HAVE_XRANDR
  X11Utils::XRRConfiguration* m_xrr_config = nullptr;
#endif
  int m_window_x = Config::Get(Config::MAIN_RENDER_WINDOW_XPOS);
  int m_window_y = Config::Get(Config::MAIN_RENDER_WINDOW_YPOS);
  unsigned int m_window_width = Config::Get(Config::MAIN_RENDER_WINDOW_WIDTH);
  unsigned int m_window_height = Config::Get(Config::MAIN_RENDER_WINDOW_HEIGHT);
  std::shared_ptr<RenderSurfaceSize> m_render_surface_size =
      std::make_shared<RenderSurfaceSize>(m_window_width, m_window_height);
  u32 m_mouse_button_mask = 0;
  int m_last_mouse_x = 0;
  int m_last_mouse_y = 0;
  bool m_mouse_position_valid = false;
};

PlatformX11::~PlatformX11()
{
#ifdef HAVE_XRANDR
  delete m_xrr_config;
#endif

  if (m_display)
  {
    if (Config::Get(Config::MAIN_SHOW_CURSOR) == Config::ShowCursor::Never)
      XFreeCursor(m_display, m_blank_cursor);

    XCloseDisplay(m_display);
  }
}

bool PlatformX11::Init()
{
  XInitThreads();
  m_display = XOpenDisplay(nullptr);
  if (!m_display)
  {
    PanicAlertFmt("No X11 display found");
    return false;
  }

  m_window = XCreateSimpleWindow(m_display, DefaultRootWindow(m_display), m_window_x, m_window_y,
                                 m_window_width, m_window_height, 0, 0, BlackPixel(m_display, 0));
  XSelectInput(m_display, m_window, StructureNotifyMask | KeyPressMask | KeyReleaseMask | FocusChangeMask | PointerMotionMask | ButtonPressMask | ButtonReleaseMask);
  Atom wmProtocols[1];
  wmProtocols[0] = XInternAtom(m_display, "WM_DELETE_WINDOW", True);
  XSetWMProtocols(m_display, m_window, wmProtocols, 1);
  pid_t pid = getpid();
  XChangeProperty(m_display, m_window, XInternAtom(m_display, "_NET_WM_PID", False), XA_CARDINAL,
                  32, PropModeReplace, reinterpret_cast<unsigned char*>(&pid), 1);
  char host_name[HOST_NAME_MAX] = "";
  if (!gethostname(host_name, sizeof(host_name)))
  {
    XTextProperty wmClientMachine = {reinterpret_cast<unsigned char*>(host_name), XA_STRING, 8,
                                     strlen(host_name)};
    XSetWMClientMachine(m_display, m_window, &wmClientMachine);
  }
  XMapRaised(m_display, m_window);
  XFlush(m_display);
  XSync(m_display, True);
  ProcessEvents();

  if (Config::Get(Config::MAIN_DISABLE_SCREENSAVER))
    UICommon::InhibitScreenSaver(true);

#ifdef HAVE_XRANDR
  m_xrr_config = new X11Utils::XRRConfiguration(m_display, m_window);
#endif

  if (Config::Get(Config::MAIN_SHOW_CURSOR) == Config::ShowCursor::Never)
  {
    // make a blank cursor
    Pixmap Blank;
    XColor DummyColor;
    char ZeroData[1] = {0};
    Blank = XCreateBitmapFromData(m_display, m_window, ZeroData, 1, 1);
    m_blank_cursor = XCreatePixmapCursor(m_display, Blank, Blank, &DummyColor, &DummyColor, 0, 0);
    XFreePixmap(m_display, Blank);
    XDefineCursor(m_display, m_window, m_blank_cursor);
  }

  // Enter fullscreen if enabled.
  if (Config::Get(Config::MAIN_FULLSCREEN))
  {
    if (X11Utils::SetFullscreen(m_display, m_window, true))
      m_window_fullscreen = true;
#ifdef HAVE_XRANDR
    m_xrr_config->ToggleDisplayMode(True);
#endif
    ProcessEvents();
  }

  UpdateWindowPosition();
  return true;
}

void PlatformX11::SetTitle(const std::string& string)
{
  XStoreName(m_display, m_window, string.c_str());
}

void PlatformX11::MainLoop()
{
  while (IsRunning())
  {
    UpdateRunningFlag();
    Core::HostDispatchJobs(Core::System::GetInstance());
    ProcessEvents();

    // TODO: Is this sleep appropriate?
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

WindowSystemInfo PlatformX11::GetWindowSystemInfo() const
{
  WindowSystemInfo wsi;
  wsi.type = WindowSystemType::X11;
  wsi.display_connection = static_cast<void*>(m_display);
  wsi.render_window = reinterpret_cast<void*>(m_window);
  wsi.render_surface = reinterpret_cast<void*>(m_window);
  wsi.render_surface_size = m_render_surface_size;
  return wsi;
}

void PlatformX11::UpdateWindowPosition()
{
  if (m_window_fullscreen)
    return;

  Window winDummy;
  unsigned int borderDummy, depthDummy;
  XGetGeometry(m_display, m_window, &winDummy, &m_window_x, &m_window_y, &m_window_width,
               &m_window_height, &borderDummy, &depthDummy);
  m_render_surface_size->Set(m_window_width, m_window_height);
}

void PlatformX11::ProcessEvents()
{
  XEvent event;
  KeySym key;
  for (int num_events = XPending(m_display); num_events > 0; num_events--)
  {
    XNextEvent(m_display, &event);
    switch (event.type)
    {
    case KeyPress:
    {
      key = XLookupKeysym((XKeyEvent*)&event, 0);
      if (key == XK_F10 && (event.xkey.state & ControlMask))
      {
        HPCOS::ToggleOverlay();
        if (Config::Get(Config::MAIN_SHOW_CURSOR) == Config::ShowCursor::Never)
        {
          if (HPCOS::OverlayVisible())
            XUndefineCursor(m_display, m_window);
          else if (Core::GetState(Core::System::GetInstance()) == Core::State::Running)
            XDefineCursor(m_display, m_window, m_blank_cursor);
        }
        break;
      }

      HPCOS::OnHostToken(HpcosX11KeyToken(key), true);
      if (key == XK_Escape && (event.xkey.state & ControlMask))
        RequestShutdown();
      else if (key == XK_F10)
      {
        if (Core::GetState(Core::System::GetInstance()) == Core::State::Running)
        {
          if (Config::Get(Config::MAIN_SHOW_CURSOR) == Config::ShowCursor::Never)
            XUndefineCursor(m_display, m_window);
          Core::SetState(Core::System::GetInstance(), Core::State::Paused);
        }
        else
        {
          if (Config::Get(Config::MAIN_SHOW_CURSOR) == Config::ShowCursor::Never && !HPCOS::OverlayVisible())
            XDefineCursor(m_display, m_window, m_blank_cursor);
          Core::SetState(Core::System::GetInstance(), Core::State::Running);
        }
      }
      else if ((key == XK_Return) && (event.xkey.state & Mod1Mask))
      {
        const bool fullscreen = !m_window_fullscreen;
        if (!X11Utils::SetFullscreen(m_display, m_window, fullscreen))
          break;
        m_window_fullscreen = fullscreen;
#ifdef HAVE_XRANDR
        m_xrr_config->ToggleDisplayMode(m_window_fullscreen);
#endif
      }
      else if (key >= XK_F1 && key <= XK_F8)
      {
        const int slot_number = key - XK_F1 + 1;
        if (event.xkey.state & ShiftMask) State::Save(Core::System::GetInstance(), slot_number);
        else State::Load(Core::System::GetInstance(), slot_number);
      }
      else if (key == XK_F9) Core::SaveScreenShot();
      else if (key == XK_F11) State::LoadLastSaved(Core::System::GetInstance());
      else if (key == XK_F12)
      {
        if (event.xkey.state & ShiftMask) State::UndoLoadState(Core::System::GetInstance());
        else State::UndoSaveState(Core::System::GetInstance());
      }
      break;
    }
    case KeyRelease:
      key = XLookupKeysym((XKeyEvent*)&event, 0);
      HPCOS::OnHostToken(HpcosX11KeyToken(key), false);
      break;
    case MotionNotify:
      if (g_presenter && HPCOS::OverlayVisible())
        g_presenter->SetMousePos(static_cast<float>(event.xmotion.x), static_cast<float>(event.xmotion.y));
      if (m_mouse_position_valid)
        HPCOS::OnMouseMotion(static_cast<float>(event.xmotion.x - m_last_mouse_x),
                             static_cast<float>(event.xmotion.y - m_last_mouse_y));
      m_last_mouse_x = event.xmotion.x;
      m_last_mouse_y = event.xmotion.y;
      m_mouse_position_valid = true;
      break;
    case ButtonPress:
    case ButtonRelease:
    {
      const bool down = event.type == ButtonPress;
      int imgui_button = -1;
      std::string token;
      if (event.xbutton.button == Button1) { imgui_button = 0; token = "Mouse1"; }
      else if (event.xbutton.button == Button3) { imgui_button = 1; token = "Mouse2"; }
      else if (event.xbutton.button == Button2) { imgui_button = 2; token = "Mouse3"; }
      else if (event.xbutton.button == 8) { imgui_button = 3; token = "Mouse4"; }
      else if (event.xbutton.button == 9) { imgui_button = 4; token = "Mouse5"; }
      if (!token.empty()) HPCOS::OnHostToken(token, down);
      if (imgui_button >= 0)
      {
        if (down) m_mouse_button_mask |= (1u << imgui_button);
        else m_mouse_button_mask &= ~(1u << imgui_button);
        if (g_presenter && HPCOS::OverlayVisible()) g_presenter->SetMousePress(m_mouse_button_mask);
      }
      break;
    }
    case FocusIn:
      m_window_focus = true;
      m_mouse_position_valid = false;
      if (Config::Get(Config::MAIN_SHOW_CURSOR) == Config::ShowCursor::Never &&
          Core::GetState(Core::System::GetInstance()) != Core::State::Paused && !HPCOS::OverlayVisible())
        XDefineCursor(m_display, m_window, m_blank_cursor);
      break;
    case FocusOut:
      m_window_focus = false;
      m_mouse_position_valid = false;
      HPCOS::ResetInput();
      if (Config::Get(Config::MAIN_SHOW_CURSOR) == Config::ShowCursor::Never)
        XUndefineCursor(m_display, m_window);
      break;
    case ClientMessage:
      if ((unsigned long)event.xclient.data.l[0] == XInternAtom(m_display, "WM_DELETE_WINDOW", False))
        Stop();
      break;
    case ConfigureNotify:
    {
      const unsigned int width = static_cast<unsigned int>(std::max(event.xconfigure.width, 1));
      const unsigned int height = static_cast<unsigned int>(std::max(event.xconfigure.height, 1));
      const bool resized = width != m_window_width || height != m_window_height;
      m_window_x = event.xconfigure.x;
      m_window_y = event.xconfigure.y;
      m_window_width = width;
      m_window_height = height;
      m_render_surface_size->Set(width, height);
      if (resized && g_presenter)
        g_presenter->ResizeSurface();
    }
      break;
    }
  }
}
}  // namespace

std::unique_ptr<Platform> Platform::CreateX11Platform()
{
  return std::make_unique<PlatformX11>();
}
