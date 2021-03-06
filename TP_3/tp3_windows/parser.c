#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int cantidad;
	char buffer1[1024];
	char buffer2[1024];
	char buffer3[1024];
	char buffer4[1024];

	Employee* nuevoEmpleado;

	if(pFile != NULL &&  pArrayListEmployee != NULL){
		// Lectura fantasma
		    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);

		    while(!feof(pFile)) //RECORRO HASTA QUE LEA CADA LINEA DEL ARCHIVO
		        {
		            cantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer1, buffer2, buffer3, buffer4);
		            if( cantidad < 4){ //VERIFICO QUE HAYA PODIDO LEVANTAR CADA CAMPO
		                break;
		              }
		            nuevoEmpleado = employee_newParametros(buffer1, buffer2,buffer3,buffer4);//CONSTRUYO UN NUEVO EMPLEADO
		            if(nuevoEmpleado != NULL){
		            ll_add(pArrayListEmployee, nuevoEmpleado);//AGREGO AL LINKEDLIST
		            retorno = 0;
		            }
		        }
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int cantidad;
	Employee auxEmpleado;
	Employee* nuevoEmpleado;

		if(pFile != NULL &&  pArrayListEmployee != NULL){

			    while(!feof(pFile)) //RECORRO HASTA QUE LEA CADA LINEA DEL ARCHIVO
			        {
			            cantidad = fread(&auxEmpleado,sizeof(Employee),1,pFile);
			            if(cantidad < 1){ //VERIFICO QUE HAYA PODIDO LEVANTAR El EMPLEADO
			                break;
			              }
			            nuevoEmpleado = employee_newParametrosCorrespondientes(&auxEmpleado.id, auxEmpleado.nombre,&auxEmpleado.horasTrabajadas,&auxEmpleado.sueldo); //CONSTRUYO UN NUEVO EMPLEADO
			            if(nuevoEmpleado != NULL){
			            	ll_add(pArrayListEmployee, nuevoEmpleado); //AGREGO AL LINKEDLIST
			            }

			        }
			    retorno = 0;
		}
    return retorno;
}
//PARSER DE ESCRITURA
int parser_EmployeeWriteFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	Employee* auxEmpleado;

	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(pFile != NULL &&  pArrayListEmployee != NULL){
		fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i = 0;i<ll_len(pArrayListEmployee);i++){
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
			if(auxEmpleado != NULL){

				if(employee_getId(auxEmpleado,&id)==0 &&
				employee_getNombre(auxEmpleado,nombre)==0 &&
				employee_getHorasTrabajadas(auxEmpleado,&horasTrabajadas)==0&&
				employee_getSueldo(auxEmpleado,&sueldo)==0)
				{
					fprintf(pFile,"%d %s %d %d \n",id,nombre,horasTrabajadas,sueldo);
					retorno = 0;
				}
			}
		}

	}
    return retorno;
}

int parser_EmployeeWriteFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
	int retorno = 1;
	Employee* auxEmpleado;

		if(pFile != NULL &&  pArrayListEmployee != NULL){

			for(int i = 0;i<ll_len(pArrayListEmployee);i++){
				auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
				if(auxEmpleado != NULL){
					if(fwrite(auxEmpleado,sizeof(Employee),1,pFile) != 1)
					{
						retorno = 1;
						break;
					}
					retorno = 0;
				}
			}

		}
	    return retorno;
}
