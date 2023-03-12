/**
 * @file
 * @brief     Descriptor Set for vendor-specific CLI interface.
 * @author    Karsten Pahnke <karsten.pahnke@emsys.de>
 * @copyright 2021 emsys Embedded Systems GmbH
 */

#include "emc/vendor/celeno/configure.h"
#include "emc/vendor/celeno/device/usb/descriptor/DescriptorSet.h"
#include "emc/vendor/celeno/device/MiscReg.h"

#include "emc/usb/descriptor/Descriptor.h"
#include "emc/usb/descriptor/DeviceDescriptor.h"
#include "emc/usb/descriptor/DeviceQualifierDescriptor.h"
#include "emc/usb/descriptor/ConfigurationDescriptor.h"
#include "emc/usb/descriptor/BOSDescriptor.h"
#include "emc/usb/descriptor/StringDescriptor.h"
#include "emc/usb/descriptor/DescriptorSet.h"

#include "emc/data/numop.h"
#include "emc/std/assert.h"

#define NUMBER_CONFIGURATIONS 1

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
**  Full Speed Descriptors
*********************************************************************/

static EMC_USB_DeviceDescriptor mg_device_fs = {
  EMC_USB_DESCRIPTOR(Device),
  EMC_USB_FROM_UINT16(USB_SPEC_BCD_VERSION_20),
  USB_CLASS_IN_INTERFACE,
  USB_SUBCLASS_IN_INTERFACE,
  USB_PROTOCOL_IN_INTERFACE,
  USB_EP_MPS_CTRL_FULL_SPEED,
  EMC_USB_FROM_UINT16(CELENO_VENDOR_ID),
  EMC_USB_FROM_UINT16(CELENO_PRODUCT_ID),
  EMC_USB_FROM_UINT16(CELENO_DEVICE_VERSION),
  MANUFACTURER_STRING_INDEX,
  PRODUCT_STRING_INDEX,
  SERIAL_NUMBER_STRING_INDEX,
  NUMBER_CONFIGURATIONS
};

extern const emc_std_uint8_t mg_config_0_fs[];

static const EMC_USB_ConfigurationDescriptor* mg_configs_fs[] = {
  (const EMC_USB_ConfigurationDescriptor*)mg_config_0_fs
};

#if EMC_USB_MAX_SPEED >= EMC_USB_HIGH_SPEED

/*********************************************************************
**  High Speed Descriptors
*********************************************************************/

static EMC_USB_DeviceDescriptor mg_device_hs = {
  EMC_USB_DESCRIPTOR(Device),
#  if EMC_USB_MAX_SPEED >= EMC_USB_SUPER_SPEED
  EMC_USB_FROM_UINT16(USB_SPEC_BCD_VERSION_21),
#  else
  EMC_USB_FROM_UINT16(USB_SPEC_BCD_VERSION_20),
#  endif
  USB_CLASS_IN_INTERFACE,
  USB_SUBCLASS_IN_INTERFACE,
  USB_PROTOCOL_IN_INTERFACE,
  USB_EP_MPS_CTRL_HIGH_SPEED,
  EMC_USB_FROM_UINT16(CELENO_VENDOR_ID),
  EMC_USB_FROM_UINT16(CELENO_PRODUCT_ID),
  EMC_USB_FROM_UINT16(CELENO_DEVICE_VERSION),
  MANUFACTURER_STRING_INDEX,
  PRODUCT_STRING_INDEX,
  SERIAL_NUMBER_STRING_INDEX,
  NUMBER_CONFIGURATIONS
};

static const EMC_USB_DeviceQualifierDescriptor mg_device_qualifier_hs = {
  EMC_USB_DESCRIPTOR(DeviceQualifier),
  EMC_USB_FROM_UINT16(USB_SPEC_BCD_VERSION_20),
  USB_CLASS_IN_INTERFACE,
  USB_SUBCLASS_IN_INTERFACE,
  USB_PROTOCOL_IN_INTERFACE,
  USB_EP_MPS_CTRL_HIGH_SPEED,
  NUMBER_CONFIGURATIONS,
  0 /**< reserved */
};

extern const emc_std_uint8_t mg_config_0_hs[];

static const EMC_USB_ConfigurationDescriptor* mg_configs_hs[] = {
  (const EMC_USB_ConfigurationDescriptor*)mg_config_0_hs
};

extern const emc_std_uint8_t mg_other_speed_config_0_fs[];

static const EMC_USB_ConfigurationDescriptor* mg_other_speed_configs_fs[] = {
  (const EMC_USB_ConfigurationDescriptor*)mg_other_speed_config_0_fs
};

extern const emc_std_uint8_t mg_other_speed_config_0_hs[];

static const EMC_USB_ConfigurationDescriptor* mg_other_speed_configs_hs[] = {
  (const EMC_USB_ConfigurationDescriptor*)mg_other_speed_config_0_hs
};

static emc_std_uint8_t mg_bos_descriptor[] = {
  EMC_USB_DESCRIPTOR(BOS),
  EMC_USB_FROM_UINT16(22),                            /**< Total length */
  2,                                                  /**< Number of device capabilities */
  EMC_USB_DEVICE_CAPABILITY_DESCRIPTOR(SuperSpeed),
  0,                                                  /**< bmAttributes */
  EMC_USB_FROM_UINT16(0x0E),                          /**< bSpeedSupported */
  0x1,                                                /**< bFunctionalitySupport */
  0x0A,                                               /**< U1 Exit latency: Less than 10 us */
  EMC_USB_FROM_UINT16(0x7FF),                         /**< U2 Exit latency: Less than 2047 us */
  EMC_USB_DEVICE_CAPABILITY_DESCRIPTOR(USB2Extension),
  0x6, 0x0, 0x0, 0x0 /**< bmAttributes: LPM and BESL supported */
};

#  ifdef EMC_USB_USE_BCDUSB_210_HS
static const emc_std_uint8_t mg_bos_descriptor_hs[] = {
  EMC_USB_DESCRIPTOR(BOS),
  12,    0, /**< Total length */
  1,        /**< Number of device capabilities */
  EMC_USB_DEVICE_CAPABILITY_DESCRIPTOR(USB2Extension),
  0x6, 0x0, 0x0, 0x0 /**< bmAttributes: LPM and BESL supported */
};
#  endif

#endif /*EMC_USB_MAX_SPEED >= EMC_USB_HIGH_SPEED*/

#if EMC_USB_MAX_SPEED >= EMC_USB_SUPER_SPEED

/*********************************************************************
**  Super Speed Descriptors
*********************************************************************/

static EMC_USB_DeviceDescriptor mg_device_ss = {
  EMC_USB_DESCRIPTOR(Device),
  EMC_USB_FROM_UINT16(USB_SPEC_BCD_VERSION_32),
  USB_CLASS_IN_INTERFACE,
  USB_SUBCLASS_IN_INTERFACE,
  USB_PROTOCOL_IN_INTERFACE,
  USB_EP_MPS_CTRL_SUPER_SPEED,
  EMC_USB_FROM_UINT16(CELENO_VENDOR_ID),
  EMC_USB_FROM_UINT16(CELENO_PRODUCT_ID),
  EMC_USB_FROM_UINT16(CELENO_DEVICE_VERSION),
  MANUFACTURER_STRING_INDEX,
  PRODUCT_STRING_INDEX,
  SERIAL_NUMBER_STRING_INDEX,
  NUMBER_CONFIGURATIONS
};

extern const emc_std_uint8_t mg_config_0_ss[];

static const EMC_USB_ConfigurationDescriptor* mg_configs_ss[] = {
  (const EMC_USB_ConfigurationDescriptor*)mg_config_0_ss
};

#endif /*EMC_USB_MAX_SPEED >= EMC_USB_SUPE_SPEED*/

/*********************************************************************
**  String Descriptors
*********************************************************************/
static const emc_std_uint8_t StrDesc_English_United_States[] = {
  4, /**< length of descriptor */
  EMC_USB_StringDescriptor_TYPE,
  0x9, 0x4 /**< language ID */
};

static const emc_std_uint8_t StrDesc_Manufacturer[] = {
  22,                           /**< length of descriptor */
  EMC_USB_StringDescriptor_TYPE,
  'c',                           0,
  'e',                           0,
  'l',                           0,
  'e',                           0,
  'n',                           0,
  'o',                           0,
  ' ',                           0,
  'l',                           0,
  't',                           0,
  'd',                           0,
};

static const emc_std_uint8_t StrDesc_DefaultProduct[] = {
  14,                           /**< length of descriptor */
  EMC_USB_StringDescriptor_TYPE,
  'C',                           0,
  'L',                           0,
  '6',                           0,
  '0',                           0,
  '0',                           0,
  '0',                           0,
};

static emc_std_uint8_t StrDesc_Serial_Number[] = {
  24,                           /**< length of descriptor */
  EMC_USB_StringDescriptor_TYPE,
  '?',                           0,
  '?',                           0,
  '?',                           0,
  '?',                           0,
  '?',                           0,
  '?',                           0,
  '?',                           0,
  '?',                           0,
  '?',                           0,
  '?',                           0,
  '?',                           0,
};

static const emc_std_uint8_t StrDesc_Interface_CLI[] = {
  28,                           /**< length of descriptor */
  EMC_USB_StringDescriptor_TYPE,
  'C',                           0,
  'L',                           0,
  'I',                           0,
  ' ',                           0,
  'I',                           0,
  'n',                           0,
  't',                           0,
  'e',                           0,
  'r',                           0,
  'f',                           0,
  'a',                           0,
  'c',                           0,
  'e', 0
};

/** here we should check if the other tables also need to be put in zi? */

#if defined(__arm)
#  pragma arm section zidata
#endif

static const EMC_USB_StringDescriptor* mg_strings_english[] = {
  (const EMC_USB_StringDescriptor*)StrDesc_English_United_States,
  (const EMC_USB_StringDescriptor*)StrDesc_Manufacturer,
  (const EMC_USB_StringDescriptor*)StrDesc_DefaultProduct,
  (const EMC_USB_StringDescriptor*)StrDesc_Serial_Number,
  (const EMC_USB_StringDescriptor*)StrDesc_Interface_CLI,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

static const EMC_USB_StringDescriptor* const* mg_strings[] = {
  mg_strings_english
};

/*********************************************************************
**  DescriptorSet
*********************************************************************/

static EMC_USB_DescriptorSet mg_usb_descriptor_set = {
  {
    {
      &mg_device_fs,
      1,
      mg_configs_fs,
#if EMC_USB_MAX_SPEED >= EMC_USB_HIGH_SPEED
      &mg_device_qualifier_hs,
      mg_other_speed_configs_fs,
#else
      0,
      0
#endif
    },
#if EMC_USB_MAX_SPEED >= EMC_USB_HIGH_SPEED
    {
      &mg_device_hs,
      1,
      mg_configs_hs,
      &mg_device_qualifier_hs,
      mg_other_speed_configs_hs,
    },
#else
    { 0, 0, 0, 0, 0 },
#endif
#if EMC_USB_MAX_SPEED >= EMC_USB_SUPER_SPEED
    {
      &mg_device_ss,
      1,
      mg_configs_ss,
      0,
      0
    }
#else
    { 0, 0, 0, 0, 0 }
#endif
  },
#if EMC_USB_MAX_SPEED >= EMC_USB_HIGH_SPEED
  (const EMC_USB_BOSDescriptor*)mg_bos_descriptor,
#else
  (const EMC_USB_BOSDescriptor*)0,
#endif
  mg_strings,
  1,                                 /**< number languages */
  4 + EMC_VENDOR_CELENO_USB_IF_COUNT /**< number of string descs */
};

const EMC_USB_DescriptorSet* EMC_USB_DescriptorSet_instance(void)
{
  return &mg_usb_descriptor_set;
}

static void set_vid_pid_bcd(EMC_USB_DeviceDescriptor* device_desc,
                            emc_std_uint16_t vid,
                            emc_std_uint16_t pid,
                            emc_std_uint16_t bcd)
{
  device_desc->idVendorLo = emc_low_uint8(vid);
  device_desc->idVendorHi = emc_high_uint8(vid);
  device_desc->idProductLo = emc_low_uint8(pid);
  device_desc->idProductHi = emc_high_uint8(pid);
  device_desc->bcdDeviceLo = emc_low_uint8(bcd);
  device_desc->bcdDeviceHi = emc_high_uint8(bcd);
}

void EMC_USB_CELENO_DescriptorSet_configure(emc_std_uint16_t vid,
                                            emc_std_uint16_t pid,
                                            emc_std_uint16_t bcdDevice,
                                            const EMC_USB_StringDescriptor* serial_number)
{
  if (serial_number) {
    mg_strings_english[SERIAL_NUMBER_STRING_INDEX] = serial_number;
  }

  set_vid_pid_bcd(&mg_device_fs, vid, pid, bcdDevice);
#if EMC_USB_MAX_SPEED >= EMC_USB_HIGH_SPEED
  set_vid_pid_bcd(&mg_device_hs, vid, pid, bcdDevice);
#endif
#if EMC_USB_MAX_SPEED >= EMC_USB_SUPER_SPEED
  set_vid_pid_bcd(&mg_device_ss, vid, pid, bcdDevice);
#endif
}

void EMC_USB_CELENO_DescriptorSet_configure_string(emc_std_uint8_t index, const EMC_USB_StringDescriptor* string)
{
  emc_std_assert(index < sizeof(mg_strings_english) / sizeof(void*));
  mg_strings_english[index] = string;
}

void EMC_USB_CELENO_DescriptorSet_limit_HS(void)
{
#ifdef EMC_USB_USE_BCDUSB_210_HS
  mg_device_hs.bcdUSBLo = emc_low_uint8(USB_SPEC_BCD_VERSION_21);
  mg_device_hs.bcdUSBHi = emc_high_uint8(USB_SPEC_BCD_VERSION_21);
  mg_usb_descriptor_set.bos_desc = (const EMC_USB_BOSDescriptor*)mg_bos_descriptor_hs;
#else
  mg_device_hs.bcdUSBLo = emc_low_uint8(USB_SPEC_BCD_VERSION_20);
  mg_device_hs.bcdUSBHi = emc_high_uint8(USB_SPEC_BCD_VERSION_20);
  mg_usb_descriptor_set.bos_desc = (const EMC_USB_BOSDescriptor*)EMC_STD_NULL;
#endif
}

void EMC_USB_CELENO_DescriptorSet_disable_lpm_besl(void)
{
  EMC_USB_DeviceCapabilityDescriptor* usb2_ext =
    EMC_USB_BOSDescriptor_device_capability((const EMC_USB_BOSDescriptor*)mg_bos_descriptor,
                                            EMC_USB_USB2Extension_CapabilityDescriptor_SUB_TYPE);

  if (usb2_ext) {
    emc_std_uint32_t* attributes = (emc_std_uint32_t*)(usb2_ext + 1);
    *attributes = 0;
  }
}

#ifdef __cplusplus
}
#endif
