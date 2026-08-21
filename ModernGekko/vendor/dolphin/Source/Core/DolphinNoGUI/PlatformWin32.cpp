// Copyright 2019 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "DolphinNoGUI/Platform.h"

#include "Core/Config/MainSettings.h"
#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "Core/HPCOSSettings.h"
#include "Core/System.h"

#include <chrono>
#include <windows.h>
#include <climits>
#include <dwmapi.h>
#include <string>
#include <vector>
#include <windowsx.h>
#include <thread>

#include "VideoCommon/Present.h"
#include "resource.h"

namespace
{
std::string HpcosWin32KeyToken(WPARAM key)
{
  if (key >= 'A' && key <= 'Z')
    return std::string(1, static_cast<char>(key));
  if (key >= '0' && key <= '9')
    return std::string(1, static_cast<char>(key));
  if (key >= VK_F1 && key <= VK_F24)
    return "F" + std::to_string(key - VK_F1 + 1);
  switch (key)
  {
  case VK_SHIFT: return "Shift_L";
  case VK_CONTROL: return "Control_L";
  case VK_MENU: return "Alt_L";
  case VK_RETURN: return "Return";
  case VK_UP: return "Up";
  case VK_DOWN: return "Down";
  case VK_LEFT: return "Left";
  case VK_RIGHT: return "Right";
  case VK_SPACE: return "Space";
  case VK_TAB: return "Tab";
  case VK_BACK: return "BackSpace";
  case VK_ESCAPE: return "Escape";
  default: return {};
  }
}

class PlatformWin32 final : public Platform
{
public:
  ~PlatformWin32() override;

  bool Init() override;
  void SetTitle(const std::string& string) override;
  void MainLoop() override;

  WindowSystemInfo GetWindowSystemInfo() const override;

private:
  static constexpr TCHAR WINDOW_CLASS_NAME[] = _T("DolphinNoGUI");

  static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

  static bool RegisterRenderWindowClass();
  bool CreateRenderWindow();
  void UpdateWindowPosition();
  void ProcessEvents();

  HWND m_hwnd{};

  int m_window_x = Config::Get(Config::MAIN_RENDER_WINDOW_XPOS);
  int m_window_y = Config::Get(Config::MAIN_RENDER_WINDOW_YPOS);
  int m_window_width = Config::Get(Config::MAIN_RENDER_WINDOW_WIDTH);
  int m_window_height = Config::Get(Config::MAIN_RENDER_WINDOW_HEIGHT);
  u32 m_mouse_button_mask = 0;
};

PlatformWin32::~PlatformWin32()
{
  if (m_hwnd)
    DestroyWindow(m_hwnd);
}

bool PlatformWin32::RegisterRenderWindowClass()
{
  WNDCLASSEX wc = {};
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.style = 0;
  wc.lpfnWndProc = WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = GetModuleHandle(nullptr);
  wc.hIcon = LoadIcon(nullptr, IDI_ICON1);
  wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
  wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
  wc.lpszMenuName = nullptr;
  wc.lpszClassName = WINDOW_CLASS_NAME;
  wc.hIconSm = LoadIcon(nullptr, IDI_ICON1);

  if (!RegisterClassEx(&wc))
  {
    MessageBox(nullptr, _T("Window registration failed."), _T("Error"), MB_ICONERROR | MB_OK);
    return false;
  }

  return true;
}

bool PlatformWin32::CreateRenderWindow()
{
  m_hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, WINDOW_CLASS_NAME, _T("Dolphin"), WS_OVERLAPPEDWINDOW,
                          m_window_x < 0 ? CW_USEDEFAULT : m_window_x,
                          m_window_y < 0 ? CW_USEDEFAULT : m_window_y, m_window_width,
                          m_window_height, nullptr, nullptr, GetModuleHandle(nullptr), this);
  if (!m_hwnd)
  {
    MessageBox(nullptr, _T("CreateWindowEx failed."), _T("Error"), MB_ICONERROR | MB_OK);
    return false;
  }

  ShowWindow(m_hwnd, SW_SHOW);
  UpdateWindow(m_hwnd);
  return true;
}

bool PlatformWin32::Init()
{
  if (!RegisterRenderWindowClass() || !CreateRenderWindow())
    return false;

  // Relative raw mouse motion avoids edge clipping and desktop acceleration.
  RAWINPUTDEVICE raw_mouse{};
  raw_mouse.usUsagePage = 0x01;
  raw_mouse.usUsage = 0x02;
  raw_mouse.dwFlags = 0;
  raw_mouse.hwndTarget = m_hwnd;
  RegisterRawInputDevices(&raw_mouse, 1, sizeof(raw_mouse));

  // TODO: Enter fullscreen if enabled.
  if (Config::Get(Config::MAIN_FULLSCREEN))
  {
    ProcessEvents();
  }

  if (Config::Get(Config::MAIN_DISABLE_SCREENSAVER))
    SetThreadExecutionState(ES_CONTINUOUS | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);

  UpdateWindowPosition();
  return true;
}

void PlatformWin32::SetTitle(const std::string& string)
{
  SetWindowTextW(m_hwnd, UTF8ToWString(string).c_str());
}

void PlatformWin32::MainLoop()
{
  while (IsRunning())
  {
    UpdateRunningFlag();
    Core::HostDispatchJobs(Core::System::GetInstance());
    ProcessEvents();
    UpdateWindowPosition();

    // TODO: Is this sleep appropriate?
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
  }
}

WindowSystemInfo PlatformWin32::GetWindowSystemInfo() const
{
  WindowSystemInfo wsi;
  wsi.type = WindowSystemType::Windows;
  wsi.render_window = reinterpret_cast<void*>(m_hwnd);
  wsi.render_surface = reinterpret_cast<void*>(m_hwnd);
  return wsi;
}

void PlatformWin32::UpdateWindowPosition()
{
  if (m_window_fullscreen)
    return;

  RECT rc = {};
  if (!GetWindowRect(m_hwnd, &rc))
    return;

  m_window_x = rc.left;
  m_window_y = rc.top;
  m_window_width = rc.right - rc.left;
  m_window_height = rc.bottom - rc.top;
}

void PlatformWin32::ProcessEvents()
{
  MSG msg;
  while (PeekMessage(&msg, m_hwnd, 0, 0, PM_REMOVE))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
}

LRESULT PlatformWin32::WndProc(const HWND hwnd, const UINT msg, const WPARAM wParam,
                               const LPARAM lParam)
{
  PlatformWin32* platform = reinterpret_cast<PlatformWin32*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
  switch (msg)
  {
  case WM_NCCREATE:
  {
    platform = static_cast<PlatformWin32*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
    SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(platform));
    return DefWindowProc(hwnd, msg, wParam, lParam);
  }

  case WM_CREATE:
  {
    if (hwnd)
    {
      // Remove rounded corners from the render window on Windows 11
      constexpr DWM_WINDOW_CORNER_PREFERENCE corner_preference = DWMWCP_DONOTROUND;
      DwmSetWindowAttribute(hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &corner_preference,
                            sizeof(corner_preference));
    }
  }
  break;

  case WM_SIZE:
  {
    if (g_presenter)
      g_presenter->ResizeSurface();
  }
  break;

  case WM_KEYDOWN:
  case WM_SYSKEYDOWN:
  {
    const bool first_press = (lParam & (1LL << 30)) == 0;
    if (wParam == VK_F10 && (GetKeyState(VK_CONTROL) & 0x8000) != 0 && first_press)
    {
      HPCOS::ToggleOverlay();
      return 0;
    }
    const std::string token = HpcosWin32KeyToken(wParam);
    if (!token.empty()) HPCOS::OnHostToken(token, true);
    if (wParam == VK_ESCAPE)
      platform->RequestShutdown();
    break;
  }

  case WM_KEYUP:
  case WM_SYSKEYUP:
  {
    const std::string token = HpcosWin32KeyToken(wParam);
    if (!token.empty()) HPCOS::OnHostToken(token, false);
    break;
  }

  case WM_MOUSEMOVE:
    if (g_presenter && HPCOS::OverlayVisible())
      g_presenter->SetMousePos(static_cast<float>(GET_X_LPARAM(lParam)),
                               static_cast<float>(GET_Y_LPARAM(lParam)));
    break;

  case WM_LBUTTONDOWN: case WM_LBUTTONUP:
  case WM_RBUTTONDOWN: case WM_RBUTTONUP:
  case WM_MBUTTONDOWN: case WM_MBUTTONUP:
  case WM_XBUTTONDOWN: case WM_XBUTTONUP:
  {
    const bool down = msg == WM_LBUTTONDOWN || msg == WM_RBUTTONDOWN || msg == WM_MBUTTONDOWN ||
                      msg == WM_XBUTTONDOWN;
    int imgui_button = -1;
    const char* token = nullptr;
    if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONUP) { imgui_button = 0; token = "Mouse1"; }
    else if (msg == WM_RBUTTONDOWN || msg == WM_RBUTTONUP) { imgui_button = 1; token = "Mouse2"; }
    else if (msg == WM_MBUTTONDOWN || msg == WM_MBUTTONUP) { imgui_button = 2; token = "Mouse3"; }
    else if (GET_XBUTTON_WPARAM(wParam) == XBUTTON1) { imgui_button = 3; token = "Mouse4"; }
    else { imgui_button = 4; token = "Mouse5"; }
    HPCOS::OnHostToken(token, down);
    if (down) platform->m_mouse_button_mask |= (1u << imgui_button);
    else platform->m_mouse_button_mask &= ~(1u << imgui_button);
    if (g_presenter && HPCOS::OverlayVisible())
      g_presenter->SetMousePress(platform->m_mouse_button_mask);
    return 0;
  }

  case WM_INPUT:
  {
    UINT size = 0;
    GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, nullptr, &size,
                    sizeof(RAWINPUTHEADER));
    if (size != 0)
    {
      std::vector<u8> bytes(size);
      if (GetRawInputData(reinterpret_cast<HRAWINPUT>(lParam), RID_INPUT, bytes.data(), &size,
                          sizeof(RAWINPUTHEADER)) == size)
      {
        const RAWINPUT* raw = reinterpret_cast<const RAWINPUT*>(bytes.data());
        if (raw->header.dwType == RIM_TYPEMOUSE)
          HPCOS::OnMouseMotion(static_cast<float>(raw->data.mouse.lLastX),
                               static_cast<float>(raw->data.mouse.lLastY));
      }
    }
    break;
  }

  case WM_KILLFOCUS:
    HPCOS::ResetInput();
    break;

  case WM_CLOSE:
    platform->RequestShutdown();
    break;

  default:
    return DefWindowProc(hwnd, msg, wParam, lParam);
  }

  return 0;
}
}  // namespace

std::unique_ptr<Platform> Platform::CreateWin32Platform()
{
  return std::make_unique<PlatformWin32>();
}
