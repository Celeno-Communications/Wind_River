/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_BCMC_CFM_H
#define CL_BCMC_CFM_H

#include "cl_tx.h"

#define BCMC_POLL_TIMEOUT 50

void cl_bcmc_cfm_init(struct cl_hw *cl_hw);
void cl_bcmc_cfm_add(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr);
struct cl_sw_txhdr *cl_bcmc_cfm_find(struct cl_hw *cl_hw, dma_addr_t dma_addr,
				     bool keep_in_list);
void cl_bcmc_cfm_flush_queue(struct cl_hw *cl_hw, struct cl_vif *cl_vif);
void cl_bcmc_cfm_poll_empty_per_vif(struct cl_hw *cl_hw,
				    struct cl_vif *cl_vif);

#endif /* CL_BCMC_CFM_H */
