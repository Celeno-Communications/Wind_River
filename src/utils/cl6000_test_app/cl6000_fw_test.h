/**
 ****************************************************************************************
 *
 * @file cl6000_fw_test.h
 *
 * @brief CL6000 FW test infrastructure.
 *
 * Copyright (C) Celeno 2013
 *
 ****************************************************************************************
 */

#ifndef CL6000_FW_TEST_H_
#define CL6000_FW_TEST_H_

#include "cl6000_common.h"

int usb_test_select_by_file(FILE* fp);

void pre_fw_test(char* lmac_fw_name,char* umac_fw_name,char* smac_fw_name, bool is_usb);
int apre_fw_test(char* lmac_fw_name,char* umac_fw_name,char* smac_fw_name, bool is_usb);
void apre_cycle_test(uint32_t base_addr);
void apre_mcci_test(uint32_t base_addr);
void apre_ipc_test(uint32_t base_addr);
void apre_interrupts_fw_test(uint32_t base_addr);
void apre_mem_fw_test(uint32_t base_addr, uint8_t dram_type, bool umac_host_if_usb);
int apre_core_test(uint32_t base_addr);
void apre_registers_test(uint32_t base_addr);
void apre_edma_test(uint32_t base_addr);
void apre_other_test(uint32_t base_addr);
void apre_edma_tp_test(uint32_t base_addr);
void apre_udma_test(uint32_t test_control_address, uint32_t test_result_address);
int apre_usb_cli_test();
int apre_usb_tp_test();
int apre_usb_wrapper_test(const char* lmac_fw_name, const char* smac_fw_name);
int apre_usb_wifi_reset_test(const char* lmac_fw_name);

#endif

