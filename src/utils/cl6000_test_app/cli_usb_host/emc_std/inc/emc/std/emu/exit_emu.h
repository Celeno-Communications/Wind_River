/**
 * @file
 * @brief   An emulation of the exit() and abort() functionality.
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de> +49-3677-68977-0
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 ****************************************************************************/
#ifndef EMC_STD_EMU_exit_emu_H
#  define EMC_STD_EMU_exit_emu_H

#  include "emc/std/emu/assert_handler.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif

  /** typedef for backward compatibility */
  typedef emc_std_assert_handler emc_abort_handler;

  /** indirection for backward compatibility */
  static inline emc_abort_handler emc_set_abort_handler(emc_abort_handler handler)
  { return emc_std_set_assert_handler(handler); }

// clang-format off extern C
#  ifdef __cplusplus
}
#  endif
// clang-format on extern C

#endif /* EMC_STD_EMU_exit_emu_H */
