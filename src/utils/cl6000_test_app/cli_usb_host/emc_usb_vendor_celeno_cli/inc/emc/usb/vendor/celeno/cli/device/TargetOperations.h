/**
 * @file
 * @brief
 * @author  <ralf.oberlaender@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_DEVICE_TargetOperations_H
#define EMC_USB_VENDOR_CELENO_CLI_DEVICE_TargetOperations_H

#include "emc/usb/vendor/celeno/cli/configure.h"
#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**@brief Waits, Disconnects USB and waits again
   @param usb_disconnect_delay_ms The time to wait until usb will be disconnected ms
   @param idle_time_ms Time to wait after disconnect ms
 */
void EMC_USB_CELENO_CLI_usb_disconnect(uint32_t usb_disconnect_time_ms, uint32_t idle_time_ms);

/**@brief Executes UMAC at given address
   @param jump_address The address of the code to execute
 */
void EMC_USB_CELENO_CLI_umac_execute(void* jump_address);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_DEVICE_TargetOperations_H */
