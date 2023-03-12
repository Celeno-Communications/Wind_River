// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_ate.h"
#include "cl_tx_inject.h"
#include "cl_calibration.h"
#include "cl_rate_ctrl.h"
#include "cl_msg_tx.h"
#include "cl_mib.h"
#include "cl_edca.h"
#include "reg_mac_hw.h"
#include "reg_riu.h"
#include "cl_tx_queue.h"
#include "cl_utils.h"
#include "cl_band.h"
#include "cl_chandef.h"
#include "cl_mac_addr.h"
#include "cl_power.h"
#include "reg_rfic_regs.h"

#define DIFF(_diff, _new, _old, _member)\
	((_diff)._member = (_new)._member - (_old)._member)

static void set_fixed_rate(struct cl_hw *cl_hw)
{
	struct cl_ate_db *ate_db = &cl_hw->ate_db;
	union cl_rate_ctrl_info_he rate_ctrl_he = {.word = 0};
	u8 ltf = 0;

	if (ate_db->mode == WRS_MODE_HE) {
		rate_ctrl_he.field.spatial_conf = RATE_CNTRL_HE_SPATIAL_CONF_DEF;

		if (ate_db->ltf == LTF_MAX)
			ltf = cl_map_gi_to_ltf(WRS_MODE_HE, ate_db->gi);
		else
			ltf = ate_db->ltf;
	}

	cl_hw->entry_fixed_rate = true;

	cl_rate_ctrl_set_fixed(cl_hw, rate_ctrl_he.word, ate_db->mode, ate_db->mcs,
			       ate_db->nss, ate_db->bw, ate_db->gi, 0, ltf);
}

static inline void read_stat(struct cl_hw *cl_hw, struct ate_stats *stats)
{
	stats->tx_bw20 = cl_mib_cntr_read(cl_hw, MIB_DOT11_20MHZ_FRAME_TRANSMITTED_COUNT);
	stats->tx_bw40 = cl_mib_cntr_read(cl_hw, MIB_DOT11_40MHZ_FRAME_TRANSMITTED_COUNT);
	stats->tx_bw80 = cl_mib_cntr_read(cl_hw, MIB_DOT11_80MHZ_FRAME_TRANSMITTED_COUNT);
	stats->tx_bw160 = cl_mib_cntr_read(cl_hw, MIB_DOT11_160MHZ_FRAME_TRANSMITTED_COUNT);
	stats->rx_bw20 = cl_mib_cntr_read(cl_hw, MIB_DOT11_20MHZ_FRAME_RECEIVED_COUNT);
	stats->rx_bw40 = cl_mib_cntr_read(cl_hw, MIB_DOT11_40MHZ_FRAME_RECEIVED_COUNT);
	stats->rx_bw80 = cl_mib_cntr_read(cl_hw, MIB_DOT11_80MHZ_FRAME_RECEIVED_COUNT);
	stats->rx_bw160 = cl_mib_cntr_read(cl_hw, MIB_DOT11_160MHZ_FRAME_RECEIVED_COUNT);
	stats->fcs_err = cl_mib_cntr_read(cl_hw, MIB_DOT11_FCS_ERROR_COUNT);
	stats->phy_err = cl_mib_cntr_read(cl_hw, MIB_DOT11_RX_PHY_ERROR_COUNT);
	stats->delimiter_err = cl_mib_cntr_read(cl_hw, MIB_DOT11_AMPDU_DELIMITER_CRC_ERROR_COUNT);
}

static int dummy_sta_add(struct cl_hw *cl_hw, struct ieee80211_vif *vif, struct ieee80211_sta *sta)
{
	int ret = 0;
	struct ieee80211_sta_ht_cap *ht_cap = &sta->ht_cap;
	struct ieee80211_sta_vht_cap *vht_cap = &sta->vht_cap;
	struct ieee80211_sta_he_cap *he_cap = &sta->he_cap;
	struct sta_info *stainfo = container_of(sta, struct sta_info, sta);

	if (!cl_band_is_6g(cl_hw)) {
		ht_cap->cap = 0xec48;
		ht_cap->ampdu_density = 0x68;
		ht_cap->ampdu_factor = 3;
		ht_cap->ht_supported = true;
		ht_cap->mcs.rx_mask[0] = 0xec;
		ht_cap->mcs.rx_mask[1] = 0xcd;
		ht_cap->mcs.rx_mask[2] = 0xf5;
		ht_cap->mcs.rx_highest = cpu_to_le16(0x100);

		vht_cap->cap = IEEE80211_VHT_CAP_MAX_A_MPDU_LENGTH_EXPONENT_MASK |
			IEEE80211_VHT_CAP_RXLDPC |
			IEEE80211_VHT_CAP_SHORT_GI_80 |
			IEEE80211_VHT_CAP_SHORT_GI_160 |
			IEEE80211_VHT_CAP_SU_BEAMFORMER_CAPABLE |
			IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE |
			IEEE80211_VHT_CAP_MU_BEAMFORMER_CAPABLE |
			IEEE80211_VHT_CAP_MU_BEAMFORMEE_CAPABLE;
		vht_cap->vht_supported = true;
		vht_cap->vht_mcs.rx_highest = 0;
		vht_cap->vht_mcs.rx_mcs_map = 0;
		vht_cap->vht_mcs.tx_mcs_map = cpu_to_le16(1);
		vht_cap->vht_mcs.tx_highest = 0;
	} else {
		struct ieee80211_he_6ghz_capa *he_6ghz_cap = &sta->he_6ghz_capa;

		he_6ghz_cap->capa = cpu_to_le16(IEEE80211_HT_MPDU_DENSITY_2);
		he_6ghz_cap->capa |= cpu_to_le16(cl_hw->conf->ha_max_mpdu_len <<
						 HE_6GHZ_CAP_MAX_MPDU_LEN_OFFSET);
		he_6ghz_cap->capa |= cpu_to_le16(IEEE80211_VHT_MAX_AMPDU_1024K <<
						 HE_6GHZ_CAP_MAX_AMPDU_LEN_EXP_OFFSET);
	}

	he_cap->has_he = true;
	he_cap->he_cap_elem.phy_cap_info[4] |= IEEE80211_HE_PHY_CAP4_MU_BEAMFORMER |
		IEEE80211_HE_PHY_CAP4_SU_BEAMFORMEE;
	if (cl_hw->conf->ce_channel_bandwidth == CHNL_BW_160) {
		he_cap->he_cap_elem.phy_cap_info[0] |=
			IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_160MHZ_IN_5G;
		he_cap->he_mcs_nss_supp.rx_mcs_160 = cpu_to_le16(0xffaa);
		he_cap->he_mcs_nss_supp.tx_mcs_160 = cpu_to_le16(0xffaa);
	} else {
		he_cap->he_cap_elem.phy_cap_info[0] |=
			IEEE80211_HE_PHY_CAP0_CHANNEL_WIDTH_SET_40MHZ_80MHZ_IN_5G;
	}

	he_cap->he_mcs_nss_supp.rx_mcs_80 = cpu_to_le16(0xffaa);
	he_cap->he_mcs_nss_supp.tx_mcs_80 = cpu_to_le16(0xffaa);

	ret = cl_sta_init_stainfo(cl_hw, stainfo);
	if (ret) {
		cl_dbg_err(cl_hw, "cl_sta_init_stainfo failed ret=%d\n", ret);

		return ret;
	}

	ret = cl_sta_add(cl_hw, vif, sta);
	if (ret)
		cl_dbg_err(cl_hw, "cl_ops_sta_add failed ret=%d\n", ret);

	return ret;
}

static bool is_valid_rate_he(struct cl_hw *cl_hw, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	u8 ltf = cl_hw->ate_db.ltf;

	/* BW */
	if (!cl_hw->conf->ce_txldpc_en) {
		if (bw > CHNL_BW_20) {
			u8 bw_mhz = BW_TO_MHZ(bw);

			cl_dbg_err(cl_hw, "Invalid bw [%u] - must be 20 when tx ldpc disabled\n",
				   bw_mhz);
			return false;
		}
	}

	/* NSS */
	if (nss >= cl_hw->conf->ce_tx_nss) {
		cl_dbg_err(cl_hw, "Invalid nss [%u] - must be < %u\n",
			   nss, cl_hw->conf->ce_tx_nss);
		return false;
	}

	/* MCS */
	if (cl_hw->conf->ce_txldpc_en) {
		if (mcs >= WRS_MCS_MAX_HE) {
			cl_dbg_err(cl_hw, "Invalid mcs [%u] - must be 0 - 11\n", mcs);
			return false;
		}
	} else {
		if (mcs >= WRS_MCS_10) {
			cl_dbg_err(cl_hw, "Invalid mcs [%u] - must be 0-9 when tx ldpc disabled\n",
				   mcs);
			return false;
		}
	}

	/* GI */
	if (gi >= WRS_GI_MAX_HE) {
		cl_dbg_err(cl_hw, "Invalid gi [%u] - must be 0(0.8u)/1(1.6u)/2(3.2u)\n", gi);
		return false;
	}

	/* LTF */
	if (ltf > LTF_MAX) {
		cl_dbg_err(cl_hw, "Invalid ltf [%u] - must be 0(X1)/1(X2)/2(X4)\n", ltf);
		return -EINVAL;
	} else if (ltf < LTF_MAX) {
		/*
		 * Supported GI/LTF combinations:
		 * GI = 3.2: LTF_X4
		 * GI = 1.6: LTF_X2
		 * GI = 0.8: LTF_X1, LTF_X2, LTF_X4
		 */
		if (gi == WRS_GI_LONG) {
			if (ltf != LTF_X4) {
				cl_dbg_err(cl_hw, "ltf must be 2 (=X4) for gi=0\n");
				return false;
			}
		} else if (gi == WRS_GI_SHORT) {
			if (ltf != LTF_X2) {
				cl_dbg_err(cl_hw, "ltf must be 1 (=X2) for gi=1\n");
				return false;
			}
		}
	}

	return true;
}

static bool is_valid_rate_vht(struct cl_hw *cl_hw, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	/* NSS */
	if (nss >= cl_hw->conf->ce_tx_nss) {
		cl_dbg_err(cl_hw, "Invalid nss [%u] - must be < %u\n",
			   nss, cl_hw->conf->ce_tx_nss);
		return false;
	}

	/* MCS */
	if (mcs >= WRS_MCS_MAX_VHT) {
		cl_dbg_err(cl_hw, "Invalid mcs [%u] - must be 0-9\n", mcs);
		return false;
	}

	/* GI */
	if (gi >= WRS_GI_MAX_VHT) {
		cl_dbg_err(cl_hw, "Invalid gi [%u] - must be 0(0.8u)/1(0.4u)\n", gi);
		return false;
	}

	/* Make sure it is not an invalid VHT rate */
	if (bw == CHNL_BW_20 && mcs == WRS_MCS_9)
		if (nss == WRS_SS_1 || nss == WRS_SS_2) {
			cl_dbg_err(cl_hw, "nss 1/2 are invalid in bw 20, mcs 9\n");
			return false;
		}

	return true;
}

static bool is_valid_rate_ht(struct cl_hw *cl_hw, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	/* BW */
	if (bw > CHNL_BW_40) {
		u8 bw_mhz = BW_TO_MHZ(bw);

		cl_dbg_err(cl_hw, "Invalid bw [%u] - must be 20/40\n", bw_mhz);
		return false;
	}

	/* NSS */
	if (nss >= cl_hw->conf->ce_tx_nss) {
		cl_dbg_err(cl_hw, "Invalid nss [%u] - must be < %u\n",
			   nss, cl_hw->conf->ce_tx_nss);
		return false;
	}

	/* MCS */
	if (mcs >= WRS_MCS_MAX_HT) {
		cl_dbg_err(cl_hw, "Invalid mcs [%u] - must be 0 - 7\n", mcs);
		return false;
	}

	/* GI */
	if (gi >= WRS_GI_MAX_HT) {
		cl_dbg_err(cl_hw, "Invalid gi [%u] - must be 0(0.8u)/1(0.4u)\n", gi);
		return false;
	}

	return true;
}

static bool is_valid_rate_ofdm(struct cl_hw *cl_hw, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	/*
	 * BW
	 * There is no need to check if bw is valid.
	 * It was already done in is_valid_bw_mhz().
	 * For ofdm we allow bw to be > 20, for FORMAT_NON_HT_DUP.
	 */

	/* NSS */
	if (nss != 0) {
		cl_dbg_err(cl_hw, "Invalid  nss [%u] - must be 0\n", nss);
		return false;
	}

	/* MCS */
	if (mcs >= WRS_MCS_MAX_OFDM) {
		cl_dbg_err(cl_hw, "Invalid  mcs [%u] - must be 0 - 7\n", mcs);
		return false;
	}

	/* GI */
	if (gi != 0) {
		cl_dbg_err(cl_hw, "Invalid  gi [%u] - nust be 0\n", gi);
		return false;
	}

	return true;
}

static bool is_valid_rate_cck(struct cl_hw *cl_hw, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	/* BW */
	if (bw > CHNL_BW_20) {
		u8 bw_mhz = BW_TO_MHZ(bw);

		cl_dbg_err(cl_hw, "Invalid bw [%u] - must be 20\n", bw_mhz);
		return false;
	}

	/* NSS */
	if (nss != 0) {
		cl_dbg_err(cl_hw, "Invalid nss [%u] - must be 0\n", nss);
		return false;
	}

	/* MCS */
	if (mcs >= WRS_MCS_MAX_CCK) {
		cl_dbg_err(cl_hw, "Invalid mcs [%u] - must be 0 - 3\n", mcs);
		return false;
	}

	/* GI */
	if (gi != 0) {
		cl_dbg_err(cl_hw, "Invalid gi [%u] - nust be 0\n", gi);
		return false;
	}

	return true;
}

static bool is_valid_rate(struct cl_hw *cl_hw)
{
	u8 mode = cl_hw->ate_db.mode;
	u8 bw = cl_hw->ate_db.bw;
	u8 nss = cl_hw->ate_db.nss;
	u8 mcs = cl_hw->ate_db.mcs;
	u8 gi = cl_hw->ate_db.gi;

	switch (mode) {
	case WRS_MODE_HE:
		return is_valid_rate_he(cl_hw, bw, nss, mcs, gi);
	case WRS_MODE_VHT:
		return is_valid_rate_vht(cl_hw, bw, nss, mcs, gi);
	case WRS_MODE_HT:
		return is_valid_rate_ht(cl_hw, bw, nss, mcs, gi);
	case WRS_MODE_OFDM:
		return is_valid_rate_ofdm(cl_hw, bw, nss, mcs, gi);
	case WRS_MODE_CCK:
		return is_valid_rate_cck(cl_hw, bw, nss, mcs, gi);
	default:
		cl_dbg_err(cl_hw,
			   "Invalid mode [%u] - must be: 0(cck)/1(ofdm)/2(ht)/3(vht)/4(he)\n",
			   mode);
		break;
	}

	return false;
}

static bool is_valid_bw(struct cl_hw *cl_hw)
{
	if (cl_hw->bw < cl_hw->ate_db.bw) {
		cl_dbg_err(cl_hw, "TX bw [%u] can't be greather than channel bw [%u]\n",
			   BW_TO_MHZ(cl_hw->ate_db.bw), BW_TO_MHZ(cl_hw->bw));
		return false;
	}

	return true;
}

static bool is_valid_bw_mhz(struct cl_hw *cl_hw, u8 bw_mhz)
{
	if (BAND_IS_5G_6G(cl_hw)) {
		if (bw_mhz != BW_TO_MHZ(CHNL_BW_20) &&
		    bw_mhz != BW_TO_MHZ(CHNL_BW_40) &&
		    bw_mhz != BW_TO_MHZ(CHNL_BW_80) &&
		    bw_mhz != BW_TO_MHZ(CHNL_BW_160)) {
			cl_dbg_err(cl_hw,
				   "Invalid bw [%u] - must be 20/40/80/160\n", bw_mhz);
			return false;
		}
	} else {
		if (bw_mhz != BW_TO_MHZ(CHNL_BW_20) &&
		    bw_mhz != BW_TO_MHZ(CHNL_BW_40)) {
			cl_dbg_err(cl_hw, "Invalid bw [%u] - must be 20/40\n", bw_mhz);
			return false;
		}
	}

	return true;
}

int cl_ate_reset(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 default_ant_mask = (1 << cl_hw->num_antennas) - 1;

	/* Reset rate parameters */
	cl_hw->ate_db.mode = 0;
	cl_hw->ate_db.bw = 0;
	cl_hw->ate_db.nss = 0;
	cl_hw->ate_db.mcs = 0;
	cl_hw->ate_db.gi = 0;
	cl_hw->ate_db.ltf = LTF_MAX;

	cl_hw->entry_fixed_rate = false;

	/* Reset TX power */
	cl_hw->ate_db.tx_power = S8_MAX;
	memset(cl_hw->ate_db.tx_power_offset, S8_MAX, MAX_ANTENNAS);

	cl_tx_inject_reset(cl_hw);

	/* Go to ACTIVE state */
	if (cl_hw->chip->conf->ce_production_mode)
		cl_msg_tx_set_idle(cl_hw, MAC_ACTIVE);

	if (cl_hw->ate_db.ant_mask != 0 &&
	    cl_hw->ate_db.ant_mask != default_ant_mask) {
		cl_hw->ate_db.ant_mask = default_ant_mask;
		cl_msg_tx_set_ant_bitmap(cl_hw, default_ant_mask);
	}

	cl_hw->ate_db.active = true;

	/*
	 * Rearm last_tbtt_irq so that error message will
	 * not be printed in cl_irq_status_tbtt()
	 */
	cl_hw->last_tbtt_irq = jiffies;

	cl_dbg_trace(cl_hw, "\n");

	return 0;
}

int cl_ate_mode(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	cl_hw->ate_db.mode = *(u8 *)data;

	cl_dbg_trace(cl_hw, "mode = %u\n", cl_hw->ate_db.mode);

	return 0;
}

int cl_ate_bw(struct wiphy *wiphy, struct wireless_dev *wdev,
	      const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 bw_mhz = *(u8 *)data;

	if (!is_valid_bw_mhz(cl_hw, bw_mhz))
		return -EINVAL;

	cl_hw->ate_db.bw = MHZ_TO_BW(bw_mhz);

	cl_dbg_trace(cl_hw, "bw = %u\n", bw_mhz);

	return 0;
}

int cl_ate_mcs(struct wiphy *wiphy, struct wireless_dev *wdev,
	       const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	cl_hw->ate_db.mcs = *(u8 *)data;

	cl_dbg_trace(cl_hw, "mcs = %u\n", cl_hw->ate_db.mcs);

	return 0;
}

int cl_ate_nss(struct wiphy *wiphy, struct wireless_dev *wdev,
	       const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 val = *(u8 *)data;

	if (val >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid nss value=%u\n", val);
		return -EINVAL;
	}

	cl_hw->ate_db.nss = val;
	cl_dbg_trace(cl_hw, "nss = %u\n", cl_hw->ate_db.nss);

	return 0;
}

int cl_ate_gi(struct wiphy *wiphy, struct wireless_dev *wdev,
	      const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	cl_hw->ate_db.gi = *(u8 *)data;

	cl_dbg_trace(cl_hw, "gi = %u\n", cl_hw->ate_db.gi);

	return 0;
}

int cl_ate_ltf(struct wiphy *wiphy, struct wireless_dev *wdev,
	       const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	cl_hw->ate_db.ltf = *(u8 *)data;

	cl_dbg_trace(cl_hw, "ltf = %u\n", cl_hw->ate_db.ltf);

	return 0;
}

int cl_ate_ldpc(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	cl_hw->conf->ce_txldpc_en = (bool)(*(u8 *)data);

	cl_dbg_trace(cl_hw, "ldpc = %u\n", cl_hw->conf->ce_txldpc_en);

	return 0;
}

int cl_ate_channel(struct wiphy *wiphy, struct wireless_dev *wdev,
		   const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u32 channel = ((u32 *)data)[0];
	u32 bw_mhz = ((u32 *)data)[1];
	s32 freq_delta_q2 = ((s32 *)data)[2];
	u32 bw = 0;
	u32 primary = 0;
	u32 center = 0;
	enum nl80211_chan_width width = NL80211_CHAN_WIDTH_20;

	if (!is_valid_bw_mhz(cl_hw, bw_mhz))
		return -EINVAL;

	if (cl_band_is_6g(cl_hw) && channel == 2 &&
	    bw_mhz != BW_TO_MHZ(CHNL_BW_20)) {
		cl_dbg_err(cl_hw, "Only 20Mhz is allowed for channel 2\n");
		return -EINVAL;
	}

	bw = MHZ_TO_BW(bw_mhz);

	if (cl_chandef_calc(cl_hw, channel, bw, &width, &primary, &center)) {
		cl_dbg_err(cl_hw, "cl_chandef_calc failed\n");
		return -EINVAL;
	}

	if (cl_hw->set_calib) {
		cl_hw->set_calib = false;
		cl_calibration_power_read(cl_hw);
	}

	cl_msg_tx_set_channel(cl_hw, channel, bw, primary,
			      center, (s8)freq_delta_q2);

	return 0;
}

int cl_ate_ant(struct wiphy *wiphy, struct wireless_dev *wdev,
	       const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 ant = *(u8 *)data;
	u8 mask;

	if (ant >= MAX_ANTENNAS) {
		cl_dbg_err(cl_hw, "Invalid antenna value [%u]", ant);
		return -EINVAL;
	}

	mask = (1 << ant);

	if (mask != cl_hw->ate_db.ant_mask) {
		cl_hw->ate_db.ant_mask = mask;
		cl_msg_tx_set_ant_bitmap(cl_hw, mask);
	}

	cl_dbg_trace(cl_hw, "ant = %u, mask = 0x%x\n", ant, mask);

	return 0;
}

#define FULL_ANT_MASK ((1 << MAX_ANTENNAS) - 1)

int cl_ate_multi_ant(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u8 mask = *(u8 *)data;

	if (mask == 0 || mask > FULL_ANT_MASK) {
		cl_dbg_err(cl_hw, "Invalid antenna bitmap [0x%x]", mask);
		return -EINVAL;
	}

	if (mask != cl_hw->ate_db.ant_mask) {
		cl_hw->ate_db.ant_mask = mask;
		cl_msg_tx_set_ant_bitmap(cl_hw, mask);
	}

	cl_dbg_trace(cl_hw, "mask = 0x%x\n", mask);

	return 0;
}

int cl_ate_packet_len(struct wiphy *wiphy, struct wireless_dev *wdev,
		      const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u32 packet_len = *(u32 *)data;

	cl_dbg_trace(cl_hw, "packet_len = %u\n", packet_len);

	return cl_tx_inject_set_length(cl_hw, packet_len);
}

#define FREQ_OFST_MAX  959

int cl_ate_freq_offset(struct wiphy *wiphy, struct wireless_dev *wdev,
		       const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u16 freq_offset = *(u16 *)data;

	if (freq_offset > FREQ_OFST_MAX) {
		cl_dbg_err(cl_hw, "Invalid freq offset 0x%04x\n", freq_offset);
		return -EINVAL;
	}

	cl_dbg_trace(cl_hw, "Freq offset 0x%04x\n", freq_offset);

	rfic_regs_xo_ctrl_1_xo_tun_fn_setf(cl_hw->chip, freq_offset);

	return 0;
}

int cl_ate_stat(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct ate_stats new_stats;
	struct ate_stats ret_stats;
	u8 adcpowdbv;

	read_stat(cl_hw, &new_stats);

	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, tx_bw20);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, tx_bw40);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, tx_bw80);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, tx_bw160);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, rx_bw20);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, rx_bw40);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, rx_bw80);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, rx_bw160);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, fcs_err);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, phy_err);
	DIFF(ret_stats, new_stats, cl_hw->ate_db.stats, delimiter_err);

	/* Present rx seccess of the defined bw */
	switch (cl_hw->ate_db.bw) {
	case CHNL_BW_20:
		ret_stats.rx_succsess = ret_stats.rx_bw20;
		break;
	case CHNL_BW_40:
		ret_stats.rx_succsess = ret_stats.rx_bw40;
		break;
	case CHNL_BW_80:
		ret_stats.rx_succsess = ret_stats.rx_bw80;
		break;
	case CHNL_BW_160:
		ret_stats.rx_succsess = ret_stats.rx_bw160;
		break;
	default:
		/* Should not get here */
		return -EINVAL;
	}

	/* Read rssi */
	riu_agcinbdpow_20_stat_unpack(cl_hw->chip, &ret_stats.rssi3, &ret_stats.rssi2,
				      &ret_stats.rssi1, &ret_stats.rssi0);
	riu_agcadcpowstat_2_unpack(cl_hw->chip, &ret_stats.rssi5, &ret_stats.rssi4,
				   &adcpowdbv, &adcpowdbv);

	cl_dbg_trace(cl_hw, "\n");

	return cl_vendor_reply(cl_hw, &ret_stats, sizeof(struct ate_stats));
}

int cl_ate_stat_reset(struct wiphy *wiphy, struct wireless_dev *wdev,
		      const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	read_stat(cl_hw, &cl_hw->ate_db.stats);

	cl_dbg_trace(cl_hw, "\n");

	return 0;
}

int cl_ate_power(struct wiphy *wiphy, struct wireless_dev *wdev,
		 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	s8 tx_power = *(s8 *)data;
	s8 tx_power_q1 = 0;

	if (tx_power < POWER_MIN_DB || tx_power > POWER_MAX_DB) {
		cl_dbg_err(cl_hw, "Invalid power (%d). Must be between %d and %d\n",
			   tx_power, POWER_MIN_DB, POWER_MAX_DB);
		return 0;
	}

	cl_hw->ate_db.tx_power = tx_power;
	tx_power_q1 = tx_power << 1;

	cl_dbg_trace(cl_hw, "ate_power = %u\n", tx_power);

	memset(&cl_hw->phy_data_info.data->pwr_tables,
	       tx_power_q1, sizeof(struct cl_pwr_tables));

	cl_msg_tx_refresh_power(cl_hw);

	return 0;
}

int cl_ate_power_offset(struct wiphy *wiphy, struct wireless_dev *wdev,
			const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	s8 *pwr_offset = cl_hw->ate_db.tx_power_offset;
	int i;

	for (i = 0; i < MAX_ANTENNAS; i++) {
		pwr_offset[i] = ((s8 *)data)[i];

		if (pwr_offset[i] < POWER_OFFSET_MIN_Q2 ||
		    pwr_offset[i] > POWER_OFFSET_MAX_Q2) {
			cl_dbg_err(cl_hw, "Invalid power offset (%d). Valid range (%d - %d)\n",
				   pwr_offset[i], POWER_OFFSET_MIN_Q2, POWER_OFFSET_MAX_Q2);
			memset(pwr_offset, S8_MAX, MAX_ANTENNAS);
			return -EINVAL;
		}
	}

	cl_dbg_trace(cl_hw, "power_offset = %d,%d\n",
		     pwr_offset[0], pwr_offset[1]);

	return cl_msg_tx_set_ant_pwr_offset(cl_hw, pwr_offset);
}

int cl_ate_tx_start(struct wiphy *wiphy, struct wireless_dev *wdev,
		    const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u32 tx_cnt = *(u32 *)data;

	if (!cl_hw->ate_db.active) {
		cl_dbg_err(cl_hw, "Must call 'ATE reset' first.\n");
		return -EPERM;
	}

	if (tx_cnt == 0) {
		cl_tx_inject_stop_traffic(cl_hw);
		return 0;
	}

	if (cl_tx_inject_is_running(cl_hw)) {
		cl_dbg_err(cl_hw, "TX already running.\n");
		return -EPERM;
	}

	if (!is_valid_rate(cl_hw) || !is_valid_bw(cl_hw))
		return -EPERM;

	set_fixed_rate(cl_hw);
	cl_tx_inject_start(cl_hw, tx_cnt);

	cl_dbg_trace(cl_hw, "\n");

	return 0;
}

int cl_ate_tx_continuous(struct wiphy *wiphy, struct wireless_dev *wdev,
			 const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	if (!cl_hw->ate_db.active) {
		cl_dbg_err(cl_hw, "Must call 'ATE reset' first.\n");
		return -EPERM;
	}

	if (cl_tx_inject_is_running(cl_hw)) {
		cl_dbg_err(cl_hw, "TX already running.\n");
		return -EPERM;
	}

	if (!is_valid_rate(cl_hw) || !is_valid_bw(cl_hw))
		return -EPERM;

	set_fixed_rate(cl_hw);
	cl_tx_inject_start_continuous(cl_hw);

	cl_dbg_trace(cl_hw, "\n");

	return 0;
}

int cl_ate_tx_agg(struct wiphy *wiphy, struct wireless_dev *wdev,
		  const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	u32 tx_cnt = *(u32 *)data;
	u8 sta_num = cl_sta_num_bh(cl_hw);

	if (!cl_hw->ate_db.active) {
		cl_dbg_err(cl_hw, "Must call 'ATE reset' first.\n");
		return -EPERM;
	}

	if (tx_cnt == 0) {
		cl_tx_inject_stop_traffic(cl_hw);
		return 0;
	}

	if (cl_tx_inject_is_running(cl_hw)) {
		cl_dbg_err(cl_hw, "TX already running.\n");
		return -EPERM;
	}

	if (!is_valid_rate(cl_hw) || !is_valid_bw(cl_hw))
		return -EPERM;

	if (sta_num == 0) {
		cl_dbg_err(cl_hw, "No stations connected\n");
		return -EPERM;
	}

	if (cl_hw->ate_db.num_dummy_sta == 0 && ce_tx_inject_real_sta == 0) {
		cl_dbg_err(cl_hw, "No dummy stations connected\n");
		return -EPERM;
	}

	if (sta_num == 1 ||
	    cl_hw->ate_db.mode != WRS_MODE_HE)
		set_fixed_rate(cl_hw);
	else
		cl_sta_loop_bh(cl_hw, cl_rate_ctrl_set_ate_agg);

	cl_tx_inject_start_agg(cl_hw, tx_cnt);

	cl_dbg_trace(cl_hw, "\n");

	return 0;
}

int cl_ate_stop(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);

	cl_tx_inject_stop(cl_hw);

	/* Go back to IDLE state */
	if (cl_hw->chip->conf->ce_production_mode)
		cl_msg_tx_set_idle(cl_hw, MAC_IDLE_SYNC);

	cl_hw->ate_db.active = false;

	cl_dbg_trace(cl_hw, "\n");

	return 0;
}

static u8 find_free_aid(struct cl_hw *cl_hw)
{
	u8 sta_idx;

	for (sta_idx = 0; sta_idx < CL_MAX_NUM_STA; sta_idx++)
		if (!cl_hw->cl_sta_db.lut[sta_idx])
			return sta_idx + 1;

	return 0;
}

int cl_ate_dummy_sta(struct wiphy *wiphy, struct wireless_dev *wdev,
		     const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	struct ieee80211_sub_if_data *sdata;
	struct net_device *dev = wdev->netdev;
	struct sta_info *stainfo = NULL;
	struct ieee80211_sta *sta = NULL;
	struct cl_sta *cl_sta = NULL;
	u8 mac[6] = {0x0, 0x1c, 0x51, 0x0, 0x0, 0x0};
	u8 num_sta = *(u8 *)data;
	u8 i = 0;
	u32 alloc_size = sizeof(struct sta_info) + sizeof(struct cl_sta);
	int ret = 0;

	if (!dev) {
		cl_dbg_err(cl_hw, "dev is NULL\n");
		return -EPERM;
	}

	sdata = IEEE80211_DEV_TO_SUB_IF(dev);
	if (!sdata) {
		cl_dbg_err(cl_hw, "sdata is NULL\n");
		return -EPERM;
	}

	sdata->flags |= IEEE80211_SDATA_IN_DRIVER;
	set_bit(SDATA_STATE_RUNNING, &sdata->state);

	for (i = 0; i < num_sta; i++) {
		if (cl_sta_num_bh(cl_hw) == TX_INJECT_MAX_STA) {
			cl_dbg_err(cl_hw, "Reached maximum of %u stations\n", TX_INJECT_MAX_STA);
			return -EPERM;
		}

		stainfo = kzalloc(alloc_size, GFP_KERNEL);
		if (!stainfo)
			return -ENOMEM;

		stainfo->sdata = sdata;
		stainfo->local = sdata->local;
		stainfo->cur_max_bandwidth = cl_hw->conf->ce_channel_bandwidth;
		stainfo->sta_state = IEEE80211_STA_AUTHORIZED;

		sta = &stainfo->sta;
		cl_mac_addr_copy(sta->addr, mac);
		sta->addr[5] = cl_sta_num_bh(cl_hw);
		sta->bandwidth = cl_hw->conf->ce_channel_bandwidth;
		sta->rx_nss = cl_hw->conf->ce_rx_nss;
		sta->aid = find_free_aid(cl_hw) + CL_MAX_NUM_STA;

		ret = dummy_sta_add(cl_hw, &sdata->vif, sta);
		if (ret) {
			kfree(stainfo);
			return ret;
		}

		/* Must be last because dummy_sta_add() --> cl_ops_sta_add() resets cl_sta! */
		cl_sta = (struct cl_sta *)sta->drv_priv;
		cl_sta->stainfo = stainfo;
		cl_sta->is_dummy = true;

		cl_hw->ate_db.num_dummy_sta++;
	}

	cl_dbg_trace(cl_hw, "\n");

	return 0;
}

int cl_ate_help(struct wiphy *wiphy, struct wireless_dev *wdev,
		const void *data, int data_len)
{
	struct cl_hw *cl_hw = WIPHY_TO_CL_HW(wiphy);
	char *ret_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!ret_buf)
		return -ENOMEM;

	snprintf(ret_buf, PAGE_SIZE,
		 "usage:\n"
		 "reset - Reset ATE configuration\n"
		 "mode <0=CCK,1=OFDM,2=HT,3=VHT,4=HE> - Set mode\n"
		 "bw <20/40/80/160> - Set TX bandwidth parameter\n"
		 "mcs <CCK=0-3, OFDM/HT=0-7, VHT=0-9, HE=0-11> - set mcs parameter\n"
		 "nss <0-1> - set nss parameter\n"
		 "gi <CCK/OFDM=0, HT/VHT=0-1, HE=0-2> - set gi\n"
		 "ltf <HE-LTF: 0=LTF_X1,1=LTF_X2,2=LTF_X4> - set ltf\n"
		 "ldpc <0=Disable, 1=Enable> - set ldpc parameter\n"
		 "channel <ch number> <ch bw [20/40/80/160]> <Frequency delta"
		 " from center Frequency (optional)> - change channel\n"
		 "ant <Antenna index 0-1> - Enable single antenna\n"
		 "multi_ant <Ant bitmap> - Enable multiple antennas\n"
		 "packet_len <packet length (16-4096)> - Set length of packets to inject\n"
		 "freq_offset <0-959> - Set frequency offset\n"
		 "stat <reset (optional)> - Display/Reset statistics\n"
		 "power <-10dB - 30dB> - Set tx power\n"
		 "power_offset <offset_ant0 offset_ant1> - Power"
		 " offset per anthenna [range +/-64][units=0.25dB]\n"
		 "tx_start <Num of packets> - Start TX packets\n"
		 "tx_continuous - Start transmitting infinite packets\n"
		 "tx_agg <Num of packets> - Start TX aggregations\n"
		 "stop - Stop transmission\n"
		 "dummy_sta <Number of stations> - Add dummy station\n");

	err = cl_vendor_reply(cl_hw, ret_buf, strlen(ret_buf));
	kfree(ret_buf);

	return err;
}

