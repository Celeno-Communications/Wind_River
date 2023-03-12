/**
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/test/unittest.h"
#include "emc/vendor/celeno/device/MiscReg.h"

extern emc_std_uint32_t pci_cfg_0_reg;
extern emc_std_uint32_t host_if_reg;
extern emc_std_uint32_t usb_capabilities;
extern emc_std_uint32_t clock_management;
extern emc_std_uint32_t chip_version;
extern emc_std_uint32_t wd_time;
extern emc_std_uint32_t wd_en;
extern emc_std_uint32_t wd_time_dyn;

void setUp(void)
{}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(MiscReg_test_read_pid) {
  EMC_CUNIT_ASSERT_EQUAL(0x603F0000, EMC_USB_CELENO_PCI_CFG_0);
  EMC_CUNIT_ASSERT_EQUAL(0x6000, EMC_USB_CELENO_pci_cfg_read_pid());

  pci_cfg_0_reg = 0x12348FFF;
  EMC_CUNIT_ASSERT_EQUAL(0x1234, EMC_USB_CELENO_pci_cfg_read_pid());

  pci_cfg_0_reg = 0x87657FFF;
  EMC_CUNIT_ASSERT_EQUAL(0x8765, EMC_USB_CELENO_pci_cfg_read_pid());
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(MiscReg_test_chip_version) {
  EMC_CUNIT_ASSERT_EQUAL(0x607C5050, EMC_USB_CELENO_CHIP_VERSION);
  EMC_CUNIT_ASSERT_EQUAL(0x6000, EMC_USB_CELENO_chip_product_id());
  EMC_CUNIT_ASSERT_EQUAL(0xA, EMC_USB_CELENO_chip_version_step());
  EMC_CUNIT_ASSERT_EQUAL(0x0, EMC_USB_CELENO_chip_version_rev());

  chip_version = 0x006000B0;
  EMC_CUNIT_ASSERT_EQUAL(0x6000, EMC_USB_CELENO_chip_product_id());
  EMC_CUNIT_ASSERT_EQUAL(0xB, EMC_USB_CELENO_chip_version_step());
  EMC_CUNIT_ASSERT_EQUAL(0x0, EMC_USB_CELENO_chip_version_rev());

  chip_version = 0xFF1234B1;
  EMC_CUNIT_ASSERT_EQUAL(0x1234, EMC_USB_CELENO_chip_product_id());
  EMC_CUNIT_ASSERT_EQUAL(0xB, EMC_USB_CELENO_chip_version_step());
  EMC_CUNIT_ASSERT_EQUAL(0x1, EMC_USB_CELENO_chip_version_rev());

  chip_version = 0x006000A1;
  EMC_CUNIT_ASSERT_EQUAL(0x6000, EMC_USB_CELENO_chip_product_id());
  EMC_CUNIT_ASSERT_EQUAL(0xA, EMC_USB_CELENO_chip_version_step());
  EMC_CUNIT_ASSERT_EQUAL(0x1, EMC_USB_CELENO_chip_version_rev());

  chip_version = 0xFFFFFEF1;
  EMC_CUNIT_ASSERT_EQUAL(0xFFFE, EMC_USB_CELENO_chip_product_id());
  EMC_CUNIT_ASSERT_EQUAL(0xF, EMC_USB_CELENO_chip_version_step());
  EMC_CUNIT_ASSERT_EQUAL(0x1, EMC_USB_CELENO_chip_version_rev());

  chip_version = 0xFFFFFF0D;
  EMC_CUNIT_ASSERT_EQUAL(0xFFFF, EMC_USB_CELENO_chip_product_id());
  EMC_CUNIT_ASSERT_EQUAL(0x0, EMC_USB_CELENO_chip_version_step());
  EMC_CUNIT_ASSERT_EQUAL(0xD, EMC_USB_CELENO_chip_version_rev());
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(MiscReg_test_host_if_limit_hs)
{
  EMC_CUNIT_ASSERT_EQUAL(0x607C5140, EMC_USB_CELENO_HOST_IF);

  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_host_if_is_hs());

  host_if_reg = 0xFFFFFFFD;
  EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_CELENO_host_if_is_hs());

  host_if_reg = 0x00000002;
  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_host_if_is_hs());
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(MiscReg_test_host_if_usb)
{
  EMC_CUNIT_ASSERT_EQUAL(0x607C5140, EMC_USB_CELENO_HOST_IF);

  EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_CELENO_host_if_is_usb());

  host_if_reg = 0x00000001;
  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_host_if_is_usb());

  host_if_reg = 0xFFFFFFFE;
  EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_CELENO_host_if_is_usb());
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(MiscReg_test_usb_capabilities)
{
  EMC_CUNIT_ASSERT_EQUAL(0x607C514C, EMC_USB_CELENO_USB_CAPS);

  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_usb_caps_ss_pm_disabled());
  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_usb_caps_hs_pm_disabled());

  usb_capabilities = 0xFFFFFFFC;
  EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_CELENO_usb_caps_ss_pm_disabled());
  EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_CELENO_usb_caps_hs_pm_disabled());

  usb_capabilities = 0x00000001;
  EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_CELENO_usb_caps_ss_pm_disabled());
  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_usb_caps_hs_pm_disabled());

  usb_capabilities = 0x00000002;
  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_usb_caps_ss_pm_disabled());
  EMC_CUNIT_ASSERT_EQUAL(emc_std_true, EMC_USB_CELENO_usb_caps_hs_pm_disabled());

  usb_capabilities = 0x00000003;
  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_usb_caps_ss_pm_disabled());
  EMC_CUNIT_ASSERT_EQUAL(emc_std_false, EMC_USB_CELENO_usb_caps_hs_pm_disabled());
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(MiscReg_test_clock_management)
{
  EMC_CUNIT_ASSERT_EQUAL(0x607C600C, EMC_USB_CELENO_CLOCK_CTRL);

  EMC_CUNIT_ASSERT_EQUAL(0, clock_management);
  EMC_USB_CELENO_clk_from_pll();
  EMC_CUNIT_ASSERT_EQUAL(1, clock_management);
}
EMC_CUNIT_END_TEST


EMC_CUNIT_START_TEST(MiscReg_test_watchdog)
{
  EMC_CUNIT_ASSERT_EQUAL(0x14, wd_time);
  EMC_CUNIT_ASSERT_EQUAL(0x0, wd_en);
  EMC_CUNIT_ASSERT_EQUAL(0x14, wd_time_dyn);


  EMC_CELENO_wd_enable(emc_std_true);
  EMC_CUNIT_ASSERT_EQUAL(0x1, wd_en);

  EMC_CELENO_wd_timeout(6);
  EMC_CUNIT_ASSERT_EQUAL(0x6, wd_time);

  EMC_CELENO_wd_rewind();
  EMC_CUNIT_ASSERT_EQUAL(0x6, wd_time);
  EMC_CUNIT_ASSERT_EQUAL(0x6, EMC_CELENO_wd_dyn_time());
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(MiscReg_test_vid_pid_guid)
{
  EMC_CUNIT_ASSERT_EQUAL(0x33de, EMC_USB_CELENO_vendor_id_from_guid(0x600033de));
  EMC_CUNIT_ASSERT_EQUAL(0x6000, EMC_USB_CELENO_product_id_from_guid(0x600033de));

  EMC_CUNIT_ASSERT_EQUAL(0x0000, EMC_USB_CELENO_vendor_id_from_guid(0x123F0000));
  EMC_CUNIT_ASSERT_EQUAL(0x123F, EMC_USB_CELENO_product_id_from_guid(0x123F0000));

  EMC_CUNIT_ASSERT_EQUAL(0x8678, EMC_USB_CELENO_vendor_id_from_guid(0x12348678));
  EMC_CUNIT_ASSERT_EQUAL(0x1234, EMC_USB_CELENO_product_id_from_guid(0x12348678));
}
EMC_CUNIT_END_TEST
// clang-format on

EMC_CUNIT_TEST_SUITE(MiscReg_test);

EMC_CUNIT_TEST(MiscReg_test_read_pid);
EMC_CUNIT_TEST(MiscReg_test_chip_version);
EMC_CUNIT_TEST(MiscReg_test_host_if_limit_hs);
EMC_CUNIT_TEST(MiscReg_test_host_if_usb);
EMC_CUNIT_TEST(MiscReg_test_usb_capabilities);
EMC_CUNIT_TEST(MiscReg_test_clock_management);
EMC_CUNIT_TEST(MiscReg_test_watchdog);
EMC_CUNIT_TEST(MiscReg_test_vid_pid_guid);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(MiscReg_test)

EMC_TEST_SUITE_DEFINE_MAIN()
