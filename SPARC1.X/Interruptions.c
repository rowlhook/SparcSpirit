#include "Interruptions.h"
#include <pic18f4550.h>
#include "USARTLIBRERIA.h"
#include "pwm.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "GPIO.h"
int emergencySwitch;
void interruptionsInit(){
    RCONbits.IPEN=0;
    INTCONbits.PEIE=1;
    INTCONbits.GIE=1;
    INTCON3bits.INT2F=0;
    //INTCONbits.RBIE=1;
    INTCON2bits.INTEDG2=1;
    INTCON3bits.INT2E=1;
   
    
    
    INTCON3bits.INT2IF=0;
}



void emergencyButton(){
    for(int i=0; i < strlen(emergency); i++){
    USART_Tx(emergency[i]);
    }
    Enable_D= OFF;
    Enable_I= OFF;
    while(EMERGENCYBUTTON==1){
        
    }if(keepgoing==1){
    Enable_D= ON;
    Enable_I= ON;}
    return;

}

