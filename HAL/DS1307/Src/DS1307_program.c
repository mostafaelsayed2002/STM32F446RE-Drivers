#include "DS1307_interface.h"
#include "SYSTICK_interface.h"
#include "ErrType.h"

static uint8_t HEXtoBCD(uint8_t hex)
{
    return ((hex / 10) << 4) | (hex % 10);
}

static uint8_t BCDtoHEX(uint8_t bcd)
{
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

static I2C_t num = I2C1;

uint8_t DS1307_AttachI2C(I2C_t *num)
{
    num = num;
    return OK;
}

uint8_t DS1307_u8EnableClock()
{
    // CH = 0 to enable the clock
    uint8_t data[2] = {0x00, 0x00};
    I2C_Write(num, DS1307_ADDRESS, data, 2);
    return OK;
}

uint8_t DS1307_u8DisableClock()
{
    // CH = 1 to disable the clock
    uint8_t data[2] = {0x00, 0x80};
    I2C_Write(num, DS1307_ADDRESS, data, 2);
    return OK;
}

uint8_t DS1307_u8SetTime(DS1307_Time_t *Time)
{
    uint8_t data[8] = {0x00, HEXtoBCD(Time->Seconds), HEXtoBCD(Time->Minutes), HEXtoBCD(Time->Hours), HEXtoBCD(Time->Day), HEXtoBCD(Time->Date), HEXtoBCD(Time->Month), HEXtoBCD(Time->Year)};
    I2C_Write(num, DS1307_ADDRESS, data, 8);
    return OK;
}

uint8_t DS1307_u8GetTime(DS1307_Time_t *Time)
{
    uint8_t data[1] = {0x00};
    I2C_Write(num, DS1307_ADDRESS, data, 1);
    SYSTICK_voidDelayms(10);
    uint8_t dataReceived[7] = {0};
    I2C_Read(num, DS1307_ADDRESS, (uint8_t *)dataReceived, 7);
    Time->Seconds = BCDtoHEX(dataReceived[0]);
    Time->Minutes = BCDtoHEX(dataReceived[1]);
    Time->Hours = BCDtoHEX(dataReceived[2]);
    Time->Day = BCDtoHEX(dataReceived[3]);
    Time->Date = BCDtoHEX(dataReceived[4]);
    Time->Month = BCDtoHEX(dataReceived[5]);
    Time->Year = BCDtoHEX(dataReceived[6]);
    return OK;
}

uint8_t DS1307_u8SetHourMode(uint8_t HourMode)
{

    uint8_t data[2] = {0x02, (HourMode << 6)};
    I2C_Write(num, DS1307_ADDRESS, data, 2);
    return OK;
}
