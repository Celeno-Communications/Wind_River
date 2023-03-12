
option(EMC_USB_VENDOR_CLASS_CELENO_ISO "" TRUE)
set(EMC_VENDOR_CELENO_USB_IF_COUNT 1 CACHE STRING "")
set(EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM "VIRTUAL" CACHE STRING "")
set(EMC_STD "EMULATE" CACHE STRING "")

eme_add_prerequisites(
  emcpp_system_celeno_wifi
  emc_usb_device
  emc_usb_descriptor
  emc_usb_vendor_iso
  )

include("emcpp_system_celeno_wifi/eme/std.cmake")

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  # this is only linked, if a uio target is compiled
  eme_add_prerequisites(emc_arch_linux_uio)
endif()
  
set(EMC_USB_DEVICE_HAL_EMC_DRIVER_IO_REQUEST_POOL_SIZE "4" CACHE STRING "")
set(EMC_USB_DEVICE_HAL_MAX_EP "4" CACHE STRING "")
set(EMC_USB_DRIVER_DWC3_MAX_ENDPOINT_DRIVER "4" CACHE STRING "")
set(EMC_USB_DRIVER_DWC3_NUMBER_ENDPOINT_ISO "2" CACHE STRING "")
option(EMC_USB_DRIVER_EP_CONTINUOUS_CHANNEL_SUPPORTED "" TRUE)
include("emcpp_system_celeno_wifi/eme/usb_dev.cmake")

option(PROJECT_BUILD_DEBUG "" TRUE)
include("emcpp_system_celeno_wifi/eme/debug.cmake")
