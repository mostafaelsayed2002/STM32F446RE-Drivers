#include <stdint.h>
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
#define SAI1_BASE_ADDRESS 0x40015800UL   // SAI1 base address
#define SAI2_BASE_ADDRESS 0x40015C00UL   // SAI2 base address

/****************************** Private peripheral bus Base Addresses *********************/

#define STK_BASE_ADDRESS 0xE000E010UL  // SysTick base address
#define NVIC_BASE_ADDRESS 0xE000E100UL // NVIC base address
#define SCB_BASE_ADDRESS 0xE000ED00UL  // System control block base address
#define MPU_BASE_ADDRESS 0xE000ED90UL  // Memory protection unit base address
#define FPU_BASE_ADDRESS 0xE000EF30UL  // Floating point unit base address

/****************************** GPIO Register Definition Structures ******************/

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

/****************************** RCC Register Definition Structures ******************/

typedef struct
{
    volatile uint32_t CR;           // RCC clock control register
    volatile uint32_t PLLCFGR;      // RCC PLL configuration register
    volatile uint32_t CFGR;         // RCC clock configuration register
    volatile uint32_t CIR;          // RCC clock interrupt register
    volatile uint32_t AHB1RSTR;     // RCC AHB1 peripheral reset register
    volatile uint32_t AHB2RSTR;     // RCC AHB2 peripheral reset register
    volatile uint32_t AHB3RSTR;     // RCC AHB3 peripheral reset register
    volatile uint32_t RESERVED0;    // Reserved
    volatile uint32_t APB1RSTR;     // RCC APB1 peripheral reset register
    volatile uint32_t APB2RSTR;     // RCC APB2 peripheral reset register
    volatile uint32_t RESERVED1[2]; // Reserved
    volatile uint32_t AHB1ENR;      // RCC AHB1 peripheral clock enable register
    volatile uint32_t AHB2ENR;      // RCC AHB2 peripheral clock enable register
    volatile uint32_t AHB3ENR;      // RCC AHB3 peripheral clock enable register
    volatile uint32_t RESERVED2;    // Reserved
    volatile uint32_t APB1ENR;      // RCC APB1 peripheral clock enable register
    volatile uint32_t APB2ENR;      // RCC APB2 peripheral clock enable register
    volatile uint32_t RESERVED3[2]; // Reserved
    volatile uint32_t AHB1LPENR;    // RCC AHB1 peripheral clock enable in low power mode register
    volatile uint32_t AHB2LPENR;    // RCC AHB2 peripheral clock enable in low power mode register
    volatile uint32_t AHB3LPENR;    // RCC AHB3 peripheral clock enable in low power mode register
    volatile uint32_t RESERVED4;    // Reserved
    volatile uint32_t APB1LPENR;    // RCC APB1 peripheral clock enable in low power mode register
    volatile uint32_t APB2LPENR;    // RCC APB2 peripheral clock enable in low power mode register
    volatile uint32_t RESERVED5[2]; // Reserved
    volatile uint32_t BDCR;         // RCC Backup domain control register
    volatile uint32_t CSR;          // RCC clock control & status register
    volatile uint32_t RESERVED6[2]; // Reserved
    volatile uint32_t SSCGR;        // RCC spread spectrum clock generation register
    volatile uint32_t PLLI2SCFGR;   // RCC PLLI2S configuration register
    volatile uint32_t PLLSAICFGR;   // RCC PLLSAI configuration register
    volatile uint32_t DCKCFGR;      // RCC Dedicated Clock Configuration Register
    volatile uint32_t CKGATENR;     // RCC clocks gated enable register
    volatile uint32_t DCKCFGR2;     // RCC dedicated clocks configuration register 2
} RCC_RegDef_t;

/****************************** SCB Register Definition Structures ******************/

typedef struct
{
    volatile uint32_t CPUID;   // CPUID base register
    volatile uint32_t ICSR;    // Interrupt control and state register
    volatile uint32_t VTOR;    // Vector table offset register
    volatile uint32_t AIRCR;   // Application interrupt and reset control register
    volatile uint32_t SCR;     // System control register
    volatile uint32_t CCR;     // Configuration and control register
    volatile uint8_t SHPR[12]; // System handler priority registers
    volatile uint32_t SHCSR;   // System handler control and state register
    volatile uint32_t CFSR;    // Configurable fault status register
    volatile uint32_t MMSR;    // MemManage fault address register
    volatile uint32_t BFSR;    // BusFault address register
    volatile uint32_t UFSR;    // UsageFault address register
    volatile uint32_t HFSR;    // HardFault address register
    volatile uint32_t MMFAR;   // MemManage fault status register
    volatile uint32_t BFAR;    // BusFault address register
    volatile uint32_t AFSR;    // Auxiliary fault status register
} SCB_RegDef_t;

/****************************** NVIC Register Definition Structures ******************/

typedef struct
{
    volatile uint32_t ISER[8]; // Interrupt set-enable registers
    volatile uint32_t RESERVED0[24];
    volatile uint32_t ICER[8]; // Interrupt clear-enable registers
    volatile uint32_t RESERVED1[24];
    volatile uint32_t ISPR[8]; // Interrupt set-pending registers
    volatile uint32_t RESERVED2[24];
    volatile uint32_t ICPR[8]; // Interrupt clear-pending registers
    volatile uint32_t RESERVED3[24];
    volatile uint32_t IABR[8]; // Interrupt active bit registers
    volatile uint32_t RESERVED4[56];
    volatile uint8_t IP[240]; // Interrupt priority registers

} NVIC_RegDef_t;

/****************************** GPIO Definitions **************************************/

#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_RegDef_t *)GPIOD_BASE_ADDRESS)
#define GPIOE ((GPIO_RegDef_t *)GPIOE_BASE_ADDRESS)
#define GPIOF ((GPIO_RegDef_t *)GPIOF_BASE_ADDRESS)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASE_ADDRESS)
#define GPIOH ((GPIO_RegDef_t *)GPIOH_BASE_ADDRESS)

/****************************** RCC Definitions **************************************/

#define RCC ((RCC_RegDef_t *)RCC_BASE_ADDRESS)

/****************************** SCB Definitions **************************************/

#define SCB ((SCB_RegDef_t *)SCB_BASE_ADDRESS)

/****************************** NVIC Definitions **************************************/

#define NVIC ((NVIC_RegDef_t *)NVIC_BASE_ADDRESS)

#endif