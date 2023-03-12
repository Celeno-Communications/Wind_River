/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_RX_PCI_H
#define CL_RX_PCI_H

#include "cl_hw.h"

void cl_rx_pci_init(struct cl_hw *cl_hw);
void cl_rx_pci_deinit(struct cl_hw *cl_hw);
void cl_rx_pci_desc_handler(struct cl_hw *cl_hw);
void cl_rx_pci_desc_tasklet(unsigned long data);

#endif /* CL_RX_PCI_H */
