// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/firmware.h>
#include "cl_fw_file.h"
#include "cl_dbgfile.h"
#include "reg_access.h"
#include "file.h"
#include "config.h"
#include "chip_ops.h"

/*
 * Poor man parser of a plain zip file
 * We use it just as a container for now. Could use cpio instead.
 * (no compression, no 64-bit data ... no nothing)
 * Reference: ZIP File Format Specification v.6.3.4 (2014)
 *     http://pkware.cachefly.net/webdocs/casestudies/APPNOTE.TXT
 * For BIG ENDIAN host: zip format is always little endian.
 */

struct pkzip_local_hdr  {
	u32 signature;
	u16 ver2extract;
	u16 flags;
	u16 cmpr_meth;
	u16 filetime;
	u16 filedate;
	u32 crc32;
	u32 cmpr_size;
	u32 orig_size;
	u16 fname_len;
	u16 hdr_extra_len;
	/* Filename goes here - not 0 terminated! */
	/* Hdr_extra_data goes here */
	/* File data goes here; no padding, no alignment */
} __packed;

#define PKZIP_LOCAL_HDR_MAGIC   0x04034b50
#define PKZIP_CENTRAL_DIR_MAGIC 0x02014b50

/*
 * Enumerate zip data in buffer, find named item
 * Return: 0 on success (the item found)
 *        -ENOENT the item not found, normal end of data found
 *        -EINVAL the data is not zip (maybe old format firmware)
 *         else invalid data format or other error
 */
static int cl_enum_zipfile(const void *data, size_t size,
			   const char *name, char **pdata, size_t *psize)
{
	const struct pkzip_local_hdr *phdr = data;
	int remain_size = (int)size;

	BUILD_BUG_ON(sizeof(struct pkzip_local_hdr) != 30);

	while (remain_size > sizeof(struct pkzip_local_hdr)) {
		char *pfname;
		char *edata;

		if (phdr->signature != PKZIP_LOCAL_HDR_MAGIC) {
			if (phdr->signature == PKZIP_CENTRAL_DIR_MAGIC)
				return -ENOENT; /* Normal end of zip */
			if ((void *)phdr == data)
				/* Bad signature in the first entry - not a zip at all */
				return -EINVAL;
			pr_err("ZIP - unexpected block: %8.8X\n", phdr->signature);
			return -1;
		}

		if (phdr->fname_len == 0 || phdr->fname_len > 128) {
			/* FIX max len */
			pr_err("ZIP entry name len bad: %u\n", phdr->fname_len);
			return -1;
		}

		if (phdr->hdr_extra_len == 0) {
			pr_err("ZIP xtra hdr size=0! FIXME!\n"); /* Copy name to tmp buffer */
			return -1;
		}

		pfname = (char *)phdr + sizeof(struct pkzip_local_hdr);
		/* Because fname in zip is not null term! */
		pfname[phdr->fname_len] = 0;
		edata = pfname + phdr->fname_len + phdr->hdr_extra_len;
		remain_size -= (sizeof(*phdr) + phdr->fname_len +
				phdr->hdr_extra_len);

		if (phdr->cmpr_size == 0 || phdr->cmpr_size > remain_size) {
			pr_err("ZIP entry data len bad: %u name=%s, left=%u\n",
			       phdr->cmpr_size, pfname, remain_size);
			return -1;
		}

		if (strncmp(name, pfname, phdr->fname_len) == 0) {
			if (phdr->cmpr_meth != 0 || phdr->cmpr_size != phdr->orig_size) {
				pr_err("ZIP entry compressed! name=%s\n", pfname);
				return -1;
			}

			*pdata = edata;
			*psize = (size_t)phdr->cmpr_size;
			return 0;
		}

		remain_size -= phdr->cmpr_size;
		phdr = (const struct pkzip_local_hdr *)(edata + phdr->cmpr_size);
	}

	return -1;
}

static int cl_fw_unpack(const void *data, size_t size,
			const char *name, char **pdata, size_t *psize)
{
	/*
	 * Get named item in firmware container
	 * Args: pdata : pointer to pointer to item data, psize : pointer to item size
	 */
	*pdata = NULL;
	*psize = 0;
	return cl_enum_zipfile(data, size, name, pdata, psize);
}

static int cl_fw_load_other(struct cl_hw *cl_hw, const char *name)
{
	/* Handle other stuff in firmware container */
	char *edata;
	size_t esize;
	struct cl_cached_fw *cached_fw = &cl_hw->cached_fw;
	int rc = cl_fw_unpack(cached_fw->data, cached_fw->size,
			      name, &edata, &esize);

	if (rc)
		return rc;

	cl_dbgfile_parse(cl_hw, edata, esize);

	return 0;
}

/*
 * Copy the FW code and data into the proper memory inside the firmware asic.
 * vaddr - run address
 * paddr - load address
 * fsize - memory section size to copy
 * msize - memory section physical size
 * mem_base - base address of xtensa internal memory
 * fw_buf - buffer holding the FW binary code and data
 */
static void cl_fw_copy_section(struct cl_chip *chip, char *fw_buf,
			       u32 mem_base, u32 vaddr, u32 paddr,
			       u32 fsize, u32 msize)
{
	u8 *src_addr;
	u32 dst_addr;
	int ret = 0;

	/* Inentify IRAM addr */
	if ((vaddr & IRAM_RUN_BASE_ADDR) == IRAM_RUN_BASE_ADDR) {
		vaddr = (vaddr - LMAC_DST_IRAM_OFFSET);
		/* Iram mask should be 1024KB even those the actual size is 256KB */
		paddr = paddr & IRAM_SECTION_SIZE_MASK;
	} else {
		paddr = paddr & FW_SECTION_SIZE_MASK;
	}

	src_addr = fw_buf + paddr;

	/* Check if run address is external or internal from xtensa point of view */
	if ((vaddr & 0xFF000000) == XTENSA_PIF_BASE_ADDR)
		dst_addr = vaddr & 0x007FFFFF; /* Must be in 8M PCIe window */
	else
		dst_addr = (mem_base | (vaddr & 0x0007FFFF));

	ret = chip_ops_write_bulk(chip, dst_addr, src_addr, (int)fsize);
	if (ret)
		cl_dbg_chip_err(chip, "chip_ops_write_bulk failed %d\n", ret);
}

static int cl_fw_phdrs_upload(struct cl_chip *chip, struct cl_hw *cl_hw,
			      u32 fw_addr, const void *edata, size_t esize)
{
	/*
	 * Load firmware image with "phdrs" header
	 * and optional non-resident (offloaded) section
	 */
	u32 size = esize, section, section_cnt = 0;
	char const *pbuf = edata;
	u32 *src;

	/* Verify FW image phdrs start magic */
	if (strncmp(pbuf, FW_START_MAGIC, strlen(FW_START_MAGIC))) {
		cl_dbg_err(cl_hw, "phdrs start magic not found, aborting...\n");
		return -1;
	}

	cl_dbg_info(cl_hw, "phdrs start magic found !!!!!\n");
	pbuf += (strlen(FW_START_MAGIC) + 1);
	size -= (strlen(FW_START_MAGIC) + 1);

	/* Verify FW image phdrs end magic */
	while (size > 0) {
		if (strncmp(pbuf, FW_END_MAGIC, strlen(FW_END_MAGIC)) == 0) {
			cl_dbg_info(cl_hw, "phdrs end magic found !!!!!\n");
			break;
		}

		pbuf += 16;
		size -= 16;
		section_cnt++;
	}

	/* FW image phdrs end magic not found */
	if (size == 0 || section_cnt > 100) {
		cl_dbg_err(cl_hw, "phdrs end magic not found, aborting...\n");
		return -1;
	}

	/* Remember where the fw code start in firmware buffer */
	src = (u32 *)(pbuf + (strlen(FW_END_MAGIC) + 1));
	/* Re-assign firmware buffer ptrs to start */
	pbuf = edata + (strlen(FW_START_MAGIC) + 1);
	size = esize - (strlen(FW_START_MAGIC) + 1);

	bool is_offload_present = false;
	u32 off2_start = 0, off2_end = 0;
	u32 off3_start = 0, off3_end = 0;

	for (section = 0; section < section_cnt; section++) {
		u32 *param = (u32 *)pbuf;

		if (param[0] == FW_REMOTE_ROM_BASE_ADDR) {
			if (param[2] > FW_REMOTE_ROM_MAX) {
				cl_dbg_info(cl_hw, "lmac%u: FW remote rom too big = %uK\n",
					    chip->idx, param[2]);
			} else {
				dma_addr_t phys_dma_addr;
				char *pfake = (char *)src + (param[1] & FW_SECTION_SIZE_MASK);
				struct cl_dma_accessed *fw_rom = &cl_hw->fw_remote_rom;

				fw_rom->size = param[2];

				if (!fw_rom->drv_v_addr) {
					fw_rom->drv_v_addr =
						chip_ops_alloc_coherent(chip, fw_rom->size,
									GFP_KERNEL,
									&phys_dma_addr);
					if (fw_rom->drv_v_addr) {
						fw_rom->fw_v_addr = FW_REMOTE_ROM_BASE_ADDR;
						fw_rom->dma_addr = phys_dma_addr;
						memcpy(fw_rom->drv_v_addr, pfake, fw_rom->size);
						cl_dbg_info(cl_hw, "lmac%u: FW ROM size=%uK\n",
							    chip->idx, fw_rom->size);
					} else {
						cl_dbg_err(cl_hw,
							   "lmac%u: FW ROM alloc %uK failed\n",
							   chip->idx, fw_rom->size);
						fw_rom->size = 0;
					}
				} else {
					memcpy(fw_rom->drv_v_addr, pfake, fw_rom->size);
				}
			}
			pbuf += 16;
			continue;
		}

		if (param[0] == FW_OFFLOAD_MEM_BASE_ADDR) {
			is_offload_present = true;
			u32 *pdata = (u32 *)((char *)src + (param[1] & 0x7FFFF));

			off2_start = pdata[0];
			off2_end = pdata[1];
			off3_start = pdata[2];
			off3_end = pdata[3];
			cl_dbg_info(cl_hw, "Resident RO DATA block: start=0x%x, end=0x%x\n\n",
				    off2_start, off2_end);
			pbuf += 16;
			continue;
		}

		cl_fw_copy_section(chip, (char *)src, fw_addr,
				   param[0],
				   param[1],
				   param[2],
				   param[3]);
		pbuf += 16;
	}

	if (is_offload_present) {
		/* 2nd pass to find the resident RO data block */
		pbuf -= (16 * section_cnt);
		char *resident_file_data = NULL;
		char *resident_umac_file_data = NULL;
		u32 *param;

		for (section = 0; section < section_cnt; section++) {
			param = (u32 *)pbuf;
			if (param[0] <= off2_start &&
			    (param[0] + param[3]) > off2_end) {
				resident_file_data =
					(char *)src + (param[1] & FW_SECTION_SIZE_MASK) +
					(off2_start - param[0]);
				cl_dbg_info(cl_hw, "resident_file_data=0x%p.\n",
					    resident_file_data);
			}

			if (param[0] <= off3_start &&
			    (param[0] + param[3]) >= off3_end) {
				resident_umac_file_data =
					(char *)src + (param[1] & FW_SECTION_SIZE_MASK) +
					(off3_start - param[0]);
				cl_dbg_info(cl_hw, "resident_umac_file_data=0x%p.\n",
					    resident_umac_file_data);
			}

			if (param[0] == FW_OFFLOAD_MEM_BASE_ADDR) {
				char *pfake = (char *)src + (param[1] & FW_SECTION_SIZE_MASK);

				cl_dbgfile_store_offload_data(chip,
							      cl_hw,
							      pfake, param[2],
							      FW_OFFLOAD_MEM_BASE_ADDR,
							      resident_file_data,
							      off2_end - off2_start,
							      off2_start,
							      resident_umac_file_data,
							      off3_end - off3_start,
							      off3_start);

				break; /* This should be last section */
			}
			pbuf += 16;
		}

		if (!resident_file_data)
			cl_dbg_warn(cl_hw, "FW resident data block [%#X-%#X] not found!\n",
				    off2_start, off2_end);
	}

	return 0;
}

static int cl_fw_load_test(struct cl_chip *chip, char *fw_name,
			   enum cl_fw_file_type type)
{
	const struct firmware *fw;
	int rc;
	char path_name[CL_PATH_MAX] = {0};
	char *data;

	snprintf(path_name, sizeof(path_name), "cl6k/%s", fw_name);
	rc = request_firmware(&fw, path_name, chip->dev);

	if (rc) {
		cl_dbg_chip_err(chip, "# Failed to get %s, with error: %x!\n",
				path_name, rc);
		goto out;
	}

	if (type == CL_FW_FILE_SMAC) {
		data = vzalloc(fw->size);
		if (!data)
			goto out;

		memcpy(data, fw->data, fw->size);

		rc = add_bt_config(chip, data);
		if (rc) {
			vfree(data);
			goto out;
		}

		rc = chip_ops_fw_upload(chip, type, data, fw->size);
		vfree(data);
	} else {
		rc = chip_ops_fw_upload(chip, type, (u8 *)fw->data, fw->size);
	}

out:
	release_firmware(fw);

	return rc;
}

static int cl_fw_load_operational_lmac(struct cl_hw *cl_hw)
{
	int rc;
	const struct firmware *fw;
	char *fw_ptr;
	size_t fw_size;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_cached_fw *cached_fw = &cl_hw->cached_fw;

	clear_bit(CL_DEV_FW_SYNC, &cl_hw->drv_flags);

	if (!cached_fw->data) {
		char path_name[CL_PATH_MAX] = {0};

		snprintf(path_name, sizeof(path_name), "cl6k/%s",
			 chip->conf->ce_lmac);
		rc = request_firmware(&fw, path_name, chip->dev);

		if (rc) {
			cl_dbg_err(cl_hw, "# Failed to get %s, with error: %x\n",
				   path_name, rc);
			return rc;
		}
		cached_fw->data = vzalloc(fw->size);
		if (!cached_fw->data) {
			release_firmware(fw);
			return -ENOMEM;
		}
		memcpy(cached_fw->data, fw->data, fw->size);
		cached_fw->size = fw->size;
		release_firmware(fw);
	}

	rc = cl_fw_unpack(cached_fw->data, cached_fw->size,
			  "lmacfw.main", &fw_ptr, &fw_size);

	if (rc == 0) {
		rc = cl_fw_phdrs_upload(chip, cl_hw, LMAC_DRAM_FW_ADDR,
					fw_ptr, fw_size);
		/* Load other stuff packed in firmware container */
		if (rc == 0)
			rc = cl_fw_load_other(cl_hw, "lmacfw.dbg");
	} else if (rc != -ENOENT) {
		/* Assume it is a single file, not a container (used for tests) */
		rc = cl_fw_phdrs_upload(chip, cl_hw, LMAC_DRAM_FW_ADDR,
					cached_fw->data, cached_fw->size);
	}

	return rc;
}

static int cl_fw_load_lmac(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;

	if (chip->fw_test) {
		if (cl_fw_load_test(chip, chip->conf->ce_lmac,
				    CL_FW_FILE_LMAC))
			return -1;
	} else {
		if (cl_fw_load_operational_lmac(cl_hw))
			return -1;
	}

	cl_hw->fw_active = true;

	return 0;
}

static int cl_fw_load_test_smac(struct cl_chip *chip)
{
	if (!chip->smac_active &&
	    chip->fw_test &&
	    strcmp(chip->conf->ce_smac, TEST_NO_LOAD)) {
		if (cl_fw_load_test(chip, chip->conf->ce_smac,
				    CL_FW_FILE_SMAC))
			return -1;

		chip->smac_active = true;
	}

	return 0;
}

static int cl_fw_load_test_umac(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;

	if (!chip->umac_active &&
	    chip->fw_test &&
	    strcmp(chip->conf->ce_umac, TEST_NO_LOAD)) {
		if (cl_fw_load_test(chip, chip->conf->ce_umac,
				    CL_FW_FILE_UMAC))
			return -1;

		chip->umac_active = true;
	}

	return 0;
}

int cl_fw_file_load(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_conf *conf = chip->conf;
	int rc = -1;

	/* Load LMAC */
	if (strcmp(conf->ce_lmac, TEST_NO_LOAD)) {
		rc = cl_fw_load_lmac(cl_hw);
		if (rc)
			return rc;
	}

	/* Load SMAC - firmware test only */
	if (strcmp(conf->ce_smac, TEST_NO_LOAD) &&
	    strcmp(conf->ce_smac, "smacfw.bin")) {
		rc = cl_fw_load_test_smac(chip);
		if (rc)
			return rc;
	}

	/* Load UMAC - firmware test only */
	if (strcmp(conf->ce_umac, TEST_NO_LOAD) &&
	    strcmp(conf->ce_umac, "umacfw.bin"))
		rc = cl_fw_load_test_umac(cl_hw);

	return rc;
}

void cl_fw_file_cleanup(struct cl_hw *cl_hw)
{
	/* Clean up all firmware allocations in cl_hw */
	cl_dbgfile_release_mem(&cl_hw->dbg_data, &cl_hw->str_offload_env);
}

void cl_fw_file_release_cached_fw(struct cl_cached_fw *cached_fw)
{
	if (!cached_fw->data)
		return;

	vfree(cached_fw->data);
	cached_fw->data = NULL;
	cached_fw->size = 0;
}

void cl_fw_file_release(struct cl_hw *cl_hw)
{
	struct cl_cached_fw *cached_fw = &cl_hw->cached_fw;

	if (cached_fw->data) {
		struct cl_dma_accessed *fw_rom = &cl_hw->fw_remote_rom;

		cl_fw_file_release_cached_fw(cached_fw);

		if (fw_rom->drv_v_addr) {
			dma_addr_t phys_dma_addr = fw_rom->dma_addr;

			chip_ops_free_coherent(cl_hw->chip, fw_rom->size,
					       fw_rom->drv_v_addr,
					       phys_dma_addr);
			fw_rom->drv_v_addr = NULL;
			fw_rom->size = 0;
			fw_rom->fw_v_addr = 0;
			fw_rom->dma_addr = 0;
		}
	}
}
