add_library(emc_vendor_celeno_device)
add_library(emc_vendor_celeno_device_base)

target_include_directories(emc_vendor_celeno_device
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc/emc/vendor/celeno/device/register/private
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../emc_usb_vendor_celeno_usbwrapper/inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../emcpp_system_celeno_wifi/inc
)

target_include_directories(emc_vendor_celeno_device_base
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../inc
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../emcpp_system_celeno_wifi/inc
)

target_link_libraries(emc_vendor_celeno_device_base
  PUBLIC
    emc_system
  PRIVATE
    emc_std_ext
    emc_log    
)

target_link_libraries(emc_vendor_celeno_device
  PUBLIC
    emc_vendor_celeno_device_base
  PRIVATE
    emc_std_ext
    emc_log    
)

target_sources(emc_vendor_celeno_device_base
  PRIVATE
    Otp.c
    AsicVersion.c
)

target_sources(emc_vendor_celeno_device
  PRIVATE
    WatchDog.c
    RegisterSet.c
    RegisterSetImpl.c
    Tci.c
)

if ((NOT EMC_USB_VENDOR_CELENO_UMAC_APP STREQUAL "pcie"))
  target_sources(emc_vendor_celeno_device
    PRIVATE
      SystemGlobalInit.c
  )
  target_link_libraries(emc_vendor_celeno_device
    PRIVATE
      emc_usb_vendor_celeno_usbwrapper_regs
  )
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "Generic")
  target_sources(emc_vendor_celeno_device_base PRIVATE
    OtpReg.c
    MiscReg.c
  )
  target_link_libraries(emc_vendor_celeno_device
    PRIVATE
      emc_usb_vendor_celeno_usbwrapper_hw
  )
  target_sources(emc_vendor_celeno_device PRIVATE
    Idma.c
    Ipc.c
    TciReg.c
  )
else()
  target_link_libraries(emc_vendor_celeno_device
    PRIVATE
      emc_usb_vendor_celeno_usbwrapper_regs
  )
  target_sources(emc_vendor_celeno_device_base PRIVATE
    OtpRegMock.c
    MiscRegMock.c
  )
  target_sources(emc_vendor_celeno_device PRIVATE
    IdmaMock.c
    IpcMock.c
    TciRegMock.c
  )
endif()

if(EMC_USB_ROLE_DEVICE)
  add_subdirectory(usb)
endif()

if(EMC_TEST)
  add_subdirectory(test)
endif()
