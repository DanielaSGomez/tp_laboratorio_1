#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int retorno = 1;

    pFile = fopen(path,"r");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        printf("Datos cargados...");
        retorno = 0;
    }
    else
    {
        printf("\nSe produjo nun error....");
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno = 1;

    pFile = fopen(path,"rb");

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        printf("Datos cargados...");
        retorno = 0;
    }
    else
    {
        printf("Error....");
    }

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int idEmployee;
    char strNombreEmployee[50];
    int horasEmployee;
    float sueldoEmployee;
    int retorno =1;

    if(pArrayListEmployee != NULL)
    {
        Employee* this = employee_new();

        if(this!=NULL)
        {
            printf("\n--------------Alta nuevo empleado--------------\n");

            printf("\nID: ");
            scanf("%d",&idEmployee);
            employee_setId(this,idEmployee);

            printf("\nNombre: ");
            fflush(stdin);
            scanf("%s",strNombreEmployee);
            employee_setNombre(this,strNombreEmployee);

            printf("\nHoras trabajadas: ");
            scanf("%d",&horasEmployee);
            employee_setHorasTrabajadas(this,horasEmployee);

            printf("\nSueldo: ");
            scanf("%f",&sueldoEmployee);
            employee_setSueldo(this,sueldoEmployee);

            ll_add(pArrayListEmployee,this);
            printf("\nSe cargo el empleado...");
            retorno = 0;
        }
    }

    return  retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

