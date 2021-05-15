/**
* @file z4.h
* @brief H fajl pomocnih funkcija
* @author Milos Strizak
* @date 14.05.2021.
* @version 1.0
*/

#ifndef Z4_H_
#define Z4_H_

#include "../usart/usart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/**
* proveraImena funkcija za proveru imena
* @param ime - korisnicko ime
* @return povratna vrednost je uint8_t
*/
uint8_t proveraImena(uint8_t ime[]);

/**
* funkcija za proveru lozinke
* @param lozinka - korisnicka lozinka
* @return povratna vrednost je uint8_t
*/
uint8_t proveraLozinke ( uint8_t lozinka[]);

/**
* funkcija za proveru poklapanja korisnika i lozinke
* @param p - korisnicko ime
* @param k - korisnicka lozinka
* @return nema povratna vrednost
*/

void Provera( uint8_t p, uint8_t k, uint8_t ime[]);

#endif /* Z4_H_ */
