// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/DVD/AMMediaboard.h"
#include "Core/HW/DVD/AMMediaboardInternal.h"

#include <algorithm>
#include <bit>
#include <random>
#include <string>
#include <unordered_map>

#include <fmt/format.h>

#include "Common/BitUtils.h"
#include "Common/CommonTypes.h"
#include "Common/FileUtil.h"
#include "Common/IOFile.h"
#include "Common/Logging/Log.h"
#include "Common/ScopeGuard.h"

#include "Core/Config/MainSettings.h"
#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/HLE/HLE.h"
#include "Core/HW/EXI/EXI_DeviceBaseboard.h"
#include "Core/HW/Memmap.h"
#include "Core/IOS/Network/Socket.h"
#include "Core/Movie.h"
#include "Core/System.h"

#include "DiscIO/CachedBlob.h"
#include "VideoCommon/OnScreenDisplay.h"

#if defined(__linux__) or defined(__APPLE__) or defined(__FreeBSD__) or defined(__NetBSD__) or     \
    defined(__HAIKU__)

#include <unistd.h>

#include "Common/UnixUtil.h"

static constexpr auto* closesocket = close;
static auto ioctlsocket(auto... args)
{
  return ioctl(args...);
}

static constexpr int WSAEWOULDBLOCK = 10035;
static constexpr int SOCKET_ERROR = -1;

using SOCKET = int;
using WSAPOLLFD = pollfd;

static constexpr SOCKET INVALID_SOCKET = SOCKET(~0);

static int WSAGetLastError()
{
  switch (errno)
  {
#if EAGAIN != EWOULDBLOCK
  case EAGAIN:
#endif
  case EINPROGRESS:
  case EWOULDBLOCK:
    return WSAEWOULDBLOCK;
  default:
    break;
  }

  return errno;
}

#endif

namespace AMMediaboard
{

static int PlatformPoll(std::span<WSAPOLLFD> pfds, std::chrono::milliseconds timeout)
{
#if defined(_WIN32)
  return WSAPoll(pfds.data(), ULONG(pfds.size()), INT(timeout.count()));
#else
  return UnixUtil::RetryOnEINTR(poll, pfds.data(), pfds.size(), timeout.count());
#endif
}

static GuestSocket GetAvailableGuestSocket()
{
  // TODO: This is a workaround to avoid a race.
  //
  // For some unknown reasons, the fd was:
  //  - shared between a client (connect) and a server (accept) socket.
  //  - closed but still used by the other in an invalid state.
  u32 count = std::size(s_sockets);
  while (count--)
  {
    const u32 i = s_next_valid_fd;
    s_next_valid_fd = (s_next_valid_fd + 1) % std::size(s_sockets);
    if (i < FIRST_VALID_FD)
      continue;
    if (s_sockets[i] == SOCKET_ERROR)
      return GuestSocket(i);
  }

  // Out of sockets.
  return INVALID_GUEST_SOCKET;
}

SOCKET GetHostSocket(GuestSocket x)
{
  const auto index = u32(x);

  if (index < std::size(s_sockets))
    return s_sockets[index];

  WARN_LOG_FMT(AMMEDIABOARD, "GC-AM: Bad GuestSocket value: {}", index);
  return INVALID_SOCKET;
}

GuestSocket GetGuestSocket(SOCKET x)
{
  const auto it = std::find(std::begin(s_sockets) + FIRST_VALID_FD, std::end(s_sockets), x);

  if (it == std::end(s_sockets))
  {
    ERROR_LOG_FMT(AMMEDIABOARD, "GuestSocket not found. This should not happen.");
    return INVALID_GUEST_SOCKET;
  }

  return GuestSocket(it - std::begin(s_sockets));
}
static GuestSocket socket_(int af, int type, int protocol)
{
  const auto guest_socket = GetAvailableGuestSocket();
  if (guest_socket == INVALID_GUEST_SOCKET)
    return INVALID_GUEST_SOCKET;

  const s32 host_fd = socket(af, type, protocol);
  if (host_fd < 0)
  {
    ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: failed to create socket ({})", Common::StrNetworkError());
    return INVALID_GUEST_SOCKET;
  }

  Common::SetPlatformSocketOptions(host_fd);

  s_sockets[u32(guest_socket)] = host_fd;
  return guest_socket;
}

static GuestSocket accept_(int fd, sockaddr* addr, socklen_t* len)
{
  const auto guest_socket = GetAvailableGuestSocket();
  if (guest_socket == INVALID_GUEST_SOCKET)
    return INVALID_GUEST_SOCKET;

  const s32 host_fd = accept(fd, addr, len);
  if (host_fd < 0)
    return INVALID_GUEST_SOCKET;

  Common::SetPlatformSocketOptions(host_fd);

  s_sockets[u32(guest_socket)] = host_fd;
  return guest_socket;
}
void AMMBCommandRecv(u32 parameter_offset)
{
  const auto fd = GetHostSocket(GuestSocket(s_media_buffer_32[parameter_offset]));
  const u32 off = s_media_buffer_32[parameter_offset + 1];
  u32 len = s_media_buffer_32[parameter_offset + 2];

  const auto data_span = GetSpanForMediaboardAddress(off);
  if (data_span.size() < len)
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "AMMBCommandRecv: Bad data offset or length: off={:08x} len={}",
                  off, len);
    len = 0;
  }

  // TODO: Might be blocking depending on the timeout (see SetTimeouts command).
  const int ret = recv(fd, reinterpret_cast<char*>(data_span.data()), len, 0);
  const int err = WSAGetLastError();

  if (ret < 0 && err != WSAEWOULDBLOCK)
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: recv( {}, 0x{:08x}, {} ) failed with error {}: {}", fd,
                  off, len, err, Common::DecodeNetworkError(err));
  }
  else if (ret == 0)
  {
    INFO_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: recv( {}, 0x{:08x}, {} ):0 shutdown received", fd, off,
                 len);
  }
  else
  {
    DEBUG_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: recv( {}, 0x{:08x}, {} ):{} {}", fd, off, len, ret,
                  err);
  }

  s_media_buffer[1] = s_media_buffer[8];
  s_media_buffer_32[1] = ret;
}

void AMMBCommandSend(u32 parameter_offset)
{
  const auto guest_socket = GuestSocket(s_media_buffer_32[parameter_offset]);
  const auto fd = GetHostSocket(guest_socket);
  const u32 off = s_media_buffer_32[parameter_offset + 1];
  u32 len = s_media_buffer_32[parameter_offset + 2];

  const auto data_span = GetSpanForMediaboardAddress(off);
  if (data_span.size() < len)
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "AMMBCommandSend: Bad data offset or length: off={:08x} len={}",
                  off, len);
    len = 0;
  }

  // TODO: Might be blocking depending on the timeout (see SetTimeouts command).
  const int ret = send(fd, reinterpret_cast<char*>(data_span.data()), len, Common::SEND_FLAGS);
  const int err = WSAGetLastError();

  if (ret < 0 && err != WSAEWOULDBLOCK)
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: send( {}({}), 0x{:08x}, {} ) failed with error {}: {}",
                  fd, u32(guest_socket), off, len, err, Common::DecodeNetworkError(err));
  }
  else
  {
    DEBUG_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: send( {}({}), 0x{:08x}, {} ): {} {}", fd,
                  u32(guest_socket), off, len, ret, err);
  }

  s_media_buffer[1] = s_media_buffer[8];
  s_media_buffer_32[1] = ret;
}

void AMMBCommandSocket(u32 parameter_offset)
{
  // Protocol is not sent (determined automatically).
  const u32 domain = s_media_buffer_32[parameter_offset];
  const u32 type = s_media_buffer_32[parameter_offset + 1];

  const GuestSocket guest_socket = socket_(int(domain), int(type), 0);

  NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: socket( {}, {} ):{}", domain, type, u32(guest_socket));

  s_media_buffer[1] = 0;
  s_media_buffer_32[1] = u32(guest_socket);
}

void AMMBCommandClosesocket(u32 parameter_offset)
{
  const auto guest_socket = GuestSocket(s_media_buffer_32[parameter_offset]);
  const auto fd = GetHostSocket(guest_socket);

  const int ret = closesocket(fd);

  NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: closesocket( {}({}) ):{}", fd, u32(guest_socket), ret);

  if (u32(guest_socket) < std::size(s_sockets))
    s_sockets[u32(guest_socket)] = SOCKET_ERROR;

  s_media_buffer_32[1] = ret;
  s_last_error = SSC_SUCCESS;
}

void AMMBCommandConnect(u32 parameter_offset)
{
  const auto guest_socket = GuestSocket(s_media_buffer_32[parameter_offset + 0]);
  const u32 addr_offset = s_media_buffer_32[parameter_offset + 1];
  const u32 len = s_media_buffer_32[parameter_offset + 2];

  GuestSocketAddress addr;

  if (len != sizeof(addr))
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "AMMBCommandConnect: Unexpected length: {}", len);
    return;
  }

  const auto addr_span = GetSpanForMediaboardAddress(addr_offset);
  if (addr_span.size() < sizeof(addr))
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "AMMBCommandConnect: Bad address offset: {:08x}", addr_offset);
    return;
  }

  memcpy(&addr, addr_span.data(), sizeof(addr));

  const int ret = NetDIMMConnect(guest_socket, addr);

  s_media_buffer[1] = s_media_buffer[8];
  s_media_buffer_32[1] = ret;
}

void AMMBCommandAccept(u32 parameter_offset)
{
  const auto guest_socket = GuestSocket(s_media_buffer_32[parameter_offset]);
  const u32 addr_off = s_media_buffer_32[parameter_offset + 1];
  const u32 addrlen_off = s_media_buffer_32[parameter_offset + 2];

  const auto addrlen_span = GetSpanForMediaboardAddress(addrlen_off);

  u8* addr_ptr{};
  u8* addrlen_ptr{};

  if (addrlen_span.size() >= sizeof(u32))
  {
    addrlen_ptr = addrlen_span.data();
    const u32 addrlen = Common::BitCastPtr<u32>(addrlen_ptr);

    const auto addr_span = GetSpanForMediaboardAddress(addr_off);
    if (addr_span.size() >= addrlen)
    {
      addr_ptr = addr_span.data();
    }
    else
    {
      ERROR_LOG_FMT(AMMEDIABOARD_NET,
                    "AMMBCommandAccept: Bad address offset or addrlen: off={:08x} len={}", addr_off,
                    addrlen);
    }
  }

  const auto accept_result = NetDIMMAccept(guest_socket, addr_ptr, addrlen_ptr);

  s_media_buffer_32[1] = u32(accept_result);
}

void AMMBCommandBind()
{
  const auto guest_socket = GuestSocket(s_media_buffer_32[2]);
  const u32 addr_offset = s_media_buffer_32[3];
  const u32 len = s_media_buffer_32[4];

  GuestSocketAddress guest_addr;

  if (len != sizeof(guest_addr))
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "AMMBCommandBind: Unexpected length: {}", len);
    return;
  }

  const auto addr_span = GetSpanForMediaboardAddress(addr_offset);
  if (addr_span.size() < sizeof(guest_addr))
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "AMMBCommandBind: Bad address offset: {:08x}", addr_offset);
    return;
  }

  memcpy(&guest_addr, addr_span.data(), sizeof(guest_addr));

  const auto bind_result = NetDIMMBind(guest_socket, guest_addr);

  s_media_buffer_32[1] = bind_result;
  s_last_error = SSC_SUCCESS;
}

static void FillPollFdsFromGuestFdSet(std::span<WSAPOLLFD> pfds, u32 guest_fds_offset,
                                      short requested_events)
{
  if (guest_fds_offset == 0)
    return;

  GuestFdSet guest_fds;

  const auto guest_fds_span = GetSpanForMediaboardAddress(guest_fds_offset);
  if (guest_fds_span.size() < sizeof(guest_fds))
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "Bad FDSET offset: {:08x}", guest_fds_offset);
    return;
  }

  std::memcpy(&guest_fds, guest_fds_span.data(), sizeof(guest_fds));

  u32 index = 0;
  for (auto& pfd : pfds)
  {
    const auto guest_socket = GuestSocket(index);
    if (guest_fds.IsFdSet(guest_socket))
    {
      pfd.fd = GetHostSocket(guest_socket);
      pfd.events |= requested_events;
    }

    ++index;
  }
}

static void WriteGuestFdSetFromPollFds(u32 guest_fds_offset, std::span<const WSAPOLLFD> fds,
                                       short returned_events)
{
  if (guest_fds_offset == 0)
    return;

  GuestFdSet guest_fds;

  const auto guest_fds_span = GetSpanForMediaboardAddress(guest_fds_offset);
  if (guest_fds_span.size() < sizeof(guest_fds))
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "Bad FDSET offset: {:08x}", guest_fds_offset);
    return;
  }

  for (const auto& fd : fds)
  {
    if ((fd.revents & returned_events) == 0)
      continue;

    const auto guest_socket = GetGuestSocket(fd.fd);
    if (guest_socket == INVALID_GUEST_SOCKET)
      continue;

    guest_fds.SetFd(guest_socket);
  }

  std::ranges::copy(Common::AsU8Span(guest_fds), guest_fds_span.data());
}

void AMMBCommandSelect(u32 parameter_offset)
{
  u32 nfds = int(s_media_buffer_32[parameter_offset]);
  const u32 readfds_offset = s_media_buffer_32[parameter_offset + 1];
  const u32 writefds_offset = s_media_buffer_32[parameter_offset + 2];
  const u32 exceptfds_offset = s_media_buffer_32[parameter_offset + 3];
  const u32 timeout_offset = s_media_buffer_32[parameter_offset + 4];

  // Games sometimes send 256 (the bit size of GuestFdSet).
  nfds = std::min<u32>(nfds, std::size(s_sockets));

  std::chrono::milliseconds timeout{-1};
  if (timeout_offset != 0)
  {
    const auto guest_timeout_span = GetSpanForMediaboardAddress(timeout_offset);

    TimeVal guest_timeout;

    if (guest_timeout_span.size() < sizeof(guest_timeout))
    {
      ERROR_LOG_FMT(AMMEDIABOARD_NET, "AMMBCommandSelect: Bad timeout offset: {:08x}",
                    timeout_offset);
    }
    else
    {
      std::memcpy(&guest_timeout, guest_timeout_span.data(), sizeof(guest_timeout));

      timeout = duration_cast<std::chrono::milliseconds>(
          std::chrono::seconds(guest_timeout.seconds) +
          std::chrono::microseconds(guest_timeout.microseconds));
    }
  }

  if (timeout < std::chrono::milliseconds{})
  {
    // TODO: We should have a way to break out of any timeout on shutdown.
    // e.g. include a "wakeup" socket in each `poll` call.
    WARN_LOG_FMT(AMMEDIABOARD, "AMMBCommandSelect: Infinite timout!");
  }

  DEBUG_LOG_FMT(AMMEDIABOARD_NET,
                "GC-AM: select( {}, 0x{:08x} 0x{:08x} 0x{:08x} 0x{:08x} ) timeout={}", nfds,
                readfds_offset, writefds_offset, exceptfds_offset, timeout_offset, timeout.count());

  // Fill with the host sockets for each guest socket less-than `nfds` in each GuestFdSet.
  std::vector<WSAPOLLFD> pollfds(nfds, WSAPOLLFD{.fd = INVALID_SOCKET});

  FillPollFdsFromGuestFdSet(pollfds, readfds_offset, POLLIN);
  FillPollFdsFromGuestFdSet(pollfds, writefds_offset, POLLOUT);
  FillPollFdsFromGuestFdSet(pollfds, exceptfds_offset, POLLPRI);

  // Erase "INVALID" entries and also entries that weren't in any GuestFdSet.
  std::erase_if(pollfds, [](const WSAPOLLFD& fd) { return fd.fd == INVALID_SOCKET; });

  // TODO: There may be some edge cases where
  // poll's (POLLIN,POLLOUT,POLLPRI) don't map 1:1 with select's (readfds,writefds,exceptfds).

  DEBUG_LOG_FMT(AMMEDIABOARD, "AMMBCommandSelect: Polling with socket count: {}", pollfds.size());

  const int ret = PlatformPoll(pollfds, timeout);

  if (ret >= 0)
  {
    WriteGuestFdSetFromPollFds(readfds_offset, pollfds, POLLIN);
    WriteGuestFdSetFromPollFds(writefds_offset, pollfds, POLLOUT);
    WriteGuestFdSetFromPollFds(exceptfds_offset, pollfds, POLLPRI);
    DEBUG_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: select result: {}", ret);
  }
  else
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: select failed: {} ({})", ret,
                  Common::StrNetworkError());
  }

  s_media_buffer[1] = 0;
  s_media_buffer_32[1] = ret;
}

void AMMBCommandSetSockOpt(u32 parameter_offset)
{
  const auto fd = GetHostSocket(GuestSocket(s_media_buffer_32[parameter_offset]));
  const int level = static_cast<int>(s_media_buffer_32[parameter_offset + 1]);
  const int optname = static_cast<int>(s_media_buffer_32[parameter_offset + 2]);
  const u32 optval_offset = s_media_buffer_32[parameter_offset + 3];
  const u32 optlen = s_media_buffer_32[parameter_offset + 4];

  const auto optval_span = GetSpanForMediaboardAddress(optval_offset);
  if (optval_span.size() < optlen)
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET,
                  "AMMBCommandSetSockOpt: Bad optval offset or length: off={:08x} len={}",
                  optval_offset, optlen);
    return;
  }

  const char* optval = reinterpret_cast<char*>(optval_span.data());

  // TODO: Ensure parameters are compatible with host's setsockopt
  const int ret = setsockopt(fd, level, optname, optval, optlen);
  const int err = WSAGetLastError();

  NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: setsockopt( {:d}, {:04x}, {}, {:p}, {} ):{:d} ({})", fd,
                 level, optname, optval, optlen, ret, err);

  s_media_buffer[1] = s_media_buffer[8];
  s_media_buffer_32[1] = ret;
}

void AMMBCommandModifyMyIPaddr(u32 parameter_offset)
{
  const u32 ip_address_offset = s_media_buffer_32[parameter_offset];
  const auto ip_address_str = GetSafeString(ip_address_offset, MAX_IPV4_STRING_LENGTH);

  NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: modifyMyIPaddr({})", ip_address_str);

  if (const auto parse_result = Common::StringToIPv4PortRange(ip_address_str))
    s_game_modified_ip_address = parse_result->first.ip_address;
}

using Clock = std::chrono::system_clock;

std::optional<Common::IPv4Port> AdjustIPv4PortFromConfig(Common::IPv4Port subject)
{
  // TODO: We should parse this elsewhere to avoid repeated string manipulations.
  for (auto&& redirection : GetIPRedirections())
  {
    if (redirection.original.IsMatch(subject))
      return redirection.Apply(subject);
  }

  return std::nullopt;
}

std::optional<Common::IPv4Port> ReverseAdjustIPv4PortFromConfig(Common::IPv4Port subject)
{
  // TODO: We should parse this elsewhere to avoid repeated string manipulations.
  for (auto&& redirection : GetIPRedirections())
  {
    if (redirection.replacement.IsMatch(subject))
      return redirection.Reverse(subject);
  }

  return std::nullopt;
}

// Ports are in host byte order.
bool BindEphemeralPort(SOCKET host_socket, Common::IPAddress ip_address,
                              u16 first_port_value, u16 last_port_value, u32 attempt_count)
{
  std::mt19937 rng(u32(Clock::now().time_since_epoch().count()));
  std::uniform_int_distribution<u16> port_distribution{first_port_value, last_port_value};

  sockaddr_in addr = {
      .sin_family = AF_INET,
      .sin_addr = std::bit_cast<in_addr>(ip_address),
  };

  while (attempt_count-- != 0)
  {
    const u16 port_value = port_distribution(rng);

    addr.sin_port = htons(port_value);

    const auto bind_result = bind(host_socket, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
    const int bind_err = WSAGetLastError();

    INFO_LOG_FMT(AMMEDIABOARD, "BindEphemeralPort: bind ({}:{}) = {} ({})",
                 Common::IPAddressToString(ip_address), port_value, bind_result,
                 Common::DecodeNetworkError(bind_err));

    if (bind_result == 0)
      return true;
  }

  return false;
}

s32 NetDIMMConnect(GuestSocket guest_socket, const GuestSocketAddress& guest_addr)
{
  INFO_LOG_FMT(AMMEDIABOARD, "NetDIMMConnect: {}:{}",
               Common::IPAddressToString(guest_addr.ip_address), ntohs(guest_addr.port));

  sockaddr_in addr{
      .sin_family = guest_addr.ip_family,
  };

  // Adjust destination IP and port.
  const auto adjusted_ipv4port = AdjustIPv4PortFromConfig({guest_addr.ip_address, guest_addr.port});
  if (adjusted_ipv4port.has_value())
  {
    addr.sin_addr = std::bit_cast<in_addr>(adjusted_ipv4port->ip_address);
    addr.sin_port = adjusted_ipv4port->port;

    INFO_LOG_FMT(AMMEDIABOARD, "NetDIMMConnect: Redirecting to: {}:{}",
                 Common::IPAddressToString(adjusted_ipv4port->ip_address),
                 ntohs(adjusted_ipv4port->port));
  }
  else
  {
    addr.sin_addr = std::bit_cast<in_addr>(guest_addr.ip_address);
    addr.sin_port = guest_addr.port;
  }

  const auto host_socket = GetHostSocket(guest_socket);

  // See if we have a redirection for the game modified IP.
  // If so, adjust the source IP by binding the socket.
  const auto adjusted_source_ipv4port = AdjustIPv4PortFromConfig({s_game_modified_ip_address, 0});
  if (adjusted_source_ipv4port.has_value())
  {
    // FYI: We don't handle the situation if games bind outgoing TCP themselves.
    // But I think that's unlikely.

    const u16 first_port_value = adjusted_source_ipv4port->GetPortValue();

    // If port zero is included then we don't care about the port number.
    const bool use_any_port = first_port_value == 0;
    const u32 attempt_count = use_any_port ? 1 : 10;

    // TODO: Handle the range properly. AdjustIPv4PortFromConfig should return a port range.
    // This magic 999 is here just to match our default config..
    const u16 last_port_value = use_any_port ? 0 : first_port_value + 999;

    const auto bind_result = BindEphemeralPort(host_socket, adjusted_source_ipv4port->ip_address,
                                               first_port_value, last_port_value, attempt_count);

    if (!bind_result)
    {
      s_last_error = SOCKET_ERROR;
      return SOCKET_ERROR;
    }
  }

  // Set socket to non-blocking
  {
    u_long val = 1;
    ioctlsocket(host_socket, FIONBIO, &val);
  }
  // Restore blocking mode
  Common::ScopeGuard guard{[&] {
    u_long val = 0;
    ioctlsocket(host_socket, FIONBIO, &val);
  }};

  const int connect_result =
      connect(host_socket, reinterpret_cast<const sockaddr*>(&addr), sizeof(addr));
  const int err = WSAGetLastError();

  INFO_LOG_FMT(AMMEDIABOARD_NET, "NetDIMMConnect: connect( {}({}), ({},{}:{}) ):{} ({})",
               host_socket, u32(guest_socket), addr.sin_family, inet_ntoa(addr.sin_addr),
               Common::swap16(addr.sin_port), connect_result, err);

  if (connect_result == 0) [[unlikely]]
  {
    // Immediate success.
    s_last_error = SSC_SUCCESS;
    return 0;
  }

  if (err != WSAEWOULDBLOCK)
  {
    // Immediate failure (e.g. WSAECONNREFUSED)
    WARN_LOG_FMT(AMMEDIABOARD, "NetDIMMConnect: connect: {} ({})", err,
                 Common::DecodeNetworkError(err));

    s_last_error = SOCKET_ERROR;
    return SOCKET_ERROR;
  }

  WSAPOLLFD pfds[1]{{.fd = host_socket, .events = POLLOUT}};

  // TODO: Possible race between this socket's SetTimeOuts and others'
  const auto timeout =
      duration_cast<std::chrono::milliseconds>(std::chrono::microseconds{s_timeouts[0]});

  // TODO: Might block if timeout is too big
  const int poll_result = PlatformPoll(pfds, timeout);

  if (poll_result < 0) [[unlikely]]
  {
    // Poll failure.
    ERROR_LOG_FMT(AMMEDIABOARD, "NetDIMMConnect: PlatformPoll: {}", Common::StrNetworkError());

    s_last_error = SOCKET_ERROR;
    return SOCKET_ERROR;
  }

  if ((pfds[0].revents & (POLLOUT | POLLERR)) == 0)
  {
    // Timeout.
    s_last_error = SSC_EWOULDBLOCK;
    return SOCKET_ERROR;
  }

  int so_error = 0;
  socklen_t optlen = sizeof(so_error);
  const int getsockopt_result =
      getsockopt(host_socket, SOL_SOCKET, SO_ERROR, reinterpret_cast<char*>(&so_error), &optlen);

  if (getsockopt_result != 0) [[unlikely]]
  {
    // getsockopt failure.
    ERROR_LOG_FMT(AMMEDIABOARD, "NetDIMMConnect: getsockopt: {}", Common::StrNetworkError());
  }
  else if (so_error == 0)
  {
    INFO_LOG_FMT(AMMEDIABOARD_NET, "NetDIMMConnect: connect( {}({}) ) succeeded", host_socket,
                 u32(guest_socket));
    s_last_error = SSC_SUCCESS;
    return 0;
  }

  ERROR_LOG_FMT(AMMEDIABOARD_NET, "NetDIMMConnect: connect( {}({}) ) failed with error {}: {}",
                host_socket, u32(guest_socket), so_error, Common::DecodeNetworkError(so_error));
  s_last_error = SOCKET_ERROR;
  return SOCKET_ERROR;
}

GuestSocket NetDIMMAccept(GuestSocket guest_socket, u8* guest_addr_ptr,
                                 u8* guest_addrlen_ptr)
{
  // Either both parameters should be provided, or neither.
  if ((guest_addr_ptr != nullptr) != (guest_addrlen_ptr != nullptr))
  {
    ERROR_LOG_FMT(AMMEDIABOARD_NET, "NetDIMMAccept: bad parmeters");

    // TODO: Not hardware tested.
    s_last_error = SSC_EFAULT;
    return INVALID_GUEST_SOCKET;
  }

  const auto host_socket = GetHostSocket(guest_socket);
  WSAPOLLFD pfds[1]{{.fd = host_socket, .events = POLLIN}};

  // FYI: Currently using a 0ms timeout to make accept calls always non-blocking.
  constexpr auto timeout = std::chrono::milliseconds{0};

  DEBUG_LOG_FMT(AMMEDIABOARD, "NetDIMMAccept: {}({})", host_socket, int(guest_socket));

  const int poll_result = PlatformPoll(pfds, timeout);

  if (poll_result < 0) [[unlikely]]
  {
    // Poll failure.
    ERROR_LOG_FMT(AMMEDIABOARD, "NetDIMMAccept: PlatformPoll: {}", Common::StrNetworkError());

    s_last_error = SOCKET_ERROR;
    return INVALID_GUEST_SOCKET;
  }

  if ((pfds[0].revents & POLLIN) == 0)
  {
    // Timeout.
    DEBUG_LOG_FMT(AMMEDIABOARD, "NetDIMMAccept: Timeout.");

    s_last_error = SSC_EWOULDBLOCK;
    return INVALID_GUEST_SOCKET;
  }

  sockaddr_in addr;
  socklen_t addrlen = sizeof(addr);
  const auto client_sock = accept_(host_socket, reinterpret_cast<sockaddr*>(&addr), &addrlen);

  if (client_sock == INVALID_GUEST_SOCKET)
  {
    ERROR_LOG_FMT(AMMEDIABOARD, "AMMBCommandAccept: accept( {}({}) ) failed: {}", host_socket,
                  int(guest_socket), Common::StrNetworkError());
    s_last_error = SOCKET_ERROR;
    return INVALID_GUEST_SOCKET;
  }

  s_last_error = SSC_SUCCESS;

  NOTICE_LOG_FMT(AMMEDIABOARD, "AMMBCommandAccept: {}:{}",
                 Common::IPAddressToString(std::bit_cast<Common::IPAddress>(addr.sin_addr)),
                 ntohs(addr.sin_port));

  if (guest_addr_ptr == nullptr)
    return client_sock;

  GuestSocketAddress guest_addr{
      .ip_family = u8(addr.sin_family),
      .port = addr.sin_port,
      .ip_address = std::bit_cast<Common::IPAddress>(addr.sin_addr),
  };

  if (const auto adjusted_ipv4port =
          ReverseAdjustIPv4PortFromConfig({guest_addr.ip_address, guest_addr.port}))
  {
    guest_addr.ip_address = adjusted_ipv4port->ip_address;
    guest_addr.port = adjusted_ipv4port->port;

    NOTICE_LOG_FMT(AMMEDIABOARD, "AMMBCommandAccept: Translating result to: {}:{}",
                   Common::IPAddressToString(guest_addr.ip_address), ntohs(guest_addr.port));
  }

  const auto write_size =
      std::min<u32>(Common::BitCastPtr<u32>(guest_addrlen_ptr), sizeof(guest_addr));

  // Write out the addr.
  std::memcpy(guest_addr_ptr, &guest_addr, write_size);

  // Write out the addrlen.
  *guest_addrlen_ptr = sizeof(guest_addr);

  return client_sock;
}

Common::IPv4Port GetAdjustedBindIPv4Port(Common::IPv4Port socket_addr)
{
  auto considered_ipv4 = socket_addr;

  if (std::bit_cast<u32>(considered_ipv4.ip_address) == INADDR_ANY)
  {
    // Because the game is binding to "0.0.0.0",
    //  use the "game modified" IP for redirection purposes.
    // If no redirection applies, then we still bind "0.0.0.0".
    considered_ipv4.ip_address = s_game_modified_ip_address;
    INFO_LOG_FMT(AMMEDIABOARD, "GetAdjustedBindIPv4Port: Considering game modified IP: {}",
                 Common::IPAddressToString(s_game_modified_ip_address));
  }

  if (const auto adjusted_ipv4 = AdjustIPv4PortFromConfig(considered_ipv4))
  {
    socket_addr = *adjusted_ipv4;
    INFO_LOG_FMT(AMMEDIABOARD, "GetAdjustedBindIPv4Port: Redirecting to: {}:{}",
                 Common::IPAddressToString(socket_addr.ip_address), ntohs(socket_addr.port));
  }

  return socket_addr;
}

u32 NetDIMMBind(GuestSocket guest_socket, const GuestSocketAddress& guest_addr)
{
  const auto host_socket = GetHostSocket(guest_socket);

  NOTICE_LOG_FMT(AMMEDIABOARD, "NetDIMMBind: {}({}) {}, {}, {}:{}", host_socket, int(guest_socket),
                 guest_addr.unknown_value, guest_addr.ip_family,
                 Common::IPAddressToString(guest_addr.ip_address), ntohs(guest_addr.port));

  const auto adjusted_ipv4port = GetAdjustedBindIPv4Port({guest_addr.ip_address, guest_addr.port});

  sockaddr_in addr{
      .sin_family = guest_addr.ip_family,
      .sin_port = adjusted_ipv4port.port,
      .sin_addr = std::bit_cast<in_addr>(adjusted_ipv4port.ip_address),
  };

  const int bind_result = bind(host_socket, reinterpret_cast<const sockaddr*>(&addr), sizeof(addr));
  const int err = WSAGetLastError();

  INFO_LOG_FMT(AMMEDIABOARD_NET, "NetDIMMBind: bind( {}({}), ({},{}:{}) ):{}", host_socket,
               u32(guest_socket), addr.sin_family,
               Common::IPAddressToString(adjusted_ipv4port.ip_address),
               Common::swap16(adjusted_ipv4port.port), bind_result);

  if (bind_result < 0)
  {
    const auto msg = fmt::format("Failed to bind socket {}:{}",
                                 Common::IPAddressToString(adjusted_ipv4port.ip_address),
                                 ntohs(adjusted_ipv4port.port));
    ERROR_LOG_FMT(AMMEDIABOARD, "NetDIMMBind: {} with error {}: {}", msg, err,
                  Common::DecodeNetworkError(err));
    OSD::AddMessage(msg, OSD::Duration::SHORT, OSD::Color::RED);
  }

  return bind_result;
}



}  // namespace AMMediaboard
