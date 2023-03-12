if(EMC_TEST_WRAPPER STREQUAL "CUNIT")
  add_executable(ContinuousBufferTest ContinuousBufferTest.c)
  target_link_libraries(ContinuousBufferTest
    PRIVATE
    emc_usb
    emc_test
    )
  eme_add_test(ContinuousBufferTest)
endif()
