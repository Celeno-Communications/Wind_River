/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MSG_TX_H
#define CL_MSG_TX_H

#include "cl_hw.h"
#include "cl_vif.h"

#define FREQUENCY_INT_MASK 0xfffc
#define FREQUENCY_FRAC_MASK 0x0003
#define FREQUENCY_INT_SHIFT 2
#define FREQUENCY_FRAC_RESOLUTION 25

#define GET_FREQ_INT(freq) (((freq) & FREQUENCY_INT_MASK) >> FREQUENCY_INT_SHIFT)
#define GET_FREQ_FRAC(freq) (((freq) & FREQUENCY_FRAC_MASK) * FREQUENCY_FRAC_RESOLUTION)

enum ke_kern_tag {
	KERN_HOST,
	KERN_LMAC,
	KERN_UMAC,
	KERN_SMAC,

	KERN_MAX,
};

/*
 * confirmation call back params
 * @err: general msg transmitting error
 * @param: pointer to lower layer feedback param (FW layer)
 */
struct cl_msg_cfm_cb_param {
	int err;
	void *param; /* Pointer to msg cfm param, the caller should be aware to that type */
};

/*
 * call back function definition, associate with all backgrounf triggered messages
 * if caller intersting in message done feedback it must declare function of this type!
 */
typedef void (*cl_msg_cfm_cb_func)(struct cl_msg_cfm_cb_param *p_cfm_cb_param, u32 token);

void cl_msg_tx_free_cfm_params(struct cl_hw *cl_hw, u16 id);

int cl_msg_tx_reset(struct cl_hw *cl_hw);
int cl_msg_tx_start(struct cl_hw *cl_hw);
int cl_msg_tx_version(struct cl_hw *cl_hw);
int cl_msg_tx_add_if(struct cl_hw *cl_hw, struct ieee80211_vif *vif, u8 vif_index);
int cl_msg_tx_remove_if(struct cl_hw *cl_hw, u8 vif_index);
int cl_msg_tx_sta_add(struct cl_hw *cl_hw, struct ieee80211_sta *sta, struct cl_vif *cl_vif,
		      u8 recovery_sta_idx, u32 rate_ctrl_info);
int cl_msg_tx_sta_del(struct cl_hw *cl_hw, u8 sta_idx);
int cl_msg_tx_set_filter(struct cl_hw *cl_hw, u32 filter, bool force);
int cl_msg_tx_set_channel(struct cl_hw *cl_hw, u32 channel, u8 bw,
			  u32 primary, u32 center, s8 sx_freq_offset_mhz);
int cl_msg_tx_dtim(struct cl_hw *cl_hw, u8 dtim_period);
int cl_msg_tx_set_beacon_int(struct cl_hw *cl_hw, u16 beacon_int, u8 vif_idx);
int cl_msg_tx_set_basic_rates(struct cl_hw *cl_hw, u32 basic_rates);
int cl_msg_tx_set_bssid(struct cl_hw *cl_hw, const u8 *bssid, u8 vif_idx);
int cl_msg_tx_set_edca(struct cl_hw *cl_hw, u8 hw_queue, u32 param,
		       struct ieee80211_he_mu_edca_param_ac_rec *mu_edca);
int cl_msg_tx_set_associated(struct cl_hw *cl_hw,
			     struct ieee80211_bss_conf *bss_conf);
int cl_msg_tx_set_slottime(struct cl_hw *cl_hw, bool use_short_slot);
int cl_msg_tx_set_idle(struct cl_hw *cl_hw, u8 idle);
void cl_msg_tx_idle_async(struct cl_hw *cl_hw);
int cl_msg_tx_set_bss_color(struct cl_vif *cl_vif,
			    struct cfg80211_he_bss_color *he_bss_color);
int cl_msg_tx_key_add(struct cl_hw *cl_hw, struct ieee80211_vif *vif, struct ieee80211_sta *sta,
		      struct ieee80211_key_conf *key_conf, u8 cipher_suite);
int cl_msg_tx_key_del(struct cl_hw *cl_hw, u8 hw_key_idx);
int cl_msg_tx_ba_add(struct cl_hw *cl_hw, u8 type, u8 sta_idx, u16 tid, u16 bufsz, u16 ssn);
int cl_msg_tx_ba_del(struct cl_hw *cl_hw, u8 type, u8 sta_idx, u16 tid);
int cl_msg_tx_phy_reset(struct cl_hw *cl_hw);
int cl_msg_tx_available_ba_txq(struct cl_hw *cl_hw, u8 sta_idx, u16 tid);
int cl_msg_tx_update_rate_dl(struct cl_hw *cl_hw, u8 sta_idx, u32 rate, u32 rate_fallback,
			     u8 req_bw_tx, u8 op_mode, u8 gid, u8 ltf,
			     u8 ltf_fallback, u32 rate_he);
int cl_msg_tx_update_rate_ul(struct cl_hw *cl_hw, u8 sta_idx, u8 bw, u8 nss, u8 mcs, u8 gi_ltf);
int cl_msg_tx_set_vns(struct cl_hw *cl_hw, u8 sta_idx, u8 is_vns);
int cl_msg_tx_set_tx_bf(struct cl_hw *cl_hw, u8 sta_idx, u8 is_on, u8 is_on_fallback);
int cl_msg_tx_sounding(struct cl_hw *cl_hw,
		       struct mm_sounding_req *sounding_req);
int cl_msg_tx_sounding_pairing(struct cl_hw *cl_hw, u8 sounding_id, u8 sounding_type,
			       u8 gid, u8 sta_idx);
int cl_msg_tx_sounding_interval(struct cl_hw *cl_hw, u16 interval, u16 lifetime,
				u8 sounding_type, u8 sta_idx);
int cl_msg_tx_config_cca(struct cl_hw *cl_hw, u32 cca_src);
int cl_msg_tx_set_ant_bitmap(struct cl_hw *cl_hw, u8 bitmap);
int cl_msg_tx_ndp_tx_control(struct cl_hw *cl_hw, u8 chain_mask, u8 bw, u8 format, u8 num_ltf);
int cl_msg_tx_reg_write(struct cl_hw *cl_hw, u32 address, u32 value, u32 mask);
int cl_msg_tx_prot_mode(struct cl_hw *cl_hw, u8 log_nav_en, u8 mode,
			u8 rate_format, u8 rate_mcs, u8 rate_pre_type);
int cl_msg_tx_bw_signaling_mode(struct cl_hw *cl_hw, u8 mode);
int cl_msg_tx_goto_power_reduction(struct cl_hw *cl_hw, u8 mode);
int cl_msg_tx_backup_bcn_en(struct cl_hw *cl_hw, bool backup_bcn_en);
int cl_msg_tx_start_periodic_tx_time(struct cl_hw *cl_hw, u16 periodic_tx_time_off,
				     u16 periodic_tx_time_on);
int cl_msg_tx_anamon_read(struct cl_hw *cl_hw, u8 mode, u8 param1, u8 param2);
int cl_msg_tx_refresh_power(struct cl_hw *cl_hw);
int cl_msg_tx_set_ant_pwr_offset(struct cl_hw *cl_hw, s8 pwr_offset[MAX_ANTENNAS]);
int cl_msg_tx_set_rate_fallback(struct cl_hw *cl_hw);
int cl_msg_tx_twt_setup(struct cl_hw *cl_hw, struct mm_twt_setup_req *params);
int cl_msg_tx_twt_teardown(struct cl_hw *cl_hw, struct mm_twt_teardown_req *params);
int cl_msg_tx_tf(struct cl_hw *cl_hw, struct mm_tf_req *params);
#ifdef NATT_DBG
int cl_msg_tx_natt_test(struct cl_hw *cl_hw, struct natt_testing_param *params);
#endif

/* Debug messages */
int cl_msg_tx_dbg_set_mod_filter(struct cl_hw *cl_hw, u32 filter);
int cl_msg_tx_dbg_set_ce_mod_filter(struct cl_hw *cl_hw, u32 filter);
int cl_msg_tx_dbg_set_sev_filter(struct cl_hw *cl_hw, u32 filter);
int cl_msg_tx_dbg_beamforming_tx(struct cl_hw *cl_hw, u32 param32);
int cl_msg_tx_dbg_set_la_mpif_mask(struct cl_hw *cl_hw, u32 mask);
int cl_msg_tx_dbg_set_la_trig_point(struct cl_hw *cl_hw, u32 trigger_point);
int cl_msg_tx_dbg_set_la_mpif_debug_mode(struct cl_hw *cl_hw, u8 mode);
int cl_msg_tx_dbg_set_la_trig_rule(struct cl_hw *cl_hw, u8 idx, bool enable, u32 address,
				   u8 oper, u32 value, u32 mask, u32 duration);
int cl_msg_tx_dbg_tx_trace_debug_flag(struct cl_hw *cl_hw, u32 bitmap, u8 w_r_cmd);
int cl_msg_tx_dbg_print_stats(struct cl_hw *cl_hw, u32 command,
			      u32 param0, u32 param1, u32 param2, u32 param3);
int cl_msg_tx_dbg_trigger(struct cl_hw *cl_hw, char *msg);
int cl_msg_tx_dbg_test_mode(struct cl_hw *cl_hw, u32 *params);
int cl_msg_tx_dbg_sounding_cmd(struct cl_hw *cl_hw, struct dbg_sounding_cmd_param *params);
#ifdef PRESILICON_TESTING
int cl_msg_tx_dbg_presilicon_test(struct cl_hw *cl_hw, struct presilicon_testing_param *params);
#endif
int cl_msg_tx_set_calib(struct cl_hw *cl_hw, u32 primary,
			u32 center, struct cl_calib_params *calib_params);
int cl_msg_tx_matlab_response(struct cl_hw *cl_hw, struct mm_matlab_calib_res  *matlab_calib_res);
int cl_msg_tx_riu_loopback_config(struct cl_hw *cl_hw, u8 rx_chain_id, u8 tx_chain_idx, u8 bw);
#endif /* CL_MSG_TX_H */
