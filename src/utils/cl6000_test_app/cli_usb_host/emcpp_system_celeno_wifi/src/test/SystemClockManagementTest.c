/** Copyright (C) 2021 emsys Embedded Systems GmbH */
#include "emc/test/unittest.h"
#include "emc/usb/device/test/DeviceMock.h"
#include "emc/usb/device/Device.h"
#include "emc/usb/descriptor/DescriptorSet.h"

#include "emc/system/celeno/device/bootloader/SystemClockManagement.h"

extern const EMC_USB_DescriptorSet* EMC_USB_DescriptorSet_instance();
static emc_std_uint8_t ep0_dma_buffer[512];

extern emc_std_uint32_t clock_management;

static void init_device(EMC_USB_Speed usb_speed)
{
  EMC_USB_DeviceConfig device_config;

  clock_management = 0x0;

  EMC_USB_DeviceConfig_init(&device_config);
  device_config.ep0_buffer = ep0_dma_buffer;
  device_config.ep0_buffer_size = sizeof(ep0_dma_buffer);
  device_config.hw.max_speed = usb_speed;

  EMC_USB_Device_create(&device_config, EMC_USB_DescriptorSet_instance());

  system_clock_mng_init();
  system_clock_mng_start();

}

void setUp(void)
{}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(SystemClockManagementTest_ss_enumeration)
{
  init_device(EMC_USB_Speed_SUPER);
  EMC_CUNIT_ASSERT(0x0 == clock_management);

  EMC_USB_DeviceMock_connect(EMC_USB_Device_GetDevice());
  EMC_CUNIT_ASSERT(0x0 == clock_management);

  EMC_USB_DeviceMock_reset(EMC_USB_Device_GetDevice());
  EMC_CUNIT_ASSERT(0x1 == clock_management);

  EMC_USB_DeviceMock_set_address(EMC_USB_Device_GetDevice(), 1);
  EMC_CUNIT_ASSERT(0x1 == clock_management);

  EMC_USB_DeviceMock_set_configuration(EMC_USB_Device_GetDevice(), 1);
  EMC_CUNIT_ASSERT(0x1 == clock_management);

  EMC_USB_DeviceMock_reset(EMC_USB_Device_GetDevice());
  EMC_CUNIT_ASSERT(0x1 == clock_management);

  EMC_USB_Device_destroy();
}
EMC_CUNIT_END_TEST

void test_enumeration_no_clock_switch(EMC_USB_Speed speed)
{
  init_device(speed);
  EMC_CUNIT_ASSERT(0x0 == clock_management);

  EMC_USB_DeviceMock_connect(EMC_USB_Device_GetDevice());
  EMC_CUNIT_ASSERT(0x0 == clock_management);

  EMC_USB_DeviceMock_reset(EMC_USB_Device_GetDevice());
  EMC_CUNIT_ASSERT(0x0 == clock_management);

  EMC_USB_DeviceMock_set_address(EMC_USB_Device_GetDevice(), 1);
  EMC_CUNIT_ASSERT(0x0 == clock_management);

  EMC_USB_DeviceMock_set_configuration(EMC_USB_Device_GetDevice(), 1);
  EMC_CUNIT_ASSERT(0x0 == clock_management);

  EMC_USB_DeviceMock_reset(EMC_USB_Device_GetDevice());
  EMC_CUNIT_ASSERT(0x0 == clock_management);

  EMC_USB_Device_destroy();
}

EMC_CUNIT_START_TEST(SystemClockManagementTest_hs_enumeration)
{
  test_enumeration_no_clock_switch(EMC_USB_Speed_HIGH);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(SystemClockManagementTest_fs_enumeration)
{
  test_enumeration_no_clock_switch(EMC_USB_Speed_FULL);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(SystemClockManagementTest);
EMC_CUNIT_TEST(SystemClockManagementTest_ss_enumeration);
EMC_CUNIT_TEST(SystemClockManagementTest_hs_enumeration);
EMC_CUNIT_TEST(SystemClockManagementTest_fs_enumeration);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(SystemClockManagementTest)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on
