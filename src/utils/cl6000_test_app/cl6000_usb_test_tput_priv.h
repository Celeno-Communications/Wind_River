/**
 ****************************************************************************************
 *
 * @file cl6000_usb_test_priv.h
 *
 * @brief CL6000 UMAC USB tput test private test infrastructure.
 *
 * Copyright (C) Emsys/Celeno 2021
 *
 ****************************************************************************************
 */

#ifndef CL6000_USB_TEST_TPUT_PRIV_H_
#define CL6000_USB_TEST_TPUT_PRIV_H_

#include "cl6000_common.h"

enum USBTP_EP {
  EP1_OUT  = 0x01,
  EP2_OUT  = 0x02,
  EP3_OUT  = 0x03,
  EP4_OUT  = 0x04,
  EP5_OUT  = 0x05,
  EP6_OUT  = 0x06,
  EP7_OUT  = 0x07,
  EP8_OUT  = 0x08,
  EP9_OUT  = 0x09,
  EP10_OUT = 0x0A,
  EP11_OUT = 0x0B,
  EP12_OUT = 0x0C,
  EP13_OUT = 0x0D,
  EP14_OUT = 0x0E,
  EP15_OUT = 0x0F,
  EP1_IN   = 0x81,
  EP2_IN   = 0x82,
  EP3_IN   = 0x83,
  EP4_IN   = 0x84,
  EP5_IN   = 0x85,
  EP6_IN   = 0x86,
  EP7_IN   = 0x87,
  EP8_IN   = 0x88,
  EP9_IN   = 0x89,
  EP10_IN  = 0x8A,
  EP11_IN  = 0x8B,
  EP12_IN  = 0x8C,
  EP13_IN  = 0x8D,
  EP14_IN  = 0x8E,
  EP15_IN  = 0x8F
};

static inline uint8_t ep_is_out(enum USBTP_EP ep) {
  if ((uint8_t)ep <= 0x0F) {
    return 1;
  }
  return 0;
}

const char* ep_as_string(enum USBTP_EP ep);

enum USBTP_MODE {
    BULK = 0,
    INT  = 1
};

static inline const char* transfer_mode_as_string(enum USBTP_MODE mode) {
  switch(mode) {
  case BULK:
    return "BULK";
  case INT:
    return "INT";
  default:
    return "unknown mode";
  }
}

enum USBTP_CHECK_DATA {
    NO_DATA_CHECK = 0,
    CHECK_DATA    = 1
};

static inline const char* check_data_as_string(enum USBTP_CHECK_DATA check) {
  switch(check) {
  case NO_DATA_CHECK:
    return "NO_DATA_CHECK";
  case CHECK_DATA:
    return "CHECK_DATA";
  default:
    return "unknown check-mode";
  }
}

enum USBTP_PAYLOAD_SIZE {
    SMALL_PACKETS = 0,
    LARGE_PACKETS = 1
};

static inline const char* payload_size_as_string(enum USBTP_PAYLOAD_SIZE payload_size) {
  switch(payload_size) {
  case SMALL_PACKETS:
    return "SMALL_PACKETS";
  case LARGE_PACKETS:
    return "LARGE_PACKETS";
  default:
    return "unknown payload_size";
  }
}

struct USBTP_TestCase {
    const char*             description;
    float                   tput_min_mbps_ss;
    float                   tput_min_mbps_hs;
    float                   duration;
    enum USBTP_EP           ep;
    enum USBTP_MODE         transfer_mode;
    enum USBTP_PAYLOAD_SIZE payload_size;
    enum USBTP_CHECK_DATA   check_data;
};

#endif // CL6000_USB_TEST_TPUT_PRIV_H_
