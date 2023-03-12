/**
 * @file
 * @brief   The Attributes of an USB Endpoint.
 *
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2007, 2009, 2010, 2012, 2020 emsys Embedded Systems GmbH
 *
 ****************************************************************************/
#ifndef EMC_USB_EndpointAttributes_H
#define EMC_USB_EndpointAttributes_H

#include "emc/usb/configure.h"
#include "emc/usb/EndpointAddress.h"
#include "emc/usb/TransferType.h"

#include "emc/log/log.h"
#include "emc/std/stdint.h"
#include "emc/std/stdlib.h"
#include "emc/std/stdbool.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/** Typedef of EMC_USB_EndpointAttributes_s for short hand notation */
typedef struct EMC_USB_EndpointAttributes_s EMC_USB_EndpointAttributes;

/** Endpoint attributes */
struct EMC_USB_EndpointAttributes_s {
  emc_logger_t*           logger;                  /**< The (optional) logger for this EP instance */
  EMC_USB_EndpointAddress ep_address;              /**< Endpoint address */
  emc_std_size_t          fifo_size;               /**< FIFO size to be used for this EP */
  emc_std_size_t          max_chain_length;        /**< Maximum SG-DMA chain length */
  emc_std_uint16_t        max_packet_size;         /**< Maximum packet size */
  emc_std_uint8_t         mult;                    /**< MULT value for high-bandwidth transfers */
  emc_std_uint8_t         max_burst_count;         /**< Maximum length of bursts for super speed transfers */
  EMC_USB_TransferType    transfer_type;           /**< Transfer type */
  emc_std_uint8_t         polling_interval;        /**< Endpoint polling interval */
  emc_std_bool            external_buffer_control; /**< EP uses External Buffer Control mode, i.e.
                                                        additional flow control using dedicated HW
                                                        signal interface */
  emc_std_bool polling_enabled;                    /**< EP uses polling mode */
};

/**
 * Initialize EndpointAttributes for BULK transfer_type with minimal value set
 * @param self The instance
 * @param ep_address The endpoint address
 * @param max_packet_size The maximum packet size in bytes
 */
void EMC_USB_EndpointAttributes_init_bulk(EMC_USB_EndpointAttributes* self,
                                          EMC_USB_EndpointAddress ep_address,
                                          emc_std_uint16_t max_packet_size);

/**
 * Initialize EndpointAttributes for ISOCHRONOUS transfer_type with minimal value set
 * @param self The instance
 * @param ep_address The endpoint address
 * @param max_packet_size The maximum packet size in bytes
 * @param polling_interval The polling interval N in units of 2^(N-1)
 */
void EMC_USB_EndpointAttributes_init_isochronous(EMC_USB_EndpointAttributes* self,
                                                 EMC_USB_EndpointAddress ep_address,
                                                 emc_std_uint16_t max_packet_size,
                                                 emc_std_uint8_t polling_interval);

/**
 * Initialize EndpointAttributes for INTERRUPT transfer_type with minimal value set
 * @param self The instance
 * @param ep_address The endpoint address
 * @param max_packet_size The maximum packet size in bytes
 * @param polling_interval The polling interval N in units of 2^(N-1)
 */
void EMC_USB_EndpointAttributes_init_interrupt(EMC_USB_EndpointAttributes* self,
                                               EMC_USB_EndpointAddress ep_address,
                                               emc_std_uint16_t max_packet_size,
                                               emc_std_uint8_t polling_interval);

/**
 * Initialize EndpointAttributes for CONTROL transfer_type with minimal value set
 * @param self The instance
 * @param ep_address The endpoint address
 * @param max_packet_size The maximum packet size in bytes
 */
void EMC_USB_EndpointAttributes_init_control(EMC_USB_EndpointAttributes* self,
                                             EMC_USB_EndpointAddress ep_address,
                                             emc_std_uint16_t max_packet_size);

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_USB_EndpointAttributes_H */
