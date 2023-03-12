/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_FreeRTOSIPConfig_H
#define EMC_SYSTEM_CELENO_FreeRTOSIPConfig_H

#include "external/freertos_plus_tcp/FreeRTOSIPConfig_AllDisabled.h"

#ifdef ipconfigUSE_TCP
#  undef ipconfigUSE_TCP
#endif
#define ipconfigUSE_TCP (1)

#endif
