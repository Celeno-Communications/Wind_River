message(STATUS "")
message(STATUS "emc_usb_vendor_celeno_cli              Description                    Value")
message(STATUS "-------------------------------------- ------------------------------ -----")
message(STATUS "[EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM] Target memory implementation . <${EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM}>")
message(STATUS "[EMC_USB_VENDOR_CELENO_CLI_LOG_LEVEL]  Log Level .................... <${EMC_USB_VENDOR_CELENO_CLI_LOG_LEVEL}>")

configure_file(eme/cmakeConfigure.h.in cmakeConfigure.h)

add_subdirectory(src)
