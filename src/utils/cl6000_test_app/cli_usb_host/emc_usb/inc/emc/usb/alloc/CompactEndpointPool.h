/**
 * @file
 * @brief   A Endpoint ressource pool in compact layout
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 */
#ifndef EMC_USB_ALLOC_CompactEndpointPool_H
#define EMC_USB_ALLOC_CompactEndpointPool_H

#include "emc/usb/alloc/Allocatable.h"
#include "emc/usb/EndpointAddress.h"
#include "emc/usb/EndpointId.h"

#include "emc/std/string.h"
#include "emc/std/assert.h"

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
extern "C" {
#endif
// clang-format on extern C

/**
 * @ingroup emdoc_emc_usb_alloc
 * Define static <tt>TYPE* TYPE_allocate()</tt> and
 * <tt>TYPE_deallocate(TYPE*)</tt> functions.
 * @param TYPE is the value-type for the memory pool.
 * @param MAX_DEVICE_INSTANCES The number of devices for the size of the pool.
 * @param MAX_ENDPOINT_INSTANCES The number of endpoints for the size of the pool.
 */
#define EMC_USB_DEFINE_COMPACT_EP_POOL(TYPE, MAX_DEVICE_INSTANCES, MAX_ENDPOINT_INSTANCES) \
                                                                        \
  static TYPE EMC_NAME2(TYPE, _pool)[MAX_DEVICE_INSTANCES][MAX_ENDPOINT_INSTANCES]; \
                                                                        \
  static inline EMC_USB_Allocatable* EMC_NAME2(TYPE, _pool_begin)(unsigned index) \
  {return (EMC_USB_Allocatable*)&EMC_NAME2(TYPE, _pool)[index][0]; }          \
                                                                        \
  static inline EMC_USB_Allocatable* EMC_NAME2(TYPE, _pool_end)(unsigned index) \
  {return (EMC_USB_Allocatable*)&EMC_NAME2(TYPE, _pool)[index][MAX_ENDPOINT_INSTANCES]; } \
                                                                        \
  static inline TYPE* lookup_by_id(unsigned index, EMC_USB_EndpointId ep_id) \
  {                                                                     \
    return (TYPE*)                                                      \
           EMC_USB_Allocatable_find_first_id(EMC_NAME2(TYPE, _pool_begin)(index), \
                                             EMC_NAME2(TYPE, _pool_end)(index), \
                                             sizeof(TYPE), (emc_std_uint16_t)ep_id); \
  }                                                                     \
                                                                        \
  static TYPE* EMC_NAME2(TYPE, _pool_allocate)(unsigned index, EMC_USB_EndpointAddress ep_address) \
  {                                                                     \
    EMC_USB_EndpointId ep_id = EMC_USB_EndpointId_convert(ep_address);  \
    TYPE*              instance = 0;                                    \
    unsigned           i;                                               \
                                                                        \
    if (lookup_by_id(index, ep_id) != 0) {                              \
      return 0;                                                         \
    }                                                                   \
    for (i = 0; i < MAX_ENDPOINT_INSTANCES; ++i) {                      \
      instance = &EMC_NAME2(TYPE, _pool)[index][i];                     \
      if (!((EMC_USB_Allocatable*)instance)->allocated) {               \
        emc_std_memset((void*)instance, 0, sizeof(TYPE));               \
        ((EMC_USB_Allocatable*)instance)->allocated = 1;                \
        ((EMC_USB_Allocatable*)instance)->index = i;                    \
        ((EMC_USB_Allocatable*)instance)->id = (emc_std_uint16_t)(ep_id); \
        return instance;                                                \
      }                                                                 \
    }                                                                   \
    return 0;                                                           \
  }                                                                     \
                                                                        \
  static void EMC_NAME2(TYPE, _pool_deallocate)(TYPE * self)            \
  { EMC_USB_Allocatable_deallocate((EMC_USB_Allocatable*)self); }       \
  /*lint -e(762,1065) */ extern int emc_macro_requires_semicolon

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
}
#endif
// clang-format on extern C

#endif /* EMC_USB_ALLOC_CompactEndpointPool_H */
