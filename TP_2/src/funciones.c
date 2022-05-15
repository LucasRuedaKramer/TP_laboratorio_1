/*
 * funciones.c
 *
 *  Created on: 14 may. 2022
 *      Author: lruedakramer
 */


#include "funciones.h"
#include "biblioteca.h"



/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int mostrarPassengers(Passenger list[], int len)
{
	int i;
	if(len<0)
	{
		return -1;
	}else
	{
	printf("\n\n");
	printf("%3s %13s %15s %14s %8s  %3s  %3s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "FLY CODE", "TYPE PASSENGER", "STATUS FLIGHT");
	for(i=0; i<len;i++)
		{
			if(list[i].isEmpty==FALSE)
			{
				mostrarUnPassenger(list,i);
			}
		}
		return 0;
	}
}




/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can'tfind a passenger] - (0) if Ok - (1) remove cancelled.
*
*/
int removePassenger (Passenger list[], int len, int id)
{
	int posicionId;
	char respuesta;

	posicionId = findPassengerById(list, len, id);

	if(posicionId==-1)
	{
		return -1;   // no se encontro el ID

	}else
	{
		printf("Esta por borrar el ID %d - %s %s - desea confirmar? s/n: ",id, list[posicionId].name, list[posicionId].lastName);
		fflush(stdin);
		scanf("%c",&respuesta);
		if(respuesta=='s')
		{
			list[posicionId].isEmpty=TRUE;
			printf("\nSe ha eliminado el ID %d - %s %s - de la base.\n", id, list[posicionId].name, list[posicionId].lastName);
			return 0;  		// eliminacion confirmada
		}else
			{
			return 1;			// eliminacion cancelada
			}

	}


}




/** \brief Modify a Passenger by Id (name, lastName, flycode or price)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can'tfind a passenger] - (0) if Ok - (1) modify cancelled.
*
*/
int modifyPassenger (Passenger list[], int len, int id)
{
	int posicionId;
	char respuesta;
	int situacion =-1;

	posicionId = findPassengerById(list, len, id);


	if(posicionId!=-1)
	{

		printf("\nEsta por modificar el ID %d - %s %s -",id, list[posicionId].name, list[posicionId].lastName);
		printf("\n\nSeleccione lo que desea modificar: ");
		printf("\na) Nombre.");
		printf("\nb) Apellido.");
		printf("\nc) Precio.");
		printf("\nd) FlyCode.");
		printf("\ne) TypePassenger.");
		printf("\nf) StatusFlight.");
		printf("\n\nIngrese su opcion: ");
		fflush(stdin);
		scanf("%c",&respuesta);

		switch(respuesta)
		{
		case 'a':
			 	 situacion = modificarString("nombre", list, len, posicionId);
			 	 break;

		case 'b':
			 	 situacion= modificarString("apellido", list, len, posicionId);
			 	 break;

		case 'c':
				 situacion= modificarFlotante("price", list, len, posicionId);
				 break;

		case 'd':
				 situacion= modificarString("flycode", list, len, posicionId);
				 break;

		case 'e':
				 situacion= modificarEntero("typePassenger", list, len, posicionId);
				 break;

		case 'f':
				 situacion= modificarEntero("statusFlight", list, len, posicionId);
				 break;


		default:
				 situacion=1; // cancelado

		}

	}

return situacion;

}




/** \brief search in a existing list of passengers the first empty position
* \param list passenger*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (!-1) if Ok, return the first empty position**/
int buscarLibre (Passenger* list, int len)
{
    int i;
    int indice=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==TRUE)
        {
            indice=i;
            break; // rompo para que me devuelva la primera posicion vacia
        }
    }
    return indice;
}




/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param flycode int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok **/
int addPassengers(Passenger* list, int len, int id, char name[],char lastName[],float price,char flycode[], int typePassenger, int statusFlight)
{
    int indiceEncontrado;

    indiceEncontrado = buscarLibre(list, len);

    if(indiceEncontrado!= -1) //encontro lugar
    {
        printf("\n---------------------------------------------------");
        printf("\n                  ALTA PASAJERO                   ");
        printf("\n---------------------------------------------------\n");

        //si encuentro lugar, pido los datos
        //cambiar el estado

        printf("Cargue los siguientes datos del nuevo pasajero:\n");

        getString(name,"Nombre");
        getString(lastName,"Apellido");
        printf("Precio: ");
        scanf("%f", &price);
        getString(flycode, "flycodes");
        printf("Tipo de Pasajero: ");
        scanf("%d", &typePassenger);
        printf("Status del vuelo: ");
        scanf("%d", &statusFlight);


        strcpy(list[indiceEncontrado].name,name);
        strcpy(list[indiceEncontrado].lastName,lastName);
	    list[indiceEncontrado].id=id;
	    list[indiceEncontrado].price=price;
	    strcpy(list[indiceEncontrado].flycode,flycode);
	    list[indiceEncontrado].typePassenger=typePassenger;
	    list[indiceEncontrado].statusFlight=statusFlight;
        printf("ID Pasajero: %d\n", id);

	    return 0; //se cargo producto

    }

    return indiceEncontrado; //indice -1, no hay lugar
}




/* brief: creacion de variables y llama a la funcion addPassenger, le pasa las variables como parametros
* \param list Passenger* Pointer to array of passengers
* \param len int Array length
* \param: id que viene hardcodeado del main (para que no se repita)
    return: int -1 no hay espacio.
             	 0 se cargo correctamente
*/
int cargarPassenger(Passenger* list, int len, int id)

{
	char name[51];
	char lastName[51];
	float price=0;
	char flycode[51];
	int typePassenger;
	int statusFlight;
	int estado=0;

	estado = addPassengers(list, len, id, name, lastName, price, flycode, typePassenger, statusFlight);

	return estado; // si es -1 no hay espacio   /   0 se cargo correctamente
}




/** \Funcion hardcodear, carga unos datos modelos en el array de pasajeros para poder testear el resto de las funciones.
* \param list Passenger* Pointer to array of passengers
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (!-1) if Ok // me devuelve el primer id libre para usar
*
*/
int hardcodear(Passenger list[], int len)
 {
	int i;
	int id[5]= {2,5,4,3,1};
	char nombres[5][51] = {"Ana","Lucas","Maria Soledad","Juan Martin", "Julio"};
	char apellidos[5][51] = {"Garcia","Lopez","Perez","Ramirez", "Tunez"};
	float precios[5] = { 25000, 40000 ,35650, 27500, 23000 };
	char flycodes[5] [51] = {"a","b","c","d","e"};
	int typePassenger [5]= {20,50,40,30,10};
	int statusFlight [5] = {1,0,1,0,1};
	int vacios[5] = {FALSE, FALSE, FALSE, FALSE, FALSE};

	if(5<len )
	{
		for(i=0; i < 5; i++)
		{
	     list[i].id=id[i];
	     strcpy(list[i].name,nombres[i]);
	     strcpy(list[i].lastName,apellidos[i]);
	     list[i].price=precios[i];
	     strcpy(list[i].flycode,flycodes[i]);
	     list[i].typePassenger=typePassenger[i];
	     list[i].statusFlight=statusFlight[i];
	     list[i].isEmpty=vacios[i];
		}
		return i+1; //i es 5 por eso sale del for, me devuelve el primer id sin usar
	}
	else
	{
		return -1; //no hay lugar
	}

}



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Passenger* Pointer to array of passengers
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger list[], int len)
{
    int salida;
	int i;
	if(len!=0 && list!= NULL)
	{
	for(i=0; i<len; i++)
		{
		list[i].isEmpty=TRUE;
		}
    salida = 0; //todo ok
	}else
	{
		salida = -1; //error. no pude inicializar la lista
	}
	return salida;
}





/** \brief print the content of one passenger array
*
* \param list Passenger*
* \param index int
* \return void
*
*/
void mostrarUnPassenger(Passenger list[], int index)
{
		printf("%5d %15s %15s %12.2f %15s %5d %5d\n",list[index].id, list[index].name, list[index].lastName, list[index].price, list[index].flycode, list[index].typePassenger, list[index].statusFlight);
}






/** \brief cuenta la cantidad de pasajeros que superen el promedio de precios de los pasajeros activos
* \param list Passenger*
* \param len int
* \param float precio promedio
* \return cantidad pasajeros con precios mayores al promedio
* */
int contarPasajerosMayorAlPromedio (Passenger* list, int len, float promedioPrecios)
{
	int contarPasajerosMayorAlPromedio=0;
	int i;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==FALSE && list[i].price>promedioPrecios)
		{
			contarPasajerosMayorAlPromedio++;
		}
	}


	return contarPasajerosMayorAlPromedio;
}




/** \brief promedio de precios de los pasajeros activos
* \param float total precios
* \param int cantidad de pasajeros
* \return precio promedio
* */
float promediarPrecios (float totalPrecios, int cantidadPasajeros)
{
	float promedio=-1;

	if(cantidadPasajeros!=0)
	{
	promedio=totalPrecios/cantidadPasajeros;
	}

return promedio;
}




/** \brief suma cantidad de pasajeros activos
* \param list Passenger*
* \param len int
* \return cantidad pasajeros
*/
int obtenerCantidadPasajeros (Passenger* list, int len)
{
	int i;
	int cantidadPasajeros=0;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
		cantidadPasajeros++;
		}
	}
return cantidadPasajeros;
}



/** \brief suma precios de pasajeros activos
* \param list Passenger*
* \param len int
* \return total de precios
* */
float obtenerTotalPrecios (Passenger* list, int len)
{
	int i;
	float sumaPrecios=0;

	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
		sumaPrecios=sumaPrecios+ list[i].price;
		}
	}
return sumaPrecios;
}



/** \brief promedio de precios de los pasajeros activos
* \param float total precios
* \param int cantidad de pasajeros
* \return precio promedio
* */
float promediasPrecios (float totalPrecios, int cantidadPasajeros)
{
	float promedio=-1;

	if(cantidadPasajeros!=0)
	{
	promedio=totalPrecios/cantidadPasajeros;
	}

return promedio;
}





/** \brief muestra estadisticas (llama a funciones para sacar total, cantidad y promedio de precios)
* \param list Passenger*
* \param len int
* \return void
* */
void mostrarEstadisticas (Passenger* list, int len)
{
	int cantidadPasajeros;
	float totalPrecios;
	float promedioPrecios;
	int cantidadPasajerosConPreciosMayorAlPromeido;

	cantidadPasajeros= obtenerCantidadPasajeros(list, len);
	totalPrecios= obtenerTotalPrecios(list, len);
	promedioPrecios = promediarPrecios(totalPrecios,cantidadPasajeros);
	cantidadPasajerosConPreciosMayorAlPromeido = contarPasajerosMayorAlPromedio(list, len, promedioPrecios);

	printf("\n\n");
	printf("TOTAL DE PRECIOS DE LOS PASAJES: $ %.2f\n", totalPrecios);
	printf("PROMEDIO DE PRECIO DE LOS PASAJES: $ %.2f\n", promedioPrecios);
	printf("PASAJEROS QUE SUPERAN EL PRECIO PROMEDIO: %d\n", cantidadPasajerosConPreciosMayorAlPromeido);
	printf("\n\n");
}




/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengers(Passenger* list, int len, int order)  //Listado de los pasajeros ordenados alfabéticamente por Apellido y Sector
{
	int i;
	int j;
	int resultado=-1;
	Passenger auxiliarPassenger;

	for(i=0;i<len-1;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
			for(j=i+1;j<len;j++)
			{
				if(strcmp(list[i].lastName, list[j].lastName)>order || (strcmp(list[i].lastName, list[j].lastName)==0 && list[i].flycode>list[j].flycode))   // >0 de A a Z			<0 o <1 de la Z a la a
				{
					auxiliarPassenger = list[i];
					list[i]=list[j];
					list[j]=auxiliarPassenger;
					resultado=0;
				}

			}
		}
	}

    printf("\n----------------------------------------------------------");
    printf("\n                   INFORMES ESTADISTICOS              ");
    printf("\n----------------------------------------------------------\n");

return resultado;
}





/** \brief Sort the elements in the array of passengers, por id de menor a mayor
* \param list Passenger*
* \param len int
* \return void
*/
void sortPassengersPorId (Passenger* list, int len)  //Listado de los pasajeros ordenados id menor a mayor
{
	int i;
	int j;
	Passenger auxiliarPassenger;

	for(i=0;i<len-1;i++)
	{
		if(list[i].isEmpty==FALSE)
		{
			for(j=i+1;j<len;j++)
			{
				if(list[i].id > list[j].id)
				{
					auxiliarPassenger = list[i];
					list[i]=list[j];
					list[j]=auxiliarPassenger;
				}

			}
		}
	}

}


/** \brief pedirle al usuario un un id de la lista que se muestra en pantalla
* \param list Passenger*
* \param len int
* el do while sigue hasta que el usuario elija un id correcto, si se arrepiente, en la siguiente funcion puede cancelar la modificacion o eliminacion
* \return id encontrado  **/


int pruebaId (Passenger list[], int len, char texto[])
{
    int busquedaId;
    int idIngresadoPorUsuario;
    int estadoMostrar;

    sortPassengersPorId(list, len); //ordeno array por id de menor a mayor para que esten prolijos a la vista del usuario

    printf("\n--------------------------------------------------------");
    printf("\n                   %s PASAJERO                   ",texto);
    printf("\n--------------------------------------------------------\n");


 do
 {
	estadoMostrar= mostrarPassengers(list, len);
	if(estadoMostrar==0)
	{
    printf("\nSeleccione un ID de la lista: ");
	scanf("%d", &idIngresadoPorUsuario);

	printf("\n\n");

    busquedaId =findPassengerById(list, len, idIngresadoPorUsuario);

    switch(busquedaId)
	{
	        case -1: //id inexistente
	        printf("Error. ID pasajero inexistente. Ingrese uno valido.\n\n");
	        break;

	        default: //se encontro el ID
	        break;

	 }
	}


}   while(busquedaId==-1);

	 return idIngresadoPorUsuario;

}





/** \brief find an Passenger by Id
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return (1) id   or (-1) if [Invalid length or NULL
pointer received or passenger not found]
*
*/
int findPassengerById(Passenger list[], int len, int idIngresadoPorUsuario)
{
    int i;
    for(i=0; i<len; i++)
	    {
	        if(list[i].isEmpty==FALSE && idIngresadoPorUsuario==list[i].id)
	        {
	                 return i; //devuelvo indice del id
	                 break;
	        }
	    }
	return -1; //no se encontro el id
}


/** \brief pedirle al usuario un string para cambiar nombre o apellido y formatearlo (paso a minuscula el string y primeras letras mayusculas)
* \param char texto, texto que se informa en el printf para reutilizar la funcion
* \param list Passenger*
* \param len int
* \param index int
* \return 0 modify correct
* 		  1 modify canceled **/
int modificarString(char texto[], Passenger list[], int len, int posicionId)
{
	char nuevoString[51];
	char respuesta;
	int i;

	printf("\nIngrese el nuevo %s: ",texto); // le pido al usuario el nuevo string
	fflush(stdin);
	gets(nuevoString);
	if(strcmp(texto,"nombre")==0) // pregunto si es el nombre
	{
		printf("\nEsta seguro que desea modificar el %s '%s' por '%s'? s/n: ",texto, list[posicionId].name, nuevoString);
	}
	else 						// si es el apellido pasa esto
	{
	    if(strcmp(texto,"apellido")==0) // pregunto si es el apellido
	{
		printf("\nEsta seguro que desea modificar el %s '%s' por '%s'? s/n: ",texto, list[posicionId].lastName, nuevoString);
	}
	else 						// si es el apellido pasa esto
	{
		printf("\nEsta seguro que desea modificar el %s '%s' por '%s'? s/n: ",texto, list[posicionId].flycode, nuevoString);
	}
	fflush(stdin);
	scanf("%c",&respuesta);
	if(respuesta=='s')
	{
		strlwr(nuevoString);  // poner string a minuscula
		nuevoString[0]=toupper(nuevoString[0]);  //poner primera letra mayuscula
		for(i=0; i<51; i++)
		{
			if(nuevoString[i]==' ')
			{
				nuevoString[i+1]=toupper(nuevoString[i+1]); // preguntar si hay nombre/apellido compuesto
			}
		}

		if(strcmp(texto,"nombre")==0)
			{
			strcpy(list[posicionId].name,nuevoString);
			}else
			{
			    if(strcmp(texto,"apellido")==0)
			{
			strcpy(list[posicionId].lastName,nuevoString);
			}else
			{
				strcpy(list[posicionId].flycode,nuevoString);
			}
		printf("\nEl nuevo %s es '%s'.\n",texto, nuevoString);
		return 0;    //Modificacion confirmada
	}
		return 1;   //Modificacion cancelada
	}
	}}




/** \brief pedirle al usuario un flotante para cambiar precio
* \param char texto, texto que se informa en el printf para reutilizar la funcion
* \param list Passenger*
* \param len int
* \param index int
* \return 0 modify correct
* 		  1 modify canceled **/
int modificarFlotante(char texto[], Passenger list[], int len, int posicionId)
{
	float nuevoFloat;
	char respuesta;

	// if(strcmp(texto,"precio")==0)      // base por si tuviese mas float a modificar
	printf("\nEl %s actual es $%.2f.",texto, list[posicionId].price);
	printf("\nIngrese el nuevo %s: ",texto);
	scanf("%f", &nuevoFloat);

	printf("Esta seguro que desea modificar el %s '$%.2f' por '$%.2f'? s/n: ",texto, list[posicionId].price, nuevoFloat);

	fflush(stdin);
	scanf("%c",&respuesta);
	if(respuesta=='s')
	{
		list[posicionId].price=nuevoFloat;

		printf("\nEl nuevo %s es '$%.2f'.\n",texto, nuevoFloat);
		return 0;   //Modificacion confirmada
	}else
	{
		return 1;   //Modificacion cancelada
	}
}





/** \brief pedirle al usuario un entero para cambiar sector
* \param char texto, texto que se informa en el printf para reutilizar la funcion
* \param list Passenger*
* \param len int
* \param index int
* \return 0 modify correct
* 		  1 modify canceled **/
int modificarEntero(char texto[], Passenger list[], int len, int posicionId)
{
	int nuevoInt;
	char respuesta;

	if(strcmp(texto,"typePassenger")==0)      // base por si tuviese mas int a modificar
	printf("\nEl %s actual es %d.",texto, list[posicionId].typePassenger);
	printf("\nIngrese el nuevo %s: ",texto);
	scanf("%d", &nuevoInt);

	printf("Esta seguro que desea modificar el %s '%d' por '%d'? s/n: ",texto, list[posicionId].typePassenger, nuevoInt);

	fflush(stdin);
	scanf("%c",&respuesta);
	if(respuesta=='s')
	{
		list[posicionId].typePassenger=nuevoInt;

		printf("\nEl nuevo %s es '%d'.\n",texto, nuevoInt);
		}else
		{
		  //  if(strcmp(texto,"statusFlight")==0)      // base por si tuviese mas int a modificar
	printf("\nEl %s actual es %d.",texto, list[posicionId].statusFlight);
	printf("\nIngrese el nuevo %s: ",texto);
	scanf("%d", &nuevoInt);

	printf("Esta seguro que desea modificar el %s '%d' por '%d'? s/n: ",texto, list[posicionId].statusFlight, nuevoInt);

	fflush(stdin);
	scanf("%c",&respuesta);
	if(respuesta=='s')
	{
		list[posicionId].statusFlight=nuevoInt;

		printf("\nEl nuevo %s es '%d'.\n",texto, nuevoInt);
		return 0;   //Modificacion confirmada
	}else
	{
		return 1;   //Modificacion cancelada
	}
}
}


