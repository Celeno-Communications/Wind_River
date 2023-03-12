// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/socket.h>
#include <linux/rtnetlink.h>
#include <net/cfg80211.h>

#include "cl_netlink.h"

void cl_netlink_send_async(struct cl_hw *cl_hw, struct cl_nl_event *event)
{
	struct sk_buff *skb = NULL;
	int msg_len;

	msg_len = sizeof(*event);
	skb = cfg80211_vendor_event_alloc(cl_hw->hw->wiphy, NULL, msg_len,
					  CL_VENDOR_EVENT_ASYNC, GFP_ATOMIC);
	if (!skb) {
		cl_dbg_err(cl_hw, "vendor_event_alloc(len:%u) failed\n", msg_len);
		return;
	}

	if (nla_put(skb, CL_VENDOR_ATTR_DATA, msg_len, event)) {
		kfree_skb(skb);
		return;
	}

	cfg80211_vendor_event(skb, GFP_ATOMIC);
}

void cl_netlink_send_event_co_locate_update(struct cl_hw *cl_hw)
{
	struct cl_nl_event event = {0};

	event.tcv_idx = cl_hw->idx;
	event.event_id = CL_NL_EVENT_ID_CO_LOCATE_UPDATE;

	cl_netlink_send_async(cl_hw, &event);
}

void cl_netlink_send_event_disassoc(struct cl_vif *cl_vif, u8 *addr)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	struct cl_nl_event event = {0};
	struct cl_netlink_disassoc_params disassoc = {0};

	event.tcv_idx = cl_hw->idx;
	event.event_id = CL_NL_EVENT_ID_DISASSOCIATE;

	disassoc.bss_idx = cl_vif->vif_index;
	memcpy(disassoc.addr, addr, ETH_ALEN);

	memcpy(event.data, &disassoc, sizeof(disassoc));
	cl_netlink_send_async(cl_hw, &event);
}

void cl_netlink_send_event_if_add(struct cl_hw *cl_hw)
{
	struct cl_nl_event event = {0};
	struct cl_netlink_if_add_param if_add = {0};

	event.tcv_idx = cl_hw->idx;
	event.event_id = CL_NL_EVENT_ID_IF_ADD;

	snprintf(if_add.dev_name, sizeof(if_add.dev_name), "chip%u", cl_hw->chip->idx);
	snprintf(if_add.if_name, sizeof(if_add.if_name), "wlan%u_0", cl_hw->idx);
	if_add.if_type = cl_hw->iface_conf;

	memcpy(event.data, &if_add, sizeof(if_add));

	cl_netlink_send_async(cl_hw, &event);
}
