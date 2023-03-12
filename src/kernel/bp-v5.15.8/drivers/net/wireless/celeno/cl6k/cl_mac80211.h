/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MAC80211_H
#define CL_MAC80211_H

#include <linux/types.h>
#include <linux/if_ether.h>

/* Copied from kernel/bp/net/mac80211/wme.c */
static const int ieee802_1d_to_ac[TID_MAX] = {
	IEEE80211_AC_BE,
	IEEE80211_AC_BK,
	IEEE80211_AC_BK,
	IEEE80211_AC_BE,
	IEEE80211_AC_VI,
	IEEE80211_AC_VI,
	IEEE80211_AC_VO,
	IEEE80211_AC_VO
};

#ifdef CE_DUMMY_PHY
extern int ce_scale_down;
#endif

#define IEEE80211_CTRL_A_CTRL_MASK  0x3

#define IEEE80211_CTRL_A_CTRL_ID_OM  0x1
#define IEEE80211_CTRL_A_CTRL_ID_UPH 0x4

#define IEEE80211_CTRL_UPH_OFFSET 6

static inline bool ieee80211_has_a_ctrl(u32 val)
{
	return ((val & IEEE80211_CTRL_A_CTRL_MASK) == IEEE80211_CTRL_A_CTRL_MASK);
}

struct ieee80211_a_control {
	union {
		struct {
			u32 b0 : 1,
			   b1 : 1,
			   control_id : 4,
			   control_info : 26;
		} __packed fields;
		u32 value;
	} u;
} __packed;

struct ieee80211_uph_ctrl {
	union {
		struct {
			u8 pwr_headroom : 5,
			   min_pwr      : 1,
			   reserved     : 2;
		} __packed fields;
		u8 value;
	} u;
} __packed;

/* HTC header might includes HT/VHT/HE variant */
/* This struct implements only HE variant type */
struct ieee80211_qos_htc_hdr {
	__le16 frame_control;
	__le16 duration_id;
	u8 addr1[ETH_ALEN];
	u8 addr2[ETH_ALEN];
	u8 addr3[ETH_ALEN];
	__le16 seq_ctrl;
	__le16 qos_ctrl;
	struct ieee80211_a_control a_ctrl;
} __packed __aligned(2);

/* WLAN_EID_BSS_COEX_2040 = 72 */
/* 802.11n 7.3.2.61 */
struct ieee80211_bss_coex_20_40_ie {
	u8 element_id;
	u8 len;
	u8 info_req : 1;
	/* Inter-BSS set 1 when prohibits a receiving BSS from operating as a 20/40 Mhz BSS */
	u8 intolerant40 : 1;
	/* Intra-BSS set 1 when prohibits a receiving AP from operating its BSS as a 20/40MHz BSS */
	u8 bss20_width_req : 1;
	u8 obss_scan_exemp_req : 1;
	u8 obss_scan_exemp_grant : 1;
	u8 rsv : 3;
} __packed;

/* WLAN_EID_BSS_INTOLERANT_CHL_REPORT = 73 */
/*802.11n 7.3.2.59 */
struct ieee80211_bss_intolerant_chl_report_ie {
	u8 element_id;
	u8 len;
	u8 regulatory_class;
	u8 ch_list[0];
} __packed;

enum ieee80211_twt_setup_command {
	IEEE80211_TWT_SETUP_COMMAND_REQUEST = 0,
	IEEE80211_TWT_SETUP_COMMAND_SUGGEST = 1,
	IEEE80211_TWT_SETUP_COMMAND_DEMAND = 2,
	IEEE80211_TWT_SETUP_COMMAND_GROUPING = 3,
	IEEE80211_TWT_SETUP_COMMAND_ACCEPT = 4,
	IEEE80211_TWT_SETUP_COMMAND_ALTERNATE = 5,
	IEEE80211_TWT_SETUP_COMMAND_DICTATE = 6,
	IEEE80211_TWT_SETUP_COMMAND_REJECT = 7
};

union ieee80211_twt_control_field {
	struct {
		u8 ndp_paging_indicator:1,
		   responder_pm_mode:1,
		   negotiation_type:2,
		   twt_info_frame_disabled:1,
		   wake_duration_unit:1, /* 0 - 256us, 1 - 1024us */
		   reserved:2;
	} __packed fields;
	u8 value;
} __packed;

struct ieee80211_twt_individual_elem {
	union ieee80211_twt_control_field control;
	union {
		struct {
			u16 request               :1,
			    setup_cmd             :3,
			    trigger               :1,
			    implicit              :1,
			    flow_type             :1,
			    flow_id               :3,
			    wake_interval_exponent:5,
			    protection            :1;
		} __packed fields;
		u16 value;
	} req_type;
	u64 target_wake_time;
	u8 min_wake_duration;
	u16 wake_interval_mantissa;
	u8 channel;
} __packed;

struct ieee80211_twt_broadcast_elem {
	union ieee80211_twt_control_field control;
	union {
		struct {
			u16 request                 :1,
			    setup_cmd               :3,
			    trigger                 :1,
			    last_broadcast_param_set:1,
			    flow_type               :1,
			    recommendation          :3,
			    wake_interval_exponent  :5,
			    reserved                :1;
		} __packed fields;
		u16 value;
	} req_type;
	u16 target_wake_time;
	u8 min_wake_duration;
	u16 wake_interval_mantissa;
	union {
		struct {
			u16 reserved   :3,
			    id         :5,
			    persistence:8;
		} __packed fields;
		u16 value;
	} broadcast_twt_info;
} __packed;

/* Union options that are not included in 'struct ieee80211_mgmt' */
struct cl_ieee80211_mgmt {
	__le16 frame_control;
	__le16 duration;
	u8 da[ETH_ALEN];
	u8 sa[ETH_ALEN];
	u8 bssid[ETH_ALEN];
	__le16 seq_ctrl;
	union {
		struct {
			__le16 auth_alg;
			__le16 auth_transaction;
			__le16 status_code;
			/* Possibly followed by Challenge text */
			u8 variable[0];
		} __packed auth;
		struct {
			__le16 reason_code;
		} __packed deauth;
		struct {
			__le16 capab_info;
			__le16 listen_interval;
			/* Followed by SSID and Supported rates */
			u8 variable[0];
		} __packed assoc_req;
		struct {
			__le16 capab_info;
			__le16 status_code;
			__le16 aid;
			/* Followed by Supported rates */
			u8 variable[0];
		} __packed assoc_resp, reassoc_resp;
		struct {
			__le16 capab_info;
			__le16 listen_interval;
			u8 current_ap[ETH_ALEN];
			/* Followed by SSID and Supported rates */
			u8 variable[0];
		} __packed reassoc_req;
		struct {
			__le16 reason_code;
		} __packed disassoc;
		struct {
			__le64 timestamp;
			__le16 beacon_int;
			__le16 capab_info;
			/*
			 * Followed by some of SSID, Supported rates,
			 * FH Params, DS Params, CF Params, IBSS Params, TIM
			 */
			u8 variable[0];
		} __packed beacon;
		struct {
			/* Only variable items: SSID, Supported rates */
			u8 variable[0];
		} __packed probe_req;
		struct {
			__le64 timestamp;
			__le16 beacon_int;
			__le16 capab_info;
			/*
			 * Followed by some of SSID, Supported rates,
			 * FH Params, DS Params, CF Params, IBSS Params
			 */
			u8 variable[0];
		} __packed probe_resp;
		struct {
			u8 category;
			union {
				struct {
					u8 action_code;
					struct ieee80211_bss_coex_20_40_ie bss_coex_20_40_ie;
					/*
					 * This IE May appear zero or more times,
					 * that situation wasn't handled here.
					 */
					struct ieee80211_bss_intolerant_chl_report_ie
						bss_intolerant_chl_report_ie;
				} __packed coex_2040_mgmt;
				struct {
					u8 action_code;
					u8 dialog_token;
					u8 twt_elem_id;
					u8 twt_elem_length;
					struct ieee80211_twt_individual_elem twt_elem;
				} __packed twt_individual_setup;
				struct {
					u8 action_code;
					u8 dialog_token;
					u8 twt_elem_id;
					u8 twt_elem_length;
					struct ieee80211_twt_broadcast_elem twt_elem;
				} __packed twt_broadcast_setup;
				struct {
					u8 action_code;
					/*
					 * reserved bits can be combined with flow_id to
					 * form broadcast TWT id of 5 bits in case that
					 * negotiation_type = 3
					 */
					u8 flow_id :3,
					   reserved:2,
					   negotiation_type:2,
					   teardown_all_twt:1;
				} __packed twt_individual_teardown;
				struct {
					u8 action_code;
					u8 flow_id:3,
					   response_requested:1,
					   next_twt_request:1,
					   next_twt_subfield_size:2,
					   all_twt:1;
					u8 next_twt[64];
				} __packed twt_information;
			} u;
		} __packed action;
	} u;
} __packed __aligned(2);

/*
 * Information Element IDs
 * Should be part of 'enum ieee80211_eid'
 */
#define WLAN_EID_TWT 216

/*
 * Action category code
 * Should be part of 'enum ieee80211_category'
 */
enum ieee80211_unprotected_s1g_actioncode {
	WLAN_UNPROT_S1G_ACTION_AID_SWITCH_REQUEST = 0,
	WLAN_UNPROT_S1G_ACTION_AID_SWITCH_RESPONSE = 1,
	WLAN_UNPROT_S1G_ACTION_SYNC_CONTROL = 2,
	WLAN_UNPROT_S1G_ACTION_STA_INFO_ANNOUNCEMENT = 3,
	WLAN_UNPROT_S1G_ACTION_EDCA_PARAMETER_SET = 4,
	WLAN_UNPROT_S1G_ACTION_EL_OPERATION = 5,
	WLAN_UNPROT_S1G_ACTION_TWT_SETUP = 6,
	WLAN_UNPROT_S1G_ACTION_TWT_TEARDOWN = 7,
	WLAN_UNPROT_S1G_ACTION_SECTORIZED_GROUP_ID_LIST = 8,
	WLAN_UNPROT_S1G_ACTION_SECTOR_ID_FEEDBACK = 9,
	WLAN_UNPROT_S1G_ACTION_RESERVED = 10,
	WLAN_UNPROT_S1G_ACTION_TWT_INFORMATION = 11,
};

#endif /* CL_MAC80211_H */
