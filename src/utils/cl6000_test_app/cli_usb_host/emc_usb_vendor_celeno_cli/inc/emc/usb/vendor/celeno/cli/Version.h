/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_Version_H
#define EMC_USB_VENDOR_CELENO_CLI_Version_H

#include "emc/usb/vendor/celeno/cli/configure.h"

#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The application identifier part of the firmware version
    @ingroup emdoc_emc_usb_vendor_celeno_cli
 */
typedef enum EMC_USB_CELENO_APP_ID {
  EMC_USB_CELENO_APP_ID_UNDEFINED  = 0,
  EMC_USB_CELENO_APP_ID_BOOTLOADER = 1,
  EMC_USB_CELENO_APP_ID_WIFI_BT    = 2,
  EMC_USB_CELENO_APP_ID_TP_TEST    = 3,
} EMC_USB_CELENO_APP_ID;

/** The Version information according to specification
    @ingroup emdoc_emc_usb_vendor_celeno_cli
 */
typedef struct EMC_USB_CELENO_CLI_Version {
  emc_std_uint32_t protocol; /**< Protocol version */
  emc_std_uint32_t firmware; /**< Firmware version */
} EMC_USB_CELENO_CLI_Version;

/**
    @relates EMC_USB_CELENO_CLI_Version
    @brief Initialize the Version from defines in this module and the project version information

    Uses @ref EMC_USB_VENDOR_CELENO_CLI_PROTOCOL_VERSION for protocol version.

    @param self The Version to initialize
    @param app_version The full version of the owning APP (version/ID/build))
 */
void EMC_USB_CELENO_CLI_Version_init(EMC_USB_CELENO_CLI_Version* self,
                                     emc_std_uint32_t app_version);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_Version_H */
