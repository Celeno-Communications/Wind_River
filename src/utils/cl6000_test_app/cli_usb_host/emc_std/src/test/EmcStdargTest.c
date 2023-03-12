/** @file
    @brief Test suite for the stdarg.h macros.
    Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include "emc/std/stdarg.h"
#include "emc/test/unittest.h"

static void setUp(void) {}

static void tearDown(void) {}

static int sum(int a1, ...)
{
  int             loop_limit = 20;
  int             result = 0;
  int             i = a1;
  emc_std_va_list ap;
  emc_std_va_start(ap, a1);
  while (i != -1 && --loop_limit) {
    result = result + i;
    i = emc_std_va_arg(ap, int);
  }
  emc_std_va_end(ap);
  return result;
}

EMC_CUNIT_START_TEST(test_stdarg_va_arg_integers) {
  EMC_CUNIT_ASSERT(sum(1, -1) == 1);
  EMC_CUNIT_ASSERT(sum(1, 2, 3, -1) == 6);
  EMC_CUNIT_ASSERT(sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1) == 10 * 11 / 2);
}
EMC_CUNIT_END_TEST

static void copy_ints(int* dest, ...)
{
  int             loop_limit = 10;
  int*            d = dest;
  emc_std_va_list ap;
  emc_std_va_start(ap, dest);
  while (d && --loop_limit) {
    int s = emc_std_va_arg(ap, int);
    *d = s;
    d = emc_std_va_arg(ap, int*);
  }
  emc_std_va_end(ap);
}

EMC_CUNIT_START_TEST(test_stdarg_va_arg_pointers) {
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  copy_ints(&v2, v1, &v3, v2, &v1, v3, (int*)0);
  EMC_CUNIT_ASSERT(v1 == 3);
  EMC_CUNIT_ASSERT(v2 == 1);
  EMC_CUNIT_ASSERT(v3 == 2);
}
EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(EmcStdargTest);
EMC_CUNIT_TEST(test_stdarg_va_arg_integers);
EMC_CUNIT_TEST(test_stdarg_va_arg_pointers);
EMC_CUNIT_TEST_SUITE_END()
EMC_CUNIT_TEST_SUITE_REGISTRATION(EmcStdargTest)
EMC_TEST_SUITE_DEFINE_MAIN()
