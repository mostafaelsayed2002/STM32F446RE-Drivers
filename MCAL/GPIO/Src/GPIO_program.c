/***********************************************************************/
/* @file   GPIO_program.c
 * @author Mostafa Elsayed
 * @brief  The GPIO main source file, includes the implementation of the functions
 * @date   29/6/2024
 */

#include <stdint.h>
#include "STM32F466xx.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "ErrType.h"

static GPIO_RegDef_t *GPIOx[GPIO_PERIPHERAL_NUM] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH};

/***********************************************************************/
/* @fn     GPIO_u8InitPin
 * @brief  Initialize a pin with the given configuration
 * @param[in]  pinConfig: A pointer to the configuration structure
 * @retval Error status
 */

uint8_t GPIO_u8InitPin(const GPIO_PinConfig_t *pinConfig)
{
    uint8_t Local_u8ErrorState = OK;
    if (pinConfig != NULL)
    {
        if (pinConfig->port <= PORTH && pinConfig->pin <= PIN15)
        {
            /*Select GPIO mode: INPUT, OUTPUT, ANALOG, AF*/
            GPIOx[pinConfig->port]->MODER &= ~(MODER_MASK << (pinConfig->pin * MODER_PIN_ACCESS));
            GPIOx[pinConfig->port]->MODER |= (pinConfig->mode << (pinConfig->pin * MODER_PIN_ACCESS));
            /*Select GPIO pull state: PULLUP, PULLDOWN, NOPULL*/
            GPIOx[pinConfig->port]->PUPDR &= ~(PUPDR_MASK << (pinConfig->pin * PUPDR_PIN_ACCESS));
            GPIOx[pinConfig->port]->PUPDR |= (pinConfig->pullType << (pinConfig->pin * PUPDR_PIN_ACCESS));
            /*Select Output type & Output speed in case of OUPUT, AF*/
            if (pinConfig->mode == GENERAL_PURPOSE_OUTPUT || pinConfig->mode == ALTERNATE_FUNCTION)
            {
                /*Select Output type: Pushpull or Open drain*/
                GPIOx[pinConfig->port]->OTYPER &= ~(OTYPER_MASK << pinConfig->pin);
                GPIOx[pinConfig->port]->OTYPER |= (pinConfig->outputType << pinConfig->pin);
                /*Select Output speed: Low, Medium, Fast, High*/
                GPIOx[pinConfig->port]->OSPEEDR &= ~(OSPEEDR_MASK << (pinConfig->pin * OSPEEDR_PIN_ACCESS));
                GPIOx[pinConfig->port]->OSPEEDR |= (pinConfig->outputSpeed << (pinConfig->pin * OSPEEDR_PIN_ACCESS));

                if (pinConfig->mode == ALTERNATE_FUNCTION)
                {
                    /*Select the alternate function*/
                    uint8_t Local_u8AFRIndex = pinConfig->pin / 8;
                    uint8_t Local_u8AFRPin = pinConfig->pin % 8;
                    GPIOx[pinConfig->port]->AFR[Local_u8AFRIndex] &= ~(AFR_MASK << (Local_u8AFRPin * AFR_PIN_ACCESS));
                    GPIOx[pinConfig->port]->AFR[Local_u8AFRIndex] |= (pinConfig->alternateFunction << (Local_u8AFRPin * AFR_PIN_ACCESS));
                }
            }
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}

/***********************************************************************/
/* @fn     GPIO_u8SetPinValue
 * @brief  Set the value of a pin
 * @param[in]   port: The port of the pin
 * @param[in]   pin: The pin number
 * @param[in]   state: The state of the pin
 * @retval Error status
 */

uint8_t GPIO_u8SetPinValue(Port_t port, Pin_t pin, PinState_t state)
{
    uint8_t Local_u8ErrorState = OK;
    if (port <= PORTH && pin <= PIN15)
    {
        if (state == LOW)
        {
            GPIOx[port]->BSRR = (1 << (16 + pin));
        }
        else if (state == HIGH)
        {
            GPIOx[port]->BSRR = (1 << pin);
        }
        else
        {
            Local_u8ErrorState = NOK;
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

/***********************************************************************/
/* @fn     GPIO_u8TogglePinValue
 * @brief  Toggle the value of a pin
 * @param[in]   port: The port of the pin
 * @param[in]   pin: The pin number
 * @retval Error status
 */

uint8_t GPIO_u8TogglePinValue(Port_t port, Pin_t pin)
{
    uint8_t Local_u8ErrorState = OK;
    if (port <= PORTH && pin <= PIN15)
    {
        GPIOx[port]->ODR ^= (1 << pin);
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
    return Local_u8ErrorState;
}

/***********************************************************************/
/* @fn     GPIO_u8ReadPinValue
 * @brief  Read the value of a pin
 * @param[in]   port: The port of the pin
 * @param[in]   pin: The pin number
 * @param[out]  state: The state of the pin
 * @retval Error status
 */

uint8_t GPIO_u8ReadPinValue(Port_t port, Pin_t pin, PinState_t *state)
{

    uint8_t Local_u8ErrorState = OK;
    if (port <= PORTH && pin <= PIN15)
    {
        if (GPIOx[port]->IDR & (1 << pin))
        {
            state = HIGH;
        }
        else
        {
            state = LOW;
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
}
