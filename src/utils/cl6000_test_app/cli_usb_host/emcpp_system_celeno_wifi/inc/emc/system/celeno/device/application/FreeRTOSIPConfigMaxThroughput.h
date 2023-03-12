/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_FreeRTOSIPConfigMaxThroughput_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_FreeRTOSIPConfigMaxThroughput_H

#ifdef ipconfigUSE_TCP_WIN
#  undef ipconfigUSE_TCP_WIN
#endif
#define ipconfigUSE_TCP_WIN (1)

#ifdef ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS
#  undef ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS
#endif
#define ipconfigNUM_NETWORK_BUFFER_DESCRIPTORS (32)

#ifdef ipconfigNETWORK_MTU
#  undef ipconfigNETWORK_MTU
#endif
#define ipconfigNETWORK_MTU (1526)

#ifdef ipconfigTCP_MSS
#  undef ipconfigTCP_MSS
#endif
#define ipconfigTCP_MSS (1460)

#ifdef ipconfigTCP_TX_BUFFER_LENGTH
#  undef ipconfigTCP_TX_BUFFER_LENGTH
#endif
#define ipconfigTCP_TX_BUFFER_LENGTH (16 * ipconfigTCP_MSS)

#ifdef ipconfigTCP_RX_BUFFER_LENGTH
#  undef ipconfigTCP_RX_BUFFER_LENGTH
#endif
#define ipconfigTCP_RX_BUFFER_LENGTH (16 * ipconfigTCP_MSS)

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_FreeRTOSIPConfigMaxThroughput_H */
