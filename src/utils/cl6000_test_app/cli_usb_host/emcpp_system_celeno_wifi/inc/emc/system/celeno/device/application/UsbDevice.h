/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbDevice_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbDevice_H

#include <stdint.h>
#include <stddef.h>

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The factory function that initializes the functions of the USB device in APP context */
typedef uint8_t* emc_usb_function_factory (uint8_t* dma_memory);

void emc_usb_init(emc_usb_function_factory* func_factory);

void emc_usb_shutdown(void);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbDevice_H */
