/* Copyright (C) 2011-2013 emsys Embedded Systems GmbH */
#include "emc/usb/request/Request.h"

// clang-format off
#if EMC_PRINT
#include "emc/std/stdio.h"
#include "emc/data/form/helper_macros.h"
#include "emc/data/form/indent.h"
#include "emc/std/assert.h"

void EMC_USB_Request_print(const EMC_USB_Request* self, FILE* file)
{
    emc_std_assert(self);
    FORM_START_HEAD(file,EMC_USB_Request);
    FORM_ATTR_STR(file,dir,EMC_USB_Request_direction_name(self));
    FORM_ATTR_STR(file,type,EMC_USB_Request_type_name(self));
    FORM_ATTR_STR(file,recipient,EMC_USB_Request_recipient_name(self));
    indent(file);
    FORM_ATTR_HEX(file,request,self->bRequest);
    indent(file);
    FORM_ATTR_HEX(file,value,EMC_USB_Request_value(self));
    FORM_ATTR_HEX(file,index,EMC_USB_Request_index(self));
    FORM_ATTR_DEC(file,length,EMC_USB_Request_length(self));
    FORM_END_HEAD(file);
    FORM_END(file,EMC_USB_Request);
}

const char* EMC_USB_Request_recipient_name(const EMC_USB_Request* self)
{
    static const char* const name[] = {
        "Device",
        "Interface",
        "Endpoint",
        "Other"
    };

    emc_std_assert(self);
    return name[EMC_USB_Request_recipient(self)];
}

const char* EMC_USB_Request_type_name(const EMC_USB_Request* self)
{
    static const char* const name[] = {
        "Standard",
        "Class",
        "Reserved",
        "Vendor",
    };

    emc_std_assert(self);
    return name[EMC_USB_Request_type(self)>>5];
}

const char* EMC_USB_Request_direction_name(const EMC_USB_Request* self)
{
    emc_std_assert(self);
    return EMC_USB_Request_direction(self) == EMC_USB_REQ_DIR_HOST_TO_DEVICE ?
        "HOST_TO_DEVICE" : "DEVICE_TO_HOST";
}

#endif
// clang-format on
