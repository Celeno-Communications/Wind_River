add_library(emc_config INTERFACE)

target_include_directories(emc_config INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

if(EMC_TEST)
  add_subdirectory(test)
endif()

if(EMC_CUSTOMER_CONFIG STREQUAL "comneon")
  target_link_libraries(emc_config INTERFACE emc_config_comneon)
endif()

if(EMC_CUSTOMER_CONFIG STREQUAL "celeno_wifi")
  target_link_libraries(emc_config INTERFACE emc_config_celeno_wifi)
endif()
