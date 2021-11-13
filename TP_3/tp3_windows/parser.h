/*
 * parser.h
 *
 *  Created on: 1 nov. 2021
 *      Author: Usuario
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */
#include "LinkedList.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeWriteFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeWriteFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
