/**
 * @file
 * @brief     Compute SerialNumber string from unique chip id
 * @author    Ralf Oberländer <ralf.oberlaender@emsys.de>
 * @copyright 2021 emsys Embedded Systems GmbH
 */

#include "emc/vendor/celeno/device/usb/descriptor/UniqueChipId.h"
#include "emc/usb/descriptor/Descriptor.h"
#include "emc/vendor/celeno/device/Otp.h"
#include "emc/vendor/celeno/device/MiscReg.h"
#include "emc/log/log.h"
#include "emc/std/string.h"
#include "emc/std/ext/ct_assert.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_VENDOR_CELENO_LOG_LEVEL);

static emc_std_uint8_t serialNumberStringDescriptor[34];

static uint32_t get_id32_0()
{
  emc_std_uint32_t value = 0xaddeadde;
  EMC_USB_CELENO_OTP_read(0xBE, &value);
  return value;
}

static uint32_t get_id32_1()
{
  emc_std_uint32_t value = 0xaddeadde;
  EMC_USB_CELENO_OTP_read(0xBF, &value);
  return value;
}

static uint8_t nibble_to_char(uint8_t nibble)
{
  if (nibble <= 9) {
    return (uint8_t)('0' + nibble);
  } else if (nibble <= 0xF) {
    return (uint8_t)('A' + nibble - 10);
  } else {
    return '?';
  }
}

/*
 * According to SW-Spec the SerialNumber format is:
 * “%02x%02x%02x%02x%02x%02x%02x%02x”
 * Chip Revision A0:
 *    <= id_0[7:0], id_0[15:8], id_0[23:16], id_0[31:24],
 *       id_1[7:0], id_1[15:8], id_1[23:16], id_1[31:24]
 * Chip Revision B0:
 *    <= id_1[31:24], id_1[23:16], id_1[15:8], id_1[7:0]
 *       id_0[31:24], id_0[23:16], id_0[15:8], id_0[7:0]
 */

static void update_string_descriptor()
{
  emc_std_uint32_t id;
  emc_std_uint8_t* p;
  emc_std_int32_t  inc;
  emc_std_uint8_t* v;

  emc_std_memset(serialNumberStringDescriptor, 0, sizeof(serialNumberStringDescriptor));
  serialNumberStringDescriptor[0] = sizeof(serialNumberStringDescriptor);
  serialNumberStringDescriptor[1] = EMC_USB_StringDescriptor_TYPE;
  if (EMC_USB_CELENO_STEP_A == EMC_USB_CELENO_chip_version_step()) {
    // fill string forwards
    p = &serialNumberStringDescriptor[2];
    inc = 4;
  } else {
    // fill string backwards
    p = &serialNumberStringDescriptor[sizeof(serialNumberStringDescriptor) - 4];
    inc = -4;
  }

  EMC_LOG2(EMC_Log_logger("emc.usb.dev.cli"), INFO, "UniqueChipId 0x%08x%08x", get_id32_1(), get_id32_0());

  id = get_id32_0();
  v = (emc_std_uint8_t*)&id;
  for (emc_std_uint8_t i = 0; i < 4; i++) {
    p[0] = nibble_to_char(emc_slice32(emc_std_uint8_t, 7, 4, *v));
    p[2] = nibble_to_char(emc_slice32(emc_std_uint8_t, 3, 0, *v));
    p += inc;
    v++;
  }

  id = get_id32_1();
  v = (emc_std_uint8_t*)&id;
  for (emc_std_uint8_t i = 0; i < 4; i++) {
    p[0] = nibble_to_char(emc_slice32(emc_std_uint8_t, 7, 4, *v));
    p[2] = nibble_to_char(emc_slice32(emc_std_uint8_t, 3, 0, *v));
    p += inc;
    v++;
  }

  p = &serialNumberStringDescriptor[2];
  EMC_LOG(EMC_Log_logger("emc.usb.dev.cli"), TRACE, "SerialNumberString:");
  EMC_LOG4(EMC_Log_logger("emc.usb.dev.cli"), TRACE, "  %c %c %c %c", p[0], p[2], p[4], p[6]);
  EMC_LOG4(EMC_Log_logger("emc.usb.dev.cli"), TRACE, "  %c %c %c %c", p[8], p[10], p[12], p[14]);
  EMC_LOG4(EMC_Log_logger("emc.usb.dev.cli"), TRACE, "  %c %c %c %c", p[16], p[18], p[20], p[22]);
  EMC_LOG4(EMC_Log_logger("emc.usb.dev.cli"), TRACE, "  %c %c %c %c", p[24], p[26], p[28], p[30]);

}

const EMC_USB_StringDescriptor* EMC_USB_CELENO_compute_serial_number()
{
  EMC_CT_ASSERT(sizeof(serialNumberStringDescriptor) == 34);
  update_string_descriptor();
  return (const EMC_USB_StringDescriptor*)serialNumberStringDescriptor;
}
