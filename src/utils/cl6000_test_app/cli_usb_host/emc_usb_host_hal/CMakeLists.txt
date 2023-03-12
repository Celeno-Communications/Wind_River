add_library(emc_usb_host_hal INTERFACE)

target_include_directories(emc_usb_host_hal INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(emc_usb_host_hal
  INTERFACE
    emc_usb
    emc_log
    emc_std
)
