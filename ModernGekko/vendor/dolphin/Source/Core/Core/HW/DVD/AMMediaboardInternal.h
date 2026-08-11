// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <array>
#include <span>
#include <string_view>
#include <cassert>
#include <climits>

#ifdef _WIN32
#include <winsock2.h>
#endif

#include "Common/BitUtils.h"
#include "Common/CommonTypes.h"
#include "Common/Network.h"
#include "Core/Core.h"
#include "Core/System.h"
#include "Core/PowerPC/MMU.h"
#include "Core/CoreTiming.h"
#include "Core/HW/DVD/AMMediaboard.h"

#ifndef _WIN32
using SOCKET = int;
#endif

namespace AMMediaboard
{

enum class GuestSocket : s32
{
};
static constexpr auto INVALID_GUEST_SOCKET = GuestSocket(-1);

struct TimeVal
{
  // TODO: Verify this.
  u64 seconds;
  u32 microseconds;
};

struct GuestFdSet
{
  static constexpr std::size_t BIT_COUNT = 256;

  std::array<u8, BIT_COUNT / CHAR_BIT> bits{};

  constexpr bool IsFdSet(GuestSocket s) const
  {
    const auto index = std::size_t(s);
    assert(index < BIT_COUNT);
    return Common::ExtractBit(bits[index / CHAR_BIT], index % CHAR_BIT) != 0;
  }

  constexpr void SetFd(GuestSocket s, bool value = true)
  {
    const auto index = std::size_t(s);
    assert(index < BIT_COUNT);
    Common::SetBit(bits[index / CHAR_BIT], index % CHAR_BIT, value);
  }
};
static_assert(sizeof(GuestFdSet) == 32);

// This seems to be based on VxWorks sockaddr_in.
struct GuestSocketAddress
{
  // Seemingly always zero or random values ? Game bug ?
  // This is the struct size in VxWorks.
  u8 unknown_value;

  u8 ip_family;
  u16 port;  // Network byte order.
  Common::IPAddress ip_address;
  std::array<u8, 8> padding;
};
static_assert(sizeof(GuestSocketAddress) == 16);

extern std::array<SOCKET, SOCKET_FD_MAX> s_sockets;
extern u32 s_next_valid_fd;
extern std::array<u32, 3> s_timeouts;
extern Common::IPAddress s_game_modified_ip_address;
extern std::array<u8, 0x4ffe00> s_network_command_buffer;
extern std::array<u8, 0x80000> s_network_buffer;

extern std::array<u32, 0xc0> s_media_buffer_32;
extern u8* const s_media_buffer;
extern u32 s_last_error;

static constexpr u32 FIRST_VALID_FD = 1;
static constexpr std::size_t MAX_IPV4_STRING_LENGTH = 15;

std::span<u8> GetSpanForMediaboardAddress(u32 address);
std::string_view GetSafeString(u32 offset, u32 max_length);
bool SafeCopyToEmu(Memory::MemoryManager& memory, u32 address, const u8* source,
                   u64 source_size, u32 offset, u32 length);
bool SafeCopyFromEmu(Memory::MemoryManager& memory, u8* destination, u32 address,
                     u64 destination_size, u32 offset, u32 length);

SOCKET GetHostSocket(GuestSocket x);
GuestSocket GetGuestSocket(SOCKET x);

void AMMBCommandRecv(u32 parameter_offset);
void AMMBCommandSend(u32 parameter_offset);
void AMMBCommandSocket(u32 parameter_offset);
void AMMBCommandClosesocket(u32 parameter_offset);
void AMMBCommandConnect(u32 parameter_offset);
void AMMBCommandAccept(u32 parameter_offset);
void AMMBCommandBind();
void AMMBCommandSelect(u32 parameter_offset);
void AMMBCommandSetSockOpt(u32 parameter_offset);
void AMMBCommandModifyMyIPaddr(u32 parameter_offset);

s32 NetDIMMConnect(GuestSocket guest_socket, const GuestSocketAddress& guest_addr);
GuestSocket NetDIMMAccept(GuestSocket guest_socket, u8* guest_addr_ptr,
                          u8* guest_addrlen_ptr);
u32 NetDIMMBind(GuestSocket guest_socket, const GuestSocketAddress& guest_addr);

}  // namespace AMMediaboard
