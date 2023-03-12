add_library(emc_hw_port)

target_include_directories(emc_hw_port PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../inc)

target_link_libraries(emc_hw_port
  PUBLIC
    emc_hw
)

if(EMC_HW_PORT_INLINE_MMIO)
  target_sources(emc_hw_port PRIVATE
    Port_inline_mmio.c # this could be empty, but require INTERFACE library
    )
else() #if(EMC_HW_PORT_VTBL)
  target_sources(emc_hw_port PRIVATE
    Port_vtbl.c
  )

  if(EMC_HW_PORT_VTBL_MMIO)
    target_sources(emc_hw_port PRIVATE
      MemoryMappedPort.c
    ) 
  endif()
endif()

if(EMCPP_UNITTEST_CPPUNIT)
  add_subdirectory(test)
endif()

