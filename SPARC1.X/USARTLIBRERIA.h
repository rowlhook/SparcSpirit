#define EnableRx RCSTAbits.CREN=1;
#define DisableRx RCSTAbits.CREN=0;

void USART_Init(long BAUD);
void USART_Tx(char data);
char USART_Rx();

