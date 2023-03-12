/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2019-2022, Celeno Corporation. */


#ifndef BTCL_H
#define BTCL_H


// Use 256 bytes for exception struct
#define IPC_BACKTRACE_DEPTH 15

/* The address is 0x40023F00 for SMAC
 * For other masters it should be 0x60323F00
 * Because chip_ops_read_bulk() adds 0x60000000,
 *  using this address without first digit
 */
#define IPC_SHARED_RAM_BASE_ADDR    0x00323F00
#define IPC_EXCEPTION_PATTERN       0xE09474C7
#define IPC_DSLAVE_PATTERN          0x6B093345

/* Version info are the last 3 uint32_t */
#define BTCL_SMAC_IROM_VERSION      (SMAC_IRAM_FW_ADDR + 0x1FFF4)
#define BTCL_SMAC_IRAM_TIMESTAMP    (SMAC_IRAM_FW_ADDR + 0x1FFF8)
#define BTCL_SMAC_IRAM_VERSION      (SMAC_IRAM_FW_ADDR + 0x1FFFC)


//unhandled exeptions list
#define   EXCEPTION_ILLEGALINSTRUCTION             0
#define   EXCEPTION_INSTRUCTIONFETCHERROR          2
#define   EXCEPTION_LOADSTOREERROR                 3
#define   EXCEPTION_INTEGERDIVIDEBYZERO            6
#define   EXCEPTION_SPECULATION                    7
#define   EXCEPTION_PRIVILEGED                     8
#define   EXCEPTION_UNALIGNED                      9
#define   EXCEPTION_INSTTLBMISS                   16
#define   EXCEPTION_INSTTLBMULTIHIT               17
#define   EXCEPTION_INSTFETCHPRIVILEGE            18
#define   EXCEPTION_INSTFETCHPROHIBITED           20
#define   EXCEPTION_LOADSTORETLBMISS              24
#define   EXCEPTION_LOADSTORETLBMULTIHIT          25
#define   EXCEPTION_LOADSTOREPRIVILEGE            26
#define   EXCEPTION_LOADPROHIBITED                28
#define   EXCEPTION_STOREPROHIBITED               29


// struct for tensilica  backtrace
struct ipc_backtrace_struct {
	u32 pc;
	u32 saved_a2;
	u32 saved_a3;
	u32 saved_a4;
};

// struct for tensilica  exception indication
struct ipc_exception_struct {
	// pattern indicating exception occurred
	u32 pattern;
	// exception type
	u32 type;
	// epc register content
	u32 epc;
	// exsave register content
	u32 excsave;
	// backtrace data
	struct ipc_backtrace_struct backtrace[IPC_BACKTRACE_DEPTH];
};

struct dslave_err_table_struct {
	u16 value;
	u16 mask;
	const char *name;
};


typedef struct cl_chip * (* btcl_hci_to_chip_device_f)(struct hci_dev *hdev);
void btcl_init_celeno(struct hci_dev *hdev, btcl_hci_to_chip_device_f func);
struct cl_chip *btcl_get_chip_by_mac_address(const u8 *addr);

#endif  /* BTCL_H */
