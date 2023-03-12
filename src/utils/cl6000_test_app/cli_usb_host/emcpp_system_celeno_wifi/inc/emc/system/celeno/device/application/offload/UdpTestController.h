/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/

#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_UdpTestController_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_UdpTestController_H

#include "emc/system/celeno/device/application/TestControlStatus.h"
#include "emc/std/threads.h"
#include "emc/log/log.h"

typedef struct ECM_CELENO_UDPTestController_config_s {
  CelenoTestCase*   test;
  CelenoTestStatus* status;
  uint16_t          port;
} ECM_CELENO_UDPTestController_config;

typedef struct ECM_CELENO_UDPTestController {
  ECM_CELENO_UDPTestController_config config;
  emc_logger_t*                       logger;
  emc_std_thrd_t                      udp_test_service;
  emc_std_bool                        udp_test_service_started;
} ECM_CELENO_UDPTestController;

extern ECM_CELENO_UDPTestController* mg_udp_test_crtl;

void EMC_USB_udp_test_controller_init(ECM_CELENO_UDPTestController* self,
                                      ECM_CELENO_UDPTestController_config* udp_ctrl_config);

void EMC_USB_udp_test_controller_poll(ECM_CELENO_UDPTestController* self);

#endif
