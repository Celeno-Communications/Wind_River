// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_ul_length.h"
#include "cl_tf.h"
#include "cl_data_rates.h"
#include "cl_sta.h"
#include "cl_wrs.h"

struct cl_ul_length {
	u16 user[CL_TF_STA_MAX];
};

static struct cl_ul_length
	inverse_data_rate_ul[CHNL_BW_MAX][WRS_SS_MAX][WRS_MCS_MAX_HE][WRS_GI_MAX_HE];
/*
 * NSS=1, GI=1.6
 * HE & LTF symbols=8
 * GI=1.6
 * HE_LTF=1
 * SYM=14.4
 * PE_DURATION=16
 * T_HE_PREAMBLE=28
 * PE_DISAMBIGUITY=1
 */
static const u16 ul_len_sgi_1_nss[UL_LEN_TABLE_ROWS] = {
	82, 106, 127, 148, 181, 202, 223, 244, 268, 298,
	322, 343, 364, 397, 418, 439, 460, 484, 514, 538,
	559, 580, 613, 634, 655, 676, 700, 730, 754, 775,
	796, 829, 850, 871, 892, 916, 946, 970, 991, 1012,
	1045, 1066, 1087, 1108, 1132, 1162, 1186, 1207, 1228, 1261,
	1282, 1303, 1324, 1348, 1378, 1402, 1423, 1444, 1477, 1498,
	1519, 1540, 1564, 1594, 1618, 1639, 1660, 1693, 1714, 1735,
	1756, 1780, 1810, 1834, 1855, 1876, 1909, 1930, 1951, 1972,
	1996, 2026, 2050, 2071, 2092, 2125, 2146, 2167, 2188, 2212,
	2242, 2266, 2287, 2308, 2341, 2362, 2383, 2404, 2428, 2458,
	2482, 2503, 2524, 2557, 2578, 2599, 2620, 2644, 2674, 2698,
	2719, 2740, 2773, 2794, 2815, 2836, 2860, 2890, 2914, 2935,
	2956, 2989, 3010, 3031, 3052, 3076, 3106, 3130, 3151, 3172,
	3205, 3226, 3247, 3268, 3292, 3322, 3346, 3367, 3388, 3421,
	3442, 3463, 3484, 3508, 3538, 3562, 3583, 3604, 3637, 3658,
	3679, 3700, 3724, 3754, 3778, 3799, 3820, 3853, 3874, 3895,
	3916, 3940, 3970, 3994, 4015, 4036, 4069
};

/*
 * NSS=2, GI=1.6
 * HE & LTF symbols=8
 * GI=1.6
 * HE_LTF=2
 * SYM=14.4
 * PE_DURATION=16
 * T_HE_PREAMBLE=36
 * PE_DISAMBIGUITY=1
 */
static const u16 ul_len_sgi_2_nss[UL_LEN_TABLE_ROWS] = {
	88, 112, 133, 154, 187, 208, 229, 250, 274, 304,
	328, 349, 370, 403, 424, 445, 466, 490, 520, 544,
	565, 586, 619, 640, 661, 682, 706, 736, 760, 781,
	802, 835, 856, 877, 898, 922, 952, 976, 997, 1018,
	1051, 1072, 1093, 1114, 1138, 1168, 1192, 1213, 1234, 1267,
	1288, 1309, 1330, 1354, 1384, 1408, 1429, 1450, 1483, 1504,
	1525, 1546, 1570, 1600, 1624, 1645, 1666, 1699, 1720, 1741,
	1762, 1786, 1816, 1840, 1861, 1882, 1915, 1936, 1957, 1978,
	2002, 2032, 2056, 2077, 2098, 2131, 2152, 2173, 2194, 2218,
	2248, 2272, 2293, 2314, 2347, 2368, 2389, 2410, 2434, 2464,
	2488, 2509, 2530, 2563, 2584, 2605, 2626, 2650, 2680, 2704,
	2725, 2746, 2779, 2800, 2821, 2842, 2866, 2896, 2920, 2941,
	2962, 2995, 3016, 3037, 3058, 3082, 3112, 3136, 3157, 3178,
	3211, 3232, 3253, 3274, 3298, 3328, 3352, 3373, 3394, 3427,
	3448, 3469, 3490, 3514, 3544, 3568, 3589, 3610, 3643, 3664,
	3685, 3706, 3730, 3760, 3784, 3805, 3826, 3859, 3880, 3901,
	3922, 3946, 3976, 4000, 4021, 4042, 4075
};

/*
 * NSS=1, GI=3.2
 * HE & LTF symbols=16
 * GI=3.2
 * HE_LTF=1
 * SYM=16
 * PE_DURATION=16
 * T_HE_PREAMBLE=36
 * PE_DISAMBIGUITY=1
 */
static const u16 ul_len_lgi_1_nss[UL_LEN_TABLE_ROWS] = {
	82, 106, 130, 154, 178, 202, 226, 250, 274, 298,
	322, 346, 370, 394, 418, 442, 466, 490, 514, 538,
	562, 586, 610, 634, 658, 682, 706, 730, 754, 778,
	802, 826, 850, 874, 898, 922, 946, 970, 994, 1018,
	1042, 1066, 1090, 1114, 1138, 1162, 1186, 1210, 1234, 1258,
	1282, 1306, 1330, 1354, 1378, 1402, 1426, 1450, 1474, 1498,
	1522, 1546, 1570, 1594, 1618, 1642, 1666, 1690, 1714, 1738,
	1762, 1786, 1810, 1834, 1858, 1882, 1906, 1930, 1954, 1978,
	2002, 2026, 2050, 2074, 2098, 2122, 2146, 2170, 2194, 2218,
	2242, 2266, 2290, 2314, 2338, 2362, 2386, 2410, 2434, 2458,
	2482, 2506, 2530, 2554, 2578, 2602, 2626, 2650, 2674, 2698,
	2722, 2746, 2770, 2794, 2818, 2842, 2866, 2890, 2914, 2938,
	2962, 2986, 3010, 3034, 3058, 3082, 3106, 3130, 3154, 3178,
	3202, 3226, 3250, 3274, 3298, 3322, 3346, 3370, 3394, 3418,
	3442, 3466, 3490, 3514, 3538, 3562, 3586, 3610, 3634, 3658,
	3682, 3706, 3730, 3754, 3778, 3802, 3826, 3850, 3874, 3898,
	3922, 3946, 3970, 3994, 4018, 4042, 4066
};

/*
 * NSS=2, GI=3.2
 * HE & LTF symbols=16
 * GI=3.2
 * HE_LTF=2
 * SYM=16
 * PE_DURATION=16
 * T_HE_PREAMBLE=52
 * PE_DISAMBIGUITY=1
 */
static const u16 ul_len_lgi_2_nss[UL_LEN_TABLE_ROWS] = {
	109, 133, 157, 181, 205, 229, 253, 277, 301, 325,
	349, 373, 397, 421, 445, 469, 493, 517, 541, 565,
	589, 613, 637, 661, 685, 709, 733, 757, 781, 805,
	829, 853, 877, 901, 925, 949, 973, 997, 1021, 1045,
	1069, 1093, 1117, 1141, 1165, 1189, 1213, 1237, 1261, 1285,
	1309, 1333, 1357, 1381, 1405, 1429, 1453, 1477, 1501, 1525,
	1549, 1573, 1597, 1621, 1645, 1669, 1693, 1717, 1741, 1765,
	1789, 1813, 1837, 1861, 1885, 1909, 1933, 1957, 1981, 2005,
	2029, 2053, 2077, 2101, 2125, 2149, 2173, 2197, 2221, 2245,
	2269, 2293, 2317, 2341, 2365, 2389, 2413, 2437, 2461, 2485,
	2509, 2533, 2557, 2581, 2605, 2629, 2653, 2677, 2701, 2725,
	2749, 2773, 2797, 2821, 2845, 2869, 2893, 2917, 2941, 2965,
	2989, 3013, 3037, 3061, 3085, 3109, 3133, 3157, 3181, 3205,
	3229, 3253, 3277, 3301, 3325, 3349, 3373, 3397, 3421, 3445,
	3469, 3493, 3517, 3541, 3565, 3589, 3613, 3637, 3661, 3685,
	3709, 3733, 3757, 3781, 3805, 3829, 3853, 3877, 3901, 3925,
	3949, 3973, 3997, 4021, 4045, 4069, 4093
};

u16 cl_ul_length_get(u8 idx, u8 nss, u8 gi_ltf)
{
	if (gi_ltf == HE_LTF_X4_GI_32) {
		switch (nss) {
		case WRS_SS_1:
			return ul_len_lgi_1_nss[idx];
		case WRS_SS_2:
			return ul_len_lgi_2_nss[idx];
		default:
			return 0;
		}
	} else {
		switch (nss) {
		case WRS_SS_1:
			return ul_len_sgi_1_nss[idx];
		case WRS_SS_2:
			return ul_len_sgi_2_nss[idx];
		default:
			return 0;
		}
	}
}

u16 cl_ul_length_get_duration(u32 bytes, u8 bw, u8 nss, u8 mcs, u8 gi)
{
	return (bytes * inverse_data_rate_ul[bw][nss][mcs][gi].user[0]) >> DATA_RATE_INVERSE_Q;
}

static void cl_ul_length_table_calc(u8 bw, u8 nss, u8 mcs, u8 gi, u8 up)
{
	inverse_data_rate_ul[bw][nss][mcs][gi].user[up] =
		inverse_data_rate.he[bw][nss][mcs][gi] / (up + 1);
}

void cl_ul_length_table_init(void)
{
	u8 nss, bw, mcs, gi;

	for (bw = 0; bw < CHNL_BW_MAX; bw++)
		for (nss = 0; nss < WRS_SS_MAX; nss++)
			for (mcs = 0; mcs < WRS_MCS_MAX_HE; mcs++)
				for (gi = 0; gi < WRS_GI_MAX_HE; gi++)
					cl_ul_length_table_calc(bw, nss, mcs, gi, 0);
}

void cl_ul_length_set_manual(struct cl_hw *cl_hw, u8 sta_idx, u8 ac, u32 bytes)
{
	struct cl_wrs_rate_params *rate_params = NULL;
	struct cl_sta *cl_sta = NULL;
	u16 duration, ul_length;

	if (ac >= AC_MAX) {
		pr_debug("Invalid AC %u\n", ac);
		return;
	}

	cl_sta_lock_bh(cl_hw);
	cl_sta = cl_sta_get(cl_hw, sta_idx);

	if (!cl_sta) {
		pr_debug("Invalid STA %u\n", sta_idx);
		goto out;
	}

	rate_params = cl_wrs_rx_rate_get(cl_sta);

	if (!rate_params) {
		pr_debug("UL prarams is null\n");
		goto out;
	}

	duration = cl_ul_length_get_duration(bytes, rate_params->bw,
					     rate_params->nss,
					     rate_params->mcs, rate_params->gi);
	duration >>= UL_LEN_IDX_FACTOR;
	if (duration > UL_LEN_MAX_IDX)
		duration = UL_LEN_MAX_IDX;

	ul_length = cl_ul_length_get(duration, rate_params->nss, rate_params->gi);
	cl_hw->tf_info.data->tf_sta_data[ac][sta_idx].ul_length[0] = ul_length;
	pr_debug("STA %u, ul_length %u\n", sta_idx, ul_length);

out:
	cl_sta_unlock_bh(cl_hw);
}
