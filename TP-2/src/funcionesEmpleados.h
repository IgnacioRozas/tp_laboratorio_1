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
/**
 * @fn int inicializarEmpleados(eEmpleados[], int)
 * @brief Pone el campo isEmpty de la estructura empleados en 1 para indicar que todos los campos estan vacios.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @return Retorna -1 si hay un error (Largo del array no valido o el puntero al array es NULO) y 0 si funciona correctamente.
 */
int inicializarEmpleados (eEmpleados array[], int largoArray);


/**
 * @fn int encontrarIndexVacio(eEmpleados[], int)
 * @brief Busca dentro del array una posicion cuyo campo isEmpty este en 1 para poder cargarle datos.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @return Retorna -1 si hay un error (Largo del array no valido, el puntero al array es NULO, o si no hay espacio disponible para
 *         cargar datos[todos los campos isEmpty estan en 0]) o retorna el primer indice del array en el que el campo isEmpty es 1.
 */
int encontrarIndexVacio (eEmpleados array[], int largoArray);


/**
 * @fn int encontrarEmpleadoPorID(eEmpleados[], int, int)
 * @brief Busca dentro del array empleados el indice en la que el idBuscado coincida con el id cargado y devuelve el indice en el que lo encontro.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @param idBuscado - id del empleado cuyo indice se desea encontrar.
 * @return Retorna -1 si hay un error (Largo del array no valido, el puntero al array es NULO o si no se encontro el ID) o retorna el indice en el que
 *         se encontro el id buscado.
 */
int encontrarEmpleadoPorID (eEmpleados array[], int largoArray, int idBuscado);


/**
 * @fn int pedirDatosEmpleado(eEmpleados[], int, int*)
 * @brief Pide los datos de los empleados y luego se los pasa a la funcion agregarEmpleado() para que los cargue si es que no hubo errores.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @param contadorID - Puntero al contador de ID incremental.
 *
 * @return Retorna -1 si hay un error (Largo del array no valido, el puntero al array es NULO o si la funcion agregarEmpleado() no pudo cargar los datos)
 * 		   o retorna 0 si se pudieron cargar los datos correctamente.
 */
int pedirDatosEmpleado(eEmpleados array[], int largoArray, int *contadorID);


/**
 * @fn int agregarEmpleado(eEmpleados[], int, int, char[], char[], float, int)
 * @brief Recibe por parametro los datos a cargar dentro de la estructura Empleados y los carga.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @param id - Id a cargar dentro de la estructura empleados.
 * @param nombre - Nombre a cargar dentro de la estructura empleados.
 * @param apellido - Apellido a cargar dentro de la estructura empleados.
 * @param salario - Salario a cargar dentro de la estructura empleados.
 * @param sector - Sector a cargar dentro de la estructura empleados.
 * @return Retorna -1 si hay un error (Largo del array no valido, el puntero al array es NULO o si no hay espacio libre para cargar los datos) o
 *         0 si se pudieron cargar los datos correctamente.
 */
int agregarEmpleado(eEmpleados array[], int largoArray, int id, char nombre[], char apellido[], float salario, int sector);


/**
 * @fn int modificarEmpleado(eEmpleados[], int, int)
 * @brief Le desplega al usuario un menu de modificaciones entre las que puede elegir modificar el nombre, apellido, sector y salario de un
 * 	      empleado.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @param idEmpleado - ID del empleado al que se le desean modificar los datos.
 * @return Retorna -1 si hay un error (Largo del array no valido, el puntero al array es NULO o si el ID ingresado no es valido) o retorna
 *         0 si se pudieron modificar los datos correctamente.
 */
int modificarEmpleado(eEmpleados array[], int largoArray, int idEmpleado);


/**
 * @fn int imprimirEmpleados(eEmpleados[], int)
 * @brief Recorre el array en busca de campos isEmpty cuyo valor sea 0 e imprime sus datos.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @return Retorna -1 si hay un error (Largo del array no valido o el puntero al array es NULO)
 */
int imprimirEmpleados(eEmpleados array[], int largoArray);


/**
 * @fn int bajaEmpleado(eEmpleados[], int, int)
 * @brief Realiza una baja logica (pone el campo isEmpty en 1) al empleado cuyo ID se pasa por parametro.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @param idEmpleado - ID que se desea dar de baja.
 * @return Retorna -1 si hay error (Largo del array no valido, el puntero al array es NULO o si el ID ingresado no es valido)
 * 	       o 0 si se pudo realizar la baja.
 */
int bajaEmpleado (eEmpleados array[], int largoArray, int idEmpleado);


/**
 * @fn int ordenarEmpleadosApellidoSector(eEmpleados[], int, int)
 * @brief Ordena en orden ascendente o descendente (a eleccion del usuario) los empleados segun el apellido, o en caso de igualdad segun el sector.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @param orden - Argumento segun el que se desea ordenar a los empleados (0: descendente / 1: ascendente)
 * @return Retorna -1 si hay error (Largo del array no valido o el puntero al array es NULO) o 0 si se pudo realizar el orden.
 */
int ordenarEmpleadosApellidoSector(eEmpleados array[], int largoArray, int orden);


/**
 * @fn int listadoSueldos(eEmpleados[], int)
 * @brief Recorre el array y obtiene el salario total de los empleados ingresados, el salario promedio y la cantidad de los empleados que superan
 * 		  el salario promedio y luego imprime los datos por pantalla.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @return Retorna -1 si hay error(Largo del array no valido, el puntero al array es NULO) o 0 si se obtuvieron e imprimieron los datos correctamente.
 */
int listadoSueldos(eEmpleados array[], int largoArray);

/**
 * @fn int verificarCargas(eEmpleados[], int, int*)
 * @brief Recorre el array y verifica si hay empleados cargados. Si no los hay setea la variable flagCarga en 0 a traves de un puntero, para
 * 		  que el usuario no pueda modificar, dar de baja ni listar datos de empleados si no hay ninguno cargado.
 *
 * @param array - Puntero al array de empleados.
 * @param largoArray - Largo del array de empleados.
 * @param flagCarga - Puntero a la variable flagCarga.
 * @return Retorna -1 si hay error (Largo del array no valido, el puntero al array es NULO, el puntero a la variable flagCarga es NULO) o
 *  	   0 si no hay error.
 */
int verificarCargas(eEmpleados array[], int largoArray, int *flagCarga);
#endif /* FUNCIONESEMPLEADOS_H_ */
