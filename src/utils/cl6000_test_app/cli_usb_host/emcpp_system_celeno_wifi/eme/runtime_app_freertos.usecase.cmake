set(EMC_USB_VENDOR_CELENO_UMAC_APP "runtime_freertos" CACHE STRING "Runtime/FreeRTOS App")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_ID "5" CACHE STRING "Runtime/FreeRTOS App ID")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_VERSION "2" CACHE STRING "Runtime/FreeRTOS App Version")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID "0" CACHE STRING "Runtime/FreeRTOS App Build ID")

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(EMC_STD_TIMESTAMP  "pthreads" CACHE STRING "")
endif()
include("emcpp_system_celeno_wifi/eme/freertos.cmake")

if (NOT FREERTOS_CONFIG_FILE_DIRECTORY)
  set(FREERTOS_CONFIG_FILE_DIRECTORY ${CMAKE_SOURCE_DIR}/emcpp_system_celeno_wifi/inc/emc/system/celeno/device/application/runtime_freertos CACHE STRING "")
endif()  

add_definitions("-DFREERTOS")

include("emcpp_system_celeno_wifi/eme/umac_usb.usecase.cmake")
