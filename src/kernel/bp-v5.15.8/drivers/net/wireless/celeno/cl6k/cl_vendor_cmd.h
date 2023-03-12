/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_VENDOR_CMD_H
#define CL_VENDOR_CMD_H

/*
 * DOC: Vendor commands
 *
 * A driver supporting vendor commands must register them as an array
 * in struct wiphy, with handlers for each one, each command has an
 * OUI and sub command ID to identify it.
 *
 * Note that this feature should not be (ab)used to implement protocol
 * features that could openly be shared across drivers. In particular,
 * it must never be required to use vendor commands to implement any
 * "normal" functionality that higher-level userspace like connection
 * managers etc. need.
 */
#include "cl_eeprom.h"

#define MAX_UNS_LONG ((unsigned long)-1)
#define VENDOR_CMD_TIMER_PERIOD_MS 5000

/* Celeno OUI - see http://www.my-ip.club/oui-info/00-1C-51 */
#define CELENO_OUI 0x001c51

struct cl_hw;

enum cl_vndr_cmds {
	CL_VNDR_CMDS_UNSPEC,
	CL_VNDR_CMDS_CECLI,
	CL_VNDR_CMDS_E2P,
	CL_VNDR_CMDS_OTP,
	CL_VNDR_CMDS_ATE,
	CL_VNDR_CMDS_HELP,
	CL_VNDR_CMDS_LAST
};

enum cl_vndr_events {
	CL_VENDOR_EVENT_ASYNC,
	CL_VENDOR_EVENT_LAST
};

/* Enum cl_vndr_nlattrs - nl80211 message attributes */
enum cl_vndr_nlattrs {
	CL_VENDOR_ATTR_UNSPEC,
	CL_VENDOR_ATTR_REPLY,
	CL_VENDOR_ATTR_DATA,
	CL_VENDOR_ATTR_LEN,

	NUM_CL_VENDOR_ATTR,
	MAX_CL_VENDOR_ATTR = NUM_CL_VENDOR_ATTR - 1
};

struct cl_channel_switch_params {
	int freq;
	int bw;
	int csa_num;
};

struct phy_calib {
	s8 power_offset;
	s8 pdi;
	s8 temp;
} __packed;

struct point {
	u8 power_level;
	u8 chan;
	u8 phy;
	u8 idx;
	u16 addr;
	struct phy_calib calib;
} __packed;

#define CLI_MAX_PARAMS 32
#define MAX_NEIGHBORS_NUM 100

struct wiphy;
void cl_vendor_cmds_init(struct wiphy *wiphy);

/* Note: data structures used by kernel and by userspace */
struct ate_stats {
	u32 tx_bw20;
	u32 tx_bw40;
	u32 tx_bw80;
	u32 tx_bw160;
	u32 rx_bw20;
	u32 rx_bw40;
	u32 rx_bw80;
	u32 rx_bw160;
	u32 fcs_err;
	u32 phy_err;
	u32 delimiter_err;
	u32 rx_succsess;
	s8 rssi0;
	s8 rssi1;
	s8 rssi2;
	s8 rssi3;
	s8 rssi4;
	s8 rssi5;
};

#ifdef NATT_DBG
struct natt_testing_param {
	u32 max_num_valid_mpdu;
	u32 non_valid_mpdu_rate;
	u32 force_min_spacing_mode;
	u32 min_spacing;
	u32 non_data1_len;
	u32 non_data1_num;
	u32 non_data1_padding;
	u32 non_data2_len;
	u32 non_data2_num;
	u32 non_data2_padding;
	u32 airtime_limit;
	u32 last_desc_set;
};
#endif

#ifdef PRESILICON_TESTING
#define PRESILICON_TEST_MAX_PARAMS 20
struct presilicon_testing_param {
	__le32 presilicon_test_index;
	__le32 param[PRESILICON_TEST_MAX_PARAMS];
};
#endif

struct cli_params {
	u32 num_params;
	char option;
	s32 params[CLI_MAX_PARAMS];
};

#define MSG_SIZE 4095

struct cl_msg_data {
	char more_data;
	char data[MSG_SIZE];
} __packed;

int cl_vendor_reply(struct cl_hw *cl_hw, void *data, u16 len);
void cl_vendor_timer_init(struct cl_hw *cl_hw);
void cl_vendor_timer_close(struct cl_hw *cl_hw);

#endif /* CL_VENDOR_CMD_H */
