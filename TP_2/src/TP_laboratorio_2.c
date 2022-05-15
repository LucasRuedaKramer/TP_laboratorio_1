/*
 ============================================================================
 Name        : TP_laboratorio_2.c
 Author      : LucasRuedaKramer
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "biblioteca.h"
#include <conio.h>
#define T 2000



int main(void)
{
	setbuf(stdout, NULL);

	Passenger listaPassenger[T];

	int respuesta;
	int idParaValidar;
	int estado;
	int id;
	int flagPrimeraCarga=0;
	int preguntaPrimeraCarga;

estado = initPassengers(listaPassenger, T);

	id = hardcodear(listaPassenger, T);


	do{

		respuesta = mostrarMenu();

		switch(respuesta)
		{
				case 1:
					estado = cargarPassenger(listaPassenger, T, id);
					analizarSituacion(estado,"Carga");
					id++;
					flagPrimeraCarga=1;
					break;
				case 2:
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						idParaValidar = pruebaId(listaPassenger, T, "M");
						estado = modifyPassenger(listaPassenger, T, idParaValidar);
						analizarSituacion(estado,"Modificacion");
					}
					break;
				case 3:
					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						idParaValidar = pruebaId(listaPassenger, T, "ELIMINAR");
						estado =removePassenger(listaPassenger, T, idParaValidar);
						analizarSituacion(estado,"Eliminacion");
					}
					break;
				case 4:

					preguntaPrimeraCarga = preguntarPrimeraCarga(flagPrimeraCarga);
					if(preguntaPrimeraCarga==1)
					{
						estado = sortPassengers(listaPassenger, T, DOWN);
						if(estado==0)
						{
							estado = mostrarPassengers(listaPassenger, T);
						}

						mostrarEstadisticas(listaPassenger, T);
					}
					break;

		}
	system("pause");
	system("cls"); //en eclipse no funciona


	}while(respuesta!=5);


	printf("Gracias por utilizar nuestro programa!\n\n");
	system("pause");


	return EXIT_SUCCESS;
}


