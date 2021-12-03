/*
 *
 *	Timers , Counters and PWM For the ATmega328P
 *
 *
 */

#ifndef __TIMER_H__
#define __TIMER_H__ 

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __AVR_ATmega328P__
	#define __AVR_ATmega328P__
#endif

#include <avr/io.h>

/*
 *  COM (Compare Output Modes)
 */
#define COM_MODE_NORMAL	0b00
#define COM_MODE_TOGGLE	0b01
#define COM_MODE_CLEAR	0b10
#define COM_MODE_SET	0b11

/*
 *	WGM (Wave Generation Modes)
 */
#define WGM_MODE_NORMAL 				0b000
#define WGM_MODE_PWM_PHASE_CORRECT 		0b001
#define WGM_MODE_PWM_CTC 				0b010
#define WGM_MODE_FAST_PWM 				0b011
#define WGM_MODE_RESERVED 				0b100
#define WGM_MODE_PWM_PHASE_CORRECT_OCR 	0b101
#define WGM_MODE_RESERVED_ 				WGM_MODE_RESERVED
#define WGM_MODE_FAST_PWM_OCR 			0b111

void Set_COM0A_COM_Mode(uint8_t Mode);
void Set_COM0B_COM_Mode(uint8_t Mode);
void Set_WGM_Mode(uint8_t Mode);


#ifdef __cplusplus
}
#endif

#endif

