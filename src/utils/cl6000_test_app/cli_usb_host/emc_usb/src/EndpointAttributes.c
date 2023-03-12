#include "emc/usb/EndpointAttributes.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"

static inline void init(EMC_USB_EndpointAttributes* self,
                        EMC_USB_EndpointAddress ep_address,
                        EMC_USB_TransferType transfer_type,
                        emc_std_uint16_t max_packet_size)
{
  emc_std_assert(self);
  emc_std_memset(self, 0, sizeof(EMC_USB_EndpointAttributes));

  self->ep_address = ep_address;
  self->transfer_type = transfer_type;
  self->max_packet_size = max_packet_size;
}

void EMC_USB_EndpointAttributes_init_bulk(EMC_USB_EndpointAttributes* self,
                                          EMC_USB_EndpointAddress ep_address,
                                          emc_std_uint16_t max_packet_size)
{
  init(self, ep_address, EMC_USB_TransferType_BULK, max_packet_size);
}

void EMC_USB_EndpointAttributes_init_isochronous(EMC_USB_EndpointAttributes* self,
                                                 EMC_USB_EndpointAddress ep_address,
                                                 emc_std_uint16_t max_packet_size,
                                                 emc_std_uint8_t polling_interval)
{
  init(self, ep_address, EMC_USB_TransferType_ISOCHRONOUS, max_packet_size);
  self->polling_interval = polling_interval;
}

void EMC_USB_EndpointAttributes_init_interrupt(EMC_USB_EndpointAttributes* self,
                                               EMC_USB_EndpointAddress ep_address,
                                               emc_std_uint16_t max_packet_size,
                                               emc_std_uint8_t polling_interval)
{
  init(self, ep_address, EMC_USB_TransferType_INTERRUPT, max_packet_size);
  self->polling_interval = polling_interval;
}

void EMC_USB_EndpointAttributes_init_control(EMC_USB_EndpointAttributes* self,
                                             EMC_USB_EndpointAddress ep_address,
                                             emc_std_uint16_t max_packet_size)
{
  init(self, ep_address, EMC_USB_TransferType_CONTROL, max_packet_size);
}
