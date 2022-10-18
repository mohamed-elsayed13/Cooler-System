/*
 * SEVEN_SEG.c
 *
 * Created: 8/15/2022 10:55:37 PM
 *  Author: Mohamed Elsayed
 */ 
#include "SEVEN_SEG.h"
/*****************************************************************************
* Function Name: SEVEN_SEG_init
* Purpose      : PortA Pins from 2 to 7 are output
* Parameters   : void
* Return value : void
*****************************************************************************/
void SEVEN_SEG_init(void){
	INIT_SEVENSEG_PINS
}
/*****************************************************************************
* Function Name: SEVEN_SEG_write
* Purpose      : Turn on LEDs of Seven segment to complete given digit (0-->9)
* Parameters   : uint8_t num (0 to 99)
* Return value : void
*****************************************************************************/
void SEVEN_SEG_write(uint8_t num){
	uint8_t x=num%10;
	EN1(1)
	EN2(0)
	switch (x)
	{
	case 0 :
	A7(0) A6(1) A5(1) A4(1) A3(1) A2(1) A1(1) 
	break;
	case 1 :
	A7(0) A6(1) A5(1) A4(0) A3(0) A2(0) A1(0)
	break;
	case 2 :
	A7(1) A6(0) A5(1) A4(1) A3(0) A2(1) A1(1)
	break;
	case 3 :
	A7(1) A6(0) A5(0) A4(1) A3(1) A2(1) A1(1)
	break;
	case 4 :
	A7(1) A6(1) A5(0) A4(0) A3(1) A2(1) A1(0)
	break;
	case 5 :
	A7(1) A6(1) A5(0) A4(1) A3(1) A2(0) A1(1)
	break;
	case 6 :
	A7(1) A6(1) A5(1) A4(1) A3(1) A2(0) A1(1)
	break;
	case 7 :
	A7(0) A6(0) A5(0) A4(0) A3(1) A2(1) A1(1)
	break;
	case 8 :
	A7(1) A6(1) A5(1) A4(1) A3(1) A2(1) A1(1)
	break;
	case 9 :
	A7(1) A6(1) A5(0) A4(1) A3(1) A2(1) A1(1)
	break;
	}
	_delay_ms(10);
	x=num/10;
	EN1(0)
	EN2(1)
	switch (x)
	{
		case 0 :
		A7(0) A6(1) A5(1) A4(1) A3(1) A2(1) A1(1)
		break;
		case 1 :
		A7(0) A6(1) A5(1) A4(0) A3(0) A2(0) A1(0)
		break;
		case 2 :
		A7(1) A6(0) A5(1) A4(1) A3(0) A2(1) A1(1)
		break;
		case 3 :
		A7(1) A6(0) A5(0) A4(1) A3(1) A2(1) A1(1)
		break;
		case 4 :
		A7(1) A6(1) A5(0) A4(0) A3(1) A2(1) A1(0)
		break;
		case 5 :
		A7(1) A6(1) A5(0) A4(1) A3(1) A2(0) A1(1)
		break;
		case 6 :
		A7(1) A6(1) A5(1) A4(1) A3(1) A2(0) A1(1)
		break;
		case 7 :
		A7(0) A6(0) A5(0) A4(0) A3(1) A2(1) A1(1)
		break;
		case 8 :
		A7(1) A6(1) A5(1) A4(1) A3(1) A2(1) A1(1)
		break;
		case 9 :
		A7(1) A6(1) A5(0) A4(1) A3(1) A2(1) A1(1)
		break;
	}
	_delay_ms(10);
}