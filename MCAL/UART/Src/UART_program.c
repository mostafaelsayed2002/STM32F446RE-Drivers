#include "UART_interface.h"
#include "UART_private.h"
#include "CommonMacros.h"
#include "STM32F466xx.h"
#include "ErrType.h"
#include <math.h>

// typedef struct
// {
//     UART_Over_t OverSa;
//     UART_WordLength_t WordLength;
//     UART_Parity_t Parity;
//     UART_Stop_t Stop;
//     uint32_t BaudRate;
//     uint32_t ClockFreq;
// } UART_Config_t;

static UART_RegDef_t *UARTx[] = {USART1, USART2, USART3, UART4, UART5, USART6};

uint8_t UART_u8Init(UART_Config_t *UART_Config)
{
    if (UART_Config == NULL)
        return NULL_POINTER;

    // OVER8 / OVER16
    CLEAR_BIT(UARTx[UART_Config->num]->CR1, UART_CR1_OVER8);
    UARTx[UART_Config->num]->CR1 |= (UART_Config->Over << UART_CR1_OVER8);
    // word length
    CLEAR_BIT(UARTx[UART_Config->num]->CR1, UART_CR1_M);
    UARTx[UART_Config->num]->CR1 |= (UART_Config->WordLength << UART_CR1_M);
    // parity
    if (UART_Config->Parity == UART_PARITY_DISABLED)
    {
        CLEAR_BIT(UARTx[UART_Config->num]->CR1, UART_CR1_PCE);
    }
    else
    {
        SET_BIT(UARTx[UART_Config->num]->CR1, UART_CR1_PCE);
        CLEAR_BIT(UARTx[UART_Config->num]->CR1, UART_CR1_PS);
        UARTx[UART_Config->num]->CR1 |= (UART_Config->Parity << UART_CR1_PS);
    }
    // stop bits
    UARTx[UART_Config->num]->CR2 &= ~(0b11 << UART_CR2_STOP);
    UARTx[UART_Config->num]->CR2 |= (UART_Config->Stop << UART_CR2_STOP);

    // baud rate
    uint64_t ClockFreq = UART_Config->ClockFreq;
    uint64_t clock = ClockFreq * 1000;
    uint32_t res = (clock / (8 * (2 - UART_Config->Over) * UART_Config->BaudRate));
    uint32_t Mantissa = res / 1000;
    uint32_t mod = res % 1000;
    uint32_t overSampling = UART_Config->Over == UART_OVER16 ? 16 : 8;
    uint32_t Fraction = ((mod * overSampling) / 1000.0) + 1;
    UARTx[UART_Config->num]->BRR = (Mantissa << 4) | Fraction;
    // enable UART
    SET_BIT(UARTx[UART_Config->num]->CR1, UART_CR1_UE);

    return OK;
}

uint8_t UART_u8Transmit(UART_t num, uint8_t Data)
{
    // Enble Transmit
    SET_BIT(UARTx[num]->CR1, UART_CR1_TE);


    while (READ_BIT(UARTx[num]->SR, UART_SR_TXE) == 0)
         ;
    UARTx[num]->DR = Data;
    return OK;
}
uint8_t UART_u8Receive(UART_t num, uint8_t *Data)
{
    // Enble Receive
    SET_BIT(UARTx[num]->CR1, UART_CR1_RE);

    while (READ_BIT(UARTx[num]->SR, UART_SR_RXNE) == 0)
        ;
    *Data = UARTx[num]->DR;
    return OK;
}
