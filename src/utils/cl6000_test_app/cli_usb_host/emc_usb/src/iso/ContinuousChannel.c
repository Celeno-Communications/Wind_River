/* Copyright (C) 2014, 2020, 2021 emsys Embedded Systems GmbH */

#include "emc/usb/iso/ContinuousChannel.h"

typedef EMC_USB_ContinuousChannel This;

void EMC_USB_ContinuousChannel_initialize(EMC_USB_ContinuousChannel* self,
                                          emc_logger_t* logger,
                                          void* context,
                                          const EMC_USB_ContinuousChannelFunctions* vtable)
{
  self->call = vtable;
  self->logger = logger;
  self->context = context;
  self->on_stop = emc_error_code_handler(0, 0);
}

void EMC_USB_ContinuousChannel_set_buffer(This* this, int* buffer)
{
  (*this->call->set_buffer)(this, buffer);
}

void EMC_USB_ContinuousChannel_set_usb_and_user_index(This* this, int usb_index, int user_index)
{
  (*this->call->set_usb_and_user_index)(this, (unsigned)usb_index, (unsigned)user_index);
}

void EMC_USB_ContinuousChannel_start(This* this, EMC_ErrorCodeHandler on_stop, int next_frame)
{
  (*this->call->start)(this, on_stop, next_frame);
}

int* EMC_USB_ContinuousChannel_update_progress(This* this, int* dps_pos)
{
  return (*this->call->update_progress)(this, dps_pos);
}

void EMC_USB_ContinuousChannel_destroy(This* this)
{
  (*this->call->destroy)(this);
}
