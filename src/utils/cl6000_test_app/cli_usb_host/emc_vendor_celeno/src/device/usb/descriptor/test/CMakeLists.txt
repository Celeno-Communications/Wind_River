if(EMC_TEST_WRAPPER STREQUAL "CUNIT")

  add_executable(UniqueChipId_test UniqueChipId_test.c)
  target_link_libraries(UniqueChipId_test
    PRIVATE
      emc_test
      emc_vendor_celeno_device_usb_descriptor
  )
  eme_add_test(UniqueChipId_test)

  
  add_executable(DescriptorSetConfigure_test DescriptorSetConfigure_test.c)
  target_link_libraries(DescriptorSetConfigure_test
    PRIVATE
      emc_test
      emc_vendor_celeno_device_usb_descriptor
      emc_usb_vendor_celeno_cli_device_descriptor
  )
  eme_add_test(DescriptorSetConfigure_test)

endif()