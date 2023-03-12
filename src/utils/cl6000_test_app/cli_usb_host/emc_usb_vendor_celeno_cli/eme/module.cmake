eme_add_prerequisites(emc_std_ext)

if(EMC_USB_ROLE_DEVICE)
  eme_add_prerequisites(emc_usb_device)
endif()
if(EMC_USB_ROLE_HOST)
  eme_add_prerequisites(emc_usb_host_hal)
endif()

if(EMC_TEST)
  if(EMC_USB_ROLE_DEVICE)
    eme_add_prerequisites(emc_usb_host_hal_mock)
  endif()
  if(EMC_USB_ROLE_HOST)
    eme_add_prerequisites(emc_usb_host_hal_libusb)
  endif()
endif()

string(TOUPPER ${EMC_USB_VENDOR_CELENO_CLI_LOG_LEVEL} EMC_USB_VENDOR_CELENO_CLI_LOG_LEVEL_UPPERCASE)
