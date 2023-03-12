/**
 * @file
 * @brief Descriptor information for throughput function
 * @copyright 2021 emsys Embedded Systems GmbH
 */
#ifndef EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_DescriptorValues_H
#define EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_DescriptorValues_H

#include "emc/system/celeno/configure.h"
#include "emc/system/celeno/device/iso_transport/config.h"
#include "emc/usb/descriptor/Descriptor.h"
#include "emc/usb/descriptor/StringDescriptor.h"
#include "emc/usb/TransferType.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

#define CELENO_BT_ISO_IFC_DESCRIPTORS_FS \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_BT_ISO_IFC_NUM, \
  0, /**< alternate setting */ \
  0, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_BT_ISO_IFC_NUM, \
  1, /**< alternate setting */ \
  2, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_BT_ISO_IN, \
  EMC_USB_TransferType_ISOCHRONOUS, \
  EMC_USB_FROM_UINT16(CELENO_BT_ISO_MPS_ALT1), \
  1, /**< polling interval (ms) */ \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_BT_ISO_OUT, \
  EMC_USB_TransferType_ISOCHRONOUS, \
  EMC_USB_FROM_UINT16(CELENO_BT_ISO_MPS_ALT1), \
  1, /**< polling interval (ms) */ \

#define CELENO_BT_ISO_IFC_DESCRIPTORS_TOTAL_LENGTH_FS \
  (EMC_USB_ConfigurationDescriptor_SIZE \
   + (2 * EMC_USB_InterfaceDescriptor_SIZE) \
   + (2 * EMC_USB_EndpointDescriptor_SIZE)) \

#define CELENO_BT_ISO_IFC_DESCRIPTORS_HS \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_BT_ISO_IFC_NUM, \
  0, /**< alternate setting */ \
  0, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_BT_ISO_IFC_NUM, \
  1, /**< alternate setting */ \
  2, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_BT_ISO_IN, \
  EMC_USB_TransferType_ISOCHRONOUS, \
  EMC_USB_FROM_UINT16(CELENO_BT_ISO_MPS_ALT1), \
  CELENO_BT_ISO_POLLING_INT, /**< polling interval (2**(N-1) uf) */ \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_BT_ISO_OUT, \
  EMC_USB_TransferType_ISOCHRONOUS, \
  EMC_USB_FROM_UINT16(CELENO_BT_ISO_MPS_ALT1), \
  CELENO_BT_ISO_POLLING_INT, /**< polling interval (2**(N-1) uf */ \

#define CELENO_BT_ISO_IFC_DESCRIPTORS_TOTAL_LENGTH_HS CELENO_BT_ISO_IFC_DESCRIPTORS_TOTAL_LENGTH_FS

#define CELENO_BT_ISO_IFC_DESCRIPTORS_SS \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_BT_ISO_IFC_NUM, \
  0, /**< alternate setting */ \
  0, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Interface), \
  CELENO_BT_ISO_IFC_NUM, \
  1, /**< alternate setting */ \
  2, /**< number of (non-zero) EPs */ \
  USB_CLASS_VENDOR_SPECIFIC, \
  USB_SUBCLASS_VENDOR_SPECIFIC, \
  USB_PROTOCOL_VENDOR_SPECIFIC, \
  FIRST_OTHER_STRING_INDEX, \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_BT_ISO_IN, \
  EMC_USB_TransferType_ISOCHRONOUS, \
  EMC_USB_FROM_UINT16(CELENO_BT_ISO_MPS_ALT1), \
  CELENO_BT_ISO_POLLING_INT, /**< polling interval (2**(N-1) uf */ \
  \
  EMC_USB_DESCRIPTOR(SuperSpeedEndpointCompanion), \
  0x00,                                        /**< burst */ \
  0x00,                                        /**< attributes */ \
  EMC_USB_FROM_UINT16(CELENO_BT_ISO_MPS_ALT1), /**< bytes per interval */ \
  \
  EMC_USB_DESCRIPTOR(Endpoint), \
  CELENO_BT_ISO_OUT, \
  EMC_USB_TransferType_ISOCHRONOUS, \
  EMC_USB_FROM_UINT16(CELENO_BT_ISO_MPS_ALT1), \
  CELENO_BT_ISO_POLLING_INT, /**< polling interval (2**(N-1) uf */ \
  \
  EMC_USB_DESCRIPTOR(SuperSpeedEndpointCompanion), \
  0x00,                                        /**< burst */ \
  0x00,                                        /**< attributes */ \
  EMC_USB_FROM_UINT16(CELENO_BT_ISO_MPS_ALT1), /**< bytes per interval */ \

#define CELENO_BT_ISO_IFC_DESCRIPTORS_TOTAL_LENGTH_SS \
  (CELENO_BT_ISO_IFC_DESCRIPTORS_TOTAL_LENGTH_HS \
   + 2 * EMC_USB_SuperSpeedEndpointCompanionDescriptor_SIZE)

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_DescriptorValues_H */
