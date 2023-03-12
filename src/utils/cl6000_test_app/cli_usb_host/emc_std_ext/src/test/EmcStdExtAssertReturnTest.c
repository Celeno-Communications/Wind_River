/* Copyright (C) 2016 emsys Embedded Systems GmbH */

#include "emc/std/stdlib.h"
#include "emc/std/ext/assert_ext.h"
#include "emc/std/string.h"
#include "emc/std/limits.h"
#include "emc/test/SimpleTest.h"

#include <stdio.h>

typedef int EmcStdExtAssertReturnTest;

static int setUp(EmcStdExtAssertReturnTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcStdExtAssertReturnTest* context) { UNUSED_PARAM(context); return 1; }

static int test_func_finalized = 0;

static void test_func()
{
  test_func_finalized = 0;
  assert_return(1);
  test_func_finalized = 1;
}

static int test_fail_func_finalized = 0;

static void test_fail_func()
{
  test_fail_func_finalized = 0;
  assert_return(0);
  test_fail_func_finalized = 1;
}

static int test_assert_return(EmcStdExtAssertReturnTest* context)
{
  UNUSED_PARAM(context);

  test_func();
  if (!test_func_finalized) {
    return 0;
  }
  test_fail_func();
  if (test_fail_func_finalized) {
    return 0;
  }
  return 1;
}

static int test_val_func()
{
  assert_return_val(1, 1);
  return 0;
}

static int test_fail_val_func()
{
  assert_return_val(0, 1);
  return 0;
}

static int test_assert_return_val(EmcStdExtAssertReturnTest* context)
{
  int error;
  UNUSED_PARAM(context);

  error = test_val_func();
  if (error) {
    return 0;
  }

  error = test_fail_val_func();
  if (!error) {
    return 0;
  }

  return 1;

  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;

  UNUSED_PARAM(argc); UNUSED_PARAM(argv);

  EMC_SIMPLE_TEST(EmcStdExtAssertReturnTest, test_assert_return);
  EMC_SIMPLE_TEST(EmcStdExtAssertReturnTest, test_assert_return_val);

  return fail_count;
}
