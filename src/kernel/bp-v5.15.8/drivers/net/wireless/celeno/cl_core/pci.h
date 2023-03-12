/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef PCI_H
#define PCI_H

#include <linux/types.h>
#include <linux/spinlock.h>
#include <linux/module.h>
#include <linux/pci.h>
#include "def.h"
#include "chip.h"

#define CL_CORE_PCI_VENDOR_ID 0x1d69

struct cl_chip_pci {
	struct pci_dev *pci_dev;
	size_t bar_len;
	void __iomem *bar0_virt_addr;
	u32 mask;
	spinlock_t isr_lock;
};

static inline struct cl_chip_pci *cl_chip_pci_priv(struct cl_chip *chip)
{
	return (struct cl_chip_pci *)chip->drv_priv;
}

int cl_core_pci_register(void);
void cl_core_pci_unregister(void);
#endif /* PCI_H */
