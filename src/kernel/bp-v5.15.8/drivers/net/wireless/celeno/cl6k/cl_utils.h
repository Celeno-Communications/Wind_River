/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_UTILS_H
#define CL_UTILS_H

#include "chip.h"
#include "cl_hw.h"
#include "cl_vendor_cmd.h"
#include "cl_vif.h"
#include "cl_ipc_shared.h"
#include "ieee80211_i.h"

#define CL_MS_TO_US(ms)     ((ms) * 1000)
#define CL_SEC_TO_MS(sec)   ((sec) * 1000)
#define CL_SEC_TO_USEC(sec) ((sec) * 1000000)
#define CL_MIN_TO_SEC(min)  ((min) * 60)
#define CL_MIN_TO_MS(min)   ((min) * 60000)

#define CL_BYTES_TO_BITS(bytes) ((bytes) << 3)

static const u8 cl_tid_to_ac_arr[TID_MAX] = {
	AC_BE,
	AC_BK,
	AC_BK,
	AC_BE,
	AC_VI,
	AC_VI,
	AC_VO,
	AC_VO
};

static inline u8 cl_tid_to_ac(int tid)
{
	return cl_tid_to_ac_arr[tid & 7];
}

static inline s16 cl_adc_to_mv(s16 adc)
{
	return (adc * 1800) >> 12;
}

static inline struct cl_vif *NETDEV_TO_CL_VIF(struct net_device *dev)
{
	struct ieee80211_sub_if_data *sdata = netdev_priv(dev);

	return (struct cl_vif *)(sdata->vif.drv_priv);
}

static inline struct cl_hw *NETDEV_TO_CL_HW(struct net_device *dev)
{
	struct ieee80211_sub_if_data *sdata = netdev_priv(dev);

	return sdata->local->hw.priv;
}

static inline struct cl_hw *WIPHY_TO_CL_HW(struct wiphy *wiphy)
{
	struct ieee80211_hw *hw = wiphy_to_ieee80211_hw(wiphy);

	return (struct cl_hw *)hw->priv;
}

void hex_dump(char *caption, u8 *buffer, u32 length, bool is_byte);
void hex_dump2(char *caption, u8 *buffer, u32 length, u32 offset, bool is_byte);
bool cl_is_valid_auth_mode(bool wpa_ie, u8 auth_mode);
u8 convert_gi_format_wrs_to_fw(u8 wrs_mode, u8 gi);
u8 convert_gi_format_fw_to_wrs(u8 format_mode, u8 gi);
u8 cl_map_gi_to_ltf(u8 mode, u8 gi);
s8 cl_calc_noise_floor(struct cl_hw *cl_hw, const s8 *reg_noise_floor);
u8 cl_convert_signed_to_reg_value(s8 val);
u8 width_to_bw(enum nl80211_chan_width width);
enum nl80211_chan_width bw_to_width(u8 bw);
bool is_la_enabled(struct cl_chip *chip);
u64 cl_get_tsf_u64(struct cl_hw *cl_hw);
u8 cl_center_freq_offset(u8 bw);
u8 max_bw_idx(u8 wrs_mode, bool is_24g);
bool cl_hw_mode_is_b_or_bg(struct cl_hw *cl_hw);
void cl_snprintf(char **buf, int *offset, size_t *size, const char *fmt, ...);
__le16 cl_get_frame_ctrl(struct cl_hw *cl_hw, struct sk_buff *skb,
			 struct cl_rx_w2e_hdr *w2e_hdr);
__le16 cl_get_seq_ctrl(struct cl_hw *cl_hw, struct sk_buff *skb,
		       struct cl_rx_w2e_hdr *w2e_hdr);
u8 *cl_get_qos_ctrl(struct cl_hw *cl_hw, struct sk_buff *skb,
		    struct cl_rx_w2e_hdr *w2e_hdr);
u8 cl_get_tid(struct cl_hw *cl_hw, struct sk_buff *skb,
	      struct cl_rx_w2e_hdr *w2e_hdr);
u32 cl_get_ht_ctl(struct cl_hw *cl_hw,
		  struct sk_buff *skb,
		  struct cl_rx_w2e_hdr *w2e_hdr);
u8 cl_get_skb_ac(struct cl_hw *cl_hw, struct sk_buff *skb,
		 struct cl_rx_w2e_hdr *w2e_hdr);
u8 *cl_get_da_addr(struct cl_hw *cl_hw, struct sk_buff *skb,
		   struct cl_rx_w2e_hdr *w2e_hdr);
u8 *cl_get_sa_addr(struct cl_hw *cl_hw, struct sk_buff *skb,
		   struct cl_rx_w2e_hdr *w2e_hdr);
bool cl_is_eapol(struct sk_buff *skb, struct cl_rx_w2e_hdr *w2e_hdr);

#endif /* CL_UTILS_H */
