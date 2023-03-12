// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_main.h"
#include "cl_msg_pci.h"
#include "reg_cmu.h"
#include "pci.h"

static const struct cl_driver_ops drv_pci_ops = {
	.msg_fw_send = cl_msg_pci_msg_fw_send,
};

void cl_pci_set_cl_hw(struct cl_chip *chip, struct cl_hw *cl_hw)
{
	chip->cl_hw_tcv0 = cl_hw;
	chip->cl_hw_tcv0->ops = &drv_pci_ops;
}

int cl_pci_init(void)
{
	int ret = 0;
	struct pci_dev *pdev = NULL;

	while ((pdev = pci_get_device(CL_CORE_PCI_VENDOR_ID, PCI_ANY_ID, pdev))) {
		struct cl_chip *chip = pci_get_drvdata(pdev);

		if (!chip)
			continue;

		ret = cl_main_init(chip);
		if (ret)
			return ret;

		pci_dev_get(pdev);
	}

	return ret;
}

void cl_pci_exit(void)
{
	struct pci_dev *pdev = NULL;

	while ((pdev = pci_get_device(CL_CORE_PCI_VENDOR_ID, PCI_ANY_ID, pdev))) {
		struct cl_chip *chip = pci_get_drvdata(pdev);

		if (!chip)
			continue;

		cl_main_deinit(chip->cl_hw_tcv0);
		if (chip->conf->ci_phy_dev == PHY_DEV_DENALI) {
			cmu_global_rst_set(chip, CMU_GLOBAL_RESET_KEY1);
			cmu_global_rst_set(chip, CMU_GLOBAL_RESET_KEY2);
		}

		pci_dev_put(pdev);
	}
}
