// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/firmware.h>
#include "core_debug.h"
#include "pci.h"
#include "chip_config.h"
#include "config.h"
#include "chip.h"
#include "ipc_shared.h"
#include "reg_access.h"
#include "reg_macsys_gcu.h"
#include "reg_ipc.h"
#include "reg_usbc.h"

struct cl_pci_db {
	u8 device_cntr;
	struct pci_dev *dev[CHIP_MAX];
};

static struct cl_pci_db pci_db;

static void cl_pci_get_celeno_device(void)
{
	/*
	 * Search the PCI for all Celeno devices.
	 * If there are two devices sort them in ascending order.
	 */
	struct pci_dev *dev = NULL;

	while ((dev = pci_get_device(CL_CORE_PCI_VENDOR_ID, PCI_ANY_ID, dev))) {
		pci_db.dev[pci_db.device_cntr] = dev;
		pci_db.device_cntr++;

		if (pci_db.device_cntr > 1) {
			s8 i = 0;
			u8 new_idx = pci_db.device_cntr - 1;
			u16 new_dev_id = pci_db.dev[new_idx]->device;

			/* Move the new udev to the correct position in the sorted udev array */
			for (i = new_idx - 1; i >= 0; i--)
				if (new_dev_id < pci_db.dev[i]->device)
					swap(pci_db.dev[i], pci_db.dev[i + 1]);
				else
					break;
		}
	}
}

static u8 cl_pci_chip_idx(struct pci_dev *pci_dev)
{
	u8 chip_idx;

	if (pci_db.device_cntr == 0)
		cl_pci_get_celeno_device();

	for (chip_idx = 0; chip_idx < CHIP_MAX; chip_idx++)
		if (pci_db.dev[chip_idx] == pci_dev)
			return chip_idx;

	return -1;
}

static int pci_get_fw(struct cl_chip *chip, const char *fw_name,
		      u8 **data, int *size)
{
	int ret;
	const struct firmware *fw;
	char path_name[STR_LEN_128B] = {0};

	snprintf(path_name, sizeof(path_name), "cl6k/%s", fw_name);

	ret = request_firmware(&fw, path_name, chip->dev);
	if (ret) {
		cl_dbg_chip_err(chip, "failed to get %s %x\n",
				fw_name, ret);
		return ret;
	}

	*data = kzalloc(fw->size, GFP_KERNEL);
	if (!*data) {
		ret = -ENOMEM;
		goto out;
	}

	memcpy(*data, fw->data, fw->size);
	*size = fw->size;

out:
	release_firmware(fw);

	return ret;
}

static int pci_mask_write32(struct cl_chip *chip, u32 addr, u32 val,
			    u32 mask, bool resp)
{
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);
	u32 reg_rd = ioread32(chip_pci->bar0_virt_addr + (addr & chip_pci->mask));
	u32 val_write = ((reg_rd & ~mask) | (val & mask));

	iowrite32(val_write, chip_pci->bar0_virt_addr + (addr & chip_pci->mask));

	return 0;
}

static int pci_write32(struct cl_chip *chip, u32 addr, u32 val)
{
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);

	iowrite32(val, chip_pci->bar0_virt_addr + (addr & chip_pci->mask));

	return 0;
}

static int pci_write_bulk(struct cl_chip *chip, u32 addr,
			  u8 *data, int size)
{
	int i;
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);
	u32 *val;

	for (i = 0; i < size; i += sizeof(u32), data += sizeof(u32)) {
		val = (u32 *)data;
		iowrite32(*val, chip_pci->bar0_virt_addr + ((addr + i) & chip_pci->mask));
	}

	return 0;
}

static int pci_read32(struct cl_chip *chip, u32 addr, u32 *val)
{
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);

	*val = ioread32(chip_pci->bar0_virt_addr + (addr & chip_pci->mask));

	return 0;
}

static int pci_read_bulk(struct cl_chip *chip, u32 addr,
			 u32 length, u8 *data)
{
	int i;
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);
	u32 val;

	for (i = 0; i < length; i += sizeof(u32), data += sizeof(u32)) {
		val = ioread32(chip_pci->bar0_virt_addr + ((addr + i) & chip_pci->mask));
		memcpy(data, &val, sizeof(u32));
	}

	return 0;
}

static int pci_fw_upload(struct cl_chip *chip, enum cl_fw_file_type type,
			 u8 *data, int size)
{
	int ret = 0;
	struct fw_file_params params = {0};

	ret = fw_file_get_params(chip, type, &params);
	if (ret)
		return ret;

	ret = pci_write_bulk(chip, params.dram_addr,
			     data, params.dram_size);
	if (ret) {
		cl_dbg_chip_err(chip, "DRAM load failed %d\n", ret);
		return ret;
	}

	/* IRAM load */
	size -= IRAM_START_OFFSET;
	size = (size < params.iram_size) ? size : params.iram_size;

	ret = pci_write_bulk(chip, params.iram_addr,
			     (data + IRAM_START_OFFSET), size);
	if (ret) {
		cl_dbg_chip_err(chip, "IRAM load failed %d\n", ret);
		return ret;
	}

	return 0;
}

static int pci_smac_fw_upload(struct cl_chip *chip)
{
	int ret = 0;
	u8 *fw_data = NULL;
	int fw_size = 0;

	ret = pci_get_fw(chip, "smacfw.bin", &fw_data, &fw_size);
	if (ret)
		return ret;

	ret = add_bt_config(chip, fw_data);
	if (ret)
		goto out;

	macsys_gcu_smac_control_smac_boot_src_setf(chip, 0);

	ret = pci_fw_upload(chip, CL_FW_FILE_SMAC, fw_data, fw_size);
	if (ret)
		goto out;

	ipc_xmac_2_host_ack_set(chip, IPC_IRQ_S2H_ALL);
	macsys_gcu_xt_control_smac_run_stall_setf(chip, 0);
	ipc_xmac_2_host_enable_set_set(chip, IPC_IRQ_S2H_ALL);

	chip->smac_active = true;
out:
	kfree(fw_data);

	return ret;
}

static void cl_core_set_idma_allocation(struct cl_chip *chip)
{
	pci_write32(chip, SHARED_RAM_START_ADDR +
		    offsetof(struct cl_ipc_shared_env, usb_umac_env) +
		    offsetof(struct usb_umac_env_tag, idma_allocation),
		    DEFAULT_IDMA_ALLOCATION_VALUE);
}

static void *cl_core_pci_alloc_coherent(struct cl_chip *chip, size_t size,
					gfp_t mem_flags, dma_addr_t *dma)
{
	return dma_alloc_coherent(chip->dev, size, dma, mem_flags);
}

static void cl_core_pci_free_coherent(struct cl_chip *chip, size_t size,
				      void *cpu_addr, dma_addr_t dma)
{
	dma_free_coherent(chip->dev, size, cpu_addr, dma);
}

static const struct cl_chip_ops pci_ops = {
	.mask_write32 = pci_mask_write32,
	.write32 = pci_write32,
	.write_bulk = pci_write_bulk,
	.read32 = pci_read32,
	.read_bulk = pci_read_bulk,
	.fw_upload = pci_fw_upload,
	.smac_fw_upload = pci_smac_fw_upload,
	.config_set = cl_chip_config_set,
	.config_print = cl_chip_config_print,
	.alloc_coherent = cl_core_pci_alloc_coherent,
	.free_coherent = cl_core_pci_free_coherent,
};

static int cl_core_pci_probe(struct pci_dev *pci_dev,
			     const struct pci_device_id *pci_id)
{
	u16 pci_cmd;
	int ret;
	u8 chip_idx = cl_pci_chip_idx(pci_dev);
	struct cl_chip_pci *chip_pci;
	struct cl_chip *chip = cl_chip_get(chip_idx);

	if (!chip) {
		pr_err("cl_chip_get idx %u failed\n", chip_idx);
		return -ENOMEM;
	}

	chip->dev = &pci_dev->dev;
	chip->bus_type = CL_BUS_TYPE_PCI;
	chip->ops = &pci_ops;

	ret = cl_chip_config_read(chip);
	if (ret) {
		cl_chip_dealloc(chip);
		return 0;
	}

	chip_pci = cl_chip_pci_priv(chip);
	chip_pci->pci_dev = pci_dev;

	pci_set_drvdata(pci_dev, chip);

	/* Hotplug fixups */
	pci_read_config_word(pci_dev, PCI_COMMAND, &pci_cmd);
	pci_cmd |= PCI_COMMAND_PARITY | PCI_COMMAND_SERR;
	pci_write_config_word(pci_dev, PCI_COMMAND, pci_cmd);
	pci_write_config_byte(pci_dev, PCI_CACHE_LINE_SIZE, L1_CACHE_BYTES >> 2);

	ret = pci_enable_device(pci_dev);
	if (ret) {
		cl_dbg_chip_err(chip, "pci_enable_device failed\n");
		goto out_chip_dealloc;
	}

	if (!dma_set_mask_and_coherent(&pci_dev->dev, DMA_BIT_MASK(32))) {
		cl_dbg_chip_verbose(chip, "Using 32bit DMA\n");
	} else {
		cl_dbg_chip_err(chip, "No suitable DMA available\n");
		goto out_disable_device;
	}

	pci_set_master(pci_dev);

	ret = pci_request_region(pci_dev, 0, "cl_core");
	if (ret) {
		cl_dbg_chip_verbose(chip, "pci_request_region failed\n");
		goto out_disable_device;
	}

	chip_pci->bar_len = pci_resource_len(pci_dev, 0);
	chip_pci->bar0_virt_addr = pci_ioremap_bar(pci_dev, 0);
	if (!chip_pci->bar0_virt_addr) {
		cl_dbg_chip_verbose(chip, "pci_ioremap_bar (%d) failed\n", 0);
		ret = -ENOMEM;
		goto out_release_regions;
	}
	/* Chip is using 32-bit bus */
	chip_pci->mask = (u32)(pci_resource_end(pci_dev, 0) ^
			       pci_resource_start(pci_dev, 0));

	spin_lock_init(&chip_pci->isr_lock);

#ifdef CONFIG_PCI_MSI
	if (chip->conf->ci_pci_msi_enable) {
		ret = pci_enable_msi(pci_dev);
		if (ret)
			cl_dbg_chip_err(chip, "pci_enable_msi failed (%d)\n", ret);
	}
#endif

	cl_core_set_idma_allocation(chip);

	if (chip->conf->ci_phy_dev != PHY_DEV_DUMMY &&
	    chip->conf->ci_phy_dev != PHY_DEV_FRU) {
		/* USB2.0 activation/suspend */
		if (chip->conf->ce_bt_mode < BT_MODE_USB)
			usbc_gusb_2_phycfg_0_suspendusb_20_setf(chip, 1);
		else
			usbc_gusb_2_phycfg_0_suspendusb_20_setf(chip, 0);
	}

	macsys_gcu_smac_control_smac_boot_src_setf(chip, 0);
	macsys_gcu_umac_control_umac_boot_src_setf(chip, 0);

	/* All cores needs to be reset first (once per chip) */
	chip_reset(chip,
		   XMAC_OCD_HALT_ON_RESET | UMAC_OCD_HALT_ON_RESET,
		   XMAC_DRESET | UMAC_DRESET,
		   XMAC_RUN_STALL | UMAC_RUN_STALL,
		   XMAC_BRESET | UMAC_BRESET,
		   XMAC_DEBUG_ENABLE | UMAC_DEBUG_ENABLE);

	ret = cl_core_chip_init(chip);
	if (ret)
		goto out_release_regions;

	if (chip->conf->ce_bt_mode && !chip->fw_test)
		ret = pci_smac_fw_upload(chip);

	return ret;

out_release_regions:
	pci_release_regions(pci_dev);
out_disable_device:
	pci_disable_device(pci_dev);
out_chip_dealloc:
	cl_chip_dealloc(chip);

	return ret;
}

static void cl_core_pci_remove(struct pci_dev *pci_dev)
{
	struct cl_chip *chip = pci_get_drvdata(pci_dev);
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);

	if (!chip) {
		pr_err("%s: failed to find chip\n", __func__);
		return;
	}

#ifdef CONFIG_PCI_MSI
	if (chip->conf->ci_pci_msi_enable) {
		pci_disable_msi(pci_dev);
		pr_debug("pci_disable_msi\n");
	}
#endif

	cl_core_chip_deinit(chip);
	chip_pci->mask = 0;

	pci_set_drvdata(pci_dev, NULL);
	iounmap(chip_pci->bar0_virt_addr);
	pci_release_regions(pci_dev);
	pci_disable_device(pci_dev);
}

static const struct pci_device_id cl_core_pci_id_table[] = {
	{ PCI_DEVICE(CL_CORE_PCI_VENDOR_ID, 0x6000) },
	{ PCI_DEVICE(CL_CORE_PCI_VENDOR_ID, 0x6001) },
	{ PCI_DEVICE(CL_CORE_PCI_VENDOR_ID, 0x6010) },
	{ PCI_DEVICE(CL_CORE_PCI_VENDOR_ID, 0x6020) },
	{ },
};

static struct pci_driver cl_core_pci_driver = {
	.name = "cl_core_pci",
	.id_table = cl_core_pci_id_table,
	.probe = cl_core_pci_probe,
	.remove = cl_core_pci_remove,
};

int cl_core_pci_register(void)
{
	int ret;

	ret = pci_register_driver(&cl_core_pci_driver);
	if (ret)
		pr_err("failed to register cl_core_pci driver: %d\n", ret);

	return ret;
}

void cl_core_pci_unregister(void)
{
	pci_unregister_driver(&cl_core_pci_driver);
}
