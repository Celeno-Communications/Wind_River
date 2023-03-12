#ifndef _REG_PHY_OLYMPUS_SXX_REGISTERS_UNPAGED_H_
#define _REG_PHY_OLYMPUS_SXX_REGISTERS_UNPAGED_H_

#include "phy_hw.h"
#include "compiler.h"
/**
* @brief sx0_calstart register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sx0_calstart                0.0           Global
* </pre>
*/
#define PHY_RF_SX0_CALSTART_ADDRESS     0x63

__INLINE uint8_t spi_read_sx0_calstart(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_CALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_sx0_calstart(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_CALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX0_CALSTART_ADDRESS, value_to_write);
}


/**
* @brief sx0_vcocalsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sx0_vcocalsel               0.0           Global
* </pre>
*/
#define PHY_RF_SX0_VCOCALSEL_ADDRESS     0x63

__INLINE uint8_t spi_read_sx0_vcocalsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_VCOCALSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_sx0_vcocalsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_VCOCALSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX0_VCOCALSEL_ADDRESS, value_to_write);
}


/**
* @brief sx0_nfrac_0x63 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 20:16           sx0_nfrac_0x63              0.0           Global
* </pre>
*/
#define PHY_RF_SX0_NFRAC_0X63_ADDRESS     0x63

__INLINE uint8_t spi_read_sx0_nfrac_0x63(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NFRAC_0X63_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_nfrac_0x63(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NFRAC_0X63_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX0_NFRAC_0X63_ADDRESS, value_to_write);
}


/**
* @brief sx0_nfrac_0x64 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sx0_nfrac_0x64              0.0           Global
* </pre>
*/
#define PHY_RF_SX0_NFRAC_0X64_ADDRESS     0x64

__INLINE uint8_t spi_read_sx0_nfrac_0x64(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NFRAC_0X64_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_nfrac_0x64(uint8_t value)
{
    spi_write(PHY_RF_SX0_NFRAC_0X64_ADDRESS, value);
}


/**
* @brief sx0_nfrac_0x65 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx0_nfrac_0x65              0.0           Global
* </pre>
*/
#define PHY_RF_SX0_NFRAC_0X65_ADDRESS     0x65

__INLINE uint8_t spi_read_sx0_nfrac_0x65(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NFRAC_0X65_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_nfrac_0x65(uint8_t value)
{
    spi_write(PHY_RF_SX0_NFRAC_0X65_ADDRESS, value);
}


/**
* @brief sx0_nfrac_2_0x66 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 20:16           sx0_nfrac_2_0x66            0.0           Global
* </pre>
*/
#define PHY_RF_SX0_NFRAC_2_0X66_ADDRESS     0x66

__INLINE uint8_t spi_read_sx0_nfrac_2_0x66(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NFRAC_2_0X66_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_nfrac_2_0x66(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NFRAC_2_0X66_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX0_NFRAC_2_0X66_ADDRESS, value_to_write);
}


/**
* @brief sx0_nfrac_2_0x67 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sx0_nfrac_2_0x67            0.0           Global
* </pre>
*/
#define PHY_RF_SX0_NFRAC_2_0X67_ADDRESS     0x67

__INLINE uint8_t spi_read_sx0_nfrac_2_0x67(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NFRAC_2_0X67_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_nfrac_2_0x67(uint8_t value)
{
    spi_write(PHY_RF_SX0_NFRAC_2_0X67_ADDRESS, value);
}


/**
* @brief sx0_nfrac_2_0x68 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx0_nfrac_2_0x68            0.0           Global
* </pre>
*/
#define PHY_RF_SX0_NFRAC_2_0X68_ADDRESS     0x68

__INLINE uint8_t spi_read_sx0_nfrac_2_0x68(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NFRAC_2_0X68_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_nfrac_2_0x68(uint8_t value)
{
    spi_write(PHY_RF_SX0_NFRAC_2_0X68_ADDRESS, value);
}


/**
* @brief sx0_nint register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx0_nint                    0.0           Global
* </pre>
*/
#define PHY_RF_SX0_NINT_ADDRESS     0x69

__INLINE uint8_t spi_read_sx0_nint(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_NINT_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_nint(uint8_t value)
{
    spi_write(PHY_RF_SX0_NINT_ADDRESS, value);
}


/**
* @brief sx0_freqmeasdur_0x6A register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 17:16           sx0_freqmeasdur_0x6A        0.0           Global
* </pre>
*/
#define PHY_RF_SX0_FREQMEASDUR_0X6A_ADDRESS     0x6A

__INLINE uint8_t spi_read_sx0_freqmeasdur_0x6A(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_FREQMEASDUR_0X6A_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_freqmeasdur_0x6A(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_FREQMEASDUR_0X6A_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX0_FREQMEASDUR_0X6A_ADDRESS, value_to_write);
}


/**
* @brief sx0_freqmeasdur_0x6B register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sx0_freqmeasdur_0x6B        0.0           Global
* </pre>
*/
#define PHY_RF_SX0_FREQMEASDUR_0X6B_ADDRESS     0x6B

__INLINE uint8_t spi_read_sx0_freqmeasdur_0x6B(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_FREQMEASDUR_0X6B_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_freqmeasdur_0x6B(uint8_t value)
{
    spi_write(PHY_RF_SX0_FREQMEASDUR_0X6B_ADDRESS, value);
}


/**
* @brief sx0_freqmeasdur_0x6C register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx0_freqmeasdur_0x6C        0.0           Global
* </pre>
*/
#define PHY_RF_SX0_FREQMEASDUR_0X6C_ADDRESS     0x6C

__INLINE uint8_t spi_read_sx0_freqmeasdur_0x6C(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_FREQMEASDUR_0X6C_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_freqmeasdur_0x6C(uint8_t value)
{
    spi_write(PHY_RF_SX0_FREQMEASDUR_0X6C_ADDRESS, value);
}


/**
* @brief sx0_freqmeastarg_0x6D register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 17:16           sx0_freqmeastarg_0x6D       0.0           Global
* </pre>
*/
#define PHY_RF_SX0_FREQMEASTARG_0X6D_ADDRESS     0x6D

__INLINE uint8_t spi_read_sx0_freqmeastarg_0x6D(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_FREQMEASTARG_0X6D_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_freqmeastarg_0x6D(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_FREQMEASTARG_0X6D_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX0_FREQMEASTARG_0X6D_ADDRESS, value_to_write);
}


/**
* @brief sx0_freqmeastarg_0x6E register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sx0_freqmeastarg_0x6E       0.0           Global
* </pre>
*/
#define PHY_RF_SX0_FREQMEASTARG_0X6E_ADDRESS     0x6E

__INLINE uint8_t spi_read_sx0_freqmeastarg_0x6E(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_FREQMEASTARG_0X6E_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_freqmeastarg_0x6E(uint8_t value)
{
    spi_write(PHY_RF_SX0_FREQMEASTARG_0X6E_ADDRESS, value);
}


/**
* @brief sx0_freqmeastarg_0x6F register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx0_freqmeastarg_0x6F       0.0           Global
* </pre>
*/
#define PHY_RF_SX0_FREQMEASTARG_0X6F_ADDRESS     0x6F

__INLINE uint8_t spi_read_sx0_freqmeastarg_0x6F(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX0_FREQMEASTARG_0X6F_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx0_freqmeastarg_0x6F(uint8_t value)
{
    spi_write(PHY_RF_SX0_FREQMEASTARG_0X6F_ADDRESS, value);
}


/**
* @brief sx1_calstart register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 6               sx1_calstart                0.0           Global
* </pre>
*/
#define PHY_RF_SX1_CALSTART_ADDRESS     0x71

__INLINE uint8_t spi_read_sx1_calstart(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_CALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 6) & mask;
}

__INLINE void spi_write_sx1_calstart(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_CALSTART_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 6);
    value = value << 6;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX1_CALSTART_ADDRESS, value_to_write);
}


/**
* @brief sx1_vcocalsel register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 5               sx1_vcocalsel               0.0           Global
* </pre>
*/
#define PHY_RF_SX1_VCOCALSEL_ADDRESS     0x71

__INLINE uint8_t spi_read_sx1_vcocalsel(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_VCOCALSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1;
    return (reg_value >> 5) & mask;
}

__INLINE void spi_write_sx1_vcocalsel(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_VCOCALSEL_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1 << 5);
    value = value << 5;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX1_VCOCALSEL_ADDRESS, value_to_write);
}


/**
* @brief sx1_nfrac_0x71 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 20:16           sx1_nfrac_0x71              0.0           Global
* </pre>
*/
#define PHY_RF_SX1_NFRAC_0X71_ADDRESS     0x71

__INLINE uint8_t spi_read_sx1_nfrac_0x71(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NFRAC_0X71_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_nfrac_0x71(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NFRAC_0X71_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX1_NFRAC_0X71_ADDRESS, value_to_write);
}


/**
* @brief sx1_nfrac_0x72 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sx1_nfrac_0x72              0.0           Global
* </pre>
*/
#define PHY_RF_SX1_NFRAC_0X72_ADDRESS     0x72

__INLINE uint8_t spi_read_sx1_nfrac_0x72(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NFRAC_0X72_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_nfrac_0x72(uint8_t value)
{
    spi_write(PHY_RF_SX1_NFRAC_0X72_ADDRESS, value);
}


/**
* @brief sx1_nfrac_0x73 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx1_nfrac_0x73              0.0           Global
* </pre>
*/
#define PHY_RF_SX1_NFRAC_0X73_ADDRESS     0x73

__INLINE uint8_t spi_read_sx1_nfrac_0x73(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NFRAC_0X73_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_nfrac_0x73(uint8_t value)
{
    spi_write(PHY_RF_SX1_NFRAC_0X73_ADDRESS, value);
}


/**
* @brief sx1_nfrac_2_0x74 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 20:16           sx1_nfrac_2_0x74            0.0           Global
* </pre>
*/
#define PHY_RF_SX1_NFRAC_2_0X74_ADDRESS     0x74

__INLINE uint8_t spi_read_sx1_nfrac_2_0x74(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NFRAC_2_0X74_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x1F;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_nfrac_2_0x74(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NFRAC_2_0X74_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x1F << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX1_NFRAC_2_0X74_ADDRESS, value_to_write);
}


/**
* @brief sx1_nfrac_2_0x75 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sx1_nfrac_2_0x75            0.0           Global
* </pre>
*/
#define PHY_RF_SX1_NFRAC_2_0X75_ADDRESS     0x75

__INLINE uint8_t spi_read_sx1_nfrac_2_0x75(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NFRAC_2_0X75_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_nfrac_2_0x75(uint8_t value)
{
    spi_write(PHY_RF_SX1_NFRAC_2_0X75_ADDRESS, value);
}


/**
* @brief sx1_nfrac_2_0x76 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx1_nfrac_2_0x76            0.0           Global
* </pre>
*/
#define PHY_RF_SX1_NFRAC_2_0X76_ADDRESS     0x76

__INLINE uint8_t spi_read_sx1_nfrac_2_0x76(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NFRAC_2_0X76_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_nfrac_2_0x76(uint8_t value)
{
    spi_write(PHY_RF_SX1_NFRAC_2_0X76_ADDRESS, value);
}


/**
* @brief sx1_nint register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx1_nint                    0.0           Global
* </pre>
*/
#define PHY_RF_SX1_NINT_ADDRESS     0x77

__INLINE uint8_t spi_read_sx1_nint(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_NINT_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_nint(uint8_t value)
{
    spi_write(PHY_RF_SX1_NINT_ADDRESS, value);
}


/**
* @brief sx1_freqmeasdur_0x78 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 17:16           sx1_freqmeasdur_0x78        0.0           Global
* </pre>
*/
#define PHY_RF_SX1_FREQMEASDUR_0X78_ADDRESS     0x78

__INLINE uint8_t spi_read_sx1_freqmeasdur_0x78(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_FREQMEASDUR_0X78_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_freqmeasdur_0x78(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_FREQMEASDUR_0X78_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX1_FREQMEASDUR_0X78_ADDRESS, value_to_write);
}


/**
* @brief sx1_freqmeasdur_0x79 register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sx1_freqmeasdur_0x79        0.0           Global
* </pre>
*/
#define PHY_RF_SX1_FREQMEASDUR_0X79_ADDRESS     0x79

__INLINE uint8_t spi_read_sx1_freqmeasdur_0x79(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_FREQMEASDUR_0X79_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_freqmeasdur_0x79(uint8_t value)
{
    spi_write(PHY_RF_SX1_FREQMEASDUR_0X79_ADDRESS, value);
}


/**
* @brief sx1_freqmeasdur_0x7A register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx1_freqmeasdur_0x7A        0.0           Global
* </pre>
*/
#define PHY_RF_SX1_FREQMEASDUR_0X7A_ADDRESS     0x7A

__INLINE uint8_t spi_read_sx1_freqmeasdur_0x7A(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_FREQMEASDUR_0X7A_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_freqmeasdur_0x7A(uint8_t value)
{
    spi_write(PHY_RF_SX1_FREQMEASDUR_0X7A_ADDRESS, value);
}


/**
* @brief sx1_freqmeastarg_0x7B register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 17:16           sx1_freqmeastarg_0x7B       0.0           Global
* </pre>
*/
#define PHY_RF_SX1_FREQMEASTARG_0X7B_ADDRESS     0x7B

__INLINE uint8_t spi_read_sx1_freqmeastarg_0x7B(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_FREQMEASTARG_0X7B_ADDRESS, 0);
    uint8_t mask = (uint8_t)0x3;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_freqmeastarg_0x7B(uint8_t value)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_FREQMEASTARG_0X7B_ADDRESS, 0);
    uint8_t mask = (uint8_t)~(0x3 << 0);
    value = value << 0;
    uint8_t value_to_write = (reg_value & (mask)) | value;
    spi_write(PHY_RF_SX1_FREQMEASTARG_0X7B_ADDRESS, value_to_write);
}


/**
* @brief sx1_freqmeastarg_0x7C register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 15:8            sx1_freqmeastarg_0x7C       0.0           Global
* </pre>
*/
#define PHY_RF_SX1_FREQMEASTARG_0X7C_ADDRESS     0x7C

__INLINE uint8_t spi_read_sx1_freqmeastarg_0x7C(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_FREQMEASTARG_0X7C_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_freqmeastarg_0x7C(uint8_t value)
{
    spi_write(PHY_RF_SX1_FREQMEASTARG_0X7C_ADDRESS, value);
}


/**
* @brief sx1_freqmeastarg_0x7D register definition
* <pre>
* Bits position   Field Name                  Reset Value   Page
* -------------   -------------------------   -----------   -----
* 7:0             sx1_freqmeastarg_0x7D       0.0           Global
* </pre>
*/
#define PHY_RF_SX1_FREQMEASTARG_0X7D_ADDRESS     0x7D

__INLINE uint8_t spi_read_sx1_freqmeastarg_0x7D(void)
{
    uint8_t reg_value = spi_read(PHY_RF_SX1_FREQMEASTARG_0X7D_ADDRESS, 0);
    uint8_t mask = (uint8_t)0xFF;
    return (reg_value >> 0) & mask;
}

__INLINE void spi_write_sx1_freqmeastarg_0x7D(uint8_t value)
{
    spi_write(PHY_RF_SX1_FREQMEASTARG_0X7D_ADDRESS, value);
}


#endif //_REG_PHY_OLYMPUS_SXX_REGISTERS_UNPAGED_H_
