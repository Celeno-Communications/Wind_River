/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "external/freertos_plus_tcp/FreeRTOS_IP_wrap.h"

struct xNetworkInterface* pxFillInterfaceDescriptor(BaseType_t xEMACIndex, struct xNetworkInterface* pxInterface)
{
  (void)xEMACIndex;
  (void)pxInterface;

  return 0;
}

struct xNetworkEndPoint* FreeRTOS_FindEndPointOnIP_IPv6(const IPv6_Address_t* pxIPAddress)
{
  (void)pxIPAddress;

  return 0;
}
