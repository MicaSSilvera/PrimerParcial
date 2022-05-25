/*
 * Censista.c
 *
 *  Created on: 23 may. 2022
 *      Author: Silvera Micaela
 */

#include "Censista.h"



#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define TEL 10
#define NOMBRE 20

void crearCensistas (struct Censista* listaCensista){

	struct Censista cencistaUno;

	cencistaUno.legajoCensista = 100;
	memcpy(&cencistaUno.nombre, "Ana", NOMBRE);
	cencistaUno.edad = 34;
	memcpy(&cencistaUno.telefono, "1203-2345", TEL);

	struct Censista cencistaDos;

	cencistaDos.legajoCensista = 101;
	memcpy(&cencistaDos.nombre, "Juan", NOMBRE);
	cencistaDos.edad = 24;
	memcpy(&cencistaDos.telefono, "4301-54678", TEL);

	struct Censista cencistaTres;

	cencistaTres.legajoCensista = 102;
	memcpy(&cencistaTres.nombre, "Sol", NOMBRE);
	cencistaTres.edad = 47;
	memcpy(&cencistaTres.telefono, "5902-37487", TEL);

	listaCensista[0] = cencistaUno;
	listaCensista[1] = cencistaDos;
	listaCensista[2] = cencistaTres;
}//fin listarCencista()

void mostrarListaCensistas (struct Censista* listaCensista, int len){


		printf("\n LISTADO DE CENSISTAS: \n");
		printf("\n-------------------------------------------------------------------------\n");

		 for(int i = 0; i< len; i++){

			 printf("\n CENSISTA: %d \n", i + 1);

			 printf("\n LEGAJO: %d",listaCensista[i].legajoCensista);

			 printf("\n NOMBRE: %s",listaCensista[i].nombre);

			 printf("\n EDAD: %d",listaCensista[i].edad);

			 printf("\n TELEFONO: %s",listaCensista[i].telefono);

			 printf("\n-------------------------------------------------------------------------\n");

		 }//fin for

}//fin mostrarListaCensistas()

void initListadoCensistas(struct Censista* listaCensista , int len){

	for(int i = 0; i < len; i++){
		struct Censista cencistaUno;

		cencistaUno.legajoCensista = 0;
		memcpy(&cencistaUno.nombre, "", NOMBRE);
		cencistaUno.edad = 0;
		memcpy(&cencistaUno.telefono, "", TEL);

	}//fin for

}//fin modificarVivienda()
