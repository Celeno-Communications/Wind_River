#include "emc/std/assert.h"
#include "emc/std/emu/assert_handler.h"

#include <emc/test/SimpleTest.h>
#include <emc/std/setjmp.h>

typedef int EmcStdAssertContextTest;

static int setUp(EmcStdAssertContextTest* context)
{
  UNUSED_PARAM(context);
  return 1;
}

static int tearDown(EmcStdAssertContextTest* context)
{
  UNUSED_PARAM(context);
  return 1;
}

static int test_emc_get_static_assert_context(EmcStdAssertContextTest* context)
{
  emc_std_uint64_t assert_context;
  UNUSED_PARAM(context);

#if EMC_STD_ASSERT_EMULATE
  assert_context = emc_get_static_assert_context();
#else
  assert_context = 0xFF;
#endif

  if (assert_context != 0) {
    return 0;
  }

  return 1;
}

#if 0
// to save the calling environment before abort
// and to return there within abort handler
static jmp_buf env_before_abort;

// to track context
static emc_std_uint64_t mg_abort_handler_context = 0;

// the custom abort handler used for this test
static void custom_emc_abort_handler(const char* file_name,
                                     unsigned int line,
                                     const char* function_name,
                                     const char* message,
                                     emc_std_uint64_t context)
{
  UNUSED_PARAM(file_name);
  UNUSED_PARAM(line);
  UNUSED_PARAM(function_name);
  UNUSED_PARAM(message);

  // track context
  mg_abort_handler_context = context;

  // return to environment before abort
  longjmp(env_before_abort, 1);
}

static int test_emc_std_assert(EmcStdAssertContextTest* context)
{
  UNUSED_PARAM(context);

  mg_abort_handler_context = 0x000000FFFF000000;

  emc_std_set_assert_handler(custom_emc_abort_handler);

  if (!setjmp(env_before_abort)) {
    emc_std_assert(0);
  }
  // expect global assert context to be zero
  if (mg_abort_handler_context != 0) {
    return 0;
  }

  return 1;
}

#endif

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcStdAssertContextTest, test_emc_get_static_assert_context);
  //EMC_SIMPLE_TEST(EmcStdAssertContextTest, test_emc_std_assert);
  return fail_count;
}
