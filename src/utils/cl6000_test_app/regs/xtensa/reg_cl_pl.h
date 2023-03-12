
/**
 ****************************************************************************************
 *
 * @file reg_cl_pl.h
 *
 * @brief address space definitions
 *
 ****************************************************************************************
 */

#ifndef _REG_CL_PL_H
#define _REG_CL_PL_H

#include "rwnx_config.h"
#include "reg_shared_ram.h"
#include "reg_lmac.h"
#include "reg_umac.h"
#include "reg_smac.h"

/****************************************************************************************
 * Terms used in this file:                                                             *
 *                                                                                      *
 * 1. Local (memory) access: access to a memory address space from                      *
 *    within the xtensa core (LMAC/UMAC).                                               *
 * 2. Remote (memory) access: access to a memory address space by                       *
 *    an external AHB-matrix master.                                                    *
 *                                                                                      *
 ****************************************************************************************
 */


/*********************************************************************************
 * CE_generic_loc2rem_ptr_convert(cpu, mem, local_ptr)                           *
 *                                                                               *
 * Convert a local memory address to the corresponding remote AHB master address *
 * Input: cpu = { LMAC, UMAC }                                                   *
 *        mem = { IRAM, DRAM }                                                   *
 *        local_ptr - local memory address                                       *
 *                                                                               *
 * For example: CE_generic_loc2rem_ptr_convert(LMAC, DRAM, ptr) -                *
 * converts the local LMAC DRAM pointer "ptr".                                   *
 *                                                                               *
 * This macro is not intended to be used directly by Software. It is used for    *
 * generating specific conversion macros (see below).                            *
 **********************************************************************************/
#define CE_generic_loc2rem_ptr_convert(cpu, mem, local_ptr)  \
   (void *)((uint32_t)local_ptr + CE_##cpu##_##mem##_REMOTE_ADDR_OFFSET)

/*********************************************************************************
 * CE_generic_rem2loc_ptr_convert(cpu, mem, remote_ptr)                          *
 *                                                                               *
 * Convert a remote (AHB-master) memory address to the corresponding local       *
 * memory address.                                                               *
 * Input: cpu = { LMAC, UMAC }                                                   *
 *        mem = { IRAM, DRAM }                                                   *
 *        remote_ptr - remote memory address                                     *
 *                                                                               *
 * For example: CE_generic_rem2loc_ptr_convert(LMAC, DRAM, ptr) -                *
 * converts the remote LMAC DRAM pointer "ptr" to a local LMAC DRAM pointer.     *
 *                                                                               *
 * This macro is not intended to be used directly by Software. It is used for    *
 * generating specific conversion macros (see below).                            *
 **********************************************************************************/
#define CE_generic_rem2loc_ptr_convert(cpu, mem, remote_ptr) \
   (void *)((uint32_t)remote_ptr - CE_##cpu##_##mem##_REMOTE_ADDR_OFFSET)

/*-------------------------------------- HOST -------------------------------------*/
// host base address & mask (used for tx queues rd index address
#if (CE_HW_VERSION >= HW_8000_STEP_A0)
#define CE_HOST_DRAM_BASE               0x607E0000 
#else // (CE_HW_VERSION >= HW_8000_STEP_A0)
#define CE_HOST_DRAM_BASE               0x604C0000
#endif // (CE_HW_VERSION >= HW_8000_STEP_A0)

#define CE_HOST_DRAM_MASK               0x0000FFFF

/*----------------------------------- Shared RAM ----------------------------------*/
// Shared RAM - included in reg_shared_ram.h file
// Logger RAM - included in reg_logger_ram.h file

// benson-axi: add support for axi model
#if (CE_HW_VERSION >= HW_8000_STEP_A0)
// Cyclic buffer
#if PRIM_BAND
#define CE_CYC_BUF_BASE_ADDR            0x60140000
#define CE_CYC_BUF_END_ADDR             0x601FFFFF
#else
#define CE_CYC_BUF_BASE_ADDR            0x60700000
#define CE_CYC_BUF_END_ADDR             0x6077FFFF
#endif

#define CYC_BUF_BASE_DIRECT_ADDR       REG_SHARED_AXI_2_DIR_PTR(CE_CYC_BUF_BASE_ADDR)
#define CYC_BUF_END_DIRECT_ADDR        REG_SHARED_AXI_2_DIR_PTR(CE_CYC_BUF_END_ADDR)

#else // (CE_HW_VERSION >= HW_8000_STEP_A0)

// Cyclic buffer
#define CE_CYC_BUF_BASE_ADDR            0x60040000
#define CE_CYC_BUF_END_ADDR             0x60077FFF
#endif // (CE_HW_VERSION >= HW_8000_STEP_A0)

#if (XT_CACHE_ENABLED)
// Data Cache mapped virtual regions
#define CE_DCACHE_REGION_0_BASE_ADDR    0xA0000000
#define CE_DCACHE_REGION_1_BASE_ADDR    0xC0000000
#define CE_DCACHE_REGION_SIZE           0x20000000
// Convert Pointer to access cached region
#define CACHE_REGION_0_PTR(p)       ( ((uint32_t)p & 0x0FFFFFFF) | CE_DCACHE_REGION_0_BASE_ADDR )
#else
#define CACHE_REGION_0_PTR(p)       (p)
#endif // XT_CACHE_ENABLED


/*----------------------------------- LMAC Memory ----------------------------------*/
// LMAC memory - included in reg_shared_ram.h file

// IRAM base address (local access)
#define CE_LMAC_LOCAL_IRAM_BASE_ADDR    0x40040000

// IRAM base address (remote access)
#define CE_LMAC_REMOTE_IRAM_BASE_ADDR   LMAC_IRAM_ADDR

// Offset between IRAM local and remote base addresses
#define CE_LMAC_IRAM_REMOTE_ADDR_OFFSET (CE_LMAC_REMOTE_IRAM_BASE_ADDR - CE_LMAC_LOCAL_IRAM_BASE_ADDR)

// DRAM base address (local access)
#define CE_LMAC_LOCAL_DRAM_BASE_ADDR    0x40000000

// DRAM base address (remote access)
#define CE_LMAC_REMOTE_DRAM_BASE_ADDR   LMAC_DRAM_ADDR

// Offset between DRAM local and remote base addresses
#define CE_LMAC_DRAM_REMOTE_ADDR_OFFSET (CE_LMAC_REMOTE_DRAM_BASE_ADDR - CE_LMAC_LOCAL_DRAM_BASE_ADDR)

/// Pointer conversion Macros

// Convert a local LMAC IRAM address to the corresponding remote address
#define CE_LMAC_IRAM_REM_PTR(ptr)       (void *)((uint32_t)ptr + CE_LMAC_IRAM_REMOTE_ADDR_OFFSET)

// Convert a local LMAC DRAM address to the corresponding remote address
#define CE_LMAC_DRAM_REM_PTR(ptr)       (void *)((uint32_t)ptr + CE_LMAC_DRAM_REMOTE_ADDR_OFFSET)

#define CE_LMAC_LOC2REM_DRAM_PTR(ptr)  CE_generic_loc2rem_ptr_convert(LMAC, DRAM, ptr)
#define CE_LMAC_REM2LOC_DRAM_PTR(ptr)  CE_generic_rem2loc_ptr_convert(LMAC, DRAM, ptr)

#define CE_LMAC_LOC2REM_IRAM_PTR(ptr)  CE_generic_loc2rem_ptr_convert(LMAC, IRAM, ptr)
#define CE_LMAC_REM2LOC_IRAM_PTR(ptr)  CE_generic_rem2loc_ptr_convert(LMAC, IRAM, ptr)


/*----------------------------------- UMAC Memory --------------------------------*/
// UMAC Instruction RAM total size in bytes
#define CE_UMAC_IRAM_SIZE    			0x30000 // 192 KB

// UMAC dram total size in bytes
#define CE_UMAC_DRAM_SIZE    			0x20000 // 128 KB

// IRAM base address (local access)
#define CE_UMAC_LOCAL_IRAM_BASE_ADDR    0x40040000

// IRAM base address (remote access)
#define CE_UMAC_REMOTE_IRAM_BASE_ADDR   UMAC_IRAM_ADDR

// Offset between IRAM local and remote base addresses
#define CE_UMAC_IRAM_REMOTE_ADDR_OFFSET (CE_UMAC_REMOTE_IRAM_BASE_ADDR - CE_UMAC_LOCAL_IRAM_BASE_ADDR)

// DRAM base address (local access)
#define CE_UMAC_LOCAL_DRAM_BASE_ADDR    0x40000000

// DRAM base address (remote access)
#define CE_UMAC_REMOTE_DRAM_BASE_ADDR   UMAC_DRAM_ADDR

// Offset between DRAM local and remote base addresses
#define CE_UMAC_DRAM_REMOTE_ADDR_OFFSET (CE_UMAC_REMOTE_DRAM_BASE_ADDR - CE_UMAC_LOCAL_DRAM_BASE_ADDR)

// Convert a local LMAC IRAM address to the corresponding remote address
#define CE_UMAC_IRAM_REM_PTR(ptr)       (void *)((uint32_t)ptr + CE_UMAC_IRAM_REMOTE_ADDR_OFFSET)

// Convert a local LMAC DRAM address to the corresponding remote address
#define CE_UMAC_DRAM_REM_PTR(ptr)       (void *)((uint32_t)ptr + CE_UMAC_DRAM_REMOTE_ADDR_OFFSET)


#define CE_UMAC_LOC2REM_DRAM_PTR(ptr)  CE_generic_loc2rem_ptr_convert(UMAC, DRAM, ptr)
#define CE_UMAC_REM2LOC_DRAM_PTR(ptr)  CE_generic_rem2loc_ptr_convert(UMAC, DRAM, ptr)

#define CE_UMAC_LOC2REM_IRAM_PTR(ptr)  CE_generic_loc2rem_ptr_convert(UMAC, IRAM, ptr)
#define CE_UMAC_REM2LOC_IRAM_PTR(ptr)  CE_generic_rem2loc_ptr_convert(UMAC, IRAM, ptr)

/*----------------------------------- SMAC Memory --------------------------------*/
// SMAC Instruction RAM total size in bytes
#define CE_SMAC_IRAM_SIZE    			0x40000 // 256 KB

// SMAC dram total size in bytes
#define CE_SMAC_DRAM_SIZE    			0x40000 // 256 KB

// IRAM base address (local access)
#define CE_SMAC_LOCAL_IRAM_BASE_ADDR    0x40040000

// IRAM base address (remote access)
#define CE_SMAC_REMOTE_IRAM_BASE_ADDR   SMAC_IRAM_ADDR

// Offset between IRAM local and remote base addresses
#define CE_SMAC_IRAM_REMOTE_ADDR_OFFSET (CE_SMAC_REMOTE_IRAM_BASE_ADDR - CE_SMAC_LOCAL_IRAM_BASE_ADDR)

// DRAM base address (local access)
#define CE_SMAC_LOCAL_DRAM_BASE_ADDR    0x40000000

// DRAM base address (remote access)
#define CE_SMAC_REMOTE_DRAM_BASE_ADDR   SMAC_DRAM_ADDR

// Offset between DRAM local and remote base addresses
#define CE_SMAC_DRAM_REMOTE_ADDR_OFFSET (CE_SMAC_REMOTE_DRAM_BASE_ADDR - CE_SMAC_LOCAL_DRAM_BASE_ADDR)


// Convert a local LMAC IRAM address to the corresponding remote address
#define CE_SMAC_IRAM_REM_PTR(ptr)       (void *)((uint32_t)ptr + CE_SMAC_IRAM_REMOTE_ADDR_OFFSET)

// Convert a local LMAC DRAM address to the corresponding remote address
#define CE_SMAC_DRAM_REM_PTR(ptr)       (void *)((uint32_t)ptr + CE_SMAC_DRAM_REMOTE_ADDR_OFFSET)


#define CE_SMAC_LOC2REM_DRAM_PTR(ptr)  CE_generic_loc2rem_ptr_convert(SMAC, DRAM, ptr)
#define CE_SMAC_REM2LOC_DRAM_PTR(ptr)  CE_generic_rem2loc_ptr_convert(SMAC, DRAM, ptr)

#define CE_SMAC_LOC2REM_IRAM_PTR(ptr)  CE_generic_loc2rem_ptr_convert(SMAC, IRAM, ptr)
#define CE_SMAC_REM2LOC_IRAM_PTR(ptr)  CE_generic_rem2loc_ptr_convert(SMAC, IRAM, ptr)


/*-------------------------- Generic Pointer Conversion Macros  --------------------------------*/
#if PRIM_BAND

   #define CE_DRAM_LOC2REM_PTR(ptr)   CE_LMAC_LOC2REM_DRAM_PTR(ptr)
   #define CE_DRAM_REM2LOC_PTR(ptr)   CE_LMAC_REM2LOC_DRAM_PTR(ptr)

   #define CE_IRAM_LOC2REM_PTR(ptr)   CE_LMAC_LOC2REM_IRAM_PTR(ptr)
   #define CE_IRAM_REM2LOC_PTR(ptr)   CE_LMAC_REM2LOC_IRAM_PTR(ptr)

   #define CE_DRAM_START_ADDR         CE_LMAC_LOCAL_DRAM_BASE_ADDR
   #define CE_DRAM_END_ADDR           (CE_LMAC_LOCAL_DRAM_BASE_ADDR + LMAC_DRAM_SIZE - 1)

   #define CE_IRAM_START_ADDR         CE_LMAC_LOCAL_IRAM_BASE_ADDR
   #define CE_IRAM_END_ADDR           (CE_LMAC_LOCAL_IRAM_BASE_ADDR + LMAC_IRAM_SIZE - 1)

   #define XMAC_DRAM_REM_PTR          CE_LMAC_DRAM_REM_PTR

   #define DRAM_REMOTE_ADDR_OFFSET    CE_LMAC_DRAM_REMOTE_ADDR_OFFSET

#elif SEC_BAND

   #define CE_DRAM_LOC2REM_PTR(ptr)   CE_SMAC_LOC2REM_DRAM_PTR(ptr)
   #define CE_DRAM_REM2LOC_PTR(ptr)   CE_SMAC_REM2LOC_DRAM_PTR(ptr)

   #define CE_IRAM_LOC2REM_PTR(ptr)   CE_SMAC_LOC2REM_IRAM_PTR(ptr)
   #define CE_IRAM_REM2LOC_PTR(ptr)   CE_SMAC_REM2LOC_IRAM_PTR(ptr)

   #define CE_DRAM_START_ADDR         CE_SMAC_LOCAL_DRAM_BASE_ADDR
   #define CE_DRAM_END_ADDR           (CE_SMAC_LOCAL_DRAM_BASE_ADDR + SMAC_DRAM_SIZE - 1)

   #define CE_IRAM_START_ADDR         CE_SMAC_LOCAL_IRAM_BASE_ADDR
   #define CE_IRAM_END_ADDR           (CE_SMAC_LOCAL_IRAM_BASE_ADDR + SMAC_IRAM_SIZE - 1)

   #define XMAC_DRAM_REM_PTR          CE_SMAC_DRAM_REM_PTR
   #define DRAM_REMOTE_ADDR_OFFSET    CE_SMAC_DRAM_REMOTE_ADDR_OFFSET

#else
   #error "Invalid CL Platform!"
#endif

/*----------------------------------- IPC Mail Box --------------------------------*/
// IPC Mail Box size in the LMAC
#define CE_LMAC_IMB_SIZE		0x400 // 1024 bytes
// IPC Mail Box base address in the LMAC
#define CE_LMAC_IMB_BASE_ADDR	 (CE_LMAC_REMOTE_DRAM_BASE_ADDR + LMAC_DRAM_SIZE - CE_LMAC_IMB_SIZE) //0x6015FC00

// IPC Mail Box size in the UMAC
#define CE_UMAC_IMB_SIZE		0x400 // 1024 bytes
// IPC Mail Box base address in the UMAC
#define CE_UMAC_IMB_BASE_ADDR	 (CE_UMAC_REMOTE_DRAM_BASE_ADDR + UMAC_DRAM_SIZE - CE_UMAC_IMB_SIZE) //0x6025FC00


/*****************************************************************************/
/*                      LMAC DIRECT ACCESS TO SHARED RAM                     */
/*****************************************************************************/


// there is no Direct access for step B
#define REG_SHARED_DIR_2_AXI_PTR(ptr)    (ptr)
#define REG_SHARED_AXI_2_DIR_PTR(ptr)    (ptr)
#if (CE_HW_VERSION >= HW_8000_STEP_B0)
/*****************************************************************************/
/*                      LMAC / SMAC DRAM1 SPACE                              */
/* ONLY LMAC/SMAC has access to this memory space. each PC has its one DRAM1 */
/*****************************************************************************/
#define REG_LMAC_SMAC_DRAM1_BASE_ADDR    0x50000000
#define REG_LMAC_SMAC_DRAM1_SIZE         0x10000
#define REG_LMAC_SMAC_DRAM1_END_ADDR     ( REG_LMAC_SMAC_DRAM1_BASE_ADDR + REG_LMAC_SMAC_DRAM1_SIZE -1)
#define REG_LMAC_SMAC_DRAM1_MASK         0x70000000
#endif

#if (CE_CYC_BUF)
/**
 ****************************************************************************************
 * @brief Check whether a given pointer has a valid cyclic buffer address.
 *
 * @param ptr Pointer to check
 *
 ****************************************************************************************
 */
__INLINE bool is_valid_cyc_buf_ptr(uint32_t ptr)
{
    return (((uint32_t)ptr >= CE_CYC_BUF_BASE_ADDR && (uint32_t)ptr <= CE_CYC_BUF_END_ADDR));
}
#endif

/**
 ****************************************************************************************
 * @brief Check whether a given pointer has a valid shared RAM address.
 *
 * @param ptr Pointer to check
 *
 ****************************************************************************************
 */
__INLINE bool is_valid_shram_ptr(uint32_t ptr)
{
    
   return((uint32_t)ptr >= REG_SHARED_RAM_BASE_ADDR && (uint32_t)ptr <= SHARED_RAM_SHRAM_END_ADDR)
          #if (CE_CYC_BUF)
          || (is_valid_cyc_buf_ptr(ptr))
          #endif
          ;
}

#if (CE_HW_VERSION >= HW_8000_STEP_B0)
__INLINE bool is_valid_dram1_ptr(uint32_t ptr)
{
    return ((ptr >= REG_LMAC_SMAC_DRAM1_BASE_ADDR) && (ptr <= REG_LMAC_SMAC_DRAM1_END_ADDR));
}
#endif

__INLINE bool is_valid_dram_ptr(uint32_t ptr)
{
    return ((ptr >= CE_DRAM_START_ADDR) && (ptr <= CE_DRAM_END_ADDR));
}

__INLINE bool is_valid_iram_ptr(uint32_t ptr)
{
    return ((ptr >= CE_IRAM_START_ADDR) && (ptr <= CE_IRAM_END_ADDR));
}

#define CL8000_ADDRESS_HIGH   0x607FFFFF
// is address inside address space window 0x60000000 - 0x607FFFFF
__INLINE bool is_valid_cl8000_address(uint32_t ptr)
{
     return ((ptr >= REG_SHARED_RAM_BASE_ADDR) && (ptr <= CL8000_ADDRESS_HIGH));
}

__INLINE bool is_valid_address(uint32_t ptr)
{
    bool is_valid = is_valid_shram_ptr(ptr);

    if (!is_valid)
        is_valid = is_valid_dram_ptr(ptr);

    if (!is_valid)
        is_valid = is_valid_iram_ptr(ptr);
         
    if (!is_valid)
        is_valid = is_valid_cl8000_address(ptr);

    #if (CE_HW_VERSION == HW_8000_STEP_B0)
    if (!is_valid)
        is_valid = is_valid_dram1_ptr(ptr);
    #endif

    return is_valid;
}

#endif // _REG_CL_PL_H

