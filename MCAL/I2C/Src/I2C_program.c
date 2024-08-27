#include "I2C_interface.h"
#include "I2C_private.h"
#include "CommonMacros.h"
#include "STM32F466xx.h"
#include "ErrType.h"

static I2C_RegDef_t *I2Cx[] = {I2C1, I2C2, I2C3};

static void Start(I2C_t num)
{
    I2Cx[num]->CR1 |= START;
    while (!(I2Cx[num]->SR1 & SB))
        ;
}

static void Stop(I2C_t num)
{
    I2Cx[num]->CR1 |= STOP;
}

static void SendSlaveAddress(I2C_t num, uint8_t SlaveAddress, uint8_t RW)
{
    // Send Slave Address with R/W bit
    I2Cx[num]->DR = (SlaveAddress << 1 || RW);

    while (!(I2Cx[num]->SR1 & ADD))
        ; // Wait for address to be sent

    // Clear ADDR by reading SR1 followed by SR2
    (void)I2Cx[num]->SR1;
    (void)I2Cx[num]->SR2;
}

static void SendData(I2C_t num, uint8_t *Data, uint8_t DataSize)
{
    for (uint8_t i = 0; i < DataSize; i++)
    {
        I2Cx[num]->DR = Data[i];
        while (!(I2Cx[num]->SR1 & BTF))
            ;
    }
}

static void ReadData(I2C_t num, uint8_t *Data, uint8_t DataSize)
{
    for (uint16_t i = 0; i < DataSize; i++)
    {
        if (i == DataSize - 1)
        {
            // For the last byte, disable ACK and send a NACK
            SET_BIT(I2Cx[num]->CR1, ACK);
        }
        else
        {
            // Enable ACK for all other bytes
            CLEAR_BIT(I2Cx[num]->CR1, ACK);
        }

        // Wait until the data is received
        while (!(READ_BIT(I2Cx[num]->SR1, RXNE)))
            ;
        // Read the received data
        Data[i] = I2Cx[num]->DR;
    }
}

uint8_t I2C_Init(I2C_Config_t *I2C_Config)
{
    if (I2C_Config == NULL)
        return NULL_POINTER;

    if (I2C_Config->ClockSpeed > 50 || I2C_Config->ClockSpeed < 2)
        return NOK;

    // Disable the I2C peripheral
    CLEAR_BIT(I2Cx[I2C_Config->I2C]->CR1, PE);

    // FREQ[5:0] Set the peripheral clock frequency
    I2Cx[I2C_Config->I2C]->CR2 &= ~(0x3F);
    I2Cx[I2C_Config->I2C]->CR2 |= I2C_Config->ClockSpeed;

    // CCR
    I2Cx[I2C_Config->I2C]->CCR = I2C_Config->CCRValue;

    // Mode: SM, FM
    CLEAR_BIT(I2Cx[I2C_Config->I2C]->CCR, F_S);
    I2Cx[I2C_Config->I2C]->CCR |= (I2C_Config->Mode << F_S);

    // Trise
    I2Cx[I2C_Config->I2C]->TRISE = I2C_Config->TRISEValue;

    // Enable the I2C peripheral
    SET_BIT(I2Cx[I2C_Config->I2C]->CR1, PE);
}

uint8_t I2C_Write(I2C_t num, uint8_t SlaveAddress, uint8_t *Data, uint8_t DataSize)
{
    Start(num);
    SendSlaveAddress(num, SlaveAddress, 0); // Write
    SendData(num, Data, DataSize);
    Stop(num);
    return OK;
}

uint8_t I2C_Read(I2C_t num, uint8_t SlaveAddress, uint8_t registerNum, uint8_t *Data, uint8_t DataSize)
{

    Start(num);
    SendSlaveAddress(num, SlaveAddress, 0); // Write
    SendData(num, &registerNum, 1);

    // Repeated Start
    Start(num);
    SendSlaveAddress(num, SlaveAddress, 1); // Read
    ReadData(num, Data, DataSize);
    Stop(num);

    return OK;
}
