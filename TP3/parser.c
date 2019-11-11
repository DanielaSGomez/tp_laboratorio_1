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
    int r,cont;


    Employee* this = NULL;

    if(pArrayListEmployee != NULL)
    {
        r = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr,nombreStr,horasTrabajadasStr,sueldoStr);

        while(!(feof(pFile)))
        {
            r= fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idStr,nombreStr,horasTrabajadasStr,sueldoStr);

            if(r==4)
            {
                 this = employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr);
                //funcion del linkedlist que agrega el item
                ll_add(pArrayListEmployee,this);
                cont++;
            }
            else
            {
                printf("\nNo se pudop cargar el archivo...");
            }


        }

        printf("\nSe leyeron los datos..");
        fclose(pFile);

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

    Employee employee;
    Employee* this;
    int cont;

    if(pArrayListEmployee!=NULL)
    {
        fread(&employee,sizeof(employee),1,pFile);

        while(!feof(pFile))
        {
            this = employee_new();
            employee_setId(this,employee.id);
            employee_setNombre(this,employee.nombre);
            employee_setHorasTrabajadas(this,employee.horasTrabajadas);
            employee_setSueldo(this,employee.sueldo);
            cont++;

            ll_add(pArrayListEmployee,this);

           fread(&employee,sizeof(employee),1,pFile);
        }
        printf("\nSe cargaron los datos...");
    }

    return 1;
}
