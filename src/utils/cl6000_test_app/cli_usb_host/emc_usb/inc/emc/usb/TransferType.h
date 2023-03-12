/**
 * @file
 * @ingroup emdoc_emc_usb
 * Copyright (C) 2011-2013,2020 emsys Embedded Systems GmbH
 */

#ifndef EMC_USB_TransferType_H
#define EMC_USB_TransferType_H

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The USB specific transfer types */
typedef enum  EMC_USB_TransferType {
  EMC_USB_TransferType_CONTROL     = 0x00, /**< Control Transfer.*/
  EMC_USB_TransferType_ISOCHRONOUS = 0x01, /**< Isocron Transfer.*/
  EMC_USB_TransferType_BULK        = 0x02, /**< Buld Transfer.*/
  EMC_USB_TransferType_INTERRUPT   = 0x03  /**< Interrupt Transfer.*/
} EMC_USB_TransferType;

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif
