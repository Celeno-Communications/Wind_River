// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/dma-mapping.h>
#include <linux/dmapool.h>

#include "chip_ops.h"
#include "cl_main.h"
#include "cl_ops.h"
#include "cl_e2p.h"
#include "cl_otp.h"
#include "cl_ul_length.h"
#include "cl_data_rates.h"
#include "cl_radar.h"
#include "cl_msg_tx.h"
#include "cl_tx.h"
#include "reg_access.h"
#include "cl_stats.h"
#include "cl_debugfs.h"
#include "cl_vendor_cmd.h"
#include "cl_chan_info.h"
#include "cl_agg_cfm.h"
#include "cl_single_cfm.h"
#include "cl_bcmc_cfm.h"
#include "cl_tx_queue.h"
#include "cl_rssi.h"
#include "cl_maintenance.h"
#include "cl_temperature.h"
#include "cl_vns.h"
#include "cl_traffic.h"
#include "cl_age_out.h"
#include "cl_env_det.h"
#include "cl_vlan_dscp.h"
#include "cl_sounding.h"
#include "cl_rx_sens.h"
#include "cl_recovery.h"
#include "cl_rate_ctrl.h"
#include "cl_dyn_mcast_rate.h"
#include "cl_dyn_bcast_rate.h"
#include "cl_tx_amsdu.h"
#include "cl_fw_test.h"
#include "cl_prot_mode.h"
#include "cl_utils.h"
#include "cl_band.h"
#include "cl_phy.h"
#include "cl_dsp_load.h"
#include "cl_calib_iq.h"
#include "cl_calib_common_api.h"
#include "cl_calibration.h"
#include "reg_macsys_gcu.h"
#include "cl_sw_txhdr.h"
#include "cl_tx_inject.h"
#include "cl_fw_file.h"
#include "cl_cap.h"
#include "cl_tcv_config.h"
#include "cl_mac_addr.h"
#include "cl_hw_assert.h"
#include "cl_power_table.h"
#include "cl_noise.h"
#include "cl_twt.h"
#include "cl_bsrp.h"
#include "cl_fw_dbg.h"
#include "cl_tf.h"
#include "cl_ul_rssi.h"
#include "cl_wrs_api.h"
#include "cl_msg_rx.h"
#include "reg_ipc.h"
#include "cl_bsr.h"
#include "cl_irq.h"
#include "cl_ipc.h"
#include "cl_usb.h"
#include "cl_calib_common_api.h"
#include "cl_calib_runtime.h"

MODULE_DESCRIPTION("Celeno 11ax driver for Linux");
MODULE_VERSION("6.0.x");
MODULE_AUTHOR("Copyright(c) 2022 Celeno Communications Ltd");
MODULE_LICENSE("Dual BSD/GPL");

#define CL_ALIGN_BOUND_64KB BIT(16)

static struct ieee80211_ops cl_ops = {
	.tx                     = cl_ops_tx,
	.start                  = cl_ops_start,
	.stop                   = cl_ops_stop,
	.add_interface          = cl_ops_add_interface,
	.remove_interface       = cl_ops_remove_interface,
	.config                 = cl_ops_config,
	.bss_info_changed       = cl_ops_bss_info_changed,
	.start_ap               = cl_ops_start_ap,
	.prepare_multicast      = cl_ops_prepare_multicast,
	.configure_filter       = cl_ops_configure_filter,
	.set_key                = cl_ops_set_key,
	.sw_scan_start          = cl_ops_sw_scan_start,
	.sta_state              = cl_ops_sta_state,
	.sta_notify             = cl_ops_sta_notify,
	.conf_tx                = cl_ops_conf_tx,
	.sta_rc_update          = cl_ops_sta_rc_update,
	.ampdu_action           = cl_ops_ampdu_action,
	.post_channel_switch    = cl_ops_post_channel_switch,
	.flush                  = cl_ops_flush,
	.tx_frames_pending      = cl_ops_tx_frames_pending,
	.reconfig_complete      = cl_ops_reconfig_complete,
	.get_txpower            = cl_ops_get_txpower,
	.set_rts_threshold      = cl_ops_set_rts_threshold,
	.event_callback         = cl_ops_event_callback,
	.rx_finish              = cl_ops_rx_finish,
	.set_tim                = cl_ops_set_tim,
	.get_expected_throughput = cl_ops_get_expected_throughput,
};

static void cl_main_set_cl_hw(struct cl_chip *chip, struct cl_hw *cl_hw)
{
	if (IS_PCI_BUS_TYPE(chip))
		cl_pci_set_cl_hw(chip, cl_hw);
	else
		cl_usb_set_cl_hw(chip, cl_hw);
}

static void cl_drv_workqueue_create(struct cl_hw *cl_hw)
{
	if (!cl_hw->drv_workqueue)
		cl_hw->drv_workqueue = create_singlethread_workqueue("drv_workqueue");
}

static void cl_drv_workqueue_destroy(struct cl_hw *cl_hw)
{
	if (cl_hw->drv_workqueue) {
		destroy_workqueue(cl_hw->drv_workqueue);
		cl_hw->drv_workqueue = NULL;
	}
}

static int tx_queues_alloc(struct cl_hw *cl_hw)
{
	struct tx_queues_dma_addr *buf = NULL;
	u32 size = sizeof(struct tx_queues_dma_addr);
	dma_addr_t phys_dma_addr;

	buf = chip_ops_alloc_coherent(cl_hw->chip, size, GFP_KERNEL, &phys_dma_addr);

	if (!buf)
		return -ENOMEM;

	cl_hw->ipc_tx_queues.queues_dma_addr = buf;
	cl_hw->ipc_tx_queues.dma_addr = phys_dma_addr;

	return 0;
}

static int __txdesc_alloc(struct cl_hw *cl_hw,
			  struct txdesc **txdesc,
			  __le32 *dma_addr,
			  u32 desc_num)
{
	dma_addr_t phys_dma_addr;
	u32 size = (desc_num * sizeof(struct txdesc));

	if (IS_PCI_BUS_TYPE(cl_hw->chip) && size < PAGE_SIZE) {
		*txdesc = dma_pool_alloc(cl_hw->txdesc_pool, GFP_KERNEL, &phys_dma_addr);

		if (!(*txdesc)) {
			cl_dbg_err(cl_hw, "dma_pool_alloc failed size=%d\n", size);
			return -ENOMEM;
		}
	} else {
		*txdesc = chip_ops_alloc_coherent(cl_hw->chip, size, GFP_KERNEL, &phys_dma_addr);

		if (!(*txdesc)) {
			cl_dbg_err(cl_hw, "chip_ops_alloc_coherent failed size=%d\n", size);
			return -ENOMEM;
		}
	}

	*dma_addr = cpu_to_le32(phys_dma_addr);
	memset(*txdesc, 0, size);

	return 0;
}

static int _txdesc_alloc(struct cl_hw *cl_hw)
{
	/*
	 * Allocate ipc txdesc for each queue, map the base
	 * address to the DMA and set the queues size
	 */
	struct cl_ipc_tx_queues *tx_queues = &cl_hw->ipc_tx_queues;
	struct tx_queues_dma_addr *queues_dma_addr = tx_queues->queues_dma_addr;
	u32 i;
	int ret;

	ret = __txdesc_alloc(cl_hw, &tx_queues->ipc_txdesc_bcmc,
			     &queues_dma_addr->bcmc, IPC_TXDESC_CNT_BCMC);
	if (ret)
		return ret;

	for (i = 0; i < MAX_SINGLE_QUEUES; i++) {
		ret = __txdesc_alloc(cl_hw, &tx_queues->ipc_txdesc_single[i],
				     &queues_dma_addr->single[i], IPC_TXDESC_CNT_SINGLE);
		if (ret)
			return ret;
	}

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++) {
		ret = __txdesc_alloc(cl_hw, &tx_queues->ipc_txdesc_agg[i],
				     &queues_dma_addr->agg[i], TXDESC_AGG_Q_SIZE_MAX);
		if (ret)
			return ret;
	}

	return 0;
}

static int txdesc_alloc(struct cl_hw *cl_hw)
{
	u32 pool_size = IPC_TXDESC_CNT_SINGLE * sizeof(struct txdesc);

	cl_hw->txdesc_pool = dma_pool_create("cl_txdesc_pool", cl_hw->chip->dev, pool_size,
					     cache_line_size(), 0);

	if (!cl_hw->txdesc_pool) {
		cl_dbg_verbose(cl_hw, "dma_pool_create failed !!!\n");
		return -ENOMEM;
	}

	return _txdesc_alloc(cl_hw);
}

static void _txdesc_dealloc(struct cl_hw *cl_hw,
			    struct txdesc *txdesc,
			    __le32 dma_addr,
			    u32 desc_num)
{
	dma_addr_t phys_dma_addr = le32_to_cpu(dma_addr);
	u32 size = (desc_num * sizeof(struct txdesc));

	if (IS_PCI_BUS_TYPE(cl_hw->chip) && size < PAGE_SIZE)
		dma_pool_free(cl_hw->txdesc_pool, txdesc, phys_dma_addr);
	else
		chip_ops_free_coherent(cl_hw->chip, size, txdesc, phys_dma_addr);
}

static void txdesc_dealloc(struct cl_hw *cl_hw)
{
	struct cl_ipc_tx_queues *tx_queues = &cl_hw->ipc_tx_queues;
	struct tx_queues_dma_addr *queues_dma_addr = tx_queues->queues_dma_addr;
	u32 i;

	if (queues_dma_addr->bcmc) {
		_txdesc_dealloc(cl_hw, tx_queues->ipc_txdesc_bcmc, queues_dma_addr->bcmc,
				IPC_TXDESC_CNT_BCMC);
		queues_dma_addr->bcmc = 0;
	}

	for (i = 0; i < MAX_SINGLE_QUEUES; i++)
		if (queues_dma_addr->single[i]) {
			_txdesc_dealloc(cl_hw, tx_queues->ipc_txdesc_single[i],
					queues_dma_addr->single[i], IPC_TXDESC_CNT_SINGLE);
			queues_dma_addr->single[i] = 0;
		}

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++)
		if (queues_dma_addr->agg[i]) {
			_txdesc_dealloc(cl_hw, tx_queues->ipc_txdesc_agg[i],
					queues_dma_addr->agg[i], TXDESC_AGG_Q_SIZE_MAX);
			queues_dma_addr->agg[i] = 0;
		}

	dma_pool_destroy(cl_hw->txdesc_pool);
	cl_hw->txdesc_pool = NULL;
}

static void tx_queues_dealloc(struct cl_hw *cl_hw)
{
	u32 len = sizeof(struct tx_queues_dma_addr);
	dma_addr_t phys_dma_addr = cl_hw->ipc_tx_queues.dma_addr;

	if (!cl_hw->ipc_tx_queues.queues_dma_addr)
		return;

	chip_ops_free_coherent(cl_hw->chip, len,
			       (void *)cl_hw->ipc_tx_queues.queues_dma_addr,
			       phys_dma_addr);
	cl_hw->ipc_tx_queues.queues_dma_addr = NULL;
}

static int write_idx_alloc(struct cl_hw *cl_hw)
{
	struct cl_txdesc_write_idx *buf = NULL;
	u32 size = sizeof(struct cl_txdesc_write_idx);
	dma_addr_t phys_dma_addr;

	buf = chip_ops_alloc_coherent(cl_hw->chip, size, GFP_KERNEL, &phys_dma_addr);

	if (!buf)
		return -ENOMEM;

	cl_hw->ipc_write_idx.txdesc_write_idx = buf;
	cl_hw->ipc_write_idx.dma_addr = phys_dma_addr;

	return 0;
}

static void write_idx_dealloc(struct cl_hw *cl_hw)
{
	u32 len = sizeof(struct cl_txdesc_write_idx);
	dma_addr_t phys_dma_addr = cl_hw->ipc_write_idx.dma_addr;

	if (!cl_hw->ipc_write_idx.txdesc_write_idx)
		return;

	chip_ops_free_coherent(cl_hw->chip, len,
			       (void *)cl_hw->ipc_write_idx.txdesc_write_idx,
			       phys_dma_addr);
	cl_hw->ipc_write_idx.txdesc_write_idx = NULL;
}

static int _dbg_info_alloc(struct cl_hw *cl_hw)
{
	dma_addr_t dma_addr;
	u32 len = sizeof(struct dbg_info);
	struct dbg_info *buf = chip_ops_alloc_coherent(cl_hw->chip, len,
						       GFP_KERNEL, &dma_addr);

	if (!buf) {
		cl_dbg_verbose(cl_hw, "buffer alloc of size %u failed\n", len);
		return -ENOMEM;
	}

	memset(buf, 0, sizeof(struct dbg_info));
	buf->u.type = DBG_INFO_UNSET;

	cl_hw->dbginfo.buf = buf;
	cl_hw->dbginfo.dma_addr = dma_addr;
	cl_hw->dbginfo.bufsz = len;

	return 0;
}

static int cl_single_cfm_alloc(struct cl_hw *cl_hw)
{
	dma_addr_t dma_addr;
	u8 *host_virt_addr;

	host_virt_addr = chip_ops_alloc_coherent(cl_hw->chip, IPC_CFM_SIZE,
						 GFP_KERNEL, &dma_addr);

	if (!host_virt_addr)
		return -ENOMEM;

	memset(host_virt_addr, 0, IPC_CFM_SIZE);
	cl_hw->single_cfm_dma_base_addr = dma_addr;
	cl_hw->single_cfm_virt_base_addr = host_virt_addr;

	return 0;
}

static void cl_single_cfm_dealloc(struct cl_hw *cl_hw)
{
	if (!cl_hw->single_cfm_virt_base_addr)
		return;

	chip_ops_free_coherent(cl_hw->chip, IPC_CFM_SIZE,
			       cl_hw->single_cfm_virt_base_addr,
			       cl_hw->single_cfm_dma_base_addr);

	cl_hw->single_cfm_dma_base_addr = 0;
	cl_hw->single_cfm_virt_base_addr = NULL;
}

static int dbg_info_alloc(struct cl_hw *cl_hw)
{
	/* Initialize the debug information buffer */
	if (_dbg_info_alloc(cl_hw)) {
		cl_dbg_verbose(cl_hw, "dbginfo allocation failed !!!\n");
		return -ENOMEM;
	}

	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_ipc_dbginfobuf_push(cl_hw->ipc_env, cl_hw->dbginfo.dma_addr);
	else
		cl_usb_dbginfobuf_push(cl_hw);
	return 0;
}

static void dbg_info_dealloc(struct cl_hw *cl_hw)
{
	if (!cl_hw->dbginfo.buf)
		return;

	chip_ops_free_coherent(cl_hw->chip,
			       cl_hw->dbginfo.bufsz,
			       cl_hw->dbginfo.buf,
			       cl_hw->dbginfo.dma_addr);

	cl_hw->dbginfo.buf = NULL;
}

static int cl_main_alloc(struct cl_hw *cl_hw)
{
	int ret;

	ret = cl_single_cfm_alloc(cl_hw);
	if (ret)
		return ret;

	ret = dbg_info_alloc(cl_hw);
	if (ret)
		return ret;

	ret = cl_phy_data_alloc(cl_hw);
	if (ret)
		return ret;

	ret = cl_calib_common_tables_alloc(cl_hw);
	if (ret)
		return ret;

	ret = cl_power_table_alloc(cl_hw);
	if (ret)
		return ret;

	ret = tx_queues_alloc(cl_hw);
	if (ret)
		return ret;

	ret = txdesc_alloc(cl_hw);
	if (ret)
		return ret;

	ret = write_idx_alloc(cl_hw);
	if (ret)
		return ret;

	ret = cl_tf_alloc(cl_hw);
	if (ret)
		return ret;

	ret = cl_bsr_alloc(cl_hw);
	if (ret)
		return ret;

	return ret;
}

static void cl_main_free(struct cl_hw *cl_hw)
{
	cl_bsr_free(cl_hw);
	cl_tf_free(cl_hw);
	write_idx_dealloc(cl_hw);
	txdesc_dealloc(cl_hw);
	tx_queues_dealloc(cl_hw);
	cl_power_table_free(cl_hw);
	cl_calib_common_tables_free(cl_hw);
	cl_phy_data_free(cl_hw);
	dbg_info_dealloc(cl_hw);
	cl_single_cfm_dealloc(cl_hw);
}

static void cl_free_hw(struct cl_hw *cl_hw)
{
	if (!cl_hw)
		return;

	cl_calib_db_free(cl_hw);
	cl_tcv_config_free(cl_hw);

	if (cl_hw->chip)
		cl_hw->chip->cl_hw_tcv0 = NULL;

	ieee80211_free_hw(cl_hw->hw);
}

static int cl_prepare_hw(struct cl_chip *chip, u8 tcv_idx)
{
	struct cl_hw *cl_hw = NULL;
	struct ieee80211_hw *hw;
	int ret;
	char name[NL80211_WIPHY_NAME_MAXLEN] = {0};

	snprintf(name, sizeof(name), "chip%u", chip->idx);

	hw = ieee80211_alloc_hw_nm(sizeof(struct cl_hw), &cl_ops, name);
	if (!hw) {
		cl_dbg_chip_err(chip, "ieee80211_alloc_hw failed\n");
		return -ENOMEM;
	}

	cl_hw = hw->priv;
	cl_hw->hw = hw;
	cl_hw->tcv_idx = tcv_idx;
	cl_hw->chip = chip;

	/*
	 * chip0, tcv0 --> 0
	 * chip0, tcv1 --> 1
	 * chip1, tcv0 --> 2
	 * chip1, tcv1 --> 3
	 * ...
	 */
	cl_hw->idx = chip->idx * TCV_MAX + tcv_idx;

	SET_IEEE80211_DEV(hw, chip->dev);

	ret = cl_tcv_config_alloc(cl_hw);
	if (ret)
		goto out_free_hw;

	ret = cl_tcv_config_read(cl_hw);
	if (ret)
		goto out_free_hw;

	ret = cl_calib_db_alloc(cl_hw);
	if (ret)
		goto out_free_hw;

	cl_hw->num_antennas = cl_hw->conf->ce_num_antennas;
	cl_hw->first_riu_chain = 0;
	cl_hw->last_riu_chain = cl_hw->num_antennas - 1;
	ret = cl_mac_addr_set(cl_hw);
	if (ret) {
		cl_dbg_err(cl_hw, "cl_mac_addr_set failed\n");
		goto out_free_hw;
	}

	if (cl_band_is_6g(cl_hw))
		cl_hw->nl_band = NL80211_BAND_6GHZ;
	else if (cl_band_is_5g(cl_hw))
		cl_hw->nl_band = NL80211_BAND_5GHZ;
	else
		cl_hw->nl_band = NL80211_BAND_2GHZ;

	cl_cap_dyn_params(cl_hw);
	cl_vendor_cmds_init(hw->wiphy);

	cl_main_set_cl_hw(chip, cl_hw);

	if (hw->wiphy->regulatory_flags & REGULATORY_WIPHY_SELF_MANAGED) {
		ret = regulatory_set_wiphy_regd(hw->wiphy, cl_hw->channel_info.rd);
		if (ret)
			cl_dbg_err(cl_hw, "regulatory failed\n");
	}

	cl_dbg_verbose(cl_hw, "cl_hw created\n");

	return 0;

out_free_hw:
	cl_free_hw(cl_hw);

	return ret;
}

void cl_main_off(struct cl_hw *cl_hw)
{
	if (IS_PCI_BUS_TYPE(cl_hw->chip)) {
		cl_irq_disable(cl_hw, cl_hw->ipc_e2a_irq.all);
		cl_ipc_stop(cl_hw);
	}

	if (!test_bit(CL_DEV_INIT, &cl_hw->drv_flags)) {
		cl_tx_off(cl_hw);
		cl_rx_off(cl_hw);
		cl_msg_rx_flush_all(cl_hw);
	}

	cl_fw_file_cleanup(cl_hw);
}

static int cl_main_ring_indices_init(struct cl_hw *cl_hw)
{
	struct cl_ring_indices *ring_indices = &cl_hw->ring_indices;

	ring_indices->pool = dma_pool_create("cl_ring_indices_pool", cl_hw->chip->dev,
					     (sizeof(struct cl_ipc_ring_indices) * TCV_MAX),
					     CL_ALIGN_BOUND_64KB, CL_ALIGN_BOUND_64KB);

	if (!ring_indices->pool) {
		cl_dbg_err(cl_hw, "ring_indices pool create failed !!!\n");
		return -ENOMEM;
	}

	ring_indices->params = dma_pool_alloc(ring_indices->pool, GFP_KERNEL,
					      &ring_indices->dma_addr);
	if (!ring_indices->params)
		return -ENOMEM;

	return 0;
}

static void cl_main_ring_indices_deinit(struct cl_hw *cl_hw)
{
	struct cl_ring_indices *ring_indices = &cl_hw->ring_indices;

	if (ring_indices->params) {
		dma_pool_free(ring_indices->pool,
			      ring_indices->params,
			      ring_indices->dma_addr);
		ring_indices->params = NULL;
	}

	dma_pool_destroy(ring_indices->pool);
	ring_indices->pool = NULL;
}

static void _cl_main_deinit(struct cl_hw *cl_hw)
{
	if (!cl_hw)
		return;

	cl_dbgfs_unregister(cl_hw);

	if (cl_hw->hw->wiphy->registered)
		ieee80211_unregister_hw(cl_hw->hw);

	cl_hw->is_stop_context = true;

	cl_drv_workqueue_destroy(cl_hw);

	if (cl_hw->chip->fw_test) {
		cl_main_off(cl_hw);
		/*
		 * In case of fw_test none of the following was initialized in __cl_main_init
		 * so we shouldn't call to deinit functions.
		 */
		goto out;
	}

	cl_noise_close(cl_hw);
	cl_maintenance_deinit(cl_hw);
	cl_vns_close(cl_hw);
	cl_rssi_assoc_exit(cl_hw);
	cl_radar_close(cl_hw);
	cl_age_out_close(cl_hw);
	cl_sounding_close(cl_hw);
	cl_chan_info_deinit(cl_hw);
	cl_wrs_api_close(cl_hw);
	cl_twt_close(cl_hw);
	cl_tx_inject_close(cl_hw);
	cl_main_off(cl_hw);
	cl_bsrp_close(cl_hw);
	cl_tf_close(cl_hw);
	/* These 2 must be called after cl_tx_off() (which is called from cl_main_off) */
	cl_tx_amsdu_txhdr_deinit(cl_hw);
	cl_sw_txhdr_deinit(cl_hw);
	cl_stats_deinit(cl_hw);
	cl_main_free(cl_hw);
	cl_fw_file_release(cl_hw);
	cl_vendor_timer_close(cl_hw);
out:
	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_ipc_deinit(cl_hw);
	else
		cl_usb_main_deinit(cl_hw);

	vfree(cl_hw->tx_queues);
	tasklet_kill(&cl_hw->rx_msg_tasklet);
}

void cl_main_deinit(struct cl_hw *cl_hw)
{
	if (!cl_hw)
		return;

	_cl_main_deinit(cl_hw);

	cl_temperature_close(cl_hw);
	cl_calib_iq_plan_deinit(cl_hw->chip);

	if (IS_PCI_BUS_TYPE(cl_hw->chip)) {
		cl_main_ring_indices_deinit(cl_hw);
		ipc_host_global_int_en_set(cl_hw->chip, 0);
		cl_irq_free(cl_hw->chip);
	}

	cl_free_hw(cl_hw);
}

static void _txdesc_reset(struct txdesc **txdesc, u32 desc_num)
{
	u32 size = (desc_num * sizeof(struct txdesc));

	memset(*txdesc, 0, size);
}

static void txdesc_reset(struct cl_hw *cl_hw)
{
	struct cl_ipc_tx_queues *tx_queues = &cl_hw->ipc_tx_queues;
	u32 i;

	_txdesc_reset(&tx_queues->ipc_txdesc_bcmc, IPC_TXDESC_CNT_BCMC);

	for (i = 0; i < MAX_SINGLE_QUEUES; i++)
		_txdesc_reset(&tx_queues->ipc_txdesc_single[i], IPC_TXDESC_CNT_SINGLE);

	for (i = 0; i < IPC_MAX_BA_SESSIONS; i++)
		_txdesc_reset(&tx_queues->ipc_txdesc_agg[i], TXDESC_AGG_Q_SIZE_MAX);
}

static void write_idx_reset(struct cl_hw *cl_hw)
{
	memset(cl_hw->ipc_write_idx.txdesc_write_idx, 0,
	       sizeof(struct cl_txdesc_write_idx));
}

static void cl_single_cfm_reset(struct cl_hw *cl_hw)
{
	cl_hw->single_cfm_read_idx = 0;
	cl_hw->single_cfm_write_idx = 0;
	memset(cl_hw->single_cfm_virt_base_addr, 0, IPC_CFM_SIZE);
}

static void dbg_info_reset(struct cl_hw *cl_hw)
{
	struct dbg_info *buf = cl_hw->dbginfo.buf;

	memset(buf, 0, sizeof(struct dbg_info));
	buf->u.type = DBG_INFO_UNSET;

	if (IS_PCI_BUS_TYPE(cl_hw->chip))
		cl_ipc_dbginfobuf_push(cl_hw->ipc_env, cl_hw->dbginfo.dma_addr);
	else
		cl_usb_dbginfobuf_push(cl_hw);
}

static int cl_main_shared_env_init(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_ipc_shared_env *shared_env = NULL;
	u32 addr = SHARED_RAM_START_ADDR;
	int size = sizeof(*shared_env);
	u8 *data;
	int error = 0;

	shared_env = kzalloc(sizeof(*shared_env), GFP_KERNEL);
	if (!shared_env) {
		cl_dbg_verbose(cl_hw, "shared RAM alloc failed !!!\n");
		return -ENOMEM;
	}

	if (IS_PCI_BUS_TYPE(chip)) {
		shared_env->usb_umac_env.idma_allocation =
				cpu_to_le32(DEFAULT_IDMA_ALLOCATION_VALUE);
		data = (u8 *)shared_env;
	} else {
		addr += sizeof(struct usb_umac_env_tag);
		size -= sizeof(struct usb_umac_env_tag);
		data = (u8 *)shared_env + sizeof(struct usb_umac_env_tag);
	}

	shared_env->la_enable = is_la_enabled(chip);
	shared_env->max_retry = chip->conf->ce_production_mode ? 0 :
				cpu_to_le16(cl_hw->conf->ce_max_retry);
	shared_env->lft_limit_ms = cpu_to_le16(CL_TX_LIFETIME_MS);
	shared_env->phy_dev = cpu_to_le16(chip->conf->ci_phy_dev);
	shared_env->bus_type = chip->bus_type;

	error = chip_ops_write_bulk(chip, addr, data, size);
	if (error)
		cl_dbg_verbose(cl_hw, "chip_ops_write_bulk failed %d !!!\n",
			       error);

	kfree(shared_env);

	return error;
}

int cl_main_on(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *chip_conf = chip->conf;
	int ret;
	u32 regval;

	cl_hw->fw_active = false;

	cl_txq_init(cl_hw);

	cl_hw_assert_info_init(cl_hw);

	if (cl_recovery_in_progress(cl_hw))
		chip_reset(chip,
			   LMAC_OCD_HALT_ON_RESET,
			   LMAC_DRESET,
			   LMAC_RUN_STALL,
			   LMAC_BRESET,
			   LMAC_DEBUG_ENABLE);

	ret = cl_fw_file_load(cl_hw);
	if (ret) {
		cl_dbg_err(cl_hw, "cl_fw_file_load failed %d\n", ret);
		return ret;
	}

	/* Clear CL_DEV_FW_ERROR after firmware loaded */
	clear_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags);

	/* Add pre FW test support - Input data per test */
	if (chip->fw_test)
		cl_fw_test_pre(cl_hw, chip_conf->ce_lmac, chip_conf->ce_umac, chip_conf->ce_smac);

	if (cl_recovery_in_progress(cl_hw)) {
		ret = cl_main_shared_env_init(cl_hw);
		if (ret) {
			cl_dbg_err(cl_hw,
				   "cl_main_shared_env_init failed %d\n", ret);
			return ret;
		}

		cl_single_cfm_reset(cl_hw);
		dbg_info_reset(cl_hw);
		txdesc_reset(cl_hw);
		write_idx_reset(cl_hw);

		if (IS_PCI_BUS_TYPE(chip))
			cl_ipc_recovery(cl_hw);
	}
	regval = macsys_gcu_xt_control_get(chip);

	/* Set lmac to run */
	if (cl_hw->fw_active)
		regval &= ~LMAC_RUN_STALL;

	/* Set smac to run */
	if (chip->smac_active)
		regval &= ~SMAC_RUN_STALL;

	/* Set umac to run in case of fw_test */
	if (chip->umac_active && chip->fw_test)
		regval &= ~UMAC_RUN_STALL;

	if (IS_PCI_BUS_TYPE(chip)) {
		/* Ack all possibly pending IRQs */
		ipc_xmac_2_host_ack_set(chip, cl_hw->ipc_e2a_irq.all);
		if (chip->smac_active)
			ipc_xmac_2_host_ack_set(chip, IPC_IRQ_S2H_ALL);
	}

	if (cl_recovery_in_progress(cl_hw) && IS_USB_BUS_TYPE(chip)) {
		chip_ops_usb_set_alternate(chip, USB_WIFI_IF_NUM, ALT_RUN);
		cl_usb_main_init(cl_hw);
	}

	macsys_gcu_xt_control_set(chip, regval);

	if (IS_PCI_BUS_TYPE(chip)) {
		cl_irq_enable(cl_hw, cl_hw->ipc_e2a_irq.all);
		if (chip->smac_active)
			cl_irq_enable(cl_hw, IPC_IRQ_S2H_ALL);
	}

	if (chip->fw_test)
		return 0;

	/*
	 * rx_mm_fw_sync_ind will set CL_DEV_FW_SYNC upon MM_FW_SYNC_IND
	 * (indicate successful FW load)
	 */
	ret = wait_event_interruptible_timeout(cl_hw->fw_sync_wq,
					       test_and_clear_bit(CL_DEV_FW_SYNC,
								  &cl_hw->drv_flags),
					       msecs_to_jiffies(5000));

	if (ret == 0) {
		pr_err("[%s]: FW synchronization timeout.\n", __func__);
		cl_hw_assert_check(cl_hw);
		ret = -ETIMEDOUT;
		goto out_free_cached_fw;
	} else if (ret == -ERESTARTSYS) {
		goto out_free_cached_fw;
	}

	return 0;

out_free_cached_fw:
	if (IS_PCI_BUS_TYPE(chip))
		cl_irq_disable(cl_hw, cl_hw->ipc_e2a_irq.all);
	cl_fw_file_release(cl_hw);
	return ret;
}

static void cl_main_e2a_irq_init(struct cl_hw *cl_hw)
{
	struct cl_ipc_e2a_irq *ipc_e2a_irq = &cl_hw->ipc_e2a_irq;

	ipc_e2a_irq->dbg = IPC_IRQ_L2H_DBG;
	ipc_e2a_irq->msg = IPC_IRQ_L2H_MSG;
	ipc_e2a_irq->rxdesc = IPC_IRQ_L2H_RXDESC;
	ipc_e2a_irq->txcfm = IPC_IRQ_L2H_TXCFM;
	ipc_e2a_irq->radar = IPC_IRQ_L2H_RADAR;
	ipc_e2a_irq->tbtt = IPC_IRQ_L2H_TBTT;
	ipc_e2a_irq->all = IPC_IRQ_L2H_ALL;
}

static int __cl_main_init(struct cl_hw *cl_hw)
{
	int ret;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *chip_conf = chip->conf;

	set_bit(CL_DEV_INIT, &cl_hw->drv_flags);

	/*
	 * Initialize umh_last_call_timestamp to current time minus (ci_umh_diff_time_ms + 1),
	 * so that if assert happens Immediately cl_umh.sh will be called.
	 */
	cl_hw->umh_last_call_timestamp = jiffies - cl_hw->conf->ci_umh_diff_time_ms - 1;

	/* IGMP */
	cl_hw->igmp_debug_level = DBG_LVL_ERROR;

	cl_hw->radio_stats_start_time = ktime_get_real_seconds();
	cl_hw->radio_max_noise_floor = -200;

	cl_vif_init(cl_hw);

	cl_drv_workqueue_create(cl_hw);

	init_waitqueue_head(&cl_hw->wait_queue);
	init_waitqueue_head(&cl_hw->fw_sync_wq);
	init_waitqueue_head(&cl_hw->radio_wait_queue);

	mutex_init(&cl_hw->dbginfo.mutex);
	mutex_init(&cl_hw->msg_tx_mutex);
	mutex_init(&cl_hw->set_channel_mutex);

	spin_lock_init(&cl_hw->tx_lock_agg);
	spin_lock_init(&cl_hw->tx_lock_cfm_agg);
	spin_lock_init(&cl_hw->tx_lock_single);
	spin_lock_init(&cl_hw->tx_lock_bcmc);
	spin_lock_init(&cl_hw->rx_msg_lock);
	spin_lock_init(&cl_hw->dbg_msg_lock);
	INIT_LIST_HEAD(&cl_hw->rx_msg_head);
	INIT_LIST_HEAD(&cl_hw->dbg_msg_head);
	INIT_LIST_HEAD(&cl_hw->single_pkt_req_msg_head);
	INIT_LIST_HEAD(&cl_hw->agg_pkt_req_msg_head);
	tasklet_init(&cl_hw->rx_msg_tasklet,
		     cl_msg_rx_tasklet,
		     (unsigned long)cl_hw);

	ret = cl_main_shared_env_init(cl_hw);
	if (ret) {
		cl_dbg_err(cl_hw, "cl_main_shared_env_init failed %d\n", ret);
		return ret;
	}

	if (IS_PCI_BUS_TYPE(chip)) {
		ret = cl_ipc_init(cl_hw);
		if (ret) {
			cl_dbg_err(cl_hw, "cl_ipc_init failed %d\n", ret);
			return ret;
		}
	} else {
		ret = cl_usb_main_init(cl_hw);
		if (ret) {
			cl_dbg_err(cl_hw, "cl_usb_init failed %d\n", ret);
			return ret;
		}
	}
	cl_main_e2a_irq_init(cl_hw);
	cl_hw->ipc_host2xmac_trigger_set = ipc_host_2_lmac_trigger_set;

	cl_hw->tx_queues = vzalloc(sizeof(*cl_hw->tx_queues));
	if (!cl_hw->tx_queues) {
		if (IS_PCI_BUS_TYPE(chip))
			cl_ipc_deinit(cl_hw);
		else
			cl_usb_main_deinit(cl_hw);
		return -ENOMEM;
	}

	ret = cl_main_on(cl_hw);
	if (ret) {
		cl_dbg_err(cl_hw, "cl_main_on failed %d\n", ret);
		if (IS_PCI_BUS_TYPE(chip))
			cl_ipc_deinit(cl_hw);
		else
			cl_usb_main_deinit(cl_hw);
		vfree(cl_hw->tx_queues);
		return ret;
	}

	/*
	 * In case fw_test is set, need to exit right after calling cl_fw_test_apre().
	 * No need to 'goto out_free'
	 */
	if (chip->fw_test) {
		/* Add apre FW test support - Output analysis */
		cl_fw_test_apre(cl_hw, chip_conf->ce_lmac, chip_conf->ce_umac, chip_conf->ce_smac);
		return ret;
	}

	ret = cl_main_alloc(cl_hw);
	if (ret)
		goto out_free;

	cl_calibration_power_read(cl_hw);
	cl_sta_init(cl_hw);
	cl_sw_txhdr_init(cl_hw);
	cl_tx_amsdu_txhdr_init(cl_hw);
	cl_rx_init(cl_hw);
	cl_prot_mode_init(cl_hw);
	cl_radar_init(cl_hw);
	cl_sounding_init(cl_hw);
	cl_vlan_dscp_init(cl_hw);
	cl_env_det_init(cl_hw);
	cl_traffic_init(cl_hw);
	cl_age_out_init(cl_hw);
	cl_vns_init(cl_hw);
	cl_maintenance_init(cl_hw);
	cl_rx_sens_init(cl_hw);
	cl_rssi_assoc_init(cl_hw);
	cl_agg_cfm_init(cl_hw);
	cl_single_cfm_init(cl_hw);
	cl_bcmc_cfm_init(cl_hw);
	cl_dyn_mcast_rate_init(cl_hw);
	cl_dyn_bcast_rate_init(cl_hw);
	cl_wrs_api_init(cl_hw);
	cl_tx_inject_init(cl_hw);
	cl_noise_init(cl_hw);
	cl_twt_init(cl_hw);
	cl_bsrp_init(cl_hw);
	cl_tf_init(cl_hw);
	cl_fw_dbg_trigger_based_init(cl_hw);
	cl_stats_init(cl_hw);
	cl_ul_rssi_init(cl_hw);
	cl_vendor_timer_init(cl_hw);

	if (cl_hw->chip->conf->ce_calib_runtime_en &&
	    cl_hw->chip->conf->ce_calib_runtime_write_to_files_en)
		cl_calib_runtime_create_calib_files(cl_hw);

	/*
	 * ieee80211_register_hw() will take care of calling wiphy_register() and
	 * also ieee80211_if_add() (because IFTYPE_STATION is supported)
	 * which will internally call register_netdev()
	 */
	ret = ieee80211_register_hw(cl_hw->hw);
	if (ret) {
		cl_dbg_err(cl_hw, "ieee80211_register_hw failed\n");
		goto out_free;
	}

	/* Keep last (userpsace use it as indication for main init finish) */
	cl_dbgfs_register(cl_hw, "cl");

	return 0;

out_free:
	cl_main_free(cl_hw);
	vfree(cl_hw->tx_queues);

	return ret;
}

static int _cl_main_init(struct cl_chip *chip, struct cl_hw *cl_hw)
{
	int ret = 0;

	if (!cl_hw)
		return ret;

	if (cl_chip_is_tcv_enabled(chip, cl_hw->tcv_idx)) {
		ret = __cl_main_init(cl_hw);
		if (ret) {
			cl_dbg_chip_err(chip, "TCV%u failed (%d)\n", cl_hw->tcv_idx, ret);
			return ret;
		}
	} else {
		ieee80211_unregister_hw(cl_hw->hw);
	}

	return ret;
}

int cl_main_init(struct cl_chip *chip)
{
	int ret;
	struct cl_chip_conf *conf = chip->conf;

	ret = cl_e2p_init(chip);
	if (ret) {
		cl_dbg_chip_err(chip, "cl_e2p_init failed %d\n", ret);
		return ret;
	}

	ret = cl_otp_init(chip);
	if (ret) {
		cl_dbg_chip_err(chip, "cl_otp_init failed %d\n", ret);
		return ret;
	}

	ret = cl_prepare_hw(chip, TCV0);
	if (ret) {
		cl_dbg_chip_err(chip, "cl_prepare_hw for TCV0 failed %d\n",
				ret);
		return ret;
	}

	if (IS_PCI_BUS_TYPE(chip)) {
		ret = cl_irq_request(chip);
		if (ret)
			goto out;
		ipc_host_global_int_en_set(chip, 1);
	}

	cl_calib_iq_plan_init(chip);

	ret = cl_calib_common_read_files(chip);
	if (ret) {
		cl_dbg_chip_err(chip, "Read calibration files failed %d\n", ret);

		return ret;
	}
	/* If runtime calibration is enabled and write to files is enabled */
	if (conf->ce_calib_runtime_en &&
	    conf->ce_calib_runtime_write_to_files_en) {
		cl_calib_iq_file_flags_set(chip);
		chip->cl_hw_tcv0->calib_db->file_flags.dcoc = CALIB_FLAG_ALL;
		chip->cl_hw_tcv0->calib_db->file_flags.dcoc_report = CALIB_FLAG_ALL_REPORT;
		chip->cl_hw_tcv0->calib_db->file_flags.bt_dcoc = CALIB_FLAG_ALL;
		chip->cl_hw_tcv0->calib_db->file_flags.bt_dcoc_report = CALIB_FLAG_ALL_REPORT;
	}

	cl_temperature_init(chip->cl_hw_tcv0);

	if (IS_PCI_BUS_TYPE(chip)) {
		ret = cl_main_ring_indices_init(chip->cl_hw_tcv0);
		if (ret)
			goto out;
	}

	cl_wrs_tables_global_build();
	cl_ul_length_table_init();
	cl_data_rates_inverse_build();

	if (!conf->ci_phy_load_bootdrv &&
	    conf->ci_phy_dev != PHY_DEV_DUMMY) {
		ret = cl_dsp_load(chip);
		if (ret) {
			cl_dbg_chip_err(chip, "cl_dsp_load failed %d\n", ret);
			goto out;
		}
	}

	ret = _cl_main_init(chip, chip->cl_hw_tcv0);
	if (ret)
		goto out;

	return ret;

 out:
	cl_free_hw(chip->cl_hw_tcv0);

	return ret;
}

static int cl_main_module_init(void)
{
	int ret;

	ret = cl_pci_init();
	if (ret)
		return ret;

	ret = cl_usb_init();
	if (ret) {
		cl_pci_exit();

		return ret;
	}

	return 0;
}
module_init(cl_main_module_init);

static void cl_main_module_exit(void)
{
	cl_pci_exit();
	cl_usb_exit();
}
module_exit(cl_main_module_exit);
