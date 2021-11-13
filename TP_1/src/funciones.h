/*
 * funciones.h
 *
 *  Created on: 23 sep. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONESMATEMATICAS_H_
#define FUNCIONESMATEMATICAS_H_



#endif /* FUNCIONESMATEMATICAS_H_ */
/// @brief muestra un menu de opciones de una calculadora imprimiendo dentro los valores de los operadores ingresados o remplaza con "x" e "y"
///
/// @param pOperandoA int primer operando (A)
/// @param pOperandoB int segundo operando (B)
/// @param pFlagMenuA int valor del flag para saber si se ingreso el primer operando
/// @param pFlagMenuB int valor del flag para saber si se ingreso el segundo operando
/// @return int devuelve la opcion elegida del menu
int menu(int* pOperandoA, int* pOperandoB, int* pFlagMenuA, int*pFlagMenuB);

/// @brief solicita al usuario que ingrese un operando y lo carga por referencia a la variable
///
/// @param operando int guarda por referencia el valor ingresado por el usuario
/// @return void
void cargarOperador(int* operando);

/// @brief muestra por pantalla los resultados de todas las operaciones realizadas anteriormente o informa si hubo algun problema para realizarlas
///
/// @param pResultadoSuma int valor por referencia del resultado de la suma realizada por los operandos
/// @param pResultadoResta  int valor por referencia del resultado de la resta realizada por los operandos
/// @param pResultadoDivision  float valor por referencia del resultado de la division realizada por los operandos
/// @param pResultadoMultiplicacion  int valor por referencia del resultado de la multiplicacion realizada por los operandos
/// @param ResultadoFactorialA long long int valor del resultado de la operacion factorial del primer operando
/// @param ResultadoFactorialB long long int valor del resultado de la operacion factorial del segundo operando
/// @param retornoDivision int valor del retorno de la funcion division que se utiliza para saber si se pudo realizar la operacion o si se ingreso algun 0 en cualquiera de los 2 operandos
/// @return void
void mostrarResultados(int* pResultadoSuma, int* pResultadoResta, float* pResultadoDivision, int* pResultadoMultiplicacion, long long int* ResultadoFactorialA, long long int* ResultadoFactorialB, int* retornoDivision);

//FUNCIONES OPERACIONES MATEMATICAS
/// @brief realiza la suma entre dos enteros y pasa el resultado por referencia
///
/// @param num1 int valor del primer operando
/// @param num2 int valor del segundo operando
/// @param resultado int puntero al espacio en memoria donde se almacenara el resultado
/// @return int retorna 1 si pudo realizar la suma y -1 si no pudo
int suma(int num1, int num2, int* resultado);

/// @brief realiza la resta entre dos enteros y pasa el resultado por referencia
///
/// @param num1 int valor del primer operando
/// @param num2 int valor del segundo operando
/// @param resultado int puntero al espacio en memoria donde se almacenara el resultado
/// @return int retorna 1 si pudo realizar la resta y -1 si no pudo
int resta(int num1, int num2, int* resultado);

/// @brief realiza la multiplicacion entre dos enteros y pasa el resultado por referencia
///
/// @param num1 int valor del primer operando
/// @param num2 int valor del segundo operando
/// @param resultado int puntero al espacio en memoria donde se almacenara el resultado
/// @return int retorna 1 si pudo realizar la multiplicacion y -1 si no pudo
int multiplicacion(int num1, int num2, int* resultado);

/// @brief realiza la division entre dos enteros y pasa el resultado por referencia
///
/// @param num1 int valor del primer operando
/// @param num2 int valor del segundo operando
/// @param resultado int puntero al espacio de memoria donde se almacenara el resultado
/// @return int retorna 1 si pudo realizar la division y -1 si no pudo
int division(int num1, int num2, float* resultado);

/// @brief realiza el factorial de un entero y pasa el resultado por referencia
///
/// @param numero int valor del operando
/// @return unsigned long long int retorna el valor del resultado del factorial del operando
unsigned long long int factorial(int numero);
