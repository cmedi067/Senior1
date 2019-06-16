#ifndef BASICFUNCS_H
#define BASICFUNCS_H

#include <xc.h>
#include<pic16f15345.h>
#include <stdio.h>
#include <stdlib.h>

void init_UART(long);
char readSerial(void);

#endif