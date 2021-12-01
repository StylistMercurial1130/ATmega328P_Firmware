
#include <timer.h>

void Set_COM0A_COM_Mode(uint8_t Mode){

    if(Mode > 0b11)
        Mode = COM_MODE_NORMAL;
    TCCR0A &= ((Mode << 6) | 0x1FF);

}

void Set_COM0B_COM_Modes(uint8_t Mode){

    if(Mode > 0b11)
        Mode = COM_MODE_NORMAL;
    TCCR0A &= ((Mode << 4) | 0xF);
}





