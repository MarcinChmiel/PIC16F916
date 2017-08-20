//AN0	-	analog input
//RA1	-	digital output
//ADC 10 bit = 1024
//1024 - Vref
//ADC - Vin
//Vin = ADC * Vref / 1024


//Example shows how to set ADC
//When analog voltage is greater than 2V - set RA1

#include <htc.h>
#include <stdio.h>
#define VREF 5.0

int main()
{
	//Oscillator INIT
	OSCCON |= (1<<0);					//Internal Oscillator
	OSCCON |= (1<<6) | (1<<5) | (1<<4);			//8MHz
	

	//IO INIT
	CMCON0 |= (1<<2) | (1<<1) | (1<<0);			//Comparators off
	ANSEL &= ~(1<<1);					//RA1 Digital output
	TRISA = 0;
	TRISA |= (1<<0);					//RA0 input
	RA1 = 0;
								//RA0 output, bits in TRISA default
								//RA0 AN0, bits in ANSEL default


	//ADC INIT
								//Channel AN0, bits CHS in ADCON0 default
								//Internal Vref default
								//Frequency Fosc/2, bits ADCS in ADCON1 default
	ADCON0 |= (1<<0);					//ADC enable


	float result;
	
	while(1)
	{
		ADCON0 |= (1<<1);				//Start conversion
		while(ADCON0 & (1<<1));
 		result = (float) ADRESH  * VREF / 256;
		if(result >= 2)
		RA1 = 1;
		else
		RA1 = 0;
	}
}
