#ifndef _REG_PHY_OLYMPUS_GLOBAL_CONFIGURATION_H_
#define _REG_PHY_OLYMPUS_GLOBAL_CONFIGURATION_H_

#include "phy_hw.h"
#include "compiler.h"
/**
* @brief version register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             version                     0xA1          Global
* </pre>
*/
#define PHY_RF_VERSION_ADDRESS     0x00

__INLINE uint8_t spi_read_version(void)
{
    uint8_t reg_value = spi_read(PHY_RF_VERSION_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief synthesizer register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5:0             synthesizer                 0             Global
* </pre>
*/
#define PHY_RF_SYNTHESIZER_ADDRESS     0x01

__INLINE uint8_t spi_read_synthesizer(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SYNTHESIZER_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_synthesizer(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SYNTHESIZER_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SYNTHESIZER_ADDRESS, value_to_write);
}


/**
* @brief sx0enforce register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sx0enforce                  0             Global
* </pre>
*/
#define PHY_RF_SX0ENFORCE_ADDRESS     0x02

__INLINE uint8_t spi_read_sx0enforce(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0ENFORCE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_sx0enforce(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0ENFORCE_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX0ENFORCE_ADDRESS, value_to_write);
}


/**
* @brief rssidebugen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               rssidebugen                 0             Global
* </pre>
*/
#define PHY_RF_RSSIDEBUGEN_ADDRESS     0x02

__INLINE uint8_t spi_read_rssidebugen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RSSIDEBUGEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_rssidebugen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RSSIDEBUGEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RSSIDEBUGEN_ADDRESS, value_to_write);
}


/**
* @brief rssidefault register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5:4             rssidefault                 0             Global
* </pre>
*/
#define PHY_RF_RSSIDEFAULT_ADDRESS     0x02

__INLINE uint8_t spi_read_rssidefault(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RSSIDEFAULT_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_rssidefault(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RSSIDEFAULT_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RSSIDEFAULT_ADDRESS, value_to_write);
}


/**
* @brief rssimaxoutn register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               rssimaxoutn                 0             Global
* </pre>
*/
#define PHY_RF_RSSIMAXOUTN_ADDRESS     0x02

__INLINE uint8_t spi_read_rssimaxoutn(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RSSIMAXOUTN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_rssimaxoutn(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RSSIMAXOUTN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RSSIMAXOUTN_ADDRESS, value_to_write);
}


/**
* @brief page register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             page                        0             Global
* </pre>
*/
#define PHY_RF_PAGE_ADDRESS     0x03

__INLINE uint8_t spi_read_page(void)
{
    uint8_t reg_value = spi_read(PHY_RF_PAGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_page(uint8_t value)
{
    spi_write(PHY_RF_PAGE_ADDRESS, value);
}


/**
* @brief anamonpage register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             anamonpage                  0             Global
* </pre>
*/
#define PHY_RF_ANAMONPAGE_ADDRESS     0x04

__INLINE uint8_t spi_read_anamonpage(void)
{
    uint8_t reg_value = spi_read(PHY_RF_ANAMONPAGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_anamonpage(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_ANAMONPAGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_ANAMONPAGE_ADDRESS, value_to_write);
}


/**
* @brief anamonsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               anamonsel                   0             Global
* </pre>
*/
#define PHY_RF_ANAMONSEL_ADDRESS     0x04

__INLINE uint8_t spi_read_anamonsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_ANAMONSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_anamonsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_ANAMONSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_ANAMONSEL_ADDRESS, value_to_write);
}


/**
* @brief fwrbypass register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               fwrbypass                   0             Global
* </pre>
*/
#define PHY_RF_FWRBYPASS_ADDRESS     0x04

__INLINE uint8_t spi_read_fwrbypass(void)
{
    uint8_t reg_value = spi_read(PHY_RF_FWRBYPASS_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_fwrbypass(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_FWRBYPASS_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_FWRBYPASS_ADDRESS, value_to_write);
}


/**
* @brief fwr_en_sel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               fwr_en_sel                  0             Global
* </pre>
*/
#define PHY_RF_FWR_EN_SEL_ADDRESS     0x04

__INLINE uint8_t spi_read_fwr_en_sel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_FWR_EN_SEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_fwr_en_sel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_FWR_EN_SEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_FWR_EN_SEL_ADDRESS, value_to_write);
}


/**
* @brief fwr_spi_apply register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               fwr_spi_apply               0             Global
* </pre>
*/
#define PHY_RF_FWR_SPI_APPLY_ADDRESS     0x04

__INLINE uint8_t spi_read_fwr_spi_apply(void)
{
    uint8_t reg_value = spi_read(PHY_RF_FWR_SPI_APPLY_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_fwr_spi_apply(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_FWR_SPI_APPLY_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_FWR_SPI_APPLY_ADDRESS, value_to_write);
}


/**
* @brief txdelay register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             txdelay                     0             Global
* </pre>
*/
#define PHY_RF_TXDELAY_ADDRESS     0x05

__INLINE uint8_t spi_read_txdelay(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TXDELAY_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_txdelay(uint8_t value)
{
    spi_write(PHY_RF_TXDELAY_ADDRESS, value);
}


/**
* @brief lastfwrcmd register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             lastfwrcmd                  0             Global
* </pre>
*/
#define PHY_RF_LASTFWRCMD_ADDRESS     0x7F

__INLINE uint8_t spi_read_lastfwrcmd(void)
{
    uint8_t reg_value = spi_read(PHY_RF_LASTFWRCMD_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief fwr_spi register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             fwr_spi                     0             Global
* </pre>
*/
#define PHY_RF_FWR_SPI_ADDRESS     0x62

__INLINE uint8_t spi_read_fwr_spi(void)
{
    uint8_t reg_value = spi_read(PHY_RF_FWR_SPI_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_fwr_spi(uint8_t value)
{
    spi_write(PHY_RF_FWR_SPI_ADDRESS, value);
}


#endif //_REG_PHY_OLYMPUS_GLOBAL_CONFIGURATION_H_
