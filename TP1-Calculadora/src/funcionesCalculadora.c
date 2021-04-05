/*
 * funcionesCalculadora.c
 *
 *  Created on: 4 abr. 2021
 *      Author: Ignacio
 */

// Funcion suma

float sumar(float primerOperando, float segundoOperando){
	float suma;
	suma = primerOperando+segundoOperando;

	return suma;
}

// Funcion resta

float restar(float primerOperando, float segundoOperando){
	float resultadoResta;
	resultadoResta = primerOperando-segundoOperando;

	return resultadoResta;
}

// Funcion multiplicacion

float multiplicar(float primerOperando, float segundoOperando){
	float resultadoMultiplicacion;
	resultadoMultiplicacion = primerOperando*segundoOperando;

	return resultadoMultiplicacion;
}

// Funcion division

float dividir(float primerOperando, float segundoOperando){
	float resultadoDivision;
	resultadoDivision = primerOperando/segundoOperando;

	return resultadoDivision;
}

// Funcion factorial

long int encontrarFactorial(int numero) {

	long factorialNumero = 1;
	int i;
	for (i = 1; i <= numero; i++) {
		factorialNumero *= i;
	}

	return factorialNumero;
}

