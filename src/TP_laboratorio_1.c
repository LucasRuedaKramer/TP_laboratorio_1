/*
 ============================================================================
 Name        : TP_laboratorio_1.c
 Author      : LucasRuedaKramer
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

   #include <stdio.h>
    #include <stdlib.h>
    #include <conio.h>
    #include "funciones.h"

int menu();
int aerolinea();
int medioDePago();
void confirmarFlag(char* x);
void opcionInvalida();
void calculador();
float kmForzado = 7090;
float precioLatamForzado = 159339;
float precioLatamDebitoForzado;
float precioLatamCreditoForzado;
float precioLatamBtcForzado;
float precioAerolineasForzado = 162965;
float precioAerolineasDebitoForzado;
float precioAerolineasCreditoForzado;
float precioAerolineasBtcForzado;
float debito = .9;
float credito = 1.25;
float btc = 4606954.55;


void main()
{
    char salir = 'n';
    float km;
    float precioLatam;
    float precioAerolineas;
    precioAerolineas = 0;
    precioLatam = 0;
    float precioLatamDebito;
    float precioAerolineasDebito;
    float precioLatamCredito;
    float precioAerolineasCredito;
    float precioLatamBtc;
    float precioAerolineasBtc;
    float diferencia;

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese los Km de su viaje:\n");
            fflush(stdin);
            scanf("%f", &km);
            printf("Los km son: %.2f\n" , km);
            break;
        case 2:
            switch (aerolinea())
            {
            case 1:
                printf("Ingrese el precio: ");
                fflush(stdin);
                scanf("%f", &precioLatam);
                printf("El precio es: %.2f\n" , precioLatam);
                break;
            case 2:
                printf("Ingrese el precio: ");
                fflush(stdin);
                scanf("%f", &precioAerolineas);
                printf("El precio es: %.2f\n" , precioAerolineas);
                break;
            case 3:
                confirmarFlag(&salir);
                break;
            case 4:
                opcionInvalida();
                break;
            default:
            printf("Opcion Invalida!!!");
            }
            break;
        case 3:
            confirmarFlag(&salir);
            break;
        case 4:
           calculador();
            break;
        case 5:
            opcionInvalida();
            break;
        default:
            printf("Opcion Invalida!!!");

        }
        getch();

    }
    while(salir != 's');
    //fflush(stdin);


    printf("Los km son de : %.2f\n" , km);

    if(precioLatam > 0)
    {
    printf("El precio de Latam es : %.2f\n" , precioLatam);
    precioLatamDebito = Multiplicar(precioLatam,km,debito);
    printf("El precio de Latam con debito es : %.2f\n" ,precioLatamDebito);
    precioLatamCredito = Multiplicar(precioLatam,km,credito);
    printf("El precio de Latam con credito es : %.2f\n" , precioLatamCredito);
    precioLatamBtc = Multiplicar(precioLatam,km,btc);
    printf("El precio de Latam con BTC es : %.2f\n" , precioLatamBtc);
    }

    if(precioAerolineas > 0)
    {
    printf("El precio de Aerolineas es : %.2f\n" , precioAerolineas);
    precioAerolineasDebito = Multiplicar(precioAerolineas,km,debito);
    printf("El precio de Aerolineas con debito es : %.2f\n" , precioAerolineasDebito);
    precioAerolineasCredito = Multiplicar(precioAerolineas,km,credito);
    printf("El precio de Aerolineas con credito es : %.2f\n" , precioAerolineasCredito);
    precioAerolineasBtc = Multiplicar(precioAerolineas,km,btc);
    printf("El precio de Aerolineas con BTC es : %.2f\n" , precioAerolineasBtc);
    }

    diferencia = Restar(precioLatam,precioAerolineas);
    printf("La diferencia de precio ingresada es : %.2f\n" , diferencia);

    /*return 0;*/
}

int menu()
{
    int opcion;
    int cant;

    system("cls");
    printf("*** Menu de Opciones ***\n\n");
    printf("1- Ingrese Km\n");
    printf("2- Ingrese la aerolinea\n");
    printf("3- Mostrar Resultados\n");
    printf("4- Desea probar una carga forzada de datos?\n");
    printf("Ingrese opcion: ");
    fflush(stdin);

    cant = scanf("%d", &opcion);

    if(cant == 0)
    {
        opcion = 5;
    }

    return opcion;
}

int aerolinea()
{
    int opcion;
    int cant;

    system("cls");
    printf("*** Ingrese el precio por Aerolinea ***\n\n");
    printf("1- Latam\n");
    printf("2- Aerolineas Argentina\n");
    printf("3- Salir\n");
    printf("Ingrese Aerloinea: ");
    fflush(stdin);

    cant = scanf("%d", &opcion);

    if(cant == 0)
    {
        opcion = 4;
    }

    return opcion;
}

int medioDePago()
{
    int opcion;
    int cant;

    system("cls");
    printf("*** Menu de Opciones de Aerolinea ***\n\n");
    printf("1- Debito\n");
    printf("2- Credito\n");
    printf("3- BTC\n");
    printf("4- Salir\n");
    printf("Ingrese Aerloinea: ");
    fflush(stdin);

    cant = scanf("%d", &opcion);

    if(cant == 0)
    {
        opcion = 5;
    }

    return opcion;
}


void confirmarFlag(char* x)
{
    printf("Confirma finalizada la carga de datos?: ");
    fflush(stdin);
    scanf("%c", x);
}

void opcionInvalida()
{
    printf("Eso no es un numero\n");
}

void calculador()
{
            printf("Los km son de : %.2f\n" , kmForzado);
            printf("El precio unitario de Latam es : %.2f\n" , precioLatamForzado);
            precioLatamDebitoForzado = Multiplicar(precioLatamForzado,kmForzado,debito);
            printf("El precio de Latam con debito es : %.2f\n" , precioLatamDebitoForzado);
            precioLatamCreditoForzado = Multiplicar(precioLatamForzado,kmForzado,credito);
            printf("El precio de Latam con credito es : %.2f\n" , precioLatamCreditoForzado);
            precioLatamBtcForzado = Multiplicar(precioLatamForzado,kmForzado,btc);
            printf("El precio de Latam con BTC es : %.2f\n" , precioLatamBtcForzado);
            printf("El precio unitario de Aerolineas es : %.2f\n" , precioAerolineasForzado);
            precioAerolineasDebitoForzado = Multiplicar(precioAerolineasForzado,kmForzado,debito);
            printf("El precio de Aerolineas con debito es : %.2f\n" , precioAerolineasDebitoForzado);
            precioAerolineasCreditoForzado = Multiplicar(precioAerolineasForzado,kmForzado,credito);
            printf("El precio de Aerolineas con credito es : %.2f\n" , precioAerolineasCreditoForzado);
            precioAerolineasBtcForzado = Multiplicar(precioAerolineasForzado,kmForzado,btc);
            printf("El precio de Aerolineas con BTC es : %.2f\n" , precioAerolineasBtcForzado);
}







