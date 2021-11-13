/*
 ============================================================================
 Name        : TP1_utn.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(void) {
	 setbuf(stdout, NULL);

	int operandoA;
	int operandoB;
	int opcionMenu = 0;

	int retornoD;

	int flagCase1 = 1;
	int flagCase2 = 1;
	int flagCase3 = 1;
	int flagCase4 = 1;

	int flagMenuA = 1;
	int flagMenuB;

	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	long long int resultadoFactorialA;
	long long int resultadoFactorialB;

	do{


	    switch(menu(&operandoA, &operandoB, &flagMenuA, &flagMenuB)){
	    case 1:
	        cargarOperador(&operandoA);
	        flagCase1 = 0;
	        break;
	    case 2:
	        if(flagCase1 == 0){
	        cargarOperador(&operandoB);
	        flagCase2 = 0;
	        }
	        else {
	            printf("Error. Para ingresar el segundo operando, primero debe ingresar el primer operando\n");
	        }
	        break;
	    case 3:
	        if(flagCase2 == 0){

	        	printf("Realizando los calculos. . . \n");

	        suma(operandoA, operandoB,&resultadoSuma);
	        resta(operandoA, operandoB,&resultadoResta);
	        multiplicacion(operandoA, operandoB,&resultadoMultiplicacion);
	        retornoD = division(operandoA, operandoB,&resultadoDivision);
	        resultadoFactorialA = factorial(operandoA);
	        resultadoFactorialB = factorial(operandoB);
	        flagCase3 = 0;

	        }
	        else{
	            printf("Error. Ingrese el 2do operando para poder realizar los calculos\n");
	        }
	        break;
	    case 4:
	        if(flagCase3 == 0){

	        mostrarResultados(&resultadoSuma, &resultadoResta, &resultadoDivision, &resultadoMultiplicacion, &resultadoFactorialA, &resultadoFactorialB, &retornoD);
	        flagCase4 = 0;
	        }
	        else {
	            printf("Error. Para mostrar los resultados primero debe hacer los calculos. \n");
	        }

	        break;
	    case 5:

	    	if(flagCase4 == 0){
	        printf("Ha salido de la calculadora. \n");
	        opcionMenu = 5;


	    	}
	    	else{
	    		printf("Error. Antes de salir muestre los resultados. \n");
	    	}


	        break;
	    }
	    system("pause");
	}while(opcionMenu != 5);
	return EXIT_SUCCESS;
}
