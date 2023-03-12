add_library(emc_system)

target_include_directories(emc_system PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

target_link_libraries(emc_system
  PUBLIC
    emc_hw
)

target_sources(emc_system PRIVATE
  Interrupt.c
)

if( EMC_TEST)
  add_subdirectory(test)
endif()
