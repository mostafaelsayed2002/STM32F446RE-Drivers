#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H

#include <stdint.h>

typedef enum
{
    I2C1,
    I2C2,
    I2C3
} I2C_t;

typedef enum
{
    I2C_SM,
    I2C_FM
} I2C_Mode_t;

typedef enum
{
    I2C_2,
    I2C_16_9
} I2C_DutyCycle_t;

typedef struct
{
    I2C_t I2C;
    uint32_t ClockSpeed;
    I2C_Mode_t Mode;
    uint16_t CCRValue;
    uint16_t TRISEValue;
} I2C_Config_t;

uint8_t I2C_Init(I2C_Config_t *I2C_Config);
uint8_t I2C_Write(I2C_t num, uint8_t SlaveAddress, uint8_t *Data, uint8_t DataSize);
uint8_t I2C_Read(I2C_t num, uint8_t SlaveAddress, uint8_t registerNum, uint8_t *Data, uint8_t DataSize);

#endif