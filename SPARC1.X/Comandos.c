#include "Comandos.h"
#include <stdlib.h>
#include <string.h>
#include "GPIO.h"
#include <xc.h>
#include "pwm.h"
#include "CONFIGURACION1.h"
/*function prints error message unto UART*/

void invalidCoordinate(){
for(int i=0; i < strlen(CE); i++){
    USART_Tx(CE[i]);
    }
    LED_R=1;
    LED_V=0;
    LED_A=0;
    return;
}
void xLimit(){
    for(int i=0; i < strlen(xl); i++){
    USART_Tx(xl[i]);
    } 
    return;
}

void yLimit(){
    for(int i=0; i < strlen(yl); i++){
    USART_Tx(yl[i]);
    } return;
}

void Error(){
    for(int i=0; i< strlen(msgwrong); i++){ //Prints all letters in a message
    USART_Tx(msgwrong[i]); //Prints Character by character
    } 
    LED_R=1;
    LED_V=0;
    LED_A=0;
}

/*Function Prints execution message unto UART*/
void Ejecutandose(){
    for(int i=0; i < strlen(msgeje); i++){
    USART_Tx(msgeje[i]);
    } 
      LED_R=0;
    LED_V=0;
    LED_A=1;
}

/*Function Types Complete message unto UART*/
void Completo(){
    for(int i=0; i < strlen(msgcomp); i++){
    USART_Tx(msgcomp[i]);
    } 
      LED_R=0;
    LED_V=1;
    LED_A=0;
}

/*Function tells whether Sparc should move Left or Right*/
void coordinateRefreshX(int newX){
    if(newX<x){ //If new value is less than previous
       Sentido_D=DERECHA;
       //Sentido_I=IZQUIERDA;
       //Sentido_D= DERECHA;
       Sentido_I=DERECHA;
       
       for(int i=0; i < strlen(msleft); i++){
    USART_Tx(msleft[i]);
    }
       contador_pulsosD(x-newX);
       //Go left function
    }
    if(newX>x){ //If new  value is larger than previous
       Sentido_D=IZQUIERDA;
       Sentido_I=IZQUIERDA;
       //Sentido_D=IZQUIERDA;
       //Sentido_I=IZQUIERDA;
      
       for(int j=0; j < strlen(msright); j++){
    USART_Tx(msright[j]);
    }
        contador_pulsosD(newX-x);//Go right function
    }
    x=newX;  //New coordinate value is set
}

/*Function tells whether Sparc should move Up or Down*/

void coordinateRefreshY(int newY){
    if(newY<y){ //If new value is less than previous
    Sentido_D=DERECHA;
       Sentido_I=IZQUIERDA;
       
       for(int i=0; i < strlen(msdown); i++){
    USART_Tx(msdown[i]);
    }
    contador_pulsosD(y-newY);   
    }
    if(newY>y){ //If new value is larger thatn previous
        Sentido_D=IZQUIERDA;
        Sentido_I=DERECHA;
      
    for(int j=0; j < strlen(msup); j++){
    USART_Tx(msup[j]);
    }
       
        contador_pulsosD(newY-y); //Go up Function
    }
    y=newY;//New value is set
}

/*Command Recognition function, takes the array gotten from UART and compares it with 
 known commands.*/
int comandos (char comando[7]){ 
    if(comando[0]=='C'){
        if (comando[1]>='0' && comando[1]<='2'){
            if (comando[2]>='0' && comando[2]<='9'){
                if (comando[3]>='0' && comando[3]<='9'){
                    if (comando[4]==','){
                        if (comando[5]>='0' && comando[5]<='2'){
                            if (comando[6]>='0' && comando[6]<='9'){
                                if (comando[7]>='0' && comando[7]<='9'){ /*ex: C024,234 (X=024 Y=234*/
                                    Ejecutandose();//Execution Message
                                    nvalorx= ((comando[1]-48)*100)+((comando[2]-48)*10)+(comando[3]-48);
                                    nvalory= ((comando[5]-48)*100)+((comando[6]-48)*10)+(comando[7]-48);
                                    //New y value Set
                                    coordinateRefreshX(nvalorx); //Function Executed with new value
                                    coordinateRefreshY(nvalory); //Function Executed with new value
                                    Completo();
                                }
                                else{
                                    invalidCoordinate(); //Error message for coordinate
                                }
                            }
                            else{
                                invalidCoordinate();
                            }
                        }
                        else{
                            invalidCoordinate(); 
                        }
                    }
                    else{
                        invalidCoordinate();
                    }
                }
                else{
                    invalidCoordinate();
                }
            }
            else{
                invalidCoordinate();
            }
        } 
        else{
            invalidCoordinate();
        }
    }
    
    else if(comando[0]=='G'){
        if (comando[1]=='O'){
            if (comando[2]=='T'){
                if (comando[3]=='O'){
                    if (comando[4]=='H'){
                        if (comando[5]=='O'){
                            if (comando[6]=='M'){
                                if (comando[7]=='E'){ /*ex GOTOHOME*/
                                    Ejecutandose();//Execution Message
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
                                }
                                else{
                                    Error(); //Error Message
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    }
    
    else if(comando[0]=='S'){
        if (comando[1]=='T'){
            if (comando[2]=='C'){
                if (comando[3]=='T'){
                    if (comando[4]=='O'){
                        if (comando[5]=='U'){
                            if (comando[6]=='C'){
                                if (comando[7]=='H'){ /*ex STCTOUCH*/
                                    Ejecutandose(); //Execution Message
                                    SOLENOID=1;
                                    Completo();
                                }
                                else{
                                    Error();
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    }
    
    
    
    else if(comando[0]=='M'){
        if (comando[1]=='A'){
            if (comando[2]=='K'){
                if (comando[3]=='E'){
                    if (comando[4]=='A'){
                        if (comando[5]=='T'){
                            if (comando[6]=='A'){
                                if (comando[7]=='P'){ /*ex MAKEATAP*/
                                    Ejecutandose();
                                    SOLENOID=1;
                                    __delay_ms(1000);
                                    SOLENOID=0;
                                    Completo();
                                }
                                
                                else{
                                    Error();
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    }
       
   
    else if(comando[0]=='T'){
        if (comando[1]=='A'){
            if (comando[2]=='K'){
                if (comando[3]=='E'){
                    if (comando[4]=='L'){
                        if (comando[5]=='I'){
                            if (comando[6]=='F'){
                                if (comando[7]=='T'){ /*ex TAKELIFT*/
                                    Ejecutandose(); //Execution Message
                                    SOLENOID=0;
                                    Completo();
                                }
                                else{
                                    Error();
                                }
                            }
                            else{
                                Error();
                            }
                        }
                        else{
                            Error();  
                        }
                    }
                    else{
                        Error();
                    }
                }
                else{
                    Error();
                }
            }
            else{
                Error();
            }
        } 
        else{
            Error();
        }
    }
    else{Error();}
    
}

