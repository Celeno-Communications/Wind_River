option(LIBUSB_REPO_CACHE "" FALSE)

option(EMC_USB_VENDOR_CLASS_CELENO_ISO_TEST "" TRUE)
option(EMC_USB_ROLE_DEVICE "" TRUE)

eme_add_prerequisites(
  emcpp_system_celeno_wifi
  emc_std
  emc_std_ext
  emc_test
  external_libusb-1.0
  )

set(EMC_STD_TIMESTAMP "std" CACHE STRING "")
include("emcpp_system_celeno_wifi/eme/std.cmake")
option(PROJECT_BUILD_DEBUG "" TRUE)
include("emcpp_system_celeno_wifi/eme/debug.cmake")
