/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_HOST_FunctionProxy_H
#define EMC_USB_VENDOR_CELENO_CLI_HOST_FunctionProxy_H

#include "emc/usb/vendor/celeno/cli/host/FunctionProxy_fwd.h"
#include "emc/usb/vendor/celeno/cli/host/Error.h"

#include "emc/usb/vendor/celeno/cli/Command.h"
#include "emc/usb/vendor/celeno/cli/Response.h"
#include "emc/std/stddef.h"
#include "emc/std/stdbool.h"

#if EMC_PRINT
#  include "emc/std/stdio_fwd.h"
#endif

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The configuration values for the CLI Function Proxy */
typedef struct EMC_USB_CELENO_CLI_FunctionProxyConfig {
  emc_std_uint16_t pid;                 /**< USB PID */
  emc_std_uint16_t bcd_device;          /**< USB bcdDevice (optional, 0 for don't care) */
  emc_std_uint8_t* sn;                  /**< USB Serial number string, will be ignored if NULL */
  emc_std_uint32_t transfer_timeout_ms; /**< Bulk Transfer timeout in ms */
} EMC_USB_CELENO_CLI_FunctionProxyConfig;

/** Initialize @param config with default values */
void EMC_USB_CELENO_CLI_FunctionProxyConfig_init(EMC_USB_CELENO_CLI_FunctionProxyConfig* config);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Initialize an FunctionProxy, but does not start any processing
 * @param self the instance of the FunctionProxy
 * @param config the instance configuration
 */
int EMC_USB_CELENO_CLI_FunctionProxy_init(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                          const EMC_USB_CELENO_CLI_FunctionProxyConfig* config);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Check, if FunctionProxy was initialized
 */
int EMC_USB_CELENO_CLI_FunctionProxy_initialized(EMC_USB_CELENO_CLI_FunctionProxy* self);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief De-Initialize an FunctionProxy
 */
void EMC_USB_CELENO_CLI_FunctionProxy_exit(EMC_USB_CELENO_CLI_FunctionProxy* self);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Start processing in FunctionProxy
 */
int EMC_USB_CELENO_CLI_FunctionProxy_start(EMC_USB_CELENO_CLI_FunctionProxy* self);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Stop processing in FunctionProxy
 */
int EMC_USB_CELENO_CLI_FunctionProxy_stop(EMC_USB_CELENO_CLI_FunctionProxy* self);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Reset the function by switching the alternate setting
 */
int EMC_USB_CELENO_CLI_FunctionProxy_reset(EMC_USB_CELENO_CLI_FunctionProxy* self);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief any command transaction with given id w/o any parameters
   @param self The context
   @param id The command ID to be used
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_any_command(EMC_USB_CELENO_CLI_FunctionProxy* self, uint32_t id);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief get version transaction
   @param self The context
   @param protocol pointer to protocol version
   @param firmware pointer to firmware version
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_get_version(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                 uint32_t* protocol,
                                                 uint32_t* firmware);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief keep alive transaction
   @param self The context
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_keep_alive(EMC_USB_CELENO_CLI_FunctionProxy* self);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief usb disconnect transaction
   @param self The context
 * @param usb_disconnect_delay_ms The disconnect delay
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_usb_disconnect(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                    emc_std_uint32_t usb_disconnect_delay_ms);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief UMAC execute/jump transaction
   @param self The context
   @param jump_address The jump address
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_umac_execute(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                  emc_std_uint32_t jump_address);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief umac restart operation
   @param self The context
   @param usb_disconnect_delay_ms The time to wait until usb will be disconnected ms
   @param restart_delay_ms The delay between usb disconnect and jump to address in ms
   @param jump_address The address of the code to execute
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_umac_restart(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                  emc_std_uint32_t usb_disconnect_delay_ms,
                                                  emc_std_uint32_t restart_delay_ms,
                                                  emc_std_uint32_t jump_address);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Get logging level (verbosity) of a specific logger
   @param self The context
   @param index The zero-based index of the logger
   @param level Caller-provided variable that will receive the logging level
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_logger_level_get(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                      emc_std_uint32_t index,
                                                      emc_std_uint32_t* level);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Set logging level (verbosity) of a specific logger
   @param self The context
   @param index The zero-based index of the logger
   @param level The logging level to set
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_logger_level_set(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                      emc_std_uint32_t index,
                                                      emc_std_uint32_t level);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Get information for specific logger
   @param self The context
   @param index The zero-based index of the logger
   @param info_string The buffer to store the logger information
   @param size    The size of info_string
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_logger_info_get(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                     emc_std_uint32_t index,
                                                     char* info_string,
                                                     size_t size);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief write transaction with response
   @param self The context
   @param address The target address
   @param data    The data to write
   @param mask    The mask of data
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_write(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                           emc_std_uint32_t address,
                                           emc_std_uint32_t data,
                                           emc_std_uint32_t mask);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief write transaction without response
   @param self The context
   @param address The target address
   @param data    The data to write
   @param mask    The mask of data
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_write_fast(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                emc_std_uint32_t address,
                                                emc_std_uint32_t data,
                                                emc_std_uint32_t mask);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief read transaction
   @param self The context
   @param address The target address
   @param data    contains the data if operation was successful
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_read(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                          emc_std_uint32_t address,
                                          emc_std_uint32_t* data);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief burst write transaction with response
   @param self The context
   @param address The target address
   @param data    The data to write
   @param size    The size of data
   @param zero_copy True to use zero copy operation
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_burst_write(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                 emc_std_uint32_t address,
                                                 const void* data,
                                                 size_t size,
                                                 emc_std_bool zero_copy);
/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief burst write transaction without response
   @param self The context
   @param address The target address
   @param data    The data to write
   @param size    The size of data
   @param zero_copy True to use zero copy operation
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_burst_write_fast(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                      emc_std_uint32_t address,
                                                      const void* data,
                                                      size_t size,
                                                      emc_std_bool zero_copy);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief burst read transaction
   @param self The context
   @param address The target address
   @param data    The buffer to store data read
   @param size    The size of data
   @param zero_copy True to use zero copy operation
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_burst_read(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                emc_std_uint32_t address,
                                                void* data,
                                                size_t size,
                                                emc_std_bool zero_copy);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Start queueing of commands in FunctionProxy
 */
void EMC_USB_CELENO_CLI_FunctionProxy_queue_begin(EMC_USB_CELENO_CLI_FunctionProxy* self);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief Stop queueing of commands and process all queued commands
 */
int EMC_USB_CELENO_CLI_FunctionProxy_queue_process(EMC_USB_CELENO_CLI_FunctionProxy* self);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief write raw data on USB endpoint
   @param self The context
   @param data    The data to write
   @param size    The mask of data
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_raw_write(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                               const void* data,
                                               emc_std_size_t size);

/**
   @relates EMC_USB_CELENO_CLI_FunctionProxy
   @brief send an IOCTL to a function
   @param self The context
   @param function_index The zero based index of the function < EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX
   @param command The command
   @param param1 Generic parameter 1
   @param param2 Generic parameter 2
   @param[out] result1 Optional generic result 1
   @param[out] result2 Optional generic result 2
   @return The success or error code
 */
int EMC_USB_CELENO_CLI_FunctionProxy_function_ioctl(EMC_USB_CELENO_CLI_FunctionProxy* self,
                                                    emc_std_uint32_t function_index,
                                                    emc_std_uint32_t command,
                                                    emc_std_uint32_t param1,
                                                    emc_std_uint32_t param2,
                                                    emc_std_uint32_t* result1,
                                                    emc_std_uint32_t* result2
                                                    );

#if EMC_PRINT
/** @relates EMC_USB_CELENO_CLI_FunctionProxy @brief Prints a FunctionProxy */
void EMC_USB_CELENO_CLI_FunctionProxy_print(const EMC_USB_CELENO_CLI_FunctionProxy* self, FILE* file);
#endif /*EMC_PRINT*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_HOST_FunctionProxy_H */
