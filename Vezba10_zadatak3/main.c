#include "../usart/usart.h"
#include "../timer0/timer0.h"
#include "../pin_driver/pin.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// makroi
#define ITERATIVE 1
#define FORMULA 2


int main()
{
	usartInit(9600);
	pinInit(PORT_B, 5, OUTPUT);
	timer0InteruptInit();

	// promenljive
	int16_t first_element;
	int16_t n;
	int16_t ratio;
	int8_t mode;
	int8_t order;
	int8_t coeff;
	int8_t x;
	int8_t number;

	char c;

	char tmp[64];

	typedef enum state_t{
		INIT,
		FE1,
		FE2,
		ORDER,
		NUM,
		RATIO1,
		RATIO2,
		COEF,
		AL1,
		N1,
		N2,
		X,
		MODE1,
		MODE2,
		I1,
		F1,
		I2,
		F2
	}state_t;

	state_t state = INIT;

	while(1)
	{
		while(!usartAvailabele());

		c = usartGetChar();

		switch(state)
		{
		case INIT:
			while(usartAvailable() == 0);
			c = usartGetChar();

			sprintf(tmp, "STANJE INIT\r\n");
			usartPutString(tmp);

			switch(c)
			{
			case 'a':
				while(usartAvailable() == 0);
				c = usartGetChar();

				timer0DelayMs(1000);
				sprintf(tmp, "STANJE INIT-> FE1\r\n");
				usartPutString(tmp);

				state = FE1;
				break;
			case 'b':
				while(usartAvailable() == 0);
				c = usartGetChar();

				timer0DelayMs(1000);
				sprintf(tmp, "STANJE INIT-> FE2\r\n");
				usartPutString(tmp);

				state = FE2;
				break;
			case 'c':
				while(usartAvailable() == 0);
				c = usartGetChar();

				timer0DelayMs(1000);
				sprintf(tmp, "STANJE INIT-> ORDER\r\n");
				usartPutString(tmp);

				state = ORDER;
				break;
			case 'd':
				while(usartAvailable() == 0);
				c = usartGetChar();

				timer0DelayMs(1000);
				sprintf(tmp, "STANJE INIT-> NUM\r\n");
				usartPutString(tmp);

				state = NUM;
				break;
			}
			break;
			case FE1:
				if(c == 'e')
				{
					while(usartAvailable() == 0);
					c = usartGetChar();

					timer0DelayMs(100);
					sprintf(tmp,"STANJE FE1\r\n");
					usartPutString(tmp);

					pinSetValue(PORT_B, 5, HIGH);
					sprintf(first_element," %d\r\n ");
					usartPutString(first_element);

					sprintf(tmp,"FE1 -> RATIO1 \r\n");
					usartPutString(tmp);

					state = RATIO1;
				}
				break;
			case FE2:
				if(c == 'f')
				{
					while(usartAvailable() == 0);
					c = usartGetChar();
					timer0DelayMs(100);
					sprintf(tmp,"STANJE FE2\r\n");
					usartPutString(tmp);

					pinSetValue(PORT_B, 5, HIGH);
					sprintf(first_element,"%d\r\n");
					usartPutString(first_element);

					sprintf(tmp, "FE2 -> RATIO2\r\n");
					usartPutString(tmp);

					state = RATIO2;
				}
				break;
			case ORDER:
				if(c == 'g')
				{
					while(usartAvailable() == 0);
					c = usartGetChar();
					timer0DelayMs(100);
					sprintf(tmp,"STANJE ORDER\r\n");
					usartPutString(tmp);

					pinSetValue(PORT_B, 5, HIGH);
					sprintf(order,"%d\r\n");
					usartPutString(order);

					sprintf(tmp, "ORDER -> COEF\r\n");
					usartPutString(tmp);

					state = COEF;
				}
				break;
			case NUM:
				if(c == 'h')
				{
					while(usartAvailable() == 0);
					c = usartGetChar();
					timer0DelayMs(100);
					sprintf(tmp,"STANJE NUM\r\n");
					usartPutString(tmp);

					pinSetValue(PORT_B, 5, HIGH);
					sprintf(number,"%d\r\n");
					usartPutString(number);

					sprintf(tmp, "NUM -> AL1\r\n");
					usartPutString(tmp);

					state = AL1;
				}
				break;
			case RATIO1:
				if(c == 'i')
				{
					while(usartAvailable() == 0);
					c = usartGetChar();
					timer0DelayMs(100);
					sprintf(tmp, "STANJE RATIO1\r\n");
					usartPutString(tmp);

					sprintf(ratio, "%d\r\n");
					usartPutString(ratio);

					for( int i = 0; i < ratio; i++)
					{
						pinSetValue(PORT_B, 5, HIGH);
						timer0DelayMs(1000);
						pinSetValue(PORT_B, 5, LOW);

						if(i !=ratio-1)
							timer0DelayMs(1000);
					}
					sprintf(tmp, "RATIO1 -> N1\r\n");
					usartPutString(tmp);

					state = N1;
				}
				break;
			case RATIO2:
				if(c == 'j')
				{
					while(usartAvailable() == 0);
					c = usartGetChar();
					timer0DelayMs(100);
					sprintf(tmp, "STANJE RATIO2\r\n");
					usartPutString(tmp);

					sprintf(ratio, "%d\r\n");
					usartPutString(ratio);

					for( int i = 0; i < ratio; i++)
					{
						pinSetValue(PORT_B, 5, HIGH);
						timer0DelayMs(1000);
						pinSetValue(PORT_B, 5, LOW);

						if(i !=ratio-1)
							timer0DelayMs(1000);
					}
					sprintf(tmp, "RATIO2 -> N2\r\n");
					usartPutString(tmp);

					state = N2;
				}
				break;

			default:
				break;
		}
	}
	return 0;
}
