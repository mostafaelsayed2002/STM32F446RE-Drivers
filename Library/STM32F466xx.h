#include <cstdint>
#ifndef STM32F466XX_H
#define STM32F466XX_H

/******************************* Memories Base Addresses *******************************/

#define FLASH_BASE_ADDRESS 0x08000000UL // Flash memory base address
#define SRAM_BASE_ADDRESS 0x20000000UL  // SRAM base address
#define ROM_BASE_ADDRESS 0x1FFF0000UL   // System memory base address

/****************************** AHB1 Peripheral Base Addresses *************************/

#define GPIOA_BASE_ADDRESS 0x40020000UL           // GPIOA base address
#define GPIOB_BASE_ADDRESS 0x40020400UL           // GPIOB base address
#define GPIOC_BASE_ADDRESS 0x40020800UL           // GPIOC base address
#define GPIOD_BASE_ADDRESS 0x40020C00UL           // GPIOD base address
#define GPIOE_BASE_ADDRESS 0x40021000UL           // GPIOE base address
#define GPIOF_BASE_ADDRESS 0x40021400UL           // GPIOF base address
#define GPIOG_BASE_ADDRESS 0x40021800UL           // GPIOG base address
#define GPIOH_BASE_ADDRESS 0x40021C00UL           // GPIOH base address
#define CRC_BASE_ADDRESS 0x40023000UL             // GPIOI base address
#define RCC_BASE_ADDRESS 0x40023800UL             // RCC base address
#define FLASH_INTERFACE_BASE_ADDRESS 0x40023C00UL // Flash interface base address
#define BKPSRAM_BASE_ADDRESS 0x40024000UL         // Backup SRAM base address
#define DMA1_BASE_ADDRESS 0x40026000UL            // DMA1 base address
#define DMA2_BASE_ADDRESS 0x40026400UL            // DMA2 base address
#define USB_OTG_HS_BASE_ADDRESS 0x40040000UL      // USB OTG HS base address

/****************************** AHB2 Peripheral Base Addresses *************************/

#define USB_OTG_FS_BASE_ADDRESS 0x50000000UL // USB OTG FS base address
#define DCMI_BASE_ADDRESS 0x50050000UL       // DCMI base address

/****************************** AHB3 Peripheral Base Addresses *************************/

#define FMC_BASE_ADDRESS 0xA0000000UL // FMC base address
#define QUADSPI_BASE_ADDRESS 0xA0001000UL

/****************************** APB1 Peripheral Base Addresses *************************/

#define TIM2_BASE_ADDRESS 0x40000000UL     // TIM2 base address
#define TIM3_BASE_ADDRESS 0x40000400UL     // TIM3 base address
#define TIM4_BASE_ADDRESS 0x40000800UL     // TIM4 base address
#define TIM5_BASE_ADDRESS 0x40000C00UL     // TIM5 base address
#define TIM6_BASE_ADDRESS 0x40001000UL     // TIM6 base address
#define TIM7_BASE_ADDRESS 0x40001400UL     // TIM7 base address
#define TIM12_BASE_ADDRESS 0x40001800UL    // TIM12 base address
#define TIM13_BASE_ADDRESS 0x40001C00UL    // TIM13 base address
#define TIM14_BASE_ADDRESS 0x40002000UL    // TIM14 base address
#define RTC_BASE_ADDRESS 0x40002800UL      // RTC base address
#define WWDG_BASE_ADDRESS 0x40002C00UL     // WWDG base address
#define IWDG_BASE_ADDRESS 0x40003000UL     // IWDG base address
#define SPI2_BASE_ADDRESS 0x40003800UL     // SPI2 base address
#define SPI3_BASE_ADDRESS 0x40003C00UL     // SPI3 base address
#define SPDIF_RX_BASE_ADDRESS 0x40004000UL // SPDIFRX base address
#define USART2_BASE_ADDRESS 0x40004400UL   // USART2 base address
#define USART3_BASE_ADDRESS 0x40004800UL   // USART3 base address
#define UART4_BASE_ADDRESS 0x40004C00UL    // UART4 base address
#define UART5_BASE_ADDRESS 0x40005000UL    // UART5 base address
#define I2C1_BASE_ADDRESS 0x40005400UL     // I2C1 base address
#define I2C2_BASE_ADDRESS 0x40005800UL     // I2C2 base address
#define I2C3_BASE_ADDRESS 0x40005C00UL     // I2C3 base address
#define CAN1_BASE_ADDRESS 0x40006400UL     // CAN1 base address
#define CAN2_BASE_ADDRESS 0x40006800UL     // CAN2 base address
#define HDMI_CEC_BASE_ADDRESS 0x40006C00UL // HDMI-CEC base address
#define PWR_BASE_ADDRESS 0x40007000UL      // PWR base address
#define DAC_BASE_ADDRESS 0x40007400UL      // DAC base address

/****************************** APB2 Peripheral Base Addresses *************************/

#define TIM1_BASE_ADDRESS 0x40010000UL   // TIM1 base address
#define TIM8_BASE_ADDRESS 0x40010400UL   // TIM8 base address
#define USART1_BASE_ADDRESS 0x40011000UL // USART1 base address
#define USART6_BASE_ADDRESS 0x40011400UL // USART6 base address
#define ADC1_BASE_ADDRESS 0x40012000UL   // ADC1 base address
#define ADC2_BASE_ADDRESS 0x40012100UL   // ADC2 base address
#define ADC3_BASE_ADDRESS 0x40012200UL   // ADC3 base address
#define SDMMC_BASE_ADDRESS 0x40012C00UL  // SDMMC base address
#define SPI1_BASE_ADDRESS 0x40013000UL   // SPI1 base address
#define SPI4_BASE_ADDRESS 0x40013400UL   // SPI4 base address
#define SYSCFG_BASE_ADDRESS 0x40013800UL // SYSCFG base address
#define EXTI_BASE_ADDRESS 0x40013C00UL   // EXTI base address
#define TIM9_BASE_ADDRESS 0x40014000UL   // TIM9 base address
#define TIM10_BASE_ADDRESS 0x40014400UL  // TIM10 base address
#define TIM11_BASE_ADDRESS 0x40014800UL  // TIM11 base address
#define SAI1_BASE_ADDRESS 0x0x40015800UL // SAI1 base address
#define SAI2_BASE_ADDRESS 0x40015C00UL   // SAI2 base address

/****************************** Peripheral Register Definition Structures ******************/

typedef struct
{
    volatile uint32_t MODER;   // GPIO port mode register
    volatile uint32_t OTYPER;  // GPIO port output type register
    volatile uint32_t OSPEEDR; // GPIO port output speed register
    volatile uint32_t PUPDR;   // GPIO port pull-up/pull-down register
    volatile uint32_t IDR;     // GPIO port input data register
    volatile uint32_t ODR;     // GPIO port output data register
    volatile uint32_t BSRR;    // GPIO port bit set/reset register
    volatile uint32_t LCKR;    // GPIO port configuration lock register
    volatile uint32_t AFR[2];  // GPIO alternate function registers
} GPIO_RegDef_t;

#endif