/**
* @file main.c
* @brief Logovanje uz lozinku i username
* @author Milos Strizak
* @date 14.05.2021.
* @version 1.0
*/

#include "z4.h"

/**
* Glavna funkcija
* @param Nema parametra
* @return Nema povratnu vrednost
*/

int main()
{
	uint8_t ime[64], lozinka[64];
	uint8_t u,l;
	usartInit(9600);

	while(1)
	{
			usartPutString_P(PSTR("Unesite korisnicko ime \r\n" ));

			while(!usartAvailable());

			_delay_ms(100);

			usartGetString(ime);
			u = proveraImena(ime);

			usartPutString_P(PSTR("Unesite lozinku: \r\n"));
			while(!usartAvailable());

			_delay_ms(100);

			usartGetString(lozinka);
			l = proveraLozinke(lozinka);

			Provera(u, l, ime);

	}
	return 0;
}
