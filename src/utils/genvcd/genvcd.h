#ifndef _GENVCD_H_
#define _GENVCD_H_

#include <stdint.h>
#include <stdbool.h>

#define GENVCD_VER_STR "genvcd cl6k-a0"

/*************************************************************************************************/

enum cl_dbg_level {
	DBG_LVL_VERBOSE,
	DBG_LVL_ERROR,
	DBG_LVL_WARNING,
	DBG_LVL_TRACE,
	DBG_LVL_INFO,
	DBG_LVL_MAX,
};

/// Hardware versions
#define HW_2400_STEP_A0  0
#define HW_2400_STEP_B0  1
#define HW_8000_STEP_A0  2
#define HW_8000_STEP_B0  3
#define HW_6000_STEP_A0  4
#define HW_6000_STEP_B0  5
#define HW_VERSION_MAX 6

#define LVL_STR(lvl) ((lvl) == DBG_LVL_VERBOSE) ? "VERB"  : \
		     ((lvl) == DBG_LVL_ERROR)   ? "ERROR" : \
		     ((lvl) == DBG_LVL_WARNING) ? "WARN"  : \
		     ((lvl) == DBG_LVL_TRACE)   ? "TRACE" : \
		     ((lvl) == DBG_LVL_INFO)    ? "INFO"  : \
						  "N/A"

#define CL_DBG(lvl, fmt, ...) \
do { \
	if ((lvl) <= DEBUG_LEVEL) \
		printf("[%s][%d][%s] " fmt, __func__, __LINE__, LVL_STR(lvl), ##__VA_ARGS__); \
} while (0)

#define cl_dbg_verbose(...) CL_DBG(DBG_LVL_VERBOSE, ##__VA_ARGS__)
#define cl_dbg_err(...)     CL_DBG(DBG_LVL_ERROR, ##__VA_ARGS__)
#define cl_dbg_warn(...)    CL_DBG(DBG_LVL_WARNING, ##__VA_ARGS__)
#define cl_dbg_trace(...)   CL_DBG(DBG_LVL_TRACE, ##__VA_ARGS__)
#define cl_dbg_info(...)    CL_DBG(DBG_LVL_INFO, ##__VA_ARGS__)

#define DEBUG_LEVEL DBG_LVL_TRACE

/*************************************************************************************************/

#define LA_MEM_LEN		(128 * 1024)	// 128KB
#define LA_WORD_LEN		4
#define LA_WIDE_SAMPLE_LEN	32		// 32 bytes = 256 bits
#define LA_NARROW_SAMPLE_LEN	16		// 16 bytes = 128 bits
#define LA_MEM_WORD_COUNT	((LA_MEM_LEN) / (LA_WORD_LEN))

#define LCU_MAX_WIDE_SAMPLES	((LA_MEM_LEN) / (LA_WIDE_SAMPLE_LEN))
#define LCU_MAX_NARROW_SAMPLES	((LA_MEM_LEN) / (LA_NARROW_SAMPLE_LEN))
#define LA_MAX_LINE_CNT		LCU_MAX_NARROW_SAMPLES

#define LCU_WIDE_ENTRY_SIZE	((LA_WIDE_SAMPLE_LEN) / (LA_WORD_LEN))
#define LCU_NARROW_ENTRY_SIZE	((LA_NARROW_SAMPLE_LEN) / (LA_WORD_LEN))

#define LCU_NUM_OF_LEGACY_MICTORS    6
#define BT_LCU_COMPACT_SUBCHAN_CNT   6

#define LCU_TIMESTAMP_SIZE	30   // in bits
#define LCU_TIMESTAMP_MASK	((0x1 << (LCU_TIMESTAMP_SIZE)) - 1)
#define MAX_TIMESTAMP LCU_TIMESTAMP_MASK
#define LCU_BT_CHAN_ID_MASK 0xFC000000
#define LCU_BT_CHAN_ID_SHIFT 26

enum channel_id {
	CHAN_ID_MAC_ELA_CHAN_0 = 0,
	CHAN_ID_MAC_ELA_CHAN_1 = 1,
	CHAN_ID_PHY_LCU_CHAN_0 = 2,
	CHAN_ID_PHY_LCU_CHAN_1 = 3,
	CHAN_ID_BT_LCU_CHAN    = 4,
};

#define CHAN_ID_INVALID         -1
#define LCU_COMMON_CHAN_CNT     6
#define LCU_VCI_MAX             4
#define MAC_ELA_CHAN_CNT        2
#define PHY_LCU_CHAN_CNT        2
#define BT_LCU_CHAN_CNT         20

#define MAX_NUM_OF_SIGNAL_GROUPS 32

#define LA_STATUS_RUN_MASK      0x0F
#define LA_STATUS_RUN_DISABLED  0x00
#define LA_STATUS_RUN_ARMED     0x01
#define LA_STATUS_RUN_RECORD    0x02
#define LA_STATUS_RUN_REC_END   0x03

// LCU_COMMON_CH_0_CONF Register
#define CH_WRITE_VCI   0x2
#define CH_WRITE_TS    0x1
#define CH_REC_FORMAT  0x0

#define BIT(pos) (1U << (pos))

#define LA_RAM_BIN_FILE_NAME  "mactrace"
#define LA_CONF_BIN_FILE_NAME "lamacconf"
#define LA_CONF_TXT_FILE_NAME "lamacconf.txt"
#define TRACE_CVD_FILE_NAME   "trace.vcd"
#define BT_DUMP_FILE_NAME     "btdump.txt"
#define RFICW_DUMP_FILE_NAME  "rficwdump.txt"

#define STR_BUF_MAX 256

// Multiplier to convert LA clocks to time:
#define TIME_UNIT_str "1ps"

// Default ASIC clock is 640 Mhz => ~ 1,562 ps/clock
#define ASIC_CLK    640 // 640 Mhz
#define DELAY ((unsigned long long)(1000000/(ASIC_CLK))) // 1562 ps

#define NUM_OF_BT_CHANNELS 20
#define BT_MODEM_SUBCHANNEL_IDX_OFT 10
#define BT_LCU_MASK_REG_COUNT 3
#define BTDIAG_CONTROLLER_MODE_OFFSET 32
#define MAX_GROUPS 96

// Compensation calculation:
// Sampling of BT channels is done 1 BT clock after change occured.
// BT clock is 16MHz, so period is 62500ps ~= 40 * DELAY, where 40
// is actaully ((NUM_OF_BT_CHANNELS) * 2). then subtract 2 due to
// lcu channel 4 (BT) being 1 ts late compared to channels 0/1 (MAC)
// and MAC taking 1 extra clock to be sampled (compared to BT)
#define BT_LCU_MAC_ELA_TS_COMPENSATION (((NUM_OF_BT_CHANNELS) * 2) - 2)

#define LEGACY_PORTS_IN_GENERAL_PORT ((PORT_SIZE_DEFAULT) / (PORT_SIZE_MAC_LEGACY))

#define MAC_NARROW_0_MODE_PORT_CNT 3

// sw diags port
#define PORT_SW_LO 0x1E
#define PORT_SW_HI 0x1F

// must match base values in hwdiag.txt
#define PORT_BASE_LEGACY   0x000
#define PORT_BASE_BAU      0x100
#define PORT_BASE_PCIEW    0x200
#define PORT_BASE_BRU      0x300
#define PORT_BASE_BAP      0x400
#define PORT_BASE_RFICW    0x500
#define PORT_BASE_RXM      0x600
#define PORT_BASE_TXM      0x700
#define PORT_BASE_LMAC_INT 0x800
#define PORT_BASE_SMAC_INT 0x801
#define PORT_BASE_UMAC_INT 0x802
#define PORT_BASE_XT_BASIC 0x803
#define PORT_BASE_XT_EXTND 0x804
#define PORT_BASE_E2W      0x900
#define PORT_BASE_APB      0x910
#define PORT_BASE_NTT      0x920
#define PORT_BASE_PTA      0xA00
#define PORT_BASE_TOP      0xB00
#define PORT_BASE_USBW     0xC00
#define PORT_BASE_IDMA     0xD00
#define PORT_BASE_USBC     0xE00
#define PORT_BASE_TCI      0xF00

// must match base values btdiag.txt
#define PORT_BASE_BT_CMPCT 0x000
#define PORT_BASE_BT       0x100

// according to spec
#define PORT_MODE_MAX_LEGACY   0x72
#define PORT_MODE_MAX_BRU      0x01
#define PORT_MODE_MAX_BAP      0x01
#define PORT_MODE_MAX_BAU      0x04
#define PORT_MODE_MAX_PCIEW    0x08
#define PORT_MODE_MAX_RXM      0x0D
#define PORT_MODE_MAX_TXM      0x18
#define PORT_MODE_MAX_PTA      0x08
#define PORT_MODE_MAX_LMAC_INT 0x01
#define PORT_MODE_MAX_SMAC_INT 0x01
#define PORT_MODE_MAX_UMAC_INT 0x01
#define PORT_MODE_MAX_XT_BASIC 0x01
#define PORT_MODE_MAX_XT_EXTND 0x01
#define PORT_MODE_MAX_E2W      0x01
#define PORT_MODE_MAX_APB      0x01
#define PORT_MODE_MAX_NTT      0x01
#define PORT_MODE_MAX_RFICW    0x11
#define PORT_MODE_MAX_TOP      0x06
#define PORT_MODE_MAX_BT       0x13
#define PORT_MODE_MAX_BT_CMPCT 0x5C
#define PORT_MODE_MAX_USBW     0x1B
#define PORT_MODE_MAX_USBC     0x04 // TODO: max=0x98 (need to update hwdiag according to DWC_usb3.v)
#define PORT_MODE_MAX_IDMA     0x05
#define PORT_MODE_MAX_TCI      0x00 // TODO: Get from RTL

// according to spec
#define PORT_SIZE_BT_CMPCT   15
#define PORT_SIZE_BT         90
#define PORT_SIZE_MAC_LEGACY 16
#define PORT_SIZE_DEFAULT    32
#define PORT_SIZE_USBC       64
#define PORT_SIZE_XT         96

#define MAC_ELA_MASK_REG_COUNT 8
#define PHY_LCU_START_PTRN_REG_COUNT 8
#define PHY_LCU_STOP_PTRN_REG_COUNT 8

enum diag_file_id {
	DIAG_FILE_ID_HW,
	DIAG_FILE_ID_SW,
	DIAG_FILE_ID_BT,
	DIAG_FILE_ID_MAX
};

enum top_port_modes {
	TOP_PORT_MODE_MAC_STATE_0,
	TOP_PORT_MODE_MAC_STATE_1,
	TOP_PORT_MODE_MAC_STATE_FULL,
	TOP_PORT_MODE_MPIF_COMMON,
	TOP_PORT_MODE_MPIF_USER,
	TOP_PORT_MODE_MPIF_USER_REDUCED,
};

// CL6000 AXI spec, Section 6.3
enum mac_ela_modes {
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___DEBUG_APB_31_0___NTT0_DEBUG_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___NTT0_DEBUG_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___DEBUG_APB_31_0___DEBUG_INT_LMAC_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___DEBUG_INT_LMAC_31_0,
	MAC_ELA_MODE___LMAC_BASIC_DEBUG,
	MAC_ELA_MODE___SMAC_BASIC_DEBUG,
	MAC_ELA_MODE___UMAC_BASIC_DEBUG,
	MAC_ELA_MODE___LMAC_EXTENDED_DEBUG,
	MAC_ELA_MODE___SMAC_EXTENDED_DEBUG,
	MAC_ELA_MODE___UMAC_EXTENDED_DEBUG,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___PCIEW_31_0___BRU_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___PCIEW_31_0___E2W_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_223_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___BAU_31_0___RXM0_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___PCIEW_31_0___RXM0_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___RXM0_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___RXM0_63_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___BAU_31_0___BRU_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___DEBUG_INT_LMAC_31_0___BAP0_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___RFICW_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___TXM0_31_0,
	MAC_ELA_MODE___PCIEW_31_0___E2W_31_0___TXM0_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_32___PTA_31_0,
	MAC_ELA_MODE___USBW_31_0___USBC_63_0,
	MAC_ELA_MODE___USBW_31_0___E2W_31_0___TXM0_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___USBW_31_0___BRU_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___USBW_31_0___E2W_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___USBW_31_0___RXM0_31_0,
	MAC_ELA_MODE___USBW_31_0___DEBUG_INT_UMAC_31_0___IDMA_31_0,
	MAC_ELA_MODE___USBW_31_0___E2W_31_0___IDMA_31_0,
	MAC_ELA_MODE___USBW_31_0___BRU_31_0___IDMA_31_0,
	MAC_ELA_MODE___USBW_31_0___DEBUG_INT_UMAC_31_0___DEBUG_INT_SMAC_31_0,
	MAC_ELA_MODE___USBW_31_0___TCI_31_0___TXM_31_0,
	MAC_ELA_MODE___PCIEW_31_0___TCI_31_0___TXM_31_0,
	MAC_ELA_MODE___MAC_TOP0_HW_DIAG_95_64___TCI_31_0___TXM_31_0,
	MAC_ELA_MODE_MAX
};

enum port_id {
	PORT_ID_INVALID,
	PORT_ID_LEGACY_A, /* mac_top0_hw_diag[31:00] */
	PORT_ID_LEGACY_B, /* mac_top0_hw_diag[63:32] */
	PORT_ID_LEGACY_C, /* mac_top0_hw_diag[95:64] */
	PORT_ID_BAU,
	PORT_ID_PCIEW,
	PORT_ID_BRU,
	PORT_ID_BAP,
	PORT_ID_RFICW,
	PORT_ID_RXM_A, /* rxm_dbg[31:00] */
	PORT_ID_RXM_B, /* rxm_dbg[63:32] */
	PORT_ID_TXM,
	PORT_ID_LMAC_INT,
	PORT_ID_SMAC_INT,
	PORT_ID_UMAC_INT,
	PORT_ID_LMAC_BASIC,
	PORT_ID_SMAC_BASIC,
	PORT_ID_UMAC_BASIC,
	PORT_ID_LMAC_EXTND,
	PORT_ID_SMAC_EXTND,
	PORT_ID_UMAC_EXTND,
	PORT_ID_E2W,
	PORT_ID_APB,
	PORT_ID_NTT,
	PORT_ID_PTA,
	PORT_ID_TOP,
	PORT_ID_BT,
	PORT_ID_BT_CMPCT,
	PORT_ID_USBW,
	PORT_ID_IDMA,
	PORT_ID_USBC, /* logic_analyzer_trace[63:00] */
	PORT_ID_TCI,
	PORT_ID_MAX,
};

enum lcu_phy_regs {
	MPU_DEBUG_1,
	MPU_DEBUG_2,
	SMU_DEBUG_1,
	SMU_DEBUG_2,
	BPU_DEBUG_SEL,
	BPU_DEBUG_SEL_1,
	RIU_MICTOR_CONF1,
	RIU_MICTOR_CONF2,
	TFU_MICTOR_CONF,
	SPU_DEBUG_1,
	SPU_DEBUG_2,
	LCU_PHY_REGS_MAX
};

struct mode_info {
	// port_id[0] - bits 31:00
	// port_id[1] - bits 63:32
	// port_id[2] - bits 95:64
	int port_id[MAC_NARROW_0_MODE_PORT_CNT];
};

struct port_info {
	int size;
	int base;
	int mode_max;
	char name[STR_BUF_MAX];
	char prefix[STR_BUF_MAX];
};

struct group {
	char name[STR_BUF_MAX];
	char id[STR_BUF_MAX + 1];
	int lsb;
	int msb;
	int changes;
	uint32_t prev;
};

struct groups {
	int port_id;
	char mictor_name[STR_BUF_MAX];
	int cnt;
	struct group group[MAX_GROUPS];
	int offset;     // location of the group in the 256/128 ela sample
};

struct lcu_bt_conf_tag {
	uint32_t controller_sub_ch_en    :6,
		 modem_sub_ch_en         :6,
		 rsv1                    :20;
	uint32_t controller_sub_ch_idx0  :6,
		 rsv2                    :2,
		 controller_sub_ch_idx1  :6,
		 rsv3                    :2,
		 controller_sub_ch_idx2  :6,
		 rsv4                    :2,
		 controller_sub_ch_idx3  :6,
		 rsv5                    :2;
	uint32_t controller_sub_ch_idx4  :6,
		 rsv6                    :2,
		 controller_sub_ch_idx5  :6,
		 rsv7                    :18;
	uint32_t modem_sub_ch_idx0       :6,
		 rsv8                    :2,
		 modem_sub_ch_idx1       :6,
		 rsv9                    :2,
		 modem_sub_ch_idx2       :6,
		 rsv10                   :2,
		 modem_sub_ch_idx3       :6,
		 rsv11                   :2;
	uint32_t modem_sub_ch_idx4       :6,
		 rsv12                   :2,
		 modem_sub_ch_idx5       :6,
		 rsv13                   :18;
	uint32_t controller_mask_idx     :4,
		 rsv14                   :28;
	uint32_t controller_mask[3];
	uint32_t modem_mask_idx          :4,
		 rsv15                   :28;
	uint32_t modem_mask[3];
};

struct lcu_common_mode {
	uint32_t ch0_conf     :3,
		 ch1_conf     :3,
		 ch2_conf     :3,
		 ch3_conf     :3,
		 ch4_conf     :3,
		 ch5_conf     :3,
		 rsv1         :2,
		 int_raw_stat :3,
		 capture_mode :1,
		 blk_exp      :8;
};

// LCU Common info - 13 dwords
struct lcu_common_tag {
	uint32_t la_version;
	struct lcu_common_mode lcu_mode;
	uint32_t lcu_status;
	uint32_t lcu_start_addr;
	uint32_t lcu_write_addr;
	uint32_t lcu_end_addr;
	uint32_t rec_start_timestamp;
	uint32_t rec_end_timestamp;
	uint32_t lcu_common_vci;
	uint32_t rec_stop_addr;
	uint32_t blk_wr_cnt;
	uint32_t lcu_bt_en;
	uint32_t lcu_bt_ch_valid;
};

// LCU Mac eLA info - 13 dwords
struct lcu_mac_conf_tag {
	uint32_t ch0_enable :1,
		 ch0_select :5,
		 rsv1       :2,
		 ch1_enable :1,
		 ch1_select :5,
		 rsv2       :2,
		 rsv3       :16;
	uint32_t mac_debug_port_sela;
	uint32_t mac_debug_port_selb;
	uint32_t mac_debug_port_selc;
	uint32_t mac_debug_port_control;
	uint32_t mac_sampling_mask[8];
};

// LCU Phy general info - 20 dwords
struct lcu_phy_gnrl {
	uint32_t    lcu_dmem_start;               // 0.0  // LCU_DMEM_START_ADDR
	uint32_t    lcu_dmem_size           :20,  // 1.0  // LCU_DMEM_SIZE
		    lcu_status              :6,   // 1.20 // LCU_STATUS
		    lcu_mpif_data_sel       :2,   // 1.26 // LCU_MPIF_DATA_SELECT
		    lcu_rx_riu_out20s_en    :3,   // 1.28 // LCU_RX_RIU_OUT20S_EN
		    rsv1                    :1;   // 1.31 // reserved
	uint32_t    lcu_phy_ch_strt_ptrn_mask[8]; // 2.0  // LCU_CH0_STRT_PTRN_MASK_REG0-7
	uint32_t    lcu_phy_ch_stop_ptrn_mask[8]; // 10.0 // LCU_CH0_STOP_PTRN_MASK_REG0-7
	uint32_t    lcu_phy_ch_mictors_bmp_0;     // 18.0 // LCU_MICTORS_BITMAP_REG0
	uint32_t    lcu_phy_ch_mictors_bmp_1;     // 19.0 // LCU_MICTORS_BITMAP_REG1
};

// LCU Phy Channel info - 2 dwords
struct lcu_phy_channel {
	uint32_t    lcu_phy_ch_conf         :12,
		    lcu_phy_ch_chains_bmp   :6,
		    rsv1                    :2,
		    lcu_phy_ch_decimation   :3,
		    rsv2                    :9;
	uint32_t    lcu_phy_ch_trig_status  :18,
		    rsv3                    :13,
		    lcu_phy_ch_en           :1;
};

// LCU info per PHY struct - 35 dwords
struct lcu_phy_conf_tag {
	struct lcu_phy_gnrl    lcu_phy_gnrl;        // 20 dw
	struct lcu_phy_channel lcu_phy_channel[2];  // 4  dw
	uint32_t lcu_phy_regs[LCU_PHY_REGS_MAX];    // 11 dw
};

// LCU configuration info - 84 dwords
// Struct MUST be aligned with struct in la.c
struct la_conf_tag {
	struct lcu_bt_conf_tag  lcu_bt_conf;  // 13 dwords
	struct lcu_common_tag   lcu_common;   // 13 dwords
	struct lcu_mac_conf_tag lcu_mac_conf; // 13 dwords
	struct lcu_phy_conf_tag lcu_phy_conf; // 35 dwords
	uint32_t dsp_version;
	uint32_t rficw_dbg_sel;
	uint32_t pciew_dbg_sel;
	uint32_t pta_dbg_sel;
	uint32_t bau_dbg_sel;
	uint32_t rxm_dbg_sel;
	uint32_t txm_dbg_sel;
	uint32_t idma_dbg_sel;
	uint32_t usbw_dbg_sel;
	uint32_t usbc_dbg_sel;
};

struct chan_info {
	bool enable;
	uint32_t select;
	uint32_t vci;
	uint32_t num_of_ch_groups;
	struct groups sig_group[MAX_NUM_OF_SIGNAL_GROUPS];
	uint8_t  hw_sel[LCU_NUM_OF_LEGACY_MICTORS];
	bool mask_enable;
	uint8_t conf;
};

struct la_tag {
	uint32_t la_version;
	bool generate_vcd;
	char *dumpdir;
	char *raw_dump_file_path;
	FILE *fp_vcd;
	FILE *fp_btdump;
	FILE *fp_rficwdump;
	struct la_conf_tag lcu_conf;
	uint32_t buf_size;
	uint32_t wr_blk_size;
	uint32_t wr_blk_cnt;
	uint32_t last_wr_index;
	uint32_t is_buf_wrapped;
	uint32_t samples_width;
	uint32_t samples_num;
	uint32_t trigger_point;
	uint32_t trigger_time;
	uint32_t sampling[8];
	struct chan_info lcu_chan[LCU_COMMON_CHAN_CNT];
	struct chan_info bt_ctrl_chan[BT_LCU_CHAN_CNT];
	struct groups controls;
	uint32_t debug_top_sel;
	uint32_t controller_mask[3];
	uint32_t modem_mask[3];
	uint32_t controller_subch_cnt;
	uint32_t modem_subch_cnt;
	uint16_t dbg_sel[PORT_ID_MAX];
	int samples_per_vci[LCU_VCI_MAX];
};

typedef struct {
	uint32_t data[LCU_WIDE_ENTRY_SIZE];
} sample_t;

#endif // _GENVCD_H_
