#include <xc.h>
#include "CONFIGURACION1.h"
#include "USARTLIBRERIA.h"


void USART_Init(long BAUD){
    //Configuracion de pines
    TRISCbits.RC6=0; //RC6= Tx
    TRISCbits.RC7=1; //RC7= Rx
  
    SPBRG = (unsigned char)((_XTAL_FREQ/BAUD)/64)-1;
    TXSTAbits.BRGH = 0; //Low speed
    TXSTAbits.SYNC = 0; //Asincronous
    RCSTAbits.SPEN = 1; //Enable Tx y Rx
    
    //Transmition
    TXSTAbits.TX9 = 0; //8 bits 
    TXSTAbits.TXEN = 1; //Enable transmition
    
    //Reception
    RCSTAbits.RC9 = 0; //8 bits
   RCSTAbits.CREN = 1; //Enable reception  
   
   
}

void USART_Tx(char data){
    while(!PIR1bits.TXIF);
    TXREG= data;  
}

char USART_Rx(){
    while(!RCIF);
    return RCREG; 
}