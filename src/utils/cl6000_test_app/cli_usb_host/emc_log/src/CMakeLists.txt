if(EMC_LOG MATCHES "NONE|KPRINT|CUSTOMER")
  add_library(emc_log INTERFACE)
  target_include_directories(emc_log INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../inc)
  target_link_libraries(emc_log INTERFACE emc_config)
else()
  add_library(emc_log)
  target_include_directories(emc_log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)
  target_link_libraries(emc_log PUBLIC emc_config)
  target_link_libraries(emc_log PUBLIC emc_std_ext)
  
  if(EMC_LOG STREQUAL "EMCPP")
    target_link_libraries(emc_log PUBLIC emcpp_log)
  endif()

  if (EMC_LOG_INTERNAL_APPENDER_UART_INSTANCES GREATER 0)
    target_link_libraries(emc_log PUBLIC external_snprintf)
  endif()  
endif()

if(NOT(EMC_LOG MATCHES "NONE|KPRINT|CUSTOMER"))
  target_sources(emc_log PRIVATE
    priority.c
  )

  if(EMC_LOG STREQUAL "INTERNAL")
    add_subdirectory(internal)
  endif()
endif()

if(EMC_TEST)
  add_subdirectory(test)
endif()
