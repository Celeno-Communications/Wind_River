// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_tx.h"
#include "cl_sounding.h"
#include "cl_msg_rx.h"
#include "cl_msg_tx.h"
#include "cl_msg_cfm.h"
#include "cl_stats.h"
#include "cl_rx_sens.h"
#include "cl_rssi.h"
#include "cl_fw_dbg.h"
#include "cl_utils.h"
#include "cl_hw_assert.h"
#include "cl_age_out.h"
#include "cl_rate_ctrl.h"
#include "cl_bss_color.h"
#include "cl_agg_rx_report.h"
#include "cl_agg_cfm.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif
#include "cl_calib_common_api.h"

static inline void rx_mm_start_cfm(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	cl_msg_cfm_clear(cl_hw, msg);
	/* Send indication to the embedded that a new rxbuffer element are ready */
	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_hw->ipc_host2xmac_trigger_set(cl_hw->chip, IPC_IRQ_A2E_RXBUF_BACK);
}

static inline void rx_mm_ba_add_cfm(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	if (le16_to_cpu(msg->id) == MM_BA_ADD_TX_CFM)
		cl_msg_cfm_assign_and_clear(cl_hw, msg);
	else
		cl_msg_cfm_clear(cl_hw, msg);
}

static inline void rx_mm_agg_tx_report_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct cl_agg_tx_report *agg_report = (struct cl_agg_tx_report *)msg->param;
	struct cl_sta *cl_sta;
	union cl_rate_ctrl_info rate_ctrl_info;
	u8 queue_idx = agg_report->queue_idx;
	u16 ssn = le16_to_cpu(agg_report->new_ssn);

	if (ssn < IEEE80211_MAX_SN)
		cl_agg_cfm_handle(cl_hw, ssn, queue_idx);

	/*
	 * Take care of endianness and update gi and format_mod fields of rate
	 * ctrl info in agg_report for the sake of any function that needs to
	 * use them
	 */
	rate_ctrl_info.word = le32_to_cpu(agg_report->rate_cntrl_info);

	cl_rate_ctrl_convert(&rate_ctrl_info);
	agg_report->rate_cntrl_info = cpu_to_le32(rate_ctrl_info.word);

	cl_sta_lock(cl_hw);
	cl_sta = cl_sta_get(cl_hw, agg_report->sta_idx);

	if (cl_sta) {
		/* TX stats */
		cl_agg_tx_report_handler(cl_hw, cl_sta, (void *)agg_report);
		cl_stats_update_tx_agg(cl_hw, cl_sta, agg_report);

		/* RSSI stats */
		if (!agg_report->ba_not_received)
			cl_rssi_block_ack_handler(cl_hw, cl_sta, agg_report);

		/*
		 * Ageout: reset ageout counter if at least one frame was
		 * success.
		 * Needed when sending UDP downlink because BA's are not
		 * forwarded to driver.
		 */
		if (agg_report->success)
			cl_age_out_reset_counter(cl_hw, cl_sta);
	}

	cl_sta_unlock(cl_hw);
}

static inline void rx_mm_agg_rx_report_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct mm_agg_rx_ind *agg_report = (struct mm_agg_rx_ind *)msg->param;
	struct cl_sta *cl_sta = NULL;

	cl_sta_lock(cl_hw);

	cl_sta = cl_sta_get(cl_hw, agg_report->sta_idx);
	if (cl_sta)
		cl_agg_rx_report_handler(cl_hw, cl_sta, agg_report);

	cl_sta_unlock(cl_hw);
}

static inline void rx_mm_sounding_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct mm_sounding_ind *ind = (struct mm_sounding_ind *)msg->param;

	cl_sounding_indication(cl_hw, ind);
}

static inline void rx_mm_bss_color_collision_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct mm_bss_color_collision_ind *ind = (struct mm_bss_color_collision_ind *)msg->param;

	cl_bss_color_collision_indication(cl_hw, ind);
}

static inline void rx_mm_fw_error_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct mm_fw_error_ind *ind = (struct mm_fw_error_ind *)msg->param;

	switch (ind->error_type) {
	case MM_FW_ERROR_TYPE_MU_OFDMA_SLOW_SECONDARY:
	case MM_FW_ERROR_TYPE_MAX:
	default:
		cl_dbg_err(cl_hw, "Invalid fw error type %u\n", ind->error_type);
		break;
	}
}

static inline void rx_mm_fw_sync_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct mm_fw_sync_ind *ind = (struct mm_fw_sync_ind *)msg->param;
	struct cl_chip *chip = cl_hw->chip;

	if (chip->bus_type != ind->bus_type)
		cl_dbg_err(cl_hw, "wrong bus_type %d !!!\n", ind->bus_type);

	set_bit(CL_DEV_FW_SYNC, &cl_hw->drv_flags);
	wake_up_interruptible(&cl_hw->fw_sync_wq);
}

static inline void rx_mm_idle_async_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	cl_hw->idle_async_set = false;

	cl_dbg_trace(cl_hw, "Clear MM_IDLE_ASYNC_IND\n");
}

static inline void rx_mm_tx_path_idle_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct mm_tx_path_idle_ind *ind = (struct mm_tx_path_idle_ind *)msg->param;

	cl_tx_handle_tx_path_idle(cl_hw, ind->ac_idle_bitmap);
}

static inline void rx_dbg_print_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	struct dbg_print_ind *ind = (struct dbg_print_ind *)msg->param;

	if (cl_hw->dbginfo.buf) {
		mutex_lock(&cl_hw->dbginfo.mutex);
		memcpy(&cl_hw->dbginfo.buf->u.dump.fw_dump.common_info.error_info,
		       ind, sizeof(*ind));
		mutex_unlock(&cl_hw->dbginfo.mutex);
	}

	cl_hw_assert_print(cl_hw, msg);
}

static inline void rx_dbg_info_ind(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	cl_fw_dbg_handler(cl_hw);
}

static void cl_mm_set_calib_cfm_handler(struct work_struct *ws)
{
	struct cl_msg_rx_work *msg_rx_work = container_of(ws, struct cl_msg_rx_work, ws);
	struct cl_hw *cl_hw = msg_rx_work->cl_hw;

	cl_calib_common_handle_set_calib_cfm(cl_hw);

	/*
	 * This mutex unlock located here because for bring up stage MM_SET_CALLIB req
	 * is only sent in the background.
	 */
	mutex_unlock(&cl_hw->set_channel_mutex);
	kfree(msg_rx_work);
}

static inline void rx_mm_set_calib_cfm(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	/* Generate & populate the work struct wrapper for the background msg */
	struct cl_msg_rx_work *msg_rx_work = kzalloc(sizeof(*msg_rx_work), GFP_ATOMIC);

	cl_msg_cfm_clear(cl_hw, msg);
	if (msg_rx_work) {
		INIT_WORK(&msg_rx_work->ws, cl_mm_set_calib_cfm_handler);
		msg_rx_work->cl_hw = cl_hw;
		/* Schedule work, the work will be executed in the background */
		queue_work(cl_hw->drv_workqueue, &msg_rx_work->ws);
	} else
		cl_dbg_err(cl_hw, "msg_rx_work allocation failed for calivration cfm\n");
}

static inline void rx_mm_matlab_calib_req(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	/* MM_MATLAB_CALIBRATION msg */
	struct mm_matlab_calib_req *req = (struct mm_matlab_calib_req *)(msg->param);
	/* Generate & populate the work struct wrapper for the background msg */
	cl_calib_common_handle_matlab_calib_req(cl_hw, req->file_len);
}

static void (*mm_hdlrs[])(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg) = {
	[MM_RESET_CFM]                  = cl_msg_cfm_clear,
	[MM_START_CFM]                  = rx_mm_start_cfm,
	[MM_VERSION_CFM]                = cl_msg_cfm_assign_and_clear,
	[MM_ADD_IF_CFM]                 = cl_msg_cfm_assign_and_clear,
	[MM_REMOVE_IF_CFM]              = cl_msg_cfm_clear,
	[MM_STA_ADD_CFM]                = cl_msg_cfm_assign_and_clear,
	[MM_STA_DEL_CFM]                = cl_msg_cfm_clear,
	[MM_SET_FILTER_CFM]             = cl_msg_cfm_clear,
	[MM_SET_CHANNEL_CFM]            = cl_msg_cfm_clear,
	[MM_SET_DTIM_CFM]               = cl_msg_cfm_clear,
	[MM_SET_BEACON_INT_CFM]         = cl_msg_cfm_clear,
	[MM_SET_BASIC_RATES_CFM]        = cl_msg_cfm_clear,
	[MM_SET_BSSID_CFM]              = cl_msg_cfm_clear,
	[MM_SET_EDCA_CFM]               = cl_msg_cfm_clear,
	[MM_SET_ASSOCIATED_CFM]         = cl_msg_cfm_clear,
	[MM_SET_SLOTTIME_CFM]           = cl_msg_cfm_clear,
	[MM_SET_IDLE_CFM]               = cl_msg_cfm_clear,
	[MM_SET_BSS_COLOR_CFM]          = cl_msg_cfm_clear,
	[MM_KEY_ADD_CFM]                = cl_msg_cfm_assign_and_clear,
	[MM_KEY_DEL_CFM]                = cl_msg_cfm_clear,
	[MM_BA_ADD_TX_CFM]              = rx_mm_ba_add_cfm,
	[MM_BA_ADD_RX_CFM]              = rx_mm_ba_add_cfm,
	[MM_BA_DEL_CFM]                 = cl_msg_cfm_assign_and_clear,
	[MM_AVAILABLE_BA_TXQ_CFM]       = cl_msg_cfm_assign_and_clear,
	[MM_UPDATE_RATE_DL_CFM]         = cl_msg_cfm_clear,
	[MM_UPDATE_RATE_UL_CFM]         = cl_msg_cfm_clear,
	[MM_SET_VNS_CFM]                = cl_msg_cfm_clear,
	[MM_SET_TX_BF_CFM]              = cl_msg_cfm_clear,
	[MM_PHY_RESET_CFM]              = cl_msg_cfm_clear,
	[MM_CONFIG_CCA_CFM]             = cl_msg_cfm_clear,
	[MM_SET_ANT_BITMAP_CFM]         = cl_msg_cfm_clear,
	[MM_NDP_TX_CONTROL_CFM]         = cl_msg_cfm_clear,
	[MM_REG_WRITE_CFM]              = cl_msg_cfm_clear,
	[MM_PROT_MODE_CFM]              = cl_msg_cfm_clear,
	[MM_BW_SIGNALING_MODE_CFM]      = cl_msg_cfm_clear,
	[MM_GOTO_POWER_REDUCTION_CFM]   = cl_msg_cfm_clear,
	[MM_SOUNDING_CFM]               = cl_msg_cfm_assign_and_clear,
	[MM_SOUNDING_INTERVAL_CFM]      = cl_msg_cfm_assign_and_clear,
	[MM_SOUNDING_STA_SWITCH_CFM]    = cl_msg_cfm_assign_and_clear,
	[MM_BACKUP_BCN_EN_CFM]          = cl_msg_cfm_clear,
	[MM_START_PERIODIC_TX_TIME_CFM] = cl_msg_cfm_clear,
	[MM_ANAMON_READ_CFM]            = cl_msg_cfm_assign_and_clear,
	[MM_REFRESH_PWR_CFM]            = cl_msg_cfm_clear,
	[MM_SET_ANT_PWR_OFFSET_CFM]     = cl_msg_cfm_clear,
	[MM_SET_RATE_FALLBACK_CFM]      = cl_msg_cfm_clear,
	[MM_TWT_SETUP_CFM]              = cl_msg_cfm_clear,
	[MM_TWT_TEARDOWN_CFM]           = cl_msg_cfm_clear,
	[MM_TF_CFM]                     = cl_msg_cfm_clear,
	[MM_RIU_LOOPBACK_CFM]           = cl_msg_cfm_clear,
	[MM_SET_CALIB_CFM]              = rx_mm_set_calib_cfm,
#ifdef NATT_DBG
	[MM_NATT_TESTING_CFM]           = cl_msg_cfm_clear,
#endif
	[MM_AGG_TX_REPORT_IND]          = rx_mm_agg_tx_report_ind,
	[MM_AGG_RX_REPORT_IND]          = rx_mm_agg_rx_report_ind,
	[MM_SOUNDING_IND]               = rx_mm_sounding_ind,
	[MM_BSS_COLOR_COLLISION_IND]    = rx_mm_bss_color_collision_ind,
	[MM_FW_ERROR_IND]               = rx_mm_fw_error_ind,
	[MM_FW_SYNC_IND]                = rx_mm_fw_sync_ind,
	[MM_IDLE_ASYNC_IND]             = rx_mm_idle_async_ind,
	[MM_TX_PATH_IDLE_IND]           = rx_mm_tx_path_idle_ind,
	[MM_MATLAB_CALIBRATION]         = rx_mm_matlab_calib_req,
	[MM_MAX]                        = NULL,
};

#define DBG_MSG_SHIFT(id)  ((id) - FIRST_MSG(TASK_DBG))

static void (*dbg_hdlrs[])(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg) = {
	[DBG_MSG_SHIFT(DBG_SET_MOD_FILTER_CFM)]         = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_SET_SEV_FILTER_CFM)]         = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_CE_SET_MOD_FILTER_CFM)]      = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_BEAMFORMING_TX_CFM)]         = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_SET_LA_MPIF_MASK_CFM)]       = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_SET_LA_TRIG_POINT_CFM)]      = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_SET_LA_MPIF_DEBUG_MODE_CFM)] = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_SET_LA_TRIG_RULE_CFM)]       = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_TX_TRACE_DEBUG_FLAG_CFM)]    = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_PRINT_STATS_CFM)]            = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_TRIGGER_CFM)]                = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_TEST_MODE_CFM)]              = cl_msg_cfm_clear,
	[DBG_MSG_SHIFT(DBG_SOUNDING_CMD_CFM)]           = cl_msg_cfm_clear,
#ifdef PRESILICON_TESTING
	[DBG_MSG_SHIFT(DBG_PRESILICON_TESTING_CFM)]     = cl_msg_cfm_clear,
#endif
	[DBG_MSG_SHIFT(DBG_PRINT_IND)]                  = rx_dbg_print_ind,
	[DBG_MSG_SHIFT(DBG_INFO_IND)]                   = rx_dbg_info_ind,
	[DBG_MSG_SHIFT(DBG_MAX)]                        = NULL,
};

static bool is_dbg_msg(u16 msg_id)
{
	return (msg_id >= FIRST_MSG(TASK_DBG) && msg_id < DBG_MAX);
}

static void cl_msg_rx_run_mm(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg, u16 msg_id)
{
	if (msg_id < MM_REQ_CFM_MAX)
		cl_dbg_trace(cl_hw, "%s\n", msg2str[msg_id]);

	mm_hdlrs[msg_id](cl_hw, msg);
}

static int cl_msg_rx_run_dbg(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg, u16 msg_id)
{
	u16 dbg_id = DBG_MSG_SHIFT(msg_id);

	if (dbg_hdlrs[dbg_id]) {
		if (msg_id < DBG_REQ_CFM_MAX) {
			u16 str_id = DBG_STR_SHIFT(msg_id);

			cl_dbg_trace(cl_hw, "%s\n", msg2str[str_id]);
		}

		dbg_hdlrs[dbg_id](cl_hw, msg);
		return 0;
	}

	return -1;
}

static int cl_msg_rx_run(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	u16 msg_id = le16_to_cpu(msg->id);

	if (msg_id < MM_MAX && mm_hdlrs[msg_id]) {
		cl_msg_rx_run_mm(cl_hw, msg, msg_id);
		return 0;
	}

	if (is_dbg_msg(msg_id))
		return cl_msg_rx_run_dbg(cl_hw, msg, msg_id);

	return -1;
}

static bool is_cfm_msg(u16 msg_id)
{
	/* A confirmation must be an odd id */
	if ((msg_id & 0x1) == 0)
		return false;

	return ((msg_id < MM_FIRST_IND) || is_dbg_msg(msg_id));
}

static int cl_msg_rx_handler(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	int ret = 0;
	u16 msg_id = le16_to_cpu(msg->id);

#ifdef TRACE_SUPPORT
	trace_cl_trace_msg_ind_start(cl_hw->idx, msg_id,
				     le32_to_cpu(msg->pattern), cl_hw->cfm_flags);
#endif
	/* Relay further actions to the msg parser */
	ret = cl_msg_rx_run(cl_hw, msg);

	if (ret) {
		cl_dbg_err(cl_hw, "Unexpected msg (%u)\n", msg_id);
	} else {
		/* Wake up the queue in case the msg is a confirmation */
		if (is_cfm_msg(msg_id))
			wake_up(&cl_hw->wait_queue);
	}

#ifdef TRACE_SUPPORT
	trace_cl_trace_msg_ind_end(cl_hw->idx, cl_hw->cfm_flags);
#endif

	return ret;
}

static struct cl_rx_msg *cl_msg_rx_get_first(struct cl_hw *cl_hw)
{
	struct cl_rx_msg *msg;
	unsigned long flags;

	spin_lock_irqsave(&cl_hw->rx_msg_lock, flags);
	msg = list_first_entry_or_null(&cl_hw->rx_msg_head, struct cl_rx_msg, list);

	if (msg)
		list_del(&msg->list);

	spin_unlock_irqrestore(&cl_hw->rx_msg_lock, flags);

	return msg;
}

void cl_msg_rx_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_rx_msg *msg;
	int msg_handled = 0;

#ifdef TRACE_SUPPORT
	trace_cl_trace_msg_tasklet_start(cl_hw->idx);
#endif

	while ((msg = cl_msg_rx_get_first(cl_hw))) {
		cl_msg_rx_handler(cl_hw, &msg->buf);
		kfree(msg);
		msg_handled++;
	}

#ifdef TRACE_SUPPORT
	trace_cl_trace_msg_tasklet_end(cl_hw->idx, msg_handled);
#endif
}

void cl_msg_rx_flush_all(struct cl_hw *cl_hw)
{
	int i = 0;

	for (i = FIRST_MSG(TASK_MM); i < MM_MAX; i++) {
		if (cl_hw->msg_cfm_params[i]) {
			cl_dbg_verbose(cl_hw, "free MM msg_cfm_params %d\n", i);
			cl_msg_tx_free_cfm_params(cl_hw, i);
		}
	}

	for (i = FIRST_MSG(TASK_DBG); i < DBG_MAX; i++) {
		if (cl_hw->msg_cfm_params[i]) {
			cl_dbg_verbose(cl_hw, "free DBG msg_cfm_params %d\n", i);
			cl_msg_tx_free_cfm_params(cl_hw, i);
		}
	}
}
