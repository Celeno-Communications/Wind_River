/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef IPC_SHARED_H
#define IPC_SHARED_H

#include <net/mac80211.h>

/* Number of available host buffers */
#define IPC_RADAR_BUF_CNT   32
#define IPC_E2A_MSG_BUF_CNT 128
#define IPC_DBG_BUF_CNT     64

/* Length used in MSGs structures (size in 4-byte words) */
#define IPC_A2E_MSG_BUF_SIZE   255
#define IPC_E2A_MSG_PARAM_SIZE 63

/* Debug messages buffers size (in bytes) */
#define IPC_DBG_PARAM_SIZE 256

#define HB_POOL_DMA_DESCS_NUM 2

/* Length of the configuration data of a logic analyzer */
#define LA_CONF_LEN          336

#define IPC_IRQ_L2H_DBG        BIT(0)
#define IPC_IRQ_L2H_MSG        BIT(1)
#define IPC_IRQ_L2H_RXDESC     BIT(2)
#define IPC_IRQ_L2H_TXCFM      0x000000F8
#define IPC_IRQ_L2H_RADAR      BIT(8)
#define IPC_IRQ_L2H_TBTT       BIT(10)

#define IPC_IRQ_L2H_ALL          \
	(IPC_IRQ_L2H_TXCFM |     \
	IPC_IRQ_L2H_RXDESC |     \
	IPC_IRQ_L2H_MSG |        \
	IPC_IRQ_L2H_DBG |        \
	IPC_IRQ_L2H_RADAR |      \
	IPC_IRQ_L2H_TBTT)

#define IPC_IRQ_S2H_HW_ERROR   BIT(12)

#define IPC_IRQ_S2H_ALL          \
	(IPC_IRQ_S2H_HW_ERROR)

#define IPC_TX_QUEUE_CNT 5
#define USB_DS_DATA_EP_CNT (IPC_TX_QUEUE_CNT + 2)

#define CL_MAX_BA_PHYSICAL_QUEUE_CNT (AC_MAX)

/* Message structure for MSGs from Emb to App */
struct cl_ipc_e2a_msg {
	__le16 id;
	__le16 dummy_dest_id;
	__le16 dummy_src_id;
	__le16 param_len;
	u32 param[IPC_E2A_MSG_PARAM_SIZE];
	__le32 pattern;
};

/* ETH2WLAN and NATT common parameters field (e2w_natt_param) struct definition: */
/*
 * Comes from ipc_dma.h
 * Element in the pool of TX DMA bridge descriptors.
 * PAY ATTENTION - Avoid Changing/adding pointers to that struct,
 * or any shared-memory-related-structs !!!
 * Since in 64Bit platforms (Where pointers are 64Bit) such pointers
 * might change alignments in shared-memory-related-structs of FW and DRV.
 */
struct dma_desc {
	/*
	 * Application subsystem address which is used as source address for DMA payload
	 * transfer
	 */
	u32 src;
	/*
	 * Points to the start of the embedded data buffer associated with this descriptor.
	 * This address acts as the destination address for the DMA payload transfer
	 */
	u32 dest;
	/* Complete length of the buffer in memory */
	u16 length;
	/* Control word for the DMA engine (e.g. for interrupt generation) */
	u16 ctrl;
	/* Pointer to the next element of the chained list */
	u32 next;
	/*
	 * When working with 64bit application the high 32bit address should be provided
	 * in the following variable (note: "PCIEW_CONF" register should be configured accordingly)
	 */
	u32 app_hi_32bit;
};

/* Message structure for Debug messages from Emb to App */
struct cl_ipc_dbg_msg {
	char string[IPC_DBG_PARAM_SIZE];
	__le32 pattern;
};

/*
 * Message structure for MSGs from App to Emb.
 * Actually a sub-structure will be used when filling the messages.
 */
struct cl_ipc_a2e_msg {
	u32 dummy_word;
	u32 msg[IPC_A2E_MSG_BUF_SIZE];
};

/* Tensilica backtrace depth */
#define IPC_BACKTRACT_DEPTH  5

/* Struct for tensilica  backtrace */
struct cl_ipc_backtrace_struct {
	__le32 pc[IPC_BACKTRACT_DEPTH];
};

/* Struct for tensilica  exception indication */
struct cl_ipc_exception {
	__le32 pattern;
	__le32 type;
	__le32 epc;
	__le32 excsave;
	struct cl_ipc_backtrace_struct backtrace;
};

/*
 * Can't use BITS_TO_LONGS since in firmware sizeof(long) == 4 and in the host
 * this might be different from compiler to compiler. We need our own macro to
 * match the firmware definition.
 */
#define CL_BITS_TO_U32S(nr) DIV_ROUND_UP(nr, BITS_PER_BYTE * sizeof(u32))

#define IPC_MAX_BA_SESSIONS 32

#define IPC_MAX_TIM_TX_OR_RX_AGG_SIZE \
	((IPC_MAX_BA_SESSIONS > CL_MAX_NUM_STA) \
	 ? IPC_MAX_BA_SESSIONS : CL_MAX_NUM_STA)

#define IPC_TIM_AGG_SIZE (IPC_MAX_TIM_TX_OR_RX_AGG_SIZE * 2)

/*
 * struct cl_ipc_enhanced_tim - ipc enhanced tim element
 *
 * This structure hold indication on the buffered traffic resembles the TIM element.
 * This enhanced TIM holds more info on the buffered traffic, it indicate whether the
 * traffic is associated with BA or singles and on which AC's.
 *
 * @tx_agg: indicate buffered tx-aggregated traffic per AC per BA session index
 * @tx_single: indicate buffered tx-singles traffic per AC per station index
 * @rx: indicate buffered rx traffic per AC per station index
 */
struct cl_ipc_enhanced_tim {
	/*
	 * Traffic indication map
	 * our driver push packets to the IPC queues (DRIVER_LAYER -> IPC_LAYER),
	 * on each push it also notify the IPC_LAYER for which queue it pushed packets.
	 * this indication done by filling the bitmap.
	 *
	 * this is enhanced tim element because it is divided into AC and packet type
	 * (aggregatable/non aggregatable).
	 * the regular tim element which exist in the beacon is divided by AID only
	 * which is less informative.
	 *
	 */
	u32 tx_rx_agg[AC_MAX][CL_BITS_TO_U32S(IPC_TIM_AGG_SIZE)];
	u32 tx_single[AC_MAX][CL_BITS_TO_U32S(FW_MAX_NUM_STA)];
};

struct cl_usb_msg_hdr {
	__le32 magic;
	__le16 version;
	__le16 data_type;
	__le16 reserved;
	__le16 length;
};

struct cl_ipc_e2a_msg_elem {
	struct cl_usb_msg_hdr usb_hdr;
	struct cl_ipc_e2a_msg e2a_msg;
};

struct cl_ipc_dbg_msg_elem {
	struct cl_usb_msg_hdr usb_hdr;
	struct cl_ipc_dbg_msg dbg_msg;
};

struct usb_l2u_msg_info {
	__le32 msg_l2u_base_addr;
	__le32 msg_l2u_elem_max;
};

struct usb_umac_env_tag {
	__le32 idma_allocation;
	struct usb_l2u_msg_info l2u_info[USB_DS_DATA_EP_CNT];
	__le32 umac_stats_addr;
};

struct cl_ipc_shared_env {
	volatile struct usb_umac_env_tag usb_umac_env;
	volatile struct cl_ipc_a2e_msg a2e_msg_buf;
	/* Fields for MSGs sending from Emb to App */
	volatile struct cl_ipc_e2a_msg_elem e2a_msg_buf;
	volatile struct dma_desc msg_dma_desc;
	volatile __le32 e2a_msg_hostbuf_addr[IPC_E2A_MSG_BUF_CNT];
	/* Fields for Debug MSGs sending from Emb to App */
	volatile struct cl_ipc_dbg_msg_elem dbg_buf;
	volatile struct dma_desc dbg_dma_desc;
	volatile __le32 dbg_hostbuf_addr[IPC_DBG_BUF_CNT];
	volatile __le32 dbginfo_addr;
	volatile __le32 dbginfo_size;
	volatile __le32 pattern_addr;
	volatile __le32 radarbuf_hostbuf[IPC_RADAR_BUF_CNT]; /* Buffers for radar events */
	/* Used to update host general debug data */
	volatile struct dma_desc dbg_info_dma_desc;
	/*
	 * The following members are assoicated with the process of fetching "application txdesc"
	 * from the application and copy them to the internal embedded queues.
	 *
	 * @host_address_dma: dedicated dma descriptor to fetch the addresses of
	 * "application txdesc" queues
	 * @write_dma_desc_pool: dedicated dma descriptor to fetch the "@txdesc_emb_wr_idx"
	 * index (dma for application txdesc metadata)
	 * @last_txdesc_dma_desc_pool: dedicated dma descriptor to fetch "application txdescs"
	 * (dma for application txdesc)
	 * @txdesc_emb_wr_idx: indicate the last valid "application txdesc" fetched
	 */
	volatile struct dma_desc host_address_dma;
	volatile struct dma_desc tx_power_tables_dma_desc;
	volatile __le32 txdesc_emb_wr_idx[IPC_TX_QUEUE_CNT + CL_MAX_BA_PHYSICAL_QUEUE_CNT];
	volatile __le32 host_rxbuf_rd_idx[CL_RX_BUF_MAX];                       /* For FW only */
	volatile struct dma_desc rx_fw_hb_pool_dma_desc[HB_POOL_DMA_DESCS_NUM]; /* For FW only */
	volatile struct dma_desc rxm_hb_pool_dma_desc[HB_POOL_DMA_DESCS_NUM];   /* For FW only */
	volatile __le32 cfm_read_pointer; /* CFM read point. Updated by Host, Read by FW */
	volatile __le16 phy_dev;
	volatile u8 bus_type;
	volatile u8 la_enable;
	volatile u8 flags;
	volatile __le16 max_retry;
	volatile __le16 lft_limit_ms;
	volatile __le16 bar_max_retry; /* Not used by driver */
	volatile __le32 assert_pattern;
	volatile __le16 assert_file_id;
	volatile __le16 assert_line_num;
	volatile __le32 assert_param;
	volatile struct cl_ipc_exception exception_info;
	volatile struct cl_ipc_enhanced_tim enhanced_tim;
};

#endif /* IPC_SHARED_H */
