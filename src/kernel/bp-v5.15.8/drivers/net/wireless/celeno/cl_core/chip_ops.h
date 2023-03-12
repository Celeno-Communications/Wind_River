/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CHIP_OPS_H
#define CHIP_OPS_H

#include "chip.h"

static inline int chip_ops_mask_write32(struct cl_chip *chip, u32 addr,
					u32 val, u32 mask, bool resp)
{
	if (chip->ops->mask_write32)
		return chip->ops->mask_write32(chip, addr, val, mask, resp);

	return -EOPNOTSUPP;
}

static inline int chip_ops_write32(struct cl_chip *chip, u32 addr, u32 val)
{
	if (chip->ops->write32)
		return chip->ops->write32(chip, addr, val);

	return -EOPNOTSUPP;
}

static inline int chip_ops_write_bulk(struct cl_chip *chip, u32 addr,
				      u8 *data, int size)
{
	if (chip->ops->write_bulk)
		return chip->ops->write_bulk(chip, addr, data, size);

	return -EOPNOTSUPP;
}

static inline int chip_ops_read32(struct cl_chip *chip, u32 addr, u32 *val)
{
	if (chip->ops->read32)
		return chip->ops->read32(chip, addr, val);

	return -EOPNOTSUPP;
}

static inline int chip_ops_read_bulk(struct cl_chip *chip, u32 addr,
				     u32 length, u8 *data)
{
	if (chip->ops->read_bulk)
		return chip->ops->read_bulk(chip, addr, length, data);

	return -EOPNOTSUPP;
}

static inline int chip_ops_fw_upload(struct cl_chip *chip,
				     enum cl_fw_file_type type,
				     u8 *data, int size)
{
	if (chip->ops->fw_upload)
		return chip->ops->fw_upload(chip, type, data, size);

	return -EOPNOTSUPP;
}

static inline int chip_ops_umac_fw_upload(struct cl_chip *chip)
{
	if (chip->ops->umac_fw_upload)
		return chip->ops->umac_fw_upload(chip);

	return -EOPNOTSUPP;
}

static inline int chip_ops_smac_fw_upload(struct cl_chip *chip)
{
	if (chip->ops->smac_fw_upload)
		return chip->ops->smac_fw_upload(chip);

	return -EOPNOTSUPP;
}

static inline int chip_ops_config_set(struct cl_chip *chip,
				      char *buf, loff_t size)
{
	if (chip->ops->config_set)
		return chip->ops->config_set(chip, buf, size);

	return -EOPNOTSUPP;
}

static inline void chip_ops_config_print(struct cl_chip *chip)
{
	if (chip->ops->config_print)
		chip->ops->config_print(chip);
}

static inline void *chip_ops_alloc_coherent(struct cl_chip *chip, size_t size,
					    gfp_t mem_flags, dma_addr_t *dma)
{
	if (chip->ops->alloc_coherent)
		return chip->ops->alloc_coherent(chip, size, mem_flags, dma);

	return NULL;
}

static inline void chip_ops_free_coherent(struct cl_chip *chip, size_t size,
					  void *cpu_addr, dma_addr_t dma)
{
	if (chip->ops->free_coherent)
		chip->ops->free_coherent(chip, size, cpu_addr, dma);
}

static inline void chip_ops_print_umac_stats(struct cl_chip *chip)
{
	if (chip->ops->print_umac_stats)
		chip->ops->print_umac_stats(chip);
}

static inline int
chip_ops_get_umac_version(struct cl_chip *chip,
			  struct cli_usb_param_version *version)
{
	if (chip->ops->get_umac_version)
		return chip->ops->get_umac_version(chip, version);

	return -EOPNOTSUPP;
}

static inline int
chip_ops_usb_set_alternate(struct cl_chip *chip, int ifnum, int val)
{
	if (chip->ops->usb_set_alternate)
		return chip->ops->usb_set_alternate(chip, ifnum, val);

	return -EOPNOTSUPP;
}
#endif /* CHIP_OPS_H */
