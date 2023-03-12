// SPDX-License-Identifier: GPL-2.0
/* Copyright(c) 2019-2021, Celeno Corporation. */

#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/init.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/fcntl.h>
#include <linux/interrupt.h>
#include <linux/ptrace.h>
#include <linux/poll.h>

#include <linux/slab.h>
#include <linux/tty.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/signal.h>
#include <linux/ioctl.h>
#include <linux/skbuff.h>

#include <net/bluetooth/bluetooth.h>
#include <net/bluetooth/hci_core.h>

#include "hci_uart.h"
#include "btcl.h"

/* HCI_CL commands */
#define HCI_CL_GO_TO_SLEEP_IND	0x30
#define HCI_CL_GO_TO_SLEEP_ACK	0x31
#define HCI_CL_WAKE_UP_IND	0x32
#define HCI_CL_WAKE_UP_ACK	0x33

/* HCI_CL receiver States */
#define HCI_CL_W4_PACKET_TYPE	0
#define HCI_CL_W4_EVENT_HDR	1
#define HCI_CL_W4_ACL_HDR	2
#define HCI_CL_W4_SCO_HDR	3
#define HCI_CL_W4_DATA		4

/* HCI_CL states */
enum hci_cl_states_e {
	HCI_CL_ASLEEP,
	HCI_CL_ASLEEP_TO_AWAKE,
	HCI_CL_AWAKE,
	HCI_CL_AWAKE_TO_ASLEEP
};

struct hci_cl_cmd {
	u8 cmd;
} __packed;

struct cl_bt {
	unsigned long rx_state;
	unsigned long rx_count;
	struct sk_buff *rx_skb;
	struct sk_buff_head txq;
	spinlock_t hci_cl_lock;		/* HCI_CL state lock	*/
	unsigned long hci_cl_state;	/* HCI_CL power state	*/
	struct sk_buff_head tx_wait_q;	/* HCI_CL wait queue	*/
	struct cl_chip *chip;
};

/*
 * Builds and sends an HCI_CL command packet.
 * These are very simple packets with only 1 cmd byte
 */
static int send_hci_cl_cmd(u8 cmd, struct hci_uart *hu)
{
	int err = 0;
	struct sk_buff *skb = NULL;
	struct cl_bt *cl_bt = hu->priv;
	struct hci_cl_cmd *hci_cl_packet;

	BT_DBG("hu %p cmd 0x%x", hu, cmd);

	/* allocate packet */
	skb = bt_skb_alloc(1, GFP_ATOMIC);
	if (!skb) {
		BT_ERR("cannot allocate memory for HCI_CL packet");
		err = -ENOMEM;
		goto out;
	}

	/* prepare packet */
	hci_cl_packet = (struct hci_cl_cmd *)skb_put(skb, 1);
	hci_cl_packet->cmd = cmd;

	/* send packet */
	skb_queue_tail(&cl_bt->txq, skb);
out:
	return err;
}

/* Initialize protocol */
static int cl_open(struct hci_uart *hu)
{
	struct cl_bt *cl_bt;

	BT_DBG("hu %p", hu);

	cl_bt = kzalloc(sizeof(*cl_bt), GFP_KERNEL);
	if (!cl_bt)
		return -ENOMEM;

	skb_queue_head_init(&cl_bt->txq);
	skb_queue_head_init(&cl_bt->tx_wait_q);
	spin_lock_init(&cl_bt->hci_cl_lock);

	cl_bt->hci_cl_state = HCI_CL_AWAKE;

	hu->priv = cl_bt;

	return 0;
}

static int cl_post_init(struct hci_dev *hdev)
{
	struct hci_uart *hu = hci_get_drvdata(hdev);
	struct cl_bt *cl_bt = hu->priv;

	cl_bt->chip = btcl_get_chip_by_mac_address(&hdev->bdaddr.b[0]);

	return 0;
}

static struct cl_chip *cl_hci_to_chip(struct hci_dev *hdev)
{
	struct hci_uart *hu = hci_get_drvdata(hdev);
	struct cl_bt *cl_bt = hu->priv;

	if (cl_bt)
		return cl_bt->chip;
	else
		return NULL;
}


static int cl_setup(struct hci_uart *hu)
{
	btcl_init_celeno(hu->hdev, cl_hci_to_chip);
	hu->hdev->post_init = cl_post_init;

	return 0;
}

/* Flush protocol data */
static int cl_flush(struct hci_uart *hu)
{
	struct cl_bt *cl_bt = hu->priv;

	BT_DBG("hu %p", hu);

	skb_queue_purge(&cl_bt->tx_wait_q);
	skb_queue_purge(&cl_bt->txq);

	return 0;
}

/* Close protocol */
static int cl_close(struct hci_uart *hu)
{
	struct cl_bt *cl_bt = hu->priv;

	BT_DBG("hu %p", hu);

	skb_queue_purge(&cl_bt->tx_wait_q);
	skb_queue_purge(&cl_bt->txq);

	kfree_skb(cl_bt->rx_skb);

	hu->priv = NULL;

	kfree(cl_bt);

	return 0;
}

/*
 * internal function, which does common work of the device wake up process:
 * 1. places all pending packets (waiting in tx_wait_q list) in txq list.
 * 2. changes internal state to HCI_CL_AWAKE.
 * Note: assumes that hci_cl_lock spinlock is taken,
 * shouldn't be called otherwise!
 */
static void __cl_do_awake(struct cl_bt *cl_bt)
{
	struct sk_buff *skb = NULL;

	while ((skb = skb_dequeue(&cl_bt->tx_wait_q)))
		skb_queue_tail(&cl_bt->txq, skb);

	cl_bt->hci_cl_state = HCI_CL_AWAKE;
}

/*
 * Called upon a wake-up-indication from the device
 */
static void cl_device_want_to_wakeup(struct hci_uart *hu)
{
	unsigned long flags;
	struct cl_bt *cl_bt = hu->priv;

	BT_DBG("hu %p", hu);

	/* lock hci_cl state */
	spin_lock_irqsave(&cl_bt->hci_cl_lock, flags);

	switch (cl_bt->hci_cl_state) {
	case HCI_CL_ASLEEP_TO_AWAKE:
		/*
		 * This state means that both the host and the BRF chip
		 * have simultaneously sent a wake-up-indication packet.
		 * Traditionally, in this case, receiving a wake-up-indication
		 * was enough and an additional wake-up-ack wasn't needed.
		 * This has changed with the BRF6350, which does require an
		 * explicit wake-up-ack. Other BRF versions, which do not
		 * require an explicit ack here, do accept it, thus it is
		 * perfectly safe to always send one.
		 */
		BT_DBG("dual wake-up-indication");
	case HCI_CL_ASLEEP:
		/* acknowledge device wake up */
		if (send_hci_cl_cmd(HCI_CL_WAKE_UP_ACK, hu) < 0) {
			BT_ERR("cannot acknowledge device wake up");
			goto out;
		}
		break;
	default:
		/* any other state is illegal */
		BT_ERR("received HCI_CL_WAKE_UP_IND in state %ld", cl_bt->hci_cl_state);
		break;
	}

	/* send pending packets and change state to HCI_CL_AWAKE */
	__cl_do_awake(cl_bt);

out:
	spin_unlock_irqrestore(&cl_bt->hci_cl_lock, flags);

	/* actually send the packets */
	hci_uart_tx_wakeup(hu);
}

/*
 * Called upon a sleep-indication from the device
 */
static void cl_device_want_to_sleep(struct hci_uart *hu)
{
	unsigned long flags;
	struct cl_bt *cl_bt = hu->priv;

	BT_DBG("hu %p", hu);

	/* lock hci_cl state */
	spin_lock_irqsave(&cl_bt->hci_cl_lock, flags);

	/* sanity check */
	if (cl_bt->hci_cl_state != HCI_CL_AWAKE)
		BT_ERR("ERR: HCI_CL_GO_TO_SLEEP_IND in state %ld", cl_bt->hci_cl_state);

	/* acknowledge device sleep */
	if (send_hci_cl_cmd(HCI_CL_GO_TO_SLEEP_ACK, hu) < 0) {
		BT_ERR("cannot acknowledge device sleep");
		goto out;
	}

	/* update state */
	cl_bt->hci_cl_state = HCI_CL_ASLEEP;

out:
	spin_unlock_irqrestore(&cl_bt->hci_cl_lock, flags);

	/* actually send the sleep ack packet */
	hci_uart_tx_wakeup(hu);
}

/*
 * Called upon wake-up-acknowledgment from the device
 */
static void cl_device_woke_up(struct hci_uart *hu)
{
	unsigned long flags;
	struct cl_bt *cl_bt = hu->priv;

	BT_DBG("hu %p", hu);

	/* lock hci_cl state */
	spin_lock_irqsave(&cl_bt->hci_cl_lock, flags);

	/* sanity check */
	if (cl_bt->hci_cl_state != HCI_CL_ASLEEP_TO_AWAKE)
		BT_ERR("received HCI_CL_WAKE_UP_ACK in state %ld", cl_bt->hci_cl_state);

	/* send pending packets and change state to HCI_CL_AWAKE */
	__cl_do_awake(cl_bt);

	spin_unlock_irqrestore(&cl_bt->hci_cl_lock, flags);

	/* actually send the packets */
	hci_uart_tx_wakeup(hu);
}

/* Enqueue frame for transmittion (padding, crc, etc) */
/* may be called from two simultaneous tasklets */
static int cl_enqueue(struct hci_uart *hu, struct sk_buff *skb)
{
	unsigned long flags = 0;
	struct cl_bt *cl_bt = hu->priv;

	BT_DBG("hu %p skb %p", hu, skb);

	/* Prepend skb with frame type */
	memcpy(skb_push(skb, 1), &bt_cb(skb)->pkt_type, 1);

	/* lock hci_cl state */
	spin_lock_irqsave(&cl_bt->hci_cl_lock, flags);

	/* act according to current state */
	switch (cl_bt->hci_cl_state) {
	case HCI_CL_AWAKE:
		BT_DBG("device awake, sending normally");
		skb_queue_tail(&cl_bt->txq, skb);
		break;
	case HCI_CL_ASLEEP:
		BT_DBG("device asleep, waking up and queueing packet");
		/* save packet for later */
		skb_queue_tail(&cl_bt->tx_wait_q, skb);
		/* awake device */
		if (send_hci_cl_cmd(HCI_CL_WAKE_UP_IND, hu) < 0) {
			BT_ERR("cannot wake up device");
			break;
		}
		cl_bt->hci_cl_state = HCI_CL_ASLEEP_TO_AWAKE;
		break;
	case HCI_CL_ASLEEP_TO_AWAKE:
		BT_DBG("device waking up, queueing packet");
		/* transient state; just keep packet for later */
		skb_queue_tail(&cl_bt->tx_wait_q, skb);
		break;
	default:
		BT_ERR("illegal hci_cl state: %ld (losing packet)", cl_bt->hci_cl_state);
		kfree_skb(skb);
		break;
	}

	spin_unlock_irqrestore(&cl_bt->hci_cl_lock, flags);

	return 0;
}

static inline int cl_check_data_len(struct hci_dev *hdev, struct cl_bt *cl_bt, int len)
{
	int room = skb_tailroom(cl_bt->rx_skb);

	BT_DBG("len %d room %d", len, room);

	if (!len) {
		hci_recv_frame(hdev, cl_bt->rx_skb);
	} else if (len > room) {
		BT_ERR("Data length is too large");
		kfree_skb(cl_bt->rx_skb);
	} else {
		cl_bt->rx_state = HCI_CL_W4_DATA;
		cl_bt->rx_count = len;
		return len;
	}

	cl_bt->rx_state = HCI_CL_W4_PACKET_TYPE;
	cl_bt->rx_skb   = NULL;
	cl_bt->rx_count = 0;

	return 0;
}

/* Recv data */
static int cl_recv(struct hci_uart *hu, const void *data, int count)
{
	struct cl_bt *cl_bt = hu->priv;
	const char *ptr;
	struct hci_event_hdr *eh;
	struct hci_acl_hdr   *ah;
	struct hci_sco_hdr   *sh;
	int len, type, dlen;

	BT_DBG("hu %p count %d rx_state %ld rx_count %ld", hu, count, cl_bt->rx_state,
	       cl_bt->rx_count);

	ptr = data;
	while (count) {
		if (cl_bt->rx_count) {
			len = min_t(unsigned int, cl_bt->rx_count, count);
			memcpy(skb_put(cl_bt->rx_skb, len), ptr, len);
			cl_bt->rx_count -= len; count -= len; ptr += len;

			if (cl_bt->rx_count)
				continue;

			switch (cl_bt->rx_state) {
			case HCI_CL_W4_DATA:
				BT_DBG("Complete data");
				hci_recv_frame(hu->hdev, cl_bt->rx_skb);

				cl_bt->rx_state = HCI_CL_W4_PACKET_TYPE;
				cl_bt->rx_skb = NULL;
				continue;

			case HCI_CL_W4_EVENT_HDR:
				eh = hci_event_hdr(cl_bt->rx_skb);

				BT_DBG("Event header: evt 0x%2.2x plen %d", eh->evt, eh->plen);

				cl_check_data_len(hu->hdev, cl_bt, eh->plen);
				continue;

			case HCI_CL_W4_ACL_HDR:
				ah = hci_acl_hdr(cl_bt->rx_skb);
				dlen = __le16_to_cpu(ah->dlen);

				BT_DBG("ACL header: dlen %d", dlen);

				cl_check_data_len(hu->hdev, cl_bt, dlen);
				continue;

			case HCI_CL_W4_SCO_HDR:
				sh = hci_sco_hdr(cl_bt->rx_skb);

				BT_DBG("SCO header: dlen %d", sh->dlen);

				cl_check_data_len(hu->hdev, cl_bt, sh->dlen);
				continue;
			}
		}

		/* HCI_CL_W4_PACKET_TYPE */
		switch (*ptr) {
		case HCI_EVENT_PKT:
			BT_DBG("Event packet");
			cl_bt->rx_state = HCI_CL_W4_EVENT_HDR;
			cl_bt->rx_count = HCI_EVENT_HDR_SIZE;
			type = HCI_EVENT_PKT;
			break;

		case HCI_ACLDATA_PKT:
			BT_DBG("ACL packet");
			cl_bt->rx_state = HCI_CL_W4_ACL_HDR;
			cl_bt->rx_count = HCI_ACL_HDR_SIZE;
			type = HCI_ACLDATA_PKT;
			break;

		case HCI_SCODATA_PKT:
			BT_DBG("SCO packet");
			cl_bt->rx_state = HCI_CL_W4_SCO_HDR;
			cl_bt->rx_count = HCI_SCO_HDR_SIZE;
			type = HCI_SCODATA_PKT;
			break;

		/* HCI_CL signals */
		case HCI_CL_GO_TO_SLEEP_IND:
			BT_DBG("HCI_CL_GO_TO_SLEEP_IND packet");
			cl_device_want_to_sleep(hu);
			ptr++; count--;
			continue;

		case HCI_CL_GO_TO_SLEEP_ACK:
			/* shouldn't happen */
			BT_ERR("received HCI_CL_GO_TO_SLEEP_ACK (in state %ld)",
			       cl_bt->hci_cl_state);
			ptr++; count--;
			continue;

		case HCI_CL_WAKE_UP_IND:
			BT_DBG("HCI_CL_WAKE_UP_IND packet");
			cl_device_want_to_wakeup(hu);
			ptr++; count--;
			continue;

		case HCI_CL_WAKE_UP_ACK:
			BT_DBG("HCI_CL_WAKE_UP_ACK packet");
			cl_device_woke_up(hu);
			ptr++; count--;
			continue;

		default:
			BT_ERR("Unknown HCI packet type %2.2x", (__u8)*ptr);
			hu->hdev->stat.err_rx++;
			ptr++; count--;
			continue;
		}

		ptr++; count--;

		/* Allocate packet */
		cl_bt->rx_skb = bt_skb_alloc(HCI_MAX_FRAME_SIZE, GFP_ATOMIC);
		if (!cl_bt->rx_skb) {
			BT_ERR("Can't allocate mem for new packet");
			cl_bt->rx_state = HCI_CL_W4_PACKET_TYPE;
			cl_bt->rx_count = 0;
			return -ENOMEM;
		}

		bt_cb(cl_bt->rx_skb)->pkt_type = type;
	}

	return count;
}

static struct sk_buff *cl_dequeue(struct hci_uart *hu)
{
	struct cl_bt *cl_bt = hu->priv;
	return skb_dequeue(&cl_bt->txq);
}

static const struct hci_uart_proto cl_proto = {
	.id		= HCI_UART_CELENO,
	.name		= "hci_celeno",
	.open		= cl_open,
	.close		= cl_close,
	.recv		= cl_recv,
	.enqueue	= cl_enqueue,
	.dequeue	= cl_dequeue,
	.flush		= cl_flush,
	.setup		= cl_setup,
};

int __init cl_init(void)
{
	return hci_uart_register_proto(&cl_proto);
}

int __exit cl_deinit(void)
{
	return hci_uart_unregister_proto(&cl_proto);
}
