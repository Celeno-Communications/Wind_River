eme_add_prerequisites(emc_std_ext)
eme_add_prerequisites(emc_system)
if (EMC_USB_ROLE_DEVICE)
  eme_add_prerequisites(emc_usb_descriptor)
endif()

string(TOUPPER ${EMC_VENDOR_CELENO_LOG_LEVEL} EMC_USB_VENDOR_CELENO_LOG_LEVEL_UPPERCASE)
