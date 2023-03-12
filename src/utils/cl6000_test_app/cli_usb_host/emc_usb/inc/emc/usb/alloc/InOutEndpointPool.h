/**
 * @file
 * @brief   A Endpoint ressource pool splitted for IN and OUT
 *
 * @author  Stefan Schulze <stefan.schulze@emsys.de> +49-3677-68977-22
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2011-2013, 2020 emsys Embedded Systems GmbH
 */
#ifndef EMC_USB_ALLOC_InOutEndpointPool_H
#define EMC_USB_ALLOC_InOutEndpointPool_H

#include "emc/usb/alloc/Allocatable.h"
#include "emc/usb/EndpointAddress.h"

#include "emc/std/string.h"
#include "emc/std/assert.h"

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
extern "C" {
#endif
// clang-format on extern C

/**
 * @ingroup emdoc_emc_usb_alloc
 * Defines static <tt>TYPE* TYPE_pool_allocate()</tt> and
 * <tt>TYPE_pool_deallocate(TYPE*)</tt> functions, optimized for EP context
 * allocation. It uses the EP number as pool index. OUT EPs are allocated starting
 * at position 0, IN EPs are allocated started at position 16.
 *
 * @param TYPE Value type for the memory pool
 * @param MAX_DEVICE_INSTANCES Number of devices for the size of the pool
 * @param MAX_IN_ENDPOINT_INSTANCES Number of in endpoints for the size of the pool
 * @param MAX_OUT_ENDPOINT_INSTANCES Number of out endpoints for the size of the pool
 */
#define EMC_USB_DEFINE_EP_POOL(TYPE, MAX_DEVICE_INSTANCES,                                       \
                               MAX_IN_ENDPOINT_INSTANCES,                                        \
                               MAX_OUT_ENDPOINT_INSTANCES)                                       \
                                                                                                 \
  static TYPE EMC_NAME2(TYPE, _pool_IN)[MAX_DEVICE_INSTANCES][MAX_IN_ENDPOINT_INSTANCES];        \
  static TYPE EMC_NAME2(TYPE, _pool_OUT)[MAX_DEVICE_INSTANCES][MAX_OUT_ENDPOINT_INSTANCES];      \
                                                                                                 \
  static TYPE* EMC_NAME2(TYPE, _pool_allocate)(emc_std_uint8_t index, EMC_USB_EndpointAddress ep_address) \
  {                                                                                              \
    int   ep_num = EMC_USB_EndpointAddress_number(ep_address);                                   \
    int   ep_is_in = EMC_USB_EndpointAddress_is_in(ep_address);                                  \
    TYPE* instance = 0;                                                                          \
    if (ep_is_in && (ep_num < (int)MAX_IN_ENDPOINT_INSTANCES)) {                                 \
      instance = &EMC_NAME2(TYPE, _pool_IN)[index][ep_num];                                      \
    }                                                                                            \
    if (!ep_is_in && (ep_num < (int)MAX_OUT_ENDPOINT_INSTANCES)) {                               \
      instance = &EMC_NAME2(TYPE, _pool_OUT)[index][ep_num];                                     \
    }                                                                                            \
    if (instance && !((EMC_USB_Allocatable*)instance)->allocated) {                              \
      emc_std_memset(instance, 0, sizeof(TYPE));                                                 \
      ((EMC_USB_Allocatable*)instance)->allocated = 1;                                           \
      ((EMC_USB_Allocatable*)instance)->index = 0;                                               \
    } else {                                                                                     \
      instance = 0;                                                                              \
    }                                                                                            \
    return instance;                                                                             \
  }                                                                                              \
                                                                                                 \
  static void EMC_NAME2(TYPE, _pool_deallocate)(TYPE * self)                                     \
  { EMC_USB_Allocatable_deallocate((EMC_USB_Allocatable*)self); }                                \
                                                                                                 \
  static void EMC_NAME2(TYPE, _pool_initialize)(emc_std_uint8_t index)                           \
  {                                                                                              \
    emc_std_memset(&EMC_NAME2(TYPE, _pool_IN)[index][0], 0, MAX_IN_ENDPOINT_INSTANCES * sizeof(TYPE)); \
    emc_std_memset(&EMC_NAME2(TYPE, _pool_OUT)[index][0], 0, MAX_OUT_ENDPOINT_INSTANCES * sizeof(TYPE)); \
  }                                                                                              \
                                                                                                 \
  static TYPE* EMC_NAME2(TYPE, _pool_lookup_by_addr)(emc_std_uint8_t index, EMC_USB_EndpointAddress address) \
  {                                                                     \
    return (EMC_USB_EndpointAddress_is_out(address))                    \
           ? &EMC_NAME2(TYPE, _pool_OUT)[index][address & 0xf]               \
           : &EMC_NAME2(TYPE, _pool_IN)[index][address & 0xf];               \
  }                                                                     \
                                                                        \
  static TYPE* EMC_NAME2(TYPE, _pool_first)(emc_std_uint8_t index)      \
  {return &EMC_NAME2(TYPE, _pool_OUT)[index][0]; }                     \
                                                                        \
  static TYPE* EMC_NAME2(TYPE, _pool_next)(emc_std_uint8_t index, TYPE * driver) \
  {                                                                     \
    return (driver == &EMC_NAME2(TYPE, _pool_OUT)[index][MAX_OUT_ENDPOINT_INSTANCES - 1]) \
           ? &EMC_NAME2(TYPE, _pool_IN)[index][0] : (++driver);              \
  }                                                                     \
                                                                        \
  static TYPE* EMC_NAME2(TYPE, _pool_last)(emc_std_uint8_t index)       \
  {return &EMC_NAME2(TYPE, _pool_IN)[index][MAX_IN_ENDPOINT_INSTANCES - 1]; } \
                                                                        \
  /*lint -e(762,1065) */ extern int emc_macro_requires_semicolon

// clang-format off extern C
#ifdef __cplusplus /* @srcdist keep */
}
#endif
// clang-format on extern C

#endif /* EMC_USB_ALLOC_InOutEndpointPool_H */
