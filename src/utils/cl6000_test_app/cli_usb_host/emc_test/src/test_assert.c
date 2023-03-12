#include "emc/test/test_assert.h"
#include <stdio.h>
#include <emc/std/stdlib.h>

void emc_test_assert_fail(const char* assertion,
                          const char* file_name,
                          unsigned int line,
                          const char* function_name)
{
  fprintf(stderr, "%s (%d) test assertion %s failed in %s()\n",
          file_name, line, assertion, function_name ? function_name : "");
  emc_std_abort();
}
