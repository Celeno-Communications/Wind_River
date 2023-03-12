#include "emc/usb/test/Pipe.h"

#include "emc/std/assert.h"
#include "emc/std/string.h"

#include "emc/log/log.h"
#include "emc/log/log_payload.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_USB_LOG_LEVEL);

#define min(a, b) ((a) < (b) ? (a) : (b))

int EMC_USB_Pipe_open(EMC_USB_Pipe* self, void* buffer, size_t length)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, sizeof(EMC_USB_Pipe));

  self->logger = EMC_Log_logger("emc.usb.test.pipe");

  EMC_LOG(self->logger, TRACE, "");

  self->length = length;
  self->buffer = buffer;
  EMC_USB_Pipe_reset(self);
  return 0;
}

emc_std_bool EMC_USB_Pipe_tx_done(const EMC_USB_Pipe* self)
{
  return self->tx_done;
}

emc_std_bool EMC_USB_Pipe_rx_done(const EMC_USB_Pipe* self)
{
  return self->rx_done;
}

size_t EMC_USB_Pipe_rx_available(const EMC_USB_Pipe* self)
{
  return (size_t)(self->tx_insert - self->rx_extract);
}

size_t EMC_USB_Pipe_tx_space(const EMC_USB_Pipe* self)
{
  return (size_t)(self->buffer + self->length - self->tx_insert);
}

int EMC_USB_Pipe_close(EMC_USB_Pipe* self)
{
  EMC_LOG(self->logger, TRACE, "");

  emc_std_assert(self);
  emc_std_memset(self, 0, sizeof(EMC_USB_Pipe));
  return 0;
}

int EMC_USB_Pipe_reset(EMC_USB_Pipe* self)
{
  EMC_LOG(self->logger, TRACE, "");

  emc_std_assert(self);
  self->tx_done = emc_std_false;
  self->rx_done = emc_std_false;
  self->tx_insert = self->buffer;
  self->rx_extract = self->buffer;
  return 0;
}

int EMC_USB_Pipe_transmit(EMC_USB_Pipe* self, const void* data, size_t size)
{
  EMC_LOG2(self->logger, TRACE, "data=%p, size=%d", data, size);

  emc_std_assert(self);
  if (size <= EMC_USB_Pipe_tx_space(self)) {
    if (size > 0) {
      emc_std_memcpy(self->tx_insert, data, size);
      self->tx_insert += size;
      EMC_LOG_PAYLOAD(self->logger, TRACE, data, size);
    }
    self->tx_done = emc_std_true;
    return (int)size;
  } else {
    return -1;
  }
}

int EMC_USB_Pipe_receive(EMC_USB_Pipe* self, void* data, size_t size)
{
  size_t available;
  size_t transferred = 0;

  EMC_LOG2(self->logger, TRACE, "data=%p, size=%d", data, size);

  emc_std_assert(self);

  if (self->tx_done) {
    available = EMC_USB_Pipe_rx_available(self);
    transferred = min(available, size);

    if (transferred > 0) {
      emc_std_memcpy(data, self->rx_extract, transferred);
      self->rx_extract += transferred;
      EMC_LOG_PAYLOAD(self->logger, TRACE, data, transferred);
      if (self->rx_extract == self->tx_insert) {
        // reset to begin to avoid wrapping
        self->tx_insert = self->buffer;
        self->rx_extract = self->buffer;
      }
    }
    self->tx_done = emc_std_false; /* no successfull receive before new transmit */
    self->rx_done = emc_std_true;  /* inform other side on rx done*/
  }

  return (int)transferred;
}
