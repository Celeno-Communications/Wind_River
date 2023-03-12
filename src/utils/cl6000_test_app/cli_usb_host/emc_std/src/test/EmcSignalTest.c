/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/test/SimpleTest.h>
#include <emc/std/signal.h>
#include <emc/std/setjmp.h>

typedef int EmcSignalTest;

static int setUp(EmcSignalTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcSignalTest* context) { UNUSED_PARAM(context); return 1; }

static void my_noop_handler(int sig) { UNUSED_PARAM(sig); }

static int test_signal(EmcSignalTest* context)
{
  void (* prev_handler)(int);
  UNUSED_PARAM(context);
#if EMC_STD_STDLIB_EMULATE
  /* this is implementation specific, but otherwise the
     internal function will not covered in case of emulation*/
  EMC_STD_SIG_DFL(0);
#endif

  prev_handler = emc_std_signal(EMC_STD_SIGABRT, EMC_STD_SIG_DFL);
  if (prev_handler == EMC_STD_SIG_ERR) {
    return 0;
  }
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, EMC_STD_SIG_DFL);
  if (prev_handler != EMC_STD_SIG_DFL) {
    return 0;
  }
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, &my_noop_handler);
  if (prev_handler != EMC_STD_SIG_DFL) {
    return 0;
  }
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, &my_noop_handler);
  if (prev_handler != &my_noop_handler) {
    return 0;
  }
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, EMC_STD_SIG_DFL);
  if (prev_handler != &my_noop_handler) {
    return 0;
  }
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, EMC_STD_SIG_DFL);
  if (prev_handler != EMC_STD_SIG_DFL) {
    return 0;
  }
  return 1;
}

static int     test_raise_sigabrt__signal_count;
static int     test_raise_sigabrt__reported_signal;
static jmp_buf test_raise_sigabrt__jmpbuf;
static void test_raise_sigabrt__my_handler(int sig)
{
  ++test_raise_sigabrt__signal_count;
  test_raise_sigabrt__reported_signal = sig;
  longjmp(test_raise_sigabrt__jmpbuf, 1);
}

static int test_raise_sigabrt(EmcSignalTest* context)
{
  void (* prev_handler)(int);
  UNUSED_PARAM(context);
  test_raise_sigabrt__signal_count = 0;
  test_raise_sigabrt__reported_signal = EMC_STD_SIGABRT + 123;
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, &test_raise_sigabrt__my_handler);
  if (prev_handler == EMC_STD_SIG_ERR) {
    return 0;
  }
  if (!setjmp(test_raise_sigabrt__jmpbuf)) {
    emc_std_raise(EMC_STD_SIGABRT);
  }
  if (1 != test_raise_sigabrt__signal_count) {
    return 0;
  }
  if (EMC_STD_SIGABRT != test_raise_sigabrt__reported_signal) {
    return 0;
  }
  prev_handler = emc_std_signal(EMC_STD_SIGABRT, prev_handler);
  /* "When a signal occurs ... it is implementation-defined whether
     the equivalent of signal(sig, SIG_DFL); is executed" */
  if ((&test_raise_sigabrt__my_handler != prev_handler) &&
      (EMC_STD_SIG_DFL != prev_handler))
  {
    return 0;
  }
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcSignalTest, test_signal);
  EMC_SIMPLE_TEST(EmcSignalTest, test_raise_sigabrt);
  return fail_count;
}
