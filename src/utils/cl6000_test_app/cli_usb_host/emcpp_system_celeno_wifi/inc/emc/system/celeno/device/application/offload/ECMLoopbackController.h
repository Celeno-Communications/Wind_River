/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_ECMLoopbackController_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_ECMLoopbackController_H

#include "emc/system/celeno/device/application/TestControlStatus.h"
#include "emc/usb/class/cdc/ecm/device/Loopback.h"

/** The configuration values for a ECM loop controller */
typedef struct EMC_CELENO_ECM_LoopbackCtrlConfig_s {
  CelenoTestCase*                 test;
  CelenoTestStatus*               status;
  EMC_USB_CLASS_CDC_ECM_Loopback* loopback;
} EMC_CELENO_ECM_LoopbackCtrlConfig;

typedef struct EMC_USB_CLASS_CDC_ECM_LoopbackCtrl_s {
  EMC_CELENO_ECM_LoopbackCtrlConfig config;
} EMC_USB_CLASS_CDC_ECM_LoopbackCtrl;

/** Initialize the USB CDC/ECM loopback ctrl module @param self */
void EMC_USB_CLASS_CDC_ECM_loopback_ctrl_init(EMC_USB_CLASS_CDC_ECM_LoopbackCtrl* self,
                                              EMC_CELENO_ECM_LoopbackCtrlConfig* ecm_ctrl_config);

/** Poll the USB CDC/ECM loopback ctrl module @param self */
void EMC_USB_CLASS_CDC_ECM_loopback_ctrl_poll(EMC_USB_CLASS_CDC_ECM_LoopbackCtrl* self);

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_ECMLoopbackController_H */
