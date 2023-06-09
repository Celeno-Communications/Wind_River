set(EMC_VENDOR_CELENO_LOG_LEVEL ${EMC_LOG_LEVEL} CACHE STRING "")
set_property(CACHE EMC_VENDOR_CELENO_LOG_LEVEL PROPERTY STRINGS "TRACE" "DEBUG" "INFO" "WARN" "ERROR" "FATAL" "OFF")

set(EMC_VENDOR_CELENO_USB_IF_COUNT 1 CACHE STRING "Number of USB interfaces provided by the UMAC APP")

set(EMC_VENDOR_CELENO_ASIC_STEPPING 0x4130 CACHE STRING "Supported ASIC version")
set_property(CACHE EMC_VENDOR_CELENO_ASIC_STEPPING PROPERTY STRINGS "0x4130" "0x4230" )
