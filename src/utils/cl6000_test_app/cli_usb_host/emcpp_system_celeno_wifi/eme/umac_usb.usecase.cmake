set(EMC_USB_VENDOR_CELENO_UMAC_APP "runtime" CACHE STRING "Runtime App")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_ID "2" CACHE STRING "Runtime App ID")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_VERSION "13" CACHE STRING "Runtime App Version")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID "0" CACHE STRING "Runtime App Build ID")
set(EMC_VENDOR_CELENO_USB_IF_COUNT 4 CACHE STRING "")

eme_add_prerequisites(
  emcpp_system_celeno_wifi
  emc_vendor_celeno
  emc_usb_vendor_celeno_cli
  emc_usb_vendor_celeno_wifi
  emc_usb_class_bluetooth
)
list(APPEND ALL_LIBRARIES_EXCLUDE_TARGETS "emc_usb_vendor_celeno_cli_device_descriptor")

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
  #set(EMC_CUSTOMER_CONFIG "celeno_wifi" CACHE STRING "" )
  #option(EMC_LOG_SYS_PROFILE "" TRUE)
else()
  set(EMC_USB_VENDOR_CELENO_CLI_TARGET_MEM "VIRTUAL" CACHE STRING "")
endif()

option(EMCPP_SYSTEM_CELENO_WATCHDOG  "support watchdog" ON)
option(EMC_USB_VENDOR_CELENO_USBW_US_FLUSH_HOST_OPTIM "" ON)

#option(EMC_USB_CLASS_BLUETOOTH_SCO_EP_INT "USB Transfer Type for SCO EPs" ON)

option(EMC_USB_VENDOR_CELENO_HAS_WIFI_FUNCTION "UMAC APP provides vendor-specific Wifi function" ON)

set(EMC_USB_DEVICE_HAL_EMC_DRIVER_IO_REQUEST_POOL_SIZE "8" CACHE STRING "")
option(EMC_USB_DEVICE_HAL_EMC_DRIVER_IO_REQUEST_POOL_PER_DATA_EP "" FALSE)
set(EMC_USB_DEVICE_HAL_MAX_EP "24" CACHE STRING "")
set(EMC_USB_DRIVER_DWC3_MAX_ENDPOINT_DRIVER ${EMC_USB_DEVICE_HAL_MAX_EP} CACHE STRING "")
set(EMC_USB_DRIVER_DWC3_NUMBER_ENDPOINT_ISO "2" CACHE STRING "")
option(EMC_USB_DRIVER_EP_CONTINUOUS_CHANNEL_SUPPORTED "" ON)
option(EMC_USB_DRIVER_DWC3_SINGLE_SHOT_EVENT_PROCESSING "" ON)
option(EMC_USB_DRIVER_EP_SHARED_BUFFER_SUPPORTED "" TRUE)
include("emcpp_system_celeno_wifi/eme/usb_dev.cmake")

option(PROJECT_BUILD_DEBUG "" TRUE)
include("emcpp_system_celeno_wifi/eme/debug.cmake")

if (CMAKE_SYSTEM_NAME STREQUAL "Generic")
  bundle_libs(libusb_base.a LIBS
    emc_hw_memory
    emc_log
    emc_std
    emc_std_ext
    emc_std_thread
    external_baisoku_tlsf
    emc_system_celeno_arch
  )

  bundle_libs(libusb.a LIBS
    emc_vendor_celeno_device_base
    emc_usb
    emc_usb_class_bluetooth_device
    emc_usb_descriptor
    emc_usb_device
    emc_usb_device_hal
    emc_usb_device_hal_emc_driver
    emc_usb_driver
    emc_usb_driver_arch
    emc_usb_driver_dwc3
    emc_usb_vendor_celeno_cli
    emc_usb_vendor_celeno_cli_device
    emc_usb_vendor_iso
  )

  bundle_libs(libusb_wifi.a LIBS
    emc_system
    emc_system_celeno_app
    emc_system_celeno_app_logging
    emc_system_celeno_sys
    emc_vendor_celeno_device
    emc_usb_vendor_celeno_usbwrapper_hw
    emc_usb_vendor_celeno_usbwrapper_transport
    emc_usb_vendor_celeno_wifi_runtime
    emc_usb_vendor_celeno_wifi_runtime_descriptor
  )


  bundle_libs(libusb_bootrom.a LIBS
    emc_system_celeno_bootloader
    emc_usb_vendor_celeno_cli_device_descriptor
  )
endif()