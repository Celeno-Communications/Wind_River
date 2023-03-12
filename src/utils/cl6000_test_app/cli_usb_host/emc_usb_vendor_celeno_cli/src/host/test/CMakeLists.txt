if(EMC_TEST_WRAPPER STREQUAL "CUNIT")
  target_sources(emc_usb_vendor_celeno_cli_test PRIVATE
      GenericProtocol_functional_test_impl.c
      ExtendedProtocol_functional_test_impl.c
  )  
  target_sources(emc_usb_vendor_celeno_cli_test_graybox PRIVATE
    GenericProtocol_functional_test_impl.c
    ExtendedProtocol_functional_test_impl.c
    )
  target_compile_definitions(emc_usb_vendor_celeno_cli_test_graybox
    PRIVATE
      EMC_TEST_GREYBOX
  )
  
  add_executable(HostExtendedProtocol_functional_test ExtendedProtocol_functional_test.c)
  target_link_libraries(HostExtendedProtocol_functional_test
    PRIVATE
      emc_usb_vendor_celeno_cli_test
      cunit
      emc_log
      emc_usb_vendor_celeno_cli_host
      emc_usb_host_hal_libusb
  )
  add_executable(HostGenericProtocol_functional_test GenericProtocol_functional_test.c)
  target_link_libraries(HostGenericProtocol_functional_test
    PRIVATE
      emc_usb_vendor_celeno_cli_test
      cunit
      emc_log
      emc_usb_vendor_celeno_cli_host
      emc_usb_host_hal_libusb
  )
  add_executable(UsbConnectionSpeed_test UsbConnectionSpeed_test.c)
  target_link_libraries(UsbConnectionSpeed_test
    PRIVATE
      emc_usb_vendor_celeno_cli_test
      cunit
      emc_log
      usb-1.0
  )
  add_executable(LibUsbConnectionSpeed LibUsbConnectionSpeed.c)
  target_link_libraries(LibUsbConnectionSpeed
    PRIVATE
      cunit
      emc_std
      usb-1.0
  )
  #don't add to tests, because it has to be executed on a real system with a real device connected  
  #eme_add_test(ExtendedProtocol_functional_test)
endif()
