#ifndef DS1307_INTERFACE_H
#define DS1307_INTERFACE_H

#include <stdint.h>
#include "I2C_interface.h"
#define DS1307_ADDRESS 0b1101000
typedef struct
{
    uint8_t Seconds;
    uint8_t Minutes;
    uint8_t Hours;
    uint8_t Day;
    uint8_t Date;
    uint8_t Month;
    uint8_t Year;
} DS1307_Time_t;

typedef enum
{
    DS1307_12H,
    DS1307_24H
} DS1307_HourMode_t;

uint8_t DS1307_AttachI2C(I2C_t *num);
uint8_t DS1307_u8EnableClock();
uint8_t DS1307_u8DisableClock();
uint8_t DS1307_u8SetTime(DS1307_Time_t *Time);
uint8_t DS1307_u8GetTime(DS1307_Time_t *Time);
uint8_t DS1307_u8SetHourMode(uint8_t HourMode);

#endif // DS1307_INTERFACE_H