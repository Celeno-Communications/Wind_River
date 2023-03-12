set(EMC_USB_VENDOR_CELENO_UMAC_APP "" CACHE STRING "")
set_property(CACHE EMC_USB_VENDOR_CELENO_UMAC_APP PROPERTY STRINGS "bootloader" "throughput" "runtime" "offload")

set(EMC_USB_VENDOR_CELENO_UMAC_APP_ID "0" CACHE STRING "")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_VERSION "0" CACHE STRING "")
set(EMC_USB_VENDOR_CELENO_UMAC_APP_BUILD_ID "0" CACHE STRING "")

option(EMC_USB_VENDOR_CELENO_HAS_WIFI_FUNCTION "UMAC APP provides vendor-specific Wifi function" ON)
option(EMC_USB_VENDOR_CELENO_HAS_ECM_FUNCTION "UMAC APP provides CDC/ECM function" OFF)

option(BUILD_CLI_HOST  "" OFF)

set(EMCPP_SYSTEM_CELENO_WIFI_CPU_CLK_MHZ 640 CACHE STRING "")
set_property(CACHE EMCPP_SYSTEM_CELENO_WIFI_CPU_CLK_MHZ PROPERTY STRINGS "640" )

set(EMCPP_SYSTEM_CELENO_WIFI_CPU_START_CLK_MHZ 640 CACHE STRING "")
set_property(CACHE EMCPP_SYSTEM_CELENO_WIFI_CPU_START_CLK_MHZ PROPERTY STRINGS "640" "60")

option(EMCPP_SYSTEM_CELENO_WIFI_POST_MORTEM_EXCEPTION "support post mortem debugging" OFF)
