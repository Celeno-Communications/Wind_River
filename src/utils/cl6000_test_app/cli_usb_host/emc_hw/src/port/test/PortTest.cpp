#include "emc/hw/port/test/PortTest.hpp"
#include "emc/hw/port/Port.h"

namespace emcpp {

  PortTest::PortTest(std::uintptr_t base_address)
    : _base_address(base_address)
    , _memory(nullptr)
  {
    if (_base_address == 0) {
      _memory = new unsigned[SIZE];
      _memory_size = SIZE;
      _base_address = reinterpret_cast<std::uintptr_t>(_memory);
    }
  }

  PortTest::~PortTest()
  {
    if (_memory) {
      delete[]_memory;
    }
  }

  void PortTest::test_create_destroy()
  {
    EMC_HW_Port* port = create_port(base_address());
    EMCPP_TEST_ASSERT_TRUE(port);

    delete_port(port);
  }

  void PortTest::test_register_write_read()
  {
    EMC_HW_Port* port = create_port(base_address());
    EMCPP_TEST_ASSERT_TRUE(port);

    std::uintptr_t address = base_address() + 0x04;
    std::uint32_t  value = 0xAAAABBBB;
    EMC_HW_Port_write32(port, &address, value);
    std::uint32_t read_value = 0;
    EMC_HW_Port_read32(port, &address, &read_value);
    EMCPP_TEST_ASSERT_EQ(value, read_value);

    delete_port(port);
  }

#if EMC_HW_PORT_READ_HOOK
  void PortTest::test_read_hook()
  {
    EMC_HW_Port* port = create_port(base_address());
    EMCPP_TEST_ASSERT_TRUE(port);

    std::uintptr_t address = (base_address() + SIZE) - 8;
    std::uint32_t  read_value = 0;
    std::uint32_t  value = 0x5555AAAA;

    EMC_HW_Port_write32(port, address, value);

    EMC_HW_Port_read32(port, address, &read_value);
    EMCPP_TEST_ASSERT_EQ(0xDEADBEEF, read_value);

    delete_port(port);
  }
#endif

#if EMC_HW_PORT_WRITE_HOOK
  void PortTest::test_write_hook()
  {
    EMC_HW_Port* port = create_port(base_address());
    EMCPP_TEST_ASSERT_TRUE(port);

    std::uintptr_t address = (base_address() + SIZE) - 4;
    std::uint32_t  read_value = 0;
    std::uint32_t  value = 0xAAAA5555;

    EMC_HW_Port_write32(port, address, value);

    read_value = 0;
    EMC_HW_Port_read32(port, address, &read_value);
    EMCPP_TEST_ASSERT_EQ(0xBABEFACE, read_value);

    delete_port(port);
  }
#endif

}

EMC_EXTERN_C_BEGIN;

#if EMC_HW_PORT_READ_HOOK
void EMC_HW_Port_read_hook(emc_std_uintptr_t address, emc_std_uint32_t* value)
{
  UNUSED_PARAM(address);

  if (0x5555AAAA == *value) {
    *value = 0xDEADBEEF;
  }
}

#endif

#if EMC_HW_PORT_WRITE_HOOK
void EMC_HW_Port_write_hook(emc_std_uintptr_t address, emc_std_uint32_t* value)
{
  UNUSED_PARAM(address);

  if (0xAAAA5555 == *value) {
    *value = 0xBABEFACE;
  }
}

#endif

EMC_EXTERN_C_END;
