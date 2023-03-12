add_library(cunit)

target_include_directories(cunit
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../CUnit/Headers
    ${CMAKE_CURRENT_SOURCE_DIR}/../../CUnit/Sources/Test
)

target_link_libraries(cunit
  PUBLIC
    emc_std
)


add_subdirectory(Basic)
add_subdirectory(Framework)
