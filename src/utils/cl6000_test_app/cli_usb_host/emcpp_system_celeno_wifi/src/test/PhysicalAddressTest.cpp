/**
 * @file
 * @author  Ralf Oberländer <ralf.oberlaender@emsys.de>
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include "emcpp/test/UnitTest.hpp"
#include "emc/hw/memory/PhysicalAddress.h"
#include "emc/vendor/celeno/device/MiscReg.h"
#include "emc/vendor/celeno/device/AsicVersion.h"

extern emc_std_uint32_t chip_version;

namespace emcpp { namespace system { namespace celeno {

  class PhysicalAddressTest : public test::TestFixture {
  public:
    void test_supported()
    {
      EMCPP_TEST_ASSERT_EQ(1, EMC_PhysicalAddress_is_supported());
    }

    void test_dram()
    {
      EMCPP_TEST_ASSERT_EQ(0x6027FFFFu, EMC_PhysicalAddress_new((void*)0x6027FFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x60280000u, EMC_PhysicalAddress_new((void*)0x40000000).handle);
      EMCPP_TEST_ASSERT_EQ(0x602800FEu, EMC_PhysicalAddress_new((void*)0x400000FE).handle);
      EMCPP_TEST_ASSERT_EQ(0x6029FFFFu, EMC_PhysicalAddress_new((void*)0x4001FFFF).handle);
      EMCPP_TEST_ASSERT_EQ(0x602A0000u, EMC_PhysicalAddress_new((void*)0x40020000).handle);
      EMCPP_TEST_ASSERT_EQ(0x602AFFFFu, EMC_PhysicalAddress_new((void*)0x4002FFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x602B0000u, EMC_PhysicalAddress_new((void*)0x40030000).handle);
      EMCPP_TEST_ASSERT_EQ(0x602BFFFFu, EMC_PhysicalAddress_new((void*)0x4003FFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x40040000u, EMC_PhysicalAddress_new((void*)0x40040000).handle);

      EMCPP_TEST_ASSERT_EQ(0x602A0000u, EMC_PhysicalAddress_new((void*)0x602A0000u).handle);
    }

    void test_iram()
    {
      chip_version = 0x006000A0;

      EMC_System_Celeno_InitAsicVersion();
      EMCPP_TEST_ASSERT_EQ(0x602BFFFFu, EMC_PhysicalAddress_new((void*)0x602BFFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x602C0000u, EMC_PhysicalAddress_new((void*)0x40080000).handle);
      EMCPP_TEST_ASSERT_EQ(0x602C00FEu, EMC_PhysicalAddress_new((void*)0x400800FE).handle);
      EMCPP_TEST_ASSERT_EQ(0x602DFFFFu, EMC_PhysicalAddress_new((void*)0x4009FFFF).handle);
      EMCPP_TEST_ASSERT_EQ(0x602E0000u, EMC_PhysicalAddress_new((void*)0x400A0000).handle);
      EMCPP_TEST_ASSERT_EQ(0x602EFFFFu, EMC_PhysicalAddress_new((void*)0x400AFFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x602F0000u, EMC_PhysicalAddress_new((void*)0x400B0000).handle);
      EMCPP_TEST_ASSERT_EQ(0x602FFFFFu, EMC_PhysicalAddress_new((void*)0x400BFFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x400C0000u, EMC_PhysicalAddress_new((void*)0x400C0000).handle);

      EMCPP_TEST_ASSERT_EQ(0x602E0000u, EMC_PhysicalAddress_new((void*)0x602E0000u).handle);
    }

    void test_iram_B()
    {
      chip_version = 0x006000B0;
      EMC_System_Celeno_InitAsicVersion();
      EMCPP_TEST_ASSERT_EQ(0x602BFFFFu, EMC_PhysicalAddress_new((void*)0x602BFFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x60500000u, EMC_PhysicalAddress_new((void*)0x40080000).handle);
      EMCPP_TEST_ASSERT_EQ(0x605000FEu, EMC_PhysicalAddress_new((void*)0x400800FE).handle);
      EMCPP_TEST_ASSERT_EQ(0x6051FFFFu, EMC_PhysicalAddress_new((void*)0x4009FFFF).handle);
      EMCPP_TEST_ASSERT_EQ(0x60520000u, EMC_PhysicalAddress_new((void*)0x400A0000).handle);
      EMCPP_TEST_ASSERT_EQ(0x6052FFFFu, EMC_PhysicalAddress_new((void*)0x400AFFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x60530000u, EMC_PhysicalAddress_new((void*)0x400B0000).handle);
      EMCPP_TEST_ASSERT_EQ(0x6053FFFFu, EMC_PhysicalAddress_new((void*)0x400BFFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x60570000u, EMC_PhysicalAddress_new((void*)0x400F0000).handle);
      EMCPP_TEST_ASSERT_EQ(0x6057FFFFu, EMC_PhysicalAddress_new((void*)0x400FFFFF).handle);

      EMCPP_TEST_ASSERT_EQ(0x40100000u, EMC_PhysicalAddress_new((void*)0x40100000).handle);

      EMCPP_TEST_ASSERT_EQ(0x602E0000u, EMC_PhysicalAddress_new((void*)0x602E0000u).handle);
    }

    void test_irom()
    {
      // irom nor reachable
      EMCPP_TEST_ASSERT_EQ(0x4FFFFFFFu, EMC_PhysicalAddress_new((void*)0x4FFFFFFF).handle);
      EMCPP_TEST_ASSERT_EQ(0x50000000u, EMC_PhysicalAddress_new((void*)0x50000000).handle);
      EMCPP_TEST_ASSERT_EQ(0x50000033u, EMC_PhysicalAddress_new((void*)0x50000033).handle);
      EMCPP_TEST_ASSERT_EQ(0x5000FFFFu, EMC_PhysicalAddress_new((void*)0x5000FFFF).handle);
      EMCPP_TEST_ASSERT_EQ(0x50010000u, EMC_PhysicalAddress_new((void*)0x50010000).handle);
    }

    void test_shared_ram()
    {
      EMCPP_TEST_ASSERT_EQ(0x60000000u, EMC_PhysicalAddress_new((void*)0x60000000u).handle);
      EMCPP_TEST_ASSERT_EQ(0x60033000u, EMC_PhysicalAddress_new((void*)0x60033000u).handle);
      EMCPP_TEST_ASSERT_EQ(0x54545454u, EMC_PhysicalAddress_new((void*)0x54545454u).handle);
    }

    EMCPP_TEST_SUITE(PhysicalAddressTest);
    EMCPP_TEST_ADD(test_supported);
    EMCPP_TEST_ADD(test_dram);
    EMCPP_TEST_ADD(test_iram);
    EMCPP_TEST_ADD(test_iram_B);
    EMCPP_TEST_ADD(test_irom);
    EMCPP_TEST_ADD(test_shared_ram);
    EMCPP_TEST_SUITE_END();

  };

  EMCPP_TEST_SUITE_INSTANTIATION(PhysicalAddressTest);

}}}
