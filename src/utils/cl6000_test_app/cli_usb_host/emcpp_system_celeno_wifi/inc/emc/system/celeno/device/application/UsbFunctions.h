/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbFunctions_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbFunctions_H

#include <stdint.h>

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

uint8_t* emc_usb_init_cli(uint8_t* dma_mem_chunk);

uint8_t* emc_usb_init_usbwrapper(uint8_t* dma_mem_chunk);
uint8_t* emc_usb_init_wifi(uint8_t* dma_mem_chunk);
uint8_t* emc_usb_init_bluetooth(uint8_t* dma_mem_chunk);

uint8_t* emc_usb_init_ecm(uint8_t* dma_mem_chunk);

uint8_t* emc_usb_init_functions_offload(uint8_t* dma_memory);

void emc_usb_poll_wifi(void);
void emc_usb_poll_bt(void);
void emc_usb_poll_ecm(void);

void emc_usb_tick_wifi(void);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_UsbFunctions_H */
