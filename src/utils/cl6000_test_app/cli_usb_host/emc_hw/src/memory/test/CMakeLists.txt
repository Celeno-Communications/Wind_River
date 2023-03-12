if(EMCPP_UNITTEST_CPPUNIT)
  add_library(emc_hw_memory_test)

  target_link_libraries(emc_hw_memory_test
    PUBLIC
      emc_hw_memory
      emcpp_test
  )

  target_sources(emc_hw_memory_test PRIVATE
    BaseTest.cpp
    MemoryPoolTest.cpp
  )
endif()

if(EMC_MEMORY_POOL_TYPE_UNCACHED)
  if(NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_executable(EmcHwMemoryPoolTest EmcHwMemoryPoolTest.c ../PhysicalAddress.c)
    target_link_libraries(EmcHwMemoryPoolTest PRIVATE emc_hw_memory)
    eme_add_test(EmcHwMemoryPoolTest)
  endif()
endif()
