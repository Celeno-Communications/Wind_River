if(EMC_TEST_WRAPPER STREQUAL "CUNIT")
  add_executable( EMC_USB_GlobalPool_test EMC_USB_GlobalPool_test.c )
  target_link_libraries( EMC_USB_GlobalPool_test PRIVATE emc_usb_test)
  eme_add_test(EMC_USB_GlobalPool_test)
  
  add_executable( EMC_USB_InOutEndpointPool_test EMC_USB_InOutEndpointPool_test.c )
  target_link_libraries( EMC_USB_InOutEndpointPool_test PRIVATE emc_usb_test)
  eme_add_test(EMC_USB_InOutEndpointPool_test)
  
  add_executable( EMC_USB_IdEndpointPool_test EMC_USB_IdEndpointPool_test.c )
  target_link_libraries( EMC_USB_IdEndpointPool_test PRIVATE emc_usb_test)
  eme_add_test(EMC_USB_IdEndpointPool_test)
  
  add_executable( EMC_USB_CompactEndpointPool_test EMC_USB_CompactEndpointPool_test.c )
  target_link_libraries( EMC_USB_CompactEndpointPool_test PRIVATE emc_usb_test)
  eme_add_test(EMC_USB_CompactEndpointPool_test)
endif()

