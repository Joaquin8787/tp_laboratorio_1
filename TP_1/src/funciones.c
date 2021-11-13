#include <stdio.h>
#include <stdlib.h>

/*
 * funciones.c
 *
 *  Created on: 23 sep. 2021
 *      Author: Usuario
 */

int menu(int* pOperandoA, int* pOperandoB,int* pFlagMenuA, int*pFlagMenuB ){
int opcion;
    system("cls");
    printf("* CALCULADORA *\n");

    if(*pFlagMenuA){
    printf(" 1) - Ingrese el primer operando (A = x)\n");
    printf(" 2) - Ingrese el segundo operando (B = y)\n");
    }

    else if(*pFlagMenuA == 0 && *pFlagMenuB){
      printf(" 1) - Ingrese el primer operando (A = %d)\n", *pOperandoA);
      printf(" 2) - Ingrese el segundo operando (B = y)\n");
  	*pFlagMenuB = 0;
    }
    else{
    printf(" 1) - Ingrese el primer operando (A = %d)\n", *pOperandoA);
    printf(" 2) - Ingrese el segundo operando (B = %d)\n",*pOperandoB);
    }


    printf(" 3) - Calcular todas las operaciones\n"
           "\t a) - Calcular la suma (A+B)\n"
           "\t b) - Calcular la resta (A-B)\n"
           "\t c) - Calcular division (A/B)\n"
           "\t d) - Calcular multiplicacion (A*B)\n"
           "\t e) - Calcular factorial (A!)\n");
    printf(" 4) - Informar resultados \n");
    printf(" 5) - Salir \n");
    printf(" Ingrese una opcion: \n");
    scanf("%d",&opcion);

    if(opcion == 1){
       	*pFlagMenuA = 0;
       	*pFlagMenuB = 1;
       }

return opcion;
}
void cargarOperador(int* pOperando){
if(pOperando != NULL){
printf("Ingrese el numero:\n");
scanf("%d",pOperando);
}
}

void mostrarResultados(int* pResultadoSuma, int* pResultadoResta, float* pResultadoDivision, int* pResultadoMultiplicacion, unsigned long long int* pResultadoFactorialA, unsigned long long int* pResultadoFactorialB, int* retornoDivision){

	    printf("La suma es: %d \n",*pResultadoSuma);
        printf("La resta es: %d \n",*pResultadoResta);
        if(*retornoDivision == -1){ //Comparo el valor que me devolvio la division para saber si puedo dividir o no
        printf("No se pudo realizar la division ya que alguno de los operandos contenia el valor 0 \n");
        }
        else{
        printf("La division es: %.3f \n",*pResultadoDivision);
        }
        printf("La multiplicacion es: %d \n",*pResultadoMultiplicacion);

        if(*pResultadoFactorialA != -1){
        	printf("El factorial de (A) es:%I64u\n",*pResultadoFactorialA);
        }
        else{
        	printf("No se pudo realizar el factorial de (A) ya que es un numero negativo\n");
        }
        if(*pResultadoFactorialB != -1){
        	printf("El factorial de (B) es:%I64u\n",*pResultadoFactorialB);
        }
        else{
        printf("No se pudo realizar el factorial de (B) ya  que se ingreso un numero negativo\n");
        }

}



//FUNCIONES OPERACIONES MATEMATICAS
int suma(int num1, int num2, int* resultado){
	int retorno = -1;
	if(resultado != NULL){
		*resultado = num1 + num2;
		retorno = 1;
	}
    return retorno;
}

int resta(int num1, int num2, int* resultado){
	int retorno = -1;
	if(resultado != NULL){
		*resultado = num1 - num2;
		retorno = 1;
	}

return retorno;


}

int division(int num1, int num2, float* resultado){
	int retorno = -1;
	if(resultado != NULL && (num1 != 0 && num2 != 0)){
     *resultado = (float) num1 / num2;
     retorno = 1;
	}
return retorno;
}

int multiplicacion(int num1, int num2, int* resultado){
	int retorno = -1;
	if(resultado != NULL){
      *resultado = num1 * num2;
		retorno = 1;
	}
return retorno;
}
 long long int factorial(int numero){
 long long int fact;

if(numero >= 0){ //VALIDO SI ES NEGATIVO
	if(numero == 0){
	    fact = 1;
	}
	else{
	    fact = numero * factorial(numero - 1);
	}
}
else{
	fact = -1;
}
return fact;

}

