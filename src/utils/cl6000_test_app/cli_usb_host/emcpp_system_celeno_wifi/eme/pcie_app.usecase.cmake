set(EMC_USB_VENDOR_CELENO_UMAC_APP "pcie" CACHE STRING "PCIe App")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_ID "6" CACHE STRING "PCIe App ID")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_VERSION "2" CACHE STRING "PCIe App Version")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID "0" CACHE STRING "PCIe App Build ID")

set(EMC_USB_VENDOR_CELENO_HAS_WIFI_FUNCTION OFF CACHE STRING "")

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(EMC_STD_TIMESTAMP  "pthreads" CACHE STRING "")
endif()

eme_add_prerequisites(emcpp_system_celeno_wifi)
eme_add_prerequisites(emc_vendor_celeno)
eme_add_prerequisites(emc_usb_vendor_celeno_usbwrapper)
list(APPEND ALL_LIBRARIES_EXCLUDE_TARGETS "emc_usb_vendor_celeno_usbwrapper_transport")
eme_add_prerequisites(emc_system)
eme_add_prerequisites(emc_log)
eme_add_prerequisites(emc_std_ext)
eme_add_prerequisites(emc_std)
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  eme_add_prerequisites(emc_arch_linux_uio)
  eme_add_prerequisites(external_popt)
endif()

include("emcpp_system_celeno_wifi/eme/std.cmake")

option(PROJECT_BUILD_DEBUG "" TRUE)
include("emcpp_system_celeno_wifi/eme/debug.cmake")
set(EMC_LOG_INTERNAL_APPENDER_BUFFERED_TRANSPORT_INSTANCES "1" CACHE STRING "")
set(EMC_LOG_INTERNAL_BUFFERED_TRANSPORT_SIZE "1 * 1024" CACHE STRING "")

if (CMAKE_SYSTEM_NAME STREQUAL "Generic")
  include("emcpp_system_celeno_wifi/eme/xtensa.cmake")
endif()
