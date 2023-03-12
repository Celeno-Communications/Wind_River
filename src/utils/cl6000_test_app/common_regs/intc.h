/**
 ****************************************************************************************
 *
 * @file intc.h
 *
 * @brief Declaration of the Reference Interrupt Controller (INTC) API.
 *
 * Copyright (C) RivieraWaves 2011-2013
 *
 ****************************************************************************************
 */

#ifndef _INTC_H_
#define _INTC_H_

/**
 ****************************************************************************************
 * @defgroup INTC INTC
 * @ingroup PLATFORM_DRIVERS
 * @brief Declaration of the Reference Interrupt Controller API
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */
// for __IRQ and __FIQ
//#include "compiler.h"

//xtensa Core Configuration Interrupt Table

//interrupt ports marked with (*) cannot be changed from software
//
/*******************************************************************/
//       | EXCM1         | EXCM2        |  EXCM3        |  NMI     //
//-------+---------------+--------------+---------------+----------//
// 0  (*)| XTOS_TIMER_0  |              |               |          //
// 1  (*)| XTOS_SW_0     |              |               |          //
// 2     | ETH2WLAN_DONE |              |               |          //
// 3     | AHBSLAVE_ERROR|              |               |          //
// 4     | UMAC_LMAC_IPC |              |               |          //
// 5     | PHY           |              |               |          //
// 6     | HOST_IPC      |              |               |          //
// 7     | MACERROR      |              |               |          //
// 8     | MACGEN        |              |               |          //
// 9     | MACTX         |              |               |          //
// 10    | MACRX         |              |               |          //
// 11    | MACTIMER      |              |               |          //
// 12    | LLI           |              |               |          //
// 13    | I2C           |              |               |          //
// 14    | DSP2LMACUMAC  |              |               |          //
// 15    | MACSECERROR   |              |               |          //
// 16    | MACSECGEN     |              |               |          //
// 17    | MACSECRX      |              |               |          //
// 18    | MACSECTIMER   |              |               |          //
// 19    | MACSECTX      |              |               |          //
// 20    | UNUSED1       |              |               |          //
// 21 (*)|               | XTOS_TIMER1  |               |          //
// 22    |               | MACHIGH      |               |          //
// 23    |               | NATT_DONE    |               |          //
// 24    |               | MACSECHIGH   |               |          //
// 25 (*)|               |              |  XTOS_TIMER2  |          //
// 26 (*)|               |              |  XTOS_SW_1    |          //
// 27    |               |              |  UNUSED2      |          //
// 28    |               |              |  UNUSED3      |          //
// 29    |               |              |  UNUSED4      |          //
// 30    |               |              |  UNUSED5      |          //
// 31 (*)|               |              |               |    NMI   //
/*******************************************************************/

/**
 ****************************************************************************************
 * @defgroup INTC_MAPPING Mapping of the peripherals interrupts in the INTC.
 * @{
 ****************************************************************************************
 */
#if (CE_HW_VERSION >= HW_8000_STEP_A0)

#define INTC_NMI            (31)                    //NMI line31
#define INTC_UNUSED8        (30)                    //L3 line30
#define INTC_UNUSED7        (29)                    //L3 line29
#define INTC_AHBSLAVE_ERROR (28)                    //L3 line28
//**HW-WIRED-PORTS-DO-NOT-CHANGE-NUMBERING ****
#define INTC_XTOSSW1        (27)           //**     //L3 line27
#define INTC_XTOSTIMER2     (26)           //**     //L3 line26
//*********************************************
#define INTC_UNUSED6        (25)                    //L2 line25
#define INTC_UNUSED5        (24)                    //L2 line24
#define INTC_UNUSED4        (23)                    //L2 line23
#define INTC_NATT_DONE      (22)                    //L2 line22
#define INTC_MACHIGH        (21)                    //L2 line21 - N/A in UMAC
//**HW-WIRED-PORTS-DO-NOT-CHANGE-NUMBERING ****
#define INTC_XTOSTIMER1     (20)           //**     //L2 line20
//*********************************************
#define INTC_UNUSED3        (19)                    //L1 line19
#define INTC_UNUSED2        (18)                    //L1 line18
#define INTC_UNUSED1        (17)                    //L1 line17
#define INTC_ETH2WLAN_DONE  (16)                    //L1 line16
#define INTC_EDMA           (15)                    //L1 line15
#define INTC_I2C            (14)                    //L1 line14
#define INTC_PHY_DSP        (13)                    //L1 line13
#define INTC_IPC_HOST       (12)                    //L1 line12
#define INTC_IPC_YMAC       (11)                    //L1 line11
#define INTC_IPC_XMAC       (10)                    //L1 line10
#define INTC_BMU            (9)                     //L1 line9
#define INTC_LLI            (8)                     //L1 line8 - PCIWRAPPER
#define INTC_MACTX          (7)                     //L1 line7 - N/A in UMAC
#define INTC_MACTIMER       (6)                     //L1 line6 - N/A in UMAC
#define INTC_MACRX          (5)                     //L1 line5 - N/A in UMAC
#define INTC_MACGEN         (4)                     //L1 line4 - N/A in UMAC
#define INTC_MACERROR       (3)                     //L1 line3 - N/A in UMAC
#define INTC_PHY_RIU        (2)                     //L1 line2
//**HW-WIRED-PORTS-DO-NOT-CHANGE-NUMBERING ****
#define INTC_XTOSSW0        (1)            //**     //L1 line1
#define INTC_XTOSTIMER0     (0)            //**     //L1 line0
//*********************************************
#else // (CE_HW_VERSION >= HW_8000_STEP_A0)
#define INTC_NMI            (31)                    // NMI
#define INTC_UNUSED5        (30)                    //L3 line30
#define INTC_UNUSED4        (29)                    //L3 line29
#define INTC_UNUSED3        (28)                    //L3 line28
#define INTC_AHBSLAVE_ERROR (27)                    //L3 line27
//**HW-WIRED-PORTS-DO-NOT-CHANGE-NUMBERING ****
#define INTC_XTOSSW1        (26)           //**     //L3 line26
#define INTC_XTOSTIMER2     (25)           //**     //L3 line25
//*********************************************
#define INTC_MACSECHIGH     (24)                    //L2 line24
#define INTC_NATT_DONE      (23)                    //L2 line23
#define INTC_MACHIGH        (22)                    //L2 line22
//**HW-WIRED-PORTS-DO-NOT-CHANGE-NUMBERING ****
#define INTC_XTOSTIMER1     (21)           //**     //L2 line21
//*********************************************
#define INTC_UNUSED1        (20)                    //L1 line20
#define INTC_MACSECTX       (19)                    //L1 line19
#define INTC_MACSECTIMER    (18)                    //L1 line18
#define INTC_MACSECRX       (17)                    //L1 line17
#define INTC_MACSECGEN      (16)                    //L1 line16
#define INTC_MACSECERROR    (15)                    //L1 line15
#define INTC_IPC_PHY        (14)                    //L1 line14
#define INTC_I2C            (13)                    //L1 line13
#define INTC_LLI            (12)                    //L1 line12 - //PCIWRAPPER
#define INTC_MACTIMER       (11)                    //L1 line11
#define INTC_MACRX          (10)                    //L1 line10
#define INTC_MACTX          (9)                     //L1 line9
#define INTC_MACGEN         (8)                     //L1 line8
#define INTC_MACERROR       (7)                     //L1 line7
#define INTC_IPC_HOST       (6)                     //L1 line6
#define INTC_PHY_RIU        (5)                     //L1 line5
#define INTC_IPC_XMAC       (4)                     //L1 line4
#define INTC_UNUSED2        (3)                     //L1 line3
#define INTC_ETH2WLAN_DONE  (2)                     //L1 line2
//**HW-WIRED-PORTS-DO-NOT-CHANGE-NUMBERING ****
#define INTC_XTOSSW0        (1)            //**     //L1 line1
#define INTC_XTOSTIMER0     (0)            //**     //L1 line0
//*********************************************
#endif // (CE_HW_VERSION >= HW_8000_STEP_A0)
/// @} INTC_MAPPING

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

#if (CE_HW_VERSION >= HW_8000_STEP_A0)
// Interrupt ports - platform side.
typedef enum int_mux_line
{
    INT_MUX_ETH2WLAN_DONE                   = (0),
    INT_MUX_NATT0_DONE                      = (1),
    INT_MUX_NATT1_DONE                      = (2),
    INT_MUX_PHY0_RIU_INT                    = (3),
    INT_MUX_PHY1_RIU_INT                    = (4),
    INT_MUX_I2C_INT                         = (5),
    INT_MUX_EDMA_INT                        = (6),
    INT_MUX_MACHW0_ERROR_INT                = (7),
    INT_MUX_MACHW0_GEN_INT                  = (8),
    INT_MUX_MACHW0_HIGH_PRI_INT             = (9),
    INT_MUX_MACHW0_RX_INT                   = (10),
    INT_MUX_MACHW0_TIMER_INT                = (11),
    INT_MUX_MACHW0_TX_INT                   = (12),
    INT_MUX_MACHW1_ERROR_INT                = (13),
    INT_MUX_MACHW1_GEN_INT                  = (14),
    INT_MUX_MACHW1_HIGH_PRI_INT             = (15),
    INT_MUX_MACHW1_RX_INT                   = (16),
    INT_MUX_MACHW1_TIMER_INT                = (17),
    INT_MUX_MACHW1_TX_INT                   = (18),
    INT_MUX_PCIEW                           = (19),
    INT_MUX_BMU_INT                         = (20),
    INT_MUX_AHB_SLAVE_ERROR                 = (21),
    INT_MUX_HOST_IPC_INT                    = (22),
    INT_MUX_XMAC_IPC_INT                    = (23),
    INT_MUX_YMAC_IPC_INT                    = (24),
    INT_MUX_PHY0_DSP_INT                    = (25),
    INT_MUX_PHY1_DSP_INT                    = (26),
    INT_MUX_LCU_INT                         = (27),
    INT_MUX_UNUSED_INT                      = (28), // Reserved
    INT_MUX_UNUSED_INT1                     = (29), // Reserved
    INT_MUX_UNUSED_INT2                     = (30), // Reserved
    INT_MUX_UNUSED_INT3                     = (31), // N/A

    // Always keep this entry last
    INT_MUX_MAX

} int_mux_line_e;

// for lmac - ipc_x is for umac, ipc_y is for smac
// for umac - ipc_x is for lmac, ipc_y is for smac
// for smac - ipc_x is for lmac, ipc_y is for umac

#else // (CE_HW_VERSION >= HW_8000_STEP_A0)
// Interrupt ports - platform side.
typedef enum int_mux_line
{
    INT_MUX_ETH2WLAN_DONE                   = (0),
    INT_MUX_AHB_SLAVE_ERROR                 = (1),  //AHB Error Indication from all Masters
    INT_MUX_NATT_DONE                       = (2),
    INT_MUX_IPC_XMAC                        = (3),  //UMAC2LMAC or LMAC2UMAC from IPC
    INT_MUX_PHY_RIU                         = (4),  //Interrupt from RIU
    INT_MUX_IPC_HOST                        = (5),
    INT_MUX_MACHW_PRIMARY_ERROR_INT         = (6),
    INT_MUX_MACHW_PRIMARY_GEN_INT           = (7),
    INT_MUX_MACHW_PRIMARY_HIGH_PRI_INT      = (8),
    INT_MUX_MACHW_PRIMARY_RX_INT            = (9),
    INT_MUX_MACHW_PRIMARY_TIMER_INT         = (10),
    INT_MUX_MACHW_PRIMARY_TX_INT            = (11),
    INT_MUX_PCIEW                           = (12),
    INT_MUX_I2C                             = (13),
    INT_MUX_IPC_PHY                         = (14),
    INT_MUX_UNUSED_INT0                     = (15), //Reserved
    INT_MUX_MACHW_SECOND_ERROR_INT          = (16), //Secondary - Both MU1 and MU2. For stations FPGA and Phase 1 only
    INT_MUX_MACHW_SECOND_GEN_INT            = (17), //Secondary - Both MU1 and MU2. For stations FPGA and Phase 1 only
    INT_MUX_MACHW_SECOND_HIGH_PRI_INT       = (18), //Seconadry - Both MU1 and MU2. For stations FPGA and Phase 1 only
    INT_MUX_MACHW_SECOND_RX_INT             = (19), //Seconadry - Both MU1 and MU2. For stations FPGA and Phase 1 only
    INT_MUX_MACHW_SECOND_TIMER_INT          = (20), //Seconadry - Both MU1 and MU2. For stations FPGA and Phase 1 only
    INT_MUX_MACHW_SECOND_TX_INT             = (21), //Seconadry - Both MU1 and MU2. For stations FPGA and Phase 1 only
    INT_MUX_UNUSED_INT1                     = (22), //Reserved
    INT_MUX_UNUSED_INT2                     = (23), //Reserved
    INT_MUX_UNUSED_INT3                     = (24), //Reserved
    INT_MUX_UNUSED_INT                      = (25), //Reserved

    // Always keep this entry last
    INT_MUX_MAX

} int_mux_line_e;
#endif // (CE_HW_VERSION >= HW_8000_STEP_A0)

/*
 * FUNCTION DECLARATIONS
 ****************************************************************************************
 */
/**
 ****************************************************************************************
 * @brief Initialize and configure the reference INTCTRL.
 * This function configures the INTC according to the system needs.
 ****************************************************************************************
 */

//void intc_init(void);
//decleration of tensilica exception handlers
void exc_handler_IllegalInstruction();
void exc_handler_InstructionFetchError();
void exc_handler_LoadStoreError();
void exc_handler_IntegerDivideByZero();
void exc_handler_Speculation();
void exc_handler_Privileged();
void exc_handler_Unaligned();
void exc_handler_InstTLBMiss();
void exc_handler_InstTLBMultiHit();
void exc_handler_InstFetchPrivilege();
void exc_handler_InstFetchProhibited();
void exc_handler_LoadStoreTLBMiss();
void exc_handler_LoadStoreTLBMultiHit();
void exc_handler_LoadStorePrivilege();
void exc_handler_LoadProhibited();
void exc_handler_StoreProhibited();
/*
/// IRQ handler.
__IRQ void intc_irq(void);

/// FIQ handler.
__FIQ void intc_fiq(void);
*/

/// @}

#endif // _INTC_H_
