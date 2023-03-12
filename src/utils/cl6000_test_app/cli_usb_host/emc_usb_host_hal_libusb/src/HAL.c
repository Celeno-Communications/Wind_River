/**
 * @file
 * @brief   libusb based HAL implementation
 * @author  <guenter.hiledbrandt@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#include "emc/usb/host/hal/HAL.h"

#include "libusb-1.0/libusb.h"

#include "emc/std/assert.h"
#include "emc/std/string.h"

#define MAX_ENDPOINT 32
#define MAX_INTERFACE 1

typedef struct DeviceContext DeviceContext;

struct EMC_USB_HOST_HAL_Interface {
  emc_std_uint8_t  number;
  emc_std_uint16_t vid;
  emc_std_uint16_t pid;
  emc_std_uint16_t bcd_device;
  uint8_t          sn[256];
};

typedef struct EMC_USB_HOST_HAL_Endpoint {
  DeviceContext* device;
  uint8_t        endpoint_number;
  unsigned int   timeout_ms;
} EMC_USB_HOST_HAL_Endpoint;

struct DeviceContext {
  libusb_context*           ctx;
  libusb_device**           all_devices;
  libusb_device_handle*     dev;
  int                       interface_number;
  int                       interface_claimed;
  EMC_USB_HOST_HAL_Endpoint out;
  EMC_USB_HOST_HAL_Endpoint in;
};

typedef struct HostContext {
  DeviceContext              device;
  EMC_USB_HOST_HAL_Interface interface[MAX_INTERFACE];
  EMC_USB_HOST_HAL_Endpoint  endpoint[MAX_ENDPOINT];
} HostContext;

static HostContext mg_host;

#if 0

static int EMC_USB_HOST_HAL_Endpoint_reset(EMC_USB_HOST_HAL_Endpoint* self)
{
  return libusb_clear_halt(self->device->dev, self->endpoint_number);
}

#endif

static void DeviceContext_close(DeviceContext* self);

static EMC_USB_HOST_HAL_Error convert_libusb_error(int error)
{
  EMC_USB_HOST_HAL_Error result;
  if (error == LIBUSB_SUCCESS) {
    result = EMC_USB_HOST_HAL_Error_NONE;
  } else if (error == LIBUSB_ERROR_TIMEOUT) {
    result = EMC_USB_HOST_HAL_Error_TIMEOUT;
  } else {
    result = EMC_USB_HOST_HAL_Error_INVALID_PARAMETER;
  }
  return result;
}

static libusb_device_handle* select_device(libusb_device** all_devices,
                                           ssize_t num_devices,
                                           uint16_t vendor_id,
                                           uint16_t product_id,
                                           uint16_t bcd_device,
                                           const uint8_t* sn)
{
  for (ssize_t i = 0; i < num_devices; ++i) {
    struct libusb_device_descriptor desc;
    int                             status = libusb_get_device_descriptor(all_devices[i], &desc);
    if (status) {
      continue;
    }

    if ((desc.idVendor == vendor_id) && (desc.idProduct == product_id)) {
      if (bcd_device) {
        if (desc.bcdDevice != bcd_device) {
          continue;
        }
      }
      if (sn) {
        if (desc.iSerialNumber) {
          libusb_device_handle* dev_handle;
          libusb_open(all_devices[i], &dev_handle);
          if (dev_handle) {
            unsigned char dev_sn[256];
            status = libusb_get_string_descriptor_ascii(dev_handle, desc.iSerialNumber, dev_sn, sizeof(dev_sn));
            if (0 == strncmp((const char*)sn, (const char*)dev_sn, sizeof(dev_sn))) {
              return dev_handle;
            } else {
              libusb_close(dev_handle);
            }
          }
        }
      } else {
        libusb_device_handle* dev_handle;
        libusb_open(all_devices[i], &dev_handle);
        if (dev_handle) {
          return dev_handle;
        }
      }
    }
  }
  return 0;
}

static int DeviceContext_open(DeviceContext* self,
                              uint16_t vendor_id,
                              uint16_t product_id,
                              emc_std_uint16_t bcd_device,
                              const uint8_t* sn,
                              int interface_number)
{
  int     status;
  ssize_t num_devices = 0;

  emc_std_memset(self, 0, sizeof(DeviceContext));
  status = libusb_init(&self->ctx);
  if (status) {
    return status;
  }

  num_devices = libusb_get_device_list(self->ctx, &self->all_devices);
  self->dev = select_device(self->all_devices, num_devices, vendor_id, product_id, bcd_device, sn);
  if (self->dev == NULL) {
    DeviceContext_close(self);
    return LIBUSB_ERROR_NO_DEVICE;
  }
  libusb_set_auto_detach_kernel_driver(self->dev, 1);
  self->interface_number = interface_number;
  status = libusb_claim_interface(self->dev, interface_number);
  if (status) {
    DeviceContext_close(self);
    return status;
  }
  self->interface_claimed = 1;
  return status;
}

static void DeviceContext_close(DeviceContext* self)
{
  if (self->dev) {
    if (self->interface_claimed) {
      libusb_release_interface(self->dev, self->interface_number);
    }
    libusb_close(self->dev);
    self->dev = NULL;
  }
  if (self->all_devices) {
    libusb_free_device_list(self->all_devices, 1);
    self->all_devices = NULL;
  }
  if (self->ctx) {
    libusb_exit(self->ctx);
    self->ctx = NULL;
  }
}

uint16_t EMC_USB_HOST_HAL_interface_get_pid(EMC_USB_HOST_HAL_Interface* interface)
{
  return interface->pid;
}

uint16_t EMC_USB_HOST_HAL_interface_get_fw_version(EMC_USB_HOST_HAL_Interface* interface)
{
  return interface->bcd_device;
}

const uint8_t* EMC_USB_HOST_HAL_interface_get_sn(EMC_USB_HOST_HAL_Interface* interface)
{
  return interface->sn;
}

EMC_USB_Speed EMC_USB_HOST_HAL_get_device_speed()
{
  libusb_device* dev = 0;
  if (!mg_host.device.dev) {
    return EMC_USB_Speed_UNDEFINED;
  }
  dev = libusb_get_device(mg_host.device.dev);
  if (!dev) {
    return EMC_USB_Speed_UNDEFINED;
  }
  switch (libusb_get_device_speed(dev)) {
  case LIBUSB_SPEED_LOW: return EMC_USB_Speed_LOW;
  case LIBUSB_SPEED_FULL: return EMC_USB_Speed_FULL;
  case LIBUSB_SPEED_HIGH: return EMC_USB_Speed_HIGH;
  case LIBUSB_SPEED_SUPER: return EMC_USB_Speed_SUPER;
  //case LIBUSB_SPEED_SUPER_PLUS : return EMC_USB_Speed_SUPER_PLUS;
  default: return EMC_USB_Speed_UNDEFINED;
  }
}

EMC_USB_HOST_HAL_Error EMC_USB_HOST_HAL_interface_set_alt_setting(emc_std_uint8_t alt_setting)
{
  int          status;
  HostContext* self = &mg_host;
  status = libusb_set_interface_alt_setting(self->device.dev, self->device.interface_number, alt_setting);
  return convert_libusb_error(status);
}

EMC_USB_HOST_HAL_Error EMC_USB_HOST_HAL_init()
{
  HostContext* self = &mg_host;
  emc_std_memset(self, 0, sizeof(HostContext));

  return EMC_USB_HOST_HAL_Error_NONE;
}

void EMC_USB_HOST_HAL_exit(void)
{
  HostContext* self = &mg_host;
  DeviceContext_close(&self->device);

  emc_std_memset(self, 0, sizeof(HostContext));
}

void EMC_USB_HOST_HAL_isr(void)
{}

EMC_USB_HOST_HAL_Interface* EMC_USB_HOST_HAL_interface_open(emc_std_uint8_t number,
                                                            emc_std_uint16_t vid,
                                                            emc_std_uint16_t pid,
                                                            emc_std_uint16_t bcd_device,
                                                            const emc_std_uint8_t* sn)
{
  int          status;
  HostContext* self = &mg_host;

  status = DeviceContext_open(&self->device, vid, pid, bcd_device, sn, number);
  if (status == 0) {
    struct libusb_device_descriptor device_desc;
    self->interface[0].number = number;
    self->interface[0].vid = vid;
    self->interface[0].pid = pid;
    emc_std_memset(self->interface[0].sn, 0, sizeof(self->interface[0].sn));

    status = libusb_get_device_descriptor(libusb_get_device(self->device.dev), &device_desc);
    self->interface[0].bcd_device = device_desc.bcdDevice;
    if (status) {
      return 0;
    }
    if (device_desc.iSerialNumber) {
      status = libusb_get_string_descriptor_ascii(self->device.dev,
                                                  device_desc.iSerialNumber,
                                                  self->interface[0].sn,
                                                  sizeof(self->interface[0].sn) - 1);
    }

    return &self->interface[0];
  } else {
    return 0;
  }
}

void EMC_USB_HOST_HAL_interface_close(EMC_USB_HOST_HAL_Interface* interface)
{
  UNUSED_PARAM(interface);
}

EMC_USB_HOST_HAL_Endpoint* EMC_USB_HOST_HAL_ep_enable(EMC_USB_EndpointAddress ep_addr,
                                                      EMC_USB_TransferType transfer_type,
                                                      emc_std_uint32_t timeout_ms,
                                                      emc_std_uint16_t* max_packet_size)
{
  EMC_USB_HOST_HAL_Endpoint* endpoint = NULL;
  HostContext*               self = &mg_host;
  int                        res;

  if (transfer_type == EMC_USB_TransferType_BULK) {
    if (EMC_USB_EndpointAddress_is_in(ep_addr)) {
      endpoint = &self->endpoint[EMC_USB_EndpointAddress_number(ep_addr) + 16];
    } else {
      endpoint = &self->endpoint[EMC_USB_EndpointAddress_number(ep_addr)];
    }
  } else {
    endpoint = NULL;
  }

  if (endpoint) {
    endpoint->device = &self->device;
    endpoint->endpoint_number = ep_addr;
    endpoint->timeout_ms = timeout_ms;
    res = libusb_get_max_packet_size(libusb_get_device(self->device.dev), ep_addr);
    if (res < 0) {
      *max_packet_size = 1024;
    } else {
      *max_packet_size = (emc_std_uint16_t)res;
    }
  }

  return endpoint;
}

EMC_USB_HOST_HAL_Error EMC_USB_HOST_HAL_ep_disable(EMC_USB_HOST_HAL_Endpoint* endpoint)
{
  EMC_USB_HOST_HAL_Error error = EMC_USB_HOST_HAL_Error_NONE;
  if (!endpoint) {
    error = EMC_USB_HOST_HAL_Error_INVALID_EP;
  }
  return error;
}

int EMC_USB_HOST_HAL_ep_write(EMC_USB_HOST_HAL_Endpoint* endpoint, const void* buffer, size_t size)
{

  int transferred;
  int status;
  int result;

  if (endpoint) {
    status = libusb_bulk_transfer(endpoint->device->dev,
                                  endpoint->endpoint_number,
                                  (void*)buffer,
                                  (int)size,
                                  &transferred,
                                  endpoint->timeout_ms);
    if (status == 0) {
      result = transferred;
    } else {
      result = convert_libusb_error(status);
    }
  } else {
    result = EMC_USB_HOST_HAL_Error_INVALID_EP;
  }
  return result;
}

int EMC_USB_HOST_HAL_ep_read(EMC_USB_HOST_HAL_Endpoint* endpoint, void* buffer, size_t size)
{
  int transferred;
  int status;
  int result;
  if (endpoint) {
    status = libusb_bulk_transfer(endpoint->device->dev,
                                  endpoint->endpoint_number,
                                  buffer,
                                  (int)size,
                                  &transferred,
                                  endpoint->timeout_ms);
    if (status == 0) {
      result = transferred;
    } else {
      result = convert_libusb_error(status);
    }
  } else {
    result = EMC_USB_HOST_HAL_Error_INVALID_EP;
  }
  return result;
}
