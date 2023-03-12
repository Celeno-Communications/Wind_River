// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_msg_cfm.h"
#include "chip.h"
#include "cl_msg_pci.h"
#include "reg_access.h"
#include "chip_ops.h"

#ifdef TRACE_SUPPORT
static int stop_lttng_trace(struct cl_hw *cl_hw)
{
	char buf_cmd[CL_PATH_MAX];
	char *envp[1] = {NULL};
	char *argv[2] = {buf_cmd, NULL};
	int ret;

	snprintf(buf_cmd, sizeof(buf_cmd), "%s/scripts/trace_stop.sh", cl_install_dir);

	cl_dbg_verbose(cl_hw, "Requesting Lttng Trace Stop: \"%s\"\n", buf_cmd);

	ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
	return ret;
}
#endif

static u16 cl_msg_cfm_clear_bit(u16 cfm)
{
	if (cfm < MM_REQ_CFM_MAX)
		return ((cfm - 1) >> 1);

	return ((cfm - 1 - FIRST_MSG(TASK_DBG) + MM_REQ_CFM_MAX) >> 1);
}

u16 cl_msg_cfm_set_bit(u16 req)
{
	if (req < MM_REQ_CFM_MAX)
		return (req >> 1);

	return ((req - FIRST_MSG(TASK_DBG) + MM_REQ_CFM_MAX) >> 1);
}

static void cl_msg_cfm_assign_params(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	u32 *param;
	u16 msg_id = le16_to_cpu(msg->id);
	u16 msg_len = le16_to_cpu(msg->param_len);

	/* A message sent in background is not allowed to assign confirmation parameters */
	if (cl_hw->msg_background) {
		cl_dbg_verbose(cl_hw,
			       "Background message can't assign confirmation parameters (%s)\n",
			       MSG_ID_STR(msg_id));
		return;
	}

	if (msg_len) {
		param = kzalloc(msg_len, GFP_ATOMIC);
		if (param) {
			memcpy(param, msg->param, msg_len);
			if (cl_hw->msg_cfm_params[msg_id])
				cl_dbg_err(cl_hw, "msg_cfm_params is not NULL for %s\n",
					   MSG_ID_STR(msg_id));
			cl_hw->msg_cfm_params[msg_id] = param;
		} else {
			cl_dbg_err(cl_hw, "param allocation failed\n");
		}
	} else {
		u16 dummy_dest_id = le16_to_cpu(msg->dummy_dest_id);
		u16 dummy_src_id = le16_to_cpu(msg->dummy_src_id);

		cl_dbg_err(cl_hw, "msg->param_len is 0 [%u,%u,%u]\n",
			   msg_id, dummy_dest_id, dummy_src_id);
	}
}

void cl_msg_cfm_assign_and_clear(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	u16 bit = cl_msg_cfm_clear_bit(le16_to_cpu(msg->id));

	if (CFM_TEST_BIT(bit, &cl_hw->cfm_flags)) {
		cl_msg_cfm_assign_params(cl_hw, msg);
		CFM_CLEAR_BIT(bit, &cl_hw->cfm_flags);
	} else {
		cl_dbg_verbose(cl_hw, "Msg ID not set in cfm_flags (%s)\n",
			       MSG_ID_STR(le16_to_cpu(msg->id)));
	}
}

void cl_msg_cfm_clear(struct cl_hw *cl_hw, struct cl_ipc_e2a_msg *msg)
{
	u16 bit = cl_msg_cfm_clear_bit(le16_to_cpu(msg->id));

	if (!CFM_TEST_AND_CLEAR_BIT(bit, &cl_hw->cfm_flags))
		cl_dbg_verbose(cl_hw, "Msg ID not set in cfm_flags (%s)\n",
			       MSG_ID_STR(le16_to_cpu(msg->id)));
}

void cl_msg_cfm_check_exception(struct cl_hw *cl_hw)
{
	/* Check if Tensilica exception occurred */
	int i;
	u32 pattern;
	u32 type;
	int ret;
	int length = sizeof(struct cl_ipc_exception);
	struct cl_ipc_exception *data = kzalloc(length, GFP_ATOMIC);

	if (!data) {
		cl_dbg_err(cl_hw, "cl_ipc_exception data alloc failed\n");
		return;
	}

	ret = chip_ops_read_bulk(cl_hw->chip, SHARED_RAM_START_ADDR +
				 offsetof(struct cl_ipc_shared_env,
					  exception_info),
				 length, (u8 *)data);

	if (ret) {
		cl_dbg_err(cl_hw, "cl_ipc_exception data read failed\n");
		goto out;
	}

	if (IS_USB_BUS_TYPE(cl_hw->chip)) {
		pattern = le32_to_cpu(data->pattern);
		type = le32_to_cpu(data->type);
	} else {
		pattern = (__force u32)data->pattern;
		type = (__force u32)data->type;
	}

	if (pattern != IPC_EXCEPTION_PATTERN)
		goto out;

	cl_dbg_err(cl_hw, "######################### firmware tensilica exception:\n");
	cl_dbg_err(cl_hw, "................................. type: ");

	switch (type) {
	case 0:
		cl_dbg_err(cl_hw, "EXCEPTION_ILLEGALINSTRUCTION\n");
		break;
	case 2:
		cl_dbg_err(cl_hw, "EXCEPTION_INSTRUCTIONFETCHERROR\n");
		break;
	case 3:
		cl_dbg_err(cl_hw, "EXCEPTION_LOADSTOREERROR\n");
		break;
	case 6:
		cl_dbg_err(cl_hw, "EXCEPTION_INTEGERDIVIDEBYZERO\n");
		break;
	case 7:
		cl_dbg_err(cl_hw, "EXCEPTION_SPECULATION\n");
		break;
	case 8:
		cl_dbg_err(cl_hw, "EXCEPTION_PRIVILEGED\n");
		break;
	case 9:
		cl_dbg_err(cl_hw, "EXCEPTION_UNALIGNED\n");
		break;
	case 16:
		cl_dbg_err(cl_hw, "EXCEPTION_INSTTLBMISS\n");
		break;
	case 17:
		cl_dbg_err(cl_hw, "EXCEPTION_INSTTLBMULTIHIT\n");
		break;
	case 18:
		cl_dbg_err(cl_hw, "EXCEPTION_INSTFETCHPRIVILEGE\n");
		break;
	case 20:
		cl_dbg_err(cl_hw, "EXCEPTION_INSTFETCHPROHIBITED\n");
		break;
	case 24:
		cl_dbg_err(cl_hw, "EXCEPTION_LOADSTORETLBMISS\n");
		break;
	case 25:
		cl_dbg_err(cl_hw, "EXCEPTION_LOADSTORETLBMULTIHIT\n");
		break;
	case 26:
		cl_dbg_err(cl_hw, "EXCEPTION_LOADSTOREPRIVILEGE\n");
		break;
	case 28:
		cl_dbg_err(cl_hw, "EXCEPTION_LOADPROHIBITED\n");
		break;
	default:
		cl_dbg_err(cl_hw, "unknown\n");
		break;
	}

	if (IS_USB_BUS_TYPE(cl_hw->chip)) {
		cl_dbg_err(cl_hw, "................................. EPC: %08X\n",
			   le32_to_cpu(data->epc));
		cl_dbg_err(cl_hw, "................................. EXCSAVE: %08X\n",
			   le32_to_cpu(data->excsave));
		cl_dbg_err(cl_hw, "...................BACKTRACE-PC................\n");

		for (i = 0; i < IPC_BACKTRACT_DEPTH; i++)
			cl_dbg_err(cl_hw, "PC#%d: 0x%08X\n", i,
				   le32_to_cpu(data->backtrace.pc[i]));
	} else {
		cl_dbg_err(cl_hw, "................................. EPC: %08X\n",
			   data->epc);
		cl_dbg_err(cl_hw, "................................. EXCSAVE: %08X\n",
			   data->excsave);
		cl_dbg_err(cl_hw, "...................BACKTRACE-PC................\n");

		for (i = 0; i < IPC_BACKTRACT_DEPTH; i++)
			cl_dbg_err(cl_hw, "PC#%d: 0x%08X\n", i,
				   data->backtrace.pc[i]);
	}

	/* Reset Exception pattern (in order to prevent Exception prints loop) */
	ret = chip_ops_write32(cl_hw->chip,
			       SHARED_RAM_START_ADDR +
			       offsetof(struct cl_ipc_shared_env,
					exception_info), 0);

out:
	kfree(data);
}

void cl_msg_cfm_simulate_timeout(struct cl_hw *cl_hw)
{
	u16 bit = cl_msg_cfm_set_bit(DBG_SET_MOD_FILTER_REQ);

	mutex_lock(&cl_hw->msg_tx_mutex);
	CFM_SET_BIT(bit, &cl_hw->cfm_flags);
	cl_msg_pci_cfm_wait(cl_hw, bit, DBG_SET_MOD_FILTER_REQ);
}

