/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/test/SimpleTest.h>
#include <emc/std/limits.h>

#if defined(_MSC_VER)
#  pragma warning(disable : 6326)
#endif

typedef int EmcLimitsTest;

static int setUp(EmcLimitsTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcLimitsTest* context) { UNUSED_PARAM(context); return 1; }

static int test_long_min_max(EmcLimitsTest* context)
{
  /* "volatile" avoids integer overflow warnings */
  volatile long long_min = EMC_STD_LONG_MIN;
  volatile long long_max = EMC_STD_LONG_MAX;
  volatile long long_min_decr = long_min - 1;
  volatile long long_max_incr = long_max + 1;
  UNUSED_PARAM(context);
  if (EMC_STD_LONG_MIN > -2147483647L) {
    return 0;
  }
  if (EMC_STD_LONG_MAX < 2147483647L) {
    return 0;
  }
#if EMC_STD_LONG_MIN > -2147483647
  if (1) {
    return 0;
  }
#endif
#if EMC_STD_LONG_MAX < 2147483647
  if (1) {
    return 0;
  }
#endif
  if (long_min_decr < long_min) {
    return 0;
  }
  if (long_max_incr > long_max) {
    return 0;
  }

  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcLimitsTest, test_long_min_max);
  return fail_count;
}
