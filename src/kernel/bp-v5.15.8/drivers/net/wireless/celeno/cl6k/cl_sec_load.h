// SPDX-License-Identifier: GPL-2.0 OR BSD-2-Clause
/* Copyright(c) 2019-2021, Celeno Corporation. */

#ifndef CL_SEC_LOAD_H
#define CL_SEC_LOAD_H

#define CL_SEC_CONTROL_BASE_ADDR            0x60000100
#define CL_SEC_CONTROL_MAGIC_ADDR           (CL_SEC_CONTROL_BASE_ADDR + 0x00)
#define CL_SEC_CONTROL_VERSION_ADDR         (CL_SEC_CONTROL_BASE_ADDR + 0x04)
#define CL_SEC_CONTROL_FW_FSM_ADDR          (CL_SEC_CONTROL_BASE_ADDR + 0x08)
#define CL_SEC_CONTROL_HOST_FSM_ADDR        (CL_SEC_CONTROL_BASE_ADDR + 0x0C)
#define CL_SEC_CONTROL_FILE_ID_ADDR         (CL_SEC_CONTROL_BASE_ADDR + 0x10)
#define CL_SEC_CONTROL_FILE_SIZE_ADDR       (CL_SEC_CONTROL_BASE_ADDR + 0x14)
#define CL_SEC_CONTROL_OWNER0_ADDR          (CL_SEC_CONTROL_BASE_ADDR + 0x18)
#define CL_SEC_CONTROL_DOWNLOAD_ADDR        (CL_SEC_CONTROL_BASE_ADDR + 0x1C)

#define CL_SEC_ENCRYPTED_BIN_ADDR           0x60000800
#define CL_SEC_MAX_BINARY_SIZE              0x3E000

#define CL_SEC_CONTROL_MAGIC_VAL            0x0BAD1234

#define CL_SEC_OTP_BYTE_SIZE                8
#define CL_SEC_OTP_BASE_ADDR                0x60000140
#define CL_SEC_OTP_ADDR_SECURITY_ENABLE     (0x340 / CL_SEC_OTP_BYTE_SIZE + CL_SEC_OTP_BASE_ADDR)
#define CL_SEC_OTP_VAL_SECURITY_SIM         3

#define CL_SEC_PHY_INFO_ADDR                0x60000330
#define CL_SEC_PHY_CORE_VERSION_ADDR        (CL_SEC_PHY_INFO_ADDR + 0x00)
#define CL_SEC_PHY_CORE_ID_ADDR             (CL_SEC_PHY_INFO_ADDR + 0x04)

#define CL_PHY_DMEM_BASE 0x60400000
#define CL_PHY_DMEM_SIZE 0x40000
#define CL_PHY_XMEM_BASE 0x60480000
#define CL_PHY_XMEM_SIZE 0x20000
#define CL_PHY_PMEM_SIZE 0x88000

#define CL_SEC_DSP_INTERNAL_MEM   0x80000000

#define CL_SEC_GET_FILE_INDEX(file_id) ((file_id) & 0xff)
#define CL_SEC_GET_FILE_CHUNK(file_id) (((file_id) >> 16) & 0xff)
#define CL_SEC_PACK_FILE_ID(file_chunk, file_count, file_index) \
	((((file_chunk) & 0xff) << 16) | (((file_count) & 0xff) << 8) | ((file_index) & 0xff))

#define CL_SEC_LOADER_NON_SECURE_NAME   "ldrns-lmacfw.bin"

enum {
	CL_SEC_DL_FSM_INIT = 0,
	CL_SEC_DL_FSM_REQUEST_FILE,
	CL_SEC_DL_FSM_PROCESS_FILE,
	CL_SEC_DL_FSM_DONE,
	CL_SEC_DL_FSM_ERROR,
	CL_SEC_DL_FSM_TEST,

	CL_SEC_DL_FSM_LAST
};

#endif   /* CL_SEC_LOAD_H */

