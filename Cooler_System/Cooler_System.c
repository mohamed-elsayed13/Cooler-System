/*
 * Cooler_System.c
 *
 * Created: 9/2/2022 12:49:47 PM
 * Author : Mohamed ELsayed
 */ 

#include "ADC.h"
#include "LCD.h"
#include "TIMER0.h"
#include "TIMER1.h"
#include "SEVEN_SEG.h"
#define ADC100 206 // 206 the ADC register value that opposite 100c on temperature sensor
uint16_t adc_value;
void OVF_ISR (void);
int main(void)
{
    SETBIT(DDRC,0); // LED
	SETBIT(DDRC,1);	// Buzzer
	ADC_init();
	LCD_init();
	timer0_ovf_isr=OVF_ISR;
	TIMER0_normaMode_init();
	SEVEN_SEG_init();
	TIMER1_PWM_oc1A_init();
	uint8_t Motor_speed=0;
	while (1) 
    {
		adc_value=ADC_read();
		adc_value=100*adc_value/ADC100;
		if(adc_value>=35 &&  adc_value<=50){
		Motor_speed=100*adc_value/50.0;
		TIMER1_PWM_oc1A_duty(Motor_speed);
		SETBIT(PORTC,0);
		SETBIT(PORTC,1);
		}
		else{
		Motor_speed=0;	
		TIMER1_PWM_oc1A_duty(Motor_speed);	
		CLRBIT(PORTC,0);
		CLRBIT(PORTC,1);
		}	
				
		LCD_write_command(0x1);
		LCD_write_string("Temp.: ");
		LCD_write_num(adc_value);
		LCD_write_string(" c");
		LCD_write_command(0xc0);
		LCD_write_string("M.speed: ");
		LCD_write_num(Motor_speed);
		LCD_write_string("%");		
		
		_delay_ms(200);
    }
}
// interrupt every 100msec to update seven_segment
void OVF_ISR (void){
	static uint8_t count=0;
	count++;
	if (count==7){
	SEVEN_SEG_write(adc_value);	
	count=0;
	}
}
