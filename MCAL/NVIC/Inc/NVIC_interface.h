#include <stdint.h>
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

typedef enum
{
    WWDG,
    PVD,
    TAMP_STAMP,
    RTC_WKUP,
    FLASH,
    RCC,
    EXTI0,
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    DMA1_Stream0,
    DMA1_Stream1,
    DMA1_Stream2,
    DMA1_Stream3,
    DMA1_Stream4,
    DMA1_Stream5,
    DMA1_Stream6,
    ADC,
    CAN1_TX,
    CAN1_RX0,
    CAN1_RX1,
    CAN1_SCE,
    EXTI9_5,
    TIM1_BRK_TIM9,
    TIM1_UP_TIM10,
    TIM1_TRG_COM_TIM11,
    TIM1_CC,
    TIM2,
    TIM3,
    TIM4,
    I2C1_EV,
    I2C1_ER,
    I2C2_EV,
    I2C2_ER,
    SPI1,
    SPI2,
    USART1,
    USART2,
    USART3,
    EXTI15_10,
    RTC_Alarm,
} InterruptNumber_t;

void NVIC_voidEnable(InterruptNumber_t interruptNumber);
void NVIC_voidDisable(InterruptNumber_t interruptNumber);
void NVIC_voidSetPendingFlag(InterruptNumber_t interruptNumber);
void NVIC_voidClearPendingFlag(InterruptNumber_t interruptNumber);
uint8_t NVIC_u8GetActiveFlag(InterruptNumber_t interruptNumber);
void NVIC_voidSetPriority(InterruptNumber_t interruptNumber, uint8_t priority);

#endif