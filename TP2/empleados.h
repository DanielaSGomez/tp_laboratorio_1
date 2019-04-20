#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#define LIBRE 0
#define OCUPADO 1

typedef struct//DEFINICION DE LA ESTRUCTURA EEMPLEADOS
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmpleados;

int mostrarMenu(char[]);//FUNCION QUE MUESTRA EL MENU SEGUN EL MENSAJE QUE SE PASE COMO PARAMETRO Y TOMA LA OPCION INGRESADA
void initEmpleados(eEmpleados[],int);//FUNCION PARA INICIALIZAR EL ARRAY CON TODOS LOS LUGARES/INDICES VACIOS/LIBRES
int buscarLibre(eEmpleados[],int);//FUNCION QUE BUSCA SI HAY UN LUGAR VACIO PARA SEGUIR CARGANDO
void altaEmpleado(eEmpleados[],int);//para cargar el emplado.
void mostrarUnEmpleado(eEmpleados);
void mostrarListaEmpleados(eEmpleados[],int);
void modificarEmpleado(eEmpleados[], int);
void bajaEmpleado(eEmpleados[],int);
#endif // EMPLEADOS_H_INCLUDED
