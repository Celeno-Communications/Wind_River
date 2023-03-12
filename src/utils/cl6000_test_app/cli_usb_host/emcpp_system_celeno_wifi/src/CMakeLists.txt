# the emc_system_celeno specific low level architecture files
add_library(emc_system_celeno_arch)

target_include_directories(emc_system_celeno_arch
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc
)

target_sources(emc_system_celeno_arch PRIVATE
  PhysicalAddress.c
  timer_ext.c
)

target_link_libraries(emc_system_celeno_arch
PUBLIC
  emc_log
  emc_hw
  emc_system
  emc_std_ext
  emc_vendor_celeno_device
)

if(EMC_USB_ROLE_DEVICE)
  target_include_directories(emc_system_celeno_arch
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/../../emc_usb_driver/inc
  )
  if(NOT EMCPP_TEST)
    target_include_directories(emc_system_celeno_arch
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/../../emc_usb_vendor_celeno_usbwrapper/inc
  )
  endif()

  target_sources(emc_system_celeno_arch PRIVATE
    UsbDeviceWait.c
    PortHook.c
  )
endif()

# the emc_system_celeno specific high level system
add_library(emc_system_celeno_sys)

target_include_directories(emc_system_celeno_sys
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../emc_usb_vendor_celeno_usbwrapper/inc
)

target_link_libraries(emc_system_celeno_sys
  PUBLIC
    emc_system
    emc_std
    emc_system_celeno_arch
)

if(NOT EMCPP_TEST)
  if (NOT EMC_USB_ROLE_HOST)
    target_sources(emc_system_celeno_sys
      PRIVATE
        DebugHelper.c
        TestHelper.c
    )
  endif()
endif()

target_sources(emc_system_celeno_sys
PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../../eme/empty.c
)

if(EMC_USB_ROLE_DEVICE)
  target_include_directories(emc_system_celeno_sys
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/../../emc_usb/inc
      ${CMAKE_CURRENT_SOURCE_DIR}/../../emc_usb_driver/inc
      ${CMAKE_CURRENT_SOURCE_DIR}/../../emc_usb_vendor_celeno_cli/inc
  )

  # the emc_system_celeno specific usb device drivers
  add_library(emc_system_celeno_usb INTERFACE)

  target_include_directories(emc_system_celeno_usb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../inc)

  target_link_libraries(emc_system_celeno_usb
  INTERFACE
    emc_usb_device
    emc_usb_driver_dwc3
    emc_usb_device_hal_emc_driver
    emc_std
  )

endif()

if (BUILD_CLI_HOST)
  add_subdirectory(host)
endif()

if(EMC_USB_ROLE_DEVICE OR (EMC_USB_VENDOR_CELENO_UMAC_APP STREQUAL "pcie"))
  add_subdirectory(device)
endif()

if(EMCPP_TEST)
  add_subdirectory(test)
endif()

if (EMC_STD_MUTEX STREQUAL "freertos")
  add_subdirectory(freertos)
endif()
