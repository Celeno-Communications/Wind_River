if(EMC_TEST_WRAPPER STREQUAL "CUNIT")
  add_executable( EMC_USB_Error_test EMC_USB_Error_test.c )
  target_link_libraries( EMC_USB_Error_test PRIVATE emc_usb_test)
  eme_add_test(EMC_USB_Error_test)
  
  add_executable( EMC_USB_EndpointId_test EMC_USB_EndpointId_test.c )
  target_link_libraries( EMC_USB_EndpointId_test PRIVATE emc_usb_test)
  eme_add_test(EMC_USB_EndpointId_test)
  
  add_executable( EMC_USB_EndpointAttributes_test EMC_USB_EndpointAttributes_test.c )
  target_link_libraries( EMC_USB_EndpointAttributes_test PRIVATE emc_usb_test)
  eme_add_test(EMC_USB_EndpointAttributes_test)
endif()

target_sources(emc_usb_test PRIVATE
  Pipe.c
)
