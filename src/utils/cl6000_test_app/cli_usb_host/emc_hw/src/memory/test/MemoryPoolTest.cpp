#include "emc/hw/memory/test/MemoryPoolTest.hpp"

namespace emcpp {

  void MemoryPoolTest::test_create_destroy()
  {
    EMC_MemoryPool* pool = create_pool();
    EMCPP_TEST_ASSERT_TRUE(pool);

    delete_pool(pool);
  }

  void MemoryPoolTest::test_allocate_small_memory()
  {
    unsigned value = 0xAAAABBBB;
    unsigned size = sizeof(value);
    unsigned alignment = 16; // 32 geht nicht!

    EMCPP_TEST_TRY {
      test_allocate_memory(size, alignment);
    }
    EMCPP_TEST_ASSERT_FALSE(did_abort());
  }

  void MemoryPoolTest::test_allocate_small_chunk_memory()
  {
    unsigned size = EMC_PORT_ALLOCATOR_SMALL_CHUNK_SIZE;
    unsigned alignment = 16; // 32 geht nicht!

    EMCPP_TEST_TRY {
      test_allocate_memory(size, alignment);
    }
    EMCPP_TEST_ASSERT_FALSE(did_abort());
  }

  void MemoryPoolTest::test_allocate_medium_chunk_memory()
  {
    unsigned size = EMC_PORT_ALLOCATOR_MEDIUM_CHUNK_SIZE;
    unsigned alignment = 4; //32

    EMCPP_TEST_TRY {
      test_allocate_memory(size, alignment);
    }
    EMCPP_TEST_ASSERT_FALSE(did_abort());
  }

  void MemoryPoolTest::test_allocate_large_chunk_memory()
  {
    unsigned size = EMC_PORT_ALLOCATOR_LARGE_CHUNK_SIZE;
    unsigned alignment = 4; //32;

    EMCPP_TEST_TRY {
      test_allocate_memory(size, alignment);
    }
    EMCPP_TEST_ASSERT_FALSE(did_abort());
  }

  void MemoryPoolTest::test_allocate_invalid_size_memory()
  {
    unsigned size = (unsigned)(-1000);
    unsigned alignment = 32;

    EMCPP_TEST_TRY {
      test_allocate_memory(size, alignment);
    }
    EMCPP_TEST_ASSERT_TRUE(did_abort());
  }

  void MemoryPoolTest::test_allocate_overflowing_size_memory()
  {
    unsigned size = (unsigned)(-1); /* Overflow if aligned */
    unsigned alignment = 32;

    EMCPP_TEST_TRY {
      test_allocate_memory(size, alignment);
    }
    EMCPP_TEST_ASSERT_TRUE(did_abort());
  }

  void MemoryPoolTest::test_allocate_memory(unsigned size, unsigned alignment)
  {
    EMC_MemoryPool* pool = create_pool();
    EMCPP_TEST_ASSERT_TRUE(pool);

    EMC_Memory memory;
    EMC_MemoryPool_allocate_aligned(pool, size, alignment, &memory);
    void* address = EMC_Memory_address(memory);
    char* ptr = static_cast<char*>(address);
    char* zero = 0;
    EMCPP_TEST_ASSERT(ptr != 0 && ((unsigned)(ptr - zero) % alignment) == 0);

    if (EMC_PhysicalAddress_is_supported()) {
      EMC_PhysicalAddress pa_one = EMC_PhysicalAddress_new(address);
      EMCPP_TEST_ASSERT(pa_one.handle);
      EMC_PhysicalAddress pa_two = EMC_Memory_physical_address(memory);
      EMCPP_TEST_ASSERT(pa_two.handle);
    }

    EMC_Memory_free(&memory, size);

    delete_pool(pool);
  }

}
