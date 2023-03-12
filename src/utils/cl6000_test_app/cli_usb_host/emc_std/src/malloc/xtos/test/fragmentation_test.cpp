/* Copyright (C) 2017 emsys Embedded Systems GmbH */
#include "emcpp/test/UnitTest.hpp"
#include "emcpp/std/memory.hpp"
#include "emcpp/std/cstdint.hpp"
#include "emcpp/std/vector.hpp"
#include "emcpp/std/functional.hpp"
#include "external/sue/sue_allocate.h"
#include "emc/std/emu/xtos/wrapper.h"

static const int max_small = 100;
static const int max_medium = 50;
static const int max_large = 3;

namespace emcpp {

// std::function<> is not emulated yet
  using ::std::function;

  typedef ::std::unique_ptr<std::uint8_t, ::std::function<void (void*)> > buffer_t;

  class FragmentationTest : public test::TestFixture {
  public:
    FragmentationTest()
      : _pool_size(32 * 1024)
      , _pool()
    {
      _pool.base = new emc_std_int8_t[_pool_size];
      _pool.end = (void*)(((emc_std_int8_t*)_pool.base) + _pool_size);
      Usb_InitMemManagement(&_pool);
    }

    ~FragmentationTest()
    {
      delete[]((emc_std_int8_t*)_pool.base);
    }

    buffer_t allocate(std::uint32_t size)
    {
      std::uint8_t* mem = static_cast<uint8_t*>(Usb_Alloc(&_pool, size));
      ::std::function<void(void*)> custom_free = ::std::bind(Usb_Free,
                                                             &_pool,
                                                             ::std::placeholders::_1);
      return buffer_t(mem, custom_free);
    }

    usb_allocator_statistics_t allocator_statistics()
    {
      return Usb_AllocatorStatistics(&_pool);
    }

    void test_alloc_free()
    {
      buffer_t buf0 = std::move(allocate(8));
      EMCPP_TEST_ASSERT_TRUE(buf0);
      buf0.reset();
    }

    void test_statistics()
    {
      usb_allocator_statistics_t stats = allocator_statistics();
      const uint32_t             initial_wasted_bytes = stats.bytes_overhead_memory;
      /* initialised state must have only to blocks */
      EMCPP_TEST_ASSERT(stats.obj_count == 2);

      buffer_t buf0 = std::move(allocate(8));
      EMCPP_TEST_ASSERT_TRUE(buf0);
      stats = allocator_statistics();
      EMCPP_TEST_ASSERT(stats.obj_count == 3);

      buffer_t buf1 = std::move(allocate(8));
      EMCPP_TEST_ASSERT_TRUE(buf1);
      stats = allocator_statistics();
      EMCPP_TEST_ASSERT(stats.obj_count == 4);

      buf0.reset();
      stats = allocator_statistics();
      EMCPP_TEST_ASSERT(stats.obj_count == 4);

      buf1.reset();
      stats = allocator_statistics();
      EMCPP_TEST_ASSERT(stats.obj_count == 4);

      /* trigger merging of unused fragments */
      buffer_t buf3 = std::move(allocate(stats.bytes_free + stats.bytes_overhead_memory
                                         - initial_wasted_bytes));
      EMCPP_TEST_ASSERT_TRUE(buf3);
      stats = allocator_statistics();
      EMCPP_TEST_ASSERT(stats.obj_count == 2);
    }

    void test_small_medium_large()
    {
      std::vector<buffer_t> small_allocations;
      std::vector<buffer_t> medium_allocations;
      std::vector<buffer_t> large_allocations;

      for (int j = 0; j < 100; j++) {
        for (int i = 0; i < max_small; i++) {
          buffer_t buf = std::move(allocate(8));
          EMCPP_TEST_ASSERT_TRUE(buf);
          small_allocations.push_back(std::move(buf));
        }

        for (int i = 0; i < max_medium; i++) {
          buffer_t buf = std::move(allocate(100));
          EMCPP_TEST_ASSERT_TRUE(buf);
          medium_allocations.push_back(std::move(buf));
        }

        for (int i = 0; i < max_large; i++) {
          buffer_t buf = std::move(allocate(5000));
          EMCPP_TEST_ASSERT_TRUE(buf);
          large_allocations.push_back(std::move(buf));
        }

        small_allocations.clear();
        medium_allocations.clear();
        large_allocations.clear();

        for (int i = 0; i < max_small; i++) {
          buffer_t buf = std::move(allocate(8));
          EMCPP_TEST_ASSERT_TRUE(buf);
          small_allocations.push_back(std::move(buf));
        }

        for (int i = 0; i < max_medium; i++) {
          buffer_t buf = std::move(allocate(100));
          EMCPP_TEST_ASSERT_TRUE(buf);
          medium_allocations.push_back(std::move(buf));
        }

        for (int i = 0; i < max_large; i++) {
          buffer_t buf = std::move(allocate(5000));
          EMCPP_TEST_ASSERT_TRUE(buf);
          large_allocations.push_back(std::move(buf));
        }

        small_allocations.clear();
        medium_allocations.clear();
        large_allocations.clear();
      }
    }

    void test_large_medium_small()
    {
      std::vector<buffer_t> small_allocations;
      std::vector<buffer_t> medium_allocations;
      std::vector<buffer_t> large_allocations;

      for (int j = 0; j < 100; j++) {
        for (int i = 0; i < max_small; i++) {
          buffer_t buf = std::move(allocate(8));
          EMCPP_TEST_ASSERT_TRUE(buf);
          large_allocations.push_back(std::move(buf));
        }

        for (int i = 0; i < max_medium; i++) {
          buffer_t buf = std::move(allocate(100));
          EMCPP_TEST_ASSERT_TRUE(buf);
          medium_allocations.push_back(std::move(buf));
        }

        for (int i = 0; i < max_large; i++) {
          buffer_t buf = std::move(allocate(5000));
          EMCPP_TEST_ASSERT_TRUE(buf);
          small_allocations.push_back(std::move(buf));
        }

        small_allocations.clear();
        medium_allocations.clear();
        large_allocations.clear();

        for (int i = 0; i < max_small; i++) {
          buffer_t buf = std::move(allocate(8));
          EMCPP_TEST_ASSERT_TRUE(buf);
          large_allocations.push_back(std::move(buf));
        }

        for (int i = 0; i < max_medium; i++) {
          buffer_t buf = std::move(allocate(100));
          EMCPP_TEST_ASSERT_TRUE(buf);
          medium_allocations.push_back(std::move(buf));
        }

        for (int i = 0; i < max_large; i++) {
          buffer_t buf = std::move(allocate(5000));
          EMCPP_TEST_ASSERT_TRUE(buf);
          small_allocations.push_back(std::move(buf));
        }

        small_allocations.clear();
        medium_allocations.clear();
        large_allocations.clear();
      }
    }

    void test_one_of_each()
    {
      std::vector<buffer_t> small_allocations;
      std::vector<buffer_t> medium_allocations;
      std::vector<buffer_t> large_allocations;

      for (int j = 0; j < 100; j++) {
        for (int i = 0; i < 100; i++) {
          if (small_allocations.size() < max_small) {
            buffer_t buf = std::move(allocate(8));
            large_allocations.push_back(std::move(buf));
          }

          if (medium_allocations.size() < max_medium) {
            buffer_t buf = std::move(allocate(100));
            medium_allocations.push_back(std::move(buf));
          }

          if (large_allocations.size() < max_large) {
            buffer_t buf = std::move(allocate(5000));
            large_allocations.push_back(std::move(buf));
          }
        }

        small_allocations.clear();
        medium_allocations.clear();
        large_allocations.clear();

        for (int i = 0; i < 100; i++) {
          if (small_allocations.size() < max_small) {
            buffer_t buf = std::move(allocate(8));
            large_allocations.push_back(std::move(buf));
          }

          if (medium_allocations.size() < max_medium) {
            buffer_t buf = std::move(allocate(100));
            medium_allocations.push_back(std::move(buf));
          }

          if (large_allocations.size() < max_large) {
            buffer_t buf = std::move(allocate(5000));
            large_allocations.push_back(std::move(buf));
          }
        }

        small_allocations.clear();
        medium_allocations.clear();
        large_allocations.clear();
      }
    }

  private:
    std::uint32_t               _pool_size;
    struct sue_allocator_pool_s _pool;

    EMCPP_TEST_SUITE(FragmentationTest);
    EMCPP_TEST_ADD(test_alloc_free);
    EMCPP_TEST_ADD(test_small_medium_large);
    EMCPP_TEST_ADD(test_large_medium_small);
    EMCPP_TEST_ADD(test_one_of_each);
    EMCPP_TEST_ADD(test_statistics);
    EMCPP_TEST_SUITE_END();

  };

  EMCPP_TEST_SUITE_INSTANTIATION(FragmentationTest);

}
