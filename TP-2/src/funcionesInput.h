/*
 * funcionesInput.h
 *
 *  Created on: 12 may. 2021
 *      Author: Ignacio
 */

#ifndef FUNCIONESINPUT_H_
#define FUNCIONESINPUT_H_

// Pedir numero entero:

int pedirNumeroEntero (int *pResultado, char *mensaje , char *mensajeError, int minimo, int maximo, int reintentos);

int obtenerEntero (int *pResultado);

int esNumerica(char *cadena, int largoCadena);


// Pedir numero flotante:

int pedirNumeroFlotante (float *pResultado, char *mensaje , char *mensajeError, int minimo, int maximo, int reintentos);

int obtenerNumeroFlotante (float *pResultado);

int esNumericaFlotante (char *cadena, int largoCadena);


// Pedir string

int pedirNombre(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* resultado);

int esNombre(char* cadena);


// Funcion myGets

int miGets(char *cadena, int largoCadena);

#endif /* FUNCIONESINPUT_H_ */
