/** @file
    @brief The continous channel implementation
    Copyright (C) 2014, 2020, 2021 emsys Embedded Systems GmbH */

#ifndef EMC_USB_ISO_ContinuousChannel_H
#define EMC_USB_ISO_ContinuousChannel_H

#include "emc/usb/iso/ContinuousChannel_fwd.h"
#include "emc/usb/alloc/Allocatable.h"

#include "emc/log/log.h"
#include "emc/std/ext/ErrorCodeHandler.h"
#include "emc/hw/memory/MemoryPool.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @struct EMC_USB_ContinuousChannel
 * @ingroup emdoc_emc_usb_iso
 * The generic EM Driver Continuous channel
 */
struct EMC_USB_ContinuousChannel {
  EMC_USB_Allocatable                              alloc_type; /**< Allocatable base type */
  const struct EMC_USB_ContinuousChannelFunctions* call;       /**< the vtable */
  emc_logger_t*                                    logger;     /**< The (optional) logger*/
  void*                                            context;    /**< generic context */
  EMC_ErrorCodeHandler                             on_stop;    /**< handler called on stop situation */
};

#define This EMC_USB_ContinuousChannel /**< Undefined below */

/** @memberof EMC_USB_ContinuousChannel
    The EMC_USB_ContinuousChannel specific function table
 */
typedef struct EMC_USB_ContinuousChannelFunctions {
  /** @privatesection */
  void (* set_buffer)(This*, int* buffer);
  void (* set_usb_and_user_index)(This*, unsigned usb_index, unsigned user_index);
  void (* start)(This*, EMC_ErrorCodeHandler on_stop, int first_frame);
  /** Return current usb chunk address in exchange for current user chunk address */
  int* (*update_progress)(This*, int* user_pos);
  void (* destroy)(This*);
} EMC_USB_ContinuousChannelFunctions;

/** @memberof EMC_USB_ContinuousChannel
    initialize the channel (typically called on ISO EP open)
    @param logger The logger
    @param context The generic context
    @param vtable the function table
 */
void EMC_USB_ContinuousChannel_initialize(This*,
                                          emc_logger_t* logger,
                                          void* context,
                                          const EMC_USB_ContinuousChannelFunctions* vtable);
/** @memberof EMC_USB_ContinuousChannel
    set the buffer to use
    @param buffer The buffer to use is of type Continuous Buffer Header returned by EMC_USB_ContinuousBuffer_buffer
    @pre The buffer must be initialized with the continuous buffer layout information.
    @see ContinuousBufferAccess
 */
void EMC_USB_ContinuousChannel_set_buffer(This*, int* buffer);

/** @memberof EMC_USB_ContinuousChannel
    set both indices
    @param usb_index The position of the USB hardware in the buffer
    @param user_index The position of the user application in the buffer
 */
void EMC_USB_ContinuousChannel_set_usb_and_user_index(This*, int usb_index, int user_index);

/** @memberof EMC_USB_ContinuousChannel
    start the operation
    @param on_stop The handler to be invoke at on stop condition
    @param next_frame The next frame to start
 */
void EMC_USB_ContinuousChannel_start(This*, EMC_ErrorCodeHandler on_stop, int next_frame);

/** @memberof EMC_USB_ContinuousChannel
    update the progress
    @param user_pos The actual user position to inform on
    @return current usb chunk address in exchange for current user chunk address
 */
int* EMC_USB_ContinuousChannel_update_progress(This*, int* user_pos);

/** @memberof EMC_USB_ContinuousChannel
    destroy the channel (typically called on ISO EP close)
 */
void EMC_USB_ContinuousChannel_destroy(This*);
#undef This

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_ISO_ContinuousChannel_H */
