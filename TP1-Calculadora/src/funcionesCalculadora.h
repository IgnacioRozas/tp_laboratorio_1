/*
 * funcionesCalculadora.h
 *
 *  Created on: 4 abr. 2021
 *      Author: Ignacio
 */

#ifndef FUNCIONESCALCULADORA_H_
#define FUNCIONESCALCULADORA_H_

// Documentacion de funciones:

// Suma

/**
 * @fn float sumar(float, float)
 * @brief Realiza la suma entre dos numeros de tipo float que son ingresados por el usuario.
 *
 * @param primerOperando - numero ingresado por el usuario para realizar la operacion.
 * @param segundoOperando - numero ingresado por el usuario para realizar la operacion.
 *
 * @return Retorna el resultado de la suma realizada entre el primer y segundo operando.
 */

float sumar(float primerOperando, float segundoOperando);


// Resta

/**
 * @fn float restar(float, float)
 * @brief Realiza la resta entre dos numeros de tipo float que son ingresados por el usuario.
 *
 * @param primerOperando - numero ingresado por el usuario para realizar la operacion.
 * @param segundoOperando - numero ingresado por el usuario para realizar la operacion.
 *
 * @return Retorna el resultado de la resta realizada entre el primer y segundo operando.
 */

float restar(float primerOperando, float segundoOperando);

// Multiplicacion

/**
 * @fn float multiplicar(float, float)
 * @brief Realiza la multiplicacion entre dos numeros de tipo float que son ingresados por el usuario.
 *
 * @param primerOperando - numero ingresado por el usuario para realizar la operacion.
 * @param segundoOperando - numero ingresado por el usuario para realizar la operacion.
 *
 * @return Retorna el resultado de la multiplicacion realizada entre el primer y segundo operando.
 */

float multiplicar(float primerOperando, float segundoOperando);

// Division

/**
 * @fn float dividir(float, float)
 * @brief Realiza la division entre dos numeros de tipo float que son ingresados por el usuario.
 *
 * @param primerOperando - numero ingresado por el usuario para realizar la operacion.
 * @param segundoOperando - numero ingresado por el usuario para realizar la operacion.
 *
 * @return Retorna el resultado de la division realizada entre el primer y segundo operando.
 */

float dividir(float primerOperando, float segundoOperando);

// Factorial

/**
 * @fn long int encontrarFactorial(int)
 * @brief Encuentra el factorial del numero entregado por el usuario.
 *
 * @param numero - Numero ingresado por el usuario.
 *
 * @return Retorna el factorial del numero ingresado por el usuario.
 */

long int encontrarFactorial(int numero);

#endif /* FUNCIONESCALCULADORA_H_ */
