// SPDX-License-Identifier: GPL-2.0
/*
 * USB usb throughput test driver
 * @brief A test driver to measure throughput and latency
 *
 * @author Guenter Hildebrandt
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kref.h>
#include <linux/uaccess.h>
#include <linux/usb.h>
#include <linux/mutex.h>
#include <linux/ktime.h>
#include <linux/delay.h>
#include <linux/scatterlist.h>
#include <linux/string.h>
#include <linux/crc32.h>
#include "usbtpt.h"

#define USE_DS_META 0

#define CPU_TO_BUS32(x) cpu_to_le32(x)
#define BUS_TO_CPU32(x) le32_to_cpu(x)
#define CPU_TO_BUS16(x) cpu_to_le16(x)
#define BUS_TO_CPU16(x) le16_to_cpu(x)

/* Define these values to match your devices */
#define USB_TPT_VENDOR_ID 0x33de
#define USB_TPT_PRODUCT_ID_DEFAULT 0x6000

#define USB_TPT_BCD_DEVICE_WIFI_BT 0x0101
#define USB_TPT_BCD_DEVICE_WIFI 0x0102
#define USB_TPT_BCD_DEVICE_BT 0x0103

#define USB_TPT_IF_NUMBER_WIFI 0x1

#define REQ_TIMEOUT 5000

/* the PIDs the driver maps to be default, can be updated via module parameter */
static unsigned short tpt_pid = USB_TPT_PRODUCT_ID_DEFAULT;

/* optional module parameter to be used e.g. as follows:
 *  insmod usbtpt.ko tpt_pid_=0x6000
 */

module_param(tpt_pid, ushort, 0660);

static bool tpt_is_pid_supported(u16 pid)
{
	return (pid == tpt_pid);
}

/* table of devices that work with this driver */
#define USB_DEVICE_IF_SIGNATURE(vend, lowest_bcd, highest_bcd, num) \
	.match_flags = (USB_DEVICE_ID_MATCH_VENDOR | \
			USB_DEVICE_ID_MATCH_DEV_RANGE | \
			USB_DEVICE_ID_MATCH_INT_NUMBER), \
	.idVendor = (vend), \
	.bcdDevice_lo = (lowest_bcd), \
	.bcdDevice_hi = (highest_bcd), \
	.bInterfaceNumber = (num)
static const struct usb_device_id tpt_table[] = {
	// Wifi+BT profile
	{ USB_DEVICE_IF_SIGNATURE(USB_TPT_VENDOR_ID, USB_TPT_BCD_DEVICE_WIFI_BT,
	  USB_TPT_BCD_DEVICE_WIFI_BT, USB_TPT_IF_NUMBER_WIFI) },
	{ USB_DEVICE_IF_SIGNATURE(USB_TPT_VENDOR_ID, USB_TPT_BCD_DEVICE_WIFI_BT,
	  USB_TPT_BCD_DEVICE_WIFI_BT, 2) },
	{ USB_DEVICE_IF_SIGNATURE(USB_TPT_VENDOR_ID, USB_TPT_BCD_DEVICE_WIFI_BT,
	  USB_TPT_BCD_DEVICE_WIFI_BT, 3) },
	// Wifi-only profile
	{ USB_DEVICE_IF_SIGNATURE(USB_TPT_VENDOR_ID, USB_TPT_BCD_DEVICE_WIFI,
	  USB_TPT_BCD_DEVICE_WIFI, USB_TPT_IF_NUMBER_WIFI) },
	// BT-only profile
	{ USB_DEVICE_IF_SIGNATURE(USB_TPT_VENDOR_ID, USB_TPT_BCD_DEVICE_BT,
	  USB_TPT_BCD_DEVICE_BT, 1) },
	{ USB_DEVICE_IF_SIGNATURE(USB_TPT_VENDOR_ID, USB_TPT_BCD_DEVICE_BT,
	  USB_TPT_BCD_DEVICE_BT, 2) },
	// BT-only device
	{ USB_DEVICE_INTERFACE_NUMBER(0x0cc4, 0x0001, 0) },
	{ USB_DEVICE_INTERFACE_NUMBER(0x0cc4, 0x0001, 1) },
	{ USB_DEVICE(0x0cc4, 0x0002) },
	{} /* Terminating entry */
};
MODULE_DEVICE_TABLE(usb, tpt_table);

/* Get a minor range for your devices from the usb maintainer */
#define USB_TPT_MINOR_BASE 192

#define ADDR_IN(addr) (((addr) & 0x80) == 0x80)
struct usb_tpt;

/* upstream protocol helper functions */
typedef u32 us_packet_descriptor;

enum us_packet_type {
	SINGLE_PACKET = 0,
	COPY_PACKET   = 1,
	RX_VECTOR     = 2
};

struct payload_header {
	u32 size;
	u32 index;
};

inline enum us_packet_type us_packet_type(us_packet_descriptor desc)
{
	return (enum us_packet_type)((BUS_TO_CPU32(desc) >> 24) & 0x3);
}

inline u8 us_packet_index(us_packet_descriptor desc)
{
	return (u8)(BUS_TO_CPU32(desc) >> 16);
}

inline u16 us_packet_size(us_packet_descriptor desc)
{
	return (u16)BUS_TO_CPU32(desc);
}

inline u16 us_container_count(void *chunk, size_t size)
{
	return (u16)(BUS_TO_CPU32(*(((u8 *)chunk) + size - 4)));
}

inline us_packet_descriptor *us_first_desc(void *chunk, size_t size)
{
	return (us_packet_descriptor *)(((u8 *)chunk) + size - 2
					* sizeof(us_packet_descriptor));
}

struct usb_tpt_ep {
	struct list_head               dev_list;
	struct usb_tpt                 *dev;
	struct usb_endpoint_descriptor desc;
	u8                             address;
	int                            payload_size;
	int                            chunk_size;
	int                            pad_size;
	int                            last_packet_chunks;
	int                            last_packet_size;
	int                            usb_packet_size;
	int                            usb_packet_chunks;
	int                            buffer_count;
	spinlock_t                     lock; /* lock for EP lists */
	struct list_head               urb_pool;
	struct usb_anchor              submitted;
	unsigned int                   sequence;
	int                            started;
	int                            wifi_transfer_remaining;
	struct usb_ctrlrequest         *cr;
};

/* Structure to hold all of our device specific stuff */
struct usb_tpt {
	struct usb_device    *udev;      /* the usb device for this device */
	struct usb_interface *interface; /* the interface for this device */
	struct kref          kref;
	struct mutex         io_mutex;  /* synchronize I/O with disconnect */
	unsigned long        disconnected : 1;

	struct tpt_parameter  param;
	struct tpt_statistics stats;
	struct list_head      out_eps;
	struct list_head      in_eps;
	struct usb_tpt_ep     *ep0;
	u32                   us_index;
	u32                   ds_index;

	struct tpt_start start_param;
	bool             running;
	ktime_t          start_time;
	__u64            packets_submitted;

	struct tasklet_struct buffer_submit_tasklet;
};

#define to_tpt_dev(d) container_of(d, struct usb_tpt, kref)

static struct usb_driver tpt_driver;

static void free_data_endpoints(struct usb_tpt *dev);
static int create_endpoints(struct usb_tpt *dev);

static void tpt_stream_callback(struct urb *urb);
static void tpt_stream_callback_idle(struct urb *urb);

static struct usb_tpt_ep *find_endpoint(struct list_head *eps,
					u8 address)
{
	struct usb_tpt_ep *ep;
	struct list_head *ep_it;

	for (ep_it = eps->next; ep_it != eps; ep_it = ep_it->next) {
		ep = list_entry(ep_it, struct usb_tpt_ep, dev_list);
		if (address == ep->address)
			return ep;
	}
	return NULL;
}

static struct scatterlist *sg_create_list(int *sg_count, size_t element_size,
					  const void *buffer, size_t size)
{
	size_t              i;
	size_t              chunk_size;
	char *ptr = (char *)buffer;
	struct scatterlist *sg;
	size_t              chunks = size / element_size;

	if (size % element_size)
		chunks++;

	*sg_count = 0;
	sg = kmalloc_array(chunks, sizeof(struct scatterlist), GFP_ATOMIC);
	if (sg) {
		struct scatterlist *sg_ptr = sg;
		*sg_count = chunks;
		sg_init_table(sg, chunks);

		for (i = 0; i < chunks; ++i) {
			chunk_size = min(size, element_size);
			sg_set_buf(sg_ptr++, (const void *)ptr, chunk_size);
			size -= chunk_size;
			ptr = ptr + chunk_size;
		}
	}
	return sg;
}

static void ep_free_buffer(struct usb_tpt_ep *ep)
{
	struct urb *urb;

	while (!list_empty(&ep->urb_pool)) {
		urb = list_entry(ep->urb_pool.next, struct urb, urb_list);
		list_del(&urb->urb_list);
		kfree(urb->transfer_buffer);
		kfree(urb->sg);
		usb_free_urb(urb);
	}
}

static void ep_last_packet_chunks_init(struct usb_tpt_ep *ep)
{
	ep->last_packet_chunks = 0;
	ep->last_packet_size = 0;
}

static void ep_init(struct usb_tpt_ep *ep, struct usb_tpt *dev,
		    struct usb_endpoint_descriptor *desc)
{
	memset(ep, 0, sizeof(struct usb_tpt_ep));
	INIT_LIST_HEAD(&ep->dev_list);
	ep->dev = dev;
	ep->desc = *desc;
	ep->address = desc->bEndpointAddress;
	ep_last_packet_chunks_init(ep);
	ep->usb_packet_size = usb_endpoint_maxp(&ep->desc);
	spin_lock_init(&ep->lock);
	INIT_LIST_HEAD(&ep->urb_pool);
	init_usb_anchor(&ep->submitted);
}

static void ep0_init(struct usb_tpt_ep *ep, struct usb_tpt *dev,
		     u16 bt_hci_if)
{
	struct usb_endpoint_descriptor desc;

	memset(&desc, 0, sizeof(desc));

	desc.bLength = USB_DT_ENDPOINT_SIZE;
	desc.bDescriptorType = USB_DT_ENDPOINT;
	desc.bEndpointAddress = 0;
	desc.bmAttributes = USB_ENDPOINT_XFER_CONTROL;

	ep_init(ep, dev, &desc);
	ep->cr = kmalloc(sizeof(*ep->cr), GFP_KERNEL);
	if (ep->cr) {
		memset(ep->cr, 0, sizeof(struct usb_ctrlrequest));
		ep->cr->bRequestType =
			(USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_DEVICE);
		ep->cr->wIndex = cpu_to_le16(bt_hci_if);
	}
}

static int ep_allocate_buffer(struct usb_tpt_ep *ep,
			      int chunk_count, int chunk_size, int buffer_count)
{
	int         retval = 0;
	struct urb *urb = NULL;
	char *buf = NULL;
	int         c;
	u16 mps = usb_endpoint_maxp(&ep->desc);

	ep_free_buffer(ep);
	ep->chunk_size = chunk_size;
	ep->pad_size = 0;
	if (!ADDR_IN(ep->address) && (ep->dev->param.flags & TPT_PARAM_FLAG_PAD_OUT_CHUNKS)) {
		if (ep->chunk_size % mps)
			ep->pad_size = mps - (ep->chunk_size % mps);
	}
	ep->payload_size = chunk_count * (ep->chunk_size + ep->pad_size);
	ep->buffer_count = buffer_count;
	ep->usb_packet_chunks = ep->dev->param.usb_packet_chunks;
	ep_last_packet_chunks_init(ep);
	ep->started = 0;
	ep->wifi_transfer_remaining = chunk_count;

	dev_info(&ep->dev->interface->dev,
		 "%s - EP[%02X] allocating %u buffer(s) of %u bytes (%u payload + %u pad bytes)",
		 __func__,
		 ep->address, ep->buffer_count, ep->payload_size,
		 ep->chunk_size, ep->pad_size);

	for (c = 0; c < ep->buffer_count; ++c) {
		urb = usb_alloc_urb(usb_endpoint_xfer_isoc(&ep->desc) ? 1 : 0,
				    GFP_KERNEL);
		if (!urb) {
			retval = -ENOMEM;
			goto error;
		}
		buf = kmalloc(ep->payload_size, GFP_KERNEL);
		if (!buf) {
			retval = -ENOMEM;
			goto error;
		}
		urb->transfer_buffer = buf;
		if (ep->dev->param.flags & TPT_PARAM_FLAG_NO_SG) {
			urb->transfer_buffer_length = ep->payload_size;
		} else {
			if (usb_device_no_sg_constraint(ep->dev->udev) &&
			    !usb_endpoint_xfer_isoc(&ep->desc)) {
				urb->sg = sg_create_list(&urb->num_sgs,
							 ep->chunk_size + ep->pad_size,
							 urb->transfer_buffer,
							 ep->payload_size);
			}
		}
		if (!ADDR_IN(ep->address) && (ep->dev->param.flags & TPT_PARAM_FLAG_ALWAYS_ZLP) &&
		    ((ep->payload_size % mps) == 0)) {
			urb->transfer_flags |= URB_ZERO_PACKET;
		}
		list_add_tail(&urb->urb_list, &ep->urb_pool);
		buf = NULL;
		urb = NULL;
	}
	return 0;

error:
	if (urb) {
		kfree(buf);
		usb_free_urb(urb);
	}
	ep_free_buffer(ep);
	return retval;
}

#if USE_DS_META
/* downstream protocol helper functions */
#define DS_MAGIC 0x474D5344 /* 'DSMG' */
#define DS_VERSION 1
#define DS_META_DESC_SIZE 1024
#define DS_MAX_PACKETS ((DS_META_DESC_SIZE \
			- sizeof(struct ds_metadata_desc)) \
			/ sizeof(struct ds_packet_desc))

struct ds_packet_desc {
	u32 packet_offset;
	u32 packet_size;
};

struct ds_metadata_desc {
	u32 magic;
	u32 version;
	u32 count;

	struct ds_packet_desc desc[1]; // variable size
};

struct ds_packet_desc *ds_init_meta_desc(struct ds_metadata_desc *desc,
					 u32 count)
{
	desc->magic = CPU_TO_BUS32(DS_MAGIC);
	desc->version = CPU_TO_BUS32(DS_VERSION);
	desc->count = CPU_TO_BUS32(count);
	return desc->desc;
}

static void ds_init_packet_desc(struct ds_packet_desc *desc, u32 offset, u32 size)
{
	desc->packet_offset = CPU_TO_BUS32(offset);
	desc->packet_size = CPU_TO_BUS32(size);
}

struct scatterlist *sg_ds_create_list(int *sg_count, size_t element_size,
				      const void *buffer, size_t size)
{
	size_t              i;
	size_t              chunk_size;
	char *ptr = (char *)buffer;
	struct scatterlist *sg;
	size_t              chunks;

	size -= DS_META_DESC_SIZE;
	chunks = size / element_size;
	if (size % element_size)
		chunks++;
	// for meta data
	chunks++;

	*sg_count = 0;
	sg = kmalloc_array(chunks, sizeof(struct scatterlist), GFP_ATOMIC);
	if (sg) {
		struct scatterlist *sg_ptr = sg;
		*sg_count = chunks;
		sg_init_table(sg, chunks);
		// meta data
		chunk_size = DS_META_DESC_SIZE;
		sg_set_buf(sg_ptr++, (const void *)ptr, chunk_size);
		ptr = ptr + chunk_size;

		for (i = 1; i < chunks; ++i) {
			chunk_size = min(size, element_size);
			sg_set_buf(sg_ptr++, (const void *)ptr, chunk_size);
			size -= chunk_size;
			ptr = ptr + chunk_size;
		}
	}
	return sg;
}

int ep_ds_allocate_buffer(struct usb_tpt_ep *ep, int chunk_count,
			  int chunk_size, int buffer_count)
{
	int         retval = 0;
	struct urb *urb = NULL;
	char *buf = NULL;
	int         c;

	ep_free_buffer(ep);
	ep->payload_size = chunk_count * chunk_size + DS_META_DESC_SIZE;
	ep->chunk_size = chunk_size;
	ep->buffer_count = buffer_count;
	ep->started = 0;

	for (c = 0; c < ep->buffer_count; ++c) {
		urb = usb_alloc_urb(usb_endpoint_xfer_isoc(&ep->desc) ? 1 : 0,
				    GFP_KERNEL);
		if (!urb) {
			retval = -ENOMEM;
			goto error;
		}
		buf = kmalloc(ep->payload_size, GFP_KERNEL);
		if (!buf) {
			retval = -ENOMEM;
			goto error;
		}
		urb->transfer_buffer = buf;

		if (usb_device_no_sg_constraint(ep->dev->udev) &&
		    !usb_endpoint_xfer_isoc(&ep->desc)) {
			urb->sg =
				sg_ds_create_list(&urb->num_sgs, chunk_size,
						  urb->transfer_buffer,
						  ep->payload_size);
		}
		list_add_tail(&urb->urb_list, &ep->urb_pool);
		buf = NULL;
		urb = NULL;
	}
	return 0;

error:
	if (urb) {
		kfree(buf);
		usb_free_urb(urb);
	}
	ep_free_buffer(ep);
	return retval;
}

void ep_ds_init_buffer(struct usb_tpt_ep *ep, int chunk_count, int chunk_size)
{
	struct urb            *urb;
	struct list_head      *urb_it;
	struct ds_packet_desc *packet_desc;
	int                   c;
	int                   i;
	unsigned char         *dst;
	u32                   offset;

	for (urb_it = ep->urb_pool.next;
		 urb_it != &ep->urb_pool;
		 urb_it = urb_it->next) {
		urb = list_entry(urb_it, struct urb, urb_list);
		dst = urb->transfer_buffer;
		dst += DS_META_DESC_SIZE;
		offset = DS_META_DESC_SIZE;
		packet_desc = ds_init_meta_desc(urb->transfer_buffer, chunk_count);
		for (c = 0; c < chunk_count; ++c) {
			ds_init_packet_desc(packet_desc++, offset, chunk_size);
			for (i = 0; i < chunk_size; ++i)
				*dst++ = (unsigned char)i;

			offset += chunk_size;
		}
	}
}
#endif

static int ep_submit_buffer(struct usb_tpt_ep *ep, struct urb *urb,
			    int transfer_length,
			    usb_complete_t completion_callback)
{
	struct usb_tpt *dev = ep->dev;
	int             ret;

	if (ADDR_IN(ep->address)) {
		if (usb_endpoint_xfer_bulk(&ep->desc)) {
			usb_fill_bulk_urb(urb, dev->udev,
					  usb_rcvbulkpipe(dev->udev, ep->address),
					  urb->transfer_buffer, transfer_length,
					  completion_callback,
					  ep);
		}
		if (usb_endpoint_xfer_int(&ep->desc)) {
			usb_fill_int_urb(urb, dev->udev,
					 usb_rcvintpipe(dev->udev, ep->address),
					 urb->transfer_buffer, transfer_length,
					 completion_callback,
					 ep,
					 ep->desc.bInterval);
		}
		if (usb_endpoint_xfer_isoc(&ep->desc)) {
			usb_fill_int_urb(urb,
					 dev->udev,
					 usb_rcvisocpipe(dev->udev, ep->address),
					 urb->transfer_buffer, transfer_length,
					 completion_callback,
					 ep,
					 ep->desc.bInterval);
			urb->transfer_flags |= URB_ISO_ASAP;
			urb->number_of_packets = 1;
			urb->iso_frame_desc[0].offset = 0;
			urb->iso_frame_desc[0].length = transfer_length;
			urb->iso_frame_desc[0].status = -1;
			urb->iso_frame_desc[0].actual_length = transfer_length;
		}

	} else {
		dev->stats.out_buffers_submitted++;
		if (usb_endpoint_xfer_control(&ep->desc)) {
			usb_fill_control_urb(urb,
					     dev->udev,
					     usb_sndctrlpipe(dev->udev, ep->address),
					     (unsigned char *)ep->cr,
					     urb->transfer_buffer, transfer_length,
					     completion_callback,
					     ep);
		}
		if (usb_endpoint_xfer_bulk(&ep->desc)) {
			usb_fill_bulk_urb(urb,
					  dev->udev,
					  usb_sndbulkpipe(dev->udev, ep->address),
					  urb->transfer_buffer, transfer_length,
					  completion_callback,
					  ep);
		}
		if (usb_endpoint_xfer_int(&ep->desc)) {
			usb_fill_int_urb(urb,
					 dev->udev,
					 usb_sndintpipe(dev->udev, ep->address),
					 urb->transfer_buffer, transfer_length,
					 completion_callback,
					 ep,
					 ep->desc.bInterval);
		}
		if (usb_endpoint_xfer_isoc(&ep->desc)) {
			usb_fill_int_urb(urb,
					 dev->udev,
					 usb_sndisocpipe(dev->udev, ep->address),
					 urb->transfer_buffer, transfer_length,
					 completion_callback,
					 ep,
					 ep->desc.bInterval);
			urb->transfer_flags |= URB_ISO_ASAP;
			urb->number_of_packets = 1;
			urb->iso_frame_desc[0].offset = 0;
			urb->iso_frame_desc[0].length = transfer_length;
			urb->iso_frame_desc[0].status = -1;
			urb->iso_frame_desc[0].actual_length = transfer_length;
		}
	}
	usb_anchor_urb(urb, &ep->submitted);
	ret = usb_submit_urb(urb, GFP_KERNEL);
	if (ret < 0)
		usb_unanchor_urb(urb);

	return ret;
}

static int ep_submit_buffer_idle(struct usb_tpt_ep *ep,
				 struct urb *urb,
				 int transfer_length,
				 usb_complete_t completion_callback)
{
	struct usb_tpt *dev = ep->dev;
	int             ret;

	if (ADDR_IN(ep->address)) {
		if (usb_endpoint_xfer_bulk(&ep->desc)) {
			usb_fill_bulk_urb(urb,
					  dev->udev,
					  usb_rcvbulkpipe(dev->udev, ep->address),
					  urb->transfer_buffer, transfer_length,
					  completion_callback,
					  ep);
		}
		if (usb_endpoint_xfer_int(&ep->desc)) {
			usb_fill_int_urb(urb,
					 dev->udev,
					 usb_rcvintpipe(dev->udev, ep->address),
					 urb->transfer_buffer, transfer_length,
					 completion_callback,
					 ep,
					 ep->desc.bInterval);
		}
		if (usb_endpoint_xfer_isoc(&ep->desc)) {
			usb_fill_int_urb(urb,
					 dev->udev,
					 usb_rcvisocpipe(dev->udev, ep->address),
					 urb->transfer_buffer, transfer_length,
					 completion_callback,
					 ep,
					 ep->desc.bInterval);
			urb->transfer_flags |= URB_ISO_ASAP;
			urb->number_of_packets = 1;
			urb->iso_frame_desc[0].offset = 0;
			urb->iso_frame_desc[0].length = transfer_length;
			urb->iso_frame_desc[0].status = -1;
			urb->iso_frame_desc[0].actual_length = transfer_length;
		}

	} else {
		if (usb_endpoint_xfer_control(&ep->desc)) {
			usb_fill_control_urb(urb,
					     dev->udev,
					     usb_sndctrlpipe(dev->udev, ep->address),
					     (unsigned char *)ep->cr,
					     urb->transfer_buffer, transfer_length,
					     completion_callback,
					     ep);
		}
		if (usb_endpoint_xfer_bulk(&ep->desc)) {
			usb_fill_bulk_urb(urb,
					  dev->udev,
					  usb_sndbulkpipe(dev->udev, ep->address),
					  urb->transfer_buffer, transfer_length,
					  completion_callback,
					  ep);
		}
		if (usb_endpoint_xfer_int(&ep->desc)) {
			usb_fill_int_urb(urb,
					 dev->udev,
					 usb_sndintpipe(dev->udev, ep->address),
					 urb->transfer_buffer, transfer_length,
					 completion_callback,
					 ep,
					 ep->desc.bInterval);
		}
		if (usb_endpoint_xfer_isoc(&ep->desc)) {
			usb_fill_int_urb(urb,
					 dev->udev,
					 usb_sndisocpipe(dev->udev, ep->address),
					 urb->transfer_buffer, transfer_length,
					 completion_callback,
					 ep,
					 ep->desc.bInterval);
			urb->transfer_flags |= URB_ISO_ASAP;
			urb->number_of_packets = 1;
			urb->iso_frame_desc[0].offset = 0;
			urb->iso_frame_desc[0].length = transfer_length;
			urb->iso_frame_desc[0].status = -1;
			urb->iso_frame_desc[0].actual_length = transfer_length;
		}
	}
	usb_anchor_urb(urb, &ep->submitted);
	ret = usb_submit_urb(urb, GFP_KERNEL);
	if (ret < 0)
		usb_unanchor_urb(urb);

	return ret;
}

static void add_crc(struct usb_tpt_ep *ep, void *buffer, size_t size)
{
	if (!ADDR_IN(ep->address) && size > 4) {
		u32 crc;
		u8 *crc_ptr = buffer;

		crc_ptr += size - 4;
		crc = crc32(0xffffffff, buffer, size - 4) ^ 0xffffffff;
		*((u32 *)crc_ptr) = crc;
	}
}

static void ep_last_packet_chunks_update(struct usb_tpt_ep *ep, int added_size)
{
	int new_size = ep->last_packet_size + added_size;

	if (new_size == ep->usb_packet_size) {
		ep->last_packet_chunks = 0;
		ep->last_packet_size = 0;
	} else if (new_size > ep->usb_packet_size) {
		ep->last_packet_chunks = 1;
		ep->last_packet_size = new_size & (ep->usb_packet_size - 1);
	} else {
		ep->last_packet_chunks++;
		ep->last_packet_size += added_size;
	}
}

static int ep_submit_buffers(struct usb_tpt_ep *ep)
{
	struct usb_tpt *dev = ep->dev;
	int             retval = 0;
	unsigned long   flags;
	struct urb	*urb;
	int             transfer_length = ep->payload_size;

	if (dev->disconnected || !dev->running)
		return -ENODEV;

	ep->started = 1;
	for (;;) {
		size_t   pos;
		u8 *ptr;

		spin_lock_irqsave(&ep->lock, flags);
		if (list_empty(&ep->urb_pool)) {
			urb = NULL;
		} else {
			urb = list_entry(ep->urb_pool.next, struct urb, urb_list);
			list_del(&urb->urb_list);
		}
		spin_unlock_irqrestore(&ep->lock, flags);
		if (!urb)
			break;
		if (!ADDR_IN(ep->address)) {
			ptr = urb->transfer_buffer;
			if (dev->param.flags & TPT_PARAM_FLAG_NO_TRANSFER_SPLIT) {
				ep_last_packet_chunks_init(ep);
				if (urb->sg) {
					sg_init_table(urb->sg, dev->param.chunk_count);
					urb->num_sgs = 0;
				}
			}
			transfer_length = 0;
			for (pos = 0;
			     pos < ep->payload_size;
			     pos += ep->chunk_size + ep->pad_size) {
				if (dev->param.verify_content) {
					u16    *dst = (u16 *)(ptr + pos);
					size_t i;
					struct payload_header *header;

					for (i = 0; i < ep->chunk_size / 2; ++i)
						*dst++ = (u16)i;
					header = (struct payload_header *)(ptr + pos);
					header->size = ep->chunk_size;
					header->index = dev->ds_index++;
					add_crc(ep, ptr + pos, ep->chunk_size);
				}
				if (dev->param.flags & TPT_PARAM_FLAG_NO_TRANSFER_SPLIT) {
					if (urb->sg) {
						sg_set_buf(&urb->sg[urb->num_sgs],
							   ptr + pos,
							   ep->chunk_size + ep->pad_size);
						urb->num_sgs++;
					}
				}
				transfer_length += ep->chunk_size + ep->pad_size;

				dev->packets_submitted++;
				if (dev->param.packets_to_transfer > 0 &&
				    dev->packets_submitted >= dev->param.packets_to_transfer) {
					dev->running = false;
					break;
				}

				ep->wifi_transfer_remaining--;
				if (ep->wifi_transfer_remaining <= 0) {
					ep->wifi_transfer_remaining = dev->param.chunk_count;
					break;
				}

				if (dev->param.flags & TPT_PARAM_FLAG_NO_TRANSFER_SPLIT) {
					ep_last_packet_chunks_update(ep, ep->chunk_size);
					if (ep->last_packet_chunks >= ep->usb_packet_chunks)
						break;
				}
			}
			if (dev->param.flags & TPT_PARAM_FLAG_NO_TRANSFER_SPLIT) {
				if (urb->sg && urb->num_sgs)
					sg_mark_end(&urb->sg[urb->num_sgs - 1]);
			}
		}
		retval = ep_submit_buffer(ep, urb, transfer_length, tpt_stream_callback);
		if (retval != 0)
			break;
		if (!dev->running)
			break;
	}
	return retval;
}

static void ep_submit_buffers_task(unsigned long ep)
{
	ep_submit_buffers((struct usb_tpt_ep *)ep);
}

static int ep_submit_buffers_idle(struct usb_tpt_ep *ep,
				  usb_complete_t completion_callback)
{
	struct usb_tpt *dev = ep->dev;
	int               retval = 0;
	unsigned long     flags;
	struct urb *urb = NULL;
	struct payload_header *header;
	int               transfer_length = ep->payload_size;

	if (dev->disconnected || !dev->running)
		return -ENODEV;

	ep->started = 1;
	for (;;) {
		size_t   pos;
		u8 *ptr;

		spin_lock_irqsave(&ep->lock, flags);
		if (list_empty(&ep->urb_pool) || retval < 0) {
			spin_unlock_irqrestore(&ep->lock, flags);
			return retval;
		}
		urb = list_entry(ep->urb_pool.next, struct urb, urb_list);
		list_del(&urb->urb_list);
		spin_unlock_irqrestore(&ep->lock, flags);
		if (!ADDR_IN(ep->address)) {
			ptr = urb->transfer_buffer;
			for (pos = 0; pos < ep->payload_size; pos += ep->chunk_size) {
				u16 *dst = (u16 *)(ptr + pos);
				size_t    i;

				for (i = 0; i < ep->chunk_size / 2; ++i)
					*dst++ = (u16)i;
				header = (struct payload_header *)(ptr + pos);
				header->size = ep->chunk_size;
				header->index = dev->ds_index++;
				add_crc(ep, ptr + pos, ep->chunk_size);
			}
		}
		retval = ep_submit_buffer_idle(ep, urb, transfer_length, completion_callback);
		if (!dev->running)
			break;
	}
	return retval;
}

static void ep_stop(struct usb_tpt_ep *ep)
{
	if (ep->started) {
		int timeout;

		dev_info(&ep->dev->interface->dev, "%s - stopping EP[%02X]",
			 __func__, ep->address);
		ep->started = 0;
		timeout = usb_wait_anchor_empty_timeout(&ep->submitted, 1000);
		if (!timeout)
			usb_kill_anchored_urbs(&ep->submitted);
	}
}

int set_device_params(struct usb_tpt *dev,
		      enum tpt_buffer_mode mode, bool verify)
{
	u16 value = cpu_to_le16((verify ? 1 : 0) << 8 | mode);

	struct tpt_cfg_params *params;
	int                    ret = -1;

	params = kmalloc(sizeof(*params), GFP_KERNEL);
	if (params) {
		params->out_ep = dev->param.out_ep;
		params->in_ep = dev->param.in_ep;
		ret = usb_control_msg(dev->udev,
				      usb_sndctrlpipe(dev->udev, 0),
						      TPT_PARAMS_REQ,
						      (USB_DIR_OUT | USB_TYPE_VENDOR
						       | USB_RECIP_INTERFACE),
						      value,
						      cpu_to_le16(USB_TPT_IF_NUMBER_WIFI),
						      params,
						      sizeof(struct tpt_cfg_params),
						      REQ_TIMEOUT);
		kfree(params);
	}
	return ret;
}

int get_device_statistics(struct usb_tpt *dev,
			  struct tpt_device_statistic *stats)
{
	int                         ret = -1;
	u16                         value;
	struct tpt_device_statistic *dev_stats;

	dev_stats = kmalloc(sizeof(*dev_stats), GFP_KERNEL);
	if (dev_stats) {
		value = (dev->param.out_ep) ? 0 : 1;
		memset(dev_stats, 0, sizeof(struct tpt_device_statistic));
		ret = usb_control_msg(dev->udev,
				      usb_rcvctrlpipe(dev->udev, 0),
						      TPT_STATS_REQ,
						      (USB_DIR_IN | USB_TYPE_VENDOR
						       | USB_RECIP_INTERFACE),
						      value,
						      cpu_to_le16(USB_TPT_IF_NUMBER_WIFI),
						      dev_stats,
						      sizeof(struct tpt_device_statistic),
						      REQ_TIMEOUT);
		if (ret > 0) {
			memcpy(stats, dev_stats, sizeof(struct tpt_device_statistic));
			dev_info(&dev->interface->dev,
				 "%s: rt:%llu bytes:%u cont-errors:%u xfer-error:%u",
				 __func__,
				 stats->runtime_us, stats->bytes,
				 stats->content_error, stats->transfer_error);
		}
		kfree(dev_stats);
	}
	return ret;
}

static int verify_raw_content(struct usb_tpt *dev, void *data, size_t size)
{
	u32 crc;
	u8 *packet = (u8 *)data;

	if (dev->param.verify_content) {
		crc = crc32(0xffffffff, packet, size - 4) ^ 0xffffffff;
		if (crc != *(u32 *)(packet + (size - 4))) {
			dev_err(&dev->interface->dev, " RX invalid crc: 0x%08x, 0x%08x",
				crc, *(u32 *)(packet + (size - 4)));
			return 1;
		}
	}
	return 0;
}

static int verify_stream_content(struct usb_tpt *dev, void *data, size_t size)
{
	u8 *ptr = (u8 *)data;
	size_t   chunks = size / dev->param.chunk_size;
	size_t   i;

	if (size % dev->param.chunk_size != 0) {
		dev_err(&dev->interface->dev,
			"RX invalid buffer size: %zu at expected index %d",
				size, dev->us_index);
		return 1;
	}
	for (i = 0; i < chunks; ++i) {
		u16 containers = us_container_count(ptr, dev->param.chunk_size);
		u16 c;
		u32 crc;
		us_packet_descriptor *desc = us_first_desc(ptr, dev->param.chunk_size);
		u8 *packet = ptr;
		s32 remaining_size = dev->param.chunk_size;
		struct payload_header *header;

		for (c = 0; c < containers; ++c, --desc) {
			enum us_packet_type type = us_packet_type(*desc);
			u16 packet_size = us_packet_size(*desc);

			if (packet_size > remaining_size) {
				dev_err(&dev->interface->dev, "RX invalid packet size: %d",
					packet_size);
				return 1;
			}
			if (dev->param.verify_content) {
				crc = crc32(0xffffffff, packet, packet_size - 4) ^ 0xffffffff;
				if (crc != *(u32 *)(packet + (packet_size - 4))) {
					dev_err(&dev->interface->dev, "RX invalid crc: 0x%08x, 0x%08x",
						crc, *(u32 *)(packet + (packet_size - 4)));
					return 1;
				}
				header = (struct payload_header *)packet;
				if (header->size != packet_size) {
					dev_err(&dev->interface->dev,
						"RX invalid packet size: header: %d, meta:%d",
						header->size, packet_size);
					return 1;
				}
				if (header->index != dev->us_index) {
					if (dev->us_index == 0) { // first packet to synchronize
						dev->us_index = header->index;
					} else {
						dev_err(&dev->interface->dev,
							"RX invalid packet index: header: %d, dev:%d",
							header->index, dev->us_index);
						return 1;
					}
				}
				dev->us_index++;
			}

			switch (type) {
			case SINGLE_PACKET:
				break;
			case COPY_PACKET:
				break;
			case RX_VECTOR:
				break;
			default:
				dev_err(&dev->interface->dev,
					"RX invalid container type: %d in chunk %zu at desc: %d",
					(int)type, i, c);
				return 1;
			}
			dev->stats.packets_transferred++;
			if (dev->param.packets_to_transfer > 0 &&
			    dev->stats.packets_transferred >=
				 dev->param.packets_to_transfer) {
				dev->running = false;
			}
			dev->stats.payload_data += packet_size;
			packet += packet_size;
			remaining_size -= packet_size;
		}
		ptr += dev->param.chunk_size;
	}
	return 0;
}

static void tpt_stream_callback(struct urb *urb)
{
	struct usb_tpt_ep *ep = urb->context;
	struct usb_tpt *dev = ep->dev;
	unsigned long          flags;
	struct tpt_statistics *stats = &dev->stats;
	struct tpt_parameter *param = &dev->param;

	if (!ADDR_IN(ep->address))
		dev->stats.out_buffers_completed++;

	if (urb->status) {
		dev_err(&dev->interface->dev, "%s - USB transfer error: %d",
			__func__, urb->status);
		if (!((urb->status == -ENOENT) ||
		      (urb->status == -ECONNRESET) ||
			  (urb->status == -ESHUTDOWN))) {
			stats->last_urb_error = urb->status;
			stats->transfer_error++;
		}

		spin_lock_irqsave(&ep->lock, flags);
		list_add_tail(&urb->urb_list, &ep->urb_pool);
		spin_unlock_irqrestore(&ep->lock, flags);

	} else {
		if (param->in_ep) {
			if (dev->start_param.raw_packets) {
				stats->payload_data += urb->actual_length;
				stats->packets_transferred += urb->actual_length / ep->chunk_size;
				if (verify_raw_content(dev, urb->transfer_buffer,
						       urb->actual_length)) {
					stats->content_error++;
				}
			} else {
				if (verify_stream_content(dev, urb->transfer_buffer,
							  urb->actual_length)) {
					stats->content_error++;
				}
			}
		} else {
			stats->packets_transferred +=
				urb->actual_length / (ep->chunk_size + ep->pad_size);
			stats->payload_data +=
				(urb->actual_length / (ep->chunk_size + ep->pad_size)) *
				ep->chunk_size;
		}

		spin_lock_irqsave(&ep->lock, flags);
		list_add_tail(&urb->urb_list, &ep->urb_pool);
		spin_unlock_irqrestore(&ep->lock, flags);

		if (ep->started)
			tasklet_schedule(&dev->buffer_submit_tasklet);
	}
}

static void tpt_stream_callback_idle(struct urb *urb)
{
	struct usb_tpt_ep *ep = urb->context;
	unsigned long flags;

	spin_lock_irqsave(&ep->lock, flags);
	list_add_tail(&urb->urb_list, &ep->urb_pool);
	spin_unlock_irqrestore(&ep->lock, flags);

	if (!urb->status) {
		ep_submit_buffers_idle(ep, tpt_stream_callback_idle);
	} else {
		dev_err(&ep->dev->interface->dev, "%s - USB transfer error: %d",
			__func__, urb->status);
	}
}

static int tpt_set_alternate_setting(struct usb_tpt *dev,
				     struct tpt_alternate_setting *as)
{
	int retval = 0;

	free_data_endpoints(dev);

	retval =
		usb_set_interface(dev->udev,
				  dev->interface->cur_altsetting->desc.bInterfaceNumber,
						 as->alt_setting);
	if (retval < 0)
		dev_info(&dev->interface->dev,
			 "usb_set_interface(alt_setting = %d) fails with status %d",
				 as->alt_setting,
				 retval);

	create_endpoints(dev);

	return retval;
}

static int tpt_start(struct usb_tpt *dev)
{
	int                   retval = 0;
	struct usb_tpt_ep     *ep = NULL;
	struct tpt_parameter  *param;

	memset(&dev->stats, 0, sizeof(dev->stats));
	dev->us_index = 0;
	dev->ds_index = 0;

	if (dev->start_param.alt_setting >= 0) {
		u8 if_nb = dev->interface->cur_altsetting->desc.bInterfaceNumber;

		free_data_endpoints(dev);

		if (dev->start_param.alt_setting ==
			 dev->interface->cur_altsetting->desc.bAlternateSetting &&
			dev->start_param.alt_setting == 1) {
			retval = usb_set_interface(dev->udev, if_nb, 0);
			if (retval < 0) {
				dev_err(&dev->interface->dev,
					"usb_set_interface(%u, 0) fails with status %d",
					if_nb, retval);
				return retval;
			}
		}

		dev_info(&dev->interface->dev,
			 "%s: cur alt_setting: %d new alt_setting: %d",
				 __func__,
				 dev->interface->cur_altsetting->desc.bAlternateSetting,
				 dev->start_param.alt_setting);
		if (dev->start_param.alt_setting !=
		   dev->interface->cur_altsetting->desc.bAlternateSetting) {
			retval = usb_set_interface(dev->udev, if_nb,
						   dev->start_param.alt_setting);
			if (retval < 0) {
				dev_err(&dev->interface->dev,
					"usb_set_interface(%u, %d) fails with status %d",
					if_nb, dev->start_param.alt_setting, retval);
				return retval;
			}
		}
		create_endpoints(dev);
	}

	if (dev->start_param.mode != 0xff) {
		retval = set_device_params(dev,
					   dev->start_param.mode,
					   dev->param.verify_content != 0);
		if (retval < 0) {
			dev_err(&dev->interface->dev, "set_device_params fails with status %d",
				retval);
			return retval;
		}
	}

	param = &dev->param;
	if (param->in_ep) {
		ep = find_endpoint(&dev->in_eps, param->in_ep);
		if (!ep) {
			dev_err(&dev->interface->dev, "No IN endpoint with number 0x%02x",
				param->in_ep);
			return -EPIPE;
		}
		ep_allocate_buffer(ep, param->chunk_count, param->chunk_size,
				   param->buffer_count);
	}
	if (param->out_ep) {
		ep = find_endpoint(&dev->out_eps, param->out_ep);
		if (!ep) {
			dev_err(&dev->interface->dev, "No OUT endpoint with number 0x%02x",
				param->out_ep);
			return -EPIPE;
		}
#if USE_DS_META
		ep_ds_allocate_buffer(ep,
				      param->chunk_count, param->chunk_size,
				      param->buffer_count);
		ep_ds_init_buffer(ep, param->chunk_count, param->chunk_size);
#else
		ep_allocate_buffer(ep,
				   param->chunk_count, param->chunk_size,
				   param->buffer_count);
#endif
	}
	if (!param->in_ep && !param->out_ep) {
		ep = dev->ep0;
		if (!ep) {
			dev_err(&dev->interface->dev, "No EP0");
			return -EPIPE;
		}
		ep_allocate_buffer(ep,
				   param->chunk_count, param->chunk_size,
				   param->buffer_count);
		ep->cr->wLength = cpu_to_le16(param->chunk_count * param->chunk_size);
	}

	dev->running = true;
	dev->packets_submitted = 0;
	dev->start_time = ktime_get();

	tasklet_init(&dev->buffer_submit_tasklet, ep_submit_buffers_task, (unsigned long)ep);
	if (dev->param.in_ep) {
		ep = find_endpoint(&dev->in_eps, dev->param.in_ep);
		tasklet_schedule(&dev->buffer_submit_tasklet);
	}
	if (dev->param.out_ep) {
		ep = find_endpoint(&dev->out_eps, dev->param.out_ep);
		tasklet_schedule(&dev->buffer_submit_tasklet);
	}
	if (!dev->param.in_ep && !dev->param.out_ep) {
		ep = dev->ep0;
		if (!ep) {
			dev_err(&dev->interface->dev, "No EP0");
			return -EPIPE;
		}
		tasklet_schedule(&dev->buffer_submit_tasklet);
	}

	if ((dev->param.flags & TPT_PARAM_FLAG_SCHEDULE_UNUSED_EPS) &&
	    (dev->param.in_ep || dev->param.out_ep)) {
		s32 ep_num;

		for (ep_num = 1; ep_num <= 15; ep_num++) {
			if (ep_num == dev->param.out_ep)
				continue;
			ep = find_endpoint(&dev->out_eps, ep_num);

			if (ep) {
				ep_allocate_buffer(ep,
						   param->chunk_count,
						   param->chunk_size,
						   param->buffer_count);
				ep_submit_buffers_idle(ep, tpt_stream_callback_idle);
				dev_info(&dev->interface->dev, "schedule additional EP%02X",
					 ep_num);
			}
		}
		for (ep_num = 0x81; ep_num <= 0x8F; ep_num++) {
			if (ep_num == dev->param.in_ep)
				continue;
			ep = find_endpoint(&dev->in_eps, ep_num);
			if (ep) {
				ep_allocate_buffer(ep,
						   param->chunk_count,
						   param->chunk_size,
						   param->buffer_count);
				ep_submit_buffers_idle(ep, tpt_stream_callback_idle);
				dev_info(&dev->interface->dev, " schedule additional EP%02X",
					 ep_num);
			}
		}
	}

	return 0;
}

static void stop_device(struct usb_tpt *dev)
{
	int               i;
	struct list_head  *eps;
	struct usb_tpt_ep *ep;
	struct list_head  *ep_it;

	tasklet_kill(&dev->buffer_submit_tasklet);

	for (i = 0; i < 2; ++i) {
		eps = i ? &dev->in_eps : &dev->out_eps;
		for (ep_it = eps->next; ep_it != eps; ep_it = ep_it->next) {
			ep = list_entry(ep_it, struct usb_tpt_ep, dev_list);
			ep_stop(ep);
		}
	}

	if (dev->interface->cur_altsetting->desc.bAlternateSetting != 0) {
		int retval = 0;

		free_data_endpoints(dev);
		retval = usb_set_interface(dev->udev,
					   dev->interface->cur_altsetting->desc.bInterfaceNumber,
					   0);
		if (retval < 0)
			dev_err(&dev->interface->dev,
				"%s - usb_set_interface(%u, 0) fails with status %d",
				__func__,
				dev->interface->cur_altsetting->desc.bInterfaceNumber, retval);
		create_endpoints(dev);
	}
	dev_info(&dev->interface->dev, "%s - done", __func__);
}

static void free_ep_buffers(struct usb_tpt *dev)
{
	int               i;
	struct list_head  *eps;
	struct usb_tpt_ep *ep;
	struct list_head  *ep_it;

	for (i = 0; i < 2; ++i) {
		eps = i ? &dev->in_eps : &dev->out_eps;
		for (ep_it = eps->next; ep_it != eps; ep_it = ep_it->next) {
			ep = list_entry(ep_it, struct usb_tpt_ep, dev_list);
			ep_free_buffer(ep);
		}
	}
}

static void free_data_endpoints(struct usb_tpt *dev)
{
	int               i;
	struct list_head  *eps;
	struct usb_tpt_ep *ep;

	for (i = 0; i < 2; ++i) {
		eps = i ? &dev->in_eps : &dev->out_eps;
		while (!list_empty(eps)) {
			ep = list_entry(eps->next, struct usb_tpt_ep, dev_list);
			list_del(&ep->dev_list);
			kfree(ep);
		}
	}
}

static void free_endpoints(struct usb_tpt *dev)
{
	struct usb_tpt_ep *ep;

	free_data_endpoints(dev);

	if (dev->ep0) {
		ep = dev->ep0;
		dev->ep0 = 0;
		kfree(ep->cr);
		kfree(ep);
	}
}

static int tpt_stop(struct usb_tpt *dev)
{
	ktime_t stop_time;

	stop_time = ktime_get();
	dev->running = false;
	dev->stats.runtime = ktime_to_ns(ktime_sub(stop_time, dev->start_time));

	stop_device(dev);
	free_ep_buffers(dev);

	return 0;
}

static long tpt_ioctl(struct file *file,
		      unsigned int cmd, unsigned long arg)
{
	struct usb_tpt *dev;
	const struct device *dev_base;
	int             retval;

	dev = file->private_data;
	dev_base = &dev->interface->dev;
	retval = 0;

	switch (cmd) {
	case TPT_SET_PARAMETER:
	{
		retval = copy_from_user(&dev->param,
					(void *)arg, sizeof(struct tpt_parameter));
		if (!retval) {
			dev_info(dev_base,
				 "%s - SET_PARAMETER: iep:%02X oep:%02x",
				 __func__,
				 dev->param.in_ep,
				 dev->param.out_ep);
			dev_info(dev_base,
				 "%s - SET_PARAMETER: cs:%u cc:%u #pkt:%u bc:%u v:%u u:%u f:0x%08x",
				 __func__,
				 dev->param.chunk_size,
				 dev->param.chunk_count,
				 dev->param.packets_to_transfer,
				 dev->param.buffer_count,
				 dev->param.verify_content,
				 dev->param.usb_packet_chunks,
				 dev->param.flags);
		}
	}
	break;
	case TPT_START:
	{
		retval = copy_from_user(&dev->start_param,
					(void *)arg, sizeof(struct tpt_start));
		if (!retval) {
			dev_info(dev_base,
				 "%s - START: as:%d mode:%d rt:%u rp:%u",
				 __func__,
				 dev->start_param.alt_setting,
				 dev->start_param.mode,
				 dev->start_param.runtime,
				 dev->start_param.raw_packets);
			retval = tpt_start(dev);
		}
	}
	break;
	case TPT_STOP:
		dev_info(dev_base, "%s - STOP", __func__);
		retval = tpt_stop(dev);
		break;
	case TPT_KEEP_ALIVE:
		dev_info(dev_base, "%s - KEEP_ALIVE", __func__);
		break;
	case TPT_GET_STATISTICS:
	{
		retval =
			copy_to_user((void *)arg, &dev->stats, sizeof(struct tpt_statistics));
	}
	break;
	case TPT_GET_STATUS:
	{
		struct tpt_status tpt_status;
		bool              running = dev->running;

		if (dev->param.out_ep) {
			struct usb_tpt_ep *ep =
				find_endpoint(&dev->out_eps, dev->param.out_ep);
			if (ep && dev->param.packets_to_transfer > 0 &&
			    !usb_anchor_empty(&ep->submitted)) {
				running = true;
			}
		}
		tpt_status.is_running = running ? 1 : 0;
		retval = copy_to_user((void *)arg,
				      &tpt_status, sizeof(struct tpt_status));
	}
	break;
	case TPT_ENDPOINT_RESET:
	{
		u8 old_alt;
		u8 if_nb = dev->interface->cur_altsetting->desc.bInterfaceNumber;

		dev_info(dev_base, "%s - ENDPOINT_RESET", __func__);
		if (dev->running)
			retval = tpt_stop(dev);
		old_alt = dev->interface->cur_altsetting->desc.bAlternateSetting;
		retval =
			usb_set_interface(dev->udev, if_nb, (old_alt == 0) ? 1 : 0);
		if (!retval)
			retval = usb_set_interface(dev->udev, if_nb, old_alt);
	}
	break;
	case TPT_GET_DEV_STATISTIC:
	{
		struct tpt_device_statistic dev_stat;

		retval = get_device_statistics(dev, &dev_stat);
		if (retval > 0) {
			retval =
				copy_to_user((void *)arg, &dev_stat,
					     sizeof(struct tpt_device_statistic));
		}
	}
	break;
	case TPT_SET_ALT_SETTING:
	{
		struct tpt_alternate_setting as;

		retval = copy_from_user(&as,
					(void *)arg, sizeof(struct tpt_alternate_setting));
		if (!retval) {
			dev_info(dev_base, "%s - SET_ALT_SETTING: %d",
				 __func__, as.alt_setting);
			retval = tpt_set_alternate_setting(dev, &as);
		} else {
			dev_err(dev_base,
				"%s - SET_ALT_SETTING: copy_from_user failed (%d)",
				__func__, retval);
		}
	}
	break;
	default:
		return -ENOTTY;
	}

	if (retval != 0) {
		dev_err(dev_base, "%s - CMD 0x%08X failed with %d",
			__func__, cmd, retval);
	}
	return retval;
}

static void tpt_delete(struct kref *kref)
{
	struct usb_tpt *dev = to_tpt_dev(kref);

	usb_put_intf(dev->interface);
	usb_put_dev(dev->udev);
	kfree(dev);
}

static int tpt_open(struct inode *inode, struct file *file)
{
	struct usb_tpt *dev;
	struct usb_interface *interface;
	int                   subminor;
	int                   retval = 0;

	subminor = iminor(inode);

	interface = usb_find_interface(&tpt_driver, subminor);
	if (!interface) {
		pr_err("%s - error, can't find device for minor %d\n",
		       __func__, subminor);
		retval = -ENODEV;
		goto exit;
	}

	dev = usb_get_intfdata(interface);
	if (!dev) {
		retval = -ENODEV;
		goto exit;
	}

	retval = usb_autopm_get_interface(interface);
	if (retval)
		goto exit;

	/* increment our usage count for the device */
	kref_get(&dev->kref);

	/* save our object in the file's private structure */
	file->private_data = dev;

exit:
	return retval;
}

static int tpt_release(struct inode *inode, struct file *file)
{
	struct usb_tpt *dev;

	dev = file->private_data;
	if (!dev)
		return -ENODEV;

	stop_device(dev);

	/* allow the device to be autosuspended */
	usb_autopm_put_interface(dev->interface);

	/* decrement the count on our device */
	kref_put(&dev->kref, tpt_delete);
	return 0;
}

static const struct file_operations tpt_fops = {
	.owner          = THIS_MODULE,
	.unlocked_ioctl = tpt_ioctl,
	.open           = tpt_open,
	.release        = tpt_release
};

/*
 * usb class driver info in order to get a minor number from the usb core,
 * and to have the device registered with the driver core
 */
static struct usb_class_driver tpt_class = {
	.name       = "usbtpt%d",
	.fops       = &tpt_fops,
	.minor_base = USB_TPT_MINOR_BASE,
};

static int create_endpoints(struct usb_tpt *dev)
{
	int                            i;
	struct usb_host_interface      *iface_desc;
	struct usb_endpoint_descriptor *endpoint;
	struct usb_tpt_ep              *ep;

	/* create the endpoints */
	iface_desc = dev->interface->cur_altsetting;
	dev_info(&dev->interface->dev, "%s: bNumEndpoints: %d",
		 __func__, iface_desc->desc.bNumEndpoints);
	for (i = 0; i < iface_desc->desc.bNumEndpoints; ++i) {
		endpoint = &iface_desc->endpoint[i].desc;
		//dev_info(&dev->interface->dev,
		//	   "tpt_probe: find ep: %02x", endpoint->bEndpointAddress);
		ep = kmalloc(sizeof(*ep), GFP_KERNEL);
		if (!ep)
			return -ENOMEM;
		ep_init(ep, dev, endpoint);
		if (usb_endpoint_dir_in(endpoint)) {
			//dev_info(&dev->interface->dev, "
			//	   tpt_probe: add ep: %02x to IN list",
			// endpoint->bEndpointAddress);
			list_add_tail(&ep->dev_list, &dev->in_eps);
		} else {
			//dev_info(&dev->interface->dev,
			//	   "tpt_probe: add ep: %02x to OUT list",
			// endpoint->bEndpointAddress);
			list_add_tail(&ep->dev_list, &dev->out_eps);
		}
	}
	return 0;
}

static int tpt_probe(struct usb_interface *interface,
		     const struct usb_device_id *id)
{
	struct usb_tpt    *dev;
	int               retval;
	struct usb_tpt_ep *ep;
	struct usb_device *udev = usb_get_dev(interface_to_usbdev(interface));
	u16               bt_hci_if = 0xFFFF;
	u16               vid = id->idVendor;
	u16               pid = udev->descriptor.idProduct;
	u16               bcd = id->bcdDevice_lo;

	if (vid == USB_TPT_VENDOR_ID) {
		if (!tpt_is_pid_supported(pid)) {
			dev_info(&interface->dev, "%s: checking for PID=%04X", __func__, tpt_pid);
			dev_info(&interface->dev, "%s: ignoring VID=%04X PID=%04X BCD %04X",
				 __func__, vid, pid, bcd);
			return 0;
		}
	}

	dev_info(&interface->dev, "%s: VID=%04X PID=%04X BCD %04X", __func__, vid, pid, bcd);

	if (vid == USB_TPT_VENDOR_ID) {
		if (bcd == USB_TPT_BCD_DEVICE_WIFI_BT)
			bt_hci_if = USB_TPT_IF_NUMBER_WIFI + 1;
		else if (pid == USB_TPT_BCD_DEVICE_BT)
			bt_hci_if = 1;
	} else if (vid == 0x0cc4) {
		bt_hci_if = 0;
	}

	/* allocate memory for our device state and initialize it */
	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return -ENOMEM;

	kref_init(&dev->kref);
	mutex_init(&dev->io_mutex);
	INIT_LIST_HEAD(&dev->out_eps);
	INIT_LIST_HEAD(&dev->in_eps);
	memset(&dev->stats, 0, sizeof(dev->stats));
	memset(&dev->param, 0, sizeof(dev->param));

	dev->udev = usb_get_dev(interface_to_usbdev(interface));
	dev->interface = usb_get_intf(interface);

	retval = create_endpoints(dev);
	if (retval)
		goto error;

	if (bt_hci_if != 0xFFFF) {
		ep = kmalloc(sizeof(*ep), GFP_KERNEL);
		if (!ep) {
			retval = -ENOMEM;
			goto error;
		}
		ep0_init(ep, dev, bt_hci_if);
		if (!ep->cr) {
			dev_err(&interface->dev, "%s: ep0_init failed", __func__);
			retval = -ENOMEM;
			goto error;
		}
		dev->ep0 = ep;
	} else {
		dev->ep0 = 0;
	}

	/* save our data pointer in this interface device */
	usb_set_intfdata(interface, dev);

	/* we can register the device now, as it is ready */
	retval = usb_register_dev(interface, &tpt_class);
	if (retval) {
		/* something prevented us from registering this driver */
		dev_err(&interface->dev, "Not able to get a minor for this device.");
		usb_set_intfdata(interface, NULL);
		goto error;
	}

	/* let the user know what node this device is now attached to */
	dev_info(&interface->dev, "usbtpt attached to usbtpt-%d",
		 interface->minor);
	return 0;

error:
	/* this frees allocated memory */
	kref_put(&dev->kref, tpt_delete);

	return retval;
}

static void tpt_disconnect(struct usb_interface *interface)
{
	struct usb_tpt *dev;

	dev_info(&interface->dev, "USB usbtpt disconnect event");

	dev = usb_get_intfdata(interface);
	if (!dev)
		return;

	usb_set_intfdata(interface, NULL);

	/* give back our minor */
	usb_deregister_dev(interface, &tpt_class);

	/* prevent more I/O from starting */
	mutex_lock(&dev->io_mutex);
	dev->disconnected = 1;
	mutex_unlock(&dev->io_mutex);

	stop_device(dev);
	free_ep_buffers(dev);
	free_endpoints(dev);

	/* decrement our usage count */
	kref_put(&dev->kref, tpt_delete);

	dev_info(&interface->dev, "USB usbtpt now disconnected");
}

static int tpt_suspend(struct usb_interface *intf, pm_message_t message)
{
	struct usb_tpt *dev = usb_get_intfdata(intf);

	if (!dev)
		return 0;
	stop_device(dev);
	return 0;
}

static int tpt_resume(struct usb_interface *intf)
{
	return 0;
}

static int tpt_pre_reset(struct usb_interface *intf)
{
	struct usb_tpt *dev = usb_get_intfdata(intf);

	if (!dev)
		return 0;
	mutex_lock(&dev->io_mutex);
	stop_device(dev);

	return 0;
}

static int tpt_post_reset(struct usb_interface *intf)
{
	struct usb_tpt *dev = usb_get_intfdata(intf);

	if (!dev)
		return 0;
	/* we are sure no URBs are active - no locking needed */
	mutex_unlock(&dev->io_mutex);

	return 0;
}

static struct usb_driver tpt_driver = {
	.name                 = "usbtpt",
	.probe                = tpt_probe,
	.disconnect           = tpt_disconnect,
	.suspend              = tpt_suspend,
	.resume               = tpt_resume,
	.pre_reset            = tpt_pre_reset,
	.post_reset           = tpt_post_reset,
	.id_table             = tpt_table,
	.supports_autosuspend = 1,
};

module_usb_driver(tpt_driver);

MODULE_LICENSE("GPL v2");
