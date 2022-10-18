/*
 * LCD.h
 *
 * Created: 8/12/2022 5:07:04 PM
 *  Author: Mohamed Elsayed
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "STD_MACROS.h"
#define INIT_LCD_PINS DDRB |= 0b11111100
#define RS(x) if(x==1){SETBIT(PORTB,2);} else{CLRBIT(PORTB,2);}
#define EN(x) if(x==1){SETBIT(PORTB,3);} else{CLRBIT(PORTB,3);}
#define D7(x) if(x==1){SETBIT(PORTB,7);} else{CLRBIT(PORTB,7);}
#define D6(x) if(x==1){SETBIT(PORTB,6);} else{CLRBIT(PORTB,6);}
#define D5(x) if(x==1){SETBIT(PORTB,5);} else{CLRBIT(PORTB,5);}
#define D4(x) if(x==1){SETBIT(PORTB,4);} else{CLRBIT(PORTB,4);}
						 
void LCD_init(void);
void LCD_write_command(uint8_t);
void LCD_write_char(uint8_t);
void LCD_write_string(uint8_t*);
void LCD_write_num(uint32_t);




#endif /* LCD_H_ */
