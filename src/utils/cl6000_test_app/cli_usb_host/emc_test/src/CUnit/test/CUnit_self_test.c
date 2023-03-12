/**
 * @file
 * @brief   CUinit self unit tests.
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/test/unittest.h"
#include "emc/std/string.h"

void setUp(void)
{}

void tearDown(void)
{}

EMC_CUNIT_START_TEST(CUnit_self_test_assert_true) {
  int value = 1;
  EMC_CUNIT_ASSERT(value > 0);
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(CUnit_self_test);

EMC_CUNIT_TEST(CUnit_self_test_assert_true);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(CUnit_self_test)

EMC_TEST_SUITE_DEFINE_MAIN()
