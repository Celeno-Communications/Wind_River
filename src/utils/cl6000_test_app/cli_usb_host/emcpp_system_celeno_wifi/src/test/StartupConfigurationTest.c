/** Copyright (C) 2021 emsys Embedded Systems GmbH */
#include "emc/test/unittest.h"
#include "emc/std/string.h"

#include "emc/system/celeno/device/bootloader/StartupConfiguration.h"

static emc_std_uint32_t mg_section[3] = {0};

void setUp(void)
{
  emc_bootrom_cfg_init(mg_section);
}

void tearDown(void)
{}

void init_valid_signature()
{
  mg_section[1] = ('l' << 24) + ('e' << 16) + ('c' << 8) + '*';
  mg_section[2] = ('*' << 24) + ('o' << 16) + ('n' << 8) + 'e';
}

// clang-format off

EMC_CUNIT_START_TEST(StartupConfigurationTest_invalid)
{
  emc_std_memset(mg_section, 0, sizeof(mg_section));
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 0);

  emc_std_memset(mg_section, 0xFF, sizeof(mg_section));
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 0);

  emc_std_memset(mg_section, 0x01, sizeof(mg_section));
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 0);

}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(StartupConfigurationTest_invalid_string)
{
  mg_section[0] = 56;
  init_valid_signature();
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 56);

  init_valid_signature();
  mg_section[1] = (mg_section[1] & 0xFFFFFF00) + 'l';
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 0);

  init_valid_signature();
  mg_section[2] = (mg_section[1] & 0x00FFFFFF) + ('x' << 24);
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 0);

  init_valid_signature();
  mg_section[1] = (mg_section[1] & 0xFFFFFF00);
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 0);

  init_valid_signature();
  mg_section[2] = (mg_section[1] & 0x00FFFFFF);
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 0);

  init_valid_signature();
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 56);
}
EMC_CUNIT_END_TEST


EMC_CUNIT_START_TEST(StartupConfigurationTest_delay)
{
  emc_std_memset(mg_section, 0, sizeof(mg_section));
  init_valid_signature();
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 0);

  mg_section[0] = 33;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 33);

  mg_section[0] = 100000;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 100000);

  mg_section[0] = 999999;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 999999);

  mg_section[0] = 1000000;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 1000000);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_START_TEST(StartupConfigurationTest_delay_max)
{
  emc_std_memset(mg_section, 0, sizeof(mg_section));
  init_valid_signature();

  mg_section[0] = 1000000;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 1000000);

  mg_section[0] = 1000001;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 1000000);

  mg_section[0] = 0x800000;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 1000000);

  mg_section[0] = 0xFFFFFFE;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 1000000);

  mg_section[0] = 0xFFFFFFF;
  EMC_CUNIT_ASSERT(emc_bootrom_cfg_startup_delay_us() == 1000000);
}
EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(StartupConfigurationTest);
EMC_CUNIT_TEST(StartupConfigurationTest_invalid);
EMC_CUNIT_TEST(StartupConfigurationTest_delay);
EMC_CUNIT_TEST(StartupConfigurationTest_delay_max);
EMC_CUNIT_TEST(StartupConfigurationTest_invalid_string);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(StartupConfigurationTest)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on
