add_library(emc_hw_port_test)

target_link_libraries(emc_hw_port_test
  PUBLIC
    emc_hw_port
    emcpp_test
)

target_sources(emc_hw_port_test PRIVATE
  PortTest.cpp
)

if(EMC_HW_PORT_INLINE_MMIO)
  add_executable(EmcHwPortInlineMemoryMappedPortTest EmcHwPortInlineMemoryMappedPortTest.cpp)
  target_link_libraries(EmcHwPortInlineMemoryMappedPortTest PRIVATE emc_hw_port_test)
  eme_add_test(EmcHwPortInlineMemoryMappedPortTest)
else()
  if(EMC_HW_PORT_VTBL_MMIO)
    add_executable(EmcHwPortMemoryMappedPortTest EmcHwPortMemoryMappedPortTest.cpp)
    target_link_libraries(EmcHwPortMemoryMappedPortTest PRIVATE emc_hw_port_test)
    eme_add_test(EmcHwPortMemoryMappedPortTest)
  endif()
endif()
