/*
 ============================================================================
 Name        : TP-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesInput.h"
#include "funcionesEmpleados.h"
#include "funcionesMenu.h"

#define TAMEMPLEADOS 1000

int main(void) {

	// Variables
	eEmpleados arrayEmpleados [TAMEMPLEADOS];
	int opcionUsuario;
	int idEmpleadoModificacion;
	int contadorID = 0;
	int flagCarga = 0;

	// Inicializaciones
	inicializarEmpleados(arrayEmpleados, TAMEMPLEADOS);

	 // Menu principal:

	do{
		system("CLS");
		menuEmpleados();
		if(pedirNumeroEntero(&opcionUsuario, "\nIngrese la opcion deseada: ", "Opcion no valida. ", 1, 5, 3) == 0){
			switch(opcionUsuario){
			case 1:
				// Alta empleado.
				system("CLS");
				if(pedirDatosEmpleado(arrayEmpleados, TAMEMPLEADOS, &contadorID) == 0){
					printf("\nEmpleado cargado con exito!\n\n");
					flagCarga = 1;
				}else{
					printf("\nNo se pudo cargar el empleado!\n\n");
				}
				system("PAUSE");
				break;

			case 2:
				// Modificar empleado.
				system("CLS");
				if(flagCarga == 1){
					if(pedirNumeroEntero(&idEmpleadoModificacion, "Ingrese ID del empleado a modificar: ", "ID no valido. ", 1, 1000, 3) == 0){
						if(modificarEmpleado(arrayEmpleados, TAMEMPLEADOS, idEmpleadoModificacion) == 0){
							printf("Empleado modificado con exito. \n");
						}else{
							printf("No se pudieron modificar los datos.\n");
						}
					}
				}else{
					printf("No se pueden modificar datos sin antes haberlos cargado!\n");
				}
				system("PAUSE");
				break;

			case 3:
				// Baja empleado.
				system("CLS");
				if(flagCarga == 1){

				}else{
					printf("No se puede dar de baja un empleado sin antes haber cargado alguno!\n");
				}
				system("PAUSE");
				break;

			case 4:
				// Informes:
				system("CLS");
				if(flagCarga == 1){
					imprimirEmpleados(arrayEmpleados, TAMEMPLEADOS);
				}else{
					printf("No se pueden mostrar los informes sin antes haber cargado algun empleado!\n");				}
				system("PAUSE");
				break;

			case 5:
				// Salida.
				break;
			}
		}

	}while(opcionUsuario != 5);

	return EXIT_SUCCESS;
}


