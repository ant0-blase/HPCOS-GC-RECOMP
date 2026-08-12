// RecompCore: StaticRecomp fastmem fault recovery.
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/StaticRecomp/StaticRecompFastmem.h"

#include <algorithm>
#include <atomic>
#include <cstdint>
#include <cstring>
#include <vector>

#include "Common/Logging/Log.h"

namespace StaticRecompFastmem
{
namespace
{
struct Entry
{
  uintptr_t fault;
  uintptr_t fixup;
};

// Built once at module load and only read afterwards. HandleFault runs inside a
// signal handler, so it must not allocate, lock or call anything non-reentrant:
// it does a binary search over this array and nothing else. The pointer is
// published after the contents are final so a fault can never observe a
// half-filled table.
std::vector<Entry> s_entries;
std::atomic<const Entry*> s_table{nullptr};
std::atomic<size_t> s_count{0};

// Recovered faults. Fastmem only pays while these stay rare: a signal costs
// thousands of cycles, so a path that faults per access would be far slower
// than the range check it replaced. Reported at shutdown so that failure mode
// is visible as a number instead of as unexplained slowness.
std::atomic<uint64_t> s_recovered{0};

// An entry is two self-relative 32-bit offsets, so the section needs no
// relocation processing: at entry address E, the faulting instruction is at
// E + entry[0] and the fixup at E + 4 + entry[1].
constexpr size_t ENTRY_SIZE = 8;
}  // namespace

bool Register(const void* section_start, const void* section_end)
{
  Unregister();

  const auto* begin = static_cast<const uint8_t*>(section_start);
  const auto* end = static_cast<const uint8_t*>(section_end);
  if (!begin || !end || end <= begin)
    return true;  // Nothing to recover; a non-fastmem module is not an error.

  const size_t bytes = static_cast<size_t>(end - begin);
  if (bytes % ENTRY_SIZE != 0)
  {
    ERROR_LOG_FMT(POWERPC, "StaticRecomp: __fastmem_ex is {} bytes, not a multiple of {}.", bytes,
                  ENTRY_SIZE);
    return false;
  }

  const size_t count = bytes / ENTRY_SIZE;
  s_entries.resize(count);
  for (size_t i = 0; i < count; ++i)
  {
    const uint8_t* entry = begin + i * ENTRY_SIZE;
    int32_t fault_rel;
    int32_t fixup_rel;
    std::memcpy(&fault_rel, entry, sizeof(fault_rel));
    std::memcpy(&fixup_rel, entry + 4, sizeof(fixup_rel));
    s_entries[i].fault = reinterpret_cast<uintptr_t>(entry) + static_cast<intptr_t>(fault_rel);
    s_entries[i].fixup = reinterpret_cast<uintptr_t>(entry + 4) + static_cast<intptr_t>(fixup_rel);
  }

  // The assembler emits entries per translation unit and the linker just
  // concatenates them, so they arrive unsorted.
  std::sort(s_entries.begin(), s_entries.end(),
            [](const Entry& a, const Entry& b) { return a.fault < b.fault; });

  s_count.store(s_entries.size(), std::memory_order_relaxed);
  s_table.store(s_entries.data(), std::memory_order_release);
  INFO_LOG_FMT(POWERPC, "StaticRecomp: fastmem recovery armed with {} entries.", count);
  return true;
}

uint64_t RecoveredFaults()
{
  return s_recovered.load(std::memory_order_relaxed);
}

void Unregister()
{
  s_table.store(nullptr, std::memory_order_release);
  s_count.store(0, std::memory_order_relaxed);
  s_entries.clear();
  s_entries.shrink_to_fit();
}

bool HandleFault(SContext* ctx)
{
  const Entry* table = s_table.load(std::memory_order_acquire);
  if (!table)
    return false;
  const size_t count = s_count.load(std::memory_order_relaxed);
  if (count == 0)
    return false;

  const auto pc = static_cast<uintptr_t>(ctx->CTX_PC);
  const Entry* found = std::lower_bound(
      table, table + count, pc, [](const Entry& e, uintptr_t value) { return e.fault < value; });
  if (found == table + count || found->fault != pc)
    return false;

  // decltype on the member alone yields a reference; the unary plus makes it a
  // prvalue so this names the platform's register value type (greg_t and
  // friends) rather than a reference to it.
  ctx->CTX_PC = static_cast<decltype(+ctx->CTX_PC)>(found->fixup);
  s_recovered.fetch_add(1, std::memory_order_relaxed);
  return true;
}
}  // namespace StaticRecompFastmem
