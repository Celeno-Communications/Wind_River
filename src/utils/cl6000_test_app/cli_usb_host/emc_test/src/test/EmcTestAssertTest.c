/* Copyright (C) 2018 emsys Embedded Systems GmbH */

#include <emc/test/SimpleTest.h>
#include <emc/test/test_assert.h>
#include <emc/std/errno.h>
#include <emc/std/limits.h>
#include <emc/std/setjmp.h>
#include <emc/std/signal.h>
#include <emc/std/stdlib.h>

typedef int EmcTestAssertTest;

static int setUp(EmcTestAssertTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcTestAssertTest* context) { UNUSED_PARAM(context); return 1; }

static int     test_assert__signal_count;
static int     test_assert__reported_signal;
static jmp_buf test_assert__jmpbuf;

static void test_assert__my_handler(int sig)
{
  ++test_assert__signal_count;
  test_assert__reported_signal = sig;
  longjmp(test_assert__jmpbuf, 1);
}

static int test_assert(EmcTestAssertTest* context)
{
  void (* prev_handler)(int);
  UNUSED_PARAM(context);
  test_assert__signal_count = 0;
  test_assert__reported_signal = EMC_STD_SIGABRT + 123;
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, &test_assert__my_handler);
  if (prev_handler == EMC_STD_SIG_ERR) {
    return 0;
  }

  if (!setjmp(test_assert__jmpbuf)) {
    EMC_TEST_ASSERT(0);
  }
  if (1 != test_assert__signal_count) {
    return 0;
  }
  if (EMC_STD_SIGABRT != test_assert__reported_signal) {
    return 0;
  }
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, prev_handler);
  /* "When a signal occurs ... it is implementation-defined whether
     the equivalent of signal(sig, SIG_DFL); is executed" */
  if ((&test_assert__my_handler != prev_handler) && (EMC_STD_SIG_DFL != prev_handler)) {
    return 0;
  }
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcTestAssertTest, test_assert);
  return fail_count;
}
