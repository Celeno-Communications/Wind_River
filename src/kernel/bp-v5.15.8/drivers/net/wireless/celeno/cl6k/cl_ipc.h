/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_IPC_H
#define CL_IPC_H

#include "def.h"
#include "pci.h"
#include "ipc_shared.h"
#include "cl_hw.h"

/* Struct used to store information about host buffers (DMA Address and local pointer) */
struct cl_ipc_hostbuf {
	ptrdiff_t hostid; /* Ptr to hostbuf client (ipc_host client) structure */
	dma_addr_t dma_addr; /* Ptr to real hostbuf dma address */
};

/* Structure used to store Shared Txring indices */
struct cl_ipc_ring_indices_elem {
	struct cl_ipc_ring_indices *indices;
	dma_addr_t dma_addr;
};

struct cl_ipc_host_rxbuf {
	/* Array of drv desc which holds the skb and additional data */
	ptrdiff_t **ipc_host_rxdesc_ptr;
	/* Address of payload for embedded push operation (part of rxdesc data) */
	u32 *dma_payload_addr;
	/* Dma pointer to array of DMA payload addresses */
	__le32 dma_payload_base_addr;
};

struct cl_ipc_host_env {
	/* Pointer to the shared environment */
	struct cl_ipc_shared_env __iomem *shared;
	/* TX ring indices (RD, WR idx & new_ssn) */
	struct cl_ipc_ring_indices_elem *ring_indices_elem;
	/* RX buffers (rxdesc & dma_addr) */
	ptrdiff_t *ipc_host_rxdesc_rxm[IPC_RXBUF_CNT_RXM];
	ptrdiff_t *ipc_host_rxdesc_fw[IPC_RXBUF_CNT_FW];
	struct cl_ipc_host_rxbuf rx_hostbuf_array[CL_RX_BUF_MAX];
	/* Host last read idx */
	u32 host_rxdesc_read_idx[CL_RX_BUF_MAX];
	/* Fields for Radar events handling */
	struct cl_ipc_hostbuf radar_hostbuf_array[IPC_RADAR_BUF_CNT];
	u8 radar_host_idx;
	/* Fields for Emb->App MSGs handling */
	struct cl_ipc_hostbuf e2a_msg_hostbuf_array[IPC_E2A_MSG_BUF_CNT];
	u8 e2a_msg_host_idx;
	/* Fields for Debug MSGs handling */
	struct cl_ipc_hostbuf dbg_hostbuf_array[IPC_DBG_BUF_CNT];
	u8 dbg_host_idx;
	/* Tasklets */
	struct tasklet_struct rxdesc_tasklet;
};

int cl_ipc_init(struct cl_hw *cl_hw);
void cl_ipc_recovery(struct cl_hw *cl_hw);
void cl_ipc_reset(struct cl_hw *cl_hw);
void cl_ipc_deinit(struct cl_hw *cl_hw);
void cl_ipc_stop(struct cl_hw *cl_hw);
int cl_ipc_rx_elem_alloc(struct cl_hw *cl_hw, struct cl_rx_elem *rx_elem, u32 size);
void cl_ipc_msgbuf_push(struct cl_ipc_host_env *ipc_env, ptrdiff_t hostid, dma_addr_t hostbuf);
void cl_ipc_rxbuf_push(struct cl_ipc_host_env *ipc_env, struct cl_rx_elem *rx_elem,
		       u32 rxdesc_read_idx, u32 host_read_idx, enum rx_buf_type type);
void cl_ipc_radarbuf_push(struct cl_ipc_host_env *ipc_env, ptrdiff_t hostid, dma_addr_t hostbuf);
void cl_ipc_dbgbuf_push(struct cl_ipc_host_env *ipc_env, ptrdiff_t hostid, dma_addr_t hostbuf);
void cl_ipc_dbginfobuf_push(struct cl_ipc_host_env *ipc_env, dma_addr_t infobuf);

#endif /* CL_IPC_H */
