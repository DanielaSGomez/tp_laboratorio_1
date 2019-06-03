#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flag = -1;
    int flagB = -1;
    int flagN = -1;
    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("\t\t--------------------------ABM EMPLEADOS------------------------------\n");

    do{
        option = mostrarMenu("Digite una opcion:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir ","Error!",1,10);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                flag = 1;
                break;
            case 2:
                controller_loadFromBinary("data.cvs",listaEmpleados);
                flagB = 1;
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                flagN = 1;
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
            case 10:
                printf("\nCerrando el sistema...");
                break;
            default:
                printf("Opcion incorrecta...");
                break;
        }
    }while(option != 10);
    return 0;
}
