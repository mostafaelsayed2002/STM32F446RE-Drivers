#include <cstdint>
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

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
} Port_t;

typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
} Pin_t;

typedef enum
{
    INPUT = 0,
    GENERAL_PURPOSE_OUTPUT,
    ALTERNATE_FUNCTION,
    ANALOG
} Mode_t;

typedef enum
{
    PUSH_PULL = 0,
    OPEN_DRAIN
} OutputType_t;

typedef enum
{
    LOW_SPEED = 0,
    MEDIUM_SPEED,
    FAST_SPEED,
    HIGH_SPEED
} OutputSpeed_t;

typedef enum
{
    NO_PULL = 0,
    PULL_UP,
    PULL_DOWN
} PullUpDown_t;

typedef enum
{
    LOW = 0,
    HIGH
} PinState_t;

typedef enum
{
    AF0 = 0,
    AF1,
    AF2,
    AF3,
    AF4,
    AF5,
    AF6,
    AF7,
    AF8,
    AF9,
    AF10,
    AF11,
    AF12,
    AF13,
    AF14,
    AF15
} AlternateFunction_t;

typedef struct
{
    Port_t port;
    Pin_t pin;
    Mode_t mode;
    OutputType_t outputType;
    OutputSpeed_t outputSpeed;
    PullUpDown_t pullType;
    AlternateFunction_t alternateFunction;
} PinConfig_t;

uint8_t GPIO_u8InitPin(const PinConfig_t *pinConfig);

uint8_t GPIO_u8SetPinValue(Port_t port, Pin_t pin, PinState_t state);

uint8_t GPIO_u8TogglePinValue(Port_t port, Pin_t pin);

uint8_t GPIO_u8ReadPinValue(Port_t port, Pin_t pin, PinState_t *state);

#endif