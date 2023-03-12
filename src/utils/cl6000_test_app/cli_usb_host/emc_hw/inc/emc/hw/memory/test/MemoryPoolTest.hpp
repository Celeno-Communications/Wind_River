/// @file
/// @brief
/// Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
#ifndef EMC_HW_MEMORY_TEST_MemoryPoolTest_HPP
#define EMC_HW_MEMORY_TEST_MemoryPoolTest_HPP

#include "emc/hw/memory/test/BaseTest.hpp"
#include "emc/hw/memory/Memory.h"
#include "emc/hw/memory/MemoryPool.h"

namespace emcpp {

  class MemoryPoolTest : public BaseTest {
    typedef BaseTest Base;

  public:
    virtual struct EMC_MemoryPool* create_pool() = 0;
    virtual void delete_pool(struct EMC_MemoryPool* pool) = 0;

    void test_create_destroy();

    void test_allocate_small_memory();
    void test_allocate_small_chunk_memory();
    void test_allocate_medium_chunk_memory();
    void test_allocate_large_chunk_memory();
    void test_allocate_invalid_size_memory();
    void test_allocate_overflowing_size_memory();

    void test_allocate_memory(unsigned size, unsigned alignment);

  protected:
    /// the base address of the Port
    std::uintptr_t base_address() const { return _base_address; }

    /// create a MemoryPoolTest with a base_address
    MemoryPoolTest(std::uintptr_t base_address = 0)
      : _base_address(base_address)
    {}

  private:
    std::uintptr_t _base_address;

  public:
    EMCPP_TEST_SUB_SUITE(MemoryPoolTest, Base);
    EMCPP_TEST_ADD(test_create_destroy);
    EMCPP_TEST_ADD(test_allocate_small_memory);
    EMCPP_TEST_ADD(test_allocate_small_chunk_memory);
    EMCPP_TEST_ADD(test_allocate_medium_chunk_memory);

#if 0
    // will only be called on pools with large chunks available
    EMCPP_TEST_ADD(test_allocate_large_chunk_memory);
#endif

#if 0
    // I think it's permitted to use SIGSEGV instead of explicit SIGABRT.
    // But on linux I can't catch SIGSEGV more than once in a test application.
    // So enable just one of these similar bad-size tests:
    EMCPP_TEST_ADD(test_allocate_invalid_size_memory);
    EMCPP_TEST_ADD(test_allocate_overflowing_size_memory);
#endif
    EMCPP_TEST_SUITE_END_ABSTRACT();
  };

}

#endif /* EMC_HW_PORT_TEST_MemoryPoolTest_HPP */
