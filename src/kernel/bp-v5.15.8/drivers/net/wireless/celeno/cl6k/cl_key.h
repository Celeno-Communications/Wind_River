/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_KEY_H
#define CL_KEY_H

#include "cl_hw.h"

bool cl_key_has_pn_tsc(struct cl_hw *cl_hw, struct hw_rxhdr *rxhdr);
int cl_key_validate_pn_tsc(struct cl_hw *cl_hw, struct sk_buff *skb,
			   struct cl_sta *cl_sta, u8 tid,
			   struct hw_rxhdr *rxhdr);
int cl_key_set(struct cl_hw *cl_hw,
	       enum set_key_cmd cmd,
	       struct ieee80211_vif *vif,
	       struct ieee80211_sta *sta,
	       struct ieee80211_key_conf *key);
struct ieee80211_key_conf *cl_key_get(struct cl_sta *cl_sta);
bool cl_key_is_cipher_wep_or_wpa(struct ieee80211_key_conf *keyconf);
bool cl_key_is_cipher_ccmp_gcmp(struct ieee80211_key_conf *keyconf);
void cl_key_ccmp_gcmp_pn_to_hdr(u8 *hdr, u64 pn, int key_id);
u8 cl_key_get_cipher_len(struct sk_buff *skb);

#endif /* CL_KEY_H */
