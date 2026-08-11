#pragma once

#pragma pack(push, 1)

/**************************************************************************
 **************************************************************************
 ** OGF 0x01	Link control commands and return parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_LINK_CONTROL 0x01

#define HCI_OCF_INQUIRY 0x0001
#define HCI_CMD_INQUIRY 0x0401
typedef struct
{
  uint8_t lap[HCI_LAP_SIZE]; /* LAP */
  uint8_t inquiry_length;    /* (N x 1.28) sec */
  uint8_t num_responses;     /* Max. # of responses */
} hci_inquiry_cp;
/* No return parameter(s) */

#define HCI_OCF_INQUIRY_CANCEL 0x0002
#define HCI_CMD_INQUIRY_CANCEL 0x0402
/* No command parameter(s) */
typedef hci_status_rp hci_inquiry_cancel_rp;

#define HCI_OCF_PERIODIC_INQUIRY 0x0003
#define HCI_CMD_PERIODIC_INQUIRY 0x0403
typedef struct
{
  uint16_t max_period_length; /* Max. and min. amount of time */
  uint16_t min_period_length; /* between consecutive inquiries */
  uint8_t lap[HCI_LAP_SIZE];  /* LAP */
  uint8_t inquiry_length;     /* (inquiry_length * 1.28) sec */
  uint8_t num_responses;      /* Max. # of responses */
} hci_periodic_inquiry_cp;

typedef hci_status_rp hci_periodic_inquiry_rp;

#define HCI_OCF_EXIT_PERIODIC_INQUIRY 0x0004
#define HCI_CMD_EXIT_PERIODIC_INQUIRY 0x0404
/* No command parameter(s) */
typedef hci_status_rp hci_exit_periodic_inquiry_rp;

#define HCI_OCF_CREATE_CON 0x0005
#define HCI_CMD_CREATE_CON 0x0405
typedef struct
{
  bdaddr_t bdaddr;            /* destination address */
  uint16_t pkt_type;          /* packet type */
  uint8_t page_scan_rep_mode; /* page scan repetition mode */
  uint8_t page_scan_mode;     /* reserved - set to 0x00 */
  uint16_t clock_offset;      /* clock offset */
  uint8_t accept_role_switch; /* accept role switch? 0x00 == No */
} hci_create_con_cp;
/* No return parameter(s) */

#define HCI_OCF_DISCONNECT 0x0006
#define HCI_CMD_DISCONNECT 0x0406
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint8_t reason;      /* reason to disconnect */
} hci_discon_cp;
/* No return parameter(s) */

/* Add SCO Connection is deprecated */
#define HCI_OCF_ADD_SCO_CON 0x0007
#define HCI_CMD_ADD_SCO_CON 0x0407
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint16_t pkt_type;   /* packet type */
} hci_add_sco_con_cp;
/* No return parameter(s) */

#define HCI_OCF_CREATE_CON_CANCEL 0x0008
#define HCI_CMD_CREATE_CON_CANCEL 0x0408
typedef struct
{
  bdaddr_t bdaddr; /* destination address */
} hci_create_con_cancel_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* destination address */
} hci_create_con_cancel_rp;

#define HCI_OCF_ACCEPT_CON 0x0009
#define HCI_CMD_ACCEPT_CON 0x0409
typedef struct
{
  bdaddr_t bdaddr; /* address of unit to be connected */
  uint8_t role;    /* connection role */
} hci_accept_con_cp;
/* No return parameter(s) */

#define HCI_OCF_REJECT_CON 0x000a
#define HCI_CMD_REJECT_CON 0x040A
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
  uint8_t reason;  /* reason to reject */
} hci_reject_con_cp;
/* No return parameter(s) */

#define HCI_OCF_LINK_KEY_REP 0x000b
#define HCI_CMD_LINK_KEY_REP 0x040B
typedef struct
{
  bdaddr_t bdaddr;           /* remote address */
  uint8_t key[HCI_KEY_SIZE]; /* key */
} hci_link_key_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* unit address */
} hci_link_key_rep_rp;

#define HCI_OCF_LINK_KEY_NEG_REP 0x000c
#define HCI_CMD_LINK_KEY_NEG_REP 0x040C
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
} hci_link_key_neg_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* unit address */
} hci_link_key_neg_rep_rp;

#define HCI_OCF_PIN_CODE_REP 0x000d
#define HCI_CMD_PIN_CODE_REP 0x040D
typedef struct
{
  bdaddr_t bdaddr;           /* remote address */
  uint8_t pin_size;          /* pin code length (in bytes) */
  uint8_t pin[HCI_PIN_SIZE]; /* pin code */
} hci_pin_code_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* unit address */
} hci_pin_code_rep_rp;

#define HCI_OCF_PIN_CODE_NEG_REP 0x000e
#define HCI_CMD_PIN_CODE_NEG_REP 0x040E
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
} hci_pin_code_neg_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* unit address */
} hci_pin_code_neg_rep_rp;

#define HCI_OCF_CHANGE_CON_PACKET_TYPE 0x000f
#define HCI_CMD_CHANGE_CON_PACKET_TYPE 0x040F
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint16_t pkt_type;   /* packet type */
} hci_change_con_pkt_type_cp;
/* No return parameter(s) */

#define HCI_OCF_AUTH_REQ 0x0011
#define HCI_CMD_AUTH_REQ 0x0411
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_auth_req_cp;
/* No return parameter(s) */

#define HCI_OCF_SET_CON_ENCRYPTION 0x0013
#define HCI_CMD_SET_CON_ENCRYPTION 0x0413
typedef struct
{
  uint16_t con_handle;       /* connection handle */
  uint8_t encryption_enable; /* 0x00 - disable, 0x01 - enable */
} hci_set_con_encryption_cp;
/* No return parameter(s) */

#define HCI_OCF_CHANGE_CON_LINK_KEY 0x0015
#define HCI_CMD_CHANGE_CON_LINK_KEY 0x0415
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_change_con_link_key_cp;
/* No return parameter(s) */

#define HCI_OCF_MASTER_LINK_KEY 0x0017
#define HCI_CMD_MASTER_LINK_KEY 0x0417
typedef struct
{
  uint8_t key_flag; /* key flag */
} hci_master_link_key_cp;
/* No return parameter(s) */

#define HCI_OCF_REMOTE_NAME_REQ 0x0019
#define HCI_CMD_REMOTE_NAME_REQ 0x0419
typedef struct
{
  bdaddr_t bdaddr;            /* remote address */
  uint8_t page_scan_rep_mode; /* page scan repetition mode */
  uint8_t page_scan_mode;     /* page scan mode */
  uint16_t clock_offset;      /* clock offset */
} hci_remote_name_req_cp;
/* No return parameter(s) */

#define HCI_OCF_REMOTE_NAME_REQ_CANCEL 0x001a
#define HCI_CMD_REMOTE_NAME_REQ_CANCEL 0x041A
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
} hci_remote_name_req_cancel_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_remote_name_req_cancel_rp;

#define HCI_OCF_READ_REMOTE_FEATURES 0x001b
#define HCI_CMD_READ_REMOTE_FEATURES 0x041B
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_remote_features_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_REMOTE_EXTENDED_FEATURES 0x001c
#define HCI_CMD_READ_REMOTE_EXTENDED_FEATURES 0x041C
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint8_t page;        /* page number */
} hci_read_remote_extended_features_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_REMOTE_VER_INFO 0x001d
#define HCI_CMD_READ_REMOTE_VER_INFO 0x041D
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_remote_ver_info_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_CLOCK_OFFSET 0x001f
#define HCI_CMD_READ_CLOCK_OFFSET 0x041F
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_clock_offset_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_LMP_HANDLE 0x0020
#define HCI_CMD_READ_LMP_HANDLE 0x0420
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_lmp_handle_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint8_t lmp_handle;  /* LMP handle */
  uint32_t reserved;   /* reserved */
} hci_read_lmp_handle_rp;

#define HCI_OCF_SETUP_SCO_CON 0x0028
#define HCI_CMD_SETUP_SCO_CON 0x0428
typedef struct
{
  uint16_t con_handle;   /* connection handle */
  uint32_t tx_bandwidth; /* transmit bandwidth */
  uint32_t rx_bandwidth; /* receive bandwidth */
  uint16_t latency;      /* maximum latency */
  uint16_t voice;        /* voice setting */
  uint8_t rt_effort;     /* retransmission effort */
  uint16_t pkt_type;     /* packet types */
} hci_setup_sco_con_cp;
/* No return parameter(s) */

#define HCI_OCF_ACCEPT_SCO_CON_REQ 0x0029
#define HCI_CMD_ACCEPT_SCO_CON_REQ 0x0429
typedef struct
{
  bdaddr_t bdaddr;       /* remote address */
  uint32_t tx_bandwidth; /* transmit bandwidth */
  uint32_t rx_bandwidth; /* receive bandwidth */
  uint16_t latency;      /* maximum latency */
  uint16_t content;      /* voice setting */
  uint8_t rt_effort;     /* retransmission effort */
  uint16_t pkt_type;     /* packet types */
} hci_accept_sco_con_req_cp;
/* No return parameter(s) */

#define HCI_OCF_REJECT_SCO_CON_REQ 0x002a
#define HCI_CMD_REJECT_SCO_CON_REQ 0x042a
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
  uint8_t reason;  /* reject error code */
} hci_reject_sco_con_req_cp;
/* No return parameter(s) */

#define HCI_OCF_IO_CAPABILITY_REP 0x002b
#define HCI_CMD_IO_CAPABILITY_REP 0x042a
typedef struct
{
  bdaddr_t bdaddr;  /* remote address */
  uint8_t io_cap;   /* IO capability */
  uint8_t oob_data; /* OOB data present */
  uint8_t auth_req; /* auth requirements */
} hci_io_capability_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_io_capability_rep_rp;

#define HCI_OCF_USER_CONFIRM_REP 0x002c
#define HCI_CMD_USER_CONFIRM_REP 0x042c
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
} hci_user_confirm_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_user_confirm_rep_rp;

#define HCI_OCF_USER_CONFIRM_NEG_REP 0x002d
#define HCI_CMD_USER_CONFIRM_NEG_REP 0x042d
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
} hci_user_confirm_neg_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_user_confirm_neg_rep_rp;

#define HCI_OCF_USER_PASSKEY_REP 0x002e
#define HCI_CMD_USER_PASSKEY_REP 0x042e
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
  uint32_t value;  /* 000000 - 999999 */
} hci_user_passkey_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_user_passkey_rep_rp;

#define HCI_OCF_USER_PASSKEY_NEG_REP 0x002f
#define HCI_CMD_USER_PASSKEY_NEG_REP 0x042f
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
} hci_user_passkey_neg_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_user_passkey_neg_rep_rp;

#define HCI_OCF_OOB_DATA_REP 0x0030
#define HCI_CMD_OOB_DATA_REP 0x0430
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
  uint8_t c[16];   /* pairing hash */
  uint8_t r[16];   /* pairing randomizer */
} hci_user_oob_data_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_user_oob_data_rep_rp;

#define HCI_OCF_OOB_DATA_NEG_REP 0x0033
#define HCI_CMD_OOB_DATA_NEG_REP 0x0433
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
} hci_user_oob_data_neg_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_user_oob_data_neg_rep_rp;

#define HCI_OCF_IO_CAPABILITY_NEG_REP 0x0034
#define HCI_CMD_IO_CAPABILITY_NEG_REP 0x0434
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
  uint8_t reason;  /* error code */
} hci_io_capability_neg_rep_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_io_capability_neg_rep_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x02	Link policy commands and return parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_LINK_POLICY 0x02

#define HCI_OCF_HOLD_MODE 0x0001
#define HCI_CMD_HOLD_MODE 0x0801
typedef struct
{
  uint16_t con_handle;   /* connection handle */
  uint16_t max_interval; /* (max_interval * 0.625) msec */
  uint16_t min_interval; /* (max_interval * 0.625) msec */
} hci_hold_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_SNIFF_MODE 0x0003
#define HCI_CMD_SNIFF_MODE 0x0803
typedef struct
{
  uint16_t con_handle;   /* connection handle */
  uint16_t max_interval; /* (max_interval * 0.625) msec */
  uint16_t min_interval; /* (max_interval * 0.625) msec */
  uint16_t attempt;      /* (2 * attempt - 1) * 0.625 msec */
  uint16_t timeout;      /* (2 * attempt - 1) * 0.625 msec */
} hci_sniff_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_EXIT_SNIFF_MODE 0x0004
#define HCI_CMD_EXIT_SNIFF_MODE 0x0804
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_exit_sniff_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_PARK_MODE 0x0005
#define HCI_CMD_PARK_MODE 0x0805
typedef struct
{
  uint16_t con_handle;   /* connection handle */
  uint16_t max_interval; /* (max_interval * 0.625) msec */
  uint16_t min_interval; /* (max_interval * 0.625) msec */
} hci_park_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_EXIT_PARK_MODE 0x0006
#define HCI_CMD_EXIT_PARK_MODE 0x0806
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_exit_park_mode_cp;
/* No return parameter(s) */

#define HCI_OCF_QOS_SETUP 0x0007
#define HCI_CMD_QOS_SETUP 0x0807
typedef struct
{
  uint16_t con_handle;      /* connection handle */
  uint8_t flags;            /* reserved for future use */
  uint8_t service_type;     /* service type */
  uint32_t token_rate;      /* bytes per second */
  uint32_t peak_bandwidth;  /* bytes per second */
  uint32_t latency;         /* microseconds */
  uint32_t delay_variation; /* microseconds */
} hci_qos_setup_cp;
/* No return parameter(s) */

#define HCI_OCF_ROLE_DISCOVERY 0x0009
#define HCI_CMD_ROLE_DISCOVERY 0x0809
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_role_discovery_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint8_t role;        /* role for the connection handle */
} hci_role_discovery_rp;

#define HCI_OCF_SWITCH_ROLE 0x000b
#define HCI_CMD_SWITCH_ROLE 0x080B
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
  uint8_t role;    /* new local role */
} hci_switch_role_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_LINK_POLICY_SETTINGS 0x000c
#define HCI_CMD_READ_LINK_POLICY_SETTINGS 0x080C
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_link_policy_settings_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint16_t settings;   /* link policy settings */
} hci_read_link_policy_settings_rp;

#define HCI_OCF_WRITE_LINK_POLICY_SETTINGS 0x000d
#define HCI_CMD_WRITE_LINK_POLICY_SETTINGS 0x080D
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint16_t settings;   /* link policy settings */
} hci_write_link_policy_settings_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
} hci_write_link_policy_settings_rp;

#define HCI_OCF_READ_DEFAULT_LINK_POLICY_SETTINGS 0x000e
#define HCI_CMD_READ_DEFAULT_LINK_POLICY_SETTINGS 0x080E
/* No command parameter(s) */
typedef struct
{
  uint8_t status;    /* 0x00 - success */
  uint16_t settings; /* link policy settings */
} hci_read_default_link_policy_settings_rp;

#define HCI_OCF_WRITE_DEFAULT_LINK_POLICY_SETTINGS 0x000f
#define HCI_CMD_WRITE_DEFAULT_LINK_POLICY_SETTINGS 0x080F
typedef struct
{
  uint16_t settings; /* link policy settings */
} hci_write_default_link_policy_settings_cp;

typedef hci_status_rp hci_write_default_link_policy_settings_rp;

#define HCI_OCF_FLOW_SPECIFICATION 0x0010
#define HCI_CMD_FLOW_SPECIFICATION 0x0810
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint8_t flags;       /* reserved */
  uint8_t flow_direction;
  uint8_t service_type;
  uint32_t token_rate;
  uint32_t token_bucket;
  uint32_t peak_bandwidth;
  uint32_t latency;
} hci_flow_specification_cp;
/* No return parameter(s) */

#define HCI_OCF_SNIFF_SUBRATING 0x0011
#define HCI_CMD_SNIFF_SUBRATING 0x0810
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint16_t max_latency;
  uint16_t max_timeout; /* max remote timeout */
  uint16_t min_timeout; /* min local timeout */
} hci_sniff_subrating_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
} hci_sniff_subrating_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x03	Host Controller and Baseband commands and return parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_HC_BASEBAND 0x03

#define HCI_OCF_SET_EVENT_MASK 0x0001
#define HCI_CMD_SET_EVENT_MASK 0x0C01
typedef struct
{
  uint8_t event_mask[HCI_EVENT_MASK_SIZE]; /* event_mask */
} hci_set_event_mask_cp;

typedef hci_status_rp hci_set_event_mask_rp;

#define HCI_OCF_RESET 0x0003
#define HCI_CMD_RESET 0x0C03
/* No command parameter(s) */
typedef hci_status_rp hci_reset_rp;

#define HCI_OCF_SET_EVENT_FILTER 0x0005
#define HCI_CMD_SET_EVENT_FILTER 0x0C05
typedef struct
{
  uint8_t filter_type;           /* filter type */
  uint8_t filter_condition_type; /* filter condition type */
                                 /* variable size condition
                                   uint8_t		condition[]; -- conditions */
} hci_set_event_filter_cp;

typedef hci_status_rp hci_set_event_filter_rp;

#define HCI_OCF_FLUSH 0x0008
#define HCI_CMD_FLUSH 0x0C08
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_flush_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
} hci_flush_rp;

#define HCI_OCF_READ_PIN_TYPE 0x0009
#define HCI_CMD_READ_PIN_TYPE 0x0C09
/* No command parameter(s) */
typedef struct
{
  uint8_t status;   /* 0x00 - success */
  uint8_t pin_type; /* PIN type */
} hci_read_pin_type_rp;

#define HCI_OCF_WRITE_PIN_TYPE 0x000a
#define HCI_CMD_WRITE_PIN_TYPE 0x0C0A
typedef struct
{
  uint8_t pin_type; /* PIN type */
} hci_write_pin_type_cp;

typedef hci_status_rp hci_write_pin_type_rp;

#define HCI_OCF_CREATE_NEW_UNIT_KEY 0x000b
#define HCI_CMD_CREATE_NEW_UNIT_KEY 0x0C0B
/* No command parameter(s) */
typedef hci_status_rp hci_create_new_unit_key_rp;

#define HCI_OCF_READ_STORED_LINK_KEY 0x000d
#define HCI_CMD_READ_STORED_LINK_KEY 0x0C0D
typedef struct
{
  bdaddr_t bdaddr;  /* address */
  uint8_t read_all; /* read all keys? 0x01 - yes */
} hci_read_stored_link_key_cp;

typedef struct
{
  uint8_t status;         /* 0x00 - success */
  uint16_t max_num_keys;  /* Max. number of keys */
  uint16_t num_keys_read; /* Number of stored keys */
} hci_read_stored_link_key_rp;

#define HCI_OCF_WRITE_STORED_LINK_KEY 0x0011
#define HCI_CMD_WRITE_STORED_LINK_KEY 0x0C11
typedef struct
{
  uint8_t num_keys_write; /* # of keys to write */
                          /* these are repeated "num_keys_write" times
                            bdaddr_t	bdaddr;             --- remote address(es)
                            uint8_t		key[HCI_KEY_SIZE];  --- key(s) */
} hci_write_stored_link_key_cp;

typedef struct
{
  uint8_t status;           /* 0x00 - success */
  uint8_t num_keys_written; /* # of keys successfully written */
} hci_write_stored_link_key_rp;

#define HCI_OCF_DELETE_STORED_LINK_KEY 0x0012
#define HCI_CMD_DELETE_STORED_LINK_KEY 0x0C12
typedef struct
{
  bdaddr_t bdaddr;    /* address */
  uint8_t delete_all; /* delete all keys? 0x01 - yes */
} hci_delete_stored_link_key_cp;

typedef struct
{
  uint8_t status;            /* 0x00 - success */
  uint16_t num_keys_deleted; /* Number of keys deleted */
} hci_delete_stored_link_key_rp;

#define HCI_OCF_WRITE_LOCAL_NAME 0x0013
#define HCI_CMD_WRITE_LOCAL_NAME 0x0C13
typedef struct
{
  char name[HCI_UNIT_NAME_SIZE]; /* new unit name */
} hci_write_local_name_cp;

typedef hci_status_rp hci_write_local_name_rp;

#define HCI_OCF_READ_LOCAL_NAME 0x0014
#define HCI_CMD_READ_LOCAL_NAME 0x0C14
/* No command parameter(s) */
typedef struct
{
  uint8_t status;                /* 0x00 - success */
  char name[HCI_UNIT_NAME_SIZE]; /* unit name */
} hci_read_local_name_rp;

#define HCI_OCF_READ_CON_ACCEPT_TIMEOUT 0x0015
#define HCI_CMD_READ_CON_ACCEPT_TIMEOUT 0x0C15
/* No command parameter(s) */
typedef struct
{
  uint8_t status;   /* 0x00 - success */
  uint16_t timeout; /* (timeout * 0.625) msec */
} hci_read_con_accept_timeout_rp;

#define HCI_OCF_WRITE_CON_ACCEPT_TIMEOUT 0x0016
#define HCI_CMD_WRITE_CON_ACCEPT_TIMEOUT 0x0C16
typedef struct
{
  uint16_t timeout; /* (timeout * 0.625) msec */
} hci_write_con_accept_timeout_cp;

typedef hci_status_rp hci_write_con_accept_timeout_rp;

#define HCI_OCF_READ_PAGE_TIMEOUT 0x0017
#define HCI_CMD_READ_PAGE_TIMEOUT 0x0C17
/* No command parameter(s) */
typedef struct
{
  uint8_t status;   /* 0x00 - success */
  uint16_t timeout; /* (timeout * 0.625) msec */
} hci_read_page_timeout_rp;

#define HCI_OCF_WRITE_PAGE_TIMEOUT 0x0018
#define HCI_CMD_WRITE_PAGE_TIMEOUT 0x0C18
typedef struct
{
  uint16_t timeout; /* (timeout * 0.625) msec */
} hci_write_page_timeout_cp;

typedef hci_status_rp hci_write_page_timeout_rp;

#define HCI_OCF_READ_SCAN_ENABLE 0x0019
#define HCI_CMD_READ_SCAN_ENABLE 0x0C19
/* No command parameter(s) */
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint8_t scan_enable; /* Scan enable */
} hci_read_scan_enable_rp;

#define HCI_OCF_WRITE_SCAN_ENABLE 0x001a
#define HCI_CMD_WRITE_SCAN_ENABLE 0x0C1A
typedef struct
{
  uint8_t scan_enable; /* Scan enable */
} hci_write_scan_enable_cp;

typedef hci_status_rp hci_write_scan_enable_rp;

#define HCI_OCF_READ_PAGE_SCAN_ACTIVITY 0x001b
#define HCI_CMD_READ_PAGE_SCAN_ACTIVITY 0x0C1B
/* No command parameter(s) */
typedef struct
{
  uint8_t status;              /* 0x00 - success */
  uint16_t page_scan_interval; /* interval * 0.625 msec */
  uint16_t page_scan_window;   /* window * 0.625 msec */
} hci_read_page_scan_activity_rp;

#define HCI_OCF_WRITE_PAGE_SCAN_ACTIVITY 0x001c
#define HCI_CMD_WRITE_PAGE_SCAN_ACTIVITY 0x0C1C
typedef struct
{
  uint16_t page_scan_interval; /* interval * 0.625 msec */
  uint16_t page_scan_window;   /* window * 0.625 msec */
} hci_write_page_scan_activity_cp;

typedef hci_status_rp hci_write_page_scan_activity_rp;

#define HCI_OCF_READ_INQUIRY_SCAN_ACTIVITY 0x001d
#define HCI_CMD_READ_INQUIRY_SCAN_ACTIVITY 0x0C1D
/* No command parameter(s) */
typedef struct
{
  uint8_t status;                 /* 0x00 - success */
  uint16_t inquiry_scan_interval; /* interval * 0.625 msec */
  uint16_t inquiry_scan_window;   /* window * 0.625 msec */
} hci_read_inquiry_scan_activity_rp;

#define HCI_OCF_WRITE_INQUIRY_SCAN_ACTIVITY 0x001e
#define HCI_CMD_WRITE_INQUIRY_SCAN_ACTIVITY 0x0C1E
typedef struct
{
  uint16_t inquiry_scan_interval; /* interval * 0.625 msec */
  uint16_t inquiry_scan_window;   /* window * 0.625 msec */
} hci_write_inquiry_scan_activity_cp;

typedef hci_status_rp hci_write_inquiry_scan_activity_rp;

#define HCI_OCF_READ_AUTH_ENABLE 0x001f
#define HCI_CMD_READ_AUTH_ENABLE 0x0C1F
/* No command parameter(s) */
typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint8_t auth_enable; /* 0x01 - enabled */
} hci_read_auth_enable_rp;

#define HCI_OCF_WRITE_AUTH_ENABLE 0x0020
#define HCI_CMD_WRITE_AUTH_ENABLE 0x0C20
typedef struct
{
  uint8_t auth_enable; /* 0x01 - enabled */
} hci_write_auth_enable_cp;

typedef hci_status_rp hci_write_auth_enable_rp;

/* Read Encryption Mode is deprecated */
#define HCI_OCF_READ_ENCRYPTION_MODE 0x0021
#define HCI_CMD_READ_ENCRYPTION_MODE 0x0C21
/* No command parameter(s) */
typedef struct
{
  uint8_t status;          /* 0x00 - success */
  uint8_t encryption_mode; /* encryption mode */
} hci_read_encryption_mode_rp;

/* Write Encryption Mode is deprecated */
#define HCI_OCF_WRITE_ENCRYPTION_MODE 0x0022
#define HCI_CMD_WRITE_ENCRYPTION_MODE 0x0C22
typedef struct
{
  uint8_t encryption_mode; /* encryption mode */
} hci_write_encryption_mode_cp;

typedef hci_status_rp hci_write_encryption_mode_rp;

#define HCI_OCF_READ_UNIT_CLASS 0x0023
#define HCI_CMD_READ_UNIT_CLASS 0x0C23
/* No command parameter(s) */
typedef struct
{
  uint8_t status;                 /* 0x00 - success */
  uint8_t uclass[HCI_CLASS_SIZE]; /* unit class */
} hci_read_unit_class_rp;

#define HCI_OCF_WRITE_UNIT_CLASS 0x0024
#define HCI_CMD_WRITE_UNIT_CLASS 0x0C24
typedef struct
{
  uint8_t uclass[HCI_CLASS_SIZE]; /* unit class */
} hci_write_unit_class_cp;

typedef hci_status_rp hci_write_unit_class_rp;

#define HCI_OCF_READ_VOICE_SETTING 0x0025
#define HCI_CMD_READ_VOICE_SETTING 0x0C25
/* No command parameter(s) */
typedef struct
{
  uint8_t status;    /* 0x00 - success */
  uint16_t settings; /* voice settings */
} hci_read_voice_setting_rp;

#define HCI_OCF_WRITE_VOICE_SETTING 0x0026
#define HCI_CMD_WRITE_VOICE_SETTING 0x0C26
typedef struct
{
  uint16_t settings; /* voice settings */
} hci_write_voice_setting_cp;

typedef hci_status_rp hci_write_voice_setting_rp;

#define HCI_OCF_READ_AUTO_FLUSH_TIMEOUT 0x0027
#define HCI_CMD_READ_AUTO_FLUSH_TIMEOUT 0x0C27
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_auto_flush_timeout_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint16_t timeout;    /* 0x00 - no flush, timeout * 0.625 msec */
} hci_read_auto_flush_timeout_rp;

#define HCI_OCF_WRITE_AUTO_FLUSH_TIMEOUT 0x0028
#define HCI_CMD_WRITE_AUTO_FLUSH_TIMEOUT 0x0C28
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint16_t timeout;    /* 0x00 - no flush, timeout * 0.625 msec */
} hci_write_auto_flush_timeout_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
} hci_write_auto_flush_timeout_rp;

#define HCI_OCF_READ_NUM_BROADCAST_RETRANS 0x0029
#define HCI_CMD_READ_NUM_BROADCAST_RETRANS 0x0C29
/* No command parameter(s) */
typedef struct
{
  uint8_t status;  /* 0x00 - success */
  uint8_t counter; /* number of broadcast retransmissions */
} hci_read_num_broadcast_retrans_rp;

#define HCI_OCF_WRITE_NUM_BROADCAST_RETRANS 0x002a
#define HCI_CMD_WRITE_NUM_BROADCAST_RETRANS 0x0C2A
typedef struct
{
  uint8_t counter; /* number of broadcast retransmissions */
} hci_write_num_broadcast_retrans_cp;

typedef hci_status_rp hci_write_num_broadcast_retrans_rp;

#define HCI_OCF_READ_HOLD_MODE_ACTIVITY 0x002b
#define HCI_CMD_READ_HOLD_MODE_ACTIVITY 0x0C2B
/* No command parameter(s) */
typedef struct
{
  uint8_t status;             /* 0x00 - success */
  uint8_t hold_mode_activity; /* Hold mode activities */
} hci_read_hold_mode_activity_rp;

#define HCI_OCF_WRITE_HOLD_MODE_ACTIVITY 0x002c
#define HCI_CMD_WRITE_HOLD_MODE_ACTIVITY 0x0C2C
typedef struct
{
  uint8_t hold_mode_activity; /* Hold mode activities */
} hci_write_hold_mode_activity_cp;

typedef hci_status_rp hci_write_hold_mode_activity_rp;

#define HCI_OCF_READ_XMIT_LEVEL 0x002d
#define HCI_CMD_READ_XMIT_LEVEL 0x0C2D
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint8_t type;        /* Xmit level type */
} hci_read_xmit_level_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  char level;          /* -30 <= level <= 30 dBm */
} hci_read_xmit_level_rp;

#define HCI_OCF_READ_SCO_FLOW_CONTROL 0x002e
#define HCI_CMD_READ_SCO_FLOW_CONTROL 0x0C2E
/* No command parameter(s) */
typedef struct
{
  uint8_t status;       /* 0x00 - success */
  uint8_t flow_control; /* 0x00 - disabled */
} hci_read_sco_flow_control_rp;

#define HCI_OCF_WRITE_SCO_FLOW_CONTROL 0x002f
#define HCI_CMD_WRITE_SCO_FLOW_CONTROL 0x0C2F
typedef struct
{
  uint8_t flow_control; /* 0x00 - disabled */
} hci_write_sco_flow_control_cp;

typedef hci_status_rp hci_write_sco_flow_control_rp;

#define HCI_OCF_HC2H_FLOW_CONTROL 0x0031
#define HCI_CMD_HC2H_FLOW_CONTROL 0x0C31
typedef struct
{
  uint8_t hc2h_flow; /* Host Controller to Host flow control */
} hci_hc2h_flow_control_cp;

typedef hci_status_rp hci_h2hc_flow_control_rp;

#define HCI_OCF_HOST_BUFFER_SIZE 0x0033
#define HCI_CMD_HOST_BUFFER_SIZE 0x0C33
typedef struct
{
  uint16_t max_acl_size; /* Max. size of ACL packet (bytes) */
  uint8_t max_sco_size;  /* Max. size of SCO packet (bytes) */
  uint16_t num_acl_pkts; /* Max. number of ACL packets */
  uint16_t num_sco_pkts; /* Max. number of SCO packets */
} hci_host_buffer_size_cp;

typedef hci_status_rp hci_host_buffer_size_rp;

#define HCI_OCF_HOST_NUM_COMPL_PKTS 0x0035
#define HCI_CMD_HOST_NUM_COMPL_PKTS 0x0C35
typedef struct
{
  uint8_t nu_con_handles; /* # of connection handles */
                          /* these are repeated "num_con_handles" times
                            uint16_t	con_handle;    --- connection handle(s)
                            uint16_t	compl_pkts;    --- # of completed packets */
} hci_host_num_compl_pkts_cp;
/* No return parameter(s) */

#define HCI_OCF_READ_LINK_SUPERVISION_TIMEOUT 0x0036
#define HCI_CMD_READ_LINK_SUPERVISION_TIMEOUT 0x0C36
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_link_supervision_timeout_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint16_t timeout;    /* Link supervision timeout * 0.625 msec */
} hci_read_link_supervision_timeout_rp;

#define HCI_OCF_WRITE_LINK_SUPERVISION_TIMEOUT 0x0037
#define HCI_CMD_WRITE_LINK_SUPERVISION_TIMEOUT 0x0C37
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint16_t timeout;    /* Link supervision timeout * 0.625 msec */
} hci_write_link_supervision_timeout_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
} hci_write_link_supervision_timeout_rp;

#define HCI_OCF_READ_NUM_SUPPORTED_IAC 0x0038
#define HCI_CMD_READ_NUM_SUPPORTED_IAC 0x0C38
/* No command parameter(s) */
typedef struct
{
  uint8_t status;  /* 0x00 - success */
  uint8_t num_iac; /* # of supported IAC during scan */
} hci_read_num_supported_iac_rp;

#define HCI_OCF_READ_IAC_LAP 0x0039
#define HCI_CMD_READ_IAC_LAP 0x0C39
/* No command parameter(s) */
typedef struct
{
  uint8_t status;  /* 0x00 - success */
  uint8_t num_iac; /* # of IAC */
                   /* these are repeated "num_iac" times
                     uint8_t		laps[HCI_LAP_SIZE]; --- LAPs */
} hci_read_iac_lap_rp;

#define HCI_OCF_WRITE_IAC_LAP 0x003a
#define HCI_CMD_WRITE_IAC_LAP 0x0C3A
typedef struct
{
  uint8_t num_iac; /* # of IAC */
                   /* these are repeated "num_iac" times
                     uint8_t		laps[HCI_LAP_SIZE]; --- LAPs */
} hci_write_iac_lap_cp;

typedef hci_status_rp hci_write_iac_lap_rp;

/* Read Page Scan Period Mode is deprecated */
#define HCI_OCF_READ_PAGE_SCAN_PERIOD 0x003b
#define HCI_CMD_READ_PAGE_SCAN_PERIOD 0x0C3B
/* No command parameter(s) */
typedef struct
{
  uint8_t status;                /* 0x00 - success */
  uint8_t page_scan_period_mode; /* Page scan period mode */
} hci_read_page_scan_period_rp;

/* Write Page Scan Period Mode is deprecated */
#define HCI_OCF_WRITE_PAGE_SCAN_PERIOD 0x003c
#define HCI_CMD_WRITE_PAGE_SCAN_PERIOD 0x0C3C
typedef struct
{
  uint8_t page_scan_period_mode; /* Page scan period mode */
} hci_write_page_scan_period_cp;

typedef hci_status_rp hci_write_page_scan_period_rp;

/* Read Page Scan Mode is deprecated */
#define HCI_OCF_READ_PAGE_SCAN 0x003d
#define HCI_CMD_READ_PAGE_SCAN 0x0C3D
/* No command parameter(s) */
typedef struct
{
  uint8_t status;         /* 0x00 - success */
  uint8_t page_scan_mode; /* Page scan mode */
} hci_read_page_scan_rp;

/* Write Page Scan Mode is deprecated */
#define HCI_OCF_WRITE_PAGE_SCAN 0x003e
#define HCI_CMD_WRITE_PAGE_SCAN 0x0C3E
typedef struct
{
  uint8_t page_scan_mode; /* Page scan mode */
} hci_write_page_scan_cp;

typedef hci_status_rp hci_write_page_scan_rp;

#define HCI_OCF_SET_AFH_CLASSIFICATION 0x003f
#define HCI_CMD_SET_AFH_CLASSIFICATION 0x0C3F
typedef struct
{
  uint8_t classification[10];
} hci_set_afh_classification_cp;

typedef hci_status_rp hci_set_afh_classification_rp;

#define HCI_OCF_READ_INQUIRY_SCAN_TYPE 0x0042
#define HCI_CMD_READ_INQUIRY_SCAN_TYPE 0x0C42
/* No command parameter(s) */

typedef struct
{
  uint8_t status; /* 0x00 - success */
  uint8_t type;   /* inquiry scan type */
} hci_read_inquiry_scan_type_rp;

#define HCI_OCF_WRITE_INQUIRY_SCAN_TYPE 0x0043
#define HCI_CMD_WRITE_INQUIRY_SCAN_TYPE 0x0C43
typedef struct
{
  uint8_t type; /* inquiry scan type */
} hci_write_inquiry_scan_type_cp;

typedef hci_status_rp hci_write_inquiry_scan_type_rp;

#define HCI_OCF_READ_INQUIRY_MODE 0x0044
#define HCI_CMD_READ_INQUIRY_MODE 0x0C44
/* No command parameter(s) */

typedef struct
{
  uint8_t status; /* 0x00 - success */
  uint8_t mode;   /* inquiry mode */
} hci_read_inquiry_mode_rp;

#define HCI_OCF_WRITE_INQUIRY_MODE 0x0045
#define HCI_CMD_WRITE_INQUIRY_MODE 0x0C45
typedef struct
{
  uint8_t mode; /* inquiry mode */
} hci_write_inquiry_mode_cp;

typedef hci_status_rp hci_write_inquiry_mode_rp;

#define HCI_OCF_READ_PAGE_SCAN_TYPE 0x0046
#define HCI_CMD_READ_PAGE_SCAN_TYPE 0x0C46
/* No command parameter(s) */

typedef struct
{
  uint8_t status; /* 0x00 - success */
  uint8_t type;   /* page scan type */
} hci_read_page_scan_type_rp;

#define HCI_OCF_WRITE_PAGE_SCAN_TYPE 0x0047
#define HCI_CMD_WRITE_PAGE_SCAN_TYPE 0x0C47
typedef struct
{
  uint8_t type; /* page scan type */
} hci_write_page_scan_type_cp;

typedef hci_status_rp hci_write_page_scan_type_rp;

#define HCI_OCF_READ_AFH_ASSESSMENT 0x0048
#define HCI_CMD_READ_AFH_ASSESSMENT 0x0C48
/* No command parameter(s) */

typedef struct
{
  uint8_t status; /* 0x00 - success */
  uint8_t mode;   /* assessment mode */
} hci_read_afh_assessment_rp;

#define HCI_OCF_WRITE_AFH_ASSESSMENT 0x0049
#define HCI_CMD_WRITE_AFH_ASSESSMENT 0x0C49
typedef struct
{
  uint8_t mode; /* assessment mode */
} hci_write_afh_assessment_cp;

typedef hci_status_rp hci_write_afh_assessment_rp;

#define HCI_OCF_READ_EXTENDED_INQUIRY_RSP 0x0051
#define HCI_CMD_READ_EXTENDED_INQUIRY_RSP 0x0C51
/* No command parameter(s) */

typedef struct
{
  uint8_t status; /* 0x00 - success */
  uint8_t fec_required;
  uint8_t response[240];
} hci_read_extended_inquiry_rsp_rp;

#define HCI_OCF_WRITE_EXTENDED_INQUIRY_RSP 0x0052
#define HCI_CMD_WRITE_EXTENDED_INQUIRY_RSP 0x0C52
typedef struct
{
  uint8_t fec_required;
  uint8_t response[240];
} hci_write_extended_inquiry_rsp_cp;

typedef hci_status_rp hci_write_extended_inquiry_rsp_rp;

#define HCI_OCF_REFRESH_ENCRYPTION_KEY 0x0053
#define HCI_CMD_REFRESH_ENCRYPTION_KEY 0x0C53
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_refresh_encryption_key_cp;

typedef hci_status_rp hci_refresh_encryption_key_rp;

#define HCI_OCF_READ_SIMPLE_PAIRING_MODE 0x0055
#define HCI_CMD_READ_SIMPLE_PAIRING_MODE 0x0C55
/* No command parameter(s) */

typedef struct
{
  uint8_t status; /* 0x00 - success */
  uint8_t mode;   /* simple pairing mode */
} hci_read_simple_pairing_mode_rp;

#define HCI_OCF_WRITE_SIMPLE_PAIRING_MODE 0x0056
#define HCI_CMD_WRITE_SIMPLE_PAIRING_MODE 0x0C56
typedef struct
{
  uint8_t mode; /* simple pairing mode */
} hci_write_simple_pairing_mode_cp;

typedef hci_status_rp hci_write_simple_pairing_mode_rp;

#define HCI_OCF_READ_LOCAL_OOB_DATA 0x0057
#define HCI_CMD_READ_LOCAL_OOB_DATA 0x0C57
/* No command parameter(s) */

typedef struct
{
  uint8_t status; /* 0x00 - success */
  uint8_t c[16];  /* pairing hash */
  uint8_t r[16];  /* pairing randomizer */
} hci_read_local_oob_data_rp;

#define HCI_OCF_READ_INQUIRY_RSP_XMIT_POWER 0x0058
#define HCI_CMD_READ_INQUIRY_RSP_XMIT_POWER 0x0C58
/* No command parameter(s) */

typedef struct
{
  uint8_t status; /* 0x00 - success */
  int8_t power;   /* TX power */
} hci_read_inquiry_rsp_xmit_power_rp;

#define HCI_OCF_WRITE_INQUIRY_RSP_XMIT_POWER 0x0059
#define HCI_CMD_WRITE_INQUIRY_RSP_XMIT_POWER 0x0C59
typedef struct
{
  int8_t power; /* TX power */
} hci_write_inquiry_rsp_xmit_power_cp;

typedef hci_status_rp hci_write_inquiry_rsp_xmit_power_rp;

#define HCI_OCF_READ_DEFAULT_ERRDATA_REPORTING 0x005A
#define HCI_CMD_READ_DEFAULT_ERRDATA_REPORTING 0x0C5A
/* No command parameter(s) */

typedef struct
{
  uint8_t status;    /* 0x00 - success */
  uint8_t reporting; /* erroneous data reporting */
} hci_read_default_errdata_reporting_rp;

#define HCI_OCF_WRITE_DEFAULT_ERRDATA_REPORTING 0x005B
#define HCI_CMD_WRITE_DEFAULT_ERRDATA_REPORTING 0x0C5B
typedef struct
{
  uint8_t reporting; /* erroneous data reporting */
} hci_write_default_errdata_reporting_cp;

typedef hci_status_rp hci_write_default_errdata_reporting_rp;

#define HCI_OCF_ENHANCED_FLUSH 0x005F
#define HCI_CMD_ENHANCED_FLUSH 0x0C5F
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint8_t packet_type;
} hci_enhanced_flush_cp;

/* No response parameter(s) */

#define HCI_OCF_SEND_KEYPRESS_NOTIFICATION 0x0060
#define HCI_CMD_SEND_KEYPRESS_NOTIFICATION 0x0C60
typedef struct
{
  bdaddr_t bdaddr; /* remote address */
  uint8_t type;    /* notification type */
} hci_send_keypress_notification_cp;

typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* remote address */
} hci_send_keypress_notification_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x04	Informational commands and return parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_INFO 0x04

#define HCI_OCF_READ_LOCAL_VER 0x0001
#define HCI_CMD_READ_LOCAL_VER 0x1001
/* No command parameter(s) */
typedef struct
{
  uint8_t status;          /* 0x00 - success */
  uint8_t hci_version;     /* HCI version */
  uint16_t hci_revision;   /* HCI revision */
  uint8_t lmp_version;     /* LMP version */
  uint16_t manufacturer;   /* Hardware manufacturer name */
  uint16_t lmp_subversion; /* LMP sub-version */
} hci_read_local_ver_rp;

#define HCI_OCF_READ_LOCAL_COMMANDS 0x0002
#define HCI_CMD_READ_LOCAL_COMMANDS 0x1002
/* No command parameter(s) */
typedef struct
{
  uint8_t status;                      /* 0x00 - success */
  uint8_t commands[HCI_COMMANDS_SIZE]; /* opcode bitmask */
} hci_read_local_commands_rp;

#define HCI_OCF_READ_LOCAL_FEATURES 0x0003
#define HCI_CMD_READ_LOCAL_FEATURES 0x1003
/* No command parameter(s) */
typedef struct
{
  uint8_t status;                      /* 0x00 - success */
  uint8_t features[HCI_FEATURES_SIZE]; /* LMP features bitmsk*/
} hci_read_local_features_rp;

#define HCI_OCF_READ_LOCAL_EXTENDED_FEATURES 0x0004
#define HCI_CMD_READ_LOCAL_EXTENDED_FEATURES 0x1004
typedef struct
{
  uint8_t page; /* page number */
} hci_read_local_extended_features_cp;

typedef struct
{
  uint8_t status;                      /* 0x00 - success */
  uint8_t page;                        /* page number */
  uint8_t max_page;                    /* maximum page number */
  uint8_t features[HCI_FEATURES_SIZE]; /* LMP features */
} hci_read_local_extended_features_rp;

#define HCI_OCF_READ_BUFFER_SIZE 0x0005
#define HCI_CMD_READ_BUFFER_SIZE 0x1005
/* No command parameter(s) */
typedef struct
{
  uint8_t status;        /* 0x00 - success */
  uint16_t max_acl_size; /* Max. size of ACL packet (bytes) */
  uint8_t max_sco_size;  /* Max. size of SCO packet (bytes) */
  uint16_t num_acl_pkts; /* Max. number of ACL packets */
  uint16_t num_sco_pkts; /* Max. number of SCO packets */
} hci_read_buffer_size_rp;

/* Read Country Code is deprecated */
#define HCI_OCF_READ_COUNTRY_CODE 0x0007
#define HCI_CMD_READ_COUNTRY_CODE 0x1007
/* No command parameter(s) */
typedef struct
{
  uint8_t status;       /* 0x00 - success */
  uint8_t country_code; /* 0x00 - NAM, EUR, JP; 0x01 - France */
} hci_read_country_code_rp;

#define HCI_OCF_READ_BDADDR 0x0009
#define HCI_CMD_READ_BDADDR 0x1009
/* No command parameter(s) */
typedef struct
{
  uint8_t status;  /* 0x00 - success */
  bdaddr_t bdaddr; /* unit address */
} hci_read_bdaddr_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x05	Status commands and return parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_STATUS 0x05

#define HCI_OCF_READ_FAILED_CONTACT_CNTR 0x0001
#define HCI_CMD_READ_FAILED_CONTACT_CNTR 0x1401
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_failed_contact_cntr_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint16_t counter;    /* number of consecutive failed contacts */
} hci_read_failed_contact_cntr_rp;

#define HCI_OCF_RESET_FAILED_CONTACT_CNTR 0x0002
#define HCI_CMD_RESET_FAILED_CONTACT_CNTR 0x1402
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_reset_failed_contact_cntr_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
} hci_reset_failed_contact_cntr_rp;

#define HCI_OCF_READ_LINK_QUALITY 0x0003
#define HCI_CMD_READ_LINK_QUALITY 0x1403
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_link_quality_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint8_t quality;     /* higher value means better quality */
} hci_read_link_quality_rp;

#define HCI_OCF_READ_RSSI 0x0005
#define HCI_CMD_READ_RSSI 0x1405
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_rssi_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  char rssi;           /* -127 <= rssi <= 127 dB */
} hci_read_rssi_rp;

#define HCI_OCF_READ_AFH_CHANNEL_MAP 0x0006
#define HCI_CMD_READ_AFH_CHANNEL_MAP 0x1406
typedef struct
{
  uint16_t con_handle; /* connection handle */
} hci_read_afh_channel_map_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint8_t mode;        /* AFH mode */
  uint8_t map[10];     /* AFH Channel Map */
} hci_read_afh_channel_map_rp;

#define HCI_OCF_READ_CLOCK 0x0007
#define HCI_CMD_READ_CLOCK 0x1407
typedef struct
{
  uint16_t con_handle; /* connection handle */
  uint8_t clock;       /* which clock */
} hci_read_clock_cp;

typedef struct
{
  uint8_t status;      /* 0x00 - success */
  uint16_t con_handle; /* connection handle */
  uint32_t clock;      /* clock value */
  uint16_t accuracy;   /* clock accuracy */
} hci_read_clock_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x06	Testing commands and return parameters
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_TESTING 0x06

#define HCI_OCF_READ_LOOPBACK_MODE 0x0001
#define HCI_CMD_READ_LOOPBACK_MODE 0x1801
/* No command parameter(s) */
typedef struct
{
  uint8_t status; /* 0x00 - success */
  uint8_t lbmode; /* loopback mode */
} hci_read_loopback_mode_rp;

#define HCI_OCF_WRITE_LOOPBACK_MODE 0x0002
#define HCI_CMD_WRITE_LOOPBACK_MODE 0x1802
typedef struct
{
  uint8_t lbmode; /* loopback mode */
} hci_write_loopback_mode_cp;

typedef hci_status_rp hci_write_loopback_mode_rp;

#define HCI_OCF_ENABLE_UNIT_UNDER_TEST 0x0003
#define HCI_CMD_ENABLE_UNIT_UNDER_TEST 0x1803
/* No command parameter(s) */
typedef hci_status_rp hci_enable_unit_under_test_rp;

#define HCI_OCF_WRITE_SIMPLE_PAIRING_DEBUG_MODE 0x0004
#define HCI_CMD_WRITE_SIMPLE_PAIRING_DEBUG_MODE 0x1804
typedef struct
{
  uint8_t mode; /* simple pairing debug mode */
} hci_write_simple_pairing_debug_mode_cp;

typedef hci_status_rp hci_write_simple_pairing_debug_mode_rp;

/**************************************************************************
 **************************************************************************
 ** OGF 0x3e	Bluetooth Logo Testing
 ** OGF 0x3f	Vendor Specific
 **************************************************************************
 **************************************************************************/

#define HCI_OGF_BT_LOGO 0x3e
#define HCI_OGF_VENDOR 0x3f

/* Ericsson specific FC */
#define HCI_CMD_ERICSSON_WRITE_PCM_SETTINGS 0xFC07
#define HCI_CMD_ERICSSON_SET_UART_BAUD_RATE 0xFC09
#define HCI_CMD_ERICSSON_SET_SCO_DATA_PATH 0xFC1D

/* Cambridge Silicon Radio specific FC */
#define HCI_CMD_CSR_EXTN 0xFC00


#pragma pack(pop)
