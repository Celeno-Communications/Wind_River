/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_FreeRTOSIPConfig_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_FreeRTOSIPConfig_H

#include "external/freertos_plus_tcp/FreeRTOSIPConfig_AllDisabled.h"

#define FREERTOSIP_INCLUDE_ICMP 0
#define FREERTOSIP_INCLUDE_DNS 0
#define FREERTOSIP_INCLUDE_DHCP 0
#define FREERTOSIP_INCLUDE_IPV6_RA 0

#ifdef ipconfigUSE_TCP
#  undef ipconfigUSE_TCP
#endif
#define ipconfigUSE_TCP (1)

#if FREERTOSIP_INCLUDE_ICMP

#  ifdef ipconfigREPLY_TO_INCOMING_PINGS
#    undef ipconfigREPLY_TO_INCOMING_PINGS
#  endif
#  define ipconfigREPLY_TO_INCOMING_PINGS (1)

#  ifdef ipconfigSUPPORT_OUTGOING_PINGS
#    undef ipconfigSUPPORT_OUTGOING_PINGS
#  endif
#  define ipconfigSUPPORT_OUTGOING_PINGS (1)

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

#if FREERTOSIP_INCLUDE_DHCP

#  if defined(ipconfigUSE_IPv6) && (ipconfigUSE_IPv6 == 1)

#    if FREERTOSIP_INCLUDE_IPV6_RA
#      ifdef ipconfigUSE_RA
#        undef ipconfigUSE_RA
#      endif
#      define ipconfigUSE_RA (1)

#    else
#      ifdef ipconfigUSE_DHCPv6
#        undef ipconfigUSE_DHCPv6
#      endif
#      define ipconfigUSE_DHCPv6 (1)
#    endif

#  endif

#  ifdef ipconfigUSE_DHCP
#    undef ipconfigUSE_DHCP
#  endif
#  define ipconfigUSE_DHCP (1)

#  ifdef ipconfigDHCP_FALL_BACK_AUTO_IP
#    undef ipconfigDHCP_FALL_BACK_AUTO_IP
#  endif
#  define ipconfigDHCP_FALL_BACK_AUTO_IP (1)

#endif

#ifdef ipconfigCOMPATIBLE_WITH_SINGLE
#  undef ipconfigCOMPATIBLE_WITH_SINGLE
#endif
#define ipconfigCOMPATIBLE_WITH_SINGLE (0)

// fix compile errors on IPv6 branch by disabling inline keyord and rely on compiler inlining for now
#ifdef portINLINE
#  undef portINLINE
#endif
#define portINLINE

#include "FreeRTOSIPConfigMaxThroughput.h"
//#include "FreeRTOSIPConfigMinRam.h"

#endif
