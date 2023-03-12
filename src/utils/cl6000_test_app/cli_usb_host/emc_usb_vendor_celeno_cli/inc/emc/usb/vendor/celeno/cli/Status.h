/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_Status_H
#define EMC_USB_VENDOR_CELENO_CLI_Status_H

#include "emc/usb/vendor/celeno/cli/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The status codes according to specification section 6.6.3
    @ingroup emdoc_emc_usb_vendor_celeno_cli
 */
typedef enum EMC_USB_CELENO_CLI_Status {
  EMC_USB_CELENO_CLI_Status_SUCCESS                = 0x00, /**< Operation successfull */
  EMC_USB_CELENO_CLI_Status_INVALID_COMMAND_CODE   = 0x01, /**< invalid CommandId */
  EMC_USB_CELENO_CLI_Status_INVALID_COMMAND_LENGTH = 0x02, /**< invalid Command length */
  EMC_USB_CELENO_CLI_Status_INVALID_OFFSET         = 0x03, /**< invalid offset */
  EMC_USB_CELENO_CLI_Status_INVALID_ADDRESS        = 0x04, /**< invalid address */
  EMC_USB_CELENO_CLI_Status_CRC_MISMATCH           = 0x05, /**< CRC mismatch */
  EMC_USB_CELENO_CLI_Status_INVALID_FUNCTION_ERROR = 0x06, /**< Invalid function called */
  EMC_USB_CELENO_CLI_Status_FUNCTION_ERROR         = 0x07  /**< Function returns an error */
} EMC_USB_CELENO_CLI_Status;

#if EMC_PRINT
/** Returns the status as string */
const char* EMC_USB_CELENO_CLI_Status_as_string(EMC_USB_CELENO_CLI_Status status);
#endif /*EMC_PRINT*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_Status_H */
