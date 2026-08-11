// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/PowerPC/PPCSymbolDB.h"

#include <algorithm>
#include <cstring>
#include <map>
#include <mutex>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>

#include <fmt/format.h>

#include "Common/CommonTypes.h"
#include "Common/FileUtil.h"
#include "Common/IOFile.h"
#include "Common/Logging/Log.h"
#include "Common/StringUtil.h"
#include "Core/Config/ConfigManager.h"
#include "Core/Core.h"
#include "Core/Debugger/DebugInterface.h"
#include "Core/PowerPC/MMU.h"
#include "Core/PowerPC/PPCAnalyst.h"
#include "Core/PowerPC/PowerPC.h"
#include "Core/PowerPC/SignatureDB/SignatureDB.h"
#include "Core/System.h"

PPCSymbolDB::PPCSymbolDB() = default;

PPCSymbolDB::~PPCSymbolDB() = default;

// Adds the function to the list, unless it's already there
const Common::Symbol* PPCSymbolDB::AddFunction(const Core::CPUThreadGuard& guard, u32 start_addr)
{
  std::lock_guard lock(m_mutex);

  // It's already in the list
  if (m_functions.contains(start_addr))
    return nullptr;

  Common::Symbol symbol;
  if (!PPCAnalyst::AnalyzeFunction(guard, start_addr, symbol))
    return nullptr;

  const auto insert = m_functions.emplace(start_addr, std::move(symbol));
  Common::Symbol* ptr = &insert.first->second;
  ptr->type = Common::Symbol::Type::Function;
  m_checksum_to_function[ptr->hash].insert(ptr);
  return ptr;
}

void PPCSymbolDB::AddKnownSymbol(const Core::CPUThreadGuard& guard, u32 startAddr, u32 size,
                                 const std::string& name, const std::string& object_name,
                                 Common::Symbol::Type type)
{
  std::lock_guard lock(m_mutex);
  AddKnownSymbol(guard, startAddr, size, name, object_name, type, &m_functions,
                 &m_checksum_to_function);
}

void PPCSymbolDB::AddKnownSymbol(const Core::CPUThreadGuard& guard, u32 startAddr, u32 size,
                                 const std::string& name, const std::string& object_name,
                                 Common::Symbol::Type type, XFuncMap* functions,
                                 XFuncPtrMap* checksum_to_function)
{
  auto iter = functions->find(startAddr);
  if (iter != functions->end())
  {
    // already got it, let's just update name, checksum & size to be sure.
    Common::Symbol* tempfunc = &iter->second;
    tempfunc->Rename(name);
    tempfunc->object_name = object_name;
    tempfunc->hash = HashSignatureDB::ComputeCodeChecksum(guard, startAddr, startAddr + size - 4);
    tempfunc->type = type;
    tempfunc->size = size;
  }
  else
  {
    // new symbol. run analyze.
    auto& new_symbol = functions->emplace(startAddr, name).first->second;
    new_symbol.object_name = object_name;
    new_symbol.type = type;
    new_symbol.address = startAddr;

    if (new_symbol.type == Common::Symbol::Type::Function)
    {
      PPCAnalyst::AnalyzeFunction(guard, startAddr, new_symbol, size);
      // Do not truncate symbol when a size is expected
      if (size != 0 && new_symbol.size != size)
      {
        WARN_LOG_FMT(SYMBOLS, "Analysed symbol ({}) size mismatch, {} expected but {} computed",
                     name, size, new_symbol.size);
        new_symbol.size = size;
      }
      (*checksum_to_function)[new_symbol.hash].insert(&new_symbol);
    }
    else
    {
      new_symbol.size = size;
    }
  }
}

void PPCSymbolDB::AddKnownNote(u32 start_addr, u32 size, const std::string& name)
{
  std::lock_guard lock(m_mutex);
  AddKnownNote(start_addr, size, name, &m_notes);
}

void PPCSymbolDB::AddKnownNote(u32 start_addr, u32 size, const std::string& name, XNoteMap* notes)
{
  auto iter = notes->find(start_addr);

  if (iter != notes->end())
  {
    // Already got it, just update the name and size.
    Common::Note* tempfunc = &iter->second;
    tempfunc->name = name;
    tempfunc->size = size;
  }
  else
  {
    Common::Note tf;
    tf.name = name;
    tf.address = start_addr;
    tf.size = size;

    (*notes)[start_addr] = tf;
  }
}

void PPCSymbolDB::DetermineNoteLayers()
{
  std::lock_guard lock(m_mutex);
  DetermineNoteLayers(&m_notes);
}

void PPCSymbolDB::DetermineNoteLayers(XNoteMap* notes)
{
  if (notes->empty())
    return;

  for (auto& note : *notes)
    note.second.layer = 0;

  for (auto iter = notes->begin(); iter != notes->end(); ++iter)
  {
    const u32 range = iter->second.address + iter->second.size;
    auto search = notes->lower_bound(range);

    while (--search != iter)
      search->second.layer += 1;
  }
}

const Common::Symbol* PPCSymbolDB::GetSymbolFromAddr(u32 addr) const
{
  std::lock_guard lock(m_mutex);
  if (m_functions.empty())
    return nullptr;

  auto it = m_functions.lower_bound(addr);

  if (it != m_functions.end())
  {
    // If the address is exactly the start address of a symbol, we're done.
    if (it->second.address == addr)
      return &it->second;
  }
  if (it != m_functions.begin())
  {
    // Otherwise, check whether the address is within the bounds of a symbol.
    --it;
    if (addr >= it->second.address && addr < it->second.address + it->second.size)
      return &it->second;
  }

  return nullptr;
}

const Common::Note* PPCSymbolDB::GetNoteFromAddr(u32 addr) const
{
  std::lock_guard lock(m_mutex);
  if (m_notes.empty())
    return nullptr;

  auto itn = m_notes.lower_bound(addr);

  // If the address is exactly the start address of a symbol, we're done.
  if (itn != m_notes.end() && itn->second.address == addr)
    return &itn->second;

  // Otherwise, check whether the address is within the bounds of a symbol.
  if (itn == m_notes.begin())
    return nullptr;

  do
  {
    --itn;

    // If itn's range reaches the address.
    if (addr < itn->second.address + itn->second.size)
      return &itn->second;

    // If layer is 0, it's the last note that could possibly reach the address, as there are no more
    // underlying notes.
  } while (itn != m_notes.begin() && itn->second.layer != 0);

  return nullptr;
}

void PPCSymbolDB::DeleteFunction(u32 start_address)
{
  std::lock_guard lock(m_mutex);
  m_functions.erase(start_address);
}

void PPCSymbolDB::DeleteNote(u32 start_address)
{
  std::lock_guard lock(m_mutex);
  m_notes.erase(start_address);
}

std::string PPCSymbolDB::GetDescription(u32 addr) const
{
  if (const Common::Symbol* const symbol = GetSymbolFromAddr(addr))
    return symbol->name;
  return " --- ";
}

void PPCSymbolDB::FillInCallers()
{
  std::lock_guard lock(m_mutex);
  FillInCallers(&m_functions);
}

void PPCSymbolDB::FillInCallers(XFuncMap* functions)
{
  for (auto& p : *functions)
  {
    p.second.callers.clear();
  }

  for (auto& entry : *functions)
  {
    Common::Symbol& f = entry.second;
    for (const Common::SCall& call : f.calls)
    {
      const Common::SCall new_call(entry.first, call.call_address);
      const u32 function_address = call.function;

      auto func_iter = functions->find(function_address);
      if (func_iter != functions->end())
      {
        Common::Symbol& called_function = func_iter->second;
        called_function.callers.push_back(new_call);
      }
      else
      {
        // LOG(SYMBOLS, "FillInCallers tries to fill data in an unknown function 0x%08x.",
        // FunctionAddress);
        // TODO - analyze the function instead.
      }
    }
  }
}

void PPCSymbolDB::PrintCalls(u32 funcAddr) const
{
  std::lock_guard lock(m_mutex);

  const auto iter = m_functions.find(funcAddr);
  if (iter == m_functions.end())
  {
    WARN_LOG_FMT(SYMBOLS, "Symbol does not exist");
    return;
  }

  const Common::Symbol& f = iter->second;
  DEBUG_LOG_FMT(SYMBOLS, "The function {} at {:08x} calls:", f.name, f.address);
  for (const Common::SCall& call : f.calls)
  {
    const auto n = m_functions.find(call.function);
    if (n != m_functions.end())
    {
      DEBUG_LOG_FMT(SYMBOLS, "* {:08x} : {}", call.call_address, n->second.name);
    }
  }
}

void PPCSymbolDB::PrintCallers(u32 funcAddr) const
{
  std::lock_guard lock(m_mutex);

  const auto iter = m_functions.find(funcAddr);
  if (iter == m_functions.end())
    return;

  const Common::Symbol& f = iter->second;
  DEBUG_LOG_FMT(SYMBOLS, "The function {} at {:08x} is called by:", f.name, f.address);
  for (const Common::SCall& caller : f.callers)
  {
    const auto n = m_functions.find(caller.function);
    if (n != m_functions.end())
    {
      DEBUG_LOG_FMT(SYMBOLS, "* {:08x} : {}", caller.call_address, n->second.name);
    }
  }
}

void PPCSymbolDB::LogFunctionCall(u32 addr)
{
  std::lock_guard lock(m_mutex);

  auto iter = m_functions.find(addr);
  if (iter == m_functions.end())
    return;

  Common::Symbol& f = iter->second;
  f.num_calls++;
}
