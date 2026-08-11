// Copyright 2021 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "HRWrap.h"

#include "Common/CommonFuncs.h"

namespace Common
{
std::string GetHResultMessage(HRESULT hr)
{
#ifdef _MSC_VER
  auto err = winrt::hresult_error(hr);
  return winrt::to_string(err.message());
#else
  return GetWin32ErrorString(static_cast<DWORD>(hr));
#endif
}
#ifdef _MSC_VER
std::string GetHResultMessage(const winrt::hresult& hr)
{
  return GetHResultMessage(hr.value);
}
#endif
}  // namespace Common
