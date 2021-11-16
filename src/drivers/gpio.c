#include <gpio.h>

#define MAX_BITS 7
#define _DECIMATE_BITS(a , b) (a & (~b))
#define _CREATE_BITS(a , b) (((a & b) ^ a) | b)

static volatile uint8_t * GPIO_DDR_Map [] = {&DDRB , &DDRC , &DDRD};
static volatile uint8_t * GPIO_PORT_Map [] = {&PORTB , &PORTC , &PORTD};

void GPIO_Write(uint8_t GPIO_Port,uint8_t GPIO_Pin,uint8_t PIN_State){

    if(PIN_State == PIN_SET)
        *GPIO_DDR_Map[GPIO_Pin] = _CREATE_BITS(*GPIO_DDR_Map[GPIO_Pin],GPIO_Pin);
    else 
        if(PIN_State == PIN_RESET)
            *GPIO_DDR_Map[GPIO_Pin] = _DECIMATE_BITS(*GPIO_DDR_Map[GPIO_Pin],GPIO_Pin);

}

uint8_t GPIO_Read(uint8_t GPIO_Port,uint8_t GPIO_Pin){

    uint8_t portVal = *GPIO_PORT_Map[GPIO_Port];
    portVal &= (1 << (MAX_BITS - GPIO_Pin));
    
    return portVal;

}

void GPIO_Set_Pins(uint8_t GPIO_Port,uint8_t GPIO_Pin,uint8_t State){

    if(State == PIN_INPUT)
        *GPIO_DDR_Map[GPIO_Port] &= _DECIMATE_BITS(*GPIO_DDR_Map[GPIO_Port],GPIO_Pin);
    else 
        if(State == PIN_OUPUT)
            *GPIO_DDR_Map[GPIO_Port] = _CREATE_BITS(*GPIO_DDR_Map[GPIO_Port],GPIO_Pin);

}
