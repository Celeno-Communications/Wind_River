if(EMC_TEST_WRAPPER STREQUAL "CUNIT")

  add_executable(log_hierarchy_test log_hierarchy_test.c)
  target_link_libraries(log_hierarchy_test PRIVATE emc_log emc_test)
  eme_add_test(log_hierarchy_test)
  
  add_executable(log_appender_test log_appender_test.c)
  target_link_libraries(log_appender_test PRIVATE emc_log emc_test)
  eme_add_test(log_appender_test)
   
  add_executable(multi_logger_test multi_logger_test.c)
  target_link_libraries(multi_logger_test PRIVATE emc_log emc_test)
  eme_add_test(multi_logger_test)
   
  add_executable(log_lock_test log_lock_test.c)
  target_link_libraries(log_lock_test PRIVATE emc_log emc_test)
  eme_add_test(log_lock_test)
   
  add_executable(log_simple_main_test log_simple_main_test.c)
  target_link_libraries(log_simple_main_test PRIVATE emc_log emc_test)
  eme_add_test(log_simple_main_test)
   
  if (EMC_LOG_INTERNAL_APPENDER_MEMORY_INSTANCES GREATER 0)
    add_executable(log_appender_memory_test log_appender_memory_test.c)
    target_link_libraries(log_appender_memory_test PRIVATE emc_log emc_test)
    eme_add_test(log_appender_memory_test)
  endif()
  if (EMC_LOG_INTERNAL_APPENDER_PRINTF_INSTANCES GREATER 0)
    add_executable(log_appender_fprintf_test log_appender_fprintf_test.c)
    target_link_libraries(log_appender_fprintf_test PRIVATE emc_log emc_test)
    eme_add_test(log_appender_fprintf_test)
  endif()
  if (EMC_LOG_INTERNAL_APPENDER_BUFFERED_TRANSPORT_INSTANCES GREATER 0)
    add_executable(log_appender_buffered_transport_test log_appender_buffered_transport_test.c)
    target_link_libraries(log_appender_buffered_transport_test PRIVATE emc_log emc_test)
    eme_add_test(log_appender_buffered_transport_test)
  endif()
endif()
