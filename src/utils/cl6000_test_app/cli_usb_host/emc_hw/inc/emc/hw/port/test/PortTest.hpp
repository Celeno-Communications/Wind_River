/// @file
/// @brief
/// Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
#ifndef EMC_HW_PORT_TEST_PortTest_HPP
#define EMC_HW_PORT_TEST_PortTest_HPP

#include "emcpp/test/HelperMacros.hpp"
#include "emcpp/test/UnitTest.hpp"
#include "emc/hw/port/Port_fwd.h"

namespace emcpp {

  class PortTest : public emcpp::test::TestFixture {
  public:
    virtual EMC_HW_Port* create_port(std::uintptr_t base_addr) = 0;
    virtual void delete_port(EMC_HW_Port* port) = 0;

    /// tests only the create and destroy methods
    void test_create_destroy();
    void test_register_write_read();

    void test_read_hook();
    void test_write_hook();

    virtual ~PortTest();

  protected:
    /// the base address of the Port
    std::uintptr_t base_address() const { return _base_address; }

    /// create a PortTest with a base_address
    PortTest(std::uintptr_t base_address = 0);

  private:
    enum {
      SIZE = 256
    };

    std::uintptr_t _base_address;
    unsigned*      _memory;
    std::size_t    _memory_size;

  public:
    EMCPP_TEST_SUITE(PortTest);
    EMCPP_TEST_ADD(test_create_destroy);
    EMCPP_TEST_ADD(test_register_write_read);
#if EMC_HW_PORT_READ_HOOK
    EMCPP_TEST_ADD(test_read_hook);
#endif
#if EMC_HW_PORT_WRITE_HOOK
    EMCPP_TEST_ADD(test_write_hook);
#endif
    EMCPP_TEST_SUITE_END_ABSTRACT();
  };

}

#endif /* EMC_HW_PORT_TEST_PortTest_HPP */
