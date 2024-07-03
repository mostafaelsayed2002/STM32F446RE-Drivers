#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <stdint.h>

void LCD_voidInit(void);
void LCD_voidCmd(uint8_t input);
void LCD_voidWrite(uint8_t input);

#endif
