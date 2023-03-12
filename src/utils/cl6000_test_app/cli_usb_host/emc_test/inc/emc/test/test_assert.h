#ifndef EMC_TEST_test_assert_H
#define EMC_TEST_test_assert_H

#include "emc/config/configure.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

void emc_test_assert_fail(const char* assertion,
                          const char* file_name,
                          unsigned int line,
                          const char* function_name);

#define EMC_TEST_ASSERT(expression) \
  do { if (!(expression)) {                                              \
      emc_test_assert_fail(# expression, __FILE__, __LINE__, __func__); \
    }} /*lint --e(717) */ while (0)

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif
