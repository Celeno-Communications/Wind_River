/* Copyright (C) 2017 emsys Embedded Systems GmbH */
#include "emcpp/test/UnitTest.hpp"
#include "emcpp/std/new.hpp"
#include "emcpp/std/memory.hpp"
#include "emcpp/std/cstdint.hpp"
#include "emcpp/std/vector.hpp"

/* keep test framework memory footprint in mind when dealing with this test
 * we provide own new/delete operators
 * catch framework using operator new will use out allocator
 */

static const int max_small = 20;
static const int max_medium = 10;
static const int max_large = 2;

typedef std::unique_ptr<std::uint8_t[]> buffer_t;

buffer_t allocate(std::uint32_t size)
{
  return buffer_t(new std::uint8_t[size]);
}

namespace emcpp {

  class EmcppStdIntegrationTest : public test::TestFixture {
  public:
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
            buffer_t buf = std::move(allocate(8));
            medium_allocations.push_back(std::move(buf));
          }

          if (large_allocations.size() < max_large) {
            buffer_t buf = std::move(allocate(8));
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
            buffer_t buf = std::move(allocate(8));
            medium_allocations.push_back(std::move(buf));
          }

          if (large_allocations.size() < max_large) {
            buffer_t buf = std::move(allocate(8));
            large_allocations.push_back(std::move(buf));
          }
        }

        small_allocations.clear();
        medium_allocations.clear();
        large_allocations.clear();
      }
    }

    EMCPP_TEST_SUITE(EmcppStdIntegrationTest);
    EMCPP_TEST_ADD(test_small_medium_large);
    EMCPP_TEST_ADD(test_large_medium_small);
    EMCPP_TEST_ADD(test_one_of_each);
    EMCPP_TEST_SUITE_END();

  };

  EMCPP_TEST_SUITE_INSTANTIATION(EmcppStdIntegrationTest);

}
