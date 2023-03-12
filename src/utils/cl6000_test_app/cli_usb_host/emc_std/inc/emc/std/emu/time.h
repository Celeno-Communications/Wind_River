/**
 * @file
 * @brief Emulation of the standard @c @<time.h@> header.
 *
 * @author  steffen <steffen.luzemann@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 */

#ifndef EMC_STD_EMU_time_H
#define EMC_STD_EMU_time_H

// clang-format off extern C
#  if defined(__cplusplus)
extern "C" {
#  endif
// clang-format on extern C

/** Integer or real floating type for time in seconds */
typedef unsigned int time_t;

/** A broken-down point in time */
struct tm {
  int tm_sec;   /**< Seconds after the minute, 0 to 60.
                     The value 60 allows for the occasional leap second. */
  int tm_min;   /**< Minutes after the hour, 0 to 59 */
  int tm_hour;  /**< Hours since midnight, 0 to 23 */
  int tm_mday;  /**< Day of the month, 1 to 31 */
  int tm_mon;   /**< Months since January, 0 to 11 */
  int tm_year;  /**< Years since 1900 */
  int tm_wday;  /**< Days since Sunday, 0 to 6 */
  int tm_yday;  /**< Days since January 1, 0 to 365 */
  int tm_isdst; /**< Daylight Savings flag, negative if unknown, positive in DST, zero otherwise */
};

/** Convert the time in seconds into a broken-down time format */
struct tm* gmtime(const time_t* numeric_time);

// clang-format off extern C
#  if defined(__cplusplus)
}
#  endif
// clang-format on extern C

#endif /* EMC_STD_EMU_time_H */
