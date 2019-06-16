/* 
 * File:   ADC_funcs.h
 * Author: cmedina
 *
 * Created on June 15, 2019, 8:25 PM
 */

#ifndef ADC_FUNCS_H
#define	ADC_FUNCS_H

#include <xc.h>
#include<pic16f15345.h>
#include <stdio.h>
#include <stdlib.h>

#define _XTAL_FREQ 32000000


char ADC_init(char*);
unsigned int ADC_read();


#endif	/* ADC_FUNCS_H */

