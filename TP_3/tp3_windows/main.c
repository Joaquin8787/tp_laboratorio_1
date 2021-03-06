#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "joaquin.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int idAutoincremental;
    char confirmar;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(menuOpciones())
        {
            case 1:
            	if(!ll_isEmpty(listaEmpleados)){
            		ll_clear(listaEmpleados);
            	}
            	if(controller_loadFromText("data.csv",listaEmpleados)==0){
            	printf("Se cargaron los datos de los empleados con exito!!! \n");
            	employee_getId(ll_get(listaEmpleados,(ll_len(listaEmpleados)-1)),&idAutoincremental);
            	}
            	else{
            	printf("No se puedieron cargar los datos de los empleados... \n");
            	 }
                getchar();
                break;
            case 2:

            	if(!ll_isEmpty(listaEmpleados)){
            	 ll_clear(listaEmpleados);
            	 }
            		if(controller_loadFromBinary("data.bin",listaEmpleados) == 0){
            		printf("Se cargaron los datos de los empleados con exito!!! \n");
            		employee_getId(ll_get(listaEmpleados,(ll_len(listaEmpleados)-1)),&idAutoincremental);
            		}
            		else{
            		printf("No se puedieron cargar los datos de los empleados... \n");
            		}

            getchar();
            break;
            case 3:
            	if(!ll_isEmpty(listaEmpleados)){
            	 if(controller_addEmployee(listaEmpleados,&idAutoincremental)== 0){
            		printf("Se puedo dar de alta el empleado con exito\n");
            		}
            		else{
            		printf("No se pudo dar de alta el empleado\n");
            		}
            	}
            	else{
            		printf("Primero debe cargar los empleados con (opcion 1 / opcion 2) para poder dar de alta otro empleado\n");
            	}
                getchar();
            break;
            case 5:
            	if(!ll_isEmpty(listaEmpleados)){
            		 controller_removeEmployee(listaEmpleados);
            	}
            	else{
            	printf("Primero debe cargar algun empleado para poder eliminarlo\n");
            	}
            break;
            case 4:
            	if(!ll_isEmpty(listaEmpleados)){
            	controller_editEmployee(listaEmpleados);
            	}
            	else{
            	printf("Primero debe cargar algun empleado para poder editarlo\n");
            	}

            break;
            case 6:
            	if(!ll_isEmpty(listaEmpleados)){
            		 controller_ListEmployee(listaEmpleados);
            	}
            	else{
            		printf("Primero debe cargar algun empleado para poder mostrarlo\n");
            	}
            	getchar();
            break;
            case 7:
            	if(!ll_isEmpty(listaEmpleados)){
            	 controller_sortEmployee(listaEmpleados);
            	 }
            	 else{
            	 printf("Debe tener a los empleados cargados para poder ordenarlos\n");
            	}
            	getchar();
            break;
            case 8:
            if(!ll_isEmpty(listaEmpleados)){
            if(controller_saveAsText("data.csv",listaEmpleados) == 0){
            printf("Guardado en modo texto con exito!!!\n");

            }
            else{
            	printf("No se pudieron guardar los empleados\n");
            }
             }
             else{
             printf("Primero debe cargar algun empleado para poder guardarlo\n");
             }
             getchar();
             break;
            case 9:
            	if(!ll_isEmpty(listaEmpleados)){
            	if(controller_saveAsBinary("data.bin" , listaEmpleados) == 0){
            	printf("Guardado en modo binario con exito!!!\n");
            	}
            	}
            	else{
            	printf("Primero debe cargar algun empleado para poder guardarlo\n");
            	}
            	getchar();
            	break;
            case 10:
            joaquin_getCaracter(&confirmar,"Esta seguro que quiere salir del programa? (s/n): ","ERROR!!! \n",'n','s',5);
            if(confirmar == 's'){
            option = 10;
            }
            break;
        }
    }while(option != 10);
    printf("Usted ha salido del programa...\n");
    return 0;
}


