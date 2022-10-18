/*
 * ADC.h
 *
 * Created: 8/20/2022 12:55:27 PM
 *  Author: Mohamed Elsayed
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD_MACROS.h"

void ADC_init(void);

uint16_t ADC_read(void);

#endif /* ADC_H_ */