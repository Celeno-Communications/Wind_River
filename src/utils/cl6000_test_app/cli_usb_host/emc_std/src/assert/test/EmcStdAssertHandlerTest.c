#include "emc/std/emu/assert_handler.h"
#include "emc/std/emu/assert.h"

#include <emc/test/SimpleTest.h>
#include <emc/std/errno.h>
#include <emc/std/limits.h>
#include <emc/std/setjmp.h>
#include <emc/std/signal.h>
#include <emc/std/stdlib.h>

typedef int EmcStdAssertHandlerTest;

static int setUp(EmcStdAssertHandlerTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcStdAssertHandlerTest* context) { UNUSED_PARAM(context); return 1; }

static jmp_buf mock_abort__jmpbuf;

static int              mock_abort_handler_count = 0;
static const char*      mock_abort_handler_file_name = 0;
static unsigned int     mock_abort_handler_line = 0;
static const char*      mock_abort_handler_function_name = 0;
static const char*      mock_abort_handler_message = 0;
static emc_std_uint64_t mock_abort_handler_context = 0;

static void mock_abort_handler(const char* file_name,
                               unsigned int line,
                               const char* function_name,
                               const char* message
                               EMC_STD_ASSERT_CONTEXT_PARAM)
{
  ++mock_abort_handler_count;
  mock_abort_handler_file_name = file_name;
  mock_abort_handler_line = line;
  mock_abort_handler_function_name = function_name;
  mock_abort_handler_message = message;
#if EMC_STD_ASSERT_CONTEXT
  mock_abort_handler_context = context;
#endif

  longjmp(mock_abort__jmpbuf, 1);
}

static int test_assert_with_handler(EmcStdAssertHandlerTest* context)
{
  emc_std_assert_handler prev_handler;

  UNUSED_PARAM(context);

  mock_abort_handler_count = 0;
  mock_abort_handler_file_name = 0;
  mock_abort_handler_line = 0;
  mock_abort_handler_function_name = 0;
  mock_abort_handler_message = 0;
  mock_abort_handler_context = 0;

  prev_handler = emc_std_set_assert_handler(mock_abort_handler);

  if (!setjmp(mock_abort__jmpbuf)) {
    __emc_std_assert_fail(
#if EMC_STD_ASSERT_SRC_POS_FILE_LINE
      "file", 27
#elif EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
      (void*)0xFFFF
#endif
#if EMC_STD_ASSERT_FUNCTION
      , "function"
#endif
#if EMC_STD_ASSERT_MESSAGE
      , "message"
#endif
#if EMC_STD_ASSERT_CONTEXT
      , 1
#endif
      );

  }

  if (1 != mock_abort_handler_count) {
    return 0;
  }
#if EMC_STD_ASSERT_SRC_POS_FILE_LINE
  if (!mock_abort_handler_file_name) {
    return 0;
  }
  if (!mock_abort_handler_line) {
    return 0;
  }
#elif EMC_STD_ASSERT_SRC_POS_PROGRAM_COUNT
#endif
#if EMC_STD_ASSERT_FUNCTION
  if (!mock_abort_handler_function_name) {
    return 0;
  }
#endif
#if EMC_STD_ASSERT_MESSAGE
  if (!mock_abort_handler_message) {
    return 0;
  }
#endif
#if EMC_STD_ASSERT_CONTEXT
  if (!mock_abort_handler_context) {
    return 0;
  }
#endif

  prev_handler = emc_std_set_assert_handler(prev_handler);
  if (&mock_abort_handler != prev_handler) {
    return 0;
  }

  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcStdAssertHandlerTest, test_assert_with_handler);
  return fail_count;
}
