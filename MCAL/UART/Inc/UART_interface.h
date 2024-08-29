#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

#include <stdint.h>

typedef enum
{
    UART1,
    UART2,
    UART3,
    UART4,
    UART5,
    UART6
} UART_t;

typedef enum
{
    UART_OVER16,
    UART_OVER8

} UART_Over_t;

typedef enum
{
    UART_8BIT,
    UART_9BIT
} UART_WordLength_t;

typedef enum
{
    UART_PARITY_EVEN,
    UART_PARITY_ODD,
    UART_PARITY_DISABLED,
} UART_Parity_t;

typedef enum
{
    UART_STOP_1BIT,
    UART_STOP_0_5BIT,
    UART_STOP_2BIT,
    UART_STOP_1_5BIT
} UART_Stop_t;

typedef struct
{
    UART_t num;
    UART_Over_t Over;
    UART_WordLength_t WordLength;
    UART_Parity_t Parity;
    UART_Stop_t Stop;
    uint32_t BaudRate;
    uint32_t ClockFreq;
} UART_Config_t;

uint8_t UART_u8Init(UART_Config_t *UART_Config);
uint8_t UART_u8Transmit(UART_t num, uint8_t Data);
uint8_t UART_u8Receive(UART_t num, uint8_t *Data);

#endif