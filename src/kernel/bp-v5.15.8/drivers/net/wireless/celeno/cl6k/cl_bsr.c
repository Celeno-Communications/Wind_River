// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_bsr.h"
#include "cl_utils.h"
#include "cl_sw_txhdr.h"
#include "chip_ops.h"

static int cl_bsr_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "bsr usage:\n"
		 "-c : Print BSR data counters\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_bsr_print_counters(struct cl_hw *cl_hw)
{
	u8 tid;
	struct cl_bsr_data *bsr_data = cl_hw->bsr_info.data;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	cl_snprintf(&buf, &len, &buf_size,
		    "BSR data counters\n"
		    "|--------------|\n"
		    "|TID| Buffers  |\n"
		    "|--------------|\n");

	for (tid = 0; tid < TID_MAX; tid++)
		cl_snprintf(&buf, &len, &buf_size,
			    "|%3u|%10u|\n", tid,
			    bsr_data->bsr_byte_cnt[tid]);

	cl_snprintf(&buf, &len, &buf_size, "|--------------|\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_bsr_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	bool print_counters = false;
	u32 expected_params = -1;

	switch (cli_params->option) {
	case 'c':
		print_counters = true;
		expected_params = 0;
		break;
	case '?':
		return cl_bsr_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (print_counters)
		return cl_bsr_print_counters(cl_hw);

out_err:
	return -EIO;
}

int cl_bsr_alloc(struct cl_hw *cl_hw)
{
	struct cl_bsr_data *buf = NULL;
	u32 len = sizeof(struct cl_bsr_data);
	dma_addr_t phys_dma_addr;

	buf = chip_ops_alloc_coherent(cl_hw->chip, len, GFP_KERNEL, &phys_dma_addr);
	if (!buf)
		return -ENOMEM;

	cl_hw->bsr_info.data = buf;
	cl_hw->bsr_info.dma_addr = phys_dma_addr;

	return 0;
}

void cl_bsr_free(struct cl_hw *cl_hw)
{
	struct cl_bsr_info *bsr_info = &cl_hw->bsr_info;
	u32 len = sizeof(struct cl_bsr_data);
	dma_addr_t phys_dma_addr = bsr_info->dma_addr;

	if (!bsr_info->data)
		return;

	chip_ops_free_coherent(cl_hw->chip, len, (void *)bsr_info->data, phys_dma_addr);
	bsr_info->data = NULL;
}

void cl_bsr_counters_dec(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr)
{
	struct cl_bsr_data *bsr_data = cl_hw->bsr_info.data;
	u32 bsr_byte_cnt;

	if (!sw_txhdr->cl_sta)
		return;

	bsr_byte_cnt = bsr_data->bsr_byte_cnt[sw_txhdr->tid];

	if (bsr_byte_cnt >= sw_txhdr->total_pkt_len)
		bsr_byte_cnt -= sw_txhdr->total_pkt_len;
	else
		bsr_byte_cnt = 0;

	bsr_data->bsr_byte_cnt[sw_txhdr->tid] = bsr_byte_cnt;
}

void cl_bsr_counters_inc(struct cl_hw *cl_hw, struct cl_sw_txhdr *sw_txhdr, u16 bytes)
{
	struct cl_bsr_data *bsr_data = cl_hw->bsr_info.data;
	int tid = sw_txhdr->tid & IEEE80211_QOS_CTL_TAG1D_MASK;
	u32 bsr_byte_cnt = bsr_data->bsr_byte_cnt[tid];

	if ((U32_MAX - bytes) > bytes)
		bsr_byte_cnt += bytes;
	else
		bsr_byte_cnt = U32_MAX;

	bsr_data->bsr_byte_cnt[tid] = bsr_byte_cnt;
	sw_txhdr->total_pkt_len += bsr_byte_cnt;
}

void cl_bsr_counters_reset(struct cl_hw *cl_hw)
{
	u8 tid;

	for (tid = 0; tid < TID_MAX; tid++)
		cl_hw->bsr_info.data->bsr_byte_cnt[tid] = 0;
}
