#include "../pin_driver/pin.h"
#include "../timer0/timer0.h"
#include "../usart/usart.h"

int main()
{
	usartInit(9600);
	pinInit(PORT_B, 5, OUTPUT);
	timer0IneruptInit();

	typedef enum state_t {LOCKED, NUM1, NUM2, UNLOCKED, BROKEN, REC1, REC2} state_t;
	state_t state=LOCKED;

	char c;

	char tmp[64];

	while(1)
	{
		while(usartAvailable() == 0);

		c = usartGetChar();

		switch(state)
		{
		///LOCKED
		case LOCKED:
			sprintf(tmp, "STANJE LOCKED\r\n");
			usartPutString(tmp);


			if(c == '1')
			{

				pinSetValue(PORT_B, 5, HIGH);
				timer0DelayMs(1000);
				pinSetValue(PORT_B, 5, LOW);

				state = NUM1;
			}
			else
			{
				pinSetValue(PORT_B, 5, HIGH);

				state = BROKEN;
			}
			break;
			///NUM1
		case NUM1:
			while(usartAvailable() == 0);

			c = usartGetChar();


			sprintf(tmp, "STANJE NUM1\r\n");
			usartPutString(tmp);


			if(c == '2')
			{

				pinSetValue(PORT_B, 5, HIGH);
				timer0DelayMs(1000);
				pinSetValue(PORT_B, 5, LOW);

				state = NUM2;
			}
			else
			{
				pinSetValue(PORT_B, 5, HIGH);

				state = BROKEN;
			}
			break;
			///NUM2
		case NUM2:
			sprintf(tmp, "STANJE NUM2\r\n");
			usartPutString(tmp);

			while(usartAvailable() == 0);

			c = usartGetChar();

			if(c == '3')
			{

				for( int i = 0; i < 3; i++)
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);
					if(i != 2)
						timer0DelayMS(1000);
				}

			}
				else
				{
					pinSetValue(PORT_B, 5, HIGH);

					state = BROKEN;
				}

			}
			break;
			///UNLOCKED
		case UNLOCKED:

			while(usartAvailable() == 0);
			c = usartGetChar();

			sprintf(tmp, "STANJE UNLOCKED\r\n");
			usartPutString(tmp);

			state = UNLOCKED;
			break;
			///BROKEN
		case BROKEN:

			while(usartAvailable() == 0);
			c = usartGetChar();
			if(c == '7')
			{
				pinSetValue(PORT_B, 5, LOW);
				timer0DelayMs(1000);
				pinSetValue(PORT_B, 5, HIGH);

				state = REC1;
			}

			else
			{
				for( int i = 0; i < 2; i++)
				{
					pinSetValue(PORT_B, 5, LOW);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, HIGH);
					if(i != 1)
						timer0DelayMS(1000);
				}

			}

			break;
			///REC1
		case REC1:
			while(usartAvailable() == 0);
			c = usartGetChar();
			if(c == '8')
			{
				pinSetValue(PORT_B, 5, LOW);
				timer0DelayMs(1000);
				pinSetValue(PORT_B, 5, HIGH);

				state = REC2;
			}
			else
			{
				for( int i = 0; i < 2; i++)
				{
					pinSetValue(PORT_B, 5, LOW);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, HIGH);
					if(i != 1)
						timer0DelayMS(1000);
				}
				state = BROKEN;
			}
			break;
			///REC2
		case REC2:
			while(usartAvailable() == 0);
			c = usartGetChar();

			if(c == '9')
			{
				pinSetValue(PORT_B, 5, LOW);

				state = LOCKED;
			}
			else
			{
				for( int i = 0; i < 2; i++)
				{
					pinSetValue(PORT_B, 5, LOW);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, HIGH);
					if(i != 1)
						timer0DelayMS(1000);
				}
				state = BROKEN;
			}
			break;

	}
	return 0;
}


