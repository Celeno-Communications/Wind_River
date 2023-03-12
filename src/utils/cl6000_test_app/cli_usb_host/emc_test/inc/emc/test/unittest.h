#ifndef EMC_TEST_unittest_H
#define EMC_TEST_unittest_H

#ifdef HAVE_CMAKE_CONFIGURE
#  include "emc_test/cmakeConfigure.h"
#endif
#include "emc/config/configure.h"

#ifndef EMC_TEST_IMPLICIT_MAIN
#  define EMC_TEST_IMPLICIT_MAIN 1
#endif

#if EMC_TEST_WRAPPER_CUNIT
#  include "emc/test/CUnit/CUnit.h"
#elif EMC_TEST_WRAPPER_CHECK
#  include "emc/test/check/check.h"
#else
#  error "No C Testing Framework specified!"
#endif

#if EMC_TEST_IMPLICIT_MAIN
#  define EMC_TEST_SUITE_DEFINE_MAIN()       \
                                             \
  int main(int argc, char* argv[])           \
  {                                          \
    return EMC_TEST_RUNNER_MAIN(argc, argv); \
  }

#else
#  define EMC_TEST_SUITE_DEFINE_MAIN()
#endif

#endif /* EMC_TEST_unittest_H */
