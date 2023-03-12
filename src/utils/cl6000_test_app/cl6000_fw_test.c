/**
 ****************************************************************************************
 *
 * @file cl8000_fw_test.c
 *
 * @brief CL8000 FW test infrastructure.
 *
 * Copyright (C) Celeno 2013 - 2017
 *
 ****************************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>

#include "reg_lmac.h"
#include "reg_smac.h"
#include "reg_umac.h"
#include "reg_logger_ram.h"
#include "rwnx_config.h"
#include "cl6000_fw_test.h"
#include "cl6000_usb_test.h"
#include "platform.h"
#include <sys/ioctl.h>
#include <fcntl.h>

#define CL8000

extern int ce_fw_scale_down;
extern CL_PLATFORM_IDX cl_platform;

#define CL_WAIT_4_TEST_END_IND_RETURN(loops) \
    while ( CL_REG_READ(base_addr + TEST_END_INDICATION_ADDR) != 0x1 ) \
    { \
        sleep(1); \
        if (cnt++ == loops*ce_fw_scale_down) {  \
            TEST_INFO("\t\tTest Timed Out !!!\n"); \
            return FAILED;  \
        } \
    }

#define CL_WAIT_4_TEST_END_IND(loops) \
    while ( CL_REG_READ(base_addr + TEST_END_INDICATION_ADDR) != 0x1 ) \
    { \
        sleep(1); \
        if (cnt++ == loops*ce_fw_scale_down) { TEST_INFO("\t\tTest Timed Out !!!\n"); return ; \
        } \
    }

#define CL_WAIT_4_EDMA_TEST_END_IND(loops) \
    while ( CL_REG_READ(base_addr + EDMA_TEST_END_INDICATION_ADDR) == 0x0 ) \
    { \
        sleep(1); \
        if (cnt++ == loops*ce_fw_scale_down) { TEST_INFO("\t\tTest Timed Out !!!\n"); return; } \
    }

#define TEST_SUCCESS        0xAAAA5555

static char *a_fw_test_name[] =
{   "regtestfw.bin",
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
    "usbclitestfw.bin",
    "usbtpttestfw.bin",
    "usbwrapperlmactestfw.bin",
    "usbwrappersmactestfw.bin",
    "usbwifiresettestfw.bin",
};

static const char* umac_lsmac_test_fw_name = "udmatestfw.bin";

/* MAC test type */
typedef enum MAC_TEST_TYPE
{
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
    MAC_USB_CLI_TEST,
    MAC_USB_TP_TEST,
    MAC_USB_WRAPPER_LMAC_TEST,
    MAC_USB_WRAPPER_SMAC_TEST,
    MAC_USB_WIFI_RESET_TEST,
    MAC_NO_TEST=0xFF
} MAC_TEST_TYPE;


#define FW_REGS_TEST_MODULES_NUMBER  12
static char *a_fw_regs_test_modules[] =
{   "",
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

#define FW_MEM_TESTS_NUMBER  16
static char *a_fw_memory_test[] =
{   "",
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
    "remote DRAM device"
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

#define DRAM_TYPE_1 1
#define DRAM_TYPE_2 2
#define IRAM_OFFSET  0x00004000
/* Host <--> LMAC base address communication in shared RAM */
#define LMAC_COMM_BASE_ADDR                 0x60008000
#define EDMA_LMAC_COMM_BASE_ADDR            0x60003000
/* Host <--> UMAC base address communication in shared RAM */
#define UMAC_COMM_BASE_ADDR                 0x60009000
/* Host <--> SMAC base address communication in shared RAM */
#define SMAC_COMM_BASE_ADDR                 0x6000A000
#define COMM_INPUT_BASE_ADDR                0x00000000
#define COMM_OUTPUT_BASE_ADDR               0x00000100
#define COMM_FULL_SIZE                      0x00000200
#define EDMA_COMM_OUTPUT_BASE_ADDR          0x00001500

/* Indicate that test has terminated */
#define TEST_END_INDICATION_ADDR            (COMM_OUTPUT_BASE_ADDR + 0x00000000)
#define EDMA_TEST_END_INDICATION_ADDR       (EDMA_COMM_OUTPUT_BASE_ADDR + 0x00000000)
/* In case the test terminated successfuly  =  TEST_SUCCESS.
 * In case of failure it indicates the module/Phase of failure */
#define TEST_FAIL_MODULE_ADDR               (COMM_OUTPUT_BASE_ADDR + 0x00000004)
/* In case the test terminated successfuly  =  TEST_SUCCESS.
 * In case of failure it indicates the address of failure (not always relevent) */
#define TEST_FAIL_ADDRESS_ADDR              (COMM_OUTPUT_BASE_ADDR + 0x00000008)

#define CELENO_LOCAL_IRAM_BASE_ADDR          0x40080000
#define CELENO_LOCAL_DRAM_BASE_ADDR          0x40000000
#if (CE_HW_VERSION >= HW_8000_STEP_B0)
    #define CELENO_LOCAL_DRAM_2_BASE_ADDR    0x50000000
#endif // CE_HW_VERSION >= HW_8000_STEP_B0
#define CELENO_LMAC_REMOTE_DRAM_BASE_ADDR    0x60200000
#define CELENO_LMAC_REMOTE_IRAM_BASE_ADDR    0x60240000
#define CELENO_UMAC_REMOTE_DRAM_BASE_ADDR    0x60280000
#define CELENO_UMAC_REMOTE_IRAM_BASE_ADDR    0x602c0000
#define CELENO_UMAC_REMOTE_IRAM_BASE_ADDR_B  0x60500000
#define CELENO_SMAC_REMOTE_DRAM_BASE_ADDR    0x60300000
#define CELENO_SMAC_REMOTE_IRAM_BASE_ADDR    0x60340000

#define CELENO_PHY_DMEM_BASE                 0x60400000
#define CELENO_PHY_DMEM_SIZE                 0x80000
#define CELENO_PHY_PMEM_BASE                 0x604C0000
#define CELENO_PHY_PMEM_SIZE                 0x40000
#define CELENO_PHY_XMEM_BASE                 0x60480000
#define CELENO_PHY_XMEM_SIZE                 0x8000


/* LMAC memory addresses and size for memory test */
/* IRAM base address */
#define CELENO_LMAC_IRAM_SIZE                   LMAC_IRAM_SIZE
#define CELENO_LMAC_LOCAL_IRAM_TEST_BASE_ADDR   (CELENO_LOCAL_IRAM_BASE_ADDR + IRAM_OFFSET)
#define CELENO_LMAC_LOCAL_IRAM_TEST_SIZE_ADDR   (CELENO_LMAC_IRAM_SIZE - IRAM_OFFSET)

/* DRAM base address */
#define CELENO_LMAC_DRAM_SIZE                   LMAC_DRAM_SIZE
#define CELENO_LMAC_LOCAL_DRAM_TEST_BASE_ADDR   (CELENO_LOCAL_DRAM_BASE_ADDR + IRAM_OFFSET)
#define CELENO_LMAC_LOCAL_DRAM_TEST_SIZE_ADDR   (CELENO_LMAC_DRAM_SIZE - IRAM_OFFSET)

#define CELENO_SHARED_RAM_TEST_BASE_ADDR     CL6000_LOCAL_SRAM_BASE
#define CELENO_SHARED_RAM_TEST_SIZE_ADDR_USB (CL6000_LOCAL_SRAM_SIZE - 0x20000) // sram size - last 128k used by the bootrom


#if (CE_HW_VERSION >= HW_8000_STEP_B0)
    // need to update the reg_mac in the SOC_ONLINE
    // in the meanwhile, the 'defines' are here
    #define LMAC_DRAM_2_SIZE        0x0010000
    #define CELENO_LMAC_LOCAL_DRAM_2_TEST_BASE_ADDR (CELENO_LOCAL_DRAM_2_BASE_ADDR + IRAM_OFFSET)
    #define CELENO_LMAC_LOCAL_DRAM_2_TEST_SIZE_ADDR (LMAC_DRAM_2_SIZE - IRAM_OFFSET)
#endif // CE_HW_VERSION >= HW_8000_STEP_B0
/* UMAC memory addresses and size for memory test */
    /* IRAM base address */
#define CELENO_UMAC_IRAM_SIZE                   CL6000_UMAC_IRAM_SIZE()
#define CELENO_UMAC_LOCAL_IRAM_TEST_BASE_ADDR   (CELENO_LOCAL_IRAM_BASE_ADDR + IRAM_OFFSET)
#define CELENO_UMAC_LOCAL_IRAM_TEST_SIZE_ADDR   (CELENO_UMAC_IRAM_SIZE - IRAM_OFFSET)

    /* DRAM base address */
#define CELENO_UMAC_DRAM_SIZE                   CL6000_UMAC_DRAM_SIZE()
#define CELENO_UMAC_LOCAL_DRAM_TEST_BASE_ADDR   (CELENO_LOCAL_DRAM_BASE_ADDR + IRAM_OFFSET)
#define CELENO_UMAC_LOCAL_DRAM_TEST_SIZE_ADDR   (CELENO_UMAC_DRAM_SIZE - IRAM_OFFSET)

/* SMAC memory addresses and size for memory test */
/* IRAM base address */
#define CELENO_SMAC_IRAM_SIZE                    SMAC_IRAM_SIZE
#define CELENO_SMAC_LOCAL_IRAM_TEST_BASE_ADDR   (CELENO_LOCAL_IRAM_BASE_ADDR + IRAM_OFFSET)
#define CELENO_SMAC_LOCAL_IRAM_TEST_SIZE_ADDR   (CELENO_SMAC_IRAM_SIZE - IRAM_OFFSET)

/* DRAM base address */
#define CELENO_SMAC_DRAM_SIZE                   SMAC_DRAM_SIZE
#define CELENO_SMAC_LOCAL_DRAM_TEST_BASE_ADDR   (CELENO_LOCAL_DRAM_BASE_ADDR + IRAM_OFFSET)
#define CELENO_SMAC_LOCAL_DRAM_TEST_SIZE_ADDR   (CELENO_SMAC_DRAM_SIZE - IRAM_OFFSET)

#if (CE_HW_VERSION >= HW_8000_STEP_B0)
    // need to update the reg_mac in the SOC_ONLINE
    // in the meanwhile, the 'defines' of dram 2 size are here
    #define SMAC_DRAM_2_SIZE        0x0010000
    #define CELENO_SMAC_LOCAL_DRAM_2_TEST_BASE_ADDR (CELENO_LOCAL_DRAM_2_BASE_ADDR + IRAM_OFFSET)
    #define CELENO_SMAC_LOCAL_DRAM_2_TEST_SIZE_ADDR   (SMAC_DRAM_2_SIZE - IRAM_OFFSET)
#endif // CE_HW_VERSION >= HW_8000_STEP_B0

/* Memory test input parameters */
#define MEM_LOCAL_IRAM_BASE_ADDR           (COMM_INPUT_BASE_ADDR + 0x00000000)
#define MEM_LOCAL_IRAM_SIZE_ADDR           (COMM_INPUT_BASE_ADDR + 0x00000004)
#define MEM_LOCAL_DRAM_BASE_ADDR           (COMM_INPUT_BASE_ADDR + 0x00000008)
#define MEM_LOCAL_DRAM_SIZE_ADDR           (COMM_INPUT_BASE_ADDR + 0x0000000C)
#if (CE_HW_VERSION >= HW_8000_STEP_B0)
    #define MEM_LOCAL_DRAM_2_BASE_ADDR           (COMM_INPUT_BASE_ADDR + 0x00000010)
    #define MEM_LOCAL_DRAM_2_SIZE_ADDR           (COMM_INPUT_BASE_ADDR + 0x00000014)
#endif // CE_HW_VERSION >= HW_8000_STEP_B0
#define MEM_REMOTE_IRAM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000018)
#define MEM_REMOTE_IRAM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x0000001C)
#define MEM_REMOTE_DRAM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000020)
#define MEM_REMOTE_DRAM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000024)
#define MEM_REMOTE_1_IRAM_BASE_ADDR        (COMM_INPUT_BASE_ADDR + 0x00000028) // SMAC support
#define MEM_REMOTE_1_IRAM_SIZE_ADDR        (COMM_INPUT_BASE_ADDR + 0x0000002C)
#define MEM_REMOTE_1_DRAM_BASE_ADDR        (COMM_INPUT_BASE_ADDR + 0x00000030)
#define MEM_REMOTE_1_DRAM_SIZE_ADDR        (COMM_INPUT_BASE_ADDR + 0x00000034)
#define CELENO_PHY_DMEM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000038)
#define CELENO_PHY_DMEM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x0000003C)
#define CELENO_PHY_PMEM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000040)
#define CELENO_PHY_PMEM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000044)
#define CELENO_PHY_XMEM_BASE_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000048)
#define CELENO_PHY_XMEM_SIZE_ADDR          (COMM_INPUT_BASE_ADDR + 0x0000004C)
#define CELENO_SRAM_BASE_ADDR              (COMM_INPUT_BASE_ADDR + 0x00000050)
#define CELENO_SRAM_SIZE_ADDR              (COMM_INPUT_BASE_ADDR + 0x00000054)

// IPC test input parameters
#define HOST_CFG_INPUT_XMAC_VALID          (COMM_INPUT_BASE_ADDR+0x00000000)
#define HOST_CFG_INPUT_YMAC_VALID          (COMM_INPUT_BASE_ADDR+0x00000004)

// MCCI test input parameters
#define HOST_CFG_INPUT_LINE_IDX            (COMM_INPUT_BASE_ADDR+0x00000000)
#define HOST_CFG_INPUT_DW_1                (COMM_INPUT_BASE_ADDR+0x00000004)
#define HOST_CFG_INPUT_DW_2                (COMM_INPUT_BASE_ADDR+0x00000008)

/* EDMA test input parameters */
#define EDMA_PHYS_MEM_ALLOC_ADDR_LO                 (COMM_INPUT_BASE_ADDR + 0x00000000)
#define EDMA_PHYS_MEM_ALLOC_ADDR_HI                 (COMM_INPUT_BASE_ADDR + 0x00000004)
#define EDMA_PHYS_MEM_SIZE_ADDR                     (COMM_INPUT_BASE_ADDR + 0x00000008)
#define EDMA_HOST_DATA_US_START_LLI_ADDR            (COMM_INPUT_BASE_ADDR + 0x00000014)
#define EDMA_HOST_DATA_US_LLI_NUM_ADDR              (COMM_INPUT_BASE_ADDR + 0x00000018)
#define EDMA_HOST_DATA_DS_START_LLI_ADDR            (COMM_INPUT_BASE_ADDR + 0x0000001C)
#define EDMA_HOST_DATA_DS_LLI_NUM_ADDR              (COMM_INPUT_BASE_ADDR + 0x00000020)
#define EDMA_HOST_DATA_BUFFER_NUM_ARR_ADDR          (COMM_INPUT_BASE_ADDR + 0x00000024)
#define EDMA_HOST_DATA_ODD_BUFFER_SIZE_ARR_ADDR     (COMM_INPUT_BASE_ADDR + 0x000000A4)
#define EDMA_HOST_DATA_EVEN_BUFFER_SIZE_ARR_ADDR    (COMM_INPUT_BASE_ADDR + 0x00000124)

#define PDMA_HOST_BRU_DESC_INFO                     (COMM_INPUT_BASE_ADDR + 0x00000348)

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
#define REGS_MODE_ADDR                       (COMM_INPUT_BASE_ADDR + 0x00000000)

/* the shared memory base address is defined in "interCommMem.h" */

uint32_t CL_UMAC_REMOTE_IRAM_BASE_ADDR () {
    if (boot_drv_usb_cfg()->asic_vers == ASIC_VERS_B) {
        return CELENO_UMAC_REMOTE_IRAM_BASE_ADDR_B;
    }

    return CELENO_UMAC_REMOTE_IRAM_BASE_ADDR;
}

void print_memtest_cfg(uint32_t comm_base) {
    printf("Shared RAM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + CELENO_SRAM_BASE_ADDR), CL_REG_READ(comm_base + CELENO_SRAM_SIZE_ADDR));
    printf("Local IRAM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + MEM_LOCAL_IRAM_BASE_ADDR), CL_REG_READ(comm_base + MEM_LOCAL_IRAM_SIZE_ADDR));
    printf("Local DRAM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + MEM_LOCAL_DRAM_BASE_ADDR), CL_REG_READ(comm_base + MEM_LOCAL_DRAM_SIZE_ADDR));
    printf("Remote IRAM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + MEM_REMOTE_IRAM_BASE_ADDR), CL_REG_READ(comm_base +MEM_REMOTE_IRAM_SIZE_ADDR));
    printf("Remote DRAM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + MEM_REMOTE_DRAM_BASE_ADDR), CL_REG_READ(comm_base + MEM_REMOTE_DRAM_SIZE_ADDR));
    printf("Remote1 IRAM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + MEM_REMOTE_1_IRAM_BASE_ADDR), CL_REG_READ(comm_base + MEM_REMOTE_1_IRAM_SIZE_ADDR));
    printf("Remote1 DRAM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + MEM_REMOTE_1_DRAM_BASE_ADDR), CL_REG_READ(comm_base + MEM_REMOTE_1_DRAM_SIZE_ADDR));
    printf("Phy DMEM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + CELENO_PHY_DMEM_BASE_ADDR), CL_REG_READ(comm_base + CELENO_PHY_DMEM_SIZE_ADDR));
    printf("Phy PMEM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + CELENO_PHY_PMEM_BASE_ADDR), CL_REG_READ(comm_base + CELENO_PHY_PMEM_SIZE_ADDR));
    printf("Phy XMEM 0x%08X[0x%04X]\n", CL_REG_READ(comm_base + CELENO_PHY_XMEM_BASE_ADDR), CL_REG_READ(comm_base + CELENO_PHY_XMEM_SIZE_ADDR));
}

void pre_fw_test(char* lmac_fw_name,char* umac_fw_name,char* smac_fw_name, bool is_usb)
{
    TEST_INFO("%s: entry (lmac=%s,umac=%s,smac=%s).\n",__func__,lmac_fw_name,umac_fw_name,smac_fw_name);

    if ( !strcmp(lmac_fw_name, umac_fw_name) && !( !strcmp(lmac_fw_name, "no_load") ) && !( !strcmp(lmac_fw_name, a_fw_test_name[MAC_IPC_TEST]) ) )
    {
        TEST_INFO("WARNING: LMAC and UMAC tests are same (lmac=%s,umac=%s).\n",lmac_fw_name,umac_fw_name);
    }
    if ( !strcmp(lmac_fw_name, smac_fw_name) && !( !strcmp(lmac_fw_name, "no_load") ) && !( !strcmp(lmac_fw_name, a_fw_test_name[MAC_IPC_TEST]) ) )
    {
        TEST_INFO("WARNING: LMAC and SMAC tests are same (lmac=%s,smac=%s).\n",lmac_fw_name,smac_fw_name);
    }
    if ( !strcmp(umac_fw_name, smac_fw_name) && !( !strcmp(umac_fw_name, "no_load") ) && !( !strcmp(umac_fw_name, a_fw_test_name[MAC_IPC_TEST]) ) )
    {
        TEST_INFO("WARNING: UMAC and SMAC tests are same (umac=%s,smac=%s).\n",umac_fw_name,smac_fw_name);
    }

    /* Running LMAC tests */
    if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_REGISTERS_TEST]) )
    {
       /* reset the MAC end test indication */
        CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
        // dummy phy mode
        CL_REG_WRITE(0x1, LMAC_COMM_BASE_ADDR + REGS_MODE_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_MEMORY_TEST]) )
    {
        char buffer[COMM_FULL_SIZE];
        memset(buffer, 0, sizeof(buffer));

        cl_usb_burst_write(LMAC_COMM_BASE_ADDR, buffer, COMM_FULL_SIZE, false);

        // reset the MAC end test indication
        CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        // Local dram 1
        CL_REG_WRITE(CELENO_LMAC_LOCAL_IRAM_TEST_BASE_ADDR,
            LMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_LOCAL_IRAM_TEST_SIZE_ADDR,
            LMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_LOCAL_DRAM_TEST_BASE_ADDR,
            LMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_LOCAL_DRAM_TEST_SIZE_ADDR,
            LMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_SIZE_ADDR);

        // Shared Memory
        if (is_usb) {
            CL_REG_WRITE(CELENO_SHARED_RAM_TEST_BASE_ADDR,
                LMAC_COMM_BASE_ADDR + CELENO_SRAM_BASE_ADDR);
            CL_REG_WRITE(CELENO_SHARED_RAM_TEST_SIZE_ADDR_USB,
                LMAC_COMM_BASE_ADDR + CELENO_SRAM_SIZE_ADDR);
        }

        // Remote - UMAC Memories
        CL_REG_WRITE(CL_UMAC_REMOTE_IRAM_BASE_ADDR(),
            LMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_IRAM_SIZE,
            LMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_REMOTE_DRAM_BASE_ADDR,
            LMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_DRAM_SIZE,
            LMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_SIZE_ADDR);

        // Remote_1 - SMAC Memories
        CL_REG_WRITE(CELENO_SMAC_REMOTE_IRAM_BASE_ADDR,
            LMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_IRAM_SIZE,
            LMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_REMOTE_DRAM_BASE_ADDR,
            LMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_DRAM_SIZE,
            LMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_SIZE_ADDR);

#if 0
        // in current CL8000 ASIC & PALLADIUM B2B models we have UMAC & PHY
        if ( cl_platform == CL_PLATFORM_ASIC_IDX || cl_platform == CL_PLATFORM_B2B_IDX )
        {
            // PHY Memories
            CL_REG_WRITE(CELENO_PHY_DMEM_BASE,
                LMAC_COMM_BASE_ADDR + CELENO_PHY_DMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_DMEM_SIZE,
                LMAC_COMM_BASE_ADDR + CELENO_PHY_DMEM_SIZE_ADDR);
            CL_REG_WRITE(CELENO_PHY_PMEM_BASE,
                LMAC_COMM_BASE_ADDR + CELENO_PHY_PMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_PMEM_SIZE,
                LMAC_COMM_BASE_ADDR + CELENO_PHY_PMEM_SIZE_ADDR);
            CL_REG_WRITE(CELENO_PHY_XMEM_BASE,
                LMAC_COMM_BASE_ADDR + CELENO_PHY_XMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_XMEM_SIZE,
                LMAC_COMM_BASE_ADDR + CELENO_PHY_XMEM_SIZE_ADDR);
        }
#endif

        print_memtest_cfg(LMAC_COMM_BASE_ADDR);

    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_INTERRUPTS_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
        /* The interrupt test do not wait on end indication, since the interrupts are set by
         * the host here after, so the host knows when the test terminates. */
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_CORE_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_IPC_TEST]) )
    {
#if 0
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        // Tell FW which of the neighbors exist
#if defined (CL8000_NOT_DPHY) // i.e. CL8000 but not PALLADIUM
        CL_REG_WRITE(1, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_XMAC_VALID); // CL8000 with UMAC
#else
        CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_XMAC_VALID); // CL8000 without UMAC
#endif
        CL_REG_WRITE(1, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_YMAC_VALID);
#else
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
#endif
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_MCCI_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
        //CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_LINE_IDX);
        //CL_REG_WRITE(0x12345678, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_DW_1);
        //CL_REG_WRITE(0x11223344, LMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_DW_2);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_CYCLE_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, LMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_EDMA_TEST]) )
    {
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_EDMA_TP_TEST]) )
    {
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
    }
    else if (!strcmp(lmac_fw_name, a_fw_test_name[MAC_UDMA_TEST]))
    {
        /* Set sequence id = 0 */
        CL_REG_WRITE(0, UDMA_LMAC_TEST_STATUS_START_ADDR +
            UDMA_TEST_STATUS_SEQUENCE_ID_OFS);
    }
    else
    {
        TEST_INFO("LMAC run %s\n\n", lmac_fw_name);
    }

    if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_REGISTERS_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
        // dummy phy mode
        CL_REG_WRITE(0x1, UMAC_COMM_BASE_ADDR + REGS_MODE_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_MEMORY_TEST]) )
    {
        char buffer[COMM_FULL_SIZE];
        memset(buffer, 0, sizeof(buffer));

        cl_usb_burst_write(UMAC_COMM_BASE_ADDR, buffer, COMM_FULL_SIZE, false);

        // reset the MAC end test indication
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        // Local
        CL_REG_WRITE(CELENO_UMAC_LOCAL_IRAM_TEST_BASE_ADDR,
            UMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_LOCAL_IRAM_TEST_SIZE_ADDR,
            UMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_LOCAL_DRAM_TEST_BASE_ADDR,
            UMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_LOCAL_DRAM_TEST_SIZE_ADDR,
            UMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_SIZE_ADDR);

        // Shared Memory
        if (is_usb) {
            CL_REG_WRITE(CELENO_SHARED_RAM_TEST_BASE_ADDR,
                UMAC_COMM_BASE_ADDR + CELENO_SRAM_BASE_ADDR);
            CL_REG_WRITE(CELENO_SHARED_RAM_TEST_SIZE_ADDR_USB,
                UMAC_COMM_BASE_ADDR + CELENO_SRAM_SIZE_ADDR);
        }

        // Remote - LMAC Memories
        CL_REG_WRITE(CELENO_LMAC_REMOTE_IRAM_BASE_ADDR,
            UMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_IRAM_SIZE,
            UMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_REMOTE_DRAM_BASE_ADDR,
            UMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_DRAM_SIZE,
            UMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_SIZE_ADDR);

        // Remote_1 - SMAC Memories
        CL_REG_WRITE(CELENO_SMAC_REMOTE_IRAM_BASE_ADDR,
            UMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_IRAM_SIZE,
            UMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_REMOTE_DRAM_BASE_ADDR,
            UMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_DRAM_SIZE,
            UMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_SIZE_ADDR);

#if 0
        // in current CL8000 ASIC & PALLADIUM B2B models we have UMAC & PHY
        if ( cl_platform == CL_PLATFORM_ASIC_IDX || cl_platform == CL_PLATFORM_B2B_IDX )
        {
            // PHY Memories
            CL_REG_WRITE(CELENO_PHY_DMEM_BASE,
                UMAC_COMM_BASE_ADDR + CELENO_PHY_DMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_DMEM_SIZE,
                UMAC_COMM_BASE_ADDR + CELENO_PHY_DMEM_SIZE_ADDR);
            CL_REG_WRITE(CELENO_PHY_PMEM_BASE,
                UMAC_COMM_BASE_ADDR + CELENO_PHY_PMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_PMEM_SIZE,
                UMAC_COMM_BASE_ADDR + CELENO_PHY_PMEM_SIZE_ADDR);
            CL_REG_WRITE(CELENO_PHY_XMEM_BASE,
                UMAC_COMM_BASE_ADDR + CELENO_PHY_XMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_XMEM_SIZE,
                UMAC_COMM_BASE_ADDR + CELENO_PHY_XMEM_SIZE_ADDR);
        }
#endif

        print_memtest_cfg(UMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_INTERRUPTS_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
        /* The interrupt test do not wait on end indication, since the interrupts are set by
           the host here after, so the host int apre_usb_cli_test()
           knows when the test terminates.
           reset the MAC ready test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_CORE_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_IPC_TEST]) )
    {
#if 0
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        // Tell FW which of the neighbors exist
#if defined (CL8000_NOT_DPHY) // i.e. CL8000 but not PALLADIUM
        CL_REG_WRITE(1, UMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_XMAC_VALID); // CL8000 with LMAC
        CL_REG_WRITE(1, UMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_YMAC_VALID); // CL8000 with SMAC
#endif
#else
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
#endif
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_MCCI_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_CYCLE_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_EDMA_TEST]) )
    {
#if 0
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        virt_dma_mem = dma_alloc_coherent(cl_hw->dev, EDMA_MEM_SIZE, &phys_dma_mem, GFP_KERNEL);
        if (virt_dma_mem != NULL)
        {
            TEST_INFO("UMAC EDMA Test: Allocated DMA memory - size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
                             EDMA_MEM_SIZE, (uint64_t)phys_dma_mem, virt_dma_mem);
            CL_REG_WRITE(phys_dma_mem & 0xffffffff, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO);
            CL_REG_WRITE(((uint64_t)phys_dma_mem) >> 32, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI);
            CL_REG_WRITE(EDMA_MEM_SIZE, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR);
        }
        else
        {
            TEST_INFO("ERROR: UMAC EDMA Test - failed to allocated DMA memory!\n");
        }
#else
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
#endif
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_EDMA_TP_TEST]) )
    {
#if 0
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, UMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        virt_dma_mem = dma_alloc_coherent(cl_hw->dev, EDMA_MEM_SIZE, &phys_dma_mem, GFP_KERNEL);
        if (virt_dma_mem != NULL)
        {
            TEST_INFO("UMAC EDMA TP Test: Allocated DMA memory - size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
                             EDMA_MEM_SIZE, (uint64_t)phys_dma_mem, virt_dma_mem);
            CL_REG_WRITE(phys_dma_mem & 0xffffffff, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO);
            CL_REG_WRITE(((uint64_t)phys_dma_mem) >> 32, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI);
            CL_REG_WRITE(EDMA_MEM_SIZE, UMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR);
        }
        else
        {
            TEST_INFO("ERROR: UMAC EDMA TP Test - failed to allocated DMA memory!\n");
        }
#else
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
#endif
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_CLI_TEST]) )
    {
       /* USB CLi test */
        TEST_INFO("Umac USB CLI test prepare - nothing todo.\n");
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_TP_TEST]) )
    {
       /* USB TP test */
        TEST_INFO("Umac USB TP test prepare - nothing todo.\n");
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_WRAPPER_LMAC_TEST]) )
    {
        /* USB Wrapper test */
        bool zero_copy = false;
        char* buffer = malloc(WRAPPER_TEST_CONTROL_STATUS_SIZE);
        memset(buffer, 0, WRAPPER_TEST_CONTROL_STATUS_SIZE);

        TEST_INFO("Umac USB Wrapper test prepare for LMAC.\n");
        cl_usb_burst_write(LMAC_WRAPPER_TEST_CONTROL_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);
        cl_usb_burst_write(LMAC_WRAPPER_TEST_STATUS_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);

        free(buffer);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_WRAPPER_SMAC_TEST]) )
    {
        /* USB Wrapper test */
        bool zero_copy = false;
        char* buffer = malloc(WRAPPER_TEST_CONTROL_STATUS_SIZE);
        memset(buffer, 0, WRAPPER_TEST_CONTROL_STATUS_SIZE);

        TEST_INFO("Umac USB Wrapper test prepare for SMAC.\n");
        cl_usb_burst_write(SMAC_WRAPPER_TEST_CONTROL_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);
        cl_usb_burst_write(SMAC_WRAPPER_TEST_STATUS_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);

        free(buffer);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_WIFI_RESET_TEST]) )
    {
        /* USB Wifi reset test */
        bool zero_copy = true;
        char* buffer = malloc(WRAPPER_TEST_CONTROL_STATUS_SIZE);
        memset(buffer, 0, WRAPPER_TEST_CONTROL_STATUS_SIZE);

        TEST_INFO("Umac USB Wifi test prepare for LMAC.\n");
        cl_usb_burst_write(LMAC_WRAPPER_TEST_CONTROL_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);
        cl_usb_burst_write(LMAC_WRAPPER_TEST_STATUS_BASE, buffer, WRAPPER_TEST_CONTROL_STATUS_SIZE, zero_copy);

        free(buffer);
    }
    else
    {
        TEST_INFO("UMAC run %s\n\n", umac_fw_name);
    }

    // Running SMAC tests
    if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_REGISTERS_TEST]) )
    {
       /* reset the MAC end test indication */
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
        // dummy phy mode
        CL_REG_WRITE(0x1, SMAC_COMM_BASE_ADDR + REGS_MODE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_MEMORY_TEST]) )
    {
        char buffer[COMM_FULL_SIZE];
        memset(buffer, 0, sizeof(buffer));

        cl_usb_burst_write(SMAC_COMM_BASE_ADDR, buffer, COMM_FULL_SIZE, false);

        // reset the MAC end test indication
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        // Local dram 1
        CL_REG_WRITE(CELENO_SMAC_LOCAL_IRAM_TEST_BASE_ADDR,
            SMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_LOCAL_IRAM_TEST_SIZE_ADDR,
            SMAC_COMM_BASE_ADDR + MEM_LOCAL_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_LOCAL_DRAM_TEST_BASE_ADDR,
            SMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_SMAC_LOCAL_DRAM_TEST_SIZE_ADDR,
            SMAC_COMM_BASE_ADDR + MEM_LOCAL_DRAM_SIZE_ADDR);

        // Shared Memory
        if (is_usb) {
            CL_REG_WRITE(CELENO_SHARED_RAM_TEST_BASE_ADDR,
                SMAC_COMM_BASE_ADDR + CELENO_SRAM_BASE_ADDR);
            CL_REG_WRITE(CELENO_SHARED_RAM_TEST_SIZE_ADDR_USB,
                SMAC_COMM_BASE_ADDR + CELENO_SRAM_SIZE_ADDR);
        }

        // Remote - LMAC Memories
        CL_REG_WRITE(CELENO_LMAC_REMOTE_IRAM_BASE_ADDR,
            SMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_IRAM_SIZE,
            SMAC_COMM_BASE_ADDR + MEM_REMOTE_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_REMOTE_DRAM_BASE_ADDR,
            SMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_LMAC_DRAM_SIZE,
            SMAC_COMM_BASE_ADDR + MEM_REMOTE_DRAM_SIZE_ADDR);

        // Remote_1 - UMAC Memories
        CL_REG_WRITE(CL_UMAC_REMOTE_IRAM_BASE_ADDR(),
            SMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_IRAM_SIZE,
            SMAC_COMM_BASE_ADDR + MEM_REMOTE_1_IRAM_SIZE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_REMOTE_DRAM_BASE_ADDR,
            SMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_BASE_ADDR);
        CL_REG_WRITE(CELENO_UMAC_DRAM_SIZE,
            SMAC_COMM_BASE_ADDR + MEM_REMOTE_1_DRAM_SIZE_ADDR);

#if 0
        // in current CL8000 ASIC & PALLADIUM B2B models we have UMAC & PHY
        if ( cl_platform == CL_PLATFORM_ASIC_IDX || cl_platform == CL_PLATFORM_B2B_IDX )
        {
            // PHY Memories
            CL_REG_WRITE(CELENO_PHY_DMEM_BASE,
                SMAC_COMM_BASE_ADDR + CELENO_PHY_DMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_DMEM_SIZE,
                SMAC_COMM_BASE_ADDR + CELENO_PHY_DMEM_SIZE_ADDR);
            CL_REG_WRITE(CELENO_PHY_PMEM_BASE,
                SMAC_COMM_BASE_ADDR + CELENO_PHY_PMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_PMEM_SIZE,
                SMAC_COMM_BASE_ADDR + CELENO_PHY_PMEM_SIZE_ADDR);
            CL_REG_WRITE(CELENO_PHY_XMEM_BASE,
                SMAC_COMM_BASE_ADDR + CELENO_PHY_XMEM_BASE_ADDR);
            CL_REG_WRITE(CELENO_PHY_XMEM_SIZE,
                SMAC_COMM_BASE_ADDR + CELENO_PHY_XMEM_SIZE_ADDR);
        }
#endif
        print_memtest_cfg(SMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_INTERRUPTS_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
        /* The interrupt test do not wait on end indication, since the interrupts are set by
         * the host here after, so the host knows when the test terminates. */
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_CORE_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_IPC_TEST]) )
    {
#if 0
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        // Tell FW which of the neighbors exist
        CL_REG_WRITE(1, SMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_XMAC_VALID); // LMAC
#if defined (CL8000_NOT_DPHY) // i.e. CL8000 but not PALLADIUM
        CL_REG_WRITE(1, SMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_YMAC_VALID); // CL8000 with UMAC
#else
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + HOST_CFG_INPUT_YMAC_VALID); // CL8000 without UMAC
#endif
#else
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
#endif
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_MCCI_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_CYCLE_TEST]) )
    {
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_EDMA_TEST]) )
    {
#if 0
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        virt_dma_mem = dma_alloc_coherent(cl_hw->dev, EDMA_MEM_SIZE, &phys_dma_mem, GFP_KERNEL);
        if (virt_dma_mem != NULL)
        {
            TEST_INFO("LMAC EDMA Test: Allocated DMA memory - size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
                             EDMA_MEM_SIZE, (uint64_t)phys_dma_mem, virt_dma_mem);

            CL_REG_WRITE(phys_dma_mem & 0xffffffff, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO);
            CL_REG_WRITE(((uint64_t)phys_dma_mem) >> 32, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI);
            CL_REG_WRITE(EDMA_MEM_SIZE, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR);
        }
        else
        {
            TEST_INFO("ERROR: LMAC EDMA Test - failed to allocated DMA memory!\n");
        }
#else
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
#endif
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_EDMA_TP_TEST]) )
    {
#if 0
        /* reset the MAC end test indication */
        CL_REG_WRITE(0, SMAC_COMM_BASE_ADDR + TEST_END_INDICATION_ADDR);

        virt_dma_mem = dma_alloc_coherent(cl_hw->dev, EDMA_MEM_SIZE, &phys_dma_mem, GFP_KERNEL);
        if (virt_dma_mem != NULL)
        {
            TEST_INFO("LMAC EDMA TP Test: Allocated DMA memory - size = 0x%x, dma-addr = 0x%llX, virt-addr = 0x%p\n",
                             EDMA_MEM_SIZE, (uint64_t)phys_dma_mem, virt_dma_mem);

            CL_REG_WRITE(phys_dma_mem & 0xffffffff, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_LO);
            CL_REG_WRITE(((uint64_t)phys_dma_mem) >> 32, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_ALLOC_ADDR_HI);
            CL_REG_WRITE(EDMA_MEM_SIZE, SMAC_COMM_BASE_ADDR + EDMA_PHYS_MEM_SIZE_ADDR);
        }
        else
        {
            TEST_INFO("ERROR: LMAC EDMA TP Test - failed to allocated DMA memory!\n");
        }
#else
        TEST_INFO("ERROR: this test does not work in usermode!\n");
        return;
#endif
    }
    else if (!strcmp(smac_fw_name, a_fw_test_name[MAC_UDMA_TEST]))
    {
        /* Set sequence id = 0 */
        CL_REG_WRITE(0, UDMA_SMAC_TEST_STATUS_START_ADDR +
         UDMA_TEST_STATUS_SEQUENCE_ID_OFS);
    }
    else
    {
        TEST_INFO("SMAC run %s\n\n", smac_fw_name);
    }

    return;
}

int apre_fw_test(char* lmac_fw_name,char* umac_fw_name,char* smac_fw_name, bool is_usb)
{
    // all tests which are not yet integrated for cl6000 will fail (... intentionally)
    int result = FAILED;

    TEST_INFO("%s: entry (lmac=%s,umac=%s,smac=%s).\n",__func__,lmac_fw_name,umac_fw_name,smac_fw_name);

    usleep(1000);

    /* handle LMAC test result */
    if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_REGISTERS_TEST]) )
    {
        /* registers test */
        TEST_INFO("Lmac Registers test: \n");
    	  apre_registers_test(LMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_MEMORY_TEST]) )
    {
        /* memory test */
        TEST_INFO("Lmac memory test \n");
    	  apre_mem_fw_test(LMAC_COMM_BASE_ADDR, DRAM_TYPE_2, false);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_INTERRUPTS_TEST]) )
    {
       /* Interrupt test */
        TEST_INFO("Lmac interrupts test \n");
       /* The interrupt test do not wait on end indication, since the interrupts are set by
        * the host here after, so the host knows when the test terminates. */
        apre_interrupts_fw_test(LMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_CORE_TEST]) )
    {
       /* Core test */
        TEST_INFO("Lmac CORE test \n");
    	  result = apre_core_test(LMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_IPC_TEST]) )
    {
        /* IPC test */
        TEST_INFO("Lmac IPC test \n");
    	apre_ipc_test(LMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_MCCI_TEST]) )
    {
       /* MCCI test */
        TEST_INFO("Lmac MCCI test \n");
    	apre_mcci_test(LMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_CYCLE_TEST]) )
    {
       /* MCCI test */
        TEST_INFO("Lmac CYCLE test \n");
    	apre_cycle_test(LMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_EDMA_TEST]) )
    {
       /* EDMA test */
        TEST_INFO("Lmac EDMA test \n");
    	apre_edma_test(EDMA_LMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(lmac_fw_name, a_fw_test_name[MAC_EDMA_TP_TEST]) )
    {
       /* EDMA TP test */
        TEST_INFO("Lmac EDMA TP test \n");
    	apre_edma_tp_test(LMAC_COMM_BASE_ADDR);
    }
    else if (!strcmp(lmac_fw_name, a_fw_test_name[MAC_UDMA_TEST]))
    {
        /* UDMA test */
        TEST_INFO("Lmac UDMA test\n");
        apre_udma_test(UDMA_LMAC_TEST_CONTROL_START_ADDR,
            UDMA_LMAC_TEST_STATUS_START_ADDR);
    }
    else if ( 0 == strcmp(lmac_fw_name, "no_load") ) {
    }
    else {
        apre_other_test(LMAC_COMM_BASE_ADDR);
    }
    TEST_INFO("\n");
    /* handle UMAC test result */
    if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_REGISTERS_TEST]) )
    {
        /* registers test */
        TEST_INFO("Umac Registers test: \n");
    	apre_registers_test(UMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_MEMORY_TEST]) )
    {
        /* memory test */
        TEST_INFO("Umac memory test \n");
    	apre_mem_fw_test(UMAC_COMM_BASE_ADDR, DRAM_TYPE_1, is_usb);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_INTERRUPTS_TEST]) )
    {
       /* Interrupt test */
        TEST_INFO("Umac interrupts test \n");
       /* The interrupt test do not wait on end indication, since the interrupts are set by
        * the host here after, so the host knows when the test terminates. */
        apre_interrupts_fw_test(UMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_CORE_TEST]) )
    {
       /* Core test */
       TEST_INFO("Umac Core test - trigger umac usb-disconnect/restart\n");
       return apre_usb_core_test();
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_IPC_TEST]) )
    {
        /* IPC test */
        TEST_INFO("Umac IPC test \n");
        apre_ipc_test(UMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_MCCI_TEST]) )
    {
       /* MCCI test */
        TEST_INFO("Umac MCCI test \n");
   	    apre_mcci_test(UMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_CYCLE_TEST]) )
    {
       /* CYCLE test */
        TEST_INFO("Umac CYCLE test \n");
   	    apre_cycle_test(UMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_EDMA_TEST]) )
    {
       /* EDMA test */
        TEST_INFO("Umac EDMA test \n");
    	apre_edma_test(UMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_EDMA_TP_TEST]) )
    {
       /* EDMA TP test */
        TEST_INFO("Umac EDMA TP test \n");
      apre_edma_tp_test(UMAC_COMM_BASE_ADDR);
    }
    else if (!strcmp(umac_fw_name, a_fw_test_name[MAC_UDMA_TEST]))
    {
        /* UDMA test runs on both LMAC & UMAC, no need to check UMAC output */
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_CLI_TEST]) )
    {
        TEST_INFO("Umac USB CLI test \n");
        return apre_usb_cli_test();
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_TP_TEST]) )
    {
        TEST_INFO("Umac USB TP test \n");
        return apre_usb_tp_test();
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_WRAPPER_LMAC_TEST]) )
    {
        TEST_INFO("Umac USB Wrapper test \n");
        return apre_usb_wrapper_test(umac_lsmac_test_fw_name, NULL);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_WRAPPER_SMAC_TEST]) )
    {
        TEST_INFO("Umac USB Wrapper test \n");
        return apre_usb_wrapper_test(NULL, umac_lsmac_test_fw_name);
    }
    else if ( !strcmp(umac_fw_name, a_fw_test_name[MAC_USB_WIFI_RESET_TEST]) )
    {
        TEST_INFO("Umac USB Wifi reset test \n");
        return apre_usb_wifi_reset_test(umac_lsmac_test_fw_name);
    }
    else if ( 0 == strcmp(umac_fw_name, "no_load") ) {
    }
    else {
        apre_other_test(UMAC_COMM_BASE_ADDR);
    }

    TEST_INFO("\n");
    /* handle SMAC test result */
    if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_REGISTERS_TEST]) )
    {
        /* registers test */
        TEST_INFO("Smac Registers test: \n");
        apre_registers_test(SMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_MEMORY_TEST]) )
    {
        /* memory test */
        TEST_INFO("Smac memory test \n");
        apre_mem_fw_test(SMAC_COMM_BASE_ADDR, DRAM_TYPE_2, false);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_INTERRUPTS_TEST]) )
    {
        /* Interrupt test */
        TEST_INFO("Smac interrupts test \n");
       /* The interrupt test do not wait on end indication, since the interrupts are set by
        * the host here after, so the host knows when the test terminates. */
        apre_interrupts_fw_test(SMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_CORE_TEST]) )
    {
        /* Core test */
        TEST_INFO("Smac CORE test \n");
        result = apre_core_test(SMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_IPC_TEST]) )
    {
        /* IPC test */
        TEST_INFO("Smac IPC test \n");
        apre_ipc_test(SMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_MCCI_TEST]) )
    {
        /* MCCI test */
        TEST_INFO("Smac MCCI test \n");
        apre_mcci_test(SMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_CYCLE_TEST]) )
    {
        /* CYCLE test */
        TEST_INFO("Smac CYCLE test \n");
        apre_cycle_test(SMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_EDMA_TEST]) )
    {
        /* EDMA test */
        TEST_INFO("Smac EDMA test \n");
        apre_edma_test(SMAC_COMM_BASE_ADDR);
    }
    else if ( !strcmp(smac_fw_name, a_fw_test_name[MAC_EDMA_TP_TEST]) )
    {
        /* EDMA TP test */
        TEST_INFO("Smac EDMA TP test \n");
        apre_edma_tp_test(SMAC_COMM_BASE_ADDR);
    }
    else if (!strcmp(smac_fw_name, a_fw_test_name[MAC_UDMA_TEST]))
    {
        /* UDMA test */
        TEST_INFO("Smac UDMA test\n");
        apre_udma_test(UDMA_SMAC_TEST_CONTROL_START_ADDR,
            UDMA_SMAC_TEST_STATUS_START_ADDR);
    }
    else if ( 0 == strcmp(smac_fw_name, "no_load") ) {
    }
    else {
        apre_other_test(SMAC_COMM_BASE_ADDR);
    }
    return result;
}

#define FW_INT_TESTS_NUMBER  32

static char *a_fw_int_name[] =
{
    "INTC_XTOSTIMER0",     // 0
    "INTC_XTOSSW0",        // 1
    "INTC_PHY_RIU",        // 2
    "INTC_MACERROR",       // 3
    "INTC_MACGEN",         // 4
    "INTC_MACRX",          // 5
    "INTC_MACTIMER",       // 6
    "INTC_MACTX",          // 7
    "INTC_LLI",            // 8
    "INTC_BMU",            // 9
    "INTC_IPC_XMAC",       // 10
    "INTC_IPC_YMAC",       // 11
    "INTC_IPC_HOST",       // 12
    "INTC_PHY_DSP",        // 13
    "INTC_I2C",            // 14
    "INTC_EDMA",           // 15
    "INTC_ETH2WLAN_DONE",  // 16
    "INTC_UNUSED1",        // 17
    "INTC_UNUSED2",        // 18
    "INTC_UNUSED3",        // 19
    "INTC_XTOSTIMER1",     // 20
    "INTC_MACHIGH",        // 21
    "INTC_NATT_DONE",      // 22
    "INTC_UNUSED4",        // 23
    "INTC_UNUSED5",        // 24
    "INTC_UNUSED6",        // 25
    "INTC_XTOSTIMER2",     // 26
    "INTC_XTOSSW1",        // 27
    "INTC_AHBSLAVE_ERROR", // 28
    "INTC_UNUSED7",        // 29
    "INTC_UNUSED8",        // 30
    "INTC_NMI",            // 31
};

#define HOST_REG_IPC_EMB_BASE_ADDR     0x007C4000
#define IPC_APP2EMB_UNMASK_SET_ADDR   (HOST_REG_IPC_EMB_BASE_ADDR+0x0c)
#define IPC_APP2EMB_TRIGGER_ADDR      (HOST_REG_IPC_EMB_BASE_ADDR+0x80)
#define IPC_APP2UMAC_TRIGGER_ADDR     (HOST_REG_IPC_EMB_BASE_ADDR+0x84)
#define IPC_APP2SMAC_TRIGGER_ADDR     (HOST_REG_IPC_EMB_BASE_ADDR+0x88)

#define REG_MAC_HW0_BASE_ADDR 0x00600000
#define REG_MAC_HW1_BASE_ADDR 0x00680000

#define MAC_HW0_GEN_INT_EVENT_FORCE_ADDR        (REG_MAC_HW0_BASE_ADDR+0x0000810C)
#define MAC_HW0_HIGH_PRI_INT_EVENT_FORCE_ADDR   (REG_MAC_HW0_BASE_ADDR+0x00008128)
#define MAC_HW0_RX_INT_EVENT_FORCE_ADDR         (REG_MAC_HW0_BASE_ADDR+0x00008144)
#define MAC_HW0_TX_INT_EVENT_FORCE_ADDR         (REG_MAC_HW0_BASE_ADDR+0x00008160)
#define MAC_HW0_TIMER_INT_EVENT_FORCE_ADDR      (REG_MAC_HW0_BASE_ADDR+0x00008250)
#define MAC_HW0_ERROR_INT_EVENT_FORCE_ADDR      (REG_MAC_HW0_BASE_ADDR+0x000080F0)

#define MAC_HW1_GEN_INT_EVENT_FORCE_ADDR        (REG_MAC_HW1_BASE_ADDR+0x0000810C)
#define MAC_HW1_HIGH_PRI_INT_EVENT_FORCE_ADDR   (REG_MAC_HW1_BASE_ADDR+0x00008128)
#define MAC_HW1_RX_INT_EVENT_FORCE_ADDR         (REG_MAC_HW1_BASE_ADDR+0x00008144)
#define MAC_HW1_TX_INT_EVENT_FORCE_ADDR         (REG_MAC_HW1_BASE_ADDR+0x00008160)
#define MAC_HW1_TIMER_INT_EVENT_FORCE_ADDR      (REG_MAC_HW1_BASE_ADDR+0x00008250)
#define MAC_HW1_ERROR_INT_EVENT_FORCE_ADDR      (REG_MAC_HW1_BASE_ADDR+0x000080F0)

#define INTERRUPTS_COUNTER_START_ADDR      (TEST_END_INDICATION_ADDR + 0x00000010)
/* there are 32 interrupts and each counter is a 4 byte variable) */
#define INTERRUPTS_COUNTER_SIZE          (FW_INT_TESTS_NUMBER * sizeof(uint32_t))
/* set places for the interrupts latency */
#define INTERRUPT_LATENCY_LEVEL_1         (INTERRUPTS_COUNTER_START_ADDR + INTERRUPTS_COUNTER_SIZE)
#define INTERRUPT_LATENCY_LEVEL_2         (INTERRUPT_LATENCY_LEVEL_1 + 0x4)
#define INTERRUPT_LATENCY_LEVEL_3         (INTERRUPT_LATENCY_LEVEL_2 + 0x4)
/* set places for the interrupts latency */
#define INTERRUPT_INTER_LATENCY_LEVEL_1    (INTERRUPT_LATENCY_LEVEL_3 + 0x4)
#define INTERRUPT_INTER_TIME_LEVEL_1       (INTERRUPT_INTER_LATENCY_LEVEL_1 + 0x4)
#define INTERRUPT_INTER_LATENCY_LEVEL_3    (INTERRUPT_INTER_TIME_LEVEL_1 + 0x4)
#define INTERRUPT_INTER_TIME_LEVEL_3       (INTERRUPT_INTER_LATENCY_LEVEL_3 + 0x4)

void apre_interrupts_fw_test(uint32_t base_addr)
{
    int I;
    uint32_t int_cnr = base_addr + INTERRUPTS_COUNTER_START_ADDR;
    uint32_t cnt=0;

    // wait for the FW to signal test end
    CL_WAIT_4_TEST_END_IND(50);

    if ( base_addr == LMAC_COMM_BASE_ADDR )
    {
        // MAC-HW General interrupt
        CL_REG_WRITE(0x00000001, MAC_HW0_GEN_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW High Priority Interrupt
        CL_REG_WRITE(0x00000040, MAC_HW0_HIGH_PRI_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW RX Interrupt
        CL_REG_WRITE(0x00010000, MAC_HW0_RX_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW TIMER interrupt
        CL_REG_WRITE(0x00004000, MAC_HW0_TIMER_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW TX interrupt
        CL_REG_WRITE(0x00000010, MAC_HW0_TX_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW ERROR interrupt
        CL_REG_WRITE(0x00000020, MAC_HW0_ERROR_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // IPC interrupt
        CL_REG_WRITE(0xFFFFFFFF, IPC_APP2EMB_TRIGGER_ADDR);
    }
    else if ( base_addr == SMAC_COMM_BASE_ADDR )
    {
        // MAC-HW General interrupt
        CL_REG_WRITE(0x00000001, MAC_HW1_GEN_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW High Priority Interrupt
        CL_REG_WRITE(0x00000040, MAC_HW1_HIGH_PRI_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW RX Interrupt
        CL_REG_WRITE(0x00010000, MAC_HW1_RX_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW TIMER interrupt
        CL_REG_WRITE(0x00004000, MAC_HW1_TIMER_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW TX interrupt
        CL_REG_WRITE(0x00000010, MAC_HW1_TX_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // MAC-HW ERROR interrupt
        CL_REG_WRITE(0x00000020, MAC_HW1_ERROR_INT_EVENT_FORCE_ADDR);
        usleep(100);
        // IPC interrupt
        CL_REG_WRITE(0xFFFFFFFF, IPC_APP2SMAC_TRIGGER_ADDR);
    }
    else
    {
        // IPC interrupt
        CL_REG_WRITE(0xFFFFFFFF, IPC_APP2UMAC_TRIGGER_ADDR);
    }

    usleep(1000);

    // Print all the interrupts conters
    for ( I = 0; I < FW_INT_TESTS_NUMBER; I++ )
    {
        TEST_INFO("\t\t%s = %u\n", a_fw_int_name[I], CL_REG_READ(int_cnr));
        int_cnr += 4;
    }

    /* display the interrupt latency for each interrupt level */
    TEST_INFO("\tInterrupt latency (in cycles):\n");
    TEST_INFO("\t\tLEVEL 1: %d\n", CL_REG_READ(base_addr + INTERRUPT_LATENCY_LEVEL_1));
    TEST_INFO("\t\tLEVEL 2: %d\n", CL_REG_READ(base_addr + INTERRUPT_LATENCY_LEVEL_2));
    TEST_INFO("\t\tLEVEL 3: %d\n", CL_REG_READ(base_addr + INTERRUPT_LATENCY_LEVEL_3));

    /* display the interrupt latency when an interrupt is set from an ISR to one in higher level */
    TEST_INFO("\tInter Interrupt latency (in cycles):\n");
    TEST_INFO("\t\tLEVEL 1: %d --> LEVEL 3: %d\n",
                 CL_REG_READ(base_addr + INTERRUPT_INTER_LATENCY_LEVEL_1),
                 CL_REG_READ(base_addr + INTERRUPT_INTER_LATENCY_LEVEL_3));
    TEST_INFO("\t\tduration in LEVEL 1: %d\n",
                    CL_REG_READ(base_addr + INTERRUPT_INTER_TIME_LEVEL_1));
}

#define TEST_MULTIPULE_ACCESS_RESULTS_ADDR    (COMM_OUTPUT_BASE_ADDR + 0x00000020)
#define TEST_SHARED_ACCESS_NUM_ADDR           (TEST_MULTIPULE_ACCESS_RESULTS_ADDR)
#define TEST_SHARED_WRITE_CYCLES_ADDR         (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000004)
#define TEST_SHARED_READ_CYCLES_ADDR          (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000008)
#if (CE_HW_VERSION == HW_8000_STEP_A0)
    #define TEST_DIRECT_SHARED_ACCESS_NUM_ADDR    (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000000C)
    #define TEST_DIRECT_SHARED_WRITE_CYCLES_ADDR  (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000010)
    #define TEST_DIRECT_SHARED_READ_CYCLES_ADDR   (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000014)
#endif // (CE_HW_VERSION == HW_8000_STEP_A0)
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
#if (CE_HW_VERSION >= HW_8000_STEP_B0)
    #define TEST_LOCAL_DRAM_2_ACCESS_NUM_ADDR       (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000054)
    #define TEST_LOCAL_DRAM_2_WRITE_CYCLES_ADDR     (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x00000058)
    #define TEST_LOCAL_DRAM_2_READ_CYCLES_ADDR      (TEST_MULTIPULE_ACCESS_RESULTS_ADDR + 0x0000005C)
#endif // CE_HW_VERSION >= HW_8000_STEP_B0
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
#if (CE_HW_VERSION == HW_8000_STEP_A0)
    #define TEST_DIRECT_SHARED_WRITE_SINGLE_ADDR  (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000008)
    #define TEST_DIRECT_SHARED_READ_SINGLE_ADDR   (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000000C)
#endif // (CE_HW_VERSION == HW_8000_STEP_A0)
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
#if (CE_HW_VERSION >= HW_8000_STEP_B0)
    #define TEST_LOCAL_DRAM_2_WRITE_SINGLE_ADDR     (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000038)
    #define TEST_LOCAL_DRAM_2_READ_SINGLE_ADDR      (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000003C)
#endif // CE_HW_VERSION >= HW_8000_STEP_B0
#define TEST_REMOTE_IRAM_WRITE_SINGLE_ADDR    (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000040)
#define TEST_REMOTE_IRAM_READ_SINGLE_ADDR     (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000044)
#define TEST_REMOTE_DRAM_WRITE_SINGLE_ADDR    (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000048)
#define TEST_REMOTE_DRAM_READ_SINGLE_ADDR     (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000004C)
#define TEST_REMOTE_1_IRAM_WRITE_SINGLE_ADDR  (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000050)
#define TEST_REMOTE_1_IRAM_READ_SINGLE_ADDR   (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000054)
#define TEST_REMOTE_1_DRAM_WRITE_SINGLE_ADDR  (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x00000058)
#define TEST_REMOTE_1_DRAM_READ_SINGLE_ADDR   (TEST_SINGLE_ACCESS_RESULTS_ADDR + 0x0000005C)

#define TEST_CYCLES_TIME_FATCH_ADDR           (TEST_REMOTE_1_DRAM_READ_SINGLE_ADDR + 0x00000004)

void apre_mem_fw_test(uint32_t base_addr, uint8_t dram_type, bool umac_host_if_usb)
{
    uint32_t fail_module,fail_addr;
    uint32_t access_num,write_cycles_access,read_cycles_access;
    uint32_t cycle_fetch_time,write_single_cycles,read_single_cycles;
    uint32_t cnt=0;

    if (umac_host_if_usb) {
        usb_wait_4_test_end_ind(100 * ce_fw_scale_down, base_addr + TEST_END_INDICATION_ADDR);
    } else {
        // Since the result and end indication are set in shared memory - Wait till
        // all the shared memry test are over prior to check the end indication.
        usleep(5000);
        // wait for the FW to signal test end
        CL_WAIT_4_TEST_END_IND(100);
    }

    fail_module = CL_REG_READ(base_addr + TEST_FAIL_MODULE_ADDR);
    fail_addr = CL_REG_READ(base_addr + TEST_FAIL_ADDRESS_ADDR);

    if ( fail_module == TEST_SUCCESS )
    {
        TEST_INFO("\t\t\tSUCCESS\n");
    }
    else
    {
        TEST_INFO("\t\t\tFAIL in %s test at address: %Xh\n", a_fw_memory_test[fail_module], fail_addr);
    }

    // Display the multiple access time to memory in cycles
    TEST_INFO("\tMultiple memory access time (in cycles):\n");

    // PHY memory
    access_num = CL_REG_READ(base_addr + TEST_PHY_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_PHY_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access = CL_REG_READ(base_addr + TEST_PHY_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tPHY DMEM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }

    // PHY PMEM memory
    access_num = CL_REG_READ(base_addr + TEST_PHY_PMEM_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_PHY_PMEM_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access = CL_REG_READ(base_addr + TEST_PHY_PMEM_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tPHY PMEM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }

    // PHY XMEM memory
    access_num = CL_REG_READ(base_addr + TEST_PHY_XMEM_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_PHY_XMEM_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access = CL_REG_READ(base_addr + TEST_PHY_XMEM_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tPHY XMEM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }

    // Shared memory
    access_num = CL_REG_READ(base_addr + TEST_SHARED_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_SHARED_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access = CL_REG_READ(base_addr + TEST_SHARED_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tSHARED RAM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }

    // Direct Shared memory
    #if (CE_HW_VERSION == HW_8000_STEP_A0)
        access_num = CL_REG_READ(base_addr + TEST_DIRECT_SHARED_ACCESS_NUM_ADDR);
        if(access_num)
        {
            write_cycles_access = CL_REG_READ(base_addr + TEST_DIRECT_SHARED_WRITE_CYCLES_ADDR) / access_num;
            read_cycles_access = CL_REG_READ(base_addr + TEST_DIRECT_SHARED_READ_CYCLES_ADDR) / access_num;
            TEST_INFO("\t\tDIRECT SHARED RAM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
        }
    #endif // (CE_HW_VERSION == HW_8000_STEP_A0)

    // Local Iram memory
    access_num = CL_REG_READ(base_addr + TEST_LOCAL_IRAM_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_LOCAL_IRAM_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access = CL_REG_READ(base_addr + TEST_LOCAL_IRAM_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tLocal IRAM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }
    // Local Dram 1 memory
    access_num = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tLocal DRAM 1: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }
    #if (CE_HW_VERSION >= HW_8000_STEP_B0)
        // Local Dram 2 memory
        if (dram_type == DRAM_TYPE_2)
        {
            access_num = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_2_ACCESS_NUM_ADDR);
            if (access_num)
            {
                write_cycles_access = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_2_WRITE_CYCLES_ADDR) / access_num;
                read_cycles_access = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_2_READ_CYCLES_ADDR) / access_num;
                TEST_INFO("\t\tLocal DRAM 2: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
            }
        }
    #endif // CE_HW_VERSION >= HW_8000_STEP_B0

    // Remote Iram memory
    access_num = CL_REG_READ(base_addr + TEST_REMOTE_IRAM_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_REMOTE_IRAM_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access = CL_REG_READ(base_addr + TEST_REMOTE_IRAM_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tRemote IRAM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }
    // Remote Dram memory
    access_num = CL_REG_READ(base_addr + TEST_REMOTE_DRAM_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_REMOTE_DRAM_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access  = CL_REG_READ(base_addr + TEST_REMOTE_DRAM_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tRemote DRAM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }
    // Remote_1 Iram memory
    access_num = CL_REG_READ(base_addr + TEST_REMOTE_1_IRAM_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_REMOTE_1_IRAM_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access = CL_REG_READ(base_addr + TEST_REMOTE_1_IRAM_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tRemote_1 IRAM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }
    // Remote_1 Dram memory
    access_num = CL_REG_READ(base_addr + TEST_REMOTE_1_DRAM_ACCESS_NUM_ADDR);
    if(access_num)
    {
        write_cycles_access = CL_REG_READ(base_addr + TEST_REMOTE_1_DRAM_WRITE_CYCLES_ADDR) / access_num;
        read_cycles_access  = CL_REG_READ(base_addr + TEST_REMOTE_1_DRAM_READ_CYCLES_ADDR) / access_num;
        TEST_INFO("\t\tRemote_1 DRAM: Write: %d Read %d\n", write_cycles_access, read_cycles_access);
    }

   // Display the single access time to memory in cycles
    TEST_INFO("\tSingle memory access time (in cycles):\n");

    cycle_fetch_time = CL_REG_READ(base_addr + TEST_CYCLES_TIME_FATCH_ADDR);

    // Shared memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_SHARED_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_SHARED_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tSHARED RAM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    // Direct Shared memory
    #if (CE_HW_VERSION == HW_8000_STEP_A0)
        write_single_cycles = CL_REG_READ(base_addr + TEST_DIRECT_SHARED_WRITE_SINGLE_ADDR);
        read_single_cycles  = CL_REG_READ(base_addr + TEST_DIRECT_SHARED_READ_SINGLE_ADDR);
        if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
            TEST_INFO("\t\tDIRECT SHARED RAM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);
    #endif // (CE_HW_VERSION == HW_8000_STEP_A0)

    // PHY memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_PHY_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_PHY_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tPHY RAM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    // PHY PMEM memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_PHY_PMEM_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_PHY_PMEM_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tPHY PMEM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    // PHY XMEM memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_PHY_XMEM_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_PHY_XMEM_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tPHY XMEM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    // Local Iram memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_LOCAL_IRAM_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_LOCAL_IRAM_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tLocal IRAM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    // Local Dram 1 memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tLocal DRAM 1: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    #if (CE_HW_VERSION >= HW_8000_STEP_B0)
        if (base_addr == LMAC_COMM_BASE_ADDR || base_addr == SMAC_COMM_BASE_ADDR)
        {
            // Local Dram 2 memory
            write_single_cycles = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_2_WRITE_SINGLE_ADDR);
            read_single_cycles = CL_REG_READ(base_addr + TEST_LOCAL_DRAM_2_READ_SINGLE_ADDR);
            if ((write_single_cycles != 0) && (read_single_cycles != 0))
                TEST_INFO("\t\tLocal DRAM 2: Write: %d Read %d\n", write_single_cycles - cycle_fetch_time,
                          read_single_cycles - cycle_fetch_time);
        }
    #endif // CE_HW_VERSION >= HW_8000_STEP_B0


    // Remote Iram memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_REMOTE_IRAM_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_REMOTE_IRAM_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tRemote IRAM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    // Remote Dram memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_REMOTE_DRAM_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_REMOTE_DRAM_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tRemote DRAM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    // Remote_1 Iram memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_REMOTE_1_IRAM_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_REMOTE_1_IRAM_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tRemote_1 IRAM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);

    // Remote_1 Dram memory
    write_single_cycles = CL_REG_READ(base_addr + TEST_REMOTE_1_DRAM_WRITE_SINGLE_ADDR);
    read_single_cycles  = CL_REG_READ(base_addr + TEST_REMOTE_1_DRAM_READ_SINGLE_ADDR);
    if ( (write_single_cycles != 0) && (read_single_cycles != 0) )
        TEST_INFO("\t\tRemote_1 DRAM: Write: %d Read %d\n",write_single_cycles-cycle_fetch_time,read_single_cycles-cycle_fetch_time);
}

#define PRINT_STR_SIZE      9

#define TEST_CYCLE_COUNTER_ADDR    (TEST_END_INDICATION_ADDR + 0x00000010)
#define TEST_MICROS_COUNTER_ADDR    (TEST_END_INDICATION_ADDR + 0x00000014)
#define TEST_LOOP_COUNTER_ADDR     (TEST_END_INDICATION_ADDR + 0x00000018)

int apre_core_test(uint32_t base_addr)
{
    uint32_t reminder,print_size;
    char print_str[PRINT_STR_SIZE];
    uint32_t cnt=0;
    uint32_t cycle_cnt,micro_cnt;

    // wait for the FW to signal test end
    CL_WAIT_4_TEST_END_IND_RETURN(5);

    memset(print_str, 0, PRINT_STR_SIZE);

    cycle_cnt = CL_REG_READ(base_addr + TEST_CYCLE_COUNTER_ADDR);
    micro_cnt = CL_REG_READ(base_addr + TEST_MICROS_COUNTER_ADDR);

    sprintf(print_str, "%u.", (cycle_cnt/micro_cnt));
    reminder = (cycle_cnt%micro_cnt);

    for (print_size = strlen(print_str); print_size < (PRINT_STR_SIZE - 1); print_size++)
    {
        reminder *= 10;
        sprintf(&print_str[print_size], "%d",(reminder/micro_cnt));
        reminder = (reminder%micro_cnt);
    }

    TEST_INFO("\t\tProcessor speed: %s\n", print_str);
    TEST_INFO("\t\tvariable loop counter %d\n", CL_REG_READ(base_addr + TEST_LOOP_COUNTER_ADDR));

    return PASSED;
}

void apre_ipc_test(uint32_t base_addr)
{
#if 0
    uint32_t fail_module;
    uint32_t cnt=0;

    msleep (1000);

    CL_REG_WRITE(0xFFFFFFFF, IPC_APP2EMB_UNMASK_SET_ADDR);

    /* IPC test */
    // wait for the FW to signal test end
    CL_WAIT_4_TEST_END_IND(2);

    fail_module = CL_REG_READ(base_addr + TEST_FAIL_MODULE_ADDR);

    if (( fail_module == TEST_SUCCESS ) && cl_hw->stats.ipc_success )
    {
        TEST_INFO("\t\tSUCCESS host interrupts = : %d\n", cl_hw->stats.count_irq);
    }
    else
    {
        TEST_INFO("\t\tFAILED host interrupts = : %d\n", cl_hw->stats.count_irq);
    }
#endif
}

#define TEST_INDICATION_RIU_SINGLE_WR    (TEST_END_INDICATION_ADDR+0x00000008)
#define TEST_INDICATION_RIU_MULTIPLE_WR  (TEST_END_INDICATION_ADDR+0x0000000c)
#define TEST_INDICATION_MCCI_SINGLE_WR   (TEST_END_INDICATION_ADDR+0x00000010)
#define TEST_INDICATION_MCCI_MULTIPLE_WR (TEST_END_INDICATION_ADDR+0x00000014)
#define TEST_INDICATION_RIU_SINGLE_RD    (TEST_END_INDICATION_ADDR+0x00000018)
#define TEST_INDICATION_RIU_MULTIPLE_RD  (TEST_END_INDICATION_ADDR+0x0000001c)
#define TEST_INDICATION_MCCI_SINGLE_RD   (TEST_END_INDICATION_ADDR+0x00000020)
#define TEST_INDICATION_MCCI_MULTIPLE_RD (TEST_END_INDICATION_ADDR+0x00000024)
#define TEST_INDICATION_AGC_SINGLE_WR    (TEST_END_INDICATION_ADDR+0x00000028)

void apre_mcci_test(uint32_t base_addr)
{
    uint32_t fail_module;
    uint32_t cnt=0;

    usleep (1000);

    // wait for the FW to signal test end
    CL_WAIT_4_TEST_END_IND(10);

    fail_module = CL_REG_READ(base_addr + TEST_FAIL_MODULE_ADDR);

    if ( fail_module == TEST_SUCCESS )
    {
        TEST_INFO("\t\tSUCCESS\n");
        TEST_INFO("RIU_SINGLE_WR: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_RIU_SINGLE_WR));
        TEST_INFO("RIU_MULTIPLE_WR: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_RIU_MULTIPLE_WR));
        TEST_INFO("MCCI_SINGLE_WR: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_MCCI_SINGLE_WR));
        TEST_INFO("MCCI_MULTIPLE_WR: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_MCCI_MULTIPLE_WR));
        TEST_INFO("RIU_SINGLE_RD: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_RIU_SINGLE_RD));
        TEST_INFO("RIU_MULTIPLE_RD: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_RIU_MULTIPLE_RD));
        TEST_INFO("MCCI_SINGLE_RD: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_MCCI_SINGLE_RD));
        TEST_INFO("MCCI_MULTIPLE_RD: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_MCCI_MULTIPLE_RD));
        TEST_INFO("AGC_SINGLE_WR: %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_AGC_SINGLE_WR));

    }
    else
        TEST_INFO("\t\tFAILED\n");
}

#define TEST_INDICATION_CYCLE_16UNROLL          (TEST_END_INDICATION_ADDR+0x00000014)
#define TEST_INDICATION_CYCLE_REVERSE_16UNROLL  (TEST_END_INDICATION_ADDR+0x00000018)
#define TEST_INDICATION_CYCLE_16UNROLL_RMW      (TEST_END_INDICATION_ADDR+0x0000001c)
#define TEST_INDICATION_CYCLE_32UNROLL          (TEST_END_INDICATION_ADDR+0x00000020)
#define TEST_INDICATION_CYCLE_REVERSE_32UNROLL  (TEST_END_INDICATION_ADDR+0x00000024)
#define TEST_INDICATION_CYCLE_32UNROLL_RMW      (TEST_END_INDICATION_ADDR+0x00000028)

void apre_cycle_test(uint32_t base_addr)
{
    uint32_t fail_module;
    uint32_t cnt=0;

    usleep (1000);

    // wait for the FW to signal test end
    CL_WAIT_4_TEST_END_IND(10);

    fail_module = CL_REG_READ(base_addr + TEST_FAIL_MODULE_ADDR);

    if ( fail_module == TEST_SUCCESS )
    {
        TEST_INFO("\t\tSUCCESS\n");
        TEST_INFO("16_UNROLL: total %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_CYCLE_16UNROLL));
        TEST_INFO("16_UNROLL_REVERSE: total %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_CYCLE_REVERSE_16UNROLL));
        TEST_INFO("16_UNROLL_REVERSE_RMW: total %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_CYCLE_16UNROLL_RMW));
        TEST_INFO("32_UNROLL: total %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_CYCLE_32UNROLL));
        TEST_INFO("32_UNROLL_REVERSE: total %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_CYCLE_REVERSE_32UNROLL));
        TEST_INFO("32_UNROLL_REVERSE_RMW: total %d cycles.\n",CL_REG_READ(base_addr+TEST_INDICATION_CYCLE_32UNROLL_RMW));
    }
    else
        TEST_INFO("\t\tFAILED\n");
}

void apre_registers_test(uint32_t base_addr)
{
    uint32_t fail_module;
    uint32_t fail_addr;
    uint32_t cnt=0;

    // wait for the FW to signal test end
    CL_WAIT_4_TEST_END_IND(10);

    fail_module = CL_REG_READ(base_addr + TEST_FAIL_MODULE_ADDR);
    fail_addr = CL_REG_READ(base_addr + TEST_FAIL_ADDRESS_ADDR);

    if ( fail_module == TEST_SUCCESS )
    {
       TEST_INFO("\t\t\tSUCCESS\n");
    }
    else
    {
       TEST_INFO("\t\t\tFAIL at module %s register: %Xh\n", a_fw_regs_test_modules[fail_module], fail_addr);
    }
}

#define EDMA_ITTERATIONS_PERFORMED_ADDR    (EDMA_TEST_END_INDICATION_ADDR + 0x00000044)

void apre_edma_test(uint32_t base_addr)
{
#if 0
    uint32_t fail_module;
    uint32_t fail_addr;
    uint32_t cnt=0;
    uint32_t compare_res;

    // wait for the FW to signal test end
    CL_WAIT_4_EDMA_TEST_END_IND(100);

    fail_module = CL_REG_READ(base_addr + TEST_FAIL_MODULE_ADDR);
    fail_addr = CL_REG_READ(base_addr + TEST_FAIL_ADDRESS_ADDR);

    TEST_INFO("\t\ttest_end_ind_addr: %u, Test result: %u.\n", base_addr + EDMA_TEST_END_INDICATION_ADDR,
                        CL_REG_READ(base_addr + EDMA_TEST_END_INDICATION_ADDR));

    TEST_INFO("\t\tTest cycles performed: %u.\n",
                        CL_REG_READ(base_addr + EDMA_ITTERATIONS_PERFORMED_ADDR));

    /* registers test */
    if ( fail_module == TEST_SUCCESS )
    {
        TEST_INFO("\t\tSUCCESS\n");
    }
    else if(fail_module < (sizeof(a_fw_edma_test) / sizeof(a_fw_edma_test[0])))
    {
        TEST_INFO("\t\tFAIL in %s phase at address: 0x%X\n", a_fw_edma_test[fail_module], fail_addr);
    }
    else
    {
        TEST_INFO("\t\tFAILURE unknown fail_module - 0x%x\n", fail_module);
    }

    if (CL_REG_READ(base_addr + EDMA_TEST_END_INDICATION_ADDR) == 1)
    {
        compare_res = apre_edmatest_host_buffs_upstream_compare(cl_hw, (uint8_t*)virt_dma_mem, EDMA_MEM_SIZE);
        if (compare_res != 0)
        {
            CL_REG_WRITE(base_addr + EDMA_TEST_END_INDICATION_ADDR, 3);
        }
    }

    /* free alocated DMA memory block */
    TEST_INFO("Mac EDMA test host free Phys:0x%llX Virt:0x%p\n", (uint64_t)phys_dma_mem, virt_dma_mem);
    dma_free_coherent(cl_hw->dev, EDMA_MEM_SIZE, virt_dma_mem, phys_dma_mem);
#endif
}

#define CL_REG_WRITE_(addr, val) CL_REG_WRITE(val, addr)

static void cl_show_mem(uint32_t base_addr, uint32_t lines)
{
    uint32_t r[4];
    uint32_t i;

    for (i = 0; i < lines; i++)
    {
        r[0] = CL_REG_READ(base_addr + 0);
        r[1] = CL_REG_READ(base_addr + 4);
        r[2] = CL_REG_READ(base_addr + 8);
        r[3] = CL_REG_READ(base_addr + 12);
        printf("%4x: %08x %08x %08x %08x\n", base_addr, r[0], r[1], r[2], r[3]);
        base_addr += 0x10;
    }
}

/* Show memory with 20 bytes per line */
static void cl_show_mem24(uint32_t base_addr, uint32_t lines)
{
    uint32_t r[6];
    uint32_t i;

    for (i = 0; i < lines; i++)
    {
        r[0] = CL_REG_READ(base_addr + 0);
        r[1] = CL_REG_READ(base_addr + 4);
        r[2] = CL_REG_READ(base_addr + 8);
        r[3] = CL_REG_READ(base_addr + 12);
        r[4] = CL_REG_READ(base_addr + 16);
        r[5] = CL_REG_READ(base_addr + 20);
        printf("%4x: %08x %08x %08x %08x %08x %08x\n", base_addr,
            r[0], r[1], r[2], r[3], r[4], r[5]);
        base_addr += sizeof(r);
    }
}

void apre_udma_test(uint32_t test_control_address, uint32_t test_result_address)
{
    uint32_t old_seq_id = 0;
    uint32_t seq_id;
    uint32_t count = 0;
    uint32_t cmd;
    uint32_t state;
    uint32_t test_result = 1;

    while (1)
    {
        seq_id = CL_REG_READ(test_result_address + UDMA_TEST_STATUS_SEQUENCE_ID_OFS);

        if (seq_id == old_seq_id)
        {
            if (++count >= 100)
            {
                TEST_INFO("Timeout\n");
                break;
            }
            sleep(1);
            continue;
        }

        old_seq_id = seq_id;
        count = 0;

        cmd = CL_REG_READ(test_control_address + UDMA_TEST_CONTROL_CMD_OFS);
        if (cmd == 0)
        {
            TEST_INFO("Init passed\n");
            seq_id = CL_REG_READ(test_control_address +
                UDMA_TEST_CONTROL_SEQUENCE_ID_OFS);
            seq_id++;

            CL_REG_WRITE_(test_control_address + UDMA_TEST_CONTROL_CMD_OFS, 1);
            CL_REG_WRITE_(test_control_address +
                        UDMA_TEST_CONTROL_SEQUENCE_ID_OFS, seq_id);
            continue;
        }

        state = CL_REG_READ(test_result_address + UDMA_TEST_STATUS_STATE_OFS);
        if (state == 2)
        { /* Finished */
            TEST_INFO("Finished\n");
            test_result = CL_REG_READ(test_result_address +
                UDMA_TEST_STATUS_RESULT_OFS);
            if (test_result == 0)
            {
                TEST_INFO("\t\tSUCCESS\n");
            }
            else
            {
                TEST_INFO("\t\tFAILURE  0x%x\n", test_result);
            }
            break;
        }
    }

    if (test_result)
    {
        cl_show_mem(test_control_address, UDMA_TEST_CONTROL_SIZE / 16);
        cl_show_mem(test_result_address, UDMA_TEST_STATUS_SIZE / 16);
        cl_show_mem24(test_control_address + UDMA_LLI_DESC_START_OFS,
            UDMA_LLI_DESC_SIZE / 24);
    }
}

void apre_edma_tp_test(uint32_t base_addr)
{
#if 0
    uint32_t fail_module;
    uint32_t fail_addr;
    uint32_t cnt=0;

    // wait for the FW to signal test end
    CL_WAIT_4_TEST_END_IND(10);

    fail_module = CL_REG_READ(base_addr + TEST_FAIL_MODULE_ADDR);
    fail_addr = CL_REG_READ(base_addr + TEST_FAIL_ADDRESS_ADDR);

    TEST_INFO("\t\tTest cycles performed: %u.\n",
                        CL_REG_READ(base_addr + EDMA_ITTERATIONS_PERFORMED_ADDR));

    /* registers test */
    if ( fail_module == TEST_SUCCESS )
    {
        TEST_INFO("\t\tSUCCESS\n");
    }
    else
    {
        TEST_INFO("\t\tFAIL in %s phase at address: 0x%X\n", a_fw_edma_test[fail_module], fail_addr);
    }

    /* free alocated DMA memory block */
    TEST_INFO("Mac EDMA TP test host free Phys:0x%llX Virt:0x%p\n", (uint64_t)phys_dma_mem, virt_dma_mem);
    dma_free_coherent(cl_hw->dev, EDMA_MEM_SIZE, virt_dma_mem, phys_dma_mem);
#endif
}

/**
 * Handler for unknown test, similar to regtest:
 * Reads TEST_END_INDICATION_ADDR, TEST_FAIL_MODULE_ADDR, TEST_FAIL_ADDRESS_ADDR
 */
void apre_other_test(uint32_t base_addr)
{
    uint32_t v=0;
    uint32_t cnt=0;

    // wait for the FW to signal test end
    CL_WAIT_4_TEST_END_IND(10);

    v = CL_REG_READ(base_addr + TEST_FAIL_MODULE_ADDR);
    if ( TEST_SUCCESS == v ) {
        TEST_INFO("SUCCESS\n");
    } else {
        TEST_INFO("Fail module = %#X\n", v);
    }
    v = CL_REG_READ(base_addr + TEST_FAIL_ADDRESS_ADDR);
    TEST_INFO("Fail address = %#X\n", v);
}

