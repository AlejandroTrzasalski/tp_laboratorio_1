/*
 * ArrayPassenger.c
 *
 *  Created on: 27 abr. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "otraBiblioteca.h"

#define LIBRE 0
#define OCUPADO 1
#define ACTIVO 2
#define DEMORA 3







int initPassenger(Passenger* list, int len)
{
	int retorno=0;

    if(list != NULL && len > 0)
    {
    	for(int i=0; i < len; i++)
    		{

    		list[i].isEmpty=LIBRE;
    		list[i].statusFlight=DEMORA;
        	retorno = 1;
    		}
    }
    return retorno;
}




int findPassengerById(Passenger* list, int len,int id)
{

    int indice= -1;

    if(list != NULL && len >0)
    {
        for(int i=0; i < len; i++)
        {
            if( list[i].isEmpty==OCUPADO && list[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}








int addPassenger(Passenger* list, int len, int id)
{
    int todoOk = 0;
    int indice=0;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    Passenger nuevoPasajero;


    	indice=buscarLibre(list,len);
        system("cls");
        printf("  *** Alta Empleado ***\n\n");

        if(indice <= -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
        	nuevoPasajero.id = id;

        	nuevoPasajero.statusFlight= ACTIVO;

            printf("Ingrese nombre: \n");
            fflush(stdin);
            getString(name, 51);
            firstToUpper(name);
            strcpy(nuevoPasajero.name,name);

            printf("Ingrese Apellido: \n");
            fflush(stdin);
            getString(lastName, 51);
            firstToUpper(lastName);
            strcpy(nuevoPasajero.lastName,lastName);

            printf("Ingrese precio del vuelo: \n");
            scanf("%f", &price);
            nuevoPasajero.price=price;

            printf("Ingrese codigo de vuelo: \n");
            fflush(stdin);
            getString(flycode, 10);
            pasarAMayusculas(flycode, 10);
            strcpy(nuevoPasajero.flycode,flycode);

            printf("Ingrese Tipo de pasajero: 1 para EJECUTIVO o 2 para TURISTA\n");
            scanf("%d", &typePassenger);
            nuevoPasajero.typePassenger=typePassenger;

            nuevoPasajero.isEmpty = OCUPADO;

            list[indice] = nuevoPasajero;



            todoOk = 1;
        }

    return todoOk;
}




int removePassenger(Passenger list[], int len, int id)
{

	int retorno=-1;
	char confirmacion;
	int	index=0;


	if(list != NULL && len >0)
	{
		index=findPassengerById(list,len,id);
		if(index==-1)
		{
			printf("El ID ingresado no existe.\n");
		}
		else
		{
			printf("Esta seguro de borrar al pasajero con ID %d (s/n)?\n", id);
			fflush(stdin);
			scanf("%c",&confirmacion);

			if(confirmacion=='s' || confirmacion == 'S')
			{

				list[index].isEmpty=LIBRE;
				retorno=0;
			}
			else
			{
				printf("Baja cancelada.\n");
			}
		}
	}

	return retorno;
}












/*
 * Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
 * Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.

	Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
*/
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int sortPassengerByCode(Passenger* list, int len, int order){

	int todoOk=-1;

	Passenger aux;

	if(list != NULL && len > 0)
	{
		switch(order)
		{
		case 1:

			for(int i = 0; i<len -1;i++)
			{
				for(int j =i+1;j<len;j++)
				{
					if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
					{
						if((list[i].statusFlight== list[j].statusFlight && strcmp(list[i].flycode,list[j].flycode) == 1)
							|| list[i].statusFlight > list[j].statusFlight)
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;

						}
					}
				}
				todoOk = 0;
			}
			break;

		case 2:
			for(int i = 0; i<len -1;i++)
						{
							for(int j =i+1;j<len;j++)
							{
								if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
								{
									if((list[i].statusFlight== list[j].statusFlight && strcmp(list[i].flycode,list[j].flycode) == -1)
									|| list[i].statusFlight < list[j].statusFlight)
									{
										aux = list[i];
										list[i] = list[j];
										list[j] = aux;

									}
								}
							}
							todoOk = 1;
						}
		}
	}


	return todoOk;
}







int sortPassengers(Passenger* list, int len, int order)
{

		int todoOk = -1;

		Passenger aux;

		if(list != NULL && len > 0)
		{
			switch(order)
			{
			case 1:
				for(int i = 0; i<len -1;i++)
				{
					for(int j =i+1;j<len;j++)
					{
						if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
						{
							if((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName,list[j].lastName) == 1)
									|| list[i].typePassenger > list[j].typePassenger)
							{
								aux = list[i];
								list[i] = list[j];
								list[j] = aux;

							}
						}
					}
					todoOk = 0;
				}
				break;
			case 2:
				for(int i = 0; i<len -1;i++)
							{
								for(int j =i+1;j<len;j++)
								{
									if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
									{
										if((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName,list[j].lastName) == -1)
												|| list[i].typePassenger < list[j].typePassenger)
										{
											aux = list[i];
											list[i] = list[j];
											list[j] = aux;

										}
									}
								}
								todoOk = 1;
							}
				break;
			}
		}

		return todoOk;
	}



int printPassenger(Passenger list[], int len)
{
	int retorno = 0;
	if(list !=NULL && len > 0){
		retorno = 1;
		system("cls");
		printf("     *** Listado de Pasajeros ***     \n");
		printf("ID    Nombre         Apellido       Precio  Flycode Tipo pasajero\n");
		for(int i=0; i<len; i++){
		printf(" %d    %20c         %20c             %5.2f     %c       %d\n",list->id,list->name[i],list->lastName[i],list->price,list->flycode[i],list->typePassenger);
		}
	}
	return retorno;
}













