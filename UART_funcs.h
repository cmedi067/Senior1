#ifndef BASICFUNCS_H
#define BASICFUNCS_H

#include <xc.h>
#include<pic16f15345.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct pinName {
    char bank;
    int pinNum;
};

void init_UART(long);
char readSerial(void);
void printSerial(char * text_to_send, int string_size);
void printIntSerial(int intToSend);

#endif