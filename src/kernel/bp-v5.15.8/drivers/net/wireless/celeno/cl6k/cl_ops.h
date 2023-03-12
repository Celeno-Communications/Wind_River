/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_OPS_H
#define CL_OPS_H

#include <net/mac80211.h>

void cl_ops_tx(struct ieee80211_hw *hw, struct ieee80211_tx_control *control, struct sk_buff *skb);
void cl_ops_rx_finish(struct ieee80211_hw *hw, struct sk_buff *skb, struct ieee80211_sta *sta);
int cl_ops_start(struct ieee80211_hw *hw);
void cl_ops_stop(struct ieee80211_hw *hw);
int cl_ops_add_interface(struct ieee80211_hw *hw, struct ieee80211_vif *vif);
void cl_ops_remove_interface(struct ieee80211_hw *hw, struct ieee80211_vif *vif);
int cl_ops_config(struct ieee80211_hw *hw, u32 changed);
void cl_ops_bss_info_changed(struct ieee80211_hw *hw,
			     struct ieee80211_vif *vif,
			     struct ieee80211_bss_conf *info,
			     u32 changed);
int cl_ops_start_ap(struct ieee80211_hw *hw, struct ieee80211_vif *vif);
u64 cl_ops_prepare_multicast(struct ieee80211_hw *hw, struct netdev_hw_addr_list *mc_list);
void cl_ops_configure_filter(struct ieee80211_hw *hw, u32 changed_flags,
			     u32 *total_flags, u64 multicast);
int cl_ops_set_key(struct ieee80211_hw *hw,
		   enum set_key_cmd cmd,
		   struct ieee80211_vif *vif,
		   struct ieee80211_sta *sta,
		   struct ieee80211_key_conf *key);
void cl_ops_sw_scan_start(struct ieee80211_hw *hw,
			  struct ieee80211_vif *vif,
			  const u8 *mac_addr);
int cl_ops_sta_state(struct ieee80211_hw *hw, struct ieee80211_vif *vif, struct ieee80211_sta *sta,
		     enum ieee80211_sta_state old_state, enum ieee80211_sta_state new_state);
void cl_ops_sta_notify(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
		       enum sta_notify_cmd cmd, struct ieee80211_sta *sta);
int cl_ops_conf_tx(struct ieee80211_hw *hw,
		   struct ieee80211_vif *vif,
		   u16 ac_queue,
		   const struct ieee80211_tx_queue_params *params);
void cl_ops_sta_rc_update(struct ieee80211_hw *hw,
			  struct ieee80211_vif *vif,
			  struct ieee80211_sta *sta,
			  u32 changed);
int cl_ops_ampdu_action(struct ieee80211_hw *hw,
			struct ieee80211_vif *vif,
			struct ieee80211_ampdu_params *params);
int cl_ops_post_channel_switch(struct ieee80211_hw *hw,
			       struct ieee80211_vif *vif);
void cl_ops_flush(struct ieee80211_hw *hw, struct ieee80211_vif *vif, u32 queues, bool drop);
bool cl_ops_tx_frames_pending(struct ieee80211_hw *hw);
void cl_ops_reconfig_complete(struct ieee80211_hw *hw,
			      enum ieee80211_reconfig_type reconfig_type);
int cl_ops_get_txpower(struct ieee80211_hw *hw, struct ieee80211_vif *vif, int *dbm);
int cl_ops_set_rts_threshold(struct ieee80211_hw *hw, u32 value);
void cl_ops_event_callback(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
			   const struct ieee80211_event *event);
int cl_ops_set_tim(struct ieee80211_hw *hw, struct ieee80211_sta *sta, bool set);
u32 cl_ops_get_expected_throughput(struct ieee80211_hw *hw, struct ieee80211_sta *sta);

#endif /* CL_OPS_H */
