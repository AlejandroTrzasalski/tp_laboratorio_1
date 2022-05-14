/*
 * otraBiblioteca.c
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */
#include "otraBiblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIBRE 0
#define OCUPADO 1
#define ACTIVO 2
#define DEMORA 3


int menu()
{
	int opcion;

	printf("\nOpciones:\n1. ALTAS.\n2. MODIFICAR.\n3. BAJA.\n4. INFORMAR.\n5. SALIR.\n");
	opcion=getOption(1,5);

	return opcion;
}

int getOption(int min, int max){
	int opcion;

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    while(opcion<min || opcion>max)
    {
        printf("Opcion invalida.\n Ingrese nuevamente: \n");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}


int buscarLibre(Passenger* list, int len)
{

	int pIndex=-1;

	if(list != NULL && len >0)
	{

        for(int i=0; i < len; i++)
        {
            if(list[i].isEmpty==LIBRE)
            {
                pIndex = i;
                break;
            }
	}

}

    return pIndex;
}

int modificarPasajero(Passenger* list, int len, int id)
{
	char confirmacion;
	char dato[20];
	int retorno=-1;
	int index=0;
	int tipoPasajero;
	float precio;
	int statusFlight;

	Passenger aux;

	if(list != NULL && len >0)
	{
		index=findPassengerById(list,len,id);
		if(index==-1)
		{
			printf("El ID ingresado no existe.\n");
		}
		else
		{
			aux=list[index];

			switch(subMenuModificar())
			{

			case 1:
				printf("Ingrese el nuevo nombre: \n");
				getString(aux.name,51);
				firstToUpper(aux.name);
				strcpy(dato,"nombre");
				break;

			case 2:
				printf("Ingrese el nuevo apellio: \n");
				getString(aux.lastName,51);
				firstToUpper(aux.lastName);
				strcpy(dato,"apellido");
				break;

			case 3:
				printf("Ingrese el nuevo precio: \n");
				scanf("%f",&precio);
				aux.price=precio;
				strcpy(dato,"precio");
				break;

			case 4:
				printf("Ingrese el nuevo codigo de vuelo: \n");
				getString(aux.flycode,10);
				pasarAMayusculas(aux.flycode, 10);
				strcpy(dato,"codigo de vuelo");
				break;

			case 5:
				printf("Ingrese el nuevo tipo de pasajero: \n");
				scanf("%d",&tipoPasajero);
				aux.typePassenger=tipoPasajero;
				strcpy(dato,"tipo de pasajero");
				break;


			case 6:
				printf("Ingrese 2 para ACTIVO y 3 PARA DEMORA ");
				fflush(stdin);
				scanf("%d",&statusFlight);
				while(statusFlight<2 || statusFlight>3)
				{
					printf("Error.\nIngrese 2 para ACTIVO y 3 PARA DEMORA ");
					fflush(stdin);
					scanf("%d",&statusFlight);
				}
				aux.statusFlight=statusFlight;
				strcpy(dato,"statusFlight");
			}



			printf("\n");
			printf("Seguro que desea modificar el %s del pasajero con ID %d (s/n)", dato, id);
			fflush(stdin);
			scanf("%c",&confirmacion);

			if(confirmacion=='s' || confirmacion == 'S')
			{
				list[index]=aux;
				retorno=0;
			}
			else
			{
				printf("Modificacion cancelada por el usuario.\n");
			}
		}
	}
	return retorno;
}

int subMenuModificar()
{
	int opcion;
	printf("Que dato desea modificar?\n"
			"1. Nombre: \n"
			"2. Apellido: \n"
			"3. Precio: \n"
			"4. Codigo de vuelo: \n"
			"5. Tipo de pasajero: \n"
			"6. Status Vuelo: \n");

				opcion=getOption(1,6);

	return opcion;
}





int listarId(Passenger list[], int len)
{
//OCUPADO 1
//LIBRE 0
//EJECUTIVO 1
//TURISTA 2


	int todoOk = 0;
	int flag=1;
	char statusFlight[10];
	char typePassenger[10];

    if( list != NULL && len > 0)
    {
		printf("ID    Nombre       Apellido     Precio   Estado de Vuevlo   Codigo de vuelo   Tipo de pasajero\n");

		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				if(list[i].statusFlight==ACTIVO){
					strcpy(statusFlight,"ACTIVO");
				}
				else{
					strcpy(statusFlight,"DEMORA");
				}

				if(list[i].typePassenger==1){
					strcpy(typePassenger,"EJECUTIVO");
				}
				else{
					strcpy(typePassenger,"TURISTA");
				}
				printf("%d ",list[i].id);
				printf("%5s ",list[i].name);
				printf("%12s ",list[i].lastName);
				printf("%12.f ",list[i].price);
				printf("%17s ",statusFlight);
				printf("%17s ", list[i].flycode);
				printf("%22s \n",typePassenger);


				flag=0;
			}

		}
		if(flag==1){
			printf("No hay pasajeros en el sistema.\n");
		}
		 todoOk = 1;
    }
   return todoOk;
}

int listarflycode(Passenger list[], int len)
{
//ACTIVO 2
//DEMORA 3

	int todoOk = 0;
	int flag=1;

    if( list != NULL && len > 0)
    {
		printf("Listado de flycode's:\n");
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCUPADO && list[i].statusFlight==ACTIVO)
			{
				printf("%s Estado de vuelo: ACTIVO\n",list[i].flycode);

				flag=0;
			}

		}
		if(flag==1){
			printf("No hay pasajeros en el sistema.\n");
		}
		 todoOk = 1;
    }
   return todoOk;
}

int totalYPromedio(Passenger* list, int len)
{
	int todoOk=0;
	float total=0;
	int cantPasajeros=0;
	float promedio;
	int pasajerosSupPromedio=0;


		if(list!= NULL && len >0)
		{
		todoOk=1;

			for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty==OCUPADO)
				{
					total += list[i].price;
					cantPasajeros++;
				}
			}


		promedio=total / cantPasajeros;

		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==OCUPADO && list[i].price > promedio){
				pasajerosSupPromedio++;
			}
		}

		printf("\nEl total de los pasajes es: %2.f\n",total);
		printf("El promedio de los pasajes es: %2.f\n",promedio);
		printf("La cantidad de pasajeros que superan el promedio es: %d\n\n",pasajerosSupPromedio);
		}
	return todoOk;
}

Passenger CrearUnPasajero()
{
    Passenger auxPassenger;
    pedirCadena("Ingrese el nombre del pasajero: ", auxPassenger.name);
    pedirCadena("Ingrese el apellido del pasajero: ", auxPassenger.lastName);
    auxPassenger.price = getFloat("Ingrese el precio del vuelo: ");
    auxPassenger.typePassenger = getFloat("Ingrese el tipo de pasajero: ");
    pedirCadena("Ingrese el codigo del vuelo: ", auxPassenger.flycode);
    auxPassenger.isEmpty = LIBRE;
    return auxPassenger;
}

int getValidInt(int *number)
{
    int sePudo = 1;
    char cadenaCargada [1001];

    sprintf(cadenaCargada, "%d", *number);
    printf("%s", cadenaCargada);
    for(int i=0; i<strlen(cadenaCargada) ; i++)
    {
        if(cadenaCargada[i] < '0' || cadenaCargada[i] > '9')
        {
            sePudo = -1;
        }
    }
    if(sePudo == 1)
    {
        *number = atoi (cadenaCargada);
    }

    return sePudo;
}

int primerEspacioLibre(Passenger list[], int len)
{
int retorno = -1;

	    for(int i=0;i<len;i++)
	    {
	        if(list[i].isEmpty == LIBRE)
	        {
	            retorno = i;
	            break;
	        }
	    }
	    return retorno;
}

int getInt(char mensaje[])
{
    int numero;
    printf("%s: ", mensaje);
    scanf("%d", &numero);
    return numero;
}

void pedirCadena (char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    firstToUpper(cadena);
}

char miToupper(char x)
{
	if(x >= 'a' && x <= 'z'){
		x = x-32;
	}
	return x;
}

int pasarAMayusculas(char vector[], int size)
{
	int retorno=0;

	if(vector != NULL && size > 0)
	{
	    for(int i=0;i<size;i++)
	    {
	        vector[i] = miToupper(vector[i]);

	    }

	    retorno =1;
	}
	return retorno;
}

char getChar(char mensaje[])
{
    char letter;
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    return letter;
}



int getFloat(char mensaje[])
{
    float numero;
    printf("%s: ", mensaje);
    scanf("%f", &numero);
    return numero;
}

int cargarUnPasajero(Passenger list[], int len)
{
    int indice;
    int retorno = -1;
    indice = primerEspacioLibre(list, len);
    if(indice != -1){
        list[indice] = CrearUnPasajero();
        retorno = 0;
    }
    else{
    	printf("No hay lugar en el sistema. \n ");
    }
    return retorno;
}

void firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(int i=0;i<tam;i++)
    {
        if(cadena[i]!='\0')
        {
            if(isspace(cadena[i]))
            {
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}

int getString(char *string, int maxLen)
{
    int retorno=-1;
    char aux[100];
    if(string!=NULL && maxLen>0 && maxLen<99){
        fflush(stdin);
        fgets(aux,100,stdin);
        while(strlen(aux)>maxLen){
            printf("El maximo numero de caracteres permitidos es %d. Reingrese dato: ",maxLen);
            fflush(stdin);
            fgets(aux,100,stdin);
        }
        aux[strlen(aux)-1]='\0';
        strcpy(string, aux);
        retorno=0;
    }
    return retorno;
}
