#include <xc.h>
 
void gpioInit();
#define ON 0
#define OFF 1
#define INPUT 1
#define OUTPUT 0


#define DERECHA 1 

#define IZQUIERDA 0


#define LED_R PORTDbits.RD4
#define LED_V PORTDbits.RD5
#define LED_A PORTDbits.RD6


#define Enable_D PORTDbits.RD2 // MOTOR LADO DERECHO
#define Sentido_D PORTDbits.RD0 //

#define Enable_I PORTDbits.RD3 // MOTOR LADO IZQUIERDO
#define Sentido_I PORTDbits.RD1  //

#define SOLENOID PORTDbits.RD7

#define SWITCHX PORTBbits.RB0
#define SWITCHY PORTBbits.RB1