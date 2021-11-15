#include <gpio.h>

#define MAX_BITS 7

static volatile uint8_t * GPIO_DDR_Map [] = {&DDRB , &DDRC , &DDRD};
static volatile uint8_t * GPIO_PORT_Map [] = {&PORTB , &PORTC , &PORTD};

void GPIO_Write(uint8_t GPIO_Port,uint8_t GPIO_Pin,uint8_t PIN_State){

    if(PIN_State == PIN_SET){
        *GPIO_DDR_Map[GPIO_Port] &= ~(1 << GPIO_Pin);
        *GPIO_PORT_Map[GPIO_Port] |= (1 << GPIO_Pin);
    }
    else if(PIN_State == PIN_RESET){
        *GPIO_DDR_Map[GPIO_Port] &= ~(1 << GPIO_Pin);
        *GPIO_PORT_Map[GPIO_Port] &= ~(1 << GPIO_Pin);
    }
                
}

uint8_t GPIO_Read(uint8_t GPIO_Port,uint8_t GPIO_Pin){

    *GPIO_DDR_Map[GPIO_Port] |= (1 << GPIO_Pin);
    uint8_t portVal = *GPIO_PORT_Map[GPIO_Port];
    return (portVal << (MAX_BITS - GPIO_Pin));

}
