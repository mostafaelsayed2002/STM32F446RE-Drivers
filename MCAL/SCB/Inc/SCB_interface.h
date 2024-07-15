#include <stdint.h>
#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H

typedef enum
{
    GROUP16_SUB0 = 0x05FA0300,
    GROUP8_SUB2 = 0x05FA0400,
    GROUP4_SUB4 = 0x05FA0500,
    GROUP2_SUB8 = 0x05FA0600,
    GROUP0_SUB16 = 0x05FA0700,
} PriorityGrouping_t;

typedef enum
{
    USAGEFAULT = 0,
    BUSFAULT,
    MEMMANAGE,
    SVCALL = 7,
    PENDSV = 10,
    SYSTICK
} Exceptions_t;

void SCB_voidSetPriorityGrouping(PriorityGrouping_t priorityGrouping);

void SCB_voidSetPriority(Exceptions_t exception, uint8_t priority);

void SCB_voidEnableFault(Exceptions_t exception);

#endif