/** Copyright (C) 2021 emsys Embedded Systems GmbH */
#include "emc/test/unittest.h"
#include "emc/vendor/celeno/device/SystemGlobalInit.h"
#include "emc/usb/vendor/celeno/usbwrapper/device/register/usbw_reg.h"

void setUp(void)
{}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(SystemGlobalInitTest_init)
{
  emc_std_uint32_t sram = 0;

  EMC_USB_CELENO_Wrapper_init(0, 0);

  EMC_CUNIT_ASSERT(0x00000007 == usbw_usbw_conf_get());

  EMC_USB_CELENO_system_global_init((emc_std_uintptr_t)&sram);

  EMC_CUNIT_ASSERT(0x00000005 == usbw_usbw_conf_get());
  EMC_CUNIT_ASSERT(0x00100F20 == sram);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(SystemGlobalInitTest);
EMC_CUNIT_TEST(SystemGlobalInitTest_init);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(SystemGlobalInitTest)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on
