/* Copyright (C) 2011 emsys Embedded Systems GmbH */

#include "emc/test/SimpleTest.h"

typedef int CompilerConfigureTest;

static int setUp(CompilerConfigureTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(CompilerConfigureTest* context) { UNUSED_PARAM(context); return 1; }

static int test_func_value(CompilerConfigureTest* context)
{
  const char* my_name = __func__;
  UNUSED_PARAM(context);
  /* emc_config_compiler_test_function(); */ /* for coverage */

  if (!my_name) {
    return 0;
  }
  if (!my_name[0]) {
    return 0;
  }

  if (('?' != my_name[0]) || (0 != my_name[1])) { /* It's not just "?" */
    if ('t' != my_name[0]) {
      return 0;
    }
    if ('e' != my_name[1]) {
      return 0;
    }
    if ('s' != my_name[2]) {
      return 0;
    }
    if ('t' != my_name[3]) {
      return 0;
    }
    if ('_' != my_name[4]) {
      return 0;
    }
    if ('f' != my_name[5]) {
      return 0;
    }
    if ('u' != my_name[6]) {
      return 0;
    }
    if ('n' != my_name[7]) {
      return 0;
    }
    if ('c' != my_name[8]) {
      return 0;
    }
    if ('_' != my_name[9]) {
      return 0;
    }
    if ('v' != my_name[10]) {
      return 0;
    }
    if ('a' != my_name[11]) {
      return 0;
    }
    if ('l' != my_name[12]) {
      return 0;
    }
    if ('u' != my_name[13]) {
      return 0;
    }
    if ('e' != my_name[14]) {
      return 0;
    }
    if ('\0' != my_name[15]) {
      return 0;
    }
  }

  return 1;
}

static int test_func_sizeof(CompilerConfigureTest* context)
{
  UNUSED_PARAM(context);
  /* It must behave like a character array, not a pointer */
  if (sizeof(__func__) == sizeof(const char*)) {
    return 0;
  }
  return 1;
}

int main(void)
{
  int fail_count = 0;
  EMC_SIMPLE_TEST(CompilerConfigureTest, test_func_value);
  EMC_SIMPLE_TEST(CompilerConfigureTest, test_func_sizeof);
  return fail_count;
}
