#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#define totalEmpleados 1000//TAMAÑO MAXIMO DE LA ESTRUCTURA

int main()
{
    int opcion;
    eEmpleados lista[totalEmpleados];//DECLARO VARIABLE LISTA
    initEmpleados(lista,totalEmpleados);//INICIALIZO LA LISTA DE EMPLEADOS EN ESTADO LIBRE

   do{
        printf("<-----------Bienvenido al sistema de ABM de empleados--------->");
        opcion = mostrarMenu("\nSeleccione una opcion: \n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-LISTAR\n6-SALIR\n");

        switch(opcion){
            case 1:
                    altaEmpleado(lista,totalEmpleados);
                    break;
            case 2:
                    modificarEmpleado(lista,totalEmpleados);
                    break;
            case 3:
                    bajaEmpleado(lista,totalEmpleados);
                    break;
            case 4:
                    mostrarListaEmpleados(lista,totalEmpleados);
                    break;
            case 5:
                    break;
            case 6:
                    printf("\nGracias por usar el sistema de ABM...El programa se cerrara...\n");
                    break;






        }

   }while(opcion!=6);







    return 0;
}
