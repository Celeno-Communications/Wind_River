/**
 * @file
 * @brief   The emc specific main for CUnit based tests.
 * This is a minimal version for command line.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 * Copyright (C) 2005-2013 emsys Embedded Systems GmbH
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Basic.h"
#include "emc/test/CUnit/CUnit.h"

void EMC_UNITTEST_add_tests(void);

#ifndef EMC_CUNIT_TEST_SUITE_INSTANTIATION
#  define EMC_CUNIT_TEST_SUITE_INSTANTIATION() EMC_UNITTEST_add_tests()
#endif

int CUnitTestRunnerMain(int argc, char* argv[])
{
  CU_BasicRunMode mode = CU_BRM_SILENT;
  CU_ErrorAction  on_error = CUEA_IGNORE;
  int             result = 0;
  int             i;

  setvbuf(stdout, NULL, _IONBF, 0);

  for (i = 1; i < argc; ++i) {
    if (!strcmp("-v", argv[i])) {
      mode = CU_BRM_VERBOSE;
    } else {
      printf("\nUsage:  BasicTest [options]\n"
             "Options:  -v   verbose mode - max output to screen\n"
             "          -h   print this message and exit.\n");
      return 0;
    }
  }

  if (CU_initialize_registry()) {
    printf("\nInitialization of Test Registry failed.");
  } else {
    EMC_CUNIT_TEST_SUITE_INSTANTIATION();

    CU_basic_set_mode(mode);
    CU_set_error_action(on_error);
    CU_basic_run_tests();

    result = CU_get_number_of_tests_failed();

    CU_cleanup_registry();
  }

  return result;
}
