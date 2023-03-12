/** @file
    @brief The compiler specific configuration for pc-lint
    Copyright (C) 2011 emsys Embedded Systems GmbH */

#ifndef EMC_CONFIG_COMPILER_cfg_lint_H
#define EMC_CONFIG_COMPILER_cfg_lint_H

/** We redirect the @c __func__ identifier to @c __FUNCTION__ */
#define __func__ __FUNCTION__

#define __PRETTY_FUNCTION__ __func__

#endif /* EMC_CONFIG_COMPILER_cfg_lint_H */
