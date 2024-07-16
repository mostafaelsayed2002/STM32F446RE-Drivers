#include <stdint.h>
#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

#include "EXTI_interface.h"
#include "GPIO_interface.h"

typedef enum
{
    EXTI0,
    EXTI1,
    EXTI2,
    EXTI3,
    EXTI4,
    EXTI5,
    EXTI6,
    EXTI7,
    EXTI8,
    EXTI9,
    EXTI10,
    EXTI11,
    EXTI12,
    EXTI13,
    EXTI14,
    EXTI15
} SYSCFG_Line_t;

typedef enum
{
    PORTA = 0,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTG,
    PORTH
} SYSCFG_Port_t;

/**
 * @fn     SYSCFG_u8SetExtiPort
 * @brief  Set the EXTI port for a specific line
 * @param[in]   line: The EXTI line
 * @param[in]   port: The EXTI port
 * @retval Error status
 */
uint8_t SYSCFG_u8SetExtiPort(SYSCFG_Line_t line, SYSCFG_Port_t port);

#endif