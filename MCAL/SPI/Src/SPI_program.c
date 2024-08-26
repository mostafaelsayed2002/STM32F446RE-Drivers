#include "SPI_interface.h"
#include "CommonMacros.h"
#include "STM32F466xx.h"
#include "SPI_private.h"
#include "ErrType.h"

#define READY 0
#define BUSY 1

uint8_t TXState[3] = {READY, READY, READY};

static SPI_RegDef_t *SPIx[3] = {SPI1, SPI2, SPI3};
static uint16_t *SPIx_Data[3];
static uint32_t SPIx_Len[3];
static void (*SPI_Callback[3])(uint16_t);

uint8_t SPI_u8Init(SPI_Config_t *config)
{
    if (config == NULL)
        return NULL_POINTER;
    // 8 or 16 bit data frame format
    SPIx[config->SPI]->CR1 &= ~(1 << DFF);
    SPIx[config->SPI]->CR1 |= (config->DataFrameFormat << DFF);

    // MSB or LSB first
    SPIx[config->SPI]->CR1 &= ~(1 << LSBFIRST);
    SPIx[config->SPI]->CR1 |= (config->LSBFirst << LSBFIRST);

    // Master or Slave
    SPIx[config->SPI]->CR1 &= ~(1 << MSTR);
    SPIx[config->SPI]->CR1 |= (config->Mode << MSTR);

    // CPOL: Zero or One start
    SPIx[config->SPI]->CR1 &= ~(1 << CPOL);
    SPIx[config->SPI]->CR1 |= (config->clockPolarity << CPOL);

    // CPHA: First or Second edge
    SPIx[config->SPI]->CR1 &= ~(1 << CPHA);
    SPIx[config->SPI]->CR1 |= (config->clockPhase << CPHA);

    // Baud rate
    SPIx[config->SPI]->CR1 &= ~(0b111 << BR);
    SPIx[config->SPI]->CR1 |= (config->BaudRate << BR);

    // Software slave management
    SET_BIT(SPIx[config->SPI]->CR1, SSM);
    if (config->Mode == MASTER)
        SET_BIT(SPIx[config->SPI]->CR1, SSI);

    // Enable SPI
    SET_BIT(SPIx[config->SPI]->CR1, SPE);
    return OK;
}

uint8_t SPI_u8TransmitReceiveAsync(SPI_t copy_SPI, uint16_t *pData, uint32_t Len, void (*callback)(uint16_t))
{
    if (TXState[copy_SPI] == BUSY)
        return NOK;

    TXState[copy_SPI] = BUSY;
    SPIx_Data[copy_SPI] = pData;
    SPIx_Len[copy_SPI] = Len;
    SPI_Callback[copy_SPI] = callback;
    SPIx[copy_SPI]->DR = *pData;
    // Enable TXE interrupt
    SET_BIT(SPIx[copy_SPI]->CR2, TXEIE);
    return OK;
}

void SPI1_IRQHandler(void)
{
    if (READ_BIT(SPI1->SR, TXE))
    {
        SPIx_Len[0]--;
        if (SPIx_Len[0] > 0)
        {
            SPIx_Data[0]++;
            SPI1->DR = *(SPIx_Data[0]);
        }
        else
        {
            TXState[1] = READY;
            CLEAR_BIT(SPI1->CR2, TXEIE);
        }
    }
    if (READ_BIT(SPI1->SR, RXNE))
    {
        if (SPI_Callback[0] != NULL)
            SPI_Callback[0](SPI1->DR);
    }
}

void SPI2_IRQHandler(void)
{
    if (READ_BIT(SPI2->SR, TXE))
    {
        SPIx_Len[1]--;
        if (SPIx_Len[1] > 0)
        {
            SPIx_Data[1]++;
            SPI2->DR = *(SPIx_Data[1]);
        }
        else
        {
            TXState[1] = READY;
            CLEAR_BIT(SPI2->CR2, TXEIE);
        }
    }
    if (READ_BIT(SPI2->SR, RXNE))
    {
        if (SPI_Callback[1] != NULL)
            SPI_Callback[1](SPI2->DR);
    }
}

void SPI3_IRQHandler(void)
{
    if (READ_BIT(SPI3->SR, TXE))
    {
        SPIx_Len[2]--;
        if (SPIx_Len[2] > 0)
        {
            SPIx_Data[2]++;
            SPI3->DR = *(SPIx_Data[2]);
        }
        else
        {
            TXState[2] = READY;
            CLEAR_BIT(SPI3->CR2, TXEIE);
        }
    }
    if (READ_BIT(SPI3->SR, RXNE))
    {
        if (SPI_Callback[2] != NULL)
            SPI_Callback[2](SPI3->DR);
    }
}
