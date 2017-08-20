//Example show how to set USART
//Receiving and sending back char from/to PC

//Configuration bit FAIL_CLOCK_MINITOR must be enabled
//TXREG - transmiter buffer
//RCREG - receiver buffer
//TXIF = 1 when TXREG is empty
//RCIF = 1 when RCREG is full




#include <htc.h>
#define _XTAL_FREQ 8000000
int main()
{

	//Oscillator Init
	OSCCON |= (1<<0);				//Internal Oscillator
	OSCCON |= (1<<6) | (1<<5) | (1<<4);		//8MHz


	//AUSART Init
	SPBRG = 12;					//BAUD 9600 ( for 8MHz, Low Speed )
	RCSTA |= (1<<7);				//Serial port enable
	TXSTA |= (1<<5);				//Transmiter enable
	RCSTA |= (1<<4);				//Receiver enable


	char c;
	
	while(1)
	{
		
		while(!RCIF);				//Wait for data in RCREG buffer
		c = RCREG;				//Load buffer to c

		while(!TXIF);				//Wait for empty TXREG buffer
		TXREG = c;				//Load c to buffer
		znak = '\0';
		
	}
}
