
#include <timer.h>

/**
 * @brief Set The Compare Match Output Mode for the 0C0A
 * 
 * @param Mode Compare Match Output Mode
 */
void Set_COM0A_COM_Mode(uint8_t Mode){

    if(Mode > 0b11)
        Mode = COM_MODE_NORMAL;
    
    TCCR0A = (Mode << 6) | (TCCR0A & ~(1 << 6));

}

/**
 * @brief Set the Compare Match Output Mode for the 0C0B
 * 
 * @param Mode Compare Match Output Mode
 */
void Set_COM0B_COM_Mode(uint8_t Mode){

    if(Mode > 0b11)
        Mode = COM_MODE_NORMAL;

    uint8_t high = (TCCR0A >> 6) , low = 0xF & TCCR0A , mid = Mode;

    TCCR0A = (high << 6) | (mid << 4) | (low); 

}

/**
 * @brief Set Wave Generation Mod
 * 
 * @param Mode Wave Generation Modes
 */
void Set_WGM_Mode(uint8_t Mode){

    if(Mode > 0b111)
        Mode = WGM_MODE_NORMAL;

    uint8_t WGM_02 = Mode >> 2;
    uint8_t WGM_0_1 = Mode & 0x3;

    TCCR0A = ((TCCR0A & ~(0b11)) | WGM_0_1);
    TCCR0B = (TCCR0A & 0xF0) | (WGM_02 << 3) | (TCCR0B & 0x7);  

}




