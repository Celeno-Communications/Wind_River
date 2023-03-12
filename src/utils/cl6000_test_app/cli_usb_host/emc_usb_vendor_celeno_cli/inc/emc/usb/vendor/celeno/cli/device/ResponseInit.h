/**
 * @file
 * @brief The initialization of Response objects
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_DEVICE_ResponseInit_H
#define EMC_USB_VENDOR_CELENO_CLI_DEVICE_ResponseInit_H

#include "emc/usb/vendor/celeno/cli/Response.h"
#include "emc/usb/vendor/celeno/cli/Command.h"

#include "emc/std/stdbool.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @relates EMC_USB_CELENO_CLI_Response
 * @brief Initialize Response from Command
 *
 * The id and the sequence_id of the command will be copied into the response,
 * but only if the specification defines a response for this command.
 * The remaining part of the response is cleared, which implies that the status will be SUCCESSS.
 *
 * @param self The response to initialize
 * @param command The command, which has triggered the response
 * @return true, if command has a response, otherwise false
 */
emc_std_bool EMC_USB_CELENO_CLI_Response_init(EMC_USB_CELENO_CLI_Response* self,
                                              const EMC_USB_CELENO_CLI_Command* command);

/**
 * @relates EMC_USB_CELENO_CLI_Response
 * @brief set the version parameter in a GET_VERSION Response
 */
void EMC_USB_CELENO_CLI_Response_set_version(EMC_USB_CELENO_CLI_Response* self,
                                             const EMC_USB_CELENO_CLI_Version* version);

/**
 * @relates EMC_USB_CELENO_CLI_Response
 * @brief set the data paramter in a SINGLE_READ Response
 */
void EMC_USB_CELENO_CLI_Response_set_data(EMC_USB_CELENO_CLI_Response* self,
                                          emc_std_uint32_t data);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_DEVICE_ResponseInit_H */
