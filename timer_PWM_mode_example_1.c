//Example show how to set timer2 in PWM mode

#include <htc.h>

int main()
{	
	OSCCON = 0b01110001;			//Internal Oscillator, 8MHz
	PORTC = 0;				//PORTC initial value
	TRISC = 0;				//PORTC outputs
	PR2 = 0x65;				//8Mhz, Prescaler = 1, 19,61KHz PWM Frequency
	CCP1CON = 0b00001100;			//PWM MODE ON
	T2CON = 0b00000100;			//TIMER2: prescaler 1, TIMER2 ON

	while(1)
	{
		CCPR1L = 32;			//DUTY CYCLE 32<<2 (+2LSB)
	}
}




