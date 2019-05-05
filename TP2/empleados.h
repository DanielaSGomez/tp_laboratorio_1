#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;

}empleado;

int mostrarMenu(char mensaje[], char errormensaje[], int lowlimit, int hilimit);

int initEmpleado(empleado[], int);
int buscarLugarLibre(empleado[], int);
int buscarExisteId(empleado[], int, int);
int anadirEmpleado(empleado[], int, int, char[], char[], float, int);
int bajaEmpleado(empleado[], int, int);
int modificarEmpleado(empleado[], int, int);
int informesSueldos(empleado[], int);
int ordenarEmpleados(empleado[], int);
int mostrarListaEmpleados(empleado[], int);
int harcodearData(empleado[], int);
#endif // EMPLEADOS_H_INCLUDED
