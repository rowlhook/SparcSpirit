#include "pwm.h"
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "GPIO.h"
#include "Interruptions.h"

unsigned char ons=0;
int cnt=0; 
int keepgoing;

//PWM period=[(PR2)+1]*4*TOSC*TMR2
//1/250 Hz= (PR2+1)*4*(1/4MHz)*16
//PR2= 249

//PWM Duty Cycle =(CCPRxL:CCPxCON<5:4>)*TOSC*(TMR2)
//CCPRL=DC/TOSC*TMR2
//CPRL= (1/250 Hz)/(1/4Mhz)*16 = 1000

//1000 -> 100%
//500 -> 50% 

void pwm_init(void) {
    /*Assign PWM values of 4ms and 50% DC*/
    PR2 = 249; //PWM Period
    CCPR1L= (500>>2 & (0x3FF)); //6 bit PWM
    CCPR2L= (500>>2 & (0x3FF));
    TRISCbits.RC1=0;
    TRISCbits.RC2=0;       
    T2CON = 0x03; //Prescaler 16 Timer 2 OFF
    CCP1CON = 0x0C; //Control (2LSB PWM and Mode PWM)
    CCP2CON=0x0C;
    TMR2=0; //Begins at 0
    T2CONbits.TMR2ON =1; //Timer 2 on
}

/*One shot for counting PWM rises*/
void contador_pulsosD(int pulsoD){
    ons=0;
    cnt=0;
   
    Enable_D= ON;
    Enable_I=ON;
    keepgoing=1;
    while(cnt<pulsoD*5){
        
        if (PORTCbits.CCP1==1){ //If register is 1
            oneShot(); }//Check if ons is on
            if(ons==1){ clearOneShot();}
        
        
        
    }
    Enable_D= OFF;
    Enable_I= OFF;
    keepgoing=0;
}
void oneShot(){
    if(ons==1){return;}
    cnt++;
    ons=1;
    return;
    
}
void clearOneShot(){
    if(PORTCbits.CCP1==0){ons=0;}
    return;
}
