/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef __USB_H
#define __USB_H

#include <linux/usb.h>
#include "chip.h"
#include "reg_mac_hw.h"
#include "reg_access.h"

#define CL_CORE_USB_VENDOR_ID 0x33de

#define CLI_USB_BCD_DEVICE_APP_MASK 0x100

#define USB_CLI_IF_NUM 0
#define USB_WIFI_IF_NUM 1

#define ALT_RUN 0x0
#define ALT_STOP 0x1

#define UMAC_GLOBAL_REGS_ADDR (LOCAL_UMAC_DRAM_FW_ADDR + 0x2FF00)
#define UMAC_USB_PROFILE_REG_ADDR (UMAC_GLOBAL_REGS_ADDR + 0x8)
#define UMAC_LOG_SIDE_BUF_ADDR_GET(chip) (mac_hw_bfr_general_get(chip) & 0x0FFFFFFF)
#define UMAC_LOG_SIDE_BUF_ADDR_RESET(chip) (mac_hw_bfr_general_set(chip, 0))
#define UMAC_LOG_SIDE_BUF_SIZE BIT(16) /* 64K */

#define UMAC_US_CONT_COUNT_OFFSET 0x0
#define UMAC_US_CONT_SIZE_OFFSET 0x4
/* RX Data Channel */
#define UMAC_US_CONT_U0_REGS_ADDR (UMAC_GLOBAL_REGS_ADDR + 0x10)
/* RXM Data Channel */
#define UMAC_US_CONT_U5_REGS_ADDR (UMAC_GLOBAL_REGS_ADDR + 0x30)

#define UMAC_DS_PACKETS_PER_HOST_TRANSFER_OFFSET 0x0
#define UMAC_DS_PDMA_WAIT_TIME_OFFSET 0x8
#define UMAC_DS_MAX_TRB_CHAIN_SIZE_OFFSET 0x4
#define UMAC_DS_CAPABILITIES_OFFSET 0xC
#define UMAC_DS_AGGR_D0_REGS_ADDR (UMAC_GLOBAL_REGS_ADDR + 0x50)
#define UMAC_DS_AGGR_D1_REGS_ADDR (UMAC_GLOBAL_REGS_ADDR + 0x60)
#define UMAC_DS_AGGR_D2_REGS_ADDR (UMAC_GLOBAL_REGS_ADDR + 0x70)
#define UMAC_DS_AGGR_D3_REGS_ADDR (UMAC_GLOBAL_REGS_ADDR + 0x80)
#define UMAC_DS_AGGR_D4_REGS_ADDR (UMAC_GLOBAL_REGS_ADDR + 0x90)
#define UMAC_DS_AGGR_D5_REGS_ADDR (UMAC_GLOBAL_REGS_ADDR + 0xA0)

#define CL_CLI_USB_WD_MS 1500
#define CL_CLI_USB_KA_MS (CL_CLI_USB_WD_MS - 500)

/* base address for protocol specific error codes */
#define CLI_BASE 1000
#define EINVCMD    (CLI_BASE + 1)
#define EINVCMDLEN (CLI_BASE + 2)
#define EINVOFFS   (CLI_BASE + 3)
#define EINVADDR   (CLI_BASE + 4)
#define ECRC       (CLI_BASE + 5)
#define ENOEXPRES  (CLI_BASE + 10)

/* Define Priorities used by logging system */
enum umac_logger_level {
	UMAC_LOGGER_LEVEL_OFF   = 0,
	UMAC_LOGGER_LEVEL_FATAL = 1,
	UMAC_LOGGER_LEVEL_ERROR = 2,
	UMAC_LOGGER_LEVEL_WARN  = 3,
	UMAC_LOGGER_LEVEL_INFO  = 4,
	UMAC_LOGGER_LEVEL_DEBUG = 5,
	UMAC_LOGGER_LEVEL_TRACE = 6
};

/** The mask to write all bits */
#define CLI_USB_WRITE_MASK_ALL 0xFFFFFFFF
#define CLI_USB_WRITE_BOUND_32KB BIT(15)

/* Timeout waiting for response */
#define CLI_USB_CLI_TIMEOUT_MS 30000
#define CLI_USB_CLI_TIMEOUT_JIFFIES msecs_to_jiffies(CLI_USB_CLI_TIMEOUT_MS)

#define CL_USB_EP_ADDR_CLI_IN 0x81
#define CL_USB_EP_ADDR_CLI_OUT 0x01

#ifdef CE_DUMMY_PHY
#define CL_USB_DISCONNECT_DELAY_MS 1
#define CL_USB_RESTART_DELAY_MS 2
#else
#define CL_USB_DISCONNECT_DELAY_MS 500
#define CL_USB_RESTART_DELAY_MS 2000
#endif

#define IS_USB_SUPER_SPEED(chip_usb) (((chip_usb)->usb_dev->speed == USB_SPEED_SUPER_PLUS) || \
				      ((chip_usb)->usb_dev->speed == USB_SPEED_SUPER))

enum cli_usb_cmd_type {
	CLI_USB_CMD_UNDEFINED = 0,
	CLI_USB_CMD_GET_VERSION = 1,
	CLI_USB_CMD_READ = 2,
	CLI_USB_CMD_WRITE = 3,
	CLI_USB_CMD_WRITE_FAST = 4,
	CLI_USB_CMD_KEEP_ALIVE = 5,
	CLI_USB_CMD_DISCONNECT_USB = 6,
	CLI_USB_CMD_UMAC_EXECUTE = 7,
	CLI_USB_CMD_UMAC_RESTART = 8,
	CLI_USB_CMD_UMAC_LOGGER_GET_INFO = 0x10,
	CLI_USB_CMD_UMAC_LOGGER_GET_LEVEL = 0x11,
	CLI_USB_CMD_UMAC_LOGGER_SET_LEVEL = 0x12,
	CLI_USB_CMD_BULK_READ_ZCOPY = 0x80,
	CLI_USB_CMD_BULK_WRITE_ZCOPY = 0x81,
	CLI_USB_CMD_BULK_WRITE_FAST_ZCOPY = 0x82,
	CLI_USB_CMD_BULK_READ_BUFF = 0x88,
	CLI_USB_CMD_BULK_WRITE_BUFF = 0x89,
	CLI_USB_CMD_BULK_WRITE_FAST_BUFF = 0x8A,
	CLI_USB_CMD_FUNC_IOCTL_0 = 0x90
};

enum usb_profile {
	WIFI_BT_PROFILE = 0x1,
	WIFI_ONLY_PROFILE = 0x2,
	BT_ONLY_PROFILE = 0x3,
	ECM_PROFILE = 0x4
};

enum cli_usb_cmd_ioctl_code {
	CL_CLI_USB_CMD_IOCTL_CODE_RESET_STATS = 0x1,
	CL_CLI_USB_CMD_IOCTL_CODE_CONF_STATS = 0x2,
	CL_CLI_USB_CMD_IOCTL_CODE_ENABLE_WD = 0x3
};

struct cli_usb_fw_file_params {
	u32 dram_addr;
	int dram_size;
	u32 iram_addr;
	int iram_size;
};

struct cl_rx_usb_sorted_pdma_elem {
	void *ptr;
	u8 type;
	u8 msdu_split;
	u16 size;
};

enum cl_usb_ep {
	CL_USB_EP_CLI_IN,
	CL_USB_EP_MSG_DBG_IN,
	CL_USB_EP_SENSING_ONLINE_IN,
	CL_USB_EP_SENSING_OFFLINE_IN,
	CL_USB_EP_RX_DATA_IN,
	CL_USB_EP_RXM_DATA_IN,

	CL_USB_EP_CLI_OUT,
	CL_USB_EP_TX_DATA_AC0_OUT,
	CL_USB_EP_TX_DATA_AC1_OUT,
	CL_USB_EP_TX_DATA_AC2_OUT,
	CL_USB_EP_TX_DATA_AC3_OUT,
	CL_USB_EP_TX_BCAST_OUT,
	CL_USB_EP_TX_HTP_OUT,
	CL_USB_EP_TX_DATA_SENSING_OUT,
	CL_USB_EP_READ_RSP,

	CL_USB_EP_MAX
};

struct cl_usb_endpoint {
	struct cl_chip *chip;
	u32 pipe;
	struct usb_anchor submitted;
	u8 address;
	u8 lli_channel;
	u16 max_packet_size;
	u32 last_packet_size;
	u32 last_packet_chunks;
	u32 max_chain_size;
	struct cl_rx_usb_sorted_pdma_elem *pdmas;
};

struct cl_chip_usb {
	struct usb_device *usb_dev;
	struct cl_chip *chip;
	u16 product_id;
	u16 bcd_device;
	u32 cli_cmd_seq_id;
	struct cl_usb_endpoint *eps;
	char *write_req_addr;
	int write_req_rem_length;
	int lcu_rem_length;
	int lcu_offset;
	bool sg_en;
	u8 umac_ds_aggr_count[UMAC_TX_LLI_CH_MAX];
	u16 single_addr_free_idx;
	struct delayed_work umac_keepalive_work;
	struct work_struct cli_work;
	struct list_head cli_cmd_list;
	int cli_cmd_cnt;
	spinlock_t cli_cmd_lock;
	unsigned long last_umac_ka;
};

static inline struct cl_chip_usb *cl_chip_usb_priv(struct cl_chip *chip)
{
	return (struct cl_chip_usb *)chip->drv_priv;
}

struct cli_usb_param_version {
	u32 protocol;
	u32 firmware;
};

struct cli_usb_param_read {
	u32 addr;
	u32 value;
};

struct cli_usb_param_write {
	u32 addr;
	u32 value;
	u32 mask;
};

struct cli_usb_param_disconnect_usb {
	u32 msec_delay;
};

struct cli_usb_param_umac_exec {
	u32 jump_addr;
};

struct cli_usb_param_umac_restart {
	u32 disconnect_delay;
	u32 restart_delay;
	u32 jump_addr;
};

struct cli_usb_param_umac_logger {
	u32 index;
	u32 level;
	u32 actual_length;
	size_t size;
	void *buf;
};

struct cli_usb_param_bulk_read {
	u32 addr;
	size_t size;
	void *buf;
};

struct cli_usb_param_bulk_write {
	u32 addr;
	size_t size;
	void *buf;
};

struct cli_usb_param_ioctl {
	u32 io_out_param[3];
	u32 io_in_param[2];
};

struct cli_usb_cmd {
	enum cli_usb_cmd_type type;
	int status;
	u32 seq_id;
	struct cl_usb_endpoint *ep;
	struct cl_chip *chip;
	struct completion complete;
	struct completion rsp_complete;
	struct completion data_complete;
	struct list_head list;
	int (*step2_func)(struct cl_chip *chip, struct cli_usb_cmd *cmd);
	int (*step3_func)(struct cl_chip *chip, struct cli_usb_cmd *cmd);
	union {
		struct cli_usb_param_version        version;
		struct cli_usb_param_read           read;
		struct cli_usb_param_write          write;
		struct cli_usb_param_disconnect_usb disconnect;
		struct cli_usb_param_umac_exec      umac_exec;
		struct cli_usb_param_umac_restart   umac_restart;
		struct cli_usb_param_umac_logger    logger;
		struct cli_usb_param_bulk_read      bulk_read;
		struct cli_usb_param_bulk_write     bulk_write;
		struct cli_usb_param_ioctl          ioctl;
	} param;
};

struct cli_usb_cmd_hdr {
	__le32 cmd_id;
	__le32 seq_id;
	__le32 param[3];
};

struct cli_usb_rsp_hdr {
	__le32 cmd_id;
	__le32 seq_id;
	__le32 status;
	__le32 param[2];
};

/* keep packed since compiler aligned it to 64 due to __le64 variable */
struct usb_umac_min_max_avg_stats {
	/* minimum value */
	__le32 min;
	/* maximum value */
	__le32 max;
	/* sum of values */
	__le64 avg_sum;
	/* number of values in sum */
	__le32 avg_cnt;
} __packed;

struct usb_umac_lli_stats {
	/* number of pDMAs got from USBWrapper */
	__le32 pdma_get;
	/* number of pDMAs completed with success */
	__le32 pdma_done;
	/* number of pDMAs completed with error */
	__le32 pdma_done_error;
	/* number of pDMAs initially queued (before first completion) */
	__le32 pdma_initial;
	/* pDMA pending time for very first pDMA in ticks */
	__le32 pdma_pending_initial;
	/* pDMA pending interval statistics in ticks */
	struct usb_umac_min_max_avg_stats range;
	/* pDMA completion count for recent update of minimum pending time */
	__le32 pdma_done_pending_min;
	/* pDMA completion count for recent update of maximum pending time */
	__le32 pdma_done_pending_max;
};

#define USBW_UL_LLI_COUNT 16
#define USBW_DL_LLI_COUNT 16

struct usb_umac_stats {
	__le32 version;
	__le32 size;

	struct usb_umac_lli_stats lli_ul[USBW_UL_LLI_COUNT];
	struct usb_umac_lli_stats lli_dl[USBW_DL_LLI_COUNT];
};

static inline u32 add_reg_base_addr(u32 reg)
{
	if ((reg & 0xf0000000) != LOCAL_UMAC_DRAM_FW_ADDR)
		return reg + XTENSA_PIF_BASE_ADDR;

	return reg;
}

void usb_deinit_app_eps(struct cl_chip *chip);
int cl_core_usb_register(void);
void cl_core_usb_unregister(void);
#endif /* __USB_H */
