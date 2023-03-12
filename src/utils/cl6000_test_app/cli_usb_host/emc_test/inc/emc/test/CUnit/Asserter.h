#ifndef EMC_TEST_CUNIT_Asserter_H
#define EMC_TEST_CUNIT_Asserter_H

#include <CUnit.h>
#include "Basic.h"

#define EMC_CUNIT_FAIL CU_FAIL
#define EMC_CUNIT_FAIL_FATAL CU_FAIL_FATAL

#define EMC_CUNIT_ASSERT CU_ASSERT
#define EMC_CUNIT_ASSERT_FATAL CU_ASSERT_FATAL

#define EMC_CUNIT_ASSERT_EQUAL CU_ASSERT_EQUAL

#define EMC_CUNIT_ASSERT_INTERNAL(condition, result)   \
  if (!(condition)) {                                  \
    EMC_CUNIT_FAIL(# condition); \
    result = emc_std_false; \
  }

#endif /* EMC_TEST_CUNIT_Asserter_H */
