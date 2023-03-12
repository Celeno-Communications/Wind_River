// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/log2.h>
#include "cl_ops.h"
#include "cl_ip.h"
#include "chip.h"
#include "cl_ampdu.h"
#include "cl_msg_tx.h"
#include "cl_tx.h"
#include "cl_tx_queue.h"
#include "cl_radio.h"
#include "cl_recovery.h"
#include "cl_rate_ctrl.h"
#include "cl_igmp.h"
#include "cl_band.h"
#include "cl_rx.h"
#include "cl_edca.h"
#include "cl_cma.h"
#include "cl_math.h"
#include "cl_utils.h"
#include "cl_dyn_mcast_rate.h"
#include "cl_dyn_bcast_rate.h"
#include "cl_vns.h"
#include "cl_vw.h"
#include "cl_key.h"
#include "cl_wrs_api.h"
#include "cl_chandef.h"
#include "cl_version.h"
#include "cl_power.h"
#include "cl_calib_dcoc.h"
#include "cl_calib_iq.h"
#include "cl_bss_color.h"
#include "cl_tx_inject.h"
#include "cl_netlink.h"
#include "cl_ipc.h"

static const int cl_ac2hwq[AC_MAX] = {
	[NL80211_TXQ_Q_VO] = CL_HWQ_VO,
	[NL80211_TXQ_Q_VI] = CL_HWQ_VI,
	[NL80211_TXQ_Q_BE] = CL_HWQ_BE,
	[NL80211_TXQ_Q_BK] = CL_HWQ_BK
};

static const int cl_ac2edca[AC_MAX] = {
	[NL80211_TXQ_Q_VO] = EDCA_AC_VO,
	[NL80211_TXQ_Q_VI] = EDCA_AC_VI,
	[NL80211_TXQ_Q_BE] = EDCA_AC_BE,
	[NL80211_TXQ_Q_BK] = EDCA_AC_BK
};

static void cl_ops_tx_agg(struct cl_hw *cl_hw,
			  struct sk_buff *skb,
			  struct ieee80211_tx_info *tx_info,
			  struct cl_sta *cl_sta)
{
	cl_hw->tx_packet_cntr.forward.from_mac_agg++;

	if (!cl_sta) {
		struct cl_vif *cl_vif =
			(struct cl_vif *)tx_info->control.vif->drv_priv;
		u8 tid = skb->priority & IEEE80211_QOS_CTL_TAG1D_MASK;
		int ac = cl_tid_to_ac(tid);

		kfree_skb(skb);
		cl_dbg_err(cl_hw, "cl_sta null in agg packet\n");
		cl_hw->tx_packet_cntr.drop.sta_null_in_agg++;
		cl_vif->trfc_cntrs[ac].tx_errors++;
		return;
	}

#ifdef CE_DUMMY_PHY
	cl_tx_wlan_to_8023(skb);
	cl_tx_agg(cl_hw, cl_sta, skb, true, true);
#else
	/* AMSDU in HW can work only with header conversion. */
	tx_info->control.flags &= ~IEEE80211_TX_CTRL_AMSDU;
	cl_tx_agg(cl_hw, cl_sta, skb, false, true);
#endif
}

static void cl_ops_tx_single(struct cl_hw *cl_hw,
			     struct sk_buff *skb,
			     struct ieee80211_tx_info *tx_info,
			     struct cl_sta *cl_sta)
{
	bool is_vns = cl_vns_is_very_near(cl_hw, cl_sta, skb);

	cl_hw->tx_packet_cntr.forward.from_mac_single++;
	if (cl_hw->tx_db.block_prob_resp) {
		struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;

		if (ieee80211_is_probe_resp(hdr->frame_control)) {
			struct cl_vif *cl_vif = NETDEV_TO_CL_VIF(skb->dev);
			u8 ac = cl_vif->vif->hw_queue[skb_get_queue_mapping(skb)];

			cl_tx_single_free_skb(cl_hw, skb);
			cl_hw->tx_packet_cntr.drop.probe_response++;
			cl_vif->trfc_cntrs[ac].tx_dropped++;
			return;
		}
	}

	cl_tx_single(cl_hw, cl_sta, skb, is_vns, true);
}

void cl_ops_tx(struct ieee80211_hw *hw, struct ieee80211_tx_control *control, struct sk_buff *skb)
{
	/*
	 * Almost all traffic passing here is singles.
	 * Only when opening a BA session some packets with
	 * IEEE80211_TX_CTL_AMPDU set can pass here.
	 * All skbs passing here did header conversion.
	 */
	struct cl_hw *cl_hw = (struct cl_hw *)hw->priv;
	struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
	struct ieee80211_sta *sta = control->sta;
	struct cl_sta *cl_sta = NULL;

	if (sta) {
		cl_sta = IEEE80211_STA_TO_CL_STA(sta);

		/*
		 * Prior to STA connection sta can be set but we don't
		 * want cl_sta to be used since it's not initialized yet
		 */
		if (cl_sta->sta_idx == STA_IDX_INVALID)
			cl_sta = NULL;
	}

	if (cl_recovery_in_progress(cl_hw)) {
		cl_hw->tx_packet_cntr.drop.in_recovery++;

		if (cl_sta) {
			struct cl_vif *cl_vif = cl_sta->cl_vif;

			if (cl_vif) {
				struct ieee80211_vif *vif = cl_vif->vif;
				u8 hw_queue;

				if (vif) {
					hw_queue = vif->hw_queue[skb_get_queue_mapping(skb)];
					cl_vif->trfc_cntrs[hw_queue].tx_dropped++;
				}
			}
		}

		cl_tx_drop_skb(skb);
		return;
	}

	if (tx_info->flags & IEEE80211_TX_CTL_AMPDU)
		cl_ops_tx_agg(cl_hw, skb, tx_info, cl_sta);
	else
		cl_ops_tx_single(cl_hw, skb, tx_info, cl_sta);
}

void cl_ops_rx_finish(struct ieee80211_hw *hw, struct sk_buff *skb, struct ieee80211_sta *sta)
{
	struct cl_hw *cl_hw = (struct cl_hw *)hw->priv;

	cl_rx_finish(cl_hw, skb, sta);
}

int cl_ops_start(struct ieee80211_hw *hw)
{
	/*
	 * Called before the first netdevice attached to the hardware
	 * is enabled. This should turn on the hardware and must turn on
	 * frame reception (for possibly enabled monitor interfaces.)
	 * Returns negative error codes, these may be seen in userspace,
	 * or zero.
	 * When the device is started it should not have a MAC address
	 * to avoid acknowledging frames before a non-monitor device
	 * is added.
	 * Must be implemented and can sleep.
	 * It does not return until the firmware is up and running.
	 */
	int error = 0;
	struct cl_hw *cl_hw = hw->priv;
	struct cl_tcv_conf *conf = cl_hw->conf;

	if (IS_PCI_BUS_TYPE(cl_hw->chip) && !cl_hw->ipc_env) {
		CL_DBG_ERROR(cl_hw, "ipc_env is NULL! 'no_dhcpcd' is missing in nvram folder\n");
		return -1;
	}

	/* Exits if device is already started */
	if (WARN_ON(test_bit(CL_DEV_STARTED, &cl_hw->drv_flags)))
		return -EBUSY;

	/* Send reset message to firmware */
	cl_msg_tx_reset(cl_hw);

	/* Start firmware */
	error = cl_msg_tx_start(cl_hw);
	if (error)
		return error;

	/* Device is now started.
	 * Set CL_DEV_STARTED bit before the calls to other messages sent to
	 * firmware, to prevent them from being blocked*
	 */
	set_bit(CL_DEV_STARTED, &cl_hw->drv_flags);

	if (!cl_recovery_in_progress(cl_hw)) {
		/* Read version */
		error = cl_version_read(cl_hw, false);
		if (error)
			return error;
	}

	/* Set firmware debug module filter */
	error = cl_msg_tx_dbg_set_ce_mod_filter(cl_hw, conf->ci_fw_dbg_module);
	if (error)
		return error;

	/* Set firmware debug severity level */
	error = cl_msg_tx_dbg_set_sev_filter(cl_hw, conf->ci_fw_dbg_severity);
	if (error)
		return error;

	/* Set firmware rate fallbacks */
	error = cl_msg_tx_set_rate_fallback(cl_hw);
	if (error)
		return error;

	error = cl_msg_tx_ndp_tx_control(cl_hw,
					 conf->ci_ndp_tx_chain_mask,
					 conf->ci_ndp_tx_bw,
					 conf->ci_ndp_tx_format,
					 conf->ci_ndp_tx_num_ltf);
	if (error)
		return error;

	/* Set default, multicast, broadcast rate */
	cl_rate_ctrl_set_default(cl_hw);
	cl_dyn_mcast_rate_set(cl_hw);
	cl_dyn_bcast_rate_set(cl_hw, 0);

	ieee80211_wake_queues(hw);

	clear_bit(CL_DEV_INIT, &cl_hw->drv_flags);

	cl_edca_hw_conf(cl_hw);

	if (!cl_hw->chip->conf->ce_calib_runtime_en &&
	    !cl_hw->chip->conf->ci_rf_calib_dis) {
		cl_calib_dcoc_init_calibration(cl_hw);
		cl_calib_iq_init_calibration(cl_hw);
	}

	return error;
}

void cl_ops_stop(struct ieee80211_hw *hw)
{
	/*
	 * Called after last netdevice attached to the hardware
	 * is disabled. This should turn off the hardware (at least
	 * it must turn off frame reception.)
	 * May be called right after add_interface if that rejects
	 * an interface. If you added any work onto the mac80211 workqueue
	 * you should ensure to cancel it on this callback.
	 * Must be implemented and can sleep.
	 */
	struct cl_hw *cl_hw = hw->priv;

	/* Stop mac80211 queues */
	ieee80211_stop_queues(hw);

	/* Go to idle */
	cl_msg_tx_set_idle(cl_hw, MAC_IDLE_SYNC);

	/*
	 * Clear CL_DEV_STARTED to prevent message to be sent (besides reset and start).
	 * It also blocks transmission of new packets
	 */
	clear_bit(CL_DEV_STARTED, &cl_hw->drv_flags);

	/* Send reset message to firmware */
	cl_msg_tx_reset(cl_hw);

	/* Reset IPC */
	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_ipc_reset(cl_hw);

	cl_hw->single_cfm_read_idx = 0;
	cl_hw->single_cfm_write_idx = 0;

	cl_hw->num_ap_started = 0;
	cl_hw->channel = 0;
	cl_hw->radio_status = RADIO_STATUS_OFF;
}

static int add_interface_to_firmware(struct cl_hw *cl_hw, struct ieee80211_vif *vif, u8 vif_index)
{
	struct mm_add_if_cfm *add_if_cfm;
	int ret;

	/* Forward the information to the firmware */
	ret = cl_msg_tx_add_if(cl_hw, vif, vif_index);
	if (ret)
		return ret;

	add_if_cfm = (struct mm_add_if_cfm *)(cl_hw->msg_cfm_params[MM_ADD_IF_CFM]);

	if (add_if_cfm->status != 0) {
		cl_dbg_verbose(cl_hw, "Status Error (%u)\n", add_if_cfm->status);
		ret = -EIO;
	}

	cl_msg_tx_free_cfm_params(cl_hw, MM_ADD_IF_CFM);

	return ret;
}

int cl_ops_add_interface(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
	/*
	 * Called when a netdevice attached to the hardware is
	 * enabled. Because it is not called for monitor mode devices, start
	 * and stop must be implemented.
	 * The driver should perform any initialization it needs before
	 * the device can be enabled. The initial configuration for the
	 * interface is given in the conf parameter.
	 * The callback may refuse to add an interface by returning a
	 * negative error code (which will be seen in userspace.)
	 * Must be implemented and can sleep.
	 */
	struct cl_hw *cl_hw = hw->priv;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;
	struct ieee80211_sub_if_data *sdata = container_of(vif, struct ieee80211_sub_if_data, vif);
	struct net_device *dev = sdata->dev;
	u8 ac, iface_idx;

	if (!dev)
		return -1;

	/*
	 * In recovery just send the message to firmware and exit
	 * (also make sure cl_vif already exists).
	 */
	if (cl_recovery_in_progress(cl_hw) && cl_vif_get_by_dev(cl_hw, dev))
		return add_interface_to_firmware(cl_hw, vif, cl_vif->vif_index);

	cl_vif->cl_hw = cl_hw;
	cl_vif->vif = vif;
	cl_vif->dev = dev;

	if (chip->conf->ce_production_mode || vif->type == NL80211_IFTYPE_STATION)
		cl_vif->tx_en = true;

	/* Copy dev ops and change ndo_start_xmit to point at cl_tx_start() */
	cl_vif->orig_dev_ops = dev->netdev_ops;
	memcpy(&cl_vif->dev_ops, dev->netdev_ops, sizeof(struct net_device_ops));
	cl_vif->dev_ops.ndo_start_xmit = cl_tx_start;
	dev->netdev_ops = &cl_vif->dev_ops;
	iface_idx = cl_hw->tcv_idx == TCV0 ? chip->idx * 2 : chip->idx * 2 + 1;

	if (sscanf(dev->name, CL_IFACE_PREFIX "%hhu_%hhu", &iface_idx, &cl_vif->vif_index) < 2)
		return -1;


	if (add_interface_to_firmware(cl_hw, vif, cl_vif->vif_index))
		return -1;

	cl_igmp_mcast_table_init(cl_hw, cl_vif);

	cl_vif->conn_data = kzalloc(sizeof(*cl_vif->conn_data), GFP_KERNEL);
	if (!cl_vif->conn_data) {
		cl_dbg_verbose(cl_hw, "Memory allocation for conn_data failed !!!\n");
		return -ENOMEM;
	}

	if (vif->type != NL80211_IFTYPE_STATION)
		vif->cab_queue = CL_HWQ_VO;

	cl_vif_add(cl_hw, cl_vif);

	for (ac = 0; ac < AC_MAX; ac++)
		vif->hw_queue[ac] = cl_ac2hwq[ac];

	if (vif->type == NL80211_IFTYPE_MESH_POINT) {
		tasklet_init(&cl_hw->tx_mesh_bcn_task, cl_tx_bcn_mesh_task,
			     (unsigned long)cl_vif);
		cl_radio_on(cl_hw);
		cl_vif->tx_en = true;
	}

	/* Set active state in station mode after ifconfig down and up */
	if (cl_radio_is_on(cl_hw) && vif->type == NL80211_IFTYPE_STATION)
		cl_msg_tx_set_idle(cl_hw, MAC_ACTIVE);

	return 0;
}

void cl_ops_remove_interface(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
	/*
	 * Notifies a driver that an interface is going down.
	 * The stop callback is called after this if it is the last interface
	 * and no monitor interfaces are present.
	 * When all interfaces are removed, the MAC address in the hardware
	 * must be cleared so the device no longer acknowledges packets,
	 * the mac_addr member of the conf structure is, however, set to the
	 * MAC address of the device going away.
	 * Hence, this callback must be implemented. It can sleep.
	 */
	struct cl_hw *cl_hw = hw->priv;
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;

	if (vif->type == NL80211_IFTYPE_MESH_POINT)
		tasklet_kill(&cl_hw->tx_mesh_bcn_task);

	cl_tx_inject_iface_remove(cl_hw, cl_vif);

	if (!cl_recovery_in_progress(cl_hw)) {
		cl_igmp_mcast_table_deinit(cl_hw, cl_vif);
		kfree(cl_vif->conn_data);
		cl_vif_remove(cl_hw, cl_vif);
		cl_msg_tx_remove_if(cl_hw, cl_vif->vif_index);
	} else {
		cl_vif_remove(cl_hw, cl_vif);
	}

	/* Return netdev_ops back to it's original configuration */
	cl_vif->dev->netdev_ops = cl_vif->orig_dev_ops;

	cl_vif->cl_hw = NULL;
	cl_vif->vif = NULL;
	cl_vif->dev = NULL;
}

static int cl_ops_conf_change_channel(struct ieee80211_hw *hw)
{
	struct cl_hw *cl_hw = hw->priv;
	struct cfg80211_chan_def *chandef = &hw->conf.chandef;
	enum nl80211_chan_width width = chandef->width;
	u32 primary = chandef->chan->center_freq;
	u32 center = chandef->center_freq1;
	u8 channel = ieee80211_frequency_to_channel(primary);

	if (!cl_hw->chandef_set) {
		cl_hw->chandef_set = true;
		cl_chandef_get_default(cl_hw, &width, &primary, &center);
		channel = cl_hw->conf->ha_channel;
	}

	if (cl_hw->channel == channel &&
	    cl_hw->bw == width_to_bw(width) &&
	    cl_hw->primary_freq == primary &&
	    cl_hw->center_freq == center)
		return 0;

	/*
	 * Flush the pending data to ensure that we will finish the pending
	 * transmissions before changing the channel
	 */
	if (IS_REAL_PHY(cl_hw->chip))
		cl_ops_flush(hw, NULL, -1, false);

	if (cl_band_is_6g(cl_hw))
		cl_netlink_send_event_co_locate_update(cl_hw);

	if (!cl_hw->chip->conf->ci_rf_init_dis) {
		if (cl_msg_tx_set_channel(cl_hw, channel, width_to_bw(width),
					  primary, center, 0))
			return -EIO;
	}

	return 0;
}

int cl_ops_config(struct ieee80211_hw *hw, u32 changed)
{
	/*
	 * Handler for configuration requests. IEEE 802.11 code calls this
	 * function to change hardware configuration, e.g., channel.
	 * This function should never fail but returns a negative error code
	 * if it does. The callback can sleep
	 */
	int error = 0;

	if (changed & IEEE80211_CONF_CHANGE_CHANNEL)
		error = cl_ops_conf_change_channel(hw);

	return error;
}

/*
 * @bss_info_changed: Handler for configuration requests related to BSS
 *  parameters that may vary during BSS's lifespan, and may affect low
 *  level driver (e.g. assoc/disassoc status, erp parameters).
 *  This function should not be used if no BSS has been set, unless
 *  for association indication. The @changed parameter indicates which
 *  of the bss parameters has changed when a call is made. The callback
 *  can sleep.
 */
void cl_ops_bss_info_changed(struct ieee80211_hw *hw,
			     struct ieee80211_vif *vif,
			     struct ieee80211_bss_conf *info,
			     u32 changed)
{
	struct cl_hw *cl_hw = hw->priv;
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;

	if (changed & BSS_CHANGED_ASSOC) {
		if (cl_msg_tx_set_associated(cl_hw, info))
			return;
	}

	if (changed & BSS_CHANGED_BSSID) {
		if (cl_msg_tx_set_bssid(cl_hw, info->bssid, cl_vif->vif_index))
			return;
	}

	if (changed & BSS_CHANGED_BEACON_INT) {
		if (vif->type == NL80211_IFTYPE_AP ||
		    cl_hw->iface_conf == CL_IFCONF_MESH_ONLY) {
			if (cl_msg_tx_set_beacon_int(cl_hw, info->beacon_int,
						     cl_vif->vif_index))
				return;
			if (cl_msg_tx_dtim(cl_hw, info->dtim_period))
				return;
		}

		if (vif->type == NL80211_IFTYPE_MESH_POINT &&
		    cl_hw->iface_conf == CL_IFCONF_MESH_AP)
			cl_hw->mesh_tbtt_div = (info->beacon_int /
					    cl_hw->conf->ha_beacon_int);
	}

	if (changed & BSS_CHANGED_BASIC_RATES) {
		int shift = hw->wiphy->bands[hw->conf.chandef.chan->band]->bitrates[0].hw_value;

		if (cl_msg_tx_set_basic_rates(cl_hw, info->basic_rates << shift))
			return;
	}

	if (changed & BSS_CHANGED_ERP_SLOT) {
		/* We must be in 11g mode here */
		if (cl_msg_tx_set_slottime(cl_hw, info->use_short_slot))
			return;
	}

	if (changed & BSS_CHANGED_HE_BSS_COLOR)
		cl_msg_tx_set_bss_color(cl_vif, &info->he_bss_color);
}

int cl_ops_start_ap(struct ieee80211_hw *hw, struct ieee80211_vif *vif)
{
	struct cl_hw *cl_hw = hw->priv;
	u8 num_ap = cl_tcv_config_get_num_ap(cl_hw);

	/*
	 * Increase num_ap_started counter and turn radio on only after
	 * all AP's were started.
	 */
	cl_hw->num_ap_started++;

	/* Turn radio ON and run ACS after last AP interface was added */
	if (num_ap == cl_hw->num_ap_started &&
	    cl_hw->conf->ce_radio_on) {
		cl_radio_on(cl_hw);
		return 0;
	}

	/*
	 * Set active state when cl_ops_start_ap() is called not during first driver start
	 * but rather after removing all interfaces and then doing up again to one interface.
	 */
	if (cl_radio_is_on(cl_hw) && !cl_recovery_in_progress(cl_hw))
		cl_msg_tx_set_idle(cl_hw, MAC_ACTIVE);

	return 0;
}

u64 cl_ops_prepare_multicast(struct ieee80211_hw *hw, struct netdev_hw_addr_list *mc_list)
{
	return netdev_hw_addr_list_count(mc_list);
}

void cl_ops_configure_filter(struct ieee80211_hw *hw, u32 changed_flags,
			     u32 *total_flags, u64 multicast)
{
	/*
	 * configure_filter: Configure the device's RX filter.
	 * See the section "Frame filtering" for more information.
	 * This callback must be implemented and can sleep.
	 */
	struct cl_hw *cl_hw = hw->priv;

	cl_dbg_trace(cl_hw, "total_flags = 0x%08x\n", *total_flags);

	/*
	 * Reset our filter flags since our start/stop ops reset
	 * the programmed settings
	 */
	if (!test_bit(CL_DEV_STARTED, &cl_hw->drv_flags)) {
		*total_flags = 0;
		return;
	}

	if (multicast)
		*total_flags |= FIF_ALLMULTI;
	else
		*total_flags &= ~FIF_ALLMULTI;

	cl_msg_tx_set_filter(cl_hw, *total_flags, false);

	*total_flags &= ~(1 << 31);
}

int cl_ops_set_key(struct ieee80211_hw *hw,
		   enum set_key_cmd cmd,
		   struct ieee80211_vif *vif,
		   struct ieee80211_sta *sta,
		   struct ieee80211_key_conf *key)
{
	struct cl_hw *cl_hw = hw->priv;

	return cl_key_set(cl_hw, cmd, vif, sta, key);
}

void cl_ops_sw_scan_start(struct ieee80211_hw *hw,
			  struct ieee80211_vif *vif,
			  const u8 *mac_addr)
{
	struct cl_hw *cl_hw = hw->priv;

	if (cl_hw->conf->ce_radio_on &&
	    cl_radio_is_off(cl_hw) &&
	    vif->type == NL80211_IFTYPE_STATION)
		cl_radio_on(cl_hw);
}

int cl_ops_sta_state(struct ieee80211_hw *hw, struct ieee80211_vif *vif, struct ieee80211_sta *sta,
		     enum ieee80211_sta_state old_state, enum ieee80211_sta_state new_state)
{
	struct cl_hw *cl_hw = hw->priv;
	int error = 0;

	if (old_state == new_state)
		return 0;

	if (old_state == IEEE80211_STA_NOTEXIST &&
	    new_state == IEEE80211_STA_NONE) {
		struct sta_info *stainfo = container_of(sta, struct sta_info, sta);

		error = cl_sta_init_stainfo(cl_hw, stainfo);
	} else if (old_state == IEEE80211_STA_AUTH &&
		   new_state == IEEE80211_STA_ASSOC) {
		error = cl_sta_add(cl_hw, vif, sta);
	} else if (old_state == IEEE80211_STA_ASSOC &&
		   new_state == IEEE80211_STA_AUTH) {
		cl_sta_remove(cl_hw, vif, sta);
	} else if (old_state == IEEE80211_STA_ASSOC &&
		   new_state == IEEE80211_STA_AUTHORIZED) {
		cl_vw_start_tx_ba_session(cl_hw, sta);
	}

	return error;
}

void cl_ops_sta_notify(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
		       enum sta_notify_cmd cmd, struct ieee80211_sta *sta)
{
	struct cl_hw *cl_hw = (struct cl_hw *)hw->priv;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);
	bool is_ps = (bool)!cmd;

	cl_sta_ps_notify(cl_hw, cl_sta, is_ps);
}

int cl_ops_conf_tx(struct ieee80211_hw *hw,
		   struct ieee80211_vif *vif,
		   u16 ac_queue,
		   const struct ieee80211_tx_queue_params *params)
{
	/*
	 * Configure TX queue parameters (EDCF (aifs, cw_min, cw_max),
	 * bursting) for a hardware TX queue.
	 * Returns a negative error code on failure.
	 * The callback can sleep.
	 */

	/* We only handle STA edca here */
	if (vif->type == NL80211_IFTYPE_STATION) {
		struct cl_hw *cl_hw = hw->priv;
		struct ieee80211_he_mu_edca_param_ac_rec mu_edca = {0};
		struct edca_params edca_params = {
			.aifsn = (u8)(params->aifs),
			.cw_min = (u8)(ilog2(params->cw_min + 1)),
			.cw_max = (u8)(ilog2(params->cw_max + 1)),
			.txop = (u8)(params->txop)
		};

		if (cl_hw->conf->ce_wireless_mode > WIRELESS_MODE_HT_VHT)
			memcpy(&mu_edca, &params->mu_edca_param_rec, sizeof(mu_edca));

		cl_edca_set(cl_hw, cl_ac2edca[ac_queue], &edca_params, &mu_edca);
	}
	return 0;
}

void cl_ops_sta_rc_update(struct ieee80211_hw *hw,
			  struct ieee80211_vif *vif,
			  struct ieee80211_sta *sta,
			  u32 changed)
{
	struct cl_hw *cl_hw = (struct cl_hw *)hw->priv;

	if (changed & IEEE80211_RC_BW_CHANGED)
		cl_wrs_api_bw_changed(cl_hw, sta, sta->bandwidth);

	if (changed & IEEE80211_RC_SMPS_CHANGED) {
		struct sta_info *stainfo = container_of(sta, struct sta_info, sta);

		cl_wrs_api_set_smps_mode(cl_hw, sta, stainfo->cur_max_bandwidth);
	}

	if (changed & IEEE80211_RC_NSS_CHANGED) {
		u8 nss = min_t(int, sta->rx_nss, WRS_SS_MAX) - 1;

		cl_wrs_api_nss_changed(cl_hw, sta, nss);
	}
}

int cl_ops_ampdu_action(struct ieee80211_hw *hw,
			struct ieee80211_vif *vif,
			struct ieee80211_ampdu_params *params)
{
	struct cl_hw *cl_hw = (struct cl_hw *)hw->priv;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(params->sta);
	int ret = 0;

	switch (params->action) {
	case IEEE80211_AMPDU_RX_START:
		ret = cl_ampdu_rx_start(cl_hw, cl_sta, params->tid,
					params->ssn, params->buf_size);
		break;
	case IEEE80211_AMPDU_RX_STOP:
		cl_ampdu_rx_stop(cl_hw, cl_sta, params->tid);
		break;
	case IEEE80211_AMPDU_TX_START:
		ret = cl_ampdu_tx_start(cl_hw, vif, cl_sta, params->tid,
					params->ssn);
		break;
	case IEEE80211_AMPDU_TX_OPERATIONAL:
		ret = cl_ampdu_tx_operational(cl_hw, cl_sta, params->tid,
					      params->buf_size, params->amsdu);
		break;
	case IEEE80211_AMPDU_TX_STOP_CONT:
	case IEEE80211_AMPDU_TX_STOP_FLUSH:
	case IEEE80211_AMPDU_TX_STOP_FLUSH_CONT:
		ret = cl_ampdu_tx_stop(cl_hw, vif, params->action, cl_sta,
				       params->tid);
		break;
	default:
		pr_warn("Error: Unknown AMPDU action (%d)\n", params->action);
	}

	return ret;
}

int cl_ops_post_channel_switch(struct ieee80211_hw *hw,
			       struct ieee80211_vif *vif)
{
	return 0;
}

void cl_ops_flush(struct ieee80211_hw *hw, struct ieee80211_vif *vif, u32 queues, bool drop)
{
	struct cl_hw *cl_hw = hw->priv;
	int flush_duration;

	if (test_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags)) {
		cl_dbg_verbose(cl_hw, ": bypassing (CL_DEV_HW_RESTART set)\n");
		return;
	}

	/* Wait for a maximum time of 200ms until all pending frames are flushed */
	for (flush_duration = 0; flush_duration < 200; flush_duration++) {
		if (!cl_txq_frames_pending(cl_hw))
			return;

		/* Lets sleep and hope for the best */
		usleep_range(1000, 2000);
	}
}

bool cl_ops_tx_frames_pending(struct ieee80211_hw *hw)
{
	struct cl_hw *cl_hw = hw->priv;

	return cl_txq_frames_pending(cl_hw);
}

void cl_ops_reconfig_complete(struct ieee80211_hw *hw,
			      enum ieee80211_reconfig_type reconfig_type)
{
	struct cl_hw *cl_hw = hw->priv;

	cl_recovery_reconfig_complete(cl_hw);
}

int cl_ops_get_txpower(struct ieee80211_hw *hw, struct ieee80211_vif *vif, int *dbm)
{
	struct cl_hw *cl_hw = hw->priv;

	if (cl_hw->phy_data_info.data)
		*dbm = cl_power_get_max(cl_hw);
	else
		*dbm = 0;

	return 0;
}

int cl_ops_set_rts_threshold(struct ieee80211_hw *hw, u32 value)
{
	return 0;
}

static void cl_ops_mgd_assoc(struct cl_hw *cl_hw, struct ieee80211_vif *vif)
{
	struct ieee80211_sub_if_data *sdata = container_of(vif, struct ieee80211_sub_if_data, vif);
	struct cl_vif *cl_vif = (struct cl_vif *)vif->drv_priv;
	struct ieee80211_sta *sta = ieee80211_find_sta(vif, sdata->u.mgd.bssid);

	if (!sta) {
		/* Should never happen */
		cl_dbg_verbose(cl_hw, "sta is NULL !!!\n");
		return;
	}

	cl_cma_table_init(cl_hw);

	cl_sta_mgd_add(cl_hw, cl_vif, sta);

	if (cl_hw->iface_conf == CL_IFCONF_REPEATER) {
		struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);

		cl_vif_ap_tx_enable(cl_hw, true);
		set_bit(CL_DEV_REPEATER, &cl_hw->drv_flags);
		cl_bss_color_repeater_handle(cl_vif, cl_sta);
	}
}

static void cl_ops_mgd_disassoc(struct cl_hw *cl_hw)
{
	if (cl_hw->iface_conf == CL_IFCONF_REPEATER) {
		cl_sta_disassociate_ap_iface(cl_hw);
		cl_vif_ap_tx_enable(cl_hw, false);
		clear_bit(CL_DEV_REPEATER, &cl_hw->drv_flags);
	}
}

void cl_ops_event_callback(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
			   const struct ieee80211_event *event)
{
	struct cl_hw *cl_hw = hw->priv;

	if (event->type == MLME_EVENT) {
		if (event->u.mlme.data == ASSOC_EVENT &&
		    event->u.mlme.status == MLME_SUCCESS)
			cl_ops_mgd_assoc(cl_hw, vif);
		else if (event->u.mlme.data == DEAUTH_TX_EVENT ||
			 event->u.mlme.data == DEAUTH_RX_EVENT)
			cl_ops_mgd_disassoc(cl_hw);
	}
}

/* This function is required for PS flow - do not remove */
int cl_ops_set_tim(struct ieee80211_hw *hw, struct ieee80211_sta *sta, bool set)
{
	return 0;
}

u32 cl_ops_get_expected_throughput(struct ieee80211_hw *hw,
				   struct ieee80211_sta *sta)
{
	struct cl_sta *cl_sta = (struct cl_sta *)sta->drv_priv;

	return cl_sta->wrs_sta.tx_su_params.data_rate;
}
