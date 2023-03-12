/// @file
/// @brief
/// Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
#ifndef EMC_HW_MEMORY_TEST_BaseTest_HPP
#define EMC_HW_MEMORY_TEST_BaseTest_HPP

#include "emcpp/test/HelperMacros.hpp"
#include "emcpp/test/UnitTest.hpp"

#include "emc/hw/configure.h"

#include "emcpp/std/cassert.hpp"
#include "emc/std/assert.h"
#include <assert.h>
#include <setjmp.h>

namespace emcpp {

#define EMCPP_TEST_TRY if (!setjmp(jmpbuf))

  class BaseTest : public emcpp::test::TestFixture {
  public:
    virtual void setUp() override;
    virtual void tearDown() override;

  protected:
    BaseTest() : _prev_handler(0) {}

    static jmp_buf jmpbuf;

    bool did_abort() const;

  private:
    static void abort_handler(int sig);

    void       (* _prev_handler)(int);

    static int signal_count;
    static int reported_signal;

    EMCPP_TEST_SUITE(BaseTest);
    EMCPP_TEST_SUITE_END_ABSTRACT();
  };

}

#endif /* EMC_HW_MEMORY_TEST_BaseTest_HPP */
