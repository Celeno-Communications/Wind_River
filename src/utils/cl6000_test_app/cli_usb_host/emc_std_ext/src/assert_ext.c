#include "emc/std/ext/assert_ext.h"

void __assert_return_failed(const char* file,
                            int line,
                            const char* function,
                            const char* message)
{
  UNUSED_PARAM(file);
  UNUSED_PARAM(line);
  UNUSED_PARAM(function);
  UNUSED_PARAM(message);
}
