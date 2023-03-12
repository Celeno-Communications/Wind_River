if (NOT EMC_LOG STREQUAL "NONE")
  eme_add_prerequisites(emc_std)
endif()

if(EMC_LOG STREQUAL "EMCPP")
  eme_add_prerequisites(emcpp_log)
endif()

if(EMC_LOG STREQUAL "INTERNAL")
  if (EMC_LOG_INTERNAL_APPENDER_UART_INSTANCES GREATER 0)
    eme_add_prerequisites(external_snprintf)
  endif()  
endif()

if(NOT EMC_LOG STREQUAL "NONE")
  set(EMC_LOG_LOGGING 1)
endif()

set(EMC_LOG_LOGGING_${EMC_LOG} 1)
set(EMC_LOG_LOGGING_USES_HASH ${EMC_LOG_USES_HASH})

set(EMC_OS_LOG_PROFILE ${EMC_LOG_PROFILE})

string(TOUPPER ${EMC_LOG_LEVEL} EMC_LOG_LEVEL_UPPERCASE)

