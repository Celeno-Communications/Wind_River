#ifndef EMC_TEST_CUNIT_CUnit_H
#  define EMC_TEST_CUNIT_CUnit_H

#  include "emc/test/CUnit/Asserter.h"
#  include <stdio.h>
#  include <emc/log/log.h>

#  define EMC_CUNIT_START_TEST(T) static void T(void)

#  define EMC_CUNIT_END_TEST

void EMC_UNITTEST_add_tests(void);

/* @todo Add setUp() and tearDown() as macro parameters */
#  define EMC_CUNIT_TEST_SUITE(SUITE)                   \
  static int EMC_UNITTEST_setUp(void) {setUp(); return 0;} \
                                                      \
  static int EMC_UNITTEST_tearDown(void) {tearDown(); return 0;} \
                                                      \
  void EMC_UNITTEST_add_tests(void)                   \
  {                                                   \
    CU_pSuite pSuite;                                 \
    pSuite = CU_add_suite(# SUITE, EMC_UNITTEST_setUp, EMC_UNITTEST_tearDown)

#  define EMC_CUNIT_TEST(TEST)                          \
  CU_add_test(pSuite, # TEST, TEST)

#  define EMC_CUNIT_TEST_SUITE_END()                    \
  }

#  define EMC_CUNIT_TEST_SUITE_REGISTRATION(SUITE)

#  define EMC_CUNIT_TEST_SUITE_INSTANTIATION() EMC_UNITTEST_add_tests()

int CUnitTestRunnerMain(int argc, char* argv[]);

#  define EMC_TEST_RUNNER_MAIN CUnitTestRunnerMain

#endif /* EMC_TEST_CUNIT_CUnit_H */
