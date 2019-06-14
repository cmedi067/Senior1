#ifndef BASICFUNCS_H
#define BASICFUNCS_H

#include <xc.h>
#include<pic16f15345.h>

char ADC_goDONE =  (0 << 1);

void init_UART(long);
void printSerial(char *, int);
char readSerial(void);
char ADC_init(void);

#endif