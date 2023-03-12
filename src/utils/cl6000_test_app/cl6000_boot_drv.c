/*
 * CL8000 Boot Driver
 */
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#include "cl6000_fw_test.h"
#include "cl6000_usb_test.h"
#include "cli_usb.h"
#include "platform.h"
#include "regs.h"
#include "libusb-1.0/libusb.h"


//----------------------------
// MACRO
//----------------------------

#define FATAL do { fprintf(stderr, "Error at line %d, file %s (%d) [%s]\n", \
  __LINE__, __FILE__, errno, strerror(errno)); exit(1); } while(0)

#define __FUNC_ENTRY__ if (boot_drv_usb_cfg()->verbose) { printf(">>> %s: Entry\n",__func__); }
#define __FUNC_EXIT__  if (boot_drv_usb_cfg()->verbose) { printf(">>> %s: Exit\n",__func__); }

#define __INIT_CHECK__(phase) \
{ \
    struct stat sb; \
    if( stat("/tmp/boot_"phase"_init",&sb) != -1 ) \
        return; \
}


#define STR_(x) #x
#define STR(x) STR_(x)

#define CL6000_BOOT_VERSION 17
#define CL6000_BOOT_VERSION_STR "cl6000_usb_boot_drv v." STR(CL6000_BOOT_VERSION)

static const char* cl6000_usb_boot_version_string = CL6000_BOOT_VERSION_STR;
static uint32_t cl6000_usb_boot_version = CL6000_BOOT_VERSION;

const char* const cl6000_usb_boot_drv_version() {
  (void)cl6000_usb_boot_version;
  return cl6000_usb_boot_version_string;
}

#define CL6000_LMAC_FW_NAME           "lmacfw.bin"
#define CL6000_SMAC_FW_NAME           "smacfw.bin"
#define CL6000_UMAC_FW_NAME           "umacfw.bin"


#define MACSYS_SMAC_CONTROL_ADDR                    (REG_MACSYS_GCU_BASE_ADDR + 0x0148)
#define MACSYS_SMAC_CONTROL_SMAC_BOOT_SOURCE_BIT    ((uint32_t)0x00000001)
#define MACSYS_SMAC_CONTROL_SMAC_BOOT_SOURCE_POS    1

//----------------------------
// Global Variable
//----------------------------
static int dry_load = 0;
static int no_start = 0;

int (*cl6000_boot_dbgprintf)(const char *fmt,...) = &printf;

#define dbgprintf cl6000_boot_dbgprintf

//
// Name: cl6000_load_bin()
// Description: Load the requested FW into specified memory
//
void cl6000_load_bin(ptrdiff_t mem_addr, size_t mem_size, const char *filename, size_t bin_offset)
{
    FILE *fp;
    size_t size, result;
    bool zero_copy = false;

    char fw_name[120];
    int err = 0;

    __FUNC_ENTRY__

    sprintf(fw_name,"%s/%s", boot_drv_usb_cfg()->fw_path, filename);

    dbgprintf("%s file=%s mem_addr=%zxh, mem_size=%zxh, bin_offset=%zxh).\n", __FUNCTION__, fw_name, mem_addr, mem_size, bin_offset);

    fp = fopen(fw_name,"r");
    if (fp == 0) {printf("\nERROR: can't find %s\n\n",fw_name); exit(1);}

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if ( size < bin_offset ) {
      printf("\nERROR: %s too small (size=%zxh, bin_offset=%zxh, mem_size=%zxh).\n\n", fw_name, size, bin_offset, mem_size);
      fclose(fp);
      exit(2);
    }

    fseek(fp, bin_offset, SEEK_SET);
    size -= bin_offset;

    size = (size < mem_size) ? size : mem_size;

    // read file into local mem buffer
    char *buf = malloc(size + 3);
    result = fread(buf, 1, size, fp);
    if ( result != size ) {
      printf("\nERROR: %s read less bytes than requested (size=%zxh, result=%zxh).\n\n", fw_name, size, result);
      err = 3;
    }

    fclose(fp);
    if (!err) {
        buf[size] = 0;
        size += 3;
        size &= ~3;
        dbgprintf("%s cli_usb_burst_write(addr=%zxh, buf, size=%zxh) ", __func__, mem_addr, size);
        if (size > 12) {
            uint32_t data;
            memcpy(&data, &buf[0], sizeof(data));
            dbgprintf("d32[0]=%08xh ", data);
            memcpy(&data, &buf[4], sizeof(data));
            dbgprintf("d32[1]=%08xh ", data);
            memcpy(&data, &buf[8], sizeof(data));
            dbgprintf("d32[2]=%08xh ", data);
        }
        dbgprintf("\n");
        err = cl_usb_burst_write(mem_addr, buf, size, zero_copy);

    }
    free(buf);
    if (err) {exit(err);}

    __FUNC_EXIT__

}

// Read and execute cli write operations from file
int cl6000_register_configuration_by_file(FILE* fp) {
  char line[256];
  while(fgets(line, sizeof(line), fp)) {
    char tail[256];
    uint32_t address;
    uint32_t data;
    int result;

    char* token = trimwhitespace(line);
    if ((!token) || (token[0] == 0) || (token[0] == '/') ||  (token[0] == '#')){
      continue;
    }

    result = sscanf(token, "%x%x%[^\n]", &address, &data, tail);
    if (result < 2) {
      TEST_INFO("ERROR reading %s\n", line);
      return 1;
    } else {
      TEST_INFO("%s: WR addr=0x%08X data=0x%08X %s\n", __FUNCTION__, address, data, tail);
      result = cl_usb_write32(address, data);
      if (result != 0) {
       TEST_INFO("Writing failed - aborted!\n");
       return 1;
      }
    }
  }
  return 0;
}

// Configure UMAC FW before start (write to virtual registers)
static void cl6000_configure_umac_fw() {
  if (strlen(boot_drv_usb_cfg()->umac_reg_cfg_file)) {
    FILE *fp = fopen(boot_drv_usb_cfg()->umac_reg_cfg_file, "rt");
    if (!fp) {
      printf("Failed to read %s \n %s\n", boot_drv_usb_cfg()->umac_reg_cfg_file, strerror(errno));
      exit(EXIT_FAILURE);
    }
    printf("Configure UMAC FW from %s\n", boot_drv_usb_cfg()->umac_reg_cfg_file);
    cl6000_register_configuration_by_file(fp);
    fclose(fp);
  }
}

//
// Name: cl6000_mac_fw_init()
// Description: put both lmac & smac in stall
//
void cl6000_mac_fw_init(uint8_t smac_boot_source_iram_init) {
  unsigned long regval;

  __FUNC_ENTRY__

  uint32_t smac_control = CL_REG_READ(MACSYS_SMAC_CONTROL_ADDR);
  dbgprintf("SMAC_CONTROL get @0x%08x => 0x%08X\n",__func__, MACSYS_SMAC_CONTROL_ADDR, smac_control);
  if (smac_boot_source_iram_init) {
    // set smac boot source to IRAM
    smac_control &= ~MACSYS_SMAC_CONTROL_SMAC_BOOT_SOURCE_BIT;
    CL_REG_WRITE(smac_control, MACSYS_SMAC_CONTROL_ADDR);
    dbgprintf("SMAC_CONTROL: set @0x%08x <= 0x%08X\n",__func__, MACSYS_SMAC_CONTROL_ADDR, smac_control);
    smac_control = CL_REG_READ(MACSYS_SMAC_CONTROL_ADDR);
  }

  // 1. return to reset value - 0x0A0A0A
  regval = macsys_gcu_xt_control_get(); // 0x607C50F0
  dbgprintf("0. XT_CTRL=0x%X.\n", regval);
  regval |= (MACSYS_GCU_XT_CONTROL_LMAC_OCD_HALT_ON_RESET_BIT|MACSYS_GCU_XT_CONTROL_SMAC_OCD_HALT_ON_RESET_BIT); // OCD=1
  regval &= ~(MACSYS_GCU_XT_CONTROL_LMAC_DRESET_N_BIT|MACSYS_GCU_XT_CONTROL_SMAC_DRESET_N_BIT|MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_BIT|MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_BIT|MACSYS_GCU_XT_CONTROL_LMAC_BRESET_N_BIT|MACSYS_GCU_XT_CONTROL_SMAC_BRESET_N_BIT); // RUN_STALL=0,BRESET=0,DRESET=0

  macsys_gcu_xt_control_set(regval); // 0x607C50F0

  regval = macsys_gcu_xt_control_get(); // 0x607C50F0
  dbgprintf("1. XT_CTRL=0x%X.\n", regval);

  macsys_gcu_xt_control_set(regval|MACSYS_GCU_XT_CONTROL_LMAC_DRESET_N_BIT|MACSYS_GCU_XT_CONTROL_SMAC_DRESET_N_BIT); // 0x607C50F0 // DRESET=1

  // 2. stall xtensa & release ocd - 0x060606
  regval = macsys_gcu_xt_control_get(); // 0x607C50F0

  dbgprintf("2. XT_CTRL=0x%X.\n", regval);

  regval |= (MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_BIT|MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_BIT);
  regval &= ~(MACSYS_GCU_XT_CONTROL_LMAC_OCD_HALT_ON_RESET_BIT|MACSYS_GCU_XT_CONTROL_SMAC_OCD_HALT_ON_RESET_BIT);

  macsys_gcu_xt_control_set(regval); // 0x607C50F0 // (OCD=0,RUN_STALL=1)

  // 3. breset release & debug enable - 0x272727
  regval = macsys_gcu_xt_control_get(); // 0x607C50F0

  dbgprintf("3. XT_CTRL=0x%X.\n", regval);

  regval |= (MACSYS_GCU_XT_CONTROL_LMAC_DEBUG_EN_BIT|MACSYS_GCU_XT_CONTROL_SMAC_DEBUG_EN_BIT|MACSYS_GCU_XT_CONTROL_LMAC_BRESET_N_BIT|MACSYS_GCU_XT_CONTROL_SMAC_BRESET_N_BIT);

  macsys_gcu_xt_control_set(regval); // 0x607C50F0 // (DEBUG_EN=1,BRESET=1)

  regval = macsys_gcu_xt_control_get(); // 0x607C50F0
  dbgprintf("3. XT_CTRL=0x%X.\n", regval);
  usleep(100);

  __FUNC_EXIT__
}

//
// Name: cl6000_load_lmac_fw()
// Description: Load/Run the LMAC FW into Xtensa embedded memory
//
void cl6000_load_lmac_fw()
{
    __FUNC_ENTRY__

    cl6000_mac_fw_init(0 /* dont set smac boot source */);

     // now load LMAC code + data
    cl6000_load_bin(CL6000_LMAC_DRAM_ADDR(), CL6000_LMAC_DRAM_SIZE(), CL6000_LMAC_FW_NAME, 0);
    cl6000_load_bin(CL6000_LMAC_IRAM_ADDR(), CL6000_LMAC_IRAM_SIZE(), CL6000_LMAC_FW_NAME, CL6000_LOCAL_LMAC_IRAM_OFFSET());
    // run lmac fw (RUN_STALL=0)
    macsys_gcu_xt_control_lmac_run_stall_setf(0); // 0x607C50F0
    printf("loaded and started %s to lmac.\n", CL6000_LMAC_FW_NAME);
}

//
// Name: cl6000_load_umac_fw()
// Description: Load/Run the UMAC FW into Xtensa embedded memory
//
void cl6000_load_umac_fw()
{
    __FUNC_ENTRY__

    if (!CL6000_UMAC_IS_BOOTROM_RUNNING(cl_usb_get_fw_version())) {
        printf("ERROR: UMAC FW can only be loaded from bootloader!\n");
        printf("Aborted!\n");
        exit(EXIT_FAILURE);
    }

    // now load UMAC code + data
    cl6000_load_bin(CL6000_LOCAL_UMAC_DRAM_BASE(), CL6000_UMAC_DRAM_SIZE(), CL6000_UMAC_FW_NAME, 0);
    cl6000_load_bin(CL6000_LOCAL_UMAC_IRAM_BASE(), CL6000_UMAC_IRAM_SIZE(), CL6000_UMAC_FW_NAME, CL6000_LOCAL_UMAC_IRAM_OFFSET());
    cl6000_configure_umac_fw();

    // run umac fw (RUN_STALL=0)
    if (!no_start) {
      cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, CL6000_LOCAL_UMAC_IRAM_BASE());
      printf("loaded and started %s to umac.\n", CL6000_UMAC_FW_NAME);
    }else{
      printf("loaded and _not_ started %s to umac.\n", CL6000_UMAC_FW_NAME);
    }
}

//
// Name: cl6000_load_smac_fw()
// Description: Load/Run the SMAC FW into Xtensa embedded memory
//
void cl6000_load_smac_fw()
{
    __FUNC_ENTRY__

    cl6000_mac_fw_init(1 /* set smac boot source to iram */);

     // now load SMAC code + data
    cl6000_load_bin(CL6000_SMAC_DRAM_ADDR(), CL6000_SMAC_DRAM_SIZE(), CL6000_SMAC_FW_NAME, 0);
    cl6000_load_bin(CL6000_SMAC_IRAM_ADDR(), CL6000_SMAC_IRAM_SIZE(), CL6000_SMAC_FW_NAME, CL6000_LOCAL_SMAC_IRAM_OFFSET());
    // run smac fw (RUN_STALL=0)
    macsys_gcu_xt_control_smac_run_stall_setf(0); // 0x607C50F0
    printf("loaded and started %s to smac.\n", CL6000_SMAC_FW_NAME);
}

int cl6000_umac_cli_selftest();

//
// Name: cl6000_load_test_fw()
// Description: Load test FW into Xtensa embedded memory
//
int cl6000_load_test_fw(char* lmac_fw_name,char* umac_fw_name,char* smac_fw_name)
{
    int result = FAILED;
    int run_stall_bits=0;
    unsigned long regval;

    if (!strcmp(lmac_fw_name,"no_load") && !strcmp(umac_fw_name,"usbbootromclitestfw.bin") && !strcmp(smac_fw_name,"no_load")) {
      return cl6000_umac_cli_selftest();
    }

    __FUNC_ENTRY__

    printf("run %s on lmac, %s on umac & %s on smac.\n",lmac_fw_name,umac_fw_name,smac_fw_name);


    if (!dry_load) {
      cl6000_mac_fw_init(1 /* set smac boot source to iram*/);

      //--------------------------------
      // Download lmac/smac/umac code & data
      //--------------------------------
      if (strcmp(lmac_fw_name,"no_load"))
      {
        // load LMAC code + data
          cl6000_load_bin(CL6000_LMAC_DRAM_ADDR(), CL6000_LMAC_DRAM_SIZE(), lmac_fw_name, 0);
          cl6000_load_bin(CL6000_LMAC_IRAM_ADDR(), CL6000_LMAC_IRAM_SIZE(), lmac_fw_name, CL6000_LOCAL_LMAC_IRAM_OFFSET());
          run_stall_bits |= MACSYS_GCU_XT_CONTROL_LMAC_RUN_STALL_BIT;
          printf("!!!!! LMAC loaded\n");
      }

      if (strcmp(umac_fw_name,"no_load"))
      {
          if (!CL6000_UMAC_IS_BOOTROM_RUNNING(cl_usb_get_fw_version())) {
              printf("ERROR: UMAC Test-FW can only be loaded from bootloader!\n");
              printf("Aborted!\n");
              exit(EXIT_FAILURE);
          }
          // load UMAC code + data
          cl6000_load_bin(CL6000_LOCAL_UMAC_DRAM_BASE(), CL6000_UMAC_DRAM_SIZE(), umac_fw_name, 0);
          cl6000_load_bin(CL6000_LOCAL_UMAC_IRAM_BASE(), CL6000_UMAC_IRAM_SIZE(), umac_fw_name, CL6000_LOCAL_UMAC_IRAM_OFFSET());
      }

      if (strcmp(smac_fw_name,"no_load"))
      {
          // load SMAC code + data
          cl6000_load_bin(CL6000_SMAC_DRAM_ADDR(), CL6000_SMAC_DRAM_SIZE(), smac_fw_name, 0);
          cl6000_load_bin(CL6000_SMAC_IRAM_ADDR(), CL6000_SMAC_IRAM_SIZE(), smac_fw_name, CL6000_LOCAL_SMAC_IRAM_OFFSET());
          run_stall_bits |= MACSYS_GCU_XT_CONTROL_SMAC_RUN_STALL_BIT;
          printf("!!!!! SMAC loaded\n");
      }
    } else {
      printf("Dry-Load: don't download\n");
    }

    if (strcmp(umac_fw_name,"no_load"))
    {
        cl6000_configure_umac_fw();
    }

    //--------------------------------------------------
    // configure pre-test registers for lmac/umac/smac
    //--------------------------------------------------
    pre_fw_test(lmac_fw_name, umac_fw_name, smac_fw_name, true /* is_usb */);

    if(no_start){
      printf("no execute of downloaded firmware\n");
      return result;
    }

    if (!dry_load) {
      //-------------------------
      // run lmac/umac/smac code
      //-------------------------
      regval = macsys_gcu_xt_control_get(); // 0x607C50F0

      dbgprintf("Get XT_CTRL=0x%X.\n", regval);

      regval &= ~(run_stall_bits);

      dbgprintf("Set XT_CTRL=0x%X.\n", regval);

      // run lmac/umac/smac fw (RUN_STALL=0)
      macsys_gcu_xt_control_set(regval); // 0x607C50F0
    } else  {
      printf("Dry-Load: don't set XT_CTRL\n");
    }

    //-----------------------
    // get apre test results
    //-----------------------
    result = apre_fw_test(lmac_fw_name, umac_fw_name, smac_fw_name, true /* is_usb */);

    __FUNC_EXIT__

    return result;
}

void cli_usb_set_test_pattern(void* data, size_t size)
{
  for (uint32_t i = 0; i < (size / 4); i++) {
    uint32_t* ptr = (uint32_t*)data + i;
    *ptr = i;
  }
}

int cli_usb_test_burst_write_read_burst(const char* description, uint32_t base_address, uint32_t size, bool zero_copy)
{
  int result = 0;
  char report[128];

  snprintf(report, sizeof(report), "%s::%s(0x%08x, 0x%04x)", description, __FUNCTION__, base_address, size);

  uint8_t* tx_data = malloc(size);
  uint8_t* rx_data = malloc(size);

  cli_usb_set_test_pattern(tx_data, size);
  memset(rx_data, 0xEE, size);

  cl_usb_burst_write(base_address, tx_data, size, zero_copy);
  cl_usb_burst_read(base_address, rx_data, size, zero_copy);

  if (memcmp(tx_data, rx_data, size) == 0) {
    printf("PASS: %s\n", report);
    result = 0;
  } else {
    printf("FAIL: %s\n", report);
    result = 1;
  }


  free(tx_data);
  free(rx_data);

  return result;

}

uint64_t clock_gettime_ms () {
  struct timespec ts;
  if (clock_gettime (CLOCK_MONOTONIC, &ts) == 0) {
    return (uint64_t) (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
  } else {
    return 0;
  }
}

#define SIGNATURE_0 0x6C65632A
#define SIGNATURE_1 0x2A6F6E65
#define HIGHLIGHT(s) "\033[1;33m" s "\033[0m"
int cl6000_umac_bootrom_startup_delay_test(uint32_t initial_startup_delay_ms) {
  CLI_USB_Config test_config, *tmp;
  uint32_t empty_buffer[3] = {0};
  uint32_t signature[3] = {SIGNATURE_0, SIGNATURE_1, 0x0};
  uint64_t last_timestamp;
  uint32_t startup_delay_ms = initial_startup_delay_ms;
  uint32_t initial_restart_timeout;

  printf("Executing %s pid=0x%04x ...\n\n", __FUNCTION__, cl_usb_get_pid());
  tmp = cl_get_usb_config();
  memcpy(&test_config, tmp, sizeof(test_config));
  initial_restart_timeout = test_config.connection_timeout_ms;

  cl_usb_write32(CL6000_UMAC_POSTMORTEM_ADDR, 0);
  test_config.silent = 1;
  test_config.connection_timeout_ms = initial_restart_timeout;
  printf("    Cleanup config section 0x4002FFF4-0x4002FFFF ...\n");
  printf("    Restart bootrom, expect " HIGHLIGHT("immediate") " re-enumeration ... max %dms\n", test_config.connection_timeout_ms);
  cl_usb_burst_write(0x4002FFF4, empty_buffer, sizeof(empty_buffer), 0);
  cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, 0x50000000);
  cl_usb_close();
  last_timestamp = clock_gettime_ms();
  if (cl_usb_open_pretty_print(&test_config) < 0) {
    printf("    Failed to enumerate bootrom.");
    return 1;
  }
  printf("    Re-enumeration duration " HIGHLIGHT("td1=%.3fs") "\n\n",  (clock_gettime_ms() - last_timestamp)/1000.0);


  test_config.connection_timeout_ms = test_config.connection_timeout_ms * 2;
  printf("    Set signature=" HIGHLIGHT("\"%s\"") ", startup_delay=" HIGHLIGHT("%dms") "\n", (char*)(&signature[0]), startup_delay_ms);
  printf("    Restart bootrom, expect delayed re-enumeration ... max %dms\n", test_config.connection_timeout_ms);
  cl_usb_write32(0x4002FFF4, startup_delay_ms * 1000);
  cl_usb_write32(0x4002FFF8, signature[0]);
  cl_usb_write32(0x4002FFFC, signature[1]);
  cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, 0x50000000);
  cl_usb_close();
  last_timestamp = clock_gettime_ms();
  if (cl_usb_open_pretty_print(&test_config) < 0) {
    printf("    Failed to enumerate bootrom.");
    return 1;
  }
  printf("    Re-enumeration duration " HIGHLIGHT("td2=%.3fs") "\n\n",  (clock_gettime_ms() - last_timestamp)/1000.0);

  startup_delay_ms = startup_delay_ms * 2;
  test_config.connection_timeout_ms = test_config.connection_timeout_ms * 2;

  printf("    Set startup_delay=" HIGHLIGHT("%ums") "\n", startup_delay_ms);
  printf("    Restart bootrom, expect double*2-delayed re-enumeration ...\n");
  cl_usb_write32(0x4002FFF4, startup_delay_ms * 1000);
  cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, 0x50000000);
  cl_usb_close();
  last_timestamp = clock_gettime_ms();
  if (cl_usb_open_pretty_print(&test_config) < 0) {
    printf("    Failed to enumerate bootrom.");
    return 1;
  }
  printf("    Re-enumeration duration " HIGHLIGHT("td3=%.3fs") "\n\n",  (clock_gettime_ms() - last_timestamp)/1000.0);

  startup_delay_ms = startup_delay_ms * 2;
  test_config.connection_timeout_ms = test_config.connection_timeout_ms * 2;

  printf("    Set startup_delay=" HIGHLIGHT("%ums") "\n", startup_delay_ms);
  printf("    Restart bootrom,expect double*4-delayed re-enumeration...\n");
  cl_usb_write32(0x4002FFF4, startup_delay_ms * 1000);
  cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, 0x50000000);
  cl_usb_close();
  last_timestamp = clock_gettime_ms();
  if (cl_usb_open_pretty_print(&test_config) < 0) {
    printf("    Failed to enumerate bootrom.");
    return 1;
  }
  printf("    Re-enumeration duration " HIGHLIGHT("td4=%.3fs") "\n\n",  (clock_gettime_ms() - last_timestamp)/1000.0);

  signature[0] = signature[0] + 0x00100000;
  test_config.connection_timeout_ms = initial_restart_timeout;
  printf("    Invalidate signature=" HIGHLIGHT("\"%s\"") ", startup_delay=%dms\n", (char*)(&signature[0]), startup_delay_ms);
  printf("    Restart bootrom, expect " HIGHLIGHT("immediate") " re-enumeration...\n");
  cl_usb_write32(0x4002FFF8, signature[0]);
  cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, 0x50000000);
  cl_usb_close();
  last_timestamp = clock_gettime_ms();
  if (cl_usb_open_pretty_print(&test_config) < 0) {
    printf("    Failed to enumerate bootrom.");
    return 1;
  }
  signature[0] = SIGNATURE_0;
  printf("    Re-enumeration duration " HIGHLIGHT("td5=%.3fs") "\n\n",  (clock_gettime_ms() - last_timestamp)/1000.0);

  startup_delay_ms = 200; // fixed to be able to distinguish between bootrom exception start delay
  test_config.connection_timeout_ms = initial_restart_timeout * 2;

  printf("    Set signature=" HIGHLIGHT("\"%s\"") ", startup_delay=" HIGHLIGHT("%dms") "\n", (char*)(&signature[0]), startup_delay_ms);
  printf("    Restart bootrom, expect delayed re-enumeration ... max %dms\n", test_config.connection_timeout_ms);
  cl_usb_write32(0x4002FFF4, startup_delay_ms * 1000);
  cl_usb_write32(0x4002FFF8, signature[0]);
  cl_usb_write32(0x4002FFFC, signature[1]);
  cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, 0x50000000);
  cl_usb_close();
  last_timestamp = clock_gettime_ms();
  if (cl_usb_open_pretty_print(&test_config) < 0) {
    printf("    Failed to enumerate bootrom.");
    return 1;
  }
  printf("    Re-enumeration duration " HIGHLIGHT("td6=%.3fs") "\n\n",  (clock_gettime_ms() - last_timestamp)/1000.0);

  cl_usb_write32(CL6000_UMAC_POSTMORTEM_ADDR, 0x0000FFFF);
  test_config.connection_timeout_ms = 10 * initial_restart_timeout;
  printf("    Check that bootrom exception delay have precedence.\n");
  printf("    Restart bootrom, expect delayed re-enumeration with " HIGHLIGHT("Bootrom exception delay") " ... max %dms\n", test_config.connection_timeout_ms);
  cl_usb_umac_restart(boot_drv_usb_cfg()->umac_disconnect_delay_ms, boot_drv_usb_cfg()->umac_restart_delay_ms, 0x50000000);
  cl_usb_close();
  last_timestamp = clock_gettime_ms();
  if (cl_usb_open_pretty_print(&test_config) < 0) {
    printf("    Failed to enumerate bootrom.");
    return 1;
  }
  printf("    Re-enumeration duration " HIGHLIGHT("td7=%.3fs") "\n\n",  (clock_gettime_ms() - last_timestamp)/1000.0);
  cl_usb_write32(CL6000_UMAC_POSTMORTEM_ADDR, 0x0);

  if (cl_usb_last_error() < 0)  {
    printf("    Failed");
    return 1;
  }
  printf("    To be checked by the user!! - (all values appr., differences significantly):\n");
  printf("        td2 > td1\n");
  printf("        td3 > td2\n");
  printf("        td4 > td3\n");
  printf("        td5 == td1\n");
  printf("        td6 == td2\n");
  printf("        td7 > td4\n");
  return 0;
}

int cl6000_umac_cli_selftest() {
  int result = 1;

  uint32_t memory_128k_address = CL6000_LOCAL_UMAC_IRAM_BASE();

  printf("Executing %s pid=0x%04x ", __FUNCTION__, cl_usb_get_pid());
  printf("bcdDevice: %x.%02x ...\n", (cl_usb_get_fw_version() & 0xFF00) >> 8, cl_usb_get_fw_version() & 0xFF);

  if (!CL6000_UMAC_IS_BOOTROM_RUNNING(cl_usb_get_fw_version())) {
    fprintf(stderr, "ERROR: %s can only run from bootloader!\n", __FUNCTION__);
    return FAILED;
  }

  cl_usb_close();

  // to show fw version
  cl_usb_open_pretty_print(cl_get_usb_config());
  cl_usb_close();

  result = cl_usb_self_test(memory_128k_address, cl_get_usb_config());
  if (result == 0) {
    cl_usb_open_pretty_print(cl_get_usb_config());
    result |= cli_usb_test_burst_write_read_burst("UMAC_DRAM_full_test unbuffered", CL6000_LOCAL_UMAC_DRAM_BASE(), CL6000_UMAC_DRAM_SIZE(), true);
    result |= cli_usb_test_burst_write_read_burst("UMAC_IRAM_full_test unbuffered", CL6000_LOCAL_UMAC_IRAM_BASE(), CL6000_UMAC_IRAM_SIZE(), true);
    result |= cli_usb_test_burst_write_read_burst("UMAC_DRAM_full_test buffered", CL6000_LOCAL_UMAC_DRAM_BASE(), CL6000_UMAC_DRAM_SIZE(), false);
    result |= cli_usb_test_burst_write_read_burst("UMAC_IRAM_full_test buffered", CL6000_LOCAL_UMAC_IRAM_BASE(), CL6000_UMAC_IRAM_SIZE(), false);

    result |= cl6000_umac_ep0_stall_test();
  }
  return result;
}

int cl6000_umac_logger_get_hierarchy(void) {
  char logger_info[256];
  uint32_t index;
  int result;

  index = 0;
  printf("%s:\n", __FUNCTION__);
  for (;; ++index) {
    result = cl_usb_logger_get_info(index, logger_info, sizeof(logger_info));
    if ((result == 0) && strnlen(logger_info, sizeof(logger_info))) {
      printf("    logger[%2u] - %s\n", index, logger_info);
    } else {
      break;
    }
  }

  return 0;
}

int cl6000_umac_logger_get_level(uint32_t index) {
  int result;
  uint32_t level;
  char level_name[64];

  result = cl_usb_logger_get_level(index, &level);
  if (result == 0) {
    result =
        cl_usb_logger_level_as_string(level, level_name, sizeof(level_name));
    if (result == 0) {
      printf("%s logger[%u] - Level %u (%s)\n", __FUNCTION__, index, level,
             level_name);
    } else {
      printf("%s unknown log level: %d for logger[%u]\n", __FUNCTION__, index,
             level);
    }
  } else {
    printf("%s failed for index %u\n", __FUNCTION__, index);
  }

  return 0;
}

int cl6000_umac_logger_set_level(uint32_t index, const char *level_string) {
  int result;
  uint32_t level;

  result = cl_usb_logger_level_as_int(level_string, &level);
  if (result != 0) {
    printf("%s aborted: unknown level: %s\n", __FUNCTION__, level_string);
    return 1;
  }
  printf("%s logger[%u] - Level %s (%u)\n", __FUNCTION__, index, level_string,
         level);

  result = cl_usb_logger_set_level(index, level);
  if (result != 0) {
    printf("%s to %u failed for index %u\n", __FUNCTION__, level, index);
  }

  return 0;
}

int cl6000_usb_version() {
  cl_usb_close();
  cl_usb_open_pretty_print(cl_get_usb_config());
  return 0;
}

int cl6000_usb_read32(uint32_t addr) {
  uint32_t result = 0;
  int error = cl_usb_read32(addr, &result);
  if (error) {
    printf("Failed %s(0x%08x).\n", __FUNCTION__, addr);
    return 1;
  }
  dbgprintf("%s(0x%08x): 0x%08x done.\n", __FUNCTION__, addr, result);
  printf("%08X\n", result);
  return 0;
}

int cl6000_usb_write32(uint32_t addr, uint32_t data) {
  int error = cl_usb_write32(addr, data);
  if (error) {
    printf("Failed %s(addr=0x%08x, data=0x%08x).\n", __FUNCTION__, addr, data);
    return 1;
  }
  printf("%s(addr=0x%08x, data=0x%08x) done.\n", __FUNCTION__, addr, data);
  return 0;
}

int cl6000_usb_read32_burst(uint32_t addr, uint32_t size) {
  bool zero_copy = true;
  uint8_t* buffer = (uint8_t*)malloc(size);
  if (!buffer) {
    printf("%s(addr=0x%08x, size=0x%08x) - out of memory.\n", __FUNCTION__, addr, size);
    return 1;
  }

  int error = cl_usb_burst_read(addr, buffer, size, zero_copy);
  if (error) {
    printf("Failed %s(addr=0x%08x, size=0x%08x).\n", __FUNCTION__, addr, size);
    return 1;
  }
  printf("%s(addr=0x%08x , size=0x%08x) ...\n", __FUNCTION__, addr, size);
  for(size_t i = 0; i < size/4; i++) {
    uint32_t data = 0;
    uint32_t offset = i * 4;
    memcpy(&data, &buffer[offset], 4);
    printf("0x%08x (0x%08x + 0x%04x) : 0x%08x\n", addr + offset, addr, offset, data);
  }
  printf("%s(addr=0x%08x , size=0x%08x) done.\n", __FUNCTION__, addr, size);
  return 0;
}

// scan for available celeno usb devices, return number of found devices
size_t usb_scan() {
  libusb_context*  context = NULL;
  libusb_device** all_devices;
  size_t valid_devices = 0;
  char dev_sn[256];


  memset(dev_sn, 0, sizeof(dev_sn));
  libusb_init(&context);
  ssize_t num_devices = libusb_get_device_list(context, &all_devices);

  fprintf(stderr, "Scanning for usb devices VID=0x%04x ...\n", CL6000_UMAC_VID);
  for (ssize_t i = 0; i < num_devices; ++i) {
    struct libusb_device_descriptor desc;
    int                             status = libusb_get_device_descriptor(all_devices[i], &desc);
    if (status) {
      continue;
    }

    if (desc.idVendor == CL6000_UMAC_VID) {
      libusb_device_handle* dev_handle;
      valid_devices++;

      if (desc.iSerialNumber) {
        libusb_open(all_devices[i], &dev_handle);
        if (dev_handle) {
          libusb_get_string_descriptor_ascii(dev_handle, desc.iSerialNumber, (unsigned char*)dev_sn, sizeof(dev_sn));
          libusb_close(dev_handle);
        }
      } else {
        strncpy(dev_sn, "<empty>", sizeof(dev_sn));
      }

      fprintf(stderr, "    VID/PID/SN 0x%04x 0x%04x %s\n", desc.idVendor, desc.idProduct, dev_sn);
    }
  }
  libusb_free_device_list(all_devices, 1);

  libusb_exit(context);
  return valid_devices;
}

int analyze_dump(const char* dump_file, const char* elf_file, bool is_bootrom) {
  char cmd[256];
  snprintf(cmd, sizeof(cmd), "analyze_umac_dram.py --dram-file=%s --elf-file=%s %s", dump_file, elf_file, is_bootrom ? "--log-mode=STD" : "");
  int result = system(cmd);
  if (result) {
    printf("ERROR: executing command: \"%s\"\n", cmd);
  }
  return result;
}

const char* parse_umac_analyze_options(int argc, char **argv, int optind) {
  static char elf_file[256];

  memset(elf_file, 0, sizeof(elf_file));

  if (argc > (optind + 1)) {
    strncpy(elf_file, argv[optind + 1], sizeof(elf_file)-1);
  } else {
    printf("missing elf-file. usage: %s umac_analyze_* <elf-file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  return elf_file;
}

int cl6000_usb_umac_restart(uint32_t disconnect_delay_ms, uint32_t restart_delay_ms, uint32_t addr) {
  uint32_t result = 0;
  int error = cl_usb_umac_restart(disconnect_delay_ms, restart_delay_ms, addr);
  if (error) {
    printf("Failed %s(0x%08x).\n", __FUNCTION__, addr);
    return 1;
  }
  dbgprintf("%s(0x%08x): 0x%08x done.\n", __FUNCTION__, addr, result);
  return 0;
}


void usage_usb_options()
{
  fprintf(stderr, 
    "\t\t -r [filename] - read umac firmware configuration from file, applicable for load_test/load_umac operation\n"
    "\t\t    format: multiple lines with <address> <value>, comments starts with \'#\'\n"
    "\t options only for command load_test usb*.bin:\n"
    "\t\t -c [id] - select dedicated usb/umac testcase\n"
    "\t\t -f [filename] - select dedicated usb/umac testcases from file\n"
    "\t\t -i ignore performance errors, reduce to warning\n"
    "\t\t -y [device] - use iwcl <device> read for coredumps (not libusb). Applies to umac_save|analyze_*_dump operations\n"
  );
}

void usage_usb_commands()
{
  fprintf(stderr, 
    "\t USB/UMAC only commands:\n"
    "\t\t umac_save_bootrom_dump: save bootrom coredump.\n"
    "\t\t umac_save_bootrom_crash_dump: save bootrom coredump from side buffer.\n"
    "\t\t umac_save_app_dump: save umac application coredump. \n"
    "\t\t umac_analyze_bootrom_dump <elffile>: download bootrom coredump and decode memory logs using analyze_umac_dram.py\n"
    "\t\t                                      with given elf-file.\n"
    "\t\t umac_analyze_bootrom_crash_dump <elffile>: download bootrom crashdump from sidebuffer and decode memory logs \n"
    "\t\t                                            using analyze_umac_dram.py with given elf-file.\n"
    "\t\t umac_analyze_app_dump <elffile>: download app coredump and decode memory logs using analyze_umac_dram.py\n"
    "\t\t                                          with given elf-file.\n"
    "\t\t usb_scan : scan usb for celeno usb devices (based on VID=0x33de). Exit code: 0 if devices are found, otherwise 1\n"
    "\t\t cli_usb_version: show full/detailed version information of cli interface.\n"
    "\t\t cli_usb_read32 <addr>: execute cli usb read32 operation with given address 32 bit aligned.\n"
    "\t\t cli_usb_write32 <addr> <data>: execute cli usb write32 operation with given address/data, both 32bit aligned.\n"
    "\t\t cli_usb_read32_burst <addr> <size>: execute cli usb read32 burst operation with given address and length,\n"
    "\t\t                                     both 32bit aligned.\n"
    "\t\t umac_logger_get_hierarchy: retrieve information on all available UMAC SW logger instances.\n"
    "\t\t umac_logger_get_level <index>: get the logging level (verbosity) of the logger identified by index.\n"
    "\t\t umac_logger_set_level <index> <level_as_string>: set the logging level (verbosity) for the logger identified by index.\n"
    "\t\t umac_bootrom_cli_test: execute umac bootrom cli protocol-test.\n"
    "\t\t                                UMAC IRAM is used as test area for memory read/write(+burst) operations.\n"
    "\t\t umac_bootrom_exception_test: execute umac bootrom exception-test.\n"
    "\t\t umac_bootrom_startup_delay_test: execute umac bootrom startup delay test.\n"
    "\t\t                                  This test restarts the bootrom with several startup delay configurations, also valid, invalid signatures.\n"
    "\t\t                                  This is no automatic test - test result has to be verified manually.\n"
    "\t\t umac_enable_wd <enable> <timeout_ms>: Enable or disable WD with given timeout in ms.\n"
    "\t\t umac_statistic_show [lli]: query umac wifi statistic for lli channel U0..U31,D0..D31.\n"
    "\t\t umac_statistic_config: [enable-cnt][enable-perf] : configure umac wifi statistic\n"
    "\t\t umac_statistic_reset: reset umac wifi statistic\n"
    "\t\t umac_config_show: print umac configuration\n"
    "\t\t umac_ecm_data_test: execute ecm sync loop test (requires cdc-ecm loop capable binary already running on UMAC)\n"
    "\t\t umac_ecm_udp_data_test: execute udp send/receive test (requires udp test service capable binary already running on UMAC)\n"
    "\t\t                         ecm network interface must be configured as ip on address 10.10.10.100\n"
    "\t\t umac_restart <addr> <restart_delay_ms> <disconnect_delay_ms>: Restart UMAC with given address and specified delay parameters.\n"
  );
}
