/* Copyright (C) 2011, 2012 emsys Embedded Systems GmbH */

#include <emc/test/SimpleTest.h>
#include <emc/std/string.h>
#include <emc/std/stdint.h>

typedef int EmcStringTest;

static int setUp(EmcStringTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcStringTest* context) { UNUSED_PARAM(context); return 1; }

static int test_memcpy(EmcStringTest* context)
{

  const emc_std_uint8_t data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  UNUSED_PARAM(context);

  for (emc_std_size_t offset = 4; offset < 32; offset++) {
    emc_std_uint8_t buffer[100] = { 0 };
    if ((buffer + offset) != (emc_std_memcpy)(buffer + offset, data, sizeof(data))) {
      return 0;
    }
    for (emc_std_size_t i = 0; i < offset; i++) {
      if (0 != buffer[i]) {
        return 0;
      }
    }
    for (emc_std_size_t i = offset + sizeof(data); i < sizeof(buffer); i++) {
      if (0 != buffer[i]) {
        return 0;
      }
    }
    for (emc_std_size_t i = 0; i < sizeof(data); i++) {
      if (data[i] != buffer[offset + i]) {
        return 0;
      }
    }
  }
  return 1;
}

static int test_strncpy(EmcStringTest* context)
{
  const char data[] = { "abcd" };
  UNUSED_PARAM(context);
  {
    char buffer[] = "ABCDEFGH";
    if (buffer != (emc_std_strncpy)(buffer, data, 5)) {
      return 0;
    }
    if (0 != (emc_std_strcmp)(buffer, data)) {
      return 0;
    }
    if ('F' != buffer[5]) {
      return 0;
    }
  }
  {
    char buffer[] = "ABCDEFGH";
    if (buffer != (emc_std_strncpy)(buffer, data, 6)) {
      return 0;
    }
    if (0 != (emc_std_strcmp)(buffer, data)) {
      return 0;
    }
    if ('\0' != buffer[5]) {
      return 0;
    }
    if ('G' != buffer[6]) {
      return 0;
    }
  }
  {
    char buffer[] = "ABCDEFGH";
    if (buffer != (emc_std_strncpy)(buffer, data, 3)) {
      return 0;
    }
    if (0 != (emc_std_strncmp)(buffer, data, 3)) {
      return 0;
    }
    if ('D' != buffer[3]) {
      return 0;
    }
  }
  return 1;
}

static int test_memcmp(EmcStringTest* context)
{
  UNUSED_PARAM(context);
  if (0 != (emc_std_memcmp)("aaa", "aaa", 4)) {
    return 0;
  }
  if (0 <= (emc_std_memcmp)("aaa", "aab", 4)) {
    return 0;
  }
  if (0 >= (emc_std_memcmp)("aab", "aaa", 4)) {
    return 0;
  }
  if (0 <= (emc_std_memcmp)("aa\x7f", "aa\xff", 4)) {
    return 0;
  }
  return 1;
}

static int test_strcmp(EmcStringTest* context)
{
  UNUSED_PARAM(context);
  if (0 != (emc_std_strcmp)("aaa", "aaa")) {
    return 0;
  }
  if (0 <= (emc_std_strcmp)("aaa", "aaabbb")) {
    return 0;
  }
  if (0 <= (emc_std_strcmp)("aaa", "aab")) {
    return 0;
  }
  if (0 >= (emc_std_strcmp)("aab", "aaa")) {
    return 0;
  }
  if (0 <= (emc_std_strcmp)("aa\x7f", "aa\xff")) {
    return 0;
  }
  return 1;
}

static int test_strncmp(EmcStringTest* context)
{
  UNUSED_PARAM(context);
  if (0 != (emc_std_strncmp)("aaa", "aaa", 4)) {
    return 0;
  }
  if (0 != (emc_std_strncmp)("aaa", "aaabbb", 3)) {
    return 0;
  }
  if (0 <= (emc_std_strncmp)("aaa", "aaabbb", 4)) {
    return 0;
  }
  if (0 <= (emc_std_strncmp)("aaa", "aab", 4)) {
    return 0;
  }
  if (0 >= (emc_std_strncmp)("aab", "aaa", 4)) {
    return 0;
  }
  if (0 <= (emc_std_strncmp)("aa\x7f", "aa\xff", 4)) {
    return 0;
  }
  return 1;
}

static int test_memchr(EmcStringTest* context)
{
  const char abcabc[] = "abcabc";
  UNUSED_PARAM(context);
  if (0 != (emc_std_memchr)(abcabc, 'd', 7)) {
    return 0;
  }
  if (abcabc + 2 != (emc_std_memchr)(abcabc, 'c', 7)) {
    return 0;
  }
  if (0 != (emc_std_memchr)(abcabc, 'a', 0)) {
    return 0;
  }
  return 1;
}

static int test_strstr(EmcStringTest* context)
{
  const char ababcabcd[] = "ababcabcd";
  const char empty[] = "";
  UNUSED_PARAM(context);

  if (0 != (emc_std_strstr)(ababcabcd, "def")) {
    return 0;
  }
  if (ababcabcd != (emc_std_strstr)(ababcabcd, "")) {
    return 0;
  }
  if (ababcabcd != (emc_std_strstr)(ababcabcd, "a")) {
    return 0;
  }
  if (ababcabcd + 1 != (emc_std_strstr)(ababcabcd, "b")) {
    return 0;
  }
  if (ababcabcd != (emc_std_strstr)(ababcabcd, "ab")) {
    return 0;
  }
  if (ababcabcd + 3 != (emc_std_strstr)(ababcabcd, "bc")) {
    return 0;
  }
  if (ababcabcd + 2 != (emc_std_strstr)(ababcabcd, "abc")) {
    return 0;
  }
  if (ababcabcd + 5 != (emc_std_strstr)(ababcabcd, "abcd")) {
    return 0;
  }
  if (0 != (emc_std_strstr)(ababcabcd, "abcde")) {
    return 0;
  }
  if (ababcabcd != (emc_std_strstr)(ababcabcd, ababcabcd)) {
    return 0;
  }
  if (0 != (emc_std_strstr)(ababcabcd, "ababcabcdx")) {
    return 0;
  }

  if (empty != (emc_std_strstr)(empty, "")) {
    return 0;
  }

  return 1;
}

static int test_strchr(EmcStringTest* context)
{
  const char abcabc_[] = "abcabc\xff";
  UNUSED_PARAM(context);
  if (abcabc_ != (emc_std_strchr)(abcabc_, 'a')) {
    return 0;
  }
  if (abcabc_ + 1 != (emc_std_strchr)(abcabc_, 'b')) {
    return 0;
  }
  if (abcabc_ + 2 != (emc_std_strchr)(abcabc_, 'c')) {
    return 0;
  }
  if (abcabc_ + 6 != (emc_std_strchr)(abcabc_, '\xff')) {
    return 0;
  }
  if (abcabc_ + 7 != (emc_std_strchr)(abcabc_, '\0')) {
    return 0;
  }
  if (0 != (emc_std_strchr)(abcabc_, 'd')) {
    return 0;
  }
  return 1;
}

static int test_memset(EmcStringTest* context)
{
  unsigned char buffer[] = { 0, 0, 0, 0 };
  int           value = 128;
  UNUSED_PARAM(context);
  if (buffer + 1 != (emc_std_memset)(buffer + 1, value, 2)) {
    return 0;
  }
  if (0 != buffer[0]) {
    return 0;
  }
  if (value != buffer[1]) {
    return 0;
  }
  if (value != buffer[2]) {
    return 0;
  }
  if (0 != buffer[3]) {
    return 0;
  }
  return 1;
}

static int test_strerror(EmcStringTest* context)
{
  int i = 0;
  UNUSED_PARAM(context);
  for (i = 0; i < 300; ++i) {
    char* msg = (emc_std_strerror)(i);
    if (0 == msg) {
      return 0;
    }
    if (0 == (emc_std_memchr(msg, 0, 512))) {
      return 0;
    }
  }
  return 1;
}

static int test_strlen(EmcStringTest* context)
{
  UNUSED_PARAM(context);
  if (0 != (emc_std_strlen)("")) {
    return 0;
  }
  if (1 != (emc_std_strlen)("a")) {
    return 0;
  }
  if (4 != (emc_std_strlen)("abcd\0efgh")) {
    return 0;
  }
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcStringTest, test_memcpy);
  EMC_SIMPLE_TEST(EmcStringTest, test_strncpy);
  EMC_SIMPLE_TEST(EmcStringTest, test_memcmp);
  EMC_SIMPLE_TEST(EmcStringTest, test_strcmp);
  EMC_SIMPLE_TEST(EmcStringTest, test_strncmp);
  EMC_SIMPLE_TEST(EmcStringTest, test_memchr);
  EMC_SIMPLE_TEST(EmcStringTest, test_strstr);
  EMC_SIMPLE_TEST(EmcStringTest, test_strchr);
  EMC_SIMPLE_TEST(EmcStringTest, test_memset);
  EMC_SIMPLE_TEST(EmcStringTest, test_strerror);
  EMC_SIMPLE_TEST(EmcStringTest, test_strlen);
  return fail_count;
}
