// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "chip.h"
#include "cl_msg_pci.h"
#include "cl_msg_rx.h"
#include "cl_recovery.h"
#include "cl_ipc.h"
#include "cl_prof.h"
#include "cl_fw_msg.h"
#include "cl_hw_assert.h"
#include "reg_ipc.h"
#include "cl_msg_cfm.h"
#ifdef TRACE_SUPPORT
#include "cl_trace.h"
#endif

static void cl_msg_pci_fw_push(struct cl_hw *cl_hw, void *msg_buf, u16 len)
{
	/* Send a message to the embedded side */
	int i;
	u32 *src;
	struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
	void __iomem *dst = (void __iomem *)&ipc_env->shared->a2e_msg_buf;

	PROF_REG_SW_SET(cl_hw, SW_PROF_IPC_MSG_PUSH);

	/* Copy the message into the IPC MSG buffer */
	src = (u32 *)msg_buf;

	/*
	 * Move the destination pointer forward by one word
	 * (due to the format of the firmware kernel messages)
	 */
	dst += sizeof(u32);

	/* Align length of message to 4 */
	len = ALIGN(len, sizeof(u32));

	/* Copy the message in the IPC queue */
	for (i = 0; i < len; i += sizeof(u32), dst += sizeof(u32))
		iowrite32(*src++, dst);

	/* Trigger the irq to send the message to EMB */
	cl_hw->ipc_host2xmac_trigger_set(cl_hw->chip, IPC_IRQ_A2E_MSG);

	PROF_REG_SW_CLR(cl_hw, SW_PROF_IPC_MSG_PUSH);
}

/*
 * Launch an async. usermode helper for various debug purposes.
 * Not waiting for completion.
 * The script must be in /var/run/cl_umh_dbg.sh (can be a symlink)
 * @param str_id  Short string to identify the reason, passed to the usermode prog. as 1st param.
 */
static void run_debug_um_helper_async(struct cl_hw *cl_hw, char const *str_id)
{
	/*
	 * Everything is static here, otherwise does not work in atomic context.
	 * The driver supports only one device instance anyway.
	 * Creating environment and path for the umh is too much work
	 * (allocate static buffer, copy cl_install_dir multiple times...)
	 * Let the user set up all the environment. I'm too lazy.
	 */

	char *envp[1] = {NULL};
	char param[16];
	char *argv[3] = { "/var/run/cl_umh_dbg.sh", param, NULL };
	int ret;

	strncpy(param, str_id, sizeof(param) - 1);
	param[sizeof(param) - 1] = 0;
	ret = call_usermodehelper(argv[0], argv, envp, UMH_NO_WAIT);
	/*
	 * Note: even if ret = 0 it does not mean the program has been started.
	 * But if ret !=0 something was wrong for sure.
	 */
	cl_dbg_verbose(cl_hw, "Run async umh: %s (%s) sts=%d\n", argv[0], param, ret);
}

void cl_msg_pci_copy_to_host(struct cl_hw *cl_hw,
			     struct cl_ipc_host_env *ipc_env)
{
	struct cl_e2a_msg_elem *msg_elem = NULL;
	struct cl_ipc_e2a_msg *msg = NULL;
	struct cl_rx_msg *rx_msg = NULL;
	u8 idx;

	while (1) {
		idx = ipc_env->e2a_msg_host_idx;
		msg_elem = (struct cl_e2a_msg_elem *)(ipc_env->e2a_msg_hostbuf_array[idx].hostid);
		msg = msg_elem->msgbuf_ptr;

		/* Look for pattern which means that this hostbuf has been used for a MSG */
		if (le32_to_cpu(msg->pattern) != IPC_E2A_MSG_VALID_PATTERN)
			break;

		/* Copy msg to local list in host */
		rx_msg = kzalloc(sizeof(*rx_msg), GFP_ATOMIC);

		if (!rx_msg)
			goto msg_push;

		memcpy(&rx_msg->buf, msg, sizeof(struct cl_ipc_e2a_msg));
		list_add_tail(&rx_msg->list, &cl_hw->rx_msg_head);

msg_push:
		/* Reset the msg element and re-use it */
		msg->pattern = 0;

		/* make sure memory is written before push to HW */
		wmb();

		/* Push back the buffer */
		cl_ipc_msgbuf_push(ipc_env, (ptrdiff_t)msg_elem, msg_elem->dma_addr);
	}
}

int cl_msg_pci_cfm_wait(struct cl_hw *cl_hw, u16 bit, u16 req_id)
{
	/*
	 * Start a timeout to stop on the main waiting queue,
	 * and then check the result.
	 */
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_pci *chip_pci = cl_chip_pci_priv(chip);
	int timeout = 0, error = 0;
	int max_timeout = 0;

	if (IS_REAL_PHY(chip)) {
		max_timeout = CL_MSG_CFM_TIMEOUT_JIFFIES;
	} else if (chip->conf->ci_phy_dev == PHY_DEV_FRU) {
		max_timeout = CL_MSG_CFM_TIMEOUT_FRU_JIFFIES;
	} else {
		max_timeout = CL_MSG_CFM_TIMEOUT_DUMMY_JIFFIES;
	}

	if (req_id == MM_SET_CALIB_REQ && cl_hw->calib_params.is_matlab) {
		max_timeout = CL_MSG_CFM_TIMEOUT_CALIB_JIFFIES;
		mutex_unlock(&cl_hw->msg_tx_mutex);
	}

	/* Wait for confirmation message */
	PROF_REG_SW_SET(cl_hw, SW_PROF_WAIT_QUEUE);
	timeout = wait_event_timeout(cl_hw->wait_queue,
				     !CFM_TEST_BIT(bit, &cl_hw->cfm_flags),
				     max_timeout);
	PROF_REG_SW_CLR(cl_hw, SW_PROF_WAIT_QUEUE);

	if (timeout == 0) {
		/*
		* Timeout occurred!
		* Make sure that confirmation wasn't received after the timeout.
		*/
		if (CFM_TEST_BIT(bit, &cl_hw->cfm_flags)) {
			cl_dbg_verbose(cl_hw, "[WARN] Timeout occurred - %s\n",
				MSG_ID_STR(req_id));
			error = -ETIMEDOUT;
		}
	}

	if (error) {
		struct cl_irq_stats *irq_stats = &chip->irq_stats;
		struct cl_ipc_host_env *ipc_env = cl_hw->ipc_env;
		unsigned long now = jiffies, flags;
		u32 status, raw_status;

#ifdef TRACE_SUPPORT
		stop_lttng_trace(cl_hw);
#endif

		/*
		 * The interrupt was not handled in time, lets try to handle it safely.
		 * The spin lock protects us from the following race scenarios:
		 * 1) atomic read of the IPC status register,
		 * 2) execution on the msg handler twice from different context.
		 * 3) disable context switch from the same core.
		 */
		spin_lock_irqsave(&chip_pci->isr_lock, flags);

		status = ipc_xmac_2_host_status_get(chip);
		raw_status = ipc_xmac_2_host_raw_status_get(chip);

		cl_dbg_verbose(cl_hw,
			       "[INFO] status=0x%x, raw_status=0x%x, last_isr_statuses=0x%x, "
			       "last_rx=%ums, last_tx=%ums, last_isr=%ums\n",
			       status,
			       raw_status,
			       irq_stats->last_isr_statuses,
			       jiffies_to_msecs(now - irq_stats->last_rx),
			       jiffies_to_msecs(now - irq_stats->last_tx),
			       jiffies_to_msecs(now - irq_stats->last_isr));

		if (status & cl_hw->ipc_e2a_irq.msg) {
			ipc_host_global_int_en_set(chip, 0);

			/* Acknowledge the MSG interrupt */
			ipc_xmac_2_host_ack_set(cl_hw->chip, cl_hw->ipc_e2a_irq.msg);

			/*
			 * Unlock before calling cl_msg_rx_tasklet() because
			 * spin_unlock_irqrestore() disables interrupts, but in
			 * cl_msg_rx_tasklet() there might be several places that
			 * use spin_unlock_bh() which enables soft-irqs.
			 */
			spin_unlock_irqrestore(&chip_pci->isr_lock, flags);

			/*
			 * Call the tasklet handler (it also gives the CPU that
			 * is mapped to the cl_interrupt few cycle to recover)
			 */
			cl_msg_pci_copy_to_host(cl_hw, ipc_env);
			cl_msg_rx_tasklet((unsigned long)cl_hw);

			/* Re-enable master interrupts */
			ipc_host_global_int_en_set(chip, 1);
		} else {
			spin_unlock_irqrestore(&chip_pci->isr_lock, flags);

			/* Copy messages from fw to host and call the tasklet handler */
			spin_lock_irqsave(&cl_hw->rx_msg_lock, flags);
			cl_msg_pci_copy_to_host(cl_hw, ipc_env);
			spin_unlock_irqrestore(&cl_hw->rx_msg_lock, flags);
			cl_msg_rx_tasklet((unsigned long)cl_hw);
		}

		if (CFM_TEST_BIT(bit, &cl_hw->cfm_flags)) {
			cl_dbg_verbose(cl_hw, "[ERR] Failed to recover from timeout\n");
		} else {
			cl_dbg_verbose(cl_hw, "[INFO] Managed to recover from timeout\n");
			error = 0;
			goto exit;
		}

		/* Failed handling the message */
		CFM_CLEAR_BIT(bit, &cl_hw->cfm_flags);

		cl_msg_cfm_check_exception(cl_hw);

		cl_hw_assert_check(cl_hw);

		if (!strcmp(chip->conf->ce_ela_mode, "XTDEBUG") ||
		    !strcmp(chip->conf->ce_ela_mode, "XTDEBUG_STD")) {
			/*
			 * Special debug hack: collect debug info & skip restart
			 * "wait4cfm" string is expected by debug script, dont change it!
			 */
			run_debug_um_helper_async(cl_hw, "wait4cfm");
			goto exit;
		}

		if (!test_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags) &&
		    !test_bit(CL_DEV_SW_RESTART, &cl_hw->drv_flags) &&
		    test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) &&
		    !cl_hw->is_stop_context) {
			/* Unlock msg mutex before restarting */
			if (req_id != MM_SET_CALIB_REQ || !cl_hw->calib_params.is_matlab)
				mutex_unlock(&cl_hw->msg_tx_mutex);

			if (cl_hw->debugfs.helper_scheduled)
				set_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags);
			else
				cl_recovery_start(cl_hw, RECOVERY_WAIT4CFM);

			return error;
		}
	}

exit:

	/* Unlock msg mutex */
	if (req_id != MM_SET_CALIB_REQ || !cl_hw->calib_params.is_matlab)
		mutex_unlock(&cl_hw->msg_tx_mutex);

	return error;
}

int cl_msg_pci_msg_fw_send(struct cl_hw *cl_hw, const void *msg_params,
			   bool background)
{
	struct fw_msg *msg = container_of((void *)msg_params,
					  struct fw_msg, param);
	u16 req_id = le16_to_cpu(msg->msg_id);
	u16 cfm_bit = cl_msg_cfm_set_bit(req_id);
	int length = sizeof(struct fw_msg) + le16_to_cpu(msg->param_len);
	int error = 0;

	if (!cl_hw->fw_active) {
		cl_dbg_verbose(cl_hw, "Bypass %s (firmware not loaded)\n",
			       MSG_ID_STR(req_id));
		/* Free the message */
		kfree(msg);
		return -EBUSY;
	}

	if (test_bit(CL_DEV_FW_ERROR, &cl_hw->drv_flags)) {
		cl_dbg_verbose(cl_hw, "Bypass %s (CL_DEV_FW_ERROR is set)\n",
			       MSG_ID_STR(req_id));
		/* Free the message */
		kfree(msg);
		return -EBUSY;
	}

	if (!test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) &&
	    req_id != MM_RESET_REQ && req_id != MM_START_REQ) {
		cl_dbg_verbose(cl_hw, "Bypass %s (CL_DEV_STARTED not set)\n",
			       MSG_ID_STR(req_id));
		/* Free the message */
		kfree(msg);
		return -EBUSY;
	}

	/* Lock msg tx of the correct msg buffer. */
	error = mutex_lock_interruptible(&cl_hw->msg_tx_mutex);

	if (error != 0) {
		cl_dbg_verbose(cl_hw, "Bypass %s (mutex error %d)\n",
			       MSG_ID_STR(req_id), error);
		/* Free the message */
		kfree(msg);
		return error;
	}

	cl_hw->msg_background = background;

	CFM_SET_BIT(cfm_bit, &cl_hw->cfm_flags);

	cl_dbg_trace(cl_hw, "%s\n", MSG_ID_STR(req_id));

	/* Push the message in the IPC */
	cl_msg_pci_fw_push(cl_hw, msg, length);

	/* Free the message */
	kfree(msg);

#ifdef TRACE_SUPPORT
	trace_cl_trace_cl_send_msg(cl_hw->idx, (int)req_id);
#endif
	if (req_id == MM_MATLAB_RESPONSE) {
		mutex_unlock(&cl_hw->msg_tx_mutex);
		return 0;
	}

	return cl_msg_pci_cfm_wait(cl_hw, cfm_bit, req_id);
}

