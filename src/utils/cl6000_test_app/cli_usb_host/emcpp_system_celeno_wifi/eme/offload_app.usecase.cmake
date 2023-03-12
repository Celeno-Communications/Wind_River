set(EMC_USB_VENDOR_CELENO_UMAC_APP "offload" CACHE STRING "Offload App")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_ID "4" CACHE STRING "Offload App ID")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_VERSION "3" CACHE STRING "Offload App Version")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID "0" CACHE STRING "Offload App Build ID")

set(EMC_VENDOR_CELENO_USB_IF_COUNT 5 CACHE STRING "" FORCE)
set(EMC_USB_VENDOR_CELENO_HAS_WIFI_FUNCTION OFF CACHE STRING "" FORCE)
set(EMC_USB_VENDOR_CELENO_HAS_ECM_FUNCTION ON CACHE STRING "" FORCE)
#set(EMC_USB_CLASS_CDC_ECM_LOOPBACK ON CACHE STRING "")
set(EMC_USB_CLASS_CDC_ECM_FREERTOS  ON CACHE STRING "")

eme_add_prerequisites(
  emcpp_system_celeno_wifi
  emc_vendor_celeno
  emc_usb_vendor_celeno_cli
  emc_usb_vendor_celeno_wifi
  emc_usb_class_bluetooth
  emc_usb_class_cdc_ecm
)

include("emcpp_system_celeno_wifi/eme/freertos.cmake")
set(FREERTOS_CONFIG_FILE_DIRECTORY ${CMAKE_SOURCE_DIR}/emcpp_system_celeno_wifi/inc/emc/system/celeno/device/application/offload CACHE STRING "")

set(EMC_STD_ATOMIC     "PSEUDO" CACHE STRING "" FORCE)

set(EMCPP_SINGLETON_GUARD "NO" CACHE STRING "")

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

set(EMC_USB_DEVICE_HAL_EMC_DRIVER_IO_REQUEST_POOL_SIZE "32" CACHE STRING "")
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

set(FREERTOS_PLUS_TCP_CONFIG_FILE_DIRECTORY ${CMAKE_SOURCE_DIR}/emcpp_system_celeno_wifi/inc/emc/system/celeno/device/offload CACHE STRING "" )
if (NOT ${FREERTOS_PLUS_TCP_CONFIG_FILE_DIRECTORY} STREQUAL "")
  eme_add_prerequisites(external_freertos_plus_tcp)

  set(FREERTOS_PLUS_TCP_NET_IF "extern" CACHE STRING "")
  option(FREERTOS_PLUS_TCP_STATIC_BUFFERS "" ON)
  #option(FREERTOS_PLUS_TCP_IPV6 "" ON)
endif()

#set(MBEDTLS_CONFIG_FILE ${CMAKE_SOURCE_DIR}/emcpp_system_celeno_wifi/inc/emc/system/celeno/device/application/offload/mbedtls_config.h CACHE STRING "")
if (NOT ${MBEDTLS_CONFIG_FILE} STREQUAL "")
  eme_add_prerequisites(external_mbedtls)
endif()

option (SHARKSSL_ENABLE "" OFF)
option (WOLFSSL_ENABLE "" OFF)
