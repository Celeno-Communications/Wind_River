/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/std/errno.h>
#include <emc/std/limits.h>

#ifdef EMC_STD_stdlib_H
#  error Invalid include order
#endif
#include <emc/std/stdlib.h>
#include <emc/test/SimpleTest.h>

typedef int EmcStdlibAtoiTest;

static int setUp(EmcStdlibAtoiTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcStdlibAtoiTest* context) { UNUSED_PARAM(context); return 1; }

static int test_atoi(EmcStdlibAtoiTest* context)
{
  UNUSED_PARAM(context);

#if -2147483647 == EMC_STD_LONG_MIN
#  error LONG_MIN valid but unexpected. Please check the test code.
#endif

  emc_std_errno = 0;
  if (0 != (emc_std_atoi)("0")) {
    return 0;
  }
  if (1 != (emc_std_atoi)("1")) {
    return 0;
  }
  if (9 != (emc_std_atoi)("9")) {
    return 0;
  }
  if (10 != (emc_std_atoi)("10")) {
    return 0;
  }
  if (12 != (emc_std_atoi)("12")) {
    return 0;
  }
  if (0 != (emc_std_atoi)("-0")) {
    return 0;
  }
  if (-1 != (emc_std_atoi)("-1")) {
    return 0;
  }
  if (-10 != (emc_std_atoi)("-10")) {
    return 0;
  }
  if (-12 != (emc_std_atoi)("-12")) {
    return 0;
  }
  if (2 != (emc_std_atoi)(" \f\n\r\t\v 2")) {
    return 0;
  }
  if (-3 != (emc_std_atoi)("   -000000000000003::::aaa")) {
    return 0;
  }
  if (0 != emc_std_errno) {
    return 0;
  }

  if (4 == sizeof(int)) {
    if (2147483639 != (emc_std_atoi)("2147483639")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (2147483640 != (emc_std_atoi)("2147483640")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (2147483647 != (emc_std_atoi)("2147483647")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-2147483639 != (emc_std_atoi)("-2147483639")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-2147483640 != (emc_std_atoi)("-2147483640")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-2147483647 != (emc_std_atoi)("-2147483647")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-2147483647 - 1 != (emc_std_atoi)("-2147483648")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }

    if (4 == sizeof(long)) {
      if ((int)EMC_STD_LONG_MAX != (emc_std_atoi)("2147483648")) {
        return 0;
      }
      if (0 != emc_std_errno) {
        if (EMC_STD_ERANGE != emc_std_errno) {
          return 0;
        }
        emc_std_errno = 0;
      }
      if ((int)EMC_STD_LONG_MAX != (emc_std_atoi)("2147483650")) {
        return 0;
      }
      if (0 != emc_std_errno) {
        if (EMC_STD_ERANGE != emc_std_errno) {
          return 0;
        }
        emc_std_errno = 0;
      }
      if ((int)EMC_STD_LONG_MAX != (emc_std_atoi)("2147483659")) {
        return 0;
      }
      if (0 != emc_std_errno) {
        if (EMC_STD_ERANGE != emc_std_errno) {
          return 0;
        }
        emc_std_errno = 0;
      }
      if ((int)EMC_STD_LONG_MIN != (emc_std_atoi)("-2147483649")) {
        return 0;
      }
      if (0 != emc_std_errno) {
        if (EMC_STD_ERANGE != emc_std_errno) {
          return 0;
        }
        emc_std_errno = 0;
      }
      if ((int)EMC_STD_LONG_MIN != (emc_std_atoi)("-2147483650")) {
        return 0;
      }
      if (0 != emc_std_errno) {
        if (EMC_STD_ERANGE != emc_std_errno) {
          return 0;
        }
        emc_std_errno = 0;
      }
      if ((int)EMC_STD_LONG_MIN != (emc_std_atoi)("-2147483659")) {
        return 0;
      }
      if (0 != emc_std_errno) {
        if (EMC_STD_ERANGE != emc_std_errno) {
          return 0;
        }
        emc_std_errno = 0;
      }
    }
    if ((int)EMC_STD_LONG_MAX != (emc_std_atoi)("9223372036854775808")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if ((int)EMC_STD_LONG_MAX != (emc_std_atoi)("9999999999999999999")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if ((int)EMC_STD_LONG_MIN != (emc_std_atoi)("-9223372036854775808")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if ((int)EMC_STD_LONG_MIN != (emc_std_atoi)("-9999999999999999999")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
#if EMC_STD_LONG_MAX > EMC_STD_INT_MAX
  } else if (8 == sizeof(long)) {
    emc_std_errno = 0;
    if (9223372036854775799L != emc_std_atol("9223372036854775799")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (9223372036854775800L != emc_std_atol("9223372036854775800")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (9223372036854775801L != emc_std_atol("9223372036854775801")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (9223372036854775807L != emc_std_atol("9223372036854775807")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (9223372036854775807L != emc_std_atol("9223372036854775808")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (9223372036854775807L != emc_std_atol("9223372036854775810")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (9223372036854775807L != emc_std_atol("9223372036854775819")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (-9223372036854775799L != emc_std_atol("-9223372036854775799")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-9223372036854775800L != emc_std_atol("-9223372036854775800")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-9223372036854775807L != emc_std_atol("-9223372036854775807")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }

    if (EMC_STD_LONG_MIN != emc_std_atol("-9223372036854775808")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }

    if (EMC_STD_LONG_MIN != emc_std_atol("-9223372036854775810")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (EMC_STD_LONG_MIN != emc_std_atol("-9223372036854775819")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
#endif /* LONG > INT */
  } else {

    /* This test must be extended */
    return 0;

  }

  return 1;
}

static int test_atol(EmcStdlibAtoiTest* context)
{
  UNUSED_PARAM(context);

#if -2147483647 == EMC_STD_LONG_MIN
#  error LONG_MIN valid but unexpected. Please check the test code.
#endif

  emc_std_errno = 0;
  if (0L != emc_std_atol("0")) {
    return 0;
  }
  if (1L != emc_std_atol("1")) {
    return 0;
  }
  if (9L != emc_std_atol("9")) {
    return 0;
  }
  if (10L != emc_std_atol("10")) {
    return 0;
  }
  if (12L != emc_std_atol("12")) {
    return 0;
  }
  if (0L != emc_std_atol("-0")) {
    return 0;
  }
  if (-1L != emc_std_atol("-1")) {
    return 0;
  }
  if (-10L != emc_std_atol("-10")) {
    return 0;
  }
  if (-12L != emc_std_atol("-12")) {
    return 0;
  }
  if (2L != emc_std_atol(" \f\n\r\t\v 2")) {
    return 0;
  }
  if (-3L != emc_std_atol("   -000000000000003::::aaa")) {
    return 0;
  }
  if (0 != emc_std_errno) {
    return 0;
  }

  if (4 == sizeof(long)) {
    emc_std_errno = 0;
    if (2147483639L != emc_std_atol("2147483639")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (2147483640L != emc_std_atol("2147483640")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (2147483647L != emc_std_atol("2147483647")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (2147483647L != emc_std_atol("2147483648")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (2147483647L != emc_std_atol("2147483650")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (2147483647L != emc_std_atol("2147483659")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (-2147483639L != emc_std_atol("-2147483639")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-2147483640L != emc_std_atol("-2147483640")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-2147483647L != emc_std_atol("-2147483647")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }

    if (-2147483647L - 1 != emc_std_atol("-2147483648")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }

    if (EMC_STD_LONG_MIN != emc_std_atol("-2147483650")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (EMC_STD_LONG_MIN != emc_std_atol("-2147483659")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }

#if EMC_STD_LONG_MAX > EMC_STD_INT_MAX
  } else if (8 == sizeof(long)) {
    emc_std_errno = 0;
    if (9223372036854775799L != emc_std_atol("9223372036854775799")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (9223372036854775800L != emc_std_atol("9223372036854775800")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (9223372036854775801L != emc_std_atol("9223372036854775801")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (9223372036854775807L != emc_std_atol("9223372036854775807")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (9223372036854775807L != emc_std_atol("9223372036854775808")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (9223372036854775807L != emc_std_atol("9223372036854775810")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (9223372036854775807L != emc_std_atol("9223372036854775819")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (-9223372036854775799L != emc_std_atol("-9223372036854775799")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-9223372036854775800L != emc_std_atol("-9223372036854775800")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }
    if (-9223372036854775807L != emc_std_atol("-9223372036854775807")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }

    if (EMC_STD_LONG_MIN != emc_std_atol("-9223372036854775808")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      return 0;
    }

    if (EMC_STD_LONG_MIN != emc_std_atol("-9223372036854775810")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
    if (EMC_STD_LONG_MIN != emc_std_atol("-9223372036854775819")) {
      return 0;
    }
    if (0 != emc_std_errno) {
      if (EMC_STD_ERANGE != emc_std_errno) {
        return 0;
      }
      emc_std_errno = 0;
    }
#endif /* LONG > INT */
  } else {

    /* This test must be extended */
    return 0;

  }

  return 1;
}

static int test_abs(EmcStdlibAtoiTest* context)
{
  UNUSED_PARAM(context);

  if (emc_std_abs(-42) != 42) {
    return 0;
  }
  if (emc_std_abs(42) != 42) {
    return 0;
  }
  if (emc_std_abs(0) != 0) {
    return 0;
  }
  if (emc_std_abs(-1) != 1) {
    return 0;
  }
  if (emc_std_abs(1) != 1) {
    return 0;
  }
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcStdlibAtoiTest, test_atoi);
  EMC_SIMPLE_TEST(EmcStdlibAtoiTest, test_atol);
  EMC_SIMPLE_TEST(EmcStdlibAtoiTest, test_abs);
  return fail_count;
}
