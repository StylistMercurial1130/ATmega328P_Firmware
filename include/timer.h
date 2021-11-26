/*
 *
 *	Timers , Counters and PWM For the ATmega328P
 *
 *
 */

#ifdef __cplusplus
	extern "C" {
#endif

#ifndef __TIMER_H__
	#define __TIMER_H__ 

#ifndef __ATMega328P__
	#define __ATMega328P__
#endif

#include <avr/io.h>

/*
 *	TODO ! Set COMO0A1 and COM0A0 registers based on input configuration 
 */

typedef enum {
	
	NORMAL = 0b00 , 
	TOGGLE = 0b01 ,
	CLEAR = 0b10 ,
	SET = 0b11 , 

} Compare_Output_Mode

typedef struct TIMER_0 Timer_0;
typedef struct TIMER_1 Timer_1;
typedef struct TIMER_2 Timer_2;


#endif

#define __cplusplus
	}
#endif
