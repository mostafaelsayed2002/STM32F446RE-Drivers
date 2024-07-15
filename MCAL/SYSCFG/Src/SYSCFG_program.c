/***********************************************************************/
/* @file   SYSCFG_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for the SYSCFG driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "STM32F466xx.h"
#include "SYSCFG_interface.h"
#include "EXTI_interface.h"
#include "GPIO_interface.h"

void SYSCFG_voidSetExtiPort(EXTI_Line_t line, Port_t port)
{
    uint8_t regNum = line / 4;
    uint8_t pinNum = line % 4;
    SYSCFG->EXTICR[regNum] &= ~(0xF << (pinNum * 4));
    SYSCFG->EXTICR[regNum] |= (port << (pinNum * 4));
}