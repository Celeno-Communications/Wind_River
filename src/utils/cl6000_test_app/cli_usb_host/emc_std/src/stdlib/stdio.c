#include "emc/std/stdio.h"

int emc_std_puts(const char* s)
{
  UNUSED_PARAM(s);
  return 0;
}

int emc_std_fputs(const char* restrict_s, EMC_STD_FILE* restrict_stream)
{
  UNUSED_PARAM(restrict_s);
  UNUSED_PARAM(restrict_stream);
  return 0;
}

EMC_STD_FILE* emc_std_fopen(const char* restrict_filename, const char* restrict_mode)
{
  UNUSED_PARAM(restrict_filename);
  UNUSED_PARAM(restrict_mode);
  return 0;
}

emc_std_size_t emc_std_fread(void* restrict_ptr,
                             emc_std_size_t size,
                             emc_std_size_t nmemb,
                             EMC_STD_FILE* restrict_stream)
{
  UNUSED_PARAM(restrict_ptr);
  UNUSED_PARAM(size);
  UNUSED_PARAM(nmemb);
  UNUSED_PARAM(restrict_stream);
  return 0;
}

emc_std_size_t emc_std_fwrite(const void* restrict_ptr,
                              emc_std_size_t size,
                              emc_std_size_t nmemb,
                              EMC_STD_FILE* restrict_stream)
{
  UNUSED_PARAM(restrict_ptr);
  UNUSED_PARAM(size);
  UNUSED_PARAM(nmemb);
  UNUSED_PARAM(restrict_stream);
  return 0;
}

int emc_std_fseek(EMC_STD_FILE* stream, long int offset, int whence)
{
  UNUSED_PARAM(stream);
  UNUSED_PARAM(offset);
  UNUSED_PARAM(whence);
  return 0;
}

int emc_std_fclose(EMC_STD_FILE* stream)
{
  UNUSED_PARAM(stream);
  return 0;
}

int emc_std_ferror(EMC_STD_FILE* stream)
{
  UNUSED_PARAM(stream);
  return 0;
}

int emc_std_feof(EMC_STD_FILE* stream)
{
  UNUSED_PARAM(stream);
  return 0;
}

#if defined(_POSIX_SOURCE)

int emc_std_fileno(EMC_STD_FILE* stream)
{
  UNUSED_PARAM(stream);
  return 0;
}

#endif /* defined(_POSIX_SOURCE) */

int emc_std_setvbuf(EMC_STD_FILE* restrict_stream,
                    char* restrict_buf,
                    int mode,
                    size_t size)
{
  UNUSED_PARAM(restrict_stream);
  UNUSED_PARAM(restrict_buf);
  UNUSED_PARAM(mode);
  UNUSED_PARAM(size);
  return 0;
}

int emc_std_fprintf(EMC_STD_FILE* restrict_stream, const char* restrict_format, ...)
{
  UNUSED_PARAM(restrict_stream);
  UNUSED_PARAM(restrict_format);
  return 0;
}

int emc_std_vfprintf(EMC_STD_FILE* restrict_stream,
                     const char* restrict_format,
                     emc_std_va_list arg)
{
  UNUSED_PARAM(restrict_stream);
  UNUSED_PARAM(restrict_format);
  UNUSED_PARAM(arg);
  return 0;
}

int emc_std_snprintf(char* restrict_s, size_t n, const char* restrict_format, ...)
{
  UNUSED_PARAM(restrict_s);
  UNUSED_PARAM(n);
  UNUSED_PARAM(restrict_format);
  return 0;
}

int emc_std_vsnprintf(char* restrict_s,
                      size_t n,
                      const char* restrict_format,
                      emc_std_va_list arg)
{
  UNUSED_PARAM(restrict_s);
  UNUSED_PARAM(n);
  UNUSED_PARAM(restrict_format);
  UNUSED_PARAM(arg);
  return 0;
}
