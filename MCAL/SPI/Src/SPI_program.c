#include "SPI_interface.h"
#include "CommonMacros.h"
#include "STM32F466xx.h"
#include "SPI_private.h"
#include "ErrType.h"

#define READY 0
#define BUSY 1

uint8_t TXState[2] = {READY, READY};
uint8_t *pTxBuffer[2] = {NULL, NULL}; // Pointer to the data to be sent
uint32_t TxLen[2] = {0, 0};           // Length of the data to be sent

void SPI4_IRQHandler(void);
void SPI1_IRQHandler(void);

static SPI_RegDef_t *SPIx[2] = {SPI1, SPI4};

void SPI_voidInit(SPI_Config_t *copy_Config)
{
    switch (copy_Config->DataFrameFormat)
    {
    case bit_8:
        CLEAR_BIT(SPIx[copy_Config->SPI]->CR1, DFF);
        break;
    case bit_16:
        SET_BIT(SPIx[copy_Config->SPI]->CR1, DFF);
        break;
    }
    switch (copy_Config->BaudRate)
    {
    case MSB:
        CLEAR_BIT(SPIx[copy_Config->SPI]->CR1, BR);
        break;
    case LSB:
        SET_BIT(SPIx[copy_Config->SPI]->CR1, BR);
        break;
    }
    switch (copy_Config->Mode)
    {
    case SLAVE:
        CLEAR_BIT(SPIx[copy_Config->SPI]->CR1, MSTR);
        break;
    case MASTER:
        SET_BIT(SPIx[copy_Config->SPI]->CR1, MSTR);
        break;
    }
    switch (copy_Config->TXInterrupt)
    {
    case TXI_ENABLED:
        SET_BIT(SPIx[copy_Config->SPI]->CR2, TXEIE);
        break;
    case TXI_DISABLED:
        CLEAR_BIT(SPIx[copy_Config->SPI]->CR2, TXEIE);
        break;
    }
    switch (copy_Config->RXInterrupt)
    {
    case RXI_ENABLED:
        SET_BIT(SPIx[copy_Config->SPI]->CR2, RXNEIE);
        break;
    case RXI_DISABLED:
        CLEAR_BIT(SPIx[copy_Config->SPI]->CR2, RXNEIE);
        break;
    }
    SET_BIT(SPIx[copy_Config->SPI]->CR1, SPE);
}

void SPI_voidSendData(uint16_t *pData, uint32_t Len, SPI_t copy_SPI)
{
    if (TXState[copy_SPI] == BUSY)
    {
        return;
    }
    pTxBuffer[copy_SPI] = pData;
    TxLen[copy_SPI] = Len;
    TXState[copy_SPI] = BUSY;
    SPIx[copy_SPI]->DR = *pTxBuffer[copy_SPI];
}

void SPI4_IRQHandler(void)
{
    if (READ_BIT(SPI4->SR, TXE))
    {
        SPI4->DR = *pTxBuffer[2];
        pTxBuffer[2]++;
        TxLen[2]--;
        if (TxLen[2] == 0)
        {
            TXState[2] = READY;
        }
    }
}
void SPI1_IRQHandler(void)
{
    if (READ_BIT(SPI1->SR, TXE))
    {
        SPI1->DR = *pTxBuffer[2];
        pTxBuffer[2]++;
        TxLen[2]--;
        if (TxLen[2] == 0)
        {
            TXState[2] = READY;
        }
    }
}