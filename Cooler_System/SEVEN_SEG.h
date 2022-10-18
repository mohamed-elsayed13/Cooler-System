/*
 * SEVEN_SEG.h
 *
 * Created: 8/15/2022 10:56:12 PM
 *  Author: Mohamed Elsayed
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_
#include "STD_MACROS.h"
#define INIT_SEVENSEG_PINS DDRA |= 0b11111110; DDRC|=0b11000000;
#define EN1(x) if(x==1) SETBIT(PORTC,6); else CLRBIT(PORTC,6);
#define EN2(x) if(x==1) SETBIT(PORTC,7); else CLRBIT(PORTC,7);
#define A7(x)  if(x==1) SETBIT(PORTA,7); else CLRBIT(PORTA,7);
#define A6(x)  if(x==1) SETBIT(PORTA,6); else CLRBIT(PORTA,6);
#define A5(x)  if(x==1) SETBIT(PORTA,5); else CLRBIT(PORTA,5);
#define A4(x)  if(x==1) SETBIT(PORTA,4); else CLRBIT(PORTA,4);
#define A3(x)  if(x==1) SETBIT(PORTA,3); else CLRBIT(PORTA,3);
#define A2(x)  if(x==1) SETBIT(PORTA,2); else CLRBIT(PORTA,2);
#define A1(x)  if(x==1) SETBIT(PORTA,1); else CLRBIT(PORTA,1);
void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t num);





#endif /* SEVEN_SEG_H_ */