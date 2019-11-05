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
    this = employee_new();

    if(!employee_setId(this,idStr)&& !employee_setNombre(this,nombreStr)&&!employee_setHorasTrabajadas(this,horasTrabajadasStr)&&!employee_setSueldo(this,sueldo))
    {
       return this;
    }

    employee_delete(this);
    return NULL;


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
