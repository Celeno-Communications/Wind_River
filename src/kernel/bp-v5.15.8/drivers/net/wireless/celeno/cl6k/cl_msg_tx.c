// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "def.h"
#include "chip.h"
#include "cl_ipc.h"
#include "cl_tx.h"
#include "cl_rx.h"
#include "cl_msg_tx.h"
#include "cl_fw_msg.h"
#include "cl_temperature.h"
#include "cl_chan_info.h"
#include "cl_power.h"
#include "cl_env_det.h"
#include "cl_rx_sens.h"
#include "cl_rx_filter.h"
#include "cl_prot_mode.h"
#include "cl_rate_ctrl.h"
#include "cl_data_rates.h"
#include "cl_utils.h"
#include "cl_rfic.h"
#include "cl_calibration.h"
#include "cl_band.h"
#include "cl_recovery.h"
#include "cl_math.h"
#include "cl_agc_params.h"
#include "cl_mac_addr.h"
#include "cl_cap.h"
#include "cl_ampdu.h"
#include "cl_drv_ops.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif
#include "cl_calib_common_api.h"
#include "cl_calib_common_db.h"
#include "cl_calib_iq.h"
#include "usb.h"

#define DRV_TASK_ID 100

#define CL_DEF_ANT_BITMAP 0x55

/* No scale-down on ASIC platform */
#define CL_ASIC_FW_SCALEDOWN 1

struct cl_msg_tx_work {
	struct work_struct ws;

	/* Background message info */
	struct cl_hw *cl_hw;
	void *msg_params;
};

void cl_msg_tx_free_cfm_params(struct cl_hw *cl_hw, u16 id)
{
	/* Free message and set pointer to NULL */
	kfree(cl_hw->msg_cfm_params[id]);
	cl_hw->msg_cfm_params[id] = NULL;
}

static inline void *cl_msg_zalloc(struct cl_hw *cl_hw, u16 msg_id, u8 dst_task_id, u16 param_len)
{
	struct fw_msg *msg;
	u32 total_size = ALIGN(sizeof(struct fw_msg) + param_len, sizeof(u32));
	u32 max_size = sizeof(u32) * IPC_A2E_MSG_BUF_SIZE;

	if (total_size > max_size) {
		cl_dbg_err(cl_hw, "total size (%u) > max size (%u)\n",
			   total_size, max_size);
		return NULL;
	}

	/* msg is freed out of the scope of this function */
	msg = kzalloc(total_size, GFP_ATOMIC);

	if (!msg)
		return NULL;

	msg->msg_id = cpu_to_le16(msg_id);
	msg->dst_kern_id = KERN_LMAC;
	msg->dst_task_id = dst_task_id;
	msg->src_kern_id = KERN_HOST;
	msg->src_task_id = DRV_TASK_ID;
	msg->param_len = cpu_to_le16(param_len);

	return &msg->param[0];
}

static inline void cl_msg_free(const void *msg_param)
{
	kfree(container_of((void *)msg_param, struct fw_msg, param));
}

static void cl_send_msg_background_handler(struct work_struct *ws)
{
	struct cl_msg_tx_work *msg_tx_work = container_of(ws, struct cl_msg_tx_work, ws);

	cl_drv_ops_msg_fw_send(msg_tx_work->cl_hw, msg_tx_work->msg_params, true);
	kfree(msg_tx_work);
}

static int cl_send_msg_background(struct cl_hw *cl_hw,
				  const void *msg_params)
{
	/* Generate & populate the work struct wrapper for the background msg */
	struct cl_msg_tx_work *msg_tx_work = kzalloc(sizeof(*msg_tx_work), GFP_ATOMIC);

	if (msg_tx_work) {
		INIT_WORK(&msg_tx_work->ws, cl_send_msg_background_handler);
		msg_tx_work->cl_hw = cl_hw;
		msg_tx_work->msg_params = (void *)msg_params;

		/* Schedule work, the work will be executed in the background */
		queue_work(cl_hw->drv_workqueue, &msg_tx_work->ws);

		return 0;
	}

	cl_dbg_err(cl_hw, "msg_tx_work allocation failed\n");
	cl_msg_free(msg_params);

	return -ENODATA;
}

static int cl_send_request(struct cl_hw *cl_hw, const void *msg_params)
{
	int ret;
	bool background = (preempt_count() != 0);

	if (background) {
		/*
		 * asynchronous operation mode, message would be triggered in the background
		 */
		ret = cl_send_msg_background(cl_hw, msg_params);
	} else {
		/*
		 * synchronous operation mode, message would be triggered immediately
		 * feedback to caller given immediately
		 */
		ret = cl_drv_ops_msg_fw_send(cl_hw, msg_params, false);
	}

	/*
	 * In case of synchronous mode ret success implies that the msg was successfully
	 * transmited where is asynchronous mode ret success implies that the msg was
	 * successfully pushed to background queue
	 */
	return ret;
}

int cl_msg_tx_reset(struct cl_hw *cl_hw)
{
	void *void_param;

	/* RESET REQ has no parameter */
	void_param = cl_msg_zalloc(cl_hw, MM_RESET_REQ, TASK_MM, 0);

	if (!void_param)
		return -ENOMEM;

	return cl_send_request(cl_hw, void_param);
}

static void cl_fill_ant_config(struct cl_hw *cl_hw,
			       struct cl_antenna_config *ant_config,
			       u8 num_antennas, u8 mask_antennas,
			       u8 tx_mask_cck, u8 rx_mask_cck)
{
	if (cl_hw->chip->conf->ci_rx_ch_0_tx_ch_1_en) {
		ant_config->mask_tx_he = 0x2;
		ant_config->mask_tx_ofdm_ht_vht = 0x2;
		tx_mask_cck = 0x2;
		ant_config->mask_rx = 0x1;
		rx_mask_cck = 0x1;
	} else {
		ant_config->mask_tx_he = mask_antennas;
		ant_config->mask_tx_ofdm_ht_vht = mask_antennas;
		ant_config->mask_rx = mask_antennas;
	}

	ant_config->num_tx_he = num_antennas;
	ant_config->num_rx = num_antennas;
	ant_config->num_tx_ofdm_ht_vht = num_antennas;

	/* Antenna configuration for CCK */
	if (cl_band_is_24g(cl_hw)) {
		ant_config->mask_tx_cck = tx_mask_cck;
		ant_config->mask_rx_cck = rx_mask_cck;
	}

	ant_config->cdb_mask = 0;
}

int cl_msg_tx_start(struct cl_hw *cl_hw)
{
	struct mm_start_req *req;
	struct cl_phy_cfg *phy_cfg;
	struct cl_start_param *param;
	struct cl_cca_config *cca_config;
	struct dbg_meta_data *dbg_metadata;
	struct cl_tcv_conf *tcv_conf = cl_hw->conf;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *chip_conf = chip->conf;
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_chip_usb *chip_usb;
	u8 bw = 0, ant = 0;

	/* Build the START REQ message */
	req = cl_msg_zalloc(cl_hw, MM_START_REQ, TASK_MM, sizeof(struct mm_start_req));

	if (!req)
		return -ENOMEM;

	phy_cfg = &req->phy_cfg;
	param = &req->param;
	cca_config = &phy_cfg->cca_config;
	dbg_metadata = &param->dbg_metadata;

	/* Set parameters for the START message */
	phy_cfg->band = cl_band_to_fw_idx(cl_hw);
	phy_cfg->channel_bandwidth = cl_hw->conf->ce_channel_bandwidth;
	phy_cfg->cca_src = cpu_to_le32(tcv_conf->ci_cca_src);
	phy_cfg->ht_rxldpc_en = tcv_conf->ce_ht_rxldpc_en;
	if (chip->conf->ce_eeprom_en == E2P_MODE_ENABLED)
		phy_cfg->freq_offset = cpu_to_le16(chip->eeprom_cache->freq_offset);
	else
		phy_cfg->freq_offset = cpu_to_le16(chip->otp_cache->freq_offset);
	phy_cfg->vns_tx_power_mode = chip_conf->ce_production_mode ? 0 : tcv_conf->ci_vns_pwr_mode;
	phy_cfg->vns_rssi_suto_resp_th = tcv_conf->ci_vns_rssi_auto_resp_thr;
	phy_cfg->no_capture_noise_sleep = chip->conf->ci_no_capture_noise_sleep;
	phy_cfg->gain_update_enable = tcv_conf->ci_gain_update_enable;
	phy_cfg->mcs_sig_b = tcv_conf->ci_mcs_sig_b;
	phy_cfg->ofdm_only = tcv_conf->ci_ofdm_only;
	phy_cfg->hr_factor = tcv_conf->ci_hr_factor[phy_cfg->channel_bandwidth];
	phy_cfg->td_csd_en = tcv_conf->ci_csd_en;
	phy_cfg->pe_duration_bcast = tcv_conf->ci_pe_duration_bcast;
	phy_cfg->tx_digital_gain = cpu_to_le32(tcv_conf->ci_tx_digital_gain);
	phy_cfg->tx_dig_gain_single_ant = cpu_to_le32(tcv_conf->ci_tx_dig_gain_single_ant);
	phy_cfg->tx_dig_gain_all_ants = cpu_to_le32(tcv_conf->ci_tx_dig_gain_all_ants);
	phy_cfg->phy_clk_gating_en = tcv_conf->ci_phy_clk_gating_en;
	phy_cfg->iqdc_dpd_mode = tcv_conf->ci_iqdc_dpd_mode;
	phy_cfg->dsp_lcu_mode = tcv_conf->ci_dsp_lcu_mode;
	phy_cfg->twin_peak_mode = chip_conf->ci_twin_peak_mode;
	phy_cfg->rx_ch_0_tx_ch_1_en = chip_conf->ci_rx_ch_0_tx_ch_1_en;

	if (chip->eeprom_cache &&
	    chip->eeprom_cache->module_hw.module_hw_type == MODULE_HW_MODE_PYTHON_PEAK)
		phy_cfg->fem_conf.ext_fem_en = true;
	else
		phy_cfg->fem_conf.ext_fem_en = false;

	memcpy(phy_cfg->rx_sensitivity, cl_hw->rx_sensitivity, MAX_ANTENNAS);

	if (!cl_hw->fw_send_start) {
		cl_hw->fw_send_start = true;
		phy_cfg->first_start = true;
	}

	cl_fill_ant_config(cl_hw, &phy_cfg->ant_config,
			   cl_hw->num_antennas, ANT_MASK(cl_hw->num_antennas),
			   tcv_conf->ce_cck_tx_ant_mask, tcv_conf->ce_cck_rx_ant_mask);

	if (!chip->rf_reg_overwrite || cl_recovery_in_progress(cl_hw)) {
		chip->rf_reg_overwrite = true;
		cl_rfic_read_overwrite_file(cl_hw,
					    phy_cfg->rf_reg_overwrite_info,
					    true);
	}

	cca_config->ed_rise_thr_dbm = (u8)tcv_conf->ci_cca_ed_rise_thr_dbm;
	cca_config->ed_fall_thr_dbm = (u8)tcv_conf->ci_cca_ed_fall_thr_dbm;
	cca_config->cs_en = tcv_conf->ci_cca_cs_en;
	cca_config->modem_en = tcv_conf->ci_cca_modem_en;
	cca_config->main_ant = tcv_conf->ci_cca_main_ant;
	cca_config->second_ant = tcv_conf->ci_cca_second_ant;
	cca_config->flag0_ctrl = tcv_conf->ci_cca_flag0_ctrl;
	cca_config->flag1_ctrl = tcv_conf->ci_cca_flag1_ctrl;
	cca_config->flag2_ctrl = tcv_conf->ci_cca_flag2_ctrl;
	cca_config->flag3_ctrl = tcv_conf->ci_cca_flag3_ctrl;
	cca_config->gi_rise_thr_dbm = (u8)tcv_conf->ci_cca_gi_rise_thr_dbm;
	cca_config->gi_fall_thr_dbm = (u8)tcv_conf->ci_cca_gi_fall_thr_dbm;
	cca_config->gi_pow_lim_dbm = (u8)tcv_conf->ci_cca_gi_pow_lim_dbm;
	cca_config->ed_en = cpu_to_le16(tcv_conf->ci_cca_ed_en);
	cca_config->gi_en = tcv_conf->ci_cca_gi_en;

	param->trigger_base_en = tcv_conf->ci_trigger_base_en;
	param->prot_log_nav_en = tcv_conf->ce_prot_log_nav_en;
	param->prot_mode = cl_prot_mode_get(cl_hw);
	param->prot_rate_format = tcv_conf->ce_prot_rate_format;
	param->prot_rate_mcs = tcv_conf->ce_prot_rate_mcs;
	param->prot_rate_pre_type = tcv_conf->ce_prot_rate_pre_type;
	param->bw_signaling_mode = tcv_conf->ce_bw_signaling_mode;
	param->cfm_size = cpu_to_le16(IPC_CFM_SIZE);
	param->phy_dev = cpu_to_le16(chip_conf->ci_phy_dev);
	param->fw_scale_down = cpu_to_le16(CL_ASIC_FW_SCALEDOWN);
	param->hal_timeout.idle = cpu_to_le32(tcv_conf->ci_hal_idle_to);
	param->hal_timeout.ac0 = cpu_to_le32(tcv_conf->ci_tx_ac0_to);
	param->hal_timeout.ac1 = cpu_to_le32(tcv_conf->ci_tx_ac1_to);
	param->hal_timeout.ac2 = cpu_to_le32(tcv_conf->ci_tx_ac2_to);
	param->hal_timeout.ac3 = cpu_to_le32(tcv_conf->ci_tx_ac3_to);
	param->hal_timeout.bcn = cpu_to_le32(tcv_conf->ci_tx_bcn_to);
	param->pta_timeout_wifi = cpu_to_le32(cl_hw->chip->conf->ci_pta_wifi_to);
	param->pta_timeout_bt = cpu_to_le32(cl_hw->chip->conf->ci_pta_bt_to);
	param->pta_conc_allow_more_2g = cl_hw->chip->conf->ci_pta_conc_allow_more_2g;
	param->fw_reg_dbg = cl_hw->chip->conf->ci_fw_reg_dbg;
	param->rf_init_dis = cl_hw->chip->conf->ci_rf_init_dis;
	param->rf_calib_dis = cl_hw->chip->conf->ci_rf_calib_dis;
	param->bt_mode = cl_hw->chip->conf->ce_bt_mode;

	if (chip->conf->ce_bt_mode != BT_MODE_OFF) {
		param->rf_bt_init = cl_hw->chip->conf->ci_rf_bt_init;
		param->rf_bt_zero_if_en = cl_hw->chip->conf->ci_rf_bt_zero_if_en;
	}

	if (IS_PCI_BUS_TYPE(chip)) {
		param->cfm_dma_base_addr = cpu_to_le32(cl_hw->single_cfm_dma_base_addr);
		/* Update rxbuff/txqueue & ring_indices that hold the array metadata */
		param->ipc_ring_indices_base = cpu_to_le32(ipc_env->ring_indices_elem->dma_addr);
		param->host_rxbuf_base_addr[CL_RX_BUF_RXM] =
			ipc_env->rx_hostbuf_array[CL_RX_BUF_RXM].dma_payload_base_addr;
		param->host_rxbuf_base_addr[CL_RX_BUF_FW] =
			ipc_env->rx_hostbuf_array[CL_RX_BUF_FW].dma_payload_base_addr;
	}
	/*
	 * The FW needs to be aware of the DMA addresses of the
	 * TX queues so it could fetch txdesc from the host.
	 */
	param->host_tx_queues_addr = cpu_to_le32(cl_hw->ipc_tx_queues.dma_addr);
	param->host_txdesc_write_idx_addr = cpu_to_le32(cl_hw->ipc_write_idx.dma_addr);
	/*
	 * Compilation flags match check - please add here all compilation flags
	 * which should be compiled on both driver and firmware.
	 */
	param->comp_flags = cpu_to_le32(0)
		| cpu_to_le32(BIT(CENX_CFG_CE_TX_CFM))

#ifdef NATT_DBG
		| cpu_to_le32(BIT(CENX_NATT_DBG))
#endif
	;

	param->dbg_test_mode_max = cpu_to_le16(DBG_TEST_MODE_MAX);

	param->ipc_rxbuf_size[CL_RX_BUF_RXM] =
		cpu_to_le16(tcv_conf->ci_ipc_rxbuf_size[CL_RX_BUF_RXM]);
	param->ipc_rxbuf_size[CL_RX_BUF_FW] =
		cpu_to_le16(tcv_conf->ci_ipc_rxbuf_size[CL_RX_BUF_FW]);

	param->host_pci_gen_ver = chip_conf->ce_host_pci_gen_ver;
	param->dma_lli_max_chan[0] = chip_conf->ci_dma_lli_max_chan[0];
	param->dma_lli_max_chan[1] = chip_conf->ci_dma_lli_max_chan[1];
	param->production_mode = chip_conf->ce_production_mode;
	param->mult_ampdu_in_txop_en = tcv_conf->ci_mult_ampdu_in_txop_en;
	param->cca_timeout = cpu_to_le32(tcv_conf->ci_cca_timeout);
	param->long_retry_limit = tcv_conf->ce_long_retry_limit;
	param->short_retry_limit = tcv_conf->ce_short_retry_limit;
	param->assoc_auth_retry_limit = tcv_conf->ci_assoc_auth_retry_limit;
	param->bcn_tx_path_min_time = cpu_to_le16(tcv_conf->ce_bcn_tx_path_min_time);
	param->backup_bcn_en = tcv_conf->ci_backup_bcn_en;
	param->tx_txop_cut_en = tcv_conf->ce_tx_txop_cut_en;
	param->ac_with_bcns_flushed_cnt_thr = tcv_conf->ci_bcns_flushed_cnt_thr;
	param->txl_statistics_struct_size = cpu_to_le32(sizeof(struct cl_txl_statistics));
	param->rxl_statistics_struct_size = cpu_to_le32(sizeof(struct cl_rxl_statistics));
	param->phy_err_prevents_phy_dump = tcv_conf->ci_phy_err_prevents_phy_dump;
	param->tx_rx_delay = tcv_conf->ci_tx_rx_delay;
	param->assert_storm_detect_thd = tcv_conf->ci_fw_assert_storm_detect_thd;
	param->assert_time_diff_sec = tcv_conf->ci_fw_assert_time_diff_sec;
	param->ps_ctrl_enabled = tcv_conf->ce_ps_ctrl_enabled;
	param->phy_data_dma_addr = cpu_to_le32(cl_hw->phy_data_info.dma_addr);
	param->phy_remote_rom_dma_addr = cpu_to_le32(cl_hw->fw_remote_rom.dma_addr);
	param->power_table_dma_addr = cpu_to_le32(cl_hw->power_table_info.dma_addr);
	param->tf_info_dma_addr = cpu_to_le32(cl_hw->tf_info.dma_addr);
	param->bsr_info_dma_addr = cpu_to_le32(cl_hw->bsr_info.dma_addr);
	param->min_ant_pwr_q1 = cl_power_min_ant_q1(cl_hw);
	/* passing to the dma the destination addr */
	param->iq_dcoc_calib_tables_dma_addr = cpu_to_le32(cl_hw->iq_dcoc_data_info.dma_addr);

	for (bw = 0; bw < CHNL_BW_MAX; bw++) {
		cl_hw->power_db.bw_factor_q2[bw] = cl_power_bw_factor_q2(cl_hw, bw);
		param->bw_factor_q2[bw] =
			cl_convert_signed_to_reg_value(cl_hw->power_db.bw_factor_q2[bw]);
	}

	for (ant = 0; ant < MAX_ANTENNAS; ant++) {
		cl_hw->power_db.ant_factor_q2[ant] = cl_power_array_gain_q2(cl_hw, ant + 1);
		param->ant_factor_q2[ant] = cl_hw->power_db.ant_factor_q2[ant];
	}

	param->default_distance.auto_resp_all = 0;
	param->default_distance.auto_resp_msta = 0;
	param->su_force_min_spacing_usec = tcv_conf->ci_su_force_min_spacing;
	param->mu_force_min_spacing_usec = tcv_conf->ci_mu_force_min_spacing;
	param->rx_padding = tcv_conf->ci_rx_padding_en;
	param->bar_cap_disable = tcv_conf->ci_bar_disable;
	param->hw_bsr = tcv_conf->ci_hw_bsr;
	param->drop_to_lower_bw = tcv_conf->ci_drop_to_lower_bw;
	param->dra_enable = false; /* DRA enable only in CDB mode */
	param->mac_clk_gating_en = tcv_conf->ci_mac_clk_gating_en;
	param->imaging_blocker = tcv_conf->ci_imaging_blocker;
	param->fec_coding = tcv_conf->ce_he_rxldpc_en;
	param->cs_required = tcv_conf->ci_cs_required;
	memcpy(param->tx_usb_max_pdmas,
	       chip_conf->ci_tx_usb_max_pdmas, UMAC_TX_LLI_CH_MAX);
	param->offload_reorder_mode = tcv_conf->ci_offload_reorder_mode;
	param->usb_single_queue_for_agg_en = tcv_conf->ci_usb_single_queue_for_agg_en;

	if (IS_USB_BUS_TYPE(chip)) {
		chip_usb = cl_chip_usb_priv(chip);
		param->is_usb_3_super_speed = IS_USB_SUPER_SPEED(chip_usb);
	}
	dbg_metadata->lmac_req_buf_size = cpu_to_le32(sizeof(struct dbg_error_trace_info_drv));
	dbg_metadata->physical_queue_cnt = CL_MAX_BA_PHYSICAL_QUEUE_CNT;
	dbg_metadata->agg_index_max = AGG_IDX_MAX;
	dbg_metadata->ce_ac_max = CE_AC_MAX;
	dbg_metadata->mu_user_max = MU_MAX_STREAMS;
	dbg_metadata->txl_exch_trace_depth = DBG_TXL_FRAME_EXCH_TRACE_DEPTH;
	dbg_metadata->mac_hw_regs_max = cpu_to_le16(HAL_MACHW_REG_NUM);
	dbg_metadata->phy_hw_regs_max = cpu_to_le16(PHY_HW_DBG_REGS_CNT);
	dbg_metadata->thd_chains_data_size = cpu_to_le16(DBG_THD_CHAINS_INFO_ARRAY_SIZE);
	dbg_metadata->chains_info_elem_cnt = DBG_CHAINS_INFO_ELEM_CNT;
	dbg_metadata->la_conf_len = cpu_to_le16(LA_CONF_LEN);

	/* Send the START REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_version(struct cl_hw *cl_hw)
{
	void *void_param;

	/* VERSION REQ has no parameter */
	void_param = cl_msg_zalloc(cl_hw, MM_VERSION_REQ, TASK_MM, 0);

	if (!void_param)
		return -ENOMEM;

	return cl_send_request(cl_hw, void_param);
}

int cl_msg_tx_add_if(struct cl_hw *cl_hw, struct ieee80211_vif *vif,
		     u8 vif_index)
{
	struct mm_add_if_req *req;

	/* Build the ADD_IF_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_ADD_IF_REQ, TASK_MM, sizeof(struct mm_add_if_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the ADD_IF_REQ message */
	cl_mac_addr_copy(req->addr.array, vif->addr);

	switch (vif->type) {
	case NL80211_IFTYPE_STATION:
	case NL80211_IFTYPE_P2P_CLIENT:
		req->type = MM_STA;
		break;

	case NL80211_IFTYPE_ADHOC:
		req->type = MM_IBSS;
		break;

	case NL80211_IFTYPE_AP:
	case NL80211_IFTYPE_P2P_GO:
		req->type = MM_AP;
		break;

	case NL80211_IFTYPE_MONITOR:
		req->type = MM_MONITOR;
		break;

	case NL80211_IFTYPE_MESH_POINT:
		req->type = MM_MESH_POINT;
		break;

	default:
		req->type = MM_STA;
		break;
	}

	req->tx_strip_vlan = 1;
	req->mac_addr_hi_mask = cpu_to_le32(cl_hw->mask_hi);
	req->mac_addr_low_mask = cpu_to_le32(cl_hw->mask_low);
	req->inst_nbr = vif_index;

	if (vif->type == NL80211_IFTYPE_AP) {
		struct ieee80211_sub_if_data *sdata = vif_to_sdata(vif);
		struct ps_data *ps = &sdata->u.ap.ps;

		req->start_dtim_count = (u8)(ps->dtim_count);
	}

	/* Send the ADD_IF_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_remove_if(struct cl_hw *cl_hw, u8 vif_index)
{
	struct mm_remove_if_req *req;

	/* Build the MM_REMOVE_IF_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_REMOVE_IF_REQ, TASK_MM, sizeof(struct mm_remove_if_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_REMOVE_IF_REQ message */
	req->inst_nbr = vif_index;

	/* Send the MM_REMOVE_IF_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_sta_add(struct cl_hw *cl_hw, struct ieee80211_sta *sta,
		      struct cl_vif *cl_vif, u8 recovery_sta_idx,
		      u32 rate_ctrl_info)
{
	struct mm_sta_add_req *req;
	struct ieee80211_sta_ht_cap *ht_cap = &sta->ht_cap;
	struct ieee80211_sta_vht_cap *vht_cap = &sta->vht_cap;
	struct ieee80211_sta_he_cap *he_cap = &sta->he_cap;
	u16 my_aid = 0;
	u8 inst_nbr = cl_vif->vif_index;
	bool is_6g = cl_band_is_6g(cl_hw);
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(sta);

	/* Build the MM_STA_ADD_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_STA_ADD_REQ, TASK_MM,
			    sizeof(struct mm_sta_add_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_STA_ADD_REQ message */
	cl_mac_addr_copy(req->mac_addr.array, sta->addr);

	if (cl_vif->vif->type == NL80211_IFTYPE_STATION)
		my_aid = cl_vif->vif->bss_conf.aid;

	if (is_6g) {
		u8 mac_cap_info4 = he_cap->he_cap_elem.mac_cap_info[4];

		req->su_bfee = (mac_cap_info4 & IEEE80211_HE_PHY_CAP4_SU_BEAMFORMEE) ? 1 : 0;
		req->mu_bfee = (mac_cap_info4 & IEEE80211_HE_PHY_CAP4_MU_BEAMFORMER) ? 1 : 0;
	} else if (vht_cap->vht_supported) {
		req->su_bfee = (vht_cap->cap & IEEE80211_VHT_CAP_SU_BEAMFORMEE_CAPABLE) ? 1 : 0;
		req->mu_bfee = (vht_cap->cap & IEEE80211_VHT_CAP_MU_BEAMFORMEE_CAPABLE) ? 1 : 0;
	}

	req->ampdu_min_spacing = cl_sta->ampdu_min_spacing;

	if (he_cap->has_he) {
		u8 mac_cap_info1 = he_cap->he_cap_elem.mac_cap_info[1];
		u8 mac_cap_info3 = he_cap->he_cap_elem.mac_cap_info[3];

		req->he_tf_mac_padding_duration =
			u8_get_bits(mac_cap_info1, IEEE80211_HE_MAC_CAP1_TF_MAC_PAD_DUR_MASK);

		req->he_rx_ctrl_frm_to_mbss =
			(mac_cap_info3 & IEEE80211_HE_MAC_CAP3_RX_CTRL_FRAME_TO_MULTIBSS) ?
			true : false;

		/* Fill PE duration table */
		cl_cap_ppe_duration(cl_hw, sta, req->pe_duration);
	}

	cl_ampdu_size_exp(cl_hw, sta, &req->ampdu_size_exp_he,
			  &req->ampdu_size_exp_vht, &req->ampdu_size_exp_ht);

	if (cl_hw->conf->ce_txldpc_en) {
		if (he_cap->has_he)
			req->ldpc_enabled = (he_cap->he_cap_elem.phy_cap_info[1] &
					     IEEE80211_HE_PHY_CAP1_LDPC_CODING_IN_PAYLOAD) ? 1 : 0;
		else if (vht_cap->vht_supported)
			req->ldpc_enabled = (vht_cap->cap & IEEE80211_VHT_CAP_RXLDPC) ? 1 : 0;
		else if (ht_cap->ht_supported)
			req->ldpc_enabled = (ht_cap->cap & IEEE80211_HT_CAP_LDPC_CODING) ? 1 : 0;
	}

	req->inst_nbr = inst_nbr;

	req->aid = cpu_to_le16(sta->aid);
	req->my_aid = cpu_to_le16(my_aid);
	req->recovery_sta_idx = recovery_sta_idx;

	/* Station power save configuration */
	req->uapsd_queues = sta->uapsd_queues;
	req->max_sp = sta->max_sp;

	/* Set WRS default parameters for rate control */
	req->tx_params.rate = cpu_to_le32(rate_ctrl_info);

	/* Fill TX antenna with default value */
	req->tx_params.ant_set = CL_DEF_ANT_BITMAP;

	/* Send the MM_STA_ADD_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_sta_del(struct cl_hw *cl_hw, u8 sta_idx)
{
	struct mm_sta_del_req *req;

	/* Build the MM_STA_DEL_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_STA_DEL_REQ, TASK_MM, sizeof(struct mm_sta_del_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_STA_DEL_REQ message */
	req->sta_idx = sta_idx;
	req->sta_del_force_trig = cl_hw->sta_del_force_trig;

	/* Send the MM_STA_DEL_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_filter(struct cl_hw *cl_hw, u32 filter, bool force)
{
	struct mm_set_filter_req *req;
	u32 rx_filter = 0;

	if (force)
		rx_filter = filter;
	else
		rx_filter = cl_rx_filter_update_flags(cl_hw, filter);

	if (rx_filter == cl_hw->rx_filter) {
		cl_dbg_trace(cl_hw, "Rx filter 0x%x already set - return\n", rx_filter);
		return 0;
	}

	/* Build the MM_SET_FILTER_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_FILTER_REQ, TASK_MM, sizeof(struct mm_set_filter_req));

	if (!req)
		return -ENOMEM;

	/* Now copy all the flags into the message parameter */
	req->filter = cpu_to_le32(rx_filter);
	cl_hw->rx_filter = rx_filter;

	cl_dbg_trace(cl_hw, "new total_flags = 0x%08x\nrx filter set to  0x%08x\n",
		     filter, rx_filter);

	/* Send the MM_SET_FILTER_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

/*
 * Mark flags of calibration data to set during set channel
 * please notice: this function is not part of the calibration flow!
 */
static u8 cl_mark_calib_flags(struct cl_hw *cl_hw)
{
	int lna = 0;
	int chain = 0;
	u8 calib_info_set = 0;
	struct cl_iq_dcoc_info *iq_dcoc_db = &cl_hw->phy_data_info.data->iq_dcoc_db;

	/* Check if DCOC flag should be marked */
	for (lna = 0; lna < DCOC_LNA_GAIN_NUM; lna++) {
		riu_chain_for_each(chain) {
			if (iq_dcoc_db->dcoc[lna][chain].i || iq_dcoc_db->dcoc[lna][chain].q) {
				calib_info_set |= SET_PHY_DATA_FLAGS_DCOC;
				break;
			}
		}
	}
	/* Check if IQ Tx LOLC flag should be marked */
	riu_chain_for_each(chain) {
		if (iq_dcoc_db->iq_tx_lolc[chain]) {
			calib_info_set |= SET_PHY_DATA_FLAGS_IQ_TX_LOLC;
			break;
		}
	}
	/* Check if IQ Tx flag should be marked */
	riu_chain_for_each(chain) {
		if (iq_dcoc_db->iq_tx[chain].coef0 || iq_dcoc_db->iq_tx[chain].coef1 ||
		    iq_dcoc_db->iq_tx[chain].coef2 || iq_dcoc_db->iq_tx[chain].gain) {
			calib_info_set |= SET_PHY_DATA_FLAGS_IQ_TX;
			break;
		}
	}
	/* Check if IQ Rx flag should be marked */
	riu_chain_for_each(chain) {
		if (iq_dcoc_db->iq_rx[chain].coef0 || iq_dcoc_db->iq_rx[chain].coef1 ||
		    iq_dcoc_db->iq_rx[chain].coef2 || iq_dcoc_db->iq_rx[chain].gain) {
			calib_info_set |= SET_PHY_DATA_FLAGS_IQ_RX;
			return calib_info_set;
		}
	}

	return calib_info_set;
}

static int _cl_msg_tx_set_channel(struct cl_hw *cl_hw, u32 channel, u8 bw, u16 primary,
				  u16 center)
{
	struct mm_set_channel_req *req;
	int res = 0;
	struct cl_phy_data *data = cl_hw->phy_data_info.data;

	req = cl_msg_zalloc(cl_hw, MM_SET_CHANNEL_REQ, TASK_MM, sizeof(struct mm_set_channel_req));

	if (!req)
		return -ENOMEM;

	req->band = cl_band_to_fw_idx(cl_hw);
	req->bandwidth = bw;
	req->prim20_freq = cpu_to_le16(primary);

	/* set frequency */
	req->center1_freq_lut.frequency_q2 = cpu_to_le16(center);
	req->hr_factor = cl_hw->conf->ci_hr_factor[bw];
	req->signal_ext = cl_hw->conf->ci_signal_extension_en;

	/* Set power per mcs offset after EIRP truncation */
	cl_power_tables_update(cl_hw, &data->pwr_tables);

	/* Get antenna power offset from eeprom */
	cl_calibration_power_offset_fill(cl_hw, channel, bw, req->ant_pwr_offset);

	/* Fill Calibration Parameters from calib_db */
	cl_calib_common_fill_phy_data(cl_hw, &data->iq_dcoc_db, SET_PHY_DATA_FLAGS_ALL, false);
	req->calib_info_set = cl_mark_calib_flags(cl_hw);

	/* Fill AGC parameters */
	cl_agc_params_fill(cl_hw, &data->agc_params);

	/* Antenna configuration */
	cl_fill_ant_config(cl_hw, &req->ant_config,
			   cl_hw->num_antennas, ANT_MASK(cl_hw->num_antennas),
			   cl_hw->conf->ce_cck_tx_ant_mask, cl_hw->conf->ce_cck_rx_ant_mask);

	cl_rfic_read_overwrite_file(cl_hw, req->rf_reg_overwrite_info, false);

	res = cl_send_request(cl_hw, req);

	if (cl_hw->chip->conf->ce_eeprom_en == E2P_MODE_ENABLED)
		cl_temperature_comp_update_calib(cl_hw);

	cl_dbg_info(cl_hw,
		    "band=%u, channel=%u, bw=%u, primary=%u.%u, center=%u.%u, sx_index=%u\n",
		    cl_hw->conf->ci_band_num, channel, bw, GET_FREQ_INT(primary),
		    GET_FREQ_FRAC(primary), GET_FREQ_INT(center), GET_FREQ_FRAC(center),
		    cl_hw->tcv_idx);

	return res;
}

int cl_msg_tx_set_channel(struct cl_hw *cl_hw, u32 channel, u8 bw,
			  u32 primary, u32 center, s8 sx_freq_offset_mhz)
{
	int res = 0;
	u32 primary_q2 = FREQ_TO_Q2(primary);
	u32 center_q2 = FREQ_TO_Q2(center);

	/*
	 * Need to take mutex lock to ensure that no one touching the phy_data
	 * DMA before FW is reading all its values.
	 */
	res = mutex_lock_interruptible(&cl_hw->set_channel_mutex);

	if (res != 0) {
		cl_dbg_verbose(cl_hw, "Error - mutex_lock_interruptible (%d)\n", res);
		return res;
	}

	cl_hw->channel = channel;
	cl_hw->bw = bw;
	cl_hw->primary_freq = primary;
	cl_hw->center_freq = center;
	primary_q2 += sx_freq_offset_mhz;
	center_q2 += sx_freq_offset_mhz;
	res = _cl_msg_tx_set_channel(cl_hw, channel, bw, primary_q2, center_q2);

	mutex_unlock(&cl_hw->set_channel_mutex);

	return res;
}

int cl_msg_tx_dtim(struct cl_hw *cl_hw, u8 dtim_period)
{
	struct mm_set_dtim_req *req;

	/* Build the MM_SET_DTIM_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_DTIM_REQ, TASK_MM, sizeof(struct mm_set_dtim_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SET_DTIM_REQ message */
	req->dtim_period = dtim_period;

	/* Send the MM_SET_DTIM_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_beacon_int(struct cl_hw *cl_hw, u16 beacon_int, u8 vif_idx)
{
	struct mm_set_beacon_int_req *req;

	/* Build the MM_SET_BEACON_INT_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_BEACON_INT_REQ, TASK_MM,
			    sizeof(struct mm_set_beacon_int_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SET_BEACON_INT_REQ message */
	req->beacon_int = cpu_to_le16(beacon_int);
	req->inst_nbr = vif_idx;

	/* Send the MM_SET_BEACON_INT_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_basic_rates(struct cl_hw *cl_hw, u32 basic_rates)
{
	struct mm_set_basic_rates_req *req;

	/* Build the MM_SET_BASIC_RATES_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_BASIC_RATES_REQ, TASK_MM,
			    sizeof(struct mm_set_basic_rates_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SET_BASIC_RATES_REQ message */
	req->rates = cpu_to_le32(basic_rates);

	/* Send the MM_SET_BASIC_RATES_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_bssid(struct cl_hw *cl_hw, const u8 *bssid, u8 vif_idx)
{
	struct mm_set_bssid_req *req;

	/* Build the MM_SET_BSSID_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_BSSID_REQ, TASK_MM, sizeof(struct mm_set_bssid_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SET_BSSID_REQ message */
	cl_mac_addr_copy(req->bssid.array, bssid);
	req->inst_nbr = vif_idx;

	/* Send the MM_SET_BSSID_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_edca(struct cl_hw *cl_hw, u8 hw_queue, u32 param,
		       struct ieee80211_he_mu_edca_param_ac_rec *mu_edca)
{
	struct mm_set_edca_req *req;

	/* Build the MM_SET_EDCA_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_EDCA_REQ, TASK_MM, sizeof(struct mm_set_edca_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SET_EDCA_REQ message */
	req->ac_param = cpu_to_le32(param);
	req->hw_queue = hw_queue;

	if (mu_edca) {
		req->mu_edca_aifsn = mu_edca->aifsn;
		req->mu_edca_ecw_min_max = mu_edca->ecw_min_max;
		req->mu_edca_timer = mu_edca->mu_edca_timer;
	}

	/* Send the MM_SET_EDCA_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_associated(struct cl_hw *cl_hw,
			     struct ieee80211_bss_conf *bss_conf)
{
	struct mm_set_associated_req *req;

	/* Build the MM_SET_AID_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_ASSOCIATED_REQ, TASK_MM,
			    sizeof(struct mm_set_associated_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SET_ASSOCIATED_REQ message */
	req->aid = cpu_to_le16(bss_conf->aid);

	/* Multiple BSSID feature support */
	if (bss_conf->nontransmitted && bss_conf->assoc) {
		u8 i = 0;
		u8 mask_addr[ETH_ALEN] = {0};
		u32 bssid_hi_mask = 0;
		u32 bssid_low_mask = 0;

		for (i = 0; i < ETH_ALEN; i++)
			mask_addr[i] = (bss_conf->transmitter_bssid[i] ^
					bss_conf->bssid[i]);
		cl_mac_addr_array_to_nxmac(mask_addr, &bssid_low_mask,
					   &bssid_hi_mask);
		/* Set mask to allow the transmitter BSSID Rx reception */
		req->bssid_hi_mask = cpu_to_le32(bssid_hi_mask);
		req->bssid_low_mask = cpu_to_le32(bssid_low_mask);
	}
	/* Send the MM_SET_AID_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_slottime(struct cl_hw *cl_hw, bool use_short_slot)
{
	struct mm_set_slottime_req *req;

	/* Build the MM_SET_SLOTTIME_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_SLOTTIME_REQ, TASK_MM,
			    sizeof(struct mm_set_slottime_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SET_SLOTTIME_REQ message */
	req->slottime = use_short_slot ? 9 : 20;

	/* Send the MM_SET_SLOTTIME_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_idle(struct cl_hw *cl_hw, u8 idle)
{
	struct mm_set_idle_req *req;

	req = cl_msg_zalloc(cl_hw, MM_SET_IDLE_REQ, TASK_MM, sizeof(struct mm_set_idle_req));

	if (!req)
		return -ENOMEM;

	req->hw_idle = idle;

	cl_dbg_info(cl_hw, "idle = %s\n", idle ? "True" : "False");

	return cl_send_request(cl_hw, req);
}

void cl_msg_tx_idle_async(struct cl_hw *cl_hw)
{
	if (!IS_REAL_PHY(cl_hw->chip))
		return;

	cl_hw->idle_async_set = true;
	cl_msg_tx_set_idle(cl_hw, MAC_IDLE_ASYNC);
}

int cl_msg_tx_set_bss_color(struct cl_vif *cl_vif,
			    struct cfg80211_he_bss_color *he_bss_color)
{
	struct mm_set_bss_color_req *req;
	struct cl_hw *cl_hw = cl_vif->cl_hw;

	req = cl_msg_zalloc(cl_hw, MM_SET_BSS_COLOR_REQ, TASK_MM,
			    sizeof(struct mm_set_bss_color_req));

	if (!req)
		return -ENOMEM;

	req->vif_idx = cl_vif->vif_index;
	req->color = he_bss_color->color;
	req->disabled = !he_bss_color->enabled;
	req->partial = he_bss_color->partial;

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_key_add(struct cl_hw *cl_hw, struct ieee80211_vif *vif,
		      struct ieee80211_sta *sta,
		      struct ieee80211_key_conf *key_conf,
		      u8 cipher_suite)
{
	struct mm_key_add_req *req;

	/* Build the MM_KEY_ADD_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_KEY_ADD_REQ, TASK_MM, sizeof(struct mm_key_add_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_KEY_ADD_REQ message */
	if (sta) {
		/* Pairwise key */
		req->sta_idx = ((struct cl_sta *)sta->drv_priv)->sta_idx;
	} else {
		/* Default key */
		req->sta_idx = 0xFF;
		req->key_idx = (u8)(key_conf->keyidx); /* Only useful for default keys */
	}

	req->inst_nbr = ((struct cl_vif *)vif->drv_priv)->vif_index;
	req->key.length = key_conf->keylen;

	memcpy(req->key.array, key_conf->key, key_conf->keylen);

	req->cipher_suite = cipher_suite;
	req->spp = cl_hw->conf->ci_spp_ksr_value;

	cl_dbg_info(cl_hw, "sta_idx:%u, key_idx:%u, inst_nbr:%u, cipher:%u, key_len:%u, spp:%u\n",
		    req->sta_idx, req->key_idx, req->inst_nbr,
		    req->cipher_suite, req->key.length, req->spp);

	/* Send the MM_KEY_ADD_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_key_del(struct cl_hw *cl_hw, u8 hw_key_idx)
{
	struct mm_key_del_req *req;

	/* Build the MM_KEY_DEL_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_KEY_DEL_REQ, TASK_MM, sizeof(struct mm_key_del_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_KEY_DEL_REQ message */
	req->hw_key_idx = hw_key_idx;

	/* Send the MM_KEY_DEL_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_ba_add(struct cl_hw *cl_hw, u8 type, u8 sta_idx,
		     u16 tid, u16 bufsz, u16 ssn)
{
	struct mm_ba_add_req *req;
	u16 msg_id = ((type == BA_AGMT_TX) ? MM_BA_ADD_TX_REQ : MM_BA_ADD_RX_REQ);

	/* Build the MM_BA_ADD_REQ message */
	req = cl_msg_zalloc(cl_hw, msg_id, TASK_MM, sizeof(struct mm_ba_add_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_BA_ADD_REQ message */
	req->type = type;
	req->sta_idx = sta_idx;
	req->tid = (u8)tid;
	req->bufsz = cpu_to_le16(bufsz);
	req->ssn = cpu_to_le16(ssn);

	/* Send the MM_BA_ADD_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_ba_del(struct cl_hw *cl_hw, u8 type, u8 sta_idx, u16 tid)
{
	struct mm_ba_del_req *req;

	/* Build the MM_BA_DEL_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_BA_DEL_REQ, TASK_MM, sizeof(struct mm_ba_del_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters */
	req->type = type;
	req->sta_idx = sta_idx;
	req->tid = (u8)tid;

	/* Send the MM_BA_DEL_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_phy_reset(struct cl_hw *cl_hw)
{
	struct mm_phy_reset_req *req;

	/* Build the PHY RESET REQ message */
	req = cl_msg_zalloc(cl_hw, MM_PHY_RESET_REQ, TASK_MM, sizeof(struct mm_phy_reset_req));
	if (!req)
		return -ENOMEM;

	/* Send the PHY RESET REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_available_ba_txq(struct cl_hw *cl_hw, u8 sta_idx, u16 tid)
{
	struct mm_available_ba_txq_req *req;

	/* Build the MM_BA_ADD_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_AVAILABLE_BA_TXQ_REQ, TASK_MM,
			    sizeof(struct mm_available_ba_txq_req));

	if (!req)
		return -ENOMEM;

	req->sta_idx = sta_idx;
	req->tid = (u8)tid;

	/* Send the MM_BA_TXQUEUE_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_update_rate_dl(struct cl_hw *cl_hw, u8 sta_idx, u32 rate, u32 rate_fallback,
			     u8 req_bw_tx, u8 op_mode, u8 gid, u8 ltf,
			     u8 ltf_fallback, u32 rate_he)
{
	struct mm_update_rate_dl_req *req;
	union cl_rate_ctrl_info rate_ctrl_info;
	u8 nss, mcs;
	u16 phy_rate;

	cl_dbg_info(cl_hw, "sta_idx=%u, rate=0x%x, rate_fallback=0x%x, req_bw_tx=%u, "
		    "op_mode=%u, gid=%u, ltf=%u, ltf_fallback=%u, rate_he=0x%x\n",
		    sta_idx, rate, rate_fallback, req_bw_tx, op_mode, gid,
		    ltf, ltf_fallback, rate_he);

	/* Build the MM_UPDATE_RATE_DL_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_UPDATE_RATE_DL_REQ, TASK_MM,
			    sizeof(struct mm_update_rate_dl_req));

	if (!req)
		return -ENOMEM;

	/* Populate tx_params */
	req->tx_params.rate = cpu_to_le32(rate);
	req->tx_params.rate_he = cpu_to_le32(rate_he);
	req->tx_params.req_bw_tx = req_bw_tx;
	req->tx_params.ant_set = CL_DEF_ANT_BITMAP;
	req->tx_params.ltf = ltf;

	req->op_mode = op_mode;
	req->sta_idx = sta_idx;
	req->rate_fallback = cpu_to_le32(rate_fallback);
	req->ltf_fallback = ltf_fallback;

	rate_ctrl_info.word = rate;
	cl_rate_ctrl_convert(&rate_ctrl_info);
	cl_rate_ctrl_parse(&rate_ctrl_info, &nss, &mcs);
	phy_rate = cl_data_rates_get(rate_ctrl_info.field.format_mod,
				     req_bw_tx,
				     nss,
				     mcs,
				     rate_ctrl_info.field.gi);
	req->tx_phy_rate = cpu_to_le16(phy_rate);

	/* Gid & mu valid bit is relevant only for MU rate updates. */
	if (op_mode == RATE_OP_MODE_STA_MU) {
		req->group_id = gid;
		req->mu_is_rate_valid = false;
	}

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_update_rate_ul(struct cl_hw *cl_hw, u8 sta_idx, u8 bw, u8 nss, u8 mcs, u8 gi_ltf)
{
	struct mm_update_rate_ul_req *req;

	/* Build the MM_UPDATE_RATE_UL_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_UPDATE_RATE_UL_REQ, TASK_MM,
			    sizeof(struct mm_update_rate_ul_req));

	if (!req)
		return -ENOMEM;

	req->sta_idx = sta_idx;
	req->bw = bw;
	req->nss = nss;
	req->mcs = mcs;
	req->gi_ltf = gi_ltf;

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_vns(struct cl_hw *cl_hw, u8 sta_idx, u8 is_vns)
{
	struct mm_set_vns_req *req;

	/* Build the VNS message */
	req = cl_msg_zalloc(cl_hw, MM_SET_VNS_REQ, TASK_MM, sizeof(struct mm_set_vns_req));

	if (!req)
		return -ENOMEM;

	req->sta_idx = sta_idx;
	req->is_vns = is_vns;

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_tx_bf(struct cl_hw *cl_hw, u8 sta_idx, u8 is_on, u8 is_on_fallback)
{
	struct mm_set_tx_bf_req *req;

	/* Build the TX-BF message */
	req = cl_msg_zalloc(cl_hw, MM_SET_TX_BF_REQ, TASK_MM, sizeof(struct mm_set_vns_req));

	if (!req)
		return -ENOMEM;

	req->sta_idx = sta_idx;
	req->is_on = is_on;
	req->is_on_fallback = is_on_fallback;

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_sounding(struct cl_hw *cl_hw,
		       struct mm_sounding_req *sounding_req)
{
	struct mm_sounding_req *req;
	u8 i;

	req = cl_msg_zalloc(cl_hw, MM_SOUNDING_REQ, TASK_MM, sizeof(struct mm_sounding_req));

	if (!req)
		return -ENOMEM;

	/* Populate mm_sounding_req */
	memcpy(req, sounding_req, sizeof(struct mm_sounding_req));

	/* In case of non-TB HE SU/CQI, nc should be set to 0 */
	if (req->sounding_type == SOUNDING_TYPE_HE_CQI ||
	    req->sounding_type == SOUNDING_TYPE_HE_SU)
		for (i = 0; i < req->sta_num; i++)
			req->info_per_sta[i].nc = 0;

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_sounding_pairing(struct cl_hw *cl_hw, u8 sounding_id, u8 sounding_type,
			       u8 gid, u8 sta_idx)
{
	struct mm_sounding_pairing *req;

	req = cl_msg_zalloc(cl_hw, MM_SOUNDING_PAIRING_REQ, TASK_MM,
			    sizeof(struct mm_sounding_pairing));

	if (!req)
		return -ENOMEM;

	req->sounding_type = sounding_type;
	req->sta_idx = sta_idx;
	req->gid = gid;
	req->sounding_id = sounding_id;

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_sounding_interval(struct cl_hw *cl_hw, u16 interval, u16 lifetime,
				u8 sounding_type, u8 sta_idx)
{
	struct mm_sounding_interval_req *req;

	req = cl_msg_zalloc(cl_hw, MM_SOUNDING_INTERVAL_REQ, TASK_MM,
			    sizeof(struct mm_sounding_interval_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SOUNDING_INTERVAL_REQ message */
	req->interval = cpu_to_le16(interval);
	req->bfr_lifetime = cpu_to_le16(lifetime);
	req->sounding_type = sounding_type;
	req->sta_idx = sta_idx;

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_config_cca(struct cl_hw *cl_hw, u32 cca_src)
{
	struct mm_config_cca_req *req;

	/* Build the MM_CONFIG_CCA_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_CONFIG_CCA_REQ, TASK_MM, sizeof(struct mm_config_cca_req));
	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_CONFIG_CCA_REQ message */
	req->sources = cpu_to_le32(cca_src);

	/* Send the MM_CONFIG_CCA_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_ant_bitmap(struct cl_hw *cl_hw, u8 bitmap)
{
	struct mm_set_ant_bitmap_req *req;
	u8 num_antennas = hweight8(bitmap);
	u8 bitmap_cck = cl_band_is_24g(cl_hw) ? bitmap : 0;

	/* Build the MM_SET_ANT_BITMAP_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_ANT_BITMAP_REQ, TASK_MM,
			    sizeof(struct mm_set_ant_bitmap_req));

	if (!req)
		return -ENOMEM;

	cl_fill_ant_config(cl_hw, &req->ant_config, num_antennas, bitmap, bitmap_cck, bitmap_cck);

	/* Send the MM_SET_ANT_BITMAP_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_ndp_tx_control(struct cl_hw *cl_hw, u8 chain_mask, u8 bw, u8 format, u8 num_ltf)
{
	struct mm_ndp_tx_control_req *req;

	/* Build the MM_NDP_TX_CONTROL_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_NDP_TX_CONTROL_REQ, TASK_MM,
			    sizeof(struct mm_ndp_tx_control_req));

	if (!req)
		return -ENOMEM;

	req->chain_mask = chain_mask;
	req->bw = bw;
	req->format = format;
	req->num_ltf = num_ltf;

	/* Send the MM_NDP_TX_CONTROL_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_reg_write(struct cl_hw *cl_hw, u32 address, u32 value, u32 mask)
{
	struct mm_reg_write_req *req;

	/* Build the MM_REG_WRITE_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_REG_WRITE_REQ, TASK_MM, sizeof(struct mm_reg_write_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_REG_WRITE_REQ message */
	req->address = cpu_to_le32(address);
	req->value = cpu_to_le32(value);
	req->mask = cpu_to_le32(mask);

	cl_dbg_info(cl_hw, "address=0x%x, value=0x%x, mask=0x%x\n", address, value, mask);

	/* Send the MM_REG_WRITE_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_prot_mode(struct cl_hw *cl_hw, u8 log_nav_en, u8 mode, u8 rate_format,
			u8 rate_mcs, u8 rate_pre_type)
{
	struct mm_prot_mode_req *req;

	/* Build the MM_PROT_MODE_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_PROT_MODE_REQ, TASK_MM, sizeof(struct mm_prot_mode_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_PROT_MODE_REQ message */
	req->log_nav_en = log_nav_en;
	req->mode = mode;
	req->rate_format = rate_format;
	req->rate_mcs = rate_mcs;
	req->rate_pre_type = rate_pre_type;

	/* Send the MM_PROT_MODE_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_bw_signaling_mode(struct cl_hw *cl_hw, u8 mode)
{
	struct mm_bw_signaling_mode_req *req;

	req = cl_msg_zalloc(cl_hw, MM_BW_SIGNALING_MODE_REQ, TASK_MM,
			    sizeof(struct mm_bw_signaling_mode_req));
	if (!req)
		return -ENOMEM;

	req->mode = mode;
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_goto_power_reduction(struct cl_hw *cl_hw, u8 mode)
{
	struct mm_goto_power_reduction_req *req;

	/* Build the MM_POWER REDUCTION_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_GOTO_POWER_REDUCTION_REQ, TASK_MM,
			    sizeof(struct mm_goto_power_reduction_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_POWER REDUCTION_REQ message */
	req->goto_power_reduction_mode = mode;

	/* Send the MM_POWER REDUCTION_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_backup_bcn_en(struct cl_hw *cl_hw, bool backup_bcn_en)
{
	struct mm_set_backup_bcn_en_req *req;

	/* Build the MM_BACKUP_BCN_EN_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_BACKUP_BCN_EN_REQ, TASK_MM,
			    sizeof(struct mm_set_backup_bcn_en_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_BACKUP_BCN_EN_REQ message */
	req->backup_bcn_en = backup_bcn_en;

	/* Send the MM_BACKUP_BCN_EN_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_start_periodic_tx_time(struct cl_hw *cl_hw, u16 periodic_tx_time_off,
				     u16 periodic_tx_time_on)
{
	struct mm_start_periodic_tx_time_req *req;

	/* Build the MM_START_PERIODIC_TX_TIME_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_START_PERIODIC_TX_TIME_REQ, TASK_MM,
			    sizeof(struct mm_start_periodic_tx_time_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_START_PERIODIC_TX_TIME_REQ message */
	req->periodic_tx_time_off = cpu_to_le16(periodic_tx_time_off);
	req->periodic_tx_time_on = cpu_to_le16(periodic_tx_time_on);

	/* Send the MM_START_PERIODIC_TX_TIME_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_anamon_read(struct cl_hw *cl_hw, u8 mode, u8 param1, u8 param2)
{
	struct mm_anamon_read_req *req;

	/* Build the MM_ANAMON_READ_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_ANAMON_READ_REQ, TASK_MM, sizeof(struct mm_anamon_read_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_ANAMON_READ_REQ message */
	req->mode = mode;
	req->param1 = param1;
	req->param2 = param2;

	/* Send the MM_ANAMON_READ_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_refresh_power(struct cl_hw *cl_hw)
{
	void *void_param;

	/* MM_REFRESH_PWR_REQ has no parameter */
	void_param = cl_msg_zalloc(cl_hw, MM_REFRESH_PWR_REQ, TASK_MM, 0);

	if (!void_param)
		return -ENOMEM;

	return cl_send_request(cl_hw, void_param);
}

int cl_msg_tx_set_ant_pwr_offset(struct cl_hw *cl_hw, s8 pwr_offset[MAX_ANTENNAS])
{
	struct mm_set_ant_pwr_offset_req *req;
	u8 i = 0;

	/* Build the MM_SET_ANT_PWR_OFFSET_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_ANT_PWR_OFFSET_REQ, TASK_MM,
			    sizeof(struct mm_set_ant_pwr_offset_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_SET_ANT_PWR_OFFSET_REQ message */
	for (i = 0; i < MAX_ANTENNAS; i++) {
		pwr_offset[i] = cl_power_offset_check_margin(cl_hw, cl_hw->bw, i, pwr_offset[i]);
		req->pwr_offset[i] = cl_convert_signed_to_reg_value(pwr_offset[i]);
	}

	/* Send the MM_SET_ANT_PWR_OFFSET_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_set_rate_fallback(struct cl_hw *cl_hw)
{
	struct mm_rate_fallback_req *req;
	struct cl_tcv_conf *conf = cl_hw->conf;

	/* Build the MM_SET_RATE_FALLBACK_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_SET_RATE_FALLBACK_REQ, TASK_MM,
			    sizeof(struct mm_rate_fallback_req));

	if (!req)
		return -ENOMEM;

	req->fallback_count_su = conf->ci_rate_fallback[CL_RATE_FALLBACK_COUNT_SU];
	req->fallback_count_mu = conf->ci_rate_fallback[CL_RATE_FALLBACK_COUNT_MU];
	req->retry_count_thr = conf->ci_rate_fallback[CL_RATE_FALLBACK_RETRY_COUNT_THR];
	req->ba_per_thr = conf->ci_rate_fallback[CL_RATE_FALLBACK_BA_PER_THR];
	req->ba_not_received_thr = conf->ci_rate_fallback[CL_RATE_FALLBACK_BA_NOT_RECEIVED_THR];
	req->disable_mcs0 = conf->ci_rate_fallback[CL_RATE_FALLBACK_DISABLE_MCS];

	/* Send the MM_SET_RATE_FALLBACK_REQ message */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_twt_setup(struct cl_hw *cl_hw, struct mm_twt_setup_req *params)
{
	struct mm_twt_setup_req *req;

	/* Build the MM_SET_RATE_FALLBACK_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_TWT_SETUP_REQ, TASK_MM, sizeof(struct mm_twt_setup_req));

	if (!req)
		return -ENOMEM;

	req->sta_idx = params->sta_idx;
	req->twt_flow_id = params->twt_flow_id;
	req->announced = params->announced;
	req->triggered = params->triggered;
	req->min_wake_duration_us = params->min_wake_duration_us;
	req->twt_interval_us = params->twt_interval_us;
	req->twt_start_time_tsf = params->twt_start_time_tsf;

	cl_dbg_info(cl_hw,
		    "sta_idx %u, flow_id %u, interval_us %llu, min_wake_duration_us %u,"
		    "start_time %llu, announced %u, triggered %u\n",
		    req->sta_idx, req->twt_flow_id, req->twt_interval_us,
		    req->min_wake_duration_us, req->twt_start_time_tsf,
		    req->announced, req->triggered);

	/* Send the message */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_twt_teardown(struct cl_hw *cl_hw, struct mm_twt_teardown_req *params)
{
	struct mm_twt_teardown_req *req;

	/* Build the MM_SET_RATE_FALLBACK_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_TWT_TEARDOWN_REQ, TASK_MM,
			    sizeof(struct mm_twt_teardown_req));

	if (!req)
		return -ENOMEM;

	req->sta_idx = params->sta_idx;
	req->twt_flow_id = params->twt_flow_id;

	cl_dbg_info(cl_hw, "sta_idx %u, flow_id %u\n",
		    req->sta_idx, req->twt_flow_id);

	/* Send the message */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_tf(struct cl_hw *cl_hw, struct mm_tf_req *params)
{
	struct mm_tf_req *req;

	/* Build the MM_TF_REQ message */
	req = cl_msg_zalloc(cl_hw, MM_TF_REQ, TASK_MM, sizeof(struct mm_tf_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_TF_REQ message */
	memcpy(req, params, sizeof(struct mm_tf_req));

	/* Send the MM_TF_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

#ifdef NATT_DBG
int cl_msg_tx_natt_test(struct cl_hw *cl_hw, struct natt_testing_param *params)
{
	struct cl_natt_test_req *req;

	/* Build the MM_NATT_TESTING_REQ message */
	req = cl_msg_zalloc(MM_NATT_TESTING_REQ, TASK_MM, DRV_TASK_ID,
			    sizeof(struct cl_natt_test_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_NATT_TESTING_REQ message */
	req->max_num_valid_mpdu = cpu_to_le32(params->max_num_valid_mpdu);
	req->non_valid_mpdu_rate = cpu_to_le32(params->non_valid_mpdu_rate);
	req->force_min_spacing_mode = cpu_to_le32(params->force_min_spacing_mode);
	req->min_spacing = cpu_to_le32(params->min_spacing);
	req->non_data1_len = cpu_to_le32(params->non_data1_len);
	req->non_data1_num = cpu_to_le32(params->non_data1_num);
	req->non_data1_padding = cpu_to_le32(params->non_data1_padding);
	req->non_data2_len = cpu_to_le32(params->non_data2_len);
	req->non_data2_num = cpu_to_le32(params->non_data2_num);
	req->non_data2_padding = cpu_to_le32(params->non_data2_padding);
	req->airtime_limit = cpu_to_le32(params->airtime_limit);
	req->last_desc_set = cpu_to_le32(params->last_desc_set);

	/* Send the MM_NATT_TESTING_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}
#endif /* NATT_DBG */

int cl_msg_tx_dbg_set_mod_filter(struct cl_hw *cl_hw, u32 filter)
{
	struct dbg_set_mod_filter_req *req;

	/* Build the DBG_SET_MOD_FILTER_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_SET_MOD_FILTER_REQ, TASK_DBG,
			    sizeof(struct dbg_set_mod_filter_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the DBG_SET_MOD_FILTER_REQ message */
	req->mod_filter = cpu_to_le32(filter);

	/* Send the DBG_SET_MOD_FILTER_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_set_ce_mod_filter(struct cl_hw *cl_hw, u32 filter)
{
	struct dbg_set_mod_filter_req *req;

	/* Build the DBG_CE_SET_MOD_FILTER_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_CE_SET_MOD_FILTER_REQ, TASK_DBG,
			    sizeof(struct dbg_set_mod_filter_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the DBG_SET_MOD_FILTER_REQ message */
	req->mod_filter = cpu_to_le32(filter);

	/* Send the DBG_CE_SET_MOD_FILTER_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_set_sev_filter(struct cl_hw *cl_hw, u32 filter)
{
	struct dbg_set_sev_filter_req *req;

	/* Build the DBG_SET_SEV_FILTER_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_SET_SEV_FILTER_REQ, TASK_DBG,
			    sizeof(struct dbg_set_sev_filter_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the DBG_SET_SEV_FILTER_REQ message */
	req->sev_filter = cpu_to_le32(filter);

	/* Send the DBG_SET_SEV_FILTER_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_beamforming_tx(struct cl_hw *cl_hw, u32 param32)
{
	struct dbg_beamforming_tx_req *req;

	/* Build the DBG_BEAMFORM_TX_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_BEAMFORMING_TX_REQ, TASK_DBG,
			    sizeof(struct dbg_beamforming_tx_req));

	if (!req)
		return -ENOMEM;

	req->bf_cmd = cpu_to_le32(param32);

	/* Send the message */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_set_la_mpif_mask(struct cl_hw *cl_hw, u32 mask)
{
	struct dbg_set_la_mpif_mask_req *req;

	/* Build the DBG_SET_LA_MPIF_MASK_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_SET_LA_MPIF_MASK_REQ, TASK_DBG,
			    sizeof(struct dbg_set_la_mpif_mask_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the DBG_SET_LA_MPIF_MASK_REQ message */
	req->mpif_mask = cpu_to_le32(mask);

	/* Send the DBG_SET_LA_MPIF_MASK_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_set_la_trig_point(struct cl_hw *cl_hw, u32 trigger_point)
{
	struct dbg_set_la_trig_point_req *req;

	/* Build the DBG_SET_LA_TRIG_POINT_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_SET_LA_TRIG_POINT_REQ, TASK_DBG,
			    sizeof(struct dbg_set_la_trig_point_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the DBG_SET_LA_TRIG_POINT_REQ message */
	req->trigger_point = cpu_to_le32(trigger_point);

	/* Send the DBG_SET_LA_TRIG_POINT_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_set_la_mpif_debug_mode(struct cl_hw *cl_hw, u8 mode)
{
	struct dbg_set_la_mpif_debug_mode_req *req;

	/* Build the DBG_SET_LA_MPIF_DEBUG_MODE_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_SET_LA_MPIF_DEBUG_MODE_REQ, TASK_DBG,
			    sizeof(struct dbg_set_la_mpif_debug_mode_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the DBG_SET_LA_MPIF_DEBUG_MODE_REQ message */
	req->mode = mode;

	/* Send the DBG_SET_LA_MPIF_DEBUG_MODE_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_set_la_trig_rule(struct cl_hw *cl_hw, u8 idx, bool enable, u32 address,
				   u8 oper, u32 value, u32 mask, u32 duration)
{
	struct dbg_set_la_trig_rule_req *req;

	req = cl_msg_zalloc(cl_hw, DBG_SET_LA_TRIG_RULE_REQ, TASK_DBG,
			    sizeof(struct dbg_set_la_trig_rule_req));

	if (!req)
		return -ENOMEM;

	req->rule_id = idx;
	req->oper = oper;
	req->enable = enable;
	req->address = cpu_to_le32(address);
	req->value = cpu_to_le32(value);
	req->mask = cpu_to_le32(mask);
	req->duration = cpu_to_le32(duration);

	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_tx_trace_debug_flag(struct cl_hw *cl_hw, u32 bitmap, u8 w_r_cmd)
{
	struct dbg_tx_trace_debug_flag_req *req;

	/* Build the DBG_TX_TRACE_DEBUG_FLAG_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_TX_TRACE_DEBUG_FLAG_REQ, TASK_DBG,
			    sizeof(struct dbg_tx_trace_debug_flag_req));

	if (!req)
		return -ENOMEM;

	req->read_write_flag = w_r_cmd;
	req->bitmap = cpu_to_le32(bitmap);

	/* Send the DBG_TX_TRACE_DEBUG_FLAG_REQ message */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_print_stats(struct cl_hw *cl_hw, u32 command,
			      u32 param0, u32 param1, u32 param2, u32 param3)
{
	struct dbg_print_stats_req *req;

	/* Build the DBG_PRINT_STATS_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_PRINT_STATS_REQ, TASK_DBG,
			    sizeof(struct dbg_print_stats_req));

	if (!req)
		return -ENOMEM;

	req->command = cpu_to_le32(command);
	req->param[0] = cpu_to_le32(param0);
	req->param[1] = cpu_to_le32(param1);
	req->param[2] = cpu_to_le32(param2);
	req->param[3] = cpu_to_le32(param3);

	cl_dbg_verbose(cl_hw, "param0 = 0x%x, param1 = 0x%x, param2 = 0x%x, param3 = 0x%x\n",
		       req->param[0], req->param[1], req->param[2], req->param[3]);

	/* Send the DBG_PRINT_STATS_REQ message */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_trigger(struct cl_hw *cl_hw, char *msg)
{
	struct dbg_trigger_req *req;
	u8 msg_len = min(strlen(msg), sizeof(req->error) - 1);

	/* Build the MM_DBG_TRIGGER_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_TRIGGER_REQ, TASK_DBG, sizeof(struct dbg_trigger_req));

	if (!req)
		return -ENOMEM;

	/* Set parameters for the MM_DBG_TRIGGER_REQ message */
	strncpy(req->error, msg, msg_len);

	/* Send the MM_DBG_TRIGGER_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_test_mode(struct cl_hw *cl_hw, u32 *params)
{
	struct dbg_test_mode_req *req;
	int i = 0;

	/* Build the DBG_TEST_MODE_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_TEST_MODE_REQ, TASK_DBG, sizeof(struct dbg_test_mode_req));

	if (!req)
		return -ENOMEM;

	req->command = cpu_to_le32(params[0]);

	/* Param[0] is the command, therefore start from param[i + 1] */
	for (i = 0; i < TEST_MODE_PARAM_MAX; i++)
		req->params[i] = cpu_to_le32(params[i + 1]);

	/* Send the DBG_TEST_MODE_REQ message */
	return cl_send_request(cl_hw, req);
}

int cl_msg_tx_dbg_sounding_cmd(struct cl_hw *cl_hw, struct dbg_sounding_cmd_param *params)
{
	struct dbg_sounding_cmd_param *req = NULL;

	/* Build the DBG_SOUNDING_CMD_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_SOUNDING_CMD_REQ, TASK_DBG,
			    sizeof(struct dbg_sounding_cmd_param));
	if (!req)
		return -ENOMEM;

	/* Set parameters for the DBG_SOUNDING_CMD_REQ message */
	memcpy(req, params, sizeof(struct dbg_sounding_cmd_param));

	/* Send the DBG_SOUNDING_CMD_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}

#ifdef PRESILICON_TESTING
int cl_msg_tx_dbg_presilicon_test(struct cl_hw *cl_hw, struct presilicon_testing_param *params)
{
	struct presilicon_testing_param *req = NULL;

	/* Build the DBG_PRESILICON_TESTING_REQ message */
	req = cl_msg_zalloc(cl_hw, DBG_PRESILICON_TESTING_REQ, TASK_DBG,
			    sizeof(struct presilicon_testing_param));

	if (!req)
		return -ENOMEM;

	memcpy(req, params, sizeof(struct presilicon_testing_param));

	/* Send the DBG_PRESILICON_TESTING_REQ message to firmware */
	return cl_send_request(cl_hw, req);
}
#endif /* PRESILICON_TESTING */

static void cl_fill_calib_config(struct cl_hw *cl_hw, struct cl_api_calib_conf *calib_conf,
				 u16 primary, struct cl_calib_params *in_calib_params)
{
	struct cl_tcv_conf *conf = cl_hw->conf;
	struct cl_calib_iq_plan *calib_iq_plan = cl_hw->calib_iq_plan;
	s8 sx_freq_offset_mhz;

	calib_conf->nco_freq = cpu_to_le16(CALIB_NCO_FREQ_DEFAULT);
	calib_conf->nco_amp = CALIB_NCO_AMP_DEFAULT;
	calib_conf->sleeve_trshld = GAIN_SLEEVE_TRSHLD_DEFAULT;
	calib_conf->n_samples_exp_lolc = N_SAMPLES_EXP_LOLC;
	calib_conf->n_samples_exp_iqc = N_SAMPLES_EXP_IQC;
	calib_conf->p_thresh = cpu_to_le32(LO_P_THRESH);
	calib_conf->n_bit_fir_scale = N_BIT_FIR_SCALE;
	calib_conf->n_bit_amp_scale = N_BIT_AMP_SCALE;
	calib_conf->n_bit_phase_scale = N_BIT_PHASE_SCALE;
	cl_calib_iq_get_tone_vector(cl_hw, calib_conf->tone_vector);
	calib_conf->gp_rad_trshld = cpu_to_le32(conf->ci_calib_conf_gp_rad_trshld);
	calib_conf->ga_lin_upper_trshld =
		cpu_to_le32(conf->ci_calib_conf_ga_lin_upper_trshld);
	calib_conf->ga_lin_lower_trshld =
		cpu_to_le32(conf->ci_calib_conf_ga_lin_lower_trshld);
	calib_conf->comp_filter_len = conf->ci_calib_conf_comp_fiter_len;
	calib_conf->singletons_num = conf->ci_calib_conf_singletons_num;
	calib_conf->tones_num = IQ_NUM_TONES_REQ;
	calib_conf->rampup_time = cpu_to_le16(conf->ci_calib_conf_rampup_time);
	calib_conf->lo_coarse_step = cpu_to_le16(conf->ci_calib_conf_lo_coarse_step);
	calib_conf->lo_fine_step = cpu_to_le16(conf->ci_calib_conf_lo_fine_step);

	/*
	 * If there is calib iq plan file and the relevant <channel,bw> exist
	 * in file, fetch the sx_freq_offset_mhz data from plan file.
	 */
	if (calib_iq_plan)
		sx_freq_offset_mhz = calib_iq_plan->sx_diff;
	else
		sx_freq_offset_mhz = in_calib_params->sx_freq_offset_mhz;
	cl_dbg_info(cl_hw, "tcv_idx = %u, channel = %u, bw = %u, sx_freq_offset_mhz = %d\n",
		    cl_hw->tcv_idx, cl_hw->channel, cl_hw->bw, sx_freq_offset_mhz);
	cl_dbg_info(cl_hw, "|       TX Calibration      ||       RX Calibration      |\n");
	cl_dbg_info(cl_hw, "|chain|pair |tx_gain|rx_gain||chain|pair |tx_gain|rx_gain|\n");
}

static int _cl_msg_tx_set_calib(struct cl_hw *cl_hw, u16 primary,
				u16 center, struct cl_calib_params *in_calib_params)
{
	struct mm_set_calib_req *req;
	int res = 0, i = 0;
	struct cl_chip *chip = cl_hw->chip;
	bool is_sys_flow = in_calib_params->is_sys_flow;

	cl_hw->chip->is_calib_in_progress = true;
	if (in_calib_params->bt_mode_bmp == 0 && WARN_ON_ONCE(in_calib_params->channel == 0))
		return -EINVAL;
	req = cl_msg_zalloc(cl_hw, MM_SET_CALIB_REQ, TASK_MM, sizeof(struct mm_set_calib_req));
	if (!req)
		return -ENOMEM;

	/* Fill Calibration results from calib_db */
	cl_calib_common_fill_phy_data(cl_hw, &cl_hw->phy_data_info.data->iq_dcoc_db,
				      SET_PHY_DATA_FLAGS_ALL, true);

	req->band = cl_band_num_to_fw_idx(in_calib_params->band);
	req->wifi_calib_bmp = in_calib_params->wifi_mode_bmp;
	req->bt_calib_bmp = in_calib_params->bt_mode_bmp;
	req->wifi_chain_bmp = in_calib_params->wifi_chain_bmp;
	req->wifi_dcoc_sx_bmp = in_calib_params->dcoc_sx_bmp;
	req->bt_bw_bmp = in_calib_params->bt_bw_bmp;
	if (in_calib_params->bt_mode_bmp) {
		if (!is_sys_flow) {
			req->bt_ch_idx_num = 1;
			req->bt_ch_idx_1m[0] = in_calib_params->channel;
			req->bt_ch_idx_2m[0] = in_calib_params->channel;
		} else {
			req->bt_ch_idx_num = chip->conf->ci_calib_bt_num_of_ch_idx;
			memcpy(req->bt_ch_idx_1m,
			       chip->conf->ci_calib_bt_channel_idx_1m,
			       BT_CALIBRATION_CHANNLES_NUM);
			memcpy(req->bt_ch_idx_2m,
			       chip->conf->ci_calib_bt_channel_idx_2m,
			       BT_CALIBRATION_CHANNLES_NUM);
		}
	}

	/* req initial rx/tx gain values */
	for (i = 0; i < MAX_CALIBRATION_TYPE_NUM; i++) {
		req->initial_rx_gain_arr[i] =
			cpu_to_le16(chip->conf->ci_calib_init_rx_gain[i]);
		req->initial_tx_gain_arr[i] =
			cpu_to_le16(chip->conf->ci_calib_init_tx_gain[i]);
		req->sx_freq_offset_mhz[i] =
			in_calib_params->sx_freq_offset_mhz;
	}

	req->wifi_channel_bw = in_calib_params->wifi_bw;
	req->prim20_freq = cpu_to_le16(primary);
	req->center1_freq_lut.frequency_q2 = cpu_to_le16(center);
	req->wifi_hr_factor = cl_hw->conf->ci_hr_factor[in_calib_params->wifi_bw];
	req->dcoc_max_vga = chip->conf->ci_dcoc_max_vga;
	/* data input from user [cecli cmd] */
	req->is_matlab = in_calib_params->is_matlab;

	cl_hw->first_riu_chain = (in_calib_params->wifi_chain_bmp & 1) ? 0 : 1;
	cl_hw->last_riu_chain = (in_calib_params->wifi_chain_bmp & 2) ? 1 : 0;

	if (in_calib_params->wifi_mode_bmp & (WIFI_CALIB_MODE_RX_GAIN |
					      WIFI_CALIB_MODE_TX_LO |
					      SET_CALIB_MODE_IQ_ALL)) {
		cl_fill_calib_config(cl_hw, &req->conf, primary, in_calib_params);
	}
	/* Antenna configuration */
	cl_fill_ant_config(cl_hw, &req->ant_config, cl_hw->num_antennas, cl_hw->num_antennas,
			   cl_hw->conf->ce_cck_tx_ant_mask, cl_hw->conf->ce_cck_rx_ant_mask);

	res = cl_send_msg_background(cl_hw, req);
	cl_dbg_info(cl_hw,
		    "band=%u, channel=%u, bw=%u, primary=%u.%u, center=%u.%u, sx_index=%u\n",
		    cl_hw->conf->ci_band_num, cl_hw->channel,  cl_hw->bw, GET_FREQ_INT(primary),
		    GET_FREQ_FRAC(primary), GET_FREQ_INT(center), GET_FREQ_FRAC(center),
		    cl_hw->tcv_idx);

	return res;
}

int cl_msg_tx_set_calib(struct cl_hw *cl_hw, u32 primary,
			u32 center, struct cl_calib_params *in_calib_params)
{
	int res = 0;
	u32 primary_q2 = FREQ_TO_Q2(primary);
	u32 center_q2 = FREQ_TO_Q2(center);
	/*
	 * Need to take mutex lock to ensure that no one touching the phy_data
	 * DMA before FW is reading all its values.
	 * The mutex is unlocked right after the iq_dcoc_data_info DMA is
	 * handled in cl_calib_common_handle_set_calib_cfm.
	 */
	res = mutex_lock_interruptible(&cl_hw->set_channel_mutex);
	if (res != 0) {
		cl_dbg_verbose(cl_hw, "Error - mutex_lock_interruptible (%d)\n", res);
		return res;
	}

	/* Copy calibration params to cl_hw - must be done after mutex lock */
	memcpy(&cl_hw->calib_params, in_calib_params, sizeof(struct cl_calib_params));

	res = _cl_msg_tx_set_calib(cl_hw, primary_q2, center_q2, &cl_hw->calib_params);

	return res;
}

int cl_msg_tx_matlab_response(struct cl_hw *cl_hw, struct mm_matlab_calib_res  *matlab_calib_res)
{
	/* copy calib data content to the req
	 * need to check if matlab_calib_res is the same
	 * size as mm_matlab_calib_res
	 */
	struct mm_matlab_calib_res *res;
	/* Build the MM_STA_DEL_REQ message */
	res = cl_msg_zalloc(cl_hw, MM_MATLAB_RESPONSE,
			    TASK_MM, sizeof(struct mm_matlab_calib_res));
	if (!res)
		return -ENOMEM;
	memcpy(res, matlab_calib_res, sizeof(struct mm_matlab_calib_res));
	cl_dbg_verbose(cl_hw,
		       "%s.\n first val [%u][%u] data:[%d][%d][%d][%d][%d]\n",
		       __func__,
		       res->data[MM_MATLAB_CALIB_RES_LEN_IDX + 2],
		       res->data[MM_MATLAB_CALIB_RES_LEN_IDX + 3],
		       res->data[MM_MATLAB_CALIB_RES_DATA_IDX],
		       res->data[MM_MATLAB_CALIB_RES_DATA_IDX + 1],
		       res->data[MM_MATLAB_CALIB_RES_DATA_IDX + 2],
		       res->data[MM_MATLAB_CALIB_RES_DATA_IDX + 3],
		       res->data[MM_MATLAB_CALIB_RES_DATA_IDX + 4]);

	/* Send the MM_MATLAB_RESPONSE message to firmware */
	return cl_send_request(cl_hw, res);
}

int cl_msg_tx_riu_loopback_config(struct cl_hw *cl_hw, u8 rx_chain_id, u8 tx_chain_id, u8 bw)
{
	struct mm_riu_loopback_config_req *req;

	req = cl_msg_zalloc(cl_hw, MM_RIU_LOOPBACK_REQ,
			    TASK_MM, sizeof(struct mm_riu_loopback_config_req));
	if (!req)
		return -ENOMEM;

	req->rx_chain_id = rx_chain_id;
	req->tx_chain_id = tx_chain_id;
	req->bw = bw;

	/* Send the MM_RIU_LOOPBACK_CONFIG message to firmware */
	return cl_send_request(cl_hw, req);
}
