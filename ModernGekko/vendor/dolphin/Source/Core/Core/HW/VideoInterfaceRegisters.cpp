// Copyright 2026 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Core/HW/VideoInterface.h"

#include <algorithm>
#include <array>
#include <cmath>

#include "Common/ChunkFile.h"
#include "Common/CommonTypes.h"
#include "Common/Config/Config.h"
#include "Common/Logging/Log.h"

#include "Core/Config/GraphicsSettings.h"
#include "Core/Config/MainSettings.h"
#include "Core/Config/ConfigManager.h"
#include "Core/CoreTiming.h"
#include "Core/System.h"
#include "Core/HW/MMIO.h"
#include "Core/HW/ProcessorInterface.h"

namespace VideoInterface
{

void VideoInterfaceManager::RegisterMMIO(MMIO::Mapping* mmio, u32 base)
{
  struct MappedVar
  {
    u32 addr;
    u16* ptr;
  };

  std::array<MappedVar, 46> directly_mapped_vars{{
      {VI_VERTICAL_TIMING, &m_vertical_timing_register.Hex},
      {VI_HORIZONTAL_TIMING_0_HI, &m_h_timing_0.Hi},
      {VI_HORIZONTAL_TIMING_0_LO, &m_h_timing_0.Lo},
      {VI_HORIZONTAL_TIMING_1_HI, &m_h_timing_1.Hi},
      {VI_HORIZONTAL_TIMING_1_LO, &m_h_timing_1.Lo},
      {VI_VBLANK_TIMING_ODD_HI, &m_vblank_timing_odd.Hi},
      {VI_VBLANK_TIMING_ODD_LO, &m_vblank_timing_odd.Lo},
      {VI_VBLANK_TIMING_EVEN_HI, &m_vblank_timing_even.Hi},
      {VI_VBLANK_TIMING_EVEN_LO, &m_vblank_timing_even.Lo},
      {VI_BURST_BLANKING_ODD_HI, &m_burst_blanking_odd.Hi},
      {VI_BURST_BLANKING_ODD_LO, &m_burst_blanking_odd.Lo},
      {VI_BURST_BLANKING_EVEN_HI, &m_burst_blanking_even.Hi},
      {VI_BURST_BLANKING_EVEN_LO, &m_burst_blanking_even.Lo},
      {VI_FB_LEFT_TOP_LO, &m_xfb_info_top.Lo},
      {VI_FB_RIGHT_TOP_LO, &m_xfb_3d_info_top.Lo},
      {VI_FB_LEFT_BOTTOM_LO, &m_xfb_info_bottom.Lo},
      {VI_FB_RIGHT_BOTTOM_LO, &m_xfb_3d_info_bottom.Lo},
      {VI_PRERETRACE_LO, &m_interrupt_register[0].Lo},
      {VI_POSTRETRACE_LO, &m_interrupt_register[1].Lo},
      {VI_DISPLAY_INTERRUPT_2_LO, &m_interrupt_register[2].Lo},
      {VI_DISPLAY_INTERRUPT_3_LO, &m_interrupt_register[3].Lo},
      {VI_DISPLAY_LATCH_0_HI, &m_latch_register[0].Hi},
      {VI_DISPLAY_LATCH_0_LO, &m_latch_register[0].Lo},
      {VI_DISPLAY_LATCH_1_HI, &m_latch_register[1].Hi},
      {VI_DISPLAY_LATCH_1_LO, &m_latch_register[1].Lo},
      {VI_HSCALEW, &m_picture_configuration.Hex},
      {VI_HSCALER, &m_horizontal_scaling.Hex},
      {VI_FILTER_COEF_0_HI, &m_filter_coef_tables.Tables02[0].Hi},
      {VI_FILTER_COEF_0_LO, &m_filter_coef_tables.Tables02[0].Lo},
      {VI_FILTER_COEF_1_HI, &m_filter_coef_tables.Tables02[1].Hi},
      {VI_FILTER_COEF_1_LO, &m_filter_coef_tables.Tables02[1].Lo},
      {VI_FILTER_COEF_2_HI, &m_filter_coef_tables.Tables02[2].Hi},
      {VI_FILTER_COEF_2_LO, &m_filter_coef_tables.Tables02[2].Lo},
      {VI_FILTER_COEF_3_HI, &m_filter_coef_tables.Tables36[0].Hi},
      {VI_FILTER_COEF_3_LO, &m_filter_coef_tables.Tables36[0].Lo},
      {VI_FILTER_COEF_4_HI, &m_filter_coef_tables.Tables36[1].Hi},
      {VI_FILTER_COEF_4_LO, &m_filter_coef_tables.Tables36[1].Lo},
      {VI_FILTER_COEF_5_HI, &m_filter_coef_tables.Tables36[2].Hi},
      {VI_FILTER_COEF_5_LO, &m_filter_coef_tables.Tables36[2].Lo},
      {VI_FILTER_COEF_6_HI, &m_filter_coef_tables.Tables36[3].Hi},
      {VI_FILTER_COEF_6_LO, &m_filter_coef_tables.Tables36[3].Lo},
      {VI_CLOCK, &m_clock},
      {VI_DTV_STATUS, &m_dtv_status.Hex},
      {VI_FBWIDTH, &m_fb_width.Hex},
      {VI_BORDER_BLANK_END, &m_border_hblank.Lo},
      {VI_BORDER_BLANK_START, &m_border_hblank.Hi},
  }};

  // Declare all the boilerplate direct MMIOs.
  for (auto& mapped_var : directly_mapped_vars)
  {
    mmio->Register(base | mapped_var.addr, MMIO::DirectRead<u16>(mapped_var.ptr),
                   MMIO::DirectWrite<u16>(mapped_var.ptr));
  }

  std::array<MappedVar, 8> update_params_on_read_vars{{
      {VI_VERTICAL_TIMING, &m_vertical_timing_register.Hex},
      {VI_HORIZONTAL_TIMING_0_HI, &m_h_timing_0.Hi},
      {VI_HORIZONTAL_TIMING_0_LO, &m_h_timing_0.Lo},
      {VI_VBLANK_TIMING_ODD_HI, &m_vblank_timing_odd.Hi},
      {VI_VBLANK_TIMING_ODD_LO, &m_vblank_timing_odd.Lo},
      {VI_VBLANK_TIMING_EVEN_HI, &m_vblank_timing_even.Hi},
      {VI_VBLANK_TIMING_EVEN_LO, &m_vblank_timing_even.Lo},
      {VI_CLOCK, &m_clock},
  }};

  // Declare all the MMIOs that update timing params.
  for (auto& mapped_var : update_params_on_read_vars)
  {
    mmio->Register(base | mapped_var.addr, MMIO::DirectRead<u16>(mapped_var.ptr),
                   MMIO::ComplexWrite<u16>([mapped_var](Core::System& system, u32, u16 val) {
                     *mapped_var.ptr = val;
                     system.GetVideoInterface().UpdateParameters();
                   }));
  }

  // XFB related MMIOs that require special handling on writes.
  mmio->Register(base | VI_FB_LEFT_TOP_HI, MMIO::DirectRead<u16>(&m_xfb_info_top.Hi),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_xfb_info_top.Hi = val;
                   if (vi.m_xfb_info_top.CLRPOFF)
                     vi.m_xfb_info_top.POFF = 0;
                 }));
  mmio->Register(base | VI_FB_LEFT_BOTTOM_HI, MMIO::DirectRead<u16>(&m_xfb_info_bottom.Hi),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_xfb_info_bottom.Hi = val;
                   if (vi.m_xfb_info_bottom.CLRPOFF)
                     vi.m_xfb_info_bottom.POFF = 0;
                 }));
  mmio->Register(base | VI_FB_RIGHT_TOP_HI, MMIO::DirectRead<u16>(&m_xfb_3d_info_top.Hi),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_xfb_3d_info_top.Hi = val;
                   if (vi.m_xfb_3d_info_top.CLRPOFF)
                     vi.m_xfb_3d_info_top.POFF = 0;
                 }));
  mmio->Register(base | VI_FB_RIGHT_BOTTOM_HI, MMIO::DirectRead<u16>(&m_xfb_3d_info_bottom.Hi),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_xfb_3d_info_bottom.Hi = val;
                   if (vi.m_xfb_3d_info_bottom.CLRPOFF)
                     vi.m_xfb_3d_info_bottom.POFF = 0;
                 }));

  // MMIOs with unimplemented writes that trigger warnings.
  mmio->Register(
      base | VI_VERTICAL_BEAM_POSITION, MMIO::ComplexRead<u16>([](Core::System& system, u32) {
        auto& vi = system.GetVideoInterface();
        return 1 + (vi.m_half_line_count) / 2;
      }),
      MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
        WARN_LOG_FMT(
            VIDEOINTERFACE,
            "Changing vertical beam position to {:#06x} - not documented or implemented yet", val);
      }));
  mmio->Register(
      base | VI_HORIZONTAL_BEAM_POSITION, MMIO::ComplexRead<u16>([](Core::System& system, u32) {
        auto& vi = system.GetVideoInterface();
        u16 value = static_cast<u16>(
            1 + vi.m_h_timing_0.HLW *
                    (system.GetCoreTiming().GetTicks() - vi.m_ticks_last_line_start) /
                    (vi.GetTicksPerHalfLine()));
        return std::clamp<u16>(value, 1, vi.m_h_timing_0.HLW * 2);
      }),
      MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
        WARN_LOG_FMT(
            VIDEOINTERFACE,
            "Changing horizontal beam position to {:#06x} - not documented or implemented yet",
            val);
      }));

  // The following MMIOs are interrupts related and update interrupt status
  // on writes.
  mmio->Register(base | VI_PRERETRACE_HI, MMIO::DirectRead<u16>(&m_interrupt_register[0].Hi),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_interrupt_register[0].Hi = val;
                   vi.UpdateInterrupts();
                 }));
  mmio->Register(base | VI_POSTRETRACE_HI, MMIO::DirectRead<u16>(&m_interrupt_register[1].Hi),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_interrupt_register[1].Hi = val;
                   vi.UpdateInterrupts();
                 }));
  mmio->Register(base | VI_DISPLAY_INTERRUPT_2_HI,
                 MMIO::DirectRead<u16>(&m_interrupt_register[2].Hi),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_interrupt_register[2].Hi = val;
                   vi.UpdateInterrupts();
                 }));
  mmio->Register(base | VI_DISPLAY_INTERRUPT_3_HI,
                 MMIO::DirectRead<u16>(&m_interrupt_register[3].Hi),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_interrupt_register[3].Hi = val;
                   vi.UpdateInterrupts();
                 }));

  // Unknown anti-aliasing related MMIO register: puts a warning on log and
  // needs to shift/mask when reading/writing.
  mmio->Register(base | VI_UNK_AA_REG_HI, MMIO::ComplexRead<u16>([](Core::System& system, u32) {
                   auto& vi = system.GetVideoInterface();
                   return vi.m_unknown_aa_register >> 16;
                 }),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_unknown_aa_register =
                       (vi.m_unknown_aa_register & 0x0000FFFF) | ((u32)val << 16);
                   WARN_LOG_FMT(VIDEOINTERFACE, "Writing to the unknown AA register (hi)");
                 }));
  mmio->Register(base | VI_UNK_AA_REG_LO, MMIO::ComplexRead<u16>([](Core::System& system, u32) {
                   auto& vi = system.GetVideoInterface();
                   return vi.m_unknown_aa_register & 0xFFFF;
                 }),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();
                   vi.m_unknown_aa_register = (vi.m_unknown_aa_register & 0xFFFF0000) | val;
                   WARN_LOG_FMT(VIDEOINTERFACE, "Writing to the unknown AA register (lo)");
                 }));

  // Control register writes only updates some select bits, and additional
  // processing needs to be done if a reset is requested.
  mmio->Register(base | VI_CONTROL_REGISTER, MMIO::DirectRead<u16>(&m_display_control_register.Hex),
                 MMIO::ComplexWrite<u16>([](Core::System& system, u32, u16 val) {
                   auto& vi = system.GetVideoInterface();

                   UVIDisplayControlRegister tmpConfig(val);
                   vi.m_display_control_register.ENB = tmpConfig.ENB;
                   vi.m_display_control_register.NIN = tmpConfig.NIN;
                   vi.m_display_control_register.DLR = tmpConfig.DLR;
                   vi.m_display_control_register.LE0 = tmpConfig.LE0;
                   vi.m_display_control_register.LE1 = tmpConfig.LE1;
                   vi.m_display_control_register.FMT = tmpConfig.FMT;

                   if (tmpConfig.RST)
                   {
                     // shuffle2 clear all data, reset to default vals, and enter idle mode
                     vi.m_display_control_register.RST = 0;
                     vi.m_interrupt_register = {};
                     vi.UpdateInterrupts();
                   }

                   vi.UpdateParameters();
                 }));

  // Map 8 bit reads (not writes) to 16 bit reads.
  for (u32 i = 0; i < 0x1000; i += 2)
  {
    mmio->Register(base | i, MMIO::ReadToLarger<u8>(mmio, base | i, 8), MMIO::InvalidWrite<u8>());
    mmio->Register(base | (i + 1), MMIO::ReadToLarger<u8>(mmio, base | i, 0),
                   MMIO::InvalidWrite<u8>());
  }

  // Map 32 bit reads and writes to 16 bit reads and writes.
  for (u32 i = 0; i < 0x1000; i += 4)
  {
    mmio->Register(base | i, MMIO::ReadToSmaller<u32>(mmio, base | i, base | (i + 2)),
                   MMIO::WriteToSmaller<u32>(mmio, base | i, base | (i + 2)));
  }
}

} // namespace VideoInterface
