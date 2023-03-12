/// Copyright (C) 2021 emsys Embedded Systems GmbH
#include "emc/test/unittest.h"
#include "emc/usb/alloc/GlobalPool.h"
#include "emc/std/string.h"

typedef struct TestDevice {
  EMC_USB_Allocatable alloc_type;
  emc_std_uint16_t    device_id;
  emc_std_uint32_t    data[32];
} TestDevice;

#define MAX_DEVICE 4

EMC_USB_DEFINE_POOL(TestDevice, MAX_DEVICE);

static TestDevice* devices[MAX_DEVICE];

static void setUp(void)
{
  emc_std_memset(&devices, 0, sizeof(devices));
}

static void tearDown(void) {}

EMC_CUNIT_START_TEST(EMC_USB_GlobalPool_alloc_dealloc_test) {

  {
    TestDevice* device = TestDevice_pool_allocate();
    EMC_CUNIT_ASSERT(0 != device);

    TestDevice_pool_deallocate(device);
  }
  {
    unsigned i;
    for (i = 0; i < MAX_DEVICE; ++i) {
      devices[i] = TestDevice_pool_allocate();
      EMC_CUNIT_ASSERT(0 != devices[i]);
    }
    {
      TestDevice* device = TestDevice_pool_allocate();
      EMC_CUNIT_ASSERT(0 == device);
    }
    for (i = 0; i < MAX_DEVICE; ++i) {
      TestDevice_pool_deallocate(devices[i]);
    }

    {
      TestDevice* device = TestDevice_pool_allocate();
      EMC_CUNIT_ASSERT(0 != device);

      TestDevice_pool_deallocate(device);
    }
  }

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_GlobalPool_lookup_test)
{
  {
    emc_std_uint16_t i;
    for (i = 0; i < MAX_DEVICE; ++i) {
      emc_std_uint16_t id = (emc_std_uint16_t)(i + 1);
      devices[i] = TestDevice_pool_allocate();
      EMC_CUNIT_ASSERT(0 != devices[i]);
      devices[i]->alloc_type.id = id;
    }
    for (i = 0; i < MAX_DEVICE; ++i) {
      emc_std_uint16_t     id = (emc_std_uint16_t)(i + 1);
      EMC_USB_Allocatable* alloc_type = TestDevice_pool_lookup(id);
      TestDevice*          device = (TestDevice*)alloc_type;
      EMC_CUNIT_ASSERT(0 != device);
      EMC_CUNIT_ASSERT(id == alloc_type->id);
      EMC_CUNIT_ASSERT(devices[i] == device);
    }

    for (i = 0; i < MAX_DEVICE; ++i) {
      TestDevice_pool_deallocate(devices[i]);
    }

    for (i = 0; i < MAX_DEVICE; ++i) {
      emc_std_uint16_t     id = (emc_std_uint16_t)(i + 1);
      EMC_USB_Allocatable* alloc_type = TestDevice_pool_lookup(id);
      TestDevice*          device = (TestDevice*)alloc_type;
      EMC_CUNIT_ASSERT(0 == device);
    }
  }

}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(EMC_USB_GlobalPool_Test);

EMC_CUNIT_TEST(EMC_USB_GlobalPool_alloc_dealloc_test);
EMC_CUNIT_TEST(EMC_USB_GlobalPool_lookup_test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(EMC_USB_GlobalPool_Test)

EMC_TEST_SUITE_DEFINE_MAIN()
