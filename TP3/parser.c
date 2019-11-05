#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char idStr[5];
    char nombreStr[21];
    char horasTrabajadasStr[5];
    char sueldoStr[10];

    Employee* this = NULL;

    if(pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr,nombreStr,horasTrabajadasStr,sueldoStr);

        while(!(feof(pFile)))
        {
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr,nombreStr,horasTrabajadasStr,sueldoStr);
            this = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
            //funcion del linkedlist que agrega el item
            ll_add(pArrayListEmployee,this);
        }
    }

    return 1;
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

    return 1;
}
