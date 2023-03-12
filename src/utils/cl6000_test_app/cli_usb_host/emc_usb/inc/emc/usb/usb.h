/**
 * @file
 * @ingroup emdoc_emc_usb
 */
/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#ifndef EMC_USB_usb_H
#define EMC_USB_usb_H

#include "emc/usb/configure.h"
#include "emc/std/ext/bitoperation.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** @name USB spec revision level (BCD) */
/*@{*/
#define USB_SPEC_BCD_VERSION_20 0x0200
#define USB_SPEC_BCD_VERSION_21 0x0210
#define USB_SPEC_BCD_VERSION_30 0x0300
#define USB_SPEC_BCD_VERSION_31 0x0310
#define USB_SPEC_BCD_VERSION_32 0x0320
/*@}*/

/** @name USB IF Class Codes */
/*@{*/
#define USB_CLASS_IN_INTERFACE 0x00
#define USB_CLASS_APPLICATION_SPECIFIC 0xFE
#define USB_CLASS_VENDOR_SPECIFIC 0xFF
/*@}*/

/** @name USB IF Subclass Codes */
/*@{*/
#define USB_SUBCLASS_IN_INTERFACE 0x00
#define USB_SUBCLASS_VENDOR_SPECIFIC 0xFF
/*@}*/

/** @name USB IF Protocol Codes */
/*@{*/
#define USB_PROTOCOL_IN_INTERFACE 0x00
#define USB_PROTOCOL_VENDOR_SPECIFIC 0xFF
/*@}*/

/** Various parameters */
enum {
  EMC_USB_MAX_FRAME_NUMBER   = 0x7FF, /**< maximum frame number */
  EMC_USB_MAX_DEVICE_ADDRESS = 0x7F,  /**< maximum device address */
};

/** @name USB Endpoint maximum packet size per transfer type and speed */
/*@{*/
#define USB_EP_MPS_CTRL_FULL_SPEED 64
#define USB_EP_MPS_CTRL_HIGH_SPEED 64
#define USB_EP_MPS_CTRL_SUPER_SPEED 0x09 /**< 2**9 = 512 */

#define USB_EP_MPS_BULK_FULL_SPEED 64
#define USB_EP_MPS_BULK_HIGH_SPEED 512
#define USB_EP_MPS_BULK_SUPER_SPEED 1024

#define USB_EP_MPS_INTERRUPT_FULL_SPEED 64
#define USB_EP_MPS_INTERRUPT_HIGH_SPEED 1024
#define USB_EP_MPS_INTERRUPT_SUPER_SPEED 1024

#define USB_EP_MPS_BULK(speed) \
  ((speed == EMC_USB_Speed_FULL) ? USB_EP_MPS_BULK_FULL_SPEED   \
   : (speed == EMC_USB_Speed_HIGH) ? USB_EP_MPS_BULK_HIGH_SPEED    \
   : (speed == EMC_USB_Speed_SUPER) ? USB_EP_MPS_BULK_SUPER_SPEED : 0)

/*@}*/

/** @name Power Attributes @{ */
#define EMC_USB_POWER_ATTRIBUTE_SELF_POWERED (1 << 6)  /**< else: bus powered */
#define EMC_USB_POWER_ATTRIBUTE_REMOTE_WAKEUP (1 << 5) /**< set when supported, unset otherwise */
#define EMC_USB_POWER_ATTRIBUTE_MANDATORY (0 | 0x80)   /**< 0x80 is mandatory - bit 7
                                                          MUST be set as per USB 2.0 specification */

/** power in 2mA units or 0 if SELF_POWERED */
#define EMC_USB_POWER(power, attribute) \
  (((attribute) & EMC_USB_POWER_ATTRIBUTE_SELF_POWERED) ? 0 : (((power) + 1) / 2))

/** power in 8mA units or 0 if SELF_POWERED */
#define EMC_USB_POWER_SS(power, attribute) \
  (((attribute) & EMC_USB_POWER_ATTRIBUTE_SELF_POWERED) ? 0 : (((power) + 7) / 8))

/*@}*/

/** Helper to initialize an uint8 array with an uint16 value (USB byte order) */
#define EMC_USB_FROM_UINT16(v) emc_low_uint8(v), emc_high_uint8(v)

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif
