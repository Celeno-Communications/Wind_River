/// Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
#include "emc/hw/memory/test/BaseTest.hpp"

#include <signal.h>
#include <stdio.h>

namespace emcpp {

  int     BaseTest::signal_count = 0;
  int     BaseTest::reported_signal = 0;
  jmp_buf BaseTest::jmpbuf;

  bool BaseTest::did_abort() const
  {
    if (1 != signal_count) {
      return false;
    }
    if ((SIGABRT != reported_signal) && (SIGSEGV != reported_signal)) {
      return false;
    }

    return true;
  }

  void BaseTest::abort_handler(int sig)
  {
    ++signal_count;
    reported_signal = sig;
    longjmp(jmpbuf, 1);
  }

  void BaseTest::setUp()
  {
    signal_count = 0;
    reported_signal = SIGABRT + 123;
    _prev_handler = signal(SIGABRT, &abort_handler);
    signal(SIGSEGV, &abort_handler);
    if (_prev_handler == SIG_ERR) {
      EMCPP_TEST_ASSERT(0);
    }
  }

  void BaseTest::tearDown()
  {
    _prev_handler = signal(SIGABRT, _prev_handler);
    /* "When a signal occurs ... it is implementation-defined whether
       the equivalent of signal(sig, SIG_DFL); is executed" */
    signal(SIGSEGV, SIG_DFL);
    if ((&abort_handler != _prev_handler) && (SIG_DFL != _prev_handler)) {
      EMCPP_TEST_ASSERT(0);
    }
  }

} // namespace
