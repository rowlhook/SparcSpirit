#include <xc.h>
#define FLAG0   INTCONbits.INT0IF
#define FLAG1   INTCON3bits.INT1IF
#define FLAG2   INTCON3bits.INT2IF

#define EMERGENCYBUTTON PORTBbits.RB2

char emergency[]="Emergency Button Pressed\n";
char check[]="STILL IN INTERRUPTION\n";
int emergencySwitch;
void interruptionsInit();
void xLimit();
void yLimit();
void emergencyButton();