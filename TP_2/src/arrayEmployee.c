/*
 * employee.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployee.h"
#include "joaquin.h"

//INICIALIZAR EMPLEADO
int initEmployees(eEmployee* list, int len)
{
    int retorno = -1;
    if(list!=NULL && len>0)
    {
        retorno = 0;
        for(int i=0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return retorno;
}
//AGREGAR EMPLEADO
int addEmployee(eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int retorno = -1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                list[i].id=id;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary = salary;
                list[i].sector = sector;
                list[i].isEmpty = 0;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
//BUSCAR EMPLEADO POR ID
int findEmployeeById(eEmployee* list, int len,int id)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0) //Si el id que le paso es igual a alguno que este en el array
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

//ELIMINAR EMPLEADO
int removeEmployee(eEmployee* list, int len, int id)
{
    int retorno = -1;
    int index;
    char confirm;

    if(list!=NULL && len>0)
    {
        index = findEmployeeById(list, len, id); //BUSCO EL EMPLEADO MEDIANTE EL ID Y DEVUELVO LA POSICION
        if(index != -1)
        {
        	printf(" ID    Nombre        Apellido             Salario   Sector\n");
            printOneEmployee(list[index]);
            joaquin_getCaracter(&confirm,"Esta seguro que quiere eliminar este empleado? (s/n): ","ERROR!!! \n",'n','s',5);
            if(confirm == 's')
            {
                list[index].isEmpty = 1;
                retorno = 0;
            }
        }
    }
    return retorno;
}

//MODIFICAR EMPLEADO
int sortEmployees(eEmployee* list, int len, int order)
{
    int retorno = - 1;
    eEmployee auxEmployee;

    if(list!=NULL && len>0)
    {
        retorno=0;
        //BURBUJEO
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
            	//DESCENDENTE

                if(order == 0 && ((strcmp(list[i].lastName, list[j].lastName) < 0)
                || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector)))
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
                //ACENDENTE
                else if(order == 1 && ((strcmp(list[i].lastName, list[j].lastName) > 0)
                || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector)))
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }
    }
    return retorno;
}
//IMPRIMIR EMPLEADOS
void printOneEmployee(eEmployee aEmployee)
{
    printf("%d   %-10s    %-20s %-10.2f %-5d\n",aEmployee.id,
                                              aEmployee.name,
                                              aEmployee.lastName,
                                              aEmployee.salary,
                                              aEmployee.sector);
}

int printEmployees(eEmployee* list, int len)
{
	int retorno = -1;
    if(list != NULL && len > 0)
    {
        printf("-----------------------------------------------------------\n");
        printf("-----------------------------------------------------------\n");
        printf("      LISTA DE EMPLEADOS\n");
        printf(" ID    Nombre        Apellido             Salario   Sector\n");
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
            	printOneEmployee(list[i]);
                retorno = 0;
            }
        }
        printf("-----------------------------------------------------------\n");
        printf("-----------------------------------------------------------\n");
    }
    return retorno;
}
/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 */

//ARRAY VACIO
int arrayEmpty(eEmployee* list, int len){
    int retorno = 1;
    if(list != NULL && len > 0){
        for(int i=0; i< len;i++){
        if(list[i].isEmpty == 0){
            retorno = -1;
        }
    }
    }
    return retorno;
}
//BUSCAR LIBRE
int findEmployeeFree(eEmployee list[], int len)
{
    int retorno = -1;
    if(list!=NULL && len > 0)
    {
    	for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int modifyEmployee(eEmployee list[], int len)
{
    int retorno = -1;
    int index;
    int option;
    int idEmployee;
    eEmployee auxEmployee;
    char confirm = 's';

    if(list!=NULL && len>0)
    {
    	do{
        printEmployees(list,len);
        joaquin_getNumero(&idEmployee,"Ingrese el ID del empleado que desea modificar: \n","ERROR!!! el ID debe ser entre 1001 y 2500 \n",MINIMO_ID ,MAXIMO_ID ,10);
        index = findEmployeeById(list,len,idEmployee); //BUSCO EL EMPLEADO MEDIANTE EL ID
        while(index == -1)
        {
        	printf("ERROR. El id ingresado no existe \n");
        	printEmployees(list,len);
        	joaquin_getNumero(&idEmployee,"Ingrese el ID del empleado que desea modificar: \n","ERROR!!! el ID debe ser entre 1001 y 2500 \n",MINIMO_ID ,MAXIMO_ID ,10);
        	index = findEmployeeById(list,len,idEmployee);
        }
                option = menuModificaciones();
                switch(option)
                {
                case 1:
                	printf(" ---- MODIFICACION DEL NOMBRE --- \n");
                    if(joaquin_getString(auxEmployee.name,"Ingrese nuevo nombre: ","ERROR!!! \n",SIZE_STRING,10) == 1)
                    {
                    	 strcpy(list[index].name,auxEmployee.name);
                    	 printf("Se modifico el nombre con exito!!!  \n");
                    	 retorno = 0;
                    }
                    break;
                case 2:
                	printf(" ---- MODIFICACION DEL APELLIDO --- \n");
                    if(joaquin_getString(auxEmployee.lastName,"Ingrese nuevo apellido: ","ERROR!!! \n",SIZE_STRING,10) == 1)
                    {
                    	 strcpy(list[index].lastName,auxEmployee.lastName);
                    	 printf("Se modifico el apellido con exito!!!  \n");
                    	 retorno = 0;
                    }
                    break;
                case 3:
                	printf(" ---- MODIFICACION DEL SALARIO --- \n");
                    if(joaquin_getNumeroFlotante(&auxEmployee.salary,"Ingrese nuevo salario: ","ERROR!!! \n",1,800000,10) == 1)
                    {
                    	list[index].salary=auxEmployee.salary;
                       	printf("Se modifico el salario con exito!!!  \n");
                       	retorno = 0;

                    }
                    break;
                case 4:
                	printf(" ---- MODIFICACION DEL SECTOR --- \n");
                    if(joaquin_getNumero(&auxEmployee.sector,"Ingrese nuevo sector (1-30): ","ERROR!!! el sector debe ser entre 1 y 30 \n",1,30,10) == 1)
                    {
                    	list[index].sector=auxEmployee.sector;
                    	printf("Se modifico el sector con exito!!! \n");
                    	retorno = 0;
                    }
                    break;
              }
            joaquin_getCaracter(&confirm,"Quiere modificar otro empleado? (s/n): ","ERROR!!! \n",'n','s',2);

            }while(confirm == 's');
      }
    return retorno;
    }

int reports(eEmployee* list, int len)
{
    int retorno = -1;
    int employeesHighSalary = 0;
    int contadorEmployees = 0;
    float acumuladorSalary = 0;
    float averageSalary;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                acumuladorSalary += list[i].salary;
                contadorEmployees++;
            }
        }
        averageSalary = acumuladorSalary/contadorEmployees; //Saco el promedio

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > averageSalary) //Me fijo si algun empleado supera el salario promedio
            {
                employeesHighSalary++;
            }
        }
        printf("------------------------------------------------------------------\n");
        printf("------------------------------------------------------------------\n");
        printf("El total de los salarios es de $ %.2f\n",acumuladorSalary);
        printf("El promedio de los salarios es de $ %.2f\n",averageSalary);
        printf("La cantidad de empleados que superan el salario promedio es de: %d\n",employeesHighSalary);
        printf("------------------------------------------------------------------\n");
        printf("------------------------------------------------------------------\n");
        retorno = 0;
    }
    return retorno;
}
