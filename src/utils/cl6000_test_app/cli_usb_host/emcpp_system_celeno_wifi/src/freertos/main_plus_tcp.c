/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "external/freertos_plus_tcp/FreeRTOS_IP_wrap.h"

/* The MAC address array is not declared const as the MAC address will
   normally be read from an EEPROM and not hard coded (in real deployed
   applications).*/
static uint8_t ucMACAddress[6] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55 };

/* Define the network addressing.  These parameters will be used if either
   ipconfigUDE_DHCP is 0 or if ipconfigUSE_DHCP is 1 but DHCP auto configuration
   failed. */
static const uint8_t ucIPAddress[4] = { 10, 10, 10, 200 };
static const uint8_t ucNetMask[4] = { 255, 0, 0, 0 };
static const uint8_t ucGatewayAddress[4] = { 10, 10, 10, 1 };

/* The following is the address of an OpenDNS server. */
static const uint8_t ucDNSServerAddress[4] = { 208, 67, 222, 222 };

int main(void)
{
  /* Initialise the RTOS's TCP/IP stack.  The tasks that use the network
     are created in the vApplicationIPNetworkEventHook() hook function
     below.  The hook function is called when the network connects. */
  FreeRTOS_IPInit(ucIPAddress,
                  ucNetMask,
                  ucGatewayAddress,
                  ucDNSServerAddress,
                  ucMACAddress);

  /*
   * Other RTOS tasks can be created here.
   */

  /* Start the RTOS scheduler. */
  vTaskStartScheduler();

  /* If all is well, the scheduler will now be running, and the following
     line will never be reached.  If the following line does execute, then
     there was insufficient FreeRTOS heap memory available for the idle and/or
     timer tasks to be created. */
  for (;;) {}
}

void vApplicationTickHook()
{}

BaseType_t xApplicationGetRandomNumber(uint32_t* pulNumber)
{
  *pulNumber = 0;

  return pdTRUE;
}

uint32_t ulApplicationGetNextSequenceNumber(uint32_t ulSourceAddress,
                                            uint16_t usSourcePort,
                                            uint32_t ulDestinationAddress,
                                            uint16_t usDestinationPort)
{
  (void)ulSourceAddress;
  (void)usSourcePort;
  (void)ulDestinationAddress;
  (void)usDestinationPort;

  return 0;
}

#if ipconfigUSE_NETWORK_EVENT_HOOK
void vApplicationIPNetworkEventHook(eIPCallbackEvent_t eNetworkEvent)
{
  (void)eNetworkEvent;
}

#endif

#if ipconfigUSE_DHCP
eDHCPCallbackAnswer_t xApplicationDHCPHook(eDHCPCallbackPhase_t eDHCPPhase, uint32_t ulIPAddress)
{
  (void)eDHCPPhase;
  (void)ulIPAddress;

  return eDHCPUseDefaults;
}

#endif

#if ipconfigDHCP_REGISTER_HOSTNAME
const char* pcApplicationHostnameHook(void)
{
  return "";
}

#endif

#if ipconfigSUPPORT_OUTGOING_PINGS
void vApplicationPingReplyHook(ePingReplyStatus_t eStatus, uint16_t usIdentifier)
{
  (void)eStatus;
  (void)usIdentifier;
}

#endif

#if FREERTOS_PLUS_TCP_STATIC_BUFFERS
void vNetworkInterfaceAllocateRAMToBuffers(
  NetworkBufferDescriptor_t xDescriptors[ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS])
{
  (void)xDescriptors;
}

#endif
