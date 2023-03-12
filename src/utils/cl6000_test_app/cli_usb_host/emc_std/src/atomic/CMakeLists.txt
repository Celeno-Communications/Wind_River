if(EMC_STD_ATOMIC STREQUAL "EMULATE")
  add_subdirectory(generic)
elseif(EMC_STD_ATOMIC STREQUAL "IMC")
  add_subdirectory(imc)
elseif(EMC_STD_ATOMIC STREQUAL "NULL")
  add_subdirectory(null)
elseif(EMC_STD_ATOMIC STREQUAL "PSEUDO")
  add_subdirectory(pseudo)
elseif(EMC_STD_ATOMIC STREQUAL "XTOS")
  add_subdirectory(xtos)
elseif(EMC_STD_ATOMIC STREQUAL "EXTERN")
else()
  message(FATAL_ERROR "Unsupported atomic architecture: ${EMC_STD_ATOMIC}.")
endif()

target_sources(emc_std PRIVATE
  stdatomic.c
)

