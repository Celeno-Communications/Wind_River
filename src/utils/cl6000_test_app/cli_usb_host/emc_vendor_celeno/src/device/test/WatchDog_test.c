/**
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/test/unittest.h"
#include "emc/system/Watchdog.h"

void setUp(void)
{}

void tearDown(void)
{}

// clang-format off
extern emc_std_uint32_t wd_time;
extern emc_std_uint32_t wd_en ;
extern emc_std_uint32_t wd_time_dyn ;

EMC_CUNIT_START_TEST(WatchDog_test) {

  EMC_Watchdog_set_timeout(259);
  EMC_Watchdog_enable(emc_std_true);

  EMC_CUNIT_ASSERT_EQUAL(0x6, wd_time);
  EMC_CUNIT_ASSERT_EQUAL(0x1, wd_en);

  EMC_Watchdog_keepalive();
  EMC_CUNIT_ASSERT_EQUAL(0x6*50, EMC_Watchdog_timeleft());

  EMC_Watchdog_emulation();
}
EMC_CUNIT_END_TEST

// clang-format on

EMC_CUNIT_TEST_SUITE(WatchDog_test);

EMC_CUNIT_TEST(WatchDog_test);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(WatchDog_test)

EMC_TEST_SUITE_DEFINE_MAIN()
