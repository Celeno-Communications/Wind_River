// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include "usb.h"
#include "pci.h"

MODULE_DESCRIPTION("Celeno cl_core driver");
MODULE_VERSION("6.0.x");
MODULE_AUTHOR("Copyright(c) 2022 Celeno Communications Ltd");
MODULE_LICENSE("Dual BSD/GPL");

union priv {
	struct cl_chip_usb chip_usb;
	struct cl_chip_pci chip_pci;
};

static int __init cl_core_init(void)
{
	int ret;

	ret = cl_chip_alloc_all(sizeof(union priv));
	if (ret)
		return ret;

	ret = cl_core_pci_register();
	if (ret)
		return ret;

	ret = cl_core_usb_register();
	if (ret)
		goto out_pci_unregister;

	return ret;

 out_pci_unregister:
	cl_core_pci_unregister();
	cl_chip_dealloc_all();

	return ret;
}
module_init(cl_core_init);

static void __exit cl_core_exit(void)
{
	cl_core_pci_unregister();
	cl_core_usb_unregister();
	cl_chip_dealloc_all();
}
module_exit(cl_core_exit);
