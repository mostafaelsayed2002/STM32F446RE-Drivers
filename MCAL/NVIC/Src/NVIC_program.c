/***********************************************************************/
/* @file   NVIC_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for the NVIC driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "ErrType.h"
#include "STM32F466xx.h"
#include "NVIC_interface.h"

uint8_t NVIC_u8Enable(IRQ_t IRQ)
{
    uint8_t Local_u8ErrorState = OK;
    if (IRQ <= FMPI2C1_ERROR_IRQ)
    {
        uint8_t regIndex = IRQ / 32;
        uint8_t bitIndex = IRQ % 32;
        NVIC->ISER[regIndex] = (1 << bitIndex);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}
uint8_t NVIC_u8Disable(IRQ_t IRQ)
{
    uint8_t Local_u8ErrorState = OK;
    if (IRQ <= FMPI2C1_ERROR_IRQ)
    {
        uint8_t regIndex = IRQ / 32;
        uint8_t bitIndex = IRQ % 32;
        NVIC->ICER[regIndex] = (1 << bitIndex);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}
uint8_t NVIC_u8SetPendingFlag(IRQ_t IRQ)
{
    uint8_t Local_u8ErrorState = OK;
    if (IRQ <= FMPI2C1_ERROR_IRQ)
    {
        uint8_t regIndex = IRQ / 32;
        uint8_t bitIndex = IRQ % 32;
        NVIC->ISPR[regIndex] = (1 << bitIndex);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}
uint8_t NVIC_u8ClearPendingFlag(IRQ_t IRQ)
{
    uint8_t Local_u8ErrorState = OK;
    if (IRQ <= FMPI2C1_ERROR_IRQ)
    {
        uint8_t regIndex = IRQ / 32;
        uint8_t bitIndex = IRQ % 32;
        NVIC->ICPR[regIndex] = (1 << bitIndex);
    }
    else
    {
        return NOK;
    }
    return Local_u8ErrorState;
}
uint8_t NVIC_u8GetActiveFlag(IRQ_t IRQ, uint8_t *value)
{
    uint8_t Local_u8ErrorState = OK;
    if (IRQ <= FMPI2C1_ERROR_IRQ)
    {
        uint8_t regIndex = IRQ / 32;
        uint8_t bitIndex = IRQ % 32;
        *value = (NVIC->IABR[regIndex] >> bitIndex) & 1;
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}
uint8_t NVIC_u8SetPriority(IRQ_t IRQ, uint8_t priority)
{

    uint8_t Local_u8ErrorState = OK;
    if (IRQ <= FMPI2C1_ERROR_IRQ)
    {
        NVIC->IP[IRQ] = priority << 4;
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}
