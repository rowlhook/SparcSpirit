#include <xc.h>
#include "CONFIGURACION1.h"
#include "USARTLIBRERIA.h"


void USART_Init(long BAUD){
    //Configuracion de pines
    TRISCbits.RC6=0; //RC6= Tx
    TRISCbits.RC7=1; //RC7= Rx
  
    SPBRG = (unsigned char)((_XTAL_FREQ/BAUD)/64)-1;
    TXSTAbits.BRGH = 0; //Low speed
    TXSTAbits.SYNC = 0; //Asincrono
    RCSTAbits.SPEN = 1; //Habilitar Tx y Rx
    
    //Transmisión
    TXSTAbits.TX9 = 0; //8 bits 
    TXSTAbits.TXEN = 1; //Activar transmisión
    
    //Recepción
    RCSTAbits.RC9 = 0; //8 bits
   RCSTAbits.CREN = 1; //Activamos recepción  
   
   
}

void USART_Tx(char data){
    while(!PIR1bits.TXIF);
    TXREG= data;  
}

char USART_Rx(){
    while(!RCIF);
    return RCREG; 
}