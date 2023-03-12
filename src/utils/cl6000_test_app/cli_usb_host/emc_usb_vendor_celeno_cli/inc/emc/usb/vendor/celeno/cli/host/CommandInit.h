/**
 * @file
 * @brief The initialization of Command objects
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_HOST_CommandInit_H
#define EMC_USB_VENDOR_CELENO_CLI_HOST_CommandInit_H

#include "emc/usb/vendor/celeno/cli/Command.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the GET_VERSION Command
 * @param self The Command object to initialize
 */
void EMC_USB_CELENO_CLI_Command_init_get_version(EMC_USB_CELENO_CLI_Command* self);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the SINGLE_READ Command
 * @param self The Command object to initialize
 * @param address The memory address
 */
void EMC_USB_CELENO_CLI_Command_init_read(EMC_USB_CELENO_CLI_Command* self,
                                          emc_std_uint32_t address);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the SINGLE_WRITE Command
 * @param self The Command object to initialize
 * @param address The memory address
 * @param data The data
 * @param mask The mask for data
 */
void EMC_USB_CELENO_CLI_Command_init_write(EMC_USB_CELENO_CLI_Command* self,
                                           emc_std_uint32_t address,
                                           emc_std_uint32_t data,
                                           emc_std_uint32_t mask
                                           );

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the SINGLE_WRITE_FAST Command without Response
 * @param self The Command object to initialize
 * @param address The memory address
 * @param data The data
 * @param mask The mask for data
 */
void EMC_USB_CELENO_CLI_Command_init_write_fast(EMC_USB_CELENO_CLI_Command* self,
                                                emc_std_uint32_t address,
                                                emc_std_uint32_t data,
                                                emc_std_uint32_t mask
                                                );

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the KEEP_ALIVE Command
 * @param self The Command object to initialize
 */
void EMC_USB_CELENO_CLI_Command_init_keep_alive(EMC_USB_CELENO_CLI_Command* self);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the USB_DISCONNECT Command
 * @param self The Command object to initialize
 * @param usb_disconnect_delay_ms The disconnect delay
 * @param disconnect_time The disconnect time in ms
 */
void EMC_USB_CELENO_CLI_Command_init_usb_disconnect(EMC_USB_CELENO_CLI_Command* self,
                                                    emc_std_uint32_t usb_disconnect_delay_ms);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the UMAC_EXECUTE Command
 * @param self The Command object to initialize
 * @param jump_address The jump start address
 */
void EMC_USB_CELENO_CLI_Command_init_umac_execute(EMC_USB_CELENO_CLI_Command* self,
                                                  emc_std_uint32_t jump_address);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the USB_DISCONNECT Command
 * @param self The Command object to initialize
   @param usb_disconnect_delay_ms The time to wait until usb will be disconnected ms
   @param restart_delay_ms The delay between usb disconnect and jump to address in ms
   @param jump_address The address of the code to execute
 */
void EMC_USB_CELENO_CLI_Command_init_umac_restart(EMC_USB_CELENO_CLI_Command* self,
                                                  emc_std_uint32_t usb_disconnect_delay_ms,
                                                  emc_std_uint32_t restart_delay_ms,
                                                  emc_std_uint32_t jump_address);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the LOGGER_LEVEL_GET Command
 * @param self The Command object to initialize
 * @param index The zero-based index of the logger
 */
void EMC_USB_CELENO_CLI_Command_init_logger_level_get(EMC_USB_CELENO_CLI_Command* self,
                                                      emc_std_uint32_t index);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the LOGGER_LEVEL_SET Command
 * @param self The Command object to initialize
 * @param index The zero-based index of the logger
 * @param level The level to be set for the logger
 */
void EMC_USB_CELENO_CLI_Command_init_logger_level_set(EMC_USB_CELENO_CLI_Command* self,
                                                      emc_std_uint32_t index,
                                                      emc_std_uint32_t level);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the LOGGER_INFO_GET Command
 * @param self The Command object to initialize
 * @param index The zero-based index of the logger
 */
void EMC_USB_CELENO_CLI_Command_init_logger_info_get(EMC_USB_CELENO_CLI_Command* self,
                                                     emc_std_uint32_t index);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the BURST_READ Command
 * @param self The Command object to initialize
 * @param address The memory address
 * @param length The length of payload data
 * @param zero_copy True to use zero copy operation
 */
void EMC_USB_CELENO_CLI_Command_init_burst_read(EMC_USB_CELENO_CLI_Command* self,
                                                emc_std_uint32_t address,
                                                emc_std_uint32_t length,
                                                emc_std_bool zero_copy);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the BURST_WRITE Command
 * @param self The Command object to initialize
 * @param address The memory address
 * @param length The length of payload data
 * @param zero_copy True to use zero copy operation
 */
void EMC_USB_CELENO_CLI_Command_init_burst_write(EMC_USB_CELENO_CLI_Command* self,
                                                 emc_std_uint32_t address,
                                                 emc_std_uint32_t length,
                                                 emc_std_bool zero_copy);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the BURST_WRITE_FAST Command without Response
 * @param self The Command object to initialize
 * @param address The memory address
 * @param length The length of payload data
 * @param zero_copy True to use zero copy operation
 */
void EMC_USB_CELENO_CLI_Command_init_burst_write_fast(EMC_USB_CELENO_CLI_Command* self,
                                                      emc_std_uint32_t address,
                                                      emc_std_uint32_t length,
                                                      emc_std_bool zero_copy);

/** @relates EMC_USB_CELENO_CLI_Command
 * @brief initialize the EMC_USB_CELENO_CLI_CommandId_FUNCTION_IOCTL Command
 * @param self The Command object to initialize
 * @param function_index The zero based index of the function < EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX
 * @param command the command
 * @param param1 protocol specific parameter 1
 * @param param2 protocol specific parameter 2
 */
void EMC_USB_CELENO_CLI_Command_init_function_ioctl(EMC_USB_CELENO_CLI_Command* self,
                                                    emc_std_uint32_t function_index,
                                                    emc_std_uint32_t command,
                                                    emc_std_uint32_t param1,
                                                    emc_std_uint32_t param2);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_HOST_CommandInit_H */
