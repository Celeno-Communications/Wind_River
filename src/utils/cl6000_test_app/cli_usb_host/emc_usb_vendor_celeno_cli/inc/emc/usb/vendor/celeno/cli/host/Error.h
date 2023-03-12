/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_HOST_Error_H
#define EMC_USB_VENDOR_CELENO_CLI_HOST_Error_H

#include "emc/usb/vendor/celeno/cli/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** Error codes reported on the Host API
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Host
 */
typedef enum EMC_USB_CELENO_CLI_Error {
  EMC_USB_CELENO_CLI_Error_PENDING                 = 1,   /**< the operation is queued, still in progress */
  EMC_USB_CELENO_CLI_Error_SUCCESS                 = 0,   /**< operation successful */
  EMC_USB_CELENO_CLI_Error_TIMEOUT                 = -1,  /**< timeout occurred */
  EMC_USB_CELENO_CLI_Error_CONNECTION_ERROR        = -2,  /**< any connection error */
  EMC_USB_CELENO_CLI_Error_INVALID_PARAMETER       = -3,  /**< invalid parameter */
  EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_TYPE   = -4,  /**< invalid type/id of response */
  EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_STATUS = -5,  /**< invalid status in response */
  EMC_USB_CELENO_CLI_Error_INVALID_RESPONSE_LENGTH = -6,  /**< invalid response length */
  EMC_USB_CELENO_CLI_Error_INVALID_VERSION         = -7,  /**< invalid version */
  EMC_USB_CELENO_CLI_Error_QUEUEING_NOT_ALLOWED    = -8,  /**< queuing not allowed for this type of command */
  EMC_USB_CELENO_CLI_Error_QUEUE_OVERFLOW          = -9,  /**< queue overflow */
  EMC_USB_CELENO_CLI_Error_QUEUE_EMPTY             = -10, /**< no commands queued */
  EMC_USB_CELENO_CLI_Error_GENERIC                 = -11  /**< generic */
} EMC_USB_CELENO_CLI_Error;

/** Returns the error as string */
const char* EMC_USB_CELENO_CLI_Error_as_string(EMC_USB_CELENO_CLI_Error error);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_HOST_Error_H */
