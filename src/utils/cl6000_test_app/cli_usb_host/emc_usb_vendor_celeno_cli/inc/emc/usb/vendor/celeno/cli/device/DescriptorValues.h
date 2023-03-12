/**
 * @file
 * @brief Descriptor information for CLI function
 * @copyright 2021 emsys Embedded Systems GmbH
 */
#ifndef EMC_USB_VENDOR_CELENO_CLI_DEVICE_DescriptorValues_H
#define EMC_USB_VENDOR_CELENO_CLI_DEVICE_DescriptorValues_H

#include "emc/usb/vendor/celeno/cli/configure.h"
#include "emc/usb/descriptor/Descriptor.h"
#include "emc/usb/descriptor/StringDescriptor.h"
#include "emc/usb/TransferType.h"
#include "emc/usb/Speed.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#define EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_HS 500
#define EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_SS (900 - 7) // to ensure that we are not above 900mA because of
                                                                 // multiples of 8mA
#define EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES EMC_USB_POWER_ATTRIBUTE_MANDATORY

#define CELENO_CLI_IFC_DESCRIPTORS_FS \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_CLI_IFC_NUM, \
  0,   /**< alternate setting */ \
  0x2, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_CLI_BULK_IN, \
  EMC_USB_TransferType_BULK, \
  EMC_USB_FROM_UINT16(USB_EP_MPS_BULK_FULL_SPEED), \
  0, /**< polling interval (ms) */ \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_CLI_BULK_OUT, \
  EMC_USB_TransferType_BULK, \
  EMC_USB_FROM_UINT16(USB_EP_MPS_BULK_FULL_SPEED), \
  0, /**< polling interval (ms) */ \
  \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_CLI_IFC_NUM, \
  1,   /**< alternate setting */ \
  0x0, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \

#define CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_FS \
  (EMC_USB_InterfaceDescriptor_SIZE \
   + (2 * EMC_USB_EndpointDescriptor_SIZE) \
   + EMC_USB_InterfaceDescriptor_SIZE)

#define CELENO_CLI_IFC_DESCRIPTORS_HS \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_CLI_IFC_NUM, \
  0,   /**< alternate setting */ \
  0x2, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_CLI_BULK_IN, \
  EMC_USB_TransferType_BULK, \
  EMC_USB_FROM_UINT16(USB_EP_MPS_BULK_HIGH_SPEED), \
  0, /**< polling interval (ms) */ \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_CLI_BULK_OUT, \
  EMC_USB_TransferType_BULK, \
  EMC_USB_FROM_UINT16(USB_EP_MPS_BULK_HIGH_SPEED), \
  0, /**< polling interval (ms) */ \
  \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_CLI_IFC_NUM, \
  1,   /**< alternate setting */ \
  0x0, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \

#define CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_HS CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_FS

#define CELENO_CLI_IFC_DESCRIPTORS_SS \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_CLI_IFC_NUM, \
  0,   /**< alternate setting */ \
  0x2, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_CLI_BULK_IN, \
  EMC_USB_TransferType_BULK, \
  EMC_USB_FROM_UINT16(USB_EP_MPS_BULK_SUPER_SPEED), \
  0, /**< polling interval (ms) */ \
  \
  EMC_USB_DESCRIPTOR(SuperSpeedEndpointCompanion), \
  0x00,       /**< burst */ \
  0x00,       /**< attributes */ \
  0x00, 0x00, /**< bytes per interval */ \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_CLI_BULK_OUT, \
  EMC_USB_TransferType_BULK, \
  EMC_USB_FROM_UINT16(USB_EP_MPS_BULK_SUPER_SPEED), \
  0, /**< polling interval (ms) */ \
  \
  EMC_USB_DESCRIPTOR(SuperSpeedEndpointCompanion), \
  0x00,       /**< burst */ \
  0x00,       /**< attributes */ \
  0x00, 0x00, /**< bytes per interval */ \
  \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_CLI_IFC_NUM, \
  1,   /**< alternate setting */ \
  0x0, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \

#define CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_SS \
  (CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_HS \
   + 2 * EMC_USB_SuperSpeedEndpointCompanionDescriptor_SIZE)

#define CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH(speed) \
  ((speed == EMC_USB_Speed_FULL) ? CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_FS   \
   : (speed == EMC_USB_Speed_HIGH) ? CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_HS    \
   : (speed == EMC_USB_Speed_SUPER) ? CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_SS : 0)

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_VENDOR_CELENO_CLI_DEVICE_DescriptorValues_H */
