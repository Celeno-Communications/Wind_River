/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_DEVICE_Function_H
#define EMC_USB_VENDOR_CELENO_CLI_DEVICE_Function_H

#include "emc/usb/vendor/celeno/cli/device/Function_fwd.h"
#include "emc/usb/vendor/celeno/cli/Version.h"

#include "emc/std/stdbool.h"
#include "emc/std/stdint.h"
#include "emc/std/stddef.h"
#include "emc/log/log.h"

#if EMC_PRINT
#  include "emc/std/stdio_fwd.h"
#endif

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** @relates EMC_USB_CELENO_CLI_Function @brief The Configuration of the Function */
typedef struct EMC_USB_CELENO_CLI_FunctionConfig {
  emc_std_uint8_t  interface_number; /**< The interface number */
  void*            buffer;           /**< The physical buffer for internal use*/
  emc_std_size_t   buffer_size;      /**< The size of the buffer */
  emc_std_uint32_t app_version;      /**< The version of the APP that owns the function */
} EMC_USB_CELENO_CLI_FunctionConfig;

/** @relates EMC_USB_CELENO_CLI_FunctionConfig initialize a default CLI function config */
void EMC_USB_CELENO_CLI_FunctionConfig_init(EMC_USB_CELENO_CLI_FunctionConfig* self);

/** @relates EMC_USB_CELENO_CLI_Function @brief Initialize a Function */
void EMC_USB_CELENO_CLI_Function_init(EMC_USB_CELENO_CLI_Function* self,
                                      const EMC_USB_CELENO_CLI_FunctionConfig* config);

/** @relates EMC_USB_CELENO_CLI_Function @brief start Function and return true in case of success */
emc_std_bool EMC_USB_CELENO_CLI_Function_start(EMC_USB_CELENO_CLI_Function* self);

/** @relates EMC_USB_CELENO_CLI_Function @brief stop Function */
void EMC_USB_CELENO_CLI_Function_stop(EMC_USB_CELENO_CLI_Function* self);

/** @relates EMC_USB_CELENO_CLI_Function
 * @brief Function prototype used for function IOCTL calls.
 * @param context The context passed during registration.
 * @param command The command to execute, protocol specific.
 * @param param1 The parameter 1, protocol specific.
 * @param param2 The parameter 2, protocol specific.
 * @param[out] data1 The optional returned data1, protocol specific.
 * @param[out] data2 The optional returned data2, protocol specific.
 */
typedef emc_std_bool EMC_USB_CELENO_CLI_FunctionIoctl (
  void* context,
  emc_std_uint32_t command,
  emc_std_uint32_t param1,
  emc_std_uint32_t param2,
  emc_std_uint32_t* data1,
  emc_std_uint32_t* data2
  );

/** @relates EMC_USB_CELENO_CLI_Function
 * @brief Function prototype used for command hook function .
 * @param context The context passed during registration.
 * @param command The current command of the cli function.
 */
typedef void EMC_USB_CELENO_CLI_CommandCallback (
  void* context,
  emc_std_uint32_t command
  );

/** @relates EMC_USB_CELENO_CLI_Function
 * @brief Register an IOCTL function. It is called if an IOCTL command from host is received.
 * @param self
 * @param index The zero based index of the function < EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX
 * @param function The pointer to the function
 * @param context the context passed to the function
 */
void EMC_USB_CELENO_CLI_Function_register_function_ioctl(EMC_USB_CELENO_CLI_Function* self,
                                                         emc_std_uint32_t index,
                                                         EMC_USB_CELENO_CLI_FunctionIoctl* function,
                                                         void* context);

/** @relates EMC_USB_CELENO_CLI_Function
 * @brief Register a callback function. It is called for every command from host before processing.
 * @param self
 * @param function The pointer to the function
 * @param context the context passed to the function
 */void EMC_USB_CELENO_CLI_Function_register_command_hook(EMC_USB_CELENO_CLI_Function* self,
                                                       EMC_USB_CELENO_CLI_CommandCallback* function,
                                                       void* context);

#if EMC_PRINT
/** @relates EMC_USB_CELENO_CLI_Function @brief Prints a Function */
void EMC_USB_CELENO_CLI_Function_print(const EMC_USB_CELENO_CLI_Function* self, FILE* file);
#endif /*EMC_PRINT*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_DEVICE_Function_H */
