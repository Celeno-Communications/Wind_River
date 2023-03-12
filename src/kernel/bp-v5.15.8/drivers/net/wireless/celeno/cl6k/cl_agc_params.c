// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_agc_params.h"
#include "chip.h"
#include "cl_hw.h"
#include "cl_band.h"
#include "cl_utils.h"

static struct cl_agc_params agc_params_24g = {
	.id                 = 2,
	.fsm_preset_p2      = { .val = 0x00004701, .mask = 0xffffffff }, /* 0x244 */
	.lna_thr_set0_ref2  = { .val = 0x2C272422, .mask = 0xffffffff }, /* 0x25C */
	.lna_thr_set0_ref3  = { .val = 0x00373731, .mask = 0xffffffff }, /* 0x260 */
	.lna_thr_set1_ref2  = { .val = 0x2C272422, .mask = 0xffffffff }, /* 0x264 */
	.lna_thr_set1_ref3  = { .val = 0x5B373731, .mask = 0xffffffff }, /* 0x268 */
	.lna_thr_set2_ref2  = { .val = 0x2C272422, .mask = 0xffffffff }, /* 0x26C */
	.lna_thr_set2_ref3  = { .val = 0x5B373731, .mask = 0xffffffff }, /* 0x270 */
	.lna_gain_set0_ref2 = { .val = 0x2724211B, .mask = 0xffffffff }, /* 0x274 */
	.lna_gain_set0_ref3 = { .val = 0x3636302C, .mask = 0xffffffff }, /* 0x278 */
	.lna_nf_set0_ref2   = { .val = 0x04080C0F, .mask = 0xffffffff }, /* 0x27C */
	.lna_nf_set0_ref3   = { .val = 0x03030303, .mask = 0xffffffff }, /* 0x280 */
	.lna_icp1_set0_ref2 = { .val = 0x66696C6C, .mask = 0xffffffff }, /* 0x284 */
	.lna_icp1_set0_ref3 = { .val = 0x625F6264, .mask = 0xffffffff }, /* 0x288 */
	.fsm_preset_p10     = { .val = 0x00001E21, .mask = 0xffffffff }, /* 0x2A8 */
	.fsm_preset_p11     = { .val = 0x00001E21, .mask = 0xffffffff }, /* 0x2AC */
	.fsm_preset_p12     = { .val = 0x00ECEA07, .mask = 0xffffffff }, /* 0x2B0 */
	.ant_loss           = { .val = 0x00000000, .mask = 0xffffffff }, /* 0x300 */
	.gain_range         = { .val = 0x47076407, .mask = 0xffffffff }, /* 0x304 */
	.vga_ref0           = { .val = 0x0001021E, .mask = 0xffffffff }, /* 0x308 */
	.lna_gain_set0_ref0 = { .val = 0x13100D07, .mask = 0xffffffff }, /* 0x30C */
	.lna_gain_set0_ref1 = { .val = 0x22221C18, .mask = 0xffffffff }, /* 0x310 */
	.lna_thr_set0_ref0  = { .val = 0x1814110D, .mask = 0xffffffff }, /* 0x314 */
	.lna_thr_set0_ref1  = { .val = 0x2222221D, .mask = 0xffffffff }, /* 0x318 */
	.lna_thr_set1_ref0  = { .val = 0x1814110D, .mask = 0xffffffff }, /* 0x31C */
	.lna_thr_set1_ref1  = { .val = 0x2222221D, .mask = 0xffffffff }, /* 0x320 */
	.lna_thr_set2_ref0  = { .val = 0x1814110D, .mask = 0xffffffff }, /* 0x324 */
	.lna_thr_set2_ref1  = { .val = 0x2222221D, .mask = 0xffffffff }, /* 0x328 */
	.lna_nf_set0_ref0   = { .val = 0x141A2023, .mask = 0xffffffff }, /* 0x32C */
	.lna_nf_set0_ref1   = { .val = 0x000D0E10, .mask = 0xffffffff }, /* 0x330 */
	.lna_icp1_set0_ref0 = { .val = 0x7A7D0000, .mask = 0xffffffff }, /* 0x334 */
	.lna_icp1_set0_ref1 = { .val = 0x00737678, .mask = 0xffffffff }, /* 0x338 */
	.ramp               = { .val = 0x05200710, .mask = 0xffffffff }, /* 0x36C */
	.dsp3               = { .val = 0x0B730000, .mask = 0xffff0000 }, /* 0x3A0 */
	.lna_gain_set1_ref0 = { .val = 0x13100D07, .mask = 0xffffffff }, /* 0x590 */
	.lna_gain_set1_ref1 = { .val = 0x22221C18, .mask = 0xffffffff }, /* 0x594 */
	.lna_gain_set1_ref2 = { .val = 0x2724211B, .mask = 0xffffffff }, /* 0x598 */
	.lna_gain_set1_ref3 = { .val = 0x3636302C, .mask = 0xffffffff }, /* 0x59C */
	.lna_nf_set1_ref0   = { .val = 0x141A2023, .mask = 0xffffffff }, /* 0x5A0 */
	.lna_nf_set1_ref1   = { .val = 0x000D0E10, .mask = 0xffffffff }, /* 0x5A4 */
	.lna_nf_set1_ref2   = { .val = 0x04080C0F, .mask = 0xffffffff }, /* 0x5A8 */
	.lna_nf_set1_ref3   = { .val = 0x03030303, .mask = 0xffffffff }, /* 0x5AC */
	.lna_icp1_set1_ref0 = { .val = 0x7A7D0000, .mask = 0xffffffff }, /* 0x5B0 */
	.lna_icp1_set1_ref1 = { .val = 0x00737678, .mask = 0xffffffff }, /* 0x5B4 */
	.lna_icp1_set1_ref2 = { .val = 0x66696C6C, .mask = 0xffffffff }, /* 0x5B8 */
	.lna_icp1_set1_ref3 = { .val = 0x625F6264, .mask = 0xffffffff }, /* 0x5BC */
};

static struct cl_agc_params agc_params_5g = {
	.id                 = 5,
	.fsm_preset_p2      = { .val = 0x00004701, .mask = 0xffffffff }, /* 0x244 */
	.lna_thr_set0_ref2  = { .val = 0x2C26211D, .mask = 0xffffffff }, /* 0x25C */
	.lna_thr_set0_ref3  = { .val = 0x00333330, .mask = 0xffffffff }, /* 0x260 */
	.lna_thr_set1_ref2  = { .val = 0x2C26211D, .mask = 0xffffffff }, /* 0x264 */
	.lna_thr_set1_ref3  = { .val = 0x5B333330, .mask = 0xffffffff }, /* 0x268 */
	.lna_thr_set2_ref2  = { .val = 0x2C26211D, .mask = 0xffffffff }, /* 0x26C */
	.lna_thr_set2_ref3  = { .val = 0x5B333330, .mask = 0xffffffff }, /* 0x270 */
	.lna_gain_set0_ref2 = { .val = 0x2F2B2722, .mask = 0xffffffff }, /* 0x274 */
	.lna_gain_set0_ref3 = { .val = 0x3D3D3934, .mask = 0xffffffff }, /* 0x278 */
	.lna_nf_set0_ref2   = { .val = 0x0406090D, .mask = 0xffffffff }, /* 0x27C */
	.lna_nf_set0_ref3   = { .val = 0x02030303, .mask = 0xffffffff }, /* 0x280 */
	.lna_icp1_set0_ref2 = { .val = 0x5D666A6F, .mask = 0xffffffff }, /* 0x284 */
	.lna_icp1_set0_ref3 = { .val = 0x5757575B, .mask = 0xffffffff }, /* 0x288 */
	.fsm_preset_p10     = { .val = 0x00001E21, .mask = 0xffffffff }, /* 0x2A8 */
	.fsm_preset_p11     = { .val = 0x00001E21, .mask = 0xffffffff }, /* 0x2AC */
	.fsm_preset_p12     = { .val = 0x00ECEA07, .mask = 0xffffffff }, /* 0x2B0 */
	.ant_loss           = { .val = 0x00000000, .mask = 0xffffffff }, /* 0x300 */
	.gain_range         = { .val = 0x47026402, .mask = 0xffffffff }, /* 0x304 */
	.vga_ref0           = { .val = 0x00010214, .mask = 0xffffffff }, /* 0x308 */
	.lna_gain_set0_ref0 = { .val = 0x1915110C, .mask = 0xffffffff }, /* 0x30C */
	.lna_gain_set0_ref1 = { .val = 0x2727231E, .mask = 0xffffffff }, /* 0x310 */
	.lna_thr_set0_ref0  = { .val = 0x15100B07, .mask = 0xffffffff }, /* 0x314 */
	.lna_thr_set0_ref1  = { .val = 0x1D1D1D19, .mask = 0xffffffff }, /* 0x318 */
	.lna_thr_set1_ref0  = { .val = 0x15100B07, .mask = 0xffffffff }, /* 0x31C */
	.lna_thr_set1_ref1  = { .val = 0x1D1D1D19, .mask = 0xffffffff }, /* 0x320 */
	.lna_thr_set2_ref0  = { .val = 0x15100B07, .mask = 0xffffffff }, /* 0x324 */
	.lna_thr_set2_ref1  = { .val = 0x1D1D1D19, .mask = 0xffffffff }, /* 0x328 */
	.lna_nf_set0_ref0   = { .val = 0x12171C20, .mask = 0xffffffff }, /* 0x32C */
	.lna_nf_set0_ref1   = { .val = 0x0A0B0B0F, .mask = 0xffffffff }, /* 0x330 */
	.lna_icp1_set0_ref0 = { .val = 0x6F727476, .mask = 0xffffffff }, /* 0x334 */
	.lna_icp1_set0_ref1 = { .val = 0x6268686D, .mask = 0xffffffff }, /* 0x338 */
	.ramp               = { .val = 0x05200710, .mask = 0xffffffff }, /* 0x36C */
	.dsp3               = { .val = 0x0B730000, .mask = 0xffff0000 }, /* 0x3A0 */
	.lna_gain_set1_ref0 = { .val = 0x1915110C, .mask = 0xffffffff }, /* 0x590 */
	.lna_gain_set1_ref1 = { .val = 0x2727231E, .mask = 0xffffffff }, /* 0x594 */
	.lna_gain_set1_ref2 = { .val = 0x2F2B2722, .mask = 0xffffffff }, /* 0x598 */
	.lna_gain_set1_ref3 = { .val = 0x3D3D3934, .mask = 0xffffffff }, /* 0x59C */
	.lna_nf_set1_ref0   = { .val = 0x12171C20, .mask = 0xffffffff }, /* 0x5A0 */
	.lna_nf_set1_ref1   = { .val = 0x0A0B0B0F, .mask = 0xffffffff }, /* 0x5A4 */
	.lna_nf_set1_ref2   = { .val = 0x0406090D, .mask = 0xffffffff }, /* 0x5A8 */
	.lna_nf_set1_ref3   = { .val = 0x02030303, .mask = 0xffffffff }, /* 0x5AC */
	.lna_icp1_set1_ref0 = { .val = 0x6F727476, .mask = 0xffffffff }, /* 0x5B0 */
	.lna_icp1_set1_ref1 = { .val = 0x6268686D, .mask = 0xffffffff }, /* 0x5B4 */
	.lna_icp1_set1_ref2 = { .val = 0x5D666A6F, .mask = 0xffffffff }, /* 0x5B8 */
	.lna_icp1_set1_ref3 = { .val = 0x5757575B, .mask = 0xffffffff }, /* 0x5BC */
};

static struct cl_agc_params agc_params_6g = {
	.id                 = 6,
	.fsm_preset_p2      = { .val = 0x00004701, .mask = 0xffffffff }, /* 0x244 */
	.lna_thr_set0_ref2  = { .val = 0x2C27221F, .mask = 0xffffffff }, /* 0x25C */
	.lna_thr_set0_ref3  = { .val = 0x00363630, .mask = 0xffffffff }, /* 0x260 */
	.lna_thr_set1_ref2  = { .val = 0x2C27221F, .mask = 0xffffffff }, /* 0x264 */
	.lna_thr_set1_ref3  = { .val = 0x5B363630, .mask = 0xffffffff }, /* 0x268 */
	.lna_thr_set2_ref2  = { .val = 0x2C27221F, .mask = 0xffffffff }, /* 0x26C */
	.lna_thr_set2_ref3  = { .val = 0x5B363630, .mask = 0xffffffff }, /* 0x270 */
	.lna_gain_set0_ref2 = { .val = 0x1A17130E, .mask = 0xffffffff }, /* 0x274 */
	.lna_gain_set0_ref3 = { .val = 0x2B2B2520, .mask = 0xffffffff }, /* 0x278 */
	.lna_nf_set0_ref2   = { .val = 0x0406090D, .mask = 0xffffffff }, /* 0x27C */
	.lna_nf_set0_ref3   = { .val = 0x02030303, .mask = 0xffffffff }, /* 0x280 */
	.lna_icp1_set0_ref2 = { .val = 0x5D666A6F, .mask = 0xffffffff }, /* 0x284 */
	.lna_icp1_set0_ref3 = { .val = 0x5757575B, .mask = 0xffffffff }, /* 0x288 */
	.fsm_preset_p10     = { .val = 0x00001E21, .mask = 0xffffffff }, /* 0x2A8 */
	.fsm_preset_p11     = { .val = 0x00001E21, .mask = 0xffffffff }, /* 0x2AC */
	.fsm_preset_p12     = { .val = 0x00ECEA07, .mask = 0xffffffff }, /* 0x2B0 */
	.ant_loss           = { .val = 0x00000000, .mask = 0xffffffff }, /* 0x300 */
	.gain_range         = { .val = 0x47026402, .mask = 0xffffffff }, /* 0x304 */
	.vga_ref0           = { .val = 0x00E1A214, .mask = 0xffffffff }, /* 0x308 */
	.lna_gain_set0_ref0 = { .val = 0x04017D78, .mask = 0xffffffff }, /* 0x30C */
	.lna_gain_set0_ref1 = { .val = 0x15150F0A, .mask = 0xffffffff }, /* 0x310 */
	.lna_thr_set0_ref0  = { .val = 0x18120E0B, .mask = 0xffffffff }, /* 0x314 */
	.lna_thr_set0_ref1  = { .val = 0x1F1F1F1C, .mask = 0xffffffff }, /* 0x318 */
	.lna_thr_set1_ref0  = { .val = 0x18120E0B, .mask = 0xffffffff }, /* 0x31C */
	.lna_thr_set1_ref1  = { .val = 0x1F1F1F1C, .mask = 0xffffffff }, /* 0x320 */
	.lna_thr_set2_ref0  = { .val = 0x18120E0B, .mask = 0xffffffff }, /* 0x324 */
	.lna_thr_set2_ref1  = { .val = 0x1F1F1F1C, .mask = 0xffffffff }, /* 0x328 */
	.lna_nf_set0_ref0   = { .val = 0x12171C20, .mask = 0xffffffff }, /* 0x32C */
	.lna_nf_set0_ref1   = { .val = 0x0A0B0B0F, .mask = 0xffffffff }, /* 0x330 */
	.lna_icp1_set0_ref0 = { .val = 0x6F727476, .mask = 0xffffffff }, /* 0x334 */
	.lna_icp1_set0_ref1 = { .val = 0x6268686D, .mask = 0xffffffff }, /* 0x338 */
	.ramp               = { .val = 0x05200710, .mask = 0xffffffff }, /* 0x36C */
	.dsp3               = { .val = 0x0B730000, .mask = 0xffff0000 }, /* 0x3A0 */
	.lna_gain_set1_ref0 = { .val = 0x05017D78, .mask = 0xffffffff }, /* 0x590 */
	.lna_gain_set1_ref1 = { .val = 0x13130F0A, .mask = 0xffffffff }, /* 0x594 */
	.lna_gain_set1_ref2 = { .val = 0x1B17130E, .mask = 0xffffffff }, /* 0x598 */
	.lna_gain_set1_ref3 = { .val = 0x29292520, .mask = 0xffffffff }, /* 0x59C */
	.lna_nf_set1_ref0   = { .val = 0x12171C20, .mask = 0xffffffff }, /* 0x5A0 */
	.lna_nf_set1_ref1   = { .val = 0x0A0B0B0F, .mask = 0xffffffff }, /* 0x5A4 */
	.lna_nf_set1_ref2   = { .val = 0x0406090D, .mask = 0xffffffff }, /* 0x5A8 */
	.lna_nf_set1_ref3   = { .val = 0x02030303, .mask = 0xffffffff }, /* 0x5AC */
	.lna_icp1_set1_ref0 = { .val = 0x6F727476, .mask = 0xffffffff }, /* 0x5B0 */
	.lna_icp1_set1_ref1 = { .val = 0x6268686D, .mask = 0xffffffff }, /* 0x5B4 */
	.lna_icp1_set1_ref2 = { .val = 0x5D666A6F, .mask = 0xffffffff }, /* 0x5B8 */
	.lna_icp1_set1_ref3 = { .val = 0x5757575B, .mask = 0xffffffff }, /* 0x5BC */
};

#ifdef __BIG_ENDIAN_BITFIELD
static void agc_params_to_le32(struct cl_agc_params *agc_params)
{
	u32 i;
	u32 size = sizeof(struct cl_agc_params);
	u32 *ptr = (u32 *)agc_params;

	/* Make sure that size divides by 4 */
	WARN_ON((size & 0x3) != 0);

	for (i = 0; i < size / 4; i++)
		ptr[i] = cpu_to_le32(ptr[i]);
}
#endif

void cl_agc_params_fill(struct cl_hw *cl_hw, struct cl_agc_params *agc_params)
{
	if (cl_band_is_24g(cl_hw))
		memcpy(agc_params, &agc_params_24g, sizeof(struct cl_agc_params));
	else if (cl_band_is_5g(cl_hw))
		memcpy(agc_params, &agc_params_5g, sizeof(struct cl_agc_params));
	else
		memcpy(agc_params, &agc_params_6g, sizeof(struct cl_agc_params));

#ifdef __BIG_ENDIAN_BITFIELD
	agc_params_to_le32(agc_params);
#endif
}

static void _cl_agc_params_dump(struct cl_hw *cl_hw, char **buf, int *len,
				ssize_t *buf_size, struct cl_agc_params *agc_params)
{
	cl_snprintf(buf, len, buf_size,
		    "|------------------------------------------------------|\n"
		    "| Addr  | Name               | Mask       | Value      |\n"
		    "|-------+--------------------+------------+------------|\n");
	cl_snprintf(buf, len, buf_size,
		    "| 0x244 | fsm_preset_p2      | 0x%08x | 0x%08x |\n",
		    agc_params->fsm_preset_p2.mask, agc_params->fsm_preset_p2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x25C | lna_thr_set0_ref2  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set0_ref2.mask, agc_params->lna_thr_set0_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x260 | lna_thr_set0_ref3  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set0_ref3.mask, agc_params->lna_thr_set0_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x264 | lna_thr_set1_ref2  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set1_ref2.mask, agc_params->lna_thr_set1_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x268 | lna_thr_set1_ref3  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set1_ref3.mask, agc_params->lna_thr_set1_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x26C | lna_thr_set2_ref2  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set2_ref2.mask, agc_params->lna_thr_set2_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x270 | lna_thr_set2_ref3  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set2_ref3.mask, agc_params->lna_thr_set2_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x274 | lna_gain_set0_ref2 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_gain_set0_ref2.mask, agc_params->lna_gain_set0_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x278 | lna_gain_set0_ref3 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_gain_set0_ref3.mask, agc_params->lna_gain_set0_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x27C | lna_nf_set0_ref2   | 0x%08x | 0x%08x |\n",
		    agc_params->lna_nf_set0_ref2.mask, agc_params->lna_nf_set0_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x280 | lna_nf_set0_ref3   | 0x%08x | 0x%08x |\n",
		    agc_params->lna_nf_set0_ref3.mask, agc_params->lna_nf_set0_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x284 | lna_icp1_set0_ref2 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_icp1_set0_ref2.mask, agc_params->lna_icp1_set0_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x288 | lna_icp1_set0_ref3 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_icp1_set0_ref3.mask, agc_params->lna_icp1_set0_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x2A8 | fsm_preset_p10     | 0x%08x | 0x%08x |\n",
		    agc_params->fsm_preset_p10.mask, agc_params->fsm_preset_p10.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x2AC | fsm_preset_p11     | 0x%08x | 0x%08x |\n",
		    agc_params->fsm_preset_p11.mask, agc_params->fsm_preset_p11.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x2B0 | fsm_preset_p12     | 0x%08x | 0x%08x |\n",
		    agc_params->fsm_preset_p12.mask, agc_params->fsm_preset_p12.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x300 | ant_loss           | 0x%08x | 0x%08x |\n",
		    agc_params->ant_loss.mask, agc_params->ant_loss.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x304 | gain_range         | 0x%08x | 0x%08x |\n",
		    agc_params->gain_range.mask, agc_params->gain_range.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x308 | vga_ref0           | 0x%08x | 0x%08x |\n",
		    agc_params->vga_ref0.mask, agc_params->vga_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x30C | lna_gain_set0_ref0 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_gain_set0_ref0.mask, agc_params->lna_gain_set0_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x310 | lna_gain_set0_ref1 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_gain_set0_ref1.mask, agc_params->lna_gain_set0_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x314 | lna_thr_set0_ref0  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set0_ref0.mask, agc_params->lna_thr_set0_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x318 | lna_thr_set0_ref1  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set0_ref1.mask, agc_params->lna_thr_set0_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x31C | lna_thr_set1_ref0  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set1_ref0.mask, agc_params->lna_thr_set1_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x320 | lna_thr_set1_ref1  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set1_ref1.mask, agc_params->lna_thr_set1_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x324 | lna_thr_set2_ref0  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set2_ref0.mask, agc_params->lna_thr_set2_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x328 | lna_thr_set2_ref1  | 0x%08x | 0x%08x |\n",
		    agc_params->lna_thr_set2_ref1.mask, agc_params->lna_thr_set2_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x32C | lna_nf_set0_ref0   | 0x%08x | 0x%08x |\n",
		    agc_params->lna_nf_set0_ref0.mask, agc_params->lna_nf_set0_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x330 | lna_nf_set0_ref1   | 0x%08x | 0x%08x |\n",
		    agc_params->lna_nf_set0_ref1.mask, agc_params->lna_nf_set0_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x334 | lna_icp1_set0_ref0 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_icp1_set0_ref0.mask, agc_params->lna_icp1_set0_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x338 | lna_icp1_set0_ref1 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_icp1_set0_ref1.mask, agc_params->lna_icp1_set0_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x36C | ramp               | 0x%08x | 0x%08x |\n",
		    agc_params->ramp.mask, agc_params->ramp.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x3A0 | dsp3               | 0x%08x | 0x%08x |\n",
		    agc_params->dsp3.mask, agc_params->dsp3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x590 | lna_gain_set1_ref0 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_gain_set1_ref0.mask,
		    agc_params->lna_gain_set1_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x594 | lna_gain_set1_ref1 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_gain_set1_ref1.mask,
		    agc_params->lna_gain_set1_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x598 | lna_gain_set1_ref2 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_gain_set1_ref2.mask,
		    agc_params->lna_gain_set1_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x59C | lna_gain_set1_ref3 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_gain_set1_ref3.mask,
		    agc_params->lna_gain_set1_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x5A0 | lna_nf_set1_ref0   | 0x%08x | 0x%08x |\n",
		    agc_params->lna_nf_set1_ref0.mask,
		    agc_params->lna_nf_set1_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x5A4 | lna_nf_set1_ref1   | 0x%08x | 0x%08x |\n",
		    agc_params->lna_nf_set1_ref1.mask,
		    agc_params->lna_nf_set1_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x5A8 | lna_nf_set1_ref2   | 0x%08x | 0x%08x |\n",
		    agc_params->lna_nf_set1_ref2.mask,
		    agc_params->lna_nf_set1_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x5AC | lna_nf_set1_ref3   | 0x%08x | 0x%08x |\n",
		    agc_params->lna_nf_set1_ref3.mask,
		    agc_params->lna_nf_set1_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x5B0 | lna_icp1_set1_ref0 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_icp1_set1_ref0.mask,
		    agc_params->lna_icp1_set1_ref0.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x5B4 | lna_icp1_set1_ref1 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_icp1_set1_ref1.mask,
		    agc_params->lna_icp1_set1_ref1.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x5B8 | lna_icp1_set1_ref2 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_icp1_set1_ref2.mask,
		    agc_params->lna_icp1_set1_ref2.val);
	cl_snprintf(buf, len, buf_size,
		    "| 0x5BC | lna_icp1_set1_ref3 | 0x%08x | 0x%08x |\n",
		    agc_params->lna_icp1_set1_ref3.mask,
		    agc_params->lna_icp1_set1_ref3.val);
	cl_snprintf(buf, len, buf_size,
		    "|------------------------------------------------------|\n");
}

static int cl_agc_params_dump(struct cl_hw *cl_hw)
{
	struct cl_agc_params *agc_params = &cl_hw->phy_data_info.data->agc_params;
	char *buf = NULL;
	ssize_t buf_size;
	int err = 0;
	int len = 0;

	if (agc_params->id) {
		cl_snprintf(&buf, &len, &buf_size, "AGC Params [%ug]\n", cl_hw->conf->ci_band_num);
		_cl_agc_params_dump(cl_hw, &buf, &len, &buf_size, agc_params);
	}

	err = cl_vendor_reply(cl_hw, buf, len);
	kfree(buf);

	return err;
}

static int cl_agc_params_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "agc_params usage:\n"
		 "-d : Dump AGC parameters\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

int cl_agc_params_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	bool dump_params = false;
	u32 expected_params = -1;

	switch (cli_params->option) {
	case 'd':
		dump_params = true;
		expected_params = 0;
		break;
	case '?':
		return cl_agc_params_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (dump_params)
		return cl_agc_params_dump(cl_hw);

out_err:
	return -EIO;
}

