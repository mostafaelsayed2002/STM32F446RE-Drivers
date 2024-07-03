#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <stdint.h>
#include "GPIO_interface.h"

void BUTTON_voidInit(Port_t port, Pin_t pin, PullUpDown_t pullType);
uint8_t BUTTON_voidRead();

#endif
