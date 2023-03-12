/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_Command_H
#define EMC_USB_VENDOR_CELENO_CLI_Command_H

#include "emc/usb/vendor/celeno/cli/CommandId.h"

#include "emc/std/stdint.h"

#if EMC_PRINT
#  include "emc/std/stdio_fwd.h"
#endif

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** @defgroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal Implementation Details of Commands
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands
 */

/** The Command / Response size
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands
    @showinitializer
 */
#define EMC_USB_CELENO_CLI_Command_SIZE 20

/** The Single Read Command Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_CommandReadParam {
  emc_std_uint32_t address; /**< the address*/
} EMC_USB_CELENO_CLI_CommandReadParam;

/** The Single Write Command Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_CommandWriteParam {
  emc_std_uint32_t address; /**< the address*/
  emc_std_uint32_t data;    /**< the data*/
  emc_std_uint32_t mask;    /**< the mask*/
} EMC_USB_CELENO_CLI_CommandWriteParam;

/** The USB Disconnect Command Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_CommandDisconnectParam {
  emc_std_uint32_t usb_disconnect_delay_ms; /**< the disconnect delay*/
} EMC_USB_CELENO_CLI_CommandDisconnectParam;

/** The UMAC Execute Command Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_CommandExecParam {
  emc_std_uint32_t address; /**< the address*/
} EMC_USB_CELENO_CLI_CommandExecParam;

/** The UMAC Restart Command Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_CommandUmacRestartParam {
  emc_std_uint32_t usb_disconnect_delay_ms; /**< the disconnect delay*/
  emc_std_uint32_t restart_delay_ms;        /**< the restart delay*/
  emc_std_uint32_t jump_address;            /**< the address to jump to*/
} EMC_USB_CELENO_CLI_CommandUmacRestartParam;

/** The Logger Info/Level Get Command Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_LoggerGetParam {
  emc_std_uint32_t index; /**< the zero-based index of the logger*/
} EMC_USB_CELENO_CLI_LoggerGetParam;

/** The Logger Level Set Command Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_LoggerLevelSetParam {
  emc_std_uint32_t index; /**< the zero-based index of the logger*/
  emc_std_uint32_t level; /**< the logging level (verbosity) to set*/
} EMC_USB_CELENO_CLI_LoggerLevelSetParam;

/** The Burst Read Command Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_CommandBurstReadParam {
  emc_std_uint32_t address; /**< the address*/
  emc_std_uint32_t length;  /**< the length*/
} EMC_USB_CELENO_CLI_CommandBurstReadParam;

/** The Burst Write Parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands_Internal
 */
typedef struct EMC_USB_CELENO_CLI_CommandBurstWriteParam {
  emc_std_uint32_t address; /**< the address*/
  emc_std_uint32_t length;  /**< the length*/
} EMC_USB_CELENO_CLI_CommandBurstWriteParam;

typedef struct EMC_USB_CELENO_CLI_FunctionIoctlParam {
  emc_std_uint32_t command; /**< the command*/
  emc_std_uint32_t param1;  /**< parameter 1*/
  emc_std_uint32_t param2;  /**< parameter 2*/
} EMC_USB_CELENO_CLI_FunctionIoctlParam;

/** The Command, consists of a unique header and command-specific parameters
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Commands
 */
typedef struct EMC_USB_CELENO_CLI_Command {
  EMC_USB_CELENO_CLI_CommandId id;          /**< identifier */
  emc_std_uint32_t             sequence_id; /**< sequence id */
  union {
    EMC_USB_CELENO_CLI_CommandReadParam        read;                 /**< read parameter */
    EMC_USB_CELENO_CLI_CommandWriteParam       write;                /**< write parameter */
    EMC_USB_CELENO_CLI_CommandDisconnectParam  disconnect;           /**< USB Disconnect parameter */
    EMC_USB_CELENO_CLI_CommandExecParam        execute;              /**< UMAC Execute parameter */
    EMC_USB_CELENO_CLI_CommandUmacRestartParam restart;              /**< UMAC Restart parameter */
    EMC_USB_CELENO_CLI_LoggerGetParam          logger_get;           /**< Logger Get Info/Level parameter */
    EMC_USB_CELENO_CLI_LoggerLevelSetParam     logger_level_set;     /**< Logger Set Level parameter */
    EMC_USB_CELENO_CLI_CommandBurstReadParam   burst_read;           /**< burst read parameter */
    EMC_USB_CELENO_CLI_CommandBurstWriteParam  burst_write;          /**< burst write parameter */
    EMC_USB_CELENO_CLI_FunctionIoctlParam      function_ioctl_param; /**< function IOCTL parameter */
    emc_std_uint32_t                           reserved[3];          /**< generic parameter */
  } param;                                                           /**< the command specific parameter */

} EMC_USB_CELENO_CLI_Command;

/**
   @relates EMC_USB_CELENO_CLI_Command
   @brief put a Command on a bytestream
 */
void EMC_USB_CELENO_CLI_Command_put(const EMC_USB_CELENO_CLI_Command* self, void** stream);

/**
   @relates EMC_USB_CELENO_CLI_Command
   @brief get a Command from a bytestream
 */
void EMC_USB_CELENO_CLI_Command_get(EMC_USB_CELENO_CLI_Command* self, void** stream);

#if EMC_PRINT
/** @relates EMC_USB_CELENO_CLI_Command @brief Prints a Command */
void EMC_USB_CELENO_CLI_Command_print(const EMC_USB_CELENO_CLI_Command* self, FILE* file);
#endif /*EMC_PRINT*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_Command_H */
