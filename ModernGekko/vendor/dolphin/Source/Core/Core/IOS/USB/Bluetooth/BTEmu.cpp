// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/IOS/USB/Bluetooth/BTEmu.h"

#include <algorithm>
#include <cstring>
#include <memory>
#include <string>

#include "Common/Assert.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Core/Core.h"
#include "Core/CoreTiming.h"
#include "Core/Debugger/Debugger_SymbolMap.h"
#include "Core/HW/Memmap.h"
#include "Core/HW/SystemTimers.h"
#include "Core/HW/Wiimote.h"
#include "Core/HW/WiimoteEmu/DesiredWiimoteState.h"
#include "Core/IOS/Device.h"
#include "Core/IOS/IOS.h"
#include "Core/Movie.h"
#include "Core/NetPlay/NetPlayClient.h"
#include "Core/NetPlay/NetPlayProto.h"
#include "Core/Wii/SysConf.h"
#include "Core/System.h"
#include "InputCommon/ControllerInterface/ControllerInterface.h"

namespace IOS::HLE
{
SQueuedEvent::SQueuedEvent(u32 size_, u16 handle) : size(size_), connection_handle(handle)
{
  if (size > 1024)
    PanicAlertFmt("SQueuedEvent: The size is too large.");
}


void BluetoothEmuDevice::DoState(PointerWrap& p)
{
  bool passthrough_bluetooth = false;
  p.Do(passthrough_bluetooth);
  if (passthrough_bluetooth && p.IsReadMode())
  {
    Core::DisplayMessage("State needs Bluetooth passthrough to be enabled. Aborting load.", 4000);
    p.SetVerifyMode();
    return;
  }

  Device::DoState(p);
  p.Do(m_controller_bd);
  DoStateForMessage(GetEmulationKernel(), p, m_hci_endpoint);
  DoStateForMessage(GetEmulationKernel(), p, m_acl_endpoint);
  p.Do(m_last_ticks);
  p.DoArray(m_packet_count);
  p.Do(m_scan_enable);
  p.Do(m_event_queue);
  m_acl_pool.DoState(p);

  for (unsigned int i = 0; i < MAX_BBMOTES; i++)
    m_wiimotes[i]->DoState(p);
}


std::optional<IPCReply> BluetoothEmuDevice::Close(u32 fd)
{
  // Clean up state
  m_scan_enable = 0;
  m_last_ticks = 0;
  memset(m_packet_count, 0, sizeof(m_packet_count));
  m_hci_endpoint.reset();
  m_acl_endpoint.reset();

  return Device::Close(fd);
}

std::optional<IPCReply> BluetoothEmuDevice::IOCtlV(const IOCtlVRequest& request)
{
  bool send_reply = true;
  switch (request.request)
  {
  case USB::IOCTLV_USBV0_CTRLMSG:  // HCI command is received from the stack
  {
    // Replies are generated inside
    ExecuteHCICommandMessage(USB::V0CtrlMessage(GetEmulationKernel(), request));
    send_reply = false;
    break;
  }

  case USB::IOCTLV_USBV0_BLKMSG:
  {
    const USB::V0BulkMessage ctrl{GetEmulationKernel(), request};
    switch (ctrl.endpoint)
    {
    case ACL_DATA_OUT:  // ACL data is received from the stack
    {
      auto& system = GetSystem();
      auto& memory = system.GetMemory();

      // This is the ACL datapath from CPU to Wii Remote
      const auto* acl_header = reinterpret_cast<hci_acldata_hdr_t*>(
          memory.GetPointerForRange(ctrl.data_address, sizeof(hci_acldata_hdr_t)));

      DEBUG_ASSERT(HCI_BC_FLAG(acl_header->con_handle) == HCI_POINT2POINT);
      DEBUG_ASSERT(HCI_PB_FLAG(acl_header->con_handle) == HCI_PACKET_START);

      SendToDevice(HCI_CON_HANDLE(acl_header->con_handle),
                   memory.GetPointerForRange(ctrl.data_address + sizeof(hci_acldata_hdr_t),
                                             acl_header->length),
                   acl_header->length);
      break;
    }
    case ACL_DATA_IN:  // We are given an ACL buffer to fill
    {
      m_acl_endpoint = std::make_unique<USB::V0BulkMessage>(GetEmulationKernel(), request);
      DEBUG_LOG_FMT(IOS_WIIMOTE, "ACL_DATA_IN: {:#010x}", request.address);
      send_reply = false;
      break;
    }
    default:
      DEBUG_ASSERT_MSG(IOS_WIIMOTE, 0, "Unknown USB::IOCTLV_USBV0_BLKMSG: {:#x}", ctrl.endpoint);
    }
    break;
  }

  case USB::IOCTLV_USBV0_INTRMSG:
  {
    const USB::V0IntrMessage ctrl{GetEmulationKernel(), request};
    if (ctrl.endpoint == HCI_EVENT)  // We are given a HCI buffer to fill
    {
      m_hci_endpoint = std::make_unique<USB::V0IntrMessage>(GetEmulationKernel(), request);
      DEBUG_LOG_FMT(IOS_WIIMOTE, "HCI_EVENT: {:#010x}", request.address);
      send_reply = false;
    }
    else
    {
      DEBUG_ASSERT_MSG(IOS_WIIMOTE, 0, "Unknown USB::IOCTLV_USBV0_INTRMSG: {:#x}", ctrl.endpoint);
    }
    break;
  }

  default:
    request.DumpUnknown(GetSystem(), GetDeviceName(), Common::Log::LogType::IOS_WIIMOTE);
  }

  if (!send_reply)
    return std::nullopt;
  return IPCReply(IPC_SUCCESS);
}

// Here we handle the USB::IOCTLV_USBV0_BLKMSG Ioctlv
void BluetoothEmuDevice::SendToDevice(u16 connection_handle, u8* data, u32 size)
{
  WiimoteDevice* wiimote = AccessWiimote(connection_handle);
  if (wiimote == nullptr)
    return;

  DEBUG_LOG_FMT(IOS_WIIMOTE, "Send ACL Packet to ConnectionHandle {:#06x}", connection_handle);
  IncDataPacket(connection_handle);
  wiimote->ExecuteL2capCmd(data, size);
}

void BluetoothEmuDevice::IncDataPacket(u16 connection_handle)
{
  m_packet_count[GetWiimoteNumberFromConnectionHandle(connection_handle)]++;
}

// Here we send ACL packets to CPU. They will consist of header + data.
// The header is for example 07 00 41 00 which means size 0x0007 and channel 0x0041.
void BluetoothEmuDevice::SendACLPacket(const bdaddr_t& source, const u8* data, u32 size)
{
  const u16 connection_handle = GetConnectionHandle(source);

  DEBUG_LOG_FMT(IOS_WIIMOTE, "ACL packet from {:x} ready to send to stack...", connection_handle);

  if (m_acl_endpoint && !m_hci_endpoint && m_event_queue.empty())
  {
    DEBUG_LOG_FMT(IOS_WIIMOTE, "ACL endpoint valid, sending packet to {:08x}",
                  m_acl_endpoint->ios_request.address);

    auto& system = GetSystem();
    auto& memory = system.GetMemory();

    hci_acldata_hdr_t* header = reinterpret_cast<hci_acldata_hdr_t*>(
        memory.GetPointerForRange(m_acl_endpoint->data_address, sizeof(hci_acldata_hdr_t)));
    header->con_handle = HCI_MK_CON_HANDLE(connection_handle, HCI_PACKET_START, HCI_POINT2POINT);
    header->length = size;

    // Write the packet to the buffer
    memcpy(reinterpret_cast<u8*>(header) + sizeof(hci_acldata_hdr_t), data, header->length);

    GetEmulationKernel().EnqueueIPCReply(m_acl_endpoint->ios_request,
                                         sizeof(hci_acldata_hdr_t) + size);
    m_acl_endpoint.reset();
  }
  else
  {
    DEBUG_LOG_FMT(IOS_WIIMOTE, "ACL endpoint not currently valid, queuing...");
    m_acl_pool.Store(data, size, connection_handle);
  }
}

// These messages are sent from the Wii Remote to the game, for example RequestConnection()
// or ConnectionComplete().
//
// Our IOS is so efficient that we could fill the buffer immediately
// rather than enqueue it to some other memory and this will do good for StateSave
void BluetoothEmuDevice::AddEventToQueue(const SQueuedEvent& event)
{
  DEBUG_LOG_FMT(IOS_WIIMOTE, "HCI event {:x} completed...",
                ((hci_event_hdr_t*)event.buffer)->event);

  if (m_hci_endpoint)
  {
    if (m_event_queue.empty())  // fast path :)
    {
      DEBUG_LOG_FMT(IOS_WIIMOTE, "HCI endpoint valid, sending packet to {:08x}",
                    m_hci_endpoint->ios_request.address);
      m_hci_endpoint->FillBuffer(event.buffer, event.size);

      // Send a reply to indicate HCI buffer is filled
      GetEmulationKernel().EnqueueIPCReply(m_hci_endpoint->ios_request, event.size);
      m_hci_endpoint.reset();
    }
    else  // push new one, pop oldest
    {
      DEBUG_LOG_FMT(IOS_WIIMOTE, "HCI endpoint not currently valid, queueing ({})...",
                    m_event_queue.size());
      m_event_queue.push_back(event);
      const SQueuedEvent& queued_event = m_event_queue.front();
      DEBUG_LOG_FMT(IOS_WIIMOTE,
                    "HCI event {:x} "
                    "being written from queue ({}) to {:08x}...",
                    ((hci_event_hdr_t*)queued_event.buffer)->event, m_event_queue.size() - 1,
                    m_hci_endpoint->ios_request.address);
      m_hci_endpoint->FillBuffer(queued_event.buffer, queued_event.size);

      // Send a reply to indicate HCI buffer is filled
      GetEmulationKernel().EnqueueIPCReply(m_hci_endpoint->ios_request, queued_event.size);
      m_hci_endpoint.reset();
      m_event_queue.pop_front();
    }
  }
  else
  {
    DEBUG_LOG_FMT(IOS_WIIMOTE, "HCI endpoint not currently valid, queuing ({})...",
                  m_event_queue.size());
    m_event_queue.push_back(event);
  }
}

void BluetoothEmuDevice::Update()
{
  // check HCI queue
  if (!m_event_queue.empty() && m_hci_endpoint)
  {
    // an endpoint has become available, and we have a stored response.
    const SQueuedEvent& event = m_event_queue.front();
    DEBUG_LOG_FMT(IOS_WIIMOTE, "HCI event {:x} being written from queue ({}) to {:08x}...",
                  ((hci_event_hdr_t*)event.buffer)->event, m_event_queue.size() - 1,
                  m_hci_endpoint->ios_request.address);
    m_hci_endpoint->FillBuffer(event.buffer, event.size);

    // Send a reply to indicate HCI buffer is filled
    GetEmulationKernel().EnqueueIPCReply(m_hci_endpoint->ios_request, event.size);
    m_hci_endpoint.reset();
    m_event_queue.pop_front();
  }

  // check ACL queue
  if (!m_acl_pool.IsEmpty() && m_acl_endpoint && m_event_queue.empty())
  {
    m_acl_pool.WriteToEndpoint(*m_acl_endpoint);
    m_acl_endpoint.reset();
  }

  for (auto& wiimote : m_wiimotes)
    wiimote->Update();

  const u64 interval = GetSystem().GetSystemTimers().GetTicksPerSecond() / Wiimote::UPDATE_FREQ;
  auto& core_timing = GetSystem().GetCoreTiming();
  const u64 now = core_timing.GetTicks();

  if (now - m_last_ticks > interval)
  {
    // Throttle before Wii Remote update so input is taken just before needed. (lower input latency)
    core_timing.Throttle(now);
    g_controller_interface.SetCurrentInputChannel(ciface::InputChannel::Bluetooth);
    g_controller_interface.UpdateInput();

    std::array<WiimoteEmu::DesiredWiimoteState, MAX_BBMOTES> wiimote_states;
    std::array<WiimoteDevice::NextUpdateInputCall, MAX_BBMOTES> next_call;

    for (size_t i = 0; i < m_wiimotes.size(); ++i)
      next_call[i] = m_wiimotes[i]->PrepareInput(&wiimote_states[i]);

    if (NetPlay::IsNetPlayRunning())
    {
      std::array<WiimoteEmu::SerializedWiimoteState, MAX_BBMOTES> serialized;
      std::array<NetPlay::NetPlayClient::WiimoteDataBatchEntry, MAX_BBMOTES> batch;
      size_t batch_count = 0;
      for (size_t i = 0; i < 4; ++i)
      {
        if (next_call[i] == WiimoteDevice::NextUpdateInputCall::None)
          continue;
        serialized[i] = WiimoteEmu::SerializeDesiredState(wiimote_states[i]);
        batch[batch_count].state = &serialized[i];
        batch[batch_count].wiimote = static_cast<int>(i);
        ++batch_count;
      }

      if (batch_count > 0)
      {
        NetPlay::NetPlay_GetWiimoteData(
            std::span<NetPlay::NetPlayClient::WiimoteDataBatchEntry>(batch.data(), batch_count));

        for (size_t i = 0; i < batch_count; ++i)
        {
          const int wiimote = batch[i].wiimote;
          if (!WiimoteEmu::DeserializeDesiredState(&wiimote_states[wiimote], serialized[wiimote]))
            PanicAlertFmtT("Received invalid Wii Remote data from Netplay.");
        }
      }
    }

    auto& movie = Core::System::GetInstance().GetMovie();
    for (int i = 0; i != MAX_WIIMOTES; ++i)
    {
      if (next_call[i] == WiimoteDevice::NextUpdateInputCall::None)
        continue;

      movie.PlayWiimote(i, &wiimote_states[i]);
      movie.CheckWiimoteStatus(i, wiimote_states[i]);
    }

    for (size_t i = 0; i < m_wiimotes.size(); ++i)
      m_wiimotes[i]->UpdateInput(next_call[i], wiimote_states[i]);

    m_last_ticks = now;
  }

  SendEventNumberOfCompletedPackets();
}

void BluetoothEmuDevice::ACLPool::Store(const u8* data, const u16 size, const u16 conn_handle)
{
  if (m_queue.size() >= 100)
  {
    // Many simultaneous exchanges of ACL packets tend to cause the queue to fill up.
    ERROR_LOG_FMT(IOS_WIIMOTE, "ACL queue size reached 100 - current packet will be dropped!");
    return;
  }

  DEBUG_ASSERT_MSG(IOS_WIIMOTE, size < ACL_PKT_SIZE, "ACL packet too large for pool");

  m_queue.push_back(Packet());
  auto& packet = m_queue.back();

  std::copy_n(data, size, packet.data);
  packet.size = size;
  packet.conn_handle = conn_handle;
}

void BluetoothEmuDevice::ACLPool::WriteToEndpoint(const USB::V0BulkMessage& endpoint)
{
  auto& packet = m_queue.front();

  const u8* const data = packet.data;
  const u16 size = packet.size;
  const u16 conn_handle = packet.conn_handle;

  DEBUG_LOG_FMT(IOS_WIIMOTE, "ACL packet being written from queue to {:08x}",
                endpoint.ios_request.address);

  auto& system = m_ios.GetSystem();
  auto& memory = system.GetMemory();

  hci_acldata_hdr_t* header = (hci_acldata_hdr_t*)memory.GetPointerForRange(
      endpoint.data_address, sizeof(hci_acldata_hdr_t));
  header->con_handle = HCI_MK_CON_HANDLE(conn_handle, HCI_PACKET_START, HCI_POINT2POINT);
  header->length = size;

  // Write the packet to the buffer
  std::copy_n(data, size, (u8*)header + sizeof(hci_acldata_hdr_t));

  m_queue.pop_front();

  m_ios.EnqueueIPCReply(endpoint.ios_request, sizeof(hci_acldata_hdr_t) + size);
}
}  // namespace IOS::HLE
