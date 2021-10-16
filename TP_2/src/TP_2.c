/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployee.h"
#include "joaquin.h"

#define LEN 2

int main()
{
	setbuf(stdout, NULL);

	int opcion;
    int idEmployee = 1001;
    int orden;
    char confirm = 'n';
    eEmployee arrayEmployees[LEN] = {{1001,"Joaquin", "Capovilla", 2500, 17,0},{1002,"Paco", "Capovilla", 5000, 13,0}};

    //initEmployees(arrayEmployees, LEN);

    do{
    	eEmployee auxEmployee;
        menuOpciones(&opcion);

        switch(opcion)
        {
        case 1:
        	printf(" ---- ALTA EMPLEADO ---- \n");
            auxEmployee.id = idEmployee;
            if(findEmployeeFree(arrayEmployees,LEN) != -1){
            	if(joaquin_getString(auxEmployee.name,"Ingrese el nombre del empleado: ","ERROR!!! \n",SIZE_STRING,10) == 1 &&
                 joaquin_getString(auxEmployee.lastName,"Ingrese el apellido del empleado: ","ERROR!!! \n",SIZE_STRING,10) == 1 &&
                 joaquin_getNumeroFlotante(&auxEmployee.salary, "Ingrese el salario del empleado: ","ERROR!!! \n",1,800000,10) ==1 &&
                 joaquin_getNumero(&auxEmployee.sector,"Ingrese el sector que corresponda al nuevo empleado (0-30): ","ERROR!!! El sector debe ser entre 0 y 30 \n",0,30,10) == 1 &&
                 addEmployee(arrayEmployees, LEN, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector) == 0)
            	{
                 printf("El empleado ha sido cargado con exito!!! \n");
                 idEmployee++;
            	}
            	 else
            	{
            	 printf("Hubo algun error al dar de alta al empleado.\n");
            	}
            }
            else{
            	printf("No hay espacio disponible para ingresar otro empleado \n");
            }
            getchar();
            break;
        case 2:
            if(arrayEmpty(arrayEmployees, LEN) == -1)
            {
                modifyEmployee(arrayEmployees, LEN);
            }
            else
            {
                printf("Primero debe ingresar algun empleado. \n");
            }
            break;
        case 3:
            if(arrayEmpty(arrayEmployees, LEN) == -1)
            {
            printf("              ---- BAJA EMPLEADO ---- \n");
            printEmployees(arrayEmployees, LEN);
            joaquin_getNumero(&auxEmployee.id,"Ingrese el ID del empleado que desea dar de baja: ","ERROR!!! el ID debe ser entre 1001 y 2500 \n",MINIMO_ID,MAXIMO_ID,10);
            if(findEmployeeById(arrayEmployees, LEN,auxEmployee.id) != -1)
            {
              if(removeEmployee(arrayEmployees, LEN, auxEmployee.id) == 0)
            	{
            	printf("Empleado dado de baja con exito!!! \n");
            	}
            	else
            	{
            	printf("Hubo algun error al dar de baja al empleado \n");
            	}
            }
            else{
            	printf("El id que ingreso no existe \n"); //EN EL CASO DE QUE INGRESE UN ID QUE ESTE DENTRO DE LO PERMITIDO PERO QUE NO EXISTA
            }

            }
            else
            {
            	printf("Primero debe ingresar algun empleado. \n");
            }
            getchar();
            break;
            case 4:
            if(arrayEmpty(arrayEmployees, LEN) == -1)
            {
                switch(menuInformes())
                {
            case 1:
               printEmployees(arrayEmployees, LEN);
            if(joaquin_getNumero(&orden,"En que orden desea mostrar a los empleados? (0 = Descendente) / (1 = Ascendente): ", "ERROR!!! \n",0,1,10) == 1 &&
               sortEmployees(arrayEmployees,LEN,orden) == 0)
               {
            	printf("\nORDENANDO . . . \n");
            	getchar();
                printEmployees(arrayEmployees, LEN);
                }
                else
                {
                printf("Hubo un error al ordenar a los empleados \n");
                }

            break;
            case 2:
            	printf("\nREALIZANDO INFORMES ... \n");
            	getchar();
                    reports(arrayEmployees,LEN);
            break;
                }
            }
            else
            {
            	printf("Primero debe ingresar algun empleado. \n");
            }
            getchar();
            break;
            case 5:
            joaquin_getCaracter(&confirm,"Esta seguro que quiere salir? (s/n): ","ERROR!!! \n",'n','s',5);
            break;
        }
        //system("cls");
    }while(confirm == 'n');
    printf("Ha salido del programa...\n");

    return 0;
}
