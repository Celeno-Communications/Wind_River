if(EMC_TEST_NATIVE_SIMPLE)

  try_compile(SETJUMP_LONGJUMP_OKAY "${CMAKE_CURRENT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/eme/cmake/try_compile/test_for_setjump_longjmp.c")
  if(SETJUMP_LONGJUMP_OKAY)
    add_executable( EmcTestAssertTest EmcTestAssertTest.c )
    target_link_libraries(EmcTestAssertTest PRIVATE emc_std emc_test)
    eme_add_test(EmcTestAssertTest)
  endif()

endif()
