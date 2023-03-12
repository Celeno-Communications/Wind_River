/**
 * @file
 * @brief   The basic type of allocatable objects
 *
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2011-2013, 2020-2021 emsys Embedded Systems GmbH
 */
#ifndef EMC_USB_ALLOC_Allocatable_H
#define EMC_USB_ALLOC_Allocatable_H

#include "emc/usb/configure.h"
#include "emc/std/stdint.h"
#include "emc/std/stdlib.h"

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
extern "C" {
#endif
// clang-format on extern C

/**
 * @defgroup emdoc_emc_usb_alloc  Generic USB object allocation
 * @ingroup emdoc_emc_usb
 */

/** @struct EMC_USB_Allocatable
 * @ingroup emdoc_emc_usb_alloc
 * The basic data for generic allocatable structures
 */
typedef struct EMC_USB_Allocatable_s {
  unsigned int     allocated; /**< Indicates that this instance is allocated and in use */
  unsigned int     index;     /**< Index/instance count value */
  emc_std_uint16_t id;        /**< Unique ID for this instance */
} EMC_USB_Allocatable;

/** clear the fields
    @memberof EMC_USB_Allocatable
 */
static inline void EMC_USB_Allocatable_clear(EMC_USB_Allocatable* self)
{
  self->id = 0;
  self->index = 0;
  self->allocated = 0;
}

/** get the next element
    @memberof EMC_USB_Allocatable
 */
static inline EMC_USB_Allocatable* EMC_USB_Allocatable_next(EMC_USB_Allocatable* self,
                                                            emc_std_size_t item_size)
{
  return (EMC_USB_Allocatable*)(((emc_std_uint8_t*)(self)) + item_size);
}

/** find first element with false allocated flag and allocate it, otherwise return 0
    @memberof EMC_USB_Allocatable
 */
EMC_USB_Allocatable* EMC_USB_Allocatable_allocate_first_free(EMC_USB_Allocatable* begin,
                                                             EMC_USB_Allocatable* end,
                                                             emc_std_size_t item_size);

/** find first element with id
    @memberof EMC_USB_Allocatable
 */
EMC_USB_Allocatable* EMC_USB_Allocatable_find_first_id(EMC_USB_Allocatable* begin,
                                                       EMC_USB_Allocatable* end,
                                                       emc_std_size_t item_size,
                                                       emc_std_uint16_t id);

/** generic dellocate
    @memberof EMC_USB_Allocatable
 */
void EMC_USB_Allocatable_deallocate(EMC_USB_Allocatable* self);

/** Converts specific context to allocatable type
 * @ingroup emdoc_emc_usb_alloc
 */
#define EMC_USB_ALLOCATABLE(specific) ((EMC_USB_Allocatable*)(specific))

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
}
#endif
// clang-format on extern C

#endif /* EMC_USB_ALLOC_Allocatable_H */
