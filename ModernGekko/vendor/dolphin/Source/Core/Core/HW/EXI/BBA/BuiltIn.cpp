// Copyright 2022 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/EXI/BBA/BuiltIn.h"

#include <bit>
#include <optional>
#include "SFML/Network/IpAddress.hpp"
#include "SFML/Network/Socket.hpp"

#ifdef _WIN32
#include <ws2tcpip.h>
#else
#include <sys/select.h>
#include <sys/socket.h>
#endif

#include "Common/BitUtils.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Common/Network.h"
#include "Common/ScopeGuard.h"
#include "Core/HW/EXI/EXI_DeviceEthernet.h"

namespace
{
// Change the IP identification and recompute the checksum
void SetIPIdentification(u8* ptr, std::size_t size, u16 value)
{
  if (size < Common::EthernetHeader::SIZE + Common::IPv4Header::SIZE)
    return;

  u8* const ip_ptr = ptr + Common::EthernetHeader::SIZE;
  const u8 ip_header_size = (*ip_ptr & 0xf) * 4;
  if (size < Common::EthernetHeader::SIZE + ip_header_size)
    return;

  u8* const ip_id_ptr = ip_ptr + offsetof(Common::IPv4Header, identification);
  Common::BitCastPtr<u16>(ip_id_ptr) = htons(value);

  u8* const ip_checksum_ptr = ip_ptr + offsetof(Common::IPv4Header, header_checksum);
  auto checksum_bitcast_ptr = Common::BitCastPtr<u16>(ip_checksum_ptr);
  checksum_bitcast_ptr = u16(0);
  checksum_bitcast_ptr = htons(Common::ComputeNetworkChecksum(ip_ptr, ip_header_size));
}
}  // namespace

namespace ExpansionInterface
{
bool CEXIETHERNET::BuiltInBBAInterface::Activate()
{
  if (IsActivated())
    return true;

  m_active = true;
  for (auto& buf : m_queue_data)
    buf.reserve(2048);

  // Workaround to get the host IP (might not be accurate)
  // TODO: Fix the JNI crash and use GetSystemDefaultInterface()
  //  - https://pastebin.com/BFpmnxby (see https://dolp.in/pr10920)
  const u32 ip = sf::IpAddress::resolve(m_local_ip)
                     .value_or(sf::IpAddress::getLocalAddress().value_or(sf::IpAddress::Any))
                     .toInteger();
  m_current_ip = htonl(ip);
  m_current_mac = Common::BitCastPtr<Common::MACAddress>(&m_eth_ref->mBbaMem[BBA_NAFR_PAR0]);
  m_arp_table[m_current_ip] = m_current_mac;
  m_router_ip = (m_current_ip & 0xFFFFFF) | 0x01000000;
  m_router_mac = Common::GenerateMacAddress(Common::MACConsumer::BBA);
  m_arp_table[m_router_ip] = m_router_mac;

  m_network_ref.Clear();

  (void)m_upnp_httpd.listen(Common::SSDP_PORT, sf::IpAddress(ip));
  m_upnp_httpd.setBlocking(false);

  return RecvInit();
}

void CEXIETHERNET::BuiltInBBAInterface::Deactivate()
{
  // Is the BBA Active? If not skip shutdown
  if (!IsActivated())
    return;
  // Signal read thread to exit.
  m_read_enabled.Clear();
  m_read_thread_shutdown.Set();
  m_active = false;

  m_network_ref.Clear();
  m_arp_table.clear();
  m_upnp_httpd.close();

  // Wait for read thread to exit.
  if (m_read_thread.joinable())
    m_read_thread.join();
}

bool CEXIETHERNET::BuiltInBBAInterface::IsActivated()
{
  return m_active;
}

void CEXIETHERNET::BuiltInBBAInterface::WriteToQueue(std::vector<u8> data)
{
  m_queue_data[m_queue_write] = std::move(data);
  const u8 next_write_index = (m_queue_write + 1) & 15;
  if (next_write_index != m_queue_read)
    m_queue_write = next_write_index;
  else
    WARN_LOG_FMT(SP1, "BBA queue overrun, data might be lost");
}

bool CEXIETHERNET::BuiltInBBAInterface::WillQueueOverrun() const
{
  return ((m_queue_write + 1) & 15) == m_queue_read;
}

void CEXIETHERNET::BuiltInBBAInterface::PollData(std::size_t* datasize)
{
  for (auto& net_ref : m_network_ref)
  {
    if (net_ref.ip == 0)
      continue;

    // Check for sleeping TCP data
    if (net_ref.type == IPPROTO_TCP)
    {
      for (auto& tcp_buf : net_ref.tcp_buffers)
      {
        if (WillQueueOverrun())
          break;
        if (!tcp_buf.used || (GetTickCountStd() - tcp_buf.tick) <= 1000)
          continue;

        // Timed out packet, resend
        tcp_buf.tick = GetTickCountStd();
        WriteToQueue(tcp_buf.data);
      }
    }

    // Check for connection data
    if (*datasize == 0)
    {
      // Send it to the network buffer if empty
      const auto socket_data = TryGetDataFromSocket(&net_ref);
      if (socket_data.has_value())
      {
        *datasize = socket_data->size();
        std::memcpy(m_eth_ref->mRecvBuffer.get(), socket_data->data(), *datasize);
      }
    }
    else if (!WillQueueOverrun())
    {
      // Otherwise, enqueue it
      const auto socket_data = TryGetDataFromSocket(&net_ref);
      if (socket_data.has_value())
        WriteToQueue(std::move(*socket_data));
    }
    else
    {
      WARN_LOG_FMT(SP1, "BBA queue might overrun, can't poll more data");
      return;
    }
  }
}

void CEXIETHERNET::BuiltInBBAInterface::ReadThreadHandler(CEXIETHERNET::BuiltInBBAInterface* self)
{
  std::size_t datasize = 0;
  while (!self->m_read_thread_shutdown.IsSet())
  {
    if (datasize == 0)
    {
      // Make thread less CPU hungry
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    if (!self->m_read_enabled.IsSet())
      continue;

    u8 wp = self->m_eth_ref->page_ptr(BBA_RWP);
    const u8 rp = self->m_eth_ref->page_ptr(BBA_RRP);
    if (rp > wp)
      wp += 16;

    if ((wp - rp) >= 8)
      continue;

    std::lock_guard<std::mutex> lock(self->m_mtx);
    // process queue file first
    if (self->m_queue_read != self->m_queue_write)
    {
      datasize = self->m_queue_data[self->m_queue_read].size();
      if (datasize > BBA_RECV_SIZE)
      {
        ERROR_LOG_FMT(SP1, "Frame size is exceiding BBA capacity, frame stack might be corrupted"
                           "Killing Dolphin...");
        std::exit(0);
      }
      std::memcpy(self->m_eth_ref->mRecvBuffer.get(), self->m_queue_data[self->m_queue_read].data(),
                  datasize);
      self->m_queue_read++;
      self->m_queue_read &= 15;
    }
    else
    {
      datasize = 0;
    }

    // Check network stack references
    self->PollData(&datasize);

    // Check for new UPnP client
    self->HandleUPnPClient();

    if (datasize > 0)
    {
      u8* buffer = reinterpret_cast<u8*>(self->m_eth_ref->mRecvBuffer.get());
      Common::PacketView packet(buffer, datasize);
      const auto packet_type = packet.GetEtherType();
      if (packet_type.has_value() && packet_type == Common::IPV4_ETHERTYPE)
      {
        SetIPIdentification(buffer, datasize, ++self->m_ip_frame_id);
      }
      if (datasize < 64)
      {
        std::fill(buffer + datasize, buffer + 64, 0);
        datasize = 64;
      }
      self->m_eth_ref->mRecvBufferLength = static_cast<u32>(datasize);
      self->m_eth_ref->RecvHandlePacket();
    }
  }
}

bool CEXIETHERNET::BuiltInBBAInterface::RecvInit()
{
  m_read_thread = std::thread(ReadThreadHandler, this);
  return true;
}

void CEXIETHERNET::BuiltInBBAInterface::RecvStart()
{
  if (m_read_enabled.IsSet())
    return;
  InitUDPPort(26502);  // Kirby Air Ride
  InitUDPPort(26512);  // Mario Kart: Double Dash!! and 1080° Avalanche
  m_read_enabled.Set();
}

void CEXIETHERNET::BuiltInBBAInterface::RecvStop()
{
  m_read_enabled.Clear();
  m_network_ref.Clear();
  m_queue_read = 0;
  m_queue_write = 0;
}
}  // namespace ExpansionInterface

BbaTcpSocket::BbaTcpSocket() = default;

sf::Socket::Status BbaTcpSocket::Connect(const sf::IpAddress& dest, u16 port, u32 net_ip)
{
  sockaddr_in addr;
  addr.sin_addr.s_addr = net_ip;
  addr.sin_family = AF_INET;
  addr.sin_port = 0;
  (void)::bind(getNativeHandle(), reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
  m_connecting_state = ConnectingState::Connecting;
  return this->connect(dest, port);
}

sf::Socket::Status BbaTcpSocket::GetPeerName(sockaddr_in* addr) const
{
  socklen_t size = sizeof(*addr);
  if (getpeername(getNativeHandle(), reinterpret_cast<sockaddr*>(addr), &size) == -1)
  {
    ERROR_LOG_FMT(SP1, "getpeername failed: {}", Common::StrNetworkError());
    return sf::Socket::Status::Error;
  }
  return sf::Socket::Status::Done;
}

sf::Socket::Status BbaTcpSocket::GetSockName(sockaddr_in* addr) const
{
  socklen_t size = sizeof(*addr);
  if (getsockname(getNativeHandle(), reinterpret_cast<sockaddr*>(addr), &size) == -1)
  {
    ERROR_LOG_FMT(SP1, "getsockname failed: {}", Common::StrNetworkError());
    return sf::Socket::Status::Error;
  }
  return sf::Socket::Status::Done;
}

BbaTcpSocket::ConnectingState BbaTcpSocket::Connected(StackRef* ref)
{
  // Called by ReadThreadHandler's TryGetDataFromSocket
  switch (m_connecting_state)
  {
  case ConnectingState::Connecting:
  {
    const int fd = getNativeHandle();
    const s32 nfds = fd + 1;
    fd_set read_fds;
    fd_set write_fds;
    fd_set except_fds;
    timeval t = {0, 0};
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);
    FD_ZERO(&except_fds);
    FD_SET(fd, &write_fds);
    FD_SET(fd, &except_fds);

    if (select(nfds, &read_fds, &write_fds, &except_fds, &t) < 0)
    {
      ERROR_LOG_FMT(SP1, "Failed to get BBA socket connection state: {}",
                    Common::StrNetworkError());
      break;
    }

    if (FD_ISSET(fd, &write_fds) == 0 && FD_ISSET(fd, &except_fds) == 0)
      break;

    s32 error = 0;
    socklen_t len = sizeof(error);
    if (getsockopt(fd, SOL_SOCKET, SO_ERROR, reinterpret_cast<char*>(&error), &len) != 0)
    {
      ERROR_LOG_FMT(SP1, "Failed to get BBA socket error state: {}", Common::StrNetworkError());
      m_connecting_state = ConnectingState::Error;
      break;
    }

    if (error != 0)
    {
      ERROR_LOG_FMT(SP1, "BBA connect failed (err={}): {}", error,
                    Common::DecodeNetworkError(error));
      m_connecting_state = ConnectingState::Error;
      break;
    }

    // Get peername to ensure the socket is connected
    sockaddr_in peer;
    socklen_t peer_len = sizeof(peer);
    if (getpeername(fd, reinterpret_cast<sockaddr*>(&peer), &peer_len) != 0)
    {
      ERROR_LOG_FMT(SP1, "BBA connect failed to get peername: {}", Common::StrNetworkError());
      m_connecting_state = ConnectingState::Error;
      break;
    }

    // Create the resulting SYN ACK packet
    m_connecting_state = ConnectingState::Connected;
    INFO_LOG_FMT(SP1, "BBA connect succeeded");

    Common::TCPPacket result(ref->bba_mac, ref->my_mac, ref->from, ref->to, ref->seq_num,
                             ref->ack_num, TCP_FLAG_SIN | TCP_FLAG_ACK);

    result.tcp_options = {
        0x02, 0x04, 0x05, 0xb4,  // Maximum segment size: 1460 bytes
        0x01, 0x01, 0x01, 0x01   // NOPs
    };

    ref->seq_num++;
    ref->tcp_buffers[0].data = result.Build();
    ref->tcp_buffers[0].seq_id = ref->seq_num - 1;
    ref->tcp_buffers[0].tick = GetTickCountStd() - 900;  // delay
    ref->tcp_buffers[0].used = true;

    break;
  }
  default:
    break;
  }
  return m_connecting_state;
}

BbaUdpSocket::BbaUdpSocket() = default;

sf::Socket::Status BbaUdpSocket::Bind(u16 port, u32 net_ip)
{
  if (port != Common::SSDP_PORT)
    return this->bind(port, sf::IpAddress(ntohl(net_ip)));

  // Handle SSDP multicast
  create();
  const int on = 1;
  if (setsockopt(getNativeHandle(), SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&on),
                 sizeof(on)) != 0)
  {
    ERROR_LOG_FMT(SP1, "setsockopt failed to reuse SSDP address: {}", Common::StrNetworkError());
  }
#ifdef SO_REUSEPORT
  if (setsockopt(getNativeHandle(), SOL_SOCKET, SO_REUSEPORT, reinterpret_cast<const char*>(&on),
                 sizeof(on)) != 0)
  {
    ERROR_LOG_FMT(SP1, "setsockopt failed to reuse SSDP port: {}", Common::StrNetworkError());
  }
#endif
  if (const char loop = 1;
      setsockopt(getNativeHandle(), IPPROTO_IP, IP_MULTICAST_LOOP, &loop, sizeof(loop)) != 0)
  {
    ERROR_LOG_FMT(SP1, "setsockopt failed to set SSDP loopback: {}", Common::StrNetworkError());
  }

  // sf::UdpSocket::bind will close the socket and get rid of its options
  sockaddr_in addr;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(Common::SSDP_PORT);
  Common::ScopeGuard error_guard([this] { close(); });
  if (::bind(getNativeHandle(), reinterpret_cast<const sockaddr*>(&addr), sizeof(addr)) != 0)
  {
    WARN_LOG_FMT(SP1, "bind with SSDP port and INADDR_ANY failed: {}", Common::StrNetworkError());
    addr.sin_addr.s_addr = net_ip;
    if (::bind(getNativeHandle(), reinterpret_cast<const sockaddr*>(&addr), sizeof(addr)) != 0)
    {
      ERROR_LOG_FMT(SP1, "bind with SSDP port failed: {}", Common::StrNetworkError());
      return sf::Socket::Status::Error;
    }
  }
  else
  {
    addr.sin_addr.s_addr = net_ip;  // Set this here for IP_MULTICAST_IF
  }
  INFO_LOG_FMT(SP1, "SSDP bind successful");

  // Bind to the right interface
  if (setsockopt(getNativeHandle(), IPPROTO_IP, IP_MULTICAST_IF,
                 reinterpret_cast<const char*>(&addr.sin_addr), sizeof(addr.sin_addr)) != 0)
  {
    ERROR_LOG_FMT(SP1, "setsockopt failed to bind to the network interface: {}",
                  Common::StrNetworkError());
    return sf::Socket::Status::Error;
  }

  // Subscribe to the SSDP multicast group
  // NB: Other groups aren't supported because of HLE
  ip_mreq mreq;
  mreq.imr_multiaddr.s_addr = std::bit_cast<u32>(Common::IP_ADDR_SSDP);
  mreq.imr_interface.s_addr = net_ip;
  if (setsockopt(getNativeHandle(), IPPROTO_IP, IP_ADD_MEMBERSHIP,
                 reinterpret_cast<const char*>(&mreq), sizeof(mreq)) != 0)
  {
    ERROR_LOG_FMT(SP1, "setsockopt failed to subscribe to SSDP multicast group: {}",
                  Common::StrNetworkError());
    return sf::Socket::Status::Error;
  }

  error_guard.Dismiss();
  INFO_LOG_FMT(SP1, "SSDP multicast membership successful");
  return sf::Socket::Status::Done;
}

StackRef* NetworkRef::GetAvailableSlot(u16 port)
{
  if (port > 0)  // existing connection?
  {
    for (auto& ref : m_stacks)
    {
      if (ref.ip != 0 && ref.local == port)
        return &ref;
    }
  }
  for (auto& ref : m_stacks)
  {
    if (ref.ip == 0)
      return &ref;
  }
  return nullptr;
}

StackRef* NetworkRef::GetTCPSlot(u16 src_port, u16 dst_port, u32 ip)
{
  for (auto& ref : m_stacks)
  {
    if (ref.ip == ip && ref.remote == dst_port && ref.local == src_port)
    {
      return &ref;
    }
  }
  return nullptr;
}

void NetworkRef::Clear()
{
  for (auto& ref : m_stacks)
  {
    if (ref.ip != 0)
    {
      ref.type == IPPROTO_TCP ? ref.tcp_socket.disconnect() : ref.udp_socket.unbind();
    }
    ref.ip = 0;
  }
}
