#ifndef _REG_UART_H_
#define _REG_UART_H_

#include <stdint.h>
#include "_reg_uart.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define DBG_FILEID __REG_UART__H__FILEID__

#define REG_UART_COUNT  15


/**
 * @brief RHR register definition
 *  Receive Holding Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 Rx_Data                   0x0
 * </pre>
 */
#define UART_RHR_ADDR        (REG_UART_BASE_ADDR+0x00000000)
#define UART_RHR_OFFSET      0x00000000
#define UART_RHR_INDEX       0x00000000
#define UART_RHR_RESET       0x00000000

__INLINE uint32_t  uart_rhr_get(void)
{
	return REG_PL_RD(UART_RHR_ADDR);
}

// field definitions
#define UART_RHR_RX_DATA_MASK               ((uint32_t)0x000000FF)
#define UART_RHR_RX_DATA_LSB                0
#define UART_RHR_RX_DATA_WIDTH              ((uint32_t)0x00000008)

#define UART_RHR_RX_DATA_RST                0x0

__INLINE uint8_t uart_rhr_rx_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_RHR_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief THR register definition
 *  Transmit Holding Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 Tx_Data                   0x0
 * </pre>
 */
#define UART_THR_ADDR        (REG_UART_BASE_ADDR+0x00000004)
#define UART_THR_OFFSET      0x00000004
#define UART_THR_INDEX       0x00000001
#define UART_THR_RESET       0x00000000

__INLINE uint32_t  uart_thr_get(void)
{
	return REG_PL_RD(UART_THR_ADDR);
}

__INLINE void uart_thr_set(uint32_t value)
{
	REG_PL_WR(UART_THR_ADDR, value);
}

// field definitions
#define UART_THR_TX_DATA_MASK               ((uint32_t)0x000000FF)
#define UART_THR_TX_DATA_LSB                0
#define UART_THR_TX_DATA_WIDTH              ((uint32_t)0x00000008)

#define UART_THR_TX_DATA_RST                0x0

__INLINE uint8_t uart_thr_tx_data_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_THR_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void uart_thr_tx_data_setf(uint8_t txdata)
{
	ASSERT_ERR((((uint32_t)txdata << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(UART_THR_ADDR, (uint32_t)txdata << 0);
}

/**
 * @brief D_LSB register definition
 *  Baud Divisor Least Significant Byte register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 D_LSB                     0x0
 * </pre>
 */
#define UART_D_LSB_ADDR        (REG_UART_BASE_ADDR+0x00000008)
#define UART_D_LSB_OFFSET      0x00000008
#define UART_D_LSB_INDEX       0x00000002
#define UART_D_LSB_RESET       0x00000000

__INLINE uint32_t  uart_d_lsb_get(void)
{
	return REG_PL_RD(UART_D_LSB_ADDR);
}

__INLINE void uart_d_lsb_set(uint32_t value)
{
	REG_PL_WR(UART_D_LSB_ADDR, value);
}

// field definitions
#define UART_D_LSB_D_LSB_MASK               ((uint32_t)0x000000FF)
#define UART_D_LSB_D_LSB_LSB                0
#define UART_D_LSB_D_LSB_WIDTH              ((uint32_t)0x00000008)

#define UART_D_LSB_D_LSB_RST                0x0

__INLINE uint8_t uart_d_lsb_d_lsb_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_D_LSB_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void uart_d_lsb_d_lsb_setf(uint8_t dlsb)
{
	ASSERT_ERR((((uint32_t)dlsb << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(UART_D_LSB_ADDR, (uint32_t)dlsb << 0);
}

/**
 * @brief D_MSB register definition
 *  Baud Divisor Most Significant Byte register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 D_MSB                     0x0
 * </pre>
 */
#define UART_D_MSB_ADDR        (REG_UART_BASE_ADDR+0x0000000C)
#define UART_D_MSB_OFFSET      0x0000000C
#define UART_D_MSB_INDEX       0x00000003
#define UART_D_MSB_RESET       0x00000000

__INLINE uint32_t  uart_d_msb_get(void)
{
	return REG_PL_RD(UART_D_MSB_ADDR);
}

__INLINE void uart_d_msb_set(uint32_t value)
{
	REG_PL_WR(UART_D_MSB_ADDR, value);
}

// field definitions
#define UART_D_MSB_D_MSB_MASK               ((uint32_t)0x000000FF)
#define UART_D_MSB_D_MSB_LSB                0
#define UART_D_MSB_D_MSB_WIDTH              ((uint32_t)0x00000008)

#define UART_D_MSB_D_MSB_RST                0x0

__INLINE uint8_t uart_d_msb_d_msb_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_D_MSB_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void uart_d_msb_d_msb_setf(uint8_t dmsb)
{
	ASSERT_ERR((((uint32_t)dmsb << 0) & ~((uint32_t)0x000000FF)) == 0);
	REG_PL_WR(UART_D_MSB_ADDR, (uint32_t)dmsb << 0);
}

/**
 * @brief ISR register definition
 *  Interrupt Status Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    03:01 Interrupt_ID              0x0
 *    00    Intr_Pending              1              
 * </pre>
 */
#define UART_ISR_ADDR        (REG_UART_BASE_ADDR+0x00000010)
#define UART_ISR_OFFSET      0x00000010
#define UART_ISR_INDEX       0x00000004
#define UART_ISR_RESET       0x00000001

__INLINE uint32_t  uart_isr_get(void)
{
	return REG_PL_RD(UART_ISR_ADDR);
}

// field definitions
#define UART_ISR_INTERRUPT_ID_MASK          ((uint32_t)0x0000000E)
#define UART_ISR_INTERRUPT_ID_LSB           1
#define UART_ISR_INTERRUPT_ID_WIDTH         ((uint32_t)0x00000003)
#define UART_ISR_INTR_PENDING_BIT           ((uint32_t)0x00000001)
#define UART_ISR_INTR_PENDING_POS           0

#define UART_ISR_INTERRUPT_ID_RST           0x0
#define UART_ISR_INTR_PENDING_RST           0x1

__INLINE void uart_isr_unpack(uint8_t* interrupt_id, uint8_t* intr_pending)
{
	uint32_t localVal = REG_PL_RD(UART_ISR_ADDR);

	*interrupt_id = (localVal & ((uint32_t)0x0000000E)) >>  1;
	*intr_pending = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t uart_isr_interrupt_id_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_ISR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000000E)) >> 1);
}
__INLINE uint8_t uart_isr_intr_pending_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_ISR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief IER register definition
 *  Interrupt Enable Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    Intr_Rst                  0              
 *    06:04 RESERVED                  0x0
 *    03    Modem_Intr_Enb            0              
 *    02    Rx_Ln_Status_Intr_Enb     0              
 *    01    Tx_Fifo_Empty_Intr        0              
 *    00    Rx_Rdy_TOIntr             0              
 * </pre>
 */
#define UART_IER_ADDR        (REG_UART_BASE_ADDR+0x00000014)
#define UART_IER_OFFSET      0x00000014
#define UART_IER_INDEX       0x00000005
#define UART_IER_RESET       0x00000000

__INLINE uint32_t  uart_ier_get(void)
{
	return REG_PL_RD(UART_IER_ADDR);
}

__INLINE void uart_ier_set(uint32_t value)
{
	REG_PL_WR(UART_IER_ADDR, value);
}

// field definitions
#define UART_IER_INTR_RST_BIT               ((uint32_t)0x00000080)
#define UART_IER_INTR_RST_POS               7
#define UART_IER_RESERVED_MASK              ((uint32_t)0x00000070)
#define UART_IER_RESERVED_LSB               4
#define UART_IER_RESERVED_WIDTH             ((uint32_t)0x00000003)
#define UART_IER_MODEM_INTR_ENB_BIT         ((uint32_t)0x00000008)
#define UART_IER_MODEM_INTR_ENB_POS         3
#define UART_IER_RX_LN_STATUS_INTR_ENB_BIT    ((uint32_t)0x00000004)
#define UART_IER_RX_LN_STATUS_INTR_ENB_POS    2
#define UART_IER_TX_FIFO_EMPTY_INTR_BIT     ((uint32_t)0x00000002)
#define UART_IER_TX_FIFO_EMPTY_INTR_POS     1
#define UART_IER_RX_RDY_TOINTR_BIT          ((uint32_t)0x00000001)
#define UART_IER_RX_RDY_TOINTR_POS          0

#define UART_IER_INTR_RST_RST               0x0
#define UART_IER_RESERVED_RST               0x0
#define UART_IER_MODEM_INTR_ENB_RST         0x0
#define UART_IER_RX_LN_STATUS_INTR_ENB_RST    0x0
#define UART_IER_TX_FIFO_EMPTY_INTR_RST     0x0
#define UART_IER_RX_RDY_TOINTR_RST          0x0

__INLINE void uart_ier_pack(uint8_t intr_rst, uint8_t reserved, uint8_t modem_intr_enb, uint8_t rx_ln_status_intr_enb, uint8_t tx_fifo_empty_intr, uint8_t rx_rdy_tointr)
{
	ASSERT_ERR((((uint32_t)intr_rst << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)reserved << 4) & ~((uint32_t)0x00000070)) == 0);
	ASSERT_ERR((((uint32_t)modem_intr_enb << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)rx_ln_status_intr_enb << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)tx_fifo_empty_intr << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rx_rdy_tointr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(UART_IER_ADDR,  ((uint32_t)intr_rst << 7) |((uint32_t)reserved << 4) |((uint32_t)modem_intr_enb << 3) |((uint32_t)rx_ln_status_intr_enb << 2) |((uint32_t)tx_fifo_empty_intr << 1) |((uint32_t)rx_rdy_tointr << 0));
}

__INLINE void uart_ier_unpack(uint8_t* intr_rst, uint8_t* reserved, uint8_t* modem_intr_enb, uint8_t* rx_ln_status_intr_enb, uint8_t* tx_fifo_empty_intr, uint8_t* rx_rdy_tointr)
{
	uint32_t localVal = REG_PL_RD(UART_IER_ADDR);

	*intr_rst = (localVal & ((uint32_t)0x00000080)) >>  7;
	*reserved = (localVal & ((uint32_t)0x00000070)) >>  4;
	*modem_intr_enb = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rx_ln_status_intr_enb = (localVal & ((uint32_t)0x00000004)) >>  2;
	*tx_fifo_empty_intr = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rx_rdy_tointr = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE void uart_ier_intr_rst_setf(uint8_t intrrst)
{
	ASSERT_ERR((((uint32_t)intrrst << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)intrrst <<7));
}
__INLINE uint8_t uart_ier_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_IER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000070)) >> 4);
}
__INLINE void uart_ier_reserved_setf(uint8_t reserved)
{
	ASSERT_ERR((((uint32_t)reserved << 4) & ~((uint32_t)0x00000070)) == 0);
	REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)reserved <<4));
}
__INLINE uint8_t uart_ier_modem_intr_enb_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_IER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void uart_ier_modem_intr_enb_setf(uint8_t modemintrenb)
{
	ASSERT_ERR((((uint32_t)modemintrenb << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)modemintrenb <<3));
}
__INLINE uint8_t uart_ier_rx_ln_status_intr_enb_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_IER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void uart_ier_rx_ln_status_intr_enb_setf(uint8_t rxlnstatusintrenb)
{
	ASSERT_ERR((((uint32_t)rxlnstatusintrenb << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)rxlnstatusintrenb <<2));
}
__INLINE uint8_t uart_ier_tx_fifo_empty_intr_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_IER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void uart_ier_tx_fifo_empty_intr_setf(uint8_t txfifoemptyintr)
{
	ASSERT_ERR((((uint32_t)txfifoemptyintr << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)txfifoemptyintr <<1));
}
__INLINE uint8_t uart_ier_rx_rdy_tointr_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_IER_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void uart_ier_rx_rdy_tointr_setf(uint8_t rxrdytointr)
{
	ASSERT_ERR((((uint32_t)rxrdytointr << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(UART_IER_ADDR, (REG_PL_RD(UART_IER_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxrdytointr <<0));
}

/**
 * @brief LCR register definition
 *  Line Control Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    06    Tx_Break_Enbl             0              
 *    05    Tx_Rx_Force_Parity_Sel    0              
 *    04    Tx_Rx_Even_Odd_Parity_Sel 0              
 *    03    Tx_Rx_Parity_Enbl         0              
 *    02    Tx_Rx_Stop_Bits           0              
 *    01:00 Tx_Rx_Char_Length         0x0
 * </pre>
 */
#define UART_LCR_ADDR        (REG_UART_BASE_ADDR+0x00000018)
#define UART_LCR_OFFSET      0x00000018
#define UART_LCR_INDEX       0x00000006
#define UART_LCR_RESET       0x00000000

__INLINE uint32_t  uart_lcr_get(void)
{
	return REG_PL_RD(UART_LCR_ADDR);
}

__INLINE void uart_lcr_set(uint32_t value)
{
	REG_PL_WR(UART_LCR_ADDR, value);
}

// field definitions
#define UART_LCR_TX_BREAK_ENBL_BIT          ((uint32_t)0x00000040)
#define UART_LCR_TX_BREAK_ENBL_POS          6
#define UART_LCR_TX_RX_FORCE_PARITY_SEL_BIT    ((uint32_t)0x00000020)
#define UART_LCR_TX_RX_FORCE_PARITY_SEL_POS    5
#define UART_LCR_TX_RX_EVEN_ODD_PARITY_SEL_BIT    ((uint32_t)0x00000010)
#define UART_LCR_TX_RX_EVEN_ODD_PARITY_SEL_POS    4
#define UART_LCR_TX_RX_PARITY_ENBL_BIT      ((uint32_t)0x00000008)
#define UART_LCR_TX_RX_PARITY_ENBL_POS      3
#define UART_LCR_TX_RX_STOP_BITS_BIT        ((uint32_t)0x00000004)
#define UART_LCR_TX_RX_STOP_BITS_POS        2
#define UART_LCR_TX_RX_CHAR_LENGTH_MASK     ((uint32_t)0x00000003)
#define UART_LCR_TX_RX_CHAR_LENGTH_LSB      0
#define UART_LCR_TX_RX_CHAR_LENGTH_WIDTH    ((uint32_t)0x00000002)

#define UART_LCR_TX_BREAK_ENBL_RST          0x0
#define UART_LCR_TX_RX_FORCE_PARITY_SEL_RST    0x0
#define UART_LCR_TX_RX_EVEN_ODD_PARITY_SEL_RST    0x0
#define UART_LCR_TX_RX_PARITY_ENBL_RST      0x0
#define UART_LCR_TX_RX_STOP_BITS_RST        0x0
#define UART_LCR_TX_RX_CHAR_LENGTH_RST      0x0

__INLINE void uart_lcr_pack(uint8_t tx_break_enbl, uint8_t tx_rx_force_parity_sel, uint8_t tx_rx_even_odd_parity_sel, uint8_t tx_rx_parity_enbl, uint8_t tx_rx_stop_bits, uint8_t tx_rx_char_length)
{
	ASSERT_ERR((((uint32_t)tx_break_enbl << 6) & ~((uint32_t)0x00000040)) == 0);
	ASSERT_ERR((((uint32_t)tx_rx_force_parity_sel << 5) & ~((uint32_t)0x00000020)) == 0);
	ASSERT_ERR((((uint32_t)tx_rx_even_odd_parity_sel << 4) & ~((uint32_t)0x00000010)) == 0);
	ASSERT_ERR((((uint32_t)tx_rx_parity_enbl << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)tx_rx_stop_bits << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)tx_rx_char_length << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(UART_LCR_ADDR,  ((uint32_t)tx_break_enbl << 6) |((uint32_t)tx_rx_force_parity_sel << 5) |((uint32_t)tx_rx_even_odd_parity_sel << 4) |((uint32_t)tx_rx_parity_enbl << 3) |((uint32_t)tx_rx_stop_bits << 2) |((uint32_t)tx_rx_char_length << 0));
}

__INLINE void uart_lcr_unpack(uint8_t* tx_break_enbl, uint8_t* tx_rx_force_parity_sel, uint8_t* tx_rx_even_odd_parity_sel, uint8_t* tx_rx_parity_enbl, uint8_t* tx_rx_stop_bits, uint8_t* tx_rx_char_length)
{
	uint32_t localVal = REG_PL_RD(UART_LCR_ADDR);

	*tx_break_enbl = (localVal & ((uint32_t)0x00000040)) >>  6;
	*tx_rx_force_parity_sel = (localVal & ((uint32_t)0x00000020)) >>  5;
	*tx_rx_even_odd_parity_sel = (localVal & ((uint32_t)0x00000010)) >>  4;
	*tx_rx_parity_enbl = (localVal & ((uint32_t)0x00000008)) >>  3;
	*tx_rx_stop_bits = (localVal & ((uint32_t)0x00000004)) >>  2;
	*tx_rx_char_length = (localVal & ((uint32_t)0x00000003)) >>  0;
}

__INLINE uint8_t uart_lcr_tx_break_enbl_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE void uart_lcr_tx_break_enbl_setf(uint8_t txbreakenbl)
{
	ASSERT_ERR((((uint32_t)txbreakenbl << 6) & ~((uint32_t)0x00000040)) == 0);
	REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000040)) | ((uint32_t)txbreakenbl <<6));
}
__INLINE uint8_t uart_lcr_tx_rx_force_parity_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE void uart_lcr_tx_rx_force_parity_sel_setf(uint8_t txrxforceparitysel)
{
	ASSERT_ERR((((uint32_t)txrxforceparitysel << 5) & ~((uint32_t)0x00000020)) == 0);
	REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000020)) | ((uint32_t)txrxforceparitysel <<5));
}
__INLINE uint8_t uart_lcr_tx_rx_even_odd_parity_sel_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE void uart_lcr_tx_rx_even_odd_parity_sel_setf(uint8_t txrxevenoddparitysel)
{
	ASSERT_ERR((((uint32_t)txrxevenoddparitysel << 4) & ~((uint32_t)0x00000010)) == 0);
	REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000010)) | ((uint32_t)txrxevenoddparitysel <<4));
}
__INLINE uint8_t uart_lcr_tx_rx_parity_enbl_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void uart_lcr_tx_rx_parity_enbl_setf(uint8_t txrxparityenbl)
{
	ASSERT_ERR((((uint32_t)txrxparityenbl << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)txrxparityenbl <<3));
}
__INLINE uint8_t uart_lcr_tx_rx_stop_bits_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE void uart_lcr_tx_rx_stop_bits_setf(uint8_t txrxstopbits)
{
	ASSERT_ERR((((uint32_t)txrxstopbits << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)txrxstopbits <<2));
}
__INLINE uint8_t uart_lcr_tx_rx_char_length_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000003)) >> 0);
}
__INLINE void uart_lcr_tx_rx_char_length_setf(uint8_t txrxcharlength)
{
	ASSERT_ERR((((uint32_t)txrxcharlength << 0) & ~((uint32_t)0x00000003)) == 0);
	REG_PL_WR(UART_LCR_ADDR, (REG_PL_RD(UART_LCR_ADDR) & ~((uint32_t)0x00000003)) | ((uint32_t)txrxcharlength <<0));
}

/**
 * @brief FCR register definition
 *  FIFO Control Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:06 Rx_FIFOTrigger            0x0
 *    05:04 Tx_FIFOTrigger            0x0
 *    03    RESERVED                  0              
 *    02    Tx_FIFOReset              0              
 *    01    Rx_FIFOReset              0              
 *    00    Rx_Tx_FIFOEnb             0              
 * </pre>
 */
#define UART_FCR_ADDR        (REG_UART_BASE_ADDR+0x0000001C)
#define UART_FCR_OFFSET      0x0000001C
#define UART_FCR_INDEX       0x00000007
#define UART_FCR_RESET       0x00000000

__INLINE uint32_t  uart_fcr_get(void)
{
	return REG_PL_RD(UART_FCR_ADDR);
}

__INLINE void uart_fcr_set(uint32_t value)
{
	REG_PL_WR(UART_FCR_ADDR, value);
}

// field definitions
#define UART_FCR_RX_FIFOTRIGGER_MASK        ((uint32_t)0x000000C0)
#define UART_FCR_RX_FIFOTRIGGER_LSB         6
#define UART_FCR_RX_FIFOTRIGGER_WIDTH       ((uint32_t)0x00000002)
#define UART_FCR_TX_FIFOTRIGGER_MASK        ((uint32_t)0x00000030)
#define UART_FCR_TX_FIFOTRIGGER_LSB         4
#define UART_FCR_TX_FIFOTRIGGER_WIDTH       ((uint32_t)0x00000002)
#define UART_FCR_RESERVED_BIT               ((uint32_t)0x00000008)
#define UART_FCR_RESERVED_POS               3
#define UART_FCR_TX_FIFORESET_BIT           ((uint32_t)0x00000004)
#define UART_FCR_TX_FIFORESET_POS           2
#define UART_FCR_RX_FIFORESET_BIT           ((uint32_t)0x00000002)
#define UART_FCR_RX_FIFORESET_POS           1
#define UART_FCR_RX_TX_FIFOENB_BIT          ((uint32_t)0x00000001)
#define UART_FCR_RX_TX_FIFOENB_POS          0

#define UART_FCR_RX_FIFOTRIGGER_RST         0x0
#define UART_FCR_TX_FIFOTRIGGER_RST         0x0
#define UART_FCR_RESERVED_RST               0x0
#define UART_FCR_TX_FIFORESET_RST           0x0
#define UART_FCR_RX_FIFORESET_RST           0x0
#define UART_FCR_RX_TX_FIFOENB_RST          0x0

__INLINE void uart_fcr_pack(uint8_t rx_fifotrigger, uint8_t tx_fifotrigger, uint8_t reserved, uint8_t tx_fiforeset, uint8_t rx_fiforeset, uint8_t rx_tx_fifoenb)
{
	ASSERT_ERR((((uint32_t)rx_fifotrigger << 6) & ~((uint32_t)0x000000C0)) == 0);
	ASSERT_ERR((((uint32_t)tx_fifotrigger << 4) & ~((uint32_t)0x00000030)) == 0);
	ASSERT_ERR((((uint32_t)reserved << 3) & ~((uint32_t)0x00000008)) == 0);
	ASSERT_ERR((((uint32_t)tx_fiforeset << 2) & ~((uint32_t)0x00000004)) == 0);
	ASSERT_ERR((((uint32_t)rx_fiforeset << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)rx_tx_fifoenb << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(UART_FCR_ADDR,  ((uint32_t)rx_fifotrigger << 6) |((uint32_t)tx_fifotrigger << 4) |((uint32_t)reserved << 3) |((uint32_t)tx_fiforeset << 2) |((uint32_t)rx_fiforeset << 1) |((uint32_t)rx_tx_fifoenb << 0));
}

__INLINE void uart_fcr_unpack(uint8_t* rx_fifotrigger, uint8_t* tx_fifotrigger, uint8_t* reserved, uint8_t* tx_fiforeset, uint8_t* rx_fiforeset, uint8_t* rx_tx_fifoenb)
{
	uint32_t localVal = REG_PL_RD(UART_FCR_ADDR);

	*rx_fifotrigger = (localVal & ((uint32_t)0x000000C0)) >>  6;
	*tx_fifotrigger = (localVal & ((uint32_t)0x00000030)) >>  4;
	*reserved = (localVal & ((uint32_t)0x00000008)) >>  3;
	*tx_fiforeset = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rx_fiforeset = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rx_tx_fifoenb = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t uart_fcr_rx_fifotrigger_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_FCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x000000C0)) >> 6);
}
__INLINE void uart_fcr_rx_fifotrigger_setf(uint8_t rxfifotrigger)
{
	ASSERT_ERR((((uint32_t)rxfifotrigger << 6) & ~((uint32_t)0x000000C0)) == 0);
	REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x000000C0)) | ((uint32_t)rxfifotrigger <<6));
}
__INLINE uint8_t uart_fcr_tx_fifotrigger_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_FCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000030)) >> 4);
}
__INLINE void uart_fcr_tx_fifotrigger_setf(uint8_t txfifotrigger)
{
	ASSERT_ERR((((uint32_t)txfifotrigger << 4) & ~((uint32_t)0x00000030)) == 0);
	REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000030)) | ((uint32_t)txfifotrigger <<4));
}
__INLINE uint8_t uart_fcr_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_FCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE void uart_fcr_reserved_setf(uint8_t reserved)
{
	ASSERT_ERR((((uint32_t)reserved << 3) & ~((uint32_t)0x00000008)) == 0);
	REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)reserved <<3));
}
__INLINE void uart_fcr_tx_fiforeset_setf(uint8_t txfiforeset)
{
	ASSERT_ERR((((uint32_t)txfiforeset << 2) & ~((uint32_t)0x00000004)) == 0);
	REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)txfiforeset <<2));
}
__INLINE void uart_fcr_rx_fiforeset_setf(uint8_t rxfiforeset)
{
	ASSERT_ERR((((uint32_t)rxfiforeset << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rxfiforeset <<1));
}
__INLINE uint8_t uart_fcr_rx_tx_fifoenb_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_FCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void uart_fcr_rx_tx_fifoenb_setf(uint8_t rxtxfifoenb)
{
	ASSERT_ERR((((uint32_t)rxtxfifoenb << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(UART_FCR_ADDR, (REG_PL_RD(UART_FCR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)rxtxfifoenb <<0));
}

/**
 * @brief MCR register definition
 *  Modem Control Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    Rts_Enbl                  0              
 *    06:02 RESERVED                  0x0
 *    01    RTSn                      1              
 *    00    DTRn                      1              
 * </pre>
 */
#define UART_MCR_ADDR        (REG_UART_BASE_ADDR+0x00000020)
#define UART_MCR_OFFSET      0x00000020
#define UART_MCR_INDEX       0x00000008
#define UART_MCR_RESET       0x00000003

__INLINE uint32_t  uart_mcr_get(void)
{
	return REG_PL_RD(UART_MCR_ADDR);
}

__INLINE void uart_mcr_set(uint32_t value)
{
	REG_PL_WR(UART_MCR_ADDR, value);
}

// field definitions
#define UART_MCR_RTS_ENBL_BIT               ((uint32_t)0x00000080)
#define UART_MCR_RTS_ENBL_POS               7
#define UART_MCR_RESERVED_MASK              ((uint32_t)0x0000007C)
#define UART_MCR_RESERVED_LSB               2
#define UART_MCR_RESERVED_WIDTH             ((uint32_t)0x00000005)
#define UART_MCR_RTSN_BIT                   ((uint32_t)0x00000002)
#define UART_MCR_RTSN_POS                   1
#define UART_MCR_DTRN_BIT                   ((uint32_t)0x00000001)
#define UART_MCR_DTRN_POS                   0

#define UART_MCR_RTS_ENBL_RST               0x0
#define UART_MCR_RESERVED_RST               0x0
#define UART_MCR_RTSN_RST                   0x1
#define UART_MCR_DTRN_RST                   0x1

__INLINE void uart_mcr_pack(uint8_t rts_enbl, uint8_t reserved, uint8_t rtsn, uint8_t dtrn)
{
	ASSERT_ERR((((uint32_t)rts_enbl << 7) & ~((uint32_t)0x00000080)) == 0);
	ASSERT_ERR((((uint32_t)reserved << 2) & ~((uint32_t)0x0000007C)) == 0);
	ASSERT_ERR((((uint32_t)rtsn << 1) & ~((uint32_t)0x00000002)) == 0);
	ASSERT_ERR((((uint32_t)dtrn << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(UART_MCR_ADDR,  ((uint32_t)rts_enbl << 7) |((uint32_t)reserved << 2) |((uint32_t)rtsn << 1) |((uint32_t)dtrn << 0));
}

__INLINE void uart_mcr_unpack(uint8_t* rts_enbl, uint8_t* reserved, uint8_t* rtsn, uint8_t* dtrn)
{
	uint32_t localVal = REG_PL_RD(UART_MCR_ADDR);

	*rts_enbl = (localVal & ((uint32_t)0x00000080)) >>  7;
	*reserved = (localVal & ((uint32_t)0x0000007C)) >>  2;
	*rtsn = (localVal & ((uint32_t)0x00000002)) >>  1;
	*dtrn = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t uart_mcr_rts_enbl_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE void uart_mcr_rts_enbl_setf(uint8_t rtsenbl)
{
	ASSERT_ERR((((uint32_t)rtsenbl << 7) & ~((uint32_t)0x00000080)) == 0);
	REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000080)) | ((uint32_t)rtsenbl <<7));
}
__INLINE uint8_t uart_mcr_reserved_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x0000007C)) >> 2);
}
__INLINE void uart_mcr_reserved_setf(uint8_t reserved)
{
	ASSERT_ERR((((uint32_t)reserved << 2) & ~((uint32_t)0x0000007C)) == 0);
	REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x0000007C)) | ((uint32_t)reserved <<2));
}
__INLINE uint8_t uart_mcr_rtsn_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE void uart_mcr_rtsn_setf(uint8_t rtsn)
{
	ASSERT_ERR((((uint32_t)rtsn << 1) & ~((uint32_t)0x00000002)) == 0);
	REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)rtsn <<1));
}
__INLINE uint8_t uart_mcr_dtrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MCR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}
__INLINE void uart_mcr_dtrn_setf(uint8_t dtrn)
{
	ASSERT_ERR((((uint32_t)dtrn << 0) & ~((uint32_t)0x00000001)) == 0);
	REG_PL_WR(UART_MCR_ADDR, (REG_PL_RD(UART_MCR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)dtrn <<0));
}

/**
 * @brief LSR register definition
 *  Line Status Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04    Rx_Break_Flag             0              
 *    03    Rx_Frame_Error_Flag       0              
 *    02    Rx_Parity_Error           0              
 *    01    Rx_Over_Run_Flag          0              
 *    00    Rxd_Rdy                   0              
 * </pre>
 */
#define UART_LSR_ADDR        (REG_UART_BASE_ADDR+0x00000024)
#define UART_LSR_OFFSET      0x00000024
#define UART_LSR_INDEX       0x00000009
#define UART_LSR_RESET       0x00000000

__INLINE uint32_t  uart_lsr_get(void)
{
	return REG_PL_RD(UART_LSR_ADDR);
}

// field definitions
#define UART_LSR_RX_BREAK_FLAG_BIT          ((uint32_t)0x00000010)
#define UART_LSR_RX_BREAK_FLAG_POS          4
#define UART_LSR_RX_FRAME_ERROR_FLAG_BIT    ((uint32_t)0x00000008)
#define UART_LSR_RX_FRAME_ERROR_FLAG_POS    3
#define UART_LSR_RX_PARITY_ERROR_BIT        ((uint32_t)0x00000004)
#define UART_LSR_RX_PARITY_ERROR_POS        2
#define UART_LSR_RX_OVER_RUN_FLAG_BIT       ((uint32_t)0x00000002)
#define UART_LSR_RX_OVER_RUN_FLAG_POS       1
#define UART_LSR_RXD_RDY_BIT                ((uint32_t)0x00000001)
#define UART_LSR_RXD_RDY_POS                0

#define UART_LSR_RX_BREAK_FLAG_RST          0x0
#define UART_LSR_RX_FRAME_ERROR_FLAG_RST    0x0
#define UART_LSR_RX_PARITY_ERROR_RST        0x0
#define UART_LSR_RX_OVER_RUN_FLAG_RST       0x0
#define UART_LSR_RXD_RDY_RST                0x0

__INLINE void uart_lsr_unpack(uint8_t* rx_break_flag, uint8_t* rx_frame_error_flag, uint8_t* rx_parity_error, uint8_t* rx_over_run_flag, uint8_t* rxd_rdy)
{
	uint32_t localVal = REG_PL_RD(UART_LSR_ADDR);

	*rx_break_flag = (localVal & ((uint32_t)0x00000010)) >>  4;
	*rx_frame_error_flag = (localVal & ((uint32_t)0x00000008)) >>  3;
	*rx_parity_error = (localVal & ((uint32_t)0x00000004)) >>  2;
	*rx_over_run_flag = (localVal & ((uint32_t)0x00000002)) >>  1;
	*rxd_rdy = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t uart_lsr_rx_break_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t uart_lsr_rx_frame_error_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t uart_lsr_rx_parity_error_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t uart_lsr_rx_over_run_flag_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t uart_lsr_rxd_rdy_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_LSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief MSR register definition
 *  Modem Status Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07    CDStaus                   1              
 *    06    RIStatus                  0              
 *    05    DSRStatus                 0              
 *    04    CTSStatus                 0              
 *    03    Delta_CDn                 1              
 *    02    Delta_RI                  1              
 *    01    Delta_DSRn                0              
 *    00    Delta_CTSn                0              
 * </pre>
 */
#define UART_MSR_ADDR        (REG_UART_BASE_ADDR+0x00000028)
#define UART_MSR_OFFSET      0x00000028
#define UART_MSR_INDEX       0x0000000A
#define UART_MSR_RESET       0x0000008C

__INLINE uint32_t  uart_msr_get(void)
{
	return REG_PL_RD(UART_MSR_ADDR);
}

// field definitions
#define UART_MSR_CDSTAUS_BIT                ((uint32_t)0x00000080)
#define UART_MSR_CDSTAUS_POS                7
#define UART_MSR_RISTATUS_BIT               ((uint32_t)0x00000040)
#define UART_MSR_RISTATUS_POS               6
#define UART_MSR_DSRSTATUS_BIT              ((uint32_t)0x00000020)
#define UART_MSR_DSRSTATUS_POS              5
#define UART_MSR_CTSSTATUS_BIT              ((uint32_t)0x00000010)
#define UART_MSR_CTSSTATUS_POS              4
#define UART_MSR_DELTA_CDN_BIT              ((uint32_t)0x00000008)
#define UART_MSR_DELTA_CDN_POS              3
#define UART_MSR_DELTA_RI_BIT               ((uint32_t)0x00000004)
#define UART_MSR_DELTA_RI_POS               2
#define UART_MSR_DELTA_DSRN_BIT             ((uint32_t)0x00000002)
#define UART_MSR_DELTA_DSRN_POS             1
#define UART_MSR_DELTA_CTSN_BIT             ((uint32_t)0x00000001)
#define UART_MSR_DELTA_CTSN_POS             0

#define UART_MSR_CDSTAUS_RST                0x1
#define UART_MSR_RISTATUS_RST               0x0
#define UART_MSR_DSRSTATUS_RST              0x0
#define UART_MSR_CTSSTATUS_RST              0x0
#define UART_MSR_DELTA_CDN_RST              0x1
#define UART_MSR_DELTA_RI_RST               0x1
#define UART_MSR_DELTA_DSRN_RST             0x0
#define UART_MSR_DELTA_CTSN_RST             0x0

__INLINE void uart_msr_unpack(uint8_t* cdstaus, uint8_t* ristatus, uint8_t* dsrstatus, uint8_t* ctsstatus, uint8_t* delta_cdn, uint8_t* delta_ri, uint8_t* delta_dsrn, uint8_t* delta_ctsn)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);

	*cdstaus = (localVal & ((uint32_t)0x00000080)) >>  7;
	*ristatus = (localVal & ((uint32_t)0x00000040)) >>  6;
	*dsrstatus = (localVal & ((uint32_t)0x00000020)) >>  5;
	*ctsstatus = (localVal & ((uint32_t)0x00000010)) >>  4;
	*delta_cdn = (localVal & ((uint32_t)0x00000008)) >>  3;
	*delta_ri = (localVal & ((uint32_t)0x00000004)) >>  2;
	*delta_dsrn = (localVal & ((uint32_t)0x00000002)) >>  1;
	*delta_ctsn = (localVal & ((uint32_t)0x00000001)) >>  0;
}

__INLINE uint8_t uart_msr_cdstaus_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000080)) >> 7);
}
__INLINE uint8_t uart_msr_ristatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000040)) >> 6);
}
__INLINE uint8_t uart_msr_dsrstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000020)) >> 5);
}
__INLINE uint8_t uart_msr_ctsstatus_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000010)) >> 4);
}
__INLINE uint8_t uart_msr_delta_cdn_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000008)) >> 3);
}
__INLINE uint8_t uart_msr_delta_ri_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000004)) >> 2);
}
__INLINE uint8_t uart_msr_delta_dsrn_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000002)) >> 1);
}
__INLINE uint8_t uart_msr_delta_ctsn_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_MSR_ADDR);
	return (uint8_t)((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief RX_FIFO_STAT register definition
 *  Rx-FIFO Status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 RX_FIFO_STATUS            0x0
 * </pre>
 */
#define UART_RX_FIFO_STAT_ADDR        (REG_UART_BASE_ADDR+0x0000002C)
#define UART_RX_FIFO_STAT_OFFSET      0x0000002C
#define UART_RX_FIFO_STAT_INDEX       0x0000000B
#define UART_RX_FIFO_STAT_RESET       0x00000000

__INLINE uint32_t  uart_rx_fifo_stat_get(void)
{
	return REG_PL_RD(UART_RX_FIFO_STAT_ADDR);
}

// field definitions
#define UART_RX_FIFO_STAT_RX_FIFO_STATUS_MASK    ((uint32_t)0x000000FF)
#define UART_RX_FIFO_STAT_RX_FIFO_STATUS_LSB    0
#define UART_RX_FIFO_STAT_RX_FIFO_STATUS_WIDTH    ((uint32_t)0x00000008)

#define UART_RX_FIFO_STAT_RX_FIFO_STATUS_RST    0x0

__INLINE uint8_t uart_rx_fifo_stat_rx_fifo_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_RX_FIFO_STAT_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief TX_FIFO_STAT register definition
 *  Tx_FIFO Status register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    07:00 TX_FIFO_STATUS            0x0
 * </pre>
 */
#define UART_TX_FIFO_STAT_ADDR        (REG_UART_BASE_ADDR+0x00000030)
#define UART_TX_FIFO_STAT_OFFSET      0x00000030
#define UART_TX_FIFO_STAT_INDEX       0x0000000C
#define UART_TX_FIFO_STAT_RESET       0x00000000

__INLINE uint32_t  uart_tx_fifo_stat_get(void)
{
	return REG_PL_RD(UART_TX_FIFO_STAT_ADDR);
}

// field definitions
#define UART_TX_FIFO_STAT_TX_FIFO_STATUS_MASK    ((uint32_t)0x000000FF)
#define UART_TX_FIFO_STAT_TX_FIFO_STATUS_LSB    0
#define UART_TX_FIFO_STAT_TX_FIFO_STATUS_WIDTH    ((uint32_t)0x00000008)

#define UART_TX_FIFO_STAT_TX_FIFO_STATUS_RST    0x0

__INLINE uint8_t uart_tx_fifo_stat_tx_fifo_status_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_TX_FIFO_STAT_ADDR);
	return (uint8_t)(localVal >> 0);
}

/**
 * @brief DIV_FRAC register definition
 *  Baud Divisor Fractional part register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 DIV_FRAC                  0x0
 * </pre>
 */
#define UART_DIV_FRAC_ADDR        (REG_UART_BASE_ADDR+0x00000034)
#define UART_DIV_FRAC_OFFSET      0x00000034
#define UART_DIV_FRAC_INDEX       0x0000000D
#define UART_DIV_FRAC_RESET       0x00000000

__INLINE uint32_t  uart_div_frac_get(void)
{
	return REG_PL_RD(UART_DIV_FRAC_ADDR);
}

__INLINE void uart_div_frac_set(uint32_t value)
{
	REG_PL_WR(UART_DIV_FRAC_ADDR, value);
}

// field definitions
#define UART_DIV_FRAC_DIV_FRAC_MASK         ((uint32_t)0x0000001F)
#define UART_DIV_FRAC_DIV_FRAC_LSB          0
#define UART_DIV_FRAC_DIV_FRAC_WIDTH        ((uint32_t)0x00000005)

#define UART_DIV_FRAC_DIV_FRAC_RST          0x0

__INLINE uint8_t uart_div_frac_div_frac_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_DIV_FRAC_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void uart_div_frac_div_frac_setf(uint8_t divfrac)
{
	ASSERT_ERR((((uint32_t)divfrac << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(UART_DIV_FRAC_ADDR, (uint32_t)divfrac << 0);
}

/**
 * @brief FCR_2 register definition
 *  FIFO Control 2 Register register description
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *    04:00 RX_FIFO_THRESHOLD         0x1
 * </pre>
 */
#define UART_FCR_2_ADDR        (REG_UART_BASE_ADDR+0x0000003C)
#define UART_FCR_2_OFFSET      0x0000003C
#define UART_FCR_2_INDEX       0x0000000F
#define UART_FCR_2_RESET       0x00000001

__INLINE uint32_t  uart_fcr_2_get(void)
{
	return REG_PL_RD(UART_FCR_2_ADDR);
}

__INLINE void uart_fcr_2_set(uint32_t value)
{
	REG_PL_WR(UART_FCR_2_ADDR, value);
}

// field definitions
#define UART_FCR_2_RX_FIFO_THRESHOLD_MASK    ((uint32_t)0x0000001F)
#define UART_FCR_2_RX_FIFO_THRESHOLD_LSB    0
#define UART_FCR_2_RX_FIFO_THRESHOLD_WIDTH    ((uint32_t)0x00000005)

#define UART_FCR_2_RX_FIFO_THRESHOLD_RST    0x1

__INLINE uint8_t uart_fcr_2_rx_fifo_threshold_getf(void)
{
	uint32_t localVal = REG_PL_RD(UART_FCR_2_ADDR);
	return (uint8_t)(localVal >> 0);
}
__INLINE void uart_fcr_2_rx_fifo_threshold_setf(uint8_t rxfifothreshold)
{
	ASSERT_ERR((((uint32_t)rxfifothreshold << 0) & ~((uint32_t)0x0000001F)) == 0);
	REG_PL_WR(UART_FCR_2_ADDR, (uint32_t)rxfifothreshold << 0);
}


#undef DBG_FILEID
#endif //_REG_UART_H_
