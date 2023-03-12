// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/dma-mapping.h>
#include <linux/dmapool.h>

#include "cl_ipc.h"
#include "cl_rx.h"
#include "cl_rx_pci.h"
#include "cl_tx.h"
#include "cl_utils.h"
#include "cl_tx_pci.h"
#include "cl_irq.h"
#include "reg_access.h"
#include "cl_enhanced_tim.h"
#include "cl_dbgfile.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif

static void ipc_env_free(struct cl_hw *cl_hw)
{
	kfree(cl_hw->ipc_env);
	cl_hw->ipc_env = NULL;
}

static void ring_indices_dealloc(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;

	if (!ipc_env->ring_indices_elem)
		return;

	memset(ipc_env->ring_indices_elem->indices, 0, sizeof(struct cl_ipc_ring_indices));
	ipc_env->ring_indices_elem->indices = NULL;
	kfree(ipc_env->ring_indices_elem);
	ipc_env->ring_indices_elem = NULL;
}

static void rx_dealloc_skb(struct cl_hw *cl_hw, struct cl_rx_elem *rx_elem,
			   u16 len)
{
	dma_unmap_single(cl_hw->chip->dev, rx_elem->dma_addr, len,
			 DMA_FROM_DEVICE);
	kfree_skb(rx_elem->skb);
	rx_elem->skb = NULL;
}

static void _rx_dealloc_buff(struct cl_hw *cl_hw,
			     u32 *rxbuf,
			     __le32 dma_addr,
			     u32 desc_num)
{
	dma_addr_t phys_dma_addr = le32_to_cpu(dma_addr);
	u32 size = (desc_num * sizeof(u32));

	chip_ops_free_coherent(cl_hw->chip, size, rxbuf, phys_dma_addr);
}

static void rx_dealloc_buff(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_ipc_host_rxbuf *rxbuf_rxm = &ipc_env->rx_hostbuf_array[CL_RX_BUF_RXM];
	struct cl_ipc_host_rxbuf *rxbuf_fw = &ipc_env->rx_hostbuf_array[CL_RX_BUF_FW];

	if (rxbuf_rxm->dma_payload_base_addr)
		_rx_dealloc_buff(cl_hw,
				 rxbuf_rxm->dma_payload_addr,
				 rxbuf_rxm->dma_payload_base_addr,
				 IPC_RXBUF_CNT_RXM);

	if (rxbuf_fw->dma_payload_base_addr)
		_rx_dealloc_buff(cl_hw,
				 rxbuf_fw->dma_payload_addr,
				 rxbuf_fw->dma_payload_base_addr,
				 IPC_RXBUF_CNT_FW);
}

static void rx_dealloc(struct cl_hw *cl_hw)
{
	struct cl_rx_elem *rx_elem = cl_hw->rx_elems;
	u16 rxbuf_size_rxm = cl_hw->conf->ci_ipc_rxbuf_size[CL_RX_BUF_RXM];
	u16 rxbuf_size_fw = cl_hw->conf->ci_ipc_rxbuf_size[CL_RX_BUF_FW];
	int i;

	if (!cl_hw->rx_elems)
		return;

	for (i = 0; i < IPC_RXBUF_CNT_RXM; i++, rx_elem++)
		if (rx_elem->skb && !rx_elem->passed)
			rx_dealloc_skb(cl_hw, rx_elem, rxbuf_size_rxm);

	for (i = 0; i < IPC_RXBUF_CNT_FW; i++, rx_elem++)
		if (rx_elem->skb && !rx_elem->passed)
			rx_dealloc_skb(cl_hw, rx_elem, rxbuf_size_fw);

	kfree(cl_hw->rx_elems);
	cl_hw->rx_elems = NULL;

	rx_dealloc_buff(cl_hw);
}

static void msg_dealloc(struct cl_hw *cl_hw)
{
	struct cl_e2a_msg_elem *msg_elem;
	int i;

	if (!cl_hw->e2a_msg_elems || !cl_hw->e2a_msg_pool)
		return;

	for (i = 0, msg_elem = cl_hw->e2a_msg_elems;
	     i < IPC_E2A_MSG_BUF_CNT; i++, msg_elem++) {
		if (msg_elem->msgbuf_ptr) {
			dma_pool_free(cl_hw->e2a_msg_pool, msg_elem->msgbuf_ptr,
				      msg_elem->dma_addr);
			msg_elem->msgbuf_ptr = NULL;
		}
	}

	dma_pool_destroy(cl_hw->e2a_msg_pool);
	cl_hw->e2a_msg_pool = NULL;

	kfree(cl_hw->e2a_msg_elems);
	cl_hw->e2a_msg_elems = NULL;
}

static void radar_dealloc(struct cl_hw *cl_hw)
{
	struct cl_radar_elem *radar_elem;
	int i;

	if (!cl_hw->radar_pool || !cl_hw->radar_elems)
		return;

	for (i = 0, radar_elem = cl_hw->radar_elems;
	     i < IPC_RADAR_BUF_CNT; i++, radar_elem++) {
		if (radar_elem->radarbuf_ptr) {
			dma_pool_free(cl_hw->radar_pool, radar_elem->radarbuf_ptr,
				      radar_elem->dma_addr);
			radar_elem->radarbuf_ptr = NULL;
		}
	}

	dma_pool_destroy(cl_hw->radar_pool);
	cl_hw->radar_pool = NULL;

	kfree(cl_hw->radar_elems);
	cl_hw->radar_elems = NULL;
}

static void dbg_dealloc(struct cl_hw *cl_hw)
{
	struct cl_dbg_elem *dbg_elem;
	int i;

	if (!cl_hw->dbg_pool || !cl_hw->dbg_elems)
		return;

	for (i = 0, dbg_elem = cl_hw->dbg_elems;
	     i < IPC_DBG_BUF_CNT; i++, dbg_elem++) {
		if (dbg_elem->dbgbuf_ptr) {
			dma_pool_free(cl_hw->dbg_pool, dbg_elem->dbgbuf_ptr,
				      dbg_elem->dma_addr);
			dbg_elem->dbgbuf_ptr = NULL;
		}
	}

	dma_pool_destroy(cl_hw->dbg_pool);
	cl_hw->dbg_pool = NULL;

	kfree(cl_hw->dbg_elems);
	cl_hw->dbg_elems = NULL;
}

static void ipc_elems_dealloc(struct cl_hw *cl_hw)
{
	ring_indices_dealloc(cl_hw);
	rx_dealloc(cl_hw);
	msg_dealloc(cl_hw);
	radar_dealloc(cl_hw);
	dbg_dealloc(cl_hw);
}

static int ring_indices_alloc(struct cl_hw *cl_hw)
{
	struct cl_ring_indices *ring_indices = &cl_hw->ring_indices;
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;

	ipc_env->ring_indices_elem = kzalloc(sizeof(*ipc_env->ring_indices_elem), GFP_KERNEL);

	if (!ipc_env->ring_indices_elem)
		return -ENOMEM;

	ipc_env->ring_indices_elem->indices = ring_indices->params;
	ipc_env->ring_indices_elem->dma_addr = ring_indices->dma_addr;

	memset(ipc_env->ring_indices_elem->indices, 0, sizeof(struct cl_ipc_ring_indices));

	return 0;
}

static int rx_skb_alloc(struct cl_hw *cl_hw)
{
	/*
	 * This function allocates Rx elements for DMA
	 * transfers and pushes the DMA address to FW.
	 */
	struct cl_rx_elem *rx_elem = cl_hw->rx_elems;
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	int i = 0;
	u16 rxbuf_size_rxm = cl_hw->conf->ci_ipc_rxbuf_size[CL_RX_BUF_RXM];
	u16 rxbuf_size_fw = cl_hw->conf->ci_ipc_rxbuf_size[CL_RX_BUF_FW];

	/* Allocate and push RXM buffers */
	for (i = 0; i < IPC_RXBUF_CNT_RXM; rx_elem++, i++) {
		if (cl_ipc_rx_elem_alloc(cl_hw, rx_elem, rxbuf_size_rxm)) {
			cl_dbg_verbose(cl_hw, "RXM rx_elem allocation failed !!!\n");
			return -ENOMEM;
		}
		cl_ipc_rxbuf_push(ipc_env, rx_elem, i, i, CL_RX_BUF_RXM);
	}

	/* Allocate and push FW buffers */
	for (i = 0; i < IPC_RXBUF_CNT_FW; rx_elem++, i++) {
		if (cl_ipc_rx_elem_alloc(cl_hw, rx_elem, rxbuf_size_fw)) {
			cl_dbg_verbose(cl_hw, "FW rx_elem allocation failed !!!\n");
			return -ENOMEM;
		}
		cl_ipc_rxbuf_push(ipc_env, rx_elem, i, i, CL_RX_BUF_FW);
	}

	return 0;
}

static int _rx_buf_alloc(struct cl_hw *cl_hw, u32 **rxbuf,
			 __le32 *dma_addr, u32 desc_num)
{
	dma_addr_t phys_dma_addr;
	u32 size = (desc_num * sizeof(u32));

	*rxbuf = chip_ops_alloc_coherent(cl_hw->chip, size,
					 GFP_KERNEL, &phys_dma_addr);

	if (!(*rxbuf))
		return -ENOMEM;

	*dma_addr = cpu_to_le32(phys_dma_addr);
	memset(*rxbuf, 0, size);

	return 0;
}

static int rx_buf_alloc(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_ipc_host_rxbuf *rxbuf_rxm = &ipc_env->rx_hostbuf_array[CL_RX_BUF_RXM];
	struct cl_ipc_host_rxbuf *rxbuf_fw = &ipc_env->rx_hostbuf_array[CL_RX_BUF_FW];
	int ret = 0;

	rxbuf_rxm->ipc_host_rxdesc_ptr = ipc_env->ipc_host_rxdesc_rxm;
	rxbuf_fw->ipc_host_rxdesc_ptr = ipc_env->ipc_host_rxdesc_fw;

	/* Allocate RXM RX write/read indexes */
	ret = _rx_buf_alloc(cl_hw,
			    (u32 **)&rxbuf_rxm->dma_payload_addr,
			    &rxbuf_rxm->dma_payload_base_addr,
			    IPC_RXBUF_CNT_RXM);
	if (ret)
		return ret;

	/* Allocate FW RX write/read indexes */
	ret = _rx_buf_alloc(cl_hw,
			    (u32 **)&rxbuf_fw->dma_payload_addr,
			    &rxbuf_fw->dma_payload_base_addr,
			    IPC_RXBUF_CNT_FW);
	if (ret)
		return ret;

	return 0;
}

static int rx_alloc(struct cl_hw *cl_hw)
{
	u32 total_rx_elems = IPC_RXBUF_CNT_RXM + IPC_RXBUF_CNT_FW;
	u32 alloc_size = total_rx_elems * sizeof(struct cl_rx_elem);
	int ret = rx_buf_alloc(cl_hw);

	if (ret)
		return ret;

	cl_hw->rx_elems = kzalloc(alloc_size, GFP_KERNEL);

	if (!cl_hw->rx_elems)
		return -ENOMEM;

	return rx_skb_alloc(cl_hw);
}

static int _msg_alloc(struct cl_hw *cl_hw, struct cl_e2a_msg_elem *msg_elem)
{
	dma_addr_t dma_addr;
	struct cl_ipc_e2a_msg *msg;

	/* Initialize the message pattern to NULL */
	msg = dma_pool_alloc(cl_hw->e2a_msg_pool, GFP_KERNEL, &dma_addr);
	if (!msg)
		return -ENOMEM;

	msg->pattern = 0;

	/* Save the msg pointer (for deallocation) and the dma_addr */
	msg_elem->msgbuf_ptr = msg;
	msg_elem->dma_addr = dma_addr;

	return 0;
}

static int msg_alloc(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_e2a_msg_elem *msg_elem;
	u32 alloc_size = IPC_E2A_MSG_BUF_CNT * sizeof(struct cl_e2a_msg_elem);
	u32 i;

	cl_hw->e2a_msg_elems = kzalloc(alloc_size, GFP_KERNEL);

	if (!cl_hw->e2a_msg_elems)
		return -ENOMEM;

	cl_hw->e2a_msg_pool = dma_pool_create("dma_pool_msg",
					      cl_hw->chip->dev,
					      sizeof(struct cl_ipc_e2a_msg),
					      cache_line_size(),
					      0);

	if (!cl_hw->e2a_msg_pool) {
		cl_dbg_verbose(cl_hw, "dma_pool_create failed !!!\n");
		return -ENOMEM;
	}

	/* Initialize the msg buffers in the global IPC array. */
	for (i = 0, msg_elem = cl_hw->e2a_msg_elems;
	     i < IPC_E2A_MSG_BUF_CNT; msg_elem++, i++) {
		if (_msg_alloc(cl_hw, msg_elem)) {
			cl_dbg_verbose(cl_hw, "msg allocation failed !!!\n");
			return -ENOMEM;
		}

		cl_ipc_msgbuf_push(ipc_env, (ptrdiff_t)msg_elem, msg_elem->dma_addr);
	}

	return 0;
}

static int _radar_alloc(struct cl_hw *cl_hw, struct cl_radar_elem *radar_elem)
{
	dma_addr_t dma_addr;
	struct cl_radar_pulse_array *radar;

	/* Initialize the message pattern to NULL */
	radar = dma_pool_alloc(cl_hw->radar_pool, GFP_KERNEL, &dma_addr);
	if (!radar)
		return -ENOMEM;

	radar->cnt = 0;

	/* Save the msg pointer (for deallocation) and the dma_addr */
	radar_elem->radarbuf_ptr = radar;
	radar_elem->dma_addr = dma_addr;

	return 0;
}

static int radar_alloc(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_radar_elem *radar_elem;
	u32 alloc_size = IPC_RADAR_BUF_CNT * sizeof(struct cl_radar_elem);
	u32 i;

	cl_hw->radar_elems = kzalloc(alloc_size, GFP_KERNEL);

	if (!cl_hw->radar_elems)
		return -ENOMEM;

	cl_hw->radar_pool = dma_pool_create("dma_pool_radar",
					    cl_hw->chip->dev,
					    sizeof(struct cl_radar_pulse_array),
					    cache_line_size(),
					    0);

	if (!cl_hw->radar_pool) {
		cl_dbg_verbose(cl_hw, "dma_pool_create failed !!!\n");
		return -ENOMEM;
	}

	/* Initialize the radar buffers in the global IPC array. */
	for (i = 0, radar_elem = cl_hw->radar_elems;
	     i < IPC_RADAR_BUF_CNT; radar_elem++, i++) {
		if (_radar_alloc(cl_hw, radar_elem)) {
			cl_dbg_verbose(cl_hw, "radar allocation failed !!!\n");
			return -ENOMEM;
		}

		cl_ipc_radarbuf_push(ipc_env, (ptrdiff_t)radar_elem, radar_elem->dma_addr);
	}

	return 0;
}

static int _dbg_alloc(struct cl_hw *cl_hw, struct cl_dbg_elem *dbg_elem)
{
	dma_addr_t dma_addr;
	struct cl_ipc_dbg_msg *dbg_msg;

	dbg_msg = dma_pool_alloc(cl_hw->dbg_pool, GFP_KERNEL, &dma_addr);
	if (!dbg_msg)
		return -ENOMEM;

	dbg_msg->pattern = 0;

	/* Save the Debug msg pointer (for deallocation) and the dma_addr */
	dbg_elem->dbgbuf_ptr = dbg_msg;
	dbg_elem->dma_addr = dma_addr;

	return 0;
}

static int dbg_alloc(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_dbg_elem *dbg_elem;
	u32 alloc_size = IPC_DBG_BUF_CNT * sizeof(struct cl_dbg_elem);
	u32 i;

	cl_hw->dbg_elems = kzalloc(alloc_size, GFP_KERNEL);

	if (!cl_hw->dbg_elems)
		return -ENOMEM;

	cl_hw->dbg_pool = dma_pool_create("dma_pool_dbg",
					  cl_hw->chip->dev,
					  sizeof(struct cl_ipc_dbg_msg),
					  cache_line_size(),
					  0);

	if (!cl_hw->dbg_pool) {
		cl_dbg_verbose(cl_hw, "dma_pool_create failed !!!\n");
		return -ENOMEM;
	}

	/* Initialize the dbg buffers in the global IPC array. */
	for (i = 0, dbg_elem = cl_hw->dbg_elems;
	     i < IPC_DBG_BUF_CNT; dbg_elem++, i++) {
		if (_dbg_alloc(cl_hw, dbg_elem)) {
			cl_dbg_verbose(cl_hw, "dbgelem allocation failed !!!\n");
			return -ENOMEM;
		}

		cl_ipc_dbgbuf_push(ipc_env, (ptrdiff_t)dbg_elem, dbg_elem->dma_addr);
	}

	return 0;
}

static int ipc_elems_alloc(struct cl_hw *cl_hw)
{
	/* Allocate all the elements required for communications with firmware */
	if (ring_indices_alloc(cl_hw))
		goto out_err;

	if (rx_alloc(cl_hw))
		goto out_err;

	if (msg_alloc(cl_hw))
		goto out_err;

	if (radar_alloc(cl_hw))
		goto out_err;

	if (dbg_alloc(cl_hw))
		goto out_err;

	return 0;

out_err:
	ipc_elems_dealloc(cl_hw);
	return -ENOMEM;
}

static u8 cl_ipc_dbgfile_handler(struct cl_hw *cl_hw, ptrdiff_t hostid)
{
	struct cl_dbg_elem *dbg_elem = (struct cl_dbg_elem *)hostid;
	struct cl_ipc_dbg_msg *dbg_msg;
	u8 ret = 0;

	/* Retrieve the message structure */
	dbg_msg = (struct cl_ipc_dbg_msg *)dbg_elem->dbgbuf_ptr;

	if (!dbg_msg) {
		ret = -1;
		cl_dbg_err(cl_hw, "dbgbuf_ptr is NULL!!!!\n");
		goto dbg_push;
	}

	/* Look for pattern which means that this hostbuf has been used for a MSG */
	if (le32_to_cpu(dbg_msg->pattern) != IPC_DBG_VALID_PATTERN) {
		ret = -1;
		goto dbg_no_push;
	}

	/* Reset the msg element and re-use it */
	dbg_msg->pattern = 0;

	/* Display the firmware string */
	cl_dbgfile_print_fw_str(cl_hw, dbg_msg->string, IPC_DBG_PARAM_SIZE);

dbg_push:
	/* make sure memory is written before push to HW */
	wmb();

	/* Push back the buffer to the firmware */
	cl_ipc_dbgbuf_push(cl_hw->ipc_env, (ptrdiff_t)dbg_elem, dbg_elem->dma_addr);

dbg_no_push:
	return ret;
}

static void cl_ipc_dbgfile_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_ipc_hostbuf *dbg_array = ipc_env->dbg_hostbuf_array;
	int dbg_handled = 0;

#ifdef TRACE_SUPPORT
	trace_cl_trace_dbg_tasklet_start(cl_hw->idx);
#endif

	while (!cl_ipc_dbgfile_handler(cl_hw, dbg_array[ipc_env->dbg_host_idx].hostid))
		dbg_handled++;

#ifdef TRACE_SUPPORT
	trace_cl_trace_dbg_tasklet_end(cl_hw->idx, dbg_handled);
#endif

	/* Enable the DBG interrupt */
	if (!test_bit(CL_DEV_STOP_HW, &cl_hw->drv_flags))
		cl_irq_enable(cl_hw, cl_hw->ipc_e2a_irq.dbg);
}

static void ipc_tasklet_init(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;

	tasklet_init(&ipc_env->rxdesc_tasklet,
		     cl_rx_pci_desc_tasklet,
		     (unsigned long)cl_hw);
	tasklet_init(&cl_hw->dbg_tasklet,
		     cl_ipc_dbgfile_tasklet,
		     (unsigned long)cl_hw);
	tasklet_init(&cl_hw->tx_single_cfm_tasklet,
		     cl_tx_pci_single_cfm_tasklet,
		     (unsigned long)cl_hw);
}

static int ipc_env_init(struct cl_hw *cl_hw)
{
	u32 *dst;
	u32 i;

	BUILD_BUG_ON_NOT_POWER_OF_2(IPC_RXBUF_CNT_RXM);
	BUILD_BUG_ON_NOT_POWER_OF_2(IPC_RXBUF_CNT_FW);

	/* Allocate the IPC environment */
	cl_hw->ipc_env = kzalloc(sizeof(*cl_hw->ipc_env), GFP_KERNEL);

	if (!cl_hw->ipc_env)
		return -ENOMEM;

	dst = (u32 *)(cl_hw->ipc_env);

	/*
	 * Reset the IPC Host environment.
	 * Perform the reset word per word because memset() does
	 * not correctly reset all (due to misaligned accesses)
	 */
	for (i = 0; i < sizeof(struct cl_ipc_host_env); i += sizeof(u32))
		*dst++ = 0;

	return 0;
}

static void ipc_shared_env_init(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);
	struct cl_ipc_shared_env __iomem *shared_env =
		(struct cl_ipc_shared_env __iomem *)(chip_pci->bar0_virt_addr +
						     SHARED_RAM_START_ADDR);

	/* Initialize the shared environment pointer */
	ipc_env->shared = shared_env;
}

int cl_ipc_init(struct cl_hw *cl_hw)
{
	/*
	 * This function initializes IPC interface by registering callbacks, setting
	 * shared memory area and calling IPC Init function.
	 * This function should be called only once during driver's lifetime.
	 */
	int ret = ipc_env_init(cl_hw);

	if (ret)
		return ret;

	ipc_shared_env_init(cl_hw);

	ret = ipc_elems_alloc(cl_hw);
	if (ret) {
		ipc_env_free(cl_hw);
		return ret;
	}

	ipc_tasklet_init(cl_hw);

	return ret;
}

static void ring_indices_reset(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;

	memset(ipc_env->ring_indices_elem->indices, 0, sizeof(struct cl_ipc_ring_indices));

	/* Reset host desc read idx follower */
	ipc_env->host_rxdesc_read_idx[CL_RX_BUF_RXM] = 0;
	ipc_env->host_rxdesc_read_idx[CL_RX_BUF_FW] = 0;
}

static void rx_skb_reset(struct cl_hw *cl_hw)
{
	/*
	 * This function allocates Rx elements for DMA
	 * transfers and pushes the DMA address to FW.
	 */
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_rx_elem *rx_elem = cl_hw->rx_elems;
	int i = 0;

	/* Push RXM buffers */
	for (i = 0; i < IPC_RXBUF_CNT_RXM; rx_elem++, i++)
		cl_ipc_rxbuf_push(ipc_env, rx_elem, i, i, CL_RX_BUF_RXM);

	/* Push FW buffers */
	for (i = 0; i < IPC_RXBUF_CNT_FW; rx_elem++, i++)
		cl_ipc_rxbuf_push(ipc_env, rx_elem, i, i, CL_RX_BUF_FW);
}

static void _rx_buf_reset(u32 **rxbuf, u32 desc_num)
{
	u32 size = (desc_num * sizeof(u32));

	memset(*rxbuf, 0, size);
}

static void rx_buf_reset(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_ipc_host_rxbuf *rxbuf_rxm = &ipc_env->rx_hostbuf_array[CL_RX_BUF_RXM];
	struct cl_ipc_host_rxbuf *rxbuf_fw = &ipc_env->rx_hostbuf_array[CL_RX_BUF_FW];

	/* Reset RXM RX buffer */
	_rx_buf_reset((u32 **)&rxbuf_rxm->dma_payload_addr,
		      IPC_RXBUF_CNT_RXM);

	/* Reset FW RX buffer */
	_rx_buf_reset((u32 **)&rxbuf_fw->dma_payload_addr,
		      IPC_RXBUF_CNT_FW);
}

static void rx_reset(struct cl_hw *cl_hw)
{
	rx_buf_reset(cl_hw);
	rx_skb_reset(cl_hw);
}

static void msg_reset(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_e2a_msg_elem *msg_elem;
	u32 i;

	ipc_env->e2a_msg_host_idx = 0;

	/* Initialize the msg buffers in the global IPC array. */
	for (i = 0, msg_elem = cl_hw->e2a_msg_elems;
	     i < IPC_E2A_MSG_BUF_CNT; msg_elem++, i++) {
		msg_elem->msgbuf_ptr->pattern = 0;
		cl_ipc_msgbuf_push(ipc_env, (ptrdiff_t)msg_elem, msg_elem->dma_addr);
	}
}

static void radar_reset(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_radar_elem *radar_elem;
	u32 i;

	ipc_env->radar_host_idx = 0;

	/* Initialize the radar buffers in the global IPC array. */
	for (i = 0, radar_elem = cl_hw->radar_elems;
	     i < IPC_RADAR_BUF_CNT; radar_elem++, i++) {
		radar_elem->radarbuf_ptr->cnt = 0;
		cl_ipc_radarbuf_push(ipc_env, (ptrdiff_t)radar_elem, radar_elem->dma_addr);
	}
}

static void dbg_reset(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_dbg_elem *dbg_elem;
	u32 i;

	ipc_env->dbg_host_idx = 0;

	/* Initialize the dbg buffers in the global IPC array. */
	for (i = 0, dbg_elem = cl_hw->dbg_elems;
	     i < IPC_DBG_BUF_CNT; dbg_elem++, i++) {
		dbg_elem->dbgbuf_ptr->pattern = 0;
		cl_ipc_dbgbuf_push(ipc_env, (ptrdiff_t)dbg_elem, dbg_elem->dma_addr);
	}
}

static void ipc_elems_reset(struct cl_hw *cl_hw)
{
	ring_indices_reset(cl_hw);
	rx_reset(cl_hw);
	msg_reset(cl_hw);
	radar_reset(cl_hw);
	dbg_reset(cl_hw);
	cl_enhanced_tim_reset(cl_hw);
}

void cl_ipc_recovery(struct cl_hw *cl_hw)
{
	ipc_shared_env_init(cl_hw);
	ipc_elems_reset(cl_hw);
}

void cl_ipc_reset(struct cl_hw *cl_hw)
{
	iowrite32(0, (void __iomem *)&cl_hw->ipc_env->shared->cfm_read_pointer);
}

void cl_ipc_deinit(struct cl_hw *cl_hw)
{
	ipc_elems_dealloc(cl_hw);
	ipc_env_free(cl_hw);
}

void cl_ipc_stop(struct cl_hw *cl_hw)
{
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;

	tasklet_kill(&ipc_env->rxdesc_tasklet);
	tasklet_kill(&cl_hw->dbg_tasklet);
	tasklet_kill(&cl_hw->tx_single_cfm_tasklet);
}

int cl_ipc_rx_elem_alloc(struct cl_hw *cl_hw, struct cl_rx_elem *rx_elem, u32 size)
{
	struct sk_buff *skb;
	dma_addr_t dma_addr;
	struct hw_rxhdr *rxhdr;

	rx_elem->passed = 0;

	skb = dev_alloc_skb(size);

	if (unlikely(!skb)) {
		cl_dbg_verbose(cl_hw, "skb alloc failed (size %u)\n", size);
		rx_elem->dma_addr = (dma_addr_t)0;
		return -ENOMEM;
	}

	rxhdr = (struct hw_rxhdr *)skb->data;
	rxhdr->pattern = 0;

	dma_addr = dma_map_single(cl_hw->chip->dev, skb->data, size, DMA_FROM_DEVICE);

	if (unlikely(dma_mapping_error(cl_hw->chip->dev, dma_addr))) {
		cl_dbg_verbose(cl_hw, "dma_mapping_error\n");
		kfree_skb(skb);
		return -1;
	}

	rx_elem->skb = skb;
	rx_elem->dma_addr = dma_addr;

	cl_rx_skb_alloc_handler(skb);

	return 0;
}

void cl_ipc_msgbuf_push(struct cl_ipc_host_env *ipc_env, ptrdiff_t hostid, dma_addr_t hostbuf)
{
	/*
	 * Push a pre-allocated buffer descriptor for MSGs
	 * This function is only called at Init time since the MSGs will be handled directly
	 * and buffer can be re-used as soon as the message is handled, no need to re-allocate
	 * new buffers in the meantime.
	 */
	struct cl_ipc_shared_env __iomem *shared_env = ipc_env->shared;
	u8 e2a_msg_host_idx = ipc_env->e2a_msg_host_idx;

	/* Save the hostid and the hostbuf in global array */
	ipc_env->e2a_msg_hostbuf_array[e2a_msg_host_idx].hostid = hostid;
	ipc_env->e2a_msg_hostbuf_array[e2a_msg_host_idx].dma_addr = hostbuf;

	/* Copy the hostbuf (DMA address) in the ipc shared memory */
	iowrite32(hostbuf, (void __iomem *)&shared_env->e2a_msg_hostbuf_addr[e2a_msg_host_idx]);

	/* Increment the array index */
	ipc_env->e2a_msg_host_idx = (e2a_msg_host_idx + 1) % IPC_E2A_MSG_BUF_CNT;
}

void cl_ipc_rxbuf_push(struct cl_ipc_host_env *ipc_env, struct cl_rx_elem *rx_elem,
		       u32 rxdesc_read_idx, u32 host_read_idx, enum rx_buf_type type)
{
	/*
	 * Push a pre-allocated buffer descriptor for Rx packet.
	 * This function is called to supply the firmware with new empty buffer.
	 */
	struct cl_ipc_ring_indices *indices = ipc_env->ring_indices_elem->indices;
	struct cl_ipc_host_rxbuf *host_rxbuf = &ipc_env->rx_hostbuf_array[type];

	/* Save the hostid and the hostbuf in global array */
	host_rxbuf->ipc_host_rxdesc_ptr[host_read_idx] = (ptrdiff_t *)rx_elem;
	host_rxbuf->dma_payload_addr[host_read_idx] = rx_elem->dma_addr;

	/* Update rxbuff metadata */
	indices->rxdesc_read_idx[type] = cpu_to_le32(rxdesc_read_idx + 1);
}

void cl_ipc_radarbuf_push(struct cl_ipc_host_env *ipc_env, ptrdiff_t hostid, dma_addr_t hostbuf)
{
	/*
	 * Push a pre-allocated radar event buffer descriptor.
	 * This function should be called by the host IRQ handler to supply the embedded
	 * side with new empty buffer.
	 */
	struct cl_ipc_shared_env __iomem *shared_env = ipc_env->shared;
	u8 radar_host_idx = ipc_env->radar_host_idx;

	/* Save the hostid and the hostbuf in global array */
	ipc_env->radar_hostbuf_array[radar_host_idx].hostid = hostid;
	ipc_env->radar_hostbuf_array[radar_host_idx].dma_addr = hostbuf;

	/* Copy the hostbuf (DMA address) in the ipc shared memory */
	iowrite32(hostbuf, (void __iomem *)&shared_env->radarbuf_hostbuf[radar_host_idx]);

	/* Increment the array index */
	ipc_env->radar_host_idx = (radar_host_idx + 1) % IPC_RADAR_BUF_CNT;
}

void cl_ipc_dbgbuf_push(struct cl_ipc_host_env *ipc_env, ptrdiff_t hostid, dma_addr_t hostbuf)
{
	/*
	 * Push a pre-allocated buffer descriptor for Debug messages.
	 * This function is only called at Init time since the Debug messages will be
	 * handled directly and buffer can be re-used as soon as the message is handled,
	 * no need to re-allocate new buffers in the meantime.
	 */
	struct cl_ipc_shared_env __iomem *shared_env = ipc_env->shared;
	u8 dbg_host_idx = ipc_env->dbg_host_idx;

	/* Save the hostid and the hostbuf in global array */
	ipc_env->dbg_hostbuf_array[dbg_host_idx].hostid = hostid;
	ipc_env->dbg_hostbuf_array[dbg_host_idx].dma_addr = hostbuf;

	/* Copy the hostbuf (DMA address) in the ipc shared memory */
	iowrite32(hostbuf, (void __iomem *)&shared_env->dbg_hostbuf_addr[dbg_host_idx]);

	/* Increment the array index */
	ipc_env->dbg_host_idx = (dbg_host_idx + 1) % IPC_DBG_BUF_CNT;
}

void cl_ipc_dbginfobuf_push(struct cl_ipc_host_env *ipc_env, dma_addr_t infobuf)
{
	/*Push the pre-allocated logic analyzer and debug information buffer */
	struct cl_ipc_shared_env __iomem *shared_env = ipc_env->shared;

	/* Copy the hostbuf (DMA address) in the ipc shared memory */
	iowrite32(infobuf, (void __iomem *)&shared_env->dbginfo_addr);
	/* Copy the hostbuf size in the ipc shared memory */
	iowrite32(DBG_DUMP_BUFFER_SIZE, (void __iomem *)&shared_env->dbginfo_size);
}
