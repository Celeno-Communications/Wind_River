if((EMC_TEST_WRAPPER STREQUAL "CUNIT") AND NOT(EMC_STD_MUTEX MATCHES "embos"))
  if(NOT(EMC_LOG MATCHES "NONE|KPRINT|CUSTOMER"))
    add_executable(log_priority_test log_priority_test.c)
    target_link_libraries(log_priority_test PRIVATE emc_log emc_test)
    eme_add_test(log_priority_test)

    add_executable(log_logger_test log_logger_test.c)
    target_link_libraries(log_logger_test PRIVATE emc_log emc_test)
    eme_add_test(log_logger_test)
    
  endif()
endif()
