if(EMC_TEST_WRAPPER STREQUAL "CUNIT")

  if(EMC_USB_ROLE_HOST)
    add_executable(Command_test Command_test.c)
    target_link_libraries(Command_test
      PRIVATE
        emc_usb_vendor_celeno_cli_host
        emc_usb_vendor_celeno_cli_test
    )
    eme_add_test(Command_test)
  endif()
  
  if((EMC_USB_ROLE_DEVICE) AND (EMC_USB_ROLE_HOST))
    add_executable(Response_test Response_test.c)
    target_link_libraries(Response_test
      PRIVATE
        emc_usb_vendor_celeno_cli_device    
        emc_usb_vendor_celeno_cli_test
        emc_usb_vendor_celeno_cli_host
    )
    eme_add_test(Response_test)
  endif()
endif()

