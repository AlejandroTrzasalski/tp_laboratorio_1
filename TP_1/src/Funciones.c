/*
 * Funciones.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


float Debito(float precio){

	float resultado;

	resultado= precio - (precio*0.1);

	return resultado;
}

float Credito(float precio){

	float resultado;

	resultado = precio*1.25;

	return resultado;
}

float Bitcoin(float precio){

	float resultado;

	resultado= precio/4606964.55;

	return resultado;
}

float PrecioUnitario(float precio, int km){

	float resultado;

	resultado= precio / km;

	return resultado;
}

float Diferencia(float precioAerolineas, float precioLatam){

	float resultado;

		if(precioAerolineas > precioLatam){
			resultado= precioAerolineas - precioLatam;
		}else{
			resultado= precioLatam - precioAerolineas;
		}



	return resultado;

}



