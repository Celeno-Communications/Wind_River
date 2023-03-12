/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_configure_H
#define EMC_USB_VENDOR_CELENO_CLI_configure_H

#include "emc/config/configure.h"

#include "emc_usb_vendor_celeno_cli/cmakeConfigure.h"

/**
 * @page emdoc_emc_usb_vendor_page USB Vendor Specific Components
 * @copybrief emdoc_emc_usb_vendor_celeno_cli
 *
 * @defgroup emdoc_emc_usb_vendor_celeno_cli USB Vendor (celeno) Specific Protocol (cli)
 * @ingroup emsys_modules
 *
 * @brief The @ref emdoc_emc_usb_vendor_celeno_cli library contains the vendor specific CLI protocol implementation
 *
 * This module is a complete implementation of the \ref emdoc_emc_usb_vendor_celeno_cli_Specifications.
 * That means it has all components to implement Host or Device side of this protocol.
 *
 * For configuration of the module use:
 * - \ref emdoc_emc_usb_vendor_celeno_cli_Defines "Defines" for Compile Time Configuration
 *
 * @defgroup emdoc_emc_usb_vendor_celeno_cli_Specifications CLI Specifications
 * @ingroup emdoc_Specifications
 * @brief CLI Specifications
 *
 * @defgroup emdoc_emc_usb_vendor_celeno_cli_Defines Defines
 * @ingroup emdoc_emc_usb_vendor_celeno_cli
 * @ingroup emdoc_Defines
 *
 * @brief Compile Time Defines for emc_usb_vendor_celeno_cli module
 *
 * Defines to  be configured at compile time.
 *
 * @defgroup emdoc_emc_usb_vendor_celeno_cli_Commands Commands
 * @ingroup emdoc_emc_usb_vendor_celeno_cli
 *
 * @brief Commands
 *
 * The Commands transferred via Bulk-Out Pipe from Host to Device
 *
 * @defgroup emdoc_emc_usb_vendor_celeno_cli_Responses Responses
 * @ingroup emdoc_emc_usb_vendor_celeno_cli
 *
 * @brief Responses
 *
 * The Responses transferred via Bulk-In Pipe from Device to Host to respond on Commands
 *
 * @defgroup emdoc_emc_usb_vendor_celeno_cli_Host Host
 * @ingroup emdoc_emc_usb_vendor_celeno_cli
 *
 * @brief Host
 *
 * The Host sends Commands and receives Responses.
 *
 * @defgroup emdoc_emc_usb_vendor_celeno_cli_Device Device
 * @ingroup emdoc_emc_usb_vendor_celeno_cli
 *
 * @brief Device
 *
 * The Device receives Commands and responds with Responses.
 *
 */

/** Out Endpoint address (rx)
   @ingroup emdoc_emc_usb_vendor_celeno_cli_Defines
   @showinitializer
 */
#define CELENO_CLI_BULK_OUT 0x01

/** In Endpoint address (tx)
   @ingroup emdoc_emc_usb_vendor_celeno_cli_Defines
   @showinitializer
 */
#define CELENO_CLI_BULK_IN 0x81

/** The implemented cli protocol version major value
 * @ingroup emdoc_emc_usb_vendor_celeno_cli_Specifications
 * @showinitializer
 */
#ifndef EMC_USB_VENDOR_CELENO_CLI_PROTOCOL_VERSION
#  define EMC_USB_VENDOR_CELENO_CLI_PROTOCOL_VERSION 0x00000105
#endif

/** The maximum command transfer length for "Combined Simple Commands" according to specification 6.6.3.2
 * @ingroup emdoc_emc_usb_vendor_celeno_cli_Defines
 * @showinitializer
 */
#ifndef EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH
#  define EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH (1024)
#endif

/** The maximum data transfer length for "Data Commands" according to specification 6.6.3.3
 * @ingroup emdoc_emc_usb_vendor_celeno_cli_Defines
 * @showinitializer
 */
#ifndef EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_LENGTH
#  define EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_LENGTH (32 * 1024)
#endif

/** Maximum number of IOCTL functions
 * @ingroup emdoc_emc_usb_vendor_celeno_cli_Defines
 * @showinitializer
 */
#ifndef EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX
#  define EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX (4)
#endif

#endif /* EMC_USB_VENDOR_CELENO_CLI_configure_H */
