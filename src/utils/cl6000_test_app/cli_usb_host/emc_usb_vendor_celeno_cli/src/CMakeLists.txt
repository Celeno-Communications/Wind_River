add_library(emc_usb_vendor_celeno_cli)

target_include_directories(emc_usb_vendor_celeno_cli
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../emcpp_system_celeno_wifi/inc
)

target_link_libraries(emc_usb_vendor_celeno_cli
  PUBLIC
    emc_usb
    emc_log
    emc_std_ext
)

if(EMC_USB_ROLE_DEVICE)

  add_library(emc_usb_vendor_celeno_cli_device)

  target_include_directories(emc_usb_vendor_celeno_cli_device PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

  target_link_libraries(emc_usb_vendor_celeno_cli_device
    PUBLIC
      emc_usb_vendor_celeno_cli
      emc_usb_device
  )
endif()

if(EMC_USB_ROLE_HOST)
  add_library(emc_usb_vendor_celeno_cli_host)

  target_include_directories(emc_usb_vendor_celeno_cli_host PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

  target_link_libraries(emc_usb_vendor_celeno_cli_host
    PUBLIC
      emc_usb_vendor_celeno_cli
      emc_usb_vendor_celeno_host
    PRIVATE
      emc_usb_host_hal
    )
endif()

if(EMC_TEST)
  add_library(emc_usb_vendor_celeno_cli_test)

  target_include_directories(emc_usb_vendor_celeno_cli_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

  target_link_libraries(emc_usb_vendor_celeno_cli_test
    PUBLIC
      emc_usb_vendor_celeno_cli_host
      emc_usb_host_hal
      emc_usb_test
  )

  target_sources(emc_usb_vendor_celeno_cli_test PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../eme/empty.c
  )

  # just a compile-time variant of emc_usb_vendor_celeno_cli_test_ 
  add_library(emc_usb_vendor_celeno_cli_test_graybox)
  target_link_libraries(emc_usb_vendor_celeno_cli_test_graybox
    PUBLIC
      emc_usb_vendor_celeno_cli_test
  )
  target_sources(emc_usb_vendor_celeno_cli_test_graybox PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../eme/empty.c
  )
endif()

target_sources(emc_usb_vendor_celeno_cli PRIVATE
  Version.c
  Command.c
  Response.c
  CommandId.c
)

if(EMC_PRINT)
  target_sources(emc_usb_vendor_celeno_cli PRIVATE
    Status.c
    CommandPrint.c
    ResponsePrint.c
  )
endif()

if(EMC_USB_ROLE_DEVICE)
  add_subdirectory(device)
endif()
if(EMC_USB_ROLE_HOST)
  add_subdirectory(host)
endif()
if(EMC_TEST)
  add_subdirectory(test)
endif()
