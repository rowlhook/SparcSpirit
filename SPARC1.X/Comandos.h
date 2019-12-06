#include <stdint.h>
#include <xc.h>
#include "USARTLIBRERIA.h"
#include <string.h>
int comandos(char comando[7]); //Declaración de función 
char msgwrong []=" Error 0: Invalid Command\n";
char msgeje []="Command in Execution\n";
char msgcomp []="Successfully Executed\n";
char msleft[]="Going Left ";
char msup[]="Going Up\n ";
char msdown[]="Going Down\n ";
char msright[]="Going Right ";
char xl[]="Limit x Reached\n";
char yl[]="Limit y Reached\n";
char CE[]=" Error 1: Invalid Coordinate\n";
void invalidCoordinate(void);
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