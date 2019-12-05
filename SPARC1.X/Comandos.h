#include <stdint.h>
#include <xc.h>
#include "USARTLIBRERIA.h"
#include <string.h>
int comandos(char comando[7]); //Declaración de función 
char msgwrong []="COMANDO INCORRECTO\n";
char msgeje []="COMANDO EJECUTANDOSE\n";
char msgcomp []="COMANDO EJECUTADO\n";
char msleft[]="HACIA LA IZQUIERDA ";
char msup[]="HACIA ARRIBA ";
char msdown[]="HACIA ABAJO ";
char msright[]="HACIA LA DERECHA ";
char xl[]="Limit x Reached\n";
char yl[]="Limit y Reached\n";
void Error(void); //Declaración de función
void Ejecutandose(void); //Declaración de función
void Completo(void); //Declaración de funcion
char reconocer_comando(void); //declaración de función
uint16_t nvalorx =0; //declaración de nuevo valor
uint16_t nvalory =0; //declaración de nuevo valor

void coordinateRefreshY (int newY);
void coordinateRefreshX (int newX);
uint16_t x=0;
uint16_t y=0;