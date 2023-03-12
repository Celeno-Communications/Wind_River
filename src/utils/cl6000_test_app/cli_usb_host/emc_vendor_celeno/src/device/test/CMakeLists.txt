
target_sources(emc_vendor_celeno_device PRIVATE
  Idma_test.c
)

if(EMC_TEST_WRAPPER STREQUAL "CUNIT")

  add_executable(Otp_test Otp_test.c)
  target_link_libraries(Otp_test
    PRIVATE
      emc_test
      emc_vendor_celeno_device
  )
  eme_add_test(Otp_test)

  add_executable(MiscReg_test MiscReg_test.c)
  target_link_libraries(MiscReg_test
    PRIVATE
      emc_test
      emc_vendor_celeno_device
  )
  eme_add_test(MiscReg_test)

  add_executable(WatchDog_test WatchDog_test.c)
  target_link_libraries(WatchDog_test
    PRIVATE
      emc_test
      emc_vendor_celeno_device
  )
  eme_add_test(WatchDog_test)

  add_executable(IpcMockTest IpcMockTest.c)
  target_link_libraries(IpcMockTest
    PRIVATE
      emc_test
      emc_vendor_celeno_device
  )
  eme_add_test(IpcMockTest)

  if (NOT EMC_USB_VENDOR_CELENO_UMAC_APP STREQUAL "pcie")
    add_executable(SystemGlobalInitTest SystemGlobalInitTest.c)
    target_link_libraries(SystemGlobalInitTest
      PRIVATE
        emc_test
        emc_vendor_celeno_device
        emc_usb_vendor_celeno_usbwrapper_mock
    )
    eme_add_test(SystemGlobalInitTest)
  endif()

  add_executable(Tci_test Tci_test.c)
  target_link_libraries(Tci_test
    PRIVATE
      emc_test
      emc_vendor_celeno_device
  )
  eme_add_test(Tci_test)

endif()
