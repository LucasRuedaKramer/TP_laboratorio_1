/*
 * biblioteca.c
 *
 *  Created on: 14 may. 2022
 *      Author: lruedakramer
 */



#include "biblioteca.h"




/** \brief imprime mensajes en pantalla segun la situacion que reciba
* \param int situacion
* \param char texto a printear
* \return void
*/
void analizarSituacion (int situacion, char texto[])
{
	if(situacion==-1)
	{
		if((strcmp(texto,"Modificacion")==0) || (strcmp(texto,"Eliminacion")==0))
		{
		printf("\nID no encontrado, intente nuevamente.\n\n");     //ID no encontrado
		}
		else
		{
		printf("\nError. No hay espacio.\n\n");
		}
	}
	else if(situacion==0)
	{
		printf("\n%s correcta y finalizada.\n\n",texto);    //confirmada
	}
	else if(situacion==1)
	{
		printf("\n%s cancelada.\n\n", texto);          // cancelado
	}
}




/** \brief mostrar menu de opciones al usuario
* \param void
* \return respuesta elegida **/
int mostrarMenu(void)
{
	int respuesta;

	printf("   BASE DE EMPLEADOS    \n");
	printf("************************");
	printf("\nElija una de las siguientes opciones:");
	printf("\n1. ALTAS.");
	printf("\n2. MODIFICAR.");
	printf("\n3. BAJAS.");
	printf("\n4. INFORMAR.");
	printf("\n5. SALIR DEL SISTEMA.");
	printf("\n\nIngrese su opcion: ");
	scanf("%d",&respuesta);

	return respuesta;
}

/** \brief pedirle al usuario un string y formatearlo (elimino salto de linea del fgets y paso a minuscula el string y primeras letras mayusculas)
* \param char string, que lo completa el usuario
* \param char texto, texto que se informa en el printf para reutilizar la funcion
* \return void **/


/** \brief preguntar si ya se carga un empleado
* \param flag que se habilita con la opcion de add employee
* \return -1 no se cargo empleado
* 		   1 ya se cargo un empleado, se habilita el resto del menu **/
int preguntarPrimeraCarga(int flag)
{
	int estado;
	if(flag == 0)
	{
		printf("No ha cargado ningun empleado. Por favor, realicelo.\n");
		estado=-1;
	}else
	{
		estado=1;
	}
	return estado;
}



void getString(char palabra[], char texto[] )
{
   int largoString;
   int i;

	printf("%s: ",texto);
	fflush(stdin);
	//__fpurge(stdin);
	fgets(palabra,51,stdin);

	largoString= strlen(palabra);       // busco el largo del string
	palabra[largoString-1]='\0';
	largoString= strlen(palabra);


	strlwr(palabra);
	palabra[0]=toupper(palabra[0]);

	for(i=0; i<largoString; i++)
	{
		if(palabra[i]==' ')
		{
			palabra[i+1]=toupper(palabra[i+1]);

		}
	}

}
