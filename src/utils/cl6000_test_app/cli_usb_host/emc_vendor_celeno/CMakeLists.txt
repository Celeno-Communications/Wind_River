message(STATUS "")
message(STATUS "emc_vendor_celeno                  Description               Value")
message(STATUS "---------------------------------- ------------------------- -----")
message(STATUS "[EMC_VENDOR_CELENO_LOG_LEVEL]..... Log Level ............... <${EMC_VENDOR_CELENO_LOG_LEVEL}>")
message(STATUS "[EMC_VENDOR_CELENO_USB_IF_COUNT].. Number of USB interfaces. <${EMC_VENDOR_CELENO_USB_IF_COUNT}>")
message(STATUS "[EMC_VENDOR_CELENO_ASIC_STEPPING]. Supported ASIC version... <${EMC_VENDOR_CELENO_ASIC_STEPPING}>")

configure_file(eme/cmakeConfigure.h.in cmakeConfigure.h)

add_subdirectory(src)