// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include <linux/module.h>
#include "cl_main.h"
#include "cl_usb.h"
#include "reg_access.h"
#include "reg_cmu.h"
#include "cl_tx.h"
#include "cl_utils.h"
#include "cl_msg_usb.h"
#include "cl_rx_usb.h"
#include "cl_tx_usb.h"
#include "cl_dbgfile.h"
#include "cl_netlink.h"

static const struct cl_driver_ops drv_usb_ops = {
	.msg_fw_send = cl_msg_usb_msg_fw_send,
};

static void cl_usb_setup_ep(struct cl_chip *chip,
			    struct usb_endpoint_descriptor *endpoint)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct usb_device *dev = chip_usb->usb_dev;
	struct cl_usb_endpoint *ep;
	u8 address = endpoint->bEndpointAddress;

	switch (address) {
	case CL_USB_EP_ADDR_MSG_DBG_IN:
		ep = &chip_usb->eps[CL_USB_EP_MSG_DBG_IN];
		ep->pipe = usb_rcvbulkpipe(dev, address);
		break;
	case CL_USB_EP_ADDR_SENSING_ONLINE_IN:
		ep = &chip_usb->eps[CL_USB_EP_SENSING_ONLINE_IN];
		ep->pipe = usb_rcvbulkpipe(dev, address);
		break;
	case CL_USB_EP_ADDR_SENSING_OFFLINE_IN:
		ep = &chip_usb->eps[CL_USB_EP_SENSING_OFFLINE_IN];
		ep->pipe = usb_rcvbulkpipe(dev, address);
		break;
	case CL_USB_EP_ADDR_RX_DATA_IN:
		ep = &chip_usb->eps[CL_USB_EP_RX_DATA_IN];
		ep->pipe = usb_rcvbulkpipe(dev, address);
		break;
	case CL_USB_EP_ADDR_RXM_DATA_IN:
		ep = &chip_usb->eps[CL_USB_EP_RXM_DATA_IN];
		ep->pipe = usb_rcvbulkpipe(dev, address);
		break;
	case CL_USB_EP_ADDR_TX_DATA_AC0_OUT:
		ep = &chip_usb->eps[CL_USB_EP_TX_DATA_AC0_OUT];
		ep->pipe = usb_sndbulkpipe(dev, address);
		ep->max_chain_size = cl_reg_read(chip,
						 UMAC_DS_AGGR_D0_REGS_ADDR +
						 UMAC_DS_MAX_TRB_CHAIN_SIZE_OFFSET);
		ep->lli_channel = UMAC_TX_LLI_CH_DATA_AC0_IDX;
		break;
	case CL_USB_EP_ADDR_TX_DATA_AC1_OUT:
		ep = &chip_usb->eps[CL_USB_EP_TX_DATA_AC1_OUT];
		ep->pipe = usb_sndbulkpipe(dev, address);
		ep->max_chain_size = cl_reg_read(chip,
						 UMAC_DS_AGGR_D1_REGS_ADDR +
						 UMAC_DS_MAX_TRB_CHAIN_SIZE_OFFSET);
		ep->lli_channel = UMAC_TX_LLI_CH_DATA_AC1_IDX;
		break;
	case CL_USB_EP_ADDR_TX_DATA_AC2_OUT:
		ep = &chip_usb->eps[CL_USB_EP_TX_DATA_AC2_OUT];
		ep->pipe = usb_sndbulkpipe(dev, address);
		ep->max_chain_size = cl_reg_read(chip,
						 UMAC_DS_AGGR_D2_REGS_ADDR +
						 UMAC_DS_MAX_TRB_CHAIN_SIZE_OFFSET);
		ep->lli_channel = UMAC_TX_LLI_CH_DATA_AC2_IDX;
		break;
	case CL_USB_EP_ADDR_TX_DATA_AC3_OUT:
		ep = &chip_usb->eps[CL_USB_EP_TX_DATA_AC3_OUT];
		ep->pipe = usb_sndbulkpipe(dev, address);
		ep->max_chain_size = cl_reg_read(chip,
						 UMAC_DS_AGGR_D3_REGS_ADDR +
						 UMAC_DS_MAX_TRB_CHAIN_SIZE_OFFSET);
		ep->lli_channel = UMAC_TX_LLI_CH_DATA_AC3_IDX;
		break;
	case CL_USB_EP_ADDR_TX_BCAST_OUT:
		ep = &chip_usb->eps[CL_USB_EP_TX_BCAST_OUT];
		ep->pipe = usb_sndbulkpipe(dev, address);
		ep->max_chain_size = cl_reg_read(chip,
						 UMAC_DS_AGGR_D4_REGS_ADDR +
						 UMAC_DS_MAX_TRB_CHAIN_SIZE_OFFSET);
		ep->lli_channel = UMAC_TX_LLI_CH_BCAST_IDX;
		break;
	case CL_USB_EP_ADDR_TX_HTP_OUT:
		ep = &chip_usb->eps[CL_USB_EP_TX_HTP_OUT];
		ep->pipe = usb_sndbulkpipe(dev, address);
		ep->max_chain_size = cl_reg_read(chip,
						 UMAC_DS_AGGR_D5_REGS_ADDR +
						 UMAC_DS_MAX_TRB_CHAIN_SIZE_OFFSET);
		ep->lli_channel = UMAC_TX_LLI_CH_HTP_IDX;
		break;
	case CL_USB_EP_ADDR_TX_DATA_SENSING_OUT:
		ep = &chip_usb->eps[CL_USB_EP_TX_DATA_SENSING_OUT];
		ep->pipe = usb_sndbulkpipe(dev, address);
		break;
	case CL_USB_EP_ADDR_READ_RSP:
		ep = &chip_usb->eps[CL_USB_EP_READ_RSP];
		ep->pipe = usb_sndbulkpipe(dev, address);
		break;
	default:
		cl_dbg_chip_verbose(chip, "unknown EP address 0x%x\n", address);
		return;
	}

	ep->chip = chip;
	ep->address = address;
	ep->max_packet_size = le16_to_cpu(endpoint->wMaxPacketSize);
	init_usb_anchor(&ep->submitted);

	cl_dbg_chip_verbose(chip, "set ep->address=0x%x\n", address);
}

static void cl_usb_init_endpoints(struct cl_chip *chip,
				  struct usb_host_interface *iface_desc)
{
	int i = 0;
	struct usb_endpoint_descriptor *endpoint;

	for (i = 0; i < iface_desc->desc.bNumEndpoints; i++) {
		endpoint = &iface_desc->endpoint[i].desc;
		if (usb_endpoint_xfer_bulk(endpoint))
			cl_usb_setup_ep(chip, endpoint);
	}
}

static void cl_usb_print_info(struct cl_chip *chip,
			      struct usb_interface *interface)
{
	struct usb_device *dev = interface_to_usbdev(interface);
	struct usb_host_interface *iface_desc = interface->cur_altsetting;
	u16 vendor_id, product_id, bcd_device;
	int ret = 0;
	char vendor_name[STR_LEN_64B];
	char product_name[STR_LEN_64B];
	char serial_name[STR_LEN_64B];
	struct cli_usb_param_version version;

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

	ret = chip_ops_get_umac_version(chip, &version);
	if (!ret)
		cl_dbg_chip_verbose(chip, "UMAC protocol=0x%x firmware=0x%x\n",
				    version.protocol, version.firmware);
}

static int cl_usb_probe(struct usb_interface *interface,
			const struct usb_device_id *id)
{
	struct usb_device *dev = interface_to_usbdev(interface);
	struct usb_host_interface *iface_desc = interface->cur_altsetting;
	u16 product_id, bcd_device;
	int ret = 0;
	struct cl_chip *chip = NULL;

	product_id = le16_to_cpu(dev->descriptor.idProduct);
	bcd_device = le16_to_cpu(dev->descriptor.bcdDevice);

	usb_get_dev(dev);
	chip = dev_get_drvdata(&dev->dev);
	if (!chip) {
		pr_err("Chip not found, product_id=%04x, bcd_device=%04x\n",
		       product_id, bcd_device);
		ret = -ENOMEM;
		goto out_usb_put;
	}

	cl_usb_init_endpoints(chip, iface_desc);
	cl_usb_print_info(chip, interface);

	ret = cl_main_init(chip);
	if (ret)
		goto out_usb_put;

	if (chip->cl_hw_tcv0)
		usb_set_intfdata(interface, chip->cl_hw_tcv0);

	if (chip->is_umac_recovery) {
		cl_netlink_send_event_if_add(chip->cl_hw_tcv0);
		chip->is_umac_recovery = false;
	}

	return ret;

out_usb_put:
	usb_put_dev(dev);

	return ret;
}

static void cl_usb_disconnect(struct usb_interface *interface)
{
	struct usb_device *dev = interface_to_usbdev(interface);
	struct cl_chip *chip = NULL;
	struct cl_hw *cl_hw = NULL;

	cl_hw = usb_get_intfdata(interface);
	if (!cl_hw) {
		pr_err("%s: failed to find cl_hw\n", __func__);
		return;
	}

	chip = dev_get_drvdata(&dev->dev);

	if (!chip) {
		set_bit(CL_DEV_HW_RESTART, &cl_hw->drv_flags);
		cl_hw->chip->is_umac_recovery = true;
	}

	cl_main_deinit(cl_hw);

	if (chip) {
		/* Use fast write (with no response) as device will go down */
		cl_reg_write_mask(chip, CMU_GLOBAL_RST_ADDR,
				  CMU_GLOBAL_RESET_KEY1,
				  CLI_USB_WRITE_MASK_ALL, false);
		cl_reg_write_mask(chip, CMU_GLOBAL_RST_ADDR,
				  CMU_GLOBAL_RESET_KEY2,
				  CLI_USB_WRITE_MASK_ALL, false);
	}

	usb_set_intfdata(interface, NULL);
	usb_put_dev(dev);
}

static int cl_usb_msg_dbg_in_alloc(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	struct cl_usb_endpoint *ep = &chip_usb->eps[CL_USB_EP_MSG_DBG_IN];
	struct cl_usb_elem *elem = NULL;
	int i;
	u8 *buf = NULL;

	if (!ep->address)
		return 0;

	for (i = 0; i < CL_MSG_DBG_URB_NUM; i++) {
		elem = cl_usb_elem_urb_alloc(cl_hw, ep);
		if (!elem)
			return -ENOMEM;
		buf = kzalloc(CL_MSG_DBG_BUF_SIZE, GFP_KERNEL);
		if (!buf)
			goto fail;
		elem->urb->transfer_buffer_length = CL_MSG_DBG_BUF_SIZE;
		elem->urb->transfer_buffer = buf;
		cl_usb_urb_submit(cl_hw, elem, cl_msg_usb_in_complete);
	}

	return 0;
 fail:
	kfree(elem);
	return -ENOMEM;
}

static int cl_usb_rx_data_in_alloc(struct cl_hw *cl_hw,
				   struct cl_usb_endpoint *ep,
				   enum rx_buf_type type)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_rx_usb_elem *rx_elem = NULL;
	int i;
	u16 urb_num = chip->conf->ci_usb_rx_urb_num[type];

	if (!ep->address)
		return 0;

	ep->pdmas = kzalloc((sizeof(struct cl_rx_usb_sorted_pdma_elem) *
			    CL_RX_USB_MAX_PDMA_INDEX), GFP_KERNEL);
	if (!ep->pdmas) {
		cl_dbg_verbose(cl_hw, "alloc pdmas failed\n");
		return -ENOMEM;
	}

	for (i = 0; i < urb_num; i++) {
		rx_elem = cl_rx_usb_elem_urb_alloc(cl_hw);
		if (!rx_elem)
			return -ENOMEM;
		rx_elem->ep = ep;
		rx_elem->container_num = chip->conf->ci_usb_rx_cont_num[type];
		if (cl_rx_usb_urb_build(cl_hw, rx_elem))
			goto fail;

		// TODO: Need a different complete function ?
		cl_usb_urb_submit(cl_hw, (struct cl_usb_elem *)rx_elem,
				  cl_rx_usb_rx_data_complete);
	}

	return 0;
 fail:
	cl_rx_usb_elem_dealloc(rx_elem);

	return -ENOMEM;
}

static int cl_usb_in_elems_alloc(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	if (cl_usb_msg_dbg_in_alloc(cl_hw))
		goto out_err;

	if (cl_usb_rx_data_in_alloc(cl_hw,
				    &chip_usb->eps[CL_USB_EP_RX_DATA_IN],
				    CL_RX_BUF_FW))
		goto out_err;

	if (cl_usb_rx_data_in_alloc(cl_hw,
				    &chip_usb->eps[CL_USB_EP_RXM_DATA_IN],
				    CL_RX_BUF_RXM))
		goto out_err;

	return 0;

out_err:
	return -ENOMEM;
}

static struct cl_dbg_msg *cl_usb_get_dbg_msg(struct cl_hw *cl_hw)
{
	struct cl_dbg_msg *msg = NULL;
	unsigned long flags;

	spin_lock_irqsave(&cl_hw->dbg_msg_lock, flags);
	msg = list_first_entry_or_null(&cl_hw->dbg_msg_head, struct cl_dbg_msg, list);

	if (msg)
		list_del(&msg->list);

	spin_unlock_irqrestore(&cl_hw->dbg_msg_lock, flags);

	return msg;
}

static void cl_usb_dbgfile_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_dbg_msg *msg = NULL;

	while ((msg = cl_usb_get_dbg_msg(cl_hw))) {
		cl_dbgfile_print_fw_str(cl_hw, msg->string,
					IPC_DBG_PARAM_SIZE);
		kfree(msg);
	}
}

static void cl_usb_tasklet_init(struct cl_hw *cl_hw)
{
	tasklet_init(&cl_hw->dbg_tasklet,
		     cl_usb_dbgfile_tasklet,
		     (unsigned long)cl_hw);
	tasklet_init(&cl_hw->tx_single_cfm_tasklet,
		     cl_tx_usb_single_cfm_tasklet,
		     (unsigned long)cl_hw);
	tasklet_init(&cl_hw->single_pkt_req_msg_tasklet,
		     cl_tx_usb_single_pkt_req_tasklet,
		     (unsigned long)cl_hw);
	tasklet_init(&cl_hw->agg_pkt_req_msg_tasklet,
		     cl_tx_usb_agg_pkt_req_tasklet,
		     (unsigned long)cl_hw);
}

void cl_usb_set_cl_hw(struct cl_chip *chip, struct cl_hw *cl_hw)
{
	chip->cl_hw_tcv0 = cl_hw;
	chip->cl_hw_tcv0->ops = &drv_usb_ops;
}

int cl_usb_dbginfobuf_push(struct cl_hw *cl_hw)
{
	struct cl_chip *chip = cl_hw->chip;
	int error = chip_ops_write32(chip, SHARED_RAM_START_ADDR +
				     offsetof(struct cl_ipc_shared_env,
					      dbginfo_addr),
				     cl_hw->dbginfo.dma_addr);
	if (error) {
		cl_dbg_err(cl_hw, "chip_ops_write32 err %d\n", error);
		return error;
	}

	error = chip_ops_write32(chip, SHARED_RAM_START_ADDR +
				 offsetof(struct cl_ipc_shared_env,
					  dbginfo_size),
				 DBG_DUMP_BUFFER_SIZE);
	if (error)
		cl_dbg_err(cl_hw, "chip_ops_write32 err %d\n", error);

	return error;
}

void cl_usb_fill_bulk_urb(struct cl_chip *chip,
			  struct urb *urb,
			  struct cl_usb_endpoint *ep,
			  void *context,
			  usb_complete_t complete_fn)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);

	urb->dev = chip_usb->usb_dev;
	urb->pipe = ep->pipe;
	urb->complete = complete_fn;
	urb->context = context;
}

struct cl_usb_elem *cl_usb_elem_urb_alloc(struct cl_hw *cl_hw,
					  struct cl_usb_endpoint *ep)
{
	struct cl_usb_elem *elem = kzalloc(sizeof(*elem), GFP_KERNEL);
	struct urb *urb = NULL;

	if (!elem)
		return NULL;

	urb = usb_alloc_urb(0, GFP_KERNEL);
	if (!urb)
		goto fail;

	elem->cl_hw = cl_hw;
	elem->urb = urb;
	elem->ep = ep;

	return elem;
 fail:
	kfree(elem);
	return NULL;
}

void cl_usb_urb_submit(struct cl_hw *cl_hw,
		       struct cl_usb_elem *elem,
		       usb_complete_t complete_fn)
{
	cl_usb_fill_bulk_urb(cl_hw->chip, elem->urb, elem->ep,
			     (void *)elem, complete_fn);
	usb_anchor_urb(elem->urb, &elem->ep->submitted);
	if (usb_submit_urb(elem->urb, GFP_KERNEL))
		cl_dbg_verbose(cl_hw, "usb_submit_urb failed\n");
}

u16 cl_usb_get_single_addr_idx(struct cl_chip *chip)
{
	struct cl_chip_usb *chip_usb = cl_chip_usb_priv(chip);
	u16 free_idx = chip_usb->single_addr_free_idx;

	chip_usb->single_addr_free_idx++;

	if (!chip_usb->single_addr_free_idx)
		chip_usb->single_addr_free_idx++;

	return free_idx;
}

int cl_usb_main_init(struct cl_hw *cl_hw)
{
	int ret = 0;
	int i;

	ret = cl_usb_in_elems_alloc(cl_hw);
	if (ret)
		return ret;

	cl_usb_tasklet_init(cl_hw);

	for (i = 0; i < IEEE80211_NUM_ACS; i++)
		cl_hw->tx_db.ac_idle[i] = true;

	return ret;
}

void cl_usb_main_deinit(struct cl_hw *cl_hw)
{
	tasklet_kill(&cl_hw->dbg_tasklet);
	tasklet_kill(&cl_hw->tx_single_cfm_tasklet);
	tasklet_kill(&cl_hw->single_pkt_req_msg_tasklet);
	tasklet_kill(&cl_hw->agg_pkt_req_msg_tasklet);
}

static const struct usb_device_id cl_usb_id_table[] = {
	{USB_DEVICE_INTERFACE_NUMBER(CL_CORE_USB_VENDOR_ID, 0x6000,
				     USB_WIFI_IF_NUM)},
	{USB_DEVICE_INTERFACE_NUMBER(CL_CORE_USB_VENDOR_ID, 0x6010,
				     USB_WIFI_IF_NUM)},
	{USB_DEVICE_INTERFACE_NUMBER(CL_CORE_USB_VENDOR_ID, 0x6020,
				     USB_WIFI_IF_NUM)},
	{ /* Terminating entry */ },
};

MODULE_DEVICE_TABLE(usb, cl_usb_id_table);

static struct usb_driver cl_usb_driver = {
	.name = "cl_usb",
	.probe = cl_usb_probe,
	.disconnect = cl_usb_disconnect,
	.id_table = cl_usb_id_table,
};

int cl_usb_init(void)
{
	int ret;

	ret = usb_register(&cl_usb_driver);
	if (ret)
		pr_err("failed to register cl usb driver: %d\n", ret);

	return ret;
}

void cl_usb_exit(void)
{
	usb_deregister(&cl_usb_driver);
}

