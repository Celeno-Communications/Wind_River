/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_CommandId_H
#define EMC_USB_VENDOR_CELENO_CLI_CommandId_H

#include "emc/usb/vendor/celeno/cli/configure.h"
#include "emc/std/stdint.h"
#include "emc/std/stdbool.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The command ID according to specification section 6.6.3
    @ingroup emdoc_emc_usb_vendor_celeno_cli
 */
typedef enum EMC_USB_CELENO_CLI_CommandId {
  EMC_USB_CELENO_CLI_CommandId_GET_VERSION           = 0x01, /**< Get version */
  EMC_USB_CELENO_CLI_CommandId_SINGLE_READ           = 0x02, /**< Single Read */
  EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE          = 0x03, /**< Single Write */
  EMC_USB_CELENO_CLI_CommandId_SINGLE_WRITE_FAST     = 0x04, /**< Single Write Fast */
  EMC_USB_CELENO_CLI_CommandId_KEEP_ALIVE            = 0x05, /**< Keep alive */
  EMC_USB_CELENO_CLI_CommandId_DISCONNECT_USB        = 0x06, /**< Disconnect USB */
  EMC_USB_CELENO_CLI_CommandId_UMAC_EXECUTE          = 0x07, /**< UMAC Execute */
  EMC_USB_CELENO_CLI_CommandId_UMAC_RESTART          = 0x08, /**< Umac restart */
  EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_GET      = 0x11, /**< Get current logging level of specific logger */
  EMC_USB_CELENO_CLI_CommandId_LOGGER_LEVEL_SET      = 0x12, /**< Set current logging level of specific logger */
  EMC_USB_CELENO_CLI_CommandId_LOGGER_INFO_GET       = 0x10, /**< Get information for a specific logger */
  EMC_USB_CELENO_CLI_CommandId_BULK_READ_ZCOPY       = 0x80, /**< Bulk Read with zero copy */
  EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_ZCOPY      = 0x81, /**< Bulk Write with zero copy */
  EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST_ZCOPY = 0x82, /**< Bulk Write Fast with zero copy */
  EMC_USB_CELENO_CLI_CommandId_BULK_READ             = 0x88, /**< Bulk Read buffered */
  EMC_USB_CELENO_CLI_CommandId_BULK_WRITE            = 0x89, /**< Bulk Write buffered */
  EMC_USB_CELENO_CLI_CommandId_BULK_WRITE_FAST       = 0x8A, /**< Bulk Write Fast buffered */
  EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_0      = 0x90, /**< Function IO Control #0 */
  EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_1      = 0x91, /**< Function IO Control #1 */
  EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_2      = 0x92, /**< Function IO Control #2 */
  EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL_3      = 0x93  /**< Function IO Control #3 */
} EMC_USB_CELENO_CLI_CommandId;

/** Returns true if a response is expected for commands of the given ID, false otherwise
    @ingroup emdoc_emc_usb_vendor_celeno_cli
 */
emc_std_bool EMC_USB_CELENO_CLI_CommandId_has_response(EMC_USB_CELENO_CLI_CommandId id);

#if EMC_PRINT
/** Returns the id as string */
const char* EMC_USB_CELENO_CLI_CommandId_as_string(EMC_USB_CELENO_CLI_CommandId id);
#endif /*EMC_PRINT*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_CommandId_H */
