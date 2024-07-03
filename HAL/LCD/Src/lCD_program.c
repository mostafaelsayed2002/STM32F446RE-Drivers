/***********************************************************************/
/* @file   LCD_program.c
 * @author Mostafa Elsayed
 * @brief This file contains the implementation for the LCD driver
 * @date   3/7/2024
 */

#include <stdint.h>
#include "STM32F10xxx.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

static GPIO_PinConfig_t control[2] = {
    {.port = RS_PORT, .pin = RS_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = EN_PORT, .pin = EN_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL}};

static GPIO_PinConfig_t data[4] = {

    {.port = D4_PORT, .pin = D4_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = D5_PORT, .pin = D5_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = D6_PORT, .pin = D6_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = D7_PORT, .pin = D7_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL}};

void LCD_voidInit(void)
{

    GPIO_u8InitPin(&control[0]);
    GPIO_u8InitPin(&control[1]);
    for (uint8_t i = 0; i < 4; i++)
    {
        GPIO_u8InitPin(&data[i]);
    }

    LCD_voidCmd(0x02);
    LCD_voidCmd(0x01);
    LCD_voidCmd(0x0c);
    LCD_voidCmd(0x06);
}

void LCD_voidCmd(uint8_t cmd)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        GPIO_u8SetPinValue(data[i].port, data[i].pin, (cmd >> (i + 4)) & 1);
    }
    GPIO_u8SetPinValue(RS_PORT, RS_PIN, 0);
    GPIO_u8SetPinValue(EN_PORT, EN_PIN, 1);

    for (uint64_t i = 0; i < 2000; i++)
        ;

    GPIO_u8SetPinValue(EN_PORT, EN_PIN, 0);

    for (uint64_t i = 0; i < 2000; i++)
        ;

    for (uint8_t i = 0; i < 4; i++)
    {
        GPIO_u8SetPinValue(data[i].port, data[i].pin, (cmd >> (i)) & 1);
    }

    GPIO_u8SetPinValue(EN_PORT, EN_PIN, 1);
    for (uint64_t i = 0; i < 2000; i++)
        ;
    GPIO_u8SetPinValue(EN_PORT, EN_PIN, 0);

    for (uint64_t i = 0; i < 2000; i++)
        ;
}

void LCD_voidWrite(uint8_t input)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        GPIO_u8SetPinValue(data[i].port, data[i].pin, (input >> (i + 4)) & 1);
    }
    GPIO_u8SetPinValue(RS_PORT, RS_PIN, 1);
    GPIO_u8SetPinValue(EN_PORT, EN_PIN, 1);

    for (uint64_t i = 0; i < 2000; i++)
        ;

    GPIO_u8SetPinValue(EN_PORT, EN_PIN, 0);

    for (uint64_t i = 0; i < 2000; i++)
        ;

    for (uint8_t i = 0; i < 4; i++)
    {
        GPIO_u8SetPinValue(data[i].port, data[i].pin, (input >> (i)) & 1);
    }

    GPIO_u8SetPinValue(EN_PORT, EN_PIN, 1);
    for (uint64_t i = 0; i < 2000; i++)
        ;
    GPIO_u8SetPinValue(EN_PORT, EN_PIN, 0);

    for (uint64_t i = 0; i < 2000; i++)
        ;
}