/* Copyright (C) 2016 emsys Embedded Systems GmbH */

#include "emc/std/stdlib.h"
#include "emc/std/ext/stdlib.h"
#include "emc/std/string.h"
#include "emc/std/limits.h"
#include <emc/std/stdint.h>
#include <emc/std/ext/memcpy.h>
#include "emc/test/SimpleTest.h"

#include <stdio.h>

typedef int EmcStdextTest;

static int setUp(EmcStdextTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcStdextTest* context) { UNUSED_PARAM(context); return 1; }

static int test_uitoa_base_invalid(EmcStdextTest* context)
{
  char str[32];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("", (emc_std_itoa)(0, str, 1))) {
    return 0;
  }
  if (0 != emc_std_strcmp("", (emc_std_itoa)(0, str, 37))) {
    return 0;
  }

  if (0 != emc_std_strcmp("", (emc_std_utoa)(0, str, 1))) {
    return 0;
  }
  if (0 != emc_std_strcmp("", (emc_std_utoa)(0, str, 37))) {
    return 0;
  }

  return 1;
}

static int test_itoa_base_10(EmcStdextTest* context)
{
  char str[32];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("0", (emc_std_itoa)(0, str, 10))) {
    return 0;
  }

  if (0 != emc_std_strcmp("1", (emc_std_itoa)(1, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("-1", (emc_std_itoa)(-1, str, 10))) {
    return 0;
  }

  if (0 != emc_std_strcmp("16", (emc_std_itoa)(16, str, 10))) {
    return 0;
  }

  if (0 != emc_std_strcmp("2147483647", (emc_std_itoa)(EMC_STD_INT_MAX, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("-2147483648", (emc_std_itoa)(EMC_STD_INT_MIN, str, 10))) {
    return 0;
  }

  return 1;
}

static int test_litoa_base_10(EmcStdextTest* context)
{
  char str[32];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("0", (emc_std_litoa)(0, str, 10))) {
    return 0;
  }

  if (0 != emc_std_strcmp("1", (emc_std_litoa)(1, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("-1", (emc_std_litoa)(-1, str, 10))) {
    return 0;
  }

  if (0 != emc_std_strcmp("16", (emc_std_litoa)(16, str, 10))) {
    return 0;
  }

  return 1;
}

static int test_utoa_base_10(EmcStdextTest* context)
{
  char str[32];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("0", (emc_std_utoa)(0, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("1", (emc_std_utoa)(1, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("16", (emc_std_utoa)(16, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("4294967295", (emc_std_utoa)(0xFFFFFFFF, str, 10))) {
    return 0;
  }

  return 1;
}

static int test_lutoa_base_10(EmcStdextTest* context)
{
  char str[32];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("0", (emc_std_lutoa)(0, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("1", (emc_std_lutoa)(1, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("16", (emc_std_lutoa)(16, str, 10))) {
    return 0;
  }
  if (0 != emc_std_strcmp("4294967295", (emc_std_lutoa)(0xFFFFFFFF, str, 10))) {
    return 0;
  }

  return 1;
}

static int test_itoa_base_2(EmcStdextTest* context)
{
  char str[33];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("0", (emc_std_itoa)(0, str, 2))) {
    return 0;
  }

  if (0 != emc_std_strcmp("1", (emc_std_itoa)(1, str, 2))) {
    return 0;
  }
  if (0 != emc_std_strcmp("11111111111111111111111111111111", emc_std_itoa(-1, str, 2))) {
    return 0;
  }
  if (0 != emc_std_strcmp("10000", (emc_std_itoa)(16, str, 2))) {
    return 0;
  }
  if (0 != emc_std_strcmp("1111111111111111111111111111111",
                          (emc_std_itoa)(EMC_STD_INT_MAX, str, 2)))
  {
    return 0;
  }
  return 1;
}

static int test_utoa_base_2(EmcStdextTest* context)
{
  char str[33];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("0", (emc_std_utoa)(0, str, 2))) {
    return 0;
  }
  if (0 != emc_std_strcmp("1", (emc_std_utoa)(1, str, 2))) {
    return 0;
  }
  if (0 != emc_std_strcmp("10000", (emc_std_utoa)(16, str, 2))) {
    return 0;
  }
  if (0 != emc_std_strcmp("11111111111111111111111111111111",
                          (emc_std_utoa)(0xFFFFFFFF, str, 2)))
  {
    return 0;
  }

  return 1;
}

static int test_itoa_base_16(EmcStdextTest* context)
{
  char str[32];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("0", (emc_std_itoa)(0, str, 16))) {
    return 0;
  }

  if (0 != emc_std_strcmp("1", (emc_std_itoa)(1, str, 16))) {
    return 0;
  }
  if (0 != emc_std_strcmp("FFFFFFFF", (emc_std_itoa)(-1, str, 16))) {
    return 0;
  }

  if (0 != emc_std_strcmp("10", (emc_std_itoa)(16, str, 16))) {
    return 0;
  }

  if (0 != emc_std_strcmp("7FFFFFFF", (emc_std_itoa)(EMC_STD_INT_MAX, str, 16))) {
    return 0;
  }
  if (0 != emc_std_strcmp("80000000", (emc_std_itoa)(EMC_STD_INT_MIN, str, 16))) {
    return 0;
  }

  return 1;
}

static int test_utoa_base_16(EmcStdextTest* context)
{
  char str[32];

  UNUSED_PARAM(context);

  if (0 != emc_std_strcmp("0", (emc_std_utoa)(0, str, 16))) {
    return 0;
  }
  if (0 != emc_std_strcmp("1", (emc_std_utoa)(1, str, 16))) {
    return 0;
  }
  if (0 != emc_std_strcmp("10", (emc_std_utoa)(16, str, 16))) {
    return 0;
  }
  if (0 != emc_std_strcmp("FFFFFFFF", (emc_std_utoa)(0xFFFFFFFF, str, 16))) {
    return 0;
  }

  return 1;
}

static int test_ext_memcpy(EmcStdextTest* context)
{

  const emc_std_uint8_t data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  UNUSED_PARAM(context);

  for (emc_std_size_t offset = 4; offset < 32; offset++) {
    emc_std_uint8_t buffer[100] = { 0 };
    if ((buffer + offset) != (emc_std_ext_memcpy)(buffer + offset, data, sizeof(data))) {
      return 0;
    }
    for (emc_std_size_t i = 0; i < offset; i++) {
      if (0 != buffer[i]) {
        return 0;
      }
    }
    for (emc_std_size_t i = offset + sizeof(data); i < sizeof(buffer); i++) {
      if (0 != buffer[i]) {
        return 0;
      }
    }
    for (emc_std_size_t i = 0; i < sizeof(data); i++) {
      if (data[i] != buffer[offset + i]) {
        return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;

  UNUSED_PARAM(argc); UNUSED_PARAM(argv);

  EMC_SIMPLE_TEST(EmcStdextTest, test_uitoa_base_invalid);
  EMC_SIMPLE_TEST(EmcStdextTest, test_itoa_base_10);
  EMC_SIMPLE_TEST(EmcStdextTest, test_utoa_base_10);
  EMC_SIMPLE_TEST(EmcStdextTest, test_litoa_base_10);
  EMC_SIMPLE_TEST(EmcStdextTest, test_lutoa_base_10);
  EMC_SIMPLE_TEST(EmcStdextTest, test_itoa_base_2);
  EMC_SIMPLE_TEST(EmcStdextTest, test_utoa_base_2);
  EMC_SIMPLE_TEST(EmcStdextTest, test_itoa_base_16);
  EMC_SIMPLE_TEST(EmcStdextTest, test_utoa_base_16);
  EMC_SIMPLE_TEST(EmcStdextTest, test_ext_memcpy);

  return fail_count;
}
