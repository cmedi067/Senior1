
#include "ADC_funcs.h"
#include "UART_funcs.h"

char ADC_init(char* pin){
    char block = pin[0];
    int pinNum = pin[1] - '0';
    char chan ;     
    
    //Clear A/D interrupt flag
    PIR1bits.ADIF = 0;
    
    //Enable A/D interrupt
    PIE1bits.ADIE = 1;
    
    //Enable Global Interrupts and peripheral interrupts
    PEIE = 1;    
    INTCONbits.GIE =1;        
            
 
     switch(block){
        case 'A' : TRISA |= 1 << pinNum;
                   ANSELA |= 1 << pinNum; 
                   chan = pinNum ;                
                   
        case 'B' : TRISB |= 1 << pinNum;
                   ANSELB |= 1 << pinNum;
                   chan = 12 + (pinNum) ;
                   
        case 'C' : TRISC |= 1 << pinNum; 
                   ANSELC |= 1 << pinNum; 
                   chan =  16 + pinNum ;                   
    }
    
    //Select channel 
    ADCON0 |= chan << 2;
    
    //Select ADC format //ADC conversion clock (6-4)) //Select Reference Source (VDD)
    ADCON1 = 0b10100000;
    
    //Turn ADC on 
    ADCON0bits.ADON = 1;   
    __delay_us(100);
    ADCON0bits.GOnDONE = 1;    
}

unsigned int ADC_read(){  
 // ADCON0bits.GOnDONE = 1;
  while(ADCON0bits.GOnDONE == 1);   
  return ( (ADRESH<<8) + ADRESL);    
}