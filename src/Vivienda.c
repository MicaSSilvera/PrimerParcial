/*
 * Viviendas.c
 *
 *  Cr eated on: 23 may. 2022
 *      Author: Silvera Micaela
 */
#include "Vivienda.h"


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MENSAJES 100

struct Vivienda altaVivienda(int idNuevo, struct Censista listaCensistas[], int len){
	struct Vivienda viviendaNueva;

	viviendaNueva.idVivienda = idNuevo;

	printf("Ingrese calle: \n");
	scanf ("%s", &viviendaNueva.calle);

	char mensaje[MENSAJES];
	memcpy(&mensaje, "Ingrese cantidad de personas: \n", MENSAJES);
	viviendaNueva.cantidadPersonas = validarEntero(mensaje);

	char mensaje2[MENSAJES];
	memcpy(&mensaje2, "Ingrese cantidad de habitaciones: \n", MENSAJES);
	viviendaNueva.cantidadHabitaciones = validarEntero(mensaje2);

	char mensaje3[MENSAJES];
	memcpy(&mensaje3, "Ingrese tipo de vivienda: [1. CASA - 2. DEPARTAMENTO - 3. CASILLA - 4. RANCHO] \n", MENSAJES);
	viviendaNueva.tipoVivienda = validarEstado(mensaje3);

	char mensaje4[MENSAJES];
	memcpy(&mensaje4, "Ingrese el legajo del censista: \n", MENSAJES);
	viviendaNueva.legajoCensista = validarCensista(mensaje4, listaCensistas, len);

	return viviendaNueva;
}//fin funcion altaVivienda
///
void mostrarLista(struct Vivienda* listaVivienda, int len){
	int contViviendas = 0;

	printf("\n LISTADO DE VIVIENDAS: \n");
	printf("\n-------------------------------------------------------------------------\n");

	 for(int i = 0; i< len; i++){

		 if(listaVivienda[i].idVivienda != 0 ){
			 contViviendas++;

			 printf("\n VIVIENDA: %d \n", contViviendas);

			 printf("\n ID: %d",listaVivienda[i].idVivienda);

			 printf("\n CALLE: %s",listaVivienda[i].calle);

			 printf("\n CANTIDAD DE PERSONAS: %d",listaVivienda[i].cantidadPersonas);

			 printf("\n CANTIDAD DE HABITACIONES: %d",listaVivienda[i].cantidadHabitaciones);

			 if( listaVivienda[i].tipoVivienda == 1){
				 printf("\n TIPO DE VIVIENDA: %d [CASA]", listaVivienda[i].tipoVivienda );
			 }else if( listaVivienda[i].tipoVivienda == 2){
				 printf("\n TIPO DE VIVIENDA: %d [DEPARTAMENTO]", listaVivienda[i].tipoVivienda );
			 }else if( listaVivienda[i].tipoVivienda == 3){
				 printf("\n TIPO DE VIVIENDA: %d [CASILLA]", listaVivienda[i].tipoVivienda );
			 }else if( listaVivienda[i].tipoVivienda == 4){
				 printf("\n TIPO DE VIVIENDA: %d [RANCHO]", listaVivienda[i].tipoVivienda );
			 }else{
				 printf("\n TIPO DE VIVIENDA: %d [NO INGRESO]", listaVivienda[i].tipoVivienda );
			 }//fin if

			 printf("\n LEGAJO CENSISTA: %d",listaVivienda[i].legajoCensista);

			 printf("\n-------------------------------------------------------------------------\n");

		 }//FIN IF

	 }//fin for



}//fin funcion mostrarLista
///
void guardarVivienda (struct Vivienda* listaVivienda,struct Vivienda viviendaNueva, int len){
	int guardoDatos = 0;

	for(int i = 0; i < len; i++){

		if(listaVivienda[i].idVivienda == 0 && guardoDatos == 0) {
		      listaVivienda[i] = viviendaNueva;
		      guardoDatos = 1;
		}//fin if

	}//fin for


}//fin guardarVivienda()
///
void modificarVivienda(struct Vivienda* listaVivienda , int len, struct Vivienda vivienda){

	for(int i = 0; i < len; i++){

		if(listaVivienda[i].idVivienda != 0){
			if(listaVivienda[i].idVivienda == vivienda.idVivienda){
				listaVivienda[i] = vivienda;
			}
		}//fin if

	}//fin for

}//fin modificarVivienda()
///
void initListadoViviendas(struct Vivienda* listaVivienda , int len){

	for(int i = 0; i < len; i++){

		listaVivienda[i].idVivienda = 0;
		memcpy(&listaVivienda[i].calle, "", 25);
		listaVivienda[i].cantidadPersonas = 0;
		listaVivienda[i].cantidadHabitaciones = 0;
		listaVivienda[i].tipoVivienda = 0;
		listaVivienda[i].legajoCensista = 0;

	}//fin for

}//fin modificarVivienda()
///
void bajaVivienda(struct Vivienda* listaVivienda , int len, int idVivienda){

	for(int i = 0; i < len; i++){

		if(listaVivienda[i].idVivienda != 0){
			if(listaVivienda[i].idVivienda == idVivienda){
				listaVivienda[i].idVivienda = 0;
				memcpy(&listaVivienda[i].calle, "", 25);
				listaVivienda[i].cantidadPersonas = 0;
				listaVivienda[i].cantidadHabitaciones = 0;
				listaVivienda[i].tipoVivienda = 0;
				listaVivienda[i].legajoCensista = 0;

				printf("LA VIVIENDA A SIDO BORRADA EXITOSAMENTE  \n");
			}//fin if

		}//fin if

	}//fin for



}//fin borrarVivienda()
///
void ordenarListaPorCalle(struct Vivienda* listaVivienda , int len){

	for(int i = 0; i < len; i++){

		for(int j = 0; j< len-1; j++){
			int indiceSiguiente = j + 1;

			struct Vivienda calleAux;
			if(strcmp(listaVivienda[j].calle, listaVivienda[indiceSiguiente].calle) > 0 ){

				calleAux = listaVivienda[j];
				listaVivienda[j] = listaVivienda[indiceSiguiente];
				listaVivienda[indiceSiguiente] = calleAux;

			}else if(strcmp(listaVivienda[j].calle, listaVivienda[indiceSiguiente].calle) == 0 && listaVivienda[j].cantidadPersonas > listaVivienda[indiceSiguiente].cantidadPersonas ){

				calleAux = listaVivienda[j];
				listaVivienda[j] = listaVivienda[indiceSiguiente];
				listaVivienda[indiceSiguiente] = calleAux;
			}//FIN IF


		}//fin for

	}//fin for

}//fin ordenarListaPorCalle()
///
int validarIngresoVivienda(struct Vivienda* listaVivienda , int len){
	int ingresoVivienda = 0;

	for(int i = 0; i < len; i++){

		if(listaVivienda[i].idVivienda > 0){
			ingresoVivienda = 1;

		}//fin if

	}//fin for


	return ingresoVivienda;
}//fin validarIngresoVivienda()
///
int validarIdVivienda(char mensaje[], struct Vivienda listaVivienda[], int len){

	int idIngresado = 0;

	char linea[50];
	int repite = 1;

	do{
		printf("\n %s ", mensaje);
		scanf ("%s", &linea);
		fflush(stdin);

		if (esEntero(linea)) {
			idIngresado = atoi(linea);

			for(int i = 0; i < len; i++){

				if(idIngresado == listaVivienda[i].idVivienda){
					repite = 0;
				}

			}//FIN FOR

			if(repite == 1){
				printf("No ha ingresado un numero de ID de vivienda correcto. Intentalo nuevamente \n");
			}//fin if

		} else {
			printf("\n No ha ingresado un valor entero. Intentalo nuevamente\n");
		}//fin if
		fflush(stdin);
	} while (repite);

	idIngresado = atoi(linea);

	return idIngresado;
}// fin validarVivienda


