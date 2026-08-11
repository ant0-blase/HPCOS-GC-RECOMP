// SPDX-License-Identifier: GPL-2.0-or-later

#include "Common/Align.h"
#include "Common/BitUtils.h"
#include "Common/Logging/Log.h"
#include "Core/HW/Memmap.h"
#include "Core/PowerPC/Gekko.h"
#include "Core/PowerPC/JitInterface.h"
#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/System.h"

#ifdef _M_X86_64
#include <emmintrin.h>
#endif
#include <cstring>
#include <memory>
#include <optional>
#include <span>

namespace PowerPC
{

void MMU::ClearPageTable()
{
  m_memory.RemoveAllPageTableMappings();
  m_page_mappings.clear();
  m_page_table.clear();
}

void MMU::ReloadPageTable()
{
  m_page_mappings.clear();

  m_temp_page_table.clear();
  std::swap(m_page_table, m_temp_page_table);

  if (m_system.GetJitInterface().WantsPageTableMappings())
    PageTableUpdated(m_temp_page_table);
  else
    m_memory.RemoveAllPageTableMappings();
}

void MMU::PageTableUpdated()
{
  m_ppc_state.pagetable_update_pending = false;

  if (!m_system.GetJitInterface().WantsPageTableMappings())
  {
    ClearPageTable();
    return;
  }

  const u32 page_table_base = m_ppc_state.pagetable_base;
  const u32 page_table_end =
      Common::AlignUp(page_table_base | m_ppc_state.pagetable_mask, PAGE_TABLE_MIN_SIZE);
  const u32 page_table_size = page_table_end - page_table_base;

  u8* page_table_view = m_system.GetMemory().GetPointerForRange(page_table_base, page_table_size);
  if (!page_table_view)
  {
    WARN_LOG_FMT(POWERPC, "Failed to read page table at {:#010x}-{:#010x}", page_table_base,
                 page_table_end);
    ClearPageTable();
    return;
  }

  PageTableUpdated(std::span(page_table_view, page_table_size));
}

void MMU::PageTableUpdated(std::span<const u8> page_table)
{
  if (page_table.size() % PAGE_TABLE_MIN_SIZE != 0)
  {
    PanicAlertFmt("Impossible page table size {}", page_table.size());
    ClearPageTable();
    return;
  }

  m_removed_mappings.clear();
  m_added_readonly_mappings.clear();
  m_added_readwrite_mappings.clear();

  if (m_page_table.size() != page_table.size())
  {
    m_memory.RemoveAllPageTableMappings();
    m_page_mappings.clear();
    m_page_table.resize(0);
    m_page_table.resize(page_table.size(), 0);
  }

  u8* old_page_table = m_page_table.data();
  const u8* new_page_table = page_table.data();

  constexpr auto compare_64_bytes = [](const u8* a, const u8* b) -> bool {
#ifdef _M_X86_64
    const __m128i a1 = _mm_load_si128(reinterpret_cast<const __m128i*>(a));
    const __m128i b1 = _mm_load_si128(reinterpret_cast<const __m128i*>(b));
    const __m128i cmp1 = _mm_cmpeq_epi8(a1, b1);
    const __m128i a2 = _mm_load_si128(reinterpret_cast<const __m128i*>(a + 0x10));
    const __m128i b2 = _mm_load_si128(reinterpret_cast<const __m128i*>(b + 0x10));
    const __m128i cmp2 = _mm_cmpeq_epi8(a2, b2);
    const __m128i cmp12 = _mm_and_si128(cmp1, cmp2);
    const __m128i a3 = _mm_load_si128(reinterpret_cast<const __m128i*>(a + 0x20));
    const __m128i b3 = _mm_load_si128(reinterpret_cast<const __m128i*>(b + 0x20));
    const __m128i cmp3 = _mm_cmpeq_epi8(a3, b3);
    const __m128i a4 = _mm_load_si128(reinterpret_cast<const __m128i*>(a + 0x30));
    const __m128i b4 = _mm_load_si128(reinterpret_cast<const __m128i*>(b + 0x30));
    const __m128i cmp4 = _mm_cmpeq_epi8(a4, b4);
    const __m128i cmp34 = _mm_and_si128(cmp3, cmp4);
    const __m128i cmp1234 = _mm_and_si128(cmp12, cmp34);
    return _mm_movemask_epi8(cmp1234) == 0xFFFF;
#else
    return std::memcmp(std::assume_aligned<64>(a), std::assume_aligned<64>(b), 64) == 0;
#endif
  };

  const auto get_page_index = [this](UPTE_Lo pte1, u32 hash) -> std::optional<EffectiveAddress> {
    u32 page_index_from_hash = hash ^ pte1.VSID;
    if (pte1.H)
      page_index_from_hash = ~page_index_from_hash;

    EffectiveAddress logical_address;
    logical_address.offset = 0;
    logical_address.page_index = page_index_from_hash;
    logical_address.API = pte1.API;

    const u32 api_mask = ((m_ppc_state.pagetable_mask & ~m_ppc_state.pagetable_base) >> 16) & 0x3f;
    if ((pte1.API & api_mask) != ((page_index_from_hash >> 10) & api_mask))
      return std::nullopt;

    return logical_address;
  };

  const auto fixup_shadowed_mappings = [this, old_page_table, new_page_table](
                                           UPTE_Lo pte1, u32 page_table_offset, bool* run_pass_2) {
    DEBUG_ASSERT(pte1.V == 1);

    bool switched_to_secondary = false;

    while (true)
    {
      const u32 big_endian_pte1 = Common::swap32(pte1.Hex);
      const u32 pteg_start = Common::AlignDown(page_table_offset, 64);
      const u32 pteg_end = pteg_start + 64;
      for (u32 i = page_table_offset; i < pteg_end; i += 8)
      {
        if (std::memcmp(new_page_table + i, &big_endian_pte1, sizeof(big_endian_pte1)) == 0)
        {
          if (std::memcmp(old_page_table + i, new_page_table + i, 8) == 0)
          {
            UPTE_Hi pte2(Common::swap32(old_page_table + i + 4));
            pte2.reserved_1 = pte2.reserved_1 ^ 1;
            const u32 big_endian_pte2 = Common::swap32(pte2.Hex);
            std::memcpy(old_page_table + i + 4, &big_endian_pte2, sizeof(big_endian_pte2));

            if (switched_to_secondary)
              *run_pass_2 = true;
          }
          return;
        }
      }

      if (pte1.H == 1)
      {
        return;
      }
      else
      {
        pte1.H = 1;
        page_table_offset =
            ((~pteg_start & m_ppc_state.pagetable_mask) | m_ppc_state.pagetable_base) -
            m_ppc_state.pagetable_base;
        switched_to_secondary = true;
      }
    }
  };

  const auto try_add_mapping = [this, &get_page_index](UPTE_Lo pte1, UPTE_Hi pte2,
                                                       u32 page_table_offset) {
    std::optional<EffectiveAddress> logical_address = get_page_index(pte1, page_table_offset / 64);
    if (!logical_address)
      return;

    for (u32 i = 0; i < std::size(m_ppc_state.sr); ++i)
    {
      const auto sr = UReg_SR{m_ppc_state.sr[i]};
      if (sr.VSID != pte1.VSID || sr.T != 0)
        continue;

      logical_address->SR = i;

      bool host_mapping = true;

      const bool wi = (pte2.WIMG & 0b1100) != 0;
      if (wi)
      {
        host_mapping = false;
      }
      else if (m_dbat_table[logical_address->Hex >> PowerPC::BAT_INDEX_SHIFT] &
               PowerPC::BAT_MAPPED_BIT)
      {
        host_mapping = false;
      }
      else if (m_power_pc.GetMemChecks().OverlapsMemcheck(logical_address->Hex,
                                                          PowerPC::HW_PAGE_SIZE))
      {
        host_mapping = false;
      }

      const u32 priority = (page_table_offset % 64 / 8) | (pte1.H << 3);
      const PageMapping page_mapping(pte2.RPN, host_mapping, priority);

      const auto it = m_page_mappings.find(logical_address->Hex);
      if (it == m_page_mappings.end()) [[likely]]
      {
        m_page_mappings.emplace(logical_address->Hex, page_mapping);
      }
      else
      {
        if (it->second.priority < priority)
        {
          continue;
        }

        if (it->second.host_mapping)
          m_removed_mappings.emplace(it->first);
        it->second.Hex = page_mapping.Hex;
      }

      if (host_mapping && pte2.R)
      {
        const u32 physical_address = pte2.RPN << 12;
        (pte2.C ? m_added_readwrite_mappings : m_added_readonly_mappings)
            .emplace(logical_address->Hex, physical_address);
      }
    }
  };

  bool run_pass_2 = false;

  for (u32 i = 0; i < page_table.size(); i += PAGE_TABLE_MIN_SIZE)
  {
    if ((i & m_ppc_state.pagetable_mask) != i || (i & m_ppc_state.pagetable_base) != 0)
      continue;

    for (u32 j = 0; j < PAGE_TABLE_MIN_SIZE; j += 64)
    {
      if (compare_64_bytes(old_page_table + i + j, new_page_table + i + j)) [[likely]]
        continue;

      for (u32 k = 0; k < 64; k += 8)
      {
        if (std::memcmp(old_page_table + i + j + k, new_page_table + i + j + k, 8) == 0) [[likely]]
          continue;

        UPTE_Lo old_pte1(Common::swap32(old_page_table + i + j + k));
        if (old_pte1.V)
        {
          const u32 priority = (k / 8) | (old_pte1.H << 3);
          std::optional<EffectiveAddress> logical_address = get_page_index(old_pte1, (i + j) / 64);
          if (!logical_address)
            continue;

          for (u32 l = 0; l < std::size(m_ppc_state.sr); ++l)
          {
            const auto sr = UReg_SR{m_ppc_state.sr[l]};
            if (sr.VSID != old_pte1.VSID || sr.T != 0)
              continue;

            logical_address->SR = l;

            const auto it = m_page_mappings.find(logical_address->Hex);
            if (it != m_page_mappings.end() && priority == it->second.priority)
            {
              if (it->second.host_mapping)
                m_removed_mappings.emplace(logical_address->Hex);
              m_page_mappings.erase(it);

              fixup_shadowed_mappings(old_pte1, i + j + k, &run_pass_2);
            }
          }
        }

        UPTE_Lo new_pte1(Common::swap32(new_page_table + i + j + k));
        UPTE_Hi new_pte2(Common::swap32(new_page_table + i + j + k + 4));
        if (new_pte1.V)
        {
          if (new_pte1.H)
          {
            run_pass_2 = true;
            continue;
          }

          try_add_mapping(new_pte1, new_pte2, i + j + k);
        }

        std::memcpy(old_page_table + i + j + k, new_page_table + i + j + k, 8);
      }
    }
  }

  if (run_pass_2) [[unlikely]]
  {
    for (u32 i = 0; i < page_table.size(); i += PAGE_TABLE_MIN_SIZE)
    {
      if ((i & m_ppc_state.pagetable_mask) != i || (i & m_ppc_state.pagetable_base) != 0)
        continue;

      for (u32 j = 0; j < PAGE_TABLE_MIN_SIZE; j += 64)
      {
        if (compare_64_bytes(old_page_table + i + j, new_page_table + i + j)) [[likely]]
          continue;

        for (u32 k = 0; k < 64; k += 8)
        {
          if (std::memcmp(old_page_table + i + j + k, new_page_table + i + j + k, 8) == 0)
              [[likely]]
          {
            continue;
          }

          UPTE_Lo new_pte1(Common::swap32(new_page_table + i + j + k));
          UPTE_Hi new_pte2(Common::swap32(new_page_table + i + j + k + 4));

          DEBUG_ASSERT(new_pte1.V == 1);
          DEBUG_ASSERT(new_pte1.H == 1);
          try_add_mapping(new_pte1, new_pte2, i + j + k);

          std::memcpy(old_page_table + i + j + k, new_page_table + i + j + k, 8);
        }
      }
    }
  }

  if (!m_removed_mappings.empty())
    m_memory.RemovePageTableMappings(m_removed_mappings);

  for (const auto& [logical_address, physical_address] : m_added_readonly_mappings)
    m_memory.AddPageTableMapping(logical_address, physical_address, false);

  for (const auto& [logical_address, physical_address] : m_added_readwrite_mappings)
    m_memory.AddPageTableMapping(logical_address, physical_address, true);
}

void MMU::PageTableUpdatedFromJit(MMU* mmu)
{
  mmu->PageTableUpdated();
}

}  // namespace PowerPC
