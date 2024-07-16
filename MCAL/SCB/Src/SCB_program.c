/***********************************************************************/
/* @file   SCB_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for the SCB driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "ErrType.h"
#include "STM32F466xx.h"
#include "SCB_interface.h"

uint8_t SCB_u8SetPriorityGrouping(PriorityGrouping_t priorityGrouping)
{
    uint8_t Local_u8ErrorState = OK;
    if (priorityGrouping == GROUP16_SUB0 || priorityGrouping == GROUP8_SUB2 || priorityGrouping == GROUP4_SUB4 || priorityGrouping == GROUP2_SUB8 || priorityGrouping == GROUP0_SUB16)
    {
        SCB->AIRCR = priorityGrouping;
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

uint8_t SCB_u8SetPriority(Exceptions_t exception, uint8_t priority)
{
    uint8_t Local_u8ErrorState = OK;
    if (priority <= 15 && (exception == USAGEFAULT || exception == BUSFAULT || exception == MEMMANAGE || exception == SVCALL || exception == PENDSV || exception == SYSTICK))
    {
        SCB->SHPR[exception] = priority << 4;
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

uint8_t SCB_u8EnableFault(Exceptions_t exception)
{

    uint8_t Local_u8ErrorState = OK;

    if (exception == USAGEFAULT || exception == BUSFAULT || exception == MEMMANAGE)
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
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}