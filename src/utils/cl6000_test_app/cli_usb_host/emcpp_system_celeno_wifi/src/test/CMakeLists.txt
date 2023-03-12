add_library(emcpp_system_celeno_test_instances OBJECT)

target_include_directories(emcpp_system_celeno_test_instances PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
target_include_directories(emcpp_system_celeno_test_instances PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../emc_usb_driver_dwc3/inc)
target_include_directories(emcpp_system_celeno_test_instances PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../../emc_usb_driver/inc)

target_sources(emcpp_system_celeno_test_instances PRIVATE
  Dwc3RegisterFileTest.cpp
  PhysicalAddressTest.cpp
  UsbDeviceWaitTest.cpp
)

target_link_libraries(emcpp_system_celeno_test_instances
  PUBLIC
    emc_hw
    emcpp_test
    emc_system_celeno_arch
)

add_executable(emcpp_system_celeno_test_app test_app.cpp)

target_link_libraries(emcpp_system_celeno_test_app
  PRIVATE
    emcpp_system_celeno_test_instances
)

eme_add_test(emcpp_system_celeno_test_app)

if(EMC_TEST_WRAPPER STREQUAL "CUNIT")
  add_executable(PortHook_test PortHook_test.c ../PortHook.c)
  target_include_directories(PortHook_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
  target_link_libraries(PortHook_test
    PRIVATE
      emc_test
      emc_hw_port
  )
  eme_add_test(PortHook_test)

  add_executable(SystemClockManagementTest SystemClockManagementTest.c
    ../device/bootloader/SystemClockManagement.c
  )

  target_include_directories(SystemClockManagementTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
  target_link_libraries(SystemClockManagementTest
    PRIVATE
      emc_usb_descriptor_test
      emc_vendor_celeno_device
      emc_usb_device_test
      emc_system_celeno_arch
  )
  eme_add_test(SystemClockManagementTest)

  add_executable(StartupConfigurationTest StartupConfigurationTest.c
    ../device/bootloader/StartupConfiguration.c
  )
  target_include_directories(StartupConfigurationTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../inc)
  target_link_libraries(StartupConfigurationTest
    PRIVATE
      emc_test
  )
  eme_add_test(StartupConfigurationTest)

endif()
