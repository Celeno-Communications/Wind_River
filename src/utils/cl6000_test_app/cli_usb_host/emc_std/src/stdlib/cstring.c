/* Copyright (C) 2004-2006, 2012 emsys Embedded Systems GmbH */

#include <emc/std/string.h>

void* emc_std_memcpy(void* restrict_s1, const void* restrict_s2, emc_std_size_t n)
{
  unsigned char*       u1 = (unsigned char*)restrict_s1;
  const unsigned char* u2 = (const unsigned char*)restrict_s2;
  while (n) {
    *u1++ = *u2++;
    --n;
  }
  return restrict_s1;
}

char* emc_std_strncpy(char* restrict_s1, const char* restrict_s2, emc_std_size_t n)
{
  char* result = restrict_s1;
  for (; n && *restrict_s2; --n) {
    *restrict_s1++ = *restrict_s2++;
  }
  for (; n; --n) {
    *restrict_s1++ = '\0';
  }
  return result;
}

int emc_std_memcmp(const void* s1, const void* s2, emc_std_size_t n)
{
  const unsigned char* u1 = (const unsigned char*)s1;
  const unsigned char* u2 = (const unsigned char*)s2;
  for (; n && *u1 == *u2; --n) {
    ++u1;
    ++u2;
  }
  if (n) {
    return *u1 > *u2 ? 1 : -1;
  }
  return 0;
}

int emc_std_strcmp(const char* s1, const char* s2)
{
  const unsigned char* u1 = (const unsigned char*)s1;
  const unsigned char* u2 = (const unsigned char*)s2;
  while (*u1 && *u1 == *u2) {
    ++u1;
    ++u2;
  }
  if (*u1 || *u2) {
    return *u1 > *u2 ? 1 : -1;
  }
  return 0;
}

int emc_std_strncmp(const char* s1, const char* s2, emc_std_size_t n)
{
  return emc_std_memcmp(s1, s2, n);
}

void* emc_std_memchr(const void* s, int c, emc_std_size_t n)
{
  const unsigned char* pos = (const unsigned char*)s;
  unsigned char        ch = (unsigned char)c;
  for (; n && ch != *pos; --n) {
    ++pos;
  }
  return n ? (void*)pos : 0;
}

void* emc_std_memset(void* s, int c, emc_std_size_t n)
{
  unsigned char* dest = (unsigned char*)s;
  while (n) {
    *dest++ = (unsigned char)c;
    --n;
  }
  return s;
}

char* emc_std_strerror(int errnum)
{
  UNUSED_PARAM(errnum);
  return (char*)"?";
}

emc_std_size_t emc_std_strlen(const char* s)
{
  emc_std_size_t result = 0;
  while (*s++) {
    ++result;
  }
  return result;
}

emc_std_size_t emc_std_strnlen(const char* s, emc_std_size_t n)
{
  emc_std_size_t result = 0;
  while (n && *s++) {
    ++result;
    --n;
  }
  return result;
}

char* emc_std_strstr(const char* s1, const char* s2)
{
  emc_std_size_t n1 = emc_std_strlen(s1);
  emc_std_size_t n2 = emc_std_strlen(s2);
  if (0 == n1) {
    return n2 ? 0 : (char*)s1;
  }
  for (; n1 >= n2; --n1, ++s1) {
    if (0 == emc_std_strncmp(s1, s2, n2)) {
      return (char*)s1;
    }
  }
  return 0;
}

char* emc_std_strchr(const char* s, int c)
{
  while (*s && *s != c) {
    ++s;
  }
  return *s == c ? (char*)s : 0;
}
