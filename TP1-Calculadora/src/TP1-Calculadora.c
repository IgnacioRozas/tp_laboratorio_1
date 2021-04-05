/*
 ============================================================================
 Name        : TP1-Calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

int main(void) {
	setbuf(stdout,NULL);

	// Variables de las opciones del menu:

	int opcionMenu;
	char opcionSalida;

	// Variables de los operandos:

	float primerOperando = 0;
	float segundoOperando = 0;
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;

	// Resultado operaciones

	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	long int resultadoFactorialA;
	long int resultadoFactorialB;

	int flagOperacionesRealizadas = 0; // Para verificar si se realizaron las operaciones antes de mostrar los resultados.

	do{
		system("CLS");

		// Menu de opciones

		printf("Calculadora.\n\n");
		printf("1. Ingrese primer operando: %.1f\n", primerOperando);
		printf("2. Ingrese segundo operando: %.1f \n", segundoOperando);
		printf("3. Calcular todas las operaciones \n");
		printf("4. Informar resultados \n");
		printf("5. Salir \n");

		printf("\nIngrese la opcion deseada: ");
		scanf("%d", &opcionMenu);
		while(opcionMenu<1 || opcionMenu >5){
			printf("\nOpcion invalida. Ingrese nuevamente la opcion deseada:");
			scanf("%d", &opcionMenu);
		}

		// Opciones

		switch(opcionMenu){
		case 1:
			system("CLS");
			printf("Ingrese primer operando (A): ");
			scanf("%f",&primerOperando);
			flagPrimerOperando = 1;
			break;

		case 2:
			system("CLS");
			printf("Ingrese segundo operando (B): ");
			scanf("%f",&segundoOperando);
			flagSegundoOperando = 1;
			break;

		case 3:
			system("CLS");

			if(flagPrimerOperando == 1 && flagSegundoOperando == 1){
				printf("Calculando todas las operaciones: \n\n");

				printf("A. Suma (A+B) \n");
				resultadoSuma = sumar(primerOperando,segundoOperando);

				printf("B. Resta (A-B) \n");
				resultadoResta = restar(primerOperando,segundoOperando);

				printf("C. Division (A/B) \n");
				resultadoDivision = dividir(primerOperando,segundoOperando);

			    printf("D. Multiplicacion (A*B) \n");
			    resultadoMultiplicacion = multiplicar(primerOperando,segundoOperando);

			    printf("E. Factorial (A!/B!) \n\n");
			    resultadoFactorialA = encontrarFactorial(primerOperando);
			    resultadoFactorialB = encontrarFactorial(segundoOperando);

			    flagOperacionesRealizadas = 1;

			}else if(flagPrimerOperando == 1 && flagSegundoOperando == 0){
				printf("Necesita ingresar el segundo operando para realizar las operaciones\n\n");
			}else if(flagPrimerOperando == 0 && flagSegundoOperando == 1){
				printf("Necesita ingresar el primer operando para realizar las operaciones\n\n");
			}else if(flagPrimerOperando == 0 && flagSegundoOperando == 0){
				printf("Necesita ingresar ambos operandos para realizar las operaciones\n\n");
			}

			system("PAUSE");

			break;

		case 4:
			system("CLS");
			if(flagOperacionesRealizadas == 0){
				printf("Debe calcular las operaciones (Opcion 3) antes de mostrar los resultados\n\n");
			}else{
				printf("Informar resultados: \n");
				printf("A. El resultado de la suma entre %.1f y %.1f es: %.2f \n", primerOperando, segundoOperando, resultadoSuma);
				printf("B. El resultado de la resta entre %.1f y %.1f es: %.2f \n", primerOperando, segundoOperando, resultadoResta);
				if(segundoOperando == 0){
					printf("C. La division no puede realizarse, ya que dividir por 0 es considerado una indefinicion matematica\n");
				}else{
					printf("C. El resultado de la division entre %.1f y %.1f es: %.2f \n", primerOperando, segundoOperando, resultadoDivision);
				}
				printf("D. El resultado de la multiplicacion entre %.1f y %.1f es: %.2f \n", primerOperando, segundoOperando, resultadoMultiplicacion);
				printf("E. El factorial de %.1f es: %ld\n"
						"   El factorial de %.1f es: %ld \n\n", primerOperando, resultadoFactorialA, segundoOperando, resultadoFactorialB);

				primerOperando = 0;
				segundoOperando = 0;
				flagPrimerOperando = 0;
				flagSegundoOperando = 0;
				flagOperacionesRealizadas = 0;
			}

			system("PAUSE");

			break;

		case 5:
			system("CLS");
			printf("Seguro que desea salir? Ingrese S para SI o N para NO: ");
			fflush(stdin);
			scanf("%c",&opcionSalida);
			while(opcionSalida != 'N' && opcionSalida != 'n' && opcionSalida != 'S' && opcionSalida != 's'){
				system("CLS");
				printf("Opcion NO valida. Ingrese nuevamente.\n Desea salir? S/N: ");
				fflush(stdin);
				scanf("%c",&opcionSalida);
			}
			break;
		}

	} while(opcionSalida != 'S' && opcionSalida != 's');

	return EXIT_SUCCESS;
}
