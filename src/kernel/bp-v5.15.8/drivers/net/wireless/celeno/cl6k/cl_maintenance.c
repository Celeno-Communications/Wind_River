// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_maintenance.h"
#include "cl_traffic.h"
#include "cl_age_out.h"
#include "cl_rx_sens.h"
#include "cl_vns.h"
#include "cl_env_det.h"
#include "cl_sounding.h"
#include "cl_sta.h"
#include "cl_traffic_mon.h"
#include "cl_cca.h"
#include "cl_noise.h"
#include "cl_ul_rssi.h"

static void cl_maintenance_callback_slow(struct work_struct *work)
{
	struct cl_hw *cl_hw = container_of(work, struct cl_hw,
					   maintenance_slow.work);

	cl_cca_maintenance(cl_hw);
	cl_noise_maintenance(cl_hw);

	if (cl_hw->chip->conf->ce_production_mode ||
	    cl_hw->chip->conf->ci_twin_peak_mode)
		goto out;

	cl_env_det_maintenance(cl_hw);
	cl_rx_sens_maintenance(cl_hw);
	cl_vns_maintenance(cl_hw);

	if (cl_hw->conf->ci_traffic_mon_en)
		cl_sta_loop(cl_hw, cl_traffic_mon_sta_maintenance);

	if (cl_sta_num(cl_hw) == 0)
		goto out;

	cl_age_out_maintenance(cl_hw);
	cl_sounding_maintenance(cl_hw);
	cl_ul_rssi_sta_maintenance(cl_hw);

out:
	schedule_delayed_work(&cl_hw->maintenance_slow,
			      msecs_to_jiffies(CL_MAINTENANCE_PERIOD_SLOW_MS));
}

static void cl_maintenance_callback_fast(struct work_struct *work)
{
	struct cl_hw *cl_hw = container_of(work, struct cl_hw,
					   maintenance_fast.work);

	if (cl_sta_num(cl_hw) == 0)
		goto out;

	cl_traffic_maintenance(cl_hw);
out:
	schedule_delayed_work(&cl_hw->maintenance_fast,
			      msecs_to_jiffies(CL_MAINTENANCE_PERIOD_FAST_MS));
}

void cl_maintenance_init(struct cl_hw *cl_hw)
{
	INIT_DELAYED_WORK(&cl_hw->maintenance_slow,
			  cl_maintenance_callback_slow);

	INIT_DELAYED_WORK(&cl_hw->maintenance_fast,
			  cl_maintenance_callback_fast);

	cl_maintenance_start(cl_hw);
}

void cl_maintenance_deinit(struct cl_hw *cl_hw)
{
	cancel_delayed_work_sync(&cl_hw->maintenance_slow);
	cancel_delayed_work_sync(&cl_hw->maintenance_fast);
}

void cl_maintenance_start(struct cl_hw *cl_hw)
{
	schedule_work(&cl_hw->maintenance_slow.work);

	if (!cl_hw->chip->conf->ce_production_mode &&
	    !cl_hw->chip->conf->ci_twin_peak_mode)
		schedule_work(&cl_hw->maintenance_fast.work);
}
