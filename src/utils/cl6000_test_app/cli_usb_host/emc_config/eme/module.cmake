if(NOT ${CUSTOMER_CONFIGURE})
  set(EMC_USE_NOT_CUSTOMER_CONFIGURE_H 1)
endif()

if(NOT EMC_CUSTOMER_CONFIG STREQUAL "")
  eme_add_prerequisites(emc_config_${EMC_CUSTOMER_CONFIG})
endif()

if(PROJECT_BUILD_DEBUG)
  if(PROJECT_BUILD_OPTIM)
    set(EMC_BUILD "DEBUG_OPTIM")
  else()
    set(EMC_BUILD "DEBUG")
  endif()
else()
  set(EMC_BUILD "OPTIM")
endif()

if(EMC_TEST)
  eme_add_prerequisites(emc_test)
endif()