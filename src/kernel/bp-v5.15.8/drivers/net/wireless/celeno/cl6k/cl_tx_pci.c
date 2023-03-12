// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <net/mac80211.h>
#include "cl_tx_pci.h"
#include "cl_ipc.h"
#include "cl_ipc_shared.h"
#include "chip.h"
#include "cl_tx.h"
#include "cl_single_cfm.h"
#include "cl_sw_txhdr.h"
#include "cl_irq.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif

void cl_tx_pci_single_cfm_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	struct cl_ipc_cfm_msg *msg = NULL;

#ifdef TRACE_SUPPORT
	trace_cl_trace_tx_pci_single_cfm_tasklet_start(cl_hw->idx,
						       cl_hw->single_cfm_read_idx);
#endif

	msg = (struct cl_ipc_cfm_msg *)(cl_hw->single_cfm_virt_base_addr) +
		(cl_hw->single_cfm_read_idx % IPC_CFM_CNT);

	while (msg && msg->dma_addr) {
		u32 cfm_read_idx = cl_hw->single_cfm_read_idx++;

		cl_single_cfm_handler(cl_hw,
				      le32_to_cpu(msg->status),
				      le32_to_cpu(msg->dma_addr),
				      le32_to_cpu(msg->single_queue_idx));
		msg->dma_addr = 0;
		iowrite32(cfm_read_idx,
			  (void __iomem *)&ipc_env->shared->cfm_read_pointer);
		msg = (struct cl_ipc_cfm_msg *)(cl_hw->single_cfm_virt_base_addr) +
			(cl_hw->single_cfm_read_idx % IPC_CFM_CNT);
	}

	/* Enable the Tx CFM interrupt bit */
	if (!test_bit(CL_DEV_STOP_HW, &cl_hw->drv_flags))
		cl_irq_enable(cl_hw, cl_hw->ipc_e2a_irq.txcfm);

#ifdef TRACE_SUPPORT
	trace_cl_trace_tx_pci_single_cfm_tasklet_end(cl_hw->idx,
						     cl_hw->single_cfm_read_idx);
#endif
}

