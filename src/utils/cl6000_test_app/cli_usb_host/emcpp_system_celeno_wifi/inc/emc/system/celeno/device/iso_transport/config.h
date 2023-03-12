/**
 * @file
 * @brief The specific DescriptorSet
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_config_H
#define EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_config_H

#define EMSYS_VENDOR_ID 0x0cc4
#define ISO_PRODUCT_ID 0x0100
#define ISO_DEVICE_VERSION 0x0100

#define EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_HS 500
#define EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_SS (900 - 7) // to ensure that we are not above 900mA because of
                                                                 // multiples of 8mA
#define EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES EMC_USB_POWER_ATTRIBUTE_MANDATORY

#define CELENO_BT_ISO_IFC_NUM 0
#define CELENO_BT_ISO_IF_COUNT 1
#define CELENO_BT_ISO_IN 0x81
#define CELENO_BT_ISO_OUT 0x01
#define CELENO_BT_ISO_MPS_ALT1 64
#define CELENO_BT_ISO_MPS_MAX 64
#define CELENO_BT_ISO_POLLING_INT 4

#define EMC_USB_CELENO_ISO_NO_CHUNKS 32

#endif /* EMC_SYSTEM_CELENO_DEVICE_ISO_TRANSPORT_config_H */
