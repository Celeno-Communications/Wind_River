#include "emc/hw/memory/test/MemoryPoolTest.hpp"
#include "emc/hw/memory/StaticPortMemoryPool.h"

namespace emcpp {

  class StaticMemoryPoolTest : public MemoryPoolTest {
    typedef MemoryPoolTest Base;

  public:
    virtual struct EMC_MemoryPool* create_pool() override
    {
      return EMC_StaticPortMemoryPool_new();
    }

    virtual void delete_pool(struct EMC_MemoryPool* pool) override
    {
      EMC_MemoryPool_delete(pool);
    }

  public:
    EMCPP_TEST_SUB_SUITE(StaticMemoryPoolTest, Base);
    EMCPP_TEST_SUITE_END();
  };

  EMCPP_TEST_SUITE_INSTANTIATION(StaticMemoryPoolTest);

}
