/*
1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main(void) {

	setbuf(stdout,NULL);


	int opcion;
	float km=0;
	int flag =0;

	float PrecioIngresadoAerolineas=0;
	float ResultadoDebitoAerolineas=0;
	float ResultadoCreditoAerolineas=0;
	float ResultadoBitcoinAerolineas=0;
	float ResultadoPrecioUnitarioAerolineas=0;

	float PrecioIngresadoLatam=0;
	float ResultadoDebitoLatam=0;
	float ResultadoCreditoLatam=0;
	float ResultadoBitcoinLatam=0;
	float ResultadoPrecioUnitarioLatam=0;

	float ResultadoDiferencia=0;


		do{
			printf( "1. Ingresar Kilómetros: (km = %.2f)\n",km );
			printf( "2. Ingresar precio de vuelos: (Aerolineas = %.2f , Latam = %.2f) \n",PrecioIngresadoAerolineas,PrecioIngresadoLatam );
			printf( "3. Calcular los costos: \n" );
			printf( "a) Tarjeta de débito. Descuento 10%%\n");
			printf( "b) Tarjeta de crédito. Interes 25%%\n");
			printf( "c) Bitcoin (1BTC -> 4606964.55 Pesos Argentinos)\n" );
			printf( "d) Mostrar precio por km (precio unitario)\n" );
			printf( "e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n" );
			printf( "4. Informar resultados. \n" );
			printf( "5. Carga forzada de datos. \n" );
			printf( "6. Salir \n" );
			scanf("%d", &opcion);


			if(opcion >= 1 && opcion <= 6)
			{

				switch(opcion)
							{

							case 1:
								printf("1. Ingresar Kilómetros: \n");
								scanf("%f",&km);
								flag=1;

									while(km <= 0){
									printf("Error.\nIngrese valor positivo. Mayor a 0.\n");
									scanf("%f",&km);
									}
							break;

							case 2:
								if(flag==1){
									printf("Ingrese precio de Aerolineas.\n");
									scanf("%f",&PrecioIngresadoAerolineas);
									printf("Ingrese precio de Latam.\n");
									scanf("%f",&PrecioIngresadoLatam);
									flag=0;
								}
								else
								{
									printf("Dato invalido.\nIngrese los km.");
								}

							break;

							case 3:

								if(flag==0){

									printf("Calculando.\n");

									ResultadoDebitoAerolineas= Debito(PrecioIngresadoAerolineas);
									ResultadoDebitoLatam= Debito(PrecioIngresadoLatam);

									ResultadoCreditoAerolineas= Credito(PrecioIngresadoAerolineas);
									ResultadoCreditoLatam= Credito(PrecioIngresadoLatam);

									ResultadoBitcoinAerolineas= Bitcoin(PrecioIngresadoAerolineas);
									ResultadoBitcoinLatam= Bitcoin(PrecioIngresadoLatam);

									ResultadoPrecioUnitarioAerolineas= PrecioUnitario(PrecioIngresadoAerolineas, km);
									ResultadoPrecioUnitarioLatam= PrecioUnitario(PrecioIngresadoLatam, km);

									ResultadoDiferencia= Diferencia(PrecioIngresadoAerolineas,PrecioIngresadoLatam);

									flag=1;
								}
								else
								{
									printf("Dato invalido.\nIngrese los datos correspondientes.");
								}

							break;

							case 4:
								if(flag==1){

									printf("4.Informar resultados: \n");

									printf("Latam: \n");
									printf("a)Precio con tarjeta de debito: $%.2f\n",ResultadoDebitoLatam);
									printf("b)Precio con tarjeta de credito: $%.2f\n",ResultadoCreditoLatam);
									printf("c)Precio pagando con Bitcoin: $%.8f BTC\n",ResultadoBitcoinLatam);
									printf("d)Precio unitario: $%.2f\n",ResultadoPrecioUnitarioLatam);

									printf("\nAerolineas: \n");
									printf("a)Precio con tarjeta de debito: $%.2f\n",ResultadoDebitoAerolineas);
									printf("b)Precio con tarjeta de credito: $%.2f\n",ResultadoCreditoAerolineas);
									printf("c)Precio pagando con Bitcoin: $%.8f BTC\n",ResultadoBitcoinAerolineas);
									printf("d)Precio unitario: $%.2f\n",ResultadoPrecioUnitarioAerolineas);

									printf("\nLa diferencia de precio es: $%.2f\n\n",ResultadoDiferencia);


									flag=0;
								}
								else
								{
									printf("Dato invalido.\nIngrese los datos correspondientes.");
								}

							break;

							case 5:

								km= 7090;
								PrecioIngresadoAerolineas= 162965;
								PrecioIngresadoLatam= 159339;

								ResultadoDebitoLatam= Debito(PrecioIngresadoLatam);
								ResultadoCreditoLatam= Credito(PrecioIngresadoLatam);
								ResultadoBitcoinLatam= Bitcoin(PrecioIngresadoLatam);
								ResultadoPrecioUnitarioLatam= PrecioUnitario(PrecioIngresadoLatam,km);

								ResultadoDebitoAerolineas= Debito(PrecioIngresadoAerolineas);
								ResultadoCreditoAerolineas= Credito(PrecioIngresadoAerolineas);
								ResultadoBitcoinAerolineas= Bitcoin(PrecioIngresadoAerolineas);
								ResultadoPrecioUnitarioAerolineas= PrecioUnitario(PrecioIngresadoAerolineas,km);

								ResultadoDiferencia= Diferencia(PrecioIngresadoAerolineas, PrecioIngresadoLatam);

								printf("\nKm ingresados: 7090km\n");

								printf("\nPrecio Aerolineas: $162965\n");
								printf("a)Precio con tarjeta de debito: $%.2f\n",ResultadoDebitoLatam);
								printf("b)Precio con tarjeta de credito: $%.2f\n",ResultadoCreditoLatam);
								printf("c)Precio pagando con Bitcoin: $%.8f\n",ResultadoBitcoinLatam);
								printf("d)Mostrar precio unitario: $%.2f\n",ResultadoPrecioUnitarioLatam);

								printf("\nPrecio Latam: $159339\n");
								printf("a)Precio con tarjeta de debito: $%.2f\n",ResultadoDebitoAerolineas);
								printf("b)Precio con tarjeta de credito: $%.2f\n",ResultadoCreditoAerolineas);
								printf("c)Precio pagando con Bitcoin: $%.8f BTC\n",ResultadoBitcoinAerolineas);
								printf("d)Mostrar precio unitario: $%.2f\n",ResultadoPrecioUnitarioAerolineas);

								printf("\nLa diferencia de precio es: $%.2f\n\n\n\n\n\n",ResultadoDiferencia);


							break;

							case 6:
								printf("Gracias. \n");
							break;
							}
			}
			else
			{
				printf("\nIngrese un valor acorde al menu por favor.\n\n");
			}


		}while(opcion != 6);



		return EXIT_SUCCESS;

}
