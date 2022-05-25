/*
 * funciones.c
 *
 *  Created on: 21 may. 2022
 *      Author: Silvera Micaela
 */

#include "funciones.h"



#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

void clearConsole(){
	printf("\n");
	printf("\n");
}//FIN clearConsole()
///
void mostrarMenu(){
	printf("\n 1) ALTA VIVIENDA ");
	printf("\n 2) MODIFICAR VIVIENDA ");
	printf("\n 3) BAJA VIVIENDA ");
	printf("\n 4) LISTAR VIVIENDAS ");
	printf("\n 5) LISTAR CENSISTA ");
	printf("\n 6) SALIR \n");
}//fin
///
int esEntero(char linea[]) {
	int esEntero = 1;
	int longitud = strlen(linea);

	if (longitud == 0) {
		esEntero = 0;
	} else if (longitud == 1 && !isdigit(linea[0])) {
		esEntero = 0;
	} else {
		int indice = 0;

		if (linea[0] == '+' || linea[0] == '-') {
			indice = 1;
		} else {
			indice = 0;
		}//FIN IF

		while (indice < longitud) {

			if (!isdigit(linea[indice])) {
				esEntero = 0;
				break;
			}//FIN IF

			indice++;
		}//FIN WHILE
	}//FIN IF

	return esEntero;
}//FIN esEntero()
///
int validarEntero(char mensaje[]){
	int numero = 0;

	char linea[50];
	int repite = 1;

	do {
		printf("\n %s ", mensaje);
		scanf ("%s", &linea);
		fflush(stdin);

		if (esEntero(linea)) {
			repite = 0;
		} else {
			printf("\nNo has ingresado un valor entero. Intentalo nuevamente\n");
		}
		fflush(stdin);
	} while (repite);

	numero = atoi(linea);

	return numero;
}//FIN validarEntero()
///
int validarEstado(char mensaje[]){
	int numero = 0;

	char linea[50];
	int repite = 1;

	do {
		printf("\n %s ", mensaje);
		scanf ("%s", &linea);
		fflush(stdin);

		if (esEntero(linea)) {
			numero = atoi(linea);
			if(numero == 1 || numero == 2 || numero == 3 || numero == 4){
				repite = 0;
			}else{
				printf("No ha ingresado una opcion correcta. Intentalo nuevamente \n");
			}//fin if

		} else {
			printf("\n No ha ingresado un valor entero. Intentalo nuevamente\n");
		}//fin if
		fflush(stdin);
	} while (repite);

	numero = atoi(linea);

	return numero;
}//FIN validarEstado()
///
char validarRespuesta(){
	char rta;
	int repite = 1;

	while(repite == 1) {
		printf("\n Estas seguro de que deseas eliminar a esa vivienda? [ s / n ] ");
		scanf ("%c", &rta);

		if (rta == 's' || rta == 'n' ) {
			repite = 0;
		} else {
			printf("\nNo has ingresado un valor correcto. Intentalo nuevamente");
		}
		fflush(stdin);

	}//FIN WHILE

	return rta;
}//FIN validarRespuesta()

int validarCensista(char mensaje[], struct Censista listaCensistas[], int len){
	int legajoIngresado = 0;

	char linea[50];
	int repite = 1;

	do {
		printf("\n %s ", mensaje);
		scanf ("%s", &linea);
		fflush(stdin);

		if (esEntero(linea)) {
			legajoIngresado = atoi(linea);

			for(int i = 0; i < len; i++){

				if(legajoIngresado == listaCensistas[i].legajoCensista){
					repite = 0;
				}

			}//FIN FOR

			if(repite == 1){
				printf("No ha ingresado un numero de legajo correcto. Intentalo nuevamente \n");
			}//fin if

		} else {
			printf("\n No ha ingresado un valor entero. Intentalo nuevamente\n");
		}//fin if
		fflush(stdin);
	} while (repite);

	legajoIngresado = atoi(linea);

	return legajoIngresado;
}//FIN validarEstado()
