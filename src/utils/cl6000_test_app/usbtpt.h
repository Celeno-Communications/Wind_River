
/*
 * USB usb throughput test driver
 * @brief A test driver to measure throughput and latency
 *
 * @author Guenter Hildebrandt
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */

#ifndef USBTPT_H_
#define USBTPT_H_

/* max number of channels run in parallel */
#define CHANNELS 2

#pragma pack(push, 1)

/* buffer mode */
enum tpt_buffer_mode {
  TPT_LARGE_BUFFERS = 0,
  TPT_SMALL_BUFFERS
};

/* Set params in value field and (re)start the data transfer
 * value low: enum tpt_buffer_mode
 * value high: bit 0: use verification
 * type: out, vendor, interface; length: 0 */
#define TPT_PARAMS_REQ 1

#define TPT_STATS_REQ  2

/* channel type */
enum tpt_channel_type {
	STREAM = 0,                             // special high bandwidth stream
	SIMPLE = 1                              // simple stream, payload only
};

/* statistics for the transfer */
struct tpt_statistics {
  int32_t           usb_error;             // the last URB error seen in completion, 0 on success
  uint64_t          runtime;               // in nanoseconds
  uint64_t          payload_data;          // the amount of transferred payload data in bytes
  uint64_t          packets_transferred;   // the number of transferred usb packets
  uint64_t          out_buffers_submitted; // number of buffers submitted
  uint64_t          out_buffers_completed; // number of buffers completed
  uint64_t          content_error;         // invalid content in packets
  uint64_t          transfer_error;        // transfer error count
  int               last_urb_error;        // last URB error
};


struct tpt_device_statistic {
  uint32_t packets;             /**< count of transferred packets */
  uint32_t content_error;       /**< count of transfer errors */
  uint32_t transfer_error;      /**< count of transfer errors */
  uint32_t bytes;               /**< count of transferred bytes */
  uint64_t unused;              /**< time relative to start time in us   */
  uint64_t runtime_us;          /**< time relative to start time in us   */
};

/* parameters for the run */
struct tpt_parameter {
  int32_t in_ep;                           // 0 or valid endpoint
  int32_t out_ep;                          // 0 or valid endpoint
  int32_t chunk_size;                      // buffer size of a chunk
  int32_t chunk_count;                     // chunk count in a transfer
	int32_t usb_packet_chunks;               // max chunks per USB MPS
  int32_t packets_to_transfer;             // the transfer stops if this amount of packets is transferred, 0 for infinite
  int32_t buffer_count;                    // buffer count used parallel
  int32_t verify_content;                  // true if the content is verified
  int32_t flags;                           // flags
};

#define TPT_PARAM_FLAG_SCHEDULE_UNUSED_EPS 0x00000001 // schedule, but dont use other-eps
#define TPT_PARAM_FLAG_NO_SG               0x00000002 // dont create sg_list
#define TPT_PARAM_FLAG_PAD_OUT_CHUNKS      0x00000004 // align out chunk size to USP MPS
#define TPT_PARAM_FLAG_NO_TRANSFER_SPLIT   0x00000008 // no host transfer split at device
#define TPT_PARAM_FLAG_ALWAYS_ZLP          0x00000010 // send ZLP also when host_transfer_count is reached

/* start parameters */
struct tpt_start {
  int32_t alt_setting;                     // the alternate setting activated
  int32_t mode;                            // mode setting
  uint32_t runtime;                        // in seconds
  uint32_t raw_packets;                    // raw packets
};

/* status of the device */
struct tpt_status {
  uint32_t is_running;                    // 1 for ongoing data transfer, 0 if data transfer is stopped
};

/* alternate setting */
struct tpt_alternate_setting {
  int32_t alt_setting;                     // the alternate setting to activate
};

#pragma pack(pop)

#define TPT_BASE 0xd0 // a magic for the driver
#define TPT_SET_PARAMETER        _IOW(TPT_BASE, 1, struct tpt_parameter)          // parameter for the run
#define TPT_START                _IOW(TPT_BASE, 10, struct tpt_start)             // start the measurement
#define TPT_STOP                 _IO(TPT_BASE, 11)                                // stop the measurement
#define TPT_GET_STATISTICS       _IOWR(TPT_BASE, 12, struct tpt_statistics)       // read the statistics from the device
#define TPT_GET_STATUS           _IOR(TPT_BASE, 13, struct tpt_status)            // read the status from the device
#define TPT_GET_DEV_STATISTIC    _IOR(TPT_BASE, 15, struct tpt_device_statistic)  // query statistics  from device
#define TPT_ENDPOINT_RESET       _IO(TPT_BASE, 16)                                // reset endpoints
#define TPT_SET_ALT_SETTING      _IOW(TPT_BASE, 17, struct tpt_alternate_setting) // set specific alternate setting
#define TPT_KEEP_ALIVE           _IO(TPT_BASE, 18)                                // keep alive
#endif
