/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_MSG_PCI_H
#define CL_MSG_PCI_H

#include "cl_hw.h"

void cl_msg_pci_copy_to_host(struct cl_hw *cl_hw,
			     struct cl_ipc_host_env *ipc_env);
int cl_msg_pci_msg_fw_send(struct cl_hw *cl_hw, const void *msg_params,
			   bool background);
int cl_msg_pci_cfm_wait(struct cl_hw *cl_hw, u16 bit, u16 req_id);
#endif /* CL_MSG_PCI_H */
