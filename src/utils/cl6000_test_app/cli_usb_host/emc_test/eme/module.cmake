if(EMC_TEST_WRAPPER STREQUAL "CUNIT")
  eme_add_prerequisites(external_cunit)
endif()

eme_add_prerequisites(emc_log)


if(EMC_TEST_WRAPPER STREQUAL "CUNIT")
 set(EMC_TEST_WRAPPER_CUNIT 1)
elseif(EMC_TEST_WRAPPER STREQUAL "CHECK")
 set(EMC_TEST_WRAPPER_CHECK 1)
elseif(EMC_TEST_WRAPPER STREQUAL "SIMPLE")
 set(EMC_TEST_WRAPPER_SIMPLE 1)
else()
endif()
