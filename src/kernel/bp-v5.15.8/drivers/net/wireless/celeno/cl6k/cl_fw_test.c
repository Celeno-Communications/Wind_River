// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Communications Ltd. */

#include "reg_access.h"
#include "cl_fw_test.h"
#include "cl_fw_file.h"
#include "cl_irq.h"

static void *virt_dma_mem;
static dma_addr_t phys_dma_mem;

#define TEST_SUCCESS 0xAAAA5555

static char *fw_test_name[] = {
	"regtestfw.bin",
	"memtestfw.bin",
	"inttestfw.bin",
	"dspmbxtestfw.bin",
	"coretestfw.bin",
	"ipctestfw.bin",
	"mccitestfw.bin",
	"cycletestfw.bin",
	"edmatestfw.bin",
	"edmatptestfw.bin",
	"udmatestfw.bin",
};

/* MAC test type */
enum MAC_TEST_TYPE {
	MAC_REGISTERS_TEST,
	MAC_MEMORY_TEST,
	MAC_INTERRUPTS_TEST,
	MAC_DSP_MAIL_BOX_TEST,
	MAC_CORE_TEST,
	MAC_IPC_TEST,
	MAC_MCCI_TEST,
	MAC_CYCLE_TEST,
	MAC_EDMA_TEST,
	MAC_EDMA_TP_TEST,
	MAC_UDMA_TEST,
	MAC_NO_TEST = 0xFF,
};

#define FW_REGS_TEST_MODULES_NUMBER 12

static char *fw_regs_test_modules[] = {
	"",
	"wrong test mode",
	"SHARED RAM",
	"MAC core",
	"IPC",
	"DMA",
	"SYS CTRL",
	"AGC",
	"MDM CONFIG",
	"RC",
	"DUMMY PHY",
	"TRIDENT"
};

#define FW_MEM_TESTS_NUMBER 37

static char *fw_memory_test[] = {
	"",
	"shared RAM data bus",
	"shared RAM address bus",
	"shared RAM device",
	"Direct shared RAM data bus",
	"Direct shared RAM address bus",
	"Direct shared RAM device",
	"phy DMEM RAM data bus",
	"phy DMEM RAM address bus",
	"phy DMEM RAM device",
	"phy PMEM RAM data bus",
	"phy PMEM RAM address bus",
	"phy PMEM RAM device",
	"phy XMEM RAM data bus",
	"phy XMEM RAM address bus",
	"phy XMEM RAM device",
	"local IRAM data bus",
	"local IRAM address bus",
	"local IRAM device",
	"local DRAM data bus",
	"local DRAM address bus",
	"local DRAM device",
	"remote IRAM data bus",
	"remote IRAM address bus",
	"remote IRAM device",
	"remote DRAM data bus",
	"remote DRAM address bus",
	"remote DRAM device",
	"remote_1 IRAM data bus",
	"remote_1 IRAM address bus",
	"remote_1 IRAM device",
	"remote_1 DRAM data bus",
	"remote_1 DRAM address bus",
	"remote_1 DRAM device",
	"local DRAM 2 data bus",
	"local DRAM 2 address bus",
	"local DRAM 2 device"
};

/* EDMA test parameters */
#define EDMA_MEM_SIZE (0x60000) /* 384K in Denali */

#define FW_EDMA_TESTS_NUMBER 7

static char *fw_edma_test[] = {
	"",
	"EDMA init",
	"EDMA start",
	"EDMA send host message",
	"EDMA get host message",
	"EDMA compare messages",
	"EDMA end"
};

#define FW_INT_TESTS_NUMBER 32

static char *fw_int_name[] = {
	"INTC_XTOSTIMER0",     /* 0 */
	"INTC_XTOSSW0",        /* 1 */
	"INTC_PHY_RIU",        /* 2 */
	"INTC_MACERROR",       /* 3 */
	"INTC_MACGEN",         /* 4 */
	"INTC_MACRX",          /* 5 */
	"INTC_MACTIMER",       /* 6 */
	"INTC_MACTX",          /* 7 */
	"INTC_LLI",            /* 8 */
	"INTC_BMU",            /* 9 */
	"INTC_IPC_XMAC",       /* 10 */
	"INTC_IPC_YMAC",       /* 11 */
	"INTC_IPC_HOST",       /* 12 */
	"INTC_PHY_DSP",        /* 13 */
	"INTC_I2C",            /* 14 */
	"INTC_EDMA",           /* 15 */
	"INTC_ETH2WLAN_DONE",  /* 16 */
	"INTC_UNUSED1",        /* 17 */
	"INTC_UNUSED2",        /* 18 */
	"INTC_UNUSED3",        /* 19 */
	"INTC_XTOSTIMER1",     /* 20 */
	"INTC_MACHIGH",        /* 21 */
	"INTC_NATT_DONE",      /* 22 */
	"INTC_PTA",            /* 23 */
	"INTC_UNUSED5",        /* 24 */
	"INTC_UNUSED6",        /* 25 */
	"INTC_XTOSTIMER2",     /* 26 */
	"INTC_XTOSSW1",        /* 27 */
	"INTC_AHBSLAVE_ERROR", /* 28 */
	"INTC_UNUSED7",        /* 29 */
	"INTC_UNUSED8",        /* 30 */
	"INTC_NMI",            /* 31 */
};

#define HOST_REG_IPC_EMB_BASE_ADDR  0x007C4000
#define IPC_APP2EMB_UNMASK_SET_ADDR (HOST_REG_IPC_EMB_BASE_ADDR + 0x0c)
#define IPC_APP2EMB_TRIGGER_ADDR    (HOST_REG_IPC_EMB_BASE_ADDR + 0x80)
#define IPC_APP2UMAC_TRIGGER_ADDR   (HOST_REG_IPC_EMB_BASE_ADDR + 0x84)
#define IPC_APP2SMAC_TRIGGER_ADDR   (HOST_REG_IPC_EMB_BASE_ADDR + 0x88)

#define REG_MAC_HW0_BASE_ADDR 0x00600000
#define REG_MAC_HW1_BASE_ADDR 0x00680000

#define MAC_HW0_GEN_INT_EVENT_FORCE_ADDR      (REG_MAC_HW0_BASE_ADDR + 0x0000810C)
#define MAC_HW0_HIGH_PRI_INT_EVENT_FORCE_ADDR (REG_MAC_HW0_BASE_ADDR + 0x00008128)
#define MAC_HW0_RX_INT_EVENT_FORCE_ADDR       (REG_MAC_HW0_BASE_ADDR + 0x00008144)
#define MAC_HW0_TX_INT_EVENT_FORCE_ADDR       (REG_MAC_HW0_BASE_ADDR + 0x00008160)
#define MAC_HW0_TIMER_INT_EVENT_FORCE_ADDR    (REG_MAC_HW0_BASE_ADDR + 0x00008250)
#define MAC_HW0_ERROR_INT_EVENT_FORCE_ADDR    (REG_MAC_HW0_BASE_ADDR + 0x000080F0)

#define MAC_HW1_GEN_INT_EVENT_FORCE_ADDR      (REG_MAC_HW1_BASE_ADDR + 0x0000810C)
#define MAC_HW1_HIGH_PRI_INT_EVENT_FORCE_ADDR (REG_MAC_HW1_BASE_ADDR + 0x00008128)
#define MAC_HW1_RX_INT_EVENT_FORCE_ADDR       (REG_MAC_HW1_BASE_ADDR + 0x00008144)
#define MAC_HW1_TX_INT_EVENT_FORCE_ADDR       (REG_MAC_HW1_BASE_ADDR + 0x00008160)
#define MAC_HW1_TIMER_INT_EVENT_FORCE_ADDR    (REG_MAC_HW1_BASE_ADDR + 0x00008250)
#define MAC_HW1_ERROR_INT_EVENT_FORCE_ADDR    (REG_MAC_HW1_BASE_ADDR + 0x000080F0)

#define INTERRUPTS_COUNTER_START_ADDR   (TEST_END_INDICATION_ADDR + 0x00000010)
/* There are 32 interrupts and each counter is a 4 byte variable) */
#define INTERRUPTS_COUNTER_SIZE         (FW_INT_TESTS_NUMBER * sizeof(u32))
/* Set places for the interrupts latency */
#define INTERRUPT_LATENCY_LEVEL_1       (INTERRUPTS_COUNTER_START_ADDR + INTERRUPTS_COUNTER_SIZE)
#define INTERRUPT_LATENCY_LEVEL_2       (INTERRUPT_LATENCY_LEVEL_1 + 0x4)
#define INTERRUPT_LATENCY_LEVEL_3       (INTERRUPT_LATENCY_LEVEL_2 + 0x4)
/* Set places for the interrupts latency */
#define INTERRUPT_INTER_LATENCY_LEVEL_1 (INTERRUPT_LATENCY_LEVEL_3 + 0x4)
#define INTERRUPT_INTER_TIME_LEVEL_1    (INTERRUPT_INTER_LATENCY_LEVEL_1 + 0x4)
#define INTERRUPT_INTER_LATENCY_LEVEL_3 (INTERRUPT_INTER_TIME_LEVEL_1 + 0x4)
#define INTERRUPT_INTER_TIME_LEVEL_3    (INTERRUPT_INTER_LATENCY_LEVEL_3 + 0x4)

#define IRAM_OFFSET                0x00004000
/* Host <--> LMAC base address communication in shared RAM */
#define LMAC_COMM_BASE_ADDR        0x00008000
#define EDMA_LMAC_COMM_BASE_ADDR   0x00003000
/* Host <--> UMAC base address communication in shared RAM */
#define UMAC_COMM_BASE_ADDR        0x00009000
/* Host <--> SMAC base address communication in shared RAM */
#define SMAC_COMM_BASE_ADDR        0x0000A000

#define COMM_INPUT_BASE_ADDR       0x00000000
#define COMM_OUTPUT_BASE_ADDR      0x00000100
#define EDMA_COMM_OUTPUT_BASE_ADDR 0x00001500

/* Indicate that test has terminated */
#define TEST_END_INDICATION_ADDR      (COMM_OUTPUT_BASE_ADDR + 0x00000000)
#define EDMA_TEST_END_INDICATION_ADDR (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000000)

#define EDMA_TEST_DBG1_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000104)
#define EDMA_TEST_DBG2_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000108)
#define EDMA_TEST_DBG3_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x0000010c)
#define EDMA_TEST_DBG4_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000110)
#define EDMA_TEST_DBG5_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000114)
#define EDMA_TEST_DBG6_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000118)
#define EDMA_TEST_DBG7_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x0000011c)
#define EDMA_TEST_DBG8_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000120)
#define EDMA_TEST_DBG9_ADDR  (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000124)
#define EDMA_TEST_DBG10_ADDR (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000128)
/* Used for assert only */
#define EDMA_TEST_READ_ASSERT_VAL1 (EDMA_COMM_OUTPUT_BASE_ADDR + 0x0000012C)
#define EDMA_TEST_READ_ASSERT_VAL2 (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000130)
#define EDMA_TEST_READ_ASSERT_VAL3 (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000134)
#define EDMA_TEST_READ_ASSERT_VAL4 (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000138)

/*
 * In case the test terminated successfully  =  TEST_SUCCESS.
 * In case of failure it indicates the module/Phase of failure
 */
#define TEST_FAIL_MODULE_ADDR      (COMM_OUTPUT_BASE_ADDR + 0x00000004)
/*
 * In case the test terminated successfully  =  TEST_SUCCESS.
 * In case of failure it indicates the address of failure (not always relevant)
 */
#define TEST_FAIL_ADDRESS_ADDR     (COMM_OUTPUT_BASE_ADDR + 0x00000008)

#define LOCAL_IRAM_BASE_ADDR       0x40080000
#define LOCAL_DRAM_BASE_ADDR       0x40000000
#define LOCAL_DRAM_2_BASE_ADDR     0x50000000
#define LMAC_REMOTE_DRAM_BASE_ADDR 0x60200000
#define LMAC_REMOTE_IRAM_BASE_ADDR 0x60240000
#define UMAC_REMOTE_DRAM_BASE_ADDR 0x60280000
#define UMAC_REMOTE_IRAM_BASE_ADDR(chip) (0x60000000 + cl_chip_umac_iram_fw_addr(chip))
#define SMAC_REMOTE_DRAM_BASE_ADDR 0x60300000
#define SMAC_REMOTE_IRAM_BASE_ADDR 0x60340000

#define PHY0_DMEM_BASE 0x60400000
#define PHY0_DMEM_SIZE 0x40000

/* Host <--> PHY0 test number and offset */
#define PHY0_DSPMBX_TEST_OFFSET    0xA00
#define PHY0_DSPMBX_TEST_VAL       0x104

#define PHY_XMEM_BASE 0x60480000
#define PHY_XMEM_SIZE 0x20000

#define PHY_PMEM_BASE 0x604C0000
#define PHY_PMEM_SIZE 0x20000

/* LMAC memory addresses and size for memory test */
/* IRAM base address */
#define LMAC_LOCAL_IRAM_TEST_BASE_ADDR      (LOCAL_IRAM_BASE_ADDR + IRAM_OFFSET)
#define LMAC_LOCAL_IRAM_TEST_SIZE_ADDR      (LMAC_IRAM_SIZE - IRAM_OFFSET)

/* DRAM base address */
#ifndef LMAC_DRAM_SIZE
#error LMAC_DRAM_SIZE not define
#endif

#define LMAC_LOCAL_DRAM_TEST_BASE_ADDR   (LOCAL_DRAM_BASE_ADDR + IRAM_OFFSET)
#define LMAC_LOCAL_DRAM_TEST_SIZE_ADDR   (LMAC_DRAM_SIZE - IRAM_OFFSET)
#define LMAC_DRAM_2_SIZE                 0x0010000
#define LMAC_LOCAL_DRAM_2_TEST_BASE_ADDR (LOCAL_DRAM_2_BASE_ADDR + IRAM_OFFSET)
#define LMAC_LOCAL_DRAM_2_TEST_SIZE_ADDR (LMAC_DRAM_2_SIZE - IRAM_OFFSET)

/* UMAC memory addresses and size for memory test are defined in chip.h*/
/* IRAM base address */


#ifndef UMAC_IRAM_SIZE
#error UMAC_IRAM_SIZE not define
#endif
#define UMAC_LOCAL_IRAM_TEST_BASE_ADDR      (LOCAL_IRAM_BASE_ADDR + IRAM_OFFSET)
#define UMAC_LOCAL_IRAM_TEST_SIZE_ADDR(chip)      (cl_chip_umac_iram_size(chip) - IRAM_OFFSET)

/* DRAM base address */
#ifndef UMAC_DRAM_SIZE
#error UMAC_DRAM_SIZE not define
#endif
#define UMAC_LOCAL_DRAM_TEST_BASE_ADDR      (LOCAL_DRAM_BASE_ADDR + IRAM_OFFSET)
#define UMAC_LOCAL_DRAM_TEST_SIZE_ADDR(chip)      (cl_chip_umac_dram_size(chip) - IRAM_OFFSET)

/* SMAC memory addresses and size for memory test */
/* IRAM base address */
#define SMAC_LOCAL_IRAM_TEST_BASE_ADDR      (LOCAL_IRAM_BASE_ADDR + IRAM_OFFSET)
#define SMAC_LOCAL_IRAM_TEST_SIZE_ADDR      (SMAC_IRAM_SIZE - IRAM_OFFSET)

/* DRAM base address */
#define SMAC_LOCAL_DRAM_TEST_BASE_ADDR      (LOCAL_DRAM_BASE_ADDR + IRAM_OFFSET)
#define SMAC_LOCAL_DRAM_TEST_SIZE_ADDR      (SMAC_DRAM_SIZE - IRAM_OFFSET)

#define SMAC_DRAM_2_SIZE                 0x0010000
#define SMAC_LOCAL_DRAM_2_TEST_BASE_ADDR (LOCAL_DRAM_2_BASE_ADDR + IRAM_OFFSET)
#define SMAC_LOCAL_DRAM_2_TEST_SIZE_ADDR (SMAC_DRAM_2_SIZE - IRAM_OFFSET)

/* Shared RAM memory addresses and size for memory test */
#define SHARED_RAM_TEST_BASE_ADDR     0x60000000
/* sram size - last 128k used by the bootrom */
#define SHARED_RAM_TEST_SIZE_ADDR_USB (0x60000 - 0x20000)

/* Memory test input parameters */
#define MEM_LOCAL_IRAM_BASE_ADDR    (COMM_INPUT_BASE_ADDR + 0x00000000)
#define MEM_LOCAL_IRAM_SIZE_ADDR    (COMM_INPUT_BASE_ADDR + 0x00000004)
#define MEM_LOCAL_DRAM_BASE_ADDR    (COMM_INPUT_BASE_ADDR + 0x00000008)
#define MEM_LOCAL_DRAM_SIZE_ADDR    (COMM_INPUT_BASE_ADDR + 0x0000000C)
#define MEM_LOCAL_DRAM_2_BASE_ADDR  (COMM_INPUT_BASE_ADDR + 0x00000010)
#define MEM_LOCAL_DRAM_2_SIZE_ADDR  (COMM_INPUT_BASE_ADDR + 0x00000014)
#define MEM_REMOTE_IRAM_BASE_ADDR   (COMM_INPUT_BASE_ADDR + 0x00000018)
#define MEM_REMOTE_IRAM_SIZE_ADDR   (COMM_INPUT_BASE_ADDR + 0x0000001C)
#define MEM_REMOTE_DRAM_BASE_ADDR   (COMM_INPUT_BASE_ADDR + 0x00000020)
#define MEM_REMOTE_DRAM_SIZE_ADDR   (COMM_INPUT_BASE_ADDR + 0x00000024)
#define MEM_REMOTE_1_IRAM_BASE_ADDR (COMM_INPUT_BASE_ADDR + 0x00000028) /* SMAC support */
#define MEM_REMOTE_1_IRAM_SIZE_ADDR (COMM_INPUT_BASE_ADDR + 0x0000002C)
#define MEM_REMOTE_1_DRAM_BASE_ADDR (COMM_INPUT_BASE_ADDR + 0x00000030)
#define MEM_REMOTE_1_DRAM_SIZE_ADDR (COMM_INPUT_BASE_ADDR + 0x00000034)
#define PHY_DMEM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000038)
#define PHY_DMEM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x0000003C)
#define PHY_PMEM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000040)
#define PHY_PMEM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000044)
#define PHY_XMEM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000048)
#define PHY_XMEM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x0000004C)
#define MEM_SRAM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000050)
#define MEM_SRAM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000054)

/* IPC test input parameters */
#define HOST_CFG_INPUT_LMAC_VALID   (COMM_INPUT_BASE_ADDR + 0x00000000)
#define HOST_CFG_INPUT_UMAC_VALID   (COMM_INPUT_BASE_ADDR + 0x00000004)
#define HOST_CFG_INPUT_SMAC_VALID   (COMM_INPUT_BASE_ADDR + 0x00000008)
#define TEST_HOST_INT_COUNT_ADDR    (COMM_OUTPUT_BASE_ADDR + 0x00000010)
#define TEST_XMAC_INT_COUNT_ADDR    (COMM_OUTPUT_BASE_ADDR + 0x00000014)
#define TEST_YMAC_INT_COUNT_ADDR    (COMM_OUTPUT_BASE_ADDR + 0x00000018)

/* MCCI test input parameters */
#define HOST_CFG_INPUT_LINE_IDX (COMM_INPUT_BASE_ADDR + 0x00000000)
#define HOST_CFG_INPUT_DW_1     (COMM_INPUT_BASE_ADDR + 0x00000004)
#define HOST_CFG_INPUT_DW_2     (COMM_INPUT_BASE_ADDR + 0x00000008)

/* EDMA test input parameters */
#define EDMA_PHYS_MEM_ALLOC_ADDR_LO              (COMM_INPUT_BASE_ADDR + 0x00000000)
#define EDMA_PHYS_MEM_ALLOC_ADDR_HI              (COMM_INPUT_BASE_ADDR + 0x00000004)
#define EDMA_PHYS_MEM_SIZE_ADDR                  (COMM_INPUT_BASE_ADDR + 0x00000008)
#define EDMA_HOST_DATA_US_START_LLI_ADDR         (COMM_INPUT_BASE_ADDR + 0x00000014)
#define EDMA_HOST_DATA_US_LLI_NUM_ADDR           (COMM_INPUT_BASE_ADDR + 0x00000018)
#define EDMA_HOST_DATA_DS_START_LLI_ADDR         (COMM_INPUT_BASE_ADDR + 0x0000001C)
#define EDMA_HOST_DATA_DS_LLI_NUM_ADDR           (COMM_INPUT_BASE_ADDR + 0x00000020)
#define EDMA_HOST_DATA_BUFFER_NUM_ARR_ADDR       (COMM_INPUT_BASE_ADDR + 0x00000024)
#define EDMA_HOST_DATA_ODD_BUFFER_SIZE_ARR_ADDR  (COMM_INPUT_BASE_ADDR + 0x000000A4)
#define EDMA_HOST_DATA_EVEN_BUFFER_SIZE_ARR_ADDR (COMM_INPUT_BASE_ADDR + 0x00000124)

#define PDMA_HOST_BRU_DESC_INFO                  (COMM_INPUT_BASE_ADDR + 0x00000348)

#define UDMA_LMAC_TEST_CONTROL_START_ADDR   0x2000
#define UDMA_SMAC_TEST_CONTROL_START_ADDR   0x4000
#define UDMA_TEST_CONTROL_SEQUENCE_ID_OFS   0x4
#define UDMA_TEST_CONTROL_CMD_OFS           0x8
#define UDMA_TEST_CONTROL_SIZE              0x100
#define UDMA_LMAC_TEST_STATUS_START_ADDR    0x3000
#define UDMA_SMAC_TEST_STATUS_START_ADDR    0x5000
#define UDMA_TEST_STATUS_SEQUENCE_ID_OFS    0x4
#define UDMA_TEST_STATUS_RESULT_OFS         0xc
#define UDMA_TEST_STATUS_STATE_OFS          0x10
#define UDMA_TEST_STATUS_SIZE               0x100
/* LLI area lays right after TestControl structure in LMAC & SMAC too */
#define UDMA_LLI_DESC_START_OFS             UDMA_TEST_CONTROL_SIZE
#define UDMA_LLI_DESC_SIZE                  0x300

/* Registers test input parameters */
#define REGS_MODE_ADDR                           (COMM_INPUT_BASE_ADDR + 0x00000000)

/* Offset as defined in FW */
#define CACHE_POLICY_NO_CACHE  0 /* bypassed: no cache. */
#define CACHE_POLICY_WT        1 /* Write-through */
#define CACHE_POLICY_WB        2 /* Write-back */
#define CACHE_POLICY_WB_NA     3 /* writeback no alloc */

static char *cache_policy_name[] = {
	"NO_CACHE",     /* 0 */
	"WT",           /* 1 */
	"WB",           /* 2 */
	"WB_NA",        /* 3 */
};

#define TEST_INDICATION_POLICY_OFFSET (0x40)
#define TEST_INDICATION_CYCLE_16UNROLL(policy) (COMM_OUTPUT_BASE_ADDR + 0x00000010 + \
					       TEST_INDICATION_POLICY_OFFSET * (policy))
#define TEST_INDICATION_CYCLE_REVERSE_16UNROLL(policy) (COMM_OUTPUT_BASE_ADDR + 0x00000014 + \
					      TEST_INDICATION_POLICY_OFFSET * (policy))
#define TEST_INDICATION_CYCLE_16UNROLL_RMW(policy) (COMM_OUTPUT_BASE_ADDR + 0x00000018 + \
						   TEST_INDICATION_POLICY_OFFSET * (policy))
#define TEST_INDICATION_CYCLE_32UNROLL(policy) (COMM_OUTPUT_BASE_ADDR + 0x0000001c + \
				      TEST_INDICATION_POLICY_OFFSET * (policy))
#define TEST_INDICATION_CYCLE_REVERSE_32UNROLL(policy) (COMM_OUTPUT_BASE_ADDR + 0x00000020 + \
						       TEST_INDICATION_POLICY_OFFSET * (policy))
#define TEST_INDICATION_CYCLE_32UNROLL_RMW(policy) (COMM_OUTPUT_BASE_ADDR + 0x00000024 + \
						   TEST_INDICATION_POLICY_OFFSET * (policy))
#define TEST_INDICATION_CYCLE_1DW_READ(policy) (COMM_OUTPUT_BASE_ADDR + 0x00000028 + \
					       TEST_INDICATION_POLICY_OFFSET * (policy))
#define TEST_INDICATION_CYCLE_1KB_READ(policy) (COMM_OUTPUT_BASE_ADDR + 0x0000002c + \
					       TEST_INDICATION_POLICY_OFFSET * (policy))
#define TEST_INDICATION_ACTUAL_CACHE_POLICY(policy) (COMM_OUTPUT_BASE_ADDR + 0x00000030 + \
						    TEST_INDICATION_POLICY_OFFSET * (policy))


#define INTERRUPT_TEST_DEBUG_AREA_ADDR  (COMM_OUTPUT_BASE_ADDR + 0x00000300)
#define INTERRUPT_TEST_DEBUG_AREA_SIZE  0x00000100

static void cl_show_mem(struct cl_hw *cl_hw, u32 base_addr, u32 lines)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 r[4];
	u32 i;

	for (i = 0; i < lines; i++) {
		r[0] = cl_reg_read(chip, base_addr + 0);
		r[1] = cl_reg_read(chip, base_addr + 4);
		r[2] = cl_reg_read(chip, base_addr + 8);
		r[3] = cl_reg_read(chip, base_addr + 12);
		pr_notice("%4x: %08x %08x %08x %08x\n", base_addr, r[0], r[1], r[2], r[3]);
		base_addr += 0x10;
	}
}

/* Show memory with 20 bytes per line */
static void cl_show_mem24(struct cl_hw *cl_hw, u32 base_addr, u32 lines)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 r[6];
	u32 i;

	for (i = 0; i < lines; i++) {
		r[0] = cl_reg_read(chip, base_addr + 0);
		r[1] = cl_reg_read(chip, base_addr + 4);
		r[2] = cl_reg_read(chip, base_addr + 8);
		r[3] = cl_reg_read(chip, base_addr + 12);
		r[4] = cl_reg_read(chip, base_addr + 16);
		r[5] = cl_reg_read(chip, base_addr + 20);
		pr_notice("%4x: %08x %08x %08x %08x %08x %08x\n", base_addr,
			  r[0], r[1], r[2], r[3], r[4], r[5]);
		base_addr += sizeof(r);
	}
}

static int cl_wait_4_test_end_ind(struct cl_hw *cl_hw, u32 base_addr, u32 loops)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 cnt = 0;
	u32 res;

	while ((res = cl_reg_read(chip, base_addr + TEST_END_INDICATION_ADDR)) != 0x1) {
		ssleep(1);
		if (cnt++ == loops * chip->conf->ci_scale_down_fw) {
			TEST_INFO("\t\tTest Timed Out !!! Result=0x%x\n", res);
			cl_show_mem(cl_hw, base_addr + COMM_OUTPUT_BASE_ADDR, 4);
			return -1;
		}
	}

	res = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);
	if (res != TEST_SUCCESS) {
		TEST_INFO("Test failed. Result=0x%x\n", res);
		cl_show_mem(cl_hw, base_addr + COMM_OUTPUT_BASE_ADDR, 4);
		return -1;
	}

	TEST_INFO("Test passed.\n");

	return 0;
}

static void cl_apre_cycle_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 fail_module;
	u32 policy;

	msleep(1000);

	/* Wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 10))
		return;

	fail_module = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);

	if (fail_module == TEST_SUCCESS) {
		TEST_INFO("\t\tSUCCESS\n");
		for (policy = CACHE_POLICY_NO_CACHE ; policy <= CACHE_POLICY_WB_NA ; policy++) {
			TEST_INFO("[%s] 16_UNROLL: total %u cycles.\n", cache_policy_name[policy],
				  cl_reg_read(chip,
					      base_addr +
					      TEST_INDICATION_CYCLE_16UNROLL(policy)));
			TEST_INFO("[%s] 16_UNROLL_REVERSE: total %u cycles.\n",
				  cache_policy_name[policy],
				  cl_reg_read(chip,
					      base_addr +
					      TEST_INDICATION_CYCLE_REVERSE_16UNROLL(policy)));
			TEST_INFO("[%s] 16_UNROLL_REVERSE_RMW: total %u cycles.\n",
				  cache_policy_name[policy],
				  cl_reg_read(chip,
					      base_addr +
					      TEST_INDICATION_CYCLE_16UNROLL_RMW(policy)));
			TEST_INFO("[%s] 32_UNROLL: total %u cycles.\n",
				  cache_policy_name[policy],
				  cl_reg_read(chip,
					      base_addr +
					      TEST_INDICATION_CYCLE_32UNROLL(policy)));
			TEST_INFO("[%s] 32_UNROLL_REVERSE: total %u cycles.\n",
				  cache_policy_name[policy],
				  cl_reg_read(chip,
					      base_addr +
					      TEST_INDICATION_CYCLE_REVERSE_32UNROLL(policy)));
			TEST_INFO("[%s] 32_UNROLL_REVERSE_RMW: total %u cycles.\n",
				  cache_policy_name[policy],
				  cl_reg_read(chip,
					      base_addr +
					      TEST_INDICATION_CYCLE_32UNROLL_RMW(policy)));
			TEST_INFO("[%s] 1DW_READ: total %u cycles.\n",
				  cache_policy_name[policy],
				  cl_reg_read(chip,
					      base_addr +
					      TEST_INDICATION_CYCLE_1DW_READ(policy)));
			TEST_INFO("[%s] 1DW_READ: total %u cycles.\n",
				  cache_policy_name[policy],
				  cl_reg_read(chip,
					      base_addr +
					      TEST_INDICATION_CYCLE_1DW_READ(policy)));
		}
	} else {
		TEST_INFO("\t\tFAILED\n");
	}
}

#define TEST_INDICATION_RIU_SINGLE_WR    (TEST_END_INDICATION_ADDR + 0x00000008)
#define TEST_INDICATION_RIU_MULTIPLE_WR  (TEST_END_INDICATION_ADDR + 0x0000000c)
#define TEST_INDICATION_MCCI_SINGLE_WR   (TEST_END_INDICATION_ADDR + 0x00000010)
#define TEST_INDICATION_MCCI_MULTIPLE_WR (TEST_END_INDICATION_ADDR + 0x00000014)
#define TEST_INDICATION_RIU_SINGLE_RD    (TEST_END_INDICATION_ADDR + 0x00000018)
#define TEST_INDICATION_RIU_MULTIPLE_RD  (TEST_END_INDICATION_ADDR + 0x0000001c)
#define TEST_INDICATION_MCCI_SINGLE_RD   (TEST_END_INDICATION_ADDR + 0x00000020)
#define TEST_INDICATION_MCCI_MULTIPLE_RD (TEST_END_INDICATION_ADDR + 0x00000024)
#define TEST_INDICATION_AGC_SINGLE_WR    (TEST_END_INDICATION_ADDR + 0x00000028)

static void cl_apre_mcci_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 fail_module;

	msleep(1000);

	/* Wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 10))
		return;

	fail_module = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);

	if (fail_module == TEST_SUCCESS) {
		TEST_INFO("\t\tSUCCESS\n");
		TEST_INFO("RIU_SINGLE_WR: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_RIU_SINGLE_WR));
		TEST_INFO("RIU_MULTIPLE_WR: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_RIU_MULTIPLE_WR));
		TEST_INFO("MCCI_SINGLE_WR: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_MCCI_SINGLE_WR));
		TEST_INFO("MCCI_MULTIPLE_WR: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_MCCI_MULTIPLE_WR));
		TEST_INFO("RIU_SINGLE_RD: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_RIU_SINGLE_RD));
		TEST_INFO("RIU_MULTIPLE_RD: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_RIU_MULTIPLE_RD));
		TEST_INFO("MCCI_SINGLE_RD: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_MCCI_SINGLE_RD));
		TEST_INFO("MCCI_MULTIPLE_RD: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_MCCI_MULTIPLE_RD));
		TEST_INFO("AGC_SINGLE_WR: %d cycles.\n",
			  cl_reg_read(chip, base_addr + TEST_INDICATION_AGC_SINGLE_WR));
	} else {
		TEST_INFO("\t\tFAILED\n");
	}
}

static void cl_apre_ipc_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 fail_module;
	u32 mac_host;
	u32 mac_xmac;
	u32 mac_ymac;
	struct cl_irq_stats *irq_stats = &chip->irq_stats;

	msleep(1000);

	/* IPC test - wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 3))
		return;

	fail_module = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);
	mac_host = cl_reg_read(chip, base_addr + TEST_HOST_INT_COUNT_ADDR);
	mac_xmac = cl_reg_read(chip, base_addr + TEST_XMAC_INT_COUNT_ADDR);
	mac_ymac = cl_reg_read(chip, base_addr + TEST_YMAC_INT_COUNT_ADDR);

	if (fail_module == TEST_SUCCESS && irq_stats->ipc_success)
		TEST_INFO("\t\tSUCCESS host interrupts = %u\n", irq_stats->count_irq);
	else
		TEST_INFO("\t\tFAILED host interrupts = %u\n", irq_stats->count_irq);

	TEST_INFO("MAC host interrupts = %u\n", mac_host);
	TEST_INFO("MAC xmac interrupts = %u\n", mac_xmac);
	TEST_INFO("MAC ymac interrupts = %u\n", mac_ymac);
}

#define EDMA_ITTERATIONS_PERFORMED_ADDR (EDMA_TEST_END_INDICATION_ADDR + 0x00000044)

static void cl_apre_edma_test_dbg_regs_print(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 start_addr = base_addr + EDMA_TEST_DBG1_ADDR;
	u32 dbg_addr;
	u32 i;

	for (i = 0; i < 14; i++) {
		dbg_addr = start_addr + i * 4;

		TEST_INFO("\tdbg reg %d addr 0x%x val = 0x%x\n",
			  i + 1, dbg_addr, cl_reg_read(chip, dbg_addr));
	}
}

static int cl_wait_4_edma_test_end_ind(struct cl_hw *cl_hw, u32 base_addr, u32 loops)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 cnt = 0;

	while (cl_reg_read(chip, base_addr + EDMA_TEST_END_INDICATION_ADDR) == 0x0) {
		ssleep(1);
		if (cnt++ == loops * chip->conf->ci_scale_down_fw) {
			TEST_INFO("\t\tTest Timed Out !!!\n");
			cl_apre_edma_test_dbg_regs_print(cl_hw, base_addr);
			cl_show_mem(cl_hw, base_addr + COMM_OUTPUT_BASE_ADDR, 4);
			return -1;
		}
	}

	return 0;
}

static void cl_pre_edmatest_host_buffs_init(struct cl_hw *cl_hw, u8 *host_base_addr,
					    u32 host_buff_size)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 lli_idx, lli_idx_start, lli_idx_max, buff_idx, dma_buff_nm;
	u32 buff_size, idx, val_to_write;
	u32 data_us_start_lli;
	u32 data_us_llis_nm;
	u32 data_ds_start_lli;
	u32 data_ds_llis_nm;
	u32 dma_data_buff_nm[PCIE_WRAP_LLI_MAX] = {0};
	u32 dma_data_odd_buffer_size[PCIE_WRAP_LLI_MAX] = {0};
	u32 dma_data_even_buffer_size[PCIE_WRAP_LLI_MAX] = {0};
	u32 *host_downstream_addr = NULL;
	u8 *host_upstream_addr = NULL;
	u32 buffer_num, odd_buffer_size, even_buffer_size;

	data_us_start_lli =
		cl_reg_read(chip, EDMA_LMAC_COMM_BASE_ADDR + EDMA_HOST_DATA_US_START_LLI_ADDR);
	data_us_llis_nm =
		cl_reg_read(chip, EDMA_LMAC_COMM_BASE_ADDR + EDMA_HOST_DATA_US_LLI_NUM_ADDR);
	data_ds_start_lli =
		cl_reg_read(chip, EDMA_LMAC_COMM_BASE_ADDR + EDMA_HOST_DATA_DS_START_LLI_ADDR);
	data_ds_llis_nm =
		cl_reg_read(chip, EDMA_LMAC_COMM_BASE_ADDR + EDMA_HOST_DATA_DS_LLI_NUM_ADDR);

	for (lli_idx = 0; lli_idx < PCIE_WRAP_LLI_MAX; lli_idx++) {
		buffer_num = EDMA_LMAC_COMM_BASE_ADDR +
			EDMA_HOST_DATA_BUFFER_NUM_ARR_ADDR + 4 * lli_idx;
		odd_buffer_size = EDMA_LMAC_COMM_BASE_ADDR +
			EDMA_HOST_DATA_ODD_BUFFER_SIZE_ARR_ADDR + 4 * lli_idx;
		even_buffer_size = EDMA_LMAC_COMM_BASE_ADDR +
			EDMA_HOST_DATA_EVEN_BUFFER_SIZE_ARR_ADDR + 4 * lli_idx;

		dma_data_buff_nm[lli_idx] = cl_reg_read(chip, buffer_num);
		dma_data_odd_buffer_size[lli_idx] = cl_reg_read(chip, odd_buffer_size);
		dma_data_even_buffer_size[lli_idx] = cl_reg_read(chip, even_buffer_size);
	}

	host_downstream_addr = (u32 *)host_base_addr;
	lli_idx_start = min_t(u32, PCIE_WRAP_LLI_MAX, data_ds_start_lli);
	lli_idx_max = min_t(u32, PCIE_WRAP_LLI_MAX, data_ds_start_lli + data_ds_llis_nm);

	/* Init downstream buffers */
	for (lli_idx = lli_idx_start; lli_idx < lli_idx_max; lli_idx++) {
		dma_buff_nm = dma_data_buff_nm[lli_idx];
		for (buff_idx = 0; buff_idx < dma_buff_nm; buff_idx++) {
			buff_size = ((buff_idx % 2) == 0) ?
				dma_data_even_buffer_size[lli_idx] :
				dma_data_odd_buffer_size[lli_idx];
			for (idx = 0; idx < (buff_size >> 2); idx++) {
				val_to_write = (lli_idx << 24) | (buff_idx << 8) | (idx & 0xFF);
				*host_downstream_addr = val_to_write;
				host_downstream_addr++;
			}
		}
	}

	/* Init upstream buffers */
	host_upstream_addr = host_base_addr + (host_buff_size / 2);
	memset(host_upstream_addr, 0, (host_buff_size / 2));
}

static u8 cl_apre_edmatest_host_buffs_upstream_compare(struct cl_hw *cl_hw,
						       u8 *host_base_addr, u32 host_buff_size)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 lli_idx, lli_idx_start, lli_idx_max, buff_idx, dma_buff_nm, curr_val;
	u32 buff_size, idx, val_to_compare;
	u32 data_us_start_lli;
	u32 data_us_llis_nm;
	u32 data_ds_start_lli;
	u32 data_ds_llis_nm;
	u32 dma_data_buff_nm[PCIE_WRAP_LLI_MAX] = {0};
	u32 dma_data_odd_buffer_size[PCIE_WRAP_LLI_MAX] = {0};
	u32 dma_data_even_buffer_size[PCIE_WRAP_LLI_MAX] = {0};
	u32 bru_desc_info;
	u32 *host_upstream_addr = NULL;
	u32 buffer_num, odd_buffer_size, even_buffer_size;

	data_us_start_lli = cl_reg_read(chip, EDMA_LMAC_COMM_BASE_ADDR +
					EDMA_HOST_DATA_US_START_LLI_ADDR);
	data_us_llis_nm = cl_reg_read(chip, EDMA_LMAC_COMM_BASE_ADDR +
				      EDMA_HOST_DATA_US_LLI_NUM_ADDR);
	data_ds_start_lli = cl_reg_read(chip, EDMA_LMAC_COMM_BASE_ADDR +
					EDMA_HOST_DATA_DS_START_LLI_ADDR);
	data_ds_llis_nm = cl_reg_read(chip, EDMA_LMAC_COMM_BASE_ADDR +
				      EDMA_HOST_DATA_DS_LLI_NUM_ADDR);

	for (lli_idx = 0; lli_idx < PCIE_WRAP_LLI_MAX; lli_idx++) {
		buffer_num = EDMA_LMAC_COMM_BASE_ADDR +
			EDMA_HOST_DATA_BUFFER_NUM_ARR_ADDR + 4 * lli_idx;
		odd_buffer_size = EDMA_LMAC_COMM_BASE_ADDR +
			EDMA_HOST_DATA_ODD_BUFFER_SIZE_ARR_ADDR + 4 * lli_idx;
		even_buffer_size = EDMA_LMAC_COMM_BASE_ADDR +
			EDMA_HOST_DATA_EVEN_BUFFER_SIZE_ARR_ADDR + 4 * lli_idx;

		dma_data_buff_nm[lli_idx] = cl_reg_read(chip, buffer_num);
		dma_data_odd_buffer_size[lli_idx] = cl_reg_read(chip, odd_buffer_size);
		dma_data_even_buffer_size[lli_idx] = cl_reg_read(chip, even_buffer_size);
	}

	host_upstream_addr = (u32 *)(host_base_addr + (host_buff_size / 2));
	lli_idx_start = min_t(u32, PCIE_WRAP_LLI_MAX, data_us_start_lli);
	lli_idx_max = min_t(u32, PCIE_WRAP_LLI_MAX, data_us_start_lli + data_us_llis_nm);

	for (lli_idx = lli_idx_start; lli_idx < lli_idx_max; lli_idx++) {
		dma_buff_nm = dma_data_buff_nm[lli_idx];
		for (buff_idx = 0; buff_idx < dma_buff_nm; buff_idx++) {
			buff_size = ((buff_idx % 2) == 0) ?
				dma_data_even_buffer_size[lli_idx] :
				dma_data_odd_buffer_size[lli_idx];
			for (idx = 0; idx < (buff_size >> 2); idx++) {
				bru_desc_info = cl_reg_read(chip,
							    EDMA_LMAC_COMM_BASE_ADDR +
							    PDMA_HOST_BRU_DESC_INFO +
							    4 * BRU_MAX_DESC_IN_LLI * lli_idx +
							    4 * buff_idx);
				/*
				 * Compare val with expected val in case of
				 * no_transfer bit is set to 0
				 */
				if (((bru_desc_info >> 1) & 1) == 0)
					val_to_compare = ((lli_idx << 24) |
							  (buff_idx << 8) |
							  (idx & 0xFF));
				else
					val_to_compare = 0;

				curr_val = *host_upstream_addr;
				if (curr_val != val_to_compare)
					return 1;

				host_upstream_addr++;
			}
		}
	}

	return 0;
}

static void dram_type_init_parameters(struct cl_hw *cl_hw,
				      u32 *lmac_dram_size,
				      u32 *lmac_local_dram_test_size_addr,
				      u32 *umac_dram_size,
				      u32 *umac_iram_size,
				      u32 *umac_local_dram_test_size_addr,
				      u32 *umac_local_iram_test_size_addr)
{
	*lmac_dram_size = LMAC_DRAM_SIZE;
	*lmac_local_dram_test_size_addr = LMAC_LOCAL_DRAM_TEST_SIZE_ADDR;
	*umac_dram_size = cl_chip_umac_dram_size(cl_hw->chip);
	*umac_iram_size = cl_chip_umac_iram_size(cl_hw->chip);
	*umac_local_dram_test_size_addr = UMAC_LOCAL_DRAM_TEST_SIZE_ADDR(cl_hw->chip);
	*umac_local_iram_test_size_addr = UMAC_LOCAL_IRAM_TEST_SIZE_ADDR(cl_hw->chip);
}

static void cl_apre_interrupts_fw_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	int i;
	u32 int_cnr = base_addr + INTERRUPTS_COUNTER_START_ADDR;

	/* Wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 50)) {
		cl_show_mem(cl_hw, base_addr + INTERRUPT_TEST_DEBUG_AREA_ADDR,
			    INTERRUPT_TEST_DEBUG_AREA_SIZE / 16);
		return;
	}

	if (base_addr == LMAC_COMM_BASE_ADDR) {
		/* MAC-HW General interrupt */
		cl_reg_write(chip, MAC_HW0_GEN_INT_EVENT_FORCE_ADDR, 0x00000001);
		msleep(100);
		/* MAC-HW High Priority Interrupt */
		cl_reg_write(chip, MAC_HW0_HIGH_PRI_INT_EVENT_FORCE_ADDR, 0x00000040);
		msleep(100);
		/* MAC-HW RX Interrupt */
		cl_reg_write(chip, MAC_HW0_RX_INT_EVENT_FORCE_ADDR, 0x00010000);
		msleep(100);
		/* MAC-HW TIMER interrupt */
		cl_reg_write(chip, MAC_HW0_TIMER_INT_EVENT_FORCE_ADDR, 0x00004000);
		msleep(100);
		/* MAC-HW TX interrupt */
		cl_reg_write(chip, MAC_HW0_TX_INT_EVENT_FORCE_ADDR, 0x00000010);
		msleep(100);
		/* MAC-HW ERROR interrupt */
		cl_reg_write(chip, MAC_HW0_ERROR_INT_EVENT_FORCE_ADDR, 0x00000020);
		msleep(100);
		/* IPC interrupt */
		cl_reg_write(chip, IPC_APP2EMB_TRIGGER_ADDR, 0xFFFFFFFF);
	} else if (base_addr == SMAC_COMM_BASE_ADDR) {
		/* MAC-HW General interrupt */
		cl_reg_write(chip, MAC_HW1_GEN_INT_EVENT_FORCE_ADDR, 0x00000001);
		msleep(100);
		/* MAC-HW High Priority Interrupt */
		cl_reg_write(chip, MAC_HW1_HIGH_PRI_INT_EVENT_FORCE_ADDR, 0x00000040);
		msleep(100);
		/* MAC-HW RX Interrupt */
		cl_reg_write(chip, MAC_HW1_RX_INT_EVENT_FORCE_ADDR, 0x00010000);
		msleep(100);
		/* MAC-HW TIMER interrupt */
		cl_reg_write(chip, MAC_HW1_TIMER_INT_EVENT_FORCE_ADDR, 0x00004000);
		msleep(100);
		/* MAC-HW TX interrupt */
		cl_reg_write(chip, MAC_HW1_TX_INT_EVENT_FORCE_ADDR, 0x00000010);
		msleep(100);
		/* MAC-HW ERROR interrupt */
		cl_reg_write(chip, MAC_HW1_ERROR_INT_EVENT_FORCE_ADDR, 0x00000020);
		msleep(100);
		/* IPC interrupt */
		cl_reg_write(chip, IPC_APP2SMAC_TRIGGER_ADDR, 0xFFFFFFFF);
	} else {
		/* IPC interrupt */
		cl_reg_write(chip, IPC_APP2UMAC_TRIGGER_ADDR, 0xFFFFFFFF);
	}

	msleep(1000);

	/* Print all the interrupts conters */
	for (i = 0; i < FW_INT_TESTS_NUMBER; i++) {
		TEST_INFO("\t\t%s = %u\n", fw_int_name[i], cl_reg_read(chip, int_cnr));
		int_cnr += 4;
	}

	/* Display the interrupt latency for each interrupt level */
	TEST_INFO("\tInterrupt latency (in cycles):\n");
	TEST_INFO("\t\tLEVEL 1: %d\n", cl_reg_read(chip, base_addr + INTERRUPT_LATENCY_LEVEL_1));
	TEST_INFO("\t\tLEVEL 2: %d\n", cl_reg_read(chip, base_addr + INTERRUPT_LATENCY_LEVEL_2));
	TEST_INFO("\t\tLEVEL 3: %d\n", cl_reg_read(chip, base_addr + INTERRUPT_LATENCY_LEVEL_3));

	/*
	 * Display the interrupt latency when an interrupt is
	 * set from an ISR to one in higher level
	 */
	TEST_INFO("\tInter Interrupt latency (in cycles):\n");
	TEST_INFO("\t\tLEVEL 1: %d --> LEVEL 3: %d\n",
		  cl_reg_read(chip, base_addr + INTERRUPT_INTER_LATENCY_LEVEL_1),
		  cl_reg_read(chip, base_addr + INTERRUPT_INTER_LATENCY_LEVEL_3));
	TEST_INFO("\t\tduration in LEVEL 1: %d\n",
		  cl_reg_read(chip, base_addr + INTERRUPT_INTER_TIME_LEVEL_1));
}

#define TEST_MULTIPULE_ACCESS_RESULTS_ADDR    (COMM_OUTPUT_BASE_ADDR + 0x00000020)
#define TEST_SHARED_ACCESS_NUM_ADDR           (TEST_MULTIPULE_ACCESS_RESULTS_ADDR)
#define TEST_SHARED_WRITE_CYCLES_ADDR         (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000004)
#define TEST_SHARED_READ_CYCLES_ADDR          (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000008)
#define TEST_DIRECT_SHARED_ACCESS_NUM_ADDR    (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000000C)
#define TEST_DIRECT_SHARED_WRITE_CYCLES_ADDR  (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000010)
#define TEST_DIRECT_SHARED_READ_CYCLES_ADDR   (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000014)
#define TEST_PHY_ACCESS_NUM_ADDR              (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000018)
#define TEST_PHY_WRITE_CYCLES_ADDR            (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000001C)
#define TEST_PHY_READ_CYCLES_ADDR             (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000020)
#define TEST_PHY_PMEM_ACCESS_NUM_ADDR         (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000024)
#define TEST_PHY_PMEM_WRITE_CYCLES_ADDR       (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000028)
#define TEST_PHY_PMEM_READ_CYCLES_ADDR        (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000002C)
#define TEST_PHY_XMEM_ACCESS_NUM_ADDR         (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000030)
#define TEST_PHY_XMEM_WRITE_CYCLES_ADDR       (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000034)
#define TEST_PHY_XMEM_READ_CYCLES_ADDR        (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000038)
#define TEST_LOCAL_IRAM_ACCESS_NUM_ADDR       (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000003C)
#define TEST_LOCAL_IRAM_WRITE_CYCLES_ADDR     (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000040)
#define TEST_LOCAL_IRAM_READ_CYCLES_ADDR      (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000044)
#define TEST_LOCAL_DRAM_ACCESS_NUM_ADDR       (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000048)
#define TEST_LOCAL_DRAM_WRITE_CYCLES_ADDR     (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000004C)
#define TEST_LOCAL_DRAM_READ_CYCLES_ADDR      (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000050)
#define TEST_LOCAL_DRAM_2_ACCESS_NUM_ADDR     (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000054)
#define TEST_LOCAL_DRAM_2_WRITE_CYCLES_ADDR   (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000058)
#define TEST_LOCAL_DRAM_2_READ_CYCLES_ADDR    (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000005C)
#define TEST_REMOTE_IRAM_ACCESS_NUM_ADDR      (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000060)
#define TEST_REMOTE_IRAM_WRITE_CYCLES_ADDR    (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000064)
#define TEST_REMOTE_IRAM_READ_CYCLES_ADDR     (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000068)
#define TEST_REMOTE_DRAM_ACCESS_NUM_ADDR      (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000006C)
#define TEST_REMOTE_DRAM_WRITE_CYCLES_ADDR    (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000070)
#define TEST_REMOTE_DRAM_READ_CYCLES_ADDR     (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000074)
#define TEST_REMOTE_1_IRAM_ACCESS_NUM_ADDR    (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000078)
#define TEST_REMOTE_1_IRAM_WRITE_CYCLES_ADDR  (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000007C)
#define TEST_REMOTE_1_IRAM_READ_CYCLES_ADDR   (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000080)
#define TEST_REMOTE_1_DRAM_ACCESS_NUM_ADDR    (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000084)
#define TEST_REMOTE_1_DRAM_WRITE_CYCLES_ADDR  (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000088)
#define TEST_REMOTE_1_DRAM_READ_CYCLES_ADDR   (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000008C)

#define TEST_SINGLE_ACCESS_RESULTS_ADDR       (TEST_REMOTE_1_DRAM_READ_CYCLES_ADDR + 0x00000004)
#define TEST_SHARED_WRITE_SINGLE_ADDR         (TEST_SINGLE_ACCESS_RESULTS_ADDR)
#define TEST_SHARED_READ_SINGLE_ADDR          (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000004)
#define TEST_DIRECT_SHARED_WRITE_SINGLE_ADDR  (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000008)
#define TEST_DIRECT_SHARED_READ_SINGLE_ADDR   (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000000C)
#define TEST_PHY_WRITE_SINGLE_ADDR            (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000010)
#define TEST_PHY_READ_SINGLE_ADDR             (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000014)
#define TEST_PHY_PMEM_WRITE_SINGLE_ADDR       (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000018)
#define TEST_PHY_PMEM_READ_SINGLE_ADDR        (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000001C)
#define TEST_PHY_XMEM_WRITE_SINGLE_ADDR       (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000020)
#define TEST_PHY_XMEM_READ_SINGLE_ADDR        (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000024)
#define TEST_LOCAL_IRAM_WRITE_SINGLE_ADDR     (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000028)
#define TEST_LOCAL_IRAM_READ_SINGLE_ADDR      (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000002C)
#define TEST_LOCAL_DRAM_WRITE_SINGLE_ADDR     (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000030)
#define TEST_LOCAL_DRAM_READ_SINGLE_ADDR      (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000034)
#define TEST_LOCAL_DRAM_2_WRITE_SINGLE_ADDR   (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000038)
#define TEST_LOCAL_DRAM_2_READ_SINGLE_ADDR    (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000003C)
#define TEST_REMOTE_IRAM_WRITE_SINGLE_ADDR    (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000040)
#define TEST_REMOTE_IRAM_READ_SINGLE_ADDR     (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000044)
#define TEST_REMOTE_DRAM_WRITE_SINGLE_ADDR    (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000048)
#define TEST_REMOTE_DRAM_READ_SINGLE_ADDR     (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000004C)
#define TEST_REMOTE_1_IRAM_WRITE_SINGLE_ADDR  (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000050)
#define TEST_REMOTE_1_IRAM_READ_SINGLE_ADDR   (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000054)
#define TEST_REMOTE_1_DRAM_WRITE_SINGLE_ADDR  (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000058)
#define TEST_REMOTE_1_DRAM_READ_SINGLE_ADDR   (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000005C)

#define TEST_CYCLES_TIME_FATCH_ADDR           (TEST_REMOTE_1_DRAM_READ_SINGLE_ADDR + 0x00000004)

static void cl_apre_mem_fw_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 fail_module, fail_addr;
	u32 access_num, write_cycles_access, read_cycles_access;
	u32 cycle_fetch_time, write_single_cycles, read_single_cycles;
	u32 write_cycles, read_cycles;

	/*
	 * Since the result and end indication are set in shared memory - Wait till
	 * all the shared memry test are over prior to check the end indication.
	 */
	msleep(5000);

	/* Wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 100)) {
		TEST_INFO("\t\t\ttimeout!!!!\n");
		fail_module = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);
		fail_addr = cl_reg_read(chip, base_addr + TEST_FAIL_ADDRESS_ADDR);
		if (fail_module < FW_MEM_TESTS_NUMBER)
			TEST_INFO("\t\t\tFAIL in %s test at address: %Xh\n",
				fw_memory_test[fail_module], fail_addr);
		else
			TEST_INFO("\t\t\tFAIL - Unknown fail_module (%u)\n", fail_module);
		return;
	}

	fail_module = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);
	fail_addr = cl_reg_read(chip, base_addr + TEST_FAIL_ADDRESS_ADDR);

	if (fail_module == TEST_SUCCESS)
		TEST_INFO("\t\t\tSUCCESS\n");
	else if (fail_module < FW_MEM_TESTS_NUMBER)
		TEST_INFO("\t\t\tFAIL in %s test at address: %Xh\n",
			  fw_memory_test[fail_module], fail_addr);
	else
		TEST_INFO("\t\t\tFAIL - Unknown fail_module (%u)\n", fail_module);

	/* Display the multiple access time to memory in cycles */
	TEST_INFO("\tMultiple memory access time (in cycles):\n");

	/* PHY memory */
	access_num = cl_reg_read(chip, base_addr + TEST_PHY_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr + TEST_PHY_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr + TEST_PHY_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tPHY DMEM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}

	/* PHY PMEM memory */
	access_num = cl_reg_read(chip, base_addr + TEST_PHY_PMEM_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr + TEST_PHY_PMEM_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr + TEST_PHY_PMEM_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tPHY PMEM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}

	/* PHY XMEM memory */
	access_num = cl_reg_read(chip, base_addr + TEST_PHY_XMEM_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr + TEST_PHY_XMEM_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr + TEST_PHY_XMEM_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tPHY XMEM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}

	/* Shared memory */
	access_num = cl_reg_read(chip, base_addr + TEST_SHARED_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr + TEST_SHARED_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr + TEST_SHARED_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tSHARED RAM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}

	/* Local Iram memory */
	access_num = cl_reg_read(chip, base_addr + TEST_LOCAL_IRAM_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr + TEST_LOCAL_IRAM_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr + TEST_LOCAL_IRAM_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tLocal IRAM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}
	/* Local Dram 1 memory */
	access_num = cl_reg_read(chip, base_addr + TEST_LOCAL_DRAM_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr + TEST_LOCAL_DRAM_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr + TEST_LOCAL_DRAM_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tLocal DRAM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}
	if (base_addr == LMAC_COMM_BASE_ADDR || base_addr == SMAC_COMM_BASE_ADDR) {
		/* Local Dram 2 memory */
		access_num = cl_reg_read(chip, base_addr + TEST_LOCAL_DRAM_2_ACCESS_NUM_ADDR);
		if (access_num) {
			write_cycles = cl_reg_read(chip, base_addr +
						   TEST_LOCAL_DRAM_2_WRITE_CYCLES_ADDR);
			read_cycles = cl_reg_read(chip, base_addr +
						  TEST_LOCAL_DRAM_2_READ_CYCLES_ADDR);

			write_cycles_access = write_cycles / access_num;
			read_cycles_access = read_cycles / access_num;
			TEST_INFO("\t\tLocal DRAM 2: Write: %d Read %d\n",
				  write_cycles_access, read_cycles_access);
		}
	}
	/* Remote Iram memory */
	access_num = cl_reg_read(chip, base_addr + TEST_REMOTE_IRAM_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_IRAM_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_IRAM_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tRemote IRAM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}
	/* Remote Dram memory */
	access_num = cl_reg_read(chip, base_addr + TEST_REMOTE_DRAM_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_DRAM_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_DRAM_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tRemote DRAM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}

	/* Remote_1 Iram memory */
	access_num = cl_reg_read(chip, base_addr + TEST_REMOTE_1_IRAM_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr +
					   TEST_REMOTE_1_IRAM_WRITE_CYCLES_ADDR);
		read_cycles = write_cycles +
			cl_reg_read(chip, base_addr + TEST_REMOTE_1_IRAM_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tRemote_1 IRAM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}
	/* Remote_1 Dram memory */
	access_num = cl_reg_read(chip, base_addr + TEST_REMOTE_1_DRAM_ACCESS_NUM_ADDR);
	if (access_num) {
		write_cycles = cl_reg_read(chip, base_addr +
					   TEST_REMOTE_1_DRAM_WRITE_CYCLES_ADDR);
		read_cycles = cl_reg_read(chip, base_addr +
					  TEST_REMOTE_1_DRAM_READ_CYCLES_ADDR);

		write_cycles_access = write_cycles / access_num;
		read_cycles_access = read_cycles / access_num;
		TEST_INFO("\t\tRemote_1 DRAM: Write: %d Read %d\n",
			  write_cycles_access, read_cycles_access);
	}

	/* Display the single access time to memory in cycles */
	TEST_INFO("\tSingle memory access time (in cycles):\n");

	cycle_fetch_time = cl_reg_read(chip, base_addr + TEST_CYCLES_TIME_FATCH_ADDR);

	/* Shared memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_SHARED_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_SHARED_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tSHARED RAM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);

	/* PHY memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_PHY_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_PHY_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tPHY RAM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);

	/* PHY PMEM memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_PHY_PMEM_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_PHY_PMEM_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tPHY PMEM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);

	/* PHY XMEM memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_PHY_XMEM_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_PHY_XMEM_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tPHY XMEM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);

	/* Local Iram memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_LOCAL_IRAM_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_LOCAL_IRAM_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tLocal IRAM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);

	/* Local Dram 1 memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_LOCAL_DRAM_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_LOCAL_DRAM_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tLocal DRAM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);
	if (base_addr == LMAC_COMM_BASE_ADDR || base_addr == SMAC_COMM_BASE_ADDR) {
		/* Local Dram 2 memory */
		write_single_cycles = cl_reg_read(chip, base_addr +
						  TEST_LOCAL_DRAM_2_WRITE_SINGLE_ADDR);
		read_single_cycles = cl_reg_read(chip, base_addr +
						 TEST_LOCAL_DRAM_2_READ_SINGLE_ADDR);
		if (write_single_cycles != 0 && read_single_cycles != 0)
			TEST_INFO("\t\tLocal DRAM 2: Write: %d Read %d\n",
				  write_single_cycles - cycle_fetch_time,
				  read_single_cycles - cycle_fetch_time);
	}
	/* Remote Iram memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_IRAM_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_IRAM_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tRemote IRAM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);

	/* Remote Dram memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_DRAM_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_DRAM_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tRemote DRAM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);

	/* Remote_1 Iram memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_1_IRAM_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_1_IRAM_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tRemote_1 IRAM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);

	/* Remote_1 Dram memory */
	write_single_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_1_DRAM_WRITE_SINGLE_ADDR);
	read_single_cycles = cl_reg_read(chip, base_addr + TEST_REMOTE_1_DRAM_READ_SINGLE_ADDR);
	if (write_single_cycles != 0 && read_single_cycles != 0)
		TEST_INFO("\t\tRemote_1 DRAM: Write: %d Read %d\n",
			  write_single_cycles - cycle_fetch_time,
			  read_single_cycles - cycle_fetch_time);
}

#define PRINT_STR_SIZE 9

#define TEST_CYCLE_COUNTER_ADDR  (TEST_END_INDICATION_ADDR + 0x00000010)
#define TEST_MICROS_COUNTER_ADDR (TEST_END_INDICATION_ADDR + 0x00000014)
#define TEST_LOOP_COUNTER_ADDR   (TEST_END_INDICATION_ADDR + 0x00000018)

static void cl_apre_core_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 reminder, print_size;
	u8 print_str[PRINT_STR_SIZE];
	u32 cycle_cnt, micro_cnt, loop_cnt;
	int len = 0;

	/* Wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 5))
		return;

	memset(print_str, 0, PRINT_STR_SIZE);

	cycle_cnt = cl_reg_read(chip, base_addr + TEST_CYCLE_COUNTER_ADDR);
	micro_cnt = cl_reg_read(chip, base_addr + TEST_MICROS_COUNTER_ADDR);
	loop_cnt = cl_reg_read(chip, base_addr + TEST_LOOP_COUNTER_ADDR);

	if (!micro_cnt) {
		TEST_INFO("micro_cnt is 0 !!!\n");
		return;
	}

	len = snprintf(print_str, sizeof(print_str), "%u.", (cycle_cnt / micro_cnt));
	reminder = (cycle_cnt % micro_cnt);

	for (print_size = strlen(print_str); print_size < (PRINT_STR_SIZE - 1); print_size++) {
		reminder *= 10;
		len += snprintf(print_str + len, sizeof(print_str) - len,
				"%d", (reminder / micro_cnt));
		reminder = (reminder % micro_cnt);
	}

	TEST_INFO("\t\tProcessor speed: %s\n", print_str);
	TEST_INFO("\t\tvariable loop counter %d\n",
		  cl_reg_read(chip, base_addr + TEST_LOOP_COUNTER_ADDR));
}

static void cl_apre_registers_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 fail_module;
	u32 fail_addr;

	/* Wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 10))
		return;

	fail_module = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);
	fail_addr = cl_reg_read(chip, base_addr + TEST_FAIL_ADDRESS_ADDR);

	if (fail_module == TEST_SUCCESS)
		TEST_INFO("\t\t\tSUCCESS\n");
	else if (fail_module < FW_REGS_TEST_MODULES_NUMBER)
		TEST_INFO("\t\t\tFAIL at module %s register: %Xh\n",
			  fw_regs_test_modules[fail_module], fail_addr);
	else
		TEST_INFO("\t\t\tFAIL - Unknown fail_module (%u)\n", fail_module);
}

static void cl_apre_other_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 fail_module;
	u32 fail_addr;

	/* Wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 10))
		return;

	fail_module = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);
	fail_addr = cl_reg_read(chip, base_addr + TEST_FAIL_ADDRESS_ADDR);

	if (fail_module == TEST_SUCCESS)
		TEST_INFO("\t\t\tSUCCESS\n");
	else if (fail_module < FW_REGS_TEST_MODULES_NUMBER)
		TEST_INFO("\t\t\tFAIL at module %s register: %Xh\n",
			  fw_regs_test_modules[fail_module], fail_addr);
	else
		TEST_INFO("\t\t\tFAIL - Unknown fail_module (%u)\n", fail_module);
}

static void cl_apre_edma_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 test_result;
	u32 compare_res;
	u32 ind_addr = base_addr + EDMA_TEST_END_INDICATION_ADDR;

	/* Wait for the FW to signal test end */
	if (cl_wait_4_edma_test_end_ind(cl_hw, base_addr, 100))
		return;

	TEST_INFO("\t\ttest_end_ind_addr: 0x%x, Test result: %u.\n",
		  ind_addr, cl_reg_read(chip, ind_addr));

	TEST_INFO("\t\tTest cycles performed: %u.\n",
		  cl_reg_read(chip, base_addr + EDMA_ITTERATIONS_PERFORMED_ADDR));

	if (cl_reg_read(chip, ind_addr) == 1) {
		compare_res = cl_apre_edmatest_host_buffs_upstream_compare(cl_hw,
									   (u8 *)virt_dma_mem,
									   EDMA_MEM_SIZE);
		if (compare_res != 0) {
			TEST_INFO("\t\tHOST buffer compare failed\n");
			cl_reg_write(chip, 3, ind_addr);
		}
	}

	test_result = cl_reg_read(chip, ind_addr);

	/* Registers test */
	if (test_result == TEST_SUCCESS) {
		TEST_INFO("\t\tSUCCESS\n");
	} else {
		TEST_INFO("\t\tFAILURE  0x%x\n", test_result);
		cl_apre_edma_test_dbg_regs_print(cl_hw, base_addr);
	}

	/* Free allocated DMA memory block */
	TEST_INFO("Mac EDMA test host free Phys:0x%llX Virt:0x%p\n",
		  (u64)phys_dma_mem, virt_dma_mem);
	chip_ops_free_coherent(cl_hw->chip, EDMA_MEM_SIZE,
			       virt_dma_mem, phys_dma_mem);
}

static void cl_apre_udma_test(struct cl_hw *cl_hw, u32 test_control_address,
			      u32 test_result_address)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 old_seq_id = 0;
	u32 seq_id;
	u32 count = 0;
	u32 cmd;
	u32 state;
	u32 test_result = 1;

	while (1) {
		seq_id = cl_reg_read(chip, test_result_address +
				     UDMA_TEST_STATUS_SEQUENCE_ID_OFS);

		if (seq_id == old_seq_id) {
			if (++count >= 100) {
				TEST_INFO("Timeout\n");
				break;
			}
			ssleep(1);
			continue;
		}

		old_seq_id = seq_id;
		count = 0;

		cmd = cl_reg_read(chip, test_control_address + UDMA_TEST_CONTROL_CMD_OFS);
		if (cmd == 0) {
			TEST_INFO("Init passed\n");
			seq_id = cl_reg_read(chip, test_control_address +
					     UDMA_TEST_CONTROL_SEQUENCE_ID_OFS);
			seq_id++;

			cl_reg_write(chip, test_control_address + UDMA_TEST_CONTROL_CMD_OFS, 1);
			cl_reg_write(chip, test_control_address +
				     UDMA_TEST_CONTROL_SEQUENCE_ID_OFS, seq_id);
			continue;
		}

		state = cl_reg_read(chip, test_result_address + UDMA_TEST_STATUS_STATE_OFS);
		if (state == 2) { /* Finished */
			TEST_INFO("Finished\n");
			test_result = cl_reg_read(chip, test_result_address +
						  UDMA_TEST_STATUS_RESULT_OFS);
			if (test_result == 0)
				TEST_INFO("\t\tSUCCESS\n");
			else
				TEST_INFO("\t\tFAILURE  0x%x\n", test_result);
			break;
		}
	}

	if (test_result) {
		cl_show_mem(cl_hw, test_control_address, UDMA_TEST_CONTROL_SIZE / 16);
		cl_show_mem(cl_hw, test_result_address, UDMA_TEST_STATUS_SIZE / 16);
		cl_show_mem24(cl_hw, test_control_address + UDMA_LLI_DESC_START_OFS,
			      UDMA_LLI_DESC_SIZE / 24);
	}
}

static void cl_apre_edma_tp_test(struct cl_hw *cl_hw, u32 base_addr)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 fail_module;
	u32 fail_addr;

	/* Wait for the FW to signal test end */
	if (cl_wait_4_test_end_ind(cl_hw, base_addr, 10))
		return;

	fail_module = cl_reg_read(chip, base_addr + TEST_FAIL_MODULE_ADDR);
	fail_addr = cl_reg_read(chip, base_addr + TEST_FAIL_ADDRESS_ADDR);

	TEST_INFO("\t\tTest cycles performed: %u.\n",
		  cl_reg_read(chip, base_addr + EDMA_ITTERATIONS_PERFORMED_ADDR));

	/* Registers test */
	if (fail_module == TEST_SUCCESS)
		TEST_INFO("\t\tSUCCESS\n");
	else if (fail_module < FW_EDMA_TESTS_NUMBER)
		TEST_INFO("\t\tFAIL in %s phase at address: 0x%X\n",
			  fw_edma_test[fail_module], fail_addr);
	else
		TEST_INFO("\t\t\tFAIL - Unknown fail_module (%u)\n", fail_module);

	/* Free allocated DMA memory block */
	TEST_INFO("Mac EDMA TP test host free Phys:0x%llX Virt:0x%p\n",
		  (u64)phys_dma_mem, virt_dma_mem);
	chip_ops_free_coherent(cl_hw->chip, EDMA_MEM_SIZE,
			       virt_dma_mem, phys_dma_mem);
}

void print_memtest_cfg(struct cl_hw *cl_hw, uint32_t comm_base)
{
	struct cl_chip *chip = cl_hw->chip;

	cl_dbg_trace(cl_hw, "Shared RAM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + MEM_SRAM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + MEM_SRAM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Local IRAM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + MEM_LOCAL_IRAM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + MEM_LOCAL_IRAM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Local DRAM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + MEM_LOCAL_DRAM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + MEM_LOCAL_DRAM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Remote IRAM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + MEM_REMOTE_IRAM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + MEM_REMOTE_IRAM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Remote DRAM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + MEM_REMOTE_DRAM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + MEM_REMOTE_DRAM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Remote1 IRAM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + MEM_REMOTE_1_IRAM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + MEM_REMOTE_1_IRAM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Remote1 DRAM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + MEM_REMOTE_1_DRAM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + MEM_REMOTE_1_DRAM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Phy DMEM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + PHY_DMEM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + PHY_DMEM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Phy PMEM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + PHY_PMEM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + PHY_PMEM_SIZE_ADDR));
	cl_dbg_trace(cl_hw, "Phy XMEM 0x%08X[0x%04X]\n",
		     cl_reg_read(chip, comm_base + PHY_XMEM_BASE_ADDR),
		     cl_reg_read(chip, comm_base + PHY_XMEM_SIZE_ADDR));
}

void cl_fw_test_pre(struct cl_hw *cl_hw, char *lmac_fw_name,
		    char *umac_fw_name, char *smac_fw_name)
{
	struct cl_chip *chip = cl_hw->chip;
	u32 lmac_dram_size, lmac_local_dram_test_size_addr, umac_dram_size, umac_iram_size,
		umac_local_dram_test_size_addr, umac_local_iram_test_size_addr;

	dram_type_init_parameters(cl_hw, &lmac_dram_size, &lmac_local_dram_test_size_addr,
				  &umac_dram_size, &umac_iram_size,
				  &umac_local_dram_test_size_addr,
				  &umac_local_iram_test_size_addr);
	cl_dbg_trace(cl_hw, ": lmac=%s, umac=%s, smac=%s\n",
		     lmac_fw_name, umac_fw_name, smac_fw_name);

	TEST_INFO("%s: entry (chip=%d,lmac=%s,umac=%s,smac=%s).\n",
		  __func__, cl_hw->chip->idx, lmac_fw_name, umac_fw_name, smac_fw_name);

	if (!strcmp(lmac_fw_name, umac_fw_name) &&
	    strcmp(lmac_fw_name, TEST_NO_LOAD) &&
	    strcmp(lmac_fw_name, fw_test_name[MAC_IPC_TEST]))
		TEST_INFO("WARNING: LMAC and UMAC tests are same (lmac=%s,umac=%s).\n",
			  lmac_fw_name, umac_fw_name);

	if (!strcmp(lmac_fw_name, smac_fw_name) &&
	    strcmp(lmac_fw_name, TEST_NO_LOAD) &&
	    strcmp(lmac_fw_name, fw_test_name[MAC_IPC_TEST]))
		TEST_INFO("WARNING: LMAC and SMAC tests are same (lmac=%s,smac=%s).\n",
			  lmac_fw_name, smac_fw_name);

	if (!strcmp(umac_fw_name, smac_fw_name) &&
	    strcmp(umac_fw_name, TEST_NO_LOAD) &&
	    strcmp(umac_fw_name, fw_test_name[MAC_IPC_TEST]))
		TEST_INFO("WARNING: UMAC and SMAC tests are same (umac=%s,smac=%s).\n",
			  umac_fw_name, smac_fw_name);

	/* Running LMAC tests */
	if (!strcmp(lmac_fw_name, fw_test_name[MAC_REGISTERS_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
		/* Dummy phy mode */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + REGS_MODE_ADDR, 0x1);
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_MEMORY_TEST])) {
		if (IS_USB_BUS_TYPE(chip)) {
			TEST_INFO("\t\tFW Memtest not supported with kernel driver "
				  "when host-if is usb: use bootdrv\n");
		} else {
			/* Reset the MAC end test indication */
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

			/* Local dram 1 */
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_BASE_ADDR,
				     LMAC_LOCAL_IRAM_TEST_BASE_ADDR);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_SIZE_ADDR,
				     LMAC_LOCAL_IRAM_TEST_SIZE_ADDR);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_BASE_ADDR,
				     LMAC_LOCAL_DRAM_TEST_BASE_ADDR);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_SIZE_ADDR,
				     lmac_local_dram_test_size_addr);

			/* Remote - UMAC Memories */
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_BASE_ADDR,
				     UMAC_REMOTE_IRAM_BASE_ADDR(chip));
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_SIZE_ADDR,
				     umac_iram_size);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_BASE_ADDR,
				     UMAC_REMOTE_DRAM_BASE_ADDR);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_SIZE_ADDR,
				     umac_dram_size);

			/* Remote_1 - SMAC Memories */
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_BASE_ADDR,
				     SMAC_REMOTE_IRAM_BASE_ADDR);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_SIZE_ADDR,
				     SMAC_IRAM_SIZE);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_BASE_ADDR,
				     SMAC_REMOTE_DRAM_BASE_ADDR);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_SIZE_ADDR,
				     SMAC_DRAM_SIZE);

			if (chip->conf->ci_phy_dev != PHY_DEV_DUMMY) {
				/* PHY Memories */
				cl_reg_write(chip, LMAC_COMM_BASE_ADDR + PHY_DMEM_BASE_ADDR,
					     PHY0_DMEM_BASE);
				cl_reg_write(chip, LMAC_COMM_BASE_ADDR + PHY_DMEM_SIZE_ADDR,
					     PHY0_DMEM_SIZE);
				cl_reg_write(chip, LMAC_COMM_BASE_ADDR + PHY_PMEM_BASE_ADDR,
					     PHY_PMEM_BASE);
				cl_reg_write(chip, LMAC_COMM_BASE_ADDR + PHY_PMEM_SIZE_ADDR,
					     PHY_PMEM_SIZE);
				cl_reg_write(chip, LMAC_COMM_BASE_ADDR + PHY_XMEM_BASE_ADDR,
					     PHY_XMEM_BASE);
				cl_reg_write(chip, LMAC_COMM_BASE_ADDR + PHY_XMEM_SIZE_ADDR,
					     PHY_XMEM_SIZE);
			}
			print_memtest_cfg(cl_hw, LMAC_COMM_BASE_ADDR);
		}
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_INTERRUPTS_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
		/*
		 * The interrupt test do not wait on end indication, since the interrupts are
		 * set by the host here after, so the host knows when the test terminates.
		 */
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_DSP_MAIL_BOX_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
		/* inform DSP that all is ready for testing */
		cl_reg_write(chip, REG_MACDSP_API_BASE_ADDR + PHY0_DSPMBX_TEST_OFFSET,
			     PHY0_DSPMBX_TEST_VAL);
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_CORE_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_IPC_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

		/* Enable all of IPC IRQ bits for testing */
		cl_irq_enable(cl_hw, 0xffffffff);

		/*
		 * Tell FW that LMAC test exists
		 * 0 - Without LMAC, 1 - With LMAC
		 */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_LMAC_VALID, 1);
		if (!strcmp(umac_fw_name, fw_test_name[MAC_IPC_TEST]))
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_UMAC_VALID, 1);
		else
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_UMAC_VALID, 0);
		if (!strcmp(smac_fw_name, fw_test_name[MAC_IPC_TEST]))
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_SMAC_VALID, 1);
		else
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_SMAC_VALID, 0);

		/* enable ALL IPC interrupts.only once cause it affect status reg as well*/
		cl_reg_write(chip, IPC_APP2EMB_UNMASK_SET_ADDR, 0xFFFFFFFF);
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_MCCI_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_CYCLE_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_EDMA_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, EDMA_LMAC_COMM_BASE_ADDR + EDMA_TEST_END_INDICATION_ADDR, 0);

		virt_dma_mem = chip_ops_alloc_coherent(chip, EDMA_MEM_SIZE,
						       GFP_KERNEL,
						       &phys_dma_mem);
		if (virt_dma_mem) {
			TEST_INFO("LMAC EDMA Test: Allocated DMA memory - "
				  "size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
				  EDMA_MEM_SIZE, (u64)phys_dma_mem, virt_dma_mem);

			cl_pre_edmatest_host_buffs_init(cl_hw, (u8 *)virt_dma_mem, EDMA_MEM_SIZE);

			cl_reg_write(chip, EDMA_LMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO,
				     phys_dma_mem & 0xffffffff);
			cl_reg_write(chip, EDMA_LMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI,
				     ((u64)phys_dma_mem) >> 32);
			cl_reg_write(chip, EDMA_LMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR,
				     EDMA_MEM_SIZE);
		} else {
			TEST_INFO("ERROR: LMAC EDMA Test - failed to allocated DMA memory!\n");
		}
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_UDMA_TEST])) {

		/* Set sequence id = 0 */
		cl_reg_write(chip, UDMA_LMAC_TEST_STATUS_START_ADDR +
			     UDMA_TEST_STATUS_SEQUENCE_ID_OFS, 0);
	} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_EDMA_TP_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

		virt_dma_mem = chip_ops_alloc_coherent(chip, EDMA_MEM_SIZE,
						       GFP_KERNEL,
						       &phys_dma_mem);
		if (virt_dma_mem) {
			TEST_INFO("LMAC EDMA TP Test: Allocated DMA memory - "
				  "size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
					EDMA_MEM_SIZE, (u64)phys_dma_mem, virt_dma_mem);

			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO,
				     phys_dma_mem & 0xffffffff);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI,
				     ((u64)phys_dma_mem) >> 32);
			cl_reg_write(chip, LMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR,
				     EDMA_MEM_SIZE);
		} else {
			TEST_INFO("ERROR: LMAC EDMA TP Test - failed to allocated DMA memory!\n");
		}
	} else {
		TEST_INFO("Lmac run %s\n\n", lmac_fw_name);
	}

	if (!strcmp(umac_fw_name, fw_test_name[MAC_REGISTERS_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
		/* Dummy phy mode */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + REGS_MODE_ADDR, 0x1);
	} else if (!strcmp(umac_fw_name, fw_test_name[MAC_MEMORY_TEST])) {
		if (IS_USB_BUS_TYPE(chip)) {
			TEST_INFO("\t\tFW Memtest not supported with kernel driver "
				  "when host-if is usb: use bootdrv\n");
		} else {
			/* Reset the MAC end test indication */
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

			/* Local dram */
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_BASE_ADDR,
				     UMAC_LOCAL_IRAM_TEST_BASE_ADDR);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_SIZE_ADDR,
				     umac_local_iram_test_size_addr);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_BASE_ADDR,
				     UMAC_LOCAL_DRAM_TEST_BASE_ADDR);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_SIZE_ADDR,
				     umac_local_dram_test_size_addr);

			/* Remote - LMAC Memories */
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_BASE_ADDR,
				     LMAC_REMOTE_IRAM_BASE_ADDR);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_SIZE_ADDR,
				     LMAC_IRAM_SIZE);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_BASE_ADDR,
				     LMAC_REMOTE_DRAM_BASE_ADDR);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_SIZE_ADDR,
				     lmac_dram_size);

			/* Remote_1 - SMAC Memories */
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_BASE_ADDR,
				     SMAC_REMOTE_IRAM_BASE_ADDR);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_SIZE_ADDR,
				     SMAC_IRAM_SIZE);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_BASE_ADDR,
				     SMAC_REMOTE_DRAM_BASE_ADDR);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_SIZE_ADDR,
				     SMAC_DRAM_SIZE);

			if (chip->conf->ci_phy_dev != PHY_DEV_DUMMY) {
				/* PHY Memories */
				cl_reg_write(chip, UMAC_COMM_BASE_ADDR + PHY_DMEM_BASE_ADDR,
					     PHY0_DMEM_BASE);
				cl_reg_write(chip, UMAC_COMM_BASE_ADDR + PHY_DMEM_SIZE_ADDR,
					     PHY0_DMEM_SIZE);
				cl_reg_write(chip, UMAC_COMM_BASE_ADDR + PHY_PMEM_BASE_ADDR,
					     PHY_PMEM_BASE);
				cl_reg_write(chip, UMAC_COMM_BASE_ADDR + PHY_PMEM_SIZE_ADDR,
					     PHY_PMEM_SIZE);
				cl_reg_write(chip, UMAC_COMM_BASE_ADDR + PHY_XMEM_BASE_ADDR,
					     PHY_XMEM_BASE);
				cl_reg_write(chip, UMAC_COMM_BASE_ADDR + PHY_XMEM_SIZE_ADDR,
					     PHY_XMEM_SIZE);
			}
			print_memtest_cfg(cl_hw, UMAC_COMM_BASE_ADDR);
		}
	} else if (!strcmp(umac_fw_name, fw_test_name[MAC_INTERRUPTS_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
		/*
		 * The interrupt test do not wait on end indication, since the interrupts are
		 * set by the host here after, so the host knows when the test terminates.
		 * reset the MAC ready test indication
		 */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(umac_fw_name, fw_test_name[MAC_CORE_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(umac_fw_name, fw_test_name[MAC_IPC_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

		/* Enable all of IPC IRQ bits for testing */
		cl_irq_enable(cl_hw, 0xffffffff);

		/*
		 * Tell FW that UMAC test exists
		 * 0 - Without UMAC, 1 - With UMAC
		 */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_UMAC_VALID, 1);
		if (!strcmp(lmac_fw_name, fw_test_name[MAC_IPC_TEST]))
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_LMAC_VALID, 1);
		else
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_LMAC_VALID, 0);
		if (!strcmp(smac_fw_name, fw_test_name[MAC_IPC_TEST]))
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_SMAC_VALID, 1);
		else
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_SMAC_VALID, 0);

	} else if (!strcmp(umac_fw_name, fw_test_name[MAC_MCCI_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(umac_fw_name, fw_test_name[MAC_CYCLE_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(umac_fw_name, fw_test_name[MAC_EDMA_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

		virt_dma_mem = chip_ops_alloc_coherent(chip, EDMA_MEM_SIZE,
						       GFP_KERNEL,
						       &phys_dma_mem);
		if (virt_dma_mem) {
			TEST_INFO("UMAC EDMA Test: Allocated DMA memory - "
				  "size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
				  EDMA_MEM_SIZE, (u64)phys_dma_mem, virt_dma_mem);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO,
				     phys_dma_mem & 0xffffffff);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI,
				     ((u64)phys_dma_mem) >> 32);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR,
				     EDMA_MEM_SIZE);
		} else {
			TEST_INFO("ERROR: UMAC EDMA Test - failed to allocated DMA memory!\n");
		}
	} else if (!strcmp(umac_fw_name, fw_test_name[MAC_EDMA_TP_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

		virt_dma_mem = chip_ops_alloc_coherent(chip, EDMA_MEM_SIZE,
						       GFP_KERNEL,
						       &phys_dma_mem);
		if (virt_dma_mem) {
			TEST_INFO("UMAC EDMA TP Test: Allocated DMA memory - "
				  "size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
				  EDMA_MEM_SIZE, (u64)phys_dma_mem, virt_dma_mem);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO,
				     phys_dma_mem & 0xffffffff);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI,
				     ((u64)phys_dma_mem) >> 32);
			cl_reg_write(chip, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR,
				     EDMA_MEM_SIZE);
		} else {
			TEST_INFO("ERROR: UMAC EDMA TP Test - failed to allocated DMA memory!\n");
		}
	} else {
		TEST_INFO("UMAC run %s\n\n", umac_fw_name);
	}

	/* Running SMAC tests */
	if (!strcmp(smac_fw_name, fw_test_name[MAC_REGISTERS_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
		/* Dummy phy mode */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + REGS_MODE_ADDR, 0x1);
	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_MEMORY_TEST])) {
		if (IS_USB_BUS_TYPE(chip)) {
			TEST_INFO("\t\tFW Memtest not supported with kernel driver "
				  "when host-if is usb: use bootdrv\n");
		} else {
			/* Reset the MAC end test indication */
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

			/* Local dram 1 */
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_BASE_ADDR,
				     SMAC_LOCAL_IRAM_TEST_BASE_ADDR);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_SIZE_ADDR,
				     SMAC_LOCAL_IRAM_TEST_SIZE_ADDR);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_BASE_ADDR,
				     SMAC_LOCAL_DRAM_TEST_BASE_ADDR);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_SIZE_ADDR,
				     SMAC_LOCAL_DRAM_TEST_SIZE_ADDR);

			/* Remote - LMAC Memories */
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_BASE_ADDR,
				     LMAC_REMOTE_IRAM_BASE_ADDR);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_SIZE_ADDR,
				     LMAC_IRAM_SIZE);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_BASE_ADDR,
				     LMAC_REMOTE_DRAM_BASE_ADDR);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_SIZE_ADDR,
				     lmac_dram_size);

			/* Remote_1 - UMAC Memories */
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_BASE_ADDR,
				     UMAC_REMOTE_IRAM_BASE_ADDR(chip));
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_SIZE_ADDR,
				     umac_iram_size);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_BASE_ADDR,
				     UMAC_REMOTE_DRAM_BASE_ADDR);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_SIZE_ADDR,
				     umac_dram_size);

			if (chip->conf->ci_phy_dev != PHY_DEV_DUMMY) {

				/* PHY Memories */
				cl_reg_write(chip, SMAC_COMM_BASE_ADDR + PHY_DMEM_BASE_ADDR,
					     PHY0_DMEM_BASE);
				cl_reg_write(chip, SMAC_COMM_BASE_ADDR + PHY_DMEM_SIZE_ADDR,
					     PHY0_DMEM_SIZE);
				cl_reg_write(chip, SMAC_COMM_BASE_ADDR + PHY_PMEM_BASE_ADDR,
					     PHY_PMEM_BASE);
				cl_reg_write(chip, SMAC_COMM_BASE_ADDR + PHY_PMEM_SIZE_ADDR,
					     PHY_PMEM_SIZE);
				cl_reg_write(chip, SMAC_COMM_BASE_ADDR + PHY_XMEM_BASE_ADDR,
					     PHY_XMEM_BASE);
				cl_reg_write(chip, SMAC_COMM_BASE_ADDR + PHY_XMEM_SIZE_ADDR,
					     PHY_XMEM_SIZE);
			}
			print_memtest_cfg(cl_hw, SMAC_COMM_BASE_ADDR);
		}
	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_INTERRUPTS_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
		/*
		 * The interrupt test do not wait on end indication, since the interrupts
		 * are set by the host here after, so the host knows when the test terminates.
		 */
	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_CORE_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_IPC_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

		/* Enable all of IPC IRQ bits for testing */
		cl_irq_enable(cl_hw, 0xffffffff);

		/*
		 * Tell FW that SMAC test exists
		 * 0 - Without SMAC, 1 - With SMAC
		 */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_SMAC_VALID, 1);
		if (!strcmp(umac_fw_name, fw_test_name[MAC_IPC_TEST]))
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_UMAC_VALID, 1);
		else
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_UMAC_VALID, 0);
		if (!strcmp(lmac_fw_name, fw_test_name[MAC_IPC_TEST]))
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_LMAC_VALID, 1);
		else
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_LMAC_VALID, 0);

	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_MCCI_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_CYCLE_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);
	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_EDMA_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

		virt_dma_mem = chip_ops_alloc_coherent(chip, EDMA_MEM_SIZE,
						       GFP_KERNEL,
						       &phys_dma_mem);
		if (virt_dma_mem) {
			TEST_INFO("SMAC EDMA Test: Allocated DMA memory - "
				  "size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
				  EDMA_MEM_SIZE, (u64)phys_dma_mem, virt_dma_mem);

			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO,
				     phys_dma_mem & 0xffffffff);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI,
				     ((u64)phys_dma_mem) >> 32);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR,
				     EDMA_MEM_SIZE);
		} else {
			TEST_INFO("ERROR: SMAC EDMA Test - failed to allocated DMA memory!\n");
		}
	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_UDMA_TEST])) {

		/* Set sequence id = 0 */
		cl_reg_write(chip, UDMA_SMAC_TEST_STATUS_START_ADDR +
			     UDMA_TEST_STATUS_SEQUENCE_ID_OFS, 0);
	} else if (!strcmp(smac_fw_name, fw_test_name[MAC_EDMA_TP_TEST])) {
		/* Reset the MAC end test indication */
		cl_reg_write(chip, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR, 0);

		virt_dma_mem = chip_ops_alloc_coherent(chip, EDMA_MEM_SIZE,
						       GFP_KERNEL,
						       &phys_dma_mem);
		if (virt_dma_mem) {
			TEST_INFO("LMAC EDMA TP Test: Allocated DMA memory - "
				  "size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
				  EDMA_MEM_SIZE, (u64)phys_dma_mem, virt_dma_mem);

			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO,
				     phys_dma_mem & 0xffffffff);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI,
				     ((u64)phys_dma_mem) >> 32);
			cl_reg_write(chip, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR,
				     EDMA_MEM_SIZE);
		} else {
			TEST_INFO("ERROR: LMAC EDMA TP Test - failed to allocated DMA memory!\n");
		}
	} else {
		TEST_INFO("Smac run %s\n\n", smac_fw_name);
	}
}

/* verify all tested FW are ready */
static bool cl_fw_test_apre_conditions(struct cl_hw *cl_hw, char *lmac_fw_name,
				       char *umac_fw_name, char *smac_fw_name)
{
	if (strcmp(lmac_fw_name, TEST_NO_LOAD) && !cl_hw->chip->cl_hw_tcv0->fw_active)
		return false;

	if (strcmp(smac_fw_name, TEST_NO_LOAD) && !cl_hw->chip->smac_active)
		return false;

	if (strcmp(umac_fw_name, TEST_NO_LOAD) && !cl_hw->chip->umac_active)
		return false;

	return true;
}

void cl_fw_test_apre(struct cl_hw *cl_hw, char *lmac_fw_name,
		     char *umac_fw_name, char *smac_fw_name)
{
	struct cl_chip *chip = cl_hw->chip;

	if (cl_fw_test_apre_conditions(cl_hw, lmac_fw_name, umac_fw_name, smac_fw_name)) {

		cl_dbg_trace(cl_hw, ": lmac=%s, umac=%s, smac=%s\n",
			     lmac_fw_name, umac_fw_name, smac_fw_name);

		msleep(1000);

		/* Handle LMAC test result */
		if (!strcmp(lmac_fw_name, fw_test_name[MAC_REGISTERS_TEST])) {
			/* Registers test */
			TEST_INFO("Lmac Registers test:\n");
			cl_apre_registers_test(cl_hw, LMAC_COMM_BASE_ADDR);
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_MEMORY_TEST])) {
			/* Memory test */
			TEST_INFO("Lmac memory test\n");
			if (IS_PCI_BUS_TYPE(chip)) {
				cl_apre_mem_fw_test(cl_hw, LMAC_COMM_BASE_ADDR);
			} else {
				TEST_INFO("\t\t\tFAIL - Not supported\n");
			}
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_INTERRUPTS_TEST])) {
			/* Interrupt test */
			TEST_INFO("Lmac interrupts test\n");
			/*
			 * The interrupt test do not wait on end indication, since the
			 * interrupts are set by the host here after, so the host knows
			 * when the test terminates.
			 */
			cl_apre_interrupts_fw_test(cl_hw, LMAC_COMM_BASE_ADDR);
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_DSP_MAIL_BOX_TEST])) {
			/* mail box  test */
			TEST_INFO("Lmac DSP Mail Box  test\n");
			cl_apre_interrupts_fw_test(cl_hw, LMAC_COMM_BASE_ADDR);
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_CORE_TEST])) {
			/* Core test */
			TEST_INFO("Lmac CORE test\n");
			cl_apre_core_test(cl_hw, LMAC_COMM_BASE_ADDR);
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_IPC_TEST])) {
			/* IPC test */
			TEST_INFO("Lmac IPC test\n");
			cl_apre_ipc_test(cl_hw, LMAC_COMM_BASE_ADDR);
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_MCCI_TEST])) {
			/* MCCI test */
			TEST_INFO("Lmac MCCI test\n");
			cl_apre_mcci_test(cl_hw, LMAC_COMM_BASE_ADDR);
		}   else if (!strcmp(lmac_fw_name, fw_test_name[MAC_CYCLE_TEST])) {
			/* MCCI test */
			TEST_INFO("Lmac CYCLE test\n");
			cl_apre_cycle_test(cl_hw, LMAC_COMM_BASE_ADDR);
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_EDMA_TEST])) {
			/* EDMA test */
			TEST_INFO("Lmac EDMA test\n");
			cl_apre_edma_test(cl_hw, EDMA_LMAC_COMM_BASE_ADDR);
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_UDMA_TEST])) {
			/* UDMA test */
			TEST_INFO("Lmac UDMA test\n");
			cl_apre_udma_test(cl_hw, UDMA_LMAC_TEST_CONTROL_START_ADDR,
					  UDMA_LMAC_TEST_STATUS_START_ADDR);
		} else if (!strcmp(lmac_fw_name, fw_test_name[MAC_EDMA_TP_TEST])) {
			/* EDMA TP test */
			TEST_INFO("Lmac EDMA TP test\n");
			cl_apre_edma_tp_test(cl_hw, LMAC_COMM_BASE_ADDR);
		} else if (strcmp(lmac_fw_name, TEST_NO_LOAD)) {
			/* Any other test */
			TEST_INFO("Lmac other test\n");
			cl_apre_other_test(cl_hw, LMAC_COMM_BASE_ADDR);
		}
		TEST_INFO("\n");
		/* Handle UMAC test result */
		if (!strcmp(umac_fw_name, fw_test_name[MAC_REGISTERS_TEST])) {
			/* Registers test */
			TEST_INFO("Umac Registers test:\n");
			cl_apre_registers_test(cl_hw, UMAC_COMM_BASE_ADDR);
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_MEMORY_TEST])) {
			/* Memory test */
			TEST_INFO("Umac memory test\n");
			if (IS_PCI_BUS_TYPE(chip)) {
				cl_apre_mem_fw_test(cl_hw, UMAC_COMM_BASE_ADDR);
			} else {
				TEST_INFO("\t\t\tFAIL - Not supported\n");
			}
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_INTERRUPTS_TEST])) {
			/* Interrupt test */
			TEST_INFO("Umac interrupts test\n");
			/*
			 * The interrupt test do not wait on end indication, since the
			 * interrupts are set by the host here after, so the host knows
			 * when the test terminates.
			 */
			cl_apre_interrupts_fw_test(cl_hw, UMAC_COMM_BASE_ADDR);
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_DSP_MAIL_BOX_TEST])) {
			/* Interrupt test */
			TEST_INFO("Error Umac doesn't support dsp mail box\n");
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_CORE_TEST])) {
			/* Core test */
			TEST_INFO("Umac CORE test\n");
			cl_apre_core_test(cl_hw, UMAC_COMM_BASE_ADDR);
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_IPC_TEST])) {
			/* IPC test */
			TEST_INFO("Umac IPC test\n");
			cl_apre_ipc_test(cl_hw, UMAC_COMM_BASE_ADDR);
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_MCCI_TEST])) {
			/* MCCI test */
			TEST_INFO("Umac MCCI test\n");
			cl_apre_mcci_test(cl_hw, UMAC_COMM_BASE_ADDR);
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_CYCLE_TEST])) {
			/* CYCLE test */
			TEST_INFO("Umac CYCLE test\n");
			cl_apre_cycle_test(cl_hw, UMAC_COMM_BASE_ADDR);
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_EDMA_TEST])) {
			/* EDMA test */
			TEST_INFO("Umac EDMA test\n");
			cl_apre_edma_test(cl_hw, UMAC_COMM_BASE_ADDR);
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_EDMA_TP_TEST])) {
			/* EDMA TP test */
			TEST_INFO("Umac EDMA TP test\n");
			cl_apre_edma_tp_test(cl_hw, UMAC_COMM_BASE_ADDR);
		} else if (!strcmp(umac_fw_name, fw_test_name[MAC_UDMA_TEST])) {
			/* UDMA test runs on both LMAC & UMAC, no need to check UMAC output */
		} else if (strcmp(umac_fw_name, TEST_NO_LOAD)) {
			/* Any other test */
			TEST_INFO("Umac other test\n");
			cl_apre_other_test(cl_hw, UMAC_COMM_BASE_ADDR);
		}

		TEST_INFO("\n");
		/* Handle SMAC test result */
		if (!strcmp(smac_fw_name, fw_test_name[MAC_REGISTERS_TEST])) {
			/* Registers test */
			TEST_INFO("Smac Registers test:\n");
			cl_apre_registers_test(cl_hw, SMAC_COMM_BASE_ADDR);
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_MEMORY_TEST])) {
			/* Memory test */
			TEST_INFO("Smac memory test\n");
			if (IS_PCI_BUS_TYPE(chip)) {
				cl_apre_mem_fw_test(cl_hw, SMAC_COMM_BASE_ADDR);
			} else {
				TEST_INFO("\t\t\tFAIL - Not supported\n");
			}
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_INTERRUPTS_TEST])) {
			/* Interrupt test */
			TEST_INFO("Smac interrupts test\n");
			/*
			 * The interrupt test do not wait on end indication, since the
			 * interrupts are set by  the host here after, so the host knows
			 * when the test terminates.
			 */
			cl_apre_interrupts_fw_test(cl_hw, SMAC_COMM_BASE_ADDR);
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_DSP_MAIL_BOX_TEST])) {
			/* Interrupt test */
			TEST_INFO("Error Smac doesn't support dsp mailboix\n");
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_CORE_TEST])) {
			/* Core test */
			TEST_INFO("Smac CORE test\n");
			cl_apre_core_test(cl_hw, SMAC_COMM_BASE_ADDR);
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_IPC_TEST])) {
			/* IPC test */
			TEST_INFO("Smac IPC test\n");
			cl_apre_ipc_test(cl_hw, SMAC_COMM_BASE_ADDR);
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_MCCI_TEST])) {
			/* MCCI test */
			TEST_INFO("Smac MCCI test\n");
			cl_apre_mcci_test(cl_hw, SMAC_COMM_BASE_ADDR);
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_CYCLE_TEST])) {
			/* CYCLE test */
			TEST_INFO("Smac CYCLE test\n");
			cl_apre_cycle_test(cl_hw, SMAC_COMM_BASE_ADDR);
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_EDMA_TEST])) {
			/* EDMA test */
			TEST_INFO("Smac EDMA test\n");
			cl_apre_edma_test(cl_hw, SMAC_COMM_BASE_ADDR);
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_UDMA_TEST])) {
			/* UDMA test */
			TEST_INFO("Smac UDMA test\n");
			cl_apre_udma_test(cl_hw, UDMA_SMAC_TEST_CONTROL_START_ADDR,
					  UDMA_SMAC_TEST_STATUS_START_ADDR);
		} else if (!strcmp(smac_fw_name, fw_test_name[MAC_EDMA_TP_TEST])) {
			/* EDMA TP test */
			TEST_INFO("Smac EDMA TP test\n");
			cl_apre_edma_tp_test(cl_hw, SMAC_COMM_BASE_ADDR);
		} else if (strcmp(smac_fw_name, TEST_NO_LOAD)) {
			/* Any other test */
			TEST_INFO("Smac other test\n");
			cl_apre_other_test(cl_hw, SMAC_COMM_BASE_ADDR);
		}
	} else {
		cl_dbg_trace(cl_hw, "skip test since FW not ready\n");
	}
}

bool cl_fw_test_is_dsp_required(char *test_name)
{
	/* Only dspmbx need dsp */
	return (!strcmp(test_name, fw_test_name[MAC_DSP_MAIL_BOX_TEST]));
}
