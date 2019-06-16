
#include "UART_funcs.h"


void init_UART(long baud_rate){
    long clock = 32000000;
    ANSELC = 0x00;
    
    //Select Pins
    RX1DTPPS = 0x14;
    RC5PPS = 0x0F;
    
    //Set Baud Rate
    unsigned int spbrgVal = (clock - baud_rate * 16) / (baud_rate * 16);      
    SPBRG = spbrgVal;
    
    //Enable Global Interrupts and peripheral interrupts
    PEIE = 1;
    INTCONbits.GIE =1;
    
    //TX config
    TX1STA = 0b10100110;
    RC1STA = 0b10010000;
    BAUD1CON = 0b00000000;
    
    RC1IE = 1;    
}


//Function used to redirect printf to UART 1
void putch(unsigned char byte)
{
    TXSTA=0x26;
    RCSTAbits.SPEN=1;
    TXREG=byte;
    while(TX1STAbits.TRMT == 0)continue;
    TX1STAbits.TRMT = 0;
}


char readSerial(void){
   
    return RC1REG;    
}




