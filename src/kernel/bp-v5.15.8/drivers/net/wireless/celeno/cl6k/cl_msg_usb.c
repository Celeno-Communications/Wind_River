// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "chip.h"
#include "chip_ops.h"
#include "cl_hw.h"
#include "cl_usb.h"
#include "cl_fw_msg.h"
#include "cl_msg_usb.h"
#include "cl_msg_cfm.h"
#include "cl_agg_cfm.h"
#include "cl_single_cfm.h"
#include "cl_tx_usb.h"
#include "cl_tx.h"
#include "reg_access.h"
#include "cl_um_helper.h"
#include "cl_hw_assert.h"
#include "cl_ipc_shared.h"
#include "cl_recovery.h"

#define CL_USB_DBGINFO_ADDR_MASK 0xFFFC0000
#define CL_USB_CALIB_ADDR_MASK 0xFFFFF000

static void cl_msg_usb_rx_msg_handle(struct cl_hw *cl_hw,
				     struct cl_ipc_e2a_msg *msg)
{
	struct cl_rx_msg *rx_msg = NULL;

	if (le32_to_cpu(msg->pattern) != IPC_E2A_MSG_VALID_PATTERN) {
		cl_dbg_verbose(cl_hw, "WRONG pattern 0x%x\n",
			       le32_to_cpu(msg->pattern));
		return;
	}

	/* Copy msg to local list in host */
	rx_msg = kzalloc(sizeof(*rx_msg), GFP_ATOMIC);

	if (!rx_msg) {
		cl_dbg_err(cl_hw, "rx_msg alloc failed\n");
		return;
	}

	memcpy(&rx_msg->buf, msg, sizeof(struct cl_ipc_e2a_msg));
	spin_lock(&cl_hw->rx_msg_lock);
	list_add_tail(&rx_msg->list, &cl_hw->rx_msg_head);
	spin_unlock(&cl_hw->rx_msg_lock);
	tasklet_schedule(&cl_hw->rx_msg_tasklet);
}

static void cl_msg_usb_dump_msg_handle(struct cl_hw *cl_hw,
				       struct cl_ipc_dbg_msg *dbg_msg)
{
	struct cl_dbg_msg *msg = NULL;

	if (le32_to_cpu(dbg_msg->pattern) != IPC_DBG_VALID_PATTERN) {
		cl_dbg_verbose(cl_hw, "WRONG pattern 0x%x\n",
			       le32_to_cpu(dbg_msg->pattern));
		return;
	}
	/* Copy dbg string to local list in host */
	msg = kzalloc(sizeof(*msg), GFP_ATOMIC);

	if (!msg)
		return;

	memcpy(msg->string, dbg_msg->string, IPC_DBG_PARAM_SIZE);
	spin_lock(&cl_hw->dbg_msg_lock);
	list_add_tail(&msg->list, &cl_hw->dbg_msg_head);
	spin_unlock(&cl_hw->dbg_msg_lock);
	tasklet_schedule(&cl_hw->dbg_tasklet);
}

static void cl_msg_usb_rem_lcu_handle(struct cl_hw *cl_hw, struct urb *urb)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	u8 *data = urb->transfer_buffer;
	int data_len = urb->actual_length;

	if (data_len > chip_usb->lcu_rem_length) {
		cl_dbg_err(cl_hw, "WRONG data_len=%d, lcu_rem_length=%d !!!\n",
			   data_len, chip_usb->lcu_rem_length);
		data_len = chip_usb->lcu_rem_length;
	}

	memcpy(cl_hw->dbginfo.buf->u.dump.la_mem[0] + chip_usb->lcu_offset,
	       data, data_len);
	chip_usb->lcu_rem_length -= data_len;
	chip_usb->lcu_offset += data_len;
	if (chip_usb->lcu_rem_length == 0)
		cl_um_helper_trigger(cl_hw);
}

static void cl_msg_usb_lcu_handle(struct cl_hw *cl_hw, struct urb *urb)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_usb_msg_hdr *hdr = urb->transfer_buffer;
	u8 *data = (u8 *)(urb->transfer_buffer + sizeof(*hdr));
	int data_len = urb->actual_length - sizeof(struct cl_usb_msg_hdr);
	int total_data_len = le16_to_cpu(hdr->length);

	memcpy(cl_hw->dbginfo.buf->u.dump.la_mem[0] + chip_usb->lcu_offset,
	       data, data_len);
	chip_usb->lcu_rem_length = total_data_len - data_len;
	chip_usb->lcu_offset += data_len;
}

static void cl_msg_usb_cfm_single_handle(struct cl_hw *cl_hw,
					 struct cl_ipc_cfm_msg *new_msg)
{
	struct cl_ipc_cfm_msg *msg = NULL;

	msg = (struct cl_ipc_cfm_msg *)(cl_hw->single_cfm_virt_base_addr) +
		(cl_hw->single_cfm_write_idx % IPC_CFM_CNT);

	if (msg->dma_addr)
		cl_dbg_err(cl_hw,
			   "msg->dma_addr is not 0 for idx=%d\n",
			   cl_hw->single_cfm_write_idx % IPC_CFM_CNT);

	*msg = *new_msg;
	cl_hw->single_cfm_write_idx++;
	tasklet_schedule(&cl_hw->tx_single_cfm_tasklet);
}

static void cl_msg_usb_read_req_complete(struct urb *urb)
{
	usb_free_urb(urb);
}

static void cl_msg_usb_read_req_submit_addr(struct cl_hw *cl_hw,
					    struct cl_usb_endpoint *ep,
					    u16 length,
					    u32 src_addr)
{
	struct urb *urb = usb_alloc_urb(0, GFP_KERNEL);
	struct cl_chip *chip = cl_hw->chip;
	void *buf = (void *)(unsigned long)(phys_to_virt(src_addr));

	if (!urb)
		return;

	/* Must be multiple of 4 */
	if (!length || (length & 0x3)) {
		cl_dbg_chip_err(chip, "length %d is not a multiple of 4\n",
				length);
		return;
	}

	cl_usb_fill_bulk_urb(chip, urb, ep, NULL,
			     cl_msg_usb_read_req_complete);

	urb->transfer_buffer_length = length;
	urb->transfer_buffer = buf;
	urb->transfer_dma = (dma_addr_t)src_addr;
	urb->transfer_flags = URB_NO_TRANSFER_DMA_MAP;

	usb_anchor_urb(urb, &ep->submitted);
	if (usb_submit_urb(urb, GFP_KERNEL)) {
		usb_unanchor_urb(urb);
		cl_dbg_chip_verbose(chip, "usb_submit_urb failed length %d buf=%p\n",
				    length, buf);
	}
}

static void cl_msg_usb_read_req_handle(struct cl_hw *cl_hw,
				       struct cl_usb_read_req_msg *msg)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_usb_endpoint *ep = &chip_usb->eps[msg->ep_idx];
	int num_trans = msg->num_trans;
	int i = 0;

	if (!ep->address) {
		cl_dbg_verbose(cl_hw, "empty ep\n");
		return;
	}

	for (i = 0; i < num_trans; i++) {
		cl_msg_usb_read_req_submit_addr(cl_hw, ep,
						le16_to_cpu(msg->length[i]),
						le32_to_cpu(msg->src_addr[i]));
	}
}

static void cl_msg_usb_write_data(struct cl_chip *chip, u8 *data, int data_len)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	memcpy(chip_usb->write_req_addr, data, data_len);

	chip_usb->write_req_rem_length -= data_len;
	if (chip_usb->write_req_rem_length)
		chip_usb->write_req_addr += data_len;
	else
		chip_usb->write_req_addr = NULL;
}

static void *cl_msg_usb_write_req_ptr_convert(struct cl_hw *cl_hw, u32 dma_addr)
{
	void *virt_dest_addr;

	/* Check if dbginfo address */
	if ((dma_addr & CL_USB_DBGINFO_ADDR_MASK) == (u32)cl_hw->dbginfo.dma_addr) {
		u32 offset = dma_addr - (u32)cl_hw->dbginfo.dma_addr;

		virt_dest_addr = (void *)cl_hw->dbginfo.buf + offset;
	} else if ((dma_addr & CL_USB_CALIB_ADDR_MASK) == cl_hw->iq_dcoc_data_info.dma_addr) {
		u32 offset = dma_addr - (u32)cl_hw->iq_dcoc_data_info.dma_addr;

		virt_dest_addr = (void *)cl_hw->iq_dcoc_data_info.iq_dcoc_data + offset;
	} else {
		virt_dest_addr = phys_to_virt(dma_addr);
	}

	return virt_dest_addr;
}

static void cl_msg_usb_write_req_handle(struct cl_hw *cl_hw, struct urb *urb)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_usb_msg_hdr *hdr = urb->transfer_buffer;
	struct cl_usb_write_req_msg *msg = (struct cl_usb_write_req_msg *)
					    ((u8 *)urb->transfer_buffer +
					    sizeof(*hdr));
	u8 *data = (u8 *)(urb->transfer_buffer + sizeof(*hdr) + sizeof(*msg));
	int total_data_len = le16_to_cpu(hdr->length);
	int data_len = urb->actual_length -
		       sizeof(struct cl_usb_msg_hdr) -
		       sizeof(struct cl_usb_write_req_msg);

	chip_usb->write_req_rem_length = total_data_len -
					 sizeof(struct cl_usb_write_req_msg);

	chip_usb->write_req_addr = cl_msg_usb_write_req_ptr_convert(cl_hw,
								    le32_to_cpu(msg->dest_addr));

	 /* Data is already in this URB */
	if (data_len)
		cl_msg_usb_write_data(chip, data, data_len);
}

static void cl_msg_usb_write_data_handle(struct cl_hw *cl_hw, struct urb *urb)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	if (!chip_usb->write_req_addr) {
		cl_dbg_err(cl_hw, "write_req_addr is NULL\n");
		chip_usb->write_req_rem_length = 0;

		return;
	}

	if (urb->actual_length > chip_usb->write_req_rem_length) {
		cl_dbg_err(cl_hw,
			   "urb->actual_length=%d write_req_rem_length=%d\n",
			   urb->actual_length,
			   chip_usb->write_req_rem_length);
		chip_usb->write_req_rem_length = 0;
		chip_usb->write_req_addr = NULL;

		return;
	}

	cl_msg_usb_write_data(chip, urb->transfer_buffer, urb->actual_length);
}

static void cl_msg_usb_agg_pkt_req_handle(struct cl_hw *cl_hw,
					  struct cl_usb_agg_pkt_req_msg *msg)
{
	struct cl_agg_pkt_req_msg *agg_req_msg = NULL;

	/* Copy msg to local list in host */
	agg_req_msg = kzalloc(sizeof(*agg_req_msg), GFP_ATOMIC);

	if (!agg_req_msg) {
		cl_dbg_err(cl_hw, "agg_req_msg alloc failed\n");
		return;
	}

	memcpy(&agg_req_msg->msg, msg, sizeof(struct cl_usb_agg_pkt_req_msg));
	spin_lock(&cl_hw->agg_pkt_req_msg_lock);
	list_add_tail(&agg_req_msg->list, &cl_hw->agg_pkt_req_msg_head);
	spin_unlock(&cl_hw->agg_pkt_req_msg_lock);
	tasklet_schedule(&cl_hw->agg_pkt_req_msg_tasklet);
}

static int cl_msg_usb_single_pkt_req_handle(struct cl_hw *cl_hw,
					    struct cl_usb_single_pkt_req_msg *msg)
{
	struct cl_single_pkt_req_msg *single_req_msg = NULL;

	u8 num_packets = msg->num_packets;
	u8 ep_idx = msg->ep_idx;
	u16 queue_idx = msg->single_queue_idx;
	u32 first_dma_addr = le32_to_cpu(msg->first_txdesc_packet_addr);

	if (msg->is_bcmc)
		return cl_tx_usb_single_packets_send(cl_hw, num_packets,
						     ep_idx, MAX_SINGLE_QUEUES,
						     first_dma_addr);

	if (queue_idx >= MAX_SINGLE_QUEUES) {
		cl_dbg_err(cl_hw, "invalid queue_idx %d\n", queue_idx);
		return -EINVAL;
	}

	/* Copy msg to local list in host */
	single_req_msg = kzalloc(sizeof(*single_req_msg), GFP_ATOMIC);

	if (!single_req_msg) {
		cl_dbg_err(cl_hw, "single_req_msg alloc failed\n");
		return -ENOMEM;
	}

	memcpy(&single_req_msg->msg, msg,
	       sizeof(struct cl_usb_single_pkt_req_msg));
	spin_lock(&cl_hw->single_pkt_req_msg_lock);
	list_add_tail(&single_req_msg->list, &cl_hw->single_pkt_req_msg_head);
	spin_unlock(&cl_hw->single_pkt_req_msg_lock);
	tasklet_schedule(&cl_hw->single_pkt_req_msg_tasklet);

	return 0;
}

static void cl_msg_usb_e2a_irq_handle(struct cl_hw *cl_hw,
				      struct cl_usb_e2a_irq_msg *irq_msg)
{
	u32 status = le32_to_cpu(irq_msg->status);

	if (status & cl_hw->ipc_e2a_irq.tbtt)
		cl_tx_bcns(cl_hw);
}

void cl_msg_usb_in_complete(struct urb *urb)
{
	struct cl_usb_elem *elem = (struct cl_usb_elem *)urb->context;
	struct cl_hw *cl_hw = elem->cl_hw;
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_usb_msg_hdr *hdr = urb->transfer_buffer;
	u8 *data = (u8 *)(urb->transfer_buffer + sizeof(*hdr));

	if (urb->status == -ESHUTDOWN ||
	    urb->status == -ENOENT ||
	    urb->status == -EPROTO ||
	    urb->status == -ECONNRESET) {
		kfree(urb->transfer_buffer);
		usb_free_urb(urb);
		kfree(elem);
		return;
	}

	if (!urb->actual_length && !urb->status) {
		cl_dbg_verbose(cl_hw, "0 length packet\n");
		goto exit;
	}

	if (chip_usb->lcu_rem_length) {
		cl_msg_usb_rem_lcu_handle(cl_hw, urb);
		goto exit;
	}

	if (chip_usb->write_req_rem_length) {
		cl_msg_usb_write_data_handle(cl_hw, urb);
		goto exit;
	}

	if (le32_to_cpu(hdr->magic) != CL_MSG_DBG_MAGIC) {
		cl_dbg_verbose(cl_hw, "WRONG magic 0x%x, urb->status=%d\n",
			       le32_to_cpu(hdr->magic), urb->status);
		goto exit;
	}

	switch (le16_to_cpu(hdr->data_type)) {
	case CL_MSG_USB_TYPE_HOSTMSG_RX:
		cl_msg_usb_rx_msg_handle(cl_hw,
					 (struct cl_ipc_e2a_msg *)data);
		break;
	case CL_MSG_USB_TYPE_DUMP:
		cl_msg_usb_dump_msg_handle(cl_hw,
					   (struct cl_ipc_dbg_msg *)data);
		break;
	case CL_MSG_USB_TYPE_LCU:
		cl_msg_usb_lcu_handle(cl_hw, urb);
		break;
	case CL_MSG_USB_TYPE_CFMSINGLE_TX:
		cl_msg_usb_cfm_single_handle(cl_hw,
					     (struct cl_ipc_cfm_msg *)data);
		break;
	case CL_MSG_USB_TYPE_READ_REQ:
		cl_msg_usb_read_req_handle(cl_hw,
					   (struct cl_usb_read_req_msg *)data);
		break;
	case CL_MSG_USB_TYPE_WRITE_REQ:
		cl_msg_usb_write_req_handle(cl_hw, urb);
		break;
	case CL_MSG_USB_TYPE_DS_AGG_PKT_REQ:
		cl_msg_usb_agg_pkt_req_handle(cl_hw,
					      (struct cl_usb_agg_pkt_req_msg *)data);
		break;
	case CL_MSG_USB_TYPE_DS_SINGLE_PKT_REQ:
		cl_msg_usb_single_pkt_req_handle(cl_hw,
						 (struct cl_usb_single_pkt_req_msg *)data);
		break;
	case CL_MSG_USB_TYPE_E2A_IRQ:
		cl_msg_usb_e2a_irq_handle(cl_hw,
					  (struct cl_usb_e2a_irq_msg *)data);
		break;
	}

 exit:
	memset(urb->transfer_buffer, 0, CL_MSG_DBG_BUF_SIZE);

	if (test_bit(CL_DEV_STARTED, &cl_hw->drv_flags) ||
	    test_bit(CL_DEV_INIT, &cl_hw->drv_flags))
		cl_usb_urb_submit(cl_hw, elem, cl_msg_usb_in_complete);
}

int cl_msg_usb_msg_fw_send(struct cl_hw *cl_hw, const void *msg_params,
			   bool background)
{
	struct cl_chip *chip = cl_hw->chip;
	struct fw_msg *msg = container_of((void *)msg_params,
					  struct fw_msg, param);
	int length = sizeof(struct fw_msg) + le16_to_cpu(msg->param_len);
	u16 req_id = le16_to_cpu(msg->msg_id);
	u16 cfm_bit = cl_msg_cfm_set_bit(req_id);
	int error = 0;
	int timeout = 0;
	int max_timeout = 0;
	/* align message length to 4 */
	length += CL_USB_ALIGN_PADS(length);

	if (!cl_hw->fw_active || cl_hw->is_stop_context) {
		cl_dbg_verbose(cl_hw, "Bypass %s (firmware is not active)\n",
			       MSG_ID_STR(req_id));
		/* Free the message */
		kfree(msg);
		return -EBUSY;
	}

	if (test_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags) &&
	    req_id != MM_RESET_REQ) {
		cl_dbg_verbose(cl_hw, "Bypass %s (CL_DEV_HW_RESTART is set)\n",
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

	error = chip_ops_write_bulk(chip, SHARED_RAM_START_ADDR +
				    offsetof(struct cl_ipc_shared_env,
					     a2e_msg_buf) +
				    offsetof(struct cl_ipc_a2e_msg, msg),
				    (u8 *)msg, length);
	if (error) {
		cl_dbg_err(cl_hw, "chip_ops_write_bulk err %d:: msg %s\n",
			   error, MSG_ID_STR(req_id));
		goto exit;
	}

	CFM_SET_BIT(cfm_bit, &cl_hw->cfm_flags);

	/* Trigger the lmac */
	cl_hw->ipc_host2xmac_trigger_set(chip, IPC_IRQ_A2E_MSG);

	cl_dbg_trace(cl_hw, "%s\n", MSG_ID_STR(req_id));

	if (IS_REAL_PHY(chip))
		max_timeout = CL_MSG_CFM_TIMEOUT_JIFFIES;
	else if (chip->conf->ci_phy_dev == PHY_DEV_FRU)
		max_timeout = CL_MSG_CFM_TIMEOUT_FRU_JIFFIES;
	else
		max_timeout = CL_MSG_CFM_TIMEOUT_DUMMY_JIFFIES;

	if (req_id == MM_SET_CALIB_REQ && cl_hw->calib_params.is_matlab) {
		max_timeout = CL_MSG_CFM_TIMEOUT_CALIB_JIFFIES;
		mutex_unlock(&cl_hw->msg_tx_mutex);
	}

	if (req_id == MM_MATLAB_RESPONSE)
		goto exit;

	/* Wait for confirmation message */
	timeout = wait_event_timeout(cl_hw->wait_queue,
				     !CFM_TEST_BIT(cfm_bit, &cl_hw->cfm_flags),
				     max_timeout);
	if (timeout == 0) {
		/*
		 * Timeout occurred!
		 * Make sure that confirmation wasn't received after the timeout.
		 */
		if (CFM_TEST_BIT(cfm_bit, &cl_hw->cfm_flags)) {
			cl_dbg_verbose(cl_hw, "[WARN] Timeout occurred - %s\n",
				       MSG_ID_STR(req_id));
			/* Failed handling the message */
			CFM_CLEAR_BIT(cfm_bit, &cl_hw->cfm_flags);
			error = -ETIMEDOUT;
		}
		cl_msg_cfm_check_exception(cl_hw);
		cl_hw_assert_check(cl_hw);
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
	if (req_id != MM_SET_CALIB_REQ || !cl_hw->calib_params.is_matlab)
		mutex_unlock(&cl_hw->msg_tx_mutex);

	return error;
}

