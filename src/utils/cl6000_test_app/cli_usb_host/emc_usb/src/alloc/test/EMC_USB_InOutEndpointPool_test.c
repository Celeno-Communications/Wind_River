/// Copyright (C) 2011-2013, 2020-2021 emsys Embedded Systems GmbH
#include "emc/test/unittest.h"
#include "emc/usb/alloc/InOutEndpointPool.h"
#include "emc/usb/EndpointAddress.h"

#include "emc/std/string.h"
#include "emc/std/assert.h"
#include "emc/std/stdint.h"

#define NB_ARRAYS 2
#define NB_OUT_INSTANCES 5
#define NB_IN_INSTANCES 7

typedef struct SampleReferenceContext {
  /** Allocatable base type */
  EMC_USB_Allocatable alloc_type;
  /** ..some more dummy info */
  emc_std_uint8_t dummy;
} SampleReferenceContext;

EMC_USB_DEFINE_EP_POOL(SampleReferenceContext, NB_ARRAYS, NB_IN_INSTANCES, NB_OUT_INSTANCES);

static void setUp(void)
{
  for (size_t j = 0; j < NB_ARRAYS; j++) {
    SampleReferenceContext_pool_initialize((emc_std_uint8_t)(j));
  }
}

static void tearDown(void) {}

EMC_CUNIT_START_TEST(EMC_USB_InOutEndpointPool_alloc_dealloc_test) {
  emc_std_uint8_t nb_instances = NB_OUT_INSTANCES + NB_IN_INSTANCES;

  SampleReferenceContext* instances[NB_ARRAYS][NB_OUT_INSTANCES + NB_IN_INSTANCES];
  SampleReferenceContext* empty_instances[NB_ARRAYS];
  emc_std_memset(&instances[0][0], 0, sizeof(instances));
  emc_std_memset(&empty_instances[0], 0, sizeof(empty_instances));

  for (size_t j = 0; j < NB_ARRAYS; j++) {
    for (size_t i = 0; i < nb_instances; ++i) {
      emc_std_uint8_t ep =
        (emc_std_uint8_t)
        ((i >= NB_OUT_INSTANCES)
         ? EMC_USB_EndpointAddress_in(i - NB_OUT_INSTANCES)
         : EMC_USB_EndpointAddress_out(i));
      SampleReferenceContext* instance = SampleReferenceContext_pool_allocate((emc_std_uint8_t)(j), ep);
      EMC_CUNIT_ASSERT(instance != 0);
      instances[j][i] = instance;
    }
  }

  for (size_t j = 0; j < NB_ARRAYS; j++) {
    empty_instances[j] = SampleReferenceContext_pool_allocate((emc_std_uint8_t)(j), 0);
    EMC_CUNIT_ASSERT_EQUAL((SampleReferenceContext*)0, empty_instances[j]);
  }

  for (size_t j = 0; j < NB_ARRAYS; j++) {
    for (size_t i = 0; i < nb_instances; ++i) {
      SampleReferenceContext* instance = instances[j][i];
      SampleReferenceContext_pool_deallocate(instance);
      instances[j][i] = 0;
    }
  }
  for (size_t j = 0; j < NB_ARRAYS; j++) {
    SampleReferenceContext_pool_deallocate(empty_instances[j]);
  }
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_InOutEndpointPool_lookup_test)
{
  SampleReferenceContext* instance01 = SampleReferenceContext_pool_allocate(0, 0x04);
  SampleReferenceContext* instance02 = SampleReferenceContext_pool_allocate(0, 0x82);
  SampleReferenceContext* instance12 = SampleReferenceContext_pool_allocate(1, 0x82);

  EMC_CUNIT_ASSERT(instance01 != 0);
  EMC_CUNIT_ASSERT(instance02 != 0);
  EMC_CUNIT_ASSERT(instance12 != 0);

  EMC_CUNIT_ASSERT(instance02 != instance12);

  EMC_CUNIT_ASSERT_EQUAL(instance01, SampleReferenceContext_pool_lookup_by_addr(0, 0x4));
  EMC_CUNIT_ASSERT_EQUAL(instance02, SampleReferenceContext_pool_lookup_by_addr(0, 0x82));
  EMC_CUNIT_ASSERT_EQUAL(instance12, SampleReferenceContext_pool_lookup_by_addr(1, 0x82));

  SampleReferenceContext_pool_deallocate(instance01);
  SampleReferenceContext_pool_deallocate(instance02);
  SampleReferenceContext_pool_deallocate(instance12);
}

EMC_CUNIT_END_TEST EMC_CUNIT_START_TEST(EMC_USB_InOutEndpointPool_iteration_test)
{
  SampleReferenceContext* context_iter;
  emc_std_uint8_t         count = 0;

  emc_std_uint8_t nb_instances = NB_OUT_INSTANCES + NB_IN_INSTANCES;
  for (size_t i = 0; i < nb_instances; ++i) {
    emc_std_uint8_t ep =
      (emc_std_uint8_t)
      ((i >= NB_OUT_INSTANCES)
       ? EMC_USB_EndpointAddress_in(i - NB_OUT_INSTANCES)
       : EMC_USB_EndpointAddress_out(i));
    SampleReferenceContext* instance = SampleReferenceContext_pool_allocate(0, ep);
    EMC_CUNIT_ASSERT(instance != 0);
    ++count;
  }
  EMC_CUNIT_ASSERT_EQUAL(count, nb_instances);

  context_iter = SampleReferenceContext_pool_first(0);
  EMC_CUNIT_ASSERT(context_iter != 0);
  count = 1;
  do {
    context_iter = SampleReferenceContext_pool_next(0, context_iter);
    EMC_CUNIT_ASSERT(context_iter != 0);
    ++count;
  } while (context_iter != SampleReferenceContext_pool_last(0));

  EMC_CUNIT_ASSERT_EQUAL(count, nb_instances);
}

EMC_CUNIT_END_TEST EMC_CUNIT_TEST_SUITE(EMC_USB_InOutEndpointPool_Test);

EMC_CUNIT_TEST(EMC_USB_InOutEndpointPool_alloc_dealloc_test);
EMC_CUNIT_TEST(EMC_USB_InOutEndpointPool_lookup_test);
EMC_CUNIT_TEST(EMC_USB_InOutEndpointPool_iteration_test);

EMC_CUNIT_TEST_SUITE_END()

EMC_CUNIT_TEST_SUITE_REGISTRATION(EMC_USB_InOutEndpointPool_Test)

EMC_TEST_SUITE_DEFINE_MAIN()
