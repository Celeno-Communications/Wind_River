/** @file
    @brief Test framework for our fundamental infrastructure.

    This test framework is intended to test our standard library
    emulation with feature-limited C and C++ compilers.

    It does not assume that the compiler supports exceptions or that
    the standard library is already working as expected.

    Copyright (C) 2009-2013 emsys Embedded Systems GmbH */

#ifndef EMC_TEST_SimpleTest_H
#define EMC_TEST_SimpleTest_H

#include "emc/config/configure.h"
#include "emc/std/signal.h"
#include "emc/std/stdio.h"
#include "emc/std/stdlib.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

static void emc_test_simple_signal_handler(int signal)
{
  UNUSED_PARAM(signal);
  emc_std_fputs("program aborted", emc_std_stderr);
  emc_std_exit(-1);
}

/** Run the test_method(Type*) test. */
#define EMC_SIMPLE_TEST(Type, test_method) do {                         \
    Type instance;                                                      \
    emc_std_signal(EMC_STD_SIGABRT, &emc_test_simple_signal_handler);   \
    if (setUp(&instance)                                                \
        && (test_method(&instance) || (tearDown(&instance) && 0))       \
        && tearDown(&instance)) {                                       \
      emc_std_puts("PASS: " EMC_STR(, Type) "::" # test_method);          \
    } else {                                                            \
      ++fail_count;                                                     \
      emc_std_puts("FAIL: " EMC_STR(, Type) "::" # test_method);          \
    }                                                                   \
} while (0)

#ifdef EMCPP_EXCEPTIONS

namespace emcpp {
  class SimpleTest {
  protected:
    bool setUp() { return true; }

    bool tearDown() { return true; }

  };

}

/** Run the Class::test_method() test.  In theory we could implement
   this macro with a template function, but for testing we must
   assume that a compiler might not generate it correctly. */
#  if EMCPP_EXCEPTIONS
#    define EMCPP_SIMPLE_TEST(Class, test_method)                        \
  emc_std_signal(EMC_STD_SIGABRT, &emc_test_simple_signal_handler); \
  do {                                                              \
    bool passed = false;                                            \
    try {                                                           \
      Class instance;                                               \
      if (instance.setUp()) {                                       \
        try {                                                       \
          if (instance.test_method()) {                             \
            passed = true;                                          \
          }                                                         \
        } catch(...) {}                                            \
        if (!instance.tearDown()) { passed = false; }               \
      }                                                             \
    } catch(...) { passed = false; }                               \
    if (passed) {                                                   \
      emc_std_puts("PASS: " EMC_STR(, Class) "::" # test_method);     \
    } else {                                                        \
      ++fail_count;                                                 \
      emc_std_puts("FAIL: " EMC_STR(, Class) "::" # test_method);     \
    }                                                               \
  } while (0)
#  else /** !EMCPP_EXCEPTIONS */
#    define EMCPP_SIMPLE_TEST(Class, test_method)                        \
  emc_std_signal(EMC_STD_SIGABRT, &emc_test_simple_signal_handler); \
  do {                                                              \
    Class instance;                                                 \
    if (instance.setUp()                                            \
        && (instance.test_method() || (instance.tearDown() && false)) \
        && instance.tearDown()) {                                   \
      emc_std_puts("PASS: " EMC_STR(, Class) "::" # test_method);     \
    } else {                                                        \
      ++fail_count;                                                 \
      emc_std_puts("FAIL: " EMC_STR(, Class) "::" # test_method);     \
    }                                                               \
  } while (0)
#  endif /** !EMCPP_EXCEPTIONS */
#endif /* def EMCPP_EXCEPTIONS */

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_TEST_SimpleTest_H */
