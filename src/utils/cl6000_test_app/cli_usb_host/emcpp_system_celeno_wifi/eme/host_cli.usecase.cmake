option(BUILD_CLI_HOST "" TRUE)

set(EMC_LOG "INTERNAL" CACHE STRING "")
set(EMC_LOG_LEVEL "FATAL" CACHE STRING "")
option(EMC_PRINT "" FALSE)
option(EMCPP_TEST "" FALSE)

eme_add_prerequisites( 
  emcpp_system_celeno_wifi
  emc_vendor_celeno
  emc_usb_vendor_celeno_cli
  emc_usb_host_hal_libusb
  emc_log
)

option(EMC_MEMORY_POOL_TYPE_UNCACHED "" FALSE)
option(EMC_HW_PORT_VTBL_MMIO "" FALSE)

# needs to be clarified! the default std will only work for gcc
if (NOT CMAKE_C_COMPILER_ID MATCHES "GNU")
  set(EMC_STD_ATOMIC "NULL" CACHE STRING "")
endif()

option(EMC_TEST "" TRUE)
set(EMC_USB_MAX_SPEED "SUPER" CACHE STRING "")
option(EMC_USB_ROLE_HOST "" TRUE)
