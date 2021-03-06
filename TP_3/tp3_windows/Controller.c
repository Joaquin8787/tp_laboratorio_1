#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "joaquin.h"

int buscarEmpleadoId(int* idABuscar, LinkedList* pArrayListEmployee,int tam){
	int retorno = 1;
	int id;//id del empleado
	Employee* empleado;

	if(idABuscar != NULL && pArrayListEmployee != NULL && tam > 0){
		for(int i=0;i<tam;i++){
			empleado = (Employee*) ll_get(pArrayListEmployee, i); //tomo un empleado
			employee_getId(empleado,&id); //tomo su id
			if(*idABuscar == id){ //comparo el id que me dieron al que recibi del empleado
			retorno = i; //retorno el indice donde esta ese empelado
			break;
			}
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 1;
	FILE* auxP;
	if(path != NULL && pArrayListEmployee != NULL){
	auxP = fopen(path,"r");//LO LEO
	if(auxP != NULL){
		parser_EmployeeFromText(auxP ,pArrayListEmployee);
		retorno = 0;
	}
	else{
		printf("No se pudo leer el archivo");
	}
	}
	fclose(auxP);
    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	 int retorno = 1;
	FILE* auxP;
	if(path != NULL && pArrayListEmployee != NULL){
		auxP = fopen(path,"rb");//LO LEO EN MODO BINARIO
		if(auxP != NULL){
		parser_EmployeeFromBinary(auxP ,pArrayListEmployee);
		retorno = 0;
		}
		else{
		printf("No se pudo leer el archivo\n");
		}

	}
	fclose(auxP);
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id)
{
	int retorno = 1;

	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	Employee* nuevoEmpleado;

	if(pArrayListEmployee != NULL){
		if(joaquin_getString(nombre,"Ingrese el nombre del empleado","ERROR!!!\n",138,10)==1
		&&joaquin_getNumero(&horasTrabajadas,"Ingrese las horas trabajadas del empleado","ERROR!!!\n",1,300,10)==1
		&&joaquin_getNumero(&sueldo,"Ingrese el sueldo del empleado","ERROR!!!\n",1,10000000,10)==1){
			(*id)++;
			nuevoEmpleado = employee_newParametrosCorrespondientes(id,nombre,&horasTrabajadas,&sueldo);
		}
		if(nuevoEmpleado != NULL){
			ll_add(pArrayListEmployee, nuevoEmpleado);
			retorno = 0;
		}

	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int idABuscar;
	int tam;
	int posicion;
	char seguir = 's';

	char auxNombre[128];
	int auxHorasTrabajadas;
	int auxSueldo;
	Employee* empleadoParaModificar;

	if(pArrayListEmployee != NULL){
	tam	= ll_len(pArrayListEmployee); //TOMO EL LARGO DE LA LISTA
	//PIDO EL ID
	do{
		joaquin_getNumero(&idABuscar,"Ingrese el id del empleado que quiere modificar: \n","ERROR!!!\n",0,tam,10);
		posicion = buscarEmpleadoId(&idABuscar, pArrayListEmployee,tam);
		while(posicion == 1){
			printf("ERROR. El id ingresado no existe\n");
			joaquin_getNumero(&idABuscar,"Ingrese el id del empleado que quiere modificar: \n","ERROR!!!\n",0,tam,10);
			posicion = buscarEmpleadoId(&idABuscar, pArrayListEmployee,tam);
		}
			if(posicion != 1){
				//TOMO EL EMPLEADO DE LA LISTA PARA MODIFICARLO
				empleadoParaModificar = (Employee*) ll_get(pArrayListEmployee,posicion);
				printf("------------------------------------------------------------------------\n");
				printf("                       EMPLEADO A MODIFICAR                             \n");
				printf("------------------------------------------------------------------------\n");
				printf("ID              NOMBRE               HORAS TRABAJADAS             SUELDO\n");
				employee_showOneEmployee(empleadoParaModificar,posicion);
				printf("------------------------------------------------------------------------\n");

				if(empleadoParaModificar != NULL){
					switch(menuModificaciones()){
					case 1:
					printf("---- NOMBRE ----\n");
					if(joaquin_getString(auxNombre,"Ingrese el nombre del empleado","ERROR!!!\n",138,10)==1){
					employee_setNombre(empleadoParaModificar,auxNombre);
					printf("Se ha modificado el nombre con exito!!!\n");
					}
					break;
					case 2:
					printf("---- HORAS TRABAJADAS ----\n");
					if(joaquin_getNumero(&auxHorasTrabajadas,"Ingrese las horas trabajadas del empleado","ERROR!!!\n",1,300,10)==1){
					employee_setHorasTrabajadas(empleadoParaModificar,auxHorasTrabajadas);
					printf("Se han modificado las horas trabajadas con exito!!!\n");
					}
					break;
					case 3:
					printf("---- SUELDO ----\n");
					if(joaquin_getNumero(&auxSueldo,"Ingrese las horas trabajadas del empleado","ERROR!!!\n",1,300,10)==1){
					employee_setSueldo(empleadoParaModificar,auxSueldo);
					printf("Se ha modificado el sueldo con exito!!!\n");
					}
					break;
					}
				}

			}
	joaquin_getCaracter(&seguir,"Quiere modificar otro empleado? (s/n): ","ERROR!!! \n",'n','s',5);
	}while(seguir == 's');

	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int idABuscar;
	int posicion;
	int tam;
	char seguir = 's';
	char confirmar;
	Employee* empleadoParaEliminar;

	if(pArrayListEmployee != NULL){
		tam	= ll_len(pArrayListEmployee);//TOMO EL LARGO DE LA LISTA
do{
	joaquin_getNumero(&idABuscar,"Ingrese el id del empleado que quiere eliminar: \n","ERROR!!!\n",0,tam,10);
			posicion = buscarEmpleadoId(&idABuscar, pArrayListEmployee,tam);
			while(posicion == 1){
			printf("ERROR. El id ingresado no existe\n");
			joaquin_getNumero(&idABuscar,"Ingrese el id del empleado que quiere eliminar: \n","ERROR!!!\n",0,tam,10);
			posicion = buscarEmpleadoId(&idABuscar, pArrayListEmployee,tam);
			}
			if(posicion != 1){
			//TOMO EL EMPLEADO DE LA LISTA PARA ELIMINARLO
			empleadoParaEliminar = (Employee*) ll_get(pArrayListEmployee,posicion);

			if(empleadoParaEliminar != NULL){
				printf("------------------------------------------------------------------------\n");
				printf("                       EMPLEADO A ELIMINAR                            \n");
				printf("------------------------------------------------------------------------\n");
				printf("ID              NOMBRE               HORAS TRABAJADAS             SUELDO\n");
				employee_showOneEmployee(empleadoParaEliminar,posicion);
				printf("------------------------------------------------------------------------\n");
				}
				joaquin_getCaracter(&confirmar,"Esta seguro que quiere eliminar este empleado? (s/n): ","ERROR!!! \n",'n','s',5);
				if(confirmar == 's'){
				employee_delete(empleadoParaEliminar);
				ll_remove(pArrayListEmployee,posicion);
				printf("Se ha eliminado el empleado con exito!!!\n");
				}
			}
joaquin_getCaracter(&seguir,"Quiere eliminar otro empleado? (s/n): ","ERROR!!! \n",'n','s',5);
}while(seguir == 's');
}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	Employee* empleado;
	if(pArrayListEmployee != NULL){
		printf("------------------------------------------------------------------------\n");
		printf("                       LISTA DE EMPLEADOS                               \n");
		printf("------------------------------------------------------------------------\n");
		printf("ID              NOMBRE               HORAS TRABAJADAS             SUELDO\n");
		for(int i= 0; i<ll_len(pArrayListEmployee);i++){
		empleado = (Employee*)ll_get(pArrayListEmployee,i);
		employee_showOneEmployee(empleado, i);
	 }
	}
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int order;
	if(pArrayListEmployee != NULL){
		switch(menuOrdenamiento())
				{
			case 1:
				  order = menuOrder();
				  printf("ORDENANDO...\n");
            	  if(!ll_sort(pArrayListEmployee,employee_compareById,order)){
            		  retorno = 1;
            		  printf("Lista ordenada!!!\n");
            	  }
            	  else{
            	  printf("Hubo algun problema al ordenar la lista\n");
            	  }
			break;
			case 2:
				  order = menuOrder();
				  printf("ORDENANDO...\n");
				  if(!ll_sort(pArrayListEmployee,employee_compareByNombre,order)){
					  retorno = 1;
					  printf("Lista ordenada!!!\n");
				   }
				  else{
				  printf("Hubo algun problema al ordenar la lista\n");
				  }
			break;
			case 3:
				  order = menuOrder();
				  printf("ORDENANDO...\n");
				  if(!ll_sort(pArrayListEmployee,employee_compareByHorasTrabajadas,order)){
				  retorno = 1;
				  printf("Lista ordenada!!!\n");
				  }
				  else{
				  printf("Hubo algun problema al ordenar la lista\n");
				  }
			break;
			case 4:
				  order = menuOrder();
				  printf("ORDENANDO...\n");
				  if(!ll_sort(pArrayListEmployee,employee_compareBySueldo,order)){
				    retorno = 1;
				    printf("Lista ordenada!!!\n");
				  }
				  else{
					  printf("Hubo algun problema al ordenar la lista\n");
				  }
			break;
			case 5:
			break;
		}

	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
		FILE* auxP;
		if(pArrayListEmployee != NULL){
		auxP = fopen(path,"w");//Lo abro para escritura
		if(auxP != NULL){
		parser_EmployeeWriteFromText(auxP,pArrayListEmployee);
		retorno = 0;
		}
		else{
		printf("No se pudo escribir en el archivo \n");
		}
		}
		fclose(auxP);
		return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	FILE* auxP;
	if(pArrayListEmployee != NULL){
	auxP = fopen(path,"wb"); //Lo abro para escritura
	if(auxP != NULL){
	parser_EmployeeWriteFromBinary(auxP ,pArrayListEmployee);
	retorno = 0;
	}
	else{
	printf("No se pudo escribir en el archivo");
	}

	}
 fclose(auxP);
 return retorno;
}

