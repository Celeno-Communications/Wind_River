/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_DEVICE_Function_private_H
#define EMC_USB_VENDOR_CELENO_CLI_DEVICE_Function_private_H

#include "emc/usb/vendor/celeno/cli/device/Function.h"
#include "emc/usb/vendor/celeno/cli/Command.h"
#include "emc/usb/vendor/celeno/cli/Response.h"
#include "emc/usb/vendor/celeno/cli/Version.h"

#include "emc/usb/EndpointAddress.h"
#include "emc/usb/device/Interface_fwd.h"
#include "emc/usb/device/hal/EPHandle.h"

#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The state codes
    @ingroup emdoc_emc_usb_vendor_celeno_cli_Device
 */
typedef enum EMC_USB_CELENO_CLI_State {
  EMC_USB_CELENO_CLI_State_RX_COMMAND,    /**< waiting on Command received */
  EMC_USB_CELENO_CLI_State_RX_DATA,       /**< waiting on Data to receive */
  EMC_USB_CELENO_CLI_State_RX_DUMMY_DATA, /**< waiting on data that are discarded */
  EMC_USB_CELENO_CLI_State_TX_RESPONSE,   /**< transmit Response */
  EMC_USB_CELENO_CLI_State_TX_DATA        /**< Transmit further Data */
} EMC_USB_CELENO_CLI_State;

#if EMC_PRINT
/** Returns the state as string */
const char* EMC_USB_CELENO_CLI_State_as_string(EMC_USB_CELENO_CLI_State state);
#endif /*EMC_PRINT*/

/**
 * Item that keeps the information for an Ioctl function.
 */
typedef struct EMC_USB_CELENO_CLI_IoctlFunctionItem {
  EMC_USB_CELENO_CLI_FunctionIoctl* function; /**< function pointer */
  void*                             context;  /**< context */
} EMC_USB_CELENO_CLI_IoctlFunctionItem;

/**
 * Item that keeps the information for hook function function.
 */
typedef struct EMC_USB_CELENO_CLI_CommandCallbackItem {
  EMC_USB_CELENO_CLI_CommandCallback* function; /**< function pointer */
  void*                               context;  /**< context */
} EMC_USB_CELENO_CLI_CommandCallbackItem;

/**
   @brief The Device context of the vendor specific protocol
   @ingroup emdoc_emc_usb_vendor_celeno_cli_Device

   The Function is the context on the USB Device side, which:
   - receives Commands (Single Commands or Command Sequences)
   - decode and handles the Command
   - generates the Responses if expected
 */
struct EMC_USB_CELENO_CLI_Function {
  EMC_USB_CELENO_CLI_FunctionConfig config;                /**< the function configuration parameters */
  EMC_USB_Interface*                interface;             /**< the underlying USB interface */
  emc_std_uint32_t                  sequence_id;           /**< last sequence id */
  EMC_USB_CELENO_CLI_State          state;                 /**< The current state */
  unsigned int                      configured;            /**< The interface is configured */
  EMC_USB_EndpointAddress           tx_ep_addr;            /**< USB Endpoint address for rx */
  EMC_USB_EndpointAddress           rx_ep_addr;            /**< USB Endpoint address for tx */
  EMC_USB_DEVICE_HAL_EPHandle_t     tx_ep_handle;          /**< USB Endpoint handle for rx */
  EMC_USB_DEVICE_HAL_EPHandle_t     rx_ep_handle;          /**< USB Endpoint handle for tx */
  emc_std_uint16_t                  rx_ep_max_packet_size; /**< max packet size for rx */
  emc_std_uint16_t                  tx_ep_max_packet_size; /**< max packet size for tx */
  emc_std_bool                      bulk_data_zero_copy;   /**< true to use DMA */
  emc_std_bool                      tx_data_in_tx_buffer;  /**< true if tx_buffer holds the data already */

  emc_logger_t* logger;    /**< The function logger instance */
  emc_logger_t* logger_rx; /**< The rx-logger instance */
  emc_logger_t* logger_tx; /**< The tx-logger instance */

  EMC_USB_CELENO_CLI_Version  version;      /**< The protocol and firmware version */
  EMC_USB_CELENO_CLI_Command  command;      /**< the current processed command */
  EMC_USB_CELENO_CLI_Response response;     /**< the current prepared response */
  emc_std_uint32_t            data_address; /**< the start address of the data */
  emc_std_uint32_t            data_length;  /**< the length of the data phase in bytes */

  emc_std_uint32_t* rx_buffer;      /**< The rx buffer for Commands */
  emc_std_uint32_t  rx_buffer_size; /**< The size of the rx buffer */
  emc_std_uint32_t* tx_buffer;      /**< The tx buffer for Responses */
  emc_std_uint32_t  tx_buffer_size; /**< The size of the tx buffer */
  emc_std_uint32_t* tx_buffer_wptr; /**< next free response chunk in TX buffer */

  EMC_USB_CELENO_CLI_IoctlFunctionItem   ioctl_functions[EMC_USB_CELENO_CLI_FUNCTION_IOCTL_MAX]; /**< IOCTL functions */
  EMC_USB_CELENO_CLI_CommandCallbackItem command_hook_function;
};

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_DEVICE_Function_H */
