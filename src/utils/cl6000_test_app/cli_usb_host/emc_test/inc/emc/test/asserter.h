#ifndef EMC_TEST_asserter_H
#define EMC_TEST_asserter_H

#ifdef HAVE_CMAKE_CONFIGURE
#  include "emc_test/cmakeConfigure.h"
#endif
#include "emc/config/configure.h"

#if EMC_TEST_WRAPPER_CUNIT
#  include "emc/test/CUnit/Asserter.h"
#elif EMC_TEST_WRAPPER_CHECK
#  include "emc/test/check/check.h"
#else
#  error "No C Testing Framework specified!"
#endif

#endif
