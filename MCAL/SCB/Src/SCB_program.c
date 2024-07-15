/***********************************************************************/
/* @file   SCB_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for the SCB driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "STM32F466xx.h"
#include "SCB_interface.h"

void SCB_voidSetPriorityGrouping(PriorityGrouping_t priorityGrouping)
{
    SCB->AIRCR = priorityGrouping;
}

void SCB_voidSetPriority(Exceptions_t exception, uint8_t priority)
{
    SCB->SHPR[exception] = priority << 4;
}

void SCB_voidEnableFault(Exceptions_t exception)
{

    switch (exception)
    {
    case USAGEFAULT:
        SCB->SHCSR |= (1 << 18);
        break;
    case BUSFAULT:
        SCB->SHCSR |= (1 << 17);
        break;
    case MEMMANAGE:
        SCB->SHCSR |= (1 << 16);
        break;
    default:
        break;
    }
}