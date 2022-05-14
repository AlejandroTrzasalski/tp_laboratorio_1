/*
 * otraBiblioteca.h
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */

#ifndef OTRABIBLIOTECA_H_
#define OTRABIBLIOTECA_H_
#include "ArrayPassenger.h"


int menu();
int getOption(int min, int max);
int buscarLibre(Passenger list[], int len);
int modificarPasajero(Passenger* list, int len, int id);
int subMenuModificar();
int pasarAMayusculas(char vector[], int size);
char miToupper(char x);
int listarId(Passenger list[], int len);
int listarflycode(Passenger list[], int len);
int totalYPromedio(Passenger* list, int len);
Passenger CrearUnPasajero();
int getValidInt(int *numero);
int primerEspacioLibre(Passenger list[], int len);
int getInt(char mensaje[]);

void pedirCadena(char mensaje[], char cadena[]);

char miToupper(char x);

int pasarAMayusculas(char vector[], int size);

char getChar(char mensaje[]);


int getFloat(char mensaje[]);

void firstToUpper(char cadena[]);

int cargarUnPasajero(Passenger list[], int len);
void firstToUpper(char cadena[]);
int getString(char *string, int maxLen);
#endif /* OTRABIBLIOTECA_H_ */
