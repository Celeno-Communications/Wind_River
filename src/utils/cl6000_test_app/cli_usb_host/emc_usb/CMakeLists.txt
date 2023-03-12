message(STATUS "")
message(STATUS "emc_usb                      Description                    Value")
message(STATUS "---------------------------- ------------------------------ -----")
message(STATUS "[EMC_USB_MAX_SPEED] ........ USB Max Speed ................ <${EMC_USB_MAX_SPEED}>")
message(STATUS "[EMC_USB_LOG_LEVEL] ........ Log Level .................... <${EMC_USB_LOG_LEVEL}>")
message(STATUS "[EMC_USB_ROLE_DEVICE] ...... USB Device Functionality ..... <${EMC_USB_ROLE_DEVICE}>")
message(STATUS "[EMC_USB_ROLE_HOST] ........ USB Host Functionality ....... <${EMC_USB_ROLE_HOST}>")

configure_file(eme/cmakeConfigure.h.in cmakeConfigure.h)

add_subdirectory(src)
