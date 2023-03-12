if(EMC_TEST_WRAPPER STREQUAL "CUNIT")

  add_executable(FunctionPrint_test FunctionPrint_test.c)

  target_link_libraries(FunctionPrint_test
    PRIVATE
      emc_usb_vendor_celeno_cli_device
      emc_usb_vendor_celeno_cli_device_descriptor
      emc_usb_vendor_celeno_cli_test
      emc_usb_device_test
      cunit
      emc_log
  )
  eme_add_test(FunctionPrint_test)

  add_executable(FunctionGenericProtocol_functional_test ../../host/test/GenericProtocol_functional_test.c
    DeviceMock.c
  )

  target_link_libraries(FunctionGenericProtocol_functional_test
    PRIVATE
      emc_usb_vendor_celeno_cli_device
      emc_usb_vendor_celeno_cli_device_descriptor
      emc_usb_vendor_celeno_cli_test_graybox
      emc_usb_device_test
      emc_usb_host_hal_mock
      cunit
      emc_log
  )
  eme_add_test(FunctionGenericProtocol_functional_test)

  add_executable(FunctionExtendedProtocol_functional_test ../../host/test/ExtendedProtocol_functional_test.c
    DeviceMock.c
  )

  target_compile_definitions(FunctionExtendedProtocol_functional_test
    PRIVATE
      EMC_TEST_GREYBOX
  )
  target_link_libraries(FunctionExtendedProtocol_functional_test
    PRIVATE
      emc_usb_vendor_celeno_cli_device
      emc_usb_vendor_celeno_cli_device_descriptor
      emc_usb_vendor_celeno_cli_test_graybox
      emc_usb_device_test
      emc_usb_host_hal_mock
      cunit
      emc_log
  )
  eme_add_test(FunctionExtendedProtocol_functional_test)
endif()
