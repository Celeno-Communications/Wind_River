/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/test/SimpleTest.h>
#include <emc/std/errno.h>
#include <emc/std/limits.h>
#include <emc/std/setjmp.h>
#include <emc/std/signal.h>
#include <emc/std/stdlib.h>

typedef int EmcStdlibAtexitTest;

static int setUp(EmcStdlibAtexitTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcStdlibAtexitTest* context) { UNUSED_PARAM(context); return 1; }

static int     test_atexit__signal_count;
static jmp_buf test_atexit__jmpbuf;

static void test_atexit__my_handler_1(void)
{
  ++test_atexit__signal_count;
  longjmp(test_atexit__jmpbuf, 1);
}

static void test_atexit__my_handler_2(void)
{
  ++test_atexit__signal_count;
}

static int test_atexit(EmcStdlibAtexitTest* context)
{
  int error = 0;
  UNUSED_PARAM(context);
  test_atexit__signal_count = 0;

  error = emc_std_atexit(&test_atexit__my_handler_1);
  if (error != 0) {
    return 0;
  }
  error = emc_std_atexit(&test_atexit__my_handler_2);
  if (error != 0) {
    return 0;
  }
  if (!setjmp(test_atexit__jmpbuf)) {
    emc_std_exit(1);
  }
  if (2 != test_atexit__signal_count) {
    return 0;
  }

  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcStdlibAtexitTest, test_atexit);
  return fail_count;
}
