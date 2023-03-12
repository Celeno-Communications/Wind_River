/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_Function_private_H
#define EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_Function_private_H

#include "emc/system/celeno/device/iso_transport/Function.h"

#include "emc/system/celeno/device/iso_transport/config.h"
#include "emc/usb/iso/ContinuousBuffer.h"
#include "emc/usb/driver/dwc3/device/Dwc3ContinuousChannel.h"
#include "eme/usb/vendor/iso/IsoEndpoint.h"

#include "emc/usb/device/Interface_fwd.h"
#include "emc/std/stdbool.h"
#include "emc/hw/MemoryRange.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** @brief The implementation structure for the ISO transport test function.
 *
 * The function generates or receives one ISO stream. 1. DWORD is a sequence number,
 * all other DWORD have conentent = position.
 */
struct EMC_USB_CELENO_ISO_Function {
  EMC_USB_CELENO_ISO_FunctionConfig config; /**< the function configuration parameters */

  EMC_USB_Interface* interface;             /**< the underlying USB interface */
  emc_logger_t*      logger;                /**< The logger instance */
  emc_std_bool       configured;            /**< the current configured state (USB semantics) */
  emc_std_bool       data_transport_active; /**< true if an alternate setting with data endpoints is set */

  EMC_MemoryRange in_ep_dma_memory;
  EMC_MemoryRange out_ep_dma_memory;

  EMC_USB_EndpointAttributes in_ep_attributes;
  EMC_USB_EndpointAttributes out_ep_attributes;

  EMC_USB_IsoEndpoint in_ep;
  EMC_USB_IsoEndpoint out_ep;

  emc_std_uint32_t in_sequence;
  emc_std_uint32_t out_sequence;
};

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_Function_private_H */
