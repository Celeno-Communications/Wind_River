#ifndef _REG_PHY_OLYMPUS_CHX_REGISTERS_H_
#define _REG_PHY_OLYMPUS_CHX_REGISTERS_H_

#include "phy_hw.h"
#include "compiler.h"
/**
* @brief rxlnaen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               rxlnaen                     0.0           0xY0
* </pre>
*/
#define PHY_RF_RXLNAEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_y0_rxlnaen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNAEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_y0_rxlnaen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNAEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXLNAEN_ADDRESS, value_to_write);
}


/**
* @brief rxgmen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               rxgmen                      0.0           0xY0
* </pre>
*/
#define PHY_RF_RXGMEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_y0_rxgmen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGMEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y0_rxgmen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGMEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXGMEN_ADDRESS, value_to_write);
}


/**
* @brief rxbbbiasen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               rxbbbiasen                  0.0           0xY0
* </pre>
*/
#define PHY_RF_RXBBBIASEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_y0_rxbbbiasen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXBBBIASEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_rxbbbiasen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXBBBIASEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXBBBIASEN_ADDRESS, value_to_write);
}


/**
* @brief rxrfptaten register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               rxrfptaten                  0.0           0xY0
* </pre>
*/
#define PHY_RF_RXRFPTATEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_y0_rxrfptaten(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFPTATEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_rxrfptaten(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFPTATEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXRFPTATEN_ADDRESS, value_to_write);
}


/**
* @brief rxlnaopampbiassel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               rxlnaopampbiassel           0.0           0xY0
* </pre>
*/
#define PHY_RF_RXLNAOPAMPBIASSEL_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_y0_rxlnaopampbiassel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNAOPAMPBIASSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_y0_rxlnaopampbiassel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNAOPAMPBIASSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXLNAOPAMPBIASSEL_ADDRESS, value_to_write);
}


/**
* @brief rxgmopampbiassel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               rxgmopampbiassel            0.0           0xY0
* </pre>
*/
#define PHY_RF_RXGMOPAMPBIASSEL_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_y0_rxgmopampbiassel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGMOPAMPBIASSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_y0_rxgmopampbiassel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGMOPAMPBIASSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXGMOPAMPBIASSEL_ADDRESS, value_to_write);
}


/**
* @brief rxcascbiasset register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1:0             rxcascbiasset               0.0           0xY0
* </pre>
*/
#define PHY_RF_RXCASCBIASSET_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_y0_rxcascbiasset(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXCASCBIASSET_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_rxcascbiasset(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXCASCBIASSET_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXCASCBIASSET_ADDRESS, value_to_write);
}


/**
* @brief rxgmgain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             rxgmgain                    0             0xY0
* </pre>
*/
#define PHY_RF_RXGMGAIN_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_y0_rxgmgain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGMGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}


/**
* @brief rxlnagain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             rxlnagain                   0             0xY0
* </pre>
*/
#define PHY_RF_RXLNAGAIN_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_y0_rxlnagain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNAGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}


/**
* @brief rxlnaresctrl register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             rxlnaresctrl                0             0xY0
* </pre>
*/
#define PHY_RF_RXLNARESCTRL_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_y0_rxlnaresctrl(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNARESCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}


/**
* @brief rxlnacurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             rxlnacurrsel                0             0xY0
* </pre>
*/
#define PHY_RF_RXLNACURRSEL_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_y0_rxlnacurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNACURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}


/**
* @brief rxgmcurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             rxgmcurrsel                 0             0xY0
* </pre>
*/
#define PHY_RF_RXGMCURRSEL_ADDRESS     0x09

__INLINE uint8_t spi_read_pg_y0_rxgmcurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGMCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}


/**
* @brief rxlnaprcapcoarse register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:3             rxlnaprcapcoarse            0             0xY0
* </pre>
*/
#define PHY_RF_RXLNAPRCAPCOARSE_ADDRESS     0x09

__INLINE uint8_t spi_read_pg_y0_rxlnaprcapcoarse(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNAPRCAPCOARSE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 3) & mask;
}


/**
* @brief rxgm5dben register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               rxgm5dben                   0             0xY0
* </pre>
*/
#define PHY_RF_RXGM5DBEN_ADDRESS     0x09

__INLINE uint8_t spi_read_pg_y0_rxgm5dben(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGM5DBEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}


/**
* @brief rxlnaprcapfine register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             rxlnaprcapfine              0             0xY0
* </pre>
*/
#define PHY_RF_RXLNAPRCAPFINE_ADDRESS     0x0A

__INLINE uint8_t spi_read_pg_y0_rxlnaprcapfine(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNAPRCAPFINE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}


/**
* @brief rxlnaseccap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             rxlnaseccap                 0             0xY0
* </pre>
*/
#define PHY_RF_RXLNASECCAP_ADDRESS     0x0A

__INLINE uint8_t spi_read_pg_y0_rxlnaseccap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNASECCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}


/**
* @brief rxlnamatchcap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             rxlnamatchcap               0             0xY0
* </pre>
*/
#define PHY_RF_RXLNAMATCHCAP_ADDRESS     0x0B

__INLINE uint8_t spi_read_pg_y0_rxlnamatchcap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXLNAMATCHCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}


/**
* @brief rxfwrgainset0_0x06 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 33:32           rxfwrgainset0_0x06          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET0_0X06_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset0_0x06(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET0_0X06_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset0_0x06(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET0_0X06_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXFWRGAINSET0_0X06_ADDRESS, value_to_write);
}


/**
* @brief rxfwrgainset0_0x07 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 31:24           rxfwrgainset0_0x07          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET0_0X07_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset0_0x07(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET0_0X07_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset0_0x07(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET0_0X07_ADDRESS, value);
}


/**
* @brief rxfwrgainset0_0x08 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 23:16           rxfwrgainset0_0x08          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET0_0X08_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset0_0x08(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET0_0X08_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset0_0x08(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET0_0X08_ADDRESS, value);
}


/**
* @brief rxfwrgainset0_0x09 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            rxfwrgainset0_0x09          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET0_0X09_ADDRESS     0x09

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset0_0x09(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET0_0X09_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset0_0x09(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET0_0X09_ADDRESS, value);
}


/**
* @brief rxfwrgainset0_0x0A register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxfwrgainset0_0x0A          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET0_0X0A_ADDRESS     0x0A

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset0_0x0A(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET0_0X0A_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset0_0x0A(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET0_0X0A_ADDRESS, value);
}


/**
* @brief rxfwrgainset1_0x0B register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 33:32           rxfwrgainset1_0x0B          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET1_0X0B_ADDRESS     0x0B

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset1_0x0B(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET1_0X0B_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset1_0x0B(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET1_0X0B_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXFWRGAINSET1_0X0B_ADDRESS, value_to_write);
}


/**
* @brief rxfwrgainset1_0x0C register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 31:24           rxfwrgainset1_0x0C          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET1_0X0C_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset1_0x0C(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET1_0X0C_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset1_0x0C(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET1_0X0C_ADDRESS, value);
}


/**
* @brief rxfwrgainset1_0x0D register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 23:16           rxfwrgainset1_0x0D          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET1_0X0D_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset1_0x0D(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET1_0X0D_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset1_0x0D(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET1_0X0D_ADDRESS, value);
}


/**
* @brief rxfwrgainset1_0x0E register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            rxfwrgainset1_0x0E          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET1_0X0E_ADDRESS     0x0E

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset1_0x0E(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET1_0X0E_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset1_0x0E(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET1_0X0E_ADDRESS, value);
}


/**
* @brief rxfwrgainset1_0x0F register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxfwrgainset1_0x0F          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET1_0X0F_ADDRESS     0x0F

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset1_0x0F(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET1_0X0F_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset1_0x0F(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET1_0X0F_ADDRESS, value);
}


/**
* @brief rxfwrgainset2_0x10 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 33:32           rxfwrgainset2_0x10          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET2_0X10_ADDRESS     0x10

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset2_0x10(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET2_0X10_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset2_0x10(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET2_0X10_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXFWRGAINSET2_0X10_ADDRESS, value_to_write);
}


/**
* @brief rxfwrgainset2_0x11 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 31:24           rxfwrgainset2_0x11          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET2_0X11_ADDRESS     0x11

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset2_0x11(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET2_0X11_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset2_0x11(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET2_0X11_ADDRESS, value);
}


/**
* @brief rxfwrgainset2_0x12 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 23:16           rxfwrgainset2_0x12          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET2_0X12_ADDRESS     0x12

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset2_0x12(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET2_0X12_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset2_0x12(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET2_0X12_ADDRESS, value);
}


/**
* @brief rxfwrgainset2_0x13 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            rxfwrgainset2_0x13          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET2_0X13_ADDRESS     0x13

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset2_0x13(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET2_0X13_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset2_0x13(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET2_0X13_ADDRESS, value);
}


/**
* @brief rxfwrgainset2_0x14 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxfwrgainset2_0x14          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET2_0X14_ADDRESS     0x14

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset2_0x14(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET2_0X14_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset2_0x14(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET2_0X14_ADDRESS, value);
}


/**
* @brief rxfwrgainset3_0x15 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 33:32           rxfwrgainset3_0x15          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET3_0X15_ADDRESS     0x15

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset3_0x15(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET3_0X15_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset3_0x15(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET3_0X15_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXFWRGAINSET3_0X15_ADDRESS, value_to_write);
}


/**
* @brief rxfwrgainset3_0x16 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 31:24           rxfwrgainset3_0x16          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET3_0X16_ADDRESS     0x16

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset3_0x16(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET3_0X16_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset3_0x16(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET3_0X16_ADDRESS, value);
}


/**
* @brief rxfwrgainset3_0x17 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 23:16           rxfwrgainset3_0x17          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET3_0X17_ADDRESS     0x17

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset3_0x17(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET3_0X17_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset3_0x17(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET3_0X17_ADDRESS, value);
}


/**
* @brief rxfwrgainset3_0x18 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            rxfwrgainset3_0x18          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET3_0X18_ADDRESS     0x18

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset3_0x18(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET3_0X18_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset3_0x18(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET3_0X18_ADDRESS, value);
}


/**
* @brief rxfwrgainset3_0x19 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxfwrgainset3_0x19          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET3_0X19_ADDRESS     0x19

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset3_0x19(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET3_0X19_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset3_0x19(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET3_0X19_ADDRESS, value);
}


/**
* @brief rxfwrgainset4_0x1A register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 33:32           rxfwrgainset4_0x1A          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET4_0X1A_ADDRESS     0x1A

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset4_0x1A(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET4_0X1A_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset4_0x1A(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET4_0X1A_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXFWRGAINSET4_0X1A_ADDRESS, value_to_write);
}


/**
* @brief rxfwrgainset4_0x1B register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 31:24           rxfwrgainset4_0x1B          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET4_0X1B_ADDRESS     0x1B

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset4_0x1B(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET4_0X1B_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset4_0x1B(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET4_0X1B_ADDRESS, value);
}


/**
* @brief rxfwrgainset4_0x1C register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 23:16           rxfwrgainset4_0x1C          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET4_0X1C_ADDRESS     0x1C

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset4_0x1C(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET4_0X1C_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset4_0x1C(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET4_0X1C_ADDRESS, value);
}


/**
* @brief rxfwrgainset4_0x1D register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            rxfwrgainset4_0x1D          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET4_0X1D_ADDRESS     0x1D

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset4_0x1D(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET4_0X1D_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset4_0x1D(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET4_0X1D_ADDRESS, value);
}


/**
* @brief rxfwrgainset4_0x1E register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxfwrgainset4_0x1E          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET4_0X1E_ADDRESS     0x1E

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset4_0x1E(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET4_0X1E_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset4_0x1E(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET4_0X1E_ADDRESS, value);
}


/**
* @brief rxfwrgainset5_0x1F register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 33:32           rxfwrgainset5_0x1F          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET5_0X1F_ADDRESS     0x1F

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset5_0x1F(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET5_0X1F_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset5_0x1F(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET5_0X1F_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXFWRGAINSET5_0X1F_ADDRESS, value_to_write);
}


/**
* @brief rxfwrgainset5_0x20 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 31:24           rxfwrgainset5_0x20          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET5_0X20_ADDRESS     0x20

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset5_0x20(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET5_0X20_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset5_0x20(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET5_0X20_ADDRESS, value);
}


/**
* @brief rxfwrgainset5_0x21 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 23:16           rxfwrgainset5_0x21          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET5_0X21_ADDRESS     0x21

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset5_0x21(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET5_0X21_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset5_0x21(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET5_0X21_ADDRESS, value);
}


/**
* @brief rxfwrgainset5_0x22 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            rxfwrgainset5_0x22          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET5_0X22_ADDRESS     0x22

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset5_0x22(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET5_0X22_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset5_0x22(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET5_0X22_ADDRESS, value);
}


/**
* @brief rxfwrgainset5_0x23 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxfwrgainset5_0x23          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET5_0X23_ADDRESS     0x23

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset5_0x23(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET5_0X23_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset5_0x23(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET5_0X23_ADDRESS, value);
}


/**
* @brief rxfwrgainset6_0x24 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 33:32           rxfwrgainset6_0x24          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET6_0X24_ADDRESS     0x24

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset6_0x24(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET6_0X24_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset6_0x24(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET6_0X24_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXFWRGAINSET6_0X24_ADDRESS, value_to_write);
}


/**
* @brief rxfwrgainset6_0x25 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 31:24           rxfwrgainset6_0x25          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET6_0X25_ADDRESS     0x25

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset6_0x25(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET6_0X25_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset6_0x25(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET6_0X25_ADDRESS, value);
}


/**
* @brief rxfwrgainset6_0x26 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 23:16           rxfwrgainset6_0x26          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET6_0X26_ADDRESS     0x26

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset6_0x26(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET6_0X26_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset6_0x26(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET6_0X26_ADDRESS, value);
}


/**
* @brief rxfwrgainset6_0x27 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            rxfwrgainset6_0x27          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET6_0X27_ADDRESS     0x27

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset6_0x27(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET6_0X27_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset6_0x27(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET6_0X27_ADDRESS, value);
}


/**
* @brief rxfwrgainset6_0x28 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxfwrgainset6_0x28          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET6_0X28_ADDRESS     0x28

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset6_0x28(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET6_0X28_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset6_0x28(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET6_0X28_ADDRESS, value);
}


/**
* @brief rxfwrgainset7_0x29 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 33:32           rxfwrgainset7_0x29          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET7_0X29_ADDRESS     0x29

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset7_0x29(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET7_0X29_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset7_0x29(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET7_0X29_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXFWRGAINSET7_0X29_ADDRESS, value_to_write);
}


/**
* @brief rxfwrgainset7_0x2A register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 31:24           rxfwrgainset7_0x2A          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET7_0X2A_ADDRESS     0x2A

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset7_0x2A(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET7_0X2A_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset7_0x2A(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET7_0X2A_ADDRESS, value);
}


/**
* @brief rxfwrgainset7_0x2B register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 23:16           rxfwrgainset7_0x2B          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET7_0X2B_ADDRESS     0x2B

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset7_0x2B(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET7_0X2B_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset7_0x2B(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET7_0X2B_ADDRESS, value);
}


/**
* @brief rxfwrgainset7_0x2C register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            rxfwrgainset7_0x2C          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET7_0X2C_ADDRESS     0x2C

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset7_0x2C(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET7_0X2C_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset7_0x2C(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET7_0X2C_ADDRESS, value);
}


/**
* @brief rxfwrgainset7_0x2D register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxfwrgainset7_0x2D          0.0           0xY1
* </pre>
*/
#define PHY_RF_RXFWRGAINSET7_0X2D_ADDRESS     0x2D

__INLINE uint8_t spi_read_pg_y1_rxfwrgainset7_0x2D(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXFWRGAINSET7_0X2D_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxfwrgainset7_0x2D(uint8_t value)
{
    spi_write(PHY_RF_RXFWRGAINSET7_0X2D_ADDRESS, value);
}


/**
* @brief rxrssien register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               rxrssien                    0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRSSIEN_ADDRESS     0x29

__INLINE uint8_t spi_read_pg_y1_rxrssien(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSIEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_y1_rxrssien(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSIEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXRSSIEN_ADDRESS, value_to_write);
}


/**
* @brief rxrssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:6             rxrssigain                  0             0xY1
* </pre>
*/
#define PHY_RF_RXRSSIGAIN_ADDRESS     0x2F

__INLINE uint8_t spi_read_pg_y1_rxrssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 6) & mask;
}


/**
* @brief rxg0rssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:6             rxg0rssigain                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXG0RSSIGAIN_ADDRESS     0x2E

__INLINE uint8_t spi_read_pg_y1_rxg0rssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG0RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y1_rxg0rssigain(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG0RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXG0RSSIGAIN_ADDRESS, value_to_write);
}


/**
* @brief rxg1rssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5:4             rxg1rssigain                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXG1RSSIGAIN_ADDRESS     0x2E

__INLINE uint8_t spi_read_pg_y1_rxg1rssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG1RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y1_rxg1rssigain(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG1RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXG1RSSIGAIN_ADDRESS, value_to_write);
}


/**
* @brief rxg2rssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:2             rxg2rssigain                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXG2RSSIGAIN_ADDRESS     0x2E

__INLINE uint8_t spi_read_pg_y1_rxg2rssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG2RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_y1_rxg2rssigain(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG2RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXG2RSSIGAIN_ADDRESS, value_to_write);
}


/**
* @brief rxg3rssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1:0             rxg3rssigain                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXG3RSSIGAIN_ADDRESS     0x2E

__INLINE uint8_t spi_read_pg_y1_rxg3rssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG3RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxg3rssigain(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG3RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXG3RSSIGAIN_ADDRESS, value_to_write);
}


/**
* @brief rxg4rssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:6             rxg4rssigain                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXG4RSSIGAIN_ADDRESS     0x30

__INLINE uint8_t spi_read_pg_y1_rxg4rssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG4RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y1_rxg4rssigain(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG4RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXG4RSSIGAIN_ADDRESS, value_to_write);
}


/**
* @brief rxg5rssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5:4             rxg5rssigain                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXG5RSSIGAIN_ADDRESS     0x30

__INLINE uint8_t spi_read_pg_y1_rxg5rssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG5RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y1_rxg5rssigain(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG5RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXG5RSSIGAIN_ADDRESS, value_to_write);
}


/**
* @brief rxg6rssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:2             rxg6rssigain                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXG6RSSIGAIN_ADDRESS     0x30

__INLINE uint8_t spi_read_pg_y1_rxg6rssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG6RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_y1_rxg6rssigain(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG6RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXG6RSSIGAIN_ADDRESS, value_to_write);
}


/**
* @brief rxg7rssigain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1:0             rxg7rssigain                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXG7RSSIGAIN_ADDRESS     0x30

__INLINE uint8_t spi_read_pg_y1_rxg7rssigain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG7RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxg7rssigain(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXG7RSSIGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXG7RSSIGAIN_ADDRESS, value_to_write);
}


/**
* @brief rxrssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrssithres0                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRSSITHRES0_ADDRESS     0x31

__INLINE uint8_t spi_read_pg_y1_rxrssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief rxrssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrssithres1                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRSSITHRES1_ADDRESS     0x32

__INLINE uint8_t spi_read_pg_y1_rxrssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief rxrssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrssithres2                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRSSITHRES2_ADDRESS     0x33

__INLINE uint8_t spi_read_pg_y1_rxrssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief rxrfg0rssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg0rssithres0            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG0RSSITHRES0_ADDRESS     0x34

__INLINE uint8_t spi_read_pg_y1_rxrfg0rssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG0RSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg0rssithres0(uint8_t value)
{
    spi_write(PHY_RF_RXRFG0RSSITHRES0_ADDRESS, value);
}


/**
* @brief rxrfg0rssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg0rssithres1            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG0RSSITHRES1_ADDRESS     0x35

__INLINE uint8_t spi_read_pg_y1_rxrfg0rssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG0RSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg0rssithres1(uint8_t value)
{
    spi_write(PHY_RF_RXRFG0RSSITHRES1_ADDRESS, value);
}


/**
* @brief rxrfg0rssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg0rssithres2            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG0RSSITHRES2_ADDRESS     0x36

__INLINE uint8_t spi_read_pg_y1_rxrfg0rssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG0RSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg0rssithres2(uint8_t value)
{
    spi_write(PHY_RF_RXRFG0RSSITHRES2_ADDRESS, value);
}


/**
* @brief rxrfg1rssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg1rssithres0            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG1RSSITHRES0_ADDRESS     0x37

__INLINE uint8_t spi_read_pg_y1_rxrfg1rssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG1RSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg1rssithres0(uint8_t value)
{
    spi_write(PHY_RF_RXRFG1RSSITHRES0_ADDRESS, value);
}


/**
* @brief rxrfg1rssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg1rssithres1            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG1RSSITHRES1_ADDRESS     0x38

__INLINE uint8_t spi_read_pg_y1_rxrfg1rssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG1RSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg1rssithres1(uint8_t value)
{
    spi_write(PHY_RF_RXRFG1RSSITHRES1_ADDRESS, value);
}


/**
* @brief rxrfg1rssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg1rssithres2            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG1RSSITHRES2_ADDRESS     0x39

__INLINE uint8_t spi_read_pg_y1_rxrfg1rssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG1RSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg1rssithres2(uint8_t value)
{
    spi_write(PHY_RF_RXRFG1RSSITHRES2_ADDRESS, value);
}


/**
* @brief rxrfg2rssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg2rssithres0            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG2RSSITHRES0_ADDRESS     0x3A

__INLINE uint8_t spi_read_pg_y1_rxrfg2rssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG2RSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg2rssithres0(uint8_t value)
{
    spi_write(PHY_RF_RXRFG2RSSITHRES0_ADDRESS, value);
}


/**
* @brief rxrfg2rssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg2rssithres1            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG2RSSITHRES1_ADDRESS     0x3B

__INLINE uint8_t spi_read_pg_y1_rxrfg2rssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG2RSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg2rssithres1(uint8_t value)
{
    spi_write(PHY_RF_RXRFG2RSSITHRES1_ADDRESS, value);
}


/**
* @brief rxrfg2rssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg2rssithres2            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG2RSSITHRES2_ADDRESS     0x3C

__INLINE uint8_t spi_read_pg_y1_rxrfg2rssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG2RSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg2rssithres2(uint8_t value)
{
    spi_write(PHY_RF_RXRFG2RSSITHRES2_ADDRESS, value);
}


/**
* @brief rxrfg3rssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg3rssithres0            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG3RSSITHRES0_ADDRESS     0x3D

__INLINE uint8_t spi_read_pg_y1_rxrfg3rssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG3RSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg3rssithres0(uint8_t value)
{
    spi_write(PHY_RF_RXRFG3RSSITHRES0_ADDRESS, value);
}


/**
* @brief rxrfg3rssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg3rssithres1            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG3RSSITHRES1_ADDRESS     0x3E

__INLINE uint8_t spi_read_pg_y1_rxrfg3rssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG3RSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg3rssithres1(uint8_t value)
{
    spi_write(PHY_RF_RXRFG3RSSITHRES1_ADDRESS, value);
}


/**
* @brief rxrfg3rssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg3rssithres2            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG3RSSITHRES2_ADDRESS     0x3F

__INLINE uint8_t spi_read_pg_y1_rxrfg3rssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG3RSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg3rssithres2(uint8_t value)
{
    spi_write(PHY_RF_RXRFG3RSSITHRES2_ADDRESS, value);
}


/**
* @brief rxrfg4rssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg4rssithres0            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG4RSSITHRES0_ADDRESS     0x40

__INLINE uint8_t spi_read_pg_y1_rxrfg4rssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG4RSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg4rssithres0(uint8_t value)
{
    spi_write(PHY_RF_RXRFG4RSSITHRES0_ADDRESS, value);
}


/**
* @brief rxrfg4rssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg4rssithres1            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG4RSSITHRES1_ADDRESS     0x41

__INLINE uint8_t spi_read_pg_y1_rxrfg4rssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG4RSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg4rssithres1(uint8_t value)
{
    spi_write(PHY_RF_RXRFG4RSSITHRES1_ADDRESS, value);
}


/**
* @brief rxrfg4rssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg4rssithres2            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG4RSSITHRES2_ADDRESS     0x42

__INLINE uint8_t spi_read_pg_y1_rxrfg4rssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG4RSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg4rssithres2(uint8_t value)
{
    spi_write(PHY_RF_RXRFG4RSSITHRES2_ADDRESS, value);
}


/**
* @brief rxrfg5rssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg5rssithres0            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG5RSSITHRES0_ADDRESS     0x43

__INLINE uint8_t spi_read_pg_y1_rxrfg5rssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG5RSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg5rssithres0(uint8_t value)
{
    spi_write(PHY_RF_RXRFG5RSSITHRES0_ADDRESS, value);
}


/**
* @brief rxrfg5rssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg5rssithres1            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG5RSSITHRES1_ADDRESS     0x44

__INLINE uint8_t spi_read_pg_y1_rxrfg5rssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG5RSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg5rssithres1(uint8_t value)
{
    spi_write(PHY_RF_RXRFG5RSSITHRES1_ADDRESS, value);
}


/**
* @brief rxrfg5rssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg5rssithres2            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG5RSSITHRES2_ADDRESS     0x45

__INLINE uint8_t spi_read_pg_y1_rxrfg5rssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG5RSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg5rssithres2(uint8_t value)
{
    spi_write(PHY_RF_RXRFG5RSSITHRES2_ADDRESS, value);
}


/**
* @brief rxrfg6rssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg6rssithres0            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG6RSSITHRES0_ADDRESS     0x46

__INLINE uint8_t spi_read_pg_y1_rxrfg6rssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG6RSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg6rssithres0(uint8_t value)
{
    spi_write(PHY_RF_RXRFG6RSSITHRES0_ADDRESS, value);
}


/**
* @brief rxrfg6rssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg6rssithres1            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG6RSSITHRES1_ADDRESS     0x47

__INLINE uint8_t spi_read_pg_y1_rxrfg6rssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG6RSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg6rssithres1(uint8_t value)
{
    spi_write(PHY_RF_RXRFG6RSSITHRES1_ADDRESS, value);
}


/**
* @brief rxrfg6rssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg6rssithres2            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG6RSSITHRES2_ADDRESS     0x48

__INLINE uint8_t spi_read_pg_y1_rxrfg6rssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG6RSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg6rssithres2(uint8_t value)
{
    spi_write(PHY_RF_RXRFG6RSSITHRES2_ADDRESS, value);
}


/**
* @brief rxrfg7rssithres0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg7rssithres0            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG7RSSITHRES0_ADDRESS     0x49

__INLINE uint8_t spi_read_pg_y1_rxrfg7rssithres0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG7RSSITHRES0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg7rssithres0(uint8_t value)
{
    spi_write(PHY_RF_RXRFG7RSSITHRES0_ADDRESS, value);
}


/**
* @brief rxrfg7rssithres1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg7rssithres1            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG7RSSITHRES1_ADDRESS     0x4A

__INLINE uint8_t spi_read_pg_y1_rxrfg7rssithres1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG7RSSITHRES1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg7rssithres1(uint8_t value)
{
    spi_write(PHY_RF_RXRFG7RSSITHRES1_ADDRESS, value);
}


/**
* @brief rxrfg7rssithres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxrfg7rssithres2            0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRFG7RSSITHRES2_ADDRESS     0x4B

__INLINE uint8_t spi_read_pg_y1_rxrfg7rssithres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRFG7RSSITHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrfg7rssithres2(uint8_t value)
{
    spi_write(PHY_RF_RXRFG7RSSITHRES2_ADDRESS, value);
}


/**
* @brief rxrssifiltbw register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2:0             rxrssifiltbw                0.0           0xY1
* </pre>
*/
#define PHY_RF_RXRSSIFILTBW_ADDRESS     0x4C

__INLINE uint8_t spi_read_pg_y1_rxrssifiltbw(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSIFILTBW_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_rxrssifiltbw(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSIFILTBW_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXRSSIFILTBW_ADDRESS, value_to_write);
}


/**
* @brief txprepaen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               txprepaen                   0.0           0xY0
* </pre>
*/
#define PHY_RF_TXPREPAEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_y0_txprepaen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPAEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_y0_txprepaen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPAEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPREPAEN_ADDRESS, value_to_write);
}


/**
* @brief txpgaen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               txpgaen                     0.0           0xY0
* </pre>
*/
#define PHY_RF_TXPGAEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_y0_txpgaen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGAEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y0_txpgaen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGAEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPGAEN_ADDRESS, value_to_write);
}


/**
* @brief txmixen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               txmixen                     0.0           0xY0
* </pre>
*/
#define PHY_RF_TXMIXEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_y0_txmixen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_txmixen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXMIXEN_ADDRESS, value_to_write);
}


/**
* @brief txenvdeten register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               txenvdeten                  0.0           0xY0
* </pre>
*/
#define PHY_RF_TXENVDETEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_y0_txenvdeten(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_txenvdeten(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXENVDETEN_ADDRESS, value_to_write);
}


/**
* @brief txenvdetdcocen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               txenvdetdcocen              0.0           0xY0
* </pre>
*/
#define PHY_RF_TXENVDETDCOCEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_y0_txenvdetdcocen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_y0_txenvdetdcocen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXENVDETDCOCEN_ADDRESS, value_to_write);
}


/**
* @brief txenvdetdcocpol register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               txenvdetdcocpol             0.0           0xY0
* </pre>
*/
#define PHY_RF_TXENVDETDCOCPOL_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_y0_txenvdetdcocpol(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCPOL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_y0_txenvdetdcocpol(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCPOL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXENVDETDCOCPOL_ADDRESS, value_to_write);
}


/**
* @brief txbiasen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               txbiasen                    0.0           0xY0
* </pre>
*/
#define PHY_RF_TXBIASEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_y0_txbiasen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXBIASEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_y0_txbiasen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXBIASEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXBIASEN_ADDRESS, value_to_write);
}


/**
* @brief txprepacurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             txprepacurrsel              0.0           0xY0
* </pre>
*/
#define PHY_RF_TXPREPACURRSEL_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_y0_txprepacurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPACURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_txprepacurrsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPACURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPREPACURRSEL_ADDRESS, value_to_write);
}


/**
* @brief txpgacurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             txpgacurrsel                0.0           0xY0
* </pre>
*/
#define PHY_RF_TXPGACURRSEL_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_y0_txpgacurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGACURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txpgacurrsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGACURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPGACURRSEL_ADDRESS, value_to_write);
}


/**
* @brief txmixcurrsell register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             txmixcurrsell               0.0           0xY0
* </pre>
*/
#define PHY_RF_TXMIXCURRSELL_ADDRESS     0x0E

__INLINE uint8_t spi_read_pg_y0_txmixcurrsell(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXCURRSELL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_txmixcurrsell(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXCURRSELL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXMIXCURRSELL_ADDRESS, value_to_write);
}


/**
* @brief txpgares register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             txpgares                    0.0           0xY0
* </pre>
*/
#define PHY_RF_TXPGARES_ADDRESS     0x0E

__INLINE uint8_t spi_read_pg_y0_txpgares(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGARES_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txpgares(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGARES_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPGARES_ADDRESS, value_to_write);
}


/**
* @brief txprepamatchcap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             txprepamatchcap             0.0           0xY0
* </pre>
*/
#define PHY_RF_TXPREPAMATCHCAP_ADDRESS     0x0F

__INLINE uint8_t spi_read_pg_y0_txprepamatchcap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPAMATCHCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_txprepamatchcap(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPAMATCHCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPREPAMATCHCAP_ADDRESS, value_to_write);
}


/**
* @brief txprepacap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             txprepacap                  0.0           0xY0
* </pre>
*/
#define PHY_RF_TXPREPACAP_ADDRESS     0x0F

__INLINE uint8_t spi_read_pg_y0_txprepacap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPACAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txprepacap(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPACAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPREPACAP_ADDRESS, value_to_write);
}


/**
* @brief txpgacap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             txpgacap                    0.0           0xY0
* </pre>
*/
#define PHY_RF_TXPGACAP_ADDRESS     0x10

__INLINE uint8_t spi_read_pg_y0_txpgacap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGACAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txpgacap(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGACAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPGACAP_ADDRESS, value_to_write);
}


/**
* @brief txmixcap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             txmixcap                    0.0           0xY0
* </pre>
*/
#define PHY_RF_TXMIXCAP_ADDRESS     0x11

__INLINE uint8_t spi_read_pg_y0_txmixcap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txmixcap(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXMIXCAP_ADDRESS, value_to_write);
}


/**
* @brief txmixlobiassel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             txmixlobiassel              0.0           0xY0
* </pre>
*/
#define PHY_RF_TXMIXLOBIASSEL_ADDRESS     0x12

__INLINE uint8_t spi_read_pg_y0_txmixlobiassel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXLOBIASSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_txmixlobiassel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXLOBIASSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXMIXLOBIASSEL_ADDRESS, value_to_write);
}


/**
* @brief txmixrctrl register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:1             txmixrctrl                  0.0           0xY0
* </pre>
*/
#define PHY_RF_TXMIXRCTRL_ADDRESS     0x12

__INLINE uint8_t spi_read_pg_y0_txmixrctrl(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXRCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_y0_txmixrctrl(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXRCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXMIXRCTRL_ADDRESS, value_to_write);
}


/**
* @brief txpagain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5:0             txpagain                    0             0xY0
* </pre>
*/
#define PHY_RF_TXPAGAIN_ADDRESS     0x13

__INLINE uint8_t spi_read_pg_y0_txpagain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3F;
    return (reg_value >> 0) & mask;
}


/**
* @brief txprepagain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txprepagain                 0             0xY0
* </pre>
*/
#define PHY_RF_TXPREPAGAIN_ADDRESS     0x14

__INLINE uint8_t spi_read_pg_y0_txprepagain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPAGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief txpgagain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpgagain                   0             0xY0
* </pre>
*/
#define PHY_RF_TXPGAGAIN_ADDRESS     0x15

__INLINE uint8_t spi_read_pg_y0_txpgagain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGAGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief txmixgain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             txmixgain                   0             0xY0
* </pre>
*/
#define PHY_RF_TXMIXGAIN_ADDRESS     0x16

__INLINE uint8_t spi_read_pg_y0_txmixgain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXMIXGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}


/**
* @brief txfwrgainset0 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txfwrgainset0               0.0           0xY1
* </pre>
*/
#define PHY_RF_TXFWRGAINSET0_ADDRESS     0x4D

__INLINE uint8_t spi_read_pg_y1_txfwrgainset0(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXFWRGAINSET0_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txfwrgainset0(uint8_t value)
{
    spi_write(PHY_RF_TXFWRGAINSET0_ADDRESS, value);
}


/**
* @brief txfwrgainset1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txfwrgainset1               0.0           0xY1
* </pre>
*/
#define PHY_RF_TXFWRGAINSET1_ADDRESS     0x4E

__INLINE uint8_t spi_read_pg_y1_txfwrgainset1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXFWRGAINSET1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txfwrgainset1(uint8_t value)
{
    spi_write(PHY_RF_TXFWRGAINSET1_ADDRESS, value);
}


/**
* @brief txfwrgainset2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txfwrgainset2               0.0           0xY1
* </pre>
*/
#define PHY_RF_TXFWRGAINSET2_ADDRESS     0x4F

__INLINE uint8_t spi_read_pg_y1_txfwrgainset2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXFWRGAINSET2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txfwrgainset2(uint8_t value)
{
    spi_write(PHY_RF_TXFWRGAINSET2_ADDRESS, value);
}


/**
* @brief txfwrgainset3 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txfwrgainset3               0.0           0xY1
* </pre>
*/
#define PHY_RF_TXFWRGAINSET3_ADDRESS     0x50

__INLINE uint8_t spi_read_pg_y1_txfwrgainset3(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXFWRGAINSET3_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txfwrgainset3(uint8_t value)
{
    spi_write(PHY_RF_TXFWRGAINSET3_ADDRESS, value);
}


/**
* @brief txpagainbyp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               txpagainbyp                 0.0           0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINBYP_ADDRESS     0x51

__INLINE uint8_t spi_read_pg_y1_txpagainbyp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINBYP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_y1_txpagainbyp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINBYP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPAGAINBYP_ADDRESS, value_to_write);
}


/**
* @brief txpagainpol register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               txpagainpol                 0.0           0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINPOL_ADDRESS     0x51

__INLINE uint8_t spi_read_pg_y1_txpagainpol(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINPOL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_y1_txpagainpol(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINPOL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPAGAINPOL_ADDRESS, value_to_write);
}


/**
* @brief txpagainoffset register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:3             txpagainoffset              0.0           0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINOFFSET_ADDRESS     0x51

__INLINE uint8_t spi_read_pg_y1_txpagainoffset(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINOFFSET_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_y1_txpagainoffset(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINOFFSET_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPAGAINOFFSET_ADDRESS, value_to_write);
}


/**
* @brief txpagainstep register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             txpagainstep                10.0          0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINSTEP_ADDRESS     0x52

__INLINE uint8_t spi_read_pg_y1_txpagainstep(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINSTEP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainstep(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINSTEP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPAGAINSTEP_ADDRESS, value_to_write);
}


/**
* @brief txpagainthres6 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpagainthres6              180.0         0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES6_ADDRESS     0x53

__INLINE uint8_t spi_read_pg_y1_txpagainthres6(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES6_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres6(uint8_t value)
{
    spi_write(PHY_RF_TXPAGAINTHRES6_ADDRESS, value);
}


/**
* @brief txpagainthres5 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpagainthres5              121.0         0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES5_ADDRESS     0x54

__INLINE uint8_t spi_read_pg_y1_txpagainthres5(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES5_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres5(uint8_t value)
{
    spi_write(PHY_RF_TXPAGAINTHRES5_ADDRESS, value);
}


/**
* @brief txpagainthres4 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpagainthres4              86.0          0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES4_ADDRESS     0x55

__INLINE uint8_t spi_read_pg_y1_txpagainthres4(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES4_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres4(uint8_t value)
{
    spi_write(PHY_RF_TXPAGAINTHRES4_ADDRESS, value);
}


/**
* @brief txpagainthres3 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpagainthres3              60.0          0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES3_ADDRESS     0x56

__INLINE uint8_t spi_read_pg_y1_txpagainthres3(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES3_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres3(uint8_t value)
{
    spi_write(PHY_RF_TXPAGAINTHRES3_ADDRESS, value);
}


/**
* @brief txpagainthres2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpagainthres2              41.0          0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES2_ADDRESS     0x57

__INLINE uint8_t spi_read_pg_y1_txpagainthres2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres2(uint8_t value)
{
    spi_write(PHY_RF_TXPAGAINTHRES2_ADDRESS, value);
}


/**
* @brief txpagainthres1_0x58 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 8:8             txpagainthres1_0x58         27.0          0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES1_0X58_ADDRESS     0x58

__INLINE uint8_t spi_read_pg_y1_txpagainthres1_0x58(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES1_0X58_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres1_0x58(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES1_0X58_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPAGAINTHRES1_0X58_ADDRESS, value_to_write);
}


/**
* @brief txpagainthres1_0x59 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpagainthres1_0x59         27.0          0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES1_0X59_ADDRESS     0x59

__INLINE uint8_t spi_read_pg_y1_txpagainthres1_0x59(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES1_0X59_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres1_0x59(uint8_t value)
{
    spi_write(PHY_RF_TXPAGAINTHRES1_0X59_ADDRESS, value);
}


/**
* @brief txpagainthres0_0x5A register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 8:8             txpagainthres0_0x5A         14.0          0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES0_0X5A_ADDRESS     0x5A

__INLINE uint8_t spi_read_pg_y1_txpagainthres0_0x5A(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES0_0X5A_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres0_0x5A(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES0_0X5A_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXPAGAINTHRES0_0X5A_ADDRESS, value_to_write);
}


/**
* @brief txpagainthres0_0x5B register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpagainthres0_0x5B         14.0          0xY1
* </pre>
*/
#define PHY_RF_TXPAGAINTHRES0_0X5B_ADDRESS     0x5B

__INLINE uint8_t spi_read_pg_y1_txpagainthres0_0x5B(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPAGAINTHRES0_0X5B_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpagainthres0_0x5B(uint8_t value)
{
    spi_write(PHY_RF_TXPAGAINTHRES0_0X5B_ADDRESS, value);
}


/**
* @brief txprepagainext register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txprepagainext              0.0           0xY1
* </pre>
*/
#define PHY_RF_TXPREPAGAINEXT_ADDRESS     0x5C

__INLINE uint8_t spi_read_pg_y1_txprepagainext(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPREPAGAINEXT_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txprepagainext(uint8_t value)
{
    spi_write(PHY_RF_TXPREPAGAINEXT_ADDRESS, value);
}


/**
* @brief txpgagainex register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txpgagainex                 0.0           0xY1
* </pre>
*/
#define PHY_RF_TXPGAGAINEX_ADDRESS     0x5D

__INLINE uint8_t spi_read_pg_y1_txpgagainex(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXPGAGAINEX_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y1_txpgagainex(uint8_t value)
{
    spi_write(PHY_RF_TXPGAGAINEX_ADDRESS, value);
}


/**
* @brief txenvdetdcocdacrange register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             txenvdetdcocdacrange        0.0           0xY0
* </pre>
*/
#define PHY_RF_TXENVDETDCOCDACRANGE_ADDRESS     0x17

__INLINE uint8_t spi_read_pg_y0_txenvdetdcocdacrange(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCDACRANGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_txenvdetdcocdacrange(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCDACRANGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXENVDETDCOCDACRANGE_ADDRESS, value_to_write);
}


/**
* @brief txenvdetdcocp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             txenvdetdcocp               0.0           0xY0
* </pre>
*/
#define PHY_RF_TXENVDETDCOCP_ADDRESS     0x18

__INLINE uint8_t spi_read_pg_y0_txenvdetdcocp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txenvdetdcocp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXENVDETDCOCP_ADDRESS, value_to_write);
}


/**
* @brief txenvdetdcocn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             txenvdetdcocn               0.0           0xY0
* </pre>
*/
#define PHY_RF_TXENVDETDCOCN_ADDRESS     0x19

__INLINE uint8_t spi_read_pg_y0_txenvdetdcocn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txenvdetdcocn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXENVDETDCOCN_ADDRESS, value_to_write);
}


/**
* @brief txenvdetreaden register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               txenvdetreaden              0.0           0xY0
* </pre>
*/
#define PHY_RF_TXENVDETREADEN_ADDRESS     0x19

__INLINE uint8_t spi_read_pg_y0_txenvdetreaden(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETREADEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_txenvdetreaden(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETREADEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXENVDETREADEN_ADDRESS, value_to_write);
}


/**
* @brief txenvdetbw register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:6             txenvdetbw                  0.0           0xY0
* </pre>
*/
#define PHY_RF_TXENVDETBW_ADDRESS     0x19

__INLINE uint8_t spi_read_pg_y0_txenvdetbw(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETBW_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y0_txenvdetbw(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETBW_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TXENVDETBW_ADDRESS, value_to_write);
}


/**
* @brief txenvdetdcocresp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             txenvdetdcocresp            0             0xY0
* </pre>
*/
#define PHY_RF_TXENVDETDCOCRESP_ADDRESS     0x1A

__INLINE uint8_t spi_read_pg_y0_txenvdetdcocresp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCRESP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}


/**
* @brief txenvdetdcocresn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             txenvdetdcocresn            0             0xY0
* </pre>
*/
#define PHY_RF_TXENVDETDCOCRESN_ADDRESS     0x1B

__INLINE uint8_t spi_read_pg_y0_txenvdetdcocresn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOCRESN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}


/**
* @brief txenvdetdcoc_err register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               txenvdetdcoc_err            0             0xY0
* </pre>
*/
#define PHY_RF_TXENVDETDCOC_ERR_ADDRESS     0x1B

__INLINE uint8_t spi_read_pg_y0_txenvdetdcoc_err(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXENVDETDCOC_ERR_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}


/**
* @brief bbldoen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               bbldoen                     0.0           0xY0
* </pre>
*/
#define PHY_RF_BBLDOEN_ADDRESS     0x1C

__INLINE uint8_t spi_read_pg_y0_bbldoen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_y0_bbldoen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBLDOEN_ADDRESS, value_to_write);
}


/**
* @brief bbcurrmiren register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               bbcurrmiren                 0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRMIREN_ADDRESS     0x1C

__INLINE uint8_t spi_read_pg_y0_bbcurrmiren(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRMIREN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrmiren(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRMIREN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRMIREN_ADDRESS, value_to_write);
}


/**
* @brief bbbq1fixedatten register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               bbbq1fixedatten             0.0           0xY0
* </pre>
*/
#define PHY_RF_BBBQ1FIXEDATTEN_ADDRESS     0x1C

__INLINE uint8_t spi_read_pg_y0_bbbq1fixedatten(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBBQ1FIXEDATTEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_bbbq1fixedatten(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBBQ1FIXEDATTEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBBQ1FIXEDATTEN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocinten register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               bbdcocinten                 0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCINTEN_ADDRESS     0x1C

__INLINE uint8_t spi_read_pg_y0_bbdcocinten(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCINTEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocinten(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCINTEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCINTEN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocpol register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               bbdcocpol                   0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCPOL_ADDRESS     0x1C

__INLINE uint8_t spi_read_pg_y0_bbdcocpol(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCPOL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocpol(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCPOL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCPOL_ADDRESS, value_to_write);
}


/**
* @brief bbcurrsel1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             bbcurrsel1                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSEL1_ADDRESS     0x1D

__INLINE uint8_t spi_read_pg_y0_bbcurrsel1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrsel1(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL1_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSEL1_ADDRESS, value_to_write);
}


/**
* @brief bbcurrsel2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             bbcurrsel2                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSEL2_ADDRESS     0x1D

__INLINE uint8_t spi_read_pg_y0_bbcurrsel2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrsel2(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL2_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSEL2_ADDRESS, value_to_write);
}


/**
* @brief bbcurrsel3 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             bbcurrsel3                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSEL3_ADDRESS     0x1E

__INLINE uint8_t spi_read_pg_y0_bbcurrsel3(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL3_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrsel3(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL3_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSEL3_ADDRESS, value_to_write);
}


/**
* @brief bbcurrsel4 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             bbcurrsel4                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSEL4_ADDRESS     0x1E

__INLINE uint8_t spi_read_pg_y0_bbcurrsel4(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL4_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrsel4(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL4_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSEL4_ADDRESS, value_to_write);
}


/**
* @brief bbcurrsel5 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             bbcurrsel5                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSEL5_ADDRESS     0x1F

__INLINE uint8_t spi_read_pg_y0_bbcurrsel5(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL5_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrsel5(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSEL5_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSEL5_ADDRESS, value_to_write);
}


/**
* @brief bbcurrseltxlevshif register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             bbcurrseltxlevshif          0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSELTXLEVSHIF_ADDRESS     0x1F

__INLINE uint8_t spi_read_pg_y0_bbcurrseltxlevshif(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSELTXLEVSHIF_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrseltxlevshif(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSELTXLEVSHIF_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSELTXLEVSHIF_ADDRESS, value_to_write);
}


/**
* @brief bbcurrseladcbuff register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             bbcurrseladcbuff            0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSELADCBUFF_ADDRESS     0x20

__INLINE uint8_t spi_read_pg_y0_bbcurrseladcbuff(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSELADCBUFF_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrseladcbuff(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSELADCBUFF_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSELADCBUFF_ADDRESS, value_to_write);
}


/**
* @brief bbcurrseldetread1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             bbcurrseldetread1           0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSELDETREAD1_ADDRESS     0x53

__INLINE uint8_t spi_read_pg_y0_bbcurrseldetread1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSELDETREAD1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrseldetread1(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSELDETREAD1_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSELDETREAD1_ADDRESS, value_to_write);
}


/**
* @brief bbcurrseldetread2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             bbcurrseldetread2           0.0           0xY0
* </pre>
*/
#define PHY_RF_BBCURRSELDETREAD2_ADDRESS     0x53

__INLINE uint8_t spi_read_pg_y0_bbcurrseldetread2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSELDETREAD2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbcurrseldetread2(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBCURRSELDETREAD2_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBCURRSELDETREAD2_ADDRESS, value_to_write);
}


/**
* @brief bbldo1v0set register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:3             bbldo1v0set                 0.0           0xY0
* </pre>
*/
#define PHY_RF_BBLDO1V0SET_ADDRESS     0x20

__INLINE uint8_t spi_read_pg_y0_bbldo1v0set(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBLDO1V0SET_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_y0_bbldo1v0set(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBLDO1V0SET_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBLDO1V0SET_ADDRESS, value_to_write);
}


/**
* @brief bbrxvcmbiasctrl register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             bbrxvcmbiasctrl             2.0           0xY0
* </pre>
*/
#define PHY_RF_BBRXVCMBIASCTRL_ADDRESS     0x21

__INLINE uint8_t spi_read_pg_y0_bbrxvcmbiasctrl(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBRXVCMBIASCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_bbrxvcmbiasctrl(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBRXVCMBIASCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBRXVCMBIASCTRL_ADDRESS, value_to_write);
}


/**
* @brief bbtxvcmbiasctrl register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:2             bbtxvcmbiasctrl             2.0           0xY0
* </pre>
*/
#define PHY_RF_BBTXVCMBIASCTRL_ADDRESS     0x21

__INLINE uint8_t spi_read_pg_y0_bbtxvcmbiasctrl(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBTXVCMBIASCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_y0_bbtxvcmbiasctrl(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBTXVCMBIASCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBTXVCMBIASCTRL_ADDRESS, value_to_write);
}


/**
* @brief bbbwctrl register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:6             bbbwctrl                    0.0           0xY0
* </pre>
*/
#define PHY_RF_BBBWCTRL_ADDRESS     0x22

__INLINE uint8_t spi_read_pg_y0_bbbwctrl(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBBWCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y0_bbbwctrl(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBBWCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBBWCTRL_ADDRESS, value_to_write);
}


/**
* @brief bbbwtrim register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbbwtrim                    6.0           0xY0
* </pre>
*/
#define PHY_RF_BBBWTRIM_ADDRESS     0x22

__INLINE uint8_t spi_read_pg_y0_bbbwtrim(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBBWTRIM_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbbwtrim(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBBWTRIM_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBBWTRIM_ADDRESS, value_to_write);
}


/**
* @brief bbdcocdacrange register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             bbdcocdacrange              0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCDACRANGE_ADDRESS     0x27

__INLINE uint8_t spi_read_pg_y0_bbdcocdacrange(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCDACRANGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocdacrange(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCDACRANGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCDACRANGE_ADDRESS, value_to_write);
}


/**
* @brief bbdcoc_err register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               bbdcoc_err                  0             0xY0
* </pre>
*/
#define PHY_RF_BBDCOC_ERR_ADDRESS     0x23

__INLINE uint8_t spi_read_pg_y0_bbdcoc_err(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOC_ERR_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}


/**
* @brief bbdcocip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocip                    0             0xY0
* </pre>
*/
#define PHY_RF_BBDCOCIP_ADDRESS     0x23

__INLINE uint8_t spi_read_pg_y0_bbdcocip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCIP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}


/**
* @brief bbdcocin register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocin                    0             0xY0
* </pre>
*/
#define PHY_RF_BBDCOCIN_ADDRESS     0x24

__INLINE uint8_t spi_read_pg_y0_bbdcocin(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}


/**
* @brief bbdcocqp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocqp                    0             0xY0
* </pre>
*/
#define PHY_RF_BBDCOCQP_ADDRESS     0x25

__INLINE uint8_t spi_read_pg_y0_bbdcocqp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCQP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}


/**
* @brief bbdcocqn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocqn                    0             0xY0
* </pre>
*/
#define PHY_RF_BBDCOCQN_ADDRESS     0x26

__INLINE uint8_t spi_read_pg_y0_bbdcocqn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCQN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}


/**
* @brief bbdcocg0ip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg0ip                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG0IP_ADDRESS     0x27

__INLINE uint8_t spi_read_pg_y0_bbdcocg0ip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG0IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg0ip(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG0IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG0IP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg0in register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg0in                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG0IN_ADDRESS     0x28

__INLINE uint8_t spi_read_pg_y0_bbdcocg0in(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG0IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg0in(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG0IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG0IN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg0qp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg0qp                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG0QP_ADDRESS     0x29

__INLINE uint8_t spi_read_pg_y0_bbdcocg0qp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG0QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg0qp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG0QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG0QP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg0qn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg0qn                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG0QN_ADDRESS     0X2A

__INLINE uint8_t spi_read_pg_y0_bbdcocg0qn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG0QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg0qn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG0QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG0QN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg1ip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg1ip                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG1IP_ADDRESS     0x2B

__INLINE uint8_t spi_read_pg_y0_bbdcocg1ip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG1IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg1ip(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG1IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG1IP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg1in register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg1in                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG1IN_ADDRESS     0x2C

__INLINE uint8_t spi_read_pg_y0_bbdcocg1in(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG1IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg1in(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG1IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG1IN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg1qp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg1qp                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG1QP_ADDRESS     0x2D

__INLINE uint8_t spi_read_pg_y0_bbdcocg1qp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG1QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg1qp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG1QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG1QP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg1qn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg1qn                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG1QN_ADDRESS     0x2E

__INLINE uint8_t spi_read_pg_y0_bbdcocg1qn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG1QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg1qn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG1QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG1QN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg2ip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg2ip                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG2IP_ADDRESS     0x2F

__INLINE uint8_t spi_read_pg_y0_bbdcocg2ip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG2IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg2ip(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG2IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG2IP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg2in register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg2in                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG2IN_ADDRESS     0x30

__INLINE uint8_t spi_read_pg_y0_bbdcocg2in(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG2IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg2in(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG2IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG2IN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg2qp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg2qp                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG2QP_ADDRESS     0x31

__INLINE uint8_t spi_read_pg_y0_bbdcocg2qp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG2QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg2qp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG2QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG2QP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg2qn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg2qn                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG2QN_ADDRESS     0x32

__INLINE uint8_t spi_read_pg_y0_bbdcocg2qn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG2QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg2qn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG2QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG2QN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg3ip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg3ip                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG3IP_ADDRESS     0x33

__INLINE uint8_t spi_read_pg_y0_bbdcocg3ip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG3IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg3ip(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG3IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG3IP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg3in register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg3in                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG3IN_ADDRESS     0x34

__INLINE uint8_t spi_read_pg_y0_bbdcocg3in(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG3IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg3in(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG3IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG3IN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg3qp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg3qp                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG3QP_ADDRESS     0x35

__INLINE uint8_t spi_read_pg_y0_bbdcocg3qp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG3QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg3qp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG3QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG3QP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg3qn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg3qn                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG3QN_ADDRESS     0x36

__INLINE uint8_t spi_read_pg_y0_bbdcocg3qn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG3QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg3qn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG3QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG3QN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg4ip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg4ip                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG4IP_ADDRESS     0x37

__INLINE uint8_t spi_read_pg_y0_bbdcocg4ip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG4IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg4ip(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG4IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG4IP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg4in register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg4in                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG4IN_ADDRESS     0x38

__INLINE uint8_t spi_read_pg_y0_bbdcocg4in(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG4IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg4in(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG4IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG4IN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg4qp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg4qp                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG4QP_ADDRESS     0x39

__INLINE uint8_t spi_read_pg_y0_bbdcocg4qp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG4QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg4qp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG4QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG4QP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg4qn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg4qn                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG4QN_ADDRESS     0x3A

__INLINE uint8_t spi_read_pg_y0_bbdcocg4qn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG4QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg4qn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG4QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG4QN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg5ip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg5ip                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG5IP_ADDRESS     0x3B

__INLINE uint8_t spi_read_pg_y0_bbdcocg5ip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG5IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg5ip(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG5IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG5IP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg5in register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg5in                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG5IN_ADDRESS     0x3C

__INLINE uint8_t spi_read_pg_y0_bbdcocg5in(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG5IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg5in(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG5IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG5IN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg5qp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg5qp                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG5QP_ADDRESS     0x3D

__INLINE uint8_t spi_read_pg_y0_bbdcocg5qp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG5QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg5qp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG5QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG5QP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg5qn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg5qn                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG5QN_ADDRESS     0x3E

__INLINE uint8_t spi_read_pg_y0_bbdcocg5qn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG5QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg5qn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG5QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG5QN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg6ip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg6ip                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG6IP_ADDRESS     0x3F

__INLINE uint8_t spi_read_pg_y0_bbdcocg6ip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG6IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg6ip(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG6IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG6IP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg6in register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg6in                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG6IN_ADDRESS     0x40

__INLINE uint8_t spi_read_pg_y0_bbdcocg6in(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG6IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg6in(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG6IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG6IN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg6qp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg6qp                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG6QP_ADDRESS     0x41

__INLINE uint8_t spi_read_pg_y0_bbdcocg6qp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG6QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg6qp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG6QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG6QP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg6qn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg6qn                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG6QN_ADDRESS     0x42

__INLINE uint8_t spi_read_pg_y0_bbdcocg6qn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG6QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg6qn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG6QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG6QN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg7ip register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg7ip                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG7IP_ADDRESS     0x43

__INLINE uint8_t spi_read_pg_y0_bbdcocg7ip(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG7IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg7ip(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG7IP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG7IP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg7in register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg7in                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG7IN_ADDRESS     0x44

__INLINE uint8_t spi_read_pg_y0_bbdcocg7in(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG7IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg7in(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG7IN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG7IN_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg7qp register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg7qp                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG7QP_ADDRESS     0x45

__INLINE uint8_t spi_read_pg_y0_bbdcocg7qp(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG7QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg7qp(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG7QP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG7QP_ADDRESS, value_to_write);
}


/**
* @brief bbdcocg7qn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbdcocg7qn                  0.0           0xY0
* </pre>
*/
#define PHY_RF_BBDCOCG7QN_ADDRESS     0x46

__INLINE uint8_t spi_read_pg_y0_bbdcocg7qn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG7QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbdcocg7qn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBDCOCG7QN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBDCOCG7QN_ADDRESS, value_to_write);
}


/**
* @brief bbrxgainpolarity register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               bbrxgainpolarity            0.0           0xY0
* </pre>
*/
#define PHY_RF_BBRXGAINPOLARITY_ADDRESS     0x46

__INLINE uint8_t spi_read_pg_y0_bbrxgainpolarity(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBRXGAINPOLARITY_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_bbrxgainpolarity(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBRXGAINPOLARITY_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBRXGAINPOLARITY_ADDRESS, value_to_write);
}


/**
* @brief bbrxgainctrl register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             bbrxgainctrl                0.0           0xY0
* </pre>
*/
#define PHY_RF_BBRXGAINCTRL_ADDRESS     0x47

__INLINE uint8_t spi_read_pg_y0_bbrxgainctrl(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBRXGAINCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}


/**
* @brief bbtxgainctrl register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             bbtxgainctrl                0.0           0xY0
* </pre>
*/
#define PHY_RF_BBTXGAINCTRL_ADDRESS     0x48

__INLINE uint8_t spi_read_pg_y0_bbtxgainctrl(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBTXGAINCTRL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}


/**
* @brief bbadcdrivepulldown register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               bbadcdrivepulldown          0.0           0xY0
* </pre>
*/
#define PHY_RF_BBADCDRIVEPULLDOWN_ADDRESS     0x55

__INLINE uint8_t spi_read_pg_y0_bbadcdrivepulldown(void)
{
    uint8_t reg_value = spi_read(PHY_RF_BBADCDRIVEPULLDOWN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_bbadcdrivepulldown(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_BBADCDRIVEPULLDOWN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_BBADCDRIVEPULLDOWN_ADDRESS, value_to_write);
}


/**
* @brief rxtxrfldo1v4en register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               rxtxrfldo1v4en              0.0           0xY0
* </pre>
*/
#define PHY_RF_RXTXRFLDO1V4EN_ADDRESS     0x49

__INLINE uint8_t spi_read_pg_y0_rxtxrfldo1v4en(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXRFLDO1V4EN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_y0_rxtxrfldo1v4en(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXRFLDO1V4EN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXTXRFLDO1V4EN_ADDRESS, value_to_write);
}


/**
* @brief rxtxrfldo1v0en register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               rxtxrfldo1v0en              0.0           0xY0
* </pre>
*/
#define PHY_RF_RXTXRFLDO1V0EN_ADDRESS     0x49

__INLINE uint8_t spi_read_pg_y0_rxtxrfldo1v0en(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXRFLDO1V0EN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_rxtxrfldo1v0en(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXRFLDO1V0EN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXTXRFLDO1V0EN_ADDRESS, value_to_write);
}


/**
* @brief rxtxrfldo1v0vset register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:2             rxtxrfldo1v0vset            0.0           0xY0
* </pre>
*/
#define PHY_RF_RXTXRFLDO1V0VSET_ADDRESS     0x49

__INLINE uint8_t spi_read_pg_y0_rxtxrfldo1v0vset(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXRFLDO1V0VSET_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_y0_rxtxrfldo1v0vset(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXRFLDO1V0VSET_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXTXRFLDO1V0VSET_ADDRESS, value_to_write);
}


/**
* @brief rxtxbandsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               rxtxbandsel                 0.0           0xY0
* </pre>
*/
#define PHY_RF_RXTXBANDSEL_ADDRESS     0x49

__INLINE uint8_t spi_read_pg_y0_rxtxbandsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXBANDSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_y0_rxtxbandsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXBANDSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXTXBANDSEL_ADDRESS, value_to_write);
}


/**
* @brief rxtxdivldo1v0set register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:6             rxtxdivldo1v0set            0.0           0xY0
* </pre>
*/
#define PHY_RF_RXTXDIVLDO1V0SET_ADDRESS     0x4A

__INLINE uint8_t spi_read_pg_y0_rxtxdivldo1v0set(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXDIVLDO1V0SET_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y0_rxtxdivldo1v0set(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXDIVLDO1V0SET_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXTXDIVLDO1V0SET_ADDRESS, value_to_write);
}


/**
* @brief rxtxloopbacken register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               rxtxloopbacken              0.0           0xY0
* </pre>
*/
#define PHY_RF_RXTXLOOPBACKEN_ADDRESS     0x4A

__INLINE uint8_t spi_read_pg_y0_rxtxloopbacken(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXLOOPBACKEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_rxtxloopbacken(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXLOOPBACKEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXTXLOOPBACKEN_ADDRESS, value_to_write);
}


/**
* @brief rxtxn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               rxtxn                       0.0           0xY0
* </pre>
*/
#define PHY_RF_RXTXN_ADDRESS     0x4A

__INLINE uint8_t spi_read_pg_y0_rxtxn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_y0_rxtxn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXTXN_ADDRESS, value_to_write);
}


/**
* @brief rxgain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxgain                      0.0           0xY0
* </pre>
*/
#define PHY_RF_RXGAIN_ADDRESS     0x4B

__INLINE uint8_t spi_read_pg_y0_rxgain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_rxgain(uint8_t value)
{
    spi_write(PHY_RF_RXGAIN_ADDRESS, value);
}


/**
* @brief txgain register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txgain                      0.0           0xY0
* </pre>
*/
#define PHY_RF_TXGAIN_ADDRESS     0x4C

__INLINE uint8_t spi_read_pg_y0_txgain(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXGAIN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txgain(uint8_t value)
{
    spi_write(PHY_RF_TXGAIN_ADDRESS, value);
}


/**
* @brief rxgain_def register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             rxgain_def                  0.0           0xY0
* </pre>
*/
#define PHY_RF_RXGAIN_DEF_ADDRESS     0x4D

__INLINE uint8_t spi_read_pg_y0_rxgain_def(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXGAIN_DEF_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_rxgain_def(uint8_t value)
{
    spi_write(PHY_RF_RXGAIN_DEF_ADDRESS, value);
}


/**
* @brief txgain_def register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txgain_def                  0.0           0xY0
* </pre>
*/
#define PHY_RF_TXGAIN_DEF_ADDRESS     0x4E

__INLINE uint8_t spi_read_pg_y0_txgain_def(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXGAIN_DEF_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_txgain_def(uint8_t value)
{
    spi_write(PHY_RF_TXGAIN_DEF_ADDRESS, value);
}


/**
* @brief lodivldoen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               lodivldoen                  0.0           0xY0
* </pre>
*/
#define PHY_RF_LODIVLDOEN_ADDRESS     0x4F

__INLINE uint8_t spi_read_pg_y0_lodivldoen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_y0_lodivldoen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_LODIVLDOEN_ADDRESS, value_to_write);
}


/**
* @brief lodiven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               lodiven                     0.0           0xY0
* </pre>
*/
#define PHY_RF_LODIVEN_ADDRESS     0x4F

__INLINE uint8_t spi_read_pg_y0_lodiven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_y0_lodiven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_LODIVEN_ADDRESS, value_to_write);
}


/**
* @brief lodivsyncpen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               lodivsyncpen                0.0           0xY0
* </pre>
*/
#define PHY_RF_LODIVSYNCPEN_ADDRESS     0x4F

__INLINE uint8_t spi_read_pg_y0_lodivsyncpen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVSYNCPEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_y0_lodivsyncpen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVSYNCPEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_LODIVSYNCPEN_ADDRESS, value_to_write);
}


/**
* @brief lodivbuffen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               lodivbuffen                 0.0           0xY0
* </pre>
*/
#define PHY_RF_LODIVBUFFEN_ADDRESS     0x4F

__INLINE uint8_t spi_read_pg_y0_lodivbuffen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVBUFFEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_y0_lodivbuffen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVBUFFEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_LODIVBUFFEN_ADDRESS, value_to_write);
}


/**
* @brief loresload register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:2             loresload                   0.0           0xY0
* </pre>
*/
#define PHY_RF_LORESLOAD_ADDRESS     0x4F

__INLINE uint8_t spi_read_pg_y0_loresload(void)
{
    uint8_t reg_value = spi_read(PHY_RF_LORESLOAD_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_y0_loresload(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_LORESLOAD_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_LORESLOAD_ADDRESS, value_to_write);
}


/**
* @brief lodivbiassel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             lodivbiassel                0.0           0xY0
* </pre>
*/
#define PHY_RF_LODIVBIASSEL_ADDRESS     0X50

__INLINE uint8_t spi_read_pg_y0_lodivbiassel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVBIASSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_lodivbiassel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_LODIVBIASSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_LODIVBIASSEL_ADDRESS, value_to_write);
}


/**
* @brief rxtxbbanamon register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             rxtxbbanamon                0.0           0xY0
* </pre>
*/
#define PHY_RF_RXTXBBANAMON_ADDRESS     0x51

__INLINE uint8_t spi_read_pg_y0_rxtxbbanamon(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXBBANAMON_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_rxtxbbanamon(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXTXBBANAMON_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXTXBBANAMON_ADDRESS, value_to_write);
}


/**
* @brief rxrssidebugvalue register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1:0             rxrssidebugvalue            0.0           0xY0
* </pre>
*/
#define PHY_RF_RXRSSIDEBUGVALUE_ADDRESS     0x52

__INLINE uint8_t spi_read_pg_y0_rxrssidebugvalue(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSIDEBUGVALUE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_y0_rxrssidebugvalue(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RXRSSIDEBUGVALUE_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RXRSSIDEBUGVALUE_ADDRESS, value_to_write);
}


#endif //_REG_PHY_OLYMPUS_CHX_REGISTERS_H_
