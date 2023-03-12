#include "emc/hw/port/test/PortTest.hpp"
#include "emc/hw/port/Port.h"

namespace emcpp {

  class InlineMemoryMappedPortTest : public PortTest {
    typedef PortTest Base;

  public:
    virtual EMC_HW_Port* create_port(std::uintptr_t base_addr) override
    {
      UNUSED_PARAM(base_addr);
      return nullptr;
    }

    virtual void delete_port(EMC_HW_Port* port) override
    {
      UNUSED_PARAM(port);
      EMC_HW_Port_destroy(port);
    }

  public:
    EMCPP_TEST_SUB_SUITE(InlineMemoryMappedPortTest, Base);
    EMCPP_TEST_SUITE_END();
  };

  EMCPP_TEST_SUITE_INSTANTIATION(InlineMemoryMappedPortTest);

}
