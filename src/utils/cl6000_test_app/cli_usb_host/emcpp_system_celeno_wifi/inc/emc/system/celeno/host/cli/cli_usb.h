/**
 * @file
 * @brief Bootrom USB CLI API
 * @author  <ralf.oberlaender@emsys.de>
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_HOST_CLI_cli_usb_H
#define EMC_SYSTEM_CELENO_HOST_CLI_cli_usb_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CL_USB_Error_PENDING 1                  /**< the operation is queued, still in progress */
#define CL_USB_Error_SUCCESS 0                  /**< the operation was successful */
#define CL_USB_Error_TIMEOUT -1                 /**< timeout occurred */
#define CL_USB_Error_CONNECTION_ERROR -2        /**< any connection error */
#define CL_USB_Error_INVALID_PARAMETER -3       /**< invalid parameter */
#define CL_USB_Error_INVALID_RESPONSE_TYPE -4   /**< invalid type/id of response */
#define CL_USB_Error_INVALID_RESPONSE_STATUS -5 /**< invalid status in response */
#define CL_USB_Error_INVALID_RESPONSE_LENGTH -6 /**< invalid response length */
#define CL_USB_Error_INVALID_VERSION -7         /**< invalid version */
#define CL_USB_Error_QUEUEING_NOT_ALLOWED -8    /**< queuing not allowed for this type of command */
#define CL_USB_Error_QUEUE_OVERFLOW -9          /**< queue overflow */
#define CL_USB_Error_QUEUE_EMPTY -10            /**< no commands queued */
#define CL_USB_Error_GENERIC -11                /**< Generic Error */

typedef enum CL_USB_SPEED_t {
  CL_USB_SPEED_UNDEFINED, /**< Device speed undefined */
  CL_USB_SPEED_LOW,       /**< Device runs at USB-Low-speed */
  CL_USB_SPEED_FULL,      /**< Device runs at USB-Full-speed */
  CL_USB_SPEED_HIGH,      /**< Device runs at USB-High-speed */
  CL_USB_SPEED_SUPER,     /**< Device runs at USB-Super-speed */
  CL_USB_SPEED_SUPER_PLUS /**< Device runs at USB-Super-speed plus */
} CL_USB_SPEED;

/** The CLI protocol version this module was compiled for. */
extern const uint32_t mg_cl_usb_max_cli_protocol_supported;

typedef struct CLI_USB_Config {
  uint16_t pid;                   ///< USB-PID
  uint16_t bcd_device;            ///< USB bcdDevice (optional, 0 for don't care)
  uint8_t* sn;                    ///< USB-S/N, will be ignored if NULL
  uint8_t  silent;                ///< Don't output error messages when set to >0.
  uint8_t  verbose;               ///< Output more messages when set to >0.
  uint32_t transfer_timeout_ms;   ///< Transfer timeout in ms for bulk eps
  uint32_t connection_timeout_ms; ///< Max Timeout for opening the interface, A value of 0 requires the device can be
  ///< opened immediately
} CLI_USB_Config;

/** Run UMAC bootloader cli functional tests.
 * @param memory address The memory to be used for the test purpose, must be 128k.
 * @param transfer_timeout_ms The transfer timeout in ms.
 * @return 0 on success */
int cl_usb_self_test(uint32_t memory_128k_address, const CLI_USB_Config* config);

/** Initialize configuration structure with default values */
void cl_usb_config_init(CLI_USB_Config* config);

/** Opens cli usb channel for USB device VID=0x33de PID=0x6000
 * @return >=0 on success */
int cl_usb_open(const CLI_USB_Config* config);

/** Close cli usb channel */
void cl_usb_close(void);

/** Returns the USB PID of the opened device */
uint16_t cl_usb_get_pid(void);

/** Returns the USB firmware version (bcdDevice) of the opened device */
uint16_t cl_usb_get_fw_version(void);

/** Returns the USB S/N of the opened device */
const uint8_t* cl_usb_get_sn(void);

/** Returns the USB speed of the opened device */
CL_USB_SPEED cl_usb_get_speed(void);

/** Return last usb error. */
int cl_usb_last_error(void);

/** Reset the CLI application. Call it after an error */
int cl_usb_reset(void);

/** Error recovery:
 * Once an usb error occurred, the system can be recovered by cl_usb_close() and cl_usb_open() in sequence.
 */

/** Execute keep-alive operation
 * @return >=0 on success */
int cl_usb_keep_alive(void);

/** Execute get version operation
 * @param protocol Pointer to protocol version
 * @param firmware Pointer to firmware version
 * @return >=0 on success */
int cl_usb_get_version(uint32_t* protocol, uint32_t* firmware);

/** Convert an application ID to the corresponding string
 * @param app_id The application ID
 * @return zero-terminated string for the application ID */
const char* cl_usb_app_id_as_string(uint8_t app_id);

/** Execute read32 operation. This operation will be appended to an combined command
 * if cl_usb_queue_start() was called before.
 * @param offset Address to read from, must be 32bit aligned
 * @param data Pointer to data
 * @return >=0 on success */
int cl_usb_read32(uint32_t offset, uint32_t* data);

/** Execute write32 operation with status response. This operation will be appended to an combined command
 * if cl_usb_queue_start() was called before.
 * @param offset Address to read from, must be 32bit aligned
 * @param data Value to be written
 * @param mask Only active bits where written
 * @return >=0 on success */
int cl_usb_write32_mask(uint32_t offset, uint32_t value, uint32_t mask);

/** Execute write32 operation without status response. This operation will be appended to an combined command
 * if cl_usb_queue_start() was called before.
 * @param offset Address to read from, must be 32bit aligned
 * @param data Value to be written
 * @param mask Only active bits where written
 * @return >=0 on success */
int cl_usb_write32_mask_fast(uint32_t offset, uint32_t value, uint32_t mask);

/** Execute burst read operation.
 * @param offset Address to read from, must be 32bit aligned
 * @param data Pointer to data buffer, must multiple of 4
 * @param size Number of bytes, must multiple of 4
 * @param zero_copy If true the device uses DMA
 * @return >=0 on success */
int cl_usb_burst_read(uint32_t offset, void* data, size_t size, bool zero_copy);

/** Execute burst write operation with status response.
 * @param offset Address to write to, must be 32bit aligned
 * @param data Pointer to data to be written, must multiple of 4
 * @param size Number of bytes, must multiple of 4
 * @param zero_copy If true the device uses DMA
 * @return >=0 on success */
int cl_usb_burst_write(uint32_t offset, const void* data, size_t size, bool zero_copy);

/** Execute burst write operation without status response.
 * @param offset Address to write to, must be 32bit aligned
 * @param data Pointer to data to be written, must multiple of 4
 * @param size Number of bytes, must multiple of 4
 * @param zero_copy If true the device uses DMA
 * @return >=0 on success */
int cl_usb_burst_write_fast(uint32_t offset, const void* data, size_t size, bool zero_copy);

/** Execute usb disconnect operation.
 * @param usb_disconnect_delay_ms Time in ms to wait, before device initiated usb disconnect becomes effective
 * @return >=0 on success */
int cl_usb_disconnect(uint32_t usb_disconnect_delay_ms);

/** Execute UMAC Execute operation.
 * @param jump_address The address to execute code from
 * @return >=0 on success */
int cl_usb_umac_execute(uint32_t jump_address);

/** Execute umac restart operation. Waits defined time. Enforces usb disconnect, waits again and executes specified
   code.
 * @param usb_disconnect_delay_ms Time in ms to wait, before device initiated usb disconnect becomes effective
 * @param restart_delay_ms Time in ms to wait, before given address is executed
 * @param jump_address The address to execute code from
 * @return >=0 on success */
int cl_usb_umac_restart(uint32_t usb_disconnect_delay_ms, uint32_t restart_delay_ms, uint32_t jump_address);

/** Execute function IO control operation
 * @param function_index The zero based function index < 4. It depends on the firmware, e.g. 0:WIFI , 1:BT
 * @param command_id The function specific command ID that should be executed.
 * @param param1 The function specific parameter 1
 * @param param2 The function specific parameter 2
 * @param[out] result1 The optional function specific result 1
 * @param[out] result2 The optional function specific result 2
 * @return >=0 on success */
int cl_usb_function_ioctl(uint32_t function_index,
                          uint32_t command_id,
                          uint32_t param1,
                          uint32_t param2,
                          uint32_t* result1,
                          uint32_t* result2);

/** Starts queuing. Every single read/write operation is queued until cl_usb_queue_process is executed.
 * @return >=0 on success */
int cl_usb_queue_start(void);

/** Finalized queuing. All operations are executed when function returns.
 * @return >=0 on success */
int cl_usb_queue_process(void);

/** Retrive information on a specific logger. To query the info for all loggers call this fuction repeatedly
 * by using an incrementing index starting at 0x0 until the function returns an error.
 * @param index Zero-based index for the logger
 * @param info_string Caller-provided buffer that will receive the logger info
 * @param size The size of info_string in bytes
 * @return >=0 on success */
int cl_usb_logger_get_info(uint32_t index, char* info_string, size_t size);

/** Get the current logging level for a specific logger.
 * @param index Zero-based index for the logger
 * @param level Caller-provided variable that will be set to the current level on return
 * @return >=0 on success */
int cl_usb_logger_get_level(uint32_t index, uint32_t* level);

/** Set the logging level for a specific logger.
 * @param index Zero-based index for the logger
 * @param level Logging level to set
 * @return >=0 on success */
int cl_usb_logger_set_level(uint32_t index, uint32_t level);

/** Converts a log-level string to a log-level number
 * @param name log-level string to convert
 * @param level computed Log level
 * @return >=0 on success */
int cl_usb_logger_level_as_int(const char* name, uint32_t* level);

/** Converts a log-level number to a log-level string
 * @param level Log level to be converted
 * @param name the computed log-level string
 * @param name_size the max size for the computed log-level string
 * @return >=0 on success */
int cl_usb_logger_level_as_string(uint32_t level, char* name, size_t name_size);

/// Helper
static inline int cl_usb_write32(uint32_t offset, uint32_t value)
{
  return cl_usb_write32_mask(offset, value, 0xFFFFFFFF);
}

static inline int cl_usb_write32_fast(uint32_t offset, uint32_t value)
{
  return cl_usb_write32_mask_fast(offset, value, 0xFFFFFFFF);
}

#endif /* EMC_SYSTEM_CELENO_HOST_CLI_cli_usb_H */
