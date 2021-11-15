#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#ifndef F_CPU 
    #define F_CPU 16000000
#endif

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void){

    DDRB = 0xFF;
    while(1){
        PORTB = 0xFF;
        _delay_ms(1);
        PORTB = 0x00;
        _delay_ms(1);

    }

}