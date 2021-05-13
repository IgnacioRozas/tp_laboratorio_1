/*
 * funcionesMenu.c
 *
 *  Created on: 13 may. 2021
 *      Author: Ignacio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuEmpleados() {
	printf("Opcion 1: Alta de empleado.\n");
	printf("Opcion 2: Modificar datos de empleado.\n");
	printf("Opcion 3: Baja de empleado.\n");
	printf("Opcion 4: Informes: \n");
	printf("Opcion 5: Salir.\n");
}

void menuModificaciones(){
	printf("Opcion 1: Modificar nombre. \n");
	printf("Opcion 2: Modificar apellido. \n");
	printf("Opcion 3: Modificar salario. \n");
	printf("Opcion 4: Modificar sector. \n");
}

void menuInformes(){
	printf("Opcion 1: Listado de empleados ordenados alfabeticamente por apellido y sector.");
	printf("Opcion 2: Total y promedio de los salarios. Recuento de empleados que superan el salario promedio.");
}
