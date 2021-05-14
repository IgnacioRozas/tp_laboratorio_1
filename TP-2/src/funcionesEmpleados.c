/*
 * funcionesEmpleados.c
 *
 *  Created on: 12 may. 2021
 *      Author: Ignacio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesEmpleados.h"
#include "funcionesInput.h"
#include "funcionesMenu.h"

int inicializarEmpleados (eEmpleados array[], int largoArray){
	int retorno = -1;
	int i;

	if(array != NULL && largoArray > 0){
		retorno = 0;
		for(i=0; i<largoArray; i++){
			array[i].isEmpty = 1;
		}
	}
	return retorno;
}

int encontrarIndexVacio (eEmpleados array[], int largoArray){
	int retorno = -1;
	int i;

	if(array != NULL && largoArray > 0){
		for(i=0; i<largoArray; i++){
			if(array[i].isEmpty == 1){
				retorno = i;
			}
		}
	}
	return retorno;
}

int encontrarEmpleadoPorID (eEmpleados array[], int largoArray, int idBuscado){
	int retorno = -1;
	int i;

	if(array != NULL && largoArray >0 && idBuscado >0){
		for(i=0; i<largoArray; i++){
			if(array[i].isEmpty == 1){
				continue;
			}else{
				if(array[i].id == idBuscado){
					retorno = i;
				}
			}
		}
	}
	return retorno;
}

int pedirDatosEmpleado(eEmpleados array[], int largoArray, int *contadorID){
	int retorno = -1;

	char auxNombre [51];
	char auxApellido [51];
	float auxSalario;
	int auxSector;
	int auxID;

	if(array != NULL && largoArray>0 && contadorID != NULL){
		if(pedirNombre("Ingrese nombre del empleado: ", "Nombre no valido. ", 1, sizeof(auxNombre), 3, auxNombre) == 0 &&
				pedirNombre("Ingrese apellido del empleado: ","Apellido no valido. ", 1, sizeof(auxApellido), 3, auxApellido) == 0 &&
				pedirNumeroEntero(&auxSector, "Ingrese numero de sector del empleado: ", "Sector no valido. ", 1, 5, 3) == 0 &&
				pedirNumeroFlotante(&auxSalario, "Ingrese salario del empleado: ", "Salario no valido. ", 30000, 100000, 3) == 0){

			(*contadorID) += 1;
			auxID = *contadorID;
			if(agregarEmpleado(array, largoArray, auxID, auxNombre, auxApellido, auxSalario, auxSector) == 0){
				retorno = 0;
			}
		}
	}

	return retorno;
}

int agregarEmpleado(eEmpleados array[], int largoArray, int id, char nombre[], char apellido[], float salario, int sector){
	int retorno = -1;
	int indexVacio = encontrarIndexVacio(array, largoArray);
	if (array != NULL && largoArray > 0){
		if(indexVacio != -1){
			retorno = 0;
			strcpy(array[indexVacio].nombre, nombre);
			strcpy(array[indexVacio].apellido, apellido);
			array[indexVacio].id = id;
			array[indexVacio].salario = salario;
			array[indexVacio].sector = sector;
			array[indexVacio].isEmpty = 0;
		}
	}else{
		printf("\n No hay lugares vacios para cargar datos!\n");
	}
	return retorno;
}

int modificarEmpleado(eEmpleados array[], int largoArray, int idEmpleado){
	int retorno = -1;
	int indexEmpleado = encontrarEmpleadoPorID(array, largoArray, idEmpleado);
	char auxNombre[51];
	char auxApellido [51];
	float auxSalario;
	int auxSector;
	int opcionModificacion;

	if (array != NULL && largoArray > 0 && idEmpleado > 0){
		if (indexEmpleado != -1) {
			system("CLS");
			menuModificaciones();
			if (pedirNumeroEntero(&opcionModificacion, "Ingrese la opcion deseada: ", "Opcion no valida. ", 1, 4, 3) == 0) {
				switch (opcionModificacion){
				case 1:
					system("CLS");
					printf("Modificar nombre: \n");
					if (pedirNombre("Ingrese nombre: ", "Nombre no valido. ", 1, sizeof(auxNombre), 3, auxNombre) == 0){
						retorno = 0;
						strcpy(array[indexEmpleado].nombre, auxNombre);
					}else{
						printf("No se pudo modificar el nombre!. ");
					}
					break;

				case 2:
					system("CLS");
					printf("Modificar apellido: \n");
					if (pedirNombre("Ingrese apellido: ", "Apellido no valido. ", 1, sizeof(auxApellido), 3, auxApellido) == 0){
						retorno = 0;
						strcpy(array[indexEmpleado].apellido, auxApellido);
					}else{
						printf("No se pudo modificar el apellido!. ");
					}
					break;
				case 3:
					system("CLS");
					printf("Modificar salario: \n");
					if(pedirNumeroFlotante(&auxSalario, "Ingrese salario: ", "Salario no valido. ", 30000, 100000, 3) == 0){
						retorno = 0;
						array[indexEmpleado].salario = auxSalario;
					}else{
						printf("No se pudo modificar el salario. ");
					}
					break;

				case 4:
					system("CLS");
					printf("Modificar sector: \n");
					if(pedirNumeroEntero(&auxSector, "Ingrese sector: ", "Sector no valido. ", 1, 5, 3) == 0){
						retorno = 0;
						array[indexEmpleado].sector = auxSector;
					}else{
						printf("No se pudo modificar el sector.");
					}
					break;
				}
			}
		}
	}else{
			printf("No se encontro al empleado\n");
	}
	return retorno;
}

int imprimirEmpleados(eEmpleados array[], int largoArray){
	int retorno = -1;
	int i;

	if(array != NULL && largoArray > 0){
		printf("Lista de empleados: \n");
		for(i=0; i<largoArray; i++){
			if(array[i].isEmpty == 0){
				retorno = 0;
				printf("ID empleado: %d || Nombre: %s || Apellido: %s || Sector: %d || Salario: %.2f\n",
						array[i].id, array[i].nombre, array[i].apellido, array[i].sector, array[i].salario);
			}
		}
	}

	return retorno;
}

int bajaEmpleado (eEmpleados array[], int largoArray, int idEmpleado) {
	int retorno = -1;
	int posicionARemover = encontrarEmpleadoPorID(array, largoArray, idEmpleado);
	if (array != NULL && largoArray > 0 && idEmpleado > 0) {
		if (posicionARemover != -1) {
			retorno = 0;
			array[posicionARemover].isEmpty = 1;
		}
	}
	return retorno;
}

int ordenarEmpleadosApellidoSector(eEmpleados array[], int largoArray, int orden){
	int retorno = -1;
	int i;
	int j;
	eEmpleados auxEmpleado;
	if(orden == 0){
		if (array != NULL && largoArray > 0) {
			retorno = 0;
			for (i = 0; i < largoArray - 1; i++) {
				for (j = i + 1; j < largoArray; j++) {
					if (strcmp(array[i].apellido, array[j].apellido) < 0) {
						auxEmpleado = array[i];
						array[i] = array[j];
						array[j] = auxEmpleado;
					} else if (strcmp(array[i].apellido, array[j].apellido) == 0) {
						if (array[i].sector < array[j].sector) {
							auxEmpleado = array[i];
							array[i] = array[j];
							array[j] = auxEmpleado;
						}
					}
				}
			}
		}
	}else if(orden == 1){
		if (array != NULL && largoArray > 0) {
			retorno = 0;
			for (i = 0; i < largoArray - 1; i++) {
				for (j = i + 1; j < largoArray; j++) {
					if (strcmp(array[i].apellido, array[j].apellido) > 0) {
						auxEmpleado = array[i];
						array[i] = array[j];
						array[j] = auxEmpleado;
					} else if (strcmp(array[i].apellido, array[j].apellido) == 0) {
						if (array[i].sector > array[j].sector) {
							auxEmpleado = array[i];
							array[i] = array[j];
							array[j] = auxEmpleado;
						}
					}
				}
			}
		}
	}

	return retorno;
}

int listadoSueldos(eEmpleados array[], int largoArray){
	int retorno = -1;
	int i;
	float totalSalario = 0;
	int cantidadSalarios = 0;
	float promedioSalario;
	int empleadosQueSuperanElPromedio = 0;

	if(array != NULL && largoArray>0){
		for(i=0;i<largoArray;i++){
			if(array[i].isEmpty == 0){
				totalSalario += array[i].salario;
				cantidadSalarios ++;
			}
		}
		promedioSalario = totalSalario/cantidadSalarios;
		for(i=0;i<largoArray;i++){
			if(array[i].isEmpty == 0){
				if(array[i].salario > promedioSalario){
					empleadosQueSuperanElPromedio ++;
				}
			}
		}
		retorno = 0;
		printf("El total de los salarios es: %.2f || Promedio salarial: %.2f || Empleados que superan el salario promedio: %d",
				totalSalario, promedioSalario, empleadosQueSuperanElPromedio);
	}

	return retorno;
}

int verificarCargas(eEmpleados array[], int largoArray, int *flagCarga){
	int retorno = -1;
	int empleadosCargados = 0;
	int i;

	if(array!=NULL && largoArray > 0 && flagCarga != NULL){
		retorno = 0;
		for(i=0;i<largoArray;i++){
			if(array[i].isEmpty == 0){
				empleadosCargados++;
			}
		}
		if(empleadosCargados == 0){
			(*flagCarga) = 0;
		}
	}
	return retorno;
}
