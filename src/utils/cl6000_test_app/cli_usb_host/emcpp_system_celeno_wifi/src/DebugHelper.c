/**
 * @file
 *
 * @author  Ralf Oberländer
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include  "emc/system/celeno/configure.h"
#include "emc/std/stdint.h"
#include  "emc/system/celeno/DebugHelper.h"

#define EMC_STD_ASSERT_IMPL_MEM 1
#include "emc/std/signal.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"
#include "emc/std/stdint.h"

void exit_handler();
void emc_usb_poll_wd(void);

volatile char debug_buffer_1[128] = CELENO_APP_VERSION_AS_STRING;

#ifdef __XTENSA__
#  ifdef FREERTOS
#    include "external/freertos_kernel/XCC_Xtensa_api.h"
#  else
#    include <xtensa/xtruntime.h>
#  endif
#endif

#if !EMC_STD_ASSERT_NONE
extern struct emc_std_assert_reason mg_emc_std_assert_reason;
#  define UMAC_RUNNING 0x004E5552
#  define UMAC_CRASHED 0x00535243

struct {
  emc_std_uint32_t signature;
  emc_std_uint32_t pc;
  emc_std_uint32_t reserved[2];
  emc_std_uint32_t exccause;
  emc_std_uint32_t excvaddr;
  emc_std_uint32_t ps;
  emc_std_uint32_t epc1;
} mg_umac_crash_info;

static void abort_handler(int signal)
{
  (void)signal;
  mg_umac_crash_info.signature = UMAC_CRASHED;
  mg_umac_crash_info.pc = (emc_std_uint32_t)mg_emc_std_assert_reason.program_count;
  exit_handler();
}

#endif

#ifdef __XTENSA__
#  if EMCPP_SYSTEM_CELENO_WIFI_POST_MORTEM_EXCEPTION
volatile uint32_t* pm_register = (uint32_t*)0x60600588;

uint32_t emc_coredump_available()
{
  return (*pm_register) != 0;
}

/// linker script defined code segment addresses
extern uint8_t _memmap_seg_irom0_0_start;
extern uint8_t _memmap_seg_BLPOSTMORTEM_start;
extern uint8_t _memmap_seg_BLPOSTMORTEM_max;
extern uint8_t _memmap_seg_BLSHAREDRAM_start;

uint8_t* get_postmortem_buffer()
{
  return (uint8_t*)&_memmap_seg_BLPOSTMORTEM_start;
}

emc_std_size_t get_postmortem_buffer_size()
{
  return (&_memmap_seg_BLPOSTMORTEM_max) - (&_memmap_seg_BLPOSTMORTEM_start);
}

uint8_t* get_blsram_buffer()
{
  return (uint8_t*)&_memmap_seg_BLSHAREDRAM_start;
}

void exit_handler()
{
  void (* reset_vector)(void) = (void*)&_memmap_seg_irom0_0_start;

  uint8_t*       src = get_blsram_buffer();
  uint8_t*       dst = get_postmortem_buffer();
  emc_std_size_t cnt = get_postmortem_buffer_size();

  *pm_register = (uint32_t)get_postmortem_buffer();

  for (emc_std_size_t i = 0; i < cnt; i++) {
    dst[i] = src[i];
  }

  (*reset_vector)();
}

#  else
uint32_t emc_coredump_available()
{
  return 0;
}

void exit_handler()
{
  while (1) {
#    if !EMC_USB_VENDOR_CELENO_APP_IS_PCIE
//    emc_usb_poll_wd();
#    endif
  }
}

#  endif

#  ifdef FREERTOS

XtExcFrame mg_exc_frame;
void exception_handler(XtExcFrame* frame)
{
  mg_umac_crash_info.signature = UMAC_CRASHED;
  mg_umac_crash_info.exccause = frame->exccause;
  mg_umac_crash_info.excvaddr = frame->excvaddr;
  mg_umac_crash_info.ps = frame->ps;
  mg_umac_crash_info.epc1 = frame->pc;
  emc_std_memcpy(&mg_exc_frame, frame, sizeof(XtExcFrame));
  emc_std_assert(0);
  while (1) {} // stop even w/o asserts
}

#  else
static void exception_handler()
{
  unsigned long exccause, excvaddr, ps, epc1;
  __asm__ volatile ("rsr %0, exccause\n\t"
                    "rsr %1, excvaddr\n\t"
                    "rsr %2, ps\n\t"
                    "rsr %3, epc1"
                    : "=a" (exccause), "=a" (excvaddr),
                    "=a" (ps), "=a" (epc1));

  mg_umac_crash_info.signature = UMAC_CRASHED;
  mg_umac_crash_info.exccause = exccause;
  mg_umac_crash_info.excvaddr = excvaddr;
  mg_umac_crash_info.ps = ps;
  mg_umac_crash_info.epc1 = epc1;

  emc_std_assert(0);
  while (1) {} // stop even w/o asserts
}

#  endif
void emc_assertion_exception_handler_init(void)
{
  (void)debug_buffer_1[0]; // reference for post mortem analysis
  emc_std_memset((void*)(&mg_umac_crash_info), 0, sizeof(mg_umac_crash_info));
#  if !EMC_STD_ASSERT_NONE
  emc_std_signal(EMC_STD_SIGABRT, abort_handler);
#  endif

  for (uint32_t i = 0; i < XCHAL_EXCCAUSE_NUM; i++) {
    if ((i == EXCCAUSE_SYSCALL) || (i == EXCCAUSE_LEVEL1_INTERRUPT) || (i == EXCCAUSE_ALLOCA)) {
      continue;
    }
#  ifdef FREERTOS
    xt_set_exception_handler(i, exception_handler);
#  else
    xtos_set_exception_handler(i, exception_handler, 0);
#  endif
  }
  mg_umac_crash_info.signature = UMAC_RUNNING;
}

#else

uint32_t emc_coredump_available()
{
  return 0;
}

void emc_assertion_exception_handler_init(void)
{
  (void)debug_buffer_1[0]; // reference for post mortem analysis
#  if !EMC_STD_ASSERT_NONE
  emc_std_signal(EMC_STD_SIGABRT, abort_handler);
#  endif
}

#endif
