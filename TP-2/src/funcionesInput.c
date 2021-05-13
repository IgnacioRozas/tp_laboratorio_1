/*
 * funcionesInput.c
 *
 *  Created on: 12 may. 2021
 *      Author: Ignacio
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesInput.h"
#include "funcionesEmpleados.h"

int pedirNumeroEntero (int *pResultado, char *mensaje , char *mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 ){
		do{
			printf("%s", mensaje);
			if(obtenerEntero(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo){
				retorno = 0;
				*pResultado = bufferInt;
				break;
			}else{
			printf("%s",mensajeError);
			reintentos --;
			}

		}while(reintentos>=0);
	}

	return retorno;
}

int obtenerEntero (int *pResultado){
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL && miGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString)) == 1){
			*pResultado = atoi(bufferString);
			retorno = 0;
	}

	return retorno;
}

int esNumerica (char *cadena, int largoCadena){
	int retorno = 1;
	int i;

	for(i=0; i<largoCadena && cadena [i] != '\0'; i++){
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
			continue;
		}
		if(cadena[i]>'9' || cadena[i] < '0'){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int pedirNumeroFlotante (float *pResultado, char *mensaje , char *mensajeError, int minimo, int maximo, int reintentos){
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 ){
		do{
			printf("%s", mensaje);
			if(obtenerNumeroFlotante(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo){
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			printf("%s",mensajeError);
			reintentos --;

		}while(reintentos>=0);
	}

	return retorno;
}

int obtenerNumeroFlotante (float *pResultado){
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL && miGets(bufferString,sizeof(bufferString)) == 0 && esNumericaFlotante(bufferString,sizeof(bufferString)) == 1){
			*pResultado = atof(bufferString);
			retorno = 0;
	}

	return retorno;
}

int esNumericaFlotante (char *cadena, int largoCadena){
	int retorno = 1;
	int i;

	for(i=0; i<largoCadena && cadena [i] != '\0'; i++){
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-')){
			continue;
		}
		if((cadena[i]>'9' || cadena[i] < '0') && cadena[i] != '.'){
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int pedirNombre(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* resultado){
    int retorno = -1;
    char bufferString[max];

    if(mensaje!=NULL && mensajeError!=NULL && min<=max && reintentos>=0 && resultado!=NULL){
        do{
        	printf("%s", mensaje);
            if(miGets(bufferString,sizeof(bufferString)) == 0){
                if(esNombre(bufferString)==1){
                    strncpy(resultado,bufferString,max);
                    retorno=0;
                    break;
                }else{
                    printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int esNombre(char* cadena){
    int retorno = 1;
    int i;
    for(i=0; cadena[i] !='\0';i++){
    	if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' ||cadena[i]>'z')){
    		retorno=0;
            break;
        }
    }
    return retorno;
}

int miGets (char *cadena, int largoCadena){
	int retorno = -1;
	char bufferString[largoCadena+10];

	if(cadena != NULL && largoCadena >0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= largoCadena){
				strncpy(cadena,bufferString,largoCadena);
				retorno = 0;
			}
		}
	}
	return retorno;
}
