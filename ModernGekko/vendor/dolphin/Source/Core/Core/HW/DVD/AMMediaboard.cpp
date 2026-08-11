// Copyright 2025 Dolphin Emulator Project
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

// Written via Write_U32_Swap (LE) because PPC display code reads with lwz + manual bswap32.
static constexpr u32 TEST_OK_WORD0 = 0x54455354;  // "TEST"
static constexpr u32 TEST_OK_WORD1 = 0x204F4B00;  // " OK\0"

MediaBoardRange::MediaBoardRange(u32 start_, u32 size_, std::span<u8> buffer_)
    : start{start_}, end{start_ + std::min(size_, u32(buffer_.size()))}, buffer{buffer_.data()},
      buffer_size{buffer_.size()}
{
  if (size_ <= buffer_.size())
    return;
  WARN_LOG_FMT(AMMEDIABOARD,
               "Invalid MediaBoardRange: start=0x{:08x}, size=0x{:06x}, buffer_size=0x{:06x}",
               start, size_, buffer_.size());
}

using Common::SEND_FLAGS;




static bool s_firmware_map = false;
static bool s_test_menu = false;
std::array<u32, 3> s_timeouts = {20000, 20000, 20000};
u32 s_last_error = SSC_SUCCESS;

u32 s_gcam_key_a = 0;
u32 s_gcam_key_b = 0;
u32 s_gcam_key_c = 0;

static File::IOFile s_netcfg;
static File::IOFile s_netctrl;
static File::IOFile s_extra;
static File::IOFile s_backup;
static File::IOFile s_dimm;

static std::unique_ptr<DiscIO::BlobReader> s_dimm_disc;

static std::array<u8, 0x200000> s_firmware;
std::array<u32, 0xc0> s_media_buffer_32;
u8* const s_media_buffer = reinterpret_cast<u8*>(s_media_buffer_32.data());

// Both Execute paths write responses to s_media_buffer, so one overwrites the other.
// Keep separate copies so each path's DMA Read returns its own response.
static std::array<u32, 8> s_exec1_last_response{};
static std::array<u32, 8> s_exec2_last_response{};

static CoreTiming::EventType* s_et_test_hw_phase2 = nullptr;
std::array<u8, 0x4ffe00> s_network_command_buffer;
std::array<u8, 0x80000> s_network_buffer;
static std::array<u8, 0x1000> s_allnet_buffer;
static std::array<u8, 0x8500> s_allnet_settings;

Common::IPAddress s_game_modified_ip_address;

// Fake loading the game to have a chance to enter test mode
static u32 s_board_status = LoadingGameProgram;
static u32 s_load_progress = 80;



constexpr char s_allnet_reply[] = {
    "uri=http://"
    "sega.com&host=sega.com&nickname=sega&name=sega&year=2025&month=08&day=16&hour=21&minute=10&"
    "second=12&place_id=1234&setting=0x123&region0=jap&region_name0=japan&region_name1=usa&region_"
    "name2=asia&region_name3=export&end"};

static const MediaBoardRange s_mediaboard_ranges[] = {
    {DIMMCommandVersion1, 0x40, Common::AsWritableU8Span(s_media_buffer_32)},
    {DIMMCommandVersion2, 0x60, Common::AsWritableU8Span(s_media_buffer_32)},
    {DIMMCommandVersion2_2, 0x220, Common::AsWritableU8Span(s_media_buffer_32)},
    {NetworkCommandAddress1, 0x1040, s_network_command_buffer},
    {NetworkCommandAddress2, 0x40000, s_network_command_buffer},  // TODO: Guesswork, verify this.
    {NetworkBufferAddress1, 0x10000, s_network_buffer},
    {NetworkBufferAddress2, 0x10000, s_network_buffer},
    {NetworkBufferAddress3, 0x50000, s_network_buffer},
    {NetworkBufferAddress4, 0xc0000, s_network_buffer},  // TODO: size bigger than buffer's?
    {NetworkBufferAddress5, 0x10000, s_network_buffer},
    {AllNetSettings, 0x8000, s_allnet_settings},
    {AllNetBuffer, 0x1000, s_allnet_buffer},
};

std::span<u8> GetSpanForMediaboardAddress(u32 address)
{
  for (const auto& range : s_mediaboard_ranges)
  {
    if (address >= range.start && address < range.end)
      return std::span{range.buffer, range.buffer_size}.subspan(address - range.start);
  }

  return {};
}

static const std::unordered_map<u16, GameType> s_game_map = {
    {0x4747, FZeroAX},
    {0x4841, FZeroAXMonster},
    {0x4B50, MarioKartGP},
    {0x4B5A, MarioKartGP},
    {0x4E4A, MarioKartGP2},
    {0x4E4C, MarioKartGP2},
    {0x454A, VirtuaStriker3},
    {0x4559, VirtuaStriker3},
    {0x4C4A, VirtuaStriker4_2006},
    {0x4C4B, VirtuaStriker4_2006},
    {0x4C4C, VirtuaStriker4_2006},
    {0x484A, VirtuaStriker4},
    {0x484E, VirtuaStriker4},
    {0x485A, VirtuaStriker4},
    {0x4A41, VirtuaStriker4},
    {0x4A4A, VirtuaStriker4},
    {0x4658, KeyOfAvalon},
    {0x4A4E, KeyOfAvalon},
    {0x4758, GekitouProYakyuu},
    {0x5342, VirtuaStriker3},
    {0x3132, VirtuaStriker3},
    {0x454C, VirtuaStriker3},
    {0x3030, FirmwareUpdate},
};

// Sockets FDs are required to go from 0 to 63.
// Games use the FD as indexes so we have to workaround it.

std::array<SOCKET, SOCKET_FD_MAX> s_sockets;


u32 s_next_valid_fd = FIRST_VALID_FD;

// Flag: next 128-byte DMA Read from the media buffer should return network config
static bool s_netconfig_read_pending = false;




std::string_view GetSafeString(u32 offset, u32 max_length)
{
  const auto str_span = GetSpanForMediaboardAddress(offset);

  if (str_span.empty())
    return {};

  // Don't exceed max_length or end of buffer.
  const auto adjusted_length = std::min<std::size_t>(max_length, str_span.size());
  const auto length = strnlen(reinterpret_cast<char*>(str_span.data()), adjusted_length);

  return {reinterpret_cast<char*>(str_span.data()), length};
}

bool SafeCopyToEmu(Memory::MemoryManager& memory, u32 address, const u8* source,
                          u64 source_size, u32 offset, u32 length)
{
  if (offset > source_size || length > source_size - offset)
  {
    ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Read overflow: offset=0x{:08x}, length={}, source_size={}",
                  offset, length, source_size);
    return false;
  }

  auto span = memory.GetSpanForAddress(address);
  if (length > span.size())
  {
    ERROR_LOG_FMT(AMMEDIABOARD,
                  "GC-AM: Memory buffer too small: address=0x{:08x}, length={}, span={}", address,
                  length, span.size());
    return false;
  }

  memory.CopyToEmu(address, source + offset, length);
  return true;
}

bool SafeCopyFromEmu(Memory::MemoryManager& memory, u8* destination, u32 address,
                            u64 destination_size, u32 offset, u32 length)
{
  if (offset > destination_size || length > destination_size - offset)
  {
    ERROR_LOG_FMT(AMMEDIABOARD,
                  "GC-AM: Write overflow: offset=0x{:08x}, length={}, destination_size={}", offset,
                  length, destination_size);
    return false;
  }

  auto span = memory.GetSpanForAddress(address);
  if (length > span.size())
  {
    ERROR_LOG_FMT(AMMEDIABOARD,
                  "GC-AM: Memory buffer too small: address=0x{:08x}, length={}, span={}", address,
                  length, span.size());
    return false;
  }

  memory.CopyFromEmu(destination + offset, address, length);
  return true;
}



static inline void PrintMBBuffer(u32 address, u32 length)
{
  const auto& system = Core::System::GetInstance();
  auto& memory = system.GetMemory();

  for (u32 i = 0; i < length; i += 0x10)
  {
    DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: {:08x} {:08x} {:08x} {:08x}", memory.Read_U32(address + i),
                  memory.Read_U32(address + i + 4), memory.Read_U32(address + i + 8),
                  memory.Read_U32(address + i + 12));
  }
}

void FirmwareMap(bool on)
{
  s_firmware_map = on;
}



static File::IOFile OpenOrCreateFile(const std::string& filename)
{
  // Try opening for read/write first
  if (File::Exists(filename))
    return File::IOFile(filename, "rb+");

  // Create new file
  return File::IOFile(filename, "wb+");
}

static void TestHwPhase2Callback(Core::System& system, u64 userdata, s64 cycles_late)
{
  const bool is_exec2 = (userdata != 0);
  auto& response = is_exec2 ? s_exec2_last_response : s_exec1_last_response;

  response.fill(0);
  response[0] = 0x03020000;  // sub_cmd=0x02, cmd_class=0x03
  response[1] = 2;           // testStatus = GOOD
  response[2] = 100;         // checkProgress

  DEBUG_LOG_FMT(AMMEDIABOARD,
                "GC-AM: TestHardware phase 2 ({}): sending result response "
                "(testStatus=2, checkProgress=100)",
                is_exec2 ? "Execute2" : "Execute1");
  ExpansionInterface::GenerateInterrupt(is_exec2 ? 0x10 : 0x04);
}

void Init()
{
  s_media_buffer_32.fill(0);
  s_exec1_last_response.fill(0);
  s_exec2_last_response.fill(0);
  s_network_buffer.fill(0);
  s_network_command_buffer.fill(0);
  s_firmware.fill(-1);
  s_sockets.fill(SOCKET_ERROR);
  s_allnet_buffer.fill(0);
  s_allnet_settings.fill(0);

  s_game_modified_ip_address = {};
  s_netconfig_read_pending = false;

  auto& core_timing = Core::System::GetInstance().GetCoreTiming();
  s_et_test_hw_phase2 = core_timing.RegisterEvent("AMMediaboardTestHwPhase2", TestHwPhase2Callback);

  s_board_status = LoadingGameProgram;
  s_load_progress = 80;

  s_firmware_map = false;
  s_test_menu = false;

  s_last_error = SSC_SUCCESS;
  s_next_valid_fd = FIRST_VALID_FD;

  s_gcam_key_a = 0;
  s_gcam_key_b = 0;
  s_gcam_key_c = 0;

  const std::string base_path = File::GetUserPath(D_TRIUSER_IDX);

  s_netcfg = OpenOrCreateFile(base_path + "trinetcfg.bin");
  s_netctrl = OpenOrCreateFile(base_path + "trinetctrl.bin");
  s_extra = OpenOrCreateFile(base_path + "triextra.bin");
  s_dimm = OpenOrCreateFile(base_path + "tridimm_" + SConfig::GetInstance().GetGameID() + ".bin");
  s_backup = OpenOrCreateFile(base_path + "backup_" + SConfig::GetInstance().GetGameID() + ".bin");

  if (!s_netcfg.IsOpen())
    PanicAlertFmt("Failed to open/create: {}", base_path + "trinetcfg.bin");
  if (!s_netctrl.IsOpen())
    PanicAlertFmt("Failed to open/create: {}", base_path + "trinetctrl.bin");
  if (!s_extra.IsOpen())
    PanicAlertFmt("Failed to open/create: {}", base_path + "triextra.bin");
  if (!s_dimm.IsOpen())
    PanicAlertFmt("Failed to open/create: {}", base_path + "tridimm.bin");
  if (!s_backup.IsOpen())
    PanicAlertFmt("Failed to open/create: {}", base_path + "backup.bin");

  // This is the firmware for the Triforce
  const std::string sega_boot_filename = base_path + "segaboot.gcm";

  if (!File::Exists(sega_boot_filename))
  {
    PanicAlertFmt("Failed to open segaboot.gcm({}), which is required for test menus.",
                  sega_boot_filename.c_str());
    return;
  }

  File::IOFile sega_boot(sega_boot_filename, "rb+");
  if (!sega_boot.IsOpen())
  {
    PanicAlertFmt("Failed to read: {}", sega_boot_filename);
    return;
  }

  const u64 length = std::min<u64>(sega_boot.GetSize(), sizeof(s_firmware));
  sega_boot.ReadBytes(s_firmware.data(), length);

  s_test_menu = true;
}

void InitDIMM(const DiscIO::Volume& volume)
{
  // Load game into RAM, like on the actual Triforce.
  s_dimm_disc = DiscIO::CreateCachedBlobReader(volume.GetBlobReader().CopyReader());
}


std::optional<ParsedIPRedirection> ParseIPRedirection(std::string_view str)
{
  // Everything after a space is the description.
  const auto ip_pair_str = std::string_view{str.begin(), std::ranges::find(str, ' ')};

  const auto parts = SplitStringIntoArray<2>(ip_pair_str, '=');
  if (!parts.has_value())
    return std::nullopt;

  const bool have_description = ip_pair_str.size() != str.size();

  return ParsedIPRedirection{
      .original = (*parts)[0],
      .replacement = (*parts)[1],
      .description = have_description ? str.substr(ip_pair_str.size() + 1) : std::string_view{},
  };
}

// Caller should check if it matches first!
Common::IPv4Port IPRedirection::Apply(Common::IPv4Port subject) const
{
  // This logic could probably be better.
  // Ranges of different sizes will be weird in general.

  const auto replacement_first_ip_u32 = replacement.first.GetIPAddressValue();
  const auto ip_count = 1u + u64(replacement.last.GetIPAddressValue()) - replacement_first_ip_u32;
  const auto result_ip =
      u32(replacement_first_ip_u32 +
          ((subject.GetIPAddressValue() - original.first.GetIPAddressValue()) % ip_count));

  subject.ip_address = std::bit_cast<Common::IPAddress>(Common::BigEndianValue{result_ip});

  const auto replacement_first_port_u16 = replacement.first.GetPortValue();
  const auto port_count = 1u + u32(replacement.last.GetPortValue()) - replacement_first_port_u16;

  // If the replacement includes all ports then we don't alter the port.
  // This allows "10.0.0.1:80-88=10.0.0.2" to have the expected behavior.
  if (port_count != 65536u)
  {
    const auto result_port_u16 =
        u16(replacement_first_port_u16 +
            ((subject.GetPortValue() - original.first.GetPortValue()) % port_count));
    subject.port = std::bit_cast<u16>(Common::BigEndianValue{result_port_u16});
  }

  return subject;
}

Common::IPv4Port IPRedirection::Reverse(Common::IPv4Port subject) const
{
  // Low effort implementation..
  return IPRedirection{.original = replacement, .replacement = original}.Apply(subject);
}

std::string IPRedirection::ToString() const
{
  return fmt::format("{}={}", original.ToString(), replacement.ToString());
}

IPRedirections GetIPRedirections()
{
  IPRedirections result;

  const auto ip_redirections_str = Config::Get(Config::MAIN_TRIFORCE_IP_REDIRECTIONS);
  for (auto&& ip_pair : ip_redirections_str | std::views::split(','))
  {
    const auto ip_pair_str = std::string_view{ip_pair};
    const auto parts = ParseIPRedirection(ip_pair_str);
    if (parts.has_value())
    {
      const auto original = Common::StringToIPv4PortRange(parts->original);
      const auto replacement = Common::StringToIPv4PortRange(parts->replacement);

      if (original.has_value() && replacement.has_value())
      {
        result.emplace_back(*original, *replacement);
        continue;
      }

      ERROR_LOG_FMT(AMMEDIABOARD, "Bad IP redirection string: {}", ip_pair_str);
    }
  }

  return result;
}


static void FileWriteData(Memory::MemoryManager& memory, File::IOFile* file, u32 seek_pos,
                          u32 address, std::size_t length)
{
  auto span = memory.GetSpanForAddress(address);
  if (length <= span.size())
  {
    file->Seek(seek_pos, File::SeekOrigin::Begin);
    file->WriteBytes(span.data(), length);
    file->Flush();
  }
  else
  {
    ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Write overflow: address=0x{:08x}, length={}, span={}",
                  address, length, span.size());
  }
}

static void FileReadData(Memory::MemoryManager& memory, File::IOFile* file, u32 seek_pos,
                         u32 address, std::size_t length)
{
  auto span = memory.GetSpanForAddress(address);
  if (length <= span.size())
  {
    file->Seek(seek_pos, File::SeekOrigin::Begin);
    file->ReadBytes(span.data(), length);
  }
  else
  {
    ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Read overflow: address=0x{:08x}, length={}, span={}",
                  address, length, span.size());
  }
}

u32 ExecuteCommand(std::array<u32, 3>& dicmd_buf, u32* diimm_buf, u32 address, u32 length)
{
  auto& system = Core::System::GetInstance();
  auto& memory = system.GetMemory();

  DecryptCommand(dicmd_buf, memory, system);

  const u32 command = dicmd_buf[0] << 24;
  const u32 offset = dicmd_buf[1] << 2;

  DEBUG_LOG_FMT(AMMEDIABOARD,
                "GC-AM: {:08x} {:08x} DMA=addr:{:08x},len:{:08x} Keys: {:08x} {:08x} {:08x}",
                command, offset, address, length, s_gcam_key_a, s_gcam_key_b, s_gcam_key_c);

  CheckTestModeBootHack(offset, memory);

  switch (AMMBDICommand(command >> 24))
  {
  case AMMBDICommand::Inquiry:
    if (s_firmware_map)
    {
      s_firmware_map = false;
    }

    // Returned value is used to set the protocol version.
    switch (GetGameType())
    {
    default:
      *diimm_buf = Version1;
      return 0;
    case VirtuaStriker4_2006:
    case KeyOfAvalon:
    case MarioKartGP:
    case MarioKartGP2:
    case FirmwareUpdate:
      *diimm_buf = Version2;
      return 0;
    }
    break;
  case AMMBDICommand::Read:
    if ((offset & 0x8FFF0000) == 0x80000000)
    {
      switch (offset)
      {
      case MediaBoardStatus1:
        memory.Write_U16(1, address);
        break;
      case MediaBoardStatus2:
        memory.Memset(address, 0, length);
        break;
      case MediaBoardStatus3:
        memory.Memset(address, 0xFF, length);
        // DIMM size (512MB)
        memory.Write_U32_Swap(0x20000000, address);
        // GCAM signature
        memory.Write_U32(0x4743414D, address + 4);
        break;
      case 0x80000100:
        memory.Write_U32_Swap(0x001F1F1F, address);
        break;
      case FirmwareStatus1:
        memory.Write_U32_Swap(0x01FA, address);
        break;
      case FirmwareStatus2:
        memory.Write_U32_Swap(1, address);
        break;
      case 0x80000160:
        memory.Write_U32(0x00001E00, address);
        break;
      case 0x80000180:
        memory.Write_U32(0, address);
        break;
      case 0x800001A0:
        memory.Write_U32(0xFFFFFFFF, address);
        break;
      default:
        PrintMBBuffer(address, length);
        ERROR_LOG_FMT(AMMEDIABOARD, "Unhandled Media Board Read: offset={0:08x} length={0:08x}",
                      offset, length);
        PanicAlertFmtT("Unhandled Media Board Read: offset={0:08x} length={0:08x}", offset, length);
        break;
      }
      return 0;
    }

    // Network configuration
    if (offset == 0x00000000 && length == 0x80)
    {
      FileReadData(memory, &s_netcfg, 0, address, length);
      return 0;
    }

    // Media crc check on/off
    if (offset == DIMMExtraSettings && length == 0x20)
    {
      FileReadData(memory, &s_extra, 0, address, length);
      return 0;
    }

    // DIMM memory (8MB)
    if (offset >= DIMMMemory && offset < 0x1F800000)
    {
      FileReadData(memory, &s_dimm, offset - DIMMMemory, address, length);
      return 0;
    }

    // DIMM memory (8MB)
    if (offset >= DIMMMemory2 && offset < 0xFF800000)
    {
      FileReadData(memory, &s_dimm, offset - DIMMMemory2, address, length);
      return 0;
    }

    if (offset == NetworkControl && length == 0x20)
    {
      FileReadData(memory, &s_netctrl, 0, address, length);
      return 0;
    }

    if (offset >= AllNetBuffer && offset < 0x89011000)
    {
      INFO_LOG_FMT(AMMEDIABOARD, "GC-AM: Read All.Net Buffer ({:08x},{})", offset, length);
      // Fake reply
      SafeCopyToEmu(memory, address, reinterpret_cast<const u8*>(s_allnet_reply),
                    sizeof(s_allnet_reply), offset - AllNetBuffer, sizeof(s_allnet_reply));
      return 0;
    }

    // Intercept 128-byte read after GetNetworkConfig: serve network config from trinetcfg.bin
    if (s_netconfig_read_pending && length == 0x80)
    {
      if (!GetSpanForMediaboardAddress(offset).empty())
      {
        s_netconfig_read_pending = false;

        u8 config[0x80] = {};
        if (s_netcfg.IsOpen())
        {
          s_netcfg.Seek(0, File::SeekOrigin::Begin);
          s_netcfg.ReadBytes(config, sizeof(config));
        }

        // config[0] is used as a menu table index. Entry 0 is NULL,
        // which causes a NULL dereference. Default to 2 (valid entry).
        if (config[0] == 0)
          config[0] = 2;

        DEBUG_LOG_FMT(AMMEDIABOARD,
                      "GC-AM: NetConfig Read (intercepted) offset={:08x} config[0]={}", offset,
                      config[0]);
        memory.CopyToEmu(address, config, sizeof(config));
        return 0;
      }
    }

    // Return saved response for each Execute path (they share s_media_buffer).
    if (offset == DIMMCommandVersion2 && length == 0x20)
    {
      DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: Read Execute1 response (saved)");
      memory.CopyToEmu(address, reinterpret_cast<const u8*>(s_exec1_last_response.data()),
                       sizeof(s_exec1_last_response));
      return 0;
    }
    if (offset == DIMMCommandVersion2_2 && length == 0x20)
    {
      DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: Read Execute2 response (saved)");
      memory.CopyToEmu(address, reinterpret_cast<const u8*>(s_exec2_last_response.data()),
                       sizeof(s_exec2_last_response));
      return 0;
    }

    if (const auto mediaboard_span = GetSpanForMediaboardAddress(offset); !mediaboard_span.empty())
    {
      DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: Read MediaBoard ({:08x},{:08x})", offset, length);
      SafeCopyToEmu(memory, address, mediaboard_span.data(), mediaboard_span.size(), 0, length);
      PrintMBBuffer(address, length);
      return 0;
    }

    if (offset == DIMMCommandExecute2)
    {
      const AMMBCommand ammb_command = Common::BitCastPtr<AMMBCommand>(s_media_buffer + 0x202);

      DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: Execute command: (2){0:04X}",
                    static_cast<u16>(ammb_command));

      memcpy(s_media_buffer, s_media_buffer + 0x200, 0x20);
      memset(s_media_buffer + 0x200, 0, 0x20);
      s_media_buffer[0x204] = 1;

      switch (ammb_command)
      {
      case AMMBCommand::Unknown_001:
        s_media_buffer_32[1] = 1;
        break;
      case AMMBCommand::GetNetworkFirmVersion:
        s_media_buffer_32[1] = 0x1305;  // Version: 13.05
        s_media_buffer[6] = 1;          // Type: VxWorks
        break;
      case AMMBCommand::GetSystemFlags:
        s_media_buffer[4] = 1;
        s_media_buffer[6] = NANDMaskBoardNAND;
        s_media_buffer[7] = 1;
        break;
      // Empty reply
      case AMMBCommand::Unknown_103:
        break;
      case AMMBCommand::GetNetworkConfig:
        s_media_buffer[4] = 1;
        // The game will do a 128-byte DMA Read for the network config.
        // We intercept that read and provide data from trinetcfg.bin.
        s_netconfig_read_pending = true;
        break;
      case AMMBCommand::NetworkReInit:
        break;
      case AMMBCommand::TestHardware:
      {
        // Execute2 layout: buf[1] = test type, buf[2] = string pointer
        // (differs from Execute1 where they're at indices 11 and 12)
        const u32 test_type = s_media_buffer_32[1];
        const u32 string_ptr = s_media_buffer_32[2];

        DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: TestHardware (Execute2): type={:08x} str_ptr={:08x}",
                      test_type, string_ptr);

        if (string_ptr != 0)
        {
          memory.Write_U32_Swap(TEST_OK_WORD0, string_ptr);
          memory.Write_U32_Swap(TEST_OK_WORD1, string_ptr + 4);
        }

        // Phase 1: Echo test_type back. The 0x80 flag is set below in the generic path.
        s_media_buffer_32[1] = test_type;

        // Schedule phase 2 result after a short delay.
        {
          auto& core_timing = system.GetCoreTiming();
          core_timing.RemoveEvent(s_et_test_hw_phase2);
          const s64 phase2_delay = system.GetSystemTimers().GetTicksPerSecond() / 10000;  // ~100us
          core_timing.ScheduleEvent(phase2_delay, s_et_test_hw_phase2, 1);  // 1 = Execute2
        }

        break;
      }
      case AMMBCommand::Accept:
        AMMBCommandAccept(2);
        break;
      case AMMBCommand::Bind:
        AMMBCommandBind();
        break;
      case AMMBCommand::Closesocket:
        AMMBCommandClosesocket(2);
        break;
      case AMMBCommand::Connect:
        AMMBCommandConnect(2);
        break;
      case AMMBCommand::InetAddr:
      {
        const char* ip_address = reinterpret_cast<char*>(s_network_command_buffer.data());

        // IP address shouldn't be longer than 15
        // TODO: Shouldn't this look at 16 characters for lack of null-termination?
        if (strnlen(ip_address, MAX_IPV4_STRING_LENGTH) > MAX_IPV4_STRING_LENGTH)
        {
          ERROR_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: Invalid size for address: InetAddr():{}",
                        strlen(ip_address));
          break;
        }

        const u32 ip = inet_addr(ip_address);
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: InetAddr( {} )", ip_address);

        s_media_buffer[1] = s_media_buffer[8];
        s_media_buffer_32[1] = ip;
        break;
      }
      case AMMBCommand::Listen:
      {
        const auto fd = GetHostSocket(GuestSocket(s_media_buffer_32[2]));
        const u32 backlog = s_media_buffer_32[3];

        const int ret = listen(fd, backlog);

        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: listen( {}, {} ):{:d}", fd, backlog, ret);

        s_media_buffer[1] = s_media_buffer[8];
        s_media_buffer_32[1] = ret;
        break;
      }
      case AMMBCommand::Recv:
        AMMBCommandRecv(2);
        break;
      case AMMBCommand::Send:
        AMMBCommandSend(2);
        break;
      case AMMBCommand::Socket:
        AMMBCommandSocket(2);
        break;
      case AMMBCommand::Select:
        AMMBCommandSelect(2);
        break;
      case AMMBCommand::SetSockOpt:
        AMMBCommandSetSockOpt(2);
        break;
      case AMMBCommand::SetTimeOuts:
      {
        const auto guest_socket = GuestSocket(s_media_buffer_32[2]);
        const auto host_socket = GetHostSocket(guest_socket);
        const u32 timeout_a = s_media_buffer_32[3];
        const u32 timeout_b = s_media_buffer_32[4];
        const u32 timeout_c = s_media_buffer_32[5];

        s_timeouts[0] = timeout_a;
        s_timeouts[1] = timeout_b;
        s_timeouts[2] = timeout_c;

        int ret = SOCKET_ERROR;

        if (host_socket != INVALID_SOCKET)
        {
          ret = setsockopt(host_socket, SOL_SOCKET, SO_SNDTIMEO,
                           reinterpret_cast<const char*>(&timeout_b), sizeof(int));
          if (ret < 0)
          {
            ret = WSAGetLastError();
          }
          else
          {
            ret = setsockopt(host_socket, SOL_SOCKET, SO_RCVTIMEO,
                             reinterpret_cast<const char*>(&timeout_c), sizeof(int));
            if (ret < 0)
              ret = WSAGetLastError();
          }

          INFO_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: SetTimeOuts( {}({}), {}, {}, {} ):{}", host_socket,
                       int(guest_socket), timeout_a, timeout_b, timeout_c, ret);
        }
        else
        {
          ERROR_LOG_FMT(AMMEDIABOARD_NET,
                        "GC-AM: Invalid Socket: SetTimeOuts( {}({}), {}, {}, {} ):{}", host_socket,
                        int(guest_socket), timeout_a, timeout_b, timeout_c, ret);
        }

        s_media_buffer[1] = s_media_buffer[8];
        s_media_buffer_32[1] = ret;
        break;
      }
      case AMMBCommand::GetParambyDHCPExec:
      {
        const u32 value = s_media_buffer_32[2];

        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: GetParambyDHCPExec({})", value);

        s_media_buffer[1] = 0;
        s_media_buffer_32[1] = 0;
        break;
      }
      case AMMBCommand::ModifyMyIPaddr:
        AMMBCommandModifyMyIPaddr(2);
        break;
      case AMMBCommand::GetLastError:
      {
        const auto guest_socket = GuestSocket(s_media_buffer_32[2]);
        const auto host_socket = GetHostSocket(guest_socket);

        if (s_last_error == SSC_EWOULDBLOCK)
        {
          // Prevent spamming
          DEBUG_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: GetLastError( {}({}) ):EWOULDBLOCK", host_socket,
                        int(guest_socket));
        }
        else
        {
          NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: GetLastError( {}({}) ):{}", host_socket,
                         int(guest_socket), int(s_last_error));
        }

        // Good enough, assuming it's called for the same socket right after an error.
        // TODO: Implement something similar per socket.
        s_media_buffer[1] = s_media_buffer[8];
        s_media_buffer_32[1] = s_last_error;
      }
      break;
      case AMMBCommand::InitLink:
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: InitLink");
        break;
      case AMMBCommand::AllNetInit:
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: AllNetInit");
        break;
      default:
        // Commands with 0x80 in the high byte are cleanup acknowledgments.
        if (static_cast<u16>(ammb_command) & 0x8000)
        {
          DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: Cleanup command {:04x} (Execute2)",
                        static_cast<u16>(ammb_command));
        }
        else
        {
          ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Command:{0:04x}", static_cast<u16>(ammb_command));
          ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Command Unhandled!");
        }
        break;
      }

      s_media_buffer[3] |= 0x80;  // Command complete flag

      // Save Execute2 response before it gets clobbered by subsequent operations
      memcpy(s_exec2_last_response.data(), s_media_buffer_32.data(), sizeof(s_exec2_last_response));

      memory.Memset(address, 0, length);

      ExpansionInterface::GenerateInterrupt(0x10);
      return 0;
    }

    // Max GC disc offset
    if (offset >= 0x57058000)
    {
      ERROR_LOG_FMT(AMMEDIABOARD, "Unhandled Media Board Read: offset={0:08x} length={0:08x}",
                    offset, length);
      PanicAlertFmtT("Unhandled Media Board Read: offset={0:08x} length={0:08x}", offset, length);
      return 0;
    }

    if (s_firmware_map)
    {
      if (!SafeCopyToEmu(memory, address, s_firmware.data(), s_firmware.size(), offset, length))
      {
        ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Invalid firmware buffer range: offset={}, length={}",
                      offset, length);
      }
      return 0;
    }

    if (const auto span = memory.GetSpanForAddress(address); span.size() < length)
    {
      ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Invalid DIMM Disc read from: offset={}, length={}",
                    offset, length);
    }
    else if (s_dimm_disc->Read(offset, length, span.data()))
    {
      return 0;
    }

    return 1;
    break;
  case AMMBDICommand::Write:

    // These two magic writes allow a new firmware to be programmed
    if (offset == FirmwareMagicWrite1 && length == 0x20)
    {
      s_firmware_map = true;
      return 0;
    }

    if (offset == FirmwareMagicWrite2 && length == 0x20)
    {
      s_firmware_map = true;
      return 0;
    }

    if (s_firmware_map)
    {
      // Firmware memory (2MB)
      if (offset >= 0x00400000 && offset <= 0x600000)
      {
        const u32 fw_offset = offset - 0x00400000;
        if (!SafeCopyFromEmu(memory, s_firmware.data(), address, s_firmware.size(), fw_offset,
                             length))
        {
          ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Invalid firmware write: offset={}, length={}",
                        fw_offset, length);
        }
        return 0;
      }
    }

    // Network configuration
    if (offset == 0x00000000 && length == 0x80)
    {
      FileWriteData(memory, &s_netcfg, 0, address, length);
      return 0;
    }

    // media crc check on/off
    if (offset == DIMMExtraSettings && length == 0x20)
    {
      FileWriteData(memory, &s_extra, 0, address, length);
      return 0;
    }

    // Backup memory (8MB)
    if (offset >= BackupMemory && offset < 0x00800000)
    {
      FileWriteData(memory, &s_backup, 0, address, length);
      return 0;
    }

    // DIMM memory (8MB)
    if (offset >= DIMMMemory && offset < 0x1F800000)
    {
      FileWriteData(memory, &s_dimm, offset - DIMMMemory, address, length);
      return 0;
    }

    // Firmware Write
    if (offset >= FirmwareAddress && offset < 0x84818000)
    {
      INFO_LOG_FMT(AMMEDIABOARD, "GC-AM: Write Firmware ({:08x})", offset);
      PrintMBBuffer(address, length);
      return 0;
    }

    // DIMM memory (8MB)
    if (offset >= DIMMMemory2 && offset < 0xFF800000)
    {
      FileWriteData(memory, &s_dimm, offset - DIMMMemory2, address, length);
      return 0;
    }

    if (offset == NetworkControl && length == 0x20)
    {
      FileWriteData(memory, &s_netctrl, 0, address, length);
      return 0;
    }

    if (offset == DIMMCommandExecute1 && length == 0x20)
    {
      if (memory.Read_U8(address) == 1)
      {
        const AMMBCommand ammb_command = Common::BitCastPtr<AMMBCommand>(s_media_buffer + 0x22);

        DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: Execute command: (1):{0:04X}",
                      static_cast<u16>(ammb_command));

        memset(s_media_buffer, 0, 0x20);

        // Counter/Command
        s_media_buffer_32[0] = s_media_buffer_32[8] | 0x80000000;  // Set command okay flag

        // Handle command
        switch (ammb_command)
        {
        case AMMBCommand::Unknown_000:
          s_media_buffer_32[1] = 1;
          break;
        case AMMBCommand::GetDIMMSize:
          s_media_buffer_32[1] = 0x20000000;
          break;
        case AMMBCommand::GetMediaBoardStatus:
          s_media_buffer_32[1] = LoadedGameProgram;
          s_media_buffer_32[2] = 100;
          break;
          // SegaBoot version: 3.09
        case AMMBCommand::GetSegaBootVersion:
          // Version
          s_media_buffer[4] = 0x03;
          s_media_buffer[5] = 0x09;
          // Unknown
          s_media_buffer[6] = 1;
          s_media_buffer_32[2] = 1;
          s_media_buffer_32[4] = 0xFF;
          break;
        case AMMBCommand::GetSystemFlags:
          s_media_buffer[4] = 1;
          s_media_buffer[5] = GDROM;
          // Enable development mode (Sega Boot)
          // This also allows region free booting
          s_media_buffer[6] = 1;
          s_media_buffer[8] = 0;  // Access Count
          break;
        case AMMBCommand::GetMediaBoardSerial:
          memcpy(s_media_buffer + 4, "A89E-27A50364511", 16);
          break;
        case AMMBCommand::GetNetworkConfig:
          s_media_buffer[4] = 1;
          break;
        case AMMBCommand::TestHardware:
        {
          // Execute1 command buffer layout (result slot at +0x20):
          //   [8] = command word, [9] = test_type, [10] = string_ptr
          const u32 test_type = s_media_buffer_32[9];
          const u32 string_ptr = s_media_buffer_32[10];

          DEBUG_LOG_FMT(AMMEDIABOARD,
                        "GC-AM: TestHardware (Execute1 inner): type={:08x} str_ptr={:08x}",
                        test_type, string_ptr);

          if (string_ptr != 0)
          {
            memory.Write_U32_Swap(TEST_OK_WORD0, string_ptr);
            memory.Write_U32_Swap(TEST_OK_WORD1, string_ptr + 4);
          }

          // Phase 1: Echo test_type back. The 0x80 flag is set below.
          s_media_buffer_32[1] = test_type;

          // Schedule phase 2 via CoreTiming.
          {
            auto& core_timing = system.GetCoreTiming();
            core_timing.RemoveEvent(s_et_test_hw_phase2);
            const s64 phase2_delay =
                system.GetSystemTimers().GetTicksPerSecond() / 10000;         // ~100us
            core_timing.ScheduleEvent(phase2_delay, s_et_test_hw_phase2, 0);  // 0 = Execute1
          }
          break;
        }
        default:
          // Commands with 0x80 in the high byte are cleanup acknowledgments.
          if (static_cast<u16>(ammb_command) & 0x8000)
          {
            DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: Cleanup command {:04x} (Execute1)",
                          static_cast<u16>(ammb_command));
          }
          else
          {
            ERROR_LOG_FMT(AMMEDIABOARD, "Unhandled Media Board Command:{0:04x}",
                          static_cast<u16>(ammb_command));
            PanicAlertFmtT("Unhandled Media Board Command:{0:04x}", static_cast<u16>(ammb_command));
          }
          break;
        }

        memset(s_media_buffer + 0x20, 0, 0x20);

        // Save Execute1 response before it gets clobbered by Execute2 operations
        memcpy(s_exec1_last_response.data(), s_media_buffer_32.data(),
               sizeof(s_exec1_last_response));

        ExpansionInterface::GenerateInterrupt(0x04);
        return 0;
      }
    }

    if (const auto mediaboard_span = GetSpanForMediaboardAddress(offset); !mediaboard_span.empty())
    {
      // Persist network config to trinetcfg.bin for SET IP ADDRESS.
      // The DMA Write (0x80 bytes) arrives before the corresponding command (0x0204),
      // so we detect it here by size and non-zero status byte.
      if (length == 0x80 && memory.Read_U8(address) != 0 && s_netcfg.IsOpen())
      {
        DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: NetConfig persist to trinetcfg.bin (status={})",
                      memory.Read_U8(address));
        FileWriteData(memory, &s_netcfg, 0, address, length);
      }

      DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: Write MediaBoard ({:08x},{:08x})", offset, length);
      SafeCopyFromEmu(memory, mediaboard_span.data(), address, mediaboard_span.size(), 0, length);
      PrintMBBuffer(address, length);
      return 0;
    }

    // Max GC disc offset
    if (offset >= 0x57058000)
    {
      PrintMBBuffer(address, length);
      ERROR_LOG_FMT(AMMEDIABOARD, "Unhandled Media Board Write: offset={0:08x} length={0:08x}",
                    offset, length);
      PanicAlertFmtT("Unhandled Media Board Write: offset={0:08x} length={0:08x}", offset, length);
    }
    break;
  case AMMBDICommand::Execute:
  {
    const auto ammb_command = static_cast<AMMBCommand>(s_media_buffer_32[8] >> 16);
    if (ammb_command == AMMBCommand::Unknown_000)
      break;

    if (offset == 0 && length == 0)
    {
      memset(s_media_buffer, 0, 0x20);

      // Counter/Command
      s_media_buffer_32[0] = s_media_buffer_32[8] | 0x80000000;  // Set command okay flag

      switch (ammb_command)
      {
      case AMMBCommand::Unknown_000:
        s_media_buffer_32[1] = 1;
        break;
      case AMMBCommand::GetDIMMSize:
        s_media_buffer_32[1] = 0x20000000;
        break;
      case AMMBCommand::GetMediaBoardStatus:
      {
        s_media_buffer_32[1] = s_board_status;
        s_media_buffer_32[2] = s_load_progress;
        if (s_load_progress < 100)
        {
          s_load_progress++;
        }
        else
        {
          s_board_status = LoadedGameProgram;
        }
      }
      break;
      // SegaBoot version: 3.11
      case AMMBCommand::GetSegaBootVersion:
        // Version
        s_media_buffer[4] = 0x03;
        s_media_buffer[5] = 0x11;
        // Unknown
        s_media_buffer[6] = 1;
        s_media_buffer_32[2] = 1;
        s_media_buffer_32[4] = 0xFF;
        break;
      case AMMBCommand::GetSystemFlags:
        s_media_buffer[4] = 1;
        s_media_buffer[5] = GDROM;
        // Enable development mode (Sega Boot)
        // This also allows region free booting
        s_media_buffer[6] = 1;
        s_media_buffer[8] = 0;  // Access Count
        break;
      case AMMBCommand::GetMediaBoardSerial:
        memcpy(s_media_buffer + 4, "A89E-27A50364511", 16);
        break;
      case AMMBCommand::GetNetworkConfig:
        s_media_buffer[4] = 1;
        break;
      case AMMBCommand::NetworkReInit:
        break;
      case AMMBCommand::TestHardware:
        // Test type

        // 0x01: Media board
        // 0x04: Network

        DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM: TestHardware: ({:08x})", s_media_buffer_32[11]);
        // Pointer to a memory address that is directly displayed on screen as a string
        DEBUG_LOG_FMT(AMMEDIABOARD, "GC-AM:               ({:08x})", s_media_buffer_32[12]);

        // On real systems it shows the status about the DIMM/GD-ROM here
        memory.Write_U32_Swap(TEST_OK_WORD0, s_media_buffer_32[12]);
        memory.Write_U32_Swap(TEST_OK_WORD1, s_media_buffer_32[12] + 4);

        s_media_buffer_32[1] = s_media_buffer_32[9];
        break;
      case AMMBCommand::Closesocket:
        AMMBCommandClosesocket(10);
        break;
      case AMMBCommand::Connect:
        AMMBCommandConnect(10);
        break;
      case AMMBCommand::Recv:
        AMMBCommandRecv(10);
        break;
      case AMMBCommand::Send:
        AMMBCommandSend(10);
        break;
      case AMMBCommand::Socket:
        AMMBCommandSocket(10);
        break;
      case AMMBCommand::Select:
        AMMBCommandSelect(10);
        break;
      case AMMBCommand::SetSockOpt:
        AMMBCommandSetSockOpt(10);
        break;
      case AMMBCommand::ModifyMyIPaddr:
        AMMBCommandModifyMyIPaddr(10);
        break;
      // Empty reply
      case AMMBCommand::InitLink:
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: InitLink");
        break;
      case AMMBCommand::Unknown_605:
        NOTICE_LOG_FMT(AMMEDIABOARD, "GC-AM: 0x605");
        break;
      case AMMBCommand::SetupLink:
      {
        const auto addra = std::bit_cast<Common::IPAddress>(s_media_buffer_32[12]);
        const auto addrb = std::bit_cast<Common::IPAddress>(s_media_buffer_32[13]);

        const u16 size = s_media_buffer[0x24] | s_media_buffer[0x25] << 8;
        const u16 port = Common::swap16(s_media_buffer[0x27] | s_media_buffer[0x26] << 8);
        const u16 unknown = s_media_buffer[0x2D] | s_media_buffer[0x2C] << 8;

        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: SetupLink:");
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:  Size: ({}) ", size);
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:  Port: ({})", port);
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:LinkNum:({:02x})", s_media_buffer[0x28]);
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:        ({:02x})", s_media_buffer[0x2A]);
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:        ({:04x})", unknown);
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:   IP:  ({})",
                       Common::IPAddressToString(addra));  // IP ?
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:   IP:  ({})",
                       Common::IPAddressToString(addrb));  // Target IP
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:        ({:08x})",
                       Common::swap32(s_media_buffer_32[14]));  // some RAM address
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:        ({:08x})",
                       Common::swap32(s_media_buffer_32[15]));  // some RAM address

        s_media_buffer_32[1] = 0;
      }
      break;
      // This sends a UDP packet to previously defined Target IP/Port
      case AMMBCommand::SearchDevices:
      {
        const u16 unknown = s_media_buffer[0x25] | s_media_buffer[0x24] << 8;
        const u16 off = s_media_buffer[0x26] | s_media_buffer[0x27] << 8;
        const u32 addr = s_media_buffer_32[10];

        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: SearchDevices: ({})", unknown);
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:        Offset: ({:04x})", off);
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM:                ({:08x})", addr);

        const auto data_span = GetSpanForMediaboardAddress(off + addr);
        if (data_span.size() < 0x20)
        {
          ERROR_LOG_FMT(AMMEDIABOARD_NET, "SearchDevices: Bad data offset: {:08x}", off + addr);
          break;
        }

        const u8* const data = data_span.data();

        for (u32 i = 0; i < 0x20; i += 0x10)
        {
          const std::array<u32, 4> data_u32 = Common::BitCastPtr<std::array<u32, 4>>(data + i);
          NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: {:08x} {:08x} {:08x} {:08x}", data_u32[0],
                         data_u32[1], data_u32[2], data_u32[3]);
        }

        s_media_buffer_32[1] = 0;
      }
      break;
      case AMMBCommand::Unknown_608:
      {
        const u32 ip = s_media_buffer_32[10];
        const u16 port = Common::swap16(s_media_buffer[6] | s_media_buffer[7] << 8);
        const u16 flag = s_media_buffer[10] | s_media_buffer[11] << 8;

        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: 0x608( {} {} {} )", ip, port, flag);
      }
      break;
      case AMMBCommand::Unknown_614:
        NOTICE_LOG_FMT(AMMEDIABOARD_NET, "GC-AM: 0x614");
        break;
      default:
        ERROR_LOG_FMT(AMMEDIABOARD, "GC-AM: Execute buffer UNKNOWN:{0:04x}",
                      static_cast<u16>(ammb_command));
        break;
      }

      memset(s_media_buffer + 0x20, 0, 0x20);

      // Save Execute1 response for DI Execute path
      memcpy(s_exec1_last_response.data(), s_media_buffer_32.data(), sizeof(s_exec1_last_response));
      return 0;
    }

    ERROR_LOG_FMT(AMMEDIABOARD, "Unhandled Media Board Execute:{0:04x}",
                  static_cast<u16>(ammb_command));
    PanicAlertFmtT("Unhandled Media Board Execute:{0:04x}", static_cast<u16>(ammb_command));
    break;
  }
  default:
    ERROR_LOG_FMT(AMMEDIABOARD, "Unhandled Media Board Command:{0:02x}", command);
    PanicAlertFmtT("Unhandled Media Board Command:{0:02x}", command);
    break;
  }

  return 0;
}

u32 GetMediaType()
{
  switch (GetGameType())
  {
  default:
  case FZeroAX:
  case VirtuaStriker3:
  case VirtuaStriker4:
  case VirtuaStriker4_2006:
  case GekitouProYakyuu:
  case KeyOfAvalon:
    return GDROM;

  case MarioKartGP:
  case MarioKartGP2:
  case FZeroAXMonster:
    return NAND;
  }
}

// This is checking for the real game IDs (See boot.id within the game)
u32 GetGameType()
{
  u16 triforce_id = 0;
  const std::string& game_id = SConfig::GetInstance().GetGameID();

  if (game_id.length() == 6)
  {
    triforce_id = game_id[1] << 8 | game_id[2];
  }
  else
  {
    triforce_id = 0x454A;  // Fallback (VirtuaStriker3)
  }

  auto it = s_game_map.find(triforce_id);
  if (it != s_game_map.end())
  {
    return it->second;
  }

  PanicAlertFmtT("Unknown game ID:{0:08x}, using default controls.", triforce_id);
  return VirtuaStriker3;  // Fallback
}

bool GetTestMenu()
{
  return s_test_menu;
}

static void CloseAllSockets()
{
  for (u32 i = FIRST_VALID_FD; i < std::size(s_sockets); ++i)
  {
    if (s_sockets[i] != SOCKET_ERROR)
    {
      closesocket(s_sockets[i]);
      s_sockets[i] = SOCKET_ERROR;
    }
  }
}

void Shutdown()
{
  s_netcfg.Close();
  s_netctrl.Close();
  s_extra.Close();
  s_backup.Close();
  s_dimm.Close();

  s_dimm_disc.reset();

  CloseAllSockets();
}

void DoState(PointerWrap& p)
{
  p.Do(s_firmware_map);
  p.Do(s_test_menu);
  p.Do(s_timeouts);
  p.Do(s_last_error);
  p.Do(s_gcam_key_a);
  p.Do(s_gcam_key_b);
  p.Do(s_gcam_key_c);
  p.Do(s_firmware);
  p.Do(s_media_buffer_32);
  p.Do(s_exec1_last_response);
  p.Do(s_exec2_last_response);
  p.Do(s_network_command_buffer);
  p.Do(s_network_buffer);
  p.Do(s_allnet_buffer);
  p.Do(s_allnet_settings);
  p.Do(s_next_valid_fd);

  p.Do(s_game_modified_ip_address);
  p.Do(s_netconfig_read_pending);

  p.Do(s_board_status);
  p.Do(s_load_progress);

  // TODO: Handle the files better.
  // Data corruption is probably currently possible.

  // s_netcfg
  // s_netctrl
  // s_extra
  // s_backup
  // s_dimm

  // TODO: Handle sockets better.
  // For now, we just recreate a TCP socket for any socket that existed.
  // We should probably re-bind sockets and handle UDP sockets.

  GuestFdSet created_sockets{};
  if (p.IsWriteMode() || p.IsVerifyMode())
  {
    for (u32 i = FIRST_VALID_FD; i < std::size(s_sockets); ++i)
    {
      if (s_sockets[i] != SOCKET_ERROR)
        created_sockets.SetFd(GuestSocket(i));
    }
  }

  p.Do(created_sockets);

  if (p.IsReadMode())
  {
    CloseAllSockets();

    for (u32 i = FIRST_VALID_FD; i < std::size(s_sockets); ++i)
    {
      if (!created_sockets.IsFdSet(GuestSocket(i)))
        continue;

      s_sockets[i] = socket(AF_INET, SOCK_STREAM, 0);
    }
  }
}

s32 DebuggerGetSocket(u32 triforce_fd)
{
  if (triforce_fd < std::size(s_sockets))
    return s32(s_sockets[triforce_fd]);

  WARN_LOG_FMT(AMMEDIABOARD, "GC-AM: Bad socket fd used by the debugger: {}", triforce_fd);
  return -1;
}
}  // namespace AMMediaboard
