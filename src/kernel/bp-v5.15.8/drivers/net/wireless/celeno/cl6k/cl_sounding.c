// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_sounding.h"
#include "cl_msg_tx.h"
#include "cl_bf.h"
#include "cl_band.h"
#include "cl_recovery.h"
#include "chip_ops.h"

#define DBG_PREFIX_MAX_LENGTH 64
#define sounding_pr(level, format, ...) \
	do { \
		if ((level) <= cl_hw->sounding.dbg_level) { \
			char __dbg_prefix[DBG_PREFIX_MAX_LENGTH] = {0}; \
			if ((level) >= DBG_LVL_TRACE) \
				snprintf(__dbg_prefix, DBG_PREFIX_MAX_LENGTH, "[%s][%d]", \
					 __func__, __LINE__); \
			pr_debug("%s [Sounding] " format, __dbg_prefix, ##__VA_ARGS__); \
		} \
	} while (0)

#define sounding_pr_verbose(...) sounding_pr(DBG_LVL_VERBOSE, ##__VA_ARGS__)
#define sounding_pr_err(...)     sounding_pr(DBG_LVL_ERROR, ##__VA_ARGS__)
#define sounding_pr_warn(...)    sounding_pr(DBG_LVL_WARNING, ##__VA_ARGS__)
#define sounding_pr_trace(...)   sounding_pr(DBG_LVL_TRACE, ##__VA_ARGS__)
#define sounding_pr_info(...)    sounding_pr(DBG_LVL_INFO, ##__VA_ARGS__)

#define CL_SOUNDING_TYPE_2_STR(type) ((type) == SOUNDING_TYPE_HE_SU ? "HE_SU" : \
				      (type) == SOUNDING_TYPE_HE_SU_TB ? "HE_SU_TB" : \
				      (type) == SOUNDING_TYPE_VHT_SU ? "VHT_SU" : \
				      (type) == SOUNDING_TYPE_HE_CQI ? "HE_CQI" : \
				      (type) == SOUNDING_TYPE_HE_CQI_TB ? "HE_CQI_TB" :\
				      (type) == SOUNDING_TYPE_HE_MU ? "HE_MU" : \
				      (type) == SOUNDING_TYPE_VHT_MU ? "VHT_MU" : "INVALID")

#define CL_SOUNDING_ALL_STA          0xff
#define CL_SOUNDING_LIFETIME_MAX     4095
#define CL_SOUNDING_LIFETIME_FACTOR  5
#define CL_SOUNDING_V_MATRIX_PADDING 32
#define V_MATRIX_MAC_OVERHEAD        41
#define Q_MATRIX_BITMAP_MASK         0xf

enum cl_sounding_feedback_type {
	CL_SOUNDING_FEEDBACK_TYPE_SU = 0,
	CL_SOUNDING_FEEDBACK_TYPE_MU,
};

enum cl_sounding_ng {
	CL_SOUNDING_NG_4 = 0,
	CL_SOUNDING_NG_16,
	CL_SOUNDING_NG_MAX
};

struct sounding_work_data {
	struct work_struct  work;
	struct cl_hw *cl_hw;
	bool start;
	bool is_recovery;
	struct cl_sounding_info *recovery_elem;
	enum sounding_type sounding_type;
	u8 gid;
	u8 sta_num;
	u8 bw;
	u8 q_matrix_bitmap;
	struct cl_sta *cl_sta_arr[CL_MU_MAX_STA_PER_GROUP];
};

static u16 ng_bw_to_nsc[CL_SOUNDING_NG_MAX][CHNL_BW_MAX_HE] = {
	{64, 128, 256, 512},
	{32, 32, 64, 128}
};

static int cl_sounding_check_response(struct cl_hw *cl_hw, u8 param_err)
{
	int ret = -1;

	switch (param_err) {
	case CL_SOUNDING_RSP_OK:
		sounding_pr_trace("param OK!\n");
		ret = 0;
		break;
	case CL_SOUNDING_RSP_ERR_RLIMIT:
		sounding_pr_err("error, resource limit reached\n");
		break;
	case CL_SOUNDING_RSP_ERR_BW:
		sounding_pr_err("error, unsupported BW tx requested\n");
		break;
	case CL_SOUNDING_RSP_ERR_NSS:
		sounding_pr_err("error, unsupported ndp NSS tx requested\n");
		break;
	case CL_SOUNDING_RSP_ERR_INTERVAL:
		sounding_pr_err("error, interval value is invalid\n");
		break;
	case CL_SOUNDING_RSP_ERR_ALREADY:
		sounding_pr_err("error, station already associated/disassociated with sounding\n");
		break;
	case CL_SOUNDING_RSP_ERR_STA:
		sounding_pr_err("error, station is inactive/active\n");
		break;
	case CL_SOUNDING_RSP_ERR_TYPE:
		sounding_pr_err("error, invalid sounding type\n");
		break;
	default:
		sounding_pr_err("error status unknown, BUG\n");
		break;
	}

	return ret;
}

static u32 cl_sounding_get_lifetime(struct cl_hw *cl_hw, u32 interval)
{
	u32 lifetime = (interval * CL_SOUNDING_LIFETIME_FACTOR) >> 1;

	if (lifetime > CL_SOUNDING_LIFETIME_MAX) {
		sounding_pr_err("lifetime (%u) exceeds 4095\n", lifetime);
		lifetime = CL_SOUNDING_LIFETIME_MAX;
	}

	return lifetime;
}

static void cl_sounding_extract_ng_cb_size(struct cl_hw *cl_hw, u8 fb_type_ng_cb_size,
					   enum cl_sounding_ng *ng, u8 *phi_psi_sum)
{
	enum cl_sounding_feedback_type fb_type =
		SOUNDING_FEEDBACK_TYPE_VAL(fb_type_ng_cb_size);
	u8 cb_size = SOUNDING_CODEBOOK_SIZE_VAL(fb_type_ng_cb_size);

	*ng = SOUNDING_NG_VAL(fb_type_ng_cb_size);

	switch (fb_type) {
	case CL_SOUNDING_FEEDBACK_TYPE_SU:
		*phi_psi_sum = (cb_size ? 10 : 6);
		break;
	case CL_SOUNDING_FEEDBACK_TYPE_MU:
		*phi_psi_sum = (cb_size ? 16 : 12);
		break;
	default:
		sounding_pr_err("Invalid feedback_type %d\n", fb_type);
		break;
	}
}

static u32 cl_sounding_get_v_matrix_size(struct cl_hw *cl_hw, u8 sta_idx, u8 bw, u8 nc, u8 nr,
					 u8 fb_type_ng_cb_size)
{
	enum cl_sounding_ng ng = 0;
	u8 phi_psi_sum = 0;
	u8 nsc;
	u32 v_size;

	cl_sounding_extract_ng_cb_size(cl_hw, fb_type_ng_cb_size, &ng, &phi_psi_sum);
	nsc = ng_bw_to_nsc[ng][bw];

	/* NC and NR should start from 1 and not 0 for the below calculation */
	nc++;
	nr++;

	/* v_size = [8*41 + 8*nc + (phi + psi)/2 * nsc*(nc * (2*nr-nc-1))] / 8 + extra padding */
	v_size = V_MATRIX_MAC_OVERHEAD + nc +
		     ((phi_psi_sum * nsc * nc * (2 * nr - nc - 1)) >> 4) +
		     CL_SOUNDING_V_MATRIX_PADDING;

	sounding_pr_info("sta %u, nc %u, nr %u, ng %d, phi_psi_sum %u, nsc %u, v_size %u\n",
			 sta_idx, nc, nr, ng, phi_psi_sum, nsc, v_size);

	return v_size;
}

static u32 cl_sounding_get_v_matrices_data_size(struct cl_hw *cl_hw,
						struct sounding_info_per_sta *info_per_sta,
						u8 sta_num, u8 bw, u8 nr)
{
	u8 i;
	u32 v_size = 0;

	for (i = 0; i < sta_num; i++)
		v_size += cl_sounding_get_v_matrix_size(cl_hw, info_per_sta[i].sta_idx,
							bw, info_per_sta[i].nc,
							nr, info_per_sta[i].fb_type_ng_cb_size);

	sounding_pr_info("v_matrices data size %u, sta_num %u\n", v_size, sta_num);

	return v_size;
}

static u32 cl_sounding_get_q_matrix_size(struct cl_hw *cl_hw,
					 const struct sounding_info_per_sta *info_per_sta,
					 u8 sta_num, u8 bw, u8 nr)
{
	u8 i;
	u8 nc = 0;
	enum cl_sounding_ng ng = 0;
	u8 nsc, phi_psi_sum = 0;
	u32 q_size = 0;

	/*
	 * NC and NR should start from 1 and not 0 for the below calculation
	 * In MU-MIMO case, when sta_num > 1, we should take the sum of all nc's
	 */
	for (i = 0; i < sta_num; i++)
		nc += info_per_sta[i].nc + 1;

	nr++;

	cl_sounding_extract_ng_cb_size(cl_hw, info_per_sta[0].fb_type_ng_cb_size, &ng,
				       &phi_psi_sum);
	nsc = ng_bw_to_nsc[ng][bw];
	q_size = (nr * nc * nsc) << 2;

	sounding_pr_info("q_matrix size %u, sta_num %u\n", q_size, sta_num);

	return q_size;
}

static u32 cl_sounding_get_required_xmem_size(struct cl_hw *cl_hw,
					      const struct mm_sounding_req *sounding_req,
					      const struct sounding_info_per_sta *info_per_sta)
{
	u8 i;
	u8 sta_num = sounding_req->sta_num;
	u8 q_matrix_bitmap = sounding_req->q_matrix_bitmap;
	u8 bw = sounding_req->req_txbw;
	u8 nr = sounding_req->ndp_nsts;
	u32 total_size = 0;

	/*
	 * In case of MU sounding only one Q matrix is generated.
	 * Otherwise, the number of Q matrices equals to te number of stations
	 */
	if (sta_num > 1 &&
	    sounding_req->sounding_type != SOUNDING_TYPE_HE_MU &&
	    sounding_req->sounding_type != SOUNDING_TYPE_VHT_MU)
		for (i = 0; i < sta_num; i++)
			total_size +=
			cl_sounding_get_q_matrix_size(cl_hw, &info_per_sta[i], 1, bw, nr);
	else
		total_size =
			cl_sounding_get_q_matrix_size(cl_hw, info_per_sta, sta_num, bw, nr);

	/*
	 * If additional SU Q matrices should be generated - consider them also when calculating
	 * the required XMEM space
	 */
	if (q_matrix_bitmap) {
		for (i = 0; i < CL_MU_MIMO_MAX_STA_PER_GRP; i++)
			if (q_matrix_bitmap & BIT(i))
				total_size +=
				cl_sounding_get_q_matrix_size(cl_hw, &info_per_sta[i], 1, bw, nr);
	}

	return total_size;
}

static bool cl_sounding_is_enough_xmem_space(struct cl_hw *cl_hw,
					     const struct mm_sounding_req *sounding_req,
					     const struct sounding_info_per_sta *info_per_sta,
					     u32 *required_size)
{
	struct cl_xmem *xmem_db = &cl_hw->chip->xmem_db;
	u32 req_mem = cl_sounding_get_required_xmem_size(cl_hw, sounding_req, info_per_sta);

	if (required_size)
		*required_size = req_mem;

	return ((xmem_db->size - xmem_db->total_used) >= req_mem);
}

static int cl_sounding_fill_info_per_sta(struct cl_hw *cl_hw, u8 sounding_type, u8 bw, u8 sta_num,
					 struct cl_sta **cl_sta_arr,
					 struct sounding_info_per_sta *info_per_sta,
					 u8 *n_sts)
{
	u8 i;
	u8 min_sts = cl_hw->num_antennas;
	struct cl_sta *cl_sta = NULL;
	u8 mu_fb_type_ng_cb_size = FEEDBACK_TYPE_MU_NG_4_CODEBOOK_SIZE_9_7;

	for (i = 0; i < sta_num; i++) {
		cl_sta = cl_sta_arr[i];

		if (!cl_sta)
			continue;

		info_per_sta[i].sta_idx = cl_sta->sta_idx;
		info_per_sta[i].nc = cl_sta->bf_db.nc;

		min_sts = min(min_sts, cl_sta->bf_db.beamformee_sts);

		switch (sounding_type) {
		case SOUNDING_TYPE_HE_CQI:
		case SOUNDING_TYPE_HE_SU:
		case SOUNDING_TYPE_VHT_SU:
		case SOUNDING_TYPE_VHT_MU:
			info_per_sta[i].fb_type_ng_cb_size =
				FEEDBACK_TYPE_SU_NG_4_CODEBOOK_SIZE_4_2;
			break;
		case SOUNDING_TYPE_HE_SU_TB:
			info_per_sta[i].fb_type_ng_cb_size =
				FEEDBACK_TYPE_SU_NG_4_CODEBOOK_SIZE_6_4;
			break;
		case SOUNDING_TYPE_HE_CQI_TB:
			info_per_sta[i].fb_type_ng_cb_size =
				FEEDBACK_TYPE_CQI_TB;
			break;
		case SOUNDING_TYPE_HE_MU:
			info_per_sta[i].fb_type_ng_cb_size =
				mu_fb_type_ng_cb_size;
			break;
		default:
			sounding_pr_trace("Invalid sounding type %u\n", sounding_type);
			break;
		}
	}

	*n_sts = min_sts;

	return 0;
}

static struct cl_sounding_info *cl_sounding_elem_alloc(struct cl_hw *cl_hw,
						       u32 v_mat_len)
{
	struct cl_sounding_info *elem = NULL;
	dma_addr_t phys_dma_addr;
	struct v_matrix_header *buf = NULL;

	elem = kzalloc(sizeof(*elem), GFP_KERNEL);

	if (!elem) {
		cl_dbg_err(cl_hw, "kzalloc failed\n");
		return NULL;
	}

	buf = chip_ops_alloc_coherent(cl_hw->chip, v_mat_len, GFP_KERNEL, &phys_dma_addr);

	if (!buf) {
		cl_dbg_err(cl_hw, "chip_ops_alloc_coherent failed. size=%u\n", v_mat_len);
		kfree(elem);
		return NULL;
	}

	elem->v_matrices_data = buf;
	elem->v_matrices_dma_addr = phys_dma_addr;
	elem->v_matrices_data_len = v_mat_len;

	return elem;
}

static void cl_sounding_elem_free(struct cl_hw *cl_hw,
				  struct cl_sounding_info *elem)
{
	struct v_matrix_header *v_data = elem->v_matrices_data;

	if (v_data) {
		chip_ops_free_coherent(cl_hw->chip,
				       elem->v_matrices_data_len,
				       (void *)v_data,
				       elem->v_matrices_dma_addr);
	} else {
		sounding_pr_err("%s: v_matrices_data is NULL for sid %u\n",
				__func__, elem->sounding_id);
	}

	elem->v_matrices_data = NULL;
	kfree(elem);
}

static void cl_sounding_req_success(struct cl_hw *cl_hw,
				    struct cl_sounding_info *elem)
{
	if (elem->gid == 0)
		cl_bf_sounding_req_success(cl_hw, elem);
}

static void cl_sounding_req_failure(struct cl_hw *cl_hw,
				    struct cl_sounding_info *elem)
{
	if (elem->gid == 0)
		cl_bf_sounding_req_failure(cl_hw, elem);
}

static void cl_sounding_increase_num_profiles(struct cl_hw *cl_hw, u8 sounding_type, u8 sta_num)
{
	if (SOUNDING_TYPE_IS_CQI(sounding_type))
		cl_hw->sounding.cqi_profiles += sta_num;
	else
		cl_hw->sounding.active_profiles += sta_num;
}

static void cl_sounding_decrease_num_profiles(struct cl_hw *cl_hw, u8 sounding_type, u8 sta_num)
{
	if (SOUNDING_TYPE_IS_CQI(sounding_type))
		cl_hw->sounding.cqi_profiles -= sta_num;
	else
		cl_hw->sounding.active_profiles -= sta_num;
}

static void _cl_sounding_add(struct cl_hw *cl_hw, struct cl_sounding_info *elem, u8 sounding_id,
			     u32 req_xmem)
{
	write_lock_bh(&cl_hw->sounding.lock);
	elem->sounding_id = sounding_id;
	elem->xmem_space = req_xmem;
	cl_hw->chip->xmem_db.total_used += req_xmem;
	cl_hw->sounding.num_soundings++;
	list_add_tail(&elem->list, &cl_hw->sounding.head);
	cl_sounding_increase_num_profiles(cl_hw, elem->type, elem->sta_num);
	write_unlock_bh(&cl_hw->sounding.lock);
}

static void _cl_sounding_remove(struct cl_hw *cl_hw, struct cl_sounding_info *elem)
{
	/* Remove the sounding sequence from the list and update the used XMEM counter */
	u8 i;

	write_lock_bh(&cl_hw->sounding.lock);
	list_del(&elem->list);
	cl_hw->chip->xmem_db.total_used -= elem->xmem_space;
	cl_hw->sounding.num_soundings--;
	cl_sounding_decrease_num_profiles(cl_hw, elem->type, elem->sta_num);
	write_unlock_bh(&cl_hw->sounding.lock);

	/* Update invalid sid for all STAs related to this sounding sequence */
	for (i = 0; i < elem->sta_num; i++) {
		struct cl_sta *cl_sta = elem->su_cl_sta_arr[i];

		if (cl_sta)
			cl_sta->su_sid = INVALID_SID;
	}

	cl_sounding_elem_free(cl_hw, elem);
}

static void cl_sounding_start_handler(struct cl_hw *cl_hw, struct sounding_work_data *data)
{
	struct mm_sounding_req sounding_req = {{{0}}};
	int ret = 0;
	u32 len = 0;
	u32 req_xmem = 0;
	struct cl_sounding_info *elem = NULL;
	u8 sounding_type = data->sounding_type;
	u8 bw = data->bw;
	u8 sta_num = data->sta_num;
	u8 q_matrix_bitmap = data->q_matrix_bitmap;
	u8 min_nsts = 0;

	q_matrix_bitmap &= Q_MATRIX_BITMAP_MASK;

	/* Configure sounding request parameters */
	sounding_req.start = true;
	sounding_req.sounding_type = sounding_type;
	sounding_req.req_txbw = bw;
	sounding_req.sta_num = sta_num;
	sounding_req.interval = cl_sounding_get_interval(cl_hw);
	sounding_req.lifetime = cl_sounding_get_lifetime(cl_hw, sounding_req.interval);
	sounding_req.q_matrix_bitmap = q_matrix_bitmap;
	ret = cl_sounding_fill_info_per_sta(cl_hw, sounding_type, bw, sta_num, data->cl_sta_arr,
					    sounding_req.info_per_sta, &min_nsts);

	if (ret < 0) {
		sounding_pr_err("cl_sounding_fill_info_per_sta failed (ret %d)\n", ret);
		return;
	}

	sounding_req.ndp_nsts = min_nsts;

	if (data->is_recovery) {
		elem = data->recovery_elem;
	} else {
		/*
		 * Check if there is enough XMEM space.
		 * Should be called after filling sounding req struct
		 */
		if (!cl_sounding_is_enough_xmem_space(cl_hw, &sounding_req,
						      sounding_req.info_per_sta, &req_xmem)) {
			sounding_pr_err("There is not enough space in XMEM!\n");
			return;
		}

		/* Should be called after filling info per STA */
		len = cl_sounding_get_v_matrices_data_size(cl_hw, sounding_req.info_per_sta,
							   sta_num, bw, min_nsts);
		elem = cl_sounding_elem_alloc(cl_hw, len);

		if (!elem)
			return;

		elem->type = sounding_type;
		elem->bw = bw;
		elem->sta_num = sta_num;
		elem->q_matrix_bitmap = q_matrix_bitmap;

		if (data->gid)
			elem->gid = data->gid;
		else
			memcpy(elem->su_cl_sta_arr, data->cl_sta_arr,
			       sta_num * sizeof(data->cl_sta_arr[0]));
	}

	sounding_req.host_address = cpu_to_le32(elem->v_matrices_dma_addr);

	/* Print request parameters */
	sounding_pr_trace("Request: start=%u, bfr_lifetime=%u, interval=%u, "
			   "req_txbw=%u, ndp_nsts=%u, sounding_type=%u\n",
			   sounding_req.start,
			   sounding_req.lifetime,
			   sounding_req.interval,
			   sounding_req.req_txbw,
			   sounding_req.ndp_nsts,
			   sounding_req.sounding_type);

	/* Send message to firmware */
	ret = cl_msg_tx_sounding(cl_hw, &sounding_req);

	/* Check firmware response */
	if (ret == 0) {
		struct mm_sounding_cfm *cfm = cl_hw->msg_cfm_params[MM_SOUNDING_CFM];

		ret = cl_sounding_check_response(cl_hw, cfm->param_err);

		if (ret == 0) {
			if (!data->is_recovery)
				_cl_sounding_add(cl_hw, elem, cfm->sounding_id, req_xmem);

			cl_sounding_req_success(cl_hw, elem);

			sounding_pr_trace("Sounding %u was enabled successfully\n",
					  cfm->sounding_id);
		} else {
			cl_sounding_req_failure(cl_hw, elem);

			if (data->is_recovery)
				_cl_sounding_remove(cl_hw, elem);
		}
	} else {
		sounding_pr_err("%s: failed to send message (%d)\n", __func__, ret);
		cl_sounding_req_failure(cl_hw, elem);

		if (data->is_recovery)
			_cl_sounding_remove(cl_hw, elem);
		else
			cl_sounding_elem_free(cl_hw, elem);
	}

	/* Free message confirmation */
	cl_msg_tx_free_cfm_params(cl_hw, MM_SOUNDING_CFM);
}

static void cl_sounding_stop_handler(struct cl_hw *cl_hw, struct cl_sounding_info *elem)
{
	struct mm_sounding_req sounding_req = {{{0}}};
	int ret = 0;

	if (!elem) {
		sounding_pr_err("elem is NULL!!\n");
		return;
	}

	/* Configure sounding request parameters */
	sounding_req.start = false;
	sounding_req.sounding_type = elem->type;
	sounding_req.sid = elem->sounding_id;

	/* Print request parameters */
	sounding_pr_trace("Delete request: sid=%u, sounding_type=%u\n",
			  elem->sounding_id, elem->type);

	/* Send message to firmware */
	ret = cl_msg_tx_sounding(cl_hw, &sounding_req);

	/* Check firmware response */
	if (ret)
		sounding_pr_err("%s: failed to send message (%d)\n", __func__, ret);

	/* Remove the sounding sequence from the list and update the used XMEM counter.
	 * Notice that elem is freed and shouldn't be accessed after the call to this function.
	 */
	_cl_sounding_remove(cl_hw, elem);

	/* Free message confirmation */
	cl_msg_tx_free_cfm_params(cl_hw, MM_SOUNDING_CFM);
}

static struct cl_sounding_info *cl_sounding_get_elem(struct cl_hw *cl_hw,
						     u8 sounding_id)
{
	struct cl_sounding_info *elem = NULL;

	read_lock_bh(&cl_hw->sounding.lock);

	list_for_each_entry(elem, &cl_hw->sounding.head, list) {
		if (elem->sounding_id == sounding_id) {
			read_unlock_bh(&cl_hw->sounding.lock);
			return elem;
		}
	}

	read_unlock_bh(&cl_hw->sounding.lock);

	return NULL;
}

static void cl_sounding_stop_by_sid(struct cl_hw *cl_hw, u8 sid)
{
	struct cl_sounding_info *elem = cl_sounding_get_elem(cl_hw, sid);

	if (!elem) {
		sounding_pr_trace("Sounding with id %u not found or is in the middle of removal\n",
				  sid);
		return;
	}

	cl_sounding_stop_handler(cl_hw, elem);
}

static void cl_sounding_handler_send_request(struct work_struct *work)
{
	struct sounding_work_data *data = (struct sounding_work_data *)work;
	struct cl_hw *cl_hw = data->cl_hw;

	if (data->start) {
		cl_sounding_start_handler(cl_hw, data);
	} else {
		struct cl_sta *cl_sta = data->cl_sta_arr[0];
		u8 sid = cl_sta->su_sid;

		cl_sounding_stop_by_sid(cl_hw, sid);
	}

	kfree(data);
}

static u16 cl_sounding_calc_interval(struct cl_hw *cl_hw, u8 active_profiles)
{
	/* Sounding interval = min interval + [(active_profiles - 1) / STA step] * interval step */

	u16 *coefs = cl_hw->conf->ce_sounding_interval_coefs;
	u16 min_interval = coefs[SOUNDING_INTERVAL_COEF_MIN_INTERVAL];
	u16 max_interval = coefs[SOUNDING_INTERVAL_COEF_MAX_INTERVAL];
	u8 sta_step = coefs[SOUNDING_INTERVAL_COEF_STA_STEP];
	u8 interval_step = coefs[SOUNDING_INTERVAL_COEF_INTERVAL_STEP];
	u16 ret = min_interval;

	if (active_profiles <= sta_step)
		return ret;

	active_profiles--;
	ret += (active_profiles / sta_step) * interval_step;

	return min(ret, max_interval);
}

static void cl_sounding_handler_change_interval(struct work_struct *work)
{
	struct sounding_work_data *data = (struct sounding_work_data *)work;
	struct cl_hw *cl_hw = data->cl_hw;
	struct mm_sounding_interval_cfm *sounding_interval_cfm = NULL;
	int ret = 0;
	/* Configure sounding request parameters */
	u16 interval = cl_sounding_get_interval(cl_hw);
	u16 lifetime = cl_sounding_get_lifetime(cl_hw, interval);

	sounding_pr_trace("Sounding interval request: sta_idx=%d, interval=%u, "
			  "lifetime=%u, sounding_type=%u\n",
			  CL_SOUNDING_ALL_STA, interval, lifetime, data->sounding_type);

	/* Start/Stop synchronize sounding request periodically */
	ret = cl_msg_tx_sounding_interval(cl_hw, interval, lifetime, data->sounding_type,
					  CL_SOUNDING_ALL_STA);
	sounding_interval_cfm = (struct mm_sounding_interval_cfm *)
				(cl_hw->msg_cfm_params[MM_SOUNDING_INTERVAL_CFM]);

	if (ret == 0)
		cl_sounding_check_response(cl_hw, sounding_interval_cfm->param_err);
	else
		sounding_pr_err("%s: failed to send message (%d)\n", __func__, ret);

	cl_msg_tx_free_cfm_params(cl_hw, MM_SOUNDING_INTERVAL_CFM);
	kfree(data);
}

static void cl_sounding_recovery_reset(struct cl_hw *cl_hw)
{
	struct cl_sounding_db *sounding_db = &cl_hw->sounding;

	memset(sounding_db->active_profiles_prev, 0, sizeof(u8) * CL_SOUNDING_STABILITY_TIME);
	sounding_db->active_profiles_idx = 0;
}

static int cl_sounding_cli_help(struct cl_hw *cl_hw)
{
	char *ret_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!ret_buf)
		return -ENOMEM;

	snprintf(ret_buf, PAGE_SIZE,
		 "sounding usage\n"
		 "-a: Create a sounding sequence [type].[bw].[gid].[q_matrix_bitmap].[sta_idx 1]"
		 "...[sta_idx n]\n\t* Available types: 0-HE_SU, 1-HE_SU_TB, 2-VHT_SU, 3-HE_CQI, "
		 "4-HE_CQI_TB, 5-HE_MU, 6-VHT_MU\n\t"
		 "* Notice that gid and q_matrix_bitmap should be passed only for MU sounding\n"
		 "-b: Delete a sounding sequence [sounding_id]\n"
		 "-c: Print sounding configuration\n"
		 "-d: Set debug level [0-Off, ..., 4-Highest]\n"
		 "-p: Print sounding db\n");

	err = cl_vendor_reply(cl_hw, ret_buf, strlen(ret_buf));
	kfree(ret_buf);

	return err;
}

static int cl_sounding_cli_create(struct cl_hw *cl_hw,
				  struct cli_params *cli_params)
{
	u8 i;
	u8 max_sta_params = 0;
	u8 curr_param_idx = 0;
	struct sounding_work_data *data = NULL;
	int err = 0;

	/* parameters extraction and validity checks */
	if (cli_params->num_params < 4) {
		sounding_pr_err("Too few parameters..\n");
		return -EIO;
	}

	data = kzalloc(sizeof(*data), GFP_KERNEL);

	if (!data)
		return -ENOMEM;

	data->sounding_type = (u8)cli_params->params[curr_param_idx++];
	data->bw = (u8)cli_params->params[curr_param_idx++];
	data->gid = (u8)cli_params->params[curr_param_idx++];
	data->q_matrix_bitmap = (u8)cli_params->params[curr_param_idx++];

	if (cl_band_is_24g(cl_hw) && SOUNDING_TYPE_IS_VHT(data->sounding_type)) {
		sounding_pr_err("A VHT sounding type (%u) is not supported in 2.4g band\n",
				data->sounding_type);
		err = -EIO;
		goto out_err;
	}

	switch (data->sounding_type) {
	case SOUNDING_TYPE_VHT_SU:
	case SOUNDING_TYPE_HE_CQI:
	case SOUNDING_TYPE_HE_SU:
		max_sta_params = 1;
		break;
	case SOUNDING_TYPE_HE_SU_TB:
	case SOUNDING_TYPE_HE_CQI_TB:
		max_sta_params = CL_MU_OFDMA_MAX_STA_PER_GRP;
		break;
	case SOUNDING_TYPE_VHT_MU:
	case SOUNDING_TYPE_HE_MU:
		sounding_pr_err("MU sounding not supported %u\n", data->sounding_type);
		err = -EIO;
		goto out_err;
	default:
		sounding_pr_err("Invalid sounding type %u\n", data->sounding_type);
		err = -EIO;
		goto out_err;
	}

	if (cli_params->num_params > (curr_param_idx + max_sta_params)) {
		sounding_pr_err("Too many parameters..\n");
		err = -EIO;
		goto out_err;
	}

	/* SU case */
	struct cl_sta *cl_sta;

	if (data->gid || data->q_matrix_bitmap) {
		sounding_pr_err("Please don't insert gid or q_matrix_bitmap != 0 "
				"for SU sounding types (< 5)\n");
		err = -EIO;
		goto out_err;
	}

	if (cli_params->num_params < curr_param_idx + 1) {
		sounding_pr_err("For SU sounding types (< 5) at least 1 STA idx "
				"must be given\n");
		err = -EIO;
		goto out_err;
	}

	/* Fill cl_sta_arr */
	for (i = 0;
	     curr_param_idx < cli_params->num_params; curr_param_idx++, i++) {
		u8 sta_idx = (u8)cli_params->params[curr_param_idx];

		cl_sta_lock_bh(cl_hw);
		cl_sta = cl_sta_get(cl_hw, sta_idx);

		if (!cl_sta) {
			sounding_pr_err("Invalid STA index %u\n", sta_idx);
			cl_sta_unlock_bh(cl_hw);
			err = -EIO;
			goto out_err;
		}

		data->cl_sta_arr[i] = cl_sta;
		cl_sta_unlock_bh(cl_hw);
	}

	data->sta_num = i;

	/* Start the new sounding sequence */
	cl_sounding_start_handler(cl_hw, data);

out_err:
	kfree(data);
	return err;
}

static void cl_sounding_cli_print_configuration(struct cl_hw *cl_hw)
{
	struct cl_tcv_conf *conf = cl_hw->conf;

	pr_debug("Min sounding interval:      %u\n",
		 conf->ce_sounding_interval_coefs[SOUNDING_INTERVAL_COEF_MIN_INTERVAL]);
	pr_debug("Sounding interval STA step: %u\n",
		 conf->ce_sounding_interval_coefs[SOUNDING_INTERVAL_COEF_STA_STEP]);
	pr_debug("Sounding interval step:     %u\n",
		 conf->ce_sounding_interval_coefs[SOUNDING_INTERVAL_COEF_INTERVAL_STEP]);
	pr_debug("Max sounding interval:      %u\n",
		 conf->ce_sounding_interval_coefs[SOUNDING_INTERVAL_COEF_MAX_INTERVAL]);
	pr_debug("Current interval:           %u\n\n", cl_sounding_get_interval(cl_hw));
}

static void cl_sounding_cli_print_sounding_db(struct cl_hw *cl_hw)
{
#define STA_INDICES_STR_LEN 64

	struct cl_sounding_info *elem = NULL;
	char sta_indices_str[STA_INDICES_STR_LEN];
	struct cl_sounding_db *sounding_db = &cl_hw->sounding;
	struct cl_xmem *xmem_db = &cl_hw->chip->xmem_db;

	pr_debug("----------------------------------------------------------------------"
		 "-------------------------------------------------------\n");
	pr_debug("| sid |   type    | bw  | gid | sta num |            sta indices           |"
		 " q matrix bitmap | xmem space | v matrices size |");

	read_lock_bh(&cl_hw->sounding.lock);

	list_for_each_entry(elem, &cl_hw->sounding.head, list) {
		u8 i, len = 0;

		memset(sta_indices_str, '\0', sizeof(sta_indices_str));

		for (i = 0; i < elem->sta_num; i++) {

			len += snprintf(sta_indices_str + len, STA_INDICES_STR_LEN - len,
					"%u%s", elem->su_cl_sta_arr[i]->sta_idx,
					(i == elem->sta_num - 1 ? "" : ","));
		}

		pr_debug("+-----+-----------+-----+-----+---------+"
			 "----------------------------------+-----------------+------------+"
			 "-----------------+\n");
		pr_debug("| %2u  | %-9s | %3u | %2u  |    %1u    | %-32s |       0x%01x       |"
			 "  %6u    |     %6u      |",
			 elem->sounding_id, CL_SOUNDING_TYPE_2_STR(elem->type), BW_TO_MHZ(elem->bw),
			 elem->gid, elem->sta_num, sta_indices_str, elem->q_matrix_bitmap,
			 elem->xmem_space, elem->v_matrices_data_len);
	}

	read_unlock_bh(&cl_hw->sounding.lock);

	pr_debug("-----------------------------------------------------------------------"
		 "------------------------------------------------------\n\n");
	pr_debug("Num of soundings:         %u\n", sounding_db->num_soundings);
	pr_debug("Active non-CQI profiles:  %u\n", sounding_db->active_profiles);
	pr_debug("Active CQI profiles:      %u\n", sounding_db->cqi_profiles);
	pr_debug("Xmem size:                %u\n", xmem_db->size);
	pr_debug("Total xmem used:          %u\n", xmem_db->total_used);
#undef STA_INDICES_STR_LEN
}

static void cl_sounding_change_interval(struct cl_hw *cl_hw, u8 sounding_type)
{
	/* Data will be freed in work handler */
	struct sounding_work_data *data = kzalloc(sizeof(*data), GFP_ATOMIC);

	if (!data)
		return;

	INIT_WORK(&data->work, cl_sounding_handler_change_interval);
	data->cl_hw = cl_hw;
	data->sounding_type = sounding_type;
	queue_work(cl_hw->sounding.sounding_wq, &data->work);
}

static void cl_sounding_indication_pr(struct cl_hw *cl_hw,
				      struct mm_sounding_ind *ind,
				      struct v_matrix_header *v_matrix,
				      u8 *avg_snr)
{
	sounding_pr_info("Sounding indication: nc index = %u, BFR BW = %u, "
		  "SNR1 = %u, SNR2 = %u, SNR3 = %u, SNR4 = %u, SNR5 = %u, SNR6 = %u,"
		  "feedback type = %u, sta index = %u\n",
		  v_matrix->nc_index, v_matrix->bw,
		  avg_snr[0], avg_snr[1], avg_snr[2], avg_snr[3], avg_snr[4],
		  avg_snr[5], ind->sounding_type, ind->sta_idx);
}

static void cl_sounding_indication_su(struct cl_hw *cl_hw,
				      struct mm_sounding_ind *ind,
				      struct cl_sounding_info *sounding_elem)
{
	struct cl_sta *cl_sta;
	struct v_matrix_header *v_matrix = NULL;
	u8 *avg_snr = NULL;
	bool pairing = false;

	v_matrix = sounding_elem->v_matrices_data + ind->v_matrix_offset[0];
	avg_snr = (u8 *)v_matrix + v_matrix->padding;

	cl_sta_lock(cl_hw);
	cl_sta = cl_sta_get(cl_hw, ind->sta_idx);

	if (cl_sta) {
		struct cl_bf_sta_db *bf_db = &cl_sta->bf_db;

		/* Update Nc for the current STA */
		bf_db->nc = v_matrix->nc_index;
		bf_db->sounding_indications++;

		if (bf_db->sounding_indications == 1) {
			/*
			 * After getting first indication disable the timer and set the BF
			 * bit in the firmware rate flags.
			 */
			cl_timer_disable(&bf_db->timer);
			cl_bf_update_rate(cl_hw, cl_sta);
			pairing = true;
		}
	}

	cl_sta_unlock(cl_hw);

	/* Send a msg to fw to pair the STA with sounding ID */
	if (pairing)
		cl_msg_tx_sounding_pairing(cl_hw, ind->sid, ind->sounding_type, 0, ind->sta_idx);

	cl_sounding_indication_pr(cl_hw, ind, v_matrix, avg_snr);
}

void cl_sounding_init(struct cl_hw *cl_hw)
{
	memset(&cl_hw->sounding, 0, sizeof(cl_hw->sounding));
	cl_hw->sounding.sounding_wq = create_workqueue("cl_sounding_wq");
	cl_hw->sounding.current_interval =
		cl_hw->conf->ce_sounding_interval_coefs[SOUNDING_INTERVAL_COEF_MIN_INTERVAL];
	cl_hw->chip->xmem_db.size = XMEM_SIZE;
	INIT_LIST_HEAD(&cl_hw->sounding.head);
	rwlock_init(&cl_hw->sounding.lock);
}

void cl_sounding_close(struct cl_hw *cl_hw)
{
	struct cl_sounding_info *elem, *tmp;

	if (cl_hw->sounding.sounding_wq)
		destroy_workqueue(cl_hw->sounding.sounding_wq);

	list_for_each_entry_safe(elem, tmp, &cl_hw->sounding.head, list)
		cl_sounding_stop_handler(cl_hw, elem);
}

void cl_sounding_send_request(struct cl_hw *cl_hw, struct cl_sta **cl_sta_arr,
			      u8 sta_num, bool enable, u8 sounding_type, u8 bw,
			      u8 q_matrix_bitmap, struct cl_sounding_info *recovery_elem)
{
	struct sounding_work_data *data;
	u8 i;

	if (!cl_sta_arr) {
		sounding_pr_err("Sta_indices is NULL! for sounding type %u\n", sounding_type);
		return;
	}

	if (cl_band_is_24g(cl_hw) && SOUNDING_TYPE_IS_VHT(sounding_type)) {
		sounding_pr_err("A VHT sounding type (%u) is not supported in 2.4g band\n",
				sounding_type);
		return;
	}

	/* data will be freed in work handler */
	data = kzalloc(sizeof(*data), GFP_ATOMIC);

	if (data) {
		INIT_WORK(&data->work, cl_sounding_handler_send_request);
		data->cl_hw = cl_hw;
		data->start = enable;
		data->sounding_type = sounding_type;
		data->bw = bw;
		data->is_recovery = cl_recovery_in_progress(cl_hw);
		data->recovery_elem = recovery_elem;

		/* Fill cl_sta_arr */
		for (i = 0; i < sta_num; i++)
			data->cl_sta_arr[i] = cl_sta_arr[i];

		data->sta_num = sta_num;

		queue_work(cl_hw->sounding.sounding_wq, &data->work);
	} else {
		sounding_pr_err("kzalloc failed\n");
	}
}

void cl_sounding_maintenance(struct cl_hw *cl_hw)
{
	/*
	 * Change sounding_index accoording to number of active_profiles.
	 * sounding_index is modified only if number of active_profiles is stable for 5 seconds.
	 *
	 * Examples:
	 * e.g #1: active_profiles=2, active_profiles_prev=3,3,3,3,3 - stabilised on 3
	 * e.g #3: active_profiles=2, active_profiles_prev=1,1,1,1,1 - stabilised on 1
	 * e.g #2: active_profiles=5, active_profiles_prev=6,7,7,6,6 - stabilised on 6
	 * e.g #4: active_profiles=5, active_profiles_prev=4,3,3,2,4 - stabilised on 4
	 */

	int i = 0;
	u8 active_profiles_min = 255;
	u8 active_profiles_max = 0;
	u8 active_profiles = cl_hw->sounding.last_conf_active_profiles;
	u8 active_profiles_new = 0;
	u16 interval;
	u16 interval_new;

	/* Add to last 5 sec buffer */
	cl_hw->sounding.active_profiles_prev[cl_hw->sounding.active_profiles_idx] =
		cl_hw->sounding.active_profiles;

	/* Increase cyclic index */
	cl_hw->sounding.active_profiles_idx++;
	if (cl_hw->sounding.active_profiles_idx == CL_SOUNDING_STABILITY_TIME)
		cl_hw->sounding.active_profiles_idx = 0;

	/* Find active_profiles min/max in last 5 seconds */
	for (i = 0; i < CL_SOUNDING_STABILITY_TIME; i++) {
		if (cl_hw->sounding.active_profiles_prev[i] < active_profiles_min)
			active_profiles_min = cl_hw->sounding.active_profiles_prev[i];

		if (cl_hw->sounding.active_profiles_prev[i] > active_profiles_max)
			active_profiles_max = cl_hw->sounding.active_profiles_prev[i];
	}

	if (active_profiles < active_profiles_min)
		active_profiles_new = active_profiles_min;
	else if (active_profiles > active_profiles_max)
		active_profiles_new = active_profiles_max;
	else /* Active_profiles in last 5 seconds did not change or is not stable */
		return;

	interval = cl_sounding_calc_interval(cl_hw, active_profiles);
	interval_new = cl_sounding_calc_interval(cl_hw, active_profiles_new);

	/* Check if sounding interval changed */
	if (interval != interval_new) {
		cl_hw->sounding.last_conf_active_profiles = active_profiles_new;
		cl_hw->sounding.current_interval = interval_new;
		cl_sounding_change_interval(cl_hw, SOUNDING_TYPE_MAX);
		sounding_pr_trace("Interval: current = %u, new = %u\n",
				  interval, interval_new);
	}
}

u16 cl_sounding_get_interval(struct cl_hw *cl_hw)
{
	return cl_hw->sounding.current_interval;
}

void cl_sounding_indication(struct cl_hw *cl_hw, struct mm_sounding_ind *ind)
{
	struct cl_sounding_info *sounding_elem = NULL;

	sounding_elem = cl_sounding_get_elem(cl_hw, ind->sid);

	if (!sounding_elem) {
		sounding_pr_err("[%s]: sounding id %u not found!\n", __func__, ind->sid);
		return;
	}

	switch (ind->sounding_type) {
	case SOUNDING_TYPE_HE_SU:
	case SOUNDING_TYPE_HE_SU_TB:
	case SOUNDING_TYPE_VHT_SU:
	case SOUNDING_TYPE_HE_CQI:
	case SOUNDING_TYPE_HE_CQI_TB:
		cl_sounding_indication_su(cl_hw, ind, sounding_elem);
		break;
	case SOUNDING_TYPE_HE_MU:
	case SOUNDING_TYPE_VHT_MU:
		sounding_pr_err("[%s]: MU sounding not supported %u\n", __func__,
				ind->sounding_type);
		return;
	default:
		sounding_pr_err("[%s]: Invalid sounding type %u\n", __func__,
				ind->sounding_type);
		return;
	}
}

void cl_sounding_recovery(struct cl_hw *cl_hw)
{
	/*
	 * After recovery process we need to update sounding requests and
	 * sounding interval in firmware
	 */
	struct cl_sounding_info *elem;

	/* No sounding is active */
	if (!cl_hw->sounding.num_soundings)
		return;

	/* Reset sounding parameters */
	cl_sounding_recovery_reset(cl_hw);

	/*
	 * Go over all clients that had sounding before recovery,
	 * and send a new sounding request to firmware.
	 */

	list_for_each_entry(elem, &cl_hw->sounding.head, list)
		cl_bf_sounding_start(cl_hw, elem->type, elem->su_cl_sta_arr, elem->sta_num, elem);
}

int cl_sounding_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool create_sounding = false;
	bool delete_sounding = false;
	bool print_conf = false;
	bool set_debug_level = false;
	bool print_sounding_db = false;

	switch (cli_params->option) {
	case 'a':
		create_sounding = true;
		goto skip_exp_params_check;
	case 'b':
		delete_sounding = true;
		expected_params = 1;
		break;
	case 'c':
		print_conf = true;
		expected_params = 0;
		break;
	case 'd':
		set_debug_level = true;
		expected_params = 1;
		break;
	case 'p':
		print_sounding_db = true;
		expected_params = 0;
		break;
	case '?':
		return cl_sounding_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option (%c) - try '?' for help\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw, "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

skip_exp_params_check:
	if (create_sounding) {
		cl_sounding_cli_create(cl_hw, cli_params);
	} else if (delete_sounding) {
		u8 sid = (u8)cli_params->params[0];

		cl_sounding_stop_by_sid(cl_hw, sid);
	} else if (print_conf) {
		cl_sounding_cli_print_configuration(cl_hw);
	} else if (set_debug_level) {
		u8 dbg_level = (u8)cli_params->params[0];

		cl_hw->sounding.dbg_level = dbg_level;
	} else if (print_sounding_db) {
		cl_sounding_cli_print_sounding_db(cl_hw);
	}

	return 0;
out_err:
	return -EIO;
}
