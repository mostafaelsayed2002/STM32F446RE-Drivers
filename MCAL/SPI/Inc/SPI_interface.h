#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include <stdint.h>

typedef enum
{
    SPI1,
    SPI4
} SPI_t;

typedef enum
{
    bit_8,
    bit_16
} DFF_t;

typedef enum
{
    MSB,
    LSB
} LSBFIRST_t;

typedef enum
{
    Fpclk_2,
    Fpclk_4,
    Fpclk_8,
    Fpclk_16,
    Fpclk_32,
    Fpclk_64,
    Fpclk_128,
    Fpclk_256
} BR_t;

typedef enum
{
    SLAVE,
    MASTER
} MODE_t;

typedef enum
{
    TXI_ENABLED,
    TXI_DISABLED
} TXI_t;

typedef enum
{
    RXI_ENABLED,
    RXI_DISABLED
} RXI_t;

typedef struct
{
    SPI_t SPI;
    DFF_t DataFrameFormat;
    LSBFIRST_t LSBFirst;
    BR_t BaudRate;
    MODE_t Mode;
    TXI_t TXInterrupt;
    RXI_t RXInterrupt;
} SPI_Config_t;

void SPI_voidInit(SPI_Config_t *copy_Config);
void SPI_voidSendData(uint16_t copy_Data, SPI_t copy_SPI);

#endif