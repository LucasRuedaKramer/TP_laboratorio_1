/*
 * biblioteca.h
 *
 *  Created on: 14 may. 2022
 *      Author: lruedakramer
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define UP 1
#define DOWN 0
#define TRUE 1
#define FALSE 0

// agregar pasajeros
void getString(char palabra[], char texto[] );

// funciones varias del main
int mostrarMenu(void);
int preguntarPrimeraCarga(int flag);
void analizarSituacion (int situacion, char texto[]);




#endif /* BIBLIOTECA_H_ */
