/*
 * funciones.h
 *
 *  Created on: 14 may. 2022
 *      Author: lruedakramer
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define UP 1
#define DOWN 0
#define TRUE 1
#define FALSE 0


struct
{
int id;
char name[51];
char lastName[51];
float price;
char flycode[51];
int typePassenger;
int statusFlight;
int isEmpty;
} typedef Passenger;

float promediarPrecios (float totalPrecios, int cantidadPasajeros);


int pruebaId (Passenger list[], int len, char texto[]);

// inicializo en cero

int initPassengers(Passenger list[], int len);

// hardcodeo datos en el array para testear

int hardcodear(Passenger list[], int len);

// agregar empleados

int cargarPassenger(Passenger* list, int len, int id);

	int addPassengers(Passenger list[], int len, int id, char name[],char lastName[],float price,char flyCode[],int typePassenger,int statusFlight);

		int buscarLibre (Passenger* list, int len);





// mostrar empleados

int mostrarPassenger(Passenger list[], int len);

	void mostrarUnPassenger(Passenger list[], int index);


// funciones vinculadas al id



int findPassengerById(Passenger list[], int len, int idIngresadoPorUsuario);



// funciones de remover y modificar

int removePassenger (Passenger list[], int len, int id);

int modifyPassenger (Passenger list[], int len, int id);

	int modificarString(char texto[], Passenger list[], int len, int id);

	int modificarFlotante(char texto[], Passenger list[], int len, int id);

	int modificarEntero(char texto[], Passenger list[], int len, int id);



// ordenar array

int sortPassengers (Passenger* list, int len, int order);

void ordenarPassengersPorId (Passenger* list, int len);


// calcular estadisticas y mostrar

int obtenerCantidadPasajeros (Passenger* list, int len);

float obtenerTotalPrecios (Passenger* list, int len);



int contarPasajerosMayorAlPromedio (Passenger* list, int len, float promedioPrecios);

void mostrarEstadisticas (Passenger* list, int len);


#endif /* FUNCIONES_H_ */
