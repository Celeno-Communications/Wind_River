#include "emc/usb/alloc/Allocatable.h"
#include "emc/std/assert.h"
#include "emc/std/string.h"
#include "emc/log/log.h"

EMC_STATIC_LOG_LEVEL_DEFINE(EMC_USB_LOG_LEVEL);

EMC_USB_Allocatable* EMC_USB_Allocatable_allocate_first_free(EMC_USB_Allocatable* begin,
                                                             EMC_USB_Allocatable* end,
                                                             emc_std_size_t item_size)
{
  EMC_USB_Allocatable* find;
  unsigned             i = 0;
  for (find = begin; find != end; find = EMC_USB_Allocatable_next(find, item_size), ++i) {
    if (!find->allocated) {
      emc_std_memset(find, 0, item_size);
      find->allocated = 1;
      find->index = i;
      return find;
    }
  }
  EMC_LOG(EMC_Log_logger("emc.usb"), ERROR, "no allocatable space left"); //lint !e666
  return 0;
}

void EMC_USB_Allocatable_deallocate(EMC_USB_Allocatable* self)
{
  if (self) {
    if (!self->allocated) {
      EMC_LOG1(EMC_Log_logger("emc.usb"), INFO, "object %p is not allocated", self); //lint !e666
      // potentially we should ignore this
      emc_std_assert(self->allocated);
    }
    self->id = 0;
    self->index = 0;
    self->allocated = 0;
  }
}

EMC_USB_Allocatable* EMC_USB_Allocatable_find_first_id(EMC_USB_Allocatable* begin,
                                                       EMC_USB_Allocatable* end,
                                                       emc_std_size_t item_size,
                                                       emc_std_uint16_t id)
{
  EMC_USB_Allocatable* find;
  for (find = begin; find != end; find = EMC_USB_Allocatable_next(find, item_size)) {
    if (find->allocated && (find->id == id)) {
      return find;
    }
  }
  return 0;
}
