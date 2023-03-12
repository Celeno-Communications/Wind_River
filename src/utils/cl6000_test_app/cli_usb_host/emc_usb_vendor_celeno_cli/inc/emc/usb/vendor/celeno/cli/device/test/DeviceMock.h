/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_DEVICE_TEST_DeviceMock_H
#define EMC_USB_VENDOR_CELENO_CLI_DEVICE_TEST_DeviceMock_H

#include "emc/usb/vendor/celeno/cli/configure.h"

#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** return 1 if success else 0 */
int create_and_enumerate_device(void);
void destroy_device(void);

/** return 1 if success else 0 */
int configure_device(emc_std_uint8_t config);

/** return 1 if success else 0 */
int set_alt_setting(emc_std_uint8_t interface, emc_std_uint8_t alt_setting);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_DEVICE_TEST_DeviceMock_H */
