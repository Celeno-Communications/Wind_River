/**
 * @file
 * @brief   The central configuration of the Host HAL.
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_USB_HOST_HAL_HAL_H
#define EMC_USB_HOST_HAL_HAL_H

#include "emc/usb/host/hal/Error.h"
#include "emc/usb/host/hal/Interface_fwd.h"
#include "emc/usb/host/hal/Endpoint_fwd.h"

#include "emc/usb/EndpointAddress.h"
#include "emc/usb/TransferType.h"
#include "emc/usb/Speed.h"

#include "emc/std/stdint.h"
#include "emc/std/stddef.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/**
 * @brief Initializes a new HAL object.
 *
 * @return The status of the HAL initialization
 */
EMC_USB_HOST_HAL_Error EMC_USB_HOST_HAL_init();

/**
 * @brief Destroys an existing HAL object
 */
void EMC_USB_HOST_HAL_exit(void);

/**
 * @brief USB Interrupt Service Routine
 */
void EMC_USB_HOST_HAL_isr(void);

/**
 * @brief Open a specific USB device interface.
 *
 * @param[in] number The interface number.
 * @param[in] vid The USB VID of the device.
 * @param[in] pid The USB PID of the device.
 * @param[in] bcd_device The USB device device firmware version (bcdDevice, 0 for don't care).
 * @param[in] sn The USB device serial number (optional).
 *
 * @return A pointer to the opened interface or 0 in case of an error.
 */
EMC_USB_HOST_HAL_Interface* EMC_USB_HOST_HAL_interface_open(emc_std_uint8_t number,
                                                            emc_std_uint16_t vid,
                                                            emc_std_uint16_t pid,
                                                            emc_std_uint16_t bcd_device,
                                                            const emc_std_uint8_t* sn);

/**
 * @brief Close a USB device interface (counterpart for EMC_USB_HOST_HAL_interface_open).
 *
 * @param[in] interface The interface pointer.
 */
void EMC_USB_HOST_HAL_interface_close(EMC_USB_HOST_HAL_Interface* interface);

/** returns USB device PID */
uint16_t EMC_USB_HOST_HAL_interface_get_pid(EMC_USB_HOST_HAL_Interface* interface);

/** returns USB device firmware version (bcdDevice) */
uint16_t EMC_USB_HOST_HAL_interface_get_fw_version(EMC_USB_HOST_HAL_Interface* interface);

/** returns USB device S/N */
const uint8_t* EMC_USB_HOST_HAL_interface_get_sn(EMC_USB_HOST_HAL_Interface* interface);

/** returns USB device speed */
EMC_USB_Speed EMC_USB_HOST_HAL_get_device_speed();

/** set the alternate setting */
EMC_USB_HOST_HAL_Error EMC_USB_HOST_HAL_interface_set_alt_setting(emc_std_uint8_t alt_setting);

/**
 * @brief Enables a specific Endpoint.
 *
 * @param[in] ep_addr        Endpoint address.
 * @param[in] transfer_type  Transfer type for this Endpoint.
 * @param[in] timeout_ms     Transfer timeout in ms.
 * @param[out] max_packet_size return the FIFO size for this Endpoint.
 *
 * @return A unique handle for the endpoint, or EMC_USB_HOST_HAL_ERROR_INVALID_EP_HANDLE in case of
 *         an error.
 */
EMC_USB_HOST_HAL_Endpoint* EMC_USB_HOST_HAL_ep_enable(EMC_USB_EndpointAddress ep_addr,
                                                      EMC_USB_TransferType transfer_type,
                                                      emc_std_uint32_t timeout_ms,
                                                      emc_std_uint16_t* max_packet_size);

/**
 * @brief Disables a specific Endpoint.
 *
 * @param[in] ep_handle The Endpoint handle as received from @ref EMC_USB_HOST_HAL_ep_enable.
 *
 * @return The error code of the operation.
 */
EMC_USB_HOST_HAL_Error EMC_USB_HOST_HAL_ep_disable(EMC_USB_HOST_HAL_Endpoint* endpoint);

/**
 * @brief Writes to the given USB Endpoint (IN direction).
 *
 * The caller has to ensure that the endpoint handle exists and the buffer is valid.
 * The USB HAL takes care of splitting the buffer into multiple chunks of the
 * corresponding EP's wMaxPacketSize.
 *
 * @param[in] ep_handle The Endpoint handle.
 * @param[in] buffer    A pointer to the transmit buffer.
 * @param[in] size      The physical size of the buffer to transmit, in bytes.
 *
 * @return The length of the written data or error if < 0
 */
int EMC_USB_HOST_HAL_ep_write(EMC_USB_HOST_HAL_Endpoint* endpoint, const void* buffer, size_t size);

/**
 * @brief Prepares the reception of a transfer (OUT direction).
 *
 * The caller has to ensure that the endpoint handle exists and the buffer
 * is valid. The provided buffer must be a multiple of the corresponding EP's wMaxPacketSize.
 * The USB HAL is responsible of concatenating multiple chunks of
 * wMaxPacketSize if the provided buffer has a size of (N * wMaxPacketSize).
 *
 * @param[in]  ep_handle The endpoint handle.
 * @param[in]  buf_size  The size of the physical buffer.
 * @param[out] buffer    A pointer to the physical buffer to be filled.
 *
 * @return The length of received data or error if < 0
 */
int EMC_USB_HOST_HAL_ep_read(EMC_USB_HOST_HAL_Endpoint* endpoint, void* buffer, size_t size);

// clang-format off extern C
#ifdef __cplusplus
}
#endif
// clang-format on extern C

#endif /* EMC_USB_HOST_HAL_HAL_H */
