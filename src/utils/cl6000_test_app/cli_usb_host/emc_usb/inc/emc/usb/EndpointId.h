/**
 * @file
 * @brief   The USB Endpoint Id type.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2020 emsys Embedded Systems GmbH
 *
 ****************************************************************************/
#ifndef EMC_USB_EndpointId_H
#define EMC_USB_EndpointId_H

#include "emc/usb/EndpointAddress.h"

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
extern "C" {
#endif
// clang-format on extern C

/**
 * @addtogroup emdoc_emc_usb_driver_EndpointAddress
 * @{
 */

/**
 * @brief  The USB Endpoint Id type and helper functions
 * The Endpoint Id implements the semantics of many hardware with direction in bit[0] and number in bit[4..1].
 */
typedef enum EMC_USB_EndpointId_e {
  EMC_USB_EndpointId_EP0_IN   = 0x01,
  EMC_USB_EndpointId_EP1_IN   = 0x03,
  EMC_USB_EndpointId_EP2_IN   = 0x05,
  EMC_USB_EndpointId_EP3_IN   = 0x07,
  EMC_USB_EndpointId_EP4_IN   = 0x09,
  EMC_USB_EndpointId_EP5_IN   = 0x0B,
  EMC_USB_EndpointId_EP6_IN   = 0x0D,
  EMC_USB_EndpointId_EP7_IN   = 0x0F,
  EMC_USB_EndpointId_EP8_IN   = 0x11,
  EMC_USB_EndpointId_EP9_IN   = 0x13,
  EMC_USB_EndpointId_EP10_IN  = 0x15,
  EMC_USB_EndpointId_EP11_IN  = 0x17,
  EMC_USB_EndpointId_EP12_IN  = 0x19,
  EMC_USB_EndpointId_EP13_IN  = 0x1B,
  EMC_USB_EndpointId_EP14_IN  = 0x1D,
  EMC_USB_EndpointId_EP15_IN  = 0x1F,

  EMC_USB_EndpointId_EP0_OUT  = 0x00,
  EMC_USB_EndpointId_EP1_OUT  = 0x02,
  EMC_USB_EndpointId_EP2_OUT  = 0x04,
  EMC_USB_EndpointId_EP3_OUT  = 0x06,
  EMC_USB_EndpointId_EP4_OUT  = 0x08,
  EMC_USB_EndpointId_EP5_OUT  = 0x0A,
  EMC_USB_EndpointId_EP6_OUT  = 0x0C,
  EMC_USB_EndpointId_EP7_OUT  = 0x0E,
  EMC_USB_EndpointId_EP8_OUT  = 0x10,
  EMC_USB_EndpointId_EP9_OUT  = 0x12,
  EMC_USB_EndpointId_EP10_OUT = 0x14,
  EMC_USB_EndpointId_EP11_OUT = 0x16,
  EMC_USB_EndpointId_EP12_OUT = 0x18,
  EMC_USB_EndpointId_EP13_OUT = 0x1A,
  EMC_USB_EndpointId_EP14_OUT = 0x1C,
  EMC_USB_EndpointId_EP15_OUT = 0x1E
} EMC_USB_EndpointId;

/** The address part mask */
#define EMC_USB_EndpointId_NUMBER_MASK 0x1E
/** The direction part mask */
#define EMC_USB_EndpointId_DIRECTION_MASK 0x01

/** The number part of a endpoint address */
#define EMC_USB_EndpointId_number(a) \
  (emc_std_uint8_t)(((a) & EMC_USB_EndpointId_NUMBER_MASK) >> 1)

/** True if the endpoint address is for an IN endpoint */
static inline emc_std_bool EMC_USB_EndpointId_is_in(EMC_USB_EndpointId id)
{
  return id & EMC_USB_EndpointId_DIRECTION_MASK;
}

/** True if the endpoint address is for an OUT endpoint */
static inline emc_std_bool EMC_USB_EndpointId_is_out(EMC_USB_EndpointId id)
{
  return !EMC_USB_EndpointId_is_in(id);
}

/** The direction part of a endpoint address */
static inline EMC_USB_EndpointDirection EMC_USB_EndpointId_direction(EMC_USB_EndpointId id)
{
  return EMC_USB_EndpointId_is_in(id) ? EMC_USB_EndpointDirection_IN : EMC_USB_EndpointDirection_OUT;
}

/** create a EMC_USB_EndpointId from number and direction */
static inline EMC_USB_EndpointId EMC_USB_EndpointId_create(emc_std_uint8_t num, emc_std_bool in)
{
  return (EMC_USB_EndpointId)(((num << 1 & EMC_USB_EndpointId_NUMBER_MASK))
                              | (in ? (emc_std_uint8_t)EMC_USB_EndpointId_DIRECTION_MASK : (emc_std_uint8_t)0x00u));
}

/** create a EMC_USB_EndpointId as conversion from EMC_USB_EndpointAddress */
static inline EMC_USB_EndpointId EMC_USB_EndpointId_convert(EMC_USB_EndpointAddress addr)
{
  return (EMC_USB_EndpointId)(((EMC_USB_EndpointAddress_number(addr) << 1 & EMC_USB_EndpointId_NUMBER_MASK))
                              | (EMC_USB_EndpointAddress_is_in(addr) ? (emc_std_uint8_t)
                                 EMC_USB_EndpointId_DIRECTION_MASK : (
                                   emc_std_uint8_t)0x00u));
}

/** converts a EMC_USB_EndpointId to a EMC_USB_EndpointAddress */
static inline EMC_USB_EndpointAddress EMC_USB_EndpointId_address(EMC_USB_EndpointId id)
{
  return EMC_USB_EndpointAddress_create(EMC_USB_EndpointId_number(id), EMC_USB_EndpointId_is_in(id));
}

/** create a out EMC_USB_EndpointId from number */
#define EMC_USB_EndpointId_out(num) \
  ((EMC_USB_EndpointId)((emc_std_uint8_t)((num) << 1) & EMC_USB_EndpointId_NUMBER_MASK))

/** create a in EMC_USB_EndpointId from number */
#define EMC_USB_EndpointId_in(num) \
  ((EMC_USB_EndpointId)(((emc_std_uint8_t)((num) << 1) & EMC_USB_EndpointId_NUMBER_MASK) \
                        | (emc_std_uint8_t)(EMC_USB_EndpointId_DIRECTION_MASK)))

/** @} */

// clang-format off extern C
#ifdef __cplusplus /*  @srcdist keep  */
}
#endif
// clang-format on extern C

#endif /* EMC_USB_EndpointId_H */
