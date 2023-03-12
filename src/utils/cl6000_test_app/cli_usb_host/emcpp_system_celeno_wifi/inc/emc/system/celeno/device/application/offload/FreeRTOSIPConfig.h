/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_FreeRTOSIPConfig_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_FreeRTOSIPConfig_H

#include "external/freertos_plus_tcp/FreeRTOSIPConfig_AllDisabled.h"

#define FREERTOSIP_INCLUDE_ICMP 1
#define FREERTOSIP_INCLUDE_DNS 0

#ifdef ipconfigUSE_TCP
#  undef ipconfigUSE_TCP
#endif
#define ipconfigUSE_TCP (1)

#ifdef ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS
#  undef ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS
#endif
#define ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS (24)

#ifdef ipconfigNETWORK_MTU
#  undef ipconfigNETWORK_MTU
#endif
#define ipconfigNETWORK_MTU (1500)

#if FREERTOSIP_INCLUDE_ICMP

#  ifdef ipconfigREPLY_TO_INCOMING_PINGS
#    undef ipconfigREPLY_TO_INCOMING_PINGS
#  endif
#  define ipconfigREPLY_TO_INCOMING_PINGS (1)

#  ifdef ipconfigSUPPORT_OUTGOING_PINGS
#    undef ipconfigSUPPORT_OUTGOING_PINGS
#  endif
#  define ipconfigSUPPORT_OUTGOING_PINGS (0)

#endif

#if FREERTOSIP_INCLUDE_DNS

#  ifdef ipconfigUSE_DNS
#    undef ipconfigUSE_DNS
#  endif
#  define ipconfigUSE_DNS (1)

#  ifdef ipconfigUSE_DNS_CACHE
#    undef ipconfigUSE_DNS_CACHE
#  endif
#  define ipconfigUSE_DNS_CACHE (1)

#  ifdef ipconfigDNS_USE_CALLBACKS
#    undef ipconfigDNS_USE_CALLBACKS
#  endif
#  define ipconfigDNS_USE_CALLBACKS (1)

#endif

//#include "../FreeRTOSIPConfigMaxThroughput.h"
//#include "FreeRTOSIPConfigMinRam.h"

#endif
