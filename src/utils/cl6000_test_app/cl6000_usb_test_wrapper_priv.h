/**
 ****************************************************************************************
 *
 * @file cl6000_usb_test_priv.h
 *
 * @brief CL6000 UMAC USB wrapper test private test infrastructure.
 *
 * Copyright (C) Emsys/Celeno 2021
 *
 ****************************************************************************************
 */

#ifndef CL6000_USB_TEST_WRAPPER_PRIV_H_
#define CL6000_USB_TEST_WRAPPER_PRIV_H_

#include "cl6000_common.h"

#define WRAPPER_TEST_CONTROL_VERSION_OFFSET       ( 0x00 )
#define WRAPPER_TEST_CONTROL_SEQ_ID_OFFSET        ( 0x04 )
#define WRAPPER_TEST_CONTROL_REQUEST_OFFSET       ( 0x08 )
#define WRAPPER_TEST_CONTROL_EP_OFFSET            ( 0x0C )
#define WRAPPER_TEST_CONTROL_LLI_CHANNEL_OFFSET   ( 0x10 )
#define WRAPPER_TEST_CONTROL_DIRECTION_OFFSET     ( 0x14 )
#define WRAPPER_TEST_CONTROL_PACKET_CNT_OFFSET    ( 0x18 )
#define WRAPPER_TEST_CONTROL_PACKET_BYTES_OFFSET  ( 0x1C )
#define WRAPPER_TEST_CONTROL_PACKET_PATTER_OFFSET ( 0x20 )
#define WRAPPER_TEST_CONTROL_TERM_CAUSE_OFFSET    ( 0x24 )
#define WRAPPER_TEST_CONTROL_TERM_PARM_OFFSET     ( 0x28 )

#define WRAPPER_TEST_STATUS_VERSION_OFFSET        ( 0x00 )
#define WRAPPER_TEST_STATUS_SEQ_ID_OFFSET         ( 0x04 )
#define WRAPPER_TEST_STATUS_TIMESTAMP             ( 0x08 )
#define WRAPPER_TEST_STATUS_RESULT                ( 0x0C )
#define WRAPPER_TEST_STATUS_STATE_OFFSET          ( 0x10 )
#define WRAPPER_TEST_STATUS_EXEC_TIME             ( 0x14 )

/// data structures for wrapper test
enum USBW_Pattern  {
    USBW_CONST_0      = 0, // fill packet with zeros
    USBW_COUNT        = 1, // count 4-byte wise per packet with overflow
    USBW_COUNT_GLOBAL = 2, // count 4-byte wise globally with overflow, reseted when test starts
    USBW_PACKET_ID    = 3, // packet id is packet counter, 1st 4 bytes contain packet id
    USBW_CRC32        = 4, // CRC32 Polynom: 0xEDB88320, XOR value 0xFFFFFFFF
    USBW_DONT_CARE    = 5, // Payload is undefined
};
typedef uint32_t USBW_Pattern;

enum USBW_Request  {
    USBW_IDLE = 0,
    USBW_START = 1 // start processing data
};
typedef uint32_t USBW_Request;

enum USBW_Direction {
    USBW_UP_STREAM   = 0,
    USBW_DOWN_STREAM = 1,
    USBW_LOOP = 2,
};
typedef uint32_t USBW_Direction;

enum USBW_TerminationCause {
    USBW_LOOP_COUNT = 0,
    USBW_TIME       = 1
};
typedef uint32_t USBW_TerminationCause;

enum USBW_LLIRetryRule {
    USBW_STOP_ON_ERROR = 0,
    USBW_RETRY_ON_ERROR = 1
};
typedef uint32_t USBW_LLIRetryRule;

struct  USBW_TerminationCondition {
     USBW_TerminationCause  cause;

    /* cause == LOOP_COUNT: the number of ampdu_sequence's to process
       cause == TIME: the test runtime in ms */
     uint32_t param1;
};

struct USBW_PacketSequence {
    uint32_t     packet_count;
    uint32_t     number_bytes;
    USBW_Pattern pattern;
};

struct USBW_TestControlRequest {
    uint32_t                         version;
    uint32_t                         sequence_id;
    USBW_Request                     cmd;
    uint32_t                         ep;
    uint32_t                         lli_channel;
    uint32_t                         number_pdma;
    USBW_Direction                   direction;
    struct USBW_PacketSequence       packets;
    uint32_t                         stop_start_packet;
    USBW_LLIRetryRule                ignorre_lli_error;
    struct USBW_TerminationCondition finalize_cond;
};

enum USBW_LLI {
    USBW_U0 =0,
    USBW_U1 =1,
    USBW_U2 =2,
    USBW_U3 =3,
    USBW_U4 =4,
    USBW_U5 =5,
    USBW_U6 =6,
    USBW_U7 =7,
    USBW_U8 =8,
    USBW_U9 =9,
    USBW_U10 =10,
    USBW_U11 =11,
    USBW_U12 =12,
    USBW_U13 =13,
    USBW_U14 =14,
    USBW_U15 =15,
    USBW_D0 =0,
    USBW_D1 =1,
    USBW_D2 =2,
    USBW_D3 =3,
    USBW_D4 =4,
    USBW_D5 =5,
    USBW_D6 =6,
    USBW_D7 =7,
    USBW_D8 =8,
    USBW_D9 =9,
    USBW_D10 =10,
    USBW_D11 =11,
    USBW_D12 =12,
    USBW_D13 =13,
    USBW_D14 =14,
    USBW_D15 =15
};

enum USBW_Status  {
    USBW_STATUS_IDLE     = 0 ,
    USBW_STATUS_STARTED  = 1,
    USBW_STATUS_FINISHED = 2
};
typedef uint32_t USBW_Status;

enum USBW_Result  {
    USBW_OK               = 0 ,
    USBW_ERROR            = 1,
    USBW_PAYLOADMISSMATCH = 2
};
typedef uint32_t USBW_Result;

struct USBW_TestStatusResponse {
    uint32_t    version;
    uint32_t    sequence_id;
    uint32_t    timestamp;
    USBW_Result result;
    USBW_Status status;
    uint32_t    execution_time_us;
};


enum USBW_ParamType  {
    USBW_VOID        = 0,
    USBW_DS_AGGR_REG = 1
};

struct USBW_param {
    enum USBW_ParamType type;
    uint32_t param[4];
};

struct USBW_TestCase {
    const char*                    description;
    float                          tput_min_mbps_ss;   // 0.0 means will not be checked superspeed value
    float                          tput_min_mbps_hs;   // 0.0 means will not be checked hightspeed value
    float                          tput_eps;           // tput epsilon
    uint32_t                       schedule_all_ep;    // driver should also schedule other endpoints
    struct USBW_param              param;              // additional  parameter
    struct USBW_TestControlRequest control_request;

};

#endif // CL6000_USB_TEST_WRAPPER_PRIV_H_
