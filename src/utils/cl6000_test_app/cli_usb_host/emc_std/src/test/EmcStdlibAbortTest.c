/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/test/SimpleTest.h>
#include <emc/std/errno.h>
#include <emc/std/limits.h>
#include <emc/std/setjmp.h>
#include <emc/std/signal.h>
#include <emc/std/stdlib.h>

typedef int EmcStdlibAbortTest;

static int setUp(EmcStdlibAbortTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcStdlibAbortTest* context) { UNUSED_PARAM(context); return 1; }

static int     test_abort__signal_count;
static int     test_abort__reported_signal;
static jmp_buf test_abort__jmpbuf;
static void test_abort__my_handler(int sig)
{
  ++test_abort__signal_count;
  test_abort__reported_signal = sig;
  longjmp(test_abort__jmpbuf, 1);
}

static int test_abort(EmcStdlibAbortTest* context)
{
  void (* prev_handler)(int);
  UNUSED_PARAM(context);
  test_abort__signal_count = 0;
  test_abort__reported_signal = EMC_STD_SIGABRT + 123;
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, &test_abort__my_handler);
  if (prev_handler == EMC_STD_SIG_ERR) {
    return 0;
  }
  if (!setjmp(test_abort__jmpbuf)) {
    emc_std_abort();
  }
  if (1 != test_abort__signal_count) {
    return 0;
  }
  if (EMC_STD_SIGABRT != test_abort__reported_signal) {
    return 0;
  }
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, prev_handler);
  /* "When a signal occurs ... it is implementation-defined whether
     the equivalent of signal(sig, SIG_DFL); is executed" */
  if ((&test_abort__my_handler != prev_handler) && (EMC_STD_SIG_DFL != prev_handler)) {
    return 0;
  }
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcStdlibAbortTest, test_abort);
  return fail_count;
}
