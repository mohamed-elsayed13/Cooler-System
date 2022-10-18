/*
 * Cooler_System.c
 *
 * Created: 9/2/2022 12:49:47 PM
 * Author : Mohamed ELsayed
 */ 

#include "ADC.h"
#include "LCD.h"
#include "Timer2.h"
#include "TIMER1.h"
#include "SEVEN_SEG.h"
#define ADC100 206 // ADC100 is the ADC register value that opposite 100c on temperature sensor
#define ADC_Min 35 // Minimum reading from sensor to Run the motor
#define ADC_Max 50 // Maximum reading from sensor to Run the motor
#define Range_ratio 3 // 50/15 --> 50 degree for 15 different reading (50-35) 
#define Value 15 // First starting speed % - Minimum sensor reading (50-35)
uint16_t adc_value;
void OVF_ISR (void);
int main(void)
{
    SETBIT(DDRC,0); // LED
	SETBIT(DDRC,1);	// Buzzer
	ADC_init();
	LCD_init();
	Timer2_OVR_ISR=OVF_ISR;
	Timer2_normal_init();
	SEVEN_SEG_init();
	TIMER1_PWM_oc1A_init();
	uint8_t Motor_speed=0;
	while (1) 
    {
		adc_value=ADC_read();
		adc_value=100*adc_value/ADC100;
		if(adc_value>=ADC_Min &&  adc_value<=ADC_Max){
		Motor_speed=adc_value+Value+Range_ratio*(adc_value-ADC_Min);
		if(Motor_speed>100)Motor_speed=100;
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
/*interrupt every 100msec to update seven_segment*/
void OVF_ISR (void){
	static uint8_t count=0;
	count++;
	if(count==7){
	SEVEN_SEG_write(adc_value);	
	count=0;
	}
}
