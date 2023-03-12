/* Copyright (C) 2021 emsys Embedded Systems GmbH */

#include "emc/system/Interrupt.h"
#include "emc/test/test_assert.h"
#include "emc/std/stddef.h"

static emc_std_uint32_t mg_poll_count;
static emc_std_uint32_t mg_acknowledge_count;
static emc_std_uint32_t mg_enable_count;
static emc_std_uint32_t mg_print_status_count;
static emc_std_uint32_t mg_register_isr_count;

static emc_std_bool EMC_Interrupt_poll_impl(InterruptContext* self, int timeout)
{
  UNUSED_PARAM(self);
  UNUSED_PARAM(timeout);
  mg_poll_count++;
  return emc_std_true;
}

static void EMC_Interrupt_acknowledge_impl(InterruptContext* self)
{
  UNUSED_PARAM(self);
  mg_acknowledge_count++;
}

static emc_std_bool EMC_Interrupt_enable_impl(InterruptContext* self, emc_std_bool enable)
{
  UNUSED_PARAM(self);
  UNUSED_PARAM(enable);
  mg_enable_count++;
  return emc_std_false;
}

static void EMC_Interrupt_print_status_impl(InterruptContext* self)
{
  UNUSED_PARAM(self);
  mg_print_status_count++;
}

static void EMC_Interrupt_register_isr_impl(InterruptContext* self, EMC_ISR isr, void* context)
{
  UNUSED_PARAM(self);
  UNUSED_PARAM(isr);
  UNUSED_PARAM(context);
  mg_register_isr_count++;
}

static void isr(emc_std_uint32_t id, void* context)
{
  UNUSED_PARAM(id);
  UNUSED_PARAM(context);
}

static InterruptContext_Functions mg_functions = {
  EMC_Interrupt_poll_impl,
  EMC_Interrupt_acknowledge_impl,
  EMC_Interrupt_enable_impl,
  EMC_Interrupt_print_status_impl,
  EMC_Interrupt_register_isr_impl
};

void test_basic()
{
  InterruptContext ic;
  EMC_InterruptContext_init(&ic, 1, 0, 0, &mg_functions);

  mg_poll_count = 0;
  mg_acknowledge_count = 0;
  mg_enable_count = 0;
  mg_print_status_count = 0;
  mg_register_isr_count = 0;

  EMC_Interrupt_poll(&ic, 0);
  EMC_Interrupt_acknowledge(&ic);
  EMC_Interrupt_enable(&ic, emc_std_true);
  EMC_Interrupt_print_status(&ic);
  EMC_Interrupt_register_isr(&ic, &isr, EMC_STD_NULL);

  EMC_TEST_ASSERT(1 == mg_poll_count);
  EMC_TEST_ASSERT(1 == mg_acknowledge_count);
  EMC_TEST_ASSERT(1 == mg_enable_count);
  EMC_TEST_ASSERT(1 == mg_print_status_count);
  EMC_TEST_ASSERT(1 == mg_register_isr_count);
}

int main(int argc, char* argv[])
{
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  test_basic();
  return 0;
}
