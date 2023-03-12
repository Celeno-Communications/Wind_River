/**
 * @file
 * @brief Configuration descriptors for CLI-only device
 * @copyright 2021 emsys Embedded Systems GmbH
 */

#include "emc/system/celeno/configure.h"
#include "emc/vendor/celeno/configure.h"
#include "emc/usb/vendor/celeno/cli/device/DescriptorValues.h"
#include "emc/usb/usb.h"

const emc_std_uint8_t mg_config_0_fs[] = {
  EMC_USB_DESCRIPTOR(Configuration),
  EMC_USB_FROM_UINT16(EMC_USB_ConfigurationDescriptor_SIZE + CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_FS),
  1,   /**< number interfaces */
  0x1, /**< number of this configuration */
  NO_STRING_INDEX,
  EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES,
  EMC_USB_POWER(EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_HS,
                EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES),

  CELENO_CLI_IFC_DESCRIPTORS_FS
};

const emc_std_uint8_t mg_config_0_hs[] = {
  EMC_USB_DESCRIPTOR(Configuration),
  EMC_USB_FROM_UINT16(EMC_USB_ConfigurationDescriptor_SIZE + CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_HS),
  1,   /**< number interfaces */
  0x1, /**< number of this configuration */
  NO_STRING_INDEX,
  EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES,
  EMC_USB_POWER(EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_HS,
                EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES),

  CELENO_CLI_IFC_DESCRIPTORS_HS
};

const emc_std_uint8_t mg_other_speed_config_0_fs[] = {
  EMC_USB_DESCRIPTOR(OtherSpeedConfiguration),
  EMC_USB_FROM_UINT16(EMC_USB_ConfigurationDescriptor_SIZE + CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_HS),
  1,   /**< number interfaces */
  0x1, /**< number of this configuration */
  NO_STRING_INDEX,
  EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES,
  EMC_USB_POWER(EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_HS,
                EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES),

  CELENO_CLI_IFC_DESCRIPTORS_HS
};

const emc_std_uint8_t mg_other_speed_config_0_hs[] = {
  EMC_USB_DESCRIPTOR(OtherSpeedConfiguration),
  EMC_USB_FROM_UINT16(EMC_USB_ConfigurationDescriptor_SIZE + CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_FS),
  1,   /**< number interfaces */
  0x1, /**< number of this configuration */
  NO_STRING_INDEX,
  EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES,
  EMC_USB_POWER(EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_HS,
                EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES),

  CELENO_CLI_IFC_DESCRIPTORS_FS
};

const emc_std_uint8_t mg_config_0_ss[] = {
  EMC_USB_DESCRIPTOR(Configuration),
  EMC_USB_FROM_UINT16(EMC_USB_ConfigurationDescriptor_SIZE + CELENO_CLI_IFC_DESCRIPTORS_TOTAL_LENGTH_SS),
  1,   /**< number interfaces */
  0x1, /**< number of this configuration */
  NO_STRING_INDEX,
  EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES,
  EMC_USB_POWER_SS(EMC_USB_VENDOR_CELENO_MAX_POWER_MILLIAMPERE_SS,
                   EMC_USB_VENDOR_CELENO_POWER_ATTRIBUTES),

  CELENO_CLI_IFC_DESCRIPTORS_SS
};

const emc_std_uint8_t StrDesc_Product[] = {
  22,                           /**< length of descriptor */
  EMC_USB_StringDescriptor_TYPE,
  'B',                           0,
  'o',                           0,
  'o',                           0,
  't',                           0,
  'l',                           0,
  'o',                           0,
  'a',                           0,
  'd',                           0,
  'e',                           0,
  'r',                           0,
};
