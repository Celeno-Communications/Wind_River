/* Copyright (C) 2017 emsys Embedded Systems GmbH */
#include "emcpp/test/UnitTest.hpp"
#include "emc/hw/memory/MemoryPool.h"
#include "emcpp/std/cstdint.hpp"
#include "emcpp/std/memory.hpp"
#include "emcpp/std/vector.hpp"

class helper {
public:
  helper()
    : _mem()
  {}

  EMC_Memory* memory() { return &_mem; }

  ~helper()
  {
    EMC_Memory_free(&_mem, 0);
  }

private:
  EMC_Memory _mem;
};

typedef std::unique_ptr<helper> buffer_t;

namespace emcpp {

  class EmcUsbDriverIntegrationTest : public test::TestFixture {
  public:
    EmcUsbDriverIntegrationTest()
      : _buf(512 * 1024)
      , _pool(nullptr)
    {
      _pool = EMC_MemoryPool_new(_buf.begin(), _buf.size());
    }

    buffer_t allocate(std::uint32_t size, std::uint32_t alignment)
    {
      helper* h = new helper;
      EMC_MemoryPool_allocate_aligned(_pool, size, alignment, h->memory());
      return buffer_t(h);
    }

    std::vector<std::uint8_t>& buffer() { return _buf; }

    void test_memory_pool()
    {
      std::vector<buffer_t> allocations;

      for (int i = 0; i < 17; i++) {
        buffer_t      buf = std::move(allocate(8 * 1024, 16));
        std::uint8_t* pointer = static_cast<std::uint8_t*>(EMC_Memory_address(*(buf->memory())));

        if (pointer != nullptr) {
          EMCPP_TEST_ASSERT(pointer > buffer().begin());
          EMCPP_TEST_ASSERT(pointer < buffer().begin() + buffer().size());
        } else {
          /* 10 allocations must fit */
          fprintf(stderr, "i=%d", i);
          EMCPP_TEST_ASSERT(i >= 10);
        }

        allocations.push_back(std::move(buf));
      }
    }

  private:
    std::vector<std::uint8_t> _buf;
    EMC_MemoryPool*           _pool;

    EMCPP_TEST_SUITE(EmcUsbDriverIntegrationTest);
    EMCPP_TEST_ADD(test_memory_pool);
    EMCPP_TEST_SUITE_END();
  };

  EMCPP_TEST_SUITE_INSTANTIATION(EmcUsbDriverIntegrationTest);

}
