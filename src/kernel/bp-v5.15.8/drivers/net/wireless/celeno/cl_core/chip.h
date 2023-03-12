/* SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause */
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#ifndef CHIP_H
#define CHIP_H

#include "chip_config.h"

#define LMAC_DRAM_FW_ADDR 0x00200000
#define LMAC_IRAM_FW_ADDR 0x00240000
#define SMAC_DRAM_FW_ADDR 0x00300000
#define SMAC_IRAM_FW_ADDR 0x00340000
#define UMAC_DRAM_FW_ADDR 0x00280000
#define UMAC_IRAM_FW_ADDR cl_chip_umac_iram_fw_addr
#define LOCAL_UMAC_DRAM_FW_ADDR 0x40000000
#define LOCAL_UMAC_IRAM_FW_ADDR 0x40080000
#define LMAC_DRAM_SIZE 0x20000 /* 128 KB */
#define LMAC_IRAM_SIZE 0x40000 /* 256 KB */
#define SMAC_DRAM_SIZE 0x28000 /* 160 KB */
#define SMAC_IRAM_SIZE 0x20000 /* 128 KB */
#define UMAC_DRAM_SIZE cl_chip_umac_dram_size
#define UMAC_IRAM_SIZE cl_chip_umac_iram_size
#define IRAM_START_OFFSET 0x80000
#define UMAC_DRAM_SIZE_A 0x30000 /* 192 KB */
#define UMAC_DRAM_SIZE_B 0x40000 /* 256 KB */
#define UMAC_IRAM_SIZE_A 0x30000 /* 192 KB */
#define UMAC_IRAM_SIZE_B 0x80000 /* 512 KB */
#define UMAC_IRAM_FW_ADDR_A 0x002c0000
#define UMAC_IRAM_FW_ADDR_B 0x00500000

#define SMAC_DRAM9_FILE_ADDR 0x24000
#define SMAC_DRAM9_CONF_SHIFT 0x03c00
#define SMAC_DRAM9_CONF_FILE_ADDR (SMAC_DRAM9_FILE_ADDR + SMAC_DRAM9_CONF_SHIFT)
#define SMAC_DRAM9_FILE_MAX_SIZE 0x400

/*
 * Totally at OTP there are 0x1FFF bits (1024 bytes = 256 words)
 * so, 256 bits (32 * 8) are needed for mapping the all otp
 */
#define OTP_BROKEN_ADDR_BITMAP_SIZE   8

struct otp_booter {
	u8 start_pattern[2];
	u8 address[3];
	u8 data_vendor_id[2];
	u8 data_device_id[2];
	u8 address_jtag_mode[3];
	u8 jtag_mode_data[4];
	u8 address_combo_phy[3];
	u8 disable_ssc[4];
	u8 end_pattern[2];
	u8 reserved[39];
} __packed;

struct otp_sw_mode {
	u8 version_id[4];
	u8 hw_metal_fix_id[4];
	u8 reserved[12];
} __packed;

struct otp_security_configuration {
	u8 security_enabled[4];
	u8 security_AES_key_owner_bitmap[1];
	u8 security_ECC_key_owner_bitmap[1];
	u8 alignment[2];
} __packed;

struct otp_security_keys {
	u8 aes_key0[32];
	u8 aes_key1[32];
	u8 aes_key2[32];
	u8 aes_key3[32];
	u8 ecc_key0[52];
	u8 ecc_key1[52];
	u8 ecc_key2[52];
	u8 ecc_key3[52];
} __packed;

struct otp_security_keys_control {
	u8 aes_key0_revoke[4];
	u8 aes_key1_revoke[4];
	u8 aes_key2_revoke[4];
	u8 aes_key3_revoke[4];
	u8 ecc_key0_revoke[4];
	u8 ecc_key1_revoke[4];
	u8 ecc_key2_revoke[4];
	u8 ecc_key3_revoke[4];
} __packed;

struct otp_security_min_version_enforcement {
	u8 min_fw_revision_0[4];
	u8 min_fw_revision_1[4];
	u8 min_fw_revision_2[4];
	u8 min_fw_revision_3[4];
} __packed;

struct otp_wifi_tx_power_module_offset {
	u8 wifi_module_offset_ch0_2_4G;
	u8 wifi_module_offset_ch1_2_4G;
	u8 wifi_module_offset_ch0_5_7G;
	u8 wifi_module_offset_ch1_5_7G;
} __packed;

struct otp_bt_tx_power_module_offset {
	u8 BT_tx_power_module_offset;
	u8 BT_tx_power[3];
} __packed;

struct otp_module_hw {
	u8 module_hw_type;
	u8 module_hw_rev_id_major;
	u8 module_hw_rev_id_minor;
	u8 otp_eeprom_format;
} __packed;

struct otp_rfic_version {
	u8 rfic_wifi_version_calib[2];
	u8 rfic_bt_version_calib[2];
	u8 rfic_lut_version_calib;
	u8 rfic_spare_version_calib;
} __packed;

struct otp_die_id {
	u8 test_revision_minor[2];
	u8 test_revision_major[2];
	u8 column;
	u8 row;
	u8 wafer;
	u8 lot_character_5;
	u8 lot_character_4;
	u8 lot_character_3;
	u8 lot_character_2;
	u8 lot_character_1;
} __packed;

struct otp {
	struct otp_booter booter;
	u8 pn[4];
	u8 mac_address[6];
	u8 mac_padding[2];
	u8 bd_address[6];
	u8 bd_padding[2];
	struct otp_sw_mode sw_mode;
	struct otp_security_configuration security_configuration;
	struct otp_security_keys security_keys;
	struct otp_security_keys_control security_keys_control;
	struct otp_security_min_version_enforcement security_min_version_enforcement;
	struct otp_wifi_tx_power_module_offset wifi_tx_power_module_offset;
	struct otp_bt_tx_power_module_offset bt_tx_power_module_offset;
	struct otp_module_hw module_hw;
	struct otp_rfic_version rfic_version;
	u8 reserved_version[2];
	u16 freq_offset;
	u8 reserved_freq_offset[2];
	u8 ambient_temperature[4];
	u8 bt_tx_power_calib_offset[16];
	u8 wifi_tx_power_calib_offfset[120];
	u8 wifi_value_pl_idx[4];
	u8 bt_power_calib_temp[6];
	u8 bt_reserved[2];
	u8 wifi_power_calib_temp[60];
	u8 reserved[24];
	struct otp_die_id die_id;
	u8 mbist[256];
} __packed;

enum cl_bus_type {
	CL_BUS_TYPE_PCI,
	CL_BUS_TYPE_USB,
};

#define IS_PCI_BUS_TYPE(chip) ((chip)->bus_type == CL_BUS_TYPE_PCI)
#define IS_USB_BUS_TYPE(chip) ((chip)->bus_type == CL_BUS_TYPE_USB)

#define CL_STEP_ID_STEP_A 0x1
#define CL_STEP_ID_STEP_B 0x2
#define CL_STEP_ID_UNDEF  0xff
#define CL_STEP_HW_REG_STEP_A 0xa
#define CL_STEP_HW_REG_STEP_B 0xb
#define IS_CL_CHIP_STEP_A(chip) ((chip)->step_id != CL_STEP_ID_STEP_B)
#define IS_CL_CHIP_STEP_B(chip) ((chip)->step_id == CL_STEP_ID_STEP_B)

/* PHY device options */
enum {
	PHY_DEV_DENALI,   /* Denali - 6g/5g/24g */
	PHY_DEV_RESERVED, /* Reserved */
	PHY_DEV_DUMMY,    /* Dummy */
	PHY_DEV_FRU,      /* Fake RF Unit */
	PHY_DEV_MAX,
};

/* AMPDU RX reorder mode */
enum {
	RX_REORDER_BY_MAC80211,
	RX_REORDER_BY_DRIVER,
	RX_REORDER_BY_FIRMWARE,
	RX_REORDER_MAX
};

enum cl_bt_mode {
	BT_MODE_OFF,
	BT_MODE_UART,
	BT_MODE_USB,
	BT_MODE_DUAL_UART,
};

#define IS_REAL_PHY(chip) ((chip)->conf->ci_phy_dev == PHY_DEV_DENALI)

enum cl_fw_file_type {
	CL_FW_FILE_LMAC,
	CL_FW_FILE_SMAC,
	CL_FW_FILE_UMAC,

	CL_FW_FILE_MAX
};

struct cli_usb_param_version;

struct cl_chip_ops {
	int (*mask_write32)(struct cl_chip *chip, u32 addr, u32 val,
			    u32 mask, bool resp);
	int (*write32)(struct cl_chip *chip, u32 addr, u32 val);
	int (*write_bulk)(struct cl_chip *chip, u32 addr,
			  u8 *data, int size);
	int (*read32)(struct cl_chip *chip, u32 addr, u32 *val);
	int (*read_bulk)(struct cl_chip *chip, u32 addr, u32 length, u8 *data);
	int (*fw_upload)(struct cl_chip *chip, enum cl_fw_file_type type,
			 u8 *data, int size);
	int (*umac_fw_upload)(struct cl_chip *chip);
	int (*smac_fw_upload)(struct cl_chip *chip);
	int (*config_set)(struct cl_chip *chip, char *buf, loff_t size);
	void (*config_print)(struct cl_chip *chip);
	void *(*alloc_coherent)(struct cl_chip *chip, size_t size,
				gfp_t mem_flags, dma_addr_t *dma);
	void (*free_coherent)(struct cl_chip *chip, size_t size,
			      void *cpu_addr, dma_addr_t dma);
	int (*print_umac_stats)(struct cl_chip *chip);
	int (*get_umac_version)(struct cl_chip *chip,
				struct cli_usb_param_version *version);
	int (*usb_set_alternate)(struct cl_chip *chip, int ifnum, int val);
};

struct fw_file_params {
	u32 dram_addr;
	int dram_size;
	u32 iram_addr;
	int iram_size;
};

struct cl_irq_stats {
	unsigned long last_rx;
	unsigned long last_tx;
	unsigned long last_isr;
	u32 last_isr_statuses;
	u32 count_irq;
	u32 ipc_success;
};

struct cl_lcu_db {
	char *raw_lcu_config;
	struct list_head cmd_head;
	int error_state;
};

struct cl_xmem {
	u32 total_used;
	u32 size;
};

struct cl_iq_dcoc_conf {
	bool dcoc_calib_needed;
	u8 dcoc_file_num_ant;
	bool bt_dcoc_calib_needed;
	u8 bt_dcoc_file_num_ant;
	bool iq_calib_needed;
	u8 iq_file_num_ant;
	bool force_calib;
	u32 iq_calib_mode_bmp;
};

struct eeprom;
struct cl_hw;

struct cl_chip {
	u8 idx;
	struct device *dev;
	const struct cl_chip_ops *ops;
	enum cl_bus_type bus_type;
	struct cl_chip_conf *conf;
	bool fw_test;
	u8 reg_dbg;
	bool smac_active;
	bool umac_active;
	bool is_smac_recovery;
	bool is_umac_recovery;
	struct cl_irq_stats irq_stats;
	struct cl_hw *cl_hw_tcv0;
	bool rf_reg_overwrite;
	struct eeprom *eeprom_cache;
	int (*eeprom_read_block)(struct cl_chip *chip, u16 addr, u16 num_of_byte, u8 *data);
	int (*eeprom_write_block)(struct cl_chip *chip, u16 addr, u16 num_of_byte, u8 *data);
	struct otp *otp_cache;
	u32 bitmap_broken_otp_addr[OTP_BROKEN_ADDR_BITMAP_SIZE];
	int (*otp_read_block)(struct cl_chip *chip, u16 addr, u16 num_of_words, u32 *data);
	int (*otp_write_block)(struct cl_chip *chip, u16 addr, u16 num_of_byte, u8 *data);
#ifdef CONFIG_DEMO_ENABLED
	int (*smac_irq_status)(struct cl_chip *chip, u32 status);
#endif
	struct cl_lcu_db lcu_db;
	struct cl_xmem xmem_db;

	u32 bt_rom_version;
	u32 bt_ram_version;
	/* Number of seconds since 01.01.2020 00:00:00 */
	u32 bt_ram_timestamp;
	struct cl_iq_dcoc_conf iq_dcoc_conf;
	bool is_calib_in_progress;
	u8 step_id;
	/* must be last */
	u8 drv_priv[] __aligned(sizeof(void *));
};

static inline bool cl_chip_is_tcv_enabled(struct cl_chip *chip, u8 tcv_idx)
{
	return chip->conf->ce_tcv_enabled[tcv_idx];
}

static inline bool cl_chip_is_tcv0_enabled(struct cl_chip *chip)
{
	return chip->conf->ce_tcv_enabled[TCV0];
}

static inline bool cl_chip_is_enabled(struct cl_chip *chip)
{
	return cl_chip_is_tcv0_enabled(chip);
}

#ifdef CONFIG_DEMO_ENABLED
static inline int cl_chip_smac_irq_status(struct cl_chip *chip, u32 status)
{
	if (chip->smac_irq_status)
		return chip->smac_irq_status(chip, status);
	else
		return -EFAULT;
}
#endif

static inline u32 cl_chip_umac_dram_size(struct cl_chip *chip)
{
	if (IS_CL_CHIP_STEP_B(chip))
		return UMAC_DRAM_SIZE_B;

	return UMAC_DRAM_SIZE_A;
}

static inline u32 cl_chip_umac_iram_size(struct cl_chip *chip)
{
	if (IS_CL_CHIP_STEP_B(chip))
		return UMAC_IRAM_SIZE_B;

	return UMAC_IRAM_SIZE_A;
}

static inline u32 cl_chip_umac_iram_fw_addr(struct cl_chip *chip)
{
	if (IS_CL_CHIP_STEP_B(chip))
		return UMAC_IRAM_FW_ADDR_B;

	return UMAC_IRAM_FW_ADDR_A;
}

int cl_chip_alloc_all(size_t priv_size);
struct cl_chip *cl_chip_get(u8 chip_idx);
void cl_chip_dealloc(struct cl_chip *chip);
void cl_chip_dealloc_all(void);
int fw_file_get_params(struct cl_chip *chip,
		       enum cl_fw_file_type type,
		       struct fw_file_params *params);
int cl_core_chip_init(struct cl_chip *chip);
void cl_core_chip_deinit(struct cl_chip *chip);
void chip_reset(struct cl_chip *chip,
		u32 ocd_halt_on_reset,
		u32 dreset,
		u32 run_stall,
		u32 breset,
		u32 debug_enable);
#endif /* CHIP_H */

