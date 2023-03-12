/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */

#include <emc/std/ctype.h>

int(emc_std_tolower)(int c) {
  return ('A' <= c && c <= 'Z') ? (c + 'a' - 'A') : c;
}
int(emc_std_toupper)(int c) {
  return ('a' <= c && c <= 'z') ? (c + 'A' - 'a') : c;
}
int(emc_std_isspace)(int c) {
  return ' ' == c || ('\t' <= c && c <= '\r');
}
int(emc_std_isdigit)(int c) {
  return '0' <= c && c <= '9';
}
int(emc_std_isxdigit)(int c) {
  return ('0' <= c && c <= '9') || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f');
}
int(emc_std_isalpha)(int c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
int(emc_std_isprint)(int c) {
  return ' ' <= c && c <= '~';
}
