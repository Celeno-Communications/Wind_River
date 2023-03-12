/// Copyright (C) 2021 emsys Embedded Systems GmbH
#include "emc/test/unittest.h"
#include "emc/usb/alloc/CompactEndpointPool.h"
#include "emc/usb/EndpointAddress.h"
#include "emc/usb/EndpointId.h"

typedef struct TestEndpoint {
  EMC_USB_Allocatable alloc_type;
  emc_std_uint8_t     address;
  emc_std_uint32_t    data[32];
} TestEndpoint;

#define MAX_DEVICE 2

#define MAX_ENDPOINT 4

EMC_USB_DEFINE_COMPACT_EP_POOL(TestEndpoint, MAX_DEVICE, MAX_ENDPOINT);

static TestEndpoint* endpoints[MAX_ENDPOINT];
EMC_USB_EndpointId   ep_ids[MAX_ENDPOINT];

static void dump_array(void)
{
  TestEndpoint* ep;
  unsigned      i;
  unsigned      index = 0;
  fprintf(stderr, "<mg_array_instance>\n");
  for (i = 0; i < MAX_ENDPOINT; ++i) {
    ep = &EMC_NAME2(TestEndpoint, _pool)[index][i];
    fprintf(stderr, "  [%d] alllocated=%d, index=%x, id=%x\n",
            i, ep->alloc_type.allocated, ep->alloc_type.index, ep->alloc_type.id);
  }
  fprintf(stderr, "</mg_array_instance>\n");
}

static void setUp(void)
{
  emc_std_memset(endpoints, 0, sizeof(endpoints));
  emc_std_memset(ep_ids, 0, sizeof(ep_ids));
  emc_std_memset(EMC_NAME2(TestEndpoint, _pool), 0, sizeof(EMC_NAME2(TestEndpoint, _pool)));
  ep_ids[0] = EMC_USB_EndpointId_EP8_IN;
  ep_ids[1] = EMC_USB_EndpointId_EP8_OUT;
  ep_ids[2] = EMC_USB_EndpointId_EP9_IN;
  ep_ids[3] = EMC_USB_EndpointId_EP9_OUT;
}

static void tearDown(void) {}

EMC_CUNIT_START_TEST(EMC_USB_CompactEndpointPool_alloc_dealloc_test) {

  unsigned device_id = 0;
  dump_array();
  {
    EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointAddress_EP1_IN;
    TestEndpoint*           endpoint = TestEndpoint_pool_allocate(device_id, ep_addr);
    dump_array();

    EMC_CUNIT_ASSERT(0 != endpoint);

    TestEndpoint_pool_deallocate(endpoint);
  }
  dump_array();

  {
    unsigned i;
    for (i = 0; i < MAX_ENDPOINT; ++i) {
      EMC_USB_EndpointId      ep_id = ep_ids[i];
      EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);
      endpoints[i] = TestEndpoint_pool_allocate(device_id, ep_addr);
      dump_array();
      EMC_CUNIT_ASSERT(0 != endpoints[i]);
    }
    /* no second allocation of the same ep_address */
    for (i = 0; i < MAX_ENDPOINT; ++i) {
      EMC_USB_EndpointId      ep_id = ep_ids[i];
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
      EMC_USB_EndpointId      ep_id = ep_ids[i];
      EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);
      endpoints[i] = TestEndpoint_pool_allocate(device_id, ep_addr);
      EMC_CUNIT_ASSERT(0 != endpoints[i]);
    }
    for (i = 0; i < MAX_ENDPOINT; ++i) {
      TestEndpoint_pool_deallocate(endpoints[i]);
    }
  }

}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_CompactEndpointPool_lookup_test)
{
  unsigned device_id = 0;
  unsigned i;
  {
    EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointAddress_EP1_IN;
    EMC_CUNIT_ASSERT(0 == lookup_by_id(device_id, EMC_USB_EndpointId_convert(ep_addr)));
  }
  for (i = 0; i < MAX_ENDPOINT; ++i) {
    EMC_USB_EndpointId      ep_id = ep_ids[i];
    EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);
    endpoints[i] = TestEndpoint_pool_allocate(device_id, ep_addr);
    EMC_CUNIT_ASSERT(0 != endpoints[i]);
  }
  for (i = 0; i < MAX_ENDPOINT; ++i) {
    EMC_USB_EndpointId      ep_id = ep_ids[i];
    EMC_USB_EndpointAddress ep_addr = EMC_USB_EndpointId_address(ep_id);

    EMC_CUNIT_ASSERT(endpoints[i] == lookup_by_id(device_id, EMC_USB_EndpointId_convert(ep_addr)));
    EMC_CUNIT_ASSERT(ep_id == endpoints[i]->alloc_type.id);
  }
  for (i = 0; i < MAX_ENDPOINT; ++i) {
    TestEndpoint_pool_deallocate(endpoints[i]);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(EMC_USB_CompactEndpointPool_Test);

EMC_CUNIT_TEST(EMC_USB_CompactEndpointPool_alloc_dealloc_test);
EMC_CUNIT_TEST(EMC_USB_CompactEndpointPool_lookup_test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(EMC_USB_CompactEndpointPool_Test)

EMC_TEST_SUITE_DEFINE_MAIN()
