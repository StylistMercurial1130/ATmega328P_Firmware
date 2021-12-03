
#include <gpio.h>

// max no of bits
#define MAX_BITS 7
/**
 * @brief Sets bits to 0
 * 
 */
#define _DECIMATE_BITS(a , b) (a & (~b))

/**
 * @brief Sets bits to 1
 * 
 */
#define _CREATE_BITS(a , b) (((a & b) ^ a) | b)

/**
 * @brief Write pins into the desired register 
 * 
 * @param GPIO_Port GPIO Port used
 * @param GPIO_Pin  Pin used
 * @param PIN_State  state of input
 */
void GPIO_Write(volatile uint8_t * GPIO_Port,uint8_t GPIO_Pin,uint8_t PIN_State){
    
    if(PIN_State == PIN_SET)
        *GPIO_Port = _CREATE_BITS(*GPIO_Port,GPIO_Pin);
    else 
        if(PIN_State == PIN_RESET)
            *GPIO_Port = _DECIMATE_BITS(*GPIO_Port,GPIO_Pin);

}

/**
 * @brief Read pins from the desired register
 * 
 * @param GPIO_Port GPIO Port that is to be read
 * @param GPIO_Pin Pin to reade from
 * @return uint8_t returns pin state 
 */
uint8_t GPIO_Read(volatile uint8_t * GPIO_Port,uint8_t GPIO_Pin){

    uint8_t portVal = *GPIO_Port;
    portVal &= (1 << (MAX_BITS - GPIO_Pin));

    return portVal;

}

/**
 * @brief Sets the DDRx ports for input or output 
 *  
 * @param GPIO_Port DDRx Port we need to set  
 * @param GPIO_Pin  Pins we need to state 
 * @param State  the state of the Pins 
 */
void GPIO_Set_Pins(volatile uint8_t  * GPIO_Port,uint8_t GPIO_Pin,uint8_t State){

    if(State == PIN_INPUT)
        *GPIO_Port &= _DECIMATE_BITS(*GPIO_Port,GPIO_Pin);
    else 
        if(State == PIN_OUPUT)
            *GPIO_Port = _CREATE_BITS(*GPIO_Port,GPIO_Pin);


}
//this is a test piece of code written on vim , more like a comment !




