target_sources(emc_usb_vendor_celeno_cli_host PRIVATE
  Error.c
  FunctionProxy.c
  CommandInit.c
)

if(EMC_TEST)
  add_subdirectory(test)
endif()
