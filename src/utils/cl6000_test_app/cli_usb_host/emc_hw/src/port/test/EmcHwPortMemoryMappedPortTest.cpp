#include "emc/hw/port/test/PortTest.hpp"
#include "emc/hw/port/MemoryMappedPort.h"

namespace emcpp {

  class MemoryMappedPortTest : public PortTest {
    typedef PortTest Base;

  public:
    virtual EMC_HW_Port* create_port(std::uintptr_t base_addr) override
    {
      return EMC_MemoryMappedPort_new(base_addr);
    }

    virtual void delete_port(EMC_HW_Port* port) override
    {
      EMC_HW_Port_delete(port);
    }

  public:
    EMCPP_TEST_SUB_SUITE(MemoryMappedPortTest, Base);
    EMCPP_TEST_SUITE_END();
  };

  EMCPP_TEST_SUITE_INSTANTIATION(MemoryMappedPortTest);

}
