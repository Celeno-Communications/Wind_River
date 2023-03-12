/**
 * @file
 * @brief   Generic Interrupt API
 *
 * @author  Karsten Pahnke <karsten.pahnke@emsys.de>
 *          emsys GmbH, D-98693 Ilmenau, Werner-von-Siemens-Str. 20
 *
 * Copyright (C) 2021 emsys Embedded Systems GmbH
 ****************************************************************************/
#ifndef EMC_SYSTEM_Interrupt_H
#define EMC_SYSTEM_Interrupt_H

#include "emc/system/configure.h"
#include "emc/std/stdbool.h"
#include "emc/std/stdint.h"

// clang-format off extern C
#ifdef __cplusplus
extern "C" {
#endif
// clang-format on extern C

/** The generic irq type
 * @ingroup emdoc_emc_system
 */
typedef void (* EMC_ISR)(emc_std_uint32_t id, void* context);

/** The interrupt context information */
typedef struct InterruptContext InterruptContext;

/**
 * @relates InterruptContext
 * @copydoc EMC_Interrupt_poll()
 * Prototype
 */
typedef emc_std_bool EMC_Interrupt_poll_f (InterruptContext* self, int timeout);

/**
 * @relates InterruptContext
 * @copydoc EMC_Interrupt_acknowledge()
 * Prototype
 */
typedef void EMC_Interrupt_acknowledge_f (InterruptContext* self);

/**
 * @relates InterruptContext
 * @copydoc EMC_Interrupt_enable()
 * Prototype
 */
typedef emc_std_bool EMC_Interrupt_enable_f (InterruptContext* self, emc_std_bool enable);

/**
 * @relates InterruptContext
 * @copydoc EMC_Interrupt_print_status()
 * Prototype
 */
typedef void EMC_Interrupt_print_status_f (InterruptContext* self);

/**
 * @relates InterruptContext
 * @copydoc EMC_Interrupt_register_isr()
 * Prototype
 */
typedef void EMC_Interrupt_register_isr_f (InterruptContext* self, EMC_ISR isr, void* context);

/**
 * @relates InterruptContext
 * Function pointer used by this object
 */
typedef struct InterruptContext_Functions {
  EMC_Interrupt_poll_f*         poll;         /**< call EMC_Interrupt_poll() */
  EMC_Interrupt_acknowledge_f*  acknowledge;  /**< call EMC_Interrupt_poll() */
  EMC_Interrupt_enable_f*       enable;       /**< call EMC_Interrupt_enable() */
  EMC_Interrupt_print_status_f* print_status; /**< call EMC_Interrupt_print_status() */
  EMC_Interrupt_register_isr_f* register_isr; /**< call EMC_Interrupt_register_isr() */
} InterruptContext_Functions;

/**
 * @ingroup emdoc_emc_system
 * The generic interrupt context
 */
struct InterruptContext {
  emc_std_uint32_t interrupt_type;             /**< the generic interrupt ID used by the application to call
                                                  EMC_System_interrupt_context */
  emc_std_uint32_t                  instance;  /**< The instance of that interrupt controller */
  int                               id;        /**< an private ID used to access the interrupt */
  const InterruptContext_Functions* functions; /**< The function table */
};

/**
 * @relates InterruptContext
 * initialize the InterruptContext
 * @param self caller provided storage for this instance
 * @param interrupt_type generic identifier
 * @param instance The zero based instance of this controller type
 * @param id private implementation, eg. number or fd
 * @param functions a initialized function pointer structure
 */
void EMC_InterruptContext_init(InterruptContext* self,
                               emc_std_uint32_t interrupt_type,
                               emc_std_uint32_t instance,
                               int id,
                               const InterruptContext_Functions* functions);

/**
 * @relates InterruptContext
 * poll interrupt with timeout
 * @param self the instance
 * @param timeout timeout in microseconds
 * @return true if an interrupt has been occurred
 */
static inline emc_std_bool EMC_Interrupt_poll(InterruptContext* self, int timeout)
{
  return self->functions->poll(self, timeout);
}

/**
 * @relates InterruptContext
 * acknowledge the interrupt
 *
 * The function should be called in the ISR or if EMC_Interrupt_poll returns
 * with true. The interrupt is disabed with this function call.
 * @param self the instance
 */
static inline void EMC_Interrupt_acknowledge(InterruptContext* self)
{
  self->functions->acknowledge(self);
}

/**
 * @relates InterruptContext
 * enable the interrupt
 * @param self the instance
 * @param enable true to enable the interrupt
 * @return true if the interrupt was enabled
 */
static inline emc_std_bool EMC_Interrupt_enable(InterruptContext* self, emc_std_bool enable)
{
  return self->functions->enable(self, enable);
}

/**
 * @relates InterruptContext
 * print interrupt status on stdout
 * @param self the instance
 */
static inline void EMC_Interrupt_print_status(InterruptContext* self)
{
  self->functions->print_status(self);
}

/**
 * @relates InterruptContext
 * register isr on context
 * @param self the instance
 * @param isr the ISR function
 * @param context the context passed to the ISR
 */
static inline void EMC_Interrupt_register_isr(InterruptContext* self, EMC_ISR isr, void* context)
{
  self->functions->register_isr(self, isr, context);
}

// clang-format off extern C
#  ifdef __cplusplus
}
#  endif
// clang-format on extern C

#endif
