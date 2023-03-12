/**
 * @file
 *
 * @brief   The test of ctype API.
 *
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2012-2013 emsys Embedded Systems GmbH
 *
 ****************************************************************************/

#include "emc/test/SimpleTest.h"
#include "emc/std/ctype.h"

typedef int EmcCtypeTest;

static int setUp(EmcCtypeTest* context) { UNUSED_PARAM(context); return 1; }

static int tearDown(EmcCtypeTest* context) { UNUSED_PARAM(context); return 1; }

/**
 * \ingroup CTYPE_Implementation_Test
 * \test toupper()
 */
static int test_toupper(EmcCtypeTest* context)
{
  UNUSED_PARAM(context);

  if (!('A' == emc_std_toupper('A'))) {
    return 0;
  }
  if (!('A' == emc_std_toupper('a'))) {
    return 0;
  }
  if (!('Z' == emc_std_toupper('Z'))) {
    return 0;
  }
  if (!('Z' == emc_std_toupper('z'))) {
    return 0;
  }
  if (!('0' == emc_std_toupper('0'))) {
    return 0;
  }
  if (!('9' == emc_std_toupper('9'))) {
    return 0;
  }
  return 1;
}

static int test_tolower(EmcCtypeTest* context)
{
  UNUSED_PARAM(context);

  if (!('a' == emc_std_tolower('A'))) {
    return 0;
  }
  if (!('a' == emc_std_tolower('a'))) {
    return 0;
  }
  if (!('z' == emc_std_tolower('Z'))) {
    return 0;
  }
  if (!('z' == emc_std_tolower('z'))) {
    return 0;
  }
  if (!('0' == emc_std_tolower('0'))) {
    return 0;
  }
  if (!('9' == emc_std_tolower('9'))) {
    return 0;
  }
  return 1;
}

/**
 * \ingroup CTYPE_Implementation_Test
 * \test toupper()
 * \see http://www.cplusplus.com/reference/cctype/
 */
static int test_type(EmcCtypeTest* context)
{
  int c = 0;
  UNUSED_PARAM(context);

  for (c = 0x00; c < 0x7F; ++c) {
    if (c <= 0x08) { /* NUL, other control codes */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c == 0x09) { /* tab \t */
      if (!(0 != emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x0D) { /* white-space control codes: '\f','\v','\n','\r' */
      if (!(0 != emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x1F) { /* other control codes */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c == 0x20) { /* space (' ') */
      if (!(0 != emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x2F) { /* !"#$%&'()*+,-./ */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x39) { /* 0123456789 */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 != emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 != emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x40) { /* :;<=>?@ */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x46) { /* ABCDEF */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 != emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x5A) { /* GHIJKLMNOPQRSTUVWXYZ */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x60) { /* [\]^_` */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x66) { /* abcdef */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 != emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x7A) { /* ghijklmnopqrstuvwxyz */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c <= 0x7E) { /* {|}~ */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else if (c == 0x7F) { /* (DEL) */
      if (!(0 == emc_std_isspace(c))) {
        return 0;
      }
      if (!(0 == emc_std_isdigit(c))) {
        return 0;
      }
      if (!(0 == emc_std_isxdigit(c))) {
        return 0;
      }
    } else {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char* argv[])
{
  int fail_count = 0;
  UNUSED_PARAM(argc); UNUSED_PARAM(argv);
  EMC_SIMPLE_TEST(EmcCtypeTest, test_tolower);
  EMC_SIMPLE_TEST(EmcCtypeTest, test_toupper);
  EMC_SIMPLE_TEST(EmcCtypeTest, test_type);
  return fail_count;
}
