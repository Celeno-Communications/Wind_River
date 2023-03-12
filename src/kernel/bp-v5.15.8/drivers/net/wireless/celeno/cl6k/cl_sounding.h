/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CL_SOUNDING_H
#define CL_SOUNDING_H

#include <linux/types.h>
#include "cl_fw_msg.h"

#define SOUNDING_ENABLE                                true
#define SOUNDING_DISABLE                               false
#define INVALID_SID                                    0xff
#define XMEM_SIZE                                      (0x180 << 10) /* 384KB */
#define CL_SOUNDING_STABILITY_TIME                     5

#define SOUNDING_FEEDBACK_TYPE_SHIFT                   2
#define SOUNDING_FEEDBACK_TYPE_MASK                    (BIT(SOUNDING_FEEDBACK_TYPE_SHIFT))
#define SOUNDING_NG_SHIFT                              1
#define SOUNDING_NG_MASK                               (BIT(SOUNDING_NG_SHIFT))
#define SOUNDING_MU_CODEBOOK_SIZE_SHIFT                0
#define SOUNDING_MU_CODEBOOK_SIZE_MASK                 (BIT(SOUNDING_MU_CODEBOOK_SIZE_SHIFT))
#define SOUNDING_FEEDBACK_TYPE_VAL(fb_type_ng_cb_size) (((fb_type_ng_cb_size) & \
							  SOUNDING_FEEDBACK_TYPE_MASK) >> \
							  SOUNDING_FEEDBACK_TYPE_SHIFT)
#define SOUNDING_NG_VAL(fb_type_ng_cb_size)            (((fb_type_ng_cb_size) & \
							  SOUNDING_NG_MASK) >> SOUNDING_NG_SHIFT)
#define SOUNDING_CODEBOOK_SIZE_VAL(fb_type_ng_cb_size) (((fb_type_ng_cb_size) & \
							  SOUNDING_MU_CODEBOOK_SIZE_MASK) >> \
							  SOUNDING_MU_CODEBOOK_SIZE_SHIFT)

#define SOUNDING_TYPE_IS_MU(type)                      ((type) >= SOUNDING_TYPE_HE_MU && \
							(type) < SOUNDING_TYPE_MAX)
#define SOUNDING_TYPE_IS_VHT(type)                     ((type) == SOUNDING_TYPE_VHT_SU || \
							(type) == SOUNDING_TYPE_VHT_MU)
#define SOUNDING_TYPE_IS_CQI(type)                     ((type) == SOUNDING_TYPE_HE_CQI || \
							(type) == SOUNDING_TYPE_HE_CQI_TB)

enum fb_type_ng_cb_size {
	FEEDBACK_TYPE_SU_NG_4_CODEBOOK_SIZE_4_2 = 0x0,
	FEEDBACK_TYPE_SU_NG_4_CODEBOOK_SIZE_6_4,
	FEEDBACK_TYPE_SU_NG_16_CODEBOOK_SIZE_4_2,
	FEEDBACK_TYPE_SU_NG_16_CODEBOOK_SIZE_6_4,
	FEEDBACK_TYPE_MU_NG_4_CODEBOOK_SIZE_7_5,
	FEEDBACK_TYPE_MU_NG_4_CODEBOOK_SIZE_9_7,
	FEEDBACK_TYPE_CQI_TB,
	FEEDBACK_TYPE_MU_NG_16_CODEBOOK_SIZE_9_7,
};

enum cl_sounding_response {
	CL_SOUNDING_RSP_OK = 0,

	CL_SOUNDING_RSP_ERR_RLIMIT,
	CL_SOUNDING_RSP_ERR_BW,
	CL_SOUNDING_RSP_ERR_NSS,
	CL_SOUNDING_RSP_ERR_INTERVAL,
	CL_SOUNDING_RSP_ERR_ALREADY,
	CL_SOUNDING_RSP_ERR_STA,
	CL_SOUNDING_RSP_ERR_TYPE,
};

enum sounding_type {
	SOUNDING_TYPE_HE_SU = 0,
	SOUNDING_TYPE_HE_SU_TB,
	SOUNDING_TYPE_VHT_SU,
	SOUNDING_TYPE_HE_CQI,
	SOUNDING_TYPE_HE_CQI_TB,
	SOUNDING_TYPE_HE_MU,
	SOUNDING_TYPE_VHT_MU,

	SOUNDING_TYPE_MAX
};

enum sounding_interval_coef {
	SOUNDING_INTERVAL_COEF_MIN_INTERVAL = 0,
	SOUNDING_INTERVAL_COEF_STA_STEP,
	SOUNDING_INTERVAL_COEF_INTERVAL_STEP,
	SOUNDING_INTERVAL_COEF_MAX_INTERVAL,
	SOUNDING_INTERVAL_COEF_MAX
};

struct cl_hw;

struct v_matrix_header {
	u32 format        : 2,
	    rsv1          : 30;
	u32 bw            : 2,
	    nr_index      : 3,
	    nc_index      : 3,
	    rsv2          : 24;
	u32 grouping      : 4,
	    rsv3          : 28;
	u32 feedback_type : 1,
	    codebook_info : 3,
	    rsv4          : 28;
	u32 ru_start_idx  : 7,
	    rsv5          : 25;
	u32 ru_end_idx    : 7,
	    rsv6          : 25;
	u32 padding       : 6,
	    rsv7          : 26;
	u32 rsv8;
};

struct cl_sounding_info {
	enum sounding_type type;
	u8 sounding_id;
	struct v_matrix_header *v_matrices_data;
	u32 v_matrices_data_len;
	u32 v_matrices_dma_addr;
	u8 gid;
	u8 bw;
	u8 sta_num;
	u8 q_matrix_bitmap;
	struct cl_sta *su_cl_sta_arr[CL_MU_MAX_STA_PER_GROUP];
	u32 xmem_space;
	struct list_head list;
};

struct cl_sounding_db {
	struct workqueue_struct *sounding_wq;
	u8 num_soundings;
	u8 cqi_profiles; /* Num of STAs with CQI active sounding */
	u8 active_profiles; /* Num of STAs with non-CQI active sounding */
	u8 active_profiles_prev[CL_SOUNDING_STABILITY_TIME];
	u8 active_profiles_idx;
	u8 dbg_level;
	u8 current_interval;
	u8 last_conf_active_profiles;
	rwlock_t lock;
	struct list_head head;
};

void cl_sounding_init(struct cl_hw *cl_hw);
void cl_sounding_close(struct cl_hw *cl_hw);
void cl_sounding_send_request(struct cl_hw *cl_hw, struct cl_sta **cl_sta_arr,
			      u8 sta_num, bool enable, u8 sounding_type, u8 bw,
			      u8 q_matrix_bitmap, struct cl_sounding_info *recovery_elem);
void cl_sounding_switch_profile(struct cl_hw *cl_hw, u8 sta_idx_en, u8 sta_idx_dis);
void cl_sounding_maintenance(struct cl_hw *cl_hw);
u16 cl_sounding_get_interval(struct cl_hw *cl_hw);
void cl_sounding_recovery(struct cl_hw *cl_hw);
void cl_sounding_indication(struct cl_hw *cl_hw, struct mm_sounding_ind *ind);
int cl_sounding_cli(struct cl_hw *cl_hw, struct cli_params *cli_params);

#endif /* CL_SOUNDING_H */
