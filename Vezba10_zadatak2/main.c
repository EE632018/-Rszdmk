#include "../usart/usart.h"
#include "../timer0/timer0.h"
#include "../pin_driver/pin.h"
#include <string.h>


int main()
{
	usartInit(9600);
	pinInit(PORT_B, 5, OUTPUT);
	timer0InteruptInit();

	typedef enum state_s
	{
		CF0U,
		CF1,
		CF2D,
		OF1,
		OF2,
		OF0,
		CF0,
		CF1D,
		CF1U,
		CF2
	} state_t;

	state_t state = CF0U;

	char c;
	char tmp[64];

	while(1)
	{
		while(usartAvailable() == 0);

		c = usartGetChar();

		switch(state)
		{
			/// CF0U
			case CF0U:
				sprintf(tmp, "STANJE CF0U\r\n");
				usartPutString(tmp);

				pinSetValue(PORT_B, 5, HIGH);
				state = CF1;
				break;
			/// CF1
			case CF1:
				sprintf(tmp, "STANJE CF1\r\n");
				usartPutString(tmp);

				for(int i = 0; i < 3; i++)
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);
					if(i != 2)
						timer0DelayMS(1000);
				}
				state = OF1;
				break;
			/// CF2D
			case CF2D:
				sprintf(tmp, "STANJE CF2D\r\n");
				usartPutString(tmp);

				pinSetValue(PORT_B, 5, HIGH);

				state = CF1;
				break;
			/// OF1
			case OF1:
				sprintf(tmp, "STANJE OF1\r\n");
				usartPutString(tmp);
				if(c == 'D')
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);

					state = CF1D;
				}
				else if(c == 'U')
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);

					state = CF1D;
				}
				else
				{
					state = OF1;
				}
				break;
			/// OF2
			case OF2:
				sprintf(tmp, "STANJE OF2\r\n");
				usartPutString(tmp);

				if(c == 'D')
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);

					state = CF2D;
				}
				else
				{
					state = OF2;
				}
				break;
			/// OF0
			case OF0:
				sprintf(tmp, "STANJE OF0\r\n");
				usartPutString(tmp);

				if(c == 'U')
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);

					state = CF0U;
				}
				else
				{
					state = OF0;
				}
				break;
			/// CF0
			case CF0:
				sprintf(tmp, "STANJE CF0\r\n");
				usartPutString(tmp);

				for(int i =0; i < 3; i++)
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);
					if(i != 2)
					{
						timer0DelayMs(1000);
					}
				}
				state = OF0;
				break;
			/// CF1D
			case CF1D:
				sprintf(tmp, "STANJE CF1D\r\n");
				usartPutString(tmp);

				pinSetValue(PORT_B, 5, HIGH);

				state = CF0;
				break;
			/// CF1U
			case CF1U:
				sprintf(tmp, "STANJE CF1U\r\n");
				usartPutString(tmp);

				pinSetValue(PORT_B, 5, HIGH);

				state = CF2;
				break;
			/// CF2
			case CF2:
				sprintf(tmp, "STANJE CF2\r\n");
				usartPutString(tmp);

				for(int i =0; i < 3; i++)
				{
					pinSetValue(PORT_B, 5, HIGH);
					timer0DelayMs(1000);
					pinSetValue(PORT_B, 5, LOW);
					if(i != 2)
					{
						timer0DelayMs(1000);
					}
				}
				state = OF0;
				break;
		}

	}
	return 0;
}
