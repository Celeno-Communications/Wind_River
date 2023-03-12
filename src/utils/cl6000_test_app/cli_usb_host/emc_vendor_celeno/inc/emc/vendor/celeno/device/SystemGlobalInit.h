/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_VENDOR_CELENO_DEVICE_SystemGlobalInit_H
#define EMC_VENDOR_CELENO_DEVICE_SystemGlobalInit_H

#include "emc/std/stdint.h"

/**
 * Perform global system initialization. This function must be called before connecting to USB.
 *
 * @param sram_base_address The base address of the Shared RAM (UMAC view).
 */
void EMC_USB_CELENO_system_global_init(emc_std_uintptr_t sram_base_address);

#endif /* EMC_VENDOR_CELENO_DEVICE_SystemGlobalInit_H */
