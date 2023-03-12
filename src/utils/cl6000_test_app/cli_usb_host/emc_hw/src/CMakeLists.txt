add_library(emc_hw INTERFACE)

target_include_directories(emc_hw INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

target_link_libraries(emc_hw
  INTERFACE
    emc_std_ext
)

add_subdirectory(port)
add_subdirectory(memory)