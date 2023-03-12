add_library(emc_usb_host_hal_libusb)

target_include_directories(emc_usb_host_hal_libusb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(emc_usb_host_hal_libusb
  PUBLIC
    emc_usb_host_hal
    usb-1.0
    pthread
)

add_subdirectory(src)
