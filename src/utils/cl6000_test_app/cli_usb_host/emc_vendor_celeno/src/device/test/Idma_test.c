/**
 * @file
 * @brief
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/

#include "emc/vendor/celeno/device/Idma.h"
#include "emc/log/log.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"
#include "emc/std/ext/timestamp.h"
#include "emc/std/ext/memcpy.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_LOG_LEVEL);

static emc_logger_t* logger()
{
#if EMC_LOG_LOGGING
  return EMC_Log_root_logger();
#else
  return 0;
#endif
}

static emc_std_uint8_t src_buf[256];
static emc_std_uint8_t dst_buf[sizeof(src_buf)];
#define  XTENSA_SRAM_BASE (0x60000000)

static emc_std_uint8_t* sram_src_buf = (emc_std_uint8_t*)(XTENSA_SRAM_BASE);
static emc_std_uint8_t* sram_dst_buf = (emc_std_uint8_t*)(XTENSA_SRAM_BASE + sizeof(src_buf));

void emc_test_idma(void)
{
  emc_std_uint8_t* src_ptr;
  emc_std_uint8_t* dst_ptr;
  emc_std_size_t   copy_size;
  emc_std_size_t   c, n;
  for (n = 0; n < sizeof(src_buf); ++n) {
    src_buf[n] = (emc_std_uint8_t)n;
  }

  src_ptr = src_buf;
  dst_ptr = dst_buf;

  for (c = 0; c < 6; ++c) {
    copy_size = sizeof(src_buf);
    emc_std_memset(dst_buf, 0, sizeof(dst_buf));
    EMC_LOG4(logger(), WARN, "CELENO_IDMA_memcpy(%u, %p, %p, %u", c, dst_ptr, src_ptr, copy_size);
    CELENO_IDMA_memcpy(c, (void*)dst_ptr, (const void*)src_ptr, copy_size);
    EMC_LOG(logger(), WARN, "done");
    emc_std_assert(0 == emc_std_memcmp(dst_ptr, src_ptr, copy_size));

    //dram->dram
    for (emc_std_size_t s = 8; s < sizeof(src_buf); s += 8) {
      timestamp_t t1, t2, t3, t4;
      emc_std_memset(dst_ptr, 0, s);
      t1 = emc_timestamp();
      CELENO_IDMA_memcpy(c, (void*)dst_ptr, (const void*)src_ptr, s);
      t2 = emc_timestamp();
      emc_std_assert(0 == emc_std_memcmp(dst_ptr, src_ptr, s));
      t3 = emc_timestamp();
      emc_std_ext_memcpy(dst_ptr, src_ptr, s);
      t4 = emc_timestamp();
      emc_std_assert(0 == emc_std_memcmp(dst_ptr, src_ptr, s));
      EMC_LOG4(logger(), WARN, "channel %u dram->dram size: %u idma: %u memcpy: %u", c, s, t2 - t1, t4 - t3);
    }

    //dram->sram
    for (emc_std_size_t s = 8; s < sizeof(src_buf); s += 8) {
      timestamp_t t1, t2, t3, t4;
      emc_std_memset(dst_ptr, 0, s);
      t1 = emc_timestamp();
      CELENO_IDMA_memcpy(c, (void*)dst_ptr, (const void*)sram_src_buf, s);
      t2 = emc_timestamp();
      emc_std_assert(0 == emc_std_memcmp(dst_ptr, sram_src_buf, s));
      t3 = emc_timestamp();
      emc_std_ext_memcpy(dst_ptr, sram_src_buf, s);
      t4 = emc_timestamp();
      EMC_LOG4(logger(), WARN, "channel %u sdram->dram size: %u idma: %u memcpy: %u", c, s, t2 - t1, t4 - t3);
    }
    //sram->sram
    for (emc_std_size_t s = 8; s < sizeof(src_buf); s += 8) {
      timestamp_t t1, t2, t3, t4;
      emc_std_memset(sram_dst_buf, 0, s);
      t1 = emc_timestamp();
      CELENO_IDMA_memcpy(c, (void*)sram_dst_buf, (const void*)sram_src_buf, s);
      t2 = emc_timestamp();
      emc_std_assert(0 == emc_std_memcmp(sram_dst_buf, sram_src_buf, s));
      t3 = emc_timestamp();
      emc_std_ext_memcpy(sram_dst_buf, sram_src_buf, s);
      t4 = emc_timestamp();
      emc_std_assert(0 == emc_std_memcmp(sram_dst_buf, sram_src_buf, s));
      EMC_LOG4(logger(), WARN, "channel %u sram->sram size: %u idma: %u memcpy: %u", c, s, t2 - t1, t4 - t3);
    }
  }
}
