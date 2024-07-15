/***********************************************************************/
/* @file   EXTI_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for the EXTI driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "STM32F466xx.h"
#include "EXTI_interface.h"

static void (*EXTI_Callback[23])(void);

void EXTI_voidInit(EXTI_Config_t *EXTI_Config)
{

    if (EXTI_Config->EnableState == UNMASKED)
    {
        EXTI->IMR |= (1 << EXTI_Config->EXTI_Line);
    }
    if (EXTI_Config->TriggerEvent == FALLING)
    {
        EXTI->FTSR |= (1 << EXTI_Config->EXTI_Line);
    }
    else if (EXTI_Config->TriggerEvent == RISING)
    {
        EXTI->RTSR |= (1 << EXTI_Config->EXTI_Line);
    }
    else if (EXTI_Config->TriggerEvent == FALLING_RISING)
    {
        EXTI->FTSR |= (1 << EXTI_Config->EXTI_Line);
        EXTI->RTSR |= (1 << EXTI_Config->EXTI_Line);
    }
    EXTI_Callback[EXTI_Config->EXTI_Line] = EXTI_Config->Callback;
}
void EXTI_voidEnableEXTI(EXTI_Line_t EXTI_Line)
{
    EXTI->IMR |= (1 << EXTI_Line);
}
void EXTI_voidDisabeEXTI(EXTI_Line_t EXTI_Line)
{
    EXTI->IMR &= ~(1 << EXTI_Line);
}
void EXTI_voidClearPendingFlag(EXTI_Line_t EXTI_Line)
{
    EXTI->PR |= (1 << EXTI_Line);
}
uint8_t EXTI_u8GetPendingFlag(EXTI_Line_t EXTI_Line)
{
    return EXTI->PR & (1 << EXTI_Line);
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
    if (EXTI_u8GetPendingFlag(EXTI5))
    {
        EXTI_voidClearPendingFlag(EXTI5);
        EXTI_Callback[EXTI5]();
    }
    if (EXTI_u8GetPendingFlag(EXTI6))
    {
        EXTI_voidClearPendingFlag(EXTI6);
        EXTI_Callback[EXTI6]();
    }
    if (EXTI_u8GetPendingFlag(EXTI7))
    {
        EXTI_voidClearPendingFlag(EXTI7);
        EXTI_Callback[EXTI7]();
    }
    if (EXTI_u8GetPendingFlag(EXTI8))
    {
        EXTI_voidClearPendingFlag(EXTI8);
        EXTI_Callback[EXTI8]();
    }
    if (EXTI_u8GetPendingFlag(EXTI9))
    {
        EXTI_voidClearPendingFlag(EXTI9);
        EXTI_Callback[EXTI9]();
    }
}
void EXTI15_10_IRQHandler(void)
{
    if (EXTI_u8GetPendingFlag(EXTI10))
    {
        EXTI_voidClearPendingFlag(EXTI10);
        EXTI_Callback[EXTI10]();
    }
    if (EXTI_u8GetPendingFlag(EXTI11))
    {
        EXTI_voidClearPendingFlag(EXTI11);
        EXTI_Callback[EXTI11]();
    }
    if (EXTI_u8GetPendingFlag(EXTI12))
    {
        EXTI_voidClearPendingFlag(EXTI12);
        EXTI_Callback[EXTI12]();
    }
    if (EXTI_u8GetPendingFlag(EXTI13))
    {
        EXTI_voidClearPendingFlag(EXTI13);
        EXTI_Callback[EXTI13]();
    }
    if (EXTI_u8GetPendingFlag(EXTI14))
    {
        EXTI_voidClearPendingFlag(EXTI14);
        EXTI_Callback[EXTI14]();
    }
    if (EXTI_u8GetPendingFlag(EXTI15))
    {
        EXTI_voidClearPendingFlag(EXTI15);
        EXTI_Callback[EXTI15]();
    }
}