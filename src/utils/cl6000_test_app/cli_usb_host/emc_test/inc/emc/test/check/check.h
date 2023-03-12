#ifndef EMC_TEST_CHECK_check_H
#  define EMC_TEST_CHECK_check_H

#  ifdef __GNUC__

#    include </usr/include/check.h>

#  endif

#  include "emc/config/version.h"
#  include <emc/std/symcat.h>

#  define EMC_CUNIT_START_TEST START_TEST

#  define EMC_CUNIT_END_TEST END_TEST

#  define EMC_CUNIT_ASSERT(T) fail_unless(T,# T)

#  define EMC_CUNIT_ASSERT_EQUAL(A, B) fail_unless((A) == (B),       \
                                                   EMC_STR(, A)     \
                                                   " != "          \
                                                   EMC_STR(, B))

#  define EMC_CUNIT_TEST_SUITE(SUITE)                 \
  Suite * SUITE ## _suite(void)                    \
  {                                             \
    Suite* s = suite_create(# SUITE);

#  define EMC_CUNIT_TEST(TEST)                                    \
  {                                                         \
    TCase* tc_case = tcase_create(# TEST);                   \
    suite_add_tcase(s, tc_case);                             \
    tcase_add_checked_fixture(tc_case, setUp, tearDown);     \
    tcase_add_test(tc_case, TEST);                           \
  }                                                         \


#  define EMC_CUNIT_TEST_SUITE_END()                  \
  return s;                                   \
  }

#  define EMC_CUNIT_TEST_SUITE_REGISTRATION(SUITE)

#  define EMC_TEST_RUNNER_MAIN checkTestRunnerMain

#endif /* EMC_TEST_CHECK_check_H */
