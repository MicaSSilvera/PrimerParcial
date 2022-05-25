/*
 * Viviendas.h
 *
 *  Created on: 23 may. 2022
 *      Author: Silvera Micaela
 */

#include "Censista.h"

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#define CALLE 25
#define NOMBRE 20

struct Vivienda{
	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
};

#endif /* VIVIENDA_H_ */

struct Vivienda altaVivienda(int idNuevo, struct Censista listaCensistas[], int len);
///
void mostrarLista(struct Vivienda* listaVivienda, int len);
///
void guardarVivienda (struct Vivienda* listaVivienda,struct Vivienda viviendaNueva, int len);
///
void modificarVivienda(struct Vivienda* listaVivienda , int len, struct Vivienda vivienda);
///
void initListadoViviendas(struct Vivienda* listaVivienda , int len);
///
void bajaVivienda(struct Vivienda* listaVivienda , int len, int idVivienda);
///
void ordenarListaPorCalle(struct Vivienda* listaVivienda , int len);
///
int validarIngresoVivienda(struct Vivienda* listaVivienda , int len);
///
int validarIdVivienda(char mensaje[], struct Vivienda listaVivienda[], int len);
