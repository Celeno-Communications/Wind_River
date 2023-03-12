/**
 * @file
 * @brief   Request specific constants and data types.
 *
 * Header for all request specific structures and constants
 * defined by USB-Spec. 1.1/2.0
 *
 * @author  Maik Otto <maik.otto@emsys.de> +49-3677-68977-0\n
 *          Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0\n
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2011-2013 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_USB_REQUEST_Request_H
#define EMC_USB_REQUEST_Request_H

#include "emc/usb/configure.h"

#include "emc/usb/request/Request_fwd.h"

#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The recipient of a request */
typedef enum EMC_USB_Recipient {
  EMC_USB_REQ_RECIPIENT_DEVICE    = 0,
  EMC_USB_REQ_RECIPIENT_INTERFACE = 1,
  EMC_USB_REQ_RECIPIENT_ENDPOINT  = 2,
  EMC_USB_REQ_RECIPIENT_OTHER     = 3
} EMC_USB_Recipient;

/** The type of a request */
typedef enum EMC_USB_RequestType {
  EMC_USB_REQ_TYPE_STANDARD = 0x00,
  EMC_USB_REQ_TYPE_CLASS    = 0x20,
  EMC_USB_REQ_TYPE_VENDOR   = 0x40
} EMC_USB_RequestType;

/** The direction of a request */
typedef enum EMC_USB_Direction {
  EMC_USB_REQ_DIR_HOST_TO_DEVICE = 0x00,
  EMC_USB_REQ_DIR_DEVICE_TO_HOST = 0x80
} EMC_USB_Direction;

enum {
  EMC_USB_REQ_RECIPIENT_MASK = 0x1F,
  EMC_USB_REQ_TYPE_MASK      = 0x60,
  EMC_USB_REQ_DIR_MASK       = 0x80
};

/** @name Status bits */
/** @{ */
#define EMC_USB_STATUS_SELF_PWR_BIT 0x01
#define EMC_USB_STATUS_REM_WAKEUP_BIT 0x02
#define EMC_USB_EP_STATUS_STALLED 0x01
#define EMC_USB_STATUS_U1_ENABLE_BIT 0x04
#define EMC_USB_STATUS_U2_ENABLE_BIT 0x08
#define EMC_USB_STATUS_LTM_ENABLE_BIT 0x10

#define EMC_USB_SUSPEND_OPTION_LOW_POWER_SUSPEND_STATE_BIT 0x01
#define EMC_USB_SUSPEND_OPTION_REM_WAKEUP_BIT 0x02

#define EMC_USB_EP_STATUS_NOT_STALLED 0x00
#define EMC_USB_EP_STATUS_STALLED 0x01
/** @} */

/** Configuration number for "unconfigured" state */
#define EMC_USB_UNCONFIGURED 0x00

/** @name Chap 9 Support (Standard)
 * Standard EMC_USB_Request Values for bRequest
 */

/*@{*/
#define EMC_USB_STD_REQ_GET_STATUS 0x00
#define EMC_USB_STD_REQ_CLR_FEATURE 0x01
#define EMC_USB_STD_REQ_SET_FEATURE 0x03
#define EMC_USB_STD_REQ_SET_ADDRESS 0x05
#define EMC_USB_STD_REQ_GET_DESCRIPTOR 0x06
#define EMC_USB_STD_REQ_SET_DESCRIPTOR 0x07
#define EMC_USB_STD_REQ_GET_CONFIGURATION 0x08
#define EMC_USB_STD_REQ_SET_CONFIGURATION 0x09
#define EMC_USB_STD_REQ_GET_INTERFACE 0x0A
#define EMC_USB_STD_REQ_SET_INTERFACE 0x0B
#define EMC_USB_STD_REQ_SYNCH_FRAME 0x0C
#define EMC_USB_STD_REQ_SET_SEL 0x30
#define EMC_USB_STD_REQ_SET_ISOCH_DELAY 0x31
/*@}*/

/**
 * emsys vendor EMC_USB_Request Value for getting firmware/hardware information
 */

typedef enum EMC_USB_Vendor_Get_Info {
  EMC_USB_VENDOR_REQ_GET_FW_PACKAGE_VERSION      = 0x00, /**< The firmware version  */
  EMC_USB_VENDOR_REQ_GET_FW_PACKAGE_NAME         = 0x01, /**< The firmware package name */
  EMC_USB_VENDOR_REQ_GET_FW_PACKAGE_RELEASE_DATE = 0x02, /**< The firmware package release date */
  EMC_USB_VENDOR_REQ_GET_FW_INFO_FIRST_RESERVED  = 0x03, /**< First reserved value */
  EMC_USB_VENDOR_REQ_GET_FW_INFO_LAST_RESERVED   = 0x0F  /**< Last reserved value */
} EMC_USB_Vendor_Get_FirmwareInfo;

/**
 * Vendor USB_Request index definitions for wIndex
 */

typedef enum EMC_USB_Vendor_TargetIndex {
  EMC_USB_VENDOR_REQ_TARGET_INDEX_EMC_USB_DEVICE = 0x0000, /**< The EMC USB Device library */
  EMC_USB_VENDOR_REQ_TARGET_INDEX_EMC_USB_OTG    = 0x0001, /**< The EMC USB OTG library */
  EMC_USB_VENDOR_REQ_TARGET_INDEX_EMC_USB_HOST   = 0x0002, /**< The EMC USB Host library */
  EMC_USB_VENDOR_REQ_TARGET_INDEX_EMC_BASE       = 0x0003, /**< The EMC base library */
  EMC_USB_VENDOR_REQ_TARGET_INDEX_EMC_USB_HAL    = 0x0004, /**< The EMC USB HAL library */
  EMC_USB_VENDOR_REQ_TARGET_INDEX_EMC_OS         = 0x0005, /**< The EMC OS library */
  EMC_USB_VENDOR_REQ_TARGET_INDEX_EMC_PORT       = 0x0006, /**< The EMC Port library */
  EMC_USB_VENDOR_REQ_TARGET_INDEX_USB_HW         = 0x0007, /**< The USB hardware */
  EMC_USB_VENDOR_REQ_TARGET_INDEX_1394_HW        = 0x0008, /**< The 1394 hardware */
  EMC_USB_VENDOR_REQ_GET_FIRST_RESERVED          = 0x0009, /**< First reserved value */
  EMC_USB_VENDOR_REQ_GET_LAST_RESERVED           = 0x000F  /**< Last reserved value */
} EMC_USB_Vendor_Get_Version;

/* @name Feature Selectors */

/*@{*/
#define EMC_USB_STD_FEATURE_DEV_REMOTE_WAKEUP 0x01 /**< Remote wakeup support */
#define EMC_USB_STD_FEATURE_ENDPOINT_STALL 0x00    /**< Stall the endpoint */
#define EMC_USB_STD_FEATURE_INTERFACE_FUNCTION_SUSPEND 0x00
#define EMC_USB_STD_FEATURE_TEST_MODE 0x02 /**< Test mode */
#define EMC_USB_STD_FEATURE_DEV_U1_ENABLE 0x30
#define EMC_USB_STD_FEATURE_DEV_U2_ENABLE 0x31
#define EMC_USB_STD_FEATURE_DEV_LTM_ENABLE 0x32
/*@}*/

/** @name EMC USB Feature Selectors for Test Mode
 * wValue feature selectors for test modes according to
 * USB Specification, Chapter 9.4.9.
 */

/*@{*/
typedef enum EMC_USB_Feature_Selector_Test_Mode {
  EMC_USB_STD_FEATURE_TEST_MODE_RESERVED                = 0x00,
  EMC_USB_STD_FEATURE_TEST_MODE_TEST_J                  = 0x01,
  EMC_USB_STD_FEATURE_TEST_MODE_TEST_K                  = 0x02,
  EMC_USB_STD_FEATURE_TEST_MODE_TEST_SE0_NAK            = 0x03,
  EMC_USB_STD_FEATURE_TEST_MODE_TEST_PACKET             = 0x04,
  EMC_USB_STD_FEATURE_TEST_MODE_TEST_FORCE_ENABLE       = 0x05,
  EMC_USB_STD_FEATURE_TEST_MODE_FIRST_STD_TEST_SELECTOR = 0x06,
  EMC_USB_STD_FEATURE_TEST_MODE_LAST_STD_TEST_SELECTOR  = 0x3F,
  EMC_USB_STD_FEATURE_TEST_MODE_FIRST_RESERVED          = 0x40,
  EMC_USB_STD_FEATURE_TEST_MODE_LAST_RESERVED           = 0xBF,
  EMC_USB_STD_FEATURE_TEST_MODE_FIRST_VENDOR            = 0xC0,
  EMC_USB_STD_FEATURE_TEST_MODE_LAST_VENDOR             = 0xCF
} EMC_USB_Feature_Selector_Test_Mode;
/*@}*/

/** Structure of a USB_request */
struct EMC_USB_Request {
  unsigned char  bmReqTyp; /**< Request Type bitmap */
  unsigned char  bRequest; /**< Request code itself */
  unsigned char  bValueLo; /**< Request-value low-byte */
  unsigned char  bValueHi; /**< Request-value high-byte */
  unsigned char  bIndexLo; /**< Request-index low-byte */
  unsigned char  bIndexHi; /**< Request-index high-byte */
  unsigned short wLength;  /**< Length of data-stage */
};

#if EMC_PRINT
#  include "emc/std/stdio_fwd.h"
/** Prints a USB request */
void EMC_USB_Request_print(const EMC_USB_Request* self, FILE* file);

/** Returns the name of the request recipient */
const char* EMC_USB_Request_recipient_name(const EMC_USB_Request* self);
/** Returns the type of the request */
const char* EMC_USB_Request_type_name(const EMC_USB_Request* self);
/** Returns the direction of the request */
const char* EMC_USB_Request_direction_name(const EMC_USB_Request* self);
#endif

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

/** @name USB request getter helper macros */
/** @{ */
#define EMC_USB_Request_value(r) \
  (emc_std_uint16_t)(((r)->bValueHi << 8) | (r)->bValueLo)

#define EMC_USB_Request_index(r) \
  (emc_std_uint16_t)(((r)->bIndexHi << 8) | (r)->bIndexLo)

#define EMC_USB_Request_length(r) \
  ((r)->wLength)

#define EMC_USB_Request_alt_setting(req) \
  ((req)->bValueLo)

#define EMC_USB_Request_feature_selector(req) \
  ((req)->bValueLo)

#define EMC_USB_Request_address(req) \
  ((req)->bValueLo)

#define EMC_USB_Request_config(req) \
  ((req)->bValueLo)

#define EMC_USB_Request_string(req) \
  ((req)->bValueLo)

#define EMC_USB_Request_interface(req) \
  ((req)->bIndexLo)

#define EMC_USB_Request_endpoint(req) \
  ((req)->bIndexLo)

#define EMC_USB_Request_descriptor_type(req) \
  ((req)->bValueHi)

#define EMC_USB_Request_language(r) \
  EMC_USB_Request_index(r)

#define EMC_USB_Request_recipient(self)                                     \
  ((EMC_USB_Recipient)((self)->bmReqTyp & EMC_USB_REQ_RECIPIENT_MASK))

#define EMC_USB_Request_type(self)                                      \
  ((EMC_USB_RequestType)((self)->bmReqTyp & EMC_USB_REQ_TYPE_MASK))

#define EMC_USB_Request_direction(self)                             \
  ((EMC_USB_Direction)((self)->bmReqTyp & EMC_USB_REQ_DIR_MASK))
/** @} */

#endif
