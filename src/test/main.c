#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#ifndef F_CPU 
    #define F_CPU 16000000
#endif

#include <gpio.h>
#include <util/delay.h>

void main(void){

    GPIO_Set_Pins((uint8_t *)&DDRB,0x2,PIN_OUPUT);
    while(1){
        GPIO_Write((uint8_t *)&PORTB,0x2,PIN_SET);
        _delay_ms(2);
        GPIO_Write((uint8_t *)&PORTB,0x2,PIN_RESET);
        _delay_ms(2);
    }
    
}




