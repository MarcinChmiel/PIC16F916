//Example show how to set USART
//Send char every 250ms via USART to PC

//Configuration bit FAIL_CLOCK_MONITOR must be enabled

#include <htc.h>
#define _XTAL_FREQ 8000000UL

int main()
{
	//OSCILLATOR INITALISATION
	OSCCON |= (1<<0);				//Internal Oscillator
	OSCCON |= (1<<6) | (1<<5) | (1<<4);		//8MHz



	//USART ASYNCHRONOUS MODE INITIALISATION
	SPBRG = 12;					//8MHz, Baud Rate 9600
	TXSTA |= (1<<5);				//Transmit enabled
	RCSTA |= (1<<7);				//Serial port enabled

	char c = 'a';	

	while(1)
	{
		__delay_ms(250);
		while(!TXIF);				//TXIF = 1 => TXREG is empty
		TXREG = c;				//TXREG transmit buffer
	}
}
