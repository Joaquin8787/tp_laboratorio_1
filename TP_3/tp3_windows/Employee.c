#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "parser.h"
#include "joaquin.h"

int employee_delete(Employee* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        free(this);
        retorno=1;
    }
    return retorno;
}
Employee* employee_new(){
	Employee* nuevoEmpleado = NULL;
	nuevoEmpleado = (Employee*)malloc(sizeof(Employee));
	if(nuevoEmpleado != NULL){
		employee_setId(nuevoEmpleado, 0);
		employee_setNombre(nuevoEmpleado," ");
		employee_setHorasTrabajadas(nuevoEmpleado,0);
		employee_setSueldo(nuevoEmpleado,0);
	}

	return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
	Employee* nuevoEmpleado = NULL;
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){

		nuevoEmpleado = employee_new();

		if(nuevoEmpleado != NULL){
			if(employee_setId(nuevoEmpleado, atoi(idStr))==1||
			employee_setNombre(nuevoEmpleado,nombreStr)==1||
			employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))==1||
			employee_setSueldo(nuevoEmpleado,atoi(sueldoStr))==1){
				printf("NO SE PUDO CARGAR EL EMPLEADO PORQUE FALLO ALGUN SETTER\n"); //DEBUG
				employee_delete(nuevoEmpleado);
				nuevoEmpleado = NULL;

			}

		}
	}
	return nuevoEmpleado;
}
Employee* employee_newParametrosCorrespondientes(int* id,char* nombre,int* horasTrabajadas, int* sueldo){
	Employee* nuevoEmpleado = NULL;
		if(id != NULL && nombre != NULL && horasTrabajadas != NULL && sueldo != NULL){
			nuevoEmpleado = employee_new();
			if(nuevoEmpleado != NULL){
				if(employee_setId(nuevoEmpleado,(*id))==1||
				employee_setNombre(nuevoEmpleado,nombre)==1||
				employee_setHorasTrabajadas(nuevoEmpleado,*horasTrabajadas)==1||
				employee_setSueldo(nuevoEmpleado,*sueldo)==1){

					printf("NO SE PUDO CARGAR EL EMPLEADO PORQUE FALLO ALGUN SETTER\n"); //DEBUG
					employee_delete(nuevoEmpleado);
					nuevoEmpleado = NULL;
				}
			}
		}
		return nuevoEmpleado;

}

//MOSTRAR EMPLEADO
int employee_showOneEmployee(Employee* auxEmpleado, int indice){
	int retorno = 1;
if(auxEmpleado != NULL && indice >=0){

	printf("%-10d      %-20s       %-15d        %-10d \n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
	retorno = 0;
}
return retorno;
}

//FUNCIONES PARA COMPARAR
int employee_compareById(void* employee1, void* employee2)
{
	int retorno;
	int id;
	int id2;
	if(employee1 != NULL && employee2 != NULL){

		employee_getId((Employee*)employee1,&id);
		employee_getId((Employee*)employee2,&id2);

		if( id > id2)
		{
		retorno = -1;
		}
		else if(id < id2)
		{
		retorno = 1;
		}
		else
		{
		retorno = 0;
		}
	}

	return retorno;
}
int employee_compareByNombre(void* employee1, void* employee2)
{
	int retorno;
	char nombre1[128];
	char nombre2[128];
    if(employee1 != NULL && employee2 != NULL){
    	employee_getNombre((Employee*)employee1,nombre1);
    	employee_getNombre((Employee*)employee2,nombre2);
	if(strcmp(nombre1,nombre2)>0){
			retorno = -1;
		}
		else if(strcmp(nombre1,nombre2)<0){
			retorno = 1;
		}
		else{
			retorno = 0;
		}
}

	return retorno;
}
int employee_compareByHorasTrabajadas(void* employee1, void* employee2)
{
	int retorno;
	int emp1;
	int emp2;
		if(employee1 != NULL && employee2 != NULL){

			employee_getHorasTrabajadas((Employee*)employee1,&emp1);
			employee_getHorasTrabajadas((Employee*)employee2,&emp2);

			if( emp1 > emp2)
			{
			retorno = -1;
			}
			else if(emp1 < emp2)
			{
			retorno = 1;
			}
			else
			{
			retorno = 0;
			}
		}


	return retorno;
}
int employee_compareBySueldo(void* employee1, void* employee2)
{
	int retorno;
	int emp1;
	int emp2;
	if(employee1 != NULL && employee2 != NULL){
		employee_getSueldo((Employee*)employee1,&emp1);
		employee_getSueldo((Employee*)employee2,&emp2);

					if( emp1 > emp2)
					{
					retorno = -1;
					}
					else if(emp1 < emp2)
					{
					retorno = 1;
					}
					else
					{
					retorno = 0;
					}

	}

	return retorno;
}


//SETTERS Y GETTERS
int employee_setId(Employee* this, int id)
{
    int retorno=1;
    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno=1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=1;
    if(this!=NULL && nombre!=NULL && strlen(nombre)>1 && strlen(nombre)<30)
    {
        strcpy(this->nombre,nombre);

        retorno=0;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=1;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
