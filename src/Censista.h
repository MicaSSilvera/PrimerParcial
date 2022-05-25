/*
 * Censista.h
 *
 *  Created on: 23 may. 2022
 *      Author: Silvera Micaela
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#define TEL 10
#define NOMBRE 20

struct Censista{
	int legajoCensista;
	char nombre[NOMBRE];
	int edad;
	char telefono[TEL];
};

#endif /* CENSISTA_H_ */

void crearCensistas (struct Censista* listaCensista);
///
void mostrarListaCensistas (struct Censista* listaCensista, int len);
///
void initListadoCensistas(struct Censista* listaCensista , int len);
