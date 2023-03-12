/**
 * @file
 * @brief   Malloc emulation based on AMS/Sandisk memory allocation functions.
 * @author  Paul Kunysch <paul.kunysch@emsys.de>
 * Copyright (C) 2007-2013 emsys Embedded Systems GmbH
 */

#include <emc/std/emu/ams/malloc.h>
#include <emc/std/assert.h>
#include <include/santypes.h>
#include <ams_heap.h>

#if EMC_MALLOC_COUNT
#  include <stdio.h>
size_t emc_heap_current, emc_heap_max, emc_heap_total;
size_t emc_heap_frees[25];
size_t emc_heap_mallocs[25];
void*  emc_heap_begin, * emc_heap_end;
static int counter_index(size_t size)
{
  return (0 == size || size >= (sizeof(emc_heap_frees) / sizeof(emc_heap_frees[0]))) ? 0 : size;
}

void emc_heap_print(const char* who)
{
  int i;
  fprintf(stderr, "***\n*** emc_heap_print(\"%s\"): current=%d max=%d total=%d\n",
          who ? who : "", emc_heap_current, emc_heap_max, emc_heap_total);
  fprintf(stderr, "***");
  for (i = 0; i < sizeof(emc_heap_frees) / sizeof(emc_heap_frees[0]); ++i) {
    fprintf(stderr, " %d", emc_heap_mallocs[i] - emc_heap_frees[i]);
  }
  fprintf(stderr, "\n***");
  for (i = 0; i < sizeof(emc_heap_frees) / sizeof(emc_heap_frees[0]); ++i) {
    fprintf(stderr, " %d-%d", emc_heap_mallocs[i], emc_heap_frees[i]);
  }
  fprintf(stderr, "\n***\n");
}

#else
#  define emc_heap_print(who) do {; } while (0)
#endif /* EMC_MALLOC_COUNT */

static void* mg_heap = NULL;

#ifndef EMC_HEAP_TRACE
#  define EMC_HEAP_TRACE 0
#endif

#if EMC_HEAP_TRACE
#  include "emc/std/stdio.h"
#  include <emc/std/memory.h>
unsigned int emc_heap_total_size = 0;
unsigned int emc_heap_used_size = 0;
unsigned int emc_heap_max_size = 0;
unsigned int emc_heap_min_addr = 0;
unsigned int emc_heap_max_addr = 0;
unsigned int emc_heap_trace_count = 0;
unsigned int emc_heap_item_size = 0;
unsigned int emc_heap_black_new = 0;
unsigned int emc_heap_black_del = 0;

#  pragma arm section zidata = "EMC_HEAP_TRACE"

enum {
  HEAP_TRACE_DEPTH = 0x1000
};

struct HeapTraceInfo {
  void* addr;
  int   size;
} emc_heap_trace[HEAP_TRACE_DEPTH];

/* HeapTraceInfo emc_heap_trace[HEAP_TRACE_DEPTH]; */

static void TRACE_NEW(void* a, size_t s)
{
  UNUSED_PARAM(s);
  emc_heap_item_size = *(((unsigned int*)(a)) - 1);
  if (emc_heap_trace_count < HEAP_TRACE_DEPTH) {
    emc_heap_trace[emc_heap_trace_count].addr = a;
    emc_heap_trace[emc_heap_trace_count].size = emc_heap_item_size;
    emc_heap_trace_count++;
  }
  emc_heap_used_size += emc_heap_item_size;
  if (emc_heap_used_size > emc_heap_max_size) {
    emc_heap_max_size = emc_heap_used_size;
  }
  if (((unsigned int)a + emc_heap_item_size) > emc_heap_max_addr) {
    emc_heap_max_addr = ((unsigned int)a + emc_heap_item_size);
  }
}

static void TRACE_DEL(void* a)
{
  if (a) {
    emc_heap_item_size = *(((unsigned int*)(a)) - 1);
    if (emc_heap_trace_count < HEAP_TRACE_DEPTH) {
      emc_heap_trace[emc_heap_trace_count].addr = a;
      emc_heap_trace[emc_heap_trace_count].size = -emc_heap_item_size;
      emc_heap_trace_count++;
    }
    emc_heap_used_size -= emc_heap_item_size;
  }
}

void emc_heap_trace_start()
{}

void emc_heap_trace_init(void* begin, size_t size)
{
  emc_heap_total_size = size;
  emc_heap_used_size = 0;
  emc_heap_max_size = 0;
  emc_heap_min_addr = (unsigned int)begin;
  emc_heap_max_addr = emc_heap_min_addr;

  emc_heap_trace_count = 0;
  emc_heap_black_new = 0;
  emc_heap_black_del = 0;
  memset(emc_heap_trace, 0, sizeof(emc_heap_trace));
  /*
     We can't print yet!
     fprintf(stderr,"emc_heap_trace_start addr=0x%lx\n", (emc_std_uint32_t)&emc_heap_trace[0]);
   */

  emc_heap_trace_start();
  /*
     We can't print yet!
     emc_heap_trace_status();
   */
}

void emc_heap_trace_status(void)
{
  fprintf(stderr,
          "emc_heap_trace_status\n"
          "address(min)= 0x%x\n"
          "address(max)= 0x%x\n"
          "total_size  = 0x%x\n"
          "used_size   = 0x%x\n"
          "max_size    = 0x%x\n"
          "trace_count = 0x%x\n",
          emc_heap_min_addr,
          emc_heap_max_addr,
          emc_heap_total_size,
          emc_heap_used_size,
          emc_heap_max_size,
          emc_heap_trace_count);
}

void emc_heap_trace_stop(void)
{}

#else
#  define TRACE_NEW(a, s)
#  define TRACE_DEL(a)
void emc_heap_trace_init(void* begin, size_t size)
{}

void emc_heap_trace_start(void)
{}

void emc_heap_trace_status(void)
{}

void emc_heap_trace_stop(void)
{}

#endif

size_t emc_heap_total = 0;
size_t emc_heap_current = 0;

void* emc_std_malloc(size_t size)
{
#if EMC_MALLOC_COUNT
  size_t* ptr = amsMalloc(mg_heap, size /* ? size + sizeof(size) : size */);
#else /* !EMC_MALLOC_COUNT */
  void* ptr = amsMalloc(mg_heap, size);
#endif /* !EMC_MALLOC_COUNT */
  if (!size) {
    if (!ptr) {
      ptr = (void*)-1;
    }
  } else if (ptr) {
#if EMC_MALLOC_COUNT
    emc_std_assert(size + 4 <= *(((unsigned int*)(ptr)) - 1));
    if (size + 4 < *(((unsigned int*)(ptr)) - 1)) {
      size = *(((unsigned int*)(ptr)) - 1) - 4;
    }
    // if (1 == size) { fprintf(stderr, "emc_sandisk_malloc(1): %p\n", ptr); }
    // *ptr = size;
    // ptr += 1;
    emc_heap_total += size;
    emc_heap_current += size;
    ++emc_heap_mallocs[counter_index(size)];
    if (emc_heap_max < emc_heap_current) {
      emc_heap_max = emc_heap_current;
    }
#endif /* EMC_MALLOC_COUNT */
  }
  emc_std_assert(ptr);
  TRACE_NEW(ptr, size);
  return ptr;
}

void emc_std_free(void* pointer)
{
  TRACE_DEL(pointer);
  if ((void*)-1 != pointer) {
#if EMC_MALLOC_COUNT
    if (pointer) {
      size_t* ptr = pointer;
      int     index;
      emc_std_assert(emc_heap_begin <= pointer && pointer <= emc_heap_end);
      // ptr -= 1;
      //emc_heap_current -= *ptr;
      *ptr = *(((unsigned int*)(ptr)) - 1) - 4;
      emc_heap_current -= *ptr;
      index = sizeof(emc_heap_frees) / sizeof(emc_heap_frees[0]) - 1;
      ++emc_heap_frees[counter_index(*ptr)];
      // if (1 == *ptr) { fprintf(stderr, "emc_sandisk_free(1): %p\n", ptr); }
    }
#endif /* EMC_MALLOC_COUNT */
    amsFree(mg_heap, pointer);
  }
}

void emcpp_dmamm_reset(void);

void emc_heap_init(void* memory, size_t size, int clear_heap)
{
#if EMC_MALLOC_COUNT
  int i;
  if (0 != emc_heap_max) {
    emc_heap_print("emc_heap_init");
  }
  emc_heap_current = emc_heap_total = emc_heap_max = 0;
  emc_heap_begin = memory; emc_heap_end = ((char*)memory) + size;
  for (i = sizeof(emc_heap_frees) / sizeof(emc_heap_frees[0]) - 1; i >= 0; --i) {
    emc_heap_frees[i] = emc_heap_mallocs[i] = 0;
  }
#endif /* EMC_MALLOC_COUNT */
  emc_heap_trace_init(memory, size);
  emcpp_dmamm_reset();
  mg_heap = amsHeapInitialise(memory, size, clear_heap);
}
