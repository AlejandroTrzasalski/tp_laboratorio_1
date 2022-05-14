/*
 ============================================================================
 Name        : TP2.c
 Author      : Trzasalski Alejandro
 Version     :
 Copyright   : Your copyright notice
 Description : TP2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "otraBiblioteca.h"



#define TAM 10
#define OCUPADO 1
#define LIBRE 0
#define ASCENDENTE 1
#define DESCENDENTE 2
int main(void) {

	setbuf(stdout,NULL);


	int id=1;
	int contador=0;
	Passenger lista[TAM];
	initPassenger(lista, TAM);
	int subMenu;
	char seguir='s';




	do{

		switch(menu())
		{
		case 1:
			if(addPassenger( lista, TAM,  id)==1){
				contador++;
				id++;
			}
			else{
				printf("Error.");
			}

			break;

		case 2:
			if(contador>0)
			{
				listarId(lista,TAM);
				printf("Seleccione el ID a modificar.\n");
				int idModificar=getOption(1,2000);
				modificarPasajero(lista, TAM,  idModificar);
			}


			break;

		case 3:
			if(contador>0)
			{
				listarId(lista,TAM);
				printf("Seleccione el ID a eliminar.\n");
				int idBaja=getOption(1,2000);

				if(removePassenger(lista, TAM, idBaja)==0){
					contador--;
				}
			}
			break;

		case 4:
			if(contador>0)
			{
					printf("Ingrese 1 para ordenar de manera ASCENDENTE o 2 para DESCENDENTE.\n");
					int ordenar=getOption(1,2);



					printf("Ingrese 1 para listar por Apellido y tipo de pasajero.\nIngrese 2 "
					"para listar el TOTAL y Promedio.\nIngrese 3 para listar por código de vuelo y tipo.\n");
					subMenu=getOption(1,3);

						switch(subMenu)
						{

						case 1:

							sortPassengers( lista,  TAM, ordenar);
							listarId(lista, TAM);
						break;

						case 2:
							totalYPromedio( lista,  TAM);
							listarId(lista, TAM);
							break;

						case 3:
							sortPassengerByCode( lista,  TAM, ordenar);
							listarId(lista, TAM);
							break;
						}
			}


			break;

		case 5:
				printf("Ingrese s para continuar o n para salir.\n");
				fflush(stdin);
				scanf("%c",&seguir);
				seguir=tolower(seguir);
				while(seguir!='n' && seguir != 's'){
					printf("Error.\nIngrese s para continuar o n para salir.\n");
					fflush(stdin);
					scanf("%c",&seguir);
					seguir=tolower(seguir);
				}

			break;
		}


	}while(seguir!='n');

	return EXIT_SUCCESS;
}
















/*
	int r1;
	int r2;
	int index;
	int r4;


	Passenger ArrayPassenger;

	r1=initPassenger(&ArrayPassenger,TAM);

	//r2= addPassenger(&ArrayPassenger,TAM,id,name,lastName,price,typePassenger,flycode);

	index = findPassengerById(&ArrayPassenger, TAM,9);

	r4=removePassenger(&ArrayPassenger,TAM,20);
*/




