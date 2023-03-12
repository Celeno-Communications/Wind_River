if((EMC_TEST_WRAPPER STREQUAL "CUNIT") AND (CMAKE_SIZEOF_VOID_P STREQUAL "4"))
  add_executable ( EmcStdargTest EmcStdargTest.c )
  target_link_libraries ( EmcStdargTest PRIVATE emc_std emc_test cunit )
  eme_add_test(EmcStdargTest)
endif()

if(EMC_TEST_NATIVE_SIMPLE)

  if(NOT((EMC_STD_ATOMIC STREQUAL "STD") AND (CMAKE_C_COMPILER_ID MATCHES "GNU") AND (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8")))
    if(NOT (EMC_STD_ATOMIC STREQUAL "NULL"))
      add_executable(EmcStdatomicTest EmcStdatomicTest.c)
      target_link_libraries(EmcStdatomicTest PRIVATE emc_std emc_test)
      eme_add_test(EmcStdatomicTest)
    endif()
  endif()

  add_executable( EmcCtypeTest EmcCtypeTest.c )
  target_link_libraries( EmcCtypeTest PRIVATE emc_std emc_test)
  eme_add_test(EmcCtypeTest)

  add_executable( EmcLimitsTest EmcLimitsTest.c )
  target_link_libraries( EmcLimitsTest PRIVATE emc_std emc_test)
  eme_add_test(EmcLimitsTest)


  try_compile(SETJUMP_LONGJUMP_OKAY "${CMAKE_CURRENT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/eme/cmake/try_compile/test_for_setjump_longjmp.c")

  if(SETJUMP_LONGJUMP_OKAY)
    add_executable( EmcSignalTest EmcSignalTest.c )
    target_link_libraries( EmcSignalTest PRIVATE emc_std emc_test)
    eme_add_test(EmcSignalTest)

    add_executable( EmcStdlibAbortTest EmcStdlibAbortTest.c )
    target_link_libraries( EmcStdlibAbortTest PRIVATE emc_std emc_test)
    eme_add_test(EmcStdlibAbortTest)

    if(NOT(EMC_STD_ASSERT STREQUAL "NONE"))
      add_executable( EmcStdAssertTest EmcStdAssertTest.c )
      target_link_libraries( EmcStdAssertTest PRIVATE emc_std emc_test)
      eme_add_test(EmcStdAssertTest)
    endif()

    add_executable( EmcStdlibAtexitTest EmcStdlibAtexitTest.c )
    target_link_libraries( EmcStdlibAtexitTest PRIVATE emc_std emc_test)
    eme_add_test(EmcStdlibAtexitTest)

  endif()
  
  if(NOT(CMAKE_C_COMPILER_ID STREQUAL "MSVC"))
    add_executable( EmcStdlibAtoiTest EmcStdlibAtoiTest.c )
    target_link_libraries( EmcStdlibAtoiTest PRIVATE emc_std emc_test)
    eme_add_test(EmcStdlibAtoiTest)
  endif()

  add_executable( EmcStdlibMallocTest EmcStdlibMallocTest.c )
  target_link_libraries( EmcStdlibMallocTest PRIVATE emc_std emc_test)
  eme_add_test(EmcStdlibMallocTest)

  add_executable( EmcStringTest EmcStringTest.c )
  target_link_libraries( EmcStringTest PRIVATE emc_std emc_test)
  eme_add_test(EmcStringTest)

endif()


add_executable ( EmcStdAssertApp EmcStdAssertApp.c )
target_link_libraries ( EmcStdAssertApp PRIVATE emc_std)
#eme_add_test(EmcStdAssertApp)
