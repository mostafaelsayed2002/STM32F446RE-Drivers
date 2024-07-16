/***********************************************************************/
/* @file   EXTI_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for the EXTI driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "ErrType.h"
#include "STM32F466xx.h"
#include "EXTI_interface.h"

static void (*EXTI_Callback[16])(void);

uint8_t EXTI_u8Init(EXTI_Config_t *copy_Config)
{
    uint8_t Local_u8ErrorState = OK;
    if (copy_Config != NULL)
    {
        if (copy_Config->EXTI_Line <= EXTI15)
        {
            switch (copy_Config->EnableState)
            {
            case UNMASKED:
                EXTI->IMR |= (1 << copy_Config->EXTI_Line);
                break;
            case MASKED:
                EXTI->IMR &= ~(1 << copy_Config->EXTI_Line);
                break;
            default:
                Local_u8ErrorState = NOK;
                break;
            }
            switch (copy_Config->TriggerEvent)
            {
            case RISING:
                EXTI->RTSR |= (1 << copy_Config->EXTI_Line);
                EXTI->FTSR &= ~(1 << copy_Config->EXTI_Line);
                break;
            case FALLING:
                EXTI->FTSR |= (1 << copy_Config->EXTI_Line);
                EXTI->RTSR &= ~(1 << copy_Config->EXTI_Line);
                break;
            case FALLING_RISING:
                EXTI->FTSR |= (1 << copy_Config->EXTI_Line);
                EXTI->RTSR |= (1 << copy_Config->EXTI_Line);
                break;
            default:
                Local_u8ErrorState = NOK;
                break;
            }
            if (copy_Config->Callback != NULL)
            {
                EXTI_Callback[copy_Config->EXTI_Line] = copy_Config->Callback;
            }
            else
            {
                Local_u8ErrorState = NULL_POINTER;
            }
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}
uint8_t EXTI_u8EnableEXTI(EXTI_Line_t copy_line)
{
    uint8_t Local_u8ErrorState = OK;
    if (copy_line <= EXTI15)
    {
        EXTI->IMR |= (1 << copy_line);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}
uint8_t EXTI_u8DisabeEXTI(EXTI_Line_t copy_line)
{
    uint8_t Local_u8ErrorState = OK;
    if (copy_line <= EXTI15)
    {
        EXTI->IMR &= ~(1 << copy_line);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}
uint8_t EXTI_u8ClearPendingFlag(EXTI_Line_t copy_line)
{
    uint8_t Local_u8ErrorState = OK;
    if (copy_line <= EXTI15)
    {
        EXTI->PR |= (1 << copy_line);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}
uint8_t EXTI_u8GetPendingFlag(EXTI_Line_t copy_line, uint8_t *value)
{
    uint8_t Local_u8ErrorState = OK;
    if (copy_line <= EXTI15)
    {
        *value = (EXTI->PR >> copy_line) & 1;
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    register Local_u8ErrorState;
}

void EXTI0_IRQHandler(void)
{
    EXTI_voidClearPendingFlag(EXTI0);
    EXTI_Callback[EXTI0]();
}

void EXTI1_IRQHandler(void)
{
    EXTI_voidClearPendingFlag(EXTI1);
    EXTI_Callback[EXTI1]();
}

void EXTI2_IRQHandler(void)
{
    EXTI_voidClearPendingFlag(EXTI2);
    EXTI_Callback[EXTI2]();
}

void EXTI3_IRQHandler(void)
{
    EXTI_voidClearPendingFlag(EXTI3);
    EXTI_Callback[EXTI3]();
}

void EXTI4_IRQHandler(void)
{
    EXTI_voidClearPendingFlag(EXTI4);
    EXTI_Callback[EXTI4]();
}

void EXTI9_5_IRQHandler(void)
{
    if ((EXTI->PR >> EXTI5) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI5);
        EXTI_Callback[EXTI5]();
    }
    if ((EXTI->PR >> EXTI6) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI6);
        EXTI_Callback[EXTI6]();
    }
    if ((EXTI->PR >> EXTI7) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI7);
        EXTI_Callback[EXTI7]();
    }
    if ((EXTI->PR >> EXTI8) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI8);
        EXTI_Callback[EXTI8]();
    }
    if ((EXTI->PR >> EXTI9) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI9);
        EXTI_Callback[EXTI9]();
    }
}
void EXTI15_10_IRQHandler(void)
{
    if ((EXTI->PR >> EXTI10) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI10);
        EXTI_Callback[EXTI10]();
    }
    if ((EXTI->PR >> EXTI11) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI11);
        EXTI_Callback[EXTI11]();
    }
    if ((EXTI->PR >> EXTI12) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI12);
        EXTI_Callback[EXTI12]();
    }
    if ((EXTI->PR >> EXTI13) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI13);
        EXTI_Callback[EXTI13]();
    }
    if ((EXTI->PR >> EXTI14) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI14);
        EXTI_Callback[EXTI14]();
    }
    if ((EXTI->PR >> EXTI14) & 1)
    {
        EXTI_voidClearPendingFlag(EXTI15);
        EXTI_Callback[EXTI15]();
    }
}