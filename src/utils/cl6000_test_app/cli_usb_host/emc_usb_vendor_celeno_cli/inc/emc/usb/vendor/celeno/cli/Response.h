/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_Response_H
#define EMC_USB_VENDOR_CELENO_CLI_Response_H

#include "emc/usb/vendor/celeno/cli/CommandId.h"
#include "emc/usb/vendor/celeno/cli/Status.h"
#include "emc/usb/vendor/celeno/cli/Version.h"

#include "emc/std/stdint.h"

#if EMC_PRINT
#  include "emc/std/stdio_fwd.h"
#endif

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The Response size according to specification section 6.6.3
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Responses
    @showinitializer
 */
#define EMC_USB_CELENO_CLI_Response_SIZE 20

/** The function IOCTL response data
    @ingroup emdoc_emc_usb_vendor_celeno_cli
 */
typedef struct EMC_USB_CELENO_CLI_FunctionIoctlData {
  emc_std_uint32_t data1; /**< data 1 */
  emc_std_uint32_t data2; /**< data 2 */
} EMC_USB_CELENO_CLI_FunctionIoctlData;

/** The Response according to specification section 6.6.3
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Responses
 */
typedef struct EMC_USB_CELENO_CLI_Response {
  EMC_USB_CELENO_CLI_CommandId id;          /**< identifier */
  emc_std_uint32_t             sequence_id; /**< sequence id */
  EMC_USB_CELENO_CLI_Status    status;      /**< status of operation */
  union {
    EMC_USB_CELENO_CLI_Version           version;       /**< version response */
    EMC_USB_CELENO_CLI_FunctionIoctlData function_data; /**< function IOCTL data */
    emc_std_uint32_t                     data;          /**< single data response */
    emc_std_uint32_t                     reserved[2];   /**< generic reserved */
  } param;                                              /**< the response type specific parameter */

} EMC_USB_CELENO_CLI_Response;

/**
   @relates EMC_USB_CELENO_CLI_Response
   @brief put a Response on a bytestream
 */
void EMC_USB_CELENO_CLI_Response_put(const EMC_USB_CELENO_CLI_Response* self, void** stream);

/**
   @relates EMC_USB_CELENO_CLI_Response
   @brief get a Response from a bytestream
 */
void EMC_USB_CELENO_CLI_Response_get(EMC_USB_CELENO_CLI_Response* self, void** stream);

#if EMC_PRINT
/** @relates EMC_USB_CELENO_CLI_Response @brief Prints a Response */
void EMC_USB_CELENO_CLI_Response_print(const EMC_USB_CELENO_CLI_Response* self, FILE* file);
#endif /*EMC_PRINT*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_Response_H */
