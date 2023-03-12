#include <emc/std/stdio.h>
#include <emc/std/stdarg.h>

#if !C_LIBRARY_HAS_FPRINTF

FILE* fopen(const char* n, const char* o)
{
  UNUSED_PARAM(n);
  UNUSED_PARAM(o);
  return 0;
}

void fclose(FILE* f)
{
  UNUSED_PARAM(f);
}

void fflush(FILE* f)
{
  UNUSED_PARAM(f);
}

int fprintf(FILE* f, const char* form, ...)
{
  va_list ap;

  UNUSED_PARAM(f);

  va_start(ap, form);
  return vprintf(form, ap);
  va_end(ap);
}

int fscanf(FILE* f, const char* form, ...)
{
  va_list ap;

  UNUSED_PARAM(f);

  va_start(ap, form);
  return scanf(form, ap);
  va_end(ap);
}

int vfprintf(FILE* f, const char* form, va_list param)
{
  UNUSED_PARAM(f);
  return vprintf(form, param);
}

#endif
