/**
 * @file
 * @brief   A Endpoint ressource pool based on EndpointId
 *
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2011-2013, 2020-2021 emsys Embedded Systems GmbH
 */
#ifndef EMC_USB_ALLOC_IdEndpointPool_H
#define EMC_USB_ALLOC_IdEndpointPool_H

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
 * Define static <tt>TYPE* TYPE_pool_allocate()</tt> and <tt>TYPE_pool_deallocate(TYPE*)</tt> functions,
 *  optimized for EP context allocation for EndpointId concepts. It uses the EndpointId as pool-index.
 *  @param TYPE is the value-type for the memory pool.
 *  @param MAX_DEVICE_INSTANCES The number of devices for the size of the pool.
 *  @param MAX_ENDPOINT_INSTANCES The number of endpoints for the size of the pool.
 */
#define EMC_USB_DEFINE_ID_EP_POOL(TYPE, MAX_DEVICE_INSTANCES, MAX_ENDPOINT_INSTANCES)              \
                                                                                                   \
  static TYPE EMC_NAME2(TYPE, _pool)[MAX_DEVICE_INSTANCES][MAX_ENDPOINT_INSTANCES];                \
                                                                                                   \
  static inline void EMC_NAME2(TYPE, _pool_initialize)(emc_std_uint8_t index)                      \
  {                                                                                                \
    emc_std_memset(&EMC_NAME2(TYPE, _pool)[index][0], 0, MAX_ENDPOINT_INSTANCES * sizeof(TYPE));   \
  }                                                                                                \
                                                                                                   \
  static TYPE* EMC_NAME2(TYPE, _pool_allocate)(unsigned int index, EMC_USB_EndpointAddress ep_address) \
  {                                                                                                \
    int   ep_id = EMC_USB_EndpointId_convert(ep_address);                                          \
    TYPE* instance = 0;                                                                            \
                                                                                                   \
    if (ep_id < (int)MAX_ENDPOINT_INSTANCES) {                                                     \
      instance = &EMC_NAME2(TYPE, _pool)[index][ep_id];                                            \
      if (!((EMC_USB_Allocatable*)instance)->allocated) {                                          \
        emc_std_memset((void*)instance, 0, sizeof(TYPE));                                          \
        ((EMC_USB_Allocatable*)instance)->allocated = 1;                                           \
        ((EMC_USB_Allocatable*)instance)->index = (unsigned)(ep_id);                               \
        ((EMC_USB_Allocatable*)instance)->id = (emc_std_uint16_t)(ep_id);                          \
      } else {                                                                                     \
        instance = 0;                                                                              \
      }                                                                                            \
    }                                                                                              \
    return instance;                                                                               \
  }                                                                                                \
                                                                        \
  static inline void EMC_NAME2(TYPE, _pool_deallocate)(TYPE * self)     \
  { EMC_USB_Allocatable_deallocate((EMC_USB_Allocatable*)self); }       \
                                                                        \
  static TYPE* EMC_NAME2(TYPE, _pool_lookup_by_id)(emc_std_uint8_t index, EMC_USB_EndpointId ep_id) \
  {                                                                     \
    if (((emc_std_uint8_t)ep_id) < MAX_ENDPOINT_INSTANCES) {            \
      return &EMC_NAME2(TYPE, _pool)[index][ep_id];                     \
    } else {                                                            \
      return 0;                                                         \
    }                                                                   \
  }                                                                     \
                                                                        \
  static inline TYPE* EMC_NAME2(TYPE, _pool_first)(emc_std_uint8_t index) \
  {return &EMC_NAME2(TYPE, _pool)[index][0]; }                         \
                                                                        \
  static inline TYPE* EMC_NAME2(TYPE, _pool_next)(TYPE * self)          \
  { return ++self; }                                                    \
                                                                        \
  static inline TYPE* EMC_NAME2(TYPE, _pool_last)(emc_std_uint8_t index) \
  {return &EMC_NAME2(TYPE, _pool)[index][MAX_ENDPOINT_INSTANCES - 1]; } \
                                                                        \
  /*lint -e(762,1065) */ extern int emc_macro_requires_semicolon

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
}
#endif
// clang-format on extern C

#endif /* EMC_USB_ALLOC_IdEndpointPool_H */
