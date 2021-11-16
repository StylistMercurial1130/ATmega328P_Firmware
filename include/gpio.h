#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#include <avr/io.h>

#define PIN_SET 1
#define PIN_RESET 0

#define PIN_OUPUT 1
#define PIN_INPUT 0

#define GPIO_PORT_B 0b001
#define GPIO_PORT_C 0b010
#define GPIO_PORT_D 0b011

void GPIO_Write(uint8_t GPIO_Port,uint8_t GPIO_Pin,uint8_t PIN_State);
uint8_t GPIO_Read(uint8_t GPIO_Port,uint8_t GPIO_Pin);
void GPIO_Set_Pins(uint8_t GPIO_Port,uint8_t GPIO_Pin,uint8_t State);

#ifdef __cplusplus
}
#endif

#endif