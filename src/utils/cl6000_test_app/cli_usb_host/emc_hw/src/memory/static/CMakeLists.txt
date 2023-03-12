target_sources(emc_hw_memory PRIVATE
  StaticPortMemoryPool.c
  StaticPortSmallMemory.c
  StaticPortMediumMemory.c
  StaticPortLargeMemory.c
)

if(EMCPP_UNITTEST_CPPUNIT)
  add_subdirectory(test)
endif()

