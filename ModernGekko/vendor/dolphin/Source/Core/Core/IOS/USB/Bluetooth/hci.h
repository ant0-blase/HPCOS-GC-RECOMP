// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

// Dolphin notes:
//  Added some info from bluetooth.h
//  All packet headers have had the packet type field removed. This is because
//   IOS adds the packet type to the header, and strips it before returning the
//   packet to the overlying Bluetooth stack.

/*	$NetBSD: hci.h,v 1.33 2009/09/11 18:35:50 plunky Exp $	*/

/*-
 * Copyright (c) 2005 Iain Hibbert.
 * Copyright (c) 2006 Itronix Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of Itronix Inc. may not be used to endorse
 *    or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ITRONIX INC. ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL ITRONIX INC. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/*-
 * Copyright (c) 2001 Maksim Yevmenkin <m_evmenkin@yahoo.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: hci.h,v 1.33 2009/09/11 18:35:50 plunky Exp $
 * $FreeBSD: src/sys/netgraph/bluetooth/include/ng_hci.h,v 1.6 2005/01/07 01:45:43 imp Exp $
 */

/*
 * This file contains everything that applications need to know from
 * Host Controller Interface (HCI). Information taken from Bluetooth
 * Core Specifications (v1.1, v2.0 and v2.1)
 *
 * This file can be included by both kernel and userland applications.
 *
 * NOTE: Here and after Bluetooth device is called a "unit". Bluetooth
 *       specification refers to both devices and units. They are the
 *       same thing (I think), so to be consistent word "unit" will be
 *       used.
 */

#pragma once

#include <array>
#include <cstdint>

#include "Common/CommonTypes.h"

// All structs in this file are packed
#pragma pack(push, 1)

/* All sizes are in bytes */
#define BLUETOOTH_BDADDR_SIZE 6

/*
 * Bluetooth device address
 */
using bdaddr_t = std::array<u8, BLUETOOTH_BDADDR_SIZE>;
constexpr bdaddr_t BDADDR_ANY{};

/**************************************************************************
 **************************************************************************
 **                   Common defines and types (HCI)
 **************************************************************************
 **************************************************************************/

#define HCI_LAP_SIZE 3         /* unit LAP */
#define HCI_KEY_SIZE 16        /* link key */
#define HCI_PIN_SIZE 16        /* link PIN */
#define HCI_EVENT_MASK_SIZE 8  /* event mask */
#define HCI_CLASS_SIZE 3       /* unit class */
#define HCI_FEATURES_SIZE 8    /* LMP features */
#define HCI_UNIT_NAME_SIZE 248 /* unit name size */
#define HCI_DEVNAME_SIZE 16    /* same as dv_xname */
#define HCI_COMMANDS_SIZE 64   /* supported commands mask */

/* HCI specification */
#define HCI_SPEC_V10 0x00 /* v1.0b */
#define HCI_SPEC_V11 0x01 /* v1.1 */
#define HCI_SPEC_V12 0x02 /* v1.2 */
#define HCI_SPEC_V20 0x03 /* v2.0 + EDR */
#define HCI_SPEC_V21 0x04 /* v2.1 + EDR */
#define HCI_SPEC_V30 0x05 /* v3.0 + HS */
/* 0x06 - 0xFF - reserved for future use */

/* LMP features (and page 0 of extended features) */
/* ------------------- byte 0 --------------------*/
#define HCI_LMP_3SLOT 0x01
#define HCI_LMP_5SLOT 0x02
#define HCI_LMP_ENCRYPTION 0x04
#define HCI_LMP_SLOT_OFFSET 0x08
#define HCI_LMP_TIMIACCURACY 0x10
#define HCI_LMP_ROLE_SWITCH 0x20
#define HCI_LMP_HOLD_MODE 0x40
#define HCI_LMP_SNIFF_MODE 0x80
/* ------------------- byte 1 --------------------*/
#define HCI_LMP_PARK_MODE 0x01
#define HCI_LMP_RSSI 0x02
#define HCI_LMP_CHANNEL_QUALITY 0x04
#define HCI_LMP_SCO_LINK 0x08
#define HCI_LMP_HV2_PKT 0x10
#define HCI_LMP_HV3_PKT 0x20
#define HCI_LMP_ULAW_LOG 0x40
#define HCI_LMP_ALAW_LOG 0x80
/* ------------------- byte 2 --------------------*/
#define HCI_LMP_CVSD 0x01
#define HCI_LMP_PAGISCHEME 0x02
#define HCI_LMP_POWER_CONTROL 0x04
#define HCI_LMP_TRANSPARENT_SCO 0x08
#define HCI_LMP_FLOW_CONTROL_LAG0 0x10
#define HCI_LMP_FLOW_CONTROL_LAG1 0x20
#define HCI_LMP_FLOW_CONTROL_LAG2 0x40
#define HCI_LMP_BC_ENCRYPTION 0x80
/* ------------------- byte 3 --------------------*/
/* reserved				0x01 */
#define HCI_LMP_EDR_ACL_2MBPS 0x02
#define HCI_LMP_EDR_ACL_3MBPS 0x04
#define HCI_LMP_ENHANCED_ISCAN 0x08
#define HCI_LMP_INTERLACED_ISCAN 0x10
#define HCI_LMP_INTERLACED_PSCAN 0x20
#define HCI_LMP_RSSI_INQUIRY 0x40
#define HCI_LMP_EV3_PKT 0x80
/* ------------------- byte 4 --------------------*/
#define HCI_LMP_EV4_PKT 0x01
#define HCI_LMP_EV5_PKT 0x02
/* reserved				0x04 */
#define HCI_LMP_AFH_CAPABLE_SLAVE 0x08
#define HCI_LMP_AFH_CLASS_SLAVE 0x10
/* reserved				0x20 */
/* reserved				0x40 */
#define HCI_LMP_3SLOT_EDR_ACL 0x80
/* ------------------- byte 5 --------------------*/
#define HCI_LMP_5SLOT_EDR_ACL 0x01
#define HCI_LMP_SNIFF_SUBRATING 0x02
#define HCI_LMP_PAUSE_ENCRYPTION 0x04
#define HCI_LMP_AFH_CAPABLE_MASTER 0x08
#define HCI_LMP_AFH_CLASS_MASTER 0x10
#define HCI_LMP_EDR_eSCO_2MBPS 0x20
#define HCI_LMP_EDR_eSCO_3MBPS 0x40
#define HCI_LMP_3SLOT_EDR_eSCO 0x80
/* ------------------- byte 6 --------------------*/
#define HCI_LMP_EXTENDED_INQUIRY 0x01
/* reserved				0x02 */
/* reserved				0x04 */
#define HCI_LMP_SIMPLE_PAIRING 0x08
#define HCI_LMP_ENCAPSULATED_PDU 0x10
#define HCI_LMP_ERRDATA_REPORTING 0x20
#define HCI_LMP_NOFLUSH_PB_FLAG 0x40
/* reserved				0x80 */
/* ------------------- byte 7 --------------------*/
#define HCI_LMP_LINK_SUPERVISION_TO 0x01
#define HCI_LMP_INQ_RSP_TX_POWER 0x02
#define HCI_LMP_ENHANCED_POWER_CONTROL 0x04
#define HCI_LMP_EXTENDED_FEATURES 0x80

/* page 1 of extended features */
/* ------------------- byte 0 --------------------*/
#define HCI_LMP_SSP 0x01

/* Link types */
#define HCI_LINK_SCO 0x00  /* Voice */
#define HCI_LINK_ACL 0x01  /* Data */
#define HCI_LINK_eSCO 0x02 /* eSCO */
                           /* 0x03 - 0xFF - reserved for future use */

/*
 * ACL/SCO packet type bits are set to enable the
 * packet type, except for 2MBPS and 3MBPS when they
 * are unset to enable the packet type.
 */
/* ACL Packet types for "Create Connection" */
#define HCI_PKT_2MBPS_DH1 0x0002
#define HCI_PKT_3MBPS_DH1 0x0004
#define HCI_PKT_DM1 0x0008
#define HCI_PKT_DH1 0x0010
#define HCI_PKT_2MBPS_DH3 0x0100
#define HCI_PKT_3MBPS_DH3 0x0200
#define HCI_PKT_DM3 0x0400
#define HCI_PKT_DH3 0x0800
#define HCI_PKT_2MBPS_DH5 0x1000
#define HCI_PKT_3MBPS_DH5 0x2000
#define HCI_PKT_DM5 0x4000
#define HCI_PKT_DH5 0x8000

/* SCO Packet types for "Setup Synchronous Connection" */
#define HCI_PKT_HV1 0x0001
#define HCI_PKT_HV2 0x0002
#define HCI_PKT_HV3 0x0004
#define HCI_PKT_EV3 0x0008
#define HCI_PKT_EV4 0x0010
#define HCI_PKT_EV5 0x0020
#define HCI_PKT_2MBPS_EV3 0x0040
#define HCI_PKT_3MBPS_EV3 0x0080
#define HCI_PKT_2MBPS_EV5 0x0100
#define HCI_PKT_3MBPS_EV5 0x0200

/*
 * Connection modes/Unit modes
 *
 * This is confusing. It means that one of the units change its mode
 * for the specific connection. For example one connection was put on
 * hold (but i could be wrong :)
 */

/* Page scan modes (are deprecated) */
#define HCI_MANDATORY_PAGE_SCAN_MODE 0x00
#define HCI_OPTIONAL_PAGE_SCAN_MODE1 0x01
#define HCI_OPTIONAL_PAGE_SCAN_MODE2 0x02
#define HCI_OPTIONAL_PAGE_SCAN_MODE3 0x03
/* 0x04 - 0xFF - reserved for future use */

/* Page scan repetition modes */
#define HCI_SCAN_REP_MODE0 0x00
#define HCI_SCAN_REP_MODE1 0x01
#define HCI_SCAN_REP_MODE2 0x02
/* 0x03 - 0xFF - reserved for future use */

/* Page scan period modes */
#define HCI_PAGE_SCAN_PERIOD_MODE0 0x00
#define HCI_PAGE_SCAN_PERIOD_MODE1 0x01
#define HCI_PAGE_SCAN_PERIOD_MODE2 0x02
/* 0x03 - 0xFF - reserved for future use */

/* Scan enable */
#define HCI_NO_SCAN_ENABLE 0x00
#define HCI_INQUIRY_SCAN_ENABLE 0x01
#define HCI_PAGE_SCAN_ENABLE 0x02
/* 0x04 - 0xFF - reserved for future use */

/* Hold mode activities */
#define HCI_HOLD_MODE_NO_CHANGE 0x00
#define HCI_HOLD_MODE_SUSPEND_PAGE_SCAN 0x01
#define HCI_HOLD_MODE_SUSPEND_INQUIRY_SCAN 0x02
#define HCI_HOLD_MODE_SUSPEND_PERIOD_INQUIRY 0x04
/* 0x08 - 0x80 - reserved for future use */

/* Connection roles */
#define HCI_ROLE_MASTER 0x00
#define HCI_ROLE_SLAVE 0x01
/* 0x02 - 0xFF - reserved for future use */

/* Key flags */
#define HCI_USE_SEMI_PERMANENT_LINK_KEYS 0x00
#define HCI_USE_TEMPORARY_LINK_KEY 0x01
/* 0x02 - 0xFF - reserved for future use */

/* Pin types */
#define HCI_PIN_TYPE_VARIABLE 0x00
#define HCI_PIN_TYPE_FIXED 0x01

/* Link key types */
#define HCI_LINK_KEY_TYPE_COMBINATION_KEY 0x00
#define HCI_LINK_KEY_TYPE_LOCAL_UNIT_KEY 0x01
#define HCI_LINK_KEY_TYPE_REMOTE_UNIT_KEY 0x02
/* 0x03 - 0xFF - reserved for future use */

/* Encryption modes */
#define HCI_ENCRYPTION_MODE_NONE 0x00
#define HCI_ENCRYPTION_MODE_P2P 0x01
#define HCI_ENCRYPTION_MODE_ALL 0x02
/* 0x03 - 0xFF - reserved for future use */

/* Quality of service types */
#define HCI_SERVICE_TYPE_NO_TRAFFIC 0x00
#define HCI_SERVICE_TYPE_BEST_EFFORT 0x01
#define HCI_SERVICE_TYPE_GUARANTEED 0x02
/* 0x03 - 0xFF - reserved for future use */

/* Link policy settings */
#define HCI_LINK_POLICY_DISABLE_ALL_LM_MODES 0x0000
#define HCI_LINK_POLICY_ENABLE_ROLE_SWITCH 0x0001 /* Master/Slave switch */
#define HCI_LINK_POLICY_ENABLE_HOLD_MODE 0x0002
#define HCI_LINK_POLICY_ENABLE_SNIFF_MODE 0x0004
#define HCI_LINK_POLICY_ENABLE_PARK_MODE 0x0008
/* 0x0010 - 0x8000 - reserved for future use */

/* Event masks */
#define HCI_EVMSK_ALL 0x00000000ffffffff
#define HCI_EVMSK_NONE 0x0000000000000000
#define HCI_EVMSK_INQUIRY_COMPL 0x0000000000000001
#define HCI_EVMSK_INQUIRY_RESULT 0x0000000000000002
#define HCI_EVMSK_CON_COMPL 0x0000000000000004
#define HCI_EVMSK_CON_REQ 0x0000000000000008
#define HCI_EVMSK_DISCON_COMPL 0x0000000000000010
#define HCI_EVMSK_AUTH_COMPL 0x0000000000000020
#define HCI_EVMSK_REMOTE_NAME_REQ_COMPL 0x0000000000000040
#define HCI_EVMSK_ENCRYPTION_CHANGE 0x0000000000000080
#define HCI_EVMSK_CHANGE_CON_LINK_KEY_COMPL 0x0000000000000100
#define HCI_EVMSK_MASTER_LINK_KEY_COMPL 0x0000000000000200
#define HCI_EVMSK_READ_REMOTE_FEATURES_COMPL 0x0000000000000400
#define HCI_EVMSK_READ_REMOTE_VER_INFO_COMPL 0x0000000000000800
#define HCI_EVMSK_QOS_SETUP_COMPL 0x0000000000001000
#define HCI_EVMSK_COMMAND_COMPL 0x0000000000002000
#define HCI_EVMSK_COMMAND_STATUS 0x0000000000004000
#define HCI_EVMSK_HARDWARE_ERROR 0x0000000000008000
#define HCI_EVMSK_FLUSH_OCCUR 0x0000000000010000
#define HCI_EVMSK_ROLE_CHANGE 0x0000000000020000
#define HCI_EVMSK_NUM_COMPL_PKTS 0x0000000000040000
#define HCI_EVMSK_MODE_CHANGE 0x0000000000080000
#define HCI_EVMSK_RETURN_LINK_KEYS 0x0000000000100000
#define HCI_EVMSK_PIN_CODE_REQ 0x0000000000200000
#define HCI_EVMSK_LINK_KEY_REQ 0x0000000000400000
#define HCI_EVMSK_LINK_KEY_NOTIFICATION 0x0000000000800000
#define HCI_EVMSK_LOOPBACK_COMMAND 0x0000000001000000
#define HCI_EVMSK_DATA_BUFFER_OVERFLOW 0x0000000002000000
#define HCI_EVMSK_MAX_SLOT_CHANGE 0x0000000004000000
#define HCI_EVMSK_READ_CLOCK_OFFSET_COMLETE 0x0000000008000000
#define HCI_EVMSK_CON_PKT_TYPE_CHANGED 0x0000000010000000
#define HCI_EVMSK_QOS_VIOLATION 0x0000000020000000
#define HCI_EVMSK_PAGE_SCAN_MODE_CHANGE 0x0000000040000000
#define HCI_EVMSK_PAGE_SCAN_REP_MODE_CHANGE 0x0000000080000000
/* 0x0000000100000000 - 0x8000000000000000 - reserved for future use */

/* Filter types */
#define HCI_FILTER_TYPE_NONE 0x00
#define HCI_FILTER_TYPE_INQUIRY_RESULT 0x01
#define HCI_FILTER_TYPE_CON_SETUP 0x02
/* 0x03 - 0xFF - reserved for future use */

/* Filter condition types for HCI_FILTER_TYPE_INQUIRY_RESULT */
#define HCI_FILTER_COND_INQUIRY_NEW_UNIT 0x00
#define HCI_FILTER_COND_INQUIRY_UNIT_CLASS 0x01
#define HCI_FILTER_COND_INQUIRY_BDADDR 0x02
/* 0x03 - 0xFF - reserved for future use */

/* Filter condition types for HCI_FILTER_TYPE_CON_SETUP */
#define HCI_FILTER_COND_CON_ANY_UNIT 0x00
#define HCI_FILTER_COND_CON_UNIT_CLASS 0x01
#define HCI_FILTER_COND_CON_BDADDR 0x02
/* 0x03 - 0xFF - reserved for future use */

/* Xmit level types */
#define HCI_XMIT_LEVEL_CURRENT 0x00
#define HCI_XMIT_LEVEL_MAXIMUM 0x01
/* 0x02 - 0xFF - reserved for future use */

/* Host Controller to Host flow control */
#define HCI_HC2H_FLOW_CONTROL_NONE 0x00
#define HCI_HC2H_FLOW_CONTROL_ACL 0x01
#define HCI_HC2H_FLOW_CONTROL_SCO 0x02
#define HCI_HC2H_FLOW_CONTROL_BOTH 0x03
/* 0x04 - 0xFF - reserved future use */

/* Loopback modes */
#define HCI_LOOPBACK_NONE 0x00
#define HCI_LOOPBACK_LOCAL 0x01
#define HCI_LOOPBACK_REMOTE 0x02
/* 0x03 - 0xFF - reserved future use */

/**************************************************************************
 **************************************************************************
 **                 Link level defines, headers and types
 **************************************************************************
 **************************************************************************/

/*
 * Macro(s) to combine OpCode and extract OGF (OpCode Group Field)
 * and OCF (OpCode Command Field) from OpCode.
 */

#define HCI_OPCODE(gf, cf) ((((gf) & 0x3f) << 10) | ((cf) & 0x3ff))
#define HCI_OCF(op) ((op) & 0x3ff)
#define HCI_OGF(op) (((op) >> 10) & 0x3f)

/*
 * Macro(s) to extract/combine connection handle, BC (Broadcast) and
 * PB (Packet boundary) flags.
 */

#define HCI_CON_HANDLE(h) ((h) & 0x0fff)
#define HCI_PB_FLAG(h) (((h) & 0x3000) >> 12)
#define HCI_BC_FLAG(h) (((h) & 0xc000) >> 14)
#define HCI_MK_CON_HANDLE(h, pb, bc) (((h) & 0x0fff) | (((pb) & 3) << 12) | (((bc) & 3) << 14))

/* PB flag values */
/* 00 - reserved for future use */
#define HCI_PACKET_FRAGMENT 0x1
#define HCI_PACKET_START 0x2
/* 11 - reserved for future use */

/* BC flag values */
#define HCI_POINT2POINT 0x0       /* only Host controller to Host */
#define HCI_BROADCAST_ACTIVE 0x1  /* both directions */
#define HCI_BROADCAST_PICONET 0x2 /* both directions */
                                  /* 11 - reserved for future use */

/* HCI command packet header */
typedef struct
{
  // uint8_t		type;	/* MUST be 0x01 */
  uint16_t opcode; /* OpCode */
  uint8_t length;  /* parameter(s) length in bytes */
} hci_cmd_hdr_t;

#define HCI_CMD_PKT 0x01
#define HCI_CMD_PKT_SIZE (sizeof(hci_cmd_hdr_t) + 0xff)

/* ACL data packet header */
typedef struct
{
  // uint8_t		type;	     /* MUST be 0x02 */
  uint16_t con_handle; /* connection handle + PB + BC flags */
  uint16_t length;     /* payload length in bytes */
} hci_acldata_hdr_t;

#define HCI_ACL_DATA_PKT 0x02
#define HCI_ACL_PKT_SIZE (sizeof(hci_acldata_hdr_t) + 0xffff)

/* SCO data packet header */
typedef struct
{
  // uint8_t		type;	    /* MUST be 0x03 */
  uint16_t con_handle; /* connection handle + reserved bits */
  uint8_t length;      /* payload length in bytes */
} hci_scodata_hdr_t;

#define HCI_SCO_DATA_PKT 0x03
#define HCI_SCO_PKT_SIZE (sizeof(hci_scodata_hdr_t) + 0xff)

/* HCI event packet header */
typedef struct
{
  // uint8_t		type;	/* MUST be 0x04 */
  uint8_t event;  /* event */
  uint8_t length; /* parameter(s) length in bytes */
} hci_event_hdr_t;

#define HCI_EVENT_PKT 0x04
#define HCI_EVENT_PKT_SIZE (sizeof(hci_event_hdr_t) + 0xff)

/* HCI status return parameter */
typedef struct
{
  uint8_t status; /* 0x00 - success */
} hci_status_rp;


#pragma pack(pop)

#include "Core/IOS/USB/Bluetooth/hci_commands.h"
#include "Core/IOS/USB/Bluetooth/hci_events.h"
