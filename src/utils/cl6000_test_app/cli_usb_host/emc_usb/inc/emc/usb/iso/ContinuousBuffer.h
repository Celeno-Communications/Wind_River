/** @file
    @brief This module defines the ContinuousBuffer that is used by the ContinuousChannel
    Copyright (C) 2021 emsys Embedded Systems GmbH */

#ifndef EMC_USB_ISO_ContinuousBuffer_H
#define EMC_USB_ISO_ContinuousBuffer_H

#include "emc/hw/MemoryRange.h"
#include "emc/usb/iso/ContinuousChannel_fwd.h"

#include "emc/std/stddef.h"
#include "emc/std/stdint.h"
#include "emc/std/stdbool.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** the status information for each transferred (micro)frame chunk */
typedef struct EMC_USB_ContinuousBuffer_Status {
  emc_std_int32_t  length;          /**< length in bytes or the 2-er complement on error */
  emc_std_uint32_t sequence_number; /**< the (micro-)frame where it was transferred */
} EMC_USB_ContinuousBuffer_Status;

/** @return true on error */
static inline emc_std_bool EMC_USB_ContinuousBuffer_Status_error(const EMC_USB_ContinuousBuffer_Status* self)
{ return self->length < 0; }

/** @return the length of the transfer */
static inline emc_std_size_t EMC_USB_ContinuousBuffer_Status_length(const EMC_USB_ContinuousBuffer_Status* self)
{ return (emc_std_size_t)self->length; }

/** set the length */
static inline void EMC_USB_ContinuousBuffer_Status_set_length(EMC_USB_ContinuousBuffer_Status* self,
                                                              emc_std_size_t length)
{ self->length = (emc_std_int32_t)length; }

/** @return the sequence number */
static inline emc_std_uint32_t EMC_USB_ContinuousBuffer_Status_sequence(const EMC_USB_ContinuousBuffer_Status* self)
{ return self->sequence_number; }

/** the continuous buffer header as defined by the EMC_USB_ContinuousChannel_set_buffer API */
typedef struct EMC_USB_ContinuousBuffer_Header {
  /** The offset of the first payload data in size of int */
  emc_std_uint32_t chunk_offset_words;
  /** the number of chunks maintained by this buffer */
  emc_std_uint32_t nb_chunks;
  /** the maximum number of int words in one chunk */
  emc_std_uint32_t chunk_capacity;
} EMC_USB_ContinuousBuffer_Header;

/** Calculate the size in bytes of the complete EMC_USB_ContinuousBuffer_Header */
#define EMC_USB_CONTINUOUS_BUFFER_SIZE(nb_chunks, chunk_capacity) \
  (sizeof(EMC_USB_ContinuousBuffer_Header) \
   + (nb_chunks) * sizeof(EMC_USB_ContinuousBuffer_Status) \
   + (nb_chunks) * (chunk_capacity) * sizeof(emc_std_uint32_t))

/** the continuous buffer instance */
typedef struct EMC_USB_ContinuousBuffer {
  EMC_USB_ContinuousBuffer_Header* header;        /**< the header information */
  EMC_USB_ContinuousBuffer_Status* status;        /**< the status information (one per chunk) */
  emc_std_int32_t*                 payload_begin; /**< begin of the payload */
  emc_std_size_t                   user_index;    /**< zero based user index */
  emc_std_size_t                   usb_index;     /**< zero based usb index */
  emc_std_bool                     empty;         /**< flag that is true if the buffer is empty */
  emc_std_bool                     direction_out; /**< true if the data flow is out */
} EMC_USB_ContinuousBuffer;

/** initialize the buffer
 * @param self The instance
 * @param buffer_mem The DMA memory that have at least the size returned by EMC_USB_CONTINUOUS_BUFFER_SIZE
 * The storage must be valid as long as the buffer is used
 * @param nb_chunks The number of chunks maintained inthis buffer
 * @param chunk_capacity The maximum size that can be transferred in size of int
 * @param direction_out True for host-to-device transfer, false otherwise
 */
void EMC_USB_ContinuousBuffer_init(EMC_USB_ContinuousBuffer* self,
                                   EMC_MemoryRange buffer_mem,
                                   emc_std_uint32_t nb_chunks,
                                   emc_std_uint32_t chunk_capacity,
                                   emc_std_bool direction_out);

/** @returns the complete continuous buffer as used by EMC_USB_ContinuousChannel_set_buffer */
static inline emc_std_int32_t* EMC_USB_ContinuousBuffer_buffer(const EMC_USB_ContinuousBuffer* self)
{ return (emc_std_int32_t*)self->header; }

/** @returns the number of chunks in the buffer */
static inline emc_std_uint32_t EMC_USB_ContinuousBuffer_chunks(const EMC_USB_ContinuousBuffer* self)
{ return self->header->nb_chunks; }

/** @returns the capacity of the chunks in the buffer in bytes */
static inline emc_std_size_t EMC_USB_ContinuousBuffer_chunk_capacity(const EMC_USB_ContinuousBuffer* self)
{ return self->header->chunk_capacity * sizeof(emc_std_int32_t); }

/** @return the status of the current user position */
static inline EMC_USB_ContinuousBuffer_Status* EMC_USB_ContinuousBuffer_status(const EMC_USB_ContinuousBuffer* self)
{ return &self->status[self->user_index]; }

/** synchronize the local state with the state of the given continuous channel */
void EMC_USB_ContinuousBuffer_update(EMC_USB_ContinuousBuffer* self, EMC_USB_ContinuousChannel* channel);

/** @return a pointer to the begin of the current user chunk. Can be used to call
   EMC_USB_ContinuousChannel_update_progress */
static inline emc_std_int32_t* EMC_USB_ContinuousBuffer_user_pos(const EMC_USB_ContinuousBuffer* self)
{ return self->payload_begin + self->user_index * self->header->chunk_capacity; }

/** @return a pointer to the begin of the current usb chunk. */
static inline emc_std_int32_t* EMC_USB_ContinuousBuffer_usb_pos(const EMC_USB_ContinuousBuffer* self)
{ return self->payload_begin + self->usb_index * self->header->chunk_capacity; }

/** @return a pointer to the usb chunk of @param self that follows the given @param usb_pos */
emc_std_int32_t* EMC_USB_ContinuousBuffer_next_usb_pos(const EMC_USB_ContinuousBuffer* self, emc_std_int32_t* usb_pos);

/**
 * Is called if a chunk was added or read
 * @param self The instance
 * @return The pointer to user chunk after incrementing the buffer position.
 */
emc_std_int32_t* EMC_USB_ContinuousBuffer_inc_user_pos(EMC_USB_ContinuousBuffer* self);

/** Increment the current usb chunk of @param self by one. Use with caution! */
void EMC_USB_ContinuousBuffer_inc_usb_pos(EMC_USB_ContinuousBuffer* self);

/**
 * Set the USB position with the pointer returned by EMC_USB_ContinuousChannel_update_progress().
 *
 * @param self instance
 * @param usb_pos The position returned by EMC_USB_ContinuousChannel_update_progress()
 * @return true if the position was modified since the last call.
 */
emc_std_bool EMC_USB_ContinuousBuffer_set_usb_pos(EMC_USB_ContinuousBuffer* self, emc_std_int32_t* usb_pos);

/** @return the number of chunks that can be read from the buffer */
emc_std_size_t EMC_USB_ContinuousBuffer_chunks_to_read(const EMC_USB_ContinuousBuffer* self);

/** @return the number of chunks that can be written to the buffer */
emc_std_size_t EMC_USB_ContinuousBuffer_chunks_to_write(const EMC_USB_ContinuousBuffer* self);

/** @return the buffer to the current user position. It is used to access the payload */
static inline void* EMC_USB_ContinuousBuffer_chunk_buffer(const EMC_USB_ContinuousBuffer* self)
{ return (void*)(self->payload_begin + self->user_index * self->header->chunk_capacity); }

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_ISO_ContinuousBuffer_H */
