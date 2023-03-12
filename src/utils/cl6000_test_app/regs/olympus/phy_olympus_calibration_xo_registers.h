#ifndef _REG_PHY_OLYMPUS_CALIBRATION_XO_REGISTERS_H_
#define _REG_PHY_OLYMPUS_CALIBRATION_XO_REGISTERS_H_

#include "phy_hw.h"
#include "compiler.h"
/**
* @brief tempsensinten register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               tempsensinten               0.0           0x92
* </pre>
*/
#define PHY_RF_TEMPSENSINTEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_92_tempsensinten(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TEMPSENSINTEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_92_tempsensinten(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TEMPSENSINTEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TEMPSENSINTEN_ADDRESS, value_to_write);
}


/**
* @brief tempsenssel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               tempsenssel                 0.0           0x92
* </pre>
*/
#define PHY_RF_TEMPSENSSEL_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_92_tempsenssel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_TEMPSENSSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_92_tempsenssel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_TEMPSENSSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_TEMPSENSSEL_ADDRESS, value_to_write);
}


/**
* @brief rcalstart register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               rcalstart                   0.0           0x92
* </pre>
*/
#define PHY_RF_RCALSTART_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_92_rcalstart(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RCALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_92_rcalstart(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_RCALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_RCALSTART_ADDRESS, value_to_write);
}


/**
* @brief rcalready register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               rcalready                   0.0           0x92
* </pre>
*/
#define PHY_RF_RCALREADY_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_92_rcalready(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RCALREADY_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}


/**
* @brief rcalval register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             rcalval                     0.0           0x92
* </pre>
*/
#define PHY_RF_RCALVAL_ADDRESS     0x09

__INLINE uint8_t spi_read_pg_92_rcalval(void)
{
    uint8_t reg_value = spi_read(PHY_RF_RCALVAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}


/**
* @brief selres register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               selres                      0.0           0x92
* </pre>
*/
#define PHY_RF_SELRES_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_92_selres(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SELRES_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_92_selres(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SELRES_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SELRES_ADDRESS, value_to_write);
}


/**
* @brief ccalstart register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               ccalstart                   0.0           0x92
* </pre>
*/
#define PHY_RF_CCALSTART_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_92_ccalstart(void)
{
    uint8_t reg_value = spi_read(PHY_RF_CCALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_92_ccalstart(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_CCALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_CCALSTART_ADDRESS, value_to_write);
}


/**
* @brief ccalready register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               ccalready                   0.0           0x92
* </pre>
*/
#define PHY_RF_CCALREADY_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_92_ccalready(void)
{
    uint8_t reg_value = spi_read(PHY_RF_CCALREADY_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}


/**
* @brief ccalerror register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               ccalerror                   0.0           0x92
* </pre>
*/
#define PHY_RF_CCALERROR_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_92_ccalerror(void)
{
    uint8_t reg_value = spi_read(PHY_RF_CCALERROR_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}


/**
* @brief ccalval register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             ccalval                     0.0           0x92
* </pre>
*/
#define PHY_RF_CCALVAL_ADDRESS     0x0A

__INLINE uint8_t spi_read_pg_92_ccalval(void)
{
    uint8_t reg_value = spi_read(PHY_RF_CCALVAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief prmoncalstart register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               prmoncalstart               0.0           0x92
* </pre>
*/
#define PHY_RF_PRMONCALSTART_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_92_prmoncalstart(void)
{
    uint8_t reg_value = spi_read(PHY_RF_PRMONCALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_92_prmoncalstart(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_PRMONCALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_PRMONCALSTART_ADDRESS, value_to_write);
}


/**
* @brief prmoncalcylces register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:3             prmoncalcylces              0.0           0x92
* </pre>
*/
#define PHY_RF_PRMONCALCYLCES_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_92_prmoncalcylces(void)
{
    uint8_t reg_value = spi_read(PHY_RF_PRMONCALCYLCES_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_92_prmoncalcylces(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_PRMONCALCYLCES_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_PRMONCALCYLCES_ADDRESS, value_to_write);
}


/**
* @brief prmoncalready register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               prmoncalready               0.0           0x92
* </pre>
*/
#define PHY_RF_PRMONCALREADY_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_92_prmoncalready(void)
{
    uint8_t reg_value = spi_read(PHY_RF_PRMONCALREADY_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}


/**
* @brief prmonnmosval register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             prmonnmosval                0.0           0x92
* </pre>
*/
#define PHY_RF_PRMONNMOSVAL_ADDRESS     0x0B

__INLINE uint8_t spi_read_pg_92_prmonnmosval(void)
{
    uint8_t reg_value = spi_read(PHY_RF_PRMONNMOSVAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief prmonpmosval register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             prmonpmosval                0.0           0x92
* </pre>
*/
#define PHY_RF_PRMONPMOSVAL_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_92_prmonpmosval(void)
{
    uint8_t reg_value = spi_read(PHY_RF_PRMONPMOSVAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief xoftun_0x0E register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 9:8             xoftun_0x0E                 0.0           0x92
* </pre>
*/
#define PHY_RF_XOFTUN_0X0E_ADDRESS     0x0E

__INLINE uint8_t spi_read_pg_92_xoftun_0x0E(void)
{
    uint8_t reg_value = spi_read(PHY_RF_XOFTUN_0X0E_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_92_xoftun_0x0E(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_XOFTUN_0X0E_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_XOFTUN_0X0E_ADDRESS, value_to_write);
}


/**
* @brief xoftun_0x0F register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             xoftun_0x0F                 0.0           0x92
* </pre>
*/
#define PHY_RF_XOFTUN_0X0F_ADDRESS     0x0F

__INLINE uint8_t spi_read_pg_92_xoftun_0x0F(void)
{
    uint8_t reg_value = spi_read(PHY_RF_XOFTUN_0X0F_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_92_xoftun_0x0F(uint8_t value)
{
    spi_write(PHY_RF_XOFTUN_0X0F_ADDRESS, value);
}


/**
* @brief xojittercap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             xojittercap                 0.0           0x92
* </pre>
*/
#define PHY_RF_XOJITTERCAP_ADDRESS     0x1A

__INLINE uint8_t spi_read_pg_92_xojittercap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_XOJITTERCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_92_xojittercap(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_XOJITTERCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_XOJITTERCAP_ADDRESS, value_to_write);
}


#endif //_REG_PHY_OLYMPUS_CALIBRATION_XO_REGISTERS_H_
