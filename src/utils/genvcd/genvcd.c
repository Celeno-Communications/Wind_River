/*
 * Copyright (C) Celeno 2022
 *
 * Usage: genvcd <dump_dir> [raw_path]
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "genvcd.h"

// CL6000 AXI spec, Section 6.3
struct mode_info mac_narrow_0_mode_info_arr[MAC_ELA_MODE_MAX] = {
	/* mac_top0_hw_diag [95:0]  */
	[0]  = {{PORT_ID_LEGACY_A, PORT_ID_LEGACY_B, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], debug_apb[31:0], ntt0_debug[31:0] */
	[1]  = {{PORT_ID_NTT, PORT_ID_APB, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], debug_apb[31:0], debug_int_LMAC[31:0] */
	[2]  = {{PORT_ID_NTT, PORT_ID_LEGACY_B, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], debug_apb[31:0], debug_int_LMAC[31:0] */
	[3]  = {{PORT_ID_LMAC_INT, PORT_ID_APB, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:32], debug_int_LMAC[31:0] */
	[4]  = {{PORT_ID_LMAC_INT, PORT_ID_LEGACY_B, PORT_ID_LEGACY_C}},
	/* LMAC basic debug */
	[5]  = {{PORT_ID_LMAC_BASIC}},
	/* SMAC basic debug */
	[6]  = {{PORT_ID_SMAC_BASIC}},
	/* UMAC basic debug */
	[7] =  {{PORT_ID_UMAC_BASIC}},
	/* LMAC extended debug  */
	[8] =  {{PORT_ID_LMAC_EXTND}},
	/* SMAC extended debug  */
	[9] =  {{PORT_ID_SMAC_EXTND}},
	/* UMAC extended debug  */
	[10] = {{PORT_ID_UMAC_EXTND}},
	/* mac_top0_hw_diag [95:64], PCIEW[31:0],BRU[31:0] */
	[11] = {{PORT_ID_BRU, PORT_ID_PCIEW, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], PCIEW[31:0],E2W[31:0] */
	[12] = {{PORT_ID_E2W, PORT_ID_PCIEW, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag[223:0] */
	[13] = {{PORT_ID_INVALID}}, // TODO: mac wide. currently done by lcu_build_wide_mode_0
	/* mac_top0_hw_diag [95:64], BAU[31:0], RXM0[31:0] */
	[14] = {{PORT_ID_RXM_A, PORT_ID_BAU, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], PCIEW[31:0], RXM0[31:0] */
	[15] = {{PORT_ID_RXM_A, PORT_ID_PCIEW, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:32], RXM0[31:0] */
	[16] = {{PORT_ID_RXM_A, PORT_ID_LEGACY_B, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], RXM0[63:0] */
	[17] = {{PORT_ID_RXM_A, PORT_ID_RXM_B, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], BAU[31:0], BRU[31:0] */
	[18] = {{PORT_ID_BRU, PORT_ID_BAU, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], debug_int_LMAC[31:0], BAP0[31:0] */
	[19] = {{PORT_ID_BAP, PORT_ID_LMAC_INT, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:32], RFICW[31:0] */
	[20] = {{PORT_ID_RFICW, PORT_ID_LEGACY_B, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:32], TXM0[31:0] */
	[21] = {{PORT_ID_TXM, PORT_ID_LEGACY_B, PORT_ID_LEGACY_C}},
	/* PCIEW[31:0],E2W[31:0], TXM0[31:0] */
	[22] = {{PORT_ID_TXM, PORT_ID_E2W, PORT_ID_PCIEW}},
	/* mac_top0_hw_diag [95:32], PTA[31:0] */
	[23] = {{PORT_ID_PTA, PORT_ID_LEGACY_B, PORT_ID_LEGACY_C}},
	/* USBW[31:0], USBC[63:0] */
	[24] = {{PORT_ID_USBC, PORT_ID_USBW}},
	/* USBW[31:0], E2W[31:0], TXM0[31:0] */
	[25] = {{PORT_ID_TXM, PORT_ID_E2W, PORT_ID_USBW}},
	/* mac_top0_hw_diag [95:64], USBW[31:0],BRU[31:0] */
	[26] = {{PORT_ID_BRU, PORT_ID_USBW, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], USBW[31:0],E2W[31:0] */
	[27] = {{PORT_ID_E2W, PORT_ID_USBW, PORT_ID_LEGACY_C}},
	/* mac_top0_hw_diag [95:64], USBW[31:0], RXM0[31:0] */
	[28] = {{PORT_ID_RXM_A, PORT_ID_USBW, PORT_ID_LEGACY_C}},
	/* USBW[31:0], debug_int_UMAC[31:0],idma[31:0] */
	[29] = {{PORT_ID_IDMA, PORT_ID_UMAC_INT, PORT_ID_USBW}},
	/* USBW[31:0], E2W[31:0],idma[31:0] */
	[30] = {{PORT_ID_IDMA, PORT_ID_E2W, PORT_ID_USBW}},
	/* USBW[31:0], BRU[31:0], idma[31:0] */
	[31] = {{PORT_ID_IDMA, PORT_ID_BRU, PORT_ID_USBW}},
	/* USBW[31:0], debug_int_UMAC[31:0], debug_int_SMAC[31:0] */
	[32] = {{PORT_ID_SMAC_INT, PORT_ID_UMAC_INT, PORT_ID_USBW}},
	/* USBW[31:0], TCI[31:0], TXM[31:0] */
	[33] = {{PORT_ID_TXM, PORT_ID_TCI, PORT_ID_USBW}},
	/* PCIEW[31:0], TCI[31:0], TXM[31:0] */
	[34] = {{PORT_ID_TXM, PORT_ID_TCI, PORT_ID_PCIEW}},
	/* mac_top0_hw_diag[95:64], TCI[31:0], TXM[31:0] */
	[35] = {{PORT_ID_TXM, PORT_ID_TCI, PORT_ID_LEGACY_C}},
};

const struct port_info port_info_arr[PORT_ID_MAX] = {
	/*                      size                diag base           max mode                name        prefix*/
	[PORT_ID_LEGACY_A]   = {PORT_SIZE_DEFAULT,  PORT_BASE_LEGACY,   PORT_MODE_MAX_LEGACY,   "hwa",      ""},
	[PORT_ID_LEGACY_B]   = {PORT_SIZE_DEFAULT,  PORT_BASE_LEGACY,   PORT_MODE_MAX_LEGACY,   "hwb",      ""},
	[PORT_ID_LEGACY_C]   = {PORT_SIZE_DEFAULT,  PORT_BASE_LEGACY,   PORT_MODE_MAX_LEGACY,   "hwc",      ""},
	[PORT_ID_BAU]        = {PORT_SIZE_DEFAULT,  PORT_BASE_BAU,      PORT_MODE_MAX_BAU,      "bau",      ""},
	[PORT_ID_PCIEW]      = {PORT_SIZE_DEFAULT,  PORT_BASE_PCIEW,    PORT_MODE_MAX_PCIEW,    "pciew",    ""},
	[PORT_ID_BRU]        = {PORT_SIZE_DEFAULT,  PORT_BASE_BRU,      PORT_MODE_MAX_BRU,      "bru",      ""},
	[PORT_ID_BAP]        = {PORT_SIZE_DEFAULT,  PORT_BASE_BAP,      PORT_MODE_MAX_BAP,      "bap",      ""},
	[PORT_ID_RFICW]      = {PORT_SIZE_DEFAULT,  PORT_BASE_RFICW,    PORT_MODE_MAX_RFICW,    "rficw",    ""},
	[PORT_ID_RXM_A]      = {PORT_SIZE_DEFAULT,  PORT_BASE_RXM,      PORT_MODE_MAX_RXM,      "rxma",     ""},
	[PORT_ID_RXM_B]      = {PORT_SIZE_DEFAULT,  PORT_BASE_RXM,      PORT_MODE_MAX_RXM,      "rxmb",     ""},
	[PORT_ID_TXM]        = {PORT_SIZE_DEFAULT,  PORT_BASE_TXM,      PORT_MODE_MAX_TXM,      "txm",      ""},
	[PORT_ID_LMAC_INT]   = {PORT_SIZE_DEFAULT,  PORT_BASE_LMAC_INT, PORT_MODE_MAX_LMAC_INT, "lmac_int", ""},
	[PORT_ID_SMAC_INT]   = {PORT_SIZE_DEFAULT,  PORT_BASE_SMAC_INT, PORT_MODE_MAX_SMAC_INT, "smac_int", ""},
	[PORT_ID_UMAC_INT]   = {PORT_SIZE_DEFAULT,  PORT_BASE_UMAC_INT, PORT_MODE_MAX_UMAC_INT, "umac_int", ""},
	[PORT_ID_LMAC_BASIC] = {PORT_SIZE_XT,       PORT_BASE_XT_BASIC, PORT_MODE_MAX_XT_BASIC, "lmac_bsc", "LMAC"},
	[PORT_ID_SMAC_BASIC] = {PORT_SIZE_XT,       PORT_BASE_XT_BASIC, PORT_MODE_MAX_XT_BASIC, "smac_bsc", "SMAC"},
	[PORT_ID_UMAC_BASIC] = {PORT_SIZE_XT,       PORT_BASE_XT_BASIC, PORT_MODE_MAX_XT_BASIC, "umac_bsc", "UMAC"},
	[PORT_ID_LMAC_EXTND] = {PORT_SIZE_XT,       PORT_BASE_XT_EXTND, PORT_MODE_MAX_XT_EXTND, "lmac_xtd", "LMAC"},
	[PORT_ID_SMAC_EXTND] = {PORT_SIZE_XT,       PORT_BASE_XT_EXTND, PORT_MODE_MAX_XT_EXTND, "smac_xtd", "SMAC"},
	[PORT_ID_UMAC_EXTND] = {PORT_SIZE_XT,       PORT_BASE_XT_EXTND, PORT_MODE_MAX_XT_EXTND, "umac_xtd", "UMAC"},
	[PORT_ID_E2W]        = {PORT_SIZE_DEFAULT,  PORT_BASE_E2W,      PORT_MODE_MAX_E2W,      "e2w",      ""},
	[PORT_ID_APB]        = {PORT_SIZE_DEFAULT,  PORT_BASE_APB,      PORT_MODE_MAX_APB,      "apb",      ""},
	[PORT_ID_NTT]        = {PORT_SIZE_DEFAULT,  PORT_BASE_NTT,      PORT_MODE_MAX_NTT,      "ntt",      ""},
	[PORT_ID_PTA]        = {PORT_SIZE_DEFAULT,  PORT_BASE_PTA,      PORT_MODE_MAX_PTA,      "pta",      ""},
	[PORT_ID_TOP]        = {PORT_SIZE_DEFAULT,  PORT_BASE_TOP,      PORT_MODE_MAX_TOP,      "top",      ""},
	[PORT_ID_BT]         = {PORT_SIZE_BT,       PORT_BASE_BT,       PORT_MODE_MAX_BT,       "bt",       ""},
	[PORT_ID_BT_CMPCT]   = {PORT_SIZE_BT_CMPCT, PORT_BASE_BT_CMPCT, PORT_MODE_MAX_BT_CMPCT, "bt_cmpct", ""},
	[PORT_ID_USBW]       = {PORT_SIZE_DEFAULT,  PORT_BASE_USBW,     PORT_MODE_MAX_USBW,     "usbw",     ""},
	[PORT_ID_IDMA]       = {PORT_SIZE_DEFAULT,  PORT_BASE_IDMA,     PORT_MODE_MAX_IDMA,     "idma",     ""},
	[PORT_ID_USBC]       = {PORT_SIZE_USBC,     PORT_BASE_USBC,     PORT_MODE_MAX_USBC,     "usbc" ,    ""},
	[PORT_ID_TCI]        = {PORT_SIZE_DEFAULT,  PORT_BASE_TCI,      PORT_MODE_MAX_TCI,      "tci",      ""},
};

const char *file_id_2_file_name[DIAG_FILE_ID_MAX] = {
	[DIAG_FILE_ID_HW] = "hwdiag.txt",
	[DIAG_FILE_ID_BT] = "btdiag.txt",
	[DIAG_FILE_ID_SW] = "swdiags",
};

struct la_tag ela;
static uint32_t g_tracebuf[(LA_MAX_LINE_CNT + 1) * 4]; //trace data
char *raw_dump_file_path;

static int int2bin(char *out, uint32_t val, int width, uint32_t smp_msk)
{
	int status = -1;
	uint32_t z = 1 << (width - 1);

	out[0] = '\0';

	for (; z > 0; z >>= 1) {
		if (z & smp_msk) {
			strcat(out, ((val & z) == z) ? "1" : "0");
			status = 0;
		} else {
			strcat(out, "x");
		}
	}

	return status;
}

static ssize_t readlinex(char **lineptr, FILE *fp)
{
	char *line, *saveptr = NULL;
	size_t len = 0;
	ssize_t read;

	*lineptr = NULL;

	// Caller should free lineptr
	read = getline(lineptr, &len, fp);

	if (read <= 0) {
		return read;
	}

	line = *lineptr;

	// Read line till sapce, comment ('#') or EOL
	line = strtok_r(line, " \n#", &saveptr);

	return line ? strlen(line) : 0;
}

static int add_group(struct groups *groups, char *name, char *id_prefix,
		     int lsb, int msb, uint32_t val)
{
	struct group *g;

	if (groups->cnt == MAX_GROUPS) {
		return -1;
	}

	if (msb >= MAX_GROUPS) {
		return -1;
	}

	g = &groups->group[groups->cnt];

	strcpy(g->name, name);
	snprintf(g->id, STR_BUF_MAX + 1, "%s%d", id_prefix, groups->cnt);
	g->lsb = lsb;
	g->msb = msb;
	g->prev = val;

	groups->cnt++;

	return 0;
}

static int enlarge_group(struct groups *groups)
{
	struct group *g;

	if (groups->cnt == 0) {
		return -1;
	}

	g = &groups->group[groups->cnt - 1];

	if (g->msb >= MAX_GROUPS) {
		return -1;
	}

	g->msb++;

	return 0;
}

void vcd_file_print_headers(struct la_tag *p_ela)
{
	FILE *fp = p_ela->fp_vcd;

	if (!fp) {
		return;
	}

	fprintf(fp, "$comment\nTOOL: %s \n$end\n"
		    "$date\n$end\n"
		    "$timescale\n" TIME_UNIT_str "\n$end\n", GENVCD_VER_STR);

	fprintf(fp, "$comment\n"
		    "* samp.mask: [0]=%08X [1]=%08X [2]=%08X [3]=%08X\n"
		    "* samp.mask: [4]=%08X [5]=%08X [6]=%08X [7]=%08X\n"
		    "* trig.point: %Xh\n"
		    "$end\n",
		    p_ela->sampling[0], p_ela->sampling[1], p_ela->sampling[2], p_ela->sampling[3],
		    p_ela->sampling[4], p_ela->sampling[5], p_ela->sampling[6], p_ela->sampling[7],
		    p_ela->trigger_point);
}

static FILE *dumpdir_fopen(struct la_tag *p_ela, const char *file_name, const char *mode)
{
	FILE *fp = NULL;
	char path[STR_BUF_MAX] = {0};

	snprintf(path, STR_BUF_MAX, "%s/%s", p_ela->dumpdir, file_name);
	fp = fopen(path, mode);

	if (!fp) {
		cl_dbg_err("Failed opening %s\n", path);
		return NULL;
	}

	return fp;
}

void lcu_sample_get(sample_t *p_sample, uint32_t sample_idx, int lcu_wide)
{
	int sample_size = lcu_wide ? LCU_WIDE_ENTRY_SIZE : LCU_NARROW_ENTRY_SIZE;
	memcpy(p_sample->data, g_tracebuf + (sample_idx * sample_size), sample_size * LA_WORD_LEN);
}

int lcu_sample_vci_get(sample_t *p_sample, uint32_t lcu_wide)
{
	uint32_t sample_size = lcu_wide ? LCU_WIDE_ENTRY_SIZE : LCU_NARROW_ENTRY_SIZE;
	uint32_t raw_value = p_sample->data[sample_size - 1];
	return raw_value >> LCU_TIMESTAMP_SIZE;
}

uint32_t lcu_sample_timestamp_get(sample_t *p_sample, uint32_t lcu_wide)
{
	uint32_t sample_size = lcu_wide ? LCU_WIDE_ENTRY_SIZE : LCU_NARROW_ENTRY_SIZE;
	uint32_t raw_value = p_sample->data[sample_size - 1];
	return raw_value & LCU_TIMESTAMP_MASK;
}

uint32_t lcu_sample_bt_chan_get(sample_t *p_sample)
{
	uint32_t raw_value = p_sample->data[2];
	return (raw_value & LCU_BT_CHAN_ID_MASK) >> LCU_BT_CHAN_ID_SHIFT;
}

static int trace_open(struct la_tag *p_ela)
{
	FILE *fp;
	int oldest_sample_index, newest_sample_index;
	int num_of_lines, samples_read;
	int num_of_samples_in_512b = p_ela->samples_width ? 2 : 4;
	int num_of_samples_in_256b = p_ela->samples_width ? 1 : 2;
	int num_of_samples_in_128b = p_ela->samples_width ? 0 : 1;
	int sample_width_in_bytes = p_ela->samples_width ? 32 : 16;
	int sample_width_in_dwords = p_ela->samples_width ? 8 : 4;
	int max_num_of_samples = p_ela->samples_width ? LCU_MAX_WIDE_SAMPLES : LA_MAX_LINE_CNT;

	fp = dumpdir_fopen(p_ela, LA_RAM_BIN_FILE_NAME, "rb");
	if (!fp) {
		return -1;
	}

	// Read whole file.
	num_of_lines = fread(g_tracebuf, LA_NARROW_SAMPLE_LEN, LA_MAX_LINE_CNT, fp);
	if (num_of_lines != LA_MAX_LINE_CNT) {
		cl_dbg_err("binary trace shorter than expected \n");
		fclose(fp);
		return -1;
	}

	num_of_lines = p_ela->samples_width ? (num_of_lines >> 1) : num_of_lines;

	cl_dbg_trace("%d %s samples available in trace file.\n", num_of_lines, (p_ela->samples_width ? "wide" : "narrow"));

	if (p_ela->is_buf_wrapped) {
		// Assuming buffer has a wrap-around - need to reorder
		if (p_ela->last_wr_index % num_of_samples_in_512b) {
			// last written address is not 512bit aligned
			oldest_sample_index = p_ela->last_wr_index + num_of_samples_in_256b; // for wide +1 : for narrow +2
			newest_sample_index = p_ela->last_wr_index + num_of_samples_in_128b; // for wide +0 : for narrow +1
		} else {
			// last written address is 512bit aligned
			oldest_sample_index = p_ela->last_wr_index + num_of_samples_in_512b; // for wide +2 : for narrow +4
			newest_sample_index = p_ela->last_wr_index + num_of_samples_in_128b; // for wide +0 : for narrow +1
			num_of_lines -= num_of_samples_in_256b; // one/two zero samples  // for wide -1 : for narrow -2
		}

		// Note: If we are here we have a wrap-around point in the buffer hence we want to reorder.
		// elapse the tracebuf - we will re-write it now with the correct sample timing order
		memset(&g_tracebuf[0], 0, sizeof(g_tracebuf));

		// Read after last written to end of buffer:
		if (0 != fseek(fp, (oldest_sample_index*sample_width_in_bytes), SEEK_SET)) {
			cl_dbg_err("fseek 1\n");
			fclose(fp);
			return -1;
		}
		samples_read = fread(g_tracebuf, sample_width_in_bytes, (max_num_of_samples - oldest_sample_index), fp);
		cl_dbg_trace("wrap part1 - %d samples: from sample %d to sample %d.\n", samples_read, oldest_sample_index, max_num_of_samples);
		if (samples_read != (max_num_of_samples-oldest_sample_index)) {
			cl_dbg_err("read too little(1): %d\n", samples_read);
			fclose(fp);
			return -1;
		}
		// read from start to (incl) last written:
		rewind(fp);
		samples_read = fread(&g_tracebuf[samples_read * sample_width_in_dwords], sample_width_in_bytes, newest_sample_index + 1, fp);
		cl_dbg_trace("wrap part2 - %d samples: from sample 0 to sample %d.\n", samples_read, newest_sample_index);
		if (samples_read != newest_sample_index + 1) {
			cl_dbg_err("read too little(2): %d\n", samples_read);
			fclose(fp);
			return -1;
		}
		cl_dbg_trace("total %d samples (oldest_sample_index=%d,newest_sample_index=%d).\n",
			     ((max_num_of_samples - oldest_sample_index) + newest_sample_index + 1), oldest_sample_index, newest_sample_index);
	} else {
		// no wrap-around - no re-order !!!
		oldest_sample_index = 0;
		newest_sample_index = p_ela->last_wr_index + num_of_samples_in_128b;
		num_of_lines = newest_sample_index+1;
		cl_dbg_trace("No wrap-around: no smaples re-order needed (oldest=%d, newest=%d)\n",
			     oldest_sample_index, newest_sample_index);
	}

	p_ela->samples_num = num_of_lines;
	fclose(fp);
	return 0;
}

void lcu_conf_print(struct la_conf_tag *confdata, FILE *fp)
{
	fprintf(fp, "lcu_common.la_version = %#x\n", confdata->lcu_common.la_version);
	fprintf(fp, "lcu_common.lcu_mode.ch0_conf = %#x\n", confdata->lcu_common.lcu_mode.ch0_conf);
	fprintf(fp, "lcu_common.lcu_mode.ch1_conf = %#x\n", confdata->lcu_common.lcu_mode.ch1_conf);
	fprintf(fp, "lcu_common.lcu_mode.ch2_conf = %#x\n", confdata->lcu_common.lcu_mode.ch2_conf);
	fprintf(fp, "lcu_common.lcu_mode.ch3_conf = %#x\n", confdata->lcu_common.lcu_mode.ch3_conf);
	fprintf(fp, "lcu_common.lcu_mode.ch4_conf = %#x\n", confdata->lcu_common.lcu_mode.ch4_conf);
	fprintf(fp, "lcu_common.lcu_mode.ch5_conf = %#x\n", confdata->lcu_common.lcu_mode.ch5_conf);
	fprintf(fp, "lcu_common.lcu_mode.int_raw_stat = %#x\n", confdata->lcu_common.lcu_mode.int_raw_stat);
	fprintf(fp, "lcu_common.lcu_mode.capture_mode = %#x\n", confdata->lcu_common.lcu_mode.capture_mode);
	fprintf(fp, "lcu_common.lcu_mode.blk_exp = %#x\n", confdata->lcu_common.lcu_mode.blk_exp);
	fprintf(fp, "lcu_common.lcu_status = %#x\n", confdata->lcu_common.lcu_status);
	fprintf(fp, "lcu_common.lcu_start_addr = %#x\n", confdata->lcu_common.lcu_start_addr);
	fprintf(fp, "lcu_common.lcu_write_addr = %#x\n", confdata->lcu_common.lcu_write_addr);
	fprintf(fp, "lcu_common.lcu_end_addr = %#x\n", confdata->lcu_common.lcu_end_addr);
	fprintf(fp, "lcu_common.rec_start_timestamp = %#x\n", confdata->lcu_common.rec_start_timestamp);
	fprintf(fp, "lcu_common.rec_end_timestamp = %#x\n", confdata->lcu_common.rec_end_timestamp);
	fprintf(fp, "lcu_common.lcu_common_vci = %#x\n", confdata->lcu_common.lcu_common_vci);
	fprintf(fp, "lcu_common.rec_stop_addr = %#x\n", confdata->lcu_common.rec_stop_addr);
	fprintf(fp, "lcu_common.blk_wr_cnt = %#x\n", confdata->lcu_common.blk_wr_cnt);

	fprintf(fp, "lcu_mac_conf.ch0_enable = %#x\n", confdata->lcu_mac_conf.ch0_enable);
	fprintf(fp, "lcu_mac_conf.ch0_select = %#x\n", confdata->lcu_mac_conf.ch0_select);
	fprintf(fp, "lcu_mac_conf.ch1_enable = %#x\n", confdata->lcu_mac_conf.ch1_enable);
	fprintf(fp, "lcu_mac_conf.ch1_select = %#x\n", confdata->lcu_mac_conf.ch1_select);
	fprintf(fp, "lcu_mac_conf.mac_debug_port_sela = %#x\n", confdata->lcu_mac_conf.mac_debug_port_sela);
	fprintf(fp, "lcu_mac_conf.mac_debug_port_selb = %#x\n", confdata->lcu_mac_conf.mac_debug_port_selb);
	fprintf(fp, "lcu_mac_conf.mac_debug_port_selc = %#x\n", confdata->lcu_mac_conf.mac_debug_port_selc);
	fprintf(fp, "lcu_mac_conf.mac_debug_port_control = %#x\n", confdata->lcu_mac_conf.mac_debug_port_control);

	for (int i = 0; i < MAC_ELA_MASK_REG_COUNT; i++) {
		fprintf(fp, "lcu_mac_conf.mac_sampling_mask[%d] = %#x\n", i, confdata->lcu_mac_conf.mac_sampling_mask[i]);
	}

	fprintf(fp, "lcu_mac_conf.pciew_dbg_sel = %#x\n", confdata->pciew_dbg_sel);
	fprintf(fp, "lcu_mac_conf.pta_dbg_sel = %#x\n", confdata->pta_dbg_sel);
	fprintf(fp, "lcu_mac_conf.bau_dbg_sel = %#x\n", confdata->bau_dbg_sel);
	fprintf(fp, "lcu_mac_conf.rxm_dbg_sel = %#x\n", confdata->rxm_dbg_sel);
	fprintf(fp, "lcu_mac_conf.txm_dbg_sel = %#x\n", confdata->txm_dbg_sel);
	fprintf(fp, "lcu_mac_conf.usbw_dbg_sel = %#x\n", confdata->usbw_dbg_sel);
	fprintf(fp, "lcu_mac_conf.usbc_dbg_sel = %#x\n", confdata->usbc_dbg_sel);
	fprintf(fp, "lcu_mac_conf.idma_dbg_sel = %#x\n", confdata->idma_dbg_sel);

	fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_dmem_start = %#x\n", confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_dmem_start);
	fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_dmem_size = %#x\n", confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_dmem_size);
	fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_status = %#x\n", confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_status);
	fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_mpif_data_sel = %#x\n", confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_mpif_data_sel);
	fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_rx_riu_out20s_en = %#x\n", confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_rx_riu_out20s_en);

	for (int i = 0; i < PHY_LCU_START_PTRN_REG_COUNT; i++) {
		fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_phy_ch_strt_ptrn_mask[%d] = %#x\n", i, confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_phy_ch_strt_ptrn_mask[i]);
	}

	for (int i = 0; i < PHY_LCU_STOP_PTRN_REG_COUNT; i++) {
		fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_phy_ch_stop_ptrn_mask[%d] = %#x\n", i, confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_phy_ch_stop_ptrn_mask[i]);
	}

	fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_phy_ch_mictors_bmp_0 = %#x\n", confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_phy_ch_mictors_bmp_0);
	fprintf(fp, "lcu_phy_conf.lcu_phy_gnrl.lcu_phy_ch_mictors_bmp_1 = %#x\n", confdata->lcu_phy_conf.lcu_phy_gnrl.lcu_phy_ch_mictors_bmp_1);

	for (int ch_id = 0; ch_id < PHY_LCU_CHAN_CNT; ch_id++) {
		fprintf(fp, "lcu_phy_conf.lcu_phy_channel[%d].lcu_phy_ch_conf = %#x\n", ch_id, confdata->lcu_phy_conf.lcu_phy_channel[ch_id].lcu_phy_ch_conf);
		fprintf(fp, "lcu_phy_conf.lcu_phy_channel[%d].lcu_phy_ch_chains_bmp = %#x\n", ch_id, confdata->lcu_phy_conf.lcu_phy_channel[ch_id].lcu_phy_ch_chains_bmp);
		fprintf(fp, "lcu_phy_conf.lcu_phy_channel[%d].lcu_phy_ch_decimation = %#x\n", ch_id, confdata->lcu_phy_conf.lcu_phy_channel[ch_id].lcu_phy_ch_decimation);
		fprintf(fp, "lcu_phy_conf.lcu_phy_channel[%d].lcu_phy_ch_trig_status = %#x\n", ch_id, confdata->lcu_phy_conf.lcu_phy_channel[ch_id].lcu_phy_ch_trig_status);
		fprintf(fp, "lcu_phy_conf.lcu_phy_channel[%d].lcu_phy_ch_en = %#x\n", ch_id, confdata->lcu_phy_conf.lcu_phy_channel[ch_id].lcu_phy_ch_en);
	}

	for (int i = 0; i < LCU_PHY_REGS_MAX; i++) {
		fprintf(fp, "lcu_phy_conf.lcu_phy_reg[%d]] = %#x\n", i, confdata->lcu_phy_conf.lcu_phy_regs[i]);
	}

	fprintf(fp, "lcu_phy_conf.rficw_dbg_sel= %#x\n", confdata->rficw_dbg_sel);
	fprintf(fp, "lcu_phy_conf.dsp_version = %#x\n", confdata->dsp_version);

	fprintf(fp, "lcu_common.lcu_bt_en= %#x\n", confdata->lcu_common.lcu_bt_en);
	fprintf(fp, "lcu_common.lcu_bt_ch_valid= %#x\n", confdata->lcu_common.lcu_bt_ch_valid);
	fprintf(fp, "lcu_bt_conf.controller_sub_ch_en= %#x\n", confdata->lcu_bt_conf.controller_sub_ch_en);
	fprintf(fp, "lcu_bt_conf.modem_sub_ch_en= %#x\n", confdata->lcu_bt_conf.modem_sub_ch_en);
	fprintf(fp, "lcu_bt_conf.controller_sub_ch_idx0= %#x\n", confdata->lcu_bt_conf.controller_sub_ch_idx0);
	fprintf(fp, "lcu_bt_conf.controller_sub_ch_idx1= %#x\n", confdata->lcu_bt_conf.controller_sub_ch_idx1);
	fprintf(fp, "lcu_bt_conf.controller_sub_ch_idx2= %#x\n", confdata->lcu_bt_conf.controller_sub_ch_idx2);
	fprintf(fp, "lcu_bt_conf.controller_sub_ch_idx3= %#x\n", confdata->lcu_bt_conf.controller_sub_ch_idx3);
	fprintf(fp, "lcu_bt_conf.controller_sub_ch_idx4= %#x\n", confdata->lcu_bt_conf.controller_sub_ch_idx4);
	fprintf(fp, "lcu_bt_conf.controller_sub_ch_idx5= %#x\n", confdata->lcu_bt_conf.controller_sub_ch_idx5);
	fprintf(fp, "lcu_bt_conf.modem_sub_ch_idx0= %#x\n", confdata->lcu_bt_conf.modem_sub_ch_idx0);
	fprintf(fp, "lcu_bt_conf.modem_sub_ch_idx1= %#x\n", confdata->lcu_bt_conf.modem_sub_ch_idx1);
	fprintf(fp, "lcu_bt_conf.modem_sub_ch_idx2= %#x\n", confdata->lcu_bt_conf.modem_sub_ch_idx2);
	fprintf(fp, "lcu_bt_conf.modem_sub_ch_idx3= %#x\n", confdata->lcu_bt_conf.modem_sub_ch_idx3);
	fprintf(fp, "lcu_bt_conf.modem_sub_ch_idx4= %#x\n", confdata->lcu_bt_conf.modem_sub_ch_idx4);
	fprintf(fp, "lcu_bt_conf.modem_sub_ch_idx5= %#x\n", confdata->lcu_bt_conf.modem_sub_ch_idx5);
	fprintf(fp, "lcu_bt_conf.controller_mask_idx= %#x\n", confdata->lcu_bt_conf.controller_mask_idx);
	fprintf(fp, "lcu_bt_conf.controller_mask[0]= %#x\n", confdata->lcu_bt_conf.controller_mask[0]);
	fprintf(fp, "lcu_bt_conf.controller_mask[1]= %#x\n", confdata->lcu_bt_conf.controller_mask[1]);
	fprintf(fp, "lcu_bt_conf.controller_mask[2]= %#x\n", confdata->lcu_bt_conf.controller_mask[2]);
	fprintf(fp, "lcu_bt_conf.modem_mask_idx= %#x\n", confdata->lcu_bt_conf.modem_mask_idx);
	fprintf(fp, "lcu_bt_conf.modem_mask[0]= %#x\n", confdata->lcu_bt_conf.modem_mask[0]);
	fprintf(fp, "lcu_bt_conf.modem_mask[1]= %#x\n", confdata->lcu_bt_conf.modem_mask[1]);
	fprintf(fp, "lcu_bt_conf.modem_mask[2]= %#x\n", confdata->lcu_bt_conf.modem_mask[2]);
}

void ela_rxm_dbg_sel_get(struct la_tag *p_ela, int rxm_dbg_sel)
{
	// 4'd6 : rxm_debug <= {info_debug, sm_debug};             // mode1 + mode0
	// 4'd7 : rxm_debug <= {axi_rd_ctl_debug, sm_debug};       // mode2 + mode0
	// 4'd8 : rxm_debug <= {axi_wr_ctl_debug, sm_debug};       // mode4 + mode0
	// 4'd9 : rxm_debug <= {rxm_axi_rdata, axi_rd_ctl_debug};  // mode3 + mode2
	// 4'd10 : rxm_debug <= {rxm_axi_wdata, axi_wr_ctl_debug}; // mode5 + mode4
	switch (rxm_dbg_sel) {
	case 6:
		p_ela->dbg_sel[PORT_ID_RXM_A] = 0;
		p_ela->dbg_sel[PORT_ID_RXM_B] = 1;
		break;
	case 7:
		p_ela->dbg_sel[PORT_ID_RXM_A] = 0;
		p_ela->dbg_sel[PORT_ID_RXM_B] = 2;
		break;
	case 8:
		p_ela->dbg_sel[PORT_ID_RXM_A] = 0;
		p_ela->dbg_sel[PORT_ID_RXM_B] = 4;
		break;
	case 9:
		p_ela->dbg_sel[PORT_ID_RXM_A] = 2;
		p_ela->dbg_sel[PORT_ID_RXM_B] = 3;
		break;
	case 10:
		p_ela->dbg_sel[PORT_ID_RXM_A] = 4;
		p_ela->dbg_sel[PORT_ID_RXM_B] = 5;
		break;
	default:
		p_ela->dbg_sel[PORT_ID_RXM_A] = rxm_dbg_sel;
		p_ela->dbg_sel[PORT_ID_RXM_B] = PORT_MODE_MAX_RXM;
	}
}

void ela_conf_dbg_sel_get(struct la_tag *p_ela, struct la_conf_tag *p_conf)
{
	memset(p_ela->dbg_sel, 0, sizeof(p_ela->dbg_sel));

	p_ela->dbg_sel[PORT_ID_LEGACY_A] = p_conf->lcu_mac_conf.mac_debug_port_sela;
	p_ela->dbg_sel[PORT_ID_LEGACY_B] = p_conf->lcu_mac_conf.mac_debug_port_selb;
	p_ela->dbg_sel[PORT_ID_LEGACY_C] = p_conf->lcu_mac_conf.mac_debug_port_selc;
	p_ela->dbg_sel[PORT_ID_BAU] = p_conf->bau_dbg_sel;
	p_ela->dbg_sel[PORT_ID_PCIEW] = p_conf->pciew_dbg_sel;
	p_ela->dbg_sel[PORT_ID_RFICW] = p_conf->rficw_dbg_sel;
	p_ela->dbg_sel[PORT_ID_TXM] = p_conf->txm_dbg_sel;
	p_ela->dbg_sel[PORT_ID_PTA] = p_conf->pta_dbg_sel;
	p_ela->dbg_sel[PORT_ID_IDMA] = p_conf->idma_dbg_sel;
	p_ela->dbg_sel[PORT_ID_USBW] = p_conf->usbw_dbg_sel;
	p_ela->dbg_sel[PORT_ID_USBC] = p_conf->usbc_dbg_sel;
	ela_rxm_dbg_sel_get(p_ela, p_conf->rxm_dbg_sel);
}

bool is_vcd_channel(int channel_id)
{
	// only MAC_ELA and BT_LCU are parsed to vcd
	return channel_id == CHAN_ID_MAC_ELA_CHAN_0 ||
	       channel_id == CHAN_ID_MAC_ELA_CHAN_1 ||
	       channel_id == CHAN_ID_BT_LCU_CHAN;
}

bool is_channel_enabled(struct la_tag *p_ela, int channel_id)
{
	return p_ela->lcu_chan[channel_id].enable;
}

bool is_channel_wide(struct la_tag *p_ela, int channel_id)
{
	return p_ela->lcu_chan[channel_id].conf & BIT(CH_REC_FORMAT);
}

bool channels_share_vci_check(struct la_tag *p_ela)
{
	bool shared_vci = false;

	for (int i = 0; i < LCU_COMMON_CHAN_CNT; i++) {
		for (int j = i + 1; j < LCU_COMMON_CHAN_CNT; j++) {
			if (is_channel_enabled(p_ela, i) &&
			    is_channel_enabled(p_ela, j) &&
			    p_ela->lcu_chan[i].vci == p_ela->lcu_chan[j].vci) {
				shared_vci = true;
				cl_dbg_warn("channels %d and %d are sharing vci=%d",
					    i, j, p_ela->lcu_chan[i].vci);
			}
		}
	}

	return shared_vci;
}

bool mixed_narrow_wide(struct la_tag *p_ela)
{
	// Only MAC_ELA_0 and PHY_LCU_0 can be wide
	bool mac_wide_used = is_channel_enabled(p_ela, CHAN_ID_MAC_ELA_CHAN_0) &&
			     is_channel_wide(p_ela, CHAN_ID_MAC_ELA_CHAN_0);
	bool phy_wide_used = is_channel_enabled(p_ela, CHAN_ID_PHY_LCU_CHAN_0) &&
			     is_channel_wide(p_ela, CHAN_ID_PHY_LCU_CHAN_0);

	// MAC_ELA_1, PHY_LCU_1 and BT_LCU are narrow
	bool mac_narrow_used = is_channel_enabled(p_ela, CHAN_ID_MAC_ELA_CHAN_1);
	bool phy_narrow_used = is_channel_enabled(p_ela, CHAN_ID_PHY_LCU_CHAN_1);
	bool bt_narrow_used = is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN);

	bool wide_used = mac_wide_used || phy_wide_used;
	bool narrow_used = mac_narrow_used || phy_narrow_used || bt_narrow_used;

	return wide_used && narrow_used;
}

static void lcu_channels_conf_check(struct la_tag *p_ela)
{
	struct la_conf_tag *p_conf = &p_ela->lcu_conf;

	p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_0].enable = p_conf->lcu_mac_conf.ch0_enable;
	p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_1].enable = p_conf->lcu_mac_conf.ch1_enable;
	p_ela->lcu_chan[CHAN_ID_PHY_LCU_CHAN_0].enable = p_conf->lcu_phy_conf.lcu_phy_channel[0].lcu_phy_ch_en;
	p_ela->lcu_chan[CHAN_ID_PHY_LCU_CHAN_1].enable = p_conf->lcu_phy_conf.lcu_phy_channel[1].lcu_phy_ch_en;
	p_ela->lcu_chan[CHAN_ID_BT_LCU_CHAN].enable    = p_conf->lcu_common.lcu_bt_en;

	p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_0].conf = p_conf->lcu_common.lcu_mode.ch0_conf;
	p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_1].conf = p_conf->lcu_common.lcu_mode.ch1_conf;
	p_ela->lcu_chan[CHAN_ID_PHY_LCU_CHAN_0].conf = p_conf->lcu_common.lcu_mode.ch2_conf;
	p_ela->lcu_chan[CHAN_ID_PHY_LCU_CHAN_1].conf = p_conf->lcu_common.lcu_mode.ch3_conf;
	p_ela->lcu_chan[CHAN_ID_BT_LCU_CHAN].conf    = p_conf->lcu_common.lcu_mode.ch4_conf;

	for (int chan = 0; chan < LCU_COMMON_CHAN_CNT; chan++) {
		if (is_channel_enabled(p_ela, chan)) {
			if (!(p_ela->lcu_chan[chan].conf & BIT(CH_WRITE_VCI))) {
				cl_dbg_warn("channel %d is missing write_vci,"
					    "vcd will not be created!\n", chan);
				p_ela->generate_vcd = false;
			}
			
			if (!(p_ela->lcu_chan[chan].conf & BIT(CH_WRITE_TS))) {
				cl_dbg_warn("channel %d is missing write_ts,"
					    "vcd will not be created!\n", chan);
				p_ela->generate_vcd = false;
			}
		}
	}

	p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_0].vci = (p_conf->lcu_common.lcu_common_vci & 0xF);
	p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_1].vci = (p_conf->lcu_common.lcu_common_vci & 0xF0) >> 4;
	p_ela->lcu_chan[CHAN_ID_PHY_LCU_CHAN_0].vci = (p_conf->lcu_common.lcu_common_vci & 0xF00) >> 8;
	p_ela->lcu_chan[CHAN_ID_PHY_LCU_CHAN_1].vci = (p_conf->lcu_common.lcu_common_vci & 0xF000) >> 12;
	p_ela->lcu_chan[CHAN_ID_BT_LCU_CHAN].vci    = (p_conf->lcu_common.lcu_common_vci & 0xF0000) >> 16;

	p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_0].select = p_conf->lcu_mac_conf.ch0_select;
	p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_1].select = p_conf->lcu_mac_conf.ch1_select;

	cl_dbg_trace("--------------------------\n");
	cl_dbg_trace("| channel |  mode  | vci |\n");
	cl_dbg_trace("|---------+--------+-----|\n");

	for (int chan = 0; chan < LCU_COMMON_CHAN_CNT; chan++) {
		if (is_channel_enabled(p_ela, chan)) {
			cl_dbg_trace("| %7d | %6s | %3d |\n", chan,
				     is_channel_wide(p_ela, chan) ? "Wide" : "Narrow",
				     p_ela->lcu_chan[chan].vci);
		}
	}

	cl_dbg_trace("--------------------------\n");

	if (channels_share_vci_check(p_ela)) {
		cl_dbg_warn("VCD will not be created due to channels sharing same vci\n");
		p_ela->generate_vcd = false;
	}

	// TODO: Add support for mixed narrow and wide samples
	// (this is genvcd limitation, not HW limitation)
	if (mixed_narrow_wide(p_ela)) {
		cl_dbg_warn("VCD will not be created due to mixed narrow and wide samples\n");
		p_ela->generate_vcd = false;
	}
}

int bt_lcu_conf_parse(struct la_tag *p_ela)
{
	struct la_conf_tag *p_conf = &p_ela->lcu_conf;
	int controller_subch_idx[BT_LCU_COMPACT_SUBCHAN_CNT] = {0};
	int modem_subch_idx[BT_LCU_COMPACT_SUBCHAN_CNT] = {0};

	if (!is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN)) {
		return 0;
	}

	for (int i = 0; i < BT_LCU_CHAN_CNT; i++) {
		p_ela->bt_ctrl_chan[i].enable = !!(p_conf->lcu_common.lcu_bt_ch_valid & BIT(i));

		if (p_conf->lcu_bt_conf.controller_mask_idx == i) {
			p_ela->bt_ctrl_chan[i].mask_enable = true;
		}

		if (p_conf->lcu_bt_conf.modem_mask_idx + BT_MODEM_SUBCHANNEL_IDX_OFT == i) {
			p_ela->bt_ctrl_chan[i].mask_enable = true;
		}
	}

	for (int i = 0; i < BT_LCU_MASK_REG_COUNT ; i++) {
		p_ela->controller_mask[i] = p_conf->lcu_bt_conf.controller_mask[i];
		p_ela->modem_mask[i] = p_conf->lcu_bt_conf.modem_mask[i];
	}

	/* BT LCU Compact Mode Configuration */
	if (p_ela->bt_ctrl_chan[0].enable) {
		for (int i = 0; i < BT_LCU_COMPACT_SUBCHAN_CNT; i++) {
			if (p_conf->lcu_common.lcu_bt_ch_valid & BIT(i)) {
				p_ela->controller_subch_cnt++;
			}

			if (p_conf->lcu_common.lcu_bt_ch_valid & BIT(i)) {
				p_ela->modem_subch_cnt++;
			}
		}

		/* Check for configuration error with bitwise & */
		if (p_conf->lcu_bt_conf.controller_sub_ch_en & p_conf->lcu_bt_conf.modem_sub_ch_en) {
			cl_dbg_err("BT LCU Controller and Modem subchannels overlap: "
				   "controller=0x%02X, modem=0x%02X\n",
				   p_conf->lcu_bt_conf.controller_sub_ch_en,
				   p_conf->lcu_bt_conf.modem_sub_ch_en);
			return -1;
		}

		controller_subch_idx[0] = p_conf->lcu_bt_conf.controller_sub_ch_idx0;
		controller_subch_idx[1] = p_conf->lcu_bt_conf.controller_sub_ch_idx1;
		controller_subch_idx[2] = p_conf->lcu_bt_conf.controller_sub_ch_idx2;
		controller_subch_idx[3] = p_conf->lcu_bt_conf.controller_sub_ch_idx3;
		controller_subch_idx[4] = p_conf->lcu_bt_conf.controller_sub_ch_idx4;
		controller_subch_idx[5] = p_conf->lcu_bt_conf.controller_sub_ch_idx5;

		modem_subch_idx[0] = p_conf->lcu_bt_conf.modem_sub_ch_idx0;
		modem_subch_idx[1] = p_conf->lcu_bt_conf.modem_sub_ch_idx1;
		modem_subch_idx[2] = p_conf->lcu_bt_conf.modem_sub_ch_idx2;
		modem_subch_idx[3] = p_conf->lcu_bt_conf.modem_sub_ch_idx3;
		modem_subch_idx[4] = p_conf->lcu_bt_conf.modem_sub_ch_idx4;
		modem_subch_idx[5] = p_conf->lcu_bt_conf.modem_sub_ch_idx5;

		/* Modem sub channels selection */
		for (int i = 0; i < BT_LCU_COMPACT_SUBCHAN_CNT; i++) {
			if (BIT(i) & p_conf->lcu_bt_conf.controller_sub_ch_en) {
				p_ela->bt_ctrl_chan[0].hw_sel[i] = controller_subch_idx[i] + BTDIAG_CONTROLLER_MODE_OFFSET;
			}

			if (BIT(i) & p_conf->lcu_bt_conf.modem_sub_ch_en) {
				p_ela->bt_ctrl_chan[0].hw_sel[i] = modem_subch_idx[i];
			}
		}
	}

	return 0;
}

static int check_la_conf(struct la_tag *p_ela)
{
	//[0] version word
	//  bits 7..0: struct version
	//  bit 8 : 1 => FPGA, 0 => ASIC
	//  bits 10..9  : LA state
	//  bits 12..11 : LA mode
	//  bits 31-24 is clock divisor (0=unknown). Other bits reserved0.

	uint32_t la_vers;
	uint32_t u32val;
	struct la_conf_tag *p_conf = &p_ela->lcu_conf;
	p_ela->generate_vcd = true;

	// Get LA version word: see above
	la_vers = p_conf->lcu_common.la_version;
	if (la_vers & 0x00FFE000) {
		cl_dbg_warn("in lamacconf reserved bits are set, may be a newer format that we may not understand\n");
	}

	switch (la_vers & 0xFF) {
	case HW_6000_STEP_A0:
	case HW_6000_STEP_B0:
		break;
	default:
		cl_dbg_err("lamacconf version (%d) is not compatible!\n", la_vers & 0xFF);
		return -1;
	}

	p_ela->la_version = la_vers;

	lcu_channels_conf_check(p_ela);

	// LA_STATUS
	u32val = p_conf->lcu_common.lcu_status;
	switch (u32val & LA_STATUS_RUN_MASK) {
	case LA_STATUS_RUN_DISABLED: // benson-tbd: ???
	case LA_STATUS_RUN_ARMED:    // benson-tbd: ???
	case LA_STATUS_RUN_REC_END:  // OK
		break;
	case LA_STATUS_RUN_RECORD:
	default:
		cl_dbg_warn("LA was not stopped when data was captured !!! [%#X]\n", u32val);
	}

	// FIXME: phy_lcu may also use wide, can corrupt parsing
	p_ela->samples_width = is_channel_wide(p_ela, CHAN_ID_MAC_ELA_CHAN_0);

	// Note: Due to inconsiderate HW design !!!
	// in narrow mode - CH0 MASK regs are sampling[4]-sampling[7]
	//                - CH1 MASK regs are sampling[0]-sampling[3]
	// in wide mode   - CH0 MASK regs are sampling[0]-sampling[7]
	if (p_ela->samples_width) {
		for (int i = 0; i < 8; i++) {
			p_ela->sampling[i] = p_conf->lcu_mac_conf.mac_sampling_mask[i];
		}
	} else {
		for (int i = 0; i < 8; i++) {
			if (i < 4) {
				p_ela->sampling[i] = p_conf->lcu_mac_conf.mac_sampling_mask[i + 4];
			} else {
				p_ela->sampling[i] = p_conf->lcu_mac_conf.mac_sampling_mask[i - 4];
			}
		}
	}

	p_ela->last_wr_index = p_conf->lcu_common.lcu_write_addr - p_conf->lcu_common.lcu_start_addr;
	p_ela->last_wr_index = p_ela->samples_width ? (p_ela->last_wr_index >> (LCU_NARROW_ENTRY_SIZE + 1)) : (p_ela->last_wr_index >> LCU_NARROW_ENTRY_SIZE);
	cl_dbg_trace("LA buffer WRAP-AROUND at %#X (format: %s)\n", p_ela->last_wr_index, p_ela->samples_width ? "wide" : "narrow");

	if (p_ela->last_wr_index >= LA_MAX_LINE_CNT) {
		cl_dbg_err("last read index > LA_MAX_LINE_CNT (%#X)\n", p_ela->last_wr_index);
		return -1;
	}

	p_ela->buf_size    = p_conf->lcu_common.lcu_end_addr - p_conf->lcu_common.lcu_start_addr;
	p_ela->wr_blk_size = 0x1000; // benson-tbd: add BLOCK_SIZE_EXPONENT register to lamacconf
	p_ela->wr_blk_cnt  = p_conf->lcu_common.blk_wr_cnt;

	// Figure out if we had a LCU buffer wrap-around or not
	if (p_ela->wr_blk_cnt >= (p_ela->buf_size/p_ela->wr_blk_size))
		p_ela->is_buf_wrapped = 1;
	else
		p_ela->is_buf_wrapped = 0;

	ela_conf_dbg_sel_get(p_ela, p_conf);

	// both MACHW's debug_port_control registers comes in 1 dword.
	p_ela->debug_top_sel = p_conf->lcu_mac_conf.mac_debug_port_control & 0xF;
	cl_dbg_trace("MACHW0: debug_top_sel=%u\n", p_ela->debug_top_sel);

	// benson-tbd: trigger_point is rec_stop_addr ???
	p_ela->trigger_point = p_conf->lcu_common.rec_stop_addr;
	cl_dbg_trace("trigger point value = 0x%X.\n", p_ela->trigger_point);

	if (p_ela->trigger_point < p_conf->lcu_common.lcu_start_addr || p_ela->trigger_point > p_conf->lcu_common.lcu_end_addr) {
		cl_dbg_err("trigger_point out of bound (0x%X)\n", p_ela->trigger_point);
		return -1;
	}

	// benson-tbd: calculate real trigger_time ??? extra cycles ???
	p_ela->trigger_time = p_conf->lcu_common.rec_end_timestamp;
	cl_dbg_trace("trigger timestamp = 0x%X.\n", p_ela->trigger_time);

	if (bt_lcu_conf_parse(p_ela) != 0)
		return -1;

	return 0;
}

static int get_la_conf(struct la_tag *p_ela)
{
	FILE *fp = NULL;
	struct la_conf_tag *p_conf = &p_ela->lcu_conf;
	char la_conf_bin_path[STR_BUF_MAX];
	int la_conf_expected_len = sizeof(*p_conf)/sizeof(uint32_t);
	int la_conf_read_len;

	memset(p_conf, 0, sizeof(*p_conf));;

	fp = dumpdir_fopen(p_ela, LA_CONF_BIN_FILE_NAME, "rb");
	if (!fp) {
		return -1;
	}

	la_conf_read_len = fread(p_conf, sizeof(uint32_t), la_conf_expected_len, fp);
	if (la_conf_read_len != la_conf_expected_len) {
		cl_dbg_err("Failed reading %s (read: 0x%X, expected: 0x%X)\n", la_conf_bin_path,
			   la_conf_read_len, la_conf_expected_len);
		fclose(fp);
		return -1;
	}

	fclose(fp);
	return 0;
}

static FILE *get_diag_port_fp(int mode_id, char *debugPortName, int diag_file_id)
{
	FILE *pFile;
	char *line = NULL;
	char sel_string[8] = "";
	int found = 0;
	ssize_t read;

	if (mode_id < 0x10) {
		sprintf(sel_string, "0x%02X", mode_id);
	} else {
		sprintf(sel_string, "0x%X", mode_id);
	}

	// Read HW diag descriptions, hwdiag.txt
	pFile = dumpdir_fopen(&ela, file_id_2_file_name[diag_file_id], "rt");
	if (!pFile) {
		return NULL;
	}

	// Walk through the name file and find the beginning of an HW diag port
	fseek(pFile, 0, SEEK_SET);
	while (1) {
		// save debugPort name for later
		if (line) {
			sprintf(debugPortName, "%s", line);
			free(line);
		}

		// Read a HW diag file line
		read = readlinex(&line, pFile);
		if (read < 0) {
			return NULL;
		}

		// Do we have a match?
		if (!strcmp(line, sel_string)) {
			found = 1;
			free(line);
			break;
		}
	}

	if (!found) {
		cl_dbg_warn("Selector %s is not defined in hwdiag.txt!\n", sel_string);
		return NULL;
	}

	return pFile;
}

static int create_diag_port_group(FILE *pFile, struct groups *groups, const char *prefix, char *debugPortName,
	char *name_extention, int diag_port_size)
{
	int lsb = 0;
	ssize_t read;
	char *line = NULL;
	char line_with_prefix[STR_BUF_MAX] = {0};
	char line_prev[STR_BUF_MAX] = "";
	int prefix_len = strlen(prefix);
	char name[STR_BUF_MAX] = {0};
	int v_lsb, v_msb, vars = 0;
	int err = 0;

	groups->cnt = 0;
	snprintf(line_with_prefix, 255, "%s%s%s_", prefix, debugPortName, name_extention);
	int name_extention_len = name_extention ? strlen(name_extention) : 0;

	for (int ii = 0; ii < diag_port_size; ii++) {
		read = readlinex(&line, pFile);

		if (read <= 0) {
			break;
		}

		if (!strcmp("null", line) ||
		    !strncmp("1'b0", line, 4)) {
			lsb++;
			free(line);
			continue;
		}

		bool is_vector = strchr(line, ':');

		if (is_vector) {
			vars = sscanf(line, "%[^[][%d:%d]", name, &v_msb, &v_lsb);

			if (v_lsb > v_msb || vars != 3) {
				cl_dbg_warn("invalid signal name! (%s)\n", line);
				free(line);
				break;
			}
		}

		char *c = strchr(line, '[');
		if (c) {
			*c = '\0';
		}

		if (is_vector) {
			// crate vector group from single line
			memcpy(line_with_prefix + prefix_len + strlen(debugPortName) + name_extention_len + 1, line, strlen(line));
			err = add_group(groups, line_with_prefix, groups->mictor_name, lsb + v_lsb, lsb + v_msb, 0);
			memset(line_with_prefix + prefix_len + strlen(debugPortName) + name_extention_len + name_extention_len + 1, 0, read);
			lsb += v_msb - v_lsb;
		} else if (strcmp(line_prev, line)) {
			// create group from single line
			memcpy(line_with_prefix + prefix_len + strlen(debugPortName) + name_extention_len + 1, line, read);
			err = add_group(groups, line_with_prefix, groups->mictor_name, lsb, lsb, 0);
			memset(line_with_prefix + prefix_len + strlen(debugPortName) + name_extention_len + name_extention_len + 1, 0, read);
			strcpy(line_prev, line);
		} else {
			// handle vector defined over several lines
			err = enlarge_group(groups);
		}

		if (err) {
			cl_dbg_warn("failed to add signal %s\n", *name ? name : debugPortName);
		}

		lsb++;
		free(line);
	}

	return 0;
}

static int create_group(int diag_file_id, int port_id, struct groups *groupf, int mode,
			const char *prefix, char *name_extension, int port_size)
{
	FILE *fp = NULL;
	char debug_port_name[STR_BUF_MAX] = {0};
	char path[STR_BUF_MAX] = {0};
	const struct port_info *p_port_info = &port_info_arr[port_id];
	int port_addr;

	groupf->port_id = port_id;

	if (!*groupf->mictor_name) {
		snprintf(groupf->mictor_name, STR_BUF_MAX, "%s%02x",
			 p_port_info->name, mode);
	}

	if (mode >= p_port_info->mode_max) {
		cl_dbg_warn("%s mode %02X is out of range, falling to mode 0\n", p_port_info->name, mode);
		mode = 0;
	}

	port_addr = p_port_info->base + mode;
	cl_dbg_trace("%s port selected: 0x%X, %d\n", groupf->mictor_name, port_addr, groupf->port_id);

	switch (diag_file_id) {
	case DIAG_FILE_ID_HW:
	case DIAG_FILE_ID_BT:
		fp = get_diag_port_fp(port_addr, debug_port_name, diag_file_id);
		if (!fp) {
			cl_dbg_err("port not found in %s (%Xh)\n", path, port_addr);
			return -1;
		}
		break;
	case DIAG_FILE_ID_SW:
		fp = dumpdir_fopen(&ela, file_id_2_file_name[diag_file_id], "r");
		if (!fp) {
			// TODO: can fallback to hwdiag
			return -1;
		}
		if (mode == 0x1F) {
			char *p;
			for (int i = 0; i < 16; i++) {
				readlinex(&p, fp);
				free(p);
			}
		}
		break;
	default:
		cl_dbg_err("unknown diag_file_id=%d\n", diag_file_id);
		return -1;
	}

	create_diag_port_group(fp, groupf, prefix, debug_port_name, name_extension, port_size);

	fclose(fp);
	return 0;
}

static int create_legacy_groups(int port_id, struct groups *sig_group,
				int general_offset, uint16_t port_sel)
{
	int res = 0;
	uint8_t dbg_sel;

	for (int i = 0; i < LEGACY_PORTS_IN_GENERAL_PORT; i++) {
		snprintf(sig_group[i].mictor_name, STR_BUF_MAX, "%s%d", port_info_arr[port_id].name, i);
	}

	for (int i = 0; i < LEGACY_PORTS_IN_GENERAL_PORT; i++) {
		int diagfileid = DIAG_FILE_ID_HW;
		dbg_sel = (port_sel >> (i * 8)) & 0xFF;

		sig_group[i].offset = general_offset + i * PORT_SIZE_MAC_LEGACY;

		if (dbg_sel == PORT_SW_LO || dbg_sel == PORT_SW_HI) {
			diagfileid = DIAG_FILE_ID_SW;
		}

		res = create_group(diagfileid, port_id, &sig_group[i], dbg_sel,
				   "mac_", "", PORT_SIZE_MAC_LEGACY);

		if (res < 0) {
			cl_dbg_err("Failed creating mictor\n");
			return -1;
		}
	}

	return 0;
}

static int create_control_groups(struct groups *control)
{
	control->offset = ela.samples_width ? (LCU_WIDE_ENTRY_SIZE-1)*32 : (LCU_NARROW_ENTRY_SIZE-1)*32;
	strcpy(control->mictor_name, "control");
	control->cnt = 0;
	add_group(control, "trigger", "ct", 30,  30,  0);
	return 0;
}

static void declare_groups(FILE *vcd, struct groups *groups)
{
	int i;

	for (i = 0; i < groups->cnt; i++) {
		struct group *g = &groups->group[i];

		if (g->lsb == g->msb) {
			fprintf(vcd, "$var wire 1 %s %s $end\n", g->id, g->name);
		} else {
			int width = (g->msb - g->lsb) + 1;
			fprintf(vcd, "$var reg %d %s %s [%d:0] $end\n", width, g->id, g->name, width - 1);
		}
	}
}

uint32_t group_mask_value_get(int groups_oft, uint32_t *p_sampling_mask, struct group *g)
{
	int lsb = g->lsb;
	int msb = g->msb;

	int mask_lsb = groups_oft + lsb;
	int mask_msb = groups_oft + msb;

	int mask_sampling_lo_index = mask_lsb / 32;
	int mask_sampling_hi_index = mask_msb / 32;

	if (mask_sampling_lo_index == mask_sampling_hi_index) {
		uint32_t mask_word = p_sampling_mask[mask_sampling_lo_index];
		int lsb_in_mask_word = mask_lsb % 32;
		int msb_in_mask_word = mask_msb % 32;
		uint32_t mask_msb_to_0_in_mask_word = mask_word & ((msb_in_mask_word == 31) ? 0xFFFFFFFF : ((1 << (msb_in_mask_word + 1)) - 1));
		uint32_t value = (mask_msb_to_0_in_mask_word) >> (lsb_in_mask_word);
		return value;
	} else {
		uint32_t mask_word_lo = p_sampling_mask[mask_sampling_lo_index];
		uint32_t mask_word_hi = p_sampling_mask[mask_sampling_hi_index];
		int lsb_in_mask_word_lo = mask_lsb % 32;
		int msb_in_mask_word_hi = mask_msb % 32;
		uint32_t mask_31_to_lsb_in_mask_word_lo = mask_word_lo & ~((1 << (lsb_in_mask_word_lo)) - 1);
		uint32_t mask_msb_to_0_in_mask_word_hi = mask_word_hi & ((1 << (msb_in_mask_word_hi + 1)) - 1);
		uint32_t value = (mask_msb_to_0_in_mask_word_hi << (32 - lsb_in_mask_word_lo)) | (mask_31_to_lsb_in_mask_word_lo >> lsb_in_mask_word_lo);
		return value;
	}
}

static void init_groups(FILE *vcd, struct groups *groups, uint32_t *sampptr)
{
	cl_dbg_trace("%-45s     mask\t port\n", "name");
	cl_dbg_trace("%-45s     ----\t ----\n", "----");

	for (int i = 0; i < groups->cnt; i++) {
		struct group *g = &groups->group[i];
		int width = (g->msb - g->lsb) + 1;
		uint32_t samp_msk = group_mask_value_get(groups->offset, sampptr, g);
		g->changes = 0;

		if (width == 1) {
			cl_dbg_trace("%-45s %#8x\t %s[%d]\n",
				     g->name, samp_msk, groups->mictor_name, g->lsb);
		} else {
			cl_dbg_trace("%-45s %#8x\t %s[%d:%d]\n",
				     g->name, samp_msk, groups->mictor_name, g->msb, g->lsb);
		}

		if (width == 1) {
			if (samp_msk) {
				fprintf(vcd, "%d%s\n", g->prev, g->id);
			} else {
				fprintf(vcd, "x%s\n", g->id);
			}
		} else {
			char bin[64] = {0};
			int2bin(bin, g->prev, width, samp_msk);
			fprintf(vcd, "b%s %s\n", bin, g->id);
		}
	}

	printf("\n");
}

static void put_groups(FILE *vcd, FILE *btdump_fp, FILE *rficwdump_fp,
		       struct groups *groups, uint32_t *valptr, uint32_t *sampptr)
{
	for (int i = 0; i < groups->cnt; i++) {
		struct group *g = &groups->group[i];
		unsigned int width = (g->msb - g->lsb) + 1;
		uint32_t samp_msk = group_mask_value_get(groups->offset, sampptr, g);
		uint32_t value =  group_mask_value_get(groups->offset, valptr, g);

		if (!samp_msk) {
			continue;
		}

		uint32_t curr = value & samp_msk;

		if (curr != g->prev) {
			g->changes++;
			if (width == 1) {
				if (samp_msk) {
					fprintf(vcd, "%d%s\n", curr, g->id);
				}
			} else {
				char bin[64];
				if (int2bin(bin, curr, width, samp_msk) == 0) {
					fprintf(vcd, "b%s %s\n", bin, g->id);
				}
			}

			g->prev = curr;
		}

		if (rficwdump_fp && (groups->port_id == PORT_ID_RFICW)) {
			fprintf(rficwdump_fp, "%s=0x%X\n", g->name, curr);
		}

		if (btdump_fp) {
			fprintf(btdump_fp, "%s=0x%X\n", g->name, curr);
		}
	}
}

void write_out(FILE *of, uint32_t *data, int index)
{
	static const char frmt[] = "%08X %08X %08X %08X # [0x%X]\n";
	fprintf(of, frmt, data[0], data[1], data[2], data[3], index);
}

static int dump_conf(struct la_tag *p_ela)
{
	FILE *of = dumpdir_fopen(p_ela, LA_CONF_TXT_FILE_NAME, "w");
	if (!of) {
		return -1;
	}

	lcu_conf_print(&p_ela->lcu_conf, of);

	fclose(of);
	return 0;
}

static int dump_trace(struct la_tag *p_ela)
{
	FILE *of = fopen(p_ela->raw_dump_file_path, "w");
	if (!of) {
		cl_dbg_err("failed to open %s\n", p_ela->raw_dump_file_path);
		return -1;
	}

	for (uint32_t num_samp = 0; num_samp < p_ela->samples_num; num_samp++) {
		sample_t samp = {0};
		lcu_sample_get(&samp, num_samp, p_ela->samples_width);
		write_out(of, samp.data, num_samp);
	}

	fclose(of);
	return 0;
}

int lcu_build_wide_mode_0(struct la_tag *p_ela, uint32_t ch_id, char *mac_num)
{
	struct groups *sig_group = &p_ela->lcu_chan[ch_id].sig_group[0];

	cl_dbg_trace("CH%d: Wide Mode 0 used for MAC-HW%s signals.\n", ch_id, mac_num);

	p_ela->lcu_chan[ch_id].num_of_ch_groups = 14;
	sig_group[0].offset = 0;
	sig_group[1].offset = 18;
	sig_group[2].offset = 36;
	sig_group[3].offset = 54;
	sig_group[4].offset = 72;
	sig_group[5].offset = 90;
	sig_group[6].offset = 122;
	sig_group[7].offset = 134;
	sig_group[8].offset = 146;
	sig_group[9].offset = 158;
	sig_group[10].offset = 170;
	sig_group[11].offset = 182;
	sig_group[12].offset = 194;
	sig_group[13].offset = 206;

	strncpy(sig_group[0].mictor_name,  "msu5", 5);
	strncpy(sig_group[1].mictor_name,  "msu4", 5);
	strncpy(sig_group[2].mictor_name,  "msu3", 5);
	strncpy(sig_group[3].mictor_name,  "msu2", 5);
	strncpy(sig_group[4].mictor_name,  "msu1", 5);
	strncpy(sig_group[5].mictor_name,  "msf", 4);
	strncpy(sig_group[6].mictor_name,  "mpu6", 5);
	strncpy(sig_group[7].mictor_name,  "mpu5", 5);
	strncpy(sig_group[8].mictor_name,  "mpu4", 5);
	strncpy(sig_group[9].mictor_name,  "mpu3", 5);
	strncpy(sig_group[10].mictor_name, "mpu2", 5);
	strncpy(sig_group[11].mictor_name, "mpu1", 5);
	strncpy(sig_group[12].mictor_name, "mpu0", 5);
	strncpy(sig_group[13].mictor_name, "mpc", 4);

	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[0], TOP_PORT_MODE_MAC_STATE_1, "", "5", 18);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[1], TOP_PORT_MODE_MAC_STATE_1, "", "4", 18);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[2], TOP_PORT_MODE_MAC_STATE_1, "", "3", 18);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[3], TOP_PORT_MODE_MAC_STATE_1, "", "2", 18);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[4], TOP_PORT_MODE_MAC_STATE_1, "", "1", 18);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[5], TOP_PORT_MODE_MAC_STATE_FULL, "", "", 32);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[6], TOP_PORT_MODE_MPIF_USER, "", "6", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[7], TOP_PORT_MODE_MPIF_USER, "", "5", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[8], TOP_PORT_MODE_MPIF_USER, "", "4", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[9], TOP_PORT_MODE_MPIF_USER, "", "3", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[10], TOP_PORT_MODE_MPIF_USER, "", "2", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[11], TOP_PORT_MODE_MPIF_USER, "", "1", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[12], TOP_PORT_MODE_MPIF_USER, "", "0", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[13], TOP_PORT_MODE_MPIF_COMMON, "", "", 11);

	return 0;
}

int lcu_build_wide_mode_2(struct la_tag *p_ela, uint32_t ch_id, char *mac_num)
{
	struct groups *sig_group = &p_ela->lcu_chan[ch_id].sig_group[0];

	cl_dbg_trace("CH%d: Wide Mode 2 used for MAC-HW%s signals.\n", ch_id, mac_num);
	p_ela->lcu_chan[ch_id].num_of_ch_groups = 13;

	sig_group[0].offset = 0;
	sig_group[1].offset = 18;
	sig_group[2].offset = 36;
	sig_group[3].offset = 54;
	sig_group[4].offset = 86;
	sig_group[5].offset = 98;
	sig_group[6].offset = 110;
	sig_group[7].offset = 122;
	sig_group[8].offset = 134;

	strncpy(sig_group[0].mictor_name, "msu3", 5);
	strncpy(sig_group[1].mictor_name, "msu2", 5);
	strncpy(sig_group[2].mictor_name, "msu1", 5);
	strncpy(sig_group[3].mictor_name, "msf",  4);
	strncpy(sig_group[4].mictor_name, "mpu3", 5);
	strncpy(sig_group[5].mictor_name, "mpu2", 5);
	strncpy(sig_group[6].mictor_name, "mpu1", 5);
	strncpy(sig_group[7].mictor_name, "mpu0", 5);
	strncpy(sig_group[8].mictor_name, "mpc",  4);

	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[0], TOP_PORT_MODE_MAC_STATE_1, "", "3", 18);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[1], TOP_PORT_MODE_MAC_STATE_1, "", "2", 18);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[2], TOP_PORT_MODE_MAC_STATE_1, "", "1", 18);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[3], TOP_PORT_MODE_MAC_STATE_FULL, "", "", 32);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[4], TOP_PORT_MODE_MPIF_USER, "", "3", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[5], TOP_PORT_MODE_MPIF_USER, "", "2", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[6], TOP_PORT_MODE_MPIF_USER, "", "1", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[7], TOP_PORT_MODE_MPIF_USER, "", "0", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[8], TOP_PORT_MODE_MPIF_COMMON, "", "", 11);

	create_legacy_groups(PORT_ID_LEGACY_B, &sig_group[9], 160, ela.dbg_sel[PORT_ID_LEGACY_B]);
	create_legacy_groups(PORT_ID_LEGACY_C, &sig_group[11], 192, ela.dbg_sel[PORT_ID_LEGACY_C]);

	return 0;
}

int lcu_build_narrow_mode_3(struct la_tag *p_ela, uint32_t ch_id, char *mac_num)
{
	struct groups *sig_group = &p_ela->lcu_chan[ch_id].sig_group[0];

	cl_dbg_trace("CH%d: Narrow Mode 3 used for MAC-HW%s signals.\n", ch_id, mac_num);
	p_ela->lcu_chan[ch_id].num_of_ch_groups = 6;

	sig_group[0].offset = 0;
	sig_group[1].offset = 32;
	sig_group[2].offset = 44;
	sig_group[3].offset = 56;
	sig_group[4].offset = 68;
	sig_group[5].offset = 80;

	strncpy(sig_group[0].mictor_name, "msf", 4);
	strncpy(sig_group[1].mictor_name, "mpu3", 5);
	strncpy(sig_group[2].mictor_name, "mpu2", 5);
	strncpy(sig_group[3].mictor_name, "mpu1", 5);
	strncpy(sig_group[4].mictor_name, "mpu0", 5);
	strncpy(sig_group[5].mictor_name, "mpc", 4);

	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[0], TOP_PORT_MODE_MAC_STATE_FULL, "", "", 32);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[1], TOP_PORT_MODE_MPIF_USER, "", "3", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[2], TOP_PORT_MODE_MPIF_USER, "", "2", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[3], TOP_PORT_MODE_MPIF_USER, "", "1", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[4], TOP_PORT_MODE_MPIF_USER, "", "0", 12);
	create_group(DIAG_FILE_ID_HW, PORT_ID_TOP, &sig_group[5], TOP_PORT_MODE_MPIF_COMMON, "", "", 11);

	return 0;
}

bool is_legacy_port_id(int port_id)
{
	return port_id == PORT_ID_LEGACY_C ||
	       port_id == PORT_ID_LEGACY_B ||
	       port_id == PORT_ID_LEGACY_A;
}

int lcu_build_narrow_mode_0(struct la_tag *p_ela, uint32_t ch_id)
{
	struct groups *sig_group = &p_ela->lcu_chan[ch_id].sig_group[0];
	struct mode_info *p_mode_info = NULL;
	uint32_t mac_ela_mode = p_ela->lcu_chan[ch_id].select;
	int sig_group_cnt = 0;
	int general_offset = 0;
	int port_id = PORT_ID_INVALID;

	if (mac_ela_mode >= MAC_ELA_MODE_MAX) {
		cl_dbg_err("invalid ela_mode=%d\n", mac_ela_mode);
		return -1;
	}

	cl_dbg_trace("LCU Channel %d: Narrow, top_sel=0, mac_ela_mode=%#X.\n", ch_id, mac_ela_mode);

	p_mode_info = &mac_narrow_0_mode_info_arr[mac_ela_mode];

	for (int i = 0; i < MAC_NARROW_0_MODE_PORT_CNT; i++) {
		port_id = p_mode_info->port_id[i];

		if (port_id == PORT_ID_INVALID) {
			break;
		}

		if (is_legacy_port_id(port_id)) {
			create_legacy_groups(port_id, &sig_group[sig_group_cnt],
					     general_offset, ela.dbg_sel[port_id]);
			sig_group_cnt += LEGACY_PORTS_IN_GENERAL_PORT;
		} else {
			sig_group[i].offset = general_offset;
			create_group(DIAG_FILE_ID_HW, port_id, &sig_group[sig_group_cnt],
				     ela.dbg_sel[port_id], port_info_arr[port_id].prefix,
				     "", port_info_arr[port_id].size);
			sig_group_cnt++;
		}

		general_offset += port_info_arr[port_id].size;
	}

	p_ela->lcu_chan[ch_id].num_of_ch_groups = sig_group_cnt;

	return 0;
}

int genvcd_init(int argc, char **argv, struct la_tag *p_ela)
{
	printf("%s\n", GENVCD_VER_STR);

	argc--;
	argv++;

	if (argc == 0 || argc > 2) {
		printf("usage: genvcd <dump_dir_path> [text_dump_file_path]\n");
		return -1;
	}

	p_ela->dumpdir = argv[0];

	printf("dump_dir: %s\n", p_ela->dumpdir);

	if (argc > 1) {
		p_ela->raw_dump_file_path = argv[1];
		printf("raw data dump path: %s\n", p_ela->raw_dump_file_path);
	}

	if (get_la_conf(p_ela))
		return -1;

	if (dump_conf(p_ela))
		return -1;

	if (check_la_conf(p_ela))
		return -1;

	return 0;
}

int vcd_sample_count_get(struct la_tag *p_ela)
{
	int sample_count = 0;
	int vci;

	for (int chan = 0; chan < LCU_COMMON_CHAN_CNT; chan++) {
		if (is_vcd_channel(chan) && is_channel_enabled(p_ela, chan)) {
			vci = ela.lcu_chan[chan].vci;
			sample_count += p_ela->samples_per_vci[vci];
		}
	}

	return sample_count;
}

int vci_2_channel_id(struct la_tag *p_ela, int vci)
{
	int chan_id = CHAN_ID_INVALID;

	for (int i = 0; i < LCU_COMMON_CHAN_CNT; i++) {
		if (is_channel_enabled(p_ela, i)) {
			if (p_ela->lcu_chan[i].vci == vci) {
				chan_id = i;
				break;
			}
		}
	}

	return chan_id;
}

void lcu_mac_create_signals_wide(struct la_tag *p_ela, int channel_id)
{
	// Only mac channel 0 support wide mode
	if (channel_id != 0) {
		cl_dbg_warn("CH%d does not support wide mode!\n", channel_id);
		return;
	}

	switch (p_ela->debug_top_sel) {
	case 0:
		lcu_build_wide_mode_0(p_ela, channel_id, "0");
		break;
	case 2:
		lcu_build_wide_mode_2(p_ela, channel_id, "0");
		break;
	default:
		// TODO: add support for mode 1
		cl_dbg_warn("CH%d Wide Mode %d not supported!\n", channel_id, p_ela->debug_top_sel);
		break;
	}
}

void lcu_mac_create_signals_narrow(struct la_tag *p_ela, int channel_id)
{
	switch(p_ela->debug_top_sel) {
	case 0:
		lcu_build_narrow_mode_0(p_ela, channel_id);
		break;
	case 3:
		lcu_build_narrow_mode_3(p_ela, channel_id, "0");
		break;
	default:
		// TODO: add support for mode 2
		cl_dbg_warn("CH%d Narrow Mode %d not supported!\n", channel_id, p_ela->debug_top_sel);
		break;
	}
}

bool lcu_bt_channel_is_compact(int bt_channel_id)
{
	// only BT channel 0 works in compact mode
	return bt_channel_id == 0;
}

bool bt_lcu_and_mac_ela_enabled(struct la_tag *p_ela)
{
	return is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN) &&
	       (is_channel_enabled(p_ela, CHAN_ID_MAC_ELA_CHAN_0) ||
	        is_channel_enabled(p_ela, CHAN_ID_MAC_ELA_CHAN_1));
}

void lcu_bt_create_signals(struct la_tag *p_ela)
{
	for (int bt_chan = 0; bt_chan < NUM_OF_BT_CHANNELS; bt_chan++) {
		struct chan_info *p_bt_chan_info = &p_ela->bt_ctrl_chan[bt_chan];

		if (!p_bt_chan_info->enable) {
			continue;
		}

		if (lcu_bt_channel_is_compact(bt_chan)) {
			p_bt_chan_info->num_of_ch_groups = BT_LCU_COMPACT_SUBCHAN_CNT;

			for (int subchan = 0; subchan < BT_LCU_COMPACT_SUBCHAN_CNT; subchan++) {
				struct groups *p_subchan_info = &p_bt_chan_info->sig_group[subchan];
				p_subchan_info->offset = subchan * PORT_SIZE_BT_CMPCT;
				create_group(DIAG_FILE_ID_BT, PORT_ID_BT_CMPCT, p_subchan_info,
					     p_bt_chan_info->hw_sel[subchan], "", "",
					     PORT_SIZE_BT_CMPCT);
			}
		} else {
			struct groups *p_subchan_info = &p_bt_chan_info->sig_group[0];
			p_bt_chan_info->num_of_ch_groups = 1;
			p_subchan_info->offset = 0;
			create_group(DIAG_FILE_ID_BT, PORT_ID_BT, p_subchan_info,
				     bt_chan - 1, "", "", PORT_SIZE_BT);
		}
	}
}

void create_signals(struct la_tag *p_ela)
{
	// Create MAC signals
	for (int channel_id = CHAN_ID_MAC_ELA_CHAN_0; channel_id < CHAN_ID_MAC_ELA_CHAN_0 + MAC_ELA_CHAN_CNT; channel_id++) {
		if (is_channel_enabled(p_ela, channel_id)) {
			if (p_ela->samples_width) {
				lcu_mac_create_signals_wide(p_ela, channel_id);
			} else {
				lcu_mac_create_signals_narrow(p_ela, channel_id);
			}
		}
	}

	// Create BT signals
	if (is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN)) {
		lcu_bt_create_signals(p_ela);
	}

	// Create Control signals
	create_control_groups(&p_ela->controls);
}

void vcd_declare_signals(struct la_tag *p_ela)
{
	FILE *vcd_fp = p_ela->fp_vcd;
	struct chan_info *p_chan_info = NULL;

	// Declare MAC signals
	for (int chan = CHAN_ID_MAC_ELA_CHAN_0; chan < CHAN_ID_MAC_ELA_CHAN_0 + MAC_ELA_CHAN_CNT; chan++) {
		p_chan_info = &p_ela->lcu_chan[chan];

		if (is_channel_enabled(p_ela, chan)) {
			for (int idx = 0; idx < p_chan_info->num_of_ch_groups; idx++) {
				declare_groups(vcd_fp, &p_chan_info->sig_group[idx]);
			}
		}
	}

	// Declare BT signals
	if (is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN)) {
		for (int chan = 0; chan < NUM_OF_BT_CHANNELS; chan++) {
			p_chan_info = &p_ela->bt_ctrl_chan[chan];

			if (p_chan_info->enable) {
				for (int idx = 0; idx < p_chan_info->num_of_ch_groups; idx++) {
					declare_groups(vcd_fp, &p_chan_info->sig_group[idx]);
				}
			}
		}
	}

	// Declare control signals
	declare_groups(vcd_fp, &p_ela->controls);
}

void vcd_initialize_signals(struct la_tag *p_ela)
{
	FILE *vcd_fp = p_ela->fp_vcd;
	struct chan_info *p_chan_info = NULL;
	uint32_t default_bt_mask[3] = {0xffffffff, 0xffffffff, 0x03ffffff};

	// Initialize MAC signals
	for (int chan = CHAN_ID_MAC_ELA_CHAN_0; chan < CHAN_ID_MAC_ELA_CHAN_0 + MAC_ELA_CHAN_CNT; chan++) {
		p_chan_info = &p_ela->lcu_chan[chan];

		if (is_channel_enabled(p_ela, chan)) {
			for (int idx = 0; idx < p_chan_info->num_of_ch_groups; idx++) {
				init_groups(vcd_fp, &p_chan_info->sig_group[idx], &ela.sampling[chan * 4]);
			}
		}
	}

	// Initialize BT signals
	if (is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN)) {
		for (int chan = 0; chan < NUM_OF_BT_CHANNELS; chan++) {
			p_chan_info = &p_ela->bt_ctrl_chan[chan];

			if (p_chan_info->enable) {
				uint32_t *p_mask = p_chan_info->mask_enable ? ((chan < 10) ? p_ela->controller_mask : p_ela->modem_mask) : default_bt_mask;
				for (int idx = 0; idx < p_chan_info->num_of_ch_groups; idx++) {
					init_groups(vcd_fp, &p_chan_info->sig_group[idx], p_mask);
				}
			}
		}
	}

	// Initialize control signals
	init_groups(vcd_fp, &p_ela->controls, p_ela->sampling);
}

void vcd_put_signals(struct la_tag *p_ela, sample_t *p_sample, uint64_t relative_ts)
{
	FILE *vcd_fp = p_ela->fp_vcd;
	FILE *btdump_fp = p_ela->fp_btdump;
	FILE *rficw_fp = p_ela->fp_rficwdump;
	uint32_t default_bt_mask[3] = {0xffffffff, 0xffffffff, 0x03ffffff};
	struct chan_info *p_chan_info = NULL;
	uint32_t vci = lcu_sample_vci_get(p_sample, ela.samples_width);
	int channel_id = vci_2_channel_id(&ela, vci);
	int bt_chan = lcu_sample_bt_chan_get(p_sample);
	static uint32_t bt_dump_ts = 0;
	static uint32_t rficw_dump_ts = 0;

	// Ensure BT compensations wont result with negative TS. Constants
	// are added to TS of all samples (if BT is enabled) since timeline
	// is shared, but will be removed only for BT samples, moving them
	// "back in time" to where they should be relative to mac smaples.
	if (is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN)) {
		relative_ts += BT_LCU_CHAN_CNT * 2;

		if (bt_lcu_and_mac_ela_enabled(&ela)) {
			relative_ts += BT_LCU_MAC_ELA_TS_COMPENSATION;
		}
	}

	// Sync up to 20 BT samples into a single timestamp - thats needed
	// since BT channels change in BT clock, but are sampled seperatly
	// in MAC clock by order. multiply by 2 needed since TS changes in
	// 640MHz clk, while sampling of BT channels done in 320MHz clk
	if (channel_id == CHAN_ID_BT_LCU_CHAN) {
		relative_ts -= bt_chan * 2;

		// Compensate for the BT LCU sampling compared to MAC ELA
		if (bt_lcu_and_mac_ela_enabled(p_ela)) {
			relative_ts -= BT_LCU_MAC_ELA_TS_COMPENSATION;
		}
	}

	fprintf(vcd_fp, "#%llu\n", relative_ts * DELAY);

	// Put MAC signals
	if (channel_id == CHAN_ID_MAC_ELA_CHAN_0 || channel_id == CHAN_ID_MAC_ELA_CHAN_1) {
		p_chan_info = &p_ela->lcu_chan[channel_id];
		bool rficw_en = p_chan_info->select == MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___RFICW_31_0;

		if (rficw_fp && rficw_en && (rficw_dump_ts != relative_ts)) {
			fprintf(rficw_fp, "\n%llu:\n", relative_ts * DELAY);
			rficw_dump_ts = relative_ts;
		}

		for (int idx = 0; idx < p_chan_info->num_of_ch_groups; idx++) {
			put_groups(vcd_fp, NULL, rficw_fp, &p_chan_info->sig_group[idx],
				   p_sample->data, &p_ela->sampling[channel_id * 4]);
		}
	}

	// Put BT signals
	if (channel_id == CHAN_ID_BT_LCU_CHAN) {
		p_chan_info = &p_ela->bt_ctrl_chan[bt_chan];

		if (btdump_fp && (bt_dump_ts != relative_ts)) {
			fprintf(btdump_fp, "\n%llu:\n", relative_ts * DELAY);
			bt_dump_ts = relative_ts;
		}

		if (p_chan_info->enable) {
			uint32_t *p_mask = p_chan_info->mask_enable ? ((bt_chan < 10) ? p_ela->controller_mask : p_ela->modem_mask) : default_bt_mask;
			for (int i = 0; i < p_chan_info->num_of_ch_groups; i++) {
				put_groups(vcd_fp, btdump_fp, NULL, &p_chan_info->sig_group[i], p_sample->data, p_mask);
			}
		}
	}

	// Put control signals
	put_groups(vcd_fp, NULL, NULL, &ela.controls, p_sample->data, ela.sampling);
}

void dbg_print_signal_changes(struct la_tag *p_ela)
{
	struct chan_info *p_chan_info = NULL;

	cl_dbg_trace("Signals Changes List:\n");

	cl_dbg_trace("%-50s changes\n", "name");
	cl_dbg_trace("%-50s -------\n", "----");

	// Print MAC signals change counters
	for (int chan = CHAN_ID_MAC_ELA_CHAN_0; chan < CHAN_ID_MAC_ELA_CHAN_0 + MAC_ELA_CHAN_CNT; chan++) {
		p_chan_info = &p_ela->lcu_chan[chan];

		if (is_channel_enabled(p_ela, chan)) {
			for (int group_idx = 0; group_idx < p_chan_info->num_of_ch_groups; group_idx++) {
				for (int sig_idx = 0; sig_idx < p_chan_info->sig_group[group_idx].cnt; sig_idx++) {
					struct group *g = &p_chan_info->sig_group[group_idx].group[sig_idx];
					cl_dbg_trace("%-50s %d\n", g->name, g->changes);
				}
			}
		}
	}

	// Print BT signals change counters
	if (is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN)) {
		for (int chan = 0; chan < NUM_OF_BT_CHANNELS; chan++) {
			p_chan_info = &p_ela->bt_ctrl_chan[chan];

			if (p_chan_info->enable) {
				for (int group_idx = 0; group_idx < p_chan_info->num_of_ch_groups; group_idx++) {
					for (int sig_idx = 0; sig_idx < p_chan_info->sig_group[group_idx].cnt; sig_idx++) {
						struct group *g = &p_chan_info->sig_group[group_idx].group[sig_idx];
						cl_dbg_trace("%-50s %d\n", g->name, g->changes);
					}
				}
			}
		}
	}
}

bool is_rficw_mode_enabled(struct la_tag *p_ela)
{
	bool ela_chan_0_rficw_en = false;
	bool ela_chan_1_rficw_en = false;

	if (!p_ela->samples_width && p_ela->debug_top_sel == 0) {
		if (is_channel_enabled(p_ela, CHAN_ID_MAC_ELA_CHAN_0)) {
			ela_chan_0_rficw_en = p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_0].select ==
					MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___RFICW_31_0;
		}

		if (is_channel_enabled(p_ela, CHAN_ID_MAC_ELA_CHAN_1)) {
			ela_chan_0_rficw_en = p_ela->lcu_chan[CHAN_ID_MAC_ELA_CHAN_1].select ==
					MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___RFICW_31_0;
		}
	}

	return ela_chan_0_rficw_en || ela_chan_1_rficw_en;
}

int dump_files_init(struct la_tag *p_ela)
{
	bool create_vcd = p_ela->generate_vcd;
	bool create_btdump = is_channel_enabled(p_ela, CHAN_ID_BT_LCU_CHAN);
	bool create_rficwdump = is_rficw_mode_enabled(p_ela);

	cl_dbg_verbose("Create: vcd [%c], btdump [%c], rficwdump [%c]\n",
			create_vcd ? 'y' : 'n',
			create_btdump ? 'y' : 'n',
			create_rficwdump ? 'y' : 'n');

	if (create_vcd) {
		p_ela->fp_vcd = dumpdir_fopen(p_ela, TRACE_CVD_FILE_NAME, "w");

		if (!p_ela->fp_vcd) {
			return -1;
		}
	}

	if (create_btdump) {
		p_ela->fp_btdump = dumpdir_fopen(p_ela, BT_DUMP_FILE_NAME, "w");

		if (!p_ela->fp_btdump) {
			cl_dbg_warn("btdump.txt will not be created!\n");
		}
	}

	if (create_rficwdump) {
		p_ela->fp_rficwdump = dumpdir_fopen(p_ela, RFICW_DUMP_FILE_NAME, "w");

		if (!p_ela->fp_rficwdump) {
			cl_dbg_warn("rficwdump.txt will not be created!\n");
		}
	}

	return 0;
}

void dump_files_close(struct la_tag *p_ela)
{
	if (p_ela->fp_vcd) {
		fclose(p_ela->fp_vcd);
	}

	if (p_ela->fp_btdump) {
		fclose(p_ela->fp_btdump);
	}

	if (p_ela->fp_rficwdump) {
		fclose(p_ela->fp_rficwdump);
	}
}

int main(int argc, char **argv)
{
	int err = 0;
	uint32_t first_ts = 0;

	err = genvcd_init(argc, argv, &ela);
	if (err) {
		return err;
	}

	if (trace_open(&ela)) {
		return -1;
	}

	if (ela.raw_dump_file_path) {
		return dump_trace(&ela);
	}

	if (!ela.generate_vcd) {
		return -1;
	}

	err = dump_files_init(&ela);
	if (err) {
		return -1;
	}

	vcd_file_print_headers(&ela);
	create_signals(&ela);
	vcd_declare_signals(&ela);
	fprintf(ela.fp_vcd, "\n$enddefinitions\n$dumpvars\n");
	vcd_initialize_signals(&ela);
	fprintf(ela.fp_vcd, "\n$end\n");

	for (int sample_idx = 0; sample_idx < ela.samples_num; sample_idx++) {
		sample_t sample = {0};
		uint32_t ts, relative_ts;
		int vci, channel_id;

		lcu_sample_get(&sample, sample_idx, ela.samples_width);
		ts = lcu_sample_timestamp_get(&sample, ela.samples_width);
		vci = lcu_sample_vci_get(&sample, ela.samples_width);
		channel_id = vci_2_channel_id(&ela, vci);

		if (channel_id == CHAN_ID_INVALID) {
			continue;
		}

		ela.samples_per_vci[vci]++;

		if (is_vcd_channel(channel_id)) {
			if (vcd_sample_count_get(&ela) == 1) {
				first_ts = ts;
			}

			if (!ts) {
				cl_dbg_warn("zero timestamp! smaple_idx=%04X, vci=%d\n", sample_idx, vci);
				continue;
			}

			// vcd uses relative timestaps, handle timestamp wrap around
			relative_ts = (first_ts <= ts) ? (ts - first_ts) : (MAX_TIMESTAMP - first_ts + ts + 1);

			cl_dbg_info("[%04X] vci=%d, ts=%08X, relative_ts=%08X\n", sample_idx, vci, ts, relative_ts);
			vcd_put_signals(&ela, &sample, relative_ts);
		}
	}

	fprintf(ela.fp_vcd, "$comment\nEND-TRACE\n$end\n");
	
	dump_files_close(&ela);

	cl_dbg_trace("Samples per vci:\n");
	for (int vci = 0; vci < LCU_VCI_MAX; vci++) {
		cl_dbg_trace("vci%d: %d\n", vci, ela.samples_per_vci[vci]);
	}

	dbg_print_signal_changes(&ela);

	cl_dbg_verbose("Done.\n");
	return 0;
}
