#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new()
{

    Employee* this = (Employee*)malloc(sizeof(Employee));

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo)
{
    Employee* this;
    int auxId;
    int auxHsTrabajadas;
    float auxSueldo;

    this = employee_new();

   if(this!=NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldo != NULL)
   {
       auxId = atoi(idStr);
       employee_setId(this,auxId);

       employee_setNombre(this, nombreStr);

       auxHsTrabajadas = atoi(horasTrabajadasStr);
       employee_setHorasTrabajadas(this,auxHsTrabajadas);

       auxSueldo = atof(sueldo);
       employee_setSueldo(this,auxSueldo);

   }

   return this;

}

void employee_delete()
{
    Employee* empleado;
    free(empleado);
    empleado = NULL;

}

int employee_setId(Employee* this,int id)
{
    int retorno  =  -1;

    if(id>0 && this != NULL)
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;//SI HAY ERROR
}

int employee_getId(Employee* this,int* id)
{

    int retorno = -1;

    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;

}


int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(nombre != NULL && this != NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }

    return retorno;

}


int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;

    if(nombre != NULL && this != NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno  =  -1;

    if(horasTrabajadas>0 && this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;


}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }

    return retorno;

}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno  =  -1;

    if(sueldo>0 && this != NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;

    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }

    return retorno;

}


int employee_printOneEmployee(Employee* employee)
{
    int retorno = 1;

    if(employee != NULL)
    {
        printf("%d  %s    %d     %f   ", employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);
        retorno = 0;
    }

    return retorno;
}
