/***********************************************************************/
/* @file   SEVEN_SEGMENT_program.c
 * @author Mostafa Elsayed
 * @brief This file contains the implementation of the functions used to control the 16x2 LCD
 * @date   3/7/2024
 */

#include "SEVEN_SEGMENT_interface.h"
#include "SEVEN_SEGMENT_config.h"
#include "GPIO_interface.h"

static uint8_t seven_segment_numbers[16] = {0b00111111,  // 0
                                            0b00000110,  // 1
                                            0b01011011,  // 2
                                            0b01001111,  // 3
                                            0b01100110,  // 4
                                            0b01101101,  // 5
                                            0b01111101,  // 6
                                            0b00000111,  // 7
                                            0b01111111,  // 8
                                            0b01101111,  // 9
                                            0b01110111,  // A
                                            0b01111100,  // B
                                            0b00111001,  // C
                                            0b01011110,  // D
                                            0b01111001,  // E
                                            0b01110001}; // F

static GPIO_PinConfig_t data[8] = {
    {.port = A_PORT, .pin = A_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = B_PORT, .pin = B_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = C_PORT, .pin = C_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = D_PORT, .pin = D_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = E_PORT, .pin = E_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = F_PORT, .pin = F_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = G_PORT, .pin = G_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL},
    {.port = DOT_PORT, .pin = DOT_PIN, .mode = OUTPUT_10MHZ, .config = OUTPUT_PUSH_PULL}};

void SEVEN_SEGMENT_voidInit(void)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        GPIO_u8InitPin(&data[i]);
    }
}
void SEVEN_SEGMENT_voidDisplay(uint8_t number, uint8_t dot)
{
    for (uint8_t i = 0; i < 7; i++)
    {
        GPIO_u8SetPinValue(data[i].port, data[i].pin, (seven_segment_numbers[number] >> i) & 1);
    }
    GPIO_u8SetPinValue(DOT_PORT, DOT_PIN, dot);
}
