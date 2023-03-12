#ifndef _REG_PHY_OLYMPUS_SXX_REGISTERS_PAGED_0X9Y_H_
#define _REG_PHY_OLYMPUS_SXX_REGISTERS_PAGED_0X9Y_H_

#include "phy_hw.h"
#include "compiler.h"
/**
* @brief sxvcohldoen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxvcohldoen                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOHLDOEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_9y_sxvcohldoen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOHLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxvcohldoen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOHLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOHLDOEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcohen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxvcohen                    0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOHEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_9y_sxvcohen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOHEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxvcohen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOHEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOHEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcohdrven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sxvcohdrven                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOHDRVEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_9y_sxvcohdrven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOHDRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxvcohdrven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOHDRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOHDRVEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcohlodrven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               sxvcohlodrven               0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOHLODRVEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_9y_sxvcohlodrven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOHLODRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxvcohlodrven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOHLODRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOHLODRVEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcolldoen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               sxvcolldoen                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOLLDOEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_9y_sxvcolldoen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxvcolldoen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOLLDOEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcolen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               sxvcolen                    0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOLEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_9y_sxvcolen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_9y_sxvcolen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOLEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcoldrven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               sxvcoldrven                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOLDRVEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_9y_sxvcoldrven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLDRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_9y_sxvcoldrven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLDRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOLDRVEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcollodrven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               sxvcollodrven               0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOLLODRVEN_ADDRESS     0x06

__INLINE uint8_t spi_read_pg_9y_sxvcollodrven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLLODRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxvcollodrven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLLODRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOLLODRVEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcodeten register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxvcodeten                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCODETEN_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_9y_sxvcodeten(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxvcodeten(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCODETEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcodetptatcurren register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxvcodetptatcurren          1.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCODETPTATCURREN_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_9y_sxvcodetptatcurren(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETPTATCURREN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxvcodetptatcurren(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETPTATCURREN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCODETPTATCURREN_ADDRESS, value_to_write);
}


/**
* @brief sxvcodetvcosel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sxvcodetvcosel              1.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCODETVCOSEL_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_9y_sxvcodetvcosel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETVCOSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxvcodetvcosel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETVCOSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCODETVCOSEL_ADDRESS, value_to_write);
}


/**
* @brief sxvcodetread register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               sxvcodetread                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCODETREAD_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_9y_sxvcodetread(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETREAD_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxvcodetread(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETREAD_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCODETREAD_ADDRESS, value_to_write);
}


/**
* @brief sxvcodetrefsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             sxvcodetrefsel              7.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCODETREFSEL_ADDRESS     0x07

__INLINE uint8_t spi_read_pg_9y_sxvcodetrefsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETREFSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxvcodetrefsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETREFSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCODETREFSEL_ADDRESS, value_to_write);
}


/**
* @brief sxvcoldo1ven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxvcoldo1ven                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOLDO1VEN_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_9y_sxvcoldo1ven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLDO1VEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxvcoldo1ven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOLDO1VEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOLDO1VEN_ADDRESS, value_to_write);
}


/**
* @brief sxvcocurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             sxvcocurrsel                15.0          0x9Y
* </pre>
*/
#define PHY_RF_SXVCOCURRSEL_ADDRESS     0x08

__INLINE uint8_t spi_read_pg_9y_sxvcocurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxvcocurrsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOCURRSEL_ADDRESS, value_to_write);
}


/**
* @brief sxvcoptatcurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:6             sxvcoptatcurrsel            0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXVCOPTATCURRSEL_ADDRESS     0x09

__INLINE uint8_t spi_read_pg_9y_sxvcoptatcurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOPTATCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxvcoptatcurrsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOPTATCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXVCOPTATCURRSEL_ADDRESS, value_to_write);
}


/**
* @brief sxvcoftun register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sxvcoftun                   127.0         0x9Y
* </pre>
*/
#define PHY_RF_SXVCOFTUN_ADDRESS     0x0A

__INLINE uint8_t spi_read_pg_9y_sxvcoftun(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOFTUN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxvcoftun(uint8_t value)
{
    spi_write(PHY_RF_SXVCOFTUN_ADDRESS, value);
}


/**
* @brief sxvcodetout register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               sxvcodetout                 0             0x9Y
* </pre>
*/
#define PHY_RF_SXVCODETOUT_ADDRESS     0x0B

__INLINE uint8_t spi_read_pg_9y_sxvcodetout(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCODETOUT_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxpfdcpldoen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxpfdcpldoen                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPFDCPLDOEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_9y_sxpfdcpldoen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDCPLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxpfdcpldoen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDCPLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPFDCPLDOEN_ADDRESS, value_to_write);
}


/**
* @brief sxpfdcpen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxpfdcpen                   0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPFDCPEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_9y_sxpfdcpen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDCPEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxpfdcpen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDCPEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPFDCPEN_ADDRESS, value_to_write);
}


/**
* @brief sxpfddesel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sxpfddesel                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPFDDESEL_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_9y_sxpfddesel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDDESEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxpfddesel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDDESEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPFDDESEL_ADDRESS, value_to_write);
}


/**
* @brief sxcpcurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:3             sxcpcurrsel                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXCPCURRSEL_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_9y_sxcpcurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCPCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxcpcurrsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCPCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXCPCURRSEL_ADDRESS, value_to_write);
}


/**
* @brief sxcpdnlinen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               sxcpdnlinen                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXCPDNLINEN_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_9y_sxcpdnlinen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCPDNLINEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_9y_sxcpdnlinen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCPDNLINEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXCPDNLINEN_ADDRESS, value_to_write);
}


/**
* @brief sxpfdtristate register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               sxpfdtristate               0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPFDTRISTATE_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_9y_sxpfdtristate(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDTRISTATE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_9y_sxpfdtristate(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDTRISTATE_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPFDTRISTATE_ADDRESS, value_to_write);
}


/**
* @brief sxpfdsyncsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               sxpfdsyncsel                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPFDSYNCSEL_ADDRESS     0x0C

__INLINE uint8_t spi_read_pg_9y_sxpfdsyncsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDSYNCSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxpfdsyncsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDSYNCSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPFDSYNCSEL_ADDRESS, value_to_write);
}


/**
* @brief sxpfddnen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxpfddnen                   0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPFDDNEN_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_9y_sxpfddnen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDDNEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxpfddnen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDDNEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPFDDNEN_ADDRESS, value_to_write);
}


/**
* @brief sxpfdsmplen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxpfdsmplen                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPFDSMPLEN_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_9y_sxpfdsmplen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDSMPLEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxpfdsmplen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDSMPLEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPFDSMPLEN_ADDRESS, value_to_write);
}


/**
* @brief sxcprdgsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5:4             sxcprdgsel                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXCPRDGSEL_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_9y_sxcprdgsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCPRDGSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxcprdgsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCPRDGSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXCPRDGSEL_ADDRESS, value_to_write);
}


/**
* @brief sxdivcalclksel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               sxdivcalclksel              0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXDIVCALCLKSEL_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_9y_sxdivcalclksel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVCALCLKSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxdivcalclksel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVCALCLKSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXDIVCALCLKSEL_ADDRESS, value_to_write);
}


/**
* @brief sxdivcalen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               sxdivcalen                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXDIVCALEN_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_9y_sxdivcalen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVCALEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_9y_sxdivcalen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVCALEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXDIVCALEN_ADDRESS, value_to_write);
}


/**
* @brief sxdivmdiven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               sxdivmdiven                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXDIVMDIVEN_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_9y_sxdivmdiven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVMDIVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_9y_sxdivmdiven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVMDIVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXDIVMDIVEN_ADDRESS, value_to_write);
}


/**
* @brief sxdivpdiven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               sxdivpdiven                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXDIVPDIVEN_ADDRESS     0x0D

__INLINE uint8_t spi_read_pg_9y_sxdivpdiven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVPDIVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxdivpdiven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVPDIVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXDIVPDIVEN_ADDRESS, value_to_write);
}


/**
* @brief sxdivsdmen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxdivsdmen                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXDIVSDMEN_ADDRESS     0x0E

__INLINE uint8_t spi_read_pg_9y_sxdivsdmen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVSDMEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxdivsdmen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVSDMEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXDIVSDMEN_ADDRESS, value_to_write);
}


/**
* @brief sxdivplswsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6:5             sxdivplswsel                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXDIVPLSWSEL_ADDRESS     0x0E

__INLINE uint8_t spi_read_pg_9y_sxdivplswsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVPLSWSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxdivplswsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVPLSWSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXDIVPLSWSEL_ADDRESS, value_to_write);
}


/**
* @brief sxsdmdithen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sxsdmdithen                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXSDMDITHEN_ADDRESS     0x0F

__INLINE uint8_t spi_read_pg_9y_sxsdmdithen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXSDMDITHEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxsdmdithen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXSDMDITHEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXSDMDITHEN_ADDRESS, value_to_write);
}


/**
* @brief sxcalfreqcntr_0x10 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 17:16           sxcalfreqcntr_0x10          0             0x9Y
* </pre>
*/
#define PHY_RF_SXCALFREQCNTR_0X10_ADDRESS     0x10

__INLINE uint8_t spi_read_pg_9y_sxcalfreqcntr_0x10(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCALFREQCNTR_0X10_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxcalfreqcntr_0x11 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sxcalfreqcntr_0x11          0             0x9Y
* </pre>
*/
#define PHY_RF_SXCALFREQCNTR_0X11_ADDRESS     0x11

__INLINE uint8_t spi_read_pg_9y_sxcalfreqcntr_0x11(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCALFREQCNTR_0X11_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxcalfreqcntr_0x12 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sxcalfreqcntr_0x12          0             0x9Y
* </pre>
*/
#define PHY_RF_SXCALFREQCNTR_0X12_ADDRESS     0x12

__INLINE uint8_t spi_read_pg_9y_sxcalfreqcntr_0x12(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCALFREQCNTR_0X12_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxsdmfullrange register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxsdmfullrange              0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXSDMFULLRANGE_ADDRESS     0x13

__INLINE uint8_t spi_read_pg_9y_sxsdmfullrange(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXSDMFULLRANGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxsdmfullrange(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXSDMFULLRANGE_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXSDMFULLRANGE_ADDRESS, value_to_write);
}


/**
* @brief sxdivldoen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxdivldoen                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXDIVLDOEN_ADDRESS     0x13

__INLINE uint8_t spi_read_pg_9y_sxdivldoen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxdivldoen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXDIVLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXDIVLDOEN_ADDRESS, value_to_write);
}


/**
* @brief sxsdmorder register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sxsdmorder                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXSDMORDER_ADDRESS     0x13

__INLINE uint8_t spi_read_pg_9y_sxsdmorder(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXSDMORDER_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxsdmorder(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXSDMORDER_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXSDMORDER_ADDRESS, value_to_write);
}


/**
* @brief sxlpfc1 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             sxlpfc1                     0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFC1_ADDRESS     0x14

__INLINE uint8_t spi_read_pg_9y_sxlpfc1(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFC1_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfc1(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFC1_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFC1_ADDRESS, value_to_write);
}


/**
* @brief sxlpfc3 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:2             sxlpfc3                     0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFC3_ADDRESS     0x14

__INLINE uint8_t spi_read_pg_9y_sxlpfc3(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFC3_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfc3(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFC3_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFC3_ADDRESS, value_to_write);
}


/**
* @brief sxlpfr2 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:3             sxlpfr2                     0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFR2_ADDRESS     0x15

__INLINE uint8_t spi_read_pg_9y_sxlpfr2(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFR2_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfr2(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFR2_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFR2_ADDRESS, value_to_write);
}


/**
* @brief sxlpfselvcll register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2:0             sxlpfselvcll                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFSELVCLL_ADDRESS     0x15

__INLINE uint8_t spi_read_pg_9y_sxlpfselvcll(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFSELVCLL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfselvcll(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFSELVCLL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFSELVCLL_ADDRESS, value_to_write);
}


/**
* @brief sxlpfselvcul register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             sxlpfselvcul                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFSELVCUL_ADDRESS     0x16

__INLINE uint8_t spi_read_pg_9y_sxlpfselvcul(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFSELVCUL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfselvcul(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFSELVCUL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFSELVCUL_ADDRESS, value_to_write);
}


/**
* @brief sxlpfcalen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               sxlpfcalen                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFCALEN_ADDRESS     0x16

__INLINE uint8_t spi_read_pg_9y_sxlpfcalen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFCALEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfcalen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFCALEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFCALEN_ADDRESS, value_to_write);
}


/**
* @brief sxlpfcmpen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               sxlpfcmpen                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFCMPEN_ADDRESS     0x16

__INLINE uint8_t spi_read_pg_9y_sxlpfcmpen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFCMPEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfcmpen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFCMPEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFCMPEN_ADDRESS, value_to_write);
}


/**
* @brief sxvctrllow register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               sxvctrllow                  0             0x9Y
* </pre>
*/
#define PHY_RF_SXVCTRLLOW_ADDRESS     0x17

__INLINE uint8_t spi_read_pg_9y_sxvctrllow(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCTRLLOW_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}


/**
* @brief sxvctrlhigh register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               sxvctrlhigh                 0             0x9Y
* </pre>
*/
#define PHY_RF_SXVCTRLHIGH_ADDRESS     0x17

__INLINE uint8_t spi_read_pg_9y_sxvctrlhigh(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCTRLHIGH_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxlogenldoen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxlogenldoen                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENLDOEN_ADDRESS     0x18

__INLINE uint8_t spi_read_pg_9y_sxlogenldoen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenldoen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENLDOEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENLDOEN_ADDRESS, value_to_write);
}


/**
* @brief sxlogenmixen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxlogenmixen                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENMIXEN_ADDRESS     0x18

__INLINE uint8_t spi_read_pg_9y_sxlogenmixen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenmixen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENMIXEN_ADDRESS, value_to_write);
}


/**
* @brief sxlogendiv2drven register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sxlogendiv2drven            0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENDIV2DRVEN_ADDRESS     0x18

__INLINE uint8_t spi_read_pg_9y_sxlogendiv2drven(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENDIV2DRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxlogendiv2drven(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENDIV2DRVEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENDIV2DRVEN_ADDRESS, value_to_write);
}


/**
* @brief sxlogenbuffen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               sxlogenbuffen               0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENBUFFEN_ADDRESS     0x18

__INLINE uint8_t spi_read_pg_9y_sxlogenbuffen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENBUFFEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenbuffen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENBUFFEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENBUFFEN_ADDRESS, value_to_write);
}


/**
* @brief sxlogenmixdivinbias register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5:4             sxlogenmixdivinbias         2.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENMIXDIVINBIAS_ADDRESS     0x19

__INLINE uint8_t spi_read_pg_9y_sxlogenmixdivinbias(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXDIVINBIAS_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenmixdivinbias(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXDIVINBIAS_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENMIXDIVINBIAS_ADDRESS, value_to_write);
}


/**
* @brief sxlogenmixvcoinbias register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1:0             sxlogenmixvcoinbias         2.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENMIXVCOINBIAS_ADDRESS     0x19

__INLINE uint8_t spi_read_pg_9y_sxlogenmixvcoinbias(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXVCOINBIAS_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenmixvcoinbias(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXVCOINBIAS_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENMIXVCOINBIAS_ADDRESS, value_to_write);
}


/**
* @brief sxlogenbuffinbias register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5:4             sxlogenbuffinbias           2.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENBUFFINBIAS_ADDRESS     0x1A

__INLINE uint8_t spi_read_pg_9y_sxlogenbuffinbias(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENBUFFINBIAS_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenbuffinbias(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENBUFFINBIAS_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENBUFFINBIAS_ADDRESS, value_to_write);
}


/**
* @brief sxlogenmixcurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2:0             sxlogenmixcurrsel           3.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENMIXCURRSEL_ADDRESS     0x1A

__INLINE uint8_t spi_read_pg_9y_sxlogenmixcurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenmixcurrsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENMIXCURRSEL_ADDRESS, value_to_write);
}


/**
* @brief sxlogenbuffcurrsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:5             sxlogenbuffcurrsel          7.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENBUFFCURRSEL_ADDRESS     0x1B

__INLINE uint8_t spi_read_pg_9y_sxlogenbuffcurrsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENBUFFCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x7;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenbuffcurrsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENBUFFCURRSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x7 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENBUFFCURRSEL_ADDRESS, value_to_write);
}


/**
* @brief sxlogenmixcap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:0             sxlogenmixcap               0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENMIXCAP_ADDRESS     0x1B

__INLINE uint8_t spi_read_pg_9y_sxlogenmixcap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenmixcap(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENMIXCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENMIXCAP_ADDRESS, value_to_write);
}


/**
* @brief sxlogenbuffcap register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             sxlogenbuffcap              0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOGENBUFFCAP_ADDRESS     0x1C

__INLINE uint8_t spi_read_pg_9y_sxlogenbuffcap(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENBUFFCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxlogenbuffcap(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOGENBUFFCAP_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOGENBUFFCAP_ADDRESS, value_to_write);
}


/**
* @brief sxlockdetavg register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3:2             sxlockdetavg                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOCKDETAVG_ADDRESS     0X1C

__INLINE uint8_t spi_read_pg_9y_sxlockdetavg(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOCKDETAVG_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_9y_sxlockdetavg(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOCKDETAVG_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOCKDETAVG_ADDRESS, value_to_write);
}


/**
* @brief sxfsmbypass register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               sxfsmbypass                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXFSMBYPASS_ADDRESS     0X1C

__INLINE uint8_t spi_read_pg_9y_sxfsmbypass(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXFSMBYPASS_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_9y_sxfsmbypass(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXFSMBYPASS_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXFSMBYPASS_ADDRESS, value_to_write);
}


/**
* @brief sxlocktol register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:6             sxlocktol                   0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOCKTOL_ADDRESS     0x1D

__INLINE uint8_t spi_read_pg_9y_sxlocktol(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOCKTOL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxlocktol(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOCKTOL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOCKTOL_ADDRESS, value_to_write);
}


/**
* @brief sxlockdeten register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sxlockdeten                 0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLOCKDETEN_ADDRESS     0x1D

__INLINE uint8_t spi_read_pg_9y_sxlockdeten(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOCKDETEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxlockdeten(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLOCKDETEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLOCKDETEN_ADDRESS, value_to_write);
}


/**
* @brief sxamplupdateper register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:3             sxamplupdateper             0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXAMPLUPDATEPER_ADDRESS     0x1D

__INLINE uint8_t spi_read_pg_9y_sxamplupdateper(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXAMPLUPDATEPER_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxamplupdateper(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXAMPLUPDATEPER_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXAMPLUPDATEPER_ADDRESS, value_to_write);
}


/**
* @brief sxfrequpdateper register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2:1             sxfrequpdateper             0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXFREQUPDATEPER_ADDRESS     0x1D

__INLINE uint8_t spi_read_pg_9y_sxfrequpdateper(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXFREQUPDATEPER_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_9y_sxfrequpdateper(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXFREQUPDATEPER_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXFREQUPDATEPER_ADDRESS, value_to_write);
}


/**
* @brief sx_nfrac_select register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               sx_nfrac_select             0.0           0x9Y
* </pre>
*/
#define PHY_RF_SX_NFRAC_SELECT_ADDRESS     0x1D

__INLINE uint8_t spi_read_pg_9y_sx_nfrac_select(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX_NFRAC_SELECT_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sx_nfrac_select(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX_NFRAC_SELECT_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX_NFRAC_SELECT_ADDRESS, value_to_write);
}


/**
* @brief sxlpfr2caloffset register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:4             sxlpfr2caloffset            0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFR2CALOFFSET_ADDRESS     0x1E

__INLINE uint8_t spi_read_pg_9y_sxlpfr2caloffset(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFR2CALOFFSET_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xF;
    return (reg_value >> 4) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfr2caloffset(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFR2CALOFFSET_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0xF << 4);
    value = value << 4;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFR2CALOFFSET_ADDRESS, value_to_write);
}


/**
* @brief sxlpfr2caloffseten register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               sxlpfr2caloffseten          0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFR2CALOFFSETEN_ADDRESS     0x1E

__INLINE uint8_t spi_read_pg_9y_sxlpfr2caloffseten(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFR2CALOFFSETEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxlpfr2caloffseten(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFR2CALOFFSETEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFR2CALOFFSETEN_ADDRESS, value_to_write);
}


/**
* @brief sxampcalfiltsamples register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2:1             sxampcalfiltsamples         0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXAMPCALFILTSAMPLES_ADDRESS     0x1E

__INLINE uint8_t spi_read_pg_9y_sxampcalfiltsamples(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXAMPCALFILTSAMPLES_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_9y_sxampcalfiltsamples(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXAMPCALFILTSAMPLES_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXAMPCALFILTSAMPLES_ADDRESS, value_to_write);
}


/**
* @brief sxlpfr2cal register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:3             sxlpfr2cal                  0             0x9Y
* </pre>
*/
#define PHY_RF_SXLPFR2CAL_ADDRESS     0x1F

__INLINE uint8_t spi_read_pg_9y_sxlpfr2cal(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFR2CAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 3) & mask;
}


/**
* @brief sxcpcurrselcal register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1:0             sxcpcurrselcal              0             0x9Y
* </pre>
*/
#define PHY_RF_SXCPCURRSELCAL_ADDRESS     0x1F

__INLINE uint8_t spi_read_pg_9y_sxcpcurrselcal(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCPCURRSELCAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxvcocurrselcal register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:3             sxvcocurrselcal             0             0x9Y
* </pre>
*/
#define PHY_RF_SXVCOCURRSELCAL_ADDRESS     0x20

__INLINE uint8_t spi_read_pg_9y_sxvcocurrselcal(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOCURRSELCAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 3) & mask;
}


/**
* @brief sxvcocurrptatcal register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1:0             sxvcocurrptatcal            0             0x9Y
* </pre>
*/
#define PHY_RF_SXVCOCURRPTATCAL_ADDRESS     0x20

__INLINE uint8_t spi_read_pg_9y_sxvcocurrptatcal(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOCURRPTATCAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxvcoftuncal register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sxvcoftuncal                0             0x9Y
* </pre>
*/
#define PHY_RF_SXVCOFTUNCAL_ADDRESS     0x21

__INLINE uint8_t spi_read_pg_9y_sxvcoftuncal(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXVCOFTUNCAL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxselxtalfreq register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxselxtalfreq               0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXSELXTALFREQ_ADDRESS     0x22

__INLINE uint8_t spi_read_pg_9y_sxselxtalfreq(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXSELXTALFREQ_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxselxtalfreq(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXSELXTALFREQ_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXSELXTALFREQ_ADDRESS, value_to_write);
}


/**
* @brief sxtempsens register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6:2             sxtempsens                  0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXTEMPSENS_ADDRESS     0x22

__INLINE uint8_t spi_read_pg_9y_sxtempsens(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENS_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_9y_sxtempsens(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENS_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXTEMPSENS_ADDRESS, value_to_write);
}


/**
* @brief sxtempsensth60 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             sxtempsensth60              0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXTEMPSENSTH60_ADDRESS     0x23

__INLINE uint8_t spi_read_pg_9y_sxtempsensth60(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSTH60_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxtempsensth60(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSTH60_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXTEMPSENSTH60_ADDRESS, value_to_write);
}


/**
* @brief sxtempsensth80 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             sxtempsensth80              0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXTEMPSENSTH80_ADDRESS     0x24

__INLINE uint8_t spi_read_pg_9y_sxtempsensth80(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSTH80_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxtempsensth80(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSTH80_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXTEMPSENSTH80_ADDRESS, value_to_write);
}


/**
* @brief sxtempsensth100 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             sxtempsensth100             0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXTEMPSENSTH100_ADDRESS     0x25

__INLINE uint8_t spi_read_pg_9y_sxtempsensth100(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSTH100_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxtempsensth100(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSTH100_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXTEMPSENSTH100_ADDRESS, value_to_write);
}


/**
* @brief sxtempsensth120 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:0             sxtempsensth120             0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXTEMPSENSTH120_ADDRESS     0x26

__INLINE uint8_t spi_read_pg_9y_sxtempsensth120(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSTH120_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxtempsensth120(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSTH120_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXTEMPSENSTH120_ADDRESS, value_to_write);
}


/**
* @brief sxtempsenscompen register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sxtempsenscompen            0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXTEMPSENSCOMPEN_ADDRESS     0x26

__INLINE uint8_t spi_read_pg_9y_sxtempsenscompen(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSCOMPEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_pg_9y_sxtempsenscompen(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXTEMPSENSCOMPEN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXTEMPSENSCOMPEN_ADDRESS, value_to_write);
}


/**
* @brief sxkvcomeasdur register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxkvcomeasdur               0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXKVCOMEASDUR_ADDRESS     0x26

__INLINE uint8_t spi_read_pg_9y_sxkvcomeasdur(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXKVCOMEASDUR_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxkvcomeasdur(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXKVCOMEASDUR_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXKVCOMEASDUR_ADDRESS, value_to_write);
}


/**
* @brief sxpfddnenman register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7               sxpfddnenman                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPFDDNENMAN_ADDRESS     0x27

__INLINE uint8_t spi_read_pg_9y_sxpfddnenman(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDDNENMAN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 7) & mask;
}

__INLINE void spi_write_pg_9y_sxpfddnenman(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPFDDNENMAN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 7);
    value = value << 7;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPFDDNENMAN_ADDRESS, value_to_write);
}


/**
* @brief sxcalclkldoff register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sxcalclkldoff               0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXCALCLKLDOFF_ADDRESS     0x27

__INLINE uint8_t spi_read_pg_9y_sxcalclkldoff(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCALCLKLDOFF_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_pg_9y_sxcalclkldoff(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXCALCLKLDOFF_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXCALCLKLDOFF_ADDRESS, value_to_write);
}


/**
* @brief sxampcalend register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               sxampcalend                 0             0x9Y
* </pre>
*/
#define PHY_RF_SXAMPCALEND_ADDRESS     0x2B

__INLINE uint8_t spi_read_pg_9y_sxampcalend(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXAMPCALEND_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}


/**
* @brief sxfreqcalend register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 1               sxfreqcalend                0             0x9Y
* </pre>
*/
#define PHY_RF_SXFREQCALEND_ADDRESS     0x2B

__INLINE uint8_t spi_read_pg_9y_sxfreqcalend(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXFREQCALEND_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 1) & mask;
}


/**
* @brief sxnooscdet register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               sxnooscdet                  0             0x9Y
* </pre>
*/
#define PHY_RF_SXNOOSCDET_ADDRESS     0x2B

__INLINE uint8_t spi_read_pg_9y_sxnooscdet(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXNOOSCDET_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}


/**
* @brief sxnooscdeterr register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 3               sxnooscdeterr               0             0x9Y
* </pre>
*/
#define PHY_RF_SXNOOSCDETERR_ADDRESS     0x2B

__INLINE uint8_t spi_read_pg_9y_sxnooscdeterr(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXNOOSCDETERR_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 3) & mask;
}


/**
* @brief sxplllocked register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4               sxplllocked                 0             0x9Y
* </pre>
*/
#define PHY_RF_SXPLLLOCKED_ADDRESS     0x2B

__INLINE uint8_t spi_read_pg_9y_sxplllocked(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPLLLOCKED_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 4) & mask;
}


/**
* @brief sxanamon register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:3             sxanamon                    0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXANAMON_ADDRESS     0x28

__INLINE uint8_t spi_read_pg_9y_sxanamon(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXANAMON_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxanamon(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXANAMON_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXANAMON_ADDRESS, value_to_write);
}


/**
* @brief sxlpftstselh register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2               sxlpftstselh                0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXLPFTSTSELH_ADDRESS     0x29

__INLINE uint8_t spi_read_pg_9y_sxlpftstselh(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFTSTSELH_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 2) & mask;
}

__INLINE void spi_write_pg_9y_sxlpftstselh(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXLPFTSTSELH_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 2);
    value = value << 2;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXLPFTSTSELH_ADDRESS, value_to_write);
}


/**
* @brief sxprdgseluptst register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 4:3             sxprdgseluptst              0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPRDGSELUPTST_ADDRESS     0x2A

__INLINE uint8_t spi_read_pg_9y_sxprdgseluptst(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPRDGSELUPTST_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 3) & mask;
}

__INLINE void spi_write_pg_9y_sxprdgseluptst(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPRDGSELUPTST_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 3);
    value = value << 3;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPRDGSELUPTST_ADDRESS, value_to_write);
}


/**
* @brief sxprdgseldntst register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 2:1             sxprdgseldntst              0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXPRDGSELDNTST_ADDRESS     0x2A

__INLINE uint8_t spi_read_pg_9y_sxprdgseldntst(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPRDGSELDNTST_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 1) & mask;
}

__INLINE void spi_write_pg_9y_sxprdgseldntst(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXPRDGSELDNTST_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 1);
    value = value << 1;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXPRDGSELDNTST_ADDRESS, value_to_write);
}


/**
* @brief sxbgren register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 0               sxbgren                     0.0           0x9Y
* </pre>
*/
#define PHY_RF_SXBGREN_ADDRESS     0x2A

__INLINE uint8_t spi_read_pg_9y_sxbgren(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SXBGREN_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_pg_9y_sxbgren(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SXBGREN_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SXBGREN_ADDRESS, value_to_write);
}


#endif //_REG_PHY_OLYMPUS_SXX_REGISTERS_PAGED_0X9Y_H_
