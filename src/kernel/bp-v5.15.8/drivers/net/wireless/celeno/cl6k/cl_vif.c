// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_vif.h"
#include "cl_hw.h"
#include "cl_mac_addr.h"
#include "cl_utils.h"
#include "cl_bcmc_cfm.h"
#include <linux/list.h>

void cl_vif_init(struct cl_hw *cl_hw)
{
	INIT_LIST_HEAD(&cl_hw->vif_db.head);
}

void cl_vif_add(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	list_add_tail(&cl_vif->list, &cl_hw->vif_db.head);

	if (cl_vif->vif->type != NL80211_IFTYPE_STATION)
		cl_hw->vif_db.num_iface_bcn++;

	/* Multicast vif set */
	cl_hw->mc_vif = cl_vif;
}

void cl_vif_remove(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	/* Multicast vif unset */
	if (cl_hw->mc_vif == cl_vif)
		cl_hw->mc_vif = cl_vif_get_next(cl_hw, cl_hw->mc_vif);

	list_del(&cl_vif->list);

	if (cl_vif->vif->type != NL80211_IFTYPE_STATION)
		cl_hw->vif_db.num_iface_bcn--;

	cl_bcmc_cfm_poll_empty_per_vif(cl_hw, cl_vif);
}

struct cl_vif *cl_vif_get_next(struct cl_hw *cl_hw, struct cl_vif *cl_vif)
{
	if (list_is_last(&cl_vif->list, &cl_hw->vif_db.head))
		return list_first_entry_or_null(&cl_hw->vif_db.head,
						struct cl_vif, list);
	else
		return list_next_entry(cl_vif, list);
}

struct cl_vif *cl_vif_get_by_dev(struct cl_hw *cl_hw, struct net_device *dev)
{
	struct cl_vif *cl_vif, *tmp;

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list)
		if (cl_vif->dev == dev)
			return cl_vif;

	return NULL;
}

struct cl_vif *cl_vif_get_by_mac(struct cl_hw *cl_hw, u8 *mac_addr)
{
	struct cl_vif *cl_vif, *tmp;

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list)
		if (cl_mac_addr_compare(cl_vif->vif->addr, mac_addr))
			return cl_vif;

	return NULL;
}

struct cl_vif *cl_vif_get_first(struct cl_hw *cl_hw)
{
	return list_first_entry_or_null(&cl_hw->vif_db.head, struct cl_vif, list);
}

struct cl_vif *cl_vif_get_first_ap(struct cl_hw *cl_hw)
{
	struct cl_vif *cl_vif, *tmp;

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list)
		if (cl_vif->vif->type == NL80211_IFTYPE_AP ||
		    cl_vif->vif->type == NL80211_IFTYPE_MESH_POINT)
			return cl_vif;

	return NULL;
}

struct net_device *cl_vif_get_first_net_device(struct cl_hw *cl_hw)
{
	struct cl_vif *cl_vif = list_first_entry_or_null(&cl_hw->vif_db.head, struct cl_vif, list);

	return cl_vif ? cl_vif->dev : NULL;
}

struct net_device *cl_vif_get_dev_by_index(struct cl_hw *cl_hw, u8 index)
{
	struct cl_vif *cl_vif, *tmp;

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list)
		if (cl_vif->vif_index == index)
			return cl_vif->dev;

	return NULL;
}

bool cl_vif_find_mac(struct cl_hw *cl_hw, u8 *mac_addr)
{
	struct cl_vif *cl_vif, *tmp;

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list)
		if (cl_mac_addr_compare(cl_vif->vif->addr, mac_addr))
			return true;

	return false;
}

void cl_vif_ap_tx_enable(struct cl_hw *cl_hw, bool enable)
{
	struct cl_vif *cl_vif, *tmp;
	struct ieee80211_vif *vif;

	list_for_each_entry_safe(cl_vif, tmp, &cl_hw->vif_db.head, list) {
		vif = cl_vif->vif;

		if (vif->type != NL80211_IFTYPE_AP)
			continue;

		cl_vif->tx_en = enable;
		cl_dbg_verbose(cl_hw, "Set tx_en=%u for vif_index=%u\n",
			       enable, cl_vif->vif_index);
	}
}

static const s8 *ac_str[] = {
	[AC_BE] = "BE",
	[AC_BK] = "BK",
	[AC_VI] = "VI",
	[AC_VO] = "VO"
};

int cl_vif_trfc_cntrs_print(struct cl_vif *cl_vif)
{
	struct cl_hw *cl_hw = cl_vif->cl_hw;
	u8 ac;
	struct cl_traffic_counters *trfc_cntrs;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	for (ac = 0; ac < AC_MAX; ac++) {
		trfc_cntrs = &cl_vif->trfc_cntrs[ac];

		cl_snprintf(&buf, &len, &buf_size,
			    "VIF [%u], AC [%s]\n",
			    cl_vif->vif_index, ac_str[ac]);
		cl_snprintf(&buf, &len, &buf_size,
			    "------------------------\n"
			    "tx_packets = %llu\n",
			    trfc_cntrs->tx_packets);
		cl_snprintf(&buf, &len, &buf_size,
			    "tx_bytes   = %llu\n", trfc_cntrs->tx_bytes);
		cl_snprintf(&buf, &len, &buf_size,
			    "tx_errors  = %u\n", trfc_cntrs->tx_errors);
		cl_snprintf(&buf, &len, &buf_size,
			    "tx_dropped = %u\n", trfc_cntrs->tx_dropped);
		cl_snprintf(&buf, &len, &buf_size,
			    "rx_packets = %llu\n", trfc_cntrs->rx_packets);
		cl_snprintf(&buf, &len, &buf_size,
			    "rx_bytes   = %llu\n", trfc_cntrs->rx_bytes);
		cl_snprintf(&buf, &len, &buf_size,
			    "rx_errors  = %u\n", trfc_cntrs->rx_errors);
		cl_snprintf(&buf, &len, &buf_size,
			    "rx_dropped = %u\n\n", trfc_cntrs->rx_dropped);
	}

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

void cl_vif_trfc_cntrs_reset(struct cl_vif *cl_vif)
{
	pr_debug("Reset traffic couters for vif %u\n", cl_vif->vif_index);
	memset(cl_vif->trfc_cntrs, 0, sizeof(cl_vif->trfc_cntrs));
}
