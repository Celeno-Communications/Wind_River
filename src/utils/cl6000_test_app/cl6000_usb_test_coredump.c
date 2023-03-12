/**
 ****************************************************************************************
 *
 * @file cl6000_usb_test_common.c
 *
 * @brief CL6000 UMAC test infrastructure.
 *
 * Copyright (C) emsys 2021
 *
 ****************************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <ctype.h>
#include <unistd.h>
#include <asm-generic/types.h>
#include "usbtpt.h"

#include "reg_logger_ram.h"
#include "cl6000_usb_test.h"
#include "regs.h"
#include "cl6000_common.h"
#include <sys/ioctl.h>
#include <fcntl.h>


int check_pattern(char* buffer,size_t size,char* app_marker)
{
    size_t marker_len=strlen(app_marker);
    for (size_t i = 0; i < size - marker_len-1; i++, buffer++ ){
      if (memcmp(buffer, app_marker, marker_len-1 ) == 0) {
        char timestamp[32] = {0};
        strncpy(timestamp, buffer, sizeof(timestamp)-1);
        printf("    found:    %s\n", timestamp);
        return 0;
      }
    }
    printf("    App-marker %s not found in coredump. Possible invalid coredump.\n",app_marker);
    return 1;
}

/* iwcl wlan0_0 cecli reg -s 0x40000000 0x18
  output:
---------------------------
|   Address  |   Value    |
|------------+------------|
| 0x40000000 | 0x80000001 |
| 0x40000004 | 0x80000002 |
| 0x40000008 | 0x80000003 |
| 0x4000000c | 0x80000004 |
| 0x40000010 | 0x80000005 |
| 0x40000014 | 0x80000006 |
---------------------------
*/
int iwcl_read_burst(uint32_t addr, void* buffer, size_t length) {
    char *line = NULL;
    size_t line_len = 0;
    ssize_t line_read;
    size_t num_lines = 0;
    char cmd[128];
    uint32_t* data_buffer = (uint32_t*)buffer;
    
    if (addr > REG_SHARED_RAM_BASE_ADDR) {
      addr -= REG_SHARED_RAM_BASE_ADDR;
    }
    snprintf(cmd, sizeof(cmd), "iwcl %s cecli reg -s 0x%08x 0x%08x 2>&1", boot_drv_usb_cfg()->umac_dump_driver_device_name, addr, (unsigned int)length);
#if 0
    printf("cmd: %s\n", cmd);
    (void)line;
    (void)line_len;
    (void)line_read;
    (void)num_lines;
    (void)data_buffer;
#else    
    FILE* output = popen(cmd, "r");
    while (output && (line_read = getline(&line, &line_len, output)) != -1) {
      if (strncmp("| 0x",line , 4)) {
        continue; // skip 1st 3 lines
      }
      if (!strncmp("----",line , 8)) {
        break; // end of stream reached
      }
      if (strnlen(line, 64) < 26) {
        fprintf(stderr, "ERROR %s: line too short: %s", __func__, line);
        continue;
      }
      uint32_t a = strtoul(&line[2], 0, 16);
      uint32_t d = strtoul(&line[15], 0, 16);
      if (errno) {
        fprintf(stderr, "ERROR %s: parse error: %s", __func__, line);
        continue;
      }
      if ((a >= (addr + length)) || (a < addr)) {
        fprintf(stderr, "ERROR %s: range error: %s", __func__, line);
        continue;
      }
      data_buffer[(a-addr) / 4] = d;
      //printf("addr=%x data=%x\n", a, d);
      num_lines++;
    }


    pclose(output);
    free(line);

    if(!num_lines) {
      fprintf(stderr, "ERROR %s: failed to execute: %s\n", __func__, cmd);
      exit(EXIT_FAILURE);
    }
#endif
    return 0;
}

int dump_read_burst(uint32_t addr, void* buffer, size_t length) {
  if (strlen(boot_drv_usb_cfg()->umac_dump_driver_device_name)) {
    uint8_t* current = buffer;
    uint8_t* end = current + length;
    int status = 0;
    while((status == 0) && (current < end)) {
      size_t next_chunk_size = (end - current) > CL6000_IWCL_MAX_BURST_SIZE ? CL6000_IWCL_MAX_BURST_SIZE : (end - current);
      status = iwcl_read_burst(addr, current, next_chunk_size);
      current += next_chunk_size;
      addr += next_chunk_size;
    }
    return status;
  } else {   
    return cl_usb_burst_read(addr, buffer, length, false);
  }
}

int save_app_dump() {
  uint32_t status = 0;
  uint32_t buffer[UMAC_DRAM_SIZE / sizeof(uint32_t)];
  uint32_t app_signature[CL6000_UMAC_CRASH_INFO_SIZE / 4] = {0};
  char* app_marker = "runtime-app";

  FILE *fp = fopen(CL6000_UMAC_APP_DUMP, "wt");
  if (!fp){
    printf("failed top open %s , ec: %d:\n", CL6000_UMAC_APP_DUMP, errno);
    printf("   %s\n",strerror(errno));
    return 1;
  }
  fprintf(fp,">%08X,Coredump\n", CL6000_LOCAL_UMAC_DRAM_BASE());

  status = dump_read_burst(CL6000_LOCAL_UMAC_DRAM_BASE(), buffer, sizeof(buffer));
  if (status ) {
    printf("Failed read coredump (addr=0x%08X, size=0x%08X).\n", CL6000_LOCAL_UMAC_DRAM_BASE(), (uint32_t)sizeof(buffer));
    fclose(fp);
    return 1;
  }
  for (size_t i = 0; i < sizeof(buffer) / sizeof(uint32_t); i++) {
    fprintf(fp, "%08X\n", buffer[i]);
  }
  fclose(fp);
  printf("    coredump 0x%08x saved to %s\n", CL6000_LOCAL_UMAC_DRAM_BASE(), CL6000_UMAC_APP_DUMP);
  /// check for pattern
  check_pattern((char*)buffer, sizeof(buffer), app_marker);

  printf("UMAC crash info:\n"); 
  dump_read_burst(CL6000_UMAC_CRASH_INFO, &app_signature, sizeof(app_signature));
  printf("    signature:       "); 
  if (app_signature[0] == 0x0) {
    printf("UMAC_INITIALIZED"); 
  } else if (app_signature[0] == 0x004E5552) {
    printf("UMAC_RUNNING"); 
  } else if (app_signature[0] == 0x00535243) {
    printf("UMAC_CRASHED"); 
  } else {
    printf("<UNKNOWN>"); 
  }
  printf(" 0x%08x\n", app_signature[0]); 
  printf("    assertion pc:    0x%08x\n", app_signature[1]); 
  printf("    exception cause: 0x%08x\n", app_signature[4]); 
  printf("    exception vaddr: 0x%08x\n", app_signature[5]); 
  printf("    exception ps:    0x%08x\n", app_signature[6]); 
  printf("    exception epc:   0x%08x\n", app_signature[7]); 

  return 0;
}

int save_bootrom_dump_impl(uint32_t ram_start_addr, uint32_t bl_ram_start_addr, const char* dump_file, const char* dump_source) {
  uint32_t status = 0;
  uint32_t buffer[CL6000_UMAC_BL_DUMP_SIZE / sizeof(uint32_t)];
  char app_marker[] = "bootloader-app";

  FILE *fp = fopen(dump_file, "wt");
  if (!fp){
    printf("failed top open %s , ec: %d:\n", dump_file, errno);
    printf("   %s\n",strerror(errno));
    return 1;
  }
  fprintf(fp, ">%08X, %s\n", bl_ram_start_addr, dump_source);

  status = dump_read_burst(ram_start_addr, buffer, sizeof(buffer));
  if (status ) {
    printf("Failed read coredump (addr=0x%08X, size=0x%08X).\n", ram_start_addr, (uint32_t)sizeof(buffer));
    fclose(fp);
    return 1;
  }
  for (size_t i = 0; i < sizeof(buffer) / sizeof(uint32_t); i++){
    fprintf(fp, "%08X\n", buffer[i]);
  }
  fclose(fp);
  printf("    Bootrom coredump 0x%08x saved to %s\n", ram_start_addr, dump_file);

  char* p= (char*)buffer;
  for (size_t i = 0; i < sizeof(buffer) - sizeof(app_marker)-1; i++, p++ ) {
    if (memcmp(p, app_marker, sizeof(app_marker)-1 ) == 0) {
      char timestamp[64] = {0};
      strncpy(timestamp, p, sizeof(timestamp));
      timestamp[sizeof(timestamp)-1] = '\0';
      printf("    found:    %s\n", timestamp);
      return 0;
    }
  }
  printf("    Bootrom application signature not found - expected \"%s\".\n", app_marker);
  return 0;
}

int save_bootrom_crash_dump() {
  uint32_t cd_addr = 0;
  uint32_t status = 0;

  status = dump_read_burst(CL6000_UMAC_POSTMORTEM_ADDR, &cd_addr, sizeof(cd_addr));
  if (status) {
    printf("coredump aborted: status %d\n",status);
    return 1;
  }
  if (cd_addr == 0) {
    cd_addr = CL6000_UMAC_BL_CRASH_DUMP_START;
    printf("    coredump: BFR Reg does not indicate coredump\n");
    printf("              Using 0x%08x as default.\n", cd_addr);
  }

  return save_bootrom_dump_impl(cd_addr, CL6000_UMAC_BL_DUMP_START, CL6000_UMAC_BL_CRASH_DUMP, "Bootrom-Crashdump");
}

int save_bootrom_dump() {
  return save_bootrom_dump_impl(CL6000_UMAC_BL_DUMP_START, CL6000_UMAC_BL_DUMP_START, CL6000_UMAC_BL_DUMP, "Bootrom-Coredump");
}

