// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "cl_radar.h"
#include "cl_irq.h"
#include "cl_ipc_shared.h"

static void cl_radar_tasklet(unsigned long data)
{
	struct cl_hw *cl_hw = (struct cl_hw *)data;
	struct cl_radar_queue_elem *radar_elem = NULL;
	unsigned long flags = 0;

	while (!list_empty(&cl_hw->radar_queue.head)) {
		spin_lock_irqsave(&cl_hw->radar_queue.lock, flags);
		radar_elem = list_first_entry(&cl_hw->radar_queue.head,
					      struct cl_radar_queue_elem, list);
		list_del(&radar_elem->list);
		spin_unlock_irqrestore(&cl_hw->radar_queue.lock, flags);

		kfree(radar_elem->radar_elem.radarbuf_ptr);
		kfree(radar_elem);
	}

	if (IS_PCI_BUS_TYPE(cl_hw->chip) &&
	    !test_bit(CL_DEV_STOP_HW, &cl_hw->drv_flags))
		cl_irq_enable(cl_hw, cl_hw->ipc_e2a_irq.radar);
}

void cl_radar_init(struct cl_hw *cl_hw)
{
	INIT_LIST_HEAD(&cl_hw->radar_queue.head);

	tasklet_init(&cl_hw->radar_tasklet, cl_radar_tasklet, (unsigned long)cl_hw);

	spin_lock_init(&cl_hw->radar_queue.lock);
}

void cl_radar_push(struct cl_hw *cl_hw, struct cl_radar_elem *radar_elem)
{
	struct cl_radar_queue_elem *new_queue_elem = NULL;
	u32 i;

	new_queue_elem = kmalloc(sizeof(*new_queue_elem), GFP_ATOMIC);

	if (new_queue_elem) {
		new_queue_elem->radar_elem.radarbuf_ptr =
			kmalloc(sizeof(*new_queue_elem->radar_elem.radarbuf_ptr), GFP_ATOMIC);

		if (new_queue_elem->radar_elem.radarbuf_ptr) {
			new_queue_elem->radar_elem.dma_addr = radar_elem->dma_addr;
			new_queue_elem->radar_elem.radarbuf_ptr->cnt =
						radar_elem->radarbuf_ptr->cnt;

			/* Copy into local list */
			for (i = 0; i < RADAR_PULSE_MAX; i++)
				new_queue_elem->radar_elem.radarbuf_ptr->pulse[i] =
					radar_elem->radarbuf_ptr->pulse[i];

			new_queue_elem->time = jiffies_to_msecs(jiffies);
			new_queue_elem->cl_hw = cl_hw;

			spin_lock(&cl_hw->radar_queue.lock);
			list_add_tail(&new_queue_elem->list, &cl_hw->radar_queue.head);
			spin_unlock(&cl_hw->radar_queue.lock);
		} else {
			kfree(new_queue_elem);
		}
	}
}

void cl_radar_tasklet_schedule(struct cl_hw *cl_hw)
{
	tasklet_schedule(&cl_hw->radar_tasklet);
}

void cl_radar_flush(struct cl_hw *cl_hw)
{
	struct cl_radar_queue_elem *radar_elem = NULL;
	unsigned long flags = 0;

	spin_lock_irqsave(&cl_hw->radar_queue.lock, flags);

	while (!list_empty(&cl_hw->radar_queue.head)) {
		radar_elem = list_first_entry(&cl_hw->radar_queue.head,
					      struct cl_radar_queue_elem, list);
		list_del(&radar_elem->list);
		kfree(radar_elem->radar_elem.radarbuf_ptr);
		kfree(radar_elem);
	}

	spin_unlock_irqrestore(&cl_hw->radar_queue.lock, flags);
}

void cl_radar_close(struct cl_hw *cl_hw)
{
	cl_radar_flush(cl_hw);
	tasklet_kill(&cl_hw->radar_tasklet);
}
