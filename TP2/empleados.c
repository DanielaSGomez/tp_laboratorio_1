
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include <ctype.h>



void altaEmpleado(eEmpleados lista[],int tam)//TOMA COMO PARAMETROS EL ARRAY DE EMPLEADOS Y EL TAMAÑO DEL ARRAY
{
    int i;
    i = buscarLibre(lista,tam);

    if(i!=-1)
    {
        printf("Ingrese id: ");
        scanf("%d", &lista[i].id);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lista[i].lastName);
        printf("Ingrese sector: ");
        fflush(stdin);
        scanf("%d",&lista[i].sector);
        printf("Ingrese sueldo: ");
        scanf("%f", &lista[i].salary);

        lista[i].isEmpty = OCUPADO;

    }
    else
    {
        printf("No hay espacio");
    }

}

int getInt(char mensaje[])
{
    int opcion;
    printf("%s",mensaje);
    scanf("%d",&opcion);
    fflush(stdin);
    return opcion;
}

/*char getChar(char mensaje[])
{
    char opcion;
    printf("%s",mensaje);
    scanf("%c",&opcion);
}
*/
int mostrarMenu(char mensaje[])
{
    int opcionElegida;
    opcionElegida = getInt(mensaje);
    fflush(stdin);
    return opcionElegida;
}

void initEmpleados(eEmpleados lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)//RECORRE EL ARRAY DE EEMPELADOS Y CARGA TODA LA LISTA COMO VACIA
    {
        lista[i].isEmpty = LIBRE;
    }

}

int buscarLibre(eEmpleados lista[],int tam)
{

    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;

}

void mostrarListaEmpleados(eEmpleados lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty!=LIBRE)
        {
            mostrarUnEmpleado(lista[i]);
        }
    }
}

void mostrarUnEmpleado(eEmpleados unEmpleados)
{

    printf("\n\nInformacion del empleado:\n%d \n%s\n%s\n%d\n%.2f\n\n",unEmpleados.id, unEmpleados.name, unEmpleados.lastName, unEmpleados.sector, unEmpleados.salary);


}
void modificarEmpleado(eEmpleados lista[], int tam)
{
    int idIngresado;
    int opcionMenu;
    int i;
    float nuevoSueldo;
    char nuevoNombre[51];
    char nuevoApellido[51];
    int nuevoSector;


    printf("Ingrese el id a modificar: ");
    scanf("%d",&idIngresado);
    fflush(stdin);

    for(i=0;i<tam;i++)
    {
     if(idIngresado == lista[i].id)
     {

        printf("\nElija una opcion a cambiar: \n1-Nombre\n2-Apellido\n3-Sector\n4-Sueldo");
        fflush(stdin);
        scanf("%d",&opcionMenu);
        break;

     }
     else
        {
            printf("El id ingresado es incorrecto...");
            break;
        }
    }

     switch(opcionMenu)
    {

        case 1:


                printf("Ingrese el nombre: ");
                fflush(stdin);
                gets(nuevoNombre);
                strcpy(lista[i].name,nuevoNombre);
                break;
        case 2:

                printf("Ingrese el apellido: ");
                fflush(stdin);
                gets(nuevoApellido);
                strcpy(lista[i].lastName,nuevoApellido);
                break;
        case 3:
                printf("Ingrese el sector: ");
                scanf("%d",&nuevoSector);
                lista[i].sector = nuevoSector;
                break;
        case 4:
                printf("Ingrese el sueldo: ");
                scanf("%f",&nuevoSueldo);
                lista[i].salary = nuevoSueldo;
                break;
        default:
                printf("Opcion incorrecta");
                break;

    }

}


void bajaEmpleado(eEmpleados lista[],int tam)
{
    int i;
    int auxID;
    int flag = 0;
    char respuesta;

    auxID = getInt("\nIngrese el Id a dar de baja: \n");

    fflush(stdin);
   for(i=0;i<tam;i++)
   {
    if(auxID==lista[i].id)
        {

        printf("\nDatos del empleado: \n");
        mostrarUnEmpleado(lista[i]);

        printf("\nConfirma que desea eliminar el empleado? s/n");
        scanf("%c",&respuesta);
        respuesta = tolower(respuesta);

        if(respuesta=='s')
        {
            lista[i].isEmpty = LIBRE;

            flag = 1;
            break;

        }
        else
        {
            printf("\nSe cancelo la baja.\n");
            break;
        }
    }

    if(flag==0)
    {
        printf("ID incorrecto");
    }
   }
}
