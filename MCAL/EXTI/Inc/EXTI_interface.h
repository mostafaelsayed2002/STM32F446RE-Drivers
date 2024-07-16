#include <stdint.h>
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum
{
    FALLING,
    RISING,
    FALLING_RISING
} TriggerEvent_t;

typedef enum
{
    MASKED,
    UNMASKED
} MaskState_t;

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
} EXTI_Line_t;

typedef struct
{
    TriggerEvent_t TriggerEvent;
    MaskState_t EnableState;
    EXTI_Line_t EXTI_Line;
    void (*Callback)(void);
} EXTI_Config_t;

/**
 * @fn     EXTI_u8Init
 * @brief  Initialize the EXTI peripheral with the given configuration
 * @param[in]  copy_Config: A pointer to the configuration structure
 * @retval Error status
 */
uint8_t EXTI_u8Init(EXTI_Config_t *copy_Config);

/**
 * @fn     EXTI_u8EnableEXTI
 * @brief  Enable the EXTI line
 * @param[in]  copy_line: The EXTI line to enable
 * @retval Error status
 */
uint8_t EXTI_u8EnableEXTI(EXTI_Line_t copy_line);

/**
 * @fn     EXTI_u8DisabeEXTI
 * @brief  Disable the EXTI line
 * @param[in]  copy_line: The EXTI line to disable
 * @retval Error status
 */
uint8_t EXTI_u8DisabeEXTI(EXTI_Line_t copy_line);

/**
 * @fn     EXTI_u8ClearPendingFlag
 * @brief  Clear the pending flag of the EXTI line
 * @param[in]  copy_line: The EXTI line to clear the pending flag for
 * @retval Error status
 */
uint8_t EXTI_u8ClearPendingFlag(EXTI_Line_t copy_line);

/**
 * @fn     EXTI_u8GetPendingFlag
 * @brief  Get the pending flag status of the EXTI line
 * @param[in]  copy_line: The EXTI line to get the pending flag status for
 * @param[out] value: Pointer to a variable to store the pending flag status
 * @retval Error status
 */
uint8_t EXTI_u8GetPendingFlag(EXTI_Line_t copy_line, uint8_t *value);

#endif