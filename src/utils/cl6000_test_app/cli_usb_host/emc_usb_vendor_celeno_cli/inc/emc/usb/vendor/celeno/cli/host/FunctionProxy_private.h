/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_VENDOR_CELENO_CLI_HOST_FunctionProxy_private_H
#define EMC_USB_VENDOR_CELENO_CLI_HOST_FunctionProxy_private_H

#include "emc/usb/vendor/celeno/cli/host/FunctionProxy_fwd.h"
#include "emc/usb/host/hal/Interface_fwd.h"
#include "emc/usb/host/hal/Endpoint_fwd.h"
#include "emc/log/log.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#define EMC_USB_VENDOR_CELENO_CLI_MAX_CMD_TRANSFER_WORDS \
  (EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH / sizeof(emc_std_uint32_t))
#define EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_WORDS \
  (EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_LENGTH / sizeof(emc_std_uint32_t))
#define EMC_USB_VENDOR_CELENO_CLI_MAX_CMD_TRANSFER_ITEMS \
  (EMC_USB_VENDOR_CELENO_CLI_MAX_COMMAND_TRANSFER_LENGTH / sizeof(EMC_USB_CELENO_CLI_Command))

/**
   @brief The Host context of the vendor specific protocol
   @ingroup emdoc_emc_usb_vendor_celeno_cli_Host
 */
struct EMC_USB_CELENO_CLI_FunctionProxy {
  emc_logger_t*               logger;                /**< the logger */
  EMC_USB_HOST_HAL_Interface* hal_interface;         /**< the hal interface context */
  emc_std_uint32_t            sequence_id;           /**< last sequence id */
  EMC_USB_HOST_HAL_Endpoint*  tx_ep;                 /**< the tx Endpoint (OUT) */
  EMC_USB_HOST_HAL_Endpoint*  rx_ep;                 /**< the rx Endpoint (IN) */
  emc_std_uint16_t            rx_ep_max_packet_size; /**< max packet size for rx */
  emc_std_uint16_t            tx_ep_max_packet_size; /**< max packet size for tx */
  emc_std_int32_t             tx_queue_depth;        /**< depth of command queue, -1 if queueing is inactive */
  emc_std_uint32_t*           tx_first_pending;      /**< first command in pending queue that awaits a response */
  emc_std_uint32_t*           tx_buffer_wptr;        /**< next free command chunk in TX buffer */
  emc_std_uint32_t            rx_responses;          /**< number of responses in RX buffer */
  emc_std_uint32_t*           rx_buffer_rptr;        /**< next filled response chunk in RX buffer */
  emc_std_uint32_t            transfer_timeout_ms;   /**< Transfer timeout in ms */

  /** rx buffer */
  emc_std_uint32_t rx_buffer[EMC_USB_VENDOR_CELENO_CLI_MAX_CMD_TRANSFER_WORDS];
  /** tx buffer */
  emc_std_uint32_t tx_buffer[EMC_USB_VENDOR_CELENO_CLI_MAX_CMD_TRANSFER_WORDS];
  /** data buffer */
  emc_std_uint32_t data_buffer[EMC_USB_VENDOR_CELENO_CLI_MAX_DATA_TRANSFER_WORDS];
  /** read value application pointers to return single_read values in case of queueing */
  emc_std_uint32_t* rx_read_values[EMC_USB_VENDOR_CELENO_CLI_MAX_CMD_TRANSFER_ITEMS];

};

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_HOST_FunctionProxy_private_H */
