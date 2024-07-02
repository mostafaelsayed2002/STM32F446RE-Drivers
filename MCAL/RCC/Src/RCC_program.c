/***********************************************************************/
/* @file   RCC_program.c
 * @author Mostafa Elsayed
 * @brief  This file contains the implementation for RCC driver
 * @date   2/7/2024
 */

#include <stdint.h>
#include "STM32F466xx.h"

#include "RCC_interface.h"
#include "RCC_private.h"

void RCC_voidAHB1EnablePeripheralClock(uint8_t peripheral)
{
    RCC->AHB1ENR |= (1 << peripheral);
}