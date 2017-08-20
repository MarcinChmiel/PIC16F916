//Example shows how to configure pins as outputs

#include <htc.h>

int main()
{
	OSCCON |= 1;				//Internal Oscillator, 4MHz
	ANSEL = 0;				//Turn off analog functions on PORTA pins
	CMCON0 |= (1<<2) | (1<<1) | (1<<0);	//Comparators off
	PORTA = 1;				//SET RA1
	TRISA = 0;				//Set PORTA pins as outputs
	while(1)
	{
		
	}
}
