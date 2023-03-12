/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_selibplat_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_selibplat_H

#define NO_BSD_SOCK
#define SOCKET int

static inline int se_connect(int* sock, const char* address, U16 port)
{
  (void)sock;
  (void)address;
  (void)port;

  return 0;
}

static inline void se_close(SOCKET* sock)
{
  (void)sock;
}

static inline S32 se_send(SOCKET* sock, const void* buf, U32 len)
{
  (void)sock;
  (void)buf;

  return (S32)len;
}

static inline S32 se_recv(SOCKET* sock, void* buf, U32 len, U32 timeout)
{
  (void)sock;
  (void)buf;
  (void)len;
  (void)timeout;

  return 0;
}

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_OFFLOAD_selibplat_H */
