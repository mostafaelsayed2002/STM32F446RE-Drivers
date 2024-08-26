#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include <stdint.h>

typedef enum
{
    SPI1,
    SPI2,
    SPI3,
} SPI_t;

typedef enum
{
    BIT8,
    BIT16
} DFF_t;

typedef enum
{
    MSB,
    LSB
} LSBFIRST_t;

typedef enum
{
    FPCLK_2,
    FPCLK_4,
    FPCLK_8,
    FPCLK_16,
    FPCLK_32,
    FPCLK_64,
    FPCLK_128,
    FPCLK_256
} BR_t;

typedef enum
{
    SLAVE,
    MASTER
} MODE_t;

typedef enum
{
    ZERO_START,
    ONE_START
} CPOL_t;

typedef enum
{
    FIRST_EDGE,
    SECOND_EDGE
} CPHA_t;

typedef struct
{
    SPI_t SPI;
    DFF_t DataFrameFormat;
    LSBFIRST_t LSBFirst;
    BR_t BaudRate;
    MODE_t Mode;
    CPOL_t clockPolarity;
    CPHA_t clockPhase;
} SPI_Config_t;

uint8_t SPI_u8Init(SPI_Config_t *copy_Config);
uint8_t SPI_u8Transmit_IT(SPI_t copy_SPI, uint16_t *pData, uint32_t Len);
uint8_t SPI_u8ReceiveIT(SPI_t copy_SPI, void (*callback)(uint16_t));

#endif