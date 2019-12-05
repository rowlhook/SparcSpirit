#include "GPIO.h"
void gpioInit(){
    CMCON=0x07;
    PORTD=0x00;
    LATD=0x00;
    TRISD=0x00;
    PORTC=0x00;
    LATC=0x00;
    PORTB=0x00;
    LATB=0x00;
    TRISB=0xFF;
    Enable_I=1;
    Enable_D=1;


}




