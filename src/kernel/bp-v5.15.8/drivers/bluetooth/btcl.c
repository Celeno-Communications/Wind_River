/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2019-2022, Celeno Corporation. */


#include <linux/module.h>

#include <net/bluetooth/bluetooth.h>
#include <net/bluetooth/hci_core.h>

#include "chip.h"
#include "reg_macsys_gcu.h"
#include "btcl.h"
#include "reg_ipc.h"
#include "ipc_shared.h"


#define BTCL_RECOVERY_TIMEOUT   1000


struct btcl_recovery_work {
	struct delayed_work ws;
	struct cl_chip *chip;
	char name[32];
};


static btcl_hci_to_chip_device_f hci_to_chip_device = NULL;

static const struct dslave_err_table_struct dslave_err_table[] = {
	{0x001, 0x1ef, "Host"},
	{0x020, 0x1f0, "UMAC"},
	{0x040, 0x1f0, "LMAC"},
	{0x060, 0x1f0, "SMAC"},
	{0x080, 0x1ef, "Eth2Wlan"},
	{0x0a0, 0x1ff, "NATT0"},
	{0x0c0, 0x1ef, "PCIEW/BOOTER"},
	{0x0e0, 0x1ef, "MAC_HW_TOP0_MAC0"},
	{0x100, 0x1f8, "RXM0"},
	{0x120, 0x1f8, "TXM0"},
	{0x140, 0x1ff, "BAP0"},
	{0x160, 0x1ff, "BRU"},
	{0x180, 0x1ef, "USBW"},
	{0x1a0, 0x1f0, "USBC"},
	{0x1c0, 0x1ff, "BAU"},
	{0x1e0, 0x1f0, "IDMA"},
};

static const char * const dslave_err_phy_table[] = {
	"Clear",
	"MAC_SUBSYS0",
	"DMSS0",
	"PMSS0"
};

static const char * const dslave_err_burst_type_table[] = {
	"FIXED", "INCR", "WRAP", "Reserved"
};

static const char *btcl_exception_to_string(u32 type)
{
	switch (type) {

	case EXCEPTION_ILLEGALINSTRUCTION:
		return "Illegal exception";
	case EXCEPTION_INSTRUCTIONFETCHERROR:
		return "Instruction fetch error";
	case EXCEPTION_LOADSTOREERROR:
		return "Load/store error";
	case EXCEPTION_INTEGERDIVIDEBYZERO:
		return "Divide by zero";
	case EXCEPTION_SPECULATION:
		return "Speculation";
	case EXCEPTION_PRIVILEGED:
		return "Privileged";
	case EXCEPTION_UNALIGNED:
		return "Unaligned";
	case EXCEPTION_INSTTLBMISS:
		return "Inst TLB miss";
	case EXCEPTION_INSTTLBMULTIHIT:
		return "Inst TLB multi hit";
	case EXCEPTION_INSTFETCHPRIVILEGE:
		return "Inst fetch privilege";
	case EXCEPTION_INSTFETCHPROHIBITED:
		return "Inst fetch prohibited";
	case EXCEPTION_LOADSTORETLBMISS:
		return "Load/store TLB miss";
	case EXCEPTION_LOADSTORETLBMULTIHIT:
		return "Load/store TLB multi hit";
	case EXCEPTION_LOADSTOREPRIVILEGE:
		return "Load/store privilege";
	case EXCEPTION_LOADPROHIBITED:
		return "Load prohibited";
	case EXCEPTION_STOREPROHIBITED:
		return "Store prohibited";
	default:
		break;
	}
		return "Unknown";
}

static inline int btcl_get_axi_master_id(u32 excsave)
{
	return (excsave & MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_MASK) >>
		MACSYS_GCU_AXI_ERROR_INFO_AXI_ERROR_MASTER_ID_LSB;
}


static void btcl_hw_error_show_exception(struct ipc_exception_struct *ipce, const char *chip_name)
{
	int i;
	const char *exc;

	exc = btcl_exception_to_string(ipce->type);

	BT_WARN("%s: Exception %s epc=0x%x excsave=0x%x",
		chip_name, exc, ipce->epc, ipce->excsave);

	for (i = 0; i < IPC_BACKTRACE_DEPTH; i++) {
		if (!ipce->backtrace[i].pc)
			break;
		BT_WARN("%s: Call 0x%x saved a2=0x%x a3=0x%x a4=0x%x",
			chip_name, ipce->backtrace[i].pc, ipce->backtrace[i].saved_a2,
			ipce->backtrace[i].saved_a3, ipce->backtrace[i].saved_a4);
	}
}

static inline u32 btcl_get_burst_length(u32 excsave)
{
	return (excsave & MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_MASK) >>
		MACSYS_GCU_AXI_ERROR_INFO_BURST_LENGTH_LSB;
}

static inline u32 btcl_get_burst_type(u32 excsave)
{
	return (excsave & MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_MASK) >>
		MACSYS_GCU_AXI_ERROR_INFO_BURST_TYPE_LSB;
}

static inline u32 btcl_check_error_made_by_mac(u32 axi_type)
{
	return !!(axi_type & MACSYS_GCU_AXI_ERROR_INT_STATUS_AXI_ERROR_EVENT_BIT);
}

static void btcl_hw_error_show_dslave_mac(struct ipc_exception_struct *ipce, const char *chip_name)
{
	int i;
	const char *str_master_id = "";
	int axi_master_id = btcl_get_axi_master_id(ipce->excsave);

	for (i = 0; ARRAY_SIZE(dslave_err_table); i++) {
		if ((axi_master_id & dslave_err_table[i].mask) == dslave_err_table[i].value) {
			str_master_id = dslave_err_table[i].name;
			break;
		}
	}

	BT_WARN("%s: Dslave error status=%s addr=0x%x burst length=%d type=%s"
		" read/write=%s master_id=0x%03x master=%s",
		chip_name,
		btcl_check_error_made_by_mac(ipce->type) ? "MAC AXI " : "",
		ipce->epc,
		btcl_get_burst_length(ipce->excsave),
		dslave_err_burst_type_table[btcl_get_burst_type(ipce->excsave)],
		(ipce->excsave & MACSYS_GCU_AXI_ERROR_INFO_READ_WRITE_B_BIT) ? "read" : "write",
		axi_master_id, str_master_id);

	for (i = 0; i < IPC_BACKTRACE_DEPTH; i++) {
		if (!ipce->backtrace[i].pc)
			break;
		BT_WARN("%s: Call 0x%x saved a2=0x%x a3=0x%x a4=0x%x",
			chip_name, ipce->backtrace[i].pc, ipce->backtrace[i].saved_a2,
			ipce->backtrace[i].saved_a3, ipce->backtrace[i].saved_a4);
	}
}

static inline u32 btcl_get_phy_burst_length(u32 excsave)
{
	return (excsave & MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_MASK) >>
		MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_LEN_LSB;
}

static inline u32 btcl_get_phy_burst_type(u32 excsave)
{
	return (excsave & MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_MASK) >>
		MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_BURST_TYPE_LSB;
}

static inline u32 btcl_check_error_made_by_phy(u32 axi_type)
{
	return !!(axi_type & MACSYS_GCU_AXI_ERROR_INT_STATUS_PHY_AXI_ERROR_EVENT_BIT);
}

static void btcl_hw_error_show_dslave_phy(struct ipc_exception_struct *ipce, const char *chip_name)
{
	int i;
	const char *str_master_id = "";
	int axi_master_id = btcl_get_axi_master_id(ipce->excsave);

	if (axi_master_id < ARRAY_SIZE(dslave_err_phy_table)) {
		str_master_id = dslave_err_phy_table[axi_master_id];
	}

	BT_WARN("%s: Dslave error status=%s addr=0x%x burst length=%d type=%s"
		" read/write=%s master_id=0x%03x master=%s",
		chip_name,
		btcl_check_error_made_by_phy(ipce->type) ? "PHY AXI " : "",
		ipce->epc,
		btcl_get_phy_burst_length(ipce->excsave),
		dslave_err_burst_type_table[btcl_get_phy_burst_type(ipce->excsave)],
		(ipce->excsave & MACSYS_GCU_PHY_AXI_ERROR_INFO_PHY_AXI_ERROR_RW_BIT) ? "read" : "write",
		axi_master_id, str_master_id);

	for (i = 0; i < IPC_BACKTRACE_DEPTH; i++) {
		if (!ipce->backtrace[i].pc)
			break;
		BT_WARN("%s: Call 0x%x saved a2=0x%x a3=0x%x a4=0x%x",
			chip_name, ipce->backtrace[i].pc, ipce->backtrace[i].saved_a2,
			ipce->backtrace[i].saved_a3, ipce->backtrace[i].saved_a4);
	}
}

static void btcl_hw_error_show_dslave(struct ipc_exception_struct *ipce, const char *chip_name)
{
	if (btcl_check_error_made_by_phy(ipce->type))
		btcl_hw_error_show_dslave_phy(ipce, chip_name);
	else
		btcl_hw_error_show_dslave_mac(ipce, chip_name);
}

static int btcl_dump_smac_stack(struct cl_chip *chip, const char *chip_name)
{
	struct ipc_exception_struct *ipce;
	u32 res;

	ipce = kzalloc(sizeof(*ipce), GFP_KERNEL);
	res = chip_ops_read_bulk(chip, IPC_SHARED_RAM_BASE_ADDR, sizeof(*ipce), (u8 *)ipce);

	if (res) {
		BT_ERR("%s: Error %d reading CLI", chip_name, res);
	} else {
		if (ipce->pattern == IPC_EXCEPTION_PATTERN) {
			btcl_hw_error_show_exception(ipce, chip_name);
			chip_ops_write32(chip, IPC_SHARED_RAM_BASE_ADDR, 0);
		} else if (ipce->pattern == IPC_DSLAVE_PATTERN) {
			btcl_hw_error_show_dslave(ipce, chip_name);
			chip_ops_write32(chip, IPC_SHARED_RAM_BASE_ADDR, 0);
		} else {
			res = -EAGAIN;
		}
	}

	kfree(ipce);

	return res;
}

static void btcl_recovery_handler(struct cl_chip *chip, const char *chip_name)
{
	if (btcl_dump_smac_stack(chip, chip_name) == 0) {
		chip_reset(chip,
			   SMAC_OCD_HALT_ON_RESET,
			   SMAC_DRESET,
			   SMAC_RUN_STALL,
			   SMAC_BRESET,
			   SMAC_DEBUG_ENABLE);

		chip_ops_smac_fw_upload(chip);
	}
}

/**
 * get_chip_by_idx - Get the Celeno Chip structure pointer
 * @chip_idx:	Chip id number
 *
 * cl_chip structure allocated during kernel module init.
 * chip->conf are filled when probe is executed.
 * Return cl_chip if probe is executed.
 */
struct cl_chip *get_chip_by_idx(u8 chip_idx)
{
	struct cl_chip *chip;

	chip = cl_chip_get(chip_idx);
	if (chip && chip->conf)
		return chip;
	else
		return NULL;
}

static void btcl_hw_error_celeno(struct hci_dev *hdev, u8 code)
{
	struct cl_chip *chip = hci_to_chip_device(hdev);
	int i;

	BT_ERR("%s: Hardware error 0x%2.2x", hdev->name, code);

	if (code == 0xc) {
		if (chip) {
			btcl_recovery_handler(chip, hdev->name);
		} else {
			for (i = 0; i < CHIP_MAX; i++) {
				chip = get_chip_by_idx(i);
				if (chip)
					btcl_recovery_handler(chip, hdev->name);
			}
		}
	}
}

static void btcl_recovery_work_do(struct work_struct *ws)
{
	/* Worker for restarting hw. */
	struct btcl_recovery_work *recovery_work = container_of(ws, struct btcl_recovery_work, ws.work);

	btcl_recovery_handler(recovery_work->chip, &recovery_work->name[0]);

	recovery_work->chip->is_smac_recovery = false;
	kfree(recovery_work);
}

static struct workqueue_struct *btcl_workqueue;

static void btcl_recovery_work_sched(struct cl_chip *chip, const char *chip_name, int timeout)
{
	/*
	 * Schedule work to restart device and firmware
	 * This is scheduled when driver detects hw assert storm.
	 */
	struct btcl_recovery_work *recovery_work;
	int name_len;

	if (chip->is_smac_recovery) {
		pr_warn("Chip %d: Failed to re-run recovery when previous is in progress!\n",
			chip->idx);
		return;
	}

	chip->is_smac_recovery = true;

	/* Recovery_work will be freed by btcl_recovery_work_do */
	recovery_work = kzalloc(sizeof(*recovery_work), GFP_ATOMIC);

	if (!recovery_work)
		return;

	INIT_DELAYED_WORK(&recovery_work->ws, btcl_recovery_work_do);
	recovery_work->chip = chip;
	name_len = strlen(chip_name);
	if (name_len < sizeof(recovery_work->name)) {
		memcpy(recovery_work->name, chip_name, name_len);
	} else {
		memcpy(recovery_work->name, chip_name, sizeof(recovery_work->name) - 1);
		recovery_work->name[sizeof(recovery_work->name) - 1] = 0;
	}

	queue_delayed_work(btcl_workqueue, &recovery_work->ws, timeout);
}

#ifdef CONFIG_DEMO_ENABLED
static int btcl_smac_irq_status(struct cl_chip *chip, u32 status)
{
	char name[15];

	if (status & IPC_IRQ_S2H_HW_ERROR) {
		sprintf(name, "chip %d", chip->idx);
		btcl_recovery_work_sched(chip, name, BTCL_RECOVERY_TIMEOUT);
	}

	return 0;
}
#endif

static void btcl_read_version(struct cl_chip *chip)
{
	chip_ops_read32(chip, BTCL_SMAC_IROM_VERSION,   &chip->bt_rom_version);
	chip_ops_read32(chip, BTCL_SMAC_IRAM_TIMESTAMP, &chip->bt_ram_timestamp);
	chip_ops_read32(chip, BTCL_SMAC_IRAM_VERSION,   &chip->bt_ram_version);
}

struct cl_chip *btcl_get_chip_by_mac_address(const u8 *addr)
{
	struct cl_chip *chip;
	int i;

	for (i = 0; i < CHIP_MAX; i++) {
		chip = get_chip_by_idx(i);
		if (chip && (memcmp(chip->conf->rw_data_public_addr, addr,
				sizeof(chip->conf->rw_data_public_addr)) == 0))
			return chip;
	}

	return NULL;
}
EXPORT_SYMBOL(btcl_get_chip_by_mac_address);

void btcl_init_celeno(struct hci_dev *hdev, btcl_hci_to_chip_device_f func)
{
	int i;
	struct cl_chip *chip;

#ifdef CONFIG_DEMO_ENABLED
	for (i = 0; i < CHIP_MAX; i++) {
		chip = get_chip_by_idx(i);

		if (chip) {
			chip->smac_irq_status = btcl_smac_irq_status;
			ipc_xmac_2_host_enable_set_set(chip, IPC_IRQ_S2H_HW_ERROR);
		}
	}
#endif

	hdev->hw_error = btcl_hw_error_celeno;
	hci_to_chip_device = func;

	for (i = 0; i < CHIP_MAX; i++) {
		chip = get_chip_by_idx(i);

		if (chip)
			btcl_read_version(chip);
	}
}
EXPORT_SYMBOL(btcl_init_celeno);


static int __init btcl_module_init(void)
{
	btcl_workqueue = create_singlethread_workqueue("btcl_workqueue");

	return 0;
}
module_init(btcl_module_init);

static void __exit btcl_module_exit(void)
{
	destroy_workqueue(btcl_workqueue);
}
module_exit(btcl_module_exit);


MODULE_DESCRIPTION("Bluetooth support for Celeno devices");
MODULE_LICENSE("GPL");
MODULE_SOFTDEP("pre: cl_core");

