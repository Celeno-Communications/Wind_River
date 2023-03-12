/**
 * @file
 * @author  Günter Hildebrandt <guenter.hildebrandt@emsys.de>
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include "emcpp/std/thread.hpp"
#include "emcpp/std/chrono.hpp"
#include "emcpp/std/iostream.hpp"
#include "emcpp/std/ext/thread/DeblockableExt.hpp"
#include "emcpp/test/UnitTest.hpp"
#include "emc/system/celeno/configure.h"
#include "emc/usb/driver/system/Timer.h"

namespace emcpp { namespace system { namespace celeno {

  // mock for the xthal_get_ccount function
  uint32_t                 ccount = 0;
  std::ext::DeblockableExt ccount_read;

  extern "C" {
  uint32_t xthal_get_ccount()
  {
    uint32_t cnt = ccount;
    ccount_read.deblock();
    return cnt;
  }

  }   // extern "C"

  // waits with a thread on the mocked clock
  class ClockMock {
  public:
    ClockMock()
      : _waiting(false)
      , _thread()
      , _thread_started()
      , _thread_ended()
    {}

    ~ClockMock()
    {
      while (_thread.joinable()) {
        increment_time(1000);
        _thread.join();
      }
    }

    void start_wait(uint32_t microSeconds)
    {
      EMCPP_TEST_ASSERT_FALSE(_waiting);
      _thread_started.reset();
      ccount_read.reset();
      _thread_ended.reset();
      _thread = std::thread(&ClockMock::runner, this, microSeconds);
      EMCPP_TEST_ASSERT_TRUE(std::cv_status::no_timeout == _thread_started.wait_for(std::chrono::milliseconds(500)));
      if (microSeconds > 0) {
        EMCPP_TEST_ASSERT_TRUE(std::cv_status::no_timeout == ccount_read.wait_for(std::chrono::milliseconds(500)));
      }
      // give the worker thread a chance to finally enter the wait
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    bool is_waiting()
    {
      return _waiting;
    }

    bool is_waiting_sync_ended()
    {
      _thread_ended.wait_for(std::chrono::milliseconds(500));
      return _waiting;
    }

    void set_tick(uint32_t ticks)
    {
      ccount = ticks;
    }

    void increment_time(uint32_t microSeconds)
    {
      ccount += microSeconds * UMAC_CYCLES_PER_MICRO_SECOND;
    }

    void runner(uint32_t microSeconds)
    {
      _waiting = true;
      _thread_started.deblock();
      EMC_USB_Driver_wait_us(microSeconds);
      _waiting = false;
      _thread_ended.deblock();
    }

  private:
    bool                     _waiting;
    std::thread              _thread;
    std::ext::DeblockableExt _thread_started;
    std::ext::DeblockableExt _thread_ended;
  };

  class UsbDeviceWaitTest : public test::TestFixture, public ClockMock {
  public:
    void wait_simple()
    {
      set_tick(0);
      start_wait(100);
      EMCPP_TEST_ASSERT_TRUE(is_waiting());
      increment_time(50);
      EMCPP_TEST_ASSERT_TRUE(is_waiting());
      increment_time(50);
      EMCPP_TEST_ASSERT_FALSE(is_waiting_sync_ended());
    }

    void wait_zero()
    {
      set_tick(0);
      start_wait(0);
      EMCPP_TEST_ASSERT_FALSE(is_waiting_sync_ended());
    }

    void wait_overrun()
    {
      set_tick(UINT32_MAX - 200);
      start_wait(100);
      EMCPP_TEST_ASSERT_TRUE(is_waiting());
      increment_time(100);
      EMCPP_TEST_ASSERT_FALSE(is_waiting_sync_ended());
    }

    void wait_long()
    {
      uint32_t long_time = UINT32_MAX / UMAC_CYCLES_PER_MICRO_SECOND;
      set_tick(0);
      start_wait(2 * long_time);
      EMCPP_TEST_ASSERT_TRUE(is_waiting());
      ccount_read.reset();
      for (int i = 0; i < 8; ++i) {
        if (!is_waiting()) {
          break;
        }
        EMCPP_TEST_ASSERT_TRUE(std::cv_status::no_timeout == ccount_read.wait_for(std::chrono::milliseconds(500)));
        increment_time(long_time / 2);
        ccount_read.reset();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
      }
      EMCPP_TEST_ASSERT_FALSE(is_waiting_sync_ended());
    }

    EMCPP_TEST_SUITE(UsbDeviceWaitTest);
    EMCPP_TEST_ADD(wait_simple);
    EMCPP_TEST_ADD(wait_zero);
    EMCPP_TEST_ADD(wait_overrun);
    EMCPP_TEST_ADD(wait_long);
    EMCPP_TEST_SUITE_END();

  };

  EMCPP_TEST_SUITE_INSTANTIATION(UsbDeviceWaitTest);

}}}
