#include <setjmp.h>

int main()
{
  jmp_buf env;
  setjmp(env);

  longjmp(env, 1);
  return 0;
}
