// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_rx_reorder.h"
#include "cl_key.h"
#include "cl_rx.h"
#include "cl_utils.h"

#define REORDER_BUF_TIMEOUT (HZ / 10)
#define REORDER_BUF_TIMEOUT_MS jiffies_to_msecs(REORDER_BUF_TIMEOUT + 1)

static bool cl_rx_reorder_ready(struct cl_tid_ampdu_rx *tid_agg_rx, u8 index)
{
	struct sk_buff_head *frames = &tid_agg_rx->reorder_buf[index];

	if (tid_agg_rx->reorder_buf_filtered & BIT_ULL(index))
		return true;

	if (skb_queue_empty(frames))
		return false;

	return true;
}

static void cl_rx_release_reorder_frame(struct cl_tid_ampdu_rx *tid_agg_rx, int index,
					struct sk_buff_head *frames)
{
	struct cl_hw *cl_hw = tid_agg_rx->cl_hw;
	struct sk_buff_head *skb_list = &tid_agg_rx->reorder_buf[index];
	struct sk_buff *skb;
	struct cl_sta *cl_sta = IEEE80211_STA_TO_CL_STA(tid_agg_rx->sta);
	struct hw_rxhdr *rxhdr = tid_agg_rx->reorder_rxhdr[index];

	lockdep_assert_held(&tid_agg_rx->reorder_lock);

	if (skb_queue_empty(skb_list))
		goto no_frame;

	tid_agg_rx->stored_mpdu_num--;

	if (!cl_rx_reorder_ready(tid_agg_rx, index)) {
		__skb_queue_purge(skb_list);
		goto no_frame;
	}

	/*
	 * For NON AMSDU - Single skb in skb_list
	 * For AMSDU - Validate first skb and set PN flag for rest.
	 */
	skb = skb_peek(skb_list);
	if (cl_key_validate_pn_tsc(cl_hw, skb, cl_sta,
				   tid_agg_rx->tid, rxhdr)) {
		__skb_queue_purge(skb_list);
		goto no_frame;
	}

	while ((skb = __skb_dequeue(skb_list)))
		__skb_queue_tail(frames, skb);

no_frame:
	tid_agg_rx->reorder_buf_filtered &= ~BIT_ULL(index);
	tid_agg_rx->head_seq_num = ieee80211_sn_inc(tid_agg_rx->head_seq_num);
}

static void cl_rx_release_reorder_frames(struct cl_tid_ampdu_rx *tid_agg_rx,
					 u16 head_seq_num,
					 struct sk_buff_head *frames)
{
	int index;

	lockdep_assert_held(&tid_agg_rx->reorder_lock);

	while (ieee80211_sn_less(tid_agg_rx->head_seq_num, head_seq_num)) {
		index = tid_agg_rx->head_seq_num % tid_agg_rx->buf_size;
		cl_rx_release_reorder_frame(tid_agg_rx, index, frames);
	}
}

static void cl_reorder_release(struct cl_tid_ampdu_rx *tid_agg_rx, struct sk_buff_head *frames)
{
	u8 index, i, j;

	lockdep_assert_held(&tid_agg_rx->reorder_lock);

	/* Release buffer until next hole */
	index = tid_agg_rx->head_seq_num % tid_agg_rx->buf_size;
	if (!cl_rx_reorder_ready(tid_agg_rx, index) && tid_agg_rx->stored_mpdu_num) {
		u8 skipped = 1;

		for (j = (index + 1) % tid_agg_rx->buf_size; j != index;
		     j = (j + 1) % tid_agg_rx->buf_size) {
			if (!cl_rx_reorder_ready(tid_agg_rx, j)) {
				skipped++;
				continue;
			}
			if (skipped &&
			    !time_after(jiffies, tid_agg_rx->reorder_time[j] +
					REORDER_BUF_TIMEOUT))
				goto set_release_timer;

			/* Incomplete A-MSDUs */
			for (i = (index + 1) % tid_agg_rx->buf_size; i != j;
			     i = (i + 1) % tid_agg_rx->buf_size) {
				__skb_queue_purge(&tid_agg_rx->reorder_buf[i]);
			}

			cl_rx_release_reorder_frame(tid_agg_rx, j, frames);

			tid_agg_rx->head_seq_num =
				(tid_agg_rx->head_seq_num +
				 skipped) & IEEE80211_SN_MASK;
			skipped = 0;
		}
	} else {
		while (cl_rx_reorder_ready(tid_agg_rx, index)) {
			cl_rx_release_reorder_frame(tid_agg_rx, index, frames);
			index = tid_agg_rx->head_seq_num % tid_agg_rx->buf_size;
		}
	}

	if (tid_agg_rx->stored_mpdu_num) {
		j = tid_agg_rx->head_seq_num % tid_agg_rx->buf_size;
		index = j;
		for (; j != (index - 1) % tid_agg_rx->buf_size;
		     j = (j + 1) % tid_agg_rx->buf_size) {
			if (cl_rx_reorder_ready(tid_agg_rx, j))
				break;
		}

 set_release_timer:
		if (!tid_agg_rx->removed)
			cl_timer_rearm_offset(&tid_agg_rx->reorder_timer,
					      tid_agg_rx->reorder_time[j]);
	} else {
		cl_timer_disable(&tid_agg_rx->reorder_timer);
	}
}

static void cl_rx_reorder_release_timeout(unsigned long data)
{
	struct cl_tid_ampdu_rx *tid_agg_rx = (struct cl_tid_ampdu_rx *)data;
	struct sk_buff *skb = NULL;
	struct cl_hw *cl_hw = NULL;
	struct ieee80211_sta *sta = NULL;
	struct sk_buff_head buffer;

	if (!tid_agg_rx)
		return;

	__skb_queue_head_init(&buffer);

	spin_lock(&tid_agg_rx->reorder_lock);

	cl_hw = tid_agg_rx->cl_hw;
	sta = tid_agg_rx->sta;
	cl_reorder_release(tid_agg_rx, &buffer);

	spin_unlock(&tid_agg_rx->reorder_lock);

	while (!skb_queue_empty(&buffer)) {
		skb = __skb_dequeue(&buffer);
		cl_rx_finish(cl_hw, skb, sta);
	}
}

static bool cl_rx_manage_reorder_buf(struct cl_tid_ampdu_rx *tid_agg_rx,
				     struct sk_buff_head *skb_list,
				     struct hw_rxhdr *rxhdr,
				     struct sk_buff_head *ordered_mpdu,
				     struct cl_sta *cl_sta,
				     u16 sc)
{
	u16 mpdu_seq_num = (sc & IEEE80211_SCTL_SEQ) >> 4;
	u16 head_seq_num, buf_size;
	u8 index;
	bool ret = true;

	if (unlikely(tid_agg_rx->auto_seq)) {
		tid_agg_rx->auto_seq = false;
		tid_agg_rx->ssn = mpdu_seq_num;
		tid_agg_rx->head_seq_num = mpdu_seq_num;
	}

	buf_size = tid_agg_rx->buf_size;
	head_seq_num = tid_agg_rx->head_seq_num;

	/* Current SN is smaller than the SSN */
	if (unlikely(!tid_agg_rx->started)) {
		if (ieee80211_sn_less(mpdu_seq_num, head_seq_num)) {
			ret = false;
			goto out;
		}
		tid_agg_rx->started = true;
	}

	/* Out of date sequence number */
	if (ieee80211_sn_less(mpdu_seq_num, head_seq_num)) {
		skb_queue_purge(skb_list);
		goto out;
	}

	/* SN exceeds buffer window */
	if (!ieee80211_sn_less(mpdu_seq_num, head_seq_num + buf_size)) {
		head_seq_num = ieee80211_sn_inc(ieee80211_sn_sub(mpdu_seq_num, buf_size));
		cl_rx_release_reorder_frames(tid_agg_rx, head_seq_num, ordered_mpdu);
	}

	index = mpdu_seq_num % tid_agg_rx->buf_size;

	/* Frame already stored */
	if (cl_rx_reorder_ready(tid_agg_rx, index)) {
		skb_queue_purge(skb_list);
		goto out;
	}

	if (mpdu_seq_num == tid_agg_rx->head_seq_num &&
	    tid_agg_rx->stored_mpdu_num == 0) {
		tid_agg_rx->head_seq_num =
				ieee80211_sn_inc(tid_agg_rx->head_seq_num);
		ret = false;
		goto out;
	}

	/* Insert frames into reorder buffer */
	skb_queue_splice_tail_init(skb_list, &tid_agg_rx->reorder_buf[index]);
	tid_agg_rx->reorder_rxhdr[index] = rxhdr;
	tid_agg_rx->reorder_time[index] = jiffies;
	tid_agg_rx->stored_mpdu_num++;
	cl_reorder_release(tid_agg_rx, ordered_mpdu);

 out:
	return ret;
}

int cl_rx_reorder_ampdu(struct cl_hw *cl_hw, struct cl_sta *cl_sta,
			struct cl_tid_ampdu_rx *tid_agg_rx,
			struct cl_rx_w2e_hdr *w2e_hdr,
			struct hw_rxhdr *rxhdr,
			struct sk_buff_head *skb_list,
			struct sk_buff_head *ordered_mpdu)
{
	struct sk_buff *skb = skb_peek(skb_list);
	u8 ack_policy;
	__le16 sc = cl_get_seq_ctrl(cl_hw, skb, w2e_hdr);
	__le16 fc = cl_get_frame_ctrl(cl_hw, skb, w2e_hdr);
	u8 *qc;
	int ret = false;

	if (!ieee80211_is_data_qos(fc) ||
	    cl_is_eapol(skb, w2e_hdr)) {
		goto dont_reorder;
	}

	/* W2E is not done on non unicast */
	if (!w2e_hdr) {
		struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;

		if (is_multicast_ether_addr(hdr->addr1))
			goto dont_reorder;
	}
	qc = cl_get_qos_ctrl(cl_hw, skb, w2e_hdr);
	ack_policy = *qc & IEEE80211_QOS_CTL_ACK_POLICY_MASK;

	if (unlikely(fc & cpu_to_le16(IEEE80211_STYPE_NULLFUNC)))
		goto dont_reorder;

	if (ack_policy != IEEE80211_QOS_CTL_ACK_POLICY_BLOCKACK &&
	    ack_policy != IEEE80211_QOS_CTL_ACK_POLICY_NORMAL)
		goto dont_reorder;

	if (!w2e_hdr)
		cl_rx_wlan_to_8023(cl_hw, cl_sta, skb_list);
	ret = true;
	spin_lock(&tid_agg_rx->reorder_lock);
	if (cl_rx_manage_reorder_buf(tid_agg_rx, skb_list, rxhdr, ordered_mpdu,
				     cl_sta, le16_to_cpu(sc))) {
		spin_unlock(&tid_agg_rx->reorder_lock);
		return ret;
	}
	spin_unlock(&tid_agg_rx->reorder_lock);

 dont_reorder:
	skb_queue_splice_tail_init(skb_list, ordered_mpdu);
	return ret;
}

void cl_rx_reorder_close(struct cl_sta *cl_sta, u8 tid)
{
	struct cl_tid_ampdu_rx *tid_agg_rx = cl_sta->tid_agg_rx[tid];
	u16 i;

	spin_lock_bh(&tid_agg_rx->reorder_lock);
	tid_agg_rx->removed = true;
	spin_unlock_bh(&tid_agg_rx->reorder_lock);

	cl_timer_disable_sync(&tid_agg_rx->reorder_timer);

	spin_lock_bh(&tid_agg_rx->reorder_lock);
	for (i = 0; i < tid_agg_rx->buf_size; i++)
		__skb_queue_purge(&tid_agg_rx->reorder_buf[i]);

	kfree(tid_agg_rx->reorder_buf);
	kfree(tid_agg_rx->reorder_rxhdr);
	kfree(tid_agg_rx->reorder_time);
	cl_sta->tid_agg_rx[tid] = NULL;

	spin_unlock_bh(&tid_agg_rx->reorder_lock);
	kfree(tid_agg_rx);
}

void cl_rx_reorder_init(struct cl_hw *cl_hw, struct cl_sta *cl_sta, u8 tid, u16 buf_size)
{
	struct cl_tid_ampdu_rx *tid_agg_rx;
	u16 i;

	tid_agg_rx = kzalloc(sizeof(*tid_agg_rx), GFP_KERNEL);
	if (!tid_agg_rx)
		return;

	spin_lock_init(&tid_agg_rx->reorder_lock);

	cl_timer_init(&tid_agg_rx->reorder_timer, cl_rx_reorder_release_timeout,
		      (unsigned long)tid_agg_rx, REORDER_BUF_TIMEOUT_MS, false);

	tid_agg_rx->reorder_buf =
		kcalloc(buf_size, sizeof(struct sk_buff_head), GFP_KERNEL);
	tid_agg_rx->reorder_rxhdr =
		kcalloc(buf_size, sizeof(struct hw_rxhdr *), GFP_KERNEL);
	tid_agg_rx->reorder_time =
		kcalloc(buf_size, sizeof(unsigned long), GFP_KERNEL);
	if (!tid_agg_rx->reorder_buf ||
	    !tid_agg_rx->reorder_rxhdr ||
	    !tid_agg_rx->reorder_time) {
		pr_err("Allocation failed!\n");
		kfree(tid_agg_rx->reorder_buf);
		kfree(tid_agg_rx->reorder_rxhdr);
		kfree(tid_agg_rx->reorder_time);
		return;
	}

	for (i = 0; i < buf_size; i++)
		__skb_queue_head_init(&tid_agg_rx->reorder_buf[i]);

	tid_agg_rx->ssn = 0;
	tid_agg_rx->head_seq_num = 0;
	tid_agg_rx->buf_size = buf_size;
	tid_agg_rx->stored_mpdu_num = 0;
	tid_agg_rx->auto_seq = 0;
	tid_agg_rx->started = false;
	tid_agg_rx->reorder_buf_filtered = 0;
	tid_agg_rx->tid = tid;
	tid_agg_rx->sta = &cl_sta->stainfo->sta;
	tid_agg_rx->cl_hw = cl_hw;
	cl_sta->tid_agg_rx[tid] = tid_agg_rx;
}
