/**
 * @file
 * @brief This file undefines problematic identifiers.
 *
 * This file contains a list of all unwanted defines and types which
 * came from the external-os headers like @<windows.h@>.  Include this
 * file after each include of @<windows.h@>.
 *
 * @bug This file undefines @c offsetof, a standard macro defined in
 * @<stddef.h@> and our emulation headers.
 *
 * @date 23.01.2008 11:13:05
 * @author Toralf Henze <toralf.henze@emsys.de> +49-3677-68977-21
 *         emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2004-2008 emsys Embedded Systems GmbH
 */

#ifndef EMC_CONFIG_COMPILER_cfg_external_undef_H
#define EMC_CONFIG_COMPILER_cfg_external_undef_H

#undef interface
#undef INTERFACE
#undef OUT
#undef IN
#undef size
#undef INFINITE
#undef ERROR

#ifdef _WINDOWS_
#  undef min
#  undef max
#  undef NO_ERROR
#  undef BAUD_300
#  undef BAUD_600
#  undef BAUD_1200
#  undef BAUD_2400
#  undef BAUD_4800
#  undef BAUD_9600
#  undef BAUD_19200
#  undef BAUD_38400
#  undef BAUD_57600
#  undef BAUD_115200
#  undef BAUD_230400
#  undef BAUD_460800
#  undef BAUD_921600

#  undef RESERVED
#  undef REG_SZ
#  undef REG_EXPAND_SZ
#  undef REG_BINARY
#  undef REG_DWORD_LITTLE_ENDIAN
#  undef REG_DWORD_BIG_ENDIAN
#  undef REG_LINK
#  undef REG_MULTI_SZ

#  undef ERROR_INVALID_PARAMETER
#  undef ERROR_INVALID_BUFFER_SIZE
#  undef ERROR_INVALID_ALIGNMENT
#  undef ERROR_BUSY
#  undef ERROR_IO_ERROR
#  undef ERROR_SYSTEM_ERROR
#  undef ERROR_NO_MEMORY
#  undef ERROR_NOT_SUPPORTED
#  undef ERROR_STATE
#  undef ERROR_INTERRUPTED
#  undef ERROR_ABORTED
#endif

#endif /* EMC_CONFIG_COMPILER_cfg_external_undef_H */
