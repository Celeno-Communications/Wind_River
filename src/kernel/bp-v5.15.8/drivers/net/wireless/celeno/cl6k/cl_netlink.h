/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_NETLINK_H
#define CL_NETLINK_H

#include "cl_hw.h"
#include "cl_vif.h"

#define CL_NL_MAX_PAYLOAD 512

struct cl_nl_event {
	char event_id;
	char tcv_idx;
	char data[CL_NL_MAX_PAYLOAD];
};

enum cl_nl_event_id {
	CL_NL_EVENT_ID_CH_SWITCH,
	CL_NL_EVENT_ID_CO_LOCATE_UPDATE,
	CL_NL_EVENT_ID_DISASSOCIATE,
	CL_NL_EVENT_ID_IF_ADD,

	CL_NL_EVENT_ID_MAX
};

struct cl_netlink_csa_params {
	char bss_idx;
	char cs_cnt;
	char bandwidth;
	signed char sec_chan_offset;
	char ht;
	char vht;
	int freq;
	int center_freq1;
	int center_freq2;
};

struct cl_netlink_disassoc_params {
	char bss_idx;
	unsigned char addr[ETH_ALEN];
};

struct cl_netlink_if_add_param {
	char dev_name[NL80211_WIPHY_NAME_MAXLEN];
	char if_name[NL80211_WIPHY_NAME_MAXLEN];
	int if_type;
};

extern struct cl_netlink_sock drv_netlink_socket;

void cl_netlink_send_async(struct cl_hw *cl_hw, struct cl_nl_event *event);
void cl_netlink_send_event_co_locate_update(struct cl_hw *cl_hw);
void cl_netlink_send_event_disassoc(struct cl_vif *cl_vif, u8 *addr);
void cl_netlink_send_event_if_add(struct cl_hw *cl_hw);

#endif /* CL_NETLINK_H */
