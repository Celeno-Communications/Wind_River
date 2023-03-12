/**
 * @file
 * @brief   The USB Endpoint Address type
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          Stefan Schulze <stefan.schulze@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * @ingroup emdoc_emc_usb
 *
 * Copyright (C) 2007, 2009, 2011-2013, 2020-2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_USB_EndpointAddress_H
#define EMC_USB_EndpointAddress_H

#include "emc/usb/configure.h"
#include "emc/std/stdint.h"
#include "emc/std/stdbool.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @defgroup emdoc_emc_usb_driver_EndpointAddress  Endpoint Address Support
 * @ingroup emdoc_emc_usb_driver_Generic
 *
 * @brief  The USB Endpoint Address and Id type and helper functions
 *
 * The Endpoint Address @ref EMC_USB_EndpointAddress is following the USB Descriptor semantics with direction in bit[7]
 * and
 * number in bit[3..0].
 * The Endpoint Id @ref EMC_USB_EndpointId is following the semantics of many hardware with direction in bit[0] and
 * number in bit[4..1].
 */

/**
 * @addtogroup emdoc_emc_usb_driver_EndpointAddress
 * @{
 */

/**
 * @brief The USB endpoint address data type implements the USB Descriptor semantics with direction in bit[7] and number
 * in bit[3..0].
 * EMC_USB_EndpointAddress
 * Private Data Member of @ref EMC_USB_EndpointAddress
 */
typedef enum EMC_USB_EndpointAddress {
  EMC_USB_EndpointAddress_EP0_IN   = 0x80,
  EMC_USB_EndpointAddress_EP1_IN   = 0x81,
  EMC_USB_EndpointAddress_EP2_IN   = 0x82,
  EMC_USB_EndpointAddress_EP3_IN   = 0x83,
  EMC_USB_EndpointAddress_EP4_IN   = 0x84,
  EMC_USB_EndpointAddress_EP5_IN   = 0x85,
  EMC_USB_EndpointAddress_EP6_IN   = 0x86,
  EMC_USB_EndpointAddress_EP7_IN   = 0x87,
  EMC_USB_EndpointAddress_EP8_IN   = 0x88,
  EMC_USB_EndpointAddress_EP9_IN   = 0x89,
  EMC_USB_EndpointAddress_EP10_IN  = 0x8A,
  EMC_USB_EndpointAddress_EP11_IN  = 0x8B,
  EMC_USB_EndpointAddress_EP12_IN  = 0x8C,
  EMC_USB_EndpointAddress_EP13_IN  = 0x8D,
  EMC_USB_EndpointAddress_EP14_IN  = 0x8E,
  EMC_USB_EndpointAddress_EP15_IN  = 0x8F,

  EMC_USB_EndpointAddress_EP0_OUT  = 0x00,
  EMC_USB_EndpointAddress_EP1_OUT  = 0x01,
  EMC_USB_EndpointAddress_EP2_OUT  = 0x02,
  EMC_USB_EndpointAddress_EP3_OUT  = 0x03,
  EMC_USB_EndpointAddress_EP4_OUT  = 0x04,
  EMC_USB_EndpointAddress_EP5_OUT  = 0x05,
  EMC_USB_EndpointAddress_EP6_OUT  = 0x06,
  EMC_USB_EndpointAddress_EP7_OUT  = 0x07,
  EMC_USB_EndpointAddress_EP8_OUT  = 0x08,
  EMC_USB_EndpointAddress_EP9_OUT  = 0x09,
  EMC_USB_EndpointAddress_EP10_OUT = 0x0A,
  EMC_USB_EndpointAddress_EP11_OUT = 0x0B,
  EMC_USB_EndpointAddress_EP12_OUT = 0x0C,
  EMC_USB_EndpointAddress_EP13_OUT = 0x0D,
  EMC_USB_EndpointAddress_EP14_OUT = 0x0E,
  EMC_USB_EndpointAddress_EP15_OUT = 0x0F
} EMC_USB_EndpointAddress;

/** The address part mask */
#define EMC_USB_EP_ADDRESS_NUMBER_MASK 0x0F

/** The direction part mask */
#define EMC_USB_EP_ADDRESS_DIRECTION_MASK 0x80

/**
 * @ingroup emdoc_emc_usb_driver_EndpointAddress
 * The direction of an Endpoint, EMC_USB_EndpointAddress_EPAddress or EMC_USB_EndpointId
 */
typedef enum EMC_USB_EndpointDirection_e {
  EMC_USB_EndpointDirection_IN, /**< The IN Direction (Device to Host)*/
  EMC_USB_EndpointDirection_OUT /**< The OUT Direction (Host to Device).*/
} EMC_USB_EndpointDirection;

/** The number part of a endpoint address.
 */
#define EMC_USB_EndpointAddress_number(ep_addr) \
  ((ep_addr) & EMC_USB_EP_ADDRESS_NUMBER_MASK)

/** The direction part of a endpoint address.
 */
#define EMC_USB_EndpointAddress_direction(ep_addr) \
  (((ep_addr) & EMC_USB_EP_ADDRESS_DIRECTION_MASK)                 \
   ? EMC_USB_EndpointDirection_IN : EMC_USB_EndpointDirection_OUT)

/** True if the endpoint address is for an in endpoint.
 */
static inline emc_std_bool EMC_USB_EndpointAddress_is_in(EMC_USB_EndpointAddress ep_addr)
{  return (ep_addr) & EMC_USB_EP_ADDRESS_DIRECTION_MASK;  }

/** True if the endpoint address is for an out endpoint.
 */
static inline emc_std_bool EMC_USB_EndpointAddress_is_out(EMC_USB_EndpointAddress ep_addr)
{ return !((ep_addr) & EMC_USB_EP_ADDRESS_DIRECTION_MASK);  }

/** create a EMC_USB_EndpointAddress from number and direction */
static inline EMC_USB_EndpointAddress EMC_USB_EndpointAddress_create(emc_std_uint8_t num, emc_std_bool in)
{
  return (EMC_USB_EndpointAddress)((num & EMC_USB_EP_ADDRESS_NUMBER_MASK)
                                   | (in ? (emc_std_uint8_t)EMC_USB_EP_ADDRESS_DIRECTION_MASK : (emc_std_uint8_t)0x00u));
}

/** create a out EMC_USB_EndpointAddress from number */
#define EMC_USB_EndpointAddress_out(num) \
  ((EMC_USB_EndpointAddress)((emc_std_uint8_t)(num) & EMC_USB_EP_ADDRESS_NUMBER_MASK))

/** create a in EMC_USB_EndpointAddress from number */
#define EMC_USB_EndpointAddress_in(num) \
  ((EMC_USB_EndpointAddress)(((emc_std_uint8_t)(num) & EMC_USB_EP_ADDRESS_NUMBER_MASK) \
                             | (emc_std_uint8_t)(EMC_USB_EP_ADDRESS_DIRECTION_MASK)))

/** @} */

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif
