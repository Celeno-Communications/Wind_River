/** @file
    @brief The continous buffer implementation
    Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/usb/iso/ContinuousBuffer.h"
#include "emc/usb/iso/ContinuousChannel.h"

#include "emc/std/string.h"
#include "emc/std/assert.h"

void EMC_USB_ContinuousBuffer_init(EMC_USB_ContinuousBuffer* self,
                                   EMC_MemoryRange buffer_mem,
                                   emc_std_uint32_t nb_chunks,
                                   emc_std_uint32_t chunk_capacity,
                                   emc_std_bool direction_out)
{
  emc_std_assert(buffer_mem.size >= EMC_USB_CONTINUOUS_BUFFER_SIZE(nb_chunks, chunk_capacity));

  emc_std_memset(self, 0, sizeof(EMC_USB_ContinuousBuffer));

  self->header = (EMC_USB_ContinuousBuffer_Header*)buffer_mem.base;
  self->status = (EMC_USB_ContinuousBuffer_Status*)(self->header + 1);
  self->payload_begin = (emc_std_int32_t*)(self->status + nb_chunks);
  self->empty = emc_std_true;
  self->direction_out = direction_out;

  self->header->chunk_offset_words = (emc_std_uint32_t)(self->payload_begin - (emc_std_int32_t*)self->header);
  self->header->nb_chunks = nb_chunks;
  self->header->chunk_capacity = chunk_capacity;

  if (self->direction_out) {
    // read one empty chunk at startup
    self->usb_index = 0;
    self->user_index = nb_chunks - 1;
  } else {
    // send one empty chunk at startup
    self->usb_index = nb_chunks - 1;
    self->user_index = 0;
  }
  self->empty = emc_std_false;
}

void EMC_USB_ContinuousBuffer_update(EMC_USB_ContinuousBuffer* self, EMC_USB_ContinuousChannel* channel)
{
  /* Fix me: casting allowed? Workaround incompatible-pointer-types */
  int*             user_pos = (int*)EMC_USB_ContinuousBuffer_user_pos(self);
  emc_std_int32_t* usb_pos = (emc_std_int32_t*)EMC_USB_ContinuousChannel_update_progress(channel, user_pos);
  EMC_USB_ContinuousBuffer_set_usb_pos(self, usb_pos);
}

emc_std_int32_t* EMC_USB_ContinuousBuffer_next_usb_pos(const EMC_USB_ContinuousBuffer* self, emc_std_int32_t* usb_pos)
{
  emc_std_uint32_t index = (emc_std_uint32_t)(usb_pos - self->payload_begin) / self->header->chunk_capacity;
  ++index;
  if (index >= self->header->nb_chunks) {
    index = 0;
  }

  return self->payload_begin + index * self->header->chunk_capacity;
}

emc_std_int32_t* EMC_USB_ContinuousBuffer_inc_user_pos(EMC_USB_ContinuousBuffer* self)
{
  self->user_index++;
  if (self->user_index >= self->header->nb_chunks) {
    self->user_index = 0;
  }
  if (self->direction_out && (self->user_index == self->usb_index)) {
    self->empty = emc_std_true;
  } else {
    self->empty = emc_std_false;
  }
  return EMC_USB_ContinuousBuffer_user_pos(self);
}

void EMC_USB_ContinuousBuffer_inc_usb_pos(EMC_USB_ContinuousBuffer* self)
{
  emc_std_size_t idx = self->usb_index + 1;
  if (idx >= self->header->nb_chunks) {
    idx = 0;
  }
  EMC_USB_ContinuousBuffer_set_usb_pos(self, self->payload_begin + idx * self->header->chunk_capacity);
}

emc_std_bool EMC_USB_ContinuousBuffer_set_usb_pos(EMC_USB_ContinuousBuffer* self, emc_std_int32_t* usb_pos)
{
  emc_std_uint32_t index = (emc_std_uint32_t)(usb_pos - self->payload_begin) / self->header->chunk_capacity;
  emc_std_bool     changed = index != self->usb_index;
  emc_std_assert(index < self->header->nb_chunks);
  self->usb_index = index;
  if (changed) {
    if (!self->direction_out && (self->user_index == self->usb_index)) {
      self->empty = emc_std_true;
    } else {
      self->empty = emc_std_false;
    }
  }
  return changed;
}

emc_std_size_t EMC_USB_ContinuousBuffer_chunks_to_read(const EMC_USB_ContinuousBuffer* self)
{
  if (self->empty) {
    return 0;
  }
  if (self->usb_index > self->user_index) {
    return self->usb_index - self->user_index;
  } else {
    return self->header->nb_chunks + self->usb_index - self->user_index;
  }
}

emc_std_size_t EMC_USB_ContinuousBuffer_chunks_to_write(const EMC_USB_ContinuousBuffer* self)
{
  if (self->empty) {
    return self->header->nb_chunks;
  }
  if (self->user_index > self->usb_index) {
    return self->header->nb_chunks - (self->user_index - self->usb_index);
  } else {
    return self->usb_index - self->user_index;
  }
}
