/*
 * funcionesEmpleados.h
 *
 *  Created on: 12 may. 2021
 *      Author: Ignacio
 */

#ifndef FUNCIONESEMPLEADOS_H_
#define FUNCIONESEMPLEADOS_H_

// Estructura empleados

typedef struct{

	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;

}eEmpleados;

// Funciones

int inicializarEmpleados (eEmpleados array[], int largoArray);

int encontrarIndexVacio (eEmpleados array[], int largoArray);

int encontrarEmpleadoPorID (eEmpleados array[], int largoArray, int idBuscado);

int inicializarIdEmpleados (eEmpleados array[], int largoArray);

int pedirDatosEmpleado(eEmpleados array[], int largoArray, int *contadorID);

int agregarEmpleado(eEmpleados array[], int largoArray, int id, char nombre[], char apellido[], float salario, int sector);

int modificarEmpleado(eEmpleados array[], int largoArray, int idEmpleado);

int imprimirEmpleados(eEmpleados array[], int largoArray);
#endif /* FUNCIONESEMPLEADOS_H_ */
