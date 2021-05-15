/**
* @file z4.c
* @brief C datoteka pomocnih funkcija
* @author Milos Strizak
* @date 14.05.2021.
* @version 1.0
*/

#include "z4.h"

uint8_t proveraImena ( uint8_t ime[])
{
	uint8_t username[] = "MyName";
	uint8_t duzina, pom = 0;
	uint8_t p = 0;

	duzina = strlen(ime);
	for(uint8_t i=0; i < duzina; i++)
	{
		if(username[i] == ime[i])
		{
			pom++;
		}

	}
	if(pom == duzina)
	{
		p = 1;
	}

	return p;
}


uint8_t proveraLozinke ( uint8_t lozinka[])
{
	uint8_t baza[] = "P@ssw0rd";
	uint8_t duzina, pom = 0;
	uint8_t k = 0;

	duzina = strlen(lozinka);

	for( uint8_t i = 0; i < duzina; i++)
	{
		if(baza[i] == lozinka[i])
		{
			pom++;
		}

	}
	if(pom == duzina)
	{
		k = 1;
	}
	return k;
}

void Provera( uint8_t p, uint8_t k, uint8_t ime[])
{
	if(p == 1 && k == 1)
	{
		usartPutString_P(PSTR("Dobrodosao/la, "));
		usartPutString(ime);
		usartPutString_P(PSTR(" \r\n"));
	}
	else
	{
		usartPutString_P(PSTR(" Logovanje neuspasno! \r\n"));
	}
}
