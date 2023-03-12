if(EMC_USB_ROLE_DEVICE)
  eme_add_prerequisites(emc_usb_device)
  eme_add_prerequisites(emc_usb_device_hal_emc_driver)
  eme_add_prerequisites(emc_usb_driver_dwc3)
endif()

if(EMC_USB_VENDOR_CLASS_CELENO_CLI)
  eme_add_prerequisites(emc_usb_vendor_celeno_cli)
  eme_add_prerequisites(emc_arch_linux_uio)
endif()

if(EMC_USB_VENDOR_CLASS_CELENO_ISO)
  eme_add_prerequisites(emc_usb_vendor_iso)
  eme_add_prerequisites(emc_arch_linux_uio)
endif()

if(EMC_USB_VENDOR_CLASS_CELENO_ISO_TEST)
  eme_add_prerequisites(emc_test)
  eme_add_prerequisites(emc_std_ext)
  eme_add_prerequisites(emc_std)
#    cunit
#    usb-1.0
#    pthread
endif()

