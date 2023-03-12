#include "emc/system/Interrupt.h"
#include "emc/std/string.h"

void EMC_InterruptContext_init(InterruptContext* self,
                               emc_std_uint32_t interrupt_type,
                               emc_std_uint32_t instance,
                               int id,
                               const InterruptContext_Functions* functions)
{
  emc_std_memset(self, 0, sizeof(InterruptContext));
  self->interrupt_type = interrupt_type;
  self->instance = instance;
  self->id = id;
  self->functions = functions;
}
