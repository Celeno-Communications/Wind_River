/** Copyright (C) 2021 emsys Embedded Systems GmbH */
#include "emc/test/unittest.h"
#include "emc/vendor/celeno/device/Ipc.h"

void setUp(void)
{}

void tearDown(void)
{}

// clang-format off

EMC_CUNIT_START_TEST(IpcMockTest_read_write_test)
{
  EMC_CELENO_trigger_umac2lmac_interrupt(0x55);
  EMC_CUNIT_ASSERT_EQUAL(0x55U, EMC_CELENO_trigger_umac2lmac_status_value());
}
EMC_CUNIT_END_TEST

EMC_CUNIT_TEST_SUITE(IpcMockTest);
EMC_CUNIT_TEST(IpcMockTest_read_write_test);
EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(IpcMockTest)

EMC_TEST_SUITE_DEFINE_MAIN()

// clang-format on
