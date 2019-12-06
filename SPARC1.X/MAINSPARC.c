/*
 * File:   MAINSPARC.c
 * Author: mausa
 *
 * Created on 22 de noviembre de 2019, 10:30 AM
 */

#include <pic18f4550.h>
#include <xc.h>
#include "Comandos.h"
#include "GPIO.h"
#include "CONFIGURACION1.h"
#include "pwm.h"
#include "USARTLIBRERIA.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Interruptions.h"


void __interrupt() INT_isr(void){
__delay_ms(10);

   
    if(FLAG2==1){
       emergencyButton();
      
       FLAG2=0;
   }
FLAG2=0;
for(int i=0; i < strlen(check); i++){
    USART_Tx(check[i]);
    } 
}
void main(void) {
    OSCCON=0x72;
    
    USART_Init(9600);
    INTCON2bits.RBPU=1;
    gpioInit();
   pwm_init();
   interruptionsInit();
   
   DisableRx;
    Enable_D= OFF;
    Enable_I= OFF;
    char instruccion[8];
    LED_R=1;
    LED_V=0;
    LED_A=0;
    Sentido_D=DERECHA;
    Sentido_I=IZQUIERDA;
    Enable_I=ON;
    Enable_D=ON;
    while(SWITCHY==0){}
    Enable_I=OFF;
    Enable_D=OFF;
    xLimit();
    Sentido_D=DERECHA;
    Sentido_I=DERECHA;
    Enable_I=ON;
    Enable_D=ON;
    while(SWITCHX==0){}
    Enable_I=OFF;
    Enable_D=OFF;
    yLimit();
    x=0;
    y=0;
    Completo();
                         
    
    while(1){
        
        
         EnableRx;  
        for(uint8_t contador=0; contador<8; contador++){
            instruccion[contador]=USART_Rx();
        }
        
        
       for(int i=0; i < 8; i++){
    USART_Tx(instruccion[i]);
    } 
          DisableRx;  
        comandos(instruccion);
        
    }
    
    return;
}
    

