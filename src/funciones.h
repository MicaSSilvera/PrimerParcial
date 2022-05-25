/*
 * funciones.h
 *
 *  Created on: 21 may. 2022
 *      Author: Silvera Micaela
 */

#include "Censista.h"

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define CALLE 25
#define NOMBRE 20

#endif /* FUNCIONES_H_ */

void clearConsole();
///
void mostrarMenu(void);
///
int validarEntero(char mensaje[]);
///
int validarEstado(char mensaje[]);
///
int validarCensista(char mensaje[], struct Censista listaCensistas[], int len);
