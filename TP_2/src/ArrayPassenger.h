/*
 * ArrayPassenger.h
 *
 *  Created on: 27 abr. 2022
 *      Author: Trzasalski Alejandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_



struct {

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}typedef Passenger;



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* Para indicar que todas las posiciones del array esten vacias,
* esta funcion pone una bandera si es verdadero en todas las posiciones
* del arreglo.
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassenger(Passenger list[], int len);



/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id);



/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger list[], int len,int id);



/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger list[], int len,int id);

int sortPassengers(Passenger* list, int len, int order);

int printPassenger(Passenger* list,int  size);


int sortPassengerByCode(Passenger* list, int len, int order);












#endif /* ARRAYPASSENGER_H_ */
