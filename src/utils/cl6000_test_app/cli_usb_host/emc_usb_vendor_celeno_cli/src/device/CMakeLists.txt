add_library(emc_usb_vendor_celeno_cli_device_descriptor)

target_include_directories(emc_usb_vendor_celeno_cli_device_descriptor
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../emcpp_system_celeno_wifi/inc
)

target_link_libraries(emc_usb_vendor_celeno_cli_device_descriptor
  PRIVATE
    emc_vendor_celeno_device_usb_descriptor
)

target_sources(emc_usb_vendor_celeno_cli_device_descriptor PRIVATE
  DescriptorCli.c
)

target_sources(emc_usb_vendor_celeno_cli_device PRIVATE
  Function.c
  ResponseInit.c
  TargetOperations.c
  ../TargetMemory.c
  ../TargetMemoryDump.c
)

target_link_libraries(emc_usb_vendor_celeno_cli_device
  PRIVATE
    emc_vendor_celeno_device
)


if(EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM STREQUAL "VIRTUAL")
  target_sources(emc_usb_vendor_celeno_cli_device PRIVATE
    VirtualTargetMemory.c
  )
endif()
if(EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM STREQUAL "MMAP")
  target_sources(emc_usb_vendor_celeno_cli_device PRIVATE
    MMAPTargetMemory.c
  )
endif()
if(EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM STREQUAL "DIRECT")
  target_sources(emc_usb_vendor_celeno_cli_device PRIVATE
    DirectTargetMemory.c
  )
endif()

if(EMC_TEST)
  add_subdirectory(test)
endif()
