/**
 * @file
 * @brief   Define a GlobalPool of Allocatable objects
 *
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2011-2013, 2020-2021 emsys Embedded Systems GmbH
 */
#ifndef EMC_USB_ALLOC_GlobalPool_H
#define EMC_USB_ALLOC_GlobalPool_H

#include "emc/usb/alloc/Allocatable.h"

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
extern "C" {
#endif
// clang-format on extern C

/**
 * @ingroup emdoc_emc_usb_alloc
 * Define static <tt>TYPE* TYPE_pool_allocate()</tt> and
 * <tt>TYPE_pool_deallocate(TYPE*)</tt> functions
 * and public <tt>TYPE* TYPE_pool_lookup(uint16_t)</tt> function.
 *
 * @param TYPE is the value-type for the memory pool.
 * @param MAX_INSTANCES is the size of the pool.
 */
#define EMC_USB_DEFINE_POOL(TYPE, MAX_INSTANCES)                        \
                                                                        \
  static TYPE EMC_NAME2(TYPE, _pool)[MAX_INSTANCES];                    \
                                                                        \
  static inline EMC_USB_Allocatable* EMC_NAME2(TYPE, _pool_begin)()     \
  { return (EMC_USB_Allocatable*)&EMC_NAME2(TYPE, _pool)[0]; }          \
                                                                        \
  static inline EMC_USB_Allocatable* EMC_NAME2(TYPE, _pool_end)()       \
  { return (EMC_USB_Allocatable*)&EMC_NAME2(TYPE, _pool)[MAX_INSTANCES]; } \
                                                                        \
  static inline TYPE* EMC_NAME2(TYPE, _pool_allocate)(void)             \
  {return (TYPE*)                                                      \
           EMC_USB_Allocatable_allocate_first_free(EMC_NAME2(TYPE, _pool_begin)(), \
                                                   EMC_NAME2(TYPE, _pool_end)(), \
                                                   sizeof(TYPE)); }          \
                                                                        \
  static inline void EMC_NAME2(TYPE, _pool_deallocate)(TYPE * self)     \
  { EMC_USB_Allocatable_deallocate((EMC_USB_Allocatable*)self); }       \
                                                                        \
  EMC_USB_Allocatable* EMC_NAME2(TYPE, _pool_lookup)(emc_std_uint16_t id) \
  {                                                                     \
    return EMC_USB_Allocatable_find_first_id(EMC_NAME2(TYPE, _pool_begin)(), \
                                             EMC_NAME2(TYPE, _pool_end)(), \
                                             sizeof(TYPE), id); }          \
  /*lint -e(762,1065) */ extern int emc_macro_requires_semicolon

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
}
#endif
// clang-format on extern C

#endif /* EMC_USB_ALLOC_GlobalPool_H */
