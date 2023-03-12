/**
 ****************************************************************************************
 *
 * @file cl6000_boot_drv.h
 *
 * @brief CL6000 boot drv infrastructure.
 *
 * Copyright (C) Emsys/Celeno 2021
 *
 ****************************************************************************************
 */

#ifndef CL6000_BOOT_DRV_H
#define CL6000_BOOT_DRV_H

#include <stdint.h>

const char* const cl6000_usb_boot_drv_version();
int cl6000_umac_cli_selftest();
int cl6000_umac_bootrom_startup_delay_test(uint32_t initial_startup_delay_ms);
int cl6000_umac_logger_get_hierarchy(void);
int cl6000_umac_logger_get_level(uint32_t index);int cl6000_umac_logger_set_level(uint32_t index, const char *level_string);
int cl6000_usb_version();
int cl6000_usb_read32(uint32_t addr);
int cl6000_usb_write32(uint32_t addr, uint32_t data);
int cl6000_usb_read32_burst(uint32_t addr, uint32_t size);
int cl6000_load_test_fw(char* lmac_fw_name,char* umac_fw_name,char* smac_fw_name);
int cl6000_usb_umac_restart(uint32_t disconnect_delay_ms, uint32_t restart_delay_ms, uint32_t addr);
void cl6000_load_lmac_fw();
void cl6000_load_smac_fw();
void cl6000_load_umac_fw();

size_t usb_scan();
int analyze_dump(const char* dump_file, const char* elf_file, bool is_bootrom);
const char* parse_umac_analyze_options(int argc, char **argv, int optind);
void usage_usb_commands();
void usage_usb_options();

#endif // CL6000_BOOT_DRV_H
