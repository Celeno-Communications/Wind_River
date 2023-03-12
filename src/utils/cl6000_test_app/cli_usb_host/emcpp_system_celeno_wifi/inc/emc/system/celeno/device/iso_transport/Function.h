/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_Function_H
#define EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_Function_H

#include "emc/std/stdint.h"
#include "emc/std/stddef.h"
#include "emc/log/log.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

typedef struct EMC_USB_CELENO_ISO_Function EMC_USB_CELENO_ISO_Function;

/** @relates EMC_USB_CELENO_Wifi_Function @brief The Configuration of the Function */
typedef struct EMC_USB_CELENO_ISO_FunctionConfig_s {
  emc_std_uint8_t interface_number; /**< The interface number, default-initialized by init function */
  void*           buffer;           /**< The physical buffer for internal use*/
  emc_std_size_t  buffer_size;      /**< The size of the buffer */
} EMC_USB_CELENO_ISO_FunctionConfig;

/** Initialize @param config wit default values */
void EMC_USB_CELENO_ISO_FunctionConfig_init(EMC_USB_CELENO_ISO_FunctionConfig* config);

/**
 * Initialize the function.
 *
 * The function is called first.
 * @param self the instance of the function
 * @param config the instance configuration
 */
void EMC_USB_CELENO_ISO_Function_init(EMC_USB_CELENO_ISO_Function* self,
                                      const EMC_USB_CELENO_ISO_FunctionConfig* config);

void EMC_USB_CELENO_ISO_Function_poll(EMC_USB_CELENO_ISO_Function* self);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_Function_H */
