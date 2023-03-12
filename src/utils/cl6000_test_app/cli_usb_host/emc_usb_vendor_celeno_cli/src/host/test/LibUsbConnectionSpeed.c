/**
 * @file
 * @brief   Return USB Speed for libusb-device with VID/PID
 * @author  <ralf.oberlaender@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "libusb-1.0/libusb.h"
#include "emc/std/stdio.h"
#include "emc/std/stdlib.h"

static const char* get_usb_speed(uint16_t vid, uint16_t pid)
{
  libusb_context*       context = EMC_STD_NULL;
  libusb_device_handle* handle = EMC_STD_NULL;
  libusb_device*        device = EMC_STD_NULL;
  const char*           result = EMC_STD_NULL;

  libusb_init(&context);
  handle = libusb_open_device_with_vid_pid(context, vid, pid);

  if (handle == EMC_STD_NULL) {
    libusb_exit(context);
    return EMC_STD_NULL;
  }

  device = libusb_get_device(handle);
  if (device == EMC_STD_NULL) {
    libusb_close(handle);
    libusb_exit(context);
    return EMC_STD_NULL;
  }

  switch (libusb_get_device_speed(device)) {
  case LIBUSB_SPEED_LOW:
    result = "LS";
    break;
  case LIBUSB_SPEED_FULL:
    result = "FS";
    break;
  case LIBUSB_SPEED_HIGH:
    result = "HS";
    break;
  case LIBUSB_SPEED_SUPER:
    result = "SS";
    break;
  default:
    result = "??";
    break;
  }

  libusb_close(handle);
  libusb_exit(context);

  return result;
}

int main(int argc, char* argv[])
{
  uint16_t    vid = 0;
  uint16_t    pid = 0;
  const char* speed = 0;

  if (argc < 3) {
    fprintf(stderr, "\nUsage:  LibUsbConnectionSpeed VID PID\n");
    return 1;
  }
  vid = (uint16_t)strtoul(argv[1], 0, 0);
  pid = (uint16_t)strtoul(argv[2], 0, 0);
  fprintf(stderr, "Checking speed for libusb device VID=0x%04x PID=0x%04x .... ", vid, pid);

  speed = get_usb_speed(vid, pid);
  if (speed) {
    fprintf(stderr, "speed=%s.\n", speed);
    return 0;
  } else {
    fprintf(stderr, "device not found.\n");
    return 2;
  }
}
