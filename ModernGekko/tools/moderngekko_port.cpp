#include "moderngekko/game.hpp"
#include "moderngekko/module_abi.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <cerrno>
#include <cctype>
#include <charconv>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <thread>
#include <unordered_set>
#include <utility>
#include <vector>

#if defined(_WIN32)
#include <windows.h>
#else
#include <fcntl.h>
#include <sys/file.h>
#include <unistd.h>
#endif

namespace fs = std::filesystem;

namespace
{
constexpr std::string_view MODULE_CACHE_IDENTITY_VERSION =
    "moderngekko-module-v2";
constexpr std::string_view MODULE_BUILD_TYPE = "Release";
constexpr std::string_view MODULE_OPT_LEVEL = "2";

struct BuildOptions
{
  std::string toolchain = "auto";
#if defined(MODERNGEKKO_DOLRECOMP_LLVM)
  std::string backend = "llvm";
#else
  std::string backend = "c";
#endif
  fs::path output;
  std::vector<std::string> runner_arguments;
};

fs::path DefaultOutput()
{
  if (const char* xdg = std::getenv("XDG_CACHE_HOME"))
    return fs::path(xdg) / "moderngekko" / "modules";
  if (const char* home = std::getenv("HOME"))
    return fs::path(home) / ".cache" / "moderngekko" / "modules";
  return "moderngekko-modules";
}

std::string Suffix()
{
#if defined(_WIN32)
  return ".dll";
#elif defined(__APPLE__)
  return ".dylib";
#else
  return ".so";
#endif
}

std::string Quote(const fs::path& value)
{
#if defined(_WIN32)
  std::string text = value.string();
  return '"' + text + '"';
#else
  std::string text = value.string();
  std::string result = "'";
  for (char c : text)
    result += c == '\'' ? "'\\''" : std::string(1, c);
  return result + "'";
#endif
}

std::uint64_t Fnv1a(std::string_view value)
{
  std::uint64_t hash = 0xcbf29ce484222325ULL;
  for (unsigned char c : value)
    hash = (hash ^ c) * 0x100000001b3ULL;
  return hash;
}

std::string Trim(std::string value)
{
  while (!value.empty() && std::isspace(static_cast<unsigned char>(value.front())))
    value.erase(value.begin());
  while (!value.empty() && std::isspace(static_cast<unsigned char>(value.back())))
    value.pop_back();
  return value;
}

std::string ManifestEscape(std::string_view value)
{
  std::string escaped;
  escaped.reserve(value.size());
  for (const char c : value)
  {
    if (c == '\\')
      escaped += "\\\\";
    else if (c == '\n')
      escaped += "\\n";
    else if (c == '\r')
      escaped += "\\r";
    else
      escaped += c;
  }
  return escaped;
}

class CacheIdentity
{
public:
  void Add(std::string key, std::string value)
  {
    m_values.emplace_back(std::move(key), std::move(value));
  }

  std::string Canonical() const
  {
    std::ostringstream output;
    for (const auto& [key, value] : m_values)
      output << key.size() << ':' << key << value.size() << ':' << value;
    return output.str();
  }

  void Write(std::ostream& output) const
  {
    for (const auto& [key, value] : m_values)
      output << key << '=' << ManifestEscape(value) << '\n';
  }

private:
  std::vector<std::pair<std::string, std::string>> m_values;
};

std::string RawEnvironment(const char* name)
{
  const char* value = std::getenv(name);
  return value ? "set:" + std::string(value) : "unset";
}

unsigned EffectiveChunkSize(const char* name, unsigned default_value)
{
  const char* value = std::getenv(name);
  if (!value || !value[0])
    return default_value;
  char* end = nullptr;
  errno = 0;
  const unsigned long parsed = std::strtoul(value, &end, 10);
  if (errno || !end || *end || parsed < 128 || parsed > 4096)
    return default_value;
  return static_cast<unsigned>(parsed);
}

unsigned EffectiveBuildJobs()
{
  constexpr unsigned default_job_limit = 4;
  const unsigned available = std::max(1u, std::thread::hardware_concurrency());
  const char* value = std::getenv("MODERNGEKKO_BUILD_JOBS");
  if (!value || !value[0])
    return std::min(default_job_limit, available);

  char* end = nullptr;
  errno = 0;
  const unsigned long parsed = std::strtoul(value, &end, 10);
  if (errno || !end || *end || parsed < 1 || parsed > default_job_limit)
    return std::min(default_job_limit, available);
  return static_cast<unsigned>(parsed);
}

std::string EffectiveLLVMBuildMode()
{
  const char* value = std::getenv("DOLRECOMP_LLVM_BUILD_MODE");
  if (!value || !value[0])
    return "balanced-default";
  if (!std::strcmp(value, "development") || !std::strcmp(value, "balanced") ||
      !std::strcmp(value, "production"))
    return value;
  return "invalid";
}

std::string EffectiveLLVMOptLevel()
{
  int level = 2;
  const char* mode = std::getenv("DOLRECOMP_LLVM_BUILD_MODE");
  if (mode && mode[0])
  {
    if (!std::strcmp(mode, "development"))
      level = 1;
    else if (!std::strcmp(mode, "balanced"))
      level = 2;
    else if (!std::strcmp(mode, "production"))
      level = 3;
    else
      return "invalid";
  }

  const char* configured = std::getenv("DOLRECOMP_LLVM_OPT_LEVEL");
  if (configured && configured[0])
  {
    char* end = nullptr;
    errno = 0;
    const long parsed = std::strtol(configured, &end, 10);
    if (errno || !end || *end || parsed < 0 || parsed > 3)
      return "invalid";
    level = static_cast<int>(parsed);
  }
  return std::to_string(level);
}

std::string FirstLine(std::string value)
{
  const std::size_t end = value.find_first_of("\r\n");
  if (end != std::string::npos)
    value.resize(end);
  return Trim(std::move(value));
}

std::uint32_t ReadBE32(const std::uint8_t* data)
{
  return (std::uint32_t{data[0]} << 24) | (std::uint32_t{data[1]} << 16) |
         (std::uint32_t{data[2]} << 8) | data[3];
}

void WriteBE32(std::uint8_t* data, std::uint32_t value)
{
  data[0] = static_cast<std::uint8_t>(value >> 24);
  data[1] = static_cast<std::uint8_t>(value >> 16);
  data[2] = static_cast<std::uint8_t>(value >> 8);
  data[3] = static_cast<std::uint8_t>(value);
}

bool ParseHex32(std::string_view value, std::uint32_t* parsed)
{
  if (value.starts_with("0x") || value.starts_with("0X"))
    value.remove_prefix(2);
  const auto result = std::from_chars(value.data(), value.data() + value.size(), *parsed, 16);
  return result.ec == std::errc{} && result.ptr == value.data() + value.size();
}

std::optional<std::uint32_t> ReadUnsignedDefine(const fs::path& path,
                                                std::string_view expected_name)
{
  std::ifstream input(path);
  std::string line;
  while (std::getline(input, line))
  {
    std::istringstream tokens(line);
    std::string directive;
    std::string name;
    std::string value;
    if (!(tokens >> directive >> name >> value) || directive != "#define" ||
        name != expected_name)
      continue;
    while (!value.empty() &&
           (value.back() == 'u' || value.back() == 'U' || value.back() == 'l' ||
            value.back() == 'L'))
      value.pop_back();
    int base = 10;
    if (value.starts_with("0x") || value.starts_with("0X"))
    {
      value.erase(0, 2);
      base = 16;
    }
    std::uint32_t parsed = 0;
    const auto result = std::from_chars(value.data(), value.data() + value.size(), parsed, base);
    if (result.ec == std::errc{} && result.ptr == value.data() + value.size())
      return parsed;
    return std::nullopt;
  }
  return std::nullopt;
}

struct DolPatch
{
  std::uint32_t address;
  std::uint32_t value;
};

struct DolPatchSet
{
  std::vector<DolPatch> entries;
  std::string fingerprint = "none";
  std::string error;

  explicit operator bool() const { return error.empty(); }
};

DolPatchSet LoadDefaultDolPatches(const fs::path& path)
{
  std::ifstream input(path);
  if (!input)
    return {};

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(input, line))
    lines.push_back(Trim(std::move(line)));

  std::unordered_set<std::string> enabled;
  std::string section;
  for (const std::string& current : lines)
  {
    if (current.starts_with('[') && current.ends_with(']'))
      section = current.substr(1, current.size() - 2);
    else if (section == "OnFrame_Enabled" && current.starts_with('$'))
      enabled.insert(current.substr(1));
  }
  if (enabled.empty())
    return {};

  DolPatchSet patches;
  std::string patch_name;
  for (const std::string& current : lines)
  {
    if (current.starts_with('[') && current.ends_with(']'))
    {
      section = current.substr(1, current.size() - 2);
      patch_name.clear();
      continue;
    }
    if (section != "OnFrame")
      continue;
    if (current.starts_with('$'))
    {
      patch_name = current.substr(1);
      continue;
    }
    if (current.empty() || current.starts_with('#') || current.starts_with(';') ||
        !enabled.contains(patch_name))
      continue;

    const std::size_t first = current.find(':');
    const std::size_t second = current.find(':', first == std::string::npos ? first : first + 1);
    if (first == std::string::npos || second == std::string::npos ||
        current.find(':', second + 1) != std::string::npos ||
        current.substr(first + 1, second - first - 1) != "dword")
    {
      patches.error = "unsupported enabled DOL patch line in " + path.string();
      return patches;
    }
    DolPatch patch{};
    if (!ParseHex32(std::string_view(current).substr(0, first), &patch.address) ||
        !ParseHex32(std::string_view(current).substr(second + 1), &patch.value))
    {
      patches.error = "malformed enabled DOL patch line in " + path.string();
      return patches;
    }
    patches.entries.push_back(patch);
  }

  std::ostringstream identity;
  identity << std::hex << std::setfill('0');
  for (const DolPatch& patch : patches.entries)
    identity << std::setw(8) << patch.address << std::setw(8) << patch.value;
  std::ostringstream fingerprint;
  fingerprint << std::hex << std::setfill('0') << std::setw(16) << Fnv1a(identity.str());
  patches.fingerprint = fingerprint.str();
  return patches;
}

bool PatchDol(const fs::path& input_path, const fs::path& output_path,
              const DolPatchSet& patches, std::string* error)
{
  std::ifstream input(input_path, std::ios::binary | std::ios::ate);
  if (!input)
  {
    *error = "can't open " + input_path.string();
    return false;
  }
  const std::streamoff input_size = input.tellg();
  if (input_size < 0x100)
  {
    *error = "malformed DOL " + input_path.string();
    return false;
  }
  std::vector<std::uint8_t> bytes(static_cast<std::size_t>(input_size));
  input.seekg(0);
  if (!input.read(reinterpret_cast<char*>(bytes.data()), input_size))
  {
    *error = "can't read " + input_path.string();
    return false;
  }

  for (const DolPatch& patch : patches.entries)
  {
    bool applied = false;
    for (std::size_t section_index = 0; section_index < 18; ++section_index)
    {
      const std::uint32_t offset = ReadBE32(bytes.data() + section_index * 4);
      const std::uint32_t address = ReadBE32(bytes.data() + 0x48 + section_index * 4);
      const std::uint32_t size = ReadBE32(bytes.data() + 0x90 + section_index * 4);
      if (patch.address < address ||
          static_cast<std::uint64_t>(patch.address) + 4 >
              static_cast<std::uint64_t>(address) + size)
        continue;
      const std::uint64_t patch_offset =
          static_cast<std::uint64_t>(offset) + patch.address - address;
      if (patch_offset + 4 > bytes.size())
      {
        *error = "DOL patch points outside the file";
        return false;
      }
      WriteBE32(bytes.data() + patch_offset, patch.value);
      applied = true;
      break;
    }
    if (!applied)
    {
      std::ostringstream message;
      message << "DOL patch address 0x" << std::hex << patch.address
              << " is outside every section";
      *error = message.str();
      return false;
    }
  }

  std::ofstream output(output_path, std::ios::binary | std::ios::trunc);
  if (!output || !output.write(reinterpret_cast<const char*>(bytes.data()), bytes.size()))
  {
    *error = "can't write " + output_path.string();
    return false;
  }
  return true;
}

std::string ReadCommand(const std::string& command)
{
#if defined(_WIN32)
  FILE* pipe = _popen(command.c_str(), "r");
#else
  FILE* pipe = popen(command.c_str(), "r");
#endif
  if (!pipe)
    return {};
  std::string output;
  char buffer[512];
  while (fgets(buffer, sizeof(buffer), pipe))
    output += buffer;
#if defined(_WIN32)
  _pclose(pipe);
#else
  pclose(pipe);
#endif
  return output;
}

std::string ResolveExecutable(std::string_view name)
{
#if defined(_WIN32)
  const std::string resolved = ReadCommand("where " + Quote(fs::path(name)) + " 2>nul");
#else
  const std::string resolved =
      ReadCommand("command -v " + Quote(fs::path(name)) + " 2>/dev/null");
#endif
  const std::string first = FirstLine(resolved);
  if (first.empty())
    return std::string(name);
  std::error_code ec;
  const fs::path canonical = fs::weakly_canonical(first, ec);
  return ec ? first : canonical.string();
}

std::string CompilerVersion(const std::string& compiler)
{
  if (compiler == "cl")
    return ReadCommand("cl 2>&1");
  return ReadCommand(compiler + " --version 2>&1");
}

std::string CompilerTarget(const std::string& compiler)
{
  if (compiler == "cl")
    return FirstLine(CompilerVersion(compiler));
  return FirstLine(ReadCommand(compiler + " -dumpmachine 2>&1"));
}

std::string LtoPluginIdentity(const std::string& compiler)
{
  if (compiler == "cl")
    return "msvc-toolchain-integrated";

  if (compiler == "clang")
  {
#if defined(_WIN32)
    if (CompilerTarget(compiler).find("msvc") != std::string::npos)
    {
      const std::string reported =
          FirstLine(ReadCommand(compiler + " -print-prog-name=lld-link 2>&1"));
      const std::string linker = ResolveExecutable(reported);
      const auto hash = moderngekko::HashFileSha256(linker);
      return hash ? "linker-integrated:" + linker + "|sha256=" + *hash : "unavailable";
    }
#elif !defined(__APPLE__)
    const std::string reported =
        FirstLine(ReadCommand(compiler + " -print-prog-name=ld 2>&1"));
    const std::string linker = ResolveExecutable(reported);
    std::string linker_name = fs::path(linker).filename().string();
    std::transform(linker_name.begin(), linker_name.end(), linker_name.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    if (linker_name.find("lld") != std::string::npos ||
        linker_name.find("mold") != std::string::npos)
    {
      const auto hash = moderngekko::HashFileSha256(linker);
      return hash ? "linker-integrated:" + linker + "|sha256=" + *hash : "unavailable";
    }
#endif
  }
#if defined(__APPLE__)
  constexpr std::string_view plugin_name = "libLTO.dylib";
#elif defined(_WIN32)
  constexpr std::string_view plugin_name = "LLVMgold.dll";
#else
  const std::string_view plugin_name =
      compiler == "gcc" ? "liblto_plugin.so" : "LLVMgold.so";
#endif
  const std::string path =
      FirstLine(ReadCommand(compiler + " -print-file-name=" + std::string(plugin_name) +
                            " 2>&1"));
  const auto hash = moderngekko::HashFileSha256(path);
  return hash ? path + "|sha256=" + *hash : "unavailable";
}

std::string LinkerIdentity(const std::string& compiler)
{
  if (compiler == "cl")
  {
    const std::string linker = ResolveExecutable("link");
    const auto hash = moderngekko::HashFileSha256(linker);
    const std::string version = ReadCommand("link 2>&1");
    if (!hash || version.empty())
      return {};
    return linker + "|sha256=" + *hash + "|" + version;
  }

  std::string linker_program = "ld";
#if defined(_WIN32)
  if (compiler == "clang" && CompilerTarget(compiler).find("msvc") != std::string::npos)
    linker_program = "lld-link";
#endif
  const std::string reported = FirstLine(
      ReadCommand(compiler + " -print-prog-name=" + linker_program + " 2>&1"));
  if (reported.empty())
    return {};
  const std::string linker = ResolveExecutable(reported);
  const auto hash = moderngekko::HashFileSha256(linker);
  if (!hash)
    return {};
#if defined(__APPLE__)
  const std::string version = ReadCommand(Quote(fs::path(linker)) + " -v 2>&1");
#else
  const std::string version = ReadCommand(Quote(fs::path(linker)) + " --version 2>&1");
#endif
  if (version.empty())
    return {};
  return linker + "|sha256=" + *hash + "|" + version;
}

std::string DolRecompLLVMIdentity(const fs::path& dolrecomp)
{
#if defined(__linux__)
  std::istringstream dependencies(
      ReadCommand("ldd " + Quote(dolrecomp) + " 2>/dev/null"));
  std::string line;
  while (std::getline(dependencies, line))
  {
    if (line.find("libLLVM") == std::string::npos)
      continue;
    const std::size_t arrow = line.find("=>");
    const std::size_t path_begin =
        line.find_first_not_of(" \t", arrow == std::string::npos ? 0 : arrow + 2);
    const std::size_t path_end = line.find_first_of(" \t(", path_begin);
    if (path_begin == std::string::npos)
      return "unresolved:" + Trim(std::move(line));
    const fs::path path = line.substr(path_begin, path_end - path_begin);
    const auto hash = moderngekko::HashFileSha256(path);
    return hash ? path.string() + "|sha256=" + *hash :
                  "unresolved:" + Trim(std::move(line));
  }
  return "statically-linked-or-not-present";
#else
  (void)dolrecomp;
  return "platform-loader-identity-unavailable";
#endif
}

std::optional<std::string> HashTextSha256(const fs::path& scratch_directory,
                                          std::string_view text)
{
  static std::atomic<std::uint64_t> scratch_sequence{0};
  std::error_code ec;
  fs::create_directories(scratch_directory, ec);
  if (ec)
    return std::nullopt;
  std::ostringstream name;
  name << ".module-identity-" << std::hex << Fnv1a(text) << '-';
#if defined(_WIN32)
  name << GetCurrentProcessId();
#else
  name << getpid();
#endif
  name << '-' << scratch_sequence.fetch_add(1) << ".tmp";
  const fs::path scratch = scratch_directory / name.str();
  {
    std::ofstream output(scratch, std::ios::binary | std::ios::trunc);
    if (!output || !output.write(text.data(), static_cast<std::streamsize>(text.size())))
      return std::nullopt;
  }
  const auto hash = moderngekko::HashFileSha256(scratch);
  fs::remove(scratch, ec);
  return hash;
}

std::optional<std::string> ManifestValue(const fs::path& path, std::string_view key)
{
  std::ifstream manifest(path);
  std::string line;
  const std::string prefix = std::string(key) + '=';
  while (std::getline(manifest, line))
  {
    if (line.starts_with(prefix))
      return line.substr(prefix.size());
  }
  return std::nullopt;
}

std::vector<std::pair<std::string, fs::path>> ModuleSourceInputs(const fs::path& source_root)
{
  const fs::path module_template = source_root / "vendor/dolphin/module-template";
  const fs::path gxruntime = source_root / "vendor/dolphin/GXRuntime";
  const fs::path chassis_abi =
      source_root / "vendor/dolphin/Source/Core/Core/PowerPC/StaticRecomp";
  std::vector<std::pair<std::string, fs::path>> inputs = {
      {"module-template/CMakeLists.txt", module_template / "CMakeLists.txt"},
      {"module-template/gen_module_tables.py", module_template / "gen_module_tables.py"},
      {"module-template/module_export.c", module_template / "module_export.c"},
      {"GXRuntime/src/core/cpu.c", gxruntime / "src/core/cpu.c"},
      {"GXRuntime/src/core/cpu_exception.c", gxruntime / "src/core/cpu_exception.c"},
      {"GXRuntime/src/core/cpu_interpreter.c", gxruntime / "src/core/cpu_interpreter.c"},
      {"GXRuntime/src/core/cpu_interpreter_table.c",
       gxruntime / "src/core/cpu_interpreter_table.c"},
      {"GXRuntime/src/core/cpu_interpreter_float.c",
       gxruntime / "src/core/cpu_interpreter_float.c"},
      {"GXRuntime/src/core/cpu_interpreter_integer.c",
       gxruntime / "src/core/cpu_interpreter_integer.c"},
      {"GXRuntime/src/core/cpu_interpreter_private.h",
       gxruntime / "src/core/cpu_interpreter_private.h"},
      {"GXRuntime/include/core/cpu.h", gxruntime / "include/core/cpu.h"},
      {"GXRuntime/include/core/types.h", gxruntime / "include/core/types.h"},
      {"StaticRecomp/StaticRecompABI.h", chassis_abi / "StaticRecompABI.h"},
      {"ModernGekko/include/moderngekko/cpu_state.h",
       source_root / "include/moderngekko/cpu_state.h"},
      {"ModernGekko/include/moderngekko/module_abi.h",
       source_root / "include/moderngekko/module_abi.h"},
  };
#if !defined(_WIN32) && !defined(__APPLE__)
  inputs.emplace_back("module-template/module.exports", module_template / "module.exports");
#endif
  return inputs;
}

std::optional<std::string> CMakeCacheValue(const fs::path& path, std::string_view name)
{
  std::ifstream input(path);
  std::string line;
  const std::string prefix = std::string(name) + ':';
  while (std::getline(input, line))
  {
    if (!line.starts_with(prefix))
      continue;
    const std::size_t separator = line.find('=', prefix.size());
    if (separator != std::string::npos)
      return line.substr(separator + 1);
  }
  return std::nullopt;
}

fs::path TemporarySibling(const fs::path& target, std::string_view purpose)
{
  static std::atomic<std::uint64_t> sequence{0};
  std::ostringstream name;
  name << '.' << target.filename().string() << '.' << purpose << '-';
#if defined(_WIN32)
  name << GetCurrentProcessId();
#else
  name << getpid();
#endif
  name << '-' << sequence.fetch_add(1) << ".tmp";
  return target.parent_path() / name.str();
}

bool AtomicReplace(const fs::path& source, const fs::path& target)
{
#if defined(_WIN32)
  return MoveFileExW(source.c_str(), target.c_str(),
                     MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != 0;
#else
  std::error_code ec;
  fs::rename(source, target, ec);
  return !ec;
#endif
}

bool AtomicWriteText(const fs::path& path, std::string_view text)
{
  std::error_code ec;
  fs::create_directories(path.parent_path(), ec);
  if (ec)
    return false;
  const fs::path temporary = TemporarySibling(path, "write");
  {
    std::ofstream output(temporary, std::ios::binary | std::ios::trunc);
    output.write(text.data(), static_cast<std::streamsize>(text.size()));
    output.flush();
    output.close();
    if (!output)
    {
      fs::remove(temporary, ec);
      return false;
    }
  }
  if (AtomicReplace(temporary, path))
    return true;
  fs::remove(temporary, ec);
  return false;
}

class CacheLock
{
public:
  explicit CacheLock(const fs::path& path)
  {
#if defined(_WIN32)
    m_handle = CreateFileW(path.c_str(), GENERIC_READ | GENERIC_WRITE, 0, nullptr,
                           OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
#else
    m_fd = open(path.c_str(), O_CREAT | O_RDWR, 0666);
    if (m_fd >= 0 && flock(m_fd, LOCK_EX | LOCK_NB) != 0)
    {
      close(m_fd);
      m_fd = -1;
    }
#endif
  }

  CacheLock(const CacheLock&) = delete;
  CacheLock& operator=(const CacheLock&) = delete;

  ~CacheLock()
  {
#if defined(_WIN32)
    if (m_handle != INVALID_HANDLE_VALUE)
      CloseHandle(m_handle);
#else
    if (m_fd >= 0)
      close(m_fd);
#endif
  }

  explicit operator bool() const
  {
#if defined(_WIN32)
    return m_handle != INVALID_HANDLE_VALUE;
#else
    return m_fd >= 0;
#endif
  }

private:
#if defined(_WIN32)
  HANDLE m_handle = INVALID_HANDLE_VALUE;
#else
  int m_fd = -1;
#endif
};

bool RunCommand(const std::string& command)
{
  std::cout << "+ " << command << '\n';
#if defined(_WIN32)
  std::vector<char> command_line(command.begin(), command.end());
  command_line.push_back('\0');
  STARTUPINFOA startup{};
  startup.cb = sizeof(startup);
  PROCESS_INFORMATION process{};
  if (!CreateProcessA(nullptr, command_line.data(), nullptr, nullptr, TRUE, 0, nullptr, nullptr,
                      &startup, &process))
  {
    std::cerr << "failed to launch command: Windows error " << GetLastError() << '\n';
    return false;
  }
  WaitForSingleObject(process.hProcess, INFINITE);
  DWORD exit_code = 1;
  const bool got_exit_code = GetExitCodeProcess(process.hProcess, &exit_code) != FALSE;
  CloseHandle(process.hThread);
  CloseHandle(process.hProcess);
  return got_exit_code && exit_code == 0;
#else
  return std::system(command.c_str()) == 0;
#endif
}

fs::path SiblingExecutable(const char* argv0, std::string name)
{
  std::error_code ec;
  fs::path self = fs::weakly_canonical(argv0, ec);
#if defined(_WIN32)
  name += ".exe";
#endif
  const fs::path sibling = self.parent_path() / name;
  return fs::is_regular_file(sibling) ? sibling : fs::path(std::move(name));
}

std::string PlatformName(moderngekko::GamePlatform platform)
{
  return platform == moderngekko::GamePlatform::Wii ? "Wii (Broadway)" : "GameCube (Gekko)";
}

std::string ActiveModule(const fs::path& output, std::string_view id)
{
  std::ifstream file(output / id / "active-module.txt");
  std::string value;
  std::getline(file, value);
  return value;
}

std::string CachedModuleStatus(const fs::path& output,
                               const moderngekko::GameMetadata& game)
{
  const std::string active = ActiveModule(output, game.disc_id);
  if (active.empty())
    return "none";

  const fs::path module = active;
  if (!fs::is_regular_file(module))
    return "missing: " + module.string();

  const fs::path manifest = module.parent_path() / "manifest.txt";
  const auto dol_hash = ManifestValue(manifest, "dol_sha256");
  if (!dol_hash)
    return "unverified manifest: " + module.string();
  if (*dol_hash != game.dol_sha256)
    return "stale DOL: " + module.string();

  // Legacy manifests recorded only declared inputs and accepted mere artifact
  // existence. Do not call those entries current even when their DOL matches.
  const auto identity_hash = ManifestValue(manifest, "cache_identity_sha256");
  const auto expected_module_hash = ManifestValue(manifest, "module_sha256");
  const auto module_abi = ManifestValue(manifest, "module_abi");
  const auto cpu_abi = ManifestValue(manifest, "cpu_abi");
  const auto cpu_state_size = ManifestValue(manifest, "cpu_state_size");
  if (ManifestValue(manifest, "module_cache_identity_version") !=
          MODULE_CACHE_IDENTITY_VERSION ||
      !identity_hash || identity_hash->size() != 64 || !expected_module_hash ||
      module_abi != std::to_string(MODERNGEKKO_MODULE_ABI_VERSION) ||
      cpu_abi != std::to_string(MODERNGEKKO_CPU_ABI_VERSION) ||
      cpu_state_size != std::to_string(sizeof(CPUState)))
  {
    return "legacy/stale ABI: " + module.string();
  }
  const auto actual_module_hash = moderngekko::HashFileSha256(module);
  if (!actual_module_hash || *actual_module_hash != *expected_module_hash)
    return "corrupt: " + module.string();
  for (const auto& [name, path] :
       ModuleSourceInputs(fs::path(MODERNGEKKO_SOURCE_DIR)))
  {
    const auto recorded_hash = ManifestValue(manifest, "source_sha256." + name);
    const auto current_hash = moderngekko::HashFileSha256(path);
    if (!recorded_hash || !current_hash || *recorded_hash != *current_hash)
      return "stale framework source: " + module.string();
  }
  return "verified current: " + module.string();
}

int Inspect(const fs::path& root, const fs::path& output)
{
  const auto result = moderngekko::InspectGame(root);
  if (!result)
  {
    std::cerr << "invalid extracted game: " << result.error << '\n';
    return 1;
  }
  const auto& game = *result.metadata;
  std::cout << "Game name: " << game.game_name << '\n'
            << "Disc ID:   " << game.disc_id << '\n'
            << "Platform:  " << PlatformName(game.platform) << '\n'
            << "Entry:     0x" << std::hex << std::setw(8) << std::setfill('0')
            << game.entry_point << std::dec << '\n'
            << "DOL SHA-256: " << game.dol_sha256 << '\n'
            << "Cached module: " << CachedModuleStatus(output, game) << '\n';
  return 0;
}

std::optional<fs::path> Build(const char* argv0, const fs::path& root,
                              BuildOptions options)
{
  const auto inspected = moderngekko::InspectGame(root);
  if (!inspected)
  {
    std::cerr << "invalid extracted game: " << inspected.error << '\n';
    return std::nullopt;
  }
  const auto& game = *inspected.metadata;
  if (options.output.empty())
    options.output = DefaultOutput();
  const fs::path source_root = fs::path(MODERNGEKKO_SOURCE_DIR);
  const DolPatchSet patches = LoadDefaultDolPatches(
      source_root / "vendor/dolphin/Data/Sys/GameSettings" / (game.disc_id + ".ini"));
  if (!patches)
  {
    std::cerr << patches.error << '\n';
    return std::nullopt;
  }

  std::string compiler;
  if (options.toolchain == "auto")
#if defined(_MSC_VER)
    compiler = "cl";
#elif defined(__clang__)
    compiler = "clang";
#elif defined(__GNUC__)
    compiler = "gcc";
#else
    compiler = ReadCommand("clang --version 2>&1").empty() ? "gcc" : "clang";
#endif
  else if (options.toolchain == "clang")
    compiler = "clang";
  else if (options.toolchain == "gcc")
    compiler = "gcc";
  else if (options.toolchain == "msvc")
  {
#if defined(_WIN32)
    compiler = "cl";
#else
    std::cerr << "MSVC modules can only be built on Windows\n";
    return std::nullopt;
#endif
  }
  else
  {
    std::cerr << "unknown toolchain: " << options.toolchain << '\n';
    return std::nullopt;
  }

  const std::string compiler_path = ResolveExecutable(compiler);
  const std::string compiler_identity = CompilerVersion(compiler);
  if (compiler_identity.empty())
  {
    std::cerr << "compiler is unavailable: " << compiler << '\n';
    return std::nullopt;
  }
  const auto compiler_hash = moderngekko::HashFileSha256(compiler_path);
  const std::string compiler_target = CompilerTarget(compiler);
  const std::string linker_identity = LinkerIdentity(compiler);
  if (!compiler_hash || compiler_target.empty() || linker_identity.empty())
  {
    std::cerr << "can't identify the module compiler/linker toolchain\n";
    return std::nullopt;
  }
  const fs::path dolrecomp = SiblingExecutable(argv0, "dolrecomp");
  const auto dolrecomp_hash = moderngekko::HashFileSha256(dolrecomp);
  if (!dolrecomp_hash)
  {
    std::cerr << "DolRecomp compiler is unavailable: " << dolrecomp << '\n';
    return std::nullopt;
  }
#if defined(__x86_64__) || defined(_M_X64)
  constexpr std::string_view architecture = "x86_64";
#elif defined(__aarch64__) || defined(_M_ARM64)
  constexpr std::string_view architecture = "aarch64";
#else
  constexpr std::string_view architecture = "unsupported";
#endif

  const fs::path module_template = source_root / "vendor/dolphin/module-template";
  const fs::path gxruntime = source_root / "vendor/dolphin/GXRuntime";
  const fs::path chassis_abi =
      source_root / "vendor/dolphin/Source/Core/Core/PowerPC/StaticRecomp";
  const auto source_module_abi =
      ReadUnsignedDefine(chassis_abi / "StaticRecompABI.h", "STATICRECOMP_ABI_VERSION");
  const auto source_cpu_abi =
      ReadUnsignedDefine(gxruntime / "include/core/cpu.h", "GXRUNTIME_CPU_ABI_VERSION");
  const auto host_source_module_abi = ReadUnsignedDefine(
      source_root / "include/moderngekko/module_abi.h", "MODERNGEKKO_MODULE_ABI_VERSION");
  const auto host_source_cpu_abi = ReadUnsignedDefine(
      source_root / "include/moderngekko/cpu_state.h", "MODERNGEKKO_CPU_ABI_VERSION");
  if (!source_module_abi || !source_cpu_abi || !host_source_module_abi ||
      !host_source_cpu_abi)
  {
    std::cerr << "can't read the module/CPU ABI versions from their source headers\n";
    return std::nullopt;
  }
  if (*source_module_abi != *host_source_module_abi ||
      *source_cpu_abi != *host_source_cpu_abi ||
      *host_source_module_abi != MODERNGEKKO_MODULE_ABI_VERSION ||
      *host_source_cpu_abi != MODERNGEKKO_CPU_ABI_VERSION)
  {
    std::cerr << "module ABI headers changed since moderngekko-port was built; rebuild the tool "
                 "before publishing a module\n";
    return std::nullopt;
  }

  CacheIdentity identity;
  identity.Add("module_cache_identity_version", std::string(MODULE_CACHE_IDENTITY_VERSION));
  identity.Add("disc_id", game.disc_id);
  identity.Add("dol_sha256", game.dol_sha256);
  identity.Add("platform", game.platform == moderngekko::GamePlatform::GameCube ?
                                   "gamecube-gekko" : "wii-broadway");
  identity.Add("dolrecomp_binary_sha256", *dolrecomp_hash);
  const std::string dolrecomp_llvm_identity = DolRecompLLVMIdentity(dolrecomp);
  if (options.backend == "llvm" &&
      dolrecomp_llvm_identity == "platform-loader-identity-unavailable")
  {
    std::cerr << "LLVM backend cache identity is unsupported on this platform\n";
    return std::nullopt;
  }
  identity.Add("dolrecomp_llvm_identity", dolrecomp_llvm_identity);
  identity.Add("module_abi", std::to_string(*source_module_abi));
  identity.Add("cpu_abi", std::to_string(*source_cpu_abi));
  identity.Add("cpu_state_size", std::to_string(sizeof(CPUState)));
  identity.Add("port_compiled_module_abi",
               std::to_string(MODERNGEKKO_MODULE_ABI_VERSION));
  identity.Add("port_compiled_cpu_abi", std::to_string(MODERNGEKKO_CPU_ABI_VERSION));
  identity.Add("architecture", std::string(architecture));
  identity.Add("backend", options.backend);
  identity.Add("toolchain_option", options.toolchain);
  identity.Add("patches", patches.fingerprint);
  identity.Add("compiler_path", compiler_path);
  identity.Add("compiler_binary_sha256", *compiler_hash);
  identity.Add("compiler_version", compiler_identity);
  identity.Add("compiler_target", compiler_target);
  identity.Add("linker_identity", linker_identity);
  const std::string lto_plugin_identity = LtoPluginIdentity(compiler);
  if (compiler == "clang" && lto_plugin_identity == "unavailable")
  {
    std::cerr << "can't identify the Clang ThinLTO implementation\n";
    return std::nullopt;
  }
  identity.Add("lto_plugin_identity", lto_plugin_identity);
  const std::string cmake_path = ResolveExecutable("cmake");
  const std::string ninja_path = ResolveExecutable("ninja");
  std::string python_path = ResolveExecutable("python3");
  const auto cmake_hash = moderngekko::HashFileSha256(cmake_path);
  const auto ninja_hash = moderngekko::HashFileSha256(ninja_path);
  auto python_hash = moderngekko::HashFileSha256(python_path);
#if defined(_WIN32)
  if (!python_hash)
  {
    python_path = ResolveExecutable("python");
    python_hash = moderngekko::HashFileSha256(python_path);
  }
#endif
  const std::string cmake_identity = ReadCommand(Quote(cmake_path) + " --version 2>&1");
  const std::string ninja_identity = ReadCommand(Quote(ninja_path) + " --version 2>&1");
  const std::string python_identity = ReadCommand(Quote(python_path) + " --version 2>&1");
  if (!cmake_hash || !ninja_hash || !python_hash || cmake_identity.empty() ||
      ninja_identity.empty() || python_identity.empty())
  {
    std::cerr << "cmake, ninja, and python3 are required to identify the module build\n";
    return std::nullopt;
  }
  identity.Add("cmake_path", cmake_path);
  identity.Add("cmake_binary_sha256", *cmake_hash);
  identity.Add("cmake_identity", cmake_identity);
  identity.Add("ninja_path", ninja_path);
  identity.Add("ninja_binary_sha256", *ninja_hash);
  identity.Add("ninja_identity", ninja_identity);
  identity.Add("python_path", python_path);
  identity.Add("python_binary_sha256", *python_hash);
  identity.Add("python_identity", python_identity);
  identity.Add("module_build_type", std::string(MODULE_BUILD_TYPE));
  identity.Add("module_opt_level", std::string(MODULE_OPT_LEVEL));
  // Apply ThinLTO explicitly instead of relying on the template's conditional
  // CheckIPOSupported result, so the successful build mode is part of the key.
  const std::string module_cmake_ipo = "OFF";
  const std::string module_effective_ipo = compiler == "clang" ? "thin-explicit" : "off";
  identity.Add("module_ipo_cmake_option", module_cmake_ipo);
  identity.Add("module_ipo_effective", module_effective_ipo);
  const std::string module_release_c_flags = compiler == "cl" ? "/DNDEBUG" :
      compiler == "clang" ? "-DNDEBUG -flto=thin" : "-DNDEBUG";
  const bool clang_msvc_target =
      compiler == "clang" && compiler_target.find("msvc") != std::string::npos;
  const std::string module_release_link_flags = compiler == "cl" ? "/INCREMENTAL:NO" :
      clang_msvc_target ? "-O2 -flto=thin -fuse-ld=lld" :
      compiler == "clang" ? "-O2 -flto=thin" : "-O2";
  identity.Add("module_base_c_flags", "");
  identity.Add("module_release_c_flags", module_release_c_flags);
  identity.Add("module_base_shared_linker_flags", "");
  identity.Add("module_release_shared_linker_flags", module_release_link_flags);
  if (compiler == "cl")
    identity.Add("module_target_compile_options", "/O2 /fp:strict");
  else
    identity.Add("module_target_compile_options", "-O2 -ffp-contract=off -fno-fast-math");

  for (const char* name : {"CFLAGS", "CPPFLAGS", "LDFLAGS", "CPATH", "C_INCLUDE_PATH",
                           "LIBRARY_PATH", "COMPILER_PATH", "LD_LIBRARY_PATH",
                           "MACOSX_DEPLOYMENT_TARGET", "SDKROOT", "CL", "_CL_", "LINK",
                           "INCLUDE", "LIB", "LIBPATH", "VSCMD_ARG_TGT_ARCH",
                           "VSCMD_ARG_HOST_ARCH", "VCToolsInstallDir", "WindowsSdkDir",
                           "WindowsSDKVersion", "CC", "CMAKE_TOOLCHAIN_FILE",
                           "CMAKE_C_COMPILER_LAUNCHER"})
    identity.Add("env." + std::string(name) + ".raw", RawEnvironment(name));
  for (const char* name : {"CFLAGS", "CPPFLAGS", "LDFLAGS", "CL", "_CL_", "LINK", "CC",
                           "CMAKE_TOOLCHAIN_FILE", "CMAKE_C_COMPILER_LAUNCHER"})
    identity.Add("env." + std::string(name) + ".effective", "unset-by-moderngekko-port");

  const char* llvm_target_raw = std::getenv("DOLRECOMP_LLVM_TARGET");
  const std::string llvm_target_effective = llvm_target_raw && llvm_target_raw[0] ?
      llvm_target_raw : "host-default:" + compiler_target;
  identity.Add("env.DOLRECOMP_LLVM_BUILD_MODE.raw",
               RawEnvironment("DOLRECOMP_LLVM_BUILD_MODE"));
  identity.Add("env.DOLRECOMP_LLVM_BUILD_MODE.effective", EffectiveLLVMBuildMode());
  identity.Add("env.DOLRECOMP_LLVM_OPT_LEVEL.raw",
               RawEnvironment("DOLRECOMP_LLVM_OPT_LEVEL"));
  identity.Add("env.DOLRECOMP_LLVM_OPT_LEVEL.effective", EffectiveLLVMOptLevel());
  identity.Add("env.DOLRECOMP_LLVM_CHUNK_INSTRUCTIONS.raw",
               RawEnvironment("DOLRECOMP_LLVM_CHUNK_INSTRUCTIONS"));
  identity.Add("env.DOLRECOMP_LLVM_CHUNK_INSTRUCTIONS.effective",
               std::to_string(EffectiveChunkSize("DOLRECOMP_LLVM_CHUNK_INSTRUCTIONS", 1024)));
  identity.Add("env.DOLRECOMP_LLVM_TARGET.raw", RawEnvironment("DOLRECOMP_LLVM_TARGET"));
  identity.Add("env.DOLRECOMP_LLVM_TARGET.effective", llvm_target_effective);
  identity.Add("env.DOLRECOMP_C_CHUNK_INSTRUCTIONS.raw",
               RawEnvironment("DOLRECOMP_C_CHUNK_INSTRUCTIONS"));
  identity.Add("env.DOLRECOMP_C_CHUNK_INSTRUCTIONS.effective",
               std::to_string(EffectiveChunkSize("DOLRECOMP_C_CHUNK_INSTRUCTIONS", 4096)));

  const auto source_inputs = ModuleSourceInputs(source_root);
  std::vector<std::pair<fs::path, std::string>> source_hashes;
  source_hashes.reserve(source_inputs.size());
  for (const auto& [name, path] : source_inputs)
  {
    const auto hash = moderngekko::HashFileSha256(path);
    if (!hash)
    {
      std::cerr << "module source input is unavailable: " << path << '\n';
      return std::nullopt;
    }
    identity.Add("source_sha256." + name, *hash);
    source_hashes.emplace_back(path, *hash);
  }

  const auto identity_hash =
      HashTextSha256(options.output / game.disc_id, identity.Canonical());
  if (!identity_hash)
  {
    std::cerr << "can't hash the module cache identity\n";
    return std::nullopt;
  }
  const std::string cache_key = game.dol_sha256 + "-" + *identity_hash;
  const fs::path artifact = options.output / game.disc_id / cache_key;
  const fs::path module = artifact / ("g" + game.disc_id + "_recomp" + Suffix());
  const fs::path module_build = artifact / "module-build";
  const fs::path built = module_build / ("g" + game.disc_id + "_recomp" + Suffix());

  const fs::path manifest_path = artifact / "manifest.txt";
  std::error_code artifact_error;
  fs::create_directories(artifact, artifact_error);
  if (artifact_error)
  {
    std::cerr << "can't create module cache directory " << artifact << '\n';
    return std::nullopt;
  }
  CacheLock cache_lock(artifact / ".cache.lock");
  if (!cache_lock)
  {
    std::cerr << "another process is building this module cache entry: " << artifact << '\n';
    return std::nullopt;
  }
  const auto activate_module = [&]() {
    std::error_code absolute_error;
    const fs::path absolute_module = fs::absolute(module, absolute_error).lexically_normal();
    if (absolute_error)
      return false;
    return AtomicWriteText(options.output / game.disc_id / "active-module.txt",
                           absolute_module.string() + '\n');
  };
  if (fs::is_regular_file(module) &&
      ManifestValue(manifest_path, "cache_identity_sha256") == identity_hash)
  {
    const auto expected_module_hash = ManifestValue(manifest_path, "module_sha256");
    const auto actual_module_hash = moderngekko::HashFileSha256(module);
    if (expected_module_hash && actual_module_hash &&
        *expected_module_hash == *actual_module_hash)
    {
      if (!activate_module())
      {
        std::cerr << "can't activate cached module " << module << '\n';
        return std::nullopt;
      }
      std::cout << "cache hit: " << module << '\n';
      return module;
    }
  }
  if (fs::is_regular_file(module))
    std::cout << "cache entry failed identity/checksum validation; rebuilding: " << module << '\n';

  const auto publish_module = [&]() -> std::optional<fs::path> {
    if (moderngekko::HashFileSha256(game.main_dol) != game.dol_sha256 ||
        moderngekko::HashFileSha256(dolrecomp) != dolrecomp_hash ||
        moderngekko::HashFileSha256(compiler_path) != compiler_hash ||
        moderngekko::HashFileSha256(cmake_path) != cmake_hash ||
        moderngekko::HashFileSha256(ninja_path) != ninja_hash ||
        moderngekko::HashFileSha256(python_path) != python_hash ||
        DolRecompLLVMIdentity(dolrecomp) != dolrecomp_llvm_identity ||
        LinkerIdentity(compiler) != linker_identity ||
        LtoPluginIdentity(compiler) != lto_plugin_identity)
    {
      std::cerr << "module toolchain changed during the build; refusing stale publication\n";
      return std::nullopt;
    }
    for (const auto& [path, expected_hash] : source_hashes)
    {
      if (moderngekko::HashFileSha256(path) != expected_hash)
      {
        std::cerr << "module source input changed during the build; refusing stale publication: "
                  << path << '\n';
        return std::nullopt;
      }
    }
    const auto built_hash = moderngekko::HashFileSha256(built);
    if (!built_hash)
    {
      std::cerr << "can't hash built module " << built << '\n';
      return std::nullopt;
    }
    const fs::path staged_module = TemporarySibling(module, "publish");
    std::error_code copy_error;
    fs::copy_file(built, staged_module, fs::copy_options::overwrite_existing, copy_error);
    const auto staged_hash = moderngekko::HashFileSha256(staged_module);
    if (copy_error || !staged_hash || *staged_hash != *built_hash)
    {
      fs::remove(staged_module, copy_error);
      std::cerr << "staged module checksum mismatch: " << staged_module << '\n';
      return std::nullopt;
    }

    std::ostringstream manifest;
    identity.Write(manifest);
    manifest << "cache_identity_sha256=" << *identity_hash << '\n'
             << "module_sha256=" << *staged_hash << '\n';
    const fs::path cmake_cache = module_build / "CMakeCache.txt";
    for (const auto& [manifest_name, cache_name] :
         std::array<std::pair<std::string_view, std::string_view>, 11>{
             {{"cmake_actual_c_compiler", "CMAKE_C_COMPILER"},
              {"cmake_detected_linker", "CMAKE_LINKER"},
              {"cmake_actual_ninja", "CMAKE_MAKE_PROGRAM"},
              {"cmake_actual_python", "Python3_EXECUTABLE"},
              {"cmake_actual_c_flags", "CMAKE_C_FLAGS"},
              {"cmake_actual_c_flags_release", "CMAKE_C_FLAGS_RELEASE"},
              {"cmake_actual_shared_linker_flags", "CMAKE_SHARED_LINKER_FLAGS"},
              {"cmake_actual_shared_linker_flags_release",
               "CMAKE_SHARED_LINKER_FLAGS_RELEASE"},
              {"cmake_actual_build_type", "CMAKE_BUILD_TYPE"},
              {"cmake_actual_module_opt", "RECOMPCORE_MODULE_OPT_LEVEL"},
              {"cmake_actual_module_ipo", "RECOMPCORE_MODULE_ENABLE_IPO"}}})
    {
      if (const auto value = CMakeCacheValue(cmake_cache, cache_name))
        manifest << manifest_name << '=' << ManifestEscape(*value) << '\n';
    }
    const auto build_graph_hash = moderngekko::HashFileSha256(module_build / "build.ninja");
    if (!build_graph_hash)
    {
      fs::remove(staged_module, copy_error);
      std::cerr << "can't hash the configured module build graph\n";
      return std::nullopt;
    }
    manifest << "cmake_build_graph_sha256=" << *build_graph_hash << '\n';

    if (!AtomicReplace(staged_module, module))
    {
      fs::remove(staged_module, copy_error);
      std::cerr << "can't atomically publish module " << module << '\n';
      return std::nullopt;
    }
    const auto published_hash = moderngekko::HashFileSha256(module);
    if (!published_hash || *published_hash != *staged_hash)
    {
      std::cerr << "published module checksum mismatch: " << module << '\n';
      return std::nullopt;
    }
    if (!AtomicWriteText(manifest_path, manifest.str()))
    {
      std::cerr << "can't atomically publish module manifest " << manifest_path << '\n';
      return std::nullopt;
    }
    if (!activate_module())
    {
      std::cerr << "can't activate built module " << module << '\n';
      return std::nullopt;
    }
    std::cout << "built module: " << module << '\n';
    return module;
  };

  fs::path recomp_dol = game.main_dol;
  if (!patches.entries.empty())
  {
    recomp_dol = artifact / "patched-main.dol";
    std::string patch_error;
    if (!PatchDol(game.main_dol, recomp_dol, patches, &patch_error))
    {
      std::cerr << patch_error << '\n';
      return std::nullopt;
    }
    std::cout << "applied " << patches.entries.size() << " default DOL patches\n";
  }
  const fs::path generated_parent = artifact / "dolrecomp-output";
  const unsigned build_jobs = EffectiveBuildJobs();
  std::string generate = Quote(dolrecomp) + " -j" +
                         std::to_string(build_jobs) +
                         " --backend=" + options.backend + " ";
  if (game.platform == moderngekko::GamePlatform::GameCube)
    generate += "--cpu gekko --gamecube " + Quote(recomp_dol) + " " + Quote(generated_parent);
  else
    generate += "--cpu broadway " + Quote(recomp_dol) + " " + game.disc_id + " " +
                Quote(generated_parent);
  if (!RunCommand(generate))
    return std::nullopt;

  fs::path generated = game.platform == moderngekko::GamePlatform::Wii ?
      generated_parent / (game.disc_id + "_generated") : generated_parent / "generated";
  std::string generated_stem =
      game.platform == moderngekko::GamePlatform::Wii ? game.disc_id : "generated";
  // DolRecomp's optional title database affects output naming only. An
  // explicit --cpu broadway keeps Wii semantics even when that database is absent.
  if (!fs::is_regular_file(generated / (generated_stem + ".h")) &&
      fs::is_regular_file(generated_parent / "generated" / "generated.h"))
  {
    generated = generated_parent / "generated";
    generated_stem = "generated";
  }
  const fs::path emitted_header = generated / (generated_stem + ".h");
  if (!fs::is_regular_file(emitted_header))
  {
    std::cerr << "DolRecomp did not produce " << emitted_header << '\n';
    return std::nullopt;
  }
  if (emitted_header.filename() != "generated.h")
    fs::copy_file(emitted_header, generated / "generated.h", fs::copy_options::overwrite_existing);
  fs::copy_file(recomp_dol, generated / "main.dol", fs::copy_options::overwrite_existing);
  const fs::path emitted_smc = generated / (generated_stem + "_smc.txt");
  const fs::path normalized_smc = generated / "generated_smc.txt";
  if (fs::is_regular_file(emitted_smc))
  {
    if (emitted_smc != normalized_smc)
      fs::copy_file(emitted_smc, normalized_smc, fs::copy_options::overwrite_existing);
  }
  else
    std::ofstream{normalized_smc};

  const unsigned compile_jobs = build_jobs;
  const std::string clean_build_environment =
      Quote(cmake_path) +
      " -E env --unset=CFLAGS --unset=CPPFLAGS --unset=LDFLAGS --unset=CL "
      "--unset=_CL_ --unset=LINK --unset=CC --unset=CMAKE_TOOLCHAIN_FILE "
      "--unset=CMAKE_C_COMPILER_LAUNCHER ";
  std::string configure =
      clean_build_environment + "CMAKE_NINJA_FORCE_RESPONSE_FILE=1 " +
      Quote(cmake_path) + " -S " +
      Quote(module_template) + " -B " + Quote(module_build) + " -G Ninja" +
      " -DCMAKE_BUILD_TYPE=" + std::string(MODULE_BUILD_TYPE) +
      " -DCMAKE_C_COMPILER:FILEPATH=" + Quote(compiler_path) +
      " -DCMAKE_MAKE_PROGRAM:FILEPATH=" + Quote(ninja_path) +
      " -DPython3_EXECUTABLE:FILEPATH=" + Quote(python_path) +
      " -DCMAKE_C_FLAGS= -DCMAKE_C_FLAGS_RELEASE=" + Quote(module_release_c_flags) +
      " -DCMAKE_SHARED_LINKER_FLAGS= -DCMAKE_SHARED_LINKER_FLAGS_RELEASE=" +
      Quote(module_release_link_flags) +
      " -DRECOMPCORE_MODULE_OPT_LEVEL=" + std::string(MODULE_OPT_LEVEL) +
      " -DRECOMPCORE_MODULE_ENABLE_IPO=" + module_cmake_ipo +
      " -DGAME_ID=" + game.disc_id +
      " -DGENERATED_DIR=" + Quote(generated) +
      " -DGXRUNTIME_DIR=" + Quote(gxruntime) +
      " -DCHASSIS_ABI_DIR=" + Quote(chassis_abi);
  if (!RunCommand(configure))
    return std::nullopt;
  const fs::path cmake_cache = module_build / "CMakeCache.txt";
  const auto configured_compiler = CMakeCacheValue(cmake_cache, "CMAKE_C_COMPILER");
  const auto configured_ninja = CMakeCacheValue(cmake_cache, "CMAKE_MAKE_PROGRAM");
  const auto configured_python = CMakeCacheValue(cmake_cache, "Python3_EXECUTABLE");
  if (!configured_compiler ||
      moderngekko::HashFileSha256(*configured_compiler) != compiler_hash ||
      !configured_ninja || moderngekko::HashFileSha256(*configured_ninja) != ninja_hash ||
      !configured_python || moderngekko::HashFileSha256(*configured_python) != python_hash ||
      CMakeCacheValue(cmake_cache, "CMAKE_BUILD_TYPE") != MODULE_BUILD_TYPE ||
      CMakeCacheValue(cmake_cache, "CMAKE_C_FLAGS") != std::string_view{} ||
      CMakeCacheValue(cmake_cache, "CMAKE_C_FLAGS_RELEASE") != module_release_c_flags ||
      CMakeCacheValue(cmake_cache, "CMAKE_SHARED_LINKER_FLAGS") != std::string_view{} ||
      CMakeCacheValue(cmake_cache, "CMAKE_SHARED_LINKER_FLAGS_RELEASE") !=
          module_release_link_flags ||
      CMakeCacheValue(cmake_cache, "RECOMPCORE_MODULE_OPT_LEVEL") != MODULE_OPT_LEVEL ||
      CMakeCacheValue(cmake_cache, "RECOMPCORE_MODULE_ENABLE_IPO") != module_cmake_ipo)
  {
    std::cerr << "module CMake configuration does not match its cache identity\n";
    return std::nullopt;
  }
  if (!RunCommand(clean_build_environment + Quote(cmake_path) + " --build " +
                  Quote(module_build) + " -j" + std::to_string(compile_jobs)))
    return std::nullopt;

  if (!fs::is_regular_file(built))
  {
    std::cerr << "module build completed but did not produce " << built << '\n';
    return std::nullopt;
  }
  return publish_module();
}

void Usage()
{
  std::cerr << "usage: moderngekko-port inspect <game-root>\n"
               "       moderngekko-port build <game-root> [--backend c|llvm] [--toolchain auto|clang|gcc|msvc] [--output path]\n"
               "       moderngekko-port run <game-root> [build options] [-- runner options]\n";
}
}  // namespace

int main(int argc, char** argv)
{
  if (argc < 3)
  {
    Usage();
    return 2;
  }
  const std::string command = argv[1];
  const fs::path root = argv[2];
  BuildOptions options;
  bool runner_args = false;
  for (int i = 3; i < argc; ++i)
  {
    const std::string arg = argv[i];
    if (runner_args)
      options.runner_arguments.push_back(arg);
    else if (arg == "--")
      runner_args = true;
    else if (arg == "--toolchain" && i + 1 < argc)
      options.toolchain = argv[++i];
    else if (arg == "--backend" && i + 1 < argc)
      options.backend = argv[++i];
    else if (arg == "--output" && i + 1 < argc)
      options.output = argv[++i];
    else if (command == "run")
      options.runner_arguments.push_back(arg);
    else
    {
      std::cerr << "unknown or incomplete option: " << arg << '\n';
      return 2;
    }
  }
  if (options.output.empty())
    options.output = DefaultOutput();
  if (options.backend != "c" && options.backend != "llvm")
  {
    std::cerr << "unknown backend: " << options.backend << '\n';
    return 2;
  }
#if !defined(MODERNGEKKO_DOLRECOMP_LLVM)
  if (options.backend == "llvm")
  {
    std::cerr << "LLVM backend is unavailable in this build\n";
    return 2;
  }
#endif
  if (command == "inspect")
    return Inspect(root, options.output);
  if (command != "build" && command != "run")
  {
    Usage();
    return 2;
  }
  const auto module = Build(argv[0], root, options);
  if (!module)
    return 1;
  if (command == "build")
    return 0;
  std::string run = Quote(SiblingExecutable(argv[0], "moderngekko-run")) + " --game " +
                    Quote(root) + " --module " + Quote(*module);
  for (const std::string& arg : options.runner_arguments)
    run += " " + Quote(arg);
  return RunCommand(run) ? 0 : 1;
}
