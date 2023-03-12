if(EMC_TEST_NATIVE_SIMPLE)

  if(EMC_STD_ASSERT_IMPL STREQUAL "HANDLER")
    if(EMC_STD_ASSERT_CONTEXT)
      add_executable( EmcStdAssertContextTest EmcStdAssertContextTest.c )
      target_link_libraries( EmcStdAssertContextTest PRIVATE emc_std emc_test)
      eme_add_test(EmcStdAssertContextTest)
    endif()

    add_executable( EmcStdAssertHandlerTest EmcStdAssertHandlerTest.c )
    target_link_libraries( EmcStdAssertHandlerTest PRIVATE emc_std emc_test)
    eme_add_test(EmcStdAssertHandlerTest)
  endif()
  
endif()
