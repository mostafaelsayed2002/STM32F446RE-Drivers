#include <stdint.h>
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

typedef enum
{
    WWDG_IRQ,
    PVD_IRQ,
    TAMP_STAMP_IRQ,
    RTC_WKUP_IRQ,
    FLASH_IRQ,
    RCC_IRQ,
    EXTI0_IRQ,
    EXTI1_IRQ,
    EXTI2_IRQ,
    EXTI3_IRQ,
    EXTI4_IRQ,
    DMA1_Stream0_IRQ,
    DMA1_Stream1_IRQ,
    DMA1_Stream2_IRQ,
    DMA1_Stream3_IRQ,
    DMA1_Stream4_IRQ,
    DMA1_Stream5_IRQ,
    DMA1_Stream6_IRQ,
    ADC_IRQ,
    CAN1_TX_IRQ,
    CAN1_RX0_IRQ,
    CAN1_RX1_IRQ,
    CAN1_SCE_IRQ,
    EXTI9_5_IRQ,
    TIM1_BRK_TIM9_IRQ,
    TIM1_UP_TIM10_IRQ,
    TIM1_TRG_COM_TIM11_IRQ,
    TIM1_CC_IRQ,
    TIM2_IRQ,
    TIM3_IRQ,
    TIM4_IRQ,
    I2C1_EV_IRQ,
    I2C1_ER_IRQ,
    I2C2_EV_IRQ,
    I2C2_ER_IRQ,
    SPI1_IRQ,
    SPI2_IRQ,
    USART1_IRQ,
    USART2_IRQ,
    USART3_IRQ,
    EXTI15_10_IRQ,
    RTC_Alarm_IRQ,
} InterruptNumber_t;

void NVIC_voidEnable(InterruptNumber_t interruptNumber);
void NVIC_voidDisable(InterruptNumber_t interruptNumber);
void NVIC_voidSetPendingFlag(InterruptNumber_t interruptNumber);
void NVIC_voidClearPendingFlag(InterruptNumber_t interruptNumber);
uint8_t NVIC_u8GetActiveFlag(InterruptNumber_t interruptNumber);
void NVIC_voidSetPriority(InterruptNumber_t interruptNumber, uint8_t priority);

#endif
