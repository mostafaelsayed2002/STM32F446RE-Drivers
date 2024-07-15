/***********************************************************************/
/* @file   NVIC_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for the NVIC driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "STM32F466xx.h"
#include "NVIC_interface.h"

void NVIC_voidEnable(InterruptNumber_t interruptNumber)
{
    uint8_t regIndex = interruptNumber / 32;
    uint8_t bitIndex = interruptNumber % 32;
    NVIC->ISER[regIndex] = (1 << bitIndex);
}
void NVIC_voidDisable(InterruptNumber_t interruptNumber)
{
    uint8_t regIndex = interruptNumber / 32;
    uint8_t bitIndex = interruptNumber % 32;
    NVIC->ICER[regIndex] = (1 << bitIndex);
}
void NVIC_voidSetPendingFlag(InterruptNumber_t interruptNumber)
{
    uint8_t regIndex = interruptNumber / 32;
    uint8_t bitIndex = interruptNumber % 32;
    NVIC->ISPR[regIndex] = (1 << bitIndex);
}
void NVIC_voidClearPendingFlag(InterruptNumber_t interruptNumber)
{
    uint8_t regIndex = interruptNumber / 32;
    uint8_t bitIndex = interruptNumber % 32;
    NVIC->ICPR[regIndex] = (1 << bitIndex);
}
uint8_t NVIC_u8GetActiveFlag(InterruptNumber_t interruptNumber)
{
    uint8_t regIndex = interruptNumber / 32;
    uint8_t bitIndex = interruptNumber % 32;
    return NVIC->IABR[regIndex] & (1 << bitIndex);
}
void NVIC_voidSetPriority(InterruptNumber_t interruptNumber, uint8_t priority)
{
    NVIC->IP[interruptNumber] = priority << 4;
}
