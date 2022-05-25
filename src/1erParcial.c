/*
 ============================================================================
 Name        : 1erParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

#include "funciones.h"
#include "Vivienda.h"
#include "Censista.h"

#define CALLE 25
#define NOMBRE 20
#define MENSAJES 2000
#define VIVIENDA 50
#define CENSISTAS 3

int main(void) {
	setbuf(stdout,NULL);

	int opcion = 0;
	int idVivienda = 2000;
	int ingresoVivienda = 0;

	struct Vivienda objetoVivienda;

	//creo un array de tipo Vivienda con 50 posiciones.
	struct Vivienda listaViviendas[VIVIENDA];
	//Cargo el array de viviendas con todos los valores en 0 para inicializarlo.
	initListadoViviendas(listaViviendas, VIVIENDA);

	//creo un array de tipo Censita con 3 posiciones.
	struct Censista listaCensistas[CENSISTAS];
	//Cargo el array de censistas con todos los valores en 0 para inicializarlo.
	initListadoCensistas(listaCensistas, CENSISTAS);
	//Cargo el array con los censistas Hardcodeados;
	crearCensistas(listaCensistas);

	while(opcion != 6){

		//Muestro el menu de opciones
		mostrarMenu();

		char mensaje[MENSAJES];
		memcpy(&mensaje, "Ingrese una opcion: ", MENSAJES);
		opcion = validarEntero(mensaje);

		clearConsole();
		int validar = 0;

	      switch(opcion){
	      	  	 case 1:  //alta

	      	  		 //llamo a la funcion altaVivienda, en la que se le pedira al usuario que ingrese los datos de la viviendo y voy a retornar un objeto de tipo Viviendo
	      	  		 objetoVivienda = altaVivienda(idVivienda, listaCensistas, CENSISTAS);

	      	  		 //llamo a la funcion guardarVivienda donde le paso la lista de viviendas y la vivienda creada y voy a guardar la nueva vivienda en mi lista de vivienda
	      	  		 guardarVivienda(listaViviendas, objetoVivienda, VIVIENDA);

	      	  		 //aumento en uno la variable idVivienda, luego de haber guardado la nueva vivienda, para que sea autoincremental.
	      	  		 idVivienda++;

	      	  		 clearConsole();

	      	  		 break;
	      	  	 case 2:  // modificar viviendas
	      	  		//chequeo que se haya ingresado al menos una vivienda.
	      	  		ingresoVivienda = validarIngresoVivienda(listaViviendas, VIVIENDA);

	      	  		if(ingresoVivienda == 1){
	      	  		//llamo la funcion mostrarLista, para que se pueda ver la vista de viviendas y poder llamar a la funcion para modificar
					mostrarLista(listaViviendas,  VIVIENDA);

					//pido al usuario que ingrese el id de la vivienda que quiere modificar
					char mensaje[MENSAJES];
					memcpy(&mensaje, "Ingrese el id de la vivienda que quiere modificar: ", MENSAJES);
					//valido que el id ingresado sea un numero entero y que se encuentre dentro de la lista de viviendas.
					int idModificarVivienda = validarIdVivienda(mensaje, listaViviendas, VIVIENDA);

					// llamo a la funcion altaVivienda para crear un objetoVivienda con los datos ingresados por el usuario
					 objetoVivienda = altaVivienda(idModificarVivienda, listaCensistas, CENSISTAS);

					 //llamo la funcion modificarVivienda para que se pueda modificar la vivienda seleccionada a traves del id
					 modificarVivienda(listaViviendas,  VIVIENDA ,objetoVivienda );
	      	  		} else {
	      	  			printf("NO SE HA INGRESADO NINGUNA VIVIENDA. \n");
	      	  		}//FIN IF

	      	  		clearConsole();
	      	  		break;
	      	  	 case 3:// baja viviendas

	      	  		//chequeo que se haya ingresado al menos una vivienda.
					ingresoVivienda = validarIngresoVivienda(listaViviendas, VIVIENDA);

					if(ingresoVivienda == 1){
						//llamo la funcion mostrarLista, para que se pueda ver la vista de viviendas y poder llamar a la funcion bajaVivienda
						mostrarLista(listaViviendas,  VIVIENDA);

						//pido al usuario que ingrese el id de la vivienda que quiere dar de baja
						char mensaje2[MENSAJES];
						memcpy(&mensaje, "Ingrese el id de la vivienda que quiere dar de baja: ", MENSAJES);
						//valido que el id ingresado sea un numero entero y que se encuentre dentro de la lista de viviendas.
						int idBajaVivienda = validarIdVivienda(mensaje, listaViviendas, VIVIENDA);

						//le pregunto al usuario si realmente quiere eliminar la vivienda seleccionada
						char rta = validarRespuesta();

						//si la respuesta del usuario es s, borro la vivienda seleccionada
						 if(rta == 's'){

							//llamo la funcion bajaVivienda para eliminar los datos de la vivienda ingresada por el usuario
							bajaVivienda(listaViviendas,  VIVIENDA, idBajaVivienda);
						  }
					} else {
						printf("NO SE HA INGRESADO NINGUNA VIVIENDA. \n");
					}//FIN IF
	      	  		clearConsole();
	      	  		break;
	      	  	 case 4://  listar viviendas

	      	  		//chequeo que se haya ingresado al menos una vivienda.
					ingresoVivienda = validarIngresoVivienda(listaViviendas, VIVIENDA);

					if(ingresoVivienda == 1){
						 //llamo a la funcion que ordena la lista por calle alfabeticamente.
						 ordenarListaPorCalle(listaViviendas, VIVIENDA);
						 //llamo la funcion mostrarLista, en la que muestra toda la lista con los datos de las viviendas ingresadas.
						 mostrarLista(listaViviendas,  VIVIENDA);
					} else {
						printf("NO SE HA INGRESADO NINGUNA VIVIENDA. \n");
					}//FIN IF
	      	  		clearConsole();
	      	  		break;
	      	  	 case 5:  // listas censista

	      	  		 //llamo la funcion mostrarListaCensistas, en la que muestra toda la lista con los datos de los Censistas hardcodeados.
	      	  		 mostrarListaCensistas(listaCensistas, CENSISTAS);

	      	  		 clearConsole();
	      	  		 break;
	      	  	 case 6://  salir
	      	  		 printf("SALIENDO... :)");
	      	  		 clearConsole();
	      	  		 break;

	      	  	 default:
					 printf("LA OPCION INGRESADA ES INCORRECTA, VUELA A INTENTARLO \n");
					 break;


	      }//fin switch

	      fflush(stdin);

	}//fin while





	return EXIT_SUCCESS;
}
