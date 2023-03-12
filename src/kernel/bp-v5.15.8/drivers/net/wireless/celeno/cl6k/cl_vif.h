/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_VIF_H
#define CL_VIF_H

#include "cl_wrs_db.h"
#include <linux/netdevice.h>

struct cl_connection_data {
	u32 max_client;            /* MAX Clients of the SSID */
	u32 max_client_timestamp;  /* MAX Clients Timestamp of the SSID */
	u32 watermark_threshold;   /* Number of clients threshold for watermark */
	u32 watermark_reached_cnt; /* Number of times the watermark threshold was reached */
};

struct cl_traffic_counters {
	u64 tx_packets;
	u64 tx_bytes;
	u64 rx_packets;
	u64 rx_bytes;
	u32 tx_errors;
	u32 rx_errors;
	u32 tx_dropped;
	u32 rx_dropped;
};

/*
 * Structure used to save information relative to the managed interfaces.
 * Will be used as the 'drv_priv' field of the "struct ieee80211_vif" structure.
 * This is also linked within the cl_hw vifs list.
 */
struct cl_vif {
	struct list_head list;
	struct cl_hw *cl_hw;
	struct ieee80211_vif *vif;
	struct net_device *dev;
	struct net_device_ops dev_ops;
	struct ieee80211_key_conf *key_conf;
	const struct net_device_ops *orig_dev_ops;
	u32 unicast_tx;
	u32 unicast_rx;
	u32 multicast_tx;
	u32 multicast_rx;
	u32 broadcast_tx;
	u32 broadcast_rx;
	u16 sequence_number;
	u8 num_sta; /* Number of station connected per SSID */
	struct cl_connection_data *conn_data;
	u8 vif_index;
	bool tx_en;
	/* Holds info for channel utilization stats */
	u32 chan_util_last_tx_bytes;
	u32 chan_util;
	struct mcast_table *mcast_table;
	struct cl_wrs_rate_params fixed_params;
	struct cl_traffic_counters trfc_cntrs[AC_MAX];
};

void cl_vif_init(struct cl_hw *cl_hw);
void cl_vif_add(struct cl_hw *cl_hw, struct cl_vif *cl_vif);
void cl_vif_remove(struct cl_hw *cl_hw, struct cl_vif *cl_vif);
struct cl_vif *cl_vif_get_next(struct cl_hw *cl_hw, struct cl_vif *cl_vif);
struct cl_vif *cl_vif_get_by_dev(struct cl_hw *cl_hw, struct net_device *dev);
struct cl_vif *cl_vif_get_by_mac(struct cl_hw *cl_hw, u8 *mac_addr);
struct cl_vif *cl_vif_get_first(struct cl_hw *cl_hw);
struct cl_vif *cl_vif_get_first_ap(struct cl_hw *cl_hw);
struct net_device *cl_vif_get_first_net_device(struct cl_hw *cl_hw);
struct net_device *cl_vif_get_dev_by_index(struct cl_hw *cl_hw, u8 index);
bool cl_vif_find_mac(struct cl_hw *cl_hw, u8 *mac_addr);
void cl_vif_ap_tx_enable(struct cl_hw *cl_hw, bool enable);
int cl_vif_trfc_cntrs_print(struct cl_vif *cl_vif);
void cl_vif_trfc_cntrs_reset(struct cl_vif *cl_vif);

#endif /* CL_VIF_H */
