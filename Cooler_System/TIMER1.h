/*
 * TIMER1.h
 *
 * Created: 8/20/2022 11:25:36 AM
 *  Author: Mohamed Elsayed
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "std_macros.h"

void TIMER1_PWM_oc1A_init(void);
void TIMER1_PWM_oc1A_duty(uint8_t duty );
void TIMER1_PWM_oc1B_init(void);
void TIMER1_PWM_oc1B_duty(uint8_t duty );


#endif /* TIMER1_H_ */