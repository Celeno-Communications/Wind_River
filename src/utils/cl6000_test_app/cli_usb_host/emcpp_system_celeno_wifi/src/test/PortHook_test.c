/**
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/test/unittest.h"
#include "emc/system/celeno/PortHook.h"
#include "emc/hw/port/MemoryMappedPort.h"

#define DWC_usb3_DCFG_OFFSET 0x0000C700
#define DWC_usb3_DCTL_OFFSET 0x0000C704

void setUp(void)
{}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(PortHook_test_ss_pm_disable)
{
  emc_std_uint32_t registers[0x10000/sizeof(emc_std_uint32_t)];
  emc_std_uintptr_t base = (emc_std_uintptr_t)&registers;

  EMC_HW_Port port;
  emc_std_uint32_t reg_ofs = DWC_usb3_DCTL_OFFSET;
  emc_std_uint32_t to_write;
  emc_std_uint32_t masked;
  emc_std_uint32_t val;

  EMC_MemoryMappedPort_init(&port, base);

  EMC_USB_CELENO_port_hook_init(base);

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0;
  to_write = 0xFFFFFFFF;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(to_write, val);

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0xFFFFFFFF;
  to_write = 0;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(to_write, val);

  EMC_USB_CELENO_port_hook_disable_ss_pm();

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0;
  to_write = 0xFFFFFFFF;
  masked = 0xFFFFE1FF;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(masked, val);

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0xFFFFFFFF;
  to_write = 0;
  masked = 0x00001E00;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(masked, val);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(PortHook_test_hs_pm_disable_dcfg)
{
  emc_std_uint32_t registers[0x10000/sizeof(emc_std_uint32_t)];
  emc_std_uintptr_t base = (emc_std_uintptr_t)&registers;

  EMC_HW_Port port;
  emc_std_uint32_t reg_ofs = DWC_usb3_DCFG_OFFSET;
  emc_std_uint32_t to_write;
  emc_std_uint32_t masked;
  emc_std_uint32_t val;

  EMC_MemoryMappedPort_init(&port, base);

  EMC_USB_CELENO_port_hook_init(base);

  registers[DWC_usb3_DCFG_OFFSET/sizeof(emc_std_uint32_t)] = 0;
  to_write = 0xFFFFFFFF;
  val = 0;
  EMC_HW_Port_write32(&port, base + DWC_usb3_DCFG_OFFSET, to_write);
  EMC_HW_Port_read32(&port, base + DWC_usb3_DCFG_OFFSET, &val);
  EMC_CUNIT_ASSERT_EQUAL(to_write, val);

  registers[DWC_usb3_DCFG_OFFSET/sizeof(emc_std_uint32_t)] = 0xFFFFFFFF;
  to_write = 0;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(to_write, val);

  EMC_USB_CELENO_port_hook_disable_hs_pm();

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0;
  to_write = 0xFFFFFFFF;
  masked = 0xFFBFFFFF;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(masked, val);

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0xFFFFFFFF;
  to_write = 0;
  masked = 0x00400000;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(masked, val);
}
EMC_CUNIT_END_TEST
EMC_CUNIT_START_TEST(PortHook_test_hs_pm_disable_dctl)
{
  emc_std_uint32_t registers[0x10000/sizeof(emc_std_uint32_t)];
  emc_std_uintptr_t base = (emc_std_uintptr_t)&registers;

  EMC_HW_Port port;
  emc_std_uint32_t reg_ofs = DWC_usb3_DCTL_OFFSET;
  emc_std_uint32_t to_write;
  emc_std_uint32_t masked;
  emc_std_uint32_t val;

  EMC_MemoryMappedPort_init(&port, base);

  EMC_USB_CELENO_port_hook_init(base);

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0;
  to_write = 0xFFFFFFFF;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(to_write, val);

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0xFFFFFFFF;
  to_write = 0;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(to_write, val);

  EMC_USB_CELENO_port_hook_disable_hs_pm();

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0;
  to_write = 0xFFFFFFFF;
  masked = 0xE00BFFFF;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(masked, val);

  registers[reg_ofs/sizeof(emc_std_uint32_t)] = 0xFFFFFFFF;
  to_write = 0;
  masked = 0x1FF40000;
  val = 0;
  EMC_HW_Port_write32(&port, base + reg_ofs, to_write);
  EMC_HW_Port_read32(&port, base + reg_ofs, &val);
  EMC_CUNIT_ASSERT_EQUAL(masked, val);
}
EMC_CUNIT_END_TEST

// clang-format on

EMC_CUNIT_TEST_SUITE(PortHook_test);

EMC_CUNIT_TEST(PortHook_test_ss_pm_disable);
EMC_CUNIT_TEST(PortHook_test_hs_pm_disable_dcfg);
EMC_CUNIT_TEST(PortHook_test_hs_pm_disable_dctl);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(PortHook_test)

EMC_TEST_SUITE_DEFINE_MAIN()
