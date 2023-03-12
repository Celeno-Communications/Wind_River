/**
 * @file
 * @brief
 * Copyright (C) 2022 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_CELENO_DEVICE_APPLICATION_TestControlStatus_H
#define EMC_SYSTEM_CELENO_DEVICE_APPLICATION_TestControlStatus_H

#include "emc/std/stdint.h"

#pragma pack(push)
#pragma pack(4)

typedef enum CelenoPattern_e {
  CELENO_CONST_0      = 0, // fill packets with zeros
  CELENO_COUNT        = 1, // count 4-byte wise per packet with overflow
  CELENO_COUNT_GLOBAL = 2, // count 4-byte wise globally with overflow, resetted when test starts
  CELENO_PACKET_ID    = 3, // packet id is packet counter, 1st 4 bytes contain packet id
  CELENO_CRC32        = 4, // CRC32 Polynom: 0x04C11DB7, XOR value 0xFFFFFFFF
  CELENO_DONT_CARE    = 5  // Payload is undefined
} CelenoPattern;

typedef enum CelenoRequest_e {
  CELENO_IDLE  = 0,
  CELENO_START = 1 // start processing data
} CelenoRequest;

typedef enum CelenoDirection_e {
  CELENO_UP_STREAM   = 0,
  CELENO_DOWN_STREAM = 1,
  CELENO_LOOP        = 2
} CelenoDirection;

typedef enum CelenoTerminationCause_e {
  CELENO_LOOP_COUNT = 0,
  CELENO_TIME       = 1
} CelenoTerminationCause;

typedef struct CelenoTestCase_s {
  emc_std_uint32_t version;
  emc_std_uint32_t sequence_id;
  CelenoRequest    cmd;
  emc_std_uint32_t ep;
  emc_std_uint32_t lli;
  emc_std_uint32_t pdma;
  CelenoDirection  direction;
  struct packets {
    emc_std_uint32_t count;
    emc_std_uint32_t byte_count;
    CelenoPattern    pattern;
  } packets;

  struct termination {
    CelenoTerminationCause cause;
    emc_std_uint32_t       param1;
  } termination;

} CelenoTestCase;

typedef enum CelenoStatus_e {
  CELENO_TEST_IDLE     = 0,
  CELENO_TEST_STARTED  = 1,
  CELENO_TEST_FINISHED = 2
} CelenoStatus;

typedef enum CelenoResult_e {
  CELENO_TEST_SUCCESS       = 0,
  CELENO_TEST_ERROR         = 1,
  CELENO_TEST_PAYLOAD_ERROR = 2
} CelenoResult;

typedef struct CelenoTestStatus_s {
  emc_std_uint32_t version;
  emc_std_uint32_t sequence_id;
  emc_std_uint32_t timestamp_us;
  CelenoResult     result;
  CelenoStatus     status;
  emc_std_uint32_t exectime_us;
} CelenoTestStatus;

#pragma pack(pop)

#endif /* EMC_SYSTEM_CELENO_DEVICE_APPLICATION_TestControlStatus_H */
