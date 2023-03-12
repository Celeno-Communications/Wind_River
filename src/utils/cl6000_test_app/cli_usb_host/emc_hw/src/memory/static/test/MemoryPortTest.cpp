/// Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
#include "emc/hw/memory/test/MemoryTest.hpp"
#include "emc/hw/port/MemoryMappedPort.h"
#include "emc/hw/memory/StaticPortMemoryPool.h"

namespace emcpp {

  class MemoryPortTest : public MemoryTest {
    typedef MemoryTest Base;

  protected:
    virtual EMC_HW_Port* create_port(std::uintptr_t base_addr) override
    {
      struct EMC_MemoryPool* pool = EMC_StaticPortMemoryPool_new();
      return EMC_MemoryMappedPort_new(base_addr, pool);
    }

    virtual void delete_port(EMC_HW_Port* /*port*/) override
    {
      // StaticPortMemoryPool should not be deleted
      // this leads to heap-use-after-free
      // potentially this requires further investigation
      // EMC_MemoryPool_delete(port->pool);
    }

  public:
    EMCPP_TEST_SUB_SUITE(MemoryPortTest, Base);
    EMCPP_TEST_SUITE_END();
  };

}

EMCPP_TEST_SUITE_INSTANTIATION(emcpp::MemoryPortTest);
