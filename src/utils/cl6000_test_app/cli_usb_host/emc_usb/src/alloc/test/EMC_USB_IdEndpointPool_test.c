/// Copyright (C) 2021 emsys Embedded Systems GmbH
#include "emc/test/unittest.h"
#include "emc/usb/alloc/IdEndpointPool.h"
#include "emc/usb/EndpointAddress.h"
#include "emc/usb/EndpointId.h"

typedef struct TestEndpoint {
  EMC_USB_Allocatable alloc_type;
  emc_std_uint8_t     address;
  emc_std_uint32_t    data[32];
} TestEndpoint;

#define MAX_DEVICE 2

#define MAX_ENDPOINT 32

EMC_USB_DEFINE_ID_EP_POOL(TestEndpoint, MAX_DEVICE, MAX_ENDPOINT);

static TestEndpoint* endpoints[MAX_ENDPOINT];

static void setUp(void)
{
  emc_std_memset(endpoints, 0, sizeof(endpoints));
  TestEndpoint_pool_initialize(0);
}

static void tearDown(void) {}

EMC_CUNIT_START_TEST(EMC_USB_IdEndpointPool_alloc_dealloc_test) {

  unsigned device_id = 0;
  {
    EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointAddress_EP1_IN;
    TestEndpoint*           endpoint = TestEndpoint_pool_allocate(device_id, ep_addr);
    EMC_CUNIT_ASSERT(0 != endpoint);

    TestEndpoint_pool_deallocate(endpoint);
  }
  {
    unsigned i;
    for (i = 0; i < MAX_ENDPOINT; ++i) {
      EMC_USB_EndpointId      ep_id = (EMC_USB_EndpointId)(i);
      EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);
      endpoints[i] = TestEndpoint_pool_allocate(device_id, ep_addr);
      EMC_CUNIT_ASSERT(0 != endpoints[i]);
    }
    /* no second allocation of the same ep_address */
    for (i = 0; i < MAX_ENDPOINT; ++i) {
      EMC_USB_EndpointId      ep_id = (EMC_USB_EndpointId)(i);
      EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);
      TestEndpoint*           endpoint = TestEndpoint_pool_allocate(device_id, ep_addr);
      EMC_CUNIT_ASSERT(0 == endpoint);
    }
    /* no more allocation than MAX_ENDPOINT */
    {
      TestEndpoint* endpoint = TestEndpoint_pool_allocate(device_id, MAX_ENDPOINT + 1);
      EMC_CUNIT_ASSERT(0 == endpoint);
    }
    for (i = 0; i < MAX_ENDPOINT; ++i) {
      TestEndpoint_pool_deallocate(endpoints[i]);
    }
    /* now the endpoints could be reallocated */
    for (i = 0; i < MAX_ENDPOINT; ++i) {
      EMC_USB_EndpointId      ep_id = (EMC_USB_EndpointId)(i);
      EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);
      endpoints[i] = TestEndpoint_pool_allocate(device_id, ep_addr);
      EMC_CUNIT_ASSERT(0 != endpoints[i]);
    }
    for (i = 0; i < MAX_ENDPOINT; ++i) {
      TestEndpoint_pool_deallocate(endpoints[i]);
    }
  }

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_IdEndpointPool_lookup_test)
{
  emc_std_uint8_t device_id = 0;

  unsigned i;
  for (i = 0; i < MAX_ENDPOINT; ++i) {
    EMC_USB_EndpointId      ep_id = (EMC_USB_EndpointId)(i);
    EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);
    endpoints[i] = TestEndpoint_pool_allocate(device_id, ep_addr);
    EMC_CUNIT_ASSERT(0 != endpoints[i]);
  }
  for (i = 0; i < MAX_ENDPOINT; ++i) {
    EMC_USB_EndpointId ep_id = (EMC_USB_EndpointId)(i);
    EMC_CUNIT_ASSERT(ep_id == endpoints[i]->alloc_type.index);

    EMC_CUNIT_ASSERT(endpoints[i] == TestEndpoint_pool_lookup_by_id(device_id, (emc_std_uint8_t)ep_id));
  }
  for (i = 0; i < MAX_ENDPOINT; ++i) {
    TestEndpoint_pool_deallocate(endpoints[i]);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_IdEndpointPool_iteration_test)
{
  emc_std_uint8_t device_id = 0;
  TestEndpoint*   iterator;

  unsigned i;
  for (i = 0; i < MAX_ENDPOINT; ++i) {
    EMC_USB_EndpointId      ep_id = (EMC_USB_EndpointId)(i);
    EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);
    endpoints[i] = TestEndpoint_pool_allocate(device_id, ep_addr);
    EMC_CUNIT_ASSERT(0 != endpoints[i]);
  }

  for (i = 0; i < MAX_ENDPOINT; ++i) {
    EMC_USB_EndpointId ep_id = (EMC_USB_EndpointId)(i);
    EMC_CUNIT_ASSERT(ep_id == endpoints[i]->alloc_type.index);

    EMC_CUNIT_ASSERT(endpoints[i] == TestEndpoint_pool_lookup_by_id(device_id, ep_id));
  }

  iterator = TestEndpoint_pool_first(device_id);
  while (iterator != TestEndpoint_pool_last(device_id)) {
    iterator = TestEndpoint_pool_next(iterator);
  }

  for (i = 0; i < MAX_ENDPOINT; ++i) {
    TestEndpoint_pool_deallocate(endpoints[i]);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(EMC_USB_IdEndpointPool_Test);

EMC_CUNIT_TEST(EMC_USB_IdEndpointPool_alloc_dealloc_test);
EMC_CUNIT_TEST(EMC_USB_IdEndpointPool_lookup_test);
EMC_CUNIT_TEST(EMC_USB_IdEndpointPool_iteration_test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(EMC_USB_IdEndpointPool_Test)

EMC_TEST_SUITE_DEFINE_MAIN()
