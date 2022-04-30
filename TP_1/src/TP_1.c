/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Tp.h"



/** \brief
 *
 * \param
 * \param
 * \return
 *
 *Trabajo Practico 1
 */

int main()
{
    setbuf(stdout, NULL);
    char seguir = 'n';
    int flagkm = 0;
    int opcion;
    int precioIngresado = 0;

    float precio = 0,
          precio_Debit_Aereo = 0,
          precio_Credito_Aereo = 0,
          precio_Bitcoin_Aereo = 0,
          precio_km_Aereo = 0,
          precio_Debit_Latam = 0,
          precio_Credito_Latam = 0,
          precio_Bitcoin_Latam = 0,
          precio_km_Latam = 0,
          precio_diferencia = 0,
          precioAereo = 0,
          precioLatam = 0;

    unsigned int km_forzado = 7090;
    unsigned long Aerolineas_forzado = 162965;
    unsigned long latam_forzado = 159339;


    float precio_Debit_Aereo_forzado = 0;
    float precio_Credito_Aereo_forzado = 0;
    float precio_Bitcoin_Aereo_forzado = 0;
    float precio_km_Aereo_forzado = 0;

    float precio_Debit_Latam_forzado = 0;
    float precio_Credito_Latam_forzado =0;
    float precio_Bitcoin_Latam_forzado = 0;
    float precio_km_Latam_forzado = 0;
    float precio_diferencia_forzado = 0;


    do
    {
        switch(menu())
        {
        case 1:
            km(&flagkm);
            break;

        case 2: // INGRESA EL PRECIO EL USUARIO
            if (flagkm == 1)
            {


                printf("ingrese el vuelo que se desea tomar Aerolineas Argentinas: $%.2f // Latam: $%.2f \n", precioAereo, precioLatam);
                printf("1_ Aerolineas Argentinas\n");
                printf("2_Latam\n");
                scanf("%d",&opcion);
                printf("ingrese el precio\n");
                scanf("%f",&precio);

                switch(opcion)
                {

                case 1:
                    precioAereo = precio;
                    break;
                case 2:
                    precioLatam = precio;
                    break;

                default:
                    printf("INGRESE OPCION VALIDA:");
                }
                precioIngresado = 1;
            }
            else
            {
                printf("ingrese primero los kilometros: \n");
            }
            break;

        case 3:
            if (flagkm == 1 || precioIngresado == 1) // VALIDACION PARA QUE INGRE PRIMERO LOS KM Y EL PRECIO
            {

                precio_Debit_Aereo =  calculosdebito(precioAereo);
                precio_Credito_Aereo = calculosCredito(precioAereo);
                precio_Bitcoin_Aereo =  calculoBitcoin(precioAereo);
                precio_km_Aereo =  calculoskm(precioAereo,flagkm );

                precio_Debit_Latam =  calculosdebito (precioLatam);
                precio_Credito_Latam =  calculosCredito(precioLatam);
                precio_Bitcoin_Latam =  calculoBitcoin(precioLatam);
                precio_km_Latam = calculoskm(precioLatam,flagkm);

                precio_diferencia = precioDif(precioAereo,precioLatam);
            }
            break;

        case 4:
            if( flagkm == 1 || precioIngresado == 1) // ACA MUESTRA EN PANTALLA
            {
                printf("***LATAM:***\n \n");
                printf("El precio con tarjeta de debito es : %.2f\n", precio_Debit_Aereo);
                printf("El precio con tarjeta de credito es :%.2f\n", precio_Credito_Aereo);
                printf("El precio pagando con bitcoin es :%.2f\n",precio_Credito_Latam);
                printf("El precio unitario es: %.2f\n\n", precio_km_Aereo);

                printf("***Aereolineas:***\n \n");
                printf("El precio con tarjeta de debito es : %.2f\n",precio_Debit_Latam);

                printf("El precio con tarjeta de credito es: %.2f\n", precio_Bitcoin_Aereo);
                printf("El precio pagando con bitcoin es: %.2f\n",precio_Bitcoin_Latam);
                printf("El precio unitario es : %.2f\n\n", precio_km_Latam);

                printf("La diferencia de precio es :%.2f\n", precio_diferencia);
            }
            else
            {
                printf("ingrese primero los km y luego los precios\n");
            }
            break;

        case 5: // CARGA FORZADA
         {
             precio_Debit_Aereo_forzado =  calculosdebito(Aerolineas_forzado);
             precio_Credito_Aereo_forzado = calculosCredito(Aerolineas_forzado);
             precio_Bitcoin_Aereo_forzado =  calculoBitcoin(Aerolineas_forzado);
             precio_km_Aereo_forzado = calculoskm(Aerolineas_forzado,km_forzado);

             precio_Debit_Latam_forzado =  calculosdebito (latam_forzado);
             precio_Credito_Latam_forzado =  calculosCredito(latam_forzado);
             precio_Bitcoin_Latam_forzado =  calculoBitcoin(latam_forzado);
             precio_km_Latam_forzado = calculoskm(latam_forzado,km_forzado);

             precio_diferencia_forzado = precioDif(Aerolineas_forzado,latam_forzado);

            printf("***precio Aereolineas:***\n \n");

            printf("El precio con tarjeta de debito es : %.2f\n", precio_Debit_Aereo_forzado );
            printf("El precio con tarjeta de credito es :%.2f\n", precio_Credito_Aereo_forzado);
            printf("El precio pagando con bitcoin es :%.4f\n",precio_Bitcoin_Aereo_forzado);
            printf("El precio unitario es: %.2f\n\n", precio_km_Aereo_forzado);

            printf("*** precio LATAM:***\n \n");
            printf("El precio con tarjeta de debito es : %.2f\n",precio_Debit_Latam_forzado);
            printf("El precio con tarjeta de credito es: %.2f\n", precio_Credito_Latam_forzado);
            printf("El precio pagando con bitcoin es: %.4f\n",precio_Bitcoin_Latam_forzado);
            printf("El precio unitario es : %.2f\n\n", precio_km_Latam_forzado);



            printf("La diferencia de precio es :%.2f\n", precio_diferencia_forzado);


        }
        break;

    case 6:
        salir(&seguir);
        break;

    default:
        {
            break;
        }
    }
    system("pause");
}
while (seguir != 's');

	return EXIT_SUCCESS;
}

int menu()
{

    int cant;
    int opcion;



    printf("\n\n*** Menu de Opciones ***\n \n");
    printf("1_ Ingresar Kilometros: \n");
    printf("2_ Ingresar precios de vuelos(Aerolineas/latam)\n");
    printf("3_ Calcular todos los costos:\n");
    printf("_a) Tarjeta de debito (descuento 10%%)\n");
    printf("_b) Tarjeta de credito (interes 25%%)\n");
    printf("_c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
    printf("_d) Mostrar precio por km (precio unitario)\n");
    printf("_e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n");
    printf("4_ Informar resultados\n");
    printf("5_ carga forzada de datos \n");
    printf("6_ salir \n");
    printf("eligir opcion: ");

    fflush(stdin);
    cant = scanf("%d", &opcion);

    if(cant == 0)
    {

        opcion = 7;
    }

    return opcion;

}


int km(int * pflag)
{

    int km;
    int auxkm;

    if (pflag != NULL)
    {

        printf("ingrese los Kilometros del vuelo: \n");
        auxkm = scanf("%d",&km);

        while(km<=0 || auxkm == 0)//VALIDACIONES PARA KM
        {
            fflush(stdin);
            printf("ERROR! ingresar nuevamente los kilometros: \n");
            scanf("%d", &km);

            auxkm = km;
        }

        *pflag = 1;


    }
    return km;
}

void salir(char * x)
{
    printf("Confirma salida?: ");
    fflush(stdin);
    scanf("%c", x);

}
