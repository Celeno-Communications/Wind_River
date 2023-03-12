/**
 * @file
 * @brief   DescriptorSet Configuration test
 * @author  <ralf.oberlaender@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/vendor/celeno/configure.h"
#include "emc/vendor/celeno/device/usb/descriptor/DescriptorSet.h"
#include "emc/usb/descriptor/DescriptorSet.h"
#include "emc/usb/descriptor/DeviceDescriptor.h"
#include "emc/usb/descriptor/BOSDescriptor.h"

#include "emc/test/unittest.h"
#include "emc/std/string.h"

void setUp(void)
{}

void tearDown(void)
{}

EMC_CUNIT_START_TEST(DescriptorSetConfigure_test_set_vid_pid_bcd) {
  uint8_t expected[] =
  {24, 3, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0};
  const EMC_USB_DescriptorSet* descriptor_set = 0;

  EMC_USB_CELENO_DescriptorSet_configure(0x5678, 0xFE12, 0x34AB, 0);
  descriptor_set = EMC_USB_DescriptorSet_instance();

  EMC_CUNIT_ASSERT_EQUAL(0x78, descriptor_set->speed_set[0].device->idVendorLo);
  EMC_CUNIT_ASSERT_EQUAL(0x56, descriptor_set->speed_set[0].device->idVendorHi);
  EMC_CUNIT_ASSERT_EQUAL(0x12, descriptor_set->speed_set[0].device->idProductLo);
  EMC_CUNIT_ASSERT_EQUAL(0xFE, descriptor_set->speed_set[0].device->idProductHi);
  EMC_CUNIT_ASSERT_EQUAL(0xAB, descriptor_set->speed_set[0].device->bcdDeviceLo);
  EMC_CUNIT_ASSERT_EQUAL(0x34, descriptor_set->speed_set[0].device->bcdDeviceHi);

  EMC_CUNIT_ASSERT_EQUAL(0x78, descriptor_set->speed_set[1].device->idVendorLo);
  EMC_CUNIT_ASSERT_EQUAL(0x56, descriptor_set->speed_set[1].device->idVendorHi);
  EMC_CUNIT_ASSERT_EQUAL(0x12, descriptor_set->speed_set[1].device->idProductLo);
  EMC_CUNIT_ASSERT_EQUAL(0xFE, descriptor_set->speed_set[1].device->idProductHi);
  EMC_CUNIT_ASSERT_EQUAL(0xAB, descriptor_set->speed_set[1].device->bcdDeviceLo);
  EMC_CUNIT_ASSERT_EQUAL(0x34, descriptor_set->speed_set[1].device->bcdDeviceHi);

  EMC_CUNIT_ASSERT_EQUAL(0x78, descriptor_set->speed_set[2].device->idVendorLo);
  EMC_CUNIT_ASSERT_EQUAL(0x56, descriptor_set->speed_set[2].device->idVendorHi);
  EMC_CUNIT_ASSERT_EQUAL(0x12, descriptor_set->speed_set[2].device->idProductLo);
  EMC_CUNIT_ASSERT_EQUAL(0xFE, descriptor_set->speed_set[2].device->idProductHi);
  EMC_CUNIT_ASSERT_EQUAL(0xAB, descriptor_set->speed_set[2].device->bcdDeviceLo);
  EMC_CUNIT_ASSERT_EQUAL(0x34, descriptor_set->speed_set[2].device->bcdDeviceHi);

  EMC_CUNIT_ASSERT(0 ==
                   emc_std_memcmp(expected, &descriptor_set->str_desc_lut[0][SERIAL_NUMBER_STRING_INDEX][0],
                                  sizeof(expected)));
}

EMC_CUNIT_START_TEST(DescriptorSetConfigure_test_defaults) {
  uint8_t expected[] =
  {24, 3, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0, '?', 0};
  const EMC_USB_DescriptorSet* descriptor_set = 0;

  descriptor_set = EMC_USB_DescriptorSet_instance();

  EMC_CUNIT_ASSERT_EQUAL(0xDE, descriptor_set->speed_set[0].device->idVendorLo);
  EMC_CUNIT_ASSERT_EQUAL(0x33, descriptor_set->speed_set[0].device->idVendorHi);
  EMC_CUNIT_ASSERT_EQUAL(0x00, descriptor_set->speed_set[0].device->idProductLo);
  EMC_CUNIT_ASSERT_EQUAL(0x60, descriptor_set->speed_set[0].device->idProductHi);
  EMC_CUNIT_ASSERT_EQUAL(0x01, descriptor_set->speed_set[0].device->bcdDeviceLo);
  EMC_CUNIT_ASSERT_EQUAL(0x00, descriptor_set->speed_set[0].device->bcdDeviceHi);

  EMC_CUNIT_ASSERT_EQUAL(0xDE, descriptor_set->speed_set[1].device->idVendorLo);
  EMC_CUNIT_ASSERT_EQUAL(0x33, descriptor_set->speed_set[1].device->idVendorHi);
  EMC_CUNIT_ASSERT_EQUAL(0x00, descriptor_set->speed_set[1].device->idProductLo);
  EMC_CUNIT_ASSERT_EQUAL(0x60, descriptor_set->speed_set[1].device->idProductHi);
  EMC_CUNIT_ASSERT_EQUAL(0x01, descriptor_set->speed_set[1].device->bcdDeviceLo);
  EMC_CUNIT_ASSERT_EQUAL(0x00, descriptor_set->speed_set[1].device->bcdDeviceHi);

  EMC_CUNIT_ASSERT_EQUAL(0xDE, descriptor_set->speed_set[2].device->idVendorLo);
  EMC_CUNIT_ASSERT_EQUAL(0x33, descriptor_set->speed_set[2].device->idVendorHi);
  EMC_CUNIT_ASSERT_EQUAL(0x00, descriptor_set->speed_set[2].device->idProductLo);
  EMC_CUNIT_ASSERT_EQUAL(0x60, descriptor_set->speed_set[2].device->idProductHi);
  EMC_CUNIT_ASSERT_EQUAL(0x01, descriptor_set->speed_set[2].device->bcdDeviceLo);
  EMC_CUNIT_ASSERT_EQUAL(0x00, descriptor_set->speed_set[2].device->bcdDeviceHi);

  EMC_CUNIT_ASSERT(0 ==
                   emc_std_memcmp(expected, &descriptor_set->str_desc_lut[0][SERIAL_NUMBER_STRING_INDEX][0],
                                  sizeof(expected)));
}

EMC_CUNIT_START_TEST(DescriptorSetConfigure_test_set_ser_num) {
  uint8_t serial_number[] =
  {24, 3, '0', 0, '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, '8', 0, '9', 0, 'A', 0};

  const EMC_USB_DescriptorSet* descriptor_set = 0;

  EMC_USB_CELENO_DescriptorSet_configure(CELENO_VENDOR_ID, 0xFE12, CELENO_DEVICE_VERSION,
                                         (const EMC_USB_StringDescriptor*)serial_number);
  descriptor_set = EMC_USB_DescriptorSet_instance();

  EMC_CUNIT_ASSERT_EQUAL(serial_number, (const uint8_t*)descriptor_set->str_desc_lut[0][SERIAL_NUMBER_STRING_INDEX]);
}

EMC_CUNIT_START_TEST(DescriptorSetConfigure_test_set_ser_num_to_short) {
  uint8_t serial_number[] = {24, 3, '0', 0, '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, 0, 0, 0, 0, 0, 0};

  const EMC_USB_DescriptorSet* descriptor_set = 0;

  EMC_USB_CELENO_DescriptorSet_configure(CELENO_VENDOR_ID, 0xFE12, CELENO_DEVICE_VERSION,
                                         (const EMC_USB_StringDescriptor*)serial_number);
  descriptor_set = EMC_USB_DescriptorSet_instance();

  EMC_CUNIT_ASSERT_EQUAL(serial_number, (const uint8_t*)descriptor_set->str_desc_lut[0][SERIAL_NUMBER_STRING_INDEX]);
}

EMC_CUNIT_START_TEST(DescriptorSetConfigure_test_string) {
  uint8_t desc1[] = {24, 3, '0', 0, '1', 0, '2', 0, '3', 0, '4', 0, '5', 0, '6', 0, '7', 0, 0, 0, 0, 0, 0, 0};
  uint8_t desc2[] = {2};

  const EMC_USB_DescriptorSet* descriptor_set = EMC_USB_DescriptorSet_instance();

  EMC_USB_CELENO_DescriptorSet_configure_string(1, (const EMC_USB_StringDescriptor*)desc1);
  EMC_CUNIT_ASSERT_EQUAL(desc1, (const uint8_t*)descriptor_set->str_desc_lut[0][1]);

  EMC_USB_CELENO_DescriptorSet_configure_string(2, (const EMC_USB_StringDescriptor*)desc2);
  EMC_CUNIT_ASSERT_EQUAL(desc2, (const uint8_t*)descriptor_set->str_desc_lut[0][2]);

  EMC_USB_CELENO_DescriptorSet_configure_string(1, 0);
  EMC_CUNIT_ASSERT_EQUAL(0, (const uint8_t*)descriptor_set->str_desc_lut[0][1]);
  EMC_CUNIT_ASSERT(0 != descriptor_set->str_desc_lut[0][2]);
}

EMC_CUNIT_START_TEST(DescriptorSetConfigure_test_disable_lpm_besl) {
  const EMC_USB_DescriptorSet* descriptor_set = EMC_USB_DescriptorSet_instance();
  const EMC_USB_BOSDescriptor* bos_desc = descriptor_set->bos_desc;

  EMC_CUNIT_ASSERT_EQUAL(22, EMC_USB_BOSDescriptor_total_length(bos_desc));
  EMC_CUNIT_ASSERT_EQUAL(2, bos_desc->bNumDevCapabilities);

  EMC_CUNIT_ASSERT_EQUAL(0x06, *((emc_std_uint8_t*)bos_desc + 18));
  EMC_USB_CELENO_DescriptorSet_disable_lpm_besl();
  EMC_CUNIT_ASSERT_EQUAL(0x00, *((emc_std_uint8_t*)bos_desc + 18));
}

EMC_CUNIT_START_TEST(DescriptorSetConfigure_test_limit_HS) {
  const EMC_USB_DescriptorSet* descriptor_set = 0;

  EMC_USB_CELENO_DescriptorSet_limit_HS();
  descriptor_set = EMC_USB_DescriptorSet_instance();
  EMC_CUNIT_ASSERT_EQUAL(0x02, descriptor_set->speed_set[1].device->bcdUSBHi);
  EMC_CUNIT_ASSERT_EQUAL(0x00, descriptor_set->speed_set[1].device->bcdUSBLo);
}

EMC_CUNIT_TEST_SUITE(DescriptorSetConfigure_test);

EMC_CUNIT_TEST(DescriptorSetConfigure_test_defaults);
EMC_CUNIT_TEST(DescriptorSetConfigure_test_string);
EMC_CUNIT_TEST(DescriptorSetConfigure_test_set_vid_pid_bcd);
EMC_CUNIT_TEST(DescriptorSetConfigure_test_set_ser_num);
EMC_CUNIT_TEST(DescriptorSetConfigure_test_set_ser_num_to_short);
EMC_CUNIT_TEST(DescriptorSetConfigure_test_disable_lpm_besl);
EMC_CUNIT_TEST(DescriptorSetConfigure_test_limit_HS);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(DescriptorSetConfigure_test)

EMC_TEST_SUITE_DEFINE_MAIN()
