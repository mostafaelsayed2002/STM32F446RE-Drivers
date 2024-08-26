#include <stdint.h>
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void RCC_voidAHB1EnablePeripheralClock(uint8_t peripheral);

void RCC_voidAPB2EnablePeripheralClock(uint8_t peripheral);
void RCC_voidAPB1EnablePeripheralClock(uint8_t peripheral);

#endif