/***********************************************************************/
/* @file   SYSCFG_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for the SYSCFG driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "ErrType.h"
#include "STM32F466xx.h"
#include "SYSCFG_interface.h"

uint8_t SYSCFG_u8SetExtiPort(SYSCFG_Line_t line, SYSCFG_Port_t port)
{
    uint8_t Local_u8ErrorState = OK;

    if (line <= EXTI15 && port <= PORTH)
    {
        uint8_t regNum = line / 4;
        uint8_t pinNum = line % 4;
        SYSCFG->EXTICR[regNum] &= ~(0xF << (pinNum * 4));
        SYSCFG->EXTICR[regNum] |= (port << (pinNum * 4));
    }
    else
    {
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}