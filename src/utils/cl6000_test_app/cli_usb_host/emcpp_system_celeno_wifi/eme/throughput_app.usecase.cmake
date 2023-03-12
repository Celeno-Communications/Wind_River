set(EMC_USB_VENDOR_CELENO_UMAC_APP "throughput" CACHE STRING "Throughput App")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_ID "3" CACHE STRING "Throughput App ID")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_VERSION "12" CACHE STRING "Throughput App Version")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID "0" CACHE STRING "Throughput App Build ID")
set(EMC_VENDOR_CELENO_USB_IF_COUNT 2 CACHE STRING "")

eme_add_prerequisites(
  emcpp_system_celeno_wifi
  emc_vendor_celeno
  emc_usb_vendor_celeno_cli
  emc_usb_vendor_celeno_wifi
)
list(APPEND ALL_LIBRARIES_EXCLUDE_TARGETS "emc_usb_vendor_celeno_cli_device_descriptor")

option(EMC_USB_VENDOR_CELENO_HAS_WIFI_FUNCTION "UMAC APP provides vendor-specific Wifi function" ON)

include("emcpp_system_celeno_wifi/eme/std.cmake")

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  # this is only linked, if a uio target is compiled
  eme_add_prerequisites(
    emc_arch_linux_uio
    external_popt
    )
endif()

if (CMAKE_SYSTEM_NAME STREQUAL "Generic")
  include("emcpp_system_celeno_wifi/eme/xtensa.cmake")
  set(EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM "DIRECT" CACHE STRING "")
else()
  set(EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM "VIRTUAL" CACHE STRING "")
endif()

set(EMC_USB_DEVICE_HAL_EMC_DRIVER_IO_REQUEST_POOL_SIZE "8" CACHE STRING "")
option(EMC_USB_DEVICE_HAL_EMC_DRIVER_IO_REQUEST_POOL_PER_DATA_EP "" FALSE)
set(EMC_USB_DEVICE_HAL_MAX_EP "32" CACHE STRING "")
set(EMC_USB_DRIVER_DWC3_MAX_ENDPOINT_DRIVER "32" CACHE STRING "")
option(EMC_USB_DRIVER_EP_SHARED_BUFFER_SUPPORTED "" TRUE)
include("emcpp_system_celeno_wifi/eme/usb_dev.cmake")

option(PROJECT_BUILD_DEBUG "" TRUE)
include("emcpp_system_celeno_wifi/eme/debug.cmake")
