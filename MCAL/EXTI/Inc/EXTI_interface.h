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
} EnabeState_t;

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
    EXTI15,
    EXTI16,
    EXTI17,
    EXTI18,
    EXTI19,
    EXTI20,
    EXTI21,
    EXTI22,
} EXTI_Line_t;

typedef struct
{
    TriggerEvent_t TriggerEvent;
    EnabeState_t EnableState;
    EXTI_Line_t EXTI_Line;
    void (*Callback)(void);
} EXTI_Config_t;

void EXTI_voidInit(EXTI_Config_t *EXTI_Config);
void EXTI_voidEnableEXTI(EXTI_Line_t EXTI_Line);
void EXTI_voidDisabeEXTI(EXTI_Line_t EXTI_Line);
void EXTI_voidClearPendingFlag(EXTI_Line_t EXTI_Line);
uint8_t EXTI_u8GetPendingFlag(EXTI_Line_t EXTI_Line);

#endif