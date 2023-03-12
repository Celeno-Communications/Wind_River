/**
 * @file
 * @brief
 * @author  <karsten.pahnke@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_TEST_Pipe_H
#define EMC_USB_TEST_Pipe_H

#include "emc/usb/configure.h"

#include "emc/std/stdint.h"
#include "emc/std/stdlib.h"
#include "emc/std/stdbool.h"

#include "emc/log/log.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The simple fifo like channel for tests
    @ingroup emdoc_emc_usb
 */
typedef struct EMC_USB_Pipe {
  emc_logger_t*    logger;
  emc_std_bool     tx_done;
  emc_std_bool     rx_done;
  size_t           length;
  emc_std_uint8_t* buffer;
  emc_std_uint8_t* tx_insert;
  emc_std_uint8_t* rx_extract;
} EMC_USB_Pipe;

int EMC_USB_Pipe_open(EMC_USB_Pipe* self, void* buffer, size_t length);

int EMC_USB_Pipe_close(EMC_USB_Pipe* self);

int EMC_USB_Pipe_reset(EMC_USB_Pipe* self);

int EMC_USB_Pipe_transmit(EMC_USB_Pipe* self, const void* data, size_t size);

int EMC_USB_Pipe_receive(EMC_USB_Pipe* self, void* data, size_t size);

/** @brief any rx transaction done (also with zero length packet) */
emc_std_bool EMC_USB_Pipe_rx_done(const EMC_USB_Pipe* self);

/** @brief number bytes received */
size_t EMC_USB_Pipe_rx_available(const EMC_USB_Pipe* self);

/** @brief any tx transaction done (also with zero length packet) */
emc_std_bool EMC_USB_Pipe_tx_done(const EMC_USB_Pipe* self);

/** @brief number bytes, which can be placed into pipe */
size_t EMC_USB_Pipe_tx_space(const EMC_USB_Pipe* self);

#if EMC_PRINT
/** Returns the status as string */
void* EMC_USB_Pipe_print(EMC_USB_Pipe* self);
#endif /*EMC_PRINT*/

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_TEST_Transport_H */
