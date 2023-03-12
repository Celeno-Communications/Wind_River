add_library(emc_hw_memory)

target_include_directories(emc_hw_memory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

target_link_libraries(emc_hw_memory
  PUBLIC
    emc_hw
)

target_sources(emc_hw_memory PRIVATE
  Memory.c
  MemoryPool.c
)

if(EMC_HW_PHYSICAL_ADDRESS_MAP STREQUAL "PSEUDO")
  target_sources(emc_hw_memory PRIVATE
    PhysicalAddress.c
  )
endif()


if(EMC_MEMORY_POOL_TYPE_UNCACHED)
  target_sources(emc_hw_memory PRIVATE
    UncachedMemoryPool.c
  )
  target_link_libraries(emc_hw_memory
    PUBLIC
      emc_std_thread
  )
endif()

if(EMC_MEMORY_POOL_TYPE_XTOS)
  target_sources(emc_hw_memory PRIVATE
    XtosMemoryPool.c
  )
endif()

if(EMC_MEMORY_POOL_TYPE_TLSF)
  target_link_libraries(emc_hw_memory
    PUBLIC
      external_baisoku_tlsf
  )

  target_sources(emc_hw_memory PRIVATE
    TlsfMemoryPool.c
  )

  set_target_properties(emc_hw_memory PROPERTIES NOT_LINTABLE "TlsfMemoryPool")

endif()

add_subdirectory(const)

if (EMC_MEMORY_POOL_TYPE_MALLOC OR EMC_TEST)
  add_subdirectory(dynamic)
endif()

if(EMC_MEMORY_POOL_TYPE_STATIC)
  add_subdirectory(static)
endif()

if(EMC_TEST)
  add_subdirectory(test)
endif()




