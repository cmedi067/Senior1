
#include "basicFuncs.h"

void init_UART(long baud_rate){
    long clock = 32000000;
    ANSELC = 0x00;
    RX1DTPPS = 0x14;
    RC5PPS = 0x0F;
    
    unsigned int spbrgVal = (clock - baud_rate * 16) / (baud_rate * 16);   
    
    SPBRG = spbrgVal;
    
    PEIE =1;
    INTCONbits.GIE =1;
    
    TX1STA = 0b10100110;
    RC1STA = 0b10010000;
    BAUD1CON = 0b00000000;
    
    RC1IE = 1;    
}
void printSerial(char * text_to_send, int string_size){
    int charCounter = 0;
    int j = 0;

    for(int i = 0; i < string_size; i++){   
        while(TX1STAbits.TRMT == 0);
        TX1REG = text_to_send[i];       
    }
}

char readSerial(void){
    while (!RC1IF);
    return RC1REG;    
}

char ADC_init(void){
    //Set RC0 and RC1 as input 
    TRISC = 0b00000011;
    
    //Set RC0 and RC1 as Analog Input
    ANSELC = 0b00000011;
    
    //Select ADC format ///ADC conversion clock (6-4))
    ADCON1 = 0b10100011;
    
    //Turn ADC on 
    ADCON0 = 0b10000001;
            
}

int ADC_read(){
    ADCON0 |= ADC_goDONE;
    
    unsigned char* currChar = __getBits(ADCON0);
    while(currChar[1] == 1){}
    
    return ( (ADRESH<<8) + ADRESL);
    
}


