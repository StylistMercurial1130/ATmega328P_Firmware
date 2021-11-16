#ifndef __AVR_ATmega328P__
    #define __AVR_ATmega328P__
#endif

#ifndef F_CPU 
    #define F_CPU 16000000
#endif

#include <gpio.h>
#include <util/delay.h>

int main(void){

    GPIO_Set_Pins(GPIO_PORT_B,0xB,PIN_OUPUT);

    while(1){

        GPIO_Write(GPIO_PORT_B,0x1,PIN_SET);
        _delay_ms(1);
        GPIO_Write(GPIO_PORT_B,0x1,PIN_RESET);

    }

}