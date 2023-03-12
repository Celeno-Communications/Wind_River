/**
 ****************************************************************************************
 *
 * @file arch.h
 *
 * @brief This file contains the definitions of the macros and functions that are
 * architecture dependent.  The implementation of those is implemented in the
 * appropriate architecture directory.
 *
 * Copyright (C) RivieraWaves 2011-2013
 *
 ****************************************************************************************
 */

#ifndef _ARCH_H_
#define _ARCH_H_

/**
 ****************************************************************************************
 * @defgroup PLATFORM_DRIVERS PLATFORM_DRIVERS
 * @ingroup MAC_HW
 * @brief Declaration of the platform API.
 * @{
 ****************************************************************************************
 */

/**
 ****************************************************************************************
 * @defgroup ARCH_XTENSA ARCH_XTENSA
 * @ingroup PLATFORM_DRIVERS
 * @brief Declaration of the platform architecture API.
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
// required to define GLOBAL_INT_** macros as inline assembly
#include "compiler.h"
//#include "rwnx_config.h"
//#include "boot.h"
//#include "ll.h"
#if CE_DBG_STR_OFFLOAD
//#include "file_id.h"
#endif //CE_DBG_STR_OFFLOAD

//#include "la.h"

// Include file for HAL
//#include <xtensa/config/core.h>
// Include file for XTOS
//#include <xtensa/xtruntime.h>
// Include file for XTOS instructions
//#include <xtensa/tie/xt_core.h>
/*
 * CPU WORD SIZE
 ****************************************************************************************
 */
#define CPU_WORD_SIZE   4

/*
 * CPU Endianness
 ****************************************************************************************
 */
#define CPU_LE          1


/*
 * Structure Defines
 ****************************************************************************************
 */

#define BG_ASSERT_STR_LEN    12
struct bg_assert_info
{
    uint8_t     dump_en;
    const char  err_str[BG_ASSERT_STR_LEN];
};

/*
 * ASSERTION CHECKS AND RECOVERY
 ****************************************************************************************
 */
void int_disable_timing_print();
void force_trigger(const char *msg);

#if CE_DBG_STR_OFFLOAD
//--------------------------------- Debug String Offload --------------------------------
void assert_err(uint16_t fileid, uint16_t line);
void assert_rec(uint16_t fileid, uint16_t line);
void assert_err_param1(uint16_t fileid, uint16_t line, int param1);
void assert_rec_param1(uint16_t fileid, uint16_t line, int param1);
void assert_warn(uint16_t fileid, uint16_t line);
void assert_warn_dump(const char *condition, const char *file, int line);
void assert_rec_bg(uint16_t fileid, uint16_t line, struct bg_assert_info *assert_info);
#else
//--------------------------- Regular (Local) debug string ------------------------------
void assert_rec(const char *condition, const char * file, int line);
void assert_err(const char *condition, const char * file, int line);
void assert_err_param1(const char *condition, const char * file, int line, int param1);
void assert_rec_param1(const char *condition, const char * file, int line, int param1);
void assert_warn(const char *condition, const char * file, int line);
void assert_warn_dump(const char *condition, const char *file, int line);
void assert_rec_bg(const char *condition, const char * file, int line);
#endif // CE_DBG_STR_OFFLOAD

#if NX_DEBUG
/***************************************************************************************
 * NX_DEBUG Enabled
 ***************************************************************************************/

#if CE_DBG_STR_OFFLOAD
//-------------------------------- Debug String Offload --------------------------------
/// Assertions showing a critical error that could require a full system reset
// benson-axi-tbd: change line from uint16_t to uint32_t to support large (>65535 lines) files???
#define ASSERT_ERR(cond)                              \
    do {                                              \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_err(DBG_FILEID, (uint16_t)__LINE__);         \
        }                                             \
    } while(0)

/// Assertions showing a critical error with Parameter that could require a full system reset
#define ASSERT_ERR_PARAM1(cond, param1)                              \
    do {                                                             \
        if (!(cond)) {                                               \
            branch_unlikely();                                       \
            assert_err_param1(DBG_FILEID,__LINE__, param1);          \
        }                                                            \
    } while(0)

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR2(cond, param0, param1) ASSERT_ERR(cond)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond)                             \
    do {                                              \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_warn(DBG_FILEID,__LINE__);         \
        }                                             \
    } while(0)

#define ASSERT_WARN_DUMP(cond)                              \
    do                                                      \
    {                                                       \
        if (!(cond))                                        \
        {                                                   \
            branch_unlikely();                              \
            assert_warn_dump(#cond,__MODULE__, __LINE__);         \
        }                                                   \
    } while (0)
#else
//--------------------------- Regular (Local) debug string ------------------------------
/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR(cond)                              \
    do {                                              \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_err(#cond, __MODULE__, __LINE__);  \
        }                                             \
    } while(0)

/// Assertions showing a critical error with Parameter that could require a full system reset
#define ASSERT_ERR_PARAM1(cond, param1)                              \
    do {                                                             \
        if (!(cond)) {                                               \
            branch_unlikely();                                       \
            assert_err_param1(#cond, __MODULE__, __LINE__, param1);  \
        }                                                            \
    } while(0)

/// Assertions showing a critical error that could require a full system reset
#define ASSERT_ERR2(cond, param0, param1) ASSERT_ERR(cond)

/// Assertions showing a non-critical problem that has to be fixed by the SW
#define ASSERT_WARN(cond)                             \
    do {                                              \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_warn(#cond, __MODULE__, __LINE__); \
        }                                             \
    } while(0)

#define ASSERT_WARN_DUMP(cond)                              \
    do                                                      \
    {                                                       \
        if (!(cond))                                        \
        {                                                   \
            branch_unlikely();                              \
            assert_warn_dump(#cond, __MODULE__, __LINE__);  \
        }                                                   \
    } while (0)
#endif //CE_DBG_STR_OFFLOAD

#if (CE_REG_ASSERT)
#define ASSERT_ERR_REG(cond)    ASSERT_ERR(cond)
#else
#define ASSERT_ERR_REG(cond)
#endif

#else
/***************************************************************************************
 * NX_DEBUG Disabled
 ***************************************************************************************/
#define ASSERT_ERR(cond)
#define ASSERT_ERR2(cond, param0, param1)
#define ASSERT_WARN(cond)
#define ASSERT_ERR_REG(cond)

#define ASSERT_REC_BG(cond)    ASSERT_ERR(cond)

#define ASSERT_REC_BG_VAL(cond, ret)  ASSERT_ERR(cond)

#endif

extern struct bg_assert_info g_mac_cca_to   ;
extern struct bg_assert_info g_hal_ac       ;
extern struct bg_assert_info g_bg_assert    ;
extern struct bg_assert_info g_cca_phylock  ;
extern struct bg_assert_info g_rx_rhd_split ;
//extern struct bg_assert_info g_mac_state_fail[TRIG_RULE_INTERNAL_MAX];


#if NX_RECOVERY
/***************************************************************************************
 * NX_RECOVERY Enabled
 ***************************************************************************************/

#if (XT_DBG_INT_PREEMPT)
/// External declaration of Global counters
extern uint32_t  g_int_cnt;
extern uint32_t  g_ce_int_cnt;

#if CE_DBG_STR_OFFLOAD
/// Assertions that trigger the automatic recovery mechanism and return void
#define ASSERT_REC(cond)                              \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(DBG_FILEID, __LINE__);         \
            g_int_cnt = 0;                            \
            g_ce_int_cnt = 0;                         \
            return;                                   \
        }                                             \
    })

/// Background Assertions that trigger the automatic recovery mechanism and return void
#define ASSERT_REC_BG(cond)                           \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(DBG_FILEID, __LINE__);      \
            g_int_cnt = 0;                            \
            g_ce_int_cnt = 0;                         \
            return;                                   \
        }                                             \
    })
#else //CE_DBG_STR_OFFLOAD
/// Assertions that trigger the automatic recovery mechanism and return void
#define ASSERT_REC(cond)                              \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(#cond, __MODULE__, __LINE__);  \
            g_int_cnt = 0;                            \
            g_ce_int_cnt = 0;                         \
            return;                                   \
        }                                             \
    })

/// Background Assertions that trigger the automatic recovery mechanism and return void
#define ASSERT_REC_BG(cond)                             \
    ({                                                       \
        if (!(cond)) {                                       \
            branch_unlikely();                               \
            assert_rec(#cond, __MODULE__, __LINE__);  \
            g_int_cnt = 0;                                   \
            g_ce_int_cnt = 0;                                \
            return;                                          \
        }                                                    \
    })
#endif // CE_DBG_STR_OFFLOAD

#if CE_DBG_STR_OFFLOAD
#define ASSERT_REC_PARAM1(cond, param1)                              \
    ({                                                               \
        if (!(cond)) {                                               \
            branch_unlikely();                                       \
            assert_rec_param1(DBG_FILEID, __LINE__,param1);          \
            g_int_cnt = 0;                                           \
            g_ce_int_cnt = 0;                                        \
            return;                                                  \
        }                                                            \
    })
#else //CE_DBG_STR_OFFLOAD
#define ASSERT_REC_PARAM1(cond, param1)                              \
    ({                                                               \
        if (!(cond)) {                                               \
            branch_unlikely();                                       \
            assert_rec_param1(#cond, __MODULE__, __LINE__,param1);   \
            g_int_cnt = 0;                                           \
            g_ce_int_cnt = 0;                                        \
            return;                                                  \
        }                                                            \
    })
#endif // CE_DBG_STR_OFFLOAD

#if CE_DBG_STR_OFFLOAD
#define ASSERT_REC_VAL(cond, ret)                     \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(DBG_FILEID, __LINE__);         \
            g_int_cnt = 0;                            \
            g_ce_int_cnt = 0;                         \
            return (ret);                             \
        }                                             \
    })

#define ASSERT_REC_BG_VAL(cond, ret, dump_en)         \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec_bg(DBG_FILEID, __LINE__,dump_en);     \
            g_int_cnt = 0;                            \
            g_ce_int_cnt = 0;                         \
            return (ret);                             \
        }                                             \
    })
#else
#define ASSERT_REC_VAL(cond, ret)                     \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(#cond, __MODULE__, __LINE__);  \
            g_int_cnt = 0;                            \
            g_ce_int_cnt = 0;                         \
            return (ret);                             \
        }                                             \
    })
#define ASSERT_REC_BG_VAL(cond, ret)                    \
    ({                                                  \
        if (!(cond)) {                                  \
            branch_unlikely();                          \
            assert_rec(#cond, __MODULE__, __LINE__); 	\
            g_int_cnt = 0;                              \
            g_ce_int_cnt = 0;                           \
            return (ret);                               \
        }                                               \
    })
#endif // CE_DBG_STR_OFFLOAD

#else // XT_DBG_INT_PREEMPT

#if CE_DBG_STR_OFFLOAD
#define ASSERT_REC(cond)                              \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(DBG_FILEID, __LINE__);         \
            return;                                   \
        }                                             \
    })

#define ASSERT_REC_BG(cond, dump_en)                 \
  ({                                                 \
        if (!(cond)) {                               \
            branch_unlikely();                       \
            assert_rec_bg(DBG_FILEID, __LINE__ ,dump_en);       \
            return;                                  \
        }                                            \
  })

/// Assertions showing a critical error with Parameter, trigger the automatic recovery mechanism and return void
#else //CE_DBG_STR_OFFLOAD
#define ASSERT_REC(cond)                              \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(#cond, __MODULE__, __LINE__);  \
            return;                                   \
        }                                             \
    })

#define ASSERT_REC_BG(cond)                                 \
  ({                                                        \
        if (!(cond)) {                                      \
            branch_unlikely();                              \
            assert_rec(#cond, __MODULE__, __LINE__ );    	\
            return;                                         \
        }                                                   \
  })
#endif

#if CE_DBG_STR_OFFLOAD
#define ASSERT_REC_PARAM1(cond, param1)                              \
    ({                                                               \
        if (!(cond)) {                                               \
            branch_unlikely();                                       \
            assert_rec_param1(DBG_FILEID, __LINE__,param1);          \
            return;                                                  \
        }                                                            \
    })
#else //CE_DBG_STR_OFFLOAD
#define ASSERT_REC_PARAM1(cond, param1)                              \
    ({                                                               \
        if (!(cond)) {                                               \
            branch_unlikely();                                       \
            assert_rec_param1(#cond, __MODULE__, __LINE__,param1);   \
            return;                                                  \
        }                                                            \
    })
#endif

#if CE_DBG_STR_OFFLOAD
#define ASSERT_REC_VAL(cond, ret)                     \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(DBG_FILEID, __LINE__);         \
            return (ret);                             \
        }                                             \
    })

#define ASSERT_REC_BG_VAL(cond, ret, dump_en)         \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec_bg(DBG_FILEID, __LINE__, dump_en);  \
            return (ret);                             \
        }                                             \
    })
#else
#define ASSERT_REC_VAL(cond, ret)                     \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(#cond, __MODULE__, __LINE__);  \
            return (ret);                             \
        }                                             \
    })
#define ASSERT_REC_BG_VAL(cond, ret)                    \
    ({                                                  \
        if (!(cond)) {                                  \
            branch_unlikely();                          \
            assert_rec(#cond, __MODULE__, __LINE__); 	\
            return (ret);                               \
        }                                               \
    })
#endif

#if CE_DBG_STR_OFFLOAD
/// Assertions that trigger the automatic recovery mechanism and do not return
#define ASSERT_REC_NO_RET(cond)                       \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(DBG_FILEID, __LINE__);         \
        }                                             \
    })
#else //CE_DBG_STR_OFFLOAD
/// Assertions that trigger the automatic recovery mechanism and do not return
#define ASSERT_REC_NO_RET(cond)                       \
    ({                                                \
        if (!(cond)) {                                \
            branch_unlikely();                        \
            assert_rec(#cond, __MODULE__, __LINE__);  \
        }                                             \
    })
#endif //CE_DBG_STR_OFFLOAD

#endif // XT_DBG_INT_PREEMPT

#else
/***************************************************************************************
 * NX_RECOVERY Disabled
 ***************************************************************************************/

/// Assertions that trigger the automatic recovery mechanism and return void
#define ASSERT_REC(cond)                ASSERT_ERR(cond)

#ifndef ASSERT_REC_BG
#define ASSERT_REC_BG(cond, dump_en)    ASSERT_ERR(cond)
#endif

#define ASSERT_REC_PARAM1(cond, param1) ASSERT_ERR_PARAM1(cond, param1)

#define ASSERT_REC_VAL(cond, ret)       ASSERT_ERR(cond)

#ifndef ASSERT_REC_BG_VAL
#define ASSERT_REC_BG_VAL(cond, ret, dump_en)    ASSERT_ERR(cond)
#endif

#define ASSERT_REC_NO_RET(cond)         ASSERT_ERR(cond)
#endif // NX_RECOVERY

#define ASSERT_PRESILICON(cond)         ASSERT_REC(cond)

/// Object allocated in shared memory - check linker script
#define __SHARED __attribute__ ((section("shram")))

///------------------------------------ Platform specific definitions --------------------------------------
#ifdef CONFIG_MACH_DINIV6
#  define XT_CORE_CLK_FREQ_MHZ       80           // Xtensa core clock frequency in MHz
#  define XT_LED_BLINK_PERIOD_BIT    CO_BIT(25)   // RUN LED blink period (~0.5sec)
#else // ASIC platform
#  define XT_CORE_CLK_FREQ_MHZ       480          // Xtensa core clock frequency in MHz
#  define XT_LED_BLINK_PERIOD_BIT    CO_BIT(28)   // Xtensa core clock frequency in MHz
#endif

#define XT_USEC()                    (XT_CORE_CLK_FREQ_MHZ)
#define XT_MSEC()                    (XT_CORE_CLK_FREQ_MHZ * 1000)
#define XT_SEC()                     (XT_CORE_CLK_FREQ_MHZ * 1000000)

/// Generating macro for busy-wait delay functions (mdelay, udelay, sdelay)
#define DELAY_FUNC_GEN(name, time_to_cycle_convert)                      \
  void name(uint32_t u32time)                                            \
  {                                                                      \
        if (u32time == 0) return;                                        \
        uint32_t u32start_cycle = xthal_get_ccount();                    \
        uint32_t u32delay_cycles = u32time * time_to_cycle_convert();    \
        while ((xthal_get_ccount() - u32start_cycle) < u32delay_cycles); \
  }

/**
 ****************************************************************************************
 * @brief Busy-wait delay for a specified period in milliseconds.
 *
 * @param[in] u32time          Delay period in milliseconds.
 *
 ****************************************************************************************
 */
void mdelay(uint32_t u32time);

/**
 ****************************************************************************************
 * @brief Busy-wait delay for a specified period in microseconds.
 *
 * @param[in] u32time          Delay period in microseconds.
 *
 ****************************************************************************************
 */
void udelay(uint32_t u32time);

/**
 ****************************************************************************************
 * @brief Busy-wait delay for a specified period in seconds.
 *
 * @param[in] u32time          Delay period in seconds.
 *
 ****************************************************************************************
 */
void sdelay(uint32_t u32time);

/// @}
/// @}
#endif // _ARCH_H_
