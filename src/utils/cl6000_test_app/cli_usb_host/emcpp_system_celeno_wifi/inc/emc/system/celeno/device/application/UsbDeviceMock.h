/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbDeviceMock_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbDeviceMock_H

#include <stdint.h>
#include <stddef.h>

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

void emc_usb_init_stimulation(void* payload_buffer, size_t payload_buffer_size, uint32_t use_wifi, uint32_t use_bt);
void emc_usb_stimulate(uint32_t use_wifi, uint32_t use_bt);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbDeviceMock_H */
