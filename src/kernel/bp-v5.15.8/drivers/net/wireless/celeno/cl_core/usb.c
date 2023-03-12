// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/firmware.h>
#include "usb.h"
#include "def.h"
#include "core_debug.h"
#include "chip_config.h"
#include "config.h"
#include "chip.h"
#include "file.h"
#include "reg_access.h"
#include "reg_macsys_gcu.h"
#include "reg_usbc.h"
#include "ipc_shared.h"

static void cli_usb_rsp_complete(struct urb *urb);
static int cl_core_usb_set_alternate(struct cl_chip *chip, int ifnum, int val);

static const struct usb_device_id cl_core_usb_id_table[] = {
	{USB_DEVICE_INTERFACE_NUMBER(CL_CORE_USB_VENDOR_ID, 0x6000,
				     USB_CLI_IF_NUM)},
	{USB_DEVICE_INTERFACE_NUMBER(CL_CORE_USB_VENDOR_ID, 0x6010,
				     USB_CLI_IF_NUM)},
	{USB_DEVICE_INTERFACE_NUMBER(CL_CORE_USB_VENDOR_ID, 0x6020,
				     USB_CLI_IF_NUM)},
	{ /* Terminating entry */ },
};
MODULE_DEVICE_TABLE(usb, cl_core_usb_id_table);

struct cl_usb_dev_info {
	struct usb_device *dev;
	u16 prod_id;
	u8 serial[STR_LEN_64B + 1];
};

struct cl_core_usb_db {
	u8 device_cntr;
	bool init_done;
	struct cl_usb_dev_info dev_info[CHIP_MAX];
};

static struct cl_core_usb_db usb_db;

static int usb_get_celeno_device(struct usb_device *udev, void *unused)
{
	u16 vendor_id = le16_to_cpu(udev->descriptor.idVendor);
	u8 *new_serial = udev->serial;
	u16 new_id_prod = le16_to_cpu(udev->descriptor.idProduct);

	if (vendor_id != CL_CORE_USB_VENDOR_ID)
		return 0;

	usb_db.dev_info[usb_db.device_cntr].dev = udev;
	usb_db.dev_info[usb_db.device_cntr].prod_id = new_id_prod;
	strncpy(usb_db.dev_info[usb_db.device_cntr].serial, new_serial, STR_LEN_64B);
	usb_db.device_cntr++;

	if (usb_db.device_cntr > 1) {
		s8 i = 0;
		u8 new_idx = usb_db.device_cntr - 1;

		/* Move the new udev to the correct position in the sorted udev array */
		for (i = new_idx - 1; i >= 0; i--) {
			struct usb_device *usb_dev = usb_db.dev_info[i].dev;
			u16 curr_id_prod = le16_to_cpu(usb_dev->descriptor.idProduct);

			if (new_id_prod < curr_id_prod) {
				swap(usb_db.dev_info[i], usb_db.dev_info[i + 1]);
			} else if (new_id_prod == curr_id_prod) {
				u8 *curr_serial = usb_db.dev_info[i].dev->serial;

				if (strcmp(new_serial, curr_serial) < 0)
					swap(usb_db.dev_info[i], usb_db.dev_info[i + 1]);
			} else {
				break;
			}
		}
	}

	return 0;
}

static int cl_core_is_udev_match_dev_entry(struct usb_device *udev, u8 dev_idx)
{
	u8 *serial = udev->serial;
	u16 id_prod = le16_to_cpu(udev->descriptor.idProduct);

	return (!strncmp(usb_db.dev_info[dev_idx].serial, serial, STR_LEN_64B) &&
		usb_db.dev_info[dev_idx].prod_id == id_prod);
}

static u8 cl_core_get_usb_chip_idx(struct usb_device *udev)
{
	u8 chip_idx;
	bool skip_dev_cntr_inc = false;

	if (!usb_db.init_done) {
		usb_db.device_cntr = 0;
		usb_for_each_dev(NULL, usb_get_celeno_device);
		usb_db.init_done = true;
		skip_dev_cntr_inc = true;
	}

	for (chip_idx = 0; chip_idx < CHIP_MAX; chip_idx++) {
		if (cl_core_is_udev_match_dev_entry(udev, chip_idx)) {
			/* Update dev in usb db */
			usb_db.dev_info[chip_idx].dev = udev;

			if (!skip_dev_cntr_inc)
				usb_db.device_cntr++;

			return chip_idx;
		}
	}

	return -1;

}

static int usb_get_fw(struct cl_chip *chip, const char *fw_name,
		      u8 **data, int *size)
{
	int ret = 0;
	const struct firmware *fw;
	char path_name[STR_LEN_128B] = {0};

	snprintf(path_name, sizeof(path_name), "cl6k/%s", fw_name);

	ret = request_firmware(&fw, path_name, chip->dev);
	if (ret) {
		cl_dbg_chip_err(chip, "failed to get %s %x\n",
				fw_name, ret);
		return ret;
	}

	*data = kzalloc(fw->size, GFP_KERNEL);
	if (!*data) {
		ret = -ENOMEM;
		goto out;
	}

	memcpy(*data, fw->data, fw->size);
	*size = fw->size;

out:
	release_firmware(fw);

	return ret;
}

static void usb_do_print_umac_stats_lli(struct cl_chip *chip,
					struct usb_umac_lli_stats *lli,
					bool uplink, u8 lli_idx)
{
	if ((le32_to_cpu(lli->pdma_get) +
	     le32_to_cpu(lli->pdma_done) +
	     le32_to_cpu(lli->pdma_done_error)) == 0)
		return;

	cl_dbg_chip_verbose(chip, "%s LLI idx %d :\n",
			    uplink ? "UL" : "DL", lli_idx);
	cl_dbg_chip_verbose(chip, "\tpdma_get=%x\n",
			    le32_to_cpu(lli->pdma_get));
	cl_dbg_chip_verbose(chip, "\tpdma_done=%x\n",
			    le32_to_cpu(lli->pdma_done));
	cl_dbg_chip_verbose(chip, "\tpdma_done_error=%x\n",
			    le32_to_cpu(lli->pdma_done_error));
	cl_dbg_chip_verbose(chip, "\tpdma_initial=%x\n",
			    le32_to_cpu(lli->pdma_initial));
	cl_dbg_chip_verbose(chip, "\tpdma_pending_initial=%x\n",
			    le32_to_cpu(lli->pdma_pending_initial));
	cl_dbg_chip_verbose(chip, "\tpdma_done_pending_min=%x\n",
			    le32_to_cpu(lli->pdma_done_pending_min));
	cl_dbg_chip_verbose(chip, "\tpdma_done_pending_max=%x\n",
			    le32_to_cpu(lli->pdma_done_pending_max));
	cl_dbg_chip_verbose(chip, "\tmin=%x\n",
			    le32_to_cpu(lli->range.min));
	cl_dbg_chip_verbose(chip, "\tmax=%x\n",
			    le32_to_cpu(lli->range.max));
	cl_dbg_chip_verbose(chip, "\tavg_sum=%llx\n",
			    le64_to_cpu(lli->range.avg_sum));
	cl_dbg_chip_verbose(chip, "\tavg_cnt=%x\n",
			    le32_to_cpu(lli->range.avg_cnt));
}

static void usb_do_print_umac_stats(struct cl_chip *chip,
				    struct usb_umac_stats *stats)
{
	int i = 0;

	cl_dbg_chip_verbose(chip, "UMAC statistics:\n");
	cl_dbg_chip_verbose(chip, "version=0x%x\n",
			    le32_to_cpu(stats->version));
	cl_dbg_chip_verbose(chip, "size=%x\n", le32_to_cpu(stats->size));
	for (i = 0; i < USBW_UL_LLI_COUNT; i++)
		usb_do_print_umac_stats_lli(chip, &stats->lli_ul[i], true, i);
	for (i = 0; i < USBW_DL_LLI_COUNT; i++)
		usb_do_print_umac_stats_lli(chip, &stats->lli_dl[i], false, i);
}

static bool cli_usb_is_bulk_write_fast_cmd(enum cli_usb_cmd_type type)
{
	return (type == CLI_USB_CMD_BULK_WRITE_FAST_ZCOPY ||
		type == CLI_USB_CMD_BULK_WRITE_FAST_BUFF);
}

static bool cli_usb_is_bulk_write_cmd(enum cli_usb_cmd_type type)
{
	return (type == CLI_USB_CMD_BULK_WRITE_ZCOPY ||
		type == CLI_USB_CMD_BULK_WRITE_BUFF ||
		cli_usb_is_bulk_write_fast_cmd(type));
}

static bool cli_usb_is_bulk_read_cmd(enum cli_usb_cmd_type type)
{
	return (type == CLI_USB_CMD_BULK_READ_ZCOPY ||
		type == CLI_USB_CMD_BULK_READ_BUFF);
}

static u8 *cli_usb_get_data_buf(struct cli_usb_cmd *cmd)
{
	if (cli_usb_is_bulk_read_cmd(cmd->type))
		return cmd->param.bulk_read.buf;
	else if (cmd->type == CLI_USB_CMD_UMAC_LOGGER_GET_INFO)
		return cmd->param.logger.buf;
	else if (cli_usb_is_bulk_write_cmd(cmd->type))
		return cmd->param.bulk_write.buf;

	return NULL;
}

static u32 cli_usb_get_data_buf_size(struct cli_usb_cmd *cmd)
{
	if (cli_usb_is_bulk_read_cmd(cmd->type))
		return cmd->param.bulk_read.size;
	else if (cmd->type == CLI_USB_CMD_UMAC_LOGGER_GET_INFO)
		return cmd->param.logger.size;
	else if (cli_usb_is_bulk_write_cmd(cmd->type))
		return cmd->param.bulk_write.size;

	return 0;
}

static void cli_usb_fill_bulk_urb(struct usb_device *usb_dev,
				  struct urb *urb,
				  u32 pipe,
				  void *context,
				  usb_complete_t complete_fn)
{
	urb->dev = usb_dev;
	urb->pipe = pipe;
	urb->complete = complete_fn;
	urb->context = context;
}

static int cli_usb_wait_for_completion(struct cl_chip *chip,
				       struct completion *complete)
{
	int ret;

	if (unlikely(in_atomic())) {
		WARN_ON(1);
		return -EPERM;
	}

	if (!wait_for_completion_timeout(complete,
					 CLI_USB_CLI_TIMEOUT_JIFFIES)) {
		cl_dbg_chip_err(chip, "timeout !!!\n");
		ret = cl_core_usb_set_alternate(chip,
						USB_CLI_IF_NUM, ALT_STOP);
		if (!ret)
			ret = cl_core_usb_set_alternate(chip,
							USB_CLI_IF_NUM,
							ALT_RUN);
		if (ret)
			cl_dbg_chip_err(chip,
					"reset via alternate failed %d!!!\n",
					ret);

		return -ETIMEDOUT;
	}

	return 0;
}

static int cli_usb_submit_rsp_urb(struct cl_chip *chip,
				  struct cli_usb_cmd *cmd)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_usb_endpoint *ep = &chip_usb->eps[CL_USB_EP_CLI_IN];
	u8 *buf = NULL;
	struct urb *urb = usb_alloc_urb(0, GFP_ATOMIC);
	size_t rsp_size = sizeof(struct cli_usb_rsp_hdr);
	int ret;

	if (!urb)
		return -ENOMEM;

	buf = kzalloc(rsp_size, GFP_ATOMIC);
	if (!buf) {
		ret = -ENOMEM;
		goto fail;
	}

	cmd->ep = ep;
	init_completion(&cmd->rsp_complete);
	cli_usb_fill_bulk_urb(chip_usb->usb_dev, urb, ep->pipe,
			      (void *)cmd, cli_usb_rsp_complete);
	urb->transfer_buffer_length = rsp_size;
	urb->transfer_buffer = buf;
	usb_anchor_urb(urb, &ep->submitted);

	ret = usb_submit_urb(urb, GFP_ATOMIC);
	if (ret) {
		cl_dbg_chip_err(chip, "usb_submit_urb failed\n");
		usb_unanchor_urb(urb);
		kfree(buf);
		goto fail;
	}

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->rsp_complete);
	if (ret)
		goto fail;

	ret = cmd->status;

	return ret;
fail:
	usb_free_urb(urb);

	return ret;
}

static void cli_usb_data_complete(struct urb *urb)
{
	struct cli_usb_cmd *cmd = urb->context;

	if (urb->actual_length == 0)
		goto out;

	if (cmd->type == CLI_USB_CMD_UMAC_LOGGER_GET_INFO)
		cmd->param.logger.actual_length = urb->actual_length;

out:
	usb_free_urb(urb);
	complete(&cmd->data_complete);
}

static int cli_usb_submit_data_urb(struct cl_chip *chip,
				   struct cli_usb_cmd *cmd)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_usb_endpoint *ep;
	u8 *buf = cli_usb_get_data_buf(cmd);
	u32 size = cli_usb_get_data_buf_size(cmd);
	struct urb *urb = usb_alloc_urb(0, GFP_ATOMIC);
	int ret;

	if (!urb)
		return -ENOMEM;

	if (!buf || !size) {
		ret = -EINVAL;
		goto fail;
	}

	if (cli_usb_is_bulk_read_cmd(cmd->type) ||
	    cmd->type == CLI_USB_CMD_UMAC_LOGGER_GET_INFO) {
		ep = &chip_usb->eps[CL_USB_EP_CLI_IN];
	} else {
		ep = &chip_usb->eps[CL_USB_EP_CLI_OUT];
		urb->transfer_flags |= URB_ZERO_PACKET;
	}

	cmd->ep = ep;
	init_completion(&cmd->data_complete);
	cli_usb_fill_bulk_urb(chip_usb->usb_dev, urb, ep->pipe,
			      (void *)cmd, cli_usb_data_complete);
	urb->transfer_buffer_length = size;
	urb->transfer_buffer = buf;
	usb_anchor_urb(urb, &ep->submitted);
	if (usb_submit_urb(urb, GFP_ATOMIC)) {
		usb_unanchor_urb(urb);
		cl_dbg_chip_err(chip, "usb_submit_urb failed\n");
	}

	/*
	 * For length=X*MPS (Max Packet Size) need to submit
	 * another URB for the zero length packet
	 */
	if (cli_usb_is_bulk_read_cmd(cmd->type) &&
	    (size % cmd->ep->max_packet_size) == 0) {
		urb = usb_alloc_urb(0, GFP_ATOMIC);
		if (!urb) {
			ret = -ENOMEM;
			goto fail;
		}
		reinit_completion(&cmd->data_complete);
		cli_usb_fill_bulk_urb(chip_usb->usb_dev, urb, ep->pipe,
				      (void *)cmd, cli_usb_data_complete);
		usb_anchor_urb(urb, &ep->submitted);
		if (usb_submit_urb(urb, GFP_ATOMIC)) {
			usb_unanchor_urb(urb);
			cl_dbg_chip_err(chip, "usb_submit_urb failed\n");
		}
	}

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->data_complete);
	if (ret)
		goto fail;

	return ret;
fail:
	usb_free_urb(urb);

	return ret;
}

static void cli_usb_rsp_handle(struct cli_usb_cmd *cmd,
			       struct cli_usb_rsp_hdr *rsp)
{
	enum cli_usb_cmd_type type = le32_to_cpu(rsp->cmd_id);

	if (type == CLI_USB_CMD_GET_VERSION) {
		cmd->param.version.protocol = le32_to_cpu(rsp->param[0]);
		cmd->param.version.firmware = le32_to_cpu(rsp->param[1]);
	} else if (type == CLI_USB_CMD_UMAC_LOGGER_GET_LEVEL) {
		cmd->param.logger.level = le32_to_cpu(rsp->param[0]);
	} else if (type == CLI_USB_CMD_READ) {
		cmd->param.read.value = le32_to_cpu(rsp->param[0]);
	} else if (type == CLI_USB_CMD_FUNC_IOCTL_0) {
		cmd->param.ioctl.io_in_param[0] = le32_to_cpu(rsp->param[0]);
		cmd->param.ioctl.io_in_param[1] = le32_to_cpu(rsp->param[1]);
	}
}

static void cli_usb_cmd_complete(struct urb *urb)
{
	kfree(urb->transfer_buffer);
	usb_free_urb(urb);
}

static void cli_usb_rsp_complete(struct urb *urb)
{
	struct cli_usb_cmd *cmd = urb->context;
	struct cl_usb_endpoint *ep = cmd->ep;
	struct cl_chip *chip = ep->chip;
	int status = urb->status;
	struct cli_usb_rsp_hdr *
		rsp = (struct cli_usb_rsp_hdr *)urb->transfer_buffer;

	cmd->status = status;

	if (status) {
		cl_dbg_chip_err(chip, "urb->status %d\n", urb->status);
		goto out;
	}

	if (urb->actual_length != sizeof(struct cli_usb_rsp_hdr)) {
		cl_dbg_chip_err(chip, "wrong urb->actual_length %x\n",
				urb->actual_length);
		goto out;
	}

	if (cmd->type != le32_to_cpu(rsp->cmd_id)) {
		cl_dbg_chip_err(chip, "cmd->type 0x%x, rsp->cmd_id 0x%x\n",
				cmd->type, le32_to_cpu(rsp->cmd_id));
		goto out;
	}

	if ((cmd->seq_id - le32_to_cpu(rsp->seq_id)) > 1) {
		cl_dbg_chip_err(chip, "cmd->seq_id %d, rsp->seq_id %d\n",
				cmd->seq_id, rsp->seq_id);
		goto out;
	}

	cmd->status = le32_to_cpu(rsp->status);
	if (!cmd->status)
		cli_usb_rsp_handle(cmd, rsp);

out:
	kfree(rsp);
	usb_free_urb(urb);

	complete(&cmd->rsp_complete);

	return;
}

static int cli_usb_send_cmd(struct cl_chip *chip,
			    struct cli_usb_cmd *cmd,
			    struct cli_usb_cmd_hdr *hdr)
{
	struct urb *urb = usb_alloc_urb(0, GFP_KERNEL);
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_usb_endpoint *ep = cmd->ep;
	int ret;

	if (!chip_usb->eps)
		return -ENODATA;

	if (!urb)
		return -ENOMEM;

	cmd->seq_id = chip_usb->cli_cmd_seq_id++;

	hdr->cmd_id = cpu_to_le32(cmd->type);
	hdr->seq_id = cpu_to_le32(cmd->seq_id);

	cli_usb_fill_bulk_urb(chip_usb->usb_dev, urb, ep->pipe,
			      (void *)cmd, cli_usb_cmd_complete);
	urb->transfer_buffer_length = sizeof(*hdr);
	urb->transfer_buffer = hdr;

	usb_anchor_urb(urb, &ep->submitted);

	ret = usb_submit_urb(urb, GFP_ATOMIC);
	if (ret) {
		usb_unanchor_urb(urb);
		cl_dbg_chip_err(chip, "usb_submit_urb failed\n");
	}

	return ret;
}

static void usb_cli_init_hdr(struct cl_chip *chip, struct cli_usb_cmd *cmd,
			     struct cli_usb_cmd_hdr *hdr)
{
	switch (cmd->type) {
	case CLI_USB_CMD_GET_VERSION:
		break;
	case CLI_USB_CMD_READ:
		hdr->param[0] = cpu_to_le32(cmd->param.read.addr);
		break;
	case CLI_USB_CMD_WRITE:
	case CLI_USB_CMD_WRITE_FAST:
		hdr->param[0] = cpu_to_le32(cmd->param.write.addr);
		hdr->param[1] = cpu_to_le32(cmd->param.write.value);
		hdr->param[2] = cpu_to_le32(cmd->param.write.mask);
		break;
	case CLI_USB_CMD_KEEP_ALIVE:
		break;
	case CLI_USB_CMD_DISCONNECT_USB:
		hdr->param[0] = cpu_to_le32(cmd->param.disconnect.msec_delay);
		break;
	case CLI_USB_CMD_UMAC_EXECUTE:
		hdr->param[0] = cpu_to_le32(cmd->param.umac_exec.jump_addr);
		break;
	case CLI_USB_CMD_UMAC_RESTART:
		hdr->param[0] = cpu_to_le32(cmd->param.umac_restart.disconnect_delay);
		hdr->param[1] = cpu_to_le32(cmd->param.umac_restart.restart_delay);
		hdr->param[2] = cpu_to_le32(cmd->param.umac_restart.jump_addr);
		break;
	case CLI_USB_CMD_UMAC_LOGGER_GET_INFO:
		hdr->param[0] = cpu_to_le32(cmd->param.logger.index);
		break;
	case CLI_USB_CMD_UMAC_LOGGER_GET_LEVEL:
		hdr->param[0] = cpu_to_le32(cmd->param.logger.index);
		break;
	case CLI_USB_CMD_UMAC_LOGGER_SET_LEVEL:
		hdr->param[0] = cpu_to_le32(cmd->param.logger.index);
		hdr->param[1] = cpu_to_le32(cmd->param.logger.level);
		break;
	case CLI_USB_CMD_BULK_READ_ZCOPY:
	case CLI_USB_CMD_BULK_READ_BUFF:
		hdr->param[0] = cpu_to_le32(cmd->param.bulk_read.addr);
		hdr->param[1] = cpu_to_le32(cmd->param.bulk_read.size);
		break;
	case CLI_USB_CMD_BULK_WRITE_ZCOPY:
	case CLI_USB_CMD_BULK_WRITE_FAST_ZCOPY:
	case CLI_USB_CMD_BULK_WRITE_BUFF:
	case CLI_USB_CMD_BULK_WRITE_FAST_BUFF:
		hdr->param[0] = cpu_to_le32(cmd->param.bulk_write.addr);
		hdr->param[1] = cpu_to_le32(cmd->param.bulk_write.size);
		break;
	case CLI_USB_CMD_FUNC_IOCTL_0:
		hdr->param[0] = cpu_to_le32(cmd->param.ioctl.io_out_param[0]);
		hdr->param[1] = cpu_to_le32(cmd->param.ioctl.io_out_param[1]);
		hdr->param[2] = cpu_to_le32(cmd->param.ioctl.io_out_param[2]);
		break;
	default:
		cl_dbg_chip_err(chip, "unknown cmd->type %d!!!\n", cmd->type);
	}
}

static void usb_cli_handle_cmd(struct cl_chip *chip, struct cli_usb_cmd *cmd)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cli_usb_cmd_hdr *hdr;
	int ret;

	spin_lock(&chip_usb->cli_cmd_lock);
	list_del(&cmd->list);
	spin_unlock(&chip_usb->cli_cmd_lock);
	chip_usb->cli_cmd_cnt--;

	hdr = kzalloc(sizeof(*hdr), GFP_KERNEL);
	if (!hdr)
		goto out;

	usb_cli_init_hdr(chip, cmd, hdr);

	ret = cli_usb_send_cmd(chip, cmd, hdr);
	if (ret) {
		cl_dbg_chip_err(chip, "cli_usb_send_cmd failed ret=%d\n", ret);
		kfree(hdr);
		cmd->status = ret;
		goto out;
	}

	if (cmd->step2_func) {
		ret = cmd->step2_func(chip, cmd);
		if (ret) {
			cmd->status = ret;
			goto out;
		}
	}

	if (cmd->step3_func) {
		ret = cmd->step3_func(chip, cmd);
		if (ret)
			cmd->status = ret;
	}
out:
	if (!cmd->step2_func)
		kfree(cmd);
	else
		complete(&cmd->complete);
}

static void usb_cli_work_do(struct work_struct *ws)
{
	struct cl_chip_usb *chip_usb = container_of(ws, struct cl_chip_usb,
						    cli_work);
	struct cl_chip *chip = chip_usb->chip;
	struct cli_usb_cmd *cmd = NULL, *cmd_tmp = NULL;

	/* Make sure list is not very loaded - may indicate a BUG if true */
	if (unlikely(chip_usb->cli_cmd_cnt > 100)) {
		cl_dbg_chip_err(chip, "chip_usb->cli_cmd_cnt=%d!!!\n",
				chip_usb->cli_cmd_cnt);
	}

	list_for_each_entry_safe(cmd, cmd_tmp, &chip_usb->cli_cmd_list, list)
		usb_cli_handle_cmd(chip, cmd);
}

static void cli_usb_list_and_schedule_cmd(struct cl_chip *chip,
					  struct cli_usb_cmd *cmd)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	cmd->chip = chip;
	cmd->ep = &chip_usb->eps[CL_USB_EP_CLI_OUT];

	spin_lock(&chip_usb->cli_cmd_lock);
	list_add_tail(&cmd->list, &chip_usb->cli_cmd_list);
	spin_unlock(&chip_usb->cli_cmd_lock);
	chip_usb->cli_cmd_cnt++;

	schedule_work(&chip_usb->cli_work);
}

static int cli_usb_umac_restart(struct cl_chip *chip, u32 disconnect_delay,
				u32 restart_delay, u32 jump_addr)
{
	struct cli_usb_cmd *cmd;

	if (!IS_ALIGNED(jump_addr, 4))
		return -EINVAL;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_UMAC_RESTART;

	cmd->param.umac_restart.disconnect_delay = disconnect_delay;
	cmd->param.umac_restart.restart_delay = restart_delay;
	cmd->param.umac_restart.jump_addr = jump_addr;

	cli_usb_list_and_schedule_cmd(chip, cmd);

	return 0;
}

/* data must be paged contiguous memory up to 32KB */
static int cli_usb_bulk_write(struct cl_chip *chip, u32 addr,
			      u32 length, u8 *data, bool resp)
{
	struct cli_usb_cmd *cmd;
	int ret = 0;

	/* Must be 32bit aligned */
	if (!IS_ALIGNED(addr, 4))
		return -EINVAL;

	/* Must be multiple of 4 */
	if (!length || (length & 0x3) ||
	    length > CLI_USB_WRITE_BOUND_32KB)
		return -EINVAL;

	/* Must be multiple of 4 */
	if (!data || ((unsigned long)data & 0x3))
		return -EINVAL;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	if (resp)
		cmd->type = CLI_USB_CMD_BULK_WRITE_BUFF;
	else
		cmd->type = CLI_USB_CMD_BULK_WRITE_FAST_BUFF;

	cmd->param.bulk_write.addr = addr;
	cmd->param.bulk_write.size = length;
	cmd->param.bulk_write.buf = data;

	cmd->step2_func = cli_usb_submit_data_urb;
	if (cmd->type == CLI_USB_CMD_BULK_WRITE_BUFF)
		cmd->step3_func = cli_usb_submit_rsp_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
out:
	kfree(cmd);

	return ret;
}

static int usb_mask_write32(struct cl_chip *chip, u32 addr,
			    u32 val, u32 mask, bool resp)
{
	struct cli_usb_cmd *cmd;
	u32 reg = add_reg_base_addr(addr);
	int type;
	int ret = 0;

	if (!IS_ALIGNED(addr, 4))
		return -EINVAL;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	if (resp)
		type = CLI_USB_CMD_WRITE;
	else
		type = CLI_USB_CMD_WRITE_FAST;

	cmd->type = type;
	cmd->param.write.addr = reg;
	cmd->param.write.value = val;
	cmd->param.write.mask = mask;

	if (type == CLI_USB_CMD_WRITE) {
		cmd->step2_func = cli_usb_submit_rsp_urb;
		init_completion(&cmd->complete);
	}

	cli_usb_list_and_schedule_cmd(chip, cmd);

	if (type == CLI_USB_CMD_WRITE_FAST)
		return ret;

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
out:
	kfree(cmd);

	return ret;
}

static int usb_write32(struct cl_chip *chip, u32 addr, u32 val)
{
	bool resp = !in_atomic();

	return usb_mask_write32(chip, addr, val, CLI_USB_WRITE_MASK_ALL, resp);
}

static int usb_write_bulk(struct cl_chip *chip, u32 addr,
			  u8 *data, int size)
{
	int i = 0;
	u32 data_length = 0;
	u32 data_offset = 0;
	int ret = 0;
	int order = get_order(CLI_USB_WRITE_BOUND_32KB);
	/* Must be DMA capable physically contiguous memory */
	u32 *dma_data;
#ifdef __BIG_ENDIAN
	u32 *src;
	int j = 0;
#endif

	dma_data = (u32 *)__get_free_pages(GFP_KERNEL, order);
	if (!dma_data) {
		cl_dbg_chip_err(chip, "__get_free_pages failed\n");
		return -ENOMEM;
	}

	for (i = 0; size > 0; i++) {
		data_length = min_t(int, size, CLI_USB_WRITE_BOUND_32KB);
		data_offset = i * CLI_USB_WRITE_BOUND_32KB;
#ifdef __LITTLE_ENDIAN
		memcpy(dma_data, data + data_offset, data_length);
#else
		src = (u32 *)(data + data_offset);
		for (j = 0; j < data_length; j += sizeof(*src))
			*dma_data++ = cpu_to_le32(*src++);
#endif
		ret = cli_usb_bulk_write(chip, add_reg_base_addr(addr),
					 data_length, (u8 *)dma_data, true);
		if (ret) {
			cl_dbg_chip_err(chip,
					"cli_usb_bulk_write failed %d\n", ret);
			goto out;
		}
		size -= CLI_USB_WRITE_BOUND_32KB;
		addr += data_length;
	}

 out:
	free_pages((unsigned long)dma_data, order);

	return ret;
}

static int usb_read32(struct cl_chip *chip, u32 addr, u32 *val)
{
	struct cli_usb_cmd *cmd;
	u32 reg = add_reg_base_addr(addr);
	int ret = 0;

	if (!IS_ALIGNED(addr, 4))
		return -EINVAL;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_READ;

	cmd->param.read.addr = reg;

	cmd->step2_func = cli_usb_submit_rsp_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
	if (ret)
		goto out;

	*val = cmd->param.read.value;
out:
	kfree(cmd);

	return ret;
}

/* Data must be paged contiguous memory up to 32KB */
static int usb_read_bulk(struct cl_chip *chip, u32 addr,
			 u32 length, u8 *data)
{
	struct cli_usb_cmd *cmd;
	u32 reg = add_reg_base_addr(addr);
	int ret = 0;

	/* Must be 32bit aligned */
	if (!IS_ALIGNED(addr, 4))
		return -EINVAL;

	/* Must be multiple of 4 */
	if (!length || (length & 0x3) ||
	    length > CLI_USB_WRITE_BOUND_32KB)
		return -EINVAL;

	/* Must be multiple of 4 */
	if (!data || ((unsigned long)data & 0x3))
		return -EINVAL;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_BULK_READ_BUFF;

	cmd->param.bulk_read.addr = reg;
	cmd->param.bulk_read.size = length;
	cmd->param.bulk_read.buf = data;

	cmd->step2_func = cli_usb_submit_rsp_urb;
	cmd->step3_func = cli_usb_submit_data_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
out:
	kfree(cmd);

	return ret;
}

static int usb_fw_upload(struct cl_chip *chip, enum cl_fw_file_type type,
			 u8 *data, int size)
{
	struct fw_file_params params = {0};
	int ret = 0;

	ret = fw_file_get_params(chip, type, &params);
	if (ret)
		return ret;

	ret = usb_write_bulk(chip, params.dram_addr,
			     data, params.dram_size);
	if (ret) {
		cl_dbg_chip_err(chip, "DRAM load failed %d\n", ret);
		return ret;
	}

	/* IRAM load */
	size -= IRAM_START_OFFSET;
	size = (size < params.iram_size) ? size : params.iram_size;

	ret = usb_write_bulk(chip, params.iram_addr,
			     (data + IRAM_START_OFFSET), size);
	if (ret) {
		cl_dbg_chip_err(chip, "IRAM load failed %d\n", ret);
		return ret;
	}

	return 0;
}

static int usb_set_usb_profile(struct cl_chip *chip)
{
	int ret;
	u32 val = 0;

	if (cl_chip_is_tcv0_enabled(chip) && chip->conf->ce_bt_mode)
		val = WIFI_BT_PROFILE;
	else if (cl_chip_is_tcv0_enabled(chip))
		val = WIFI_ONLY_PROFILE;
	else if (chip->conf->ce_bt_mode)
		val = BT_ONLY_PROFILE;
	else
		cl_dbg_chip_err(chip, "WIFI and BT are disabled !!!\n");

	if (val == 0)
		return -EINVAL;

	ret = usb_write32(chip, UMAC_USB_PROFILE_REG_ADDR, val);
	if (ret)
		cl_dbg_chip_err(chip, "write 0x%x to 0x%x failed %d\n",
				val, UMAC_USB_PROFILE_REG_ADDR, ret);

	return ret;
}

static u32 usb_get_umac_ds_reg_addr(struct cl_chip *chip, u8 lli)
{
	switch (lli) {
	case 0:
		return UMAC_DS_AGGR_D0_REGS_ADDR;
	case 1:
		return UMAC_DS_AGGR_D1_REGS_ADDR;
	case 2:
		return UMAC_DS_AGGR_D2_REGS_ADDR;
	case 3:
		return UMAC_DS_AGGR_D3_REGS_ADDR;
	case 4:
		return UMAC_DS_AGGR_D4_REGS_ADDR;
	case 5:
		return UMAC_DS_AGGR_D5_REGS_ADDR;
	default:
		return 0;
	}
}

static int usb_set_ds_packets_per_host_transfer(struct cl_chip *chip,
						u8 ds_lli)
{
	struct cl_chip_conf *conf = chip->conf;
	int ret = 0;
	u32 reg_addr = usb_get_umac_ds_reg_addr(chip, ds_lli) +
		       UMAC_DS_PACKETS_PER_HOST_TRANSFER_OFFSET;
	u32 val = conf->ci_tx_usb_max_pdmas[ds_lli];

	if (conf->ci_tx_usb_mode[ds_lli] == USB_TX_MODE_NO_XFER_SPLIT)
		val = val / 2;

	ret = usb_write32(chip, reg_addr, val);
	if (ret)
		cl_dbg_chip_err(chip, "write 0x%x to 0x%x failed %d\n",
				val, reg_addr, ret);

	return ret;
}

static int usb_set_ds_wait_time(struct cl_chip *chip, u8 ds_lli)
{
	int ret = 0;
	u32 reg_addr = usb_get_umac_ds_reg_addr(chip, ds_lli) +
		       UMAC_DS_PDMA_WAIT_TIME_OFFSET;

	ret = usb_write32(chip, reg_addr, 0xFFFFFFFF);
	if (ret)
		cl_dbg_chip_err(chip, "write 0x%x to 0x%x failed %d\n",
				0xFFFFFFF, reg_addr, ret);

	return ret;
}

static int usb_set_ds_capabilities(struct cl_chip *chip, u8 ds_lli)
{
	int ret = 0;
	u32 val = 0;
	u32 reg_addr = usb_get_umac_ds_reg_addr(chip, ds_lli) +
		       UMAC_DS_CAPABILITIES_OFFSET;

	val = chip->conf->ci_tx_usb_mode[ds_lli];

	ret = usb_write32(chip, reg_addr, val);
	if (ret)
		cl_dbg_chip_err(chip, "write 0x%x to 0x%x failed %d\n",
				val, reg_addr, ret);

	return ret;
}

static int usb_set_ds_mode_config(struct cl_chip *chip)
{
	int ret = 0;
	u8 ds_lli = 0;
	struct cl_chip_conf *conf = chip->conf;

	for (ds_lli = 0; ds_lli < UMAC_TX_LLI_CH_MAX; ds_lli++) {
		ret = usb_set_ds_packets_per_host_transfer(chip, ds_lli);
		if (ret)
			return ret;

		if (conf->ci_tx_usb_mode[ds_lli] == USB_TX_MODE_NO_XFER_SPLIT) {
			ret = usb_set_ds_wait_time(chip, ds_lli);
			if (ret)
				return ret;
		}

		if (conf->ci_tx_usb_mode[ds_lli] != USB_TX_MODE_NORMAL) {
			ret = usb_set_ds_capabilities(chip, ds_lli);
			if (ret)
				return ret;
		}
	}

	return ret;
}

static int usb_us_cont_config(struct cl_chip *chip)
{
	int ret = 0;
	struct cl_chip_conf *conf = chip->conf;

	ret = usb_write32(chip,
			  UMAC_US_CONT_U0_REGS_ADDR + UMAC_US_CONT_COUNT_OFFSET,
			  conf->ci_usb_rx_cont_num[CL_RX_BUF_FW]);
	if (ret)
		return ret;

	ret = usb_write32(chip,
			  UMAC_US_CONT_U5_REGS_ADDR + UMAC_US_CONT_COUNT_OFFSET,
			  conf->ci_usb_rx_cont_num[CL_RX_BUF_RXM]);

	return ret;
}

static int usb_set_umac_configuration(struct cl_chip *chip)
{
	int ret = 0;

	ret = usb_set_usb_profile(chip);
	if (ret)
		return ret;

	ret = usb_set_ds_mode_config(chip);
	if (ret)
		return ret;

	ret = usb_us_cont_config(chip);

	return ret;
}

static int usb_check_umac_assert(struct cl_chip *chip)
{
	u32 addr_offset = UMAC_LOG_SIDE_BUF_ADDR_GET(chip);
	int size = UMAC_LOG_SIDE_BUF_SIZE;
	int order = get_order(size);
	/* Must be DMA capable physically contiguous memory */
	u32 *dma_data;
	u8 *data_offset;
	int ret;
	char filename[CL_PATH_MAX];

	if (!addr_offset)
		return 0;

	dma_data = (u32 *)__get_free_pages(GFP_KERNEL, order);
	if (!dma_data) {
		cl_dbg_chip_err(chip, "__get_free_pages failed\n");
		return -ENOMEM;
	}

	data_offset = (u8 *)dma_data;
	while (size > 0) {
		if (usb_read_bulk(chip, addr_offset,
				  CLI_USB_WRITE_BOUND_32KB, data_offset)) {
			cl_dbg_chip_err(chip, "failed to read addr=0x%x\n", addr_offset);
			ret = -EINVAL;
			goto out;
		}

		size -= CLI_USB_WRITE_BOUND_32KB;
		data_offset += CLI_USB_WRITE_BOUND_32KB;
		addr_offset += CLI_USB_WRITE_BOUND_32KB;
	}

	snprintf(filename, sizeof(filename), "/tmp/umac_dump_chip%u", chip->idx);

	cl_dbg_chip_verbose(chip, "create %s\n", filename);

	cl_file_open_and_write(filename, O_WRONLY | O_CREAT,
			       (char *)dma_data, UMAC_LOG_SIDE_BUF_SIZE);

 out:
	/* Reset the BFR_GENERAL register */
	UMAC_LOG_SIDE_BUF_ADDR_RESET(chip);

	free_pages((unsigned long)dma_data, order);

	return ret;
}

static int usb_umac_fw_upload(struct cl_chip *chip)
{
	int ret = 0;
	u8 *fw_data = NULL;
	int fw_size = 0;
	int restart_delay = CL_USB_RESTART_DELAY_MS;

	/* This will make sure CHIPX restarts after CHIPX-1 */
	if (chip->idx > CHIP0) {
		if (IS_REAL_PHY(chip))
			restart_delay = restart_delay * 2 * chip->idx;
		else
			restart_delay = restart_delay * 16;
	}

	ret = usb_get_fw(chip, "umacfw.bin", &fw_data, &fw_size);
	if (ret)
		return ret;

	ret = usb_fw_upload(chip, CL_FW_FILE_UMAC, fw_data, fw_size);
	if (ret)
		goto out;

	ret = usb_set_umac_configuration(chip);
	if (ret)
		goto out;

	macsys_gcu_xt_control_umac_run_stall_setf(chip, 0);

	ret = cli_usb_umac_restart(chip, CL_USB_DISCONNECT_DELAY_MS,
				   restart_delay, LOCAL_UMAC_IRAM_FW_ADDR);
out:
	kfree(fw_data);

	return ret;
}

static int usb_smac_fw_upload(struct cl_chip *chip)
{
	int ret = 0;
	u8 *fw_data = NULL;
	int fw_size = 0;

	ret = usb_get_fw(chip, "smacfw.bin", &fw_data, &fw_size);
	if (ret)
		return ret;

	ret = add_bt_config(chip, fw_data);
	if (ret)
		goto out;

	macsys_gcu_smac_control_smac_boot_src_setf(chip, 0);

	ret = usb_fw_upload(chip, CL_FW_FILE_SMAC, fw_data, fw_size);
	if (ret)
		goto out;

	macsys_gcu_xt_control_smac_run_stall_setf(chip, 0);

	chip->smac_active = true;
out:
	kfree(fw_data);

	return ret;
}

static void *cl_core_usb_alloc_coherent(struct cl_chip *chip, size_t size,
					gfp_t mem_flags, dma_addr_t *dma)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	void *buf = usb_alloc_coherent(chip_usb->usb_dev, size,
				       mem_flags | __GFP_ZERO, dma);

	return buf;
}

static void cl_core_usb_free_coherent(struct cl_chip *chip, size_t size,
				      void *cpu_addr, dma_addr_t dma)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	usb_free_coherent(chip_usb->usb_dev, size, cpu_addr,  dma);
}

static int usb_print_umac_stats(struct cl_chip *chip)
{
	u32 addr = 0;
	int ret = 0;
	struct usb_umac_stats *stats;

	stats = kzalloc(sizeof(*stats), GFP_KERNEL);
	if (!stats)
		return -ENOMEM;

	if (usb_read32(chip, SHARED_RAM_START_ADDR +
		       offsetof(struct cl_ipc_shared_env, usb_umac_env) +
		       offsetof(struct usb_umac_env_tag, umac_stats_addr),
		       &addr)) {
		cl_dbg_chip_err(chip, "failed to read umac_stats_addr\n");
		ret = -EINVAL;
		goto out;
	}

	if (!addr) {
		cl_dbg_chip_err(chip, "umac_stats_addr is not set\n");
		ret = -EINVAL;
		goto out;
	}

	if (usb_read_bulk(chip, addr, sizeof(struct usb_umac_stats),
			  (u8 *)stats)) {
		cl_dbg_chip_err(chip, "failed to read addr=0x%x\n", addr);
		ret = -EINVAL;
		goto out;
	}

	usb_do_print_umac_stats(chip, stats);
out:
	kfree(stats);

	return ret;
}

static int usb_get_umac_version(struct cl_chip *chip,
				struct cli_usb_param_version *version)
{
	struct cli_usb_cmd *cmd;
	int ret = 0;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_GET_VERSION;

	cmd->step2_func = cli_usb_submit_rsp_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
	*version = cmd->param.version;
out:
	kfree(cmd);

	return ret;
}

static int cl_core_usb_set_alternate(struct cl_chip *chip, int ifnum, int val)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	return usb_set_interface(chip_usb->usb_dev, ifnum, val);
}

static void usb_print_info(struct cl_chip *chip,
			   struct usb_interface *interface)
{
	struct usb_device *dev = interface_to_usbdev(interface);
	struct usb_host_interface *iface_desc = interface->cur_altsetting;
	u16 vendor_id, product_id, bcd_device;
	char vendor_name[STR_LEN_64B];
	char product_name[STR_LEN_64B];
	char serial_name[STR_LEN_64B];

	vendor_id = le16_to_cpu(dev->descriptor.idVendor);
	product_id = le16_to_cpu(dev->descriptor.idProduct);
	bcd_device = le16_to_cpu(dev->descriptor.bcdDevice);

	usb_string(dev, dev->descriptor.iManufacturer, vendor_name, STR_LEN_64B);
	usb_string(dev, dev->descriptor.iProduct, product_name, STR_LEN_64B);
	usb_string(dev, dev->descriptor.iSerialNumber, serial_name, STR_LEN_64B);

	cl_dbg_chip_verbose(chip, "busnum=%x, bInterfaceNumber=%d\n",
			    dev->bus->busnum, iface_desc->desc.bInterfaceNumber);
	cl_dbg_chip_verbose(chip, "serial_id = %x, serial_name=%s\n",
			    dev->descriptor.iSerialNumber, serial_name);
	cl_dbg_chip_verbose(chip, "vendor_id = %04x, vendor_name=%s\n",
			    vendor_id, vendor_name);
	cl_dbg_chip_verbose(chip, "product_id = %04x, product_name=%s\n",
			    product_id, product_name);
	cl_dbg_chip_verbose(chip, "bcd_device = %04x\n", bcd_device);
	if (dev->speed == USB_SPEED_SUPER_PLUS)
		cl_dbg_chip_verbose(chip, "USB 3.1\n");
	else if (dev->speed == USB_SPEED_SUPER)
		cl_dbg_chip_verbose(chip, "USB 3.0\n");
	else if (dev->speed == USB_SPEED_HIGH)
		cl_dbg_chip_verbose(chip, "USB 2.0\n");
	else
		cl_dbg_chip_verbose(chip, "USB 1.1\n");
}

int cli_usb_umac_logger_get_info(struct cl_chip *chip, u32 idx,
				 u8 *data, size_t size)
{
	struct cli_usb_cmd *cmd;
	int ret = 0;

	/* Must be >=4 and multiple of 4 */
	if (!data || ((unsigned long)data & 0x3) || size < 4 || (size & 0x3))
		return -EINVAL;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_UMAC_LOGGER_GET_INFO;

	cmd->param.logger.index = idx;
	cmd->param.logger.buf = data;
	cmd->param.logger.size = size;

	cmd->step2_func = cli_usb_submit_rsp_urb;
	cmd->step3_func = cli_usb_submit_data_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
	if (ret)
		cl_dbg_chip_err(chip, "status=%d for index %d\n", ret, idx);

	if (!ret && cmd->param.logger.actual_length == sizeof(u32))
		ret = cmd->param.logger.actual_length;
out:
	kfree(cmd);

	return ret;
}

int cli_usb_umac_logger_get_level(struct cl_chip *chip, u32 idx, u32 *level)
{
	struct cli_usb_cmd *cmd;
	int ret = 0;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_UMAC_LOGGER_GET_LEVEL;

	cmd->param.logger.index = idx;

	cmd->step2_func = cli_usb_submit_rsp_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
	if (ret) {
		cl_dbg_chip_err(chip, "status=%d for index %d\n", ret, idx);
		goto out;
	}

	*level = cmd->param.logger.level;
out:
	kfree(cmd);

	return ret;
}

int cli_usb_umac_logger_set_level(struct cl_chip *chip, u32 idx, u32 level)
{
	struct cli_usb_cmd *cmd;
	int ret = 0;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_UMAC_LOGGER_SET_LEVEL;

	cmd->param.logger.index = idx;
	cmd->param.logger.level = level;

	cmd->step2_func = cli_usb_submit_rsp_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
	if (ret) {
		cl_dbg_chip_err(chip, "status=%d for index %d\n", ret, idx);
		goto out;
	}
out:
	kfree(cmd);

	return ret;
}

int cli_usb_disconnect(struct cl_chip *chip, u32 delay)
{
	struct cli_usb_cmd *cmd;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_DISCONNECT_USB;

	cmd->param.disconnect.msec_delay = delay;

	cli_usb_list_and_schedule_cmd(chip, cmd);

	return 0;
}

int cli_usb_umac_exec(struct cl_chip *chip, u32 addr)
{
	struct cli_usb_cmd *cmd;

	if (!IS_ALIGNED(addr, 4))
		return -EINVAL;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_UMAC_EXECUTE;

	cmd->param.umac_exec.jump_addr = addr;

	cli_usb_list_and_schedule_cmd(chip, cmd);

	return 0;
}

static int cli_usb_keep_alive(struct cl_chip *chip)
{
	struct cli_usb_cmd *cmd;
	int ret = 0;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_KEEP_ALIVE;

	cmd->step2_func = cli_usb_submit_rsp_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
out:
	kfree(cmd);

	return ret;
}

static int cli_usb_ioctl(struct cl_chip *chip,
			 enum cli_usb_cmd_ioctl_code code,
			 u32 param1, u32 param2)
{
	struct cli_usb_cmd *cmd;
	int ret = 0;

	cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
	if (!cmd)
		return -ENOMEM;

	cmd->type = CLI_USB_CMD_FUNC_IOCTL_0;

	cmd->param.ioctl.io_out_param[0] = code;
	cmd->param.ioctl.io_out_param[1] = param1;
	cmd->param.ioctl.io_out_param[2] = param2;

	cmd->step2_func = cli_usb_submit_rsp_urb;

	init_completion(&cmd->complete);

	cli_usb_list_and_schedule_cmd(chip, cmd);

	/* Wait for response */
	ret = cli_usb_wait_for_completion(chip, &cmd->complete);
	if (ret)
		goto out;

	ret = cmd->status;
out:
	kfree(cmd);

	return ret;
}

static void cl_core_umac_keepalive_callback(struct work_struct *work)
{
	int ret = 0;
	struct cl_chip_usb *chip_usb = container_of(work, struct cl_chip_usb,
						    umac_keepalive_work.work);
	struct cl_chip *chip = chip_usb->chip;

	if (chip_usb->last_umac_ka &&
	    time_after(jiffies, chip_usb->last_umac_ka +
		       msecs_to_jiffies(CL_CLI_USB_WD_MS)))
		cl_dbg_chip_err(chip, "%u msec passed since last keepalive\n",
				jiffies_to_msecs(jiffies -
						 chip_usb->last_umac_ka));
	ret = cli_usb_keep_alive(chip);
	if (ret)
		cl_dbg_chip_err(chip, "cli_usb_keep_alive failed %d\n", ret);

	chip_usb->last_umac_ka = jiffies;
	schedule_delayed_work(&chip_usb->umac_keepalive_work,
			      msecs_to_jiffies(CL_CLI_USB_KA_MS));
}

static int usb_setup_ep(struct cl_chip *chip, u8 address)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct usb_device *dev = chip_usb->usb_dev;
	struct usb_endpoint_descriptor *endpoint;
	struct cl_usb_endpoint *ep;

	if (address == CL_USB_EP_ADDR_CLI_IN) {
		endpoint = &dev->ep_in[1]->desc;
		if (address != endpoint->bEndpointAddress) {
			cl_dbg_chip_err(chip, "invalid CLI IN address 0x%x\n",
					endpoint->bEndpointAddress);
			return -EINVAL;
		}

		ep = &chip_usb->eps[CL_USB_EP_CLI_IN];
		ep->pipe = usb_rcvbulkpipe(dev, address);
	} else {
		endpoint = &dev->ep_out[1]->desc;
		if (address != endpoint->bEndpointAddress) {
			cl_dbg_chip_err(chip, "invalid CLI OUT address 0x%x\n",
					endpoint->bEndpointAddress);
			return -EINVAL;
		}
		ep = &chip_usb->eps[CL_USB_EP_CLI_OUT];
		ep->pipe = usb_sndbulkpipe(dev, address);
	}

	if (ep->pipe == 0) {
		cl_dbg_chip_err(chip, "no pipe for address 0x%x\n", address);
		return -ENODEV;
	}

	ep->chip = chip;
	ep->address = address;
	ep->max_packet_size = le16_to_cpu(endpoint->wMaxPacketSize);
	init_usb_anchor(&ep->submitted);

	return 0;
}

static int usb_setup_eps(struct cl_chip *chip)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	if (!chip_usb->eps) {
		chip_usb->eps = kzalloc((sizeof(struct cl_usb_endpoint) *
					 CL_USB_EP_MAX), GFP_KERNEL);

		if (!chip_usb->eps)
			return -ENOMEM;
	}

	if (usb_setup_ep(chip, CL_USB_EP_ADDR_CLI_IN)) {
		cl_dbg_chip_err(chip, "no CLI IN endpoint\n");
		return -ENODEV;
	}

	if (usb_setup_ep(chip, CL_USB_EP_ADDR_CLI_OUT)) {
		cl_dbg_chip_err(chip, "no CLI OUT endpoint\n");
		return -ENODEV;
	}

	return 0;
}

static void usb_deinit_ep(struct cl_usb_endpoint *ep)
{
	int timeout;

	if (!ep->address || usb_anchor_empty(&ep->submitted))
		return;

	timeout = usb_wait_anchor_empty_timeout(&ep->submitted, 1000);
	if (!timeout)
		usb_kill_anchored_urbs(&ep->submitted);
}

static void usb_deinit_cli_eps(struct cl_chip *chip)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	if (!chip_usb->eps)
		return;

	usb_deinit_ep(&chip_usb->eps[CL_USB_EP_CLI_IN]);
	usb_deinit_ep(&chip_usb->eps[CL_USB_EP_CLI_OUT]);
}

static void usb_deinit_eps(struct cl_chip *chip)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	usb_deinit_cli_eps(chip);
	usb_deinit_app_eps(chip);

	kfree(chip_usb->eps);
	chip_usb->eps = NULL;
}

static const struct cl_chip_ops usb_ops = {
	.mask_write32 = usb_mask_write32,
	.write32 = usb_write32,
	.write_bulk = usb_write_bulk,
	.read32 = usb_read32,
	.read_bulk = usb_read_bulk,
	.fw_upload = usb_fw_upload,
	.umac_fw_upload = usb_umac_fw_upload,
	.smac_fw_upload = usb_smac_fw_upload,
	.config_set = cl_chip_config_set,
	.config_print = cl_chip_config_print,
	.alloc_coherent = cl_core_usb_alloc_coherent,
	.free_coherent = cl_core_usb_free_coherent,
	.print_umac_stats = usb_print_umac_stats,
	.get_umac_version = usb_get_umac_version,
	.usb_set_alternate = cl_core_usb_set_alternate,
};

static int cl_core_usb_probe(struct usb_interface *interface,
			     const struct usb_device_id *id)
{
	struct usb_device *dev = interface_to_usbdev(interface);
	u16 product_id;
	u16 bcd_device;
	int ret = 0;
	u8 ds_lli = 0;
	struct cl_chip_usb *chip_usb;
	u8 chip_idx = cl_core_get_usb_chip_idx(dev);
	struct cl_chip *chip = cl_chip_get(chip_idx);

	if (!chip) {
		pr_err("cl_chip_get idx %u failed\n", chip_idx);
		return -ENOMEM;
	}

	product_id = le16_to_cpu(dev->descriptor.idProduct);
	bcd_device = le16_to_cpu(dev->descriptor.bcdDevice);

	chip->dev = &dev->dev;
	chip->bus_type = CL_BUS_TYPE_USB;
	chip->ops = &usb_ops;

	ret = cl_chip_config_read(chip);
	if (ret) {
		cl_chip_dealloc(chip);
		return 0;
	}

	usb_get_dev(dev);

	chip_usb = cl_chip_usb_priv(chip);
	chip_usb->usb_dev = dev;
	chip_usb->chip = chip;
	chip_usb->product_id = product_id;
	chip_usb->bcd_device = bcd_device;
	chip_usb->sg_en = usb_device_no_sg_constraint(dev);
	/*
	 * Index 0 is not allowed because it indicates
	 * this address was already confirmed
	 */
	chip_usb->single_addr_free_idx = 1;

	INIT_WORK(&chip_usb->cli_work, usb_cli_work_do);
	INIT_LIST_HEAD(&chip_usb->cli_cmd_list);
	spin_lock_init(&chip_usb->cli_cmd_lock);

	dev_set_drvdata(&dev->dev, chip);

	ret = usb_setup_eps(chip);
	if (ret)
		goto fail;

	usb_print_info(chip, interface);

	/* In bootrom we load umac and finish here */
	if ((bcd_device & CLI_USB_BCD_DEVICE_APP_MASK) == 0) {
		ret = usb_check_umac_assert(chip);
		if (ret) {
			cl_dbg_chip_err(chip, "usb_check_umac_assert failed %d\n", ret);
			goto fail;
		}

		ret = usb_umac_fw_upload(chip);
		if (ret) {
			cl_dbg_chip_err(chip, "umac_restart failed %d\n", ret);
			goto fail;
		}

		return 0;
	}

	for (ds_lli = 0; ds_lli < UMAC_TX_LLI_CH_MAX; ds_lli++) {
		u32 reg_addr = usb_get_umac_ds_reg_addr(chip, ds_lli) +
			       UMAC_DS_PACKETS_PER_HOST_TRANSFER_OFFSET;
		u32 reg_val = 0;

		ret = usb_read32(chip, reg_addr, &reg_val);
		if (ret)
			cl_dbg_chip_err(chip, "read 0x%x failed %d\n",
					reg_addr, ret);

		chip_usb->umac_ds_aggr_count[ds_lli] = reg_val;
	}

	/* USB2.0 activation/suspend */
	if (dev->speed >= USB_SPEED_SUPER)
		usbc_gusb_2_phycfg_0_suspendusb_20_setf(chip, 1);
	else
		usbc_gusb_2_phycfg_0_suspendusb_20_setf(chip, 0);

	macsys_gcu_smac_control_smac_boot_src_setf(chip, 0);
	/* All cores needs to be reset first (once per chip) */
	chip_reset(chip,
		   XMAC_OCD_HALT_ON_RESET,
		   XMAC_DRESET,
		   XMAC_RUN_STALL,
		   XMAC_BRESET,
		   XMAC_DEBUG_ENABLE);

	chip->umac_active = true;
	if (chip->conf->ce_bt_mode && !chip->fw_test) {
		ret = usb_smac_fw_upload(chip);
		if (ret)
			goto fail;
	}

	ret = cl_core_chip_init(chip);
	if (ret)
		goto fail;

	if (chip->conf->ci_umac_wd_en) {
		ret = cli_usb_ioctl(chip, CL_CLI_USB_CMD_IOCTL_CODE_ENABLE_WD,
				    1, CL_CLI_USB_WD_MS);
		if (ret) {
			cl_dbg_chip_err(chip, "cli_usb_ioctl failed %d\n", ret);
			goto fail;
		}

		INIT_DELAYED_WORK(&chip_usb->umac_keepalive_work,
				  cl_core_umac_keepalive_callback);
		schedule_work(&chip_usb->umac_keepalive_work.work);
	}

	return 0;

 fail:
	dev_set_drvdata(&dev->dev, NULL);
	usb_put_dev(dev);
	usb_deinit_eps(chip);
	cl_chip_dealloc(chip);

	return ret;
}

static void cl_core_usb_driver_disconnect(struct usb_interface *interface)
{
	struct usb_device *dev = interface_to_usbdev(interface);
	struct cl_chip *chip;
	struct cl_chip_usb *chip_usb;

	chip = dev_get_drvdata(&dev->dev);
	if (!chip)
		return;

	chip_usb = cl_chip_usb_priv(chip);

	if (chip->conf->ci_umac_wd_en && chip->umac_active)
		cancel_delayed_work_sync(&chip_usb->umac_keepalive_work);

	cancel_work_sync(&chip_usb->cli_work);

	cl_core_chip_deinit(chip);
	chip->umac_active = false;
	usb_db.dev_info[chip->idx].dev = NULL;
	usb_db.device_cntr--;

	usb_put_dev(chip_usb->usb_dev);
	usb_deinit_eps(chip);

	dev_set_drvdata(chip->dev, NULL);
}

static struct usb_driver cl_core_usb_driver = {
	.name = "cl_core_usb",
	.id_table = cl_core_usb_id_table,
	.probe = cl_core_usb_probe,
	.disconnect = cl_core_usb_driver_disconnect,
};

void usb_deinit_app_eps(struct cl_chip *chip)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	int i = 0;

	if (!chip_usb->eps)
		return;

	for (i = 0; i < CL_USB_EP_MAX; i++)
		if (i != CL_USB_EP_CLI_IN && i != CL_USB_EP_CLI_OUT)
			usb_deinit_ep(&chip_usb->eps[i]);
}
EXPORT_SYMBOL(usb_deinit_app_eps);

int cl_core_usb_register(void)
{
	int ret;

	ret = usb_register(&cl_core_usb_driver);
	if (ret)
		pr_err("failed to register cl_core_usb_driver: %d\n", ret);

	return ret;
}

void cl_core_usb_unregister(void)
{
	usb_deregister(&cl_core_usb_driver);
}
