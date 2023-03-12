// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/dma-mapping.h>
#include <linux/list.h>
#include <linux/jiffies.h>
#include <linux/kthread.h>
#include <net/mac80211.h>
#include <linux/sched/signal.h>
#include "cl_utils.h"
#include "cl_rx.h"
#include "cl_tx.h"
#include "cl_debugfs.h"
#include "cl_prof.h"
#include "cl_ipc_shared.h"
#include "cl_traffic.h"
#include "reg_riu.h"
#include "reg_mac_hw.h"

#define GI_08  0
#define GI_16  1
#define GI_32  2
#define GI_04  3

#define GI_MAX_FW 4
#define GI_MAX_HE 3
#define GI_MAX_HT_VHT 2

#define CL_TSF_LOW_MIGHT_OVERFLOW_TH 0xFFFFF000

static u8 conv_wrs_gi_ht_vht[GI_MAX_HT_VHT] = {
	[WRS_GI_LONG] = GI_08,
	[WRS_GI_SHORT] = GI_04
};

static u8 conv_wrs_gi_he[GI_MAX_HE] = {
	[WRS_GI_LONG] = GI_32,
	[WRS_GI_SHORT] = GI_16,
	[WRS_GI_VSHORT] = GI_08
};

static u8 conv_fw_gi_ht_vht[GI_MAX_FW] = {
	[GI_08] = WRS_GI_LONG,
	[GI_16] = 0,
	[GI_32] = 0,
	[GI_04] = WRS_GI_SHORT,
};

static u8 conv_fw_gi_he[GI_MAX_FW] = {
	[GI_08] = WRS_GI_VSHORT,
	[GI_16] = WRS_GI_SHORT,
	[GI_32] = WRS_GI_LONG,
	[GI_04] = 0,
};

void hex_dump2(char *caption, u8 *buffer, u32 length, u32 offset, bool is_byte)
{
	u8 *pt = buffer;
	u32 i;
	bool end_nl = false;
	char buf[STR_LEN_256B] = {0};
	int len = 0;

	if (caption)
		pr_debug("%s: %p, len = %u\n", caption, buffer, length);

	if (is_byte) {
		for (i = 0; i < length; i++) {
			if (i % 16 == 0)
				len += snprintf(buf + len, sizeof(buf) - len,
						"0x%04x : ", i + offset);
			len += snprintf(buf + len, sizeof(buf) - len,
					"%02x ", ((u8)pt[i]));
			end_nl = true;
			if (i % 16 == 15) {
				pr_debug("%s", buf);
				len = 0;
				end_nl = false;
			}
		}
	} else {
		for (i = 0; i < (length / sizeof(u32)); i++) {
			if (i % 4 == 0)
				len += snprintf(buf + len, sizeof(buf) - len,
						"0x%04x : ",
						(u32)(i * sizeof(u32) + offset));
			len += snprintf(buf + len, sizeof(buf) - len,
					"%08x ", *((u32 *)(pt + i * sizeof(u32))));
			end_nl = true;
			if (i % 4 == 3) {
				pr_debug("%s", buf);
				len = 0;
				end_nl = false;
			}
		}
	}

	if (end_nl)
		pr_debug("%s", buf);
}

void hex_dump(char *caption, u8 *buffer, u32 length, bool is_byte)
{
	hex_dump2(caption, buffer, length, 0, is_byte);
}

u8 convert_gi_format_wrs_to_fw(u8 wrs_mode, u8 gi)
{
	if (wrs_mode == WRS_MODE_HE && gi < GI_MAX_HE)
		return conv_wrs_gi_he[gi];
	else if (wrs_mode > WRS_MODE_OFDM && gi < GI_MAX_HT_VHT)
		return conv_wrs_gi_ht_vht[gi];
	else
		return 0;
}

u8 convert_gi_format_fw_to_wrs(u8 format_mode, u8 gi)
{
	if (gi < GI_MAX_FW) {
		if (format_mode >= FORMATMOD_HE_SU)
			return conv_fw_gi_he[gi];
		else if (format_mode >= FORMATMOD_HT_MF)
			return conv_fw_gi_ht_vht[gi];
	}

	return 0;
}

static u8 map_gi_to_ltf[WRS_GI_MAX] = {
	[WRS_GI_LONG] = LTF_X4,
	[WRS_GI_SHORT] = LTF_X2,
	[WRS_GI_VSHORT] = LTF_X2,
};

u8 cl_map_gi_to_ltf(u8 mode, u8 gi)
{
	if (mode == WRS_MODE_HE && gi < WRS_GI_MAX)
		return map_gi_to_ltf[gi];

	return 0;
}

/* This table holds 10^(-110 -> 0) Q39 values for rx RSSI and noise floor calculations */
#define CL_EXP_TBL_SIZE 111 /* 10^x table size (-110 -> 0dBm) */

static u64 CL_EXP_10[CL_EXP_TBL_SIZE] = {
	0x7FFFFFFFFFULL, 0x65AC8C2F36ULL, 0x50C335D3DBLL, 0x4026E73CCDULL, 0x32F52CFEEAULL, 0x287A26C490ULL,
	0x2026F30FBBULL, 0x198A13577CULL, 0x144960C577ULL, 0x101D3F2D96ULL, 0x0CCCCCCCCDULL, 0x0A2ADAD185ULL,
	0x08138561FCULL, 0x066A4A52E1ULL, 0x0518847FE4ULL, 0x040C3713A8ULL, 0x0337184E5FULL, 0x028DCEBBF3ULL,
	0x0207567A25ULL, 0x019C86515CULL, 0x0147AE147BULL, 0x01044914F4ULL, 0x00CEC089CC, 0x00A43AA1E3,
	0x008273A664, 0x00679F1B91, 0x00524F3B0A, 0x0041617932, 0x0033EF0C37, 0x002940A1BC,
	0x0020C49BA6, 0x001A074EE5, 0x0014ACDA94, 0x00106C4364, 0x000D0B90A4, 0x000A5CB5F5,
	0x00083B1F81, 0x000689BF52, 0x0005318139, 0x000420102C, 0x000346DC5D, 0x00029A54B1,
	0x000211490F, 0x0001A46D24, 0x00014DF4DD, 0x0001094565, 0x0000D2B65A, 0x0000A75FEF,
	0x000084F352, 0x0000699B38, 0x000053E2D6, 0x000042A212, 0x000034EDB5, 0x00002A0AEA,
	0x0000216549, 0x00001A86F1, 0x000015123C, 0x000010BCCB, 0x00000D4B88, 0x00000A8F86,
	0x000008637C, 0x000006A9CF, 0x0000054AF8, 0x000004344B, 0x00000356EE, 0x000002A718,
	0x0000021B6C, 0x000001AC7B, 0x000001545A, 0x0000010E5A, 0x000000D6C0, 0x000000AA95,
	0x000000877F, 0x0000006BA1, 0x000000557E, 0x00000043E9, 0x00000035F1, 0x0000002AD9,
	0x0000002209, 0x0000001B09, 0x000000157A, 0x000000110F, 0x0000000D8D, 0x0000000AC3,
	0x000000088D, 0x00000006CA, 0x0000000565, 0x0000000449, 0x0000000367, 0x00000002B4,
	0x0000000226, 0x00000001B5, 0x000000015B, 0x0000000114, 0x00000000DB, 0x00000000AE,
	0x000000008A, 0x000000006E, 0x0000000057, 0x0000000045, 0x0000000037, 0x000000002C,
	0x0000000023, 0x000000001C, 0x0000000016, 0x0000000011, 0x000000000E, 0x000000000B,
	0x0000000009, 0x0000000007, 0x0000000005
};

static s8 cl_eng_to_noise_floor(u64 eng)
{
	s8 i = 0;
	s8 noise = 0;
	s64 min_delta = S64_MAX;

	for (i = CL_EXP_TBL_SIZE - 1; i >= 0; i--) {
		if (abs((s64)(((s64)eng) - ((s64)CL_EXP_10[i]))) < min_delta) {
			min_delta = abs((s64)(((s64)eng) - ((s64)CL_EXP_10[i])));
			noise = i;
		}
	}

	return (-noise);
}

static void cl_read_reg_noise(struct cl_hw *cl_hw, s8 res[4])
{
	u32 reg_val = riu_agcinbdpow_20_pnoisestat_get(cl_hw->chip);
	u8 i = 0;

	for (i = 0; i < 4; i++) {
		u8 curr_val = (reg_val >> (i * 8)) & 0xFF;
		/* Convert reg value to real value */
		res[i] = curr_val - 0xFF;
	}
}

s8 cl_calc_noise_floor(struct cl_hw *cl_hw, const s8 *reg_noise_floor)
{
	s8 noise_floor[4] = {0};
	u64 noise_floor_eng = 0;

	if (reg_noise_floor)
		memcpy(noise_floor, reg_noise_floor, sizeof(noise_floor));
	else
		cl_read_reg_noise(cl_hw, noise_floor);

	noise_floor[0] = abs(noise_floor[0]);
	noise_floor[1] = abs(noise_floor[1]);
	noise_floor[2] = abs(noise_floor[2]);
	noise_floor[3] = abs(noise_floor[3]);

	noise_floor_eng = (CL_EXP_10[min(noise_floor[0], (s8)(CL_EXP_TBL_SIZE - 1))] +
			   CL_EXP_10[min(noise_floor[1], (s8)(CL_EXP_TBL_SIZE - 1))] +
			   CL_EXP_10[min(noise_floor[2], (s8)(CL_EXP_TBL_SIZE - 1))] +
			   CL_EXP_10[min(noise_floor[3], (s8)(CL_EXP_TBL_SIZE - 1))]);

	noise_floor_eng = div64_u64(noise_floor_eng, 4);

	return cl_eng_to_noise_floor(noise_floor_eng);
}

u8 cl_convert_signed_to_reg_value(s8 val)
{
	bool sign = (val < 0 ? true : false);
	u8 res = abs(val);

	if (sign)
		res |= (1 << 7);

	return res;
}

static const int nl_width_to_phy_bw[] = {
	[NL80211_CHAN_WIDTH_20_NOHT] = CHNL_BW_20,
	[NL80211_CHAN_WIDTH_20]      = CHNL_BW_20,
	[NL80211_CHAN_WIDTH_40]      = CHNL_BW_40,
	[NL80211_CHAN_WIDTH_80]      = CHNL_BW_80,
	[NL80211_CHAN_WIDTH_80P80]   = CHNL_BW_20,
	[NL80211_CHAN_WIDTH_160]     = CHNL_BW_160,
	[NL80211_CHAN_WIDTH_5]       = CHNL_BW_20,
	[NL80211_CHAN_WIDTH_10]      = CHNL_BW_20,
};

u8 width_to_bw(enum nl80211_chan_width width)
{
	if (width <= NL80211_CHAN_WIDTH_10)
		return nl_width_to_phy_bw[width];

	return NL80211_CHAN_WIDTH_20;
}

static const int phy_bw_to_nl_width[] = {
	[CHNL_BW_20]  = NL80211_CHAN_WIDTH_20,
	[CHNL_BW_40]  = NL80211_CHAN_WIDTH_40,
	[CHNL_BW_80]  = NL80211_CHAN_WIDTH_80,
	[CHNL_BW_160] = NL80211_CHAN_WIDTH_160,
};

enum nl80211_chan_width bw_to_width(u8 bw)
{
	if (bw < CHNL_BW_MAX)
		return phy_bw_to_nl_width[bw];

	return CHNL_BW_20;
}

bool cl_is_valid_auth_mode(bool is_wpa, u8 auth_mode)
{
	return is_wpa ? (auth_mode <= CL_AKM_SUITE_PSK) :
		(auth_mode <= CL_AKM_SUITE_FT_FILS_SHA384);
}

bool is_la_enabled(struct cl_chip *chip)
{
	s8 *ela_mode = chip->conf->ce_ela_mode;

	return (!strcmp(ela_mode, "default") ||
		!strncmp(ela_mode, "lcu_bt", 6) ||
		!strncmp(ela_mode, "lcu_mac", 7) ||
		!strncmp(ela_mode, "lcu_phy", 7));
}

u64 cl_get_tsf_u64(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 tsf_low = mac_hw_tsf_lo_get(chip);
	u32 tsf_high = mac_hw_tsf_hi_get(chip);
	u64 tsf;

	if (tsf_low > CL_TSF_LOW_MIGHT_OVERFLOW_TH) {
		u32 tmp_tsf_low = mac_hw_tsf_lo_get(chip);

		/* Overflow of tsf_low occurred */
		if (tmp_tsf_low < 0xFFFFF000)
			tsf_high++;
	}

	tsf = ((u64)tsf_high << 32) | (u64)tsf_low;

	return tsf;
}

u8 cl_center_freq_offset(u8 bw)
{
	if (bw == CHNL_BW_160)
		return 70;

	if (bw == CHNL_BW_80)
		return 30;

	if (bw == CHNL_BW_40)
		return 10;

	return 0;
}

u8 max_bw_idx(u8 wrs_mode, bool is_24g)
{
	if (wrs_mode < WRS_MODE_HT)
		return CHNL_BW_20 + 1;

	if (wrs_mode == WRS_MODE_HT || is_24g)
		return CHNL_BW_40 + 1;

	return CHNL_BW_MAX;
}

bool cl_hw_mode_is_b_or_bg(struct cl_hw *cl_hw)
{
	return (cl_hw->conf->ha_hw_mode == HW_MODE_B ||
		cl_hw->conf->ha_hw_mode == HW_MODE_BG);
}

void cl_snprintf(char **buf, int *offset, size_t *size, const char *fmt, ...)
{
	void *new_buf = NULL;
	va_list args;
	u16 str_len = strlen(fmt);
	u16 new_size;

	if (!*buf) {
		*size = PAGE_SIZE;
		*buf = kzalloc(*size, GFP_KERNEL);
		if (!*buf) {
			pr_err("Buffer allocation failed (%u)\n", (u32)*size);
			return;
		}
	}

	/* Additional space is required */
	if (str_len > *size - *offset) {
		new_size = *size * 2;
		new_buf = kvzalloc(new_size, GFP_KERNEL);
		if (new_buf) {
			*size = new_size;
			memcpy(new_buf, *buf, strlen(*buf));
			kvfree(*buf);
			*buf = new_buf;
		} else {
			pr_err("Buffer allocation failed (%u)\n", (u32)*size);
			return;
		}
	}

	va_start(args, fmt);
	*offset += vsnprintf(*buf + *offset, *size, fmt, args);
	va_end(args);
}

__le16 cl_get_frame_ctrl(struct cl_hw *cl_hw, struct sk_buff *skb,
			 struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;

	if (w2e_hdr)
		return w2e_hdr->frame_ctrl;

	return hdr->frame_control;
}

__le16 cl_get_seq_ctrl(struct cl_hw *cl_hw, struct sk_buff *skb,
		       struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;

	if (w2e_hdr)
		return w2e_hdr->seq_ctrl;

	return hdr->seq_ctrl;
}

u8 *cl_get_qos_ctrl(struct cl_hw *cl_hw, struct sk_buff *skb,
		    struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;

	if (w2e_hdr)
		return (u8 *)&w2e_hdr->qos_ctrl;

	return ieee80211_get_qos_ctl(hdr);
}

u8 cl_get_tid(struct cl_hw *cl_hw, struct sk_buff *skb,
	      struct cl_rx_w2e_hdr *w2e_hdr)
{
	u8 *qc = cl_get_qos_ctrl(cl_hw, skb, w2e_hdr);

	return *qc & IEEE80211_QOS_CTL_TID_MASK;
}

u32 cl_get_ht_ctl(struct cl_hw *cl_hw,
		  struct sk_buff *skb,
		  struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_qos_htc_hdr
			*hdr = (struct ieee80211_qos_htc_hdr *)skb->data;

	if (w2e_hdr)
		return le32_to_cpu((__force __le32)w2e_hdr->optional[0]);

	return hdr->a_ctrl.u.value;
}

u8 cl_get_skb_ac(struct cl_hw *cl_hw, struct sk_buff *skb,
		 struct cl_rx_w2e_hdr *w2e_hdr)
{
	__le16 fc = cl_get_frame_ctrl(cl_hw, skb, w2e_hdr);

	if (ieee80211_is_data_qos(fc)) {
		u8 tid = cl_get_tid(cl_hw, skb, w2e_hdr);

		return cl_tid_to_ac(tid);
	}

	return AC_BE;
}

u8 *cl_get_da_addr(struct cl_hw *cl_hw, struct sk_buff *skb,
		   struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;

	if (w2e_hdr)
		return skb->data;

	return ieee80211_get_DA(hdr);
}

u8 *cl_get_sa_addr(struct cl_hw *cl_hw, struct sk_buff *skb,
		   struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;

	if (w2e_hdr)
		return &skb->data[ETH_ALEN];

	return ieee80211_get_SA(hdr);
}

bool cl_is_eapol(struct sk_buff *skb, struct cl_rx_w2e_hdr *w2e_hdr)
{
	struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
	__le16 fc = hdr->frame_control;
	unsigned int hdrlen = 0;
	u16 ethertype = 0;
	u8 *temp = NULL;

	/* Find the wireless header size */
	hdrlen = ieee80211_has_a4(fc) ? 30 : 24;

	if (ieee80211_is_data_qos(fc)) {
		hdrlen += IEEE80211_QOS_CTL_LEN;

		if (ieee80211_has_order(fc))
			hdrlen += IEEE80211_HT_CTL_LEN;
	}

	/* Skip wireless header */
	temp = (u8 *)(skb->data + hdrlen);

	/* Skip LLC and SNAP header */
	ethertype = (temp[6] << 8) | temp[7];

	return (ethertype == ETH_P_PAE);
}

