/*
 *
 *	Timers , Counters and PWM For the ATmega328P
 *
 *
 */

#ifndef __TIMER_H__
#define __TIMER_H__ 

#ifndef __AVR_ATmega328P__
	#define __AVR_ATmega328P__
#endif

#include <avr/io.h>

#define COM_MODE_NORMAL 0b00
#define COM_MODE_TOGGLE 0b01
#define COM_MODE_CLEAR 0b10
#define COM_MODE_SET 0b11

void Set_COM0A_COM_Mode(uint8_t Mode);
void Set_COM0B_COM_Modes(uint8_t Mode);


#endif

