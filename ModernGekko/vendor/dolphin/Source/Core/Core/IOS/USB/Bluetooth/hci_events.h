#pragma once

#pragma pack(push, 1)

/**************************************************************************
 **************************************************************************
 **                         Events and event parameters
 **************************************************************************
 **************************************************************************/

#define HCI_EVENT_INQUIRY_COMPL 0x01
typedef struct
{
  uint8_t status; /* 0x00 - success */
} hci_inquiry_compl_ep;

#define HCI_EVENT_INQUIRY_RESULT 0x02
typedef struct
{
  uint8_t num_responses; /* number of responses */
  /*	hci_inquiry_response[num_responses]   -- see below */
} hci_inquiry_result_ep;

typedef struct
{
  bdaddr_t bdaddr;                /* unit address */
  uint8_t page_scan_rep_mode;     /* page scan rep. mode */
  uint8_t page_scan_period_mode;  /* page scan period mode */
  uint8_t page_scan_mode;         /* page scan mode */
  uint8_t uclass[HCI_CLASS_SIZE]; /* unit class */
  uint16_t clock_offset;          /* clock offset */
} hci_inquiry_response;

#define HCI_EVENT_CON_COMPL 0x03
typedef struct
{
  uint8_t status;          /* 0x00 - success */
  uint16_t con_handle;     /* Connection handle */
  bdaddr_t bdaddr;         /* remote unit address */
  uint8_t link_type;       /* Link type */
  uint8_t encryption_mode; /* Encryption mode */
} hci_con_compl_ep;

#define HCI_EVENT_CON_REQ 0x04
typedef struct
{
  bdaddr_t bdaddr;                /* remote unit address */
  uint8_t uclass[HCI_CLASS_SIZE]; /* remote unit class */
  uint8_t link_type;              /* link type */
} hci_con_req_ep;

#define HCI_EVENT_DISCON_COMPL 0x05
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint8_t reason;      /* reason to disconnect */
} hci_discon_compl_ep;

#define HCI_EVENT_AUTH_COMPL 0x06
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
} hci_auth_compl_ep;

#define HCI_EVENT_REMOTE_NAME_REQ_COMPL 0x07
typedef struct
{
  uint8_t status;                /* 0x00 - success */
  bdaddr_t bdaddr;               /* remote unit address */
  char name[HCI_UNIT_NAME_SIZE]; /* remote unit name */
} hci_remote_name_req_compl_ep;

#define HCI_EVENT_ENCRYPTION_CHANGE 0x08
typedef struct
{
  uint8_t status;            /* 0x00 - success */
  uint16_t con_handle;       /* Connection handle */
  uint8_t encryption_enable; /* 0x00 - disable */
} hci_encryption_change_ep;

#define HCI_EVENT_CHANGE_CON_LINK_KEY_COMPL 0x09
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* Connection handle */
} hci_change_con_link_key_compl_ep;

#define HCI_EVENT_MASTER_LINK_KEY_COMPL 0x0a
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* Connection handle */
  uint8_t key_flag;    /* Key flag */
} hci_master_link_key_compl_ep;

#define HCI_EVENT_READ_REMOTE_FEATURES_COMPL 0x0b
typedef struct
{
  uint8_t status;                      /* 0x00 - success */
  uint16_t con_handle;                 /* Connection handle */
  uint8_t features[HCI_FEATURES_SIZE]; /* LMP features bitmsk*/
} hci_read_remote_features_compl_ep;

#define HCI_EVENT_READ_REMOTE_VER_INFO_COMPL 0x0c
typedef struct
{
  uint8_t status;          /* 0x00 - success */
  uint16_t con_handle;     /* Connection handle */
  uint8_t lmp_version;     /* LMP version */
  uint16_t manufacturer;   /* Hardware manufacturer name */
  uint16_t lmp_subversion; /* LMP sub-version */
} hci_read_remote_ver_info_compl_ep;

#define HCI_EVENT_QOS_SETUP_COMPL 0x0d
typedef struct
{
  uint8_t status;           /* 0x00 - success */
  uint16_t con_handle;      /* connection handle */
  uint8_t flags;            /* reserved for future use */
  uint8_t service_type;     /* service type */
  uint32_t token_rate;      /* bytes per second */
  uint32_t peak_bandwidth;  /* bytes per second */
  uint32_t latency;         /* microseconds */
  uint32_t delay_variation; /* microseconds */
} hci_qos_setup_compl_ep;

#define HCI_EVENT_COMMAND_COMPL 0x0e
typedef struct
{
  uint8_t num_cmd_pkts; /* # of HCI command packets */
  uint16_t opcode;      /* command OpCode */
                        /* command return parameters (if any) */
} hci_command_compl_ep;

#define HCI_EVENT_COMMAND_STATUS 0x0f
typedef struct
{
  uint8_t status;       /* 0x00 - pending */
  uint8_t num_cmd_pkts; /* # of HCI command packets */
  uint16_t opcode;      /* command OpCode */
} hci_command_status_ep;

#define HCI_EVENT_HARDWARE_ERROR 0x10
typedef struct
{
  uint8_t hardware_code; /* hardware error code */
} hci_hardware_error_ep;

#define HCI_EVENT_FLUSH_OCCUR 0x11
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_flush_occur_ep;

#define HCI_EVENT_ROLE_CHANGE 0x12
typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* address of remote unit */
  uint8_t role;    /* new connection role */
} hci_role_change_ep;

#define HCI_EVENT_NUM_COMPL_PKTS 0x13
typedef struct
{
  uint8_t num_con_handles; /* # of connection handles */
                           /* these are repeated "num_con_handles" times
                             uint16_t	con_handle; --- connection handle(s)
                             uint16_t	compl_pkts; --- # of completed packets */
} hci_num_compl_pkts_ep;

typedef struct
{
  uint16_t con_handle;
  uint16_t compl_pkts;
} hci_num_compl_pkts_info;

#define HCI_EVENT_MODE_CHANGE 0x14
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint8_t unit_mode;   /* remote unit mode */
  uint16_t interval;   /* interval * 0.625 msec */
} hci_mode_change_ep;

#define HCI_EVENT_RETURN_LINK_KEYS 0x15
typedef struct
{
  uint8_t num_keys; /* # of keys */
                    /* these are repeated "num_keys" times
                      bdaddr_t	bdaddr;               --- remote address(es)
                      uint8_t		key[HCI_KEY_SIZE]; --- key(s) */
} hci_return_link_keys_ep;

#define HCI_EVENT_PIN_CODE_REQ 0x16
typedef struct
{
  bdaddr_t bdaddr; /* remote unit address */
} hci_pin_code_req_ep;

#define HCI_EVENT_LINK_KEY_REQ 0x17
typedef struct
{
  bdaddr_t bdaddr; /* remote unit address */
} hci_link_key_req_ep;

#define HCI_EVENT_LINK_KEY_NOTIFICATION 0x18
typedef struct
{
  bdaddr_t bdaddr;           /* remote unit address */
  uint8_t key[HCI_KEY_SIZE]; /* link key */
  uint8_t key_type;          /* type of the key */
} hci_link_key_notification_ep;

#define HCI_EVENT_LOOPBACK_COMMAND 0x19
typedef hci_cmd_hdr_t hci_loopback_command_ep;

#define HCI_EVENT_DATA_BUFFER_OVERFLOW 0x1a
typedef struct
{
  uint8_t link_type; /* Link type */
} hci_data_buffer_overflow_ep;

#define HCI_EVENT_MAX_SLOT_CHANGE 0x1b
typedef struct
{
  uint16_t con_handle;   /* connection handle */
  uint8_t lmp_max_slots; /* Max. # of slots allowed */
} hci_max_slot_change_ep;

#define HCI_EVENT_READ_CLOCK_OFFSET_COMPL 0x1c
typedef struct
{
  uint8_t status;        /* 0x00 - success */
  uint16_t con_handle;   /* Connection handle */
  uint16_t clock_offset; /* Clock offset */
} hci_read_clock_offset_compl_ep;

#define HCI_EVENT_CON_PKT_TYPE_CHANGED 0x1d
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint16_t pkt_type;   /* packet type */
} hci_con_pkt_type_changed_ep;

#define HCI_EVENT_QOS_VIOLATION 0x1e
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_qos_violation_ep;

/* Page Scan Mode Change Event is deprecated */
#define HCI_EVENT_PAGE_SCAN_MODE_CHANGE 0x1f
typedef struct
{
  bdaddr_t bdaddr;        /* destination address */
  uint8_t page_scan_mode; /* page scan mode */
} hci_page_scan_mode_change_ep;

#define HCI_EVENT_PAGE_SCAN_REP_MODE_CHANGE 0x20
typedef struct
{
  bdaddr_t bdaddr;            /* destination address */
  uint8_t page_scan_rep_mode; /* page scan repetition mode */
} hci_page_scan_rep_mode_change_ep;

#define HCI_EVENT_FLOW_SPECIFICATION_COMPL 0x21
typedef struct
{
  uint8_t status;          /* 0x00 - success */
  uint16_t con_handle;     /* connection handle */
  uint8_t flags;           /* reserved */
  uint8_t direction;       /* flow direction */
  uint8_t type;            /* service type */
  uint32_t token_rate;     /* token rate */
  uint32_t bucket_size;    /* token bucket size */
  uint32_t peak_bandwidth; /* peak bandwidth */
  uint32_t latency;        /* access latency */
} hci_flow_specification_compl_ep;

#define HCI_EVENT_RSSI_RESULT 0x22
typedef struct
{
  uint8_t num_responses; /* number of responses */
  /*	hci_rssi_response[num_responses]   -- see below */
} hci_rssi_result_ep;

typedef struct
{
  bdaddr_t bdaddr;                /* unit address */
  uint8_t page_scan_rep_mode;     /* page scan rep. mode */
  uint8_t blank;                  /* reserved */
  uint8_t uclass[HCI_CLASS_SIZE]; /* unit class */
  uint16_t clock_offset;          /* clock offset */
  int8_t rssi;                    /* rssi */
} hci_rssi_response;

#define HCI_EVENT_READ_REMOTE_EXTENDED_FEATURES 0x23
typedef struct
{
  uint8_t status;                      /* 0x00 - success */
  uint16_t con_handle;                 /* connection handle */
  uint8_t page;                        /* page number */
  uint8_t max;                         /* max page number */
  uint8_t features[HCI_FEATURES_SIZE]; /* LMP features bitmsk*/
} hci_read_remote_extended_features_ep;

#define HCI_EVENT_SCO_CON_COMPL 0x2c
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  bdaddr_t bdaddr;     /* unit address */
  uint8_t link_type;   /* link type */
  uint8_t interval;    /* transmission interval */
  uint8_t window;      /* retransmission window */
  uint16_t rxlen;      /* rx packet length */
  uint16_t txlen;      /* tx packet length */
  uint8_t mode;        /* air mode */
} hci_sco_con_compl_ep;

#define HCI_EVENT_SCO_CON_CHANGED 0x2d
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint8_t interval;    /* transmission interval */
  uint8_t window;      /* retransmission window */
  uint16_t rxlen;      /* rx packet length */
  uint16_t txlen;      /* tx packet length */
} hci_sco_con_changed_ep;

#define HCI_EVENT_SNIFF_SUBRATING 0x2e
typedef struct
{
  uint8_t status;          /* 0x00 - success */
  uint16_t con_handle;     /* connection handle */
  uint16_t tx_latency;     /* max transmit latency */
  uint16_t rx_latency;     /* max receive latency */
  uint16_t remote_timeout; /* remote timeout */
  uint16_t local_timeout;  /* local timeout */
} hci_sniff_subrating_ep;

#define HCI_EVENT_EXTENDED_RESULT 0x2f
typedef struct
{
  uint8_t num_responses; /* must be 0x01 */
  bdaddr_t bdaddr;       /* remote device address */
  uint8_t page_scan_rep_mode;
  uint8_t reserved;
  uint8_t uclass[HCI_CLASS_SIZE];
  uint16_t clock_offset;
  int8_t rssi;
  uint8_t response[240]; /* extended inquiry response */
} hci_extended_result_ep;

#define HCI_EVENT_ENCRYPTION_KEY_REFRESH 0x30
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
} hci_encryption_key_refresh_ep;

#define HCI_EVENT_IO_CAPABILITY_REQ 0x31
typedef struct
{
  bdaddr_t bdaddr; /* remote device address */
} hci_io_capability_req_ep;

#define HCI_EVENT_IO_CAPABILITY_RSP 0x32
typedef struct
{
  bdaddr_t bdaddr; /* remote device address */
  uint8_t io_capability;
  uint8_t oob_data_present;
  uint8_t auth_requirement;
} hci_io_capability_rsp_ep;

#define HCI_EVENT_USER_CONFIRM_REQ 0x33
typedef struct
{
  bdaddr_t bdaddr; /* remote device address */
  uint32_t value;  /* 000000 - 999999 */
} hci_user_confirm_req_ep;

#define HCI_EVENT_USER_PASSKEY_REQ 0x34
typedef struct
{
  bdaddr_t bdaddr; /* remote device address */
} hci_user_passkey_req_ep;

#define HCI_EVENT_REMOTE_OOB_DATA_REQ 0x35
typedef struct
{
  bdaddr_t bdaddr; /* remote device address */
} hci_remote_oob_data_req_ep;

#define HCI_EVENT_SIMPLE_PAIRING_COMPL 0x36
typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote device address */
} hci_simple_pairing_compl_ep;

#define HCI_EVENT_LINK_SUPERVISION_TO_CHANGED 0x38
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint16_t timeout;    /* link supervision timeout */
} hci_link_supervision_to_changed_ep;

#define HCI_EVENT_ENHANCED_FLUSH_COMPL 0x39
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_enhanced_flush_compl_ep;

#define HCI_EVENT_USER_PASSKEY_NOTIFICATION 0x3b
typedef struct
{
  bdaddr_t bdaddr; /* remote device address */
  uint32_t value;  /* 000000 - 999999 */
} hci_user_passkey_notification_ep;

#define HCI_EVENT_KEYPRESS_NOTIFICATION 0x3c
typedef struct
{
  bdaddr_t bdaddr; /* remote device address */
  uint8_t notification_type;
} hci_keypress_notification_ep;

#define HCI_EVENT_REMOTE_FEATURES_NOTIFICATION 0x3d
typedef struct
{
  bdaddr_t bdaddr;                     /* remote device address */
  uint8_t features[HCI_FEATURES_SIZE]; /* LMP features bitmsk*/
} hci_remote_features_notification_ep;

#define HCI_EVENT_BT_LOGO 0xfe

#define HCI_EVENT_VENDOR 0xff

/**************************************************************************
 **************************************************************************
 **                 HCI Socket Definitions
 **************************************************************************
 **************************************************************************/

/* HCI socket options */
#define SO_HCI_EVT_FILTER 1 /* get/set event filter */
#define SO_HCI_PKT_FILTER 2 /* get/set packet filter */
#define SO_HCI_DIRECTION 3  /* packet direction indicator */

/* Control Messages */
#define SCM_HCI_DIRECTION SO_HCI_DIRECTION

/*
 * HCI socket filter and get/set routines
 *
 * for ease of use, we filter 256 possible events/packets
 */
struct hci_filter
{
  uint32_t mask[8]; /* 256 bits */
};

static __inline void hci_filter_set(uint8_t bit, hci_filter* filter)
{
  uint8_t off = bit - 1;

  off >>= 5;
  filter->mask[off] |= (1 << ((bit - 1) & 0x1f));
}

static __inline void hci_filter_clr(uint8_t bit, hci_filter* filter)
{
  uint8_t off = bit - 1;

  off >>= 5;
  filter->mask[off] &= ~(1 << ((bit - 1) & 0x1f));
}

static __inline int hci_filter_test(uint8_t bit, const struct hci_filter* filter)
{
  uint8_t off = bit - 1;

  off >>= 5;
  return (filter->mask[off] & (1 << ((bit - 1) & 0x1f)));
}

/*
 * HCI socket ioctl's
 *
 * Apart from GBTINFOA, these are all indexed on the unit name
 */

#define SIOCGBTINFO _IOWR('b', 5, struct btreq)  /* get unit info */
#define SIOCGBTINFOA _IOWR('b', 6, struct btreq) /* get info by address */
#define SIOCNBTINFO _IOWR('b', 7, struct btreq)  /* next unit info */

#define SIOCSBTFLAGS _IOWR('b', 8, struct btreq)  /* set unit flags */
#define SIOCSBTPOLICY _IOWR('b', 9, struct btreq) /* set unit link policy */
#define SIOCSBTPTYPE _IOWR('b', 10, struct btreq) /* set unit packet type */

#define SIOCGBTSTATS _IOWR('b', 11, struct btreq) /* get unit statistics */
#define SIOCZBTSTATS _IOWR('b', 12, struct btreq) /* zero unit statistics */

#define SIOCBTDUMP _IOW('b', 13, struct btreq)     /* print debug info */
#define SIOCSBTSCOMTU _IOWR('b', 17, struct btreq) /* set sco_mtu value */

struct bt_stats
{
  uint32_t err_tx;
  uint32_t err_rx;
  uint32_t cmd_tx;
  uint32_t evt_rx;
  uint32_t acl_tx;
  uint32_t acl_rx;
  uint32_t sco_tx;
  uint32_t sco_rx;
  uint32_t byte_tx;
  uint32_t byte_rx;
};

struct btreq
{
  char btr_name[HCI_DEVNAME_SIZE]; /* device name */

  union
  {
    struct
    {
      bdaddr_t btri_bdaddr;      /* device bdaddr */
      uint16_t btri_flags;       /* flags */
      uint16_t btri_num_cmd;     /* # of free cmd buffers */
      uint16_t btri_num_acl;     /* # of free ACL buffers */
      uint16_t btri_num_sco;     /* # of free SCO buffers */
      uint16_t btri_acl_mtu;     /* ACL mtu */
      uint16_t btri_sco_mtu;     /* SCO mtu */
      uint16_t btri_link_policy; /* Link Policy */
      uint16_t btri_packet_type; /* Packet Type */
    } btri;
    bt_stats btrs; /* unit stats */
  } btru;
};

#define btr_flags btru.btri.btri_flags
#define btr_bdaddr btru.btri.btri_bdaddr
#define btr_num_cmd btru.btri.btri_num_cmd
#define btr_num_acl btru.btri.btri_num_acl
#define btr_num_sco btru.btri.btri_num_sco
#define btr_acl_mtu btru.btri.btri_acl_mtu
#define btr_sco_mtu btru.btri.btri_sco_mtu
#define btr_link_policy btru.btri.btri_link_policy
#define btr_packet_type btru.btri.btri_packet_type
#define btr_stats btru.btrs

/* hci_unit & btr_flags */
#define BTF_UP (1 << 0)       /* unit is up */
#define BTF_RUNNING (1 << 1)  /* unit is running */
#define BTF_XMIT_CMD (1 << 2) /* unit is transmitting CMD packets */
#define BTF_XMIT_ACL (1 << 3) /* unit is transmitting ACL packets */
#define BTF_XMIT_SCO (1 << 4) /* unit is transmitting SCO packets */
#define BTF_XMIT (BTF_XMIT_CMD | BTF_XMIT_ACL | BTF_XMIT_SCO)
#define BTF_INIT_BDADDR (1 << 5)      /* waiting for bdaddr */
#define BTF_INIT_BUFFER_SIZE (1 << 6) /* waiting for buffer size */
#define BTF_INIT_FEATURES (1 << 7)    /* waiting for features */
#define BTF_POWER_UP_NOOP (1 << 8)    /* should wait for No-op on power up */
#define BTF_INIT_COMMANDS (1 << 9)    /* waiting for supported commands */
#define BTF_MASTER (1 << 10)          /* request Master role */

#define BTF_INIT (BTF_INIT_BDADDR | BTF_INIT_BUFFER_SIZE | BTF_INIT_FEATURES | BTF_INIT_COMMANDS)

//////////////////////////////////////////////////////////////////////////
// Dolphin-custom structs (to kill)
//////////////////////////////////////////////////////////////////////////
#include "Common/CommonTypes.h"
struct SCommandMessage
{
  u16 Opcode;
  u8 len;
};

struct SHCIEventCommand
{
  u8 EventType;
  u8 PayloadLength;
  u8 PacketIndicator;
  u16 Opcode;
};

struct SHCIEventStatus
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u8 PacketIndicator;
  u16 Opcode;
};

struct SHCIEventInquiryResult
{
  u8 EventType;
  u8 PayloadLength;
  u8 num_responses;
};

struct SHCIEventInquiryComplete
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u8 num_responses;
};

struct SHCIEventReadClockOffsetComplete
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u16 ConnectionHandle;
  u16 ClockOffset;
};

struct SHCIEventConPacketTypeChange
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u16 ConnectionHandle;
  u16 PacketType;
};

struct SHCIEventReadRemoteVerInfo
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u16 ConnectionHandle;
  u8 lmp_version;
  u16 manufacturer;
  u16 lmp_subversion;
};

struct SHCIEventReadRemoteFeatures
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u16 ConnectionHandle;
  u8 features[HCI_FEATURES_SIZE];
};

struct SHCIEventRemoteNameReq
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  bdaddr_t bdaddr;
  u8 RemoteName[HCI_UNIT_NAME_SIZE];
};

struct SHCIEventRequestConnection
{
  u8 EventType;
  u8 PayloadLength;
  bdaddr_t bdaddr;
  uint8_t uclass[HCI_CLASS_SIZE]; /* unit class */
  u8 LinkType;
};

struct SHCIEventConnectionComplete
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u16 Connection_Handle;
  bdaddr_t bdaddr;
  u8 LinkType;
  u8 EncryptionEnabled;
};

struct SHCIEventRoleChange
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  bdaddr_t bdaddr;
  u8 NewRole;
};

struct SHCIEventAuthenticationCompleted
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u16 Connection_Handle;
};

struct SHCIEventModeChange
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u16 Connection_Handle;
  u8 CurrentMode;
  u16 Value;
};

struct SHCIEventDisconnectCompleted
{
  u8 EventType;
  u8 PayloadLength;
  u8 EventStatus;
  u16 Connection_Handle;
  u8 Reason;
};

struct SHCIEventRequestLinkKey
{
  u8 EventType;
  u8 PayloadLength;
  bdaddr_t bdaddr;
};

struct SHCIEventLinkKeyNotification
{
  u8 EventType;
  u8 PayloadLength;
  u8 numKeys;
  bdaddr_t bdaddr;
  u8 LinkKey[HCI_KEY_SIZE];
};
//////////////////////////////////////////////////////////////////////////

#pragma pack(pop)

