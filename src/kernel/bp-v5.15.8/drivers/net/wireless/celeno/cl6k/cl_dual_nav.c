// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_dual_nav.h"
#include "reg_mac_hw.h"
#include "cl_utils.h"
#include "cl_tx.h"
#include "cl_mac_addr.h"
#include "cl_tx_inject.h"
#include "cl_tx_queue.h"
#include "cl_msg_tx.h"

static u8 fake_dest_mac[] = { 0x00, 0x11, 0x11, 0x11, 0x11, 0x11 };

static int cl_dual_nav_cli_help(struct cl_hw *cl_hw)
{
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;

	if (!buf)
		return -ENOMEM;

	snprintf(buf, PAGE_SIZE,
		 "dual_nav usage:\n"
		 "-a : Set NAV duration upon Tx [usec]\n"
		 "-b : Enable/Disable ignore rule bits [0/1]\n"
		 "-c : Enable/Disable NAV clear upon Tx [0/1]\n"
		 "-d : Read nav duration\n"
		 "-e : Enable/Disable single TX inject "
			"[En/Dis][size][delay msec]\n"
		 "-f : busy read every 4 msec [# prints]\n"
		 "-g : set NAV Limit [usec]\n");

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_dual_nav_set_duration(struct cl_hw *cl_hw, u32 duration)
{
	int ret = 0;
	u32 test_params[TEST_MODE_PARAM_MAX + 1] = {0};

	test_params[0] = DBG_TEST_MODE_SET_NAV_DURATION;
	test_params[1] = duration;

	ret = cl_msg_tx_dbg_test_mode(cl_hw, test_params);
	if (ret)
		cl_dbg_err(cl_hw, "cl_send_dbg_test_mode failed\n");

	return ret;
}

static int cl_dual_nav_set_ignore_rule(struct cl_hw *cl_hw, bool enable)
{
	struct cl_chip *chip = cl_hw->chip;

	mac_hw_dual_nav_config_ignore_classify_inter_rule_1_setf(chip, enable);
	mac_hw_dual_nav_config_ignore_classify_inter_rule_2_setf(chip, enable);
	mac_hw_dual_nav_config_ignore_classify_inter_rule_3_setf(chip, enable);
	mac_hw_dual_nav_config_ignore_classify_inter_rule_4_setf(chip, enable);
	mac_hw_dual_nav_config_ignore_classify_inter_rule_5_setf(chip, enable);
	mac_hw_dual_nav_config_ignore_classify_inter_rule_6_setf(chip, enable);

	return 0;
}

static int cl_dual_nav_set_nav_clear(struct cl_hw *cl_hw, bool enable)
{
	int ret = 0;
	u32 test_params[TEST_MODE_PARAM_MAX + 1] = {0};

	test_params[0] = DBG_TEST_MODE_SET_NAV_CLEAR;
	test_params[1] = enable;

	ret = cl_msg_tx_dbg_test_mode(cl_hw, test_params);
	if (ret)
		cl_dbg_err(cl_hw, "cl_send_dbg_test_mode failed\n");

	return ret;
}

static int cl_dual_nav_read_nav_dur(struct cl_hw *cl_hw)
{
	char reply_str[10] = {0};

	snprintf(&reply_str[0], sizeof(reply_str), "%x",
		 mac_hw_nav_value_nav_counter_getf(cl_hw->chip));

	return cl_vendor_reply(cl_hw, reply_str, sizeof(reply_str));
}

static void cl_dual_nav_send_fake_tx_timer(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct sk_buff *skb = NULL;
	struct cl_tx_inject *tx_inject = &cl_hw->tx_inject;
	struct ieee80211_qos_hdr *qos_hdr = NULL;

	if (atomic_read(&tx_inject->alloc_counter) == TX_INJECT_MAX_SKBS)
		return;

	if (cl_txq_single_is_full(cl_hw, HIGH_PRIORITY_QUEUE)) {
		cl_dbg_err(cl_hw, "HIGH_PRIORITY_QUEUE full\n");
		return;
	}

	skb = cl_tx_inject_alloc_skb(cl_hw, NULL, false);
	if (!skb)
		return;

	qos_hdr = (struct ieee80211_qos_hdr *)skb->data;
	cl_mac_addr_copy(qos_hdr->addr1, fake_dest_mac);
	cl_tx_single(cl_hw, NULL, skb, false, true);
}

static int cl_dual_nav_send_fake_tx(struct cl_hw *cl_hw, bool enable, u32 size,
				    u32 delay)
{
	if (enable && !cl_hw->dual_nav_timer.enable) {
		cl_timer_init(&cl_hw->dual_nav_timer,
			      cl_dual_nav_send_fake_tx_timer,
			      (unsigned long)cl_hw, delay, true);

		cl_hw->tx_inject.packet_len = size;
		cl_dbg_verbose(cl_hw, "timer enabled\n");
		cl_timer_enable(&cl_hw->dual_nav_timer);
	} else {
		cl_timer_disable(&cl_hw->dual_nav_timer);
		cl_dbg_verbose(cl_hw, "timer disabled\n");
	}

	return 0;
}

#define TO_PERCENT(val, interval) (100 * (val) / (interval))
static int cl_dual_nav_read_busy(struct cl_hw *cl_hw, u32 print_num)
{
	struct cl_chip *chip = cl_hw->chip;
	int i = 0;
	u32 diff_nav_busy = 0;
	u32 diff_edca_busy = 0;
	char *buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
	int err = 0;
	int len = 0;

	if (!buf)
		return -ENOMEM;

	while (i < print_num) {
		u32 nav_busy = mac_hw_edca_nav_busy_get(chip);
		u32 edca_busy = mac_hw_edca_cca_busy_get(chip);

		usleep_range(3900, 4100);
		diff_nav_busy = mac_hw_edca_nav_busy_get(chip) - nav_busy;
		diff_edca_busy = mac_hw_edca_cca_busy_get(chip) - edca_busy;
		len += snprintf(buf + len, PAGE_SIZE - len,
				"diff_nav_busy=%u (%u%%), diff_edca_busy=%u (%u%%)\n",
				diff_nav_busy, TO_PERCENT(diff_nav_busy, 4000),
				diff_edca_busy, TO_PERCENT(diff_edca_busy, 4000));
		i++;
	}

	err = cl_vendor_reply(cl_hw, buf, strlen(buf));
	kfree(buf);

	return err;
}

static int cl_dual_nav_set_nav_limit(struct cl_hw *cl_hw, u32 nav_limit)
{
	mac_hw_nav_limit_set(cl_hw->chip, nav_limit);
	return 0;
}

int cl_dual_nav_cli(struct cl_hw *cl_hw, struct cli_params *cli_params)
{
	u32 expected_params = 0;
	bool long_nav = false;
	bool ignore_rule = false;
	bool nav_clear = false;
	bool read_nav_dur = false;
	bool send_fake_tx = false;
	bool read_busy = false;
	bool nav_limit = false;

	switch (cli_params->option) {
	case 'a':
		long_nav = true;
		expected_params = 1;
		break;
	case 'b':
		ignore_rule = true;
		expected_params = 1;
		break;
	case 'c':
		nav_clear = true;
		expected_params = 1;
		break;
	case 'd':
		read_nav_dur = true;
		expected_params = 0;
		break;
	case 'e':
		send_fake_tx = true;
		expected_params = 3;
		break;
	case 'f':
		read_busy = true;
		expected_params = 1;
		break;
	case 'g':
		nav_limit = true;
		expected_params = 1;
		break;
	case '?':
		return cl_dual_nav_cli_help(cl_hw);
	default:
		cl_dbg_err(cl_hw, "Illegal option %c\n", cli_params->option);
		goto out_err;
	}

	if (expected_params != cli_params->num_params) {
		cl_dbg_err(cl_hw,
			   "Wrong number of arguments (expected %u) (actual %u)\n",
			   expected_params, cli_params->num_params);
		goto out_err;
	}

	if (long_nav)
		return cl_dual_nav_set_duration(cl_hw, cli_params->params[0]);

	if (ignore_rule)
		return cl_dual_nav_set_ignore_rule(cl_hw, !!cli_params->params[0]);

	if (nav_clear)
		return cl_dual_nav_set_nav_clear(cl_hw, !!cli_params->params[0]);

	if (read_nav_dur)
		return cl_dual_nav_read_nav_dur(cl_hw);

	if (send_fake_tx)
		return cl_dual_nav_send_fake_tx(cl_hw, !!cli_params->params[0],
						cli_params->params[1],
						cli_params->params[2]);

	if (read_busy)
		return cl_dual_nav_read_busy(cl_hw, cli_params->params[0]);

	if (nav_limit)
		return cl_dual_nav_set_nav_limit(cl_hw, cli_params->params[0]);

out_err:
	return -EIO;
}
