add_library(emc_test)

target_include_directories(emc_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

if(EMC_TEST)
  add_subdirectory(test)
endif()

target_sources(emc_test PRIVATE
  test_assert.c
)

target_link_libraries(emc_test
  PUBLIC
    emc_std
    emc_log
)
  
if(EMC_TEST_WRAPPER STREQUAL "CUNIT")

  add_subdirectory(CUnit)
  
  target_link_libraries(emc_test
    PUBLIC
      cunit
  )
endif()

set_target_properties(emc_test PROPERTIES NOT_LINTABLE TRUE)
