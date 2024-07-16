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
    OTG_FS_WKUP_IRQ,
    TIM8_BRK_TIM12_IRQ,
    TIM8_UP_TIM13_IRQ,
    TIM8_TRG_COM_TIM14_IRQ,
    TIM8_CC_IRQ,
    DMA1_Stream7_IRQ,
    FSMC_IRQ,
    SDIO_IRQ,
    TIM5_IRQ,
    SPI3_IRQ,
    UART4_IRQ,
    UART5_IRQ,
    TIM6_DAC_IRQ,
    TIM7_IRQ,
    DMA2_Stream0_IRQ,
    DMA2_Stream1_IRQ,
    DMA2_Stream2_IRQ,
    DMA2_Stream3_IRQ,
    DMA2_Stream4_IRQ,
    CAN2_TX_IRQ = 63,
    CAN2_RX0_IRQ,
    CAN2_RX1_IRQ,
    CAN2_SCE_IRQ,
    OTG_FS_IRQ,
    DMA2_Stream5_IRQ,
    DMA2_Stream6_IRQ,
    DMA2_Stream7_IRQ,
    USART6_IRQ,
    I2C3_EV_IRQ,
    I2C3_ER_IRQ,
    OTG_HS_EP1_OUT_IRQ,
    OTG_HS_EP1_IN_IRQ,
    OTG_HS_WKUP_IRQ,
    OTG_HS_IRQ,
    DCMI_IRQ,
    FPU_IRQ = 81,
    SPI4_IRQ = 84,
    SAI1_IRQ = 87,
    SAI2_IRQ = 91,
    QUADSPI_IRQ,
    HDMI_CEC_IRQ,
    SPDIF_RX_IRQ,
    FMPI2C1_IRQ,
    FMPI2C1_ERROR_IRQ,
} IRQ_t;

/**
 * @fn     NVIC_u8Enable
 * @brief  Enable an interrupt
 * @param[in]   interruptNumber: The interrupt number
 * @retval Error status
 */
uint8_t NVIC_u8Enable(IRQ_t IRQ);

/**
 * @fn     NVIC_u8Disable
 * @brief  Disable an interrupt
 * @param[in]   IRQ: The interrupt number
 * @retval Error status
 */
uint8_t NVIC_u8Disable(IRQ_t IRQ);

/**
 * @fn     NVIC_u8SetPendingFlag
 * @brief  Set the pending flag for an interrupt
 * @param[in]   IRQ: The interrupt number
 * @retval Error status
 */
uint8_t NVIC_u8SetPendingFlag(IRQ_t IRQ);

/**
 * @fn     NVIC_u8ClearPendingFlag
 * @brief  Clear the pending flag for an interrupt
 * @param[in]   IRQ: The interrupt number
 * @retval Error status
 */
uint8_t NVIC_u8ClearPendingFlag(IRQ_t IRQ);

/**
 * @fn     NVIC_u8GetActiveFlag
 * @brief  Get the active flag for an interrupt
 * @param[in]   IRQ: The interrupt number
 * @param[out]  value: Pointer to store the active flag value
 * @retval Error status
 */
uint8_t NVIC_u8GetActiveFlag(IRQ_t IRQ, uint8_t *value);

/**
 * @fn     NVIC_u8SetPriority
 * @brief  Set the priority for an interrupt
 * @param[in]   IRQ: The interrupt number
 * @param[in]   priority: The priority value
 * @retval Error status
 */
uint8_t NVIC_u8SetPriority(IRQ_t IRQ, uint8_t priority);

#endif
