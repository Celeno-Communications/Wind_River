eme_add_prerequisites(emc_usb_host_hal)

find_package(libusb-1)
if (NOT libusb-1_FOUND)
  eme_add_prerequisites(external_libusb-1.0)
endif()