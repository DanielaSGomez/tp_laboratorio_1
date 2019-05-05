#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "empleados.h"
#include "biblioteca.h"
#define MAXEMPLEADOS 1000 //CANTIDAD MAXIMA DE ELEMENTOS EN EL ARRAY

int main()
{
    int opcionMenu;
    int flag = 0;
    empleado lista[MAXEMPLEADOS];
    int id = 0;
    char nombre[51];
    char apellido[51];
    float sueldo = 0;
    int sector = 0;
    int opcionInfomes;

    //INICIALIZACION DEL ARRAY
    initEmpleado(lista,MAXEMPLEADOS);

    //harcodearData(lista, 7-1);/*<----------------FUNCION HARCODEO (6 LUGARES OCUPADOS, 1 LIBRE)*/

    printf("\t\t\t\t\tBIENVENIDO AL SISTEMA DE ABM DE EMPLEADOS\n\n");

    do
    {
        opcionMenu = mostrarMenu("\nDIGITE UNA OPCION: \n1-ALTA\n2-BAJA\n3-MODIFICAR\n4-INFORMES\n5-SALIR\n","\nError\n",0,6);

        switch(opcionMenu)
        {
        case 1:

            anadirEmpleado(lista,MAXEMPLEADOS,id,nombre,apellido,sueldo,sector);
            //SI UTILIZA LA FUNCION ANADIREMPLEADO ----->FLAG =1;
            flag =1;
            break;

        case 2:
            if(flag == 0)
            {
                printf("\nPrimero ingrese un alta...");
            }
            else
            {
                bajaEmpleado(lista,MAXEMPLEADOS,id);
            }

            break;

        case 3:
            if(flag==0)
            {
                printf("\nPrimero ingrese un alta...");
            }
            else
            {
                modificarEmpleado(lista, MAXEMPLEADOS,id);
            }

            break;

        case 4:
            if(flag==0)
            {
                printf("\nPrimero ingrese un alta...");
            }
            else
            {
                printf("\n\t\t\t\tLISTA DE EMPLEADOS\n\n");
                mostrarListaEmpleados(lista, MAXEMPLEADOS);
                printf("\n\t\t\t\tSUBMENU DE INFORMES");
                opcionInfomes = getValidInt("\nDigite una opcion: \n1-Ordenamiento de lista\n2-Informes de sueldos","\nOpcion invalida",0,3);

                switch(opcionInfomes)
                {
                    case 1:
                        ordenarEmpleados(lista, MAXEMPLEADOS);
                        break;
                    case 2:
                        informesSueldos(lista, MAXEMPLEADOS);
                        break;
                }
            }

            //break del case 4 del switch principal
            break;

        case 5:
            printf("\nSaliendo del sistema...");
            break;

        default:
            printf("\nError");
            break;
        }

    }while(opcionMenu !=5);



 system("cls");


    return 0;
}
