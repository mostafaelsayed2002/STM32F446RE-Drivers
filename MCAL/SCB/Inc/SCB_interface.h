#include <stdint.h>
#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H

typedef enum
{
    GROUP16_SUB0 = 0x05FA0300,
    GROUP8_SUB2 = 0x05FA0400,
    GROUP4_SUB4 = 0x05FA0500,
    GROUP2_SUB8 = 0x05FA0600,
    GROUP0_SUB16 = 0x05FA0700,
} PriorityGrouping_t;

typedef enum
{
    USAGEFAULT = 0,
    BUSFAULT,
    MEMMANAGE,
    SVCALL = 7,
    PENDSV = 10,
    SYSTICK
} Exceptions_t;

/**
 * @fn     SCB_u8SetPriorityGrouping
 * @brief  Sets the priority grouping for the NVIC
 * @param[in]   priorityGrouping: The priority grouping value
 * @retval Error status
 */
uint8_t SCB_u8SetPriorityGrouping(PriorityGrouping_t priorityGrouping);

/**
 * @fn     SCB_u8SetPriority
 * @brief  Sets the priority of an exception
 * @param[in]   exception: The exception type
 * @param[in]   priority: The priority value
 * @retval Error status
 */
uint8_t SCB_u8SetPriority(Exceptions_t exception, uint8_t priority);

/**
 * @fn     SCB_u8EnableFault
 * @brief  Enables a fault exception
 * @param[in]   exception: The exception type
 * @retval Error status
 */
uint8_t SCB_u8EnableFault(Exceptions_t exception);

#endif